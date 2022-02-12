static void hdlcd_crtc_cleanup(struct drm_crtc *crtc)
{
struct hdlcd_drm_private *hdlcd = crtc_to_hdlcd_priv(crtc);
hdlcd_write(hdlcd, HDLCD_REG_COMMAND, 0);
drm_crtc_cleanup(crtc);
}
static int hdlcd_set_pxl_fmt(struct drm_crtc *crtc)
{
unsigned int btpp;
struct hdlcd_drm_private *hdlcd = crtc_to_hdlcd_priv(crtc);
uint32_t pixel_format;
struct simplefb_format *format = NULL;
int i;
pixel_format = crtc->primary->state->fb->pixel_format;
for (i = 0; i < ARRAY_SIZE(supported_formats); i++) {
if (supported_formats[i].fourcc == pixel_format)
format = &supported_formats[i];
}
if (WARN_ON(!format))
return 0;
btpp = (format->bits_per_pixel + 7) / 8;
hdlcd_write(hdlcd, HDLCD_REG_PIXEL_FORMAT, (btpp - 1) << 3);
hdlcd_write(hdlcd, HDLCD_REG_RED_SELECT, format->red.offset |
#ifdef CONFIG_DRM_HDLCD_SHOW_UNDERRUN
0x00ff0000 |
#endif
((format->red.length & 0xf) << 8));
hdlcd_write(hdlcd, HDLCD_REG_GREEN_SELECT, format->green.offset |
((format->green.length & 0xf) << 8));
hdlcd_write(hdlcd, HDLCD_REG_BLUE_SELECT, format->blue.offset |
((format->blue.length & 0xf) << 8));
return 0;
}
static void hdlcd_crtc_mode_set_nofb(struct drm_crtc *crtc)
{
struct hdlcd_drm_private *hdlcd = crtc_to_hdlcd_priv(crtc);
struct drm_display_mode *m = &crtc->state->adjusted_mode;
struct videomode vm;
unsigned int polarities, err;
vm.vfront_porch = m->crtc_vsync_start - m->crtc_vdisplay;
vm.vback_porch = m->crtc_vtotal - m->crtc_vsync_end;
vm.vsync_len = m->crtc_vsync_end - m->crtc_vsync_start;
vm.hfront_porch = m->crtc_hsync_start - m->crtc_hdisplay;
vm.hback_porch = m->crtc_htotal - m->crtc_hsync_end;
vm.hsync_len = m->crtc_hsync_end - m->crtc_hsync_start;
polarities = HDLCD_POLARITY_DATAEN | HDLCD_POLARITY_DATA;
if (m->flags & DRM_MODE_FLAG_PHSYNC)
polarities |= HDLCD_POLARITY_HSYNC;
if (m->flags & DRM_MODE_FLAG_PVSYNC)
polarities |= HDLCD_POLARITY_VSYNC;
hdlcd_write(hdlcd, HDLCD_REG_BUS_OPTIONS,
HDLCD_BUS_MAX_OUTSTAND | HDLCD_BUS_BURST_16);
hdlcd_write(hdlcd, HDLCD_REG_V_DATA, m->crtc_vdisplay - 1);
hdlcd_write(hdlcd, HDLCD_REG_V_BACK_PORCH, vm.vback_porch - 1);
hdlcd_write(hdlcd, HDLCD_REG_V_FRONT_PORCH, vm.vfront_porch - 1);
hdlcd_write(hdlcd, HDLCD_REG_V_SYNC, vm.vsync_len - 1);
hdlcd_write(hdlcd, HDLCD_REG_H_DATA, m->crtc_hdisplay - 1);
hdlcd_write(hdlcd, HDLCD_REG_H_BACK_PORCH, vm.hback_porch - 1);
hdlcd_write(hdlcd, HDLCD_REG_H_FRONT_PORCH, vm.hfront_porch - 1);
hdlcd_write(hdlcd, HDLCD_REG_H_SYNC, vm.hsync_len - 1);
hdlcd_write(hdlcd, HDLCD_REG_POLARITIES, polarities);
err = hdlcd_set_pxl_fmt(crtc);
if (err)
return;
clk_set_rate(hdlcd->clk, m->crtc_clock * 1000);
}
static void hdlcd_crtc_enable(struct drm_crtc *crtc)
{
struct hdlcd_drm_private *hdlcd = crtc_to_hdlcd_priv(crtc);
clk_prepare_enable(hdlcd->clk);
hdlcd_crtc_mode_set_nofb(crtc);
hdlcd_write(hdlcd, HDLCD_REG_COMMAND, 1);
drm_crtc_vblank_on(crtc);
}
static void hdlcd_crtc_disable(struct drm_crtc *crtc)
{
struct hdlcd_drm_private *hdlcd = crtc_to_hdlcd_priv(crtc);
drm_crtc_vblank_off(crtc);
hdlcd_write(hdlcd, HDLCD_REG_COMMAND, 0);
clk_disable_unprepare(hdlcd->clk);
}
static int hdlcd_crtc_atomic_check(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct hdlcd_drm_private *hdlcd = crtc_to_hdlcd_priv(crtc);
struct drm_display_mode *mode = &state->adjusted_mode;
long rate, clk_rate = mode->clock * 1000;
rate = clk_round_rate(hdlcd->clk, clk_rate);
if (rate != clk_rate) {
return -EINVAL;
}
return 0;
}
static void hdlcd_crtc_atomic_begin(struct drm_crtc *crtc,
struct drm_crtc_state *state)
{
struct drm_pending_vblank_event *event = crtc->state->event;
if (event) {
crtc->state->event = NULL;
spin_lock_irq(&crtc->dev->event_lock);
if (drm_crtc_vblank_get(crtc) == 0)
drm_crtc_arm_vblank_event(crtc, event);
else
drm_crtc_send_vblank_event(crtc, event);
spin_unlock_irq(&crtc->dev->event_lock);
}
}
static int hdlcd_plane_atomic_check(struct drm_plane *plane,
struct drm_plane_state *state)
{
u32 src_w, src_h;
src_w = state->src_w >> 16;
src_h = state->src_h >> 16;
if ((src_w != state->crtc_w) || (src_h != state->crtc_h))
return -EINVAL;
return 0;
}
static void hdlcd_plane_atomic_update(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct hdlcd_drm_private *hdlcd;
struct drm_gem_cma_object *gem;
unsigned int depth, bpp;
u32 src_w, src_h, dest_w, dest_h;
dma_addr_t scanout_start;
if (!plane->state->fb)
return;
drm_fb_get_bpp_depth(plane->state->fb->pixel_format, &depth, &bpp);
src_w = plane->state->src_w >> 16;
src_h = plane->state->src_h >> 16;
dest_w = plane->state->crtc_w;
dest_h = plane->state->crtc_h;
gem = drm_fb_cma_get_gem_obj(plane->state->fb, 0);
scanout_start = gem->paddr + plane->state->fb->offsets[0] +
plane->state->crtc_y * plane->state->fb->pitches[0] +
plane->state->crtc_x * bpp / 8;
hdlcd = plane->dev->dev_private;
hdlcd_write(hdlcd, HDLCD_REG_FB_LINE_LENGTH, plane->state->fb->pitches[0]);
hdlcd_write(hdlcd, HDLCD_REG_FB_LINE_PITCH, plane->state->fb->pitches[0]);
hdlcd_write(hdlcd, HDLCD_REG_FB_LINE_COUNT, dest_h - 1);
hdlcd_write(hdlcd, HDLCD_REG_FB_BASE, scanout_start);
}
static void hdlcd_plane_destroy(struct drm_plane *plane)
{
drm_plane_helper_disable(plane);
drm_plane_cleanup(plane);
}
static struct drm_plane *hdlcd_plane_init(struct drm_device *drm)
{
struct hdlcd_drm_private *hdlcd = drm->dev_private;
struct drm_plane *plane = NULL;
u32 formats[ARRAY_SIZE(supported_formats)], i;
int ret;
plane = devm_kzalloc(drm->dev, sizeof(*plane), GFP_KERNEL);
if (!plane)
return ERR_PTR(-ENOMEM);
for (i = 0; i < ARRAY_SIZE(supported_formats); i++)
formats[i] = supported_formats[i].fourcc;
ret = drm_universal_plane_init(drm, plane, 0xff, &hdlcd_plane_funcs,
formats, ARRAY_SIZE(formats),
DRM_PLANE_TYPE_PRIMARY, NULL);
if (ret) {
devm_kfree(drm->dev, plane);
return ERR_PTR(ret);
}
drm_plane_helper_add(plane, &hdlcd_plane_helper_funcs);
hdlcd->plane = plane;
return plane;
}
int hdlcd_setup_crtc(struct drm_device *drm)
{
struct hdlcd_drm_private *hdlcd = drm->dev_private;
struct drm_plane *primary;
int ret;
primary = hdlcd_plane_init(drm);
if (IS_ERR(primary))
return PTR_ERR(primary);
ret = drm_crtc_init_with_planes(drm, &hdlcd->crtc, primary, NULL,
&hdlcd_crtc_funcs, NULL);
if (ret) {
hdlcd_plane_destroy(primary);
devm_kfree(drm->dev, primary);
return ret;
}
drm_crtc_helper_add(&hdlcd->crtc, &hdlcd_crtc_helper_funcs);
return 0;
}
