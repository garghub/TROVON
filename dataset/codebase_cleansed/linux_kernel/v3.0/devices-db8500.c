void dma40_u8500ed_fixup(void)
{
dma40_plat_data.memcpy = NULL;
dma40_plat_data.memcpy_len = 0;
dma40_resources[0].start = U8500_DMA_BASE_ED;
dma40_resources[0].end = U8500_DMA_BASE_ED + SZ_4K - 1;
dma40_resources[1].start = U8500_DMA_LCPA_BASE_ED;
dma40_resources[1].end = U8500_DMA_LCPA_BASE_ED + 2 * SZ_1K - 1;
}
