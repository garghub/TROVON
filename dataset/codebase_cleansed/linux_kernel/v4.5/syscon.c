static struct syscon *of_syscon_register(struct device_node *np)
{
struct syscon *syscon;
struct regmap *regmap;
void __iomem *base;
u32 reg_io_width;
int ret;
struct regmap_config syscon_config = syscon_regmap_config;
if (!of_device_is_compatible(np, "syscon"))
return ERR_PTR(-EINVAL);
syscon = kzalloc(sizeof(*syscon), GFP_KERNEL);
if (!syscon)
return ERR_PTR(-ENOMEM);
base = of_iomap(np, 0);
if (!base) {
ret = -ENOMEM;
goto err_map;
}
if (of_property_read_bool(np, "big-endian"))
syscon_config.val_format_endian = REGMAP_ENDIAN_BIG;
else if (of_property_read_bool(np, "little-endian"))
syscon_config.val_format_endian = REGMAP_ENDIAN_LITTLE;
ret = of_property_read_u32(np, "reg-io-width", &reg_io_width);
if (ret)
reg_io_width = 4;
syscon_config.reg_stride = reg_io_width;
syscon_config.val_bits = reg_io_width * 8;
regmap = regmap_init_mmio(NULL, base, &syscon_config);
if (IS_ERR(regmap)) {
pr_err("regmap init failed\n");
ret = PTR_ERR(regmap);
goto err_regmap;
}
syscon->regmap = regmap;
syscon->np = np;
spin_lock(&syscon_list_slock);
list_add_tail(&syscon->list, &syscon_list);
spin_unlock(&syscon_list_slock);
return syscon;
err_regmap:
iounmap(base);
err_map:
kfree(syscon);
return ERR_PTR(ret);
}
struct regmap *syscon_node_to_regmap(struct device_node *np)
{
struct syscon *entry, *syscon = NULL;
spin_lock(&syscon_list_slock);
list_for_each_entry(entry, &syscon_list, list)
if (entry->np == np) {
syscon = entry;
break;
}
spin_unlock(&syscon_list_slock);
if (!syscon)
syscon = of_syscon_register(np);
if (IS_ERR(syscon))
return ERR_CAST(syscon);
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
if (property)
syscon_np = of_parse_phandle(np, property, 0);
else
syscon_np = np;
if (!syscon_np)
return ERR_PTR(-ENODEV);
regmap = syscon_node_to_regmap(syscon_np);
of_node_put(syscon_np);
return regmap;
}
static int syscon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct syscon_platform_data *pdata = dev_get_platdata(dev);
struct syscon *syscon;
struct resource *res;
void __iomem *base;
syscon = devm_kzalloc(dev, sizeof(*syscon), GFP_KERNEL);
if (!syscon)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
base = devm_ioremap(dev, res->start, resource_size(res));
if (!base)
return -ENOMEM;
syscon_regmap_config.max_register = res->end - res->start - 3;
if (pdata)
syscon_regmap_config.name = pdata->label;
syscon->regmap = devm_regmap_init_mmio(dev, base,
&syscon_regmap_config);
if (IS_ERR(syscon->regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(syscon->regmap);
}
platform_set_drvdata(pdev, syscon);
dev_dbg(dev, "regmap %pR registered\n", res);
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
