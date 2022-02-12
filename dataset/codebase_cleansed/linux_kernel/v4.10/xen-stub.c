int xen_stub_memory_device_init(void)
{
if (!xen_initial_domain())
return -ENODEV;
return acpi_bus_register_driver(&xen_stub_memory_device_driver);
}
void xen_stub_memory_device_exit(void)
{
acpi_bus_unregister_driver(&xen_stub_memory_device_driver);
}
int xen_stub_processor_init(void)
{
if (!xen_initial_domain())
return -ENODEV;
return acpi_bus_register_driver(&xen_stub_processor_driver);
}
void xen_stub_processor_exit(void)
{
acpi_bus_unregister_driver(&xen_stub_processor_driver);
}
