static void __init sbc8548_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
static int __init sbc8548_hw_rev(void)
{
struct device_node *np;
struct resource res;
unsigned int *rev;
int board_rev = 0;
np = of_find_compatible_node(NULL, NULL, "hw-rev");
if (np == NULL) {
printk("No HW-REV found in DTB.\n");
return -ENODEV;
}
of_address_to_resource(np, 0, &res);
of_node_put(np);
rev = ioremap(res.start,sizeof(unsigned int));
board_rev = (*rev) >> 28;
iounmap(rev);
return board_rev;
}
static void __init sbc8548_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("sbc8548_setup_arch()", 0);
fsl_pci_assign_primary();
sbc_rev = sbc8548_hw_rev();
}
static void sbc8548_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Wind River\n");
seq_printf(m, "Machine\t\t: SBC8548 v%d\n", sbc_rev);
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static int __init sbc8548_probe(void)
{
return of_machine_is_compatible("SBC8548");
}
