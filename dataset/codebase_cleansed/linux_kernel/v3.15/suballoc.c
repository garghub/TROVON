static u64 ocfs2_group_from_res(struct ocfs2_suballoc_result *res)
{
if (res->sr_blkno == 0)
return 0;
if (res->sr_bg_blkno)
return res->sr_bg_blkno;
return ocfs2_which_suballoc_group(res->sr_blkno, res->sr_bit_offset);
}
void ocfs2_free_ac_resource(struct ocfs2_alloc_context *ac)
{
struct inode *inode = ac->ac_inode;
if (inode) {
if (ac->ac_which != OCFS2_AC_USE_LOCAL)
ocfs2_inode_unlock(inode, 1);
mutex_unlock(&inode->i_mutex);
iput(inode);
ac->ac_inode = NULL;
}
brelse(ac->ac_bh);
ac->ac_bh = NULL;
ac->ac_resv = NULL;
if (ac->ac_find_loc_priv) {
kfree(ac->ac_find_loc_priv);
ac->ac_find_loc_priv = NULL;
}
}
void ocfs2_free_alloc_context(struct ocfs2_alloc_context *ac)
{
ocfs2_free_ac_resource(ac);
kfree(ac);
}
static u32 ocfs2_bits_per_group(struct ocfs2_chain_list *cl)
{
return (u32)le16_to_cpu(cl->cl_cpg) * (u32)le16_to_cpu(cl->cl_bpc);
}
static int ocfs2_validate_gd_self(struct super_block *sb,
struct buffer_head *bh,
int resize)
{
struct ocfs2_group_desc *gd = (struct ocfs2_group_desc *)bh->b_data;
if (!OCFS2_IS_VALID_GROUP_DESC(gd)) {
do_error("Group descriptor #%llu has bad signature %.*s",
(unsigned long long)bh->b_blocknr, 7,
gd->bg_signature);
return -EINVAL;
}
if (le64_to_cpu(gd->bg_blkno) != bh->b_blocknr) {
do_error("Group descriptor #%llu has an invalid bg_blkno "
"of %llu",
(unsigned long long)bh->b_blocknr,
(unsigned long long)le64_to_cpu(gd->bg_blkno));
return -EINVAL;
}
if (le32_to_cpu(gd->bg_generation) != OCFS2_SB(sb)->fs_generation) {
do_error("Group descriptor #%llu has an invalid "
"fs_generation of #%u",
(unsigned long long)bh->b_blocknr,
le32_to_cpu(gd->bg_generation));
return -EINVAL;
}
if (le16_to_cpu(gd->bg_free_bits_count) > le16_to_cpu(gd->bg_bits)) {
do_error("Group descriptor #%llu has bit count %u but "
"claims that %u are free",
(unsigned long long)bh->b_blocknr,
le16_to_cpu(gd->bg_bits),
le16_to_cpu(gd->bg_free_bits_count));
return -EINVAL;
}
if (le16_to_cpu(gd->bg_bits) > (8 * le16_to_cpu(gd->bg_size))) {
do_error("Group descriptor #%llu has bit count %u but "
"max bitmap bits of %u",
(unsigned long long)bh->b_blocknr,
le16_to_cpu(gd->bg_bits),
8 * le16_to_cpu(gd->bg_size));
return -EINVAL;
}
return 0;
}
static int ocfs2_validate_gd_parent(struct super_block *sb,
struct ocfs2_dinode *di,
struct buffer_head *bh,
int resize)
{
unsigned int max_bits;
struct ocfs2_group_desc *gd = (struct ocfs2_group_desc *)bh->b_data;
if (di->i_blkno != gd->bg_parent_dinode) {
do_error("Group descriptor #%llu has bad parent "
"pointer (%llu, expected %llu)",
(unsigned long long)bh->b_blocknr,
(unsigned long long)le64_to_cpu(gd->bg_parent_dinode),
(unsigned long long)le64_to_cpu(di->i_blkno));
return -EINVAL;
}
max_bits = le16_to_cpu(di->id2.i_chain.cl_cpg) * le16_to_cpu(di->id2.i_chain.cl_bpc);
if (le16_to_cpu(gd->bg_bits) > max_bits) {
do_error("Group descriptor #%llu has bit count of %u",
(unsigned long long)bh->b_blocknr,
le16_to_cpu(gd->bg_bits));
return -EINVAL;
}
if ((le16_to_cpu(gd->bg_chain) >
le16_to_cpu(di->id2.i_chain.cl_next_free_rec)) ||
((le16_to_cpu(gd->bg_chain) ==
le16_to_cpu(di->id2.i_chain.cl_next_free_rec)) && !resize)) {
do_error("Group descriptor #%llu has bad chain %u",
(unsigned long long)bh->b_blocknr,
le16_to_cpu(gd->bg_chain));
return -EINVAL;
}
return 0;
}
int ocfs2_check_group_descriptor(struct super_block *sb,
struct ocfs2_dinode *di,
struct buffer_head *bh)
{
int rc;
struct ocfs2_group_desc *gd = (struct ocfs2_group_desc *)bh->b_data;
BUG_ON(!buffer_uptodate(bh));
rc = ocfs2_validate_meta_ecc(sb, bh->b_data, &gd->bg_check);
if (rc) {
mlog(ML_ERROR,
"Checksum failed for group descriptor %llu\n",
(unsigned long long)bh->b_blocknr);
} else
rc = ocfs2_validate_gd_self(sb, bh, 1);
if (!rc)
rc = ocfs2_validate_gd_parent(sb, di, bh, 1);
return rc;
}
static int ocfs2_validate_group_descriptor(struct super_block *sb,
struct buffer_head *bh)
{
int rc;
struct ocfs2_group_desc *gd = (struct ocfs2_group_desc *)bh->b_data;
trace_ocfs2_validate_group_descriptor(
(unsigned long long)bh->b_blocknr);
BUG_ON(!buffer_uptodate(bh));
rc = ocfs2_validate_meta_ecc(sb, bh->b_data, &gd->bg_check);
if (rc)
return rc;
return ocfs2_validate_gd_self(sb, bh, 0);
}
int ocfs2_read_group_descriptor(struct inode *inode, struct ocfs2_dinode *di,
u64 gd_blkno, struct buffer_head **bh)
{
int rc;
struct buffer_head *tmp = *bh;
rc = ocfs2_read_block(INODE_CACHE(inode), gd_blkno, &tmp,
ocfs2_validate_group_descriptor);
if (rc)
goto out;
rc = ocfs2_validate_gd_parent(inode->i_sb, di, tmp, 0);
if (rc) {
brelse(tmp);
goto out;
}
if (!*bh)
*bh = tmp;
out:
return rc;
}
static void ocfs2_bg_discontig_add_extent(struct ocfs2_super *osb,
struct ocfs2_group_desc *bg,
struct ocfs2_chain_list *cl,
u64 p_blkno, unsigned int clusters)
{
struct ocfs2_extent_list *el = &bg->bg_list;
struct ocfs2_extent_rec *rec;
BUG_ON(!ocfs2_supports_discontig_bg(osb));
if (!el->l_next_free_rec)
el->l_count = cpu_to_le16(ocfs2_extent_recs_per_gd(osb->sb));
rec = &el->l_recs[le16_to_cpu(el->l_next_free_rec)];
rec->e_blkno = cpu_to_le64(p_blkno);
rec->e_cpos = cpu_to_le32(le16_to_cpu(bg->bg_bits) /
le16_to_cpu(cl->cl_bpc));
rec->e_leaf_clusters = cpu_to_le16(clusters);
le16_add_cpu(&bg->bg_bits, clusters * le16_to_cpu(cl->cl_bpc));
le16_add_cpu(&bg->bg_free_bits_count,
clusters * le16_to_cpu(cl->cl_bpc));
le16_add_cpu(&el->l_next_free_rec, 1);
}
static int ocfs2_block_group_fill(handle_t *handle,
struct inode *alloc_inode,
struct buffer_head *bg_bh,
u64 group_blkno,
unsigned int group_clusters,
u16 my_chain,
struct ocfs2_chain_list *cl)
{
int status = 0;
struct ocfs2_super *osb = OCFS2_SB(alloc_inode->i_sb);
struct ocfs2_group_desc *bg = (struct ocfs2_group_desc *) bg_bh->b_data;
struct super_block * sb = alloc_inode->i_sb;
if (((unsigned long long) bg_bh->b_blocknr) != group_blkno) {
ocfs2_error(alloc_inode->i_sb, "group block (%llu) != "
"b_blocknr (%llu)",
(unsigned long long)group_blkno,
(unsigned long long) bg_bh->b_blocknr);
status = -EIO;
goto bail;
}
status = ocfs2_journal_access_gd(handle,
INODE_CACHE(alloc_inode),
bg_bh,
OCFS2_JOURNAL_ACCESS_CREATE);
if (status < 0) {
mlog_errno(status);
goto bail;
}
memset(bg, 0, sb->s_blocksize);
strcpy(bg->bg_signature, OCFS2_GROUP_DESC_SIGNATURE);
bg->bg_generation = cpu_to_le32(OCFS2_SB(sb)->fs_generation);
bg->bg_size = cpu_to_le16(ocfs2_group_bitmap_size(sb, 1,
osb->s_feature_incompat));
bg->bg_chain = cpu_to_le16(my_chain);
bg->bg_next_group = cl->cl_recs[my_chain].c_blkno;
bg->bg_parent_dinode = cpu_to_le64(OCFS2_I(alloc_inode)->ip_blkno);
bg->bg_blkno = cpu_to_le64(group_blkno);
if (group_clusters == le16_to_cpu(cl->cl_cpg))
bg->bg_bits = cpu_to_le16(ocfs2_bits_per_group(cl));
else
ocfs2_bg_discontig_add_extent(osb, bg, cl, group_blkno,
group_clusters);
ocfs2_set_bit(0, (unsigned long *)bg->bg_bitmap);
bg->bg_free_bits_count = cpu_to_le16(le16_to_cpu(bg->bg_bits) - 1);
ocfs2_journal_dirty(handle, bg_bh);
bail:
if (status)
mlog_errno(status);
return status;
}
static inline u16 ocfs2_find_smallest_chain(struct ocfs2_chain_list *cl)
{
u16 curr, best;
best = curr = 0;
while (curr < le16_to_cpu(cl->cl_count)) {
if (le32_to_cpu(cl->cl_recs[best].c_total) >
le32_to_cpu(cl->cl_recs[curr].c_total))
best = curr;
curr++;
}
return best;
}
static struct buffer_head *
ocfs2_block_group_alloc_contig(struct ocfs2_super *osb, handle_t *handle,
struct inode *alloc_inode,
struct ocfs2_alloc_context *ac,
struct ocfs2_chain_list *cl)
{
int status;
u32 bit_off, num_bits;
u64 bg_blkno;
struct buffer_head *bg_bh;
unsigned int alloc_rec = ocfs2_find_smallest_chain(cl);
status = ocfs2_claim_clusters(handle, ac,
le16_to_cpu(cl->cl_cpg), &bit_off,
&num_bits);
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
bg_blkno = ocfs2_clusters_to_blocks(osb->sb, bit_off);
trace_ocfs2_block_group_alloc_contig(
(unsigned long long)bg_blkno, alloc_rec);
bg_bh = sb_getblk(osb->sb, bg_blkno);
if (!bg_bh) {
status = -ENOMEM;
mlog_errno(status);
goto bail;
}
ocfs2_set_new_buffer_uptodate(INODE_CACHE(alloc_inode), bg_bh);
status = ocfs2_block_group_fill(handle, alloc_inode, bg_bh,
bg_blkno, num_bits, alloc_rec, cl);
if (status < 0) {
brelse(bg_bh);
mlog_errno(status);
}
bail:
return status ? ERR_PTR(status) : bg_bh;
}
static int ocfs2_block_group_claim_bits(struct ocfs2_super *osb,
handle_t *handle,
struct ocfs2_alloc_context *ac,
unsigned int min_bits,
u32 *bit_off, u32 *num_bits)
{
int status = 0;
while (min_bits) {
status = ocfs2_claim_clusters(handle, ac, min_bits,
bit_off, num_bits);
if (status != -ENOSPC)
break;
min_bits >>= 1;
}
return status;
}
static int ocfs2_block_group_grow_discontig(handle_t *handle,
struct inode *alloc_inode,
struct buffer_head *bg_bh,
struct ocfs2_alloc_context *ac,
struct ocfs2_chain_list *cl,
unsigned int min_bits)
{
int status;
struct ocfs2_super *osb = OCFS2_SB(alloc_inode->i_sb);
struct ocfs2_group_desc *bg =
(struct ocfs2_group_desc *)bg_bh->b_data;
unsigned int needed = le16_to_cpu(cl->cl_cpg) -
le16_to_cpu(bg->bg_bits) / le16_to_cpu(cl->cl_bpc);
u32 p_cpos, clusters;
u64 p_blkno;
struct ocfs2_extent_list *el = &bg->bg_list;
status = ocfs2_journal_access_gd(handle,
INODE_CACHE(alloc_inode),
bg_bh,
OCFS2_JOURNAL_ACCESS_CREATE);
if (status < 0) {
mlog_errno(status);
goto bail;
}
while ((needed > 0) && (le16_to_cpu(el->l_next_free_rec) <
le16_to_cpu(el->l_count))) {
if (min_bits > needed)
min_bits = needed;
status = ocfs2_block_group_claim_bits(osb, handle, ac,
min_bits, &p_cpos,
&clusters);
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
p_blkno = ocfs2_clusters_to_blocks(osb->sb, p_cpos);
ocfs2_bg_discontig_add_extent(osb, bg, cl, p_blkno,
clusters);
min_bits = clusters;
needed = le16_to_cpu(cl->cl_cpg) -
le16_to_cpu(bg->bg_bits) / le16_to_cpu(cl->cl_bpc);
}
if (needed > 0) {
status = -ENOSPC;
goto bail;
}
ocfs2_journal_dirty(handle, bg_bh);
bail:
return status;
}
static void ocfs2_bg_alloc_cleanup(handle_t *handle,
struct ocfs2_alloc_context *cluster_ac,
struct inode *alloc_inode,
struct buffer_head *bg_bh)
{
int i, ret;
struct ocfs2_group_desc *bg;
struct ocfs2_extent_list *el;
struct ocfs2_extent_rec *rec;
if (!bg_bh)
return;
bg = (struct ocfs2_group_desc *)bg_bh->b_data;
el = &bg->bg_list;
for (i = 0; i < le16_to_cpu(el->l_next_free_rec); i++) {
rec = &el->l_recs[i];
ret = ocfs2_free_clusters(handle, cluster_ac->ac_inode,
cluster_ac->ac_bh,
le64_to_cpu(rec->e_blkno),
le16_to_cpu(rec->e_leaf_clusters));
if (ret)
mlog_errno(ret);
}
ocfs2_remove_from_cache(INODE_CACHE(alloc_inode), bg_bh);
brelse(bg_bh);
}
static struct buffer_head *
ocfs2_block_group_alloc_discontig(handle_t *handle,
struct inode *alloc_inode,
struct ocfs2_alloc_context *ac,
struct ocfs2_chain_list *cl)
{
int status;
u32 bit_off, num_bits;
u64 bg_blkno;
unsigned int min_bits = le16_to_cpu(cl->cl_cpg) >> 1;
struct buffer_head *bg_bh = NULL;
unsigned int alloc_rec = ocfs2_find_smallest_chain(cl);
struct ocfs2_super *osb = OCFS2_SB(alloc_inode->i_sb);
if (!ocfs2_supports_discontig_bg(osb)) {
status = -ENOSPC;
goto bail;
}
status = ocfs2_extend_trans(handle,
ocfs2_calc_bg_discontig_credits(osb->sb));
if (status) {
mlog_errno(status);
goto bail;
}
ac->ac_disable_chain_relink = 1;
status = ocfs2_block_group_claim_bits(osb, handle, ac, min_bits,
&bit_off, &num_bits);
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
min_bits = num_bits;
bg_blkno = ocfs2_clusters_to_blocks(osb->sb, bit_off);
trace_ocfs2_block_group_alloc_discontig(
(unsigned long long)bg_blkno, alloc_rec);
bg_bh = sb_getblk(osb->sb, bg_blkno);
if (!bg_bh) {
status = -ENOMEM;
mlog_errno(status);
goto bail;
}
ocfs2_set_new_buffer_uptodate(INODE_CACHE(alloc_inode), bg_bh);
status = ocfs2_block_group_fill(handle, alloc_inode, bg_bh,
bg_blkno, num_bits, alloc_rec, cl);
if (status < 0) {
mlog_errno(status);
goto bail;
}
status = ocfs2_block_group_grow_discontig(handle, alloc_inode,
bg_bh, ac, cl, min_bits);
if (status)
mlog_errno(status);
bail:
if (status)
ocfs2_bg_alloc_cleanup(handle, ac, alloc_inode, bg_bh);
return status ? ERR_PTR(status) : bg_bh;
}
static int ocfs2_block_group_alloc(struct ocfs2_super *osb,
struct inode *alloc_inode,
struct buffer_head *bh,
u64 max_block,
u64 *last_alloc_group,
int flags)
{
int status, credits;
struct ocfs2_dinode *fe = (struct ocfs2_dinode *) bh->b_data;
struct ocfs2_chain_list *cl;
struct ocfs2_alloc_context *ac = NULL;
handle_t *handle = NULL;
u16 alloc_rec;
struct buffer_head *bg_bh = NULL;
struct ocfs2_group_desc *bg;
BUG_ON(ocfs2_is_cluster_bitmap(alloc_inode));
cl = &fe->id2.i_chain;
status = ocfs2_reserve_clusters_with_limit(osb,
le16_to_cpu(cl->cl_cpg),
max_block, flags, &ac);
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
credits = ocfs2_calc_group_alloc_credits(osb->sb,
le16_to_cpu(cl->cl_cpg));
handle = ocfs2_start_trans(osb, credits);
if (IS_ERR(handle)) {
status = PTR_ERR(handle);
handle = NULL;
mlog_errno(status);
goto bail;
}
if (last_alloc_group && *last_alloc_group != 0) {
trace_ocfs2_block_group_alloc(
(unsigned long long)*last_alloc_group);
ac->ac_last_group = *last_alloc_group;
}
bg_bh = ocfs2_block_group_alloc_contig(osb, handle, alloc_inode,
ac, cl);
if (IS_ERR(bg_bh) && (PTR_ERR(bg_bh) == -ENOSPC))
bg_bh = ocfs2_block_group_alloc_discontig(handle,
alloc_inode,
ac, cl);
if (IS_ERR(bg_bh)) {
status = PTR_ERR(bg_bh);
bg_bh = NULL;
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
bg = (struct ocfs2_group_desc *) bg_bh->b_data;
status = ocfs2_journal_access_di(handle, INODE_CACHE(alloc_inode),
bh, OCFS2_JOURNAL_ACCESS_WRITE);
if (status < 0) {
mlog_errno(status);
goto bail;
}
alloc_rec = le16_to_cpu(bg->bg_chain);
le32_add_cpu(&cl->cl_recs[alloc_rec].c_free,
le16_to_cpu(bg->bg_free_bits_count));
le32_add_cpu(&cl->cl_recs[alloc_rec].c_total,
le16_to_cpu(bg->bg_bits));
cl->cl_recs[alloc_rec].c_blkno = bg->bg_blkno;
if (le16_to_cpu(cl->cl_next_free_rec) < le16_to_cpu(cl->cl_count))
le16_add_cpu(&cl->cl_next_free_rec, 1);
le32_add_cpu(&fe->id1.bitmap1.i_used, le16_to_cpu(bg->bg_bits) -
le16_to_cpu(bg->bg_free_bits_count));
le32_add_cpu(&fe->id1.bitmap1.i_total, le16_to_cpu(bg->bg_bits));
le32_add_cpu(&fe->i_clusters, le16_to_cpu(cl->cl_cpg));
ocfs2_journal_dirty(handle, bh);
spin_lock(&OCFS2_I(alloc_inode)->ip_lock);
OCFS2_I(alloc_inode)->ip_clusters = le32_to_cpu(fe->i_clusters);
fe->i_size = cpu_to_le64(ocfs2_clusters_to_bytes(alloc_inode->i_sb,
le32_to_cpu(fe->i_clusters)));
spin_unlock(&OCFS2_I(alloc_inode)->ip_lock);
i_size_write(alloc_inode, le64_to_cpu(fe->i_size));
alloc_inode->i_blocks = ocfs2_inode_sector_count(alloc_inode);
ocfs2_update_inode_fsync_trans(handle, alloc_inode, 0);
status = 0;
if (last_alloc_group)
*last_alloc_group = ac->ac_last_group;
bail:
if (handle)
ocfs2_commit_trans(osb, handle);
if (ac)
ocfs2_free_alloc_context(ac);
brelse(bg_bh);
if (status)
mlog_errno(status);
return status;
}
static int ocfs2_reserve_suballoc_bits(struct ocfs2_super *osb,
struct ocfs2_alloc_context *ac,
int type,
u32 slot,
u64 *last_alloc_group,
int flags)
{
int status;
u32 bits_wanted = ac->ac_bits_wanted;
struct inode *alloc_inode;
struct buffer_head *bh = NULL;
struct ocfs2_dinode *fe;
u32 free_bits;
alloc_inode = ocfs2_get_system_file_inode(osb, type, slot);
if (!alloc_inode) {
mlog_errno(-EINVAL);
return -EINVAL;
}
mutex_lock(&alloc_inode->i_mutex);
status = ocfs2_inode_lock(alloc_inode, &bh, 1);
if (status < 0) {
mutex_unlock(&alloc_inode->i_mutex);
iput(alloc_inode);
mlog_errno(status);
return status;
}
ac->ac_inode = alloc_inode;
ac->ac_alloc_slot = slot;
fe = (struct ocfs2_dinode *) bh->b_data;
BUG_ON(!OCFS2_IS_VALID_DINODE(fe));
if (!(fe->i_flags & cpu_to_le32(OCFS2_CHAIN_FL))) {
ocfs2_error(alloc_inode->i_sb, "Invalid chain allocator %llu",
(unsigned long long)le64_to_cpu(fe->i_blkno));
status = -EIO;
goto bail;
}
free_bits = le32_to_cpu(fe->id1.bitmap1.i_total) -
le32_to_cpu(fe->id1.bitmap1.i_used);
if (bits_wanted > free_bits) {
if (ocfs2_is_cluster_bitmap(alloc_inode)) {
trace_ocfs2_reserve_suballoc_bits_nospc(bits_wanted,
free_bits);
status = -ENOSPC;
goto bail;
}
if (!(flags & ALLOC_NEW_GROUP)) {
trace_ocfs2_reserve_suballoc_bits_no_new_group(
slot, bits_wanted, free_bits);
status = -ENOSPC;
goto bail;
}
status = ocfs2_block_group_alloc(osb, alloc_inode, bh,
ac->ac_max_block,
last_alloc_group, flags);
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
atomic_inc(&osb->alloc_stats.bg_extends);
BUG_ON(bits_wanted >
(le32_to_cpu(fe->id1.bitmap1.i_total)
- le32_to_cpu(fe->id1.bitmap1.i_used)));
}
get_bh(bh);
ac->ac_bh = bh;
bail:
brelse(bh);
if (status)
mlog_errno(status);
return status;
}
static void ocfs2_init_inode_steal_slot(struct ocfs2_super *osb)
{
spin_lock(&osb->osb_lock);
osb->s_inode_steal_slot = OCFS2_INVALID_SLOT;
spin_unlock(&osb->osb_lock);
atomic_set(&osb->s_num_inodes_stolen, 0);
}
static void ocfs2_init_meta_steal_slot(struct ocfs2_super *osb)
{
spin_lock(&osb->osb_lock);
osb->s_meta_steal_slot = OCFS2_INVALID_SLOT;
spin_unlock(&osb->osb_lock);
atomic_set(&osb->s_num_meta_stolen, 0);
}
void ocfs2_init_steal_slots(struct ocfs2_super *osb)
{
ocfs2_init_inode_steal_slot(osb);
ocfs2_init_meta_steal_slot(osb);
}
static void __ocfs2_set_steal_slot(struct ocfs2_super *osb, int slot, int type)
{
spin_lock(&osb->osb_lock);
if (type == INODE_ALLOC_SYSTEM_INODE)
osb->s_inode_steal_slot = slot;
else if (type == EXTENT_ALLOC_SYSTEM_INODE)
osb->s_meta_steal_slot = slot;
spin_unlock(&osb->osb_lock);
}
static int __ocfs2_get_steal_slot(struct ocfs2_super *osb, int type)
{
int slot = OCFS2_INVALID_SLOT;
spin_lock(&osb->osb_lock);
if (type == INODE_ALLOC_SYSTEM_INODE)
slot = osb->s_inode_steal_slot;
else if (type == EXTENT_ALLOC_SYSTEM_INODE)
slot = osb->s_meta_steal_slot;
spin_unlock(&osb->osb_lock);
return slot;
}
static int ocfs2_get_inode_steal_slot(struct ocfs2_super *osb)
{
return __ocfs2_get_steal_slot(osb, INODE_ALLOC_SYSTEM_INODE);
}
static int ocfs2_get_meta_steal_slot(struct ocfs2_super *osb)
{
return __ocfs2_get_steal_slot(osb, EXTENT_ALLOC_SYSTEM_INODE);
}
static int ocfs2_steal_resource(struct ocfs2_super *osb,
struct ocfs2_alloc_context *ac,
int type)
{
int i, status = -ENOSPC;
int slot = __ocfs2_get_steal_slot(osb, type);
if (slot == OCFS2_INVALID_SLOT)
slot = osb->slot_num + 1;
for (i = 0; i < osb->max_slots; i++, slot++) {
if (slot == osb->max_slots)
slot = 0;
if (slot == osb->slot_num)
continue;
status = ocfs2_reserve_suballoc_bits(osb, ac,
type,
(u32)slot, NULL,
NOT_ALLOC_NEW_GROUP);
if (status >= 0) {
__ocfs2_set_steal_slot(osb, slot, type);
break;
}
ocfs2_free_ac_resource(ac);
}
return status;
}
static int ocfs2_steal_inode(struct ocfs2_super *osb,
struct ocfs2_alloc_context *ac)
{
return ocfs2_steal_resource(osb, ac, INODE_ALLOC_SYSTEM_INODE);
}
static int ocfs2_steal_meta(struct ocfs2_super *osb,
struct ocfs2_alloc_context *ac)
{
return ocfs2_steal_resource(osb, ac, EXTENT_ALLOC_SYSTEM_INODE);
}
int ocfs2_reserve_new_metadata_blocks(struct ocfs2_super *osb,
int blocks,
struct ocfs2_alloc_context **ac)
{
int status;
int slot = ocfs2_get_meta_steal_slot(osb);
*ac = kzalloc(sizeof(struct ocfs2_alloc_context), GFP_KERNEL);
if (!(*ac)) {
status = -ENOMEM;
mlog_errno(status);
goto bail;
}
(*ac)->ac_bits_wanted = blocks;
(*ac)->ac_which = OCFS2_AC_USE_META;
(*ac)->ac_group_search = ocfs2_block_group_search;
if (slot != OCFS2_INVALID_SLOT &&
atomic_read(&osb->s_num_meta_stolen) < OCFS2_MAX_TO_STEAL)
goto extent_steal;
atomic_set(&osb->s_num_meta_stolen, 0);
status = ocfs2_reserve_suballoc_bits(osb, (*ac),
EXTENT_ALLOC_SYSTEM_INODE,
(u32)osb->slot_num, NULL,
ALLOC_GROUPS_FROM_GLOBAL|ALLOC_NEW_GROUP);
if (status >= 0) {
status = 0;
if (slot != OCFS2_INVALID_SLOT)
ocfs2_init_meta_steal_slot(osb);
goto bail;
} else if (status < 0 && status != -ENOSPC) {
mlog_errno(status);
goto bail;
}
ocfs2_free_ac_resource(*ac);
extent_steal:
status = ocfs2_steal_meta(osb, *ac);
atomic_inc(&osb->s_num_meta_stolen);
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
status = 0;
bail:
if ((status < 0) && *ac) {
ocfs2_free_alloc_context(*ac);
*ac = NULL;
}
if (status)
mlog_errno(status);
return status;
}
int ocfs2_reserve_new_metadata(struct ocfs2_super *osb,
struct ocfs2_extent_list *root_el,
struct ocfs2_alloc_context **ac)
{
return ocfs2_reserve_new_metadata_blocks(osb,
ocfs2_extend_meta_needed(root_el),
ac);
}
int ocfs2_reserve_new_inode(struct ocfs2_super *osb,
struct ocfs2_alloc_context **ac)
{
int status;
int slot = ocfs2_get_inode_steal_slot(osb);
u64 alloc_group;
*ac = kzalloc(sizeof(struct ocfs2_alloc_context), GFP_KERNEL);
if (!(*ac)) {
status = -ENOMEM;
mlog_errno(status);
goto bail;
}
(*ac)->ac_bits_wanted = 1;
(*ac)->ac_which = OCFS2_AC_USE_INODE;
(*ac)->ac_group_search = ocfs2_block_group_search;
if (!(osb->s_mount_opt & OCFS2_MOUNT_INODE64))
(*ac)->ac_max_block = (u32)~0U;
if (slot != OCFS2_INVALID_SLOT &&
atomic_read(&osb->s_num_inodes_stolen) < OCFS2_MAX_TO_STEAL)
goto inode_steal;
atomic_set(&osb->s_num_inodes_stolen, 0);
alloc_group = osb->osb_inode_alloc_group;
status = ocfs2_reserve_suballoc_bits(osb, *ac,
INODE_ALLOC_SYSTEM_INODE,
(u32)osb->slot_num,
&alloc_group,
ALLOC_NEW_GROUP |
ALLOC_GROUPS_FROM_GLOBAL);
if (status >= 0) {
status = 0;
spin_lock(&osb->osb_lock);
osb->osb_inode_alloc_group = alloc_group;
spin_unlock(&osb->osb_lock);
trace_ocfs2_reserve_new_inode_new_group(
(unsigned long long)alloc_group);
if (slot != OCFS2_INVALID_SLOT)
ocfs2_init_inode_steal_slot(osb);
goto bail;
} else if (status < 0 && status != -ENOSPC) {
mlog_errno(status);
goto bail;
}
ocfs2_free_ac_resource(*ac);
inode_steal:
status = ocfs2_steal_inode(osb, *ac);
atomic_inc(&osb->s_num_inodes_stolen);
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
status = 0;
bail:
if ((status < 0) && *ac) {
ocfs2_free_alloc_context(*ac);
*ac = NULL;
}
if (status)
mlog_errno(status);
return status;
}
int ocfs2_reserve_cluster_bitmap_bits(struct ocfs2_super *osb,
struct ocfs2_alloc_context *ac)
{
int status;
ac->ac_which = OCFS2_AC_USE_MAIN;
ac->ac_group_search = ocfs2_cluster_group_search;
status = ocfs2_reserve_suballoc_bits(osb, ac,
GLOBAL_BITMAP_SYSTEM_INODE,
OCFS2_INVALID_SLOT, NULL,
ALLOC_NEW_GROUP);
if (status < 0 && status != -ENOSPC) {
mlog_errno(status);
goto bail;
}
bail:
return status;
}
static int ocfs2_reserve_clusters_with_limit(struct ocfs2_super *osb,
u32 bits_wanted, u64 max_block,
int flags,
struct ocfs2_alloc_context **ac)
{
int status;
*ac = kzalloc(sizeof(struct ocfs2_alloc_context), GFP_KERNEL);
if (!(*ac)) {
status = -ENOMEM;
mlog_errno(status);
goto bail;
}
(*ac)->ac_bits_wanted = bits_wanted;
(*ac)->ac_max_block = max_block;
status = -ENOSPC;
if (!(flags & ALLOC_GROUPS_FROM_GLOBAL) &&
ocfs2_alloc_should_use_local(osb, bits_wanted)) {
status = ocfs2_reserve_local_alloc_bits(osb,
bits_wanted,
*ac);
if ((status < 0) && (status != -ENOSPC)) {
mlog_errno(status);
goto bail;
}
}
if (status == -ENOSPC) {
status = ocfs2_reserve_cluster_bitmap_bits(osb, *ac);
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
}
status = 0;
bail:
if ((status < 0) && *ac) {
ocfs2_free_alloc_context(*ac);
*ac = NULL;
}
if (status)
mlog_errno(status);
return status;
}
int ocfs2_reserve_clusters(struct ocfs2_super *osb,
u32 bits_wanted,
struct ocfs2_alloc_context **ac)
{
return ocfs2_reserve_clusters_with_limit(osb, bits_wanted, 0,
ALLOC_NEW_GROUP, ac);
}
static int ocfs2_test_bg_bit_allocatable(struct buffer_head *bg_bh,
int nr)
{
struct ocfs2_group_desc *bg = (struct ocfs2_group_desc *) bg_bh->b_data;
int ret;
if (ocfs2_test_bit(nr, (unsigned long *)bg->bg_bitmap))
return 0;
if (!buffer_jbd(bg_bh))
return 1;
jbd_lock_bh_state(bg_bh);
bg = (struct ocfs2_group_desc *) bh2jh(bg_bh)->b_committed_data;
if (bg)
ret = !ocfs2_test_bit(nr, (unsigned long *)bg->bg_bitmap);
else
ret = 1;
jbd_unlock_bh_state(bg_bh);
return ret;
}
static int ocfs2_block_group_find_clear_bits(struct ocfs2_super *osb,
struct buffer_head *bg_bh,
unsigned int bits_wanted,
unsigned int total_bits,
struct ocfs2_suballoc_result *res)
{
void *bitmap;
u16 best_offset, best_size;
int offset, start, found, status = 0;
struct ocfs2_group_desc *bg = (struct ocfs2_group_desc *) bg_bh->b_data;
BUG_ON(!OCFS2_IS_VALID_GROUP_DESC(bg));
found = start = best_offset = best_size = 0;
bitmap = bg->bg_bitmap;
while((offset = ocfs2_find_next_zero_bit(bitmap, total_bits, start)) != -1) {
if (offset == total_bits)
break;
if (!ocfs2_test_bg_bit_allocatable(bg_bh, offset)) {
found = 0;
start = offset + 1;
} else if (offset == start) {
found++;
start++;
} else {
found = 1;
start = offset + 1;
}
if (found > best_size) {
best_size = found;
best_offset = start - found;
}
if (found == bits_wanted) {
break;
}
}
if (best_size) {
res->sr_bit_offset = best_offset;
res->sr_bits = best_size;
} else {
status = -ENOSPC;
}
return status;
}
int ocfs2_block_group_set_bits(handle_t *handle,
struct inode *alloc_inode,
struct ocfs2_group_desc *bg,
struct buffer_head *group_bh,
unsigned int bit_off,
unsigned int num_bits)
{
int status;
void *bitmap = bg->bg_bitmap;
int journal_type = OCFS2_JOURNAL_ACCESS_WRITE;
BUG_ON(!OCFS2_IS_VALID_GROUP_DESC(bg));
BUG_ON(le16_to_cpu(bg->bg_free_bits_count) < num_bits);
trace_ocfs2_block_group_set_bits(bit_off, num_bits);
if (ocfs2_is_cluster_bitmap(alloc_inode))
journal_type = OCFS2_JOURNAL_ACCESS_UNDO;
status = ocfs2_journal_access_gd(handle,
INODE_CACHE(alloc_inode),
group_bh,
journal_type);
if (status < 0) {
mlog_errno(status);
goto bail;
}
le16_add_cpu(&bg->bg_free_bits_count, -num_bits);
if (le16_to_cpu(bg->bg_free_bits_count) > le16_to_cpu(bg->bg_bits)) {
ocfs2_error(alloc_inode->i_sb, "Group descriptor # %llu has bit"
" count %u but claims %u are freed. num_bits %d",
(unsigned long long)le64_to_cpu(bg->bg_blkno),
le16_to_cpu(bg->bg_bits),
le16_to_cpu(bg->bg_free_bits_count), num_bits);
return -EROFS;
}
while(num_bits--)
ocfs2_set_bit(bit_off++, bitmap);
ocfs2_journal_dirty(handle, group_bh);
bail:
return status;
}
static inline u16 ocfs2_find_victim_chain(struct ocfs2_chain_list *cl)
{
u16 curr, best;
BUG_ON(!cl->cl_next_free_rec);
best = curr = 0;
while (curr < le16_to_cpu(cl->cl_next_free_rec)) {
if (le32_to_cpu(cl->cl_recs[curr].c_free) >
le32_to_cpu(cl->cl_recs[best].c_free))
best = curr;
curr++;
}
BUG_ON(best >= le16_to_cpu(cl->cl_next_free_rec));
return best;
}
static int ocfs2_relink_block_group(handle_t *handle,
struct inode *alloc_inode,
struct buffer_head *fe_bh,
struct buffer_head *bg_bh,
struct buffer_head *prev_bg_bh,
u16 chain)
{
int status;
u64 bg_ptr, prev_bg_ptr;
struct ocfs2_dinode *fe = (struct ocfs2_dinode *) fe_bh->b_data;
struct ocfs2_group_desc *bg = (struct ocfs2_group_desc *) bg_bh->b_data;
struct ocfs2_group_desc *prev_bg = (struct ocfs2_group_desc *) prev_bg_bh->b_data;
BUG_ON(!OCFS2_IS_VALID_GROUP_DESC(bg));
BUG_ON(!OCFS2_IS_VALID_GROUP_DESC(prev_bg));
trace_ocfs2_relink_block_group(
(unsigned long long)le64_to_cpu(fe->i_blkno), chain,
(unsigned long long)le64_to_cpu(bg->bg_blkno),
(unsigned long long)le64_to_cpu(prev_bg->bg_blkno));
bg_ptr = le64_to_cpu(bg->bg_next_group);
prev_bg_ptr = le64_to_cpu(prev_bg->bg_next_group);
status = ocfs2_journal_access_gd(handle, INODE_CACHE(alloc_inode),
prev_bg_bh,
OCFS2_JOURNAL_ACCESS_WRITE);
if (status < 0)
goto out;
prev_bg->bg_next_group = bg->bg_next_group;
ocfs2_journal_dirty(handle, prev_bg_bh);
status = ocfs2_journal_access_gd(handle, INODE_CACHE(alloc_inode),
bg_bh, OCFS2_JOURNAL_ACCESS_WRITE);
if (status < 0)
goto out_rollback_prev_bg;
bg->bg_next_group = fe->id2.i_chain.cl_recs[chain].c_blkno;
ocfs2_journal_dirty(handle, bg_bh);
status = ocfs2_journal_access_di(handle, INODE_CACHE(alloc_inode),
fe_bh, OCFS2_JOURNAL_ACCESS_WRITE);
if (status < 0)
goto out_rollback_bg;
fe->id2.i_chain.cl_recs[chain].c_blkno = bg->bg_blkno;
ocfs2_journal_dirty(handle, fe_bh);
out:
if (status < 0)
mlog_errno(status);
return status;
out_rollback_bg:
bg->bg_next_group = cpu_to_le64(bg_ptr);
out_rollback_prev_bg:
prev_bg->bg_next_group = cpu_to_le64(prev_bg_ptr);
goto out;
}
static inline int ocfs2_block_group_reasonably_empty(struct ocfs2_group_desc *bg,
u32 wanted)
{
return le16_to_cpu(bg->bg_free_bits_count) > wanted;
}
static int ocfs2_cluster_group_search(struct inode *inode,
struct buffer_head *group_bh,
u32 bits_wanted, u32 min_bits,
u64 max_block,
struct ocfs2_suballoc_result *res)
{
int search = -ENOSPC;
int ret;
u64 blkoff;
struct ocfs2_group_desc *gd = (struct ocfs2_group_desc *) group_bh->b_data;
struct ocfs2_super *osb = OCFS2_SB(inode->i_sb);
unsigned int max_bits, gd_cluster_off;
BUG_ON(!ocfs2_is_cluster_bitmap(inode));
if (gd->bg_free_bits_count) {
max_bits = le16_to_cpu(gd->bg_bits);
gd_cluster_off = ocfs2_blocks_to_clusters(inode->i_sb,
le64_to_cpu(gd->bg_blkno));
if ((gd_cluster_off + max_bits) >
OCFS2_I(inode)->ip_clusters) {
max_bits = OCFS2_I(inode)->ip_clusters - gd_cluster_off;
trace_ocfs2_cluster_group_search_wrong_max_bits(
(unsigned long long)le64_to_cpu(gd->bg_blkno),
le16_to_cpu(gd->bg_bits),
OCFS2_I(inode)->ip_clusters, max_bits);
}
ret = ocfs2_block_group_find_clear_bits(OCFS2_SB(inode->i_sb),
group_bh, bits_wanted,
max_bits, res);
if (ret)
return ret;
if (max_block) {
blkoff = ocfs2_clusters_to_blocks(inode->i_sb,
gd_cluster_off +
res->sr_bit_offset +
res->sr_bits);
trace_ocfs2_cluster_group_search_max_block(
(unsigned long long)blkoff,
(unsigned long long)max_block);
if (blkoff > max_block)
return -ENOSPC;
}
if (min_bits <= res->sr_bits)
search = 0;
else if (res->sr_bits) {
ocfs2_local_alloc_seen_free_bits(osb, res->sr_bits);
}
}
return search;
}
static int ocfs2_block_group_search(struct inode *inode,
struct buffer_head *group_bh,
u32 bits_wanted, u32 min_bits,
u64 max_block,
struct ocfs2_suballoc_result *res)
{
int ret = -ENOSPC;
u64 blkoff;
struct ocfs2_group_desc *bg = (struct ocfs2_group_desc *) group_bh->b_data;
BUG_ON(min_bits != 1);
BUG_ON(ocfs2_is_cluster_bitmap(inode));
if (bg->bg_free_bits_count) {
ret = ocfs2_block_group_find_clear_bits(OCFS2_SB(inode->i_sb),
group_bh, bits_wanted,
le16_to_cpu(bg->bg_bits),
res);
if (!ret && max_block) {
blkoff = le64_to_cpu(bg->bg_blkno) +
res->sr_bit_offset + res->sr_bits;
trace_ocfs2_block_group_search_max_block(
(unsigned long long)blkoff,
(unsigned long long)max_block);
if (blkoff > max_block)
ret = -ENOSPC;
}
}
return ret;
}
int ocfs2_alloc_dinode_update_counts(struct inode *inode,
handle_t *handle,
struct buffer_head *di_bh,
u32 num_bits,
u16 chain)
{
int ret;
u32 tmp_used;
struct ocfs2_dinode *di = (struct ocfs2_dinode *) di_bh->b_data;
struct ocfs2_chain_list *cl = (struct ocfs2_chain_list *) &di->id2.i_chain;
ret = ocfs2_journal_access_di(handle, INODE_CACHE(inode), di_bh,
OCFS2_JOURNAL_ACCESS_WRITE);
if (ret < 0) {
mlog_errno(ret);
goto out;
}
tmp_used = le32_to_cpu(di->id1.bitmap1.i_used);
di->id1.bitmap1.i_used = cpu_to_le32(num_bits + tmp_used);
le32_add_cpu(&cl->cl_recs[chain].c_free, -num_bits);
ocfs2_journal_dirty(handle, di_bh);
out:
return ret;
}
void ocfs2_rollback_alloc_dinode_counts(struct inode *inode,
struct buffer_head *di_bh,
u32 num_bits,
u16 chain)
{
u32 tmp_used;
struct ocfs2_dinode *di = (struct ocfs2_dinode *) di_bh->b_data;
struct ocfs2_chain_list *cl;
cl = (struct ocfs2_chain_list *)&di->id2.i_chain;
tmp_used = le32_to_cpu(di->id1.bitmap1.i_used);
di->id1.bitmap1.i_used = cpu_to_le32(tmp_used - num_bits);
le32_add_cpu(&cl->cl_recs[chain].c_free, num_bits);
}
static int ocfs2_bg_discontig_fix_by_rec(struct ocfs2_suballoc_result *res,
struct ocfs2_extent_rec *rec,
struct ocfs2_chain_list *cl)
{
unsigned int bpc = le16_to_cpu(cl->cl_bpc);
unsigned int bitoff = le32_to_cpu(rec->e_cpos) * bpc;
unsigned int bitcount = le16_to_cpu(rec->e_leaf_clusters) * bpc;
if (res->sr_bit_offset < bitoff)
return 0;
if (res->sr_bit_offset >= (bitoff + bitcount))
return 0;
res->sr_blkno = le64_to_cpu(rec->e_blkno) +
(res->sr_bit_offset - bitoff);
if ((res->sr_bit_offset + res->sr_bits) > (bitoff + bitcount))
res->sr_bits = (bitoff + bitcount) - res->sr_bit_offset;
return 1;
}
static void ocfs2_bg_discontig_fix_result(struct ocfs2_alloc_context *ac,
struct ocfs2_group_desc *bg,
struct ocfs2_suballoc_result *res)
{
int i;
u64 bg_blkno = res->sr_bg_blkno;
struct ocfs2_extent_rec *rec;
struct ocfs2_dinode *di = (struct ocfs2_dinode *)ac->ac_bh->b_data;
struct ocfs2_chain_list *cl = &di->id2.i_chain;
if (ocfs2_is_cluster_bitmap(ac->ac_inode)) {
res->sr_blkno = 0;
return;
}
res->sr_blkno = res->sr_bg_blkno + res->sr_bit_offset;
res->sr_bg_blkno = 0;
if (!ocfs2_supports_discontig_bg(OCFS2_SB(ac->ac_inode->i_sb)) ||
!bg->bg_list.l_next_free_rec)
return;
for (i = 0; i < le16_to_cpu(bg->bg_list.l_next_free_rec); i++) {
rec = &bg->bg_list.l_recs[i];
if (ocfs2_bg_discontig_fix_by_rec(res, rec, cl)) {
res->sr_bg_blkno = bg_blkno;
break;
}
}
}
static int ocfs2_search_one_group(struct ocfs2_alloc_context *ac,
handle_t *handle,
u32 bits_wanted,
u32 min_bits,
struct ocfs2_suballoc_result *res,
u16 *bits_left)
{
int ret;
struct buffer_head *group_bh = NULL;
struct ocfs2_group_desc *gd;
struct ocfs2_dinode *di = (struct ocfs2_dinode *)ac->ac_bh->b_data;
struct inode *alloc_inode = ac->ac_inode;
ret = ocfs2_read_group_descriptor(alloc_inode, di,
res->sr_bg_blkno, &group_bh);
if (ret < 0) {
mlog_errno(ret);
return ret;
}
gd = (struct ocfs2_group_desc *) group_bh->b_data;
ret = ac->ac_group_search(alloc_inode, group_bh, bits_wanted, min_bits,
ac->ac_max_block, res);
if (ret < 0) {
if (ret != -ENOSPC)
mlog_errno(ret);
goto out;
}
if (!ret)
ocfs2_bg_discontig_fix_result(ac, gd, res);
res->sr_bg_stable_blkno = group_bh->b_blocknr;
if (ac->ac_find_loc_only)
goto out_loc_only;
ret = ocfs2_alloc_dinode_update_counts(alloc_inode, handle, ac->ac_bh,
res->sr_bits,
le16_to_cpu(gd->bg_chain));
if (ret < 0) {
mlog_errno(ret);
goto out;
}
ret = ocfs2_block_group_set_bits(handle, alloc_inode, gd, group_bh,
res->sr_bit_offset, res->sr_bits);
if (ret < 0) {
ocfs2_rollback_alloc_dinode_counts(alloc_inode, ac->ac_bh,
res->sr_bits,
le16_to_cpu(gd->bg_chain));
mlog_errno(ret);
}
out_loc_only:
*bits_left = le16_to_cpu(gd->bg_free_bits_count);
out:
brelse(group_bh);
return ret;
}
static int ocfs2_search_chain(struct ocfs2_alloc_context *ac,
handle_t *handle,
u32 bits_wanted,
u32 min_bits,
struct ocfs2_suballoc_result *res,
u16 *bits_left)
{
int status;
u16 chain;
u64 next_group;
struct inode *alloc_inode = ac->ac_inode;
struct buffer_head *group_bh = NULL;
struct buffer_head *prev_group_bh = NULL;
struct ocfs2_dinode *fe = (struct ocfs2_dinode *) ac->ac_bh->b_data;
struct ocfs2_chain_list *cl = (struct ocfs2_chain_list *) &fe->id2.i_chain;
struct ocfs2_group_desc *bg;
chain = ac->ac_chain;
trace_ocfs2_search_chain_begin(
(unsigned long long)OCFS2_I(alloc_inode)->ip_blkno,
bits_wanted, chain);
status = ocfs2_read_group_descriptor(alloc_inode, fe,
le64_to_cpu(cl->cl_recs[chain].c_blkno),
&group_bh);
if (status < 0) {
mlog_errno(status);
goto bail;
}
bg = (struct ocfs2_group_desc *) group_bh->b_data;
status = -ENOSPC;
while ((status = ac->ac_group_search(alloc_inode, group_bh,
bits_wanted, min_bits,
ac->ac_max_block,
res)) == -ENOSPC) {
if (!bg->bg_next_group)
break;
brelse(prev_group_bh);
prev_group_bh = NULL;
next_group = le64_to_cpu(bg->bg_next_group);
prev_group_bh = group_bh;
group_bh = NULL;
status = ocfs2_read_group_descriptor(alloc_inode, fe,
next_group, &group_bh);
if (status < 0) {
mlog_errno(status);
goto bail;
}
bg = (struct ocfs2_group_desc *) group_bh->b_data;
}
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
trace_ocfs2_search_chain_succ(
(unsigned long long)le64_to_cpu(bg->bg_blkno), res->sr_bits);
res->sr_bg_blkno = le64_to_cpu(bg->bg_blkno);
BUG_ON(res->sr_bits == 0);
if (!status)
ocfs2_bg_discontig_fix_result(ac, bg, res);
res->sr_bg_stable_blkno = group_bh->b_blocknr;
if (!ac->ac_disable_chain_relink &&
(prev_group_bh) &&
(ocfs2_block_group_reasonably_empty(bg, res->sr_bits))) {
status = ocfs2_relink_block_group(handle, alloc_inode,
ac->ac_bh, group_bh,
prev_group_bh, chain);
if (status < 0) {
mlog_errno(status);
goto bail;
}
}
if (ac->ac_find_loc_only)
goto out_loc_only;
status = ocfs2_alloc_dinode_update_counts(alloc_inode, handle,
ac->ac_bh, res->sr_bits,
chain);
if (status) {
mlog_errno(status);
goto bail;
}
status = ocfs2_block_group_set_bits(handle,
alloc_inode,
bg,
group_bh,
res->sr_bit_offset,
res->sr_bits);
if (status < 0) {
ocfs2_rollback_alloc_dinode_counts(alloc_inode,
ac->ac_bh, res->sr_bits, chain);
mlog_errno(status);
goto bail;
}
trace_ocfs2_search_chain_end(
(unsigned long long)le64_to_cpu(fe->i_blkno),
res->sr_bits);
out_loc_only:
*bits_left = le16_to_cpu(bg->bg_free_bits_count);
bail:
brelse(group_bh);
brelse(prev_group_bh);
if (status)
mlog_errno(status);
return status;
}
static int ocfs2_claim_suballoc_bits(struct ocfs2_alloc_context *ac,
handle_t *handle,
u32 bits_wanted,
u32 min_bits,
struct ocfs2_suballoc_result *res)
{
int status;
u16 victim, i;
u16 bits_left = 0;
u64 hint = ac->ac_last_group;
struct ocfs2_chain_list *cl;
struct ocfs2_dinode *fe;
BUG_ON(ac->ac_bits_given >= ac->ac_bits_wanted);
BUG_ON(bits_wanted > (ac->ac_bits_wanted - ac->ac_bits_given));
BUG_ON(!ac->ac_bh);
fe = (struct ocfs2_dinode *) ac->ac_bh->b_data;
BUG_ON(!OCFS2_IS_VALID_DINODE(fe));
if (le32_to_cpu(fe->id1.bitmap1.i_used) >=
le32_to_cpu(fe->id1.bitmap1.i_total)) {
ocfs2_error(ac->ac_inode->i_sb,
"Chain allocator dinode %llu has %u used "
"bits but only %u total.",
(unsigned long long)le64_to_cpu(fe->i_blkno),
le32_to_cpu(fe->id1.bitmap1.i_used),
le32_to_cpu(fe->id1.bitmap1.i_total));
status = -EIO;
goto bail;
}
res->sr_bg_blkno = hint;
if (res->sr_bg_blkno) {
status = ocfs2_search_one_group(ac, handle, bits_wanted,
min_bits, res, &bits_left);
if (!status)
goto set_hint;
if (status < 0 && status != -ENOSPC) {
mlog_errno(status);
goto bail;
}
}
cl = (struct ocfs2_chain_list *) &fe->id2.i_chain;
victim = ocfs2_find_victim_chain(cl);
ac->ac_chain = victim;
status = ocfs2_search_chain(ac, handle, bits_wanted, min_bits,
res, &bits_left);
if (!status) {
hint = ocfs2_group_from_res(res);
goto set_hint;
}
if (status < 0 && status != -ENOSPC) {
mlog_errno(status);
goto bail;
}
trace_ocfs2_claim_suballoc_bits(victim);
ac->ac_disable_chain_relink = 1;
for (i = 0; i < le16_to_cpu(cl->cl_next_free_rec); i ++) {
if (i == victim)
continue;
if (!cl->cl_recs[i].c_free)
continue;
ac->ac_chain = i;
status = ocfs2_search_chain(ac, handle, bits_wanted, min_bits,
res, &bits_left);
if (!status) {
hint = ocfs2_group_from_res(res);
break;
}
if (status < 0 && status != -ENOSPC) {
mlog_errno(status);
goto bail;
}
}
set_hint:
if (status != -ENOSPC) {
if (bits_left < min_bits)
ac->ac_last_group = 0;
else
ac->ac_last_group = hint;
}
bail:
if (status)
mlog_errno(status);
return status;
}
int ocfs2_claim_metadata(handle_t *handle,
struct ocfs2_alloc_context *ac,
u32 bits_wanted,
u64 *suballoc_loc,
u16 *suballoc_bit_start,
unsigned int *num_bits,
u64 *blkno_start)
{
int status;
struct ocfs2_suballoc_result res = { .sr_blkno = 0, };
BUG_ON(!ac);
BUG_ON(ac->ac_bits_wanted < (ac->ac_bits_given + bits_wanted));
BUG_ON(ac->ac_which != OCFS2_AC_USE_META);
status = ocfs2_claim_suballoc_bits(ac,
handle,
bits_wanted,
1,
&res);
if (status < 0) {
mlog_errno(status);
goto bail;
}
atomic_inc(&OCFS2_SB(ac->ac_inode->i_sb)->alloc_stats.bg_allocs);
*suballoc_loc = res.sr_bg_blkno;
*suballoc_bit_start = res.sr_bit_offset;
*blkno_start = res.sr_blkno;
ac->ac_bits_given += res.sr_bits;
*num_bits = res.sr_bits;
status = 0;
bail:
if (status)
mlog_errno(status);
return status;
}
static void ocfs2_init_inode_ac_group(struct inode *dir,
struct buffer_head *parent_di_bh,
struct ocfs2_alloc_context *ac)
{
struct ocfs2_dinode *di = (struct ocfs2_dinode *)parent_di_bh->b_data;
if (OCFS2_I(dir)->ip_last_used_group &&
OCFS2_I(dir)->ip_last_used_slot == ac->ac_alloc_slot)
ac->ac_last_group = OCFS2_I(dir)->ip_last_used_group;
else if (le16_to_cpu(di->i_suballoc_slot) == ac->ac_alloc_slot) {
if (di->i_suballoc_loc)
ac->ac_last_group = le64_to_cpu(di->i_suballoc_loc);
else
ac->ac_last_group = ocfs2_which_suballoc_group(
le64_to_cpu(di->i_blkno),
le16_to_cpu(di->i_suballoc_bit));
}
}
static inline void ocfs2_save_inode_ac_group(struct inode *dir,
struct ocfs2_alloc_context *ac)
{
OCFS2_I(dir)->ip_last_used_group = ac->ac_last_group;
OCFS2_I(dir)->ip_last_used_slot = ac->ac_alloc_slot;
}
int ocfs2_find_new_inode_loc(struct inode *dir,
struct buffer_head *parent_fe_bh,
struct ocfs2_alloc_context *ac,
u64 *fe_blkno)
{
int ret;
handle_t *handle = NULL;
struct ocfs2_suballoc_result *res;
BUG_ON(!ac);
BUG_ON(ac->ac_bits_given != 0);
BUG_ON(ac->ac_bits_wanted != 1);
BUG_ON(ac->ac_which != OCFS2_AC_USE_INODE);
res = kzalloc(sizeof(*res), GFP_NOFS);
if (res == NULL) {
ret = -ENOMEM;
mlog_errno(ret);
goto out;
}
ocfs2_init_inode_ac_group(dir, parent_fe_bh, ac);
handle = ocfs2_start_trans(OCFS2_SB(dir->i_sb), OCFS2_SUBALLOC_ALLOC);
if (IS_ERR(handle)) {
ret = PTR_ERR(handle);
handle = NULL;
mlog_errno(ret);
goto out;
}
ac->ac_find_loc_only = 1;
ret = ocfs2_claim_suballoc_bits(ac, handle, 1, 1, res);
if (ret < 0) {
mlog_errno(ret);
goto out;
}
ac->ac_find_loc_priv = res;
*fe_blkno = res->sr_blkno;
ocfs2_update_inode_fsync_trans(handle, dir, 0);
out:
if (handle)
ocfs2_commit_trans(OCFS2_SB(dir->i_sb), handle);
if (ret)
kfree(res);
return ret;
}
int ocfs2_claim_new_inode_at_loc(handle_t *handle,
struct inode *dir,
struct ocfs2_alloc_context *ac,
u64 *suballoc_loc,
u16 *suballoc_bit,
u64 di_blkno)
{
int ret;
u16 chain;
struct ocfs2_suballoc_result *res = ac->ac_find_loc_priv;
struct buffer_head *bg_bh = NULL;
struct ocfs2_group_desc *bg;
struct ocfs2_dinode *di = (struct ocfs2_dinode *) ac->ac_bh->b_data;
BUG_ON(res->sr_blkno != di_blkno);
ret = ocfs2_read_group_descriptor(ac->ac_inode, di,
res->sr_bg_stable_blkno, &bg_bh);
if (ret) {
mlog_errno(ret);
goto out;
}
bg = (struct ocfs2_group_desc *) bg_bh->b_data;
chain = le16_to_cpu(bg->bg_chain);
ret = ocfs2_alloc_dinode_update_counts(ac->ac_inode, handle,
ac->ac_bh, res->sr_bits,
chain);
if (ret) {
mlog_errno(ret);
goto out;
}
ret = ocfs2_block_group_set_bits(handle,
ac->ac_inode,
bg,
bg_bh,
res->sr_bit_offset,
res->sr_bits);
if (ret < 0) {
ocfs2_rollback_alloc_dinode_counts(ac->ac_inode,
ac->ac_bh, res->sr_bits, chain);
mlog_errno(ret);
goto out;
}
trace_ocfs2_claim_new_inode_at_loc((unsigned long long)di_blkno,
res->sr_bits);
atomic_inc(&OCFS2_SB(ac->ac_inode->i_sb)->alloc_stats.bg_allocs);
BUG_ON(res->sr_bits != 1);
*suballoc_loc = res->sr_bg_blkno;
*suballoc_bit = res->sr_bit_offset;
ac->ac_bits_given++;
ocfs2_save_inode_ac_group(dir, ac);
out:
brelse(bg_bh);
return ret;
}
int ocfs2_claim_new_inode(handle_t *handle,
struct inode *dir,
struct buffer_head *parent_fe_bh,
struct ocfs2_alloc_context *ac,
u64 *suballoc_loc,
u16 *suballoc_bit,
u64 *fe_blkno)
{
int status;
struct ocfs2_suballoc_result res;
BUG_ON(!ac);
BUG_ON(ac->ac_bits_given != 0);
BUG_ON(ac->ac_bits_wanted != 1);
BUG_ON(ac->ac_which != OCFS2_AC_USE_INODE);
ocfs2_init_inode_ac_group(dir, parent_fe_bh, ac);
status = ocfs2_claim_suballoc_bits(ac,
handle,
1,
1,
&res);
if (status < 0) {
mlog_errno(status);
goto bail;
}
atomic_inc(&OCFS2_SB(ac->ac_inode->i_sb)->alloc_stats.bg_allocs);
BUG_ON(res.sr_bits != 1);
*suballoc_loc = res.sr_bg_blkno;
*suballoc_bit = res.sr_bit_offset;
*fe_blkno = res.sr_blkno;
ac->ac_bits_given++;
ocfs2_save_inode_ac_group(dir, ac);
status = 0;
bail:
if (status)
mlog_errno(status);
return status;
}
static inline u32 ocfs2_desc_bitmap_to_cluster_off(struct inode *inode,
u64 bg_blkno,
u16 bg_bit_off)
{
struct ocfs2_super *osb = OCFS2_SB(inode->i_sb);
u32 cluster = 0;
BUG_ON(!ocfs2_is_cluster_bitmap(inode));
if (bg_blkno != osb->first_cluster_group_blkno)
cluster = ocfs2_blocks_to_clusters(inode->i_sb, bg_blkno);
cluster += (u32) bg_bit_off;
return cluster;
}
u64 ocfs2_which_cluster_group(struct inode *inode, u32 cluster)
{
struct ocfs2_super *osb = OCFS2_SB(inode->i_sb);
u32 group_no;
BUG_ON(!ocfs2_is_cluster_bitmap(inode));
group_no = cluster / osb->bitmap_cpg;
if (!group_no)
return osb->first_cluster_group_blkno;
return ocfs2_clusters_to_blocks(inode->i_sb,
group_no * osb->bitmap_cpg);
}
static inline void ocfs2_block_to_cluster_group(struct inode *inode,
u64 data_blkno,
u64 *bg_blkno,
u16 *bg_bit_off)
{
struct ocfs2_super *osb = OCFS2_SB(inode->i_sb);
u32 data_cluster = ocfs2_blocks_to_clusters(osb->sb, data_blkno);
BUG_ON(!ocfs2_is_cluster_bitmap(inode));
*bg_blkno = ocfs2_which_cluster_group(inode,
data_cluster);
if (*bg_blkno == osb->first_cluster_group_blkno)
*bg_bit_off = (u16) data_cluster;
else
*bg_bit_off = (u16) ocfs2_blocks_to_clusters(osb->sb,
data_blkno - *bg_blkno);
}
int __ocfs2_claim_clusters(handle_t *handle,
struct ocfs2_alloc_context *ac,
u32 min_clusters,
u32 max_clusters,
u32 *cluster_start,
u32 *num_clusters)
{
int status;
unsigned int bits_wanted = max_clusters;
struct ocfs2_suballoc_result res = { .sr_blkno = 0, };
struct ocfs2_super *osb = OCFS2_SB(ac->ac_inode->i_sb);
BUG_ON(ac->ac_bits_given >= ac->ac_bits_wanted);
BUG_ON(ac->ac_which != OCFS2_AC_USE_LOCAL
&& ac->ac_which != OCFS2_AC_USE_MAIN);
if (ac->ac_which == OCFS2_AC_USE_LOCAL) {
WARN_ON(min_clusters > 1);
status = ocfs2_claim_local_alloc_bits(osb,
handle,
ac,
bits_wanted,
cluster_start,
num_clusters);
if (!status)
atomic_inc(&osb->alloc_stats.local_data);
} else {
if (min_clusters > (osb->bitmap_cpg - 1)) {
mlog(ML_ERROR, "minimum allocation requested %u exceeds "
"group bitmap size %u!\n", min_clusters,
osb->bitmap_cpg);
status = -ENOSPC;
goto bail;
}
if (bits_wanted > (osb->bitmap_cpg - 1))
bits_wanted = osb->bitmap_cpg - 1;
status = ocfs2_claim_suballoc_bits(ac,
handle,
bits_wanted,
min_clusters,
&res);
if (!status) {
BUG_ON(res.sr_blkno);
*cluster_start =
ocfs2_desc_bitmap_to_cluster_off(ac->ac_inode,
res.sr_bg_blkno,
res.sr_bit_offset);
atomic_inc(&osb->alloc_stats.bitmap_data);
*num_clusters = res.sr_bits;
}
}
if (status < 0) {
if (status != -ENOSPC)
mlog_errno(status);
goto bail;
}
ac->ac_bits_given += *num_clusters;
bail:
if (status)
mlog_errno(status);
return status;
}
int ocfs2_claim_clusters(handle_t *handle,
struct ocfs2_alloc_context *ac,
u32 min_clusters,
u32 *cluster_start,
u32 *num_clusters)
{
unsigned int bits_wanted = ac->ac_bits_wanted - ac->ac_bits_given;
return __ocfs2_claim_clusters(handle, ac, min_clusters,
bits_wanted, cluster_start, num_clusters);
}
static int ocfs2_block_group_clear_bits(handle_t *handle,
struct inode *alloc_inode,
struct ocfs2_group_desc *bg,
struct buffer_head *group_bh,
unsigned int bit_off,
unsigned int num_bits,
void (*undo_fn)(unsigned int bit,
unsigned long *bmap))
{
int status;
unsigned int tmp;
struct ocfs2_group_desc *undo_bg = NULL;
BUG_ON(!OCFS2_IS_VALID_GROUP_DESC(bg));
trace_ocfs2_block_group_clear_bits(bit_off, num_bits);
BUG_ON(undo_fn && !ocfs2_is_cluster_bitmap(alloc_inode));
status = ocfs2_journal_access_gd(handle, INODE_CACHE(alloc_inode),
group_bh,
undo_fn ?
OCFS2_JOURNAL_ACCESS_UNDO :
OCFS2_JOURNAL_ACCESS_WRITE);
if (status < 0) {
mlog_errno(status);
goto bail;
}
if (undo_fn) {
jbd_lock_bh_state(group_bh);
undo_bg = (struct ocfs2_group_desc *)
bh2jh(group_bh)->b_committed_data;
BUG_ON(!undo_bg);
}
tmp = num_bits;
while(tmp--) {
ocfs2_clear_bit((bit_off + tmp),
(unsigned long *) bg->bg_bitmap);
if (undo_fn)
undo_fn(bit_off + tmp,
(unsigned long *) undo_bg->bg_bitmap);
}
le16_add_cpu(&bg->bg_free_bits_count, num_bits);
if (le16_to_cpu(bg->bg_free_bits_count) > le16_to_cpu(bg->bg_bits)) {
ocfs2_error(alloc_inode->i_sb, "Group descriptor # %llu has bit"
" count %u but claims %u are freed. num_bits %d",
(unsigned long long)le64_to_cpu(bg->bg_blkno),
le16_to_cpu(bg->bg_bits),
le16_to_cpu(bg->bg_free_bits_count), num_bits);
return -EROFS;
}
if (undo_fn)
jbd_unlock_bh_state(group_bh);
ocfs2_journal_dirty(handle, group_bh);
bail:
return status;
}
static int _ocfs2_free_suballoc_bits(handle_t *handle,
struct inode *alloc_inode,
struct buffer_head *alloc_bh,
unsigned int start_bit,
u64 bg_blkno,
unsigned int count,
void (*undo_fn)(unsigned int bit,
unsigned long *bitmap))
{
int status = 0;
u32 tmp_used;
struct ocfs2_dinode *fe = (struct ocfs2_dinode *) alloc_bh->b_data;
struct ocfs2_chain_list *cl = &fe->id2.i_chain;
struct buffer_head *group_bh = NULL;
struct ocfs2_group_desc *group;
BUG_ON(!OCFS2_IS_VALID_DINODE(fe));
BUG_ON((count + start_bit) > ocfs2_bits_per_group(cl));
trace_ocfs2_free_suballoc_bits(
(unsigned long long)OCFS2_I(alloc_inode)->ip_blkno,
(unsigned long long)bg_blkno,
start_bit, count);
status = ocfs2_read_group_descriptor(alloc_inode, fe, bg_blkno,
&group_bh);
if (status < 0) {
mlog_errno(status);
goto bail;
}
group = (struct ocfs2_group_desc *) group_bh->b_data;
BUG_ON((count + start_bit) > le16_to_cpu(group->bg_bits));
status = ocfs2_block_group_clear_bits(handle, alloc_inode,
group, group_bh,
start_bit, count, undo_fn);
if (status < 0) {
mlog_errno(status);
goto bail;
}
status = ocfs2_journal_access_di(handle, INODE_CACHE(alloc_inode),
alloc_bh, OCFS2_JOURNAL_ACCESS_WRITE);
if (status < 0) {
mlog_errno(status);
goto bail;
}
le32_add_cpu(&cl->cl_recs[le16_to_cpu(group->bg_chain)].c_free,
count);
tmp_used = le32_to_cpu(fe->id1.bitmap1.i_used);
fe->id1.bitmap1.i_used = cpu_to_le32(tmp_used - count);
ocfs2_journal_dirty(handle, alloc_bh);
bail:
brelse(group_bh);
if (status)
mlog_errno(status);
return status;
}
int ocfs2_free_suballoc_bits(handle_t *handle,
struct inode *alloc_inode,
struct buffer_head *alloc_bh,
unsigned int start_bit,
u64 bg_blkno,
unsigned int count)
{
return _ocfs2_free_suballoc_bits(handle, alloc_inode, alloc_bh,
start_bit, bg_blkno, count, NULL);
}
int ocfs2_free_dinode(handle_t *handle,
struct inode *inode_alloc_inode,
struct buffer_head *inode_alloc_bh,
struct ocfs2_dinode *di)
{
u64 blk = le64_to_cpu(di->i_blkno);
u16 bit = le16_to_cpu(di->i_suballoc_bit);
u64 bg_blkno = ocfs2_which_suballoc_group(blk, bit);
if (di->i_suballoc_loc)
bg_blkno = le64_to_cpu(di->i_suballoc_loc);
return ocfs2_free_suballoc_bits(handle, inode_alloc_inode,
inode_alloc_bh, bit, bg_blkno, 1);
}
static int _ocfs2_free_clusters(handle_t *handle,
struct inode *bitmap_inode,
struct buffer_head *bitmap_bh,
u64 start_blk,
unsigned int num_clusters,
void (*undo_fn)(unsigned int bit,
unsigned long *bitmap))
{
int status;
u16 bg_start_bit;
u64 bg_blkno;
struct ocfs2_dinode *fe;
BUG_ON(start_blk != ocfs2_clusters_to_blocks(bitmap_inode->i_sb, ocfs2_blocks_to_clusters(bitmap_inode->i_sb, start_blk)));
fe = (struct ocfs2_dinode *) bitmap_bh->b_data;
ocfs2_block_to_cluster_group(bitmap_inode, start_blk, &bg_blkno,
&bg_start_bit);
trace_ocfs2_free_clusters((unsigned long long)bg_blkno,
(unsigned long long)start_blk,
bg_start_bit, num_clusters);
status = _ocfs2_free_suballoc_bits(handle, bitmap_inode, bitmap_bh,
bg_start_bit, bg_blkno,
num_clusters, undo_fn);
if (status < 0) {
mlog_errno(status);
goto out;
}
ocfs2_local_alloc_seen_free_bits(OCFS2_SB(bitmap_inode->i_sb),
num_clusters);
out:
if (status)
mlog_errno(status);
return status;
}
int ocfs2_free_clusters(handle_t *handle,
struct inode *bitmap_inode,
struct buffer_head *bitmap_bh,
u64 start_blk,
unsigned int num_clusters)
{
return _ocfs2_free_clusters(handle, bitmap_inode, bitmap_bh,
start_blk, num_clusters,
_ocfs2_set_bit);
}
int ocfs2_release_clusters(handle_t *handle,
struct inode *bitmap_inode,
struct buffer_head *bitmap_bh,
u64 start_blk,
unsigned int num_clusters)
{
return _ocfs2_free_clusters(handle, bitmap_inode, bitmap_bh,
start_blk, num_clusters,
_ocfs2_clear_bit);
}
static inline void ocfs2_debug_bg(struct ocfs2_group_desc *bg)
{
printk("Block Group:\n");
printk("bg_signature: %s\n", bg->bg_signature);
printk("bg_size: %u\n", bg->bg_size);
printk("bg_bits: %u\n", bg->bg_bits);
printk("bg_free_bits_count: %u\n", bg->bg_free_bits_count);
printk("bg_chain: %u\n", bg->bg_chain);
printk("bg_generation: %u\n", le32_to_cpu(bg->bg_generation));
printk("bg_next_group: %llu\n",
(unsigned long long)bg->bg_next_group);
printk("bg_parent_dinode: %llu\n",
(unsigned long long)bg->bg_parent_dinode);
printk("bg_blkno: %llu\n",
(unsigned long long)bg->bg_blkno);
}
static inline void ocfs2_debug_suballoc_inode(struct ocfs2_dinode *fe)
{
int i;
printk("Suballoc Inode %llu:\n", (unsigned long long)fe->i_blkno);
printk("i_signature: %s\n", fe->i_signature);
printk("i_size: %llu\n",
(unsigned long long)fe->i_size);
printk("i_clusters: %u\n", fe->i_clusters);
printk("i_generation: %u\n",
le32_to_cpu(fe->i_generation));
printk("id1.bitmap1.i_used: %u\n",
le32_to_cpu(fe->id1.bitmap1.i_used));
printk("id1.bitmap1.i_total: %u\n",
le32_to_cpu(fe->id1.bitmap1.i_total));
printk("id2.i_chain.cl_cpg: %u\n", fe->id2.i_chain.cl_cpg);
printk("id2.i_chain.cl_bpc: %u\n", fe->id2.i_chain.cl_bpc);
printk("id2.i_chain.cl_count: %u\n", fe->id2.i_chain.cl_count);
printk("id2.i_chain.cl_next_free_rec: %u\n",
fe->id2.i_chain.cl_next_free_rec);
for(i = 0; i < fe->id2.i_chain.cl_next_free_rec; i++) {
printk("fe->id2.i_chain.cl_recs[%d].c_free: %u\n", i,
fe->id2.i_chain.cl_recs[i].c_free);
printk("fe->id2.i_chain.cl_recs[%d].c_total: %u\n", i,
fe->id2.i_chain.cl_recs[i].c_total);
printk("fe->id2.i_chain.cl_recs[%d].c_blkno: %llu\n", i,
(unsigned long long)fe->id2.i_chain.cl_recs[i].c_blkno);
}
}
int ocfs2_lock_allocators(struct inode *inode,
struct ocfs2_extent_tree *et,
u32 clusters_to_add, u32 extents_to_split,
struct ocfs2_alloc_context **data_ac,
struct ocfs2_alloc_context **meta_ac)
{
int ret = 0, num_free_extents;
unsigned int max_recs_needed = clusters_to_add + 2 * extents_to_split;
struct ocfs2_super *osb = OCFS2_SB(inode->i_sb);
*meta_ac = NULL;
if (data_ac)
*data_ac = NULL;
BUG_ON(clusters_to_add != 0 && data_ac == NULL);
num_free_extents = ocfs2_num_free_extents(osb, et);
if (num_free_extents < 0) {
ret = num_free_extents;
mlog_errno(ret);
goto out;
}
if (!num_free_extents ||
(ocfs2_sparse_alloc(osb) && num_free_extents < max_recs_needed)) {
ret = ocfs2_reserve_new_metadata(osb, et->et_root_el, meta_ac);
if (ret < 0) {
if (ret != -ENOSPC)
mlog_errno(ret);
goto out;
}
}
if (clusters_to_add == 0)
goto out;
ret = ocfs2_reserve_clusters(osb, clusters_to_add, data_ac);
if (ret < 0) {
if (ret != -ENOSPC)
mlog_errno(ret);
goto out;
}
out:
if (ret) {
if (*meta_ac) {
ocfs2_free_alloc_context(*meta_ac);
*meta_ac = NULL;
}
}
return ret;
}
static int ocfs2_get_suballoc_slot_bit(struct ocfs2_super *osb, u64 blkno,
u16 *suballoc_slot, u64 *group_blkno,
u16 *suballoc_bit)
{
int status;
struct buffer_head *inode_bh = NULL;
struct ocfs2_dinode *inode_fe;
trace_ocfs2_get_suballoc_slot_bit((unsigned long long)blkno);
status = ocfs2_read_blocks_sync(osb, blkno, 1, &inode_bh);
if (status < 0) {
mlog(ML_ERROR, "read block %llu failed %d\n",
(unsigned long long)blkno, status);
goto bail;
}
inode_fe = (struct ocfs2_dinode *) inode_bh->b_data;
if (!OCFS2_IS_VALID_DINODE(inode_fe)) {
mlog(ML_ERROR, "invalid inode %llu requested\n",
(unsigned long long)blkno);
status = -EINVAL;
goto bail;
}
if (le16_to_cpu(inode_fe->i_suballoc_slot) != (u16)OCFS2_INVALID_SLOT &&
(u32)le16_to_cpu(inode_fe->i_suballoc_slot) > osb->max_slots - 1) {
mlog(ML_ERROR, "inode %llu has invalid suballoc slot %u\n",
(unsigned long long)blkno,
(u32)le16_to_cpu(inode_fe->i_suballoc_slot));
status = -EINVAL;
goto bail;
}
if (suballoc_slot)
*suballoc_slot = le16_to_cpu(inode_fe->i_suballoc_slot);
if (suballoc_bit)
*suballoc_bit = le16_to_cpu(inode_fe->i_suballoc_bit);
if (group_blkno)
*group_blkno = le64_to_cpu(inode_fe->i_suballoc_loc);
bail:
brelse(inode_bh);
if (status)
mlog_errno(status);
return status;
}
static int ocfs2_test_suballoc_bit(struct ocfs2_super *osb,
struct inode *suballoc,
struct buffer_head *alloc_bh,
u64 group_blkno, u64 blkno,
u16 bit, int *res)
{
struct ocfs2_dinode *alloc_di;
struct ocfs2_group_desc *group;
struct buffer_head *group_bh = NULL;
u64 bg_blkno;
int status;
trace_ocfs2_test_suballoc_bit((unsigned long long)blkno,
(unsigned int)bit);
alloc_di = (struct ocfs2_dinode *)alloc_bh->b_data;
if ((bit + 1) > ocfs2_bits_per_group(&alloc_di->id2.i_chain)) {
mlog(ML_ERROR, "suballoc bit %u out of range of %u\n",
(unsigned int)bit,
ocfs2_bits_per_group(&alloc_di->id2.i_chain));
status = -EINVAL;
goto bail;
}
bg_blkno = group_blkno ? group_blkno :
ocfs2_which_suballoc_group(blkno, bit);
status = ocfs2_read_group_descriptor(suballoc, alloc_di, bg_blkno,
&group_bh);
if (status < 0) {
mlog(ML_ERROR, "read group %llu failed %d\n",
(unsigned long long)bg_blkno, status);
goto bail;
}
group = (struct ocfs2_group_desc *) group_bh->b_data;
*res = ocfs2_test_bit(bit, (unsigned long *)group->bg_bitmap);
bail:
brelse(group_bh);
if (status)
mlog_errno(status);
return status;
}
int ocfs2_test_inode_bit(struct ocfs2_super *osb, u64 blkno, int *res)
{
int status;
u64 group_blkno = 0;
u16 suballoc_bit = 0, suballoc_slot = 0;
struct inode *inode_alloc_inode;
struct buffer_head *alloc_bh = NULL;
trace_ocfs2_test_inode_bit((unsigned long long)blkno);
status = ocfs2_get_suballoc_slot_bit(osb, blkno, &suballoc_slot,
&group_blkno, &suballoc_bit);
if (status < 0) {
mlog(ML_ERROR, "get alloc slot and bit failed %d\n", status);
goto bail;
}
inode_alloc_inode =
ocfs2_get_system_file_inode(osb, INODE_ALLOC_SYSTEM_INODE,
suballoc_slot);
if (!inode_alloc_inode) {
status = -EINVAL;
mlog(ML_ERROR, "unable to get alloc inode in slot %u\n",
(u32)suballoc_slot);
goto bail;
}
mutex_lock(&inode_alloc_inode->i_mutex);
status = ocfs2_inode_lock(inode_alloc_inode, &alloc_bh, 0);
if (status < 0) {
mutex_unlock(&inode_alloc_inode->i_mutex);
iput(inode_alloc_inode);
mlog(ML_ERROR, "lock on alloc inode on slot %u failed %d\n",
(u32)suballoc_slot, status);
goto bail;
}
status = ocfs2_test_suballoc_bit(osb, inode_alloc_inode, alloc_bh,
group_blkno, blkno, suballoc_bit, res);
if (status < 0)
mlog(ML_ERROR, "test suballoc bit failed %d\n", status);
ocfs2_inode_unlock(inode_alloc_inode, 0);
mutex_unlock(&inode_alloc_inode->i_mutex);
iput(inode_alloc_inode);
brelse(alloc_bh);
bail:
if (status)
mlog_errno(status);
return status;
}
