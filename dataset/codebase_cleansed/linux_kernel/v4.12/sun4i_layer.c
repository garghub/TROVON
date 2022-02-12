static int sun4i_backend_layer_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
return 0;
}
static void sun4i_backend_layer_atomic_disable(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct sun4i_layer *layer = plane_to_sun4i_layer(plane);
struct sun4i_backend *backend = layer->backend;
sun4i_backend_layer_enable(backend, layer->id, false);
}
static void sun4i_backend_layer_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct sun4i_layer *layer = plane_to_sun4i_layer(plane);
struct sun4i_backend *backend = layer->backend;
sun4i_backend_update_layer_coord(backend, layer->id, plane);
sun4i_backend_update_layer_formats(backend, layer->id, plane);
sun4i_backend_update_layer_buffer(backend, layer->id, plane);
sun4i_backend_layer_enable(backend, layer->id, true);
}
static struct sun4i_layer *sun4i_layer_init_one(struct drm_device *drm,
struct sun4i_backend *backend,
const struct sun4i_plane_desc *plane)
{
struct sun4i_layer *layer;
int ret;
layer = devm_kzalloc(drm->dev, sizeof(*layer), GFP_KERNEL);
if (!layer)
return ERR_PTR(-ENOMEM);
ret = drm_universal_plane_init(drm, &layer->plane, 0,
&sun4i_backend_layer_funcs,
plane->formats, plane->nformats,
plane->type, NULL);
if (ret) {
dev_err(drm->dev, "Couldn't initialize layer\n");
return ERR_PTR(ret);
}
drm_plane_helper_add(&layer->plane,
&sun4i_backend_layer_helper_funcs);
layer->backend = backend;
return layer;
}
struct sun4i_layer **sun4i_layers_init(struct drm_device *drm,
struct sun4i_backend *backend)
{
struct sun4i_layer **layers;
int i;
layers = devm_kcalloc(drm->dev, ARRAY_SIZE(sun4i_backend_planes) + 1,
sizeof(*layers), GFP_KERNEL);
if (!layers)
return ERR_PTR(-ENOMEM);
for (i = 0; i < ARRAY_SIZE(sun4i_backend_planes); i++) {
const struct sun4i_plane_desc *plane = &sun4i_backend_planes[i];
struct sun4i_layer *layer;
layer = sun4i_layer_init_one(drm, backend, plane);
if (IS_ERR(layer)) {
dev_err(drm->dev, "Couldn't initialize %s plane\n",
i ? "overlay" : "primary");
return ERR_CAST(layer);
};
DRM_DEBUG_DRIVER("Assigning %s plane to pipe %d\n",
i ? "overlay" : "primary", plane->pipe);
regmap_update_bits(backend->regs, SUN4I_BACKEND_ATTCTL_REG0(i),
SUN4I_BACKEND_ATTCTL_REG0_LAY_PIPESEL_MASK,
SUN4I_BACKEND_ATTCTL_REG0_LAY_PIPESEL(plane->pipe));
layer->id = i;
layers[i] = layer;
};
return layers;
}
