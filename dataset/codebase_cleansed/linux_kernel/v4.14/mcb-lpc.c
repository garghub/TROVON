static int mcb_lpc_probe(struct platform_device *pdev)
{
struct resource *res;
struct priv *priv;
int ret = 0;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!priv->mem) {
dev_err(&pdev->dev, "No Memory resource\n");
return -ENODEV;
}
res = devm_request_mem_region(&pdev->dev, priv->mem->start,
resource_size(priv->mem),
KBUILD_MODNAME);
if (!res) {
dev_err(&pdev->dev, "Failed to request IO memory\n");
return -EBUSY;
}
priv->base = devm_ioremap(&pdev->dev, priv->mem->start,
resource_size(priv->mem));
if (!priv->base) {
dev_err(&pdev->dev, "Cannot ioremap\n");
return -ENOMEM;
}
platform_set_drvdata(pdev, priv);
priv->bus = mcb_alloc_bus(&pdev->dev);
if (IS_ERR(priv->bus))
return PTR_ERR(priv->bus);
ret = chameleon_parse_cells(priv->bus, priv->mem->start, priv->base);
if (ret < 0) {
mcb_release_bus(priv->bus);
return ret;
}
dev_dbg(&pdev->dev, "Found %d cells\n", ret);
mcb_bus_add_devices(priv->bus);
return 0;
}
static int mcb_lpc_remove(struct platform_device *pdev)
{
struct priv *priv = platform_get_drvdata(pdev);
mcb_release_bus(priv->bus);
return 0;
}
static int mcb_lpc_create_platform_device(const struct dmi_system_id *id)
{
struct resource *res = id->driver_data;
int ret;
mcb_lpc_pdev = platform_device_alloc("mcb-lpc", -1);
if (!mcb_lpc_pdev)
return -ENOMEM;
ret = platform_device_add_resources(mcb_lpc_pdev, res, 1);
if (ret)
goto out_put;
ret = platform_device_add(mcb_lpc_pdev);
if (ret)
goto out_put;
return 0;
out_put:
platform_device_put(mcb_lpc_pdev);
return ret;
}
static int __init mcb_lpc_init(void)
{
if (!dmi_check_system(mcb_lpc_dmi_table))
return -ENODEV;
return platform_driver_register(&mcb_lpc_driver);
}
static void __exit mcb_lpc_exit(void)
{
platform_device_unregister(mcb_lpc_pdev);
platform_driver_unregister(&mcb_lpc_driver);
}
