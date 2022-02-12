static int __init omap3logic_i2c_init(void)
{
omap3_pmic_init("twl4030", &omap3logic_twldata);
return 0;
}
static void __init board_mmc_init(void)
{
if (machine_is_omap3530_lv_som()) {
board_mmc_info[0].gpio_cd = OMAP3530_LV_SOM_MMC_GPIO_CD;
board_mmc_info[0].gpio_wp = OMAP3530_LV_SOM_MMC_GPIO_WP;
omap_mux_init_signal("gpio_110", OMAP_PIN_OUTPUT);
omap_mux_init_signal("gpio_126", OMAP_PIN_OUTPUT);
} else if (machine_is_omap3_torpedo()) {
board_mmc_info[0].gpio_cd = OMAP3_TORPEDO_MMC_GPIO_CD;
omap_mux_init_signal("gpio_127", OMAP_PIN_OUTPUT);
} else {
printk(KERN_ERR "%s(): unknown machine type\n", __func__);
return;
}
omap2_hsmmc_init(board_mmc_info);
}
static void omap3torpedo_fix_pbias_voltage(void)
{
u16 control_pbias_offset = OMAP343X_CONTROL_PBIAS_LITE;
u32 reg;
if (machine_is_omap3_torpedo())
{
reg = omap_ctrl_readl(control_pbias_offset);
reg &= ~OMAP343X_PBIASLITEPWRDNZ1;
omap_ctrl_writel(reg, control_pbias_offset);
msleep(100);
reg |= OMAP343X_PBIASLITEVMODE1;
reg |= OMAP343X_PBIASLITEPWRDNZ1;
omap_ctrl_writel(reg | 0x300, control_pbias_offset);
}
}
static inline void __init board_smsc911x_init(void)
{
if (machine_is_omap3530_lv_som()) {
board_smsc911x_data.gpio_irq =
OMAP3530_LV_SOM_SMSC911X_GPIO_IRQ;
omap_mux_init_signal("gpio_152", OMAP_PIN_INPUT);
} else if (machine_is_omap3_torpedo()) {
board_smsc911x_data.gpio_irq = OMAP3_TORPEDO_SMSC911X_GPIO_IRQ;
omap_mux_init_signal("gpio_129", OMAP_PIN_INPUT);
} else {
printk(KERN_ERR "%s(): unknown machine type\n", __func__);
return;
}
gpmc_smsc911x_init(&board_smsc911x_data);
}
static void __init omap3logic_init(void)
{
omap3_mux_init(board_mux, OMAP_PACKAGE_CBB);
omap3torpedo_fix_pbias_voltage();
omap3logic_i2c_init();
omap_serial_init();
omap_sdrc_init(NULL, NULL);
board_mmc_init();
board_smsc911x_init();
omap_mux_init_signal("sdrc_cke0", OMAP_PIN_OUTPUT);
omap_mux_init_signal("sdrc_cke1", OMAP_PIN_OUTPUT);
}
