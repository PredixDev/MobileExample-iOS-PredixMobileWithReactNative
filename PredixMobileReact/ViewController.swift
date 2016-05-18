//
//  ViewController.swift
//  PredixMobileReact
//
//  Created by Johns, Andy (GE Corporate) on 5/13/16.
//  Copyright © 2016 GE. All rights reserved.
//

import UIKit
import PredixMobileSDK

class ViewController: UIViewController, PredixAppWindowProtocol {

    @IBOutlet var spinnerMessage: UILabel!
    @IBOutlet var spinner: UIActivityIndicatorView!
    
    var rootView : RCTRootView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    // MARK: - PredixAppWindowProtocol
    func loadURL(URL: NSURL, parameters: [NSObject : AnyObject]?, onComplete: (()->())?)
    {
        if URL.scheme != "about"
        {
            // pull react native page from webapp
            let jsCodeLocation = URL;
            
            // load from react-native host for testing
            //let jsCodeLocation = NSURL(string: "http://localhost:8081/index.ios.bundle?platform=ios&dev=true")!
            
            let rootView = RCTRootView(bundleURL: jsCodeLocation, moduleName: "PredixMobileReact", initialProperties: nil, launchOptions: nil)
        
            self.rootView = rootView
            self.view = rootView
        }
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
    
    func receiveAppNotification(originalScript: String)
    {
        // split out script from arguments, and serialize arguments
        
        // remove trailing semicolon if present
        var script = originalScript
        if script.hasSuffix(";")
        {
            script.removeAtIndex(script.endIndex.predecessor())
        }
        
        // Separate the function name from the arguments. Removing any empty elements
        let scriptComponents = script.componentsSeparatedByCharactersInSet(NSCharacterSet.init(charactersInString: "()")).filter{ (component) -> Bool in
            !component.isEmpty
        }
    
        // scriptComponents should now be one or two elements. if one, it's the function name, if two it's the function name and all the arguments as a string.
        
        // default to no arguments
        var arguments : [AnyObject] = []


        // form a JSON array of the arguments and create an NSData object of the string to de-serialize
        if let argumentData = "[\(scriptComponents[1])]".dataUsingEncoding(NSUTF8StringEncoding) where scriptComponents.count > 1
        {
            // if argumentData can be de-serialzed, then do so, and replace default arguments variable
            if let deserializedObject = try? NSJSONSerialization.JSONObjectWithData(argumentData, options: NSJSONReadingOptions.AllowFragments), deserializedArguments = deserializedObject as? [AnyObject]
            {
                arguments = deserializedArguments
            }
        }

        // if we have a function name, send the event.
        if scriptComponents.count > 0
        {
            self.rootView.bridge.eventDispatcher.sendAppEventWithName(scriptComponents[0], body:arguments)
        }
        
    }
}

