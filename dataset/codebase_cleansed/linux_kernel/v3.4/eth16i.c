static int __init do_eth16i_probe(struct net_device *dev)
{
int i;
int ioaddr;
int base_addr = dev->base_addr;
if(eth16i_debug > 4)
printk(KERN_DEBUG "Probing started for %s\n", cardname);
if(base_addr > 0x1ff)
return eth16i_probe1(dev, base_addr);
else if(base_addr != 0)
return -ENXIO;
for(i = 0; (ioaddr = eth16i_portlist[i]) ; i++)
if(eth16i_probe1(dev, ioaddr) == 0)
return 0;
for(i = 0; (ioaddr = eth32i_portlist[i]) ; i++)
if(eth16i_probe1(dev, ioaddr) == 0)
return 0;
return -ENODEV;
}
struct net_device * __init eth16i_probe(int unit)
{
struct net_device *dev = alloc_etherdev(sizeof(struct eth16i_local));
int err;
if (!dev)
return ERR_PTR(-ENOMEM);
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
err = do_eth16i_probe(dev);
if (err)
goto out;
return dev;
out:
free_netdev(dev);
return ERR_PTR(err);
}
static int __init eth16i_probe1(struct net_device *dev, int ioaddr)
{
struct eth16i_local *lp = netdev_priv(dev);
static unsigned version_printed;
int retval;
if (!request_region(ioaddr, ETH16I_IO_EXTENT, cardname))
return -EBUSY;
if(ioaddr < 0x1000) {
if(eth16i_portlist[(inb(ioaddr + JUMPERLESS_CONFIG) & 0x07)]
!= ioaddr) {
retval = -ENODEV;
goto out;
}
}
if(eth16i_check_signature(ioaddr) != 0) {
retval = -ENODEV;
goto out;
}
eth16i_select_regbank(TRANSCEIVER_MODE_RB, ioaddr);
outb(0x00, ioaddr + TRANSCEIVER_MODE_REG);
outb(0x00, ioaddr + RESET);
BITSET(ioaddr + CONFIG_REG_0, BIT(7));
if( (eth16i_debug & version_printed++) == 0)
printk(KERN_INFO "%s", version);
dev->base_addr = ioaddr;
dev->irq = eth16i_get_irq(ioaddr);
if ((retval = request_irq(dev->irq, (void *)&eth16i_interrupt, 0, cardname, dev))) {
printk(KERN_WARNING "%s at %#3x, but is unusable due to conflicting IRQ %d.\n",
cardname, ioaddr, dev->irq);
goto out;
}
printk(KERN_INFO "%s: %s at %#3x, IRQ %d, ",
dev->name, cardname, ioaddr, dev->irq);
eth16i_select_regbank(TRANSCEIVER_MODE_RB, ioaddr);
outb(0x38, ioaddr + TRANSCEIVER_MODE_REG);
eth16i_initialize(dev, 1);
BITCLR(ioaddr + CONFIG_REG_1, POWERUP);
dev->netdev_ops = &eth16i_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
spin_lock_init(&lp->lock);
retval = register_netdev(dev);
if (retval)
goto out1;
return 0;
out1:
free_irq(dev->irq, dev);
out:
release_region(ioaddr, ETH16I_IO_EXTENT);
return retval;
}
static void eth16i_initialize(struct net_device *dev, int boot)
{
int ioaddr = dev->base_addr;
int i, node_w = 0;
unsigned char node_byte = 0;
eth16i_select_regbank(NODE_ID_RB, ioaddr);
for(i = 0 ; i < 3 ; i++) {
unsigned short node_val = eth16i_read_eeprom(ioaddr, E_NODEID_0 + i);
((unsigned short *)dev->dev_addr)[i] = ntohs(node_val);
}
for(i = 0; i < 6; i++) {
outb( ((unsigned char *)dev->dev_addr)[i], ioaddr + NODE_ID_0 + i);
if(boot) {
printk("%02x", inb(ioaddr + NODE_ID_0 + i));
if(i != 5)
printk(":");
}
}
eth16i_select_regbank(HASH_TABLE_RB, ioaddr);
for(i = 0; i < 8; i++)
outb(0x00, ioaddr + HASH_TABLE_0 + i);
eth16i_select_regbank(2, ioaddr);
node_byte = 0;
node_w = eth16i_read_eeprom(ioaddr, E_PRODUCT_CFG);
if( (node_w & 0xFF00) == 0x0800)
node_byte |= BUFFER_WIDTH_8;
node_byte |= SRAM_BS1;
if( (node_w & 0x00FF) == 64)
node_byte |= SRAM_BS0;
node_byte |= DLC_EN | SRAM_CYCLE_TIME_100NS | (ETH16I_TX_BUF_SIZE << 2);
outb(node_byte, ioaddr + CONFIG_REG_0);
outb(HALT_ON_16, ioaddr + COL_16_REG);
#ifdef MODULE
#else
dev->if_port = (dev->mem_start < E_PORT_FROM_EPROM) ?
dev->mem_start : E_PORT_FROM_EPROM;
#endif
if(boot) {
static const char * const porttype[] = {
"BNC", "DIX", "TP", "AUTO", "FROM_EPROM"
};
switch(dev->if_port)
{
case E_PORT_FROM_EPROM:
dev->if_port = eth16i_read_eeprom(ioaddr, E_PORT_SELECT);
break;
case E_PORT_AUTO:
dev->if_port = eth16i_probe_port(ioaddr);
break;
case E_PORT_BNC:
case E_PORT_TP:
case E_PORT_DIX:
break;
}
printk(" %s interface.\n", porttype[dev->if_port]);
eth16i_set_port(ioaddr, dev->if_port);
}
outb(MODE_2, ioaddr + RECEIVE_MODE_REG);
}
static int eth16i_probe_port(int ioaddr)
{
int i;
int retcode;
unsigned char dummy_packet[64];
outb(0xc0 | POWERUP, ioaddr + CONFIG_REG_1);
BITSET(ioaddr + CONFIG_REG_0, DLC_EN);
eth16i_select_regbank(NODE_ID_RB, ioaddr);
for(i = 0; i < 6; i++) {
dummy_packet[i] = inb(ioaddr + NODE_ID_0 + i);
dummy_packet[i+6] = inb(ioaddr + NODE_ID_0 + i);
}
dummy_packet[12] = 0x00;
dummy_packet[13] = 0x04;
memset(dummy_packet + 14, 0, sizeof(dummy_packet) - 14);
eth16i_select_regbank(2, ioaddr);
for(i = 0; i < 3; i++) {
BITSET(ioaddr + CONFIG_REG_0, DLC_EN);
BITCLR(ioaddr + CONFIG_REG_0, DLC_EN);
eth16i_set_port(ioaddr, i);
if(eth16i_debug > 1)
printk(KERN_DEBUG "Set port number %d\n", i);
retcode = eth16i_send_probe_packet(ioaddr, dummy_packet, 64);
if(retcode == 0) {
retcode = eth16i_receive_probe_packet(ioaddr);
if(retcode != -1) {
if(eth16i_debug > 1)
printk(KERN_DEBUG "Eth16i interface port found at %d\n", i);
return i;
}
}
else {
if(eth16i_debug > 1)
printk(KERN_DEBUG "TRANSMIT_DONE timeout when probing interface port\n");
}
}
if( eth16i_debug > 1)
printk(KERN_DEBUG "Using default port\n");
return E_PORT_BNC;
}
static void eth16i_set_port(int ioaddr, int porttype)
{
unsigned short temp = 0;
eth16i_select_regbank(TRANSCEIVER_MODE_RB, ioaddr);
outb(LOOPBACK_CONTROL, ioaddr + TRANSMIT_MODE_REG);
temp |= DIS_AUTO_PORT_SEL;
switch(porttype) {
case E_PORT_BNC :
temp |= AUI_SELECT;
break;
case E_PORT_TP :
break;
case E_PORT_DIX :
temp |= AUI_SELECT;
BITSET(ioaddr + TRANSMIT_MODE_REG, CONTROL_OUTPUT);
break;
}
outb(temp, ioaddr + TRANSCEIVER_MODE_REG);
if(eth16i_debug > 1) {
printk(KERN_DEBUG "TRANSMIT_MODE_REG = %x\n", inb(ioaddr + TRANSMIT_MODE_REG));
printk(KERN_DEBUG "TRANSCEIVER_MODE_REG = %x\n",
inb(ioaddr+TRANSCEIVER_MODE_REG));
}
}
static int eth16i_send_probe_packet(int ioaddr, unsigned char *b, int l)
{
unsigned long starttime;
outb(0xff, ioaddr + TX_STATUS_REG);
outw(l, ioaddr + DATAPORT);
outsw(ioaddr + DATAPORT, (unsigned short *)b, (l + 1) >> 1);
starttime = jiffies;
outb(TX_START | 1, ioaddr + TRANSMIT_START_REG);
while( (inb(ioaddr + TX_STATUS_REG) & 0x80) == 0) {
if( time_after(jiffies, starttime + TX_TIMEOUT)) {
return -1;
}
}
return 0;
}
static int eth16i_receive_probe_packet(int ioaddr)
{
unsigned long starttime;
starttime = jiffies;
while((inb(ioaddr + TX_STATUS_REG) & 0x20) == 0) {
if( time_after(jiffies, starttime + TX_TIMEOUT)) {
if(eth16i_debug > 1)
printk(KERN_DEBUG "Timeout occurred waiting transmit packet received\n");
starttime = jiffies;
while((inb(ioaddr + RX_STATUS_REG) & 0x80) == 0) {
if( time_after(jiffies, starttime + TX_TIMEOUT)) {
if(eth16i_debug > 1)
printk(KERN_DEBUG "Timeout occurred waiting receive packet\n");
return -1;
}
}
if(eth16i_debug > 1)
printk(KERN_DEBUG "RECEIVE_PACKET\n");
return 0;
}
}
if(eth16i_debug > 1) {
printk(KERN_DEBUG "TRANSMIT_PACKET_RECEIVED %x\n", inb(ioaddr + TX_STATUS_REG));
printk(KERN_DEBUG "RX_STATUS_REG = %x\n", inb(ioaddr + RX_STATUS_REG));
}
return 0;
}
static int __init eth16i_get_irq(int ioaddr)
{
unsigned char cbyte;
if( ioaddr < 0x1000) {
cbyte = inb(ioaddr + JUMPERLESS_CONFIG);
return eth16i_irqmap[((cbyte & 0xC0) >> 6)];
} else {
unsigned short index = 0;
cbyte = inb(ioaddr + EISA_IRQ_REG);
while( (cbyte & 0x01) == 0) {
cbyte = cbyte >> 1;
index++;
}
return eth32i_irqmap[index];
}
}
static int __init eth16i_check_signature(int ioaddr)
{
int i;
unsigned char creg[4] = { 0 };
for(i = 0; i < 4 ; i++) {
creg[i] = inb(ioaddr + TRANSMIT_MODE_REG + i);
if(eth16i_debug > 1)
printk("eth16i: read signature byte %x at %x\n",
creg[i],
ioaddr + TRANSMIT_MODE_REG + i);
}
creg[0] &= 0x0F;
creg[2] &= 0x7F;
#if 0
if( ! ((creg[0] == 0x06) && (creg[1] == 0x41)) ) {
if(creg[1] != 0x42)
return -1;
}
#endif
if( !((creg[2] == 0x36) && (creg[3] == 0xE0)) ) {
creg[2] &= 0x40;
creg[3] &= 0x03;
if( !((creg[2] == 0x40) && (creg[3] == 0x00)) )
return -1;
}
if(eth16i_read_eeprom(ioaddr, E_NODEID_0) != 0)
return -1;
if((eth16i_read_eeprom(ioaddr, E_NODEID_1) & 0xFF00) != 0x4B00)
return -1;
return 0;
}
static int eth16i_read_eeprom(int ioaddr, int offset)
{
int data = 0;
eth16i_eeprom_cmd(ioaddr, EEPROM_READ | offset);
outb(CS_1, ioaddr + EEPROM_CTRL_REG);
data = eth16i_read_eeprom_word(ioaddr);
outb(CS_0 | SK_0, ioaddr + EEPROM_CTRL_REG);
return data;
}
static int eth16i_read_eeprom_word(int ioaddr)
{
int i;
int data = 0;
for(i = 16; i > 0; i--) {
outb(CS_1 | SK_0, ioaddr + EEPROM_CTRL_REG);
eeprom_slow_io();
outb(CS_1 | SK_1, ioaddr + EEPROM_CTRL_REG);
eeprom_slow_io();
data = (data << 1) |
((inb(ioaddr + EEPROM_DATA_REG) & DI_1) ? 1 : 0);
eeprom_slow_io();
}
return data;
}
static void eth16i_eeprom_cmd(int ioaddr, unsigned char command)
{
int i;
outb(CS_0 | SK_0, ioaddr + EEPROM_CTRL_REG);
outb(DI_0, ioaddr + EEPROM_DATA_REG);
outb(CS_1 | SK_0, ioaddr + EEPROM_CTRL_REG);
outb(DI_1, ioaddr + EEPROM_DATA_REG);
outb(CS_1 | SK_1, ioaddr + EEPROM_CTRL_REG);
for(i = 7; i >= 0; i--) {
short cmd = ( (command & (1 << i)) ? DI_1 : DI_0 );
outb(cmd, ioaddr + EEPROM_DATA_REG);
outb(CS_1 | SK_0, ioaddr + EEPROM_CTRL_REG);
eeprom_slow_io();
outb(CS_1 | SK_1, ioaddr + EEPROM_CTRL_REG);
eeprom_slow_io();
}
}
static int eth16i_open(struct net_device *dev)
{
struct eth16i_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
outb(0xc0 | POWERUP, ioaddr + CONFIG_REG_1);
eth16i_initialize(dev, 0);
lp->tx_buf_size = eth16i_tx_buf_map[ETH16I_TX_BUF_SIZE & 0x03];
if(eth16i_debug > 0)
printk(KERN_DEBUG "%s: transmit buffer size %d\n",
dev->name, lp->tx_buf_size);
BITCLR(ioaddr + CONFIG_REG_0, DLC_EN);
eth16i_select_regbank(2, ioaddr);
lp->open_time = jiffies;
lp->tx_started = 0;
lp->tx_queue = 0;
lp->tx_queue_len = 0;
outw(ETH16I_INTR_ON, ioaddr + TX_INTR_REG);
netif_start_queue(dev);
return 0;
}
static int eth16i_close(struct net_device *dev)
{
struct eth16i_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
eth16i_reset(dev);
outw(ETH16I_INTR_OFF, ioaddr + TX_INTR_REG);
netif_stop_queue(dev);
lp->open_time = 0;
BITSET(ioaddr + CONFIG_REG_0, DLC_EN);
outb(0x00, ioaddr + CONFIG_REG_1);
return 0;
}
static void eth16i_timeout(struct net_device *dev)
{
struct eth16i_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
outw(ETH16I_INTR_OFF, ioaddr + TX_INTR_REG);
printk(KERN_WARNING "%s: transmit timed out with status %04x, %s ?\n",
dev->name,
inw(ioaddr + TX_STATUS_REG), (inb(ioaddr + TX_STATUS_REG) & TX_DONE) ?
"IRQ conflict" : "network cable problem");
dev->trans_start = jiffies;
if(eth16i_debug > 0) {
printk(KERN_DEBUG "%s: timeout: %02x %02x %02x %02x %02x %02x %02x %02x.\n",
dev->name, inb(ioaddr + 0),
inb(ioaddr + 1), inb(ioaddr + 2),
inb(ioaddr + 3), inb(ioaddr + 4),
inb(ioaddr + 5),
inb(ioaddr + 6), inb(ioaddr + 7));
printk(KERN_DEBUG "%s: transmit start reg: %02x. collision reg %02x\n",
dev->name, inb(ioaddr + TRANSMIT_START_REG),
inb(ioaddr + COL_16_REG));
printk(KERN_DEBUG "lp->tx_queue = %d\n", lp->tx_queue);
printk(KERN_DEBUG "lp->tx_queue_len = %d\n", lp->tx_queue_len);
printk(KERN_DEBUG "lp->tx_started = %d\n", lp->tx_started);
}
dev->stats.tx_errors++;
eth16i_reset(dev);
dev->trans_start = jiffies;
outw(ETH16I_INTR_ON, ioaddr + TX_INTR_REG);
netif_wake_queue(dev);
}
static netdev_tx_t eth16i_tx(struct sk_buff *skb, struct net_device *dev)
{
struct eth16i_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
int status = 0;
ushort length = skb->len;
unsigned char *buf;
unsigned long flags;
if (length < ETH_ZLEN) {
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
length = ETH_ZLEN;
}
buf = skb->data;
netif_stop_queue(dev);
outw(ETH16I_INTR_OFF, ioaddr + TX_INTR_REG);
spin_lock_irqsave(&lp->lock, flags);
if( (length + 2) > (lp->tx_buf_size - lp->tx_queue_len)) {
if(eth16i_debug > 0)
printk(KERN_WARNING "%s: Transmit buffer full.\n", dev->name);
}
else {
outw(length, ioaddr + DATAPORT);
if( ioaddr < 0x1000 )
outsw(ioaddr + DATAPORT, buf, (length + 1) >> 1);
else {
unsigned char frag = length % 4;
outsl(ioaddr + DATAPORT, buf, length >> 2);
if( frag != 0 ) {
outsw(ioaddr + DATAPORT, (buf + (length & 0xFFFC)), 1);
if( frag == 3 )
outsw(ioaddr + DATAPORT,
(buf + (length & 0xFFFC) + 2), 1);
}
}
lp->tx_buffered_packets++;
lp->tx_buffered_bytes = length;
lp->tx_queue++;
lp->tx_queue_len += length + 2;
}
lp->tx_buf_busy = 0;
if(lp->tx_started == 0) {
outb(TX_START | lp->tx_queue, ioaddr + TRANSMIT_START_REG);
lp->tx_queue = 0;
lp->tx_queue_len = 0;
lp->tx_started = 1;
netif_wake_queue(dev);
}
else if(lp->tx_queue_len < lp->tx_buf_size - (ETH_FRAME_LEN + 2)) {
netif_wake_queue(dev);
}
spin_unlock_irqrestore(&lp->lock, flags);
outw(ETH16I_INTR_ON, ioaddr + TX_INTR_REG);
status = 0;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void eth16i_rx(struct net_device *dev)
{
int ioaddr = dev->base_addr;
int boguscount = MAX_RX_LOOP;
while( (inb(ioaddr + RECEIVE_MODE_REG) & RX_BUFFER_EMPTY) == 0) {
ushort status = inw(ioaddr + DATAPORT);
ushort pkt_len = inw(ioaddr + DATAPORT);
if(eth16i_debug > 4)
printk(KERN_DEBUG "%s: Receiving packet mode %02x status %04x.\n",
dev->name,
inb(ioaddr + RECEIVE_MODE_REG), status);
if( !(status & PKT_GOOD) ) {
dev->stats.rx_errors++;
if( (pkt_len < ETH_ZLEN) || (pkt_len > ETH_FRAME_LEN) ) {
dev->stats.rx_length_errors++;
eth16i_reset(dev);
return;
}
else {
eth16i_skip_packet(dev);
dev->stats.rx_dropped++;
}
}
else {
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, pkt_len + 3);
if( skb == NULL ) {
printk(KERN_WARNING "%s: Could'n allocate memory for packet (len %d)\n",
dev->name, pkt_len);
eth16i_skip_packet(dev);
dev->stats.rx_dropped++;
break;
}
skb_reserve(skb,2);
if(ioaddr < 0x1000)
insw(ioaddr + DATAPORT, skb_put(skb, pkt_len),
(pkt_len + 1) >> 1);
else {
unsigned char *buf = skb_put(skb, pkt_len);
unsigned char frag = pkt_len % 4;
insl(ioaddr + DATAPORT, buf, pkt_len >> 2);
if(frag != 0) {
unsigned short rest[2];
rest[0] = inw( ioaddr + DATAPORT );
if(frag == 3)
rest[1] = inw( ioaddr + DATAPORT );
memcpy(buf + (pkt_len & 0xfffc), (char *)rest, frag);
}
}
skb->protocol=eth_type_trans(skb, dev);
if( eth16i_debug > 5 ) {
int i;
printk(KERN_DEBUG "%s: Received packet of length %d.\n",
dev->name, pkt_len);
for(i = 0; i < 14; i++)
printk(KERN_DEBUG " %02x", skb->data[i]);
printk(KERN_DEBUG ".\n");
}
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
}
if(--boguscount <= 0)
break;
}
}
static irqreturn_t eth16i_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct eth16i_local *lp;
int ioaddr = 0, status;
int handled = 0;
ioaddr = dev->base_addr;
lp = netdev_priv(dev);
outw(ETH16I_INTR_OFF, ioaddr + TX_INTR_REG);
spin_lock(&lp->lock);
status = inw(ioaddr + TX_STATUS_REG);
outw(status, ioaddr + TX_STATUS_REG);
if (status)
handled = 1;
if(eth16i_debug > 3)
printk(KERN_DEBUG "%s: Interrupt with status %04x.\n", dev->name, status);
if( status & 0x7f00 ) {
dev->stats.rx_errors++;
if(status & (BUS_RD_ERR << 8) )
printk(KERN_WARNING "%s: Bus read error.\n",dev->name);
if(status & (SHORT_PKT_ERR << 8) ) dev->stats.rx_length_errors++;
if(status & (ALIGN_ERR << 8) ) dev->stats.rx_frame_errors++;
if(status & (CRC_ERR << 8) ) dev->stats.rx_crc_errors++;
if(status & (RX_BUF_OVERFLOW << 8) ) dev->stats.rx_over_errors++;
}
if( status & 0x001a) {
dev->stats.tx_errors++;
if(status & CR_LOST) dev->stats.tx_carrier_errors++;
if(status & TX_JABBER_ERR) dev->stats.tx_window_errors++;
#if 0
if(status & COLLISION) {
dev->stats.collisions +=
((inb(ioaddr+TRANSMIT_MODE_REG) & 0xF0) >> 4);
}
#endif
if(status & COLLISIONS_16) {
if(lp->col_16 < MAX_COL_16) {
lp->col_16++;
dev->stats.collisions++;
outb(0x02, ioaddr + COL_16_REG);
}
else {
printk(KERN_WARNING "%s: bailing out due to many consecutive 16-in-a-row collisions. Network cable problem?\n", dev->name);
}
}
}
if( status & 0x00ff ) {
if(status & TX_DONE) {
dev->stats.tx_packets = lp->tx_buffered_packets;
dev->stats.tx_bytes += lp->tx_buffered_bytes;
lp->col_16 = 0;
if(lp->tx_queue) {
outb(TX_START | lp->tx_queue, ioaddr + TRANSMIT_START_REG);
lp->tx_queue = 0;
lp->tx_queue_len = 0;
lp->tx_started = 1;
}
else {
lp->tx_started = 0;
}
netif_wake_queue(dev);
}
}
if( ( status & 0x8000 ) ||
( (inb(ioaddr + RECEIVE_MODE_REG) & RX_BUFFER_EMPTY) == 0) ) {
eth16i_rx(dev);
}
outw(ETH16I_INTR_ON, ioaddr + TX_INTR_REG);
if(lp->tx_queue_len < lp->tx_buf_size - (ETH_FRAME_LEN + 2)) {
netif_wake_queue(dev);
}
spin_unlock(&lp->lock);
return IRQ_RETVAL(handled);
}
static void eth16i_skip_packet(struct net_device *dev)
{
int ioaddr = dev->base_addr;
inw(ioaddr + DATAPORT);
inw(ioaddr + DATAPORT);
inw(ioaddr + DATAPORT);
outb(SKIP_RX_PACKET, ioaddr + FILTER_SELF_RX_REG);
while( inb( ioaddr + FILTER_SELF_RX_REG ) != 0);
}
static void eth16i_reset(struct net_device *dev)
{
struct eth16i_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
if(eth16i_debug > 1)
printk(KERN_DEBUG "%s: Resetting device.\n", dev->name);
BITSET(ioaddr + CONFIG_REG_0, DLC_EN);
outw(0xffff, ioaddr + TX_STATUS_REG);
eth16i_select_regbank(2, ioaddr);
lp->tx_started = 0;
lp->tx_buf_busy = 0;
lp->tx_queue = 0;
lp->tx_queue_len = 0;
BITCLR(ioaddr + CONFIG_REG_0, DLC_EN);
}
static void eth16i_multicast(struct net_device *dev)
{
int ioaddr = dev->base_addr;
if (!netdev_mc_empty(dev) || dev->flags&(IFF_ALLMULTI|IFF_PROMISC))
{
outb(3, ioaddr + RECEIVE_MODE_REG);
} else {
outb(2, ioaddr + RECEIVE_MODE_REG);
}
}
static void eth16i_select_regbank(unsigned char banknbr, int ioaddr)
{
unsigned char data;
data = inb(ioaddr + CONFIG_REG_1);
outb( ((data & 0xF3) | ( (banknbr & 0x03) << 2)), ioaddr + CONFIG_REG_1);
}
static ushort eth16i_parse_mediatype(const char* s)
{
if(!s)
return E_PORT_FROM_EPROM;
if (!strncmp(s, "bnc", 3))
return E_PORT_BNC;
else if (!strncmp(s, "tp", 2))
return E_PORT_TP;
else if (!strncmp(s, "dix", 3))
return E_PORT_DIX;
else if (!strncmp(s, "auto", 4))
return E_PORT_AUTO;
else
return E_PORT_FROM_EPROM;
}
int __init init_module(void)
{
int this_dev, found = 0;
struct net_device *dev;
for (this_dev = 0; this_dev < MAX_ETH16I_CARDS; this_dev++) {
dev = alloc_etherdev(sizeof(struct eth16i_local));
if (!dev)
break;
dev->base_addr = io[this_dev];
if(debug != -1)
eth16i_debug = debug;
if(eth16i_debug > 1)
printk(KERN_NOTICE "eth16i(%d): interface type %s\n", this_dev, mediatype[this_dev] ? mediatype[this_dev] : "none" );
dev->if_port = eth16i_parse_mediatype(mediatype[this_dev]);
if(io[this_dev] == 0) {
if (this_dev != 0) {
free_netdev(dev);
break;
}
printk(KERN_NOTICE "eth16i.c: Presently autoprobing (not recommended) for a single card.\n");
}
if (do_eth16i_probe(dev) == 0) {
dev_eth16i[found++] = dev;
continue;
}
printk(KERN_WARNING "eth16i.c No Eth16i card found (i/o = 0x%x).\n",
io[this_dev]);
free_netdev(dev);
break;
}
if (found)
return 0;
return -ENXIO;
}
void __exit cleanup_module(void)
{
int this_dev;
for(this_dev = 0; this_dev < MAX_ETH16I_CARDS; this_dev++) {
struct net_device *dev = dev_eth16i[this_dev];
if (netdev_priv(dev)) {
unregister_netdev(dev);
free_irq(dev->irq, dev);
release_region(dev->base_addr, ETH16I_IO_EXTENT);
free_netdev(dev);
}
}
}
