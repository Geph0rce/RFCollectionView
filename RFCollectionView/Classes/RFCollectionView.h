//
//  RFCollectionView.h
//  RFCollectionView
//
//  Created by Roger on 2017/12/22.
//

#import <UIKit/UIKit.h>

typedef void (^RFCollectionViewProvider)(__kindof UIView *view, id data, NSInteger index);

@interface RFCollectionView : UIScrollView

@property (nonatomic, copy) RFCollectionViewProvider viewProvider;
@property (nonatomic, strong) NSArray *data;

- (void)reloadData;

@end
