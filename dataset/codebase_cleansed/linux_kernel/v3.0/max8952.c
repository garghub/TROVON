static int max8952_read_reg(struct max8952_data *max8952, u8 reg)
{
int ret = i2c_smbus_read_byte_data(max8952->client, reg);
if (ret > 0)
ret &= 0xff;
return ret;
}
static int max8952_write_reg(struct max8952_data *max8952,
u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(max8952->client, reg, value);
}
static int max8952_voltage(struct max8952_data *max8952, u8 mode)
{
return (max8952->pdata->dvs_mode[mode] * 10 + 770) * 1000;
}
static int max8952_list_voltage(struct regulator_dev *rdev,
unsigned int selector)
{
struct max8952_data *max8952 = rdev_get_drvdata(rdev);
if (rdev_get_id(rdev) != 0)
return -EINVAL;
return max8952_voltage(max8952, selector);
}
static int max8952_is_enabled(struct regulator_dev *rdev)
{
struct max8952_data *max8952 = rdev_get_drvdata(rdev);
return max8952->en;
}
static int max8952_enable(struct regulator_dev *rdev)
{
struct max8952_data *max8952 = rdev_get_drvdata(rdev);
if (gpio_is_valid(max8952->pdata->gpio_en))
gpio_set_value(max8952->pdata->gpio_en, 1);
max8952->en = true;
return 0;
}
static int max8952_disable(struct regulator_dev *rdev)
{
struct max8952_data *max8952 = rdev_get_drvdata(rdev);
if (gpio_is_valid(max8952->pdata->gpio_en))
gpio_set_value(max8952->pdata->gpio_en, 0);
else
return -EPERM;
max8952->en = false;
return 0;
}
static int max8952_get_voltage(struct regulator_dev *rdev)
{
struct max8952_data *max8952 = rdev_get_drvdata(rdev);
u8 vid = 0;
if (max8952->vid0)
vid += 1;
if (max8952->vid1)
vid += 2;
return max8952_voltage(max8952, vid);
}
static int max8952_set_voltage(struct regulator_dev *rdev,
int min_uV, int max_uV, unsigned *selector)
{
struct max8952_data *max8952 = rdev_get_drvdata(rdev);
s8 vid = -1, i;
if (!gpio_is_valid(max8952->pdata->gpio_vid0) ||
!gpio_is_valid(max8952->pdata->gpio_vid1)) {
return -EPERM;
}
for (i = 0; i < MAX8952_NUM_DVS_MODE; i++) {
int volt = max8952_voltage(max8952, i);
if (volt <= max_uV && volt >= min_uV)
if (vid == -1 || max8952_voltage(max8952, vid) > volt)
vid = i;
}
if (vid >= 0 && vid < MAX8952_NUM_DVS_MODE) {
max8952->vid0 = (vid % 2 == 1);
max8952->vid1 = (((vid >> 1) % 2) == 1);
*selector = vid;
gpio_set_value(max8952->pdata->gpio_vid0, max8952->vid0);
gpio_set_value(max8952->pdata->gpio_vid1, max8952->vid1);
} else
return -EINVAL;
return 0;
}
static int __devinit max8952_pmic_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct max8952_platform_data *pdata = client->dev.platform_data;
struct max8952_data *max8952;
int ret = 0, err = 0;
if (!pdata) {
dev_err(&client->dev, "Require the platform data\n");
return -EINVAL;
}
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE))
return -EIO;
max8952 = kzalloc(sizeof(struct max8952_data), GFP_KERNEL);
if (!max8952)
return -ENOMEM;
max8952->client = client;
max8952->dev = &client->dev;
max8952->pdata = pdata;
mutex_init(&max8952->mutex);
max8952->rdev = regulator_register(&regulator, max8952->dev,
&pdata->reg_data, max8952);
if (IS_ERR(max8952->rdev)) {
ret = PTR_ERR(max8952->rdev);
dev_err(max8952->dev, "regulator init failed (%d)\n", ret);
goto err_reg;
}
max8952->en = !!(pdata->reg_data.constraints.boot_on);
max8952->vid0 = (pdata->default_mode % 2) == 1;
max8952->vid1 = ((pdata->default_mode >> 1) % 2) == 1;
if (gpio_is_valid(pdata->gpio_en)) {
if (!gpio_request(pdata->gpio_en, "MAX8952 EN"))
gpio_direction_output(pdata->gpio_en, max8952->en);
else
err = 1;
} else
err = 2;
if (err) {
dev_info(max8952->dev, "EN gpio invalid: assume that EN"
"is always High\n");
max8952->en = 1;
pdata->gpio_en = -1;
}
err = 0;
if (gpio_is_valid(pdata->gpio_vid0) &&
gpio_is_valid(pdata->gpio_vid1)) {
if (!gpio_request(pdata->gpio_vid0, "MAX8952 VID0"))
gpio_direction_output(pdata->gpio_vid0,
(pdata->default_mode) % 2);
else
err = 1;
if (!gpio_request(pdata->gpio_vid1, "MAX8952 VID1"))
gpio_direction_output(pdata->gpio_vid1,
(pdata->default_mode >> 1) % 2);
else {
if (!err)
gpio_free(pdata->gpio_vid0);
err = 2;
}
} else
err = 3;
if (err) {
dev_warn(max8952->dev, "VID0/1 gpio invalid: "
"DVS not available.\n");
max8952->vid0 = 0;
max8952->vid1 = 0;
pdata->gpio_vid0 = -1;
pdata->gpio_vid1 = -1;
max8952_write_reg(max8952, MAX8952_REG_CONTROL, 0x60);
dev_err(max8952->dev, "DVS modes disabled because VID0 and VID1"
" do not have proper controls.\n");
} else {
max8952_write_reg(max8952, MAX8952_REG_CONTROL, 0x0);
}
max8952_write_reg(max8952, MAX8952_REG_MODE0,
(max8952_read_reg(max8952,
MAX8952_REG_MODE0) & 0xC0) |
(pdata->dvs_mode[0] & 0x3F));
max8952_write_reg(max8952, MAX8952_REG_MODE1,
(max8952_read_reg(max8952,
MAX8952_REG_MODE1) & 0xC0) |
(pdata->dvs_mode[1] & 0x3F));
max8952_write_reg(max8952, MAX8952_REG_MODE2,
(max8952_read_reg(max8952,
MAX8952_REG_MODE2) & 0xC0) |
(pdata->dvs_mode[2] & 0x3F));
max8952_write_reg(max8952, MAX8952_REG_MODE3,
(max8952_read_reg(max8952,
MAX8952_REG_MODE3) & 0xC0) |
(pdata->dvs_mode[3] & 0x3F));
max8952_write_reg(max8952, MAX8952_REG_SYNC,
(max8952_read_reg(max8952, MAX8952_REG_SYNC) & 0x3F) |
((pdata->sync_freq & 0x3) << 6));
max8952_write_reg(max8952, MAX8952_REG_RAMP,
(max8952_read_reg(max8952, MAX8952_REG_RAMP) & 0x1F) |
((pdata->ramp_speed & 0x7) << 5));
i2c_set_clientdata(client, max8952);
return 0;
err_reg:
kfree(max8952);
return ret;
}
static int __devexit max8952_pmic_remove(struct i2c_client *client)
{
struct max8952_data *max8952 = i2c_get_clientdata(client);
struct max8952_platform_data *pdata = max8952->pdata;
struct regulator_dev *rdev = max8952->rdev;
regulator_unregister(rdev);
gpio_free(pdata->gpio_vid0);
gpio_free(pdata->gpio_vid1);
gpio_free(pdata->gpio_en);
kfree(max8952);
return 0;
}
static int __init max8952_pmic_init(void)
{
return i2c_add_driver(&max8952_pmic_driver);
}
static void __exit max8952_pmic_exit(void)
{
i2c_del_driver(&max8952_pmic_driver);
}
