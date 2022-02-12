STATIC int
xfs_attr_name_to_xname(
struct xfs_name *xname,
const unsigned char *aname)
{
if (!aname)
return EINVAL;
xname->name = aname;
xname->len = strlen((char *)aname);
if (xname->len >= MAXNAMELEN)
return EFAULT;
return 0;
}
int
xfs_inode_hasattr(
struct xfs_inode *ip)
{
if (!XFS_IFORK_Q(ip) ||
(ip->i_d.di_aformat == XFS_DINODE_FMT_EXTENTS &&
ip->i_d.di_anextents == 0))
return 0;
return 1;
}
STATIC int
xfs_attr_get_int(
struct xfs_inode *ip,
struct xfs_name *name,
unsigned char *value,
int *valuelenp,
int flags)
{
xfs_da_args_t args;
int error;
if (!xfs_inode_hasattr(ip))
return ENOATTR;
memset((char *)&args, 0, sizeof(args));
args.name = name->name;
args.namelen = name->len;
args.value = value;
args.valuelen = *valuelenp;
args.flags = flags;
args.hashval = xfs_da_hashname(args.name, args.namelen);
args.dp = ip;
args.whichfork = XFS_ATTR_FORK;
if (ip->i_d.di_aformat == XFS_DINODE_FMT_LOCAL) {
error = xfs_attr_shortform_getvalue(&args);
} else if (xfs_bmap_one_block(ip, XFS_ATTR_FORK)) {
error = xfs_attr_leaf_get(&args);
} else {
error = xfs_attr_node_get(&args);
}
*valuelenp = args.valuelen;
if (error == EEXIST)
error = 0;
return(error);
}
int
xfs_attr_get(
xfs_inode_t *ip,
const unsigned char *name,
unsigned char *value,
int *valuelenp,
int flags)
{
int error;
struct xfs_name xname;
XFS_STATS_INC(xs_attr_get);
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
return(EIO);
error = xfs_attr_name_to_xname(&xname, name);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_SHARED);
error = xfs_attr_get_int(ip, &xname, value, valuelenp, flags);
xfs_iunlock(ip, XFS_ILOCK_SHARED);
return(error);
}
STATIC int
xfs_attr_calc_size(
struct xfs_inode *ip,
int namelen,
int valuelen,
int *local)
{
struct xfs_mount *mp = ip->i_mount;
int size;
int nblks;
size = xfs_attr_leaf_newentsize(namelen, valuelen,
mp->m_sb.sb_blocksize, local);
nblks = XFS_DAENTER_SPACE_RES(mp, XFS_ATTR_FORK);
if (*local) {
if (size > (mp->m_sb.sb_blocksize >> 1)) {
nblks *= 2;
}
} else {
uint dblocks = XFS_B_TO_FSB(mp, valuelen);
nblks += dblocks;
nblks += XFS_NEXTENTADD_SPACE_RES(mp, dblocks, XFS_ATTR_FORK);
}
return nblks;
}
STATIC int
xfs_attr_set_int(
struct xfs_inode *dp,
struct xfs_name *name,
unsigned char *value,
int valuelen,
int flags)
{
xfs_da_args_t args;
xfs_fsblock_t firstblock;
xfs_bmap_free_t flist;
int error, err2, committed;
struct xfs_mount *mp = dp->i_mount;
struct xfs_trans_res tres;
int rsvd = (flags & ATTR_ROOT) != 0;
int local;
error = xfs_qm_dqattach(dp, 0);
if (error)
return error;
if (XFS_IFORK_Q(dp) == 0) {
int sf_size = sizeof(xfs_attr_sf_hdr_t) +
XFS_ATTR_SF_ENTSIZE_BYNAME(name->len, valuelen);
if ((error = xfs_bmap_add_attrfork(dp, sf_size, rsvd)))
return(error);
}
memset((char *)&args, 0, sizeof(args));
args.name = name->name;
args.namelen = name->len;
args.value = value;
args.valuelen = valuelen;
args.flags = flags;
args.hashval = xfs_da_hashname(args.name, args.namelen);
args.dp = dp;
args.firstblock = &firstblock;
args.flist = &flist;
args.whichfork = XFS_ATTR_FORK;
args.op_flags = XFS_DA_OP_ADDNAME | XFS_DA_OP_OKNOENT;
args.total = xfs_attr_calc_size(dp, name->len, valuelen, &local);
args.trans = xfs_trans_alloc(mp, XFS_TRANS_ATTR_SET);
if (rsvd)
args.trans->t_flags |= XFS_TRANS_RESERVE;
tres.tr_logres = M_RES(mp)->tr_attrsetm.tr_logres +
M_RES(mp)->tr_attrsetrt.tr_logres * args.total;
tres.tr_logcount = XFS_ATTRSET_LOG_COUNT;
tres.tr_logflags = XFS_TRANS_PERM_LOG_RES;
error = xfs_trans_reserve(args.trans, &tres, args.total, 0);
if (error) {
xfs_trans_cancel(args.trans, 0);
return(error);
}
xfs_ilock(dp, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota_nblks(args.trans, dp, args.total, 0,
rsvd ? XFS_QMOPT_RES_REGBLKS | XFS_QMOPT_FORCE_RES :
XFS_QMOPT_RES_REGBLKS);
if (error) {
xfs_iunlock(dp, XFS_ILOCK_EXCL);
xfs_trans_cancel(args.trans, XFS_TRANS_RELEASE_LOG_RES);
return (error);
}
xfs_trans_ijoin(args.trans, dp, 0);
if ((dp->i_d.di_aformat == XFS_DINODE_FMT_LOCAL) ||
((dp->i_d.di_aformat == XFS_DINODE_FMT_EXTENTS) &&
(dp->i_d.di_anextents == 0))) {
if (dp->i_d.di_aformat == XFS_DINODE_FMT_EXTENTS)
xfs_attr_shortform_create(&args);
error = xfs_attr_shortform_addname(&args);
if (error != ENOSPC) {
ASSERT(args.trans != NULL);
if (mp->m_flags & XFS_MOUNT_WSYNC) {
xfs_trans_set_sync(args.trans);
}
if (!error && (flags & ATTR_KERNOTIME) == 0) {
xfs_trans_ichgtime(args.trans, dp,
XFS_ICHGTIME_CHG);
}
err2 = xfs_trans_commit(args.trans,
XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(dp, XFS_ILOCK_EXCL);
return(error == 0 ? err2 : error);
}
xfs_bmap_init(args.flist, args.firstblock);
error = xfs_attr_shortform_to_leaf(&args);
if (!error) {
error = xfs_bmap_finish(&args.trans, args.flist,
&committed);
}
if (error) {
ASSERT(committed);
args.trans = NULL;
xfs_bmap_cancel(&flist);
goto out;
}
if (committed)
xfs_trans_ijoin(args.trans, dp, 0);
error = xfs_trans_roll(&args.trans, dp);
if (error)
goto out;
}
if (xfs_bmap_one_block(dp, XFS_ATTR_FORK)) {
error = xfs_attr_leaf_addname(&args);
} else {
error = xfs_attr_node_addname(&args);
}
if (error) {
goto out;
}
if (mp->m_flags & XFS_MOUNT_WSYNC) {
xfs_trans_set_sync(args.trans);
}
if ((flags & ATTR_KERNOTIME) == 0)
xfs_trans_ichgtime(args.trans, dp, XFS_ICHGTIME_CHG);
xfs_trans_log_inode(args.trans, dp, XFS_ILOG_CORE);
error = xfs_trans_commit(args.trans, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(dp, XFS_ILOCK_EXCL);
return(error);
out:
if (args.trans)
xfs_trans_cancel(args.trans,
XFS_TRANS_RELEASE_LOG_RES|XFS_TRANS_ABORT);
xfs_iunlock(dp, XFS_ILOCK_EXCL);
return(error);
}
int
xfs_attr_set(
xfs_inode_t *dp,
const unsigned char *name,
unsigned char *value,
int valuelen,
int flags)
{
int error;
struct xfs_name xname;
XFS_STATS_INC(xs_attr_set);
if (XFS_FORCED_SHUTDOWN(dp->i_mount))
return (EIO);
error = xfs_attr_name_to_xname(&xname, name);
if (error)
return error;
return xfs_attr_set_int(dp, &xname, value, valuelen, flags);
}
STATIC int
xfs_attr_remove_int(xfs_inode_t *dp, struct xfs_name *name, int flags)
{
xfs_da_args_t args;
xfs_fsblock_t firstblock;
xfs_bmap_free_t flist;
int error;
xfs_mount_t *mp = dp->i_mount;
memset((char *)&args, 0, sizeof(args));
args.name = name->name;
args.namelen = name->len;
args.flags = flags;
args.hashval = xfs_da_hashname(args.name, args.namelen);
args.dp = dp;
args.firstblock = &firstblock;
args.flist = &flist;
args.total = 0;
args.whichfork = XFS_ATTR_FORK;
args.op_flags = XFS_DA_OP_OKNOENT;
error = xfs_qm_dqattach(dp, 0);
if (error)
return error;
args.trans = xfs_trans_alloc(mp, XFS_TRANS_ATTR_RM);
if (flags & ATTR_ROOT)
args.trans->t_flags |= XFS_TRANS_RESERVE;
error = xfs_trans_reserve(args.trans, &M_RES(mp)->tr_attrrm,
XFS_ATTRRM_SPACE_RES(mp), 0);
if (error) {
xfs_trans_cancel(args.trans, 0);
return(error);
}
xfs_ilock(dp, XFS_ILOCK_EXCL);
xfs_trans_ijoin(args.trans, dp, 0);
if (!xfs_inode_hasattr(dp)) {
error = XFS_ERROR(ENOATTR);
goto out;
}
if (dp->i_d.di_aformat == XFS_DINODE_FMT_LOCAL) {
ASSERT(dp->i_afp->if_flags & XFS_IFINLINE);
error = xfs_attr_shortform_remove(&args);
if (error) {
goto out;
}
} else if (xfs_bmap_one_block(dp, XFS_ATTR_FORK)) {
error = xfs_attr_leaf_removename(&args);
} else {
error = xfs_attr_node_removename(&args);
}
if (error) {
goto out;
}
if (mp->m_flags & XFS_MOUNT_WSYNC) {
xfs_trans_set_sync(args.trans);
}
if ((flags & ATTR_KERNOTIME) == 0)
xfs_trans_ichgtime(args.trans, dp, XFS_ICHGTIME_CHG);
xfs_trans_log_inode(args.trans, dp, XFS_ILOG_CORE);
error = xfs_trans_commit(args.trans, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(dp, XFS_ILOCK_EXCL);
return(error);
out:
if (args.trans)
xfs_trans_cancel(args.trans,
XFS_TRANS_RELEASE_LOG_RES|XFS_TRANS_ABORT);
xfs_iunlock(dp, XFS_ILOCK_EXCL);
return(error);
}
int
xfs_attr_remove(
xfs_inode_t *dp,
const unsigned char *name,
int flags)
{
int error;
struct xfs_name xname;
XFS_STATS_INC(xs_attr_remove);
if (XFS_FORCED_SHUTDOWN(dp->i_mount))
return (EIO);
error = xfs_attr_name_to_xname(&xname, name);
if (error)
return error;
xfs_ilock(dp, XFS_ILOCK_SHARED);
if (!xfs_inode_hasattr(dp)) {
xfs_iunlock(dp, XFS_ILOCK_SHARED);
return XFS_ERROR(ENOATTR);
}
xfs_iunlock(dp, XFS_ILOCK_SHARED);
return xfs_attr_remove_int(dp, &xname, flags);
}
STATIC int
xfs_attr_shortform_addname(xfs_da_args_t *args)
{
int newsize, forkoff, retval;
trace_xfs_attr_sf_addname(args);
retval = xfs_attr_shortform_lookup(args);
if ((args->flags & ATTR_REPLACE) && (retval == ENOATTR)) {
return(retval);
} else if (retval == EEXIST) {
if (args->flags & ATTR_CREATE)
return(retval);
retval = xfs_attr_shortform_remove(args);
ASSERT(retval == 0);
}
if (args->namelen >= XFS_ATTR_SF_ENTSIZE_MAX ||
args->valuelen >= XFS_ATTR_SF_ENTSIZE_MAX)
return(XFS_ERROR(ENOSPC));
newsize = XFS_ATTR_SF_TOTSIZE(args->dp);
newsize += XFS_ATTR_SF_ENTSIZE_BYNAME(args->namelen, args->valuelen);
forkoff = xfs_attr_shortform_bytesfit(args->dp, newsize);
if (!forkoff)
return(XFS_ERROR(ENOSPC));
xfs_attr_shortform_add(args, forkoff);
return(0);
}
STATIC int
xfs_attr_leaf_addname(xfs_da_args_t *args)
{
xfs_inode_t *dp;
struct xfs_buf *bp;
int retval, error, committed, forkoff;
trace_xfs_attr_leaf_addname(args);
dp = args->dp;
args->blkno = 0;
error = xfs_attr3_leaf_read(args->trans, args->dp, args->blkno, -1, &bp);
if (error)
return error;
retval = xfs_attr3_leaf_lookup_int(bp, args);
if ((args->flags & ATTR_REPLACE) && (retval == ENOATTR)) {
xfs_trans_brelse(args->trans, bp);
return retval;
} else if (retval == EEXIST) {
if (args->flags & ATTR_CREATE) {
xfs_trans_brelse(args->trans, bp);
return retval;
}
trace_xfs_attr_leaf_replace(args);
args->op_flags |= XFS_DA_OP_RENAME;
args->blkno2 = args->blkno;
args->index2 = args->index;
args->rmtblkno2 = args->rmtblkno;
args->rmtblkcnt2 = args->rmtblkcnt;
}
retval = xfs_attr3_leaf_add(bp, args);
if (retval == ENOSPC) {
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_attr3_leaf_to_node(args);
if (!error) {
error = xfs_bmap_finish(&args->trans, args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
return(error);
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
error = xfs_trans_roll(&args->trans, dp);
if (error)
return (error);
error = xfs_attr_node_addname(args);
return(error);
}
error = xfs_trans_roll(&args->trans, dp);
if (error)
return (error);
if (args->rmtblkno > 0) {
error = xfs_attr_rmtval_set(args);
if (error)
return(error);
}
if (args->op_flags & XFS_DA_OP_RENAME) {
error = xfs_attr3_leaf_flipflags(args);
if (error)
return(error);
args->index = args->index2;
args->blkno = args->blkno2;
args->rmtblkno = args->rmtblkno2;
args->rmtblkcnt = args->rmtblkcnt2;
if (args->rmtblkno) {
error = xfs_attr_rmtval_remove(args);
if (error)
return(error);
}
error = xfs_attr3_leaf_read(args->trans, args->dp, args->blkno,
-1, &bp);
if (error)
return error;
xfs_attr3_leaf_remove(bp, args);
if ((forkoff = xfs_attr_shortform_allfit(bp, dp))) {
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_attr3_leaf_to_shortform(bp, args, forkoff);
if (!error) {
error = xfs_bmap_finish(&args->trans,
args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
return(error);
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
}
error = xfs_trans_roll(&args->trans, dp);
} else if (args->rmtblkno > 0) {
error = xfs_attr3_leaf_clearflag(args);
}
return error;
}
STATIC int
xfs_attr_leaf_removename(xfs_da_args_t *args)
{
xfs_inode_t *dp;
struct xfs_buf *bp;
int error, committed, forkoff;
trace_xfs_attr_leaf_removename(args);
dp = args->dp;
args->blkno = 0;
error = xfs_attr3_leaf_read(args->trans, args->dp, args->blkno, -1, &bp);
if (error)
return error;
error = xfs_attr3_leaf_lookup_int(bp, args);
if (error == ENOATTR) {
xfs_trans_brelse(args->trans, bp);
return error;
}
xfs_attr3_leaf_remove(bp, args);
if ((forkoff = xfs_attr_shortform_allfit(bp, dp))) {
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_attr3_leaf_to_shortform(bp, args, forkoff);
if (!error) {
error = xfs_bmap_finish(&args->trans, args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
return error;
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
}
return 0;
}
STATIC int
xfs_attr_leaf_get(xfs_da_args_t *args)
{
struct xfs_buf *bp;
int error;
trace_xfs_attr_leaf_get(args);
args->blkno = 0;
error = xfs_attr3_leaf_read(args->trans, args->dp, args->blkno, -1, &bp);
if (error)
return error;
error = xfs_attr3_leaf_lookup_int(bp, args);
if (error != EEXIST) {
xfs_trans_brelse(args->trans, bp);
return error;
}
error = xfs_attr3_leaf_getvalue(bp, args);
xfs_trans_brelse(args->trans, bp);
if (!error && (args->rmtblkno > 0) && !(args->flags & ATTR_KERNOVAL)) {
error = xfs_attr_rmtval_get(args);
}
return error;
}
STATIC int
xfs_attr_node_addname(xfs_da_args_t *args)
{
xfs_da_state_t *state;
xfs_da_state_blk_t *blk;
xfs_inode_t *dp;
xfs_mount_t *mp;
int committed, retval, error;
trace_xfs_attr_node_addname(args);
dp = args->dp;
mp = dp->i_mount;
restart:
state = xfs_da_state_alloc();
state->args = args;
state->mp = mp;
state->blocksize = state->mp->m_sb.sb_blocksize;
state->node_ents = state->mp->m_attr_node_ents;
error = xfs_da3_node_lookup_int(state, &retval);
if (error)
goto out;
blk = &state->path.blk[ state->path.active-1 ];
ASSERT(blk->magic == XFS_ATTR_LEAF_MAGIC);
if ((args->flags & ATTR_REPLACE) && (retval == ENOATTR)) {
goto out;
} else if (retval == EEXIST) {
if (args->flags & ATTR_CREATE)
goto out;
trace_xfs_attr_node_replace(args);
args->op_flags |= XFS_DA_OP_RENAME;
args->blkno2 = args->blkno;
args->index2 = args->index;
args->rmtblkno2 = args->rmtblkno;
args->rmtblkcnt2 = args->rmtblkcnt;
args->rmtblkno = 0;
args->rmtblkcnt = 0;
}
retval = xfs_attr3_leaf_add(blk->bp, state->args);
if (retval == ENOSPC) {
if (state->path.active == 1) {
xfs_da_state_free(state);
state = NULL;
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_attr3_leaf_to_node(args);
if (!error) {
error = xfs_bmap_finish(&args->trans,
args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
goto out;
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
error = xfs_trans_roll(&args->trans, dp);
if (error)
goto out;
goto restart;
}
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_da3_split(state);
if (!error) {
error = xfs_bmap_finish(&args->trans, args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
goto out;
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
} else {
xfs_da3_fixhashpath(state, &state->path);
}
xfs_da_state_free(state);
state = NULL;
error = xfs_trans_roll(&args->trans, dp);
if (error)
goto out;
if (args->rmtblkno > 0) {
error = xfs_attr_rmtval_set(args);
if (error)
return(error);
}
if (args->op_flags & XFS_DA_OP_RENAME) {
error = xfs_attr3_leaf_flipflags(args);
if (error)
goto out;
args->index = args->index2;
args->blkno = args->blkno2;
args->rmtblkno = args->rmtblkno2;
args->rmtblkcnt = args->rmtblkcnt2;
if (args->rmtblkno) {
error = xfs_attr_rmtval_remove(args);
if (error)
return(error);
}
args->flags |= XFS_ATTR_INCOMPLETE;
state = xfs_da_state_alloc();
state->args = args;
state->mp = mp;
state->blocksize = state->mp->m_sb.sb_blocksize;
state->node_ents = state->mp->m_attr_node_ents;
state->inleaf = 0;
error = xfs_da3_node_lookup_int(state, &retval);
if (error)
goto out;
blk = &state->path.blk[ state->path.active-1 ];
ASSERT(blk->magic == XFS_ATTR_LEAF_MAGIC);
error = xfs_attr3_leaf_remove(blk->bp, args);
xfs_da3_fixhashpath(state, &state->path);
if (retval && (state->path.active > 1)) {
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_da3_join(state);
if (!error) {
error = xfs_bmap_finish(&args->trans,
args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
goto out;
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
}
error = xfs_trans_roll(&args->trans, dp);
if (error)
goto out;
} else if (args->rmtblkno > 0) {
error = xfs_attr3_leaf_clearflag(args);
if (error)
goto out;
}
retval = error = 0;
out:
if (state)
xfs_da_state_free(state);
if (error)
return(error);
return(retval);
}
STATIC int
xfs_attr_node_removename(xfs_da_args_t *args)
{
xfs_da_state_t *state;
xfs_da_state_blk_t *blk;
xfs_inode_t *dp;
struct xfs_buf *bp;
int retval, error, committed, forkoff;
trace_xfs_attr_node_removename(args);
dp = args->dp;
state = xfs_da_state_alloc();
state->args = args;
state->mp = dp->i_mount;
state->blocksize = state->mp->m_sb.sb_blocksize;
state->node_ents = state->mp->m_attr_node_ents;
error = xfs_da3_node_lookup_int(state, &retval);
if (error || (retval != EEXIST)) {
if (error == 0)
error = retval;
goto out;
}
blk = &state->path.blk[ state->path.active-1 ];
ASSERT(blk->bp != NULL);
ASSERT(blk->magic == XFS_ATTR_LEAF_MAGIC);
if (args->rmtblkno > 0) {
error = xfs_attr_fillstate(state);
if (error)
goto out;
error = xfs_attr3_leaf_setflag(args);
if (error)
goto out;
error = xfs_attr_rmtval_remove(args);
if (error)
goto out;
error = xfs_attr_refillstate(state);
if (error)
goto out;
}
blk = &state->path.blk[ state->path.active-1 ];
ASSERT(blk->magic == XFS_ATTR_LEAF_MAGIC);
retval = xfs_attr3_leaf_remove(blk->bp, args);
xfs_da3_fixhashpath(state, &state->path);
if (retval && (state->path.active > 1)) {
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_da3_join(state);
if (!error) {
error = xfs_bmap_finish(&args->trans, args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
goto out;
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
error = xfs_trans_roll(&args->trans, dp);
if (error)
goto out;
}
if (xfs_bmap_one_block(dp, XFS_ATTR_FORK)) {
ASSERT(state->path.active == 1);
ASSERT(state->path.blk[0].bp);
state->path.blk[0].bp = NULL;
error = xfs_attr3_leaf_read(args->trans, args->dp, 0, -1, &bp);
if (error)
goto out;
if ((forkoff = xfs_attr_shortform_allfit(bp, dp))) {
xfs_bmap_init(args->flist, args->firstblock);
error = xfs_attr3_leaf_to_shortform(bp, args, forkoff);
if (!error) {
error = xfs_bmap_finish(&args->trans,
args->flist,
&committed);
}
if (error) {
ASSERT(committed);
args->trans = NULL;
xfs_bmap_cancel(args->flist);
goto out;
}
if (committed)
xfs_trans_ijoin(args->trans, dp, 0);
} else
xfs_trans_brelse(args->trans, bp);
}
error = 0;
out:
xfs_da_state_free(state);
return(error);
}
STATIC int
xfs_attr_fillstate(xfs_da_state_t *state)
{
xfs_da_state_path_t *path;
xfs_da_state_blk_t *blk;
int level;
trace_xfs_attr_fillstate(state->args);
path = &state->path;
ASSERT((path->active >= 0) && (path->active < XFS_DA_NODE_MAXDEPTH));
for (blk = path->blk, level = 0; level < path->active; blk++, level++) {
if (blk->bp) {
blk->disk_blkno = XFS_BUF_ADDR(blk->bp);
blk->bp = NULL;
} else {
blk->disk_blkno = 0;
}
}
path = &state->altpath;
ASSERT((path->active >= 0) && (path->active < XFS_DA_NODE_MAXDEPTH));
for (blk = path->blk, level = 0; level < path->active; blk++, level++) {
if (blk->bp) {
blk->disk_blkno = XFS_BUF_ADDR(blk->bp);
blk->bp = NULL;
} else {
blk->disk_blkno = 0;
}
}
return(0);
}
STATIC int
xfs_attr_refillstate(xfs_da_state_t *state)
{
xfs_da_state_path_t *path;
xfs_da_state_blk_t *blk;
int level, error;
trace_xfs_attr_refillstate(state->args);
path = &state->path;
ASSERT((path->active >= 0) && (path->active < XFS_DA_NODE_MAXDEPTH));
for (blk = path->blk, level = 0; level < path->active; blk++, level++) {
if (blk->disk_blkno) {
error = xfs_da3_node_read(state->args->trans,
state->args->dp,
blk->blkno, blk->disk_blkno,
&blk->bp, XFS_ATTR_FORK);
if (error)
return(error);
} else {
blk->bp = NULL;
}
}
path = &state->altpath;
ASSERT((path->active >= 0) && (path->active < XFS_DA_NODE_MAXDEPTH));
for (blk = path->blk, level = 0; level < path->active; blk++, level++) {
if (blk->disk_blkno) {
error = xfs_da3_node_read(state->args->trans,
state->args->dp,
blk->blkno, blk->disk_blkno,
&blk->bp, XFS_ATTR_FORK);
if (error)
return(error);
} else {
blk->bp = NULL;
}
}
return(0);
}
STATIC int
xfs_attr_node_get(xfs_da_args_t *args)
{
xfs_da_state_t *state;
xfs_da_state_blk_t *blk;
int error, retval;
int i;
trace_xfs_attr_node_get(args);
state = xfs_da_state_alloc();
state->args = args;
state->mp = args->dp->i_mount;
state->blocksize = state->mp->m_sb.sb_blocksize;
state->node_ents = state->mp->m_attr_node_ents;
error = xfs_da3_node_lookup_int(state, &retval);
if (error) {
retval = error;
} else if (retval == EEXIST) {
blk = &state->path.blk[ state->path.active-1 ];
ASSERT(blk->bp != NULL);
ASSERT(blk->magic == XFS_ATTR_LEAF_MAGIC);
retval = xfs_attr3_leaf_getvalue(blk->bp, args);
if (!retval && (args->rmtblkno > 0)
&& !(args->flags & ATTR_KERNOVAL)) {
retval = xfs_attr_rmtval_get(args);
}
}
for (i = 0; i < state->path.active; i++) {
xfs_trans_brelse(args->trans, state->path.blk[i].bp);
state->path.blk[i].bp = NULL;
}
xfs_da_state_free(state);
return(retval);
}
