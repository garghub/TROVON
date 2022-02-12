void __init mach_prom_init_machtype(void)
{
if (strstr(arcs_cmdline, "PMON_VER=LM")) {
if (strstr(arcs_cmdline, "PMON_VER=LM8"))
mips_machtype = MACH_LEMOTE_YL2F89;
else if (strstr(arcs_cmdline, "PMON_VER=LM6"))
mips_machtype = MACH_LEMOTE_FL2F;
else if (strstr(arcs_cmdline, "PMON_VER=LM9"))
mips_machtype = MACH_LEMOTE_LL2F;
else
mips_machtype = MACH_LEMOTE_NAS;
strcat(arcs_cmdline, " machtype=");
strcat(arcs_cmdline, get_system_type());
strcat(arcs_cmdline, " ");
}
}
