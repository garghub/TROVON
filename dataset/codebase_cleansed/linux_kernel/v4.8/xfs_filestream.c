int
xfs_filestream_peek_ag(
xfs_mount_t *mp,
xfs_agnumber_t agno)
{
struct xfs_perag *pag;
int ret;
pag = xfs_perag_get(mp, agno);
ret = atomic_read(&pag->pagf_fstrms);
xfs_perag_put(pag);
return ret;
}
static int
xfs_filestream_get_ag(
xfs_mount_t *mp,
xfs_agnumber_t agno)
{
struct xfs_perag *pag;
int ret;
pag = xfs_perag_get(mp, agno);
ret = atomic_inc_return(&pag->pagf_fstrms);
xfs_perag_put(pag);
return ret;
}
static void
xfs_filestream_put_ag(
xfs_mount_t *mp,
xfs_agnumber_t agno)
{
struct xfs_perag *pag;
pag = xfs_perag_get(mp, agno);
atomic_dec(&pag->pagf_fstrms);
xfs_perag_put(pag);
}
static void
xfs_fstrm_free_func(
struct xfs_mru_cache_elem *mru)
{
struct xfs_fstrm_item *item =
container_of(mru, struct xfs_fstrm_item, mru);
xfs_filestream_put_ag(item->ip->i_mount, item->ag);
trace_xfs_filestream_free(item->ip, item->ag);
kmem_free(item);
}
static int
xfs_filestream_pick_ag(
struct xfs_inode *ip,
xfs_agnumber_t startag,
xfs_agnumber_t *agp,
int flags,
xfs_extlen_t minlen)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_fstrm_item *item;
struct xfs_perag *pag;
xfs_extlen_t longest, free = 0, minfree, maxfree = 0;
xfs_agnumber_t ag, max_ag = NULLAGNUMBER;
int err, trylock, nscan;
ASSERT(S_ISDIR(VFS_I(ip)->i_mode));
minfree = mp->m_sb.sb_agblocks / 50;
ag = startag;
*agp = NULLAGNUMBER;
trylock = XFS_ALLOC_FLAG_TRYLOCK;
for (nscan = 0; 1; nscan++) {
trace_xfs_filestream_scan(ip, ag);
pag = xfs_perag_get(mp, ag);
if (!pag->pagf_init) {
err = xfs_alloc_pagf_init(mp, NULL, ag, trylock);
if (err && !trylock) {
xfs_perag_put(pag);
return err;
}
}
if (!pag->pagf_init)
goto next_ag;
if (pag->pagf_freeblks > maxfree) {
maxfree = pag->pagf_freeblks;
max_ag = ag;
}
if (xfs_filestream_get_ag(mp, ag) > 1) {
xfs_filestream_put_ag(mp, ag);
goto next_ag;
}
longest = xfs_alloc_longest_free_extent(mp, pag,
xfs_alloc_min_freelist(mp, pag));
if (((minlen && longest >= minlen) ||
(!minlen && pag->pagf_freeblks >= minfree)) &&
(!pag->pagf_metadata || !(flags & XFS_PICK_USERDATA) ||
(flags & XFS_PICK_LOWSPACE))) {
free = pag->pagf_freeblks;
xfs_perag_put(pag);
*agp = ag;
break;
}
xfs_filestream_put_ag(mp, ag);
next_ag:
xfs_perag_put(pag);
if (++ag >= mp->m_sb.sb_agcount)
ag = 0;
if (ag != startag)
continue;
if (trylock != 0) {
trylock = 0;
continue;
}
if (!(flags & XFS_PICK_LOWSPACE)) {
flags |= XFS_PICK_LOWSPACE;
continue;
}
if (max_ag != NULLAGNUMBER) {
xfs_filestream_get_ag(mp, max_ag);
free = maxfree;
*agp = max_ag;
break;
}
trace_xfs_filestream_pick(ip, *agp, free, nscan);
*agp = 0;
return 0;
}
trace_xfs_filestream_pick(ip, *agp, free, nscan);
if (*agp == NULLAGNUMBER)
return 0;
err = -ENOMEM;
item = kmem_alloc(sizeof(*item), KM_MAYFAIL);
if (!item)
goto out_put_ag;
item->ag = *agp;
item->ip = ip;
err = xfs_mru_cache_insert(mp->m_filestream, ip->i_ino, &item->mru);
if (err) {
if (err == -EEXIST)
err = 0;
goto out_free_item;
}
return 0;
out_free_item:
kmem_free(item);
out_put_ag:
xfs_filestream_put_ag(mp, *agp);
return err;
}
static struct xfs_inode *
xfs_filestream_get_parent(
struct xfs_inode *ip)
{
struct inode *inode = VFS_I(ip), *dir = NULL;
struct dentry *dentry, *parent;
dentry = d_find_alias(inode);
if (!dentry)
goto out;
parent = dget_parent(dentry);
if (!parent)
goto out_dput;
dir = igrab(d_inode(parent));
dput(parent);
out_dput:
dput(dentry);
out:
return dir ? XFS_I(dir) : NULL;
}
xfs_agnumber_t
xfs_filestream_lookup_ag(
struct xfs_inode *ip)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_inode *pip = NULL;
xfs_agnumber_t startag, ag = NULLAGNUMBER;
struct xfs_mru_cache_elem *mru;
ASSERT(S_ISREG(VFS_I(ip)->i_mode));
pip = xfs_filestream_get_parent(ip);
if (!pip)
return NULLAGNUMBER;
mru = xfs_mru_cache_lookup(mp->m_filestream, pip->i_ino);
if (mru) {
ag = container_of(mru, struct xfs_fstrm_item, mru)->ag;
xfs_mru_cache_done(mp->m_filestream);
trace_xfs_filestream_lookup(ip, ag);
goto out;
}
if (mp->m_flags & XFS_MOUNT_32BITINODES) {
xfs_agnumber_t rotorstep = xfs_rotorstep;
startag = (mp->m_agfrotor / rotorstep) % mp->m_sb.sb_agcount;
mp->m_agfrotor = (mp->m_agfrotor + 1) %
(mp->m_sb.sb_agcount * rotorstep);
} else
startag = XFS_INO_TO_AGNO(mp, pip->i_ino);
if (xfs_filestream_pick_ag(pip, startag, &ag, 0, 0))
ag = NULLAGNUMBER;
out:
IRELE(pip);
return ag;
}
int
xfs_filestream_new_ag(
struct xfs_bmalloca *ap,
xfs_agnumber_t *agp)
{
struct xfs_inode *ip = ap->ip, *pip;
struct xfs_mount *mp = ip->i_mount;
xfs_extlen_t minlen = ap->length;
xfs_agnumber_t startag = 0;
int flags, err = 0;
struct xfs_mru_cache_elem *mru;
*agp = NULLAGNUMBER;
pip = xfs_filestream_get_parent(ip);
if (!pip)
goto exit;
mru = xfs_mru_cache_remove(mp->m_filestream, pip->i_ino);
if (mru) {
struct xfs_fstrm_item *item =
container_of(mru, struct xfs_fstrm_item, mru);
startag = (item->ag + 1) % mp->m_sb.sb_agcount;
}
flags = (ap->userdata ? XFS_PICK_USERDATA : 0) |
(ap->dfops->dop_low ? XFS_PICK_LOWSPACE : 0);
err = xfs_filestream_pick_ag(pip, startag, agp, flags, minlen);
if (mru)
xfs_fstrm_free_func(mru);
IRELE(pip);
exit:
if (*agp == NULLAGNUMBER)
*agp = 0;
return err;
}
void
xfs_filestream_deassociate(
struct xfs_inode *ip)
{
xfs_mru_cache_delete(ip->i_mount->m_filestream, ip->i_ino);
}
int
xfs_filestream_mount(
xfs_mount_t *mp)
{
return xfs_mru_cache_create(&mp->m_filestream, xfs_fstrm_centisecs * 10,
10, xfs_fstrm_free_func);
}
void
xfs_filestream_unmount(
xfs_mount_t *mp)
{
xfs_mru_cache_destroy(mp->m_filestream);
}
