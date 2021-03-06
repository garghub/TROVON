static void
nv50_crtc_lut_load(struct drm_crtc *crtc)
{
struct nouveau_drm *drm = nouveau_drm(crtc->dev);
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
void __iomem *lut = nvbo_kmap_obj_iovirtual(nv_crtc->lut.nvbo);
int i;
NV_DEBUG(drm, "\n");
for (i = 0; i < 256; i++) {
writew(nv_crtc->lut.r[i] >> 2, lut + 8*i + 0);
writew(nv_crtc->lut.g[i] >> 2, lut + 8*i + 2);
writew(nv_crtc->lut.b[i] >> 2, lut + 8*i + 4);
}
if (nv_crtc->lut.depth == 30) {
writew(nv_crtc->lut.r[i - 1] >> 2, lut + 8*i + 0);
writew(nv_crtc->lut.g[i - 1] >> 2, lut + 8*i + 2);
writew(nv_crtc->lut.b[i - 1] >> 2, lut + 8*i + 4);
}
}
int
nv50_crtc_blank(struct nouveau_crtc *nv_crtc, bool blanked)
{
struct drm_device *dev = nv_crtc->base.dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_channel *evo = nv50_display(dev)->master;
int index = nv_crtc->index, ret;
NV_DEBUG(drm, "index %d\n", nv_crtc->index);
NV_DEBUG(drm, "%s\n", blanked ? "blanked" : "unblanked");
if (blanked) {
nv_crtc->cursor.hide(nv_crtc, false);
ret = RING_SPACE(evo, nv_device(drm->device)->chipset != 0x50 ? 7 : 5);
if (ret) {
NV_ERROR(drm, "no space while blanking crtc\n");
return ret;
}
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(index, CLUT_MODE), 2);
OUT_RING(evo, NV50_EVO_CRTC_CLUT_MODE_BLANK);
OUT_RING(evo, 0);
if (nv_device(drm->device)->chipset != 0x50) {
BEGIN_NV04(evo, 0, NV84_EVO_CRTC(index, CLUT_DMA), 1);
OUT_RING(evo, NV84_EVO_CRTC_CLUT_DMA_HANDLE_NONE);
}
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(index, FB_DMA), 1);
OUT_RING(evo, NV50_EVO_CRTC_FB_DMA_HANDLE_NONE);
} else {
if (nv_crtc->cursor.visible)
nv_crtc->cursor.show(nv_crtc, false);
else
nv_crtc->cursor.hide(nv_crtc, false);
ret = RING_SPACE(evo, nv_device(drm->device)->chipset != 0x50 ? 10 : 8);
if (ret) {
NV_ERROR(drm, "no space while unblanking crtc\n");
return ret;
}
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(index, CLUT_MODE), 2);
OUT_RING(evo, nv_crtc->lut.depth == 8 ?
NV50_EVO_CRTC_CLUT_MODE_OFF :
NV50_EVO_CRTC_CLUT_MODE_ON);
OUT_RING(evo, nv_crtc->lut.nvbo->bo.offset >> 8);
if (nv_device(drm->device)->chipset != 0x50) {
BEGIN_NV04(evo, 0, NV84_EVO_CRTC(index, CLUT_DMA), 1);
OUT_RING(evo, NvEvoVRAM);
}
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(index, FB_OFFSET), 2);
OUT_RING(evo, nv_crtc->fb.offset >> 8);
OUT_RING(evo, 0);
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(index, FB_DMA), 1);
if (nv_device(drm->device)->chipset != 0x50)
if (nv_crtc->fb.tile_flags == 0x7a00 ||
nv_crtc->fb.tile_flags == 0xfe00)
OUT_RING(evo, NvEvoFB32);
else
if (nv_crtc->fb.tile_flags == 0x7000)
OUT_RING(evo, NvEvoFB16);
else
OUT_RING(evo, NvEvoVRAM_LP);
else
OUT_RING(evo, NvEvoVRAM_LP);
}
nv_crtc->fb.blanked = blanked;
return 0;
}
static int
nv50_crtc_set_dither(struct nouveau_crtc *nv_crtc, bool update)
{
struct nouveau_channel *evo = nv50_display(nv_crtc->base.dev)->master;
struct nouveau_connector *nv_connector;
struct drm_connector *connector;
int head = nv_crtc->index, ret;
u32 mode = 0x00;
nv_connector = nouveau_crtc_connector_get(nv_crtc);
connector = &nv_connector->base;
if (nv_connector->dithering_mode == DITHERING_MODE_AUTO) {
if (nv_crtc->base.fb->depth > connector->display_info.bpc * 3)
mode = DITHERING_MODE_DYNAMIC2X2;
} else {
mode = nv_connector->dithering_mode;
}
if (nv_connector->dithering_depth == DITHERING_DEPTH_AUTO) {
if (connector->display_info.bpc >= 8)
mode |= DITHERING_DEPTH_8BPC;
} else {
mode |= nv_connector->dithering_depth;
}
ret = RING_SPACE(evo, 2 + (update ? 2 : 0));
if (ret == 0) {
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(head, DITHER_CTRL), 1);
OUT_RING (evo, mode);
if (update) {
BEGIN_NV04(evo, 0, NV50_EVO_UPDATE, 1);
OUT_RING (evo, 0);
FIRE_RING (evo);
}
}
return ret;
}
static int
nv50_crtc_set_color_vibrance(struct nouveau_crtc *nv_crtc, bool update)
{
struct drm_device *dev = nv_crtc->base.dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_channel *evo = nv50_display(dev)->master;
int ret;
int adj;
u32 hue, vib;
NV_DEBUG(drm, "vibrance = %i, hue = %i\n",
nv_crtc->color_vibrance, nv_crtc->vibrant_hue);
ret = RING_SPACE(evo, 2 + (update ? 2 : 0));
if (ret) {
NV_ERROR(drm, "no space while setting color vibrance\n");
return ret;
}
adj = (nv_crtc->color_vibrance > 0) ? 50 : 0;
vib = ((nv_crtc->color_vibrance * 2047 + adj) / 100) & 0xfff;
hue = ((nv_crtc->vibrant_hue * 2047) / 100) & 0xfff;
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, COLOR_CTRL), 1);
OUT_RING (evo, (hue << 20) | (vib << 8));
if (update) {
BEGIN_NV04(evo, 0, NV50_EVO_UPDATE, 1);
OUT_RING (evo, 0);
FIRE_RING (evo);
}
return 0;
}
struct nouveau_connector *
nouveau_crtc_connector_get(struct nouveau_crtc *nv_crtc)
{
struct drm_device *dev = nv_crtc->base.dev;
struct drm_connector *connector;
struct drm_crtc *crtc = to_drm_crtc(nv_crtc);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->encoder)
if (connector->encoder->crtc == crtc)
return nouveau_connector(connector);
}
return NULL;
}
static int
nv50_crtc_set_scale(struct nouveau_crtc *nv_crtc, bool update)
{
struct nouveau_connector *nv_connector;
struct drm_crtc *crtc = &nv_crtc->base;
struct drm_device *dev = crtc->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_channel *evo = nv50_display(dev)->master;
struct drm_display_mode *umode = &crtc->mode;
struct drm_display_mode *omode;
int scaling_mode, ret;
u32 ctrl = 0, oX, oY;
NV_DEBUG(drm, "\n");
nv_connector = nouveau_crtc_connector_get(nv_crtc);
if (!nv_connector || !nv_connector->native_mode) {
NV_ERROR(drm, "no native mode, forcing panel scaling\n");
scaling_mode = DRM_MODE_SCALE_NONE;
} else {
scaling_mode = nv_connector->scaling_mode;
}
if (scaling_mode != DRM_MODE_SCALE_NONE)
omode = nv_connector->native_mode;
else
omode = umode;
oX = omode->hdisplay;
oY = omode->vdisplay;
if (omode->flags & DRM_MODE_FLAG_DBLSCAN)
oY *= 2;
if (nv_connector && ( nv_connector->underscan == UNDERSCAN_ON ||
(nv_connector->underscan == UNDERSCAN_AUTO &&
nv_connector->edid &&
drm_detect_hdmi_monitor(nv_connector->edid)))) {
u32 bX = nv_connector->underscan_hborder;
u32 bY = nv_connector->underscan_vborder;
u32 aspect = (oY << 19) / oX;
if (bX) {
oX -= (bX * 2);
if (bY) oY -= (bY * 2);
else oY = ((oX * aspect) + (aspect / 2)) >> 19;
} else {
oX -= (oX >> 4) + 32;
if (bY) oY -= (bY * 2);
else oY = ((oX * aspect) + (aspect / 2)) >> 19;
}
}
switch (scaling_mode) {
case DRM_MODE_SCALE_CENTER:
oX = min((u32)umode->hdisplay, oX);
oY = min((u32)umode->vdisplay, oY);
case DRM_MODE_SCALE_ASPECT:
if (oY < oX) {
u32 aspect = (umode->hdisplay << 19) / umode->vdisplay;
oX = ((oY * aspect) + (aspect / 2)) >> 19;
} else {
u32 aspect = (umode->vdisplay << 19) / umode->hdisplay;
oY = ((oX * aspect) + (aspect / 2)) >> 19;
}
break;
default:
break;
}
if (umode->hdisplay != oX || umode->vdisplay != oY ||
umode->flags & DRM_MODE_FLAG_INTERLACE ||
umode->flags & DRM_MODE_FLAG_DBLSCAN)
ctrl |= NV50_EVO_CRTC_SCALE_CTRL_ACTIVE;
ret = RING_SPACE(evo, 5);
if (ret)
return ret;
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, SCALE_CTRL), 1);
OUT_RING (evo, ctrl);
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, SCALE_RES1), 2);
OUT_RING (evo, oY << 16 | oX);
OUT_RING (evo, oY << 16 | oX);
if (update) {
nv50_display_flip_stop(crtc);
nv50_display_sync(dev);
nv50_display_flip_next(crtc, crtc->fb, NULL);
}
return 0;
}
int
nv50_crtc_set_clock(struct drm_device *dev, int head, int pclk)
{
struct nouveau_device *device = nouveau_dev(dev);
struct nouveau_clock *clk = nouveau_clock(device);
return clk->pll_set(clk, PLL_VPLL0 + head, pclk);
}
static void
nv50_crtc_destroy(struct drm_crtc *crtc)
{
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
struct nouveau_drm *drm = nouveau_drm(crtc->dev);
NV_DEBUG(drm, "\n");
nouveau_bo_unmap(nv_crtc->lut.nvbo);
nouveau_bo_ref(NULL, &nv_crtc->lut.nvbo);
nouveau_bo_unmap(nv_crtc->cursor.nvbo);
nouveau_bo_ref(NULL, &nv_crtc->cursor.nvbo);
drm_crtc_cleanup(&nv_crtc->base);
kfree(nv_crtc);
}
int
nv50_crtc_cursor_set(struct drm_crtc *crtc, struct drm_file *file_priv,
uint32_t buffer_handle, uint32_t width, uint32_t height)
{
struct drm_device *dev = crtc->dev;
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
struct nouveau_bo *cursor = NULL;
struct drm_gem_object *gem;
int ret = 0, i;
if (!buffer_handle) {
nv_crtc->cursor.hide(nv_crtc, true);
return 0;
}
if (width != 64 || height != 64)
return -EINVAL;
gem = drm_gem_object_lookup(dev, file_priv, buffer_handle);
if (!gem)
return -ENOENT;
cursor = nouveau_gem_object(gem);
ret = nouveau_bo_map(cursor);
if (ret)
goto out;
for (i = 0; i < 64 * 64; i++)
nouveau_bo_wr32(nv_crtc->cursor.nvbo, i, nouveau_bo_rd32(cursor, i));
nouveau_bo_unmap(cursor);
nv_crtc->cursor.set_offset(nv_crtc, nv_crtc->cursor.nvbo->bo.offset);
nv_crtc->cursor.show(nv_crtc, true);
out:
drm_gem_object_unreference_unlocked(gem);
return ret;
}
int
nv50_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
nv_crtc->cursor.set_pos(nv_crtc, x, y);
return 0;
}
static void
nv50_crtc_gamma_set(struct drm_crtc *crtc, u16 *r, u16 *g, u16 *b,
uint32_t start, uint32_t size)
{
int end = (start + size > 256) ? 256 : start + size, i;
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
for (i = start; i < end; i++) {
nv_crtc->lut.r[i] = r[i];
nv_crtc->lut.g[i] = g[i];
nv_crtc->lut.b[i] = b[i];
}
if (!nv_crtc->base.fb) {
nv_crtc->lut.depth = 0;
return;
}
nv50_crtc_lut_load(crtc);
}
static void
nv50_crtc_save(struct drm_crtc *crtc)
{
struct nouveau_drm *drm = nouveau_drm(crtc->dev);
NV_ERROR(drm, "!!\n");
}
static void
nv50_crtc_restore(struct drm_crtc *crtc)
{
struct nouveau_drm *drm = nouveau_drm(crtc->dev);
NV_ERROR(drm, "!!\n");
}
static void
nv50_crtc_dpms(struct drm_crtc *crtc, int mode)
{
}
static void
nv50_crtc_prepare(struct drm_crtc *crtc)
{
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
struct drm_device *dev = crtc->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
NV_DEBUG(drm, "index %d\n", nv_crtc->index);
nv50_display_flip_stop(crtc);
drm_vblank_pre_modeset(dev, nv_crtc->index);
nv50_crtc_blank(nv_crtc, true);
}
static void
nv50_crtc_commit(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
NV_DEBUG(drm, "index %d\n", nv_crtc->index);
nv50_crtc_blank(nv_crtc, false);
drm_vblank_post_modeset(dev, nv_crtc->index);
nv50_display_sync(dev);
nv50_display_flip_next(crtc, crtc->fb, NULL);
}
static bool
nv50_crtc_mode_fixup(struct drm_crtc *crtc, const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static int
nv50_crtc_do_mode_set_base(struct drm_crtc *crtc,
struct drm_framebuffer *passed_fb,
int x, int y, bool atomic)
{
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
struct drm_device *dev = nv_crtc->base.dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_channel *evo = nv50_display(dev)->master;
struct drm_framebuffer *drm_fb;
struct nouveau_framebuffer *fb;
int ret;
NV_DEBUG(drm, "index %d\n", nv_crtc->index);
if (!atomic && !crtc->fb) {
NV_DEBUG(drm, "No FB bound\n");
return 0;
}
if (atomic) {
drm_fb = passed_fb;
fb = nouveau_framebuffer(passed_fb);
} else {
drm_fb = crtc->fb;
fb = nouveau_framebuffer(crtc->fb);
ret = nouveau_bo_pin(fb->nvbo, TTM_PL_FLAG_VRAM);
if (ret)
return ret;
if (passed_fb) {
struct nouveau_framebuffer *ofb = nouveau_framebuffer(passed_fb);
nouveau_bo_unpin(ofb->nvbo);
}
}
nv_crtc->fb.offset = fb->nvbo->bo.offset;
nv_crtc->fb.tile_flags = nouveau_bo_tile_layout(fb->nvbo);
nv_crtc->fb.cpp = drm_fb->bits_per_pixel / 8;
if (!nv_crtc->fb.blanked && nv_device(drm->device)->chipset != 0x50) {
ret = RING_SPACE(evo, 2);
if (ret)
return ret;
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, FB_DMA), 1);
OUT_RING (evo, fb->r_dma);
}
ret = RING_SPACE(evo, 12);
if (ret)
return ret;
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, FB_OFFSET), 5);
OUT_RING (evo, nv_crtc->fb.offset >> 8);
OUT_RING (evo, 0);
OUT_RING (evo, (drm_fb->height << 16) | drm_fb->width);
OUT_RING (evo, fb->r_pitch);
OUT_RING (evo, fb->r_format);
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, CLUT_MODE), 1);
OUT_RING (evo, fb->base.depth == 8 ?
NV50_EVO_CRTC_CLUT_MODE_OFF : NV50_EVO_CRTC_CLUT_MODE_ON);
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, FB_POS), 1);
OUT_RING (evo, (y << 16) | x);
if (nv_crtc->lut.depth != fb->base.depth) {
nv_crtc->lut.depth = fb->base.depth;
nv50_crtc_lut_load(crtc);
}
return 0;
}
static int
nv50_crtc_mode_set(struct drm_crtc *crtc, struct drm_display_mode *umode,
struct drm_display_mode *mode, int x, int y,
struct drm_framebuffer *old_fb)
{
struct drm_device *dev = crtc->dev;
struct nouveau_channel *evo = nv50_display(dev)->master;
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
u32 head = nv_crtc->index * 0x400;
u32 ilace = (mode->flags & DRM_MODE_FLAG_INTERLACE) ? 2 : 1;
u32 vscan = (mode->flags & DRM_MODE_FLAG_DBLSCAN) ? 2 : 1;
u32 hactive, hsynce, hbackp, hfrontp, hblanke, hblanks;
u32 vactive, vsynce, vbackp, vfrontp, vblanke, vblanks;
u32 vblan2e = 0, vblan2s = 1;
int ret;
hactive = mode->htotal;
hsynce = mode->hsync_end - mode->hsync_start - 1;
hbackp = mode->htotal - mode->hsync_end;
hblanke = hsynce + hbackp;
hfrontp = mode->hsync_start - mode->hdisplay;
hblanks = mode->htotal - hfrontp - 1;
vactive = mode->vtotal * vscan / ilace;
vsynce = ((mode->vsync_end - mode->vsync_start) * vscan / ilace) - 1;
vbackp = (mode->vtotal - mode->vsync_end) * vscan / ilace;
vblanke = vsynce + vbackp;
vfrontp = (mode->vsync_start - mode->vdisplay) * vscan / ilace;
vblanks = vactive - vfrontp - 1;
if (mode->flags & DRM_MODE_FLAG_INTERLACE) {
vblan2e = vactive + vsynce + vbackp;
vblan2s = vblan2e + (mode->vdisplay * vscan / ilace);
vactive = (vactive * 2) + 1;
}
ret = RING_SPACE(evo, 18);
if (ret == 0) {
BEGIN_NV04(evo, 0, 0x0804 + head, 2);
OUT_RING (evo, 0x00800000 | mode->clock);
OUT_RING (evo, (ilace == 2) ? 2 : 0);
BEGIN_NV04(evo, 0, 0x0810 + head, 6);
OUT_RING (evo, 0x00000000);
OUT_RING (evo, (vactive << 16) | hactive);
OUT_RING (evo, ( vsynce << 16) | hsynce);
OUT_RING (evo, (vblanke << 16) | hblanke);
OUT_RING (evo, (vblanks << 16) | hblanks);
OUT_RING (evo, (vblan2e << 16) | vblan2s);
BEGIN_NV04(evo, 0, 0x082c + head, 1);
OUT_RING (evo, 0x00000000);
BEGIN_NV04(evo, 0, 0x0900 + head, 1);
OUT_RING (evo, 0x00000311);
BEGIN_NV04(evo, 0, 0x08c8 + head, 1);
OUT_RING (evo, (umode->vdisplay << 16) | umode->hdisplay);
BEGIN_NV04(evo, 0, 0x08d4 + head, 1);
OUT_RING (evo, 0x00000000);
}
nv_crtc->set_dither(nv_crtc, false);
nv_crtc->set_scale(nv_crtc, false);
nv_crtc->set_color_vibrance(nv_crtc, false);
return nv50_crtc_do_mode_set_base(crtc, old_fb, x, y, false);
}
static int
nv50_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
int ret;
nv50_display_flip_stop(crtc);
ret = nv50_crtc_do_mode_set_base(crtc, old_fb, x, y, false);
if (ret)
return ret;
ret = nv50_display_sync(crtc->dev);
if (ret)
return ret;
return nv50_display_flip_next(crtc, crtc->fb, NULL);
}
static int
nv50_crtc_mode_set_base_atomic(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
int x, int y, enum mode_set_atomic state)
{
int ret;
nv50_display_flip_stop(crtc);
ret = nv50_crtc_do_mode_set_base(crtc, fb, x, y, true);
if (ret)
return ret;
return nv50_display_sync(crtc->dev);
}
int
nv50_crtc_create(struct drm_device *dev, int index)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_crtc *nv_crtc = NULL;
int ret, i;
NV_DEBUG(drm, "\n");
nv_crtc = kzalloc(sizeof(*nv_crtc), GFP_KERNEL);
if (!nv_crtc)
return -ENOMEM;
nv_crtc->index = index;
nv_crtc->set_dither = nv50_crtc_set_dither;
nv_crtc->set_scale = nv50_crtc_set_scale;
nv_crtc->set_color_vibrance = nv50_crtc_set_color_vibrance;
nv_crtc->color_vibrance = 50;
nv_crtc->vibrant_hue = 0;
nv_crtc->lut.depth = 0;
for (i = 0; i < 256; i++) {
nv_crtc->lut.r[i] = i << 8;
nv_crtc->lut.g[i] = i << 8;
nv_crtc->lut.b[i] = i << 8;
}
drm_crtc_init(dev, &nv_crtc->base, &nv50_crtc_funcs);
drm_crtc_helper_add(&nv_crtc->base, &nv50_crtc_helper_funcs);
drm_mode_crtc_set_gamma_size(&nv_crtc->base, 256);
ret = nouveau_bo_new(dev, 4096, 0x100, TTM_PL_FLAG_VRAM,
0, 0x0000, NULL, &nv_crtc->lut.nvbo);
if (!ret) {
ret = nouveau_bo_pin(nv_crtc->lut.nvbo, TTM_PL_FLAG_VRAM);
if (!ret)
ret = nouveau_bo_map(nv_crtc->lut.nvbo);
if (ret)
nouveau_bo_ref(NULL, &nv_crtc->lut.nvbo);
}
if (ret)
goto out;
ret = nouveau_bo_new(dev, 64*64*4, 0x100, TTM_PL_FLAG_VRAM,
0, 0x0000, NULL, &nv_crtc->cursor.nvbo);
if (!ret) {
ret = nouveau_bo_pin(nv_crtc->cursor.nvbo, TTM_PL_FLAG_VRAM);
if (!ret)
ret = nouveau_bo_map(nv_crtc->cursor.nvbo);
if (ret)
nouveau_bo_ref(NULL, &nv_crtc->cursor.nvbo);
}
if (ret)
goto out;
nv50_cursor_init(nv_crtc);
out:
if (ret)
nv50_crtc_destroy(&nv_crtc->base);
return ret;
}
