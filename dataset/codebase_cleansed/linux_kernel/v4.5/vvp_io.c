int cl_is_normalio(const struct lu_env *env, const struct cl_io *io)
{
struct vvp_io *vio = vvp_env_io(env);
LASSERT(io->ci_type == CIT_READ || io->ci_type == CIT_WRITE);
return vio->cui_io_subtype == IO_NORMAL;
}
static bool can_populate_pages(const struct lu_env *env, struct cl_io *io,
struct inode *inode)
{
struct ll_inode_info *lli = ll_i2info(inode);
struct ccc_io *cio = ccc_env_io(env);
bool rc = true;
switch (io->ci_type) {
case CIT_READ:
case CIT_WRITE:
if (ll_layout_version_get(lli) != cio->cui_layout_gen) {
io->ci_need_restart = 1;
io->ci_continue = 0;
rc = false;
}
case CIT_FAULT:
default:
break;
}
return rc;
}
static int vvp_io_fault_iter_init(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct vvp_io *vio = cl2vvp_io(env, ios);
struct inode *inode = ccc_object_inode(ios->cis_obj);
LASSERT(inode ==
file_inode(cl2ccc_io(env, ios)->cui_fd->fd_file));
vio->u.fault.ft_mtime = inode->i_mtime.tv_sec;
return 0;
}
static void vvp_io_fini(const struct lu_env *env, const struct cl_io_slice *ios)
{
struct cl_io *io = ios->cis_io;
struct cl_object *obj = io->ci_obj;
struct ccc_io *cio = cl2ccc_io(env, ios);
CLOBINVRNT(env, obj, ccc_object_invariant(obj));
CDEBUG(D_VFSTRACE, DFID
" ignore/verify layout %d/%d, layout version %d restore needed %d\n",
PFID(lu_object_fid(&obj->co_lu)),
io->ci_ignore_layout, io->ci_verify_layout,
cio->cui_layout_gen, io->ci_restore_needed);
if (io->ci_restore_needed == 1) {
int rc;
rc = ll_layout_restore(ccc_object_inode(obj));
if (rc == 0) {
io->ci_restore_needed = 0;
io->ci_need_restart = 1;
io->ci_verify_layout = 1;
} else {
io->ci_restore_needed = 1;
io->ci_need_restart = 0;
io->ci_verify_layout = 0;
io->ci_result = rc;
}
}
if (!io->ci_ignore_layout && io->ci_verify_layout) {
__u32 gen = 0;
ll_layout_refresh(ccc_object_inode(obj), &gen);
io->ci_need_restart = cio->cui_layout_gen != gen;
if (io->ci_need_restart) {
CDEBUG(D_VFSTRACE,
DFID" layout changed from %d to %d.\n",
PFID(lu_object_fid(&obj->co_lu)),
cio->cui_layout_gen, gen);
ll_i2info(ccc_object_inode(obj))->lli_flags &=
~LLIF_FILE_RESTORING;
}
}
}
static void vvp_io_fault_fini(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct cl_io *io = ios->cis_io;
struct cl_page *page = io->u.ci_fault.ft_page;
CLOBINVRNT(env, io->ci_obj, ccc_object_invariant(io->ci_obj));
if (page != NULL) {
lu_ref_del(&page->cp_reference, "fault", io);
cl_page_put(env, page);
io->u.ci_fault.ft_page = NULL;
}
vvp_io_fini(env, ios);
}
static enum cl_lock_mode vvp_mode_from_vma(struct vm_area_struct *vma)
{
if ((vma->vm_flags & VM_SHARED) && (vma->vm_flags & VM_WRITE))
return CLM_WRITE;
return CLM_READ;
}
static int vvp_mmap_locks(const struct lu_env *env,
struct ccc_io *vio, struct cl_io *io)
{
struct ccc_thread_info *cti = ccc_env_info(env);
struct mm_struct *mm = current->mm;
struct vm_area_struct *vma;
struct cl_lock_descr *descr = &cti->cti_descr;
ldlm_policy_data_t policy;
unsigned long addr;
ssize_t count;
int result;
struct iov_iter i;
struct iovec iov;
LASSERT(io->ci_type == CIT_READ || io->ci_type == CIT_WRITE);
if (!cl_is_normalio(env, io))
return 0;
if (vio->cui_iter == NULL)
return 0;
if (mm == NULL)
return 0;
iov_for_each(iov, i, *(vio->cui_iter)) {
addr = (unsigned long)iov.iov_base;
count = iov.iov_len;
if (count == 0)
continue;
count += addr & (~CFS_PAGE_MASK);
addr &= CFS_PAGE_MASK;
down_read(&mm->mmap_sem);
while ((vma = our_vma(mm, addr, count)) != NULL) {
struct inode *inode = file_inode(vma->vm_file);
int flags = CEF_MUST;
if (ll_file_nolock(vma->vm_file)) {
flags = CEF_NEVER;
}
policy_from_vma(&policy, vma, addr, count);
descr->cld_mode = vvp_mode_from_vma(vma);
descr->cld_obj = ll_i2info(inode)->lli_clob;
descr->cld_start = cl_index(descr->cld_obj,
policy.l_extent.start);
descr->cld_end = cl_index(descr->cld_obj,
policy.l_extent.end);
descr->cld_enq_flags = flags;
result = cl_io_lock_alloc_add(env, io, descr);
CDEBUG(D_VFSTRACE, "lock: %d: [%lu, %lu]\n",
descr->cld_mode, descr->cld_start,
descr->cld_end);
if (result < 0) {
up_read(&mm->mmap_sem);
return result;
}
if (vma->vm_end - addr >= count)
break;
count -= vma->vm_end - addr;
addr = vma->vm_end;
}
up_read(&mm->mmap_sem);
}
return 0;
}
static int vvp_io_rw_lock(const struct lu_env *env, struct cl_io *io,
enum cl_lock_mode mode, loff_t start, loff_t end)
{
struct ccc_io *cio = ccc_env_io(env);
int result;
int ast_flags = 0;
LASSERT(io->ci_type == CIT_READ || io->ci_type == CIT_WRITE);
ccc_io_update_iov(env, cio, io);
if (io->u.ci_rw.crw_nonblock)
ast_flags |= CEF_NONBLOCK;
result = vvp_mmap_locks(env, cio, io);
if (result == 0)
result = ccc_io_one_lock(env, io, ast_flags, mode, start, end);
return result;
}
static int vvp_io_read_lock(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct cl_io *io = ios->cis_io;
struct cl_io_rw_common *rd = &io->u.ci_rd.rd;
int result;
result = vvp_io_rw_lock(env, io, CLM_READ, rd->crw_pos,
rd->crw_pos + rd->crw_count - 1);
return result;
}
static int vvp_io_fault_lock(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct cl_io *io = ios->cis_io;
struct vvp_io *vio = cl2vvp_io(env, ios);
return ccc_io_one_lock_index
(env, io, 0, vvp_mode_from_vma(vio->u.fault.ft_vma),
io->u.ci_fault.ft_index, io->u.ci_fault.ft_index);
}
static int vvp_io_write_lock(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct cl_io *io = ios->cis_io;
loff_t start;
loff_t end;
if (io->u.ci_wr.wr_append) {
start = 0;
end = OBD_OBJECT_EOF;
} else {
start = io->u.ci_wr.wr.crw_pos;
end = start + io->u.ci_wr.wr.crw_count - 1;
}
return vvp_io_rw_lock(env, io, CLM_WRITE, start, end);
}
static int vvp_io_setattr_iter_init(const struct lu_env *env,
const struct cl_io_slice *ios)
{
return 0;
}
static int vvp_io_setattr_lock(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct ccc_io *cio = ccc_env_io(env);
struct cl_io *io = ios->cis_io;
__u64 new_size;
__u32 enqflags = 0;
if (cl_io_is_trunc(io)) {
new_size = io->u.ci_setattr.sa_attr.lvb_size;
if (new_size == 0)
enqflags = CEF_DISCARD_DATA;
} else {
if ((io->u.ci_setattr.sa_attr.lvb_mtime >=
io->u.ci_setattr.sa_attr.lvb_ctime) ||
(io->u.ci_setattr.sa_attr.lvb_atime >=
io->u.ci_setattr.sa_attr.lvb_ctime))
return 0;
new_size = 0;
}
cio->u.setattr.cui_local_lock = SETATTR_EXTENT_LOCK;
return ccc_io_one_lock(env, io, enqflags, CLM_WRITE,
new_size, OBD_OBJECT_EOF);
}
static int vvp_do_vmtruncate(struct inode *inode, size_t size)
{
int result;
ll_inode_size_lock(inode);
result = inode_newsize_ok(inode, size);
if (result < 0) {
ll_inode_size_unlock(inode);
return result;
}
truncate_setsize(inode, size);
ll_inode_size_unlock(inode);
return result;
}
static int vvp_io_setattr_trunc(const struct lu_env *env,
const struct cl_io_slice *ios,
struct inode *inode, loff_t size)
{
inode_dio_wait(inode);
return 0;
}
static int vvp_io_setattr_time(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct cl_io *io = ios->cis_io;
struct cl_object *obj = io->ci_obj;
struct cl_attr *attr = ccc_env_thread_attr(env);
int result;
unsigned valid = CAT_CTIME;
cl_object_attr_lock(obj);
attr->cat_ctime = io->u.ci_setattr.sa_attr.lvb_ctime;
if (io->u.ci_setattr.sa_valid & ATTR_ATIME_SET) {
attr->cat_atime = io->u.ci_setattr.sa_attr.lvb_atime;
valid |= CAT_ATIME;
}
if (io->u.ci_setattr.sa_valid & ATTR_MTIME_SET) {
attr->cat_mtime = io->u.ci_setattr.sa_attr.lvb_mtime;
valid |= CAT_MTIME;
}
result = cl_object_attr_set(env, obj, attr, valid);
cl_object_attr_unlock(obj);
return result;
}
static int vvp_io_setattr_start(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct cl_io *io = ios->cis_io;
struct inode *inode = ccc_object_inode(io->ci_obj);
int result = 0;
inode_lock(inode);
if (cl_io_is_trunc(io))
result = vvp_io_setattr_trunc(env, ios, inode,
io->u.ci_setattr.sa_attr.lvb_size);
if (result == 0)
result = vvp_io_setattr_time(env, ios);
return result;
}
static void vvp_io_setattr_end(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct cl_io *io = ios->cis_io;
struct inode *inode = ccc_object_inode(io->ci_obj);
if (cl_io_is_trunc(io))
vvp_do_vmtruncate(inode, io->u.ci_setattr.sa_attr.lvb_size);
inode_unlock(inode);
}
static void vvp_io_setattr_fini(const struct lu_env *env,
const struct cl_io_slice *ios)
{
vvp_io_fini(env, ios);
}
static int vvp_io_read_start(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct vvp_io *vio = cl2vvp_io(env, ios);
struct ccc_io *cio = cl2ccc_io(env, ios);
struct cl_io *io = ios->cis_io;
struct cl_object *obj = io->ci_obj;
struct inode *inode = ccc_object_inode(obj);
struct ll_ra_read *bead = &vio->cui_bead;
struct file *file = cio->cui_fd->fd_file;
int result;
loff_t pos = io->u.ci_rd.rd.crw_pos;
long cnt = io->u.ci_rd.rd.crw_count;
long tot = cio->cui_tot_count;
int exceed = 0;
CLOBINVRNT(env, obj, ccc_object_invariant(obj));
CDEBUG(D_VFSTRACE, "read: -> [%lli, %lli)\n", pos, pos + cnt);
if (!can_populate_pages(env, io, inode))
return 0;
result = ccc_prep_size(env, obj, io, pos, tot, &exceed);
if (result != 0)
return result;
else if (exceed != 0)
goto out;
LU_OBJECT_HEADER(D_INODE, env, &obj->co_lu,
"Read ino %lu, %lu bytes, offset %lld, size %llu\n",
inode->i_ino, cnt, pos, i_size_read(inode));
cio->cui_fd->fd_file->f_ra.ra_pages = 0;
if (!vio->cui_ra_window_set) {
vio->cui_ra_window_set = 1;
bead->lrr_start = cl_index(obj, pos);
bead->lrr_count = cl_index(obj, tot + PAGE_CACHE_SIZE - 1);
ll_ra_read_in(file, bead);
}
file_accessed(file);
switch (vio->cui_io_subtype) {
case IO_NORMAL:
LASSERT(cio->cui_iocb->ki_pos == pos);
result = generic_file_read_iter(cio->cui_iocb, cio->cui_iter);
break;
case IO_SPLICE:
result = generic_file_splice_read(file, &pos,
vio->u.splice.cui_pipe, cnt,
vio->u.splice.cui_flags);
io->ci_continue = 0;
break;
default:
CERROR("Wrong IO type %u\n", vio->cui_io_subtype);
LBUG();
}
out:
if (result >= 0) {
if (result < cnt)
io->ci_continue = 0;
io->ci_nob += result;
ll_rw_stats_tally(ll_i2sbi(inode), current->pid,
cio->cui_fd, pos, result, READ);
result = 0;
}
return result;
}
static void vvp_io_read_fini(const struct lu_env *env, const struct cl_io_slice *ios)
{
struct vvp_io *vio = cl2vvp_io(env, ios);
struct ccc_io *cio = cl2ccc_io(env, ios);
if (vio->cui_ra_window_set)
ll_ra_read_ex(cio->cui_fd->fd_file, &vio->cui_bead);
vvp_io_fini(env, ios);
}
static int vvp_io_write_start(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct ccc_io *cio = cl2ccc_io(env, ios);
struct cl_io *io = ios->cis_io;
struct cl_object *obj = io->ci_obj;
struct inode *inode = ccc_object_inode(obj);
ssize_t result = 0;
loff_t pos = io->u.ci_wr.wr.crw_pos;
size_t cnt = io->u.ci_wr.wr.crw_count;
if (!can_populate_pages(env, io, inode))
return 0;
if (cl_io_is_append(io)) {
pos = io->u.ci_wr.wr.crw_pos = i_size_read(inode);
cio->cui_iocb->ki_pos = pos;
} else {
LASSERT(cio->cui_iocb->ki_pos == pos);
}
CDEBUG(D_VFSTRACE, "write: [%lli, %lli)\n", pos, pos + (long long)cnt);
if (cio->cui_iter == NULL)
result = 0;
else
result = generic_file_write_iter(cio->cui_iocb, cio->cui_iter);
if (result > 0) {
if (result < cnt)
io->ci_continue = 0;
io->ci_nob += result;
ll_rw_stats_tally(ll_i2sbi(inode), current->pid,
cio->cui_fd, pos, result, WRITE);
result = 0;
}
return result;
}
static int vvp_io_kernel_fault(struct vvp_fault_io *cfio)
{
struct vm_fault *vmf = cfio->fault.ft_vmf;
cfio->fault.ft_flags = filemap_fault(cfio->ft_vma, vmf);
cfio->fault.ft_flags_valid = 1;
if (vmf->page) {
CDEBUG(D_PAGE,
"page %p map %p index %lu flags %lx count %u priv %0lx: got addr %p type NOPAGE\n",
vmf->page, vmf->page->mapping, vmf->page->index,
(long)vmf->page->flags, page_count(vmf->page),
page_private(vmf->page), vmf->virtual_address);
if (unlikely(!(cfio->fault.ft_flags & VM_FAULT_LOCKED))) {
lock_page(vmf->page);
cfio->fault.ft_flags |= VM_FAULT_LOCKED;
}
cfio->ft_vmpage = vmf->page;
return 0;
}
if (cfio->fault.ft_flags & (VM_FAULT_SIGBUS | VM_FAULT_SIGSEGV)) {
CDEBUG(D_PAGE, "got addr %p - SIGBUS\n", vmf->virtual_address);
return -EFAULT;
}
if (cfio->fault.ft_flags & VM_FAULT_OOM) {
CDEBUG(D_PAGE, "got addr %p - OOM\n", vmf->virtual_address);
return -ENOMEM;
}
if (cfio->fault.ft_flags & VM_FAULT_RETRY)
return -EAGAIN;
CERROR("Unknown error in page fault %d!\n", cfio->fault.ft_flags);
return -EINVAL;
}
static int vvp_io_fault_start(const struct lu_env *env,
const struct cl_io_slice *ios)
{
struct vvp_io *vio = cl2vvp_io(env, ios);
struct cl_io *io = ios->cis_io;
struct cl_object *obj = io->ci_obj;
struct inode *inode = ccc_object_inode(obj);
struct cl_fault_io *fio = &io->u.ci_fault;
struct vvp_fault_io *cfio = &vio->u.fault;
loff_t offset;
int result = 0;
struct page *vmpage = NULL;
struct cl_page *page;
loff_t size;
pgoff_t last;
if (fio->ft_executable &&
inode->i_mtime.tv_sec != vio->u.fault.ft_mtime)
CWARN("binary "DFID
" changed while waiting for the page fault lock\n",
PFID(lu_object_fid(&obj->co_lu)));
offset = cl_offset(obj, fio->ft_index + 1) - 1;
LASSERT(cl_index(obj, offset) == fio->ft_index);
result = ccc_prep_size(env, obj, io, 0, offset + 1, NULL);
if (result != 0)
return result;
if (fio->ft_mkwrite) {
LASSERT(cfio->ft_vmpage != NULL);
lock_page(cfio->ft_vmpage);
} else {
result = vvp_io_kernel_fault(cfio);
if (result != 0)
return result;
}
vmpage = cfio->ft_vmpage;
LASSERT(PageLocked(vmpage));
if (OBD_FAIL_CHECK(OBD_FAIL_LLITE_FAULT_TRUNC_RACE))
ll_invalidate_page(vmpage);
size = i_size_read(inode);
if (unlikely((vmpage->mapping != inode->i_mapping) ||
(page_offset(vmpage) > size))) {
CDEBUG(D_PAGE, "llite: fault and truncate race happened!\n");
result = 1;
goto out;
}
if (fio->ft_mkwrite) {
pgoff_t last_index;
last_index = cl_index(obj, size - 1);
if (last_index < fio->ft_index) {
CDEBUG(D_PAGE,
"llite: mkwrite and truncate race happened: %p: 0x%lx 0x%lx\n",
vmpage->mapping, fio->ft_index, last_index);
result = -ENODATA;
goto out;
}
}
page = cl_page_find(env, obj, fio->ft_index, vmpage, CPT_CACHEABLE);
if (IS_ERR(page)) {
result = PTR_ERR(page);
goto out;
}
if (fio->ft_mkwrite) {
wait_on_page_writeback(vmpage);
if (set_page_dirty(vmpage)) {
struct ccc_page *cp;
cl_page_assume(env, io, page);
cp = cl2ccc_page(cl_page_at(page, &vvp_device_type));
vvp_write_pending(cl2ccc(obj), cp);
result = cl_page_cache_add(env, io, page, CRT_WRITE);
LASSERT(cl_page_is_owned(page, io));
vmpage = NULL;
if (result < 0) {
cl_page_unmap(env, io, page);
cl_page_discard(env, io, page);
cl_page_disown(env, io, page);
cl_page_put(env, page);
if (result == -EDQUOT)
result = -ENOSPC;
goto out;
} else
cl_page_disown(env, io, page);
}
}
last = cl_index(obj, size - 1);
LASSERT(!fio->ft_mkwrite || fio->ft_index <= last);
if (fio->ft_index == last)
fio->ft_nob = size - cl_offset(obj, fio->ft_index);
else
fio->ft_nob = cl_page_size(obj);
lu_ref_add(&page->cp_reference, "fault", io);
fio->ft_page = page;
out:
if (vmpage != NULL)
unlock_page(vmpage);
cfio->fault.ft_flags &= ~VM_FAULT_LOCKED;
return result;
}
static int vvp_io_fsync_start(const struct lu_env *env,
const struct cl_io_slice *ios)
{
return 0;
}
static int vvp_io_read_page(const struct lu_env *env,
const struct cl_io_slice *ios,
const struct cl_page_slice *slice)
{
struct cl_io *io = ios->cis_io;
struct cl_object *obj = slice->cpl_obj;
struct ccc_page *cp = cl2ccc_page(slice);
struct cl_page *page = slice->cpl_page;
struct inode *inode = ccc_object_inode(obj);
struct ll_sb_info *sbi = ll_i2sbi(inode);
struct ll_file_data *fd = cl2ccc_io(env, ios)->cui_fd;
struct ll_readahead_state *ras = &fd->fd_ras;
struct page *vmpage = cp->cpg_page;
struct cl_2queue *queue = &io->ci_queue;
int rc;
CLOBINVRNT(env, obj, ccc_object_invariant(obj));
LASSERT(slice->cpl_obj == obj);
if (sbi->ll_ra_info.ra_max_pages_per_file &&
sbi->ll_ra_info.ra_max_pages)
ras_update(sbi, inode, ras, page->cp_index,
cp->cpg_defer_uptodate);
rc = cl_page_is_under_lock(env, io, page);
if (rc != -EBUSY) {
CL_PAGE_HEADER(D_WARNING, env, page, "%s: %d\n",
rc == -ENODATA ? "without a lock" :
"match failed", rc);
if (rc != -ENODATA)
return rc;
}
if (cp->cpg_defer_uptodate) {
cp->cpg_ra_used = 1;
cl_page_export(env, page, 1);
}
cl_page_list_add(&queue->c2_qin, page);
if (sbi->ll_ra_info.ra_max_pages_per_file &&
sbi->ll_ra_info.ra_max_pages)
ll_readahead(env, io, ras,
vmpage->mapping, &queue->c2_qin, fd->fd_flags);
return 0;
}
static int vvp_page_sync_io(const struct lu_env *env, struct cl_io *io,
struct cl_page *page, struct ccc_page *cp,
enum cl_req_type crt)
{
struct cl_2queue *queue;
int result;
LASSERT(io->ci_type == CIT_READ || io->ci_type == CIT_WRITE);
queue = &io->ci_queue;
cl_2queue_init_page(queue, page);
result = cl_io_submit_sync(env, io, crt, queue, 0);
LASSERT(cl_page_is_owned(page, io));
if (crt == CRT_READ)
cl_page_list_disown(env, io, &queue->c2_qin);
cl_2queue_fini(env, queue);
return result;
}
static int vvp_io_prepare_partial(const struct lu_env *env, struct cl_io *io,
struct cl_object *obj, struct cl_page *pg,
struct ccc_page *cp,
unsigned from, unsigned to)
{
struct cl_attr *attr = ccc_env_thread_attr(env);
loff_t offset = cl_offset(obj, pg->cp_index);
int result;
cl_object_attr_lock(obj);
result = cl_object_attr_get(env, obj, attr);
cl_object_attr_unlock(obj);
if (result == 0) {
if (attr->cat_kms <= offset) {
char *kaddr = kmap_atomic(cp->cpg_page);
memset(kaddr, 0, cl_page_size(obj));
kunmap_atomic(kaddr);
} else if (cp->cpg_defer_uptodate)
cp->cpg_ra_used = 1;
else
result = vvp_page_sync_io(env, io, pg, cp, CRT_READ);
if (result == 0)
cl_page_export(env, pg, 1);
}
return result;
}
static int vvp_io_prepare_write(const struct lu_env *env,
const struct cl_io_slice *ios,
const struct cl_page_slice *slice,
unsigned from, unsigned to)
{
struct cl_object *obj = slice->cpl_obj;
struct ccc_page *cp = cl2ccc_page(slice);
struct cl_page *pg = slice->cpl_page;
struct page *vmpage = cp->cpg_page;
int result;
LINVRNT(cl_page_is_vmlocked(env, pg));
LASSERT(vmpage->mapping->host == ccc_object_inode(obj));
result = 0;
CL_PAGE_HEADER(D_PAGE, env, pg, "preparing: [%d, %d]\n", from, to);
if (!PageUptodate(vmpage)) {
if (from == 0 && to == PAGE_CACHE_SIZE) {
CL_PAGE_HEADER(D_PAGE, env, pg, "full page write\n");
POISON_PAGE(page, 0x11);
} else
result = vvp_io_prepare_partial(env, ios->cis_io, obj,
pg, cp, from, to);
} else
CL_PAGE_HEADER(D_PAGE, env, pg, "uptodate\n");
return result;
}
static int vvp_io_commit_write(const struct lu_env *env,
const struct cl_io_slice *ios,
const struct cl_page_slice *slice,
unsigned from, unsigned to)
{
struct cl_object *obj = slice->cpl_obj;
struct cl_io *io = ios->cis_io;
struct ccc_page *cp = cl2ccc_page(slice);
struct cl_page *pg = slice->cpl_page;
struct inode *inode = ccc_object_inode(obj);
struct ll_sb_info *sbi = ll_i2sbi(inode);
struct ll_inode_info *lli = ll_i2info(inode);
struct page *vmpage = cp->cpg_page;
int result;
int tallyop;
loff_t size;
LINVRNT(cl_page_is_vmlocked(env, pg));
LASSERT(vmpage->mapping->host == inode);
LU_OBJECT_HEADER(D_INODE, env, &obj->co_lu, "committing page write\n");
CL_PAGE_HEADER(D_PAGE, env, pg, "committing: [%d, %d]\n", from, to);
if (!PageDirty(vmpage)) {
tallyop = LPROC_LL_DIRTY_MISSES;
result = cl_page_cache_add(env, io, pg, CRT_WRITE);
if (result == 0) {
set_page_dirty(vmpage);
vvp_write_pending(cl2ccc(obj), cp);
} else if (result == -EDQUOT) {
pgoff_t last_index = i_size_read(inode) >> PAGE_CACHE_SHIFT;
bool need_clip = true;
if (last_index > pg->cp_index) {
to = PAGE_CACHE_SIZE;
need_clip = false;
} else if (last_index == pg->cp_index) {
int size_to = i_size_read(inode) & ~CFS_PAGE_MASK;
if (to < size_to)
to = size_to;
}
if (need_clip)
cl_page_clip(env, pg, 0, to);
result = vvp_page_sync_io(env, io, pg, cp, CRT_WRITE);
if (result)
CERROR("Write page %lu of inode %p failed %d\n",
pg->cp_index, inode, result);
}
} else {
tallyop = LPROC_LL_DIRTY_HITS;
result = 0;
}
ll_stats_ops_tally(sbi, tallyop, 1);
if (result == 0) {
spin_lock(&lli->lli_lock);
lli->lli_flags |= LLIF_DATA_MODIFIED;
spin_unlock(&lli->lli_lock);
}
size = cl_offset(obj, pg->cp_index) + to;
ll_inode_size_lock(inode);
if (result == 0) {
if (size > i_size_read(inode)) {
cl_isize_write_nolock(inode, size);
CDEBUG(D_VFSTRACE, DFID" updating i_size %lu\n",
PFID(lu_object_fid(&obj->co_lu)),
(unsigned long)size);
}
cl_page_export(env, pg, 1);
} else {
if (size > i_size_read(inode))
cl_page_discard(env, io, pg);
}
ll_inode_size_unlock(inode);
return result;
}
int vvp_io_init(const struct lu_env *env, struct cl_object *obj,
struct cl_io *io)
{
struct vvp_io *vio = vvp_env_io(env);
struct ccc_io *cio = ccc_env_io(env);
struct inode *inode = ccc_object_inode(obj);
int result;
CLOBINVRNT(env, obj, ccc_object_invariant(obj));
CDEBUG(D_VFSTRACE, DFID
" ignore/verify layout %d/%d, layout version %d restore needed %d\n",
PFID(lu_object_fid(&obj->co_lu)),
io->ci_ignore_layout, io->ci_verify_layout,
cio->cui_layout_gen, io->ci_restore_needed);
CL_IO_SLICE_CLEAN(cio, cui_cl);
cl_io_slice_add(io, &cio->cui_cl, obj, &vvp_io_ops);
vio->cui_ra_window_set = 0;
result = 0;
if (io->ci_type == CIT_READ || io->ci_type == CIT_WRITE) {
size_t count;
struct ll_inode_info *lli = ll_i2info(inode);
count = io->u.ci_rw.crw_count;
if (count == 0)
result = 1;
else
cio->cui_tot_count = count;
lustre_get_jobid(lli->lli_jobid);
} else if (io->ci_type == CIT_SETATTR) {
if (!cl_io_is_trunc(io))
io->ci_lockreq = CILR_MANDATORY;
}
if (io->ci_type == CIT_MISC && !io->ci_verify_layout)
io->ci_ignore_layout = 1;
if (result == 0 && !io->ci_ignore_layout) {
result = ll_layout_refresh(inode, &cio->cui_layout_gen);
if (result == -ENOENT)
result = 0;
if (result < 0)
CERROR("%s: refresh file layout " DFID " error %d.\n",
ll_get_fsname(inode->i_sb, NULL, 0),
PFID(lu_object_fid(&obj->co_lu)), result);
}
return result;
}
static struct vvp_io *cl2vvp_io(const struct lu_env *env,
const struct cl_io_slice *slice)
{
cl2ccc_io(env, slice);
return vvp_env_io(env);
}
