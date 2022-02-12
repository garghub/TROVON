void vmacache_flush_all(struct mm_struct *mm)
{
struct task_struct *g, *p;
count_vm_vmacache_event(VMACACHE_FULL_FLUSHES);
if (atomic_read(&mm->mm_users) == 1)
return;
rcu_read_lock();
for_each_process_thread(g, p) {
if (mm == p->mm)
vmacache_flush(p);
}
rcu_read_unlock();
}
static inline bool vmacache_valid_mm(struct mm_struct *mm)
{
return current->mm == mm && !(current->flags & PF_KTHREAD);
}
void vmacache_update(unsigned long addr, struct vm_area_struct *newvma)
{
if (vmacache_valid_mm(newvma->vm_mm))
current->vmacache[VMACACHE_HASH(addr)] = newvma;
}
static bool vmacache_valid(struct mm_struct *mm)
{
struct task_struct *curr;
if (!vmacache_valid_mm(mm))
return false;
curr = current;
if (mm->vmacache_seqnum != curr->vmacache_seqnum) {
curr->vmacache_seqnum = mm->vmacache_seqnum;
vmacache_flush(curr);
return false;
}
return true;
}
struct vm_area_struct *vmacache_find(struct mm_struct *mm, unsigned long addr)
{
int i;
count_vm_vmacache_event(VMACACHE_FIND_CALLS);
if (!vmacache_valid(mm))
return NULL;
for (i = 0; i < VMACACHE_SIZE; i++) {
struct vm_area_struct *vma = current->vmacache[i];
if (!vma)
continue;
if (WARN_ON_ONCE(vma->vm_mm != mm))
break;
if (vma->vm_start <= addr && vma->vm_end > addr) {
count_vm_vmacache_event(VMACACHE_FIND_HITS);
return vma;
}
}
return NULL;
}
struct vm_area_struct *vmacache_find_exact(struct mm_struct *mm,
unsigned long start,
unsigned long end)
{
int i;
count_vm_vmacache_event(VMACACHE_FIND_CALLS);
if (!vmacache_valid(mm))
return NULL;
for (i = 0; i < VMACACHE_SIZE; i++) {
struct vm_area_struct *vma = current->vmacache[i];
if (vma && vma->vm_start == start && vma->vm_end == end) {
count_vm_vmacache_event(VMACACHE_FIND_HITS);
return vma;
}
}
return NULL;
}
