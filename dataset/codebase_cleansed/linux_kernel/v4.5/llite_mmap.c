void policy_from_vma(ldlm_policy_data_t *policy,
struct vm_area_struct *vma, unsigned long addr,
size_t count)
{
policy->l_extent.start = ((addr - vma->vm_start) & CFS_PAGE_MASK) +
(vma->vm_pgoff << PAGE_CACHE_SHIFT);
policy->l_extent.end = (policy->l_extent.start + count - 1) |
~CFS_PAGE_MASK;
}
struct vm_area_struct *our_vma(struct mm_struct *mm, unsigned long addr,
size_t count)
{
struct vm_area_struct *vma, *ret = NULL;
LASSERT(!down_write_trylock(&mm->mmap_sem));
for (vma = find_vma(mm, addr);
vma != NULL && vma->vm_start < (addr + count); vma = vma->vm_next) {
if (vma->vm_ops && vma->vm_ops == &ll_file_vm_ops &&
vma->vm_flags & VM_SHARED) {
ret = vma;
break;
}
}
return ret;
}
static struct cl_io *
ll_fault_io_init(struct vm_area_struct *vma, struct lu_env **env_ret,
struct cl_env_nest *nest, pgoff_t index,
unsigned long *ra_flags)
{
struct file *file = vma->vm_file;
struct inode *inode = file_inode(file);
struct cl_io *io;
struct cl_fault_io *fio;
struct lu_env *env;
int rc;
*env_ret = NULL;
if (ll_file_nolock(file))
return ERR_PTR(-EOPNOTSUPP);
env = cl_env_nested_get(nest);
if (IS_ERR(env))
return ERR_PTR(-EINVAL);
*env_ret = env;
io = ccc_env_thread_io(env);
io->ci_obj = ll_i2info(inode)->lli_clob;
LASSERT(io->ci_obj != NULL);
fio = &io->u.ci_fault;
fio->ft_index = index;
fio->ft_executable = vma->vm_flags&VM_EXEC;
if (ra_flags != NULL)
*ra_flags = vma->vm_flags & (VM_RAND_READ|VM_SEQ_READ);
vma->vm_flags &= ~VM_SEQ_READ;
vma->vm_flags |= VM_RAND_READ;
CDEBUG(D_MMAP, "vm_flags: %lx (%lu %d)\n", vma->vm_flags,
fio->ft_index, fio->ft_executable);
rc = cl_io_init(env, io, CIT_FAULT, io->ci_obj);
if (rc == 0) {
struct ccc_io *cio = ccc_env_io(env);
struct ll_file_data *fd = LUSTRE_FPRIVATE(file);
LASSERT(cio->cui_cl.cis_io == io);
io->ci_lockreq = CILR_MANDATORY;
cio->cui_fd = fd;
} else {
LASSERT(rc < 0);
cl_io_fini(env, io);
cl_env_nested_put(nest, env);
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
struct cl_env_nest nest;
int result;
sigset_t set;
struct inode *inode;
struct ll_inode_info *lli;
LASSERT(vmpage != NULL);
io = ll_fault_io_init(vma, &env, &nest, vmpage->index, NULL);
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
inode = ccc_object_inode(io->ci_obj);
lli = ll_i2info(inode);
down_read(&lli->lli_trunc_sem);
result = cl_io_loop(env, io);
up_read(&lli->lli_trunc_sem);
cfs_restore_sigs(set);
if (result == 0) {
struct inode *inode = file_inode(vma->vm_file);
struct ll_inode_info *lli = ll_i2info(inode);
lock_page(vmpage);
if (vmpage->mapping == NULL) {
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
if (result == 0) {
spin_lock(&lli->lli_lock);
lli->lli_flags |= LLIF_DATA_MODIFIED;
spin_unlock(&lli->lli_lock);
}
}
out_io:
cl_io_fini(env, io);
cl_env_nested_put(&nest, env);
out:
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
struct cl_env_nest nest;
int result;
int fault_ret = 0;
io = ll_fault_io_init(vma, &env, &nest, vmf->pgoff, &ra_flags);
if (IS_ERR(io))
return to_fault_error(PTR_ERR(io));
result = io->ci_result;
if (result == 0) {
vio = vvp_env_io(env);
vio->u.fault.ft_vma = vma;
vio->u.fault.ft_vmpage = NULL;
vio->u.fault.fault.ft_vmf = vmf;
vio->u.fault.fault.ft_flags = 0;
vio->u.fault.fault.ft_flags_valid = false;
result = cl_io_loop(env, io);
if (vio->u.fault.fault.ft_flags_valid)
fault_ret = vio->u.fault.fault.ft_flags;
vmpage = vio->u.fault.ft_vmpage;
if (result != 0 && vmpage != NULL) {
page_cache_release(vmpage);
vmf->page = NULL;
}
}
cl_io_fini(env, io);
cl_env_nested_put(&nest, env);
vma->vm_flags |= ra_flags;
if (result != 0 && !(fault_ret & VM_FAULT_RETRY))
fault_ret |= to_fault_error(result);
CDEBUG(D_MMAP, "%s fault %d/%d\n",
current->comm, fault_ret, result);
return fault_ret;
}
static int ll_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
int count = 0;
bool printed = false;
int result;
sigset_t set;
set = cfs_block_sigsinv(sigmask(SIGKILL) | sigmask(SIGTERM));
restart:
result = ll_fault0(vma, vmf);
LASSERT(!(result & VM_FAULT_LOCKED));
if (result == 0) {
struct page *vmpage = vmf->page;
lock_page(vmpage);
if (unlikely(vmpage->mapping == NULL)) {
unlock_page(vmpage);
page_cache_release(vmpage);
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
static int ll_page_mkwrite(struct vm_area_struct *vma, struct vm_fault *vmf)
{
int count = 0;
bool printed = false;
bool retry;
int result;
do {
retry = false;
result = ll_page_mkwrite0(vma, vmf->page, &retry);
if (!printed && ++count > 16) {
CWARN("app(%s): the page %lu of file %lu is under heavy contention.\n",
current->comm, vmf->pgoff,
file_inode(vma->vm_file)->i_ino);
printed = true;
}
} while (retry);
switch (result) {
case 0:
LASSERT(PageLocked(vmf->page));
result = VM_FAULT_LOCKED;
break;
case -ENODATA:
case -EFAULT:
result = VM_FAULT_NOPAGE;
break;
case -ENOMEM:
result = VM_FAULT_OOM;
break;
case -EAGAIN:
result = VM_FAULT_RETRY;
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
struct ccc_object *vob = cl_inode2ccc(inode);
LASSERT(vma->vm_file);
LASSERT(atomic_read(&vob->cob_mmap_cnt) >= 0);
atomic_inc(&vob->cob_mmap_cnt);
}
static void ll_vm_close(struct vm_area_struct *vma)
{
struct inode *inode = file_inode(vma->vm_file);
struct ccc_object *vob = cl_inode2ccc(inode);
LASSERT(vma->vm_file);
atomic_dec(&vob->cob_mmap_cnt);
LASSERT(atomic_read(&vob->cob_mmap_cnt) >= 0);
}
int ll_teardown_mmaps(struct address_space *mapping, __u64 first, __u64 last)
{
int rc = -ENOENT;
LASSERTF(last > first, "last %llu first %llu\n", last, first);
if (mapping_mapped(mapping)) {
rc = 0;
unmap_mapping_range(mapping, first + PAGE_CACHE_SIZE - 1,
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
