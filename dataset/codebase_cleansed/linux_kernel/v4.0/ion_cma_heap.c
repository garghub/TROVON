static int ion_cma_allocate(struct ion_heap *heap, struct ion_buffer *buffer,
unsigned long len, unsigned long align,
unsigned long flags)
{
struct ion_cma_heap *cma_heap = to_cma_heap(heap);
struct device *dev = cma_heap->dev;
struct ion_cma_buffer_info *info;
dev_dbg(dev, "Request buffer allocation len %ld\n", len);
if (buffer->flags & ION_FLAG_CACHED)
return -EINVAL;
if (align > PAGE_SIZE)
return -EINVAL;
info = kzalloc(sizeof(struct ion_cma_buffer_info), GFP_KERNEL);
if (!info)
return ION_CMA_ALLOCATE_FAILED;
info->cpu_addr = dma_alloc_coherent(dev, len, &(info->handle),
GFP_HIGHUSER | __GFP_ZERO);
if (!info->cpu_addr) {
dev_err(dev, "Fail to allocate buffer\n");
goto err;
}
info->table = kmalloc(sizeof(struct sg_table), GFP_KERNEL);
if (!info->table)
goto free_mem;
if (dma_common_get_sgtable
(dev, info->table, info->cpu_addr, info->handle, len))
goto free_table;
buffer->priv_virt = info;
dev_dbg(dev, "Allocate buffer %p\n", buffer);
return 0;
free_table:
kfree(info->table);
free_mem:
dma_free_coherent(dev, len, info->cpu_addr, info->handle);
err:
kfree(info);
return ION_CMA_ALLOCATE_FAILED;
}
static void ion_cma_free(struct ion_buffer *buffer)
{
struct ion_cma_heap *cma_heap = to_cma_heap(buffer->heap);
struct device *dev = cma_heap->dev;
struct ion_cma_buffer_info *info = buffer->priv_virt;
dev_dbg(dev, "Release buffer %p\n", buffer);
dma_free_coherent(dev, buffer->size, info->cpu_addr, info->handle);
sg_free_table(info->table);
kfree(info->table);
kfree(info);
}
static int ion_cma_phys(struct ion_heap *heap, struct ion_buffer *buffer,
ion_phys_addr_t *addr, size_t *len)
{
struct ion_cma_heap *cma_heap = to_cma_heap(buffer->heap);
struct device *dev = cma_heap->dev;
struct ion_cma_buffer_info *info = buffer->priv_virt;
dev_dbg(dev, "Return buffer %p physical address %pa\n", buffer,
&info->handle);
*addr = info->handle;
*len = buffer->size;
return 0;
}
static struct sg_table *ion_cma_heap_map_dma(struct ion_heap *heap,
struct ion_buffer *buffer)
{
struct ion_cma_buffer_info *info = buffer->priv_virt;
return info->table;
}
static void ion_cma_heap_unmap_dma(struct ion_heap *heap,
struct ion_buffer *buffer)
{
}
static int ion_cma_mmap(struct ion_heap *mapper, struct ion_buffer *buffer,
struct vm_area_struct *vma)
{
struct ion_cma_heap *cma_heap = to_cma_heap(buffer->heap);
struct device *dev = cma_heap->dev;
struct ion_cma_buffer_info *info = buffer->priv_virt;
return dma_mmap_coherent(dev, vma, info->cpu_addr, info->handle,
buffer->size);
}
static void *ion_cma_map_kernel(struct ion_heap *heap,
struct ion_buffer *buffer)
{
struct ion_cma_buffer_info *info = buffer->priv_virt;
return info->cpu_addr;
}
static void ion_cma_unmap_kernel(struct ion_heap *heap,
struct ion_buffer *buffer)
{
}
struct ion_heap *ion_cma_heap_create(struct ion_platform_heap *data)
{
struct ion_cma_heap *cma_heap;
cma_heap = kzalloc(sizeof(struct ion_cma_heap), GFP_KERNEL);
if (!cma_heap)
return ERR_PTR(-ENOMEM);
cma_heap->heap.ops = &ion_cma_ops;
cma_heap->dev = data->priv;
cma_heap->heap.type = ION_HEAP_TYPE_DMA;
return &cma_heap->heap;
}
void ion_cma_heap_destroy(struct ion_heap *heap)
{
struct ion_cma_heap *cma_heap = to_cma_heap(heap);
kfree(cma_heap);
}
