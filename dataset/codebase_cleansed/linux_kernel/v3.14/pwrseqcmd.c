bool rtl_hal_pwrseqcmdparsing (struct rtl_priv* rtlpriv, u8 cut_version,
u8 fab_version, u8 interface_type,
struct wlan_pwr_cfg pwrcfgcmd[])
{
struct wlan_pwr_cfg pwr_cfg_cmd = {0};
bool polling_bit = false;
u32 ary_idx=0;
u8 value = 0;
u32 offset = 0;
u32 polling_count = 0;
u32 max_polling_cnt = 5000;
do {
pwr_cfg_cmd = pwrcfgcmd[ary_idx];
RT_TRACE(COMP_INIT, DBG_TRACE,
("rtl_hal_pwrseqcmdparsing(): offset(%#x),cut_msk(%#x), fab_msk(%#x),"
"interface_msk(%#x), base(%#x), cmd(%#x), msk(%#x), value(%#x)\n",
GET_PWR_CFG_OFFSET(pwr_cfg_cmd), GET_PWR_CFG_CUT_MASK(pwr_cfg_cmd),
GET_PWR_CFG_FAB_MASK(pwr_cfg_cmd), GET_PWR_CFG_INTF_MASK(pwr_cfg_cmd),
GET_PWR_CFG_BASE(pwr_cfg_cmd), GET_PWR_CFG_CMD(pwr_cfg_cmd),
GET_PWR_CFG_MASK(pwr_cfg_cmd), GET_PWR_CFG_VALUE(pwr_cfg_cmd)));
if ((GET_PWR_CFG_FAB_MASK(pwr_cfg_cmd)&fab_version) &&
(GET_PWR_CFG_CUT_MASK(pwr_cfg_cmd)&cut_version) &&
(GET_PWR_CFG_INTF_MASK(pwr_cfg_cmd)&interface_type)) {
switch (GET_PWR_CFG_CMD(pwr_cfg_cmd)) {
case PWR_CMD_READ:
RT_TRACE(COMP_INIT, DBG_TRACE,
("rtl_hal_pwrseqcmdparsing(): PWR_CMD_READ\n"));
break;
case PWR_CMD_WRITE: {
RT_TRACE(COMP_INIT, DBG_TRACE,
("rtl_hal_pwrseqcmdparsing(): PWR_CMD_WRITE\n"));
offset = GET_PWR_CFG_OFFSET(pwr_cfg_cmd);
value = rtl_read_byte(rtlpriv, offset);
value = value & (~(GET_PWR_CFG_MASK(pwr_cfg_cmd)));
value = value | (GET_PWR_CFG_VALUE(pwr_cfg_cmd)
& GET_PWR_CFG_MASK(pwr_cfg_cmd));
rtl_write_byte(rtlpriv, offset, value);
}
break;
case PWR_CMD_POLLING:
RT_TRACE(COMP_INIT, DBG_TRACE,
("rtl_hal_pwrseqcmdparsing(): PWR_CMD_POLLING\n"));
polling_bit = false;
offset = GET_PWR_CFG_OFFSET(pwr_cfg_cmd);
do {
value = rtl_read_byte(rtlpriv, offset);
value = value & GET_PWR_CFG_MASK(pwr_cfg_cmd);
if (value == (GET_PWR_CFG_VALUE(pwr_cfg_cmd)
& GET_PWR_CFG_MASK(pwr_cfg_cmd)))
polling_bit=true;
else
udelay(10);
if (polling_count++ > max_polling_cnt) {
return false;
}
} while (!polling_bit);
break;
case PWR_CMD_DELAY:
RT_TRACE(COMP_INIT, DBG_TRACE,
("rtl_hal_pwrseqcmdparsing(): PWR_CMD_DELAY\n"));
if (GET_PWR_CFG_VALUE(pwr_cfg_cmd) == PWRSEQ_DELAY_US)
udelay(GET_PWR_CFG_OFFSET(pwr_cfg_cmd));
else
mdelay(GET_PWR_CFG_OFFSET(pwr_cfg_cmd));
break;
case PWR_CMD_END:
RT_TRACE(COMP_INIT, DBG_TRACE,
("rtl_hal_pwrseqcmdparsing(): PWR_CMD_END\n"));
return true;
break;
default:
RT_ASSERT(false,
("rtl_hal_pwrseqcmdparsing(): Unknown CMD!!\n"));
break;
}
}
ary_idx++;
} while (1);
return true;
}
