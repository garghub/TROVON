static void vvp_page_fini_common(struct ccc_page *cp)
{
struct page *vmpage = cp->cpg_page;
LASSERT(vmpage);
put_page(vmpage);
}
static void vvp_page_fini(const struct lu_env *env,
struct cl_page_slice *slice)
{
struct ccc_page *cp = cl2ccc_page(slice);
struct page *vmpage = cp->cpg_page;
LASSERT((struct cl_page *)vmpage->private != slice->cpl_page);
vvp_page_fini_common(cp);
}
static int vvp_page_own(const struct lu_env *env,
const struct cl_page_slice *slice, struct cl_io *io,
int nonblock)
{
struct ccc_page *vpg = cl2ccc_page(slice);
struct page *vmpage = vpg->cpg_page;
LASSERT(vmpage);
if (nonblock) {
if (!trylock_page(vmpage))
return -EAGAIN;
if (unlikely(PageWriteback(vmpage))) {
unlock_page(vmpage);
return -EAGAIN;
}
return 0;
}
lock_page(vmpage);
wait_on_page_writeback(vmpage);
return 0;
}
static void vvp_page_assume(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
struct page *vmpage = cl2vm_page(slice);
LASSERT(vmpage);
LASSERT(PageLocked(vmpage));
wait_on_page_writeback(vmpage);
}
static void vvp_page_unassume(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
struct page *vmpage = cl2vm_page(slice);
LASSERT(vmpage);
LASSERT(PageLocked(vmpage));
}
static void vvp_page_disown(const struct lu_env *env,
const struct cl_page_slice *slice, struct cl_io *io)
{
struct page *vmpage = cl2vm_page(slice);
LASSERT(vmpage);
LASSERT(PageLocked(vmpage));
unlock_page(cl2vm_page(slice));
}
static void vvp_page_discard(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
struct page *vmpage = cl2vm_page(slice);
struct address_space *mapping;
struct ccc_page *cpg = cl2ccc_page(slice);
LASSERT(vmpage);
LASSERT(PageLocked(vmpage));
mapping = vmpage->mapping;
if (cpg->cpg_defer_uptodate && !cpg->cpg_ra_used)
ll_ra_stats_inc(mapping, RA_STAT_DISCARDED);
truncate_complete_page(mapping, vmpage);
}
static int vvp_page_unmap(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
struct page *vmpage = cl2vm_page(slice);
__u64 offset;
LASSERT(vmpage);
LASSERT(PageLocked(vmpage));
offset = vmpage->index << PAGE_SHIFT;
ll_teardown_mmaps(vmpage->mapping, offset, offset + PAGE_SIZE);
return 0;
}
static void vvp_page_delete(const struct lu_env *env,
const struct cl_page_slice *slice)
{
struct page *vmpage = cl2vm_page(slice);
struct inode *inode = vmpage->mapping->host;
struct cl_object *obj = slice->cpl_obj;
LASSERT(PageLocked(vmpage));
LASSERT((struct cl_page *)vmpage->private == slice->cpl_page);
LASSERT(inode == ccc_object_inode(obj));
vvp_write_complete(cl2ccc(obj), cl2ccc_page(slice));
ClearPagePrivate(vmpage);
vmpage->private = 0;
}
static void vvp_page_export(const struct lu_env *env,
const struct cl_page_slice *slice,
int uptodate)
{
struct page *vmpage = cl2vm_page(slice);
LASSERT(vmpage);
LASSERT(PageLocked(vmpage));
if (uptodate)
SetPageUptodate(vmpage);
else
ClearPageUptodate(vmpage);
}
static int vvp_page_is_vmlocked(const struct lu_env *env,
const struct cl_page_slice *slice)
{
return PageLocked(cl2vm_page(slice)) ? -EBUSY : -ENODATA;
}
static int vvp_page_prep_read(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
return PageUptodate(cl2vm_page(slice)) ? -EALREADY : 0;
}
static int vvp_page_prep_write(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
struct page *vmpage = cl2vm_page(slice);
struct cl_page *pg = slice->cpl_page;
LASSERT(PageLocked(vmpage));
LASSERT(!PageDirty(vmpage));
if (!pg->cp_sync_io)
set_page_writeback(vmpage);
vvp_write_pending(cl2ccc(slice->cpl_obj), cl2ccc_page(slice));
return 0;
}
static void vvp_vmpage_error(struct inode *inode, struct page *vmpage, int ioret)
{
struct ccc_object *obj = cl_inode2ccc(inode);
if (ioret == 0) {
ClearPageError(vmpage);
obj->cob_discard_page_warned = 0;
} else {
SetPageError(vmpage);
if (ioret == -ENOSPC)
set_bit(AS_ENOSPC, &inode->i_mapping->flags);
else
set_bit(AS_EIO, &inode->i_mapping->flags);
if ((ioret == -ESHUTDOWN || ioret == -EINTR) &&
obj->cob_discard_page_warned == 0) {
obj->cob_discard_page_warned = 1;
ll_dirty_page_discard_warn(vmpage, ioret);
}
}
}
static void vvp_page_completion_read(const struct lu_env *env,
const struct cl_page_slice *slice,
int ioret)
{
struct ccc_page *cp = cl2ccc_page(slice);
struct page *vmpage = cp->cpg_page;
struct cl_page *page = cl_page_top(slice->cpl_page);
struct inode *inode = ccc_object_inode(page->cp_obj);
LASSERT(PageLocked(vmpage));
CL_PAGE_HEADER(D_PAGE, env, page, "completing READ with %d\n", ioret);
if (cp->cpg_defer_uptodate)
ll_ra_count_put(ll_i2sbi(inode), 1);
if (ioret == 0) {
if (!cp->cpg_defer_uptodate)
cl_page_export(env, page, 1);
} else
cp->cpg_defer_uptodate = 0;
if (!page->cp_sync_io)
unlock_page(vmpage);
}
static void vvp_page_completion_write(const struct lu_env *env,
const struct cl_page_slice *slice,
int ioret)
{
struct ccc_page *cp = cl2ccc_page(slice);
struct cl_page *pg = slice->cpl_page;
struct page *vmpage = cp->cpg_page;
CL_PAGE_HEADER(D_PAGE, env, pg, "completing WRITE with %d\n", ioret);
cp->cpg_write_queued = 0;
vvp_write_complete(cl2ccc(slice->cpl_obj), cp);
if (pg->cp_sync_io) {
LASSERT(PageLocked(vmpage));
LASSERT(!PageWriteback(vmpage));
} else {
LASSERT(PageWriteback(vmpage));
vvp_vmpage_error(ccc_object_inode(pg->cp_obj), vmpage, ioret);
end_page_writeback(vmpage);
}
}
static int vvp_page_make_ready(const struct lu_env *env,
const struct cl_page_slice *slice)
{
struct page *vmpage = cl2vm_page(slice);
struct cl_page *pg = slice->cpl_page;
int result = 0;
lock_page(vmpage);
if (clear_page_dirty_for_io(vmpage)) {
LASSERT(pg->cp_state == CPS_CACHED);
set_page_writeback(vmpage);
vvp_write_pending(cl2ccc(slice->cpl_obj), cl2ccc_page(slice));
CL_PAGE_HEADER(D_PAGE, env, pg, "readied\n");
} else if (pg->cp_state == CPS_PAGEOUT) {
result = -EALREADY;
} else {
CL_PAGE_DEBUG(D_ERROR, env, pg, "Unexpecting page state %d.\n",
pg->cp_state);
LBUG();
}
unlock_page(vmpage);
return result;
}
static int vvp_page_print(const struct lu_env *env,
const struct cl_page_slice *slice,
void *cookie, lu_printer_t printer)
{
struct ccc_page *vp = cl2ccc_page(slice);
struct page *vmpage = vp->cpg_page;
(*printer)(env, cookie, LUSTRE_VVP_NAME "-page@%p(%d:%d:%d) vm@%p ",
vp, vp->cpg_defer_uptodate, vp->cpg_ra_used,
vp->cpg_write_queued, vmpage);
if (vmpage) {
(*printer)(env, cookie, "%lx %d:%d %lx %lu %slru",
(long)vmpage->flags, page_count(vmpage),
page_mapcount(vmpage), vmpage->private,
page_index(vmpage),
list_empty(&vmpage->lru) ? "not-" : "");
}
(*printer)(env, cookie, "\n");
return 0;
}
static void vvp_transient_page_verify(const struct cl_page *page)
{
struct inode *inode = ccc_object_inode(page->cp_obj);
LASSERT(!inode_trylock(inode));
}
static int vvp_transient_page_own(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused, int nonblock)
{
vvp_transient_page_verify(slice->cpl_page);
return 0;
}
static void vvp_transient_page_assume(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
vvp_transient_page_verify(slice->cpl_page);
}
static void vvp_transient_page_unassume(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
vvp_transient_page_verify(slice->cpl_page);
}
static void vvp_transient_page_disown(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
vvp_transient_page_verify(slice->cpl_page);
}
static void vvp_transient_page_discard(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
struct cl_page *page = slice->cpl_page;
vvp_transient_page_verify(slice->cpl_page);
cl_page_delete(env, page);
}
static int vvp_transient_page_is_vmlocked(const struct lu_env *env,
const struct cl_page_slice *slice)
{
struct inode *inode = ccc_object_inode(slice->cpl_obj);
int locked;
locked = !inode_trylock(inode);
if (!locked)
inode_unlock(inode);
return locked ? -EBUSY : -ENODATA;
}
static void
vvp_transient_page_completion(const struct lu_env *env,
const struct cl_page_slice *slice,
int ioret)
{
vvp_transient_page_verify(slice->cpl_page);
}
static void vvp_transient_page_fini(const struct lu_env *env,
struct cl_page_slice *slice)
{
struct ccc_page *cp = cl2ccc_page(slice);
struct cl_page *clp = slice->cpl_page;
struct ccc_object *clobj = cl2ccc(clp->cp_obj);
vvp_page_fini_common(cp);
LASSERT(!inode_trylock(clobj->cob_inode));
clobj->cob_transient_pages--;
}
int vvp_page_init(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, struct page *vmpage)
{
struct ccc_page *cpg = cl_object_page_slice(obj, page);
CLOBINVRNT(env, obj, ccc_object_invariant(obj));
cpg->cpg_page = vmpage;
get_page(vmpage);
INIT_LIST_HEAD(&cpg->cpg_pending_linkage);
if (page->cp_type == CPT_CACHEABLE) {
SetPagePrivate(vmpage);
vmpage->private = (unsigned long)page;
cl_page_slice_add(page, &cpg->cpg_cl, obj, &vvp_page_ops);
} else {
struct ccc_object *clobj = cl2ccc(obj);
LASSERT(!inode_trylock(clobj->cob_inode));
cl_page_slice_add(page, &cpg->cpg_cl, obj,
&vvp_transient_page_ops);
clobj->cob_transient_pages++;
}
return 0;
}
