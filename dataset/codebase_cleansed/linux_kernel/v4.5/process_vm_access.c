static int process_vm_rw_pages(struct page **pages,
unsigned offset,
size_t len,
struct iov_iter *iter,
int vm_write)
{
while (len && iov_iter_count(iter)) {
struct page *page = *pages++;
size_t copy = PAGE_SIZE - offset;
size_t copied;
if (copy > len)
copy = len;
if (vm_write) {
copied = copy_page_from_iter(page, offset, copy, iter);
set_page_dirty_lock(page);
} else {
copied = copy_page_to_iter(page, offset, copy, iter);
}
len -= copied;
if (copied < copy && iov_iter_count(iter))
return -EFAULT;
offset = 0;
}
return 0;
}
static int process_vm_rw_single_vec(unsigned long addr,
unsigned long len,
struct iov_iter *iter,
struct page **process_pages,
struct mm_struct *mm,
struct task_struct *task,
int vm_write)
{
unsigned long pa = addr & PAGE_MASK;
unsigned long start_offset = addr - pa;
unsigned long nr_pages;
ssize_t rc = 0;
unsigned long max_pages_per_loop = PVM_MAX_KMALLOC_PAGES
/ sizeof(struct pages *);
if (len == 0)
return 0;
nr_pages = (addr + len - 1) / PAGE_SIZE - addr / PAGE_SIZE + 1;
while (!rc && nr_pages && iov_iter_count(iter)) {
int pages = min(nr_pages, max_pages_per_loop);
size_t bytes;
pages = get_user_pages_unlocked(task, mm, pa, pages,
vm_write, 0, process_pages);
if (pages <= 0)
return -EFAULT;
bytes = pages * PAGE_SIZE - start_offset;
if (bytes > len)
bytes = len;
rc = process_vm_rw_pages(process_pages,
start_offset, bytes, iter,
vm_write);
len -= bytes;
start_offset = 0;
nr_pages -= pages;
pa += pages * PAGE_SIZE;
while (pages)
put_page(process_pages[--pages]);
}
return rc;
}
static ssize_t process_vm_rw_core(pid_t pid, struct iov_iter *iter,
const struct iovec *rvec,
unsigned long riovcnt,
unsigned long flags, int vm_write)
{
struct task_struct *task;
struct page *pp_stack[PVM_MAX_PP_ARRAY_COUNT];
struct page **process_pages = pp_stack;
struct mm_struct *mm;
unsigned long i;
ssize_t rc = 0;
unsigned long nr_pages = 0;
unsigned long nr_pages_iov;
ssize_t iov_len;
size_t total_len = iov_iter_count(iter);
for (i = 0; i < riovcnt; i++) {
iov_len = rvec[i].iov_len;
if (iov_len > 0) {
nr_pages_iov = ((unsigned long)rvec[i].iov_base
+ iov_len)
/ PAGE_SIZE - (unsigned long)rvec[i].iov_base
/ PAGE_SIZE + 1;
nr_pages = max(nr_pages, nr_pages_iov);
}
}
if (nr_pages == 0)
return 0;
if (nr_pages > PVM_MAX_PP_ARRAY_COUNT) {
process_pages = kmalloc(min_t(size_t, PVM_MAX_KMALLOC_PAGES,
sizeof(struct pages *)*nr_pages),
GFP_KERNEL);
if (!process_pages)
return -ENOMEM;
}
rcu_read_lock();
task = find_task_by_vpid(pid);
if (task)
get_task_struct(task);
rcu_read_unlock();
if (!task) {
rc = -ESRCH;
goto free_proc_pages;
}
mm = mm_access(task, PTRACE_MODE_ATTACH_REALCREDS);
if (!mm || IS_ERR(mm)) {
rc = IS_ERR(mm) ? PTR_ERR(mm) : -ESRCH;
if (rc == -EACCES)
rc = -EPERM;
goto put_task_struct;
}
for (i = 0; i < riovcnt && iov_iter_count(iter) && !rc; i++)
rc = process_vm_rw_single_vec(
(unsigned long)rvec[i].iov_base, rvec[i].iov_len,
iter, process_pages, mm, task, vm_write);
total_len -= iov_iter_count(iter);
if (total_len)
rc = total_len;
mmput(mm);
put_task_struct:
put_task_struct(task);
free_proc_pages:
if (process_pages != pp_stack)
kfree(process_pages);
return rc;
}
static ssize_t process_vm_rw(pid_t pid,
const struct iovec __user *lvec,
unsigned long liovcnt,
const struct iovec __user *rvec,
unsigned long riovcnt,
unsigned long flags, int vm_write)
{
struct iovec iovstack_l[UIO_FASTIOV];
struct iovec iovstack_r[UIO_FASTIOV];
struct iovec *iov_l = iovstack_l;
struct iovec *iov_r = iovstack_r;
struct iov_iter iter;
ssize_t rc;
int dir = vm_write ? WRITE : READ;
if (flags != 0)
return -EINVAL;
rc = import_iovec(dir, lvec, liovcnt, UIO_FASTIOV, &iov_l, &iter);
if (rc < 0)
return rc;
if (!iov_iter_count(&iter))
goto free_iovecs;
rc = rw_copy_check_uvector(CHECK_IOVEC_ONLY, rvec, riovcnt, UIO_FASTIOV,
iovstack_r, &iov_r);
if (rc <= 0)
goto free_iovecs;
rc = process_vm_rw_core(pid, &iter, iov_r, riovcnt, flags, vm_write);
free_iovecs:
if (iov_r != iovstack_r)
kfree(iov_r);
kfree(iov_l);
return rc;
}
static ssize_t
compat_process_vm_rw(compat_pid_t pid,
const struct compat_iovec __user *lvec,
unsigned long liovcnt,
const struct compat_iovec __user *rvec,
unsigned long riovcnt,
unsigned long flags, int vm_write)
{
struct iovec iovstack_l[UIO_FASTIOV];
struct iovec iovstack_r[UIO_FASTIOV];
struct iovec *iov_l = iovstack_l;
struct iovec *iov_r = iovstack_r;
struct iov_iter iter;
ssize_t rc = -EFAULT;
int dir = vm_write ? WRITE : READ;
if (flags != 0)
return -EINVAL;
rc = compat_import_iovec(dir, lvec, liovcnt, UIO_FASTIOV, &iov_l, &iter);
if (rc < 0)
return rc;
if (!iov_iter_count(&iter))
goto free_iovecs;
rc = compat_rw_copy_check_uvector(CHECK_IOVEC_ONLY, rvec, riovcnt,
UIO_FASTIOV, iovstack_r,
&iov_r);
if (rc <= 0)
goto free_iovecs;
rc = process_vm_rw_core(pid, &iter, iov_r, riovcnt, flags, vm_write);
free_iovecs:
if (iov_r != iovstack_r)
kfree(iov_r);
kfree(iov_l);
return rc;
}
