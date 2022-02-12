static int dwmac100_dma_init(void __iomem *ioaddr, int pbl, int fb, int mb,
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
writel(DMA_BUS_MODE_DEFAULT | (pbl << DMA_BUS_MODE_PBL_SHIFT),
ioaddr + DMA_BUS_MODE);
writel(DMA_INTR_DEFAULT_MASK, ioaddr + DMA_INTR_ENA);
writel(dma_tx, ioaddr + DMA_TX_BASE_ADDR);
writel(dma_rx, ioaddr + DMA_RCV_BASE_ADDR);
return 0;
}
static void dwmac100_dma_operation_mode(void __iomem *ioaddr, int txmode,
int rxmode)
{
u32 csr6 = readl(ioaddr + DMA_CONTROL);
if (txmode <= 32)
csr6 |= DMA_CONTROL_TTC_32;
else if (txmode <= 64)
csr6 |= DMA_CONTROL_TTC_64;
else
csr6 |= DMA_CONTROL_TTC_128;
writel(csr6, ioaddr + DMA_CONTROL);
}
static void dwmac100_dump_dma_regs(void __iomem *ioaddr)
{
int i;
pr_debug("DWMAC 100 DMA CSR\n");
for (i = 0; i < 9; i++)
pr_debug("\t CSR%d (offset 0x%x): 0x%08x\n", i,
(DMA_BUS_MODE + i * 4),
readl(ioaddr + DMA_BUS_MODE + i * 4));
pr_debug("\tCSR20 (0x%x): 0x%08x, CSR21 (0x%x): 0x%08x\n",
DMA_CUR_TX_BUF_ADDR, readl(ioaddr + DMA_CUR_TX_BUF_ADDR),
DMA_CUR_RX_BUF_ADDR, readl(ioaddr + DMA_CUR_RX_BUF_ADDR));
}
static void dwmac100_dma_diagnostic_fr(void *data, struct stmmac_extra_stats *x,
void __iomem *ioaddr)
{
struct net_device_stats *stats = (struct net_device_stats *)data;
u32 csr8 = readl(ioaddr + DMA_MISSED_FRAME_CTR);
if (unlikely(csr8)) {
if (csr8 & DMA_MISSED_FRAME_OVE) {
stats->rx_over_errors += 0x800;
x->rx_overflow_cntr += 0x800;
} else {
unsigned int ove_cntr;
ove_cntr = ((csr8 & DMA_MISSED_FRAME_OVE_CNTR) >> 17);
stats->rx_over_errors += ove_cntr;
x->rx_overflow_cntr += ove_cntr;
}
if (csr8 & DMA_MISSED_FRAME_OVE_M) {
stats->rx_missed_errors += 0xffff;
x->rx_missed_cntr += 0xffff;
} else {
unsigned int miss_f = (csr8 & DMA_MISSED_FRAME_M_CNTR);
stats->rx_missed_errors += miss_f;
x->rx_missed_cntr += miss_f;
}
}
}
