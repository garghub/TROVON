static struct mipi_dsim_platform_data *to_dsim_plat(struct platform_device
*pdev)
{
return pdev->dev.platform_data;
}
static int exynos_mipi_regulator_enable(struct mipi_dsim_device *dsim)
{
int ret;
mutex_lock(&dsim->lock);
ret = regulator_bulk_enable(ARRAY_SIZE(supplies), supplies);
mutex_unlock(&dsim->lock);
return ret;
}
static int exynos_mipi_regulator_disable(struct mipi_dsim_device *dsim)
{
int ret;
mutex_lock(&dsim->lock);
ret = regulator_bulk_disable(ARRAY_SIZE(supplies), supplies);
mutex_unlock(&dsim->lock);
return ret;
}
static void exynos_mipi_update_cfg(struct mipi_dsim_device *dsim)
{
exynos_mipi_dsi_stand_by(dsim, 0);
exynos_mipi_dsi_init_dsim(dsim);
exynos_mipi_dsi_init_link(dsim);
exynos_mipi_dsi_set_hs_enable(dsim);
exynos_mipi_dsi_set_display_mode(dsim, dsim->dsim_config);
exynos_mipi_dsi_init_interrupt(dsim);
exynos_mipi_dsi_stand_by(dsim, 1);
}
static int exynos_mipi_dsi_early_blank_mode(struct mipi_dsim_device *dsim,
int power)
{
struct mipi_dsim_lcd_driver *client_drv = dsim->dsim_lcd_drv;
struct mipi_dsim_lcd_device *client_dev = dsim->dsim_lcd_dev;
switch (power) {
case FB_BLANK_POWERDOWN:
if (dsim->suspended)
return 0;
if (client_drv && client_drv->suspend)
client_drv->suspend(client_dev);
clk_disable(dsim->clock);
exynos_mipi_regulator_disable(dsim);
dsim->suspended = true;
break;
default:
break;
}
return 0;
}
static int exynos_mipi_dsi_blank_mode(struct mipi_dsim_device *dsim, int power)
{
struct platform_device *pdev = to_platform_device(dsim->dev);
struct mipi_dsim_lcd_driver *client_drv = dsim->dsim_lcd_drv;
struct mipi_dsim_lcd_device *client_dev = dsim->dsim_lcd_dev;
switch (power) {
case FB_BLANK_UNBLANK:
if (!dsim->suspended)
return 0;
if (client_drv && client_drv->power_on)
client_drv->power_on(client_dev, 1);
exynos_mipi_regulator_enable(dsim);
if (dsim->pd->phy_enable)
dsim->pd->phy_enable(pdev, true);
clk_enable(dsim->clock);
exynos_mipi_update_cfg(dsim);
if (client_drv && client_drv->set_sequence)
client_drv->set_sequence(client_dev);
dsim->suspended = false;
break;
case FB_BLANK_NORMAL:
break;
default:
break;
}
return 0;
}
int exynos_mipi_dsi_register_lcd_device(struct mipi_dsim_lcd_device *lcd_dev)
{
struct mipi_dsim_ddi *dsim_ddi;
if (!lcd_dev->name) {
pr_err("dsim_lcd_device name is NULL.\n");
return -EFAULT;
}
dsim_ddi = kzalloc(sizeof(struct mipi_dsim_ddi), GFP_KERNEL);
if (!dsim_ddi) {
pr_err("failed to allocate dsim_ddi object.\n");
return -ENOMEM;
}
dsim_ddi->dsim_lcd_dev = lcd_dev;
mutex_lock(&mipi_dsim_lock);
list_add_tail(&dsim_ddi->list, &dsim_ddi_list);
mutex_unlock(&mipi_dsim_lock);
return 0;
}
struct mipi_dsim_ddi *exynos_mipi_dsi_find_lcd_device(struct mipi_dsim_lcd_driver *lcd_drv)
{
struct mipi_dsim_ddi *dsim_ddi, *next;
struct mipi_dsim_lcd_device *lcd_dev;
mutex_lock(&mipi_dsim_lock);
list_for_each_entry_safe(dsim_ddi, next, &dsim_ddi_list, list) {
if (!dsim_ddi)
goto out;
lcd_dev = dsim_ddi->dsim_lcd_dev;
if (!lcd_dev)
continue;
if ((strcmp(lcd_drv->name, lcd_dev->name)) == 0) {
dsim_ddi->bus_id = lcd_dev->bus_id;
mutex_unlock(&mipi_dsim_lock);
return dsim_ddi;
}
list_del(&dsim_ddi->list);
kfree(dsim_ddi);
}
out:
mutex_unlock(&mipi_dsim_lock);
return NULL;
}
int exynos_mipi_dsi_register_lcd_driver(struct mipi_dsim_lcd_driver *lcd_drv)
{
struct mipi_dsim_ddi *dsim_ddi;
if (!lcd_drv->name) {
pr_err("dsim_lcd_driver name is NULL.\n");
return -EFAULT;
}
dsim_ddi = exynos_mipi_dsi_find_lcd_device(lcd_drv);
if (!dsim_ddi) {
pr_err("mipi_dsim_ddi object not found.\n");
return -EFAULT;
}
dsim_ddi->dsim_lcd_drv = lcd_drv;
pr_info("registered panel driver(%s) to mipi-dsi driver.\n",
lcd_drv->name);
return 0;
}
struct mipi_dsim_ddi *exynos_mipi_dsi_bind_lcd_ddi(struct mipi_dsim_device *dsim,
const char *name)
{
struct mipi_dsim_ddi *dsim_ddi, *next;
struct mipi_dsim_lcd_driver *lcd_drv;
struct mipi_dsim_lcd_device *lcd_dev;
int ret;
mutex_lock(&dsim->lock);
list_for_each_entry_safe(dsim_ddi, next, &dsim_ddi_list, list) {
lcd_drv = dsim_ddi->dsim_lcd_drv;
lcd_dev = dsim_ddi->dsim_lcd_dev;
if (!lcd_drv || !lcd_dev ||
(dsim->id != dsim_ddi->bus_id))
continue;
dev_dbg(dsim->dev, "lcd_drv->id = %d, lcd_dev->id = %d\n",
lcd_drv->id, lcd_dev->id);
dev_dbg(dsim->dev, "lcd_dev->bus_id = %d, dsim->id = %d\n",
lcd_dev->bus_id, dsim->id);
if ((strcmp(lcd_drv->name, name) == 0)) {
lcd_dev->master = dsim;
lcd_dev->dev.parent = dsim->dev;
dev_set_name(&lcd_dev->dev, "%s", lcd_drv->name);
ret = device_register(&lcd_dev->dev);
if (ret < 0) {
dev_err(dsim->dev,
"can't register %s, status %d\n",
dev_name(&lcd_dev->dev), ret);
mutex_unlock(&dsim->lock);
return NULL;
}
dsim->dsim_lcd_dev = lcd_dev;
dsim->dsim_lcd_drv = lcd_drv;
mutex_unlock(&dsim->lock);
return dsim_ddi;
}
}
mutex_unlock(&dsim->lock);
return NULL;
}
static int exynos_mipi_dsi_probe(struct platform_device *pdev)
{
struct resource *res;
struct mipi_dsim_device *dsim;
struct mipi_dsim_config *dsim_config;
struct mipi_dsim_platform_data *dsim_pd;
struct mipi_dsim_ddi *dsim_ddi;
int ret = -EINVAL;
dsim = kzalloc(sizeof(struct mipi_dsim_device), GFP_KERNEL);
if (!dsim) {
dev_err(&pdev->dev, "failed to allocate dsim object.\n");
return -ENOMEM;
}
dsim->pd = to_dsim_plat(pdev);
dsim->dev = &pdev->dev;
dsim->id = pdev->id;
dsim_pd = (struct mipi_dsim_platform_data *)dsim->pd;
if (dsim_pd == NULL) {
dev_err(&pdev->dev, "failed to get platform data for dsim.\n");
goto err_clock_get;
}
dsim_config = dsim_pd->dsim_config;
if (dsim_config == NULL) {
dev_err(&pdev->dev, "failed to get dsim config data.\n");
goto err_clock_get;
}
dsim->dsim_config = dsim_config;
dsim->master_ops = &master_ops;
mutex_init(&dsim->lock);
ret = regulator_bulk_get(&pdev->dev, ARRAY_SIZE(supplies), supplies);
if (ret) {
dev_err(&pdev->dev, "Failed to get regulators: %d\n", ret);
goto err_clock_get;
}
dsim->clock = clk_get(&pdev->dev, "dsim0");
if (IS_ERR(dsim->clock)) {
dev_err(&pdev->dev, "failed to get dsim clock source\n");
goto err_clock_get;
}
clk_enable(dsim->clock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get io memory region\n");
goto err_platform_get;
}
dsim->res = request_mem_region(res->start, resource_size(res),
dev_name(&pdev->dev));
if (!dsim->res) {
dev_err(&pdev->dev, "failed to request io memory region\n");
ret = -ENOMEM;
goto err_mem_region;
}
dsim->reg_base = ioremap(res->start, resource_size(res));
if (!dsim->reg_base) {
dev_err(&pdev->dev, "failed to remap io region\n");
ret = -ENOMEM;
goto err_ioremap;
}
mutex_init(&dsim->lock);
dsim_ddi = exynos_mipi_dsi_bind_lcd_ddi(dsim, dsim_pd->lcd_panel_name);
if (!dsim_ddi) {
dev_err(&pdev->dev, "mipi_dsim_ddi object not found.\n");
goto err_bind;
}
dsim->irq = platform_get_irq(pdev, 0);
if (dsim->irq < 0) {
dev_err(&pdev->dev, "failed to request dsim irq resource\n");
ret = -EINVAL;
goto err_platform_get_irq;
}
init_completion(&dsim_wr_comp);
init_completion(&dsim_rd_comp);
platform_set_drvdata(pdev, dsim);
ret = request_irq(dsim->irq, exynos_mipi_dsi_interrupt_handler,
IRQF_SHARED, dev_name(&pdev->dev), dsim);
if (ret != 0) {
dev_err(&pdev->dev, "failed to request dsim irq\n");
ret = -EINVAL;
goto err_bind;
}
exynos_mipi_dsi_init_interrupt(dsim);
if (dsim_ddi->dsim_lcd_drv && dsim_ddi->dsim_lcd_drv->probe)
dsim_ddi->dsim_lcd_drv->probe(dsim_ddi->dsim_lcd_dev);
if (dsim_pd->enabled) {
exynos_mipi_regulator_enable(dsim);
goto done;
}
if (dsim_ddi->dsim_lcd_drv && dsim_ddi->dsim_lcd_drv->power_on)
dsim_ddi->dsim_lcd_drv->power_on(dsim_ddi->dsim_lcd_dev, 1);
exynos_mipi_regulator_enable(dsim);
if (dsim->pd->phy_enable)
dsim->pd->phy_enable(pdev, true);
exynos_mipi_update_cfg(dsim);
if (dsim_ddi->dsim_lcd_drv && dsim_ddi->dsim_lcd_drv->set_sequence)
dsim_ddi->dsim_lcd_drv->set_sequence(dsim_ddi->dsim_lcd_dev);
dsim->suspended = false;
done:
platform_set_drvdata(pdev, dsim);
dev_dbg(&pdev->dev, "%s() completed sucessfuly (%s mode)\n", __func__,
dsim_config->e_interface == DSIM_COMMAND ? "CPU" : "RGB");
return 0;
err_bind:
iounmap(dsim->reg_base);
err_ioremap:
release_mem_region(dsim->res->start, resource_size(dsim->res));
err_mem_region:
release_resource(dsim->res);
err_platform_get:
clk_disable(dsim->clock);
clk_put(dsim->clock);
err_clock_get:
kfree(dsim);
err_platform_get_irq:
return ret;
}
static int __devexit exynos_mipi_dsi_remove(struct platform_device *pdev)
{
struct mipi_dsim_device *dsim = platform_get_drvdata(pdev);
struct mipi_dsim_ddi *dsim_ddi, *next;
struct mipi_dsim_lcd_driver *dsim_lcd_drv;
iounmap(dsim->reg_base);
clk_disable(dsim->clock);
clk_put(dsim->clock);
release_resource(dsim->res);
release_mem_region(dsim->res->start, resource_size(dsim->res));
list_for_each_entry_safe(dsim_ddi, next, &dsim_ddi_list, list) {
if (dsim_ddi) {
if (dsim->id != dsim_ddi->bus_id)
continue;
dsim_lcd_drv = dsim_ddi->dsim_lcd_drv;
if (dsim_lcd_drv->remove)
dsim_lcd_drv->remove(dsim_ddi->dsim_lcd_dev);
kfree(dsim_ddi);
}
}
regulator_bulk_free(ARRAY_SIZE(supplies), supplies);
kfree(dsim);
return 0;
}
static int exynos_mipi_dsi_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct mipi_dsim_device *dsim = platform_get_drvdata(pdev);
struct mipi_dsim_lcd_driver *client_drv = dsim->dsim_lcd_drv;
struct mipi_dsim_lcd_device *client_dev = dsim->dsim_lcd_dev;
disable_irq(dsim->irq);
if (dsim->suspended)
return 0;
if (client_drv && client_drv->suspend)
client_drv->suspend(client_dev);
if (dsim->pd->phy_enable)
dsim->pd->phy_enable(pdev, false);
clk_disable(dsim->clock);
exynos_mipi_regulator_disable(dsim);
dsim->suspended = true;
return 0;
}
static int exynos_mipi_dsi_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct mipi_dsim_device *dsim = platform_get_drvdata(pdev);
struct mipi_dsim_lcd_driver *client_drv = dsim->dsim_lcd_drv;
struct mipi_dsim_lcd_device *client_dev = dsim->dsim_lcd_dev;
enable_irq(dsim->irq);
if (!dsim->suspended)
return 0;
if (client_drv && client_drv->power_on)
client_drv->power_on(client_dev, 1);
exynos_mipi_regulator_enable(dsim);
if (dsim->pd->phy_enable)
dsim->pd->phy_enable(pdev, true);
clk_enable(dsim->clock);
exynos_mipi_update_cfg(dsim);
if (client_drv && client_drv->set_sequence)
client_drv->set_sequence(client_dev);
dsim->suspended = false;
return 0;
}
