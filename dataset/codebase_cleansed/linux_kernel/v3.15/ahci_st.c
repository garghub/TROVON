static void st_ahci_configure_oob(void __iomem *mmio)
{
unsigned long old_val, new_val;
new_val = (0x02 << ST_AHCI_OOBR_CWMIN_SHIFT) |
(0x04 << ST_AHCI_OOBR_CWMAX_SHIFT) |
(0x08 << ST_AHCI_OOBR_CIMIN_SHIFT) |
(0x0C << ST_AHCI_OOBR_CIMAX_SHIFT);
old_val = readl(mmio + ST_AHCI_OOBR);
writel(old_val | ST_AHCI_OOBR_WE, mmio + ST_AHCI_OOBR);
writel(new_val | ST_AHCI_OOBR_WE, mmio + ST_AHCI_OOBR);
writel(new_val, mmio + ST_AHCI_OOBR);
}
static int st_ahci_deassert_resets(struct device *dev)
{
struct st_ahci_drv_data *drv_data = dev_get_drvdata(dev);
int err;
if (drv_data->pwr) {
err = reset_control_deassert(drv_data->pwr);
if (err) {
dev_err(dev, "unable to bring out of pwrdwn\n");
return err;
}
}
st_ahci_configure_oob(drv_data->hpriv->mmio);
if (drv_data->sw_rst) {
err = reset_control_deassert(drv_data->sw_rst);
if (err) {
dev_err(dev, "unable to bring out of sw-rst\n");
return err;
}
}
if (drv_data->pwr_rst) {
err = reset_control_deassert(drv_data->pwr_rst);
if (err) {
dev_err(dev, "unable to bring out of pwr-rst\n");
return err;
}
}
return 0;
}
static void st_ahci_host_stop(struct ata_host *host)
{
struct ahci_host_priv *hpriv = host->private_data;
struct device *dev = host->dev;
struct st_ahci_drv_data *drv_data = dev_get_drvdata(dev);
int err;
if (drv_data->pwr) {
err = reset_control_assert(drv_data->pwr);
if (err)
dev_err(dev, "unable to pwrdwn\n");
}
ahci_platform_disable_resources(hpriv);
}
static int st_ahci_probe_resets(struct platform_device *pdev)
{
struct st_ahci_drv_data *drv_data = platform_get_drvdata(pdev);
drv_data->pwr = devm_reset_control_get(&pdev->dev, "pwr-dwn");
if (IS_ERR(drv_data->pwr)) {
dev_info(&pdev->dev, "power reset control not defined\n");
drv_data->pwr = NULL;
}
drv_data->sw_rst = devm_reset_control_get(&pdev->dev, "sw-rst");
if (IS_ERR(drv_data->sw_rst)) {
dev_info(&pdev->dev, "soft reset control not defined\n");
drv_data->sw_rst = NULL;
}
drv_data->pwr_rst = devm_reset_control_get(&pdev->dev, "pwr-rst");
if (IS_ERR(drv_data->pwr_rst)) {
dev_dbg(&pdev->dev, "power soft reset control not defined\n");
drv_data->pwr_rst = NULL;
}
return st_ahci_deassert_resets(&pdev->dev);
}
static int st_ahci_probe(struct platform_device *pdev)
{
struct st_ahci_drv_data *drv_data;
struct ahci_host_priv *hpriv;
int err;
drv_data = devm_kzalloc(&pdev->dev, sizeof(*drv_data), GFP_KERNEL);
if (!drv_data)
return -ENOMEM;
platform_set_drvdata(pdev, drv_data);
hpriv = ahci_platform_get_resources(pdev);
if (IS_ERR(hpriv))
return PTR_ERR(hpriv);
drv_data->hpriv = hpriv;
err = st_ahci_probe_resets(pdev);
if (err)
return err;
err = ahci_platform_enable_resources(hpriv);
if (err)
return err;
err = ahci_platform_init_host(pdev, hpriv, &st_ahci_port_info, 0, 0);
if (err) {
ahci_platform_disable_resources(hpriv);
return err;
}
return 0;
}
static int st_ahci_suspend(struct device *dev)
{
struct st_ahci_drv_data *drv_data = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = drv_data->hpriv;
int err;
err = ahci_platform_suspend_host(dev);
if (err)
return err;
if (drv_data->pwr) {
err = reset_control_assert(drv_data->pwr);
if (err) {
dev_err(dev, "unable to pwrdwn");
return err;
}
}
ahci_platform_disable_resources(hpriv);
return 0;
}
static int st_ahci_resume(struct device *dev)
{
struct st_ahci_drv_data *drv_data = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = drv_data->hpriv;
int err;
err = ahci_platform_enable_resources(hpriv);
if (err)
return err;
err = st_ahci_deassert_resets(dev);
if (err) {
ahci_platform_disable_resources(hpriv);
return err;
}
return ahci_platform_resume_host(dev);
}
