static int gayle_test_irq(ide_hwif_t *hwif)
{
unsigned char ch;
ch = z_readb(hwif->io_ports.irq_addr);
if (!(ch & GAYLE_IRQ_IDE))
return 0;
return 1;
}
static void gayle_a1200_clear_irq(ide_drive_t *drive)
{
ide_hwif_t *hwif = drive->hwif;
(void)z_readb(hwif->io_ports.status_addr);
z_writeb(0x7c, hwif->io_ports.irq_addr);
}
static void __init gayle_setup_ports(struct ide_hw *hw, unsigned long base,
unsigned long ctl, unsigned long irq_port)
{
int i;
memset(hw, 0, sizeof(*hw));
hw->io_ports.data_addr = base;
for (i = 1; i < 8; i++)
hw->io_ports_array[i] = base + 2 + i * 4;
hw->io_ports.ctl_addr = ctl;
hw->io_ports.irq_addr = irq_port;
hw->irq = IRQ_AMIGA_PORTS;
}
static int __init amiga_gayle_ide_probe(struct platform_device *pdev)
{
struct resource *res;
struct gayle_ide_platform_data *pdata;
unsigned long base, ctrlport, irqport;
unsigned int i;
int error;
struct ide_hw hw[GAYLE_NUM_HWIFS], *hws[GAYLE_NUM_HWIFS];
struct ide_port_info d = gayle_port_info;
struct ide_host *host;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
if (!request_mem_region(res->start, resource_size(res), "IDE"))
return -EBUSY;
pdata = pdev->dev.platform_data;
pr_info("ide: Gayle IDE controller (A%u style%s)\n",
pdata->explicit_ack ? 1200 : 4000,
ide_doubler ? ", IDE doubler" : "");
base = (unsigned long)ZTWO_VADDR(pdata->base);
ctrlport = 0;
irqport = (unsigned long)ZTWO_VADDR(pdata->irqport);
if (pdata->explicit_ack)
d.port_ops = &gayle_a1200_port_ops;
else
d.port_ops = &gayle_a4000_port_ops;
for (i = 0; i < GAYLE_NUM_PROBE_HWIFS; i++, base += GAYLE_NEXT_PORT) {
if (GAYLE_HAS_CONTROL_REG)
ctrlport = base + GAYLE_CONTROL;
gayle_setup_ports(&hw[i], base, ctrlport, irqport);
hws[i] = &hw[i];
}
error = ide_host_add(&d, hws, i, &host);
if (error)
goto out;
platform_set_drvdata(pdev, host);
return 0;
out:
release_mem_region(res->start, resource_size(res));
return error;
}
static int __exit amiga_gayle_ide_remove(struct platform_device *pdev)
{
struct ide_host *host = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ide_host_remove(host);
release_mem_region(res->start, resource_size(res));
return 0;
}
static int __init amiga_gayle_ide_init(void)
{
return platform_driver_probe(&amiga_gayle_ide_driver,
amiga_gayle_ide_probe);
}
static void __exit amiga_gayle_ide_exit(void)
{
platform_driver_unregister(&amiga_gayle_ide_driver);
}
