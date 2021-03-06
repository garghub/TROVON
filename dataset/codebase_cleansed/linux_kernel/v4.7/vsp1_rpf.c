static inline void vsp1_rpf_write(struct vsp1_rwpf *rpf,
struct vsp1_dl_list *dl, u32 reg, u32 data)
{
vsp1_dl_list_write(dl, reg + rpf->entity.index * VI6_RPF_OFFSET, data);
}
static void rpf_set_memory(struct vsp1_entity *entity, struct vsp1_dl_list *dl)
{
struct vsp1_rwpf *rpf = entity_to_rwpf(entity);
vsp1_rpf_write(rpf, dl, VI6_RPF_SRCM_ADDR_Y,
rpf->mem.addr[0] + rpf->offsets[0]);
vsp1_rpf_write(rpf, dl, VI6_RPF_SRCM_ADDR_C0,
rpf->mem.addr[1] + rpf->offsets[1]);
vsp1_rpf_write(rpf, dl, VI6_RPF_SRCM_ADDR_C1,
rpf->mem.addr[2] + rpf->offsets[1]);
}
static void rpf_configure(struct vsp1_entity *entity,
struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl)
{
struct vsp1_rwpf *rpf = to_rwpf(&entity->subdev);
const struct vsp1_format_info *fmtinfo = rpf->fmtinfo;
const struct v4l2_pix_format_mplane *format = &rpf->format;
const struct v4l2_mbus_framefmt *source_format;
const struct v4l2_mbus_framefmt *sink_format;
const struct v4l2_rect *crop;
unsigned int left = 0;
unsigned int top = 0;
u32 pstride;
u32 infmt;
crop = vsp1_rwpf_get_crop(rpf, rpf->entity.config);
vsp1_rpf_write(rpf, dl, VI6_RPF_SRC_BSIZE,
(crop->width << VI6_RPF_SRC_BSIZE_BHSIZE_SHIFT) |
(crop->height << VI6_RPF_SRC_BSIZE_BVSIZE_SHIFT));
vsp1_rpf_write(rpf, dl, VI6_RPF_SRC_ESIZE,
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
} else {
rpf->offsets[1] = 0;
}
vsp1_rpf_write(rpf, dl, VI6_RPF_SRCM_PSTRIDE, pstride);
sink_format = vsp1_entity_get_pad_format(&rpf->entity,
rpf->entity.config,
RWPF_PAD_SINK);
source_format = vsp1_entity_get_pad_format(&rpf->entity,
rpf->entity.config,
RWPF_PAD_SOURCE);
infmt = VI6_RPF_INFMT_CIPM
| (fmtinfo->hwfmt << VI6_RPF_INFMT_RDFMT_SHIFT);
if (fmtinfo->swap_yc)
infmt |= VI6_RPF_INFMT_SPYCS;
if (fmtinfo->swap_uv)
infmt |= VI6_RPF_INFMT_SPUVS;
if (sink_format->code != source_format->code)
infmt |= VI6_RPF_INFMT_CSC;
vsp1_rpf_write(rpf, dl, VI6_RPF_INFMT, infmt);
vsp1_rpf_write(rpf, dl, VI6_RPF_DSWAP, fmtinfo->swap);
if (pipe->bru) {
const struct v4l2_rect *compose;
compose = vsp1_entity_get_pad_compose(pipe->bru,
pipe->bru->config,
rpf->bru_input);
left = compose->left;
top = compose->top;
}
vsp1_rpf_write(rpf, dl, VI6_RPF_LOC,
(left << VI6_RPF_LOC_HCOORD_SHIFT) |
(top << VI6_RPF_LOC_VCOORD_SHIFT));
vsp1_rpf_write(rpf, dl, VI6_RPF_ALPH_SEL, VI6_RPF_ALPH_SEL_AEXT_EXT |
(fmtinfo->alpha ? VI6_RPF_ALPH_SEL_ASEL_PACKED
: VI6_RPF_ALPH_SEL_ASEL_FIXED));
vsp1_rpf_write(rpf, dl, VI6_RPF_VRTCOL_SET,
rpf->alpha << VI6_RPF_VRTCOL_SET_LAYA_SHIFT);
if (entity->vsp1->info->gen == 3) {
u32 mult;
if (fmtinfo->alpha) {
bool premultiplied = format->flags
& V4L2_PIX_FMT_FLAG_PREMUL_ALPHA;
mult = VI6_RPF_MULT_ALPHA_A_MMD_RATIO
| (premultiplied ?
VI6_RPF_MULT_ALPHA_P_MMD_RATIO :
VI6_RPF_MULT_ALPHA_P_MMD_NONE)
| (rpf->alpha << VI6_RPF_MULT_ALPHA_RATIO_SHIFT);
} else {
mult = VI6_RPF_MULT_ALPHA_A_MMD_NONE
| VI6_RPF_MULT_ALPHA_P_MMD_NONE;
}
vsp1_rpf_write(rpf, dl, VI6_RPF_MULT_ALPHA, mult);
}
vsp1_pipeline_propagate_alpha(pipe, &rpf->entity, dl, rpf->alpha);
vsp1_rpf_write(rpf, dl, VI6_RPF_MSK_CTRL, 0);
vsp1_rpf_write(rpf, dl, VI6_RPF_CKEY_CTRL, 0);
}
struct vsp1_rwpf *vsp1_rpf_create(struct vsp1_device *vsp1, unsigned int index)
{
struct vsp1_rwpf *rpf;
char name[6];
int ret;
rpf = devm_kzalloc(vsp1->dev, sizeof(*rpf), GFP_KERNEL);
if (rpf == NULL)
return ERR_PTR(-ENOMEM);
rpf->max_width = RPF_MAX_WIDTH;
rpf->max_height = RPF_MAX_HEIGHT;
rpf->entity.ops = &rpf_entity_ops;
rpf->entity.type = VSP1_ENTITY_RPF;
rpf->entity.index = index;
sprintf(name, "rpf.%u", index);
ret = vsp1_entity_init(vsp1, &rpf->entity, name, 2, &rpf_ops);
if (ret < 0)
return ERR_PTR(ret);
ret = vsp1_rwpf_init_ctrls(rpf);
if (ret < 0) {
dev_err(vsp1->dev, "rpf%u: failed to initialize controls\n",
index);
goto error;
}
return rpf;
error:
vsp1_entity_destroy(&rpf->entity);
return ERR_PTR(ret);
}
