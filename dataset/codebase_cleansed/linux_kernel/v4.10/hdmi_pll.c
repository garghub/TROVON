void hdmi_pll_dump(struct hdmi_pll_data *pll, struct seq_file *s)
{
#define DUMPPLL(r) seq_printf(s, "%-35s %08x\n", #r,\
hdmi_read_reg(pll->base, r))
DUMPPLL(PLLCTRL_PLL_CONTROL);
DUMPPLL(PLLCTRL_PLL_STATUS);
DUMPPLL(PLLCTRL_PLL_GO);
DUMPPLL(PLLCTRL_CFG1);
DUMPPLL(PLLCTRL_CFG2);
DUMPPLL(PLLCTRL_CFG3);
DUMPPLL(PLLCTRL_SSC_CFG1);
DUMPPLL(PLLCTRL_SSC_CFG2);
DUMPPLL(PLLCTRL_CFG4);
}
static int hdmi_pll_enable(struct dss_pll *dsspll)
{
struct hdmi_pll_data *pll = container_of(dsspll, struct hdmi_pll_data, pll);
struct hdmi_wp_data *wp = pll->wp;
int r;
r = pm_runtime_get_sync(&pll->pdev->dev);
WARN_ON(r < 0);
dss_ctrl_pll_enable(DSS_PLL_HDMI, true);
r = hdmi_wp_set_pll_pwr(wp, HDMI_PLLPWRCMD_BOTHON_ALLCLKS);
if (r)
return r;
return 0;
}
static void hdmi_pll_disable(struct dss_pll *dsspll)
{
struct hdmi_pll_data *pll = container_of(dsspll, struct hdmi_pll_data, pll);
struct hdmi_wp_data *wp = pll->wp;
int r;
hdmi_wp_set_pll_pwr(wp, HDMI_PLLPWRCMD_ALLOFF);
dss_ctrl_pll_enable(DSS_PLL_HDMI, false);
r = pm_runtime_put_sync(&pll->pdev->dev);
WARN_ON(r < 0 && r != -ENOSYS);
}
static int dsi_init_pll_data(struct platform_device *pdev, struct hdmi_pll_data *hpll)
{
struct dss_pll *pll = &hpll->pll;
struct clk *clk;
int r;
clk = devm_clk_get(&pdev->dev, "sys_clk");
if (IS_ERR(clk)) {
DSSERR("can't get sys_clk\n");
return PTR_ERR(clk);
}
pll->name = "hdmi";
pll->id = DSS_PLL_HDMI;
pll->base = hpll->base;
pll->clkin = clk;
switch (omapdss_get_version()) {
case OMAPDSS_VER_OMAP4430_ES1:
case OMAPDSS_VER_OMAP4430_ES2:
case OMAPDSS_VER_OMAP4:
pll->hw = &dss_omap4_hdmi_pll_hw;
break;
case OMAPDSS_VER_OMAP5:
case OMAPDSS_VER_DRA7xx:
pll->hw = &dss_omap5_hdmi_pll_hw;
break;
default:
return -ENODEV;
}
pll->ops = &dsi_pll_ops;
r = dss_pll_register(pll);
if (r)
return r;
return 0;
}
int hdmi_pll_init(struct platform_device *pdev, struct hdmi_pll_data *pll,
struct hdmi_wp_data *wp)
{
int r;
struct resource *res;
pll->pdev = pdev;
pll->wp = wp;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "pll");
if (!res) {
DSSERR("can't get PLL mem resource\n");
return -EINVAL;
}
pll->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pll->base)) {
DSSERR("can't ioremap PLLCTRL\n");
return PTR_ERR(pll->base);
}
r = dsi_init_pll_data(pdev, pll);
if (r) {
DSSERR("failed to init HDMI PLL\n");
return r;
}
return 0;
}
void hdmi_pll_uninit(struct hdmi_pll_data *hpll)
{
struct dss_pll *pll = &hpll->pll;
dss_pll_unregister(pll);
}
