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
void dss_sdi_init(u8 datapairs)
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
if (cpu_is_omap3630() || cpu_is_omap44xx())
seq_printf(s, "%s (%s) = %lu / %lu = %lu\n",
fclk_name, fclk_real_name,
dpll4_ck_rate,
dpll4_ck_rate / dpll4_m4_ck_rate,
fclk_rate);
else
seq_printf(s, "%s (%s) = %lu / %lu * 2 = %lu\n",
fclk_name, fclk_real_name,
dpll4_ck_rate,
dpll4_ck_rate / dpll4_m4_ck_rate,
fclk_rate);
} else {
seq_printf(s, "%s (%s) = %lu\n",
fclk_name, fclk_real_name,
fclk_rate);
}
dss_runtime_put();
}
void dss_dump_regs(struct seq_file *s)
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
void dss_select_dispc_clk_source(enum omap_dss_clk_source clk_src)
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
}
dss_feat_get_reg_field(FEAT_REG_DISPC_CLK_SWITCH, &start, &end);
REG_FLD_MOD(DSS_CONTROL, b, start, end);
dss.dispc_clk_source = clk_src;
}
void dss_select_dsi_clk_source(int dsi_module,
enum omap_dss_clk_source clk_src)
{
struct platform_device *dsidev;
int b;
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
}
REG_FLD_MOD(DSS_CONTROL, b, 1, 1);
dss.dsi_clk_source[dsi_module] = clk_src;
}
void dss_select_lcd_clk_source(enum omap_channel channel,
enum omap_dss_clk_source clk_src)
{
struct platform_device *dsidev;
int b, ix, pos;
if (!dss_has_feature(FEAT_LCD_CLK_SRC))
return;
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
BUG_ON(channel != OMAP_DSS_CHANNEL_LCD2);
b = 1;
dsidev = dsi_get_dsidev_from_id(1);
dsi_wait_pll_hsdiv_dispc_active(dsidev);
break;
default:
BUG();
}
pos = channel == OMAP_DSS_CHANNEL_LCD ? 0 : 12;
REG_FLD_MOD(DSS_CONTROL, b, pos, pos);
ix = channel == OMAP_DSS_CHANNEL_LCD ? 0 : 1;
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
int ix = channel == OMAP_DSS_CHANNEL_LCD ? 0 : 1;
return dss.lcd_clk_source[ix];
} else {
return dss.dispc_clk_source;
}
}
int dss_calc_clock_rates(struct dss_clock_info *cinfo)
{
if (dss.dpll4_m4_ck) {
unsigned long prate;
u16 fck_div_max = 16;
if (cpu_is_omap3630() || cpu_is_omap44xx())
fck_div_max = 32;
if (cinfo->fck_div > fck_div_max || cinfo->fck_div == 0)
return -EINVAL;
prate = clk_get_rate(clk_get_parent(dss.dpll4_m4_ck));
cinfo->fck = prate / cinfo->fck_div;
} else {
if (cinfo->fck_div != 0)
return -EINVAL;
cinfo->fck = clk_get_rate(dss.dss_clk);
}
return 0;
}
int dss_set_clock_div(struct dss_clock_info *cinfo)
{
if (dss.dpll4_m4_ck) {
unsigned long prate;
int r;
prate = clk_get_rate(clk_get_parent(dss.dpll4_m4_ck));
DSSDBG("dpll4_m4 = %ld\n", prate);
r = clk_set_rate(dss.dpll4_m4_ck, prate / cinfo->fck_div);
if (r)
return r;
} else {
if (cinfo->fck_div != 0)
return -EINVAL;
}
DSSDBG("fck = %ld (%d)\n", cinfo->fck, cinfo->fck_div);
return 0;
}
int dss_get_clock_div(struct dss_clock_info *cinfo)
{
cinfo->fck = clk_get_rate(dss.dss_clk);
if (dss.dpll4_m4_ck) {
unsigned long prate;
prate = clk_get_rate(clk_get_parent(dss.dpll4_m4_ck));
if (cpu_is_omap3630() || cpu_is_omap44xx())
cinfo->fck_div = prate / (cinfo->fck);
else
cinfo->fck_div = prate / (cinfo->fck / 2);
} else {
cinfo->fck_div = 0;
}
return 0;
}
unsigned long dss_get_dpll4_rate(void)
{
if (dss.dpll4_m4_ck)
return clk_get_rate(clk_get_parent(dss.dpll4_m4_ck));
else
return 0;
}
int dss_calc_clock_div(bool is_tft, unsigned long req_pck,
struct dss_clock_info *dss_cinfo,
struct dispc_clock_info *dispc_cinfo)
{
unsigned long prate;
struct dss_clock_info best_dss;
struct dispc_clock_info best_dispc;
unsigned long fck, max_dss_fck;
u16 fck_div, fck_div_max = 16;
int match = 0;
int min_fck_per_pck;
prate = dss_get_dpll4_rate();
max_dss_fck = dss_feat_get_param_max(FEAT_PARAM_DSS_FCK);
fck = clk_get_rate(dss.dss_clk);
if (req_pck == dss.cache_req_pck &&
((cpu_is_omap34xx() && prate == dss.cache_prate) ||
dss.cache_dss_cinfo.fck == fck)) {
DSSDBG("dispc clock info found from cache.\n");
*dss_cinfo = dss.cache_dss_cinfo;
*dispc_cinfo = dss.cache_dispc_cinfo;
return 0;
}
min_fck_per_pck = CONFIG_OMAP2_DSS_MIN_FCK_PER_PCK;
if (min_fck_per_pck &&
req_pck * min_fck_per_pck > max_dss_fck) {
DSSERR("Requested pixel clock not possible with the current "
"OMAP2_DSS_MIN_FCK_PER_PCK setting. Turning "
"the constraint off.\n");
min_fck_per_pck = 0;
}
retry:
memset(&best_dss, 0, sizeof(best_dss));
memset(&best_dispc, 0, sizeof(best_dispc));
if (dss.dpll4_m4_ck == NULL) {
struct dispc_clock_info cur_dispc;
fck = clk_get_rate(dss.dss_clk);
fck_div = 1;
dispc_find_clk_divs(is_tft, req_pck, fck, &cur_dispc);
match = 1;
best_dss.fck = fck;
best_dss.fck_div = fck_div;
best_dispc = cur_dispc;
goto found;
} else {
if (cpu_is_omap3630() || cpu_is_omap44xx())
fck_div_max = 32;
for (fck_div = fck_div_max; fck_div > 0; --fck_div) {
struct dispc_clock_info cur_dispc;
if (fck_div_max == 32)
fck = prate / fck_div;
else
fck = prate / fck_div * 2;
if (fck > max_dss_fck)
continue;
if (min_fck_per_pck &&
fck < req_pck * min_fck_per_pck)
continue;
match = 1;
dispc_find_clk_divs(is_tft, req_pck, fck, &cur_dispc);
if (abs(cur_dispc.pck - req_pck) <
abs(best_dispc.pck - req_pck)) {
best_dss.fck = fck;
best_dss.fck_div = fck_div;
best_dispc = cur_dispc;
if (cur_dispc.pck == req_pck)
goto found;
}
}
}
found:
if (!match) {
if (min_fck_per_pck) {
DSSERR("Could not find suitable clock settings.\n"
"Turning FCK/PCK constraint off and"
"trying again.\n");
min_fck_per_pck = 0;
goto retry;
}
DSSERR("Could not find suitable clock settings.\n");
return -EINVAL;
}
if (dss_cinfo)
*dss_cinfo = best_dss;
if (dispc_cinfo)
*dispc_cinfo = best_dispc;
dss.cache_req_pck = req_pck;
dss.cache_prate = prate;
dss.cache_dss_cinfo = best_dss;
dss.cache_dispc_cinfo = best_dispc;
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
void dss_select_hdmi_venc_clk_source(enum dss_hdmi_venc_clk_source_select hdmi)
{
REG_FLD_MOD(DSS_CONTROL, hdmi, 15, 15);
}
static int dss_get_clocks(void)
{
struct clk *clk;
int r;
clk = clk_get(&dss.pdev->dev, "fck");
if (IS_ERR(clk)) {
DSSERR("can't get clock fck\n");
r = PTR_ERR(clk);
goto err;
}
dss.dss_clk = clk;
if (cpu_is_omap34xx()) {
clk = clk_get(NULL, "dpll4_m4_ck");
if (IS_ERR(clk)) {
DSSERR("Failed to get dpll4_m4_ck\n");
r = PTR_ERR(clk);
goto err;
}
} else if (cpu_is_omap44xx()) {
clk = clk_get(NULL, "dpll_per_m5x2_ck");
if (IS_ERR(clk)) {
DSSERR("Failed to get dpll_per_m5x2_ck\n");
r = PTR_ERR(clk);
goto err;
}
} else {
clk = NULL;
}
dss.dpll4_m4_ck = clk;
return 0;
err:
if (dss.dss_clk)
clk_put(dss.dss_clk);
if (dss.dpll4_m4_ck)
clk_put(dss.dpll4_m4_ck);
return r;
}
static void dss_put_clocks(void)
{
if (dss.dpll4_m4_ck)
clk_put(dss.dpll4_m4_ck);
clk_put(dss.dss_clk);
}
struct clk *dss_get_ick(void)
{
return clk_get(&dss.pdev->dev, "ick");
}
int dss_runtime_get(void)
{
int r;
DSSDBG("dss_runtime_get\n");
r = pm_runtime_get_sync(&dss.pdev->dev);
WARN_ON(r < 0);
return r < 0 ? r : 0;
}
void dss_runtime_put(void)
{
int r;
DSSDBG("dss_runtime_put\n");
r = pm_runtime_put(&dss.pdev->dev);
WARN_ON(r < 0);
}
void dss_debug_dump_clocks(struct seq_file *s)
{
dss_dump_clocks(s);
dispc_dump_clocks(s);
#ifdef CONFIG_OMAP2_DSS_DSI
dsi_dump_clocks(s);
#endif
}
static int omap_dsshw_probe(struct platform_device *pdev)
{
struct resource *dss_mem;
u32 rev;
int r;
dss.pdev = pdev;
dss_mem = platform_get_resource(dss.pdev, IORESOURCE_MEM, 0);
if (!dss_mem) {
DSSERR("can't get IORESOURCE_MEM DSS\n");
r = -EINVAL;
goto err_ioremap;
}
dss.base = ioremap(dss_mem->start, resource_size(dss_mem));
if (!dss.base) {
DSSERR("can't ioremap DSS\n");
r = -ENOMEM;
goto err_ioremap;
}
r = dss_get_clocks();
if (r)
goto err_clocks;
pm_runtime_enable(&pdev->dev);
r = dss_runtime_get();
if (r)
goto err_runtime_get;
REG_FLD_MOD(DSS_CONTROL, 0, 0, 0);
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
r = dpi_init();
if (r) {
DSSERR("Failed to initialize DPI\n");
goto err_dpi;
}
r = sdi_init();
if (r) {
DSSERR("Failed to initialize SDI\n");
goto err_sdi;
}
rev = dss_read_reg(DSS_REVISION);
printk(KERN_INFO "OMAP DSS rev %d.%d\n",
FLD_GET(rev, 7, 4), FLD_GET(rev, 3, 0));
dss_runtime_put();
return 0;
err_sdi:
dpi_exit();
err_dpi:
dss_runtime_put();
err_runtime_get:
pm_runtime_disable(&pdev->dev);
dss_put_clocks();
err_clocks:
iounmap(dss.base);
err_ioremap:
return r;
}
static int omap_dsshw_remove(struct platform_device *pdev)
{
dpi_exit();
sdi_exit();
iounmap(dss.base);
pm_runtime_disable(&pdev->dev);
dss_put_clocks();
return 0;
}
static int dss_runtime_suspend(struct device *dev)
{
dss_save_context();
clk_disable(dss.dss_clk);
return 0;
}
static int dss_runtime_resume(struct device *dev)
{
clk_enable(dss.dss_clk);
dss_restore_context();
return 0;
}
int dss_init_platform_driver(void)
{
return platform_driver_register(&omap_dsshw_driver);
}
void dss_uninit_platform_driver(void)
{
return platform_driver_unregister(&omap_dsshw_driver);
}
