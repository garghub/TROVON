int IFRFbWriteEmbedded(struct vnt_private *pDevice, u32 dwData)
{
u8 pbyData[4];
pbyData[0] = (u8)dwData;
pbyData[1] = (u8)(dwData >> 8);
pbyData[2] = (u8)(dwData >> 16);
pbyData[3] = (u8)(dwData >> 24);
CONTROLnsRequestOut(pDevice,
MESSAGE_TYPE_WRITE_IFRF, 0, 0, 4, pbyData);
return true;
}
int RFbSetPower(struct vnt_private *priv, u32 rate, u32 channel)
{
int ret = true;
u8 power = priv->byCCKPwr;
if (channel == 0)
return -EINVAL;
switch (rate) {
case RATE_1M:
case RATE_2M:
case RATE_5M:
case RATE_11M:
power = priv->abyCCKPwrTbl[channel-1];
break;
case RATE_6M:
case RATE_9M:
case RATE_18M:
case RATE_24M:
case RATE_36M:
case RATE_48M:
case RATE_54M:
if (channel > CB_MAX_CHANNEL_24G)
power = priv->abyOFDMAPwrTbl[channel-15];
else
power = priv->abyOFDMPwrTbl[channel-1];
break;
}
ret = RFbRawSetPower(priv, power, rate);
return ret;
}
int RFbRawSetPower(struct vnt_private *priv, u8 power, u32 rate)
{
u32 power_setting = 0;
int ret = true;
if (priv->byCurPwr == power)
return true;
priv->byCurPwr = power;
switch (priv->byRFType) {
case RF_AL2230:
if (priv->byCurPwr >= AL2230_PWR_IDX_LEN)
return false;
ret &= IFRFbWriteEmbedded(priv,
al2230_power_table[priv->byCurPwr]);
if (rate <= RATE_11M)
ret &= IFRFbWriteEmbedded(priv, 0x0001b400 +
(BY_AL2230_REG_LEN << 3) + IFREGCTL_REGW);
else
ret &= IFRFbWriteEmbedded(priv, 0x0005a400 +
(BY_AL2230_REG_LEN << 3) + IFREGCTL_REGW);
break;
case RF_AL2230S:
if (priv->byCurPwr >= AL2230_PWR_IDX_LEN)
return false;
ret &= IFRFbWriteEmbedded(priv,
al2230_power_table[priv->byCurPwr]);
if (rate <= RATE_11M) {
ret &= IFRFbWriteEmbedded(priv, 0x040c1400 +
(BY_AL2230_REG_LEN << 3) + IFREGCTL_REGW);
ret &= IFRFbWriteEmbedded(priv, 0x00299b00 +
(BY_AL2230_REG_LEN << 3) + IFREGCTL_REGW);
} else {
ret &= IFRFbWriteEmbedded(priv, 0x0005a400 +
(BY_AL2230_REG_LEN << 3) + IFREGCTL_REGW);
ret &= IFRFbWriteEmbedded(priv, 0x00099b00 +
(BY_AL2230_REG_LEN << 3) + IFREGCTL_REGW);
}
break;
case RF_AIROHA7230:
if (rate <= RATE_11M)
ret &= IFRFbWriteEmbedded(priv, 0x111bb900 +
(BY_AL7230_REG_LEN << 3)+IFREGCTL_REGW);
else
ret &= IFRFbWriteEmbedded(priv, 0x221bb900 +
(BY_AL7230_REG_LEN << 3)+IFREGCTL_REGW);
if (priv->byCurPwr > AL7230_PWR_IDX_LEN)
return false;
power_setting = 0x080c0b00 | ((priv->byCurPwr) << 12) |
(BY_AL7230_REG_LEN << 3) | IFREGCTL_REGW;
ret &= IFRFbWriteEmbedded(priv, power_setting);
break;
case RF_VT3226:
if (priv->byCurPwr >= VT3226_PWR_IDX_LEN)
return false;
power_setting = ((0x3f - priv->byCurPwr) << 20) | (0x17 << 8) |
(BY_VT3226_REG_LEN << 3) | IFREGCTL_REGW;
ret &= IFRFbWriteEmbedded(priv, power_setting);
break;
case RF_VT3226D0:
if (priv->byCurPwr >= VT3226_PWR_IDX_LEN)
return false;
if (rate <= RATE_11M) {
power_setting = ((0x3f-priv->byCurPwr) << 20) |
(0xe07 << 8) | (BY_VT3226_REG_LEN << 3) |
IFREGCTL_REGW;
ret &= IFRFbWriteEmbedded(priv, power_setting);
ret &= IFRFbWriteEmbedded(priv, 0x03c6a200 +
(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
if (priv->vnt_mgmt.eScanState != WMAC_NO_SCANNING) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"RFbRawSetPower> 11B mode uCurrChannel[%d]\n",
priv->vnt_mgmt.uScanChannel);
ret &= IFRFbWriteEmbedded(priv,
vt3226d0_lo_current_table[priv->
vnt_mgmt.uScanChannel - 1]);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"RFbRawSetPower> 11B mode uCurrChannel[%d]\n",
priv->vnt_mgmt.uCurrChannel);
ret &= IFRFbWriteEmbedded(priv,
vt3226d0_lo_current_table[priv->
vnt_mgmt.uCurrChannel - 1]);
}
ret &= IFRFbWriteEmbedded(priv, 0x015C0800 +
(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO
"@@@@ RFbRawSetPower> 11G mode\n");
power_setting = ((0x3f-priv->byCurPwr) << 20) |
(0x7 << 8) | (BY_VT3226_REG_LEN << 3) |
IFREGCTL_REGW;
ret &= IFRFbWriteEmbedded(priv, power_setting);
ret &= IFRFbWriteEmbedded(priv, 0x00C6A200 +
(BY_VT3226_REG_LEN << 3) + IFREGCTL_REGW);
ret &= IFRFbWriteEmbedded(priv, 0x016BC600 +
(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
ret &= IFRFbWriteEmbedded(priv, 0x00900800 +
(BY_VT3226_REG_LEN<<3)+IFREGCTL_REGW);
}
break;
case RF_VT3342A0:
if (priv->byCurPwr >= VT3342_PWR_IDX_LEN)
return false;
power_setting = ((0x3F-priv->byCurPwr) << 20) |
(0x27 << 8) | (BY_VT3342_REG_LEN << 3) |
IFREGCTL_REGW;
ret &= IFRFbWriteEmbedded(priv, power_setting);
break;
default:
break;
}
return ret;
}
void RFvRSSITodBm(struct vnt_private *priv, u8 rssi, long *dbm)
{
u8 idx = (((rssi & 0xc0) >> 6) & 0x03);
long b = (rssi & 0x3f);
long a = 0;
u8 airoharf[4] = {0, 18, 0, 40};
switch (priv->byRFType) {
case RF_AL2230:
case RF_AL2230S:
case RF_AIROHA7230:
case RF_VT3226:
case RF_VT3226D0:
case RF_VT3342A0:
a = airoharf[idx];
break;
default:
break;
}
*dbm = -1 * (a + b * 2);
}
void RFbRFTableDownload(struct vnt_private *priv)
{
u16 length1 = 0, length2 = 0, length3 = 0;
u8 *addr1 = NULL, *addr2 = NULL, *addr3 = NULL;
u16 length, value;
u8 array[256];
switch (priv->byRFType) {
case RF_AL2230:
case RF_AL2230S:
length1 = CB_AL2230_INIT_SEQ * 3;
length2 = CB_MAX_CHANNEL_24G * 3;
length3 = CB_MAX_CHANNEL_24G * 3;
addr1 = &al2230_init_table[0][0];
addr2 = &al2230_channel_table0[0][0];
addr3 = &al2230_channel_table1[0][0];
break;
case RF_AIROHA7230:
length1 = CB_AL7230_INIT_SEQ * 3;
length2 = CB_MAX_CHANNEL * 3;
length3 = CB_MAX_CHANNEL * 3;
addr1 = &al7230_init_table[0][0];
addr2 = &al7230_channel_table0[0][0];
addr3 = &al7230_channel_table1[0][0];
break;
case RF_VT3226:
length1 = CB_VT3226_INIT_SEQ * 3;
length2 = CB_MAX_CHANNEL_24G * 3;
length3 = CB_MAX_CHANNEL_24G * 3;
addr1 = &at3226_init_table[0][0];
addr2 = &vt3226_channel_table0[0][0];
addr3 = &vt3226_channel_table1[0][0];
break;
case RF_VT3226D0:
length1 = CB_VT3226_INIT_SEQ * 3;
length2 = CB_MAX_CHANNEL_24G * 3;
length3 = CB_MAX_CHANNEL_24G * 3;
addr1 = &at3226d0_init_table[0][0];
addr2 = &vt3226_channel_table0[0][0];
addr3 = &vt3226_channel_table1[0][0];
break;
case RF_VT3342A0:
length1 = CB_VT3342_INIT_SEQ * 3;
length2 = CB_MAX_CHANNEL * 3;
length3 = CB_MAX_CHANNEL * 3;
addr1 = &vt3342a0_init_table[0][0];
addr2 = &vt3342_channel_table0[0][0];
addr3 = &vt3342_channel_table1[0][0];
break;
}
memcpy(array, addr1, length1);
CONTROLnsRequestOut(priv, MESSAGE_TYPE_WRITE, 0,
MESSAGE_REQUEST_RF_INIT, length1, array);
value = 0;
while (length2 > 0) {
if (length2 >= 64)
length = 64;
else
length = length2;
memcpy(array, addr2, length);
CONTROLnsRequestOut(priv, MESSAGE_TYPE_WRITE,
value, MESSAGE_REQUEST_RF_CH0, length, array);
length2 -= length;
value += length;
addr2 += length;
}
value = 0;
while (length3 > 0) {
if (length3 >= 64)
length = 64;
else
length = length3;
memcpy(array, addr3, length);
CONTROLnsRequestOut(priv, MESSAGE_TYPE_WRITE,
value, MESSAGE_REQUEST_RF_CH1, length, array);
length3 -= length;
value += length;
addr3 += length;
}
if (priv->byRFType == RF_AIROHA7230) {
length1 = CB_AL7230_INIT_SEQ * 3;
length2 = CB_MAX_CHANNEL * 3;
addr1 = &(al7230_init_table_amode[0][0]);
addr2 = &(al7230_channel_table2[0][0]);
memcpy(array, addr1, length1);
CONTROLnsRequestOut(priv, MESSAGE_TYPE_WRITE,
0, MESSAGE_REQUEST_RF_INIT2, length1, array);
value = 0;
while (length2 > 0) {
if (length2 >= 64)
length = 64;
else
length = length2;
memcpy(array, addr2, length);
CONTROLnsRequestOut(priv, MESSAGE_TYPE_WRITE,
value, MESSAGE_REQUEST_RF_CH2, length, array);
length2 -= length;
value += length;
addr2 += length;
}
}
}
