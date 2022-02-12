static void __init
sbc8641_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("sbc8641_setup_arch()", 0);
printk("SBC8641 board from Wind River\n");
#ifdef CONFIG_SMP
mpc86xx_smp_init();
#endif
fsl_pci_assign_primary();
}
static void
sbc8641_show_cpuinfo(struct seq_file *m)
{
uint svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Wind River Systems\n");
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
}
static int __init sbc8641_probe(void)
{
if (of_machine_is_compatible("wind,sbc8641"))
return 1;
return 0;
}
