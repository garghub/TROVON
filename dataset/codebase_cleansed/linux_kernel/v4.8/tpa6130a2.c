static int tpa6130a2_power(struct tpa6130a2_data *data, bool enable)
{
int ret;
if (enable) {
ret = regulator_enable(data->supply);
if (ret != 0) {
dev_err(data->dev,
"Failed to enable supply: %d\n", ret);
return ret;
}
if (data->power_gpio >= 0)
gpio_set_value(data->power_gpio, 1);
} else {
if (data->power_gpio >= 0)
gpio_set_value(data->power_gpio, 0);
ret = regulator_disable(data->supply);
if (ret != 0) {
dev_err(data->dev,
"Failed to disable supply: %d\n", ret);
return ret;
}
regcache_mark_dirty(data->regmap);
}
return ret;
}
static int tpa6130a2_power_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kctrl, int event)
{
struct snd_soc_component *c = snd_soc_dapm_to_component(w->dapm);
struct tpa6130a2_data *data = snd_soc_component_get_drvdata(c);
int ret;
if (SND_SOC_DAPM_EVENT_ON(event)) {
tpa6130a2_power(data, true);
ret = regcache_sync(data->regmap);
if (ret < 0) {
dev_err(c->dev, "Failed to initialize chip\n");
tpa6130a2_power(data, false);
return ret;
}
} else {
tpa6130a2_power(data, false);
}
return 0;
}
static int tpa6130a2_component_probe(struct snd_soc_component *component)
{
struct tpa6130a2_data *data = snd_soc_component_get_drvdata(component);
if (data->id == TPA6140A2)
return snd_soc_add_component_controls(component,
tpa6140a2_controls, ARRAY_SIZE(tpa6140a2_controls));
else
return snd_soc_add_component_controls(component,
tpa6130a2_controls, ARRAY_SIZE(tpa6130a2_controls));
}
static int tpa6130a2_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev;
struct tpa6130a2_data *data;
struct tpa6130a2_platform_data *pdata = client->dev.platform_data;
struct device_node *np = client->dev.of_node;
const char *regulator;
unsigned int version;
int ret;
dev = &client->dev;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->dev = dev;
data->regmap = devm_regmap_init_i2c(client, &tpa6130a2_regmap_config);
if (IS_ERR(data->regmap))
return PTR_ERR(data->regmap);
if (pdata) {
data->power_gpio = pdata->power_gpio;
} else if (np) {
data->power_gpio = of_get_named_gpio(np, "power-gpio", 0);
} else {
dev_err(dev, "Platform data not set\n");
dump_stack();
return -ENODEV;
}
i2c_set_clientdata(client, data);
data->id = id->driver_data;
if (data->power_gpio >= 0) {
ret = devm_gpio_request(dev, data->power_gpio,
"tpa6130a2 enable");
if (ret < 0) {
dev_err(dev, "Failed to request power GPIO (%d)\n",
data->power_gpio);
return ret;
}
gpio_direction_output(data->power_gpio, 0);
}
switch (data->id) {
default:
dev_warn(dev, "Unknown TPA model (%d). Assuming 6130A2\n",
data->id);
case TPA6130A2:
regulator = "Vdd";
break;
case TPA6140A2:
regulator = "AVdd";
break;
}
data->supply = devm_regulator_get(dev, regulator);
if (IS_ERR(data->supply)) {
ret = PTR_ERR(data->supply);
dev_err(dev, "Failed to request supply: %d\n", ret);
return ret;
}
ret = tpa6130a2_power(data, true);
if (ret != 0)
return ret;
regmap_read(data->regmap, TPA6130A2_REG_VERSION, &version);
version &= TPA6130A2_VERSION_MASK;
if ((version != 1) && (version != 2))
dev_warn(dev, "UNTESTED version detected (%d)\n", version);
ret = tpa6130a2_power(data, false);
if (ret != 0)
return ret;
return devm_snd_soc_register_component(&client->dev,
&tpa6130a2_component_driver, NULL, 0);
}
