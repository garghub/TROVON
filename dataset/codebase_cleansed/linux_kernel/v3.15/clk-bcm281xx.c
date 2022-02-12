static int __init bcm281xx_root_ccu_clks_setup(struct ccu_data *ccu)
{
struct clk **clks;
size_t count = BCM281XX_ROOT_CCU_CLOCK_COUNT;
clks = kzalloc(count * sizeof(*clks), GFP_KERNEL);
if (!clks) {
pr_err("%s: failed to allocate root clocks\n", __func__);
return -ENOMEM;
}
ccu->data.clks = clks;
ccu->data.clk_num = count;
PERI_CLK_SETUP(clks, ccu, BCM281XX_ROOT_CCU_FRAC_1M, frac_1m);
return 0;
}
static int __init bcm281xx_aon_ccu_clks_setup(struct ccu_data *ccu)
{
struct clk **clks;
size_t count = BCM281XX_AON_CCU_CLOCK_COUNT;
clks = kzalloc(count * sizeof(*clks), GFP_KERNEL);
if (!clks) {
pr_err("%s: failed to allocate aon clocks\n", __func__);
return -ENOMEM;
}
ccu->data.clks = clks;
ccu->data.clk_num = count;
PERI_CLK_SETUP(clks, ccu, BCM281XX_AON_CCU_HUB_TIMER, hub_timer);
PERI_CLK_SETUP(clks, ccu, BCM281XX_AON_CCU_PMU_BSC, pmu_bsc);
PERI_CLK_SETUP(clks, ccu, BCM281XX_AON_CCU_PMU_BSC_VAR, pmu_bsc_var);
return 0;
}
static int __init bcm281xx_hub_ccu_clks_setup(struct ccu_data *ccu)
{
struct clk **clks;
size_t count = BCM281XX_HUB_CCU_CLOCK_COUNT;
clks = kzalloc(count * sizeof(*clks), GFP_KERNEL);
if (!clks) {
pr_err("%s: failed to allocate hub clocks\n", __func__);
return -ENOMEM;
}
ccu->data.clks = clks;
ccu->data.clk_num = count;
PERI_CLK_SETUP(clks, ccu, BCM281XX_HUB_CCU_TMON_1M, tmon_1m);
return 0;
}
static int __init bcm281xx_master_ccu_clks_setup(struct ccu_data *ccu)
{
struct clk **clks;
size_t count = BCM281XX_MASTER_CCU_CLOCK_COUNT;
clks = kzalloc(count * sizeof(*clks), GFP_KERNEL);
if (!clks) {
pr_err("%s: failed to allocate master clocks\n", __func__);
return -ENOMEM;
}
ccu->data.clks = clks;
ccu->data.clk_num = count;
PERI_CLK_SETUP(clks, ccu, BCM281XX_MASTER_CCU_SDIO1, sdio1);
PERI_CLK_SETUP(clks, ccu, BCM281XX_MASTER_CCU_SDIO2, sdio2);
PERI_CLK_SETUP(clks, ccu, BCM281XX_MASTER_CCU_SDIO3, sdio3);
PERI_CLK_SETUP(clks, ccu, BCM281XX_MASTER_CCU_SDIO4, sdio4);
PERI_CLK_SETUP(clks, ccu, BCM281XX_MASTER_CCU_USB_IC, usb_ic);
PERI_CLK_SETUP(clks, ccu, BCM281XX_MASTER_CCU_HSIC2_48M, hsic2_48m);
PERI_CLK_SETUP(clks, ccu, BCM281XX_MASTER_CCU_HSIC2_12M, hsic2_12m);
return 0;
}
static int __init bcm281xx_slave_ccu_clks_setup(struct ccu_data *ccu)
{
struct clk **clks;
size_t count = BCM281XX_SLAVE_CCU_CLOCK_COUNT;
clks = kzalloc(count * sizeof(*clks), GFP_KERNEL);
if (!clks) {
pr_err("%s: failed to allocate slave clocks\n", __func__);
return -ENOMEM;
}
ccu->data.clks = clks;
ccu->data.clk_num = count;
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_UARTB, uartb);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_UARTB2, uartb2);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_UARTB3, uartb3);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_UARTB4, uartb4);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_SSP0, ssp0);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_SSP2, ssp2);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_BSC1, bsc1);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_BSC2, bsc2);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_BSC3, bsc3);
PERI_CLK_SETUP(clks, ccu, BCM281XX_SLAVE_CCU_PWM, pwm);
return 0;
}
static void __init kona_dt_root_ccu_setup(struct device_node *node)
{
kona_dt_ccu_setup(node, bcm281xx_root_ccu_clks_setup);
}
static void __init kona_dt_aon_ccu_setup(struct device_node *node)
{
kona_dt_ccu_setup(node, bcm281xx_aon_ccu_clks_setup);
}
static void __init kona_dt_hub_ccu_setup(struct device_node *node)
{
kona_dt_ccu_setup(node, bcm281xx_hub_ccu_clks_setup);
}
static void __init kona_dt_master_ccu_setup(struct device_node *node)
{
kona_dt_ccu_setup(node, bcm281xx_master_ccu_clks_setup);
}
static void __init kona_dt_slave_ccu_setup(struct device_node *node)
{
kona_dt_ccu_setup(node, bcm281xx_slave_ccu_clks_setup);
}
