int of_flash_probe_gemini(struct platform_device *pdev,
struct device_node *np,
struct map_info *map)
{
struct regmap *rmap;
struct device *dev = &pdev->dev;
u32 val;
int ret;
if (!of_device_is_compatible(np, "cortina,gemini-flash"))
return 0;
rmap = syscon_regmap_lookup_by_phandle(np, "syscon");
if (IS_ERR(rmap)) {
dev_err(dev, "no syscon\n");
return PTR_ERR(rmap);
}
ret = regmap_read(rmap, GLOBAL_STATUS, &val);
if (ret) {
dev_err(dev, "failed to read global status register\n");
return -ENODEV;
}
dev_dbg(dev, "global status reg: %08x\n", val);
if ((val & FLASH_TYPE_MASK) != FLASH_TYPE_PARALLEL) {
dev_err(dev, "flash is not parallel\n");
return -ENODEV;
}
if (val & FLASH_WIDTH_16BIT) {
if (map->bankwidth != 2)
dev_warn(dev, "flash hardware say flash is 16 bit wide but DT says it is %d bits wide\n",
map->bankwidth * 8);
} else {
if (map->bankwidth != 1)
dev_warn(dev, "flash hardware say flash is 8 bit wide but DT says it is %d bits wide\n",
map->bankwidth * 8);
}
dev_info(&pdev->dev, "initialized Gemini-specific physmap control\n");
return 0;
}
