void CsrWifiRouterPfree(void *ptr)
{
kfree(ptr);
}
size_t CsrWifiRouterMaPacketSubscribeReqSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 2;
bufferSize += 4;
return bufferSize;
}
u8* CsrWifiRouterMaPacketSubscribeReqSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiRouterMaPacketSubscribeReq *primitive = (CsrWifiRouterMaPacketSubscribeReq *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint8Ser(ptr, len, (u8) primitive->encapsulation);
CsrUint16Ser(ptr, len, (u16) primitive->protocol);
CsrUint32Ser(ptr, len, (u32) primitive->oui);
return(ptr);
}
void* CsrWifiRouterMaPacketSubscribeReqDes(u8 *buffer, size_t length)
{
CsrWifiRouterMaPacketSubscribeReq *primitive = kmalloc(sizeof(CsrWifiRouterMaPacketSubscribeReq), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->encapsulation, buffer, &offset);
CsrUint16Des((u16 *) &primitive->protocol, buffer, &offset);
CsrUint32Des((u32 *) &primitive->oui, buffer, &offset);
return primitive;
}
size_t CsrWifiRouterMaPacketReqSizeof(void *msg)
{
CsrWifiRouterMaPacketReq *primitive = (CsrWifiRouterMaPacketReq *) msg;
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 2;
bufferSize += primitive->frameLength;
bufferSize += 4;
bufferSize += 2;
bufferSize += 4;
bufferSize += 1;
return bufferSize;
}
u8* CsrWifiRouterMaPacketReqSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiRouterMaPacketReq *primitive = (CsrWifiRouterMaPacketReq *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint8Ser(ptr, len, (u8) primitive->subscriptionHandle);
CsrUint16Ser(ptr, len, (u16) primitive->frameLength);
if (primitive->frameLength)
{
CsrMemCpySer(ptr, len, (const void *) primitive->frame, ((u16) (primitive->frameLength)));
}
CsrUint32Ser(ptr, len, 0);
CsrUint16Ser(ptr, len, (u16) primitive->priority);
CsrUint32Ser(ptr, len, (u32) primitive->hostTag);
CsrUint8Ser(ptr, len, (u8) primitive->cfmRequested);
return(ptr);
}
void* CsrWifiRouterMaPacketReqDes(u8 *buffer, size_t length)
{
CsrWifiRouterMaPacketReq *primitive = kmalloc(sizeof(CsrWifiRouterMaPacketReq), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->subscriptionHandle, buffer, &offset);
CsrUint16Des((u16 *) &primitive->frameLength, buffer, &offset);
if (primitive->frameLength)
{
primitive->frame = kmalloc(primitive->frameLength, GFP_KERNEL);
CsrMemCpyDes(primitive->frame, buffer, &offset, ((u16) (primitive->frameLength)));
}
else
{
primitive->frame = NULL;
}
primitive->freeFunction = NULL;
offset += 4;
CsrUint16Des((u16 *) &primitive->priority, buffer, &offset);
CsrUint32Des((u32 *) &primitive->hostTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->cfmRequested, buffer, &offset);
return primitive;
}
void CsrWifiRouterMaPacketReqSerFree(void *voidPrimitivePointer)
{
CsrWifiRouterMaPacketReq *primitive = (CsrWifiRouterMaPacketReq *) voidPrimitivePointer;
kfree(primitive->frame);
kfree(primitive);
}
size_t CsrWifiRouterMaPacketResSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 2;
return bufferSize;
}
u8* CsrWifiRouterMaPacketResSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiRouterMaPacketRes *primitive = (CsrWifiRouterMaPacketRes *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint8Ser(ptr, len, (u8) primitive->subscriptionHandle);
CsrUint16Ser(ptr, len, (u16) primitive->result);
return(ptr);
}
void* CsrWifiRouterMaPacketResDes(u8 *buffer, size_t length)
{
CsrWifiRouterMaPacketRes *primitive = kmalloc(sizeof(CsrWifiRouterMaPacketRes), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->subscriptionHandle, buffer, &offset);
CsrUint16Des((u16 *) &primitive->result, buffer, &offset);
return primitive;
}
size_t CsrWifiRouterMaPacketCancelReqSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 4;
bufferSize += 2;
bufferSize += 6;
return bufferSize;
}
u8* CsrWifiRouterMaPacketCancelReqSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiRouterMaPacketCancelReq *primitive = (CsrWifiRouterMaPacketCancelReq *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint32Ser(ptr, len, (u32) primitive->hostTag);
CsrUint16Ser(ptr, len, (u16) primitive->priority);
CsrMemCpySer(ptr, len, (const void *) primitive->peerMacAddress.a, ((u16) (6)));
return(ptr);
}
void* CsrWifiRouterMaPacketCancelReqDes(u8 *buffer, size_t length)
{
CsrWifiRouterMaPacketCancelReq *primitive = kmalloc(sizeof(CsrWifiRouterMaPacketCancelReq), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint32Des((u32 *) &primitive->hostTag, buffer, &offset);
CsrUint16Des((u16 *) &primitive->priority, buffer, &offset);
CsrMemCpyDes(primitive->peerMacAddress.a, buffer, &offset, ((u16) (6)));
return primitive;
}
size_t CsrWifiRouterMaPacketSubscribeCfmSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 2;
bufferSize += 2;
return bufferSize;
}
u8* CsrWifiRouterMaPacketSubscribeCfmSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiRouterMaPacketSubscribeCfm *primitive = (CsrWifiRouterMaPacketSubscribeCfm *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint8Ser(ptr, len, (u8) primitive->subscriptionHandle);
CsrUint16Ser(ptr, len, (u16) primitive->status);
CsrUint16Ser(ptr, len, (u16) primitive->allocOffset);
return(ptr);
}
void* CsrWifiRouterMaPacketSubscribeCfmDes(u8 *buffer, size_t length)
{
CsrWifiRouterMaPacketSubscribeCfm *primitive = kmalloc(sizeof(CsrWifiRouterMaPacketSubscribeCfm), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->subscriptionHandle, buffer, &offset);
CsrUint16Des((u16 *) &primitive->status, buffer, &offset);
CsrUint16Des((u16 *) &primitive->allocOffset, buffer, &offset);
return primitive;
}
size_t CsrWifiRouterMaPacketUnsubscribeCfmSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 2;
return bufferSize;
}
u8* CsrWifiRouterMaPacketUnsubscribeCfmSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiRouterMaPacketUnsubscribeCfm *primitive = (CsrWifiRouterMaPacketUnsubscribeCfm *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint16Ser(ptr, len, (u16) primitive->status);
return(ptr);
}
void* CsrWifiRouterMaPacketUnsubscribeCfmDes(u8 *buffer, size_t length)
{
CsrWifiRouterMaPacketUnsubscribeCfm *primitive = kmalloc(sizeof(CsrWifiRouterMaPacketUnsubscribeCfm), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint16Des((u16 *) &primitive->status, buffer, &offset);
return primitive;
}
size_t CsrWifiRouterMaPacketCfmSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 2;
bufferSize += 4;
bufferSize += 2;
return bufferSize;
}
u8* CsrWifiRouterMaPacketCfmSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiRouterMaPacketCfm *primitive = (CsrWifiRouterMaPacketCfm *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint16Ser(ptr, len, (u16) primitive->result);
CsrUint32Ser(ptr, len, (u32) primitive->hostTag);
CsrUint16Ser(ptr, len, (u16) primitive->rate);
return(ptr);
}
void* CsrWifiRouterMaPacketCfmDes(u8 *buffer, size_t length)
{
CsrWifiRouterMaPacketCfm *primitive = kmalloc(sizeof(CsrWifiRouterMaPacketCfm), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint16Des((u16 *) &primitive->result, buffer, &offset);
CsrUint32Des((u32 *) &primitive->hostTag, buffer, &offset);
CsrUint16Des((u16 *) &primitive->rate, buffer, &offset);
return primitive;
}
size_t CsrWifiRouterMaPacketIndSizeof(void *msg)
{
CsrWifiRouterMaPacketInd *primitive = (CsrWifiRouterMaPacketInd *) msg;
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 2;
bufferSize += 2;
bufferSize += primitive->frameLength;
bufferSize += 4;
bufferSize += 2;
bufferSize += 2;
bufferSize += 2;
return bufferSize;
}
u8* CsrWifiRouterMaPacketIndSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiRouterMaPacketInd *primitive = (CsrWifiRouterMaPacketInd *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint8Ser(ptr, len, (u8) primitive->subscriptionHandle);
CsrUint16Ser(ptr, len, (u16) primitive->result);
CsrUint16Ser(ptr, len, (u16) primitive->frameLength);
if (primitive->frameLength)
{
CsrMemCpySer(ptr, len, (const void *) primitive->frame, ((u16) (primitive->frameLength)));
}
CsrUint32Ser(ptr, len, 0);
CsrUint16Ser(ptr, len, (u16) primitive->rssi);
CsrUint16Ser(ptr, len, (u16) primitive->snr);
CsrUint16Ser(ptr, len, (u16) primitive->rate);
return(ptr);
}
void* CsrWifiRouterMaPacketIndDes(u8 *buffer, size_t length)
{
CsrWifiRouterMaPacketInd *primitive = kmalloc(sizeof(CsrWifiRouterMaPacketInd), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->subscriptionHandle, buffer, &offset);
CsrUint16Des((u16 *) &primitive->result, buffer, &offset);
CsrUint16Des((u16 *) &primitive->frameLength, buffer, &offset);
if (primitive->frameLength)
{
primitive->frame = kmalloc(primitive->frameLength, GFP_KERNEL);
CsrMemCpyDes(primitive->frame, buffer, &offset, ((u16) (primitive->frameLength)));
}
else
{
primitive->frame = NULL;
}
primitive->freeFunction = NULL;
offset += 4;
CsrUint16Des((u16 *) &primitive->rssi, buffer, &offset);
CsrUint16Des((u16 *) &primitive->snr, buffer, &offset);
CsrUint16Des((u16 *) &primitive->rate, buffer, &offset);
return primitive;
}
void CsrWifiRouterMaPacketIndSerFree(void *voidPrimitivePointer)
{
CsrWifiRouterMaPacketInd *primitive = (CsrWifiRouterMaPacketInd *) voidPrimitivePointer;
kfree(primitive->frame);
kfree(primitive);
}
