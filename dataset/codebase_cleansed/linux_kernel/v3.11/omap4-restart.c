void omap44xx_restart(enum reboot_mode mode, const char *cmd)
{
omap4_prminst_global_warm_sw_reset();
while (1)
;
}
