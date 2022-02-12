static int dwmac1000_dma_init(void __iomem *ioaddr, int pbl, int fb, int mb,
int burst_len, u32 dma_tx, u32 dma_rx, int atds)
{
u32 value = readl(ioaddr + DMA_BUS_MODE);
int limit;
value |= DMA_BUS_MODE_SFT_RESET;
writel(value, ioaddr + DMA_BUS_MODE);
limit = 10;
while (limit--) {
if (!(readl(ioaddr + DMA_BUS_MODE) & DMA_BUS_MODE_SFT_RESET))
break;
mdelay(10);
}
if (limit < 0)
return -EBUSY;
value = DMA_BUS_MODE_PBL | ((pbl << DMA_BUS_MODE_PBL_SHIFT) |
(pbl << DMA_BUS_MODE_RPBL_SHIFT));
if (fb)
value |= DMA_BUS_MODE_FB;
if (mb)
value |= DMA_BUS_MODE_MB;
#ifdef CONFIG_STMMAC_DA
value |= DMA_BUS_MODE_DA;
#endif
if (atds)
value |= DMA_BUS_MODE_ATDS;
writel(value, ioaddr + DMA_BUS_MODE);
writel(burst_len, ioaddr + DMA_AXI_BUS_MODE);
writel(DMA_INTR_DEFAULT_MASK, ioaddr + DMA_INTR_ENA);
writel(dma_tx, ioaddr + DMA_TX_BASE_ADDR);
writel(dma_rx, ioaddr + DMA_RCV_BASE_ADDR);
return 0;
}
static void dwmac1000_dma_operation_mode(void __iomem *ioaddr, int txmode,
int rxmode)
{
u32 csr6 = readl(ioaddr + DMA_CONTROL);
if (txmode == SF_DMA_MODE) {
pr_debug("GMAC: enable TX store and forward mode\n");
csr6 |= DMA_CONTROL_TSF;
csr6 |= DMA_CONTROL_OSF;
} else {
pr_debug("GMAC: disabling TX SF (threshold %d)\n", txmode);
csr6 &= ~DMA_CONTROL_TSF;
csr6 &= DMA_CONTROL_TC_TX_MASK;
if (txmode <= 32)
csr6 |= DMA_CONTROL_TTC_32;
else if (txmode <= 64)
csr6 |= DMA_CONTROL_TTC_64;
else if (txmode <= 128)
csr6 |= DMA_CONTROL_TTC_128;
else if (txmode <= 192)
csr6 |= DMA_CONTROL_TTC_192;
else
csr6 |= DMA_CONTROL_TTC_256;
}
if (rxmode == SF_DMA_MODE) {
pr_debug("GMAC: enable RX store and forward mode\n");
csr6 |= DMA_CONTROL_RSF;
} else {
pr_debug("GMAC: disable RX SF mode (threshold %d)\n", rxmode);
csr6 &= ~DMA_CONTROL_RSF;
csr6 &= DMA_CONTROL_TC_RX_MASK;
if (rxmode <= 32)
csr6 |= DMA_CONTROL_RTC_32;
else if (rxmode <= 64)
csr6 |= DMA_CONTROL_RTC_64;
else if (rxmode <= 96)
csr6 |= DMA_CONTROL_RTC_96;
else
csr6 |= DMA_CONTROL_RTC_128;
}
writel(csr6, ioaddr + DMA_CONTROL);
}
static void dwmac1000_dump_dma_regs(void __iomem *ioaddr)
{
int i;
pr_info(" DMA registers\n");
for (i = 0; i < 22; i++) {
if ((i < 9) || (i > 17)) {
int offset = i * 4;
pr_err("\t Reg No. %d (offset 0x%x): 0x%08x\n", i,
(DMA_BUS_MODE + offset),
readl(ioaddr + DMA_BUS_MODE + offset));
}
}
}
static unsigned int dwmac1000_get_hw_feature(void __iomem *ioaddr)
{
return readl(ioaddr + DMA_HW_FEATURE);
}
static void dwmac1000_rx_watchdog(void __iomem *ioaddr, u32 riwt)
{
writel(riwt, ioaddr + DMA_RX_WATCHDOG);
}
