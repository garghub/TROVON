void __init
register_isa_ports(unsigned int membase, unsigned int portbase, unsigned int portshift)
{
isa_membase = membase;
isa_portbase = portbase;
isa_portshift = portshift;
isa_sysctl_header = register_sysctl_table(ctl_bus);
}
