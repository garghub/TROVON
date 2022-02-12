void omap3xxx_restart(enum reboot_mode mode, const char *cmd)
{
omap3_ctrl_write_boot_mode((cmd ? (u8)*cmd : 0));
omap_prm_reset_system();
}
