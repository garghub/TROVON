static int keywest_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
i2c_set_clientdata(client, keywest_ctx);
return 0;
}
static int keywest_attach_adapter(struct i2c_adapter *adapter)
{
struct i2c_board_info info;
if (! keywest_ctx)
return -EINVAL;
if (strncmp(adapter->name, "mac-io", 6))
return 0;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "keywest", I2C_NAME_SIZE);
info.addr = keywest_ctx->addr;
keywest_ctx->client = i2c_new_device(adapter, &info);
if (!keywest_ctx->client)
return -ENODEV;
if (!keywest_ctx->client->driver) {
i2c_unregister_device(keywest_ctx->client);
keywest_ctx->client = NULL;
return -ENODEV;
}
list_add_tail(&keywest_ctx->client->detected,
&keywest_ctx->client->driver->clients);
return 0;
}
static int keywest_remove(struct i2c_client *client)
{
if (! keywest_ctx)
return 0;
if (client == keywest_ctx->client)
keywest_ctx->client = NULL;
return 0;
}
void snd_pmac_keywest_cleanup(struct pmac_keywest *i2c)
{
if (keywest_ctx && keywest_ctx == i2c) {
i2c_del_driver(&keywest_driver);
keywest_ctx = NULL;
}
}
int __devinit snd_pmac_tumbler_post_init(void)
{
int err;
if (!keywest_ctx || !keywest_ctx->client)
return -ENXIO;
if ((err = keywest_ctx->init_client(keywest_ctx)) < 0) {
snd_printk(KERN_ERR "tumbler: %i :cannot initialize the MCS\n", err);
return err;
}
return 0;
}
int __devinit snd_pmac_keywest_init(struct pmac_keywest *i2c)
{
int err;
if (keywest_ctx)
return -EBUSY;
keywest_ctx = i2c;
if ((err = i2c_add_driver(&keywest_driver))) {
snd_printk(KERN_ERR "cannot register keywest i2c driver\n");
return err;
}
return 0;
}
