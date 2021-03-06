static void dumpregs(struct net_device *dev)
{
int z;
for (z = 0; z < 160; z += 2) {
if (!(z & 15))
printk("REGS: %04x:", z);
printk(" %04x", inw(dev->base_addr + z));
if ((z & 15) == 14)
printk("\n");
}
}
static void dumpmem(struct net_device *dev, u32 start, u32 len)
{
ibmlana_priv *priv = netdev_priv(dev);
int z;
printk("Address %04x:\n", start);
for (z = 0; z < len; z++) {
if ((z & 15) == 0)
printk("%04x:", z);
printk(" %02x", readb(priv->base + start + z));
if ((z & 15) == 15)
printk("\n");
}
if ((z & 15) != 0)
printk("\n");
}
static void PrTime(void)
{
struct timeval tv;
do_gettimeofday(&tv);
printk("%9d:%06d: ", (int) tv.tv_sec, (int) tv.tv_usec);
}
static void getaddrs(struct mca_device *mdev, int *base, int *memlen,
int *iobase, int *irq, ibmlana_medium *medium)
{
u_char pos0, pos1;
pos0 = mca_device_read_stored_pos(mdev, 2);
pos1 = mca_device_read_stored_pos(mdev, 3);
*base = 0xc0000 + ((pos1 & 0xf0) << 9);
*memlen = (pos1 & 0x01) ? 0x8000 : 0x4000;
*iobase = (pos0 & 0xe0) << 7;
switch (pos0 & 0x06) {
case 0:
*irq = 5;
break;
case 2:
*irq = 15;
break;
case 4:
*irq = 10;
break;
case 6:
*irq = 11;
break;
}
*medium = (pos0 & 0x18) >> 3;
}
static int wait_timeout(struct net_device *dev, int regoffs, u16 mask,
u16 value, int timeout)
{
unsigned long fin = jiffies + timeout;
while (time_before(jiffies,fin))
if ((inw(dev->base_addr + regoffs) & mask) == value)
return 1;
return 0;
}
static void ResetBoard(struct net_device *dev)
{
unsigned char bcmval;
bcmval = inb(dev->base_addr + BCMREG);
bcmval |= BCMREG_RESET;
outb(bcmval, dev->base_addr + BCMREG);
udelay(10);
bcmval &= ~BCMREG_RESET;
outb(bcmval, dev->base_addr + BCMREG);
bcmval |= BCMREG_RAMEN | BCMREG_RAMWIN;
outb(bcmval, dev->base_addr + BCMREG);
}
static void InitDscrs(struct net_device *dev)
{
ibmlana_priv *priv = netdev_priv(dev);
u32 addr, baddr, raddr;
int z;
tda_t tda;
rda_t rda;
rra_t rra;
memset_io(priv->base, 0xaa,
dev->mem_start - dev->mem_start);
priv->tdastart = addr = 0;
priv->txbufstart = baddr = sizeof(tda_t) * TXBUFCNT;
for (z = 0; z < TXBUFCNT; z++) {
tda.status = 0;
tda.config = 0;
tda.length = 0;
tda.fragcount = 1;
tda.startlo = baddr;
tda.starthi = 0;
tda.fraglength = 0;
if (z == TXBUFCNT - 1)
tda.link = priv->tdastart;
else
tda.link = addr + sizeof(tda_t);
tda.link |= 1;
memcpy_toio(priv->base + addr, &tda, sizeof(tda_t));
addr += sizeof(tda_t);
baddr += PKTSIZE;
}
priv->rxbufcnt = (dev->mem_end - dev->mem_start - baddr) / (sizeof(rra_t) + sizeof(rda_t) + PKTSIZE);
priv->rrastart = raddr = priv->txbufstart + (TXBUFCNT * PKTSIZE);
priv->rdastart = addr = priv->rrastart + (priv->rxbufcnt * sizeof(rra_t));
priv->rxbufstart = baddr = priv->rdastart + (priv->rxbufcnt * sizeof(rda_t));
for (z = 0; z < priv->rxbufcnt; z++) {
rra.startlo = baddr;
rra.starthi = 0;
rra.cntlo = PKTSIZE >> 1;
rra.cnthi = 0;
memcpy_toio(priv->base + raddr, &rra, sizeof(rra_t));
rda.status = 0;
rda.length = 0;
rda.startlo = 0;
rda.starthi = 0;
rda.seqno = 0;
if (z < priv->rxbufcnt - 1)
rda.link = addr + sizeof(rda_t);
else
rda.link = 1;
rda.inuse = 1;
memcpy_toio(priv->base + addr, &rda, sizeof(rda_t));
baddr += PKTSIZE;
raddr += sizeof(rra_t);
addr += sizeof(rda_t);
}
priv->nextrxdescr = 0;
priv->lastrxdescr = priv->rxbufcnt - 1;
priv->nexttxdescr = 0;
priv->currtxdescr = 0;
priv->txusedcnt = 0;
memset(priv->txused, 0, sizeof(priv->txused));
}
static int InitSONIC(struct net_device *dev)
{
ibmlana_priv *priv = netdev_priv(dev);
outw(0, SONIC_URRA);
outw(priv->rrastart, dev->base_addr + SONIC_RSA);
outw(priv->rrastart + (priv->rxbufcnt * sizeof(rra_t)), dev->base_addr + SONIC_REA);
outw(priv->rrastart, dev->base_addr + SONIC_RRP);
outw(priv->rrastart, dev->base_addr + SONIC_RWP);
outw((PKTSIZE - 4) >> 1, dev->base_addr + SONIC_EOBC);
outw(CMDREG_RRRA, dev->base_addr + SONIC_CMDREG);
if (!wait_timeout(dev, SONIC_CMDREG, CMDREG_RRRA, 0, 2)) {
printk(KERN_ERR "%s: SONIC did not respond on RRRA command - giving up.", dev->name);
return 0;
}
outw(0, dev->base_addr + SONIC_URDA);
outw(priv->rdastart, dev->base_addr + SONIC_CRDA);
outw(0, dev->base_addr + SONIC_UTDA);
return 1;
}
static void StopSONIC(struct net_device *dev)
{
outb(inb(dev->base_addr + BCMREG) & (~BCMREG_IEN), dev->base_addr + BCMREG);
outb(0, dev->base_addr + SONIC_IMREG);
outw(CMDREG_RST, dev->base_addr + SONIC_CMDREG);
udelay(10);
outw(CMDREG_RST, dev->base_addr + SONIC_CMDREG);
}
static void putcam(camentry_t * cams, int *camcnt, char *addr)
{
camentry_t *pcam = cams + (*camcnt);
u8 *uaddr = (u8 *) addr;
pcam->index = *camcnt;
pcam->addr0 = (((u16) uaddr[1]) << 8) | uaddr[0];
pcam->addr1 = (((u16) uaddr[3]) << 8) | uaddr[2];
pcam->addr2 = (((u16) uaddr[5]) << 8) | uaddr[4];
(*camcnt)++;
}
static void InitBoard(struct net_device *dev)
{
ibmlana_priv *priv = netdev_priv(dev);
int camcnt;
camentry_t cams[16];
u32 cammask;
struct netdev_hw_addr *ha;
u16 rcrval;
outw(CMDREG_RST, dev->base_addr + SONIC_CMDREG);
udelay(10);
outw(inw(dev->base_addr + SONIC_ISREG), dev->base_addr + SONIC_ISREG);
outw(DCREG_USR1 | DCREG_USR0 | DCREG_WC1 | DCREG_DW32, dev->base_addr + SONIC_DCREG);
outw(0, dev->base_addr + SONIC_DCREG2);
outw(0, dev->base_addr + SONIC_CMDREG);
udelay(10);
outw(0, dev->base_addr + SONIC_URRA);
camcnt = 0;
putcam(cams, &camcnt, dev->dev_addr);
netdev_for_each_mc_addr(ha, dev) {
putcam(cams, &camcnt, ha->addr);
if (camcnt == 16)
break;
}
cammask = (1 << camcnt) - 1;
memcpy_toio(priv->base, cams, sizeof(camentry_t) * camcnt);
memcpy_toio(priv->base + (sizeof(camentry_t) * camcnt), &cammask, sizeof(cammask));
#ifdef DEBUG
printk("CAM setup:\n");
dumpmem(dev, 0, sizeof(camentry_t) * camcnt + sizeof(cammask));
#endif
outw(0, dev->base_addr + SONIC_CAMPTR);
outw(camcnt, dev->base_addr + SONIC_CAMCNT);
outw(CMDREG_LCAM, dev->base_addr + SONIC_CMDREG);
if (!wait_timeout(dev, SONIC_CMDREG, CMDREG_LCAM, 0, 2)) {
printk(KERN_ERR "%s:SONIC did not respond on LCAM command - giving up.", dev->name);
return;
} else {
outw(ISREG_LCD, dev->base_addr + SONIC_ISREG);
#ifdef DEBUG
printk("Loading CAM done, address pointers %04x:%04x\n",
inw(dev->base_addr + SONIC_URRA),
inw(dev->base_addr + SONIC_CAMPTR));
{
int z;
printk("\n-->CAM: PTR %04x CNT %04x\n",
inw(dev->base_addr + SONIC_CAMPTR),
inw(dev->base_addr + SONIC_CAMCNT));
outw(CMDREG_RST, dev->base_addr + SONIC_CMDREG);
for (z = 0; z < camcnt; z++) {
outw(z, dev->base_addr + SONIC_CAMEPTR);
printk("Entry %d: %04x %04x %04x\n", z,
inw(dev->base_addr + SONIC_CAMADDR0),
inw(dev->base_addr + SONIC_CAMADDR1),
inw(dev->base_addr + SONIC_CAMADDR2));
}
outw(0, dev->base_addr + SONIC_CMDREG);
}
#endif
}
rcrval = RCREG_BRD | RCREG_LB_NONE;
if ((dev->flags & IFF_ALLMULTI) || netdev_mc_count(dev) > camcnt)
rcrval |= RCREG_AMC;
if (dev->flags & IFF_PROMISC)
rcrval |= RCREG_PRO;
outw(rcrval, dev->base_addr + SONIC_RCREG);
#ifdef DEBUG
printk("\nRCRVAL: %04x\n", rcrval);
#endif
InitDscrs(dev);
if (!InitSONIC(dev))
return;
outw(0xffff, dev->base_addr + SONIC_ISREG);
outw(CMDREG_RXEN, dev->base_addr + SONIC_CMDREG);
outw(IMREG_PRXEN | IMREG_RBEEN | IMREG_PTXEN | IMREG_TXEREN, dev->base_addr + SONIC_IMREG);
outb(inb(dev->base_addr + BCMREG) | BCMREG_IEN, dev->base_addr + BCMREG);
#ifdef DEBUG
printk("Register dump after initialization:\n");
dumpregs(dev);
#endif
}
static void StartTx(struct net_device *dev, int descr)
{
ibmlana_priv *priv = netdev_priv(dev);
int addr;
addr = priv->tdastart + (descr * sizeof(tda_t));
outw(addr, dev->base_addr + SONIC_CTDA);
priv->currtxdescr = descr;
outw(CMDREG_TXP, dev->base_addr + SONIC_CMDREG);
}
static void irqrbe_handler(struct net_device *dev)
{
ibmlana_priv *priv = netdev_priv(dev);
outw(priv->rrastart, dev->base_addr + SONIC_RRP);
outw(priv->rrastart, dev->base_addr + SONIC_RWP);
}
static void irqrx_handler(struct net_device *dev)
{
ibmlana_priv *priv = netdev_priv(dev);
rda_t rda;
u32 rdaaddr, lrdaaddr;
while (1) {
rdaaddr = priv->rdastart + (priv->nextrxdescr * sizeof(rda_t));
lrdaaddr = priv->rdastart + (priv->lastrxdescr * sizeof(rda_t));
memcpy_fromio(&rda, priv->base + rdaaddr, sizeof(rda_t));
rda.status &= 0xffff;
rda.length &= 0xffff;
rda.startlo &= 0xffff;
if (rda.inuse)
break;
else if (rda.status & RCREG_PRX) {
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, rda.length + 2);
if (skb == NULL)
dev->stats.rx_dropped++;
else {
memcpy_fromio(skb_put(skb, rda.length),
priv->base +
rda.startlo, rda.length);
skb->protocol = eth_type_trans(skb, dev);
skb_checksum_none_assert(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += rda.length;
netif_rx(skb);
}
}
else {
dev->stats.rx_errors++;
if (rda.status & RCREG_FAER)
dev->stats.rx_frame_errors++;
if (rda.status & RCREG_CRCR)
dev->stats.rx_crc_errors++;
}
rda.link = 1;
rda.inuse = 1;
memcpy_toio(priv->base + rdaaddr, &rda,
sizeof(rda_t));
memcpy_toio(priv->base + lrdaaddr + 20, &rdaaddr, 4);
priv->lastrxdescr = priv->nextrxdescr;
if ((++priv->nextrxdescr) >= priv->rxbufcnt)
priv->nextrxdescr = 0;
}
}
static void irqtx_handler(struct net_device *dev)
{
ibmlana_priv *priv = netdev_priv(dev);
tda_t tda;
memcpy_fromio(&tda, priv->base + priv->tdastart + (priv->currtxdescr * sizeof(tda_t)), sizeof(tda_t));
dev->stats.tx_packets++;
dev->stats.tx_bytes += tda.length;
priv->txused[priv->currtxdescr] = 0;
priv->txusedcnt--;
if (priv->txusedcnt > 0)
StartTx(dev, (priv->currtxdescr + 1) % TXBUFCNT);
netif_wake_queue(dev);
}
static void irqtxerr_handler(struct net_device *dev)
{
ibmlana_priv *priv = netdev_priv(dev);
tda_t tda;
memcpy_fromio(&tda, priv->base + priv->tdastart + (priv->currtxdescr * sizeof(tda_t)), sizeof(tda_t));
dev->stats.tx_errors++;
if (tda.status & (TCREG_NCRS | TCREG_CRSL))
dev->stats.tx_carrier_errors++;
if (tda.status & TCREG_EXC)
dev->stats.tx_aborted_errors++;
if (tda.status & TCREG_OWC)
dev->stats.tx_window_errors++;
if (tda.status & TCREG_FU)
dev->stats.tx_fifo_errors++;
priv->txused[priv->currtxdescr] = 0;
priv->txusedcnt--;
if (priv->txusedcnt > 0)
StartTx(dev, (priv->currtxdescr + 1) % TXBUFCNT);
netif_wake_queue(dev);
}
static irqreturn_t irq_handler(int dummy, void *device)
{
struct net_device *dev = device;
u16 ival;
if (!(inb(dev->base_addr + BCMREG) & BCMREG_IPEND))
return IRQ_NONE;
while (1) {
ival = inw(dev->base_addr + SONIC_ISREG);
if (ival & ISREG_RBE) {
irqrbe_handler(dev);
outw(ISREG_RBE, dev->base_addr + SONIC_ISREG);
}
if (ival & ISREG_PKTRX) {
irqrx_handler(dev);
outw(ISREG_PKTRX, dev->base_addr + SONIC_ISREG);
}
if (ival & ISREG_TXDN) {
irqtx_handler(dev);
outw(ISREG_TXDN, dev->base_addr + SONIC_ISREG);
}
if (ival & ISREG_TXER) {
irqtxerr_handler(dev);
outw(ISREG_TXER, dev->base_addr + SONIC_ISREG);
}
break;
}
return IRQ_HANDLED;
}
static int ibmlana_open(struct net_device *dev)
{
int result;
ibmlana_priv *priv = netdev_priv(dev);
result = request_irq(priv->realirq, irq_handler, IRQF_SHARED,
dev->name, dev);
if (result != 0) {
printk(KERN_ERR "%s: failed to register irq %d\n", dev->name, dev->irq);
return result;
}
dev->irq = priv->realirq;
InitBoard(dev);
netif_start_queue(dev);
return 0;
}
static int ibmlana_close(struct net_device *dev)
{
if (dev->irq != 0)
free_irq(dev->irq, dev);
dev->irq = 0;
return 0;
}
static netdev_tx_t ibmlana_tx(struct sk_buff *skb, struct net_device *dev)
{
ibmlana_priv *priv = netdev_priv(dev);
int tmplen, addr;
unsigned long flags;
tda_t tda;
int baddr;
if (priv->txusedcnt >= TXBUFCNT) {
dev->stats.tx_dropped++;
goto tx_done;
}
tmplen = skb->len;
if (tmplen < 60)
tmplen = 60;
baddr = priv->txbufstart + (priv->nexttxdescr * PKTSIZE);
memcpy_toio(priv->base + baddr, skb->data, skb->len);
if (tmplen > skb->len) {
char *fill = "NetBSD is a nice OS too! ";
unsigned int destoffs = skb->len, l = strlen(fill);
while (destoffs < tmplen) {
memcpy_toio(priv->base + baddr + destoffs, fill, l);
destoffs += l;
}
}
addr = priv->tdastart + (priv->nexttxdescr * sizeof(tda_t));
memcpy_fromio(&tda, priv->base + addr, sizeof(tda_t));
tda.length = tda.fraglength = tmplen;
memcpy_toio(priv->base + addr, &tda, sizeof(tda_t));
spin_lock_irqsave(&priv->lock, flags);
priv->txusedcnt++;
priv->txused[priv->nexttxdescr] = 1;
if (priv->txusedcnt >= TXBUFCNT)
netif_stop_queue(dev);
if (priv->txusedcnt == 1)
StartTx(dev, priv->nexttxdescr);
priv->nexttxdescr = (priv->nexttxdescr + 1) % TXBUFCNT;
spin_unlock_irqrestore(&priv->lock, flags);
tx_done:
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void ibmlana_set_multicast_list(struct net_device *dev)
{
StopSONIC(dev);
InitBoard(dev);
}
static int ibmlana_init_one(struct device *kdev)
{
struct mca_device *mdev = to_mca_device(kdev);
struct net_device *dev;
int slot = mdev->slot, z, rc;
int base = 0, irq = 0, iobase = 0, memlen = 0;
ibmlana_priv *priv;
ibmlana_medium medium;
dev = alloc_etherdev(sizeof(ibmlana_priv));
if (!dev)
return -ENOMEM;
dev->irq = ibmlana_irq;
dev->base_addr = ibmlana_io;
base = dev->mem_start;
irq = dev->irq;
getaddrs(mdev, &base, &memlen, &iobase, &irq, &medium);
if (dev->irq && dev->irq != irq) {
rc = -ENODEV;
goto err_out;
}
if (dev->mem_start && dev->mem_start != base) {
rc = -ENODEV;
goto err_out;
}
printk(KERN_INFO "%s: IBM LAN Adapter/A found in slot %d\n", dev->name, slot + 1);
if (!request_region(iobase, IBM_LANA_IORANGE, DRV_NAME)) {
printk(KERN_ERR "%s: cannot allocate I/O range at %#x!\n", DRV_NAME, iobase);
startslot = slot + 1;
rc = -EBUSY;
goto err_out;
}
priv = netdev_priv(dev);
priv->slot = slot;
priv->realirq = mca_device_transform_irq(mdev, irq);
priv->medium = medium;
spin_lock_init(&priv->lock);
dev->irq = 0;
dev->mem_start = base;
dev->mem_end = base + memlen;
dev->base_addr = iobase;
priv->base = ioremap(base, memlen);
if (!priv->base) {
printk(KERN_ERR "%s: cannot remap memory!\n", DRV_NAME);
startslot = slot + 1;
rc = -EBUSY;
goto err_out_reg;
}
mca_device_set_name(mdev, ibmlana_adapter_names[mdev->index]);
mca_device_set_claim(mdev, 1);
dev->netdev_ops = &ibmlana_netdev_ops;
dev->flags |= IFF_MULTICAST;
for (z = 0; z < ETH_ALEN; z++)
dev->dev_addr[z] = inb(dev->base_addr + MACADDRPROM + z);
printk(KERN_INFO "%s: IRQ %d, I/O %#lx, memory %#lx-%#lx, "
"MAC address %pM.\n",
dev->name, priv->realirq, dev->base_addr,
dev->mem_start, dev->mem_end - 1,
dev->dev_addr);
printk(KERN_INFO "%s: %s medium\n", dev->name, MediaNames[priv->medium]);
ResetBoard(dev);
startslot = slot + 1;
rc = register_netdev(dev);
if (rc)
goto err_out_claimed;
dev_set_drvdata(kdev, dev);
return 0;
err_out_claimed:
mca_device_set_claim(mdev, 0);
iounmap(priv->base);
err_out_reg:
release_region(iobase, IBM_LANA_IORANGE);
err_out:
free_netdev(dev);
return rc;
}
static int ibmlana_remove_one(struct device *kdev)
{
struct mca_device *mdev = to_mca_device(kdev);
struct net_device *dev = dev_get_drvdata(kdev);
ibmlana_priv *priv = netdev_priv(dev);
unregister_netdev(dev);
release_region(dev->base_addr, IBM_LANA_IORANGE);
mca_device_set_claim(mdev, 0);
iounmap(priv->base);
free_netdev(dev);
return 0;
}
static int __init ibmlana_init_module(void)
{
return mca_register_driver(&ibmlana_driver);
}
static void __exit ibmlana_cleanup_module(void)
{
mca_unregister_driver(&ibmlana_driver);
}
