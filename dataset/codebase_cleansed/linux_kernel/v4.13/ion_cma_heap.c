static int ion_cma_allocate(struct ion_heap *heap, struct ion_buffer *buffer,
unsigned long len,
unsigned long flags)
{
struct ion_cma_heap *cma_heap = to_cma_heap(heap);
struct sg_table *table;
struct page *pages;
int ret;
pages = cma_alloc(cma_heap->cma, len, 0, GFP_KERNEL);
if (!pages)
return -ENOMEM;
table = kmalloc(sizeof(struct sg_table), GFP_KERNEL);
if (!table)
goto err;
ret = sg_alloc_table(table, 1, GFP_KERNEL);
if (ret)
goto free_mem;
sg_set_page(table->sgl, pages, len, 0);
buffer->priv_virt = pages;
buffer->sg_table = table;
return 0;
free_mem:
kfree(table);
err:
cma_release(cma_heap->cma, pages, buffer->size);
return -ENOMEM;
}
static void ion_cma_free(struct ion_buffer *buffer)
{
struct ion_cma_heap *cma_heap = to_cma_heap(buffer->heap);
struct page *pages = buffer->priv_virt;
cma_release(cma_heap->cma, pages, buffer->size);
sg_free_table(buffer->sg_table);
kfree(buffer->sg_table);
}
static struct ion_heap *__ion_cma_heap_create(struct cma *cma)
{
struct ion_cma_heap *cma_heap;
cma_heap = kzalloc(sizeof(*cma_heap), GFP_KERNEL);
if (!cma_heap)
return ERR_PTR(-ENOMEM);
cma_heap->heap.ops = &ion_cma_ops;
cma_heap->cma = cma;
cma_heap->heap.type = ION_HEAP_TYPE_DMA;
return &cma_heap->heap;
}
int __ion_add_cma_heaps(struct cma *cma, void *data)
{
struct ion_heap *heap;
heap = __ion_cma_heap_create(cma);
if (IS_ERR(heap))
return PTR_ERR(heap);
heap->name = cma_get_name(cma);
ion_device_add_heap(heap);
return 0;
}
static int ion_add_cma_heaps(void)
{
cma_for_each_area(__ion_add_cma_heaps, NULL);
return 0;
}
