int __init bcm63xx_enet_register(int unit,
const struct bcm63xx_enet_platform_data *pd)
{
struct platform_device *pdev;
struct bcm63xx_enet_platform_data *dpd;
int ret;
if (unit > 1)
return -ENODEV;
if (unit == 1 && BCMCPU_IS_6338())
return -ENODEV;
if (!shared_device_registered) {
shared_res[0].start = bcm63xx_regset_address(RSET_ENETDMA);
shared_res[0].end = shared_res[0].start;
if (BCMCPU_IS_6338())
shared_res[0].end += (RSET_ENETDMA_SIZE / 2) - 1;
else
shared_res[0].end += (RSET_ENETDMA_SIZE) - 1;
ret = platform_device_register(&bcm63xx_enet_shared_device);
if (ret)
return ret;
shared_device_registered = 1;
}
if (unit == 0) {
enet0_res[0].start = bcm63xx_regset_address(RSET_ENET0);
enet0_res[0].end = enet0_res[0].start;
enet0_res[0].end += RSET_ENET_SIZE - 1;
enet0_res[1].start = bcm63xx_get_irq_number(IRQ_ENET0);
enet0_res[2].start = bcm63xx_get_irq_number(IRQ_ENET0_RXDMA);
enet0_res[3].start = bcm63xx_get_irq_number(IRQ_ENET0_TXDMA);
pdev = &bcm63xx_enet0_device;
} else {
enet1_res[0].start = bcm63xx_regset_address(RSET_ENET1);
enet1_res[0].end = enet1_res[0].start;
enet1_res[0].end += RSET_ENET_SIZE - 1;
enet1_res[1].start = bcm63xx_get_irq_number(IRQ_ENET1);
enet1_res[2].start = bcm63xx_get_irq_number(IRQ_ENET1_RXDMA);
enet1_res[3].start = bcm63xx_get_irq_number(IRQ_ENET1_TXDMA);
pdev = &bcm63xx_enet1_device;
}
dpd = pdev->dev.platform_data;
memcpy(dpd, pd, sizeof(*pd));
if (dpd->use_internal_phy) {
if (unit == 1)
return -ENODEV;
dpd->phy_id = 1;
dpd->has_phy_interrupt = 1;
dpd->phy_interrupt = bcm63xx_get_irq_number(IRQ_ENET_PHY);
}
ret = platform_device_register(pdev);
if (ret)
return ret;
return 0;
}
