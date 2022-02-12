int acpi_gsi_to_irq(u32 gsi, unsigned int *irq)
{
struct irq_domain *d = irq_find_matching_fwnode(acpi_gsi_domain_id,
DOMAIN_BUS_ANY);
*irq = irq_find_mapping(d, gsi);
return (*irq > 0) ? *irq : -EINVAL;
}
int acpi_register_gsi(struct device *dev, u32 gsi, int trigger,
int polarity)
{
struct irq_fwspec fwspec;
if (WARN_ON(!acpi_gsi_domain_id)) {
pr_warn("GSI: No registered irqchip, giving up\n");
return -EINVAL;
}
fwspec.fwnode = acpi_gsi_domain_id;
fwspec.param[0] = gsi;
fwspec.param[1] = acpi_dev_get_irq_type(trigger, polarity);
fwspec.param_count = 2;
return irq_create_fwspec_mapping(&fwspec);
}
void acpi_unregister_gsi(u32 gsi)
{
struct irq_domain *d = irq_find_matching_fwnode(acpi_gsi_domain_id,
DOMAIN_BUS_ANY);
int irq = irq_find_mapping(d, gsi);
irq_dispose_mapping(irq);
}
void __init acpi_set_irq_model(enum acpi_irq_model_id model,
struct fwnode_handle *fwnode)
{
acpi_irq_model = model;
acpi_gsi_domain_id = fwnode;
}
