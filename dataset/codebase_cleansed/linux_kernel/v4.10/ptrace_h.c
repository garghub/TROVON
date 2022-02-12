void user_disable_single_step(struct task_struct *child)
{
if ((long)child->thread.breakinfo.addr != -1L) {
*(child->thread.breakinfo.addr) = child->thread.breakinfo.inst;
child->thread.breakinfo.addr = (unsigned short *)-1L;
}
}
static int isbranch(struct task_struct *task, int reson)
{
unsigned char cond = h8300_get_reg(task, PT_CCR);
__asm__("bld #3,%w0\n\t"
"bxor #1,%w0\n\t"
"bst #4,%w0\n\t"
"bor #2,%w0\n\t"
"bst #5,%w0\n\t"
"bld #2,%w0\n\t"
"bor #0,%w0\n\t"
"bst #6,%w0\n\t"
: "=&r"(cond) : "0"(cond) : "cc");
cond &= condmask[reson >> 1];
if (!(reson & 1))
return cond == 0;
else
return cond != 0;
}
static unsigned short *decode(struct task_struct *child,
const struct optable *op,
char *fetch_p, unsigned short *pc,
unsigned char inst)
{
unsigned long addr;
unsigned long *sp;
int regno;
switch (op->type) {
case none:
return (unsigned short *)pc + op->length;
case jabs:
addr = *(unsigned long *)pc;
return (unsigned short *)(addr & 0x00ffffff);
case ind:
addr = *pc & 0xff;
return (unsigned short *)(*(unsigned long *)addr);
case ret:
sp = (unsigned long *)h8300_get_reg(child, PT_USP);
return (unsigned short *)(*(sp+2) & 0x00ffffff);
case reg:
regno = (*pc >> 4) & 0x07;
if (regno == 0)
addr = h8300_get_reg(child, PT_ER0);
else
addr = h8300_get_reg(child, regno-1 + PT_ER1);
return (unsigned short *)addr;
case relb:
if (inst == 0x55 || isbranch(child, inst & 0x0f))
pc = (unsigned short *)((unsigned long)pc +
((signed char)(*fetch_p)));
return pc+1;
case relw:
if (inst == 0x5c || isbranch(child, (*fetch_p & 0xf0) >> 4))
pc = (unsigned short *)((unsigned long)pc +
((signed short)(*(pc+1))));
return pc+2;
default:
return NULL;
}
}
static unsigned short *nextpc(struct task_struct *child, unsigned short *pc)
{
const struct optable *op;
unsigned char *fetch_p;
int op_len;
unsigned char inst;
op = optables[0].ptr;
op_len = optables[0].size;
fetch_p = (unsigned char *)pc;
inst = *fetch_p++;
do {
if ((inst & op->bitmask) == op->bitpattern) {
if (op->length < 0) {
op = optables[-op->length].ptr;
op_len = optables[-op->length].size + 1;
inst = *fetch_p++;
} else
return decode(child, op, fetch_p, pc, inst);
} else
op++;
} while (--op_len > 0);
return NULL;
}
void user_enable_single_step(struct task_struct *child)
{
unsigned short *next;
next = nextpc(child, (unsigned short *)h8300_get_reg(child, PT_PC));
child->thread.breakinfo.addr = next;
child->thread.breakinfo.inst = *next;
*next = BREAKINST;
}
asmlinkage void trace_trap(unsigned long bp)
{
if ((unsigned long)current->thread.breakinfo.addr == bp) {
user_disable_single_step(current);
force_sig(SIGTRAP, current);
} else
force_sig(SIGILL, current);
}
