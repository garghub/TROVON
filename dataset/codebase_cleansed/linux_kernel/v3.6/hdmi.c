static int hdmi_runtime_get(void)
{
int r;
DSSDBG("hdmi_runtime_get\n");
r = pm_runtime_get_sync(&hdmi.pdev->dev);
WARN_ON(r < 0);
if (r < 0)
return r;
return 0;
}
static void hdmi_runtime_put(void)
{
int r;
DSSDBG("hdmi_runtime_put\n");
r = pm_runtime_put_sync(&hdmi.pdev->dev);
WARN_ON(r < 0 && r != -ENOSYS);
}
static int __init hdmi_init_display(struct omap_dss_device *dssdev)
{
DSSDBG("init_display\n");
dss_init_hdmi_ip_ops(&hdmi.ip_data);
return 0;
}
static const struct hdmi_config *hdmi_find_timing(
const struct hdmi_config *timings_arr,
int len)
{
int i;
for (i = 0; i < len; i++) {
if (timings_arr[i].cm.code == hdmi.ip_data.cfg.cm.code)
return &timings_arr[i];
}
return NULL;
}
static const struct hdmi_config *hdmi_get_timings(void)
{
const struct hdmi_config *arr;
int len;
if (hdmi.ip_data.cfg.cm.mode == HDMI_DVI) {
arr = vesa_timings;
len = ARRAY_SIZE(vesa_timings);
} else {
arr = cea_timings;
len = ARRAY_SIZE(cea_timings);
}
return hdmi_find_timing(arr, len);
}
static bool hdmi_timings_compare(struct omap_video_timings *timing1,
const struct omap_video_timings *timing2)
{
int timing1_vsync, timing1_hsync, timing2_vsync, timing2_hsync;
if ((timing2->pixel_clock == timing1->pixel_clock) &&
(timing2->x_res == timing1->x_res) &&
(timing2->y_res == timing1->y_res)) {
timing2_hsync = timing2->hfp + timing2->hsw + timing2->hbp;
timing1_hsync = timing1->hfp + timing1->hsw + timing1->hbp;
timing2_vsync = timing2->vfp + timing2->vsw + timing2->vbp;
timing1_vsync = timing2->vfp + timing2->vsw + timing2->vbp;
DSSDBG("timing1_hsync = %d timing1_vsync = %d"\
"timing2_hsync = %d timing2_vsync = %d\n",
timing1_hsync, timing1_vsync,
timing2_hsync, timing2_vsync);
if ((timing1_hsync == timing2_hsync) &&
(timing1_vsync == timing2_vsync)) {
return true;
}
}
return false;
}
static struct hdmi_cm hdmi_get_code(struct omap_video_timings *timing)
{
int i;
struct hdmi_cm cm = {-1};
DSSDBG("hdmi_get_code\n");
for (i = 0; i < ARRAY_SIZE(cea_timings); i++) {
if (hdmi_timings_compare(timing, &cea_timings[i].timings)) {
cm = cea_timings[i].cm;
goto end;
}
}
for (i = 0; i < ARRAY_SIZE(vesa_timings); i++) {
if (hdmi_timings_compare(timing, &vesa_timings[i].timings)) {
cm = vesa_timings[i].cm;
goto end;
}
}
end: return cm;
}
unsigned long hdmi_get_pixel_clock(void)
{
return hdmi.ip_data.cfg.timings.pixel_clock * 1000;
}
static void hdmi_compute_pll(struct omap_dss_device *dssdev, int phy,
struct hdmi_pll_info *pi)
{
unsigned long clkin, refclk;
u32 mf;
clkin = clk_get_rate(hdmi.sys_clk) / 10000;
if (dssdev->clocks.hdmi.regn == 0)
pi->regn = HDMI_DEFAULT_REGN;
else
pi->regn = dssdev->clocks.hdmi.regn;
refclk = clkin / pi->regn;
if (dssdev->clocks.hdmi.regm2 == 0)
pi->regm2 = HDMI_DEFAULT_REGM2;
else
pi->regm2 = dssdev->clocks.hdmi.regm2;
pi->regm = phy * pi->regm2 / refclk;
mf = (phy - pi->regm / pi->regm2 * refclk) * 262144;
pi->regmf = pi->regm2 * mf / refclk;
pi->dcofreq = phy > 1000 * 100;
pi->regsd = ((pi->regm * clkin / 10) / (pi->regn * 250) + 5) / 10;
pi->refsel = HDMI_REFSEL_SYSCLK;
DSSDBG("M = %d Mf = %d\n", pi->regm, pi->regmf);
DSSDBG("range = %d sd = %d\n", pi->dcofreq, pi->regsd);
}
static int hdmi_power_on(struct omap_dss_device *dssdev)
{
int r;
const struct hdmi_config *timing;
struct omap_video_timings *p;
unsigned long phy;
r = hdmi_runtime_get();
if (r)
return r;
dss_mgr_disable(dssdev->manager);
p = &dssdev->panel.timings;
DSSDBG("hdmi_power_on x_res= %d y_res = %d\n",
dssdev->panel.timings.x_res,
dssdev->panel.timings.y_res);
timing = hdmi_get_timings();
if (timing == NULL) {
hdmi.ip_data.cfg.cm.code = 4;
hdmi.ip_data.cfg.cm.mode = HDMI_DVI;
hdmi.ip_data.cfg = vesa_timings[0];
} else {
hdmi.ip_data.cfg = *timing;
}
phy = p->pixel_clock;
hdmi_compute_pll(dssdev, phy, &hdmi.ip_data.pll_data);
hdmi.ip_data.ops->video_disable(&hdmi.ip_data);
r = hdmi.ip_data.ops->pll_enable(&hdmi.ip_data);
if (r) {
DSSDBG("Failed to lock PLL\n");
goto err;
}
r = hdmi.ip_data.ops->phy_enable(&hdmi.ip_data);
if (r) {
DSSDBG("Failed to start PHY\n");
goto err;
}
hdmi.ip_data.ops->video_configure(&hdmi.ip_data);
dss_select_hdmi_venc_clk_source(DSS_HDMI_M_PCLK);
dss_select_dispc_clk_source(dssdev->clocks.dispc.dispc_fclk_src);
dispc_enable_gamma_table(0);
dss_mgr_set_timings(dssdev->manager, &dssdev->panel.timings);
r = hdmi.ip_data.ops->video_enable(&hdmi.ip_data);
if (r)
goto err_vid_enable;
r = dss_mgr_enable(dssdev->manager);
if (r)
goto err_mgr_enable;
return 0;
err_mgr_enable:
hdmi.ip_data.ops->video_disable(&hdmi.ip_data);
err_vid_enable:
hdmi.ip_data.ops->phy_disable(&hdmi.ip_data);
hdmi.ip_data.ops->pll_disable(&hdmi.ip_data);
err:
hdmi_runtime_put();
return -EIO;
}
static void hdmi_power_off(struct omap_dss_device *dssdev)
{
dss_mgr_disable(dssdev->manager);
hdmi.ip_data.ops->video_disable(&hdmi.ip_data);
hdmi.ip_data.ops->phy_disable(&hdmi.ip_data);
hdmi.ip_data.ops->pll_disable(&hdmi.ip_data);
hdmi_runtime_put();
}
int omapdss_hdmi_display_check_timing(struct omap_dss_device *dssdev,
struct omap_video_timings *timings)
{
struct hdmi_cm cm;
cm = hdmi_get_code(timings);
if (cm.code == -1) {
return -EINVAL;
}
return 0;
}
void omapdss_hdmi_display_set_timing(struct omap_dss_device *dssdev)
{
struct hdmi_cm cm;
cm = hdmi_get_code(&dssdev->panel.timings);
hdmi.ip_data.cfg.cm.code = cm.code;
hdmi.ip_data.cfg.cm.mode = cm.mode;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE) {
int r;
hdmi_power_off(dssdev);
r = hdmi_power_on(dssdev);
if (r)
DSSERR("failed to power on device\n");
} else {
dss_mgr_set_timings(dssdev->manager, &dssdev->panel.timings);
}
}
static void hdmi_dump_regs(struct seq_file *s)
{
mutex_lock(&hdmi.lock);
if (hdmi_runtime_get())
return;
hdmi.ip_data.ops->dump_wrapper(&hdmi.ip_data, s);
hdmi.ip_data.ops->dump_pll(&hdmi.ip_data, s);
hdmi.ip_data.ops->dump_phy(&hdmi.ip_data, s);
hdmi.ip_data.ops->dump_core(&hdmi.ip_data, s);
hdmi_runtime_put();
mutex_unlock(&hdmi.lock);
}
int omapdss_hdmi_read_edid(u8 *buf, int len)
{
int r;
mutex_lock(&hdmi.lock);
r = hdmi_runtime_get();
BUG_ON(r);
r = hdmi.ip_data.ops->read_edid(&hdmi.ip_data, buf, len);
hdmi_runtime_put();
mutex_unlock(&hdmi.lock);
return r;
}
bool omapdss_hdmi_detect(void)
{
int r;
mutex_lock(&hdmi.lock);
r = hdmi_runtime_get();
BUG_ON(r);
r = hdmi.ip_data.ops->detect(&hdmi.ip_data);
hdmi_runtime_put();
mutex_unlock(&hdmi.lock);
return r == 1;
}
int omapdss_hdmi_display_enable(struct omap_dss_device *dssdev)
{
struct omap_dss_hdmi_data *priv = dssdev->data;
int r = 0;
DSSDBG("ENTER hdmi_display_enable\n");
mutex_lock(&hdmi.lock);
if (dssdev->manager == NULL) {
DSSERR("failed to enable display: no manager\n");
r = -ENODEV;
goto err0;
}
hdmi.ip_data.hpd_gpio = priv->hpd_gpio;
r = omap_dss_start_device(dssdev);
if (r) {
DSSERR("failed to start device\n");
goto err0;
}
if (dssdev->platform_enable) {
r = dssdev->platform_enable(dssdev);
if (r) {
DSSERR("failed to enable GPIO's\n");
goto err1;
}
}
r = hdmi_power_on(dssdev);
if (r) {
DSSERR("failed to power on device\n");
goto err2;
}
mutex_unlock(&hdmi.lock);
return 0;
err2:
if (dssdev->platform_disable)
dssdev->platform_disable(dssdev);
err1:
omap_dss_stop_device(dssdev);
err0:
mutex_unlock(&hdmi.lock);
return r;
}
void omapdss_hdmi_display_disable(struct omap_dss_device *dssdev)
{
DSSDBG("Enter hdmi_display_disable\n");
mutex_lock(&hdmi.lock);
hdmi_power_off(dssdev);
if (dssdev->platform_disable)
dssdev->platform_disable(dssdev);
omap_dss_stop_device(dssdev);
mutex_unlock(&hdmi.lock);
}
static int hdmi_get_clocks(struct platform_device *pdev)
{
struct clk *clk;
clk = clk_get(&pdev->dev, "sys_clk");
if (IS_ERR(clk)) {
DSSERR("can't get sys_clk\n");
return PTR_ERR(clk);
}
hdmi.sys_clk = clk;
return 0;
}
static void hdmi_put_clocks(void)
{
if (hdmi.sys_clk)
clk_put(hdmi.sys_clk);
}
int hdmi_compute_acr(u32 sample_freq, u32 *n, u32 *cts)
{
u32 deep_color;
bool deep_color_correct = false;
u32 pclk = hdmi.ip_data.cfg.timings.pixel_clock;
if (n == NULL || cts == NULL)
return -EINVAL;
deep_color = 100;
switch (sample_freq) {
case 32000:
case 48000:
case 96000:
case 192000:
if (deep_color == 125)
if (pclk == 27027 || pclk == 74250)
deep_color_correct = true;
if (deep_color == 150)
if (pclk == 27027)
deep_color_correct = true;
break;
case 44100:
case 88200:
case 176400:
if (deep_color == 125)
if (pclk == 27027)
deep_color_correct = true;
break;
default:
return -EINVAL;
}
if (deep_color_correct) {
switch (sample_freq) {
case 32000:
*n = 8192;
break;
case 44100:
*n = 12544;
break;
case 48000:
*n = 8192;
break;
case 88200:
*n = 25088;
break;
case 96000:
*n = 16384;
break;
case 176400:
*n = 50176;
break;
case 192000:
*n = 32768;
break;
default:
return -EINVAL;
}
} else {
switch (sample_freq) {
case 32000:
*n = 4096;
break;
case 44100:
*n = 6272;
break;
case 48000:
*n = 6144;
break;
case 88200:
*n = 12544;
break;
case 96000:
*n = 12288;
break;
case 176400:
*n = 25088;
break;
case 192000:
*n = 24576;
break;
default:
return -EINVAL;
}
}
*cts = pclk * (*n / 128) * deep_color / (sample_freq / 10);
return 0;
}
int hdmi_audio_enable(void)
{
DSSDBG("audio_enable\n");
return hdmi.ip_data.ops->audio_enable(&hdmi.ip_data);
}
void hdmi_audio_disable(void)
{
DSSDBG("audio_disable\n");
hdmi.ip_data.ops->audio_disable(&hdmi.ip_data);
}
int hdmi_audio_start(void)
{
DSSDBG("audio_start\n");
return hdmi.ip_data.ops->audio_start(&hdmi.ip_data);
}
void hdmi_audio_stop(void)
{
DSSDBG("audio_stop\n");
hdmi.ip_data.ops->audio_stop(&hdmi.ip_data);
}
bool hdmi_mode_has_audio(void)
{
if (hdmi.ip_data.cfg.cm.mode == HDMI_HDMI)
return true;
else
return false;
}
int hdmi_audio_config(struct omap_dss_audio *audio)
{
return hdmi.ip_data.ops->audio_config(&hdmi.ip_data, audio);
}
static void __init hdmi_probe_pdata(struct platform_device *pdev)
{
struct omap_dss_board_info *pdata = pdev->dev.platform_data;
int r, i;
for (i = 0; i < pdata->num_devices; ++i) {
struct omap_dss_device *dssdev = pdata->devices[i];
if (dssdev->type != OMAP_DISPLAY_TYPE_HDMI)
continue;
r = hdmi_init_display(dssdev);
if (r) {
DSSERR("device %s init failed: %d\n", dssdev->name, r);
continue;
}
r = omap_dss_register_device(dssdev, &pdev->dev, i);
if (r)
DSSERR("device %s register failed: %d\n",
dssdev->name, r);
}
}
static int __init omapdss_hdmihw_probe(struct platform_device *pdev)
{
struct resource *hdmi_mem;
int r;
hdmi.pdev = pdev;
mutex_init(&hdmi.lock);
hdmi_mem = platform_get_resource(hdmi.pdev, IORESOURCE_MEM, 0);
if (!hdmi_mem) {
DSSERR("can't get IORESOURCE_MEM HDMI\n");
return -EINVAL;
}
hdmi.ip_data.base_wp = ioremap(hdmi_mem->start,
resource_size(hdmi_mem));
if (!hdmi.ip_data.base_wp) {
DSSERR("can't ioremap WP\n");
return -ENOMEM;
}
r = hdmi_get_clocks(pdev);
if (r) {
iounmap(hdmi.ip_data.base_wp);
return r;
}
pm_runtime_enable(&pdev->dev);
hdmi.ip_data.core_sys_offset = HDMI_CORE_SYS;
hdmi.ip_data.core_av_offset = HDMI_CORE_AV;
hdmi.ip_data.pll_offset = HDMI_PLLCTRL;
hdmi.ip_data.phy_offset = HDMI_PHY;
mutex_init(&hdmi.ip_data.lock);
hdmi_panel_init();
dss_debugfs_create_file("hdmi", hdmi_dump_regs);
hdmi_probe_pdata(pdev);
return 0;
}
static int __exit omapdss_hdmihw_remove(struct platform_device *pdev)
{
omap_dss_unregister_child_devices(&pdev->dev);
hdmi_panel_exit();
pm_runtime_disable(&pdev->dev);
hdmi_put_clocks();
iounmap(hdmi.ip_data.base_wp);
return 0;
}
static int hdmi_runtime_suspend(struct device *dev)
{
clk_disable_unprepare(hdmi.sys_clk);
dispc_runtime_put();
return 0;
}
static int hdmi_runtime_resume(struct device *dev)
{
int r;
r = dispc_runtime_get();
if (r < 0)
return r;
clk_prepare_enable(hdmi.sys_clk);
return 0;
}
int __init hdmi_init_platform_driver(void)
{
return platform_driver_probe(&omapdss_hdmihw_driver, omapdss_hdmihw_probe);
}
void __exit hdmi_uninit_platform_driver(void)
{
platform_driver_unregister(&omapdss_hdmihw_driver);
}
