static int ahci_platform_enable_phys(struct ahci_host_priv *hpriv)
{
int rc, i;
for (i = 0; i < hpriv->nports; i++) {
rc = phy_init(hpriv->phys[i]);
if (rc)
goto disable_phys;
rc = phy_power_on(hpriv->phys[i]);
if (rc) {
phy_exit(hpriv->phys[i]);
goto disable_phys;
}
}
return 0;
disable_phys:
while (--i >= 0) {
phy_power_off(hpriv->phys[i]);
phy_exit(hpriv->phys[i]);
}
return rc;
}
static void ahci_platform_disable_phys(struct ahci_host_priv *hpriv)
{
int i;
for (i = 0; i < hpriv->nports; i++) {
phy_power_off(hpriv->phys[i]);
phy_exit(hpriv->phys[i]);
}
}
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
int ahci_platform_enable_regulators(struct ahci_host_priv *hpriv)
{
int rc, i;
for (i = 0; i < hpriv->nports; i++) {
if (!hpriv->target_pwrs[i])
continue;
rc = regulator_enable(hpriv->target_pwrs[i]);
if (rc)
goto disable_target_pwrs;
}
return 0;
disable_target_pwrs:
while (--i >= 0)
if (hpriv->target_pwrs[i])
regulator_disable(hpriv->target_pwrs[i]);
return rc;
}
void ahci_platform_disable_regulators(struct ahci_host_priv *hpriv)
{
int i;
for (i = 0; i < hpriv->nports; i++) {
if (!hpriv->target_pwrs[i])
continue;
regulator_disable(hpriv->target_pwrs[i]);
}
}
int ahci_platform_enable_resources(struct ahci_host_priv *hpriv)
{
int rc;
rc = ahci_platform_enable_regulators(hpriv);
if (rc)
return rc;
rc = ahci_platform_enable_clks(hpriv);
if (rc)
goto disable_regulator;
rc = ahci_platform_enable_phys(hpriv);
if (rc)
goto disable_clks;
return 0;
disable_clks:
ahci_platform_disable_clks(hpriv);
disable_regulator:
ahci_platform_disable_regulators(hpriv);
return rc;
}
void ahci_platform_disable_resources(struct ahci_host_priv *hpriv)
{
ahci_platform_disable_phys(hpriv);
ahci_platform_disable_clks(hpriv);
ahci_platform_disable_regulators(hpriv);
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
for (c = 0; c < hpriv->nports; c++)
if (hpriv->target_pwrs && hpriv->target_pwrs[c])
regulator_put(hpriv->target_pwrs[c]);
kfree(hpriv->target_pwrs);
}
static int ahci_platform_get_phy(struct ahci_host_priv *hpriv, u32 port,
struct device *dev, struct device_node *node)
{
int rc;
hpriv->phys[port] = devm_of_phy_get(dev, node, NULL);
if (!IS_ERR(hpriv->phys[port]))
return 0;
rc = PTR_ERR(hpriv->phys[port]);
switch (rc) {
case -ENOSYS:
if (of_find_property(node, "phys", NULL)) {
dev_err(dev,
"couldn't get PHY in node %s: ENOSYS\n",
node->name);
break;
}
case -ENODEV:
hpriv->phys[port] = NULL;
rc = 0;
break;
default:
dev_err(dev,
"couldn't get PHY in node %s: %d\n",
node->name, rc);
break;
}
return rc;
}
static int ahci_platform_get_regulator(struct ahci_host_priv *hpriv, u32 port,
struct device *dev)
{
struct regulator *target_pwr;
int rc = 0;
target_pwr = regulator_get_optional(dev, "target");
if (!IS_ERR(target_pwr))
hpriv->target_pwrs[port] = target_pwr;
else
rc = PTR_ERR(target_pwr);
return rc;
}
struct ahci_host_priv *ahci_platform_get_resources(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct clk *clk;
struct device_node *child;
int i, sz, enabled_ports = 0, rc = -ENOMEM, child_nodes;
u32 mask_port_map = 0;
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
hpriv->nports = child_nodes = of_get_child_count(dev->of_node);
if (!child_nodes)
hpriv->nports = 1;
sz = hpriv->nports * sizeof(*hpriv->phys);
hpriv->phys = devm_kzalloc(dev, sz, GFP_KERNEL);
if (!hpriv->phys) {
rc = -ENOMEM;
goto err_out;
}
sz = hpriv->nports * sizeof(*hpriv->target_pwrs);
hpriv->target_pwrs = kzalloc(sz, GFP_KERNEL);
if (!hpriv->target_pwrs) {
rc = -ENOMEM;
goto err_out;
}
if (child_nodes) {
for_each_child_of_node(dev->of_node, child) {
u32 port;
struct platform_device *port_dev __maybe_unused;
if (!of_device_is_available(child))
continue;
if (of_property_read_u32(child, "reg", &port)) {
rc = -EINVAL;
goto err_out;
}
if (port >= hpriv->nports) {
dev_warn(dev, "invalid port number %d\n", port);
continue;
}
mask_port_map |= BIT(port);
#ifdef CONFIG_OF_ADDRESS
of_platform_device_create(child, NULL, NULL);
port_dev = of_find_device_by_node(child);
if (port_dev) {
rc = ahci_platform_get_regulator(hpriv, port,
&port_dev->dev);
if (rc == -EPROBE_DEFER)
goto err_out;
}
#endif
rc = ahci_platform_get_phy(hpriv, port, dev, child);
if (rc)
goto err_out;
enabled_ports++;
}
if (!enabled_ports) {
dev_warn(dev, "No port enabled\n");
rc = -ENODEV;
goto err_out;
}
if (!hpriv->mask_port_map)
hpriv->mask_port_map = mask_port_map;
} else {
rc = ahci_platform_get_phy(hpriv, 0, dev, dev->of_node);
if (rc)
goto err_out;
rc = ahci_platform_get_regulator(hpriv, 0, dev);
if (rc == -EPROBE_DEFER)
goto err_out;
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
struct scsi_host_template *sht)
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
hpriv->irq = irq;
pi.private_data = (void *)(unsigned long)hpriv->flags;
ahci_save_initial_config(dev, hpriv);
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
if (hpriv->cap & HOST_CAP_64) {
rc = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(64));
if (rc) {
rc = dma_coerce_mask_and_coherent(dev,
DMA_BIT_MASK(32));
if (rc) {
dev_err(dev, "Failed to enable 64-bit DMA.\n");
return rc;
}
dev_warn(dev, "Enable 32-bit DMA instead of 64-bit.\n");
}
}
rc = ahci_reset_controller(host);
if (rc)
return rc;
ahci_init_controller(host);
ahci_print_info(host, "platform");
return ahci_host_activate(host, sht);
}
static void ahci_host_stop(struct ata_host *host)
{
struct ahci_host_priv *hpriv = host->private_data;
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
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
int rc;
rc = ahci_platform_suspend_host(dev);
if (rc)
return rc;
ahci_platform_disable_resources(hpriv);
return 0;
}
int ahci_platform_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
int rc;
rc = ahci_platform_enable_resources(hpriv);
if (rc)
return rc;
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
