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
void dss_ctrl_pll_enable(enum dss_pll_id pll_id, bool enable)
{
unsigned shift;
unsigned val;
if (!dss.syscon_pll_ctrl)
return;
val = !enable;
switch (pll_id) {
case DSS_PLL_VIDEO1:
shift = 0;
break;
case DSS_PLL_VIDEO2:
shift = 1;
break;
case DSS_PLL_HDMI:
shift = 2;
break;
default:
DSSERR("illegal DSS PLL ID %d\n", pll_id);
return;
}
regmap_update_bits(dss.syscon_pll_ctrl, dss.syscon_pll_ctrl_offset,
1 << shift, val << shift);
}
void dss_ctrl_pll_set_control_mux(enum dss_pll_id pll_id,
enum omap_channel channel)
{
unsigned shift, val;
if (!dss.syscon_pll_ctrl)
return;
switch (channel) {
case OMAP_DSS_CHANNEL_LCD:
shift = 3;
switch (pll_id) {
case DSS_PLL_VIDEO1:
val = 0; break;
case DSS_PLL_HDMI:
val = 1; break;
default:
DSSERR("error in PLL mux config for LCD\n");
return;
}
break;
case OMAP_DSS_CHANNEL_LCD2:
shift = 5;
switch (pll_id) {
case DSS_PLL_VIDEO1:
val = 0; break;
case DSS_PLL_VIDEO2:
val = 1; break;
case DSS_PLL_HDMI:
val = 2; break;
default:
DSSERR("error in PLL mux config for LCD2\n");
return;
}
break;
case OMAP_DSS_CHANNEL_LCD3:
shift = 7;
switch (pll_id) {
case DSS_PLL_VIDEO1:
val = 1; break;
case DSS_PLL_VIDEO2:
val = 0; break;
case DSS_PLL_HDMI:
val = 2; break;
default:
DSSERR("error in PLL mux config for LCD3\n");
return;
}
break;
default:
DSSERR("error in PLL mux config\n");
return;
}
regmap_update_bits(dss.syscon_pll_ctrl, dss.syscon_pll_ctrl_offset,
0x3 << shift, val << shift);
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
const char *fclk_name, *fclk_real_name;
unsigned long fclk_rate;
if (dss_runtime_get())
return;
seq_printf(s, "- DSS -\n");
fclk_name = dss_get_generic_clk_source_name(OMAP_DSS_CLK_SRC_FCK);
fclk_real_name = dss_feat_get_clk_source_name(OMAP_DSS_CLK_SRC_FCK);
fclk_rate = clk_get_rate(dss.dss_clk);
seq_printf(s, "%s (%s) = %lu\n",
fclk_name, fclk_real_name,
fclk_rate);
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
int b;
u8 start, end;
switch (clk_src) {
case OMAP_DSS_CLK_SRC_FCK:
b = 0;
break;
case OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DISPC:
b = 1;
break;
case OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DISPC:
b = 2;
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
int b, pos;
switch (clk_src) {
case OMAP_DSS_CLK_SRC_FCK:
b = 0;
break;
case OMAP_DSS_CLK_SRC_DSI_PLL_HSDIV_DSI:
BUG_ON(dsi_module != 0);
b = 1;
break;
case OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DSI:
BUG_ON(dsi_module != 1);
b = 1;
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
break;
case OMAP_DSS_CLK_SRC_DSI2_PLL_HSDIV_DISPC:
BUG_ON(channel != OMAP_DSS_CHANNEL_LCD2 &&
channel != OMAP_DSS_CHANNEL_LCD3);
b = 1;
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
bool dss_div_calc(unsigned long pck, unsigned long fck_min,
dss_div_calc_func func, void *data)
{
int fckd, fckd_start, fckd_stop;
unsigned long fck;
unsigned long fck_hw_max;
unsigned long fckd_hw_max;
unsigned long prate;
unsigned m;
fck_hw_max = dss_feat_get_param_max(FEAT_PARAM_DSS_FCK);
if (dss.parent_clk == NULL) {
unsigned pckd;
pckd = fck_hw_max / pck;
fck = pck * pckd;
fck = clk_round_rate(dss.dss_clk, fck);
return func(fck, data);
}
fckd_hw_max = dss.feat->fck_div_max;
m = dss.feat->dss_fck_multiplier;
prate = clk_get_rate(dss.parent_clk);
fck_min = fck_min ? fck_min : 1;
fckd_start = min(prate * m / fck_min, fckd_hw_max);
fckd_stop = max(DIV_ROUND_UP(prate * m, fck_hw_max), 1ul);
for (fckd = fckd_start; fckd >= fckd_stop; --fckd) {
fck = DIV_ROUND_UP(prate, fckd) * m;
if (func(fck, data))
return true;
}
return false;
}
int dss_set_fck_rate(unsigned long rate)
{
int r;
DSSDBG("set fck to %lu\n", rate);
r = clk_set_rate(dss.dss_clk, rate);
if (r)
return r;
dss.dss_clk_rate = clk_get_rate(dss.dss_clk);
WARN_ONCE(dss.dss_clk_rate != rate,
"clk rate mismatch: %lu != %lu", dss.dss_clk_rate,
rate);
return 0;
}
unsigned long dss_get_dispc_clk_rate(void)
{
return dss.dss_clk_rate;
}
static int dss_setup_default_clock(void)
{
unsigned long max_dss_fck, prate;
unsigned long fck;
unsigned fck_div;
int r;
max_dss_fck = dss_feat_get_param_max(FEAT_PARAM_DSS_FCK);
if (dss.parent_clk == NULL) {
fck = clk_round_rate(dss.dss_clk, max_dss_fck);
} else {
prate = clk_get_rate(dss.parent_clk);
fck_div = DIV_ROUND_UP(prate * dss.feat->dss_fck_multiplier,
max_dss_fck);
fck = DIV_ROUND_UP(prate, fck_div) * dss.feat->dss_fck_multiplier;
}
r = dss_set_fck_rate(fck);
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
static int dss_dpi_select_source_omap2_omap3(int port, enum omap_channel channel)
{
if (channel != OMAP_DSS_CHANNEL_LCD)
return -EINVAL;
return 0;
}
static int dss_dpi_select_source_omap4(int port, enum omap_channel channel)
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
static int dss_dpi_select_source_omap5(int port, enum omap_channel channel)
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
static int dss_dpi_select_source_dra7xx(int port, enum omap_channel channel)
{
switch (port) {
case 0:
return dss_dpi_select_source_omap5(port, channel);
case 1:
if (channel != OMAP_DSS_CHANNEL_LCD2)
return -EINVAL;
break;
case 2:
if (channel != OMAP_DSS_CHANNEL_LCD3)
return -EINVAL;
break;
default:
return -EINVAL;
}
return 0;
}
int dss_dpi_select_source(int port, enum omap_channel channel)
{
return dss.feat->dpi_select_source(port, channel);
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
if (dss.feat->parent_clk_name) {
clk = clk_get(NULL, dss.feat->parent_clk_name);
if (IS_ERR(clk)) {
DSSERR("Failed to get %s\n", dss.feat->parent_clk_name);
return PTR_ERR(clk);
}
} else {
clk = NULL;
}
dss.parent_clk = clk;
return 0;
}
static void dss_put_clocks(void)
{
if (dss.parent_clk)
clk_put(dss.parent_clk);
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
case OMAPDSS_VER_AM43xx:
src = &am43xx_dss_feats;
break;
case OMAPDSS_VER_DRA7xx:
src = &dra7xx_dss_feats;
break;
default:
return -ENODEV;
}
memcpy(dst, src, sizeof(*dst));
dss.feat = dst;
return 0;
}
static int __init dss_init_ports(struct platform_device *pdev)
{
struct device_node *parent = pdev->dev.of_node;
struct device_node *port;
int r;
if (parent == NULL)
return 0;
port = omapdss_of_get_next_port(parent, NULL);
if (!port)
return 0;
if (dss.feat->num_ports == 0)
return 0;
do {
enum omap_display_type port_type;
u32 reg;
r = of_property_read_u32(port, "reg", &reg);
if (r)
reg = 0;
if (reg >= dss.feat->num_ports)
continue;
port_type = dss.feat->ports[reg];
switch (port_type) {
case OMAP_DISPLAY_TYPE_DPI:
dpi_init_port(pdev, port);
break;
case OMAP_DISPLAY_TYPE_SDI:
sdi_init_port(pdev, port);
break;
default:
break;
}
} while ((port = omapdss_of_get_next_port(parent, port)) != NULL);
return 0;
}
static void __exit dss_uninit_ports(struct platform_device *pdev)
{
struct device_node *parent = pdev->dev.of_node;
struct device_node *port;
if (parent == NULL)
return;
port = omapdss_of_get_next_port(parent, NULL);
if (!port)
return;
if (dss.feat->num_ports == 0)
return;
do {
enum omap_display_type port_type;
u32 reg;
int r;
r = of_property_read_u32(port, "reg", &reg);
if (r)
reg = 0;
if (reg >= dss.feat->num_ports)
continue;
port_type = dss.feat->ports[reg];
switch (port_type) {
case OMAP_DISPLAY_TYPE_DPI:
dpi_uninit_port(port);
break;
case OMAP_DISPLAY_TYPE_SDI:
sdi_uninit_port(port);
break;
default:
break;
}
} while ((port = omapdss_of_get_next_port(parent, port)) != NULL);
}
static int __init omap_dsshw_probe(struct platform_device *pdev)
{
struct resource *dss_mem;
struct device_node *np = pdev->dev.of_node;
u32 rev;
int r;
struct regulator *pll_regulator;
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
dss_init_ports(pdev);
if (np && of_property_read_bool(np, "syscon-pll-ctrl")) {
dss.syscon_pll_ctrl = syscon_regmap_lookup_by_phandle(np,
"syscon-pll-ctrl");
if (IS_ERR(dss.syscon_pll_ctrl)) {
dev_err(&pdev->dev,
"failed to get syscon-pll-ctrl regmap\n");
return PTR_ERR(dss.syscon_pll_ctrl);
}
if (of_property_read_u32_index(np, "syscon-pll-ctrl", 1,
&dss.syscon_pll_ctrl_offset)) {
dev_err(&pdev->dev,
"failed to get syscon-pll-ctrl offset\n");
return -EINVAL;
}
}
pll_regulator = devm_regulator_get(&pdev->dev, "vdda_video");
if (IS_ERR(pll_regulator)) {
r = PTR_ERR(pll_regulator);
switch (r) {
case -ENOENT:
pll_regulator = NULL;
break;
case -EPROBE_DEFER:
return -EPROBE_DEFER;
default:
DSSERR("can't get DPLL VDDA regulator\n");
return r;
}
}
if (of_property_match_string(np, "reg-names", "pll1") >= 0) {
dss.video1_pll = dss_video_pll_init(pdev, 0, pll_regulator);
if (IS_ERR(dss.video1_pll)) {
r = PTR_ERR(dss.video1_pll);
goto err_pll_init;
}
}
if (of_property_match_string(np, "reg-names", "pll2") >= 0) {
dss.video2_pll = dss_video_pll_init(pdev, 1, pll_regulator);
if (IS_ERR(dss.video2_pll)) {
r = PTR_ERR(dss.video2_pll);
goto err_pll_init;
}
}
rev = dss_read_reg(DSS_REVISION);
printk(KERN_INFO "OMAP DSS rev %d.%d\n",
FLD_GET(rev, 7, 4), FLD_GET(rev, 3, 0));
dss_runtime_put();
dss_debugfs_create_file("dss", dss_dump_regs);
pm_set_vt_switch(0);
return 0;
err_pll_init:
if (dss.video1_pll)
dss_video_pll_uninit(dss.video1_pll);
if (dss.video2_pll)
dss_video_pll_uninit(dss.video2_pll);
err_runtime_get:
pm_runtime_disable(&pdev->dev);
err_setup_clocks:
dss_put_clocks();
return r;
}
static int __exit omap_dsshw_remove(struct platform_device *pdev)
{
if (dss.video1_pll)
dss_video_pll_uninit(dss.video1_pll);
if (dss.video2_pll)
dss_video_pll_uninit(dss.video2_pll);
dss_uninit_ports(pdev);
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
