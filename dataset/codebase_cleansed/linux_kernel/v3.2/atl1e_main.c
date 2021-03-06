static inline void atl1e_irq_enable(struct atl1e_adapter *adapter)
{
if (likely(atomic_dec_and_test(&adapter->irq_sem))) {
AT_WRITE_REG(&adapter->hw, REG_ISR, 0);
AT_WRITE_REG(&adapter->hw, REG_IMR, IMR_NORMAL_MASK);
AT_WRITE_FLUSH(&adapter->hw);
}
}
static inline void atl1e_irq_disable(struct atl1e_adapter *adapter)
{
atomic_inc(&adapter->irq_sem);
AT_WRITE_REG(&adapter->hw, REG_IMR, 0);
AT_WRITE_FLUSH(&adapter->hw);
synchronize_irq(adapter->pdev->irq);
}
static inline void atl1e_irq_reset(struct atl1e_adapter *adapter)
{
atomic_set(&adapter->irq_sem, 0);
AT_WRITE_REG(&adapter->hw, REG_ISR, 0);
AT_WRITE_REG(&adapter->hw, REG_IMR, 0);
AT_WRITE_FLUSH(&adapter->hw);
}
static void atl1e_phy_config(unsigned long data)
{
struct atl1e_adapter *adapter = (struct atl1e_adapter *) data;
struct atl1e_hw *hw = &adapter->hw;
unsigned long flags;
spin_lock_irqsave(&adapter->mdio_lock, flags);
atl1e_restart_autoneg(hw);
spin_unlock_irqrestore(&adapter->mdio_lock, flags);
}
void atl1e_reinit_locked(struct atl1e_adapter *adapter)
{
WARN_ON(in_interrupt());
while (test_and_set_bit(__AT_RESETTING, &adapter->flags))
msleep(1);
atl1e_down(adapter);
atl1e_up(adapter);
clear_bit(__AT_RESETTING, &adapter->flags);
}
static void atl1e_reset_task(struct work_struct *work)
{
struct atl1e_adapter *adapter;
adapter = container_of(work, struct atl1e_adapter, reset_task);
atl1e_reinit_locked(adapter);
}
static int atl1e_check_link(struct atl1e_adapter *adapter)
{
struct atl1e_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
int err = 0;
u16 speed, duplex, phy_data;
atl1e_read_phy_reg(hw, MII_BMSR, &phy_data);
atl1e_read_phy_reg(hw, MII_BMSR, &phy_data);
if ((phy_data & BMSR_LSTATUS) == 0) {
if (netif_carrier_ok(netdev)) {
u32 value;
value = AT_READ_REG(hw, REG_MAC_CTRL);
value &= ~MAC_CTRL_RX_EN;
AT_WRITE_REG(hw, REG_MAC_CTRL, value);
adapter->link_speed = SPEED_0;
netif_carrier_off(netdev);
netif_stop_queue(netdev);
}
} else {
err = atl1e_get_speed_and_duplex(hw, &speed, &duplex);
if (unlikely(err))
return err;
if (adapter->link_speed != speed ||
adapter->link_duplex != duplex) {
adapter->link_speed = speed;
adapter->link_duplex = duplex;
atl1e_setup_mac_ctrl(adapter);
netdev_info(netdev,
"NIC Link is Up <%d Mbps %s Duplex>\n",
adapter->link_speed,
adapter->link_duplex == FULL_DUPLEX ?
"Full" : "Half");
}
if (!netif_carrier_ok(netdev)) {
netif_carrier_on(netdev);
netif_wake_queue(netdev);
}
}
return 0;
}
static void atl1e_link_chg_task(struct work_struct *work)
{
struct atl1e_adapter *adapter;
unsigned long flags;
adapter = container_of(work, struct atl1e_adapter, link_chg_task);
spin_lock_irqsave(&adapter->mdio_lock, flags);
atl1e_check_link(adapter);
spin_unlock_irqrestore(&adapter->mdio_lock, flags);
}
static void atl1e_link_chg_event(struct atl1e_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
u16 phy_data = 0;
u16 link_up = 0;
spin_lock(&adapter->mdio_lock);
atl1e_read_phy_reg(&adapter->hw, MII_BMSR, &phy_data);
atl1e_read_phy_reg(&adapter->hw, MII_BMSR, &phy_data);
spin_unlock(&adapter->mdio_lock);
link_up = phy_data & BMSR_LSTATUS;
if (!link_up) {
if (netif_carrier_ok(netdev)) {
netdev_info(netdev, "NIC Link is Down\n");
adapter->link_speed = SPEED_0;
netif_stop_queue(netdev);
}
}
schedule_work(&adapter->link_chg_task);
}
static void atl1e_del_timer(struct atl1e_adapter *adapter)
{
del_timer_sync(&adapter->phy_config_timer);
}
static void atl1e_cancel_work(struct atl1e_adapter *adapter)
{
cancel_work_sync(&adapter->reset_task);
cancel_work_sync(&adapter->link_chg_task);
}
static void atl1e_tx_timeout(struct net_device *netdev)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
schedule_work(&adapter->reset_task);
}
static void atl1e_set_multi(struct net_device *netdev)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
struct atl1e_hw *hw = &adapter->hw;
struct netdev_hw_addr *ha;
u32 mac_ctrl_data = 0;
u32 hash_value;
mac_ctrl_data = AT_READ_REG(hw, REG_MAC_CTRL);
if (netdev->flags & IFF_PROMISC) {
mac_ctrl_data |= MAC_CTRL_PROMIS_EN;
} else if (netdev->flags & IFF_ALLMULTI) {
mac_ctrl_data |= MAC_CTRL_MC_ALL_EN;
mac_ctrl_data &= ~MAC_CTRL_PROMIS_EN;
} else {
mac_ctrl_data &= ~(MAC_CTRL_PROMIS_EN | MAC_CTRL_MC_ALL_EN);
}
AT_WRITE_REG(hw, REG_MAC_CTRL, mac_ctrl_data);
AT_WRITE_REG(hw, REG_RX_HASH_TABLE, 0);
AT_WRITE_REG_ARRAY(hw, REG_RX_HASH_TABLE, 1, 0);
netdev_for_each_mc_addr(ha, netdev) {
hash_value = atl1e_hash_mc_addr(hw, ha->addr);
atl1e_hash_set(hw, hash_value);
}
}
static void __atl1e_vlan_mode(u32 features, u32 *mac_ctrl_data)
{
if (features & NETIF_F_HW_VLAN_RX) {
*mac_ctrl_data |= MAC_CTRL_RMV_VLAN;
} else {
*mac_ctrl_data &= ~MAC_CTRL_RMV_VLAN;
}
}
static void atl1e_vlan_mode(struct net_device *netdev, u32 features)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
u32 mac_ctrl_data = 0;
netdev_dbg(adapter->netdev, "%s\n", __func__);
atl1e_irq_disable(adapter);
mac_ctrl_data = AT_READ_REG(&adapter->hw, REG_MAC_CTRL);
__atl1e_vlan_mode(features, &mac_ctrl_data);
AT_WRITE_REG(&adapter->hw, REG_MAC_CTRL, mac_ctrl_data);
atl1e_irq_enable(adapter);
}
static void atl1e_restore_vlan(struct atl1e_adapter *adapter)
{
netdev_dbg(adapter->netdev, "%s\n", __func__);
atl1e_vlan_mode(adapter->netdev, adapter->netdev->features);
}
static int atl1e_set_mac_addr(struct net_device *netdev, void *p)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
if (netif_running(netdev))
return -EBUSY;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
memcpy(adapter->hw.mac_addr, addr->sa_data, netdev->addr_len);
atl1e_hw_set_mac_addr(&adapter->hw);
return 0;
}
static u32 atl1e_fix_features(struct net_device *netdev, u32 features)
{
if (features & NETIF_F_HW_VLAN_RX)
features |= NETIF_F_HW_VLAN_TX;
else
features &= ~NETIF_F_HW_VLAN_TX;
return features;
}
static int atl1e_set_features(struct net_device *netdev, u32 features)
{
u32 changed = netdev->features ^ features;
if (changed & NETIF_F_HW_VLAN_RX)
atl1e_vlan_mode(netdev, features);
return 0;
}
static int atl1e_change_mtu(struct net_device *netdev, int new_mtu)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
int old_mtu = netdev->mtu;
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN;
if ((max_frame < ETH_ZLEN + ETH_FCS_LEN) ||
(max_frame > MAX_JUMBO_FRAME_SIZE)) {
netdev_warn(adapter->netdev, "invalid MTU setting\n");
return -EINVAL;
}
if (old_mtu != new_mtu && netif_running(netdev)) {
while (test_and_set_bit(__AT_RESETTING, &adapter->flags))
msleep(1);
netdev->mtu = new_mtu;
adapter->hw.max_frame_size = new_mtu;
adapter->hw.rx_jumbo_th = (max_frame + 7) >> 3;
atl1e_down(adapter);
atl1e_up(adapter);
clear_bit(__AT_RESETTING, &adapter->flags);
}
return 0;
}
static int atl1e_mdio_read(struct net_device *netdev, int phy_id, int reg_num)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
u16 result;
atl1e_read_phy_reg(&adapter->hw, reg_num & MDIO_REG_ADDR_MASK, &result);
return result;
}
static void atl1e_mdio_write(struct net_device *netdev, int phy_id,
int reg_num, int val)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
atl1e_write_phy_reg(&adapter->hw, reg_num & MDIO_REG_ADDR_MASK, val);
}
static int atl1e_mii_ioctl(struct net_device *netdev,
struct ifreq *ifr, int cmd)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
struct mii_ioctl_data *data = if_mii(ifr);
unsigned long flags;
int retval = 0;
if (!netif_running(netdev))
return -EINVAL;
spin_lock_irqsave(&adapter->mdio_lock, flags);
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = 0;
break;
case SIOCGMIIREG:
if (atl1e_read_phy_reg(&adapter->hw, data->reg_num & 0x1F,
&data->val_out)) {
retval = -EIO;
goto out;
}
break;
case SIOCSMIIREG:
if (data->reg_num & ~(0x1F)) {
retval = -EFAULT;
goto out;
}
netdev_dbg(adapter->netdev, "<atl1e_mii_ioctl> write %x %x\n",
data->reg_num, data->val_in);
if (atl1e_write_phy_reg(&adapter->hw,
data->reg_num, data->val_in)) {
retval = -EIO;
goto out;
}
break;
default:
retval = -EOPNOTSUPP;
break;
}
out:
spin_unlock_irqrestore(&adapter->mdio_lock, flags);
return retval;
}
static int atl1e_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
return atl1e_mii_ioctl(netdev, ifr, cmd);
default:
return -EOPNOTSUPP;
}
}
static void atl1e_setup_pcicmd(struct pci_dev *pdev)
{
u16 cmd;
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
cmd &= ~(PCI_COMMAND_INTX_DISABLE | PCI_COMMAND_IO);
cmd |= (PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER);
pci_write_config_word(pdev, PCI_COMMAND, cmd);
pci_write_config_dword(pdev, REG_PM_CTRLSTAT, 0);
msleep(1);
}
static int __devinit atl1e_alloc_queues(struct atl1e_adapter *adapter)
{
return 0;
}
static int __devinit atl1e_sw_init(struct atl1e_adapter *adapter)
{
struct atl1e_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
u32 phy_status_data = 0;
adapter->wol = 0;
adapter->link_speed = SPEED_0;
adapter->link_duplex = FULL_DUPLEX;
adapter->num_rx_queues = 1;
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_id = pdev->subsystem_device;
hw->revision_id = pdev->revision;
pci_read_config_word(pdev, PCI_COMMAND, &hw->pci_cmd_word);
phy_status_data = AT_READ_REG(hw, REG_PHY_STATUS);
if (hw->revision_id >= 0xF0) {
hw->nic_type = athr_l2e_revB;
} else {
if (phy_status_data & PHY_STATUS_100M)
hw->nic_type = athr_l1e;
else
hw->nic_type = athr_l2e_revA;
}
phy_status_data = AT_READ_REG(hw, REG_PHY_STATUS);
if (phy_status_data & PHY_STATUS_EMI_CA)
hw->emi_ca = true;
else
hw->emi_ca = false;
hw->phy_configured = false;
hw->preamble_len = 7;
hw->max_frame_size = adapter->netdev->mtu;
hw->rx_jumbo_th = (hw->max_frame_size + ETH_HLEN +
VLAN_HLEN + ETH_FCS_LEN + 7) >> 3;
hw->rrs_type = atl1e_rrs_disable;
hw->indirect_tab = 0;
hw->base_cpu = 0;
hw->ict = 50000;
hw->smb_timer = 200000;
hw->tpd_burst = 5;
hw->rrd_thresh = 1;
hw->tpd_thresh = adapter->tx_ring.count / 2;
hw->rx_count_down = 4;
hw->tx_count_down = hw->imt * 4 / 3;
hw->dmar_block = atl1e_dma_req_1024;
hw->dmaw_block = atl1e_dma_req_1024;
hw->dmar_dly_cnt = 15;
hw->dmaw_dly_cnt = 4;
if (atl1e_alloc_queues(adapter)) {
netdev_err(adapter->netdev, "Unable to allocate memory for queues\n");
return -ENOMEM;
}
atomic_set(&adapter->irq_sem, 1);
spin_lock_init(&adapter->mdio_lock);
spin_lock_init(&adapter->tx_lock);
set_bit(__AT_DOWN, &adapter->flags);
return 0;
}
static void atl1e_clean_tx_ring(struct atl1e_adapter *adapter)
{
struct atl1e_tx_ring *tx_ring = (struct atl1e_tx_ring *)
&adapter->tx_ring;
struct atl1e_tx_buffer *tx_buffer = NULL;
struct pci_dev *pdev = adapter->pdev;
u16 index, ring_count;
if (tx_ring->desc == NULL || tx_ring->tx_buffer == NULL)
return;
ring_count = tx_ring->count;
for (index = 0; index < ring_count; index++) {
tx_buffer = &tx_ring->tx_buffer[index];
if (tx_buffer->dma) {
if (tx_buffer->flags & ATL1E_TX_PCIMAP_SINGLE)
pci_unmap_single(pdev, tx_buffer->dma,
tx_buffer->length, PCI_DMA_TODEVICE);
else if (tx_buffer->flags & ATL1E_TX_PCIMAP_PAGE)
pci_unmap_page(pdev, tx_buffer->dma,
tx_buffer->length, PCI_DMA_TODEVICE);
tx_buffer->dma = 0;
}
}
for (index = 0; index < ring_count; index++) {
tx_buffer = &tx_ring->tx_buffer[index];
if (tx_buffer->skb) {
dev_kfree_skb_any(tx_buffer->skb);
tx_buffer->skb = NULL;
}
}
memset(tx_ring->desc, 0, sizeof(struct atl1e_tpd_desc) *
ring_count);
memset(tx_ring->tx_buffer, 0, sizeof(struct atl1e_tx_buffer) *
ring_count);
}
static void atl1e_clean_rx_ring(struct atl1e_adapter *adapter)
{
struct atl1e_rx_ring *rx_ring =
(struct atl1e_rx_ring *)&adapter->rx_ring;
struct atl1e_rx_page_desc *rx_page_desc = rx_ring->rx_page_desc;
u16 i, j;
if (adapter->ring_vir_addr == NULL)
return;
for (i = 0; i < adapter->num_rx_queues; i++) {
for (j = 0; j < AT_PAGE_NUM_PER_QUEUE; j++) {
if (rx_page_desc[i].rx_page[j].addr != NULL) {
memset(rx_page_desc[i].rx_page[j].addr, 0,
rx_ring->real_page_size);
}
}
}
}
static void atl1e_cal_ring_size(struct atl1e_adapter *adapter, u32 *ring_size)
{
*ring_size = ((u32)(adapter->tx_ring.count *
sizeof(struct atl1e_tpd_desc) + 7
+ adapter->rx_ring.real_page_size * AT_PAGE_NUM_PER_QUEUE *
adapter->num_rx_queues + 31
+ (1 + AT_PAGE_NUM_PER_QUEUE * adapter->num_rx_queues) *
sizeof(u32) + 3));
}
static void atl1e_init_ring_resources(struct atl1e_adapter *adapter)
{
struct atl1e_rx_ring *rx_ring = NULL;
rx_ring = &adapter->rx_ring;
rx_ring->real_page_size = adapter->rx_ring.page_size
+ adapter->hw.max_frame_size
+ ETH_HLEN + VLAN_HLEN
+ ETH_FCS_LEN;
rx_ring->real_page_size = roundup(rx_ring->real_page_size, 32);
atl1e_cal_ring_size(adapter, &adapter->ring_size);
adapter->ring_vir_addr = NULL;
adapter->rx_ring.desc = NULL;
rwlock_init(&adapter->tx_ring.tx_lock);
}
static void atl1e_init_ring_ptrs(struct atl1e_adapter *adapter)
{
struct atl1e_tx_ring *tx_ring = NULL;
struct atl1e_rx_ring *rx_ring = NULL;
struct atl1e_rx_page_desc *rx_page_desc = NULL;
int i, j;
tx_ring = &adapter->tx_ring;
rx_ring = &adapter->rx_ring;
rx_page_desc = rx_ring->rx_page_desc;
tx_ring->next_to_use = 0;
atomic_set(&tx_ring->next_to_clean, 0);
for (i = 0; i < adapter->num_rx_queues; i++) {
rx_page_desc[i].rx_using = 0;
rx_page_desc[i].rx_nxseq = 0;
for (j = 0; j < AT_PAGE_NUM_PER_QUEUE; j++) {
*rx_page_desc[i].rx_page[j].write_offset_addr = 0;
rx_page_desc[i].rx_page[j].read_offset = 0;
}
}
}
static void atl1e_free_ring_resources(struct atl1e_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
atl1e_clean_tx_ring(adapter);
atl1e_clean_rx_ring(adapter);
if (adapter->ring_vir_addr) {
pci_free_consistent(pdev, adapter->ring_size,
adapter->ring_vir_addr, adapter->ring_dma);
adapter->ring_vir_addr = NULL;
}
if (adapter->tx_ring.tx_buffer) {
kfree(adapter->tx_ring.tx_buffer);
adapter->tx_ring.tx_buffer = NULL;
}
}
static int atl1e_setup_ring_resources(struct atl1e_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
struct atl1e_tx_ring *tx_ring;
struct atl1e_rx_ring *rx_ring;
struct atl1e_rx_page_desc *rx_page_desc;
int size, i, j;
u32 offset = 0;
int err = 0;
if (adapter->ring_vir_addr != NULL)
return 0;
tx_ring = &adapter->tx_ring;
rx_ring = &adapter->rx_ring;
size = adapter->ring_size;
adapter->ring_vir_addr = pci_alloc_consistent(pdev,
adapter->ring_size, &adapter->ring_dma);
if (adapter->ring_vir_addr == NULL) {
netdev_err(adapter->netdev,
"pci_alloc_consistent failed, size = D%d\n", size);
return -ENOMEM;
}
memset(adapter->ring_vir_addr, 0, adapter->ring_size);
rx_page_desc = rx_ring->rx_page_desc;
tx_ring->dma = roundup(adapter->ring_dma, 8);
offset = tx_ring->dma - adapter->ring_dma;
tx_ring->desc = adapter->ring_vir_addr + offset;
size = sizeof(struct atl1e_tx_buffer) * (tx_ring->count);
tx_ring->tx_buffer = kzalloc(size, GFP_KERNEL);
if (tx_ring->tx_buffer == NULL) {
netdev_err(adapter->netdev, "kzalloc failed, size = D%d\n",
size);
err = -ENOMEM;
goto failed;
}
offset += (sizeof(struct atl1e_tpd_desc) * tx_ring->count);
offset = roundup(offset, 32);
for (i = 0; i < adapter->num_rx_queues; i++) {
for (j = 0; j < AT_PAGE_NUM_PER_QUEUE; j++) {
rx_page_desc[i].rx_page[j].dma =
adapter->ring_dma + offset;
rx_page_desc[i].rx_page[j].addr =
adapter->ring_vir_addr + offset;
offset += rx_ring->real_page_size;
}
}
tx_ring->cmb_dma = adapter->ring_dma + offset;
tx_ring->cmb = adapter->ring_vir_addr + offset;
offset += sizeof(u32);
for (i = 0; i < adapter->num_rx_queues; i++) {
for (j = 0; j < AT_PAGE_NUM_PER_QUEUE; j++) {
rx_page_desc[i].rx_page[j].write_offset_dma =
adapter->ring_dma + offset;
rx_page_desc[i].rx_page[j].write_offset_addr =
adapter->ring_vir_addr + offset;
offset += sizeof(u32);
}
}
if (unlikely(offset > adapter->ring_size)) {
netdev_err(adapter->netdev, "offset(%d) > ring size(%d) !!\n",
offset, adapter->ring_size);
err = -1;
goto failed;
}
return 0;
failed:
if (adapter->ring_vir_addr != NULL) {
pci_free_consistent(pdev, adapter->ring_size,
adapter->ring_vir_addr, adapter->ring_dma);
adapter->ring_vir_addr = NULL;
}
return err;
}
static inline void atl1e_configure_des_ring(const struct atl1e_adapter *adapter)
{
struct atl1e_hw *hw = (struct atl1e_hw *)&adapter->hw;
struct atl1e_rx_ring *rx_ring =
(struct atl1e_rx_ring *)&adapter->rx_ring;
struct atl1e_tx_ring *tx_ring =
(struct atl1e_tx_ring *)&adapter->tx_ring;
struct atl1e_rx_page_desc *rx_page_desc = NULL;
int i, j;
AT_WRITE_REG(hw, REG_DESC_BASE_ADDR_HI,
(u32)((adapter->ring_dma & AT_DMA_HI_ADDR_MASK) >> 32));
AT_WRITE_REG(hw, REG_TPD_BASE_ADDR_LO,
(u32)((tx_ring->dma) & AT_DMA_LO_ADDR_MASK));
AT_WRITE_REG(hw, REG_TPD_RING_SIZE, (u16)(tx_ring->count));
AT_WRITE_REG(hw, REG_HOST_TX_CMB_LO,
(u32)((tx_ring->cmb_dma) & AT_DMA_LO_ADDR_MASK));
rx_page_desc = rx_ring->rx_page_desc;
for (i = 0; i < AT_MAX_RECEIVE_QUEUE; i++) {
AT_WRITE_REG(hw, atl1e_rx_page_hi_addr_regs[i],
(u32)((adapter->ring_dma &
AT_DMA_HI_ADDR_MASK) >> 32));
for (j = 0; j < AT_PAGE_NUM_PER_QUEUE; j++) {
u32 page_phy_addr;
u32 offset_phy_addr;
page_phy_addr = rx_page_desc[i].rx_page[j].dma;
offset_phy_addr =
rx_page_desc[i].rx_page[j].write_offset_dma;
AT_WRITE_REG(hw, atl1e_rx_page_lo_addr_regs[i][j],
page_phy_addr & AT_DMA_LO_ADDR_MASK);
AT_WRITE_REG(hw, atl1e_rx_page_write_offset_regs[i][j],
offset_phy_addr & AT_DMA_LO_ADDR_MASK);
AT_WRITE_REGB(hw, atl1e_rx_page_vld_regs[i][j], 1);
}
}
AT_WRITE_REG(hw, REG_HOST_RXFPAGE_SIZE, rx_ring->page_size);
AT_WRITE_REG(hw, REG_LOAD_PTR, 1);
}
static inline void atl1e_configure_tx(struct atl1e_adapter *adapter)
{
struct atl1e_hw *hw = (struct atl1e_hw *)&adapter->hw;
u32 dev_ctrl_data = 0;
u32 max_pay_load = 0;
u32 jumbo_thresh = 0;
u32 extra_size = 0;
if (hw->nic_type != athr_l2e_revB) {
extra_size = ETH_HLEN + VLAN_HLEN + ETH_FCS_LEN;
if (hw->max_frame_size <= 1500) {
jumbo_thresh = hw->max_frame_size + extra_size;
} else if (hw->max_frame_size < 6*1024) {
jumbo_thresh =
(hw->max_frame_size + extra_size) * 2 / 3;
} else {
jumbo_thresh = (hw->max_frame_size + extra_size) / 2;
}
AT_WRITE_REG(hw, REG_TX_EARLY_TH, (jumbo_thresh + 7) >> 3);
}
dev_ctrl_data = AT_READ_REG(hw, REG_DEVICE_CTRL);
max_pay_load = ((dev_ctrl_data >> DEVICE_CTRL_MAX_PAYLOAD_SHIFT)) &
DEVICE_CTRL_MAX_PAYLOAD_MASK;
hw->dmaw_block = min_t(u32, max_pay_load, hw->dmaw_block);
max_pay_load = ((dev_ctrl_data >> DEVICE_CTRL_MAX_RREQ_SZ_SHIFT)) &
DEVICE_CTRL_MAX_RREQ_SZ_MASK;
hw->dmar_block = min_t(u32, max_pay_load, hw->dmar_block);
if (hw->nic_type != athr_l2e_revB)
AT_WRITE_REGW(hw, REG_TXQ_CTRL + 2,
atl1e_pay_load_size[hw->dmar_block]);
AT_WRITE_REGW(hw, REG_TXQ_CTRL,
(((u16)hw->tpd_burst & TXQ_CTRL_NUM_TPD_BURST_MASK)
<< TXQ_CTRL_NUM_TPD_BURST_SHIFT)
| TXQ_CTRL_ENH_MODE | TXQ_CTRL_EN);
}
static inline void atl1e_configure_rx(struct atl1e_adapter *adapter)
{
struct atl1e_hw *hw = (struct atl1e_hw *)&adapter->hw;
u32 rxf_len = 0;
u32 rxf_low = 0;
u32 rxf_high = 0;
u32 rxf_thresh_data = 0;
u32 rxq_ctrl_data = 0;
if (hw->nic_type != athr_l2e_revB) {
AT_WRITE_REGW(hw, REG_RXQ_JMBOSZ_RRDTIM,
(u16)((hw->rx_jumbo_th & RXQ_JMBOSZ_TH_MASK) <<
RXQ_JMBOSZ_TH_SHIFT |
(1 & RXQ_JMBO_LKAH_MASK) <<
RXQ_JMBO_LKAH_SHIFT));
rxf_len = AT_READ_REG(hw, REG_SRAM_RXF_LEN);
rxf_high = rxf_len * 4 / 5;
rxf_low = rxf_len / 5;
rxf_thresh_data = ((rxf_high & RXQ_RXF_PAUSE_TH_HI_MASK)
<< RXQ_RXF_PAUSE_TH_HI_SHIFT) |
((rxf_low & RXQ_RXF_PAUSE_TH_LO_MASK)
<< RXQ_RXF_PAUSE_TH_LO_SHIFT);
AT_WRITE_REG(hw, REG_RXQ_RXF_PAUSE_THRESH, rxf_thresh_data);
}
AT_WRITE_REG(hw, REG_IDT_TABLE, hw->indirect_tab);
AT_WRITE_REG(hw, REG_BASE_CPU_NUMBER, hw->base_cpu);
if (hw->rrs_type & atl1e_rrs_ipv4)
rxq_ctrl_data |= RXQ_CTRL_HASH_TYPE_IPV4;
if (hw->rrs_type & atl1e_rrs_ipv4_tcp)
rxq_ctrl_data |= RXQ_CTRL_HASH_TYPE_IPV4_TCP;
if (hw->rrs_type & atl1e_rrs_ipv6)
rxq_ctrl_data |= RXQ_CTRL_HASH_TYPE_IPV6;
if (hw->rrs_type & atl1e_rrs_ipv6_tcp)
rxq_ctrl_data |= RXQ_CTRL_HASH_TYPE_IPV6_TCP;
if (hw->rrs_type != atl1e_rrs_disable)
rxq_ctrl_data |=
(RXQ_CTRL_HASH_ENABLE | RXQ_CTRL_RSS_MODE_MQUESINT);
rxq_ctrl_data |= RXQ_CTRL_IPV6_XSUM_VERIFY_EN | RXQ_CTRL_PBA_ALIGN_32 |
RXQ_CTRL_CUT_THRU_EN | RXQ_CTRL_EN;
AT_WRITE_REG(hw, REG_RXQ_CTRL, rxq_ctrl_data);
}
static inline void atl1e_configure_dma(struct atl1e_adapter *adapter)
{
struct atl1e_hw *hw = &adapter->hw;
u32 dma_ctrl_data = 0;
dma_ctrl_data = DMA_CTRL_RXCMB_EN;
dma_ctrl_data |= (((u32)hw->dmar_block) & DMA_CTRL_DMAR_BURST_LEN_MASK)
<< DMA_CTRL_DMAR_BURST_LEN_SHIFT;
dma_ctrl_data |= (((u32)hw->dmaw_block) & DMA_CTRL_DMAW_BURST_LEN_MASK)
<< DMA_CTRL_DMAW_BURST_LEN_SHIFT;
dma_ctrl_data |= DMA_CTRL_DMAR_REQ_PRI | DMA_CTRL_DMAR_OUT_ORDER;
dma_ctrl_data |= (((u32)hw->dmar_dly_cnt) & DMA_CTRL_DMAR_DLY_CNT_MASK)
<< DMA_CTRL_DMAR_DLY_CNT_SHIFT;
dma_ctrl_data |= (((u32)hw->dmaw_dly_cnt) & DMA_CTRL_DMAW_DLY_CNT_MASK)
<< DMA_CTRL_DMAW_DLY_CNT_SHIFT;
AT_WRITE_REG(hw, REG_DMA_CTRL, dma_ctrl_data);
}
static void atl1e_setup_mac_ctrl(struct atl1e_adapter *adapter)
{
u32 value;
struct atl1e_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
value = MAC_CTRL_TX_EN |
MAC_CTRL_RX_EN ;
if (FULL_DUPLEX == adapter->link_duplex)
value |= MAC_CTRL_DUPLX;
value |= ((u32)((SPEED_1000 == adapter->link_speed) ?
MAC_CTRL_SPEED_1000 : MAC_CTRL_SPEED_10_100) <<
MAC_CTRL_SPEED_SHIFT);
value |= (MAC_CTRL_TX_FLOW | MAC_CTRL_RX_FLOW);
value |= (MAC_CTRL_ADD_CRC | MAC_CTRL_PAD);
value |= (((u32)adapter->hw.preamble_len &
MAC_CTRL_PRMLEN_MASK) << MAC_CTRL_PRMLEN_SHIFT);
__atl1e_vlan_mode(netdev->features, &value);
value |= MAC_CTRL_BC_EN;
if (netdev->flags & IFF_PROMISC)
value |= MAC_CTRL_PROMIS_EN;
if (netdev->flags & IFF_ALLMULTI)
value |= MAC_CTRL_MC_ALL_EN;
AT_WRITE_REG(hw, REG_MAC_CTRL, value);
}
static int atl1e_configure(struct atl1e_adapter *adapter)
{
struct atl1e_hw *hw = &adapter->hw;
u32 intr_status_data = 0;
AT_WRITE_REG(hw, REG_ISR, ~0);
atl1e_hw_set_mac_addr(hw);
AT_WRITE_REG(hw, REG_WOL_CTRL, 0);
atl1e_configure_des_ring(adapter);
AT_WRITE_REGW(hw, REG_IRQ_MODU_TIMER_INIT, hw->imt);
AT_WRITE_REGW(hw, REG_IRQ_MODU_TIMER2_INIT, hw->imt);
AT_WRITE_REG(hw, REG_MASTER_CTRL, MASTER_CTRL_LED_MODE |
MASTER_CTRL_ITIMER_EN | MASTER_CTRL_ITIMER2_EN);
AT_WRITE_REGW(hw, REG_TRIG_RRD_THRESH, hw->rrd_thresh);
AT_WRITE_REGW(hw, REG_TRIG_TPD_THRESH, hw->tpd_thresh);
AT_WRITE_REGW(hw, REG_TRIG_RXTIMER, hw->rx_count_down);
AT_WRITE_REGW(hw, REG_TRIG_TXTIMER, hw->tx_count_down);
AT_WRITE_REGW(hw, REG_CMBDISDMA_TIMER, hw->ict);
AT_WRITE_REG(hw, REG_MTU, hw->max_frame_size + ETH_HLEN +
VLAN_HLEN + ETH_FCS_LEN);
atl1e_configure_tx(adapter);
atl1e_configure_rx(adapter);
atl1e_configure_dma(adapter);
AT_WRITE_REG(hw, REG_SMB_STAT_TIMER, hw->smb_timer);
intr_status_data = AT_READ_REG(hw, REG_ISR);
if (unlikely((intr_status_data & ISR_PHY_LINKDOWN) != 0)) {
netdev_err(adapter->netdev,
"atl1e_configure failed, PCIE phy link down\n");
return -1;
}
AT_WRITE_REG(hw, REG_ISR, 0x7fffffff);
return 0;
}
static struct net_device_stats *atl1e_get_stats(struct net_device *netdev)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
struct atl1e_hw_stats *hw_stats = &adapter->hw_stats;
struct net_device_stats *net_stats = &netdev->stats;
net_stats->rx_packets = hw_stats->rx_ok;
net_stats->tx_packets = hw_stats->tx_ok;
net_stats->rx_bytes = hw_stats->rx_byte_cnt;
net_stats->tx_bytes = hw_stats->tx_byte_cnt;
net_stats->multicast = hw_stats->rx_mcast;
net_stats->collisions = hw_stats->tx_1_col +
hw_stats->tx_2_col * 2 +
hw_stats->tx_late_col + hw_stats->tx_abort_col;
net_stats->rx_errors = hw_stats->rx_frag + hw_stats->rx_fcs_err +
hw_stats->rx_len_err + hw_stats->rx_sz_ov +
hw_stats->rx_rrd_ov + hw_stats->rx_align_err;
net_stats->rx_fifo_errors = hw_stats->rx_rxf_ov;
net_stats->rx_length_errors = hw_stats->rx_len_err;
net_stats->rx_crc_errors = hw_stats->rx_fcs_err;
net_stats->rx_frame_errors = hw_stats->rx_align_err;
net_stats->rx_over_errors = hw_stats->rx_rrd_ov + hw_stats->rx_rxf_ov;
net_stats->rx_missed_errors = hw_stats->rx_rrd_ov + hw_stats->rx_rxf_ov;
net_stats->tx_errors = hw_stats->tx_late_col + hw_stats->tx_abort_col +
hw_stats->tx_underrun + hw_stats->tx_trunc;
net_stats->tx_fifo_errors = hw_stats->tx_underrun;
net_stats->tx_aborted_errors = hw_stats->tx_abort_col;
net_stats->tx_window_errors = hw_stats->tx_late_col;
return net_stats;
}
static void atl1e_update_hw_stats(struct atl1e_adapter *adapter)
{
u16 hw_reg_addr = 0;
unsigned long *stats_item = NULL;
hw_reg_addr = REG_MAC_RX_STATUS_BIN;
stats_item = &adapter->hw_stats.rx_ok;
while (hw_reg_addr <= REG_MAC_RX_STATUS_END) {
*stats_item += AT_READ_REG(&adapter->hw, hw_reg_addr);
stats_item++;
hw_reg_addr += 4;
}
hw_reg_addr = REG_MAC_TX_STATUS_BIN;
stats_item = &adapter->hw_stats.tx_ok;
while (hw_reg_addr <= REG_MAC_TX_STATUS_END) {
*stats_item += AT_READ_REG(&adapter->hw, hw_reg_addr);
stats_item++;
hw_reg_addr += 4;
}
}
static inline void atl1e_clear_phy_int(struct atl1e_adapter *adapter)
{
u16 phy_data;
spin_lock(&adapter->mdio_lock);
atl1e_read_phy_reg(&adapter->hw, MII_INT_STATUS, &phy_data);
spin_unlock(&adapter->mdio_lock);
}
static bool atl1e_clean_tx_irq(struct atl1e_adapter *adapter)
{
struct atl1e_tx_ring *tx_ring = (struct atl1e_tx_ring *)
&adapter->tx_ring;
struct atl1e_tx_buffer *tx_buffer = NULL;
u16 hw_next_to_clean = AT_READ_REGW(&adapter->hw, REG_TPD_CONS_IDX);
u16 next_to_clean = atomic_read(&tx_ring->next_to_clean);
while (next_to_clean != hw_next_to_clean) {
tx_buffer = &tx_ring->tx_buffer[next_to_clean];
if (tx_buffer->dma) {
if (tx_buffer->flags & ATL1E_TX_PCIMAP_SINGLE)
pci_unmap_single(adapter->pdev, tx_buffer->dma,
tx_buffer->length, PCI_DMA_TODEVICE);
else if (tx_buffer->flags & ATL1E_TX_PCIMAP_PAGE)
pci_unmap_page(adapter->pdev, tx_buffer->dma,
tx_buffer->length, PCI_DMA_TODEVICE);
tx_buffer->dma = 0;
}
if (tx_buffer->skb) {
dev_kfree_skb_irq(tx_buffer->skb);
tx_buffer->skb = NULL;
}
if (++next_to_clean == tx_ring->count)
next_to_clean = 0;
}
atomic_set(&tx_ring->next_to_clean, next_to_clean);
if (netif_queue_stopped(adapter->netdev) &&
netif_carrier_ok(adapter->netdev)) {
netif_wake_queue(adapter->netdev);
}
return true;
}
static irqreturn_t atl1e_intr(int irq, void *data)
{
struct net_device *netdev = data;
struct atl1e_adapter *adapter = netdev_priv(netdev);
struct atl1e_hw *hw = &adapter->hw;
int max_ints = AT_MAX_INT_WORK;
int handled = IRQ_NONE;
u32 status;
do {
status = AT_READ_REG(hw, REG_ISR);
if ((status & IMR_NORMAL_MASK) == 0 ||
(status & ISR_DIS_INT) != 0) {
if (max_ints != AT_MAX_INT_WORK)
handled = IRQ_HANDLED;
break;
}
if (status & ISR_GPHY)
atl1e_clear_phy_int(adapter);
AT_WRITE_REG(hw, REG_ISR, status | ISR_DIS_INT);
handled = IRQ_HANDLED;
if (status & ISR_PHY_LINKDOWN) {
netdev_err(adapter->netdev,
"pcie phy linkdown %x\n", status);
if (netif_running(adapter->netdev)) {
atl1e_irq_reset(adapter);
schedule_work(&adapter->reset_task);
break;
}
}
if (status & (ISR_DMAR_TO_RST | ISR_DMAW_TO_RST)) {
netdev_err(adapter->netdev,
"PCIE DMA RW error (status = 0x%x)\n",
status);
atl1e_irq_reset(adapter);
schedule_work(&adapter->reset_task);
break;
}
if (status & ISR_SMB)
atl1e_update_hw_stats(adapter);
if (status & (ISR_GPHY | ISR_MANUAL)) {
netdev->stats.tx_carrier_errors++;
atl1e_link_chg_event(adapter);
break;
}
if (status & ISR_TX_EVENT)
atl1e_clean_tx_irq(adapter);
if (status & ISR_RX_EVENT) {
AT_WRITE_REG(hw, REG_IMR,
IMR_NORMAL_MASK & ~ISR_RX_EVENT);
AT_WRITE_FLUSH(hw);
if (likely(napi_schedule_prep(
&adapter->napi)))
__napi_schedule(&adapter->napi);
}
} while (--max_ints > 0);
AT_WRITE_REG(&adapter->hw, REG_ISR, 0);
return handled;
}
static inline void atl1e_rx_checksum(struct atl1e_adapter *adapter,
struct sk_buff *skb, struct atl1e_recv_ret_status *prrs)
{
u8 *packet = (u8 *)(prrs + 1);
struct iphdr *iph;
u16 head_len = ETH_HLEN;
u16 pkt_flags;
u16 err_flags;
skb_checksum_none_assert(skb);
pkt_flags = prrs->pkt_flag;
err_flags = prrs->err_flag;
if (((pkt_flags & RRS_IS_IPV4) || (pkt_flags & RRS_IS_IPV6)) &&
((pkt_flags & RRS_IS_TCP) || (pkt_flags & RRS_IS_UDP))) {
if (pkt_flags & RRS_IS_IPV4) {
if (pkt_flags & RRS_IS_802_3)
head_len += 8;
iph = (struct iphdr *) (packet + head_len);
if (iph->frag_off != 0 && !(pkt_flags & RRS_IS_IP_DF))
goto hw_xsum;
}
if (!(err_flags & (RRS_ERR_IP_CSUM | RRS_ERR_L4_CSUM))) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
return;
}
}
hw_xsum :
return;
}
static struct atl1e_rx_page *atl1e_get_rx_page(struct atl1e_adapter *adapter,
u8 que)
{
struct atl1e_rx_page_desc *rx_page_desc =
(struct atl1e_rx_page_desc *) adapter->rx_ring.rx_page_desc;
u8 rx_using = rx_page_desc[que].rx_using;
return (struct atl1e_rx_page *)&(rx_page_desc[que].rx_page[rx_using]);
}
static void atl1e_clean_rx_irq(struct atl1e_adapter *adapter, u8 que,
int *work_done, int work_to_do)
{
struct net_device *netdev = adapter->netdev;
struct atl1e_rx_ring *rx_ring = (struct atl1e_rx_ring *)
&adapter->rx_ring;
struct atl1e_rx_page_desc *rx_page_desc =
(struct atl1e_rx_page_desc *) rx_ring->rx_page_desc;
struct sk_buff *skb = NULL;
struct atl1e_rx_page *rx_page = atl1e_get_rx_page(adapter, que);
u32 packet_size, write_offset;
struct atl1e_recv_ret_status *prrs;
write_offset = *(rx_page->write_offset_addr);
if (likely(rx_page->read_offset < write_offset)) {
do {
if (*work_done >= work_to_do)
break;
(*work_done)++;
prrs = (struct atl1e_recv_ret_status *) (rx_page->addr +
rx_page->read_offset);
if (prrs->seq_num != rx_page_desc[que].rx_nxseq) {
netdev_err(netdev,
"rx sequence number error (rx=%d) (expect=%d)\n",
prrs->seq_num,
rx_page_desc[que].rx_nxseq);
rx_page_desc[que].rx_nxseq++;
AT_WRITE_REG(&adapter->hw, REG_DEBUG_DATA0,
(((u32)prrs->seq_num) << 16) |
rx_page_desc[que].rx_nxseq);
goto fatal_err;
}
rx_page_desc[que].rx_nxseq++;
if (prrs->pkt_flag & RRS_IS_ERR_FRAME) {
if (prrs->err_flag & (RRS_ERR_BAD_CRC |
RRS_ERR_DRIBBLE | RRS_ERR_CODE |
RRS_ERR_TRUNC)) {
netdev_err(netdev,
"rx packet desc error %x\n",
*((u32 *)prrs + 1));
goto skip_pkt;
}
}
packet_size = ((prrs->word1 >> RRS_PKT_SIZE_SHIFT) &
RRS_PKT_SIZE_MASK) - 4;
skb = netdev_alloc_skb_ip_align(netdev, packet_size);
if (skb == NULL) {
netdev_warn(netdev,
"Memory squeeze, deferring packet\n");
goto skip_pkt;
}
memcpy(skb->data, (u8 *)(prrs + 1), packet_size);
skb_put(skb, packet_size);
skb->protocol = eth_type_trans(skb, netdev);
atl1e_rx_checksum(adapter, skb, prrs);
if (prrs->pkt_flag & RRS_IS_VLAN_TAG) {
u16 vlan_tag = (prrs->vtag >> 4) |
((prrs->vtag & 7) << 13) |
((prrs->vtag & 8) << 9);
netdev_dbg(netdev,
"RXD VLAN TAG<RRD>=0x%04x\n",
prrs->vtag);
__vlan_hwaccel_put_tag(skb, vlan_tag);
}
netif_receive_skb(skb);
skip_pkt:
rx_page->read_offset +=
(((u32)((prrs->word1 >> RRS_PKT_SIZE_SHIFT) &
RRS_PKT_SIZE_MASK) +
sizeof(struct atl1e_recv_ret_status) + 31) &
0xFFFFFFE0);
if (rx_page->read_offset >= rx_ring->page_size) {
u16 reg_addr;
u8 rx_using;
rx_page->read_offset =
*(rx_page->write_offset_addr) = 0;
rx_using = rx_page_desc[que].rx_using;
reg_addr =
atl1e_rx_page_vld_regs[que][rx_using];
AT_WRITE_REGB(&adapter->hw, reg_addr, 1);
rx_page_desc[que].rx_using ^= 1;
rx_page = atl1e_get_rx_page(adapter, que);
}
write_offset = *(rx_page->write_offset_addr);
} while (rx_page->read_offset < write_offset);
}
return;
fatal_err:
if (!test_bit(__AT_DOWN, &adapter->flags))
schedule_work(&adapter->reset_task);
}
static int atl1e_clean(struct napi_struct *napi, int budget)
{
struct atl1e_adapter *adapter =
container_of(napi, struct atl1e_adapter, napi);
u32 imr_data;
int work_done = 0;
if (!netif_carrier_ok(adapter->netdev))
goto quit_polling;
atl1e_clean_rx_irq(adapter, 0, &work_done, budget);
if (work_done < budget) {
quit_polling:
napi_complete(napi);
imr_data = AT_READ_REG(&adapter->hw, REG_IMR);
AT_WRITE_REG(&adapter->hw, REG_IMR, imr_data | ISR_RX_EVENT);
if (test_bit(__AT_DOWN, &adapter->flags)) {
atomic_dec(&adapter->irq_sem);
netdev_err(adapter->netdev,
"atl1e_clean is called when AT_DOWN\n");
}
}
return work_done;
}
static void atl1e_netpoll(struct net_device *netdev)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
disable_irq(adapter->pdev->irq);
atl1e_intr(adapter->pdev->irq, netdev);
enable_irq(adapter->pdev->irq);
}
static inline u16 atl1e_tpd_avail(struct atl1e_adapter *adapter)
{
struct atl1e_tx_ring *tx_ring = &adapter->tx_ring;
u16 next_to_use = 0;
u16 next_to_clean = 0;
next_to_clean = atomic_read(&tx_ring->next_to_clean);
next_to_use = tx_ring->next_to_use;
return (u16)(next_to_clean > next_to_use) ?
(next_to_clean - next_to_use - 1) :
(tx_ring->count + next_to_clean - next_to_use - 1);
}
static struct atl1e_tpd_desc *atl1e_get_tpd(struct atl1e_adapter *adapter)
{
struct atl1e_tx_ring *tx_ring = &adapter->tx_ring;
u16 next_to_use = 0;
next_to_use = tx_ring->next_to_use;
if (++tx_ring->next_to_use == tx_ring->count)
tx_ring->next_to_use = 0;
memset(&tx_ring->desc[next_to_use], 0, sizeof(struct atl1e_tpd_desc));
return (struct atl1e_tpd_desc *)&tx_ring->desc[next_to_use];
}
static struct atl1e_tx_buffer *
atl1e_get_tx_buffer(struct atl1e_adapter *adapter, struct atl1e_tpd_desc *tpd)
{
struct atl1e_tx_ring *tx_ring = &adapter->tx_ring;
return &tx_ring->tx_buffer[tpd - tx_ring->desc];
}
static u16 atl1e_cal_tdp_req(const struct sk_buff *skb)
{
int i = 0;
u16 tpd_req = 1;
u16 fg_size = 0;
u16 proto_hdr_len = 0;
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
fg_size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
tpd_req += ((fg_size + MAX_TX_BUF_LEN - 1) >> MAX_TX_BUF_SHIFT);
}
if (skb_is_gso(skb)) {
if (skb->protocol == htons(ETH_P_IP) ||
(skb_shinfo(skb)->gso_type == SKB_GSO_TCPV6)) {
proto_hdr_len = skb_transport_offset(skb) +
tcp_hdrlen(skb);
if (proto_hdr_len < skb_headlen(skb)) {
tpd_req += ((skb_headlen(skb) - proto_hdr_len +
MAX_TX_BUF_LEN - 1) >>
MAX_TX_BUF_SHIFT);
}
}
}
return tpd_req;
}
static int atl1e_tso_csum(struct atl1e_adapter *adapter,
struct sk_buff *skb, struct atl1e_tpd_desc *tpd)
{
u8 hdr_len;
u32 real_len;
unsigned short offload_type;
int err;
if (skb_is_gso(skb)) {
if (skb_header_cloned(skb)) {
err = pskb_expand_head(skb, 0, 0, GFP_ATOMIC);
if (unlikely(err))
return -1;
}
offload_type = skb_shinfo(skb)->gso_type;
if (offload_type & SKB_GSO_TCPV4) {
real_len = (((unsigned char *)ip_hdr(skb) - skb->data)
+ ntohs(ip_hdr(skb)->tot_len));
if (real_len < skb->len)
pskb_trim(skb, real_len);
hdr_len = (skb_transport_offset(skb) + tcp_hdrlen(skb));
if (unlikely(skb->len == hdr_len)) {
netdev_warn(adapter->netdev,
"IPV4 tso with zero data??\n");
goto check_sum;
} else {
ip_hdr(skb)->check = 0;
ip_hdr(skb)->tot_len = 0;
tcp_hdr(skb)->check = ~csum_tcpudp_magic(
ip_hdr(skb)->saddr,
ip_hdr(skb)->daddr,
0, IPPROTO_TCP, 0);
tpd->word3 |= (ip_hdr(skb)->ihl &
TDP_V4_IPHL_MASK) <<
TPD_V4_IPHL_SHIFT;
tpd->word3 |= ((tcp_hdrlen(skb) >> 2) &
TPD_TCPHDRLEN_MASK) <<
TPD_TCPHDRLEN_SHIFT;
tpd->word3 |= ((skb_shinfo(skb)->gso_size) &
TPD_MSS_MASK) << TPD_MSS_SHIFT;
tpd->word3 |= 1 << TPD_SEGMENT_EN_SHIFT;
}
return 0;
}
}
check_sum:
if (likely(skb->ip_summed == CHECKSUM_PARTIAL)) {
u8 css, cso;
cso = skb_checksum_start_offset(skb);
if (unlikely(cso & 0x1)) {
netdev_err(adapter->netdev,
"payload offset should not ant event number\n");
return -1;
} else {
css = cso + skb->csum_offset;
tpd->word3 |= (cso & TPD_PLOADOFFSET_MASK) <<
TPD_PLOADOFFSET_SHIFT;
tpd->word3 |= (css & TPD_CCSUMOFFSET_MASK) <<
TPD_CCSUMOFFSET_SHIFT;
tpd->word3 |= 1 << TPD_CC_SEGMENT_EN_SHIFT;
}
}
return 0;
}
static void atl1e_tx_map(struct atl1e_adapter *adapter,
struct sk_buff *skb, struct atl1e_tpd_desc *tpd)
{
struct atl1e_tpd_desc *use_tpd = NULL;
struct atl1e_tx_buffer *tx_buffer = NULL;
u16 buf_len = skb_headlen(skb);
u16 map_len = 0;
u16 mapped_len = 0;
u16 hdr_len = 0;
u16 nr_frags;
u16 f;
int segment;
nr_frags = skb_shinfo(skb)->nr_frags;
segment = (tpd->word3 >> TPD_SEGMENT_EN_SHIFT) & TPD_SEGMENT_EN_MASK;
if (segment) {
map_len = hdr_len = skb_transport_offset(skb) + tcp_hdrlen(skb);
use_tpd = tpd;
tx_buffer = atl1e_get_tx_buffer(adapter, use_tpd);
tx_buffer->length = map_len;
tx_buffer->dma = pci_map_single(adapter->pdev,
skb->data, hdr_len, PCI_DMA_TODEVICE);
ATL1E_SET_PCIMAP_TYPE(tx_buffer, ATL1E_TX_PCIMAP_SINGLE);
mapped_len += map_len;
use_tpd->buffer_addr = cpu_to_le64(tx_buffer->dma);
use_tpd->word2 = (use_tpd->word2 & (~TPD_BUFLEN_MASK)) |
((cpu_to_le32(tx_buffer->length) &
TPD_BUFLEN_MASK) << TPD_BUFLEN_SHIFT);
}
while (mapped_len < buf_len) {
if (mapped_len == 0) {
use_tpd = tpd;
} else {
use_tpd = atl1e_get_tpd(adapter);
memcpy(use_tpd, tpd, sizeof(struct atl1e_tpd_desc));
}
tx_buffer = atl1e_get_tx_buffer(adapter, use_tpd);
tx_buffer->skb = NULL;
tx_buffer->length = map_len =
((buf_len - mapped_len) >= MAX_TX_BUF_LEN) ?
MAX_TX_BUF_LEN : (buf_len - mapped_len);
tx_buffer->dma =
pci_map_single(adapter->pdev, skb->data + mapped_len,
map_len, PCI_DMA_TODEVICE);
ATL1E_SET_PCIMAP_TYPE(tx_buffer, ATL1E_TX_PCIMAP_SINGLE);
mapped_len += map_len;
use_tpd->buffer_addr = cpu_to_le64(tx_buffer->dma);
use_tpd->word2 = (use_tpd->word2 & (~TPD_BUFLEN_MASK)) |
((cpu_to_le32(tx_buffer->length) &
TPD_BUFLEN_MASK) << TPD_BUFLEN_SHIFT);
}
for (f = 0; f < nr_frags; f++) {
const struct skb_frag_struct *frag;
u16 i;
u16 seg_num;
frag = &skb_shinfo(skb)->frags[f];
buf_len = skb_frag_size(frag);
seg_num = (buf_len + MAX_TX_BUF_LEN - 1) / MAX_TX_BUF_LEN;
for (i = 0; i < seg_num; i++) {
use_tpd = atl1e_get_tpd(adapter);
memcpy(use_tpd, tpd, sizeof(struct atl1e_tpd_desc));
tx_buffer = atl1e_get_tx_buffer(adapter, use_tpd);
BUG_ON(tx_buffer->skb);
tx_buffer->skb = NULL;
tx_buffer->length =
(buf_len > MAX_TX_BUF_LEN) ?
MAX_TX_BUF_LEN : buf_len;
buf_len -= tx_buffer->length;
tx_buffer->dma = skb_frag_dma_map(&adapter->pdev->dev,
frag,
(i * MAX_TX_BUF_LEN),
tx_buffer->length,
DMA_TO_DEVICE);
ATL1E_SET_PCIMAP_TYPE(tx_buffer, ATL1E_TX_PCIMAP_PAGE);
use_tpd->buffer_addr = cpu_to_le64(tx_buffer->dma);
use_tpd->word2 = (use_tpd->word2 & (~TPD_BUFLEN_MASK)) |
((cpu_to_le32(tx_buffer->length) &
TPD_BUFLEN_MASK) << TPD_BUFLEN_SHIFT);
}
}
if ((tpd->word3 >> TPD_SEGMENT_EN_SHIFT) & TPD_SEGMENT_EN_MASK)
tpd->word3 |= 1 << TPD_HDRFLAG_SHIFT;
use_tpd->word3 |= 1 << TPD_EOP_SHIFT;
tx_buffer->skb = skb;
}
static void atl1e_tx_queue(struct atl1e_adapter *adapter, u16 count,
struct atl1e_tpd_desc *tpd)
{
struct atl1e_tx_ring *tx_ring = &adapter->tx_ring;
wmb();
AT_WRITE_REG(&adapter->hw, REG_MB_TPD_PROD_IDX, tx_ring->next_to_use);
}
static netdev_tx_t atl1e_xmit_frame(struct sk_buff *skb,
struct net_device *netdev)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
unsigned long flags;
u16 tpd_req = 1;
struct atl1e_tpd_desc *tpd;
if (test_bit(__AT_DOWN, &adapter->flags)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if (unlikely(skb->len <= 0)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
tpd_req = atl1e_cal_tdp_req(skb);
if (!spin_trylock_irqsave(&adapter->tx_lock, flags))
return NETDEV_TX_LOCKED;
if (atl1e_tpd_avail(adapter) < tpd_req) {
netif_stop_queue(netdev);
spin_unlock_irqrestore(&adapter->tx_lock, flags);
return NETDEV_TX_BUSY;
}
tpd = atl1e_get_tpd(adapter);
if (vlan_tx_tag_present(skb)) {
u16 vlan_tag = vlan_tx_tag_get(skb);
u16 atl1e_vlan_tag;
tpd->word3 |= 1 << TPD_INS_VL_TAG_SHIFT;
AT_VLAN_TAG_TO_TPD_TAG(vlan_tag, atl1e_vlan_tag);
tpd->word2 |= (atl1e_vlan_tag & TPD_VLANTAG_MASK) <<
TPD_VLAN_SHIFT;
}
if (skb->protocol == htons(ETH_P_8021Q))
tpd->word3 |= 1 << TPD_VL_TAGGED_SHIFT;
if (skb_network_offset(skb) != ETH_HLEN)
tpd->word3 |= 1 << TPD_ETHTYPE_SHIFT;
if (atl1e_tso_csum(adapter, skb, tpd) != 0) {
spin_unlock_irqrestore(&adapter->tx_lock, flags);
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
atl1e_tx_map(adapter, skb, tpd);
atl1e_tx_queue(adapter, tpd_req, tpd);
netdev->trans_start = jiffies;
spin_unlock_irqrestore(&adapter->tx_lock, flags);
return NETDEV_TX_OK;
}
static void atl1e_free_irq(struct atl1e_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
free_irq(adapter->pdev->irq, netdev);
if (adapter->have_msi)
pci_disable_msi(adapter->pdev);
}
static int atl1e_request_irq(struct atl1e_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
struct net_device *netdev = adapter->netdev;
int flags = 0;
int err = 0;
adapter->have_msi = true;
err = pci_enable_msi(adapter->pdev);
if (err) {
netdev_dbg(adapter->netdev,
"Unable to allocate MSI interrupt Error: %d\n", err);
adapter->have_msi = false;
} else
netdev->irq = pdev->irq;
if (!adapter->have_msi)
flags |= IRQF_SHARED;
err = request_irq(adapter->pdev->irq, atl1e_intr, flags,
netdev->name, netdev);
if (err) {
netdev_dbg(adapter->netdev,
"Unable to allocate interrupt Error: %d\n", err);
if (adapter->have_msi)
pci_disable_msi(adapter->pdev);
return err;
}
netdev_dbg(adapter->netdev, "atl1e_request_irq OK\n");
return err;
}
int atl1e_up(struct atl1e_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int err = 0;
u32 val;
err = atl1e_init_hw(&adapter->hw);
if (err) {
err = -EIO;
return err;
}
atl1e_init_ring_ptrs(adapter);
atl1e_set_multi(netdev);
atl1e_restore_vlan(adapter);
if (atl1e_configure(adapter)) {
err = -EIO;
goto err_up;
}
clear_bit(__AT_DOWN, &adapter->flags);
napi_enable(&adapter->napi);
atl1e_irq_enable(adapter);
val = AT_READ_REG(&adapter->hw, REG_MASTER_CTRL);
AT_WRITE_REG(&adapter->hw, REG_MASTER_CTRL,
val | MASTER_CTRL_MANUAL_INT);
err_up:
return err;
}
void atl1e_down(struct atl1e_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
set_bit(__AT_DOWN, &adapter->flags);
netif_stop_queue(netdev);
atl1e_reset_hw(&adapter->hw);
msleep(1);
napi_disable(&adapter->napi);
atl1e_del_timer(adapter);
atl1e_irq_disable(adapter);
netif_carrier_off(netdev);
adapter->link_speed = SPEED_0;
adapter->link_duplex = -1;
atl1e_clean_tx_ring(adapter);
atl1e_clean_rx_ring(adapter);
}
static int atl1e_open(struct net_device *netdev)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
int err;
if (test_bit(__AT_TESTING, &adapter->flags))
return -EBUSY;
atl1e_init_ring_resources(adapter);
err = atl1e_setup_ring_resources(adapter);
if (unlikely(err))
return err;
err = atl1e_request_irq(adapter);
if (unlikely(err))
goto err_req_irq;
err = atl1e_up(adapter);
if (unlikely(err))
goto err_up;
return 0;
err_up:
atl1e_free_irq(adapter);
err_req_irq:
atl1e_free_ring_resources(adapter);
atl1e_reset_hw(&adapter->hw);
return err;
}
static int atl1e_close(struct net_device *netdev)
{
struct atl1e_adapter *adapter = netdev_priv(netdev);
WARN_ON(test_bit(__AT_RESETTING, &adapter->flags));
atl1e_down(adapter);
atl1e_free_irq(adapter);
atl1e_free_ring_resources(adapter);
return 0;
}
static int atl1e_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl1e_adapter *adapter = netdev_priv(netdev);
struct atl1e_hw *hw = &adapter->hw;
u32 ctrl = 0;
u32 mac_ctrl_data = 0;
u32 wol_ctrl_data = 0;
u16 mii_advertise_data = 0;
u16 mii_bmsr_data = 0;
u16 mii_intr_status_data = 0;
u32 wufc = adapter->wol;
u32 i;
#ifdef CONFIG_PM
int retval = 0;
#endif
if (netif_running(netdev)) {
WARN_ON(test_bit(__AT_RESETTING, &adapter->flags));
atl1e_down(adapter);
}
netif_device_detach(netdev);
#ifdef CONFIG_PM
retval = pci_save_state(pdev);
if (retval)
return retval;
#endif
if (wufc) {
atl1e_read_phy_reg(hw, MII_BMSR, (u16 *)&mii_bmsr_data);
atl1e_read_phy_reg(hw, MII_BMSR, (u16 *)&mii_bmsr_data);
mii_advertise_data = ADVERTISE_10HALF;
if ((atl1e_write_phy_reg(hw, MII_CTRL1000, 0) != 0) ||
(atl1e_write_phy_reg(hw,
MII_ADVERTISE, mii_advertise_data) != 0) ||
(atl1e_phy_commit(hw)) != 0) {
netdev_dbg(adapter->netdev, "set phy register failed\n");
goto wol_dis;
}
hw->phy_configured = false;
if (wufc & AT_WUFC_MAG)
wol_ctrl_data |= WOL_MAGIC_EN | WOL_MAGIC_PME_EN;
if (wufc & AT_WUFC_LNKC) {
if (mii_bmsr_data & BMSR_LSTATUS) {
for (i = 0; i < AT_SUSPEND_LINK_TIMEOUT; i++) {
msleep(100);
atl1e_read_phy_reg(hw, MII_BMSR,
(u16 *)&mii_bmsr_data);
if (mii_bmsr_data & BMSR_LSTATUS)
break;
}
if ((mii_bmsr_data & BMSR_LSTATUS) == 0)
netdev_dbg(adapter->netdev,
"Link may change when suspend\n");
}
wol_ctrl_data |= WOL_LINK_CHG_EN | WOL_LINK_CHG_PME_EN;
if (atl1e_write_phy_reg(hw, MII_INT_CTRL, 0x400) != 0) {
netdev_dbg(adapter->netdev,
"read write phy register failed\n");
goto wol_dis;
}
}
atl1e_read_phy_reg(hw, MII_INT_STATUS, &mii_intr_status_data);
mac_ctrl_data = MAC_CTRL_RX_EN;
mac_ctrl_data |= MAC_CTRL_SPEED_10_100 << MAC_CTRL_SPEED_SHIFT;
mac_ctrl_data |= (((u32)adapter->hw.preamble_len &
MAC_CTRL_PRMLEN_MASK) <<
MAC_CTRL_PRMLEN_SHIFT);
__atl1e_vlan_mode(netdev->features, &mac_ctrl_data);
if (wufc & AT_WUFC_MAG)
mac_ctrl_data |= MAC_CTRL_BC_EN;
netdev_dbg(adapter->netdev, "suspend MAC=0x%x\n",
mac_ctrl_data);
AT_WRITE_REG(hw, REG_WOL_CTRL, wol_ctrl_data);
AT_WRITE_REG(hw, REG_MAC_CTRL, mac_ctrl_data);
ctrl = AT_READ_REG(hw, REG_PCIE_PHYMISC);
ctrl |= PCIE_PHYMISC_FORCE_RCV_DET;
AT_WRITE_REG(hw, REG_PCIE_PHYMISC, ctrl);
pci_enable_wake(pdev, pci_choose_state(pdev, state), 1);
goto suspend_exit;
}
wol_dis:
AT_WRITE_REG(hw, REG_WOL_CTRL, 0);
ctrl = AT_READ_REG(hw, REG_PCIE_PHYMISC);
ctrl |= PCIE_PHYMISC_FORCE_RCV_DET;
AT_WRITE_REG(hw, REG_PCIE_PHYMISC, ctrl);
atl1e_force_ps(hw);
hw->phy_configured = false;
pci_enable_wake(pdev, pci_choose_state(pdev, state), 0);
suspend_exit:
if (netif_running(netdev))
atl1e_free_irq(adapter);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int atl1e_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl1e_adapter *adapter = netdev_priv(netdev);
u32 err;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
err = pci_enable_device(pdev);
if (err) {
netdev_err(adapter->netdev,
"Cannot enable PCI device from suspend\n");
return err;
}
pci_set_master(pdev);
AT_READ_REG(&adapter->hw, REG_WOL_CTRL);
pci_enable_wake(pdev, PCI_D3hot, 0);
pci_enable_wake(pdev, PCI_D3cold, 0);
AT_WRITE_REG(&adapter->hw, REG_WOL_CTRL, 0);
if (netif_running(netdev)) {
err = atl1e_request_irq(adapter);
if (err)
return err;
}
atl1e_reset_hw(&adapter->hw);
if (netif_running(netdev))
atl1e_up(adapter);
netif_device_attach(netdev);
return 0;
}
static void atl1e_shutdown(struct pci_dev *pdev)
{
atl1e_suspend(pdev, PMSG_SUSPEND);
}
static int atl1e_init_netdev(struct net_device *netdev, struct pci_dev *pdev)
{
SET_NETDEV_DEV(netdev, &pdev->dev);
pci_set_drvdata(pdev, netdev);
netdev->irq = pdev->irq;
netdev->netdev_ops = &atl1e_netdev_ops;
netdev->watchdog_timeo = AT_TX_WATCHDOG;
atl1e_set_ethtool_ops(netdev);
netdev->hw_features = NETIF_F_SG | NETIF_F_HW_CSUM | NETIF_F_TSO |
NETIF_F_HW_VLAN_RX;
netdev->features = netdev->hw_features | NETIF_F_LLTX |
NETIF_F_HW_VLAN_TX;
return 0;
}
static int __devinit atl1e_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *netdev;
struct atl1e_adapter *adapter = NULL;
static int cards_found;
int err = 0;
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "cannot enable PCI device\n");
return err;
}
if ((pci_set_dma_mask(pdev, DMA_BIT_MASK(32)) != 0) ||
(pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32)) != 0)) {
dev_err(&pdev->dev, "No usable DMA configuration,aborting\n");
goto err_dma;
}
err = pci_request_regions(pdev, atl1e_driver_name);
if (err) {
dev_err(&pdev->dev, "cannot obtain PCI resources\n");
goto err_pci_reg;
}
pci_set_master(pdev);
netdev = alloc_etherdev(sizeof(struct atl1e_adapter));
if (netdev == NULL) {
err = -ENOMEM;
dev_err(&pdev->dev, "etherdev alloc failed\n");
goto err_alloc_etherdev;
}
err = atl1e_init_netdev(netdev, pdev);
if (err) {
netdev_err(netdev, "init netdevice failed\n");
goto err_init_netdev;
}
adapter = netdev_priv(netdev);
adapter->bd_number = cards_found;
adapter->netdev = netdev;
adapter->pdev = pdev;
adapter->hw.adapter = adapter;
adapter->hw.hw_addr = pci_iomap(pdev, BAR_0, 0);
if (!adapter->hw.hw_addr) {
err = -EIO;
netdev_err(netdev, "cannot map device registers\n");
goto err_ioremap;
}
netdev->base_addr = (unsigned long)adapter->hw.hw_addr;
adapter->mii.dev = netdev;
adapter->mii.mdio_read = atl1e_mdio_read;
adapter->mii.mdio_write = atl1e_mdio_write;
adapter->mii.phy_id_mask = 0x1f;
adapter->mii.reg_num_mask = MDIO_REG_ADDR_MASK;
netif_napi_add(netdev, &adapter->napi, atl1e_clean, 64);
init_timer(&adapter->phy_config_timer);
adapter->phy_config_timer.function = atl1e_phy_config;
adapter->phy_config_timer.data = (unsigned long) adapter;
atl1e_check_options(adapter);
atl1e_setup_pcicmd(pdev);
err = atl1e_sw_init(adapter);
if (err) {
netdev_err(netdev, "net device private data init failed\n");
goto err_sw_init;
}
atl1e_phy_init(&adapter->hw);
err = atl1e_reset_hw(&adapter->hw);
if (err) {
err = -EIO;
goto err_reset;
}
if (atl1e_read_mac_addr(&adapter->hw) != 0) {
err = -EIO;
netdev_err(netdev, "get mac address failed\n");
goto err_eeprom;
}
memcpy(netdev->dev_addr, adapter->hw.mac_addr, netdev->addr_len);
memcpy(netdev->perm_addr, adapter->hw.mac_addr, netdev->addr_len);
netdev_dbg(netdev, "mac address : %pM\n", adapter->hw.mac_addr);
INIT_WORK(&adapter->reset_task, atl1e_reset_task);
INIT_WORK(&adapter->link_chg_task, atl1e_link_chg_task);
err = register_netdev(netdev);
if (err) {
netdev_err(netdev, "register netdevice failed\n");
goto err_register;
}
netif_stop_queue(netdev);
netif_carrier_off(netdev);
cards_found++;
return 0;
err_reset:
err_register:
err_sw_init:
err_eeprom:
iounmap(adapter->hw.hw_addr);
err_init_netdev:
err_ioremap:
free_netdev(netdev);
err_alloc_etherdev:
pci_release_regions(pdev);
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static void __devexit atl1e_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl1e_adapter *adapter = netdev_priv(netdev);
set_bit(__AT_DOWN, &adapter->flags);
atl1e_del_timer(adapter);
atl1e_cancel_work(adapter);
unregister_netdev(netdev);
atl1e_free_ring_resources(adapter);
atl1e_force_ps(&adapter->hw);
iounmap(adapter->hw.hw_addr);
pci_release_regions(pdev);
free_netdev(netdev);
pci_disable_device(pdev);
}
static pci_ers_result_t
atl1e_io_error_detected(struct pci_dev *pdev, pci_channel_state_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl1e_adapter *adapter = netdev_priv(netdev);
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (netif_running(netdev))
atl1e_down(adapter);
pci_disable_device(pdev);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t atl1e_io_slot_reset(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl1e_adapter *adapter = netdev_priv(netdev);
if (pci_enable_device(pdev)) {
netdev_err(adapter->netdev,
"Cannot re-enable PCI device after reset\n");
return PCI_ERS_RESULT_DISCONNECT;
}
pci_set_master(pdev);
pci_enable_wake(pdev, PCI_D3hot, 0);
pci_enable_wake(pdev, PCI_D3cold, 0);
atl1e_reset_hw(&adapter->hw);
return PCI_ERS_RESULT_RECOVERED;
}
static void atl1e_io_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct atl1e_adapter *adapter = netdev_priv(netdev);
if (netif_running(netdev)) {
if (atl1e_up(adapter)) {
netdev_err(adapter->netdev,
"can't bring device back up after reset\n");
return;
}
}
netif_device_attach(netdev);
}
static int __init atl1e_init_module(void)
{
return pci_register_driver(&atl1e_driver);
}
static void __exit atl1e_exit_module(void)
{
pci_unregister_driver(&atl1e_driver);
}
