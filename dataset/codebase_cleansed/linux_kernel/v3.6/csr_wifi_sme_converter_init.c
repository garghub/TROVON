CsrMsgConvMsgEntry* CsrWifiSmeConverterLookup(CsrMsgConvMsgEntry *ce, u16 msgType)
{
if (msgType & CSR_PRIM_UPSTREAM)
{
u16 idx = (msgType & ~CSR_PRIM_UPSTREAM) + CSR_WIFI_SME_PRIM_DOWNSTREAM_COUNT;
if (idx < (CSR_WIFI_SME_PRIM_UPSTREAM_COUNT + CSR_WIFI_SME_PRIM_DOWNSTREAM_COUNT) &&
csrwifisme_conv_lut[idx].msgType == msgType)
{
return &csrwifisme_conv_lut[idx];
}
}
else
{
if (msgType < CSR_WIFI_SME_PRIM_DOWNSTREAM_COUNT &&
csrwifisme_conv_lut[msgType].msgType == msgType)
{
return &csrwifisme_conv_lut[msgType];
}
}
return NULL;
}
void CsrWifiSmeConverterInit(void)
{
CsrMsgConvInsert(CSR_WIFI_SME_PRIM, csrwifisme_conv_lut);
CsrMsgConvCustomLookupRegister(CSR_WIFI_SME_PRIM, CsrWifiSmeConverterLookup);
}
const CsrLogPrimitiveInformation* CsrWifiSmeTechInfoGet(void)
{
return &csrwifisme_conv_info;
}
