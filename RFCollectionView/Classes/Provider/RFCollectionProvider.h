//
//  RFCollectionProvider.h
//  Masonry
//
//  Created by qianjie on 2017/12/22.
//

#import <Foundation/Foundation.h>
#import <RFCollectionView/RFCollectionDataProvider.h>
#import <RFCollectionView/RFCollectionViewProvider.h>

typedef CGSize (^RFCollectionSizeProvider)(NSUInteger index, __kindof NSObject *data, CGSize collectionViewSize);

@interface RFCollectionProvider : NSObject

@property (nonatomic, strong) RFCollectionDataProvider *dataProvider;
@property (nonatomic, strong) RFCollectionViewProvider *viewProvider;


@end
