void omap3xxx_restart(enum reboot_mode mode, const char *cmd)
{
omap3_ctrl_write_boot_mode((cmd ? (u8)*cmd : 0));
omap3xxx_prm_dpll3_reset();
while (1);
}
