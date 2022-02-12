static void vsp1_du_pipeline_frame_end(struct vsp1_pipeline *pipe,
bool completed)
{
struct vsp1_drm_pipeline *drm_pipe = to_vsp1_drm_pipeline(pipe);
if (drm_pipe->du_complete)
drm_pipe->du_complete(drm_pipe->du_private, completed);
}
int vsp1_du_init(struct device *dev)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
if (!vsp1)
return -EPROBE_DEFER;
return 0;
}
int vsp1_du_setup_lif(struct device *dev, unsigned int pipe_index,
const struct vsp1_du_lif_config *cfg)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
struct vsp1_drm_pipeline *drm_pipe;
struct vsp1_pipeline *pipe;
struct vsp1_bru *bru;
struct v4l2_subdev_format format;
const char *bru_name;
unsigned int i;
int ret;
if (pipe_index >= vsp1->info->lif_count)
return -EINVAL;
drm_pipe = &vsp1->drm->pipe[pipe_index];
pipe = &drm_pipe->pipe;
bru = to_bru(&pipe->bru->subdev);
bru_name = pipe->bru->type == VSP1_ENTITY_BRU ? "BRU" : "BRS";
if (!cfg) {
ret = vsp1_pipeline_stop(pipe);
if (ret == -ETIMEDOUT)
dev_err(vsp1->dev, "DRM pipeline stop timeout\n");
media_pipeline_stop(&pipe->output->entity.subdev.entity);
for (i = 0; i < ARRAY_SIZE(pipe->inputs); ++i) {
struct vsp1_rwpf *rpf = pipe->inputs[i];
if (!rpf)
continue;
WARN_ON(list_empty(&rpf->entity.list_pipe));
list_del_init(&rpf->entity.list_pipe);
pipe->inputs[i] = NULL;
bru->inputs[rpf->bru_input].rpf = NULL;
}
drm_pipe->du_complete = NULL;
pipe->num_inputs = 0;
vsp1_dlm_reset(pipe->output->dlm);
vsp1_device_put(vsp1);
dev_dbg(vsp1->dev, "%s: pipeline disabled\n", __func__);
return 0;
}
dev_dbg(vsp1->dev, "%s: configuring LIF%u with format %ux%u\n",
__func__, pipe_index, cfg->width, cfg->height);
memset(&format, 0, sizeof(format));
format.which = V4L2_SUBDEV_FORMAT_ACTIVE;
for (i = 0; i < pipe->bru->source_pad; ++i) {
format.pad = i;
format.format.width = cfg->width;
format.format.height = cfg->height;
format.format.code = MEDIA_BUS_FMT_ARGB8888_1X32;
format.format.field = V4L2_FIELD_NONE;
ret = v4l2_subdev_call(&pipe->bru->subdev, pad,
set_fmt, NULL, &format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on %s pad %u\n",
__func__, format.format.width, format.format.height,
format.format.code, bru_name, i);
}
format.pad = pipe->bru->source_pad;
format.format.width = cfg->width;
format.format.height = cfg->height;
format.format.code = MEDIA_BUS_FMT_ARGB8888_1X32;
format.format.field = V4L2_FIELD_NONE;
ret = v4l2_subdev_call(&pipe->bru->subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on %s pad %u\n",
__func__, format.format.width, format.format.height,
format.format.code, bru_name, i);
format.pad = RWPF_PAD_SINK;
ret = v4l2_subdev_call(&pipe->output->entity.subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on WPF%u sink\n",
__func__, format.format.width, format.format.height,
format.format.code, pipe->output->entity.index);
format.pad = RWPF_PAD_SOURCE;
ret = v4l2_subdev_call(&pipe->output->entity.subdev, pad, get_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: got format %ux%u (%x) on WPF%u source\n",
__func__, format.format.width, format.format.height,
format.format.code, pipe->output->entity.index);
format.pad = LIF_PAD_SINK;
ret = v4l2_subdev_call(&pipe->lif->subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on LIF%u sink\n",
__func__, format.format.width, format.format.height,
format.format.code, pipe_index);
if (format.format.width != cfg->width ||
format.format.height != cfg->height ||
format.format.code != MEDIA_BUS_FMT_ARGB8888_1X32) {
dev_dbg(vsp1->dev, "%s: format mismatch\n", __func__);
return -EPIPE;
}
ret = vsp1_device_get(vsp1);
if (ret < 0)
return ret;
drm_pipe->du_complete = cfg->callback;
drm_pipe->du_private = cfg->callback_data;
ret = media_pipeline_start(&pipe->output->entity.subdev.entity,
&pipe->pipe);
if (ret < 0) {
dev_dbg(vsp1->dev, "%s: pipeline start failed\n", __func__);
vsp1_device_put(vsp1);
return ret;
}
vsp1_write(vsp1, VI6_DISP_IRQ_STA, 0);
vsp1_write(vsp1, VI6_DISP_IRQ_ENB, 0);
dev_dbg(vsp1->dev, "%s: pipeline enabled\n", __func__);
return 0;
}
void vsp1_du_atomic_begin(struct device *dev, unsigned int pipe_index)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
struct vsp1_drm_pipeline *drm_pipe = &vsp1->drm->pipe[pipe_index];
drm_pipe->enabled = drm_pipe->pipe.num_inputs != 0;
}
int vsp1_du_atomic_update(struct device *dev, unsigned int pipe_index,
unsigned int rpf_index,
const struct vsp1_du_atomic_config *cfg)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
struct vsp1_drm_pipeline *drm_pipe = &vsp1->drm->pipe[pipe_index];
const struct vsp1_format_info *fmtinfo;
struct vsp1_rwpf *rpf;
if (rpf_index >= vsp1->info->rpf_count)
return -EINVAL;
rpf = vsp1->rpf[rpf_index];
if (!cfg) {
dev_dbg(vsp1->dev, "%s: RPF%u: disable requested\n", __func__,
rpf_index);
drm_pipe->pipe.inputs[rpf_index] = NULL;
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
drm_pipe->pipe.inputs[rpf_index] = rpf;
return 0;
}
static int vsp1_du_setup_rpf_pipe(struct vsp1_device *vsp1,
struct vsp1_pipeline *pipe,
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
ret = v4l2_subdev_call(&pipe->bru->subdev, pad, set_fmt, NULL,
&format);
if (ret < 0)
return ret;
dev_dbg(vsp1->dev, "%s: set format %ux%u (%x) on BRU pad %u\n",
__func__, format.format.width, format.format.height,
format.format.code, format.pad);
sel.pad = bru_input;
sel.target = V4L2_SEL_TGT_COMPOSE;
sel.r = vsp1->drm->inputs[rpf->entity.index].compose;
ret = v4l2_subdev_call(&pipe->bru->subdev, pad, set_selection, NULL,
&sel);
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
void vsp1_du_atomic_flush(struct device *dev, unsigned int pipe_index)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
struct vsp1_drm_pipeline *drm_pipe = &vsp1->drm->pipe[pipe_index];
struct vsp1_pipeline *pipe = &drm_pipe->pipe;
struct vsp1_rwpf *inputs[VSP1_MAX_RPF] = { NULL, };
struct vsp1_bru *bru = to_bru(&pipe->bru->subdev);
struct vsp1_entity *entity;
struct vsp1_entity *next;
struct vsp1_dl_list *dl;
const char *bru_name;
unsigned long flags;
unsigned int i;
int ret;
bru_name = pipe->bru->type == VSP1_ENTITY_BRU ? "BRU" : "BRS";
dl = vsp1_dl_list_get(pipe->output->dlm);
pipe->num_inputs = 0;
for (i = 0; i < vsp1->info->rpf_count; ++i) {
struct vsp1_rwpf *rpf = vsp1->rpf[i];
unsigned int j;
if (!pipe->inputs[i])
continue;
for (j = pipe->num_inputs++; j > 0; --j) {
if (rpf_zpos(vsp1, inputs[j-1]) <= rpf_zpos(vsp1, rpf))
break;
inputs[j] = inputs[j-1];
}
inputs[j] = rpf;
}
for (i = 0; i < pipe->bru->source_pad; ++i) {
struct vsp1_rwpf *rpf = inputs[i];
if (!rpf) {
bru->inputs[i].rpf = NULL;
continue;
}
if (list_empty(&rpf->entity.list_pipe))
list_add_tail(&rpf->entity.list_pipe, &pipe->entities);
bru->inputs[i].rpf = rpf;
rpf->bru_input = i;
rpf->entity.sink = pipe->bru;
rpf->entity.sink_pad = i;
dev_dbg(vsp1->dev, "%s: connecting RPF.%u to %s:%u\n",
__func__, rpf->entity.index, bru_name, i);
ret = vsp1_du_setup_rpf_pipe(vsp1, pipe, rpf, i);
if (ret < 0)
dev_err(vsp1->dev,
"%s: failed to setup RPF.%u\n",
__func__, rpf->entity.index);
}
list_for_each_entry_safe(entity, next, &pipe->entities, list_pipe) {
if (entity->type == VSP1_ENTITY_RPF &&
!pipe->inputs[entity->index]) {
vsp1_dl_list_write(dl, entity->route->reg,
VI6_DPR_NODE_UNUSED);
list_del_init(&entity->list_pipe);
continue;
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
if (!drm_pipe->enabled && pipe->num_inputs) {
spin_lock_irqsave(&pipe->irqlock, flags);
vsp1_pipeline_run(pipe);
spin_unlock_irqrestore(&pipe->irqlock, flags);
} else if (drm_pipe->enabled && !pipe->num_inputs) {
vsp1_pipeline_stop(pipe);
}
}
int vsp1_du_map_sg(struct device *dev, struct sg_table *sgt)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
return dma_map_sg_attrs(vsp1->bus_master, sgt->sgl, sgt->nents,
DMA_TO_DEVICE, DMA_ATTR_SKIP_CPU_SYNC);
}
void vsp1_du_unmap_sg(struct device *dev, struct sg_table *sgt)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
dma_unmap_sg_attrs(vsp1->bus_master, sgt->sgl, sgt->nents,
DMA_TO_DEVICE, DMA_ATTR_SKIP_CPU_SYNC);
}
int vsp1_drm_init(struct vsp1_device *vsp1)
{
unsigned int i;
vsp1->drm = devm_kzalloc(vsp1->dev, sizeof(*vsp1->drm), GFP_KERNEL);
if (!vsp1->drm)
return -ENOMEM;
for (i = 0; i < vsp1->info->lif_count; ++i) {
struct vsp1_drm_pipeline *drm_pipe = &vsp1->drm->pipe[i];
struct vsp1_pipeline *pipe = &drm_pipe->pipe;
vsp1_pipeline_init(pipe);
pipe->bru = i == 0 ? &vsp1->bru->entity : &vsp1->brs->entity;
pipe->lif = &vsp1->lif[i]->entity;
pipe->output = vsp1->wpf[i];
pipe->output->pipe = pipe;
pipe->frame_end = vsp1_du_pipeline_frame_end;
pipe->bru->sink = &pipe->output->entity;
pipe->bru->sink_pad = 0;
pipe->output->entity.sink = pipe->lif;
pipe->output->entity.sink_pad = 0;
list_add_tail(&pipe->bru->list_pipe, &pipe->entities);
list_add_tail(&pipe->lif->list_pipe, &pipe->entities);
list_add_tail(&pipe->output->entity.list_pipe, &pipe->entities);
}
for (i = 0; i < vsp1->info->rpf_count; ++i) {
struct vsp1_rwpf *input = vsp1->rpf[i];
INIT_LIST_HEAD(&input->entity.list_pipe);
}
return 0;
}
void vsp1_drm_cleanup(struct vsp1_device *vsp1)
{
}
