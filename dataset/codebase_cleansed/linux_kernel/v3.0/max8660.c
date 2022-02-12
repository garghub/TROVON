static int max8660_write(struct max8660 *max8660, u8 reg, u8 mask, u8 val)
{
static const u8 max8660_addresses[MAX8660_N_REGS] =
{ 0x10, 0x12, 0x20, 0x23, 0x24, 0x29, 0x2a, 0x32, 0x33, 0x39, 0x80 };
int ret;
u8 reg_val = (max8660->shadow_regs[reg] & mask) | val;
dev_vdbg(&max8660->client->dev, "Writing reg %02x with %02x\n",
max8660_addresses[reg], reg_val);
ret = i2c_smbus_write_byte_data(max8660->client,
max8660_addresses[reg], reg_val);
if (ret == 0)
max8660->shadow_regs[reg] = reg_val;
return ret;
}
static int max8660_dcdc_is_enabled(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 val = max8660->shadow_regs[MAX8660_OVER1];
u8 mask = (rdev_get_id(rdev) == MAX8660_V3) ? 1 : 4;
return !!(val & mask);
}
static int max8660_dcdc_enable(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 bit = (rdev_get_id(rdev) == MAX8660_V3) ? 1 : 4;
return max8660_write(max8660, MAX8660_OVER1, 0xff, bit);
}
static int max8660_dcdc_disable(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 mask = (rdev_get_id(rdev) == MAX8660_V3) ? ~1 : ~4;
return max8660_write(max8660, MAX8660_OVER1, mask, 0);
}
static int max8660_dcdc_list(struct regulator_dev *rdev, unsigned selector)
{
if (selector > MAX8660_DCDC_MAX_SEL)
return -EINVAL;
return MAX8660_DCDC_MIN_UV + selector * MAX8660_DCDC_STEP;
}
static int max8660_dcdc_get(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 reg = (rdev_get_id(rdev) == MAX8660_V3) ? MAX8660_ADTV2 : MAX8660_SDTV2;
u8 selector = max8660->shadow_regs[reg];
return MAX8660_DCDC_MIN_UV + selector * MAX8660_DCDC_STEP;
}
static int max8660_dcdc_set(struct regulator_dev *rdev, int min_uV, int max_uV,
unsigned int *s)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 reg, selector, bits;
int ret;
if (min_uV < MAX8660_DCDC_MIN_UV || min_uV > MAX8660_DCDC_MAX_UV)
return -EINVAL;
if (max_uV < MAX8660_DCDC_MIN_UV || max_uV > MAX8660_DCDC_MAX_UV)
return -EINVAL;
selector = (min_uV - (MAX8660_DCDC_MIN_UV - MAX8660_DCDC_STEP + 1))
/ MAX8660_DCDC_STEP;
*s = selector;
ret = max8660_dcdc_list(rdev, selector);
if (ret < 0 || ret > max_uV)
return -EINVAL;
reg = (rdev_get_id(rdev) == MAX8660_V3) ? MAX8660_ADTV2 : MAX8660_SDTV2;
ret = max8660_write(max8660, reg, 0, selector);
if (ret)
return ret;
bits = (rdev_get_id(rdev) == MAX8660_V3) ? 0x03 : 0x30;
return max8660_write(max8660, MAX8660_VCC1, 0xff, bits);
}
static int max8660_ldo5_list(struct regulator_dev *rdev, unsigned selector)
{
if (selector > MAX8660_LDO5_MAX_SEL)
return -EINVAL;
return MAX8660_LDO5_MIN_UV + selector * MAX8660_LDO5_STEP;
}
static int max8660_ldo5_get(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 selector = max8660->shadow_regs[MAX8660_MDTV2];
return MAX8660_LDO5_MIN_UV + selector * MAX8660_LDO5_STEP;
}
static int max8660_ldo5_set(struct regulator_dev *rdev, int min_uV, int max_uV,
unsigned int *s)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 selector;
int ret;
if (min_uV < MAX8660_LDO5_MIN_UV || min_uV > MAX8660_LDO5_MAX_UV)
return -EINVAL;
if (max_uV < MAX8660_LDO5_MIN_UV || max_uV > MAX8660_LDO5_MAX_UV)
return -EINVAL;
selector = (min_uV - (MAX8660_LDO5_MIN_UV - MAX8660_LDO5_STEP + 1))
/ MAX8660_LDO5_STEP;
ret = max8660_ldo5_list(rdev, selector);
if (ret < 0 || ret > max_uV)
return -EINVAL;
*s = selector;
ret = max8660_write(max8660, MAX8660_MDTV2, 0, selector);
if (ret)
return ret;
return max8660_write(max8660, MAX8660_VCC1, 0xff, 0xc0);
}
static int max8660_ldo67_is_enabled(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 val = max8660->shadow_regs[MAX8660_OVER2];
u8 mask = (rdev_get_id(rdev) == MAX8660_V6) ? 2 : 4;
return !!(val & mask);
}
static int max8660_ldo67_enable(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 bit = (rdev_get_id(rdev) == MAX8660_V6) ? 2 : 4;
return max8660_write(max8660, MAX8660_OVER2, 0xff, bit);
}
static int max8660_ldo67_disable(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 mask = (rdev_get_id(rdev) == MAX8660_V6) ? ~2 : ~4;
return max8660_write(max8660, MAX8660_OVER2, mask, 0);
}
static int max8660_ldo67_list(struct regulator_dev *rdev, unsigned selector)
{
if (selector > MAX8660_LDO67_MAX_SEL)
return -EINVAL;
return MAX8660_LDO67_MIN_UV + selector * MAX8660_LDO67_STEP;
}
static int max8660_ldo67_get(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 shift = (rdev_get_id(rdev) == MAX8660_V6) ? 0 : 4;
u8 selector = (max8660->shadow_regs[MAX8660_L12VCR] >> shift) & 0xf;
return MAX8660_LDO67_MIN_UV + selector * MAX8660_LDO67_STEP;
}
static int max8660_ldo67_set(struct regulator_dev *rdev, int min_uV,
int max_uV, unsigned int *s)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 selector;
int ret;
if (min_uV < MAX8660_LDO67_MIN_UV || min_uV > MAX8660_LDO67_MAX_UV)
return -EINVAL;
if (max_uV < MAX8660_LDO67_MIN_UV || max_uV > MAX8660_LDO67_MAX_UV)
return -EINVAL;
selector = (min_uV - (MAX8660_LDO67_MIN_UV - MAX8660_LDO67_STEP + 1))
/ MAX8660_LDO67_STEP;
ret = max8660_ldo67_list(rdev, selector);
if (ret < 0 || ret > max_uV)
return -EINVAL;
*s = selector;
if (rdev_get_id(rdev) == MAX8660_V6)
return max8660_write(max8660, MAX8660_L12VCR, 0xf0, selector);
else
return max8660_write(max8660, MAX8660_L12VCR, 0x0f, selector << 4);
}
static int __devinit max8660_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
struct regulator_dev **rdev;
struct max8660_platform_data *pdata = client->dev.platform_data;
struct max8660 *max8660;
int boot_on, i, id, ret = -EINVAL;
if (pdata->num_subdevs > MAX8660_V_END) {
dev_err(&client->dev, "Too many regulators found!\n");
goto out;
}
max8660 = kzalloc(sizeof(struct max8660) +
sizeof(struct regulator_dev *) * MAX8660_V_END,
GFP_KERNEL);
if (!max8660) {
ret = -ENOMEM;
goto out;
}
max8660->client = client;
rdev = max8660->rdev;
if (pdata->en34_is_high) {
max8660->shadow_regs[MAX8660_OVER1] = 5;
} else {
max8660_dcdc_ops.enable = max8660_dcdc_enable;
max8660_dcdc_ops.disable = max8660_dcdc_disable;
}
max8660->shadow_regs[MAX8660_ADTV1] =
max8660->shadow_regs[MAX8660_ADTV2] =
max8660->shadow_regs[MAX8660_SDTV1] =
max8660->shadow_regs[MAX8660_SDTV2] = 0x1b;
max8660->shadow_regs[MAX8660_MDTV1] =
max8660->shadow_regs[MAX8660_MDTV2] = 0x04;
for (i = 0; i < pdata->num_subdevs; i++) {
if (!pdata->subdevs[i].platform_data)
goto err_free;
boot_on = pdata->subdevs[i].platform_data->constraints.boot_on;
switch (pdata->subdevs[i].id) {
case MAX8660_V3:
if (boot_on)
max8660->shadow_regs[MAX8660_OVER1] |= 1;
break;
case MAX8660_V4:
if (boot_on)
max8660->shadow_regs[MAX8660_OVER1] |= 4;
break;
case MAX8660_V5:
break;
case MAX8660_V6:
if (boot_on)
max8660->shadow_regs[MAX8660_OVER2] |= 2;
break;
case MAX8660_V7:
if (!strcmp(i2c_id->name, "max8661")) {
dev_err(&client->dev, "Regulator not on this chip!\n");
goto err_free;
}
if (boot_on)
max8660->shadow_regs[MAX8660_OVER2] |= 4;
break;
default:
dev_err(&client->dev, "invalid regulator %s\n",
pdata->subdevs[i].name);
goto err_free;
}
}
for (i = 0; i < pdata->num_subdevs; i++) {
id = pdata->subdevs[i].id;
rdev[i] = regulator_register(&max8660_reg[id], &client->dev,
pdata->subdevs[i].platform_data,
max8660);
if (IS_ERR(rdev[i])) {
ret = PTR_ERR(rdev[i]);
dev_err(&client->dev, "failed to register %s\n",
max8660_reg[id].name);
goto err_unregister;
}
}
i2c_set_clientdata(client, max8660);
dev_info(&client->dev, "Maxim 8660/8661 regulator driver loaded\n");
return 0;
err_unregister:
while (--i >= 0)
regulator_unregister(rdev[i]);
err_free:
kfree(max8660);
out:
return ret;
}
static int __devexit max8660_remove(struct i2c_client *client)
{
struct max8660 *max8660 = i2c_get_clientdata(client);
int i;
for (i = 0; i < MAX8660_V_END; i++)
if (max8660->rdev[i])
regulator_unregister(max8660->rdev[i]);
kfree(max8660);
return 0;
}
static int __init max8660_init(void)
{
return i2c_add_driver(&max8660_driver);
}
static void __exit max8660_exit(void)
{
i2c_del_driver(&max8660_driver);
}
