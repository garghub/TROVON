void _paravirt_nop(void)
{
}
u32 _paravirt_ident_32(u32 x)
{
return x;
}
u64 _paravirt_ident_64(u64 x)
{
return x;
}
void __init default_banner(void)
{
printk(KERN_INFO "Booting paravirtualized kernel on %s\n",
pv_info.name);
}
unsigned paravirt_patch_nop(void)
{
return 0;
}
unsigned paravirt_patch_ignore(unsigned len)
{
return len;
}
unsigned paravirt_patch_call(void *insnbuf,
const void *target, u16 tgt_clobbers,
unsigned long addr, u16 site_clobbers,
unsigned len)
{
struct branch *b = insnbuf;
unsigned long delta = (unsigned long)target - (addr+5);
if (tgt_clobbers & ~site_clobbers)
return len;
if (len < 5)
return len;
b->opcode = 0xe8;
b->delta = delta;
BUILD_BUG_ON(sizeof(*b) != 5);
return 5;
}
unsigned paravirt_patch_jmp(void *insnbuf, const void *target,
unsigned long addr, unsigned len)
{
struct branch *b = insnbuf;
unsigned long delta = (unsigned long)target - (addr+5);
if (len < 5)
return len;
b->opcode = 0xe9;
b->delta = delta;
return 5;
}
static void *get_call_destination(u8 type)
{
struct paravirt_patch_template tmpl = {
.pv_init_ops = pv_init_ops,
.pv_time_ops = pv_time_ops,
.pv_cpu_ops = pv_cpu_ops,
.pv_irq_ops = pv_irq_ops,
.pv_apic_ops = pv_apic_ops,
.pv_mmu_ops = pv_mmu_ops,
#ifdef CONFIG_PARAVIRT_SPINLOCKS
.pv_lock_ops = pv_lock_ops,
#endif
};
return *((void **)&tmpl + type);
}
unsigned paravirt_patch_default(u8 type, u16 clobbers, void *insnbuf,
unsigned long addr, unsigned len)
{
void *opfunc = get_call_destination(type);
unsigned ret;
if (opfunc == NULL)
ret = paravirt_patch_insns(insnbuf, len, ud2a, ud2a+sizeof(ud2a));
else if (opfunc == _paravirt_nop)
ret = paravirt_patch_nop();
else if (opfunc == _paravirt_ident_32)
ret = paravirt_patch_ident_32(insnbuf, len);
else if (opfunc == _paravirt_ident_64)
ret = paravirt_patch_ident_64(insnbuf, len);
else if (type == PARAVIRT_PATCH(pv_cpu_ops.iret) ||
#ifdef CONFIG_X86_32
type == PARAVIRT_PATCH(pv_cpu_ops.irq_enable_sysexit) ||
#endif
type == PARAVIRT_PATCH(pv_cpu_ops.usergs_sysret32) ||
type == PARAVIRT_PATCH(pv_cpu_ops.usergs_sysret64))
ret = paravirt_patch_jmp(insnbuf, opfunc, addr, len);
else
ret = paravirt_patch_call(insnbuf, opfunc, CLBR_ANY,
addr, clobbers, len);
return ret;
}
unsigned paravirt_patch_insns(void *insnbuf, unsigned len,
const char *start, const char *end)
{
unsigned insn_len = end - start;
if (insn_len > len || start == NULL)
insn_len = len;
else
memcpy(insnbuf, start, insn_len);
return insn_len;
}
static void native_flush_tlb(void)
{
__native_flush_tlb();
}
static void native_flush_tlb_global(void)
{
__native_flush_tlb_global();
}
static void native_flush_tlb_single(unsigned long addr)
{
__native_flush_tlb_single(addr);
}
static u64 native_steal_clock(int cpu)
{
return 0;
}
int paravirt_disable_iospace(void)
{
return request_resource(&ioport_resource, &reserve_ioports);
}
static inline void enter_lazy(enum paravirt_lazy_mode mode)
{
BUG_ON(this_cpu_read(paravirt_lazy_mode) != PARAVIRT_LAZY_NONE);
this_cpu_write(paravirt_lazy_mode, mode);
}
static void leave_lazy(enum paravirt_lazy_mode mode)
{
BUG_ON(this_cpu_read(paravirt_lazy_mode) != mode);
this_cpu_write(paravirt_lazy_mode, PARAVIRT_LAZY_NONE);
}
void paravirt_enter_lazy_mmu(void)
{
enter_lazy(PARAVIRT_LAZY_MMU);
}
void paravirt_leave_lazy_mmu(void)
{
leave_lazy(PARAVIRT_LAZY_MMU);
}
void paravirt_flush_lazy_mmu(void)
{
preempt_disable();
if (paravirt_get_lazy_mode() == PARAVIRT_LAZY_MMU) {
arch_leave_lazy_mmu_mode();
arch_enter_lazy_mmu_mode();
}
preempt_enable();
}
void paravirt_start_context_switch(struct task_struct *prev)
{
BUG_ON(preemptible());
if (this_cpu_read(paravirt_lazy_mode) == PARAVIRT_LAZY_MMU) {
arch_leave_lazy_mmu_mode();
set_ti_thread_flag(task_thread_info(prev), TIF_LAZY_MMU_UPDATES);
}
enter_lazy(PARAVIRT_LAZY_CPU);
}
void paravirt_end_context_switch(struct task_struct *next)
{
BUG_ON(preemptible());
leave_lazy(PARAVIRT_LAZY_CPU);
if (test_and_clear_ti_thread_flag(task_thread_info(next), TIF_LAZY_MMU_UPDATES))
arch_enter_lazy_mmu_mode();
}
enum paravirt_lazy_mode paravirt_get_lazy_mode(void)
{
if (in_interrupt())
return PARAVIRT_LAZY_NONE;
return this_cpu_read(paravirt_lazy_mode);
}
