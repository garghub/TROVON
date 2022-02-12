void *dma_alloc_noncoherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp)
{
void *paddr;
paddr = alloc_pages_exact(size, gfp);
if (!paddr)
return NULL;
*dma_handle = plat_kernel_addr_to_dma(dev, paddr);
return paddr;
}
void dma_free_noncoherent(struct device *dev, size_t size, void *vaddr,
dma_addr_t dma_handle)
{
free_pages_exact((void *)plat_dma_addr_to_kernel(dev, dma_handle),
size);
}
void *dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp)
{
void *paddr, *kvaddr;
paddr = alloc_pages_exact(size, gfp);
if (!paddr)
return NULL;
kvaddr = ioremap_nocache((unsigned long)paddr, size);
if (kvaddr != NULL)
memset(kvaddr, 0, size);
*dma_handle = plat_kernel_addr_to_dma(dev, paddr);
return kvaddr;
}
void dma_free_coherent(struct device *dev, size_t size, void *kvaddr,
dma_addr_t dma_handle)
{
iounmap((void __force __iomem *)kvaddr);
free_pages_exact((void *)plat_dma_addr_to_kernel(dev, dma_handle),
size);
}
void __arc_dma_cache_sync(unsigned long paddr, size_t size,
enum dma_data_direction dir)
{
__inline_dma_cache_sync(paddr, size, dir);
}
