void CsrWifiNmeApUpstreamStateHandlers(void* drvpriv, CsrWifiFsmEvent* msg)
{
switch(msg->type) {
case CSR_WIFI_NME_AP_START_CFM:
CsrWifiNmeApStartCfmHandler(drvpriv, msg);
break;
case CSR_WIFI_NME_AP_STOP_CFM:
CsrWifiNmeApStopCfmHandler(drvpriv, msg);
break;
case CSR_WIFI_NME_AP_CONFIG_SET_CFM:
CsrWifiNmeApConfigSetCfmHandler(drvpriv,msg);
break;
default:
unifi_error(drvpriv, "CsrWifiNmeApUpstreamStateHandlers: unhandled NME_AP message type 0x%.4X\n",msg->type);
break;
}
}
