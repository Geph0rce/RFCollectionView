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

@interface RFCollectionProvider<Data, View> : NSObject

@property (nonatomic, strong) RFCollectionDataProvider<Data> *dataProvider;
@property (nonatomic, strong) RFCollectionViewProvider<Data, View> *viewProvider;
@property (nonatomic, copy) RFCollectionSizeProvider sizeProvider;
@end
