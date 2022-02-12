void CsrWifiNmeApPfree(void *ptr)
{
kfree(ptr);
}
size_t CsrWifiNmeApConfigSetReqSizeof(void *msg)
{
CsrWifiNmeApConfigSetReq *primitive = (CsrWifiNmeApConfigSetReq *) msg;
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 1;
bufferSize += 2;
bufferSize += 1;
bufferSize += 2;
bufferSize += 1;
bufferSize += 20;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
{
u16 i2;
for (i2 = 0; i2 < 4; i2++)
{
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 2;
bufferSize += 1;
}
}
{
u16 i2;
for (i2 = 0; i2 < 4; i2++)
{
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 2;
bufferSize += 1;
}
}
bufferSize += 1;
bufferSize += 1;
{
u16 i2;
for (i2 = 0; i2 < primitive->apMacConfig.macAddressListCount; i2++)
{
bufferSize += 6;
}
}
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
return bufferSize;
}
u8* CsrWifiNmeApConfigSetReqSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApConfigSetReq *primitive = (CsrWifiNmeApConfigSetReq *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->apConfig.apGroupkeyTimeout);
CsrUint8Ser(ptr, len, (u8) primitive->apConfig.apStrictGtkRekey);
CsrUint16Ser(ptr, len, (u16) primitive->apConfig.apGmkTimeout);
CsrUint16Ser(ptr, len, (u16) primitive->apConfig.apResponseTimeout);
CsrUint8Ser(ptr, len, (u8) primitive->apConfig.apRetransLimit);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.phySupportedBitmap);
CsrUint16Ser(ptr, len, (u16) primitive->apMacConfig.beaconInterval);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.dtimPeriod);
CsrUint16Ser(ptr, len, (u16) primitive->apMacConfig.maxListenInterval);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.supportedRatesCount);
CsrMemCpySer(ptr, len, (const void *) primitive->apMacConfig.supportedRates, ((u16) (20)));
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.preamble);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.shortSlotTimeEnabled);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.ctsProtectionType);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmEnabled);
{
u16 i2;
for (i2 = 0; i2 < 4; i2++)
{
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmApParams[i2].cwMin);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmApParams[i2].cwMax);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmApParams[i2].aifs);
CsrUint16Ser(ptr, len, (u16) primitive->apMacConfig.wmmApParams[i2].txopLimit);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmApParams[i2].admissionControlMandatory);
}
}
{
u16 i2;
for (i2 = 0; i2 < 4; i2++)
{
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmApBcParams[i2].cwMin);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmApBcParams[i2].cwMax);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmApBcParams[i2].aifs);
CsrUint16Ser(ptr, len, (u16) primitive->apMacConfig.wmmApBcParams[i2].txopLimit);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.wmmApBcParams[i2].admissionControlMandatory);
}
}
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.accessType);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.macAddressListCount);
{
u16 i2;
for (i2 = 0; i2 < primitive->apMacConfig.macAddressListCount; i2++)
{
CsrMemCpySer(ptr, len, (const void *) primitive->apMacConfig.macAddressList[i2].a, ((u16) (6)));
}
}
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.apHtParams.greenfieldSupported);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.apHtParams.shortGi20MHz);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.apHtParams.rxStbc);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.apHtParams.rifsModeAllowed);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.apHtParams.htProtection);
CsrUint8Ser(ptr, len, (u8) primitive->apMacConfig.apHtParams.dualCtsProtection);
return(ptr);
}
void* CsrWifiNmeApConfigSetReqDes(u8 *buffer, size_t length)
{
CsrWifiNmeApConfigSetReq *primitive = kmalloc(sizeof(CsrWifiNmeApConfigSetReq), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apConfig.apGroupkeyTimeout, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apConfig.apStrictGtkRekey, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apConfig.apGmkTimeout, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apConfig.apResponseTimeout, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apConfig.apRetransLimit, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.phySupportedBitmap, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apMacConfig.beaconInterval, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.dtimPeriod, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apMacConfig.maxListenInterval, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.supportedRatesCount, buffer, &offset);
CsrMemCpyDes(primitive->apMacConfig.supportedRates, buffer, &offset, ((u16) (20)));
CsrUint8Des((u8 *) &primitive->apMacConfig.preamble, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.shortSlotTimeEnabled, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.ctsProtectionType, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmEnabled, buffer, &offset);
{
u16 i2;
for (i2 = 0; i2 < 4; i2++)
{
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmApParams[i2].cwMin, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmApParams[i2].cwMax, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmApParams[i2].aifs, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apMacConfig.wmmApParams[i2].txopLimit, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmApParams[i2].admissionControlMandatory, buffer, &offset);
}
}
{
u16 i2;
for (i2 = 0; i2 < 4; i2++)
{
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmApBcParams[i2].cwMin, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmApBcParams[i2].cwMax, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmApBcParams[i2].aifs, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apMacConfig.wmmApBcParams[i2].txopLimit, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.wmmApBcParams[i2].admissionControlMandatory, buffer, &offset);
}
}
CsrUint8Des((u8 *) &primitive->apMacConfig.accessType, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.macAddressListCount, buffer, &offset);
primitive->apMacConfig.macAddressList = NULL;
if (primitive->apMacConfig.macAddressListCount)
{
primitive->apMacConfig.macAddressList = kmalloc(sizeof(CsrWifiMacAddress) * primitive->apMacConfig.macAddressListCount, GFP_KERNEL);
}
{
u16 i2;
for (i2 = 0; i2 < primitive->apMacConfig.macAddressListCount; i2++)
{
CsrMemCpyDes(primitive->apMacConfig.macAddressList[i2].a, buffer, &offset, ((u16) (6)));
}
}
CsrUint8Des((u8 *) &primitive->apMacConfig.apHtParams.greenfieldSupported, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.apHtParams.shortGi20MHz, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.apHtParams.rxStbc, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.apHtParams.rifsModeAllowed, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.apHtParams.htProtection, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apMacConfig.apHtParams.dualCtsProtection, buffer, &offset);
return primitive;
}
void CsrWifiNmeApConfigSetReqSerFree(void *voidPrimitivePointer)
{
CsrWifiNmeApConfigSetReq *primitive = (CsrWifiNmeApConfigSetReq *) voidPrimitivePointer;
kfree(primitive->apMacConfig.macAddressList);
kfree(primitive);
}
size_t CsrWifiNmeApWpsRegisterReqSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 2;
bufferSize += 2;
bufferSize += 8;
return bufferSize;
}
u8* CsrWifiNmeApWpsRegisterReqSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApWpsRegisterReq *primitive = (CsrWifiNmeApWpsRegisterReq *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint16Ser(ptr, len, (u16) primitive->selectedDevicePasswordId);
CsrUint16Ser(ptr, len, (u16) primitive->selectedConfigMethod);
CsrMemCpySer(ptr, len, (const void *) primitive->pin, ((u16) (8)));
return(ptr);
}
void* CsrWifiNmeApWpsRegisterReqDes(u8 *buffer, size_t length)
{
CsrWifiNmeApWpsRegisterReq *primitive = kmalloc(sizeof(CsrWifiNmeApWpsRegisterReq), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint16Des((u16 *) &primitive->selectedDevicePasswordId, buffer, &offset);
CsrUint16Des((u16 *) &primitive->selectedConfigMethod, buffer, &offset);
CsrMemCpyDes(primitive->pin, buffer, &offset, ((u16) (8)));
return primitive;
}
size_t CsrWifiNmeApStartReqSizeof(void *msg)
{
CsrWifiNmeApStartReq *primitive = (CsrWifiNmeApStartReq *) msg;
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 1;
bufferSize += 32;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
switch (primitive->apCredentials.authType)
{
case CSR_WIFI_SME_AP_AUTH_TYPE_OPEN_SYSTEM:
bufferSize += 1;
break;
case CSR_WIFI_SME_AP_AUTH_TYPE_WEP:
bufferSize += 1;
switch (primitive->apCredentials.nmeAuthType.authwep.wepKeyType)
{
case CSR_WIFI_SME_CREDENTIAL_TYPE_WEP128:
bufferSize += 1;
bufferSize += 1;
bufferSize += 13;
bufferSize += 13;
bufferSize += 13;
bufferSize += 13;
break;
case CSR_WIFI_SME_CREDENTIAL_TYPE_WEP64:
bufferSize += 1;
bufferSize += 1;
bufferSize += 5;
bufferSize += 5;
bufferSize += 5;
bufferSize += 5;
break;
default:
break;
}
break;
case CSR_WIFI_SME_AP_AUTH_TYPE_PERSONAL:
bufferSize += 1;
bufferSize += 2;
bufferSize += 2;
bufferSize += 1;
switch (primitive->apCredentials.nmeAuthType.authTypePersonal.pskOrPassphrase)
{
case CSR_WIFI_NME_AP_CREDENTIAL_TYPE_PSK:
bufferSize += 2;
bufferSize += 32;
break;
case CSR_WIFI_NME_AP_CREDENTIAL_TYPE_PASSPHRASE:
bufferSize += 2;
bufferSize += (primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.passphrase.passphrase ? strlen(primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.passphrase.passphrase) : 0) + 1;
break;
default:
break;
}
break;
default:
break;
}
bufferSize += 1;
bufferSize += 1;
bufferSize += 3;
bufferSize += 1;
{
u16 i3;
for (i3 = 0; i3 < primitive->p2pGoParam.operatingChanList.channelEntryListCount; i3++)
{
bufferSize += 1;
bufferSize += 1;
bufferSize += primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannelCount;
}
}
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
return bufferSize;
}
u8* CsrWifiNmeApStartReqSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApStartReq *primitive = (CsrWifiNmeApStartReq *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint8Ser(ptr, len, (u8) primitive->apType);
CsrUint8Ser(ptr, len, (u8) primitive->cloakSsid);
CsrMemCpySer(ptr, len, (const void *) primitive->ssid.ssid, ((u16) (32)));
CsrUint8Ser(ptr, len, (u8) primitive->ssid.length);
CsrUint8Ser(ptr, len, (u8) primitive->ifIndex);
CsrUint8Ser(ptr, len, (u8) primitive->channel);
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.authType);
switch (primitive->apCredentials.authType)
{
case CSR_WIFI_SME_AP_AUTH_TYPE_OPEN_SYSTEM:
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.nmeAuthType.openSystemEmpty.empty);
break;
case CSR_WIFI_SME_AP_AUTH_TYPE_WEP:
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.nmeAuthType.authwep.wepKeyType);
switch (primitive->apCredentials.nmeAuthType.authwep.wepKeyType)
{
case CSR_WIFI_SME_CREDENTIAL_TYPE_WEP128:
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.wepAuthType);
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.selectedWepKey);
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.key1, ((u16) (13)));
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.key2, ((u16) (13)));
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.key3, ((u16) (13)));
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.key4, ((u16) (13)));
break;
case CSR_WIFI_SME_CREDENTIAL_TYPE_WEP64:
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.wepAuthType);
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.selectedWepKey);
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.key1, ((u16) (5)));
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.key2, ((u16) (5)));
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.key3, ((u16) (5)));
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.key4, ((u16) (5)));
break;
default:
break;
}
break;
case CSR_WIFI_SME_AP_AUTH_TYPE_PERSONAL:
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.nmeAuthType.authTypePersonal.authSupport);
CsrUint16Ser(ptr, len, (u16) primitive->apCredentials.nmeAuthType.authTypePersonal.rsnCapabilities);
CsrUint16Ser(ptr, len, (u16) primitive->apCredentials.nmeAuthType.authTypePersonal.wapiCapabilities);
CsrUint8Ser(ptr, len, (u8) primitive->apCredentials.nmeAuthType.authTypePersonal.pskOrPassphrase);
switch (primitive->apCredentials.nmeAuthType.authTypePersonal.pskOrPassphrase)
{
case CSR_WIFI_NME_AP_CREDENTIAL_TYPE_PSK:
CsrUint16Ser(ptr, len, (u16) primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.psk.encryptionMode);
CsrMemCpySer(ptr, len, (const void *) primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.psk.psk, ((u16) (32)));
break;
case CSR_WIFI_NME_AP_CREDENTIAL_TYPE_PASSPHRASE:
CsrUint16Ser(ptr, len, (u16) primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.passphrase.encryptionMode);
CsrCharStringSer(ptr, len, primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.passphrase.passphrase);
break;
default:
break;
}
break;
default:
break;
}
CsrUint8Ser(ptr, len, (u8) primitive->maxConnections);
CsrUint8Ser(ptr, len, (u8) primitive->p2pGoParam.groupCapability);
CsrMemCpySer(ptr, len, (const void *) primitive->p2pGoParam.operatingChanList.country, ((u16) (3)));
CsrUint8Ser(ptr, len, (u8) primitive->p2pGoParam.operatingChanList.channelEntryListCount);
{
u16 i3;
for (i3 = 0; i3 < primitive->p2pGoParam.operatingChanList.channelEntryListCount; i3++)
{
CsrUint8Ser(ptr, len, (u8) primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingClass);
CsrUint8Ser(ptr, len, (u8) primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannelCount);
if (primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannelCount)
{
CsrMemCpySer(ptr, len, (const void *) primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannel, ((u16) (primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannelCount)));
}
}
}
CsrUint8Ser(ptr, len, (u8) primitive->p2pGoParam.opPsEnabled);
CsrUint8Ser(ptr, len, (u8) primitive->p2pGoParam.ctWindow);
CsrUint8Ser(ptr, len, (u8) primitive->p2pGoParam.noaConfigMethod);
CsrUint8Ser(ptr, len, (u8) primitive->p2pGoParam.allowNoaWithNonP2pDevices);
CsrUint8Ser(ptr, len, (u8) primitive->wpsEnabled);
return(ptr);
}
void* CsrWifiNmeApStartReqDes(u8 *buffer, size_t length)
{
CsrWifiNmeApStartReq *primitive = kmalloc(sizeof(CsrWifiNmeApStartReq), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apType, buffer, &offset);
CsrUint8Des((u8 *) &primitive->cloakSsid, buffer, &offset);
CsrMemCpyDes(primitive->ssid.ssid, buffer, &offset, ((u16) (32)));
CsrUint8Des((u8 *) &primitive->ssid.length, buffer, &offset);
CsrUint8Des((u8 *) &primitive->ifIndex, buffer, &offset);
CsrUint8Des((u8 *) &primitive->channel, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apCredentials.authType, buffer, &offset);
switch (primitive->apCredentials.authType)
{
case CSR_WIFI_SME_AP_AUTH_TYPE_OPEN_SYSTEM:
CsrUint8Des((u8 *) &primitive->apCredentials.nmeAuthType.openSystemEmpty.empty, buffer, &offset);
break;
case CSR_WIFI_SME_AP_AUTH_TYPE_WEP:
CsrUint8Des((u8 *) &primitive->apCredentials.nmeAuthType.authwep.wepKeyType, buffer, &offset);
switch (primitive->apCredentials.nmeAuthType.authwep.wepKeyType)
{
case CSR_WIFI_SME_CREDENTIAL_TYPE_WEP128:
CsrUint8Des((u8 *) &primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.wepAuthType, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.selectedWepKey, buffer, &offset);
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.key1, buffer, &offset, ((u16) (13)));
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.key2, buffer, &offset, ((u16) (13)));
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.key3, buffer, &offset, ((u16) (13)));
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep128Key.key4, buffer, &offset, ((u16) (13)));
break;
case CSR_WIFI_SME_CREDENTIAL_TYPE_WEP64:
CsrUint8Des((u8 *) &primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.wepAuthType, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.selectedWepKey, buffer, &offset);
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.key1, buffer, &offset, ((u16) (5)));
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.key2, buffer, &offset, ((u16) (5)));
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.key3, buffer, &offset, ((u16) (5)));
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authwep.wepCredentials.wep64Key.key4, buffer, &offset, ((u16) (5)));
break;
default:
break;
}
break;
case CSR_WIFI_SME_AP_AUTH_TYPE_PERSONAL:
CsrUint8Des((u8 *) &primitive->apCredentials.nmeAuthType.authTypePersonal.authSupport, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apCredentials.nmeAuthType.authTypePersonal.rsnCapabilities, buffer, &offset);
CsrUint16Des((u16 *) &primitive->apCredentials.nmeAuthType.authTypePersonal.wapiCapabilities, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apCredentials.nmeAuthType.authTypePersonal.pskOrPassphrase, buffer, &offset);
switch (primitive->apCredentials.nmeAuthType.authTypePersonal.pskOrPassphrase)
{
case CSR_WIFI_NME_AP_CREDENTIAL_TYPE_PSK:
CsrUint16Des((u16 *) &primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.psk.encryptionMode, buffer, &offset);
CsrMemCpyDes(primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.psk.psk, buffer, &offset, ((u16) (32)));
break;
case CSR_WIFI_NME_AP_CREDENTIAL_TYPE_PASSPHRASE:
CsrUint16Des((u16 *) &primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.passphrase.encryptionMode, buffer, &offset);
CsrCharStringDes(&primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.passphrase.passphrase, buffer, &offset);
break;
default:
break;
}
break;
default:
break;
}
CsrUint8Des((u8 *) &primitive->maxConnections, buffer, &offset);
CsrUint8Des((u8 *) &primitive->p2pGoParam.groupCapability, buffer, &offset);
CsrMemCpyDes(primitive->p2pGoParam.operatingChanList.country, buffer, &offset, ((u16) (3)));
CsrUint8Des((u8 *) &primitive->p2pGoParam.operatingChanList.channelEntryListCount, buffer, &offset);
primitive->p2pGoParam.operatingChanList.channelEntryList = NULL;
if (primitive->p2pGoParam.operatingChanList.channelEntryListCount)
{
primitive->p2pGoParam.operatingChanList.channelEntryList = kmalloc(sizeof(CsrWifiSmeApP2pOperatingChanEntry) * primitive->p2pGoParam.operatingChanList.channelEntryListCount, GFP_KERNEL);
}
{
u16 i3;
for (i3 = 0; i3 < primitive->p2pGoParam.operatingChanList.channelEntryListCount; i3++)
{
CsrUint8Des((u8 *) &primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingClass, buffer, &offset);
CsrUint8Des((u8 *) &primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannelCount, buffer, &offset);
if (primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannelCount)
{
primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannel = kmalloc(primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannelCount, GFP_KERNEL);
CsrMemCpyDes(primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannel, buffer, &offset, ((u16) (primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannelCount)));
}
else
{
primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannel = NULL;
}
}
}
CsrUint8Des((u8 *) &primitive->p2pGoParam.opPsEnabled, buffer, &offset);
CsrUint8Des((u8 *) &primitive->p2pGoParam.ctWindow, buffer, &offset);
CsrUint8Des((u8 *) &primitive->p2pGoParam.noaConfigMethod, buffer, &offset);
CsrUint8Des((u8 *) &primitive->p2pGoParam.allowNoaWithNonP2pDevices, buffer, &offset);
CsrUint8Des((u8 *) &primitive->wpsEnabled, buffer, &offset);
return primitive;
}
void CsrWifiNmeApStartReqSerFree(void *voidPrimitivePointer)
{
CsrWifiNmeApStartReq *primitive = (CsrWifiNmeApStartReq *) voidPrimitivePointer;
switch (primitive->apCredentials.authType)
{
case CSR_WIFI_SME_AP_AUTH_TYPE_PERSONAL:
switch (primitive->apCredentials.nmeAuthType.authTypePersonal.pskOrPassphrase)
{
case CSR_WIFI_NME_AP_CREDENTIAL_TYPE_PASSPHRASE:
kfree(primitive->apCredentials.nmeAuthType.authTypePersonal.authPers_credentials.passphrase.passphrase);
break;
default:
break;
}
break;
default:
break;
}
{
u16 i3;
for (i3 = 0; i3 < primitive->p2pGoParam.operatingChanList.channelEntryListCount; i3++)
{
kfree(primitive->p2pGoParam.operatingChanList.channelEntryList[i3].operatingChannel);
}
}
kfree(primitive->p2pGoParam.operatingChanList.channelEntryList);
kfree(primitive);
}
size_t CsrWifiNmeApWmmParamUpdateReqSizeof(void *msg)
{
size_t bufferSize = 2;
{
u16 i1;
for (i1 = 0; i1 < 4; i1++)
{
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 2;
bufferSize += 1;
}
}
{
u16 i1;
for (i1 = 0; i1 < 4; i1++)
{
bufferSize += 1;
bufferSize += 1;
bufferSize += 1;
bufferSize += 2;
bufferSize += 1;
}
}
return bufferSize;
}
u8* CsrWifiNmeApWmmParamUpdateReqSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApWmmParamUpdateReq *primitive = (CsrWifiNmeApWmmParamUpdateReq *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
{
u16 i1;
for (i1 = 0; i1 < 4; i1++)
{
CsrUint8Ser(ptr, len, (u8) primitive->wmmApParams[i1].cwMin);
CsrUint8Ser(ptr, len, (u8) primitive->wmmApParams[i1].cwMax);
CsrUint8Ser(ptr, len, (u8) primitive->wmmApParams[i1].aifs);
CsrUint16Ser(ptr, len, (u16) primitive->wmmApParams[i1].txopLimit);
CsrUint8Ser(ptr, len, (u8) primitive->wmmApParams[i1].admissionControlMandatory);
}
}
{
u16 i1;
for (i1 = 0; i1 < 4; i1++)
{
CsrUint8Ser(ptr, len, (u8) primitive->wmmApBcParams[i1].cwMin);
CsrUint8Ser(ptr, len, (u8) primitive->wmmApBcParams[i1].cwMax);
CsrUint8Ser(ptr, len, (u8) primitive->wmmApBcParams[i1].aifs);
CsrUint16Ser(ptr, len, (u16) primitive->wmmApBcParams[i1].txopLimit);
CsrUint8Ser(ptr, len, (u8) primitive->wmmApBcParams[i1].admissionControlMandatory);
}
}
return(ptr);
}
void* CsrWifiNmeApWmmParamUpdateReqDes(u8 *buffer, size_t length)
{
CsrWifiNmeApWmmParamUpdateReq *primitive = kmalloc(sizeof(CsrWifiNmeApWmmParamUpdateReq), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
{
u16 i1;
for (i1 = 0; i1 < 4; i1++)
{
CsrUint8Des((u8 *) &primitive->wmmApParams[i1].cwMin, buffer, &offset);
CsrUint8Des((u8 *) &primitive->wmmApParams[i1].cwMax, buffer, &offset);
CsrUint8Des((u8 *) &primitive->wmmApParams[i1].aifs, buffer, &offset);
CsrUint16Des((u16 *) &primitive->wmmApParams[i1].txopLimit, buffer, &offset);
CsrUint8Des((u8 *) &primitive->wmmApParams[i1].admissionControlMandatory, buffer, &offset);
}
}
{
u16 i1;
for (i1 = 0; i1 < 4; i1++)
{
CsrUint8Des((u8 *) &primitive->wmmApBcParams[i1].cwMin, buffer, &offset);
CsrUint8Des((u8 *) &primitive->wmmApBcParams[i1].cwMax, buffer, &offset);
CsrUint8Des((u8 *) &primitive->wmmApBcParams[i1].aifs, buffer, &offset);
CsrUint16Des((u16 *) &primitive->wmmApBcParams[i1].txopLimit, buffer, &offset);
CsrUint8Des((u8 *) &primitive->wmmApBcParams[i1].admissionControlMandatory, buffer, &offset);
}
}
return primitive;
}
size_t CsrWifiNmeApStaRemoveReqSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 6;
bufferSize += 1;
return bufferSize;
}
u8* CsrWifiNmeApStaRemoveReqSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApStaRemoveReq *primitive = (CsrWifiNmeApStaRemoveReq *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrMemCpySer(ptr, len, (const void *) primitive->staMacAddress.a, ((u16) (6)));
CsrUint8Ser(ptr, len, (u8) primitive->keepBlocking);
return(ptr);
}
void* CsrWifiNmeApStaRemoveReqDes(u8 *buffer, size_t length)
{
CsrWifiNmeApStaRemoveReq *primitive = kmalloc(sizeof(CsrWifiNmeApStaRemoveReq), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrMemCpyDes(primitive->staMacAddress.a, buffer, &offset, ((u16) (6)));
CsrUint8Des((u8 *) &primitive->keepBlocking, buffer, &offset);
return primitive;
}
size_t CsrWifiNmeApWpsRegisterCfmSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 2;
return bufferSize;
}
u8* CsrWifiNmeApWpsRegisterCfmSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApWpsRegisterCfm *primitive = (CsrWifiNmeApWpsRegisterCfm *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint16Ser(ptr, len, (u16) primitive->status);
return(ptr);
}
void* CsrWifiNmeApWpsRegisterCfmDes(u8 *buffer, size_t length)
{
CsrWifiNmeApWpsRegisterCfm *primitive = kmalloc(sizeof(CsrWifiNmeApWpsRegisterCfm), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint16Des((u16 *) &primitive->status, buffer, &offset);
return primitive;
}
size_t CsrWifiNmeApStartCfmSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 2;
bufferSize += 32;
bufferSize += 1;
return bufferSize;
}
u8* CsrWifiNmeApStartCfmSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApStartCfm *primitive = (CsrWifiNmeApStartCfm *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint16Ser(ptr, len, (u16) primitive->status);
CsrMemCpySer(ptr, len, (const void *) primitive->ssid.ssid, ((u16) (32)));
CsrUint8Ser(ptr, len, (u8) primitive->ssid.length);
return(ptr);
}
void* CsrWifiNmeApStartCfmDes(u8 *buffer, size_t length)
{
CsrWifiNmeApStartCfm *primitive = kmalloc(sizeof(CsrWifiNmeApStartCfm), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint16Des((u16 *) &primitive->status, buffer, &offset);
CsrMemCpyDes(primitive->ssid.ssid, buffer, &offset, ((u16) (32)));
CsrUint8Des((u8 *) &primitive->ssid.length, buffer, &offset);
return primitive;
}
size_t CsrWifiNmeApStopCfmSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 2;
return bufferSize;
}
u8* CsrWifiNmeApStopCfmSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApStopCfm *primitive = (CsrWifiNmeApStopCfm *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint16Ser(ptr, len, (u16) primitive->status);
return(ptr);
}
void* CsrWifiNmeApStopCfmDes(u8 *buffer, size_t length)
{
CsrWifiNmeApStopCfm *primitive = kmalloc(sizeof(CsrWifiNmeApStopCfm), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint16Des((u16 *) &primitive->status, buffer, &offset);
return primitive;
}
size_t CsrWifiNmeApStopIndSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 2;
return bufferSize;
}
u8* CsrWifiNmeApStopIndSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApStopInd *primitive = (CsrWifiNmeApStopInd *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint8Ser(ptr, len, (u8) primitive->apType);
CsrUint16Ser(ptr, len, (u16) primitive->status);
return(ptr);
}
void* CsrWifiNmeApStopIndDes(u8 *buffer, size_t length)
{
CsrWifiNmeApStopInd *primitive = kmalloc(sizeof(CsrWifiNmeApStopInd), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->apType, buffer, &offset);
CsrUint16Des((u16 *) &primitive->status, buffer, &offset);
return primitive;
}
size_t CsrWifiNmeApStationIndSizeof(void *msg)
{
size_t bufferSize = 2;
bufferSize += 2;
bufferSize += 1;
bufferSize += 6;
bufferSize += 6;
return bufferSize;
}
u8* CsrWifiNmeApStationIndSer(u8 *ptr, size_t *len, void *msg)
{
CsrWifiNmeApStationInd *primitive = (CsrWifiNmeApStationInd *)msg;
*len = 0;
CsrUint16Ser(ptr, len, primitive->common.type);
CsrUint16Ser(ptr, len, (u16) primitive->interfaceTag);
CsrUint8Ser(ptr, len, (u8) primitive->mediaStatus);
CsrMemCpySer(ptr, len, (const void *) primitive->peerMacAddress.a, ((u16) (6)));
CsrMemCpySer(ptr, len, (const void *) primitive->peerDeviceAddress.a, ((u16) (6)));
return(ptr);
}
void* CsrWifiNmeApStationIndDes(u8 *buffer, size_t length)
{
CsrWifiNmeApStationInd *primitive = kmalloc(sizeof(CsrWifiNmeApStationInd), GFP_KERNEL);
size_t offset;
offset = 0;
CsrUint16Des(&primitive->common.type, buffer, &offset);
CsrUint16Des((u16 *) &primitive->interfaceTag, buffer, &offset);
CsrUint8Des((u8 *) &primitive->mediaStatus, buffer, &offset);
CsrMemCpyDes(primitive->peerMacAddress.a, buffer, &offset, ((u16) (6)));
CsrMemCpyDes(primitive->peerDeviceAddress.a, buffer, &offset, ((u16) (6)));
return primitive;
}
