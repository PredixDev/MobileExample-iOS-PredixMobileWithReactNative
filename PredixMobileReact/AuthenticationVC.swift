//
//  AuthenticationVC.swift
//  NativeDatabaseViewer
//
//  Created by Johns, Andy (GE Corporate) on 1/22/16.
//  Copyright © 2016 GE. All rights reserved.
//

import UIKit
import PredixMobileSDK

class AuthenticationVC: UIViewController, UIWebViewDelegate, PredixAppWindowProtocol {

    @IBOutlet var spinner: UIActivityIndicatorView!
    @IBOutlet var webView: UIWebView!
    @IBOutlet var spinnerMessage: UILabel!
    var webViewFinishedLoad : (()->())?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        self.automaticallyAdjustsScrollViewInsets = false
        self.webView.delegate = self
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    // MARK: - PredixAppWindowProtocol
    func loadURL(_ url: URL, parameters: [AnyHashable: Any]?, onComplete: (()->())?)
    {
        if let onComplete = onComplete
        {
            self.webViewFinishedLoad = onComplete
        }
        
        self.webView.scrollView.isScrollEnabled = true
        if let params = parameters, let scrollStateString = params["nativeScroll"] as? String, scrollStateString == "false"
        {
            self.webView.scrollView.isScrollEnabled = false
        }
        
        self.webView.loadRequest(URLRequest(url:url))
    }
    
    func updateWaitState(_ state: WaitState, message: String?)
    {
        switch state
        {
        case .notWaiting :
            self.spinner.stopAnimating()
            self.spinner.isHidden = true
            self.spinnerMessage.text = nil
            self.spinnerMessage.isHidden = true
            
        case .waiting :
            
            self.spinner.isHidden = false
            self.spinnerMessage.isHidden = false
            self.spinner.startAnimating()
            self.spinnerMessage.text = message
        }
    }
    
    func waitState() -> (PredixMobileSDK.WaitStateReturn)
    {
        return WaitStateReturn(state: self.spinner.isHidden ? .notWaiting : .waiting, message: self.spinnerMessage.text)
    }
    
    //MARK: UIWebViewDelegate
    func webViewDidStartLoad(_ webView: UIWebView)
    {
        Logger.trace("Web view starting load")
        self.spinner.startAnimating()
    }
    
    func webViewDidFinishLoad(_ webView: UIWebView)
    {
        
        if let request = webView.request, let cachedResponse = URLCache.shared.cachedResponse(for: request), let response = cachedResponse.response as? HTTPURLResponse
        {
            if response.statusCode > 399
            {
                Logger.error("Web view page load error (\(response.statusCode)) while authenticating. Aborting authentication")
                PredixMobilityManager.sharedInstance.authenticationComplete()
            }
        }
        
        Logger.trace("Web view finished load")
        self.spinner.stopAnimating()
        if let webViewFinishedLoad = self.webViewFinishedLoad
        {
            self.webViewFinishedLoad = nil
            webViewFinishedLoad()
        }
    }
    
    func webView(_ webView: UIWebView, didFailLoadWithError error: Error)
    {
        self.spinner.stopAnimating()
        
        let error = error as NSError
        
        // Ignore cancelled and "Frame Load Interrupted" errors
        if error.code == NSURLErrorCancelled {return}
        if error.code == 102 && error.domain == "WebKitErrorDomain" {return}
        
        Logger.debug("Web view encountered loading error: \(error.description)")
        ShowSeriousErrorHelper.ShowUserError(error.localizedDescription)
    }
}
