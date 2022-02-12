int ahci_platform_enable_clks(struct ahci_host_priv *hpriv)
{
int c, rc;
for (c = 0; c < AHCI_MAX_CLKS && hpriv->clks[c]; c++) {
rc = clk_prepare_enable(hpriv->clks[c]);
if (rc)
goto disable_unprepare_clk;
}
return 0;
disable_unprepare_clk:
while (--c >= 0)
clk_disable_unprepare(hpriv->clks[c]);
return rc;
}
void ahci_platform_disable_clks(struct ahci_host_priv *hpriv)
{
int c;
for (c = AHCI_MAX_CLKS - 1; c >= 0; c--)
if (hpriv->clks[c])
clk_disable_unprepare(hpriv->clks[c]);
}
int ahci_platform_enable_resources(struct ahci_host_priv *hpriv)
{
int rc;
if (hpriv->target_pwr) {
rc = regulator_enable(hpriv->target_pwr);
if (rc)
return rc;
}
rc = ahci_platform_enable_clks(hpriv);
if (rc)
goto disable_regulator;
if (hpriv->phy) {
rc = phy_init(hpriv->phy);
if (rc)
goto disable_clks;
rc = phy_power_on(hpriv->phy);
if (rc) {
phy_exit(hpriv->phy);
goto disable_clks;
}
}
return 0;
disable_clks:
ahci_platform_disable_clks(hpriv);
disable_regulator:
if (hpriv->target_pwr)
regulator_disable(hpriv->target_pwr);
return rc;
}
void ahci_platform_disable_resources(struct ahci_host_priv *hpriv)
{
if (hpriv->phy) {
phy_power_off(hpriv->phy);
phy_exit(hpriv->phy);
}
ahci_platform_disable_clks(hpriv);
if (hpriv->target_pwr)
regulator_disable(hpriv->target_pwr);
}
static void ahci_platform_put_resources(struct device *dev, void *res)
{
struct ahci_host_priv *hpriv = res;
int c;
if (hpriv->got_runtime_pm) {
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
}
for (c = 0; c < AHCI_MAX_CLKS && hpriv->clks[c]; c++)
clk_put(hpriv->clks[c]);
}
struct ahci_host_priv *ahci_platform_get_resources(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct clk *clk;
int i, rc = -ENOMEM;
if (!devres_open_group(dev, NULL, GFP_KERNEL))
return ERR_PTR(-ENOMEM);
hpriv = devres_alloc(ahci_platform_put_resources, sizeof(*hpriv),
GFP_KERNEL);
if (!hpriv)
goto err_out;
devres_add(dev, hpriv);
hpriv->mmio = devm_ioremap_resource(dev,
platform_get_resource(pdev, IORESOURCE_MEM, 0));
if (IS_ERR(hpriv->mmio)) {
dev_err(dev, "no mmio space\n");
rc = PTR_ERR(hpriv->mmio);
goto err_out;
}
hpriv->target_pwr = devm_regulator_get_optional(dev, "target");
if (IS_ERR(hpriv->target_pwr)) {
rc = PTR_ERR(hpriv->target_pwr);
if (rc == -EPROBE_DEFER)
goto err_out;
hpriv->target_pwr = NULL;
}
for (i = 0; i < AHCI_MAX_CLKS; i++) {
if (i == 0)
clk = clk_get(dev, NULL);
else
clk = of_clk_get(dev->of_node, i);
if (IS_ERR(clk)) {
rc = PTR_ERR(clk);
if (rc == -EPROBE_DEFER)
goto err_out;
break;
}
hpriv->clks[i] = clk;
}
hpriv->phy = devm_phy_get(dev, "sata-phy");
if (IS_ERR(hpriv->phy)) {
rc = PTR_ERR(hpriv->phy);
switch (rc) {
case -ENOSYS:
if (of_find_property(dev->of_node, "phys", NULL)) {
dev_err(dev, "couldn't get sata-phy: ENOSYS\n");
goto err_out;
}
case -ENODEV:
hpriv->phy = NULL;
break;
case -EPROBE_DEFER:
goto err_out;
default:
dev_err(dev, "couldn't get sata-phy\n");
goto err_out;
}
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
hpriv->got_runtime_pm = true;
devres_remove_group(dev, NULL);
return hpriv;
err_out:
devres_release_group(dev, NULL);
return ERR_PTR(rc);
}
int ahci_platform_init_host(struct platform_device *pdev,
struct ahci_host_priv *hpriv,
const struct ata_port_info *pi_template,
unsigned long host_flags,
unsigned int force_port_map,
unsigned int mask_port_map)
{
struct device *dev = &pdev->dev;
struct ata_port_info pi = *pi_template;
const struct ata_port_info *ppi[] = { &pi, NULL };
struct ata_host *host;
int i, irq, n_ports, rc;
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "no irq\n");
return -EINVAL;
}
pi.private_data = (void *)host_flags;
hpriv->flags |= host_flags;
ahci_save_initial_config(dev, hpriv, force_port_map, mask_port_map);
if (hpriv->cap & HOST_CAP_NCQ)
pi.flags |= ATA_FLAG_NCQ;
if (hpriv->cap & HOST_CAP_PMP)
pi.flags |= ATA_FLAG_PMP;
ahci_set_em_messages(hpriv, &pi);
n_ports = max(ahci_nr_ports(hpriv->cap), fls(hpriv->port_map));
host = ata_host_alloc_pinfo(dev, ppi, n_ports);
if (!host)
return -ENOMEM;
host->private_data = hpriv;
if (!(hpriv->cap & HOST_CAP_SSS) || ahci_ignore_sss)
host->flags |= ATA_HOST_PARALLEL_SCAN;
else
dev_info(dev, "SSS flag set, parallel bus scan disabled\n");
if (pi.flags & ATA_FLAG_EM)
ahci_reset_em(host);
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
ata_port_desc(ap, "mmio %pR",
platform_get_resource(pdev, IORESOURCE_MEM, 0));
ata_port_desc(ap, "port 0x%x", 0x100 + ap->port_no * 0x80);
if (ap->flags & ATA_FLAG_EM)
ap->em_message_type = hpriv->em_msg_type;
if (!(hpriv->port_map & (1 << i)))
ap->ops = &ata_dummy_port_ops;
}
rc = ahci_reset_controller(host);
if (rc)
return rc;
ahci_init_controller(host);
ahci_print_info(host, "platform");
return ata_host_activate(host, irq, ahci_interrupt, IRQF_SHARED,
&ahci_platform_sht);
}
static void ahci_host_stop(struct ata_host *host)
{
struct device *dev = host->dev;
struct ahci_platform_data *pdata = dev_get_platdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
if (pdata && pdata->exit)
pdata->exit(dev);
ahci_platform_disable_resources(hpriv);
}
int ahci_platform_suspend_host(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
void __iomem *mmio = hpriv->mmio;
u32 ctl;
if (hpriv->flags & AHCI_HFLAG_NO_SUSPEND) {
dev_err(dev, "firmware update required for suspend/resume\n");
return -EIO;
}
ctl = readl(mmio + HOST_CTL);
ctl &= ~HOST_IRQ_EN;
writel(ctl, mmio + HOST_CTL);
readl(mmio + HOST_CTL);
return ata_host_suspend(host, PMSG_SUSPEND);
}
int ahci_platform_resume_host(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
int rc;
if (dev->power.power_state.event == PM_EVENT_SUSPEND) {
rc = ahci_reset_controller(host);
if (rc)
return rc;
ahci_init_controller(host);
}
ata_host_resume(host);
return 0;
}
int ahci_platform_suspend(struct device *dev)
{
struct ahci_platform_data *pdata = dev_get_platdata(dev);
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
int rc;
rc = ahci_platform_suspend_host(dev);
if (rc)
return rc;
if (pdata && pdata->suspend) {
rc = pdata->suspend(dev);
if (rc)
goto resume_host;
}
ahci_platform_disable_resources(hpriv);
return 0;
resume_host:
ahci_platform_resume_host(dev);
return rc;
}
int ahci_platform_resume(struct device *dev)
{
struct ahci_platform_data *pdata = dev_get_platdata(dev);
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
int rc;
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
if (pdata && pdata->resume) {
rc = pdata->resume(dev);
if (rc)
goto disable_resources;
}
rc = ahci_platform_resume_host(dev);
if (rc)
goto disable_resources;
pm_runtime_disable(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
return 0;
disable_resources:
ahci_platform_disable_resources(hpriv);
return rc;
}
