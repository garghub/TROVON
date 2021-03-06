static ssize_t dmabounce_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct dmabounce_device_info *device_info = dev->archdata.dmabounce;
return sprintf(buf, "%lu %lu %lu %lu %lu %lu\n",
device_info->small.allocs,
device_info->large.allocs,
device_info->total_allocs - device_info->small.allocs -
device_info->large.allocs,
device_info->total_allocs,
device_info->map_op_count,
device_info->bounce_count);
}
static inline struct safe_buffer *
alloc_safe_buffer(struct dmabounce_device_info *device_info, void *ptr,
size_t size, enum dma_data_direction dir)
{
struct safe_buffer *buf;
struct dmabounce_pool *pool;
struct device *dev = device_info->dev;
unsigned long flags;
dev_dbg(dev, "%s(ptr=%p, size=%d, dir=%d)\n",
__func__, ptr, size, dir);
if (size <= device_info->small.size) {
pool = &device_info->small;
} else if (size <= device_info->large.size) {
pool = &device_info->large;
} else {
pool = NULL;
}
buf = kmalloc(sizeof(struct safe_buffer), GFP_ATOMIC);
if (buf == NULL) {
dev_warn(dev, "%s: kmalloc failed\n", __func__);
return NULL;
}
buf->ptr = ptr;
buf->size = size;
buf->direction = dir;
buf->pool = pool;
if (pool) {
buf->safe = dma_pool_alloc(pool->pool, GFP_ATOMIC,
&buf->safe_dma_addr);
} else {
buf->safe = dma_alloc_coherent(dev, size, &buf->safe_dma_addr,
GFP_ATOMIC);
}
if (buf->safe == NULL) {
dev_warn(dev,
"%s: could not alloc dma memory (size=%d)\n",
__func__, size);
kfree(buf);
return NULL;
}
#ifdef STATS
if (pool)
pool->allocs++;
device_info->total_allocs++;
#endif
write_lock_irqsave(&device_info->lock, flags);
list_add(&buf->node, &device_info->safe_buffers);
write_unlock_irqrestore(&device_info->lock, flags);
return buf;
}
static inline struct safe_buffer *
find_safe_buffer(struct dmabounce_device_info *device_info, dma_addr_t safe_dma_addr)
{
struct safe_buffer *b, *rb = NULL;
unsigned long flags;
read_lock_irqsave(&device_info->lock, flags);
list_for_each_entry(b, &device_info->safe_buffers, node)
if (b->safe_dma_addr == safe_dma_addr) {
rb = b;
break;
}
read_unlock_irqrestore(&device_info->lock, flags);
return rb;
}
static inline void
free_safe_buffer(struct dmabounce_device_info *device_info, struct safe_buffer *buf)
{
unsigned long flags;
dev_dbg(device_info->dev, "%s(buf=%p)\n", __func__, buf);
write_lock_irqsave(&device_info->lock, flags);
list_del(&buf->node);
write_unlock_irqrestore(&device_info->lock, flags);
if (buf->pool)
dma_pool_free(buf->pool->pool, buf->safe, buf->safe_dma_addr);
else
dma_free_coherent(device_info->dev, buf->size, buf->safe,
buf->safe_dma_addr);
kfree(buf);
}
static struct safe_buffer *find_safe_buffer_dev(struct device *dev,
dma_addr_t dma_addr, const char *where)
{
if (!dev || !dev->archdata.dmabounce)
return NULL;
if (dma_mapping_error(dev, dma_addr)) {
dev_err(dev, "Trying to %s invalid mapping\n", where);
return NULL;
}
return find_safe_buffer(dev->archdata.dmabounce, dma_addr);
}
static int needs_bounce(struct device *dev, dma_addr_t dma_addr, size_t size)
{
if (!dev || !dev->archdata.dmabounce)
return 0;
if (dev->dma_mask) {
unsigned long limit, mask = *dev->dma_mask;
limit = (mask + 1) & ~mask;
if (limit && size > limit) {
dev_err(dev, "DMA mapping too big (requested %#x "
"mask %#Lx)\n", size, *dev->dma_mask);
return -E2BIG;
}
if ((dma_addr | (dma_addr + size - 1)) & ~mask)
return 1;
}
return !!dev->archdata.dmabounce->needs_bounce(dev, dma_addr, size);
}
static inline dma_addr_t map_single(struct device *dev, void *ptr, size_t size,
enum dma_data_direction dir)
{
struct dmabounce_device_info *device_info = dev->archdata.dmabounce;
struct safe_buffer *buf;
if (device_info)
DO_STATS ( device_info->map_op_count++ );
buf = alloc_safe_buffer(device_info, ptr, size, dir);
if (buf == NULL) {
dev_err(dev, "%s: unable to map unsafe buffer %p!\n",
__func__, ptr);
return ~0;
}
dev_dbg(dev, "%s: unsafe buffer %p (dma=%#x) mapped to %p (dma=%#x)\n",
__func__, buf->ptr, virt_to_dma(dev, buf->ptr),
buf->safe, buf->safe_dma_addr);
if (dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL) {
dev_dbg(dev, "%s: copy unsafe %p to safe %p, size %d\n",
__func__, ptr, buf->safe, size);
memcpy(buf->safe, ptr, size);
}
return buf->safe_dma_addr;
}
static inline void unmap_single(struct device *dev, struct safe_buffer *buf,
size_t size, enum dma_data_direction dir)
{
BUG_ON(buf->size != size);
BUG_ON(buf->direction != dir);
dev_dbg(dev, "%s: unsafe buffer %p (dma=%#x) mapped to %p (dma=%#x)\n",
__func__, buf->ptr, virt_to_dma(dev, buf->ptr),
buf->safe, buf->safe_dma_addr);
DO_STATS(dev->archdata.dmabounce->bounce_count++);
if (dir == DMA_FROM_DEVICE || dir == DMA_BIDIRECTIONAL) {
void *ptr = buf->ptr;
dev_dbg(dev, "%s: copy back safe %p to unsafe %p size %d\n",
__func__, buf->safe, ptr, size);
memcpy(ptr, buf->safe, size);
__cpuc_flush_dcache_area(ptr, size);
}
free_safe_buffer(dev->archdata.dmabounce, buf);
}
dma_addr_t __dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size, enum dma_data_direction dir)
{
dma_addr_t dma_addr;
int ret;
dev_dbg(dev, "%s(page=%p,off=%#lx,size=%zx,dir=%x)\n",
__func__, page, offset, size, dir);
dma_addr = pfn_to_dma(dev, page_to_pfn(page)) + offset;
ret = needs_bounce(dev, dma_addr, size);
if (ret < 0)
return ~0;
if (ret == 0) {
__dma_page_cpu_to_dev(page, offset, size, dir);
return dma_addr;
}
if (PageHighMem(page)) {
dev_err(dev, "DMA buffer bouncing of HIGHMEM pages is not supported\n");
return ~0;
}
return map_single(dev, page_address(page) + offset, size, dir);
}
void __dma_unmap_page(struct device *dev, dma_addr_t dma_addr, size_t size,
enum dma_data_direction dir)
{
struct safe_buffer *buf;
dev_dbg(dev, "%s(dma=%#x,size=%d,dir=%x)\n",
__func__, dma_addr, size, dir);
buf = find_safe_buffer_dev(dev, dma_addr, __func__);
if (!buf) {
__dma_page_dev_to_cpu(pfn_to_page(dma_to_pfn(dev, dma_addr)),
dma_addr & ~PAGE_MASK, size, dir);
return;
}
unmap_single(dev, buf, size, dir);
}
int dmabounce_sync_for_cpu(struct device *dev, dma_addr_t addr,
unsigned long off, size_t sz, enum dma_data_direction dir)
{
struct safe_buffer *buf;
dev_dbg(dev, "%s(dma=%#x,off=%#lx,sz=%zx,dir=%x)\n",
__func__, addr, off, sz, dir);
buf = find_safe_buffer_dev(dev, addr, __func__);
if (!buf)
return 1;
BUG_ON(buf->direction != dir);
dev_dbg(dev, "%s: unsafe buffer %p (dma=%#x) mapped to %p (dma=%#x)\n",
__func__, buf->ptr, virt_to_dma(dev, buf->ptr),
buf->safe, buf->safe_dma_addr);
DO_STATS(dev->archdata.dmabounce->bounce_count++);
if (dir == DMA_FROM_DEVICE || dir == DMA_BIDIRECTIONAL) {
dev_dbg(dev, "%s: copy back safe %p to unsafe %p size %d\n",
__func__, buf->safe + off, buf->ptr + off, sz);
memcpy(buf->ptr + off, buf->safe + off, sz);
}
return 0;
}
int dmabounce_sync_for_device(struct device *dev, dma_addr_t addr,
unsigned long off, size_t sz, enum dma_data_direction dir)
{
struct safe_buffer *buf;
dev_dbg(dev, "%s(dma=%#x,off=%#lx,sz=%zx,dir=%x)\n",
__func__, addr, off, sz, dir);
buf = find_safe_buffer_dev(dev, addr, __func__);
if (!buf)
return 1;
BUG_ON(buf->direction != dir);
dev_dbg(dev, "%s: unsafe buffer %p (dma=%#x) mapped to %p (dma=%#x)\n",
__func__, buf->ptr, virt_to_dma(dev, buf->ptr),
buf->safe, buf->safe_dma_addr);
DO_STATS(dev->archdata.dmabounce->bounce_count++);
if (dir == DMA_TO_DEVICE || dir == DMA_BIDIRECTIONAL) {
dev_dbg(dev, "%s: copy out unsafe %p to safe %p, size %d\n",
__func__,buf->ptr + off, buf->safe + off, sz);
memcpy(buf->safe + off, buf->ptr + off, sz);
}
return 0;
}
static int dmabounce_init_pool(struct dmabounce_pool *pool, struct device *dev,
const char *name, unsigned long size)
{
pool->size = size;
DO_STATS(pool->allocs = 0);
pool->pool = dma_pool_create(name, dev, size,
0 ,
0 );
return pool->pool ? 0 : -ENOMEM;
}
int dmabounce_register_dev(struct device *dev, unsigned long small_buffer_size,
unsigned long large_buffer_size,
int (*needs_bounce_fn)(struct device *, dma_addr_t, size_t))
{
struct dmabounce_device_info *device_info;
int ret;
device_info = kmalloc(sizeof(struct dmabounce_device_info), GFP_ATOMIC);
if (!device_info) {
dev_err(dev,
"Could not allocated dmabounce_device_info\n");
return -ENOMEM;
}
ret = dmabounce_init_pool(&device_info->small, dev,
"small_dmabounce_pool", small_buffer_size);
if (ret) {
dev_err(dev,
"dmabounce: could not allocate DMA pool for %ld byte objects\n",
small_buffer_size);
goto err_free;
}
if (large_buffer_size) {
ret = dmabounce_init_pool(&device_info->large, dev,
"large_dmabounce_pool",
large_buffer_size);
if (ret) {
dev_err(dev,
"dmabounce: could not allocate DMA pool for %ld byte objects\n",
large_buffer_size);
goto err_destroy;
}
}
device_info->dev = dev;
INIT_LIST_HEAD(&device_info->safe_buffers);
rwlock_init(&device_info->lock);
device_info->needs_bounce = needs_bounce_fn;
#ifdef STATS
device_info->total_allocs = 0;
device_info->map_op_count = 0;
device_info->bounce_count = 0;
device_info->attr_res = device_create_file(dev, &dev_attr_dmabounce_stats);
#endif
dev->archdata.dmabounce = device_info;
dev_info(dev, "dmabounce: registered device\n");
return 0;
err_destroy:
dma_pool_destroy(device_info->small.pool);
err_free:
kfree(device_info);
return ret;
}
void dmabounce_unregister_dev(struct device *dev)
{
struct dmabounce_device_info *device_info = dev->archdata.dmabounce;
dev->archdata.dmabounce = NULL;
if (!device_info) {
dev_warn(dev,
"Never registered with dmabounce but attempting"
"to unregister!\n");
return;
}
if (!list_empty(&device_info->safe_buffers)) {
dev_err(dev,
"Removing from dmabounce with pending buffers!\n");
BUG();
}
if (device_info->small.pool)
dma_pool_destroy(device_info->small.pool);
if (device_info->large.pool)
dma_pool_destroy(device_info->large.pool);
#ifdef STATS
if (device_info->attr_res == 0)
device_remove_file(dev, &dev_attr_dmabounce_stats);
#endif
kfree(device_info);
dev_info(dev, "dmabounce: device unregistered\n");
}
