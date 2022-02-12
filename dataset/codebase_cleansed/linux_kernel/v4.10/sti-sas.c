static int sti_sas_read_reg(void *context, unsigned int reg,
unsigned int *value)
{
struct sti_sas_data *drvdata = context;
int status;
u32 val;
status = regmap_read(drvdata->dac.regmap, reg, &val);
*value = (unsigned int)val;
return status;
}
static int sti_sas_write_reg(void *context, unsigned int reg,
unsigned int value)
{
struct sti_sas_data *drvdata = context;
int status;
status = regmap_write(drvdata->dac.regmap, reg, value);
return status;
}
static int sti_sas_init_sas_registers(struct snd_soc_codec *codec,
struct sti_sas_data *data)
{
int ret;
ret = snd_soc_update_bits(codec, STIH407_AUDIO_GLUE_CTRL,
SPDIF_BIPHASE_ENABLE_MASK, 0);
if (!ret)
ret = snd_soc_update_bits(codec, STIH407_AUDIO_GLUE_CTRL,
SPDIF_BIPHASE_IDLE_MASK, 0);
if (ret < 0) {
dev_err(codec->dev, "Failed to update SPDIF registers\n");
return ret;
}
ret = snd_soc_update_bits(codec, STIH407_AUDIO_DAC_CTRL,
STIH407_DAC_STANDBY_MASK,
STIH407_DAC_STANDBY_MASK);
if (!ret)
ret = snd_soc_update_bits(codec, STIH407_AUDIO_DAC_CTRL,
STIH407_DAC_STANDBY_ANA_MASK,
STIH407_DAC_STANDBY_ANA_MASK);
if (!ret)
ret = snd_soc_update_bits(codec, STIH407_AUDIO_DAC_CTRL,
STIH407_DAC_SOFTMUTE_MASK,
STIH407_DAC_SOFTMUTE_MASK);
if (ret < 0) {
dev_err(codec->dev, "Failed to update DAC registers\n");
return ret;
}
return ret;
}
static int sti_sas_dac_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS) {
dev_err(dai->codec->dev,
"%s: ERROR: Unsupporter master mask 0x%x\n",
__func__, fmt & SND_SOC_DAIFMT_MASTER_MASK);
return -EINVAL;
}
return 0;
}
static int stih407_sas_dac_mute(struct snd_soc_dai *dai, int mute, int stream)
{
struct snd_soc_codec *codec = dai->codec;
if (mute) {
return snd_soc_update_bits(codec, STIH407_AUDIO_DAC_CTRL,
STIH407_DAC_SOFTMUTE_MASK,
STIH407_DAC_SOFTMUTE_MASK);
} else {
return snd_soc_update_bits(codec, STIH407_AUDIO_DAC_CTRL,
STIH407_DAC_SOFTMUTE_MASK,
0);
}
}
static int sti_sas_spdif_set_fmt(struct snd_soc_dai *dai,
unsigned int fmt)
{
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS) {
dev_err(dai->codec->dev,
"%s: ERROR: Unsupporter master mask 0x%x\n",
__func__, fmt & SND_SOC_DAIFMT_MASTER_MASK);
return -EINVAL;
}
return 0;
}
static int sti_sas_spdif_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
return snd_soc_update_bits(codec, STIH407_AUDIO_GLUE_CTRL,
SPDIF_BIPHASE_ENABLE_MASK,
SPDIF_BIPHASE_ENABLE_MASK);
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
return snd_soc_update_bits(codec, STIH407_AUDIO_GLUE_CTRL,
SPDIF_BIPHASE_ENABLE_MASK,
0);
default:
return -EINVAL;
}
}
static bool sti_sas_volatile_register(struct device *dev, unsigned int reg)
{
if (reg == STIH407_AUDIO_GLUE_CTRL)
return true;
return false;
}
static int sti_sas_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct sti_sas_data *drvdata = dev_get_drvdata(codec->dev);
if (dir == SND_SOC_CLOCK_OUT)
return 0;
if (clk_id != 0)
return -EINVAL;
switch (dai->id) {
case STI_SAS_DAI_SPDIF_OUT:
drvdata->spdif.mclk = freq;
break;
case STI_SAS_DAI_ANALOG_OUT:
drvdata->dac.mclk = freq;
break;
}
return 0;
}
static int sti_sas_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct sti_sas_data *drvdata = dev_get_drvdata(codec->dev);
struct snd_pcm_runtime *runtime = substream->runtime;
switch (dai->id) {
case STI_SAS_DAI_SPDIF_OUT:
if ((drvdata->spdif.mclk / runtime->rate) != 128) {
dev_err(codec->dev, "unexpected mclk-fs ratio\n");
return -EINVAL;
}
break;
case STI_SAS_DAI_ANALOG_OUT:
if ((drvdata->dac.mclk / runtime->rate) != 256) {
dev_err(codec->dev, "unexpected mclk-fs ratio\n");
return -EINVAL;
}
break;
}
return 0;
}
static int sti_sas_resume(struct snd_soc_codec *codec)
{
struct sti_sas_data *drvdata = dev_get_drvdata(codec->dev);
return sti_sas_init_sas_registers(codec, drvdata);
}
static int sti_sas_codec_probe(struct snd_soc_codec *codec)
{
struct sti_sas_data *drvdata = dev_get_drvdata(codec->dev);
int ret;
ret = sti_sas_init_sas_registers(codec, drvdata);
return ret;
}
static int sti_sas_driver_probe(struct platform_device *pdev)
{
struct device_node *pnode = pdev->dev.of_node;
struct sti_sas_data *drvdata;
const struct of_device_id *of_id;
drvdata = devm_kzalloc(&pdev->dev, sizeof(struct sti_sas_data),
GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
of_id = of_match_node(sti_sas_dev_match, pnode);
if (!of_id->data) {
dev_err(&pdev->dev, "data associated to device is missing\n");
return -EINVAL;
}
drvdata->dev_data = (struct sti_sas_dev_data *)of_id->data;
drvdata->dev = &pdev->dev;
drvdata->dac.virt_regmap = devm_regmap_init(&pdev->dev, NULL, drvdata,
drvdata->dev_data->regmap);
if (IS_ERR(drvdata->dac.virt_regmap)) {
dev_err(&pdev->dev, "audio registers not enabled\n");
return PTR_ERR(drvdata->dac.virt_regmap);
}
drvdata->dac.regmap =
syscon_regmap_lookup_by_phandle(pnode, "st,syscfg");
if (IS_ERR(drvdata->dac.regmap)) {
dev_err(&pdev->dev, "syscon registers not available\n");
return PTR_ERR(drvdata->dac.regmap);
}
drvdata->spdif.regmap = drvdata->dac.regmap;
sti_sas_dai[STI_SAS_DAI_ANALOG_OUT].ops = drvdata->dev_data->dac_ops;
sti_sas_driver.component_driver.dapm_widgets = drvdata->dev_data->dapm_widgets;
sti_sas_driver.component_driver.num_dapm_widgets = drvdata->dev_data->num_dapm_widgets;
sti_sas_driver.component_driver.dapm_routes = drvdata->dev_data->dapm_routes;
sti_sas_driver.component_driver.num_dapm_routes = drvdata->dev_data->num_dapm_routes;
dev_set_drvdata(&pdev->dev, drvdata);
return snd_soc_register_codec(&pdev->dev, &sti_sas_driver,
sti_sas_dai,
ARRAY_SIZE(sti_sas_dai));
}
static int sti_sas_driver_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
