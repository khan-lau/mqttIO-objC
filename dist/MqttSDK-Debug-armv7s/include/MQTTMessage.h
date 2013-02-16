//
//  MQTTMessage.h
//  MQtt Client
//
//  Created by Kyle Roche on 8/21/11.
//  Copyright (c) 2011 2lemetry, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MQTTMessage : NSObject {
    UInt8    type;
    UInt8    qos;
    BOOL     retainFlag;
    BOOL     dupFlag;
    NSData*  data;
}

enum {
    MQTTConnect = 1,
    MQTTConnack = 2,
    MQTTPublish = 3,
    MQTTPuback = 4,
    MQTTPubrec = 5,
    MQTTPubrel = 6,
    MQTTPubcomp = 7,
    MQTTSubscribe = 8,
    MQTTSuback = 9,
    MQTTUnsubscribe = 10,
    MQTTUnsuback = 11,
    MQTTPingreq = 12,
    MQTTPingresp = 13,
    MQTTDisconnect = 14
};

// instance methods
+ (id)connectMessageWithClientId:(NSString*)clientId
                        userName:(NSString*)userName
                        password:(NSString*)password
                       keepAlive:(NSInteger)keeplive
                    cleanSession:(BOOL)cleanSessionFlag;
+ (id)pingreqMessage;
+ (id)subscribeMessageWithMessageId:(UInt16)msgId
                              topic:(NSString*)topic
                                qos:(UInt8)qos;
+ (id)unsubscribeMessageWithMessageId:(UInt16)msgId
                                topic:(NSString*)topic;
+ (id)publishMessageWithData:(NSData*)payload
                     onTopic:(NSString*)theTopic
                     retainFlag:(BOOL)retain;
+ (id)publishMessageWithData:(NSData*)payload
                     onTopic:(NSString*)topic
                         qos:(UInt8)qosLevel
                       msgId:(UInt16)msgId
                  retainFlag:(BOOL)retain
                     dupFlag:(BOOL)dup;
+ (id)pubackMessageWithMessageId:(UInt16)msgId;
+ (id)pubrecMessageWithMessageId:(UInt16)msgId;
+ (id)pubrelMessageWithMessageId:(UInt16)msgId;
+ (id)pubcompMessageWithMessageId:(UInt16)msgId;

- (id)initWithType:(UInt8)aType;
- (id)initWithType:(UInt8)aType data:(NSData*)aData;
- (id)initWithType:(UInt8)aType
               qos:(UInt8)aQos
              data:(NSData*)aData;
- (id)initWithType:(UInt8)aType
               qos:(UInt8)aQos
        retainFlag:(BOOL)aRetainFlag
           dupFlag:(BOOL)aDupFlag
              data:(NSData*)aData;
- (void)setDupFlag;
- (UInt8)type;
- (UInt8)qos;
- (BOOL)retainFlag;
- (BOOL)isDuplicate;
- (NSData*)data;
- (void)dealloc;

@end

@interface NSMutableData (MQTT)
- (void)appendByte:(UInt8)byte;
- (void)appendUInt16BigEndian:(UInt16)val;
- (void)appendMQTTString:(NSString*)s;

@end
