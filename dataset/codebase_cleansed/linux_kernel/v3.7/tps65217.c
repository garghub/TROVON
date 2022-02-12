int tps65217_reg_read(struct tps65217 *tps, unsigned int reg,
unsigned int *val)
{
return regmap_read(tps->regmap, reg, val);
}
int tps65217_reg_write(struct tps65217 *tps, unsigned int reg,
unsigned int val, unsigned int level)
{
int ret;
unsigned int xor_reg_val;
switch (level) {
case TPS65217_PROTECT_NONE:
return regmap_write(tps->regmap, reg, val);
case TPS65217_PROTECT_L1:
xor_reg_val = reg ^ TPS65217_PASSWORD_REGS_UNLOCK;
ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
xor_reg_val);
if (ret < 0)
return ret;
return regmap_write(tps->regmap, reg, val);
case TPS65217_PROTECT_L2:
xor_reg_val = reg ^ TPS65217_PASSWORD_REGS_UNLOCK;
ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
xor_reg_val);
if (ret < 0)
return ret;
ret = regmap_write(tps->regmap, reg, val);
if (ret < 0)
return ret;
ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
xor_reg_val);
if (ret < 0)
return ret;
return regmap_write(tps->regmap, reg, val);
default:
return -EINVAL;
}
}
static int tps65217_update_bits(struct tps65217 *tps, unsigned int reg,
unsigned int mask, unsigned int val, unsigned int level)
{
int ret;
unsigned int data;
ret = tps65217_reg_read(tps, reg, &data);
if (ret) {
dev_err(tps->dev, "Read from reg 0x%x failed\n", reg);
return ret;
}
data &= ~mask;
data |= val & mask;
ret = tps65217_reg_write(tps, reg, data, level);
if (ret)
dev_err(tps->dev, "Write for reg 0x%x failed\n", reg);
return ret;
}
int tps65217_set_bits(struct tps65217 *tps, unsigned int reg,
unsigned int mask, unsigned int val, unsigned int level)
{
return tps65217_update_bits(tps, reg, mask, val, level);
}
int tps65217_clear_bits(struct tps65217 *tps, unsigned int reg,
unsigned int mask, unsigned int level)
{
return tps65217_update_bits(tps, reg, mask, 0, level);
}
static int __devinit tps65217_probe(struct i2c_client *client,
const struct i2c_device_id *ids)
{
struct tps65217 *tps;
unsigned int version;
unsigned int chip_id = ids->driver_data;
const struct of_device_id *match;
int ret;
if (client->dev.of_node) {
match = of_match_device(tps65217_of_match, &client->dev);
if (!match) {
dev_err(&client->dev,
"Failed to find matching dt id\n");
return -EINVAL;
}
chip_id = (unsigned int)match->data;
}
if (!chip_id) {
dev_err(&client->dev, "id is null.\n");
return -ENODEV;
}
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
i2c_set_clientdata(client, tps);
tps->dev = &client->dev;
tps->id = chip_id;
tps->regmap = devm_regmap_init_i2c(client, &tps65217_regmap_config);
if (IS_ERR(tps->regmap)) {
ret = PTR_ERR(tps->regmap);
dev_err(tps->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = mfd_add_devices(tps->dev, -1, tps65217s,
ARRAY_SIZE(tps65217s), NULL, 0, NULL);
if (ret < 0) {
dev_err(tps->dev, "mfd_add_devices failed: %d\n", ret);
return ret;
}
ret = tps65217_reg_read(tps, TPS65217_REG_CHIPID, &version);
if (ret < 0) {
dev_err(tps->dev, "Failed to read revision register: %d\n",
ret);
return ret;
}
dev_info(tps->dev, "TPS65217 ID %#x version 1.%d\n",
(version & TPS65217_CHIPID_CHIP_MASK) >> 4,
version & TPS65217_CHIPID_REV_MASK);
return 0;
}
static int __devexit tps65217_remove(struct i2c_client *client)
{
struct tps65217 *tps = i2c_get_clientdata(client);
mfd_remove_devices(tps->dev);
return 0;
}
static int __init tps65217_init(void)
{
return i2c_add_driver(&tps65217_driver);
}
static void __exit tps65217_exit(void)
{
i2c_del_driver(&tps65217_driver);
}
