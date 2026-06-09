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

typedef void (^TurboDjxCompletionHandler)(BOOL success, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface TurboDJXSDK : NSObject

typedef void (^playletCompletionHandler)(NSArray<DJXPlayletInfoModel *> * _Nullable playletList, NSError * _Nullable error);


+ (instancetype)sharedInstance;

//获取版本号
+ (NSString *)SDKVerson;

//初始化短剧
- (void)initPlayetSDKWithAppID:(NSString *)appId
    configName:(NSString *)configName
    completionHandler:(TurboDjxCompletionHandler _Nullable)completionHandler;

//初始化短视频
- (void)initShortVideoWithAppID:(NSString *)appId
    completionHandler:(TurboDjxCompletionHandler _Nullable)completionHandler;

//短剧列表控制器
- (UIViewController *)configPlayletTheater;

//滑滑流短剧控制器
- (UIViewController *)configPlayletVC;
//滑滑流短剧控制器，指定view size
- (UIViewController *)configPlayletVCWithViewSize:(CGSize)viewSize;

//短视频控制器
-(UIViewController *)configShortVideoVCWithPosId:(NSString *)posId;

////短视频控制器
//- (UIViewController *)configVideoVC;
//
////短视频----仅推荐
//- (UIViewController *)configRecommendVideoVC;
//
////短视频---仅关注
//- (UIViewController *)configFollowVideoVC;

/// 获取短剧的收藏列表
/// - Parameters:
///   - page: 第几页
///   - number: 一页多少个
///   - playletCompletionHandler: 结果回调
- (void)requestPlayletCollectionListWithPage:(NSInteger)pageIndex pageSize:(NSInteger)pageSize completion:(playletCompletionHandler)completion;

/// 获取短剧的播放记录列表
/// - Parameters:
///   - page: 第几页
///   - number: 一页多少个
///   - playletCompletionHandler: 结果回调
- (void)requestPlayletHistoryListWithPage:(NSInteger)pageIndex pageSize:(NSInteger)pageSize completion:(playletCompletionHandler)completion;

//根据短剧model进入短剧播放页
- (void)enterPlayerWithModel:(DJXPlayletInfoModel *)model;

@end

NS_ASSUME_NONNULL_END
