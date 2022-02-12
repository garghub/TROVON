static int arizona_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct arizona *arizona;
const struct regmap_config *regmap_config = NULL;
unsigned long type;
int ret;
if (i2c->dev.of_node)
type = arizona_of_get_type(&i2c->dev);
else
type = id->driver_data;
switch (type) {
case WM5102:
if (IS_ENABLED(CONFIG_MFD_WM5102))
regmap_config = &wm5102_i2c_regmap;
break;
case WM5110:
case WM8280:
if (IS_ENABLED(CONFIG_MFD_WM5110))
regmap_config = &wm5110_i2c_regmap;
break;
case WM8997:
if (IS_ENABLED(CONFIG_MFD_WM8997))
regmap_config = &wm8997_i2c_regmap;
break;
case WM8998:
case WM1814:
if (IS_ENABLED(CONFIG_MFD_WM8998))
regmap_config = &wm8998_i2c_regmap;
break;
default:
dev_err(&i2c->dev, "Unknown device type %ld\n", type);
return -EINVAL;
}
if (!regmap_config) {
dev_err(&i2c->dev,
"No kernel support for device type %ld\n", type);
return -EINVAL;
}
arizona = devm_kzalloc(&i2c->dev, sizeof(*arizona), GFP_KERNEL);
if (arizona == NULL)
return -ENOMEM;
arizona->regmap = devm_regmap_init_i2c(i2c, regmap_config);
if (IS_ERR(arizona->regmap)) {
ret = PTR_ERR(arizona->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
arizona->type = type;
arizona->dev = &i2c->dev;
arizona->irq = i2c->irq;
return arizona_dev_init(arizona);
}
static int arizona_i2c_remove(struct i2c_client *i2c)
{
struct arizona *arizona = dev_get_drvdata(&i2c->dev);
arizona_dev_exit(arizona);
return 0;
}
