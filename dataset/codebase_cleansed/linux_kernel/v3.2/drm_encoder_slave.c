int drm_i2c_encoder_init(struct drm_device *dev,
struct drm_encoder_slave *encoder,
struct i2c_adapter *adap,
const struct i2c_board_info *info)
{
char modalias[sizeof(I2C_MODULE_PREFIX)
+ I2C_NAME_SIZE];
struct module *module = NULL;
struct i2c_client *client;
struct drm_i2c_encoder_driver *encoder_drv;
int err = 0;
snprintf(modalias, sizeof(modalias),
"%s%s", I2C_MODULE_PREFIX, info->type);
request_module(modalias);
client = i2c_new_device(adap, info);
if (!client) {
err = -ENOMEM;
goto fail;
}
if (!client->driver) {
err = -ENODEV;
goto fail_unregister;
}
module = client->driver->driver.owner;
if (!try_module_get(module)) {
err = -ENODEV;
goto fail_unregister;
}
encoder->bus_priv = client;
encoder_drv = to_drm_i2c_encoder_driver(client->driver);
err = encoder_drv->encoder_init(client, dev, encoder);
if (err)
goto fail_unregister;
if (info->platform_data)
encoder->slave_funcs->set_config(&encoder->base,
info->platform_data);
return 0;
fail_unregister:
i2c_unregister_device(client);
module_put(module);
fail:
return err;
}
void drm_i2c_encoder_destroy(struct drm_encoder *drm_encoder)
{
struct drm_encoder_slave *encoder = to_encoder_slave(drm_encoder);
struct i2c_client *client = drm_i2c_encoder_get_client(drm_encoder);
struct module *module = client->driver->driver.owner;
i2c_unregister_device(client);
encoder->bus_priv = NULL;
module_put(module);
}
