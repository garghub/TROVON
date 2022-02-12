void policy_from_vma(union ldlm_policy_data *policy,
struct vm_area_struct *vma, unsigned long addr,
size_t count)
{
policy->l_extent.start = ((addr - vma->vm_start) & PAGE_MASK) +
(vma->vm_pgoff << PAGE_SHIFT);
policy->l_extent.end = (policy->l_extent.start + count - 1) |
~PAGE_MASK;
}
struct vm_area_struct *our_vma(struct mm_struct *mm, unsigned long addr,
size_t count)
{
struct vm_area_struct *vma, *ret = NULL;
LASSERT(!down_write_trylock(&mm->mmap_sem));
for (vma = find_vma(mm, addr);
vma && vma->vm_start < (addr + count); vma = vma->vm_next) {
if (vma->vm_ops && vma->vm_ops == &ll_file_vm_ops &&
vma->vm_flags & VM_SHARED) {
ret = vma;
break;
}
}
return ret;
}
static struct cl_io *
ll_fault_io_init(struct lu_env *env, struct vm_area_struct *vma,
pgoff_t index, unsigned long *ra_flags)
{
struct file *file = vma->vm_file;
struct inode *inode = file_inode(file);
struct cl_io *io;
struct cl_fault_io *fio;
int rc;
if (ll_file_nolock(file))
return ERR_PTR(-EOPNOTSUPP);
restart:
io = vvp_env_thread_io(env);
io->ci_obj = ll_i2info(inode)->lli_clob;
LASSERT(io->ci_obj);
fio = &io->u.ci_fault;
fio->ft_index = index;
fio->ft_executable = vma->vm_flags & VM_EXEC;
if (ra_flags)
*ra_flags = vma->vm_flags & (VM_RAND_READ | VM_SEQ_READ);
vma->vm_flags &= ~VM_SEQ_READ;
vma->vm_flags |= VM_RAND_READ;
CDEBUG(D_MMAP, "vm_flags: %lx (%lu %d)\n", vma->vm_flags,
fio->ft_index, fio->ft_executable);
rc = cl_io_init(env, io, CIT_FAULT, io->ci_obj);
if (rc == 0) {
struct vvp_io *vio = vvp_env_io(env);
struct ll_file_data *fd = LUSTRE_FPRIVATE(file);
LASSERT(vio->vui_cl.cis_io == io);
io->ci_lockreq = CILR_MANDATORY;
vio->vui_fd = fd;
} else {
LASSERT(rc < 0);
cl_io_fini(env, io);
if (io->ci_need_restart)
goto restart;
io = ERR_PTR(rc);
}
return io;
}
static int ll_page_mkwrite0(struct vm_area_struct *vma, struct page *vmpage,
bool *retry)
{
struct lu_env *env;
struct cl_io *io;
struct vvp_io *vio;
int result;
int refcheck;
sigset_t set;
struct inode *inode;
struct ll_inode_info *lli;
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return PTR_ERR(env);
io = ll_fault_io_init(env, vma, vmpage->index, NULL);
if (IS_ERR(io)) {
result = PTR_ERR(io);
goto out;
}
result = io->ci_result;
if (result < 0)
goto out_io;
io->u.ci_fault.ft_mkwrite = 1;
io->u.ci_fault.ft_writable = 1;
vio = vvp_env_io(env);
vio->u.fault.ft_vma = vma;
vio->u.fault.ft_vmpage = vmpage;
set = cfs_block_sigsinv(sigmask(SIGKILL) | sigmask(SIGTERM));
inode = vvp_object_inode(io->ci_obj);
lli = ll_i2info(inode);
result = cl_io_loop(env, io);
cfs_restore_sigs(set);
if (result == 0) {
struct inode *inode = file_inode(vma->vm_file);
struct ll_inode_info *lli = ll_i2info(inode);
lock_page(vmpage);
if (!vmpage->mapping) {
unlock_page(vmpage);
if (result == 0)
result = -ENODATA;
} else if (!PageDirty(vmpage)) {
unlock_page(vmpage);
CDEBUG(D_MMAP, "Race on page_mkwrite %p/%lu, page has been written out, retry.\n",
vmpage, vmpage->index);
*retry = true;
result = -EAGAIN;
}
if (!result)
set_bit(LLIF_DATA_MODIFIED, &lli->lli_flags);
}
out_io:
cl_io_fini(env, io);
out:
cl_env_put(env, &refcheck);
CDEBUG(D_MMAP, "%s mkwrite with %d\n", current->comm, result);
LASSERT(ergo(result == 0, PageLocked(vmpage)));
return result;
}
static inline int to_fault_error(int result)
{
switch (result) {
case 0:
result = VM_FAULT_LOCKED;
break;
case -EFAULT:
result = VM_FAULT_NOPAGE;
break;
case -ENOMEM:
result = VM_FAULT_OOM;
break;
default:
result = VM_FAULT_SIGBUS;
break;
}
return result;
}
static int ll_fault0(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct lu_env *env;
struct cl_io *io;
struct vvp_io *vio = NULL;
struct page *vmpage;
unsigned long ra_flags;
int result = 0;
int fault_ret = 0;
int refcheck;
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return PTR_ERR(env);
io = ll_fault_io_init(env, vma, vmf->pgoff, &ra_flags);
if (IS_ERR(io)) {
result = to_fault_error(PTR_ERR(io));
goto out;
}
result = io->ci_result;
if (result == 0) {
vio = vvp_env_io(env);
vio->u.fault.ft_vma = vma;
vio->u.fault.ft_vmpage = NULL;
vio->u.fault.ft_vmf = vmf;
vio->u.fault.ft_flags = 0;
vio->u.fault.ft_flags_valid = false;
ll_cl_add(vma->vm_file, env, io);
result = cl_io_loop(env, io);
ll_cl_remove(vma->vm_file, env);
if (vio->u.fault.ft_flags_valid)
fault_ret = vio->u.fault.ft_flags;
vmpage = vio->u.fault.ft_vmpage;
if (result != 0 && vmpage) {
put_page(vmpage);
vmf->page = NULL;
}
}
cl_io_fini(env, io);
vma->vm_flags |= ra_flags;
out:
cl_env_put(env, &refcheck);
if (result != 0 && !(fault_ret & VM_FAULT_RETRY))
fault_ret |= to_fault_error(result);
CDEBUG(D_MMAP, "%s fault %d/%d\n", current->comm, fault_ret, result);
return fault_ret;
}
static int ll_fault(struct vm_fault *vmf)
{
int count = 0;
bool printed = false;
int result;
sigset_t set;
set = cfs_block_sigsinv(sigmask(SIGKILL) | sigmask(SIGTERM));
restart:
result = ll_fault0(vmf->vma, vmf);
LASSERT(!(result & VM_FAULT_LOCKED));
if (result == 0) {
struct page *vmpage = vmf->page;
lock_page(vmpage);
if (unlikely(!vmpage->mapping)) {
unlock_page(vmpage);
put_page(vmpage);
vmf->page = NULL;
if (!printed && ++count > 16) {
CWARN("the page is under heavy contention, maybe your app(%s) needs revising :-)\n",
current->comm);
printed = true;
}
goto restart;
}
result = VM_FAULT_LOCKED;
}
cfs_restore_sigs(set);
return result;
}
static int ll_page_mkwrite(struct vm_fault *vmf)
{
struct vm_area_struct *vma = vmf->vma;
int count = 0;
bool printed = false;
bool retry;
int result;
file_update_time(vma->vm_file);
do {
retry = false;
result = ll_page_mkwrite0(vma, vmf->page, &retry);
if (!printed && ++count > 16) {
const struct dentry *de = vma->vm_file->f_path.dentry;
CWARN("app(%s): the page %lu of file "DFID" is under heavy contention\n",
current->comm, vmf->pgoff,
PFID(ll_inode2fid(de->d_inode)));
printed = true;
}
} while (retry);
switch (result) {
case 0:
LASSERT(PageLocked(vmf->page));
result = VM_FAULT_LOCKED;
break;
case -ENODATA:
case -EAGAIN:
case -EFAULT:
result = VM_FAULT_NOPAGE;
break;
case -ENOMEM:
result = VM_FAULT_OOM;
break;
default:
result = VM_FAULT_SIGBUS;
break;
}
return result;
}
static void ll_vm_open(struct vm_area_struct *vma)
{
struct inode *inode = file_inode(vma->vm_file);
struct vvp_object *vob = cl_inode2vvp(inode);
LASSERT(atomic_read(&vob->vob_mmap_cnt) >= 0);
atomic_inc(&vob->vob_mmap_cnt);
}
static void ll_vm_close(struct vm_area_struct *vma)
{
struct inode *inode = file_inode(vma->vm_file);
struct vvp_object *vob = cl_inode2vvp(inode);
atomic_dec(&vob->vob_mmap_cnt);
LASSERT(atomic_read(&vob->vob_mmap_cnt) >= 0);
}
int ll_teardown_mmaps(struct address_space *mapping, __u64 first, __u64 last)
{
int rc = -ENOENT;
LASSERTF(last > first, "last %llu first %llu\n", last, first);
if (mapping_mapped(mapping)) {
rc = 0;
unmap_mapping_range(mapping, first + PAGE_SIZE - 1,
last - first + 1, 0);
}
return rc;
}
int ll_file_mmap(struct file *file, struct vm_area_struct *vma)
{
struct inode *inode = file_inode(file);
int rc;
if (ll_file_nolock(file))
return -EOPNOTSUPP;
ll_stats_ops_tally(ll_i2sbi(inode), LPROC_LL_MAP, 1);
rc = generic_file_mmap(file, vma);
if (rc == 0) {
vma->vm_ops = &ll_file_vm_ops;
vma->vm_ops->open(vma);
rc = ll_glimpse_size(inode);
}
return rc;
}
