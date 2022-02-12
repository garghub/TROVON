static int __init
etrax_ethernet_init(void)
{
struct net_device *dev;
struct net_local* np;
int i, err;
printk(KERN_INFO
"ETRAX 100LX 10/100MBit ethernet v2.0 (c) 1998-2007 Axis Communications AB\n");
if (cris_request_io_interface(if_eth, cardname)) {
printk(KERN_CRIT "etrax_ethernet_init failed to get IO interface\n");
return -EBUSY;
}
dev = alloc_etherdev(sizeof(struct net_local));
if (!dev)
return -ENOMEM;
np = netdev_priv(dev);
dev->features |= NETIF_F_LLTX;
dev->base_addr = (unsigned int)R_NETWORK_SA_0;
dev->irq = NETWORK_DMA_RX_IRQ_NBR;
dev->dma = NETWORK_RX_DMA_NBR;
dev->ethtool_ops = &e100_ethtool_ops;
dev->netdev_ops = &e100_netdev_ops;
spin_lock_init(&np->lock);
spin_lock_init(&np->led_lock);
spin_lock_init(&np->transceiver_lock);
for (i = 0; i < NBR_OF_RX_DESC; i++) {
RxDescList[i].skb = dev_alloc_skb(MAX_MEDIA_DATA_SIZE + 2 * L1_CACHE_BYTES);
if (!RxDescList[i].skb)
return -ENOMEM;
RxDescList[i].descr.ctrl = 0;
RxDescList[i].descr.sw_len = MAX_MEDIA_DATA_SIZE;
RxDescList[i].descr.next = virt_to_phys(&RxDescList[i + 1]);
RxDescList[i].descr.buf = L1_CACHE_ALIGN(virt_to_phys(RxDescList[i].skb->data));
RxDescList[i].descr.status = 0;
RxDescList[i].descr.hw_len = 0;
prepare_rx_descriptor(&RxDescList[i].descr);
}
RxDescList[NBR_OF_RX_DESC - 1].descr.ctrl = d_eol;
RxDescList[NBR_OF_RX_DESC - 1].descr.next = virt_to_phys(&RxDescList[0]);
rx_queue_len = 0;
for (i = 0; i < NBR_OF_TX_DESC; i++) {
TxDescList[i].descr.ctrl = 0;
TxDescList[i].descr.sw_len = 0;
TxDescList[i].descr.next = virt_to_phys(&TxDescList[i + 1].descr);
TxDescList[i].descr.buf = 0;
TxDescList[i].descr.status = 0;
TxDescList[i].descr.hw_len = 0;
TxDescList[i].skb = 0;
}
TxDescList[NBR_OF_TX_DESC - 1].descr.ctrl = d_eol;
TxDescList[NBR_OF_TX_DESC - 1].descr.next = virt_to_phys(&TxDescList[0].descr);
myNextRxDesc = &RxDescList[0];
myLastRxDesc = &RxDescList[NBR_OF_RX_DESC - 1];
myFirstTxDesc = &TxDescList[0];
myNextTxDesc = &TxDescList[0];
myLastTxDesc = &TxDescList[NBR_OF_TX_DESC - 1];
err = register_netdev(dev);
if (err) {
free_netdev(dev);
return err;
}
e100_set_mac_address(dev, &default_mac);
current_speed = 10;
current_speed_selection = 0;
speed_timer.expires = jiffies + NET_LINK_UP_CHECK_INTERVAL;
speed_timer.data = (unsigned long)dev;
speed_timer.function = e100_check_speed;
clear_led_timer.function = e100_clear_network_leds;
clear_led_timer.data = (unsigned long)dev;
full_duplex = 0;
current_duplex = autoneg;
duplex_timer.expires = jiffies + NET_DUPLEX_CHECK_INTERVAL;
duplex_timer.data = (unsigned long)dev;
duplex_timer.function = e100_check_duplex;
np->mii_if.phy_id_mask = 0x1f;
np->mii_if.reg_num_mask = 0x1f;
np->mii_if.dev = dev;
np->mii_if.mdio_read = e100_get_mdio_reg;
np->mii_if.mdio_write = e100_set_mdio_reg;
*R_NETWORK_GA_0 = 0x00000000;
*R_NETWORK_GA_1 = 0x00000000;
led_next_time = jiffies;
return 0;
}
static int
e100_set_mac_address(struct net_device *dev, void *p)
{
struct net_local *np = netdev_priv(dev);
struct sockaddr *addr = p;
spin_lock(&np->lock);
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
*R_NETWORK_SA_0 = dev->dev_addr[0] | (dev->dev_addr[1] << 8) |
(dev->dev_addr[2] << 16) | (dev->dev_addr[3] << 24);
*R_NETWORK_SA_1 = dev->dev_addr[4] | (dev->dev_addr[5] << 8);
*R_NETWORK_SA_2 = 0;
printk(KERN_INFO "%s: changed MAC to %pM\n", dev->name, dev->dev_addr);
spin_unlock(&np->lock);
return 0;
}
static int
e100_open(struct net_device *dev)
{
unsigned long flags;
*R_NETWORK_MGM_CTRL = IO_STATE(R_NETWORK_MGM_CTRL, mdoe, enable);
*R_IRQ_MASK0_CLR =
IO_STATE(R_IRQ_MASK0_CLR, overrun, clr) |
IO_STATE(R_IRQ_MASK0_CLR, underrun, clr) |
IO_STATE(R_IRQ_MASK0_CLR, excessive_col, clr);
*R_IRQ_MASK2_CLR =
IO_STATE(R_IRQ_MASK2_CLR, dma0_descr, clr) |
IO_STATE(R_IRQ_MASK2_CLR, dma0_eop, clr) |
IO_STATE(R_IRQ_MASK2_CLR, dma1_descr, clr) |
IO_STATE(R_IRQ_MASK2_CLR, dma1_eop, clr);
RESET_DMA(NETWORK_TX_DMA_NBR);
RESET_DMA(NETWORK_RX_DMA_NBR);
WAIT_DMA(NETWORK_TX_DMA_NBR);
WAIT_DMA(NETWORK_RX_DMA_NBR);
if (request_irq(NETWORK_DMA_RX_IRQ_NBR, e100rxtx_interrupt, 0, cardname,
(void *)dev)) {
goto grace_exit0;
}
if (request_irq(NETWORK_DMA_TX_IRQ_NBR, e100rxtx_interrupt, 0,
cardname, (void *)dev)) {
goto grace_exit1;
}
if (request_irq(NETWORK_STATUS_IRQ_NBR, e100nw_interrupt, 0,
cardname, (void *)dev)) {
goto grace_exit2;
}
if (cris_request_dma(NETWORK_TX_DMA_NBR,
cardname,
DMA_VERBOSE_ON_ERROR,
dma_eth)) {
goto grace_exit3;
}
if (cris_request_dma(NETWORK_RX_DMA_NBR,
cardname,
DMA_VERBOSE_ON_ERROR,
dma_eth)) {
goto grace_exit4;
}
*R_NETWORK_SA_0 = dev->dev_addr[0] | (dev->dev_addr[1] << 8) |
(dev->dev_addr[2] << 16) | (dev->dev_addr[3] << 24);
*R_NETWORK_SA_1 = dev->dev_addr[4] | (dev->dev_addr[5] << 8);
*R_NETWORK_SA_2 = 0;
#if 0
*R_NETWORK_GA_0 = 0xffffffff;
*R_NETWORK_GA_1 = 0xffffffff;
*R_NETWORK_REC_CONFIG = 0xd;
#else
SETS(network_rec_config_shadow, R_NETWORK_REC_CONFIG, max_size, size1522);
SETS(network_rec_config_shadow, R_NETWORK_REC_CONFIG, broadcast, receive);
SETS(network_rec_config_shadow, R_NETWORK_REC_CONFIG, ma0, enable);
SETF(network_rec_config_shadow, R_NETWORK_REC_CONFIG, duplex, full_duplex);
*R_NETWORK_REC_CONFIG = network_rec_config_shadow;
#endif
*R_NETWORK_GEN_CONFIG =
IO_STATE(R_NETWORK_GEN_CONFIG, phy, mii_clk) |
IO_STATE(R_NETWORK_GEN_CONFIG, enable, on);
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, clr_error, clr);
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, delay, none);
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, cancel, dont);
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, cd, enable);
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, retry, enable);
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, pad, enable);
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, crc, enable);
*R_NETWORK_TR_CTRL = network_tr_ctrl_shadow;
local_irq_save(flags);
*R_IRQ_MASK2_SET =
IO_STATE(R_IRQ_MASK2_SET, dma0_eop, set) |
IO_STATE(R_IRQ_MASK2_SET, dma1_eop, set);
*R_IRQ_MASK0_SET =
IO_STATE(R_IRQ_MASK0_SET, overrun, set) |
IO_STATE(R_IRQ_MASK0_SET, underrun, set) |
IO_STATE(R_IRQ_MASK0_SET, excessive_col, set);
*R_DMA_CH0_CLR_INTR = IO_STATE(R_DMA_CH0_CLR_INTR, clr_eop, do);
*R_DMA_CH1_CLR_INTR = IO_STATE(R_DMA_CH1_CLR_INTR, clr_eop, do);
(void)*R_REC_COUNTERS;
(void)*R_TR_COUNTERS;
*R_DMA_CH1_FIRST = virt_to_phys(myNextRxDesc);
*R_DMA_CH1_CMD = IO_STATE(R_DMA_CH1_CMD, cmd, start);
*R_DMA_CH0_FIRST = 0;
*R_DMA_CH0_DESCR = virt_to_phys(myLastTxDesc);
netif_start_queue(dev);
local_irq_restore(flags);
if (e100_probe_transceiver(dev))
goto grace_exit5;
add_timer(&speed_timer);
add_timer(&duplex_timer);
netif_carrier_on(dev);
return 0;
grace_exit5:
cris_free_dma(NETWORK_RX_DMA_NBR, cardname);
grace_exit4:
cris_free_dma(NETWORK_TX_DMA_NBR, cardname);
grace_exit3:
free_irq(NETWORK_STATUS_IRQ_NBR, (void *)dev);
grace_exit2:
free_irq(NETWORK_DMA_TX_IRQ_NBR, (void *)dev);
grace_exit1:
free_irq(NETWORK_DMA_RX_IRQ_NBR, (void *)dev);
grace_exit0:
return -EAGAIN;
}
static void
dummy_check_speed(struct net_device* dev)
{
current_speed = 100;
}
static void
generic_check_speed(struct net_device* dev)
{
unsigned long data;
struct net_local *np = netdev_priv(dev);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id, MII_ADVERTISE);
if ((data & ADVERTISE_100FULL) ||
(data & ADVERTISE_100HALF))
current_speed = 100;
else
current_speed = 10;
}
static void
tdk_check_speed(struct net_device* dev)
{
unsigned long data;
struct net_local *np = netdev_priv(dev);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id,
MDIO_TDK_DIAGNOSTIC_REG);
current_speed = (data & MDIO_TDK_DIAGNOSTIC_RATE ? 100 : 10);
}
static void
broadcom_check_speed(struct net_device* dev)
{
unsigned long data;
struct net_local *np = netdev_priv(dev);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id,
MDIO_AUX_CTRL_STATUS_REG);
current_speed = (data & MDIO_BC_SPEED ? 100 : 10);
}
static void
intel_check_speed(struct net_device* dev)
{
unsigned long data;
struct net_local *np = netdev_priv(dev);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id,
MDIO_INT_STATUS_REG_2);
current_speed = (data & MDIO_INT_SPEED ? 100 : 10);
}
static void
e100_check_speed(unsigned long priv)
{
struct net_device* dev = (struct net_device*)priv;
struct net_local *np = netdev_priv(dev);
static int led_initiated = 0;
unsigned long data;
int old_speed = current_speed;
spin_lock(&np->transceiver_lock);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id, MII_BMSR);
if (!(data & BMSR_LSTATUS)) {
current_speed = 0;
} else {
transceiver->check_speed(dev);
}
spin_lock(&np->led_lock);
if ((old_speed != current_speed) || !led_initiated) {
led_initiated = 1;
e100_set_network_leds(NO_NETWORK_ACTIVITY);
if (current_speed)
netif_carrier_on(dev);
else
netif_carrier_off(dev);
}
spin_unlock(&np->led_lock);
speed_timer.expires = jiffies + NET_LINK_UP_CHECK_INTERVAL;
add_timer(&speed_timer);
spin_unlock(&np->transceiver_lock);
}
static void
e100_negotiate(struct net_device* dev)
{
struct net_local *np = netdev_priv(dev);
unsigned short data = e100_get_mdio_reg(dev, np->mii_if.phy_id,
MII_ADVERTISE);
data &= ~(ADVERTISE_100HALF | ADVERTISE_100FULL |
ADVERTISE_10HALF | ADVERTISE_10FULL);
switch (current_speed_selection) {
case 10:
if (current_duplex == full)
data |= ADVERTISE_10FULL;
else if (current_duplex == half)
data |= ADVERTISE_10HALF;
else
data |= ADVERTISE_10HALF | ADVERTISE_10FULL;
break;
case 100:
if (current_duplex == full)
data |= ADVERTISE_100FULL;
else if (current_duplex == half)
data |= ADVERTISE_100HALF;
else
data |= ADVERTISE_100HALF | ADVERTISE_100FULL;
break;
case 0:
if (current_duplex == full)
data |= ADVERTISE_100FULL | ADVERTISE_10FULL;
else if (current_duplex == half)
data |= ADVERTISE_100HALF | ADVERTISE_10HALF;
else
data |= ADVERTISE_10HALF | ADVERTISE_10FULL |
ADVERTISE_100HALF | ADVERTISE_100FULL;
break;
default:
data |= ADVERTISE_10HALF | ADVERTISE_10FULL |
ADVERTISE_100HALF | ADVERTISE_100FULL;
break;
}
e100_set_mdio_reg(dev, np->mii_if.phy_id, MII_ADVERTISE, data);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id, MII_BMCR);
if (autoneg_normal) {
data |= BMCR_ANENABLE | BMCR_ANRESTART;
} else {
data &= ~(BMCR_ANENABLE | BMCR_ANRESTART);
if (current_speed_selection == 10)
data &= ~BMCR_SPEED100;
else
data |= BMCR_SPEED100;
if (current_duplex != full)
data &= ~BMCR_FULLDPLX;
else
data |= BMCR_FULLDPLX;
}
e100_set_mdio_reg(dev, np->mii_if.phy_id, MII_BMCR, data);
}
static void
e100_set_speed(struct net_device* dev, unsigned long speed)
{
struct net_local *np = netdev_priv(dev);
spin_lock(&np->transceiver_lock);
if (speed != current_speed_selection) {
current_speed_selection = speed;
e100_negotiate(dev);
}
spin_unlock(&np->transceiver_lock);
}
static void
e100_check_duplex(unsigned long priv)
{
struct net_device *dev = (struct net_device *)priv;
struct net_local *np = netdev_priv(dev);
int old_duplex;
spin_lock(&np->transceiver_lock);
old_duplex = full_duplex;
transceiver->check_duplex(dev);
if (old_duplex != full_duplex) {
SETF(network_rec_config_shadow, R_NETWORK_REC_CONFIG, duplex, full_duplex);
*R_NETWORK_REC_CONFIG = network_rec_config_shadow;
}
duplex_timer.expires = jiffies + NET_DUPLEX_CHECK_INTERVAL;
add_timer(&duplex_timer);
np->mii_if.full_duplex = full_duplex;
spin_unlock(&np->transceiver_lock);
}
static void
dummy_check_duplex(struct net_device* dev)
{
full_duplex = 1;
}
static void
generic_check_duplex(struct net_device* dev)
{
unsigned long data;
struct net_local *np = netdev_priv(dev);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id, MII_ADVERTISE);
if ((data & ADVERTISE_10FULL) ||
(data & ADVERTISE_100FULL))
full_duplex = 1;
else
full_duplex = 0;
}
static void
tdk_check_duplex(struct net_device* dev)
{
unsigned long data;
struct net_local *np = netdev_priv(dev);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id,
MDIO_TDK_DIAGNOSTIC_REG);
full_duplex = (data & MDIO_TDK_DIAGNOSTIC_DPLX) ? 1 : 0;
}
static void
broadcom_check_duplex(struct net_device* dev)
{
unsigned long data;
struct net_local *np = netdev_priv(dev);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id,
MDIO_AUX_CTRL_STATUS_REG);
full_duplex = (data & MDIO_BC_FULL_DUPLEX_IND) ? 1 : 0;
}
static void
intel_check_duplex(struct net_device* dev)
{
unsigned long data;
struct net_local *np = netdev_priv(dev);
data = e100_get_mdio_reg(dev, np->mii_if.phy_id,
MDIO_INT_STATUS_REG_2);
full_duplex = (data & MDIO_INT_FULL_DUPLEX_IND) ? 1 : 0;
}
static void
e100_set_duplex(struct net_device* dev, enum duplex new_duplex)
{
struct net_local *np = netdev_priv(dev);
spin_lock(&np->transceiver_lock);
if (new_duplex != current_duplex) {
current_duplex = new_duplex;
e100_negotiate(dev);
}
spin_unlock(&np->transceiver_lock);
}
static int
e100_probe_transceiver(struct net_device* dev)
{
int ret = 0;
#if !defined(CONFIG_ETRAX_NO_PHY)
unsigned int phyid_high;
unsigned int phyid_low;
unsigned int oui;
struct transceiver_ops* ops = NULL;
struct net_local *np = netdev_priv(dev);
spin_lock(&np->transceiver_lock);
for (np->mii_if.phy_id = 0; np->mii_if.phy_id <= 31;
np->mii_if.phy_id++) {
if (e100_get_mdio_reg(dev,
np->mii_if.phy_id, MII_BMSR) != 0xffff)
break;
}
if (np->mii_if.phy_id == 32) {
ret = -ENODEV;
goto out;
}
phyid_high = e100_get_mdio_reg(dev, np->mii_if.phy_id, MII_PHYSID1);
phyid_low = e100_get_mdio_reg(dev, np->mii_if.phy_id, MII_PHYSID2);
oui = (phyid_high << 6) | (phyid_low >> 10);
for (ops = &transceivers[0]; ops->oui; ops++) {
if (ops->oui == oui)
break;
}
transceiver = ops;
out:
spin_unlock(&np->transceiver_lock);
#endif
return ret;
}
static int
e100_get_mdio_reg(struct net_device *dev, int phy_id, int location)
{
unsigned short cmd;
int data;
int bitCounter;
cmd = (MDIO_START << 14) | (MDIO_READ << 12) | (phy_id << 7) |
(location << 2);
e100_send_mdio_cmd(cmd, 0);
data = 0;
for (bitCounter=15; bitCounter>=0 ; bitCounter--) {
data |= (e100_receive_mdio_bit() << bitCounter);
}
return data;
}
static void
e100_set_mdio_reg(struct net_device *dev, int phy_id, int location, int value)
{
int bitCounter;
unsigned short cmd;
cmd = (MDIO_START << 14) | (MDIO_WRITE << 12) | (phy_id << 7) |
(location << 2);
e100_send_mdio_cmd(cmd, 1);
for (bitCounter=15; bitCounter>=0 ; bitCounter--) {
e100_send_mdio_bit(GET_BIT(bitCounter, value));
}
}
static void
e100_send_mdio_cmd(unsigned short cmd, int write_cmd)
{
int bitCounter;
unsigned char data = 0x2;
for (bitCounter = 31; bitCounter>= 0; bitCounter--)
e100_send_mdio_bit(GET_BIT(bitCounter, MDIO_PREAMBLE));
for (bitCounter = 15; bitCounter >= 2; bitCounter--)
e100_send_mdio_bit(GET_BIT(bitCounter, cmd));
for (bitCounter = 1; bitCounter >= 0 ; bitCounter--)
if (write_cmd)
e100_send_mdio_bit(GET_BIT(bitCounter, data));
else
e100_receive_mdio_bit();
}
static void
e100_send_mdio_bit(unsigned char bit)
{
*R_NETWORK_MGM_CTRL =
IO_STATE(R_NETWORK_MGM_CTRL, mdoe, enable) |
IO_FIELD(R_NETWORK_MGM_CTRL, mdio, bit);
udelay(1);
*R_NETWORK_MGM_CTRL =
IO_STATE(R_NETWORK_MGM_CTRL, mdoe, enable) |
IO_MASK(R_NETWORK_MGM_CTRL, mdck) |
IO_FIELD(R_NETWORK_MGM_CTRL, mdio, bit);
udelay(1);
}
static unsigned char
e100_receive_mdio_bit(void)
{
unsigned char bit;
*R_NETWORK_MGM_CTRL = 0;
bit = IO_EXTRACT(R_NETWORK_STAT, mdio, *R_NETWORK_STAT);
udelay(1);
*R_NETWORK_MGM_CTRL = IO_MASK(R_NETWORK_MGM_CTRL, mdck);
udelay(1);
return bit;
}
static void
e100_reset_transceiver(struct net_device* dev)
{
struct net_local *np = netdev_priv(dev);
unsigned short cmd;
unsigned short data;
int bitCounter;
data = e100_get_mdio_reg(dev, np->mii_if.phy_id, MII_BMCR);
cmd = (MDIO_START << 14) | (MDIO_WRITE << 12) | (np->mii_if.phy_id << 7) | (MII_BMCR << 2);
e100_send_mdio_cmd(cmd, 1);
data |= 0x8000;
for (bitCounter = 15; bitCounter >= 0 ; bitCounter--) {
e100_send_mdio_bit(GET_BIT(bitCounter, data));
}
}
static void
e100_tx_timeout(struct net_device *dev)
{
struct net_local *np = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&np->lock, flags);
printk(KERN_WARNING "%s: transmit timed out, %s?\n", dev->name,
tx_done(dev) ? "IRQ problem" : "network cable problem");
dev->stats.tx_errors++;
RESET_DMA(NETWORK_TX_DMA_NBR);
WAIT_DMA(NETWORK_TX_DMA_NBR);
e100_reset_transceiver(dev);
while (myFirstTxDesc != myNextTxDesc) {
dev_kfree_skb(myFirstTxDesc->skb);
myFirstTxDesc->skb = 0;
myFirstTxDesc = phys_to_virt(myFirstTxDesc->descr.next);
}
*R_DMA_CH0_FIRST = 0;
*R_DMA_CH0_DESCR = virt_to_phys(myLastTxDesc);
netif_wake_queue(dev);
spin_unlock_irqrestore(&np->lock, flags);
}
static int
e100_send_packet(struct sk_buff *skb, struct net_device *dev)
{
struct net_local *np = netdev_priv(dev);
unsigned char *buf = skb->data;
unsigned long flags;
#ifdef ETHDEBUG
printk("send packet len %d\n", length);
#endif
spin_lock_irqsave(&np->lock, flags);
myNextTxDesc->skb = skb;
netif_trans_update(dev);
e100_hardware_send_packet(np, buf, skb->len);
myNextTxDesc = phys_to_virt(myNextTxDesc->descr.next);
if (myNextTxDesc == myFirstTxDesc) {
netif_stop_queue(dev);
}
spin_unlock_irqrestore(&np->lock, flags);
return NETDEV_TX_OK;
}
static irqreturn_t
e100rxtx_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
unsigned long irqbits;
irqbits = *R_IRQ_MASK2_RD;
if (irqbits & IO_STATE(R_IRQ_MASK2_RD, dma1_eop, active)) {
*R_DMA_CH1_CLR_INTR = IO_STATE(R_DMA_CH1_CLR_INTR, clr_eop, do);
while ((*R_DMA_CH1_FIRST != virt_to_phys(myNextRxDesc)) &&
(myNextRxDesc != myLastRxDesc)) {
e100_rx(dev);
dev->stats.rx_packets++;
*R_DMA_CH1_CMD = IO_STATE(R_DMA_CH1_CMD, cmd, restart);
*R_DMA_CH1_CLR_INTR =
IO_STATE(R_DMA_CH1_CLR_INTR, clr_eop, do) |
IO_STATE(R_DMA_CH1_CLR_INTR, clr_descr, do);
}
}
while (virt_to_phys(myFirstTxDesc) != *R_DMA_CH0_FIRST &&
(netif_queue_stopped(dev) || myFirstTxDesc != myNextTxDesc)) {
dev->stats.tx_bytes += myFirstTxDesc->skb->len;
dev->stats.tx_packets++;
dev_kfree_skb_irq(myFirstTxDesc->skb);
myFirstTxDesc->skb = 0;
myFirstTxDesc = phys_to_virt(myFirstTxDesc->descr.next);
netif_wake_queue(dev);
}
if (irqbits & IO_STATE(R_IRQ_MASK2_RD, dma0_eop, active)) {
*R_DMA_CH0_CLR_INTR = IO_STATE(R_DMA_CH0_CLR_INTR, clr_eop, do);
}
return IRQ_HANDLED;
}
static irqreturn_t
e100nw_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
unsigned long irqbits = *R_IRQ_MASK0_RD;
if (irqbits & IO_STATE(R_IRQ_MASK0_RD, underrun, active)) {
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, clr_error, clr);
*R_NETWORK_TR_CTRL = network_tr_ctrl_shadow;
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, clr_error, nop);
dev->stats.tx_errors++;
D(printk("ethernet receiver underrun!\n"));
}
if (irqbits & IO_STATE(R_IRQ_MASK0_RD, overrun, active)) {
update_rx_stats(&dev->stats);
D(printk("ethernet receiver overrun!\n"));
}
if (irqbits & IO_STATE(R_IRQ_MASK0_RD, excessive_col, active)) {
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, clr_error, clr);
*R_NETWORK_TR_CTRL = network_tr_ctrl_shadow;
SETS(network_tr_ctrl_shadow, R_NETWORK_TR_CTRL, clr_error, nop);
dev->stats.tx_errors++;
D(printk("ethernet excessive collisions!\n"));
}
return IRQ_HANDLED;
}
static void
e100_rx(struct net_device *dev)
{
struct sk_buff *skb;
int length = 0;
struct net_local *np = netdev_priv(dev);
unsigned char *skb_data_ptr;
#ifdef ETHDEBUG
int i;
#endif
etrax_eth_descr *prevRxDesc;
spin_lock(&np->led_lock);
if (!led_active && time_after(jiffies, led_next_time)) {
e100_set_network_leds(NETWORK_ACTIVITY);
led_next_time = jiffies + NET_FLASH_TIME;
led_active = 1;
mod_timer(&clear_led_timer, jiffies + HZ/10);
}
spin_unlock(&np->led_lock);
length = myNextRxDesc->descr.hw_len - 4;
dev->stats.rx_bytes += length;
#ifdef ETHDEBUG
printk("Got a packet of length %d:\n", length);
skb_data_ptr = (unsigned char *)phys_to_virt(myNextRxDesc->descr.buf);
for (i = 0; i < 8; i++) {
printk("%d: %.2x %.2x %.2x %.2x %.2x %.2x %.2x %.2x\n", i * 8,
skb_data_ptr[0],skb_data_ptr[1],skb_data_ptr[2],skb_data_ptr[3],
skb_data_ptr[4],skb_data_ptr[5],skb_data_ptr[6],skb_data_ptr[7]);
skb_data_ptr += 8;
}
#endif
if (length < RX_COPYBREAK) {
skb = dev_alloc_skb(length - ETHER_HEAD_LEN);
if (!skb) {
dev->stats.rx_errors++;
printk(KERN_NOTICE "%s: Memory squeeze, dropping packet.\n", dev->name);
goto update_nextrxdesc;
}
skb_put(skb, length - ETHER_HEAD_LEN);
skb_data_ptr = skb_push(skb, ETHER_HEAD_LEN);
#ifdef ETHDEBUG
printk("head = 0x%x, data = 0x%x, tail = 0x%x, end = 0x%x\n",
skb->head, skb->data, skb_tail_pointer(skb),
skb_end_pointer(skb));
printk("copying packet to 0x%x.\n", skb_data_ptr);
#endif
memcpy(skb_data_ptr, phys_to_virt(myNextRxDesc->descr.buf), length);
}
else {
int align;
struct sk_buff *new_skb = dev_alloc_skb(MAX_MEDIA_DATA_SIZE + 2 * L1_CACHE_BYTES);
if (!new_skb) {
dev->stats.rx_errors++;
printk(KERN_NOTICE "%s: Memory squeeze, dropping packet.\n", dev->name);
goto update_nextrxdesc;
}
skb = myNextRxDesc->skb;
align = (int)phys_to_virt(myNextRxDesc->descr.buf) - (int)skb->data;
skb_put(skb, length + align);
skb_pull(skb, align);
myNextRxDesc->skb = new_skb;
myNextRxDesc->descr.buf = L1_CACHE_ALIGN(virt_to_phys(myNextRxDesc->skb->data));
}
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
update_nextrxdesc:
myNextRxDesc->descr.status = 0;
prevRxDesc = myNextRxDesc;
myNextRxDesc = phys_to_virt(myNextRxDesc->descr.next);
rx_queue_len++;
if (rx_queue_len == RX_QUEUE_THRESHOLD) {
flush_etrax_cache();
prevRxDesc->descr.ctrl |= d_eol;
myLastRxDesc->descr.ctrl &= ~d_eol;
myLastRxDesc = prevRxDesc;
rx_queue_len = 0;
}
}
static int
e100_close(struct net_device *dev)
{
printk(KERN_INFO "Closing %s.\n", dev->name);
netif_stop_queue(dev);
*R_IRQ_MASK0_CLR =
IO_STATE(R_IRQ_MASK0_CLR, overrun, clr) |
IO_STATE(R_IRQ_MASK0_CLR, underrun, clr) |
IO_STATE(R_IRQ_MASK0_CLR, excessive_col, clr);
*R_IRQ_MASK2_CLR =
IO_STATE(R_IRQ_MASK2_CLR, dma0_descr, clr) |
IO_STATE(R_IRQ_MASK2_CLR, dma0_eop, clr) |
IO_STATE(R_IRQ_MASK2_CLR, dma1_descr, clr) |
IO_STATE(R_IRQ_MASK2_CLR, dma1_eop, clr);
RESET_DMA(NETWORK_TX_DMA_NBR);
RESET_DMA(NETWORK_RX_DMA_NBR);
free_irq(NETWORK_DMA_RX_IRQ_NBR, (void *)dev);
free_irq(NETWORK_DMA_TX_IRQ_NBR, (void *)dev);
free_irq(NETWORK_STATUS_IRQ_NBR, (void *)dev);
cris_free_dma(NETWORK_TX_DMA_NBR, cardname);
cris_free_dma(NETWORK_RX_DMA_NBR, cardname);
update_rx_stats(&dev->stats);
update_tx_stats(&dev->stats);
del_timer(&speed_timer);
del_timer(&duplex_timer);
return 0;
}
static int
e100_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct mii_ioctl_data *data = if_mii(ifr);
struct net_local *np = netdev_priv(dev);
int rc = 0;
int old_autoneg;
spin_lock(&np->lock);
switch (cmd) {
case SET_ETH_SPEED_10:
e100_set_speed(dev, 10);
break;
case SET_ETH_SPEED_100:
e100_set_speed(dev, 100);
break;
case SET_ETH_SPEED_AUTO:
e100_set_speed(dev, 0);
break;
case SET_ETH_DUPLEX_HALF:
e100_set_duplex(dev, half);
break;
case SET_ETH_DUPLEX_FULL:
e100_set_duplex(dev, full);
break;
case SET_ETH_DUPLEX_AUTO:
e100_set_duplex(dev, autoneg);
break;
case SET_ETH_AUTONEG:
old_autoneg = autoneg_normal;
autoneg_normal = *(int*)data;
if (autoneg_normal != old_autoneg)
e100_negotiate(dev);
break;
default:
rc = generic_mii_ioctl(&np->mii_if, if_mii(ifr),
cmd, NULL);
break;
}
spin_unlock(&np->lock);
return rc;
}
static int e100_get_link_ksettings(struct net_device *dev,
struct ethtool_link_ksettings *cmd)
{
struct net_local *np = netdev_priv(dev);
u32 supported;
spin_lock_irq(&np->lock);
mii_ethtool_get_link_ksettings(&np->mii_if, cmd);
spin_unlock_irq(&np->lock);
ethtool_convert_link_mode_to_legacy_u32(&supported,
cmd->link_modes.supported);
supported &= ~(SUPPORTED_1000baseT_Half | SUPPORTED_1000baseT_Full);
ethtool_convert_legacy_u32_to_link_mode(cmd->link_modes.supported,
supported);
return 0;
}
static int e100_set_link_ksettings(struct net_device *dev,
const struct ethtool_link_ksettings *ecmd)
{
if (ecmd->base.autoneg == AUTONEG_ENABLE) {
e100_set_duplex(dev, autoneg);
e100_set_speed(dev, 0);
} else {
e100_set_duplex(dev, ecmd->base.duplex == DUPLEX_HALF ?
half : full);
e100_set_speed(dev, ecmd->base.speed == SPEED_10 ? 10 : 100);
}
return 0;
}
static void e100_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "ETRAX 100LX", sizeof(info->driver));
strlcpy(info->version, "$Revision: 1.31 $", sizeof(info->version));
strlcpy(info->fw_version, "N/A", sizeof(info->fw_version));
strlcpy(info->bus_info, "N/A", sizeof(info->bus_info));
}
static int e100_nway_reset(struct net_device *dev)
{
if (current_duplex == autoneg && current_speed_selection == 0)
e100_negotiate(dev);
return 0;
}
static int
e100_set_config(struct net_device *dev, struct ifmap *map)
{
struct net_local *np = netdev_priv(dev);
spin_lock(&np->lock);
switch(map->port) {
case IF_PORT_UNKNOWN:
e100_set_speed(dev, 0);
e100_set_duplex(dev, autoneg);
break;
case IF_PORT_10BASET:
e100_set_speed(dev, 10);
e100_set_duplex(dev, autoneg);
break;
case IF_PORT_100BASET:
case IF_PORT_100BASETX:
e100_set_speed(dev, 100);
e100_set_duplex(dev, autoneg);
break;
case IF_PORT_100BASEFX:
case IF_PORT_10BASE2:
case IF_PORT_AUI:
spin_unlock(&np->lock);
return -EOPNOTSUPP;
default:
printk(KERN_ERR "%s: Invalid media selected", dev->name);
spin_unlock(&np->lock);
return -EINVAL;
}
spin_unlock(&np->lock);
return 0;
}
static void
update_rx_stats(struct net_device_stats *es)
{
unsigned long r = *R_REC_COUNTERS;
es->rx_fifo_errors += IO_EXTRACT(R_REC_COUNTERS, congestion, r);
es->rx_crc_errors += IO_EXTRACT(R_REC_COUNTERS, crc_error, r);
es->rx_frame_errors += IO_EXTRACT(R_REC_COUNTERS, alignment_error, r);
es->rx_length_errors += IO_EXTRACT(R_REC_COUNTERS, oversize, r);
}
static void
update_tx_stats(struct net_device_stats *es)
{
unsigned long r = *R_TR_COUNTERS;
es->collisions +=
IO_EXTRACT(R_TR_COUNTERS, single_col, r) +
IO_EXTRACT(R_TR_COUNTERS, multiple_col, r);
}
static struct net_device_stats *
e100_get_stats(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
update_rx_stats(&dev->stats);
update_tx_stats(&dev->stats);
spin_unlock_irqrestore(&lp->lock, flags);
return &dev->stats;
}
static void
set_multicast_list(struct net_device *dev)
{
struct net_local *lp = netdev_priv(dev);
int num_addr = netdev_mc_count(dev);
unsigned long int lo_bits;
unsigned long int hi_bits;
spin_lock(&lp->lock);
if (dev->flags & IFF_PROMISC) {
lo_bits = 0xfffffffful;
hi_bits = 0xfffffffful;
SETS(network_rec_config_shadow, R_NETWORK_REC_CONFIG, individual, receive);
*R_NETWORK_REC_CONFIG = network_rec_config_shadow;
} else if (dev->flags & IFF_ALLMULTI) {
lo_bits = 0xfffffffful;
hi_bits = 0xfffffffful;
SETS(network_rec_config_shadow, R_NETWORK_REC_CONFIG, individual, discard);
*R_NETWORK_REC_CONFIG = network_rec_config_shadow;
} else if (num_addr == 0) {
lo_bits = 0x00000000ul;
hi_bits = 0x00000000ul;
SETS(network_rec_config_shadow, R_NETWORK_REC_CONFIG, individual, discard);
*R_NETWORK_REC_CONFIG = network_rec_config_shadow;
} else {
char hash_ix;
struct netdev_hw_addr *ha;
char *baddr;
lo_bits = 0x00000000ul;
hi_bits = 0x00000000ul;
netdev_for_each_mc_addr(ha, dev) {
hash_ix = 0;
baddr = ha->addr;
hash_ix ^= (*baddr) & 0x3f;
hash_ix ^= ((*baddr) >> 6) & 0x03;
++baddr;
hash_ix ^= ((*baddr) << 2) & 0x03c;
hash_ix ^= ((*baddr) >> 4) & 0xf;
++baddr;
hash_ix ^= ((*baddr) << 4) & 0x30;
hash_ix ^= ((*baddr) >> 2) & 0x3f;
++baddr;
hash_ix ^= (*baddr) & 0x3f;
hash_ix ^= ((*baddr) >> 6) & 0x03;
++baddr;
hash_ix ^= ((*baddr) << 2) & 0x03c;
hash_ix ^= ((*baddr) >> 4) & 0xf;
++baddr;
hash_ix ^= ((*baddr) << 4) & 0x30;
hash_ix ^= ((*baddr) >> 2) & 0x3f;
hash_ix &= 0x3f;
if (hash_ix >= 32) {
hi_bits |= (1 << (hash_ix-32));
} else {
lo_bits |= (1 << hash_ix);
}
}
SETS(network_rec_config_shadow, R_NETWORK_REC_CONFIG, individual, discard);
*R_NETWORK_REC_CONFIG = network_rec_config_shadow;
}
*R_NETWORK_GA_0 = lo_bits;
*R_NETWORK_GA_1 = hi_bits;
spin_unlock(&lp->lock);
}
void
e100_hardware_send_packet(struct net_local *np, char *buf, int length)
{
D(printk("e100 send pack, buf 0x%x len %d\n", buf, length));
spin_lock(&np->led_lock);
if (!led_active && time_after(jiffies, led_next_time)) {
e100_set_network_leds(NETWORK_ACTIVITY);
led_next_time = jiffies + NET_FLASH_TIME;
led_active = 1;
mod_timer(&clear_led_timer, jiffies + HZ/10);
}
spin_unlock(&np->led_lock);
myNextTxDesc->descr.sw_len = length;
myNextTxDesc->descr.ctrl = d_eop | d_eol | d_wait;
myNextTxDesc->descr.buf = virt_to_phys(buf);
myLastTxDesc->descr.ctrl &= ~d_eol;
myLastTxDesc = myNextTxDesc;
*R_DMA_CH0_CMD = IO_STATE(R_DMA_CH0_CMD, cmd, restart);
}
static void
e100_clear_network_leds(unsigned long dummy)
{
struct net_device *dev = (struct net_device *)dummy;
struct net_local *np = netdev_priv(dev);
spin_lock(&np->led_lock);
if (led_active && time_after(jiffies, led_next_time)) {
e100_set_network_leds(NO_NETWORK_ACTIVITY);
led_next_time = jiffies + NET_FLASH_PAUSE;
led_active = 0;
}
spin_unlock(&np->led_lock);
}
static void
e100_set_network_leds(int active)
{
#if defined(CONFIG_ETRAX_NETWORK_LED_ON_WHEN_LINK)
int light_leds = (active == NO_NETWORK_ACTIVITY);
#elif defined(CONFIG_ETRAX_NETWORK_LED_ON_WHEN_ACTIVITY)
int light_leds = (active == NETWORK_ACTIVITY);
#else
#error "Define either CONFIG_ETRAX_NETWORK_LED_ON_WHEN_LINK or CONFIG_ETRAX_NETWORK_LED_ON_WHEN_ACTIVITY"
#endif
if (!current_speed) {
CRIS_LED_NETWORK_SET(CRIS_LED_OFF);
} else if (light_leds) {
if (current_speed == 10) {
CRIS_LED_NETWORK_SET(CRIS_LED_ORANGE);
} else {
CRIS_LED_NETWORK_SET(CRIS_LED_GREEN);
}
} else {
CRIS_LED_NETWORK_SET(CRIS_LED_OFF);
}
}
static void
e100_netpoll(struct net_device* netdev)
{
e100rxtx_interrupt(NETWORK_DMA_TX_IRQ_NBR, netdev);
}
static int __init
e100_boot_setup(char* str)
{
struct sockaddr sa = {0};
int i;
for (i = 0; i < ETH_ALEN; i++) {
unsigned int tmp;
if (sscanf(str + 3*i, "%2x", &tmp) != 1) {
printk(KERN_WARNING "Malformed station address");
return 0;
}
sa.sa_data[i] = (char)tmp;
}
default_mac = sa;
return 1;
}
