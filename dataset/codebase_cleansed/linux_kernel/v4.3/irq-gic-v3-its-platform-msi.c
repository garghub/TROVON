static int its_pmsi_prepare(struct irq_domain *domain, struct device *dev,
int nvec, msi_alloc_info_t *info)
{
struct msi_domain_info *msi_info;
u32 dev_id;
int ret;
msi_info = msi_get_domain_info(domain->parent);
ret = of_property_read_u32_index(dev->of_node, "msi-parent",
1, &dev_id);
if (ret)
return ret;
info->scratchpad[0].ul = dev_id;
return msi_info->ops->msi_prepare(domain->parent,
dev, nvec, info);
}
static int __init its_pmsi_init(void)
{
struct device_node *np;
struct irq_domain *parent;
for (np = of_find_matching_node(NULL, its_device_id); np;
np = of_find_matching_node(np, its_device_id)) {
if (!of_property_read_bool(np, "msi-controller"))
continue;
parent = irq_find_matching_host(np, DOMAIN_BUS_NEXUS);
if (!parent || !msi_get_domain_info(parent)) {
pr_err("%s: unable to locate ITS domain\n",
np->full_name);
continue;
}
if (!platform_msi_create_irq_domain(np, &its_pmsi_domain_info,
parent)) {
pr_err("%s: unable to create platform domain\n",
np->full_name);
continue;
}
pr_info("Platform MSI: %s domain created\n", np->full_name);
}
return 0;
}
