void ssi_pm_ext_hw_suspend(struct device *dev)
{
struct ssi_drvdata *drvdata =
(struct ssi_drvdata *)dev_get_drvdata(dev);
unsigned int val;
void __iomem *cc_base = drvdata->cc_base;
unsigned int sram_addr = 0;
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, SRAM_ADDR), sram_addr);
for (;sram_addr < SSI_CC_SRAM_SIZE ; sram_addr+=4) {
CC_HAL_WRITE_REGISTER(CC_REG_OFFSET(HOST_RGF, SRAM_DATA), 0x0);
do {
val = CC_HAL_READ_REGISTER(CC_REG_OFFSET(HOST_RGF, SRAM_DATA_READY));
} while (!(val &0x1));
}
}
void ssi_pm_ext_hw_resume(struct device *dev)
{
return;
}
