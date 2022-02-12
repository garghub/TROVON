static int alloc_emuframe(void)
{
mm_context_t *mm_ctx = &current->mm->context;
int idx;
retry:
spin_lock(&mm_ctx->bd_emupage_lock);
if (!mm_ctx->bd_emupage_allocmap) {
mm_ctx->bd_emupage_allocmap =
kcalloc(BITS_TO_LONGS(emupage_frame_count),
sizeof(unsigned long),
GFP_ATOMIC);
if (!mm_ctx->bd_emupage_allocmap) {
idx = BD_EMUFRAME_NONE;
goto out_unlock;
}
}
idx = bitmap_find_free_region(mm_ctx->bd_emupage_allocmap,
emupage_frame_count, 0);
if (idx < 0) {
spin_unlock(&mm_ctx->bd_emupage_lock);
if (!wait_event_killable(mm_ctx->bd_emupage_queue,
!bitmap_full(mm_ctx->bd_emupage_allocmap,
emupage_frame_count)))
goto retry;
return BD_EMUFRAME_NONE;
}
pr_debug("allocate emuframe %d to %d\n", idx, current->pid);
out_unlock:
spin_unlock(&mm_ctx->bd_emupage_lock);
return idx;
}
static void free_emuframe(int idx, struct mm_struct *mm)
{
mm_context_t *mm_ctx = &mm->context;
spin_lock(&mm_ctx->bd_emupage_lock);
pr_debug("free emuframe %d from %d\n", idx, current->pid);
bitmap_clear(mm_ctx->bd_emupage_allocmap, idx, 1);
wake_up(&mm_ctx->bd_emupage_queue);
spin_unlock(&mm_ctx->bd_emupage_lock);
}
static bool within_emuframe(struct pt_regs *regs)
{
unsigned long base = (unsigned long)dsemul_page();
if (regs->cp0_epc < base)
return false;
if (regs->cp0_epc >= (base + PAGE_SIZE))
return false;
return true;
}
bool dsemul_thread_cleanup(struct task_struct *tsk)
{
int fr_idx;
fr_idx = atomic_xchg(&tsk->thread.bd_emu_frame, BD_EMUFRAME_NONE);
if (fr_idx == BD_EMUFRAME_NONE)
return false;
task_lock(tsk);
if (tsk->mm)
free_emuframe(fr_idx, tsk->mm);
task_unlock(tsk);
return true;
}
bool dsemul_thread_rollback(struct pt_regs *regs)
{
struct emuframe __user *fr;
int fr_idx;
if (!within_emuframe(regs))
return false;
fr_idx = atomic_read(&current->thread.bd_emu_frame);
if (fr_idx == BD_EMUFRAME_NONE)
return false;
fr = &dsemul_page()[fr_idx];
if (msk_isa16_mode(regs->cp0_epc) == (unsigned long)&fr->emul)
regs->cp0_epc = current->thread.bd_emu_branch_pc;
else if (msk_isa16_mode(regs->cp0_epc) == (unsigned long)&fr->badinst)
regs->cp0_epc = current->thread.bd_emu_cont_pc;
atomic_set(&current->thread.bd_emu_frame, BD_EMUFRAME_NONE);
free_emuframe(fr_idx, current->mm);
return true;
}
void dsemul_mm_cleanup(struct mm_struct *mm)
{
mm_context_t *mm_ctx = &mm->context;
kfree(mm_ctx->bd_emupage_allocmap);
}
int mips_dsemul(struct pt_regs *regs, mips_instruction ir,
unsigned long branch_pc, unsigned long cont_pc)
{
int isa16 = get_isa16_mode(regs->cp0_epc);
mips_instruction break_math;
struct emuframe __user *fr;
int err, fr_idx;
if (ir == 0)
return -1;
if (isa16) {
union mips_instruction insn = { .word = ir };
if ((ir >> 16) == MM_NOP16)
return -1;
if (insn.mm_a_format.opcode == mm_addiupc_op) {
unsigned int rs;
s32 v;
rs = (((insn.mm_a_format.rs + 0xe) & 0xf) + 2);
v = regs->cp0_epc & ~3;
v += insn.mm_a_format.simmediate << 2;
regs->regs[rs] = (long)v;
return -1;
}
}
pr_debug("dsemul 0x%08lx cont at 0x%08lx\n", regs->cp0_epc, cont_pc);
fr_idx = atomic_read(&current->thread.bd_emu_frame);
if (fr_idx == BD_EMUFRAME_NONE)
fr_idx = alloc_emuframe();
if (fr_idx == BD_EMUFRAME_NONE)
return SIGBUS;
fr = &dsemul_page()[fr_idx];
break_math = BREAK_MATH(isa16);
if (isa16) {
err = __put_user(ir >> 16,
(u16 __user *)(&fr->emul));
err |= __put_user(ir & 0xffff,
(u16 __user *)((long)(&fr->emul) + 2));
err |= __put_user(break_math >> 16,
(u16 __user *)(&fr->badinst));
err |= __put_user(break_math & 0xffff,
(u16 __user *)((long)(&fr->badinst) + 2));
} else {
err = __put_user(ir, &fr->emul);
err |= __put_user(break_math, &fr->badinst);
}
if (unlikely(err)) {
MIPS_FPU_EMU_INC_STATS(errors);
free_emuframe(fr_idx, current->mm);
return SIGBUS;
}
current->thread.bd_emu_branch_pc = branch_pc;
current->thread.bd_emu_cont_pc = cont_pc;
atomic_set(&current->thread.bd_emu_frame, fr_idx);
regs->cp0_epc = (unsigned long)&fr->emul | isa16;
flush_cache_sigtramp((unsigned long)&fr->emul);
return 0;
}
bool do_dsemulret(struct pt_regs *xcp)
{
if (!dsemul_thread_cleanup(current)) {
MIPS_FPU_EMU_INC_STATS(errors);
return false;
}
xcp->cp0_epc = current->thread.bd_emu_cont_pc;
pr_debug("dsemulret to 0x%08lx\n", xcp->cp0_epc);
MIPS_FPU_EMU_INC_STATS(ds_emul);
return true;
}
