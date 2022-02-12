static void __init ppa8548_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static void __init ppa8548_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("ppa8548_setup_arch()", 0);
}
static void ppa8548_show_cpuinfo(struct seq_file *m)
{
uint32_t svid, phid1;
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Prodrive B.V.\n");
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
static int __init ppa8548_probe(void)
{
return of_machine_is_compatible("ppa8548");
}
