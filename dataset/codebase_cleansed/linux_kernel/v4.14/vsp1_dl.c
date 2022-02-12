static int vsp1_dl_body_init(struct vsp1_device *vsp1,
struct vsp1_dl_body *dlb, unsigned int num_entries,
size_t extra_size)
{
size_t size = num_entries * sizeof(*dlb->entries) + extra_size;
dlb->vsp1 = vsp1;
dlb->size = size;
dlb->entries = dma_alloc_wc(vsp1->bus_master, dlb->size, &dlb->dma,
GFP_KERNEL);
if (!dlb->entries)
return -ENOMEM;
return 0;
}
static void vsp1_dl_body_cleanup(struct vsp1_dl_body *dlb)
{
dma_free_wc(dlb->vsp1->bus_master, dlb->size, dlb->entries, dlb->dma);
}
struct vsp1_dl_body *vsp1_dl_fragment_alloc(struct vsp1_device *vsp1,
unsigned int num_entries)
{
struct vsp1_dl_body *dlb;
int ret;
dlb = kzalloc(sizeof(*dlb), GFP_KERNEL);
if (!dlb)
return NULL;
ret = vsp1_dl_body_init(vsp1, dlb, num_entries, 0);
if (ret < 0) {
kfree(dlb);
return NULL;
}
return dlb;
}
void vsp1_dl_fragment_free(struct vsp1_dl_body *dlb)
{
if (!dlb)
return;
vsp1_dl_body_cleanup(dlb);
kfree(dlb);
}
void vsp1_dl_fragment_write(struct vsp1_dl_body *dlb, u32 reg, u32 data)
{
dlb->entries[dlb->num_entries].addr = reg;
dlb->entries[dlb->num_entries].data = data;
dlb->num_entries++;
}
static struct vsp1_dl_list *vsp1_dl_list_alloc(struct vsp1_dl_manager *dlm)
{
struct vsp1_dl_list *dl;
size_t header_size;
int ret;
dl = kzalloc(sizeof(*dl), GFP_KERNEL);
if (!dl)
return NULL;
INIT_LIST_HEAD(&dl->fragments);
dl->dlm = dlm;
header_size = dlm->mode == VSP1_DL_MODE_HEADER
? ALIGN(sizeof(struct vsp1_dl_header), 8)
: 0;
ret = vsp1_dl_body_init(dlm->vsp1, &dl->body0, VSP1_DL_NUM_ENTRIES,
header_size);
if (ret < 0) {
kfree(dl);
return NULL;
}
if (dlm->mode == VSP1_DL_MODE_HEADER) {
size_t header_offset = VSP1_DL_NUM_ENTRIES
* sizeof(*dl->body0.entries);
dl->header = ((void *)dl->body0.entries) + header_offset;
dl->dma = dl->body0.dma + header_offset;
memset(dl->header, 0, sizeof(*dl->header));
dl->header->lists[0].addr = dl->body0.dma;
}
return dl;
}
static void vsp1_dl_list_free(struct vsp1_dl_list *dl)
{
vsp1_dl_body_cleanup(&dl->body0);
list_splice_init(&dl->fragments, &dl->dlm->gc_fragments);
kfree(dl);
}
struct vsp1_dl_list *vsp1_dl_list_get(struct vsp1_dl_manager *dlm)
{
struct vsp1_dl_list *dl = NULL;
unsigned long flags;
spin_lock_irqsave(&dlm->lock, flags);
if (!list_empty(&dlm->free)) {
dl = list_first_entry(&dlm->free, struct vsp1_dl_list, list);
list_del(&dl->list);
INIT_LIST_HEAD(&dl->chain);
}
spin_unlock_irqrestore(&dlm->lock, flags);
return dl;
}
static void __vsp1_dl_list_put(struct vsp1_dl_list *dl)
{
struct vsp1_dl_list *dl_child;
if (!dl)
return;
if (dl->has_chain) {
list_for_each_entry(dl_child, &dl->chain, chain)
__vsp1_dl_list_put(dl_child);
}
dl->has_chain = false;
if (!list_empty(&dl->fragments)) {
list_splice_init(&dl->fragments, &dl->dlm->gc_fragments);
schedule_work(&dl->dlm->gc_work);
}
dl->body0.num_entries = 0;
list_add_tail(&dl->list, &dl->dlm->free);
}
void vsp1_dl_list_put(struct vsp1_dl_list *dl)
{
unsigned long flags;
if (!dl)
return;
spin_lock_irqsave(&dl->dlm->lock, flags);
__vsp1_dl_list_put(dl);
spin_unlock_irqrestore(&dl->dlm->lock, flags);
}
void vsp1_dl_list_write(struct vsp1_dl_list *dl, u32 reg, u32 data)
{
vsp1_dl_fragment_write(&dl->body0, reg, data);
}
int vsp1_dl_list_add_fragment(struct vsp1_dl_list *dl,
struct vsp1_dl_body *dlb)
{
if (dl->dlm->mode != VSP1_DL_MODE_HEADER)
return -EINVAL;
list_add_tail(&dlb->list, &dl->fragments);
return 0;
}
int vsp1_dl_list_add_chain(struct vsp1_dl_list *head,
struct vsp1_dl_list *dl)
{
if (head->dlm->mode != VSP1_DL_MODE_HEADER)
return -EINVAL;
head->has_chain = true;
list_add_tail(&dl->chain, &head->chain);
return 0;
}
static void vsp1_dl_list_fill_header(struct vsp1_dl_list *dl, bool is_last)
{
struct vsp1_dl_manager *dlm = dl->dlm;
struct vsp1_dl_header_list *hdr = dl->header->lists;
struct vsp1_dl_body *dlb;
unsigned int num_lists = 0;
hdr->num_bytes = dl->body0.num_entries
* sizeof(*dl->header->lists);
list_for_each_entry(dlb, &dl->fragments, list) {
num_lists++;
hdr++;
hdr->addr = dlb->dma;
hdr->num_bytes = dlb->num_entries
* sizeof(*dl->header->lists);
}
dl->header->num_lists = num_lists;
if (!list_empty(&dl->chain) && !is_last) {
struct vsp1_dl_list *next = list_next_entry(dl, chain);
dl->header->next_header = next->dma;
dl->header->flags = VSP1_DLH_AUTO_START;
} else if (!dlm->singleshot) {
dl->header->next_header = dl->dma;
dl->header->flags = VSP1_DLH_INT_ENABLE | VSP1_DLH_AUTO_START;
} else {
dl->header->flags = VSP1_DLH_INT_ENABLE;
}
}
static bool vsp1_dl_list_hw_update_pending(struct vsp1_dl_manager *dlm)
{
struct vsp1_device *vsp1 = dlm->vsp1;
if (!dlm->queued)
return false;
if (dlm->mode == VSP1_DL_MODE_HEADERLESS)
return !!(vsp1_read(vsp1, VI6_DL_BODY_SIZE)
& VI6_DL_BODY_SIZE_UPD);
else
return !!(vsp1_read(vsp1, VI6_CMD(dlm->index) & VI6_CMD_UPDHDR));
}
static void vsp1_dl_list_hw_enqueue(struct vsp1_dl_list *dl)
{
struct vsp1_dl_manager *dlm = dl->dlm;
struct vsp1_device *vsp1 = dlm->vsp1;
if (dlm->mode == VSP1_DL_MODE_HEADERLESS) {
vsp1_write(vsp1, VI6_DL_HDR_ADDR(0), dl->body0.dma);
vsp1_write(vsp1, VI6_DL_BODY_SIZE, VI6_DL_BODY_SIZE_UPD |
(dl->body0.num_entries * sizeof(*dl->header->lists)));
} else {
vsp1_write(vsp1, VI6_DL_HDR_ADDR(dlm->index), dl->dma);
}
}
static void vsp1_dl_list_commit_continuous(struct vsp1_dl_list *dl)
{
struct vsp1_dl_manager *dlm = dl->dlm;
if (vsp1_dl_list_hw_update_pending(dlm)) {
__vsp1_dl_list_put(dlm->pending);
dlm->pending = dl;
return;
}
vsp1_dl_list_hw_enqueue(dl);
__vsp1_dl_list_put(dlm->queued);
dlm->queued = dl;
}
static void vsp1_dl_list_commit_singleshot(struct vsp1_dl_list *dl)
{
struct vsp1_dl_manager *dlm = dl->dlm;
vsp1_dl_list_hw_enqueue(dl);
dlm->active = dl;
}
void vsp1_dl_list_commit(struct vsp1_dl_list *dl)
{
struct vsp1_dl_manager *dlm = dl->dlm;
struct vsp1_dl_list *dl_child;
unsigned long flags;
if (dlm->mode == VSP1_DL_MODE_HEADER) {
vsp1_dl_list_fill_header(dl, list_empty(&dl->chain));
list_for_each_entry(dl_child, &dl->chain, chain) {
bool last = list_is_last(&dl_child->chain, &dl->chain);
vsp1_dl_list_fill_header(dl_child, last);
}
}
spin_lock_irqsave(&dlm->lock, flags);
if (dlm->singleshot)
vsp1_dl_list_commit_singleshot(dl);
else
vsp1_dl_list_commit_continuous(dl);
spin_unlock_irqrestore(&dlm->lock, flags);
}
bool vsp1_dlm_irq_frame_end(struct vsp1_dl_manager *dlm)
{
bool completed = false;
spin_lock(&dlm->lock);
if (dlm->singleshot) {
__vsp1_dl_list_put(dlm->active);
dlm->active = NULL;
completed = true;
goto done;
}
if (vsp1_dl_list_hw_update_pending(dlm))
goto done;
if (dlm->queued) {
__vsp1_dl_list_put(dlm->active);
dlm->active = dlm->queued;
dlm->queued = NULL;
completed = true;
}
if (dlm->pending) {
vsp1_dl_list_hw_enqueue(dlm->pending);
dlm->queued = dlm->pending;
dlm->pending = NULL;
}
done:
spin_unlock(&dlm->lock);
return completed;
}
void vsp1_dlm_setup(struct vsp1_device *vsp1)
{
u32 ctrl = (256 << VI6_DL_CTRL_AR_WAIT_SHIFT)
| VI6_DL_CTRL_DC2 | VI6_DL_CTRL_DC1 | VI6_DL_CTRL_DC0
| VI6_DL_CTRL_DLE;
if (vsp1->drm)
ctrl |= VI6_DL_CTRL_CFM0 | VI6_DL_CTRL_NH0;
vsp1_write(vsp1, VI6_DL_CTRL, ctrl);
vsp1_write(vsp1, VI6_DL_SWAP, VI6_DL_SWAP_LWS);
}
void vsp1_dlm_reset(struct vsp1_dl_manager *dlm)
{
unsigned long flags;
spin_lock_irqsave(&dlm->lock, flags);
__vsp1_dl_list_put(dlm->active);
__vsp1_dl_list_put(dlm->queued);
__vsp1_dl_list_put(dlm->pending);
spin_unlock_irqrestore(&dlm->lock, flags);
dlm->active = NULL;
dlm->queued = NULL;
dlm->pending = NULL;
}
static void vsp1_dlm_fragments_free(struct vsp1_dl_manager *dlm)
{
unsigned long flags;
spin_lock_irqsave(&dlm->lock, flags);
while (!list_empty(&dlm->gc_fragments)) {
struct vsp1_dl_body *dlb;
dlb = list_first_entry(&dlm->gc_fragments, struct vsp1_dl_body,
list);
list_del(&dlb->list);
spin_unlock_irqrestore(&dlm->lock, flags);
vsp1_dl_fragment_free(dlb);
spin_lock_irqsave(&dlm->lock, flags);
}
spin_unlock_irqrestore(&dlm->lock, flags);
}
static void vsp1_dlm_garbage_collect(struct work_struct *work)
{
struct vsp1_dl_manager *dlm =
container_of(work, struct vsp1_dl_manager, gc_work);
vsp1_dlm_fragments_free(dlm);
}
struct vsp1_dl_manager *vsp1_dlm_create(struct vsp1_device *vsp1,
unsigned int index,
unsigned int prealloc)
{
struct vsp1_dl_manager *dlm;
unsigned int i;
dlm = devm_kzalloc(vsp1->dev, sizeof(*dlm), GFP_KERNEL);
if (!dlm)
return NULL;
dlm->index = index;
dlm->mode = index == 0 && !vsp1->info->uapi
? VSP1_DL_MODE_HEADERLESS : VSP1_DL_MODE_HEADER;
dlm->singleshot = vsp1->info->uapi;
dlm->vsp1 = vsp1;
spin_lock_init(&dlm->lock);
INIT_LIST_HEAD(&dlm->free);
INIT_LIST_HEAD(&dlm->gc_fragments);
INIT_WORK(&dlm->gc_work, vsp1_dlm_garbage_collect);
for (i = 0; i < prealloc; ++i) {
struct vsp1_dl_list *dl;
dl = vsp1_dl_list_alloc(dlm);
if (!dl)
return NULL;
list_add_tail(&dl->list, &dlm->free);
}
return dlm;
}
void vsp1_dlm_destroy(struct vsp1_dl_manager *dlm)
{
struct vsp1_dl_list *dl, *next;
if (!dlm)
return;
cancel_work_sync(&dlm->gc_work);
list_for_each_entry_safe(dl, next, &dlm->free, list) {
list_del(&dl->list);
vsp1_dl_list_free(dl);
}
vsp1_dlm_fragments_free(dlm);
}
