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
static bool twl4030_audio_has_codec(struct twl4030_audio_data *pdata,
struct device_node *node)
{
if (pdata && pdata->codec)
return true;
if (of_find_node_by_name(node, "codec"))
return true;
return false;
}
static bool twl4030_audio_has_vibra(struct twl4030_audio_data *pdata,
struct device_node *node)
{
int vibra;
if (pdata && pdata->vibra)
return true;
if (!of_property_read_u32(node, "ti,enable-vibra", &vibra) && vibra)
return true;
return false;
}
static int __devinit twl4030_audio_probe(struct platform_device *pdev)
{
struct twl4030_audio *audio;
struct twl4030_audio_data *pdata = pdev->dev.platform_data;
struct device_node *node = pdev->dev.of_node;
struct mfd_cell *cell = NULL;
int ret, childs = 0;
u8 val;
if (!pdata && !node) {
dev_err(&pdev->dev, "Platform data is missing\n");
return -EINVAL;
}
audio = devm_kzalloc(&pdev->dev, sizeof(struct twl4030_audio),
GFP_KERNEL);
if (!audio)
return -ENOMEM;
mutex_init(&audio->mutex);
audio->audio_mclk = twl_get_hfclk_rate();
switch (audio->audio_mclk) {
case 19200000:
val = TWL4030_APLL_INFREQ_19200KHZ;
break;
case 26000000:
val = TWL4030_APLL_INFREQ_26000KHZ;
break;
case 38400000:
val = TWL4030_APLL_INFREQ_38400KHZ;
break;
default:
dev_err(&pdev->dev, "Invalid audio_mclk\n");
return -EINVAL;
}
twl_i2c_write_u8(TWL4030_MODULE_AUDIO_VOICE, val, TWL4030_REG_APLL_CTL);
audio->resource[TWL4030_AUDIO_RES_POWER].reg = TWL4030_REG_CODEC_MODE;
audio->resource[TWL4030_AUDIO_RES_POWER].mask = TWL4030_CODECPDZ;
audio->resource[TWL4030_AUDIO_RES_APLL].reg = TWL4030_REG_APLL_CTL;
audio->resource[TWL4030_AUDIO_RES_APLL].mask = TWL4030_APLL_EN;
if (twl4030_audio_has_codec(pdata, node)) {
cell = &audio->cells[childs];
cell->name = "twl4030-codec";
if (pdata) {
cell->platform_data = pdata->codec;
cell->pdata_size = sizeof(*pdata->codec);
}
childs++;
}
if (twl4030_audio_has_vibra(pdata, node)) {
cell = &audio->cells[childs];
cell->name = "twl4030-vibra";
if (pdata) {
cell->platform_data = pdata->vibra;
cell->pdata_size = sizeof(*pdata->vibra);
}
childs++;
}
platform_set_drvdata(pdev, audio);
twl4030_audio_dev = pdev;
if (childs)
ret = mfd_add_devices(&pdev->dev, pdev->id, audio->cells,
childs, NULL, 0, NULL);
else {
dev_err(&pdev->dev, "No platform data found for childs\n");
ret = -ENODEV;
}
if (ret) {
platform_set_drvdata(pdev, NULL);
twl4030_audio_dev = NULL;
}
return ret;
}
static int __devexit twl4030_audio_remove(struct platform_device *pdev)
{
mfd_remove_devices(&pdev->dev);
platform_set_drvdata(pdev, NULL);
twl4030_audio_dev = NULL;
return 0;
}
