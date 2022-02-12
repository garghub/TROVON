int drm_encoder_register_all(struct drm_device *dev)
{
struct drm_encoder *encoder;
int ret = 0;
drm_for_each_encoder(encoder, dev) {
if (encoder->funcs->late_register)
ret = encoder->funcs->late_register(encoder);
if (ret)
return ret;
}
return 0;
}
void drm_encoder_unregister_all(struct drm_device *dev)
{
struct drm_encoder *encoder;
drm_for_each_encoder(encoder, dev) {
if (encoder->funcs->early_unregister)
encoder->funcs->early_unregister(encoder);
}
}
int drm_encoder_init(struct drm_device *dev,
struct drm_encoder *encoder,
const struct drm_encoder_funcs *funcs,
int encoder_type, const char *name, ...)
{
int ret;
ret = drm_mode_object_add(dev, &encoder->base, DRM_MODE_OBJECT_ENCODER);
if (ret)
return ret;
encoder->dev = dev;
encoder->encoder_type = encoder_type;
encoder->funcs = funcs;
if (name) {
va_list ap;
va_start(ap, name);
encoder->name = kvasprintf(GFP_KERNEL, name, ap);
va_end(ap);
} else {
encoder->name = kasprintf(GFP_KERNEL, "%s-%d",
drm_encoder_enum_list[encoder_type].name,
encoder->base.id);
}
if (!encoder->name) {
ret = -ENOMEM;
goto out_put;
}
list_add_tail(&encoder->head, &dev->mode_config.encoder_list);
encoder->index = dev->mode_config.num_encoder++;
out_put:
if (ret)
drm_mode_object_unregister(dev, &encoder->base);
return ret;
}
void drm_encoder_cleanup(struct drm_encoder *encoder)
{
struct drm_device *dev = encoder->dev;
if (encoder->bridge) {
struct drm_bridge *bridge = encoder->bridge;
struct drm_bridge *next;
while (bridge) {
next = bridge->next;
drm_bridge_detach(bridge);
bridge = next;
}
}
drm_mode_object_unregister(dev, &encoder->base);
kfree(encoder->name);
list_del(&encoder->head);
dev->mode_config.num_encoder--;
memset(encoder, 0, sizeof(*encoder));
}
static struct drm_crtc *drm_encoder_get_crtc(struct drm_encoder *encoder)
{
struct drm_connector *connector;
struct drm_device *dev = encoder->dev;
bool uses_atomic = false;
struct drm_connector_list_iter conn_iter;
drm_connector_list_iter_begin(dev, &conn_iter);
drm_for_each_connector_iter(connector, &conn_iter) {
if (!connector->state)
continue;
uses_atomic = true;
if (connector->state->best_encoder != encoder)
continue;
drm_connector_list_iter_end(&conn_iter);
return connector->state->crtc;
}
drm_connector_list_iter_end(&conn_iter);
if (uses_atomic)
return NULL;
return encoder->crtc;
}
int drm_mode_getencoder(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_mode_get_encoder *enc_resp = data;
struct drm_encoder *encoder;
struct drm_crtc *crtc;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
encoder = drm_encoder_find(dev, enc_resp->encoder_id);
if (!encoder)
return -ENOENT;
drm_modeset_lock(&dev->mode_config.connection_mutex, NULL);
crtc = drm_encoder_get_crtc(encoder);
if (crtc)
enc_resp->crtc_id = crtc->base.id;
else
enc_resp->crtc_id = 0;
drm_modeset_unlock(&dev->mode_config.connection_mutex);
enc_resp->encoder_type = encoder->encoder_type;
enc_resp->encoder_id = encoder->base.id;
enc_resp->possible_crtcs = encoder->possible_crtcs;
enc_resp->possible_clones = encoder->possible_clones;
return 0;
}
