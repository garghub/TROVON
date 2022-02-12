static int imx7_gpc_pu_pgc_sw_pxx_req(struct generic_pm_domain *genpd,
bool on)
{
struct imx7_pgc_domain *domain = container_of(genpd,
struct imx7_pgc_domain,
genpd);
unsigned int offset = on ?
GPC_PU_PGC_SW_PUP_REQ : GPC_PU_PGC_SW_PDN_REQ;
const bool enable_power_control = !on;
const bool has_regulator = !IS_ERR(domain->regulator);
unsigned long deadline;
int ret = 0;
regmap_update_bits(domain->regmap, GPC_PGC_CPU_MAPPING,
domain->bits.map, domain->bits.map);
if (has_regulator && on) {
ret = regulator_enable(domain->regulator);
if (ret) {
dev_err(domain->dev, "failed to enable regulator\n");
goto unmap;
}
}
if (enable_power_control)
regmap_update_bits(domain->regmap, GPC_PGC_CTRL(domain->pgc),
GPC_PGC_CTRL_PCR, GPC_PGC_CTRL_PCR);
regmap_update_bits(domain->regmap, offset,
domain->bits.pxx, domain->bits.pxx);
deadline = jiffies + msecs_to_jiffies(1);
while (true) {
u32 pxx_req;
regmap_read(domain->regmap, offset, &pxx_req);
if (!(pxx_req & domain->bits.pxx))
break;
if (time_after(jiffies, deadline)) {
dev_err(domain->dev, "falied to command PGC\n");
ret = -ETIMEDOUT;
on = !on;
break;
}
cpu_relax();
}
if (enable_power_control)
regmap_update_bits(domain->regmap, GPC_PGC_CTRL(domain->pgc),
GPC_PGC_CTRL_PCR, 0);
if (has_regulator && !on) {
int err;
err = regulator_disable(domain->regulator);
if (err)
dev_err(domain->dev,
"failed to disable regulator: %d\n", ret);
ret = ret ?: err;
}
unmap:
regmap_update_bits(domain->regmap, GPC_PGC_CPU_MAPPING,
domain->bits.map, 0);
return ret;
}
static int imx7_gpc_pu_pgc_sw_pup_req(struct generic_pm_domain *genpd)
{
return imx7_gpc_pu_pgc_sw_pxx_req(genpd, true);
}
static int imx7_gpc_pu_pgc_sw_pdn_req(struct generic_pm_domain *genpd)
{
return imx7_gpc_pu_pgc_sw_pxx_req(genpd, false);
}
static int imx7_pgc_domain_probe(struct platform_device *pdev)
{
struct imx7_pgc_domain *domain = pdev->dev.platform_data;
int ret;
domain->dev = &pdev->dev;
domain->regulator = devm_regulator_get_optional(domain->dev, "power");
if (IS_ERR(domain->regulator)) {
if (PTR_ERR(domain->regulator) != -ENODEV) {
if (PTR_ERR(domain->regulator) != -EPROBE_DEFER)
dev_err(domain->dev, "Failed to get domain's regulator\n");
return PTR_ERR(domain->regulator);
}
} else {
regulator_set_voltage(domain->regulator,
domain->voltage, domain->voltage);
}
ret = pm_genpd_init(&domain->genpd, NULL, true);
if (ret) {
dev_err(domain->dev, "Failed to init power domain\n");
return ret;
}
ret = of_genpd_add_provider_simple(domain->dev->of_node,
&domain->genpd);
if (ret) {
dev_err(domain->dev, "Failed to add genpd provider\n");
pm_genpd_remove(&domain->genpd);
}
return ret;
}
static int imx7_pgc_domain_remove(struct platform_device *pdev)
{
struct imx7_pgc_domain *domain = pdev->dev.platform_data;
of_genpd_del_provider(domain->dev->of_node);
pm_genpd_remove(&domain->genpd);
return 0;
}
static int imx_gpcv2_probe(struct platform_device *pdev)
{
static const struct regmap_range yes_ranges[] = {
regmap_reg_range(GPC_LPCR_A7_BSC,
GPC_M4_PU_PDN_FLG),
regmap_reg_range(GPC_PGC_CTRL(PGC_MIPI),
GPC_PGC_SR(PGC_MIPI)),
regmap_reg_range(GPC_PGC_CTRL(PGC_PCIE),
GPC_PGC_SR(PGC_PCIE)),
regmap_reg_range(GPC_PGC_CTRL(PGC_USB_HSIC),
GPC_PGC_SR(PGC_USB_HSIC)),
};
static const struct regmap_access_table access_table = {
.yes_ranges = yes_ranges,
.n_yes_ranges = ARRAY_SIZE(yes_ranges),
};
static const struct regmap_config regmap_config = {
.reg_bits = 32,
.val_bits = 32,
.reg_stride = 4,
.rd_table = &access_table,
.wr_table = &access_table,
.max_register = SZ_4K,
};
struct device *dev = &pdev->dev;
struct device_node *pgc_np, *np;
struct regmap *regmap;
struct resource *res;
void __iomem *base;
int ret;
pgc_np = of_get_child_by_name(dev->of_node, "pgc");
if (!pgc_np) {
dev_err(dev, "No power domains specified in DT\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
regmap = devm_regmap_init_mmio(dev, base, &regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(dev, "failed to init regmap (%d)\n", ret);
return ret;
}
for_each_child_of_node(pgc_np, np) {
struct platform_device *pd_pdev;
struct imx7_pgc_domain *domain;
u32 domain_index;
ret = of_property_read_u32(np, "reg", &domain_index);
if (ret) {
dev_err(dev, "Failed to read 'reg' property\n");
of_node_put(np);
return ret;
}
if (domain_index >= ARRAY_SIZE(imx7_pgc_domains)) {
dev_warn(dev,
"Domain index %d is out of bounds\n",
domain_index);
continue;
}
domain = &imx7_pgc_domains[domain_index];
domain->regmap = regmap;
domain->genpd.power_on = imx7_gpc_pu_pgc_sw_pup_req;
domain->genpd.power_off = imx7_gpc_pu_pgc_sw_pdn_req;
pd_pdev = platform_device_alloc("imx7-pgc-domain",
domain_index);
if (!pd_pdev) {
dev_err(dev, "Failed to allocate platform device\n");
of_node_put(np);
return -ENOMEM;
}
pd_pdev->dev.platform_data = domain;
pd_pdev->dev.parent = dev;
pd_pdev->dev.of_node = np;
ret = platform_device_add(pd_pdev);
if (ret) {
platform_device_put(pd_pdev);
of_node_put(np);
return ret;
}
}
return 0;
}
