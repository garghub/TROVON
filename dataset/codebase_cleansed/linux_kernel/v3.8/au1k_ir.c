static void au1k_irda_plat_set_phy_mode(struct au1k_private *p, int mode)
{
if (p->platdata && p->platdata->set_phy_mode)
p->platdata->set_phy_mode(mode);
}
static inline unsigned long irda_read(struct au1k_private *p,
unsigned long ofs)
{
(void)__raw_readl(p->iobase + ofs);
return __raw_readl(p->iobase + ofs);
}
static inline void irda_write(struct au1k_private *p, unsigned long ofs,
unsigned long val)
{
__raw_writel(val, p->iobase + ofs);
wmb();
}
static struct db_dest *GetFreeDB(struct au1k_private *aup)
{
struct db_dest *db;
db = aup->pDBfree;
if (db)
aup->pDBfree = db->pnext;
return db;
}
static void *dma_alloc(size_t size, dma_addr_t *dma_handle)
{
void *ret;
int gfp = GFP_ATOMIC | GFP_DMA;
ret = (void *)__get_free_pages(gfp, get_order(size));
if (ret != NULL) {
memset(ret, 0, size);
*dma_handle = virt_to_bus(ret);
ret = (void *)KSEG0ADDR(ret);
}
return ret;
}
static void dma_free(void *vaddr, size_t size)
{
vaddr = (void *)KSEG0ADDR(vaddr);
free_pages((unsigned long) vaddr, get_order(size));
}
static void setup_hw_rings(struct au1k_private *aup, u32 rx_base, u32 tx_base)
{
int i;
for (i = 0; i < NUM_IR_DESC; i++) {
aup->rx_ring[i] = (volatile struct ring_dest *)
(rx_base + sizeof(struct ring_dest) * i);
}
for (i = 0; i < NUM_IR_DESC; i++) {
aup->tx_ring[i] = (volatile struct ring_dest *)
(tx_base + sizeof(struct ring_dest) * i);
}
}
static int au1k_irda_init_iobuf(iobuff_t *io, int size)
{
io->head = kmalloc(size, GFP_KERNEL);
if (io->head != NULL) {
io->truesize = size;
io->in_frame = FALSE;
io->state = OUTSIDE_FRAME;
io->data = io->head;
}
return io->head ? 0 : -ENOMEM;
}
static int au1k_irda_set_speed(struct net_device *dev, int speed)
{
struct au1k_private *aup = netdev_priv(dev);
volatile struct ring_dest *ptxd;
unsigned long control;
int ret = 0, timeout = 10, i;
if (speed == aup->speed)
return ret;
au1k_irda_plat_set_phy_mode(aup, AU1000_IRDA_PHY_MODE_OFF);
irda_write(aup, IR_STATUS, irda_read(aup, IR_STATUS) & ~IR_PHYEN);
irda_write(aup, IR_CONFIG_1,
irda_read(aup, IR_CONFIG_1) & ~(IR_RX_ENABLE | IR_TX_ENABLE));
msleep(20);
while (irda_read(aup, IR_STATUS) & (IR_RX_STATUS | IR_TX_STATUS)) {
msleep(20);
if (!timeout--) {
printk(KERN_ERR "%s: rx/tx disable timeout\n",
dev->name);
break;
}
}
irda_write(aup, IR_CONFIG_1,
irda_read(aup, IR_CONFIG_1) & ~IR_DMA_ENABLE);
msleep(20);
aup->tx_head = aup->tx_tail = aup->rx_head = 0;
for (i = 0; i < NUM_IR_DESC; i++) {
ptxd = aup->tx_ring[i];
ptxd->flags = 0;
ptxd->count_0 = 0;
ptxd->count_1 = 0;
}
for (i = 0; i < NUM_IR_DESC; i++) {
ptxd = aup->rx_ring[i];
ptxd->count_0 = 0;
ptxd->count_1 = 0;
ptxd->flags = AU_OWN;
}
if (speed == 4000000)
au1k_irda_plat_set_phy_mode(aup, AU1000_IRDA_PHY_MODE_FIR);
else
au1k_irda_plat_set_phy_mode(aup, AU1000_IRDA_PHY_MODE_SIR);
switch (speed) {
case 9600:
irda_write(aup, IR_WRITE_PHY_CONFIG, IR_BR(11) | IR_PW(12));
irda_write(aup, IR_CONFIG_1, IR_SIR_MODE);
break;
case 19200:
irda_write(aup, IR_WRITE_PHY_CONFIG, IR_BR(5) | IR_PW(12));
irda_write(aup, IR_CONFIG_1, IR_SIR_MODE);
break;
case 38400:
irda_write(aup, IR_WRITE_PHY_CONFIG, IR_BR(2) | IR_PW(12));
irda_write(aup, IR_CONFIG_1, IR_SIR_MODE);
break;
case 57600:
irda_write(aup, IR_WRITE_PHY_CONFIG, IR_BR(1) | IR_PW(12));
irda_write(aup, IR_CONFIG_1, IR_SIR_MODE);
break;
case 115200:
irda_write(aup, IR_WRITE_PHY_CONFIG, IR_PW(12));
irda_write(aup, IR_CONFIG_1, IR_SIR_MODE);
break;
case 4000000:
irda_write(aup, IR_WRITE_PHY_CONFIG, IR_P(15));
irda_write(aup, IR_CONFIG_1, IR_FIR | IR_DMA_ENABLE |
IR_RX_ENABLE);
break;
default:
printk(KERN_ERR "%s unsupported speed %x\n", dev->name, speed);
ret = -EINVAL;
break;
}
aup->speed = speed;
irda_write(aup, IR_STATUS, irda_read(aup, IR_STATUS) | IR_PHYEN);
control = irda_read(aup, IR_STATUS);
irda_write(aup, IR_RING_PROMPT, 0);
if (control & (1 << 14)) {
printk(KERN_ERR "%s: configuration error\n", dev->name);
} else {
if (control & (1 << 11))
printk(KERN_DEBUG "%s Valid SIR config\n", dev->name);
if (control & (1 << 12))
printk(KERN_DEBUG "%s Valid MIR config\n", dev->name);
if (control & (1 << 13))
printk(KERN_DEBUG "%s Valid FIR config\n", dev->name);
if (control & (1 << 10))
printk(KERN_DEBUG "%s TX enabled\n", dev->name);
if (control & (1 << 9))
printk(KERN_DEBUG "%s RX enabled\n", dev->name);
}
return ret;
}
static void update_rx_stats(struct net_device *dev, u32 status, u32 count)
{
struct net_device_stats *ps = &dev->stats;
ps->rx_packets++;
if (status & IR_RX_ERROR) {
ps->rx_errors++;
if (status & (IR_PHY_ERROR | IR_FIFO_OVER))
ps->rx_missed_errors++;
if (status & IR_MAX_LEN)
ps->rx_length_errors++;
if (status & IR_CRC_ERROR)
ps->rx_crc_errors++;
} else
ps->rx_bytes += count;
}
static void update_tx_stats(struct net_device *dev, u32 status, u32 pkt_len)
{
struct net_device_stats *ps = &dev->stats;
ps->tx_packets++;
ps->tx_bytes += pkt_len;
if (status & IR_TX_ERROR) {
ps->tx_errors++;
ps->tx_aborted_errors++;
}
}
static void au1k_tx_ack(struct net_device *dev)
{
struct au1k_private *aup = netdev_priv(dev);
volatile struct ring_dest *ptxd;
ptxd = aup->tx_ring[aup->tx_tail];
while (!(ptxd->flags & AU_OWN) && (aup->tx_tail != aup->tx_head)) {
update_tx_stats(dev, ptxd->flags,
(ptxd->count_1 << 8) | ptxd->count_0);
ptxd->count_0 = 0;
ptxd->count_1 = 0;
wmb();
aup->tx_tail = (aup->tx_tail + 1) & (NUM_IR_DESC - 1);
ptxd = aup->tx_ring[aup->tx_tail];
if (aup->tx_full) {
aup->tx_full = 0;
netif_wake_queue(dev);
}
}
if (aup->tx_tail == aup->tx_head) {
if (aup->newspeed) {
au1k_irda_set_speed(dev, aup->newspeed);
aup->newspeed = 0;
} else {
irda_write(aup, IR_CONFIG_1,
irda_read(aup, IR_CONFIG_1) & ~IR_TX_ENABLE);
irda_write(aup, IR_CONFIG_1,
irda_read(aup, IR_CONFIG_1) | IR_RX_ENABLE);
irda_write(aup, IR_RING_PROMPT, 0);
}
}
}
static int au1k_irda_rx(struct net_device *dev)
{
struct au1k_private *aup = netdev_priv(dev);
volatile struct ring_dest *prxd;
struct sk_buff *skb;
struct db_dest *pDB;
u32 flags, count;
prxd = aup->rx_ring[aup->rx_head];
flags = prxd->flags;
while (!(flags & AU_OWN)) {
pDB = aup->rx_db_inuse[aup->rx_head];
count = (prxd->count_1 << 8) | prxd->count_0;
if (!(flags & IR_RX_ERROR)) {
update_rx_stats(dev, flags, count);
skb = alloc_skb(count + 1, GFP_ATOMIC);
if (skb == NULL) {
dev->stats.rx_dropped++;
continue;
}
skb_reserve(skb, 1);
if (aup->speed == 4000000)
skb_put(skb, count);
else
skb_put(skb, count - 2);
skb_copy_to_linear_data(skb, (void *)pDB->vaddr,
count - 2);
skb->dev = dev;
skb_reset_mac_header(skb);
skb->protocol = htons(ETH_P_IRDA);
netif_rx(skb);
prxd->count_0 = 0;
prxd->count_1 = 0;
}
prxd->flags |= AU_OWN;
aup->rx_head = (aup->rx_head + 1) & (NUM_IR_DESC - 1);
irda_write(aup, IR_RING_PROMPT, 0);
prxd = aup->rx_ring[aup->rx_head];
flags = prxd->flags;
}
return 0;
}
static irqreturn_t au1k_irda_interrupt(int dummy, void *dev_id)
{
struct net_device *dev = dev_id;
struct au1k_private *aup = netdev_priv(dev);
irda_write(aup, IR_INT_CLEAR, 0);
au1k_irda_rx(dev);
au1k_tx_ack(dev);
return IRQ_HANDLED;
}
static int au1k_init(struct net_device *dev)
{
struct au1k_private *aup = netdev_priv(dev);
u32 enable, ring_address;
int i;
enable = IR_HC | IR_CE | IR_C;
#ifndef CONFIG_CPU_LITTLE_ENDIAN
enable |= IR_BE;
#endif
aup->tx_head = 0;
aup->tx_tail = 0;
aup->rx_head = 0;
for (i = 0; i < NUM_IR_DESC; i++)
aup->rx_ring[i]->flags = AU_OWN;
irda_write(aup, IR_ENABLE, enable);
msleep(20);
au1k_irda_plat_set_phy_mode(aup, AU1000_IRDA_PHY_MODE_OFF);
irda_write(aup, IR_STATUS, irda_read(aup, IR_STATUS) & ~IR_PHYEN);
msleep(20);
irda_write(aup, IR_MAX_PKT_LEN, MAX_BUF_SIZE);
ring_address = (u32)virt_to_phys((void *)aup->rx_ring[0]);
irda_write(aup, IR_RING_BASE_ADDR_H, ring_address >> 26);
irda_write(aup, IR_RING_BASE_ADDR_L, (ring_address >> 10) & 0xffff);
irda_write(aup, IR_RING_SIZE,
(RING_SIZE_64 << 8) | (RING_SIZE_64 << 12));
irda_write(aup, IR_CONFIG_2, IR_PHYCLK_48MHZ | IR_ONE_PIN);
irda_write(aup, IR_RING_ADDR_CMPR, 0);
au1k_irda_set_speed(dev, 9600);
return 0;
}
static int au1k_irda_start(struct net_device *dev)
{
struct au1k_private *aup = netdev_priv(dev);
char hwname[32];
int retval;
retval = au1k_init(dev);
if (retval) {
printk(KERN_ERR "%s: error in au1k_init\n", dev->name);
return retval;
}
retval = request_irq(aup->irq_tx, &au1k_irda_interrupt, 0,
dev->name, dev);
if (retval) {
printk(KERN_ERR "%s: unable to get IRQ %d\n",
dev->name, dev->irq);
return retval;
}
retval = request_irq(aup->irq_rx, &au1k_irda_interrupt, 0,
dev->name, dev);
if (retval) {
free_irq(aup->irq_tx, dev);
printk(KERN_ERR "%s: unable to get IRQ %d\n",
dev->name, dev->irq);
return retval;
}
sprintf(hwname, "Au1000 SIR/FIR");
aup->irlap = irlap_open(dev, &aup->qos, hwname);
netif_start_queue(dev);
irda_write(aup, IR_CONFIG_2, irda_read(aup, IR_CONFIG_2) | IR_IEN);
au1k_irda_plat_set_phy_mode(aup, AU1000_IRDA_PHY_MODE_SIR);
aup->timer.expires = RUN_AT((3 * HZ));
aup->timer.data = (unsigned long)dev;
return 0;
}
static int au1k_irda_stop(struct net_device *dev)
{
struct au1k_private *aup = netdev_priv(dev);
au1k_irda_plat_set_phy_mode(aup, AU1000_IRDA_PHY_MODE_OFF);
irda_write(aup, IR_CONFIG_2, irda_read(aup, IR_CONFIG_2) & ~IR_IEN);
irda_write(aup, IR_CONFIG_1, 0);
irda_write(aup, IR_ENABLE, 0);
if (aup->irlap) {
irlap_close(aup->irlap);
aup->irlap = NULL;
}
netif_stop_queue(dev);
del_timer(&aup->timer);
free_irq(aup->irq_tx, dev);
free_irq(aup->irq_rx, dev);
return 0;
}
static int au1k_irda_hard_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct au1k_private *aup = netdev_priv(dev);
int speed = irda_get_next_speed(skb);
volatile struct ring_dest *ptxd;
struct db_dest *pDB;
u32 len, flags;
if (speed != aup->speed && speed != -1)
aup->newspeed = speed;
if ((skb->len == 0) && (aup->newspeed)) {
if (aup->tx_tail == aup->tx_head) {
au1k_irda_set_speed(dev, speed);
aup->newspeed = 0;
}
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
ptxd = aup->tx_ring[aup->tx_head];
flags = ptxd->flags;
if (flags & AU_OWN) {
printk(KERN_DEBUG "%s: tx_full\n", dev->name);
netif_stop_queue(dev);
aup->tx_full = 1;
return 1;
} else if (((aup->tx_head + 1) & (NUM_IR_DESC - 1)) == aup->tx_tail) {
printk(KERN_DEBUG "%s: tx_full\n", dev->name);
netif_stop_queue(dev);
aup->tx_full = 1;
return 1;
}
pDB = aup->tx_db_inuse[aup->tx_head];
#if 0
if (irda_read(aup, IR_RX_BYTE_CNT) != 0) {
printk(KERN_DEBUG "tx warning: rx byte cnt %x\n",
irda_read(aup, IR_RX_BYTE_CNT));
}
#endif
if (aup->speed == 4000000) {
skb_copy_from_linear_data(skb, (void *)pDB->vaddr, skb->len);
ptxd->count_0 = skb->len & 0xff;
ptxd->count_1 = (skb->len >> 8) & 0xff;
} else {
len = async_wrap_skb(skb, (u8 *)pDB->vaddr, MAX_BUF_SIZE);
ptxd->count_0 = len & 0xff;
ptxd->count_1 = (len >> 8) & 0xff;
ptxd->flags |= IR_DIS_CRC;
}
ptxd->flags |= AU_OWN;
wmb();
irda_write(aup, IR_CONFIG_1,
irda_read(aup, IR_CONFIG_1) | IR_TX_ENABLE);
irda_write(aup, IR_RING_PROMPT, 0);
dev_kfree_skb(skb);
aup->tx_head = (aup->tx_head + 1) & (NUM_IR_DESC - 1);
return NETDEV_TX_OK;
}
static void au1k_tx_timeout(struct net_device *dev)
{
u32 speed;
struct au1k_private *aup = netdev_priv(dev);
printk(KERN_ERR "%s: tx timeout\n", dev->name);
speed = aup->speed;
aup->speed = 0;
au1k_irda_set_speed(dev, speed);
aup->tx_full = 0;
netif_wake_queue(dev);
}
static int au1k_irda_ioctl(struct net_device *dev, struct ifreq *ifreq, int cmd)
{
struct if_irda_req *rq = (struct if_irda_req *)ifreq;
struct au1k_private *aup = netdev_priv(dev);
int ret = -EOPNOTSUPP;
switch (cmd) {
case SIOCSBANDWIDTH:
if (capable(CAP_NET_ADMIN)) {
if (aup->open)
ret = au1k_irda_set_speed(dev,
rq->ifr_baudrate);
else {
printk(KERN_ERR "%s ioctl: !netif_running\n",
dev->name);
ret = 0;
}
}
break;
case SIOCSMEDIABUSY:
ret = -EPERM;
if (capable(CAP_NET_ADMIN)) {
irda_device_set_media_busy(dev, TRUE);
ret = 0;
}
break;
case SIOCGRECEIVING:
rq->ifr_receiving = 0;
break;
default:
break;
}
return ret;
}
static int au1k_irda_net_init(struct net_device *dev)
{
struct au1k_private *aup = netdev_priv(dev);
struct db_dest *pDB, *pDBfree;
int i, err, retval = 0;
dma_addr_t temp;
err = au1k_irda_init_iobuf(&aup->rx_buff, 14384);
if (err)
goto out1;
dev->netdev_ops = &au1k_irda_netdev_ops;
irda_init_max_qos_capabilies(&aup->qos);
aup->qos.baud_rate.bits = IR_9600 | IR_19200 | IR_38400 |
IR_57600 | IR_115200 | IR_576000 | (IR_4000000 << 8);
aup->qos.min_turn_time.bits = qos_mtt_bits;
irda_qos_bits_to_value(&aup->qos);
retval = -ENOMEM;
aup->rx_ring[0] = (struct ring_dest *)
dma_alloc(2 * MAX_NUM_IR_DESC * (sizeof(struct ring_dest)),
&temp);
if (!aup->rx_ring[0])
goto out2;
aup->db[0].vaddr =
dma_alloc(MAX_BUF_SIZE * 2 * NUM_IR_DESC, &temp);
if (!aup->db[0].vaddr)
goto out3;
setup_hw_rings(aup, (u32)aup->rx_ring[0], (u32)aup->rx_ring[0] + 512);
pDBfree = NULL;
pDB = aup->db;
for (i = 0; i < (2 * NUM_IR_DESC); i++) {
pDB->pnext = pDBfree;
pDBfree = pDB;
pDB->vaddr =
(u32 *)((unsigned)aup->db[0].vaddr + (MAX_BUF_SIZE * i));
pDB->dma_addr = (dma_addr_t)virt_to_bus(pDB->vaddr);
pDB++;
}
aup->pDBfree = pDBfree;
for (i = 0; i < NUM_IR_DESC; i++) {
pDB = GetFreeDB(aup);
if (!pDB)
goto out3;
aup->rx_ring[i]->addr_0 = (u8)(pDB->dma_addr & 0xff);
aup->rx_ring[i]->addr_1 = (u8)((pDB->dma_addr >> 8) & 0xff);
aup->rx_ring[i]->addr_2 = (u8)((pDB->dma_addr >> 16) & 0xff);
aup->rx_ring[i]->addr_3 = (u8)((pDB->dma_addr >> 24) & 0xff);
aup->rx_db_inuse[i] = pDB;
}
for (i = 0; i < NUM_IR_DESC; i++) {
pDB = GetFreeDB(aup);
if (!pDB)
goto out3;
aup->tx_ring[i]->addr_0 = (u8)(pDB->dma_addr & 0xff);
aup->tx_ring[i]->addr_1 = (u8)((pDB->dma_addr >> 8) & 0xff);
aup->tx_ring[i]->addr_2 = (u8)((pDB->dma_addr >> 16) & 0xff);
aup->tx_ring[i]->addr_3 = (u8)((pDB->dma_addr >> 24) & 0xff);
aup->tx_ring[i]->count_0 = 0;
aup->tx_ring[i]->count_1 = 0;
aup->tx_ring[i]->flags = 0;
aup->tx_db_inuse[i] = pDB;
}
return 0;
out3:
dma_free((void *)aup->rx_ring[0],
2 * MAX_NUM_IR_DESC * (sizeof(struct ring_dest)));
out2:
kfree(aup->rx_buff.head);
out1:
printk(KERN_ERR "au1k_irda_net_init() failed. Returns %d\n", retval);
return retval;
}
static int au1k_irda_probe(struct platform_device *pdev)
{
struct au1k_private *aup;
struct net_device *dev;
struct resource *r;
int err;
dev = alloc_irdadev(sizeof(struct au1k_private));
if (!dev)
return -ENOMEM;
aup = netdev_priv(dev);
aup->platdata = pdev->dev.platform_data;
err = -EINVAL;
r = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!r)
goto out;
aup->irq_tx = r->start;
r = platform_get_resource(pdev, IORESOURCE_IRQ, 1);
if (!r)
goto out;
aup->irq_rx = r->start;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r)
goto out;
err = -EBUSY;
aup->ioarea = request_mem_region(r->start, r->end - r->start + 1,
pdev->name);
if (!aup->ioarea)
goto out;
aup->iobase = ioremap_nocache(r->start, r->end - r->start + 1);
if (!aup->iobase)
goto out2;
dev->irq = aup->irq_rx;
err = au1k_irda_net_init(dev);
if (err)
goto out3;
err = register_netdev(dev);
if (err)
goto out4;
platform_set_drvdata(pdev, dev);
printk(KERN_INFO "IrDA: Registered device %s\n", dev->name);
return 0;
out4:
dma_free((void *)aup->db[0].vaddr,
MAX_BUF_SIZE * 2 * NUM_IR_DESC);
dma_free((void *)aup->rx_ring[0],
2 * MAX_NUM_IR_DESC * (sizeof(struct ring_dest)));
kfree(aup->rx_buff.head);
out3:
iounmap(aup->iobase);
out2:
release_resource(aup->ioarea);
kfree(aup->ioarea);
out:
free_netdev(dev);
return err;
}
static int au1k_irda_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct au1k_private *aup = netdev_priv(dev);
unregister_netdev(dev);
dma_free((void *)aup->db[0].vaddr,
MAX_BUF_SIZE * 2 * NUM_IR_DESC);
dma_free((void *)aup->rx_ring[0],
2 * MAX_NUM_IR_DESC * (sizeof(struct ring_dest)));
kfree(aup->rx_buff.head);
iounmap(aup->iobase);
release_resource(aup->ioarea);
kfree(aup->ioarea);
free_netdev(dev);
return 0;
}
static int __init au1k_irda_load(void)
{
return platform_driver_register(&au1k_irda_driver);
}
static void __exit au1k_irda_unload(void)
{
return platform_driver_unregister(&au1k_irda_driver);
}
