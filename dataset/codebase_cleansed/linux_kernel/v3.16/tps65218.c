int tps65218_reg_read(struct tps65218 *tps, unsigned int reg,
unsigned int *val)
{
return regmap_read(tps->regmap, reg, val);
}
int tps65218_reg_write(struct tps65218 *tps, unsigned int reg,
unsigned int val, unsigned int level)
{
int ret;
unsigned int xor_reg_val;
switch (level) {
case TPS65218_PROTECT_NONE:
return regmap_write(tps->regmap, reg, val);
case TPS65218_PROTECT_L1:
xor_reg_val = reg ^ TPS65218_PASSWORD_REGS_UNLOCK;
ret = regmap_write(tps->regmap, TPS65218_REG_PASSWORD,
xor_reg_val);
if (ret < 0)
return ret;
return regmap_write(tps->regmap, reg, val);
default:
return -EINVAL;
}
}
static int tps65218_update_bits(struct tps65218 *tps, unsigned int reg,
unsigned int mask, unsigned int val, unsigned int level)
{
int ret;
unsigned int data;
ret = tps65218_reg_read(tps, reg, &data);
if (ret) {
dev_err(tps->dev, "Read from reg 0x%x failed\n", reg);
return ret;
}
data &= ~mask;
data |= val & mask;
mutex_lock(&tps->tps_lock);
ret = tps65218_reg_write(tps, reg, data, level);
if (ret)
dev_err(tps->dev, "Write for reg 0x%x failed\n", reg);
mutex_unlock(&tps->tps_lock);
return ret;
}
int tps65218_set_bits(struct tps65218 *tps, unsigned int reg,
unsigned int mask, unsigned int val, unsigned int level)
{
return tps65218_update_bits(tps, reg, mask, val, level);
}
int tps65218_clear_bits(struct tps65218 *tps, unsigned int reg,
unsigned int mask, unsigned int level)
{
return tps65218_update_bits(tps, reg, mask, 0, level);
}
static int tps65218_probe(struct i2c_client *client,
const struct i2c_device_id *ids)
{
struct tps65218 *tps;
const struct of_device_id *match;
int ret;
match = of_match_device(of_tps65218_match_table, &client->dev);
if (!match) {
dev_err(&client->dev,
"Failed to find matching dt id\n");
return -EINVAL;
}
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
i2c_set_clientdata(client, tps);
tps->dev = &client->dev;
tps->irq = client->irq;
tps->regmap = devm_regmap_init_i2c(client, &tps65218_regmap_config);
if (IS_ERR(tps->regmap)) {
ret = PTR_ERR(tps->regmap);
dev_err(tps->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
mutex_init(&tps->tps_lock);
ret = regmap_add_irq_chip(tps->regmap, tps->irq,
IRQF_ONESHOT, 0, &tps65218_irq_chip,
&tps->irq_data);
if (ret < 0)
return ret;
ret = of_platform_populate(client->dev.of_node, NULL, NULL,
&client->dev);
if (ret < 0)
goto err_irq;
return 0;
err_irq:
regmap_del_irq_chip(tps->irq, tps->irq_data);
return ret;
}
static int tps65218_remove(struct i2c_client *client)
{
struct tps65218 *tps = i2c_get_clientdata(client);
regmap_del_irq_chip(tps->irq, tps->irq_data);
return 0;
}
