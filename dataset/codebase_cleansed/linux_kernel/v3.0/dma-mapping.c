static int __init dma_init(void)
{
dma_debug_init(PREALLOC_DMA_DEBUG_ENTRIES);
return 0;
}
struct dma_map_ops *dma_get_ops(struct device *dev)
{
return dma_ops;
}
