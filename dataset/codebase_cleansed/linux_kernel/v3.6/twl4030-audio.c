static int twl4030_audio_set_resource(enum twl4030_audio_res id, int enable)
{
struct twl4030_audio *audio = platform_get_drvdata(twl4030_audio_dev);
u8 val;
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE, &val,
audio->resource[id].reg);
if (enable)
val |= audio->resource[id].mask;
else
val &= ~audio->resource[id].mask;
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
val, audio->resource[id].reg);
return val;
}
static inline int twl4030_audio_get_resource(enum twl4030_audio_res id)
{
struct twl4030_audio *audio = platform_get_drvdata(twl4030_audio_dev);
u8 val;
twl_i2c_read_u8(TWL4030_MODULE_AUDIO_VOICE, &val,
audio->resource[id].reg);
return val;
}
int twl4030_audio_enable_resource(enum twl4030_audio_res id)
{
struct twl4030_audio *audio = platform_get_drvdata(twl4030_audio_dev);
int val;
if (id >= TWL4030_AUDIO_RES_MAX) {
dev_err(&twl4030_audio_dev->dev,
"Invalid resource ID (%u)\n", id);
return -EINVAL;
}
mutex_lock(&audio->mutex);
if (!audio->resource[id].request_count)
val = twl4030_audio_set_resource(id, 1);
else
val = twl4030_audio_get_resource(id);
audio->resource[id].request_count++;
mutex_unlock(&audio->mutex);
return val;
}
int twl4030_audio_disable_resource(unsigned id)
{
struct twl4030_audio *audio = platform_get_drvdata(twl4030_audio_dev);
int val;
if (id >= TWL4030_AUDIO_RES_MAX) {
dev_err(&twl4030_audio_dev->dev,
"Invalid resource ID (%u)\n", id);
return -EINVAL;
}
mutex_lock(&audio->mutex);
if (!audio->resource[id].request_count) {
dev_err(&twl4030_audio_dev->dev,
"Resource has been disabled already (%u)\n", id);
mutex_unlock(&audio->mutex);
return -EPERM;
}
audio->resource[id].request_count--;
if (!audio->resource[id].request_count)
val = twl4030_audio_set_resource(id, 0);
else
val = twl4030_audio_get_resource(id);
mutex_unlock(&audio->mutex);
return val;
}
unsigned int twl4030_audio_get_mclk(void)
{
struct twl4030_audio *audio = platform_get_drvdata(twl4030_audio_dev);
return audio->audio_mclk;
}
static int __devinit twl4030_audio_probe(struct platform_device *pdev)
{
struct twl4030_audio *audio;
struct twl4030_audio_data *pdata = pdev->dev.platform_data;
struct mfd_cell *cell = NULL;
int ret, childs = 0;
u8 val;
if (!pdata) {
dev_err(&pdev->dev, "Platform data is missing\n");
return -EINVAL;
}
val = 0;
switch (pdata->audio_mclk) {
case 19200000:
val |= TWL4030_APLL_INFREQ_19200KHZ;
break;
case 26000000:
val |= TWL4030_APLL_INFREQ_26000KHZ;
break;
case 38400000:
val |= TWL4030_APLL_INFREQ_38400KHZ;
break;
default:
dev_err(&pdev->dev, "Invalid audio_mclk\n");
return -EINVAL;
}
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE,
val, TWL4030_REG_APLL_CTL);
audio = kzalloc(sizeof(struct twl4030_audio), GFP_KERNEL);
if (!audio)
return -ENOMEM;
platform_set_drvdata(pdev, audio);
twl4030_audio_dev = pdev;
mutex_init(&audio->mutex);
audio->audio_mclk = pdata->audio_mclk;
audio->resource[TWL4030_AUDIO_RES_POWER].reg = TWL4030_REG_CODEC_MODE;
audio->resource[TWL4030_AUDIO_RES_POWER].mask = TWL4030_CODECPDZ;
audio->resource[TWL4030_AUDIO_RES_APLL].reg = TWL4030_REG_APLL_CTL;
audio->resource[TWL4030_AUDIO_RES_APLL].mask = TWL4030_APLL_EN;
if (pdata->codec) {
cell = &audio->cells[childs];
cell->name = "twl4030-codec";
cell->platform_data = pdata->codec;
cell->pdata_size = sizeof(*pdata->codec);
childs++;
}
if (pdata->vibra) {
cell = &audio->cells[childs];
cell->name = "twl4030-vibra";
cell->platform_data = pdata->vibra;
cell->pdata_size = sizeof(*pdata->vibra);
childs++;
}
if (childs)
ret = mfd_add_devices(&pdev->dev, pdev->id, audio->cells,
childs, NULL, 0, NULL);
else {
dev_err(&pdev->dev, "No platform data found for childs\n");
ret = -ENODEV;
}
if (!ret)
return 0;
platform_set_drvdata(pdev, NULL);
kfree(audio);
twl4030_audio_dev = NULL;
return ret;
}
static int __devexit twl4030_audio_remove(struct platform_device *pdev)
{
struct twl4030_audio *audio = platform_get_drvdata(pdev);
mfd_remove_devices(&pdev->dev);
platform_set_drvdata(pdev, NULL);
kfree(audio);
twl4030_audio_dev = NULL;
return 0;
}
