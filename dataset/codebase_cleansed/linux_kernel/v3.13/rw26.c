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
if (offset == 0 && length == PAGE_CACHE_SIZE) {
env = cl_env_get(&refcheck);
if (!IS_ERR(env)) {
inode = vmpage->mapping->host;
obj = ll_i2info(inode)->lli_clob;
if (obj != NULL) {
page = cl_vmpage_page(vmpage, obj);
if (page != NULL) {
lu_ref_add(&page->cp_reference,
"delete", vmpage);
cl_page_delete(env, page);
lu_ref_del(&page->cp_reference,
"delete", vmpage);
cl_page_put(env, page);
}
} else
LASSERT(vmpage->private == 0);
cl_env_put(env, &refcheck);
}
}
}
static int ll_releasepage(struct page *vmpage, RELEASEPAGE_ARG_TYPE gfp_mask)
{
struct cl_env_nest nest;
struct lu_env *env;
struct cl_object *obj;
struct cl_page *page;
struct address_space *mapping;
int result;
LASSERT(PageLocked(vmpage));
if (PageWriteback(vmpage) || PageDirty(vmpage))
return 0;
mapping = vmpage->mapping;
if (mapping == NULL)
return 1;
obj = ll_i2info(mapping->host)->lli_clob;
if (obj == NULL)
return 1;
if (page_count(vmpage) > 3)
return 0;
env = cl_env_nested_get(&nest);
if (IS_ERR(env))
return 0;
page = cl_vmpage_page(vmpage, obj);
result = page == NULL;
if (page != NULL) {
if (!cl_page_in_use(page)) {
result = 1;
cl_page_delete(env, page);
}
cl_page_put(env, page);
}
cl_env_nested_put(&nest, env);
return result;
}
static int ll_set_page_dirty(struct page *vmpage)
{
#if 0
struct cl_page *page = vvp_vmpage_page_transient(vmpage);
struct vvp_object *obj = cl_inode2vvp(vmpage->mapping->host);
struct vvp_page *cpg;
LASSERT(&obj->co_cl == page->cp_obj);
cpg = cl2vvp_page(cl_page_at(page, &vvp_device_type));
vvp_write_pending(obj, cpg);
#endif
return __set_page_dirty_nobuffers(vmpage);
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
*max_pages = (user_addr + size + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;
*max_pages -= user_addr >> PAGE_CACHE_SHIFT;
OBD_ALLOC_LARGE(*pages, *max_pages * sizeof(**pages));
if (*pages) {
result = get_user_pages_fast(user_addr, *max_pages,
(rw == READ), *pages);
if (unlikely(result <= 0))
OBD_FREE_LARGE(*pages, *max_pages * sizeof(**pages));
}
return result;
}
static void ll_free_user_pages(struct page **pages, int npages, int do_dirty)
{
int i;
for (i = 0; i < npages; i++) {
if (pages[i] == NULL)
break;
if (do_dirty)
set_page_dirty_lock(pages[i]);
page_cache_release(pages[i]);
}
OBD_FREE_LARGE(pages, npages * sizeof(*pages));
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
struct page *vmpage = cl_page_vmpage(env, clp);
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
cl_2queue_add(queue, clp);
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
struct ll_dio_pages pvec = { .ldp_pages = pages,
.ldp_nr = page_count,
.ldp_size = size,
.ldp_offsets = NULL,
.ldp_start_offset = file_offset
};
return ll_direct_rw_pages(env, io, rw, inode, &pvec);
}
static ssize_t ll_direct_IO_26(int rw, struct kiocb *iocb,
const struct iovec *iov, loff_t file_offset,
unsigned long nr_segs)
{
struct lu_env *env;
struct cl_io *io;
struct file *file = iocb->ki_filp;
struct inode *inode = file->f_mapping->host;
struct ccc_object *obj = cl_inode2ccc(inode);
long count = iov_length(iov, nr_segs);
long tot_bytes = 0, result = 0;
struct ll_inode_info *lli = ll_i2info(inode);
unsigned long seg = 0;
long size = MAX_DIO_SIZE;
int refcheck;
if (!lli->lli_has_smd)
return -EBADF;
if ((file_offset & ~CFS_PAGE_MASK) || (count & ~CFS_PAGE_MASK))
return -EINVAL;
CDEBUG(D_VFSTRACE, "VFS Op:inode=%lu/%u(%p), size=%lu (max %lu), "
"offset=%lld=%llx, pages %lu (max %lu)\n",
inode->i_ino, inode->i_generation, inode, count, MAX_DIO_SIZE,
file_offset, file_offset, count >> PAGE_CACHE_SHIFT,
MAX_DIO_SIZE >> PAGE_CACHE_SHIFT);
for (seg = 0; seg < nr_segs; seg++) {
if (((unsigned long)iov[seg].iov_base & ~CFS_PAGE_MASK) ||
(iov[seg].iov_len & ~CFS_PAGE_MASK))
return -EINVAL;
}
env = cl_env_get(&refcheck);
LASSERT(!IS_ERR(env));
io = ccc_env_io(env)->cui_cl.cis_io;
LASSERT(io != NULL);
if (rw == READ)
mutex_lock(&inode->i_mutex);
LASSERT(obj->cob_transient_pages == 0);
for (seg = 0; seg < nr_segs; seg++) {
long iov_left = iov[seg].iov_len;
unsigned long user_addr = (unsigned long)iov[seg].iov_base;
if (rw == READ) {
if (file_offset >= i_size_read(inode))
break;
if (file_offset + iov_left > i_size_read(inode))
iov_left = i_size_read(inode) - file_offset;
}
while (iov_left > 0) {
struct page **pages;
int page_count, max_pages = 0;
long bytes;
bytes = min(size, iov_left);
page_count = ll_get_user_pages(rw, user_addr, bytes,
&pages, &max_pages);
if (likely(page_count > 0)) {
if (unlikely(page_count < max_pages))
bytes = page_count << PAGE_CACHE_SHIFT;
result = ll_direct_IO_26_seg(env, io, rw, inode,
file->f_mapping,
bytes, file_offset,
pages, page_count);
ll_free_user_pages(pages, max_pages, rw==READ);
} else if (page_count == 0) {
GOTO(out, result = -EFAULT);
} else {
result = page_count;
}
if (unlikely(result <= 0)) {
if (result == -ENOMEM &&
size > (PAGE_CACHE_SIZE / sizeof(*pages)) *
PAGE_CACHE_SIZE) {
size = ((((size / 2) - 1) |
~CFS_PAGE_MASK) + 1) &
CFS_PAGE_MASK;
CDEBUG(D_VFSTRACE,"DIO size now %lu\n",
size);
continue;
}
GOTO(out, result);
}
tot_bytes += result;
file_offset += result;
iov_left -= result;
user_addr += result;
}
}
out:
LASSERT(obj->cob_transient_pages == 0);
if (rw == READ)
mutex_unlock(&inode->i_mutex);
if (tot_bytes > 0) {
if (rw == WRITE) {
struct lov_stripe_md *lsm;
lsm = ccc_inode_lsm_get(inode);
LASSERT(lsm != NULL);
lov_stripe_lock(lsm);
obd_adjust_kms(ll_i2dtexp(inode), lsm, file_offset, 0);
lov_stripe_unlock(lsm);
ccc_inode_lsm_put(inode, lsm);
}
}
cl_env_put(env, &refcheck);
return tot_bytes ? : result;
}
static int ll_write_begin(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned flags,
struct page **pagep, void **fsdata)
{
pgoff_t index = pos >> PAGE_CACHE_SHIFT;
struct page *page;
int rc;
unsigned from = pos & (PAGE_CACHE_SIZE - 1);
page = grab_cache_page_write_begin(mapping, index, flags);
if (!page)
return -ENOMEM;
*pagep = page;
rc = ll_prepare_write(file, page, from, from + len);
if (rc) {
unlock_page(page);
page_cache_release(page);
}
return rc;
}
static int ll_write_end(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned copied,
struct page *page, void *fsdata)
{
unsigned from = pos & (PAGE_CACHE_SIZE - 1);
int rc;
rc = ll_commit_write(file, page, from, from + copied);
unlock_page(page);
page_cache_release(page);
return rc ?: copied;
}
int ll_migratepage(struct address_space *mapping,
struct page *newpage, struct page *page
, enum migrate_mode mode
)
{
return -EIO;
}
