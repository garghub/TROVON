static int ip32_be_handler(struct pt_regs *regs, int is_fixup)
{
int data = regs->cp0_cause & 4;
if (is_fixup)
return MIPS_BE_FIXUP;
printk("Got %cbe at 0x%lx\n", data ? 'd' : 'i', regs->cp0_epc);
show_regs(regs);
dump_tlb_all();
while(1);
force_sig(SIGBUS, current);
}
void __init ip32_be_init(void)
{
board_be_handler = ip32_be_handler;
}
