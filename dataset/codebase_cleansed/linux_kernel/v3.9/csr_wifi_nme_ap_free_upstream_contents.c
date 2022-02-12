void CsrWifiNmeApFreeUpstreamMessageContents(u16 eventClass, void *message)\r\n{\r\nif (eventClass != CSR_WIFI_NME_AP_PRIM)\r\n{\r\nreturn;\r\n}\r\nif (NULL == message)\r\n{\r\nreturn;\r\n}\r\n}
