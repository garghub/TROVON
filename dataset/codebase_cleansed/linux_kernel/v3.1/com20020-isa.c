static int __init com20020isa_probe(struct net_device *dev)
{
int ioaddr;
unsigned long airqmask;
struct arcnet_local *lp = netdev_priv(dev);
int err;
BUGLVL(D_NORMAL) printk(VERSION);
ioaddr = dev->base_addr;
if (!ioaddr) {
BUGMSG(D_NORMAL, "No autoprobe (yet) for IO mapped cards; you "
"must specify the base address!\n");
return -ENODEV;
}
if (!request_region(ioaddr, ARCNET_TOTAL_SIZE, "arcnet (COM20020)")) {
BUGMSG(D_NORMAL, "IO region %xh-%xh already allocated.\n",
ioaddr, ioaddr + ARCNET_TOTAL_SIZE - 1);
return -ENXIO;
}
if (ASTATUS() == 0xFF) {
BUGMSG(D_NORMAL, "IO address %x empty\n", ioaddr);
err = -ENODEV;
goto out;
}
if (com20020_check(dev)) {
err = -ENODEV;
goto out;
}
if (!dev->irq) {
BUGMSG(D_INIT_REASONS, "intmask was %02Xh\n", inb(_INTMASK));
outb(0, _INTMASK);
airqmask = probe_irq_on();
outb(NORXflag, _INTMASK);
udelay(1);
outb(0, _INTMASK);
dev->irq = probe_irq_off(airqmask);
if ((int)dev->irq <= 0) {
BUGMSG(D_INIT_REASONS, "Autoprobe IRQ failed first time\n");
airqmask = probe_irq_on();
outb(NORXflag, _INTMASK);
udelay(5);
outb(0, _INTMASK);
dev->irq = probe_irq_off(airqmask);
if ((int)dev->irq <= 0) {
BUGMSG(D_NORMAL, "Autoprobe IRQ failed.\n");
err = -ENODEV;
goto out;
}
}
}
lp->card_name = "ISA COM20020";
if ((err = com20020_found(dev, 0)) != 0)
goto out;
return 0;
out:
release_region(ioaddr, ARCNET_TOTAL_SIZE);
return err;
}
static int __init com20020_init(void)
{
struct net_device *dev;
struct arcnet_local *lp;
dev = alloc_arcdev(device);
if (!dev)
return -ENOMEM;
if (node && node != 0xff)
dev->dev_addr[0] = node;
dev->netdev_ops = &com20020_netdev_ops;
lp = netdev_priv(dev);
lp->backplane = backplane;
lp->clockp = clockp & 7;
lp->clockm = clockm & 3;
lp->timeout = timeout & 3;
lp->hw.owner = THIS_MODULE;
dev->base_addr = io;
dev->irq = irq;
if (dev->irq == 2)
dev->irq = 9;
if (com20020isa_probe(dev)) {
free_netdev(dev);
return -EIO;
}
my_dev = dev;
return 0;
}
static void __exit com20020_exit(void)
{
unregister_netdev(my_dev);
free_irq(my_dev->irq, my_dev);
release_region(my_dev->base_addr, ARCNET_TOTAL_SIZE);
free_netdev(my_dev);
}
static int __init com20020isa_setup(char *s)
{
int ints[8];
s = get_options(s, 8, ints);
if (!ints[0])
return 1;
switch (ints[0]) {
default:
printk("com90xx: Too many arguments.\n");
case 6:
timeout = ints[6];
case 5:
clockp = ints[5];
case 4:
backplane = ints[4];
case 3:
node = ints[3];
case 2:
irq = ints[2];
case 1:
io = ints[1];
}
if (*s)
snprintf(device, sizeof(device), "%s", s);
return 1;
}
