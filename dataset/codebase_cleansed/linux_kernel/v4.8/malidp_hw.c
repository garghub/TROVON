static int malidp500_query_hw(struct malidp_hw_device *hwdev)
{
u32 conf = malidp_hw_read(hwdev, MALIDP500_CONFIG_ID);
u8 ln_size_mult = conf & 0x10 ? 2 : 1;
hwdev->min_line_size = 2;
hwdev->max_line_size = SZ_2K * ln_size_mult;
hwdev->rotation_memory[0] = SZ_1K * 64 * ln_size_mult;
hwdev->rotation_memory[1] = 0;
return 0;
}
static void malidp500_enter_config_mode(struct malidp_hw_device *hwdev)
{
u32 status, count = 100;
malidp_hw_setbits(hwdev, MALIDP500_DC_CONFIG_REQ, MALIDP500_DC_CONTROL);
while (count) {
status = malidp_hw_read(hwdev, hwdev->map.dc_base + MALIDP_REG_STATUS);
if ((status & MALIDP500_DC_CONFIG_REQ) == MALIDP500_DC_CONFIG_REQ)
break;
usleep_range(1000, 10000);
count--;
}
WARN(count == 0, "timeout while entering config mode");
}
static void malidp500_leave_config_mode(struct malidp_hw_device *hwdev)
{
u32 status, count = 100;
malidp_hw_clearbits(hwdev, MALIDP500_DC_CONFIG_REQ, MALIDP500_DC_CONTROL);
while (count) {
status = malidp_hw_read(hwdev, hwdev->map.dc_base + MALIDP_REG_STATUS);
if ((status & MALIDP500_DC_CONFIG_REQ) == 0)
break;
usleep_range(100, 1000);
count--;
}
WARN(count == 0, "timeout while leaving config mode");
}
static bool malidp500_in_config_mode(struct malidp_hw_device *hwdev)
{
u32 status;
status = malidp_hw_read(hwdev, hwdev->map.dc_base + MALIDP_REG_STATUS);
if ((status & MALIDP500_DC_CONFIG_REQ) == MALIDP500_DC_CONFIG_REQ)
return true;
return false;
}
static void malidp500_set_config_valid(struct malidp_hw_device *hwdev)
{
malidp_hw_setbits(hwdev, MALIDP_CFG_VALID, MALIDP500_CONFIG_VALID);
}
static void malidp500_modeset(struct malidp_hw_device *hwdev, struct videomode *mode)
{
u32 val = 0;
malidp_hw_clearbits(hwdev, MALIDP500_DC_CLEAR_MASK, MALIDP500_DC_CONTROL);
if (mode->flags & DISPLAY_FLAGS_HSYNC_HIGH)
val |= MALIDP500_HSYNCPOL;
if (mode->flags & DISPLAY_FLAGS_VSYNC_HIGH)
val |= MALIDP500_VSYNCPOL;
val |= MALIDP_DE_DEFAULT_PREFETCH_START;
malidp_hw_setbits(hwdev, val, MALIDP500_DC_CONTROL);
val = ((MALIDP_BGND_COLOR_G & 0xfff) << 16) |
(MALIDP_BGND_COLOR_R & 0xfff);
malidp_hw_write(hwdev, val, MALIDP500_BGND_COLOR);
malidp_hw_write(hwdev, MALIDP_BGND_COLOR_B, MALIDP500_BGND_COLOR + 4);
val = MALIDP_DE_H_FRONTPORCH(mode->hfront_porch) |
MALIDP_DE_H_BACKPORCH(mode->hback_porch);
malidp_hw_write(hwdev, val, MALIDP500_TIMINGS_BASE + MALIDP_DE_H_TIMINGS);
val = MALIDP500_DE_V_FRONTPORCH(mode->vfront_porch) |
MALIDP_DE_V_BACKPORCH(mode->vback_porch);
malidp_hw_write(hwdev, val, MALIDP500_TIMINGS_BASE + MALIDP_DE_V_TIMINGS);
val = MALIDP_DE_H_SYNCWIDTH(mode->hsync_len) |
MALIDP_DE_V_SYNCWIDTH(mode->vsync_len);
malidp_hw_write(hwdev, val, MALIDP500_TIMINGS_BASE + MALIDP_DE_SYNC_WIDTH);
val = MALIDP_DE_H_ACTIVE(mode->hactive) | MALIDP_DE_V_ACTIVE(mode->vactive);
malidp_hw_write(hwdev, val, MALIDP500_TIMINGS_BASE + MALIDP_DE_HV_ACTIVE);
if (mode->flags & DISPLAY_FLAGS_INTERLACED)
malidp_hw_setbits(hwdev, MALIDP_DISP_FUNC_ILACED, MALIDP_DE_DISPLAY_FUNC);
else
malidp_hw_clearbits(hwdev, MALIDP_DISP_FUNC_ILACED, MALIDP_DE_DISPLAY_FUNC);
}
static int malidp500_rotmem_required(struct malidp_hw_device *hwdev, u16 w, u16 h, u32 fmt)
{
unsigned int depth;
int bpp;
if ((fmt == DRM_FORMAT_RGB888) || (fmt == DRM_FORMAT_BGR888))
return -EINVAL;
drm_fb_get_bpp_depth(fmt, &depth, &bpp);
return w * bpp;
}
static int malidp550_query_hw(struct malidp_hw_device *hwdev)
{
u32 conf = malidp_hw_read(hwdev, MALIDP550_CONFIG_ID);
u8 ln_size = (conf >> 4) & 0x3, rsize;
hwdev->min_line_size = 2;
switch (ln_size) {
case 0:
hwdev->max_line_size = SZ_2K;
rsize = 64;
break;
case 1:
hwdev->max_line_size = SZ_4K;
rsize = 128;
break;
case 2:
hwdev->max_line_size = 1280;
rsize = 40;
break;
case 3:
hwdev->max_line_size = 0;
return -EINVAL;
}
hwdev->rotation_memory[0] = hwdev->rotation_memory[1] = rsize * SZ_1K;
return 0;
}
static void malidp550_enter_config_mode(struct malidp_hw_device *hwdev)
{
u32 status, count = 100;
malidp_hw_setbits(hwdev, MALIDP550_DC_CONFIG_REQ, MALIDP550_DC_CONTROL);
while (count) {
status = malidp_hw_read(hwdev, hwdev->map.dc_base + MALIDP_REG_STATUS);
if ((status & MALIDP550_DC_CONFIG_REQ) == MALIDP550_DC_CONFIG_REQ)
break;
usleep_range(1000, 10000);
count--;
}
WARN(count == 0, "timeout while entering config mode");
}
static void malidp550_leave_config_mode(struct malidp_hw_device *hwdev)
{
u32 status, count = 100;
malidp_hw_clearbits(hwdev, MALIDP550_DC_CONFIG_REQ, MALIDP550_DC_CONTROL);
while (count) {
status = malidp_hw_read(hwdev, hwdev->map.dc_base + MALIDP_REG_STATUS);
if ((status & MALIDP550_DC_CONFIG_REQ) == 0)
break;
usleep_range(100, 1000);
count--;
}
WARN(count == 0, "timeout while leaving config mode");
}
static bool malidp550_in_config_mode(struct malidp_hw_device *hwdev)
{
u32 status;
status = malidp_hw_read(hwdev, hwdev->map.dc_base + MALIDP_REG_STATUS);
if ((status & MALIDP550_DC_CONFIG_REQ) == MALIDP550_DC_CONFIG_REQ)
return true;
return false;
}
static void malidp550_set_config_valid(struct malidp_hw_device *hwdev)
{
malidp_hw_setbits(hwdev, MALIDP_CFG_VALID, MALIDP550_CONFIG_VALID);
}
static void malidp550_modeset(struct malidp_hw_device *hwdev, struct videomode *mode)
{
u32 val = MALIDP_DE_DEFAULT_PREFETCH_START;
malidp_hw_write(hwdev, val, MALIDP550_DE_CONTROL);
val = (((MALIDP_BGND_COLOR_R >> 4) & 0xff) << 16) |
(((MALIDP_BGND_COLOR_G >> 4) & 0xff) << 8) |
((MALIDP_BGND_COLOR_B >> 4) & 0xff);
malidp_hw_write(hwdev, val, MALIDP550_DE_BGND_COLOR);
val = MALIDP_DE_H_FRONTPORCH(mode->hfront_porch) |
MALIDP_DE_H_BACKPORCH(mode->hback_porch);
malidp_hw_write(hwdev, val, MALIDP550_TIMINGS_BASE + MALIDP_DE_H_TIMINGS);
val = MALIDP550_DE_V_FRONTPORCH(mode->vfront_porch) |
MALIDP_DE_V_BACKPORCH(mode->vback_porch);
malidp_hw_write(hwdev, val, MALIDP550_TIMINGS_BASE + MALIDP_DE_V_TIMINGS);
val = MALIDP_DE_H_SYNCWIDTH(mode->hsync_len) |
MALIDP_DE_V_SYNCWIDTH(mode->vsync_len);
if (mode->flags & DISPLAY_FLAGS_HSYNC_HIGH)
val |= MALIDP550_HSYNCPOL;
if (mode->flags & DISPLAY_FLAGS_VSYNC_HIGH)
val |= MALIDP550_VSYNCPOL;
malidp_hw_write(hwdev, val, MALIDP550_TIMINGS_BASE + MALIDP_DE_SYNC_WIDTH);
val = MALIDP_DE_H_ACTIVE(mode->hactive) | MALIDP_DE_V_ACTIVE(mode->vactive);
malidp_hw_write(hwdev, val, MALIDP550_TIMINGS_BASE + MALIDP_DE_HV_ACTIVE);
if (mode->flags & DISPLAY_FLAGS_INTERLACED)
malidp_hw_setbits(hwdev, MALIDP_DISP_FUNC_ILACED, MALIDP_DE_DISPLAY_FUNC);
else
malidp_hw_clearbits(hwdev, MALIDP_DISP_FUNC_ILACED, MALIDP_DE_DISPLAY_FUNC);
}
static int malidp550_rotmem_required(struct malidp_hw_device *hwdev, u16 w, u16 h, u32 fmt)
{
u32 bytes_per_col;
if ((fmt == DRM_FORMAT_RGB888) || (fmt == DRM_FORMAT_BGR888))
return -EINVAL;
switch (fmt) {
case DRM_FORMAT_ARGB2101010:
case DRM_FORMAT_ABGR2101010:
case DRM_FORMAT_RGBA1010102:
case DRM_FORMAT_BGRA1010102:
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_RGBA8888:
case DRM_FORMAT_BGRA8888:
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_RGBX8888:
case DRM_FORMAT_BGRX8888:
case DRM_FORMAT_RGB888:
case DRM_FORMAT_BGR888:
case DRM_FORMAT_RGBA5551:
case DRM_FORMAT_ABGR1555:
case DRM_FORMAT_RGB565:
case DRM_FORMAT_BGR565:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_YUYV:
bytes_per_col = 32;
break;
case DRM_FORMAT_NV12:
case DRM_FORMAT_YUV420:
bytes_per_col = 24;
break;
default:
return -EINVAL;
}
return w * bytes_per_col;
}
static int malidp650_query_hw(struct malidp_hw_device *hwdev)
{
u32 conf = malidp_hw_read(hwdev, MALIDP550_CONFIG_ID);
u8 ln_size = (conf >> 4) & 0x3, rsize;
hwdev->min_line_size = 4;
switch (ln_size) {
case 0:
case 2:
hwdev->max_line_size = 0;
return -EINVAL;
case 1:
hwdev->max_line_size = SZ_4K;
rsize = 128;
break;
case 3:
hwdev->max_line_size = 2560;
rsize = 80;
}
hwdev->rotation_memory[0] = hwdev->rotation_memory[1] = rsize * SZ_1K;
return 0;
}
u8 malidp_hw_get_format_id(const struct malidp_hw_regmap *map,
u8 layer_id, u32 format)
{
unsigned int i;
for (i = 0; i < map->n_input_formats; i++) {
if (((map->input_formats[i].layer & layer_id) == layer_id) &&
(map->input_formats[i].format == format))
return map->input_formats[i].id;
}
return MALIDP_INVALID_FORMAT_ID;
}
static void malidp_hw_clear_irq(struct malidp_hw_device *hwdev, u8 block, u32 irq)
{
u32 base = malidp_get_block_base(hwdev, block);
if (hwdev->map.features & MALIDP_REGMAP_HAS_CLEARIRQ)
malidp_hw_write(hwdev, irq, base + MALIDP_REG_CLEARIRQ);
else
malidp_hw_write(hwdev, irq, base + MALIDP_REG_STATUS);
}
static irqreturn_t malidp_de_irq(int irq, void *arg)
{
struct drm_device *drm = arg;
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev;
const struct malidp_irq_map *de;
u32 status, mask, dc_status;
irqreturn_t ret = IRQ_NONE;
if (!drm->dev_private)
return IRQ_HANDLED;
hwdev = malidp->dev;
de = &hwdev->map.de_irq_map;
dc_status = malidp_hw_read(hwdev, hwdev->map.dc_base + MALIDP_REG_STATUS);
if (dc_status & hwdev->map.dc_irq_map.vsync_irq) {
atomic_set(&malidp->config_valid, 1);
malidp_hw_clear_irq(hwdev, MALIDP_DC_BLOCK, dc_status);
ret = IRQ_WAKE_THREAD;
}
status = malidp_hw_read(hwdev, MALIDP_REG_STATUS);
if (!(status & de->irq_mask))
return ret;
mask = malidp_hw_read(hwdev, MALIDP_REG_MASKIRQ);
status &= mask;
if (status & de->vsync_irq)
drm_crtc_handle_vblank(&malidp->crtc);
malidp_hw_clear_irq(hwdev, MALIDP_DE_BLOCK, status);
return (ret == IRQ_NONE) ? IRQ_HANDLED : ret;
}
static irqreturn_t malidp_de_irq_thread_handler(int irq, void *arg)
{
struct drm_device *drm = arg;
struct malidp_drm *malidp = drm->dev_private;
wake_up(&malidp->wq);
return IRQ_HANDLED;
}
int malidp_de_irq_init(struct drm_device *drm, int irq)
{
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
int ret;
malidp_hw_disable_irq(hwdev, MALIDP_DE_BLOCK, 0xffffffff);
malidp_hw_clear_irq(hwdev, MALIDP_DE_BLOCK, 0xffffffff);
malidp_hw_disable_irq(hwdev, MALIDP_DC_BLOCK, 0xffffffff);
malidp_hw_clear_irq(hwdev, MALIDP_DC_BLOCK, 0xffffffff);
ret = devm_request_threaded_irq(drm->dev, irq, malidp_de_irq,
malidp_de_irq_thread_handler,
IRQF_SHARED, "malidp-de", drm);
if (ret < 0) {
DRM_ERROR("failed to install DE IRQ handler\n");
return ret;
}
malidp_hw_enable_irq(hwdev, MALIDP_DC_BLOCK,
hwdev->map.dc_irq_map.irq_mask);
malidp_hw_enable_irq(hwdev, MALIDP_DE_BLOCK,
hwdev->map.de_irq_map.irq_mask);
return 0;
}
void malidp_de_irq_fini(struct drm_device *drm)
{
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
malidp_hw_disable_irq(hwdev, MALIDP_DE_BLOCK,
hwdev->map.de_irq_map.irq_mask);
malidp_hw_disable_irq(hwdev, MALIDP_DC_BLOCK,
hwdev->map.dc_irq_map.irq_mask);
}
static irqreturn_t malidp_se_irq(int irq, void *arg)
{
struct drm_device *drm = arg;
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
u32 status, mask;
status = malidp_hw_read(hwdev, hwdev->map.se_base + MALIDP_REG_STATUS);
if (!(status & hwdev->map.se_irq_map.irq_mask))
return IRQ_NONE;
mask = malidp_hw_read(hwdev, hwdev->map.se_base + MALIDP_REG_MASKIRQ);
status = malidp_hw_read(hwdev, hwdev->map.se_base + MALIDP_REG_STATUS);
status &= mask;
malidp_hw_clear_irq(hwdev, MALIDP_SE_BLOCK, status);
return IRQ_HANDLED;
}
static irqreturn_t malidp_se_irq_thread_handler(int irq, void *arg)
{
return IRQ_HANDLED;
}
int malidp_se_irq_init(struct drm_device *drm, int irq)
{
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
int ret;
malidp_hw_disable_irq(hwdev, MALIDP_SE_BLOCK, 0xffffffff);
malidp_hw_clear_irq(hwdev, MALIDP_SE_BLOCK, 0xffffffff);
ret = devm_request_threaded_irq(drm->dev, irq, malidp_se_irq,
malidp_se_irq_thread_handler,
IRQF_SHARED, "malidp-se", drm);
if (ret < 0) {
DRM_ERROR("failed to install SE IRQ handler\n");
return ret;
}
malidp_hw_enable_irq(hwdev, MALIDP_SE_BLOCK,
hwdev->map.se_irq_map.irq_mask);
return 0;
}
void malidp_se_irq_fini(struct drm_device *drm)
{
struct malidp_drm *malidp = drm->dev_private;
struct malidp_hw_device *hwdev = malidp->dev;
malidp_hw_disable_irq(hwdev, MALIDP_SE_BLOCK,
hwdev->map.se_irq_map.irq_mask);
}
