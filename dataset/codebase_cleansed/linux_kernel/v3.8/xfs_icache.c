STATIC struct xfs_inode *
xfs_inode_alloc(
struct xfs_mount *mp,
xfs_ino_t ino)
{
struct xfs_inode *ip;
ip = kmem_zone_alloc(xfs_inode_zone, KM_SLEEP);
if (!ip)
return NULL;
if (inode_init_always(mp->m_super, VFS_I(ip))) {
kmem_zone_free(xfs_inode_zone, ip);
return NULL;
}
ASSERT(atomic_read(&ip->i_pincount) == 0);
ASSERT(!spin_is_locked(&ip->i_flags_lock));
ASSERT(!xfs_isiflocked(ip));
ASSERT(ip->i_ino == 0);
mrlock_init(&ip->i_iolock, MRLOCK_BARRIER, "xfsio", ip->i_ino);
ip->i_ino = ino;
ip->i_mount = mp;
memset(&ip->i_imap, 0, sizeof(struct xfs_imap));
ip->i_afp = NULL;
memset(&ip->i_df, 0, sizeof(xfs_ifork_t));
ip->i_flags = 0;
ip->i_delayed_blks = 0;
memset(&ip->i_d, 0, sizeof(xfs_icdinode_t));
return ip;
}
STATIC void
xfs_inode_free_callback(
struct rcu_head *head)
{
struct inode *inode = container_of(head, struct inode, i_rcu);
struct xfs_inode *ip = XFS_I(inode);
kmem_zone_free(xfs_inode_zone, ip);
}
STATIC void
xfs_inode_free(
struct xfs_inode *ip)
{
switch (ip->i_d.di_mode & S_IFMT) {
case S_IFREG:
case S_IFDIR:
case S_IFLNK:
xfs_idestroy_fork(ip, XFS_DATA_FORK);
break;
}
if (ip->i_afp)
xfs_idestroy_fork(ip, XFS_ATTR_FORK);
if (ip->i_itemp) {
ASSERT(!(ip->i_itemp->ili_item.li_flags & XFS_LI_IN_AIL));
xfs_inode_item_destroy(ip);
ip->i_itemp = NULL;
}
ASSERT(atomic_read(&ip->i_pincount) == 0);
ASSERT(!spin_is_locked(&ip->i_flags_lock));
ASSERT(!xfs_isiflocked(ip));
spin_lock(&ip->i_flags_lock);
ip->i_flags = XFS_IRECLAIM;
ip->i_ino = 0;
spin_unlock(&ip->i_flags_lock);
call_rcu(&VFS_I(ip)->i_rcu, xfs_inode_free_callback);
}
static int
xfs_iget_cache_hit(
struct xfs_perag *pag,
struct xfs_inode *ip,
xfs_ino_t ino,
int flags,
int lock_flags) __releases(RCU)
{
struct inode *inode = VFS_I(ip);
struct xfs_mount *mp = ip->i_mount;
int error;
spin_lock(&ip->i_flags_lock);
if (ip->i_ino != ino) {
trace_xfs_iget_skip(ip);
XFS_STATS_INC(xs_ig_frecycle);
error = EAGAIN;
goto out_error;
}
if (ip->i_flags & (XFS_INEW|XFS_IRECLAIM)) {
trace_xfs_iget_skip(ip);
XFS_STATS_INC(xs_ig_frecycle);
error = EAGAIN;
goto out_error;
}
if (ip->i_d.di_mode == 0 && !(flags & XFS_IGET_CREATE)) {
error = ENOENT;
goto out_error;
}
if (ip->i_flags & XFS_IRECLAIMABLE) {
trace_xfs_iget_reclaim(ip);
ip->i_flags |= XFS_IRECLAIM;
spin_unlock(&ip->i_flags_lock);
rcu_read_unlock();
error = -inode_init_always(mp->m_super, inode);
if (error) {
rcu_read_lock();
spin_lock(&ip->i_flags_lock);
ip->i_flags &= ~(XFS_INEW | XFS_IRECLAIM);
ASSERT(ip->i_flags & XFS_IRECLAIMABLE);
trace_xfs_iget_reclaim_fail(ip);
goto out_error;
}
spin_lock(&pag->pag_ici_lock);
spin_lock(&ip->i_flags_lock);
ip->i_flags &= ~XFS_IRECLAIM_RESET_FLAGS;
ip->i_flags |= XFS_INEW;
__xfs_inode_clear_reclaim_tag(mp, pag, ip);
inode->i_state = I_NEW;
ASSERT(!rwsem_is_locked(&ip->i_iolock.mr_lock));
mrlock_init(&ip->i_iolock, MRLOCK_BARRIER, "xfsio", ip->i_ino);
spin_unlock(&ip->i_flags_lock);
spin_unlock(&pag->pag_ici_lock);
} else {
if (!igrab(inode)) {
trace_xfs_iget_skip(ip);
error = EAGAIN;
goto out_error;
}
spin_unlock(&ip->i_flags_lock);
rcu_read_unlock();
trace_xfs_iget_hit(ip);
}
if (lock_flags != 0)
xfs_ilock(ip, lock_flags);
xfs_iflags_clear(ip, XFS_ISTALE | XFS_IDONTCACHE);
XFS_STATS_INC(xs_ig_found);
return 0;
out_error:
spin_unlock(&ip->i_flags_lock);
rcu_read_unlock();
return error;
}
static int
xfs_iget_cache_miss(
struct xfs_mount *mp,
struct xfs_perag *pag,
xfs_trans_t *tp,
xfs_ino_t ino,
struct xfs_inode **ipp,
int flags,
int lock_flags)
{
struct xfs_inode *ip;
int error;
xfs_agino_t agino = XFS_INO_TO_AGINO(mp, ino);
int iflags;
ip = xfs_inode_alloc(mp, ino);
if (!ip)
return ENOMEM;
error = xfs_iread(mp, tp, ip, flags);
if (error)
goto out_destroy;
trace_xfs_iget_miss(ip);
if ((ip->i_d.di_mode == 0) && !(flags & XFS_IGET_CREATE)) {
error = ENOENT;
goto out_destroy;
}
if (radix_tree_preload(GFP_NOFS)) {
error = EAGAIN;
goto out_destroy;
}
if (lock_flags) {
if (!xfs_ilock_nowait(ip, lock_flags))
BUG();
}
iflags = XFS_INEW;
if (flags & XFS_IGET_DONTCACHE)
iflags |= XFS_IDONTCACHE;
ip->i_udquot = ip->i_gdquot = NULL;
xfs_iflags_set(ip, iflags);
spin_lock(&pag->pag_ici_lock);
error = radix_tree_insert(&pag->pag_ici_root, agino, ip);
if (unlikely(error)) {
WARN_ON(error != -EEXIST);
XFS_STATS_INC(xs_ig_dup);
error = EAGAIN;
goto out_preload_end;
}
spin_unlock(&pag->pag_ici_lock);
radix_tree_preload_end();
*ipp = ip;
return 0;
out_preload_end:
spin_unlock(&pag->pag_ici_lock);
radix_tree_preload_end();
if (lock_flags)
xfs_iunlock(ip, lock_flags);
out_destroy:
__destroy_inode(VFS_I(ip));
xfs_inode_free(ip);
return error;
}
int
xfs_iget(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_ino_t ino,
uint flags,
uint lock_flags,
xfs_inode_t **ipp)
{
xfs_inode_t *ip;
int error;
xfs_perag_t *pag;
xfs_agino_t agino;
ASSERT((lock_flags & (XFS_IOLOCK_EXCL | XFS_IOLOCK_SHARED)) == 0);
if (!ino || XFS_INO_TO_AGNO(mp, ino) >= mp->m_sb.sb_agcount)
return EINVAL;
pag = xfs_perag_get(mp, XFS_INO_TO_AGNO(mp, ino));
agino = XFS_INO_TO_AGINO(mp, ino);
again:
error = 0;
rcu_read_lock();
ip = radix_tree_lookup(&pag->pag_ici_root, agino);
if (ip) {
error = xfs_iget_cache_hit(pag, ip, ino, flags, lock_flags);
if (error)
goto out_error_or_again;
} else {
rcu_read_unlock();
XFS_STATS_INC(xs_ig_missed);
error = xfs_iget_cache_miss(mp, pag, tp, ino, &ip,
flags, lock_flags);
if (error)
goto out_error_or_again;
}
xfs_perag_put(pag);
*ipp = ip;
if (xfs_iflags_test(ip, XFS_INEW) && ip->i_d.di_mode != 0)
xfs_setup_inode(ip);
return 0;
out_error_or_again:
if (error == EAGAIN) {
delay(1);
goto again;
}
xfs_perag_put(pag);
return error;
}
STATIC int
xfs_inode_ag_walk_grab(
struct xfs_inode *ip)
{
struct inode *inode = VFS_I(ip);
ASSERT(rcu_read_lock_held());
spin_lock(&ip->i_flags_lock);
if (!ip->i_ino)
goto out_unlock_noent;
if (__xfs_iflags_test(ip, XFS_INEW | XFS_IRECLAIMABLE | XFS_IRECLAIM))
goto out_unlock_noent;
spin_unlock(&ip->i_flags_lock);
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
return EFSCORRUPTED;
if (!igrab(inode))
return ENOENT;
if (is_bad_inode(inode)) {
IRELE(ip);
return ENOENT;
}
return 0;
out_unlock_noent:
spin_unlock(&ip->i_flags_lock);
return ENOENT;
}
STATIC int
xfs_inode_ag_walk(
struct xfs_mount *mp,
struct xfs_perag *pag,
int (*execute)(struct xfs_inode *ip,
struct xfs_perag *pag, int flags,
void *args),
int flags,
void *args,
int tag)
{
uint32_t first_index;
int last_error = 0;
int skipped;
int done;
int nr_found;
restart:
done = 0;
skipped = 0;
first_index = 0;
nr_found = 0;
do {
struct xfs_inode *batch[XFS_LOOKUP_BATCH];
int error = 0;
int i;
rcu_read_lock();
if (tag == -1)
nr_found = radix_tree_gang_lookup(&pag->pag_ici_root,
(void **)batch, first_index,
XFS_LOOKUP_BATCH);
else
nr_found = radix_tree_gang_lookup_tag(
&pag->pag_ici_root,
(void **) batch, first_index,
XFS_LOOKUP_BATCH, tag);
if (!nr_found) {
rcu_read_unlock();
break;
}
for (i = 0; i < nr_found; i++) {
struct xfs_inode *ip = batch[i];
if (done || xfs_inode_ag_walk_grab(ip))
batch[i] = NULL;
if (XFS_INO_TO_AGNO(mp, ip->i_ino) != pag->pag_agno)
continue;
first_index = XFS_INO_TO_AGINO(mp, ip->i_ino + 1);
if (first_index < XFS_INO_TO_AGINO(mp, ip->i_ino))
done = 1;
}
rcu_read_unlock();
for (i = 0; i < nr_found; i++) {
if (!batch[i])
continue;
error = execute(batch[i], pag, flags, args);
IRELE(batch[i]);
if (error == EAGAIN) {
skipped++;
continue;
}
if (error && last_error != EFSCORRUPTED)
last_error = error;
}
if (error == EFSCORRUPTED)
break;
cond_resched();
} while (nr_found && !done);
if (skipped) {
delay(1);
goto restart;
}
return last_error;
}
STATIC void
xfs_queue_eofblocks(
struct xfs_mount *mp)
{
rcu_read_lock();
if (radix_tree_tagged(&mp->m_perag_tree, XFS_ICI_EOFBLOCKS_TAG))
queue_delayed_work(mp->m_eofblocks_workqueue,
&mp->m_eofblocks_work,
msecs_to_jiffies(xfs_eofb_secs * 1000));
rcu_read_unlock();
}
void
xfs_eofblocks_worker(
struct work_struct *work)
{
struct xfs_mount *mp = container_of(to_delayed_work(work),
struct xfs_mount, m_eofblocks_work);
xfs_icache_free_eofblocks(mp, NULL);
xfs_queue_eofblocks(mp);
}
int
xfs_inode_ag_iterator(
struct xfs_mount *mp,
int (*execute)(struct xfs_inode *ip,
struct xfs_perag *pag, int flags,
void *args),
int flags,
void *args)
{
struct xfs_perag *pag;
int error = 0;
int last_error = 0;
xfs_agnumber_t ag;
ag = 0;
while ((pag = xfs_perag_get(mp, ag))) {
ag = pag->pag_agno + 1;
error = xfs_inode_ag_walk(mp, pag, execute, flags, args, -1);
xfs_perag_put(pag);
if (error) {
last_error = error;
if (error == EFSCORRUPTED)
break;
}
}
return XFS_ERROR(last_error);
}
int
xfs_inode_ag_iterator_tag(
struct xfs_mount *mp,
int (*execute)(struct xfs_inode *ip,
struct xfs_perag *pag, int flags,
void *args),
int flags,
void *args,
int tag)
{
struct xfs_perag *pag;
int error = 0;
int last_error = 0;
xfs_agnumber_t ag;
ag = 0;
while ((pag = xfs_perag_get_tag(mp, ag, tag))) {
ag = pag->pag_agno + 1;
error = xfs_inode_ag_walk(mp, pag, execute, flags, args, tag);
xfs_perag_put(pag);
if (error) {
last_error = error;
if (error == EFSCORRUPTED)
break;
}
}
return XFS_ERROR(last_error);
}
static void
xfs_reclaim_work_queue(
struct xfs_mount *mp)
{
rcu_read_lock();
if (radix_tree_tagged(&mp->m_perag_tree, XFS_ICI_RECLAIM_TAG)) {
queue_delayed_work(mp->m_reclaim_workqueue, &mp->m_reclaim_work,
msecs_to_jiffies(xfs_syncd_centisecs / 6 * 10));
}
rcu_read_unlock();
}
void
xfs_reclaim_worker(
struct work_struct *work)
{
struct xfs_mount *mp = container_of(to_delayed_work(work),
struct xfs_mount, m_reclaim_work);
xfs_reclaim_inodes(mp, SYNC_TRYLOCK);
xfs_reclaim_work_queue(mp);
}
static void
__xfs_inode_set_reclaim_tag(
struct xfs_perag *pag,
struct xfs_inode *ip)
{
radix_tree_tag_set(&pag->pag_ici_root,
XFS_INO_TO_AGINO(ip->i_mount, ip->i_ino),
XFS_ICI_RECLAIM_TAG);
if (!pag->pag_ici_reclaimable) {
spin_lock(&ip->i_mount->m_perag_lock);
radix_tree_tag_set(&ip->i_mount->m_perag_tree,
XFS_INO_TO_AGNO(ip->i_mount, ip->i_ino),
XFS_ICI_RECLAIM_TAG);
spin_unlock(&ip->i_mount->m_perag_lock);
xfs_reclaim_work_queue(ip->i_mount);
trace_xfs_perag_set_reclaim(ip->i_mount, pag->pag_agno,
-1, _RET_IP_);
}
pag->pag_ici_reclaimable++;
}
void
xfs_inode_set_reclaim_tag(
xfs_inode_t *ip)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_perag *pag;
pag = xfs_perag_get(mp, XFS_INO_TO_AGNO(mp, ip->i_ino));
spin_lock(&pag->pag_ici_lock);
spin_lock(&ip->i_flags_lock);
__xfs_inode_set_reclaim_tag(pag, ip);
__xfs_iflags_set(ip, XFS_IRECLAIMABLE);
spin_unlock(&ip->i_flags_lock);
spin_unlock(&pag->pag_ici_lock);
xfs_perag_put(pag);
}
STATIC void
__xfs_inode_clear_reclaim(
xfs_perag_t *pag,
xfs_inode_t *ip)
{
pag->pag_ici_reclaimable--;
if (!pag->pag_ici_reclaimable) {
spin_lock(&ip->i_mount->m_perag_lock);
radix_tree_tag_clear(&ip->i_mount->m_perag_tree,
XFS_INO_TO_AGNO(ip->i_mount, ip->i_ino),
XFS_ICI_RECLAIM_TAG);
spin_unlock(&ip->i_mount->m_perag_lock);
trace_xfs_perag_clear_reclaim(ip->i_mount, pag->pag_agno,
-1, _RET_IP_);
}
}
STATIC void
__xfs_inode_clear_reclaim_tag(
xfs_mount_t *mp,
xfs_perag_t *pag,
xfs_inode_t *ip)
{
radix_tree_tag_clear(&pag->pag_ici_root,
XFS_INO_TO_AGINO(mp, ip->i_ino), XFS_ICI_RECLAIM_TAG);
__xfs_inode_clear_reclaim(pag, ip);
}
STATIC int
xfs_reclaim_inode_grab(
struct xfs_inode *ip,
int flags)
{
ASSERT(rcu_read_lock_held());
if (!ip->i_ino)
return 1;
if ((flags & SYNC_TRYLOCK) &&
__xfs_iflags_test(ip, XFS_IFLOCK | XFS_IRECLAIM))
return 1;
spin_lock(&ip->i_flags_lock);
if (!__xfs_iflags_test(ip, XFS_IRECLAIMABLE) ||
__xfs_iflags_test(ip, XFS_IRECLAIM)) {
spin_unlock(&ip->i_flags_lock);
return 1;
}
__xfs_iflags_set(ip, XFS_IRECLAIM);
spin_unlock(&ip->i_flags_lock);
return 0;
}
STATIC int
xfs_reclaim_inode(
struct xfs_inode *ip,
struct xfs_perag *pag,
int sync_mode)
{
struct xfs_buf *bp = NULL;
int error;
restart:
error = 0;
xfs_ilock(ip, XFS_ILOCK_EXCL);
if (!xfs_iflock_nowait(ip)) {
if (!(sync_mode & SYNC_WAIT))
goto out;
xfs_iflock(ip);
}
if (is_bad_inode(VFS_I(ip)))
goto reclaim;
if (XFS_FORCED_SHUTDOWN(ip->i_mount)) {
xfs_iunpin_wait(ip);
xfs_iflush_abort(ip, false);
goto reclaim;
}
if (xfs_ipincount(ip)) {
if (!(sync_mode & SYNC_WAIT))
goto out_ifunlock;
xfs_iunpin_wait(ip);
}
if (xfs_iflags_test(ip, XFS_ISTALE))
goto reclaim;
if (xfs_inode_clean(ip))
goto reclaim;
if (!(sync_mode & SYNC_WAIT))
goto out_ifunlock;
error = xfs_iflush(ip, &bp);
if (error == EAGAIN) {
xfs_iunlock(ip, XFS_ILOCK_EXCL);
delay(2);
goto restart;
}
if (!error) {
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
}
xfs_iflock(ip);
reclaim:
xfs_ifunlock(ip);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
XFS_STATS_INC(xs_ig_reclaims);
spin_lock(&pag->pag_ici_lock);
if (!radix_tree_delete(&pag->pag_ici_root,
XFS_INO_TO_AGINO(ip->i_mount, ip->i_ino)))
ASSERT(0);
__xfs_inode_clear_reclaim(pag, ip);
spin_unlock(&pag->pag_ici_lock);
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_qm_dqdetach(ip);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
xfs_inode_free(ip);
return error;
out_ifunlock:
xfs_ifunlock(ip);
out:
xfs_iflags_clear(ip, XFS_IRECLAIM);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
}
STATIC int
xfs_reclaim_inodes_ag(
struct xfs_mount *mp,
int flags,
int *nr_to_scan)
{
struct xfs_perag *pag;
int error = 0;
int last_error = 0;
xfs_agnumber_t ag;
int trylock = flags & SYNC_TRYLOCK;
int skipped;
restart:
ag = 0;
skipped = 0;
while ((pag = xfs_perag_get_tag(mp, ag, XFS_ICI_RECLAIM_TAG))) {
unsigned long first_index = 0;
int done = 0;
int nr_found = 0;
ag = pag->pag_agno + 1;
if (trylock) {
if (!mutex_trylock(&pag->pag_ici_reclaim_lock)) {
skipped++;
xfs_perag_put(pag);
continue;
}
first_index = pag->pag_ici_reclaim_cursor;
} else
mutex_lock(&pag->pag_ici_reclaim_lock);
do {
struct xfs_inode *batch[XFS_LOOKUP_BATCH];
int i;
rcu_read_lock();
nr_found = radix_tree_gang_lookup_tag(
&pag->pag_ici_root,
(void **)batch, first_index,
XFS_LOOKUP_BATCH,
XFS_ICI_RECLAIM_TAG);
if (!nr_found) {
done = 1;
rcu_read_unlock();
break;
}
for (i = 0; i < nr_found; i++) {
struct xfs_inode *ip = batch[i];
if (done || xfs_reclaim_inode_grab(ip, flags))
batch[i] = NULL;
if (XFS_INO_TO_AGNO(mp, ip->i_ino) !=
pag->pag_agno)
continue;
first_index = XFS_INO_TO_AGINO(mp, ip->i_ino + 1);
if (first_index < XFS_INO_TO_AGINO(mp, ip->i_ino))
done = 1;
}
rcu_read_unlock();
for (i = 0; i < nr_found; i++) {
if (!batch[i])
continue;
error = xfs_reclaim_inode(batch[i], pag, flags);
if (error && last_error != EFSCORRUPTED)
last_error = error;
}
*nr_to_scan -= XFS_LOOKUP_BATCH;
cond_resched();
} while (nr_found && !done && *nr_to_scan > 0);
if (trylock && !done)
pag->pag_ici_reclaim_cursor = first_index;
else
pag->pag_ici_reclaim_cursor = 0;
mutex_unlock(&pag->pag_ici_reclaim_lock);
xfs_perag_put(pag);
}
if (skipped && (flags & SYNC_WAIT) && *nr_to_scan > 0) {
trylock = 0;
goto restart;
}
return XFS_ERROR(last_error);
}
int
xfs_reclaim_inodes(
xfs_mount_t *mp,
int mode)
{
int nr_to_scan = INT_MAX;
return xfs_reclaim_inodes_ag(mp, mode, &nr_to_scan);
}
void
xfs_reclaim_inodes_nr(
struct xfs_mount *mp,
int nr_to_scan)
{
xfs_reclaim_work_queue(mp);
xfs_ail_push_all(mp->m_ail);
xfs_reclaim_inodes_ag(mp, SYNC_TRYLOCK | SYNC_WAIT, &nr_to_scan);
}
int
xfs_reclaim_inodes_count(
struct xfs_mount *mp)
{
struct xfs_perag *pag;
xfs_agnumber_t ag = 0;
int reclaimable = 0;
while ((pag = xfs_perag_get_tag(mp, ag, XFS_ICI_RECLAIM_TAG))) {
ag = pag->pag_agno + 1;
reclaimable += pag->pag_ici_reclaimable;
xfs_perag_put(pag);
}
return reclaimable;
}
STATIC int
xfs_inode_match_id(
struct xfs_inode *ip,
struct xfs_eofblocks *eofb)
{
if (eofb->eof_flags & XFS_EOF_FLAGS_UID &&
ip->i_d.di_uid != eofb->eof_uid)
return 0;
if (eofb->eof_flags & XFS_EOF_FLAGS_GID &&
ip->i_d.di_gid != eofb->eof_gid)
return 0;
if (eofb->eof_flags & XFS_EOF_FLAGS_PRID &&
xfs_get_projid(ip) != eofb->eof_prid)
return 0;
return 1;
}
STATIC int
xfs_inode_free_eofblocks(
struct xfs_inode *ip,
struct xfs_perag *pag,
int flags,
void *args)
{
int ret;
struct xfs_eofblocks *eofb = args;
if (!xfs_can_free_eofblocks(ip, false)) {
trace_xfs_inode_free_eofblocks_invalid(ip);
xfs_inode_clear_eofblocks_tag(ip);
return 0;
}
if (!(flags & SYNC_WAIT) &&
mapping_tagged(VFS_I(ip)->i_mapping, PAGECACHE_TAG_DIRTY))
return 0;
if (eofb) {
if (!xfs_inode_match_id(ip, eofb))
return 0;
if (eofb->eof_flags & XFS_EOF_FLAGS_MINFILESIZE &&
XFS_ISIZE(ip) < eofb->eof_min_file_size)
return 0;
}
ret = xfs_free_eofblocks(ip->i_mount, ip, true);
if (ret == EAGAIN && !(flags & SYNC_WAIT))
ret = 0;
return ret;
}
int
xfs_icache_free_eofblocks(
struct xfs_mount *mp,
struct xfs_eofblocks *eofb)
{
int flags = SYNC_TRYLOCK;
if (eofb && (eofb->eof_flags & XFS_EOF_FLAGS_SYNC))
flags = SYNC_WAIT;
return xfs_inode_ag_iterator_tag(mp, xfs_inode_free_eofblocks, flags,
eofb, XFS_ICI_EOFBLOCKS_TAG);
}
void
xfs_inode_set_eofblocks_tag(
xfs_inode_t *ip)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_perag *pag;
int tagged;
pag = xfs_perag_get(mp, XFS_INO_TO_AGNO(mp, ip->i_ino));
spin_lock(&pag->pag_ici_lock);
trace_xfs_inode_set_eofblocks_tag(ip);
tagged = radix_tree_tagged(&pag->pag_ici_root,
XFS_ICI_EOFBLOCKS_TAG);
radix_tree_tag_set(&pag->pag_ici_root,
XFS_INO_TO_AGINO(ip->i_mount, ip->i_ino),
XFS_ICI_EOFBLOCKS_TAG);
if (!tagged) {
spin_lock(&ip->i_mount->m_perag_lock);
radix_tree_tag_set(&ip->i_mount->m_perag_tree,
XFS_INO_TO_AGNO(ip->i_mount, ip->i_ino),
XFS_ICI_EOFBLOCKS_TAG);
spin_unlock(&ip->i_mount->m_perag_lock);
xfs_queue_eofblocks(ip->i_mount);
trace_xfs_perag_set_eofblocks(ip->i_mount, pag->pag_agno,
-1, _RET_IP_);
}
spin_unlock(&pag->pag_ici_lock);
xfs_perag_put(pag);
}
void
xfs_inode_clear_eofblocks_tag(
xfs_inode_t *ip)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_perag *pag;
pag = xfs_perag_get(mp, XFS_INO_TO_AGNO(mp, ip->i_ino));
spin_lock(&pag->pag_ici_lock);
trace_xfs_inode_clear_eofblocks_tag(ip);
radix_tree_tag_clear(&pag->pag_ici_root,
XFS_INO_TO_AGINO(ip->i_mount, ip->i_ino),
XFS_ICI_EOFBLOCKS_TAG);
if (!radix_tree_tagged(&pag->pag_ici_root, XFS_ICI_EOFBLOCKS_TAG)) {
spin_lock(&ip->i_mount->m_perag_lock);
radix_tree_tag_clear(&ip->i_mount->m_perag_tree,
XFS_INO_TO_AGNO(ip->i_mount, ip->i_ino),
XFS_ICI_EOFBLOCKS_TAG);
spin_unlock(&ip->i_mount->m_perag_lock);
trace_xfs_perag_clear_eofblocks(ip->i_mount, pag->pag_agno,
-1, _RET_IP_);
}
spin_unlock(&pag->pag_ici_lock);
xfs_perag_put(pag);
}
