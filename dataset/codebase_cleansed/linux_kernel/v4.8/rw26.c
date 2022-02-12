static void ll_invalidatepage(struct page *vmpage, unsigned int offset,
unsigned int length)
{
struct inode *inode;
struct lu_env *env;
struct cl_page *page;
struct cl_object *obj;
int refcheck;
LASSERT(PageLocked(vmpage));
LASSERT(!PageWriteback(vmpage));
if (offset == 0 && length == PAGE_SIZE) {
env = cl_env_get(&refcheck);
if (!IS_ERR(env)) {
inode = vmpage->mapping->host;
obj = ll_i2info(inode)->lli_clob;
if (obj) {
page = cl_vmpage_page(vmpage, obj);
if (page) {
cl_page_delete(env, page);
cl_page_put(env, page);
}
} else {
LASSERT(vmpage->private == 0);
}
cl_env_put(env, &refcheck);
}
}
}
static int ll_releasepage(struct page *vmpage, gfp_t gfp_mask)
{
struct lu_env *env;
void *cookie;
struct cl_object *obj;
struct cl_page *page;
struct address_space *mapping;
int result = 0;
LASSERT(PageLocked(vmpage));
if (PageWriteback(vmpage) || PageDirty(vmpage))
return 0;
mapping = vmpage->mapping;
if (!mapping)
return 1;
obj = ll_i2info(mapping->host)->lli_clob;
if (!obj)
return 1;
if (page_count(vmpage) > 3)
return 0;
page = cl_vmpage_page(vmpage, obj);
if (!page)
return 1;
cookie = cl_env_reenter();
env = cl_env_percpu_get();
LASSERT(!IS_ERR(env));
if (!cl_page_in_use(page)) {
result = 1;
cl_page_delete(env, page);
}
LASSERT(cl_object_refc(obj) > 1);
cl_page_put(env, page);
cl_env_percpu_put(env);
cl_env_reexit(cookie);
return result;
}
static inline int ll_get_user_pages(int rw, unsigned long user_addr,
size_t size, struct page ***pages,
int *max_pages)
{
int result = -ENOMEM;
if (size > MAX_DIRECTIO_SIZE) {
*pages = NULL;
return -EFBIG;
}
*max_pages = (user_addr + size + PAGE_SIZE - 1) >> PAGE_SHIFT;
*max_pages -= user_addr >> PAGE_SHIFT;
*pages = libcfs_kvzalloc(*max_pages * sizeof(**pages), GFP_NOFS);
if (*pages) {
result = get_user_pages_fast(user_addr, *max_pages,
(rw == READ), *pages);
if (unlikely(result <= 0))
kvfree(*pages);
}
return result;
}
static void ll_free_user_pages(struct page **pages, int npages, int do_dirty)
{
int i;
for (i = 0; i < npages; i++) {
if (do_dirty)
set_page_dirty_lock(pages[i]);
put_page(pages[i]);
}
kvfree(pages);
}
ssize_t ll_direct_rw_pages(const struct lu_env *env, struct cl_io *io,
int rw, struct inode *inode,
struct ll_dio_pages *pv)
{
struct cl_page *clp;
struct cl_2queue *queue;
struct cl_object *obj = io->ci_obj;
int i;
ssize_t rc = 0;
loff_t file_offset = pv->ldp_start_offset;
long size = pv->ldp_size;
int page_count = pv->ldp_nr;
struct page **pages = pv->ldp_pages;
long page_size = cl_page_size(obj);
bool do_io;
int io_pages = 0;
queue = &io->ci_queue;
cl_2queue_init(queue);
for (i = 0; i < page_count; i++) {
if (pv->ldp_offsets)
file_offset = pv->ldp_offsets[i];
LASSERT(!(file_offset & (page_size - 1)));
clp = cl_page_find(env, obj, cl_index(obj, file_offset),
pv->ldp_pages[i], CPT_TRANSIENT);
if (IS_ERR(clp)) {
rc = PTR_ERR(clp);
break;
}
rc = cl_page_own(env, io, clp);
if (rc) {
LASSERT(clp->cp_state == CPS_FREEING);
cl_page_put(env, clp);
break;
}
do_io = true;
if (clp->cp_type == CPT_CACHEABLE) {
struct page *vmpage = cl_page_vmpage(clp);
struct page *src_page;
struct page *dst_page;
void *src;
void *dst;
src_page = (rw == WRITE) ? pages[i] : vmpage;
dst_page = (rw == WRITE) ? vmpage : pages[i];
src = kmap_atomic(src_page);
dst = kmap_atomic(dst_page);
memcpy(dst, src, min(page_size, size));
kunmap_atomic(dst);
kunmap_atomic(src);
if (rw == WRITE)
set_page_dirty(vmpage);
if (rw == READ) {
cl_page_disown(env, io, clp);
do_io = false;
}
}
if (likely(do_io)) {
cl_page_list_add(&queue->c2_qin, clp);
cl_page_clip(env, clp, 0, min(size, page_size));
++io_pages;
}
cl_page_put(env, clp);
size -= page_size;
file_offset += page_size;
}
if (rc == 0 && io_pages) {
rc = cl_io_submit_sync(env, io,
rw == READ ? CRT_READ : CRT_WRITE,
queue, 0);
}
if (rc == 0)
rc = pv->ldp_size;
cl_2queue_discard(env, io, queue);
cl_2queue_disown(env, io, queue);
cl_2queue_fini(env, queue);
return rc;
}
static ssize_t ll_direct_IO_26_seg(const struct lu_env *env, struct cl_io *io,
int rw, struct inode *inode,
struct address_space *mapping,
size_t size, loff_t file_offset,
struct page **pages, int page_count)
{
struct ll_dio_pages pvec = {
.ldp_pages = pages,
.ldp_nr = page_count,
.ldp_size = size,
.ldp_offsets = NULL,
.ldp_start_offset = file_offset
};
return ll_direct_rw_pages(env, io, rw, inode, &pvec);
}
static ssize_t ll_direct_IO_26(struct kiocb *iocb, struct iov_iter *iter)
{
struct lu_env *env;
struct cl_io *io;
struct file *file = iocb->ki_filp;
struct inode *inode = file->f_mapping->host;
struct vvp_object *obj = cl_inode2vvp(inode);
loff_t file_offset = iocb->ki_pos;
ssize_t count = iov_iter_count(iter);
ssize_t tot_bytes = 0, result = 0;
struct ll_inode_info *lli = ll_i2info(inode);
long size = MAX_DIO_SIZE;
int refcheck;
if (!lli->lli_has_smd)
return -EBADF;
if ((file_offset & ~PAGE_MASK) || (count & ~PAGE_MASK))
return -EINVAL;
CDEBUG(D_VFSTRACE, "VFS Op:inode="DFID"(%p), size=%zd (max %lu), offset=%lld=%llx, pages %zd (max %lu)\n",
PFID(ll_inode2fid(inode)), inode, count, MAX_DIO_SIZE,
file_offset, file_offset, count >> PAGE_SHIFT,
MAX_DIO_SIZE >> PAGE_SHIFT);
if (iov_iter_alignment(iter) & ~PAGE_MASK)
return -EINVAL;
env = cl_env_get(&refcheck);
LASSERT(!IS_ERR(env));
io = vvp_env_io(env)->vui_cl.cis_io;
LASSERT(io);
if (iov_iter_rw(iter) == READ)
inode_lock(inode);
LASSERT(obj->vob_transient_pages == 0);
while (iov_iter_count(iter)) {
struct page **pages;
size_t offs;
count = min_t(size_t, iov_iter_count(iter), size);
if (iov_iter_rw(iter) == READ) {
if (file_offset >= i_size_read(inode))
break;
if (file_offset + count > i_size_read(inode))
count = i_size_read(inode) - file_offset;
}
result = iov_iter_get_pages_alloc(iter, &pages, count, &offs);
if (likely(result > 0)) {
int n = DIV_ROUND_UP(result + offs, PAGE_SIZE);
result = ll_direct_IO_26_seg(env, io, iov_iter_rw(iter),
inode, file->f_mapping,
result, file_offset, pages,
n);
ll_free_user_pages(pages, n, iov_iter_rw(iter) == READ);
}
if (unlikely(result <= 0)) {
if (result == -ENOMEM &&
size > (PAGE_SIZE / sizeof(*pages)) *
PAGE_SIZE) {
size = ((((size / 2) - 1) |
~PAGE_MASK) + 1) &
PAGE_MASK;
CDEBUG(D_VFSTRACE, "DIO size now %lu\n",
size);
continue;
}
goto out;
}
iov_iter_advance(iter, result);
tot_bytes += result;
file_offset += result;
}
out:
LASSERT(obj->vob_transient_pages == 0);
if (iov_iter_rw(iter) == READ)
inode_unlock(inode);
if (tot_bytes > 0) {
struct vvp_io *vio = vvp_env_io(env);
vio->u.write.vui_written += tot_bytes;
}
cl_env_put(env, &refcheck);
return tot_bytes ? tot_bytes : result;
}
static int ll_prepare_partial_page(const struct lu_env *env, struct cl_io *io,
struct cl_page *pg)
{
struct cl_attr *attr = vvp_env_thread_attr(env);
struct cl_object *obj = io->ci_obj;
struct vvp_page *vpg = cl_object_page_slice(obj, pg);
loff_t offset = cl_offset(obj, vvp_index(vpg));
int result;
cl_object_attr_lock(obj);
result = cl_object_attr_get(env, obj, attr);
cl_object_attr_unlock(obj);
if (result == 0) {
if (attr->cat_kms <= offset) {
char *kaddr = kmap_atomic(vpg->vpg_page);
memset(kaddr, 0, cl_page_size(obj));
kunmap_atomic(kaddr);
} else if (vpg->vpg_defer_uptodate) {
vpg->vpg_ra_used = 1;
} else {
result = ll_page_sync_io(env, io, pg, CRT_READ);
}
}
return result;
}
static int ll_write_begin(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned flags,
struct page **pagep, void **fsdata)
{
struct ll_cl_context *lcc;
const struct lu_env *env;
struct cl_io *io;
struct cl_page *page;
struct cl_object *clob = ll_i2info(mapping->host)->lli_clob;
pgoff_t index = pos >> PAGE_SHIFT;
struct page *vmpage = NULL;
unsigned int from = pos & (PAGE_SIZE - 1);
unsigned int to = from + len;
int result = 0;
CDEBUG(D_VFSTRACE, "Writing %lu of %d to %d bytes\n", index, from, len);
lcc = ll_cl_find(file);
if (!lcc) {
result = -EIO;
goto out;
}
env = lcc->lcc_env;
io = lcc->lcc_io;
vmpage = grab_cache_page_nowait(mapping, index);
if (unlikely(!vmpage || PageDirty(vmpage) || PageWriteback(vmpage))) {
struct vvp_io *vio = vvp_env_io(env);
struct cl_page_list *plist = &vio->u.write.vui_queue;
if (vmpage && plist->pl_nr > 0) {
unlock_page(vmpage);
put_page(vmpage);
vmpage = NULL;
}
result = vvp_io_write_commit(env, io);
if (result < 0)
goto out;
if (!vmpage) {
vmpage = grab_cache_page_write_begin(mapping, index,
flags);
if (!vmpage) {
result = -ENOMEM;
goto out;
}
}
}
page = cl_page_find(env, clob, vmpage->index, vmpage, CPT_CACHEABLE);
if (IS_ERR(page)) {
result = PTR_ERR(page);
goto out;
}
lcc->lcc_page = page;
lu_ref_add(&page->cp_reference, "cl_io", io);
cl_page_assume(env, io, page);
if (!PageUptodate(vmpage)) {
if (from == 0 && to == PAGE_SIZE) {
CL_PAGE_HEADER(D_PAGE, env, page, "full page write\n");
POISON_PAGE(vmpage, 0x11);
} else {
result = ll_prepare_partial_page(env, io, page);
if (result == 0)
SetPageUptodate(vmpage);
}
}
if (result < 0)
cl_page_unassume(env, io, page);
out:
if (result < 0) {
if (vmpage) {
unlock_page(vmpage);
put_page(vmpage);
}
} else {
*pagep = vmpage;
*fsdata = lcc;
}
return result;
}
static int ll_write_end(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned copied,
struct page *vmpage, void *fsdata)
{
struct ll_cl_context *lcc = fsdata;
const struct lu_env *env;
struct cl_io *io;
struct vvp_io *vio;
struct cl_page *page;
unsigned from = pos & (PAGE_SIZE - 1);
bool unplug = false;
int result = 0;
put_page(vmpage);
env = lcc->lcc_env;
page = lcc->lcc_page;
io = lcc->lcc_io;
vio = vvp_env_io(env);
LASSERT(cl_page_is_owned(page, io));
if (copied > 0) {
struct cl_page_list *plist = &vio->u.write.vui_queue;
lcc->lcc_page = NULL;
cl_page_list_add(plist, page);
if (plist->pl_nr == 1)
vio->u.write.vui_from = from;
else
LASSERT(from == 0);
vio->u.write.vui_to = from + copied;
if (plist->pl_nr >= PTLRPC_MAX_BRW_PAGES)
unplug = true;
CL_PAGE_DEBUG(D_VFSTRACE, env, page,
"queued page: %d.\n", plist->pl_nr);
} else {
cl_page_disown(env, io, page);
lcc->lcc_page = NULL;
lu_ref_del(&page->cp_reference, "cl_io", io);
cl_page_put(env, page);
unplug = true;
}
if (unplug ||
file->f_flags & O_SYNC || IS_SYNC(file_inode(file)))
result = vvp_io_write_commit(env, io);
return result >= 0 ? copied : result;
}
static int ll_migratepage(struct address_space *mapping,
struct page *newpage, struct page *page,
enum migrate_mode mode
)
{
return -EIO;
}
