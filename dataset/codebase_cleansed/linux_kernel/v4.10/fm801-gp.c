static int fm801_gp_cooked_read(struct gameport *gameport, int *axes, int *buttons)
{
unsigned short w;
w = inw(gameport->io + 2);
*buttons = (~w >> 14) & 0x03;
axes[0] = (w == 0xffff) ? -1 : ((w & 0x1fff) << 5);
w = inw(gameport->io + 4);
axes[1] = (w == 0xffff) ? -1 : ((w & 0x1fff) << 5);
w = inw(gameport->io + 6);
*buttons |= ((~w >> 14) & 0x03) << 2;
axes[2] = (w == 0xffff) ? -1 : ((w & 0x1fff) << 5);
w = inw(gameport->io + 8);
axes[3] = (w == 0xffff) ? -1 : ((w & 0x1fff) << 5);
outw(0xff, gameport->io);
return 0;
}
static int fm801_gp_open(struct gameport *gameport, int mode)
{
switch (mode) {
#ifdef HAVE_COOKED
case GAMEPORT_MODE_COOKED:
return 0;
#endif
case GAMEPORT_MODE_RAW:
return 0;
default:
return -1;
}
return 0;
}
static int fm801_gp_probe(struct pci_dev *pci, const struct pci_device_id *id)
{
struct fm801_gp *gp;
struct gameport *port;
int error;
gp = kzalloc(sizeof(struct fm801_gp), GFP_KERNEL);
port = gameport_allocate_port();
if (!gp || !port) {
printk(KERN_ERR "fm801-gp: Memory allocation failed\n");
error = -ENOMEM;
goto err_out_free;
}
error = pci_enable_device(pci);
if (error)
goto err_out_free;
port->open = fm801_gp_open;
#ifdef HAVE_COOKED
port->cooked_read = fm801_gp_cooked_read;
#endif
gameport_set_name(port, "FM801");
gameport_set_phys(port, "pci%s/gameport0", pci_name(pci));
port->dev.parent = &pci->dev;
port->io = pci_resource_start(pci, 0);
gp->gameport = port;
gp->res_port = request_region(port->io, 0x10, "FM801 GP");
if (!gp->res_port) {
printk(KERN_DEBUG "fm801-gp: unable to grab region 0x%x-0x%x\n",
port->io, port->io + 0x0f);
error = -EBUSY;
goto err_out_disable_dev;
}
pci_set_drvdata(pci, gp);
outb(0x60, port->io + 0x0d);
gameport_register_port(port);
return 0;
err_out_disable_dev:
pci_disable_device(pci);
err_out_free:
gameport_free_port(port);
kfree(gp);
return error;
}
static void fm801_gp_remove(struct pci_dev *pci)
{
struct fm801_gp *gp = pci_get_drvdata(pci);
gameport_unregister_port(gp->gameport);
release_resource(gp->res_port);
kfree(gp);
pci_disable_device(pci);
}
