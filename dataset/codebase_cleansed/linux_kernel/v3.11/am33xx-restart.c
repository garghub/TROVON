void am33xx_restart(enum reboot_mode mode, const char *cmd)
{
am33xx_prm_rmw_reg_bits(AM33XX_GLOBAL_WARM_SW_RST_MASK,
AM33XX_GLOBAL_WARM_SW_RST_MASK,
AM33XX_PRM_DEVICE_MOD,
AM33XX_PRM_RSTCTRL_OFFSET);
(void)am33xx_prm_read_reg(AM33XX_PRM_DEVICE_MOD,
AM33XX_PRM_RSTCTRL_OFFSET);
}
