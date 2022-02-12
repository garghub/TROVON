static void dwmac100_core_init(struct mac_device_info *hw, int mtu)
{
void __iomem *ioaddr = hw->pcsr;
u32 value = readl(ioaddr + MAC_CONTROL);
writel((value | MAC_CORE_INIT), ioaddr + MAC_CONTROL);
#ifdef STMMAC_VLAN_TAG_USED
writel(ETH_P_8021Q, ioaddr + MAC_VLAN1);
#endif
}
static void dwmac100_dump_mac_regs(struct mac_device_info *hw)
{
void __iomem *ioaddr = hw->pcsr;
pr_info("\t----------------------------------------------\n"
"\t DWMAC 100 CSR (base addr = 0x%p)\n"
"\t----------------------------------------------\n", ioaddr);
pr_info("\tcontrol reg (offset 0x%x): 0x%08x\n", MAC_CONTROL,
readl(ioaddr + MAC_CONTROL));
pr_info("\taddr HI (offset 0x%x): 0x%08x\n ", MAC_ADDR_HIGH,
readl(ioaddr + MAC_ADDR_HIGH));
pr_info("\taddr LO (offset 0x%x): 0x%08x\n", MAC_ADDR_LOW,
readl(ioaddr + MAC_ADDR_LOW));
pr_info("\tmulticast hash HI (offset 0x%x): 0x%08x\n",
MAC_HASH_HIGH, readl(ioaddr + MAC_HASH_HIGH));
pr_info("\tmulticast hash LO (offset 0x%x): 0x%08x\n",
MAC_HASH_LOW, readl(ioaddr + MAC_HASH_LOW));
pr_info("\tflow control (offset 0x%x): 0x%08x\n",
MAC_FLOW_CTRL, readl(ioaddr + MAC_FLOW_CTRL));
pr_info("\tVLAN1 tag (offset 0x%x): 0x%08x\n", MAC_VLAN1,
readl(ioaddr + MAC_VLAN1));
pr_info("\tVLAN2 tag (offset 0x%x): 0x%08x\n", MAC_VLAN2,
readl(ioaddr + MAC_VLAN2));
}
static int dwmac100_rx_ipc_enable(struct mac_device_info *hw)
{
return 0;
}
static int dwmac100_irq_status(struct mac_device_info *hw,
struct stmmac_extra_stats *x)
{
return 0;
}
static void dwmac100_set_umac_addr(struct mac_device_info *hw,
unsigned char *addr,
unsigned int reg_n)
{
void __iomem *ioaddr = hw->pcsr;
stmmac_set_mac_addr(ioaddr, addr, MAC_ADDR_HIGH, MAC_ADDR_LOW);
}
static void dwmac100_get_umac_addr(struct mac_device_info *hw,
unsigned char *addr,
unsigned int reg_n)
{
void __iomem *ioaddr = hw->pcsr;
stmmac_get_mac_addr(ioaddr, addr, MAC_ADDR_HIGH, MAC_ADDR_LOW);
}
static void dwmac100_set_filter(struct mac_device_info *hw,
struct net_device *dev)
{
void __iomem *ioaddr = (void __iomem *)dev->base_addr;
u32 value = readl(ioaddr + MAC_CONTROL);
if (dev->flags & IFF_PROMISC) {
value |= MAC_CONTROL_PR;
value &= ~(MAC_CONTROL_PM | MAC_CONTROL_IF | MAC_CONTROL_HO |
MAC_CONTROL_HP);
} else if ((netdev_mc_count(dev) > HASH_TABLE_SIZE)
|| (dev->flags & IFF_ALLMULTI)) {
value |= MAC_CONTROL_PM;
value &= ~(MAC_CONTROL_PR | MAC_CONTROL_IF | MAC_CONTROL_HO);
writel(0xffffffff, ioaddr + MAC_HASH_HIGH);
writel(0xffffffff, ioaddr + MAC_HASH_LOW);
} else if (netdev_mc_empty(dev)) {
value &= ~(MAC_CONTROL_PM | MAC_CONTROL_PR | MAC_CONTROL_IF |
MAC_CONTROL_HO | MAC_CONTROL_HP);
} else {
u32 mc_filter[2];
struct netdev_hw_addr *ha;
value |= MAC_CONTROL_HP;
value &= ~(MAC_CONTROL_PM | MAC_CONTROL_PR |
MAC_CONTROL_IF | MAC_CONTROL_HO);
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
}
writel(mc_filter[0], ioaddr + MAC_HASH_LOW);
writel(mc_filter[1], ioaddr + MAC_HASH_HIGH);
}
writel(value, ioaddr + MAC_CONTROL);
}
static void dwmac100_flow_ctrl(struct mac_device_info *hw, unsigned int duplex,
unsigned int fc, unsigned int pause_time)
{
void __iomem *ioaddr = hw->pcsr;
unsigned int flow = MAC_FLOW_CTRL_ENABLE;
if (duplex)
flow |= (pause_time << MAC_FLOW_CTRL_PT_SHIFT);
writel(flow, ioaddr + MAC_FLOW_CTRL);
}
static void dwmac100_pmt(struct mac_device_info *hw, unsigned long mode)
{
return;
}
struct mac_device_info *dwmac100_setup(void __iomem *ioaddr, int *synopsys_id)
{
struct mac_device_info *mac;
mac = kzalloc(sizeof(const struct mac_device_info), GFP_KERNEL);
if (!mac)
return NULL;
pr_info("\tDWMAC100\n");
mac->pcsr = ioaddr;
mac->mac = &dwmac100_ops;
mac->dma = &dwmac100_dma_ops;
mac->link.port = MAC_CONTROL_PS;
mac->link.duplex = MAC_CONTROL_F;
mac->link.speed = 0;
mac->mii.addr = MAC_MII_ADDR;
mac->mii.data = MAC_MII_DATA;
mac->mii.addr_shift = 11;
mac->mii.addr_mask = 0x0000F800;
mac->mii.reg_shift = 6;
mac->mii.reg_mask = 0x000007C0;
mac->mii.clk_csr_shift = 2;
mac->mii.clk_csr_mask = GENMASK(5, 2);
*synopsys_id = 0;
return mac;
}
