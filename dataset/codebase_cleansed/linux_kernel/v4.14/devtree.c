unsigned int __init arc_early_base_baud(void)
{
return arc_base_baud/16;
}
static void __init arc_set_early_base_baud(unsigned long dt_root)
{
if (of_flat_dt_is_compatible(dt_root, "abilis,arc-tb10x"))
arc_base_baud = 166666666;
else if (of_flat_dt_is_compatible(dt_root, "snps,arc-sdp") ||
of_flat_dt_is_compatible(dt_root, "snps,hsdk"))
arc_base_baud = 33333333;
else if (of_flat_dt_is_compatible(dt_root, "ezchip,arc-nps"))
arc_base_baud = 800000000;
else
arc_base_baud = 50000000;
}
static const void * __init arch_get_next_mach(const char *const **match)
{
static const struct machine_desc *mdesc = __arch_info_begin;
const struct machine_desc *m = mdesc;
if (m >= __arch_info_end)
return NULL;
mdesc++;
*match = m->dt_compat;
return m;
}
const struct machine_desc * __init setup_machine_fdt(void *dt)
{
const struct machine_desc *mdesc;
unsigned long dt_root;
if (!early_init_dt_scan(dt))
return NULL;
mdesc = of_flat_dt_match_machine(NULL, arch_get_next_mach);
if (!mdesc)
machine_halt();
dt_root = of_get_flat_dt_root();
arc_set_early_base_baud(dt_root);
return mdesc;
}
