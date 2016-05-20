// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.1 clang-703.0.29)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
#endif

#import <PredixMobileSDK/PredixMobileSDK.h>

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSURLRequest;
@class NSHTTPURLResponse;

SWIFT_PROTOCOL("_TtP15PredixMobileSDK15ServiceProtocol_")
@protocol ServiceProtocol
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
@optional
+ (void)registered;
+ (void)unregistered;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK10CDBService")
@interface CDBService : NSObject <ServiceProtocol>
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, ConfigurationLocation) {
  ConfigurationLocationsettings = 0,
  ConfigurationLocationinfoplist = 1,
};


SWIFT_CLASS("_TtC15PredixMobileSDK19ConnectivityService")
@interface ConnectivityService : NSObject <ServiceProtocol>
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK9DBService")
@interface DBService : NSObject <ServiceProtocol>
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK14FullTextSearch")
@interface FullTextSearch : NSObject
+ (id _Nonnull (^ _Nonnull)(NSString * _Nonnull))createKey;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK10LogService")
@interface LogService : NSObject <ServiceProtocol>
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSCharacterSet (SWIFT_EXTENSION(PredixMobileSDK))
@end


SWIFT_CLASS("_TtC15PredixMobileSDK13NotifyService")
@interface NotifyService : NSObject <ServiceProtocol>
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK14OpenURLService")
@interface OpenURLService : NSObject <ServiceProtocol>
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface PGSDKLogger (SWIFT_EXTENSION(PredixMobileSDK))
@end

@class NSURL;
enum WaitState : NSInteger;
@class WaitStateReturn;

