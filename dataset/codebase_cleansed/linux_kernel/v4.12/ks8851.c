static void ks8851_wrreg16(struct ks8851_net *ks, unsigned reg, unsigned val)
{
struct spi_transfer *xfer = &ks->spi_xfer1;
struct spi_message *msg = &ks->spi_msg1;
__le16 txb[2];
int ret;
txb[0] = cpu_to_le16(MK_OP(reg & 2 ? 0xC : 0x03, reg) | KS_SPIOP_WR);
txb[1] = cpu_to_le16(val);
xfer->tx_buf = txb;
xfer->rx_buf = NULL;
xfer->len = 4;
ret = spi_sync(ks->spidev, msg);
if (ret < 0)
netdev_err(ks->netdev, "spi_sync() failed\n");
}
static void ks8851_wrreg8(struct ks8851_net *ks, unsigned reg, unsigned val)
{
struct spi_transfer *xfer = &ks->spi_xfer1;
struct spi_message *msg = &ks->spi_msg1;
__le16 txb[2];
int ret;
int bit;
bit = 1 << (reg & 3);
txb[0] = cpu_to_le16(MK_OP(bit, reg) | KS_SPIOP_WR);
txb[1] = val;
xfer->tx_buf = txb;
xfer->rx_buf = NULL;
xfer->len = 3;
ret = spi_sync(ks->spidev, msg);
if (ret < 0)
netdev_err(ks->netdev, "spi_sync() failed\n");
}
static void ks8851_rdreg(struct ks8851_net *ks, unsigned op,
u8 *rxb, unsigned rxl)
{
struct spi_transfer *xfer;
struct spi_message *msg;
__le16 *txb = (__le16 *)ks->txd;
u8 *trx = ks->rxd;
int ret;
txb[0] = cpu_to_le16(op | KS_SPIOP_RD);
if (ks->spidev->master->flags & SPI_MASTER_HALF_DUPLEX) {
msg = &ks->spi_msg2;
xfer = ks->spi_xfer2;
xfer->tx_buf = txb;
xfer->rx_buf = NULL;
xfer->len = 2;
xfer++;
xfer->tx_buf = NULL;
xfer->rx_buf = trx;
xfer->len = rxl;
} else {
msg = &ks->spi_msg1;
xfer = &ks->spi_xfer1;
xfer->tx_buf = txb;
xfer->rx_buf = trx;
xfer->len = rxl + 2;
}
ret = spi_sync(ks->spidev, msg);
if (ret < 0)
netdev_err(ks->netdev, "read: spi_sync() failed\n");
else if (ks->spidev->master->flags & SPI_MASTER_HALF_DUPLEX)
memcpy(rxb, trx, rxl);
else
memcpy(rxb, trx + 2, rxl);
}
static unsigned ks8851_rdreg8(struct ks8851_net *ks, unsigned reg)
{
u8 rxb[1];
ks8851_rdreg(ks, MK_OP(1 << (reg & 3), reg), rxb, 1);
return rxb[0];
}
static unsigned ks8851_rdreg16(struct ks8851_net *ks, unsigned reg)
{
__le16 rx = 0;
ks8851_rdreg(ks, MK_OP(reg & 2 ? 0xC : 0x3, reg), (u8 *)&rx, 2);
return le16_to_cpu(rx);
}
static unsigned ks8851_rdreg32(struct ks8851_net *ks, unsigned reg)
{
__le32 rx = 0;
WARN_ON(reg & 3);
ks8851_rdreg(ks, MK_OP(0xf, reg), (u8 *)&rx, 4);
return le32_to_cpu(rx);
}
static void ks8851_soft_reset(struct ks8851_net *ks, unsigned op)
{
ks8851_wrreg16(ks, KS_GRR, op);
mdelay(1);
ks8851_wrreg16(ks, KS_GRR, 0);
mdelay(1);
}
static void ks8851_set_powermode(struct ks8851_net *ks, unsigned pwrmode)
{
unsigned pmecr;
netif_dbg(ks, hw, ks->netdev, "setting power mode %d\n", pwrmode);
pmecr = ks8851_rdreg16(ks, KS_PMECR);
pmecr &= ~PMECR_PM_MASK;
pmecr |= pwrmode;
ks8851_wrreg16(ks, KS_PMECR, pmecr);
}
static int ks8851_write_mac_addr(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
int i;
mutex_lock(&ks->lock);
ks8851_set_powermode(ks, PMECR_PM_NORMAL);
for (i = 0; i < ETH_ALEN; i++)
ks8851_wrreg8(ks, KS_MAR(i), dev->dev_addr[i]);
if (!netif_running(dev))
ks8851_set_powermode(ks, PMECR_PM_SOFTDOWN);
mutex_unlock(&ks->lock);
return 0;
}
static void ks8851_read_mac_addr(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
int i;
mutex_lock(&ks->lock);
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = ks8851_rdreg8(ks, KS_MAR(i));
mutex_unlock(&ks->lock);
}
static void ks8851_init_mac(struct ks8851_net *ks)
{
struct net_device *dev = ks->netdev;
if (ks->rc_ccr & CCR_EEPROM) {
ks8851_read_mac_addr(dev);
if (is_valid_ether_addr(dev->dev_addr))
return;
netdev_err(ks->netdev, "invalid mac address read %pM\n",
dev->dev_addr);
}
eth_hw_addr_random(dev);
ks8851_write_mac_addr(dev);
}
static void ks8851_rdfifo(struct ks8851_net *ks, u8 *buff, unsigned len)
{
struct spi_transfer *xfer = ks->spi_xfer2;
struct spi_message *msg = &ks->spi_msg2;
u8 txb[1];
int ret;
netif_dbg(ks, rx_status, ks->netdev,
"%s: %d@%p\n", __func__, len, buff);
txb[0] = KS_SPIOP_RXFIFO;
xfer->tx_buf = txb;
xfer->rx_buf = NULL;
xfer->len = 1;
xfer++;
xfer->rx_buf = buff;
xfer->tx_buf = NULL;
xfer->len = len;
ret = spi_sync(ks->spidev, msg);
if (ret < 0)
netdev_err(ks->netdev, "%s: spi_sync() failed\n", __func__);
}
static void ks8851_dbg_dumpkkt(struct ks8851_net *ks, u8 *rxpkt)
{
netdev_dbg(ks->netdev,
"pkt %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x\n",
rxpkt[4], rxpkt[5], rxpkt[6], rxpkt[7],
rxpkt[8], rxpkt[9], rxpkt[10], rxpkt[11],
rxpkt[12], rxpkt[13], rxpkt[14], rxpkt[15]);
}
static void ks8851_rx_pkts(struct ks8851_net *ks)
{
struct sk_buff *skb;
unsigned rxfc;
unsigned rxlen;
unsigned rxstat;
u32 rxh;
u8 *rxpkt;
rxfc = ks8851_rdreg8(ks, KS_RXFC);
netif_dbg(ks, rx_status, ks->netdev,
"%s: %d packets\n", __func__, rxfc);
for (; rxfc != 0; rxfc--) {
rxh = ks8851_rdreg32(ks, KS_RXFHSR);
rxstat = rxh & 0xffff;
rxlen = (rxh >> 16) & 0xfff;
netif_dbg(ks, rx_status, ks->netdev,
"rx: stat 0x%04x, len 0x%04x\n", rxstat, rxlen);
ks8851_wrreg16(ks, KS_RXFDPR, RXFDPR_RXFPAI | 0x00);
ks8851_wrreg16(ks, KS_RXQCR,
ks->rc_rxqcr | RXQCR_SDA | RXQCR_ADRFE);
if (rxlen > 4) {
unsigned int rxalign;
rxlen -= 4;
rxalign = ALIGN(rxlen, 4);
skb = netdev_alloc_skb_ip_align(ks->netdev, rxalign);
if (skb) {
rxpkt = skb_put(skb, rxlen) - 8;
ks8851_rdfifo(ks, rxpkt, rxalign + 8);
if (netif_msg_pktdata(ks))
ks8851_dbg_dumpkkt(ks, rxpkt);
skb->protocol = eth_type_trans(skb, ks->netdev);
netif_rx_ni(skb);
ks->netdev->stats.rx_packets++;
ks->netdev->stats.rx_bytes += rxlen;
}
}
ks8851_wrreg16(ks, KS_RXQCR, ks->rc_rxqcr);
}
}
static irqreturn_t ks8851_irq(int irq, void *_ks)
{
struct ks8851_net *ks = _ks;
unsigned status;
unsigned handled = 0;
mutex_lock(&ks->lock);
status = ks8851_rdreg16(ks, KS_ISR);
netif_dbg(ks, intr, ks->netdev,
"%s: status 0x%04x\n", __func__, status);
if (status & IRQ_LCI)
handled |= IRQ_LCI;
if (status & IRQ_LDI) {
u16 pmecr = ks8851_rdreg16(ks, KS_PMECR);
pmecr &= ~PMECR_WKEVT_MASK;
ks8851_wrreg16(ks, KS_PMECR, pmecr | PMECR_WKEVT_LINK);
handled |= IRQ_LDI;
}
if (status & IRQ_RXPSI)
handled |= IRQ_RXPSI;
if (status & IRQ_TXI) {
handled |= IRQ_TXI;
ks->tx_space = ks8851_rdreg16(ks, KS_TXMIR);
netif_dbg(ks, intr, ks->netdev,
"%s: txspace %d\n", __func__, ks->tx_space);
}
if (status & IRQ_RXI)
handled |= IRQ_RXI;
if (status & IRQ_SPIBEI) {
dev_err(&ks->spidev->dev, "%s: spi bus error\n", __func__);
handled |= IRQ_SPIBEI;
}
ks8851_wrreg16(ks, KS_ISR, handled);
if (status & IRQ_RXI) {
ks8851_rx_pkts(ks);
}
if (status & IRQ_RXPSI) {
struct ks8851_rxctrl *rxc = &ks->rxctrl;
ks8851_wrreg16(ks, KS_MAHTR0, rxc->mchash[0]);
ks8851_wrreg16(ks, KS_MAHTR1, rxc->mchash[1]);
ks8851_wrreg16(ks, KS_MAHTR2, rxc->mchash[2]);
ks8851_wrreg16(ks, KS_MAHTR3, rxc->mchash[3]);
ks8851_wrreg16(ks, KS_RXCR2, rxc->rxcr2);
ks8851_wrreg16(ks, KS_RXCR1, rxc->rxcr1);
}
mutex_unlock(&ks->lock);
if (status & IRQ_LCI)
mii_check_link(&ks->mii);
if (status & IRQ_TXI)
netif_wake_queue(ks->netdev);
return IRQ_HANDLED;
}
static inline unsigned calc_txlen(unsigned len)
{
return ALIGN(len + 4, 4);
}
static void ks8851_wrpkt(struct ks8851_net *ks, struct sk_buff *txp, bool irq)
{
struct spi_transfer *xfer = ks->spi_xfer2;
struct spi_message *msg = &ks->spi_msg2;
unsigned fid = 0;
int ret;
netif_dbg(ks, tx_queued, ks->netdev, "%s: skb %p, %d@%p, irq %d\n",
__func__, txp, txp->len, txp->data, irq);
fid = ks->fid++;
fid &= TXFR_TXFID_MASK;
if (irq)
fid |= TXFR_TXIC;
ks->txh.txb[1] = KS_SPIOP_TXFIFO;
ks->txh.txw[1] = cpu_to_le16(fid);
ks->txh.txw[2] = cpu_to_le16(txp->len);
xfer->tx_buf = &ks->txh.txb[1];
xfer->rx_buf = NULL;
xfer->len = 5;
xfer++;
xfer->tx_buf = txp->data;
xfer->rx_buf = NULL;
xfer->len = ALIGN(txp->len, 4);
ret = spi_sync(ks->spidev, msg);
if (ret < 0)
netdev_err(ks->netdev, "%s: spi_sync() failed\n", __func__);
}
static void ks8851_done_tx(struct ks8851_net *ks, struct sk_buff *txb)
{
struct net_device *dev = ks->netdev;
dev->stats.tx_bytes += txb->len;
dev->stats.tx_packets++;
dev_kfree_skb(txb);
}
static void ks8851_tx_work(struct work_struct *work)
{
struct ks8851_net *ks = container_of(work, struct ks8851_net, tx_work);
struct sk_buff *txb;
bool last = skb_queue_empty(&ks->txq);
mutex_lock(&ks->lock);
while (!last) {
txb = skb_dequeue(&ks->txq);
last = skb_queue_empty(&ks->txq);
if (txb != NULL) {
ks8851_wrreg16(ks, KS_RXQCR, ks->rc_rxqcr | RXQCR_SDA);
ks8851_wrpkt(ks, txb, last);
ks8851_wrreg16(ks, KS_RXQCR, ks->rc_rxqcr);
ks8851_wrreg16(ks, KS_TXQCR, TXQCR_METFE);
ks8851_done_tx(ks, txb);
}
}
mutex_unlock(&ks->lock);
}
static int ks8851_net_open(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
mutex_lock(&ks->lock);
netif_dbg(ks, ifup, ks->netdev, "opening\n");
ks8851_set_powermode(ks, PMECR_PM_NORMAL);
ks8851_soft_reset(ks, GRR_QMU);
ks8851_wrreg16(ks, KS_TXCR, (TXCR_TXE |
TXCR_TXPE |
TXCR_TXCRC |
TXCR_TXFCE));
ks8851_wrreg16(ks, KS_TXFDPR, TXFDPR_TXFPAI);
ks8851_wrreg16(ks, KS_RXCR1, (RXCR1_RXPAFMA |
RXCR1_RXFCE |
RXCR1_RXBE |
RXCR1_RXUE |
RXCR1_RXE));
ks8851_wrreg16(ks, KS_RXCR2, RXCR2_SRDBL_FRAME);
ks8851_wrreg16(ks, KS_RXDTTR, 1000);
ks8851_wrreg16(ks, KS_RXDBCTR, 4096);
ks8851_wrreg16(ks, KS_RXFCTR, 10);
ks->rc_rxqcr = (RXQCR_RXFCTE |
RXQCR_RXDBCTE |
RXQCR_RXDTTE);
ks8851_wrreg16(ks, KS_RXQCR, ks->rc_rxqcr);
#define STD_IRQ (IRQ_LCI | \
IRQ_TXI | \
IRQ_RXI | \
IRQ_SPIBEI | \
IRQ_TXPSI | \
IRQ_RXPSI)
ks->rc_ier = STD_IRQ;
ks8851_wrreg16(ks, KS_ISR, STD_IRQ);
ks8851_wrreg16(ks, KS_IER, STD_IRQ);
netif_start_queue(ks->netdev);
netif_dbg(ks, ifup, ks->netdev, "network device up\n");
mutex_unlock(&ks->lock);
return 0;
}
static int ks8851_net_stop(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
netif_info(ks, ifdown, dev, "shutting down\n");
netif_stop_queue(dev);
mutex_lock(&ks->lock);
ks8851_wrreg16(ks, KS_IER, 0x0000);
ks8851_wrreg16(ks, KS_ISR, 0xffff);
mutex_unlock(&ks->lock);
flush_work(&ks->tx_work);
flush_work(&ks->rxctrl_work);
mutex_lock(&ks->lock);
ks8851_wrreg16(ks, KS_RXCR1, 0x0000);
ks8851_wrreg16(ks, KS_TXCR, 0x0000);
ks8851_set_powermode(ks, PMECR_PM_SOFTDOWN);
mutex_unlock(&ks->lock);
while (!skb_queue_empty(&ks->txq)) {
struct sk_buff *txb = skb_dequeue(&ks->txq);
netif_dbg(ks, ifdown, ks->netdev,
"%s: freeing txb %p\n", __func__, txb);
dev_kfree_skb(txb);
}
return 0;
}
static netdev_tx_t ks8851_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
unsigned needed = calc_txlen(skb->len);
netdev_tx_t ret = NETDEV_TX_OK;
netif_dbg(ks, tx_queued, ks->netdev,
"%s: skb %p, %d@%p\n", __func__, skb, skb->len, skb->data);
spin_lock(&ks->statelock);
if (needed > ks->tx_space) {
netif_stop_queue(dev);
ret = NETDEV_TX_BUSY;
} else {
ks->tx_space -= needed;
skb_queue_tail(&ks->txq, skb);
}
spin_unlock(&ks->statelock);
schedule_work(&ks->tx_work);
return ret;
}
static void ks8851_rxctrl_work(struct work_struct *work)
{
struct ks8851_net *ks = container_of(work, struct ks8851_net, rxctrl_work);
mutex_lock(&ks->lock);
ks8851_wrreg16(ks, KS_RXCR1, 0x00);
mutex_unlock(&ks->lock);
}
static void ks8851_set_rx_mode(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
struct ks8851_rxctrl rxctrl;
memset(&rxctrl, 0, sizeof(rxctrl));
if (dev->flags & IFF_PROMISC) {
rxctrl.rxcr1 = RXCR1_RXAE | RXCR1_RXINVF;
} else if (dev->flags & IFF_ALLMULTI) {
rxctrl.rxcr1 = (RXCR1_RXME | RXCR1_RXAE |
RXCR1_RXPAFMA | RXCR1_RXMAFMA);
} else if (dev->flags & IFF_MULTICAST && !netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
u32 crc;
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc(ETH_ALEN, ha->addr);
crc >>= (32 - 6);
rxctrl.mchash[crc >> 4] |= (1 << (crc & 0xf));
}
rxctrl.rxcr1 = RXCR1_RXME | RXCR1_RXPAFMA;
} else {
rxctrl.rxcr1 = RXCR1_RXPAFMA;
}
rxctrl.rxcr1 |= (RXCR1_RXUE |
RXCR1_RXBE |
RXCR1_RXE |
RXCR1_RXFCE);
rxctrl.rxcr2 |= RXCR2_SRDBL_FRAME;
spin_lock(&ks->statelock);
if (memcmp(&rxctrl, &ks->rxctrl, sizeof(rxctrl)) != 0) {
memcpy(&ks->rxctrl, &rxctrl, sizeof(ks->rxctrl));
schedule_work(&ks->rxctrl_work);
}
spin_unlock(&ks->statelock);
}
static int ks8851_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = addr;
if (netif_running(dev))
return -EBUSY;
if (!is_valid_ether_addr(sa->sa_data))
return -EADDRNOTAVAIL;
memcpy(dev->dev_addr, sa->sa_data, ETH_ALEN);
return ks8851_write_mac_addr(dev);
}
static int ks8851_net_ioctl(struct net_device *dev, struct ifreq *req, int cmd)
{
struct ks8851_net *ks = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
return generic_mii_ioctl(&ks->mii, if_mii(req), cmd, NULL);
}
static void ks8851_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *di)
{
strlcpy(di->driver, "KS8851", sizeof(di->driver));
strlcpy(di->version, "1.00", sizeof(di->version));
strlcpy(di->bus_info, dev_name(dev->dev.parent), sizeof(di->bus_info));
}
static u32 ks8851_get_msglevel(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
return ks->msg_enable;
}
static void ks8851_set_msglevel(struct net_device *dev, u32 to)
{
struct ks8851_net *ks = netdev_priv(dev);
ks->msg_enable = to;
}
static int ks8851_get_link_ksettings(struct net_device *dev,
struct ethtool_link_ksettings *cmd)
{
struct ks8851_net *ks = netdev_priv(dev);
return mii_ethtool_get_link_ksettings(&ks->mii, cmd);
}
static int ks8851_set_link_ksettings(struct net_device *dev,
const struct ethtool_link_ksettings *cmd)
{
struct ks8851_net *ks = netdev_priv(dev);
return mii_ethtool_set_link_ksettings(&ks->mii, cmd);
}
static u32 ks8851_get_link(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
return mii_link_ok(&ks->mii);
}
static int ks8851_nway_reset(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
return mii_nway_restart(&ks->mii);
}
static void ks8851_eeprom_regread(struct eeprom_93cx6 *ee)
{
struct ks8851_net *ks = ee->data;
unsigned val;
val = ks8851_rdreg16(ks, KS_EEPCR);
ee->reg_data_out = (val & EEPCR_EESB) ? 1 : 0;
ee->reg_data_clock = (val & EEPCR_EESCK) ? 1 : 0;
ee->reg_chip_select = (val & EEPCR_EECS) ? 1 : 0;
}
static void ks8851_eeprom_regwrite(struct eeprom_93cx6 *ee)
{
struct ks8851_net *ks = ee->data;
unsigned val = EEPCR_EESA;
if (ee->drive_data)
val |= EEPCR_EESRWA;
if (ee->reg_data_in)
val |= EEPCR_EEDO;
if (ee->reg_data_clock)
val |= EEPCR_EESCK;
if (ee->reg_chip_select)
val |= EEPCR_EECS;
ks8851_wrreg16(ks, KS_EEPCR, val);
}
static int ks8851_eeprom_claim(struct ks8851_net *ks)
{
if (!(ks->rc_ccr & CCR_EEPROM))
return -ENOENT;
mutex_lock(&ks->lock);
ks8851_wrreg16(ks, KS_EEPCR, EEPCR_EESA | EEPCR_EECS);
return 0;
}
static void ks8851_eeprom_release(struct ks8851_net *ks)
{
unsigned val = ks8851_rdreg16(ks, KS_EEPCR);
ks8851_wrreg16(ks, KS_EEPCR, val & ~EEPCR_EESA);
mutex_unlock(&ks->lock);
}
static int ks8851_set_eeprom(struct net_device *dev,
struct ethtool_eeprom *ee, u8 *data)
{
struct ks8851_net *ks = netdev_priv(dev);
int offset = ee->offset;
int len = ee->len;
u16 tmp;
if (len != 1)
return -EINVAL;
if (ee->magic != KS_EEPROM_MAGIC)
return -EINVAL;
if (ks8851_eeprom_claim(ks))
return -ENOENT;
eeprom_93cx6_wren(&ks->eeprom, true);
eeprom_93cx6_read(&ks->eeprom, offset/2, &tmp);
if (offset & 1) {
tmp &= 0xff;
tmp |= *data << 8;
} else {
tmp &= 0xff00;
tmp |= *data;
}
eeprom_93cx6_write(&ks->eeprom, offset/2, tmp);
eeprom_93cx6_wren(&ks->eeprom, false);
ks8851_eeprom_release(ks);
return 0;
}
static int ks8851_get_eeprom(struct net_device *dev,
struct ethtool_eeprom *ee, u8 *data)
{
struct ks8851_net *ks = netdev_priv(dev);
int offset = ee->offset;
int len = ee->len;
if (len & 1 || offset & 1)
return -EINVAL;
if (ks8851_eeprom_claim(ks))
return -ENOENT;
ee->magic = KS_EEPROM_MAGIC;
eeprom_93cx6_multiread(&ks->eeprom, offset/2, (__le16 *)data, len/2);
ks8851_eeprom_release(ks);
return 0;
}
static int ks8851_get_eeprom_len(struct net_device *dev)
{
struct ks8851_net *ks = netdev_priv(dev);
return ks->rc_ccr & CCR_EEPROM ? 128 : 0;
}
static int ks8851_phy_reg(int reg)
{
switch (reg) {
case MII_BMCR:
return KS_P1MBCR;
case MII_BMSR:
return KS_P1MBSR;
case MII_PHYSID1:
return KS_PHY1ILR;
case MII_PHYSID2:
return KS_PHY1IHR;
case MII_ADVERTISE:
return KS_P1ANAR;
case MII_LPA:
return KS_P1ANLPR;
}
return 0x0;
}
static int ks8851_phy_read(struct net_device *dev, int phy_addr, int reg)
{
struct ks8851_net *ks = netdev_priv(dev);
int ksreg;
int result;
ksreg = ks8851_phy_reg(reg);
if (!ksreg)
return 0x0;
mutex_lock(&ks->lock);
result = ks8851_rdreg16(ks, ksreg);
mutex_unlock(&ks->lock);
return result;
}
static void ks8851_phy_write(struct net_device *dev,
int phy, int reg, int value)
{
struct ks8851_net *ks = netdev_priv(dev);
int ksreg;
ksreg = ks8851_phy_reg(reg);
if (ksreg) {
mutex_lock(&ks->lock);
ks8851_wrreg16(ks, ksreg, value);
mutex_unlock(&ks->lock);
}
}
static int ks8851_read_selftest(struct ks8851_net *ks)
{
unsigned both_done = MBIR_TXMBF | MBIR_RXMBF;
int ret = 0;
unsigned rd;
rd = ks8851_rdreg16(ks, KS_MBIR);
if ((rd & both_done) != both_done) {
netdev_warn(ks->netdev, "Memory selftest not finished\n");
return 0;
}
if (rd & MBIR_TXMBFA) {
netdev_err(ks->netdev, "TX memory selftest fail\n");
ret |= 1;
}
if (rd & MBIR_RXMBFA) {
netdev_err(ks->netdev, "RX memory selftest fail\n");
ret |= 2;
}
return 0;
}
static int ks8851_suspend(struct device *dev)
{
struct ks8851_net *ks = dev_get_drvdata(dev);
struct net_device *netdev = ks->netdev;
if (netif_running(netdev)) {
netif_device_detach(netdev);
ks8851_net_stop(netdev);
}
return 0;
}
static int ks8851_resume(struct device *dev)
{
struct ks8851_net *ks = dev_get_drvdata(dev);
struct net_device *netdev = ks->netdev;
if (netif_running(netdev)) {
ks8851_net_open(netdev);
netif_device_attach(netdev);
}
return 0;
}
static int ks8851_probe(struct spi_device *spi)
{
struct net_device *ndev;
struct ks8851_net *ks;
int ret;
unsigned cider;
int gpio;
ndev = alloc_etherdev(sizeof(struct ks8851_net));
if (!ndev)
return -ENOMEM;
spi->bits_per_word = 8;
ks = netdev_priv(ndev);
ks->netdev = ndev;
ks->spidev = spi;
ks->tx_space = 6144;
gpio = of_get_named_gpio_flags(spi->dev.of_node, "reset-gpios",
0, NULL);
if (gpio == -EPROBE_DEFER) {
ret = gpio;
goto err_gpio;
}
ks->gpio = gpio;
if (gpio_is_valid(gpio)) {
ret = devm_gpio_request_one(&spi->dev, gpio,
GPIOF_OUT_INIT_LOW, "ks8851_rst_n");
if (ret) {
dev_err(&spi->dev, "reset gpio request failed\n");
goto err_gpio;
}
}
ks->vdd_io = devm_regulator_get(&spi->dev, "vdd-io");
if (IS_ERR(ks->vdd_io)) {
ret = PTR_ERR(ks->vdd_io);
goto err_reg_io;
}
ret = regulator_enable(ks->vdd_io);
if (ret) {
dev_err(&spi->dev, "regulator vdd_io enable fail: %d\n",
ret);
goto err_reg_io;
}
ks->vdd_reg = devm_regulator_get(&spi->dev, "vdd");
if (IS_ERR(ks->vdd_reg)) {
ret = PTR_ERR(ks->vdd_reg);
goto err_reg;
}
ret = regulator_enable(ks->vdd_reg);
if (ret) {
dev_err(&spi->dev, "regulator vdd enable fail: %d\n",
ret);
goto err_reg;
}
if (gpio_is_valid(gpio)) {
usleep_range(10000, 11000);
gpio_set_value(gpio, 1);
}
mutex_init(&ks->lock);
spin_lock_init(&ks->statelock);
INIT_WORK(&ks->tx_work, ks8851_tx_work);
INIT_WORK(&ks->rxctrl_work, ks8851_rxctrl_work);
spi_message_init(&ks->spi_msg1);
spi_message_add_tail(&ks->spi_xfer1, &ks->spi_msg1);
spi_message_init(&ks->spi_msg2);
spi_message_add_tail(&ks->spi_xfer2[0], &ks->spi_msg2);
spi_message_add_tail(&ks->spi_xfer2[1], &ks->spi_msg2);
ks->eeprom.data = ks;
ks->eeprom.width = PCI_EEPROM_WIDTH_93C46;
ks->eeprom.register_read = ks8851_eeprom_regread;
ks->eeprom.register_write = ks8851_eeprom_regwrite;
ks->mii.dev = ndev;
ks->mii.phy_id = 1,
ks->mii.phy_id_mask = 1;
ks->mii.reg_num_mask = 0xf;
ks->mii.mdio_read = ks8851_phy_read;
ks->mii.mdio_write = ks8851_phy_write;
dev_info(&spi->dev, "message enable is %d\n", msg_enable);
ks->msg_enable = netif_msg_init(msg_enable, (NETIF_MSG_DRV |
NETIF_MSG_PROBE |
NETIF_MSG_LINK));
skb_queue_head_init(&ks->txq);
ndev->ethtool_ops = &ks8851_ethtool_ops;
SET_NETDEV_DEV(ndev, &spi->dev);
spi_set_drvdata(spi, ks);
ndev->if_port = IF_PORT_100BASET;
ndev->netdev_ops = &ks8851_netdev_ops;
ndev->irq = spi->irq;
ks8851_soft_reset(ks, GRR_GSR);
cider = ks8851_rdreg16(ks, KS_CIDER);
if ((cider & ~CIDER_REV_MASK) != CIDER_ID) {
dev_err(&spi->dev, "failed to read device ID\n");
ret = -ENODEV;
goto err_id;
}
ks->rc_ccr = ks8851_rdreg16(ks, KS_CCR);
ks8851_read_selftest(ks);
ks8851_init_mac(ks);
ret = request_threaded_irq(spi->irq, NULL, ks8851_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
ndev->name, ks);
if (ret < 0) {
dev_err(&spi->dev, "failed to get irq\n");
goto err_irq;
}
ret = register_netdev(ndev);
if (ret) {
dev_err(&spi->dev, "failed to register network device\n");
goto err_netdev;
}
netdev_info(ndev, "revision %d, MAC %pM, IRQ %d, %s EEPROM\n",
CIDER_REV_GET(cider), ndev->dev_addr, ndev->irq,
ks->rc_ccr & CCR_EEPROM ? "has" : "no");
return 0;
err_netdev:
free_irq(ndev->irq, ks);
err_irq:
if (gpio_is_valid(gpio))
gpio_set_value(gpio, 0);
err_id:
regulator_disable(ks->vdd_reg);
err_reg:
regulator_disable(ks->vdd_io);
err_reg_io:
err_gpio:
free_netdev(ndev);
return ret;
}
static int ks8851_remove(struct spi_device *spi)
{
struct ks8851_net *priv = spi_get_drvdata(spi);
if (netif_msg_drv(priv))
dev_info(&spi->dev, "remove\n");
unregister_netdev(priv->netdev);
free_irq(spi->irq, priv);
if (gpio_is_valid(priv->gpio))
gpio_set_value(priv->gpio, 0);
regulator_disable(priv->vdd_reg);
regulator_disable(priv->vdd_io);
free_netdev(priv->netdev);
return 0;
}
