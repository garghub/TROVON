static u_char get_buffer_byte(struct net_device *dev, unsigned offset)
{
int ioaddr = dev->base_addr;
outb(offset >> 8, _ADDR_HI);
outb(offset & 0xff, _ADDR_LO);
return inb(_MEMDATA);
}
static void put_buffer_byte(struct net_device *dev, unsigned offset, u_char datum)
{
int ioaddr = dev->base_addr;
outb(offset >> 8, _ADDR_HI);
outb(offset & 0xff, _ADDR_LO);
outb(datum, _MEMDATA);
}
static void get_whole_buffer(struct net_device *dev, unsigned offset, unsigned length, char *dest)
{
int ioaddr = dev->base_addr;
outb((offset >> 8) | AUTOINCflag, _ADDR_HI);
outb(offset & 0xff, _ADDR_LO);
while (length--)
#ifdef ONE_AT_A_TIME_RX
*(dest++) = get_buffer_byte(dev, offset++);
#else
*(dest++) = inb(_MEMDATA);
#endif
}
static void put_whole_buffer(struct net_device *dev, unsigned offset, unsigned length, char *dest)
{
int ioaddr = dev->base_addr;
outb((offset >> 8) | AUTOINCflag, _ADDR_HI);
outb(offset & 0xff, _ADDR_LO);
while (length--)
#ifdef ONE_AT_A_TIME_TX
put_buffer_byte(dev, offset++, *(dest++));
#else
outb(*(dest++), _MEMDATA);
#endif
}
static int __init com90io_probe(struct net_device *dev)
{
int ioaddr = dev->base_addr, status;
unsigned long airqmask;
BUGLVL(D_NORMAL) printk(VERSION);
BUGLVL(D_NORMAL) printk("E-mail me if you actually test this driver, please!\n");
if (!ioaddr) {
BUGMSG(D_NORMAL, "No autoprobe for IO mapped cards; you "
"must specify the base address!\n");
return -ENODEV;
}
if (!request_region(ioaddr, ARCNET_TOTAL_SIZE, "com90io probe")) {
BUGMSG(D_INIT_REASONS, "IO request_region %x-%x failed.\n",
ioaddr, ioaddr + ARCNET_TOTAL_SIZE - 1);
return -ENXIO;
}
if (ASTATUS() == 0xFF) {
BUGMSG(D_INIT_REASONS, "IO address %x empty\n", ioaddr);
goto err_out;
}
inb(_RESET);
mdelay(RESETtime);
status = ASTATUS();
if ((status & 0x9D) != (NORXflag | RECONflag | TXFREEflag | RESETflag)) {
BUGMSG(D_INIT_REASONS, "Status invalid (%Xh).\n", status);
goto err_out;
}
BUGMSG(D_INIT_REASONS, "Status after reset: %X\n", status);
ACOMMAND(CFLAGScmd | RESETclear | CONFIGclear);
BUGMSG(D_INIT_REASONS, "Status after reset acknowledged: %X\n", status);
status = ASTATUS();
if (status & RESETflag) {
BUGMSG(D_INIT_REASONS, "Eternal reset (status=%Xh)\n", status);
goto err_out;
}
outb((0x16 | IOMAPflag) & ~ENABLE16flag, _CONFIG);
outb(AUTOINCflag, _ADDR_HI);
outb(0, _ADDR_LO);
if ((status = inb(_MEMDATA)) != 0xd1) {
BUGMSG(D_INIT_REASONS, "Signature byte not found"
" (%Xh instead).\n", status);
goto err_out;
}
if (!dev->irq) {
airqmask = probe_irq_on();
outb(NORXflag, _INTMASK);
udelay(1);
outb(0, _INTMASK);
dev->irq = probe_irq_off(airqmask);
if ((int)dev->irq <= 0) {
BUGMSG(D_INIT_REASONS, "Autoprobe IRQ failed\n");
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
if (request_irq(dev->irq, arcnet_interrupt, 0, "arcnet (COM90xx-IO)", dev)) {
BUGMSG(D_NORMAL, "Can't get IRQ %d!\n", dev->irq);
return -ENODEV;
}
if (!request_region(dev->base_addr, ARCNET_TOTAL_SIZE, "arcnet (COM90xx-IO)")) {
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
SETCONF();
dev->dev_addr[0] = get_buffer_byte(dev, 1);
err = register_netdev(dev);
if (err) {
outb((inb(_CONFIG) & ~IOMAPflag), _CONFIG);
free_irq(dev->irq, dev);
release_region(dev->base_addr, ARCNET_TOTAL_SIZE);
return err;
}
BUGMSG(D_NORMAL, "COM90IO: station %02Xh found at %03lXh, IRQ %d.\n",
dev->dev_addr[0], dev->base_addr, dev->irq);
return 0;
}
static int com90io_reset(struct net_device *dev, int really_reset)
{
struct arcnet_local *lp = netdev_priv(dev);
short ioaddr = dev->base_addr;
BUGMSG(D_INIT, "Resetting %s (status=%02Xh)\n", dev->name, ASTATUS());
if (really_reset) {
inb(_RESET);
mdelay(RESETtime);
}
lp->config = (0x1C | IOMAPflag) & ~ENABLE16flag;
SETCONF();
ACOMMAND(CFLAGScmd | RESETclear);
ACOMMAND(CFLAGScmd | CONFIGclear);
if (get_buffer_byte(dev, 0) != TESTvalue) {
BUGMSG(D_NORMAL, "reset failed: TESTvalue not present.\n");
return 1;
}
ACOMMAND(CONFIGcmd | EXTconf);
return 0;
}
static void com90io_command(struct net_device *dev, int cmd)
{
short ioaddr = dev->base_addr;
ACOMMAND(cmd);
}
static int com90io_status(struct net_device *dev)
{
short ioaddr = dev->base_addr;
return ASTATUS();
}
static void com90io_setmask(struct net_device *dev, int mask)
{
short ioaddr = dev->base_addr;
AINTMASK(mask);
}
static void com90io_copy_to_card(struct net_device *dev, int bufnum, int offset,
void *buf, int count)
{
TIME("put_whole_buffer", count, put_whole_buffer(dev, bufnum * 512 + offset, count, buf));
}
static void com90io_copy_from_card(struct net_device *dev, int bufnum, int offset,
void *buf, int count)
{
TIME("get_whole_buffer", count, get_whole_buffer(dev, bufnum * 512 + offset, count, buf));
}
static int __init com90io_setup(char *s)
{
int ints[4];
s = get_options(s, 4, ints);
if (!ints[0])
return 0;
switch (ints[0]) {
default:
printk("com90io: Too many arguments.\n");
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
outb((inb(_CONFIG) & ~IOMAPflag), _CONFIG);
free_irq(dev->irq, dev);
release_region(dev->base_addr, ARCNET_TOTAL_SIZE);
free_netdev(dev);
}
