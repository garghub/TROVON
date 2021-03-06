static char *udl_set_register(char *buf, u8 reg, u8 val)
{
*buf++ = 0xAF;
*buf++ = 0x20;
*buf++ = reg;
*buf++ = val;
return buf;
}
static char *udl_vidreg_lock(char *buf)
{
return udl_set_register(buf, 0xFF, 0x00);
}
static char *udl_vidreg_unlock(char *buf)
{
return udl_set_register(buf, 0xFF, 0xFF);
}
static char *udl_set_blank(char *buf, int dpms_mode)
{
u8 reg;
switch (dpms_mode) {
case DRM_MODE_DPMS_OFF:
reg = 0x07;
break;
case DRM_MODE_DPMS_STANDBY:
reg = 0x05;
break;
case DRM_MODE_DPMS_SUSPEND:
reg = 0x01;
break;
case DRM_MODE_DPMS_ON:
reg = 0x00;
break;
}
return udl_set_register(buf, 0x1f, reg);
}
static char *udl_set_color_depth(char *buf, u8 selection)
{
return udl_set_register(buf, 0x00, selection);
}
static char *udl_set_base16bpp(char *wrptr, u32 base)
{
wrptr = udl_set_register(wrptr, 0x20, base >> 16);
wrptr = udl_set_register(wrptr, 0x21, base >> 8);
return udl_set_register(wrptr, 0x22, base);
}
static char *udl_set_base8bpp(char *wrptr, u32 base)
{
wrptr = udl_set_register(wrptr, 0x26, base >> 16);
wrptr = udl_set_register(wrptr, 0x27, base >> 8);
return udl_set_register(wrptr, 0x28, base);
}
static char *udl_set_register_16(char *wrptr, u8 reg, u16 value)
{
wrptr = udl_set_register(wrptr, reg, value >> 8);
return udl_set_register(wrptr, reg+1, value);
}
static char *udl_set_register_16be(char *wrptr, u8 reg, u16 value)
{
wrptr = udl_set_register(wrptr, reg, value);
return udl_set_register(wrptr, reg+1, value >> 8);
}
static u16 udl_lfsr16(u16 actual_count)
{
u32 lv = 0xFFFF;
while (actual_count--) {
lv = ((lv << 1) |
(((lv >> 15) ^ (lv >> 4) ^ (lv >> 2) ^ (lv >> 1)) & 1))
& 0xFFFF;
}
return (u16) lv;
}
static char *udl_set_register_lfsr16(char *wrptr, u8 reg, u16 value)
{
return udl_set_register_16(wrptr, reg, udl_lfsr16(value));
}
static char *udl_set_vid_cmds(char *wrptr, struct drm_display_mode *mode)
{
u16 xds, yds;
u16 xde, yde;
u16 yec;
xds = mode->crtc_htotal - mode->crtc_hsync_start;
wrptr = udl_set_register_lfsr16(wrptr, 0x01, xds);
xde = xds + mode->crtc_hdisplay;
wrptr = udl_set_register_lfsr16(wrptr, 0x03, xde);
yds = mode->crtc_vtotal - mode->crtc_vsync_start;
wrptr = udl_set_register_lfsr16(wrptr, 0x05, yds);
yde = yds + mode->crtc_vdisplay;
wrptr = udl_set_register_lfsr16(wrptr, 0x07, yde);
wrptr = udl_set_register_lfsr16(wrptr, 0x09,
mode->crtc_htotal - 1);
wrptr = udl_set_register_lfsr16(wrptr, 0x0B, 1);
wrptr = udl_set_register_lfsr16(wrptr, 0x0D,
mode->crtc_hsync_end - mode->crtc_hsync_start + 1);
wrptr = udl_set_register_16(wrptr, 0x0F, mode->hdisplay);
yec = mode->crtc_vtotal;
wrptr = udl_set_register_lfsr16(wrptr, 0x11, yec);
wrptr = udl_set_register_lfsr16(wrptr, 0x13, 0);
wrptr = udl_set_register_lfsr16(wrptr, 0x15, mode->crtc_vsync_end - mode->crtc_vsync_start);
wrptr = udl_set_register_16(wrptr, 0x17, mode->crtc_vdisplay);
wrptr = udl_set_register_16be(wrptr, 0x1B,
mode->clock / 5);
return wrptr;
}
static char *udl_dummy_render(char *wrptr)
{
*wrptr++ = 0xAF;
*wrptr++ = 0x6A;
*wrptr++ = 0x00;
*wrptr++ = 0x00;
*wrptr++ = 0x00;
*wrptr++ = 0x01;
*wrptr++ = 0x00;
*wrptr++ = 0x00;
*wrptr++ = 0x00;
return wrptr;
}
static int udl_crtc_write_mode_to_hw(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct udl_device *udl = dev->dev_private;
struct urb *urb;
char *buf;
int retval;
urb = udl_get_urb(dev);
if (!urb)
return -ENOMEM;
buf = (char *)urb->transfer_buffer;
memcpy(buf, udl->mode_buf, udl->mode_buf_len);
retval = udl_submit_urb(dev, urb, udl->mode_buf_len);
DRM_INFO("write mode info %d\n", udl->mode_buf_len);
return retval;
}
static void udl_crtc_dpms(struct drm_crtc *crtc, int mode)
{
struct drm_device *dev = crtc->dev;
struct udl_device *udl = dev->dev_private;
int retval;
if (mode == DRM_MODE_DPMS_OFF) {
char *buf;
struct urb *urb;
urb = udl_get_urb(dev);
if (!urb)
return;
buf = (char *)urb->transfer_buffer;
buf = udl_vidreg_lock(buf);
buf = udl_set_blank(buf, mode);
buf = udl_vidreg_unlock(buf);
buf = udl_dummy_render(buf);
retval = udl_submit_urb(dev, urb, buf - (char *)
urb->transfer_buffer);
} else {
if (udl->mode_buf_len == 0) {
DRM_ERROR("Trying to enable DPMS with no mode\n");
return;
}
udl_crtc_write_mode_to_hw(crtc);
}
}
static int udl_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct udl_framebuffer *ufb = to_udl_fb(crtc->primary->fb);
struct udl_device *udl = dev->dev_private;
char *buf;
char *wrptr;
int color_depth = 0;
buf = (char *)udl->mode_buf;
wrptr = udl_vidreg_lock(buf);
wrptr = udl_set_color_depth(wrptr, color_depth);
wrptr = udl_set_base16bpp(wrptr, 0);
wrptr = udl_set_base8bpp(wrptr, 2 * mode->vdisplay * mode->hdisplay);
wrptr = udl_set_vid_cmds(wrptr, adjusted_mode);
wrptr = udl_set_blank(wrptr, DRM_MODE_DPMS_ON);
wrptr = udl_vidreg_unlock(wrptr);
wrptr = udl_dummy_render(wrptr);
if (old_fb) {
struct udl_framebuffer *uold_fb = to_udl_fb(old_fb);
uold_fb->active_16 = false;
}
ufb->active_16 = true;
udl->mode_buf_len = wrptr - buf;
udl_handle_damage(ufb, 0, 0, ufb->base.width, ufb->base.height);
return 0;
}
static void udl_crtc_disable(struct drm_crtc *crtc)
{
udl_crtc_dpms(crtc, DRM_MODE_DPMS_OFF);
}
static void udl_crtc_destroy(struct drm_crtc *crtc)
{
drm_crtc_cleanup(crtc);
kfree(crtc);
}
static int udl_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags)
{
struct udl_framebuffer *ufb = to_udl_fb(fb);
struct drm_device *dev = crtc->dev;
unsigned long flags;
struct drm_framebuffer *old_fb = crtc->primary->fb;
if (old_fb) {
struct udl_framebuffer *uold_fb = to_udl_fb(old_fb);
uold_fb->active_16 = false;
}
ufb->active_16 = true;
udl_handle_damage(ufb, 0, 0, fb->width, fb->height);
spin_lock_irqsave(&dev->event_lock, flags);
if (event)
drm_send_vblank_event(dev, 0, event);
spin_unlock_irqrestore(&dev->event_lock, flags);
crtc->primary->fb = fb;
return 0;
}
static void udl_crtc_prepare(struct drm_crtc *crtc)
{
}
static void udl_crtc_commit(struct drm_crtc *crtc)
{
udl_crtc_dpms(crtc, DRM_MODE_DPMS_ON);
}
static int udl_crtc_init(struct drm_device *dev)
{
struct drm_crtc *crtc;
crtc = kzalloc(sizeof(struct drm_crtc) + sizeof(struct drm_connector *), GFP_KERNEL);
if (crtc == NULL)
return -ENOMEM;
drm_crtc_init(dev, crtc, &udl_crtc_funcs);
drm_crtc_helper_add(crtc, &udl_helper_funcs);
return 0;
}
int udl_modeset_init(struct drm_device *dev)
{
struct drm_encoder *encoder;
drm_mode_config_init(dev);
dev->mode_config.min_width = 640;
dev->mode_config.min_height = 480;
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
dev->mode_config.prefer_shadow = 0;
dev->mode_config.preferred_depth = 24;
dev->mode_config.funcs = &udl_mode_funcs;
drm_mode_create_dirty_info_property(dev);
udl_crtc_init(dev);
encoder = udl_encoder_init(dev);
udl_connector_init(dev, encoder);
return 0;
}
void udl_modeset_cleanup(struct drm_device *dev)
{
drm_mode_config_cleanup(dev);
}
