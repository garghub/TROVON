void CsrWifiRouterTransportInit(unifi_priv_t *priv)
{
unifi_trace(priv, UDBG1, "CsrWifiRouterTransportInit: \n");
drvpriv = priv;
(void)CsrMsgConvInit();
CsrWifiRouterConverterInit();
CsrWifiRouterCtrlConverterInit();
CsrWifiSmeConverterInit();
#ifdef CSR_SUPPORT_WEXT
#ifdef CSR_SUPPORT_WEXT_AP
CsrWifiNmeApConverterInit();
#endif
#endif
}
void CsrWifiRouterTransportRecv(unifi_priv_t *priv, u8* buffer, size_t bufferLength)
{
CsrMsgConvMsgEntry* msgEntry;
u16 primType;
CsrSchedQid src;
CsrSchedQid dest;
u16 msgType;
size_t offset = 0;
CsrWifiFsmEvent* msg;
CsrUint16Des(&primType, buffer, &offset);
CsrUint16Des(&src, buffer, &offset);
CsrUint16Des(&dest, buffer, &offset);
CsrUint16Des(&msgType, buffer, &offset);
offset -= 2;
unifi_trace(priv, UDBG4, "CsrWifiRouterTransportRecv: primType=0x%.4X, msgType=0x%.4X, bufferLength=%d\n",
primType, msgType, bufferLength);
if (primType == CSR_WIFI_HOSTIO_PRIM)
{
CsrWifiRouterCtrlHipReq req = {{CSR_WIFI_ROUTER_CTRL_HIP_REQ, CSR_WIFI_ROUTER_CTRL_PRIM, dest, src, NULL}, 0, NULL, 0, NULL, 0, NULL};
req.mlmeCommandLength = bufferLength;
req.mlmeCommand = buffer;
offset += 8;
CsrUint16Des(&req.dataRef1Length, buffer, &offset);
offset += 2;
CsrUint16Des(&req.dataRef2Length, buffer, &offset);
if (req.dataRef1Length)
{
u16 dr1Offset = (bufferLength - req.dataRef2Length) - req.dataRef1Length;
req.dataRef1 = &buffer[dr1Offset];
}
if (req.dataRef2Length)
{
u16 dr2Offset = bufferLength - req.dataRef2Length;
req.dataRef2 = &buffer[dr2Offset];
}
req.mlmeCommandLength -= (req.dataRef1Length + req.dataRef2Length + 6);
req.mlmeCommand = &buffer[6];
CsrWifiRouterCtrlHipReqHandler(priv, &req.common);
return;
}
msgEntry = CsrMsgConvFindEntry(primType, msgType);
if (!msgEntry)
{
unifi_error(priv, "CsrWifiRouterTransportDeserialiseAndSend can not process the message. primType=0x%.4X, msgType=0x%.4X\n",
primType, msgType);
dump(buffer, bufferLength);
return;
}
msg = (CsrWifiFsmEvent*)(msgEntry->deserFunc)(&buffer[offset], bufferLength - offset);
msg->primtype = primType;
msg->type = msgType;
msg->source = src;
msg->destination = dest;
switch(primType)
{
case CSR_WIFI_ROUTER_CTRL_PRIM:
CsrWifiRouterCtrlDownstreamStateHandlers[msg->type - CSR_WIFI_ROUTER_CTRL_PRIM_DOWNSTREAM_LOWEST](priv, msg);
CsrWifiRouterCtrlFreeDownstreamMessageContents(CSR_WIFI_ROUTER_CTRL_PRIM, msg);
break;
case CSR_WIFI_ROUTER_PRIM:
CsrWifiRouterDownstreamStateHandlers[msg->type - CSR_WIFI_ROUTER_PRIM_DOWNSTREAM_LOWEST](priv, msg);
CsrWifiRouterFreeDownstreamMessageContents(CSR_WIFI_ROUTER_PRIM, msg);
break;
case CSR_WIFI_SME_PRIM:
CsrWifiSmeUpstreamStateHandlers[msg->type - CSR_WIFI_SME_PRIM_UPSTREAM_LOWEST](priv, msg);
CsrWifiSmeFreeUpstreamMessageContents(CSR_WIFI_SME_PRIM, msg);
break;
#ifdef CSR_SUPPORT_WEXT
#ifdef CSR_SUPPORT_WEXT_AP
case CSR_WIFI_NME_AP_PRIM:
CsrWifiNmeApUpstreamStateHandlers(priv, msg);
CsrWifiNmeApFreeUpstreamMessageContents(CSR_WIFI_NME_AP_PRIM, msg);
break;
#endif
#endif
default:
unifi_error(priv, "CsrWifiRouterTransportDeserialiseAndSend unhandled prim type 0x%.4X\n", primType);
break;
}
kfree(msg);
}
static void CsrWifiRouterTransportSerialiseAndSend(u16 primType, void* msg)
{
CsrWifiFsmEvent* evt = (CsrWifiFsmEvent*)msg;
CsrMsgConvMsgEntry* msgEntry;
size_t msgSize;
size_t encodeBufferLen = 0;
size_t offset = 0;
u8* encodeBuffer;
unifi_trace(drvpriv, UDBG4, "CsrWifiRouterTransportSerialiseAndSend: primType=0x%.4X, msgType=0x%.4X\n",
primType, evt->type);
msgEntry = CsrMsgConvFindEntry(primType, evt->type);
if (!msgEntry)
{
unifi_error(drvpriv, "CsrWifiRouterTransportSerialiseAndSend can not process the message. primType=0x%.4X, msgType=0x%.4X\n",
primType, evt->type);
return;
}
msgSize = 6 + (msgEntry->sizeofFunc)((void*)msg);
encodeBuffer = kmalloc(msgSize, GFP_KERNEL);
CsrUint16Ser(encodeBuffer, &encodeBufferLen, primType);
CsrUint16Ser(encodeBuffer, &encodeBufferLen, evt->source);
CsrUint16Ser(encodeBuffer, &encodeBufferLen, evt->destination);
(void)(msgEntry->serFunc)(&encodeBuffer[encodeBufferLen], &offset, msg);
encodeBufferLen += offset;
uf_sme_queue_message(drvpriv, encodeBuffer, encodeBufferLen);
kfree(msg);
}
