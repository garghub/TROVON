static int ns558_isa_probe(int io)
{
int i, j, b;
unsigned char c, u, v;
struct ns558 *ns558;
struct gameport *port;
if (!request_region(io, 1, "ns558-isa"))
return -EBUSY;
c = inb(io);
outb(~c & ~3, io);
if (~(u = v = inb(io)) & 3) {
outb(c, io);
release_region(io, 1);
return -ENODEV;
}
for (i = 0; i < 1000; i++) v &= inb(io);
if (u == v) {
outb(c, io);
release_region(io, 1);
return -ENODEV;
}
msleep(3);
u = inb(io);
for (i = 0; i < 1000; i++)
if ((u ^ inb(io)) & 0xf) {
outb(c, io);
release_region(io, 1);
return -ENODEV;
}
for (i = 1; i < 5; i++) {
release_region(io & (-1 << (i - 1)), (1 << (i - 1)));
if (!request_region(io & (-1 << i), (1 << i), "ns558-isa"))
break;
outb(0xff, io & (-1 << i));
for (j = b = 0; j < 1000; j++)
if (inb(io & (-1 << i)) != inb((io & (-1 << i)) + (1 << i) - 1)) b++;
msleep(3);
if (b > 300) {
release_region(io & (-1 << i), (1 << i));
break;
}
}
i--;
if (i != 4) {
if (!request_region(io & (-1 << i), (1 << i), "ns558-isa"))
return -EBUSY;
}
ns558 = kzalloc(sizeof(struct ns558), GFP_KERNEL);
port = gameport_allocate_port();
if (!ns558 || !port) {
printk(KERN_ERR "ns558: Memory allocation failed.\n");
release_region(io & (-1 << i), (1 << i));
kfree(ns558);
gameport_free_port(port);
return -ENOMEM;
}
ns558->io = io;
ns558->size = 1 << i;
ns558->gameport = port;
port->io = io;
gameport_set_name(port, "NS558 ISA Gameport");
gameport_set_phys(port, "isa%04x/gameport0", io & (-1 << i));
gameport_register_port(port);
list_add(&ns558->node, &ns558_list);
return 0;
}
static int ns558_pnp_probe(struct pnp_dev *dev, const struct pnp_device_id *did)
{
int ioport, iolen;
struct ns558 *ns558;
struct gameport *port;
if (!pnp_port_valid(dev, 0)) {
printk(KERN_WARNING "ns558: No i/o ports on a gameport? Weird\n");
return -ENODEV;
}
ioport = pnp_port_start(dev, 0);
iolen = pnp_port_len(dev, 0);
if (!request_region(ioport, iolen, "ns558-pnp"))
return -EBUSY;
ns558 = kzalloc(sizeof(struct ns558), GFP_KERNEL);
port = gameport_allocate_port();
if (!ns558 || !port) {
printk(KERN_ERR "ns558: Memory allocation failed\n");
kfree(ns558);
gameport_free_port(port);
return -ENOMEM;
}
ns558->io = ioport;
ns558->size = iolen;
ns558->dev = dev;
ns558->gameport = port;
gameport_set_name(port, "NS558 PnP Gameport");
gameport_set_phys(port, "pnp%s/gameport0", dev_name(&dev->dev));
port->dev.parent = &dev->dev;
port->io = ioport;
gameport_register_port(port);
list_add_tail(&ns558->node, &ns558_list);
return 0;
}
static int __init ns558_init(void)
{
int i = 0;
int error;
error = pnp_register_driver(&ns558_pnp_driver);
if (error && error != -ENODEV)
return error;
while (ns558_isa_portlist[i])
ns558_isa_probe(ns558_isa_portlist[i++]);
return list_empty(&ns558_list) && error ? -ENODEV : 0;
}
static void __exit ns558_exit(void)
{
struct ns558 *ns558, *safe;
list_for_each_entry_safe(ns558, safe, &ns558_list, node) {
gameport_unregister_port(ns558->gameport);
release_region(ns558->io & ~(ns558->size - 1), ns558->size);
kfree(ns558);
}
pnp_unregister_driver(&ns558_pnp_driver);
}
