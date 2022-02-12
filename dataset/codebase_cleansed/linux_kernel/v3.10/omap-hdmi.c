static int omap_hdmi_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct hdmi_priv *priv = snd_soc_dai_get_drvdata(dai);
int err;
err = snd_pcm_hw_constraint_step(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_PERIOD_BYTES, 128);
if (err < 0) {
dev_err(dai->dev, "could not apply constraint\n");
return err;
}
if (!priv->dssdev->driver->audio_supported(priv->dssdev)) {
dev_err(dai->dev, "audio not supported\n");
return -ENODEV;
}
snd_soc_dai_set_dma_data(dai, substream, &priv->dma_data);
return 0;
}
static int omap_hdmi_dai_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct hdmi_priv *priv = snd_soc_dai_get_drvdata(dai);
return priv->dssdev->driver->audio_enable(priv->dssdev);
}
static int omap_hdmi_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct hdmi_priv *priv = snd_soc_dai_get_drvdata(dai);
struct snd_aes_iec958 *iec = &priv->iec;
struct snd_cea_861_aud_if *cea = &priv->cea;
int err = 0;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
priv->dma_data.maxburst = 16;
break;
case SNDRV_PCM_FORMAT_S24_LE:
priv->dma_data.maxburst = 32;
break;
default:
dev_err(dai->dev, "format not supported!\n");
return -EINVAL;
}
memset(iec->status, 0, sizeof(iec->status));
iec->status[0] &= ~IEC958_AES0_PROFESSIONAL;
iec->status[0] &= ~IEC958_AES0_NONAUDIO;
iec->status[0] |= IEC958_AES0_CON_NOT_COPYRIGHT;
iec->status[0] |= IEC958_AES0_CON_EMPHASIS_NONE;
iec->status[0] |= IEC958_AES1_PRO_MODE_NOTID;
iec->status[1] = IEC958_AES1_CON_GENERAL;
iec->status[2] |= IEC958_AES2_CON_SOURCE_UNSPEC;
iec->status[2] |= IEC958_AES2_CON_CHANNEL_UNSPEC;
switch (params_rate(params)) {
case 32000:
iec->status[3] |= IEC958_AES3_CON_FS_32000;
break;
case 44100:
iec->status[3] |= IEC958_AES3_CON_FS_44100;
break;
case 48000:
iec->status[3] |= IEC958_AES3_CON_FS_48000;
break;
case 88200:
iec->status[3] |= IEC958_AES3_CON_FS_88200;
break;
case 96000:
iec->status[3] |= IEC958_AES3_CON_FS_96000;
break;
case 176400:
iec->status[3] |= IEC958_AES3_CON_FS_176400;
break;
case 192000:
iec->status[3] |= IEC958_AES3_CON_FS_192000;
break;
default:
dev_err(dai->dev, "rate not supported!\n");
return -EINVAL;
}
iec->status[3] |= IEC958_AES3_CON_CLOCK_1000PPM;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
iec->status[4] |= IEC958_AES4_CON_WORDLEN_20_16;
iec->status[4] &= ~IEC958_AES4_CON_MAX_WORDLEN_24;
break;
case SNDRV_PCM_FORMAT_S24_LE:
iec->status[4] |= IEC958_AES4_CON_WORDLEN_24_20;
iec->status[4] |= IEC958_AES4_CON_MAX_WORDLEN_24;
break;
default:
dev_err(dai->dev, "format not supported!\n");
return -EINVAL;
}
cea->db1_ct_cc = (params_channels(params) - 1)
& CEA861_AUDIO_INFOFRAME_DB1CC;
cea->db1_ct_cc |= CEA861_AUDIO_INFOFRAME_DB1CT_FROM_STREAM;
cea->db2_sf_ss = CEA861_AUDIO_INFOFRAME_DB2SF_FROM_STREAM;
cea->db2_sf_ss |= CEA861_AUDIO_INFOFRAME_DB2SS_FROM_STREAM;
cea->db3 = 0;
if (params_channels(params) == 2)
cea->db4_ca = 0x0;
else
cea->db4_ca = 0x13;
cea->db5_dminh_lsv = CEA861_AUDIO_INFOFRAME_DB5_DM_INH_PROHIBITED;
cea->db5_dminh_lsv |= (0 & CEA861_AUDIO_INFOFRAME_DB5_LSV);
priv->dss_audio.iec = iec;
priv->dss_audio.cea = cea;
err = priv->dssdev->driver->audio_config(priv->dssdev,
&priv->dss_audio);
return err;
}
static int omap_hdmi_dai_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct hdmi_priv *priv = snd_soc_dai_get_drvdata(dai);
int err = 0;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
err = priv->dssdev->driver->audio_start(priv->dssdev);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
priv->dssdev->driver->audio_stop(priv->dssdev);
break;
default:
err = -EINVAL;
}
return err;
}
static void omap_hdmi_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct hdmi_priv *priv = snd_soc_dai_get_drvdata(dai);
priv->dssdev->driver->audio_disable(priv->dssdev);
}
static int omap_hdmi_probe(struct platform_device *pdev)
{
int ret;
struct resource *hdmi_rsrc;
struct hdmi_priv *hdmi_data;
bool hdmi_dev_found = false;
hdmi_data = devm_kzalloc(&pdev->dev, sizeof(*hdmi_data), GFP_KERNEL);
if (hdmi_data == NULL) {
dev_err(&pdev->dev, "Cannot allocate memory for HDMI data\n");
return -ENOMEM;
}
hdmi_rsrc = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!hdmi_rsrc) {
dev_err(&pdev->dev, "Cannot obtain IORESOURCE_MEM HDMI\n");
return -ENODEV;
}
hdmi_data->dma_data.addr = hdmi_rsrc->start + OMAP_HDMI_AUDIO_DMA_PORT;
hdmi_rsrc = platform_get_resource(pdev, IORESOURCE_DMA, 0);
if (!hdmi_rsrc) {
dev_err(&pdev->dev, "Cannot obtain IORESOURCE_DMA HDMI\n");
return -ENODEV;
}
hdmi_data->dma_req = hdmi_rsrc->start;
hdmi_data->dma_data.filter_data = &hdmi_data->dma_req;
hdmi_data->dma_data.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
for_each_dss_dev(hdmi_data->dssdev) {
omap_dss_get_device(hdmi_data->dssdev);
if (!hdmi_data->dssdev->driver) {
omap_dss_put_device(hdmi_data->dssdev);
continue;
}
if (hdmi_data->dssdev->type == OMAP_DISPLAY_TYPE_HDMI) {
hdmi_dev_found = true;
break;
}
}
if (!hdmi_dev_found) {
dev_err(&pdev->dev, "no driver for HDMI display found\n");
return -ENODEV;
}
dev_set_drvdata(&pdev->dev, hdmi_data);
ret = snd_soc_register_component(&pdev->dev, &omap_hdmi_component,
&omap_hdmi_dai, 1);
return ret;
}
static int omap_hdmi_remove(struct platform_device *pdev)
{
struct hdmi_priv *hdmi_data = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_component(&pdev->dev);
if (hdmi_data == NULL) {
dev_err(&pdev->dev, "cannot obtain HDMi data\n");
return -ENODEV;
}
omap_dss_put_device(hdmi_data->dssdev);
return 0;
}
