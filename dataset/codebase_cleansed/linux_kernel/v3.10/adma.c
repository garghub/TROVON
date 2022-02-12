static int __init iop3xx_adma_cap_init(void)
{
#ifdef CONFIG_ARCH_IOP32X
dma_cap_set(DMA_MEMCPY, iop3xx_dma_0_data.cap_mask);
dma_cap_set(DMA_INTERRUPT, iop3xx_dma_0_data.cap_mask);
#else
dma_cap_set(DMA_MEMCPY, iop3xx_dma_0_data.cap_mask);
dma_cap_set(DMA_INTERRUPT, iop3xx_dma_0_data.cap_mask);
#endif
#ifdef CONFIG_ARCH_IOP32X
dma_cap_set(DMA_MEMCPY, iop3xx_dma_1_data.cap_mask);
dma_cap_set(DMA_INTERRUPT, iop3xx_dma_1_data.cap_mask);
#else
dma_cap_set(DMA_MEMCPY, iop3xx_dma_1_data.cap_mask);
dma_cap_set(DMA_INTERRUPT, iop3xx_dma_1_data.cap_mask);
#endif
#ifdef CONFIG_ARCH_IOP32X
dma_cap_set(DMA_XOR, iop3xx_aau_data.cap_mask);
dma_cap_set(DMA_MEMSET, iop3xx_aau_data.cap_mask);
dma_cap_set(DMA_INTERRUPT, iop3xx_aau_data.cap_mask);
#else
dma_cap_set(DMA_XOR, iop3xx_aau_data.cap_mask);
dma_cap_set(DMA_XOR_VAL, iop3xx_aau_data.cap_mask);
dma_cap_set(DMA_MEMSET, iop3xx_aau_data.cap_mask);
dma_cap_set(DMA_INTERRUPT, iop3xx_aau_data.cap_mask);
#endif
return 0;
}
