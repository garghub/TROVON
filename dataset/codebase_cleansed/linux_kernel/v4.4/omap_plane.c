static inline struct omap_plane_state *
to_omap_plane_state(struct drm_plane_state *state)
{
return container_of(state, struct omap_plane_state, base);
}
static int omap_plane_prepare_fb(struct drm_plane *plane,
const struct drm_plane_state *new_state)
{
if (!new_state->fb)
return 0;
return omap_framebuffer_pin(new_state->fb);
}
static void omap_plane_cleanup_fb(struct drm_plane *plane,
const struct drm_plane_state *old_state)
{
if (old_state->fb)
omap_framebuffer_unpin(old_state->fb);
}
static void omap_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
struct drm_plane_state *state = plane->state;
struct omap_plane_state *omap_state = to_omap_plane_state(state);
struct omap_overlay_info info;
struct omap_drm_window win;
int ret;
DBG("%s, crtc=%p fb=%p", omap_plane->name, state->crtc, state->fb);
memset(&info, 0, sizeof(info));
info.rotation_type = OMAP_DSS_ROT_DMA;
info.rotation = OMAP_DSS_ROT_0;
info.global_alpha = 0xff;
info.mirror = 0;
info.zorder = omap_state->zorder;
memset(&win, 0, sizeof(win));
win.rotation = state->rotation;
win.crtc_x = state->crtc_x;
win.crtc_y = state->crtc_y;
win.crtc_w = state->crtc_w;
win.crtc_h = state->crtc_h;
win.src_x = state->src_x >> 16;
win.src_y = state->src_y >> 16;
switch (state->rotation & DRM_ROTATE_MASK) {
case BIT(DRM_ROTATE_90):
case BIT(DRM_ROTATE_270):
win.src_w = state->src_h >> 16;
win.src_h = state->src_w >> 16;
break;
default:
win.src_w = state->src_w >> 16;
win.src_h = state->src_h >> 16;
break;
}
omap_framebuffer_update_scanout(state->fb, &win, &info);
DBG("%dx%d -> %dx%d (%d)", info.width, info.height,
info.out_width, info.out_height,
info.screen_width);
DBG("%d,%d %pad %pad", info.pos_x, info.pos_y,
&info.paddr, &info.p_uv_addr);
dispc_ovl_set_channel_out(omap_plane->id,
omap_crtc_channel(state->crtc));
ret = dispc_ovl_setup(omap_plane->id, &info, false,
omap_crtc_timings(state->crtc), false);
if (WARN_ON(ret)) {
dispc_ovl_enable(omap_plane->id, false);
return;
}
dispc_ovl_enable(omap_plane->id, true);
}
static void omap_plane_atomic_disable(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
struct omap_plane_state *omap_state = to_omap_plane_state(plane->state);
struct omap_plane *omap_plane = to_omap_plane(plane);
plane->state->rotation = BIT(DRM_ROTATE_0);
omap_state->zorder = plane->type == DRM_PLANE_TYPE_PRIMARY
? 0 : omap_plane->id;
dispc_ovl_enable(omap_plane->id, false);
}
static int omap_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct drm_crtc_state *crtc_state;
if (!state->crtc)
return 0;
crtc_state = drm_atomic_get_crtc_state(state->state, state->crtc);
if (IS_ERR(crtc_state))
return PTR_ERR(crtc_state);
if (state->crtc_x < 0 || state->crtc_y < 0)
return -EINVAL;
if (state->crtc_x + state->crtc_w > crtc_state->adjusted_mode.hdisplay)
return -EINVAL;
if (state->crtc_y + state->crtc_h > crtc_state->adjusted_mode.vdisplay)
return -EINVAL;
return 0;
}
static void omap_plane_reset(struct drm_plane *plane)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
struct omap_plane_state *omap_state;
if (plane->state && plane->state->fb)
drm_framebuffer_unreference(plane->state->fb);
kfree(plane->state);
plane->state = NULL;
omap_state = kzalloc(sizeof(*omap_state), GFP_KERNEL);
if (omap_state == NULL)
return;
omap_state->zorder = plane->type == DRM_PLANE_TYPE_PRIMARY
? 0 : omap_plane->id;
omap_state->base.rotation = BIT(DRM_ROTATE_0);
plane->state = &omap_state->base;
plane->state->plane = plane;
}
static void omap_plane_destroy(struct drm_plane *plane)
{
struct omap_plane *omap_plane = to_omap_plane(plane);
DBG("%s", omap_plane->name);
omap_irq_unregister(plane->dev, &omap_plane->error_irq);
drm_plane_cleanup(plane);
kfree(omap_plane);
}
void omap_plane_install_properties(struct drm_plane *plane,
struct drm_mode_object *obj)
{
struct drm_device *dev = plane->dev;
struct omap_drm_private *priv = dev->dev_private;
if (priv->has_dmm) {
struct drm_property *prop = dev->mode_config.rotation_property;
drm_object_attach_property(obj, prop, 0);
}
drm_object_attach_property(obj, priv->zorder_prop, 0);
}
static struct drm_plane_state *
omap_plane_atomic_duplicate_state(struct drm_plane *plane)
{
struct omap_plane_state *state;
struct omap_plane_state *copy;
if (WARN_ON(!plane->state))
return NULL;
state = to_omap_plane_state(plane->state);
copy = kmemdup(state, sizeof(*state), GFP_KERNEL);
if (copy == NULL)
return NULL;
__drm_atomic_helper_plane_duplicate_state(plane, &copy->base);
return &copy->base;
}
static void omap_plane_atomic_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
__drm_atomic_helper_plane_destroy_state(plane, state);
kfree(to_omap_plane_state(state));
}
static int omap_plane_atomic_set_property(struct drm_plane *plane,
struct drm_plane_state *state,
struct drm_property *property,
uint64_t val)
{
struct omap_drm_private *priv = plane->dev->dev_private;
struct omap_plane_state *omap_state = to_omap_plane_state(state);
if (property == priv->zorder_prop)
omap_state->zorder = val;
else
return -EINVAL;
return 0;
}
static int omap_plane_atomic_get_property(struct drm_plane *plane,
const struct drm_plane_state *state,
struct drm_property *property,
uint64_t *val)
{
struct omap_drm_private *priv = plane->dev->dev_private;
const struct omap_plane_state *omap_state =
container_of(state, const struct omap_plane_state, base);
if (property == priv->zorder_prop)
*val = omap_state->zorder;
else
return -EINVAL;
return 0;
}
static void omap_plane_error_irq(struct omap_drm_irq *irq, uint32_t irqstatus)
{
struct omap_plane *omap_plane =
container_of(irq, struct omap_plane, error_irq);
DRM_ERROR_RATELIMITED("%s: errors: %08x\n", omap_plane->name,
irqstatus);
}
struct drm_plane *omap_plane_init(struct drm_device *dev,
int id, enum drm_plane_type type)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_plane *plane;
struct omap_plane *omap_plane;
int ret;
DBG("%s: type=%d", plane_names[id], type);
omap_plane = kzalloc(sizeof(*omap_plane), GFP_KERNEL);
if (!omap_plane)
return ERR_PTR(-ENOMEM);
omap_plane->nformats = omap_framebuffer_get_formats(
omap_plane->formats, ARRAY_SIZE(omap_plane->formats),
dss_feat_get_supported_color_modes(id));
omap_plane->id = id;
omap_plane->name = plane_names[id];
plane = &omap_plane->base;
omap_plane->error_irq.irqmask = error_irqs[id];
omap_plane->error_irq.irq = omap_plane_error_irq;
omap_irq_register(dev, &omap_plane->error_irq);
ret = drm_universal_plane_init(dev, plane, (1 << priv->num_crtcs) - 1,
&omap_plane_funcs, omap_plane->formats,
omap_plane->nformats, type);
if (ret < 0)
goto error;
drm_plane_helper_add(plane, &omap_plane_helper_funcs);
omap_plane_install_properties(plane, &plane->base);
return plane;
error:
omap_irq_unregister(plane->dev, &omap_plane->error_irq);
kfree(omap_plane);
return NULL;
}
