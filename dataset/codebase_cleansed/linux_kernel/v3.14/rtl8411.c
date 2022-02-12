static u8 rtl8411_get_ic_version(struct rtsx_pcr *pcr)
{
u8 val;
rtsx_pci_read_register(pcr, SYS_VER, &val);
return val & 0x0F;
}
static int rtl8411b_is_qfn48(struct rtsx_pcr *pcr)
{
u8 val = 0;
rtsx_pci_read_register(pcr, RTL8411B_PACKAGE_MODE, &val);
if (val & 0x2)
return 1;
else
return 0;
}
static void rtl8411_fetch_vendor_settings(struct rtsx_pcr *pcr)
{
u32 reg1 = 0;
u8 reg3 = 0;
rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG1, &reg1);
dev_dbg(&(pcr->pci->dev), "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG1, reg1);
if (!rtsx_vendor_setting_valid(reg1))
return;
pcr->aspm_en = rtsx_reg_to_aspm(reg1);
pcr->sd30_drive_sel_1v8 =
map_sd_drive(rtsx_reg_to_sd30_drive_sel_1v8(reg1));
pcr->card_drive_sel &= 0x3F;
pcr->card_drive_sel |= rtsx_reg_to_card_drive_sel(reg1);
rtsx_pci_read_config_byte(pcr, PCR_SETTING_REG3, &reg3);
dev_dbg(&(pcr->pci->dev), "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG3, reg3);
pcr->sd30_drive_sel_3v3 = rtl8411_reg_to_sd30_drive_sel_3v3(reg3);
}
static void rtl8411b_fetch_vendor_settings(struct rtsx_pcr *pcr)
{
u32 reg = 0;
rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG1, &reg);
dev_dbg(&(pcr->pci->dev), "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG1, reg);
if (!rtsx_vendor_setting_valid(reg))
return;
pcr->aspm_en = rtsx_reg_to_aspm(reg);
pcr->sd30_drive_sel_1v8 =
map_sd_drive(rtsx_reg_to_sd30_drive_sel_1v8(reg));
pcr->sd30_drive_sel_3v3 =
map_sd_drive(rtl8411b_reg_to_sd30_drive_sel_3v3(reg));
}
static void rtl8411_force_power_down(struct rtsx_pcr *pcr, u8 pm_state)
{
rtsx_pci_write_register(pcr, FPDCTL, 0x07, 0x07);
}
static int rtl8411_extra_init_hw(struct rtsx_pcr *pcr)
{
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_DRIVE_SEL,
0xFF, pcr->sd30_drive_sel_3v3);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CD_PAD_CTL,
CD_DISABLE_MASK | CD_AUTO_DISABLE, CD_ENABLE);
return rtsx_pci_send_cmd(pcr, 100);
}
static int rtl8411b_extra_init_hw(struct rtsx_pcr *pcr)
{
rtsx_pci_init_cmd(pcr);
if (rtl8411b_is_qfn48(pcr))
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD,
CARD_PULL_CTL3, 0xFF, 0xF5);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_DRIVE_SEL,
0xFF, pcr->sd30_drive_sel_3v3);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CD_PAD_CTL,
CD_DISABLE_MASK | CD_AUTO_DISABLE, CD_ENABLE);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, FUNC_FORCE_CTL,
0x06, 0x00);
return rtsx_pci_send_cmd(pcr, 100);
}
static int rtl8411_turn_on_led(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, CARD_GPIO, 0x01, 0x00);
}
static int rtl8411_turn_off_led(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, CARD_GPIO, 0x01, 0x01);
}
static int rtl8411_enable_auto_blink(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, CARD_AUTO_BLINK, 0xFF, 0x0D);
}
static int rtl8411_disable_auto_blink(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, CARD_AUTO_BLINK, 0x08, 0x00);
}
static int rtl8411_card_power_on(struct rtsx_pcr *pcr, int card)
{
int err;
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
BPP_POWER_MASK, BPP_POWER_5_PERCENT_ON);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_CTL,
BPP_LDO_POWB, BPP_LDO_SUSPEND);
err = rtsx_pci_send_cmd(pcr, 100);
if (err < 0)
return err;
udelay(150);
err = rtsx_pci_write_register(pcr, CARD_PWR_CTL,
BPP_POWER_MASK, BPP_POWER_10_PERCENT_ON);
if (err < 0)
return err;
udelay(150);
err = rtsx_pci_write_register(pcr, CARD_PWR_CTL,
BPP_POWER_MASK, BPP_POWER_15_PERCENT_ON);
if (err < 0)
return err;
udelay(150);
err = rtsx_pci_write_register(pcr, CARD_PWR_CTL,
BPP_POWER_MASK, BPP_POWER_ON);
if (err < 0)
return err;
return rtsx_pci_write_register(pcr, LDO_CTL, BPP_LDO_POWB, BPP_LDO_ON);
}
static int rtl8411_card_power_off(struct rtsx_pcr *pcr, int card)
{
int err;
err = rtsx_pci_write_register(pcr, CARD_PWR_CTL,
BPP_POWER_MASK, BPP_POWER_OFF);
if (err < 0)
return err;
return rtsx_pci_write_register(pcr, LDO_CTL,
BPP_LDO_POWB, BPP_LDO_SUSPEND);
}
static int rtl8411_do_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage,
int bpp_tuned18_shift, int bpp_asic_1v8)
{
u8 mask, val;
int err;
mask = (BPP_REG_TUNED18 << bpp_tuned18_shift) | BPP_PAD_MASK;
if (voltage == OUTPUT_3V3) {
err = rtsx_pci_write_register(pcr,
SD30_DRIVE_SEL, 0x07, pcr->sd30_drive_sel_3v3);
if (err < 0)
return err;
val = (BPP_ASIC_3V3 << bpp_tuned18_shift) | BPP_PAD_3V3;
} else if (voltage == OUTPUT_1V8) {
err = rtsx_pci_write_register(pcr,
SD30_DRIVE_SEL, 0x07, pcr->sd30_drive_sel_1v8);
if (err < 0)
return err;
val = (bpp_asic_1v8 << bpp_tuned18_shift) | BPP_PAD_1V8;
} else {
return -EINVAL;
}
return rtsx_pci_write_register(pcr, LDO_CTL, mask, val);
}
static int rtl8411_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
return rtl8411_do_switch_output_voltage(pcr, voltage,
BPP_TUNED18_SHIFT_8411, BPP_ASIC_1V8);
}
static int rtl8402_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
return rtl8411_do_switch_output_voltage(pcr, voltage,
BPP_TUNED18_SHIFT_8402, BPP_ASIC_2V0);
}
static unsigned int rtl8411_cd_deglitch(struct rtsx_pcr *pcr)
{
unsigned int card_exist;
card_exist = rtsx_pci_readl(pcr, RTSX_BIPR);
card_exist &= CARD_EXIST;
if (!card_exist) {
rtsx_pci_write_register(pcr, CD_PAD_CTL,
CD_DISABLE_MASK, CD_ENABLE);
rtsx_pci_write_register(pcr, EFUSE_CONTENT, 0xe0, 0x00);
return 0;
}
if (hweight32(card_exist) > 1) {
rtsx_pci_write_register(pcr, CARD_PWR_CTL,
BPP_POWER_MASK, BPP_POWER_5_PERCENT_ON);
msleep(100);
card_exist = rtsx_pci_readl(pcr, RTSX_BIPR);
if (card_exist & MS_EXIST)
card_exist = MS_EXIST;
else if (card_exist & SD_EXIST)
card_exist = SD_EXIST;
else
card_exist = 0;
rtsx_pci_write_register(pcr, CARD_PWR_CTL,
BPP_POWER_MASK, BPP_POWER_OFF);
dev_dbg(&(pcr->pci->dev),
"After CD deglitch, card_exist = 0x%x\n",
card_exist);
}
if (card_exist & MS_EXIST) {
rtsx_pci_write_register(pcr, EFUSE_CONTENT, 0xe0, 0x40);
rtsx_pci_write_register(pcr, CD_PAD_CTL,
CD_DISABLE_MASK, MS_CD_EN_ONLY);
} else if (card_exist & SD_EXIST) {
rtsx_pci_write_register(pcr, EFUSE_CONTENT, 0xe0, 0x80);
rtsx_pci_write_register(pcr, CD_PAD_CTL,
CD_DISABLE_MASK, SD_CD_EN_ONLY);
}
return card_exist;
}
static int rtl8411_conv_clk_and_div_n(int input, int dir)
{
int output;
if (dir == CLK_TO_DIV_N)
output = input * 4 / 5 - 2;
else
output = (input + 2) * 5 / 4;
return output;
}
static void rtl8411_init_common_params(struct rtsx_pcr *pcr)
{
pcr->extra_caps = EXTRA_CAPS_SD_SDR50 | EXTRA_CAPS_SD_SDR104;
pcr->num_slots = 2;
pcr->flags = 0;
pcr->card_drive_sel = RTL8411_CARD_DRIVE_DEFAULT;
pcr->sd30_drive_sel_1v8 = DRIVER_TYPE_B;
pcr->sd30_drive_sel_3v3 = DRIVER_TYPE_D;
pcr->aspm_en = ASPM_L1_EN;
pcr->tx_initial_phase = SET_CLOCK_PHASE(23, 7, 14);
pcr->rx_initial_phase = SET_CLOCK_PHASE(4, 3, 10);
pcr->ic_version = rtl8411_get_ic_version(pcr);
}
void rtl8411_init_params(struct rtsx_pcr *pcr)
{
rtl8411_init_common_params(pcr);
pcr->ops = &rtl8411_pcr_ops;
set_pull_ctrl_tables(pcr, rtl8411);
}
void rtl8411b_init_params(struct rtsx_pcr *pcr)
{
rtl8411_init_common_params(pcr);
pcr->ops = &rtl8411b_pcr_ops;
if (rtl8411b_is_qfn48(pcr))
set_pull_ctrl_tables(pcr, rtl8411b_qfn48);
else
set_pull_ctrl_tables(pcr, rtl8411b_qfn64);
}
void rtl8402_init_params(struct rtsx_pcr *pcr)
{
rtl8411_init_common_params(pcr);
pcr->ops = &rtl8402_pcr_ops;
set_pull_ctrl_tables(pcr, rtl8411);
}
