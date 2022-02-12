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
malidp_hw_clearbits(hwdev, MALIDP_CFG_VALID, MALIDP500_CONFIG_VALID);
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
if ((fmt == DRM_FORMAT_RGB888) || (fmt == DRM_FORMAT_BGR888))
return -EINVAL;
return w * drm_format_plane_cpp(fmt, 0) * 8;
}
static void malidp500_se_write_pp_coefftab(struct malidp_hw_device *hwdev,
u32 direction,
u16 addr,
u8 coeffs_id)
{
int i;
u16 scaling_control = MALIDP500_SE_CONTROL + MALIDP_SE_SCALING_CONTROL;
malidp_hw_write(hwdev,
direction | (addr & MALIDP_SE_COEFFTAB_ADDR_MASK),
scaling_control + MALIDP_SE_COEFFTAB_ADDR);
for (i = 0; i < ARRAY_SIZE(dp500_se_scaling_coeffs); ++i)
malidp_hw_write(hwdev, MALIDP_SE_SET_COEFFTAB_DATA(
dp500_se_scaling_coeffs[coeffs_id][i]),
scaling_control + MALIDP_SE_COEFFTAB_DATA);
}
static int malidp500_se_set_scaling_coeffs(struct malidp_hw_device *hwdev,
struct malidp_se_config *se_config,
struct malidp_se_config *old_config)
{
u8 h = (u8)se_config->hcoeff - 1;
u8 v = (u8)se_config->vcoeff - 1;
if (WARN_ON(h >= ARRAY_SIZE(dp500_se_scaling_coeffs) ||
v >= ARRAY_SIZE(dp500_se_scaling_coeffs)))
return -EINVAL;
if ((h == v) && (se_config->hcoeff != old_config->hcoeff ||
se_config->vcoeff != old_config->vcoeff)) {
malidp500_se_write_pp_coefftab(hwdev,
(MALIDP_SE_V_COEFFTAB |
MALIDP_SE_H_COEFFTAB),
0, v);
} else {
if (se_config->vcoeff != old_config->vcoeff)
malidp500_se_write_pp_coefftab(hwdev,
MALIDP_SE_V_COEFFTAB,
0, v);
if (se_config->hcoeff != old_config->hcoeff)
malidp500_se_write_pp_coefftab(hwdev,
MALIDP_SE_H_COEFFTAB,
0, h);
}
return 0;
}
static long malidp500_se_calc_mclk(struct malidp_hw_device *hwdev,
struct malidp_se_config *se_config,
struct videomode *vm)
{
unsigned long mclk;
unsigned long pxlclk = vm->pixelclock;
unsigned long htotal = vm->hactive + vm->hfront_porch +
vm->hback_porch + vm->hsync_len;
unsigned long input_size = se_config->input_w * se_config->input_h;
unsigned long a = 10;
long ret;
if (se_config->scale_enable) {
a = 15 * input_size / (htotal * se_config->output_h);
if (a < 15)
a = 15;
}
mclk = a * pxlclk / 10;
ret = clk_get_rate(hwdev->mclk);
if (ret < mclk) {
DRM_DEBUG_DRIVER("mclk requirement of %lu kHz can't be met.\n",
mclk / 1000);
return -EINVAL;
}
return ret;
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
malidp_hw_clearbits(hwdev, MALIDP_CFG_VALID, MALIDP550_CONFIG_VALID);
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
static int malidp550_se_set_scaling_coeffs(struct malidp_hw_device *hwdev,
struct malidp_se_config *se_config,
struct malidp_se_config *old_config)
{
u32 mask = MALIDP550_SE_CTL_VCSEL(MALIDP550_SE_CTL_SEL_MASK) |
MALIDP550_SE_CTL_HCSEL(MALIDP550_SE_CTL_SEL_MASK);
u32 new_value = MALIDP550_SE_CTL_VCSEL(se_config->vcoeff) |
MALIDP550_SE_CTL_HCSEL(se_config->hcoeff);
malidp_hw_clearbits(hwdev, mask, MALIDP550_SE_CONTROL);
malidp_hw_setbits(hwdev, new_value, MALIDP550_SE_CONTROL);
return 0;
}
static long malidp550_se_calc_mclk(struct malidp_hw_device *hwdev,
struct malidp_se_config *se_config,
struct videomode *vm)
{
unsigned long mclk;
unsigned long pxlclk = vm->pixelclock;
unsigned long htotal = vm->hactive + vm->hfront_porch +
vm->hback_porch + vm->hsync_len;
unsigned long numerator = 1, denominator = 1;
long ret;
if (se_config->scale_enable) {
numerator = max(se_config->input_w, se_config->output_w) *
se_config->input_h;
numerator += se_config->output_w *
(se_config->output_h -
min(se_config->input_h, se_config->output_h));
denominator = (htotal - 2) * se_config->output_h;
}
if (numerator < denominator)
numerator = denominator = 1;
mclk = (pxlclk * numerator) / denominator;
ret = clk_get_rate(hwdev->mclk);
if (ret < mclk) {
DRM_DEBUG_DRIVER("mclk requirement of %lu kHz can't be met.\n",
mclk / 1000);
return -EINVAL;
}
return ret;
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
for (i = 0; i < map->n_pixel_formats; i++) {
if (((map->pixel_formats[i].layer & layer_id) == layer_id) &&
(map->pixel_formats[i].format == format))
return map->pixel_formats[i].id;
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
hwdev = malidp->dev;
de = &hwdev->map.de_irq_map;
if (hwdev->pm_suspended)
return IRQ_NONE;
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
if (hwdev->pm_suspended)
return IRQ_NONE;
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
