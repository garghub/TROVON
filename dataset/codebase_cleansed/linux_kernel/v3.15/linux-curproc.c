void cfs_cap_raise(cfs_cap_t cap)
{
struct cred *cred;
cred = prepare_creds();
if (cred) {
cap_raise(cred->cap_effective, cap);
commit_creds(cred);
}
}
void cfs_cap_lower(cfs_cap_t cap)
{
struct cred *cred;
cred = prepare_creds();
if (cred) {
cap_lower(cred->cap_effective, cap);
commit_creds(cred);
}
}
int cfs_cap_raised(cfs_cap_t cap)
{
return cap_raised(current_cap(), cap);
}
void cfs_kernel_cap_pack(kernel_cap_t kcap, cfs_cap_t *cap)
{
*cap = kcap.cap[0];
}
void cfs_kernel_cap_unpack(kernel_cap_t *kcap, cfs_cap_t cap)
{
kcap->cap[0] = cap;
}
cfs_cap_t cfs_curproc_cap_pack(void)
{
cfs_cap_t cap;
cfs_kernel_cap_pack(current_cap(), &cap);
return cap;
}
static int cfs_access_process_vm(struct task_struct *tsk, unsigned long addr,
void *buf, int len, int write)
{
struct mm_struct *mm;
struct vm_area_struct *vma;
struct page *page;
void *old_buf = buf;
mm = get_task_mm(tsk);
if (!mm)
return 0;
down_read(&mm->mmap_sem);
while (len) {
int bytes, rc, offset;
void *maddr;
rc = get_user_pages(tsk, mm, addr, 1,
write, 1, &page, &vma);
if (rc <= 0)
break;
bytes = len;
offset = addr & (PAGE_SIZE-1);
if (bytes > PAGE_SIZE-offset)
bytes = PAGE_SIZE-offset;
maddr = kmap(page);
if (write) {
copy_to_user_page(vma, page, addr,
maddr + offset, buf, bytes);
set_page_dirty_lock(page);
} else {
copy_from_user_page(vma, page, addr,
buf, maddr + offset, bytes);
}
kunmap(page);
page_cache_release(page);
len -= bytes;
buf += bytes;
addr += bytes;
}
up_read(&mm->mmap_sem);
mmput(mm);
return buf - old_buf;
}
int cfs_get_environ(const char *key, char *value, int *val_len)
{
struct mm_struct *mm;
char *buffer, *tmp_buf = NULL;
int buf_len = PAGE_CACHE_SIZE;
int key_len = strlen(key);
unsigned long addr;
int rc;
buffer = kmalloc(buf_len, GFP_USER);
if (!buffer)
return -ENOMEM;
mm = get_task_mm(current);
if (!mm) {
kfree(buffer);
return -EINVAL;
}
if (down_read_trylock(&mm->mmap_sem) == 0) {
kfree(buffer);
return -EDEADLK;
}
up_read(&mm->mmap_sem);
addr = mm->env_start;
while (addr < mm->env_end) {
int this_len, retval, scan_len;
char *env_start, *env_end;
memset(buffer, 0, buf_len);
this_len = min_t(int, mm->env_end - addr, buf_len);
retval = cfs_access_process_vm(current, addr, buffer,
this_len, 0);
if (retval != this_len)
break;
addr += retval;
env_start = buffer;
scan_len = this_len;
while (scan_len) {
char *entry;
int entry_len;
env_end = memscan(env_start, '\0', scan_len);
LASSERT(env_end >= env_start &&
env_end <= env_start + scan_len);
if (unlikely(env_end - env_start == scan_len)) {
if (unlikely(scan_len == this_len)) {
CERROR("Too long env variable.\n");
GOTO(out, rc = -EINVAL);
}
addr -= scan_len;
break;
}
entry = env_start;
entry_len = env_end - env_start;
if (entry_len > key_len + 1 &&
!memcmp(entry, key, key_len)) {
entry += key_len + 1;
entry_len -= key_len + 1;
if (entry_len >= *val_len)
GOTO(out, rc = -EOVERFLOW);
memcpy(value, entry, entry_len);
*val_len = entry_len;
GOTO(out, rc = 0);
}
scan_len -= (env_end - env_start + 1);
env_start = env_end + 1;
}
}
GOTO(out, rc = -ENOENT);
out:
mmput(mm);
kfree((void *)buffer);
if (tmp_buf)
kfree((void *)tmp_buf);
return rc;
}
