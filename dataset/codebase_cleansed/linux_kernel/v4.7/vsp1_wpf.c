static inline void vsp1_wpf_write(struct vsp1_rwpf *wpf,
struct vsp1_dl_list *dl, u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg + wpf->entity.index * VI6_WPF_OFFSET, data);
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
static void wpf_set_memory(struct vsp1_entity *entity, struct vsp1_dl_list *dl)
{
struct vsp1_rwpf *wpf = entity_to_rwpf(entity);
vsp1_wpf_write(wpf, dl, VI6_WPF_DSTM_ADDR_Y, wpf->mem.addr[0]);
vsp1_wpf_write(wpf, dl, VI6_WPF_DSTM_ADDR_C0, wpf->mem.addr[1]);
vsp1_wpf_write(wpf, dl, VI6_WPF_DSTM_ADDR_C1, wpf->mem.addr[2]);
}
static void wpf_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl)
{
struct vsp1_rwpf *wpf = to_rwpf(&entity->subdev);
struct vsp1_device *vsp1 = wpf->entity.vsp1;
const struct v4l2_mbus_framefmt *source_format;
const struct v4l2_mbus_framefmt *sink_format;
const struct v4l2_rect *crop;
unsigned int i;
u32 outfmt = 0;
u32 srcrpf = 0;
crop = vsp1_rwpf_get_crop(wpf, wpf->entity.config);
vsp1_wpf_write(wpf, dl, VI6_WPF_HSZCLIP, VI6_WPF_SZCLIP_EN |
(crop->left << VI6_WPF_SZCLIP_OFST_SHIFT) |
(crop->width << VI6_WPF_SZCLIP_SIZE_SHIFT));
vsp1_wpf_write(wpf, dl, VI6_WPF_VSZCLIP, VI6_WPF_SZCLIP_EN |
(crop->top << VI6_WPF_SZCLIP_OFST_SHIFT) |
(crop->height << VI6_WPF_SZCLIP_SIZE_SHIFT));
sink_format = vsp1_entity_get_pad_format(&wpf->entity,
wpf->entity.config,
RWPF_PAD_SINK);
source_format = vsp1_entity_get_pad_format(&wpf->entity,
wpf->entity.config,
RWPF_PAD_SOURCE);
if (!pipe->lif) {
const struct v4l2_pix_format_mplane *format = &wpf->format;
const struct vsp1_format_info *fmtinfo = wpf->fmtinfo;
outfmt = fmtinfo->hwfmt << VI6_WPF_OUTFMT_WRFMT_SHIFT;
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
}
if (sink_format->code != source_format->code)
outfmt |= VI6_WPF_OUTFMT_CSC;
outfmt |= wpf->alpha << VI6_WPF_OUTFMT_PDV_SHIFT;
vsp1_wpf_write(wpf, dl, VI6_WPF_OUTFMT, outfmt);
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
VI6_WFP_IRQ_ENB_FREE);
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
ret = vsp1_entity_init(vsp1, &wpf->entity, name, 2, &wpf_ops);
if (ret < 0)
return ERR_PTR(ret);
wpf->dlm = vsp1_dlm_create(vsp1, index, 4);
if (!wpf->dlm) {
ret = -ENOMEM;
goto error;
}
ret = vsp1_rwpf_init_ctrls(wpf);
if (ret < 0) {
dev_err(vsp1->dev, "wpf%u: failed to initialize controls\n",
index);
goto error;
}
return wpf;
error:
vsp1_entity_destroy(&wpf->entity);
return ERR_PTR(ret);
}
