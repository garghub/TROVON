static int max16064_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return pmbus_do_probe(client, id, &max16064_info);
}
static int max16064_remove(struct i2c_client *client)
{
return pmbus_do_remove(client);
}
static int __init max16064_init(void)
{
return i2c_add_driver(&max16064_driver);
}
static void __exit max16064_exit(void)
{
i2c_del_driver(&max16064_driver);
}
