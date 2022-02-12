static inline void vsp1_wpf_write(struct vsp1_rwpf *wpf,
struct vsp1_dl_list *dl, u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg + wpf->entity.index * VI6_WPF_OFFSET, data);
}
static int vsp1_wpf_set_rotation(struct vsp1_rwpf *wpf, unsigned int rotation)
{
struct vsp1_video *video = wpf->video;
struct v4l2_mbus_framefmt *sink_format;
struct v4l2_mbus_framefmt *source_format;
bool rotate;
int ret = 0;
rotate = rotation == 90 || rotation == 270;
if (rotate == wpf->flip.rotate)
return 0;
mutex_lock(&video->lock);
if (vb2_is_busy(&video->queue)) {
ret = -EBUSY;
goto done;
}
sink_format = vsp1_entity_get_pad_format(&wpf->entity,
wpf->entity.config,
RWPF_PAD_SINK);
source_format = vsp1_entity_get_pad_format(&wpf->entity,
wpf->entity.config,
RWPF_PAD_SOURCE);
mutex_lock(&wpf->entity.lock);
if (rotate) {
source_format->width = sink_format->height;
source_format->height = sink_format->width;
} else {
source_format->width = sink_format->width;
source_format->height = sink_format->height;
}
wpf->flip.rotate = rotate;
mutex_unlock(&wpf->entity.lock);
done:
mutex_unlock(&video->lock);
return ret;
}
static int vsp1_wpf_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct vsp1_rwpf *wpf =
container_of(ctrl->handler, struct vsp1_rwpf, ctrls);
unsigned int rotation;
u32 flip = 0;
int ret;
rotation = wpf->flip.ctrls.rotate ? wpf->flip.ctrls.rotate->val : 0;
ret = vsp1_wpf_set_rotation(wpf, rotation);
if (ret < 0)
return ret;
if (wpf->flip.ctrls.vflip->val)
flip |= BIT(WPF_CTRL_VFLIP);
if (wpf->flip.ctrls.hflip && wpf->flip.ctrls.hflip->val)
flip |= BIT(WPF_CTRL_HFLIP);
if (rotation == 180 || rotation == 270)
flip ^= BIT(WPF_CTRL_VFLIP) | BIT(WPF_CTRL_HFLIP);
spin_lock_irq(&wpf->flip.lock);
wpf->flip.pending = flip;
spin_unlock_irq(&wpf->flip.lock);
return 0;
}
static int wpf_init_controls(struct vsp1_rwpf *wpf)
{
struct vsp1_device *vsp1 = wpf->entity.vsp1;
unsigned int num_flip_ctrls;
spin_lock_init(&wpf->flip.lock);
if (wpf->entity.index != 0) {
num_flip_ctrls = 0;
} else if (vsp1->info->features & VSP1_HAS_WPF_HFLIP) {
num_flip_ctrls = 3;
} else if (vsp1->info->features & VSP1_HAS_WPF_VFLIP) {
num_flip_ctrls = 1;
} else {
num_flip_ctrls = 0;
}
vsp1_rwpf_init_ctrls(wpf, num_flip_ctrls);
if (num_flip_ctrls >= 1) {
wpf->flip.ctrls.vflip =
v4l2_ctrl_new_std(&wpf->ctrls, &vsp1_wpf_ctrl_ops,
V4L2_CID_VFLIP, 0, 1, 1, 0);
}
if (num_flip_ctrls == 3) {
wpf->flip.ctrls.hflip =
v4l2_ctrl_new_std(&wpf->ctrls, &vsp1_wpf_ctrl_ops,
V4L2_CID_HFLIP, 0, 1, 1, 0);
wpf->flip.ctrls.rotate =
v4l2_ctrl_new_std(&wpf->ctrls, &vsp1_wpf_ctrl_ops,
V4L2_CID_ROTATE, 0, 270, 90, 0);
v4l2_ctrl_cluster(3, &wpf->flip.ctrls.vflip);
}
if (wpf->ctrls.error) {
dev_err(vsp1->dev, "wpf%u: failed to initialize controls\n",
wpf->entity.index);
return wpf->ctrls.error;
}
return 0;
}
static int wpf_s_stream(struct v4l2_subdev *subdev, int enable)
{
struct vsp1_rwpf *wpf = to_rwpf(subdev);
struct vsp1_device *vsp1 = wpf->entity.vsp1;
if (enable)
return 0;
vsp1_write(vsp1, VI6_WPF_IRQ_ENB(wpf->entity.index), 0);
vsp1_write(vsp1, wpf->entity.index * VI6_WPF_OFFSET +
VI6_WPF_SRCRPF, 0);
return 0;
}
static void vsp1_wpf_destroy(struct vsp1_entity *entity)
{
struct vsp1_rwpf *wpf = entity_to_rwpf(entity);
vsp1_dlm_destroy(wpf->dlm);
}
static void wpf_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl,
enum vsp1_entity_params params)
{
struct vsp1_rwpf *wpf = to_rwpf(&entity->subdev);
struct vsp1_device *vsp1 = wpf->entity.vsp1;
const struct v4l2_mbus_framefmt *source_format;
const struct v4l2_mbus_framefmt *sink_format;
unsigned int i;
u32 outfmt = 0;
u32 srcrpf = 0;
if (params == VSP1_ENTITY_PARAMS_RUNTIME) {
const unsigned int mask = BIT(WPF_CTRL_VFLIP)
| BIT(WPF_CTRL_HFLIP);
unsigned long flags;
spin_lock_irqsave(&wpf->flip.lock, flags);
wpf->flip.active = (wpf->flip.active & ~mask)
| (wpf->flip.pending & mask);
spin_unlock_irqrestore(&wpf->flip.lock, flags);
outfmt = (wpf->alpha << VI6_WPF_OUTFMT_PDV_SHIFT) | wpf->outfmt;
if (wpf->flip.active & BIT(WPF_CTRL_VFLIP))
outfmt |= VI6_WPF_OUTFMT_FLP;
if (wpf->flip.active & BIT(WPF_CTRL_HFLIP))
outfmt |= VI6_WPF_OUTFMT_HFLP;
vsp1_wpf_write(wpf, dl, VI6_WPF_OUTFMT, outfmt);
return;
}
sink_format = vsp1_entity_get_pad_format(&wpf->entity,
wpf->entity.config,
RWPF_PAD_SINK);
source_format = vsp1_entity_get_pad_format(&wpf->entity,
wpf->entity.config,
RWPF_PAD_SOURCE);
if (params == VSP1_ENTITY_PARAMS_PARTITION) {
const struct v4l2_pix_format_mplane *format = &wpf->format;
const struct vsp1_format_info *fmtinfo = wpf->fmtinfo;
struct vsp1_rwpf_memory mem = wpf->mem;
unsigned int flip = wpf->flip.active;
unsigned int width = sink_format->width;
unsigned int height = sink_format->height;
unsigned int offset;
if (pipe->partitions > 1)
width = pipe->partition.width;
vsp1_wpf_write(wpf, dl, VI6_WPF_HSZCLIP, VI6_WPF_SZCLIP_EN |
(0 << VI6_WPF_SZCLIP_OFST_SHIFT) |
(width << VI6_WPF_SZCLIP_SIZE_SHIFT));
vsp1_wpf_write(wpf, dl, VI6_WPF_VSZCLIP, VI6_WPF_SZCLIP_EN |
(0 << VI6_WPF_SZCLIP_OFST_SHIFT) |
(height << VI6_WPF_SZCLIP_SIZE_SHIFT));
if (pipe->lif)
return;
if (flip & BIT(WPF_CTRL_HFLIP) && !wpf->flip.rotate)
offset = format->width - pipe->partition.left
- pipe->partition.width;
else if (flip & BIT(WPF_CTRL_VFLIP) && wpf->flip.rotate)
offset = format->height - pipe->partition.left
- pipe->partition.width;
else
offset = pipe->partition.left;
for (i = 0; i < format->num_planes; ++i) {
unsigned int hsub = i > 0 ? fmtinfo->hsub : 1;
unsigned int vsub = i > 0 ? fmtinfo->vsub : 1;
if (wpf->flip.rotate)
mem.addr[i] += offset / vsub
* format->plane_fmt[i].bytesperline;
else
mem.addr[i] += offset / hsub
* fmtinfo->bpp[i] / 8;
}
if (flip & BIT(WPF_CTRL_VFLIP)) {
if (wpf->flip.rotate)
height = pipe->partition.width;
else
height = format->height;
mem.addr[0] += (height - 1)
* format->plane_fmt[0].bytesperline;
if (format->num_planes > 1) {
offset = (height / fmtinfo->vsub - 1)
* format->plane_fmt[1].bytesperline;
mem.addr[1] += offset;
mem.addr[2] += offset;
}
}
if (wpf->flip.rotate && !(flip & BIT(WPF_CTRL_HFLIP))) {
unsigned int hoffset = max(0, (int)format->width - 16);
for (i = 0; i < format->num_planes; ++i) {
unsigned int hsub = i > 0 ? fmtinfo->hsub : 1;
mem.addr[i] += hoffset / hsub
* fmtinfo->bpp[i] / 8;
}
}
if (vsp1->info->gen == 3 && format->num_planes == 3 &&
fmtinfo->swap_uv)
swap(mem.addr[1], mem.addr[2]);
vsp1_wpf_write(wpf, dl, VI6_WPF_DSTM_ADDR_Y, mem.addr[0]);
vsp1_wpf_write(wpf, dl, VI6_WPF_DSTM_ADDR_C0, mem.addr[1]);
vsp1_wpf_write(wpf, dl, VI6_WPF_DSTM_ADDR_C1, mem.addr[2]);
return;
}
if (!pipe->lif) {
const struct v4l2_pix_format_mplane *format = &wpf->format;
const struct vsp1_format_info *fmtinfo = wpf->fmtinfo;
outfmt = fmtinfo->hwfmt << VI6_WPF_OUTFMT_WRFMT_SHIFT;
if (wpf->flip.rotate)
outfmt |= VI6_WPF_OUTFMT_ROT;
if (fmtinfo->alpha)
outfmt |= VI6_WPF_OUTFMT_PXA;
if (fmtinfo->swap_yc)
outfmt |= VI6_WPF_OUTFMT_SPYCS;
if (fmtinfo->swap_uv)
outfmt |= VI6_WPF_OUTFMT_SPUVS;
vsp1_wpf_write(wpf, dl, VI6_WPF_DSTM_STRIDE_Y,
format->plane_fmt[0].bytesperline);
if (format->num_planes > 1)
vsp1_wpf_write(wpf, dl, VI6_WPF_DSTM_STRIDE_C,
format->plane_fmt[1].bytesperline);
vsp1_wpf_write(wpf, dl, VI6_WPF_DSWAP, fmtinfo->swap);
if (vsp1->info->features & VSP1_HAS_WPF_HFLIP &&
wpf->entity.index == 0)
vsp1_wpf_write(wpf, dl, VI6_WPF_ROT_CTRL,
VI6_WPF_ROT_CTRL_LN16 |
(256 << VI6_WPF_ROT_CTRL_LMEM_WD_SHIFT));
}
if (sink_format->code != source_format->code)
outfmt |= VI6_WPF_OUTFMT_CSC;
wpf->outfmt = outfmt;
vsp1_dl_list_write(dl, VI6_DPR_WPF_FPORCH(wpf->entity.index),
VI6_DPR_WPF_FPORCH_FP_WPFN);
vsp1_dl_list_write(dl, VI6_WPF_WRBCK_CTRL, 0);
for (i = 0; i < vsp1->info->rpf_count; ++i) {
struct vsp1_rwpf *input = pipe->inputs[i];
if (!input)
continue;
srcrpf |= (!pipe->bru && pipe->num_inputs == 1)
? VI6_WPF_SRCRPF_RPF_ACT_MST(input->entity.index)
: VI6_WPF_SRCRPF_RPF_ACT_SUB(input->entity.index);
}
if (pipe->bru || pipe->num_inputs > 1)
srcrpf |= VI6_WPF_SRCRPF_VIRACT_MST;
vsp1_wpf_write(wpf, dl, VI6_WPF_SRCRPF, srcrpf);
vsp1_dl_list_write(dl, VI6_WPF_IRQ_STA(wpf->entity.index), 0);
vsp1_dl_list_write(dl, VI6_WPF_IRQ_ENB(wpf->entity.index),
VI6_WFP_IRQ_ENB_DFEE);
}
static unsigned int wpf_max_width(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe)
{
struct vsp1_rwpf *wpf = to_rwpf(&entity->subdev);
return wpf->flip.rotate ? 256 : wpf->max_width;
}
struct vsp1_rwpf *vsp1_wpf_create(struct vsp1_device *vsp1, unsigned int index)
{
struct vsp1_rwpf *wpf;
char name[6];
int ret;
wpf = devm_kzalloc(vsp1->dev, sizeof(*wpf), GFP_KERNEL);
if (wpf == NULL)
return ERR_PTR(-ENOMEM);
if (vsp1->info->gen == 2) {
wpf->max_width = WPF_GEN2_MAX_WIDTH;
wpf->max_height = WPF_GEN2_MAX_HEIGHT;
} else {
wpf->max_width = WPF_GEN3_MAX_WIDTH;
wpf->max_height = WPF_GEN3_MAX_HEIGHT;
}
wpf->entity.ops = &wpf_entity_ops;
wpf->entity.type = VSP1_ENTITY_WPF;
wpf->entity.index = index;
sprintf(name, "wpf.%u", index);
ret = vsp1_entity_init(vsp1, &wpf->entity, name, 2, &wpf_ops,
MEDIA_ENT_F_PROC_VIDEO_PIXEL_FORMATTER);
if (ret < 0)
return ERR_PTR(ret);
wpf->dlm = vsp1_dlm_create(vsp1, index, 64);
if (!wpf->dlm) {
ret = -ENOMEM;
goto error;
}
ret = wpf_init_controls(wpf);
if (ret < 0) {
dev_err(vsp1->dev, "wpf%u: failed to initialize controls\n",
index);
goto error;
}
v4l2_ctrl_handler_setup(&wpf->ctrls);
return wpf;
error:
vsp1_entity_destroy(&wpf->entity);
return ERR_PTR(ret);
}
