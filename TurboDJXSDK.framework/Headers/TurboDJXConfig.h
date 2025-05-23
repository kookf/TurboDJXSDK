//
//  TurboDJXConfig.h
//  TurboDJXSDK
//
//  Created by qy on 2025/4/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ShortPlayRewardsSuccessDelegate <NSObject>

@optional
- (void)rewardsSuccess;

@end


@protocol ShortVideoRewardsViewDelegate <NSObject>

@required
- (void)getRewards;

@end

@interface TurboDJXConfig : NSObject

//自定义短故事信息流广告位ID  必设置项
@property (nonatomic, strong) NSString *storyNativePlacementID;
//自定义短故事激励广告位ID    必设置项
@property (nonatomic, strong) NSString *storyRewardPlacementID;
//自定义短剧激励广告位ID     必设置项
@property (nonatomic, strong) NSString *videoRewardPlacementID;


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
@property (nonatomic, assign) id<ShortPlayRewardsSuccessDelegate> rewardSuccessDelegate;

//短故事信息流广告每多少页出现一次（2-4之间, 默认3）
@property (nonatomic, assign) int NOV_INSERT_INTERVAL;
//短故事信息流广告插入在第几行下面 （0-5之间, 默认3）
@property (nonatomic, assign) int NOV_START_LINE_NUMBER;


//短视频是否隐藏关注按钮 默认 false
@property (nonatomic, assign) bool hideVideoFollow;
//短视频倒计时奖励视图delegate  不设置代表不显示倒计时视图
@property (nonatomic, assign) id<ShortVideoRewardsViewDelegate> rewardDelegate;
//短视频倒计时奖励视图位置(倒计时控件宽高固定为60)
@property (nonatomic, assign) CGPoint rewardOrigin;


+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
