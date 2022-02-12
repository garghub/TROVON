static int device_gpadc_init(struct pm80x_chip *chip,
struct pm80x_platform_data *pdata)
{
struct pm80x_subchip *subchip = chip->subchip;
struct regmap *map = subchip->regmap_gpadc;
int data = 0, mask = 0, ret = 0;
if (!map) {
dev_warn(chip->dev,
"Warning: gpadc regmap is not available!\n");
return -EINVAL;
}
ret = regmap_update_bits(map,
PM800_GPADC_MISC_CONFIG2,
PM800_GPADC_MISC_GPFSM_EN,
PM800_GPADC_MISC_GPFSM_EN);
if (ret < 0)
goto out;
ret = regmap_update_bits(map, PM800_GPADC_MEAS_EN1,
PM800_MEAS_EN1_VBAT, PM800_MEAS_EN1_VBAT);
if (ret < 0)
goto out;
ret = regmap_update_bits(map, PM800_GPADC_MEAS_EN2,
(PM800_MEAS_EN2_RFTMP | PM800_MEAS_GP0_EN),
(PM800_MEAS_EN2_RFTMP | PM800_MEAS_GP0_EN));
if (ret < 0)
goto out;
mask = (PM800_GPADC_GP_BIAS_EN0 | PM800_GPADC_GP_BIAS_EN1 |
PM800_GPADC_GP_BIAS_EN2 | PM800_GPADC_GP_BIAS_EN3);
if (pdata && (pdata->batt_det == 0))
data = (PM800_GPADC_GP_BIAS_EN0 | PM800_GPADC_GP_BIAS_EN1 |
PM800_GPADC_GP_BIAS_EN2 | PM800_GPADC_GP_BIAS_EN3);
else
data = (PM800_GPADC_GP_BIAS_EN0 | PM800_GPADC_GP_BIAS_EN2 |
PM800_GPADC_GP_BIAS_EN3);
ret = regmap_update_bits(map, PM800_GP_BIAS_ENA1, mask, data);
if (ret < 0)
goto out;
dev_info(chip->dev, "pm800 device_gpadc_init: Done\n");
return 0;
out:
dev_info(chip->dev, "pm800 device_gpadc_init: Failed!\n");
return ret;
}
static int device_irq_init_800(struct pm80x_chip *chip)
{
struct regmap *map = chip->regmap;
unsigned long flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
int data, mask, ret = -EINVAL;
if (!map || !chip->irq) {
dev_err(chip->dev, "incorrect parameters\n");
return -EINVAL;
}
mask =
PM800_WAKEUP2_INV_INT | PM800_WAKEUP2_INT_CLEAR |
PM800_WAKEUP2_INT_MASK;
data = PM800_WAKEUP2_INT_CLEAR;
ret = regmap_update_bits(map, PM800_WAKEUP2, mask, data);
if (ret < 0)
goto out;
ret =
regmap_add_irq_chip(chip->regmap, chip->irq, flags, -1,
chip->regmap_irq_chip, &chip->irq_data);
out:
return ret;
}
static void device_irq_exit_800(struct pm80x_chip *chip)
{
regmap_del_irq_chip(chip->irq, chip->irq_data);
}
static int pm800_pages_init(struct pm80x_chip *chip)
{
struct pm80x_subchip *subchip;
struct i2c_client *client = chip->client;
subchip = chip->subchip;
if (subchip->power_page_addr) {
subchip->power_page =
i2c_new_dummy(client->adapter, subchip->power_page_addr);
subchip->regmap_power =
devm_regmap_init_i2c(subchip->power_page,
&pm80x_regmap_config);
i2c_set_clientdata(subchip->power_page, chip);
} else
dev_info(chip->dev,
"PM800 block power 0x31: No power_page_addr\n");
if (subchip->gpadc_page_addr) {
subchip->gpadc_page = i2c_new_dummy(client->adapter,
subchip->gpadc_page_addr);
subchip->regmap_gpadc =
devm_regmap_init_i2c(subchip->gpadc_page,
&pm80x_regmap_config);
i2c_set_clientdata(subchip->gpadc_page, chip);
} else
dev_info(chip->dev,
"PM800 block GPADC 0x32: No gpadc_page_addr\n");
return 0;
}
static void pm800_pages_exit(struct pm80x_chip *chip)
{
struct pm80x_subchip *subchip;
regmap_exit(chip->regmap);
i2c_unregister_device(chip->client);
subchip = chip->subchip;
if (subchip->power_page) {
regmap_exit(subchip->regmap_power);
i2c_unregister_device(subchip->power_page);
}
if (subchip->gpadc_page) {
regmap_exit(subchip->regmap_gpadc);
i2c_unregister_device(subchip->gpadc_page);
}
}
static int device_800_init(struct pm80x_chip *chip,
struct pm80x_platform_data *pdata)
{
int ret, pmic_id;
unsigned int val;
ret = regmap_read(chip->regmap, PM800_CHIP_ID, &val);
if (ret < 0) {
dev_err(chip->dev, "Failed to read CHIP ID: %d\n", ret);
goto out;
}
pmic_id = val & PM80X_VERSION_MASK;
if ((pmic_id >= PM800_CHIP_A0) && (pmic_id <= PM800_CHIP_END)) {
chip->version = val;
dev_info(chip->dev,
"88PM80x:Marvell 88PM800 (ID:0x%x) detected\n", val);
} else {
dev_err(chip->dev,
"Failed to detect Marvell 88PM800:ChipID[0x%x]\n", val);
ret = -EINVAL;
goto out;
}
ret = regmap_read(chip->regmap, PM800_RTC_CONTROL, &val);
if (ret < 0) {
dev_err(chip->dev, "Failed to read RTC register: %d\n", ret);
goto out;
}
if (val & PM800_ALARM_WAKEUP) {
if (pdata && pdata->rtc)
pdata->rtc->rtc_wakeup = 1;
}
ret = device_gpadc_init(chip, pdata);
if (ret < 0) {
dev_err(chip->dev, "[%s]Failed to init gpadc\n", __func__);
goto out;
}
chip->regmap_irq_chip = &pm800_irq_chip;
ret = device_irq_init_800(chip);
if (ret < 0) {
dev_err(chip->dev, "[%s]Failed to init pm800 irq\n", __func__);
goto out;
}
ret =
mfd_add_devices(chip->dev, 0, &onkey_devs[0],
ARRAY_SIZE(onkey_devs), &onkey_resources[0], 0,
NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add onkey subdev\n");
goto out_dev;
} else
dev_info(chip->dev, "[%s]:Added mfd onkey_devs\n", __func__);
if (pdata && pdata->rtc) {
rtc_devs[0].platform_data = pdata->rtc;
rtc_devs[0].pdata_size = sizeof(struct pm80x_rtc_pdata);
ret = mfd_add_devices(chip->dev, 0, &rtc_devs[0],
ARRAY_SIZE(rtc_devs), NULL, 0, NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add rtc subdev\n");
goto out_dev;
} else
dev_info(chip->dev,
"[%s]:Added mfd rtc_devs\n", __func__);
}
return 0;
out_dev:
mfd_remove_devices(chip->dev);
device_irq_exit_800(chip);
out:
return ret;
}
static int pm800_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret = 0;
struct pm80x_chip *chip;
struct pm80x_platform_data *pdata = client->dev.platform_data;
struct pm80x_subchip *subchip;
ret = pm80x_init(client, id);
if (ret) {
dev_err(&client->dev, "pm800_init fail\n");
goto out_init;
}
chip = i2c_get_clientdata(client);
subchip =
devm_kzalloc(&client->dev, sizeof(struct pm80x_subchip),
GFP_KERNEL);
if (!subchip) {
ret = -ENOMEM;
goto err_subchip_alloc;
}
subchip->power_page_addr = pdata->power_page_addr;
subchip->gpadc_page_addr = pdata->gpadc_page_addr;
chip->subchip = subchip;
ret = device_800_init(chip, pdata);
if (ret) {
dev_err(chip->dev, "%s id 0x%x failed!\n", __func__, chip->id);
goto err_800_init;
}
ret = pm800_pages_init(chip);
if (ret) {
dev_err(&client->dev, "pm800_pages_init failed!\n");
goto err_page_init;
}
if (pdata->plat_config)
pdata->plat_config(chip, pdata);
err_page_init:
mfd_remove_devices(chip->dev);
device_irq_exit_800(chip);
err_800_init:
devm_kfree(&client->dev, subchip);
err_subchip_alloc:
pm80x_deinit(client);
out_init:
return ret;
}
static int pm800_remove(struct i2c_client *client)
{
struct pm80x_chip *chip = i2c_get_clientdata(client);
mfd_remove_devices(chip->dev);
device_irq_exit_800(chip);
pm800_pages_exit(chip);
devm_kfree(&client->dev, chip->subchip);
pm80x_deinit(client);
return 0;
}
static int __init pm800_i2c_init(void)
{
return i2c_add_driver(&pm800_driver);
}
static void __exit pm800_i2c_exit(void)
{
i2c_del_driver(&pm800_driver);
}
