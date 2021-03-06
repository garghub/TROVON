void *dma_alloc_coherent(struct device *hwdev, size_t size, dma_addr_t *dma_handle, gfp_t gfp)
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
void dma_free_coherent(struct device *hwdev, size_t size, void *vaddr, dma_addr_t dma_handle)
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
dma_addr_t dma_map_single(struct device *dev, void *ptr, size_t size,
enum dma_data_direction direction)
{
BUG_ON(direction == DMA_NONE);
frv_cache_wback_inv((unsigned long) ptr, (unsigned long) ptr + size);
return virt_to_bus(ptr);
}
int dma_map_sg(struct device *dev, struct scatterlist *sg, int nents,
enum dma_data_direction direction)
{
int i;
for (i=0; i<nents; i++)
frv_cache_wback_inv(sg_dma_address(&sg[i]),
sg_dma_address(&sg[i]) + sg_dma_len(&sg[i]));
BUG_ON(direction == DMA_NONE);
return nents;
}
dma_addr_t dma_map_page(struct device *dev, struct page *page, unsigned long offset,
size_t size, enum dma_data_direction direction)
{
BUG_ON(direction == DMA_NONE);
flush_dcache_page(page);
return (dma_addr_t) page_to_phys(page) + offset;
}
