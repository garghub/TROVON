static void radeon_lock_cursor(struct drm_crtc *crtc, bool lock)
{
struct radeon_device *rdev = crtc->dev->dev_private;
struct radeon_crtc *radeon_crtc = to_radeon_crtc(crtc);
uint32_t cur_lock;
if (ASIC_IS_DCE4(rdev)) {
cur_lock = RREG32(EVERGREEN_CUR_UPDATE + radeon_crtc->crtc_offset);
if (lock)
cur_lock |= EVERGREEN_CURSOR_UPDATE_LOCK;
else
cur_lock &= ~EVERGREEN_CURSOR_UPDATE_LOCK;
WREG32(EVERGREEN_CUR_UPDATE + radeon_crtc->crtc_offset, cur_lock);
} else if (ASIC_IS_AVIVO(rdev)) {
cur_lock = RREG32(AVIVO_D1CUR_UPDATE + radeon_crtc->crtc_offset);
if (lock)
cur_lock |= AVIVO_D1CURSOR_UPDATE_LOCK;
else
cur_lock &= ~AVIVO_D1CURSOR_UPDATE_LOCK;
WREG32(AVIVO_D1CUR_UPDATE + radeon_crtc->crtc_offset, cur_lock);
} else {
cur_lock = RREG32(RADEON_CUR_OFFSET + radeon_crtc->crtc_offset);
if (lock)
cur_lock |= RADEON_CUR_LOCK;
else
cur_lock &= ~RADEON_CUR_LOCK;
WREG32(RADEON_CUR_OFFSET + radeon_crtc->crtc_offset, cur_lock);
}
}
static void radeon_hide_cursor(struct drm_crtc *crtc)
{
struct radeon_crtc *radeon_crtc = to_radeon_crtc(crtc);
struct radeon_device *rdev = crtc->dev->dev_private;
if (ASIC_IS_DCE4(rdev)) {
WREG32_IDX(EVERGREEN_CUR_CONTROL + radeon_crtc->crtc_offset,
EVERGREEN_CURSOR_MODE(EVERGREEN_CURSOR_24_8_PRE_MULT) |
EVERGREEN_CURSOR_URGENT_CONTROL(EVERGREEN_CURSOR_URGENT_1_2));
} else if (ASIC_IS_AVIVO(rdev)) {
WREG32_IDX(AVIVO_D1CUR_CONTROL + radeon_crtc->crtc_offset,
(AVIVO_D1CURSOR_MODE_24BPP << AVIVO_D1CURSOR_MODE_SHIFT));
} else {
u32 reg;
switch (radeon_crtc->crtc_id) {
case 0:
reg = RADEON_CRTC_GEN_CNTL;
break;
case 1:
reg = RADEON_CRTC2_GEN_CNTL;
break;
default:
return;
}
WREG32_IDX(reg, RREG32_IDX(reg) & ~RADEON_CRTC_CUR_EN);
}
}
static void radeon_show_cursor(struct drm_crtc *crtc)
{
struct radeon_crtc *radeon_crtc = to_radeon_crtc(crtc);
struct radeon_device *rdev = crtc->dev->dev_private;
if (ASIC_IS_DCE4(rdev)) {
WREG32(RADEON_MM_INDEX, EVERGREEN_CUR_CONTROL + radeon_crtc->crtc_offset);
WREG32(RADEON_MM_DATA, EVERGREEN_CURSOR_EN |
EVERGREEN_CURSOR_MODE(EVERGREEN_CURSOR_24_8_PRE_MULT) |
EVERGREEN_CURSOR_URGENT_CONTROL(EVERGREEN_CURSOR_URGENT_1_2));
} else if (ASIC_IS_AVIVO(rdev)) {
WREG32(RADEON_MM_INDEX, AVIVO_D1CUR_CONTROL + radeon_crtc->crtc_offset);
WREG32(RADEON_MM_DATA, AVIVO_D1CURSOR_EN |
(AVIVO_D1CURSOR_MODE_24BPP << AVIVO_D1CURSOR_MODE_SHIFT));
} else {
switch (radeon_crtc->crtc_id) {
case 0:
WREG32(RADEON_MM_INDEX, RADEON_CRTC_GEN_CNTL);
break;
case 1:
WREG32(RADEON_MM_INDEX, RADEON_CRTC2_GEN_CNTL);
break;
default:
return;
}
WREG32_P(RADEON_MM_DATA, (RADEON_CRTC_CUR_EN |
(RADEON_CRTC_CUR_MODE_24BPP << RADEON_CRTC_CUR_MODE_SHIFT)),
~(RADEON_CRTC_CUR_EN | RADEON_CRTC_CUR_MODE_MASK));
}
}
static int radeon_cursor_move_locked(struct drm_crtc *crtc, int x, int y)
{
struct radeon_crtc *radeon_crtc = to_radeon_crtc(crtc);
struct radeon_device *rdev = crtc->dev->dev_private;
int xorigin = 0, yorigin = 0;
int w = radeon_crtc->cursor_width;
if (ASIC_IS_AVIVO(rdev)) {
x += crtc->x;
y += crtc->y;
}
DRM_DEBUG("x %d y %d c->x %d c->y %d\n", x, y, crtc->x, crtc->y);
if (x < 0) {
xorigin = min(-x, radeon_crtc->max_cursor_width - 1);
x = 0;
}
if (y < 0) {
yorigin = min(-y, radeon_crtc->max_cursor_height - 1);
y = 0;
}
if (ASIC_IS_AVIVO(rdev) && !ASIC_IS_DCE6(rdev)) {
int i = 0;
struct drm_crtc *crtc_p;
list_for_each_entry(crtc_p, &crtc->dev->mode_config.crtc_list, head) {
if (crtc_p->enabled)
i++;
}
if (i > 1) {
int cursor_end, frame_end;
cursor_end = x - xorigin + w;
frame_end = crtc->x + crtc->mode.crtc_hdisplay;
if (cursor_end >= frame_end) {
w = w - (cursor_end - frame_end);
if (!(frame_end & 0x7f))
w--;
} else {
if (!(cursor_end & 0x7f))
w--;
}
if (w <= 0) {
w = 1;
cursor_end = x - xorigin + w;
if (!(cursor_end & 0x7f)) {
x--;
WARN_ON_ONCE(x < 0);
}
}
}
}
if (ASIC_IS_DCE4(rdev)) {
WREG32(EVERGREEN_CUR_POSITION + radeon_crtc->crtc_offset, (x << 16) | y);
WREG32(EVERGREEN_CUR_HOT_SPOT + radeon_crtc->crtc_offset, (xorigin << 16) | yorigin);
WREG32(EVERGREEN_CUR_SIZE + radeon_crtc->crtc_offset,
((w - 1) << 16) | (radeon_crtc->cursor_height - 1));
} else if (ASIC_IS_AVIVO(rdev)) {
WREG32(AVIVO_D1CUR_POSITION + radeon_crtc->crtc_offset, (x << 16) | y);
WREG32(AVIVO_D1CUR_HOT_SPOT + radeon_crtc->crtc_offset, (xorigin << 16) | yorigin);
WREG32(AVIVO_D1CUR_SIZE + radeon_crtc->crtc_offset,
((w - 1) << 16) | (radeon_crtc->cursor_height - 1));
} else {
if (crtc->mode.flags & DRM_MODE_FLAG_DBLSCAN)
y *= 2;
WREG32(RADEON_CUR_HORZ_VERT_OFF + radeon_crtc->crtc_offset,
(RADEON_CUR_LOCK
| (xorigin << 16)
| yorigin));
WREG32(RADEON_CUR_HORZ_VERT_POSN + radeon_crtc->crtc_offset,
(RADEON_CUR_LOCK
| (x << 16)
| y));
WREG32(RADEON_CUR_OFFSET + radeon_crtc->crtc_offset, (radeon_crtc->legacy_cursor_offset +
(yorigin * 256)));
}
radeon_crtc->cursor_x = x;
radeon_crtc->cursor_y = y;
return 0;
}
int radeon_crtc_cursor_move(struct drm_crtc *crtc,
int x, int y)
{
int ret;
radeon_lock_cursor(crtc, true);
ret = radeon_cursor_move_locked(crtc, x, y);
radeon_lock_cursor(crtc, false);
return ret;
}
static int radeon_set_cursor(struct drm_crtc *crtc, struct drm_gem_object *obj)
{
struct radeon_crtc *radeon_crtc = to_radeon_crtc(crtc);
struct radeon_device *rdev = crtc->dev->dev_private;
struct radeon_bo *robj = gem_to_radeon_bo(obj);
uint64_t gpu_addr;
int ret;
ret = radeon_bo_reserve(robj, false);
if (unlikely(ret != 0))
goto fail;
ret = radeon_bo_pin_restricted(robj, RADEON_GEM_DOMAIN_VRAM,
ASIC_IS_AVIVO(rdev) ? 0 : 1 << 27,
&gpu_addr);
radeon_bo_unreserve(robj);
if (ret)
goto fail;
if (ASIC_IS_DCE4(rdev)) {
WREG32(EVERGREEN_CUR_SURFACE_ADDRESS_HIGH + radeon_crtc->crtc_offset,
upper_32_bits(gpu_addr));
WREG32(EVERGREEN_CUR_SURFACE_ADDRESS + radeon_crtc->crtc_offset,
gpu_addr & 0xffffffff);
} else if (ASIC_IS_AVIVO(rdev)) {
if (rdev->family >= CHIP_RV770) {
if (radeon_crtc->crtc_id)
WREG32(R700_D2CUR_SURFACE_ADDRESS_HIGH, upper_32_bits(gpu_addr));
else
WREG32(R700_D1CUR_SURFACE_ADDRESS_HIGH, upper_32_bits(gpu_addr));
}
WREG32(AVIVO_D1CUR_SURFACE_ADDRESS + radeon_crtc->crtc_offset,
gpu_addr & 0xffffffff);
} else {
radeon_crtc->legacy_cursor_offset = gpu_addr - radeon_crtc->legacy_display_base_addr;
WREG32(RADEON_CUR_OFFSET + radeon_crtc->crtc_offset, radeon_crtc->legacy_cursor_offset);
}
return 0;
fail:
drm_gem_object_unreference_unlocked(obj);
return ret;
}
int radeon_crtc_cursor_set2(struct drm_crtc *crtc,
struct drm_file *file_priv,
uint32_t handle,
uint32_t width,
uint32_t height,
int32_t hot_x,
int32_t hot_y)
{
struct radeon_crtc *radeon_crtc = to_radeon_crtc(crtc);
struct drm_gem_object *obj;
int ret;
if (!handle) {
radeon_hide_cursor(crtc);
obj = NULL;
goto unpin;
}
if ((width > radeon_crtc->max_cursor_width) ||
(height > radeon_crtc->max_cursor_height)) {
DRM_ERROR("bad cursor width or height %d x %d\n", width, height);
return -EINVAL;
}
obj = drm_gem_object_lookup(crtc->dev, file_priv, handle);
if (!obj) {
DRM_ERROR("Cannot find cursor object %x for crtc %d\n", handle, radeon_crtc->crtc_id);
return -ENOENT;
}
radeon_crtc->cursor_width = width;
radeon_crtc->cursor_height = height;
radeon_lock_cursor(crtc, true);
if (hot_x != radeon_crtc->cursor_hot_x ||
hot_y != radeon_crtc->cursor_hot_y) {
int x, y;
x = radeon_crtc->cursor_x + radeon_crtc->cursor_hot_x - hot_x;
y = radeon_crtc->cursor_y + radeon_crtc->cursor_hot_y - hot_y;
radeon_cursor_move_locked(crtc, x, y);
radeon_crtc->cursor_hot_x = hot_x;
radeon_crtc->cursor_hot_y = hot_y;
}
ret = radeon_set_cursor(crtc, obj);
if (ret)
DRM_ERROR("radeon_set_cursor returned %d, not changing cursor\n",
ret);
else
radeon_show_cursor(crtc);
radeon_lock_cursor(crtc, false);
unpin:
if (radeon_crtc->cursor_bo) {
struct radeon_bo *robj = gem_to_radeon_bo(radeon_crtc->cursor_bo);
ret = radeon_bo_reserve(robj, false);
if (likely(ret == 0)) {
radeon_bo_unpin(robj);
radeon_bo_unreserve(robj);
}
if (radeon_crtc->cursor_bo != obj)
drm_gem_object_unreference_unlocked(radeon_crtc->cursor_bo);
}
radeon_crtc->cursor_bo = obj;
return 0;
}
void radeon_cursor_reset(struct drm_crtc *crtc)
{
struct radeon_crtc *radeon_crtc = to_radeon_crtc(crtc);
int ret;
if (radeon_crtc->cursor_bo) {
radeon_lock_cursor(crtc, true);
radeon_cursor_move_locked(crtc, radeon_crtc->cursor_x,
radeon_crtc->cursor_y);
ret = radeon_set_cursor(crtc, radeon_crtc->cursor_bo);
if (ret)
DRM_ERROR("radeon_set_cursor returned %d, not showing "
"cursor\n", ret);
else
radeon_show_cursor(crtc);
radeon_lock_cursor(crtc, false);
}
}
