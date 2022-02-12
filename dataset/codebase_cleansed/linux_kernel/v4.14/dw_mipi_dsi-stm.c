static inline void dsi_write(struct dw_mipi_dsi_stm *dsi, u32 reg, u32 val)
{
writel(val, dsi->base + reg);
}
static inline u32 dsi_read(struct dw_mipi_dsi_stm *dsi, u32 reg)
{
return readl(dsi->base + reg);
}
static inline void dsi_set(struct dw_mipi_dsi_stm *dsi, u32 reg, u32 mask)
{
dsi_write(dsi, reg, dsi_read(dsi, reg) | mask);
}
static inline void dsi_clear(struct dw_mipi_dsi_stm *dsi, u32 reg, u32 mask)
{
dsi_write(dsi, reg, dsi_read(dsi, reg) & ~mask);
}
static inline void dsi_update_bits(struct dw_mipi_dsi_stm *dsi, u32 reg,
u32 mask, u32 val)
{
dsi_write(dsi, reg, (dsi_read(dsi, reg) & ~mask) | val);
}
static enum dsi_color dsi_color_from_mipi(enum mipi_dsi_pixel_format fmt)
{
switch (fmt) {
case MIPI_DSI_FMT_RGB888:
return DSI_RGB888;
case MIPI_DSI_FMT_RGB666:
return DSI_RGB666_CONF2;
case MIPI_DSI_FMT_RGB666_PACKED:
return DSI_RGB666_CONF1;
case MIPI_DSI_FMT_RGB565:
return DSI_RGB565_CONF1;
default:
DRM_DEBUG_DRIVER("MIPI color invalid, so we use rgb888\n");
}
return DSI_RGB888;
}
static int dsi_pll_get_clkout_khz(int clkin_khz, int idf, int ndiv, int odf)
{
if (idf * odf)
return DIV_ROUND_CLOSEST(clkin_khz * ndiv, idf * odf);
return 0;
}
static int dsi_pll_get_params(int clkin_khz, int clkout_khz,
int *idf, int *ndiv, int *odf)
{
int i, o, n, n_min, n_max;
int fvco_min, fvco_max, delta, best_delta;
if ((clkin_khz <= 0) || (clkout_khz <= 0))
return -EINVAL;
fvco_min = LANE_MIN_KBPS * 2 * ODF_MAX;
fvco_max = LANE_MAX_KBPS * 2 * ODF_MIN;
best_delta = 1000000;
for (i = IDF_MIN; i <= IDF_MAX; i++) {
n_min = ((fvco_min * i) / (2 * clkin_khz)) + 1;
n_max = (fvco_max * i) / (2 * clkin_khz);
if (n_min >= NDIV_MAX)
break;
if (n_min < NDIV_MIN)
n_min = NDIV_MIN;
if (n_max > NDIV_MAX)
n_max = NDIV_MAX;
for (o = ODF_MIN; o <= ODF_MAX; o *= 2) {
n = DIV_ROUND_CLOSEST(i * o * clkout_khz, clkin_khz);
if ((n < n_min) || (n > n_max))
continue;
delta = dsi_pll_get_clkout_khz(clkin_khz, i, n, o) -
clkout_khz;
if (delta < 0)
delta = -delta;
if (delta < best_delta) {
*idf = i;
*ndiv = n;
*odf = o;
best_delta = delta;
}
if (!delta)
return 0;
}
}
return 0;
}
static int dw_mipi_dsi_phy_init(void *priv_data)
{
struct dw_mipi_dsi_stm *dsi = priv_data;
u32 val;
int ret;
dsi_set(dsi, DSI_WRPCR, WRPCR_REGEN | WRPCR_BGREN);
ret = readl_poll_timeout(dsi->base + DSI_WISR, val, val & WISR_RRS,
SLEEP_US, TIMEOUT_US);
if (ret)
DRM_DEBUG_DRIVER("!TIMEOUT! waiting REGU, let's continue\n");
dsi_set(dsi, DSI_WRPCR, WRPCR_PLLEN);
ret = readl_poll_timeout(dsi->base + DSI_WISR, val, val & WISR_PLLLS,
SLEEP_US, TIMEOUT_US);
if (ret)
DRM_DEBUG_DRIVER("!TIMEOUT! waiting PLL, let's continue\n");
dsi_set(dsi, DSI_WCR, WCR_DSIEN);
return 0;
}
static int
dw_mipi_dsi_get_lane_mbps(void *priv_data, struct drm_display_mode *mode,
unsigned long mode_flags, u32 lanes, u32 format,
unsigned int *lane_mbps)
{
struct dw_mipi_dsi_stm *dsi = priv_data;
unsigned int idf, ndiv, odf, pll_in_khz, pll_out_khz;
int ret, bpp;
u32 val;
pll_in_khz = (unsigned int)(clk_get_rate(dsi->pllref_clk) / 1000);
bpp = mipi_dsi_pixel_format_to_bpp(format);
pll_out_khz = mode->clock * bpp / lanes;
pll_out_khz = (pll_out_khz * 12) / 10;
if (pll_out_khz > LANE_MAX_KBPS) {
pll_out_khz = LANE_MAX_KBPS;
DRM_WARN("Warning max phy mbps is used\n");
}
if (pll_out_khz < LANE_MIN_KBPS) {
pll_out_khz = LANE_MIN_KBPS;
DRM_WARN("Warning min phy mbps is used\n");
}
idf = 0;
ndiv = 0;
odf = 0;
ret = dsi_pll_get_params(pll_in_khz, pll_out_khz, &idf, &ndiv, &odf);
if (ret)
DRM_WARN("Warning dsi_pll_get_params(): bad params\n");
pll_out_khz = dsi_pll_get_clkout_khz(pll_in_khz, idf, ndiv, odf);
dsi_update_bits(dsi, DSI_WRPCR, WRPCR_NDIV | WRPCR_IDF | WRPCR_ODF,
(ndiv << 2) | (idf << 11) | ((ffs(odf) - 1) << 16));
val = 4000000 / pll_out_khz;
dsi_update_bits(dsi, DSI_WPCR0, WPCR0_UIX4, val);
dsi_clear(dsi, DSI_WCFGR, WCFGR_DSIM);
dsi_update_bits(dsi, DSI_WCFGR, WCFGR_COLMUX,
dsi_color_from_mipi(format) << 1);
*lane_mbps = pll_out_khz / 1000;
DRM_DEBUG_DRIVER("pll_in %ukHz pll_out %ukHz lane_mbps %uMHz\n",
pll_in_khz, pll_out_khz, *lane_mbps);
return 0;
}
static int dw_mipi_dsi_stm_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct dw_mipi_dsi_stm *dsi;
struct resource *res;
int ret;
dsi = devm_kzalloc(dev, sizeof(*dsi), GFP_KERNEL);
if (!dsi)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
DRM_ERROR("Unable to get resource\n");
return -ENODEV;
}
dsi->base = devm_ioremap_resource(dev, res);
if (IS_ERR(dsi->base)) {
DRM_ERROR("Unable to get dsi registers\n");
return PTR_ERR(dsi->base);
}
dsi->pllref_clk = devm_clk_get(dev, "ref");
if (IS_ERR(dsi->pllref_clk)) {
ret = PTR_ERR(dsi->pllref_clk);
dev_err(dev, "Unable to get pll reference clock: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(dsi->pllref_clk);
if (ret) {
dev_err(dev, "%s: Failed to enable pllref_clk\n", __func__);
return ret;
}
dw_mipi_dsi_stm_plat_data.base = dsi->base;
dw_mipi_dsi_stm_plat_data.priv_data = dsi;
ret = dw_mipi_dsi_probe(pdev, &dw_mipi_dsi_stm_plat_data);
if (ret) {
DRM_ERROR("Failed to initialize mipi dsi host\n");
clk_disable_unprepare(dsi->pllref_clk);
}
return ret;
}
static int dw_mipi_dsi_stm_remove(struct platform_device *pdev)
{
struct dw_mipi_dsi_stm *dsi = dw_mipi_dsi_stm_plat_data.priv_data;
clk_disable_unprepare(dsi->pllref_clk);
dw_mipi_dsi_remove(pdev);
return 0;
}
