static int hdmi_runtime_get(void)
{
int r;
DSSDBG("hdmi_runtime_get\n");
r = pm_runtime_get_sync(&hdmi.pdev->dev);
WARN_ON(r < 0);
return r < 0 ? r : 0;
}
static void hdmi_runtime_put(void)
{
int r;
DSSDBG("hdmi_runtime_put\n");
r = pm_runtime_put(&hdmi.pdev->dev);
WARN_ON(r < 0);
}
int hdmi_init_display(struct omap_dss_device *dssdev)
{
DSSDBG("init_display\n");
dss_init_hdmi_ip_ops(&hdmi.ip_data);
return 0;
}
static int get_timings_index(void)
{
int code;
if (hdmi.mode == 0)
code = code_vesa[hdmi.code];
else
code = code_cea[hdmi.code];
if (code == -1) {
hdmi.code = 4;
hdmi.mode = HDMI_DVI;
code = code_vesa[hdmi.code];
}
return code;
}
static struct hdmi_cm hdmi_get_code(struct omap_video_timings *timing)
{
int i = 0, code = -1, temp_vsync = 0, temp_hsync = 0;
int timing_vsync = 0, timing_hsync = 0;
struct hdmi_video_timings temp;
struct hdmi_cm cm = {-1};
DSSDBG("hdmi_get_code\n");
for (i = 0; i < OMAP_HDMI_TIMINGS_NB; i++) {
temp = cea_vesa_timings[i].timings;
if ((temp.pixel_clock == timing->pixel_clock) &&
(temp.x_res == timing->x_res) &&
(temp.y_res == timing->y_res)) {
temp_hsync = temp.hfp + temp.hsw + temp.hbp;
timing_hsync = timing->hfp + timing->hsw + timing->hbp;
temp_vsync = temp.vfp + temp.vsw + temp.vbp;
timing_vsync = timing->vfp + timing->vsw + timing->vbp;
DSSDBG("temp_hsync = %d , temp_vsync = %d"
"timing_hsync = %d, timing_vsync = %d\n",
temp_hsync, temp_hsync,
timing_hsync, timing_vsync);
if ((temp_hsync == timing_hsync) &&
(temp_vsync == timing_vsync)) {
code = i;
cm.code = code_index[i];
if (code < 14)
cm.mode = HDMI_HDMI;
else
cm.mode = HDMI_DVI;
DSSDBG("Hdmi_code = %d mode = %d\n",
cm.code, cm.mode);
break;
}
}
}
return cm;
}
static void update_hdmi_timings(struct hdmi_config *cfg,
struct omap_video_timings *timings, int code)
{
cfg->timings.timings.x_res = timings->x_res;
cfg->timings.timings.y_res = timings->y_res;
cfg->timings.timings.hbp = timings->hbp;
cfg->timings.timings.hfp = timings->hfp;
cfg->timings.timings.hsw = timings->hsw;
cfg->timings.timings.vbp = timings->vbp;
cfg->timings.timings.vfp = timings->vfp;
cfg->timings.timings.vsw = timings->vsw;
cfg->timings.timings.pixel_clock = timings->pixel_clock;
cfg->timings.vsync_pol = cea_vesa_timings[code].vsync_pol;
cfg->timings.hsync_pol = cea_vesa_timings[code].hsync_pol;
}
unsigned long hdmi_get_pixel_clock(void)
{
return hdmi.ip_data.cfg.timings.timings.pixel_clock * 1000;
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
pi->regm = (phy * 100 / (refclk)) / 100;
if (dssdev->clocks.hdmi.regm2 == 0)
pi->regm2 = HDMI_DEFAULT_REGM2;
else
pi->regm2 = dssdev->clocks.hdmi.regm2;
mf = (phy - pi->regm * refclk) * 262144;
pi->regmf = mf / (refclk);
pi->dcofreq = phy > 1000 * 100;
pi->regsd = ((pi->regm * clkin / 10) / (pi->regn * 250) + 5) / 10;
pi->refsel = HDMI_REFSEL_SYSCLK;
DSSDBG("M = %d Mf = %d\n", pi->regm, pi->regmf);
DSSDBG("range = %d sd = %d\n", pi->dcofreq, pi->regsd);
}
static int hdmi_power_on(struct omap_dss_device *dssdev)
{
int r, code = 0;
struct omap_video_timings *p;
unsigned long phy;
r = hdmi_runtime_get();
if (r)
return r;
dispc_mgr_enable(OMAP_DSS_CHANNEL_DIGIT, 0);
p = &dssdev->panel.timings;
DSSDBG("hdmi_power_on x_res= %d y_res = %d\n",
dssdev->panel.timings.x_res,
dssdev->panel.timings.y_res);
code = get_timings_index();
update_hdmi_timings(&hdmi.ip_data.cfg, p, code);
phy = p->pixel_clock;
hdmi_compute_pll(dssdev, phy, &hdmi.ip_data.pll_data);
hdmi.ip_data.ops->video_enable(&hdmi.ip_data, 0);
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
hdmi.ip_data.cfg.cm.mode = hdmi.mode;
hdmi.ip_data.cfg.cm.code = hdmi.code;
hdmi.ip_data.ops->video_configure(&hdmi.ip_data);
dss_select_hdmi_venc_clk_source(DSS_HDMI_M_PCLK);
dss_select_dispc_clk_source(dssdev->clocks.dispc.dispc_fclk_src);
dispc_enable_gamma_table(0);
dispc_set_digit_size(dssdev->panel.timings.x_res,
dssdev->panel.timings.y_res);
hdmi.ip_data.ops->video_enable(&hdmi.ip_data, 1);
dispc_mgr_enable(OMAP_DSS_CHANNEL_DIGIT, 1);
return 0;
err:
hdmi_runtime_put();
return -EIO;
}
static void hdmi_power_off(struct omap_dss_device *dssdev)
{
dispc_mgr_enable(OMAP_DSS_CHANNEL_DIGIT, 0);
hdmi.ip_data.ops->video_enable(&hdmi.ip_data, 0);
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
hdmi.code = cm.code;
hdmi.mode = cm.mode;
if (dssdev->state == OMAP_DSS_DISPLAY_ACTIVE) {
int r;
hdmi_power_off(dssdev);
r = hdmi_power_on(dssdev);
if (r)
DSSERR("failed to power on device\n");
}
}
void hdmi_dump_regs(struct seq_file *s)
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
int r = 0;
DSSDBG("ENTER hdmi_display_enable\n");
mutex_lock(&hdmi.lock);
if (dssdev->manager == NULL) {
DSSERR("failed to enable display: no manager\n");
r = -ENODEV;
goto err0;
}
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
static int hdmi_audio_hw_params(struct hdmi_ip_data *ip_data,
struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct hdmi_audio_format audio_format;
struct hdmi_audio_dma audio_dma;
struct hdmi_core_audio_config core_cfg;
struct hdmi_core_infoframe_audio aud_if_cfg;
int err, n, cts;
enum hdmi_core_audio_sample_freq sample_freq;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
core_cfg.i2s_cfg.word_max_length =
HDMI_AUDIO_I2S_MAX_WORD_20BITS;
core_cfg.i2s_cfg.word_length = HDMI_AUDIO_I2S_CHST_WORD_16_BITS;
core_cfg.i2s_cfg.in_length_bits =
HDMI_AUDIO_I2S_INPUT_LENGTH_16;
core_cfg.i2s_cfg.justification = HDMI_AUDIO_JUSTIFY_LEFT;
audio_format.samples_per_word = HDMI_AUDIO_ONEWORD_TWOSAMPLES;
audio_format.sample_size = HDMI_AUDIO_SAMPLE_16BITS;
audio_format.justification = HDMI_AUDIO_JUSTIFY_LEFT;
audio_dma.transfer_size = 0x10;
break;
case SNDRV_PCM_FORMAT_S24_LE:
core_cfg.i2s_cfg.word_max_length =
HDMI_AUDIO_I2S_MAX_WORD_24BITS;
core_cfg.i2s_cfg.word_length = HDMI_AUDIO_I2S_CHST_WORD_24_BITS;
core_cfg.i2s_cfg.in_length_bits =
HDMI_AUDIO_I2S_INPUT_LENGTH_24;
audio_format.samples_per_word = HDMI_AUDIO_ONEWORD_ONESAMPLE;
audio_format.sample_size = HDMI_AUDIO_SAMPLE_24BITS;
audio_format.justification = HDMI_AUDIO_JUSTIFY_RIGHT;
core_cfg.i2s_cfg.justification = HDMI_AUDIO_JUSTIFY_RIGHT;
audio_dma.transfer_size = 0x20;
break;
default:
return -EINVAL;
}
switch (params_rate(params)) {
case 32000:
sample_freq = HDMI_AUDIO_FS_32000;
break;
case 44100:
sample_freq = HDMI_AUDIO_FS_44100;
break;
case 48000:
sample_freq = HDMI_AUDIO_FS_48000;
break;
default:
return -EINVAL;
}
err = hdmi_config_audio_acr(ip_data, params_rate(params), &n, &cts);
if (err < 0)
return err;
audio_format.stereo_channels = HDMI_AUDIO_STEREO_ONECHANNEL;
audio_format.active_chnnls_msk = 0x03;
audio_format.type = HDMI_AUDIO_TYPE_LPCM;
audio_format.sample_order = HDMI_AUDIO_SAMPLE_LEFT_FIRST;
audio_format.en_sig_blk_strt_end = HDMI_AUDIO_BLOCK_SIG_STARTEND_OFF;
audio_dma.block_size = 0xC0;
audio_dma.mode = HDMI_AUDIO_TRANSF_DMA;
audio_dma.fifo_threshold = 0x20;
hdmi_wp_audio_config_dma(ip_data, &audio_dma);
hdmi_wp_audio_config_format(ip_data, &audio_format);
core_cfg.i2s_cfg.en_high_bitrate_aud = false;
core_cfg.i2s_cfg.cbit_order = false;
core_cfg.i2s_cfg.sck_edge_mode = HDMI_AUDIO_I2S_SCK_EDGE_RISING;
core_cfg.i2s_cfg.vbit = HDMI_AUDIO_I2S_VBIT_FOR_PCM;
core_cfg.i2s_cfg.ws_polarity = HDMI_AUDIO_I2S_WS_POLARITY_LOW_IS_LEFT;
core_cfg.i2s_cfg.direction = HDMI_AUDIO_I2S_MSB_SHIFTED_FIRST;
core_cfg.i2s_cfg.shift = HDMI_AUDIO_I2S_FIRST_BIT_SHIFT;
core_cfg.i2s_cfg.active_sds = HDMI_AUDIO_I2S_SD0_EN;
core_cfg.freq_sample = sample_freq;
core_cfg.n = n;
core_cfg.cts = cts;
if (dss_has_feature(FEAT_HDMI_CTS_SWMODE)) {
core_cfg.aud_par_busclk = 0;
core_cfg.cts_mode = HDMI_AUDIO_CTS_MODE_SW;
core_cfg.use_mclk = false;
} else {
core_cfg.aud_par_busclk = (((128 * 31) - 1) << 8);
core_cfg.cts_mode = HDMI_AUDIO_CTS_MODE_HW;
core_cfg.use_mclk = true;
core_cfg.mclk_mode = HDMI_AUDIO_MCLK_128FS;
}
core_cfg.layout = HDMI_AUDIO_LAYOUT_2CH;
core_cfg.en_spdif = false;
core_cfg.fs_override = true;
core_cfg.en_acr_pkt = true;
core_cfg.en_dsd_audio = false;
core_cfg.en_parallel_aud_input = true;
hdmi_core_audio_config(ip_data, &core_cfg);
aud_if_cfg.db1_coding_type = HDMI_INFOFRAME_AUDIO_DB1CT_FROM_STREAM;
aud_if_cfg.db1_channel_count = 2;
aud_if_cfg.db2_sample_freq = HDMI_INFOFRAME_AUDIO_DB2SF_FROM_STREAM;
aud_if_cfg.db2_sample_size = HDMI_INFOFRAME_AUDIO_DB2SS_FROM_STREAM;
aud_if_cfg.db4_channel_alloc = 0x00;
aud_if_cfg.db5_downmix_inh = false;
aud_if_cfg.db5_lsv = 0;
hdmi_core_audio_infoframe_config(ip_data, &aud_if_cfg);
return 0;
}
static int hdmi_audio_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
if (!hdmi.mode) {
pr_err("Current video settings do not support audio.\n");
return -EIO;
}
return 0;
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
static int omapdss_hdmihw_probe(struct platform_device *pdev)
{
struct resource *hdmi_mem;
int r;
hdmi.pdata = pdev->dev.platform_data;
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
hdmi_panel_init();
#if defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI) || \
defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI_MODULE)
r = snd_soc_register_codec(&pdev->dev, &hdmi_audio_codec_drv,
&hdmi_codec_dai_drv, 1);
if (r) {
DSSERR("can't register ASoC HDMI audio codec\n");
return r;
}
#endif
return 0;
}
static int omapdss_hdmihw_remove(struct platform_device *pdev)
{
hdmi_panel_exit();
#if defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI) || \
defined(CONFIG_SND_OMAP_SOC_OMAP4_HDMI_MODULE)
snd_soc_unregister_codec(&pdev->dev);
#endif
pm_runtime_disable(&pdev->dev);
hdmi_put_clocks();
iounmap(hdmi.ip_data.base_wp);
return 0;
}
static int hdmi_runtime_suspend(struct device *dev)
{
clk_disable(hdmi.sys_clk);
dispc_runtime_put();
dss_runtime_put();
return 0;
}
static int hdmi_runtime_resume(struct device *dev)
{
int r;
r = dss_runtime_get();
if (r < 0)
goto err_get_dss;
r = dispc_runtime_get();
if (r < 0)
goto err_get_dispc;
clk_enable(hdmi.sys_clk);
return 0;
err_get_dispc:
dss_runtime_put();
err_get_dss:
return r;
}
int hdmi_init_platform_driver(void)
{
return platform_driver_register(&omapdss_hdmihw_driver);
}
void hdmi_uninit_platform_driver(void)
{
return platform_driver_unregister(&omapdss_hdmihw_driver);
}
