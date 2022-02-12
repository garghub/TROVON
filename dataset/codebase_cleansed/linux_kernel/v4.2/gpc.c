void imx_gpc_set_arm_power_up_timing(u32 sw2iso, u32 sw)
{
writel_relaxed((sw2iso << GPC_PGC_SW2ISO_SHIFT) |
(sw << GPC_PGC_SW_SHIFT), gpc_base + GPC_PGC_CPU_PUPSCR);
}
void imx_gpc_set_arm_power_down_timing(u32 sw2iso, u32 sw)
{
writel_relaxed((sw2iso << GPC_PGC_SW2ISO_SHIFT) |
(sw << GPC_PGC_SW_SHIFT), gpc_base + GPC_PGC_CPU_PDNSCR);
}
void imx_gpc_set_arm_power_in_lpm(bool power_off)
{
writel_relaxed(power_off, gpc_base + GPC_PGC_CPU_PDN);
}
void imx_gpc_pre_suspend(bool arm_power_off)
{
void __iomem *reg_imr1 = gpc_base + GPC_IMR1;
int i;
if (arm_power_off)
imx_gpc_set_arm_power_in_lpm(arm_power_off);
for (i = 0; i < IMR_NUM; i++) {
gpc_saved_imrs[i] = readl_relaxed(reg_imr1 + i * 4);
writel_relaxed(~gpc_wake_irqs[i], reg_imr1 + i * 4);
}
}
void imx_gpc_post_resume(void)
{
void __iomem *reg_imr1 = gpc_base + GPC_IMR1;
int i;
imx_gpc_set_arm_power_in_lpm(false);
for (i = 0; i < IMR_NUM; i++)
writel_relaxed(gpc_saved_imrs[i], reg_imr1 + i * 4);
}
static int imx_gpc_irq_set_wake(struct irq_data *d, unsigned int on)
{
unsigned int idx = d->hwirq / 32;
u32 mask;
mask = 1 << d->hwirq % 32;
gpc_wake_irqs[idx] = on ? gpc_wake_irqs[idx] | mask :
gpc_wake_irqs[idx] & ~mask;
return 0;
}
void imx_gpc_mask_all(void)
{
void __iomem *reg_imr1 = gpc_base + GPC_IMR1;
int i;
for (i = 0; i < IMR_NUM; i++) {
gpc_saved_imrs[i] = readl_relaxed(reg_imr1 + i * 4);
writel_relaxed(~0, reg_imr1 + i * 4);
}
}
void imx_gpc_restore_all(void)
{
void __iomem *reg_imr1 = gpc_base + GPC_IMR1;
int i;
for (i = 0; i < IMR_NUM; i++)
writel_relaxed(gpc_saved_imrs[i], reg_imr1 + i * 4);
}
void imx_gpc_hwirq_unmask(unsigned int hwirq)
{
void __iomem *reg;
u32 val;
reg = gpc_base + GPC_IMR1 + hwirq / 32 * 4;
val = readl_relaxed(reg);
val &= ~(1 << hwirq % 32);
writel_relaxed(val, reg);
}
void imx_gpc_hwirq_mask(unsigned int hwirq)
{
void __iomem *reg;
u32 val;
reg = gpc_base + GPC_IMR1 + hwirq / 32 * 4;
val = readl_relaxed(reg);
val |= 1 << (hwirq % 32);
writel_relaxed(val, reg);
}
static void imx_gpc_irq_unmask(struct irq_data *d)
{
imx_gpc_hwirq_unmask(d->hwirq);
irq_chip_unmask_parent(d);
}
static void imx_gpc_irq_mask(struct irq_data *d)
{
imx_gpc_hwirq_mask(d->hwirq);
irq_chip_mask_parent(d);
}
static int imx_gpc_domain_xlate(struct irq_domain *domain,
struct device_node *controller,
const u32 *intspec,
unsigned int intsize,
unsigned long *out_hwirq,
unsigned int *out_type)
{
if (domain->of_node != controller)
return -EINVAL;
if (intsize != 3)
return -EINVAL;
if (intspec[0] != 0)
return -EINVAL;
*out_hwirq = intspec[1];
*out_type = intspec[2];
return 0;
}
static int imx_gpc_domain_alloc(struct irq_domain *domain,
unsigned int irq,
unsigned int nr_irqs, void *data)
{
struct of_phandle_args *args = data;
struct of_phandle_args parent_args;
irq_hw_number_t hwirq;
int i;
if (args->args_count != 3)
return -EINVAL;
if (args->args[0] != 0)
return -EINVAL;
hwirq = args->args[1];
if (hwirq >= GPC_MAX_IRQS)
return -EINVAL;
for (i = 0; i < nr_irqs; i++)
irq_domain_set_hwirq_and_chip(domain, irq + i, hwirq + i,
&imx_gpc_chip, NULL);
parent_args = *args;
parent_args.np = domain->parent->of_node;
return irq_domain_alloc_irqs_parent(domain, irq, nr_irqs, &parent_args);
}
static int __init imx_gpc_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *parent_domain, *domain;
int i;
if (!parent) {
pr_err("%s: no parent, giving up\n", node->full_name);
return -ENODEV;
}
parent_domain = irq_find_host(parent);
if (!parent_domain) {
pr_err("%s: unable to obtain parent domain\n", node->full_name);
return -ENXIO;
}
gpc_base = of_iomap(node, 0);
if (WARN_ON(!gpc_base))
return -ENOMEM;
domain = irq_domain_add_hierarchy(parent_domain, 0, GPC_MAX_IRQS,
node, &imx_gpc_domain_ops,
NULL);
if (!domain) {
iounmap(gpc_base);
return -ENOMEM;
}
for (i = 0; i < IMR_NUM; i++)
writel_relaxed(~0, gpc_base + GPC_IMR1 + i * 4);
return 0;
}
void __init imx_gpc_check_dt(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-gpc");
if (WARN_ON(!np))
return;
if (WARN_ON(!of_find_property(np, "interrupt-controller", NULL))) {
pr_warn("Outdated DT detected, suspend/resume will NOT work\n");
gpc_base = of_iomap(np, 0);
}
}
static void _imx6q_pm_pu_power_off(struct generic_pm_domain *genpd)
{
int iso, iso2sw;
u32 val;
val = readl_relaxed(gpc_base + GPC_PGC_GPU_PDNSCR);
iso = val & 0x3f;
iso2sw = (val >> 8) & 0x3f;
writel_relaxed(0x1, gpc_base + GPC_PGC_GPU_PDN);
val = readl_relaxed(gpc_base + GPC_CNTR);
val |= GPU_VPU_PDN_REQ;
writel_relaxed(val, gpc_base + GPC_CNTR);
ndelay((iso + iso2sw) * 1000 / 66);
}
static int imx6q_pm_pu_power_off(struct generic_pm_domain *genpd)
{
struct pu_domain *pu = container_of(genpd, struct pu_domain, base);
_imx6q_pm_pu_power_off(genpd);
if (pu->reg)
regulator_disable(pu->reg);
return 0;
}
static int imx6q_pm_pu_power_on(struct generic_pm_domain *genpd)
{
struct pu_domain *pu = container_of(genpd, struct pu_domain, base);
int i, ret, sw, sw2iso;
u32 val;
if (pu->reg)
ret = regulator_enable(pu->reg);
if (pu->reg && ret) {
pr_err("%s: failed to enable regulator: %d\n", __func__, ret);
return ret;
}
for (i = 0; i < pu->num_clks; i++)
clk_prepare_enable(pu->clk[i]);
writel_relaxed(0x1, gpc_base + GPC_PGC_GPU_PDN);
val = readl_relaxed(gpc_base + GPC_PGC_GPU_PUPSCR);
sw = val & 0x3f;
sw2iso = (val >> 8) & 0x3f;
val = readl_relaxed(gpc_base + GPC_CNTR);
val |= GPU_VPU_PUP_REQ;
writel_relaxed(val, gpc_base + GPC_CNTR);
ndelay((sw + sw2iso) * 1000 / 66);
for (i = 0; i < pu->num_clks; i++)
clk_disable_unprepare(pu->clk[i]);
return 0;
}
static int imx_gpc_genpd_init(struct device *dev, struct regulator *pu_reg)
{
struct clk *clk;
int i;
imx6q_pu_domain.reg = pu_reg;
for (i = 0; ; i++) {
clk = of_clk_get(dev->of_node, i);
if (IS_ERR(clk))
break;
if (i >= GPC_CLK_MAX) {
dev_err(dev, "more than %d clocks\n", GPC_CLK_MAX);
goto clk_err;
}
imx6q_pu_domain.clk[i] = clk;
}
imx6q_pu_domain.num_clks = i;
imx6q_pm_pu_power_on(&imx6q_pu_domain.base);
if (!IS_ENABLED(CONFIG_PM_GENERIC_DOMAINS))
return 0;
pm_genpd_init(&imx6q_pu_domain.base, NULL, false);
return of_genpd_add_provider_onecell(dev->of_node,
&imx_gpc_onecell_data);
clk_err:
while (i--)
clk_put(imx6q_pu_domain.clk[i]);
return -EINVAL;
}
static int imx_gpc_probe(struct platform_device *pdev)
{
struct regulator *pu_reg;
int ret;
if (!of_property_read_bool(pdev->dev.of_node, "#power-domain-cells"))
return 0;
pu_reg = devm_regulator_get_optional(&pdev->dev, "pu");
if (PTR_ERR(pu_reg) == -ENODEV)
pu_reg = NULL;
if (IS_ERR(pu_reg)) {
ret = PTR_ERR(pu_reg);
dev_err(&pdev->dev, "failed to get pu regulator: %d\n", ret);
return ret;
}
return imx_gpc_genpd_init(&pdev->dev, pu_reg);
}
static int __init imx_pgc_init(void)
{
return platform_driver_register(&imx_gpc_driver);
}
