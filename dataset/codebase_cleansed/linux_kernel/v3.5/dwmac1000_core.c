static void dwmac1000_core_init(void __iomem *ioaddr)
{
u32 value = readl(ioaddr + GMAC_CONTROL);
value |= GMAC_CORE_INIT;
writel(value, ioaddr + GMAC_CONTROL);
writel(0x207, ioaddr + GMAC_INT_MASK);
#ifdef STMMAC_VLAN_TAG_USED
writel(0x0, ioaddr + GMAC_VLAN_TAG);
#endif
}
static int dwmac1000_rx_ipc_enable(void __iomem *ioaddr)
{
u32 value = readl(ioaddr + GMAC_CONTROL);
value |= GMAC_CONTROL_IPC;
writel(value, ioaddr + GMAC_CONTROL);
value = readl(ioaddr + GMAC_CONTROL);
return !!(value & GMAC_CONTROL_IPC);
}
static void dwmac1000_dump_regs(void __iomem *ioaddr)
{
int i;
pr_info("\tDWMAC1000 regs (base addr = 0x%p)\n", ioaddr);
for (i = 0; i < 55; i++) {
int offset = i * 4;
pr_info("\tReg No. %d (offset 0x%x): 0x%08x\n", i,
offset, readl(ioaddr + offset));
}
}
static void dwmac1000_set_umac_addr(void __iomem *ioaddr, unsigned char *addr,
unsigned int reg_n)
{
stmmac_set_mac_addr(ioaddr, addr, GMAC_ADDR_HIGH(reg_n),
GMAC_ADDR_LOW(reg_n));
}
static void dwmac1000_get_umac_addr(void __iomem *ioaddr, unsigned char *addr,
unsigned int reg_n)
{
stmmac_get_mac_addr(ioaddr, addr, GMAC_ADDR_HIGH(reg_n),
GMAC_ADDR_LOW(reg_n));
}
static void dwmac1000_set_filter(struct net_device *dev, int id)
{
void __iomem *ioaddr = (void __iomem *) dev->base_addr;
unsigned int value = 0;
unsigned int perfect_addr_number;
CHIP_DBG(KERN_INFO "%s: # mcasts %d, # unicast %d\n",
__func__, netdev_mc_count(dev), netdev_uc_count(dev));
if (dev->flags & IFF_PROMISC)
value = GMAC_FRAME_FILTER_PR;
else if ((netdev_mc_count(dev) > HASH_TABLE_SIZE)
|| (dev->flags & IFF_ALLMULTI)) {
value = GMAC_FRAME_FILTER_PM;
writel(0xffffffff, ioaddr + GMAC_HASH_HIGH);
writel(0xffffffff, ioaddr + GMAC_HASH_LOW);
} else if (!netdev_mc_empty(dev)) {
u32 mc_filter[2];
struct netdev_hw_addr *ha;
value = GMAC_FRAME_FILTER_HMC;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int bit_nr =
bitrev32(~crc32_le(~0, ha->addr, 6)) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
}
writel(mc_filter[0], ioaddr + GMAC_HASH_LOW);
writel(mc_filter[1], ioaddr + GMAC_HASH_HIGH);
}
if (id > DWMAC_CORE_3_40)
perfect_addr_number = GMAC_MAX_PERFECT_ADDRESSES;
else
perfect_addr_number = GMAC_MAX_PERFECT_ADDRESSES / 2;
if (netdev_uc_count(dev) > perfect_addr_number)
value |= GMAC_FRAME_FILTER_PR;
else {
int reg = 1;
struct netdev_hw_addr *ha;
netdev_for_each_uc_addr(ha, dev) {
dwmac1000_set_umac_addr(ioaddr, ha->addr, reg);
reg++;
}
}
#ifdef FRAME_FILTER_DEBUG
value |= GMAC_FRAME_FILTER_RA;
#endif
writel(value, ioaddr + GMAC_FRAME_FILTER);
CHIP_DBG(KERN_INFO "\tFrame Filter reg: 0x%08x\n\tHash regs: "
"HI 0x%08x, LO 0x%08x\n", readl(ioaddr + GMAC_FRAME_FILTER),
readl(ioaddr + GMAC_HASH_HIGH), readl(ioaddr + GMAC_HASH_LOW));
}
static void dwmac1000_flow_ctrl(void __iomem *ioaddr, unsigned int duplex,
unsigned int fc, unsigned int pause_time)
{
unsigned int flow = 0;
CHIP_DBG(KERN_DEBUG "GMAC Flow-Control:\n");
if (fc & FLOW_RX) {
CHIP_DBG(KERN_DEBUG "\tReceive Flow-Control ON\n");
flow |= GMAC_FLOW_CTRL_RFE;
}
if (fc & FLOW_TX) {
CHIP_DBG(KERN_DEBUG "\tTransmit Flow-Control ON\n");
flow |= GMAC_FLOW_CTRL_TFE;
}
if (duplex) {
CHIP_DBG(KERN_DEBUG "\tduplex mode: PAUSE %d\n", pause_time);
flow |= (pause_time << GMAC_FLOW_CTRL_PT_SHIFT);
}
writel(flow, ioaddr + GMAC_FLOW_CTRL);
}
static void dwmac1000_pmt(void __iomem *ioaddr, unsigned long mode)
{
unsigned int pmt = 0;
if (mode & WAKE_MAGIC) {
CHIP_DBG(KERN_DEBUG "GMAC: WOL Magic frame\n");
pmt |= power_down | magic_pkt_en;
}
if (mode & WAKE_UCAST) {
CHIP_DBG(KERN_DEBUG "GMAC: WOL on global unicast\n");
pmt |= global_unicast;
}
writel(pmt, ioaddr + GMAC_PMT);
}
static void dwmac1000_irq_status(void __iomem *ioaddr)
{
u32 intr_status = readl(ioaddr + GMAC_INT_STATUS);
if ((intr_status & mmc_tx_irq))
CHIP_DBG(KERN_DEBUG "GMAC: MMC tx interrupt: 0x%08x\n",
readl(ioaddr + GMAC_MMC_TX_INTR));
if (unlikely(intr_status & mmc_rx_irq))
CHIP_DBG(KERN_DEBUG "GMAC: MMC rx interrupt: 0x%08x\n",
readl(ioaddr + GMAC_MMC_RX_INTR));
if (unlikely(intr_status & mmc_rx_csum_offload_irq))
CHIP_DBG(KERN_DEBUG "GMAC: MMC rx csum offload: 0x%08x\n",
readl(ioaddr + GMAC_MMC_RX_CSUM_OFFLOAD));
if (unlikely(intr_status & pmt_irq)) {
CHIP_DBG(KERN_DEBUG "GMAC: received Magic frame\n");
readl(ioaddr + GMAC_PMT);
}
}
struct mac_device_info *dwmac1000_setup(void __iomem *ioaddr)
{
struct mac_device_info *mac;
u32 hwid = readl(ioaddr + GMAC_VERSION);
mac = kzalloc(sizeof(const struct mac_device_info), GFP_KERNEL);
if (!mac)
return NULL;
mac->mac = &dwmac1000_ops;
mac->dma = &dwmac1000_dma_ops;
mac->link.port = GMAC_CONTROL_PS;
mac->link.duplex = GMAC_CONTROL_DM;
mac->link.speed = GMAC_CONTROL_FES;
mac->mii.addr = GMAC_MII_ADDR;
mac->mii.data = GMAC_MII_DATA;
mac->synopsys_uid = hwid;
return mac;
}
