//
//  RFCommonMacros.h
//  Pods
//
//  Created by Roger on 2017/12/6.
//

#ifndef RFCommonMacros_h
#define RFCommonMacros_h


#import <RFFoundation/EXTScope.h>
#import <RFFoundation/EXTSynthesize.h>

#define let __auto_type const
#define var __auto_type
#define guard(CONDITION) if (CONDITION) {}

#define APPDELEGATE ((AppDelegate *)[[UIApplication sharedApplication] delegate])

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define WINDOW_HEIGHT_WITHOUT_STATUS_BAR ([[[[UIApplication sharedApplication] windows] objectAtIndex:0] frame].size.height - 20)

#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_SCALE [UIScreen mainScreen].bounds.size.width / 320

#define IS_IPHONEX (SCREEN_WIDTH == 375.f && SCREEN_HEIGHT == 812.f ? YES : NO)
#define IS_IPHONEX_BOTTOM_HEIGHT (IS_IPHONEX ? 34 : 0)
#define IS_IPHONEX_BOTTOM (IS_IPHONEX ? 14 : 0)

#define IS_4INCH_SCREEN  (([[UIScreen mainScreen] bounds].size.height == 568) ? YES : NO)
#define IS_35INCH_SCREEN ([[UIScreen mainScreen] bounds].size.height < 568)
#define IS_47INCH_SCREEN (([[UIScreen mainScreen] bounds].size.height == 667) ? YES : NO)
#define IS_55INCH_SCREEN (([[UIScreen mainScreen] bounds].size.height == 736) ? YES : NO)

#define IOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]

#define IS_IOS7 ([[UIDevice currentDevice].systemVersion doubleValue] >= 7.0 && [[UIDevice currentDevice].systemVersion doubleValue] < 8.0)
#define IS_IOS8 ([[UIDevice currentDevice].systemVersion doubleValue] >= 8.0 && [[UIDevice currentDevice].systemVersion doubleValue] < 9.0)
#define IS_IOS9 ([[UIDevice currentDevice].systemVersion doubleValue] >= 9.0 && [[UIDevice currentDevice].systemVersion doubleValue] < 10.0)
#define IS_DEVICE_IPAD ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)

#define POINTS_FROM_PIXELS(__PIXELS) (__PIXELS / [[UIScreen mainScreen] scale])
#define ONE_PIXEL POINTS_FROM_PIXELS(1.0)

#if TARGET_OS_IPHONE
//iPhone Device
#endif
#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

#define VIEW_BORDER_RADIUS(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

#define PATH_TEMP NSTemporaryDirectory()
#define PATH_DOCUMENT [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
#define PATH_CACHE [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

#define GET_IMAGE(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]

#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)
#define DISPATCH_Time(time)  dispatch_time(DISPATCH_TIME_NOW, time * NSEC_PER_SEC)
#define DISPATCH_BACK(disTime,block) dispatch_after(disTime, dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^(void){dispatch_async(dispatch_get_main_queue(), block);});

#define FORBIDDEN_ADJUST_SCROLLVIEW_INSETS(controller, scrollview) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
if ([UIScrollView instancesRespondToSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:")]) { \
[scrollview performSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:") withObject:@(2)]; \
} else { \
controller.automaticallyAdjustsScrollViewInsets = NO; \
} \
_Pragma("clang diagnostic pop")

#ifdef DEBUG
#    define DLog(fmt, ...) NSLog((@"%s #%d " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#    define DLog(...)
#endif

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define PREFIXNAME(a) CAT(__, a)
#define MERGENAME(a, b) CAT(a, CAT(_, b))

#define RFPROPERTY_ARRAY(genericType, propertyName) RFPROPERTYDEAIL_ARRAY(genericType, propertyName, nonatomic, strong)
#define RFPROPERTY_DICT(genericType, propertyName) RFPROPERTYDEAIL_DICT(genericType, propertyName, nonatomic, strong)

#if __has_feature(objc_generics)
#define RFPROPERTYDEAIL_ARRAY(genericType, propertyName, ...) \
property (__VA_ARGS__) NSArray <genericType *> *propertyName; \
@property (nonatomic, readonly) BOOL PREFIXNAME(MERGENAME(propertyName, genericType));

#define RFPROPERTYDEAIL_DICT(genericType, propertyName, ...) \
property (__VA_ARGS__) NSDictionary <id<NSCopying>, genericType *> *propertyName; \
@property (nonatomic, readonly) BOOL PREFIXNAME(MERGENAME(propertyName, genericType));

#else
#define RFPROPERTYDEAIL_ARRAY(genericType, propertyName, ...) \
property (__VA_ARGS__) NSArray *propertyName; \
@property (nonatomic, readonly) BOOL PREFIXNAME(MERGENAME(propertyName, genericType));

#define RFPROPERTYDEAIL_DICT(genericType, propertyName, ...) \
property (__VA_ARGS__) NSDictionary *propertyName; \
@property (nonatomic, readonly) BOOL PREFIXNAME(MERGENAME(propertyName, genericType));
#endif

#define INCASE_EMPTY(string, replacement) (string.length ? string : replacement)
#define INCASE_EMPTYSTRING(string) (string.length ? string : @"")

#endif /* RFCommonMacros_h */
