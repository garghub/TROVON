static int cp6_trap(struct pt_regs *regs, unsigned int instr)
{
u32 temp;
asm volatile (
"mrc p15, 0, %0, c15, c1, 0\n\t"
"orr %0, %0, #(1 << 6)\n\t"
"mcr p15, 0, %0, c15, c1, 0\n\t"
: "=r"(temp));
return 0;
}
void __init iop_init_cp6_handler(void)
{
register_undef_hook(&cp6_hook);
}
