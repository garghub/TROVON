static int __init do_eepro_probe(struct net_device *dev)
{
int i;
int base_addr = dev->base_addr;
int irq = dev->irq;
#ifdef PnPWakeup
#define WakeupPort 0x279
#define WakeupSeq {0x6A, 0xB5, 0xDA, 0xED, 0xF6, 0xFB, 0x7D, 0xBE,\
0xDF, 0x6F, 0x37, 0x1B, 0x0D, 0x86, 0xC3, 0x61,\
0xB0, 0x58, 0x2C, 0x16, 0x8B, 0x45, 0xA2, 0xD1,\
0xE8, 0x74, 0x3A, 0x9D, 0xCE, 0xE7, 0x73, 0x43}
{
unsigned short int WS[32]=WakeupSeq;
if (request_region(WakeupPort, 2, "eepro wakeup")) {
if (net_debug>5)
printk(KERN_DEBUG "Waking UP\n");
outb_p(0,WakeupPort);
outb_p(0,WakeupPort);
for (i=0; i<32; i++) {
outb_p(WS[i],WakeupPort);
if (net_debug>5) printk(KERN_DEBUG ": %#x ",WS[i]);
}
release_region(WakeupPort, 2);
} else
printk(KERN_WARNING "PnP wakeup region busy!\n");
}
#endif
if (base_addr > 0x1ff)
return eepro_probe1(dev, 0);
else if (base_addr != 0)
return -ENXIO;
for (i = 0; eepro_portlist[i]; i++) {
dev->base_addr = eepro_portlist[i];
dev->irq = irq;
if (eepro_probe1(dev, 1) == 0)
return 0;
}
return -ENODEV;
}
struct net_device * __init eepro_probe(int unit)
{
struct net_device *dev = alloc_etherdev(sizeof(struct eepro_local));
int err;
if (!dev)
return ERR_PTR(-ENODEV);
sprintf(dev->name, "eth%d", unit);
netdev_boot_setup_check(dev);
err = do_eepro_probe(dev);
if (err)
goto out;
return dev;
out:
free_netdev(dev);
return ERR_PTR(err);
}
static void __init printEEPROMInfo(struct net_device *dev)
{
struct eepro_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
unsigned short Word;
int i,j;
j = ee_Checksum;
for (i = 0; i < 8; i++)
j += lp->word[i];
for ( ; i < ee_SIZE; i++)
j += read_eeprom(ioaddr, i, dev);
printk(KERN_DEBUG "Checksum: %#x\n",j&0xffff);
Word = lp->word[0];
printk(KERN_DEBUG "Word0:\n");
printk(KERN_DEBUG " Plug 'n Pray: %d\n",GetBit(Word,ee_PnP));
printk(KERN_DEBUG " Buswidth: %d\n",(GetBit(Word,ee_BusWidth)+1)*8 );
printk(KERN_DEBUG " AutoNegotiation: %d\n",GetBit(Word,ee_AutoNeg));
printk(KERN_DEBUG " IO Address: %#x\n", (Word>>ee_IO0)<<4);
if (net_debug>4) {
Word = lp->word[1];
printk(KERN_DEBUG "Word1:\n");
printk(KERN_DEBUG " INT: %d\n", Word & ee_IntMask);
printk(KERN_DEBUG " LI: %d\n", GetBit(Word,ee_LI));
printk(KERN_DEBUG " PC: %d\n", GetBit(Word,ee_PC));
printk(KERN_DEBUG " TPE/AUI: %d\n", GetBit(Word,ee_TPE_AUI));
printk(KERN_DEBUG " Jabber: %d\n", GetBit(Word,ee_Jabber));
printk(KERN_DEBUG " AutoPort: %d\n", !GetBit(Word,ee_AutoPort));
printk(KERN_DEBUG " Duplex: %d\n", GetBit(Word,ee_Duplex));
}
Word = lp->word[5];
printk(KERN_DEBUG "Word5:\n");
printk(KERN_DEBUG " BNC: %d\n",GetBit(Word,ee_BNC_TPE));
printk(KERN_DEBUG " NumConnectors: %d\n",GetBit(Word,ee_NumConn));
printk(KERN_DEBUG " Has ");
if (GetBit(Word,ee_PortTPE)) printk(KERN_DEBUG "TPE ");
if (GetBit(Word,ee_PortBNC)) printk(KERN_DEBUG "BNC ");
if (GetBit(Word,ee_PortAUI)) printk(KERN_DEBUG "AUI ");
printk(KERN_DEBUG "port(s)\n");
Word = lp->word[6];
printk(KERN_DEBUG "Word6:\n");
printk(KERN_DEBUG " Stepping: %d\n",Word & ee_StepMask);
printk(KERN_DEBUG " BoardID: %d\n",Word>>ee_BoardID);
Word = lp->word[7];
printk(KERN_DEBUG "Word7:\n");
printk(KERN_DEBUG " INT to IRQ:\n");
for (i=0, j=0; i<15; i++)
if (GetBit(Word,i)) printk(KERN_DEBUG " INT%d -> IRQ %d;",j++,i);
printk(KERN_DEBUG "\n");
}
static void eepro_recalc (struct net_device *dev)
{
struct eepro_local * lp;
lp = netdev_priv(dev);
lp->xmt_ram = RAM_SIZE - lp->rcv_ram;
if (lp->eepro == LAN595FX_10ISA) {
lp->xmt_lower_limit = XMT_START_10;
lp->xmt_upper_limit = (lp->xmt_ram - 2);
lp->rcv_lower_limit = lp->xmt_ram;
lp->rcv_upper_limit = (RAM_SIZE - 2);
}
else {
lp->rcv_lower_limit = RCV_START_PRO;
lp->rcv_upper_limit = (lp->rcv_ram - 2);
lp->xmt_lower_limit = lp->rcv_ram;
lp->xmt_upper_limit = (RAM_SIZE - 2);
}
}
static void __init eepro_print_info (struct net_device *dev)
{
struct eepro_local * lp = netdev_priv(dev);
int i;
const char * ifmap[] = {"AUI", "10Base2", "10BaseT"};
i = inb(dev->base_addr + ID_REG);
printk(KERN_DEBUG " id: %#x ",i);
printk(" io: %#x ", (unsigned)dev->base_addr);
switch (lp->eepro) {
case LAN595FX_10ISA:
printk("%s: Intel EtherExpress 10 ISA\n at %#x,",
dev->name, (unsigned)dev->base_addr);
break;
case LAN595FX:
printk("%s: Intel EtherExpress Pro/10+ ISA\n at %#x,",
dev->name, (unsigned)dev->base_addr);
break;
case LAN595TX:
printk("%s: Intel EtherExpress Pro/10 ISA at %#x,",
dev->name, (unsigned)dev->base_addr);
break;
case LAN595:
printk("%s: Intel 82595-based lan card at %#x,",
dev->name, (unsigned)dev->base_addr);
break;
}
printk(" %pM", dev->dev_addr);
if (net_debug > 3)
printk(KERN_DEBUG ", %dK RCV buffer",
(int)(lp->rcv_ram)/1024);
if (dev->irq > 2)
printk(", IRQ %d, %s.\n", dev->irq, ifmap[dev->if_port]);
else
printk(", %s.\n", ifmap[dev->if_port]);
if (net_debug > 3) {
i = lp->word[5];
if (i & 0x2000)
printk(KERN_DEBUG "%s: Concurrent Processing is "
"enabled but not used!\n", dev->name);
}
if (net_debug>3)
printEEPROMInfo(dev);
}
static int __init eepro_probe1(struct net_device *dev, int autoprobe)
{
unsigned short station_addr[3], id, counter;
int i;
struct eepro_local *lp;
int ioaddr = dev->base_addr;
int err;
if (!request_region(ioaddr, EEPRO_IO_EXTENT, DRV_NAME)) {
if (!autoprobe)
printk(KERN_WARNING "EEPRO: io-port 0x%04x in use\n",
ioaddr);
return -EBUSY;
}
id = inb(ioaddr + ID_REG);
if ((id & ID_REG_MASK) != ID_REG_SIG)
goto exit;
counter = id & R_ROBIN_BITS;
if ((inb(ioaddr + ID_REG) & R_ROBIN_BITS) != (counter + 0x40))
goto exit;
lp = netdev_priv(dev);
memset(lp, 0, sizeof(struct eepro_local));
lp->xmt_bar = XMT_BAR_PRO;
lp->xmt_lower_limit_reg = XMT_LOWER_LIMIT_REG_PRO;
lp->xmt_upper_limit_reg = XMT_UPPER_LIMIT_REG_PRO;
lp->eeprom_reg = EEPROM_REG_PRO;
spin_lock_init(&lp->lock);
station_addr[0] = read_eeprom(ioaddr, 2, dev);
if (station_addr[0] == 0x0000 || station_addr[0] == 0xffff) {
lp->eepro = LAN595FX_10ISA;
lp->eeprom_reg = EEPROM_REG_10;
lp->xmt_lower_limit_reg = XMT_LOWER_LIMIT_REG_10;
lp->xmt_upper_limit_reg = XMT_UPPER_LIMIT_REG_10;
lp->xmt_bar = XMT_BAR_10;
station_addr[0] = read_eeprom(ioaddr, 2, dev);
}
for (i = 0; i < 8; i++) {
lp->word[i] = read_eeprom(ioaddr, i, dev);
}
station_addr[1] = lp->word[3];
station_addr[2] = lp->word[4];
if (!lp->eepro) {
if (lp->word[7] == ee_FX_INT2IRQ)
lp->eepro = 2;
else if (station_addr[2] == SA_ADDR1)
lp->eepro = 1;
}
for (i=0; i < 6; i++)
dev->dev_addr[i] = ((unsigned char *) station_addr)[5-i];
if (dev->mem_end < 3072 || dev->mem_end > 29696)
lp->rcv_ram = RCV_DEFAULT_RAM;
eepro_recalc(dev);
if (GetBit(lp->word[5], ee_BNC_TPE))
dev->if_port = BNC;
else
dev->if_port = TPE;
if (dev->irq < 2 && lp->eepro != 0) {
int count = lp->word[1] & 7;
unsigned irqMask = lp->word[7];
while (count--)
irqMask &= irqMask - 1;
count = ffs(irqMask);
if (count)
dev->irq = count - 1;
if (dev->irq < 2) {
printk(KERN_ERR " Duh! illegal interrupt vector stored in EEPROM.\n");
goto exit;
} else if (dev->irq == 2) {
dev->irq = 9;
}
}
dev->netdev_ops = &eepro_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
dev->ethtool_ops = &eepro_ethtool_ops;
eepro_print_info(dev);
eepro_reset(ioaddr);
err = register_netdev(dev);
if (err)
goto err;
return 0;
exit:
err = -ENODEV;
err:
release_region(dev->base_addr, EEPRO_IO_EXTENT);
return err;
}
static int eepro_grab_irq(struct net_device *dev)
{
static const int irqlist[] = { 3, 4, 5, 7, 9, 10, 11, 12, 0 };
const int *irqp = irqlist;
int temp_reg, ioaddr = dev->base_addr;
eepro_sw2bank1(ioaddr);
eepro_en_intline(ioaddr);
eepro_sw2bank0(ioaddr);
eepro_clear_int(ioaddr);
eepro_en_intexec(ioaddr);
do {
eepro_sw2bank1(ioaddr);
temp_reg = inb(ioaddr + INT_NO_REG);
outb((temp_reg & 0xf8) | irqrmap[*irqp], ioaddr + INT_NO_REG);
eepro_sw2bank0(ioaddr);
if (request_irq (*irqp, NULL, IRQF_SHARED, "bogus", dev) != EBUSY) {
unsigned long irq_mask;
irq_mask = probe_irq_on();
eepro_diag(ioaddr);
mdelay(20);
if (*irqp == probe_irq_off(irq_mask))
break;
eepro_clear_int(ioaddr);
}
} while (*++irqp);
eepro_sw2bank1(ioaddr);
eepro_dis_intline(ioaddr);
eepro_sw2bank0(ioaddr);
eepro_dis_int(ioaddr);
eepro_clear_int(ioaddr);
return dev->irq;
}
static int eepro_open(struct net_device *dev)
{
unsigned short temp_reg, old8, old9;
int irqMask;
int i, ioaddr = dev->base_addr;
struct eepro_local *lp = netdev_priv(dev);
if (net_debug > 3)
printk(KERN_DEBUG "%s: entering eepro_open routine.\n", dev->name);
irqMask = lp->word[7];
if (lp->eepro == LAN595FX_10ISA) {
if (net_debug > 3) printk(KERN_DEBUG "p->eepro = 3;\n");
}
else if (irqMask == ee_FX_INT2IRQ)
{
lp->eepro = 2;
if (net_debug > 3) printk(KERN_DEBUG "p->eepro = 2;\n");
}
else if ((dev->dev_addr[0] == SA_ADDR0 &&
dev->dev_addr[1] == SA_ADDR1 &&
dev->dev_addr[2] == SA_ADDR2))
{
lp->eepro = 1;
if (net_debug > 3) printk(KERN_DEBUG "p->eepro = 1;\n");
}
else lp->eepro = 0;
if (dev->irq < 2 && eepro_grab_irq(dev) == 0) {
printk(KERN_ERR "%s: unable to get IRQ %d.\n", dev->name, dev->irq);
return -EAGAIN;
}
if (request_irq(dev->irq , eepro_interrupt, 0, dev->name, dev)) {
printk(KERN_ERR "%s: unable to get IRQ %d.\n", dev->name, dev->irq);
return -EAGAIN;
}
eepro_sw2bank2(ioaddr);
temp_reg = inb(ioaddr + lp->eeprom_reg);
lp->stepping = temp_reg >> 5;
if (net_debug > 3)
printk(KERN_DEBUG "The stepping of the 82595 is %d\n", lp->stepping);
if (temp_reg & 0x10)
outb(temp_reg & 0xef, ioaddr + lp->eeprom_reg);
for (i=0; i < 6; i++)
outb(dev->dev_addr[i] , ioaddr + I_ADD_REG0 + i);
temp_reg = inb(ioaddr + REG1);
outb(temp_reg | XMT_Chain_Int | XMT_Chain_ErrStop
| RCV_Discard_BadFrame, ioaddr + REG1);
temp_reg = inb(ioaddr + REG2);
outb(temp_reg | 0x14, ioaddr + REG2);
temp_reg = inb(ioaddr + REG3);
outb(temp_reg & 0x3f, ioaddr + REG3);
eepro_sw2bank1(ioaddr);
temp_reg = inb(ioaddr + INT_NO_REG);
if (lp->eepro == LAN595FX || lp->eepro == LAN595FX_10ISA)
outb((temp_reg & 0xf8) | irqrmap2[dev->irq], ioaddr + INT_NO_REG);
else outb((temp_reg & 0xf8) | irqrmap[dev->irq], ioaddr + INT_NO_REG);
temp_reg = inb(ioaddr + INT_NO_REG);
if (lp->eepro == LAN595FX || lp->eepro == LAN595FX_10ISA)
outb((temp_reg & 0xf0) | irqrmap2[dev->irq] | 0x08,ioaddr+INT_NO_REG);
else outb((temp_reg & 0xf8) | irqrmap[dev->irq], ioaddr + INT_NO_REG);
if (net_debug > 3)
printk(KERN_DEBUG "eepro_open: content of INT Reg is %x\n", temp_reg);
outb(lp->rcv_lower_limit >> 8, ioaddr + RCV_LOWER_LIMIT_REG);
outb(lp->rcv_upper_limit >> 8, ioaddr + RCV_UPPER_LIMIT_REG);
outb(lp->xmt_lower_limit >> 8, ioaddr + lp->xmt_lower_limit_reg);
outb(lp->xmt_upper_limit >> 8, ioaddr + lp->xmt_upper_limit_reg);
eepro_en_intline(ioaddr);
eepro_sw2bank0(ioaddr);
eepro_en_int(ioaddr);
eepro_clear_int(ioaddr);
outw(lp->rcv_lower_limit, ioaddr + RCV_BAR);
lp->rx_start = lp->rcv_lower_limit;
outw(lp->rcv_upper_limit | 0xfe, ioaddr + RCV_STOP);
outw(lp->xmt_lower_limit, ioaddr + lp->xmt_bar);
lp->tx_start = lp->tx_end = lp->xmt_lower_limit;
lp->tx_last = 0;
old8 = inb(ioaddr + 8);
outb(~old8, ioaddr + 8);
if ((temp_reg = inb(ioaddr + 8)) == old8) {
if (net_debug > 3)
printk(KERN_DEBUG "i82595 detected!\n");
lp->version = LAN595;
}
else {
lp->version = LAN595TX;
outb(old8, ioaddr + 8);
old9 = inb(ioaddr + 9);
if (irqMask==ee_FX_INT2IRQ) {
if (net_debug > 3) {
printk(KERN_DEBUG "IrqMask: %#x\n",irqMask);
printk(KERN_DEBUG "i82595FX detected!\n");
}
lp->version = LAN595FX;
outb(old9, ioaddr + 9);
if (dev->if_port != TPE) {
eepro_sw2bank2(ioaddr);
temp_reg = inb(ioaddr + REG13);
outb(temp_reg & ~(FDX | A_N_ENABLE), REG13);
eepro_sw2bank0(ioaddr);
}
}
else if (net_debug > 3) {
printk(KERN_DEBUG "temp_reg: %#x ~old9: %#x\n",temp_reg,((~old9)&0xff));
printk(KERN_DEBUG "i82595TX detected!\n");
}
}
eepro_sel_reset(ioaddr);
netif_start_queue(dev);
if (net_debug > 3)
printk(KERN_DEBUG "%s: exiting eepro_open routine.\n", dev->name);
eepro_en_rx(ioaddr);
return 0;
}
static void eepro_tx_timeout (struct net_device *dev)
{
struct eepro_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
printk (KERN_ERR "%s: transmit timed out, %s?\n", dev->name,
"network cable problem");
printk (KERN_DEBUG "%s: transmit timed out, %s?\n", dev->name,
"network cable problem");
eepro_complete_selreset(ioaddr);
}
static netdev_tx_t eepro_send_packet(struct sk_buff *skb,
struct net_device *dev)
{
struct eepro_local *lp = netdev_priv(dev);
unsigned long flags;
int ioaddr = dev->base_addr;
short length = skb->len;
if (net_debug > 5)
printk(KERN_DEBUG "%s: entering eepro_send_packet routine.\n", dev->name);
if (length < ETH_ZLEN) {
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
length = ETH_ZLEN;
}
netif_stop_queue (dev);
eepro_dis_int(ioaddr);
spin_lock_irqsave(&lp->lock, flags);
{
unsigned char *buf = skb->data;
if (hardware_send_packet(dev, buf, length))
dev->stats.tx_dropped++;
else {
dev->stats.tx_bytes+=skb->len;
netif_wake_queue(dev);
}
}
dev_kfree_skb (skb);
if (net_debug > 5)
printk(KERN_DEBUG "%s: exiting eepro_send_packet routine.\n", dev->name);
eepro_en_int(ioaddr);
spin_unlock_irqrestore(&lp->lock, flags);
return NETDEV_TX_OK;
}
static irqreturn_t
eepro_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct eepro_local *lp;
int ioaddr, status, boguscount = 20;
int handled = 0;
lp = netdev_priv(dev);
spin_lock(&lp->lock);
if (net_debug > 5)
printk(KERN_DEBUG "%s: entering eepro_interrupt routine.\n", dev->name);
ioaddr = dev->base_addr;
while (((status = inb(ioaddr + STATUS_REG)) & (RX_INT|TX_INT)) && (boguscount--))
{
handled = 1;
if (status & RX_INT) {
if (net_debug > 4)
printk(KERN_DEBUG "%s: packet received interrupt.\n", dev->name);
eepro_dis_int(ioaddr);
eepro_ack_rx(ioaddr);
eepro_rx(dev);
eepro_en_int(ioaddr);
}
if (status & TX_INT) {
if (net_debug > 4)
printk(KERN_DEBUG "%s: packet transmit interrupt.\n", dev->name);
eepro_dis_int(ioaddr);
eepro_ack_tx(ioaddr);
eepro_transmit_interrupt(dev);
eepro_en_int(ioaddr);
}
}
if (net_debug > 5)
printk(KERN_DEBUG "%s: exiting eepro_interrupt routine.\n", dev->name);
spin_unlock(&lp->lock);
return IRQ_RETVAL(handled);
}
static int eepro_close(struct net_device *dev)
{
struct eepro_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
short temp_reg;
netif_stop_queue(dev);
eepro_sw2bank1(ioaddr);
temp_reg = inb(ioaddr + REG1);
outb(temp_reg & 0x7f, ioaddr + REG1);
eepro_sw2bank0(ioaddr);
outb(STOP_RCV_CMD, ioaddr);
lp->tx_start = lp->tx_end = lp->xmt_lower_limit;
lp->tx_last = 0;
eepro_dis_int(ioaddr);
eepro_clear_int(ioaddr);
eepro_reset(ioaddr);
free_irq(dev->irq, dev);
return 0;
}
static void
set_multicast_list(struct net_device *dev)
{
struct eepro_local *lp = netdev_priv(dev);
short ioaddr = dev->base_addr;
unsigned short mode;
struct netdev_hw_addr *ha;
int mc_count = netdev_mc_count(dev);
if (dev->flags&(IFF_ALLMULTI|IFF_PROMISC) || mc_count > 63)
{
eepro_sw2bank2(ioaddr);
mode = inb(ioaddr + REG2);
outb(mode | PRMSC_Mode, ioaddr + REG2);
mode = inb(ioaddr + REG3);
outb(mode, ioaddr + REG3);
eepro_sw2bank0(ioaddr);
}
else if (mc_count == 0)
{
eepro_sw2bank2(ioaddr);
mode = inb(ioaddr + REG2);
outb(mode & 0xd6, ioaddr + REG2);
mode = inb(ioaddr + REG3);
outb(mode, ioaddr + REG3);
eepro_sw2bank0(ioaddr);
}
else
{
unsigned short status, *eaddrs;
int i, boguscount = 0;
eepro_dis_int(ioaddr);
eepro_sw2bank2(ioaddr);
mode = inb(ioaddr + REG2);
outb(mode | Multi_IA, ioaddr + REG2);
mode = inb(ioaddr + REG3);
outb(mode, ioaddr + REG3);
eepro_sw2bank0(ioaddr);
outw(lp->tx_end, ioaddr + HOST_ADDRESS_REG);
outw(MC_SETUP, ioaddr + IO_PORT);
outw(0, ioaddr + IO_PORT);
outw(0, ioaddr + IO_PORT);
outw(6 * (mc_count + 1), ioaddr + IO_PORT);
netdev_for_each_mc_addr(ha, dev) {
eaddrs = (unsigned short *) ha->addr;
outw(*eaddrs++, ioaddr + IO_PORT);
outw(*eaddrs++, ioaddr + IO_PORT);
outw(*eaddrs++, ioaddr + IO_PORT);
}
eaddrs = (unsigned short *) dev->dev_addr;
outw(eaddrs[0], ioaddr + IO_PORT);
outw(eaddrs[1], ioaddr + IO_PORT);
outw(eaddrs[2], ioaddr + IO_PORT);
outw(lp->tx_end, ioaddr + lp->xmt_bar);
outb(MC_SETUP, ioaddr);
i = lp->tx_end + XMT_HEADER + 6 * (mc_count + 1);
if (lp->tx_start != lp->tx_end)
{
outw(lp->tx_last + XMT_CHAIN, ioaddr + HOST_ADDRESS_REG);
outw(i, ioaddr + IO_PORT);
outw(lp->tx_last + XMT_COUNT, ioaddr + HOST_ADDRESS_REG);
status = inw(ioaddr + IO_PORT);
outw(status | CHAIN_BIT, ioaddr + IO_PORT);
lp->tx_end = i ;
}
else {
lp->tx_start = lp->tx_end = i ;
}
do {
SLOW_DOWN;
SLOW_DOWN;
if (inb(ioaddr + STATUS_REG) & 0x08)
{
i = inb(ioaddr);
outb(0x08, ioaddr + STATUS_REG);
if (i & 0x20) {
printk(KERN_NOTICE "%s: multicast setup failed.\n",
dev->name);
break;
} else if ((i & 0x0f) == 0x03) {
printk(KERN_DEBUG "%s: set Rx mode to %d address%s.\n",
dev->name, mc_count,
mc_count > 1 ? "es":"");
break;
}
}
} while (++boguscount < 100);
eepro_en_int(ioaddr);
}
if (lp->eepro == LAN595FX_10ISA) {
eepro_complete_selreset(ioaddr);
}
else
eepro_en_rx(ioaddr);
}
static int
read_eeprom(int ioaddr, int location, struct net_device *dev)
{
int i;
unsigned short retval = 0;
struct eepro_local *lp = netdev_priv(dev);
short ee_addr = ioaddr + lp->eeprom_reg;
int read_cmd = location | EE_READ_CMD;
short ctrl_val = EECS ;
eepro_sw2bank1(ioaddr);
outb(0x00, ioaddr + STATUS_REG);
eepro_sw2bank2(ioaddr);
outb(ctrl_val, ee_addr);
for (i = 8; i >= 0; i--) {
short outval = (read_cmd & (1 << i)) ? ctrl_val | EEDI
: ctrl_val;
outb(outval, ee_addr);
outb(outval | EESK, ee_addr);
eeprom_delay();
outb(outval, ee_addr);
eeprom_delay();
}
outb(ctrl_val, ee_addr);
for (i = 16; i > 0; i--) {
outb(ctrl_val | EESK, ee_addr); eeprom_delay();
retval = (retval << 1) | ((inb(ee_addr) & EEDO) ? 1 : 0);
outb(ctrl_val, ee_addr); eeprom_delay();
}
ctrl_val &= ~EECS;
outb(ctrl_val | EESK, ee_addr);
eeprom_delay();
outb(ctrl_val, ee_addr);
eeprom_delay();
eepro_sw2bank0(ioaddr);
return retval;
}
static int
hardware_send_packet(struct net_device *dev, void *buf, short length)
{
struct eepro_local *lp = netdev_priv(dev);
short ioaddr = dev->base_addr;
unsigned status, tx_available, last, end;
if (net_debug > 5)
printk(KERN_DEBUG "%s: entering hardware_send_packet routine.\n", dev->name);
if (lp->tx_end > lp->tx_start)
tx_available = lp->xmt_ram - (lp->tx_end - lp->tx_start);
else if (lp->tx_end < lp->tx_start)
tx_available = lp->tx_start - lp->tx_end;
else tx_available = lp->xmt_ram;
if (((((length + 3) >> 1) << 1) + 2*XMT_HEADER) >= tx_available) {
return 1;
}
last = lp->tx_end;
end = last + (((length + 3) >> 1) << 1) + XMT_HEADER;
if (end >= lp->xmt_upper_limit + 2) {
if ((lp->xmt_upper_limit + 2 - last) <= XMT_HEADER) {
last = lp->xmt_lower_limit;
end = last + (((length + 3) >> 1) << 1) + XMT_HEADER;
}
else end = lp->xmt_lower_limit + (end -
lp->xmt_upper_limit + 2);
}
outw(last, ioaddr + HOST_ADDRESS_REG);
outw(XMT_CMD, ioaddr + IO_PORT);
outw(0, ioaddr + IO_PORT);
outw(end, ioaddr + IO_PORT);
outw(length, ioaddr + IO_PORT);
if (lp->version == LAN595)
outsw(ioaddr + IO_PORT, buf, (length + 3) >> 1);
else {
unsigned short temp = inb(ioaddr + INT_MASK_REG);
outb(temp | IO_32_BIT, ioaddr + INT_MASK_REG);
outsl(ioaddr + IO_PORT_32_BIT, buf, (length + 3) >> 2);
outb(temp & ~(IO_32_BIT), ioaddr + INT_MASK_REG);
}
status = inw(ioaddr + IO_PORT);
if (lp->tx_start == lp->tx_end) {
outw(last, ioaddr + lp->xmt_bar);
outb(XMT_CMD, ioaddr);
lp->tx_start = last;
}
else {
if (lp->tx_end != last) {
outw(lp->tx_last + XMT_CHAIN, ioaddr + HOST_ADDRESS_REG);
outw(last, ioaddr + IO_PORT);
}
outw(lp->tx_last + XMT_COUNT, ioaddr + HOST_ADDRESS_REG);
status = inw(ioaddr + IO_PORT);
outw(status | CHAIN_BIT, ioaddr + IO_PORT);
outb(RESUME_XMT_CMD, ioaddr);
}
lp->tx_last = last;
lp->tx_end = end;
if (net_debug > 5)
printk(KERN_DEBUG "%s: exiting hardware_send_packet routine.\n", dev->name);
return 0;
}
static void
eepro_rx(struct net_device *dev)
{
struct eepro_local *lp = netdev_priv(dev);
short ioaddr = dev->base_addr;
short boguscount = 20;
short rcv_car = lp->rx_start;
unsigned rcv_event, rcv_status, rcv_next_frame, rcv_size;
if (net_debug > 5)
printk(KERN_DEBUG "%s: entering eepro_rx routine.\n", dev->name);
outw(rcv_car, ioaddr + HOST_ADDRESS_REG);
rcv_event = inw(ioaddr + IO_PORT);
while (rcv_event == RCV_DONE) {
rcv_status = inw(ioaddr + IO_PORT);
rcv_next_frame = inw(ioaddr + IO_PORT);
rcv_size = inw(ioaddr + IO_PORT);
if ((rcv_status & (RX_OK | RX_ERROR)) == RX_OK) {
struct sk_buff *skb;
dev->stats.rx_bytes+=rcv_size;
rcv_size &= 0x3fff;
skb = dev_alloc_skb(rcv_size+5);
if (skb == NULL) {
printk(KERN_NOTICE "%s: Memory squeeze, dropping packet.\n", dev->name);
dev->stats.rx_dropped++;
rcv_car = lp->rx_start + RCV_HEADER + rcv_size;
lp->rx_start = rcv_next_frame;
outw(rcv_next_frame, ioaddr + HOST_ADDRESS_REG);
break;
}
skb_reserve(skb,2);
if (lp->version == LAN595)
insw(ioaddr+IO_PORT, skb_put(skb,rcv_size), (rcv_size + 3) >> 1);
else {
unsigned short temp = inb(ioaddr + INT_MASK_REG);
outb(temp | IO_32_BIT, ioaddr + INT_MASK_REG);
insl(ioaddr+IO_PORT_32_BIT, skb_put(skb,rcv_size),
(rcv_size + 3) >> 2);
outb(temp & ~(IO_32_BIT), ioaddr + INT_MASK_REG);
}
skb->protocol = eth_type_trans(skb,dev);
netif_rx(skb);
dev->stats.rx_packets++;
}
else {
dev->stats.rx_errors++;
if (rcv_status & 0x0100)
dev->stats.rx_over_errors++;
else if (rcv_status & 0x0400)
dev->stats.rx_frame_errors++;
else if (rcv_status & 0x0800)
dev->stats.rx_crc_errors++;
printk(KERN_DEBUG "%s: event = %#x, status = %#x, next = %#x, size = %#x\n",
dev->name, rcv_event, rcv_status, rcv_next_frame, rcv_size);
}
if (rcv_status & 0x1000)
dev->stats.rx_length_errors++;
rcv_car = lp->rx_start + RCV_HEADER + rcv_size;
lp->rx_start = rcv_next_frame;
if (--boguscount == 0)
break;
outw(rcv_next_frame, ioaddr + HOST_ADDRESS_REG);
rcv_event = inw(ioaddr + IO_PORT);
}
if (rcv_car == 0)
rcv_car = lp->rcv_upper_limit | 0xff;
outw(rcv_car - 1, ioaddr + RCV_STOP);
if (net_debug > 5)
printk(KERN_DEBUG "%s: exiting eepro_rx routine.\n", dev->name);
}
static void
eepro_transmit_interrupt(struct net_device *dev)
{
struct eepro_local *lp = netdev_priv(dev);
short ioaddr = dev->base_addr;
short boguscount = 25;
short xmt_status;
while ((lp->tx_start != lp->tx_end) && boguscount--) {
outw(lp->tx_start, ioaddr + HOST_ADDRESS_REG);
xmt_status = inw(ioaddr+IO_PORT);
if (!(xmt_status & TX_DONE_BIT))
break;
xmt_status = inw(ioaddr+IO_PORT);
lp->tx_start = inw(ioaddr+IO_PORT);
netif_wake_queue (dev);
if (xmt_status & TX_OK)
dev->stats.tx_packets++;
else {
dev->stats.tx_errors++;
if (xmt_status & 0x0400) {
dev->stats.tx_carrier_errors++;
printk(KERN_DEBUG "%s: carrier error\n",
dev->name);
printk(KERN_DEBUG "%s: XMT status = %#x\n",
dev->name, xmt_status);
}
else {
printk(KERN_DEBUG "%s: XMT status = %#x\n",
dev->name, xmt_status);
printk(KERN_DEBUG "%s: XMT status = %#x\n",
dev->name, xmt_status);
}
}
if (xmt_status & 0x000f) {
dev->stats.collisions += (xmt_status & 0x000f);
}
if ((xmt_status & 0x0040) == 0x0) {
dev->stats.tx_heartbeat_errors++;
}
}
}
static int eepro_ethtool_get_settings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct eepro_local *lp = netdev_priv(dev);
cmd->supported = SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_Autoneg;
cmd->advertising = ADVERTISED_10baseT_Half |
ADVERTISED_10baseT_Full |
ADVERTISED_Autoneg;
if (GetBit(lp->word[5], ee_PortTPE)) {
cmd->supported |= SUPPORTED_TP;
cmd->advertising |= ADVERTISED_TP;
}
if (GetBit(lp->word[5], ee_PortBNC)) {
cmd->supported |= SUPPORTED_BNC;
cmd->advertising |= ADVERTISED_BNC;
}
if (GetBit(lp->word[5], ee_PortAUI)) {
cmd->supported |= SUPPORTED_AUI;
cmd->advertising |= ADVERTISED_AUI;
}
ethtool_cmd_speed_set(cmd, SPEED_10);
if (dev->if_port == TPE && lp->word[1] & ee_Duplex) {
cmd->duplex = DUPLEX_FULL;
}
else {
cmd->duplex = DUPLEX_HALF;
}
cmd->port = dev->if_port;
cmd->phy_address = dev->base_addr;
cmd->transceiver = XCVR_INTERNAL;
if (lp->word[0] & ee_AutoNeg) {
cmd->autoneg = 1;
}
return 0;
}
static void eepro_ethtool_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *drvinfo)
{
strcpy(drvinfo->driver, DRV_NAME);
strcpy(drvinfo->version, DRV_VERSION);
sprintf(drvinfo->bus_info, "ISA 0x%lx", dev->base_addr);
}
int __init init_module(void)
{
struct net_device *dev;
int i;
if (io[0] == -1 && autodetect == 0) {
printk(KERN_WARNING "eepro_init_module: Probe is very dangerous in ISA boards!\n");
printk(KERN_WARNING "eepro_init_module: Please add \"autodetect=1\" to force probe\n");
return -ENODEV;
}
else if (autodetect) {
for (i = 0; i < MAX_EEPRO; i++) {
io[i] = 0;
}
printk(KERN_INFO "eepro_init_module: Auto-detecting boards (May God protect us...)\n");
}
for (i = 0; i < MAX_EEPRO && io[i] != -1; i++) {
dev = alloc_etherdev(sizeof(struct eepro_local));
if (!dev)
break;
dev->mem_end = mem[i];
dev->base_addr = io[i];
dev->irq = irq[i];
if (do_eepro_probe(dev) == 0) {
dev_eepro[n_eepro++] = dev;
continue;
}
free_netdev(dev);
break;
}
if (n_eepro)
printk(KERN_INFO "%s", version);
return n_eepro ? 0 : -ENODEV;
}
void __exit
cleanup_module(void)
{
int i;
for (i=0; i<n_eepro; i++) {
struct net_device *dev = dev_eepro[i];
unregister_netdev(dev);
release_region(dev->base_addr, EEPRO_IO_EXTENT);
free_netdev(dev);
}
}
