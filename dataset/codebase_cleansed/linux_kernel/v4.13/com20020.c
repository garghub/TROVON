static void com20020_copy_from_card(struct net_device *dev, int bufnum,
int offset, void *buf, int count)
{
int ioaddr = dev->base_addr, ofs = 512 * bufnum + offset;
arcnet_outb((ofs >> 8) | RDDATAflag | AUTOINCflag,
ioaddr, COM20020_REG_W_ADDR_HI);
arcnet_outb(ofs & 0xff, ioaddr, COM20020_REG_W_ADDR_LO);
TIME(dev, "insb", count,
arcnet_insb(ioaddr, COM20020_REG_RW_MEMDATA, buf, count));
}
static void com20020_copy_to_card(struct net_device *dev, int bufnum,
int offset, void *buf, int count)
{
int ioaddr = dev->base_addr, ofs = 512 * bufnum + offset;
arcnet_outb((ofs >> 8) | AUTOINCflag, ioaddr, COM20020_REG_W_ADDR_HI);
arcnet_outb(ofs & 0xff, ioaddr, COM20020_REG_W_ADDR_LO);
TIME(dev, "outsb", count,
arcnet_outsb(ioaddr, COM20020_REG_RW_MEMDATA, buf, count));
}
int com20020_check(struct net_device *dev)
{
int ioaddr = dev->base_addr, status;
struct arcnet_local *lp = netdev_priv(dev);
arcnet_outb(XTOcfg(3) | RESETcfg, ioaddr, COM20020_REG_W_CONFIG);
udelay(5);
arcnet_outb(XTOcfg(3), ioaddr, COM20020_REG_W_CONFIG);
mdelay(RESETtime);
lp->setup = lp->clockm ? 0 : (lp->clockp << 1);
lp->setup2 = (lp->clockm << 4) | 8;
lp->setup = lp->setup | P1MODE;
com20020_set_subaddress(lp, ioaddr, SUB_SETUP1);
arcnet_outb(lp->setup, ioaddr, COM20020_REG_W_XREG);
if (lp->clockm != 0) {
com20020_set_subaddress(lp, ioaddr, SUB_SETUP2);
arcnet_outb(lp->setup2, ioaddr, COM20020_REG_W_XREG);
mdelay(1);
arcnet_outb(STARTIOcmd, ioaddr, COM20020_REG_W_COMMAND);
}
lp->config = (lp->timeout << 3) | (lp->backplane << 2) | SUB_NODE;
arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
arcnet_outb(0x42, ioaddr, COM20020_REG_W_XREG);
status = arcnet_inb(ioaddr, COM20020_REG_R_STATUS);
if ((status & 0x99) != (NORXflag | TXFREEflag | RESETflag)) {
arc_printk(D_NORMAL, dev, "status invalid (%Xh).\n", status);
return -ENODEV;
}
arc_printk(D_INIT_REASONS, dev, "status after reset: %X\n", status);
arcnet_outb(CFLAGScmd | RESETclear | CONFIGclear,
ioaddr, COM20020_REG_W_COMMAND);
status = arcnet_inb(ioaddr, COM20020_REG_R_STATUS);
arc_printk(D_INIT_REASONS, dev, "status after reset acknowledged: %X\n",
status);
arcnet_outb(0 | RDDATAflag | AUTOINCflag,
ioaddr, COM20020_REG_W_ADDR_HI);
arcnet_outb(0, ioaddr, COM20020_REG_W_ADDR_LO);
status = arcnet_inb(ioaddr, COM20020_REG_RW_MEMDATA);
if (status != TESTvalue) {
arc_printk(D_NORMAL, dev, "Signature byte not found (%02Xh != D1h).\n",
status);
return -ENODEV;
}
return 0;
}
static int com20020_set_hwaddr(struct net_device *dev, void *addr)
{
int ioaddr = dev->base_addr;
struct arcnet_local *lp = netdev_priv(dev);
struct sockaddr *hwaddr = addr;
memcpy(dev->dev_addr, hwaddr->sa_data, 1);
com20020_set_subaddress(lp, ioaddr, SUB_NODE);
arcnet_outb(dev->dev_addr[0], ioaddr, COM20020_REG_W_XREG);
return 0;
}
static int com20020_netdev_open(struct net_device *dev)
{
int ioaddr = dev->base_addr;
struct arcnet_local *lp = netdev_priv(dev);
lp->config |= TXENcfg;
arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
return arcnet_open(dev);
}
static int com20020_netdev_close(struct net_device *dev)
{
int ioaddr = dev->base_addr;
struct arcnet_local *lp = netdev_priv(dev);
arcnet_close(dev);
lp->config &= ~TXENcfg;
arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
return 0;
}
int com20020_found(struct net_device *dev, int shared)
{
struct arcnet_local *lp;
int ioaddr = dev->base_addr;
lp = netdev_priv(dev);
lp->hw.owner = THIS_MODULE;
lp->hw.command = com20020_command;
lp->hw.status = com20020_status;
lp->hw.intmask = com20020_setmask;
lp->hw.reset = com20020_reset;
lp->hw.copy_to_card = com20020_copy_to_card;
lp->hw.copy_from_card = com20020_copy_from_card;
lp->hw.close = com20020_close;
if (!dev->dev_addr[0])
dev->dev_addr[0] = arcnet_inb(ioaddr, 8);
com20020_set_subaddress(lp, ioaddr, SUB_SETUP1);
arcnet_outb(lp->setup, ioaddr, COM20020_REG_W_XREG);
if (lp->card_flags & ARC_CAN_10MBIT) {
com20020_set_subaddress(lp, ioaddr, SUB_SETUP2);
arcnet_outb(lp->setup2, ioaddr, COM20020_REG_W_XREG);
mdelay(1);
arcnet_outb(STARTIOcmd, ioaddr, COM20020_REG_W_COMMAND);
}
lp->config = (lp->timeout << 3) | (lp->backplane << 2) | SUB_NODE;
arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
arcnet_outb(dev->dev_addr[0], ioaddr, COM20020_REG_W_XREG);
if (request_irq(dev->irq, arcnet_interrupt, shared,
"arcnet (COM20020)", dev)) {
arc_printk(D_NORMAL, dev, "Can't get IRQ %d!\n", dev->irq);
return -ENODEV;
}
arc_printk(D_NORMAL, dev, "%s: station %02Xh found at %03lXh, IRQ %d.\n",
lp->card_name, dev->dev_addr[0], dev->base_addr, dev->irq);
if (lp->backplane)
arc_printk(D_NORMAL, dev, "Using backplane mode.\n");
if (lp->timeout != 3)
arc_printk(D_NORMAL, dev, "Using extended timeout value of %d\n",
lp->timeout);
arc_printk(D_NORMAL, dev, "Using CKP %d - data rate %s\n",
lp->setup >> 1,
clockrates[3 -
((lp->setup2 & 0xF0) >> 4) +
((lp->setup & 0x0F) >> 1)]);
if (register_netdev(dev)) {
free_irq(dev->irq, dev);
return -EIO;
}
return 0;
}
static int com20020_reset(struct net_device *dev, int really_reset)
{
struct arcnet_local *lp = netdev_priv(dev);
u_int ioaddr = dev->base_addr;
u_char inbyte;
arc_printk(D_DEBUG, dev, "%s: %d: %s: dev: %p, lp: %p, dev->name: %s\n",
__FILE__, __LINE__, __func__, dev, lp, dev->name);
arc_printk(D_INIT, dev, "Resetting %s (status=%02Xh)\n",
dev->name, arcnet_inb(ioaddr, COM20020_REG_R_STATUS));
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
lp->config |= (lp->timeout << 3) | (lp->backplane << 2);
arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
if (really_reset) {
arcnet_outb(lp->config | RESETcfg, ioaddr, COM20020_REG_W_CONFIG);
udelay(5);
arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
mdelay(RESETtime * 2);
}
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
arcnet_outb(CFLAGScmd | RESETclear | CONFIGclear,
ioaddr, COM20020_REG_W_COMMAND);
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
com20020_copy_from_card(dev, 0, 0, &inbyte, 1);
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
if (inbyte != TESTvalue) {
arc_printk(D_DEBUG, dev, "%s: %d: %s\n",
__FILE__, __LINE__, __func__);
arc_printk(D_NORMAL, dev, "reset failed: TESTvalue not present.\n");
return 1;
}
arcnet_outb(CONFIGcmd | EXTconf, ioaddr, COM20020_REG_W_COMMAND);
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
return 0;
}
static void com20020_setmask(struct net_device *dev, int mask)
{
u_int ioaddr = dev->base_addr;
arc_printk(D_DURING, dev, "Setting mask to %x at %x\n", mask, ioaddr);
arcnet_outb(mask, ioaddr, COM20020_REG_W_INTMASK);
}
static void com20020_command(struct net_device *dev, int cmd)
{
u_int ioaddr = dev->base_addr;
arcnet_outb(cmd, ioaddr, COM20020_REG_W_COMMAND);
}
static int com20020_status(struct net_device *dev)
{
u_int ioaddr = dev->base_addr;
return arcnet_inb(ioaddr, COM20020_REG_R_STATUS) +
(arcnet_inb(ioaddr, COM20020_REG_R_DIAGSTAT) << 8);
}
static void com20020_close(struct net_device *dev)
{
struct arcnet_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
lp->config &= ~TXENcfg;
arcnet_outb(lp->config, ioaddr, COM20020_REG_W_CONFIG);
}
static void com20020_set_mc_list(struct net_device *dev)
{
struct arcnet_local *lp = netdev_priv(dev);
int ioaddr = dev->base_addr;
if ((dev->flags & IFF_PROMISC) && (dev->flags & IFF_UP)) {
if (!(lp->setup & PROMISCset))
arc_printk(D_NORMAL, dev, "Setting promiscuous flag...\n");
com20020_set_subaddress(lp, ioaddr, SUB_SETUP1);
lp->setup |= PROMISCset;
arcnet_outb(lp->setup, ioaddr, COM20020_REG_W_XREG);
} else {
if ((lp->setup & PROMISCset))
arc_printk(D_NORMAL, dev, "Resetting promiscuous flag...\n");
com20020_set_subaddress(lp, ioaddr, SUB_SETUP1);
lp->setup &= ~PROMISCset;
arcnet_outb(lp->setup, ioaddr, COM20020_REG_W_XREG);
}
}
static int __init com20020_module_init(void)
{
if (BUGLVL(D_NORMAL))
pr_info("%s\n", "COM20020 chipset support (by David Woodhouse et al.)");
return 0;
}
static void __exit com20020_module_exit(void)
{
}
