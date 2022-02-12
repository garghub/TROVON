static inline struct vc4_plane_state *
to_vc4_plane_state(struct drm_plane_state *state)
{
return (struct vc4_plane_state *)state;
}
static const struct hvs_format *vc4_get_hvs_format(u32 drm_format)
{
unsigned i;
for (i = 0; i < ARRAY_SIZE(hvs_formats); i++) {
if (hvs_formats[i].drm == drm_format)
return &hvs_formats[i];
}
return NULL;
}
static bool plane_enabled(struct drm_plane_state *state)
{
return state->fb && state->crtc;
}
static struct drm_plane_state *vc4_plane_duplicate_state(struct drm_plane *plane)
{
struct vc4_plane_state *vc4_state;
if (WARN_ON(!plane->state))
return NULL;
vc4_state = kmemdup(plane->state, sizeof(*vc4_state), GFP_KERNEL);
if (!vc4_state)
return NULL;
__drm_atomic_helper_plane_duplicate_state(plane, &vc4_state->base);
if (vc4_state->dlist) {
vc4_state->dlist = kmemdup(vc4_state->dlist,
vc4_state->dlist_count * 4,
GFP_KERNEL);
if (!vc4_state->dlist) {
kfree(vc4_state);
return NULL;
}
vc4_state->dlist_size = vc4_state->dlist_count;
}
return &vc4_state->base;
}
static void vc4_plane_destroy_state(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
kfree(vc4_state->dlist);
__drm_atomic_helper_plane_destroy_state(plane, &vc4_state->base);
kfree(state);
}
static void vc4_plane_reset(struct drm_plane *plane)
{
struct vc4_plane_state *vc4_state;
WARN_ON(plane->state);
vc4_state = kzalloc(sizeof(*vc4_state), GFP_KERNEL);
if (!vc4_state)
return;
plane->state = &vc4_state->base;
vc4_state->base.plane = plane;
}
static void vc4_dlist_write(struct vc4_plane_state *vc4_state, u32 val)
{
if (vc4_state->dlist_count == vc4_state->dlist_size) {
u32 new_size = max(4u, vc4_state->dlist_count * 2);
u32 *new_dlist = kmalloc(new_size * 4, GFP_KERNEL);
if (!new_dlist)
return;
memcpy(new_dlist, vc4_state->dlist, vc4_state->dlist_count * 4);
kfree(vc4_state->dlist);
vc4_state->dlist = new_dlist;
vc4_state->dlist_size = new_size;
}
vc4_state->dlist[vc4_state->dlist_count++] = val;
}
static int vc4_plane_mode_set(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
struct drm_framebuffer *fb = state->fb;
struct drm_gem_cma_object *bo = drm_fb_cma_get_gem_obj(fb, 0);
u32 ctl0_offset = vc4_state->dlist_count;
const struct hvs_format *format = vc4_get_hvs_format(fb->pixel_format);
uint32_t offset = fb->offsets[0];
int crtc_x = state->crtc_x;
int crtc_y = state->crtc_y;
int crtc_w = state->crtc_w;
int crtc_h = state->crtc_h;
if (state->crtc_w << 16 != state->src_w ||
state->crtc_h << 16 != state->src_h) {
return -EINVAL;
}
if (crtc_x < 0) {
offset += drm_format_plane_cpp(fb->pixel_format, 0) * -crtc_x;
crtc_w += crtc_x;
crtc_x = 0;
}
if (crtc_y < 0) {
offset += fb->pitches[0] * -crtc_y;
crtc_h += crtc_y;
crtc_y = 0;
}
vc4_dlist_write(vc4_state,
SCALER_CTL0_VALID |
(format->pixel_order << SCALER_CTL0_ORDER_SHIFT) |
(format->hvs << SCALER_CTL0_PIXEL_FORMAT_SHIFT) |
SCALER_CTL0_UNITY);
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(0xff, SCALER_POS0_FIXED_ALPHA) |
VC4_SET_FIELD(crtc_x, SCALER_POS0_START_X) |
VC4_SET_FIELD(crtc_y, SCALER_POS0_START_Y));
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(format->has_alpha ?
SCALER_POS2_ALPHA_MODE_PIPELINE :
SCALER_POS2_ALPHA_MODE_FIXED,
SCALER_POS2_ALPHA_MODE) |
VC4_SET_FIELD(crtc_w, SCALER_POS2_WIDTH) |
VC4_SET_FIELD(crtc_h, SCALER_POS2_HEIGHT));
vc4_dlist_write(vc4_state, 0xc0c0c0c0);
vc4_state->pw0_offset = vc4_state->dlist_count;
vc4_dlist_write(vc4_state, bo->paddr + offset);
vc4_dlist_write(vc4_state, 0xc0c0c0c0);
vc4_dlist_write(vc4_state,
VC4_SET_FIELD(fb->pitches[0], SCALER_SRC_PITCH));
vc4_state->dlist[ctl0_offset] |=
VC4_SET_FIELD(vc4_state->dlist_count, SCALER_CTL0_SIZE);
return 0;
}
static int vc4_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
vc4_state->dlist_count = 0;
if (plane_enabled(state))
return vc4_plane_mode_set(plane, state);
else
return 0;
}
static void vc4_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *old_state)
{
}
u32 vc4_plane_write_dlist(struct drm_plane *plane, u32 __iomem *dlist)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(plane->state);
int i;
vc4_state->hw_dlist = dlist;
for (i = 0; i < vc4_state->dlist_count; i++)
writel(vc4_state->dlist[i], &dlist[i]);
return vc4_state->dlist_count;
}
u32 vc4_plane_dlist_size(struct drm_plane_state *state)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(state);
return vc4_state->dlist_count;
}
void vc4_plane_async_set_fb(struct drm_plane *plane, struct drm_framebuffer *fb)
{
struct vc4_plane_state *vc4_state = to_vc4_plane_state(plane->state);
struct drm_gem_cma_object *bo = drm_fb_cma_get_gem_obj(fb, 0);
uint32_t addr;
WARN_ON_ONCE(plane->state->crtc_x < 0 || plane->state->crtc_y < 0);
addr = bo->paddr + fb->offsets[0];
writel(addr, &vc4_state->hw_dlist[vc4_state->pw0_offset]);
vc4_state->dlist[vc4_state->pw0_offset] = addr;
}
static void vc4_plane_destroy(struct drm_plane *plane)
{
drm_plane_helper_disable(plane);
drm_plane_cleanup(plane);
}
struct drm_plane *vc4_plane_init(struct drm_device *dev,
enum drm_plane_type type)
{
struct drm_plane *plane = NULL;
struct vc4_plane *vc4_plane;
u32 formats[ARRAY_SIZE(hvs_formats)];
int ret = 0;
unsigned i;
vc4_plane = devm_kzalloc(dev->dev, sizeof(*vc4_plane),
GFP_KERNEL);
if (!vc4_plane) {
ret = -ENOMEM;
goto fail;
}
for (i = 0; i < ARRAY_SIZE(hvs_formats); i++)
formats[i] = hvs_formats[i].drm;
plane = &vc4_plane->base;
ret = drm_universal_plane_init(dev, plane, 0xff,
&vc4_plane_funcs,
formats, ARRAY_SIZE(formats),
type, NULL);
drm_plane_helper_add(plane, &vc4_plane_helper_funcs);
return plane;
fail:
if (plane)
vc4_plane_destroy(plane);
return ERR_PTR(ret);
}
