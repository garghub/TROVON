static int atl2_sw_init(struct atl2_adapter *adapter)
{
struct atl2_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_id = pdev->subsystem_device;
hw->revision_id = pdev->revision;
pci_read_config_word(pdev, PCI_COMMAND, &hw->pci_cmd_word);
adapter->wol = 0;
adapter->ict = 50000;
adapter->link_speed = SPEED_0;
adapter->link_duplex = FULL_DUPLEX;
hw->phy_configured = false;
hw->preamble_len = 7;
hw->ipgt = 0x60;
hw->min_ifg = 0x50;
hw->ipgr1 = 0x40;
hw->ipgr2 = 0x60;
hw->retry_buf = 2;
hw->max_retry = 0xf;
hw->lcol = 0x37;
hw->jam_ipg = 7;
hw->fc_rxd_hi = 0;
hw->fc_rxd_lo = 0;
hw->max_frame_size = adapter->netdev->mtu;
spin_lock_init(&adapter->stats_lock);
set_bit(__ATL2_DOWN, &adapter->flags);
return 0;
}
static void atl2_set_multi(struct net_device *netdev)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct atl2_hw *hw = &adapter->hw;
struct netdev_hw_addr *ha;
u32 rctl;
u32 hash_value;
rctl = ATL2_READ_REG(hw, REG_MAC_CTRL);
if (netdev->flags & IFF_PROMISC) {
rctl |= MAC_CTRL_PROMIS_EN;
} else if (netdev->flags & IFF_ALLMULTI) {
rctl |= MAC_CTRL_MC_ALL_EN;
rctl &= ~MAC_CTRL_PROMIS_EN;
} else
rctl &= ~(MAC_CTRL_PROMIS_EN | MAC_CTRL_MC_ALL_EN);
ATL2_WRITE_REG(hw, REG_MAC_CTRL, rctl);
ATL2_WRITE_REG(hw, REG_RX_HASH_TABLE, 0);
ATL2_WRITE_REG_ARRAY(hw, REG_RX_HASH_TABLE, 1, 0);
netdev_for_each_mc_addr(ha, netdev) {
hash_value = atl2_hash_mc_addr(hw, ha->addr);
atl2_hash_set(hw, hash_value);
}
}
static void init_ring_ptrs(struct atl2_adapter *adapter)
{
adapter->txd_write_ptr = 0;
atomic_set(&adapter->txd_read_ptr, 0);
adapter->rxd_read_ptr = 0;
adapter->rxd_write_ptr = 0;
atomic_set(&adapter->txs_write_ptr, 0);
adapter->txs_next_clear = 0;
}
static int atl2_configure(struct atl2_adapter *adapter)
{
struct atl2_hw *hw = &adapter->hw;
u32 value;
ATL2_WRITE_REG(&adapter->hw, REG_ISR, 0xffffffff);
value = (((u32)hw->mac_addr[2]) << 24) |
(((u32)hw->mac_addr[3]) << 16) |
(((u32)hw->mac_addr[4]) << 8) |
(((u32)hw->mac_addr[5]));
ATL2_WRITE_REG(hw, REG_MAC_STA_ADDR, value);
value = (((u32)hw->mac_addr[0]) << 8) |
(((u32)hw->mac_addr[1]));
ATL2_WRITE_REG(hw, (REG_MAC_STA_ADDR+4), value);
ATL2_WRITE_REG(hw, REG_DESC_BASE_ADDR_HI,
(u32)((adapter->ring_dma & 0xffffffff00000000ULL) >> 32));
ATL2_WRITE_REG(hw, REG_TXD_BASE_ADDR_LO,
(u32)(adapter->txd_dma & 0x00000000ffffffffULL));
ATL2_WRITE_REG(hw, REG_TXS_BASE_ADDR_LO,
(u32)(adapter->txs_dma & 0x00000000ffffffffULL));
ATL2_WRITE_REG(hw, REG_RXD_BASE_ADDR_LO,
(u32)(adapter->rxd_dma & 0x00000000ffffffffULL));
ATL2_WRITE_REGW(hw, REG_TXD_MEM_SIZE, (u16)(adapter->txd_ring_size/4));
ATL2_WRITE_REGW(hw, REG_TXS_MEM_SIZE, (u16)adapter->txs_ring_size);
ATL2_WRITE_REGW(hw, REG_RXD_BUF_NUM, (u16)adapter->rxd_ring_size);
value = (((u32)hw->ipgt & MAC_IPG_IFG_IPGT_MASK) <<
MAC_IPG_IFG_IPGT_SHIFT) |
(((u32)hw->min_ifg & MAC_IPG_IFG_MIFG_MASK) <<
MAC_IPG_IFG_MIFG_SHIFT) |
(((u32)hw->ipgr1 & MAC_IPG_IFG_IPGR1_MASK) <<
MAC_IPG_IFG_IPGR1_SHIFT)|
(((u32)hw->ipgr2 & MAC_IPG_IFG_IPGR2_MASK) <<
MAC_IPG_IFG_IPGR2_SHIFT);
ATL2_WRITE_REG(hw, REG_MAC_IPG_IFG, value);
value = ((u32)hw->lcol & MAC_HALF_DUPLX_CTRL_LCOL_MASK) |
(((u32)hw->max_retry & MAC_HALF_DUPLX_CTRL_RETRY_MASK) <<
MAC_HALF_DUPLX_CTRL_RETRY_SHIFT) |
MAC_HALF_DUPLX_CTRL_EXC_DEF_EN |
(0xa << MAC_HALF_DUPLX_CTRL_ABEBT_SHIFT) |
(((u32)hw->jam_ipg & MAC_HALF_DUPLX_CTRL_JAMIPG_MASK) <<
MAC_HALF_DUPLX_CTRL_JAMIPG_SHIFT);
ATL2_WRITE_REG(hw, REG_MAC_HALF_DUPLX_CTRL, value);
ATL2_WRITE_REGW(hw, REG_IRQ_MODU_TIMER_INIT, adapter->imt);
ATL2_WRITE_REG(hw, REG_MASTER_CTRL, MASTER_CTRL_ITIMER_EN);
ATL2_WRITE_REGW(hw, REG_CMBDISDMA_TIMER, adapter->ict);
ATL2_WRITE_REG(hw, REG_MTU, adapter->netdev->mtu +
ENET_HEADER_SIZE + VLAN_SIZE + ETHERNET_FCS_SIZE);
ATL2_WRITE_REG(hw, REG_TX_CUT_THRESH, 0x177);
ATL2_WRITE_REGW(hw, REG_PAUSE_ON_TH, hw->fc_rxd_hi);
ATL2_WRITE_REGW(hw, REG_PAUSE_OFF_TH, hw->fc_rxd_lo);
ATL2_WRITE_REGW(hw, REG_MB_TXD_WR_IDX, (u16)adapter->txd_write_ptr);
ATL2_WRITE_REGW(hw, REG_MB_RXD_RD_IDX, (u16)adapter->rxd_read_ptr);
ATL2_WRITE_REGB(hw, REG_DMAR, DMAR_EN);
ATL2_WRITE_REGB(hw, REG_DMAW, DMAW_EN);
value = ATL2_READ_REG(&adapter->hw, REG_ISR);
if ((value & ISR_PHY_LINKDOWN) != 0)
value = 1;
else
value = 0;
ATL2_WRITE_REG(&adapter->hw, REG_ISR, 0x3fffffff);
ATL2_WRITE_REG(&adapter->hw, REG_ISR, 0);
return value;
}
static s32 atl2_setup_ring_resources(struct atl2_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
int size;
u8 offset = 0;
adapter->ring_size = size =
adapter->txd_ring_size * 1 + 7 +
adapter->txs_ring_size * 4 + 7 +
adapter->rxd_ring_size * 1536 + 127;
adapter->ring_vir_addr = pci_alloc_consistent(pdev, size,
&adapter->ring_dma);
if (!adapter->ring_vir_addr)
return -ENOMEM;
memset(adapter->ring_vir_addr, 0, adapter->ring_size);
adapter->txd_dma = adapter->ring_dma ;
offset = (adapter->txd_dma & 0x7) ? (8 - (adapter->txd_dma & 0x7)) : 0;
adapter->txd_dma += offset;
adapter->txd_ring = adapter->ring_vir_addr + offset;
adapter->txs_dma = adapter->txd_dma + adapter->txd_ring_size;
offset = (adapter->txs_dma & 0x7) ? (8 - (adapter->txs_dma & 0x7)) : 0;
adapter->txs_dma += offset;
adapter->txs_ring = (struct tx_pkt_status *)
(((u8 *)adapter->txd_ring) + (adapter->txd_ring_size + offset));
adapter->rxd_dma = adapter->txs_dma + adapter->txs_ring_size * 4;
offset = (adapter->rxd_dma & 127) ?
(128 - (adapter->rxd_dma & 127)) : 0;
if (offset > 7)
offset -= 8;
else
offset += (128 - 8);
adapter->rxd_dma += offset;
adapter->rxd_ring = (struct rx_desc *) (((u8 *)adapter->txs_ring) +
(adapter->txs_ring_size * 4 + offset));
return 0;
}
static inline void atl2_irq_enable(struct atl2_adapter *adapter)
{
ATL2_WRITE_REG(&adapter->hw, REG_IMR, IMR_NORMAL_MASK);
ATL2_WRITE_FLUSH(&adapter->hw);
}
static inline void atl2_irq_disable(struct atl2_adapter *adapter)
{
ATL2_WRITE_REG(&adapter->hw, REG_IMR, 0);
ATL2_WRITE_FLUSH(&adapter->hw);
synchronize_irq(adapter->pdev->irq);
}
static void __atl2_vlan_mode(netdev_features_t features, u32 *ctrl)
{
if (features & NETIF_F_HW_VLAN_CTAG_RX) {
*ctrl |= MAC_CTRL_RMV_VLAN;
} else {
*ctrl &= ~MAC_CTRL_RMV_VLAN;
}
}
static void atl2_vlan_mode(struct net_device *netdev,
netdev_features_t features)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
u32 ctrl;
atl2_irq_disable(adapter);
ctrl = ATL2_READ_REG(&adapter->hw, REG_MAC_CTRL);
__atl2_vlan_mode(features, &ctrl);
ATL2_WRITE_REG(&adapter->hw, REG_MAC_CTRL, ctrl);
atl2_irq_enable(adapter);
}
static void atl2_restore_vlan(struct atl2_adapter *adapter)
{
atl2_vlan_mode(adapter->netdev, adapter->netdev->features);
}
static netdev_features_t atl2_fix_features(struct net_device *netdev,
netdev_features_t features)
{
if (features & NETIF_F_HW_VLAN_CTAG_RX)
features |= NETIF_F_HW_VLAN_CTAG_TX;
else
features &= ~NETIF_F_HW_VLAN_CTAG_TX;
return features;
}
static int atl2_set_features(struct net_device *netdev,
netdev_features_t features)
{
netdev_features_t changed = netdev->features ^ features;
if (changed & NETIF_F_HW_VLAN_CTAG_RX)
atl2_vlan_mode(netdev, features);
return 0;
}
static void atl2_intr_rx(struct atl2_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct rx_desc *rxd;
struct sk_buff *skb;
do {
rxd = adapter->rxd_ring+adapter->rxd_write_ptr;
if (!rxd->status.update)
break;
rxd->status.update = 0;
if (rxd->status.ok && rxd->status.pkt_size >= 60) {
int rx_size = (int)(rxd->status.pkt_size - 4);
skb = netdev_alloc_skb_ip_align(netdev, rx_size);
if (NULL == skb) {
netdev->stats.rx_dropped++;
break;
}
memcpy(skb->data, rxd->packet, rx_size);
skb_put(skb, rx_size);
skb->protocol = eth_type_trans(skb, netdev);
if (rxd->status.vlan) {
u16 vlan_tag = (rxd->status.vtag>>4) |
((rxd->status.vtag&7) << 13) |
((rxd->status.vtag&8) << 9);
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vlan_tag);
}
netif_rx(skb);
netdev->stats.rx_bytes += rx_size;
netdev->stats.rx_packets++;
} else {
netdev->stats.rx_errors++;
if (rxd->status.ok && rxd->status.pkt_size <= 60)
netdev->stats.rx_length_errors++;
if (rxd->status.mcast)
netdev->stats.multicast++;
if (rxd->status.crc)
netdev->stats.rx_crc_errors++;
if (rxd->status.align)
netdev->stats.rx_frame_errors++;
}
if (++adapter->rxd_write_ptr == adapter->rxd_ring_size)
adapter->rxd_write_ptr = 0;
} while (1);
adapter->rxd_read_ptr = adapter->rxd_write_ptr;
ATL2_WRITE_REGW(&adapter->hw, REG_MB_RXD_RD_IDX, adapter->rxd_read_ptr);
}
static void atl2_intr_tx(struct atl2_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
u32 txd_read_ptr;
u32 txs_write_ptr;
struct tx_pkt_status *txs;
struct tx_pkt_header *txph;
int free_hole = 0;
do {
txs_write_ptr = (u32) atomic_read(&adapter->txs_write_ptr);
txs = adapter->txs_ring + txs_write_ptr;
if (!txs->update)
break;
free_hole = 1;
txs->update = 0;
if (++txs_write_ptr == adapter->txs_ring_size)
txs_write_ptr = 0;
atomic_set(&adapter->txs_write_ptr, (int)txs_write_ptr);
txd_read_ptr = (u32) atomic_read(&adapter->txd_read_ptr);
txph = (struct tx_pkt_header *)
(((u8 *)adapter->txd_ring) + txd_read_ptr);
if (txph->pkt_size != txs->pkt_size) {
struct tx_pkt_status *old_txs = txs;
printk(KERN_WARNING
"%s: txs packet size not consistent with txd"
" txd_:0x%08x, txs_:0x%08x!\n",
adapter->netdev->name,
*(u32 *)txph, *(u32 *)txs);
printk(KERN_WARNING
"txd read ptr: 0x%x\n",
txd_read_ptr);
txs = adapter->txs_ring + txs_write_ptr;
printk(KERN_WARNING
"txs-behind:0x%08x\n",
*(u32 *)txs);
if (txs_write_ptr < 2) {
txs = adapter->txs_ring +
(adapter->txs_ring_size +
txs_write_ptr - 2);
} else {
txs = adapter->txs_ring + (txs_write_ptr - 2);
}
printk(KERN_WARNING
"txs-before:0x%08x\n",
*(u32 *)txs);
txs = old_txs;
}
txd_read_ptr += (((u32)(txph->pkt_size) + 7) & ~3);
if (txd_read_ptr >= adapter->txd_ring_size)
txd_read_ptr -= adapter->txd_ring_size;
atomic_set(&adapter->txd_read_ptr, (int)txd_read_ptr);
if (txs->ok) {
netdev->stats.tx_bytes += txs->pkt_size;
netdev->stats.tx_packets++;
}
else
netdev->stats.tx_errors++;
if (txs->defer)
netdev->stats.collisions++;
if (txs->abort_col)
netdev->stats.tx_aborted_errors++;
if (txs->late_col)
netdev->stats.tx_window_errors++;
if (txs->underun)
netdev->stats.tx_fifo_errors++;
} while (1);
if (free_hole) {
if (netif_queue_stopped(adapter->netdev) &&
netif_carrier_ok(adapter->netdev))
netif_wake_queue(adapter->netdev);
}
}
static void atl2_check_for_link(struct atl2_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
u16 phy_data = 0;
spin_lock(&adapter->stats_lock);
atl2_read_phy_reg(&adapter->hw, MII_BMSR, &phy_data);
atl2_read_phy_reg(&adapter->hw, MII_BMSR, &phy_data);
spin_unlock(&adapter->stats_lock);
if (!(phy_data & BMSR_LSTATUS)) {
if (netif_carrier_ok(netdev)) {
printk(KERN_INFO "%s: %s NIC Link is Down\n",
atl2_driver_name, netdev->name);
adapter->link_speed = SPEED_0;
netif_carrier_off(netdev);
netif_stop_queue(netdev);
}
}
schedule_work(&adapter->link_chg_task);
}
static inline void atl2_clear_phy_int(struct atl2_adapter *adapter)
{
u16 phy_data;
spin_lock(&adapter->stats_lock);
atl2_read_phy_reg(&adapter->hw, 19, &phy_data);
spin_unlock(&adapter->stats_lock);
}
static irqreturn_t atl2_intr(int irq, void *data)
{
struct atl2_adapter *adapter = netdev_priv(data);
struct atl2_hw *hw = &adapter->hw;
u32 status;
status = ATL2_READ_REG(hw, REG_ISR);
if (0 == status)
return IRQ_NONE;
if (status & ISR_PHY)
atl2_clear_phy_int(adapter);
ATL2_WRITE_REG(hw, REG_ISR, status | ISR_DIS_INT);
if (status & ISR_PHY_LINKDOWN) {
if (netif_running(adapter->netdev)) {
ATL2_WRITE_REG(hw, REG_ISR, 0);
ATL2_WRITE_REG(hw, REG_IMR, 0);
ATL2_WRITE_FLUSH(hw);
schedule_work(&adapter->reset_task);
return IRQ_HANDLED;
}
}
if (status & (ISR_DMAR_TO_RST | ISR_DMAW_TO_RST)) {
ATL2_WRITE_REG(hw, REG_ISR, 0);
ATL2_WRITE_REG(hw, REG_IMR, 0);
ATL2_WRITE_FLUSH(hw);
schedule_work(&adapter->reset_task);
return IRQ_HANDLED;
}
if (status & (ISR_PHY | ISR_MANUAL)) {
adapter->netdev->stats.tx_carrier_errors++;
atl2_check_for_link(adapter);
}
if (status & ISR_TX_EVENT)
atl2_intr_tx(adapter);
if (status & ISR_RX_EVENT)
atl2_intr_rx(adapter);
ATL2_WRITE_REG(&adapter->hw, REG_ISR, 0);
return IRQ_HANDLED;
}
static int atl2_request_irq(struct atl2_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int flags, err = 0;
flags = IRQF_SHARED;
adapter->have_msi = true;
err = pci_enable_msi(adapter->pdev);
if (err)
adapter->have_msi = false;
if (adapter->have_msi)
flags &= ~IRQF_SHARED;
return request_irq(adapter->pdev->irq, atl2_intr, flags, netdev->name,
netdev);
}
static void atl2_free_ring_resources(struct atl2_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
pci_free_consistent(pdev, adapter->ring_size, adapter->ring_vir_addr,
adapter->ring_dma);
}
static int atl2_open(struct net_device *netdev)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
int err;
u32 val;
if (test_bit(__ATL2_TESTING, &adapter->flags))
return -EBUSY;
err = atl2_setup_ring_resources(adapter);
if (err)
return err;
err = atl2_init_hw(&adapter->hw);
if (err) {
err = -EIO;
goto err_init_hw;
}
atl2_set_multi(netdev);
init_ring_ptrs(adapter);
atl2_restore_vlan(adapter);
if (atl2_configure(adapter)) {
err = -EIO;
goto err_config;
}
err = atl2_request_irq(adapter);
if (err)
goto err_req_irq;
clear_bit(__ATL2_DOWN, &adapter->flags);
mod_timer(&adapter->watchdog_timer, round_jiffies(jiffies + 4*HZ));
val = ATL2_READ_REG(&adapter->hw, REG_MASTER_CTRL);
ATL2_WRITE_REG(&adapter->hw, REG_MASTER_CTRL,
val | MASTER_CTRL_MANUAL_INT);
atl2_irq_enable(adapter);
return 0;
err_init_hw:
err_req_irq:
err_config:
atl2_free_ring_resources(adapter);
atl2_reset_hw(&adapter->hw);
return err;
}
static void atl2_down(struct atl2_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
set_bit(__ATL2_DOWN, &adapter->flags);
netif_tx_disable(netdev);
atl2_reset_hw(&adapter->hw);
msleep(1);
atl2_irq_disable(adapter);
del_timer_sync(&adapter->watchdog_timer);
del_timer_sync(&adapter->phy_config_timer);
clear_bit(0, &adapter->cfg_phy);
netif_carrier_off(netdev);
adapter->link_speed = SPEED_0;
adapter->link_duplex = -1;
}
static void atl2_free_irq(struct atl2_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
free_irq(adapter->pdev->irq, netdev);
#ifdef CONFIG_PCI_MSI
if (adapter->have_msi)
pci_disable_msi(adapter->pdev);
#endif
}
static int atl2_close(struct net_device *netdev)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
WARN_ON(test_bit(__ATL2_RESETTING, &adapter->flags));
atl2_down(adapter);
atl2_free_irq(adapter);
atl2_free_ring_resources(adapter);
return 0;
}
static inline int TxsFreeUnit(struct atl2_adapter *adapter)
{
u32 txs_write_ptr = (u32) atomic_read(&adapter->txs_write_ptr);
return (adapter->txs_next_clear >= txs_write_ptr) ?
(int) (adapter->txs_ring_size - adapter->txs_next_clear +
txs_write_ptr - 1) :
(int) (txs_write_ptr - adapter->txs_next_clear - 1);
}
static inline int TxdFreeBytes(struct atl2_adapter *adapter)
{
u32 txd_read_ptr = (u32)atomic_read(&adapter->txd_read_ptr);
return (adapter->txd_write_ptr >= txd_read_ptr) ?
(int) (adapter->txd_ring_size - adapter->txd_write_ptr +
txd_read_ptr - 1) :
(int) (txd_read_ptr - adapter->txd_write_ptr - 1);
}
static netdev_tx_t atl2_xmit_frame(struct sk_buff *skb,
struct net_device *netdev)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct tx_pkt_header *txph;
u32 offset, copy_len;
int txs_unused;
int txbuf_unused;
if (test_bit(__ATL2_DOWN, &adapter->flags)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if (unlikely(skb->len <= 0)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
txs_unused = TxsFreeUnit(adapter);
txbuf_unused = TxdFreeBytes(adapter);
if (skb->len + sizeof(struct tx_pkt_header) + 4 > txbuf_unused ||
txs_unused < 1) {
netif_stop_queue(netdev);
return NETDEV_TX_BUSY;
}
offset = adapter->txd_write_ptr;
txph = (struct tx_pkt_header *) (((u8 *)adapter->txd_ring) + offset);
*(u32 *)txph = 0;
txph->pkt_size = skb->len;
offset += 4;
if (offset >= adapter->txd_ring_size)
offset -= adapter->txd_ring_size;
copy_len = adapter->txd_ring_size - offset;
if (copy_len >= skb->len) {
memcpy(((u8 *)adapter->txd_ring) + offset, skb->data, skb->len);
offset += ((u32)(skb->len + 3) & ~3);
} else {
memcpy(((u8 *)adapter->txd_ring)+offset, skb->data, copy_len);
memcpy((u8 *)adapter->txd_ring, skb->data+copy_len,
skb->len-copy_len);
offset = ((u32)(skb->len-copy_len + 3) & ~3);
}
#ifdef NETIF_F_HW_VLAN_CTAG_TX
if (skb_vlan_tag_present(skb)) {
u16 vlan_tag = skb_vlan_tag_get(skb);
vlan_tag = (vlan_tag << 4) |
(vlan_tag >> 13) |
((vlan_tag >> 9) & 0x8);
txph->ins_vlan = 1;
txph->vlan = vlan_tag;
}
#endif
if (offset >= adapter->txd_ring_size)
offset -= adapter->txd_ring_size;
adapter->txd_write_ptr = offset;
adapter->txs_ring[adapter->txs_next_clear].update = 0;
if (++adapter->txs_next_clear == adapter->txs_ring_size)
adapter->txs_next_clear = 0;
ATL2_WRITE_REGW(&adapter->hw, REG_MB_TXD_WR_IDX,
(adapter->txd_write_ptr >> 2));
mmiowb();
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
static int atl2_change_mtu(struct net_device *netdev, int new_mtu)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct atl2_hw *hw = &adapter->hw;
if ((new_mtu < 40) || (new_mtu > (ETH_DATA_LEN + VLAN_SIZE)))
return -EINVAL;
if (hw->max_frame_size != new_mtu) {
netdev->mtu = new_mtu;
ATL2_WRITE_REG(hw, REG_MTU, new_mtu + ENET_HEADER_SIZE +
VLAN_SIZE + ETHERNET_FCS_SIZE);
}
return 0;
}
static int atl2_set_mac(struct net_device *netdev, void *p)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
if (netif_running(netdev))
return -EBUSY;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
memcpy(adapter->hw.mac_addr, addr->sa_data, netdev->addr_len);
atl2_set_mac_addr(&adapter->hw);
return 0;
}
static int atl2_mii_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct mii_ioctl_data *data = if_mii(ifr);
unsigned long flags;
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = 0;
break;
case SIOCGMIIREG:
spin_lock_irqsave(&adapter->stats_lock, flags);
if (atl2_read_phy_reg(&adapter->hw,
data->reg_num & 0x1F, &data->val_out)) {
spin_unlock_irqrestore(&adapter->stats_lock, flags);
return -EIO;
}
spin_unlock_irqrestore(&adapter->stats_lock, flags);
break;
case SIOCSMIIREG:
if (data->reg_num & ~(0x1F))
return -EFAULT;
spin_lock_irqsave(&adapter->stats_lock, flags);
if (atl2_write_phy_reg(&adapter->hw, data->reg_num,
data->val_in)) {
spin_unlock_irqrestore(&adapter->stats_lock, flags);
return -EIO;
}
spin_unlock_irqrestore(&adapter->stats_lock, flags);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int atl2_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
return atl2_mii_ioctl(netdev, ifr, cmd);
#ifdef ETHTOOL_OPS_COMPAT
case SIOCETHTOOL:
return ethtool_ioctl(ifr);
#endif
default:
return -EOPNOTSUPP;
}
}
static void atl2_tx_timeout(struct net_device *netdev)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
schedule_work(&adapter->reset_task);
}
static void atl2_watchdog(unsigned long data)
{
struct atl2_adapter *adapter = (struct atl2_adapter *) data;
if (!test_bit(__ATL2_DOWN, &adapter->flags)) {
u32 drop_rxd, drop_rxs;
unsigned long flags;
spin_lock_irqsave(&adapter->stats_lock, flags);
drop_rxd = ATL2_READ_REG(&adapter->hw, REG_STS_RXD_OV);
drop_rxs = ATL2_READ_REG(&adapter->hw, REG_STS_RXS_OV);
spin_unlock_irqrestore(&adapter->stats_lock, flags);
adapter->netdev->stats.rx_over_errors += drop_rxd + drop_rxs;
mod_timer(&adapter->watchdog_timer,
round_jiffies(jiffies + 4 * HZ));
}
}
static void atl2_phy_config(unsigned long data)
{
struct atl2_adapter *adapter = (struct atl2_adapter *) data;
struct atl2_hw *hw = &adapter->hw;
unsigned long flags;
spin_lock_irqsave(&adapter->stats_lock, flags);
atl2_write_phy_reg(hw, MII_ADVERTISE, hw->mii_autoneg_adv_reg);
atl2_write_phy_reg(hw, MII_BMCR, MII_CR_RESET | MII_CR_AUTO_NEG_EN |
MII_CR_RESTART_AUTO_NEG);
spin_unlock_irqrestore(&adapter->stats_lock, flags);
clear_bit(0, &adapter->cfg_phy);
}
static int atl2_up(struct atl2_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int err = 0;
u32 val;
err = atl2_init_hw(&adapter->hw);
if (err) {
err = -EIO;
return err;
}
atl2_set_multi(netdev);
init_ring_ptrs(adapter);
atl2_restore_vlan(adapter);
if (atl2_configure(adapter)) {
err = -EIO;
goto err_up;
}
clear_bit(__ATL2_DOWN, &adapter->flags);
val = ATL2_READ_REG(&adapter->hw, REG_MASTER_CTRL);
ATL2_WRITE_REG(&adapter->hw, REG_MASTER_CTRL, val |
MASTER_CTRL_MANUAL_INT);
atl2_irq_enable(adapter);
err_up:
return err;
}
static void atl2_reinit_locked(struct atl2_adapter *adapter)
{
WARN_ON(in_interrupt());
while (test_and_set_bit(__ATL2_RESETTING, &adapter->flags))
msleep(1);
atl2_down(adapter);
atl2_up(adapter);
clear_bit(__ATL2_RESETTING, &adapter->flags);
}
static void atl2_reset_task(struct work_struct *work)
{
struct atl2_adapter *adapter;
adapter = container_of(work, struct atl2_adapter, reset_task);
atl2_reinit_locked(adapter);
}
static void atl2_setup_mac_ctrl(struct atl2_adapter *adapter)
{
u32 value;
struct atl2_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
value = MAC_CTRL_TX_EN | MAC_CTRL_RX_EN | MAC_CTRL_MACLP_CLK_PHY;
if (FULL_DUPLEX == adapter->link_duplex)
value |= MAC_CTRL_DUPLX;
value |= (MAC_CTRL_TX_FLOW | MAC_CTRL_RX_FLOW);
value |= (MAC_CTRL_ADD_CRC | MAC_CTRL_PAD);
value |= (((u32)adapter->hw.preamble_len & MAC_CTRL_PRMLEN_MASK) <<
MAC_CTRL_PRMLEN_SHIFT);
__atl2_vlan_mode(netdev->features, &value);
value |= MAC_CTRL_BC_EN;
if (netdev->flags & IFF_PROMISC)
value |= MAC_CTRL_PROMIS_EN;
else if (netdev->flags & IFF_ALLMULTI)
value |= MAC_CTRL_MC_ALL_EN;
value |= (((u32)(adapter->hw.retry_buf &
MAC_CTRL_HALF_LEFT_BUF_MASK)) << MAC_CTRL_HALF_LEFT_BUF_SHIFT);
ATL2_WRITE_REG(hw, REG_MAC_CTRL, value);
}
static int atl2_check_link(struct atl2_adapter *adapter)
{
struct atl2_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
int ret_val;
u16 speed, duplex, phy_data;
int reconfig = 0;
atl2_read_phy_reg(hw, MII_BMSR, &phy_data);
atl2_read_phy_reg(hw, MII_BMSR, &phy_data);
if (!(phy_data&BMSR_LSTATUS)) {
if (netif_carrier_ok(netdev)) {
u32 value;
value = ATL2_READ_REG(hw, REG_MAC_CTRL);
value &= ~MAC_CTRL_RX_EN;
ATL2_WRITE_REG(hw, REG_MAC_CTRL, value);
adapter->link_speed = SPEED_0;
netif_carrier_off(netdev);
netif_stop_queue(netdev);
}
return 0;
}
ret_val = atl2_get_speed_and_duplex(hw, &speed, &duplex);
if (ret_val)
return ret_val;
switch (hw->MediaType) {
case MEDIA_TYPE_100M_FULL:
if (speed != SPEED_100 || duplex != FULL_DUPLEX)
reconfig = 1;
break;
case MEDIA_TYPE_100M_HALF:
if (speed != SPEED_100 || duplex != HALF_DUPLEX)
reconfig = 1;
break;
case MEDIA_TYPE_10M_FULL:
if (speed != SPEED_10 || duplex != FULL_DUPLEX)
reconfig = 1;
break;
case MEDIA_TYPE_10M_HALF:
if (speed != SPEED_10 || duplex != HALF_DUPLEX)
reconfig = 1;
break;
}
if (reconfig == 0) {
if (adapter->link_speed != speed ||
adapter->link_duplex != duplex) {
adapter->link_speed = speed;
adapter->link_duplex = duplex;
atl2_setup_mac_ctrl(adapter);
printk(KERN_INFO "%s: %s NIC Link is Up<%d Mbps %s>\n",
atl2_driver_name, netdev->name,
adapter->link_speed,
adapter->link_duplex == FULL_DUPLEX ?
"Full Duplex" : "Half Duplex");
}
if (!netif_carrier_ok(netdev)) {
netif_carrier_on(netdev);
netif_wake_queue(netdev);
}
return 0;
}
if (netif_carrier_ok(netdev)) {
u32 value;
value = ATL2_READ_REG(hw, REG_MAC_CTRL);
value &= ~MAC_CTRL_RX_EN;
ATL2_WRITE_REG(hw, REG_MAC_CTRL, value);
adapter->link_speed = SPEED_0;
netif_carrier_off(netdev);
netif_stop_queue(netdev);
}
if (!test_bit(__ATL2_DOWN, &adapter->flags)) {
if (!test_and_set_bit(0, &adapter->cfg_phy))
mod_timer(&adapter->phy_config_timer,
round_jiffies(jiffies + 5 * HZ));
}
return 0;
}
static void atl2_link_chg_task(struct work_struct *work)
{
struct atl2_adapter *adapter;
unsigned long flags;
adapter = container_of(work, struct atl2_adapter, link_chg_task);
spin_lock_irqsave(&adapter->stats_lock, flags);
atl2_check_link(adapter);
spin_unlock_irqrestore(&adapter->stats_lock, flags);
}
static void atl2_setup_pcicmd(struct pci_dev *pdev)
{
u16 cmd;
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
if (cmd & PCI_COMMAND_INTX_DISABLE)
cmd &= ~PCI_COMMAND_INTX_DISABLE;
if (cmd & PCI_COMMAND_IO)
cmd &= ~PCI_COMMAND_IO;
if (0 == (cmd & PCI_COMMAND_MEMORY))
cmd |= PCI_COMMAND_MEMORY;
if (0 == (cmd & PCI_COMMAND_MASTER))
cmd |= PCI_COMMAND_MASTER;
pci_write_config_word(pdev, PCI_COMMAND, cmd);
pci_write_config_dword(pdev, REG_PM_CTRLSTAT, 0);
}
static void atl2_poll_controller(struct net_device *netdev)
{
disable_irq(netdev->irq);
atl2_intr(netdev->irq, netdev);
enable_irq(netdev->irq);
}
static int atl2_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct atl2_adapter *adapter;
static int cards_found;
unsigned long mmio_start;
int mmio_len;
int err;
cards_found = 0;
err = pci_enable_device(pdev);
if (err)
return err;
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32)) &&
pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32))) {
printk(KERN_ERR "atl2: No usable DMA configuration, aborting\n");
goto err_dma;
}
err = pci_request_regions(pdev, atl2_driver_name);
if (err)
goto err_pci_reg;
pci_set_master(pdev);
err = -ENOMEM;
netdev = alloc_etherdev(sizeof(struct atl2_adapter));
if (!netdev)
goto err_alloc_etherdev;
SET_NETDEV_DEV(netdev, &pdev->dev);
pci_set_drvdata(pdev, netdev);
adapter = netdev_priv(netdev);
adapter->netdev = netdev;
adapter->pdev = pdev;
adapter->hw.back = adapter;
mmio_start = pci_resource_start(pdev, 0x0);
mmio_len = pci_resource_len(pdev, 0x0);
adapter->hw.mem_rang = (u32)mmio_len;
adapter->hw.hw_addr = ioremap(mmio_start, mmio_len);
if (!adapter->hw.hw_addr) {
err = -EIO;
goto err_ioremap;
}
atl2_setup_pcicmd(pdev);
netdev->netdev_ops = &atl2_netdev_ops;
netdev->ethtool_ops = &atl2_ethtool_ops;
netdev->watchdog_timeo = 5 * HZ;
strncpy(netdev->name, pci_name(pdev), sizeof(netdev->name) - 1);
netdev->mem_start = mmio_start;
netdev->mem_end = mmio_start + mmio_len;
adapter->bd_number = cards_found;
adapter->pci_using_64 = false;
err = atl2_sw_init(adapter);
if (err)
goto err_sw_init;
err = -EIO;
netdev->hw_features = NETIF_F_HW_VLAN_CTAG_RX;
netdev->features |= (NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX);
atl2_phy_init(&adapter->hw);
if (atl2_reset_hw(&adapter->hw)) {
err = -EIO;
goto err_reset;
}
atl2_read_mac_addr(&adapter->hw);
memcpy(netdev->dev_addr, adapter->hw.mac_addr, netdev->addr_len);
if (!is_valid_ether_addr(netdev->dev_addr)) {
err = -EIO;
goto err_eeprom;
}
atl2_check_options(adapter);
setup_timer(&adapter->watchdog_timer, atl2_watchdog,
(unsigned long)adapter);
setup_timer(&adapter->phy_config_timer, atl2_phy_config,
(unsigned long)adapter);
INIT_WORK(&adapter->reset_task, atl2_reset_task);
INIT_WORK(&adapter->link_chg_task, atl2_link_chg_task);
strcpy(netdev->name, "eth%d");
err = register_netdev(netdev);
if (err)
goto err_register;
netif_carrier_off(netdev);
netif_stop_queue(netdev);
cards_found++;
return 0;
err_reset:
err_register:
err_sw_init:
err_eeprom:
iounmap(adapter->hw.hw_addr);
err_ioremap:
free_netdev(netdev);
err_alloc_etherdev:
pci_release_regions(pdev);
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static void atl2_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl2_adapter *adapter = netdev_priv(netdev);
set_bit(__ATL2_DOWN, &adapter->flags);
del_timer_sync(&adapter->watchdog_timer);
del_timer_sync(&adapter->phy_config_timer);
cancel_work_sync(&adapter->reset_task);
cancel_work_sync(&adapter->link_chg_task);
unregister_netdev(netdev);
atl2_force_ps(&adapter->hw);
iounmap(adapter->hw.hw_addr);
pci_release_regions(pdev);
free_netdev(netdev);
pci_disable_device(pdev);
}
static int atl2_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl2_adapter *adapter = netdev_priv(netdev);
struct atl2_hw *hw = &adapter->hw;
u16 speed, duplex;
u32 ctrl = 0;
u32 wufc = adapter->wol;
#ifdef CONFIG_PM
int retval = 0;
#endif
netif_device_detach(netdev);
if (netif_running(netdev)) {
WARN_ON(test_bit(__ATL2_RESETTING, &adapter->flags));
atl2_down(adapter);
}
#ifdef CONFIG_PM
retval = pci_save_state(pdev);
if (retval)
return retval;
#endif
atl2_read_phy_reg(hw, MII_BMSR, (u16 *)&ctrl);
atl2_read_phy_reg(hw, MII_BMSR, (u16 *)&ctrl);
if (ctrl & BMSR_LSTATUS)
wufc &= ~ATLX_WUFC_LNKC;
if (0 != (ctrl & BMSR_LSTATUS) && 0 != wufc) {
u32 ret_val;
ret_val = atl2_get_speed_and_duplex(hw, &speed, &duplex);
if (ret_val) {
printk(KERN_DEBUG
"%s: get speed&duplex error while suspend\n",
atl2_driver_name);
goto wol_dis;
}
ctrl = 0;
if (wufc & ATLX_WUFC_MAG)
ctrl |= (WOL_MAGIC_EN | WOL_MAGIC_PME_EN);
ATL2_WRITE_REG(hw, REG_WOL_CTRL, ctrl);
ctrl = MAC_CTRL_RX_EN | MAC_CTRL_MACLP_CLK_PHY;
if (FULL_DUPLEX == adapter->link_duplex)
ctrl |= MAC_CTRL_DUPLX;
ctrl |= (MAC_CTRL_ADD_CRC | MAC_CTRL_PAD);
ctrl |= (((u32)adapter->hw.preamble_len &
MAC_CTRL_PRMLEN_MASK) << MAC_CTRL_PRMLEN_SHIFT);
ctrl |= (((u32)(adapter->hw.retry_buf &
MAC_CTRL_HALF_LEFT_BUF_MASK)) <<
MAC_CTRL_HALF_LEFT_BUF_SHIFT);
if (wufc & ATLX_WUFC_MAG) {
ctrl |= MAC_CTRL_BC_EN;
}
ATL2_WRITE_REG(hw, REG_MAC_CTRL, ctrl);
ctrl = ATL2_READ_REG(hw, REG_PCIE_PHYMISC);
ctrl |= PCIE_PHYMISC_FORCE_RCV_DET;
ATL2_WRITE_REG(hw, REG_PCIE_PHYMISC, ctrl);
ctrl = ATL2_READ_REG(hw, REG_PCIE_DLL_TX_CTRL1);
ctrl |= PCIE_DLL_TX_CTRL1_SEL_NOR_CLK;
ATL2_WRITE_REG(hw, REG_PCIE_DLL_TX_CTRL1, ctrl);
pci_enable_wake(pdev, pci_choose_state(pdev, state), 1);
goto suspend_exit;
}
if (0 == (ctrl&BMSR_LSTATUS) && 0 != (wufc&ATLX_WUFC_LNKC)) {
ctrl |= (WOL_LINK_CHG_EN | WOL_LINK_CHG_PME_EN);
ATL2_WRITE_REG(hw, REG_WOL_CTRL, ctrl);
ATL2_WRITE_REG(hw, REG_MAC_CTRL, 0);
ctrl = ATL2_READ_REG(hw, REG_PCIE_PHYMISC);
ctrl |= PCIE_PHYMISC_FORCE_RCV_DET;
ATL2_WRITE_REG(hw, REG_PCIE_PHYMISC, ctrl);
ctrl = ATL2_READ_REG(hw, REG_PCIE_DLL_TX_CTRL1);
ctrl |= PCIE_DLL_TX_CTRL1_SEL_NOR_CLK;
ATL2_WRITE_REG(hw, REG_PCIE_DLL_TX_CTRL1, ctrl);
hw->phy_configured = false;
pci_enable_wake(pdev, pci_choose_state(pdev, state), 1);
goto suspend_exit;
}
wol_dis:
ATL2_WRITE_REG(hw, REG_WOL_CTRL, 0);
ctrl = ATL2_READ_REG(hw, REG_PCIE_PHYMISC);
ctrl |= PCIE_PHYMISC_FORCE_RCV_DET;
ATL2_WRITE_REG(hw, REG_PCIE_PHYMISC, ctrl);
ctrl = ATL2_READ_REG(hw, REG_PCIE_DLL_TX_CTRL1);
ctrl |= PCIE_DLL_TX_CTRL1_SEL_NOR_CLK;
ATL2_WRITE_REG(hw, REG_PCIE_DLL_TX_CTRL1, ctrl);
atl2_force_ps(hw);
hw->phy_configured = false;
pci_enable_wake(pdev, pci_choose_state(pdev, state), 0);
suspend_exit:
if (netif_running(netdev))
atl2_free_irq(adapter);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int atl2_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl2_adapter *adapter = netdev_priv(netdev);
u32 err;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
err = pci_enable_device(pdev);
if (err) {
printk(KERN_ERR
"atl2: Cannot enable PCI device from suspend\n");
return err;
}
pci_set_master(pdev);
ATL2_READ_REG(&adapter->hw, REG_WOL_CTRL);
pci_enable_wake(pdev, PCI_D3hot, 0);
pci_enable_wake(pdev, PCI_D3cold, 0);
ATL2_WRITE_REG(&adapter->hw, REG_WOL_CTRL, 0);
if (netif_running(netdev)) {
err = atl2_request_irq(adapter);
if (err)
return err;
}
atl2_reset_hw(&adapter->hw);
if (netif_running(netdev))
atl2_up(adapter);
netif_device_attach(netdev);
return 0;
}
static void atl2_shutdown(struct pci_dev *pdev)
{
atl2_suspend(pdev, PMSG_SUSPEND);
}
static int __init atl2_init_module(void)
{
printk(KERN_INFO "%s - version %s\n", atl2_driver_string,
atl2_driver_version);
printk(KERN_INFO "%s\n", atl2_copyright);
return pci_register_driver(&atl2_driver);
}
static void __exit atl2_exit_module(void)
{
pci_unregister_driver(&atl2_driver);
}
static void atl2_read_pci_cfg(struct atl2_hw *hw, u32 reg, u16 *value)
{
struct atl2_adapter *adapter = hw->back;
pci_read_config_word(adapter->pdev, reg, value);
}
static void atl2_write_pci_cfg(struct atl2_hw *hw, u32 reg, u16 *value)
{
struct atl2_adapter *adapter = hw->back;
pci_write_config_word(adapter->pdev, reg, *value);
}
static int atl2_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct atl2_hw *hw = &adapter->hw;
ecmd->supported = (SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full |
SUPPORTED_Autoneg |
SUPPORTED_TP);
ecmd->advertising = ADVERTISED_TP;
ecmd->advertising |= ADVERTISED_Autoneg;
ecmd->advertising |= hw->autoneg_advertised;
ecmd->port = PORT_TP;
ecmd->phy_address = 0;
ecmd->transceiver = XCVR_INTERNAL;
if (adapter->link_speed != SPEED_0) {
ethtool_cmd_speed_set(ecmd, adapter->link_speed);
if (adapter->link_duplex == FULL_DUPLEX)
ecmd->duplex = DUPLEX_FULL;
else
ecmd->duplex = DUPLEX_HALF;
} else {
ethtool_cmd_speed_set(ecmd, SPEED_UNKNOWN);
ecmd->duplex = DUPLEX_UNKNOWN;
}
ecmd->autoneg = AUTONEG_ENABLE;
return 0;
}
static int atl2_set_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct atl2_hw *hw = &adapter->hw;
while (test_and_set_bit(__ATL2_RESETTING, &adapter->flags))
msleep(1);
if (ecmd->autoneg == AUTONEG_ENABLE) {
#define MY_ADV_MASK (ADVERTISE_10_HALF | \
ADVERTISE_10_FULL | \
ADVERTISE_100_HALF| \
ADVERTISE_100_FULL)
if ((ecmd->advertising & MY_ADV_MASK) == MY_ADV_MASK) {
hw->MediaType = MEDIA_TYPE_AUTO_SENSOR;
hw->autoneg_advertised = MY_ADV_MASK;
} else if ((ecmd->advertising & MY_ADV_MASK) ==
ADVERTISE_100_FULL) {
hw->MediaType = MEDIA_TYPE_100M_FULL;
hw->autoneg_advertised = ADVERTISE_100_FULL;
} else if ((ecmd->advertising & MY_ADV_MASK) ==
ADVERTISE_100_HALF) {
hw->MediaType = MEDIA_TYPE_100M_HALF;
hw->autoneg_advertised = ADVERTISE_100_HALF;
} else if ((ecmd->advertising & MY_ADV_MASK) ==
ADVERTISE_10_FULL) {
hw->MediaType = MEDIA_TYPE_10M_FULL;
hw->autoneg_advertised = ADVERTISE_10_FULL;
} else if ((ecmd->advertising & MY_ADV_MASK) ==
ADVERTISE_10_HALF) {
hw->MediaType = MEDIA_TYPE_10M_HALF;
hw->autoneg_advertised = ADVERTISE_10_HALF;
} else {
clear_bit(__ATL2_RESETTING, &adapter->flags);
return -EINVAL;
}
ecmd->advertising = hw->autoneg_advertised |
ADVERTISED_TP | ADVERTISED_Autoneg;
} else {
clear_bit(__ATL2_RESETTING, &adapter->flags);
return -EINVAL;
}
if (netif_running(adapter->netdev)) {
atl2_down(adapter);
atl2_up(adapter);
} else
atl2_reset_hw(&adapter->hw);
clear_bit(__ATL2_RESETTING, &adapter->flags);
return 0;
}
static u32 atl2_get_msglevel(struct net_device *netdev)
{
return 0;
}
static void atl2_set_msglevel(struct net_device *netdev, u32 data)
{
}
static int atl2_get_regs_len(struct net_device *netdev)
{
#define ATL2_REGS_LEN 42
return sizeof(u32) * ATL2_REGS_LEN;
}
static void atl2_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *p)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct atl2_hw *hw = &adapter->hw;
u32 *regs_buff = p;
u16 phy_data;
memset(p, 0, sizeof(u32) * ATL2_REGS_LEN);
regs->version = (1 << 24) | (hw->revision_id << 16) | hw->device_id;
regs_buff[0] = ATL2_READ_REG(hw, REG_VPD_CAP);
regs_buff[1] = ATL2_READ_REG(hw, REG_SPI_FLASH_CTRL);
regs_buff[2] = ATL2_READ_REG(hw, REG_SPI_FLASH_CONFIG);
regs_buff[3] = ATL2_READ_REG(hw, REG_TWSI_CTRL);
regs_buff[4] = ATL2_READ_REG(hw, REG_PCIE_DEV_MISC_CTRL);
regs_buff[5] = ATL2_READ_REG(hw, REG_MASTER_CTRL);
regs_buff[6] = ATL2_READ_REG(hw, REG_MANUAL_TIMER_INIT);
regs_buff[7] = ATL2_READ_REG(hw, REG_IRQ_MODU_TIMER_INIT);
regs_buff[8] = ATL2_READ_REG(hw, REG_PHY_ENABLE);
regs_buff[9] = ATL2_READ_REG(hw, REG_CMBDISDMA_TIMER);
regs_buff[10] = ATL2_READ_REG(hw, REG_IDLE_STATUS);
regs_buff[11] = ATL2_READ_REG(hw, REG_MDIO_CTRL);
regs_buff[12] = ATL2_READ_REG(hw, REG_SERDES_LOCK);
regs_buff[13] = ATL2_READ_REG(hw, REG_MAC_CTRL);
regs_buff[14] = ATL2_READ_REG(hw, REG_MAC_IPG_IFG);
regs_buff[15] = ATL2_READ_REG(hw, REG_MAC_STA_ADDR);
regs_buff[16] = ATL2_READ_REG(hw, REG_MAC_STA_ADDR+4);
regs_buff[17] = ATL2_READ_REG(hw, REG_RX_HASH_TABLE);
regs_buff[18] = ATL2_READ_REG(hw, REG_RX_HASH_TABLE+4);
regs_buff[19] = ATL2_READ_REG(hw, REG_MAC_HALF_DUPLX_CTRL);
regs_buff[20] = ATL2_READ_REG(hw, REG_MTU);
regs_buff[21] = ATL2_READ_REG(hw, REG_WOL_CTRL);
regs_buff[22] = ATL2_READ_REG(hw, REG_SRAM_TXRAM_END);
regs_buff[23] = ATL2_READ_REG(hw, REG_DESC_BASE_ADDR_HI);
regs_buff[24] = ATL2_READ_REG(hw, REG_TXD_BASE_ADDR_LO);
regs_buff[25] = ATL2_READ_REG(hw, REG_TXD_MEM_SIZE);
regs_buff[26] = ATL2_READ_REG(hw, REG_TXS_BASE_ADDR_LO);
regs_buff[27] = ATL2_READ_REG(hw, REG_TXS_MEM_SIZE);
regs_buff[28] = ATL2_READ_REG(hw, REG_RXD_BASE_ADDR_LO);
regs_buff[29] = ATL2_READ_REG(hw, REG_RXD_BUF_NUM);
regs_buff[30] = ATL2_READ_REG(hw, REG_DMAR);
regs_buff[31] = ATL2_READ_REG(hw, REG_TX_CUT_THRESH);
regs_buff[32] = ATL2_READ_REG(hw, REG_DMAW);
regs_buff[33] = ATL2_READ_REG(hw, REG_PAUSE_ON_TH);
regs_buff[34] = ATL2_READ_REG(hw, REG_PAUSE_OFF_TH);
regs_buff[35] = ATL2_READ_REG(hw, REG_MB_TXD_WR_IDX);
regs_buff[36] = ATL2_READ_REG(hw, REG_MB_RXD_RD_IDX);
regs_buff[38] = ATL2_READ_REG(hw, REG_ISR);
regs_buff[39] = ATL2_READ_REG(hw, REG_IMR);
atl2_read_phy_reg(hw, MII_BMCR, &phy_data);
regs_buff[40] = (u32)phy_data;
atl2_read_phy_reg(hw, MII_BMSR, &phy_data);
regs_buff[41] = (u32)phy_data;
}
static int atl2_get_eeprom_len(struct net_device *netdev)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
if (!atl2_check_eeprom_exist(&adapter->hw))
return 512;
else
return 0;
}
static int atl2_get_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct atl2_hw *hw = &adapter->hw;
u32 *eeprom_buff;
int first_dword, last_dword;
int ret_val = 0;
int i;
if (eeprom->len == 0)
return -EINVAL;
if (atl2_check_eeprom_exist(hw))
return -EINVAL;
eeprom->magic = hw->vendor_id | (hw->device_id << 16);
first_dword = eeprom->offset >> 2;
last_dword = (eeprom->offset + eeprom->len - 1) >> 2;
eeprom_buff = kmalloc(sizeof(u32) * (last_dword - first_dword + 1),
GFP_KERNEL);
if (!eeprom_buff)
return -ENOMEM;
for (i = first_dword; i < last_dword; i++) {
if (!atl2_read_eeprom(hw, i*4, &(eeprom_buff[i-first_dword]))) {
ret_val = -EIO;
goto free;
}
}
memcpy(bytes, (u8 *)eeprom_buff + (eeprom->offset & 3),
eeprom->len);
free:
kfree(eeprom_buff);
return ret_val;
}
static int atl2_set_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
struct atl2_hw *hw = &adapter->hw;
u32 *eeprom_buff;
u32 *ptr;
int max_len, first_dword, last_dword, ret_val = 0;
int i;
if (eeprom->len == 0)
return -EOPNOTSUPP;
if (eeprom->magic != (hw->vendor_id | (hw->device_id << 16)))
return -EFAULT;
max_len = 512;
first_dword = eeprom->offset >> 2;
last_dword = (eeprom->offset + eeprom->len - 1) >> 2;
eeprom_buff = kmalloc(max_len, GFP_KERNEL);
if (!eeprom_buff)
return -ENOMEM;
ptr = eeprom_buff;
if (eeprom->offset & 3) {
if (!atl2_read_eeprom(hw, first_dword*4, &(eeprom_buff[0]))) {
ret_val = -EIO;
goto out;
}
ptr++;
}
if (((eeprom->offset + eeprom->len) & 3)) {
if (!atl2_read_eeprom(hw, last_dword * 4,
&(eeprom_buff[last_dword - first_dword]))) {
ret_val = -EIO;
goto out;
}
}
memcpy(ptr, bytes, eeprom->len);
for (i = 0; i < last_dword - first_dword + 1; i++) {
if (!atl2_write_eeprom(hw, ((first_dword+i)*4), eeprom_buff[i])) {
ret_val = -EIO;
goto out;
}
}
out:
kfree(eeprom_buff);
return ret_val;
}
static void atl2_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
strlcpy(drvinfo->driver, atl2_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, atl2_driver_version,
sizeof(drvinfo->version));
strlcpy(drvinfo->fw_version, "L2", sizeof(drvinfo->fw_version));
strlcpy(drvinfo->bus_info, pci_name(adapter->pdev),
sizeof(drvinfo->bus_info));
}
static void atl2_get_wol(struct net_device *netdev,
struct ethtool_wolinfo *wol)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
wol->supported = WAKE_MAGIC;
wol->wolopts = 0;
if (adapter->wol & ATLX_WUFC_EX)
wol->wolopts |= WAKE_UCAST;
if (adapter->wol & ATLX_WUFC_MC)
wol->wolopts |= WAKE_MCAST;
if (adapter->wol & ATLX_WUFC_BC)
wol->wolopts |= WAKE_BCAST;
if (adapter->wol & ATLX_WUFC_MAG)
wol->wolopts |= WAKE_MAGIC;
if (adapter->wol & ATLX_WUFC_LNKC)
wol->wolopts |= WAKE_PHY;
}
static int atl2_set_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
if (wol->wolopts & (WAKE_ARP | WAKE_MAGICSECURE))
return -EOPNOTSUPP;
if (wol->wolopts & (WAKE_UCAST | WAKE_BCAST | WAKE_MCAST))
return -EOPNOTSUPP;
adapter->wol = 0;
if (wol->wolopts & WAKE_MAGIC)
adapter->wol |= ATLX_WUFC_MAG;
if (wol->wolopts & WAKE_PHY)
adapter->wol |= ATLX_WUFC_LNKC;
return 0;
}
static int atl2_nway_reset(struct net_device *netdev)
{
struct atl2_adapter *adapter = netdev_priv(netdev);
if (netif_running(netdev))
atl2_reinit_locked(adapter);
return 0;
}
static s32 atl2_reset_hw(struct atl2_hw *hw)
{
u32 icr;
u16 pci_cfg_cmd_word;
int i;
atl2_read_pci_cfg(hw, PCI_REG_COMMAND, &pci_cfg_cmd_word);
if ((pci_cfg_cmd_word &
(CMD_IO_SPACE|CMD_MEMORY_SPACE|CMD_BUS_MASTER)) !=
(CMD_IO_SPACE|CMD_MEMORY_SPACE|CMD_BUS_MASTER)) {
pci_cfg_cmd_word |=
(CMD_IO_SPACE|CMD_MEMORY_SPACE|CMD_BUS_MASTER);
atl2_write_pci_cfg(hw, PCI_REG_COMMAND, &pci_cfg_cmd_word);
}
ATL2_WRITE_REG(hw, REG_MASTER_CTRL, MASTER_CTRL_SOFT_RST);
wmb();
msleep(1);
for (i = 0; i < 10; i++) {
icr = ATL2_READ_REG(hw, REG_IDLE_STATUS);
if (!icr)
break;
msleep(1);
cpu_relax();
}
if (icr)
return icr;
return 0;
}
static bool atl2_spi_read(struct atl2_hw *hw, u32 addr, u32 *buf)
{
int i;
u32 value;
ATL2_WRITE_REG(hw, REG_SPI_DATA, 0);
ATL2_WRITE_REG(hw, REG_SPI_ADDR, addr);
value = SPI_FLASH_CTRL_WAIT_READY |
(CUSTOM_SPI_CS_SETUP & SPI_FLASH_CTRL_CS_SETUP_MASK) <<
SPI_FLASH_CTRL_CS_SETUP_SHIFT |
(CUSTOM_SPI_CLK_HI & SPI_FLASH_CTRL_CLK_HI_MASK) <<
SPI_FLASH_CTRL_CLK_HI_SHIFT |
(CUSTOM_SPI_CLK_LO & SPI_FLASH_CTRL_CLK_LO_MASK) <<
SPI_FLASH_CTRL_CLK_LO_SHIFT |
(CUSTOM_SPI_CS_HOLD & SPI_FLASH_CTRL_CS_HOLD_MASK) <<
SPI_FLASH_CTRL_CS_HOLD_SHIFT |
(CUSTOM_SPI_CS_HI & SPI_FLASH_CTRL_CS_HI_MASK) <<
SPI_FLASH_CTRL_CS_HI_SHIFT |
(0x1 & SPI_FLASH_CTRL_INS_MASK) << SPI_FLASH_CTRL_INS_SHIFT;
ATL2_WRITE_REG(hw, REG_SPI_FLASH_CTRL, value);
value |= SPI_FLASH_CTRL_START;
ATL2_WRITE_REG(hw, REG_SPI_FLASH_CTRL, value);
for (i = 0; i < 10; i++) {
msleep(1);
value = ATL2_READ_REG(hw, REG_SPI_FLASH_CTRL);
if (!(value & SPI_FLASH_CTRL_START))
break;
}
if (value & SPI_FLASH_CTRL_START)
return false;
*buf = ATL2_READ_REG(hw, REG_SPI_DATA);
return true;
}
static int get_permanent_address(struct atl2_hw *hw)
{
u32 Addr[2];
u32 i, Control;
u16 Register;
u8 EthAddr[ETH_ALEN];
bool KeyValid;
if (is_valid_ether_addr(hw->perm_mac_addr))
return 0;
Addr[0] = 0;
Addr[1] = 0;
if (!atl2_check_eeprom_exist(hw)) {
Register = 0;
KeyValid = false;
i = 0;
while (1) {
if (atl2_read_eeprom(hw, i + 0x100, &Control)) {
if (KeyValid) {
if (Register == REG_MAC_STA_ADDR)
Addr[0] = Control;
else if (Register ==
(REG_MAC_STA_ADDR + 4))
Addr[1] = Control;
KeyValid = false;
} else if ((Control & 0xff) == 0x5A) {
KeyValid = true;
Register = (u16) (Control >> 16);
} else {
break;
}
} else {
break;
}
i += 4;
}
*(u32 *) &EthAddr[2] = LONGSWAP(Addr[0]);
*(u16 *) &EthAddr[0] = SHORTSWAP(*(u16 *) &Addr[1]);
if (is_valid_ether_addr(EthAddr)) {
memcpy(hw->perm_mac_addr, EthAddr, ETH_ALEN);
return 0;
}
return 1;
}
Addr[0] = 0;
Addr[1] = 0;
Register = 0;
KeyValid = false;
i = 0;
while (1) {
if (atl2_spi_read(hw, i + 0x1f000, &Control)) {
if (KeyValid) {
if (Register == REG_MAC_STA_ADDR)
Addr[0] = Control;
else if (Register == (REG_MAC_STA_ADDR + 4))
Addr[1] = Control;
KeyValid = false;
} else if ((Control & 0xff) == 0x5A) {
KeyValid = true;
Register = (u16) (Control >> 16);
} else {
break;
}
} else {
break;
}
i += 4;
}
*(u32 *) &EthAddr[2] = LONGSWAP(Addr[0]);
*(u16 *) &EthAddr[0] = SHORTSWAP(*(u16 *)&Addr[1]);
if (is_valid_ether_addr(EthAddr)) {
memcpy(hw->perm_mac_addr, EthAddr, ETH_ALEN);
return 0;
}
Addr[0] = ATL2_READ_REG(hw, REG_MAC_STA_ADDR);
Addr[1] = ATL2_READ_REG(hw, REG_MAC_STA_ADDR + 4);
*(u32 *) &EthAddr[2] = LONGSWAP(Addr[0]);
*(u16 *) &EthAddr[0] = SHORTSWAP(*(u16 *) &Addr[1]);
if (is_valid_ether_addr(EthAddr)) {
memcpy(hw->perm_mac_addr, EthAddr, ETH_ALEN);
return 0;
}
return 1;
}
static s32 atl2_read_mac_addr(struct atl2_hw *hw)
{
if (get_permanent_address(hw)) {
hw->perm_mac_addr[0] = 0x00;
hw->perm_mac_addr[1] = 0x13;
hw->perm_mac_addr[2] = 0x74;
hw->perm_mac_addr[3] = 0x00;
hw->perm_mac_addr[4] = 0x5c;
hw->perm_mac_addr[5] = 0x38;
}
memcpy(hw->mac_addr, hw->perm_mac_addr, ETH_ALEN);
return 0;
}
static u32 atl2_hash_mc_addr(struct atl2_hw *hw, u8 *mc_addr)
{
u32 crc32, value;
int i;
value = 0;
crc32 = ether_crc_le(6, mc_addr);
for (i = 0; i < 32; i++)
value |= (((crc32 >> i) & 1) << (31 - i));
return value;
}
static void atl2_hash_set(struct atl2_hw *hw, u32 hash_value)
{
u32 hash_bit, hash_reg;
u32 mta;
hash_reg = (hash_value >> 31) & 0x1;
hash_bit = (hash_value >> 26) & 0x1F;
mta = ATL2_READ_REG_ARRAY(hw, REG_RX_HASH_TABLE, hash_reg);
mta |= (1 << hash_bit);
ATL2_WRITE_REG_ARRAY(hw, REG_RX_HASH_TABLE, hash_reg, mta);
}
static void atl2_init_pcie(struct atl2_hw *hw)
{
u32 value;
value = LTSSM_TEST_MODE_DEF;
ATL2_WRITE_REG(hw, REG_LTSSM_TEST_MODE, value);
value = PCIE_DLL_TX_CTRL1_DEF;
ATL2_WRITE_REG(hw, REG_PCIE_DLL_TX_CTRL1, value);
}
static void atl2_init_flash_opcode(struct atl2_hw *hw)
{
if (hw->flash_vendor >= ARRAY_SIZE(flash_table))
hw->flash_vendor = 0;
ATL2_WRITE_REGB(hw, REG_SPI_FLASH_OP_PROGRAM,
flash_table[hw->flash_vendor].cmdPROGRAM);
ATL2_WRITE_REGB(hw, REG_SPI_FLASH_OP_SC_ERASE,
flash_table[hw->flash_vendor].cmdSECTOR_ERASE);
ATL2_WRITE_REGB(hw, REG_SPI_FLASH_OP_CHIP_ERASE,
flash_table[hw->flash_vendor].cmdCHIP_ERASE);
ATL2_WRITE_REGB(hw, REG_SPI_FLASH_OP_RDID,
flash_table[hw->flash_vendor].cmdRDID);
ATL2_WRITE_REGB(hw, REG_SPI_FLASH_OP_WREN,
flash_table[hw->flash_vendor].cmdWREN);
ATL2_WRITE_REGB(hw, REG_SPI_FLASH_OP_RDSR,
flash_table[hw->flash_vendor].cmdRDSR);
ATL2_WRITE_REGB(hw, REG_SPI_FLASH_OP_WRSR,
flash_table[hw->flash_vendor].cmdWRSR);
ATL2_WRITE_REGB(hw, REG_SPI_FLASH_OP_READ,
flash_table[hw->flash_vendor].cmdREAD);
}
static s32 atl2_init_hw(struct atl2_hw *hw)
{
u32 ret_val = 0;
atl2_init_pcie(hw);
ATL2_WRITE_REG(hw, REG_RX_HASH_TABLE, 0);
ATL2_WRITE_REG_ARRAY(hw, REG_RX_HASH_TABLE, 1, 0);
atl2_init_flash_opcode(hw);
ret_val = atl2_phy_init(hw);
return ret_val;
}
static s32 atl2_get_speed_and_duplex(struct atl2_hw *hw, u16 *speed,
u16 *duplex)
{
s32 ret_val;
u16 phy_data;
ret_val = atl2_read_phy_reg(hw, MII_ATLX_PSSR, &phy_data);
if (ret_val)
return ret_val;
if (!(phy_data & MII_ATLX_PSSR_SPD_DPLX_RESOLVED))
return ATLX_ERR_PHY_RES;
switch (phy_data & MII_ATLX_PSSR_SPEED) {
case MII_ATLX_PSSR_100MBS:
*speed = SPEED_100;
break;
case MII_ATLX_PSSR_10MBS:
*speed = SPEED_10;
break;
default:
return ATLX_ERR_PHY_SPEED;
}
if (phy_data & MII_ATLX_PSSR_DPLX)
*duplex = FULL_DUPLEX;
else
*duplex = HALF_DUPLEX;
return 0;
}
static s32 atl2_read_phy_reg(struct atl2_hw *hw, u16 reg_addr, u16 *phy_data)
{
u32 val;
int i;
val = ((u32)(reg_addr & MDIO_REG_ADDR_MASK)) << MDIO_REG_ADDR_SHIFT |
MDIO_START |
MDIO_SUP_PREAMBLE |
MDIO_RW |
MDIO_CLK_25_4 << MDIO_CLK_SEL_SHIFT;
ATL2_WRITE_REG(hw, REG_MDIO_CTRL, val);
wmb();
for (i = 0; i < MDIO_WAIT_TIMES; i++) {
udelay(2);
val = ATL2_READ_REG(hw, REG_MDIO_CTRL);
if (!(val & (MDIO_START | MDIO_BUSY)))
break;
wmb();
}
if (!(val & (MDIO_START | MDIO_BUSY))) {
*phy_data = (u16)val;
return 0;
}
return ATLX_ERR_PHY;
}
static s32 atl2_write_phy_reg(struct atl2_hw *hw, u32 reg_addr, u16 phy_data)
{
int i;
u32 val;
val = ((u32)(phy_data & MDIO_DATA_MASK)) << MDIO_DATA_SHIFT |
(reg_addr & MDIO_REG_ADDR_MASK) << MDIO_REG_ADDR_SHIFT |
MDIO_SUP_PREAMBLE |
MDIO_START |
MDIO_CLK_25_4 << MDIO_CLK_SEL_SHIFT;
ATL2_WRITE_REG(hw, REG_MDIO_CTRL, val);
wmb();
for (i = 0; i < MDIO_WAIT_TIMES; i++) {
udelay(2);
val = ATL2_READ_REG(hw, REG_MDIO_CTRL);
if (!(val & (MDIO_START | MDIO_BUSY)))
break;
wmb();
}
if (!(val & (MDIO_START | MDIO_BUSY)))
return 0;
return ATLX_ERR_PHY;
}
static s32 atl2_phy_setup_autoneg_adv(struct atl2_hw *hw)
{
s32 ret_val;
s16 mii_autoneg_adv_reg;
mii_autoneg_adv_reg = MII_AR_DEFAULT_CAP_MASK;
mii_autoneg_adv_reg &= ~MII_AR_SPEED_MASK;
switch (hw->MediaType) {
case MEDIA_TYPE_AUTO_SENSOR:
mii_autoneg_adv_reg |=
(MII_AR_10T_HD_CAPS |
MII_AR_10T_FD_CAPS |
MII_AR_100TX_HD_CAPS|
MII_AR_100TX_FD_CAPS);
hw->autoneg_advertised =
ADVERTISE_10_HALF |
ADVERTISE_10_FULL |
ADVERTISE_100_HALF|
ADVERTISE_100_FULL;
break;
case MEDIA_TYPE_100M_FULL:
mii_autoneg_adv_reg |= MII_AR_100TX_FD_CAPS;
hw->autoneg_advertised = ADVERTISE_100_FULL;
break;
case MEDIA_TYPE_100M_HALF:
mii_autoneg_adv_reg |= MII_AR_100TX_HD_CAPS;
hw->autoneg_advertised = ADVERTISE_100_HALF;
break;
case MEDIA_TYPE_10M_FULL:
mii_autoneg_adv_reg |= MII_AR_10T_FD_CAPS;
hw->autoneg_advertised = ADVERTISE_10_FULL;
break;
default:
mii_autoneg_adv_reg |= MII_AR_10T_HD_CAPS;
hw->autoneg_advertised = ADVERTISE_10_HALF;
break;
}
mii_autoneg_adv_reg |= (MII_AR_ASM_DIR | MII_AR_PAUSE);
hw->mii_autoneg_adv_reg = mii_autoneg_adv_reg;
ret_val = atl2_write_phy_reg(hw, MII_ADVERTISE, mii_autoneg_adv_reg);
if (ret_val)
return ret_val;
return 0;
}
static s32 atl2_phy_commit(struct atl2_hw *hw)
{
s32 ret_val;
u16 phy_data;
phy_data = MII_CR_RESET | MII_CR_AUTO_NEG_EN | MII_CR_RESTART_AUTO_NEG;
ret_val = atl2_write_phy_reg(hw, MII_BMCR, phy_data);
if (ret_val) {
u32 val;
int i;
for (i = 0; i < 25; i++) {
msleep(1);
val = ATL2_READ_REG(hw, REG_MDIO_CTRL);
if (!(val & (MDIO_START | MDIO_BUSY)))
break;
}
if (0 != (val & (MDIO_START | MDIO_BUSY))) {
printk(KERN_ERR "atl2: PCIe link down for at least 25ms !\n");
return ret_val;
}
}
return 0;
}
static s32 atl2_phy_init(struct atl2_hw *hw)
{
s32 ret_val;
u16 phy_val;
if (hw->phy_configured)
return 0;
ATL2_WRITE_REGW(hw, REG_PHY_ENABLE, 1);
ATL2_WRITE_FLUSH(hw);
msleep(1);
atl2_write_phy_reg(hw, MII_DBG_ADDR, 0);
atl2_read_phy_reg(hw, MII_DBG_DATA, &phy_val);
if (phy_val & 0x1000) {
phy_val &= ~0x1000;
atl2_write_phy_reg(hw, MII_DBG_DATA, phy_val);
}
msleep(1);
ret_val = atl2_write_phy_reg(hw, 18, 0xC00);
if (ret_val)
return ret_val;
ret_val = atl2_phy_setup_autoneg_adv(hw);
if (ret_val)
return ret_val;
ret_val = atl2_phy_commit(hw);
if (ret_val)
return ret_val;
hw->phy_configured = true;
return ret_val;
}
static void atl2_set_mac_addr(struct atl2_hw *hw)
{
u32 value;
value = (((u32)hw->mac_addr[2]) << 24) |
(((u32)hw->mac_addr[3]) << 16) |
(((u32)hw->mac_addr[4]) << 8) |
(((u32)hw->mac_addr[5]));
ATL2_WRITE_REG_ARRAY(hw, REG_MAC_STA_ADDR, 0, value);
value = (((u32)hw->mac_addr[0]) << 8) |
(((u32)hw->mac_addr[1]));
ATL2_WRITE_REG_ARRAY(hw, REG_MAC_STA_ADDR, 1, value);
}
static int atl2_check_eeprom_exist(struct atl2_hw *hw)
{
u32 value;
value = ATL2_READ_REG(hw, REG_SPI_FLASH_CTRL);
if (value & SPI_FLASH_CTRL_EN_VPD) {
value &= ~SPI_FLASH_CTRL_EN_VPD;
ATL2_WRITE_REG(hw, REG_SPI_FLASH_CTRL, value);
}
value = ATL2_READ_REGW(hw, REG_PCIE_CAP_LIST);
return ((value & 0xFF00) == 0x6C00) ? 0 : 1;
}
static bool atl2_write_eeprom(struct atl2_hw *hw, u32 offset, u32 value)
{
return true;
}
static bool atl2_read_eeprom(struct atl2_hw *hw, u32 Offset, u32 *pValue)
{
int i;
u32 Control;
if (Offset & 0x3)
return false;
ATL2_WRITE_REG(hw, REG_VPD_DATA, 0);
Control = (Offset & VPD_CAP_VPD_ADDR_MASK) << VPD_CAP_VPD_ADDR_SHIFT;
ATL2_WRITE_REG(hw, REG_VPD_CAP, Control);
for (i = 0; i < 10; i++) {
msleep(2);
Control = ATL2_READ_REG(hw, REG_VPD_CAP);
if (Control & VPD_CAP_VPD_FLAG)
break;
}
if (Control & VPD_CAP_VPD_FLAG) {
*pValue = ATL2_READ_REG(hw, REG_VPD_DATA);
return true;
}
return false;
}
static void atl2_force_ps(struct atl2_hw *hw)
{
u16 phy_val;
atl2_write_phy_reg(hw, MII_DBG_ADDR, 0);
atl2_read_phy_reg(hw, MII_DBG_DATA, &phy_val);
atl2_write_phy_reg(hw, MII_DBG_DATA, phy_val | 0x1000);
atl2_write_phy_reg(hw, MII_DBG_ADDR, 2);
atl2_write_phy_reg(hw, MII_DBG_DATA, 0x3000);
atl2_write_phy_reg(hw, MII_DBG_ADDR, 3);
atl2_write_phy_reg(hw, MII_DBG_DATA, 0);
}
static int atl2_validate_option(int *value, struct atl2_option *opt)
{
int i;
struct atl2_opt_list *ent;
if (*value == OPTION_UNSET) {
*value = opt->def;
return 0;
}
switch (opt->type) {
case enable_option:
switch (*value) {
case OPTION_ENABLED:
printk(KERN_INFO "%s Enabled\n", opt->name);
return 0;
case OPTION_DISABLED:
printk(KERN_INFO "%s Disabled\n", opt->name);
return 0;
}
break;
case range_option:
if (*value >= opt->arg.r.min && *value <= opt->arg.r.max) {
printk(KERN_INFO "%s set to %i\n", opt->name, *value);
return 0;
}
break;
case list_option:
for (i = 0; i < opt->arg.l.nr; i++) {
ent = &opt->arg.l.p[i];
if (*value == ent->i) {
if (ent->str[0] != '\0')
printk(KERN_INFO "%s\n", ent->str);
return 0;
}
}
break;
default:
BUG();
}
printk(KERN_INFO "Invalid %s specified (%i) %s\n",
opt->name, *value, opt->err);
*value = opt->def;
return -1;
}
static void atl2_check_options(struct atl2_adapter *adapter)
{
int val;
struct atl2_option opt;
int bd = adapter->bd_number;
if (bd >= ATL2_MAX_NIC) {
printk(KERN_NOTICE "Warning: no configuration for board #%i\n",
bd);
printk(KERN_NOTICE "Using defaults for all values\n");
#ifndef module_param_array
bd = ATL2_MAX_NIC;
#endif
}
opt.type = range_option;
opt.name = "Bytes of Transmit Memory";
opt.err = "using default of " __MODULE_STRING(ATL2_DEFAULT_TX_MEMSIZE);
opt.def = ATL2_DEFAULT_TX_MEMSIZE;
opt.arg.r.min = ATL2_MIN_TX_MEMSIZE;
opt.arg.r.max = ATL2_MAX_TX_MEMSIZE;
#ifdef module_param_array
if (num_TxMemSize > bd) {
#endif
val = TxMemSize[bd];
atl2_validate_option(&val, &opt);
adapter->txd_ring_size = ((u32) val) * 1024;
#ifdef module_param_array
} else
adapter->txd_ring_size = ((u32)opt.def) * 1024;
#endif
adapter->txs_ring_size = adapter->txd_ring_size / 128;
if (adapter->txs_ring_size > 160)
adapter->txs_ring_size = 160;
opt.type = range_option;
opt.name = "Number of receive memory block";
opt.err = "using default of " __MODULE_STRING(ATL2_DEFAULT_RXD_COUNT);
opt.def = ATL2_DEFAULT_RXD_COUNT;
opt.arg.r.min = ATL2_MIN_RXD_COUNT;
opt.arg.r.max = ATL2_MAX_RXD_COUNT;
#ifdef module_param_array
if (num_RxMemBlock > bd) {
#endif
val = RxMemBlock[bd];
atl2_validate_option(&val, &opt);
adapter->rxd_ring_size = (u32)val;
#ifdef module_param_array
} else
adapter->rxd_ring_size = (u32)opt.def;
#endif
adapter->hw.fc_rxd_hi = (adapter->rxd_ring_size / 8) * 7;
adapter->hw.fc_rxd_lo = (ATL2_MIN_RXD_COUNT / 8) >
(adapter->rxd_ring_size / 12) ? (ATL2_MIN_RXD_COUNT / 8) :
(adapter->rxd_ring_size / 12);
opt.type = range_option;
opt.name = "Interrupt Moderate Timer";
opt.err = "using default of " __MODULE_STRING(INT_MOD_DEFAULT_CNT);
opt.def = INT_MOD_DEFAULT_CNT;
opt.arg.r.min = INT_MOD_MIN_CNT;
opt.arg.r.max = INT_MOD_MAX_CNT;
#ifdef module_param_array
if (num_IntModTimer > bd) {
#endif
val = IntModTimer[bd];
atl2_validate_option(&val, &opt);
adapter->imt = (u16) val;
#ifdef module_param_array
} else
adapter->imt = (u16)(opt.def);
#endif
opt.type = range_option;
opt.name = "SPI Flash Vendor";
opt.err = "using default of " __MODULE_STRING(FLASH_VENDOR_DEFAULT);
opt.def = FLASH_VENDOR_DEFAULT;
opt.arg.r.min = FLASH_VENDOR_MIN;
opt.arg.r.max = FLASH_VENDOR_MAX;
#ifdef module_param_array
if (num_FlashVendor > bd) {
#endif
val = FlashVendor[bd];
atl2_validate_option(&val, &opt);
adapter->hw.flash_vendor = (u8) val;
#ifdef module_param_array
} else
adapter->hw.flash_vendor = (u8)(opt.def);
#endif
opt.type = range_option;
opt.name = "Speed/Duplex Selection";
opt.err = "using default of " __MODULE_STRING(MEDIA_TYPE_AUTO_SENSOR);
opt.def = MEDIA_TYPE_AUTO_SENSOR;
opt.arg.r.min = MEDIA_TYPE_AUTO_SENSOR;
opt.arg.r.max = MEDIA_TYPE_10M_HALF;
#ifdef module_param_array
if (num_MediaType > bd) {
#endif
val = MediaType[bd];
atl2_validate_option(&val, &opt);
adapter->hw.MediaType = (u16) val;
#ifdef module_param_array
} else
adapter->hw.MediaType = (u16)(opt.def);
#endif
}
