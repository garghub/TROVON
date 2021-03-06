static void platform_fixups(void)
{
void *devp;
dt_fixup_memory(bd.bi_memstart, bd.bi_memsize);
dt_fixup_mac_address_by_alias("ethernet0", bd.bi_enetaddr);
dt_fixup_mac_address_by_alias("ethernet1", bd.bi_enet1addr);
dt_fixup_mac_address_by_alias("ethernet2", bd.bi_enet2addr);
dt_fixup_cpu_clocks(bd.bi_intfreq, bd.bi_busfreq / 8, bd.bi_busfreq);
devp = find_node_by_devtype(NULL, "soc");
if (devp) {
void *serial = NULL;
setprop(devp, "bus-frequency", &bd.bi_busfreq,
sizeof(bd.bi_busfreq));
while ((serial = find_node_by_devtype(serial, "serial"))) {
if (get_parent(serial) != devp)
continue;
setprop(serial, "clock-frequency", &bd.bi_busfreq,
sizeof(bd.bi_busfreq));
}
}
devp = find_node_by_compatible(NULL, "fsl,cpm2-brg");
if (devp)
setprop(devp, "clock-frequency", &bd.bi_brgfreq,
sizeof(bd.bi_brgfreq));
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
fdt_init(_dtb_start);
serial_console_init();
platform_ops.fixups = platform_fixups;
}
