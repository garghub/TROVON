int __init bcm63xx_dsp_register(const struct bcm63xx_dsp_platform_data *pd)
{
struct bcm63xx_dsp_platform_data *dpd;
u32 val;
val = bcm_mpi_readl(MPI_CSBASE_REG(pd->cs - 1));
val &= MPI_CSBASE_BASE_MASK;
voip_dsp_resources[0].start = val;
voip_dsp_resources[0].end = val + 0xFFFFFFF;
voip_dsp_resources[1].start = pd->ext_irq;
dpd = bcm63xx_voip_dsp_device.dev.platform_data;
memcpy(dpd, pd, sizeof (*pd));
return platform_device_register(&bcm63xx_voip_dsp_device);
}
