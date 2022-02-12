static inline void vf610_mscm_ir_save(struct vf610_mscm_ir_chip_data *data)
{
int i;
for (i = 0; i < MSCM_IRSPRC_NUM; i++)
data->saved_irsprc[i] = readw_relaxed(data->mscm_ir_base + MSCM_IRSPRC(i));
}
static inline void vf610_mscm_ir_restore(struct vf610_mscm_ir_chip_data *data)
{
int i;
for (i = 0; i < MSCM_IRSPRC_NUM; i++)
writew_relaxed(data->saved_irsprc[i], data->mscm_ir_base + MSCM_IRSPRC(i));
}
static int vf610_mscm_ir_notifier(struct notifier_block *self,
unsigned long cmd, void *v)
{
switch (cmd) {
case CPU_CLUSTER_PM_ENTER:
vf610_mscm_ir_save(mscm_ir_data);
break;
case CPU_CLUSTER_PM_ENTER_FAILED:
case CPU_CLUSTER_PM_EXIT:
vf610_mscm_ir_restore(mscm_ir_data);
break;
}
return NOTIFY_OK;
}
static void vf610_mscm_ir_enable(struct irq_data *data)
{
irq_hw_number_t hwirq = data->hwirq;
struct vf610_mscm_ir_chip_data *chip_data = data->chip_data;
u16 irsprc;
irsprc = readw_relaxed(chip_data->mscm_ir_base + MSCM_IRSPRC(hwirq));
irsprc &= MSCM_IRSPRC_CPEN_MASK;
WARN_ON(irsprc & ~chip_data->cpu_mask);
writew_relaxed(chip_data->cpu_mask,
chip_data->mscm_ir_base + MSCM_IRSPRC(hwirq));
irq_chip_enable_parent(data);
}
static void vf610_mscm_ir_disable(struct irq_data *data)
{
irq_hw_number_t hwirq = data->hwirq;
struct vf610_mscm_ir_chip_data *chip_data = data->chip_data;
writew_relaxed(0x0, chip_data->mscm_ir_base + MSCM_IRSPRC(hwirq));
irq_chip_disable_parent(data);
}
static int vf610_mscm_ir_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
int i;
irq_hw_number_t hwirq;
struct irq_fwspec *fwspec = arg;
struct irq_fwspec parent_fwspec;
if (!irq_domain_get_of_node(domain->parent))
return -EINVAL;
if (fwspec->param_count != 2)
return -EINVAL;
hwirq = fwspec->param[0];
for (i = 0; i < nr_irqs; i++)
irq_domain_set_hwirq_and_chip(domain, virq + i, hwirq + i,
&vf610_mscm_ir_irq_chip,
domain->host_data);
parent_fwspec.fwnode = domain->parent->fwnode;
if (mscm_ir_data->is_nvic) {
parent_fwspec.param_count = 1;
parent_fwspec.param[0] = fwspec->param[0];
} else {
parent_fwspec.param_count = 3;
parent_fwspec.param[0] = GIC_SPI;
parent_fwspec.param[1] = fwspec->param[0];
parent_fwspec.param[2] = fwspec->param[1];
}
return irq_domain_alloc_irqs_parent(domain, virq, nr_irqs,
&parent_fwspec);
}
static int vf610_mscm_ir_domain_translate(struct irq_domain *d,
struct irq_fwspec *fwspec,
unsigned long *hwirq,
unsigned int *type)
{
if (WARN_ON(fwspec->param_count < 2))
return -EINVAL;
*hwirq = fwspec->param[0];
*type = fwspec->param[1] & IRQ_TYPE_SENSE_MASK;
return 0;
}
static int __init vf610_mscm_ir_of_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *domain, *domain_parent;
struct regmap *mscm_cp_regmap;
int ret, cpuid;
domain_parent = irq_find_host(parent);
if (!domain_parent) {
pr_err("vf610_mscm_ir: interrupt-parent not found\n");
return -EINVAL;
}
mscm_ir_data = kzalloc(sizeof(*mscm_ir_data), GFP_KERNEL);
if (!mscm_ir_data)
return -ENOMEM;
mscm_ir_data->mscm_ir_base = of_io_request_and_map(node, 0, "mscm-ir");
if (IS_ERR(mscm_ir_data->mscm_ir_base)) {
pr_err("vf610_mscm_ir: unable to map mscm register\n");
ret = PTR_ERR(mscm_ir_data->mscm_ir_base);
goto out_free;
}
mscm_cp_regmap = syscon_regmap_lookup_by_phandle(node, "fsl,cpucfg");
if (IS_ERR(mscm_cp_regmap)) {
ret = PTR_ERR(mscm_cp_regmap);
pr_err("vf610_mscm_ir: regmap lookup for cpucfg failed\n");
goto out_unmap;
}
regmap_read(mscm_cp_regmap, MSCM_CPxNUM, &cpuid);
mscm_ir_data->cpu_mask = 0x1 << cpuid;
domain = irq_domain_add_hierarchy(domain_parent, 0,
MSCM_IRSPRC_NUM, node,
&mscm_irq_domain_ops, mscm_ir_data);
if (!domain) {
ret = -ENOMEM;
goto out_unmap;
}
if (of_device_is_compatible(irq_domain_get_of_node(domain->parent),
"arm,armv7m-nvic"))
mscm_ir_data->is_nvic = true;
cpu_pm_register_notifier(&mscm_ir_notifier_block);
return 0;
out_unmap:
iounmap(mscm_ir_data->mscm_ir_base);
out_free:
kfree(mscm_ir_data);
return ret;
}
