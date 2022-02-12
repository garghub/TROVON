static irqreturn_t acpi_ged_irq_handler(int irq, void *data)
{
struct acpi_ged_event *event = data;
acpi_status acpi_ret;
acpi_ret = acpi_execute_simple_method(event->handle, NULL, event->gsi);
if (ACPI_FAILURE(acpi_ret))
dev_err_once(event->dev, "IRQ method execution failed\n");
return IRQ_HANDLED;
}
static acpi_status acpi_ged_request_interrupt(struct acpi_resource *ares,
void *context)
{
struct acpi_ged_event *event;
unsigned int irq;
unsigned int gsi;
unsigned int irqflags = IRQF_ONESHOT;
struct device *dev = context;
acpi_handle handle = ACPI_HANDLE(dev);
acpi_handle evt_handle;
struct resource r;
struct acpi_resource_irq *p = &ares->data.irq;
struct acpi_resource_extended_irq *pext = &ares->data.extended_irq;
if (ares->type == ACPI_RESOURCE_TYPE_END_TAG)
return AE_OK;
if (!acpi_dev_resource_interrupt(ares, 0, &r)) {
dev_err(dev, "unable to parse IRQ resource\n");
return AE_ERROR;
}
if (ares->type == ACPI_RESOURCE_TYPE_IRQ)
gsi = p->interrupts[0];
else
gsi = pext->interrupts[0];
irq = r.start;
if (ACPI_FAILURE(acpi_get_handle(handle, "_EVT", &evt_handle))) {
dev_err(dev, "cannot locate _EVT method\n");
return AE_ERROR;
}
dev_info(dev, "GED listening GSI %u @ IRQ %u\n", gsi, irq);
event = devm_kzalloc(dev, sizeof(*event), GFP_KERNEL);
if (!event)
return AE_ERROR;
event->gsi = gsi;
event->dev = dev;
event->irq = irq;
event->handle = evt_handle;
if (r.flags & IORESOURCE_IRQ_SHAREABLE)
irqflags |= IRQF_SHARED;
if (devm_request_threaded_irq(dev, irq, NULL, acpi_ged_irq_handler,
irqflags, "ACPI:Ged", event)) {
dev_err(dev, "failed to setup event handler for irq %u\n", irq);
return AE_ERROR;
}
return AE_OK;
}
static int ged_probe(struct platform_device *pdev)
{
acpi_status acpi_ret;
acpi_ret = acpi_walk_resources(ACPI_HANDLE(&pdev->dev), "_CRS",
acpi_ged_request_interrupt, &pdev->dev);
if (ACPI_FAILURE(acpi_ret)) {
dev_err(&pdev->dev, "unable to parse the _CRS record\n");
return -EINVAL;
}
return 0;
}
