bool drm_rect_intersect(struct drm_rect *r1, const struct drm_rect *r2)
{
r1->x1 = max(r1->x1, r2->x1);
r1->y1 = max(r1->y1, r2->y1);
r1->x2 = min(r1->x2, r2->x2);
r1->y2 = min(r1->y2, r2->y2);
return drm_rect_visible(r1);
}
bool drm_rect_clip_scaled(struct drm_rect *src, struct drm_rect *dst,
const struct drm_rect *clip,
int hscale, int vscale)
{
int diff;
diff = clip->x1 - dst->x1;
if (diff > 0) {
int64_t tmp = src->x1 + (int64_t) diff * hscale;
src->x1 = clamp_t(int64_t, tmp, INT_MIN, INT_MAX);
}
diff = clip->y1 - dst->y1;
if (diff > 0) {
int64_t tmp = src->y1 + (int64_t) diff * vscale;
src->y1 = clamp_t(int64_t, tmp, INT_MIN, INT_MAX);
}
diff = dst->x2 - clip->x2;
if (diff > 0) {
int64_t tmp = src->x2 - (int64_t) diff * hscale;
src->x2 = clamp_t(int64_t, tmp, INT_MIN, INT_MAX);
}
diff = dst->y2 - clip->y2;
if (diff > 0) {
int64_t tmp = src->y2 - (int64_t) diff * vscale;
src->y2 = clamp_t(int64_t, tmp, INT_MIN, INT_MAX);
}
return drm_rect_intersect(dst, clip);
}
static int drm_calc_scale(int src, int dst)
{
int scale = 0;
if (WARN_ON(src < 0 || dst < 0))
return -EINVAL;
if (dst == 0)
return 0;
scale = src / dst;
return scale;
}
int drm_rect_calc_hscale(const struct drm_rect *src,
const struct drm_rect *dst,
int min_hscale, int max_hscale)
{
int src_w = drm_rect_width(src);
int dst_w = drm_rect_width(dst);
int hscale = drm_calc_scale(src_w, dst_w);
if (hscale < 0 || dst_w == 0)
return hscale;
if (hscale < min_hscale || hscale > max_hscale)
return -ERANGE;
return hscale;
}
int drm_rect_calc_vscale(const struct drm_rect *src,
const struct drm_rect *dst,
int min_vscale, int max_vscale)
{
int src_h = drm_rect_height(src);
int dst_h = drm_rect_height(dst);
int vscale = drm_calc_scale(src_h, dst_h);
if (vscale < 0 || dst_h == 0)
return vscale;
if (vscale < min_vscale || vscale > max_vscale)
return -ERANGE;
return vscale;
}
int drm_rect_calc_hscale_relaxed(struct drm_rect *src,
struct drm_rect *dst,
int min_hscale, int max_hscale)
{
int src_w = drm_rect_width(src);
int dst_w = drm_rect_width(dst);
int hscale = drm_calc_scale(src_w, dst_w);
if (hscale < 0 || dst_w == 0)
return hscale;
if (hscale < min_hscale) {
int max_dst_w = src_w / min_hscale;
drm_rect_adjust_size(dst, max_dst_w - dst_w, 0);
return min_hscale;
}
if (hscale > max_hscale) {
int max_src_w = dst_w * max_hscale;
drm_rect_adjust_size(src, max_src_w - src_w, 0);
return max_hscale;
}
return hscale;
}
int drm_rect_calc_vscale_relaxed(struct drm_rect *src,
struct drm_rect *dst,
int min_vscale, int max_vscale)
{
int src_h = drm_rect_height(src);
int dst_h = drm_rect_height(dst);
int vscale = drm_calc_scale(src_h, dst_h);
if (vscale < 0 || dst_h == 0)
return vscale;
if (vscale < min_vscale) {
int max_dst_h = src_h / min_vscale;
drm_rect_adjust_size(dst, 0, max_dst_h - dst_h);
return min_vscale;
}
if (vscale > max_vscale) {
int max_src_h = dst_h * max_vscale;
drm_rect_adjust_size(src, 0, max_src_h - src_h);
return max_vscale;
}
return vscale;
}
void drm_rect_debug_print(const char *prefix, const struct drm_rect *r, bool fixed_point)
{
int w = drm_rect_width(r);
int h = drm_rect_height(r);
if (fixed_point)
DRM_DEBUG_KMS("%s%d.%06ux%d.%06u%+d.%06u%+d.%06u\n", prefix,
w >> 16, ((w & 0xffff) * 15625) >> 10,
h >> 16, ((h & 0xffff) * 15625) >> 10,
r->x1 >> 16, ((r->x1 & 0xffff) * 15625) >> 10,
r->y1 >> 16, ((r->y1 & 0xffff) * 15625) >> 10);
else
DRM_DEBUG_KMS("%s%dx%d%+d%+d\n", prefix, w, h, r->x1, r->y1);
}
void drm_rect_rotate(struct drm_rect *r,
int width, int height,
unsigned int rotation)
{
struct drm_rect tmp;
if (rotation & (DRM_REFLECT_X | DRM_REFLECT_Y)) {
tmp = *r;
if (rotation & DRM_REFLECT_X) {
r->x1 = width - tmp.x2;
r->x2 = width - tmp.x1;
}
if (rotation & DRM_REFLECT_Y) {
r->y1 = height - tmp.y2;
r->y2 = height - tmp.y1;
}
}
switch (rotation & DRM_ROTATE_MASK) {
case DRM_ROTATE_0:
break;
case DRM_ROTATE_90:
tmp = *r;
r->x1 = tmp.y1;
r->x2 = tmp.y2;
r->y1 = width - tmp.x2;
r->y2 = width - tmp.x1;
break;
case DRM_ROTATE_180:
tmp = *r;
r->x1 = width - tmp.x2;
r->x2 = width - tmp.x1;
r->y1 = height - tmp.y2;
r->y2 = height - tmp.y1;
break;
case DRM_ROTATE_270:
tmp = *r;
r->x1 = height - tmp.y2;
r->x2 = height - tmp.y1;
r->y1 = tmp.x1;
r->y2 = tmp.x2;
break;
default:
break;
}
}
void drm_rect_rotate_inv(struct drm_rect *r,
int width, int height,
unsigned int rotation)
{
struct drm_rect tmp;
switch (rotation & DRM_ROTATE_MASK) {
case DRM_ROTATE_0:
break;
case DRM_ROTATE_90:
tmp = *r;
r->x1 = width - tmp.y2;
r->x2 = width - tmp.y1;
r->y1 = tmp.x1;
r->y2 = tmp.x2;
break;
case DRM_ROTATE_180:
tmp = *r;
r->x1 = width - tmp.x2;
r->x2 = width - tmp.x1;
r->y1 = height - tmp.y2;
r->y2 = height - tmp.y1;
break;
case DRM_ROTATE_270:
tmp = *r;
r->x1 = tmp.y1;
r->x2 = tmp.y2;
r->y1 = height - tmp.x2;
r->y2 = height - tmp.x1;
break;
default:
break;
}
if (rotation & (DRM_REFLECT_X | DRM_REFLECT_Y)) {
tmp = *r;
if (rotation & DRM_REFLECT_X) {
r->x1 = width - tmp.x2;
r->x2 = width - tmp.x1;
}
if (rotation & DRM_REFLECT_Y) {
r->y1 = height - tmp.y2;
r->y2 = height - tmp.y1;
}
}
}
