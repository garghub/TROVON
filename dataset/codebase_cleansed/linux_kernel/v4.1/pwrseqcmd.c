u8 rtl88eu_pwrseqcmdparsing(struct adapter *padapter, u8 cut_vers, u8 fab_vers,
u8 ifacetype, struct wl_pwr_cfg pwrseqcmd[])
{
struct wl_pwr_cfg pwrcfgcmd = {0};
u8 poll_bit = false;
u32 aryidx = 0;
u8 value = 0;
u32 offset = 0;
u32 poll_count = 0;
u32 max_poll_count = 5000;
do {
pwrcfgcmd = pwrseqcmd[aryidx];
RT_TRACE(_module_hal_init_c_ , _drv_info_,
("rtl88eu_pwrseqcmdparsing: offset(%#x) cut_msk(%#x)"
"fab_msk(%#x) interface_msk(%#x) base(%#x) cmd(%#x)"
"msk(%#x) value(%#x)\n",
GET_PWR_CFG_OFFSET(pwrcfgcmd),
GET_PWR_CFG_CUT_MASK(pwrcfgcmd),
GET_PWR_CFG_FAB_MASK(pwrcfgcmd),
GET_PWR_CFG_INTF_MASK(pwrcfgcmd),
GET_PWR_CFG_BASE(pwrcfgcmd),
GET_PWR_CFG_CMD(pwrcfgcmd),
GET_PWR_CFG_MASK(pwrcfgcmd),
GET_PWR_CFG_VALUE(pwrcfgcmd)));
if ((GET_PWR_CFG_FAB_MASK(pwrcfgcmd) & fab_vers) &&
(GET_PWR_CFG_CUT_MASK(pwrcfgcmd) & cut_vers) &&
(GET_PWR_CFG_INTF_MASK(pwrcfgcmd) & ifacetype)) {
switch (GET_PWR_CFG_CMD(pwrcfgcmd)) {
case PWR_CMD_READ:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("rtl88eu_pwrseqcmdparsing: PWR_CMD_READ\n"));
break;
case PWR_CMD_WRITE:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("rtl88eu_pwrseqcmdparsing: PWR_CMD_WRITE\n"));
offset = GET_PWR_CFG_OFFSET(pwrcfgcmd);
value = usb_read8(padapter, offset);
value &= ~(GET_PWR_CFG_MASK(pwrcfgcmd));
value |= (GET_PWR_CFG_VALUE(pwrcfgcmd) &
GET_PWR_CFG_MASK(pwrcfgcmd));
usb_write8(padapter, offset, value);
break;
case PWR_CMD_POLLING:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("rtl88eu_pwrseqcmdparsing: PWR_CMD_POLLING\n"));
poll_bit = false;
offset = GET_PWR_CFG_OFFSET(pwrcfgcmd);
do {
value = usb_read8(padapter, offset);
value &= GET_PWR_CFG_MASK(pwrcfgcmd);
if (value == (GET_PWR_CFG_VALUE(pwrcfgcmd) &
GET_PWR_CFG_MASK(pwrcfgcmd)))
poll_bit = true;
else
udelay(10);
if (poll_count++ > max_poll_count) {
DBG_88E("Fail to polling Offset[%#x]\n", offset);
return false;
}
} while (!poll_bit);
break;
case PWR_CMD_DELAY:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("rtl88eu_pwrseqcmdparsing: PWR_CMD_DELAY\n"));
if (GET_PWR_CFG_VALUE(pwrcfgcmd) == PWRSEQ_DELAY_US)
udelay(GET_PWR_CFG_OFFSET(pwrcfgcmd));
else
udelay(GET_PWR_CFG_OFFSET(pwrcfgcmd)*1000);
break;
case PWR_CMD_END:
RT_TRACE(_module_hal_init_c_, _drv_info_,
("rtl88eu_pwrseqcmdparsing: PWR_CMD_END\n"));
return true;
default:
RT_TRACE(_module_hal_init_c_, _drv_err_,
("rtl88eu_pwrseqcmdparsing: Unknown CMD!!\n"));
break;
}
}
aryidx++;
} while (1);
return true;
}
