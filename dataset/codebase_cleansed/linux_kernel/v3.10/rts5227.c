static int rts5227_extra_init_hw(struct rtsx_pcr *pcr)
{
u16 cap;
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, GPIO_CTL, 0x02, 0x02);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_PWR_SEL, 0x03, 0x00);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_PWR_SEL, 0x03, 0x01);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, OLT_LED_CTL, 0x0F, 0x02);
pcie_capability_read_word(pcr->pci, PCI_EXP_DEVCTL2, &cap);
if (cap & PCI_EXP_LTR_EN)
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LTR_CTL, 0xFF, 0xA3);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, OBFF_CFG, 0x03, 0x03);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, 0xFF03, 0x08, 0x08);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD,
SD30_CLK_DRIVE_SEL, 0xFF, 0x96);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD,
SD30_CMD_DRIVE_SEL, 0xFF, 0x96);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD,
SD30_DAT_DRIVE_SEL, 0xFF, 0x96);
return rtsx_pci_send_cmd(pcr, 100);
}
static int rts5227_optimize_phy(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_phy_register(pcr, 0x00, 0xBA42);
}
static int rts5227_turn_on_led(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, GPIO_CTL, 0x02, 0x02);
}
static int rts5227_turn_off_led(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, GPIO_CTL, 0x02, 0x00);
}
static int rts5227_enable_auto_blink(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, OLT_LED_CTL, 0x08, 0x08);
}
static int rts5227_disable_auto_blink(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, OLT_LED_CTL, 0x08, 0x00);
}
static int rts5227_card_power_on(struct rtsx_pcr *pcr, int card)
{
int err;
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
SD_POWER_MASK, SD_PARTIAL_POWER_ON);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
LDO3318_PWR_MASK, 0x02);
err = rtsx_pci_send_cmd(pcr, 100);
if (err < 0)
return err;
udelay(150);
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
SD_POWER_MASK, SD_POWER_ON);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
LDO3318_PWR_MASK, 0x06);
err = rtsx_pci_send_cmd(pcr, 100);
if (err < 0)
return err;
return 0;
}
static int rts5227_card_power_off(struct rtsx_pcr *pcr, int card)
{
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
SD_POWER_MASK | PMOS_STRG_MASK,
SD_POWER_OFF | PMOS_STRG_400mA);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
LDO3318_PWR_MASK, 0X00);
return rtsx_pci_send_cmd(pcr, 100);
}
static int rts5227_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
int err;
u8 drive_sel;
if (voltage == OUTPUT_3V3) {
err = rtsx_pci_write_phy_register(pcr, 0x08, 0x4FC0 | 0x24);
if (err < 0)
return err;
drive_sel = 0x96;
} else if (voltage == OUTPUT_1V8) {
err = rtsx_pci_write_phy_register(pcr, 0x11, 0x3C02);
if (err < 0)
return err;
err = rtsx_pci_write_phy_register(pcr, 0x08, 0x4C80 | 0x24);
if (err < 0)
return err;
drive_sel = 0xB3;
} else {
return -EINVAL;
}
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_CLK_DRIVE_SEL,
0xFF, drive_sel);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_CMD_DRIVE_SEL,
0xFF, drive_sel);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, SD30_DAT_DRIVE_SEL,
0xFF, drive_sel);
return rtsx_pci_send_cmd(pcr, 100);
}
void rts5227_init_params(struct rtsx_pcr *pcr)
{
pcr->extra_caps = EXTRA_CAPS_SD_SDR50 | EXTRA_CAPS_SD_SDR104;
pcr->num_slots = 2;
pcr->ops = &rts5227_pcr_ops;
pcr->sd_pull_ctl_enable_tbl = rts5227_sd_pull_ctl_enable_tbl;
pcr->sd_pull_ctl_disable_tbl = rts5227_sd_pull_ctl_disable_tbl;
pcr->ms_pull_ctl_enable_tbl = rts5227_ms_pull_ctl_enable_tbl;
pcr->ms_pull_ctl_disable_tbl = rts5227_ms_pull_ctl_disable_tbl;
}
