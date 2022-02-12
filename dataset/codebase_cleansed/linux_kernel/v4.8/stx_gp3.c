static void __init stx_gp3_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
mpc85xx_cpm2_pic_init();
}
static void __init stx_gp3_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("stx_gp3_setup_arch()", 0);
fsl_pci_assign_primary();
#ifdef CONFIG_CPM2
cpm2_reset();
#endif
}
static void stx_gp3_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: RPC Electronics STx\n");
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static int __init stx_gp3_probe(void)
{
return of_machine_is_compatible("stx,gp3-8560");
}
