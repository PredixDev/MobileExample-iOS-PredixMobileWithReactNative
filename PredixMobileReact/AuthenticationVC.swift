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
    func loadURL(URL: NSURL, parameters: [NSObject : AnyObject]?, onComplete: (()->())?)
    {
        if let onComplete = onComplete
        {
            self.webViewFinishedLoad = onComplete
        }
        
        self.webView.scrollView.scrollEnabled = true
        if let params = parameters, scrollStateString = params["nativeScroll"] as? String where scrollStateString == "false"
        {
            self.webView.scrollView.scrollEnabled = false
        }
        
        self.webView.loadRequest(NSURLRequest(URL:URL))
    }
    
    func updateWaitState(state: WaitState, message: String?)
    {
        switch state
        {
        case .NotWaiting :
            self.spinner.stopAnimating()
            self.spinner.hidden = true
            self.spinnerMessage.text = nil
            self.spinnerMessage.hidden = true
            
        case .Waiting :
            
            self.spinner.hidden = false
            self.spinnerMessage.hidden = false
            self.spinner.startAnimating()
            self.spinnerMessage.text = message
        }
    }
    
    func waitState() -> (PredixMobileSDK.WaitStateReturn)
    {
        return WaitStateReturn(state: self.spinner.hidden ? .NotWaiting : .Waiting, message: self.spinnerMessage.text)
    }
    
    //MARK: UIWebViewDelegate
    func webViewDidStartLoad(webView: UIWebView)
    {
        PGSDKLogger.trace("Web view starting load")
        self.spinner.startAnimating()
    }
    
    func webViewDidFinishLoad(webView: UIWebView)
    {
        
        if let request = webView.request, cachedResponse = NSURLCache.sharedURLCache().cachedResponseForRequest(request), response = cachedResponse.response as? NSHTTPURLResponse
        {
            if response.statusCode > 399
            {
                PGSDKLogger.error("Web view page load error (\(response.statusCode)) while authenticating. Aborting authentication")
                PredixMobilityManager.sharedInstance.authenticationComplete()
            }
        }
        
        PGSDKLogger.trace("Web view finished load")
        self.spinner.stopAnimating()
        if let webViewFinishedLoad = self.webViewFinishedLoad
        {
            self.webViewFinishedLoad = nil
            webViewFinishedLoad()
        }
    }
    
    func webView(webView: UIWebView, didFailLoadWithError errorOptional: NSError?)
    {
        self.spinner.stopAnimating()
        
        guard let error = errorOptional else
        {
            // no error object, nothing to do...
            return
        }
        
        // Ignore cancelled and "Frame Load Interrupted" errors
        if error.code == NSURLErrorCancelled {return}
        if error.code == 102 && error.domain == "WebKitErrorDomain" {return}
        
        PGSDKLogger.debug("Web view encountered loading error: \(error.description)")
        ShowSeriousErrorHelper.ShowUserError(error.localizedDescription)
    }
}
