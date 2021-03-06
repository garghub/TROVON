void dma_cache_sync(struct device *dev, void *vaddr, size_t size,\r\nenum dma_data_direction dir)\r\n{\r\nswitch (dir) {\r\ncase DMA_BIDIRECTIONAL:\r\n__flush_invalidate_dcache_range((unsigned long)vaddr, size);\r\nbreak;\r\ncase DMA_FROM_DEVICE:\r\n__invalidate_dcache_range((unsigned long)vaddr, size);\r\nbreak;\r\ncase DMA_TO_DEVICE:\r\n__flush_dcache_range((unsigned long)vaddr, size);\r\nbreak;\r\ncase DMA_NONE:\r\nBUG();\r\nbreak;\r\n}\r\n}\r\nstatic void do_cache_op(dma_addr_t dma_handle, size_t size,\r\nvoid (*fn)(unsigned long, unsigned long))\r\n{\r\nunsigned long off = dma_handle & (PAGE_SIZE - 1);\r\nunsigned long pfn = PFN_DOWN(dma_handle);\r\nstruct page *page = pfn_to_page(pfn);\r\nif (!PageHighMem(page))\r\nfn((unsigned long)bus_to_virt(dma_handle), size);\r\nelse\r\nwhile (size > 0) {\r\nsize_t sz = min_t(size_t, size, PAGE_SIZE - off);\r\nvoid *vaddr = kmap_atomic(page);\r\nfn((unsigned long)vaddr + off, sz);\r\nkunmap_atomic(vaddr);\r\noff = 0;\r\n++page;\r\nsize -= sz;\r\n}\r\n}\r\nstatic void xtensa_sync_single_for_cpu(struct device *dev,\r\ndma_addr_t dma_handle, size_t size,\r\nenum dma_data_direction dir)\r\n{\r\nswitch (dir) {\r\ncase DMA_BIDIRECTIONAL:\r\ncase DMA_FROM_DEVICE:\r\ndo_cache_op(dma_handle, size, __invalidate_dcache_range);\r\nbreak;\r\ncase DMA_NONE:\r\nBUG();\r\nbreak;\r\ndefault:\r\nbreak;\r\n}\r\n}\r\nstatic void xtensa_sync_single_for_device(struct device *dev,\r\ndma_addr_t dma_handle, size_t size,\r\nenum dma_data_direction dir)\r\n{\r\nswitch (dir) {\r\ncase DMA_BIDIRECTIONAL:\r\ncase DMA_TO_DEVICE:\r\nif (XCHAL_DCACHE_IS_WRITEBACK)\r\ndo_cache_op(dma_handle, size, __flush_dcache_range);\r\nbreak;\r\ncase DMA_NONE:\r\nBUG();\r\nbreak;\r\ndefault:\r\nbreak;\r\n}\r\n}\r\nstatic void xtensa_sync_sg_for_cpu(struct device *dev,\r\nstruct scatterlist *sg, int nents,\r\nenum dma_data_direction dir)\r\n{\r\nstruct scatterlist *s;\r\nint i;\r\nfor_each_sg(sg, s, nents, i) {\r\nxtensa_sync_single_for_cpu(dev, sg_dma_address(s),\r\nsg_dma_len(s), dir);\r\n}\r\n}\r\nstatic void xtensa_sync_sg_for_device(struct device *dev,\r\nstruct scatterlist *sg, int nents,\r\nenum dma_data_direction dir)\r\n{\r\nstruct scatterlist *s;\r\nint i;\r\nfor_each_sg(sg, s, nents, i) {\r\nxtensa_sync_single_for_device(dev, sg_dma_address(s),\r\nsg_dma_len(s), dir);\r\n}\r\n}\r\nstatic void *xtensa_dma_alloc(struct device *dev, size_t size,\r\ndma_addr_t *handle, gfp_t flag,\r\nunsigned long attrs)\r\n{\r\nunsigned long ret;\r\nunsigned long uncached = 0;\r\nunsigned long count = PAGE_ALIGN(size) >> PAGE_SHIFT;\r\nstruct page *page = NULL;\r\nflag &= ~(__GFP_DMA | __GFP_HIGHMEM);\r\nif (dev == NULL || (dev->coherent_dma_mask < 0xffffffff))\r\nflag |= GFP_DMA;\r\nif (gfpflags_allow_blocking(flag))\r\npage = dma_alloc_from_contiguous(dev, count, get_order(size),\r\nflag);\r\nif (!page)\r\npage = alloc_pages(flag, get_order(size));\r\nif (!page)\r\nreturn NULL;\r\nret = (unsigned long)page_address(page);\r\nBUG_ON(ret < XCHAL_KSEG_CACHED_VADDR ||\r\nret > XCHAL_KSEG_CACHED_VADDR + XCHAL_KSEG_SIZE - 1);\r\nuncached = ret + XCHAL_KSEG_BYPASS_VADDR - XCHAL_KSEG_CACHED_VADDR;\r\n*handle = virt_to_bus((void *)ret);\r\n__invalidate_dcache_range(ret, size);\r\nreturn (void *)uncached;\r\n}\r\nstatic void xtensa_dma_free(struct device *dev, size_t size, void *vaddr,\r\ndma_addr_t dma_handle, unsigned long attrs)\r\n{\r\nunsigned long addr = (unsigned long)vaddr +\r\nXCHAL_KSEG_CACHED_VADDR - XCHAL_KSEG_BYPASS_VADDR;\r\nstruct page *page = virt_to_page(addr);\r\nunsigned long count = PAGE_ALIGN(size) >> PAGE_SHIFT;\r\nBUG_ON(addr < XCHAL_KSEG_CACHED_VADDR ||\r\naddr > XCHAL_KSEG_CACHED_VADDR + XCHAL_KSEG_SIZE - 1);\r\nif (!dma_release_from_contiguous(dev, page, count))\r\n__free_pages(page, get_order(size));\r\n}\r\nstatic dma_addr_t xtensa_map_page(struct device *dev, struct page *page,\r\nunsigned long offset, size_t size,\r\nenum dma_data_direction dir,\r\nunsigned long attrs)\r\n{\r\ndma_addr_t dma_handle = page_to_phys(page) + offset;\r\nif (!(attrs & DMA_ATTR_SKIP_CPU_SYNC))\r\nxtensa_sync_single_for_device(dev, dma_handle, size, dir);\r\nreturn dma_handle;\r\n}\r\nstatic void xtensa_unmap_page(struct device *dev, dma_addr_t dma_handle,\r\nsize_t size, enum dma_data_direction dir,\r\nunsigned long attrs)\r\n{\r\nif (!(attrs & DMA_ATTR_SKIP_CPU_SYNC))\r\nxtensa_sync_single_for_cpu(dev, dma_handle, size, dir);\r\n}\r\nstatic int xtensa_map_sg(struct device *dev, struct scatterlist *sg,\r\nint nents, enum dma_data_direction dir,\r\nunsigned long attrs)\r\n{\r\nstruct scatterlist *s;\r\nint i;\r\nfor_each_sg(sg, s, nents, i) {\r\ns->dma_address = xtensa_map_page(dev, sg_page(s), s->offset,\r\ns->length, dir, attrs);\r\n}\r\nreturn nents;\r\n}\r\nstatic void xtensa_unmap_sg(struct device *dev,\r\nstruct scatterlist *sg, int nents,\r\nenum dma_data_direction dir,\r\nunsigned long attrs)\r\n{\r\nstruct scatterlist *s;\r\nint i;\r\nfor_each_sg(sg, s, nents, i) {\r\nxtensa_unmap_page(dev, sg_dma_address(s),\r\nsg_dma_len(s), dir, attrs);\r\n}\r\n}\r\nint xtensa_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)\r\n{\r\nreturn 0;\r\n}\r\nstatic int __init xtensa_dma_init(void)\r\n{\r\ndma_debug_init(PREALLOC_DMA_DEBUG_ENTRIES);\r\nreturn 0;\r\n}
