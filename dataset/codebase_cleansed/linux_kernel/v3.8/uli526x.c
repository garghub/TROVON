static void srom_clk_write(struct uli526x_board_info *db, u32 data)
{
void __iomem *ioaddr = db->ioaddr;
uw32(DCR9, data | CR9_SROM_READ | CR9_SRCS);
udelay(5);
uw32(DCR9, data | CR9_SROM_READ | CR9_SRCS | CR9_SRCLK);
udelay(5);
uw32(DCR9, data | CR9_SROM_READ | CR9_SRCS);
udelay(5);
}
static int uli526x_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct uli526x_board_info *db;
struct net_device *dev;
void __iomem *ioaddr;
int i, err;
ULI526X_DBUG(0, "uli526x_init_one()", 0);
if (!printed_version++)
pr_info("%s\n", version);
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
if (pci_resource_len(pdev, 0) < (ULI526X_IO_SIZE) ) {
pr_err("Allocated I/O size too small\n");
err = -ENODEV;
goto err_out_disable;
}
err = pci_request_regions(pdev, DRV_NAME);
if (err < 0) {
pr_err("Failed to request PCI regions\n");
goto err_out_disable;
}
db = netdev_priv(dev);
err = -ENOMEM;
db->desc_pool_ptr = pci_alloc_consistent(pdev, sizeof(struct tx_desc) * DESC_ALL_CNT + 0x20, &db->desc_pool_dma_ptr);
if (!db->desc_pool_ptr)
goto err_out_release;
db->buf_pool_ptr = pci_alloc_consistent(pdev, TX_BUF_ALLOC * TX_DESC_CNT + 4, &db->buf_pool_dma_ptr);
if (!db->buf_pool_ptr)
goto err_out_free_tx_desc;
db->first_tx_desc = (struct tx_desc *) db->desc_pool_ptr;
db->first_tx_desc_dma = db->desc_pool_dma_ptr;
db->buf_pool_start = db->buf_pool_ptr;
db->buf_pool_dma_start = db->buf_pool_dma_ptr;
switch (ent->driver_data) {
case PCI_ULI5263_ID:
db->phy.write = phy_writeby_cr10;
db->phy.read = phy_readby_cr10;
break;
default:
db->phy.write = phy_writeby_cr9;
db->phy.read = phy_readby_cr9;
break;
}
ioaddr = pci_iomap(pdev, 0, 0);
if (!ioaddr)
goto err_out_free_tx_buf;
db->ioaddr = ioaddr;
db->pdev = pdev;
db->init = 1;
pci_set_drvdata(pdev, dev);
dev->netdev_ops = &netdev_ops;
dev->ethtool_ops = &netdev_ethtool_ops;
spin_lock_init(&db->lock);
for (i = 0; i < 64; i++)
((__le16 *) db->srom)[i] = cpu_to_le16(read_srom_word(db, i));
if(((u16 *) db->srom)[0] == 0xffff || ((u16 *) db->srom)[0] == 0)
{
uw32(DCR0, 0x10000);
uw32(DCR13, 0x1c0);
uw32(DCR14, 0);
uw32(DCR14, 0x10);
uw32(DCR14, 0);
uw32(DCR13, 0);
uw32(DCR13, 0x1b0);
for (i = 0; i < 6; i++)
dev->dev_addr[i] = ur32(DCR14);
uw32(DCR13, 0);
uw32(DCR0, 0);
udelay(10);
}
else
{
for (i = 0; i < 6; i++)
dev->dev_addr[i] = db->srom[20 + i];
}
err = register_netdev (dev);
if (err)
goto err_out_unmap;
netdev_info(dev, "ULi M%04lx at pci%s, %pM, irq %d\n",
ent->driver_data >> 16, pci_name(pdev),
dev->dev_addr, pdev->irq);
pci_set_master(pdev);
return 0;
err_out_unmap:
pci_iounmap(pdev, db->ioaddr);
err_out_free_tx_buf:
pci_free_consistent(pdev, TX_BUF_ALLOC * TX_DESC_CNT + 4,
db->buf_pool_ptr, db->buf_pool_dma_ptr);
err_out_free_tx_desc:
pci_free_consistent(pdev, sizeof(struct tx_desc) * DESC_ALL_CNT + 0x20,
db->desc_pool_ptr, db->desc_pool_dma_ptr);
err_out_release:
pci_release_regions(pdev);
err_out_disable:
pci_disable_device(pdev);
err_out_free:
pci_set_drvdata(pdev, NULL);
free_netdev(dev);
return err;
}
static void uli526x_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct uli526x_board_info *db = netdev_priv(dev);
unregister_netdev(dev);
pci_iounmap(pdev, db->ioaddr);
pci_free_consistent(db->pdev, sizeof(struct tx_desc) *
DESC_ALL_CNT + 0x20, db->desc_pool_ptr,
db->desc_pool_dma_ptr);
pci_free_consistent(db->pdev, TX_BUF_ALLOC * TX_DESC_CNT + 4,
db->buf_pool_ptr, db->buf_pool_dma_ptr);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
free_netdev(dev);
}
static int uli526x_open(struct net_device *dev)
{
int ret;
struct uli526x_board_info *db = netdev_priv(dev);
ULI526X_DBUG(0, "uli526x_open", 0);
db->cr6_data = CR6_DEFAULT | uli526x_cr6_user_set;
db->tx_packet_cnt = 0;
db->rx_avail_cnt = 0;
db->link_failed = 1;
netif_carrier_off(dev);
db->wait_reset = 0;
db->NIC_capability = 0xf;
db->PHY_reg4 = 0x1e0;
db->cr6_data |= ULI526X_TXTH_256;
db->cr0_data = CR0_DEFAULT;
uli526x_init(dev);
ret = request_irq(db->pdev->irq, uli526x_interrupt, IRQF_SHARED,
dev->name, dev);
if (ret)
return ret;
netif_wake_queue(dev);
init_timer(&db->timer);
db->timer.expires = ULI526X_TIMER_WUT + HZ * 2;
db->timer.data = (unsigned long)dev;
db->timer.function = uli526x_timer;
add_timer(&db->timer);
return 0;
}
static void uli526x_init(struct net_device *dev)
{
struct uli526x_board_info *db = netdev_priv(dev);
struct uli_phy_ops *phy = &db->phy;
void __iomem *ioaddr = db->ioaddr;
u8 phy_tmp;
u8 timeout;
u16 phy_reg_reset;
ULI526X_DBUG(0, "uli526x_init()", 0);
uw32(DCR0, ULI526X_RESET);
udelay(100);
uw32(DCR0, db->cr0_data);
udelay(5);
db->phy_addr = 1;
for (phy_tmp = 0; phy_tmp < 32; phy_tmp++) {
u16 phy_value;
phy_value = phy->read(db, phy_tmp, 3);
if (phy_value != 0xffff && phy_value != 0) {
db->phy_addr = phy_tmp;
break;
}
}
if (phy_tmp == 32)
pr_warn("Can not find the phy address!!!\n");
db->media_mode = uli526x_media_mode;
phy_reg_reset = phy->read(db, db->phy_addr, 0);
phy_reg_reset = (phy_reg_reset | 0x8000);
phy->write(db, db->phy_addr, 0, phy_reg_reset);
udelay(500);
timeout = 10;
while (timeout-- && phy->read(db, db->phy_addr, 0) & 0x8000)
udelay(100);
uli526x_set_phyxcer(db);
if ( !(db->media_mode & ULI526X_AUTO) )
db->op_mode = db->media_mode;
uli526x_descriptor_init(dev, ioaddr);
update_cr6(db->cr6_data, ioaddr);
send_filter_frame(dev, netdev_mc_count(dev));
db->cr7_data = CR7_DEFAULT;
uw32(DCR7, db->cr7_data);
uw32(DCR15, db->cr15_data);
db->cr6_data |= CR6_RXSC | CR6_TXSC;
update_cr6(db->cr6_data, ioaddr);
}
static netdev_tx_t uli526x_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct uli526x_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
struct tx_desc *txptr;
unsigned long flags;
ULI526X_DBUG(0, "uli526x_start_xmit", 0);
netif_stop_queue(dev);
if (skb->len > MAX_PACKET_SIZE) {
netdev_err(dev, "big packet = %d\n", (u16)skb->len);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
spin_lock_irqsave(&db->lock, flags);
if (db->tx_packet_cnt >= TX_FREE_DESC_CNT) {
spin_unlock_irqrestore(&db->lock, flags);
netdev_err(dev, "No Tx resource %ld\n", db->tx_packet_cnt);
return NETDEV_TX_BUSY;
}
uw32(DCR7, 0);
txptr = db->tx_insert_ptr;
skb_copy_from_linear_data(skb, txptr->tx_buf_ptr, skb->len);
txptr->tdes1 = cpu_to_le32(0xe1000000 | skb->len);
db->tx_insert_ptr = txptr->next_tx_desc;
if (db->tx_packet_cnt < TX_DESC_CNT) {
txptr->tdes0 = cpu_to_le32(0x80000000);
db->tx_packet_cnt++;
uw32(DCR1, 0x1);
dev->trans_start = jiffies;
}
if ( db->tx_packet_cnt < TX_FREE_DESC_CNT )
netif_wake_queue(dev);
spin_unlock_irqrestore(&db->lock, flags);
uw32(DCR7, db->cr7_data);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int uli526x_stop(struct net_device *dev)
{
struct uli526x_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
netif_stop_queue(dev);
del_timer_sync(&db->timer);
uw32(DCR0, ULI526X_RESET);
udelay(5);
db->phy.write(db, db->phy_addr, 0, 0x8000);
free_irq(db->pdev->irq, dev);
uli526x_free_rxbuffer(db);
return 0;
}
static irqreturn_t uli526x_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct uli526x_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
unsigned long flags;
spin_lock_irqsave(&db->lock, flags);
uw32(DCR7, 0);
db->cr5_data = ur32(DCR5);
uw32(DCR5, db->cr5_data);
if ( !(db->cr5_data & 0x180c1) ) {
uw32(DCR7, db->cr7_data);
spin_unlock_irqrestore(&db->lock, flags);
return IRQ_HANDLED;
}
if (db->cr5_data & 0x2000) {
ULI526X_DBUG(1, "System bus error happen. CR5=", db->cr5_data);
db->reset_fatal++;
db->wait_reset = 1;
spin_unlock_irqrestore(&db->lock, flags);
return IRQ_HANDLED;
}
if ( (db->cr5_data & 0x40) && db->rx_avail_cnt )
uli526x_rx_packet(dev, db);
if (db->rx_avail_cnt<RX_DESC_CNT)
allocate_rx_buffer(dev);
if ( db->cr5_data & 0x01)
uli526x_free_tx_pkt(dev, db);
uw32(DCR7, db->cr7_data);
spin_unlock_irqrestore(&db->lock, flags);
return IRQ_HANDLED;
}
static void uli526x_poll(struct net_device *dev)
{
struct uli526x_board_info *db = netdev_priv(dev);
uli526x_interrupt(db->pdev->irq, dev);
}
static void uli526x_free_tx_pkt(struct net_device *dev,
struct uli526x_board_info * db)
{
struct tx_desc *txptr;
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
update_cr6(db->cr6_data, db->ioaddr);
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
if ( db->tx_packet_cnt < TX_WAKE_DESC_CNT )
netif_wake_queue(dev);
}
static void uli526x_rx_packet(struct net_device *dev, struct uli526x_board_info * db)
{
struct rx_desc *rxptr;
struct sk_buff *skb;
int rxlen;
u32 rdes0;
rxptr = db->rx_ready_ptr;
while(db->rx_avail_cnt) {
rdes0 = le32_to_cpu(rxptr->rdes0);
if (rdes0 & 0x80000000)
{
break;
}
db->rx_avail_cnt--;
db->interval_rx_cnt++;
pci_unmap_single(db->pdev, le32_to_cpu(rxptr->rdes2), RX_ALLOC_SIZE, PCI_DMA_FROMDEVICE);
if ( (rdes0 & 0x300) != 0x300) {
ULI526X_DBUG(0, "Reuse SK buffer, rdes0", rdes0);
uli526x_reuse_skb(db, rxptr->rx_skb_ptr);
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
struct sk_buff *new_skb = NULL;
skb = rxptr->rx_skb_ptr;
if ((rxlen < RX_COPY_SIZE) &&
(((new_skb = netdev_alloc_skb(dev, rxlen + 2)) != NULL))) {
skb = new_skb;
skb_reserve(skb, 2);
memcpy(skb_put(skb, rxlen),
skb_tail_pointer(rxptr->rx_skb_ptr),
rxlen);
uli526x_reuse_skb(db, rxptr->rx_skb_ptr);
} else
skb_put(skb, rxlen);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += rxlen;
} else {
ULI526X_DBUG(0, "Reuse SK buffer, rdes0", rdes0);
uli526x_reuse_skb(db, rxptr->rx_skb_ptr);
}
}
rxptr = rxptr->next_rx_desc;
}
db->rx_ready_ptr = rxptr;
}
static void uli526x_set_filter_mode(struct net_device * dev)
{
struct uli526x_board_info *db = netdev_priv(dev);
unsigned long flags;
ULI526X_DBUG(0, "uli526x_set_filter_mode()", 0);
spin_lock_irqsave(&db->lock, flags);
if (dev->flags & IFF_PROMISC) {
ULI526X_DBUG(0, "Enable PROM Mode", 0);
db->cr6_data |= CR6_PM | CR6_PBF;
update_cr6(db->cr6_data, db->ioaddr);
spin_unlock_irqrestore(&db->lock, flags);
return;
}
if (dev->flags & IFF_ALLMULTI ||
netdev_mc_count(dev) > ULI5261_MAX_MULTICAST) {
ULI526X_DBUG(0, "Pass all multicast address",
netdev_mc_count(dev));
db->cr6_data &= ~(CR6_PM | CR6_PBF);
db->cr6_data |= CR6_PAM;
spin_unlock_irqrestore(&db->lock, flags);
return;
}
ULI526X_DBUG(0, "Set multicast address", netdev_mc_count(dev));
send_filter_frame(dev, netdev_mc_count(dev));
spin_unlock_irqrestore(&db->lock, flags);
}
static void
ULi_ethtool_gset(struct uli526x_board_info *db, struct ethtool_cmd *ecmd)
{
ecmd->supported = (SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full |
SUPPORTED_Autoneg |
SUPPORTED_MII);
ecmd->advertising = (ADVERTISED_10baseT_Half |
ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half |
ADVERTISED_100baseT_Full |
ADVERTISED_Autoneg |
ADVERTISED_MII);
ecmd->port = PORT_MII;
ecmd->phy_address = db->phy_addr;
ecmd->transceiver = XCVR_EXTERNAL;
ethtool_cmd_speed_set(ecmd, SPEED_10);
ecmd->duplex = DUPLEX_HALF;
if(db->op_mode==ULI526X_100MHF || db->op_mode==ULI526X_100MFD)
{
ethtool_cmd_speed_set(ecmd, SPEED_100);
}
if(db->op_mode==ULI526X_10MFD || db->op_mode==ULI526X_100MFD)
{
ecmd->duplex = DUPLEX_FULL;
}
if(db->link_failed)
{
ethtool_cmd_speed_set(ecmd, -1);
ecmd->duplex = -1;
}
if (db->media_mode & ULI526X_AUTO)
{
ecmd->autoneg = AUTONEG_ENABLE;
}
}
static void netdev_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct uli526x_board_info *np = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(np->pdev), sizeof(info->bus_info));
}
static int netdev_get_settings(struct net_device *dev, struct ethtool_cmd *cmd) {
struct uli526x_board_info *np = netdev_priv(dev);
ULi_ethtool_gset(np, cmd);
return 0;
}
static u32 netdev_get_link(struct net_device *dev) {
struct uli526x_board_info *np = netdev_priv(dev);
if(np->link_failed)
return 0;
else
return 1;
}
static void uli526x_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
wol->supported = WAKE_PHY | WAKE_MAGIC;
wol->wolopts = 0;
}
static void uli526x_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *) data;
struct uli526x_board_info *db = netdev_priv(dev);
struct uli_phy_ops *phy = &db->phy;
void __iomem *ioaddr = db->ioaddr;
unsigned long flags;
u8 tmp_cr12 = 0;
u32 tmp_cr8;
spin_lock_irqsave(&db->lock, flags);
tmp_cr8 = ur32(DCR8);
if ( (db->interval_rx_cnt==0) && (tmp_cr8) ) {
db->reset_cr8++;
db->wait_reset = 1;
}
db->interval_rx_cnt = 0;
if ( db->tx_packet_cnt &&
time_after(jiffies, dev_trans_start(dev) + ULI526X_TX_KICK) ) {
uw32(DCR1, 0x1);
if ( time_after(jiffies, dev_trans_start(dev) + ULI526X_TX_TIMEOUT) ) {
db->reset_TXtimeout++;
db->wait_reset = 1;
netdev_err(dev, " Tx timeout - resetting\n");
}
}
if (db->wait_reset) {
ULI526X_DBUG(0, "Dynamic Reset device", db->tx_packet_cnt);
db->reset_count++;
uli526x_dynamic_reset(dev);
db->timer.expires = ULI526X_TIMER_WUT;
add_timer(&db->timer);
spin_unlock_irqrestore(&db->lock, flags);
return;
}
if ((phy->read(db, db->phy_addr, 5) & 0x01e0)!=0)
tmp_cr12 = 3;
if ( !(tmp_cr12 & 0x3) && !db->link_failed ) {
ULI526X_DBUG(0, "Link Failed", tmp_cr12);
netif_carrier_off(dev);
netdev_info(dev, "NIC Link is Down\n");
db->link_failed = 1;
if ( !(db->media_mode & 0x8) )
phy->write(db, db->phy_addr, 0, 0x1000);
if (db->media_mode & ULI526X_AUTO) {
db->cr6_data&=~0x00000200;
update_cr6(db->cr6_data, db->ioaddr);
}
} else
if ((tmp_cr12 & 0x3) && db->link_failed) {
ULI526X_DBUG(0, "Link link OK", tmp_cr12);
db->link_failed = 0;
if ( (db->media_mode & ULI526X_AUTO) &&
uli526x_sense_speed(db) )
db->link_failed = 1;
uli526x_process_mode(db);
if(db->link_failed==0)
{
netdev_info(dev, "NIC Link is Up %d Mbps %s duplex\n",
(db->op_mode == ULI526X_100MHF ||
db->op_mode == ULI526X_100MFD)
? 100 : 10,
(db->op_mode == ULI526X_10MFD ||
db->op_mode == ULI526X_100MFD)
? "Full" : "Half");
netif_carrier_on(dev);
}
}
else if(!(tmp_cr12 & 0x3) && db->link_failed)
{
if(db->init==1)
{
netdev_info(dev, "NIC Link is Down\n");
netif_carrier_off(dev);
}
}
db->init=0;
db->timer.expires = ULI526X_TIMER_WUT;
add_timer(&db->timer);
spin_unlock_irqrestore(&db->lock, flags);
}
static void uli526x_reset_prepare(struct net_device *dev)
{
struct uli526x_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
db->cr6_data &= ~(CR6_RXSC | CR6_TXSC);
update_cr6(db->cr6_data, ioaddr);
uw32(DCR7, 0);
uw32(DCR5, ur32(DCR5));
netif_stop_queue(dev);
uli526x_free_rxbuffer(db);
db->tx_packet_cnt = 0;
db->rx_avail_cnt = 0;
db->link_failed = 1;
db->init=1;
db->wait_reset = 0;
}
static void uli526x_dynamic_reset(struct net_device *dev)
{
ULI526X_DBUG(0, "uli526x_dynamic_reset()", 0);
uli526x_reset_prepare(dev);
uli526x_init(dev);
netif_wake_queue(dev);
}
static int uli526x_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
pci_power_t power_state;
int err;
ULI526X_DBUG(0, "uli526x_suspend", 0);
if (!netdev_priv(dev))
return 0;
pci_save_state(pdev);
if (!netif_running(dev))
return 0;
netif_device_detach(dev);
uli526x_reset_prepare(dev);
power_state = pci_choose_state(pdev, state);
pci_enable_wake(pdev, power_state, 0);
err = pci_set_power_state(pdev, power_state);
if (err) {
netif_device_attach(dev);
uli526x_init(dev);
netif_wake_queue(dev);
}
return err;
}
static int uli526x_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
int err;
ULI526X_DBUG(0, "uli526x_resume", 0);
if (!netdev_priv(dev))
return 0;
pci_restore_state(pdev);
if (!netif_running(dev))
return 0;
err = pci_set_power_state(pdev, PCI_D0);
if (err) {
netdev_warn(dev, "Could not put device into D0\n");
return err;
}
netif_device_attach(dev);
uli526x_init(dev);
netif_wake_queue(dev);
return 0;
}
static void uli526x_free_rxbuffer(struct uli526x_board_info * db)
{
ULI526X_DBUG(0, "uli526x_free_rxbuffer()", 0);
while (db->rx_avail_cnt) {
dev_kfree_skb(db->rx_ready_ptr->rx_skb_ptr);
db->rx_ready_ptr = db->rx_ready_ptr->next_rx_desc;
db->rx_avail_cnt--;
}
}
static void uli526x_reuse_skb(struct uli526x_board_info *db, struct sk_buff * skb)
{
struct rx_desc *rxptr = db->rx_insert_ptr;
if (!(rxptr->rdes0 & cpu_to_le32(0x80000000))) {
rxptr->rx_skb_ptr = skb;
rxptr->rdes2 = cpu_to_le32(pci_map_single(db->pdev,
skb_tail_pointer(skb),
RX_ALLOC_SIZE,
PCI_DMA_FROMDEVICE));
wmb();
rxptr->rdes0 = cpu_to_le32(0x80000000);
db->rx_avail_cnt++;
db->rx_insert_ptr = rxptr->next_rx_desc;
} else
ULI526X_DBUG(0, "SK Buffer reuse method error", db->rx_avail_cnt);
}
static void uli526x_descriptor_init(struct net_device *dev, void __iomem *ioaddr)
{
struct uli526x_board_info *db = netdev_priv(dev);
struct tx_desc *tmp_tx;
struct rx_desc *tmp_rx;
unsigned char *tmp_buf;
dma_addr_t tmp_tx_dma, tmp_rx_dma;
dma_addr_t tmp_buf_dma;
int i;
ULI526X_DBUG(0, "uli526x_descriptor_init()", 0);
db->tx_insert_ptr = db->first_tx_desc;
db->tx_remove_ptr = db->first_tx_desc;
uw32(DCR4, db->first_tx_desc_dma);
db->first_rx_desc = (void *)db->first_tx_desc + sizeof(struct tx_desc) * TX_DESC_CNT;
db->first_rx_desc_dma = db->first_tx_desc_dma + sizeof(struct tx_desc) * TX_DESC_CNT;
db->rx_insert_ptr = db->first_rx_desc;
db->rx_ready_ptr = db->first_rx_desc;
uw32(DCR3, db->first_rx_desc_dma);
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
uw32(DCR6, cr6_data);
udelay(5);
}
static void send_filter_frame(struct net_device *dev, int mc_cnt)
{
struct uli526x_board_info *db = netdev_priv(dev);
void __iomem *ioaddr = db->ioaddr;
struct netdev_hw_addr *ha;
struct tx_desc *txptr;
u16 * addrptr;
u32 * suptr;
int i;
ULI526X_DBUG(0, "send_filter_frame()", 0);
txptr = db->tx_insert_ptr;
suptr = (u32 *) txptr->tx_buf_ptr;
addrptr = (u16 *) dev->dev_addr;
*suptr++ = addrptr[0] << FLT_SHIFT;
*suptr++ = addrptr[1] << FLT_SHIFT;
*suptr++ = addrptr[2] << FLT_SHIFT;
*suptr++ = 0xffff << FLT_SHIFT;
*suptr++ = 0xffff << FLT_SHIFT;
*suptr++ = 0xffff << FLT_SHIFT;
netdev_for_each_mc_addr(ha, dev) {
addrptr = (u16 *) ha->addr;
*suptr++ = addrptr[0] << FLT_SHIFT;
*suptr++ = addrptr[1] << FLT_SHIFT;
*suptr++ = addrptr[2] << FLT_SHIFT;
}
for (i = netdev_mc_count(dev); i < 14; i++) {
*suptr++ = 0xffff << FLT_SHIFT;
*suptr++ = 0xffff << FLT_SHIFT;
*suptr++ = 0xffff << FLT_SHIFT;
}
db->tx_insert_ptr = txptr->next_tx_desc;
txptr->tdes1 = cpu_to_le32(0x890000c0);
if (db->tx_packet_cnt < TX_DESC_CNT) {
db->tx_packet_cnt++;
txptr->tdes0 = cpu_to_le32(0x80000000);
update_cr6(db->cr6_data | 0x2000, ioaddr);
uw32(DCR1, 0x1);
update_cr6(db->cr6_data, ioaddr);
dev->trans_start = jiffies;
} else
netdev_err(dev, "No Tx resource - Send_filter_frame!\n");
}
static void allocate_rx_buffer(struct net_device *dev)
{
struct uli526x_board_info *db = netdev_priv(dev);
struct rx_desc *rxptr;
struct sk_buff *skb;
rxptr = db->rx_insert_ptr;
while(db->rx_avail_cnt < RX_DESC_CNT) {
skb = netdev_alloc_skb(dev, RX_ALLOC_SIZE);
if (skb == NULL)
break;
rxptr->rx_skb_ptr = skb;
rxptr->rdes2 = cpu_to_le32(pci_map_single(db->pdev,
skb_tail_pointer(skb),
RX_ALLOC_SIZE,
PCI_DMA_FROMDEVICE));
wmb();
rxptr->rdes0 = cpu_to_le32(0x80000000);
rxptr = rxptr->next_rx_desc;
db->rx_avail_cnt++;
}
db->rx_insert_ptr = rxptr;
}
static u16 read_srom_word(struct uli526x_board_info *db, int offset)
{
void __iomem *ioaddr = db->ioaddr;
u16 srom_data = 0;
int i;
uw32(DCR9, CR9_SROM_READ);
uw32(DCR9, CR9_SROM_READ | CR9_SRCS);
srom_clk_write(db, SROM_DATA_1);
srom_clk_write(db, SROM_DATA_1);
srom_clk_write(db, SROM_DATA_0);
for (i = 5; i >= 0; i--) {
srom_data = (offset & (1 << i)) ? SROM_DATA_1 : SROM_DATA_0;
srom_clk_write(db, srom_data);
}
uw32(DCR9, CR9_SROM_READ | CR9_SRCS);
for (i = 16; i > 0; i--) {
uw32(DCR9, CR9_SROM_READ | CR9_SRCS | CR9_SRCLK);
udelay(5);
srom_data = (srom_data << 1) |
((ur32(DCR9) & CR9_CRDOUT) ? 1 : 0);
uw32(DCR9, CR9_SROM_READ | CR9_SRCS);
udelay(5);
}
uw32(DCR9, CR9_SROM_READ);
return srom_data;
}
static u8 uli526x_sense_speed(struct uli526x_board_info * db)
{
struct uli_phy_ops *phy = &db->phy;
u8 ErrFlag = 0;
u16 phy_mode;
phy_mode = phy->read(db, db->phy_addr, 1);
phy_mode = phy->read(db, db->phy_addr, 1);
if ( (phy_mode & 0x24) == 0x24 ) {
phy_mode = ((phy->read(db, db->phy_addr, 5) & 0x01e0)<<7);
if(phy_mode&0x8000)
phy_mode = 0x8000;
else if(phy_mode&0x4000)
phy_mode = 0x4000;
else if(phy_mode&0x2000)
phy_mode = 0x2000;
else
phy_mode = 0x1000;
switch (phy_mode) {
case 0x1000: db->op_mode = ULI526X_10MHF; break;
case 0x2000: db->op_mode = ULI526X_10MFD; break;
case 0x4000: db->op_mode = ULI526X_100MHF; break;
case 0x8000: db->op_mode = ULI526X_100MFD; break;
default: db->op_mode = ULI526X_10MHF; ErrFlag = 1; break;
}
} else {
db->op_mode = ULI526X_10MHF;
ULI526X_DBUG(0, "Link Failed :", phy_mode);
ErrFlag = 1;
}
return ErrFlag;
}
static void uli526x_set_phyxcer(struct uli526x_board_info *db)
{
struct uli_phy_ops *phy = &db->phy;
u16 phy_reg;
phy_reg = phy->read(db, db->phy_addr, 4) & ~0x01e0;
if (db->media_mode & ULI526X_AUTO) {
phy_reg |= db->PHY_reg4;
} else {
switch(db->media_mode) {
case ULI526X_10MHF: phy_reg |= 0x20; break;
case ULI526X_10MFD: phy_reg |= 0x40; break;
case ULI526X_100MHF: phy_reg |= 0x80; break;
case ULI526X_100MFD: phy_reg |= 0x100; break;
}
}
if ( !(phy_reg & 0x01e0)) {
phy_reg|=db->PHY_reg4;
db->media_mode|=ULI526X_AUTO;
}
phy->write(db, db->phy_addr, 4, phy_reg);
phy->write(db, db->phy_addr, 0, 0x1200);
udelay(50);
}
static void uli526x_process_mode(struct uli526x_board_info *db)
{
struct uli_phy_ops *phy = &db->phy;
u16 phy_reg;
if (db->op_mode & 0x4)
db->cr6_data |= CR6_FDM;
else
db->cr6_data &= ~CR6_FDM;
update_cr6(db->cr6_data, db->ioaddr);
if (!(db->media_mode & 0x8)) {
phy_reg = phy->read(db, db->phy_addr, 6);
if (!(phy_reg & 0x1)) {
phy_reg = 0x0;
switch(db->op_mode) {
case ULI526X_10MHF: phy_reg = 0x0; break;
case ULI526X_10MFD: phy_reg = 0x100; break;
case ULI526X_100MHF: phy_reg = 0x2000; break;
case ULI526X_100MFD: phy_reg = 0x2100; break;
}
phy->write(db, db->phy_addr, 0, phy_reg);
}
}
}
static void phy_writeby_cr9(struct uli526x_board_info *db, u8 phy_addr,
u8 offset, u16 phy_data)
{
u16 i;
for (i = 0; i < 35; i++)
phy_write_1bit(db, PHY_DATA_1);
phy_write_1bit(db, PHY_DATA_0);
phy_write_1bit(db, PHY_DATA_1);
phy_write_1bit(db, PHY_DATA_0);
phy_write_1bit(db, PHY_DATA_1);
for (i = 0x10; i > 0; i = i >> 1)
phy_write_1bit(db, phy_addr & i ? PHY_DATA_1 : PHY_DATA_0);
for (i = 0x10; i > 0; i = i >> 1)
phy_write_1bit(db, offset & i ? PHY_DATA_1 : PHY_DATA_0);
phy_write_1bit(db, PHY_DATA_1);
phy_write_1bit(db, PHY_DATA_0);
for (i = 0x8000; i > 0; i >>= 1)
phy_write_1bit(db, phy_data & i ? PHY_DATA_1 : PHY_DATA_0);
}
static u16 phy_readby_cr9(struct uli526x_board_info *db, u8 phy_addr, u8 offset)
{
u16 phy_data;
int i;
for (i = 0; i < 35; i++)
phy_write_1bit(db, PHY_DATA_1);
phy_write_1bit(db, PHY_DATA_0);
phy_write_1bit(db, PHY_DATA_1);
phy_write_1bit(db, PHY_DATA_1);
phy_write_1bit(db, PHY_DATA_0);
for (i = 0x10; i > 0; i = i >> 1)
phy_write_1bit(db, phy_addr & i ? PHY_DATA_1 : PHY_DATA_0);
for (i = 0x10; i > 0; i = i >> 1)
phy_write_1bit(db, offset & i ? PHY_DATA_1 : PHY_DATA_0);
phy_read_1bit(db);
for (phy_data = 0, i = 0; i < 16; i++) {
phy_data <<= 1;
phy_data |= phy_read_1bit(db);
}
return phy_data;
}
static u16 phy_readby_cr10(struct uli526x_board_info *db, u8 phy_addr,
u8 offset)
{
void __iomem *ioaddr = db->ioaddr;
u32 cr10_value = phy_addr;
cr10_value = (cr10_value << 5) + offset;
cr10_value = (cr10_value << 16) + 0x08000000;
uw32(DCR10, cr10_value);
udelay(1);
while (1) {
cr10_value = ur32(DCR10);
if (cr10_value & 0x10000000)
break;
}
return cr10_value & 0x0ffff;
}
static void phy_writeby_cr10(struct uli526x_board_info *db, u8 phy_addr,
u8 offset, u16 phy_data)
{
void __iomem *ioaddr = db->ioaddr;
u32 cr10_value = phy_addr;
cr10_value = (cr10_value << 5) + offset;
cr10_value = (cr10_value << 16) + 0x04000000 + phy_data;
uw32(DCR10, cr10_value);
udelay(1);
}
static void phy_write_1bit(struct uli526x_board_info *db, u32 data)
{
void __iomem *ioaddr = db->ioaddr;
uw32(DCR9, data);
udelay(1);
uw32(DCR9, data | MDCLKH);
udelay(1);
uw32(DCR9, data);
udelay(1);
}
static u16 phy_read_1bit(struct uli526x_board_info *db)
{
void __iomem *ioaddr = db->ioaddr;
u16 phy_data;
uw32(DCR9, 0x50000);
udelay(1);
phy_data = (ur32(DCR9) >> 19) & 0x1;
uw32(DCR9, 0x40000);
udelay(1);
return phy_data;
}
static int __init uli526x_init_module(void)
{
pr_info("%s\n", version);
printed_version = 1;
ULI526X_DBUG(0, "init_module() ", debug);
if (debug)
uli526x_debug = debug;
if (cr6set)
uli526x_cr6_user_set = cr6set;
switch (mode) {
case ULI526X_10MHF:
case ULI526X_100MHF:
case ULI526X_10MFD:
case ULI526X_100MFD:
uli526x_media_mode = mode;
break;
default:
uli526x_media_mode = ULI526X_AUTO;
break;
}
return pci_register_driver(&uli526x_driver);
}
static void __exit uli526x_cleanup_module(void)
{
ULI526X_DBUG(0, "uli526x_clean_module() ", debug);
pci_unregister_driver(&uli526x_driver);
}
