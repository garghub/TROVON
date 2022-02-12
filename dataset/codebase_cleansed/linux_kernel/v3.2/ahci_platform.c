static int __init ahci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_platform_data *pdata = dev_get_platdata(dev);
const struct platform_device_id *id = platform_get_device_id(pdev);
struct ata_port_info pi = ahci_port_info[id ? id->driver_data : 0];
const struct ata_port_info *ppi[] = { &pi, NULL };
struct ahci_host_priv *hpriv;
struct ata_host *host;
struct resource *mem;
int irq;
int n_ports;
int i;
int rc;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(dev, "no mmio space\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "no irq\n");
return -EINVAL;
}
if (pdata && pdata->ata_port_info)
pi = *pdata->ata_port_info;
hpriv = devm_kzalloc(dev, sizeof(*hpriv), GFP_KERNEL);
if (!hpriv) {
dev_err(dev, "can't alloc ahci_host_priv\n");
return -ENOMEM;
}
hpriv->flags |= (unsigned long)pi.private_data;
hpriv->mmio = devm_ioremap(dev, mem->start, resource_size(mem));
if (!hpriv->mmio) {
dev_err(dev, "can't map %pR\n", mem);
return -ENOMEM;
}
if (pdata && pdata->init) {
rc = pdata->init(dev, hpriv->mmio);
if (rc)
return rc;
}
ahci_save_initial_config(dev, hpriv,
pdata ? pdata->force_port_map : 0,
pdata ? pdata->mask_port_map : 0);
if (hpriv->cap & HOST_CAP_NCQ)
pi.flags |= ATA_FLAG_NCQ;
if (hpriv->cap & HOST_CAP_PMP)
pi.flags |= ATA_FLAG_PMP;
ahci_set_em_messages(hpriv, &pi);
n_ports = max(ahci_nr_ports(hpriv->cap), fls(hpriv->port_map));
host = ata_host_alloc_pinfo(dev, ppi, n_ports);
if (!host) {
rc = -ENOMEM;
goto err0;
}
host->private_data = hpriv;
if (!(hpriv->cap & HOST_CAP_SSS) || ahci_ignore_sss)
host->flags |= ATA_HOST_PARALLEL_SCAN;
else
printk(KERN_INFO "ahci: SSS flag set, parallel bus scan disabled\n");
if (pi.flags & ATA_FLAG_EM)
ahci_reset_em(host);
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
ata_port_desc(ap, "mmio %pR", mem);
ata_port_desc(ap, "port 0x%x", 0x100 + ap->port_no * 0x80);
if (ap->flags & ATA_FLAG_EM)
ap->em_message_type = hpriv->em_msg_type;
if (!(hpriv->port_map & (1 << i)))
ap->ops = &ata_dummy_port_ops;
}
rc = ahci_reset_controller(host);
if (rc)
goto err0;
ahci_init_controller(host);
ahci_print_info(host, "platform");
rc = ata_host_activate(host, irq, ahci_interrupt, IRQF_SHARED,
&ahci_platform_sht);
if (rc)
goto err0;
return 0;
err0:
if (pdata && pdata->exit)
pdata->exit(dev);
return rc;
}
static int __devexit ahci_remove(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_platform_data *pdata = dev_get_platdata(dev);
struct ata_host *host = dev_get_drvdata(dev);
ata_host_detach(host);
if (pdata && pdata->exit)
pdata->exit(dev);
return 0;
}
static int __init ahci_init(void)
{
return platform_driver_probe(&ahci_driver, ahci_probe);
}
static void __exit ahci_exit(void)
{
platform_driver_unregister(&ahci_driver);
}
