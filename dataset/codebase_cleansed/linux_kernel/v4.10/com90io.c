static u_char get_buffer_byte(struct net_device *dev, unsigned offset)
{
int ioaddr = dev->base_addr;
arcnet_outb(offset >> 8, ioaddr, COM9026_REG_W_ADDR_HI);
arcnet_outb(offset & 0xff, ioaddr, COM9026_REG_W_ADDR_LO);
return arcnet_inb(ioaddr, COM9026_REG_RW_MEMDATA);
}
static void put_buffer_byte(struct net_device *dev, unsigned offset,
u_char datum)
{
int ioaddr = dev->base_addr;
arcnet_outb(offset >> 8, ioaddr, COM9026_REG_W_ADDR_HI);
arcnet_outb(offset & 0xff, ioaddr, COM9026_REG_W_ADDR_LO);
arcnet_outb(datum, ioaddr, COM9026_REG_RW_MEMDATA);
}
static void get_whole_buffer(struct net_device *dev, unsigned offset,
unsigned length, char *dest)
{
int ioaddr = dev->base_addr;
arcnet_outb((offset >> 8) | AUTOINCflag, ioaddr, COM9026_REG_W_ADDR_HI);
arcnet_outb(offset & 0xff, ioaddr, COM9026_REG_W_ADDR_LO);
while (length--)
#ifdef ONE_AT_A_TIME_RX
*(dest++) = get_buffer_byte(dev, offset++);
#else
*(dest++) = arcnet_inb(ioaddr, COM9026_REG_RW_MEMDATA);
#endif
}
static void put_whole_buffer(struct net_device *dev, unsigned offset,
unsigned length, char *dest)
{
int ioaddr = dev->base_addr;
arcnet_outb((offset >> 8) | AUTOINCflag, ioaddr, COM9026_REG_W_ADDR_HI);
arcnet_outb(offset & 0xff, ioaddr,COM9026_REG_W_ADDR_LO);
while (length--)
#ifdef ONE_AT_A_TIME_TX
put_buffer_byte(dev, offset++, *(dest++));
#else
arcnet_outb(*(dest++), ioaddr, COM9026_REG_RW_MEMDATA);
#endif
}
static int __init com90io_probe(struct net_device *dev)
{
int ioaddr = dev->base_addr, status;
unsigned long airqmask;
if (BUGLVL(D_NORMAL)) {
pr_info("%s\n", "COM90xx IO-mapped mode support (by David Woodhouse et el.)");
pr_info("E-mail me if you actually test this driver, please!\n");
}
if (!ioaddr) {
arc_printk(D_NORMAL, dev, "No autoprobe for IO mapped cards; you must specify the base address!\n");
return -ENODEV;
}
if (!request_region(ioaddr, ARCNET_TOTAL_SIZE, "com90io probe")) {
arc_printk(D_INIT_REASONS, dev, "IO request_region %x-%x failed\n",
ioaddr, ioaddr + ARCNET_TOTAL_SIZE - 1);
return -ENXIO;
}
if (arcnet_inb(ioaddr, COM9026_REG_R_STATUS) == 0xFF) {
arc_printk(D_INIT_REASONS, dev, "IO address %x empty\n",
ioaddr);
goto err_out;
}
arcnet_inb(ioaddr, COM9026_REG_R_RESET);
mdelay(RESETtime);
status = arcnet_inb(ioaddr, COM9026_REG_R_STATUS);
if ((status & 0x9D) != (NORXflag | RECONflag | TXFREEflag | RESETflag)) {
arc_printk(D_INIT_REASONS, dev, "Status invalid (%Xh)\n",
status);
goto err_out;
}
arc_printk(D_INIT_REASONS, dev, "Status after reset: %X\n", status);
arcnet_outb(CFLAGScmd | RESETclear | CONFIGclear,
ioaddr, COM9026_REG_W_COMMAND);
arc_printk(D_INIT_REASONS, dev, "Status after reset acknowledged: %X\n",
status);
status = arcnet_inb(ioaddr, COM9026_REG_R_STATUS);
if (status & RESETflag) {
arc_printk(D_INIT_REASONS, dev, "Eternal reset (status=%Xh)\n",
status);
goto err_out;
}
arcnet_outb((0x16 | IOMAPflag) & ~ENABLE16flag,
ioaddr, COM9026_REG_RW_CONFIG);
arcnet_outb(AUTOINCflag, ioaddr, COM9026_REG_W_ADDR_HI);
arcnet_outb(0, ioaddr, COM9026_REG_W_ADDR_LO);
status = arcnet_inb(ioaddr, COM9026_REG_RW_MEMDATA);
if (status != 0xd1) {
arc_printk(D_INIT_REASONS, dev, "Signature byte not found (%Xh instead).\n",
status);
goto err_out;
}
if (!dev->irq) {
airqmask = probe_irq_on();
arcnet_outb(NORXflag, ioaddr, COM9026_REG_W_INTMASK);
udelay(1);
arcnet_outb(0, ioaddr, COM9026_REG_W_INTMASK);
dev->irq = probe_irq_off(airqmask);
if ((int)dev->irq <= 0) {
arc_printk(D_INIT_REASONS, dev, "Autoprobe IRQ failed\n");
goto err_out;
}
}
release_region(ioaddr, ARCNET_TOTAL_SIZE);
return com90io_found(dev);
err_out:
release_region(ioaddr, ARCNET_TOTAL_SIZE);
return -ENODEV;
}
static int __init com90io_found(struct net_device *dev)
{
struct arcnet_local *lp;
int ioaddr = dev->base_addr;
int err;
if (request_irq(dev->irq, arcnet_interrupt, 0,
"arcnet (COM90xx-IO)", dev)) {
arc_printk(D_NORMAL, dev, "Can't get IRQ %d!\n", dev->irq);
return -ENODEV;
}
if (!request_region(dev->base_addr, ARCNET_TOTAL_SIZE,
"arcnet (COM90xx-IO)")) {
free_irq(dev->irq, dev);
return -EBUSY;
}
lp = netdev_priv(dev);
lp->card_name = "COM90xx I/O";
lp->hw.command = com90io_command;
lp->hw.status = com90io_status;
lp->hw.intmask = com90io_setmask;
lp->hw.reset = com90io_reset;
lp->hw.owner = THIS_MODULE;
lp->hw.copy_to_card = com90io_copy_to_card;
lp->hw.copy_from_card = com90io_copy_from_card;
lp->config = (0x16 | IOMAPflag) & ~ENABLE16flag;
arcnet_outb(lp->config, ioaddr, COM9026_REG_RW_CONFIG);
dev->dev_addr[0] = get_buffer_byte(dev, 1);
err = register_netdev(dev);
if (err) {
arcnet_outb(arcnet_inb(ioaddr, COM9026_REG_RW_CONFIG) & ~IOMAPflag,
ioaddr, COM9026_REG_RW_CONFIG);
free_irq(dev->irq, dev);
release_region(dev->base_addr, ARCNET_TOTAL_SIZE);
return err;
}
arc_printk(D_NORMAL, dev, "COM90IO: station %02Xh found at %03lXh, IRQ %d.\n",
dev->dev_addr[0], dev->base_addr, dev->irq);
return 0;
}
static int com90io_reset(struct net_device *dev, int really_reset)
{
struct arcnet_local *lp = netdev_priv(dev);
short ioaddr = dev->base_addr;
arc_printk(D_INIT, dev, "Resetting %s (status=%02Xh)\n",
dev->name, arcnet_inb(ioaddr, COM9026_REG_R_STATUS));
if (really_reset) {
arcnet_inb(ioaddr, COM9026_REG_R_RESET);
mdelay(RESETtime);
}
lp->config = (0x1C | IOMAPflag) & ~ENABLE16flag;
arcnet_outb(lp->config, ioaddr, COM9026_REG_RW_CONFIG);
arcnet_outb(CFLAGScmd | RESETclear, ioaddr, COM9026_REG_W_COMMAND);
arcnet_outb(CFLAGScmd | CONFIGclear, ioaddr, COM9026_REG_W_COMMAND);
if (get_buffer_byte(dev, 0) != TESTvalue) {
arc_printk(D_NORMAL, dev, "reset failed: TESTvalue not present.\n");
return 1;
}
arcnet_outb(CONFIGcmd | EXTconf, ioaddr, COM9026_REG_W_COMMAND);
return 0;
}
static void com90io_command(struct net_device *dev, int cmd)
{
short ioaddr = dev->base_addr;
arcnet_outb(cmd, ioaddr, COM9026_REG_W_COMMAND);
}
static int com90io_status(struct net_device *dev)
{
short ioaddr = dev->base_addr;
return arcnet_inb(ioaddr, COM9026_REG_R_STATUS);
}
static void com90io_setmask(struct net_device *dev, int mask)
{
short ioaddr = dev->base_addr;
arcnet_outb(mask, ioaddr, COM9026_REG_W_INTMASK);
}
static void com90io_copy_to_card(struct net_device *dev, int bufnum,
int offset, void *buf, int count)
{
TIME(dev, "put_whole_buffer", count,
put_whole_buffer(dev, bufnum * 512 + offset, count, buf));
}
static void com90io_copy_from_card(struct net_device *dev, int bufnum,
int offset, void *buf, int count)
{
TIME(dev, "get_whole_buffer", count,
get_whole_buffer(dev, bufnum * 512 + offset, count, buf));
}
static int __init com90io_setup(char *s)
{
int ints[4];
s = get_options(s, 4, ints);
if (!ints[0])
return 0;
switch (ints[0]) {
default:
pr_err("Too many arguments\n");
case 2:
irq = ints[2];
case 1:
io = ints[1];
}
if (*s)
snprintf(device, sizeof(device), "%s", s);
return 1;
}
static int __init com90io_init(void)
{
struct net_device *dev;
int err;
dev = alloc_arcdev(device);
if (!dev)
return -ENOMEM;
dev->base_addr = io;
dev->irq = irq;
if (dev->irq == 2)
dev->irq = 9;
err = com90io_probe(dev);
if (err) {
free_netdev(dev);
return err;
}
my_dev = dev;
return 0;
}
static void __exit com90io_exit(void)
{
struct net_device *dev = my_dev;
int ioaddr = dev->base_addr;
unregister_netdev(dev);
arcnet_outb(arcnet_inb(ioaddr, COM9026_REG_RW_CONFIG) & ~IOMAPflag,
ioaddr, COM9026_REG_RW_CONFIG);
free_irq(dev->irq, dev);
release_region(dev->base_addr, ARCNET_TOTAL_SIZE);
free_netdev(dev);
}
