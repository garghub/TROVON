int pmc_leon_need_fixup(void)
{
unsigned int systemid = amba_system_id >> 16;
unsigned int *id;
id = &pmc_leon_fixup_ids[0];
while (*id != 0) {
if (*id == systemid)
return 1;
id++;
}
return 0;
}
void pmc_leon_idle_fixup(void)
{
register unsigned int address = (unsigned int)leon3_irqctrl_regs;
__asm__ __volatile__ (
"mov %%g0, %%asr19\n"
"lda [%0] %1, %%g0\n"
:
: "r"(address), "i"(ASI_LEON_BYPASS));
}
void pmc_leon_idle(void)
{
__asm__ __volatile__ ("mov %g0, %asr19\n\t");
}
static int __init leon_pmc_install(void)
{
if (pmc_leon_need_fixup())
pm_idle = pmc_leon_idle_fixup;
else
pm_idle = pmc_leon_idle;
printk(KERN_INFO "leon: power management initialized\n");
return 0;
}
