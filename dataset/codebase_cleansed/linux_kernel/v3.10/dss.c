static inline void dss_write_reg(const struct dss_reg idx, u32 val)
{
__raw_writel(val, dss.base + idx.idx);
}
static inline u32 dss_read_reg(const struct dss_reg idx)
{
return __raw_readl(dss.base + idx.idx);
}
static void dss_save_context(void)
{
DSSDBG("dss_save_context\n");
SR(CONTROL);
if (dss_feat_get_supported_displays(OMAP_DSS_CHANNEL_LCD) &
OMAP_DISPLAY_TYPE_SDI) {
SR(SDI_CONTROL);
SR(PLL_CONTROL);
}
dss.ctx_valid = true;
DSSDBG("context saved\n");
}
static void dss_restore_context(void)
{
DSSDBG("dss_restore_context\n");
if (!dss.ctx_valid)
return;
RR(CONTROL);
if (dss_feat_get_supported_displays(OMAP_DSS_CHANNEL_LCD) &
OMAP_DISPLAY_TYPE_SDI) {
RR(SDI_CONTROL);
RR(PLL_CONTROL);
}
DSSDBG("context restored\n");
}
int dss_get_ctx_loss_count(void)
{
struct omap_dss_board_info *board_data = dss.pdev->dev.platform_data;
int cnt;
if (!board_data->get_context_loss_count)
return -ENOENT;
cnt = board_data->get_context_loss_count(&dss.pdev->dev);
WARN_ONCE(cnt < 0, "get_context_loss_count failed: %d\n", cnt);
return cnt;
}
void dss_sdi_init(int datapairs)
{
u32 l;
BUG_ON(datapairs > 3 || datapairs < 1);
l = dss_read_reg(DSS_SDI_CONTROL);
l = FLD_MOD(l, 0xf, 19, 15);
l = FLD_MOD(l, datapairs-1, 3, 2);
l = FLD_MOD(l, 2, 1, 0);
dss_write_reg(DSS_SDI_CONTROL, l);
l = dss_read_reg(DSS_PLL_CONTROL);
l = FLD_MOD(l, 0x7, 25, 22);
l = FLD_MOD(l, 0xb, 16, 11);
l = FLD_MOD(l, 0xb4, 10, 1);
dss_write_reg(DSS_PLL_CONTROL, l);
}
int dss_sdi_enable(void)
{
unsigned long timeout;
dispc_pck_free_enable(1);
REG_FLD_MOD(DSS_PLL_CONTROL, 1, 18, 18);
udelay(1);
REG_FLD_MOD(DSS_PLL_CONTROL, 1, 28, 28);
timeout = jiffies + msecs_to_jiffies(500);
while (dss_read_reg(DSS_SDI_STATUS) & (1 << 6)) {
if (time_after_eq(jiffies, timeout)) {
DSSERR("PLL lock request timed out\n");
goto err1;
}
}
REG_FLD_MOD(DSS_PLL_CONTROL, 0, 28, 28);
timeout = jiffies + msecs_to_jiffies(500);
while (!(dss_read_reg(DSS_SDI_STATUS) & (1 << 5))) {
if (time_after_eq(jiffies, timeout)) {
DSSERR("PLL lock timed out\n");
goto err1;
}
}
dispc_lcd_enable_signal(1);
timeout = jiffies + msecs_to_jiffies(500);
while (!(dss_read_reg(DSS_SDI_STATUS) & (1 << 2))) {
if (time_after_eq(jiffies, timeout)) {
DSSERR("SDI reset timed out\n");
goto err2;
}
}
return 0;
err2:
dispc_lcd_enable_signal(0);
err1:
REG_FLD_MOD(DSS_PLL_CONTROL, 0, 18, 18);
dispc_pck_free_enable(0);
return -ETIMEDOUT;
}
void dss_sdi_disable(void)
{
dispc_lcd_enable_signal(0);
dispc_pck_free_enable(0);
REG_FLD_MOD(DSS_PLL_CONTROL, 0, 18, 18);
}
const char *dss_get_generic_clk_source_name(enum omap_dss_clk_source clk_src)
{
return dss_generic_clk_source_names[clk_src];
}
void dss_dump_clocks(struct seq_file *s)
{
unsigned long dpll4_ck_rate;
unsigned long dpll4_m4_ck_rate;
const char *fclk_name, *fclk_real_name;
unsigned long fclk_rate;
if (dss_runtime_get())
return;
seq_printf(s, "- DSS -\n");
fclk_name = dss_get_generic_clk_source_name(OMAP_DSS_CLK_SRC_FCK);
fclk_real_name = dss_feat_get_clk_source_name(OMAP_DSS_CLK_SRC_FCK);
fclk_rate = clk_get_rate(dss.dss_clk);
if (dss.dpll4_m4_ck) {
dpll4_ck_rate = clk_get_rate(clk_get_parent(dss.dpll4_m4_ck));
dpll4_m4_ck_rate = clk_get_rate(dss.dpll4_m4_ck);
seq_printf(s, "dpll4_ck %lu\n", dpll4_ck_rate);
seq_printf(s, "%s (%s) = %lu / %lu * %d = %lu\n",
fclk_name, fclk_real_name, dpll4_ck_rate,
dpll4_ck_rate / dpll4_m4_ck_rate,
dss.feat->dss_fck_multiplier, fclk_rate);
} else {
seq_printf(s, "%s (%s) = %lu\n",
fclk_name, fclk_real_name,
fclk_rate);
}
dss_runtime_put();
}
static void dss_dump_regs(struct seq_file *s)
{
#define DUMPREG(r) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if (dss_runtime_get())
return;
DUMPREG(DSS_REVISION);
DUMPREG(DSS_SYSCONFIG);
DUMPREG(DSS_SYSSTATUS);
DUMPREG(DSS_CONTROL);
if (dss_feat_get_supported_displays(OMAP_DSS_CHANNEL_LCD) &
OMAP_DISPLAY_TYPE_SDI) {
DUMPREG(DSS_SDI_CONTROL);
DUMPREG(DSS_PLL_CONTROL);
DUMPREG(DSS_SDI_STATUS);
}
dss_runtime_put();
#undef DUMPREG
}
static void dss_select_dispc_clk_source(enum omap_dss_clk_source clk_src)
{
struct platform_device *dsidev;
int b;
u8 start, end;
switch (clk_src) {
case OMAP_DSS_CLK_SRC_FCK:
b = 0;
break;
case OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC:
b = 1;
dsidev = dsi_get_dsidev_from_id(0);
dsi_wait_pll_hsdiv_dispc_active(dsidev);
break;
case OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DISPC:
b = 2;
dsidev = dsi_get_dsidev_from_id(1);
dsi_wait_pll_hsdiv_dispc_active(dsidev);
break;
default:
BUG();
return;
}
dss_feat_get_reg_field(FEAT_REG_DISPC_CLK_SWITCH, &start, &end);
REG_FLD_MOD(DSS_CONTROL, b, start, end);
dss.dispc_clk_source = clk_src;
}
void dss_select_dsi_clk_source(int dsi_module,
enum omap_dss_clk_source clk_src)
{
struct platform_device *dsidev;
int b, pos;
switch (clk_src) {
case OMAP_DSS_CLK_SRC_FCK:
b = 0;
break;
case OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI:
BUG_ON(dsi_module != 0);
b = 1;
dsidev = dsi_get_dsidev_from_id(0);
dsi_wait_pll_hsdiv_dsi_active(dsidev);
break;
case OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DSI:
BUG_ON(dsi_module != 1);
b = 1;
dsidev = dsi_get_dsidev_from_id(1);
dsi_wait_pll_hsdiv_dsi_active(dsidev);
break;
default:
BUG();
return;
}
pos = dsi_module == 0 ? 1 : 10;
REG_FLD_MOD(DSS_CONTROL, b, pos, pos);
dss.dsi_clk_source[dsi_module] = clk_src;
}
void dss_select_lcd_clk_source(enum omap_channel channel,
enum omap_dss_clk_source clk_src)
{
struct platform_device *dsidev;
int b, ix, pos;
if (!dss_has_feature(FEAT_LCD_CLK_SRC)) {
dss_select_dispc_clk_source(clk_src);
return;
}
switch (clk_src) {
case OMAP_DSS_CLK_SRC_FCK:
b = 0;
break;
case OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC:
BUG_ON(channel != OMAP_DSS_CHANNEL_LCD);
b = 1;
dsidev = dsi_get_dsidev_from_id(0);
dsi_wait_pll_hsdiv_dispc_active(dsidev);
break;
case OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DISPC:
BUG_ON(channel != OMAP_DSS_CHANNEL_LCD2 &&
channel != OMAP_DSS_CHANNEL_LCD3);
b = 1;
dsidev = dsi_get_dsidev_from_id(1);
dsi_wait_pll_hsdiv_dispc_active(dsidev);
break;
default:
BUG();
return;
}
pos = channel == OMAP_DSS_CHANNEL_LCD ? 0 :
(channel == OMAP_DSS_CHANNEL_LCD2 ? 12 : 19);
REG_FLD_MOD(DSS_CONTROL, b, pos, pos);
ix = channel == OMAP_DSS_CHANNEL_LCD ? 0 :
(channel == OMAP_DSS_CHANNEL_LCD2 ? 1 : 2);
dss.lcd_clk_source[ix] = clk_src;
}
enum omap_dss_clk_source dss_get_dispc_clk_source(void)
{
return dss.dispc_clk_source;
}
enum omap_dss_clk_source dss_get_dsi_clk_source(int dsi_module)
{
return dss.dsi_clk_source[dsi_module];
}
enum omap_dss_clk_source dss_get_lcd_clk_source(enum omap_channel channel)
{
if (dss_has_feature(FEAT_LCD_CLK_SRC)) {
int ix = channel == OMAP_DSS_CHANNEL_LCD ? 0 :
(channel == OMAP_DSS_CHANNEL_LCD2 ? 1 : 2);
return dss.lcd_clk_source[ix];
} else {
return dss.dispc_clk_source;
}
}
int dss_calc_clock_rates(struct dss_clock_info *cinfo)
{
if (dss.dpll4_m4_ck) {
unsigned long prate;
if (cinfo->fck_div > dss.feat->fck_div_max ||
cinfo->fck_div == 0)
return -EINVAL;
prate = clk_get_rate(clk_get_parent(dss.dpll4_m4_ck));
cinfo->fck = prate / cinfo->fck_div *
dss.feat->dss_fck_multiplier;
} else {
if (cinfo->fck_div != 0)
return -EINVAL;
cinfo->fck = clk_get_rate(dss.dss_clk);
}
return 0;
}
bool dss_div_calc(unsigned long fck_min, dss_div_calc_func func, void *data)
{
int fckd, fckd_start, fckd_stop;
unsigned long fck;
unsigned long fck_hw_max;
unsigned long fckd_hw_max;
unsigned long prate;
unsigned m;
if (dss.dpll4_m4_ck == NULL) {
fck = clk_get_rate(dss.dss_clk);
fckd = 1;
return func(fckd, fck, data);
}
fck_hw_max = dss_feat_get_param_max(FEAT_PARAM_DSS_FCK);
fckd_hw_max = dss.feat->fck_div_max;
m = dss.feat->dss_fck_multiplier;
prate = dss_get_dpll4_rate();
fck_min = fck_min ? fck_min : 1;
fckd_start = min(prate * m / fck_min, fckd_hw_max);
fckd_stop = max(DIV_ROUND_UP(prate * m, fck_hw_max), 1ul);
for (fckd = fckd_start; fckd >= fckd_stop; --fckd) {
fck = prate / fckd * m;
if (func(fckd, fck, data))
return true;
}
return false;
}
int dss_set_clock_div(struct dss_clock_info *cinfo)
{
if (dss.dpll4_m4_ck) {
unsigned long prate;
int r;
prate = clk_get_rate(clk_get_parent(dss.dpll4_m4_ck));
DSSDBG("dpll4_m4 = %ld\n", prate);
r = clk_set_rate(dss.dpll4_m4_ck,
DIV_ROUND_UP(prate, cinfo->fck_div));
if (r)
return r;
} else {
if (cinfo->fck_div != 0)
return -EINVAL;
}
dss.dss_clk_rate = clk_get_rate(dss.dss_clk);
WARN_ONCE(dss.dss_clk_rate != cinfo->fck,
"clk rate mismatch: %lu != %lu", dss.dss_clk_rate,
cinfo->fck);
DSSDBG("fck = %ld (%d)\n", cinfo->fck, cinfo->fck_div);
return 0;
}
unsigned long dss_get_dpll4_rate(void)
{
if (dss.dpll4_m4_ck)
return clk_get_rate(clk_get_parent(dss.dpll4_m4_ck));
else
return 0;
}
unsigned long dss_get_dispc_clk_rate(void)
{
return dss.dss_clk_rate;
}
static int dss_setup_default_clock(void)
{
unsigned long max_dss_fck, prate;
unsigned fck_div;
struct dss_clock_info dss_cinfo = { 0 };
int r;
if (dss.dpll4_m4_ck == NULL)
return 0;
max_dss_fck = dss_feat_get_param_max(FEAT_PARAM_DSS_FCK);
prate = dss_get_dpll4_rate();
fck_div = DIV_ROUND_UP(prate * dss.feat->dss_fck_multiplier,
max_dss_fck);
dss_cinfo.fck_div = fck_div;
r = dss_calc_clock_rates(&dss_cinfo);
if (r)
return r;
r = dss_set_clock_div(&dss_cinfo);
if (r)
return r;
return 0;
}
void dss_set_venc_output(enum omap_dss_venc_type type)
{
int l = 0;
if (type == OMAP_DSS_VENC_TYPE_COMPOSITE)
l = 0;
else if (type == OMAP_DSS_VENC_TYPE_SVIDEO)
l = 1;
else
BUG();
REG_FLD_MOD(DSS_CONTROL, l, 6, 6);
}
void dss_set_dac_pwrdn_bgz(bool enable)
{
REG_FLD_MOD(DSS_CONTROL, enable, 5, 5);
}
void dss_select_hdmi_venc_clk_source(enum dss_hdmi_venc_clk_source_select src)
{
enum omap_display_type dp;
dp = dss_feat_get_supported_displays(OMAP_DSS_CHANNEL_DIGIT);
WARN_ON((src == DSS_VENC_TV_CLK) && !(dp & OMAP_DISPLAY_TYPE_VENC));
WARN_ON((src == DSS_HDMI_M_PCLK) && !(dp & OMAP_DISPLAY_TYPE_HDMI));
if ((dp & OMAP_DISPLAY_TYPE_VENC) && (dp & OMAP_DISPLAY_TYPE_HDMI))
REG_FLD_MOD(DSS_CONTROL, src, 15, 15);
}
enum dss_hdmi_venc_clk_source_select dss_get_hdmi_venc_clk_source(void)
{
enum omap_display_type displays;
displays = dss_feat_get_supported_displays(OMAP_DSS_CHANNEL_DIGIT);
if ((displays & OMAP_DISPLAY_TYPE_HDMI) == 0)
return DSS_VENC_TV_CLK;
if ((displays & OMAP_DISPLAY_TYPE_VENC) == 0)
return DSS_HDMI_M_PCLK;
return REG_GET(DSS_CONTROL, 15, 15);
}
static int dss_dpi_select_source_omap2_omap3(enum omap_channel channel)
{
if (channel != OMAP_DSS_CHANNEL_LCD)
return -EINVAL;
return 0;
}
static int dss_dpi_select_source_omap4(enum omap_channel channel)
{
int val;
switch (channel) {
case OMAP_DSS_CHANNEL_LCD2:
val = 0;
break;
case OMAP_DSS_CHANNEL_DIGIT:
val = 1;
break;
default:
return -EINVAL;
}
REG_FLD_MOD(DSS_CONTROL, val, 17, 17);
return 0;
}
static int dss_dpi_select_source_omap5(enum omap_channel channel)
{
int val;
switch (channel) {
case OMAP_DSS_CHANNEL_LCD:
val = 1;
break;
case OMAP_DSS_CHANNEL_LCD2:
val = 2;
break;
case OMAP_DSS_CHANNEL_LCD3:
val = 3;
break;
case OMAP_DSS_CHANNEL_DIGIT:
val = 0;
break;
default:
return -EINVAL;
}
REG_FLD_MOD(DSS_CONTROL, val, 17, 16);
return 0;
}
int dss_dpi_select_source(enum omap_channel channel)
{
return dss.feat->dpi_select_source(channel);
}
static int dss_get_clocks(void)
{
struct clk *clk;
clk = devm_clk_get(&dss.pdev->dev, "fck");
if (IS_ERR(clk)) {
DSSERR("can't get clock fck\n");
return PTR_ERR(clk);
}
dss.dss_clk = clk;
if (dss.feat->clk_name) {
clk = clk_get(NULL, dss.feat->clk_name);
if (IS_ERR(clk)) {
DSSERR("Failed to get %s\n", dss.feat->clk_name);
return PTR_ERR(clk);
}
} else {
clk = NULL;
}
dss.dpll4_m4_ck = clk;
return 0;
}
static void dss_put_clocks(void)
{
if (dss.dpll4_m4_ck)
clk_put(dss.dpll4_m4_ck);
}
static int dss_runtime_get(void)
{
int r;
DSSDBG("dss_runtime_get\n");
r = pm_runtime_get_sync(&dss.pdev->dev);
WARN_ON(r < 0);
return r < 0 ? r : 0;
}
static void dss_runtime_put(void)
{
int r;
DSSDBG("dss_runtime_put\n");
r = pm_runtime_put_sync(&dss.pdev->dev);
WARN_ON(r < 0 && r != -ENOSYS && r != -EBUSY);
}
void dss_debug_dump_clocks(struct seq_file *s)
{
dss_dump_clocks(s);
dispc_dump_clocks(s);
#ifdef CONFIG_OMAP2_DSS_DSI
dsi_dump_clocks(s);
#endif
}
static int __init dss_init_features(struct platform_device *pdev)
{
const struct dss_features *src;
struct dss_features *dst;
dst = devm_kzalloc(&pdev->dev, sizeof(*dst), GFP_KERNEL);
if (!dst) {
dev_err(&pdev->dev, "Failed to allocate local DSS Features\n");
return -ENOMEM;
}
switch (omapdss_get_version()) {
case OMAPDSS_VER_OMAP24xx:
src = &omap24xx_dss_feats;
break;
case OMAPDSS_VER_OMAP34xx_ES1:
case OMAPDSS_VER_OMAP34xx_ES3:
case OMAPDSS_VER_AM35xx:
src = &omap34xx_dss_feats;
break;
case OMAPDSS_VER_OMAP3630:
src = &omap3630_dss_feats;
break;
case OMAPDSS_VER_OMAP4430_ES1:
case OMAPDSS_VER_OMAP4430_ES2:
case OMAPDSS_VER_OMAP4:
src = &omap44xx_dss_feats;
break;
case OMAPDSS_VER_OMAP5:
src = &omap54xx_dss_feats;
break;
default:
return -ENODEV;
}
memcpy(dst, src, sizeof(*dst));
dss.feat = dst;
return 0;
}
static int __init omap_dsshw_probe(struct platform_device *pdev)
{
struct resource *dss_mem;
u32 rev;
int r;
dss.pdev = pdev;
r = dss_init_features(dss.pdev);
if (r)
return r;
dss_mem = platform_get_resource(dss.pdev, IORESOURCE_MEM, 0);
if (!dss_mem) {
DSSERR("can't get IORESOURCE_MEM DSS\n");
return -EINVAL;
}
dss.base = devm_ioremap(&pdev->dev, dss_mem->start,
resource_size(dss_mem));
if (!dss.base) {
DSSERR("can't ioremap DSS\n");
return -ENOMEM;
}
r = dss_get_clocks();
if (r)
return r;
r = dss_setup_default_clock();
if (r)
goto err_setup_clocks;
pm_runtime_enable(&pdev->dev);
r = dss_runtime_get();
if (r)
goto err_runtime_get;
dss.dss_clk_rate = clk_get_rate(dss.dss_clk);
REG_FLD_MOD(DSS_CONTROL, 0, 0, 0);
dss_select_dispc_clk_source(OMAP_DSS_CLK_SRC_FCK);
#ifdef CONFIG_OMAP2_DSS_VENC
REG_FLD_MOD(DSS_CONTROL, 1, 4, 4);
REG_FLD_MOD(DSS_CONTROL, 1, 3, 3);
REG_FLD_MOD(DSS_CONTROL, 0, 2, 2);
#endif
dss.dsi_clk_source[0] = OMAP_DSS_CLK_SRC_FCK;
dss.dsi_clk_source[1] = OMAP_DSS_CLK_SRC_FCK;
dss.dispc_clk_source = OMAP_DSS_CLK_SRC_FCK;
dss.lcd_clk_source[0] = OMAP_DSS_CLK_SRC_FCK;
dss.lcd_clk_source[1] = OMAP_DSS_CLK_SRC_FCK;
rev = dss_read_reg(DSS_REVISION);
printk(KERN_INFO "OMAP DSS rev %d.%d\n",
FLD_GET(rev, 7, 4), FLD_GET(rev, 3, 0));
dss_runtime_put();
dss_debugfs_create_file("dss", dss_dump_regs);
return 0;
err_runtime_get:
pm_runtime_disable(&pdev->dev);
err_setup_clocks:
dss_put_clocks();
return r;
}
static int __exit omap_dsshw_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
dss_put_clocks();
return 0;
}
static int dss_runtime_suspend(struct device *dev)
{
dss_save_context();
dss_set_min_bus_tput(dev, 0);
return 0;
}
static int dss_runtime_resume(struct device *dev)
{
int r;
r = dss_set_min_bus_tput(dev, 1000000000);
if (r)
return r;
dss_restore_context();
return 0;
}
int __init dss_init_platform_driver(void)
{
return platform_driver_probe(&omap_dsshw_driver, omap_dsshw_probe);
}
void dss_uninit_platform_driver(void)
{
platform_driver_unregister(&omap_dsshw_driver);
}
