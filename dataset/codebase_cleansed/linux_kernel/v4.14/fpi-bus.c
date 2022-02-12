static int ltq_fpi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct resource *res_xbar;
struct regmap *rcu_regmap;
void __iomem *xbar_membase;
u32 rcu_ahb_endianness_reg_offset;
int ret;
res_xbar = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xbar_membase = devm_ioremap_resource(dev, res_xbar);
if (IS_ERR(xbar_membase))
return PTR_ERR(xbar_membase);
rcu_regmap = syscon_regmap_lookup_by_phandle(np, "lantiq,rcu");
if (IS_ERR(rcu_regmap))
return PTR_ERR(rcu_regmap);
ret = device_property_read_u32(dev, "lantiq,offset-endianness",
&rcu_ahb_endianness_reg_offset);
if (ret) {
dev_err(&pdev->dev, "Failed to get RCU reg offset\n");
return ret;
}
ret = regmap_update_bits(rcu_regmap, rcu_ahb_endianness_reg_offset,
RCU_VR9_BE_AHB1S, RCU_VR9_BE_AHB1S);
if (ret) {
dev_warn(&pdev->dev,
"Failed to configure RCU AHB endianness\n");
return ret;
}
ltq_w32_mask(XBAR_FPI_BURST_EN, 0, xbar_membase + XBAR_ALWAYS_LAST);
return of_platform_populate(dev->of_node, NULL, NULL, dev);
}
