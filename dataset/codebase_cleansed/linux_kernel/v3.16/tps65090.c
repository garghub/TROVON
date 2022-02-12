static bool is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS65090_REG_INTR_MASK:
case TPS65090_REG_INTR_MASK2:
case TPS65090_REG_CG_CTRL0:
case TPS65090_REG_CG_CTRL1:
case TPS65090_REG_CG_CTRL2:
case TPS65090_REG_CG_CTRL3:
case TPS65090_REG_CG_CTRL4:
case TPS65090_REG_CG_CTRL5:
return false;
}
return true;
}
static int tps65090_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tps65090_platform_data *pdata = dev_get_platdata(&client->dev);
int irq_base = 0;
struct tps65090 *tps65090;
int ret;
if (!pdata && !client->dev.of_node) {
dev_err(&client->dev,
"tps65090 requires platform data or of_node\n");
return -EINVAL;
}
if (pdata)
irq_base = pdata->irq_base;
tps65090 = devm_kzalloc(&client->dev, sizeof(*tps65090), GFP_KERNEL);
if (!tps65090) {
dev_err(&client->dev, "mem alloc for tps65090 failed\n");
return -ENOMEM;
}
tps65090->dev = &client->dev;
i2c_set_clientdata(client, tps65090);
tps65090->rmap = devm_regmap_init_i2c(client, &tps65090_regmap_config);
if (IS_ERR(tps65090->rmap)) {
ret = PTR_ERR(tps65090->rmap);
dev_err(&client->dev, "regmap_init failed with err: %d\n", ret);
return ret;
}
if (client->irq) {
ret = regmap_add_irq_chip(tps65090->rmap, client->irq,
IRQF_ONESHOT | IRQF_TRIGGER_LOW, irq_base,
&tps65090_irq_chip, &tps65090->irq_data);
if (ret) {
dev_err(&client->dev,
"IRQ init failed with err: %d\n", ret);
return ret;
}
} else {
tps65090s[CHARGER].num_resources = 0;
}
ret = mfd_add_devices(tps65090->dev, -1, tps65090s,
ARRAY_SIZE(tps65090s), NULL,
0, regmap_irq_get_domain(tps65090->irq_data));
if (ret) {
dev_err(&client->dev, "add mfd devices failed with err: %d\n",
ret);
goto err_irq_exit;
}
return 0;
err_irq_exit:
if (client->irq)
regmap_del_irq_chip(client->irq, tps65090->irq_data);
return ret;
}
static int tps65090_i2c_remove(struct i2c_client *client)
{
struct tps65090 *tps65090 = i2c_get_clientdata(client);
mfd_remove_devices(tps65090->dev);
if (client->irq)
regmap_del_irq_chip(client->irq, tps65090->irq_data);
return 0;
}
static int __init tps65090_init(void)
{
return i2c_add_driver(&tps65090_driver);
}
static void __exit tps65090_exit(void)
{
i2c_del_driver(&tps65090_driver);
}
