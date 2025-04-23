//
//  TurboDJXSDK.h
//  TurboDJXSDK
//
//  Created by qy on 2025/4/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TurboDJXConfig.h"
#import <PangrowthDJX/PangrowthDJX.h>

NS_ASSUME_NONNULL_BEGIN

@interface TurboDJXSDK : NSObject

typedef void (^completionHandler)(NSArray<DJXPlayletInfoModel *> *list);

+ (instancetype)sharedInstance;

//获取版本号
+ (void)getSDKVerson;

//初始化
- (void)initSDKWithAppID:(NSString *)appID WithConfigName:(NSString *)configName;

//短剧列表控制器
- (UIViewController *)configPlayletTheater;

//滑滑流短剧控制器
- (UIViewController *)configPlayletVC;

//短故事控制器
- (UIViewController *)configMiniStoryVC;

//短视频控制器
- (UIViewController *)configVideoVC;

/// 获取短剧的收藏列表
/// - Parameters:
///   - page: 第几页
///   - number: 一页多少个
///   - completeHandler: 结果回调
- (void)requestCollectionList:(NSInteger)pageIndex pageSize:(NSInteger)pageSize completion:(completionHandler)completion;

@end

NS_ASSUME_NONNULL_END
