static int write_regs(struct i2c_client *client, u8 *regs)
{
int i;
for (i = 0; regs[i] != 0xFF; i += 2)
if (i2c_smbus_write_byte_data(client, regs[i], regs[i + 1]) < 0)
return -1;
return 0;
}
static int wis_ov7640_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
client->flags = I2C_CLIENT_SCCB;
printk(KERN_DEBUG
"wis-ov7640: initializing OV7640 at address %d on %s\n",
client->addr, adapter->name);
if (write_regs(client, initial_registers) < 0) {
printk(KERN_ERR "wis-ov7640: error initializing OV7640\n");
return -ENODEV;
}
return 0;
}
static int wis_ov7640_remove(struct i2c_client *client)
{
return 0;
}
static int __init wis_ov7640_init(void)
{
return i2c_add_driver(&wis_ov7640_driver);
}
static void __exit wis_ov7640_cleanup(void)
{
i2c_del_driver(&wis_ov7640_driver);
}
