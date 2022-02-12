static __init void bcm63xx_enetdmac_regs_init(void)
{
if (BCMCPU_IS_6345())
bcm63xx_regs_enetdmac = bcm6345_regs_enetdmac;
else
bcm63xx_regs_enetdmac = bcm6348_regs_enetdmac;
}
static __init void bcm63xx_enetdmac_regs_init(void) { }
static int __init register_shared(void)
{
int ret, chan_count;
if (shared_device_registered)
return 0;
bcm63xx_enetdmac_regs_init();
shared_res[0].start = bcm63xx_regset_address(RSET_ENETDMA);
shared_res[0].end = shared_res[0].start;
if (BCMCPU_IS_6345())
shared_res[0].end += (RSET_6345_ENETDMA_SIZE) - 1;
else
shared_res[0].end += (RSET_ENETDMA_SIZE) - 1;
if (BCMCPU_IS_6328() || BCMCPU_IS_6362() || BCMCPU_IS_6368())
chan_count = 32;
else if (BCMCPU_IS_6345())
chan_count = 8;
else
chan_count = 16;
shared_res[1].start = bcm63xx_regset_address(RSET_ENETDMAC);
shared_res[1].end = shared_res[1].start;
shared_res[1].end += RSET_ENETDMAC_SIZE(chan_count) - 1;
shared_res[2].start = bcm63xx_regset_address(RSET_ENETDMAS);
shared_res[2].end = shared_res[2].start;
shared_res[2].end += RSET_ENETDMAS_SIZE(chan_count) - 1;
ret = platform_device_register(&bcm63xx_enet_shared_device);
if (ret)
return ret;
shared_device_registered = 1;
return 0;
}
int __init bcm63xx_enet_register(int unit,
const struct bcm63xx_enet_platform_data *pd)
{
struct platform_device *pdev;
struct bcm63xx_enet_platform_data *dpd;
int ret;
if (unit > 1)
return -ENODEV;
if (unit == 1 && (BCMCPU_IS_6338() || BCMCPU_IS_6345()))
return -ENODEV;
ret = register_shared();
if (ret)
return ret;
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
dpd->dma_chan_en_mask = ENETDMAC_CHANCFG_EN_MASK;
dpd->dma_chan_int_mask = ENETDMAC_IR_PKTDONE_MASK;
if (BCMCPU_IS_6345()) {
dpd->dma_chan_en_mask |= ENETDMAC_CHANCFG_CHAINING_MASK;
dpd->dma_chan_en_mask |= ENETDMAC_CHANCFG_WRAP_EN_MASK;
dpd->dma_chan_en_mask |= ENETDMAC_CHANCFG_FLOWC_EN_MASK;
dpd->dma_chan_int_mask |= ENETDMA_IR_BUFDONE_MASK;
dpd->dma_chan_int_mask |= ENETDMA_IR_NOTOWNER_MASK;
dpd->dma_chan_width = ENETDMA_6345_CHAN_WIDTH;
dpd->dma_desc_shift = ENETDMA_6345_DESC_SHIFT;
} else {
dpd->dma_has_sram = true;
dpd->dma_chan_width = ENETDMA_CHAN_WIDTH;
}
ret = platform_device_register(pdev);
if (ret)
return ret;
return 0;
}
int __init
bcm63xx_enetsw_register(const struct bcm63xx_enetsw_platform_data *pd)
{
int ret;
if (!BCMCPU_IS_6328() && !BCMCPU_IS_6362() && !BCMCPU_IS_6368())
return -ENODEV;
ret = register_shared();
if (ret)
return ret;
enetsw_res[0].start = bcm63xx_regset_address(RSET_ENETSW);
enetsw_res[0].end = enetsw_res[0].start;
enetsw_res[0].end += RSET_ENETSW_SIZE - 1;
enetsw_res[1].start = bcm63xx_get_irq_number(IRQ_ENETSW_RXDMA0);
enetsw_res[2].start = bcm63xx_get_irq_number(IRQ_ENETSW_TXDMA0);
if (!enetsw_res[2].start)
enetsw_res[2].start = -1;
memcpy(bcm63xx_enetsw_device.dev.platform_data, pd, sizeof(*pd));
if (BCMCPU_IS_6328())
enetsw_pd.num_ports = ENETSW_PORTS_6328;
else if (BCMCPU_IS_6362() || BCMCPU_IS_6368())
enetsw_pd.num_ports = ENETSW_PORTS_6368;
enetsw_pd.dma_has_sram = true;
enetsw_pd.dma_chan_width = ENETDMA_CHAN_WIDTH;
enetsw_pd.dma_chan_en_mask = ENETDMAC_CHANCFG_EN_MASK;
enetsw_pd.dma_chan_int_mask = ENETDMAC_IR_PKTDONE_MASK;
ret = platform_device_register(&bcm63xx_enetsw_device);
if (ret)
return ret;
return 0;
}
