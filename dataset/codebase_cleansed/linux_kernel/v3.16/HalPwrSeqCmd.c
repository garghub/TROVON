u8 HalPwrSeqCmdParsing23a(struct rtw_adapter *padapter, u8 CutVersion,
u8 FabVersion, u8 InterfaceType,
struct wlan_pwr_cfg PwrSeqCmd[])
{
struct wlan_pwr_cfg PwrCfgCmd = { 0 };
u8 bPollingBit = false;
u32 AryIdx = 0;
u8 value = 0;
u32 offset = 0;
u32 pollingCount = 0;
u32 maxPollingCnt = 5000;
do {
PwrCfgCmd = PwrSeqCmd[AryIdx];
RT_TRACE(_module_hal_init_c_, _drv_info_,
("HalPwrSeqCmdParsing23a: offset(%#x) cut_msk(%#x) "
"fab_msk(%#x) interface_msk(%#x) base(%#x) cmd(%#x) "
"msk(%#x) value(%#x)\n",
GET_PWR_CFG_OFFSET(PwrCfgCmd),
GET_PWR_CFG_CUT_MASK(PwrCfgCmd),
GET_PWR_CFG_FAB_MASK(PwrCfgCmd),
GET_PWR_CFG_INTF_MASK(PwrCfgCmd),
GET_PWR_CFG_BASE(PwrCfgCmd),
GET_PWR_CFG_CMD(PwrCfgCmd),
GET_PWR_CFG_MASK(PwrCfgCmd),
GET_PWR_CFG_VALUE(PwrCfgCmd)));
if ((GET_PWR_CFG_FAB_MASK(PwrCfgCmd) & FabVersion) &&
(GET_PWR_CFG_CUT_MASK(PwrCfgCmd) & CutVersion) &&
(GET_PWR_CFG_INTF_MASK(PwrCfgCmd) & InterfaceType)) {
switch (GET_PWR_CFG_CMD(PwrCfgCmd)) {
case PWR_CMD_READ:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("HalPwrSeqCmdParsing23a: "
"PWR_CMD_READ\n"));
break;
case PWR_CMD_WRITE:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("HalPwrSeqCmdParsing23a: "
"PWR_CMD_WRITE\n"));
offset = GET_PWR_CFG_OFFSET(PwrCfgCmd);
value = rtl8723au_read8(padapter, offset);
value &= ~(GET_PWR_CFG_MASK(PwrCfgCmd));
value |= (GET_PWR_CFG_VALUE(PwrCfgCmd) &
GET_PWR_CFG_MASK(PwrCfgCmd));
rtl8723au_write8(padapter, offset, value);
break;
case PWR_CMD_POLLING:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("HalPwrSeqCmdParsing23a: "
"PWR_CMD_POLLING\n"));
bPollingBit = false;
offset = GET_PWR_CFG_OFFSET(PwrCfgCmd);
do {
value = rtl8723au_read8(padapter,
offset);
value &= GET_PWR_CFG_MASK(PwrCfgCmd);
if (value ==
(GET_PWR_CFG_VALUE(PwrCfgCmd) &
GET_PWR_CFG_MASK(PwrCfgCmd)))
bPollingBit = true;
else
udelay(10);
if (pollingCount++ > maxPollingCnt) {
DBG_8723A("Fail to polling "
"Offset[%#x]\n",
offset);
return false;
}
} while (!bPollingBit);
break;
case PWR_CMD_DELAY:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("HalPwrSeqCmdParsing23a: "
"PWR_CMD_DELAY\n"));
if (GET_PWR_CFG_VALUE(PwrCfgCmd) ==
PWRSEQ_DELAY_US)
udelay(GET_PWR_CFG_OFFSET(PwrCfgCmd));
else
udelay(GET_PWR_CFG_OFFSET(PwrCfgCmd) *
1000);
break;
case PWR_CMD_END:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("HalPwrSeqCmdParsing23a: "
"PWR_CMD_END\n"));
return true;
break;
default:
RT_TRACE(_module_hal_init_c_, _drv_err_,
("HalPwrSeqCmdParsing23a: "
"Unknown CMD!!\n"));
break;
}
}
AryIdx++;
} while (1);
return true;
}
