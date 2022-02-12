static int __init dma_init(void)\r\n{\r\ndma_debug_init(PREALLOC_DMA_DEBUG_ENTRIES);\r\nreturn 0;\r\n}\r\nstruct dma_map_ops *dma_get_ops(struct device *dev)\r\n{\r\nreturn dma_ops;\r\n}
