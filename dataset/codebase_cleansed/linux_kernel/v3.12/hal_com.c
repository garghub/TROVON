void dump_chip_info(struct HAL_VERSION chip_vers)
{
uint cnt = 0;
char buf[128];
if (IS_81XXC(chip_vers)) {
cnt += sprintf((buf+cnt), "Chip Version Info: %s_",
IS_92C_SERIAL(chip_vers) ?
"CHIP_8192C" : "CHIP_8188C");
} else if (IS_92D(chip_vers)) {
cnt += sprintf((buf+cnt), "Chip Version Info: CHIP_8192D_");
} else if (IS_8723_SERIES(chip_vers)) {
cnt += sprintf((buf+cnt), "Chip Version Info: CHIP_8723A_");
} else if (IS_8188E(chip_vers)) {
cnt += sprintf((buf+cnt), "Chip Version Info: CHIP_8188E_");
}
cnt += sprintf((buf+cnt), "%s_", IS_NORMAL_CHIP(chip_vers) ?
"Normal_Chip" : "Test_Chip");
cnt += sprintf((buf+cnt), "%s_", IS_CHIP_VENDOR_TSMC(chip_vers) ?
"TSMC" : "UMC");
if (IS_A_CUT(chip_vers))
cnt += sprintf((buf+cnt), "A_CUT_");
else if (IS_B_CUT(chip_vers))
cnt += sprintf((buf+cnt), "B_CUT_");
else if (IS_C_CUT(chip_vers))
cnt += sprintf((buf+cnt), "C_CUT_");
else if (IS_D_CUT(chip_vers))
cnt += sprintf((buf+cnt), "D_CUT_");
else if (IS_E_CUT(chip_vers))
cnt += sprintf((buf+cnt), "E_CUT_");
else
cnt += sprintf((buf+cnt), "UNKNOWN_CUT(%d)_",
chip_vers.CUTVersion);
if (IS_1T1R(chip_vers))
cnt += sprintf((buf+cnt), "1T1R_");
else if (IS_1T2R(chip_vers))
cnt += sprintf((buf+cnt), "1T2R_");
else if (IS_2T2R(chip_vers))
cnt += sprintf((buf+cnt), "2T2R_");
else
cnt += sprintf((buf+cnt), "UNKNOWN_RFTYPE(%d)_",
chip_vers.RFType);
cnt += sprintf((buf+cnt), "RomVer(%d)\n", chip_vers.ROMVer);
pr_info("%s", buf);
}
u8
hal_com_get_channel_plan(struct adapter *padapter, u8 hw_channel_plan,
u8 sw_channel_plan, u8 def_channel_plan,
bool load_fail)
{
u8 sw_cfg;
u8 chnlplan;
sw_cfg = true;
if (!load_fail) {
if (!rtw_is_channel_plan_valid(sw_channel_plan))
sw_cfg = false;
if (hw_channel_plan & CHAN_PLAN_HW)
sw_cfg = false;
}
if (sw_cfg)
chnlplan = sw_channel_plan;
else
chnlplan = hw_channel_plan & (~CHAN_PLAN_HW);
if (!rtw_is_channel_plan_valid(chnlplan))
chnlplan = def_channel_plan;
return chnlplan;
}
u8 MRateToHwRate(u8 rate)
{
u8 ret = DESC_RATE1M;
switch (rate) {
case IEEE80211_CCK_RATE_1MB:
ret = DESC_RATE1M;
break;
case IEEE80211_CCK_RATE_2MB:
ret = DESC_RATE2M;
break;
case IEEE80211_CCK_RATE_5MB:
ret = DESC_RATE5_5M;
break;
case IEEE80211_CCK_RATE_11MB:
ret = DESC_RATE11M;
break;
case IEEE80211_OFDM_RATE_6MB:
ret = DESC_RATE6M;
break;
case IEEE80211_OFDM_RATE_9MB:
ret = DESC_RATE9M;
break;
case IEEE80211_OFDM_RATE_12MB:
ret = DESC_RATE12M;
break;
case IEEE80211_OFDM_RATE_18MB:
ret = DESC_RATE18M;
break;
case IEEE80211_OFDM_RATE_24MB:
ret = DESC_RATE24M;
break;
case IEEE80211_OFDM_RATE_36MB:
ret = DESC_RATE36M;
break;
case IEEE80211_OFDM_RATE_48MB:
ret = DESC_RATE48M;
break;
case IEEE80211_OFDM_RATE_54MB:
ret = DESC_RATE54M;
break;
default:
break;
}
return ret;
}
void HalSetBrateCfg(struct adapter *adapt, u8 *brates, u16 *rate_cfg)
{
u8 i, is_brate, brate;
for (i = 0; i < NDIS_802_11_LENGTH_RATES_EX; i++) {
is_brate = brates[i] & IEEE80211_BASIC_RATE_MASK;
brate = brates[i] & 0x7f;
if (is_brate) {
switch (brate) {
case IEEE80211_CCK_RATE_1MB:
*rate_cfg |= RATE_1M;
break;
case IEEE80211_CCK_RATE_2MB:
*rate_cfg |= RATE_2M;
break;
case IEEE80211_CCK_RATE_5MB:
*rate_cfg |= RATE_5_5M;
break;
case IEEE80211_CCK_RATE_11MB:
*rate_cfg |= RATE_11M;
break;
case IEEE80211_OFDM_RATE_6MB:
*rate_cfg |= RATE_6M;
break;
case IEEE80211_OFDM_RATE_9MB:
*rate_cfg |= RATE_9M;
break;
case IEEE80211_OFDM_RATE_12MB:
*rate_cfg |= RATE_12M;
break;
case IEEE80211_OFDM_RATE_18MB:
*rate_cfg |= RATE_18M;
break;
case IEEE80211_OFDM_RATE_24MB:
*rate_cfg |= RATE_24M;
break;
case IEEE80211_OFDM_RATE_36MB:
*rate_cfg |= RATE_36M;
break;
case IEEE80211_OFDM_RATE_48MB:
*rate_cfg |= RATE_48M;
break;
case IEEE80211_OFDM_RATE_54MB:
*rate_cfg |= RATE_54M;
break;
}
}
}
}
static void one_out_pipe(struct adapter *adapter)
{
struct dvobj_priv *pdvobjpriv = adapter_to_dvobj(adapter);
pdvobjpriv->Queue2Pipe[0] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[1] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[2] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[3] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[4] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[5] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[6] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[7] = pdvobjpriv->RtOutPipe[0];
}
static void two_out_pipe(struct adapter *adapter, bool wifi_cfg)
{
struct dvobj_priv *pdvobjpriv = adapter_to_dvobj(adapter);
if (wifi_cfg) {
pdvobjpriv->Queue2Pipe[0] = pdvobjpriv->RtOutPipe[1];
pdvobjpriv->Queue2Pipe[1] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[2] = pdvobjpriv->RtOutPipe[1];
pdvobjpriv->Queue2Pipe[3] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[4] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[5] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[6] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[7] = pdvobjpriv->RtOutPipe[0];
} else {
pdvobjpriv->Queue2Pipe[0] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[1] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[2] = pdvobjpriv->RtOutPipe[1];
pdvobjpriv->Queue2Pipe[3] = pdvobjpriv->RtOutPipe[1];
pdvobjpriv->Queue2Pipe[4] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[5] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[6] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[7] = pdvobjpriv->RtOutPipe[0];
}
}
static void three_out_pipe(struct adapter *adapter, bool wifi_cfg)
{
struct dvobj_priv *pdvobjpriv = adapter_to_dvobj(adapter);
if (wifi_cfg) {
pdvobjpriv->Queue2Pipe[0] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[1] = pdvobjpriv->RtOutPipe[1];
pdvobjpriv->Queue2Pipe[2] = pdvobjpriv->RtOutPipe[2];
pdvobjpriv->Queue2Pipe[3] = pdvobjpriv->RtOutPipe[1];
pdvobjpriv->Queue2Pipe[4] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[5] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[6] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[7] = pdvobjpriv->RtOutPipe[0];
} else {
pdvobjpriv->Queue2Pipe[0] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[1] = pdvobjpriv->RtOutPipe[1];
pdvobjpriv->Queue2Pipe[2] = pdvobjpriv->RtOutPipe[2];
pdvobjpriv->Queue2Pipe[3] = pdvobjpriv->RtOutPipe[2];
pdvobjpriv->Queue2Pipe[4] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[5] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[6] = pdvobjpriv->RtOutPipe[0];
pdvobjpriv->Queue2Pipe[7] = pdvobjpriv->RtOutPipe[0];
}
}
bool Hal_MappingOutPipe(struct adapter *adapter, u8 numoutpipe)
{
struct registry_priv *pregistrypriv = &adapter->registrypriv;
bool wifi_cfg = (pregistrypriv->wifi_spec) ? true : false;
bool result = true;
switch (numoutpipe) {
case 2:
two_out_pipe(adapter, wifi_cfg);
break;
case 3:
three_out_pipe(adapter, wifi_cfg);
break;
case 1:
one_out_pipe(adapter);
break;
default:
result = false;
break;
}
return result;
}
void hal_init_macaddr(struct adapter *adapter)
{
rtw_hal_set_hwreg(adapter, HW_VAR_MAC_ADDR,
adapter->eeprompriv.mac_addr);
}
void c2h_evt_clear(struct adapter *adapter)
{
rtw_write8(adapter, REG_C2HEVT_CLEAR, C2H_EVT_HOST_CLOSE);
}
s32 c2h_evt_read(struct adapter *adapter, u8 *buf)
{
s32 ret = _FAIL;
struct c2h_evt_hdr *c2h_evt;
int i;
u8 trigger;
if (buf == NULL)
goto exit;
trigger = rtw_read8(adapter, REG_C2HEVT_CLEAR);
if (trigger == C2H_EVT_HOST_CLOSE)
goto exit;
else if (trigger != C2H_EVT_FW_CLOSE)
goto clear_evt;
c2h_evt = (struct c2h_evt_hdr *)buf;
_rtw_memset(c2h_evt, 0, 16);
*buf = rtw_read8(adapter, REG_C2HEVT_MSG_NORMAL);
*(buf+1) = rtw_read8(adapter, REG_C2HEVT_MSG_NORMAL + 1);
RT_PRINT_DATA(_module_hal_init_c_, _drv_info_, "c2h_evt_read(): ",
&c2h_evt , sizeof(c2h_evt));
for (i = 0; i < c2h_evt->plen; i++)
c2h_evt->payload[i] = rtw_read8(adapter, REG_C2HEVT_MSG_NORMAL +
sizeof(*c2h_evt) + i);
RT_PRINT_DATA(_module_hal_init_c_, _drv_info_,
"c2h_evt_read(): Command Content:\n",
c2h_evt->payload, c2h_evt->plen);
ret = _SUCCESS;
clear_evt:
c2h_evt_clear(adapter);
exit:
return ret;
}
