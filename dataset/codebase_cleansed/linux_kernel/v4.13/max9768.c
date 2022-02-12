static int max9768_get_gpio(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *c = snd_soc_kcontrol_component(kcontrol);
struct max9768 *max9768 = snd_soc_component_get_drvdata(c);
int val = gpio_get_value_cansleep(max9768->mute_gpio);
ucontrol->value.integer.value[0] = !val;
return 0;
}
static int max9768_set_gpio(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *c = snd_soc_kcontrol_component(kcontrol);
struct max9768 *max9768 = snd_soc_component_get_drvdata(c);
gpio_set_value_cansleep(max9768->mute_gpio, !ucontrol->value.integer.value[0]);
return 0;
}
static int max9768_probe(struct snd_soc_component *component)
{
struct max9768 *max9768 = snd_soc_component_get_drvdata(component);
int ret;
if (max9768->flags & MAX9768_FLAG_CLASSIC_PWM) {
ret = regmap_write(max9768->regmap, MAX9768_CTRL,
MAX9768_CTRL_PWM);
if (ret)
return ret;
}
if (gpio_is_valid(max9768->mute_gpio)) {
ret = snd_soc_add_component_controls(component, max9768_mute,
ARRAY_SIZE(max9768_mute));
if (ret)
return ret;
}
return 0;
}
static int max9768_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max9768 *max9768;
struct max9768_pdata *pdata = client->dev.platform_data;
int err;
max9768 = devm_kzalloc(&client->dev, sizeof(*max9768), GFP_KERNEL);
if (!max9768)
return -ENOMEM;
if (pdata) {
err = devm_gpio_request_one(&client->dev, pdata->mute_gpio,
GPIOF_INIT_HIGH, "MAX9768 Mute");
max9768->mute_gpio = err ?: pdata->mute_gpio;
err = devm_gpio_request_one(&client->dev, pdata->shdn_gpio,
GPIOF_INIT_HIGH, "MAX9768 Shutdown");
max9768->shdn_gpio = err ?: pdata->shdn_gpio;
max9768->flags = pdata->flags;
} else {
max9768->shdn_gpio = -EINVAL;
max9768->mute_gpio = -EINVAL;
}
i2c_set_clientdata(client, max9768);
max9768->regmap = devm_regmap_init_i2c(client, &max9768_i2c_regmap_config);
if (IS_ERR(max9768->regmap))
return PTR_ERR(max9768->regmap);
return devm_snd_soc_register_component(&client->dev,
&max9768_component_driver, NULL, 0);
}
