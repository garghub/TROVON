static void __init __used legacy_init_ehci_clk(char *clkname)
{
int ret;
ret = clk_add_alias("main_clk", NULL, clkname, NULL);
if (ret)
pr_err("%s:Failed to add main_clk alias to %s :%d\n",
__func__, clkname, ret);
}
static void __init __used legacy_init_wl12xx(unsigned ref_clock,
unsigned tcxo_clock,
int gpio)
{
int res;
wl12xx.board_ref_clock = ref_clock;
wl12xx.board_tcxo_clock = tcxo_clock;
wl12xx.irq = gpio_to_irq(gpio);
res = wl12xx_set_platform_data(&wl12xx);
if (res) {
pr_err("error setting wl12xx data: %d\n", res);
return;
}
}
static inline void legacy_init_wl12xx(unsigned ref_clock,
unsigned tcxo_clock,
int gpio)
{
}
static void __init omap2420_n8x0_legacy_init(void)
{
omap_auxdata_lookup[0].platform_data = n8x0_legacy_init();
}
static void __init hsmmc2_internal_input_clk(void)
{
u32 reg;
reg = omap_ctrl_readl(OMAP343X_CONTROL_DEVCONF1);
reg |= OMAP2_MMCSDIO2ADPCLKISEL;
omap_ctrl_writel(reg, OMAP343X_CONTROL_DEVCONF1);
}
static int omap3_sbc_t3730_twl_callback(struct device *dev,
unsigned gpio,
unsigned ngpio)
{
int res;
res = gpio_request_one(gpio + 2, GPIOF_OUT_INIT_HIGH,
"wlan rst");
if (res)
return res;
gpio_export(gpio, 0);
return 0;
}
static void __init omap3_sbc_t3730_twl_init(void)
{
twl_gpio_auxdata.setup = omap3_sbc_t3730_twl_callback;
}
static void __init omap3_sbc_t3730_legacy_init(void)
{
legacy_init_wl12xx(WL12XX_REFCLOCK_38, 0, 136);
omap_ads7846_init(1, 57, 0, NULL);
}
static void __init omap3_igep0020_legacy_init(void)
{
omap3_igep2_display_init_of();
}
static void __init omap3_evm_legacy_init(void)
{
legacy_init_wl12xx(WL12XX_REFCLOCK_38, 0, 149);
}
static void __init omap3_zoom_legacy_init(void)
{
legacy_init_wl12xx(WL12XX_REFCLOCK_26, 0, 162);
}
static void am35xx_enable_emac_int(void)
{
u32 v;
v = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
v |= (AM35XX_CPGMAC_C0_RX_PULSE_CLR | AM35XX_CPGMAC_C0_TX_PULSE_CLR |
AM35XX_CPGMAC_C0_MISC_PULSE_CLR | AM35XX_CPGMAC_C0_RX_THRESH_CLR);
omap_ctrl_writel(v, AM35XX_CONTROL_LVL_INTR_CLEAR);
omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
static void am35xx_disable_emac_int(void)
{
u32 v;
v = omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
v |= (AM35XX_CPGMAC_C0_RX_PULSE_CLR | AM35XX_CPGMAC_C0_TX_PULSE_CLR);
omap_ctrl_writel(v, AM35XX_CONTROL_LVL_INTR_CLEAR);
omap_ctrl_readl(AM35XX_CONTROL_LVL_INTR_CLEAR);
}
static void __init am3517_evm_legacy_init(void)
{
u32 v;
v = omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
v &= ~AM35XX_CPGMACSS_SW_RST;
omap_ctrl_writel(v, AM35XX_CONTROL_IP_SW_RESET);
omap_ctrl_readl(AM35XX_CONTROL_IP_SW_RESET);
}
static void __init nokia_n900_legacy_init(void)
{
hsmmc2_internal_input_clk();
if (omap_type() == OMAP2_DEVICE_TYPE_SEC) {
if (IS_ENABLED(CONFIG_ARM_ERRATA_430973)) {
pr_info("RX-51: Enabling ARM errata 430973 workaround\n");
rx51_secure_update_aux_cr(BIT(6), 0);
} else {
pr_warning("RX-51: Not enabling ARM errata 430973 workaround\n");
pr_warning("Thumb binaries may crash randomly without this workaround\n");
}
}
}
static void __init omap4_sdp_legacy_init(void)
{
omap_4430sdp_display_init_of();
legacy_init_wl12xx(WL12XX_REFCLOCK_26,
WL12XX_TCXOCLOCK_26, 53);
}
static void __init omap4_panda_legacy_init(void)
{
omap4_panda_display_init_of();
legacy_init_ehci_clk("auxclk3_ck");
legacy_init_wl12xx(WL12XX_REFCLOCK_38, 0, 53);
}
static void __init omap5_uevm_legacy_init(void)
{
legacy_init_ehci_clk("auxclk1_ck");
}
void omap_pcs_legacy_init(int irq, void (*rearm)(void))
{
pcs_pdata.irq = irq;
pcs_pdata.rearm = rearm;
}
void omap_auxdata_legacy_init(struct device *dev)
{
if (dev->platform_data)
return;
if (strcmp("twl4030-gpio", dev_name(dev)))
return;
dev->platform_data = &twl_gpio_auxdata;
}
static void pdata_quirks_check(struct pdata_init *quirks)
{
while (quirks->compatible) {
if (of_machine_is_compatible(quirks->compatible)) {
if (quirks->fn)
quirks->fn();
break;
}
quirks++;
}
}
void __init pdata_quirks_init(struct of_device_id *omap_dt_match_table)
{
omap_sdrc_init(NULL, NULL);
pdata_quirks_check(auxdata_quirks);
of_platform_populate(NULL, omap_dt_match_table,
omap_auxdata_lookup, NULL);
pdata_quirks_check(pdata_quirks);
}
