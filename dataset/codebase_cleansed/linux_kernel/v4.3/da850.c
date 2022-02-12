static void ehrpwm_tblck_enable(struct clk *clk)
{
u32 val;
val = readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP1_REG));
val |= DA8XX_EHRPWM_TBCLKSYNC;
writel(val, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP1_REG));
}
static void ehrpwm_tblck_disable(struct clk *clk)
{
u32 val;
val = readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP1_REG));
val &= ~DA8XX_EHRPWM_TBCLKSYNC;
writel(val, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP1_REG));
}
static void da850_set_async3_src(int pllnum)
{
struct clk *clk, *newparent = pllnum ? &pll1_sysclk2 : &pll0_sysclk2;
struct clk_lookup *c;
unsigned int v;
int ret;
for (c = da850_clks; c->clk; c++) {
clk = c->clk;
if (clk->flags & DA850_CLK_ASYNC3) {
ret = clk_set_parent(clk, newparent);
WARN(ret, "DA850: unable to re-parent clock %s",
clk->name);
}
}
v = __raw_readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP3_REG));
if (pllnum)
v |= CFGCHIP3_ASYNC3_CLKSRC;
else
v &= ~CFGCHIP3_ASYNC3_CLKSRC;
__raw_writel(v, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP3_REG));
}
static int da850_set_voltage(unsigned int index)
{
struct da850_opp *opp;
if (!cvdd)
return -ENODEV;
opp = (struct da850_opp *) cpufreq_info.freq_table[index].driver_data;
return regulator_set_voltage(cvdd, opp->cvdd_min, opp->cvdd_max);
}
static int da850_regulator_init(void)
{
cvdd = regulator_get(NULL, "cvdd");
if (WARN(IS_ERR(cvdd), "Unable to obtain voltage regulator for CVDD;"
" voltage scaling unsupported\n")) {
return PTR_ERR(cvdd);
}
return 0;
}
int da850_register_cpufreq(char *async_clk)
{
int i;
if (async_clk)
clk_add_alias("async", da850_cpufreq_device.name,
async_clk, NULL);
for (i = 0; i < ARRAY_SIZE(da850_freq_table); i++) {
if (da850_freq_table[i].frequency <= da850_max_speed) {
cpufreq_info.freq_table = &da850_freq_table[i];
break;
}
}
return platform_device_register(&da850_cpufreq_device);
}
static int da850_round_armrate(struct clk *clk, unsigned long rate)
{
int ret = 0, diff;
unsigned int best = (unsigned int) -1;
struct cpufreq_frequency_table *table = cpufreq_info.freq_table;
struct cpufreq_frequency_table *pos;
rate /= 1000;
cpufreq_for_each_entry(pos, table) {
diff = pos->frequency - rate;
if (diff < 0)
diff = -diff;
if (diff < best) {
best = diff;
ret = pos->frequency;
}
}
return ret * 1000;
}
static int da850_set_armrate(struct clk *clk, unsigned long index)
{
struct clk *pllclk = &pll0_clk;
return clk_set_rate(pllclk, index);
}
static int da850_set_pll0rate(struct clk *clk, unsigned long index)
{
unsigned int prediv, mult, postdiv;
struct da850_opp *opp;
struct pll_data *pll = clk->pll_data;
int ret;
opp = (struct da850_opp *) cpufreq_info.freq_table[index].driver_data;
prediv = opp->prediv;
mult = opp->mult;
postdiv = opp->postdiv;
ret = davinci_set_pllrate(pll, prediv, mult, postdiv);
if (WARN_ON(ret))
return ret;
return 0;
}
int __init da850_register_cpufreq(char *async_clk)
{
return 0;
}
static int da850_set_armrate(struct clk *clk, unsigned long rate)
{
return -EINVAL;
}
static int da850_set_pll0rate(struct clk *clk, unsigned long armrate)
{
return -EINVAL;
}
static int da850_round_armrate(struct clk *clk, unsigned long rate)
{
return clk->rate;
}
int __init da850_register_pm(struct platform_device *pdev)
{
int ret;
struct davinci_pm_config *pdata = pdev->dev.platform_data;
ret = davinci_cfg_reg(DA850_RTC_ALARM);
if (ret)
return ret;
pdata->ddr2_ctlr_base = da8xx_get_mem_ctlr();
pdata->deepsleep_reg = DA8XX_SYSCFG1_VIRT(DA8XX_DEEPSLEEP_REG);
pdata->ddrpsc_num = DA8XX_LPSC1_EMIF3C;
pdata->cpupll_reg_base = ioremap(DA8XX_PLL0_BASE, SZ_4K);
if (!pdata->cpupll_reg_base)
return -ENOMEM;
pdata->ddrpll_reg_base = ioremap(DA850_PLL1_BASE, SZ_4K);
if (!pdata->ddrpll_reg_base) {
ret = -ENOMEM;
goto no_ddrpll_mem;
}
pdata->ddrpsc_reg_base = ioremap(DA8XX_PSC1_BASE, SZ_4K);
if (!pdata->ddrpsc_reg_base) {
ret = -ENOMEM;
goto no_ddrpsc_mem;
}
return platform_device_register(pdev);
no_ddrpsc_mem:
iounmap(pdata->ddrpll_reg_base);
no_ddrpll_mem:
iounmap(pdata->cpupll_reg_base);
return ret;
}
int __init da850_register_vpif(void)
{
return platform_device_register(&da850_vpif_dev);
}
int __init da850_register_vpif_display(struct vpif_display_config
*display_config)
{
da850_vpif_display_dev.dev.platform_data = display_config;
return platform_device_register(&da850_vpif_display_dev);
}
int __init da850_register_vpif_capture(struct vpif_capture_config
*capture_config)
{
da850_vpif_capture_dev.dev.platform_data = capture_config;
return platform_device_register(&da850_vpif_capture_dev);
}
int __init da850_register_gpio(void)
{
return da8xx_register_gpio(&da850_gpio_platform_data);
}
void __init da850_init(void)
{
unsigned int v;
davinci_common_init(&davinci_soc_info_da850);
da8xx_syscfg0_base = ioremap(DA8XX_SYSCFG0_BASE, SZ_4K);
if (WARN(!da8xx_syscfg0_base, "Unable to map syscfg0 module"))
return;
da8xx_syscfg1_base = ioremap(DA8XX_SYSCFG1_BASE, SZ_4K);
if (WARN(!da8xx_syscfg1_base, "Unable to map syscfg1 module"))
return;
da850_set_async3_src(1);
v = __raw_readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP0_REG));
v &= ~CFGCHIP0_PLL_MASTER_LOCK;
__raw_writel(v, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP0_REG));
v = __raw_readl(DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP3_REG));
v &= ~CFGCHIP3_PLL1_MASTER_LOCK;
__raw_writel(v, DA8XX_SYSCFG0_VIRT(DA8XX_CFGCHIP3_REG));
}
