void *dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp)
{
void *ret;
gfp &= ~(__GFP_DMA | __GFP_HIGHMEM);
if (dev == NULL || (*dev->dma_mask < 0xffffffff))
gfp |= GFP_DMA;
ret = (void *)__get_free_pages(gfp, get_order(size));
if (ret != NULL) {
memset(ret, 0, size);
*dma_handle = virt_to_phys(ret);
}
return ret;
}
void dma_free_coherent(struct device *dev, size_t size,
void *vaddr, dma_addr_t dma_handle)
{
free_pages((unsigned long)vaddr, get_order(size));
}
void dma_sync_single_for_device(struct device *dev, dma_addr_t handle,
size_t size, enum dma_data_direction dir)
{
switch (dir) {
case DMA_TO_DEVICE:
flush_dcache_range(handle, size);
break;
case DMA_FROM_DEVICE:
break;
default:
if (printk_ratelimit())
printk("dma_sync_single_for_device: unsupported dir %u\n", dir);
break;
}
}
dma_addr_t dma_map_single(struct device *dev, void *addr, size_t size,
enum dma_data_direction dir)
{
dma_addr_t handle = virt_to_phys(addr);
flush_dcache_range(handle, size);
return handle;
}
dma_addr_t dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir)
{
dma_addr_t handle = page_to_phys(page) + offset;
dma_sync_single_for_device(dev, handle, size, dir);
return handle;
}