SWIFT_PROTOCOL("_TtP15PredixMobileSDK23PredixAppWindowProtocol_")
@protocol PredixAppWindowProtocol
- (void)loadURL:(NSURL * _Nonnull)URL parameters:(NSDictionary * _Nullable)parameters onComplete:(void (^ _Nullable)(void))onComplete;
- (void)updateWaitState:(enum WaitState)state message:(NSString * _Nullable)message;
- (WaitStateReturn * _Nonnull)waitState;
@optional
- (void)receiveAppNotification:(NSString * _Nonnull)script;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK27PredixMobilityConfiguration")
@interface PredixMobilityConfiguration : NSObject
+ (BOOL)automaticallyListenForApplicationStateEvents;
+ (void)setAutomaticallyListenForApplicationStateEvents:(BOOL)value;
+ (PGSDKLoggerLevelEnum)defaultLoggingLevel;
+ (void)setDefaultLoggingLevel:(PGSDKLoggerLevelEnum)value;
+ (NSString * _Nonnull)defaultDatabaseName;
+ (void)setDefaultDatabaseName:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)authenticationScheme;
+ (void)setAuthenticationScheme:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)authenticationGrantIndicator;
+ (void)setAuthenticationGrantIndicator:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)loggingLevelConfigKey;
+ (void)setLoggingLevelConfigKey:(NSString * _Nonnull)value;
+ (enum ConfigurationLocation)loggingLevelConfigLocation;
+ (void)setLoggingLevelConfigLocation:(enum ConfigurationLocation)value;
+ (NSString * _Nonnull)traceLogsRequestsConfigKey;
+ (void)setTraceLogsRequestsConfigKey:(NSString * _Nonnull)value;
+ (enum ConfigurationLocation)traceLogsRequestsConfigLocation;
+ (void)setTraceLogsRequestsConfigLocation:(enum ConfigurationLocation)value;
+ (NSString * _Nonnull)serverEndpointConfigKey;
+ (void)setServerEndpointConfigKey:(NSString * _Nonnull)value;
+ (enum ConfigurationLocation)serverEndpointConfigLocation;
+ (void)setServerEndpointConfigLocation:(enum ConfigurationLocation)value;
+ (NSString * _Nonnull)userSessionURLPath;
+ (void)setUserSessionURLPath:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)loginURLPath;
+ (void)setLoginURLPath:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)logoutURLPath;
+ (void)setLogoutURLPath:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)dataReplicationURLPath;
+ (void)setDataReplicationURLPath:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)authorizationCheckURLPath;
+ (void)setAuthorizationCheckURLPath:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)userSessionUsernameKey;
+ (void)setUserSessionUsernameKey:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)userSessionAuthenticatedKey;
+ (void)setUserSessionAuthenticatedKey:(NSString * _Nonnull)value;
+ (NSString * _Nullable)userSessionDatabaseNameKey;
+ (void)setUserSessionDatabaseNameKey:(NSString * _Nullable)value;
+ (NSString * _Nonnull)pmappDocumentNameKey;
+ (void)setPmappDocumentNameKey:(NSString * _Nonnull)value;
+ (enum ConfigurationLocation)pmappDocumentNameConfigLocation;
+ (void)setPmappDocumentNameConfigLocation:(enum ConfigurationLocation)value;
+ (NSString * _Nonnull)pmappDocumentVersionKey;
+ (void)setPmappDocumentVersionKey:(NSString * _Nonnull)value;
+ (enum ConfigurationLocation)pmappDocumentVersionConfigLocation;
+ (void)setPmappDocumentVersionConfigLocation:(enum ConfigurationLocation)value;
+ (NSString * _Nonnull)pmAppDocumentWebAppNameKey;
+ (void)setPmAppDocumentWebAppNameKey:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)pmAppDocumentOfflineAppNameKey;
+ (void)setPmAppDocumentOfflineAppNameKey:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)pmAppDocumentDependenciesKey;
+ (void)setPmAppDocumentDependenciesKey:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)API_HOST;
+ (void)setAPI_HOST:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)seriousErrorDefaultMessage;
+ (void)setSeriousErrorDefaultMessage:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)seriousErrorPage;
+ (void)setSeriousErrorPage:(NSString * _Nonnull)value;
+ (void (^ _Nullable)(void (^ _Nonnull)(void)))additionalBootRestartWorkflow;
+ (void)setAdditionalBootRestartWorkflow:(void (^ _Nullable)(void (^ _Nonnull)(void)))value;
+ (NSArray<Class <ServiceProtocol>> * _Nullable)additionalBootServicesToRegister;
+ (void)setAdditionalBootServicesToRegister:(NSArray<Class <ServiceProtocol>> * _Nullable)value;
+ (BOOL)shouldLogUnhandledErrors;
+ (void)setShouldLogUnhandledErrors:(BOOL)value;
+ (BOOL)shouldInitializeDefaultsFromSettings;
+ (void)setShouldInitializeDefaultsFromSettings:(BOOL)value;
+ (BOOL)shouldIssueWarningsForPlaceholderURLs;
+ (void)setShouldIssueWarningsForPlaceholderURLs:(BOOL)value;
+ (BOOL)requireDevicePasscodeSet;
+ (void)setRequireDevicePasscodeSet:(BOOL)value;
+ (NSString * _Nonnull)defaultInitializationDetectionKey;
+ (void)setDefaultInitializationDetectionKey:(NSString * _Nonnull)value;
+ (BOOL)traceLogsAllRequestsDefault;
+ (void)setTraceLogsAllRequestsDefault:(BOOL)value;
+ (NSDictionary<NSString *, id> * _Nullable)remoteNotificationRegistrationAdditionalInfo;
+ (void)setRemoteNotificationRegistrationAdditionalInfo:(NSDictionary<NSString *, id> * _Nullable)value;
+ (NSString * _Nonnull)remoteNotificationRegistrationDocumentId;
+ (void)setRemoteNotificationRegistrationDocumentId:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)remoteNotificationRegistrationDocumentType;
+ (void)setRemoteNotificationRegistrationDocumentType:(NSString * _Nonnull)value;
+ (NSDictionary<NSString *, id> * _Nullable)replicationAdditionalPushSettings;
+ (void)setReplicationAdditionalPushSettings:(NSDictionary<NSString *, id> * _Nullable)value;
+ (NSDictionary<NSString *, id> * _Nullable)replicationAdditionalPullSettings;
+ (void)setReplicationAdditionalPullSettings:(NSDictionary<NSString *, id> * _Nullable)value;
+ (NSString * _Nullable)keychainAccessGroup;
+ (void)setKeychainAccessGroup:(NSString * _Nullable)value;
+ (NSString * _Nonnull)keychainKeyPrefix;
+ (void)setKeychainKeyPrefix:(NSString * _Nonnull)value;
+ (NSString * _Nonnull)versionInfo;
+ (BOOL)considerUIReadyWhenApplicationDidBecomeActive;
+ (void)setConsiderUIReadyWhenApplicationDidBecomeActive:(BOOL)value;
+ (NSURL * _Nonnull)localStorageURL;
+ (NSURL * _Nullable)userLocalStorageURL;
+ (void)loadConfiguration;
+ (void)appendDataViewDefinition:(NSString * _Nonnull)viewName version:(NSString * _Nonnull)version mapFunction:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull, void (^ _Nonnull)(id _Nonnull, id _Nullable)))mapFunction;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSNotification;
@class UIApplication;
@class UILocalNotification;
@class NSData;
@class NSError;

