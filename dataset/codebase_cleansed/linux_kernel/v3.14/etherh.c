static inline void etherh_set_ctrl(struct etherh_priv *eh, unsigned char mask)
{
unsigned char ctrl = eh->ctrl | mask;
eh->ctrl = ctrl;
writeb(ctrl, eh->ctrl_port);
}
static inline void etherh_clr_ctrl(struct etherh_priv *eh, unsigned char mask)
{
unsigned char ctrl = eh->ctrl & ~mask;
eh->ctrl = ctrl;
writeb(ctrl, eh->ctrl_port);
}
static inline unsigned int etherh_get_stat(struct etherh_priv *eh)
{
return readb(eh->ctrl_port);
}
static void etherh_irq_enable(ecard_t *ec, int irqnr)
{
struct etherh_priv *eh = ec->irq_data;
etherh_set_ctrl(eh, ETHERH_CP_IE);
}
static void etherh_irq_disable(ecard_t *ec, int irqnr)
{
struct etherh_priv *eh = ec->irq_data;
etherh_clr_ctrl(eh, ETHERH_CP_IE);
}
static void
etherh_setif(struct net_device *dev)
{
struct ei_device *ei_local = netdev_priv(dev);
unsigned long flags;
void __iomem *addr;
local_irq_save(flags);
switch (etherh_priv(dev)->id) {
case PROD_I3_ETHERLAN600:
case PROD_I3_ETHERLAN600A:
addr = (void __iomem *)dev->base_addr + EN0_RCNTHI;
switch (dev->if_port) {
case IF_PORT_10BASE2:
writeb((readb(addr) & 0xf8) | 1, addr);
break;
case IF_PORT_10BASET:
writeb((readb(addr) & 0xf8), addr);
break;
}
break;
case PROD_I3_ETHERLAN500:
switch (dev->if_port) {
case IF_PORT_10BASE2:
etherh_clr_ctrl(etherh_priv(dev), ETHERH_CP_IF);
break;
case IF_PORT_10BASET:
etherh_set_ctrl(etherh_priv(dev), ETHERH_CP_IF);
break;
}
break;
default:
break;
}
local_irq_restore(flags);
}
static int
etherh_getifstat(struct net_device *dev)
{
struct ei_device *ei_local = netdev_priv(dev);
void __iomem *addr;
int stat = 0;
switch (etherh_priv(dev)->id) {
case PROD_I3_ETHERLAN600:
case PROD_I3_ETHERLAN600A:
addr = (void __iomem *)dev->base_addr + EN0_RCNTHI;
switch (dev->if_port) {
case IF_PORT_10BASE2:
stat = 1;
break;
case IF_PORT_10BASET:
stat = readb(addr) & 4;
break;
}
break;
case PROD_I3_ETHERLAN500:
switch (dev->if_port) {
case IF_PORT_10BASE2:
stat = 1;
break;
case IF_PORT_10BASET:
stat = etherh_get_stat(etherh_priv(dev)) & ETHERH_CP_HEARTBEAT;
break;
}
break;
default:
stat = 0;
break;
}
return stat != 0;
}
static int etherh_set_config(struct net_device *dev, struct ifmap *map)
{
switch (map->port) {
case IF_PORT_10BASE2:
case IF_PORT_10BASET:
dev->flags &= ~IFF_AUTOMEDIA;
dev->if_port = map->port;
break;
default:
return -EINVAL;
}
etherh_setif(dev);
return 0;
}
static void
etherh_reset(struct net_device *dev)
{
struct ei_device *ei_local = netdev_priv(dev);
void __iomem *addr = (void __iomem *)dev->base_addr;
writeb(E8390_NODMA+E8390_PAGE0+E8390_STOP, addr);
if (dev->flags & IFF_AUTOMEDIA && ei_local->interface_num) {
ei_local->interface_num = 0;
if (dev->if_port == IF_PORT_10BASET)
dev->if_port = IF_PORT_10BASE2;
else
dev->if_port = IF_PORT_10BASET;
etherh_setif(dev);
}
}
static void
etherh_block_output (struct net_device *dev, int count, const unsigned char *buf, int start_page)
{
struct ei_device *ei_local = netdev_priv(dev);
unsigned long dma_start;
void __iomem *dma_base, *addr;
if (ei_local->dmaing) {
netdev_err(dev, "DMAing conflict in etherh_block_input: "
" DMAstat %d irqlock %d\n",
ei_local->dmaing, ei_local->irqlock);
return;
}
if (count & 1 && ei_local->word16)
count++;
ei_local->dmaing = 1;
addr = (void __iomem *)dev->base_addr;
dma_base = etherh_priv(dev)->dma_base;
count = (count + 1) & ~1;
writeb (E8390_NODMA | E8390_PAGE0 | E8390_START, addr + E8390_CMD);
writeb (0x42, addr + EN0_RCNTLO);
writeb (0x00, addr + EN0_RCNTHI);
writeb (0x42, addr + EN0_RSARLO);
writeb (0x00, addr + EN0_RSARHI);
writeb (E8390_RREAD | E8390_START, addr + E8390_CMD);
udelay (1);
writeb (ENISR_RDC, addr + EN0_ISR);
writeb (count, addr + EN0_RCNTLO);
writeb (count >> 8, addr + EN0_RCNTHI);
writeb (0, addr + EN0_RSARLO);
writeb (start_page, addr + EN0_RSARHI);
writeb (E8390_RWRITE | E8390_START, addr + E8390_CMD);
if (ei_local->word16)
writesw (dma_base, buf, count >> 1);
else
writesb (dma_base, buf, count);
dma_start = jiffies;
while ((readb (addr + EN0_ISR) & ENISR_RDC) == 0)
if (time_after(jiffies, dma_start + 2*HZ/100)) {
netdev_warn(dev, "timeout waiting for TX RDC\n");
etherh_reset (dev);
__NS8390_init (dev, 1);
break;
}
writeb (ENISR_RDC, addr + EN0_ISR);
ei_local->dmaing = 0;
}
static void
etherh_block_input (struct net_device *dev, int count, struct sk_buff *skb, int ring_offset)
{
struct ei_device *ei_local = netdev_priv(dev);
unsigned char *buf;
void __iomem *dma_base, *addr;
if (ei_local->dmaing) {
netdev_err(dev, "DMAing conflict in etherh_block_input: "
" DMAstat %d irqlock %d\n",
ei_local->dmaing, ei_local->irqlock);
return;
}
ei_local->dmaing = 1;
addr = (void __iomem *)dev->base_addr;
dma_base = etherh_priv(dev)->dma_base;
buf = skb->data;
writeb (E8390_NODMA | E8390_PAGE0 | E8390_START, addr + E8390_CMD);
writeb (count, addr + EN0_RCNTLO);
writeb (count >> 8, addr + EN0_RCNTHI);
writeb (ring_offset, addr + EN0_RSARLO);
writeb (ring_offset >> 8, addr + EN0_RSARHI);
writeb (E8390_RREAD | E8390_START, addr + E8390_CMD);
if (ei_local->word16) {
readsw (dma_base, buf, count >> 1);
if (count & 1)
buf[count - 1] = readb (dma_base);
} else
readsb (dma_base, buf, count);
writeb (ENISR_RDC, addr + EN0_ISR);
ei_local->dmaing = 0;
}
static void
etherh_get_header (struct net_device *dev, struct e8390_pkt_hdr *hdr, int ring_page)
{
struct ei_device *ei_local = netdev_priv(dev);
void __iomem *dma_base, *addr;
if (ei_local->dmaing) {
netdev_err(dev, "DMAing conflict in etherh_get_header: "
" DMAstat %d irqlock %d\n",
ei_local->dmaing, ei_local->irqlock);
return;
}
ei_local->dmaing = 1;
addr = (void __iomem *)dev->base_addr;
dma_base = etherh_priv(dev)->dma_base;
writeb (E8390_NODMA | E8390_PAGE0 | E8390_START, addr + E8390_CMD);
writeb (sizeof (*hdr), addr + EN0_RCNTLO);
writeb (0, addr + EN0_RCNTHI);
writeb (0, addr + EN0_RSARLO);
writeb (ring_page, addr + EN0_RSARHI);
writeb (E8390_RREAD | E8390_START, addr + E8390_CMD);
if (ei_local->word16)
readsw (dma_base, hdr, sizeof (*hdr) >> 1);
else
readsb (dma_base, hdr, sizeof (*hdr));
writeb (ENISR_RDC, addr + EN0_ISR);
ei_local->dmaing = 0;
}
static int
etherh_open(struct net_device *dev)
{
struct ei_device *ei_local = netdev_priv(dev);
if (request_irq(dev->irq, __ei_interrupt, 0, dev->name, dev))
return -EAGAIN;
ei_local->interface_num = 0;
if (dev->flags & IFF_AUTOMEDIA) {
dev->if_port = IF_PORT_10BASET;
etherh_setif(dev);
mdelay(1);
if (!etherh_getifstat(dev)) {
dev->if_port = IF_PORT_10BASE2;
etherh_setif(dev);
}
} else
etherh_setif(dev);
etherh_reset(dev);
__ei_open(dev);
return 0;
}
static int
etherh_close(struct net_device *dev)
{
__ei_close (dev);
free_irq (dev->irq, dev);
return 0;
}
static void __init etherh_banner(void)
{
static int version_printed;
if ((etherh_msg_enable & NETIF_MSG_DRV) && (version_printed++ == 0))
pr_info("%s", version);
}
static int etherh_addr(char *addr, struct expansion_card *ec)
{
struct in_chunk_dir cd;
char *s;
if (!ecard_readchunk(&cd, ec, 0xf5, 0)) {
printk(KERN_ERR "%s: unable to read podule description string\n",
dev_name(&ec->dev));
goto no_addr;
}
s = strchr(cd.d.string, '(');
if (s) {
int i;
for (i = 0; i < 6; i++) {
addr[i] = simple_strtoul(s + 1, &s, 0x10);
if (*s != (i == 5? ')' : ':'))
break;
}
if (i == 6)
return 0;
}
printk(KERN_ERR "%s: unable to parse MAC address: %s\n",
dev_name(&ec->dev), cd.d.string);
no_addr:
return -ENODEV;
}
static int __init etherm_addr(char *addr)
{
unsigned int serial;
if (system_serial_low == 0 && system_serial_high == 0)
return -ENODEV;
serial = system_serial_low | system_serial_high;
addr[0] = 0;
addr[1] = 0;
addr[2] = 0xa4;
addr[3] = 0x10 + (serial >> 24);
addr[4] = serial >> 16;
addr[5] = serial >> 8;
return 0;
}
static void etherh_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, dev_name(dev->dev.parent),
sizeof(info->bus_info));
}
static int etherh_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
cmd->supported = etherh_priv(dev)->supported;
ethtool_cmd_speed_set(cmd, SPEED_10);
cmd->duplex = DUPLEX_HALF;
cmd->port = dev->if_port == IF_PORT_10BASET ? PORT_TP : PORT_BNC;
cmd->autoneg = (dev->flags & IFF_AUTOMEDIA ?
AUTONEG_ENABLE : AUTONEG_DISABLE);
return 0;
}
static int etherh_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
switch (cmd->autoneg) {
case AUTONEG_ENABLE:
dev->flags |= IFF_AUTOMEDIA;
break;
case AUTONEG_DISABLE:
switch (cmd->port) {
case PORT_TP:
dev->if_port = IF_PORT_10BASET;
break;
case PORT_BNC:
dev->if_port = IF_PORT_10BASE2;
break;
default:
return -EINVAL;
}
dev->flags &= ~IFF_AUTOMEDIA;
break;
default:
return -EINVAL;
}
etherh_setif(dev);
return 0;
}
static u32 etherh_get_msglevel(struct net_device *dev)
{
struct ei_device *ei_local = netdev_priv(dev);
return ei_local->msg_enable;
}
static void etherh_set_msglevel(struct net_device *dev, u32 v)
{
struct ei_device *ei_local = netdev_priv(dev);
ei_local->msg_enable = v;
}
static int
etherh_probe(struct expansion_card *ec, const struct ecard_id *id)
{
const struct etherh_data *data = id->data;
struct ei_device *ei_local;
struct net_device *dev;
struct etherh_priv *eh;
int ret;
etherh_banner();
ret = ecard_request_resources(ec);
if (ret)
goto out;
dev = ____alloc_ei_netdev(sizeof(struct etherh_priv));
if (!dev) {
ret = -ENOMEM;
goto release;
}
SET_NETDEV_DEV(dev, &ec->dev);
dev->netdev_ops = &etherh_netdev_ops;
dev->irq = ec->irq;
dev->ethtool_ops = &etherh_ethtool_ops;
if (data->supported & SUPPORTED_Autoneg)
dev->flags |= IFF_AUTOMEDIA;
if (data->supported & SUPPORTED_TP) {
dev->flags |= IFF_PORTSEL;
dev->if_port = IF_PORT_10BASET;
} else if (data->supported & SUPPORTED_BNC) {
dev->flags |= IFF_PORTSEL;
dev->if_port = IF_PORT_10BASE2;
} else
dev->if_port = IF_PORT_UNKNOWN;
eh = etherh_priv(dev);
eh->supported = data->supported;
eh->ctrl = 0;
eh->id = ec->cid.product;
eh->memc = ecardm_iomap(ec, ECARD_RES_MEMC, 0, PAGE_SIZE);
if (!eh->memc) {
ret = -ENOMEM;
goto free;
}
eh->ctrl_port = eh->memc;
if (data->ctrl_ioc) {
eh->ioc_fast = ecardm_iomap(ec, ECARD_RES_IOCFAST, 0, PAGE_SIZE);
if (!eh->ioc_fast) {
ret = -ENOMEM;
goto free;
}
eh->ctrl_port = eh->ioc_fast;
}
dev->base_addr = (unsigned long)eh->memc + data->ns8390_offset;
eh->dma_base = eh->memc + data->dataport_offset;
eh->ctrl_port += data->ctrlport_offset;
if (ec->slot_no != 8) {
ecard_setirq(ec, &etherh_ops, eh);
} else {
etherh_set_ctrl(eh, ETHERH_CP_IE);
}
ei_local = netdev_priv(dev);
spin_lock_init(&ei_local->page_lock);
if (ec->cid.product == PROD_ANT_ETHERM) {
etherm_addr(dev->dev_addr);
ei_local->reg_offset = etherm_regoffsets;
} else {
etherh_addr(dev->dev_addr, ec);
ei_local->reg_offset = etherh_regoffsets;
}
ei_local->name = dev->name;
ei_local->word16 = 1;
ei_local->tx_start_page = data->tx_start_page;
ei_local->rx_start_page = ei_local->tx_start_page + TX_PAGES;
ei_local->stop_page = data->stop_page;
ei_local->reset_8390 = etherh_reset;
ei_local->block_input = etherh_block_input;
ei_local->block_output = etherh_block_output;
ei_local->get_8390_hdr = etherh_get_header;
ei_local->interface_num = 0;
ei_local->msg_enable = etherh_msg_enable;
etherh_reset(dev);
__NS8390_init(dev, 0);
ret = register_netdev(dev);
if (ret)
goto free;
netdev_info(dev, "%s in slot %d, %pM\n",
data->name, ec->slot_no, dev->dev_addr);
ecard_set_drvdata(ec, dev);
return 0;
free:
free_netdev(dev);
release:
ecard_release_resources(ec);
out:
return ret;
}
static void etherh_remove(struct expansion_card *ec)
{
struct net_device *dev = ecard_get_drvdata(ec);
ecard_set_drvdata(ec, NULL);
unregister_netdev(dev);
free_netdev(dev);
ecard_release_resources(ec);
}
static int __init etherh_init(void)
{
int i;
for (i = 0; i < 16; i++) {
etherh_regoffsets[i] = i << 2;
etherm_regoffsets[i] = i << 5;
}
return ecard_register_driver(&etherh_driver);
}
static void __exit etherh_exit(void)
{
ecard_remove_driver(&etherh_driver);
}
