int vchiq_platform_init(struct platform_device *pdev, VCHIQ_STATE_T *state)
{
struct device *dev = &pdev->dev;
struct rpi_firmware *fw = platform_get_drvdata(pdev);
VCHIQ_SLOT_ZERO_T *vchiq_slot_zero;
struct resource *res;
void *slot_mem;
dma_addr_t slot_phys;
u32 channelbase;
int slot_mem_size, frag_mem_size;
int err, irq, i;
err = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (err < 0)
return err;
err = of_property_read_u32(dev->of_node, "cache-line-size",
&g_cache_line_size);
if (err) {
dev_err(dev, "Missing cache-line-size property\n");
return -ENODEV;
}
g_fragments_size = 2 * g_cache_line_size;
slot_mem_size = PAGE_ALIGN(TOTAL_SLOTS * VCHIQ_SLOT_SIZE);
frag_mem_size = PAGE_ALIGN(g_fragments_size * MAX_FRAGMENTS);
slot_mem = dmam_alloc_coherent(dev, slot_mem_size + frag_mem_size,
&slot_phys, GFP_KERNEL);
if (!slot_mem) {
dev_err(dev, "could not allocate DMA memory\n");
return -ENOMEM;
}
WARN_ON(((unsigned long)slot_mem & (PAGE_SIZE - 1)) != 0);
vchiq_slot_zero = vchiq_init_slots(slot_mem, slot_mem_size);
if (!vchiq_slot_zero)
return -EINVAL;
vchiq_slot_zero->platform_data[VCHIQ_PLATFORM_FRAGMENTS_OFFSET_IDX] =
(int)slot_phys + slot_mem_size;
vchiq_slot_zero->platform_data[VCHIQ_PLATFORM_FRAGMENTS_COUNT_IDX] =
MAX_FRAGMENTS;
g_fragments_base = (char *)slot_mem + slot_mem_size;
slot_mem_size += frag_mem_size;
g_free_fragments = g_fragments_base;
for (i = 0; i < (MAX_FRAGMENTS - 1); i++) {
*(char **)&g_fragments_base[i*g_fragments_size] =
&g_fragments_base[(i + 1)*g_fragments_size];
}
*(char **)&g_fragments_base[i * g_fragments_size] = NULL;
sema_init(&g_free_fragments_sema, MAX_FRAGMENTS);
if (vchiq_init_state(state, vchiq_slot_zero, 0) != VCHIQ_SUCCESS)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
g_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(g_regs))
return PTR_ERR(g_regs);
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "failed to get IRQ\n");
return irq;
}
err = devm_request_irq(dev, irq, vchiq_doorbell_irq, IRQF_IRQPOLL,
"VCHIQ doorbell", state);
if (err) {
dev_err(dev, "failed to register irq=%d\n", irq);
return err;
}
channelbase = slot_phys;
err = rpi_firmware_property(fw, RPI_FIRMWARE_VCHIQ_INIT,
&channelbase, sizeof(channelbase));
if (err || channelbase) {
dev_err(dev, "failed to set channelbase\n");
return err ? : -ENXIO;
}
g_dev = dev;
vchiq_log_info(vchiq_arm_log_level,
"vchiq_init - done (slots %pK, phys %pad)",
vchiq_slot_zero, &slot_phys);
vchiq_call_connected_callbacks();
return 0;
}
VCHIQ_STATUS_T
vchiq_platform_init_state(VCHIQ_STATE_T *state)
{
VCHIQ_STATUS_T status = VCHIQ_SUCCESS;
state->platform_state = kzalloc(sizeof(VCHIQ_2835_ARM_STATE_T), GFP_KERNEL);
((VCHIQ_2835_ARM_STATE_T *)state->platform_state)->inited = 1;
status = vchiq_arm_init_state(state, &((VCHIQ_2835_ARM_STATE_T *)state->platform_state)->arm_state);
if (status != VCHIQ_SUCCESS)
{
((VCHIQ_2835_ARM_STATE_T *)state->platform_state)->inited = 0;
}
return status;
}
VCHIQ_ARM_STATE_T*
vchiq_platform_get_arm_state(VCHIQ_STATE_T *state)
{
if (!((VCHIQ_2835_ARM_STATE_T *)state->platform_state)->inited)
{
BUG();
}
return &((VCHIQ_2835_ARM_STATE_T *)state->platform_state)->arm_state;
}
void
remote_event_signal(REMOTE_EVENT_T *event)
{
wmb();
event->fired = 1;
dsb(sy);
if (event->armed)
writel(0, g_regs + BELL2);
}
VCHIQ_STATUS_T
vchiq_prepare_bulk_data(VCHIQ_BULK_T *bulk, VCHI_MEM_HANDLE_T memhandle,
void *offset, int size, int dir)
{
struct vchiq_pagelist_info *pagelistinfo;
WARN_ON(memhandle != VCHI_MEM_HANDLE_INVALID);
pagelistinfo = create_pagelist((char __user *)offset, size,
(dir == VCHIQ_BULK_RECEIVE)
? PAGELIST_READ
: PAGELIST_WRITE,
current);
if (!pagelistinfo)
return VCHIQ_ERROR;
bulk->handle = memhandle;
bulk->data = (void *)(unsigned long)pagelistinfo->dma_addr;
bulk->remote_data = pagelistinfo;
return VCHIQ_SUCCESS;
}
void
vchiq_complete_bulk(VCHIQ_BULK_T *bulk)
{
if (bulk && bulk->remote_data && bulk->actual)
free_pagelist((struct vchiq_pagelist_info *)bulk->remote_data,
bulk->actual);
}
void
vchiq_transfer_bulk(VCHIQ_BULK_T *bulk)
{
BUG();
}
void
vchiq_dump_platform_state(void *dump_context)
{
char buf[80];
int len;
len = snprintf(buf, sizeof(buf),
" Platform: 2835 (VC master)");
vchiq_dump(dump_context, buf, len + 1);
}
VCHIQ_STATUS_T
vchiq_platform_suspend(VCHIQ_STATE_T *state)
{
return VCHIQ_ERROR;
}
VCHIQ_STATUS_T
vchiq_platform_resume(VCHIQ_STATE_T *state)
{
return VCHIQ_SUCCESS;
}
void
vchiq_platform_paused(VCHIQ_STATE_T *state)
{
}
void
vchiq_platform_resumed(VCHIQ_STATE_T *state)
{
}
int
vchiq_platform_videocore_wanted(VCHIQ_STATE_T *state)
{
return 1;
}
int
vchiq_platform_use_suspend_timer(void)
{
return 0;
}
void
vchiq_dump_platform_use_state(VCHIQ_STATE_T *state)
{
vchiq_log_info(vchiq_arm_log_level, "Suspend timer not in use");
}
void
vchiq_platform_handle_timeout(VCHIQ_STATE_T *state)
{
(void)state;
}
static irqreturn_t
vchiq_doorbell_irq(int irq, void *dev_id)
{
VCHIQ_STATE_T *state = dev_id;
irqreturn_t ret = IRQ_NONE;
unsigned int status;
status = readl(g_regs + BELL0);
if (status & 0x4) {
remote_event_pollall(state);
ret = IRQ_HANDLED;
}
return ret;
}
static void
cleaup_pagelistinfo(struct vchiq_pagelist_info *pagelistinfo)
{
if (pagelistinfo->scatterlist_mapped) {
dma_unmap_sg(g_dev, pagelistinfo->scatterlist,
pagelistinfo->num_pages, pagelistinfo->dma_dir);
}
if (pagelistinfo->pages_need_release) {
unsigned int i;
for (i = 0; i < pagelistinfo->num_pages; i++)
put_page(pagelistinfo->pages[i]);
}
dma_free_coherent(g_dev, pagelistinfo->pagelist_buffer_size,
pagelistinfo->pagelist, pagelistinfo->dma_addr);
}
static struct vchiq_pagelist_info *
create_pagelist(char __user *buf, size_t count, unsigned short type,
struct task_struct *task)
{
PAGELIST_T *pagelist;
struct vchiq_pagelist_info *pagelistinfo;
struct page **pages;
u32 *addrs;
unsigned int num_pages, offset, i, k;
int actual_pages;
size_t pagelist_size;
struct scatterlist *scatterlist, *sg;
int dma_buffers;
dma_addr_t dma_addr;
offset = ((unsigned int)(unsigned long)buf & (PAGE_SIZE - 1));
num_pages = (count + offset + PAGE_SIZE - 1) / PAGE_SIZE;
pagelist_size = sizeof(PAGELIST_T) +
(num_pages * sizeof(u32)) +
(num_pages * sizeof(pages[0]) +
(num_pages * sizeof(struct scatterlist))) +
sizeof(struct vchiq_pagelist_info);
pagelist = dma_zalloc_coherent(g_dev,
pagelist_size,
&dma_addr,
GFP_KERNEL);
vchiq_log_trace(vchiq_arm_log_level, "create_pagelist - %pK",
pagelist);
if (!pagelist)
return NULL;
addrs = pagelist->addrs;
pages = (struct page **)(addrs + num_pages);
scatterlist = (struct scatterlist *)(pages + num_pages);
pagelistinfo = (struct vchiq_pagelist_info *)
(scatterlist + num_pages);
pagelist->length = count;
pagelist->type = type;
pagelist->offset = offset;
pagelistinfo->pagelist = pagelist;
pagelistinfo->pagelist_buffer_size = pagelist_size;
pagelistinfo->dma_addr = dma_addr;
pagelistinfo->dma_dir = (type == PAGELIST_WRITE) ?
DMA_TO_DEVICE : DMA_FROM_DEVICE;
pagelistinfo->num_pages = num_pages;
pagelistinfo->pages_need_release = 0;
pagelistinfo->pages = pages;
pagelistinfo->scatterlist = scatterlist;
pagelistinfo->scatterlist_mapped = 0;
if (is_vmalloc_addr(buf)) {
unsigned long length = count;
unsigned int off = offset;
for (actual_pages = 0; actual_pages < num_pages;
actual_pages++) {
struct page *pg = vmalloc_to_page(buf + (actual_pages *
PAGE_SIZE));
size_t bytes = PAGE_SIZE - off;
if (bytes > length)
bytes = length;
pages[actual_pages] = pg;
length -= bytes;
off = 0;
}
} else {
down_read(&task->mm->mmap_sem);
actual_pages = get_user_pages(
(unsigned long)buf & ~(PAGE_SIZE - 1),
num_pages,
(type == PAGELIST_READ) ? FOLL_WRITE : 0,
pages,
NULL );
up_read(&task->mm->mmap_sem);
if (actual_pages != num_pages) {
vchiq_log_info(vchiq_arm_log_level,
"create_pagelist - only %d/%d pages locked",
actual_pages,
num_pages);
while (actual_pages > 0)
{
actual_pages--;
put_page(pages[actual_pages]);
}
cleaup_pagelistinfo(pagelistinfo);
return NULL;
}
pagelistinfo->pages_need_release = 1;
}
sg_init_table(scatterlist, num_pages);
for (i = 0; i < num_pages; i++)
sg_set_page(scatterlist + i, pages[i], PAGE_SIZE, 0);
dma_buffers = dma_map_sg(g_dev,
scatterlist,
num_pages,
pagelistinfo->dma_dir);
if (dma_buffers == 0) {
cleaup_pagelistinfo(pagelistinfo);
return NULL;
}
pagelistinfo->scatterlist_mapped = 1;
k = 0;
for_each_sg(scatterlist, sg, dma_buffers, i) {
u32 len = sg_dma_len(sg);
u32 addr = sg_dma_address(sg);
WARN_ON(len == 0);
WARN_ON(len & ~PAGE_MASK);
WARN_ON(addr & ~PAGE_MASK);
if (k > 0 &&
((addrs[k - 1] & PAGE_MASK) |
((addrs[k - 1] & ~PAGE_MASK) + 1) << PAGE_SHIFT)
== addr) {
addrs[k - 1] += (len >> PAGE_SHIFT);
} else {
addrs[k++] = addr | ((len >> PAGE_SHIFT) - 1);
}
}
if ((type == PAGELIST_READ) &&
((pagelist->offset & (g_cache_line_size - 1)) ||
((pagelist->offset + pagelist->length) &
(g_cache_line_size - 1)))) {
char *fragments;
if (down_interruptible(&g_free_fragments_sema) != 0) {
cleaup_pagelistinfo(pagelistinfo);
return NULL;
}
WARN_ON(g_free_fragments == NULL);
down(&g_free_fragments_mutex);
fragments = g_free_fragments;
WARN_ON(fragments == NULL);
g_free_fragments = *(char **) g_free_fragments;
up(&g_free_fragments_mutex);
pagelist->type = PAGELIST_READ_WITH_FRAGMENTS +
(fragments - g_fragments_base) / g_fragments_size;
}
return pagelistinfo;
}
static void
free_pagelist(struct vchiq_pagelist_info *pagelistinfo,
int actual)
{
unsigned int i;
PAGELIST_T *pagelist = pagelistinfo->pagelist;
struct page **pages = pagelistinfo->pages;
unsigned int num_pages = pagelistinfo->num_pages;
vchiq_log_trace(vchiq_arm_log_level, "free_pagelist - %pK, %d",
pagelistinfo->pagelist, actual);
dma_unmap_sg(g_dev, pagelistinfo->scatterlist,
pagelistinfo->num_pages, pagelistinfo->dma_dir);
pagelistinfo->scatterlist_mapped = 0;
if (pagelist->type >= PAGELIST_READ_WITH_FRAGMENTS) {
char *fragments = g_fragments_base +
(pagelist->type - PAGELIST_READ_WITH_FRAGMENTS) *
g_fragments_size;
int head_bytes, tail_bytes;
head_bytes = (g_cache_line_size - pagelist->offset) &
(g_cache_line_size - 1);
tail_bytes = (pagelist->offset + actual) &
(g_cache_line_size - 1);
if ((actual >= 0) && (head_bytes != 0)) {
if (head_bytes > actual)
head_bytes = actual;
memcpy((char *)page_address(pages[0]) +
pagelist->offset,
fragments,
head_bytes);
}
if ((actual >= 0) && (head_bytes < actual) &&
(tail_bytes != 0)) {
memcpy((char *)page_address(pages[num_pages - 1]) +
((pagelist->offset + actual) &
(PAGE_SIZE - 1) & ~(g_cache_line_size - 1)),
fragments + g_cache_line_size,
tail_bytes);
}
down(&g_free_fragments_mutex);
*(char **)fragments = g_free_fragments;
g_free_fragments = fragments;
up(&g_free_fragments_mutex);
up(&g_free_fragments_sema);
}
if (pagelist->type != PAGELIST_WRITE &&
pagelistinfo->pages_need_release) {
for (i = 0; i < num_pages; i++)
set_page_dirty(pages[i]);
}
cleaup_pagelistinfo(pagelistinfo);
}
