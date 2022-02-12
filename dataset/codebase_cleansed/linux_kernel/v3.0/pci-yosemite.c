static int __init pmc_yosemite_setup(void)
{
unsigned long io_v_base;
io_v_base = (unsigned long) ioremap(TITAN_IO_BASE, TITAN_IO_SIZE);
if (!io_v_base)
panic(ioremap_failed);
set_io_port_base(io_v_base);
py_controller.io_map_base = io_v_base;
TITAN_WRITE(RM9000x2_OCD_LKM7, TITAN_READ(RM9000x2_OCD_LKM7) | 1);
ioport_resource.end = TITAN_IO_SIZE - 1;
register_pci_controller(&py_controller);
return 0;
}