SWIFT_CLASS("_TtC15PredixMobileSDK21PredixMobilityManager")
@interface PredixMobilityManager : NSObject
+ (PredixMobilityManager * _Nonnull)sharedInstance;
@property (nonatomic, strong) id <PredixAppWindowProtocol> _Nonnull packageWindow;
@property (nonatomic, copy) id <PredixAppWindowProtocol> _Nonnull (^ _Nonnull presentAuthentication)(id <PredixAppWindowProtocol> _Nonnull);
@property (nonatomic, copy) void (^ _Nonnull dismissAuthentication)(id <PredixAppWindowProtocol> _Nonnull);
@property (nonatomic, copy) NSArray<NSDictionary<NSString *, id> *> * _Nullable localOrRemoteNotifications;
@property (nonatomic, readonly) BOOL isShowingAuthentication;
@property (nonatomic, readonly, strong) id <PredixAppWindowProtocol> _Nonnull currentWindow;
- (nonnull instancetype)initWithPackageWindow:(id <PredixAppWindowProtocol> _Nonnull)packageWindow presentAuthentication:(id <PredixAppWindowProtocol> _Nonnull (^ _Nonnull)(id <PredixAppWindowProtocol> _Nonnull))presentAuthentication dismissAuthentication:(void (^ _Nonnull)(id <PredixAppWindowProtocol> _Nonnull))dismissAuthentication OBJC_DESIGNATED_INITIALIZER;
- (void)showAuthentication:(NSURL * _Nonnull)URL onComplete:(void (^ _Nullable)(void))onComplete;
- (void)showAuthentication:(NSURL * _Nonnull)URL parameters:(NSDictionary * _Nullable)parameters onComplete:(void (^ _Nullable)(void))onComplete;
- (void)authenticationComplete;
- (void)showPackageWindow:(NSURL * _Nonnull)URL parameters:(NSDictionary * _Nullable)parameters onComplete:(void (^ _Nullable)(void))onComplete;
- (void)startApp;
- (void)callBootService;
- (void)ShowUserError:(NSString * _Nonnull)msg;
- (void)addTranslationForNotification:(NSString * _Nonnull)originalNotificationName asNotificationName:(NSString * _Nonnull)asNotificationName translation:(NSDictionary<NSString *, id> * _Nullable (^ _Nonnull)(NSNotification * _Nonnull))translation;
- (void)removeTranslationForNotificationName:(NSString * _Nonnull)notificationName;
- (void)applicationWillResignActive:(UIApplication * _Nonnull)application;
- (void)applicationDidEnterBackground:(UIApplication * _Nonnull)application;
- (void)applicationWillEnterForeground:(UIApplication * _Nonnull)application;
- (void)applicationDidBecomeActive:(UIApplication * _Nonnull)application;
- (void)applicationWillTerminate:(UIApplication * _Nonnull)application;
- (void)application:(UIApplication * _Nonnull)application didReceiveLocalNotification:(UILocalNotification * _Nonnull)notification;
- (void)application:(UIApplication * _Nonnull)application didReceiveRemoteNotification:(NSDictionary * _Nonnull)userInfo;
- (void)application:(UIApplication * _Nonnull)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData * _Nonnull)deviceToken;
- (void)application:(UIApplication * _Nonnull)application didFailToRegisterForRemoteNotificationsWithError:(NSError * _Nonnull)error;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK25ReachabilityStatusWrapper")
@interface ReachabilityStatusWrapper : NSObject
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
@end



