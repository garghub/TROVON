static int tps65086_probe(struct i2c_client *client,
const struct i2c_device_id *ids)
{
struct tps65086 *tps;
unsigned int version;
int ret;
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
i2c_set_clientdata(client, tps);
tps->dev = &client->dev;
tps->irq = client->irq;
tps->regmap = devm_regmap_init_i2c(client, &tps65086_regmap_config);
if (IS_ERR(tps->regmap)) {
dev_err(tps->dev, "Failed to initialize register map\n");
return PTR_ERR(tps->regmap);
}
ret = regmap_read(tps->regmap, TPS65086_DEVICEID, &version);
if (ret) {
dev_err(tps->dev, "Failed to read revision register\n");
return ret;
}
dev_info(tps->dev, "Device: TPS65086%01lX, OTP: %c, Rev: %ld\n",
(version & TPS65086_DEVICEID_PART_MASK),
(char)((version & TPS65086_DEVICEID_OTP_MASK) >> 4) + 'A',
(version & TPS65086_DEVICEID_REV_MASK) >> 6);
ret = regmap_add_irq_chip(tps->regmap, tps->irq, IRQF_ONESHOT, 0,
&tps65086_irq_chip, &tps->irq_data);
if (ret) {
dev_err(tps->dev, "Failed to register IRQ chip\n");
return ret;
}
ret = mfd_add_devices(tps->dev, PLATFORM_DEVID_AUTO, tps65086_cells,
ARRAY_SIZE(tps65086_cells), NULL, 0,
regmap_irq_get_domain(tps->irq_data));
if (ret) {
regmap_del_irq_chip(tps->irq, tps->irq_data);
return ret;
}
return 0;
}
static int tps65086_remove(struct i2c_client *client)
{
struct tps65086 *tps = i2c_get_clientdata(client);
regmap_del_irq_chip(tps->irq, tps->irq_data);
return 0;
}
