static void
nv50_cursor_show(struct nouveau_crtc *nv_crtc, bool update)
{
struct drm_device *dev = nv_crtc->base.dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_channel *evo = nv50_display(dev)->master;
int ret;
NV_DEBUG(drm, "\n");
if (update && nv_crtc->cursor.visible)
return;
ret = RING_SPACE(evo, (nv_device(drm->device)->chipset != 0x50 ? 5 : 3) + update * 2);
if (ret) {
NV_ERROR(drm, "no space while unhiding cursor\n");
return;
}
if (nv_device(drm->device)->chipset != 0x50) {
BEGIN_NV04(evo, 0, NV84_EVO_CRTC(nv_crtc->index, CURSOR_DMA), 1);
OUT_RING(evo, NvEvoVRAM);
}
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, CURSOR_CTRL), 2);
OUT_RING(evo, NV50_EVO_CRTC_CURSOR_CTRL_SHOW);
OUT_RING(evo, nv_crtc->cursor.offset >> 8);
if (update) {
BEGIN_NV04(evo, 0, NV50_EVO_UPDATE, 1);
OUT_RING(evo, 0);
FIRE_RING(evo);
nv_crtc->cursor.visible = true;
}
}
static void
nv50_cursor_hide(struct nouveau_crtc *nv_crtc, bool update)
{
struct drm_device *dev = nv_crtc->base.dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_channel *evo = nv50_display(dev)->master;
int ret;
NV_DEBUG(drm, "\n");
if (update && !nv_crtc->cursor.visible)
return;
ret = RING_SPACE(evo, (nv_device(drm->device)->chipset != 0x50 ? 5 : 3) + update * 2);
if (ret) {
NV_ERROR(drm, "no space while hiding cursor\n");
return;
}
BEGIN_NV04(evo, 0, NV50_EVO_CRTC(nv_crtc->index, CURSOR_CTRL), 2);
OUT_RING(evo, NV50_EVO_CRTC_CURSOR_CTRL_HIDE);
OUT_RING(evo, 0);
if (nv_device(drm->device)->chipset != 0x50) {
BEGIN_NV04(evo, 0, NV84_EVO_CRTC(nv_crtc->index, CURSOR_DMA), 1);
OUT_RING(evo, NV84_EVO_CRTC_CURSOR_DMA_HANDLE_NONE);
}
if (update) {
BEGIN_NV04(evo, 0, NV50_EVO_UPDATE, 1);
OUT_RING(evo, 0);
FIRE_RING(evo);
nv_crtc->cursor.visible = false;
}
}
static void
nv50_cursor_set_pos(struct nouveau_crtc *nv_crtc, int x, int y)
{
struct nouveau_device *device = nouveau_dev(nv_crtc->base.dev);
nv_crtc->cursor_saved_x = x; nv_crtc->cursor_saved_y = y;
nv_wr32(device, NV50_PDISPLAY_CURSOR_USER_POS(nv_crtc->index),
((y & 0xFFFF) << 16) | (x & 0xFFFF));
nv_wr32(device, NV50_PDISPLAY_CURSOR_USER_POS_CTRL(nv_crtc->index), 0);
}
static void
nv50_cursor_set_offset(struct nouveau_crtc *nv_crtc, uint32_t offset)
{
if (offset == nv_crtc->cursor.offset)
return;
nv_crtc->cursor.offset = offset;
if (nv_crtc->cursor.visible) {
nv_crtc->cursor.visible = false;
nv_crtc->cursor.show(nv_crtc, true);
}
}
int
nv50_cursor_init(struct nouveau_crtc *nv_crtc)
{
nv_crtc->cursor.set_offset = nv50_cursor_set_offset;
nv_crtc->cursor.set_pos = nv50_cursor_set_pos;
nv_crtc->cursor.hide = nv50_cursor_hide;
nv_crtc->cursor.show = nv50_cursor_show;
return 0;
}
