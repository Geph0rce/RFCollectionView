//
//  RFCollectionDataProvider.h
//  Masonry
//
//  Created by qianjie on 2017/12/22.
//

#import <Foundation/Foundation.h>

@interface RFCollectionDataProvider<Data>: NSObject

@property (nonatomic, strong) NSArray<Data> *data;

- (Data)dataAtIndex:(NSUInteger)index;

- (NSUInteger)numberOfItems;

@end
