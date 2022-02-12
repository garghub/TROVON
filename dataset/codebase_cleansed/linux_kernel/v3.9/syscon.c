static int syscon_match(struct device *dev, void *data)
{
struct syscon *syscon = dev_get_drvdata(dev);
struct device_node *dn = data;
return (syscon->dev->of_node == dn) ? 1 : 0;
}
struct regmap *syscon_node_to_regmap(struct device_node *np)
{
struct syscon *syscon;
struct device *dev;
dev = driver_find_device(&syscon_driver.driver, NULL, np,
syscon_match);
if (!dev)
return ERR_PTR(-EPROBE_DEFER);
syscon = dev_get_drvdata(dev);
return syscon->regmap;
}
struct regmap *syscon_regmap_lookup_by_compatible(const char *s)
{
struct device_node *syscon_np;
struct regmap *regmap;
syscon_np = of_find_compatible_node(NULL, NULL, s);
if (!syscon_np)
return ERR_PTR(-ENODEV);
regmap = syscon_node_to_regmap(syscon_np);
of_node_put(syscon_np);
return regmap;
}
struct regmap *syscon_regmap_lookup_by_phandle(struct device_node *np,
const char *property)
{
struct device_node *syscon_np;
struct regmap *regmap;
syscon_np = of_parse_phandle(np, property, 0);
if (!syscon_np)
return ERR_PTR(-ENODEV);
regmap = syscon_node_to_regmap(syscon_np);
of_node_put(syscon_np);
return regmap;
}
static int syscon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct syscon *syscon;
struct resource res;
int ret;
if (!np)
return -ENOENT;
syscon = devm_kzalloc(dev, sizeof(struct syscon),
GFP_KERNEL);
if (!syscon)
return -ENOMEM;
syscon->base = of_iomap(np, 0);
if (!syscon->base)
return -EADDRNOTAVAIL;
ret = of_address_to_resource(np, 0, &res);
if (ret)
return ret;
syscon_regmap_config.max_register = res.end - res.start - 3;
syscon->regmap = devm_regmap_init_mmio(dev, syscon->base,
&syscon_regmap_config);
if (IS_ERR(syscon->regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(syscon->regmap);
}
syscon->dev = dev;
platform_set_drvdata(pdev, syscon);
dev_info(dev, "syscon regmap start 0x%x end 0x%x registered\n",
res.start, res.end);
return 0;
}
static int syscon_remove(struct platform_device *pdev)
{
struct syscon *syscon;
syscon = platform_get_drvdata(pdev);
iounmap(syscon->base);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init syscon_init(void)
{
return platform_driver_register(&syscon_driver);
}
static void __exit syscon_exit(void)
{
platform_driver_unregister(&syscon_driver);
}
