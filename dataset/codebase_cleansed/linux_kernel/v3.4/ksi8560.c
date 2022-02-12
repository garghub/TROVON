static void machine_restart(char *cmd)
{
if (cpld_base)
out_8(cpld_base + KSI8560_CPLD_RCR1, KSI8560_CPLD_RCR1_CPUHR);
else
printk(KERN_ERR "Can't find CPLD base, hang forever\n");
for (;;);
}
static void __init ksi8560_pic_init(void)
{
struct mpic *mpic = mpic_alloc(NULL, 0, MPIC_BIG_ENDIAN,
0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
mpc85xx_cpm2_pic_init();
}
static void __init init_ioports(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(ksi8560_pins); i++) {
struct cpm_pin *pin = &ksi8560_pins[i];
cpm2_set_pin(pin->port, pin->pin, pin->flags);
}
cpm2_clk_setup(CPM_CLK_SCC1, CPM_BRG1, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC1, CPM_BRG1, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_SCC2, CPM_BRG2, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_SCC2, CPM_BRG2, CPM_CLK_TX);
cpm2_clk_setup(CPM_CLK_FCC1, CPM_CLK9, CPM_CLK_RX);
cpm2_clk_setup(CPM_CLK_FCC1, CPM_CLK10, CPM_CLK_TX);
}
static void __init ksi8560_setup_arch(void)
{
struct device_node *cpld;
cpld = of_find_compatible_node(NULL, NULL, "emerson,KSI8560-cpld");
if (cpld)
cpld_base = of_iomap(cpld, 0);
else
printk(KERN_ERR "Can't find CPLD in device tree\n");
if (ppc_md.progress)
ppc_md.progress("ksi8560_setup_arch()", 0);
#ifdef CONFIG_CPM2
cpm2_reset();
init_ioports();
#endif
}
static void ksi8560_show_cpuinfo(struct seq_file *m)
{
uint pvid, svid, phid1;
pvid = mfspr(SPRN_PVR);
svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Emerson Network Power\n");
seq_printf(m, "Board\t\t: KSI8560\n");
if (cpld_base) {
seq_printf(m, "Hardware rev\t: %d\n",
in_8(cpld_base + KSI8560_CPLD_HVR));
seq_printf(m, "CPLD rev\t: %d\n",
in_8(cpld_base + KSI8560_CPLD_PVR));
} else
seq_printf(m, "Unknown Hardware and CPLD revs\n");
seq_printf(m, "PVR\t\t: 0x%x\n", pvid);
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
phid1 = mfspr(SPRN_HID1);
seq_printf(m, "PLL setting\t: 0x%x\n", ((phid1 >> 24) & 0x3f));
}
static int __init ksi8560_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "emerson,KSI8560");
}
