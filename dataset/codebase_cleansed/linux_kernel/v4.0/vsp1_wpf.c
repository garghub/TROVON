static inline u32 vsp1_wpf_read(struct vsp1_rwpf *wpf, u32 reg)
{
return vsp1_read(wpf->entity.vsp1,
reg + wpf->entity.index * VI6_WPF_OFFSET);
}
static inline void vsp1_wpf_write(struct vsp1_rwpf *wpf, u32 reg, u32 data)
{
vsp1_write(wpf->entity.vsp1,
reg + wpf->entity.index * VI6_WPF_OFFSET, data);
}
static int wpf_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vsp1_rwpf *wpf =
container_of(ctrl->handler, struct vsp1_rwpf, ctrls);
u32 value;
if (!vsp1_entity_is_streaming(&wpf->entity))
return 0;
switch (ctrl->id) {
case V4L2_CID_ALPHA_COMPONENT:
value = vsp1_wpf_read(wpf, VI6_WPF_OUTFMT);
value &= ~VI6_WPF_OUTFMT_PDV_MASK;
value |= ctrl->val << VI6_WPF_OUTFMT_PDV_SHIFT;
vsp1_wpf_write(wpf, VI6_WPF_OUTFMT, value);
break;
}
return 0;
}
static int wpf_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct vsp1_pipeline *pipe = to_vsp1_pipeline(&subdev->entity);
struct vsp1_rwpf *wpf = to_rwpf(subdev);
struct vsp1_device *vsp1 = wpf->entity.vsp1;
const struct v4l2_rect *crop = &wpf->crop;
unsigned int i;
u32 srcrpf = 0;
u32 outfmt = 0;
int ret;
ret = vsp1_entity_set_streaming(&wpf->entity, enable);
if (ret < 0)
return ret;
if (!enable) {
vsp1_write(vsp1, VI6_WPF_IRQ_ENB(wpf->entity.index), 0);
vsp1_wpf_write(wpf, VI6_WPF_SRCRPF, 0);
return 0;
}
for (i = 0; i < pipe->num_inputs; ++i) {
struct vsp1_rwpf *input = pipe->inputs[i];
srcrpf |= (!pipe->bru && pipe->num_inputs == 1)
? VI6_WPF_SRCRPF_RPF_ACT_MST(input->entity.index)
: VI6_WPF_SRCRPF_RPF_ACT_SUB(input->entity.index);
}
if (pipe->bru || pipe->num_inputs > 1)
srcrpf |= VI6_WPF_SRCRPF_VIRACT_MST;
vsp1_wpf_write(wpf, VI6_WPF_SRCRPF, srcrpf);
if (!pipe->lif) {
struct v4l2_pix_format_mplane *format = &wpf->video.format;
vsp1_wpf_write(wpf, VI6_WPF_DSTM_STRIDE_Y,
format->plane_fmt[0].bytesperline);
if (format->num_planes > 1)
vsp1_wpf_write(wpf, VI6_WPF_DSTM_STRIDE_C,
format->plane_fmt[1].bytesperline);
}
vsp1_wpf_write(wpf, VI6_WPF_HSZCLIP, VI6_WPF_SZCLIP_EN |
(crop->left << VI6_WPF_SZCLIP_OFST_SHIFT) |
(crop->width << VI6_WPF_SZCLIP_SIZE_SHIFT));
vsp1_wpf_write(wpf, VI6_WPF_VSZCLIP, VI6_WPF_SZCLIP_EN |
(crop->top << VI6_WPF_SZCLIP_OFST_SHIFT) |
(crop->height << VI6_WPF_SZCLIP_SIZE_SHIFT));
if (!pipe->lif) {
const struct vsp1_format_info *fmtinfo = wpf->video.fmtinfo;
outfmt = fmtinfo->hwfmt << VI6_WPF_OUTFMT_WRFMT_SHIFT;
if (fmtinfo->alpha)
outfmt |= VI6_WPF_OUTFMT_PXA;
if (fmtinfo->swap_yc)
outfmt |= VI6_WPF_OUTFMT_SPYCS;
if (fmtinfo->swap_uv)
outfmt |= VI6_WPF_OUTFMT_SPUVS;
vsp1_wpf_write(wpf, VI6_WPF_DSWAP, fmtinfo->swap);
}
if (wpf->entity.formats[RWPF_PAD_SINK].code !=
wpf->entity.formats[RWPF_PAD_SOURCE].code)
outfmt |= VI6_WPF_OUTFMT_CSC;
mutex_lock(wpf->ctrls.lock);
outfmt |= vsp1_wpf_read(wpf, VI6_WPF_OUTFMT) & VI6_WPF_OUTFMT_PDV_MASK;
vsp1_wpf_write(wpf, VI6_WPF_OUTFMT, outfmt);
mutex_unlock(wpf->ctrls.lock);
vsp1_write(vsp1, VI6_DPR_WPF_FPORCH(wpf->entity.index),
VI6_DPR_WPF_FPORCH_FP_WPFN);
vsp1_write(vsp1, VI6_WPF_WRBCK_CTRL, 0);
vsp1_write(vsp1, VI6_WPF_IRQ_STA(wpf->entity.index), 0);
vsp1_write(vsp1, VI6_WPF_IRQ_ENB(wpf->entity.index),
VI6_WFP_IRQ_ENB_FREE);
return 0;
}
static void wpf_vdev_queue(struct vsp1_video *video,
struct vsp1_video_buffer *buf)
{
struct vsp1_rwpf *wpf = container_of(video, struct vsp1_rwpf, video);
vsp1_wpf_write(wpf, VI6_WPF_DSTM_ADDR_Y, buf->addr[0]);
if (buf->buf.num_planes > 1)
vsp1_wpf_write(wpf, VI6_WPF_DSTM_ADDR_C0, buf->addr[1]);
if (buf->buf.num_planes > 2)
vsp1_wpf_write(wpf, VI6_WPF_DSTM_ADDR_C1, buf->addr[2]);
}
struct vsp1_rwpf *vsp1_wpf_create(struct vsp1_device *vsp1, unsigned int index)
{
struct v4l2_subdev *subdev;
struct vsp1_video *video;
struct vsp1_rwpf *wpf;
unsigned int flags;
int ret;
wpf = devm_kzalloc(vsp1->dev, sizeof(*wpf), GFP_KERNEL);
if (wpf == NULL)
return ERR_PTR(-ENOMEM);
wpf->max_width = WPF_MAX_WIDTH;
wpf->max_height = WPF_MAX_HEIGHT;
wpf->entity.type = VSP1_ENTITY_WPF;
wpf->entity.index = index;
ret = vsp1_entity_init(vsp1, &wpf->entity, 2);
if (ret < 0)
return ERR_PTR(ret);
subdev = &wpf->entity.subdev;
v4l2_subdev_init(subdev, &wpf_ops);
subdev->entity.ops = &vsp1_media_ops;
subdev->internal_ops = &vsp1_subdev_internal_ops;
snprintf(subdev->name, sizeof(subdev->name), "%s wpf.%u",
dev_name(vsp1->dev), index);
v4l2_set_subdevdata(subdev, wpf);
subdev->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
vsp1_entity_init_formats(subdev, NULL);
v4l2_ctrl_handler_init(&wpf->ctrls, 1);
v4l2_ctrl_new_std(&wpf->ctrls, &wpf_ctrl_ops, V4L2_CID_ALPHA_COMPONENT,
0, 255, 1, 255);
wpf->entity.subdev.ctrl_handler = &wpf->ctrls;
if (wpf->ctrls.error) {
dev_err(vsp1->dev, "wpf%u: failed to initialize controls\n",
index);
ret = wpf->ctrls.error;
goto error;
}
video = &wpf->video;
video->type = V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE;
video->vsp1 = vsp1;
video->ops = &wpf_vdev_ops;
ret = vsp1_video_init(video, &wpf->entity);
if (ret < 0)
goto error;
wpf->entity.video = video;
flags = MEDIA_LNK_FL_ENABLED;
if (!(vsp1->pdata.features & VSP1_HAS_LIF) || index != 0)
flags |= MEDIA_LNK_FL_IMMUTABLE;
ret = media_entity_create_link(&wpf->entity.subdev.entity,
RWPF_PAD_SOURCE,
&wpf->video.video.entity, 0, flags);
if (ret < 0)
goto error;
wpf->entity.sink = &wpf->video.video.entity;
return wpf;
error:
vsp1_entity_destroy(&wpf->entity);
return ERR_PTR(ret);
}
