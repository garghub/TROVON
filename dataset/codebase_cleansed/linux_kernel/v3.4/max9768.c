static int max9768_get_gpio(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct max9768 *max9768 = snd_soc_codec_get_drvdata(codec);
int val = gpio_get_value_cansleep(max9768->mute_gpio);
ucontrol->value.integer.value[0] = !val;
return 0;
}
static int max9768_set_gpio(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
struct max9768 *max9768 = snd_soc_codec_get_drvdata(codec);
gpio_set_value_cansleep(max9768->mute_gpio, !ucontrol->value.integer.value[0]);
return 0;
}
static int max9768_probe(struct snd_soc_codec *codec)
{
struct max9768 *max9768 = snd_soc_codec_get_drvdata(codec);
int ret;
codec->control_data = max9768->regmap;
ret = snd_soc_codec_set_cache_io(codec, 2, 6, SND_SOC_REGMAP);
if (ret)
return ret;
if (max9768->flags & MAX9768_FLAG_CLASSIC_PWM) {
ret = snd_soc_write(codec, MAX9768_CTRL, MAX9768_CTRL_PWM);
if (ret)
return ret;
}
if (gpio_is_valid(max9768->mute_gpio)) {
ret = snd_soc_add_codec_controls(codec, max9768_mute,
ARRAY_SIZE(max9768_mute));
if (ret)
return ret;
}
return 0;
}
static int __devinit max9768_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max9768 *max9768;
struct max9768_pdata *pdata = client->dev.platform_data;
int err;
max9768 = devm_kzalloc(&client->dev, sizeof(*max9768), GFP_KERNEL);
if (!max9768)
return -ENOMEM;
if (pdata) {
err = gpio_request_one(pdata->mute_gpio, GPIOF_INIT_HIGH, "MAX9768 Mute");
max9768->mute_gpio = err ?: pdata->mute_gpio;
err = gpio_request_one(pdata->shdn_gpio, GPIOF_INIT_HIGH, "MAX9768 Shutdown");
max9768->shdn_gpio = err ?: pdata->shdn_gpio;
max9768->flags = pdata->flags;
} else {
max9768->shdn_gpio = -EINVAL;
max9768->mute_gpio = -EINVAL;
}
i2c_set_clientdata(client, max9768);
max9768->regmap = regmap_init_i2c(client, &max9768_i2c_regmap_config);
if (IS_ERR(max9768->regmap)) {
err = PTR_ERR(max9768->regmap);
goto err_gpio_free;
}
err = snd_soc_register_codec(&client->dev, &max9768_codec_driver, NULL, 0);
if (err)
goto err_regmap_free;
return 0;
err_regmap_free:
regmap_exit(max9768->regmap);
err_gpio_free:
if (gpio_is_valid(max9768->shdn_gpio))
gpio_free(max9768->shdn_gpio);
if (gpio_is_valid(max9768->mute_gpio))
gpio_free(max9768->mute_gpio);
return err;
}
static int __devexit max9768_i2c_remove(struct i2c_client *client)
{
struct max9768 *max9768 = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
regmap_exit(max9768->regmap);
if (gpio_is_valid(max9768->shdn_gpio))
gpio_free(max9768->shdn_gpio);
if (gpio_is_valid(max9768->mute_gpio))
gpio_free(max9768->mute_gpio);
return 0;
}
