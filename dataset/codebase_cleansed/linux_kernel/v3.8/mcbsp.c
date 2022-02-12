static void omap1_mcbsp_request(unsigned int id)
{
if (id == 0 || id == 2) {
if (dsp_use++ == 0) {
api_clk = clk_get(NULL, "api_ck");
dsp_clk = clk_get(NULL, "dsp_ck");
if (!IS_ERR(api_clk) && !IS_ERR(dsp_clk)) {
clk_enable(api_clk);
clk_enable(dsp_clk);
__raw_writew(__raw_readw(DSP_RSTCT2) | DPS_RSTCT2_PER_EN |
DSP_RSTCT2_WD_PER_EN, DSP_RSTCT2);
}
}
}
}
static void omap1_mcbsp_free(unsigned int id)
{
if (id == 0 || id == 2) {
if (--dsp_use == 0) {
if (!IS_ERR(api_clk)) {
clk_disable(api_clk);
clk_put(api_clk);
}
if (!IS_ERR(dsp_clk)) {
clk_disable(dsp_clk);
clk_put(dsp_clk);
}
}
}
}
static void omap_mcbsp_register_board_cfg(struct resource *res, int res_count,
struct omap_mcbsp_platform_data *config, int size)
{
int i;
omap_mcbsp_devices = kzalloc(size * sizeof(struct platform_device *),
GFP_KERNEL);
if (!omap_mcbsp_devices) {
printk(KERN_ERR "Could not register McBSP devices\n");
return;
}
for (i = 0; i < size; i++) {
struct platform_device *new_mcbsp;
int ret;
new_mcbsp = platform_device_alloc("omap-mcbsp", i + 1);
if (!new_mcbsp)
continue;
platform_device_add_resources(new_mcbsp, &res[i * res_count],
res_count);
config[i].reg_size = 2;
config[i].reg_step = 2;
new_mcbsp->dev.platform_data = &config[i];
ret = platform_device_add(new_mcbsp);
if (ret) {
platform_device_put(new_mcbsp);
continue;
}
omap_mcbsp_devices[i] = new_mcbsp;
}
}
static int __init omap1_mcbsp_init(void)
{
if (!cpu_class_is_omap1())
return -ENODEV;
if (cpu_is_omap7xx())
omap_mcbsp_register_board_cfg(omap7xx_mcbsp_res_0,
OMAP7XX_MCBSP_RES_SZ,
omap7xx_mcbsp_pdata,
OMAP7XX_MCBSP_COUNT);
if (cpu_is_omap15xx())
omap_mcbsp_register_board_cfg(omap15xx_mcbsp_res_0,
OMAP15XX_MCBSP_RES_SZ,
omap15xx_mcbsp_pdata,
OMAP15XX_MCBSP_COUNT);
if (cpu_is_omap16xx())
omap_mcbsp_register_board_cfg(omap16xx_mcbsp_res_0,
OMAP16XX_MCBSP_RES_SZ,
omap16xx_mcbsp_pdata,
OMAP16XX_MCBSP_COUNT);
return 0;
}
