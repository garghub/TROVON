static int of_pmsi_get_dev_id(struct irq_domain *domain, struct device *dev,
u32 *dev_id)
{
int ret, index = 0;
do {
struct of_phandle_args args;
ret = of_parse_phandle_with_args(dev->of_node,
"msi-parent", "#msi-cells",
index, &args);
if (args.np == irq_domain_get_of_node(domain)) {
if (WARN_ON(args.args_count != 1))
return -EINVAL;
*dev_id = args.args[0];
break;
}
} while (!ret);
return ret;
}
int __weak iort_pmsi_get_dev_id(struct device *dev, u32 *dev_id)
{
return -1;
}
static int its_pmsi_prepare(struct irq_domain *domain, struct device *dev,
int nvec, msi_alloc_info_t *info)
{
struct msi_domain_info *msi_info;
u32 dev_id;
int ret;
msi_info = msi_get_domain_info(domain->parent);
if (dev->of_node)
ret = of_pmsi_get_dev_id(domain, dev, &dev_id);
else
ret = iort_pmsi_get_dev_id(dev, &dev_id);
if (ret)
return ret;
info->scratchpad[0].ul = dev_id;
return msi_info->ops->msi_prepare(domain->parent,
dev, nvec, info);
}
static int __init its_pmsi_init_one(struct fwnode_handle *fwnode,
const char *name)
{
struct irq_domain *parent;
parent = irq_find_matching_fwnode(fwnode, DOMAIN_BUS_NEXUS);
if (!parent || !msi_get_domain_info(parent)) {
pr_err("%s: unable to locate ITS domain\n", name);
return -ENXIO;
}
if (!platform_msi_create_irq_domain(fwnode, &its_pmsi_domain_info,
parent)) {
pr_err("%s: unable to create platform domain\n", name);
return -ENXIO;
}
pr_info("Platform MSI: %s domain created\n", name);
return 0;
}
static int __init
its_pmsi_parse_madt(struct acpi_subtable_header *header,
const unsigned long end)
{
struct acpi_madt_generic_translator *its_entry;
struct fwnode_handle *domain_handle;
const char *node_name;
int err = -ENXIO;
its_entry = (struct acpi_madt_generic_translator *)header;
node_name = kasprintf(GFP_KERNEL, "ITS@0x%lx",
(long)its_entry->base_address);
domain_handle = iort_find_domain_token(its_entry->translation_id);
if (!domain_handle) {
pr_err("%s: Unable to locate ITS domain handle\n", node_name);
goto out;
}
err = its_pmsi_init_one(domain_handle, node_name);
out:
kfree(node_name);
return err;
}
static void __init its_pmsi_acpi_init(void)
{
acpi_table_parse_madt(ACPI_MADT_TYPE_GENERIC_TRANSLATOR,
its_pmsi_parse_madt, 0);
}
static inline void its_pmsi_acpi_init(void) { }
static void __init its_pmsi_of_init(void)
{
struct device_node *np;
for (np = of_find_matching_node(NULL, its_device_id); np;
np = of_find_matching_node(np, its_device_id)) {
if (!of_property_read_bool(np, "msi-controller"))
continue;
its_pmsi_init_one(of_node_to_fwnode(np), np->full_name);
}
}
static int __init its_pmsi_init(void)
{
its_pmsi_of_init();
its_pmsi_acpi_init();
return 0;
}