SWIFT_PROTOCOL("_TtP15PredixMobileSDK21ServiceRouterProtocol_")
@protocol ServiceRouterProtocol
- (BOOL)registerService:(Class <ServiceProtocol> _Nonnull)service;
- (void)unregisterService:(Class <ServiceProtocol> _Nonnull)service;
- (void)processRequest:(NSURLRequest * _Nonnull)request responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
- (void)processRequestWithServiceId:(NSString * _Nonnull)serviceId responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
- (void)processRequest:(NSString * _Nonnull)serviceId extraPath:(NSString * _Nullable)extraPath responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
- (void)processRequest:(NSString * _Nonnull)serviceId extraPath:(NSString * _Nullable)extraPath method:(NSString * _Nonnull)method data:(NSData * _Nullable)data responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK13ServiceRouter")
@interface ServiceRouter : NSObject <ServiceRouterProtocol>
+ (id <ServiceRouterProtocol> _Nonnull)sharedInstance;
- (BOOL)registerService:(Class <ServiceProtocol> _Nonnull)service;
- (void)unregisterService:(Class <ServiceProtocol> _Nonnull)service;
- (void)processRequestWithServiceId:(NSString * _Nonnull)serviceId responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
- (void)processRequest:(NSString * _Nonnull)serviceId extraPath:(NSString * _Nullable)extraPath responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
- (void)processRequest:(NSString * _Nonnull)serviceId extraPath:(NSString * _Nullable)extraPath method:(NSString * _Nonnull)method data:(NSData * _Nullable)data responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
- (void)processRequest:(NSURLRequest * _Nonnull)request responseBlock:(responseReturnBlock _Nonnull)responseBlock dataBlock:(dataReturnBlock _Nonnull)dataBlock completionBlock:(requestCompleteBlock _Nonnull)completionBlock;
@end



SWIFT_CLASS("_TtC15PredixMobileSDK11UserService")
@interface UserService : NSObject <ServiceProtocol>
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15PredixMobileSDK19UserSettingsService")
@interface UserSettingsService : NSObject <ServiceProtocol>
+ (NSString * _Nonnull)serviceIdentifier;
+ (void)performRequest:(NSURLRequest * _Nonnull)request response:(NSHTTPURLResponse * _Nonnull)response responseReturn:(responseReturnBlock _Nonnull)responseReturn dataReturn:(dataReturnBlock _Nonnull)dataReturn requestComplete:(requestCompleteBlock _Nonnull)requestComplete;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, WaitState) {
  WaitStateWaiting = 0,
  WaitStateNotWaiting = 1,
};


SWIFT_CLASS("_TtC15PredixMobileSDK15WaitStateReturn")
@interface WaitStateReturn : NSObject
- (nonnull instancetype)initWithState:(enum WaitState)state message:(NSString * _Nullable)message OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init:(enum WaitState)state :(NSString * _Nullable)message OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithState:(enum WaitState)state OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init:(enum WaitState)state OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop