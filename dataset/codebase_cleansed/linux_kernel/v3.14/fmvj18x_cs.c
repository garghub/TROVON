static int fmvj18x_probe(struct pcmcia_device *link)
{
local_info_t *lp;
struct net_device *dev;
dev_dbg(&link->dev, "fmvj18x_attach()\n");
dev = alloc_etherdev(sizeof(local_info_t));
if (!dev)
return -ENOMEM;
lp = netdev_priv(dev);
link->priv = dev;
lp->p_dev = link;
lp->base = NULL;
link->resource[0]->end = 32;
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
link->config_flags |= CONF_ENABLE_IRQ;
dev->netdev_ops = &fjn_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
SET_ETHTOOL_OPS(dev, &netdev_ethtool_ops);
return fmvj18x_config(link);
}
static void fmvj18x_detach(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
dev_dbg(&link->dev, "fmvj18x_detach\n");
unregister_netdev(dev);
fmvj18x_release(link);
free_netdev(dev);
}
static int mfc_try_io_port(struct pcmcia_device *link)
{
int i, ret;
static const unsigned int serial_base[5] =
{ 0x3f8, 0x2f8, 0x3e8, 0x2e8, 0x0 };
for (i = 0; i < 5; i++) {
link->resource[1]->start = serial_base[i];
link->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
if (link->resource[1]->start == 0) {
link->resource[1]->end = 0;
pr_notice("out of resource for serial\n");
}
ret = pcmcia_request_io(link);
if (ret == 0)
return ret;
}
return ret;
}
static int ungermann_try_io_port(struct pcmcia_device *link)
{
int ret;
unsigned int ioaddr;
for (ioaddr = 0x300; ioaddr < 0x3e0; ioaddr += 0x20) {
link->resource[0]->start = ioaddr;
ret = pcmcia_request_io(link);
if (ret == 0) {
link->config_index =
((link->resource[0]->start & 0x0f0) >> 3) | 0x22;
return ret;
}
}
return ret;
}
static int fmvj18x_ioprobe(struct pcmcia_device *p_dev, void *priv_data)
{
return 0;
}
static int fmvj18x_config(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
local_info_t *lp = netdev_priv(dev);
int i, ret;
unsigned int ioaddr;
cardtype_t cardtype;
char *card_name = "unknown";
u8 *buf;
size_t len;
u_char buggybuf[32];
dev_dbg(&link->dev, "fmvj18x_config\n");
link->io_lines = 5;
len = pcmcia_get_tuple(link, CISTPL_FUNCE, &buf);
kfree(buf);
if (len) {
ret = pcmcia_loop_config(link, fmvj18x_ioprobe, NULL);
if (ret != 0)
goto failed;
switch (link->manf_id) {
case MANFID_TDK:
cardtype = TDK;
if (link->card_id == PRODID_TDK_GN3410 ||
link->card_id == PRODID_TDK_NP9610 ||
link->card_id == PRODID_TDK_MN3200) {
link->config_base = 0x800;
link->config_index = 0x47;
link->resource[1]->end = 8;
}
break;
case MANFID_NEC:
cardtype = NEC;
link->config_base = 0x800;
link->config_index = 0x47;
link->resource[1]->end = 8;
break;
case MANFID_KME:
cardtype = KME;
link->config_base = 0x800;
link->config_index = 0x47;
link->resource[1]->end = 8;
break;
case MANFID_CONTEC:
cardtype = CONTEC;
break;
case MANFID_FUJITSU:
if (link->config_base == 0x0fe0)
cardtype = MBH10302;
else if (link->card_id == PRODID_FUJITSU_MBH10302)
cardtype = MBH10304;
else if (link->card_id == PRODID_FUJITSU_MBH10304)
cardtype = MBH10304;
else
cardtype = LA501;
break;
default:
cardtype = MBH10304;
}
} else {
switch (link->manf_id) {
case MANFID_FUJITSU:
if (link->card_id == PRODID_FUJITSU_MBH10304) {
cardtype = XXX10304;
link->config_index = 0x20;
} else {
cardtype = MBH10302;
link->config_index = 1;
}
break;
case MANFID_UNGERMANN:
cardtype = UNGERMANN;
break;
default:
cardtype = MBH10302;
link->config_index = 1;
}
}
if (link->resource[1]->end != 0) {
ret = mfc_try_io_port(link);
if (ret != 0) goto failed;
} else if (cardtype == UNGERMANN) {
ret = ungermann_try_io_port(link);
if (ret != 0) goto failed;
} else {
ret = pcmcia_request_io(link);
if (ret)
goto failed;
}
ret = pcmcia_request_irq(link, fjn_interrupt);
if (ret)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
dev->irq = link->irq;
dev->base_addr = link->resource[0]->start;
if (resource_size(link->resource[1]) != 0) {
ret = fmvj18x_setup_mfc(link);
if (ret != 0) goto failed;
}
ioaddr = dev->base_addr;
if (sram_config == 0)
outb(CONFIG0_RST, ioaddr + CONFIG_0);
else
outb(CONFIG0_RST_1, ioaddr + CONFIG_0);
if (cardtype == MBH10302)
outb(BANK_0, ioaddr + CONFIG_1);
else
outb(BANK_0U, ioaddr + CONFIG_1);
switch (cardtype) {
case MBH10304:
case TDK:
case LA501:
case CONTEC:
case NEC:
case KME:
if (cardtype == MBH10304) {
card_name = "FMV-J182";
len = pcmcia_get_tuple(link, CISTPL_FUNCE, &buf);
if (len < 11) {
kfree(buf);
goto failed;
}
for (i = 5; i < 11; i++)
dev->dev_addr[i] = buf[i];
kfree(buf);
} else {
if (pcmcia_get_mac_from_cis(link, dev))
goto failed;
if( cardtype == TDK ) {
card_name = "TDK LAK-CD021";
} else if( cardtype == LA501 ) {
card_name = "LA501";
} else if( cardtype == NEC ) {
card_name = "PK-UG-J001";
} else if( cardtype == KME ) {
card_name = "Panasonic";
} else {
card_name = "C-NET(PC)C";
}
}
break;
case UNGERMANN:
for (i = 0; i < 6; i++)
dev->dev_addr[i] = inb(ioaddr + UNGERMANN_MAC_ID + i);
card_name = "Access/CARD";
break;
case XXX10304:
if (fmvj18x_get_hwinfo(link, buggybuf) == -1) {
pr_notice("unable to read hardware net address\n");
goto failed;
}
for (i = 0 ; i < 6; i++) {
dev->dev_addr[i] = buggybuf[i];
}
card_name = "FMV-J182";
break;
case MBH10302:
default:
for (i = 0; i < 6; i++)
dev->dev_addr[i] = inb(ioaddr + MAC_ID + i);
card_name = "FMV-J181";
break;
}
lp->cardtype = cardtype;
SET_NETDEV_DEV(dev, &link->dev);
if (register_netdev(dev) != 0) {
pr_notice("register_netdev() failed\n");
goto failed;
}
netdev_info(dev, "%s, sram %s, port %#3lx, irq %d, hw_addr %pM\n",
card_name, sram_config == 0 ? "4K TX*2" : "8K TX*2",
dev->base_addr, dev->irq, dev->dev_addr);
return 0;
failed:
fmvj18x_release(link);
return -ENODEV;
}
static int fmvj18x_get_hwinfo(struct pcmcia_device *link, u_char *node_id)
{
u_char __iomem *base;
int i, j;
link->resource[2]->flags |= WIN_DATA_WIDTH_8|WIN_MEMORY_TYPE_AM|WIN_ENABLE;
link->resource[2]->start = 0; link->resource[2]->end = 0;
i = pcmcia_request_window(link, link->resource[2], 0);
if (i != 0)
return -1;
base = ioremap(link->resource[2]->start, resource_size(link->resource[2]));
pcmcia_map_mem_page(link, link->resource[2], 0);
for (i = 0; i < 0x200; i++) {
if (readb(base+i*2) == 0x22) {
if (readb(base+(i-1)*2) == 0xff &&
readb(base+(i+5)*2) == 0x04 &&
readb(base+(i+6)*2) == 0x06 &&
readb(base+(i+13)*2) == 0xff)
break;
}
}
if (i != 0x200) {
for (j = 0 ; j < 6; j++,i++) {
node_id[j] = readb(base+(i+7)*2);
}
}
iounmap(base);
j = pcmcia_release_window(link, link->resource[2]);
return (i != 0x200) ? 0 : -1;
}
static int fmvj18x_setup_mfc(struct pcmcia_device *link)
{
int i;
struct net_device *dev = link->priv;
unsigned int ioaddr;
local_info_t *lp = netdev_priv(dev);
link->resource[3]->flags = WIN_DATA_WIDTH_8|WIN_MEMORY_TYPE_AM|WIN_ENABLE;
link->resource[3]->start = link->resource[3]->end = 0;
i = pcmcia_request_window(link, link->resource[3], 0);
if (i != 0)
return -1;
lp->base = ioremap(link->resource[3]->start,
resource_size(link->resource[3]));
if (lp->base == NULL) {
netdev_notice(dev, "ioremap failed\n");
return -1;
}
i = pcmcia_map_mem_page(link, link->resource[3], 0);
if (i != 0) {
iounmap(lp->base);
lp->base = NULL;
return -1;
}
ioaddr = dev->base_addr;
writeb(0x47, lp->base+0x800);
writeb(0x0, lp->base+0x802);
writeb(ioaddr & 0xff, lp->base+0x80a);
writeb((ioaddr >> 8) & 0xff, lp->base+0x80c);
writeb(0x45, lp->base+0x820);
writeb(0x8, lp->base+0x822);
return 0;
}
static void fmvj18x_release(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
local_info_t *lp = netdev_priv(dev);
u_char __iomem *tmp;
dev_dbg(&link->dev, "fmvj18x_release\n");
if (lp->base != NULL) {
tmp = lp->base;
lp->base = NULL;
iounmap(tmp);
}
pcmcia_disable_device(link);
}
static int fmvj18x_suspend(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open)
netif_device_detach(dev);
return 0;
}
static int fmvj18x_resume(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open) {
fjn_reset(dev);
netif_device_attach(dev);
}
return 0;
}
static irqreturn_t fjn_interrupt(int dummy, void *dev_id)
{
struct net_device *dev = dev_id;
local_info_t *lp = netdev_priv(dev);
unsigned int ioaddr;
unsigned short tx_stat, rx_stat;
ioaddr = dev->base_addr;
outw(0x0000, ioaddr + TX_INTR);
udelay(1);
tx_stat = inb(ioaddr + TX_STATUS);
rx_stat = inb(ioaddr + RX_STATUS);
outb(tx_stat, ioaddr + TX_STATUS);
outb(rx_stat, ioaddr + RX_STATUS);
pr_debug("%s: interrupt, rx_status %02x.\n", dev->name, rx_stat);
pr_debug(" tx_status %02x.\n", tx_stat);
if (rx_stat || (inb(ioaddr + RX_MODE) & F_BUF_EMP) == 0) {
fjn_rx(dev);
}
if (tx_stat & F_TMT_RDY) {
dev->stats.tx_packets += lp->sent ;
lp->sent = 0 ;
if (lp->tx_queue) {
outb(DO_TX | lp->tx_queue, ioaddr + TX_START);
lp->sent = lp->tx_queue ;
lp->tx_queue = 0;
lp->tx_queue_len = 0;
dev->trans_start = jiffies;
} else {
lp->tx_started = 0;
}
netif_wake_queue(dev);
}
pr_debug("%s: exiting interrupt,\n", dev->name);
pr_debug(" tx_status %02x, rx_status %02x.\n", tx_stat, rx_stat);
outb(D_TX_INTR, ioaddr + TX_INTR);
outb(D_RX_INTR, ioaddr + RX_INTR);
if (lp->base != NULL) {
writeb(0x01, lp->base+0x802);
writeb(0x09, lp->base+0x822);
}
return IRQ_HANDLED;
}
static void fjn_tx_timeout(struct net_device *dev)
{
struct local_info_t *lp = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
netdev_notice(dev, "transmit timed out with status %04x, %s?\n",
htons(inw(ioaddr + TX_STATUS)),
inb(ioaddr + TX_STATUS) & F_TMT_RDY
? "IRQ conflict" : "network cable problem");
netdev_notice(dev, "timeout registers: %04x %04x %04x "
"%04x %04x %04x %04x %04x.\n",
htons(inw(ioaddr + 0)), htons(inw(ioaddr + 2)),
htons(inw(ioaddr + 4)), htons(inw(ioaddr + 6)),
htons(inw(ioaddr + 8)), htons(inw(ioaddr + 10)),
htons(inw(ioaddr + 12)), htons(inw(ioaddr + 14)));
dev->stats.tx_errors++;
local_irq_disable();
fjn_reset(dev);
lp->tx_started = 0;
lp->tx_queue = 0;
lp->tx_queue_len = 0;
lp->sent = 0;
lp->open_time = jiffies;
local_irq_enable();
netif_wake_queue(dev);
}
static netdev_tx_t fjn_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct local_info_t *lp = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
short length = skb->len;
if (length < ETH_ZLEN)
{
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
length = ETH_ZLEN;
}
netif_stop_queue(dev);
{
unsigned char *buf = skb->data;
if (length > ETH_FRAME_LEN) {
netdev_notice(dev, "Attempting to send a large packet (%d bytes)\n",
length);
return NETDEV_TX_BUSY;
}
netdev_dbg(dev, "Transmitting a packet of length %lu\n",
(unsigned long)skb->len);
dev->stats.tx_bytes += skb->len;
outw(0x0000, ioaddr + TX_INTR);
udelay(1);
outw(length, ioaddr + DATAPORT);
outsw(ioaddr + DATAPORT, buf, (length + 1) >> 1);
lp->tx_queue++;
lp->tx_queue_len += ((length+3) & ~1);
if (lp->tx_started == 0) {
outb(DO_TX | lp->tx_queue, ioaddr + TX_START);
lp->sent = lp->tx_queue ;
lp->tx_queue = 0;
lp->tx_queue_len = 0;
lp->tx_started = 1;
netif_start_queue(dev);
} else {
if( sram_config == 0 ) {
if (lp->tx_queue_len < (4096 - (ETH_FRAME_LEN +2)) )
netif_start_queue(dev);
} else {
if (lp->tx_queue_len < (8192 - (ETH_FRAME_LEN +2)) &&
lp->tx_queue < 127 )
netif_start_queue(dev);
}
}
outb(D_TX_INTR, ioaddr + TX_INTR);
outb(D_RX_INTR, ioaddr + RX_INTR);
}
dev_kfree_skb (skb);
return NETDEV_TX_OK;
}
static void fjn_reset(struct net_device *dev)
{
struct local_info_t *lp = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
int i;
netdev_dbg(dev, "fjn_reset() called\n");
if( sram_config == 0 )
outb(CONFIG0_RST, ioaddr + CONFIG_0);
else
outb(CONFIG0_RST_1, ioaddr + CONFIG_0);
if (lp->cardtype == MBH10302)
outb(BANK_0, ioaddr + CONFIG_1);
else
outb(BANK_0U, ioaddr + CONFIG_1);
outb(D_TX_MODE, ioaddr + TX_MODE);
outb(ID_MATCHED, ioaddr + RX_MODE);
for (i = 0; i < 6; i++)
outb(dev->dev_addr[i], ioaddr + NODE_ID + i);
set_rx_mode(dev);
if (lp->cardtype == MBH10302)
outb(BANK_2, ioaddr + CONFIG_1);
else
outb(BANK_2U, ioaddr + CONFIG_1);
if( lp->cardtype == TDK || lp->cardtype == CONTEC)
outb(TDK_AUTO_MODE, ioaddr + COL_CTRL);
else
outb(AUTO_MODE, ioaddr + COL_CTRL);
outb(0x00, ioaddr + BMPR12);
outb(0x00, ioaddr + BMPR13);
outb(0x01, ioaddr + RX_SKIP);
if( sram_config == 0 )
outb(CONFIG0_DFL, ioaddr + CONFIG_0);
else
outb(CONFIG0_DFL_1, ioaddr + CONFIG_0);
inw(ioaddr + DATAPORT);
inw(ioaddr + DATAPORT);
outb(0xff, ioaddr + TX_STATUS);
outb(0xff, ioaddr + RX_STATUS);
if (lp->cardtype == MBH10302)
outb(INTR_OFF, ioaddr + LAN_CTRL);
outb(D_TX_INTR, ioaddr + TX_INTR);
outb(D_RX_INTR, ioaddr + RX_INTR);
if (lp->cardtype == MBH10302)
outb(INTR_ON, ioaddr + LAN_CTRL);
}
static void fjn_rx(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
int boguscount = 10;
pr_debug("%s: in rx_packet(), rx_status %02x.\n",
dev->name, inb(ioaddr + RX_STATUS));
while ((inb(ioaddr + RX_MODE) & F_BUF_EMP) == 0) {
u_short status = inw(ioaddr + DATAPORT);
netdev_dbg(dev, "Rxing packet mode %02x status %04x.\n",
inb(ioaddr + RX_MODE), status);
#ifndef final_version
if (status == 0) {
outb(F_SKP_PKT, ioaddr + RX_SKIP);
break;
}
#endif
if ((status & 0xF0) != 0x20) {
dev->stats.rx_errors++;
if (status & F_LEN_ERR) dev->stats.rx_length_errors++;
if (status & F_ALG_ERR) dev->stats.rx_frame_errors++;
if (status & F_CRC_ERR) dev->stats.rx_crc_errors++;
if (status & F_OVR_FLO) dev->stats.rx_over_errors++;
} else {
u_short pkt_len = inw(ioaddr + DATAPORT);
struct sk_buff *skb;
if (pkt_len > 1550) {
netdev_notice(dev, "The FMV-18x claimed a very large packet, size %d\n",
pkt_len);
outb(F_SKP_PKT, ioaddr + RX_SKIP);
dev->stats.rx_errors++;
break;
}
skb = netdev_alloc_skb(dev, pkt_len + 2);
if (skb == NULL) {
outb(F_SKP_PKT, ioaddr + RX_SKIP);
dev->stats.rx_dropped++;
break;
}
skb_reserve(skb, 2);
insw(ioaddr + DATAPORT, skb_put(skb, pkt_len),
(pkt_len + 1) >> 1);
skb->protocol = eth_type_trans(skb, dev);
{
int i;
pr_debug("%s: Rxed packet of length %d: ",
dev->name, pkt_len);
for (i = 0; i < 14; i++)
pr_debug(" %02x", skb->data[i]);
pr_debug(".\n");
}
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
if (--boguscount <= 0)
break;
}
}
static void netdev_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
snprintf(info->bus_info, sizeof(info->bus_info),
"PCMCIA 0x%lx", dev->base_addr);
}
static int fjn_config(struct net_device *dev, struct ifmap *map){
return 0;
}
static int fjn_open(struct net_device *dev)
{
struct local_info_t *lp = netdev_priv(dev);
struct pcmcia_device *link = lp->p_dev;
pr_debug("fjn_open('%s').\n", dev->name);
if (!pcmcia_dev_present(link))
return -ENODEV;
link->open++;
fjn_reset(dev);
lp->tx_started = 0;
lp->tx_queue = 0;
lp->tx_queue_len = 0;
lp->open_time = jiffies;
netif_start_queue(dev);
return 0;
}
static int fjn_close(struct net_device *dev)
{
struct local_info_t *lp = netdev_priv(dev);
struct pcmcia_device *link = lp->p_dev;
unsigned int ioaddr = dev->base_addr;
pr_debug("fjn_close('%s').\n", dev->name);
lp->open_time = 0;
netif_stop_queue(dev);
if( sram_config == 0 )
outb(CONFIG0_RST ,ioaddr + CONFIG_0);
else
outb(CONFIG0_RST_1 ,ioaddr + CONFIG_0);
outb(CHIP_OFF ,ioaddr + CONFIG_1);
if (lp->cardtype == MBH10302)
outb(INTR_OFF, ioaddr + LAN_CTRL);
link->open--;
return 0;
}
static void set_rx_mode(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
u_char mc_filter[8];
u_long flags;
int i;
int saved_bank;
int saved_config_0 = inb(ioaddr + CONFIG_0);
local_irq_save(flags);
if (sram_config == 0)
outb(CONFIG0_RST, ioaddr + CONFIG_0);
else
outb(CONFIG0_RST_1, ioaddr + CONFIG_0);
if (dev->flags & IFF_PROMISC) {
memset(mc_filter, 0xff, sizeof(mc_filter));
outb(3, ioaddr + RX_MODE);
} else if (netdev_mc_count(dev) > MC_FILTERBREAK ||
(dev->flags & IFF_ALLMULTI)) {
memset(mc_filter, 0xff, sizeof(mc_filter));
outb(2, ioaddr + RX_MODE);
} else if (netdev_mc_empty(dev)) {
memset(mc_filter, 0x00, sizeof(mc_filter));
outb(1, ioaddr + RX_MODE);
} else {
struct netdev_hw_addr *ha;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
unsigned int bit = ether_crc_le(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit >> 3] |= (1 << (bit & 7));
}
outb(2, ioaddr + RX_MODE);
}
saved_bank = inb(ioaddr + CONFIG_1);
outb(0xe4, ioaddr + CONFIG_1);
for (i = 0; i < 8; i++)
outb(mc_filter[i], ioaddr + MAR_ADR + i);
outb(saved_bank, ioaddr + CONFIG_1);
outb(saved_config_0, ioaddr + CONFIG_0);
local_irq_restore(flags);
}
