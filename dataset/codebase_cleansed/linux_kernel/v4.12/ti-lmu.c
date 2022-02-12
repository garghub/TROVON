static int ti_lmu_enable_hw(struct ti_lmu *lmu, enum ti_lmu_id id)
{
int ret;
if (gpio_is_valid(lmu->en_gpio)) {
ret = devm_gpio_request_one(lmu->dev, lmu->en_gpio,
GPIOF_OUT_INIT_HIGH, "lmu_hwen");
if (ret) {
dev_err(lmu->dev, "Can not request enable GPIO: %d\n",
ret);
return ret;
}
}
usleep_range(1000, 1500);
if (id == LM3631) {
return regmap_update_bits(lmu->regmap, LM3631_REG_DEVCTRL,
LM3631_LCD_EN_MASK,
LM3631_LCD_EN_MASK);
}
return 0;
}
static void ti_lmu_disable_hw(struct ti_lmu *lmu)
{
if (gpio_is_valid(lmu->en_gpio))
gpio_set_value(lmu->en_gpio, 0);
}
static int ti_lmu_probe(struct i2c_client *cl, const struct i2c_device_id *id)
{
struct device *dev = &cl->dev;
const struct of_device_id *match;
const struct ti_lmu_data *data;
struct regmap_config regmap_cfg;
struct ti_lmu *lmu;
int ret;
match = of_match_device(ti_lmu_of_match, dev);
if (!match)
return -ENODEV;
data = (struct ti_lmu_data *)match->data;
lmu = devm_kzalloc(dev, sizeof(*lmu), GFP_KERNEL);
if (!lmu)
return -ENOMEM;
lmu->dev = &cl->dev;
memset(&regmap_cfg, 0, sizeof(struct regmap_config));
regmap_cfg.reg_bits = 8;
regmap_cfg.val_bits = 8;
regmap_cfg.name = id->name;
regmap_cfg.max_register = data->max_register;
lmu->regmap = devm_regmap_init_i2c(cl, &regmap_cfg);
if (IS_ERR(lmu->regmap))
return PTR_ERR(lmu->regmap);
lmu->en_gpio = of_get_named_gpio(dev->of_node, "enable-gpios", 0);
ret = ti_lmu_enable_hw(lmu, id->driver_data);
if (ret)
return ret;
BLOCKING_INIT_NOTIFIER_HEAD(&lmu->notifier);
i2c_set_clientdata(cl, lmu);
return mfd_add_devices(lmu->dev, 0, data->cells,
data->num_cells, NULL, 0, NULL);
}
static int ti_lmu_remove(struct i2c_client *cl)
{
struct ti_lmu *lmu = i2c_get_clientdata(cl);
ti_lmu_disable_hw(lmu);
mfd_remove_devices(lmu->dev);
return 0;
}
