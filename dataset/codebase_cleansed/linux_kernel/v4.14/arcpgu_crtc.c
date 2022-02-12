static void arc_pgu_set_pxl_fmt(struct drm_crtc *crtc)
{
struct arcpgu_drm_private *arcpgu = crtc_to_arcpgu_priv(crtc);
const struct drm_framebuffer *fb = crtc->primary->state->fb;
uint32_t pixel_format = fb->format->format;
struct simplefb_format *format = NULL;
int i;
for (i = 0; i < ARRAY_SIZE(supported_formats); i++) {
if (supported_formats[i].fourcc == pixel_format)
format = &supported_formats[i];
}
if (WARN_ON(!format))
return;
if (format->fourcc == DRM_FORMAT_RGB888)
arc_pgu_write(arcpgu, ARCPGU_REG_CTRL,
arc_pgu_read(arcpgu, ARCPGU_REG_CTRL) |
ARCPGU_MODE_RGB888_MASK);
}
static enum drm_mode_status arc_pgu_crtc_mode_valid(struct drm_crtc *crtc,
const struct drm_display_mode *mode)
{
struct arcpgu_drm_private *arcpgu = crtc_to_arcpgu_priv(crtc);
long rate, clk_rate = mode->clock * 1000;
long diff = clk_rate / 200;
rate = clk_round_rate(arcpgu->clk, clk_rate);
if ((max(rate, clk_rate) - min(rate, clk_rate) < diff) && (rate > 0))
return MODE_OK;
return MODE_NOCLOCK;
}
static void arc_pgu_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct arcpgu_drm_private *arcpgu = crtc_to_arcpgu_priv(crtc);
struct drm_display_mode *m = &crtc->state->adjusted_mode;
u32 val;
arc_pgu_write(arcpgu, ARCPGU_REG_FMT,
ENCODE_PGU_XY(m->crtc_htotal, m->crtc_vtotal));
arc_pgu_write(arcpgu, ARCPGU_REG_HSYNC,
ENCODE_PGU_XY(m->crtc_hsync_start - m->crtc_hdisplay,
m->crtc_hsync_end - m->crtc_hdisplay));
arc_pgu_write(arcpgu, ARCPGU_REG_VSYNC,
ENCODE_PGU_XY(m->crtc_vsync_start - m->crtc_vdisplay,
m->crtc_vsync_end - m->crtc_vdisplay));
arc_pgu_write(arcpgu, ARCPGU_REG_ACTIVE,
ENCODE_PGU_XY(m->crtc_hblank_end - m->crtc_hblank_start,
m->crtc_vblank_end - m->crtc_vblank_start));
val = arc_pgu_read(arcpgu, ARCPGU_REG_CTRL);
if (m->flags & DRM_MODE_FLAG_PVSYNC)
val |= ARCPGU_CTRL_VS_POL_MASK << ARCPGU_CTRL_VS_POL_OFST;
else
val &= ~(ARCPGU_CTRL_VS_POL_MASK << ARCPGU_CTRL_VS_POL_OFST);
if (m->flags & DRM_MODE_FLAG_PHSYNC)
val |= ARCPGU_CTRL_HS_POL_MASK << ARCPGU_CTRL_HS_POL_OFST;
else
val &= ~(ARCPGU_CTRL_HS_POL_MASK << ARCPGU_CTRL_HS_POL_OFST);
arc_pgu_write(arcpgu, ARCPGU_REG_CTRL, val);
arc_pgu_write(arcpgu, ARCPGU_REG_STRIDE, 0);
arc_pgu_write(arcpgu, ARCPGU_REG_START_SET, 1);
arc_pgu_set_pxl_fmt(crtc);
clk_set_rate(arcpgu->clk, m->crtc_clock * 1000);
}
static void arc_pgu_crtc_atomic_enable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct arcpgu_drm_private *arcpgu = crtc_to_arcpgu_priv(crtc);
clk_prepare_enable(arcpgu->clk);
arc_pgu_write(arcpgu, ARCPGU_REG_CTRL,
arc_pgu_read(arcpgu, ARCPGU_REG_CTRL) |
ARCPGU_CTRL_ENABLE_MASK);
}
static void arc_pgu_crtc_atomic_disable(struct drm_crtc *crtc,
struct drm_crtc_state *old_state)
{
struct arcpgu_drm_private *arcpgu = crtc_to_arcpgu_priv(crtc);
if (!crtc->primary->fb)
return;
clk_disable_unprepare(arcpgu->clk);
arc_pgu_write(arcpgu, ARCPGU_REG_CTRL,
arc_pgu_read(arcpgu, ARCPGU_REG_CTRL) &
~ARCPGU_CTRL_ENABLE_MASK);
}
static void arc_pgu_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct drm_pending_vblank_event *event = crtc->state->event;
if (event) {
crtc->state->event = NULL;
spin_lock_irq(&crtc->dev->event_lock);
drm_crtc_send_vblank_event(crtc, event);
spin_unlock_irq(&crtc->dev->event_lock);
}
}
static void arc_pgu_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct arcpgu_drm_private *arcpgu;
struct drm_gem_cma_object *gem;
if (!plane->state->crtc || !plane->state->fb)
return;
arcpgu = crtc_to_arcpgu_priv(plane->state->crtc);
gem = drm_fb_cma_get_gem_obj(plane->state->fb, 0);
arc_pgu_write(arcpgu, ARCPGU_REG_BUF0_ADDR, gem->paddr);
}
static void arc_pgu_plane_destroy(struct drm_plane *plane)
{
drm_plane_helper_disable(plane);
drm_plane_cleanup(plane);
}
static struct drm_plane *arc_pgu_plane_init(struct drm_device *drm)
{
struct arcpgu_drm_private *arcpgu = drm->dev_private;
struct drm_plane *plane = NULL;
u32 formats[ARRAY_SIZE(supported_formats)], i;
int ret;
plane = devm_kzalloc(drm->dev, sizeof(*plane), GFP_KERNEL);
if (!plane)
return ERR_PTR(-ENOMEM);
for (i = 0; i < ARRAY_SIZE(supported_formats); i++)
formats[i] = supported_formats[i].fourcc;
ret = drm_universal_plane_init(drm, plane, 0xff, &arc_pgu_plane_funcs,
formats, ARRAY_SIZE(formats),
NULL,
DRM_PLANE_TYPE_PRIMARY, NULL);
if (ret)
return ERR_PTR(ret);
drm_plane_helper_add(plane, &arc_pgu_plane_helper_funcs);
arcpgu->plane = plane;
return plane;
}
int arc_pgu_setup_crtc(struct drm_device *drm)
{
struct arcpgu_drm_private *arcpgu = drm->dev_private;
struct drm_plane *primary;
int ret;
primary = arc_pgu_plane_init(drm);
if (IS_ERR(primary))
return PTR_ERR(primary);
ret = drm_crtc_init_with_planes(drm, &arcpgu->crtc, primary, NULL,
&arc_pgu_crtc_funcs, NULL);
if (ret) {
arc_pgu_plane_destroy(primary);
return ret;
}
drm_crtc_helper_add(&arcpgu->crtc, &arc_pgu_crtc_helper_funcs);
return 0;
}
