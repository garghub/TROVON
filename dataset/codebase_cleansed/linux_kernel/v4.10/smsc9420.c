static inline u32 smsc9420_reg_read(struct smsc9420_pdata *pd, u32 offset)
{
return ioread32(pd->ioaddr + offset);
}
static inline void
smsc9420_reg_write(struct smsc9420_pdata *pd, u32 offset, u32 value)
{
iowrite32(value, pd->ioaddr + offset);
}
static inline void smsc9420_pci_flush_write(struct smsc9420_pdata *pd)
{
smsc9420_reg_read(pd, ID_REV);
}
static int smsc9420_mii_read(struct mii_bus *bus, int phyaddr, int regidx)
{
struct smsc9420_pdata *pd = (struct smsc9420_pdata *)bus->priv;
unsigned long flags;
u32 addr;
int i, reg = -EIO;
spin_lock_irqsave(&pd->phy_lock, flags);
if ((smsc9420_reg_read(pd, MII_ACCESS) & MII_ACCESS_MII_BUSY_)) {
netif_warn(pd, drv, pd->dev, "MII is busy???\n");
goto out;
}
addr = ((phyaddr & 0x1F) << 11) | ((regidx & 0x1F) << 6) |
MII_ACCESS_MII_READ_;
smsc9420_reg_write(pd, MII_ACCESS, addr);
for (i = 0; i < 5; i++) {
if (!(smsc9420_reg_read(pd, MII_ACCESS) &
MII_ACCESS_MII_BUSY_)) {
reg = (u16)smsc9420_reg_read(pd, MII_DATA);
goto out;
}
udelay(10);
}
netif_warn(pd, drv, pd->dev, "MII busy timeout!\n");
out:
spin_unlock_irqrestore(&pd->phy_lock, flags);
return reg;
}
static int smsc9420_mii_write(struct mii_bus *bus, int phyaddr, int regidx,
u16 val)
{
struct smsc9420_pdata *pd = (struct smsc9420_pdata *)bus->priv;
unsigned long flags;
u32 addr;
int i, reg = -EIO;
spin_lock_irqsave(&pd->phy_lock, flags);
if ((smsc9420_reg_read(pd, MII_ACCESS) & MII_ACCESS_MII_BUSY_)) {
netif_warn(pd, drv, pd->dev, "MII is busy???\n");
goto out;
}
smsc9420_reg_write(pd, MII_DATA, (u32)val);
addr = ((phyaddr & 0x1F) << 11) | ((regidx & 0x1F) << 6) |
MII_ACCESS_MII_WRITE_;
smsc9420_reg_write(pd, MII_ACCESS, addr);
for (i = 0; i < 5; i++) {
if (!(smsc9420_reg_read(pd, MII_ACCESS) &
MII_ACCESS_MII_BUSY_)) {
reg = 0;
goto out;
}
udelay(10);
}
netif_warn(pd, drv, pd->dev, "MII busy timeout!\n");
out:
spin_unlock_irqrestore(&pd->phy_lock, flags);
return reg;
}
static u32 smsc9420_hash(u8 addr[ETH_ALEN])
{
return (ether_crc(ETH_ALEN, addr) >> 26) & 0x3f;
}
static int smsc9420_eeprom_reload(struct smsc9420_pdata *pd)
{
int timeout = 100000;
BUG_ON(!pd);
if (smsc9420_reg_read(pd, E2P_CMD) & E2P_CMD_EPC_BUSY_) {
netif_dbg(pd, drv, pd->dev, "%s: Eeprom busy\n", __func__);
return -EIO;
}
smsc9420_reg_write(pd, E2P_CMD,
(E2P_CMD_EPC_BUSY_ | E2P_CMD_EPC_CMD_RELOAD_));
do {
udelay(10);
if (!(smsc9420_reg_read(pd, E2P_CMD) & E2P_CMD_EPC_BUSY_))
return 0;
} while (timeout--);
netif_warn(pd, drv, pd->dev, "%s: Eeprom timed out\n", __func__);
return -EIO;
}
static int smsc9420_do_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
if (!netif_running(dev) || !dev->phydev)
return -EINVAL;
return phy_mii_ioctl(dev->phydev, ifr, cmd);
}
static void smsc9420_ethtool_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct smsc9420_pdata *pd = netdev_priv(netdev);
strlcpy(drvinfo->driver, DRV_NAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->bus_info, pci_name(pd->pdev),
sizeof(drvinfo->bus_info));
strlcpy(drvinfo->version, DRV_VERSION, sizeof(drvinfo->version));
}
static u32 smsc9420_ethtool_get_msglevel(struct net_device *netdev)
{
struct smsc9420_pdata *pd = netdev_priv(netdev);
return pd->msg_enable;
}
static void smsc9420_ethtool_set_msglevel(struct net_device *netdev, u32 data)
{
struct smsc9420_pdata *pd = netdev_priv(netdev);
pd->msg_enable = data;
}
static int smsc9420_ethtool_getregslen(struct net_device *dev)
{
return 0x100 + (32 * sizeof(u32));
}
static void
smsc9420_ethtool_getregs(struct net_device *dev, struct ethtool_regs *regs,
void *buf)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
struct phy_device *phy_dev = dev->phydev;
unsigned int i, j = 0;
u32 *data = buf;
regs->version = smsc9420_reg_read(pd, ID_REV);
for (i = 0; i < 0x100; i += (sizeof(u32)))
data[j++] = smsc9420_reg_read(pd, i);
if (!phy_dev)
return;
for (i = 0; i <= 31; i++)
data[j++] = smsc9420_mii_read(phy_dev->mdio.bus,
phy_dev->mdio.addr, i);
}
static void smsc9420_eeprom_enable_access(struct smsc9420_pdata *pd)
{
unsigned int temp = smsc9420_reg_read(pd, GPIO_CFG);
temp &= ~GPIO_CFG_EEPR_EN_;
smsc9420_reg_write(pd, GPIO_CFG, temp);
msleep(1);
}
static int smsc9420_eeprom_send_cmd(struct smsc9420_pdata *pd, u32 op)
{
int timeout = 100;
u32 e2cmd;
netif_dbg(pd, hw, pd->dev, "op 0x%08x\n", op);
if (smsc9420_reg_read(pd, E2P_CMD) & E2P_CMD_EPC_BUSY_) {
netif_warn(pd, hw, pd->dev, "Busy at start\n");
return -EBUSY;
}
e2cmd = op | E2P_CMD_EPC_BUSY_;
smsc9420_reg_write(pd, E2P_CMD, e2cmd);
do {
msleep(1);
e2cmd = smsc9420_reg_read(pd, E2P_CMD);
} while ((e2cmd & E2P_CMD_EPC_BUSY_) && (--timeout));
if (!timeout) {
netif_info(pd, hw, pd->dev, "TIMED OUT\n");
return -EAGAIN;
}
if (e2cmd & E2P_CMD_EPC_TIMEOUT_) {
netif_info(pd, hw, pd->dev,
"Error occurred during eeprom operation\n");
return -EINVAL;
}
return 0;
}
static int smsc9420_eeprom_read_location(struct smsc9420_pdata *pd,
u8 address, u8 *data)
{
u32 op = E2P_CMD_EPC_CMD_READ_ | address;
int ret;
netif_dbg(pd, hw, pd->dev, "address 0x%x\n", address);
ret = smsc9420_eeprom_send_cmd(pd, op);
if (!ret)
data[address] = smsc9420_reg_read(pd, E2P_DATA);
return ret;
}
static int smsc9420_eeprom_write_location(struct smsc9420_pdata *pd,
u8 address, u8 data)
{
u32 op = E2P_CMD_EPC_CMD_ERASE_ | address;
int ret;
netif_dbg(pd, hw, pd->dev, "address 0x%x, data 0x%x\n", address, data);
ret = smsc9420_eeprom_send_cmd(pd, op);
if (!ret) {
op = E2P_CMD_EPC_CMD_WRITE_ | address;
smsc9420_reg_write(pd, E2P_DATA, (u32)data);
ret = smsc9420_eeprom_send_cmd(pd, op);
}
return ret;
}
static int smsc9420_ethtool_get_eeprom_len(struct net_device *dev)
{
return SMSC9420_EEPROM_SIZE;
}
static int smsc9420_ethtool_get_eeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom, u8 *data)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
u8 eeprom_data[SMSC9420_EEPROM_SIZE];
int len, i;
smsc9420_eeprom_enable_access(pd);
len = min(eeprom->len, SMSC9420_EEPROM_SIZE);
for (i = 0; i < len; i++) {
int ret = smsc9420_eeprom_read_location(pd, i, eeprom_data);
if (ret < 0) {
eeprom->len = 0;
return ret;
}
}
memcpy(data, &eeprom_data[eeprom->offset], len);
eeprom->magic = SMSC9420_EEPROM_MAGIC;
eeprom->len = len;
return 0;
}
static int smsc9420_ethtool_set_eeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom, u8 *data)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
int ret;
if (eeprom->magic != SMSC9420_EEPROM_MAGIC)
return -EINVAL;
smsc9420_eeprom_enable_access(pd);
smsc9420_eeprom_send_cmd(pd, E2P_CMD_EPC_CMD_EWEN_);
ret = smsc9420_eeprom_write_location(pd, eeprom->offset, *data);
smsc9420_eeprom_send_cmd(pd, E2P_CMD_EPC_CMD_EWDS_);
eeprom->len = 1;
return ret;
}
static void smsc9420_set_mac_address(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
u8 *dev_addr = dev->dev_addr;
u32 mac_high16 = (dev_addr[5] << 8) | dev_addr[4];
u32 mac_low32 = (dev_addr[3] << 24) | (dev_addr[2] << 16) |
(dev_addr[1] << 8) | dev_addr[0];
smsc9420_reg_write(pd, ADDRH, mac_high16);
smsc9420_reg_write(pd, ADDRL, mac_low32);
}
static void smsc9420_check_mac_address(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
if (is_valid_ether_addr(dev->dev_addr)) {
smsc9420_set_mac_address(dev);
netif_dbg(pd, probe, pd->dev,
"MAC Address is specified by configuration\n");
} else {
u32 mac_high16 = smsc9420_reg_read(pd, ADDRH);
u32 mac_low32 = smsc9420_reg_read(pd, ADDRL);
dev->dev_addr[0] = (u8)(mac_low32);
dev->dev_addr[1] = (u8)(mac_low32 >> 8);
dev->dev_addr[2] = (u8)(mac_low32 >> 16);
dev->dev_addr[3] = (u8)(mac_low32 >> 24);
dev->dev_addr[4] = (u8)(mac_high16);
dev->dev_addr[5] = (u8)(mac_high16 >> 8);
if (is_valid_ether_addr(dev->dev_addr)) {
netif_dbg(pd, probe, pd->dev,
"Mac Address is read from EEPROM\n");
} else {
eth_hw_addr_random(dev);
smsc9420_set_mac_address(dev);
netif_dbg(pd, probe, pd->dev,
"MAC Address is set to random\n");
}
}
}
static void smsc9420_stop_tx(struct smsc9420_pdata *pd)
{
u32 dmac_control, mac_cr, dma_intr_ena;
int timeout = 1000;
dmac_control = smsc9420_reg_read(pd, DMAC_CONTROL);
dmac_control &= (~DMAC_CONTROL_ST_);
smsc9420_reg_write(pd, DMAC_CONTROL, dmac_control);
while (--timeout) {
if (smsc9420_reg_read(pd, DMAC_STATUS) & DMAC_STS_TS_)
break;
udelay(10);
}
if (!timeout)
netif_warn(pd, ifdown, pd->dev, "TX DMAC failed to stop\n");
smsc9420_reg_write(pd, DMAC_STATUS, DMAC_STS_TXPS_);
dma_intr_ena = smsc9420_reg_read(pd, DMAC_INTR_ENA);
dma_intr_ena &= ~(DMAC_INTR_ENA_TX_);
smsc9420_reg_write(pd, DMAC_INTR_ENA, dma_intr_ena);
smsc9420_pci_flush_write(pd);
mac_cr = smsc9420_reg_read(pd, MAC_CR) & (~MAC_CR_TXEN_);
smsc9420_reg_write(pd, MAC_CR, mac_cr);
smsc9420_pci_flush_write(pd);
}
static void smsc9420_free_tx_ring(struct smsc9420_pdata *pd)
{
int i;
BUG_ON(!pd->tx_ring);
if (!pd->tx_buffers)
return;
for (i = 0; i < TX_RING_SIZE; i++) {
struct sk_buff *skb = pd->tx_buffers[i].skb;
if (skb) {
BUG_ON(!pd->tx_buffers[i].mapping);
pci_unmap_single(pd->pdev, pd->tx_buffers[i].mapping,
skb->len, PCI_DMA_TODEVICE);
dev_kfree_skb_any(skb);
}
pd->tx_ring[i].status = 0;
pd->tx_ring[i].length = 0;
pd->tx_ring[i].buffer1 = 0;
pd->tx_ring[i].buffer2 = 0;
}
wmb();
kfree(pd->tx_buffers);
pd->tx_buffers = NULL;
pd->tx_ring_head = 0;
pd->tx_ring_tail = 0;
}
static void smsc9420_free_rx_ring(struct smsc9420_pdata *pd)
{
int i;
BUG_ON(!pd->rx_ring);
if (!pd->rx_buffers)
return;
for (i = 0; i < RX_RING_SIZE; i++) {
if (pd->rx_buffers[i].skb)
dev_kfree_skb_any(pd->rx_buffers[i].skb);
if (pd->rx_buffers[i].mapping)
pci_unmap_single(pd->pdev, pd->rx_buffers[i].mapping,
PKT_BUF_SZ, PCI_DMA_FROMDEVICE);
pd->rx_ring[i].status = 0;
pd->rx_ring[i].length = 0;
pd->rx_ring[i].buffer1 = 0;
pd->rx_ring[i].buffer2 = 0;
}
wmb();
kfree(pd->rx_buffers);
pd->rx_buffers = NULL;
pd->rx_ring_head = 0;
pd->rx_ring_tail = 0;
}
static void smsc9420_stop_rx(struct smsc9420_pdata *pd)
{
int timeout = 1000;
u32 mac_cr, dmac_control, dma_intr_ena;
dma_intr_ena = smsc9420_reg_read(pd, DMAC_INTR_ENA);
dma_intr_ena &= (~DMAC_INTR_ENA_RX_);
smsc9420_reg_write(pd, DMAC_INTR_ENA, dma_intr_ena);
smsc9420_pci_flush_write(pd);
mac_cr = smsc9420_reg_read(pd, MAC_CR) & (~MAC_CR_RXEN_);
smsc9420_reg_write(pd, MAC_CR, mac_cr);
smsc9420_pci_flush_write(pd);
dmac_control = smsc9420_reg_read(pd, DMAC_CONTROL);
dmac_control &= (~DMAC_CONTROL_SR_);
smsc9420_reg_write(pd, DMAC_CONTROL, dmac_control);
smsc9420_pci_flush_write(pd);
while (--timeout) {
if (smsc9420_reg_read(pd, DMAC_STATUS) & DMAC_STS_RS_)
break;
udelay(10);
}
if (!timeout)
netif_warn(pd, ifdown, pd->dev,
"RX DMAC did not stop! timeout\n");
smsc9420_reg_write(pd, DMAC_STATUS, DMAC_STS_RXPS_);
}
static irqreturn_t smsc9420_isr(int irq, void *dev_id)
{
struct smsc9420_pdata *pd = dev_id;
u32 int_cfg, int_sts, int_ctl;
irqreturn_t ret = IRQ_NONE;
ulong flags;
BUG_ON(!pd);
BUG_ON(!pd->ioaddr);
int_cfg = smsc9420_reg_read(pd, INT_CFG);
if ((int_cfg & (INT_CFG_IRQ_EN_ | INT_CFG_IRQ_INT_)) !=
(INT_CFG_IRQ_EN_ | INT_CFG_IRQ_INT_))
return IRQ_NONE;
int_sts = smsc9420_reg_read(pd, INT_STAT);
if (likely(INT_STAT_DMAC_INT_ & int_sts)) {
u32 status = smsc9420_reg_read(pd, DMAC_STATUS);
u32 ints_to_clear = 0;
if (status & DMAC_STS_TX_) {
ints_to_clear |= (DMAC_STS_TX_ | DMAC_STS_NIS_);
netif_wake_queue(pd->dev);
}
if (status & DMAC_STS_RX_) {
u32 dma_intr_ena = smsc9420_reg_read(pd, DMAC_INTR_ENA);
dma_intr_ena &= (~DMAC_INTR_ENA_RX_);
smsc9420_reg_write(pd, DMAC_INTR_ENA, dma_intr_ena);
smsc9420_pci_flush_write(pd);
ints_to_clear |= (DMAC_STS_RX_ | DMAC_STS_NIS_);
napi_schedule(&pd->napi);
}
if (ints_to_clear)
smsc9420_reg_write(pd, DMAC_STATUS, ints_to_clear);
ret = IRQ_HANDLED;
}
if (unlikely(INT_STAT_SW_INT_ & int_sts)) {
spin_lock_irqsave(&pd->int_lock, flags);
int_ctl = smsc9420_reg_read(pd, INT_CTL);
int_ctl &= (~INT_CTL_SW_INT_EN_);
smsc9420_reg_write(pd, INT_CTL, int_ctl);
spin_unlock_irqrestore(&pd->int_lock, flags);
smsc9420_reg_write(pd, INT_STAT, INT_STAT_SW_INT_);
pd->software_irq_signal = true;
smp_wmb();
ret = IRQ_HANDLED;
}
smsc9420_pci_flush_write(pd);
return ret;
}
static void smsc9420_poll_controller(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
const int irq = pd->pdev->irq;
disable_irq(irq);
smsc9420_isr(0, dev);
enable_irq(irq);
}
static void smsc9420_dmac_soft_reset(struct smsc9420_pdata *pd)
{
smsc9420_reg_write(pd, BUS_MODE, BUS_MODE_SWR_);
smsc9420_reg_read(pd, BUS_MODE);
udelay(2);
if (smsc9420_reg_read(pd, BUS_MODE) & BUS_MODE_SWR_)
netif_warn(pd, drv, pd->dev, "Software reset not cleared\n");
}
static int smsc9420_stop(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
u32 int_cfg;
ulong flags;
BUG_ON(!pd);
BUG_ON(!dev->phydev);
spin_lock_irqsave(&pd->int_lock, flags);
int_cfg = smsc9420_reg_read(pd, INT_CFG) & (~INT_CFG_IRQ_EN_);
smsc9420_reg_write(pd, INT_CFG, int_cfg);
spin_unlock_irqrestore(&pd->int_lock, flags);
netif_tx_disable(dev);
napi_disable(&pd->napi);
smsc9420_stop_tx(pd);
smsc9420_free_tx_ring(pd);
smsc9420_stop_rx(pd);
smsc9420_free_rx_ring(pd);
free_irq(pd->pdev->irq, pd);
smsc9420_dmac_soft_reset(pd);
phy_stop(dev->phydev);
phy_disconnect(dev->phydev);
mdiobus_unregister(pd->mii_bus);
mdiobus_free(pd->mii_bus);
return 0;
}
static void smsc9420_rx_count_stats(struct net_device *dev, u32 desc_status)
{
if (unlikely(desc_status & RDES0_ERROR_SUMMARY_)) {
dev->stats.rx_errors++;
if (desc_status & RDES0_DESCRIPTOR_ERROR_)
dev->stats.rx_over_errors++;
else if (desc_status & (RDES0_FRAME_TOO_LONG_ |
RDES0_RUNT_FRAME_ | RDES0_COLLISION_SEEN_))
dev->stats.rx_frame_errors++;
else if (desc_status & RDES0_CRC_ERROR_)
dev->stats.rx_crc_errors++;
}
if (unlikely(desc_status & RDES0_LENGTH_ERROR_))
dev->stats.rx_length_errors++;
if (unlikely(!((desc_status & RDES0_LAST_DESCRIPTOR_) &&
(desc_status & RDES0_FIRST_DESCRIPTOR_))))
dev->stats.rx_length_errors++;
if (desc_status & RDES0_MULTICAST_FRAME_)
dev->stats.multicast++;
}
static void smsc9420_rx_handoff(struct smsc9420_pdata *pd, const int index,
const u32 status)
{
struct net_device *dev = pd->dev;
struct sk_buff *skb;
u16 packet_length = (status & RDES0_FRAME_LENGTH_MASK_)
>> RDES0_FRAME_LENGTH_SHFT_;
packet_length -= 4;
if (pd->rx_csum)
packet_length -= 2;
dev->stats.rx_packets++;
dev->stats.rx_bytes += packet_length;
pci_unmap_single(pd->pdev, pd->rx_buffers[index].mapping,
PKT_BUF_SZ, PCI_DMA_FROMDEVICE);
pd->rx_buffers[index].mapping = 0;
skb = pd->rx_buffers[index].skb;
pd->rx_buffers[index].skb = NULL;
if (pd->rx_csum) {
u16 hw_csum = get_unaligned_le16(skb_tail_pointer(skb) +
NET_IP_ALIGN + packet_length + 4);
put_unaligned_le16(hw_csum, &skb->csum);
skb->ip_summed = CHECKSUM_COMPLETE;
}
skb_reserve(skb, NET_IP_ALIGN);
skb_put(skb, packet_length);
skb->protocol = eth_type_trans(skb, dev);
netif_receive_skb(skb);
}
static int smsc9420_alloc_rx_buffer(struct smsc9420_pdata *pd, int index)
{
struct sk_buff *skb = netdev_alloc_skb(pd->dev, PKT_BUF_SZ);
dma_addr_t mapping;
BUG_ON(pd->rx_buffers[index].skb);
BUG_ON(pd->rx_buffers[index].mapping);
if (unlikely(!skb))
return -ENOMEM;
mapping = pci_map_single(pd->pdev, skb_tail_pointer(skb),
PKT_BUF_SZ, PCI_DMA_FROMDEVICE);
if (pci_dma_mapping_error(pd->pdev, mapping)) {
dev_kfree_skb_any(skb);
netif_warn(pd, rx_err, pd->dev, "pci_map_single failed!\n");
return -ENOMEM;
}
pd->rx_buffers[index].skb = skb;
pd->rx_buffers[index].mapping = mapping;
pd->rx_ring[index].buffer1 = mapping + NET_IP_ALIGN;
pd->rx_ring[index].status = RDES0_OWN_;
wmb();
return 0;
}
static void smsc9420_alloc_new_rx_buffers(struct smsc9420_pdata *pd)
{
while (pd->rx_ring_tail != pd->rx_ring_head) {
if (smsc9420_alloc_rx_buffer(pd, pd->rx_ring_tail))
break;
pd->rx_ring_tail = (pd->rx_ring_tail + 1) % RX_RING_SIZE;
}
}
static int smsc9420_rx_poll(struct napi_struct *napi, int budget)
{
struct smsc9420_pdata *pd =
container_of(napi, struct smsc9420_pdata, napi);
struct net_device *dev = pd->dev;
u32 drop_frame_cnt, dma_intr_ena, status;
int work_done;
for (work_done = 0; work_done < budget; work_done++) {
rmb();
status = pd->rx_ring[pd->rx_ring_head].status;
if (status & RDES0_OWN_)
break;
smsc9420_rx_count_stats(dev, status);
smsc9420_rx_handoff(pd, pd->rx_ring_head, status);
pd->rx_ring_head = (pd->rx_ring_head + 1) % RX_RING_SIZE;
smsc9420_alloc_new_rx_buffers(pd);
}
drop_frame_cnt = smsc9420_reg_read(pd, MISS_FRAME_CNTR);
dev->stats.rx_dropped +=
(drop_frame_cnt & 0xFFFF) + ((drop_frame_cnt >> 17) & 0x3FF);
smsc9420_reg_write(pd, RX_POLL_DEMAND, 1);
smsc9420_pci_flush_write(pd);
if (work_done < budget) {
napi_complete(&pd->napi);
dma_intr_ena = smsc9420_reg_read(pd, DMAC_INTR_ENA);
dma_intr_ena |= (DMAC_INTR_ENA_RX_ | DMAC_INTR_ENA_NIS_);
smsc9420_reg_write(pd, DMAC_INTR_ENA, dma_intr_ena);
smsc9420_pci_flush_write(pd);
}
return work_done;
}
static void
smsc9420_tx_update_stats(struct net_device *dev, u32 status, u32 length)
{
if (unlikely(status & TDES0_ERROR_SUMMARY_)) {
dev->stats.tx_errors++;
if (status & (TDES0_EXCESSIVE_DEFERRAL_ |
TDES0_EXCESSIVE_COLLISIONS_))
dev->stats.tx_aborted_errors++;
if (status & (TDES0_LOSS_OF_CARRIER_ | TDES0_NO_CARRIER_))
dev->stats.tx_carrier_errors++;
} else {
dev->stats.tx_packets++;
dev->stats.tx_bytes += (length & 0x7FF);
}
if (unlikely(status & TDES0_EXCESSIVE_COLLISIONS_)) {
dev->stats.collisions += 16;
} else {
dev->stats.collisions +=
(status & TDES0_COLLISION_COUNT_MASK_) >>
TDES0_COLLISION_COUNT_SHFT_;
}
if (unlikely(status & TDES0_HEARTBEAT_FAIL_))
dev->stats.tx_heartbeat_errors++;
}
static void smsc9420_complete_tx(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
while (pd->tx_ring_tail != pd->tx_ring_head) {
int index = pd->tx_ring_tail;
u32 status, length;
rmb();
status = pd->tx_ring[index].status;
length = pd->tx_ring[index].length;
if (unlikely(TDES0_OWN_ & status))
break;
smsc9420_tx_update_stats(dev, status, length);
BUG_ON(!pd->tx_buffers[index].skb);
BUG_ON(!pd->tx_buffers[index].mapping);
pci_unmap_single(pd->pdev, pd->tx_buffers[index].mapping,
pd->tx_buffers[index].skb->len, PCI_DMA_TODEVICE);
pd->tx_buffers[index].mapping = 0;
dev_kfree_skb_any(pd->tx_buffers[index].skb);
pd->tx_buffers[index].skb = NULL;
pd->tx_ring[index].buffer1 = 0;
wmb();
pd->tx_ring_tail = (pd->tx_ring_tail + 1) % TX_RING_SIZE;
}
}
static netdev_tx_t smsc9420_hard_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
dma_addr_t mapping;
int index = pd->tx_ring_head;
u32 tmp_desc1;
bool about_to_take_last_desc =
(((pd->tx_ring_head + 2) % TX_RING_SIZE) == pd->tx_ring_tail);
smsc9420_complete_tx(dev);
rmb();
BUG_ON(pd->tx_ring[index].status & TDES0_OWN_);
BUG_ON(pd->tx_buffers[index].skb);
BUG_ON(pd->tx_buffers[index].mapping);
mapping = pci_map_single(pd->pdev, skb->data,
skb->len, PCI_DMA_TODEVICE);
if (pci_dma_mapping_error(pd->pdev, mapping)) {
netif_warn(pd, tx_err, pd->dev,
"pci_map_single failed, dropping packet\n");
return NETDEV_TX_BUSY;
}
pd->tx_buffers[index].skb = skb;
pd->tx_buffers[index].mapping = mapping;
tmp_desc1 = (TDES1_LS_ | ((u32)skb->len & 0x7FF));
if (unlikely(about_to_take_last_desc)) {
tmp_desc1 |= TDES1_IC_;
netif_stop_queue(pd->dev);
}
if (unlikely(index == (TX_RING_SIZE - 1)))
tmp_desc1 |= TDES1_TER_;
pd->tx_ring[index].buffer1 = mapping;
pd->tx_ring[index].length = tmp_desc1;
wmb();
pd->tx_ring_head = (pd->tx_ring_head + 1) % TX_RING_SIZE;
pd->tx_ring[index].status = TDES0_OWN_;
wmb();
skb_tx_timestamp(skb);
smsc9420_reg_write(pd, TX_POLL_DEMAND, 1);
smsc9420_pci_flush_write(pd);
return NETDEV_TX_OK;
}
static struct net_device_stats *smsc9420_get_stats(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
u32 counter = smsc9420_reg_read(pd, MISS_FRAME_CNTR);
dev->stats.rx_dropped +=
(counter & 0x0000FFFF) + ((counter >> 17) & 0x000003FF);
return &dev->stats;
}
static void smsc9420_set_multicast_list(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
u32 mac_cr = smsc9420_reg_read(pd, MAC_CR);
if (dev->flags & IFF_PROMISC) {
netif_dbg(pd, hw, pd->dev, "Promiscuous Mode Enabled\n");
mac_cr |= MAC_CR_PRMS_;
mac_cr &= (~MAC_CR_MCPAS_);
mac_cr &= (~MAC_CR_HPFILT_);
} else if (dev->flags & IFF_ALLMULTI) {
netif_dbg(pd, hw, pd->dev, "Receive all Multicast Enabled\n");
mac_cr &= (~MAC_CR_PRMS_);
mac_cr |= MAC_CR_MCPAS_;
mac_cr &= (~MAC_CR_HPFILT_);
} else if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
u32 hash_lo = 0, hash_hi = 0;
netif_dbg(pd, hw, pd->dev, "Multicast filter enabled\n");
netdev_for_each_mc_addr(ha, dev) {
u32 bit_num = smsc9420_hash(ha->addr);
u32 mask = 1 << (bit_num & 0x1F);
if (bit_num & 0x20)
hash_hi |= mask;
else
hash_lo |= mask;
}
smsc9420_reg_write(pd, HASHH, hash_hi);
smsc9420_reg_write(pd, HASHL, hash_lo);
mac_cr &= (~MAC_CR_PRMS_);
mac_cr &= (~MAC_CR_MCPAS_);
mac_cr |= MAC_CR_HPFILT_;
} else {
netif_dbg(pd, hw, pd->dev, "Receive own packets only\n");
smsc9420_reg_write(pd, HASHH, 0);
smsc9420_reg_write(pd, HASHL, 0);
mac_cr &= (~MAC_CR_PRMS_);
mac_cr &= (~MAC_CR_MCPAS_);
mac_cr &= (~MAC_CR_HPFILT_);
}
smsc9420_reg_write(pd, MAC_CR, mac_cr);
smsc9420_pci_flush_write(pd);
}
static void smsc9420_phy_update_flowcontrol(struct smsc9420_pdata *pd)
{
struct net_device *dev = pd->dev;
struct phy_device *phy_dev = dev->phydev;
u32 flow;
if (phy_dev->duplex == DUPLEX_FULL) {
u16 lcladv = phy_read(phy_dev, MII_ADVERTISE);
u16 rmtadv = phy_read(phy_dev, MII_LPA);
u8 cap = mii_resolve_flowctrl_fdx(lcladv, rmtadv);
if (cap & FLOW_CTRL_RX)
flow = 0xFFFF0002;
else
flow = 0;
netif_info(pd, link, pd->dev, "rx pause %s, tx pause %s\n",
cap & FLOW_CTRL_RX ? "enabled" : "disabled",
cap & FLOW_CTRL_TX ? "enabled" : "disabled");
} else {
netif_info(pd, link, pd->dev, "half duplex\n");
flow = 0;
}
smsc9420_reg_write(pd, FLOW, flow);
}
static void smsc9420_phy_adjust_link(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
struct phy_device *phy_dev = dev->phydev;
int carrier;
if (phy_dev->duplex != pd->last_duplex) {
u32 mac_cr = smsc9420_reg_read(pd, MAC_CR);
if (phy_dev->duplex) {
netif_dbg(pd, link, pd->dev, "full duplex mode\n");
mac_cr |= MAC_CR_FDPX_;
} else {
netif_dbg(pd, link, pd->dev, "half duplex mode\n");
mac_cr &= ~MAC_CR_FDPX_;
}
smsc9420_reg_write(pd, MAC_CR, mac_cr);
smsc9420_phy_update_flowcontrol(pd);
pd->last_duplex = phy_dev->duplex;
}
carrier = netif_carrier_ok(dev);
if (carrier != pd->last_carrier) {
if (carrier)
netif_dbg(pd, link, pd->dev, "carrier OK\n");
else
netif_dbg(pd, link, pd->dev, "no carrier\n");
pd->last_carrier = carrier;
}
}
static int smsc9420_mii_probe(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
struct phy_device *phydev = NULL;
BUG_ON(dev->phydev);
phydev = mdiobus_get_phy(pd->mii_bus, 1);
if (!phydev) {
netdev_err(dev, "no PHY found at address 1\n");
return -ENODEV;
}
phydev = phy_connect(dev, phydev_name(phydev),
smsc9420_phy_adjust_link, PHY_INTERFACE_MODE_MII);
if (IS_ERR(phydev)) {
netdev_err(dev, "Could not attach to PHY\n");
return PTR_ERR(phydev);
}
phydev->supported &= (PHY_BASIC_FEATURES | SUPPORTED_Pause |
SUPPORTED_Asym_Pause);
phydev->advertising = phydev->supported;
phy_attached_info(phydev);
pd->last_duplex = -1;
pd->last_carrier = -1;
return 0;
}
static int smsc9420_mii_init(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
int err = -ENXIO;
pd->mii_bus = mdiobus_alloc();
if (!pd->mii_bus) {
err = -ENOMEM;
goto err_out_1;
}
pd->mii_bus->name = DRV_MDIONAME;
snprintf(pd->mii_bus->id, MII_BUS_ID_SIZE, "%x",
(pd->pdev->bus->number << 8) | pd->pdev->devfn);
pd->mii_bus->priv = pd;
pd->mii_bus->read = smsc9420_mii_read;
pd->mii_bus->write = smsc9420_mii_write;
pd->mii_bus->phy_mask = ~(1 << 1);
if (mdiobus_register(pd->mii_bus)) {
netif_warn(pd, probe, pd->dev, "Error registering mii bus\n");
goto err_out_free_bus_2;
}
if (smsc9420_mii_probe(dev) < 0) {
netif_warn(pd, probe, pd->dev, "Error probing mii bus\n");
goto err_out_unregister_bus_3;
}
return 0;
err_out_unregister_bus_3:
mdiobus_unregister(pd->mii_bus);
err_out_free_bus_2:
mdiobus_free(pd->mii_bus);
err_out_1:
return err;
}
static int smsc9420_alloc_tx_ring(struct smsc9420_pdata *pd)
{
int i;
BUG_ON(!pd->tx_ring);
pd->tx_buffers = kmalloc_array(TX_RING_SIZE,
sizeof(struct smsc9420_ring_info),
GFP_KERNEL);
if (!pd->tx_buffers)
return -ENOMEM;
for (i = 0; i < TX_RING_SIZE; i++) {
pd->tx_buffers[i].skb = NULL;
pd->tx_buffers[i].mapping = 0;
pd->tx_ring[i].status = 0;
pd->tx_ring[i].length = 0;
pd->tx_ring[i].buffer1 = 0;
pd->tx_ring[i].buffer2 = 0;
}
pd->tx_ring[TX_RING_SIZE - 1].length = TDES1_TER_;
wmb();
pd->tx_ring_head = 0;
pd->tx_ring_tail = 0;
smsc9420_reg_write(pd, TX_BASE_ADDR, pd->tx_dma_addr);
smsc9420_pci_flush_write(pd);
return 0;
}
static int smsc9420_alloc_rx_ring(struct smsc9420_pdata *pd)
{
int i;
BUG_ON(!pd->rx_ring);
pd->rx_buffers = kmalloc_array(RX_RING_SIZE,
sizeof(struct smsc9420_ring_info),
GFP_KERNEL);
if (pd->rx_buffers == NULL)
goto out;
for (i = 0; i < RX_RING_SIZE; i++) {
pd->rx_ring[i].status = 0;
pd->rx_ring[i].length = PKT_BUF_SZ;
pd->rx_ring[i].buffer2 = 0;
pd->rx_buffers[i].skb = NULL;
pd->rx_buffers[i].mapping = 0;
}
pd->rx_ring[RX_RING_SIZE - 1].length = (PKT_BUF_SZ | RDES1_RER_);
for (i = 0; i < RX_RING_SIZE; i++) {
if (smsc9420_alloc_rx_buffer(pd, i)) {
netif_warn(pd, ifup, pd->dev,
"failed to allocate rx skb %d\n", i);
goto out_free_rx_skbs;
}
}
pd->rx_ring_head = 0;
pd->rx_ring_tail = 0;
smsc9420_reg_write(pd, VLAN1, ETH_P_8021Q);
netif_dbg(pd, ifup, pd->dev, "VLAN1 = 0x%08x\n",
smsc9420_reg_read(pd, VLAN1));
if (pd->rx_csum) {
u32 coe = smsc9420_reg_read(pd, COE_CR) | RX_COE_EN;
smsc9420_reg_write(pd, COE_CR, coe);
netif_dbg(pd, ifup, pd->dev, "COE_CR = 0x%08x\n", coe);
}
smsc9420_reg_write(pd, RX_BASE_ADDR, pd->rx_dma_addr);
smsc9420_pci_flush_write(pd);
return 0;
out_free_rx_skbs:
smsc9420_free_rx_ring(pd);
out:
return -ENOMEM;
}
static int smsc9420_open(struct net_device *dev)
{
struct smsc9420_pdata *pd = netdev_priv(dev);
u32 bus_mode, mac_cr, dmac_control, int_cfg, dma_intr_ena, int_ctl;
const int irq = pd->pdev->irq;
unsigned long flags;
int result = 0, timeout;
if (!is_valid_ether_addr(dev->dev_addr)) {
netif_warn(pd, ifup, pd->dev,
"dev_addr is not a valid MAC address\n");
result = -EADDRNOTAVAIL;
goto out_0;
}
netif_carrier_off(dev);
spin_lock_irqsave(&pd->int_lock, flags);
int_cfg = smsc9420_reg_read(pd, INT_CFG) & (~INT_CFG_IRQ_EN_);
smsc9420_reg_write(pd, INT_CFG, int_cfg);
smsc9420_reg_write(pd, INT_CTL, 0);
spin_unlock_irqrestore(&pd->int_lock, flags);
smsc9420_reg_write(pd, DMAC_INTR_ENA, 0);
smsc9420_reg_write(pd, INT_STAT, 0xFFFFFFFF);
smsc9420_pci_flush_write(pd);
result = request_irq(irq, smsc9420_isr, IRQF_SHARED, DRV_NAME, pd);
if (result) {
netif_warn(pd, ifup, pd->dev, "Unable to use IRQ = %d\n", irq);
result = -ENODEV;
goto out_0;
}
smsc9420_dmac_soft_reset(pd);
smsc9420_reg_write(pd, MAC_CR, 0);
smsc9420_set_mac_address(dev);
smsc9420_reg_write(pd, GPIO_CFG,
(GPIO_CFG_LED_3_ | GPIO_CFG_LED_2_ | GPIO_CFG_LED_1_));
bus_mode = BUS_MODE_DMA_BURST_LENGTH_16;
#ifdef __BIG_ENDIAN
bus_mode |= BUS_MODE_DBO_;
#endif
smsc9420_reg_write(pd, BUS_MODE, bus_mode);
smsc9420_pci_flush_write(pd);
smsc9420_reg_write(pd, BUS_CFG, BUS_CFG_RXTXWEIGHT_4_1);
smsc9420_reg_write(pd, DMAC_CONTROL,
(DMAC_CONTROL_SF_ | DMAC_CONTROL_OSF_));
smsc9420_pci_flush_write(pd);
netif_dbg(pd, ifup, pd->dev, "Testing ISR using IRQ %d\n", irq);
pd->software_irq_signal = false;
spin_lock_irqsave(&pd->int_lock, flags);
int_cfg = smsc9420_reg_read(pd, INT_CFG) | INT_CFG_IRQ_EN_;
int_cfg &= ~(INT_CFG_INT_DEAS_MASK);
int_cfg |= (INT_DEAS_TIME & INT_CFG_INT_DEAS_MASK);
smsc9420_reg_write(pd, INT_CFG, int_cfg);
int_ctl = smsc9420_reg_read(pd, INT_CTL) | INT_CTL_SW_INT_EN_;
smsc9420_reg_write(pd, INT_CTL, int_ctl);
spin_unlock_irqrestore(&pd->int_lock, flags);
smsc9420_pci_flush_write(pd);
timeout = 1000;
while (timeout--) {
if (pd->software_irq_signal)
break;
msleep(1);
}
spin_lock_irqsave(&pd->int_lock, flags);
int_cfg = smsc9420_reg_read(pd, INT_CFG) & (~INT_CFG_IRQ_EN_);
smsc9420_reg_write(pd, INT_CFG, int_cfg);
spin_unlock_irqrestore(&pd->int_lock, flags);
if (!pd->software_irq_signal) {
netif_warn(pd, ifup, pd->dev, "ISR failed signaling test\n");
result = -ENODEV;
goto out_free_irq_1;
}
netif_dbg(pd, ifup, pd->dev, "ISR passed test using IRQ %d\n", irq);
result = smsc9420_alloc_tx_ring(pd);
if (result) {
netif_warn(pd, ifup, pd->dev,
"Failed to Initialize tx dma ring\n");
result = -ENOMEM;
goto out_free_irq_1;
}
result = smsc9420_alloc_rx_ring(pd);
if (result) {
netif_warn(pd, ifup, pd->dev,
"Failed to Initialize rx dma ring\n");
result = -ENOMEM;
goto out_free_tx_ring_2;
}
result = smsc9420_mii_init(dev);
if (result) {
netif_warn(pd, ifup, pd->dev, "Failed to initialize Phy\n");
result = -ENODEV;
goto out_free_rx_ring_3;
}
phy_start(dev->phydev);
napi_enable(&pd->napi);
mac_cr = smsc9420_reg_read(pd, MAC_CR) | MAC_CR_TXEN_ | MAC_CR_RXEN_;
smsc9420_reg_write(pd, MAC_CR, mac_cr);
dmac_control = smsc9420_reg_read(pd, DMAC_CONTROL);
dmac_control |= DMAC_CONTROL_ST_ | DMAC_CONTROL_SR_;
smsc9420_reg_write(pd, DMAC_CONTROL, dmac_control);
smsc9420_pci_flush_write(pd);
dma_intr_ena = smsc9420_reg_read(pd, DMAC_INTR_ENA);
dma_intr_ena |=
(DMAC_INTR_ENA_TX_ | DMAC_INTR_ENA_RX_ | DMAC_INTR_ENA_NIS_);
smsc9420_reg_write(pd, DMAC_INTR_ENA, dma_intr_ena);
smsc9420_pci_flush_write(pd);
netif_wake_queue(dev);
smsc9420_reg_write(pd, RX_POLL_DEMAND, 1);
spin_lock_irqsave(&pd->int_lock, flags);
int_cfg = smsc9420_reg_read(pd, INT_CFG) | INT_CFG_IRQ_EN_;
smsc9420_reg_write(pd, INT_CFG, int_cfg);
spin_unlock_irqrestore(&pd->int_lock, flags);
return 0;
out_free_rx_ring_3:
smsc9420_free_rx_ring(pd);
out_free_tx_ring_2:
smsc9420_free_tx_ring(pd);
out_free_irq_1:
free_irq(irq, pd);
out_0:
return result;
}
static int smsc9420_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct smsc9420_pdata *pd = netdev_priv(dev);
u32 int_cfg;
ulong flags;
spin_lock_irqsave(&pd->int_lock, flags);
int_cfg = smsc9420_reg_read(pd, INT_CFG) & (~INT_CFG_IRQ_EN_);
smsc9420_reg_write(pd, INT_CFG, int_cfg);
spin_unlock_irqrestore(&pd->int_lock, flags);
if (netif_running(dev)) {
netif_tx_disable(dev);
smsc9420_stop_tx(pd);
smsc9420_free_tx_ring(pd);
napi_disable(&pd->napi);
smsc9420_stop_rx(pd);
smsc9420_free_rx_ring(pd);
free_irq(pd->pdev->irq, pd);
netif_device_detach(dev);
}
pci_save_state(pdev);
pci_enable_wake(pdev, pci_choose_state(pdev, state), 0);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int smsc9420_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct smsc9420_pdata *pd = netdev_priv(dev);
int err;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
err = pci_enable_device(pdev);
if (err)
return err;
pci_set_master(pdev);
err = pci_enable_wake(pdev, PCI_D0, 0);
if (err)
netif_warn(pd, ifup, pd->dev, "pci_enable_wake failed: %d\n",
err);
if (netif_running(dev)) {
err = smsc9420_open(dev);
netif_device_attach(dev);
}
return err;
}
static int
smsc9420_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct net_device *dev;
struct smsc9420_pdata *pd;
void __iomem *virt_addr;
int result = 0;
u32 id_rev;
pr_info("%s version %s\n", DRV_DESCRIPTION, DRV_VERSION);
result = pci_enable_device(pdev);
if (unlikely(result)) {
pr_err("Cannot enable smsc9420\n");
goto out_0;
}
pci_set_master(pdev);
dev = alloc_etherdev(sizeof(*pd));
if (!dev)
goto out_disable_pci_device_1;
SET_NETDEV_DEV(dev, &pdev->dev);
if (!(pci_resource_flags(pdev, SMSC_BAR) & IORESOURCE_MEM)) {
netdev_err(dev, "Cannot find PCI device base address\n");
goto out_free_netdev_2;
}
if ((pci_request_regions(pdev, DRV_NAME))) {
netdev_err(dev, "Cannot obtain PCI resources, aborting\n");
goto out_free_netdev_2;
}
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
netdev_err(dev, "No usable DMA configuration, aborting\n");
goto out_free_regions_3;
}
virt_addr = ioremap(pci_resource_start(pdev, SMSC_BAR),
pci_resource_len(pdev, SMSC_BAR));
if (!virt_addr) {
netdev_err(dev, "Cannot map device registers, aborting\n");
goto out_free_regions_3;
}
virt_addr += LAN9420_CPSR_ENDIAN_OFFSET;
pd = netdev_priv(dev);
pd->rx_ring = pci_alloc_consistent(pdev,
sizeof(struct smsc9420_dma_desc) * RX_RING_SIZE +
sizeof(struct smsc9420_dma_desc) * TX_RING_SIZE,
&pd->rx_dma_addr);
if (!pd->rx_ring)
goto out_free_io_4;
pd->tx_ring = (pd->rx_ring + RX_RING_SIZE);
pd->tx_dma_addr = pd->rx_dma_addr +
sizeof(struct smsc9420_dma_desc) * RX_RING_SIZE;
pd->pdev = pdev;
pd->dev = dev;
pd->ioaddr = virt_addr;
pd->msg_enable = smsc_debug;
pd->rx_csum = true;
netif_dbg(pd, probe, pd->dev, "lan_base=0x%08lx\n", (ulong)virt_addr);
id_rev = smsc9420_reg_read(pd, ID_REV);
switch (id_rev & 0xFFFF0000) {
case 0x94200000:
netif_info(pd, probe, pd->dev,
"LAN9420 identified, ID_REV=0x%08X\n", id_rev);
break;
default:
netif_warn(pd, probe, pd->dev, "LAN9420 NOT identified\n");
netif_warn(pd, probe, pd->dev, "ID_REV=0x%08X\n", id_rev);
goto out_free_dmadesc_5;
}
smsc9420_dmac_soft_reset(pd);
smsc9420_eeprom_reload(pd);
smsc9420_check_mac_address(dev);
dev->netdev_ops = &smsc9420_netdev_ops;
dev->ethtool_ops = &smsc9420_ethtool_ops;
netif_napi_add(dev, &pd->napi, smsc9420_rx_poll, NAPI_WEIGHT);
result = register_netdev(dev);
if (result) {
netif_warn(pd, probe, pd->dev, "error %i registering device\n",
result);
goto out_free_dmadesc_5;
}
pci_set_drvdata(pdev, dev);
spin_lock_init(&pd->int_lock);
spin_lock_init(&pd->phy_lock);
dev_info(&dev->dev, "MAC Address: %pM\n", dev->dev_addr);
return 0;
out_free_dmadesc_5:
pci_free_consistent(pdev, sizeof(struct smsc9420_dma_desc) *
(RX_RING_SIZE + TX_RING_SIZE), pd->rx_ring, pd->rx_dma_addr);
out_free_io_4:
iounmap(virt_addr - LAN9420_CPSR_ENDIAN_OFFSET);
out_free_regions_3:
pci_release_regions(pdev);
out_free_netdev_2:
free_netdev(dev);
out_disable_pci_device_1:
pci_disable_device(pdev);
out_0:
return -ENODEV;
}
static void smsc9420_remove(struct pci_dev *pdev)
{
struct net_device *dev;
struct smsc9420_pdata *pd;
dev = pci_get_drvdata(pdev);
if (!dev)
return;
pd = netdev_priv(dev);
unregister_netdev(dev);
BUG_ON(pd->tx_buffers);
BUG_ON(pd->rx_buffers);
BUG_ON(!pd->tx_ring);
BUG_ON(!pd->rx_ring);
pci_free_consistent(pdev, sizeof(struct smsc9420_dma_desc) *
(RX_RING_SIZE + TX_RING_SIZE), pd->rx_ring, pd->rx_dma_addr);
iounmap(pd->ioaddr - LAN9420_CPSR_ENDIAN_OFFSET);
pci_release_regions(pdev);
free_netdev(dev);
pci_disable_device(pdev);
}
static int __init smsc9420_init_module(void)
{
smsc_debug = netif_msg_init(debug, SMSC_MSG_DEFAULT);
return pci_register_driver(&smsc9420_driver);
}
static void __exit smsc9420_exit_module(void)
{
pci_unregister_driver(&smsc9420_driver);
}
