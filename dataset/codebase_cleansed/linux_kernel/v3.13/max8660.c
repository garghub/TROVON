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
static int max8660_dcdc_get_voltage_sel(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 reg = (rdev_get_id(rdev) == MAX8660_V3) ? MAX8660_ADTV2 : MAX8660_SDTV2;
u8 selector = max8660->shadow_regs[reg];
return selector;
}
static int max8660_dcdc_set_voltage_sel(struct regulator_dev *rdev,
unsigned int selector)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 reg, bits;
int ret;
reg = (rdev_get_id(rdev) == MAX8660_V3) ? MAX8660_ADTV2 : MAX8660_SDTV2;
ret = max8660_write(max8660, reg, 0, selector);
if (ret)
return ret;
bits = (rdev_get_id(rdev) == MAX8660_V3) ? 0x03 : 0x30;
return max8660_write(max8660, MAX8660_VCC1, 0xff, bits);
}
static int max8660_ldo5_get_voltage_sel(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 selector = max8660->shadow_regs[MAX8660_MDTV2];
return selector;
}
static int max8660_ldo5_set_voltage_sel(struct regulator_dev *rdev,
unsigned int selector)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
int ret;
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
static int max8660_ldo67_get_voltage_sel(struct regulator_dev *rdev)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
u8 shift = (rdev_get_id(rdev) == MAX8660_V6) ? 0 : 4;
u8 selector = (max8660->shadow_regs[MAX8660_L12VCR] >> shift) & 0xf;
return selector;
}
static int max8660_ldo67_set_voltage_sel(struct regulator_dev *rdev,
unsigned int selector)
{
struct max8660 *max8660 = rdev_get_drvdata(rdev);
if (rdev_get_id(rdev) == MAX8660_V6)
return max8660_write(max8660, MAX8660_L12VCR, 0xf0, selector);
else
return max8660_write(max8660, MAX8660_L12VCR, 0x0f,
selector << 4);
}
static int max8660_pdata_from_dt(struct device *dev,
struct device_node **of_node,
struct max8660_platform_data *pdata)
{
int matched, i;
struct device_node *np;
struct max8660_subdev_data *sub;
struct of_regulator_match rmatch[ARRAY_SIZE(max8660_reg)];
np = of_find_node_by_name(dev->of_node, "regulators");
if (!np) {
dev_err(dev, "missing 'regulators' subnode in DT\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(rmatch); i++)
rmatch[i].name = max8660_reg[i].name;
matched = of_regulator_match(dev, np, rmatch, ARRAY_SIZE(rmatch));
if (matched <= 0)
return matched;
pdata->subdevs = devm_kzalloc(dev, sizeof(struct max8660_subdev_data) *
matched, GFP_KERNEL);
if (!pdata->subdevs)
return -ENOMEM;
pdata->num_subdevs = matched;
sub = pdata->subdevs;
for (i = 0; i < matched; i++) {
sub->id = i;
sub->name = rmatch[i].name;
sub->platform_data = rmatch[i].init_data;
of_node[i] = rmatch[i].of_node;
sub++;
}
return 0;
}
static inline int max8660_pdata_from_dt(struct device *dev,
struct device_node **of_node,
struct max8660_platform_data *pdata)
{
return 0;
}
static int max8660_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
struct regulator_dev **rdev;
struct device *dev = &client->dev;
struct max8660_platform_data *pdata = dev_get_platdata(dev);
struct regulator_config config = { };
struct max8660 *max8660;
int boot_on, i, id, ret = -EINVAL;
struct device_node *of_node[MAX8660_V_END];
unsigned long type;
if (dev->of_node && !pdata) {
const struct of_device_id *id;
struct max8660_platform_data pdata_of;
id = of_match_device(of_match_ptr(max8660_dt_ids), dev);
if (!id)
return -ENODEV;
ret = max8660_pdata_from_dt(dev, of_node, &pdata_of);
if (ret < 0)
return ret;
pdata = &pdata_of;
type = (unsigned long) id->data;
} else {
type = i2c_id->driver_data;
memset(of_node, 0, sizeof(of_node));
}
if (pdata->num_subdevs > MAX8660_V_END) {
dev_err(dev, "Too many regulators found!\n");
return -EINVAL;
}
max8660 = devm_kzalloc(dev, sizeof(struct max8660) +
sizeof(struct regulator_dev *) * MAX8660_V_END,
GFP_KERNEL);
if (!max8660)
return -ENOMEM;
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
return ret;
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
if (type == MAX8661) {
dev_err(dev, "Regulator not on this chip!\n");
return -EINVAL;
}
if (boot_on)
max8660->shadow_regs[MAX8660_OVER2] |= 4;
break;
default:
dev_err(dev, "invalid regulator %s\n",
pdata->subdevs[i].name);
return ret;
}
}
for (i = 0; i < pdata->num_subdevs; i++) {
id = pdata->subdevs[i].id;
config.dev = dev;
config.init_data = pdata->subdevs[i].platform_data;
config.of_node = of_node[i];
config.driver_data = max8660;
rdev[i] = devm_regulator_register(&client->dev,
&max8660_reg[id], &config);
if (IS_ERR(rdev[i])) {
ret = PTR_ERR(rdev[i]);
dev_err(&client->dev, "failed to register %s\n",
max8660_reg[id].name);
return PTR_ERR(rdev[i]);
}
}
i2c_set_clientdata(client, max8660);
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
