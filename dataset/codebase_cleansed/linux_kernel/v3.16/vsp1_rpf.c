static inline u32 vsp1_rpf_read(struct vsp1_rwpf *rpf, u32 reg)
{
return vsp1_read(rpf->entity.vsp1,
reg + rpf->entity.index * VI6_RPF_OFFSET);
}
static inline void vsp1_rpf_write(struct vsp1_rwpf *rpf, u32 reg, u32 data)
{
vsp1_write(rpf->entity.vsp1,
reg + rpf->entity.index * VI6_RPF_OFFSET, data);
}
static int rpf_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct vsp1_rwpf *rpf = to_rwpf(subdev);
const struct vsp1_format_info *fmtinfo = rpf->video.fmtinfo;
const struct v4l2_pix_format_mplane *format = &rpf->video.format;
const struct v4l2_rect *crop = &rpf->crop;
u32 pstride;
u32 infmt;
if (!enable)
return 0;
vsp1_rpf_write(rpf, VI6_RPF_SRC_BSIZE,
(crop->width << VI6_RPF_SRC_BSIZE_BHSIZE_SHIFT) |
(crop->height << VI6_RPF_SRC_BSIZE_BVSIZE_SHIFT));
vsp1_rpf_write(rpf, VI6_RPF_SRC_ESIZE,
(crop->width << VI6_RPF_SRC_ESIZE_EHSIZE_SHIFT) |
(crop->height << VI6_RPF_SRC_ESIZE_EVSIZE_SHIFT));
rpf->offsets[0] = crop->top * format->plane_fmt[0].bytesperline
+ crop->left * fmtinfo->bpp[0] / 8;
pstride = format->plane_fmt[0].bytesperline
<< VI6_RPF_SRCM_PSTRIDE_Y_SHIFT;
if (format->num_planes > 1) {
rpf->offsets[1] = crop->top * format->plane_fmt[1].bytesperline
+ crop->left * fmtinfo->bpp[1] / 8;
pstride |= format->plane_fmt[1].bytesperline
<< VI6_RPF_SRCM_PSTRIDE_C_SHIFT;
}
vsp1_rpf_write(rpf, VI6_RPF_SRCM_PSTRIDE, pstride);
infmt = VI6_RPF_INFMT_CIPM
| (fmtinfo->hwfmt << VI6_RPF_INFMT_RDFMT_SHIFT);
if (fmtinfo->swap_yc)
infmt |= VI6_RPF_INFMT_SPYCS;
if (fmtinfo->swap_uv)
infmt |= VI6_RPF_INFMT_SPUVS;
if (rpf->entity.formats[RWPF_PAD_SINK].code !=
rpf->entity.formats[RWPF_PAD_SOURCE].code)
infmt |= VI6_RPF_INFMT_CSC;
vsp1_rpf_write(rpf, VI6_RPF_INFMT, infmt);
vsp1_rpf_write(rpf, VI6_RPF_DSWAP, fmtinfo->swap);
vsp1_rpf_write(rpf, VI6_RPF_LOC,
(rpf->location.left << VI6_RPF_LOC_HCOORD_SHIFT) |
(rpf->location.top << VI6_RPF_LOC_VCOORD_SHIFT));
vsp1_rpf_write(rpf, VI6_RPF_ALPH_SEL, VI6_RPF_ALPH_SEL_ASEL_FIXED);
vsp1_rpf_write(rpf, VI6_RPF_VRTCOL_SET,
255 << VI6_RPF_VRTCOL_SET_LAYA_SHIFT);
vsp1_rpf_write(rpf, VI6_RPF_MSK_CTRL, 0);
vsp1_rpf_write(rpf, VI6_RPF_CKEY_CTRL, 0);
return 0;
}
static void rpf_vdev_queue(struct vsp1_video *video,
struct vsp1_video_buffer *buf)
{
struct vsp1_rwpf *rpf = container_of(video, struct vsp1_rwpf, video);
vsp1_rpf_write(rpf, VI6_RPF_SRCM_ADDR_Y,
buf->addr[0] + rpf->offsets[0]);
if (buf->buf.num_planes > 1)
vsp1_rpf_write(rpf, VI6_RPF_SRCM_ADDR_C0,
buf->addr[1] + rpf->offsets[1]);
if (buf->buf.num_planes > 2)
vsp1_rpf_write(rpf, VI6_RPF_SRCM_ADDR_C1,
buf->addr[2] + rpf->offsets[1]);
}
struct vsp1_rwpf *vsp1_rpf_create(struct vsp1_device *vsp1, unsigned int index)
{
struct v4l2_subdev *subdev;
struct vsp1_video *video;
struct vsp1_rwpf *rpf;
int ret;
rpf = devm_kzalloc(vsp1->dev, sizeof(*rpf), GFP_KERNEL);
if (rpf == NULL)
return ERR_PTR(-ENOMEM);
rpf->max_width = RPF_MAX_WIDTH;
rpf->max_height = RPF_MAX_HEIGHT;
rpf->entity.type = VSP1_ENTITY_RPF;
rpf->entity.index = index;
ret = vsp1_entity_init(vsp1, &rpf->entity, 2);
if (ret < 0)
return ERR_PTR(ret);
subdev = &rpf->entity.subdev;
v4l2_subdev_init(subdev, &rpf_ops);
subdev->entity.ops = &vsp1_media_ops;
subdev->internal_ops = &vsp1_subdev_internal_ops;
snprintf(subdev->name, sizeof(subdev->name), "%s rpf.%u",
dev_name(vsp1->dev), index);
v4l2_set_subdevdata(subdev, rpf);
subdev->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
vsp1_entity_init_formats(subdev, NULL);
video = &rpf->video;
video->type = V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE;
video->vsp1 = vsp1;
video->ops = &rpf_vdev_ops;
ret = vsp1_video_init(video, &rpf->entity);
if (ret < 0)
goto error_video;
ret = media_entity_create_link(&rpf->video.video.entity, 0,
&rpf->entity.subdev.entity,
RWPF_PAD_SINK,
MEDIA_LNK_FL_ENABLED |
MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
goto error_link;
return rpf;
error_link:
vsp1_video_cleanup(video);
error_video:
media_entity_cleanup(&rpf->entity.subdev.entity);
return ERR_PTR(ret);
}
