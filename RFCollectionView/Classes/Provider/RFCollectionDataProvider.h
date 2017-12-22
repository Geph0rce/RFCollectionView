//
//  RFCollectionDataProvider.h
//  Masonry
//
//  Created by qianjie on 2017/12/22.
//

#import <Foundation/Foundation.h>

@interface RFCollectionDataProvider : NSObject

@property (nonatomic, strong) NSArray *data;

- (NSObject *)dataAtIndex:(NSUInteger)index;

@end
