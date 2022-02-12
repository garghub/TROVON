static int idepnp_probe(struct pnp_dev *dev, const struct pnp_device_id *dev_id)
{
struct ide_host *host;
unsigned long base, ctl;
int rc;
struct ide_hw hw, *hws[] = { &hw };
printk(KERN_INFO DRV_NAME ": generic PnP IDE interface\n");
if (!(pnp_port_valid(dev, 0) && pnp_port_valid(dev, 1) && pnp_irq_valid(dev, 0)))
return -1;
base = pnp_port_start(dev, 0);
ctl = pnp_port_start(dev, 1);
if (!request_region(base, 8, DRV_NAME)) {
printk(KERN_ERR "%s: I/O resource 0x%lX-0x%lX not free.\n",
DRV_NAME, base, base + 7);
return -EBUSY;
}
if (!request_region(ctl, 1, DRV_NAME)) {
printk(KERN_ERR "%s: I/O resource 0x%lX not free.\n",
DRV_NAME, ctl);
release_region(base, 8);
return -EBUSY;
}
memset(&hw, 0, sizeof(hw));
ide_std_init_ports(&hw, base, ctl);
hw.irq = pnp_irq(dev, 0);
rc = ide_host_add(&ide_pnp_port_info, hws, 1, &host);
if (rc)
goto out;
pnp_set_drvdata(dev, host);
return 0;
out:
release_region(ctl, 1);
release_region(base, 8);
return rc;
}
static void idepnp_remove(struct pnp_dev *dev)
{
struct ide_host *host = pnp_get_drvdata(dev);
ide_host_remove(host);
release_region(pnp_port_start(dev, 1), 1);
release_region(pnp_port_start(dev, 0), 8);
}
