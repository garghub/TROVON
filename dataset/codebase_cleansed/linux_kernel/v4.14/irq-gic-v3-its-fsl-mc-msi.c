static int its_fsl_mc_msi_prepare(struct irq_domain *msi_domain,
struct device *dev,
int nvec, msi_alloc_info_t *info)
{
struct fsl_mc_device *mc_bus_dev;
struct msi_domain_info *msi_info;
if (WARN_ON(!dev_is_fsl_mc(dev)))
return -EINVAL;
mc_bus_dev = to_fsl_mc_device(dev);
if (WARN_ON(!(mc_bus_dev->flags & FSL_MC_IS_DPRC)))
return -EINVAL;
#ifdef GENERIC_MSI_DOMAIN_OPS
info->scratchpad[0].ul = mc_bus_dev->icid;
#endif
msi_info = msi_get_domain_info(msi_domain->parent);
return msi_info->ops->msi_prepare(msi_domain->parent, dev, nvec, info);
}
int __init its_fsl_mc_msi_init(void)
{
struct device_node *np;
struct irq_domain *parent;
struct irq_domain *mc_msi_domain;
for (np = of_find_matching_node(NULL, its_device_id); np;
np = of_find_matching_node(np, its_device_id)) {
if (!of_property_read_bool(np, "msi-controller"))
continue;
parent = irq_find_matching_host(np, DOMAIN_BUS_NEXUS);
if (!parent || !msi_get_domain_info(parent)) {
pr_err("%pOF: unable to locate ITS domain\n", np);
continue;
}
mc_msi_domain = fsl_mc_msi_create_irq_domain(
of_node_to_fwnode(np),
&its_fsl_mc_msi_domain_info,
parent);
if (!mc_msi_domain) {
pr_err("%pOF: unable to create fsl-mc domain\n", np);
continue;
}
WARN_ON(mc_msi_domain->host_data !=
&its_fsl_mc_msi_domain_info);
pr_info("fsl-mc MSI: %pOF domain created\n", np);
}
return 0;
}
void its_fsl_mc_msi_cleanup(void)
{
struct device_node *np;
for (np = of_find_matching_node(NULL, its_device_id); np;
np = of_find_matching_node(np, its_device_id)) {
struct irq_domain *mc_msi_domain = irq_find_matching_host(
np,
DOMAIN_BUS_FSL_MC_MSI);
if (!of_property_read_bool(np, "msi-controller"))
continue;
if (mc_msi_domain &&
mc_msi_domain->host_data == &its_fsl_mc_msi_domain_info)
irq_domain_remove(mc_msi_domain);
}
}
