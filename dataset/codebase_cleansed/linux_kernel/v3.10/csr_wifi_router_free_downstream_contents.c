void CsrWifiRouterFreeDownstreamMessageContents(u16 eventClass, void *message)
{
if (eventClass != CSR_WIFI_ROUTER_PRIM)
{
return;
}
if (NULL == message)
{
return;
}
switch (*((CsrWifiRouterPrim *) message))
{
case CSR_WIFI_ROUTER_MA_PACKET_REQ:
{
CsrWifiRouterMaPacketReq *p = (CsrWifiRouterMaPacketReq *)message;
kfree(p->frame);
p->frame = NULL;
break;
}
default:
break;
}
}
