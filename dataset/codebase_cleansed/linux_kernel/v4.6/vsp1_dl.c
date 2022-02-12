static void vsp1_dl_free_list(struct vsp1_dl_list *list)
{
if (!list)
return;
list->in_use = false;
}
void vsp1_dl_reset(struct vsp1_dl *dl)
{
unsigned int i;
dl->lists.active = NULL;
dl->lists.queued = NULL;
dl->lists.pending = NULL;
dl->lists.write = NULL;
for (i = 0; i < ARRAY_SIZE(dl->lists.all); ++i)
dl->lists.all[i].in_use = false;
}
void vsp1_dl_begin(struct vsp1_dl *dl)
{
struct vsp1_dl_list *list = NULL;
unsigned long flags;
unsigned int i;
spin_lock_irqsave(&dl->lock, flags);
for (i = 0; i < ARRAY_SIZE(dl->lists.all); ++i) {
if (!dl->lists.all[i].in_use) {
list = &dl->lists.all[i];
break;
}
}
if (!list) {
list = dl->lists.pending;
dl->lists.pending = NULL;
}
spin_unlock_irqrestore(&dl->lock, flags);
dl->lists.write = list;
list->in_use = true;
list->reg_count = 0;
}
void vsp1_dl_add(struct vsp1_entity *e, u32 reg, u32 data)
{
struct vsp1_pipeline *pipe = to_vsp1_pipeline(&e->subdev.entity);
struct vsp1_dl *dl = pipe->dl;
struct vsp1_dl_list *list = dl->lists.write;
list->body[list->reg_count].addr = reg;
list->body[list->reg_count].data = data;
list->reg_count++;
}
void vsp1_dl_commit(struct vsp1_dl *dl)
{
struct vsp1_device *vsp1 = dl->vsp1;
struct vsp1_dl_list *list;
unsigned long flags;
bool update;
list = dl->lists.write;
dl->lists.write = NULL;
spin_lock_irqsave(&dl->lock, flags);
update = !!(vsp1_read(vsp1, VI6_DL_BODY_SIZE) & VI6_DL_BODY_SIZE_UPD);
if (update) {
vsp1_dl_free_list(dl->lists.pending);
dl->lists.pending = list;
goto done;
}
vsp1_write(vsp1, VI6_DL_HDR_ADDR(0), list->dma);
vsp1_write(vsp1, VI6_DL_BODY_SIZE, VI6_DL_BODY_SIZE_UPD |
(list->reg_count * 8));
vsp1_dl_free_list(dl->lists.queued);
dl->lists.queued = list;
done:
spin_unlock_irqrestore(&dl->lock, flags);
}
void vsp1_dl_irq_display_start(struct vsp1_dl *dl)
{
spin_lock(&dl->lock);
if (dl->lists.active) {
vsp1_dl_free_list(dl->lists.active);
dl->lists.active = NULL;
}
spin_unlock(&dl->lock);
}
void vsp1_dl_irq_frame_end(struct vsp1_dl *dl)
{
struct vsp1_device *vsp1 = dl->vsp1;
spin_lock(&dl->lock);
if (vsp1_read(vsp1, VI6_DL_BODY_SIZE) & VI6_DL_BODY_SIZE_UPD)
goto done;
if (dl->lists.queued) {
WARN_ON(dl->lists.active);
dl->lists.active = dl->lists.queued;
dl->lists.queued = NULL;
}
if (dl->lists.pending) {
struct vsp1_dl_list *list = dl->lists.pending;
vsp1_write(vsp1, VI6_DL_HDR_ADDR(0), list->dma);
vsp1_write(vsp1, VI6_DL_BODY_SIZE, VI6_DL_BODY_SIZE_UPD |
(list->reg_count * 8));
dl->lists.queued = list;
dl->lists.pending = NULL;
}
done:
spin_unlock(&dl->lock);
}
void vsp1_dl_setup(struct vsp1_device *vsp1)
{
u32 ctrl = (256 << VI6_DL_CTRL_AR_WAIT_SHIFT)
| VI6_DL_CTRL_DC2 | VI6_DL_CTRL_DC1 | VI6_DL_CTRL_DC0
| VI6_DL_CTRL_DLE;
if (vsp1->drm)
ctrl |= VI6_DL_CTRL_CFM0 | VI6_DL_CTRL_NH0;
vsp1_write(vsp1, VI6_DL_CTRL, ctrl);
vsp1_write(vsp1, VI6_DL_SWAP, VI6_DL_SWAP_LWS);
}
struct vsp1_dl *vsp1_dl_create(struct vsp1_device *vsp1)
{
struct vsp1_dl *dl;
unsigned int i;
dl = kzalloc(sizeof(*dl), GFP_KERNEL);
if (!dl)
return NULL;
spin_lock_init(&dl->lock);
dl->vsp1 = vsp1;
dl->size = VSP1_DL_BODY_SIZE * ARRAY_SIZE(dl->lists.all);
dl->mem = dma_alloc_wc(vsp1->dev, dl->size, &dl->dma,
GFP_KERNEL);
if (!dl->mem) {
kfree(dl);
return NULL;
}
for (i = 0; i < ARRAY_SIZE(dl->lists.all); ++i) {
struct vsp1_dl_list *list = &dl->lists.all[i];
list->size = VSP1_DL_BODY_SIZE;
list->reg_count = 0;
list->in_use = false;
list->dma = dl->dma + VSP1_DL_BODY_SIZE * i;
list->body = dl->mem + VSP1_DL_BODY_SIZE * i;
}
return dl;
}
void vsp1_dl_destroy(struct vsp1_dl *dl)
{
dma_free_wc(dl->vsp1->dev, dl->size, dl->mem, dl->dma);
kfree(dl);
}
