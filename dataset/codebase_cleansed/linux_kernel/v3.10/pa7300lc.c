static u32 cpu_hpa(void)
{
return 0xfffb0000;
}
static void pa7300lc_lpmc(int code, struct pt_regs *regs)
{
u32 hpa;
printk(KERN_WARNING "LPMC on CPU %d\n", smp_processor_id());
show_regs(regs);
hpa = cpu_hpa();
printk(KERN_WARNING
"MIOC_CONTROL %08x\n" "MIOC_STATUS %08x\n"
"MDERRADD %08x\n" "DMAERR %08x\n"
"DIOERR %08x\n" "HIDMAMEM %08x\n",
gsc_readl(hpa+MIOC_CONTROL), gsc_readl(hpa+MIOC_STATUS),
gsc_readl(hpa+MDERRADD), gsc_readl(hpa+DMAERR),
gsc_readl(hpa+DIOERR), gsc_readl(hpa+HIDMAMEM));
}
void pa7300lc_init(void)
{
cpu_lpmc = pa7300lc_lpmc;
}
