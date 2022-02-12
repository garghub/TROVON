static unsigned int acpi_gsi_get_irq_type(int trigger, int polarity)
{
switch (polarity) {
case ACPI_ACTIVE_LOW:
return trigger == ACPI_EDGE_SENSITIVE ?
IRQ_TYPE_EDGE_FALLING :
IRQ_TYPE_LEVEL_LOW;
case ACPI_ACTIVE_HIGH:
return trigger == ACPI_EDGE_SENSITIVE ?
IRQ_TYPE_EDGE_RISING :
IRQ_TYPE_LEVEL_HIGH;
case ACPI_ACTIVE_BOTH:
if (trigger == ACPI_EDGE_SENSITIVE)
return IRQ_TYPE_EDGE_BOTH;
default:
return IRQ_TYPE_NONE;
}
}
int acpi_gsi_to_irq(u32 gsi, unsigned int *irq)
{
*irq = irq_find_mapping(NULL, gsi);
return (*irq > 0) ? *irq : -EINVAL;
}
int acpi_register_gsi(struct device *dev, u32 gsi, int trigger,
int polarity)
{
unsigned int irq;
unsigned int irq_type = acpi_gsi_get_irq_type(trigger, polarity);
irq = irq_create_mapping(NULL, gsi);
if (!irq)
return -EINVAL;
if (irq_type != IRQ_TYPE_NONE &&
irq_type != irq_get_trigger_type(irq))
irq_set_irq_type(irq, irq_type);
return irq;
}
void acpi_unregister_gsi(u32 gsi)
{
int irq = irq_find_mapping(NULL, gsi);
irq_dispose_mapping(irq);
}
