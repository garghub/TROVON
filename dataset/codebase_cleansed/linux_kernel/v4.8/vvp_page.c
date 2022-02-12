static void vvp_page_fini_common(struct vvp_page *vpg)
{
struct page *vmpage = vpg->vpg_page;
LASSERT(vmpage);
put_page(vmpage);
}
static void vvp_page_fini(const struct lu_env *env,
struct cl_page_slice *slice)
{
struct vvp_page *vpg = cl2vvp_page(slice);
struct page *vmpage = vpg->vpg_page;
LASSERT((struct cl_page *)vmpage->private != slice->cpl_page);
vvp_page_fini_common(vpg);
}
static int vvp_page_own(const struct lu_env *env,
const struct cl_page_slice *slice, struct cl_io *io,
int nonblock)
{
struct vvp_page *vpg = cl2vvp_page(slice);
struct page *vmpage = vpg->vpg_page;
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
struct vvp_page *vpg = cl2vvp_page(slice);
LASSERT(vmpage);
LASSERT(PageLocked(vmpage));
if (vpg->vpg_defer_uptodate && !vpg->vpg_ra_used)
ll_ra_stats_inc(vmpage->mapping->host, RA_STAT_DISCARDED);
ll_invalidate_page(vmpage);
}
static void vvp_page_delete(const struct lu_env *env,
const struct cl_page_slice *slice)
{
struct page *vmpage = cl2vm_page(slice);
struct inode *inode = vmpage->mapping->host;
struct cl_object *obj = slice->cpl_obj;
struct cl_page *page = slice->cpl_page;
int refc;
LASSERT(PageLocked(vmpage));
LASSERT((struct cl_page *)vmpage->private == page);
LASSERT(inode == vvp_object_inode(obj));
vvp_write_complete(cl2vvp(obj), cl2vvp_page(slice));
refc = atomic_dec_return(&page->cp_ref);
LASSERTF(refc >= 1, "page = %p, refc = %d\n", page, refc);
ClearPageUptodate(vmpage);
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
vvp_write_pending(cl2vvp(slice->cpl_obj), cl2vvp_page(slice));
return 0;
}
static void vvp_vmpage_error(struct inode *inode, struct page *vmpage, int ioret)
{
struct vvp_object *obj = cl_inode2vvp(inode);
if (ioret == 0) {
ClearPageError(vmpage);
obj->vob_discard_page_warned = 0;
} else {
SetPageError(vmpage);
if (ioret == -ENOSPC)
set_bit(AS_ENOSPC, &inode->i_mapping->flags);
else
set_bit(AS_EIO, &inode->i_mapping->flags);
if ((ioret == -ESHUTDOWN || ioret == -EINTR) &&
obj->vob_discard_page_warned == 0) {
obj->vob_discard_page_warned = 1;
ll_dirty_page_discard_warn(vmpage, ioret);
}
}
}
static void vvp_page_completion_read(const struct lu_env *env,
const struct cl_page_slice *slice,
int ioret)
{
struct vvp_page *vpg = cl2vvp_page(slice);
struct page *vmpage = vpg->vpg_page;
struct cl_page *page = slice->cpl_page;
struct inode *inode = vvp_object_inode(page->cp_obj);
LASSERT(PageLocked(vmpage));
CL_PAGE_HEADER(D_PAGE, env, page, "completing READ with %d\n", ioret);
if (vpg->vpg_defer_uptodate)
ll_ra_count_put(ll_i2sbi(inode), 1);
if (ioret == 0) {
if (!vpg->vpg_defer_uptodate)
cl_page_export(env, page, 1);
} else {
vpg->vpg_defer_uptodate = 0;
}
if (!page->cp_sync_io)
unlock_page(vmpage);
}
static void vvp_page_completion_write(const struct lu_env *env,
const struct cl_page_slice *slice,
int ioret)
{
struct vvp_page *vpg = cl2vvp_page(slice);
struct cl_page *pg = slice->cpl_page;
struct page *vmpage = vpg->vpg_page;
CL_PAGE_HEADER(D_PAGE, env, pg, "completing WRITE with %d\n", ioret);
vpg->vpg_write_queued = 0;
vvp_write_complete(cl2vvp(slice->cpl_obj), vpg);
if (pg->cp_sync_io) {
LASSERT(PageLocked(vmpage));
LASSERT(!PageWriteback(vmpage));
} else {
LASSERT(PageWriteback(vmpage));
vvp_vmpage_error(vvp_object_inode(pg->cp_obj), vmpage, ioret);
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
vvp_write_pending(cl2vvp(slice->cpl_obj), cl2vvp_page(slice));
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
static int vvp_page_is_under_lock(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *io, pgoff_t *max_index)
{
if (io->ci_type == CIT_READ || io->ci_type == CIT_WRITE ||
io->ci_type == CIT_FAULT) {
struct vvp_io *vio = vvp_env_io(env);
if (unlikely(vio->vui_fd->fd_flags & LL_FILE_GROUP_LOCKED))
*max_index = CL_PAGE_EOF;
}
return 0;
}
static int vvp_page_print(const struct lu_env *env,
const struct cl_page_slice *slice,
void *cookie, lu_printer_t printer)
{
struct vvp_page *vpg = cl2vvp_page(slice);
struct page *vmpage = vpg->vpg_page;
(*printer)(env, cookie, LUSTRE_VVP_NAME "-page@%p(%d:%d:%d) vm@%p ",
vpg, vpg->vpg_defer_uptodate, vpg->vpg_ra_used,
vpg->vpg_write_queued, vmpage);
if (vmpage) {
(*printer)(env, cookie, "%lx %d:%d %lx %lu %slru",
(long)vmpage->flags, page_count(vmpage),
page_mapcount(vmpage), vmpage->private,
vmpage->index,
list_empty(&vmpage->lru) ? "not-" : "");
}
(*printer)(env, cookie, "\n");
return 0;
}
static int vvp_page_fail(const struct lu_env *env,
const struct cl_page_slice *slice)
{
LBUG();
return 0;
}
static int vvp_transient_page_prep(const struct lu_env *env,
const struct cl_page_slice *slice,
struct cl_io *unused)
{
return 0;
}
static void vvp_transient_page_verify(const struct cl_page *page)
{
struct inode *inode = vvp_object_inode(page->cp_obj);
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
struct inode *inode = vvp_object_inode(slice->cpl_obj);
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
struct vvp_page *vpg = cl2vvp_page(slice);
struct cl_page *clp = slice->cpl_page;
struct vvp_object *clobj = cl2vvp(clp->cp_obj);
vvp_page_fini_common(vpg);
LASSERT(!inode_trylock(clobj->vob_inode));
clobj->vob_transient_pages--;
}
int vvp_page_init(const struct lu_env *env, struct cl_object *obj,
struct cl_page *page, pgoff_t index)
{
struct vvp_page *vpg = cl_object_page_slice(obj, page);
struct page *vmpage = page->cp_vmpage;
CLOBINVRNT(env, obj, vvp_object_invariant(obj));
vpg->vpg_page = vmpage;
get_page(vmpage);
INIT_LIST_HEAD(&vpg->vpg_pending_linkage);
if (page->cp_type == CPT_CACHEABLE) {
atomic_inc(&page->cp_ref);
SetPagePrivate(vmpage);
vmpage->private = (unsigned long)page;
cl_page_slice_add(page, &vpg->vpg_cl, obj, index,
&vvp_page_ops);
} else {
struct vvp_object *clobj = cl2vvp(obj);
LASSERT(!inode_trylock(clobj->vob_inode));
cl_page_slice_add(page, &vpg->vpg_cl, obj, index,
&vvp_transient_page_ops);
clobj->vob_transient_pages++;
}
return 0;
}
