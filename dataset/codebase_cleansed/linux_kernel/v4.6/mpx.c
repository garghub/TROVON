static inline unsigned long mpx_bd_size_bytes(struct mm_struct *mm)
{
if (is_64bit_mm(mm))
return MPX_BD_SIZE_BYTES_64;
else
return MPX_BD_SIZE_BYTES_32;
}
static inline unsigned long mpx_bt_size_bytes(struct mm_struct *mm)
{
if (is_64bit_mm(mm))
return MPX_BT_SIZE_BYTES_64;
else
return MPX_BT_SIZE_BYTES_32;
}
static unsigned long mpx_mmap(unsigned long len)
{
struct mm_struct *mm = current->mm;
unsigned long addr, populate;
if (len != mpx_bt_size_bytes(mm))
return -EINVAL;
down_write(&mm->mmap_sem);
addr = do_mmap(NULL, 0, len, PROT_READ | PROT_WRITE,
MAP_ANONYMOUS | MAP_PRIVATE, VM_MPX, 0, &populate);
up_write(&mm->mmap_sem);
if (populate)
mm_populate(addr, populate);
return addr;
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
if (X86_REX_B(insn->rex_prefix.value))
regno += 8;
break;
case REG_TYPE_INDEX:
regno = X86_SIB_INDEX(insn->sib.value);
if (X86_REX_X(insn->rex_prefix.value))
regno += 8;
break;
case REG_TYPE_BASE:
regno = X86_SIB_BASE(insn->sib.value);
if (X86_REX_B(insn->rex_prefix.value))
regno += 8;
break;
default:
pr_err("invalid register type");
BUG();
break;
}
if (regno >= nr_registers) {
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
siginfo_t *mpx_generate_siginfo(struct pt_regs *regs)
{
const struct mpx_bndreg_state *bndregs;
const struct mpx_bndreg *bndreg;
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
bndregs = get_xsave_field_ptr(XFEATURE_MASK_BNDREGS);
if (!bndregs) {
err = -EINVAL;
goto err_out;
}
bndreg = &bndregs->bndreg[bndregno];
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
trace_mpx_bounds_register_exception(info->si_addr, bndreg);
return info;
err_out:
kfree(info);
return ERR_PTR(err);
}
static __user void *mpx_get_bounds_dir(void)
{
const struct mpx_bndcsr *bndcsr;
if (!cpu_feature_enabled(X86_FEATURE_MPX))
return MPX_INVALID_BOUNDS_DIR;
bndcsr = get_xsave_field_ptr(XFEATURE_MASK_BNDCSR);
if (!bndcsr)
return MPX_INVALID_BOUNDS_DIR;
if (!(bndcsr->bndcfgu & MPX_BNDCFG_ENABLE_FLAG))
return MPX_INVALID_BOUNDS_DIR;
return (void __user *)(unsigned long)
(bndcsr->bndcfgu & MPX_BNDCFG_ADDR_MASK);
}
int mpx_enable_management(void)
{
void __user *bd_base = MPX_INVALID_BOUNDS_DIR;
struct mm_struct *mm = current->mm;
int ret = 0;
bd_base = mpx_get_bounds_dir();
down_write(&mm->mmap_sem);
mm->bd_addr = bd_base;
if (mm->bd_addr == MPX_INVALID_BOUNDS_DIR)
ret = -ENXIO;
up_write(&mm->mmap_sem);
return ret;
}
int mpx_disable_management(void)
{
struct mm_struct *mm = current->mm;
if (!cpu_feature_enabled(X86_FEATURE_MPX))
return -ENXIO;
down_write(&mm->mmap_sem);
mm->bd_addr = MPX_INVALID_BOUNDS_DIR;
up_write(&mm->mmap_sem);
return 0;
}
static int mpx_cmpxchg_bd_entry(struct mm_struct *mm,
unsigned long *curval,
unsigned long __user *addr,
unsigned long old_val, unsigned long new_val)
{
int ret;
if (is_64bit_mm(mm)) {
ret = user_atomic_cmpxchg_inatomic(curval,
addr, old_val, new_val);
} else {
u32 uninitialized_var(curval_32);
u32 old_val_32 = old_val;
u32 new_val_32 = new_val;
u32 __user *addr_32 = (u32 __user *)addr;
ret = user_atomic_cmpxchg_inatomic(&curval_32,
addr_32, old_val_32, new_val_32);
*curval = curval_32;
}
return ret;
}
static int allocate_bt(struct mm_struct *mm, long __user *bd_entry)
{
unsigned long expected_old_val = 0;
unsigned long actual_old_val = 0;
unsigned long bt_addr;
unsigned long bd_new_entry;
int ret = 0;
bt_addr = mpx_mmap(mpx_bt_size_bytes(mm));
if (IS_ERR((void *)bt_addr))
return PTR_ERR((void *)bt_addr);
bd_new_entry = bt_addr | MPX_BD_ENTRY_VALID_FLAG;
ret = mpx_cmpxchg_bd_entry(mm, &actual_old_val, bd_entry,
expected_old_val, bd_new_entry);
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
trace_mpx_new_bounds_table(bt_addr);
return 0;
out_unmap:
vm_munmap(bt_addr, mpx_bt_size_bytes(mm));
return ret;
}
static int do_mpx_bt_fault(void)
{
unsigned long bd_entry, bd_base;
const struct mpx_bndcsr *bndcsr;
struct mm_struct *mm = current->mm;
bndcsr = get_xsave_field_ptr(XFEATURE_MASK_BNDCSR);
if (!bndcsr)
return -EINVAL;
bd_base = bndcsr->bndcfgu & MPX_BNDCFG_ADDR_MASK;
bd_entry = bndcsr->bndstatus & MPX_BNDSTA_ADDR_MASK;
if ((bd_entry < bd_base) ||
(bd_entry >= bd_base + mpx_bd_size_bytes(mm)))
return -EINVAL;
return allocate_bt(mm, (long __user *)bd_entry);
}
int mpx_handle_bd_fault(void)
{
if (!kernel_managing_mpx_tables(current->mm))
return -EINVAL;
if (do_mpx_bt_fault()) {
force_sig(SIGSEGV, current);
}
return 0;
}
static int mpx_resolve_fault(long __user *addr, int write)
{
long gup_ret;
int nr_pages = 1;
int force = 0;
gup_ret = get_user_pages((unsigned long)addr, nr_pages, write,
force, NULL, NULL);
if (!gup_ret)
return -EFAULT;
if (gup_ret < 0)
return gup_ret;
return 0;
}
static unsigned long mpx_bd_entry_to_bt_addr(struct mm_struct *mm,
unsigned long bd_entry)
{
unsigned long bt_addr = bd_entry;
int align_to_bytes;
bt_addr &= ~MPX_BD_ENTRY_VALID_FLAG;
if (is_64bit_mm(mm))
align_to_bytes = 8;
else
align_to_bytes = 4;
bt_addr &= ~(align_to_bytes-1);
return bt_addr;
}
int get_user_bd_entry(struct mm_struct *mm, unsigned long *bd_entry_ret,
long __user *bd_entry_ptr)
{
u32 bd_entry_32;
int ret;
if (is_64bit_mm(mm))
return get_user(*bd_entry_ret, bd_entry_ptr);
ret = get_user(bd_entry_32, (u32 __user *)bd_entry_ptr);
*bd_entry_ret = bd_entry_32;
return ret;
}
static int get_bt_addr(struct mm_struct *mm,
long __user *bd_entry_ptr,
unsigned long *bt_addr_result)
{
int ret;
int valid_bit;
unsigned long bd_entry;
unsigned long bt_addr;
if (!access_ok(VERIFY_READ, (bd_entry_ptr), sizeof(*bd_entry_ptr)))
return -EFAULT;
while (1) {
int need_write = 0;
pagefault_disable();
ret = get_user_bd_entry(mm, &bd_entry, bd_entry_ptr);
pagefault_enable();
if (!ret)
break;
if (ret == -EFAULT)
ret = mpx_resolve_fault(bd_entry_ptr, need_write);
if (ret)
return ret;
}
valid_bit = bd_entry & MPX_BD_ENTRY_VALID_FLAG;
bt_addr = mpx_bd_entry_to_bt_addr(mm, bd_entry);
if (!valid_bit && bt_addr)
return -EINVAL;
if (!valid_bit)
return -ENOENT;
*bt_addr_result = bt_addr;
return 0;
}
static inline int bt_entry_size_bytes(struct mm_struct *mm)
{
if (is_64bit_mm(mm))
return MPX_BT_ENTRY_BYTES_64;
else
return MPX_BT_ENTRY_BYTES_32;
}
static unsigned long mpx_get_bt_entry_offset_bytes(struct mm_struct *mm,
unsigned long addr)
{
unsigned long bt_table_nr_entries;
unsigned long offset = addr;
if (is_64bit_mm(mm)) {
offset >>= 3;
bt_table_nr_entries = MPX_BT_NR_ENTRIES_64;
} else {
offset >>= 2;
bt_table_nr_entries = MPX_BT_NR_ENTRIES_32;
}
offset &= (bt_table_nr_entries-1);
offset *= bt_entry_size_bytes(mm);
return offset;
}
static inline unsigned long bd_entry_virt_space(struct mm_struct *mm)
{
unsigned long long virt_space;
unsigned long long GB = (1ULL << 30);
if (!is_64bit_mm(mm))
return (4ULL * GB) / MPX_BD_NR_ENTRIES_32;
virt_space = (1ULL << boot_cpu_data.x86_virt_bits);
return virt_space / MPX_BD_NR_ENTRIES_64;
}
static noinline int zap_bt_entries_mapping(struct mm_struct *mm,
unsigned long bt_addr,
unsigned long start_mapping, unsigned long end_mapping)
{
struct vm_area_struct *vma;
unsigned long addr, len;
unsigned long start;
unsigned long end;
start = bt_addr + mpx_get_bt_entry_offset_bytes(mm, start_mapping);
end = bt_addr + mpx_get_bt_entry_offset_bytes(mm, end_mapping - 1);
end += bt_entry_size_bytes(mm);
vma = find_vma(mm, start);
if (!vma || vma->vm_start > start)
return -EINVAL;
addr = start;
while (vma && vma->vm_start < end) {
if (!(vma->vm_flags & VM_MPX))
return -EINVAL;
len = min(vma->vm_end, end) - addr;
zap_page_range(vma, addr, len, NULL);
trace_mpx_unmap_zap(addr, addr+len);
vma = vma->vm_next;
addr = vma->vm_start;
}
return 0;
}
static unsigned long mpx_get_bd_entry_offset(struct mm_struct *mm,
unsigned long addr)
{
if (is_64bit_mm(mm)) {
int bd_entry_size = 8;
addr &= ((1UL << boot_cpu_data.x86_virt_bits) - 1);
return (addr / bd_entry_virt_space(mm)) * bd_entry_size;
} else {
int bd_entry_size = 4;
return (addr / bd_entry_virt_space(mm)) * bd_entry_size;
}
}
static int unmap_entire_bt(struct mm_struct *mm,
long __user *bd_entry, unsigned long bt_addr)
{
unsigned long expected_old_val = bt_addr | MPX_BD_ENTRY_VALID_FLAG;
unsigned long uninitialized_var(actual_old_val);
int ret;
while (1) {
int need_write = 1;
unsigned long cleared_bd_entry = 0;
pagefault_disable();
ret = mpx_cmpxchg_bd_entry(mm, &actual_old_val,
bd_entry, expected_old_val, cleared_bd_entry);
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
return do_munmap(mm, bt_addr, mpx_bt_size_bytes(mm));
}
static int try_unmap_single_bt(struct mm_struct *mm,
unsigned long start, unsigned long end)
{
struct vm_area_struct *next;
struct vm_area_struct *prev;
unsigned long bta_start_vaddr = start & ~(bd_entry_virt_space(mm)-1);
unsigned long bta_end_vaddr = bta_start_vaddr + bd_entry_virt_space(mm);
unsigned long uninitialized_var(bt_addr);
void __user *bde_vaddr;
int ret;
next = find_vma_prev(mm, start, &prev);
while (next && (next->vm_flags & VM_MPX))
next = next->vm_next;
while (prev && (prev->vm_flags & VM_MPX))
prev = prev->vm_prev;
next = find_vma_prev(mm, start, &prev);
if ((!prev || prev->vm_end <= bta_start_vaddr) &&
(!next || next->vm_start >= bta_end_vaddr)) {
start = bta_start_vaddr;
end = bta_end_vaddr;
}
bde_vaddr = mm->bd_addr + mpx_get_bd_entry_offset(mm, start);
ret = get_bt_addr(mm, bde_vaddr, &bt_addr);
if (ret == -ENOENT) {
ret = 0;
return 0;
}
if (ret)
return ret;
if ((start == bta_start_vaddr) &&
(end == bta_end_vaddr))
return unmap_entire_bt(mm, bde_vaddr, bt_addr);
return zap_bt_entries_mapping(mm, bt_addr, start, end);
}
static int mpx_unmap_tables(struct mm_struct *mm,
unsigned long start, unsigned long end)
{
unsigned long one_unmap_start;
trace_mpx_unmap_search(start, end);
one_unmap_start = start;
while (one_unmap_start < end) {
int ret;
unsigned long next_unmap_start = ALIGN(one_unmap_start+1,
bd_entry_virt_space(mm));
unsigned long one_unmap_end = end;
if (one_unmap_end > next_unmap_start)
one_unmap_end = next_unmap_start;
ret = try_unmap_single_bt(mm, one_unmap_start, one_unmap_end);
if (ret)
return ret;
one_unmap_start = next_unmap_start;
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
