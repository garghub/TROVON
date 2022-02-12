int __execute_only_pkey(struct mm_struct *mm)
{
bool need_to_set_mm_pkey = false;
int execute_only_pkey = mm->context.execute_only_pkey;
int ret;
if (execute_only_pkey == -1) {
execute_only_pkey = mm_pkey_alloc(mm);
if (execute_only_pkey < 0)
return -1;
need_to_set_mm_pkey = true;
}
preempt_disable();
if (!need_to_set_mm_pkey &&
current->thread.fpu.initialized &&
!__pkru_allows_read(read_pkru(), execute_only_pkey)) {
preempt_enable();
return execute_only_pkey;
}
preempt_enable();
ret = arch_set_user_pkey_access(current, execute_only_pkey,
PKEY_DISABLE_ACCESS);
if (ret) {
mm_set_pkey_free(mm, execute_only_pkey);
return -1;
}
if (need_to_set_mm_pkey)
mm->context.execute_only_pkey = execute_only_pkey;
return execute_only_pkey;
}
static inline bool vma_is_pkey_exec_only(struct vm_area_struct *vma)
{
if ((vma->vm_flags & (VM_READ | VM_WRITE | VM_EXEC)) != VM_EXEC)
return false;
if (vma_pkey(vma) != vma->vm_mm->context.execute_only_pkey)
return false;
return true;
}
int __arch_override_mprotect_pkey(struct vm_area_struct *vma, int prot, int pkey)
{
if (pkey != -1)
return pkey;
if (vma_is_pkey_exec_only(vma) &&
(prot & (PROT_READ|PROT_WRITE))) {
return 0;
}
if (prot == PROT_EXEC) {
pkey = execute_only_pkey(vma->vm_mm);
if (pkey > 0)
return pkey;
}
return vma_pkey(vma);
}
void copy_init_pkru_to_fpregs(void)
{
u32 init_pkru_value_snapshot = READ_ONCE(init_pkru_value);
if (!init_pkru_value_snapshot && !read_pkru())
return;
write_pkru(init_pkru_value_snapshot);
}
static ssize_t init_pkru_read_file(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
char buf[32];
unsigned int len;
len = sprintf(buf, "0x%x\n", init_pkru_value);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t init_pkru_write_file(struct file *file,
const char __user *user_buf, size_t count, loff_t *ppos)
{
char buf[32];
ssize_t len;
u32 new_init_pkru;
len = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, len))
return -EFAULT;
buf[len] = '\0';
if (kstrtouint(buf, 0, &new_init_pkru))
return -EINVAL;
if (new_init_pkru & (PKRU_AD_BIT|PKRU_WD_BIT))
return -EINVAL;
WRITE_ONCE(init_pkru_value, new_init_pkru);
return count;
}
static int __init create_init_pkru_value(void)
{
debugfs_create_file("init_pkru", S_IRUSR | S_IWUSR,
arch_debugfs_dir, NULL, &fops_init_pkru);
return 0;
}
static __init int setup_init_pkru(char *opt)
{
u32 new_init_pkru;
if (kstrtouint(opt, 0, &new_init_pkru))
return 1;
WRITE_ONCE(init_pkru_value, new_init_pkru);
return 1;
}
