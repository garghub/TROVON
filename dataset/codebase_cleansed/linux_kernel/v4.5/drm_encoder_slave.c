int drm_i2c_encoder_init(struct drm_device *dev,
struct drm_encoder_slave *encoder,
struct i2c_adapter *adap,
const struct i2c_board_info *info)
{
struct module *module = NULL;
struct i2c_client *client;
struct drm_i2c_encoder_driver *encoder_drv;
int err = 0;
request_module("%s%s", I2C_MODULE_PREFIX, info->type);
client = i2c_new_device(adap, info);
if (!client) {
err = -ENOMEM;
goto fail;
}
if (!client->dev.driver) {
err = -ENODEV;
goto fail_unregister;
}
module = client->dev.driver->owner;
if (!try_module_get(module)) {
err = -ENODEV;
goto fail_unregister;
}
encoder->bus_priv = client;
encoder_drv = to_drm_i2c_encoder_driver(to_i2c_driver(client->dev.driver));
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
struct module *module = client->dev.driver->owner;
i2c_unregister_device(client);
encoder->bus_priv = NULL;
module_put(module);
}
static inline const struct drm_encoder_slave_funcs *
get_slave_funcs(struct drm_encoder *enc)
{
return to_encoder_slave(enc)->slave_funcs;
}
void drm_i2c_encoder_dpms(struct drm_encoder *encoder, int mode)
{
get_slave_funcs(encoder)->dpms(encoder, mode);
}
bool drm_i2c_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return get_slave_funcs(encoder)->mode_fixup(encoder, mode, adjusted_mode);
}
void drm_i2c_encoder_prepare(struct drm_encoder *encoder)
{
drm_i2c_encoder_dpms(encoder, DRM_MODE_DPMS_OFF);
}
void drm_i2c_encoder_commit(struct drm_encoder *encoder)
{
drm_i2c_encoder_dpms(encoder, DRM_MODE_DPMS_ON);
}
void drm_i2c_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
get_slave_funcs(encoder)->mode_set(encoder, mode, adjusted_mode);
}
enum drm_connector_status drm_i2c_encoder_detect(struct drm_encoder *encoder,
struct drm_connector *connector)
{
return get_slave_funcs(encoder)->detect(encoder, connector);
}
void drm_i2c_encoder_save(struct drm_encoder *encoder)
{
get_slave_funcs(encoder)->save(encoder);
}
void drm_i2c_encoder_restore(struct drm_encoder *encoder)
{
get_slave_funcs(encoder)->restore(encoder);
}
