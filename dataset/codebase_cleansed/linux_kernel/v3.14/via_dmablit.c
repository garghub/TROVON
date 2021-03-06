static void
via_unmap_blit_from_device(struct pci_dev *pdev, drm_via_sg_info_t *vsg)
{
int num_desc = vsg->num_desc;
unsigned cur_descriptor_page = num_desc / vsg->descriptors_per_page;
unsigned descriptor_this_page = num_desc % vsg->descriptors_per_page;
drm_via_descriptor_t *desc_ptr = vsg->desc_pages[cur_descriptor_page] +
descriptor_this_page;
dma_addr_t next = vsg->chain_start;
while (num_desc--) {
if (descriptor_this_page-- == 0) {
cur_descriptor_page--;
descriptor_this_page = vsg->descriptors_per_page - 1;
desc_ptr = vsg->desc_pages[cur_descriptor_page] +
descriptor_this_page;
}
dma_unmap_single(&pdev->dev, next, sizeof(*desc_ptr), DMA_TO_DEVICE);
dma_unmap_page(&pdev->dev, desc_ptr->mem_addr, desc_ptr->size, vsg->direction);
next = (dma_addr_t) desc_ptr->next;
desc_ptr--;
}
}
static void
via_map_blit_for_device(struct pci_dev *pdev,
const drm_via_dmablit_t *xfer,
drm_via_sg_info_t *vsg,
int mode)
{
unsigned cur_descriptor_page = 0;
unsigned num_descriptors_this_page = 0;
unsigned char *mem_addr = xfer->mem_addr;
unsigned char *cur_mem;
unsigned char *first_addr = (unsigned char *)VIA_PGDN(mem_addr);
uint32_t fb_addr = xfer->fb_addr;
uint32_t cur_fb;
unsigned long line_len;
unsigned remaining_len;
int num_desc = 0;
int cur_line;
dma_addr_t next = 0 | VIA_DMA_DPR_EC;
drm_via_descriptor_t *desc_ptr = NULL;
if (mode == 1)
desc_ptr = vsg->desc_pages[cur_descriptor_page];
for (cur_line = 0; cur_line < xfer->num_lines; ++cur_line) {
line_len = xfer->line_length;
cur_fb = fb_addr;
cur_mem = mem_addr;
while (line_len > 0) {
remaining_len = min(PAGE_SIZE-VIA_PGOFF(cur_mem), line_len);
line_len -= remaining_len;
if (mode == 1) {
desc_ptr->mem_addr =
dma_map_page(&pdev->dev,
vsg->pages[VIA_PFN(cur_mem) -
VIA_PFN(first_addr)],
VIA_PGOFF(cur_mem), remaining_len,
vsg->direction);
desc_ptr->dev_addr = cur_fb;
desc_ptr->size = remaining_len;
desc_ptr->next = (uint32_t) next;
next = dma_map_single(&pdev->dev, desc_ptr, sizeof(*desc_ptr),
DMA_TO_DEVICE);
desc_ptr++;
if (++num_descriptors_this_page >= vsg->descriptors_per_page) {
num_descriptors_this_page = 0;
desc_ptr = vsg->desc_pages[++cur_descriptor_page];
}
}
num_desc++;
cur_mem += remaining_len;
cur_fb += remaining_len;
}
mem_addr += xfer->mem_stride;
fb_addr += xfer->fb_stride;
}
if (mode == 1) {
vsg->chain_start = next;
vsg->state = dr_via_device_mapped;
}
vsg->num_desc = num_desc;
}
static void
via_free_sg_info(struct pci_dev *pdev, drm_via_sg_info_t *vsg)
{
struct page *page;
int i;
switch (vsg->state) {
case dr_via_device_mapped:
via_unmap_blit_from_device(pdev, vsg);
case dr_via_desc_pages_alloc:
for (i = 0; i < vsg->num_desc_pages; ++i) {
if (vsg->desc_pages[i] != NULL)
free_page((unsigned long)vsg->desc_pages[i]);
}
kfree(vsg->desc_pages);
case dr_via_pages_locked:
for (i = 0; i < vsg->num_pages; ++i) {
if (NULL != (page = vsg->pages[i])) {
if (!PageReserved(page) && (DMA_FROM_DEVICE == vsg->direction))
SetPageDirty(page);
page_cache_release(page);
}
}
case dr_via_pages_alloc:
vfree(vsg->pages);
default:
vsg->state = dr_via_sg_init;
}
vfree(vsg->bounce_buffer);
vsg->bounce_buffer = NULL;
vsg->free_on_sequence = 0;
}
static void
via_fire_dmablit(struct drm_device *dev, drm_via_sg_info_t *vsg, int engine)
{
drm_via_private_t *dev_priv = (drm_via_private_t *)dev->dev_private;
VIA_WRITE(VIA_PCI_DMA_MAR0 + engine*0x10, 0);
VIA_WRITE(VIA_PCI_DMA_DAR0 + engine*0x10, 0);
VIA_WRITE(VIA_PCI_DMA_CSR0 + engine*0x04, VIA_DMA_CSR_DD | VIA_DMA_CSR_TD |
VIA_DMA_CSR_DE);
VIA_WRITE(VIA_PCI_DMA_MR0 + engine*0x04, VIA_DMA_MR_CM | VIA_DMA_MR_TDIE);
VIA_WRITE(VIA_PCI_DMA_BCR0 + engine*0x10, 0);
VIA_WRITE(VIA_PCI_DMA_DPR0 + engine*0x10, vsg->chain_start);
wmb();
VIA_WRITE(VIA_PCI_DMA_CSR0 + engine*0x04, VIA_DMA_CSR_DE | VIA_DMA_CSR_TS);
VIA_READ(VIA_PCI_DMA_CSR0 + engine*0x04);
}
static int
via_lock_all_dma_pages(drm_via_sg_info_t *vsg, drm_via_dmablit_t *xfer)
{
int ret;
unsigned long first_pfn = VIA_PFN(xfer->mem_addr);
vsg->num_pages = VIA_PFN(xfer->mem_addr + (xfer->num_lines * xfer->mem_stride - 1)) -
first_pfn + 1;
vsg->pages = vzalloc(sizeof(struct page *) * vsg->num_pages);
if (NULL == vsg->pages)
return -ENOMEM;
down_read(&current->mm->mmap_sem);
ret = get_user_pages(current, current->mm,
(unsigned long)xfer->mem_addr,
vsg->num_pages,
(vsg->direction == DMA_FROM_DEVICE),
0, vsg->pages, NULL);
up_read(&current->mm->mmap_sem);
if (ret != vsg->num_pages) {
if (ret < 0)
return ret;
vsg->state = dr_via_pages_locked;
return -EINVAL;
}
vsg->state = dr_via_pages_locked;
DRM_DEBUG("DMA pages locked\n");
return 0;
}
static int
via_alloc_desc_pages(drm_via_sg_info_t *vsg)
{
int i;
vsg->descriptors_per_page = PAGE_SIZE / sizeof(drm_via_descriptor_t);
vsg->num_desc_pages = (vsg->num_desc + vsg->descriptors_per_page - 1) /
vsg->descriptors_per_page;
if (NULL == (vsg->desc_pages = kcalloc(vsg->num_desc_pages, sizeof(void *), GFP_KERNEL)))
return -ENOMEM;
vsg->state = dr_via_desc_pages_alloc;
for (i = 0; i < vsg->num_desc_pages; ++i) {
if (NULL == (vsg->desc_pages[i] =
(drm_via_descriptor_t *) __get_free_page(GFP_KERNEL)))
return -ENOMEM;
}
DRM_DEBUG("Allocated %d pages for %d descriptors.\n", vsg->num_desc_pages,
vsg->num_desc);
return 0;
}
static void
via_abort_dmablit(struct drm_device *dev, int engine)
{
drm_via_private_t *dev_priv = (drm_via_private_t *)dev->dev_private;
VIA_WRITE(VIA_PCI_DMA_CSR0 + engine*0x04, VIA_DMA_CSR_TA);
}
static void
via_dmablit_engine_off(struct drm_device *dev, int engine)
{
drm_via_private_t *dev_priv = (drm_via_private_t *)dev->dev_private;
VIA_WRITE(VIA_PCI_DMA_CSR0 + engine*0x04, VIA_DMA_CSR_TD | VIA_DMA_CSR_DD);
}
void
via_dmablit_handler(struct drm_device *dev, int engine, int from_irq)
{
drm_via_private_t *dev_priv = (drm_via_private_t *)dev->dev_private;
drm_via_blitq_t *blitq = dev_priv->blit_queues + engine;
int cur;
int done_transfer;
unsigned long irqsave = 0;
uint32_t status = 0;
DRM_DEBUG("DMA blit handler called. engine = %d, from_irq = %d, blitq = 0x%lx\n",
engine, from_irq, (unsigned long) blitq);
if (from_irq)
spin_lock(&blitq->blit_lock);
else
spin_lock_irqsave(&blitq->blit_lock, irqsave);
done_transfer = blitq->is_active &&
((status = VIA_READ(VIA_PCI_DMA_CSR0 + engine*0x04)) & VIA_DMA_CSR_TD);
done_transfer = done_transfer || (blitq->aborting && !(status & VIA_DMA_CSR_DE));
cur = blitq->cur;
if (done_transfer) {
blitq->blits[cur]->aborted = blitq->aborting;
blitq->done_blit_handle++;
wake_up(blitq->blit_queue + cur);
cur++;
if (cur >= VIA_NUM_BLIT_SLOTS)
cur = 0;
blitq->cur = cur;
VIA_WRITE(VIA_PCI_DMA_CSR0 + engine*0x04, VIA_DMA_CSR_TD);
blitq->is_active = 0;
blitq->aborting = 0;
schedule_work(&blitq->wq);
} else if (blitq->is_active && time_after_eq(jiffies, blitq->end)) {
via_abort_dmablit(dev, engine);
blitq->aborting = 1;
blitq->end = jiffies + HZ;
}
if (!blitq->is_active) {
if (blitq->num_outstanding) {
via_fire_dmablit(dev, blitq->blits[cur], engine);
blitq->is_active = 1;
blitq->cur = cur;
blitq->num_outstanding--;
blitq->end = jiffies + HZ;
if (!timer_pending(&blitq->poll_timer))
mod_timer(&blitq->poll_timer, jiffies + 1);
} else {
if (timer_pending(&blitq->poll_timer))
del_timer(&blitq->poll_timer);
via_dmablit_engine_off(dev, engine);
}
}
if (from_irq)
spin_unlock(&blitq->blit_lock);
else
spin_unlock_irqrestore(&blitq->blit_lock, irqsave);
}
static int
via_dmablit_active(drm_via_blitq_t *blitq, int engine, uint32_t handle, wait_queue_head_t **queue)
{
unsigned long irqsave;
uint32_t slot;
int active;
spin_lock_irqsave(&blitq->blit_lock, irqsave);
active = ((blitq->done_blit_handle - handle) > (1 << 23)) &&
((blitq->cur_blit_handle - handle) <= (1 << 23));
if (queue && active) {
slot = handle - blitq->done_blit_handle + blitq->cur - 1;
if (slot >= VIA_NUM_BLIT_SLOTS)
slot -= VIA_NUM_BLIT_SLOTS;
*queue = blitq->blit_queue + slot;
}
spin_unlock_irqrestore(&blitq->blit_lock, irqsave);
return active;
}
static int
via_dmablit_sync(struct drm_device *dev, uint32_t handle, int engine)
{
drm_via_private_t *dev_priv = (drm_via_private_t *)dev->dev_private;
drm_via_blitq_t *blitq = dev_priv->blit_queues + engine;
wait_queue_head_t *queue;
int ret = 0;
if (via_dmablit_active(blitq, engine, handle, &queue)) {
DRM_WAIT_ON(ret, *queue, 3 * HZ,
!via_dmablit_active(blitq, engine, handle, NULL));
}
DRM_DEBUG("DMA blit sync handle 0x%x engine %d returned %d\n",
handle, engine, ret);
return ret;
}
static void
via_dmablit_timer(unsigned long data)
{
drm_via_blitq_t *blitq = (drm_via_blitq_t *) data;
struct drm_device *dev = blitq->dev;
int engine = (int)
(blitq - ((drm_via_private_t *)dev->dev_private)->blit_queues);
DRM_DEBUG("Polling timer called for engine %d, jiffies %lu\n", engine,
(unsigned long) jiffies);
via_dmablit_handler(dev, engine, 0);
if (!timer_pending(&blitq->poll_timer)) {
mod_timer(&blitq->poll_timer, jiffies + 1);
via_dmablit_handler(dev, engine, 0);
}
}
static void
via_dmablit_workqueue(struct work_struct *work)
{
drm_via_blitq_t *blitq = container_of(work, drm_via_blitq_t, wq);
struct drm_device *dev = blitq->dev;
unsigned long irqsave;
drm_via_sg_info_t *cur_sg;
int cur_released;
DRM_DEBUG("Workqueue task called for blit engine %ld\n", (unsigned long)
(blitq - ((drm_via_private_t *)dev->dev_private)->blit_queues));
spin_lock_irqsave(&blitq->blit_lock, irqsave);
while (blitq->serviced != blitq->cur) {
cur_released = blitq->serviced++;
DRM_DEBUG("Releasing blit slot %d\n", cur_released);
if (blitq->serviced >= VIA_NUM_BLIT_SLOTS)
blitq->serviced = 0;
cur_sg = blitq->blits[cur_released];
blitq->num_free++;
spin_unlock_irqrestore(&blitq->blit_lock, irqsave);
wake_up(&blitq->busy_queue);
via_free_sg_info(dev->pdev, cur_sg);
kfree(cur_sg);
spin_lock_irqsave(&blitq->blit_lock, irqsave);
}
spin_unlock_irqrestore(&blitq->blit_lock, irqsave);
}
void
via_init_dmablit(struct drm_device *dev)
{
int i, j;
drm_via_private_t *dev_priv = (drm_via_private_t *)dev->dev_private;
drm_via_blitq_t *blitq;
pci_set_master(dev->pdev);
for (i = 0; i < VIA_NUM_BLIT_ENGINES; ++i) {
blitq = dev_priv->blit_queues + i;
blitq->dev = dev;
blitq->cur_blit_handle = 0;
blitq->done_blit_handle = 0;
blitq->head = 0;
blitq->cur = 0;
blitq->serviced = 0;
blitq->num_free = VIA_NUM_BLIT_SLOTS - 1;
blitq->num_outstanding = 0;
blitq->is_active = 0;
blitq->aborting = 0;
spin_lock_init(&blitq->blit_lock);
for (j = 0; j < VIA_NUM_BLIT_SLOTS; ++j)
init_waitqueue_head(blitq->blit_queue + j);
init_waitqueue_head(&blitq->busy_queue);
INIT_WORK(&blitq->wq, via_dmablit_workqueue);
setup_timer(&blitq->poll_timer, via_dmablit_timer,
(unsigned long)blitq);
}
}
static int
via_build_sg_info(struct drm_device *dev, drm_via_sg_info_t *vsg, drm_via_dmablit_t *xfer)
{
int draw = xfer->to_fb;
int ret = 0;
vsg->direction = (draw) ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
vsg->bounce_buffer = NULL;
vsg->state = dr_via_sg_init;
if (xfer->num_lines <= 0 || xfer->line_length <= 0) {
DRM_ERROR("Zero size bitblt.\n");
return -EINVAL;
}
if ((xfer->mem_stride - xfer->line_length) > 2*PAGE_SIZE) {
DRM_ERROR("Too large system memory stride. Stride: %d, "
"Length: %d\n", xfer->mem_stride, xfer->line_length);
return -EINVAL;
}
if ((xfer->mem_stride == xfer->line_length) &&
(xfer->fb_stride == xfer->line_length)) {
xfer->mem_stride *= xfer->num_lines;
xfer->line_length = xfer->mem_stride;
xfer->fb_stride = xfer->mem_stride;
xfer->num_lines = 1;
}
if (xfer->num_lines > 2048 || (xfer->num_lines*xfer->mem_stride > (2048*2048*4))) {
DRM_ERROR("Too large PCI DMA bitblt.\n");
return -EINVAL;
}
if (xfer->mem_stride < xfer->line_length ||
abs(xfer->fb_stride) < xfer->line_length) {
DRM_ERROR("Invalid frame-buffer / memory stride.\n");
return -EINVAL;
}
#ifdef VIA_BUGFREE
if ((((unsigned long)xfer->mem_addr & 3) != ((unsigned long)xfer->fb_addr & 3)) ||
((xfer->num_lines > 1) && ((xfer->mem_stride & 3) != (xfer->fb_stride & 3)))) {
DRM_ERROR("Invalid DRM bitblt alignment.\n");
return -EINVAL;
}
#else
if ((((unsigned long)xfer->mem_addr & 15) ||
((unsigned long)xfer->fb_addr & 3)) ||
((xfer->num_lines > 1) &&
((xfer->mem_stride & 15) || (xfer->fb_stride & 3)))) {
DRM_ERROR("Invalid DRM bitblt alignment.\n");
return -EINVAL;
}
#endif
if (0 != (ret = via_lock_all_dma_pages(vsg, xfer))) {
DRM_ERROR("Could not lock DMA pages.\n");
via_free_sg_info(dev->pdev, vsg);
return ret;
}
via_map_blit_for_device(dev->pdev, xfer, vsg, 0);
if (0 != (ret = via_alloc_desc_pages(vsg))) {
DRM_ERROR("Could not allocate DMA descriptor pages.\n");
via_free_sg_info(dev->pdev, vsg);
return ret;
}
via_map_blit_for_device(dev->pdev, xfer, vsg, 1);
return 0;
}
static int
via_dmablit_grab_slot(drm_via_blitq_t *blitq, int engine)
{
int ret = 0;
unsigned long irqsave;
DRM_DEBUG("Num free is %d\n", blitq->num_free);
spin_lock_irqsave(&blitq->blit_lock, irqsave);
while (blitq->num_free == 0) {
spin_unlock_irqrestore(&blitq->blit_lock, irqsave);
DRM_WAIT_ON(ret, blitq->busy_queue, HZ, blitq->num_free > 0);
if (ret)
return (-EINTR == ret) ? -EAGAIN : ret;
spin_lock_irqsave(&blitq->blit_lock, irqsave);
}
blitq->num_free--;
spin_unlock_irqrestore(&blitq->blit_lock, irqsave);
return 0;
}
static void
via_dmablit_release_slot(drm_via_blitq_t *blitq)
{
unsigned long irqsave;
spin_lock_irqsave(&blitq->blit_lock, irqsave);
blitq->num_free++;
spin_unlock_irqrestore(&blitq->blit_lock, irqsave);
wake_up(&blitq->busy_queue);
}
static int
via_dmablit(struct drm_device *dev, drm_via_dmablit_t *xfer)
{
drm_via_private_t *dev_priv = (drm_via_private_t *)dev->dev_private;
drm_via_sg_info_t *vsg;
drm_via_blitq_t *blitq;
int ret;
int engine;
unsigned long irqsave;
if (dev_priv == NULL) {
DRM_ERROR("Called without initialization.\n");
return -EINVAL;
}
engine = (xfer->to_fb) ? 0 : 1;
blitq = dev_priv->blit_queues + engine;
if (0 != (ret = via_dmablit_grab_slot(blitq, engine)))
return ret;
if (NULL == (vsg = kmalloc(sizeof(*vsg), GFP_KERNEL))) {
via_dmablit_release_slot(blitq);
return -ENOMEM;
}
if (0 != (ret = via_build_sg_info(dev, vsg, xfer))) {
via_dmablit_release_slot(blitq);
kfree(vsg);
return ret;
}
spin_lock_irqsave(&blitq->blit_lock, irqsave);
blitq->blits[blitq->head++] = vsg;
if (blitq->head >= VIA_NUM_BLIT_SLOTS)
blitq->head = 0;
blitq->num_outstanding++;
xfer->sync.sync_handle = ++blitq->cur_blit_handle;
spin_unlock_irqrestore(&blitq->blit_lock, irqsave);
xfer->sync.engine = engine;
via_dmablit_handler(dev, engine, 0);
return 0;
}
int
via_dma_blit_sync(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_via_blitsync_t *sync = data;
int err;
if (sync->engine >= VIA_NUM_BLIT_ENGINES)
return -EINVAL;
err = via_dmablit_sync(dev, sync->sync_handle, sync->engine);
if (-EINTR == err)
err = -EAGAIN;
return err;
}
int
via_dma_blit(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
drm_via_dmablit_t *xfer = data;
int err;
err = via_dmablit(dev, xfer);
return err;
}
