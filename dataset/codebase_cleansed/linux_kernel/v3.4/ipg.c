static inline void __iomem *ipg_ioaddr(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
return sp->ioaddr;
}
static void ipg_dump_rfdlist(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int i;
u32 offset;
IPG_DEBUG_MSG("_dump_rfdlist\n");
netdev_info(dev, "rx_current = %02x\n", sp->rx_current);
netdev_info(dev, "rx_dirty = %02x\n", sp->rx_dirty);
netdev_info(dev, "RFDList start address = %016lx\n",
(unsigned long)sp->rxd_map);
netdev_info(dev, "RFDListPtr register = %08x%08x\n",
ipg_r32(IPG_RFDLISTPTR1), ipg_r32(IPG_RFDLISTPTR0));
for (i = 0; i < IPG_RFDLIST_LENGTH; i++) {
offset = (u32) &sp->rxd[i].next_desc - (u32) sp->rxd;
netdev_info(dev, "%02x %04x RFDNextPtr = %016lx\n",
i, offset, (unsigned long)sp->rxd[i].next_desc);
offset = (u32) &sp->rxd[i].rfs - (u32) sp->rxd;
netdev_info(dev, "%02x %04x RFS = %016lx\n",
i, offset, (unsigned long)sp->rxd[i].rfs);
offset = (u32) &sp->rxd[i].frag_info - (u32) sp->rxd;
netdev_info(dev, "%02x %04x frag_info = %016lx\n",
i, offset, (unsigned long)sp->rxd[i].frag_info);
}
}
static void ipg_dump_tfdlist(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int i;
u32 offset;
IPG_DEBUG_MSG("_dump_tfdlist\n");
netdev_info(dev, "tx_current = %02x\n", sp->tx_current);
netdev_info(dev, "tx_dirty = %02x\n", sp->tx_dirty);
netdev_info(dev, "TFDList start address = %016lx\n",
(unsigned long) sp->txd_map);
netdev_info(dev, "TFDListPtr register = %08x%08x\n",
ipg_r32(IPG_TFDLISTPTR1), ipg_r32(IPG_TFDLISTPTR0));
for (i = 0; i < IPG_TFDLIST_LENGTH; i++) {
offset = (u32) &sp->txd[i].next_desc - (u32) sp->txd;
netdev_info(dev, "%02x %04x TFDNextPtr = %016lx\n",
i, offset, (unsigned long)sp->txd[i].next_desc);
offset = (u32) &sp->txd[i].tfc - (u32) sp->txd;
netdev_info(dev, "%02x %04x TFC = %016lx\n",
i, offset, (unsigned long) sp->txd[i].tfc);
offset = (u32) &sp->txd[i].frag_info - (u32) sp->txd;
netdev_info(dev, "%02x %04x frag_info = %016lx\n",
i, offset, (unsigned long) sp->txd[i].frag_info);
}
}
static void ipg_write_phy_ctl(void __iomem *ioaddr, u8 data)
{
ipg_w8(IPG_PC_RSVD_MASK & data, PHY_CTRL);
ndelay(IPG_PC_PHYCTRLWAIT_NS);
}
static void ipg_drive_phy_ctl_low_high(void __iomem *ioaddr, u8 data)
{
ipg_write_phy_ctl(ioaddr, IPG_PC_MGMTCLK_LO | data);
ipg_write_phy_ctl(ioaddr, IPG_PC_MGMTCLK_HI | data);
}
static void send_three_state(void __iomem *ioaddr, u8 phyctrlpolarity)
{
phyctrlpolarity |= (IPG_PC_MGMTDATA & 0) | IPG_PC_MGMTDIR;
ipg_drive_phy_ctl_low_high(ioaddr, phyctrlpolarity);
}
static void send_end(void __iomem *ioaddr, u8 phyctrlpolarity)
{
ipg_w8((IPG_PC_MGMTCLK_LO | (IPG_PC_MGMTDATA & 0) | IPG_PC_MGMTDIR |
phyctrlpolarity) & IPG_PC_RSVD_MASK, PHY_CTRL);
}
static u16 read_phy_bit(void __iomem *ioaddr, u8 phyctrlpolarity)
{
u16 bit_data;
ipg_write_phy_ctl(ioaddr, IPG_PC_MGMTCLK_LO | phyctrlpolarity);
bit_data = ((ipg_r8(PHY_CTRL) & IPG_PC_MGMTDATA) >> 1) & 1;
ipg_write_phy_ctl(ioaddr, IPG_PC_MGMTCLK_HI | phyctrlpolarity);
return bit_data;
}
static int mdio_read(struct net_device *dev, int phy_id, int phy_reg)
{
void __iomem *ioaddr = ipg_ioaddr(dev);
struct {
u32 field;
unsigned int len;
} p[] = {
{ GMII_PREAMBLE, 32 },
{ GMII_ST, 2 },
{ GMII_READ, 2 },
{ phy_id, 5 },
{ phy_reg, 5 },
{ 0x0000, 2 },
{ 0x0000, 16 },
{ 0x0000, 1 }
};
unsigned int i, j;
u8 polarity, data;
polarity = ipg_r8(PHY_CTRL);
polarity &= (IPG_PC_DUPLEX_POLARITY | IPG_PC_LINK_POLARITY);
for (j = 0; j < 5; j++) {
for (i = 0; i < p[j].len; i++) {
data = (p[j].field >> (p[j].len - 1 - i)) << 1;
data &= IPG_PC_MGMTDATA;
data |= polarity | IPG_PC_MGMTDIR;
ipg_drive_phy_ctl_low_high(ioaddr, data);
}
}
send_three_state(ioaddr, polarity);
read_phy_bit(ioaddr, polarity);
for (i = 0; i < p[6].len; i++) {
p[6].field |=
(read_phy_bit(ioaddr, polarity) << (p[6].len - 1 - i));
}
send_three_state(ioaddr, polarity);
send_three_state(ioaddr, polarity);
send_three_state(ioaddr, polarity);
send_end(ioaddr, polarity);
return p[6].field;
}
static void mdio_write(struct net_device *dev, int phy_id, int phy_reg, int val)
{
void __iomem *ioaddr = ipg_ioaddr(dev);
struct {
u32 field;
unsigned int len;
} p[] = {
{ GMII_PREAMBLE, 32 },
{ GMII_ST, 2 },
{ GMII_WRITE, 2 },
{ phy_id, 5 },
{ phy_reg, 5 },
{ 0x0002, 2 },
{ val & 0xffff, 16 },
{ 0x0000, 1 }
};
unsigned int i, j;
u8 polarity, data;
polarity = ipg_r8(PHY_CTRL);
polarity &= (IPG_PC_DUPLEX_POLARITY | IPG_PC_LINK_POLARITY);
for (j = 0; j < 7; j++) {
for (i = 0; i < p[j].len; i++) {
data = (p[j].field >> (p[j].len - 1 - i)) << 1;
data &= IPG_PC_MGMTDATA;
data |= polarity | IPG_PC_MGMTDIR;
ipg_drive_phy_ctl_low_high(ioaddr, data);
}
}
ipg_write_phy_ctl(ioaddr, IPG_PC_MGMTCLK_LO | polarity);
ipg_r8(PHY_CTRL);
ipg_write_phy_ctl(ioaddr, IPG_PC_MGMTCLK_HI | polarity);
}
static void ipg_set_led_mode(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
u32 mode;
mode = ipg_r32(ASIC_CTRL);
mode &= ~(IPG_AC_LED_MODE_BIT_1 | IPG_AC_LED_MODE | IPG_AC_LED_SPEED);
if ((sp->led_mode & 0x03) > 1)
mode |= IPG_AC_LED_MODE_BIT_1;
if ((sp->led_mode & 0x01) == 1)
mode |= IPG_AC_LED_MODE;
if ((sp->led_mode & 0x08) == 8)
mode |= IPG_AC_LED_SPEED;
ipg_w32(mode, ASIC_CTRL);
}
static void ipg_set_phy_set(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
int physet;
physet = ipg_r8(PHY_SET);
physet &= ~(IPG_PS_MEM_LENB9B | IPG_PS_MEM_LEN9 | IPG_PS_NON_COMPDET);
physet |= ((sp->led_mode & 0x70) >> 4);
ipg_w8(physet, PHY_SET);
}
static int ipg_reset(struct net_device *dev, u32 resetflags)
{
void __iomem *ioaddr = ipg_ioaddr(dev);
unsigned int timeout_count = 0;
IPG_DEBUG_MSG("_reset\n");
ipg_w32(ipg_r32(ASIC_CTRL) | resetflags, ASIC_CTRL);
mdelay(IPG_AC_RESETWAIT);
while (IPG_AC_RESET_BUSY & ipg_r32(ASIC_CTRL)) {
mdelay(IPG_AC_RESETWAIT);
if (++timeout_count > IPG_AC_RESET_TIMEOUT)
return -ETIME;
}
ipg_set_led_mode(dev);
ipg_set_phy_set(dev);
return 0;
}
static int ipg_find_phyaddr(struct net_device *dev)
{
unsigned int phyaddr, i;
for (i = 0; i < 32; i++) {
u32 status;
phyaddr = (IPG_NIC_PHY_ADDRESS + i) % 32;
status = mdio_read(dev, phyaddr, MII_BMSR);
if ((status != 0xFFFF) && (status != 0))
return phyaddr;
}
return 0x1f;
}
static int ipg_config_autoneg(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int txflowcontrol;
unsigned int rxflowcontrol;
unsigned int fullduplex;
u32 mac_ctrl_val;
u32 asicctrl;
u8 phyctrl;
const char *speed;
const char *duplex;
const char *tx_desc;
const char *rx_desc;
IPG_DEBUG_MSG("_config_autoneg\n");
asicctrl = ipg_r32(ASIC_CTRL);
phyctrl = ipg_r8(PHY_CTRL);
mac_ctrl_val = ipg_r32(MAC_CTRL);
fullduplex = 0;
txflowcontrol = 0;
rxflowcontrol = 0;
sp->tenmbpsmode = 0;
switch (phyctrl & IPG_PC_LINK_SPEED) {
case IPG_PC_LINK_SPEED_10MBPS:
speed = "10Mbps";
sp->tenmbpsmode = 1;
break;
case IPG_PC_LINK_SPEED_100MBPS:
speed = "100Mbps";
break;
case IPG_PC_LINK_SPEED_1000MBPS:
speed = "1000Mbps";
break;
default:
speed = "undefined!";
return 0;
}
netdev_info(dev, "Link speed = %s\n", speed);
if (sp->tenmbpsmode == 1)
netdev_info(dev, "10Mbps operational mode enabled\n");
if (phyctrl & IPG_PC_DUPLEX_STATUS) {
fullduplex = 1;
txflowcontrol = 1;
rxflowcontrol = 1;
}
if (fullduplex == 1) {
duplex = "full";
mac_ctrl_val |= IPG_MC_DUPLEX_SELECT_FD;
if (txflowcontrol == 1) {
tx_desc = "";
mac_ctrl_val |= IPG_MC_TX_FLOW_CONTROL_ENABLE;
} else {
tx_desc = "no ";
mac_ctrl_val &= ~IPG_MC_TX_FLOW_CONTROL_ENABLE;
}
if (rxflowcontrol == 1) {
rx_desc = "";
mac_ctrl_val |= IPG_MC_RX_FLOW_CONTROL_ENABLE;
} else {
rx_desc = "no ";
mac_ctrl_val &= ~IPG_MC_RX_FLOW_CONTROL_ENABLE;
}
} else {
duplex = "half";
tx_desc = "no ";
rx_desc = "no ";
mac_ctrl_val &= (~IPG_MC_DUPLEX_SELECT_FD &
~IPG_MC_TX_FLOW_CONTROL_ENABLE &
~IPG_MC_RX_FLOW_CONTROL_ENABLE);
}
netdev_info(dev, "setting %s duplex, %sTX, %sRX flow control\n",
duplex, tx_desc, rx_desc);
ipg_w32(mac_ctrl_val, MAC_CTRL);
return 0;
}
static void ipg_nic_set_multicast_list(struct net_device *dev)
{
void __iomem *ioaddr = ipg_ioaddr(dev);
struct netdev_hw_addr *ha;
unsigned int hashindex;
u32 hashtable[2];
u8 receivemode;
IPG_DEBUG_MSG("_nic_set_multicast_list\n");
receivemode = IPG_RM_RECEIVEUNICAST | IPG_RM_RECEIVEBROADCAST;
if (dev->flags & IFF_PROMISC) {
receivemode = IPG_RM_RECEIVEALLFRAMES;
} else if ((dev->flags & IFF_ALLMULTI) ||
((dev->flags & IFF_MULTICAST) &&
(netdev_mc_count(dev) > IPG_MULTICAST_HASHTABLE_SIZE))) {
receivemode |= IPG_RM_RECEIVEMULTICAST;
} else if ((dev->flags & IFF_MULTICAST) && !netdev_mc_empty(dev)) {
receivemode |= IPG_RM_RECEIVEMULTICASTHASH;
}
hashtable[0] = 0x00000000;
hashtable[1] = 0x00000000;
netdev_for_each_mc_addr(ha, dev) {
hashindex = crc32_le(0xffffffff, ha->addr,
ETH_ALEN);
hashindex = hashindex & 0x3F;
set_bit(hashindex, (void *)hashtable);
}
ipg_w32(hashtable[0], HASHTABLE_0);
ipg_w32(hashtable[1], HASHTABLE_1);
ipg_w8(IPG_RM_RSVD_MASK & receivemode, RECEIVE_MODE);
IPG_DEBUG_MSG("ReceiveMode = %x\n", ipg_r8(RECEIVE_MODE));
}
static int ipg_io_config(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = ipg_ioaddr(dev);
u32 origmacctrl;
u32 restoremacctrl;
IPG_DEBUG_MSG("_io_config\n");
origmacctrl = ipg_r32(MAC_CTRL);
restoremacctrl = origmacctrl | IPG_MC_STATISTICS_ENABLE;
if (!IPG_STRIP_FCS_ON_RX)
restoremacctrl |= IPG_MC_RCV_FCS;
if (origmacctrl & IPG_MC_TX_ENABLED)
restoremacctrl |= IPG_MC_TX_ENABLE;
if (origmacctrl & IPG_MC_RX_ENABLED)
restoremacctrl |= IPG_MC_RX_ENABLE;
ipg_w32((origmacctrl & (IPG_MC_RX_DISABLE | IPG_MC_TX_DISABLE)) &
IPG_MC_RSVD_MASK, MAC_CTRL);
ipg_w32((origmacctrl & IPG_MC_IFS_96BIT) & IPG_MC_RSVD_MASK, MAC_CTRL);
ipg_nic_set_multicast_list(dev);
ipg_w16(sp->max_rxframe_size, MAX_FRAME_SIZE);
ipg_w8(IPG_RXDMAPOLLPERIOD_VALUE, RX_DMA_POLL_PERIOD);
ipg_w8(IPG_RXDMAURGENTTHRESH_VALUE, RX_DMA_URGENT_THRESH);
ipg_w8(IPG_RXDMABURSTTHRESH_VALUE, RX_DMA_BURST_THRESH);
ipg_w8(IPG_TXDMAPOLLPERIOD_VALUE, TX_DMA_POLL_PERIOD);
ipg_w8(IPG_TXDMAURGENTTHRESH_VALUE, TX_DMA_URGENT_THRESH);
ipg_w8(IPG_TXDMABURSTTHRESH_VALUE, TX_DMA_BURST_THRESH);
ipg_w16((IPG_IE_HOST_ERROR | IPG_IE_TX_DMA_COMPLETE |
IPG_IE_TX_COMPLETE | IPG_IE_INT_REQUESTED |
IPG_IE_UPDATE_STATS | IPG_IE_LINK_EVENT |
IPG_IE_RX_DMA_COMPLETE | IPG_IE_RX_DMA_PRIORITY), INT_ENABLE);
ipg_w16(IPG_FLOWONTHRESH_VALUE, FLOW_ON_THRESH);
ipg_w16(IPG_FLOWOFFTHRESH_VALUE, FLOW_OFF_THRESH);
ipg_w16(ipg_r16(DEBUG_CTRL) | 0x0200, DEBUG_CTRL);
ipg_w16(ipg_r16(DEBUG_CTRL) | 0x0010, DEBUG_CTRL);
ipg_w16(ipg_r16(DEBUG_CTRL) | 0x0020, DEBUG_CTRL);
ipg_w32(IPG_MC_RSVD_MASK & restoremacctrl, MAC_CTRL);
ipg_w32(IPG_RZ_ALL, RMON_STATISTICS_MASK);
ipg_w32(IPG_SM_MACCONTROLFRAMESXMTD | IPG_SM_MACCONTROLFRAMESRCVD |
IPG_SM_BCSTOCTETXMTOK_BCSTFRAMESXMTDOK | IPG_SM_TXJUMBOFRAMES |
IPG_SM_MCSTOCTETXMTOK_MCSTFRAMESXMTDOK | IPG_SM_RXJUMBOFRAMES |
IPG_SM_BCSTOCTETRCVDOK_BCSTFRAMESRCVDOK |
IPG_SM_UDPCHECKSUMERRORS | IPG_SM_TCPCHECKSUMERRORS |
IPG_SM_IPCHECKSUMERRORS, STATISTICS_MASK);
return 0;
}
static int ipg_get_rxbuff(struct net_device *dev, int entry)
{
struct ipg_nic_private *sp = netdev_priv(dev);
struct ipg_rx *rxfd = sp->rxd + entry;
struct sk_buff *skb;
u64 rxfragsize;
IPG_DEBUG_MSG("_get_rxbuff\n");
skb = netdev_alloc_skb_ip_align(dev, sp->rxsupport_size);
if (!skb) {
sp->rx_buff[entry] = NULL;
return -ENOMEM;
}
sp->rx_buff[entry] = skb;
rxfd->frag_info = cpu_to_le64(pci_map_single(sp->pdev, skb->data,
sp->rx_buf_sz, PCI_DMA_FROMDEVICE));
rxfragsize = sp->rxfrag_size;
rxfd->frag_info |= cpu_to_le64((rxfragsize << 48) & IPG_RFI_FRAGLEN);
return 0;
}
static int init_rfdlist(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int i;
IPG_DEBUG_MSG("_init_rfdlist\n");
for (i = 0; i < IPG_RFDLIST_LENGTH; i++) {
struct ipg_rx *rxfd = sp->rxd + i;
if (sp->rx_buff[i]) {
pci_unmap_single(sp->pdev,
le64_to_cpu(rxfd->frag_info) & ~IPG_RFI_FRAGLEN,
sp->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb_irq(sp->rx_buff[i]);
sp->rx_buff[i] = NULL;
}
rxfd->rfs = 0x0000000000000000;
if (ipg_get_rxbuff(dev, i) < 0) {
IPG_DEBUG_MSG("Cannot allocate Rx buffer\n");
if (i == 0) {
netdev_err(dev, "No memory available for RFD list\n");
return -ENOMEM;
}
}
rxfd->next_desc = cpu_to_le64(sp->rxd_map +
sizeof(struct ipg_rx)*(i + 1));
}
sp->rxd[i - 1].next_desc = cpu_to_le64(sp->rxd_map);
sp->rx_current = 0;
sp->rx_dirty = 0;
ipg_w32((u32) sp->rxd_map, RFD_LIST_PTR_0);
ipg_w32(0x00000000, RFD_LIST_PTR_1);
return 0;
}
static void init_tfdlist(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int i;
IPG_DEBUG_MSG("_init_tfdlist\n");
for (i = 0; i < IPG_TFDLIST_LENGTH; i++) {
struct ipg_tx *txfd = sp->txd + i;
txfd->tfc = cpu_to_le64(IPG_TFC_TFDDONE);
if (sp->tx_buff[i]) {
dev_kfree_skb_irq(sp->tx_buff[i]);
sp->tx_buff[i] = NULL;
}
txfd->next_desc = cpu_to_le64(sp->txd_map +
sizeof(struct ipg_tx)*(i + 1));
}
sp->txd[i - 1].next_desc = cpu_to_le64(sp->txd_map);
sp->tx_current = 0;
sp->tx_dirty = 0;
IPG_DDEBUG_MSG("Starting TFDListPtr = %08x\n",
(u32) sp->txd_map);
ipg_w32((u32) sp->txd_map, TFD_LIST_PTR_0);
ipg_w32(0x00000000, TFD_LIST_PTR_1);
sp->reset_current_tfd = 1;
}
static void ipg_nic_txfree(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
unsigned int released, pending, dirty;
IPG_DEBUG_MSG("_nic_txfree\n");
pending = sp->tx_current - sp->tx_dirty;
dirty = sp->tx_dirty % IPG_TFDLIST_LENGTH;
for (released = 0; released < pending; released++) {
struct sk_buff *skb = sp->tx_buff[dirty];
struct ipg_tx *txfd = sp->txd + dirty;
IPG_DEBUG_MSG("TFC = %016lx\n", (unsigned long) txfd->tfc);
if (!(txfd->tfc & cpu_to_le64(IPG_TFC_TFDDONE)))
break;
if (skb) {
pci_unmap_single(sp->pdev,
le64_to_cpu(txfd->frag_info) & ~IPG_TFI_FRAGLEN,
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
sp->tx_buff[dirty] = NULL;
}
dirty = (dirty + 1) % IPG_TFDLIST_LENGTH;
}
sp->tx_dirty += released;
if (netif_queue_stopped(dev) &&
(sp->tx_current != (sp->tx_dirty + IPG_TFDLIST_LENGTH))) {
netif_wake_queue(dev);
}
}
static void ipg_tx_timeout(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
ipg_reset(dev, IPG_AC_TX_RESET | IPG_AC_DMA | IPG_AC_NETWORK |
IPG_AC_FIFO);
spin_lock_irq(&sp->lock);
if (ipg_io_config(dev) < 0)
netdev_info(dev, "Error during re-configuration\n");
init_tfdlist(dev);
spin_unlock_irq(&sp->lock);
ipg_w32((ipg_r32(MAC_CTRL) | IPG_MC_TX_ENABLE) & IPG_MC_RSVD_MASK,
MAC_CTRL);
}
static void ipg_nic_txcleanup(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int i;
IPG_DEBUG_MSG("_nic_txcleanup\n");
for (i = 0; i < IPG_TFDLIST_LENGTH; i++) {
u32 txstatusdword = ipg_r32(TX_STATUS);
IPG_DEBUG_MSG("TxStatus = %08x\n", txstatusdword);
if (!(txstatusdword & IPG_TS_TX_COMPLETE))
break;
if (sp->tenmbpsmode) {
netif_wake_queue(dev);
}
if (txstatusdword & IPG_TS_TX_ERROR) {
IPG_DEBUG_MSG("Transmit error\n");
sp->stats.tx_errors++;
}
if (txstatusdword & IPG_TS_LATE_COLLISION) {
IPG_DEBUG_MSG("Late collision on transmit\n");
ipg_w32((ipg_r32(MAC_CTRL) | IPG_MC_TX_ENABLE) &
IPG_MC_RSVD_MASK, MAC_CTRL);
}
if (txstatusdword & IPG_TS_TX_MAX_COLL) {
IPG_DEBUG_MSG("Maximum collisions on transmit\n");
ipg_w32((ipg_r32(MAC_CTRL) | IPG_MC_TX_ENABLE) &
IPG_MC_RSVD_MASK, MAC_CTRL);
}
if (txstatusdword & IPG_TS_TX_UNDERRUN) {
IPG_DEBUG_MSG("Transmitter underrun\n");
sp->stats.tx_fifo_errors++;
ipg_reset(dev, IPG_AC_TX_RESET | IPG_AC_DMA |
IPG_AC_NETWORK | IPG_AC_FIFO);
if (ipg_io_config(dev) < 0) {
netdev_info(dev, "Error during re-configuration\n");
}
init_tfdlist(dev);
ipg_w32((ipg_r32(MAC_CTRL) | IPG_MC_TX_ENABLE) &
IPG_MC_RSVD_MASK, MAC_CTRL);
}
}
ipg_nic_txfree(dev);
}
static struct net_device_stats *ipg_nic_get_stats(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
u16 temp1;
u16 temp2;
IPG_DEBUG_MSG("_nic_get_stats\n");
if (!test_bit(__LINK_STATE_START, &dev->state))
return &sp->stats;
sp->stats.rx_packets += ipg_r32(IPG_FRAMESRCVDOK);
sp->stats.tx_packets += ipg_r32(IPG_FRAMESXMTDOK);
sp->stats.rx_bytes += ipg_r32(IPG_OCTETRCVOK);
sp->stats.tx_bytes += ipg_r32(IPG_OCTETXMTOK);
temp1 = ipg_r16(IPG_FRAMESLOSTRXERRORS);
sp->stats.rx_errors += temp1;
sp->stats.rx_missed_errors += temp1;
temp1 = ipg_r32(IPG_SINGLECOLFRAMES) + ipg_r32(IPG_MULTICOLFRAMES) +
ipg_r32(IPG_LATECOLLISIONS);
temp2 = ipg_r16(IPG_CARRIERSENSEERRORS);
sp->stats.collisions += temp1;
sp->stats.tx_dropped += ipg_r16(IPG_FRAMESABORTXSCOLLS);
sp->stats.tx_errors += ipg_r16(IPG_FRAMESWEXDEFERRAL) +
ipg_r32(IPG_FRAMESWDEFERREDXMT) + temp1 + temp2;
sp->stats.multicast += ipg_r32(IPG_MCSTOCTETRCVDOK);
sp->stats.tx_carrier_errors += temp2;
sp->stats.rx_length_errors += ipg_r16(IPG_INRANGELENGTHERRORS) +
ipg_r16(IPG_FRAMETOOLONGERRRORS);
sp->stats.rx_crc_errors += ipg_r16(IPG_FRAMECHECKSEQERRORS);
ipg_r32(IPG_MCSTFRAMESRCVDOK);
return &sp->stats;
}
static int ipg_nic_rxrestore(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
const unsigned int curr = sp->rx_current;
unsigned int dirty = sp->rx_dirty;
IPG_DEBUG_MSG("_nic_rxrestore\n");
for (dirty = sp->rx_dirty; curr - dirty > 0; dirty++) {
unsigned int entry = dirty % IPG_RFDLIST_LENGTH;
if (sp->rx_buff[entry])
continue;
if (ipg_get_rxbuff(dev, entry) < 0) {
IPG_DEBUG_MSG("Cannot allocate new Rx buffer\n");
break;
}
sp->rxd[entry].rfs = 0x0000000000000000;
}
sp->rx_dirty = dirty;
return 0;
}
static void ipg_nic_rx_free_skb(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
unsigned int entry = sp->rx_current % IPG_RFDLIST_LENGTH;
if (sp->rx_buff[entry]) {
struct ipg_rx *rxfd = sp->rxd + entry;
pci_unmap_single(sp->pdev,
le64_to_cpu(rxfd->frag_info) & ~IPG_RFI_FRAGLEN,
sp->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb_irq(sp->rx_buff[entry]);
sp->rx_buff[entry] = NULL;
}
}
static int ipg_nic_rx_check_frame_type(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
struct ipg_rx *rxfd = sp->rxd + (sp->rx_current % IPG_RFDLIST_LENGTH);
int type = FRAME_NO_START_NO_END;
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_FRAMESTART)
type += FRAME_WITH_START;
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_FRAMEEND)
type += FRAME_WITH_END;
return type;
}
static int ipg_nic_rx_check_error(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
unsigned int entry = sp->rx_current % IPG_RFDLIST_LENGTH;
struct ipg_rx *rxfd = sp->rxd + entry;
if (IPG_DROP_ON_RX_ETH_ERRORS && (le64_to_cpu(rxfd->rfs) &
(IPG_RFS_RXFIFOOVERRUN | IPG_RFS_RXRUNTFRAME |
IPG_RFS_RXALIGNMENTERROR | IPG_RFS_RXFCSERROR |
IPG_RFS_RXOVERSIZEDFRAME | IPG_RFS_RXLENGTHERROR))) {
IPG_DEBUG_MSG("Rx error, RFS = %016lx\n",
(unsigned long) rxfd->rfs);
sp->stats.rx_errors++;
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_RXFIFOOVERRUN) {
IPG_DEBUG_MSG("RX FIFO overrun occurred\n");
sp->stats.rx_fifo_errors++;
}
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_RXRUNTFRAME) {
IPG_DEBUG_MSG("RX runt occurred\n");
sp->stats.rx_length_errors++;
}
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_RXALIGNMENTERROR) {
IPG_DEBUG_MSG("RX alignment error occurred\n");
sp->stats.rx_frame_errors++;
}
if (sp->rx_buff[entry]) {
pci_unmap_single(sp->pdev,
le64_to_cpu(rxfd->frag_info) & ~IPG_RFI_FRAGLEN,
sp->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb_irq(sp->rx_buff[entry]);
sp->rx_buff[entry] = NULL;
}
return ERROR_PACKET;
}
return NORMAL_PACKET;
}
static void ipg_nic_rx_with_start_and_end(struct net_device *dev,
struct ipg_nic_private *sp,
struct ipg_rx *rxfd, unsigned entry)
{
struct ipg_jumbo *jumbo = &sp->jumbo;
struct sk_buff *skb;
int framelen;
if (jumbo->found_start) {
dev_kfree_skb_irq(jumbo->skb);
jumbo->found_start = 0;
jumbo->current_size = 0;
jumbo->skb = NULL;
}
if (ipg_nic_rx_check_error(dev) != NORMAL_PACKET)
return;
skb = sp->rx_buff[entry];
if (!skb)
return;
framelen = le64_to_cpu(rxfd->rfs) & IPG_RFS_RXFRAMELEN;
if (framelen > sp->rxfrag_size)
framelen = sp->rxfrag_size;
skb_put(skb, framelen);
skb->protocol = eth_type_trans(skb, dev);
skb_checksum_none_assert(skb);
netif_rx(skb);
sp->rx_buff[entry] = NULL;
}
static void ipg_nic_rx_with_start(struct net_device *dev,
struct ipg_nic_private *sp,
struct ipg_rx *rxfd, unsigned entry)
{
struct ipg_jumbo *jumbo = &sp->jumbo;
struct pci_dev *pdev = sp->pdev;
struct sk_buff *skb;
if (ipg_nic_rx_check_error(dev) != NORMAL_PACKET)
return;
skb = sp->rx_buff[entry];
if (!skb)
return;
if (jumbo->found_start)
dev_kfree_skb_irq(jumbo->skb);
pci_unmap_single(pdev, le64_to_cpu(rxfd->frag_info) & ~IPG_RFI_FRAGLEN,
sp->rx_buf_sz, PCI_DMA_FROMDEVICE);
skb_put(skb, sp->rxfrag_size);
jumbo->found_start = 1;
jumbo->current_size = sp->rxfrag_size;
jumbo->skb = skb;
sp->rx_buff[entry] = NULL;
}
static void ipg_nic_rx_with_end(struct net_device *dev,
struct ipg_nic_private *sp,
struct ipg_rx *rxfd, unsigned entry)
{
struct ipg_jumbo *jumbo = &sp->jumbo;
if (ipg_nic_rx_check_error(dev) == NORMAL_PACKET) {
struct sk_buff *skb = sp->rx_buff[entry];
if (!skb)
return;
if (jumbo->found_start) {
int framelen, endframelen;
framelen = le64_to_cpu(rxfd->rfs) & IPG_RFS_RXFRAMELEN;
endframelen = framelen - jumbo->current_size;
if (framelen > sp->rxsupport_size)
dev_kfree_skb_irq(jumbo->skb);
else {
memcpy(skb_put(jumbo->skb, endframelen),
skb->data, endframelen);
jumbo->skb->protocol =
eth_type_trans(jumbo->skb, dev);
skb_checksum_none_assert(jumbo->skb);
netif_rx(jumbo->skb);
}
}
jumbo->found_start = 0;
jumbo->current_size = 0;
jumbo->skb = NULL;
ipg_nic_rx_free_skb(dev);
} else {
dev_kfree_skb_irq(jumbo->skb);
jumbo->found_start = 0;
jumbo->current_size = 0;
jumbo->skb = NULL;
}
}
static void ipg_nic_rx_no_start_no_end(struct net_device *dev,
struct ipg_nic_private *sp,
struct ipg_rx *rxfd, unsigned entry)
{
struct ipg_jumbo *jumbo = &sp->jumbo;
if (ipg_nic_rx_check_error(dev) == NORMAL_PACKET) {
struct sk_buff *skb = sp->rx_buff[entry];
if (skb) {
if (jumbo->found_start) {
jumbo->current_size += sp->rxfrag_size;
if (jumbo->current_size <= sp->rxsupport_size) {
memcpy(skb_put(jumbo->skb,
sp->rxfrag_size),
skb->data, sp->rxfrag_size);
}
}
ipg_nic_rx_free_skb(dev);
}
} else {
dev_kfree_skb_irq(jumbo->skb);
jumbo->found_start = 0;
jumbo->current_size = 0;
jumbo->skb = NULL;
}
}
static int ipg_nic_rx_jumbo(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
unsigned int curr = sp->rx_current;
void __iomem *ioaddr = sp->ioaddr;
unsigned int i;
IPG_DEBUG_MSG("_nic_rx\n");
for (i = 0; i < IPG_MAXRFDPROCESS_COUNT; i++, curr++) {
unsigned int entry = curr % IPG_RFDLIST_LENGTH;
struct ipg_rx *rxfd = sp->rxd + entry;
if (!(rxfd->rfs & cpu_to_le64(IPG_RFS_RFDDONE)))
break;
switch (ipg_nic_rx_check_frame_type(dev)) {
case FRAME_WITH_START_WITH_END:
ipg_nic_rx_with_start_and_end(dev, sp, rxfd, entry);
break;
case FRAME_WITH_START:
ipg_nic_rx_with_start(dev, sp, rxfd, entry);
break;
case FRAME_WITH_END:
ipg_nic_rx_with_end(dev, sp, rxfd, entry);
break;
case FRAME_NO_START_NO_END:
ipg_nic_rx_no_start_no_end(dev, sp, rxfd, entry);
break;
}
}
sp->rx_current = curr;
if (i == IPG_MAXRFDPROCESS_COUNT) {
ipg_w32(ipg_r32(ASIC_CTRL) | IPG_AC_INT_REQUEST, ASIC_CTRL);
}
ipg_nic_rxrestore(dev);
return 0;
}
static int ipg_nic_rx(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
unsigned int curr = sp->rx_current;
void __iomem *ioaddr = sp->ioaddr;
struct ipg_rx *rxfd;
unsigned int i;
IPG_DEBUG_MSG("_nic_rx\n");
#define __RFS_MASK \
cpu_to_le64(IPG_RFS_RFDDONE | IPG_RFS_FRAMESTART | IPG_RFS_FRAMEEND)
for (i = 0; i < IPG_MAXRFDPROCESS_COUNT; i++, curr++) {
unsigned int entry = curr % IPG_RFDLIST_LENGTH;
struct sk_buff *skb = sp->rx_buff[entry];
unsigned int framelen;
rxfd = sp->rxd + entry;
if (((rxfd->rfs & __RFS_MASK) != __RFS_MASK) || !skb)
break;
framelen = le64_to_cpu(rxfd->rfs) & IPG_RFS_RXFRAMELEN;
if (framelen > sp->rxfrag_size) {
IPG_DEBUG_MSG
("RFS FrameLen > allocated fragment size\n");
framelen = sp->rxfrag_size;
}
if ((IPG_DROP_ON_RX_ETH_ERRORS && (le64_to_cpu(rxfd->rfs) &
(IPG_RFS_RXFIFOOVERRUN | IPG_RFS_RXRUNTFRAME |
IPG_RFS_RXALIGNMENTERROR | IPG_RFS_RXFCSERROR |
IPG_RFS_RXOVERSIZEDFRAME | IPG_RFS_RXLENGTHERROR)))) {
IPG_DEBUG_MSG("Rx error, RFS = %016lx\n",
(unsigned long int) rxfd->rfs);
sp->stats.rx_errors++;
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_RXFIFOOVERRUN) {
IPG_DEBUG_MSG("RX FIFO overrun occurred\n");
sp->stats.rx_fifo_errors++;
}
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_RXRUNTFRAME) {
IPG_DEBUG_MSG("RX runt occurred\n");
sp->stats.rx_length_errors++;
}
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_RXOVERSIZEDFRAME) ;
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_RXALIGNMENTERROR) {
IPG_DEBUG_MSG("RX alignment error occurred\n");
sp->stats.rx_frame_errors++;
}
if (le64_to_cpu(rxfd->rfs) & IPG_RFS_RXFCSERROR) ;
if (skb) {
__le64 info = rxfd->frag_info;
pci_unmap_single(sp->pdev,
le64_to_cpu(info) & ~IPG_RFI_FRAGLEN,
sp->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb_irq(skb);
}
} else {
skb_put(skb, framelen);
skb->protocol = eth_type_trans(skb, dev);
skb_checksum_none_assert(skb);
netif_rx(skb);
}
sp->rx_buff[entry] = NULL;
}
if (i == IPG_MAXRFDPROCESS_COUNT)
ipg_w32(ipg_r32(ASIC_CTRL) | IPG_AC_INT_REQUEST, ASIC_CTRL);
#ifdef IPG_DEBUG
if (!i)
sp->EmptyRFDListCount++;
#endif
while ((le64_to_cpu(rxfd->rfs) & IPG_RFS_RFDDONE) &&
!((le64_to_cpu(rxfd->rfs) & IPG_RFS_FRAMESTART) &&
(le64_to_cpu(rxfd->rfs) & IPG_RFS_FRAMEEND))) {
unsigned int entry = curr++ % IPG_RFDLIST_LENGTH;
rxfd = sp->rxd + entry;
IPG_DEBUG_MSG("Frame requires multiple RFDs\n");
if (sp->rx_buff[entry]) {
pci_unmap_single(sp->pdev,
le64_to_cpu(rxfd->frag_info) & ~IPG_RFI_FRAGLEN,
sp->rx_buf_sz, PCI_DMA_FROMDEVICE);
dev_kfree_skb_irq(sp->rx_buff[entry]);
}
sp->rx_buff[entry] = NULL;
}
sp->rx_current = curr;
if ((curr - sp->rx_dirty) >= IPG_MINUSEDRFDSTOFREE)
ipg_nic_rxrestore(dev);
return 0;
}
static void ipg_reset_after_host_error(struct work_struct *work)
{
struct ipg_nic_private *sp =
container_of(work, struct ipg_nic_private, task.work);
struct net_device *dev = sp->dev;
ipg_reset(dev, IPG_AC_GLOBAL_RESET | IPG_AC_HOST | IPG_AC_DMA);
init_rfdlist(dev);
init_tfdlist(dev);
if (ipg_io_config(dev) < 0) {
netdev_info(dev, "Cannot recover from PCI error\n");
schedule_delayed_work(&sp->task, HZ);
}
}
static irqreturn_t ipg_interrupt_handler(int irq, void *dev_inst)
{
struct net_device *dev = dev_inst;
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int handled = 0;
u16 status;
IPG_DEBUG_MSG("_interrupt_handler\n");
if (sp->is_jumbo)
ipg_nic_rxrestore(dev);
spin_lock(&sp->lock);
status = ipg_r16(INT_STATUS_ACK);
IPG_DEBUG_MSG("IntStatusAck = %04x\n", status);
if (!(status & IPG_IS_RSVD_MASK))
goto out_enable;
handled = 1;
if (unlikely(!netif_running(dev)))
goto out_unlock;
if (status & IPG_IS_RFD_LIST_END) {
IPG_DEBUG_MSG("RFDListEnd Interrupt\n");
ipg_nic_rxrestore(dev);
#ifdef IPG_DEBUG
sp->RFDlistendCount++;
#endif
}
if ((status & IPG_IS_RX_DMA_PRIORITY) ||
(status & IPG_IS_RFD_LIST_END) ||
(status & IPG_IS_RX_DMA_COMPLETE) ||
(status & IPG_IS_INT_REQUESTED)) {
#ifdef IPG_DEBUG
if (status & (~(IPG_IS_RX_DMA_PRIORITY | IPG_IS_RFD_LIST_END |
IPG_IS_RX_DMA_COMPLETE | IPG_IS_INT_REQUESTED) &
(IPG_IS_HOST_ERROR | IPG_IS_TX_DMA_COMPLETE |
IPG_IS_LINK_EVENT | IPG_IS_TX_COMPLETE |
IPG_IS_UPDATE_STATS)))
sp->RFDListCheckedCount++;
#endif
if (sp->is_jumbo)
ipg_nic_rx_jumbo(dev);
else
ipg_nic_rx(dev);
}
if (status & IPG_IS_TX_DMA_COMPLETE)
ipg_nic_txfree(dev);
if (status & IPG_IS_TX_COMPLETE)
ipg_nic_txcleanup(dev);
if (status & IPG_IS_UPDATE_STATS)
ipg_nic_get_stats(dev);
if (status & IPG_IS_HOST_ERROR) {
IPG_DDEBUG_MSG("HostError Interrupt\n");
schedule_delayed_work(&sp->task, 0);
}
if (status & IPG_IS_LINK_EVENT) {
if (ipg_config_autoneg(dev) < 0)
netdev_info(dev, "Auto-negotiation error\n");
}
if (status & IPG_IS_MAC_CTRL_FRAME)
IPG_DEBUG_MSG("MACCtrlFrame interrupt\n");
if (status & IPG_IS_RX_COMPLETE)
IPG_DEBUG_MSG("RxComplete interrupt\n");
if (status & IPG_IS_RX_EARLY)
IPG_DEBUG_MSG("RxEarly interrupt\n");
out_enable:
ipg_w16(IPG_IE_TX_DMA_COMPLETE | IPG_IE_RX_DMA_COMPLETE |
IPG_IE_HOST_ERROR | IPG_IE_INT_REQUESTED | IPG_IE_TX_COMPLETE |
IPG_IE_LINK_EVENT | IPG_IE_UPDATE_STATS, INT_ENABLE);
out_unlock:
spin_unlock(&sp->lock);
return IRQ_RETVAL(handled);
}
static void ipg_rx_clear(struct ipg_nic_private *sp)
{
unsigned int i;
for (i = 0; i < IPG_RFDLIST_LENGTH; i++) {
if (sp->rx_buff[i]) {
struct ipg_rx *rxfd = sp->rxd + i;
dev_kfree_skb_irq(sp->rx_buff[i]);
sp->rx_buff[i] = NULL;
pci_unmap_single(sp->pdev,
le64_to_cpu(rxfd->frag_info) & ~IPG_RFI_FRAGLEN,
sp->rx_buf_sz, PCI_DMA_FROMDEVICE);
}
}
}
static void ipg_tx_clear(struct ipg_nic_private *sp)
{
unsigned int i;
for (i = 0; i < IPG_TFDLIST_LENGTH; i++) {
if (sp->tx_buff[i]) {
struct ipg_tx *txfd = sp->txd + i;
pci_unmap_single(sp->pdev,
le64_to_cpu(txfd->frag_info) & ~IPG_TFI_FRAGLEN,
sp->tx_buff[i]->len, PCI_DMA_TODEVICE);
dev_kfree_skb_irq(sp->tx_buff[i]);
sp->tx_buff[i] = NULL;
}
}
}
static int ipg_nic_open(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
struct pci_dev *pdev = sp->pdev;
int rc;
IPG_DEBUG_MSG("_nic_open\n");
sp->rx_buf_sz = sp->rxsupport_size;
ipg_w16(0x0000, INT_ENABLE);
rc = request_irq(pdev->irq, ipg_interrupt_handler, IRQF_SHARED,
dev->name, dev);
if (rc < 0) {
netdev_info(dev, "Error when requesting interrupt\n");
goto out;
}
dev->irq = pdev->irq;
rc = -ENOMEM;
sp->rxd = dma_alloc_coherent(&pdev->dev, IPG_RX_RING_BYTES,
&sp->rxd_map, GFP_KERNEL);
if (!sp->rxd)
goto err_free_irq_0;
sp->txd = dma_alloc_coherent(&pdev->dev, IPG_TX_RING_BYTES,
&sp->txd_map, GFP_KERNEL);
if (!sp->txd)
goto err_free_rx_1;
rc = init_rfdlist(dev);
if (rc < 0) {
netdev_info(dev, "Error during configuration\n");
goto err_free_tx_2;
}
init_tfdlist(dev);
rc = ipg_io_config(dev);
if (rc < 0) {
netdev_info(dev, "Error during configuration\n");
goto err_release_tfdlist_3;
}
if (ipg_config_autoneg(dev) < 0)
netdev_info(dev, "Auto-negotiation error\n");
sp->jumbo.found_start = 0;
sp->jumbo.current_size = 0;
sp->jumbo.skb = NULL;
ipg_w32((ipg_r32(MAC_CTRL) | IPG_MC_RX_ENABLE | IPG_MC_TX_ENABLE) &
IPG_MC_RSVD_MASK, MAC_CTRL);
netif_start_queue(dev);
out:
return rc;
err_release_tfdlist_3:
ipg_tx_clear(sp);
ipg_rx_clear(sp);
err_free_tx_2:
dma_free_coherent(&pdev->dev, IPG_TX_RING_BYTES, sp->txd, sp->txd_map);
err_free_rx_1:
dma_free_coherent(&pdev->dev, IPG_RX_RING_BYTES, sp->rxd, sp->rxd_map);
err_free_irq_0:
free_irq(pdev->irq, dev);
goto out;
}
static int ipg_nic_stop(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
struct pci_dev *pdev = sp->pdev;
IPG_DEBUG_MSG("_nic_stop\n");
netif_stop_queue(dev);
IPG_DUMPTFDLIST(dev);
do {
(void) ipg_r16(INT_STATUS_ACK);
ipg_reset(dev, IPG_AC_GLOBAL_RESET | IPG_AC_HOST | IPG_AC_DMA);
synchronize_irq(pdev->irq);
} while (ipg_r16(INT_ENABLE) & IPG_IE_RSVD_MASK);
ipg_rx_clear(sp);
ipg_tx_clear(sp);
pci_free_consistent(pdev, IPG_RX_RING_BYTES, sp->rxd, sp->rxd_map);
pci_free_consistent(pdev, IPG_TX_RING_BYTES, sp->txd, sp->txd_map);
free_irq(pdev->irq, dev);
return 0;
}
static netdev_tx_t ipg_nic_hard_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int entry = sp->tx_current % IPG_TFDLIST_LENGTH;
unsigned long flags;
struct ipg_tx *txfd;
IPG_DDEBUG_MSG("_nic_hard_start_xmit\n");
if (sp->tenmbpsmode)
netif_stop_queue(dev);
if (sp->reset_current_tfd) {
sp->reset_current_tfd = 0;
entry = 0;
}
txfd = sp->txd + entry;
sp->tx_buff[entry] = skb;
txfd->tfc = cpu_to_le64(IPG_TFC_TFDDONE);
txfd->tfc |= cpu_to_le64(IPG_TFC_WORDALIGNDISABLED |
(IPG_TFC_FRAMEID & sp->tx_current) |
(IPG_TFC_FRAGCOUNT & (1 << 24)));
if (sp->tenmbpsmode)
txfd->tfc |= cpu_to_le64(IPG_TFC_TXINDICATE);
txfd->tfc |= cpu_to_le64(IPG_TFC_TXDMAINDICATE);
if (!(IPG_APPEND_FCS_ON_TX))
txfd->tfc |= cpu_to_le64(IPG_TFC_FCSAPPENDDISABLE);
if (IPG_ADD_IPCHECKSUM_ON_TX)
txfd->tfc |= cpu_to_le64(IPG_TFC_IPCHECKSUMENABLE);
if (IPG_ADD_TCPCHECKSUM_ON_TX)
txfd->tfc |= cpu_to_le64(IPG_TFC_TCPCHECKSUMENABLE);
if (IPG_ADD_UDPCHECKSUM_ON_TX)
txfd->tfc |= cpu_to_le64(IPG_TFC_UDPCHECKSUMENABLE);
if (IPG_INSERT_MANUAL_VLAN_TAG) {
txfd->tfc |= cpu_to_le64(IPG_TFC_VLANTAGINSERT |
((u64) IPG_MANUAL_VLAN_VID << 32) |
((u64) IPG_MANUAL_VLAN_CFI << 44) |
((u64) IPG_MANUAL_VLAN_USERPRIORITY << 45));
}
txfd->frag_info = cpu_to_le64(pci_map_single(sp->pdev, skb->data,
skb->len, PCI_DMA_TODEVICE));
txfd->frag_info |= cpu_to_le64(IPG_TFI_FRAGLEN &
((u64) (skb->len & 0xffff) << 48));
txfd->tfc &= cpu_to_le64(~IPG_TFC_TFDDONE);
spin_lock_irqsave(&sp->lock, flags);
sp->tx_current++;
mmiowb();
ipg_w32(IPG_DC_TX_DMA_POLL_NOW, DMA_CTRL);
if (sp->tx_current == (sp->tx_dirty + IPG_TFDLIST_LENGTH))
netif_stop_queue(dev);
spin_unlock_irqrestore(&sp->lock, flags);
return NETDEV_TX_OK;
}
static void ipg_set_phy_default_param(unsigned char rev,
struct net_device *dev, int phy_address)
{
unsigned short length;
unsigned char revision;
const unsigned short *phy_param;
unsigned short address, value;
phy_param = &DefaultPhyParam[0];
length = *phy_param & 0x00FF;
revision = (unsigned char)((*phy_param) >> 8);
phy_param++;
while (length != 0) {
if (rev == revision) {
while (length > 1) {
address = *phy_param;
value = *(phy_param + 1);
phy_param += 2;
mdio_write(dev, phy_address, address, value);
length -= 4;
}
break;
} else {
phy_param += length / 2;
length = *phy_param & 0x00FF;
revision = (unsigned char)((*phy_param) >> 8);
phy_param++;
}
}
}
static int read_eeprom(struct net_device *dev, int eep_addr)
{
void __iomem *ioaddr = ipg_ioaddr(dev);
unsigned int i;
int ret = 0;
u16 value;
value = IPG_EC_EEPROM_READOPCODE | (eep_addr & 0xff);
ipg_w16(value, EEPROM_CTRL);
for (i = 0; i < 1000; i++) {
u16 data;
mdelay(10);
data = ipg_r16(EEPROM_CTRL);
if (!(data & IPG_EC_EEPROM_BUSY)) {
ret = ipg_r16(EEPROM_DATA);
break;
}
}
return ret;
}
static void ipg_init_mii(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
struct mii_if_info *mii_if = &sp->mii_if;
int phyaddr;
mii_if->dev = dev;
mii_if->mdio_read = mdio_read;
mii_if->mdio_write = mdio_write;
mii_if->phy_id_mask = 0x1f;
mii_if->reg_num_mask = 0x1f;
mii_if->phy_id = phyaddr = ipg_find_phyaddr(dev);
if (phyaddr != 0x1f) {
u16 mii_phyctrl, mii_1000cr;
mii_1000cr = mdio_read(dev, phyaddr, MII_CTRL1000);
mii_1000cr |= ADVERTISE_1000FULL | ADVERTISE_1000HALF |
GMII_PHY_1000BASETCONTROL_PreferMaster;
mdio_write(dev, phyaddr, MII_CTRL1000, mii_1000cr);
mii_phyctrl = mdio_read(dev, phyaddr, MII_BMCR);
ipg_set_phy_default_param(sp->pdev->revision, dev, phyaddr);
mii_phyctrl |= BMCR_RESET | BMCR_ANRESTART;
mdio_write(dev, phyaddr, MII_BMCR, mii_phyctrl);
}
}
static int ipg_hw_init(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
void __iomem *ioaddr = sp->ioaddr;
unsigned int i;
int rc;
sp->led_mode = read_eeprom(dev, 6);
rc = ipg_reset(dev, IPG_RESET_MASK);
if (rc < 0)
goto out;
ipg_init_mii(dev);
for (i = 0; i < 3; i++)
sp->station_addr[i] = read_eeprom(dev, 16 + i);
for (i = 0; i < 3; i++)
ipg_w16(sp->station_addr[i], STATION_ADDRESS_0 + 2*i);
dev->dev_addr[0] = ipg_r16(STATION_ADDRESS_0) & 0x00ff;
dev->dev_addr[1] = (ipg_r16(STATION_ADDRESS_0) & 0xff00) >> 8;
dev->dev_addr[2] = ipg_r16(STATION_ADDRESS_1) & 0x00ff;
dev->dev_addr[3] = (ipg_r16(STATION_ADDRESS_1) & 0xff00) >> 8;
dev->dev_addr[4] = ipg_r16(STATION_ADDRESS_2) & 0x00ff;
dev->dev_addr[5] = (ipg_r16(STATION_ADDRESS_2) & 0xff00) >> 8;
out:
return rc;
}
static int ipg_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct ipg_nic_private *sp = netdev_priv(dev);
int rc;
mutex_lock(&sp->mii_mutex);
rc = generic_mii_ioctl(&sp->mii_if, if_mii(ifr), cmd, NULL);
mutex_unlock(&sp->mii_mutex);
return rc;
}
static int ipg_nic_change_mtu(struct net_device *dev, int new_mtu)
{
struct ipg_nic_private *sp = netdev_priv(dev);
int err;
IPG_DEBUG_MSG("_nic_change_mtu\n");
if (new_mtu < 68 || new_mtu > 10240)
return -EINVAL;
err = ipg_nic_stop(dev);
if (err)
return err;
dev->mtu = new_mtu;
sp->max_rxframe_size = new_mtu;
sp->rxfrag_size = new_mtu;
if (sp->rxfrag_size > 4088)
sp->rxfrag_size = 4088;
sp->rxsupport_size = sp->max_rxframe_size;
if (new_mtu > 0x0600)
sp->is_jumbo = true;
else
sp->is_jumbo = false;
return ipg_nic_open(dev);
}
static int ipg_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct ipg_nic_private *sp = netdev_priv(dev);
int rc;
mutex_lock(&sp->mii_mutex);
rc = mii_ethtool_gset(&sp->mii_if, cmd);
mutex_unlock(&sp->mii_mutex);
return rc;
}
static int ipg_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct ipg_nic_private *sp = netdev_priv(dev);
int rc;
mutex_lock(&sp->mii_mutex);
rc = mii_ethtool_sset(&sp->mii_if, cmd);
mutex_unlock(&sp->mii_mutex);
return rc;
}
static int ipg_nway_reset(struct net_device *dev)
{
struct ipg_nic_private *sp = netdev_priv(dev);
int rc;
mutex_lock(&sp->mii_mutex);
rc = mii_nway_restart(&sp->mii_if);
mutex_unlock(&sp->mii_mutex);
return rc;
}
static void __devexit ipg_remove(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct ipg_nic_private *sp = netdev_priv(dev);
IPG_DEBUG_MSG("_remove\n");
unregister_netdev(dev);
pci_iounmap(pdev, sp->ioaddr);
pci_release_regions(pdev);
free_netdev(dev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int __devinit ipg_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
unsigned int i = id->driver_data;
struct ipg_nic_private *sp;
struct net_device *dev;
void __iomem *ioaddr;
int rc;
rc = pci_enable_device(pdev);
if (rc < 0)
goto out;
pr_info("%s: %s\n", pci_name(pdev), ipg_brand_name[i]);
pci_set_master(pdev);
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(40));
if (rc < 0) {
rc = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (rc < 0) {
pr_err("%s: DMA config failed\n", pci_name(pdev));
goto err_disable_0;
}
}
dev = alloc_etherdev(sizeof(struct ipg_nic_private));
if (!dev) {
rc = -ENOMEM;
goto err_disable_0;
}
sp = netdev_priv(dev);
spin_lock_init(&sp->lock);
mutex_init(&sp->mii_mutex);
sp->is_jumbo = IPG_IS_JUMBO;
sp->rxfrag_size = IPG_RXFRAG_SIZE;
sp->rxsupport_size = IPG_RXSUPPORT_SIZE;
sp->max_rxframe_size = IPG_MAX_RXFRAME_SIZE;
dev->netdev_ops = &ipg_netdev_ops;
SET_NETDEV_DEV(dev, &pdev->dev);
SET_ETHTOOL_OPS(dev, &ipg_ethtool_ops);
rc = pci_request_regions(pdev, DRV_NAME);
if (rc)
goto err_free_dev_1;
ioaddr = pci_iomap(pdev, 1, pci_resource_len(pdev, 1));
if (!ioaddr) {
pr_err("%s: cannot map MMIO\n", pci_name(pdev));
rc = -EIO;
goto err_release_regions_2;
}
sp->ioaddr = ioaddr;
sp->pdev = pdev;
sp->dev = dev;
INIT_DELAYED_WORK(&sp->task, ipg_reset_after_host_error);
pci_set_drvdata(pdev, dev);
rc = ipg_hw_init(dev);
if (rc < 0)
goto err_unmap_3;
rc = register_netdev(dev);
if (rc < 0)
goto err_unmap_3;
netdev_info(dev, "Ethernet device registered\n");
out:
return rc;
err_unmap_3:
pci_iounmap(pdev, ioaddr);
err_release_regions_2:
pci_release_regions(pdev);
err_free_dev_1:
free_netdev(dev);
err_disable_0:
pci_disable_device(pdev);
goto out;
}
static int __init ipg_init_module(void)
{
return pci_register_driver(&ipg_pci_driver);
}
static void __exit ipg_exit_module(void)
{
pci_unregister_driver(&ipg_pci_driver);
}
