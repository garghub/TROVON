int bcma_pflash_init(struct bcma_drv_cc *cc)
{
struct bcma_pflash *pflash = &cc->pflash;
pflash->present = true;
if (!(bcma_read32(cc->core, BCMA_CC_FLASH_CFG) & BCMA_CC_FLASH_CFG_DS))
bcma_pflash_data.width = 1;
else
bcma_pflash_data.width = 2;
bcma_pflash_resource.start = BCMA_SOC_FLASH2;
bcma_pflash_resource.end = BCMA_SOC_FLASH2 + BCMA_SOC_FLASH2_SZ;
return 0;
}
