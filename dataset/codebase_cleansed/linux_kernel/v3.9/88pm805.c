static int device_irq_init_805(struct pm80x_chip *chip)
{
struct regmap *map = chip->regmap;
unsigned long flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
int data, mask, ret = -EINVAL;
if (!map || !chip->irq) {
dev_err(chip->dev, "incorrect parameters\n");
return -EINVAL;
}
mask =
PM805_STATUS0_INT_CLEAR | PM805_STATUS0_INV_INT |
PM800_STATUS0_INT_MASK;
data = PM805_STATUS0_INT_CLEAR;
ret = regmap_update_bits(map, PM805_INT_STATUS0, mask, data);
msleep(1);
if (ret < 0)
goto out;
ret =
regmap_add_irq_chip(chip->regmap, chip->irq, flags, -1,
chip->regmap_irq_chip, &chip->irq_data);
out:
return ret;
}
static void device_irq_exit_805(struct pm80x_chip *chip)
{
regmap_del_irq_chip(chip->irq, chip->irq_data);
}
static int device_805_init(struct pm80x_chip *chip)
{
int ret = 0;
unsigned int val;
struct regmap *map = chip->regmap;
if (!map) {
dev_err(chip->dev, "regmap is invalid\n");
return -EINVAL;
}
ret = regmap_read(map, PM805_CHIP_ID, &val);
if (ret < 0) {
dev_err(chip->dev, "Failed to read CHIP ID: %d\n", ret);
goto out_irq_init;
}
chip->version = val;
chip->regmap_irq_chip = &pm805_irq_chip;
ret = device_irq_init_805(chip);
if (ret < 0) {
dev_err(chip->dev, "Failed to init pm805 irq!\n");
goto out_irq_init;
}
ret = mfd_add_devices(chip->dev, 0, &codec_devs[0],
ARRAY_SIZE(codec_devs), &codec_resources[0], 0,
NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add codec subdev\n");
goto out_codec;
} else
dev_info(chip->dev, "[%s]:Added mfd codec_devs\n", __func__);
return 0;
out_codec:
device_irq_exit_805(chip);
out_irq_init:
return ret;
}
static int pm805_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret = 0;
struct pm80x_chip *chip;
struct pm80x_platform_data *pdata = client->dev.platform_data;
ret = pm80x_init(client, id);
if (ret) {
dev_err(&client->dev, "pm805_init fail!\n");
goto out_init;
}
chip = i2c_get_clientdata(client);
ret = device_805_init(chip);
if (ret) {
dev_err(chip->dev, "%s id 0x%x failed!\n", __func__, chip->id);
goto err_805_init;
}
if (pdata->plat_config)
pdata->plat_config(chip, pdata);
err_805_init:
pm80x_deinit();
out_init:
return ret;
}
static int pm805_remove(struct i2c_client *client)
{
struct pm80x_chip *chip = i2c_get_clientdata(client);
mfd_remove_devices(chip->dev);
device_irq_exit_805(chip);
pm80x_deinit();
return 0;
}
static int __init pm805_i2c_init(void)
{
return i2c_add_driver(&pm805_driver);
}
static void __exit pm805_i2c_exit(void)
{
i2c_del_driver(&pm805_driver);
}
