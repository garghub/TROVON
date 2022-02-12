static u8 rts5229_get_ic_version(struct rtsx_pcr *pcr)
{
u8 val;
rtsx_pci_read_register(pcr, DUMMY_REG_RESET_0, &val);
return val & 0x0F;
}
static int rts5229_extra_init_hw(struct rtsx_pcr *pcr)
{
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, GPIO_CTL, 0x02, 0x02);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_PWR_SEL, 0x03, 0x00);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, LDO_PWR_SEL, 0x03, 0x01);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, OLT_LED_CTL, 0x0F, 0x02);
return rtsx_pci_send_cmd(pcr, 100);
}
static int rts5229_optimize_phy(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_phy_register(pcr, 0x00, 0xBA42);
}
static int rts5229_turn_on_led(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, GPIO_CTL, 0x02, 0x02);
}
static int rts5229_turn_off_led(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, GPIO_CTL, 0x02, 0x00);
}
static int rts5229_enable_auto_blink(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, OLT_LED_CTL, 0x08, 0x08);
}
static int rts5229_disable_auto_blink(struct rtsx_pcr *pcr)
{
return rtsx_pci_write_register(pcr, OLT_LED_CTL, 0x08, 0x00);
}
static int rts5229_card_power_on(struct rtsx_pcr *pcr, int card)
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
static int rts5229_card_power_off(struct rtsx_pcr *pcr, int card)
{
rtsx_pci_init_cmd(pcr);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, CARD_PWR_CTL,
SD_POWER_MASK | PMOS_STRG_MASK,
SD_POWER_OFF | PMOS_STRG_400mA);
rtsx_pci_add_cmd(pcr, WRITE_REG_CMD, PWR_GATE_CTRL,
LDO3318_PWR_MASK, 0X00);
return rtsx_pci_send_cmd(pcr, 100);
}
static int rts5229_switch_output_voltage(struct rtsx_pcr *pcr, u8 voltage)
{
int err;
if (voltage == OUTPUT_3V3) {
err = rtsx_pci_write_phy_register(pcr, 0x08, 0x4FC0 | 0x24);
if (err < 0)
return err;
} else if (voltage == OUTPUT_1V8) {
err = rtsx_pci_write_phy_register(pcr, 0x08, 0x4C40 | 0x24);
if (err < 0)
return err;
} else {
return -EINVAL;
}
return 0;
}
void rts5229_init_params(struct rtsx_pcr *pcr)
{
pcr->extra_caps = EXTRA_CAPS_SD_SDR50 | EXTRA_CAPS_SD_SDR104;
pcr->num_slots = 2;
pcr->ops = &rts5229_pcr_ops;
pcr->ic_version = rts5229_get_ic_version(pcr);
if (pcr->ic_version == IC_VER_C) {
pcr->sd_pull_ctl_enable_tbl = rts5229_sd_pull_ctl_enable_tbl2;
pcr->sd_pull_ctl_disable_tbl = rts5229_sd_pull_ctl_disable_tbl2;
} else {
pcr->sd_pull_ctl_enable_tbl = rts5229_sd_pull_ctl_enable_tbl1;
pcr->sd_pull_ctl_disable_tbl = rts5229_sd_pull_ctl_disable_tbl1;
}
pcr->ms_pull_ctl_enable_tbl = rts5229_ms_pull_ctl_enable_tbl;
pcr->ms_pull_ctl_disable_tbl = rts5229_ms_pull_ctl_disable_tbl;
}
