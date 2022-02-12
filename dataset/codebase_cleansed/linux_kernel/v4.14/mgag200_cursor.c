static void mga_hide_cursor(struct mga_device *mdev)
{
WREG8(MGA_CURPOSXL, 0);
WREG8(MGA_CURPOSXH, 0);
if (mdev->cursor.pixels_1->pin_count)
mgag200_bo_unpin(mdev->cursor.pixels_1);
if (mdev->cursor.pixels_2->pin_count)
mgag200_bo_unpin(mdev->cursor.pixels_2);
}
int mga_crtc_cursor_set(struct drm_crtc *crtc,
struct drm_file *file_priv,
uint32_t handle,
uint32_t width,
uint32_t height)
{
struct drm_device *dev = crtc->dev;
struct mga_device *mdev = (struct mga_device *)dev->dev_private;
struct mgag200_bo *pixels_1 = mdev->cursor.pixels_1;
struct mgag200_bo *pixels_2 = mdev->cursor.pixels_2;
struct mgag200_bo *pixels_current = mdev->cursor.pixels_current;
struct mgag200_bo *pixels_prev = mdev->cursor.pixels_prev;
struct drm_gem_object *obj;
struct mgag200_bo *bo = NULL;
int ret = 0;
unsigned int i, row, col;
uint32_t colour_set[16];
uint32_t *next_space = &colour_set[0];
uint32_t *palette_iter;
uint32_t this_colour;
bool found = false;
int colour_count = 0;
u64 gpu_addr;
u8 reg_index;
u8 this_row[48];
if (!pixels_1 || !pixels_2) {
WREG8(MGA_CURPOSXL, 0);
WREG8(MGA_CURPOSXH, 0);
return -ENOTSUPP;
}
if ((width != 64 || height != 64) && handle) {
WREG8(MGA_CURPOSXL, 0);
WREG8(MGA_CURPOSXH, 0);
return -EINVAL;
}
BUG_ON(pixels_1 != pixels_current && pixels_1 != pixels_prev);
BUG_ON(pixels_2 != pixels_current && pixels_2 != pixels_prev);
BUG_ON(pixels_current == pixels_prev);
if (!handle || !file_priv) {
mga_hide_cursor(mdev);
return 0;
}
obj = drm_gem_object_lookup(file_priv, handle);
if (!obj)
return -ENOENT;
ret = mgag200_bo_reserve(pixels_1, true);
if (ret) {
WREG8(MGA_CURPOSXL, 0);
WREG8(MGA_CURPOSXH, 0);
goto out_unref;
}
ret = mgag200_bo_reserve(pixels_2, true);
if (ret) {
WREG8(MGA_CURPOSXL, 0);
WREG8(MGA_CURPOSXH, 0);
mgag200_bo_unreserve(pixels_1);
goto out_unreserve1;
}
if (!pixels_1->pin_count) {
ret = mgag200_bo_pin(pixels_1, TTM_PL_FLAG_VRAM,
&mdev->cursor.pixels_1_gpu_addr);
if (ret)
goto out1;
}
if (!pixels_2->pin_count) {
ret = mgag200_bo_pin(pixels_2, TTM_PL_FLAG_VRAM,
&mdev->cursor.pixels_2_gpu_addr);
if (ret) {
mgag200_bo_unpin(pixels_1);
goto out1;
}
}
bo = gem_to_mga_bo(obj);
ret = mgag200_bo_reserve(bo, true);
if (ret) {
dev_err(&dev->pdev->dev, "failed to reserve user bo\n");
goto out1;
}
if (!bo->kmap.virtual) {
ret = ttm_bo_kmap(&bo->bo, 0, bo->bo.num_pages, &bo->kmap);
if (ret) {
dev_err(&dev->pdev->dev, "failed to kmap user buffer updates\n");
goto out2;
}
}
memset(&colour_set[0], 0, sizeof(uint32_t)*16);
for (i = 0; i < 16384; i += 4) {
this_colour = ioread32(bo->kmap.virtual + i);
if (this_colour>>24 != 0xff &&
this_colour>>24 != 0x0) {
if (warn_transparent) {
dev_info(&dev->pdev->dev, "Video card doesn't support cursors with partial transparency.\n");
dev_info(&dev->pdev->dev, "Not enabling hardware cursor.\n");
warn_transparent = false;
}
ret = -EINVAL;
goto out3;
}
if (this_colour>>24 == 0x0)
continue;
found = false;
for (palette_iter = &colour_set[0]; palette_iter != next_space; palette_iter++) {
if (*palette_iter == this_colour) {
found = true;
break;
}
}
if (found)
continue;
if (colour_count >= 16) {
if (warn_palette) {
dev_info(&dev->pdev->dev, "Video card only supports cursors with up to 16 colours.\n");
dev_info(&dev->pdev->dev, "Not enabling hardware cursor.\n");
warn_palette = false;
}
ret = -EINVAL;
goto out3;
}
*next_space = this_colour;
next_space++;
colour_count++;
}
for (i = 0; i < colour_count; i++) {
if (i <= 2)
reg_index = 0x8 + i*0x4;
else
reg_index = 0x60 + i*0x3;
WREG_DAC(reg_index, colour_set[i] & 0xff);
WREG_DAC(reg_index+1, colour_set[i]>>8 & 0xff);
WREG_DAC(reg_index+2, colour_set[i]>>16 & 0xff);
BUG_ON((colour_set[i]>>24 & 0xff) != 0xff);
}
if (!pixels_prev->kmap.virtual) {
ret = ttm_bo_kmap(&pixels_prev->bo, 0,
pixels_prev->bo.num_pages,
&pixels_prev->kmap);
if (ret) {
dev_err(&dev->pdev->dev, "failed to kmap cursor updates\n");
goto out3;
}
}
for (row = 0; row < 64; row++) {
memset(&this_row[0], 0, 48);
for (col = 0; col < 64; col++) {
this_colour = ioread32(bo->kmap.virtual + 4*(col + 64*row));
if (this_colour>>24 == 0x0) {
this_row[47 - col/8] |= 0x80>>(col%8);
continue;
}
for (i = 0; i < colour_count; i++) {
if (colour_set[i] == this_colour) {
if (col % 2)
this_row[col/2] |= i<<4;
else
this_row[col/2] |= i;
break;
}
}
}
memcpy_toio(pixels_prev->kmap.virtual + row*48, &this_row[0], 48);
}
if (pixels_prev == pixels_1)
gpu_addr = mdev->cursor.pixels_1_gpu_addr;
else
gpu_addr = mdev->cursor.pixels_2_gpu_addr;
WREG_DAC(MGA1064_CURSOR_BASE_ADR_LOW, (u8)((gpu_addr>>10) & 0xff));
WREG_DAC(MGA1064_CURSOR_BASE_ADR_HI, (u8)((gpu_addr>>18) & 0x3f));
WREG_DAC(MGA1064_CURSOR_CTL, 4);
if (mdev->cursor.pixels_1 == mdev->cursor.pixels_prev) {
mdev->cursor.pixels_prev = mdev->cursor.pixels_2;
mdev->cursor.pixels_current = mdev->cursor.pixels_1;
} else if (mdev->cursor.pixels_1 == mdev->cursor.pixels_current) {
mdev->cursor.pixels_prev = mdev->cursor.pixels_1;
mdev->cursor.pixels_current = mdev->cursor.pixels_2;
} else {
BUG();
}
ret = 0;
ttm_bo_kunmap(&pixels_prev->kmap);
out3:
ttm_bo_kunmap(&bo->kmap);
out2:
mgag200_bo_unreserve(bo);
out1:
if (ret)
mga_hide_cursor(mdev);
mgag200_bo_unreserve(pixels_1);
out_unreserve1:
mgag200_bo_unreserve(pixels_2);
out_unref:
drm_gem_object_put_unlocked(obj);
return ret;
}
int mga_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct mga_device *mdev = (struct mga_device *)crtc->dev->dev_private;
x += 64;
y += 64;
BUG_ON(x <= 0);
BUG_ON(y <= 0);
BUG_ON(x & ~0xffff);
BUG_ON(y & ~0xffff);
WREG8(MGA_CURPOSXL, x & 0xff);
WREG8(MGA_CURPOSXH, (x>>8) & 0xff);
WREG8(MGA_CURPOSYL, y & 0xff);
WREG8(MGA_CURPOSYH, (y>>8) & 0xff);
return 0;
}
