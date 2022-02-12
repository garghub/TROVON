const struct vsp1_format_info *vsp1_get_format_info(struct vsp1_device *vsp1,
u32 fourcc)
{
unsigned int i;
if (vsp1->info->gen != 2) {
switch (fourcc) {
case V4L2_PIX_FMT_VYUY:
case V4L2_PIX_FMT_HSV24:
case V4L2_PIX_FMT_HSV32:
return NULL;
}
}
for (i = 0; i < ARRAY_SIZE(vsp1_video_formats); ++i) {
const struct vsp1_format_info *info = &vsp1_video_formats[i];
if (info->fourcc == fourcc)
return info;
}
return NULL;
}
void vsp1_pipeline_reset(struct vsp1_pipeline *pipe)
{
unsigned int i;
if (pipe->bru) {
struct vsp1_bru *bru = to_bru(&pipe->bru->subdev);
for (i = 0; i < ARRAY_SIZE(bru->inputs); ++i)
bru->inputs[i].rpf = NULL;
}
for (i = 0; i < ARRAY_SIZE(pipe->inputs); ++i) {
if (pipe->inputs[i]) {
pipe->inputs[i]->pipe = NULL;
pipe->inputs[i] = NULL;
}
}
if (pipe->output) {
pipe->output->pipe = NULL;
pipe->output = NULL;
}
if (pipe->hgo) {
struct vsp1_hgo *hgo = to_hgo(&pipe->hgo->subdev);
hgo->histo.pipe = NULL;
}
if (pipe->hgt) {
struct vsp1_hgt *hgt = to_hgt(&pipe->hgt->subdev);
hgt->histo.pipe = NULL;
}
INIT_LIST_HEAD(&pipe->entities);
pipe->state = VSP1_PIPELINE_STOPPED;
pipe->buffers_ready = 0;
pipe->num_inputs = 0;
pipe->bru = NULL;
pipe->hgo = NULL;
pipe->hgt = NULL;
pipe->lif = NULL;
pipe->uds = NULL;
}
void vsp1_pipeline_init(struct vsp1_pipeline *pipe)
{
mutex_init(&pipe->lock);
spin_lock_init(&pipe->irqlock);
init_waitqueue_head(&pipe->wq);
kref_init(&pipe->kref);
INIT_LIST_HEAD(&pipe->entities);
pipe->state = VSP1_PIPELINE_STOPPED;
}
void vsp1_pipeline_run(struct vsp1_pipeline *pipe)
{
struct vsp1_device *vsp1 = pipe->output->entity.vsp1;
if (pipe->state == VSP1_PIPELINE_STOPPED) {
vsp1_write(vsp1, VI6_CMD(pipe->output->entity.index),
VI6_CMD_STRCMD);
pipe->state = VSP1_PIPELINE_RUNNING;
}
pipe->buffers_ready = 0;
}
bool vsp1_pipeline_stopped(struct vsp1_pipeline *pipe)
{
unsigned long flags;
bool stopped;
spin_lock_irqsave(&pipe->irqlock, flags);
stopped = pipe->state == VSP1_PIPELINE_STOPPED;
spin_unlock_irqrestore(&pipe->irqlock, flags);
return stopped;
}
int vsp1_pipeline_stop(struct vsp1_pipeline *pipe)
{
struct vsp1_device *vsp1 = pipe->output->entity.vsp1;
struct vsp1_entity *entity;
unsigned long flags;
int ret;
if (pipe->lif) {
ret = vsp1_reset_wpf(vsp1, pipe->output->entity.index);
if (ret == 0) {
spin_lock_irqsave(&pipe->irqlock, flags);
pipe->state = VSP1_PIPELINE_STOPPED;
spin_unlock_irqrestore(&pipe->irqlock, flags);
}
} else {
spin_lock_irqsave(&pipe->irqlock, flags);
if (pipe->state == VSP1_PIPELINE_RUNNING)
pipe->state = VSP1_PIPELINE_STOPPING;
spin_unlock_irqrestore(&pipe->irqlock, flags);
ret = wait_event_timeout(pipe->wq, vsp1_pipeline_stopped(pipe),
msecs_to_jiffies(500));
ret = ret == 0 ? -ETIMEDOUT : 0;
}
list_for_each_entry(entity, &pipe->entities, list_pipe) {
if (entity->route && entity->route->reg)
vsp1_write(vsp1, entity->route->reg,
VI6_DPR_NODE_UNUSED);
}
if (pipe->hgo)
vsp1_write(vsp1, VI6_DPR_HGO_SMPPT,
(7 << VI6_DPR_SMPPT_TGW_SHIFT) |
(VI6_DPR_NODE_UNUSED << VI6_DPR_SMPPT_PT_SHIFT));
if (pipe->hgt)
vsp1_write(vsp1, VI6_DPR_HGT_SMPPT,
(7 << VI6_DPR_SMPPT_TGW_SHIFT) |
(VI6_DPR_NODE_UNUSED << VI6_DPR_SMPPT_PT_SHIFT));
v4l2_subdev_call(&pipe->output->entity.subdev, video, s_stream, 0);
return ret;
}
bool vsp1_pipeline_ready(struct vsp1_pipeline *pipe)
{
unsigned int mask;
mask = ((1 << pipe->num_inputs) - 1) << 1;
if (!pipe->lif)
mask |= 1 << 0;
return pipe->buffers_ready == mask;
}
void vsp1_pipeline_frame_end(struct vsp1_pipeline *pipe)
{
bool completed;
if (pipe == NULL)
return;
completed = vsp1_dlm_irq_frame_end(pipe->output->dlm);
if (!completed) {
return;
}
if (pipe->hgo)
vsp1_hgo_frame_end(pipe->hgo);
if (pipe->hgt)
vsp1_hgt_frame_end(pipe->hgt);
if (pipe->frame_end)
pipe->frame_end(pipe);
pipe->sequence++;
}
void vsp1_pipeline_propagate_alpha(struct vsp1_pipeline *pipe,
struct vsp1_dl_list *dl, unsigned int alpha)
{
if (!pipe->uds)
return;
if (pipe->uds_input->type == VSP1_ENTITY_BRU)
alpha = 255;
vsp1_uds_set_alpha(pipe->uds, dl, alpha);
}
void vsp1_pipelines_suspend(struct vsp1_device *vsp1)
{
unsigned long flags;
unsigned int i;
int ret;
for (i = 0; i < vsp1->info->wpf_count; ++i) {
struct vsp1_rwpf *wpf = vsp1->wpf[i];
struct vsp1_pipeline *pipe;
if (wpf == NULL)
continue;
pipe = wpf->pipe;
if (pipe == NULL)
continue;
spin_lock_irqsave(&pipe->irqlock, flags);
if (pipe->state == VSP1_PIPELINE_RUNNING)
pipe->state = VSP1_PIPELINE_STOPPING;
spin_unlock_irqrestore(&pipe->irqlock, flags);
}
for (i = 0; i < vsp1->info->wpf_count; ++i) {
struct vsp1_rwpf *wpf = vsp1->wpf[i];
struct vsp1_pipeline *pipe;
if (wpf == NULL)
continue;
pipe = wpf->pipe;
if (pipe == NULL)
continue;
ret = wait_event_timeout(pipe->wq, vsp1_pipeline_stopped(pipe),
msecs_to_jiffies(500));
if (ret == 0)
dev_warn(vsp1->dev, "pipeline %u stop timeout\n",
wpf->entity.index);
}
}
void vsp1_pipelines_resume(struct vsp1_device *vsp1)
{
unsigned long flags;
unsigned int i;
for (i = 0; i < vsp1->info->wpf_count; ++i) {
struct vsp1_rwpf *wpf = vsp1->wpf[i];
struct vsp1_pipeline *pipe;
if (wpf == NULL)
continue;
pipe = wpf->pipe;
if (pipe == NULL)
continue;
spin_lock_irqsave(&pipe->irqlock, flags);
if (vsp1_pipeline_ready(pipe))
vsp1_pipeline_run(pipe);
spin_unlock_irqrestore(&pipe->irqlock, flags);
}
}
