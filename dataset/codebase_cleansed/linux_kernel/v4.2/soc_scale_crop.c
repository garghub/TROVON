static bool is_smaller(const struct v4l2_rect *r1, const struct v4l2_rect *r2)
{
return r1->width < r2->width || r1->height < r2->height;
}
static bool is_inside(const struct v4l2_rect *r1, const struct v4l2_rect *r2)
{
return r1->left > r2->left || r1->top > r2->top ||
r1->left + r1->width < r2->left + r2->width ||
r1->top + r1->height < r2->top + r2->height;
}
int soc_camera_client_g_rect(struct v4l2_subdev *sd, struct v4l2_rect *rect)
{
struct v4l2_crop crop;
struct v4l2_cropcap cap;
int ret;
crop.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
ret = v4l2_subdev_call(sd, video, g_crop, &crop);
if (!ret) {
*rect = crop.c;
return ret;
}
cap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
ret = v4l2_subdev_call(sd, video, cropcap, &cap);
if (!ret)
*rect = cap.defrect;
return ret;
}
static void update_subrect(struct v4l2_rect *rect, struct v4l2_rect *subrect)
{
if (rect->width < subrect->width)
subrect->width = rect->width;
if (rect->height < subrect->height)
subrect->height = rect->height;
if (rect->left > subrect->left)
subrect->left = rect->left;
else if (rect->left + rect->width >
subrect->left + subrect->width)
subrect->left = rect->left + rect->width -
subrect->width;
if (rect->top > subrect->top)
subrect->top = rect->top;
else if (rect->top + rect->height >
subrect->top + subrect->height)
subrect->top = rect->top + rect->height -
subrect->height;
}
int soc_camera_client_s_crop(struct v4l2_subdev *sd,
struct v4l2_crop *crop, struct v4l2_crop *cam_crop,
struct v4l2_rect *target_rect, struct v4l2_rect *subrect)
{
struct v4l2_rect *rect = &crop->c, *cam_rect = &cam_crop->c;
struct device *dev = sd->v4l2_dev->dev;
struct v4l2_cropcap cap;
int ret;
unsigned int width, height;
v4l2_subdev_call(sd, video, s_crop, crop);
ret = soc_camera_client_g_rect(sd, cam_rect);
if (ret < 0)
return ret;
if (!memcmp(rect, cam_rect, sizeof(*rect))) {
dev_dbg(dev, "Camera S_CROP successful for %dx%d@%d:%d\n",
rect->width, rect->height, rect->left, rect->top);
*target_rect = *cam_rect;
return 0;
}
dev_geo(dev, "Fix camera S_CROP for %dx%d@%d:%d to %dx%d@%d:%d\n",
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top,
rect->width, rect->height, rect->left, rect->top);
ret = v4l2_subdev_call(sd, video, cropcap, &cap);
if (ret < 0)
return ret;
soc_camera_limit_side(&rect->left, &rect->width, cap.bounds.left, 2,
cap.bounds.width);
soc_camera_limit_side(&rect->top, &rect->height, cap.bounds.top, 4,
cap.bounds.height);
width = max_t(unsigned int, cam_rect->width, 2);
height = max_t(unsigned int, cam_rect->height, 2);
while (!ret && (is_smaller(cam_rect, rect) ||
is_inside(cam_rect, rect)) &&
(cap.bounds.width > width || cap.bounds.height > height)) {
width *= 2;
height *= 2;
cam_rect->width = width;
cam_rect->height = height;
if (cam_rect->left > rect->left)
cam_rect->left = cap.bounds.left;
if (cam_rect->left + cam_rect->width < rect->left + rect->width)
cam_rect->width = rect->left + rect->width -
cam_rect->left;
if (cam_rect->top > rect->top)
cam_rect->top = cap.bounds.top;
if (cam_rect->top + cam_rect->height < rect->top + rect->height)
cam_rect->height = rect->top + rect->height -
cam_rect->top;
v4l2_subdev_call(sd, video, s_crop, cam_crop);
ret = soc_camera_client_g_rect(sd, cam_rect);
dev_geo(dev, "Camera S_CROP %d for %dx%d@%d:%d\n", ret,
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top);
}
if (is_smaller(cam_rect, rect) || is_inside(cam_rect, rect)) {
*cam_rect = cap.bounds;
v4l2_subdev_call(sd, video, s_crop, cam_crop);
ret = soc_camera_client_g_rect(sd, cam_rect);
dev_geo(dev, "Camera S_CROP %d for max %dx%d@%d:%d\n", ret,
cam_rect->width, cam_rect->height,
cam_rect->left, cam_rect->top);
}
if (!ret) {
*target_rect = *cam_rect;
update_subrect(target_rect, subrect);
}
return ret;
}
static int client_set_fmt(struct soc_camera_device *icd,
struct v4l2_rect *rect, struct v4l2_rect *subrect,
unsigned int max_width, unsigned int max_height,
struct v4l2_subdev_format *format, bool host_can_scale)
{
struct v4l2_subdev *sd = soc_camera_to_subdev(icd);
struct device *dev = icd->parent;
struct v4l2_mbus_framefmt *mf = &format->format;
unsigned int width = mf->width, height = mf->height, tmp_w, tmp_h;
struct v4l2_cropcap cap;
bool host_1to1;
int ret;
ret = v4l2_device_call_until_err(sd->v4l2_dev,
soc_camera_grp_id(icd), pad,
set_fmt, NULL, format);
if (ret < 0)
return ret;
dev_geo(dev, "camera scaled to %ux%u\n", mf->width, mf->height);
if (width == mf->width && height == mf->height) {
host_1to1 = true;
goto update_cache;
}
host_1to1 = false;
if (!host_can_scale)
goto update_cache;
cap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
ret = v4l2_subdev_call(sd, video, cropcap, &cap);
if (ret < 0)
return ret;
if (max_width > cap.bounds.width)
max_width = cap.bounds.width;
if (max_height > cap.bounds.height)
max_height = cap.bounds.height;
tmp_w = mf->width;
tmp_h = mf->height;
while ((width > tmp_w || height > tmp_h) &&
tmp_w < max_width && tmp_h < max_height) {
tmp_w = min(2 * tmp_w, max_width);
tmp_h = min(2 * tmp_h, max_height);
mf->width = tmp_w;
mf->height = tmp_h;
ret = v4l2_device_call_until_err(sd->v4l2_dev,
soc_camera_grp_id(icd), pad,
set_fmt, NULL, format);
dev_geo(dev, "Camera scaled to %ux%u\n",
mf->width, mf->height);
if (ret < 0) {
dev_err(dev, "Client failed to set format: %d\n", ret);
return ret;
}
}
update_cache:
ret = soc_camera_client_g_rect(sd, rect);
if (ret < 0)
return ret;
if (host_1to1)
*subrect = *rect;
else
update_subrect(rect, subrect);
return 0;
}
int soc_camera_client_scale(struct soc_camera_device *icd,
struct v4l2_rect *rect, struct v4l2_rect *subrect,
struct v4l2_mbus_framefmt *mf,
unsigned int *width, unsigned int *height,
bool host_can_scale, unsigned int shift)
{
struct device *dev = icd->parent;
struct v4l2_subdev_format fmt_tmp = {
.which = V4L2_SUBDEV_FORMAT_ACTIVE,
.format = *mf,
};
struct v4l2_mbus_framefmt *mf_tmp = &fmt_tmp.format;
unsigned int scale_h, scale_v;
int ret;
ret = client_set_fmt(icd, rect, subrect, *width, *height,
&fmt_tmp, host_can_scale);
if (ret < 0)
return ret;
dev_geo(dev, "5: camera scaled to %ux%u\n",
mf_tmp->width, mf_tmp->height);
scale_h = soc_camera_calc_scale(rect->width, shift, mf_tmp->width);
scale_v = soc_camera_calc_scale(rect->height, shift, mf_tmp->height);
mf->width = mf_tmp->width;
mf->height = mf_tmp->height;
mf->colorspace = mf_tmp->colorspace;
*width = soc_camera_shift_scale(subrect->width, shift, scale_h);
*height = soc_camera_shift_scale(subrect->height, shift, scale_v);
dev_geo(dev, "8: new client sub-window %ux%u\n", *width, *height);
return 0;
}
void soc_camera_calc_client_output(struct soc_camera_device *icd,
struct v4l2_rect *rect, struct v4l2_rect *subrect,
const struct v4l2_pix_format *pix, struct v4l2_mbus_framefmt *mf,
unsigned int shift)
{
struct device *dev = icd->parent;
unsigned int scale_v, scale_h;
if (subrect->width == rect->width &&
subrect->height == rect->height) {
mf->width = pix->width;
mf->height = pix->height;
return;
}
dev_geo(dev, "2: subwin %ux%u@%u:%u\n",
subrect->width, subrect->height,
subrect->left, subrect->top);
scale_h = soc_camera_calc_scale(subrect->width, shift, pix->width);
scale_v = soc_camera_calc_scale(subrect->height, shift, pix->height);
dev_geo(dev, "3: scales %u:%u\n", scale_h, scale_v);
mf->width = soc_camera_shift_scale(rect->width, shift, scale_h);
mf->height = soc_camera_shift_scale(rect->height, shift, scale_v);
}
