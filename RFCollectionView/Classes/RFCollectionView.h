//
//  RFCollectionView.h
//  RFCollectionView
//
//  Created by Roger on 2017/12/22.
//

#import <UIKit/UIKit.h>

typedef void (^RFCollectionViewUpdater)(__kindof UIView *view, id data, NSInteger index);

@interface RFCollectionView : UIScrollView

@property (nonatomic, copy) RFCollectionViewUpdater viewUpdater;
@property (nonatomic, strong) NSArray *data;

- (void)reloadData;

@end
