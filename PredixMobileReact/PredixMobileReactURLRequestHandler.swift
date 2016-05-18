//
//  PredixMobileReactURLRequestHandler.swift
//  PredixMobileReact
//
//  Created by Johns, Andy (GE Corporate) on 5/16/16.
//  Copyright © 2016 GE. All rights reserved.
//

import Foundation
import PredixMobileSDK

extension PredixMobileReactURLRequestHandler : RCTURLRequestHandler
{
    public func canHandleRequest(request: NSURLRequest!) -> Bool {
        return request.URL!.host == PredixMobilityConfiguration.API_HOST
    }
    
    public func sendRequest(request: NSURLRequest!, withDelegate delegate: RCTURLRequestDelegate!) -> AnyObject! {
        ServiceRouter.sharedInstance.processRequest(request, responseBlock: { (response: NSURLResponse?) in
                delegate.URLRequest(request, didReceiveResponse: response)
            }, dataBlock: { (data: NSData?) in
                delegate.URLRequest(request, didReceiveData:data)
            }) { 
                delegate.URLRequest(request, didCompleteWithError: nil)
        }
        return request
    }
    
    public func handlerPriority() -> Float {
        return 999.0
    }
    
    
}