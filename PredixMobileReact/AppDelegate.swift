//
//  AppDelegate.swift
//  PredixMobileReact
//
//  Created by Johns, Andy (GE Corporate) on 5/13/16.
//  Copyright © 2016 GE. All rights reserved.
//

import UIKit
import PredixMobileSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    let originalDefaultSessionConfiguration = URLSessionConfiguration.default
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        #if DEBUG
            if NSProcessInfo.processInfo().environment["XCInjectBundleInto"] != nil {
                // Exit if we're running unit tests...
                Logger.debug("Detected running functional unit tests, not starting normal services or running normal UI processes")
                return true
            }
        #endif
        
        // logging our current running environment
        Logger.debug("Started app with launchOptions: \(String(describing: launchOptions))")
        
        if Logger.isInfoEnabled() {
            let versionInfo = PredixMobilityConfiguration.getVersionInfo()
            let processInfo = ProcessInfo.processInfo
            let device = UIDevice.current
            var runningEnvironment = "Running Environment:"
            runningEnvironment += "\n     locale: \(versionInfo[VersionInfoKeys.Locale] ?? "")"
            runningEnvironment += "\n     device system name:\(versionInfo[VersionInfoKeys.DeviceOS] ?? "")"
            runningEnvironment += "\n     device system version:\(versionInfo[VersionInfoKeys.DeviceOSVersion] ?? "")"
            runningEnvironment += "\n     device vendor identifier:\(device.identifierForVendor!.uuidString)"
            runningEnvironment += "\n     iOS Version/Build: \(processInfo.operatingSystemVersionString)"
            runningEnvironment += "\n     app bundle id: \(versionInfo[VersionInfoKeys.ApplicationBundleId] ?? "")"
            runningEnvironment += "\n     app version: \(versionInfo[VersionInfoKeys.ApplicationVersion] ?? "")"
            runningEnvironment += "\n     app build version: \(versionInfo[VersionInfoKeys.ApplicationBuildVersion] ?? "")"
            runningEnvironment += "\n     \(PredixMobilityConfiguration.versionInfo)"
            
            Logger.info(runningEnvironment)
        }

        // Pre-load configuration. This will load any Settings bundles into NSUserDefaults and set default logging levels
        PredixMobilityConfiguration.loadConfiguration()
        
        // create the PredixMobilityManager object. This object coordinates the application state, interacts with the various services, and holds closures called during authentication.
        
        let vc : ViewController = self.window?.rootViewController as! ViewController
        let pmm = PredixMobilityManager(packageWindow: vc, presentAuthentication: {[unowned self] (packageWindow) -> (PredixAppWindowProtocol) in
            
            // for this example we're using a new instance of the primary view controller to host the authentication pages.
            let authVC = vc.storyboard!.instantiateViewController(withIdentifier: "authenticationVC") as! AuthenticationVC
            self.window?.rootViewController!.present(authVC, animated: true, completion: nil)
            return authVC as PredixAppWindowProtocol
            
            }, dismissAuthentication: {(authenticationWindow: PredixAppWindowProtocol) -> () in
                
                if let authVC = authenticationWindow as? UIViewController
                {
                    authVC.dismiss(animated: true, completion: nil)
                }
                
            })
        
        // start the application. This will spin up the PredixMobile environment and call the Boot service to start the application.
        pmm.startApp()
        
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }


}

