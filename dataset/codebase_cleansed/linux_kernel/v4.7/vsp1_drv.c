static irqreturn_t vsp1_irq_handler(int irq, void *data)
{
u32 mask = VI6_WFP_IRQ_STA_DFE | VI6_WFP_IRQ_STA_FRE;
struct vsp1_device *vsp1 = data;
irqreturn_t ret = IRQ_NONE;
unsigned int i;
u32 status;
for (i = 0; i < vsp1->info->wpf_count; ++i) {
struct vsp1_rwpf *wpf = vsp1->wpf[i];
if (wpf == NULL)
continue;
status = vsp1_read(vsp1, VI6_WPF_IRQ_STA(i));
vsp1_write(vsp1, VI6_WPF_IRQ_STA(i), ~status & mask);
if (status & VI6_WFP_IRQ_STA_FRE) {
vsp1_pipeline_frame_end(wpf->pipe);
ret = IRQ_HANDLED;
}
}
status = vsp1_read(vsp1, VI6_DISP_IRQ_STA);
vsp1_write(vsp1, VI6_DISP_IRQ_STA, ~status & VI6_DISP_IRQ_STA_DST);
if (status & VI6_DISP_IRQ_STA_DST) {
vsp1_drm_display_start(vsp1);
ret = IRQ_HANDLED;
}
return ret;
}
static int vsp1_create_sink_links(struct vsp1_device *vsp1,
struct vsp1_entity *sink)
{
struct media_entity *entity = &sink->subdev.entity;
struct vsp1_entity *source;
unsigned int pad;
int ret;
list_for_each_entry(source, &vsp1->entities, list_dev) {
u32 flags;
if (source->type == sink->type)
continue;
if (source->type == VSP1_ENTITY_LIF ||
source->type == VSP1_ENTITY_WPF)
continue;
flags = source->type == VSP1_ENTITY_RPF &&
sink->type == VSP1_ENTITY_WPF &&
source->index == sink->index
? MEDIA_LNK_FL_ENABLED : 0;
for (pad = 0; pad < entity->num_pads; ++pad) {
if (!(entity->pads[pad].flags & MEDIA_PAD_FL_SINK))
continue;
ret = media_create_pad_link(&source->subdev.entity,
source->source_pad,
entity, pad, flags);
if (ret < 0)
return ret;
if (flags & MEDIA_LNK_FL_ENABLED)
source->sink = entity;
}
}
return 0;
}
static int vsp1_uapi_create_links(struct vsp1_device *vsp1)
{
struct vsp1_entity *entity;
unsigned int i;
int ret;
list_for_each_entry(entity, &vsp1->entities, list_dev) {
if (entity->type == VSP1_ENTITY_LIF ||
entity->type == VSP1_ENTITY_RPF)
continue;
ret = vsp1_create_sink_links(vsp1, entity);
if (ret < 0)
return ret;
}
if (vsp1->info->features & VSP1_HAS_LIF) {
ret = media_create_pad_link(&vsp1->wpf[0]->entity.subdev.entity,
RWPF_PAD_SOURCE,
&vsp1->lif->entity.subdev.entity,
LIF_PAD_SINK, 0);
if (ret < 0)
return ret;
}
for (i = 0; i < vsp1->info->rpf_count; ++i) {
struct vsp1_rwpf *rpf = vsp1->rpf[i];
ret = media_create_pad_link(&rpf->video->video.entity, 0,
&rpf->entity.subdev.entity,
RWPF_PAD_SINK,
MEDIA_LNK_FL_ENABLED |
MEDIA_LNK_FL_IMMUTABLE);
if (ret < 0)
return ret;
}
for (i = 0; i < vsp1->info->wpf_count; ++i) {
struct vsp1_rwpf *wpf = vsp1->wpf[i];
unsigned int flags = MEDIA_LNK_FL_ENABLED;
if (!(vsp1->info->features & VSP1_HAS_LIF) || i != 0)
flags |= MEDIA_LNK_FL_IMMUTABLE;
ret = media_create_pad_link(&wpf->entity.subdev.entity,
RWPF_PAD_SOURCE,
&wpf->video->video.entity, 0,
flags);
if (ret < 0)
return ret;
}
return 0;
}
static void vsp1_destroy_entities(struct vsp1_device *vsp1)
{
struct vsp1_entity *entity, *_entity;
struct vsp1_video *video, *_video;
list_for_each_entry_safe(entity, _entity, &vsp1->entities, list_dev) {
list_del(&entity->list_dev);
vsp1_entity_destroy(entity);
}
list_for_each_entry_safe(video, _video, &vsp1->videos, list) {
list_del(&video->list);
vsp1_video_cleanup(video);
}
v4l2_device_unregister(&vsp1->v4l2_dev);
media_device_unregister(&vsp1->media_dev);
media_device_cleanup(&vsp1->media_dev);
if (!vsp1->info->uapi)
vsp1_drm_cleanup(vsp1);
}
static int vsp1_create_entities(struct vsp1_device *vsp1)
{
struct media_device *mdev = &vsp1->media_dev;
struct v4l2_device *vdev = &vsp1->v4l2_dev;
struct vsp1_entity *entity;
unsigned int i;
int ret;
mdev->dev = vsp1->dev;
strlcpy(mdev->model, "VSP1", sizeof(mdev->model));
snprintf(mdev->bus_info, sizeof(mdev->bus_info), "platform:%s",
dev_name(mdev->dev));
media_device_init(mdev);
vsp1->media_ops.link_setup = vsp1_entity_link_setup;
if (vsp1->info->uapi)
vsp1->media_ops.link_validate = v4l2_subdev_link_validate;
vdev->mdev = mdev;
ret = v4l2_device_register(vsp1->dev, vdev);
if (ret < 0) {
dev_err(vsp1->dev, "V4L2 device registration failed (%d)\n",
ret);
goto done;
}
if (vsp1->info->features & VSP1_HAS_BRU) {
vsp1->bru = vsp1_bru_create(vsp1);
if (IS_ERR(vsp1->bru)) {
ret = PTR_ERR(vsp1->bru);
goto done;
}
list_add_tail(&vsp1->bru->entity.list_dev, &vsp1->entities);
}
vsp1->hsi = vsp1_hsit_create(vsp1, true);
if (IS_ERR(vsp1->hsi)) {
ret = PTR_ERR(vsp1->hsi);
goto done;
}
list_add_tail(&vsp1->hsi->entity.list_dev, &vsp1->entities);
vsp1->hst = vsp1_hsit_create(vsp1, false);
if (IS_ERR(vsp1->hst)) {
ret = PTR_ERR(vsp1->hst);
goto done;
}
list_add_tail(&vsp1->hst->entity.list_dev, &vsp1->entities);
if (vsp1->info->features & VSP1_HAS_LIF) {
vsp1->lif = vsp1_lif_create(vsp1);
if (IS_ERR(vsp1->lif)) {
ret = PTR_ERR(vsp1->lif);
goto done;
}
list_add_tail(&vsp1->lif->entity.list_dev, &vsp1->entities);
}
if (vsp1->info->features & VSP1_HAS_LUT) {
vsp1->lut = vsp1_lut_create(vsp1);
if (IS_ERR(vsp1->lut)) {
ret = PTR_ERR(vsp1->lut);
goto done;
}
list_add_tail(&vsp1->lut->entity.list_dev, &vsp1->entities);
}
for (i = 0; i < vsp1->info->rpf_count; ++i) {
struct vsp1_rwpf *rpf;
rpf = vsp1_rpf_create(vsp1, i);
if (IS_ERR(rpf)) {
ret = PTR_ERR(rpf);
goto done;
}
vsp1->rpf[i] = rpf;
list_add_tail(&rpf->entity.list_dev, &vsp1->entities);
if (vsp1->info->uapi) {
struct vsp1_video *video = vsp1_video_create(vsp1, rpf);
if (IS_ERR(video)) {
ret = PTR_ERR(video);
goto done;
}
list_add_tail(&video->list, &vsp1->videos);
}
}
if (vsp1->info->features & VSP1_HAS_SRU) {
vsp1->sru = vsp1_sru_create(vsp1);
if (IS_ERR(vsp1->sru)) {
ret = PTR_ERR(vsp1->sru);
goto done;
}
list_add_tail(&vsp1->sru->entity.list_dev, &vsp1->entities);
}
for (i = 0; i < vsp1->info->uds_count; ++i) {
struct vsp1_uds *uds;
uds = vsp1_uds_create(vsp1, i);
if (IS_ERR(uds)) {
ret = PTR_ERR(uds);
goto done;
}
vsp1->uds[i] = uds;
list_add_tail(&uds->entity.list_dev, &vsp1->entities);
}
for (i = 0; i < vsp1->info->wpf_count; ++i) {
struct vsp1_rwpf *wpf;
wpf = vsp1_wpf_create(vsp1, i);
if (IS_ERR(wpf)) {
ret = PTR_ERR(wpf);
goto done;
}
vsp1->wpf[i] = wpf;
list_add_tail(&wpf->entity.list_dev, &vsp1->entities);
if (vsp1->info->uapi) {
struct vsp1_video *video = vsp1_video_create(vsp1, wpf);
if (IS_ERR(video)) {
ret = PTR_ERR(video);
goto done;
}
list_add_tail(&video->list, &vsp1->videos);
wpf->entity.sink = &video->video.entity;
}
}
list_for_each_entry(entity, &vsp1->entities, list_dev) {
ret = v4l2_device_register_subdev(&vsp1->v4l2_dev,
&entity->subdev);
if (ret < 0)
goto done;
}
if (vsp1->info->uapi)
ret = vsp1_uapi_create_links(vsp1);
else
ret = vsp1_drm_create_links(vsp1);
if (ret < 0)
goto done;
if (vsp1->info->uapi)
ret = v4l2_device_register_subdev_nodes(&vsp1->v4l2_dev);
else
ret = vsp1_drm_init(vsp1);
if (ret < 0)
goto done;
ret = media_device_register(mdev);
done:
if (ret < 0)
vsp1_destroy_entities(vsp1);
return ret;
}
int vsp1_reset_wpf(struct vsp1_device *vsp1, unsigned int index)
{
unsigned int timeout;
u32 status;
status = vsp1_read(vsp1, VI6_STATUS);
if (!(status & VI6_STATUS_SYS_ACT(index)))
return 0;
vsp1_write(vsp1, VI6_SRESET, VI6_SRESET_SRTS(index));
for (timeout = 10; timeout > 0; --timeout) {
status = vsp1_read(vsp1, VI6_STATUS);
if (!(status & VI6_STATUS_SYS_ACT(index)))
break;
usleep_range(1000, 2000);
}
if (!timeout) {
dev_err(vsp1->dev, "failed to reset wpf.%u\n", index);
return -ETIMEDOUT;
}
return 0;
}
static int vsp1_device_init(struct vsp1_device *vsp1)
{
unsigned int i;
int ret;
for (i = 0; i < vsp1->info->wpf_count; ++i) {
ret = vsp1_reset_wpf(vsp1, i);
if (ret < 0)
return ret;
}
vsp1_write(vsp1, VI6_CLK_DCSWT, (8 << VI6_CLK_DCSWT_CSTPW_SHIFT) |
(8 << VI6_CLK_DCSWT_CSTRW_SHIFT));
for (i = 0; i < vsp1->info->rpf_count; ++i)
vsp1_write(vsp1, VI6_DPR_RPF_ROUTE(i), VI6_DPR_NODE_UNUSED);
for (i = 0; i < vsp1->info->uds_count; ++i)
vsp1_write(vsp1, VI6_DPR_UDS_ROUTE(i), VI6_DPR_NODE_UNUSED);
vsp1_write(vsp1, VI6_DPR_SRU_ROUTE, VI6_DPR_NODE_UNUSED);
vsp1_write(vsp1, VI6_DPR_LUT_ROUTE, VI6_DPR_NODE_UNUSED);
vsp1_write(vsp1, VI6_DPR_CLU_ROUTE, VI6_DPR_NODE_UNUSED);
vsp1_write(vsp1, VI6_DPR_HST_ROUTE, VI6_DPR_NODE_UNUSED);
vsp1_write(vsp1, VI6_DPR_HSI_ROUTE, VI6_DPR_NODE_UNUSED);
vsp1_write(vsp1, VI6_DPR_BRU_ROUTE, VI6_DPR_NODE_UNUSED);
vsp1_write(vsp1, VI6_DPR_HGO_SMPPT, (7 << VI6_DPR_SMPPT_TGW_SHIFT) |
(VI6_DPR_NODE_UNUSED << VI6_DPR_SMPPT_PT_SHIFT));
vsp1_write(vsp1, VI6_DPR_HGT_SMPPT, (7 << VI6_DPR_SMPPT_TGW_SHIFT) |
(VI6_DPR_NODE_UNUSED << VI6_DPR_SMPPT_PT_SHIFT));
vsp1_dlm_setup(vsp1);
return 0;
}
int vsp1_device_get(struct vsp1_device *vsp1)
{
int ret = 0;
mutex_lock(&vsp1->lock);
if (vsp1->ref_count > 0)
goto done;
ret = clk_prepare_enable(vsp1->clock);
if (ret < 0)
goto done;
ret = vsp1_device_init(vsp1);
if (ret < 0) {
clk_disable_unprepare(vsp1->clock);
goto done;
}
done:
if (!ret)
vsp1->ref_count++;
mutex_unlock(&vsp1->lock);
return ret;
}
void vsp1_device_put(struct vsp1_device *vsp1)
{
mutex_lock(&vsp1->lock);
if (--vsp1->ref_count == 0)
clk_disable_unprepare(vsp1->clock);
mutex_unlock(&vsp1->lock);
}
static int vsp1_pm_suspend(struct device *dev)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
WARN_ON(mutex_is_locked(&vsp1->lock));
if (vsp1->ref_count == 0)
return 0;
vsp1_pipelines_suspend(vsp1);
clk_disable_unprepare(vsp1->clock);
return 0;
}
static int vsp1_pm_resume(struct device *dev)
{
struct vsp1_device *vsp1 = dev_get_drvdata(dev);
WARN_ON(mutex_is_locked(&vsp1->lock));
if (vsp1->ref_count == 0)
return 0;
clk_prepare_enable(vsp1->clock);
vsp1_pipelines_resume(vsp1);
return 0;
}
static int vsp1_probe(struct platform_device *pdev)
{
struct vsp1_device *vsp1;
struct resource *irq;
struct resource *io;
unsigned int i;
u32 version;
int ret;
vsp1 = devm_kzalloc(&pdev->dev, sizeof(*vsp1), GFP_KERNEL);
if (vsp1 == NULL)
return -ENOMEM;
vsp1->dev = &pdev->dev;
mutex_init(&vsp1->lock);
INIT_LIST_HEAD(&vsp1->entities);
INIT_LIST_HEAD(&vsp1->videos);
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
vsp1->mmio = devm_ioremap_resource(&pdev->dev, io);
if (IS_ERR(vsp1->mmio))
return PTR_ERR(vsp1->mmio);
vsp1->clock = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(vsp1->clock)) {
dev_err(&pdev->dev, "failed to get clock\n");
return PTR_ERR(vsp1->clock);
}
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq) {
dev_err(&pdev->dev, "missing IRQ\n");
return -EINVAL;
}
ret = devm_request_irq(&pdev->dev, irq->start, vsp1_irq_handler,
IRQF_SHARED, dev_name(&pdev->dev), vsp1);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request IRQ\n");
return ret;
}
ret = clk_prepare_enable(vsp1->clock);
if (ret < 0)
return ret;
version = vsp1_read(vsp1, VI6_IP_VERSION);
clk_disable_unprepare(vsp1->clock);
for (i = 0; i < ARRAY_SIZE(vsp1_device_infos); ++i) {
if ((version & VI6_IP_VERSION_MODEL_MASK) ==
vsp1_device_infos[i].version) {
vsp1->info = &vsp1_device_infos[i];
break;
}
}
if (!vsp1->info) {
dev_err(&pdev->dev, "unsupported IP version 0x%08x\n", version);
return -ENXIO;
}
dev_dbg(&pdev->dev, "IP version 0x%08x\n", version);
ret = vsp1_create_entities(vsp1);
if (ret < 0) {
dev_err(&pdev->dev, "failed to create entities\n");
return ret;
}
platform_set_drvdata(pdev, vsp1);
return 0;
}
static int vsp1_remove(struct platform_device *pdev)
{
struct vsp1_device *vsp1 = platform_get_drvdata(pdev);
vsp1_destroy_entities(vsp1);
return 0;
}
