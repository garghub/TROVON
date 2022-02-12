CsrMsgConvMsgEntry* CsrWifiRouterConverterLookup(CsrMsgConvMsgEntry *ce, u16 msgType)
{
if (msgType & CSR_PRIM_UPSTREAM)
{
u16 idx = (msgType & ~CSR_PRIM_UPSTREAM) + CSR_WIFI_ROUTER_PRIM_DOWNSTREAM_COUNT;
if (idx < (CSR_WIFI_ROUTER_PRIM_UPSTREAM_COUNT + CSR_WIFI_ROUTER_PRIM_DOWNSTREAM_COUNT) &&
csrwifirouter_conv_lut[idx].msgType == msgType)
{
return &csrwifirouter_conv_lut[idx];
}
}
else
{
if (msgType < CSR_WIFI_ROUTER_PRIM_DOWNSTREAM_COUNT &&
csrwifirouter_conv_lut[msgType].msgType == msgType)
{
return &csrwifirouter_conv_lut[msgType];
}
}
return NULL;
}
void CsrWifiRouterConverterInit(void)
{
CsrMsgConvInsert(CSR_WIFI_ROUTER_PRIM, csrwifirouter_conv_lut);
CsrMsgConvCustomLookupRegister(CSR_WIFI_ROUTER_PRIM, CsrWifiRouterConverterLookup);
}
const CsrLogPrimitiveInformation* CsrWifiRouterTechInfoGet(void)
{
return &csrwifirouter_conv_info;
}
