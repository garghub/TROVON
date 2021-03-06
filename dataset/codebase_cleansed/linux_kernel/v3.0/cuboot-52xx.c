static void platform_fixups(void)
{
void *soc, *reg;
int div;
u32 sysfreq;
dt_fixup_memory(bd.bi_memstart, bd.bi_memsize);
dt_fixup_mac_addresses(bd.bi_enetaddr);
dt_fixup_cpu_clocks(bd.bi_intfreq, bd.bi_busfreq / 4, bd.bi_busfreq);
soc = find_node_by_devtype(NULL, "soc");
if (!soc)
soc = find_node_by_compatible(NULL, "fsl,mpc5200-immr");
if (!soc)
soc = find_node_by_compatible(NULL, "fsl,mpc5200b-immr");
if (soc) {
setprop(soc, "bus-frequency", &bd.bi_ipbfreq,
sizeof(bd.bi_ipbfreq));
if (!dt_xlate_reg(soc, 0, (void*)&reg, NULL))
return;
div = in_8(reg + 0x204) & 0x0020 ? 8 : 4;
sysfreq = bd.bi_busfreq * div;
setprop(soc, "system-frequency", &sysfreq, sizeof(sysfreq));
}
}
void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
fdt_init(_dtb_start);
serial_console_init();
platform_ops.fixups = platform_fixups;
}
