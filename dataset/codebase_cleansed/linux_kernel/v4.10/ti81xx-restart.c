void ti81xx_restart(enum reboot_mode mode, const char *cmd)
{
omap2_prm_set_mod_reg_bits(TI81XX_GLOBAL_RST_COLD, 0,
TI81XX_PRM_DEVICE_RSTCTRL);
while (1);
}
