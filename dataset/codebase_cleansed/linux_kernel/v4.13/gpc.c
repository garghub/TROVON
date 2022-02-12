static inline struct imx_pm_domain *
to_imx_pm_domain(struct generic_pm_domain *genpd)
{
return container_of(genpd, struct imx_pm_domain, base);
}
static int imx6_pm_domain_power_off(struct generic_pm_domain *genpd)
{
struct imx_pm_domain *pd = to_imx_pm_domain(genpd);
int iso, iso2sw;
u32 val;
if (pd->flags & PGC_DOMAIN_FLAG_NO_PD)
return -EBUSY;
regmap_read(pd->regmap, pd->reg_offs + GPC_PGC_PUPSCR_OFFS, &val);
iso = val & 0x3f;
iso2sw = (val >> 8) & 0x3f;
regmap_update_bits(pd->regmap, pd->reg_offs + GPC_PGC_CTRL_OFFS,
0x1, 0x1);
val = BIT(pd->cntr_pdn_bit);
regmap_update_bits(pd->regmap, GPC_CNTR, val, val);
udelay(DIV_ROUND_UP(iso + iso2sw, pd->ipg_rate_mhz));
if (pd->supply)
regulator_disable(pd->supply);
return 0;
}
static int imx6_pm_domain_power_on(struct generic_pm_domain *genpd)
{
struct imx_pm_domain *pd = to_imx_pm_domain(genpd);
int i, ret, sw, sw2iso;
u32 val;
if (pd->supply) {
ret = regulator_enable(pd->supply);
if (ret) {
pr_err("%s: failed to enable regulator: %d\n",
__func__, ret);
return ret;
}
}
for (i = 0; i < pd->num_clks; i++)
clk_prepare_enable(pd->clk[i]);
regmap_update_bits(pd->regmap, pd->reg_offs + GPC_PGC_CTRL_OFFS,
0x1, 0x1);
regmap_read(pd->regmap, pd->reg_offs + GPC_PGC_PUPSCR_OFFS, &val);
sw = val & 0x3f;
sw2iso = (val >> 8) & 0x3f;
val = BIT(pd->cntr_pdn_bit + 1);
regmap_update_bits(pd->regmap, GPC_CNTR, val, val);
udelay(DIV_ROUND_UP(sw + sw2iso, pd->ipg_rate_mhz));
for (i = 0; i < pd->num_clks; i++)
clk_disable_unprepare(pd->clk[i]);
return 0;
}
static int imx_pgc_get_clocks(struct device *dev, struct imx_pm_domain *domain)
{
int i, ret;
for (i = 0; ; i++) {
struct clk *clk = of_clk_get(dev->of_node, i);
if (IS_ERR(clk))
break;
if (i >= GPC_CLK_MAX) {
dev_err(dev, "more than %d clocks\n", GPC_CLK_MAX);
ret = -EINVAL;
goto clk_err;
}
domain->clk[i] = clk;
}
domain->num_clks = i;
return 0;
clk_err:
while (i--)
clk_put(domain->clk[i]);
return ret;
}
static void imx_pgc_put_clocks(struct imx_pm_domain *domain)
{
int i;
for (i = domain->num_clks - 1; i >= 0; i--)
clk_put(domain->clk[i]);
}
static int imx_pgc_parse_dt(struct device *dev, struct imx_pm_domain *domain)
{
domain->supply = devm_regulator_get_optional(dev, "power");
if (IS_ERR(domain->supply)) {
if (PTR_ERR(domain->supply) == -ENODEV)
domain->supply = NULL;
else
return PTR_ERR(domain->supply);
}
return imx_pgc_get_clocks(dev, domain);
}
static int imx_pgc_power_domain_probe(struct platform_device *pdev)
{
struct imx_pm_domain *domain = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
int ret;
if (dev->of_node) {
ret = imx_pgc_parse_dt(dev, domain);
if (ret)
return ret;
}
if (domain->base.power_on)
domain->base.power_on(&domain->base);
if (IS_ENABLED(CONFIG_PM_GENERIC_DOMAINS)) {
pm_genpd_init(&domain->base, NULL, false);
ret = of_genpd_add_provider_simple(dev->of_node, &domain->base);
if (ret)
goto genpd_err;
}
device_link_add(dev, dev->parent, DL_FLAG_AUTOREMOVE);
return 0;
genpd_err:
pm_genpd_remove(&domain->base);
imx_pgc_put_clocks(domain);
return ret;
}
static int imx_pgc_power_domain_remove(struct platform_device *pdev)
{
struct imx_pm_domain *domain = pdev->dev.platform_data;
if (IS_ENABLED(CONFIG_PM_GENERIC_DOMAINS)) {
of_genpd_del_provider(pdev->dev.of_node);
pm_genpd_remove(&domain->base);
imx_pgc_put_clocks(domain);
}
return 0;
}
static int imx_gpc_old_dt_init(struct device *dev, struct regmap *regmap,
unsigned int num_domains)
{
struct imx_pm_domain *domain;
int i, ret;
for (i = 0; i < num_domains; i++) {
domain = &imx_gpc_domains[i];
domain->regmap = regmap;
domain->ipg_rate_mhz = 66;
if (i == 1) {
domain->supply = devm_regulator_get(dev, "pu");
if (IS_ERR(domain->supply))
return PTR_ERR(domain->supply);;
ret = imx_pgc_get_clocks(dev, domain);
if (ret)
goto clk_err;
domain->base.power_on(&domain->base);
}
}
for (i = 0; i < num_domains; i++)
pm_genpd_init(&imx_gpc_domains[i].base, NULL, false);
if (IS_ENABLED(CONFIG_PM_GENERIC_DOMAINS)) {
ret = of_genpd_add_provider_onecell(dev->of_node,
&imx_gpc_onecell_data);
if (ret)
goto genpd_err;
}
return 0;
genpd_err:
for (i = 0; i < num_domains; i++)
pm_genpd_remove(&imx_gpc_domains[i].base);
imx_pgc_put_clocks(&imx_gpc_domains[GPC_PGC_DOMAIN_PU]);
clk_err:
return ret;
}
static int imx_gpc_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(imx_gpc_dt_ids, &pdev->dev);
const struct imx_gpc_dt_data *of_id_data = of_id->data;
struct device_node *pgc_node;
struct regmap *regmap;
struct resource *res;
void __iomem *base;
int ret;
pgc_node = of_get_child_by_name(pdev->dev.of_node, "pgc");
if (!of_property_read_bool(pdev->dev.of_node, "#power-domain-cells") &&
!pgc_node)
return 0;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
regmap = devm_regmap_init_mmio_clk(&pdev->dev, NULL, base,
&imx_gpc_regmap_config);
if (IS_ERR(regmap)) {
ret = PTR_ERR(regmap);
dev_err(&pdev->dev, "failed to init regmap: %d\n",
ret);
return ret;
}
if (of_id_data->err009619_present)
imx_gpc_domains[GPC_PGC_DOMAIN_PU].flags |=
PGC_DOMAIN_FLAG_NO_PD;
if (!pgc_node) {
ret = imx_gpc_old_dt_init(&pdev->dev, regmap,
of_id_data->num_domains);
if (ret)
return ret;
} else {
struct imx_pm_domain *domain;
struct platform_device *pd_pdev;
struct device_node *np;
struct clk *ipg_clk;
unsigned int ipg_rate_mhz;
int domain_index;
ipg_clk = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(ipg_clk))
return PTR_ERR(ipg_clk);
ipg_rate_mhz = clk_get_rate(ipg_clk) / 1000000;
for_each_child_of_node(pgc_node, np) {
ret = of_property_read_u32(np, "reg", &domain_index);
if (ret) {
of_node_put(np);
return ret;
}
if (domain_index >= of_id_data->num_domains)
continue;
domain = &imx_gpc_domains[domain_index];
domain->regmap = regmap;
domain->ipg_rate_mhz = ipg_rate_mhz;
pd_pdev = platform_device_alloc("imx-pgc-power-domain",
domain_index);
if (!pd_pdev) {
of_node_put(np);
return -ENOMEM;
}
pd_pdev->dev.platform_data = domain;
pd_pdev->dev.parent = &pdev->dev;
pd_pdev->dev.of_node = np;
ret = platform_device_add(pd_pdev);
if (ret) {
platform_device_put(pd_pdev);
of_node_put(np);
return ret;
}
}
}
return 0;
}
static int imx_gpc_remove(struct platform_device *pdev)
{
int ret;
if (!of_get_child_by_name(pdev->dev.of_node, "pgc")) {
of_genpd_del_provider(pdev->dev.of_node);
ret = pm_genpd_remove(&imx_gpc_domains[GPC_PGC_DOMAIN_PU].base);
if (ret)
return ret;
imx_pgc_put_clocks(&imx_gpc_domains[GPC_PGC_DOMAIN_PU]);
ret = pm_genpd_remove(&imx_gpc_domains[GPC_PGC_DOMAIN_ARM].base);
if (ret)
return ret;
}
return 0;
}
