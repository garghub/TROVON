static inline int
xfs_buf_is_vmapped(
struct xfs_buf *bp)
{
return bp->b_addr && bp->b_page_count > 1;
}
static inline int
xfs_buf_vmap_len(
struct xfs_buf *bp)
{
return (bp->b_page_count * PAGE_SIZE) - bp->b_offset;
}
static inline void
xfs_buf_ioacct_inc(
struct xfs_buf *bp)
{
if (bp->b_flags & XBF_NO_IOACCT)
return;
ASSERT(bp->b_flags & XBF_ASYNC);
spin_lock(&bp->b_lock);
if (!(bp->b_state & XFS_BSTATE_IN_FLIGHT)) {
bp->b_state |= XFS_BSTATE_IN_FLIGHT;
percpu_counter_inc(&bp->b_target->bt_io_count);
}
spin_unlock(&bp->b_lock);
}
static inline void
__xfs_buf_ioacct_dec(
struct xfs_buf *bp)
{
lockdep_assert_held(&bp->b_lock);
if (bp->b_state & XFS_BSTATE_IN_FLIGHT) {
bp->b_state &= ~XFS_BSTATE_IN_FLIGHT;
percpu_counter_dec(&bp->b_target->bt_io_count);
}
}
static inline void
xfs_buf_ioacct_dec(
struct xfs_buf *bp)
{
spin_lock(&bp->b_lock);
__xfs_buf_ioacct_dec(bp);
spin_unlock(&bp->b_lock);
}
void
xfs_buf_stale(
struct xfs_buf *bp)
{
ASSERT(xfs_buf_islocked(bp));
bp->b_flags |= XBF_STALE;
bp->b_flags &= ~_XBF_DELWRI_Q;
spin_lock(&bp->b_lock);
__xfs_buf_ioacct_dec(bp);
atomic_set(&bp->b_lru_ref, 0);
if (!(bp->b_state & XFS_BSTATE_DISPOSE) &&
(list_lru_del(&bp->b_target->bt_lru, &bp->b_lru)))
atomic_dec(&bp->b_hold);
ASSERT(atomic_read(&bp->b_hold) >= 1);
spin_unlock(&bp->b_lock);
}
static int
xfs_buf_get_maps(
struct xfs_buf *bp,
int map_count)
{
ASSERT(bp->b_maps == NULL);
bp->b_map_count = map_count;
if (map_count == 1) {
bp->b_maps = &bp->__b_map;
return 0;
}
bp->b_maps = kmem_zalloc(map_count * sizeof(struct xfs_buf_map),
KM_NOFS);
if (!bp->b_maps)
return -ENOMEM;
return 0;
}
static void
xfs_buf_free_maps(
struct xfs_buf *bp)
{
if (bp->b_maps != &bp->__b_map) {
kmem_free(bp->b_maps);
bp->b_maps = NULL;
}
}
struct xfs_buf *
_xfs_buf_alloc(
struct xfs_buftarg *target,
struct xfs_buf_map *map,
int nmaps,
xfs_buf_flags_t flags)
{
struct xfs_buf *bp;
int error;
int i;
bp = kmem_zone_zalloc(xfs_buf_zone, KM_NOFS);
if (unlikely(!bp))
return NULL;
flags &= ~(XBF_UNMAPPED | XBF_TRYLOCK | XBF_ASYNC | XBF_READ_AHEAD);
atomic_set(&bp->b_hold, 1);
atomic_set(&bp->b_lru_ref, 1);
init_completion(&bp->b_iowait);
INIT_LIST_HEAD(&bp->b_lru);
INIT_LIST_HEAD(&bp->b_list);
sema_init(&bp->b_sema, 0);
spin_lock_init(&bp->b_lock);
XB_SET_OWNER(bp);
bp->b_target = target;
bp->b_flags = flags;
error = xfs_buf_get_maps(bp, nmaps);
if (error) {
kmem_zone_free(xfs_buf_zone, bp);
return NULL;
}
bp->b_bn = map[0].bm_bn;
bp->b_length = 0;
for (i = 0; i < nmaps; i++) {
bp->b_maps[i].bm_bn = map[i].bm_bn;
bp->b_maps[i].bm_len = map[i].bm_len;
bp->b_length += map[i].bm_len;
}
bp->b_io_length = bp->b_length;
atomic_set(&bp->b_pin_count, 0);
init_waitqueue_head(&bp->b_waiters);
XFS_STATS_INC(target->bt_mount, xb_create);
trace_xfs_buf_init(bp, _RET_IP_);
return bp;
}
STATIC int
_xfs_buf_get_pages(
xfs_buf_t *bp,
int page_count)
{
if (bp->b_pages == NULL) {
bp->b_page_count = page_count;
if (page_count <= XB_PAGES) {
bp->b_pages = bp->b_page_array;
} else {
bp->b_pages = kmem_alloc(sizeof(struct page *) *
page_count, KM_NOFS);
if (bp->b_pages == NULL)
return -ENOMEM;
}
memset(bp->b_pages, 0, sizeof(struct page *) * page_count);
}
return 0;
}
STATIC void
_xfs_buf_free_pages(
xfs_buf_t *bp)
{
if (bp->b_pages != bp->b_page_array) {
kmem_free(bp->b_pages);
bp->b_pages = NULL;
}
}
void
xfs_buf_free(
xfs_buf_t *bp)
{
trace_xfs_buf_free(bp, _RET_IP_);
ASSERT(list_empty(&bp->b_lru));
if (bp->b_flags & _XBF_PAGES) {
uint i;
if (xfs_buf_is_vmapped(bp))
vm_unmap_ram(bp->b_addr - bp->b_offset,
bp->b_page_count);
for (i = 0; i < bp->b_page_count; i++) {
struct page *page = bp->b_pages[i];
__free_page(page);
}
} else if (bp->b_flags & _XBF_KMEM)
kmem_free(bp->b_addr);
_xfs_buf_free_pages(bp);
xfs_buf_free_maps(bp);
kmem_zone_free(xfs_buf_zone, bp);
}
STATIC int
xfs_buf_allocate_memory(
xfs_buf_t *bp,
uint flags)
{
size_t size;
size_t nbytes, offset;
gfp_t gfp_mask = xb_to_gfp(flags);
unsigned short page_count, i;
xfs_off_t start, end;
int error;
size = BBTOB(bp->b_length);
if (size < PAGE_SIZE) {
bp->b_addr = kmem_alloc(size, KM_NOFS);
if (!bp->b_addr) {
goto use_alloc_page;
}
if (((unsigned long)(bp->b_addr + size - 1) & PAGE_MASK) !=
((unsigned long)bp->b_addr & PAGE_MASK)) {
kmem_free(bp->b_addr);
bp->b_addr = NULL;
goto use_alloc_page;
}
bp->b_offset = offset_in_page(bp->b_addr);
bp->b_pages = bp->b_page_array;
bp->b_pages[0] = virt_to_page(bp->b_addr);
bp->b_page_count = 1;
bp->b_flags |= _XBF_KMEM;
return 0;
}
use_alloc_page:
start = BBTOB(bp->b_maps[0].bm_bn) >> PAGE_SHIFT;
end = (BBTOB(bp->b_maps[0].bm_bn + bp->b_length) + PAGE_SIZE - 1)
>> PAGE_SHIFT;
page_count = end - start;
error = _xfs_buf_get_pages(bp, page_count);
if (unlikely(error))
return error;
offset = bp->b_offset;
bp->b_flags |= _XBF_PAGES;
for (i = 0; i < bp->b_page_count; i++) {
struct page *page;
uint retries = 0;
retry:
page = alloc_page(gfp_mask);
if (unlikely(page == NULL)) {
if (flags & XBF_READ_AHEAD) {
bp->b_page_count = i;
error = -ENOMEM;
goto out_free_pages;
}
if (!(++retries % 100))
xfs_err(NULL,
"%s(%u) possible memory allocation deadlock in %s (mode:0x%x)",
current->comm, current->pid,
__func__, gfp_mask);
XFS_STATS_INC(bp->b_target->bt_mount, xb_page_retries);
congestion_wait(BLK_RW_ASYNC, HZ/50);
goto retry;
}
XFS_STATS_INC(bp->b_target->bt_mount, xb_page_found);
nbytes = min_t(size_t, size, PAGE_SIZE - offset);
size -= nbytes;
bp->b_pages[i] = page;
offset = 0;
}
return 0;
out_free_pages:
for (i = 0; i < bp->b_page_count; i++)
__free_page(bp->b_pages[i]);
bp->b_flags &= ~_XBF_PAGES;
return error;
}
STATIC int
_xfs_buf_map_pages(
xfs_buf_t *bp,
uint flags)
{
ASSERT(bp->b_flags & _XBF_PAGES);
if (bp->b_page_count == 1) {
bp->b_addr = page_address(bp->b_pages[0]) + bp->b_offset;
} else if (flags & XBF_UNMAPPED) {
bp->b_addr = NULL;
} else {
int retried = 0;
unsigned nofs_flag;
nofs_flag = memalloc_nofs_save();
do {
bp->b_addr = vm_map_ram(bp->b_pages, bp->b_page_count,
-1, PAGE_KERNEL);
if (bp->b_addr)
break;
vm_unmap_aliases();
} while (retried++ <= 1);
memalloc_nofs_restore(nofs_flag);
if (!bp->b_addr)
return -ENOMEM;
bp->b_addr += bp->b_offset;
}
return 0;
}
static int
_xfs_buf_obj_cmp(
struct rhashtable_compare_arg *arg,
const void *obj)
{
const struct xfs_buf_map *map = arg->key;
const struct xfs_buf *bp = obj;
BUILD_BUG_ON(offsetof(struct xfs_buf_map, bm_bn) != 0);
if (bp->b_bn != map->bm_bn)
return 1;
if (unlikely(bp->b_length != map->bm_len)) {
ASSERT(bp->b_flags & XBF_STALE);
return 1;
}
return 0;
}
int
xfs_buf_hash_init(
struct xfs_perag *pag)
{
spin_lock_init(&pag->pag_buf_lock);
return rhashtable_init(&pag->pag_buf_hash, &xfs_buf_hash_params);
}
void
xfs_buf_hash_destroy(
struct xfs_perag *pag)
{
rhashtable_destroy(&pag->pag_buf_hash);
}
xfs_buf_t *
_xfs_buf_find(
struct xfs_buftarg *btp,
struct xfs_buf_map *map,
int nmaps,
xfs_buf_flags_t flags,
xfs_buf_t *new_bp)
{
struct xfs_perag *pag;
xfs_buf_t *bp;
struct xfs_buf_map cmap = { .bm_bn = map[0].bm_bn };
xfs_daddr_t eofs;
int i;
for (i = 0; i < nmaps; i++)
cmap.bm_len += map[i].bm_len;
ASSERT(!(BBTOB(cmap.bm_len) < btp->bt_meta_sectorsize));
ASSERT(!(BBTOB(cmap.bm_bn) & (xfs_off_t)btp->bt_meta_sectormask));
eofs = XFS_FSB_TO_BB(btp->bt_mount, btp->bt_mount->m_sb.sb_dblocks);
if (cmap.bm_bn < 0 || cmap.bm_bn >= eofs) {
xfs_alert(btp->bt_mount,
"%s: Block out of range: block 0x%llx, EOFS 0x%llx ",
__func__, cmap.bm_bn, eofs);
WARN_ON(1);
return NULL;
}
pag = xfs_perag_get(btp->bt_mount,
xfs_daddr_to_agno(btp->bt_mount, cmap.bm_bn));
spin_lock(&pag->pag_buf_lock);
bp = rhashtable_lookup_fast(&pag->pag_buf_hash, &cmap,
xfs_buf_hash_params);
if (bp) {
atomic_inc(&bp->b_hold);
goto found;
}
if (new_bp) {
new_bp->b_pag = pag;
rhashtable_insert_fast(&pag->pag_buf_hash,
&new_bp->b_rhash_head,
xfs_buf_hash_params);
spin_unlock(&pag->pag_buf_lock);
} else {
XFS_STATS_INC(btp->bt_mount, xb_miss_locked);
spin_unlock(&pag->pag_buf_lock);
xfs_perag_put(pag);
}
return new_bp;
found:
spin_unlock(&pag->pag_buf_lock);
xfs_perag_put(pag);
if (!xfs_buf_trylock(bp)) {
if (flags & XBF_TRYLOCK) {
xfs_buf_rele(bp);
XFS_STATS_INC(btp->bt_mount, xb_busy_locked);
return NULL;
}
xfs_buf_lock(bp);
XFS_STATS_INC(btp->bt_mount, xb_get_locked_waited);
}
if (bp->b_flags & XBF_STALE) {
ASSERT((bp->b_flags & _XBF_DELWRI_Q) == 0);
ASSERT(bp->b_iodone == NULL);
bp->b_flags &= _XBF_KMEM | _XBF_PAGES;
bp->b_ops = NULL;
}
trace_xfs_buf_find(bp, flags, _RET_IP_);
XFS_STATS_INC(btp->bt_mount, xb_get_locked);
return bp;
}
struct xfs_buf *
xfs_buf_get_map(
struct xfs_buftarg *target,
struct xfs_buf_map *map,
int nmaps,
xfs_buf_flags_t flags)
{
struct xfs_buf *bp;
struct xfs_buf *new_bp;
int error = 0;
bp = _xfs_buf_find(target, map, nmaps, flags, NULL);
if (likely(bp))
goto found;
new_bp = _xfs_buf_alloc(target, map, nmaps, flags);
if (unlikely(!new_bp))
return NULL;
error = xfs_buf_allocate_memory(new_bp, flags);
if (error) {
xfs_buf_free(new_bp);
return NULL;
}
bp = _xfs_buf_find(target, map, nmaps, flags, new_bp);
if (!bp) {
xfs_buf_free(new_bp);
return NULL;
}
if (bp != new_bp)
xfs_buf_free(new_bp);
found:
if (!bp->b_addr) {
error = _xfs_buf_map_pages(bp, flags);
if (unlikely(error)) {
xfs_warn(target->bt_mount,
"%s: failed to map pagesn", __func__);
xfs_buf_relse(bp);
return NULL;
}
}
if (!(flags & XBF_READ))
xfs_buf_ioerror(bp, 0);
XFS_STATS_INC(target->bt_mount, xb_get);
trace_xfs_buf_get(bp, flags, _RET_IP_);
return bp;
}
STATIC int
_xfs_buf_read(
xfs_buf_t *bp,
xfs_buf_flags_t flags)
{
ASSERT(!(flags & XBF_WRITE));
ASSERT(bp->b_maps[0].bm_bn != XFS_BUF_DADDR_NULL);
bp->b_flags &= ~(XBF_WRITE | XBF_ASYNC | XBF_READ_AHEAD);
bp->b_flags |= flags & (XBF_READ | XBF_ASYNC | XBF_READ_AHEAD);
if (flags & XBF_ASYNC) {
xfs_buf_submit(bp);
return 0;
}
return xfs_buf_submit_wait(bp);
}
xfs_buf_t *
xfs_buf_read_map(
struct xfs_buftarg *target,
struct xfs_buf_map *map,
int nmaps,
xfs_buf_flags_t flags,
const struct xfs_buf_ops *ops)
{
struct xfs_buf *bp;
flags |= XBF_READ;
bp = xfs_buf_get_map(target, map, nmaps, flags);
if (bp) {
trace_xfs_buf_read(bp, flags, _RET_IP_);
if (!(bp->b_flags & XBF_DONE)) {
XFS_STATS_INC(target->bt_mount, xb_get_read);
bp->b_ops = ops;
_xfs_buf_read(bp, flags);
} else if (flags & XBF_ASYNC) {
xfs_buf_relse(bp);
return NULL;
} else {
bp->b_flags &= ~XBF_READ;
}
}
return bp;
}
void
xfs_buf_readahead_map(
struct xfs_buftarg *target,
struct xfs_buf_map *map,
int nmaps,
const struct xfs_buf_ops *ops)
{
if (bdi_read_congested(target->bt_bdev->bd_bdi))
return;
xfs_buf_read_map(target, map, nmaps,
XBF_TRYLOCK|XBF_ASYNC|XBF_READ_AHEAD, ops);
}
int
xfs_buf_read_uncached(
struct xfs_buftarg *target,
xfs_daddr_t daddr,
size_t numblks,
int flags,
struct xfs_buf **bpp,
const struct xfs_buf_ops *ops)
{
struct xfs_buf *bp;
*bpp = NULL;
bp = xfs_buf_get_uncached(target, numblks, flags);
if (!bp)
return -ENOMEM;
ASSERT(bp->b_map_count == 1);
bp->b_bn = XFS_BUF_DADDR_NULL;
bp->b_maps[0].bm_bn = daddr;
bp->b_flags |= XBF_READ;
bp->b_ops = ops;
xfs_buf_submit_wait(bp);
if (bp->b_error) {
int error = bp->b_error;
xfs_buf_relse(bp);
return error;
}
*bpp = bp;
return 0;
}
void
xfs_buf_set_empty(
struct xfs_buf *bp,
size_t numblks)
{
if (bp->b_pages)
_xfs_buf_free_pages(bp);
bp->b_pages = NULL;
bp->b_page_count = 0;
bp->b_addr = NULL;
bp->b_length = numblks;
bp->b_io_length = numblks;
ASSERT(bp->b_map_count == 1);
bp->b_bn = XFS_BUF_DADDR_NULL;
bp->b_maps[0].bm_bn = XFS_BUF_DADDR_NULL;
bp->b_maps[0].bm_len = bp->b_length;
}
static inline struct page *
mem_to_page(
void *addr)
{
if ((!is_vmalloc_addr(addr))) {
return virt_to_page(addr);
} else {
return vmalloc_to_page(addr);
}
}
int
xfs_buf_associate_memory(
xfs_buf_t *bp,
void *mem,
size_t len)
{
int rval;
int i = 0;
unsigned long pageaddr;
unsigned long offset;
size_t buflen;
int page_count;
pageaddr = (unsigned long)mem & PAGE_MASK;
offset = (unsigned long)mem - pageaddr;
buflen = PAGE_ALIGN(len + offset);
page_count = buflen >> PAGE_SHIFT;
if (bp->b_pages)
_xfs_buf_free_pages(bp);
bp->b_pages = NULL;
bp->b_addr = mem;
rval = _xfs_buf_get_pages(bp, page_count);
if (rval)
return rval;
bp->b_offset = offset;
for (i = 0; i < bp->b_page_count; i++) {
bp->b_pages[i] = mem_to_page((void *)pageaddr);
pageaddr += PAGE_SIZE;
}
bp->b_io_length = BTOBB(len);
bp->b_length = BTOBB(buflen);
return 0;
}
xfs_buf_t *
xfs_buf_get_uncached(
struct xfs_buftarg *target,
size_t numblks,
int flags)
{
unsigned long page_count;
int error, i;
struct xfs_buf *bp;
DEFINE_SINGLE_BUF_MAP(map, XFS_BUF_DADDR_NULL, numblks);
bp = _xfs_buf_alloc(target, &map, 1, flags & XBF_NO_IOACCT);
if (unlikely(bp == NULL))
goto fail;
page_count = PAGE_ALIGN(numblks << BBSHIFT) >> PAGE_SHIFT;
error = _xfs_buf_get_pages(bp, page_count);
if (error)
goto fail_free_buf;
for (i = 0; i < page_count; i++) {
bp->b_pages[i] = alloc_page(xb_to_gfp(flags));
if (!bp->b_pages[i])
goto fail_free_mem;
}
bp->b_flags |= _XBF_PAGES;
error = _xfs_buf_map_pages(bp, 0);
if (unlikely(error)) {
xfs_warn(target->bt_mount,
"%s: failed to map pages", __func__);
goto fail_free_mem;
}
trace_xfs_buf_get_uncached(bp, _RET_IP_);
return bp;
fail_free_mem:
while (--i >= 0)
__free_page(bp->b_pages[i]);
_xfs_buf_free_pages(bp);
fail_free_buf:
xfs_buf_free_maps(bp);
kmem_zone_free(xfs_buf_zone, bp);
fail:
return NULL;
}
void
xfs_buf_hold(
xfs_buf_t *bp)
{
trace_xfs_buf_hold(bp, _RET_IP_);
atomic_inc(&bp->b_hold);
}
void
xfs_buf_rele(
xfs_buf_t *bp)
{
struct xfs_perag *pag = bp->b_pag;
bool release;
bool freebuf = false;
trace_xfs_buf_rele(bp, _RET_IP_);
if (!pag) {
ASSERT(list_empty(&bp->b_lru));
if (atomic_dec_and_test(&bp->b_hold)) {
xfs_buf_ioacct_dec(bp);
xfs_buf_free(bp);
}
return;
}
ASSERT(atomic_read(&bp->b_hold) > 0);
release = atomic_dec_and_lock(&bp->b_hold, &pag->pag_buf_lock);
spin_lock(&bp->b_lock);
if (!release) {
if ((atomic_read(&bp->b_hold) == 1) && !list_empty(&bp->b_lru))
__xfs_buf_ioacct_dec(bp);
goto out_unlock;
}
__xfs_buf_ioacct_dec(bp);
if (!(bp->b_flags & XBF_STALE) && atomic_read(&bp->b_lru_ref)) {
if (list_lru_add(&bp->b_target->bt_lru, &bp->b_lru)) {
bp->b_state &= ~XFS_BSTATE_DISPOSE;
atomic_inc(&bp->b_hold);
}
spin_unlock(&pag->pag_buf_lock);
} else {
if (!(bp->b_state & XFS_BSTATE_DISPOSE)) {
list_lru_del(&bp->b_target->bt_lru, &bp->b_lru);
} else {
ASSERT(list_empty(&bp->b_lru));
}
ASSERT(!(bp->b_flags & _XBF_DELWRI_Q));
rhashtable_remove_fast(&pag->pag_buf_hash, &bp->b_rhash_head,
xfs_buf_hash_params);
spin_unlock(&pag->pag_buf_lock);
xfs_perag_put(pag);
freebuf = true;
}
out_unlock:
spin_unlock(&bp->b_lock);
if (freebuf)
xfs_buf_free(bp);
}
int
xfs_buf_trylock(
struct xfs_buf *bp)
{
int locked;
locked = down_trylock(&bp->b_sema) == 0;
if (locked) {
XB_SET_OWNER(bp);
trace_xfs_buf_trylock(bp, _RET_IP_);
} else {
trace_xfs_buf_trylock_fail(bp, _RET_IP_);
}
return locked;
}
void
xfs_buf_lock(
struct xfs_buf *bp)
{
trace_xfs_buf_lock(bp, _RET_IP_);
if (atomic_read(&bp->b_pin_count) && (bp->b_flags & XBF_STALE))
xfs_log_force(bp->b_target->bt_mount, 0);
down(&bp->b_sema);
XB_SET_OWNER(bp);
trace_xfs_buf_lock_done(bp, _RET_IP_);
}
void
xfs_buf_unlock(
struct xfs_buf *bp)
{
ASSERT(xfs_buf_islocked(bp));
XB_CLEAR_OWNER(bp);
up(&bp->b_sema);
trace_xfs_buf_unlock(bp, _RET_IP_);
}
STATIC void
xfs_buf_wait_unpin(
xfs_buf_t *bp)
{
DECLARE_WAITQUEUE (wait, current);
if (atomic_read(&bp->b_pin_count) == 0)
return;
add_wait_queue(&bp->b_waiters, &wait);
for (;;) {
set_current_state(TASK_UNINTERRUPTIBLE);
if (atomic_read(&bp->b_pin_count) == 0)
break;
io_schedule();
}
remove_wait_queue(&bp->b_waiters, &wait);
set_current_state(TASK_RUNNING);
}
void
xfs_buf_ioend(
struct xfs_buf *bp)
{
bool read = bp->b_flags & XBF_READ;
trace_xfs_buf_iodone(bp, _RET_IP_);
bp->b_flags &= ~(XBF_READ | XBF_WRITE | XBF_READ_AHEAD);
if (!bp->b_error && bp->b_io_error)
xfs_buf_ioerror(bp, bp->b_io_error);
if (read && !bp->b_error && bp->b_ops) {
ASSERT(!bp->b_iodone);
bp->b_ops->verify_read(bp);
}
if (!bp->b_error)
bp->b_flags |= XBF_DONE;
if (bp->b_iodone)
(*(bp->b_iodone))(bp);
else if (bp->b_flags & XBF_ASYNC)
xfs_buf_relse(bp);
else
complete(&bp->b_iowait);
}
static void
xfs_buf_ioend_work(
struct work_struct *work)
{
struct xfs_buf *bp =
container_of(work, xfs_buf_t, b_ioend_work);
xfs_buf_ioend(bp);
}
static void
xfs_buf_ioend_async(
struct xfs_buf *bp)
{
INIT_WORK(&bp->b_ioend_work, xfs_buf_ioend_work);
queue_work(bp->b_ioend_wq, &bp->b_ioend_work);
}
void
xfs_buf_ioerror(
xfs_buf_t *bp,
int error)
{
ASSERT(error <= 0 && error >= -1000);
bp->b_error = error;
trace_xfs_buf_ioerror(bp, error, _RET_IP_);
}
void
xfs_buf_ioerror_alert(
struct xfs_buf *bp,
const char *func)
{
xfs_alert(bp->b_target->bt_mount,
"metadata I/O error: block 0x%llx (\"%s\") error %d numblks %d",
(uint64_t)XFS_BUF_ADDR(bp), func, -bp->b_error, bp->b_length);
}
int
xfs_bwrite(
struct xfs_buf *bp)
{
int error;
ASSERT(xfs_buf_islocked(bp));
bp->b_flags |= XBF_WRITE;
bp->b_flags &= ~(XBF_ASYNC | XBF_READ | _XBF_DELWRI_Q |
XBF_WRITE_FAIL | XBF_DONE);
error = xfs_buf_submit_wait(bp);
if (error) {
xfs_force_shutdown(bp->b_target->bt_mount,
SHUTDOWN_META_IO_ERROR);
}
return error;
}
static void
xfs_buf_bio_end_io(
struct bio *bio)
{
struct xfs_buf *bp = (struct xfs_buf *)bio->bi_private;
if (bio->bi_status) {
int error = blk_status_to_errno(bio->bi_status);
cmpxchg(&bp->b_io_error, 0, error);
}
if (!bp->b_error && xfs_buf_is_vmapped(bp) && (bp->b_flags & XBF_READ))
invalidate_kernel_vmap_range(bp->b_addr, xfs_buf_vmap_len(bp));
if (atomic_dec_and_test(&bp->b_io_remaining) == 1)
xfs_buf_ioend_async(bp);
bio_put(bio);
}
static void
xfs_buf_ioapply_map(
struct xfs_buf *bp,
int map,
int *buf_offset,
int *count,
int op,
int op_flags)
{
int page_index;
int total_nr_pages = bp->b_page_count;
int nr_pages;
struct bio *bio;
sector_t sector = bp->b_maps[map].bm_bn;
int size;
int offset;
total_nr_pages = bp->b_page_count;
page_index = 0;
offset = *buf_offset;
while (offset >= PAGE_SIZE) {
page_index++;
offset -= PAGE_SIZE;
}
size = min_t(int, BBTOB(bp->b_maps[map].bm_len), *count);
*count -= size;
*buf_offset += size;
next_chunk:
atomic_inc(&bp->b_io_remaining);
nr_pages = min(total_nr_pages, BIO_MAX_PAGES);
bio = bio_alloc(GFP_NOIO, nr_pages);
bio->bi_bdev = bp->b_target->bt_bdev;
bio->bi_iter.bi_sector = sector;
bio->bi_end_io = xfs_buf_bio_end_io;
bio->bi_private = bp;
bio_set_op_attrs(bio, op, op_flags);
for (; size && nr_pages; nr_pages--, page_index++) {
int rbytes, nbytes = PAGE_SIZE - offset;
if (nbytes > size)
nbytes = size;
rbytes = bio_add_page(bio, bp->b_pages[page_index], nbytes,
offset);
if (rbytes < nbytes)
break;
offset = 0;
sector += BTOBB(nbytes);
size -= nbytes;
total_nr_pages--;
}
if (likely(bio->bi_iter.bi_size)) {
if (xfs_buf_is_vmapped(bp)) {
flush_kernel_vmap_range(bp->b_addr,
xfs_buf_vmap_len(bp));
}
submit_bio(bio);
if (size)
goto next_chunk;
} else {
atomic_dec(&bp->b_io_remaining);
xfs_buf_ioerror(bp, -EIO);
bio_put(bio);
}
}
STATIC void
_xfs_buf_ioapply(
struct xfs_buf *bp)
{
struct blk_plug plug;
int op;
int op_flags = 0;
int offset;
int size;
int i;
bp->b_error = 0;
if (!bp->b_ioend_wq)
bp->b_ioend_wq = bp->b_target->bt_mount->m_buf_workqueue;
if (bp->b_flags & XBF_WRITE) {
op = REQ_OP_WRITE;
if (bp->b_flags & XBF_SYNCIO)
op_flags = REQ_SYNC;
if (bp->b_flags & XBF_FUA)
op_flags |= REQ_FUA;
if (bp->b_flags & XBF_FLUSH)
op_flags |= REQ_PREFLUSH;
if (bp->b_ops) {
bp->b_ops->verify_write(bp);
if (bp->b_error) {
xfs_force_shutdown(bp->b_target->bt_mount,
SHUTDOWN_CORRUPT_INCORE);
return;
}
} else if (bp->b_bn != XFS_BUF_DADDR_NULL) {
struct xfs_mount *mp = bp->b_target->bt_mount;
if (xfs_sb_version_hascrc(&mp->m_sb)) {
xfs_warn(mp,
"%s: no ops on block 0x%llx/0x%x",
__func__, bp->b_bn, bp->b_length);
xfs_hex_dump(bp->b_addr, 64);
dump_stack();
}
}
} else if (bp->b_flags & XBF_READ_AHEAD) {
op = REQ_OP_READ;
op_flags = REQ_RAHEAD;
} else {
op = REQ_OP_READ;
}
op_flags |= REQ_META;
offset = bp->b_offset;
size = BBTOB(bp->b_io_length);
blk_start_plug(&plug);
for (i = 0; i < bp->b_map_count; i++) {
xfs_buf_ioapply_map(bp, i, &offset, &size, op, op_flags);
if (bp->b_error)
break;
if (size <= 0)
break;
}
blk_finish_plug(&plug);
}
void
xfs_buf_submit(
struct xfs_buf *bp)
{
trace_xfs_buf_submit(bp, _RET_IP_);
ASSERT(!(bp->b_flags & _XBF_DELWRI_Q));
ASSERT(bp->b_flags & XBF_ASYNC);
if (XFS_FORCED_SHUTDOWN(bp->b_target->bt_mount)) {
xfs_buf_ioerror(bp, -EIO);
bp->b_flags &= ~XBF_DONE;
xfs_buf_stale(bp);
xfs_buf_ioend(bp);
return;
}
if (bp->b_flags & XBF_WRITE)
xfs_buf_wait_unpin(bp);
bp->b_io_error = 0;
xfs_buf_hold(bp);
atomic_set(&bp->b_io_remaining, 1);
xfs_buf_ioacct_inc(bp);
_xfs_buf_ioapply(bp);
if (atomic_dec_and_test(&bp->b_io_remaining) == 1) {
if (bp->b_error)
xfs_buf_ioend(bp);
else
xfs_buf_ioend_async(bp);
}
xfs_buf_rele(bp);
}
int
xfs_buf_submit_wait(
struct xfs_buf *bp)
{
int error;
trace_xfs_buf_submit_wait(bp, _RET_IP_);
ASSERT(!(bp->b_flags & (_XBF_DELWRI_Q | XBF_ASYNC)));
if (XFS_FORCED_SHUTDOWN(bp->b_target->bt_mount)) {
xfs_buf_ioerror(bp, -EIO);
xfs_buf_stale(bp);
bp->b_flags &= ~XBF_DONE;
return -EIO;
}
if (bp->b_flags & XBF_WRITE)
xfs_buf_wait_unpin(bp);
bp->b_io_error = 0;
xfs_buf_hold(bp);
atomic_set(&bp->b_io_remaining, 1);
_xfs_buf_ioapply(bp);
if (atomic_dec_and_test(&bp->b_io_remaining) == 1)
xfs_buf_ioend(bp);
trace_xfs_buf_iowait(bp, _RET_IP_);
wait_for_completion(&bp->b_iowait);
trace_xfs_buf_iowait_done(bp, _RET_IP_);
error = bp->b_error;
xfs_buf_rele(bp);
return error;
}
void *
xfs_buf_offset(
struct xfs_buf *bp,
size_t offset)
{
struct page *page;
if (bp->b_addr)
return bp->b_addr + offset;
offset += bp->b_offset;
page = bp->b_pages[offset >> PAGE_SHIFT];
return page_address(page) + (offset & (PAGE_SIZE-1));
}
void
xfs_buf_iomove(
xfs_buf_t *bp,
size_t boff,
size_t bsize,
void *data,
xfs_buf_rw_t mode)
{
size_t bend;
bend = boff + bsize;
while (boff < bend) {
struct page *page;
int page_index, page_offset, csize;
page_index = (boff + bp->b_offset) >> PAGE_SHIFT;
page_offset = (boff + bp->b_offset) & ~PAGE_MASK;
page = bp->b_pages[page_index];
csize = min_t(size_t, PAGE_SIZE - page_offset,
BBTOB(bp->b_io_length) - boff);
ASSERT((csize + page_offset) <= PAGE_SIZE);
switch (mode) {
case XBRW_ZERO:
memset(page_address(page) + page_offset, 0, csize);
break;
case XBRW_READ:
memcpy(data, page_address(page) + page_offset, csize);
break;
case XBRW_WRITE:
memcpy(page_address(page) + page_offset, data, csize);
}
boff += csize;
data += csize;
}
}
static enum lru_status
xfs_buftarg_wait_rele(
struct list_head *item,
struct list_lru_one *lru,
spinlock_t *lru_lock,
void *arg)
{
struct xfs_buf *bp = container_of(item, struct xfs_buf, b_lru);
struct list_head *dispose = arg;
if (atomic_read(&bp->b_hold) > 1) {
trace_xfs_buf_wait_buftarg(bp, _RET_IP_);
return LRU_SKIP;
}
if (!spin_trylock(&bp->b_lock))
return LRU_SKIP;
atomic_set(&bp->b_lru_ref, 0);
bp->b_state |= XFS_BSTATE_DISPOSE;
list_lru_isolate_move(lru, item, dispose);
spin_unlock(&bp->b_lock);
return LRU_REMOVED;
}
void
xfs_wait_buftarg(
struct xfs_buftarg *btp)
{
LIST_HEAD(dispose);
int loop = 0;
while (percpu_counter_sum(&btp->bt_io_count))
delay(100);
flush_workqueue(btp->bt_mount->m_buf_workqueue);
while (list_lru_count(&btp->bt_lru)) {
list_lru_walk(&btp->bt_lru, xfs_buftarg_wait_rele,
&dispose, LONG_MAX);
while (!list_empty(&dispose)) {
struct xfs_buf *bp;
bp = list_first_entry(&dispose, struct xfs_buf, b_lru);
list_del_init(&bp->b_lru);
if (bp->b_flags & XBF_WRITE_FAIL) {
xfs_alert(btp->bt_mount,
"Corruption Alert: Buffer at block 0x%llx had permanent write failures!",
(long long)bp->b_bn);
xfs_alert(btp->bt_mount,
"Please run xfs_repair to determine the extent of the problem.");
}
xfs_buf_rele(bp);
}
if (loop++ != 0)
delay(100);
}
}
static enum lru_status
xfs_buftarg_isolate(
struct list_head *item,
struct list_lru_one *lru,
spinlock_t *lru_lock,
void *arg)
{
struct xfs_buf *bp = container_of(item, struct xfs_buf, b_lru);
struct list_head *dispose = arg;
if (!spin_trylock(&bp->b_lock))
return LRU_SKIP;
if (!atomic_add_unless(&bp->b_lru_ref, -1, 0)) {
spin_unlock(&bp->b_lock);
return LRU_ROTATE;
}
bp->b_state |= XFS_BSTATE_DISPOSE;
list_lru_isolate_move(lru, item, dispose);
spin_unlock(&bp->b_lock);
return LRU_REMOVED;
}
static unsigned long
xfs_buftarg_shrink_scan(
struct shrinker *shrink,
struct shrink_control *sc)
{
struct xfs_buftarg *btp = container_of(shrink,
struct xfs_buftarg, bt_shrinker);
LIST_HEAD(dispose);
unsigned long freed;
freed = list_lru_shrink_walk(&btp->bt_lru, sc,
xfs_buftarg_isolate, &dispose);
while (!list_empty(&dispose)) {
struct xfs_buf *bp;
bp = list_first_entry(&dispose, struct xfs_buf, b_lru);
list_del_init(&bp->b_lru);
xfs_buf_rele(bp);
}
return freed;
}
static unsigned long
xfs_buftarg_shrink_count(
struct shrinker *shrink,
struct shrink_control *sc)
{
struct xfs_buftarg *btp = container_of(shrink,
struct xfs_buftarg, bt_shrinker);
return list_lru_shrink_count(&btp->bt_lru, sc);
}
void
xfs_free_buftarg(
struct xfs_mount *mp,
struct xfs_buftarg *btp)
{
unregister_shrinker(&btp->bt_shrinker);
ASSERT(percpu_counter_sum(&btp->bt_io_count) == 0);
percpu_counter_destroy(&btp->bt_io_count);
list_lru_destroy(&btp->bt_lru);
xfs_blkdev_issue_flush(btp);
kmem_free(btp);
}
int
xfs_setsize_buftarg(
xfs_buftarg_t *btp,
unsigned int sectorsize)
{
btp->bt_meta_sectorsize = sectorsize;
btp->bt_meta_sectormask = sectorsize - 1;
if (set_blocksize(btp->bt_bdev, sectorsize)) {
xfs_warn(btp->bt_mount,
"Cannot set_blocksize to %u on device %pg",
sectorsize, btp->bt_bdev);
return -EINVAL;
}
btp->bt_logical_sectorsize = bdev_logical_block_size(btp->bt_bdev);
btp->bt_logical_sectormask = bdev_logical_block_size(btp->bt_bdev) - 1;
return 0;
}
STATIC int
xfs_setsize_buftarg_early(
xfs_buftarg_t *btp,
struct block_device *bdev)
{
return xfs_setsize_buftarg(btp, bdev_logical_block_size(bdev));
}
xfs_buftarg_t *
xfs_alloc_buftarg(
struct xfs_mount *mp,
struct block_device *bdev)
{
xfs_buftarg_t *btp;
btp = kmem_zalloc(sizeof(*btp), KM_SLEEP | KM_NOFS);
btp->bt_mount = mp;
btp->bt_dev = bdev->bd_dev;
btp->bt_bdev = bdev;
if (xfs_setsize_buftarg_early(btp, bdev))
goto error;
if (list_lru_init(&btp->bt_lru))
goto error;
if (percpu_counter_init(&btp->bt_io_count, 0, GFP_KERNEL))
goto error;
btp->bt_shrinker.count_objects = xfs_buftarg_shrink_count;
btp->bt_shrinker.scan_objects = xfs_buftarg_shrink_scan;
btp->bt_shrinker.seeks = DEFAULT_SEEKS;
btp->bt_shrinker.flags = SHRINKER_NUMA_AWARE;
register_shrinker(&btp->bt_shrinker);
return btp;
error:
kmem_free(btp);
return NULL;
}
void
xfs_buf_delwri_cancel(
struct list_head *list)
{
struct xfs_buf *bp;
while (!list_empty(list)) {
bp = list_first_entry(list, struct xfs_buf, b_list);
xfs_buf_lock(bp);
bp->b_flags &= ~_XBF_DELWRI_Q;
list_del_init(&bp->b_list);
xfs_buf_relse(bp);
}
}
bool
xfs_buf_delwri_queue(
struct xfs_buf *bp,
struct list_head *list)
{
ASSERT(xfs_buf_islocked(bp));
ASSERT(!(bp->b_flags & XBF_READ));
if (bp->b_flags & _XBF_DELWRI_Q) {
trace_xfs_buf_delwri_queued(bp, _RET_IP_);
return false;
}
trace_xfs_buf_delwri_queue(bp, _RET_IP_);
bp->b_flags |= _XBF_DELWRI_Q;
if (list_empty(&bp->b_list)) {
atomic_inc(&bp->b_hold);
list_add_tail(&bp->b_list, list);
}
return true;
}
static int
xfs_buf_cmp(
void *priv,
struct list_head *a,
struct list_head *b)
{
struct xfs_buf *ap = container_of(a, struct xfs_buf, b_list);
struct xfs_buf *bp = container_of(b, struct xfs_buf, b_list);
xfs_daddr_t diff;
diff = ap->b_maps[0].bm_bn - bp->b_maps[0].bm_bn;
if (diff < 0)
return -1;
if (diff > 0)
return 1;
return 0;
}
static int
xfs_buf_delwri_submit_buffers(
struct list_head *buffer_list,
struct list_head *wait_list)
{
struct xfs_buf *bp, *n;
LIST_HEAD (submit_list);
int pinned = 0;
struct blk_plug plug;
list_sort(NULL, buffer_list, xfs_buf_cmp);
blk_start_plug(&plug);
list_for_each_entry_safe(bp, n, buffer_list, b_list) {
if (!wait_list) {
if (xfs_buf_ispinned(bp)) {
pinned++;
continue;
}
if (!xfs_buf_trylock(bp))
continue;
} else {
xfs_buf_lock(bp);
}
if (!(bp->b_flags & _XBF_DELWRI_Q)) {
list_del_init(&bp->b_list);
xfs_buf_relse(bp);
continue;
}
trace_xfs_buf_delwri_split(bp, _RET_IP_);
bp->b_flags &= ~(_XBF_DELWRI_Q | XBF_WRITE_FAIL);
bp->b_flags |= XBF_WRITE | XBF_ASYNC;
if (wait_list) {
xfs_buf_hold(bp);
list_move_tail(&bp->b_list, wait_list);
} else
list_del_init(&bp->b_list);
xfs_buf_submit(bp);
}
blk_finish_plug(&plug);
return pinned;
}
int
xfs_buf_delwri_submit_nowait(
struct list_head *buffer_list)
{
return xfs_buf_delwri_submit_buffers(buffer_list, NULL);
}
int
xfs_buf_delwri_submit(
struct list_head *buffer_list)
{
LIST_HEAD (wait_list);
int error = 0, error2;
struct xfs_buf *bp;
xfs_buf_delwri_submit_buffers(buffer_list, &wait_list);
while (!list_empty(&wait_list)) {
bp = list_first_entry(&wait_list, struct xfs_buf, b_list);
list_del_init(&bp->b_list);
xfs_buf_lock(bp);
error2 = bp->b_error;
xfs_buf_relse(bp);
if (!error)
error = error2;
}
return error;
}
int
xfs_buf_delwri_pushbuf(
struct xfs_buf *bp,
struct list_head *buffer_list)
{
LIST_HEAD (submit_list);
int error;
ASSERT(bp->b_flags & _XBF_DELWRI_Q);
trace_xfs_buf_delwri_pushbuf(bp, _RET_IP_);
xfs_buf_lock(bp);
list_move(&bp->b_list, &submit_list);
xfs_buf_unlock(bp);
xfs_buf_delwri_submit_buffers(&submit_list, buffer_list);
xfs_buf_lock(bp);
error = bp->b_error;
bp->b_flags |= _XBF_DELWRI_Q;
xfs_buf_unlock(bp);
return error;
}
int __init
xfs_buf_init(void)
{
xfs_buf_zone = kmem_zone_init_flags(sizeof(xfs_buf_t), "xfs_buf",
KM_ZONE_HWALIGN, NULL);
if (!xfs_buf_zone)
goto out;
return 0;
out:
return -ENOMEM;
}
void
xfs_buf_terminate(void)
{
kmem_zone_destroy(xfs_buf_zone);
}
