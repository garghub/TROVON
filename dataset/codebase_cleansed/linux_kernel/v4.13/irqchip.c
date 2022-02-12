void __init irqchip_init(void)
{
of_irq_init(__irqchip_of_table);
acpi_probe_device_table(irqchip);
}
