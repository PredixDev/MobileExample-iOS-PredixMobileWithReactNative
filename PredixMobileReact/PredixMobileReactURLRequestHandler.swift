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
    public func canHandle(_ request: URLRequest!) -> Bool {
        return request.url!.host == PredixMobilityConfiguration.apiHostname
    }
    
    public func send(_ request: URLRequest!, with delegate: RCTURLRequestDelegate!) -> Any! {
        ServiceRouter.sharedInstance.processRequest(request, responseBlock: { (response: URLResponse?) in
                delegate.urlRequest(request, didReceive: response)
            }, dataBlock: { (data: Data?) in
                delegate.urlRequest(request, didReceive:data)
            }) { 
                delegate.urlRequest(request, didCompleteWithError: nil)
        }
        return request as AnyObject!
    }
    
    public func handlerPriority() -> Float {
        return 999.0
    }
    
    
}
