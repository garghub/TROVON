static int hdmi_runtime_get(void)
{
int r;
DSSDBG("hdmi_runtime_get\n");
r = dss_runtime_get();
if (r < 0)
goto err_get_dss;
r = pm_runtime_get_sync(&hdmi.pdev->dev);
WARN_ON(r < 0);
if (r < 0)
goto err_get_hdmi;
return 0;
err_get_hdmi:
dss_runtime_put();
err_get_dss:
return r;
}
static void hdmi_runtime_put(void)
{
int r;
DSSDBG("hdmi_runtime_put\n");
r = pm_runtime_put_sync(&hdmi.pdev->dev);
WARN_ON(r < 0);
dss_runtime_put();
}
int hdmi_init_display(struct omap_dss_device *dssdev)
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
const struct hdmi_video_timings *timing2)
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
hdmi.ip_data.ops->video_configure(&hdmi.ip_data);
dss_select_hdmi_venc_clk_source(DSS_HDMI_M_PCLK);
dss_select_dispc_clk_source(dssdev->clocks.dispc.dispc_fclk_src);
dispc_enable_gamma_table(0);
dispc_set_digit_size(dssdev->panel.timings.x_res,
dssdev->panel.timings.y_res);
hdmi.ip_data.ops->video_enable(&hdmi.ip_data, 1);
r = dss_mgr_enable(dssdev->manager);
if (r)
goto err_mgr_enable;
return 0;
err_mgr_enable:
hdmi.ip_data.ops->video_enable(&hdmi.ip_data, 0);
hdmi.ip_data.ops->phy_disable(&hdmi.ip_data);
hdmi.ip_data.ops->pll_disable(&hdmi.ip_data);
err:
hdmi_runtime_put();
return -EIO;
}
static void hdmi_power_off(struct omap_dss_device *dssdev)
{
dss_mgr_disable(dssdev->manager);
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
hdmi.ip_data.cfg.cm.code = cm.code;
hdmi.ip_data.cfg.cm.mode = cm.mode;
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
static int hdmi_audio_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct platform_device *pdev = to_platform_device(codec->dev);
struct hdmi_ip_data *ip_data = snd_soc_codec_get_drvdata(codec);
int err = 0;
if (!(ip_data->ops) && !(ip_data->ops->audio_enable)) {
dev_err(&pdev->dev, "Cannot enable/disable audio\n");
return -ENODEV;
}
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ip_data->ops->audio_enable(ip_data, true);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
ip_data->ops->audio_enable(ip_data, false);
break;
default:
err = -EINVAL;
}
return err;
}
static int hdmi_audio_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
struct hdmi_ip_data *ip_data = snd_soc_codec_get_drvdata(codec);
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
core_cfg.use_mclk = dss_has_feature(FEAT_HDMI_AUDIO_USE_MCLK);
} else {
core_cfg.aud_par_busclk = (((128 * 31) - 1) << 8);
core_cfg.cts_mode = HDMI_AUDIO_CTS_MODE_HW;
core_cfg.use_mclk = true;
}
if (core_cfg.use_mclk)
core_cfg.mclk_mode = HDMI_AUDIO_MCLK_128FS;
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
if (!hdmi.ip_data.cfg.cm.mode) {
pr_err("Current video settings do not support audio.\n");
return -EIO;
}
return 0;
}
static int hdmi_audio_codec_probe(struct snd_soc_codec *codec)
{
struct hdmi_ip_data *priv = &hdmi.ip_data;
snd_soc_codec_set_drvdata(codec, priv);
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
