static int gfs2_aspace_writepage(struct page *page, struct writeback_control *wbc)
{
struct buffer_head *bh, *head;
int nr_underway = 0;
int write_flags = REQ_META | REQ_PRIO | wbc_to_write_flags(wbc);
BUG_ON(!PageLocked(page));
BUG_ON(!page_has_buffers(page));
head = page_buffers(page);
bh = head;
do {
if (!buffer_mapped(bh))
continue;
if (wbc->sync_mode != WB_SYNC_NONE) {
lock_buffer(bh);
} else if (!trylock_buffer(bh)) {
redirty_page_for_writepage(wbc, page);
continue;
}
if (test_clear_buffer_dirty(bh)) {
mark_buffer_async_write(bh);
} else {
unlock_buffer(bh);
}
} while ((bh = bh->b_this_page) != head);
BUG_ON(PageWriteback(page));
set_page_writeback(page);
do {
struct buffer_head *next = bh->b_this_page;
if (buffer_async_write(bh)) {
submit_bh(REQ_OP_WRITE, write_flags, bh);
nr_underway++;
}
bh = next;
} while (bh != head);
unlock_page(page);
if (nr_underway == 0)
end_page_writeback(page);
return 0;
}
struct buffer_head *gfs2_getbuf(struct gfs2_glock *gl, u64 blkno, int create)
{
struct address_space *mapping = gfs2_glock2aspace(gl);
struct gfs2_sbd *sdp = gl->gl_name.ln_sbd;
struct page *page;
struct buffer_head *bh;
unsigned int shift;
unsigned long index;
unsigned int bufnum;
if (mapping == NULL)
mapping = &sdp->sd_aspace;
shift = PAGE_SHIFT - sdp->sd_sb.sb_bsize_shift;
index = blkno >> shift;
bufnum = blkno - (index << shift);
if (create) {
for (;;) {
page = grab_cache_page(mapping, index);
if (page)
break;
yield();
}
} else {
page = find_get_page_flags(mapping, index,
FGP_LOCK|FGP_ACCESSED);
if (!page)
return NULL;
}
if (!page_has_buffers(page))
create_empty_buffers(page, sdp->sd_sb.sb_bsize, 0);
for (bh = page_buffers(page); bufnum--; bh = bh->b_this_page)
;
get_bh(bh);
if (!buffer_mapped(bh))
map_bh(bh, sdp->sd_vfs, blkno);
unlock_page(page);
put_page(page);
return bh;
}
static void meta_prep_new(struct buffer_head *bh)
{
struct gfs2_meta_header *mh = (struct gfs2_meta_header *)bh->b_data;
lock_buffer(bh);
clear_buffer_dirty(bh);
set_buffer_uptodate(bh);
unlock_buffer(bh);
mh->mh_magic = cpu_to_be32(GFS2_MAGIC);
}
struct buffer_head *gfs2_meta_new(struct gfs2_glock *gl, u64 blkno)
{
struct buffer_head *bh;
bh = gfs2_getbuf(gl, blkno, CREATE);
meta_prep_new(bh);
return bh;
}
static void gfs2_meta_read_endio(struct bio *bio)
{
struct bio_vec *bvec;
int i;
bio_for_each_segment_all(bvec, bio, i) {
struct page *page = bvec->bv_page;
struct buffer_head *bh = page_buffers(page);
unsigned int len = bvec->bv_len;
while (bh_offset(bh) < bvec->bv_offset)
bh = bh->b_this_page;
do {
struct buffer_head *next = bh->b_this_page;
len -= bh->b_size;
bh->b_end_io(bh, !bio->bi_status);
bh = next;
} while (bh && len);
}
bio_put(bio);
}
static void gfs2_submit_bhs(int op, int op_flags, struct buffer_head *bhs[],
int num)
{
while (num > 0) {
struct buffer_head *bh = *bhs;
struct bio *bio;
bio = bio_alloc(GFP_NOIO, num);
bio->bi_iter.bi_sector = bh->b_blocknr * (bh->b_size >> 9);
bio->bi_bdev = bh->b_bdev;
while (num > 0) {
bh = *bhs;
if (!bio_add_page(bio, bh->b_page, bh->b_size, bh_offset(bh))) {
BUG_ON(bio->bi_iter.bi_size == 0);
break;
}
bhs++;
num--;
}
bio->bi_end_io = gfs2_meta_read_endio;
bio_set_op_attrs(bio, op, op_flags);
submit_bio(bio);
}
}
int gfs2_meta_read(struct gfs2_glock *gl, u64 blkno, int flags,
int rahead, struct buffer_head **bhp)
{
struct gfs2_sbd *sdp = gl->gl_name.ln_sbd;
struct buffer_head *bh, *bhs[2];
int num = 0;
if (unlikely(test_bit(SDF_SHUTDOWN, &sdp->sd_flags))) {
*bhp = NULL;
return -EIO;
}
*bhp = bh = gfs2_getbuf(gl, blkno, CREATE);
lock_buffer(bh);
if (buffer_uptodate(bh)) {
unlock_buffer(bh);
flags &= ~DIO_WAIT;
} else {
bh->b_end_io = end_buffer_read_sync;
get_bh(bh);
bhs[num++] = bh;
}
if (rahead) {
bh = gfs2_getbuf(gl, blkno + 1, CREATE);
lock_buffer(bh);
if (buffer_uptodate(bh)) {
unlock_buffer(bh);
brelse(bh);
} else {
bh->b_end_io = end_buffer_read_sync;
bhs[num++] = bh;
}
}
gfs2_submit_bhs(REQ_OP_READ, REQ_META | REQ_PRIO, bhs, num);
if (!(flags & DIO_WAIT))
return 0;
bh = *bhp;
wait_on_buffer(bh);
if (unlikely(!buffer_uptodate(bh))) {
struct gfs2_trans *tr = current->journal_info;
if (tr && test_bit(TR_TOUCHED, &tr->tr_flags))
gfs2_io_error_bh(sdp, bh);
brelse(bh);
*bhp = NULL;
return -EIO;
}
return 0;
}
int gfs2_meta_wait(struct gfs2_sbd *sdp, struct buffer_head *bh)
{
if (unlikely(test_bit(SDF_SHUTDOWN, &sdp->sd_flags)))
return -EIO;
wait_on_buffer(bh);
if (!buffer_uptodate(bh)) {
struct gfs2_trans *tr = current->journal_info;
if (tr && test_bit(TR_TOUCHED, &tr->tr_flags))
gfs2_io_error_bh(sdp, bh);
return -EIO;
}
if (unlikely(test_bit(SDF_SHUTDOWN, &sdp->sd_flags)))
return -EIO;
return 0;
}
void gfs2_remove_from_journal(struct buffer_head *bh, int meta)
{
struct address_space *mapping = bh->b_page->mapping;
struct gfs2_sbd *sdp = gfs2_mapping2sbd(mapping);
struct gfs2_bufdata *bd = bh->b_private;
struct gfs2_trans *tr = current->journal_info;
int was_pinned = 0;
if (test_clear_buffer_pinned(bh)) {
trace_gfs2_pin(bd, 0);
atomic_dec(&sdp->sd_log_pinned);
list_del_init(&bd->bd_list);
if (meta == REMOVE_META)
tr->tr_num_buf_rm++;
else
tr->tr_num_databuf_rm++;
set_bit(TR_TOUCHED, &tr->tr_flags);
was_pinned = 1;
brelse(bh);
}
if (bd) {
spin_lock(&sdp->sd_ail_lock);
if (bd->bd_tr) {
gfs2_trans_add_revoke(sdp, bd);
} else if (was_pinned) {
bh->b_private = NULL;
kmem_cache_free(gfs2_bufdata_cachep, bd);
}
spin_unlock(&sdp->sd_ail_lock);
}
clear_buffer_dirty(bh);
clear_buffer_uptodate(bh);
}
void gfs2_meta_wipe(struct gfs2_inode *ip, u64 bstart, u32 blen)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
struct buffer_head *bh;
while (blen) {
bh = gfs2_getbuf(ip->i_gl, bstart, NO_CREATE);
if (bh) {
lock_buffer(bh);
gfs2_log_lock(sdp);
gfs2_remove_from_journal(bh, REMOVE_META);
gfs2_log_unlock(sdp);
unlock_buffer(bh);
brelse(bh);
}
bstart++;
blen--;
}
}
int gfs2_meta_indirect_buffer(struct gfs2_inode *ip, int height, u64 num,
struct buffer_head **bhp)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
struct gfs2_glock *gl = ip->i_gl;
struct buffer_head *bh;
int ret = 0;
u32 mtype = height ? GFS2_METATYPE_IN : GFS2_METATYPE_DI;
int rahead = 0;
if (num == ip->i_no_addr)
rahead = ip->i_rahead;
ret = gfs2_meta_read(gl, num, DIO_WAIT, rahead, &bh);
if (ret == 0 && gfs2_metatype_check(sdp, bh, mtype)) {
brelse(bh);
ret = -EIO;
}
*bhp = bh;
return ret;
}
struct buffer_head *gfs2_meta_ra(struct gfs2_glock *gl, u64 dblock, u32 extlen)
{
struct gfs2_sbd *sdp = gl->gl_name.ln_sbd;
struct buffer_head *first_bh, *bh;
u32 max_ra = gfs2_tune_get(sdp, gt_max_readahead) >>
sdp->sd_sb.sb_bsize_shift;
BUG_ON(!extlen);
if (max_ra < 1)
max_ra = 1;
if (extlen > max_ra)
extlen = max_ra;
first_bh = gfs2_getbuf(gl, dblock, CREATE);
if (buffer_uptodate(first_bh))
goto out;
if (!buffer_locked(first_bh))
ll_rw_block(REQ_OP_READ, REQ_META, 1, &first_bh);
dblock++;
extlen--;
while (extlen) {
bh = gfs2_getbuf(gl, dblock, CREATE);
if (!buffer_uptodate(bh) && !buffer_locked(bh))
ll_rw_block(REQ_OP_READ, REQ_RAHEAD | REQ_META, 1, &bh);
brelse(bh);
dblock++;
extlen--;
if (!buffer_locked(first_bh) && buffer_uptodate(first_bh))
goto out;
}
wait_on_buffer(first_bh);
out:
return first_bh;
}
