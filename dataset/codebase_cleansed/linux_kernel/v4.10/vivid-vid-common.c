const struct vivid_fmt *vivid_get_format(struct vivid_dev *dev, u32 pixelformat)
{
const struct vivid_fmt *fmt;
unsigned k;
for (k = 0; k < ARRAY_SIZE(vivid_formats); k++) {
fmt = &vivid_formats[k];
if (fmt->fourcc == pixelformat)
if (fmt->buffers == 1 || dev->multiplanar)
return fmt;
}
return NULL;
}
bool vivid_vid_can_loop(struct vivid_dev *dev)
{
if (dev->src_rect.width != dev->sink_rect.width ||
dev->src_rect.height != dev->sink_rect.height)
return false;
if (dev->fmt_cap->fourcc != dev->fmt_out->fourcc)
return false;
if (dev->field_cap != dev->field_out)
return false;
if (dev->field_cap == V4L2_FIELD_SEQ_TB ||
dev->field_cap == V4L2_FIELD_SEQ_BT)
return false;
if (vivid_is_svid_cap(dev) && vivid_is_svid_out(dev)) {
if (!(dev->std_cap & V4L2_STD_525_60) !=
!(dev->std_out & V4L2_STD_525_60))
return false;
return true;
}
if (vivid_is_hdmi_cap(dev) && vivid_is_hdmi_out(dev))
return true;
return false;
}
void vivid_send_source_change(struct vivid_dev *dev, unsigned type)
{
struct v4l2_event ev = {
.type = V4L2_EVENT_SOURCE_CHANGE,
.u.src_change.changes = V4L2_EVENT_SRC_CH_RESOLUTION,
};
unsigned i;
for (i = 0; i < dev->num_inputs; i++) {
ev.id = i;
if (dev->input_type[i] == type) {
if (video_is_registered(&dev->vid_cap_dev) && dev->has_vid_cap)
v4l2_event_queue(&dev->vid_cap_dev, &ev);
if (video_is_registered(&dev->vbi_cap_dev) && dev->has_vbi_cap)
v4l2_event_queue(&dev->vbi_cap_dev, &ev);
}
}
}
void fmt_sp2mp(const struct v4l2_format *sp_fmt, struct v4l2_format *mp_fmt)
{
struct v4l2_pix_format_mplane *mp = &mp_fmt->fmt.pix_mp;
struct v4l2_plane_pix_format *ppix = &mp->plane_fmt[0];
const struct v4l2_pix_format *pix = &sp_fmt->fmt.pix;
bool is_out = sp_fmt->type == V4L2_BUF_TYPE_VIDEO_OUTPUT;
memset(mp->reserved, 0, sizeof(mp->reserved));
mp_fmt->type = is_out ? V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE :
V4L2_CAP_VIDEO_CAPTURE_MPLANE;
mp->width = pix->width;
mp->height = pix->height;
mp->pixelformat = pix->pixelformat;
mp->field = pix->field;
mp->colorspace = pix->colorspace;
mp->xfer_func = pix->xfer_func;
mp->ycbcr_enc = pix->ycbcr_enc;
mp->quantization = pix->quantization;
mp->num_planes = 1;
mp->flags = pix->flags;
ppix->sizeimage = pix->sizeimage;
ppix->bytesperline = pix->bytesperline;
memset(ppix->reserved, 0, sizeof(ppix->reserved));
}
int fmt_sp2mp_func(struct file *file, void *priv,
struct v4l2_format *f, fmtfunc func)
{
struct v4l2_format fmt;
struct v4l2_pix_format_mplane *mp = &fmt.fmt.pix_mp;
struct v4l2_plane_pix_format *ppix = &mp->plane_fmt[0];
struct v4l2_pix_format *pix = &f->fmt.pix;
int ret;
fmt_sp2mp(f, &fmt);
ret = func(file, priv, &fmt);
pix->width = mp->width;
pix->height = mp->height;
pix->pixelformat = mp->pixelformat;
pix->field = mp->field;
pix->colorspace = mp->colorspace;
pix->xfer_func = mp->xfer_func;
pix->ycbcr_enc = mp->ycbcr_enc;
pix->quantization = mp->quantization;
pix->sizeimage = ppix->sizeimage;
pix->bytesperline = ppix->bytesperline;
pix->flags = mp->flags;
return ret;
}
int vivid_vid_adjust_sel(unsigned flags, struct v4l2_rect *r)
{
unsigned w = r->width;
unsigned h = r->height;
w &= 0xffff;
h &= 0xffff;
if (!(flags & V4L2_SEL_FLAG_LE)) {
w++;
h++;
if (w < 2)
w = 2;
if (h < 2)
h = 2;
}
if (!(flags & V4L2_SEL_FLAG_GE)) {
if (w > MAX_WIDTH)
w = MAX_WIDTH;
if (h > MAX_HEIGHT)
h = MAX_HEIGHT;
}
w = w & ~1;
h = h & ~1;
if (w < 2 || h < 2)
return -ERANGE;
if (w > MAX_WIDTH || h > MAX_HEIGHT)
return -ERANGE;
if (r->top < 0)
r->top = 0;
if (r->left < 0)
r->left = 0;
r->left &= 0xfffe;
r->top &= 0xfffe;
if (r->left + w > MAX_WIDTH)
r->left = MAX_WIDTH - w;
if (r->top + h > MAX_HEIGHT)
r->top = MAX_HEIGHT - h;
if ((flags & (V4L2_SEL_FLAG_GE | V4L2_SEL_FLAG_LE)) ==
(V4L2_SEL_FLAG_GE | V4L2_SEL_FLAG_LE) &&
(r->width != w || r->height != h))
return -ERANGE;
r->width = w;
r->height = h;
return 0;
}
int vivid_enum_fmt_vid(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct vivid_dev *dev = video_drvdata(file);
const struct vivid_fmt *fmt;
if (f->index >= ARRAY_SIZE(vivid_formats) -
(dev->multiplanar ? 0 : VIVID_MPLANAR_FORMATS))
return -EINVAL;
fmt = &vivid_formats[f->index];
f->pixelformat = fmt->fourcc;
return 0;
}
int vidioc_enum_fmt_vid_mplane(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct vivid_dev *dev = video_drvdata(file);
if (!dev->multiplanar)
return -ENOTTY;
return vivid_enum_fmt_vid(file, priv, f);
}
int vidioc_enum_fmt_vid(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
struct vivid_dev *dev = video_drvdata(file);
if (dev->multiplanar)
return -ENOTTY;
return vivid_enum_fmt_vid(file, priv, f);
}
int vidioc_g_std(struct file *file, void *priv, v4l2_std_id *id)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX) {
if (!vivid_is_sdtv_cap(dev))
return -ENODATA;
*id = dev->std_cap;
} else {
if (!vivid_is_svid_out(dev))
return -ENODATA;
*id = dev->std_out;
}
return 0;
}
int vidioc_g_dv_timings(struct file *file, void *_fh,
struct v4l2_dv_timings *timings)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX) {
if (!vivid_is_hdmi_cap(dev))
return -ENODATA;
*timings = dev->dv_timings_cap;
} else {
if (!vivid_is_hdmi_out(dev))
return -ENODATA;
*timings = dev->dv_timings_out;
}
return 0;
}
int vidioc_enum_dv_timings(struct file *file, void *_fh,
struct v4l2_enum_dv_timings *timings)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX) {
if (!vivid_is_hdmi_cap(dev))
return -ENODATA;
} else {
if (!vivid_is_hdmi_out(dev))
return -ENODATA;
}
return v4l2_enum_dv_timings_cap(timings, &vivid_dv_timings_cap,
NULL, NULL);
}
int vidioc_dv_timings_cap(struct file *file, void *_fh,
struct v4l2_dv_timings_cap *cap)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
if (vdev->vfl_dir == VFL_DIR_RX) {
if (!vivid_is_hdmi_cap(dev))
return -ENODATA;
} else {
if (!vivid_is_hdmi_out(dev))
return -ENODATA;
}
*cap = vivid_dv_timings_cap;
return 0;
}
int vidioc_g_edid(struct file *file, void *_fh,
struct v4l2_edid *edid)
{
struct vivid_dev *dev = video_drvdata(file);
struct video_device *vdev = video_devdata(file);
struct cec_adapter *adap;
memset(edid->reserved, 0, sizeof(edid->reserved));
if (vdev->vfl_dir == VFL_DIR_RX) {
if (edid->pad >= dev->num_inputs)
return -EINVAL;
if (dev->input_type[edid->pad] != HDMI)
return -EINVAL;
adap = dev->cec_rx_adap;
} else {
unsigned int bus_idx;
if (edid->pad >= dev->num_outputs)
return -EINVAL;
if (dev->output_type[edid->pad] != HDMI)
return -EINVAL;
bus_idx = dev->cec_output2bus_map[edid->pad];
adap = dev->cec_tx_adap[bus_idx];
}
if (edid->start_block == 0 && edid->blocks == 0) {
edid->blocks = dev->edid_blocks;
return 0;
}
if (dev->edid_blocks == 0)
return -ENODATA;
if (edid->start_block >= dev->edid_blocks)
return -EINVAL;
if (edid->start_block + edid->blocks > dev->edid_blocks)
edid->blocks = dev->edid_blocks - edid->start_block;
memcpy(edid->edid, dev->edid, edid->blocks * 128);
cec_set_edid_phys_addr(edid->edid, edid->blocks * 128, adap->phys_addr);
return 0;
}
