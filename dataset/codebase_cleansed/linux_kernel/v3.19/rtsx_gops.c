int rtsx_gops_pm_reset(struct rtsx_pcr *pcr)
{
int err;
rtsx_pci_write_register(pcr, ASPM_FORCE_CTL, 0xFF, 0x00);
err = rtsx_pci_update_cfg_byte(pcr, LCTLR, ~LCTLR_ASPM_CTL_MASK, 0x00);
if (err < 0)
return err;
return rtsx_pci_write_register(pcr, PM_CTRL3, D3_DELINK_MODE_EN, 0x00);
}
