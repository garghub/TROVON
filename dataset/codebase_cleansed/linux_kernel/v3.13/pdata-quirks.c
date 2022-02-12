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
static void __init hsmmc2_internal_input_clk(void)
{
u32 reg;
reg = omap_ctrl_readl(OMAP343X_CONTROL_DEVCONF1);
reg |= OMAP2_MMCSDIO2ADPCLKISEL;
omap_ctrl_writel(reg, OMAP343X_CONTROL_DEVCONF1);
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
void __init pdata_quirks_init(struct of_device_id *omap_dt_match_table)
{
struct pdata_init *quirks = pdata_quirks;
omap_sdrc_init(NULL, NULL);
of_platform_populate(NULL, omap_dt_match_table,
omap_auxdata_lookup, NULL);
while (quirks->compatible) {
if (of_machine_is_compatible(quirks->compatible)) {
if (quirks->fn)
quirks->fn();
break;
}
quirks++;
}
}
