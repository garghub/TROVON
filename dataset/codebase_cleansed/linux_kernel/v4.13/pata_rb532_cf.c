static irqreturn_t rb532_pata_irq_handler(int irq, void *dev_instance)
{
struct ata_host *ah = dev_instance;
struct rb532_cf_info *info = ah->private_data;
if (gpio_get_value(info->gpio_line)) {
irq_set_irq_type(info->irq, IRQ_TYPE_LEVEL_LOW);
ata_sff_interrupt(info->irq, dev_instance);
} else {
irq_set_irq_type(info->irq, IRQ_TYPE_LEVEL_HIGH);
}
return IRQ_HANDLED;
}
static void rb532_pata_setup_ports(struct ata_host *ah)
{
struct rb532_cf_info *info = ah->private_data;
struct ata_port *ap;
ap = ah->ports[0];
ap->ops = &rb532_pata_port_ops;
ap->pio_mask = ATA_PIO4;
ap->ioaddr.cmd_addr = info->iobase + RB500_CF_REG_BASE;
ap->ioaddr.ctl_addr = info->iobase + RB500_CF_REG_CTRL;
ap->ioaddr.altstatus_addr = info->iobase + RB500_CF_REG_CTRL;
ata_sff_std_ports(&ap->ioaddr);
ap->ioaddr.data_addr = info->iobase + RB500_CF_REG_DBUF32;
ap->ioaddr.error_addr = info->iobase + RB500_CF_REG_ERR;
}
static int rb532_pata_driver_probe(struct platform_device *pdev)
{
int irq;
int gpio;
struct resource *res;
struct ata_host *ah;
struct cf_device *pdata;
struct rb532_cf_info *info;
int ret;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no IOMEM resource found\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev, "no IRQ resource found\n");
return -ENOENT;
}
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "no platform data specified\n");
return -EINVAL;
}
gpio = pdata->gpio_pin;
if (gpio < 0) {
dev_err(&pdev->dev, "no GPIO found for irq%d\n", irq);
return -ENOENT;
}
ret = gpio_request(gpio, DRV_NAME);
if (ret) {
dev_err(&pdev->dev, "GPIO request failed\n");
return ret;
}
ah = ata_host_alloc(&pdev->dev, RB500_CF_MAXPORTS);
if (!ah)
return -ENOMEM;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
ah->private_data = info;
info->gpio_line = gpio;
info->irq = irq;
info->iobase = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (!info->iobase)
return -ENOMEM;
ret = gpio_direction_input(gpio);
if (ret) {
dev_err(&pdev->dev, "unable to set GPIO direction, err=%d\n",
ret);
goto err_free_gpio;
}
rb532_pata_setup_ports(ah);
ret = ata_host_activate(ah, irq, rb532_pata_irq_handler,
IRQF_TRIGGER_LOW, &rb532_pata_sht);
if (ret)
goto err_free_gpio;
return 0;
err_free_gpio:
gpio_free(gpio);
return ret;
}
static int rb532_pata_driver_remove(struct platform_device *pdev)
{
struct ata_host *ah = platform_get_drvdata(pdev);
struct rb532_cf_info *info = ah->private_data;
ata_host_detach(ah);
gpio_free(info->gpio_line);
return 0;
}
