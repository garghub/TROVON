static int dmfe_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct dmfe_board_info *db;
struct net_device *dev;
u32 pci_pmr;
int i, err;
DMFE_DBUG(0, "dmfe_init_one()", 0);
if (!printed_version++)
pr_info("%s\n", version);
#ifdef CONFIG_TULIP_DM910X
if ((ent->driver_data == PCI_DM9100_ID && pdev->revision >= 0x30) ||
ent->driver_data == PCI_DM9102_ID) {
struct device_node *dp = pci_device_to_OF_node(pdev);
if (dp && of_get_property(dp, "local-mac-address", NULL)) {
pr_info("skipping on-board DM910x (use tulip)\n");
return -ENODEV;
}
}
#endif
dev = alloc_etherdev(sizeof(*db));
if (dev == NULL)
return -ENOMEM;
SET_NETDEV_DEV(dev, &pdev->dev);
if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
pr_warn("32-bit PCI DMA not available\n");
err = -ENODEV;
goto err_out_free;
}
err = pci_enable_device(pdev);
if (err)
goto err_out_free;
if (!pci_resource_start(pdev, 0)) {
pr_err("I/O base is zero\n");
err = -ENODEV;
goto err_out_disable;
}
if (pci_resource_len(pdev, 0) < (CHK_IO_SIZE(pdev)) ) {
pr_err("Allocated I/O size too small\n");
err = -ENODEV;
goto err_out_disable;
}
#if 0
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0x80);
#endif
if (pci_request_regions(pdev, DRV_NAME)) {
pr_err("Failed to request PCI regions\n");
err = -ENODEV;
goto err_out_disable;
}
db = netdev_priv(dev);
db->desc_pool_ptr = pci_alloc_consistent(pdev, sizeof(struct tx_desc) *
DESC_ALL_CNT + 0x20, &db->desc_pool_dma_ptr);
if (!db->desc_pool_ptr) {
err = -ENOMEM;
goto err_out_res;
}
db->buf_pool_ptr = pci_alloc_consistent(pdev, TX_BUF_ALLOC *
TX_DESC_CNT + 4, &db->buf_pool_dma_ptr);
if (!db->buf_pool_ptr) {
err = -ENOMEM;
goto err_out_free_desc;
}
db->first_tx_desc = (struct tx_desc *) db->desc_pool_ptr;
db->first_tx_desc_dma = db->desc_pool_dma_ptr;
db->buf_pool_start = db->buf_pool_ptr;
db->buf_pool_dma_start = db->buf_pool_dma_ptr;
db->chip_id = ent->driver_data;
db->ioaddr = pci_iomap(pdev, 0, 0);
if (!db->ioaddr) {
err = -ENOMEM;
goto err_out_free_buf;
}
db->chip_revision = pdev->revision;
db->wol_mode = 0;
db->pdev = pdev;
pci_set_drvdata(pdev, dev);
dev->netdev_ops = &netdev_ops;
dev->ethtool_ops = &netdev_ethtool_ops;
netif_carrier_off(dev);
spin_lock_init(&db->lock);
pci_read_config_dword(pdev, 0x50, &pci_pmr);
pci_pmr &= 0x70000;
if ( (pci_pmr == 0x10000) && (db->chip_revision == 0x31) )
db->chip_type = 1;
else
db->chip_type = 0;
for (i = 0; i < 64; i++) {
((__le16 *) db->srom)[i] =
cpu_to_le16(read_srom_word(db->ioaddr, i));
}
for (i = 0; i < 6; i++)
dev->dev_addr[i] = db->srom[20 + i];
err = register_netdev (dev);
if (err)
goto err_out_unmap;
dev_info(&dev->dev, "Davicom DM%04lx at pci%s, %pM, irq %d\n",
ent->driver_data >> 16,
pci_name(pdev), dev->dev_addr, pdev->irq);
pci_set_master(pdev);
return 0;
err_out_unmap:
pci_iounmap(pdev, db->ioaddr);
err_out_free_buf:
pci_free_consistent(pdev, TX_BUF_ALLOC * TX_DESC_CNT + 4,
db->buf_pool_ptr, db->buf_pool_dma_ptr);
err_out_free_desc:
pci_free_consistent(pdev, sizeof(struct tx_desc) * DESC_ALL_CNT + 0x20,
db->desc_pool_ptr, db->desc_pool_dma_ptr);
err_out_res:
pci_release_regions(pdev);
err_out_disable:
pci_disable_device(pdev);
err_out_free:
free_netdev(dev);
return err;
}
static void dmfe_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct dmfe_board_info *db = netdev_priv(dev);
DMFE_DBUG(0, "dmfe_remove_one()", 0);
if (dev) {
unregister_netdev(dev);
pci_iounmap(db->pdev, db->ioaddr);
pci_free_consistent(db->pdev, sizeof(struct tx_desc) *
DESC_ALL_CNT + 0x20, db->desc_pool_ptr,
db->desc_pool_dma_ptr);
pci_free_consistent(db->pdev, TX_BUF_ALLOC * TX_DESC_CNT + 4,
db->buf_pool_ptr, db->buf_pool_dma_ptr);
pci_release_regions(pdev);
free_netdev(dev);
}
DMFE_DBUG(0, "dmfe_remove_one() exit", 0);
}
static int dmfe_open(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
const int irq = db->pdev->irq;
int ret;
DMFE_DBUG(0, "dmfe_open", 0);
ret = request_irq(irq, dmfe_interrupt, IRQF_SHARED, dev->name, dev);
if (ret)
return ret;
db->cr6_data = CR6_DEFAULT | dmfe_cr6_user_set;
db->tx_packet_cnt = 0;
db->tx_queue_cnt = 0;
db->rx_avail_cnt = 0;
db->wait_reset = 0;
db->first_in_callback = 0;
db->NIC_capability = 0xf;
db->PHY_reg4 = 0x1e0;
if ( !chkmode || (db->chip_id == PCI_DM9132_ID) ||
(db->chip_revision >= 0x30) ) {
db->cr6_data |= DMFE_TXTH_256;
db->cr0_data = CR0_DEFAULT;
db->dm910x_chk_mode=4;
} else {
db->cr6_data |= CR6_SFT;
db->cr0_data = 0;
db->dm910x_chk_mode = 1;
}
dmfe_init_dm910x(dev);
netif_wake_queue(dev);
init_timer(&db->timer);
db->timer.expires = DMFE_TIMER_WUT + HZ * 2;
db->timer.data = (unsigned long)dev;
db->timer.function = dmfe_timer;
add_timer(&db->timer);
return 0;
}
static void dmfe_init_dm910x(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
DMFE_DBUG(0, "dmfe_init_dm910x()", 0);
dw32(DCR0, DM910X_RESET);
udelay(100);
dw32(DCR0, db->cr0_data);
udelay(5);
db->phy_addr = 1;
dmfe_parse_srom(db);
db->media_mode = dmfe_media_mode;
dw32(DCR12, 0x180);
if (db->chip_id == PCI_DM9009_ID) {
dw32(DCR12, 0x80);
mdelay(300);
}
dw32(DCR12, 0x0);
if ( !(db->media_mode & 0x10) )
dmfe_set_phyxcer(db);
if ( !(db->media_mode & DMFE_AUTO) )
db->op_mode = db->media_mode;
dmfe_descriptor_init(dev);
update_cr6(db->cr6_data, ioaddr);
if (db->chip_id == PCI_DM9132_ID)
dm9132_id_table(dev);
else
send_filter_frame(dev);
db->cr7_data = CR7_DEFAULT;
dw32(DCR7, db->cr7_data);
dw32(DCR15, db->cr15_data);
db->cr6_data |= CR6_RXSC | CR6_TXSC | 0x40000;
update_cr6(db->cr6_data, ioaddr);
}
static netdev_tx_t dmfe_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
struct tx_desc *txptr;
unsigned long flags;
DMFE_DBUG(0, "dmfe_start_xmit", 0);
if (skb->len > MAX_PACKET_SIZE) {
pr_err("big packet = %d\n", (u16)skb->len);
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
netif_stop_queue(dev);
spin_lock_irqsave(&db->lock, flags);
if (db->tx_queue_cnt >= TX_FREE_DESC_CNT) {
spin_unlock_irqrestore(&db->lock, flags);
pr_err("No Tx resource %ld\n", db->tx_queue_cnt);
return NETDEV_TX_BUSY;
}
dw32(DCR7, 0);
txptr = db->tx_insert_ptr;
skb_copy_from_linear_data(skb, txptr->tx_buf_ptr, skb->len);
txptr->tdes1 = cpu_to_le32(0xe1000000 | skb->len);
db->tx_insert_ptr = txptr->next_tx_desc;
if ( (!db->tx_queue_cnt) && (db->tx_packet_cnt < TX_MAX_SEND_CNT) ) {
txptr->tdes0 = cpu_to_le32(0x80000000);
db->tx_packet_cnt++;
dw32(DCR1, 0x1);
netif_trans_update(dev);
} else {
db->tx_queue_cnt++;
dw32(DCR1, 0x1);
}
if ( db->tx_queue_cnt < TX_FREE_DESC_CNT )
netif_wake_queue(dev);
spin_unlock_irqrestore(&db->lock, flags);
dw32(DCR7, db->cr7_data);
dev_consume_skb_any(skb);
return NETDEV_TX_OK;
}
static int dmfe_stop(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
DMFE_DBUG(0, "dmfe_stop", 0);
netif_stop_queue(dev);
del_timer_sync(&db->timer);
dw32(DCR0, DM910X_RESET);
udelay(100);
dmfe_phy_write(ioaddr, db->phy_addr, 0, 0x8000, db->chip_id);
free_irq(db->pdev->irq, dev);
dmfe_free_rxbuffer(db);
#if 0
printk("FU:%lx EC:%lx LC:%lx NC:%lx LOC:%lx TXJT:%lx RESET:%lx RCR8:%lx FAL:%lx TT:%lx\n",
db->tx_fifo_underrun, db->tx_excessive_collision,
db->tx_late_collision, db->tx_no_carrier, db->tx_loss_carrier,
db->tx_jabber_timeout, db->reset_count, db->reset_cr8,
db->reset_fatal, db->reset_TXtimeout);
#endif
return 0;
}
static irqreturn_t dmfe_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
unsigned long flags;
DMFE_DBUG(0, "dmfe_interrupt()", 0);
spin_lock_irqsave(&db->lock, flags);
db->cr5_data = dr32(DCR5);
dw32(DCR5, db->cr5_data);
if ( !(db->cr5_data & 0xc1) ) {
spin_unlock_irqrestore(&db->lock, flags);
return IRQ_HANDLED;
}
dw32(DCR7, 0);
if (db->cr5_data & 0x2000) {
DMFE_DBUG(1, "System bus error happen. CR5=", db->cr5_data);
db->reset_fatal++;
db->wait_reset = 1;
spin_unlock_irqrestore(&db->lock, flags);
return IRQ_HANDLED;
}
if ( (db->cr5_data & 0x40) && db->rx_avail_cnt )
dmfe_rx_packet(dev, db);
if (db->rx_avail_cnt<RX_DESC_CNT)
allocate_rx_buffer(dev);
if ( db->cr5_data & 0x01)
dmfe_free_tx_pkt(dev, db);
if (db->dm910x_chk_mode & 0x2) {
db->dm910x_chk_mode = 0x4;
db->cr6_data |= 0x100;
update_cr6(db->cr6_data, ioaddr);
}
dw32(DCR7, db->cr7_data);
spin_unlock_irqrestore(&db->lock, flags);
return IRQ_HANDLED;
}
static void poll_dmfe (struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
const int irq = db->pdev->irq;
disable_irq(irq);
dmfe_interrupt (irq, dev);
enable_irq(irq);
}
static void dmfe_free_tx_pkt(struct net_device *dev, struct dmfe_board_info *db)
{
struct tx_desc *txptr;
void __iomem *ioaddr = db->ioaddr;
u32 tdes0;
txptr = db->tx_remove_ptr;
while(db->tx_packet_cnt) {
tdes0 = le32_to_cpu(txptr->tdes0);
if (tdes0 & 0x80000000)
break;
db->tx_packet_cnt--;
dev->stats.tx_packets++;
if ( tdes0 != 0x7fffffff ) {
dev->stats.collisions += (tdes0 >> 3) & 0xf;
dev->stats.tx_bytes += le32_to_cpu(txptr->tdes1) & 0x7ff;
if (tdes0 & TDES0_ERR_MASK) {
dev->stats.tx_errors++;
if (tdes0 & 0x0002) {
db->tx_fifo_underrun++;
if ( !(db->cr6_data & CR6_SFT) ) {
db->cr6_data = db->cr6_data | CR6_SFT;
update_cr6(db->cr6_data, ioaddr);
}
}
if (tdes0 & 0x0100)
db->tx_excessive_collision++;
if (tdes0 & 0x0200)
db->tx_late_collision++;
if (tdes0 & 0x0400)
db->tx_no_carrier++;
if (tdes0 & 0x0800)
db->tx_loss_carrier++;
if (tdes0 & 0x4000)
db->tx_jabber_timeout++;
}
}
txptr = txptr->next_tx_desc;
}
db->tx_remove_ptr = txptr;
if ( (db->tx_packet_cnt < TX_MAX_SEND_CNT) && db->tx_queue_cnt ) {
txptr->tdes0 = cpu_to_le32(0x80000000);
db->tx_packet_cnt++;
db->tx_queue_cnt--;
dw32(DCR1, 0x1);
netif_trans_update(dev);
}
if ( db->tx_queue_cnt < TX_WAKE_DESC_CNT )
netif_wake_queue(dev);
}
static inline u32 cal_CRC(unsigned char * Data, unsigned int Len, u8 flag)
{
u32 crc = crc32(~0, Data, Len);
if (flag) crc = ~crc;
return crc;
}
static void dmfe_rx_packet(struct net_device *dev, struct dmfe_board_info *db)
{
struct rx_desc *rxptr;
struct sk_buff *skb, *newskb;
int rxlen;
u32 rdes0;
rxptr = db->rx_ready_ptr;
while(db->rx_avail_cnt) {
rdes0 = le32_to_cpu(rxptr->rdes0);
if (rdes0 & 0x80000000)
break;
db->rx_avail_cnt--;
db->interval_rx_cnt++;
pci_unmap_single(db->pdev, le32_to_cpu(rxptr->rdes2),
RX_ALLOC_SIZE, PCI_DMA_FROMDEVICE);
if ( (rdes0 & 0x300) != 0x300) {
DMFE_DBUG(0, "Reuse SK buffer, rdes0", rdes0);
dmfe_reuse_skb(db, rxptr->rx_skb_ptr);
} else {
rxlen = ( (rdes0 >> 16) & 0x3fff) - 4;
if (rdes0 & 0x8000) {
dev->stats.rx_errors++;
if (rdes0 & 1)
dev->stats.rx_fifo_errors++;
if (rdes0 & 2)
dev->stats.rx_crc_errors++;
if (rdes0 & 0x80)
dev->stats.rx_length_errors++;
}
if ( !(rdes0 & 0x8000) ||
((db->cr6_data & CR6_PM) && (rxlen>6)) ) {
skb = rxptr->rx_skb_ptr;
if ( (db->dm910x_chk_mode & 1) &&
(cal_CRC(skb->data, rxlen, 1) !=
(*(u32 *) (skb->data+rxlen) ))) {
dmfe_reuse_skb(db, rxptr->rx_skb_ptr);
db->dm910x_chk_mode = 3;
} else {
if ((rxlen < RX_COPY_SIZE) &&
((newskb = netdev_alloc_skb(dev, rxlen + 2))
!= NULL)) {
skb = newskb;
skb_reserve(skb, 2);
skb_copy_from_linear_data(rxptr->rx_skb_ptr,
skb_put(skb, rxlen),
rxlen);
dmfe_reuse_skb(db, rxptr->rx_skb_ptr);
} else
skb_put(skb, rxlen);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += rxlen;
}
} else {
DMFE_DBUG(0, "Reuse SK buffer, rdes0", rdes0);
dmfe_reuse_skb(db, rxptr->rx_skb_ptr);
}
}
rxptr = rxptr->next_rx_desc;
}
db->rx_ready_ptr = rxptr;
}
static void dmfe_set_filter_mode(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
unsigned long flags;
int mc_count = netdev_mc_count(dev);
DMFE_DBUG(0, "dmfe_set_filter_mode()", 0);
spin_lock_irqsave(&db->lock, flags);
if (dev->flags & IFF_PROMISC) {
DMFE_DBUG(0, "Enable PROM Mode", 0);
db->cr6_data |= CR6_PM | CR6_PBF;
update_cr6(db->cr6_data, db->ioaddr);
spin_unlock_irqrestore(&db->lock, flags);
return;
}
if (dev->flags & IFF_ALLMULTI || mc_count > DMFE_MAX_MULTICAST) {
DMFE_DBUG(0, "Pass all multicast address", mc_count);
db->cr6_data &= ~(CR6_PM | CR6_PBF);
db->cr6_data |= CR6_PAM;
spin_unlock_irqrestore(&db->lock, flags);
return;
}
DMFE_DBUG(0, "Set multicast address", mc_count);
if (db->chip_id == PCI_DM9132_ID)
dm9132_id_table(dev);
else
send_filter_frame(dev);
spin_unlock_irqrestore(&db->lock, flags);
}
static void dmfe_ethtool_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct dmfe_board_info *np = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(np->pdev), sizeof(info->bus_info));
}
static int dmfe_ethtool_set_wol(struct net_device *dev,
struct ethtool_wolinfo *wolinfo)
{
struct dmfe_board_info *db = netdev_priv(dev);
if (wolinfo->wolopts & (WAKE_UCAST | WAKE_MCAST | WAKE_BCAST |
WAKE_ARP | WAKE_MAGICSECURE))
return -EOPNOTSUPP;
db->wol_mode = wolinfo->wolopts;
return 0;
}
static void dmfe_ethtool_get_wol(struct net_device *dev,
struct ethtool_wolinfo *wolinfo)
{
struct dmfe_board_info *db = netdev_priv(dev);
wolinfo->supported = WAKE_PHY | WAKE_MAGIC;
wolinfo->wolopts = db->wol_mode;
}
static void dmfe_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
u32 tmp_cr8;
unsigned char tmp_cr12;
unsigned long flags;
int link_ok, link_ok_phy;
DMFE_DBUG(0, "dmfe_timer()", 0);
spin_lock_irqsave(&db->lock, flags);
if (db->first_in_callback == 0) {
db->first_in_callback = 1;
if (db->chip_type && (db->chip_id==PCI_DM9102_ID)) {
db->cr6_data &= ~0x40000;
update_cr6(db->cr6_data, ioaddr);
dmfe_phy_write(ioaddr, db->phy_addr, 0, 0x1000, db->chip_id);
db->cr6_data |= 0x40000;
update_cr6(db->cr6_data, ioaddr);
db->timer.expires = DMFE_TIMER_WUT + HZ * 2;
add_timer(&db->timer);
spin_unlock_irqrestore(&db->lock, flags);
return;
}
}
if ( (db->dm910x_chk_mode & 0x1) &&
(dev->stats.rx_packets > MAX_CHECK_PACKET) )
db->dm910x_chk_mode = 0x4;
tmp_cr8 = dr32(DCR8);
if ( (db->interval_rx_cnt==0) && (tmp_cr8) ) {
db->reset_cr8++;
db->wait_reset = 1;
}
db->interval_rx_cnt = 0;
if ( db->tx_packet_cnt &&
time_after(jiffies, dev_trans_start(dev) + DMFE_TX_KICK) ) {
dw32(DCR1, 0x1);
if (time_after(jiffies, dev_trans_start(dev) + DMFE_TX_TIMEOUT) ) {
db->reset_TXtimeout++;
db->wait_reset = 1;
dev_warn(&dev->dev, "Tx timeout - resetting\n");
}
}
if (db->wait_reset) {
DMFE_DBUG(0, "Dynamic Reset device", db->tx_packet_cnt);
db->reset_count++;
dmfe_dynamic_reset(dev);
db->first_in_callback = 0;
db->timer.expires = DMFE_TIMER_WUT;
add_timer(&db->timer);
spin_unlock_irqrestore(&db->lock, flags);
return;
}
if (db->chip_id == PCI_DM9132_ID)
tmp_cr12 = dr8(DCR9 + 3);
else
tmp_cr12 = dr8(DCR12);
if ( ((db->chip_id == PCI_DM9102_ID) &&
(db->chip_revision == 0x30)) ||
((db->chip_id == PCI_DM9132_ID) &&
(db->chip_revision == 0x10)) ) {
if (tmp_cr12 & 2)
link_ok = 0;
else
link_ok = 1;
}
else
link_ok = (tmp_cr12 & 0x43) ? 1 : 0;
dmfe_phy_read (db->ioaddr, db->phy_addr, 1, db->chip_id);
link_ok_phy = (dmfe_phy_read (db->ioaddr,
db->phy_addr, 1, db->chip_id) & 0x4) ? 1 : 0;
if (link_ok_phy != link_ok) {
DMFE_DBUG (0, "PHY and chip report different link status", 0);
link_ok = link_ok | link_ok_phy;
}
if ( !link_ok && netif_carrier_ok(dev)) {
DMFE_DBUG(0, "Link Failed", tmp_cr12);
netif_carrier_off(dev);
if ( !(db->media_mode & 0x38) )
dmfe_phy_write(db->ioaddr, db->phy_addr,
0, 0x1000, db->chip_id);
if (db->media_mode & DMFE_AUTO) {
db->cr6_data|=0x00040000;
db->cr6_data&=~0x00000200;
update_cr6(db->cr6_data, ioaddr);
}
} else if (!netif_carrier_ok(dev)) {
DMFE_DBUG(0, "Link link OK", tmp_cr12);
if ( !(db->media_mode & DMFE_AUTO) || !dmfe_sense_speed(db)) {
netif_carrier_on(dev);
SHOW_MEDIA_TYPE(db->op_mode);
}
dmfe_process_mode(db);
}
if (db->HPNA_command & 0xf00) {
db->HPNA_timer--;
if (!db->HPNA_timer)
dmfe_HPNA_remote_cmd_chk(db);
}
db->timer.expires = DMFE_TIMER_WUT;
add_timer(&db->timer);
spin_unlock_irqrestore(&db->lock, flags);
}
static void dmfe_dynamic_reset(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
DMFE_DBUG(0, "dmfe_dynamic_reset()", 0);
db->cr6_data &= ~(CR6_RXSC | CR6_TXSC);
update_cr6(db->cr6_data, ioaddr);
dw32(DCR7, 0);
dw32(DCR5, dr32(DCR5));
netif_stop_queue(dev);
dmfe_free_rxbuffer(db);
db->tx_packet_cnt = 0;
db->tx_queue_cnt = 0;
db->rx_avail_cnt = 0;
netif_carrier_off(dev);
db->wait_reset = 0;
dmfe_init_dm910x(dev);
netif_wake_queue(dev);
}
static void dmfe_free_rxbuffer(struct dmfe_board_info * db)
{
DMFE_DBUG(0, "dmfe_free_rxbuffer()", 0);
while (db->rx_avail_cnt) {
dev_kfree_skb(db->rx_ready_ptr->rx_skb_ptr);
db->rx_ready_ptr = db->rx_ready_ptr->next_rx_desc;
db->rx_avail_cnt--;
}
}
static void dmfe_reuse_skb(struct dmfe_board_info *db, struct sk_buff * skb)
{
struct rx_desc *rxptr = db->rx_insert_ptr;
if (!(rxptr->rdes0 & cpu_to_le32(0x80000000))) {
rxptr->rx_skb_ptr = skb;
rxptr->rdes2 = cpu_to_le32( pci_map_single(db->pdev,
skb->data, RX_ALLOC_SIZE, PCI_DMA_FROMDEVICE) );
wmb();
rxptr->rdes0 = cpu_to_le32(0x80000000);
db->rx_avail_cnt++;
db->rx_insert_ptr = rxptr->next_rx_desc;
} else
DMFE_DBUG(0, "SK Buffer reuse method error", db->rx_avail_cnt);
}
static void dmfe_descriptor_init(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
struct tx_desc *tmp_tx;
struct rx_desc *tmp_rx;
unsigned char *tmp_buf;
dma_addr_t tmp_tx_dma, tmp_rx_dma;
dma_addr_t tmp_buf_dma;
int i;
DMFE_DBUG(0, "dmfe_descriptor_init()", 0);
db->tx_insert_ptr = db->first_tx_desc;
db->tx_remove_ptr = db->first_tx_desc;
dw32(DCR4, db->first_tx_desc_dma);
db->first_rx_desc = (void *)db->first_tx_desc +
sizeof(struct tx_desc) * TX_DESC_CNT;
db->first_rx_desc_dma = db->first_tx_desc_dma +
sizeof(struct tx_desc) * TX_DESC_CNT;
db->rx_insert_ptr = db->first_rx_desc;
db->rx_ready_ptr = db->first_rx_desc;
dw32(DCR3, db->first_rx_desc_dma);
tmp_buf = db->buf_pool_start;
tmp_buf_dma = db->buf_pool_dma_start;
tmp_tx_dma = db->first_tx_desc_dma;
for (tmp_tx = db->first_tx_desc, i = 0; i < TX_DESC_CNT; i++, tmp_tx++) {
tmp_tx->tx_buf_ptr = tmp_buf;
tmp_tx->tdes0 = cpu_to_le32(0);
tmp_tx->tdes1 = cpu_to_le32(0x81000000);
tmp_tx->tdes2 = cpu_to_le32(tmp_buf_dma);
tmp_tx_dma += sizeof(struct tx_desc);
tmp_tx->tdes3 = cpu_to_le32(tmp_tx_dma);
tmp_tx->next_tx_desc = tmp_tx + 1;
tmp_buf = tmp_buf + TX_BUF_ALLOC;
tmp_buf_dma = tmp_buf_dma + TX_BUF_ALLOC;
}
(--tmp_tx)->tdes3 = cpu_to_le32(db->first_tx_desc_dma);
tmp_tx->next_tx_desc = db->first_tx_desc;
tmp_rx_dma=db->first_rx_desc_dma;
for (tmp_rx = db->first_rx_desc, i = 0; i < RX_DESC_CNT; i++, tmp_rx++) {
tmp_rx->rdes0 = cpu_to_le32(0);
tmp_rx->rdes1 = cpu_to_le32(0x01000600);
tmp_rx_dma += sizeof(struct rx_desc);
tmp_rx->rdes3 = cpu_to_le32(tmp_rx_dma);
tmp_rx->next_rx_desc = tmp_rx + 1;
}
(--tmp_rx)->rdes3 = cpu_to_le32(db->first_rx_desc_dma);
tmp_rx->next_rx_desc = db->first_rx_desc;
allocate_rx_buffer(dev);
}
static void update_cr6(u32 cr6_data, void __iomem *ioaddr)
{
u32 cr6_tmp;
cr6_tmp = cr6_data & ~0x2002;
dw32(DCR6, cr6_tmp);
udelay(5);
dw32(DCR6, cr6_data);
udelay(5);
}
static void dm9132_id_table(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr + 0xc0;
u16 *addrptr = (u16 *)dev->dev_addr;
struct netdev_hw_addr *ha;
u16 i, hash_table[4];
for (i = 0; i < 3; i++) {
dw16(0, addrptr[i]);
ioaddr += 4;
}
memset(hash_table, 0, sizeof(hash_table));
hash_table[3] = 0x8000;
netdev_for_each_mc_addr(ha, dev) {
u32 hash_val = cal_CRC((char *)ha->addr, 6, 0) & 0x3f;
hash_table[hash_val / 16] |= (u16) 1 << (hash_val % 16);
}
for (i = 0; i < 4; i++, ioaddr += 4)
dw16(0, hash_table[i]);
}
static void send_filter_frame(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
struct netdev_hw_addr *ha;
struct tx_desc *txptr;
u16 * addrptr;
u32 * suptr;
int i;
DMFE_DBUG(0, "send_filter_frame()", 0);
txptr = db->tx_insert_ptr;
suptr = (u32 *) txptr->tx_buf_ptr;
addrptr = (u16 *) dev->dev_addr;
*suptr++ = addrptr[0];
*suptr++ = addrptr[1];
*suptr++ = addrptr[2];
*suptr++ = 0xffff;
*suptr++ = 0xffff;
*suptr++ = 0xffff;
netdev_for_each_mc_addr(ha, dev) {
addrptr = (u16 *) ha->addr;
*suptr++ = addrptr[0];
*suptr++ = addrptr[1];
*suptr++ = addrptr[2];
}
for (i = netdev_mc_count(dev); i < 14; i++) {
*suptr++ = 0xffff;
*suptr++ = 0xffff;
*suptr++ = 0xffff;
}
db->tx_insert_ptr = txptr->next_tx_desc;
txptr->tdes1 = cpu_to_le32(0x890000c0);
if (!db->tx_packet_cnt) {
void __iomem *ioaddr = db->ioaddr;
db->tx_packet_cnt++;
txptr->tdes0 = cpu_to_le32(0x80000000);
update_cr6(db->cr6_data | 0x2000, ioaddr);
dw32(DCR1, 0x1);
update_cr6(db->cr6_data, ioaddr);
netif_trans_update(dev);
} else
db->tx_queue_cnt++;
}
static void allocate_rx_buffer(struct net_device *dev)
{
struct dmfe_board_info *db = netdev_priv(dev);
struct rx_desc *rxptr;
struct sk_buff *skb;
rxptr = db->rx_insert_ptr;
while(db->rx_avail_cnt < RX_DESC_CNT) {
if ( ( skb = netdev_alloc_skb(dev, RX_ALLOC_SIZE) ) == NULL )
break;
rxptr->rx_skb_ptr = skb;
rxptr->rdes2 = cpu_to_le32( pci_map_single(db->pdev, skb->data,
RX_ALLOC_SIZE, PCI_DMA_FROMDEVICE) );
wmb();
rxptr->rdes0 = cpu_to_le32(0x80000000);
rxptr = rxptr->next_rx_desc;
db->rx_avail_cnt++;
}
db->rx_insert_ptr = rxptr;
}
static void srom_clk_write(void __iomem *ioaddr, u32 data)
{
static const u32 cmd[] = {
CR9_SROM_READ | CR9_SRCS,
CR9_SROM_READ | CR9_SRCS | CR9_SRCLK,
CR9_SROM_READ | CR9_SRCS
};
int i;
for (i = 0; i < ARRAY_SIZE(cmd); i++) {
dw32(DCR9, data | cmd[i]);
udelay(5);
}
}
static u16 read_srom_word(void __iomem *ioaddr, int offset)
{
u16 srom_data;
int i;
dw32(DCR9, CR9_SROM_READ);
udelay(5);
dw32(DCR9, CR9_SROM_READ | CR9_SRCS);
udelay(5);
srom_clk_write(ioaddr, SROM_DATA_1);
srom_clk_write(ioaddr, SROM_DATA_1);
srom_clk_write(ioaddr, SROM_DATA_0);
for (i = 5; i >= 0; i--) {
srom_data = (offset & (1 << i)) ? SROM_DATA_1 : SROM_DATA_0;
srom_clk_write(ioaddr, srom_data);
}
dw32(DCR9, CR9_SROM_READ | CR9_SRCS);
udelay(5);
for (i = 16; i > 0; i--) {
dw32(DCR9, CR9_SROM_READ | CR9_SRCS | CR9_SRCLK);
udelay(5);
srom_data = (srom_data << 1) |
((dr32(DCR9) & CR9_CRDOUT) ? 1 : 0);
dw32(DCR9, CR9_SROM_READ | CR9_SRCS);
udelay(5);
}
dw32(DCR9, CR9_SROM_READ);
udelay(5);
return srom_data;
}
static u8 dmfe_sense_speed(struct dmfe_board_info *db)
{
void __iomem *ioaddr = db->ioaddr;
u8 ErrFlag = 0;
u16 phy_mode;
update_cr6(db->cr6_data & ~0x40000, ioaddr);
phy_mode = dmfe_phy_read(db->ioaddr, db->phy_addr, 1, db->chip_id);
phy_mode = dmfe_phy_read(db->ioaddr, db->phy_addr, 1, db->chip_id);
if ( (phy_mode & 0x24) == 0x24 ) {
if (db->chip_id == PCI_DM9132_ID)
phy_mode = dmfe_phy_read(db->ioaddr,
db->phy_addr, 7, db->chip_id) & 0xf000;
else
phy_mode = dmfe_phy_read(db->ioaddr,
db->phy_addr, 17, db->chip_id) & 0xf000;
switch (phy_mode) {
case 0x1000: db->op_mode = DMFE_10MHF; break;
case 0x2000: db->op_mode = DMFE_10MFD; break;
case 0x4000: db->op_mode = DMFE_100MHF; break;
case 0x8000: db->op_mode = DMFE_100MFD; break;
default: db->op_mode = DMFE_10MHF;
ErrFlag = 1;
break;
}
} else {
db->op_mode = DMFE_10MHF;
DMFE_DBUG(0, "Link Failed :", phy_mode);
ErrFlag = 1;
}
return ErrFlag;
}
static void dmfe_set_phyxcer(struct dmfe_board_info *db)
{
void __iomem *ioaddr = db->ioaddr;
u16 phy_reg;
db->cr6_data &= ~0x40000;
update_cr6(db->cr6_data, ioaddr);
if (db->chip_id == PCI_DM9009_ID) {
phy_reg = dmfe_phy_read(db->ioaddr,
db->phy_addr, 18, db->chip_id) & ~0x1000;
dmfe_phy_write(db->ioaddr,
db->phy_addr, 18, phy_reg, db->chip_id);
}
phy_reg = dmfe_phy_read(db->ioaddr, db->phy_addr, 4, db->chip_id) & ~0x01e0;
if (db->media_mode & DMFE_AUTO) {
phy_reg |= db->PHY_reg4;
} else {
switch(db->media_mode) {
case DMFE_10MHF: phy_reg |= 0x20; break;
case DMFE_10MFD: phy_reg |= 0x40; break;
case DMFE_100MHF: phy_reg |= 0x80; break;
case DMFE_100MFD: phy_reg |= 0x100; break;
}
if (db->chip_id == PCI_DM9009_ID) phy_reg &= 0x61;
}
if ( !(phy_reg & 0x01e0)) {
phy_reg|=db->PHY_reg4;
db->media_mode|=DMFE_AUTO;
}
dmfe_phy_write(db->ioaddr, db->phy_addr, 4, phy_reg, db->chip_id);
if ( db->chip_type && (db->chip_id == PCI_DM9102_ID) )
dmfe_phy_write(db->ioaddr, db->phy_addr, 0, 0x1800, db->chip_id);
if ( !db->chip_type )
dmfe_phy_write(db->ioaddr, db->phy_addr, 0, 0x1200, db->chip_id);
}
static void dmfe_process_mode(struct dmfe_board_info *db)
{
u16 phy_reg;
if (db->op_mode & 0x4)
db->cr6_data |= CR6_FDM;
else
db->cr6_data &= ~CR6_FDM;
if (db->op_mode & 0x10)
db->cr6_data |= 0x40000;
else
db->cr6_data &= ~0x40000;
update_cr6(db->cr6_data, db->ioaddr);
if ( !(db->media_mode & 0x18)) {
phy_reg = dmfe_phy_read(db->ioaddr, db->phy_addr, 6, db->chip_id);
if ( !(phy_reg & 0x1) ) {
phy_reg = 0x0;
switch(db->op_mode) {
case DMFE_10MHF: phy_reg = 0x0; break;
case DMFE_10MFD: phy_reg = 0x100; break;
case DMFE_100MHF: phy_reg = 0x2000; break;
case DMFE_100MFD: phy_reg = 0x2100; break;
}
dmfe_phy_write(db->ioaddr,
db->phy_addr, 0, phy_reg, db->chip_id);
if ( db->chip_type && (db->chip_id == PCI_DM9102_ID) )
mdelay(20);
dmfe_phy_write(db->ioaddr,
db->phy_addr, 0, phy_reg, db->chip_id);
}
}
}
static void dmfe_phy_write(void __iomem *ioaddr, u8 phy_addr, u8 offset,
u16 phy_data, u32 chip_id)
{
u16 i;
if (chip_id == PCI_DM9132_ID) {
dw16(0x80 + offset * 4, phy_data);
} else {
for (i = 0; i < 35; i++)
dmfe_phy_write_1bit(ioaddr, PHY_DATA_1);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_0);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_1);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_0);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_1);
for (i = 0x10; i > 0; i = i >> 1)
dmfe_phy_write_1bit(ioaddr,
phy_addr & i ? PHY_DATA_1 : PHY_DATA_0);
for (i = 0x10; i > 0; i = i >> 1)
dmfe_phy_write_1bit(ioaddr,
offset & i ? PHY_DATA_1 : PHY_DATA_0);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_1);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_0);
for ( i = 0x8000; i > 0; i >>= 1)
dmfe_phy_write_1bit(ioaddr,
phy_data & i ? PHY_DATA_1 : PHY_DATA_0);
}
}
static u16 dmfe_phy_read(void __iomem *ioaddr, u8 phy_addr, u8 offset, u32 chip_id)
{
int i;
u16 phy_data;
if (chip_id == PCI_DM9132_ID) {
phy_data = dr16(0x80 + offset * 4);
} else {
for (i = 0; i < 35; i++)
dmfe_phy_write_1bit(ioaddr, PHY_DATA_1);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_0);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_1);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_1);
dmfe_phy_write_1bit(ioaddr, PHY_DATA_0);
for (i = 0x10; i > 0; i = i >> 1)
dmfe_phy_write_1bit(ioaddr,
phy_addr & i ? PHY_DATA_1 : PHY_DATA_0);
for (i = 0x10; i > 0; i = i >> 1)
dmfe_phy_write_1bit(ioaddr,
offset & i ? PHY_DATA_1 : PHY_DATA_0);
dmfe_phy_read_1bit(ioaddr);
for (phy_data = 0, i = 0; i < 16; i++) {
phy_data <<= 1;
phy_data |= dmfe_phy_read_1bit(ioaddr);
}
}
return phy_data;
}
static void dmfe_phy_write_1bit(void __iomem *ioaddr, u32 phy_data)
{
dw32(DCR9, phy_data);
udelay(1);
dw32(DCR9, phy_data | MDCLKH);
udelay(1);
dw32(DCR9, phy_data);
udelay(1);
}
static u16 dmfe_phy_read_1bit(void __iomem *ioaddr)
{
u16 phy_data;
dw32(DCR9, 0x50000);
udelay(1);
phy_data = (dr32(DCR9) >> 19) & 0x1;
dw32(DCR9, 0x40000);
udelay(1);
return phy_data;
}
static void dmfe_parse_srom(struct dmfe_board_info * db)
{
char * srom = db->srom;
int dmfe_mode, tmp_reg;
DMFE_DBUG(0, "dmfe_parse_srom() ", 0);
db->cr15_data = CR15_DEFAULT;
if ( ( (int) srom[18] & 0xff) == SROM_V41_CODE) {
db->NIC_capability = le16_to_cpup((__le16 *) (srom + 34));
db->PHY_reg4 = 0;
for (tmp_reg = 1; tmp_reg < 0x10; tmp_reg <<= 1) {
switch( db->NIC_capability & tmp_reg ) {
case 0x1: db->PHY_reg4 |= 0x0020; break;
case 0x2: db->PHY_reg4 |= 0x0040; break;
case 0x4: db->PHY_reg4 |= 0x0080; break;
case 0x8: db->PHY_reg4 |= 0x0100; break;
}
}
dmfe_mode = (le32_to_cpup((__le32 *) (srom + 34)) &
le32_to_cpup((__le32 *) (srom + 36)));
switch(dmfe_mode) {
case 0x4: dmfe_media_mode = DMFE_100MHF; break;
case 0x2: dmfe_media_mode = DMFE_10MFD; break;
case 0x8: dmfe_media_mode = DMFE_100MFD; break;
case 0x100:
case 0x200: dmfe_media_mode = DMFE_1M_HPNA; break;
}
if ( (SF_mode & 0x1) || (srom[43] & 0x80) )
db->cr15_data |= 0x40;
if ( (SF_mode & 0x2) || (srom[40] & 0x1) )
db->cr15_data |= 0x400;
if ( (SF_mode & 0x4) || (srom[40] & 0xe) )
db->cr15_data |= 0x9800;
}
db->HPNA_command = 1;
if (HPNA_rx_cmd == 0)
db->HPNA_command |= 0x8000;
if (HPNA_tx_cmd == 1)
switch(HPNA_mode) {
case 0: db->HPNA_command |= 0x0904; break;
case 1: db->HPNA_command |= 0x0a00; break;
case 2: db->HPNA_command |= 0x0506; break;
case 3: db->HPNA_command |= 0x0602; break;
}
else
switch(HPNA_mode) {
case 0: db->HPNA_command |= 0x0004; break;
case 1: db->HPNA_command |= 0x0000; break;
case 2: db->HPNA_command |= 0x0006; break;
case 3: db->HPNA_command |= 0x0002; break;
}
db->HPNA_present = 0;
update_cr6(db->cr6_data | 0x40000, db->ioaddr);
tmp_reg = dmfe_phy_read(db->ioaddr, db->phy_addr, 3, db->chip_id);
if ( ( tmp_reg & 0xfff0 ) == 0xb900 ) {
db->HPNA_timer = 8;
if ( dmfe_phy_read(db->ioaddr, db->phy_addr, 31, db->chip_id) == 0x4404) {
db->HPNA_present = 1;
dmfe_program_DM9801(db, tmp_reg);
} else {
db->HPNA_present = 2;
dmfe_program_DM9802(db);
}
}
}
static void dmfe_program_DM9801(struct dmfe_board_info * db, int HPNA_rev)
{
uint reg17, reg25;
if ( !HPNA_NoiseFloor ) HPNA_NoiseFloor = DM9801_NOISE_FLOOR;
switch(HPNA_rev) {
case 0xb900:
db->HPNA_command |= 0x1000;
reg25 = dmfe_phy_read(db->ioaddr, db->phy_addr, 24, db->chip_id);
reg25 = ( (reg25 + HPNA_NoiseFloor) & 0xff) | 0xf000;
reg17 = dmfe_phy_read(db->ioaddr, db->phy_addr, 17, db->chip_id);
break;
case 0xb901:
reg25 = dmfe_phy_read(db->ioaddr, db->phy_addr, 25, db->chip_id);
reg25 = (reg25 & 0xff00) + HPNA_NoiseFloor;
reg17 = dmfe_phy_read(db->ioaddr, db->phy_addr, 17, db->chip_id);
reg17 = (reg17 & 0xfff0) + HPNA_NoiseFloor + 3;
break;
case 0xb902:
case 0xb903:
default:
db->HPNA_command |= 0x1000;
reg25 = dmfe_phy_read(db->ioaddr, db->phy_addr, 25, db->chip_id);
reg25 = (reg25 & 0xff00) + HPNA_NoiseFloor - 5;
reg17 = dmfe_phy_read(db->ioaddr, db->phy_addr, 17, db->chip_id);
reg17 = (reg17 & 0xfff0) + HPNA_NoiseFloor;
break;
}
dmfe_phy_write(db->ioaddr, db->phy_addr, 16, db->HPNA_command, db->chip_id);
dmfe_phy_write(db->ioaddr, db->phy_addr, 17, reg17, db->chip_id);
dmfe_phy_write(db->ioaddr, db->phy_addr, 25, reg25, db->chip_id);
}
static void dmfe_program_DM9802(struct dmfe_board_info * db)
{
uint phy_reg;
if ( !HPNA_NoiseFloor ) HPNA_NoiseFloor = DM9802_NOISE_FLOOR;
dmfe_phy_write(db->ioaddr, db->phy_addr, 16, db->HPNA_command, db->chip_id);
phy_reg = dmfe_phy_read(db->ioaddr, db->phy_addr, 25, db->chip_id);
phy_reg = ( phy_reg & 0xff00) + HPNA_NoiseFloor;
dmfe_phy_write(db->ioaddr, db->phy_addr, 25, phy_reg, db->chip_id);
}
static void dmfe_HPNA_remote_cmd_chk(struct dmfe_board_info * db)
{
uint phy_reg;
phy_reg = dmfe_phy_read(db->ioaddr, db->phy_addr, 17, db->chip_id) & 0x60;
switch(phy_reg) {
case 0x00: phy_reg = 0x0a00;break;
case 0x20: phy_reg = 0x0900;break;
case 0x40: phy_reg = 0x0600;break;
case 0x60: phy_reg = 0x0500;break;
}
if ( phy_reg != (db->HPNA_command & 0x0f00) ) {
dmfe_phy_write(db->ioaddr, db->phy_addr, 16, db->HPNA_command,
db->chip_id);
db->HPNA_timer=8;
} else
db->HPNA_timer=600;
}
static int dmfe_suspend(struct pci_dev *pci_dev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pci_dev);
struct dmfe_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
u32 tmp;
netif_device_detach(dev);
db->cr6_data &= ~(CR6_RXSC | CR6_TXSC);
update_cr6(db->cr6_data, ioaddr);
dw32(DCR7, 0);
dw32(DCR5, dr32(DCR5));
dmfe_free_rxbuffer(db);
pci_read_config_dword(pci_dev, 0x40, &tmp);
tmp &= ~(DMFE_WOL_LINKCHANGE|DMFE_WOL_MAGICPACKET);
if (db->wol_mode & WAKE_PHY)
tmp |= DMFE_WOL_LINKCHANGE;
if (db->wol_mode & WAKE_MAGIC)
tmp |= DMFE_WOL_MAGICPACKET;
pci_write_config_dword(pci_dev, 0x40, tmp);
pci_enable_wake(pci_dev, PCI_D3hot, 1);
pci_enable_wake(pci_dev, PCI_D3cold, 1);
pci_save_state(pci_dev);
pci_set_power_state(pci_dev, pci_choose_state (pci_dev, state));
return 0;
}
static int dmfe_resume(struct pci_dev *pci_dev)
{
struct net_device *dev = pci_get_drvdata(pci_dev);
u32 tmp;
pci_set_power_state(pci_dev, PCI_D0);
pci_restore_state(pci_dev);
dmfe_init_dm910x(dev);
pci_read_config_dword(pci_dev, 0x40, &tmp);
tmp &= ~(DMFE_WOL_LINKCHANGE | DMFE_WOL_MAGICPACKET);
pci_write_config_dword(pci_dev, 0x40, tmp);
pci_enable_wake(pci_dev, PCI_D3hot, 0);
pci_enable_wake(pci_dev, PCI_D3cold, 0);
netif_device_attach(dev);
return 0;
}
static int __init dmfe_init_module(void)
{
int rc;
pr_info("%s\n", version);
printed_version = 1;
DMFE_DBUG(0, "init_module() ", debug);
if (debug)
dmfe_debug = debug;
if (cr6set)
dmfe_cr6_user_set = cr6set;
switch(mode) {
case DMFE_10MHF:
case DMFE_100MHF:
case DMFE_10MFD:
case DMFE_100MFD:
case DMFE_1M_HPNA:
dmfe_media_mode = mode;
break;
default:dmfe_media_mode = DMFE_AUTO;
break;
}
if (HPNA_mode > 4)
HPNA_mode = 0;
if (HPNA_rx_cmd > 1)
HPNA_rx_cmd = 0;
if (HPNA_tx_cmd > 1)
HPNA_tx_cmd = 0;
if (HPNA_NoiseFloor > 15)
HPNA_NoiseFloor = 0;
rc = pci_register_driver(&dmfe_driver);
if (rc < 0)
return rc;
return 0;
}
static void __exit dmfe_cleanup_module(void)
{
DMFE_DBUG(0, "dmfe_cleanup_module() ", debug);
pci_unregister_driver(&dmfe_driver);
}
