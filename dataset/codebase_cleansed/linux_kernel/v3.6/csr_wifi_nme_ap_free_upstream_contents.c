void CsrWifiNmeApFreeUpstreamMessageContents(u16 eventClass, void *message)
{
if (eventClass != CSR_WIFI_NME_AP_PRIM)
{
return;
}
if (NULL == message)
{
return;
}
}
