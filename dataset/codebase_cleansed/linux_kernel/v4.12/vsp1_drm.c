void vsp1_drm_display_start(struct vsp1_device *vsp1)
{
vsp1_dlm_irq_display_start(vsp1->drm->pipe.output->dlm);
}
int vsp1_du_init(struct device *dev)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
if (!vsp1)
return -EPROBE_DEFER;
return 0;
}
int vsp1_du_setup_lif(struct device *dev, const struct vsp1_du_lif_config *cfg)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
struct vsp1_pipeline *pipe = &vsp1->drm->pipe;
struct vsp1_bru *bru = vsp1->bru;
struct v4l2_subdev_format format;
unsigned int i;
int ret;
if (!cfg) {
ret = vsp1_pipeline_stop(pipe);
if (ret == -ETIMEDOUT)
dev_err(vsp1->dev, "DRM pipeline stop timeout\n");
media_pipeline_stop(&pipe->output->entity.subdev.entity);
for (i = 0; i < bru->entity.source_pad; ++i) {
vsp1->drm->inputs[i].enabled = false;
bru->inputs[i].rpf = NULL;
pipe->inputs[i] = NULL;
}
pipe->num_inputs = 0;
vsp1_dlm_reset(pipe->output->dlm);
vsp1_device_put(vsp1);
dev_dbg(vsp1->dev, "%s: pipeline disabled\n", __func__);
return 0;
}
dev_dbg(vsp1->dev, "%s: configuring LIF with format %ux%u\n",
__func__, cfg->width, cfg->height);
memset(&format, 0, sizeof(format));
format.which = V4L2_SUBDEV_FORMAT_ACTIVE;
for (i = 0; i < bru->entity.source_pad; ++i) {
format.pad = i;
format.format.width = cfg->width;
format.format.height = cfg->height;
format.format.code = MEDIA_BUS_FMT_ARGB8888_1X32;
format.format.field = V4L2_FIELD_NONE;
ret = v4l2_subdev_call(&bru->entity.subdev, pad,
set_fmt, NULL, &format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on BRU pad %u\n",
__func__, format.format.width, format.format.height,
format.format.code, i);
}
format.pad = bru->entity.source_pad;
format.format.width = cfg->width;
format.format.height = cfg->height;
format.format.code = MEDIA_BUS_FMT_ARGB8888_1X32;
format.format.field = V4L2_FIELD_NONE;
ret = v4l2_subdev_call(&bru->entity.subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on BRU pad %u\n",
__func__, format.format.width, format.format.height,
format.format.code, i);
format.pad = RWPF_PAD_SINK;
ret = v4l2_subdev_call(&vsp1->wpf[0]->entity.subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on WPF0 sink\n",
__func__, format.format.width, format.format.height,
format.format.code);
format.pad = RWPF_PAD_SOURCE;
ret = v4l2_subdev_call(&vsp1->wpf[0]->entity.subdev, pad, get_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: got format %ux%u (%x) on WPF0 source\n",
__func__, format.format.width, format.format.height,
format.format.code);
format.pad = LIF_PAD_SINK;
ret = v4l2_subdev_call(&vsp1->lif->entity.subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on LIF sink\n",
__func__, format.format.width, format.format.height,
format.format.code);
if (format.format.width != cfg->width ||
format.format.height != cfg->height ||
format.format.code != MEDIA_BUS_FMT_ARGB8888_1X32) {
dev_dbg(vsp1->dev, "%s: format mismatch\n", __func__);
return -EPIPE;
}
ret = vsp1_device_get(vsp1);
if (ret < 0)
return ret;
ret = media_pipeline_start(&pipe->output->entity.subdev.entity,
&pipe->pipe);
if (ret < 0) {
dev_dbg(vsp1->dev, "%s: pipeline start failed\n", __func__);
vsp1_device_put(vsp1);
return ret;
}
dev_dbg(vsp1->dev, "%s: pipeline enabled\n", __func__);
return 0;
}
void vsp1_du_atomic_begin(struct device *dev)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
struct vsp1_pipeline *pipe = &vsp1->drm->pipe;
vsp1->drm->num_inputs = pipe->num_inputs;
}
int vsp1_du_atomic_update(struct device *dev, unsigned int rpf_index,
const struct vsp1_du_atomic_config *cfg)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
const struct vsp1_format_info *fmtinfo;
struct vsp1_rwpf *rpf;
if (rpf_index >= vsp1->info->rpf_count)
return -EINVAL;
rpf = vsp1->rpf[rpf_index];
if (!cfg) {
dev_dbg(vsp1->dev, "%s: RPF%u: disable requested\n", __func__,
rpf_index);
vsp1->drm->inputs[rpf_index].enabled = false;
return 0;
}
dev_dbg(vsp1->dev,
"%s: RPF%u: (%u,%u)/%ux%u -> (%u,%u)/%ux%u (%08x), pitch %u dma { %pad, %pad, %pad } zpos %u\n",
__func__, rpf_index,
cfg->src.left, cfg->src.top, cfg->src.width, cfg->src.height,
cfg->dst.left, cfg->dst.top, cfg->dst.width, cfg->dst.height,
cfg->pixelformat, cfg->pitch, &cfg->mem[0], &cfg->mem[1],
&cfg->mem[2], cfg->zpos);
fmtinfo = vsp1_get_format_info(vsp1, cfg->pixelformat);
if (!fmtinfo) {
dev_dbg(vsp1->dev, "Unsupport pixel format %08x for RPF\n",
cfg->pixelformat);
return -EINVAL;
}
rpf->fmtinfo = fmtinfo;
rpf->format.num_planes = fmtinfo->planes;
rpf->format.plane_fmt[0].bytesperline = cfg->pitch;
rpf->format.plane_fmt[1].bytesperline = cfg->pitch;
rpf->alpha = cfg->alpha;
rpf->mem.addr[0] = cfg->mem[0];
rpf->mem.addr[1] = cfg->mem[1];
rpf->mem.addr[2] = cfg->mem[2];
vsp1->drm->inputs[rpf_index].crop = cfg->src;
vsp1->drm->inputs[rpf_index].compose = cfg->dst;
vsp1->drm->inputs[rpf_index].zpos = cfg->zpos;
vsp1->drm->inputs[rpf_index].enabled = true;
return 0;
}
static int vsp1_du_setup_rpf_pipe(struct vsp1_device *vsp1,
struct vsp1_rwpf *rpf, unsigned int bru_input)
{
struct v4l2_subdev_selection sel;
struct v4l2_subdev_format format;
const struct v4l2_rect *crop;
int ret;
crop = &vsp1->drm->inputs[rpf->entity.index].crop;
memset(&format, 0, sizeof(format));
format.which = V4L2_SUBDEV_FORMAT_ACTIVE;
format.pad = RWPF_PAD_SINK;
format.format.width = crop->width + crop->left;
format.format.height = crop->height + crop->top;
format.format.code = rpf->fmtinfo->mbus;
format.format.field = V4L2_FIELD_NONE;
ret = v4l2_subdev_call(&rpf->entity.subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev,
"%s: set format %ux%u (%x) on RPF%u sink\n",
__func__, format.format.width, format.format.height,
format.format.code, rpf->entity.index);
memset(&sel, 0, sizeof(sel));
sel.which = V4L2_SUBDEV_FORMAT_ACTIVE;
sel.pad = RWPF_PAD_SINK;
sel.target = V4L2_SEL_TGT_CROP;
sel.r = *crop;
ret = v4l2_subdev_call(&rpf->entity.subdev, pad, set_selection, NULL,
&sel);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev,
"%s: set selection (%u,%u)/%ux%u on RPF%u sink\n",
__func__, sel.r.left, sel.r.top, sel.r.width, sel.r.height,
rpf->entity.index);
format.pad = RWPF_PAD_SOURCE;
ret = v4l2_subdev_call(&rpf->entity.subdev, pad, get_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev,
"%s: got format %ux%u (%x) on RPF%u source\n",
__func__, format.format.width, format.format.height,
format.format.code, rpf->entity.index);
format.format.code = MEDIA_BUS_FMT_ARGB8888_1X32;
ret = v4l2_subdev_call(&rpf->entity.subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
format.pad = bru_input;
ret = v4l2_subdev_call(&vsp1->bru->entity.subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on BRU pad %u\n",
__func__, format.format.width, format.format.height,
format.format.code, format.pad);
sel.pad = bru_input;
sel.target = V4L2_SEL_TGT_COMPOSE;
sel.r = vsp1->drm->inputs[rpf->entity.index].compose;
ret = v4l2_subdev_call(&vsp1->bru->entity.subdev, pad, set_selection,
NULL, &sel);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev,
"%s: set selection (%u,%u)/%ux%u on BRU pad %u\n",
__func__, sel.r.left, sel.r.top, sel.r.width, sel.r.height,
sel.pad);
return 0;
}
static unsigned int rpf_zpos(struct vsp1_device *vsp1, struct vsp1_rwpf *rpf)
{
return vsp1->drm->inputs[rpf->entity.index].zpos;
}
void vsp1_du_atomic_flush(struct device *dev)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
struct vsp1_pipeline *pipe = &vsp1->drm->pipe;
struct vsp1_rwpf *inputs[VSP1_MAX_RPF] = { NULL, };
struct vsp1_entity *entity;
struct vsp1_dl_list *dl;
unsigned long flags;
unsigned int i;
int ret;
dl = vsp1_dl_list_get(pipe->output->dlm);
pipe->num_inputs = 0;
for (i = 0; i < vsp1->info->rpf_count; ++i) {
struct vsp1_rwpf *rpf = vsp1->rpf[i];
unsigned int j;
if (!vsp1->drm->inputs[i].enabled) {
pipe->inputs[i] = NULL;
continue;
}
pipe->inputs[i] = rpf;
for (j = pipe->num_inputs++; j > 0; --j) {
if (rpf_zpos(vsp1, inputs[j-1]) <= rpf_zpos(vsp1, rpf))
break;
inputs[j] = inputs[j-1];
}
inputs[j] = rpf;
}
for (i = 0; i < vsp1->info->num_bru_inputs; ++i) {
struct vsp1_rwpf *rpf = inputs[i];
if (!rpf) {
vsp1->bru->inputs[i].rpf = NULL;
continue;
}
vsp1->bru->inputs[i].rpf = rpf;
rpf->bru_input = i;
rpf->entity.sink_pad = i;
dev_dbg(vsp1->dev, "%s: connecting RPF.%u to BRU:%u\n",
__func__, rpf->entity.index, i);
ret = vsp1_du_setup_rpf_pipe(vsp1, rpf, i);
if (ret < 0)
dev_err(vsp1->dev,
"%s: failed to setup RPF.%u\n",
__func__, rpf->entity.index);
}
list_for_each_entry(entity, &pipe->entities, list_pipe) {
if (entity->type == VSP1_ENTITY_RPF) {
struct vsp1_rwpf *rpf = to_rwpf(&entity->subdev);
if (!pipe->inputs[rpf->entity.index]) {
vsp1_dl_list_write(dl, entity->route->reg,
VI6_DPR_NODE_UNUSED);
continue;
}
}
vsp1_entity_route_setup(entity, pipe, dl);
if (entity->ops->configure) {
entity->ops->configure(entity, pipe, dl,
VSP1_ENTITY_PARAMS_INIT);
entity->ops->configure(entity, pipe, dl,
VSP1_ENTITY_PARAMS_RUNTIME);
entity->ops->configure(entity, pipe, dl,
VSP1_ENTITY_PARAMS_PARTITION);
}
}
vsp1_dl_list_commit(dl);
if (!vsp1->drm->num_inputs && pipe->num_inputs) {
vsp1_write(vsp1, VI6_DISP_IRQ_STA, 0);
vsp1_write(vsp1, VI6_DISP_IRQ_ENB, VI6_DISP_IRQ_ENB_DSTE);
spin_lock_irqsave(&pipe->irqlock, flags);
vsp1_pipeline_run(pipe);
spin_unlock_irqrestore(&pipe->irqlock, flags);
} else if (vsp1->drm->num_inputs && !pipe->num_inputs) {
vsp1_write(vsp1, VI6_DISP_IRQ_ENB, 0);
vsp1_pipeline_stop(pipe);
}
}
int vsp1_drm_create_links(struct vsp1_device *vsp1)
{
const u32 flags = MEDIA_LNK_FL_ENABLED | MEDIA_LNK_FL_IMMUTABLE;
unsigned int i;
int ret;
if (!vsp1->bru || !vsp1->lif)
return -ENXIO;
for (i = 0; i < vsp1->info->rpf_count; ++i) {
struct vsp1_rwpf *rpf = vsp1->rpf[i];
ret = media_create_pad_link(&rpf->entity.subdev.entity,
RWPF_PAD_SOURCE,
&vsp1->bru->entity.subdev.entity,
i, flags);
if (ret < 0)
return ret;
rpf->entity.sink = &vsp1->bru->entity.subdev.entity;
rpf->entity.sink_pad = i;
}
ret = media_create_pad_link(&vsp1->bru->entity.subdev.entity,
vsp1->bru->entity.source_pad,
&vsp1->wpf[0]->entity.subdev.entity,
RWPF_PAD_SINK, flags);
if (ret < 0)
return ret;
vsp1->bru->entity.sink = &vsp1->wpf[0]->entity.subdev.entity;
vsp1->bru->entity.sink_pad = RWPF_PAD_SINK;
ret = media_create_pad_link(&vsp1->wpf[0]->entity.subdev.entity,
RWPF_PAD_SOURCE,
&vsp1->lif->entity.subdev.entity,
LIF_PAD_SINK, flags);
if (ret < 0)
return ret;
return 0;
}
int vsp1_drm_init(struct vsp1_device *vsp1)
{
struct vsp1_pipeline *pipe;
unsigned int i;
vsp1->drm = devm_kzalloc(vsp1->dev, sizeof(*vsp1->drm), GFP_KERNEL);
if (!vsp1->drm)
return -ENOMEM;
pipe = &vsp1->drm->pipe;
vsp1_pipeline_init(pipe);
for (i = 0; i < vsp1->info->rpf_count; ++i) {
struct vsp1_rwpf *input = vsp1->rpf[i];
list_add_tail(&input->entity.list_pipe, &pipe->entities);
}
list_add_tail(&vsp1->bru->entity.list_pipe, &pipe->entities);
list_add_tail(&vsp1->wpf[0]->entity.list_pipe, &pipe->entities);
list_add_tail(&vsp1->lif->entity.list_pipe, &pipe->entities);
pipe->bru = &vsp1->bru->entity;
pipe->lif = &vsp1->lif->entity;
pipe->output = vsp1->wpf[0];
pipe->output->pipe = pipe;
return 0;
}
void vsp1_drm_cleanup(struct vsp1_device *vsp1)
{
}
