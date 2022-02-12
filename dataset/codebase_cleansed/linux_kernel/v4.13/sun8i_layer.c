static void sun8i_mixer_layer_atomic_disable(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct sun8i_layer *layer = plane_to_sun8i_layer(plane);
struct sun8i_mixer *mixer = layer->mixer;
sun8i_mixer_layer_enable(mixer, layer->id, false);
}
static void sun8i_mixer_layer_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct sun8i_layer *layer = plane_to_sun8i_layer(plane);
struct sun8i_mixer *mixer = layer->mixer;
sun8i_mixer_update_layer_coord(mixer, layer->id, plane);
sun8i_mixer_update_layer_formats(mixer, layer->id, plane);
sun8i_mixer_update_layer_buffer(mixer, layer->id, plane);
sun8i_mixer_layer_enable(mixer, layer->id, true);
}
static struct sun8i_layer *sun8i_layer_init_one(struct drm_device *drm,
struct sun8i_mixer *mixer,
const struct sun8i_plane_desc *plane)
{
struct sun8i_layer *layer;
int ret;
layer = devm_kzalloc(drm->dev, sizeof(*layer), GFP_KERNEL);
if (!layer)
return ERR_PTR(-ENOMEM);
ret = drm_universal_plane_init(drm, &layer->plane, 0,
&sun8i_mixer_layer_funcs,
plane->formats, plane->nformats,
plane->type, NULL);
if (ret) {
dev_err(drm->dev, "Couldn't initialize layer\n");
return ERR_PTR(ret);
}
drm_plane_helper_add(&layer->plane,
&sun8i_mixer_layer_helper_funcs);
layer->mixer = mixer;
return layer;
}
struct drm_plane **sun8i_layers_init(struct drm_device *drm,
struct sunxi_engine *engine)
{
struct drm_plane **planes;
struct sun8i_mixer *mixer = engine_to_sun8i_mixer(engine);
int i;
planes = devm_kcalloc(drm->dev, ARRAY_SIZE(sun8i_mixer_planes) + 1,
sizeof(*planes), GFP_KERNEL);
if (!planes)
return ERR_PTR(-ENOMEM);
for (i = 0; i < ARRAY_SIZE(sun8i_mixer_planes); i++) {
const struct sun8i_plane_desc *plane = &sun8i_mixer_planes[i];
struct sun8i_layer *layer;
layer = sun8i_layer_init_one(drm, mixer, plane);
if (IS_ERR(layer)) {
dev_err(drm->dev, "Couldn't initialize %s plane\n",
i ? "overlay" : "primary");
return ERR_CAST(layer);
};
layer->id = i;
planes[i] = &layer->plane;
};
return planes;
}
