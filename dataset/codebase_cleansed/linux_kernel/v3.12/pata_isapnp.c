static int isapnp_init_one(struct pnp_dev *idev, const struct pnp_device_id *dev_id)
{
struct ata_host *host;
struct ata_port *ap;
void __iomem *cmd_addr, *ctl_addr;
int irq = 0;
irq_handler_t handler = NULL;
if (pnp_port_valid(idev, 0) == 0)
return -ENODEV;
if (pnp_irq_valid(idev, 0)) {
irq = pnp_irq(idev, 0);
handler = ata_sff_interrupt;
}
host = ata_host_alloc(&idev->dev, 1);
if (!host)
return -ENOMEM;
cmd_addr = devm_ioport_map(&idev->dev, pnp_port_start(idev, 0), 8);
if (!cmd_addr)
return -ENOMEM;
ap = host->ports[0];
ap->ops = &isapnp_noalt_port_ops;
ap->pio_mask = ATA_PIO0;
ap->flags |= ATA_FLAG_SLAVE_POSS;
ap->ioaddr.cmd_addr = cmd_addr;
if (pnp_port_valid(idev, 1)) {
ctl_addr = devm_ioport_map(&idev->dev,
pnp_port_start(idev, 1), 1);
ap->ioaddr.altstatus_addr = ctl_addr;
ap->ioaddr.ctl_addr = ctl_addr;
ap->ops = &isapnp_port_ops;
}
ata_sff_std_ports(&ap->ioaddr);
ata_port_desc(ap, "cmd 0x%llx ctl 0x%llx",
(unsigned long long)pnp_port_start(idev, 0),
(unsigned long long)pnp_port_start(idev, 1));
return ata_host_activate(host, irq, handler, 0,
&isapnp_sht);
}
static void isapnp_remove_one(struct pnp_dev *idev)
{
struct device *dev = &idev->dev;
struct ata_host *host = dev_get_drvdata(dev);
ata_host_detach(host);
}
static int __init isapnp_init(void)
{
return pnp_register_driver(&isapnp_driver);
}
static void __exit isapnp_exit(void)
{
pnp_unregister_driver(&isapnp_driver);
}
