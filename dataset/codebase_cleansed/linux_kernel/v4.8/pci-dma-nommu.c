static void *frv_dma_alloc(struct device *hwdev, size_t size, dma_addr_t *dma_handle,
gfp_t gfp, unsigned long attrs)
{
struct dma_alloc_record *new;
struct list_head *this = &dma_alloc_list;
unsigned long flags;
unsigned long start = DMA_SRAM_START;
unsigned long end;
if (!DMA_SRAM_START) {
printk("%s called without any DMA area reserved!\n", __func__);
return NULL;
}
new = kmalloc(sizeof (*new), GFP_ATOMIC);
if (!new)
return NULL;
new->len = (size + 31) & ~31;
spin_lock_irqsave(&dma_alloc_lock, flags);
list_for_each (this, &dma_alloc_list) {
struct dma_alloc_record *this_r = list_entry(this, struct dma_alloc_record, list);
end = this_r->ofs;
if (end - start >= size)
goto gotone;
start = this_r->ofs + this_r->len;
}
end = DMA_SRAM_END;
this = &dma_alloc_list;
if (end - start >= size) {
gotone:
new->ofs = start;
list_add_tail(&new->list, this);
spin_unlock_irqrestore(&dma_alloc_lock, flags);
*dma_handle = start;
return (void *)start;
}
kfree(new);
spin_unlock_irqrestore(&dma_alloc_lock, flags);
return NULL;
}
static void frv_dma_free(struct device *hwdev, size_t size, void *vaddr,
dma_addr_t dma_handle, unsigned long attrs)
{
struct dma_alloc_record *rec;
unsigned long flags;
spin_lock_irqsave(&dma_alloc_lock, flags);
list_for_each_entry(rec, &dma_alloc_list, list) {
if (rec->ofs == dma_handle) {
list_del(&rec->list);
kfree(rec);
spin_unlock_irqrestore(&dma_alloc_lock, flags);
return;
}
}
spin_unlock_irqrestore(&dma_alloc_lock, flags);
BUG();
}
static int frv_dma_map_sg(struct device *dev, struct scatterlist *sglist,
int nents, enum dma_data_direction direction,
unsigned long attrs)
{
int i;
struct scatterlist *sg;
for_each_sg(sglist, sg, nents, i) {
frv_cache_wback_inv(sg_dma_address(sg),
sg_dma_address(sg) + sg_dma_len(sg));
}
BUG_ON(direction == DMA_NONE);
return nents;
}
static dma_addr_t frv_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction direction, unsigned long attrs)
{
BUG_ON(direction == DMA_NONE);
flush_dcache_page(page);
return (dma_addr_t) page_to_phys(page) + offset;
}
static void frv_dma_sync_single_for_device(struct device *dev,
dma_addr_t dma_handle, size_t size,
enum dma_data_direction direction)
{
flush_write_buffers();
}
static void frv_dma_sync_sg_for_device(struct device *dev,
struct scatterlist *sg, int nelems,
enum dma_data_direction direction)
{
flush_write_buffers();
}
static int frv_dma_supported(struct device *dev, u64 mask)
{
if (mask < 0x00ffffff)
return 0;
return 1;
}
