static int i2c_reg_read(struct stmpe *stmpe, u8 reg)
{
struct i2c_client *i2c = stmpe->client;
return i2c_smbus_read_byte_data(i2c, reg);
}
static int i2c_reg_write(struct stmpe *stmpe, u8 reg, u8 val)
{
struct i2c_client *i2c = stmpe->client;
return i2c_smbus_write_byte_data(i2c, reg, val);
}
static int i2c_block_read(struct stmpe *stmpe, u8 reg, u8 length, u8 *values)
{
struct i2c_client *i2c = stmpe->client;
return i2c_smbus_read_i2c_block_data(i2c, reg, length, values);
}
static int i2c_block_write(struct stmpe *stmpe, u8 reg, u8 length,
const u8 *values)
{
struct i2c_client *i2c = stmpe->client;
return i2c_smbus_write_i2c_block_data(i2c, reg, length, values);
}
static int
stmpe_i2c_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
i2c_ci.data = (void *)id;
i2c_ci.irq = i2c->irq;
i2c_ci.client = i2c;
i2c_ci.dev = &i2c->dev;
return stmpe_probe(&i2c_ci, id->driver_data);
}
static int stmpe_i2c_remove(struct i2c_client *i2c)
{
struct stmpe *stmpe = dev_get_drvdata(&i2c->dev);
return stmpe_remove(stmpe);
}
static int __init stmpe_init(void)
{
return i2c_add_driver(&stmpe_i2c_driver);
}
static void __exit stmpe_exit(void)
{
i2c_del_driver(&stmpe_i2c_driver);
}
