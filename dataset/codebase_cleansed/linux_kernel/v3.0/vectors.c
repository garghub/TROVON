asmlinkage void dbginterrupt_c(struct frame *fp)
{
extern void dump(struct pt_regs *fp);
printk(KERN_DEBUG "%s(%d): BUS ERROR TRAP\n", __FILE__, __LINE__);
dump((struct pt_regs *) fp);
asm("halt");
}
void set_evector(int vecnum, void (*handler)(void))
{
if (vecnum >= 0 && vecnum <= 255)
_ramvec[vecnum] = handler;
}
void __init init_vectors(void)
{
int i;
for (i = 3; (i <= 23); i++)
_ramvec[i] = trap;
for (i = 33; (i <= 63); i++)
_ramvec[i] = trap;
for (i = 24; (i <= 31); i++)
_ramvec[i] = inthandler;
for (i = 64; (i < 255); i++)
_ramvec[i] = inthandler;
_ramvec[255] = 0;
_ramvec[2] = buserr;
_ramvec[32] = system_call;
#ifdef TRAP_DBG_INTERRUPT
_ramvec[12] = dbginterrupt;
#endif
}
