int
xfs_fs_geometry(
xfs_mount_t *mp,
xfs_fsop_geom_t *geo,
int new_version)
{
memset(geo, 0, sizeof(*geo));
geo->blocksize = mp->m_sb.sb_blocksize;
geo->rtextsize = mp->m_sb.sb_rextsize;
geo->agblocks = mp->m_sb.sb_agblocks;
geo->agcount = mp->m_sb.sb_agcount;
geo->logblocks = mp->m_sb.sb_logblocks;
geo->sectsize = mp->m_sb.sb_sectsize;
geo->inodesize = mp->m_sb.sb_inodesize;
geo->imaxpct = mp->m_sb.sb_imax_pct;
geo->datablocks = mp->m_sb.sb_dblocks;
geo->rtblocks = mp->m_sb.sb_rblocks;
geo->rtextents = mp->m_sb.sb_rextents;
geo->logstart = mp->m_sb.sb_logstart;
ASSERT(sizeof(geo->uuid)==sizeof(mp->m_sb.sb_uuid));
memcpy(geo->uuid, &mp->m_sb.sb_uuid, sizeof(mp->m_sb.sb_uuid));
if (new_version >= 2) {
geo->sunit = mp->m_sb.sb_unit;
geo->swidth = mp->m_sb.sb_width;
}
if (new_version >= 3) {
geo->version = XFS_FSOP_GEOM_VERSION;
geo->flags = XFS_FSOP_GEOM_FLAGS_NLINK |
XFS_FSOP_GEOM_FLAGS_DIRV2 |
(xfs_sb_version_hasattr(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_ATTR : 0) |
(xfs_sb_version_hasquota(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_QUOTA : 0) |
(xfs_sb_version_hasalign(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_IALIGN : 0) |
(xfs_sb_version_hasdalign(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_DALIGN : 0) |
(xfs_sb_version_hasextflgbit(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_EXTFLG : 0) |
(xfs_sb_version_hassector(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_SECTOR : 0) |
(xfs_sb_version_hasasciici(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_DIRV2CI : 0) |
(xfs_sb_version_haslazysbcount(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_LAZYSB : 0) |
(xfs_sb_version_hasattr2(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_ATTR2 : 0) |
(xfs_sb_version_hasprojid32bit(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_PROJID32 : 0) |
(xfs_sb_version_hascrc(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_V5SB : 0) |
(xfs_sb_version_hasftype(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_FTYPE : 0) |
(xfs_sb_version_hasfinobt(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_FINOBT : 0) |
(xfs_sb_version_hassparseinodes(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_SPINODES : 0) |
(xfs_sb_version_hasrmapbt(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_RMAPBT : 0) |
(xfs_sb_version_hasreflink(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_REFLINK : 0);
geo->logsectsize = xfs_sb_version_hassector(&mp->m_sb) ?
mp->m_sb.sb_logsectsize : BBSIZE;
geo->rtsectsize = mp->m_sb.sb_blocksize;
geo->dirblocksize = mp->m_dir_geo->blksize;
}
if (new_version >= 4) {
geo->flags |=
(xfs_sb_version_haslogv2(&mp->m_sb) ?
XFS_FSOP_GEOM_FLAGS_LOGV2 : 0);
geo->logsunit = mp->m_sb.sb_logsunit;
}
return 0;
}
static struct xfs_buf *
xfs_growfs_get_hdr_buf(
struct xfs_mount *mp,
xfs_daddr_t blkno,
size_t numblks,
int flags,
const struct xfs_buf_ops *ops)
{
struct xfs_buf *bp;
bp = xfs_buf_get_uncached(mp->m_ddev_targp, numblks, flags);
if (!bp)
return NULL;
xfs_buf_zero(bp, 0, BBTOB(bp->b_length));
bp->b_bn = blkno;
bp->b_maps[0].bm_bn = blkno;
bp->b_ops = ops;
return bp;
}
static int
xfs_growfs_data_private(
xfs_mount_t *mp,
xfs_growfs_data_t *in)
{
xfs_agf_t *agf;
struct xfs_agfl *agfl;
xfs_agi_t *agi;
xfs_agnumber_t agno;
xfs_extlen_t agsize;
xfs_extlen_t tmpsize;
xfs_alloc_rec_t *arec;
xfs_buf_t *bp;
int bucket;
int dpct;
int error, saved_error = 0;
xfs_agnumber_t nagcount;
xfs_agnumber_t nagimax = 0;
xfs_rfsblock_t nb, nb_mod;
xfs_rfsblock_t new;
xfs_rfsblock_t nfree;
xfs_agnumber_t oagcount;
int pct;
xfs_trans_t *tp;
nb = in->newblocks;
pct = in->imaxpct;
if (nb < mp->m_sb.sb_dblocks || pct < 0 || pct > 100)
return -EINVAL;
if ((error = xfs_sb_validate_fsb_count(&mp->m_sb, nb)))
return error;
dpct = pct - mp->m_sb.sb_imax_pct;
error = xfs_buf_read_uncached(mp->m_ddev_targp,
XFS_FSB_TO_BB(mp, nb) - XFS_FSS_TO_BB(mp, 1),
XFS_FSS_TO_BB(mp, 1), 0, &bp, NULL);
if (error)
return error;
xfs_buf_relse(bp);
new = nb;
nb_mod = do_div(new, mp->m_sb.sb_agblocks);
nagcount = new + (nb_mod != 0);
if (nb_mod && nb_mod < XFS_MIN_AG_BLOCKS) {
nagcount--;
nb = (xfs_rfsblock_t)nagcount * mp->m_sb.sb_agblocks;
if (nb < mp->m_sb.sb_dblocks)
return -EINVAL;
}
new = nb - mp->m_sb.sb_dblocks;
oagcount = mp->m_sb.sb_agcount;
if (nagcount > oagcount) {
error = xfs_initialize_perag(mp, nagcount, &nagimax);
if (error)
return error;
}
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_growdata,
XFS_GROWFS_SPACE_RES(mp), 0, XFS_TRANS_RESERVE, &tp);
if (error)
return error;
nfree = 0;
for (agno = nagcount - 1; agno >= oagcount; agno--, new -= agsize) {
__be32 *agfl_bno;
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AG_DADDR(mp, agno, XFS_AGF_DADDR(mp)),
XFS_FSS_TO_BB(mp, 1), 0,
&xfs_agf_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
agf = XFS_BUF_TO_AGF(bp);
agf->agf_magicnum = cpu_to_be32(XFS_AGF_MAGIC);
agf->agf_versionnum = cpu_to_be32(XFS_AGF_VERSION);
agf->agf_seqno = cpu_to_be32(agno);
if (agno == nagcount - 1)
agsize =
nb -
(agno * (xfs_rfsblock_t)mp->m_sb.sb_agblocks);
else
agsize = mp->m_sb.sb_agblocks;
agf->agf_length = cpu_to_be32(agsize);
agf->agf_roots[XFS_BTNUM_BNOi] = cpu_to_be32(XFS_BNO_BLOCK(mp));
agf->agf_roots[XFS_BTNUM_CNTi] = cpu_to_be32(XFS_CNT_BLOCK(mp));
agf->agf_levels[XFS_BTNUM_BNOi] = cpu_to_be32(1);
agf->agf_levels[XFS_BTNUM_CNTi] = cpu_to_be32(1);
if (xfs_sb_version_hasrmapbt(&mp->m_sb)) {
agf->agf_roots[XFS_BTNUM_RMAPi] =
cpu_to_be32(XFS_RMAP_BLOCK(mp));
agf->agf_levels[XFS_BTNUM_RMAPi] = cpu_to_be32(1);
agf->agf_rmap_blocks = cpu_to_be32(1);
}
agf->agf_flfirst = cpu_to_be32(1);
agf->agf_fllast = 0;
agf->agf_flcount = 0;
tmpsize = agsize - mp->m_ag_prealloc_blocks;
agf->agf_freeblks = cpu_to_be32(tmpsize);
agf->agf_longest = cpu_to_be32(tmpsize);
if (xfs_sb_version_hascrc(&mp->m_sb))
uuid_copy(&agf->agf_uuid, &mp->m_sb.sb_meta_uuid);
if (xfs_sb_version_hasreflink(&mp->m_sb)) {
agf->agf_refcount_root = cpu_to_be32(
xfs_refc_block(mp));
agf->agf_refcount_level = cpu_to_be32(1);
agf->agf_refcount_blocks = cpu_to_be32(1);
}
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AG_DADDR(mp, agno, XFS_AGFL_DADDR(mp)),
XFS_FSS_TO_BB(mp, 1), 0,
&xfs_agfl_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
agfl = XFS_BUF_TO_AGFL(bp);
if (xfs_sb_version_hascrc(&mp->m_sb)) {
agfl->agfl_magicnum = cpu_to_be32(XFS_AGFL_MAGIC);
agfl->agfl_seqno = cpu_to_be32(agno);
uuid_copy(&agfl->agfl_uuid, &mp->m_sb.sb_meta_uuid);
}
agfl_bno = XFS_BUF_TO_AGFL_BNO(mp, bp);
for (bucket = 0; bucket < XFS_AGFL_SIZE(mp); bucket++)
agfl_bno[bucket] = cpu_to_be32(NULLAGBLOCK);
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AG_DADDR(mp, agno, XFS_AGI_DADDR(mp)),
XFS_FSS_TO_BB(mp, 1), 0,
&xfs_agi_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
agi = XFS_BUF_TO_AGI(bp);
agi->agi_magicnum = cpu_to_be32(XFS_AGI_MAGIC);
agi->agi_versionnum = cpu_to_be32(XFS_AGI_VERSION);
agi->agi_seqno = cpu_to_be32(agno);
agi->agi_length = cpu_to_be32(agsize);
agi->agi_count = 0;
agi->agi_root = cpu_to_be32(XFS_IBT_BLOCK(mp));
agi->agi_level = cpu_to_be32(1);
agi->agi_freecount = 0;
agi->agi_newino = cpu_to_be32(NULLAGINO);
agi->agi_dirino = cpu_to_be32(NULLAGINO);
if (xfs_sb_version_hascrc(&mp->m_sb))
uuid_copy(&agi->agi_uuid, &mp->m_sb.sb_meta_uuid);
if (xfs_sb_version_hasfinobt(&mp->m_sb)) {
agi->agi_free_root = cpu_to_be32(XFS_FIBT_BLOCK(mp));
agi->agi_free_level = cpu_to_be32(1);
}
for (bucket = 0; bucket < XFS_AGI_UNLINKED_BUCKETS; bucket++)
agi->agi_unlinked[bucket] = cpu_to_be32(NULLAGINO);
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AGB_TO_DADDR(mp, agno, XFS_BNO_BLOCK(mp)),
BTOBB(mp->m_sb.sb_blocksize), 0,
&xfs_allocbt_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
if (xfs_sb_version_hascrc(&mp->m_sb))
xfs_btree_init_block(mp, bp, XFS_ABTB_CRC_MAGIC, 0, 1,
agno, XFS_BTREE_CRC_BLOCKS);
else
xfs_btree_init_block(mp, bp, XFS_ABTB_MAGIC, 0, 1,
agno, 0);
arec = XFS_ALLOC_REC_ADDR(mp, XFS_BUF_TO_BLOCK(bp), 1);
arec->ar_startblock = cpu_to_be32(mp->m_ag_prealloc_blocks);
arec->ar_blockcount = cpu_to_be32(
agsize - be32_to_cpu(arec->ar_startblock));
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AGB_TO_DADDR(mp, agno, XFS_CNT_BLOCK(mp)),
BTOBB(mp->m_sb.sb_blocksize), 0,
&xfs_allocbt_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
if (xfs_sb_version_hascrc(&mp->m_sb))
xfs_btree_init_block(mp, bp, XFS_ABTC_CRC_MAGIC, 0, 1,
agno, XFS_BTREE_CRC_BLOCKS);
else
xfs_btree_init_block(mp, bp, XFS_ABTC_MAGIC, 0, 1,
agno, 0);
arec = XFS_ALLOC_REC_ADDR(mp, XFS_BUF_TO_BLOCK(bp), 1);
arec->ar_startblock = cpu_to_be32(mp->m_ag_prealloc_blocks);
arec->ar_blockcount = cpu_to_be32(
agsize - be32_to_cpu(arec->ar_startblock));
nfree += be32_to_cpu(arec->ar_blockcount);
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
if (xfs_sb_version_hasrmapbt(&mp->m_sb)) {
struct xfs_rmap_rec *rrec;
struct xfs_btree_block *block;
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AGB_TO_DADDR(mp, agno, XFS_RMAP_BLOCK(mp)),
BTOBB(mp->m_sb.sb_blocksize), 0,
&xfs_rmapbt_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
xfs_btree_init_block(mp, bp, XFS_RMAP_CRC_MAGIC, 0, 0,
agno, XFS_BTREE_CRC_BLOCKS);
block = XFS_BUF_TO_BLOCK(bp);
rrec = XFS_RMAP_REC_ADDR(block, 1);
rrec->rm_startblock = 0;
rrec->rm_blockcount = cpu_to_be32(XFS_BNO_BLOCK(mp));
rrec->rm_owner = cpu_to_be64(XFS_RMAP_OWN_FS);
rrec->rm_offset = 0;
be16_add_cpu(&block->bb_numrecs, 1);
rrec = XFS_RMAP_REC_ADDR(block, 2);
rrec->rm_startblock = cpu_to_be32(XFS_BNO_BLOCK(mp));
rrec->rm_blockcount = cpu_to_be32(2);
rrec->rm_owner = cpu_to_be64(XFS_RMAP_OWN_AG);
rrec->rm_offset = 0;
be16_add_cpu(&block->bb_numrecs, 1);
rrec = XFS_RMAP_REC_ADDR(block, 3);
rrec->rm_startblock = cpu_to_be32(XFS_IBT_BLOCK(mp));
rrec->rm_blockcount = cpu_to_be32(XFS_RMAP_BLOCK(mp) -
XFS_IBT_BLOCK(mp));
rrec->rm_owner = cpu_to_be64(XFS_RMAP_OWN_INOBT);
rrec->rm_offset = 0;
be16_add_cpu(&block->bb_numrecs, 1);
rrec = XFS_RMAP_REC_ADDR(block, 4);
rrec->rm_startblock = cpu_to_be32(XFS_RMAP_BLOCK(mp));
rrec->rm_blockcount = cpu_to_be32(1);
rrec->rm_owner = cpu_to_be64(XFS_RMAP_OWN_AG);
rrec->rm_offset = 0;
be16_add_cpu(&block->bb_numrecs, 1);
if (xfs_sb_version_hasreflink(&mp->m_sb)) {
rrec = XFS_RMAP_REC_ADDR(block, 5);
rrec->rm_startblock = cpu_to_be32(
xfs_refc_block(mp));
rrec->rm_blockcount = cpu_to_be32(1);
rrec->rm_owner = cpu_to_be64(XFS_RMAP_OWN_REFC);
rrec->rm_offset = 0;
be16_add_cpu(&block->bb_numrecs, 1);
}
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
}
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AGB_TO_DADDR(mp, agno, XFS_IBT_BLOCK(mp)),
BTOBB(mp->m_sb.sb_blocksize), 0,
&xfs_inobt_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
if (xfs_sb_version_hascrc(&mp->m_sb))
xfs_btree_init_block(mp, bp, XFS_IBT_CRC_MAGIC, 0, 0,
agno, XFS_BTREE_CRC_BLOCKS);
else
xfs_btree_init_block(mp, bp, XFS_IBT_MAGIC, 0, 0,
agno, 0);
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
if (xfs_sb_version_hasfinobt(&mp->m_sb)) {
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AGB_TO_DADDR(mp, agno, XFS_FIBT_BLOCK(mp)),
BTOBB(mp->m_sb.sb_blocksize), 0,
&xfs_inobt_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
if (xfs_sb_version_hascrc(&mp->m_sb))
xfs_btree_init_block(mp, bp, XFS_FIBT_CRC_MAGIC,
0, 0, agno,
XFS_BTREE_CRC_BLOCKS);
else
xfs_btree_init_block(mp, bp, XFS_FIBT_MAGIC, 0,
0, agno, 0);
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
}
if (xfs_sb_version_hasreflink(&mp->m_sb)) {
bp = xfs_growfs_get_hdr_buf(mp,
XFS_AGB_TO_DADDR(mp, agno, xfs_refc_block(mp)),
BTOBB(mp->m_sb.sb_blocksize), 0,
&xfs_refcountbt_buf_ops);
if (!bp) {
error = -ENOMEM;
goto error0;
}
xfs_btree_init_block(mp, bp, XFS_REFC_CRC_MAGIC,
0, 0, agno,
XFS_BTREE_CRC_BLOCKS);
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error)
goto error0;
}
}
xfs_trans_agblocks_delta(tp, nfree);
if (new) {
struct xfs_owner_info oinfo;
error = xfs_ialloc_read_agi(mp, tp, agno, &bp);
if (error) {
goto error0;
}
ASSERT(bp);
agi = XFS_BUF_TO_AGI(bp);
be32_add_cpu(&agi->agi_length, new);
ASSERT(nagcount == oagcount ||
be32_to_cpu(agi->agi_length) == mp->m_sb.sb_agblocks);
xfs_ialloc_log_agi(tp, bp, XFS_AGI_LENGTH);
error = xfs_alloc_read_agf(mp, tp, agno, 0, &bp);
if (error) {
goto error0;
}
ASSERT(bp);
agf = XFS_BUF_TO_AGF(bp);
be32_add_cpu(&agf->agf_length, new);
ASSERT(be32_to_cpu(agf->agf_length) ==
be32_to_cpu(agi->agi_length));
xfs_alloc_log_agf(tp, bp, XFS_AGF_LENGTH);
xfs_rmap_ag_owner(&oinfo, XFS_RMAP_OWN_NULL);
error = xfs_free_extent(tp,
XFS_AGB_TO_FSB(mp, agno,
be32_to_cpu(agf->agf_length) - new),
new, &oinfo, XFS_AG_RESV_NONE);
if (error)
goto error0;
}
if (nagcount > oagcount)
xfs_trans_mod_sb(tp, XFS_TRANS_SB_AGCOUNT, nagcount - oagcount);
if (nb > mp->m_sb.sb_dblocks)
xfs_trans_mod_sb(tp, XFS_TRANS_SB_DBLOCKS,
nb - mp->m_sb.sb_dblocks);
if (nfree)
xfs_trans_mod_sb(tp, XFS_TRANS_SB_FDBLOCKS, nfree);
if (dpct)
xfs_trans_mod_sb(tp, XFS_TRANS_SB_IMAXPCT, dpct);
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp);
if (error)
return error;
if (nagimax)
mp->m_maxagi = nagimax;
if (mp->m_sb.sb_imax_pct) {
__uint64_t icount = mp->m_sb.sb_dblocks * mp->m_sb.sb_imax_pct;
do_div(icount, 100);
mp->m_maxicount = icount << mp->m_sb.sb_inopblog;
} else
mp->m_maxicount = 0;
xfs_set_low_space_thresholds(mp);
mp->m_alloc_set_aside = xfs_alloc_set_aside(mp);
error = xfs_fs_reserve_ag_blocks(mp);
if (error && error != -ENOSPC)
goto out;
for (agno = 1; agno < nagcount; agno++) {
error = 0;
if (agno < oagcount) {
error = xfs_trans_read_buf(mp, NULL, mp->m_ddev_targp,
XFS_AGB_TO_DADDR(mp, agno, XFS_SB_BLOCK(mp)),
XFS_FSS_TO_BB(mp, 1), 0, &bp,
&xfs_sb_buf_ops);
} else {
bp = xfs_trans_get_buf(NULL, mp->m_ddev_targp,
XFS_AGB_TO_DADDR(mp, agno, XFS_SB_BLOCK(mp)),
XFS_FSS_TO_BB(mp, 1), 0);
if (bp) {
bp->b_ops = &xfs_sb_buf_ops;
xfs_buf_zero(bp, 0, BBTOB(bp->b_length));
} else
error = -ENOMEM;
}
if (error) {
xfs_warn(mp,
"error %d reading secondary superblock for ag %d",
error, agno);
saved_error = error;
continue;
}
xfs_sb_to_disk(XFS_BUF_TO_SBP(bp), &mp->m_sb);
error = xfs_bwrite(bp);
xfs_buf_relse(bp);
if (error) {
xfs_warn(mp,
"write error %d updating secondary superblock for ag %d",
error, agno);
saved_error = error;
continue;
}
}
out:
return saved_error ? saved_error : error;
error0:
xfs_trans_cancel(tp);
return error;
}
static int
xfs_growfs_log_private(
xfs_mount_t *mp,
xfs_growfs_log_t *in)
{
xfs_extlen_t nb;
nb = in->newblocks;
if (nb < XFS_MIN_LOG_BLOCKS || nb < XFS_B_TO_FSB(mp, XFS_MIN_LOG_BYTES))
return -EINVAL;
if (nb == mp->m_sb.sb_logblocks &&
in->isint == (mp->m_sb.sb_logstart != 0))
return -EINVAL;
return -ENOSYS;
}
int
xfs_growfs_data(
xfs_mount_t *mp,
xfs_growfs_data_t *in)
{
int error;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (!mutex_trylock(&mp->m_growlock))
return -EWOULDBLOCK;
error = xfs_growfs_data_private(mp, in);
mp->m_generation++;
mutex_unlock(&mp->m_growlock);
return error;
}
int
xfs_growfs_log(
xfs_mount_t *mp,
xfs_growfs_log_t *in)
{
int error;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (!mutex_trylock(&mp->m_growlock))
return -EWOULDBLOCK;
error = xfs_growfs_log_private(mp, in);
mutex_unlock(&mp->m_growlock);
return error;
}
int
xfs_fs_counts(
xfs_mount_t *mp,
xfs_fsop_counts_t *cnt)
{
cnt->allocino = percpu_counter_read_positive(&mp->m_icount);
cnt->freeino = percpu_counter_read_positive(&mp->m_ifree);
cnt->freedata = percpu_counter_read_positive(&mp->m_fdblocks) -
mp->m_alloc_set_aside;
spin_lock(&mp->m_sb_lock);
cnt->freertx = mp->m_sb.sb_frextents;
spin_unlock(&mp->m_sb_lock);
return 0;
}
int
xfs_reserve_blocks(
xfs_mount_t *mp,
__uint64_t *inval,
xfs_fsop_resblks_t *outval)
{
__int64_t lcounter, delta;
__int64_t fdblks_delta = 0;
__uint64_t request;
__int64_t free;
int error = 0;
if (inval == (__uint64_t *)NULL) {
if (!outval)
return -EINVAL;
outval->resblks = mp->m_resblks;
outval->resblks_avail = mp->m_resblks_avail;
return 0;
}
request = *inval;
spin_lock(&mp->m_sb_lock);
if (mp->m_resblks > request) {
lcounter = mp->m_resblks_avail - request;
if (lcounter > 0) {
fdblks_delta = lcounter;
mp->m_resblks_avail -= lcounter;
}
mp->m_resblks = request;
if (fdblks_delta) {
spin_unlock(&mp->m_sb_lock);
error = xfs_mod_fdblocks(mp, fdblks_delta, 0);
spin_lock(&mp->m_sb_lock);
}
goto out;
}
error = -ENOSPC;
do {
free = percpu_counter_sum(&mp->m_fdblocks) -
mp->m_alloc_set_aside;
if (!free)
break;
delta = request - mp->m_resblks;
lcounter = free - delta;
if (lcounter < 0)
fdblks_delta = free;
else
fdblks_delta = delta;
spin_unlock(&mp->m_sb_lock);
error = xfs_mod_fdblocks(mp, -fdblks_delta, 0);
spin_lock(&mp->m_sb_lock);
} while (error == -ENOSPC);
if (!error && fdblks_delta) {
mp->m_resblks += fdblks_delta;
mp->m_resblks_avail += fdblks_delta;
}
out:
if (outval) {
outval->resblks = mp->m_resblks;
outval->resblks_avail = mp->m_resblks_avail;
}
spin_unlock(&mp->m_sb_lock);
return error;
}
int
xfs_fs_goingdown(
xfs_mount_t *mp,
__uint32_t inflags)
{
switch (inflags) {
case XFS_FSOP_GOING_FLAGS_DEFAULT: {
struct super_block *sb = freeze_bdev(mp->m_super->s_bdev);
if (sb && !IS_ERR(sb)) {
xfs_force_shutdown(mp, SHUTDOWN_FORCE_UMOUNT);
thaw_bdev(sb->s_bdev, sb);
}
break;
}
case XFS_FSOP_GOING_FLAGS_LOGFLUSH:
xfs_force_shutdown(mp, SHUTDOWN_FORCE_UMOUNT);
break;
case XFS_FSOP_GOING_FLAGS_NOLOGFLUSH:
xfs_force_shutdown(mp,
SHUTDOWN_FORCE_UMOUNT | SHUTDOWN_LOG_IO_ERROR);
break;
default:
return -EINVAL;
}
return 0;
}
void
xfs_do_force_shutdown(
xfs_mount_t *mp,
int flags,
char *fname,
int lnnum)
{
int logerror;
logerror = flags & SHUTDOWN_LOG_IO_ERROR;
if (!(flags & SHUTDOWN_FORCE_UMOUNT)) {
xfs_notice(mp,
"%s(0x%x) called from line %d of file %s. Return address = 0x%p",
__func__, flags, lnnum, fname, __return_address);
}
if (XFS_FORCED_SHUTDOWN(mp) && !logerror)
return;
if (xfs_log_force_umount(mp, logerror))
return;
if (flags & SHUTDOWN_CORRUPT_INCORE) {
xfs_alert_tag(mp, XFS_PTAG_SHUTDOWN_CORRUPT,
"Corruption of in-memory data detected. Shutting down filesystem");
if (XFS_ERRLEVEL_HIGH <= xfs_error_level)
xfs_stack_trace();
} else if (!(flags & SHUTDOWN_FORCE_UMOUNT)) {
if (logerror) {
xfs_alert_tag(mp, XFS_PTAG_SHUTDOWN_LOGERROR,
"Log I/O Error Detected. Shutting down filesystem");
} else if (flags & SHUTDOWN_DEVICE_REQ) {
xfs_alert_tag(mp, XFS_PTAG_SHUTDOWN_IOERROR,
"All device paths lost. Shutting down filesystem");
} else if (!(flags & SHUTDOWN_REMOTE_REQ)) {
xfs_alert_tag(mp, XFS_PTAG_SHUTDOWN_IOERROR,
"I/O Error Detected. Shutting down filesystem");
}
}
if (!(flags & SHUTDOWN_FORCE_UMOUNT)) {
xfs_alert(mp,
"Please umount the filesystem and rectify the problem(s)");
}
}
int
xfs_fs_reserve_ag_blocks(
struct xfs_mount *mp)
{
xfs_agnumber_t agno;
struct xfs_perag *pag;
int error = 0;
int err2;
for (agno = 0; agno < mp->m_sb.sb_agcount; agno++) {
pag = xfs_perag_get(mp, agno);
err2 = xfs_ag_resv_init(pag);
xfs_perag_put(pag);
if (err2 && !error)
error = err2;
}
if (error && error != -ENOSPC) {
xfs_warn(mp,
"Error %d reserving per-AG metadata reserve pool.", error);
xfs_force_shutdown(mp, SHUTDOWN_CORRUPT_INCORE);
}
return error;
}
int
xfs_fs_unreserve_ag_blocks(
struct xfs_mount *mp)
{
xfs_agnumber_t agno;
struct xfs_perag *pag;
int error = 0;
int err2;
for (agno = 0; agno < mp->m_sb.sb_agcount; agno++) {
pag = xfs_perag_get(mp, agno);
err2 = xfs_ag_resv_free(pag);
xfs_perag_put(pag);
if (err2 && !error)
error = err2;
}
if (error)
xfs_warn(mp,
"Error %d freeing per-AG metadata reserve pool.", error);
return error;
}
