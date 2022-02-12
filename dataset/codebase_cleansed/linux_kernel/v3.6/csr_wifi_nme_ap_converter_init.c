CsrMsgConvMsgEntry* CsrWifiNmeApConverterLookup(CsrMsgConvMsgEntry *ce, u16 msgType)
{
if (msgType & CSR_PRIM_UPSTREAM)
{
u16 idx = (msgType & ~CSR_PRIM_UPSTREAM) + CSR_WIFI_NME_AP_PRIM_DOWNSTREAM_COUNT;
if (idx < (CSR_WIFI_NME_AP_PRIM_UPSTREAM_COUNT + CSR_WIFI_NME_AP_PRIM_DOWNSTREAM_COUNT) &&
csrwifinmeap_conv_lut[idx].msgType == msgType)
{
return &csrwifinmeap_conv_lut[idx];
}
}
else
{
if (msgType < CSR_WIFI_NME_AP_PRIM_DOWNSTREAM_COUNT &&
csrwifinmeap_conv_lut[msgType].msgType == msgType)
{
return &csrwifinmeap_conv_lut[msgType];
}
}
return NULL;
}
void CsrWifiNmeApConverterInit(void)
{
CsrMsgConvInsert(CSR_WIFI_NME_AP_PRIM, csrwifinmeap_conv_lut);
CsrMsgConvCustomLookupRegister(CSR_WIFI_NME_AP_PRIM, CsrWifiNmeApConverterLookup);
}
const CsrLogPrimitiveInformation* CsrWifiNmeApTechInfoGet(void)
{
return &csrwifinmeap_conv_info;
}
