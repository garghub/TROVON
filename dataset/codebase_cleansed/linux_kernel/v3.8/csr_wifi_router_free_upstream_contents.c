void CsrWifiRouterFreeUpstreamMessageContents(u16 eventClass, void *message)
{
if (eventClass != CSR_WIFI_ROUTER_PRIM)
return;
if (NULL == message)
return;
switch (*((CsrWifiRouterPrim *) message)) {
case CSR_WIFI_ROUTER_MA_PACKET_IND:
{
CsrWifiRouterMaPacketInd *p =
(CsrWifiRouterMaPacketInd *) message;
kfree(p->frame);
p->frame = NULL;
break;
}
default:
break;
}
}
