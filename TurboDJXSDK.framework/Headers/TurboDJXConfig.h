//
//  TurboDJXConfig.h
//  TurboDJXSDK
//
//  Created by qy on 2025/4/22.
//

#import <Foundation/Foundation.h>
#import <PangrowthDJX/PangrowthDJX.h>
#import <PangrowthMiniStory/PangrowthMiniStory.h>

NS_ASSUME_NONNULL_BEGIN

//短故事激励下发代理
@protocol ShortStoryRewardsSuccessDelegate <NSObject>

@optional
- (void)storyRewardsSuccess;

@end

//短故事阅读代理
@protocol ShortStoryReaderDelegate<NSObject>
/// 开始阅读
- (void)startReading:(MNStorySessionContext *)sessionContext;

/// 翻页
- (void)turnPage:(MNStorySessionContext *)sessionContext from:(NSInteger)fromPage to:(NSInteger)toPage;

/// 退出阅读
- (void)stopReading:(MNStorySessionContext *)sessionContext;

/// 整本书读完
- (void)finishReading:(MNStorySessionContext *)sessionContext;
@end

//短剧代理
@protocol ShortPlayDelegate <NSObject>

@optional
- (void)playletRewardsSuccess;
- (void)playletRewardsFailed:(NSString *_Nullable)error;
- (void)playletStopWithModel:(DJXPlayletInfoModel *)model;
- (void)playletPlayWithModel:(DJXPlayletInfoModel *)model;
- (void)playletClose;

@end

//短视频代理
@protocol ShortVideoDelegate <NSObject>

@optional
- (void)shortVideoGetRewards;
- (void)shortVideoRewardsFailed:(NSString *_Nullable)error;
- (void)shortVideoLoadSuccess;
- (void)shortVideoLoadFailed:(NSString *)error;
- (void)shortVideoStopWithVideoId:(NSString *)videoId;
- (void)shortVideoPlayWithVideoId:(NSString *)videoId;
- (void)shortVideoClose;

@end

@interface TurboDJXConfig : NSObject


//自定义短故事信息流广告位ID  必设置项
@property (nonatomic, strong) NSString *storyNativePlacementID;
//自定义短故事激励广告位ID    必设置项
@property (nonatomic, strong) NSString *storyRewardPlacementID;
//自定义短剧激励广告位ID     必设置项
@property (nonatomic, strong) NSString *videoRewardPlacementID;


//激励广告服务端回调设置用户id
@property (nonatomic, strong) NSString *userId;
//激励广告服务端回调设置用户数据
@property (nonatomic, strong) NSString *userData;


//app是否有备案号 默认无
@property (nonatomic, assign) bool icp;
//是否打开青少年模式 默认不打开
@property (nonatomic, assign) bool teenMode;
//是否允许获取idfa 默认允许
@property (nonatomic, assign) bool accessIDFA;


//短剧免费集数 默认10 最大20
@property (nonatomic, assign) int DJX_FREE_SET;
//短剧单次解锁集数 默认5 最大10
@property (nonatomic, assign) int DJX_LOCK_SET;
//短剧是否隐藏收藏按钮 默认 false
@property (nonatomic, assign) bool hideDJXFavorButton;
//短剧是否隐藏点赞按钮 默认 false
@property (nonatomic, assign) bool hideDJXLikeButton;
//短剧激励视频奖励成功回调  不需要这个回调的可以不用配置此项
@property (nonatomic, assign) id<ShortPlayDelegate> playletDelegate;


//短故事信息流广告每多少页出现一次（2-4之间, 默认3）
@property (nonatomic, assign) int NOV_INSERT_INTERVAL;
//短故事信息流广告插入在第几行下面 （0-5之间, 默认3）
@property (nonatomic, assign) int NOV_START_LINE_NUMBER;
//短剧激励视频奖励成功回调  不需要这个回调的可以不用配置此项
@property (nonatomic, weak) id<ShortStoryRewardsSuccessDelegate> storyRewardSuccessDelegate;
@property (nonatomic, weak) id<ShortStoryReaderDelegate> storyReaderDelegate;


//短视频是否隐藏关注按钮 默认 false
@property (nonatomic, assign) bool hideVideoFollow;
//短视频倒计时奖励视图delegate  不设置代表不显示倒计时视图
@property (nonatomic, weak) id<ShortVideoDelegate> videoDelegate;
//如果非全屏展示，建议传一个要展示的size
@property (nonatomic, assign) CGSize shortVideoBouns;
//短视频倒计时奖励视图位置(倒计时控件宽高固定为60)
@property (nonatomic, assign) CGPoint rewardOrigin;

//短剧剧场(短剧列表)是否显示返回按钮，默认不显示
@property (nonatomic, assign) BOOL showPlayletTheaterBackButton;
//短剧滑滑流是否显示返回按钮，默认不显示
@property (nonatomic, assign) BOOL showPlayletBackButton;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
