static u8 rts5249_get_ic_version(struct rtsx_pcr *pcr)
{
u8 val;
rtsx_pci_read_register(pcr, DUMMY_REG_RESET_0, &val);
return val & 0x0F;
}
static void rts5249_fill_driving(struct rtsx_pcr *pcr, u8 voltage)
{
u8 driving_3v3[4][3] = {
{0x11, 0x11, 0x11},
{0x55, 0x55, 0x5C},
{0x99, 0x99, 0x92},
{0x99, 0x99, 0x92},
};
u8 driving_1v8[4][3] = {
{0x3C, 0x3C, 0x3C},
{0xB3, 0xB3, 0xB3},
{0xFE, 0xFE, 0xFE},
{0xC4, 0xC4, 0xC4},
};
u8 (*driving)[3], drive_sel;
if (voltage == OUTPUT_3V3) {
driving = driving_3v3;
drive_sel = pcr->sd30_drive_sel_3v3;
} else {
driving = driving_1v8;
drive_sel = pcr->sd30_drive_sel_1v8;
}
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_CLK_DRIVE_SEL,
0xFF, driving[drive_sel][0]);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_CMD_DRIVE_SEL,
0xFF, driving[drive_sel][1]);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_DAT_DRIVE_SEL,
0xFF, driving[drive_sel][2]);
}
static void rts5249_fetch_vendor_settings(struct rtsx_pcr *pcr)
{
u32 reg;
rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG1, &reg);
dev_dbg(&(pcr->pci->dev), "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG1, reg);
if (!rtsx_vendor_setting_valid(reg))
return;
pcr->aspm_en = rtsx_reg_to_aspm(reg);
pcr->sd30_drive_sel_1v8 = rtsx_reg_to_sd30_drive_sel_1v8(reg);
pcr->card_drive_sel &= 0x3F;
pcr->card_drive_sel |= rtsx_reg_to_card_drive_sel(reg);
rtsx_pci_read_config_dword(pcr, PCR_SETTING_REG2, &reg);
dev_dbg(&(pcr->pci->dev), "Cfg 0x%x: 0x%x\n", PCR_SETTING_REG2, reg);
pcr->sd30_drive_sel_3v3 = rtsx_reg_to_sd30_drive_sel_3v3(reg);
if (rtsx_reg_check_reverse_socket(reg))
pcr->flags |= PCR_REVERSE_SOCKET;
}
static void rts5249_force_power_down(struct rtsx_pcr *pcr, u8 pm_state)
{
rtsx_pci_write_register(pcr, AUTOLOAD_CFG_BASE + 1, 0xFF, 0);
rtsx_pci_write_register(pcr, AUTOLOAD_CFG_BASE + 2, 0xFF, 0);
rtsx_pci_write_register(pcr, AUTOLOAD_CFG_BASE + 3, 0x01, 0);
if (pm_state == HOST_ENTER_S3)
rtsx_pci_write_register(pcr, PM_CTRL3, 0x10, 0x10);
rtsx_pci_write_register(pcr, FPDCTL, 0x03, 0x03);
}
static int rts5249_extra_init_hw(struct rtsx_pcr *pcr)
{
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, GPIO_CTL, 0x02, 0x02);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, ASPM_FORCE_CTL, 0x3F, 0);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_PWR_SEL, 0x03, 0x00);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_PWR_SEL, 0x03, 0x01);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, OLT_LED_CTL, 0x0F, 0x02);
rts5249_fill_driving(pcr, OUTPUT_3V3);
if (pcr->flags & PCR_REVERSE_SOCKET)
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD,
AUTOLOAD_CFG_BASE + 3, 0xB0, 0xB0);
else
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD,
AUTOLOAD_CFG_BASE + 3, 0xB0, 0x80);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PM_CTRL3, 0x10, 0x00);
return rtsx_pci_send_cmd(pcr, 100);
}
static int rts5249_optimize_phy(struct rtsx_pcr *pcr)
{
int err;
err = rtsx_pci_write_phy_register(pcr, PHY_REG_REV, 0xFE46);
if (err < 0)
return err;
msleep(1);
return rtsx_pci_write_phy_register(pcr, PHY_BPCR, 0x05C0);
}
static int rts5249_turn_on_led(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, GPIO_CTL, 0x02, 0x02);
}
static int rts5249_turn_off_led(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, GPIO_CTL, 0x02, 0x00);
}
static int rts5249_enable_auto_blink(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, OLT_LED_CTL, 0x08, 0x08);
}
static int rts5249_disable_auto_blink(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, OLT_LED_CTL, 0x08, 0x00);
}
static int rts5249_card_power_on(struct rtsx_pcr *pcr, int card)
{
int err;
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
SD_POWER_MASK, SD_VCC_PARTIAL_POWER_ON);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
LDO3318_PWR_MASK, 0x02);
err = rtsx_pci_send_cmd(pcr, 100);
if (err < 0)
return err;
msleep(5);
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
SD_POWER_MASK, SD_VCC_POWER_ON);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
LDO3318_PWR_MASK, 0x06);
err = rtsx_pci_send_cmd(pcr, 100);
if (err < 0)
return err;
return 0;
}
static int rts5249_card_power_off(struct rtsx_pcr *pcr, int card)
{
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
SD_POWER_MASK, SD_POWER_OFF);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
LDO3318_PWR_MASK, 0x00);
return rtsx_pci_send_cmd(pcr, 100);
}
static int rts5249_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
int err;
if (voltage == OUTPUT_3V3) {
err = rtsx_pci_write_phy_register(pcr, PHY_TUNE, 0x4FC0 | 0x24);
if (err < 0)
return err;
} else if (voltage == OUTPUT_1V8) {
err = rtsx_pci_write_phy_register(pcr, PHY_BACR, 0x3C02);
if (err < 0)
return err;
err = rtsx_pci_write_phy_register(pcr, PHY_TUNE, 0x4C40 | 0x24);
if (err < 0)
return err;
} else {
return -EINVAL;
}
rtsx_pci_init_cmd(pcr);
rts5249_fill_driving(pcr, voltage);
return rtsx_pci_send_cmd(pcr, 100);
}
void rts5249_init_params(struct rtsx_pcr *pcr)
{
pcr->extra_caps = EXTRA_CAPS_SD_SDR50 | EXTRA_CAPS_SD_SDR104;
pcr->num_slots = 2;
pcr->ops = &rts5249_pcr_ops;
pcr->flags = 0;
pcr->card_drive_sel = RTSX_CARD_DRIVE_DEFAULT;
pcr->sd30_drive_sel_1v8 = CFG_DRIVER_TYPE_C;
pcr->sd30_drive_sel_3v3 = CFG_DRIVER_TYPE_B;
pcr->aspm_en = ASPM_L1_EN;
pcr->tx_initial_phase = SET_CLOCK_PHASE(1, 29, 16);
pcr->rx_initial_phase = SET_CLOCK_PHASE(24, 6, 5);
pcr->ic_version = rts5249_get_ic_version(pcr);
pcr->sd_pull_ctl_enable_tbl = rts5249_sd_pull_ctl_enable_tbl;
pcr->sd_pull_ctl_disable_tbl = rts5249_sd_pull_ctl_disable_tbl;
pcr->ms_pull_ctl_enable_tbl = rts5249_ms_pull_ctl_enable_tbl;
pcr->ms_pull_ctl_disable_tbl = rts5249_ms_pull_ctl_disable_tbl;
}
