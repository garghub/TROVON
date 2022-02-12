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
g_virt_to_bus_offset = virt_to_dma(dev, (void *)0);
(void)of_property_read_u32(dev->of_node, "cache-line-size",
&g_cache_line_size);
g_fragments_size = 2 * g_cache_line_size;
slot_mem_size = PAGE_ALIGN(TOTAL_SLOTS * VCHIQ_SLOT_SIZE);
frag_mem_size = PAGE_ALIGN(g_fragments_size * MAX_FRAGMENTS);
slot_mem = dmam_alloc_coherent(dev, slot_mem_size + frag_mem_size,
&slot_phys, GFP_KERNEL);
if (!slot_mem) {
dev_err(dev, "could not allocate DMA memory\n");
return -ENOMEM;
}
WARN_ON(((int)slot_mem & (PAGE_SIZE - 1)) != 0);
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
vchiq_log_info(vchiq_arm_log_level,
"vchiq_init - done (slots %x, phys %pad)",
(unsigned int)vchiq_slot_zero, &slot_phys);
vchiq_call_connected_callbacks();
return 0;
}
VCHIQ_STATUS_T
vchiq_platform_init_state(VCHIQ_STATE_T *state)
{
VCHIQ_STATUS_T status = VCHIQ_SUCCESS;
state->platform_state = kzalloc(sizeof(VCHIQ_2835_ARM_STATE_T), GFP_KERNEL);
((VCHIQ_2835_ARM_STATE_T*)state->platform_state)->inited = 1;
status = vchiq_arm_init_state(state, &((VCHIQ_2835_ARM_STATE_T*)state->platform_state)->arm_state);
if(status != VCHIQ_SUCCESS)
{
((VCHIQ_2835_ARM_STATE_T*)state->platform_state)->inited = 0;
}
return status;
}
VCHIQ_ARM_STATE_T*
vchiq_platform_get_arm_state(VCHIQ_STATE_T *state)
{
if(!((VCHIQ_2835_ARM_STATE_T*)state->platform_state)->inited)
{
BUG();
}
return &((VCHIQ_2835_ARM_STATE_T*)state->platform_state)->arm_state;
}
void
remote_event_signal(REMOTE_EVENT_T *event)
{
wmb();
event->fired = 1;
dsb();
if (event->armed)
writel(0, g_regs + BELL2);
}
int
vchiq_copy_from_user(void *dst, const void *src, int size)
{
if ((uint32_t)src < TASK_SIZE) {
return copy_from_user(dst, src, size);
} else {
memcpy(dst, src, size);
return 0;
}
}
VCHIQ_STATUS_T
vchiq_prepare_bulk_data(VCHIQ_BULK_T *bulk, VCHI_MEM_HANDLE_T memhandle,
void *offset, int size, int dir)
{
PAGELIST_T *pagelist;
int ret;
WARN_ON(memhandle != VCHI_MEM_HANDLE_INVALID);
ret = create_pagelist((char __user *)offset, size,
(dir == VCHIQ_BULK_RECEIVE)
? PAGELIST_READ
: PAGELIST_WRITE,
current,
&pagelist);
if (ret != 0)
return VCHIQ_ERROR;
bulk->handle = memhandle;
bulk->data = VCHIQ_ARM_ADDRESS(pagelist);
bulk->remote_data = pagelist;
return VCHIQ_SUCCESS;
}
void
vchiq_complete_bulk(VCHIQ_BULK_T *bulk)
{
if (bulk && bulk->remote_data && bulk->actual)
free_pagelist((PAGELIST_T *)bulk->remote_data, bulk->actual);
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
vchiq_platform_videocore_wanted(VCHIQ_STATE_T* state)
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
static int
create_pagelist(char __user *buf, size_t count, unsigned short type,
struct task_struct *task, PAGELIST_T ** ppagelist)
{
PAGELIST_T *pagelist;
struct page **pages;
unsigned long *addrs;
unsigned int num_pages, offset, i;
char *addr, *base_addr, *next_addr;
int run, addridx, actual_pages;
unsigned long *need_release;
offset = (unsigned int)buf & (PAGE_SIZE - 1);
num_pages = (count + offset + PAGE_SIZE - 1) / PAGE_SIZE;
*ppagelist = NULL;
pagelist = kmalloc(sizeof(PAGELIST_T) +
(num_pages * sizeof(unsigned long)) +
sizeof(unsigned long) +
(num_pages * sizeof(pages[0])),
GFP_KERNEL);
vchiq_log_trace(vchiq_arm_log_level,
"create_pagelist - %x", (unsigned int)pagelist);
if (!pagelist)
return -ENOMEM;
addrs = pagelist->addrs;
need_release = (unsigned long *)(addrs + num_pages);
pages = (struct page **)(addrs + num_pages + 1);
if (is_vmalloc_addr(buf)) {
int dir = (type == PAGELIST_WRITE) ?
DMA_TO_DEVICE : DMA_FROM_DEVICE;
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
dmac_map_area(page_address(pg) + off, bytes, dir);
length -= bytes;
off = 0;
}
*need_release = 0;
} else {
down_read(&task->mm->mmap_sem);
actual_pages = get_user_pages(task, task->mm,
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
page_cache_release(pages[actual_pages]);
}
kfree(pagelist);
if (actual_pages == 0)
actual_pages = -ENOMEM;
return actual_pages;
}
*need_release = 1;
}
pagelist->length = count;
pagelist->type = type;
pagelist->offset = offset;
base_addr = VCHIQ_ARM_ADDRESS(page_address(pages[0]));
next_addr = base_addr + PAGE_SIZE;
addridx = 0;
run = 0;
for (i = 1; i < num_pages; i++) {
addr = VCHIQ_ARM_ADDRESS(page_address(pages[i]));
if ((addr == next_addr) && (run < (PAGE_SIZE - 1))) {
next_addr += PAGE_SIZE;
run++;
} else {
addrs[addridx] = (unsigned long)base_addr + run;
addridx++;
base_addr = addr;
next_addr = addr + PAGE_SIZE;
run = 0;
}
}
addrs[addridx] = (unsigned long)base_addr + run;
addridx++;
if ((type == PAGELIST_READ) &&
((pagelist->offset & (g_cache_line_size - 1)) ||
((pagelist->offset + pagelist->length) &
(g_cache_line_size - 1)))) {
char *fragments;
if (down_interruptible(&g_free_fragments_sema) != 0) {
kfree(pagelist);
return -EINTR;
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
dmac_flush_range(pagelist, addrs + num_pages);
*ppagelist = pagelist;
return 0;
}
static void
free_pagelist(PAGELIST_T *pagelist, int actual)
{
unsigned long *need_release;
struct page **pages;
unsigned int num_pages, i;
vchiq_log_trace(vchiq_arm_log_level,
"free_pagelist - %x, %d", (unsigned int)pagelist, actual);
num_pages =
(pagelist->length + pagelist->offset + PAGE_SIZE - 1) /
PAGE_SIZE;
need_release = (unsigned long *)(pagelist->addrs + num_pages);
pages = (struct page **)(pagelist->addrs + num_pages + 1);
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
if (*need_release) {
unsigned int length = pagelist->length;
unsigned int offset = pagelist->offset;
for (i = 0; i < num_pages; i++) {
struct page *pg = pages[i];
if (pagelist->type != PAGELIST_WRITE) {
unsigned int bytes = PAGE_SIZE - offset;
if (bytes > length)
bytes = length;
dmac_unmap_area(page_address(pg) + offset,
bytes, DMA_FROM_DEVICE);
length -= bytes;
offset = 0;
set_page_dirty(pg);
}
page_cache_release(pg);
}
}
kfree(pagelist);
}
