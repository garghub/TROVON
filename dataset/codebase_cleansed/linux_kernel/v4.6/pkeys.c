int __execute_only_pkey(struct mm_struct *mm)
{
int ret;
preempt_disable();
if (fpregs_active() &&
!__pkru_allows_read(read_pkru(), PKEY_DEDICATED_EXECUTE_ONLY)) {
preempt_enable();
return PKEY_DEDICATED_EXECUTE_ONLY;
}
preempt_enable();
ret = arch_set_user_pkey_access(current, PKEY_DEDICATED_EXECUTE_ONLY,
PKEY_DISABLE_ACCESS);
if (ret)
return 0;
return PKEY_DEDICATED_EXECUTE_ONLY;
}
static inline bool vma_is_pkey_exec_only(struct vm_area_struct *vma)
{
if ((vma->vm_flags & (VM_READ | VM_WRITE | VM_EXEC)) != VM_EXEC)
return false;
if (vma_pkey(vma) != PKEY_DEDICATED_EXECUTE_ONLY)
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
