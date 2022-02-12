CsrMsgConvMsgEntry* CsrWifiRouterCtrlConverterLookup(CsrMsgConvMsgEntry *ce, u16 msgType)
{
if (msgType & CSR_PRIM_UPSTREAM)
{
u16 idx = (msgType & ~CSR_PRIM_UPSTREAM) + CSR_WIFI_ROUTER_CTRL_PRIM_DOWNSTREAM_COUNT;
if (idx < (CSR_WIFI_ROUTER_CTRL_PRIM_UPSTREAM_COUNT + CSR_WIFI_ROUTER_CTRL_PRIM_DOWNSTREAM_COUNT) &&
csrwifirouterctrl_conv_lut[idx].msgType == msgType)
{
return &csrwifirouterctrl_conv_lut[idx];
}
}
else
{
if (msgType < CSR_WIFI_ROUTER_CTRL_PRIM_DOWNSTREAM_COUNT &&
csrwifirouterctrl_conv_lut[msgType].msgType == msgType)
{
return &csrwifirouterctrl_conv_lut[msgType];
}
}
return NULL;
}
void CsrWifiRouterCtrlConverterInit(void)
{
CsrMsgConvInsert(CSR_WIFI_ROUTER_CTRL_PRIM, csrwifirouterctrl_conv_lut);
CsrMsgConvCustomLookupRegister(CSR_WIFI_ROUTER_CTRL_PRIM, CsrWifiRouterCtrlConverterLookup);
}
const CsrLogPrimitiveInformation* CsrWifiRouterCtrlTechInfoGet(void)
{
return &csrwifirouterctrl_conv_info;
}
