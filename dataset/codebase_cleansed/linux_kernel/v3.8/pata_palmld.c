static int palmld_pata_probe(struct platform_device *pdev)
{
struct ata_host *host;
struct ata_port *ap;
void __iomem *mem;
int ret;
host = ata_host_alloc(&pdev->dev, 1);
if (!host) {
ret = -ENOMEM;
goto err1;
}
mem = devm_ioremap(&pdev->dev, PALMLD_IDE_PHYS, 0x1000);
if (!mem) {
ret = -ENOMEM;
goto err1;
}
ret = gpio_request_array(palmld_hdd_gpios,
ARRAY_SIZE(palmld_hdd_gpios));
if (ret)
goto err1;
gpio_set_value(GPIO_NR_PALMLD_IDE_RESET, 0);
msleep(30);
gpio_set_value(GPIO_NR_PALMLD_IDE_RESET, 1);
msleep(30);
ap = host->ports[0];
ap->ops = &palmld_port_ops;
ap->pio_mask = ATA_PIO4;
ap->flags |= ATA_FLAG_PIO_POLLING;
ap->ioaddr.cmd_addr = mem + 0x10;
ap->ioaddr.altstatus_addr = mem + 0xe;
ap->ioaddr.ctl_addr = mem + 0xe;
ata_sff_std_ports(&ap->ioaddr);
ret = ata_host_activate(host, 0, NULL, IRQF_TRIGGER_RISING,
&palmld_sht);
if (ret)
goto err2;
return ret;
err2:
gpio_free_array(palmld_hdd_gpios, ARRAY_SIZE(palmld_hdd_gpios));
err1:
return ret;
}
static int palmld_pata_remove(struct platform_device *dev)
{
ata_platform_remove_one(dev);
gpio_set_value(GPIO_NR_PALMLD_IDE_PWEN, 0);
gpio_free_array(palmld_hdd_gpios, ARRAY_SIZE(palmld_hdd_gpios));
return 0;
}
