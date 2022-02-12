static const char *mpx_mapping_name(struct vm_area_struct *vma)
{
return "[mpx]";
}
static int is_mpx_vma(struct vm_area_struct *vma)
{
return (vma->vm_ops == &mpx_vma_ops);
}
static unsigned long mpx_mmap(unsigned long len)
{
unsigned long ret;
unsigned long addr, pgoff;
struct mm_struct *mm = current->mm;
vm_flags_t vm_flags;
struct vm_area_struct *vma;
if (len != MPX_BD_SIZE_BYTES && len != MPX_BT_SIZE_BYTES)
return -EINVAL;
down_write(&mm->mmap_sem);
if (mm->map_count > sysctl_max_map_count) {
ret = -ENOMEM;
goto out;
}
addr = get_unmapped_area(NULL, 0, len, 0, MAP_ANONYMOUS | MAP_PRIVATE);
if (addr & ~PAGE_MASK) {
ret = addr;
goto out;
}
vm_flags = VM_READ | VM_WRITE | VM_MPX |
mm->def_flags | VM_MAYREAD | VM_MAYWRITE | VM_MAYEXEC;
pgoff = addr >> PAGE_SHIFT;
ret = mmap_region(NULL, addr, len, vm_flags, pgoff);
if (IS_ERR_VALUE(ret))
goto out;
vma = find_vma(mm, ret);
if (!vma) {
ret = -ENOMEM;
goto out;
}
vma->vm_ops = &mpx_vma_ops;
if (vm_flags & VM_LOCKED) {
up_write(&mm->mmap_sem);
mm_populate(ret, len);
return ret;
}
out:
up_write(&mm->mmap_sem);
return ret;
}
static int get_reg_offset(struct insn *insn, struct pt_regs *regs,
enum reg_type type)
{
int regno = 0;
static const int regoff[] = {
offsetof(struct pt_regs, ax),
offsetof(struct pt_regs, cx),
offsetof(struct pt_regs, dx),
offsetof(struct pt_regs, bx),
offsetof(struct pt_regs, sp),
offsetof(struct pt_regs, bp),
offsetof(struct pt_regs, si),
offsetof(struct pt_regs, di),
#ifdef CONFIG_X86_64
offsetof(struct pt_regs, r8),
offsetof(struct pt_regs, r9),
offsetof(struct pt_regs, r10),
offsetof(struct pt_regs, r11),
offsetof(struct pt_regs, r12),
offsetof(struct pt_regs, r13),
offsetof(struct pt_regs, r14),
offsetof(struct pt_regs, r15),
#endif
};
int nr_registers = ARRAY_SIZE(regoff);
if (IS_ENABLED(CONFIG_X86_64) && !insn->x86_64)
nr_registers -= 8;
switch (type) {
case REG_TYPE_RM:
regno = X86_MODRM_RM(insn->modrm.value);
if (X86_REX_B(insn->rex_prefix.value) == 1)
regno += 8;
break;
case REG_TYPE_INDEX:
regno = X86_SIB_INDEX(insn->sib.value);
if (X86_REX_X(insn->rex_prefix.value) == 1)
regno += 8;
break;
case REG_TYPE_BASE:
regno = X86_SIB_BASE(insn->sib.value);
if (X86_REX_B(insn->rex_prefix.value) == 1)
regno += 8;
break;
default:
pr_err("invalid register type");
BUG();
break;
}
if (regno > nr_registers) {
WARN_ONCE(1, "decoded an instruction with an invalid register");
return -EINVAL;
}
return regoff[regno];
}
static void __user *mpx_get_addr_ref(struct insn *insn, struct pt_regs *regs)
{
unsigned long addr, base, indx;
int addr_offset, base_offset, indx_offset;
insn_byte_t sib;
insn_get_modrm(insn);
insn_get_sib(insn);
sib = insn->sib.value;
if (X86_MODRM_MOD(insn->modrm.value) == 3) {
addr_offset = get_reg_offset(insn, regs, REG_TYPE_RM);
if (addr_offset < 0)
goto out_err;
addr = regs_get_register(regs, addr_offset);
} else {
if (insn->sib.nbytes) {
base_offset = get_reg_offset(insn, regs, REG_TYPE_BASE);
if (base_offset < 0)
goto out_err;
indx_offset = get_reg_offset(insn, regs, REG_TYPE_INDEX);
if (indx_offset < 0)
goto out_err;
base = regs_get_register(regs, base_offset);
indx = regs_get_register(regs, indx_offset);
addr = base + indx * (1 << X86_SIB_SCALE(sib));
} else {
addr_offset = get_reg_offset(insn, regs, REG_TYPE_RM);
if (addr_offset < 0)
goto out_err;
addr = regs_get_register(regs, addr_offset);
}
addr += insn->displacement.value;
}
return (void __user *)addr;
out_err:
return (void __user *)-1;
}
static int mpx_insn_decode(struct insn *insn,
struct pt_regs *regs)
{
unsigned char buf[MAX_INSN_SIZE];
int x86_64 = !test_thread_flag(TIF_IA32);
int not_copied;
int nr_copied;
not_copied = copy_from_user(buf, (void __user *)regs->ip, sizeof(buf));
nr_copied = sizeof(buf) - not_copied;
if (!nr_copied)
return -EFAULT;
insn_init(insn, buf, nr_copied, x86_64);
insn_get_length(insn);
if (nr_copied < insn->length)
return -EFAULT;
insn_get_opcode(insn);
if (insn->opcode.bytes[0] != 0x0f)
goto bad_opcode;
if ((insn->opcode.bytes[1] != 0x1a) &&
(insn->opcode.bytes[1] != 0x1b))
goto bad_opcode;
return 0;
bad_opcode:
return -EINVAL;
}
siginfo_t *mpx_generate_siginfo(struct pt_regs *regs,
struct xsave_struct *xsave_buf)
{
struct bndreg *bndregs, *bndreg;
siginfo_t *info = NULL;
struct insn insn;
uint8_t bndregno;
int err;
err = mpx_insn_decode(&insn, regs);
if (err)
goto err_out;
insn_get_modrm(&insn);
bndregno = X86_MODRM_REG(insn.modrm.value);
if (bndregno > 3) {
err = -EINVAL;
goto err_out;
}
bndregs = get_xsave_addr(xsave_buf, XSTATE_BNDREGS);
if (!bndregs) {
err = -EINVAL;
goto err_out;
}
bndreg = &bndregs[bndregno];
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
err = -ENOMEM;
goto err_out;
}
info->si_lower = (void __user *)(unsigned long)bndreg->lower_bound;
info->si_upper = (void __user *)(unsigned long)~bndreg->upper_bound;
info->si_addr_lsb = 0;
info->si_signo = SIGSEGV;
info->si_errno = 0;
info->si_code = SEGV_BNDERR;
info->si_addr = mpx_get_addr_ref(&insn, regs);
if (info->si_addr == (void *)-1) {
err = -EINVAL;
goto err_out;
}
return info;
err_out:
kfree(info);
return ERR_PTR(err);
}
static __user void *task_get_bounds_dir(struct task_struct *tsk)
{
struct bndcsr *bndcsr;
if (!cpu_feature_enabled(X86_FEATURE_MPX))
return MPX_INVALID_BOUNDS_DIR;
if (IS_ENABLED(CONFIG_X86_64) && test_thread_flag(TIF_IA32))
return MPX_INVALID_BOUNDS_DIR;
fpu_save_init(&tsk->thread.fpu);
bndcsr = get_xsave_addr(&tsk->thread.fpu.state->xsave, XSTATE_BNDCSR);
if (!bndcsr)
return MPX_INVALID_BOUNDS_DIR;
if (!(bndcsr->bndcfgu & MPX_BNDCFG_ENABLE_FLAG))
return MPX_INVALID_BOUNDS_DIR;
return (void __user *)(unsigned long)
(bndcsr->bndcfgu & MPX_BNDCFG_ADDR_MASK);
}
int mpx_enable_management(struct task_struct *tsk)
{
void __user *bd_base = MPX_INVALID_BOUNDS_DIR;
struct mm_struct *mm = tsk->mm;
int ret = 0;
bd_base = task_get_bounds_dir(tsk);
down_write(&mm->mmap_sem);
mm->bd_addr = bd_base;
if (mm->bd_addr == MPX_INVALID_BOUNDS_DIR)
ret = -ENXIO;
up_write(&mm->mmap_sem);
return ret;
}
int mpx_disable_management(struct task_struct *tsk)
{
struct mm_struct *mm = current->mm;
if (!cpu_feature_enabled(X86_FEATURE_MPX))
return -ENXIO;
down_write(&mm->mmap_sem);
mm->bd_addr = MPX_INVALID_BOUNDS_DIR;
up_write(&mm->mmap_sem);
return 0;
}
static int allocate_bt(long __user *bd_entry)
{
unsigned long expected_old_val = 0;
unsigned long actual_old_val = 0;
unsigned long bt_addr;
int ret = 0;
bt_addr = mpx_mmap(MPX_BT_SIZE_BYTES);
if (IS_ERR((void *)bt_addr))
return PTR_ERR((void *)bt_addr);
bt_addr = bt_addr | MPX_BD_ENTRY_VALID_FLAG;
ret = user_atomic_cmpxchg_inatomic(&actual_old_val, bd_entry,
expected_old_val, bt_addr);
if (ret)
goto out_unmap;
if (actual_old_val & MPX_BD_ENTRY_VALID_FLAG) {
ret = 0;
goto out_unmap;
}
if (expected_old_val != actual_old_val) {
ret = -EINVAL;
goto out_unmap;
}
return 0;
out_unmap:
vm_munmap(bt_addr & MPX_BT_ADDR_MASK, MPX_BT_SIZE_BYTES);
return ret;
}
static int do_mpx_bt_fault(struct xsave_struct *xsave_buf)
{
unsigned long bd_entry, bd_base;
struct bndcsr *bndcsr;
bndcsr = get_xsave_addr(xsave_buf, XSTATE_BNDCSR);
if (!bndcsr)
return -EINVAL;
bd_base = bndcsr->bndcfgu & MPX_BNDCFG_ADDR_MASK;
bd_entry = bndcsr->bndstatus & MPX_BNDSTA_ADDR_MASK;
if ((bd_entry < bd_base) ||
(bd_entry >= bd_base + MPX_BD_SIZE_BYTES))
return -EINVAL;
return allocate_bt((long __user *)bd_entry);
}
int mpx_handle_bd_fault(struct xsave_struct *xsave_buf)
{
if (!kernel_managing_mpx_tables(current->mm))
return -EINVAL;
if (do_mpx_bt_fault(xsave_buf)) {
force_sig(SIGSEGV, current);
}
return 0;
}
static int mpx_resolve_fault(long __user *addr, int write)
{
long gup_ret;
int nr_pages = 1;
int force = 0;
gup_ret = get_user_pages(current, current->mm, (unsigned long)addr,
nr_pages, write, force, NULL, NULL);
if (!gup_ret)
return -EFAULT;
if (gup_ret < 0)
return gup_ret;
return 0;
}
static int get_bt_addr(struct mm_struct *mm,
long __user *bd_entry, unsigned long *bt_addr)
{
int ret;
int valid_bit;
if (!access_ok(VERIFY_READ, (bd_entry), sizeof(*bd_entry)))
return -EFAULT;
while (1) {
int need_write = 0;
pagefault_disable();
ret = get_user(*bt_addr, bd_entry);
pagefault_enable();
if (!ret)
break;
if (ret == -EFAULT)
ret = mpx_resolve_fault(bd_entry, need_write);
if (ret)
return ret;
}
valid_bit = *bt_addr & MPX_BD_ENTRY_VALID_FLAG;
*bt_addr &= MPX_BT_ADDR_MASK;
if (!valid_bit && *bt_addr)
return -EINVAL;
if (!valid_bit)
return -ENOENT;
return 0;
}
static int zap_bt_entries(struct mm_struct *mm,
unsigned long bt_addr,
unsigned long start, unsigned long end)
{
struct vm_area_struct *vma;
unsigned long addr, len;
vma = find_vma(mm, start);
if (!vma || vma->vm_start > start)
return -EINVAL;
addr = start;
while (vma && vma->vm_start < end) {
if (!is_mpx_vma(vma))
return -EINVAL;
len = min(vma->vm_end, end) - addr;
zap_page_range(vma, addr, len, NULL);
vma = vma->vm_next;
addr = vma->vm_start;
}
return 0;
}
static int unmap_single_bt(struct mm_struct *mm,
long __user *bd_entry, unsigned long bt_addr)
{
unsigned long expected_old_val = bt_addr | MPX_BD_ENTRY_VALID_FLAG;
unsigned long actual_old_val = 0;
int ret;
while (1) {
int need_write = 1;
pagefault_disable();
ret = user_atomic_cmpxchg_inatomic(&actual_old_val, bd_entry,
expected_old_val, 0);
pagefault_enable();
if (!ret)
break;
if (ret == -EFAULT)
ret = mpx_resolve_fault(bd_entry, need_write);
if (ret)
return ret;
}
if (actual_old_val != expected_old_val) {
if (!actual_old_val)
return 0;
return -EINVAL;
}
return do_munmap(mm, bt_addr, MPX_BT_SIZE_BYTES);
}
static int unmap_shared_bt(struct mm_struct *mm,
long __user *bd_entry, unsigned long start,
unsigned long end, bool prev_shared, bool next_shared)
{
unsigned long bt_addr;
int ret;
ret = get_bt_addr(mm, bd_entry, &bt_addr);
if (ret)
return ret;
if (prev_shared && next_shared)
ret = zap_bt_entries(mm, bt_addr,
bt_addr+MPX_GET_BT_ENTRY_OFFSET(start),
bt_addr+MPX_GET_BT_ENTRY_OFFSET(end));
else if (prev_shared)
ret = zap_bt_entries(mm, bt_addr,
bt_addr+MPX_GET_BT_ENTRY_OFFSET(start),
bt_addr+MPX_BT_SIZE_BYTES);
else if (next_shared)
ret = zap_bt_entries(mm, bt_addr, bt_addr,
bt_addr+MPX_GET_BT_ENTRY_OFFSET(end));
else
ret = unmap_single_bt(mm, bd_entry, bt_addr);
return ret;
}
static int unmap_edge_bts(struct mm_struct *mm,
unsigned long start, unsigned long end)
{
int ret;
long __user *bde_start, *bde_end;
struct vm_area_struct *prev, *next;
bool prev_shared = false, next_shared = false;
bde_start = mm->bd_addr + MPX_GET_BD_ENTRY_OFFSET(start);
bde_end = mm->bd_addr + MPX_GET_BD_ENTRY_OFFSET(end-1);
next = find_vma_prev(mm, start, &prev);
if (prev && (mm->bd_addr + MPX_GET_BD_ENTRY_OFFSET(prev->vm_end-1))
== bde_start)
prev_shared = true;
if (next && (mm->bd_addr + MPX_GET_BD_ENTRY_OFFSET(next->vm_start))
== bde_end)
next_shared = true;
if (bde_start == bde_end) {
return unmap_shared_bt(mm, bde_start, start, end,
prev_shared, next_shared);
}
ret = unmap_shared_bt(mm, bde_start, start, end, prev_shared, false);
if (ret)
return ret;
ret = unmap_shared_bt(mm, bde_end, start, end, false, next_shared);
if (ret)
return ret;
return 0;
}
static int mpx_unmap_tables(struct mm_struct *mm,
unsigned long start, unsigned long end)
{
int ret;
long __user *bd_entry, *bde_start, *bde_end;
unsigned long bt_addr;
ret = unmap_edge_bts(mm, start, end);
switch (ret) {
case 0:
case -ENOENT:
break;
case -EINVAL:
case -EFAULT:
default:
return ret;
}
bde_start = mm->bd_addr + MPX_GET_BD_ENTRY_OFFSET(start);
bde_end = mm->bd_addr + MPX_GET_BD_ENTRY_OFFSET(end-1);
for (bd_entry = bde_start + 1; bd_entry < bde_end; bd_entry++) {
ret = get_bt_addr(mm, bd_entry, &bt_addr);
switch (ret) {
case 0:
break;
case -ENOENT:
continue;
case -EINVAL:
case -EFAULT:
default:
return ret;
}
ret = unmap_single_bt(mm, bd_entry, bt_addr);
if (ret)
return ret;
}
return 0;
}
void mpx_notify_unmap(struct mm_struct *mm, struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
int ret;
if (!kernel_managing_mpx_tables(current->mm))
return;
do {
if (vma->vm_flags & VM_MPX)
return;
vma = vma->vm_next;
} while (vma && vma->vm_start < end);
ret = mpx_unmap_tables(mm, start, end);
if (ret)
force_sig(SIGSEGV, current);
}
