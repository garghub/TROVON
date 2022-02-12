void am33xx_restart(enum reboot_mode mode, const char *cmd)
{
omap_prm_reset_system();
}
