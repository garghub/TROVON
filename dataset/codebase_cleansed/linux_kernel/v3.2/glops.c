static void gfs2_ail_error(struct gfs2_glock *gl, const struct buffer_head *bh)
{
fs_err(gl->gl_sbd, "AIL buffer %p: blocknr %llu state 0x%08lx mapping %p page state 0x%lx\n",
bh, (unsigned long long)bh->b_blocknr, bh->b_state,
bh->b_page->mapping, bh->b_page->flags);
fs_err(gl->gl_sbd, "AIL glock %u:%llu mapping %p\n",
gl->gl_name.ln_type, gl->gl_name.ln_number,
gfs2_glock2aspace(gl));
gfs2_lm_withdraw(gl->gl_sbd, "AIL error\n");
}
static void __gfs2_ail_flush(struct gfs2_glock *gl, bool fsync)
{
struct gfs2_sbd *sdp = gl->gl_sbd;
struct list_head *head = &gl->gl_ail_list;
struct gfs2_bufdata *bd, *tmp;
struct buffer_head *bh;
const unsigned long b_state = (1UL << BH_Dirty)|(1UL << BH_Pinned)|(1UL << BH_Lock);
sector_t blocknr;
gfs2_log_lock(sdp);
spin_lock(&sdp->sd_ail_lock);
list_for_each_entry_safe(bd, tmp, head, bd_ail_gl_list) {
bh = bd->bd_bh;
if (bh->b_state & b_state) {
if (fsync)
continue;
gfs2_ail_error(gl, bh);
}
blocknr = bh->b_blocknr;
bh->b_private = NULL;
gfs2_remove_from_ail(bd);
bd->bd_bh = NULL;
bd->bd_blkno = blocknr;
gfs2_trans_add_revoke(sdp, bd);
}
BUG_ON(!fsync && atomic_read(&gl->gl_ail_count));
spin_unlock(&sdp->sd_ail_lock);
gfs2_log_unlock(sdp);
}
static void gfs2_ail_empty_gl(struct gfs2_glock *gl)
{
struct gfs2_sbd *sdp = gl->gl_sbd;
struct gfs2_trans tr;
memset(&tr, 0, sizeof(tr));
tr.tr_revokes = atomic_read(&gl->gl_ail_count);
if (!tr.tr_revokes)
return;
tr.tr_reserved = 1 + gfs2_struct2blk(sdp, tr.tr_revokes, sizeof(u64));
tr.tr_ip = (unsigned long)__builtin_return_address(0);
INIT_LIST_HEAD(&tr.tr_list_buf);
gfs2_log_reserve(sdp, tr.tr_reserved);
BUG_ON(current->journal_info);
current->journal_info = &tr;
__gfs2_ail_flush(gl, 0);
gfs2_trans_end(sdp);
gfs2_log_flush(sdp, NULL);
}
void gfs2_ail_flush(struct gfs2_glock *gl, bool fsync)
{
struct gfs2_sbd *sdp = gl->gl_sbd;
unsigned int revokes = atomic_read(&gl->gl_ail_count);
int ret;
if (!revokes)
return;
ret = gfs2_trans_begin(sdp, 0, revokes);
if (ret)
return;
__gfs2_ail_flush(gl, fsync);
gfs2_trans_end(sdp);
gfs2_log_flush(sdp, NULL);
}
static void rgrp_go_sync(struct gfs2_glock *gl)
{
struct address_space *metamapping = gfs2_glock2aspace(gl);
struct gfs2_rgrpd *rgd;
int error;
if (!test_and_clear_bit(GLF_DIRTY, &gl->gl_flags))
return;
BUG_ON(gl->gl_state != LM_ST_EXCLUSIVE);
gfs2_log_flush(gl->gl_sbd, gl);
filemap_fdatawrite(metamapping);
error = filemap_fdatawait(metamapping);
mapping_set_error(metamapping, error);
gfs2_ail_empty_gl(gl);
spin_lock(&gl->gl_spin);
rgd = gl->gl_object;
if (rgd)
gfs2_free_clones(rgd);
spin_unlock(&gl->gl_spin);
}
static void rgrp_go_inval(struct gfs2_glock *gl, int flags)
{
struct address_space *mapping = gfs2_glock2aspace(gl);
BUG_ON(!(flags & DIO_METADATA));
gfs2_assert_withdraw(gl->gl_sbd, !atomic_read(&gl->gl_ail_count));
truncate_inode_pages(mapping, 0);
if (gl->gl_object) {
struct gfs2_rgrpd *rgd = (struct gfs2_rgrpd *)gl->gl_object;
rgd->rd_flags &= ~GFS2_RDF_UPTODATE;
}
}
static void inode_go_sync(struct gfs2_glock *gl)
{
struct gfs2_inode *ip = gl->gl_object;
struct address_space *metamapping = gfs2_glock2aspace(gl);
int error;
if (ip && !S_ISREG(ip->i_inode.i_mode))
ip = NULL;
if (ip && test_and_clear_bit(GIF_SW_PAGED, &ip->i_flags))
unmap_shared_mapping_range(ip->i_inode.i_mapping, 0, 0);
if (!test_and_clear_bit(GLF_DIRTY, &gl->gl_flags))
return;
BUG_ON(gl->gl_state != LM_ST_EXCLUSIVE);
gfs2_log_flush(gl->gl_sbd, gl);
filemap_fdatawrite(metamapping);
if (ip) {
struct address_space *mapping = ip->i_inode.i_mapping;
filemap_fdatawrite(mapping);
error = filemap_fdatawait(mapping);
mapping_set_error(mapping, error);
}
error = filemap_fdatawait(metamapping);
mapping_set_error(metamapping, error);
gfs2_ail_empty_gl(gl);
smp_mb__before_clear_bit();
clear_bit(GLF_DIRTY, &gl->gl_flags);
}
static void inode_go_inval(struct gfs2_glock *gl, int flags)
{
struct gfs2_inode *ip = gl->gl_object;
gfs2_assert_withdraw(gl->gl_sbd, !atomic_read(&gl->gl_ail_count));
if (flags & DIO_METADATA) {
struct address_space *mapping = gfs2_glock2aspace(gl);
truncate_inode_pages(mapping, 0);
if (ip) {
set_bit(GIF_INVALID, &ip->i_flags);
forget_all_cached_acls(&ip->i_inode);
gfs2_dir_hash_inval(ip);
}
}
if (ip == GFS2_I(gl->gl_sbd->sd_rindex)) {
gfs2_log_flush(gl->gl_sbd, NULL);
gl->gl_sbd->sd_rindex_uptodate = 0;
}
if (ip && S_ISREG(ip->i_inode.i_mode))
truncate_inode_pages(ip->i_inode.i_mapping, 0);
}
static int inode_go_demote_ok(const struct gfs2_glock *gl)
{
struct gfs2_sbd *sdp = gl->gl_sbd;
struct gfs2_holder *gh;
if (sdp->sd_jindex == gl->gl_object || sdp->sd_rindex == gl->gl_object)
return 0;
if (!list_empty(&gl->gl_holders)) {
gh = list_entry(gl->gl_holders.next, struct gfs2_holder, gh_list);
if (gh->gh_list.next != &gl->gl_holders)
return 0;
}
return 1;
}
static void gfs2_set_nlink(struct inode *inode, u32 nlink)
{
if ((inode->i_nlink != nlink) && (inode->i_nlink != 0)) {
if (nlink == 0)
clear_nlink(inode);
else
set_nlink(inode, nlink);
}
}
static int gfs2_dinode_in(struct gfs2_inode *ip, const void *buf)
{
const struct gfs2_dinode *str = buf;
struct timespec atime;
u16 height, depth;
if (unlikely(ip->i_no_addr != be64_to_cpu(str->di_num.no_addr)))
goto corrupt;
ip->i_no_formal_ino = be64_to_cpu(str->di_num.no_formal_ino);
ip->i_inode.i_mode = be32_to_cpu(str->di_mode);
ip->i_inode.i_rdev = 0;
switch (ip->i_inode.i_mode & S_IFMT) {
case S_IFBLK:
case S_IFCHR:
ip->i_inode.i_rdev = MKDEV(be32_to_cpu(str->di_major),
be32_to_cpu(str->di_minor));
break;
};
ip->i_inode.i_uid = be32_to_cpu(str->di_uid);
ip->i_inode.i_gid = be32_to_cpu(str->di_gid);
gfs2_set_nlink(&ip->i_inode, be32_to_cpu(str->di_nlink));
i_size_write(&ip->i_inode, be64_to_cpu(str->di_size));
gfs2_set_inode_blocks(&ip->i_inode, be64_to_cpu(str->di_blocks));
atime.tv_sec = be64_to_cpu(str->di_atime);
atime.tv_nsec = be32_to_cpu(str->di_atime_nsec);
if (timespec_compare(&ip->i_inode.i_atime, &atime) < 0)
ip->i_inode.i_atime = atime;
ip->i_inode.i_mtime.tv_sec = be64_to_cpu(str->di_mtime);
ip->i_inode.i_mtime.tv_nsec = be32_to_cpu(str->di_mtime_nsec);
ip->i_inode.i_ctime.tv_sec = be64_to_cpu(str->di_ctime);
ip->i_inode.i_ctime.tv_nsec = be32_to_cpu(str->di_ctime_nsec);
ip->i_goal = be64_to_cpu(str->di_goal_meta);
ip->i_generation = be64_to_cpu(str->di_generation);
ip->i_diskflags = be32_to_cpu(str->di_flags);
ip->i_eattr = be64_to_cpu(str->di_eattr);
gfs2_set_inode_flags(&ip->i_inode);
height = be16_to_cpu(str->di_height);
if (unlikely(height > GFS2_MAX_META_HEIGHT))
goto corrupt;
ip->i_height = (u8)height;
depth = be16_to_cpu(str->di_depth);
if (unlikely(depth > GFS2_DIR_MAX_DEPTH))
goto corrupt;
ip->i_depth = (u8)depth;
ip->i_entries = be32_to_cpu(str->di_entries);
if (S_ISREG(ip->i_inode.i_mode))
gfs2_set_aops(&ip->i_inode);
return 0;
corrupt:
gfs2_consist_inode(ip);
return -EIO;
}
int gfs2_inode_refresh(struct gfs2_inode *ip)
{
struct buffer_head *dibh;
int error;
error = gfs2_meta_inode_buffer(ip, &dibh);
if (error)
return error;
if (gfs2_metatype_check(GFS2_SB(&ip->i_inode), dibh, GFS2_METATYPE_DI)) {
brelse(dibh);
return -EIO;
}
error = gfs2_dinode_in(ip, dibh->b_data);
brelse(dibh);
clear_bit(GIF_INVALID, &ip->i_flags);
return error;
}
static int inode_go_lock(struct gfs2_holder *gh)
{
struct gfs2_glock *gl = gh->gh_gl;
struct gfs2_sbd *sdp = gl->gl_sbd;
struct gfs2_inode *ip = gl->gl_object;
int error = 0;
if (!ip || (gh->gh_flags & GL_SKIP))
return 0;
if (test_bit(GIF_INVALID, &ip->i_flags)) {
error = gfs2_inode_refresh(ip);
if (error)
return error;
}
if ((ip->i_diskflags & GFS2_DIF_TRUNC_IN_PROG) &&
(gl->gl_state == LM_ST_EXCLUSIVE) &&
(gh->gh_state == LM_ST_EXCLUSIVE)) {
spin_lock(&sdp->sd_trunc_lock);
if (list_empty(&ip->i_trunc_list))
list_add(&sdp->sd_trunc_list, &ip->i_trunc_list);
spin_unlock(&sdp->sd_trunc_lock);
wake_up(&sdp->sd_quota_wait);
return 1;
}
return error;
}
static int inode_go_dump(struct seq_file *seq, const struct gfs2_glock *gl)
{
const struct gfs2_inode *ip = gl->gl_object;
if (ip == NULL)
return 0;
gfs2_print_dbg(seq, " I: n:%llu/%llu t:%u f:0x%02lx d:0x%08x s:%llu\n",
(unsigned long long)ip->i_no_formal_ino,
(unsigned long long)ip->i_no_addr,
IF2DT(ip->i_inode.i_mode), ip->i_flags,
(unsigned int)ip->i_diskflags,
(unsigned long long)i_size_read(&ip->i_inode));
return 0;
}
static void trans_go_sync(struct gfs2_glock *gl)
{
struct gfs2_sbd *sdp = gl->gl_sbd;
if (gl->gl_state != LM_ST_UNLOCKED &&
test_bit(SDF_JOURNAL_LIVE, &sdp->sd_flags)) {
gfs2_meta_syncfs(sdp);
gfs2_log_shutdown(sdp);
}
}
static int trans_go_xmote_bh(struct gfs2_glock *gl, struct gfs2_holder *gh)
{
struct gfs2_sbd *sdp = gl->gl_sbd;
struct gfs2_inode *ip = GFS2_I(sdp->sd_jdesc->jd_inode);
struct gfs2_glock *j_gl = ip->i_gl;
struct gfs2_log_header_host head;
int error;
if (test_bit(SDF_JOURNAL_LIVE, &sdp->sd_flags)) {
j_gl->gl_ops->go_inval(j_gl, DIO_METADATA);
error = gfs2_find_jhead(sdp->sd_jdesc, &head);
if (error)
gfs2_consist(sdp);
if (!(head.lh_flags & GFS2_LOG_HEAD_UNMOUNT))
gfs2_consist(sdp);
if (!test_bit(SDF_SHUTDOWN, &sdp->sd_flags)) {
sdp->sd_log_sequence = head.lh_sequence + 1;
gfs2_log_pointers_init(sdp, head.lh_blkno);
}
}
return 0;
}
static int trans_go_demote_ok(const struct gfs2_glock *gl)
{
return 0;
}
static void iopen_go_callback(struct gfs2_glock *gl)
{
struct gfs2_inode *ip = (struct gfs2_inode *)gl->gl_object;
struct gfs2_sbd *sdp = gl->gl_sbd;
if (sdp->sd_vfs->s_flags & MS_RDONLY)
return;
if (gl->gl_demote_state == LM_ST_UNLOCKED &&
gl->gl_state == LM_ST_SHARED && ip) {
gfs2_glock_hold(gl);
if (queue_work(gfs2_delete_workqueue, &gl->gl_delete) == 0)
gfs2_glock_put_nolock(gl);
}
}
