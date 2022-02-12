static void __init tqm85xx_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0,
MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
mpc85xx_cpm2_pic_init();
}
static void __init tqm85xx_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("tqm85xx_setup_arch()", 0);
#ifdef CONFIG_CPM2
cpm2_reset();
#endif
fsl_pci_assign_primary();
}
static void tqm85xx_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: TQ Components\n");
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static void __devinit tqm85xx_ti1520_fixup(struct pci_dev *pdev)
{
unsigned int val;
if (!machine_is(tqm85xx))
return;
dev_info(&pdev->dev, "Using TI 1520 fixup on TQM85xx\n");
pci_read_config_dword(pdev, 0x80, &val);
pci_write_config_dword(pdev, 0x80, val | (1 << 27));
}
static int __init tqm85xx_probe(void)
{
return of_flat_dt_match(of_get_flat_dt_root(), board);
}
