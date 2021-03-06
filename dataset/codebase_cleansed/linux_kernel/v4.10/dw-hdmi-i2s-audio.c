static inline void hdmi_write(struct dw_hdmi_i2s_audio_data *audio,
u8 val, int offset)
{
struct dw_hdmi *hdmi = audio->hdmi;
audio->write(hdmi, val, offset);
}
static inline u8 hdmi_read(struct dw_hdmi_i2s_audio_data *audio, int offset)
{
struct dw_hdmi *hdmi = audio->hdmi;
return audio->read(hdmi, offset);
}
static int dw_hdmi_i2s_hw_params(struct device *dev, void *data,
struct hdmi_codec_daifmt *fmt,
struct hdmi_codec_params *hparms)
{
struct dw_hdmi_i2s_audio_data *audio = data;
struct dw_hdmi *hdmi = audio->hdmi;
u8 conf0 = 0;
u8 conf1 = 0;
u8 inputclkfs = 0;
if ((fmt->fmt != HDMI_I2S) ||
(fmt->bit_clk_master | fmt->frame_clk_master)) {
dev_err(dev, "unsupported format/settings\n");
return -EINVAL;
}
inputclkfs = HDMI_AUD_INPUTCLKFS_64FS;
conf0 = HDMI_AUD_CONF0_I2S_ALL_ENABLE;
switch (hparms->sample_width) {
case 16:
conf1 = HDMI_AUD_CONF1_WIDTH_16;
break;
case 24:
case 32:
conf1 = HDMI_AUD_CONF1_WIDTH_24;
break;
}
dw_hdmi_set_sample_rate(hdmi, hparms->sample_rate);
hdmi_write(audio, inputclkfs, HDMI_AUD_INPUTCLKFS);
hdmi_write(audio, conf0, HDMI_AUD_CONF0);
hdmi_write(audio, conf1, HDMI_AUD_CONF1);
dw_hdmi_audio_enable(hdmi);
return 0;
}
static void dw_hdmi_i2s_audio_shutdown(struct device *dev, void *data)
{
struct dw_hdmi_i2s_audio_data *audio = data;
struct dw_hdmi *hdmi = audio->hdmi;
dw_hdmi_audio_disable(hdmi);
hdmi_write(audio, HDMI_AUD_CONF0_SW_RESET, HDMI_AUD_CONF0);
}
static int snd_dw_hdmi_probe(struct platform_device *pdev)
{
struct dw_hdmi_i2s_audio_data *audio = pdev->dev.platform_data;
struct platform_device_info pdevinfo;
struct hdmi_codec_pdata pdata;
struct platform_device *platform;
pdata.ops = &dw_hdmi_i2s_ops;
pdata.i2s = 1;
pdata.max_i2s_channels = 6;
pdata.data = audio;
memset(&pdevinfo, 0, sizeof(pdevinfo));
pdevinfo.parent = pdev->dev.parent;
pdevinfo.id = PLATFORM_DEVID_AUTO;
pdevinfo.name = HDMI_CODEC_DRV_NAME;
pdevinfo.data = &pdata;
pdevinfo.size_data = sizeof(pdata);
pdevinfo.dma_mask = DMA_BIT_MASK(32);
platform = platform_device_register_full(&pdevinfo);
if (IS_ERR(platform))
return PTR_ERR(platform);
dev_set_drvdata(&pdev->dev, platform);
return 0;
}
static int snd_dw_hdmi_remove(struct platform_device *pdev)
{
struct platform_device *platform = dev_get_drvdata(&pdev->dev);
platform_device_unregister(platform);
return 0;
}
