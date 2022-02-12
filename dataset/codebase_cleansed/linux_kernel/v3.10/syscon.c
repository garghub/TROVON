static int syscon_match_node(struct device *dev, void *data)
{
struct device_node *dn = data;
return (dev->of_node == dn) ? 1 : 0;
}
struct regmap *syscon_node_to_regmap(struct device_node *np)
{
struct syscon *syscon;
struct device *dev;
dev = driver_find_device(&syscon_driver.driver, NULL, np,
syscon_match_node);
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
static int syscon_match_pdevname(struct device *dev, void *data)
{
struct platform_device *pdev = to_platform_device(dev);
const struct platform_device_id *id = platform_get_device_id(pdev);
if (id)
if (!strcmp(id->name, (const char *)data))
return 1;
return !strcmp(dev_name(dev), (const char *)data);
}
struct regmap *syscon_regmap_lookup_by_pdevname(const char *s)
{
struct device *dev;
struct syscon *syscon;
dev = driver_find_device(&syscon_driver.driver, NULL, (void *)s,
syscon_match_pdevname);
if (!dev)
return ERR_PTR(-EPROBE_DEFER);
syscon = dev_get_drvdata(dev);
return syscon->regmap;
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
struct syscon *syscon;
struct resource *res;
syscon = devm_kzalloc(dev, sizeof(*syscon), GFP_KERNEL);
if (!syscon)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
syscon->base = devm_ioremap(dev, res->start, resource_size(res));
if (!syscon->base)
return -ENOMEM;
syscon_regmap_config.max_register = res->end - res->start - 3;
syscon->regmap = devm_regmap_init_mmio(dev, syscon->base,
&syscon_regmap_config);
if (IS_ERR(syscon->regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(syscon->regmap);
}
platform_set_drvdata(pdev, syscon);
dev_info(dev, "regmap %pR registered\n", res);
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
