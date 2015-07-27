//
// Created by fireflyc 
//

#import <Foundation/Foundation.h>

@class AMQPBasicProperties;


@interface AMQPOutputStream : NSObject

- (void)AMQPWriteUInt8:(UInt8)val;

- (void)AMQPWriteUInt16:(UInt16)val;

- (void)AMQPWriteUInt32:(UInt32)val;

- (void)AMQPWriteUInt64:(UInt64)val;

- (void)AMQPWriteShortStr:(NSString *)val;

- (void)AMQPWriteLongStr:(NSString *)val;

- (void)AMQPWriteNSDictionary:(NSDictionary *)val;

- (void)AMQPWriteData:(NSData *)data;

- (void)AMQPWriteProperties:(AMQPBasicProperties *)properties;

- (instancetype)init;

@property NSMutableData *data;

- (void)AMQPWriteDate:(NSDate *)date;
@end

@interface AMQPInputStream : NSObject
- (UInt8)AMQPReadUInt8;

- (UInt16)AMQPReadUInt16;

- (UInt32)AMQPReadUInt32;

- (UInt64)AMQPReadUInt64;

- (NSString *)AMQPReadShortStr;

- (NSString *)AMQPReadLongStr;

- (NSDate *)AMQPReadDate;

- (NSDictionary *)AMQPReadNSDictionary;

- (AMQPBasicProperties *)AMQPReadProperties;

- (instancetype)initWithData:(NSData *)data;

- (char *)AMQPReadBytesWithLen:(size_t)len;

- (void)reset;

- (void)resetToOffset:(size_t)offset;

@property NSData *data;
@end