static inline int
fetch_robust_entry(compat_uptr_t *uentry, struct robust_list __user **entry,
compat_uptr_t __user *head, unsigned int *pi)
{
if (get_user(*uentry, head))
return -EFAULT;
*entry = compat_ptr((*uentry) & ~1);
*pi = (unsigned int)(*uentry) & 1;
return 0;
}
static void __user *futex_uaddr(struct robust_list __user *entry,
compat_long_t futex_offset)
{
compat_uptr_t base = ptr_to_compat(entry);
void __user *uaddr = compat_ptr(base + futex_offset);
return uaddr;
}
void compat_exit_robust_list(struct task_struct *curr)
{
struct compat_robust_list_head __user *head = curr->compat_robust_list;
struct robust_list __user *entry, *next_entry, *pending;
unsigned int limit = ROBUST_LIST_LIMIT, pi, pip;
unsigned int uninitialized_var(next_pi);
compat_uptr_t uentry, next_uentry, upending;
compat_long_t futex_offset;
int rc;
if (!futex_cmpxchg_enabled)
return;
if (fetch_robust_entry(&uentry, &entry, &head->list.next, &pi))
return;
if (get_user(futex_offset, &head->futex_offset))
return;
if (fetch_robust_entry(&upending, &pending,
&head->list_op_pending, &pip))
return;
next_entry = NULL;
while (entry != (struct robust_list __user *) &head->list) {
rc = fetch_robust_entry(&next_uentry, &next_entry,
(compat_uptr_t __user *)&entry->next, &next_pi);
if (entry != pending) {
void __user *uaddr = futex_uaddr(entry, futex_offset);
if (handle_futex_death(uaddr, curr, pi))
return;
}
if (rc)
return;
uentry = next_uentry;
entry = next_entry;
pi = next_pi;
if (!--limit)
break;
cond_resched();
}
if (pending) {
void __user *uaddr = futex_uaddr(pending, futex_offset);
handle_futex_death(uaddr, curr, pip);
}
}
