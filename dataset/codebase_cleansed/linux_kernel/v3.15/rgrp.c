static inline void gfs2_setbit(const struct gfs2_rbm *rbm, bool do_clone,
unsigned char new_state)
{
unsigned char *byte1, *byte2, *end, cur_state;
struct gfs2_bitmap *bi = rbm_bi(rbm);
unsigned int buflen = bi->bi_len;
const unsigned int bit = (rbm->offset % GFS2_NBBY) * GFS2_BIT_SIZE;
byte1 = bi->bi_bh->b_data + bi->bi_offset + (rbm->offset / GFS2_NBBY);
end = bi->bi_bh->b_data + bi->bi_offset + buflen;
BUG_ON(byte1 >= end);
cur_state = (*byte1 >> bit) & GFS2_BIT_MASK;
if (unlikely(!valid_change[new_state * 4 + cur_state])) {
pr_warn("buf_blk = 0x%x old_state=%d, new_state=%d\n",
rbm->offset, cur_state, new_state);
pr_warn("rgrp=0x%llx bi_start=0x%x\n",
(unsigned long long)rbm->rgd->rd_addr, bi->bi_start);
pr_warn("bi_offset=0x%x bi_len=0x%x\n",
bi->bi_offset, bi->bi_len);
dump_stack();
gfs2_consist_rgrpd(rbm->rgd);
return;
}
*byte1 ^= (cur_state ^ new_state) << bit;
if (do_clone && bi->bi_clone) {
byte2 = bi->bi_clone + bi->bi_offset + (rbm->offset / GFS2_NBBY);
cur_state = (*byte2 >> bit) & GFS2_BIT_MASK;
*byte2 ^= (cur_state ^ new_state) << bit;
}
}
static inline u8 gfs2_testbit(const struct gfs2_rbm *rbm)
{
struct gfs2_bitmap *bi = rbm_bi(rbm);
const u8 *buffer = bi->bi_bh->b_data + bi->bi_offset;
const u8 *byte;
unsigned int bit;
byte = buffer + (rbm->offset / GFS2_NBBY);
bit = (rbm->offset % GFS2_NBBY) * GFS2_BIT_SIZE;
return (*byte >> bit) & GFS2_BIT_MASK;
}
static inline u64 gfs2_bit_search(const __le64 *ptr, u64 mask, u8 state)
{
u64 tmp;
static const u64 search[] = {
[0] = 0xffffffffffffffffULL,
[1] = 0xaaaaaaaaaaaaaaaaULL,
[2] = 0x5555555555555555ULL,
[3] = 0x0000000000000000ULL,
};
tmp = le64_to_cpu(*ptr) ^ search[state];
tmp &= (tmp >> 1);
tmp &= mask;
return tmp;
}
static inline int rs_cmp(u64 blk, u32 len, struct gfs2_blkreserv *rs)
{
u64 startblk = gfs2_rbm_to_block(&rs->rs_rbm);
if (blk >= startblk + rs->rs_free)
return 1;
if (blk + len - 1 < startblk)
return -1;
return 0;
}
static u32 gfs2_bitfit(const u8 *buf, const unsigned int len,
u32 goal, u8 state)
{
u32 spoint = (goal << 1) & ((8*sizeof(u64)) - 1);
const __le64 *ptr = ((__le64 *)buf) + (goal >> 5);
const __le64 *end = (__le64 *)(buf + ALIGN(len, sizeof(u64)));
u64 tmp;
u64 mask = 0x5555555555555555ULL;
u32 bit;
mask <<= spoint;
tmp = gfs2_bit_search(ptr, mask, state);
ptr++;
while(tmp == 0 && ptr < end) {
tmp = gfs2_bit_search(ptr, 0x5555555555555555ULL, state);
ptr++;
}
if (ptr == end && (len & (sizeof(u64) - 1)))
tmp &= (((u64)~0) >> (64 - 8*(len & (sizeof(u64) - 1))));
if (tmp == 0)
return BFITNOENT;
ptr--;
bit = __ffs64(tmp);
bit /= 2;
return (((const unsigned char *)ptr - buf) * GFS2_NBBY) + bit;
}
static int gfs2_rbm_from_block(struct gfs2_rbm *rbm, u64 block)
{
u64 rblock = block - rbm->rgd->rd_data0;
if (WARN_ON_ONCE(rblock > UINT_MAX))
return -EINVAL;
if (block >= rbm->rgd->rd_data0 + rbm->rgd->rd_data)
return -E2BIG;
rbm->bii = 0;
rbm->offset = (u32)(rblock);
if (rbm->offset < rbm_bi(rbm)->bi_blocks)
return 0;
rbm->offset += (sizeof(struct gfs2_rgrp) -
sizeof(struct gfs2_meta_header)) * GFS2_NBBY;
rbm->bii = rbm->offset / rbm->rgd->rd_sbd->sd_blocks_per_bitmap;
rbm->offset -= rbm->bii * rbm->rgd->rd_sbd->sd_blocks_per_bitmap;
return 0;
}
static bool gfs2_rbm_incr(struct gfs2_rbm *rbm)
{
if (rbm->offset + 1 < rbm_bi(rbm)->bi_blocks) {
rbm->offset++;
return false;
}
if (rbm->bii == rbm->rgd->rd_length - 1)
return true;
rbm->offset = 0;
rbm->bii++;
return false;
}
static bool gfs2_unaligned_extlen(struct gfs2_rbm *rbm, u32 n_unaligned, u32 *len)
{
u32 n;
u8 res;
for (n = 0; n < n_unaligned; n++) {
res = gfs2_testbit(rbm);
if (res != GFS2_BLKST_FREE)
return true;
(*len)--;
if (*len == 0)
return true;
if (gfs2_rbm_incr(rbm))
return true;
}
return false;
}
static u32 gfs2_free_extlen(const struct gfs2_rbm *rrbm, u32 len)
{
struct gfs2_rbm rbm = *rrbm;
u32 n_unaligned = rbm.offset & 3;
u32 size = len;
u32 bytes;
u32 chunk_size;
u8 *ptr, *start, *end;
u64 block;
struct gfs2_bitmap *bi;
if (n_unaligned &&
gfs2_unaligned_extlen(&rbm, 4 - n_unaligned, &len))
goto out;
n_unaligned = len & 3;
while (len > 3) {
bi = rbm_bi(&rbm);
start = bi->bi_bh->b_data;
if (bi->bi_clone)
start = bi->bi_clone;
end = start + bi->bi_bh->b_size;
start += bi->bi_offset;
BUG_ON(rbm.offset & 3);
start += (rbm.offset / GFS2_NBBY);
bytes = min_t(u32, len / GFS2_NBBY, (end - start));
ptr = memchr_inv(start, 0, bytes);
chunk_size = ((ptr == NULL) ? bytes : (ptr - start));
chunk_size *= GFS2_NBBY;
BUG_ON(len < chunk_size);
len -= chunk_size;
block = gfs2_rbm_to_block(&rbm);
if (gfs2_rbm_from_block(&rbm, block + chunk_size)) {
n_unaligned = 0;
break;
}
if (ptr) {
n_unaligned = 3;
break;
}
n_unaligned = len & 3;
}
if (n_unaligned)
gfs2_unaligned_extlen(&rbm, n_unaligned, &len);
out:
return size - len;
}
static u32 gfs2_bitcount(struct gfs2_rgrpd *rgd, const u8 *buffer,
unsigned int buflen, u8 state)
{
const u8 *byte = buffer;
const u8 *end = buffer + buflen;
const u8 state1 = state << 2;
const u8 state2 = state << 4;
const u8 state3 = state << 6;
u32 count = 0;
for (; byte < end; byte++) {
if (((*byte) & 0x03) == state)
count++;
if (((*byte) & 0x0C) == state1)
count++;
if (((*byte) & 0x30) == state2)
count++;
if (((*byte) & 0xC0) == state3)
count++;
}
return count;
}
void gfs2_rgrp_verify(struct gfs2_rgrpd *rgd)
{
struct gfs2_sbd *sdp = rgd->rd_sbd;
struct gfs2_bitmap *bi = NULL;
u32 length = rgd->rd_length;
u32 count[4], tmp;
int buf, x;
memset(count, 0, 4 * sizeof(u32));
for (buf = 0; buf < length; buf++) {
bi = rgd->rd_bits + buf;
for (x = 0; x < 4; x++)
count[x] += gfs2_bitcount(rgd,
bi->bi_bh->b_data +
bi->bi_offset,
bi->bi_len, x);
}
if (count[0] != rgd->rd_free) {
if (gfs2_consist_rgrpd(rgd))
fs_err(sdp, "free data mismatch: %u != %u\n",
count[0], rgd->rd_free);
return;
}
tmp = rgd->rd_data - rgd->rd_free - rgd->rd_dinodes;
if (count[1] != tmp) {
if (gfs2_consist_rgrpd(rgd))
fs_err(sdp, "used data mismatch: %u != %u\n",
count[1], tmp);
return;
}
if (count[2] + count[3] != rgd->rd_dinodes) {
if (gfs2_consist_rgrpd(rgd))
fs_err(sdp, "used metadata mismatch: %u != %u\n",
count[2] + count[3], rgd->rd_dinodes);
return;
}
}
static inline int rgrp_contains_block(struct gfs2_rgrpd *rgd, u64 block)
{
u64 first = rgd->rd_data0;
u64 last = first + rgd->rd_data;
return first <= block && block < last;
}
struct gfs2_rgrpd *gfs2_blk2rgrpd(struct gfs2_sbd *sdp, u64 blk, bool exact)
{
struct rb_node *n, *next;
struct gfs2_rgrpd *cur;
spin_lock(&sdp->sd_rindex_spin);
n = sdp->sd_rindex_tree.rb_node;
while (n) {
cur = rb_entry(n, struct gfs2_rgrpd, rd_node);
next = NULL;
if (blk < cur->rd_addr)
next = n->rb_left;
else if (blk >= cur->rd_data0 + cur->rd_data)
next = n->rb_right;
if (next == NULL) {
spin_unlock(&sdp->sd_rindex_spin);
if (exact) {
if (blk < cur->rd_addr)
return NULL;
if (blk >= cur->rd_data0 + cur->rd_data)
return NULL;
}
return cur;
}
n = next;
}
spin_unlock(&sdp->sd_rindex_spin);
return NULL;
}
struct gfs2_rgrpd *gfs2_rgrpd_get_first(struct gfs2_sbd *sdp)
{
const struct rb_node *n;
struct gfs2_rgrpd *rgd;
spin_lock(&sdp->sd_rindex_spin);
n = rb_first(&sdp->sd_rindex_tree);
rgd = rb_entry(n, struct gfs2_rgrpd, rd_node);
spin_unlock(&sdp->sd_rindex_spin);
return rgd;
}
struct gfs2_rgrpd *gfs2_rgrpd_get_next(struct gfs2_rgrpd *rgd)
{
struct gfs2_sbd *sdp = rgd->rd_sbd;
const struct rb_node *n;
spin_lock(&sdp->sd_rindex_spin);
n = rb_next(&rgd->rd_node);
if (n == NULL)
n = rb_first(&sdp->sd_rindex_tree);
if (unlikely(&rgd->rd_node == n)) {
spin_unlock(&sdp->sd_rindex_spin);
return NULL;
}
rgd = rb_entry(n, struct gfs2_rgrpd, rd_node);
spin_unlock(&sdp->sd_rindex_spin);
return rgd;
}
void gfs2_free_clones(struct gfs2_rgrpd *rgd)
{
int x;
for (x = 0; x < rgd->rd_length; x++) {
struct gfs2_bitmap *bi = rgd->rd_bits + x;
kfree(bi->bi_clone);
bi->bi_clone = NULL;
}
}
int gfs2_rs_alloc(struct gfs2_inode *ip)
{
int error = 0;
down_write(&ip->i_rw_mutex);
if (ip->i_res)
goto out;
ip->i_res = kmem_cache_zalloc(gfs2_rsrv_cachep, GFP_NOFS);
if (!ip->i_res) {
error = -ENOMEM;
goto out;
}
RB_CLEAR_NODE(&ip->i_res->rs_node);
out:
up_write(&ip->i_rw_mutex);
return error;
}
static void dump_rs(struct seq_file *seq, const struct gfs2_blkreserv *rs)
{
gfs2_print_dbg(seq, " B: n:%llu s:%llu b:%u f:%u\n",
(unsigned long long)rs->rs_inum,
(unsigned long long)gfs2_rbm_to_block(&rs->rs_rbm),
rs->rs_rbm.offset, rs->rs_free);
}
static void __rs_deltree(struct gfs2_blkreserv *rs)
{
struct gfs2_rgrpd *rgd;
if (!gfs2_rs_active(rs))
return;
rgd = rs->rs_rbm.rgd;
trace_gfs2_rs(rs, TRACE_RS_TREEDEL);
rb_erase(&rs->rs_node, &rgd->rd_rstree);
RB_CLEAR_NODE(&rs->rs_node);
if (rs->rs_free) {
struct gfs2_bitmap *bi = rbm_bi(&rs->rs_rbm);
BUG_ON(rs->rs_rbm.rgd->rd_reserved < rs->rs_free);
rs->rs_rbm.rgd->rd_reserved -= rs->rs_free;
rgd->rd_extfail_pt += rs->rs_free;
rs->rs_free = 0;
clear_bit(GBF_FULL, &bi->bi_flags);
}
}
void gfs2_rs_deltree(struct gfs2_blkreserv *rs)
{
struct gfs2_rgrpd *rgd;
rgd = rs->rs_rbm.rgd;
if (rgd) {
spin_lock(&rgd->rd_rsspin);
__rs_deltree(rs);
spin_unlock(&rgd->rd_rsspin);
}
}
void gfs2_rs_delete(struct gfs2_inode *ip, atomic_t *wcount)
{
down_write(&ip->i_rw_mutex);
if (ip->i_res && ((wcount == NULL) || (atomic_read(wcount) <= 1))) {
gfs2_rs_deltree(ip->i_res);
BUG_ON(ip->i_res->rs_free);
kmem_cache_free(gfs2_rsrv_cachep, ip->i_res);
ip->i_res = NULL;
}
up_write(&ip->i_rw_mutex);
}
static void return_all_reservations(struct gfs2_rgrpd *rgd)
{
struct rb_node *n;
struct gfs2_blkreserv *rs;
spin_lock(&rgd->rd_rsspin);
while ((n = rb_first(&rgd->rd_rstree))) {
rs = rb_entry(n, struct gfs2_blkreserv, rs_node);
__rs_deltree(rs);
}
spin_unlock(&rgd->rd_rsspin);
}
void gfs2_clear_rgrpd(struct gfs2_sbd *sdp)
{
struct rb_node *n;
struct gfs2_rgrpd *rgd;
struct gfs2_glock *gl;
while ((n = rb_first(&sdp->sd_rindex_tree))) {
rgd = rb_entry(n, struct gfs2_rgrpd, rd_node);
gl = rgd->rd_gl;
rb_erase(n, &sdp->sd_rindex_tree);
if (gl) {
spin_lock(&gl->gl_spin);
gl->gl_object = NULL;
spin_unlock(&gl->gl_spin);
gfs2_glock_add_to_lru(gl);
gfs2_glock_put(gl);
}
gfs2_free_clones(rgd);
kfree(rgd->rd_bits);
return_all_reservations(rgd);
kmem_cache_free(gfs2_rgrpd_cachep, rgd);
}
}
static void gfs2_rindex_print(const struct gfs2_rgrpd *rgd)
{
pr_info("ri_addr = %llu\n", (unsigned long long)rgd->rd_addr);
pr_info("ri_length = %u\n", rgd->rd_length);
pr_info("ri_data0 = %llu\n", (unsigned long long)rgd->rd_data0);
pr_info("ri_data = %u\n", rgd->rd_data);
pr_info("ri_bitbytes = %u\n", rgd->rd_bitbytes);
}
static int compute_bitstructs(struct gfs2_rgrpd *rgd)
{
struct gfs2_sbd *sdp = rgd->rd_sbd;
struct gfs2_bitmap *bi;
u32 length = rgd->rd_length;
u32 bytes_left, bytes;
int x;
if (!length)
return -EINVAL;
rgd->rd_bits = kcalloc(length, sizeof(struct gfs2_bitmap), GFP_NOFS);
if (!rgd->rd_bits)
return -ENOMEM;
bytes_left = rgd->rd_bitbytes;
for (x = 0; x < length; x++) {
bi = rgd->rd_bits + x;
bi->bi_flags = 0;
if (length == 1) {
bytes = bytes_left;
bi->bi_offset = sizeof(struct gfs2_rgrp);
bi->bi_start = 0;
bi->bi_len = bytes;
bi->bi_blocks = bytes * GFS2_NBBY;
} else if (x == 0) {
bytes = sdp->sd_sb.sb_bsize - sizeof(struct gfs2_rgrp);
bi->bi_offset = sizeof(struct gfs2_rgrp);
bi->bi_start = 0;
bi->bi_len = bytes;
bi->bi_blocks = bytes * GFS2_NBBY;
} else if (x + 1 == length) {
bytes = bytes_left;
bi->bi_offset = sizeof(struct gfs2_meta_header);
bi->bi_start = rgd->rd_bitbytes - bytes_left;
bi->bi_len = bytes;
bi->bi_blocks = bytes * GFS2_NBBY;
} else {
bytes = sdp->sd_sb.sb_bsize -
sizeof(struct gfs2_meta_header);
bi->bi_offset = sizeof(struct gfs2_meta_header);
bi->bi_start = rgd->rd_bitbytes - bytes_left;
bi->bi_len = bytes;
bi->bi_blocks = bytes * GFS2_NBBY;
}
bytes_left -= bytes;
}
if (bytes_left) {
gfs2_consist_rgrpd(rgd);
return -EIO;
}
bi = rgd->rd_bits + (length - 1);
if ((bi->bi_start + bi->bi_len) * GFS2_NBBY != rgd->rd_data) {
if (gfs2_consist_rgrpd(rgd)) {
gfs2_rindex_print(rgd);
fs_err(sdp, "start=%u len=%u offset=%u\n",
bi->bi_start, bi->bi_len, bi->bi_offset);
}
return -EIO;
}
return 0;
}
u64 gfs2_ri_total(struct gfs2_sbd *sdp)
{
u64 total_data = 0;
struct inode *inode = sdp->sd_rindex;
struct gfs2_inode *ip = GFS2_I(inode);
char buf[sizeof(struct gfs2_rindex)];
int error, rgrps;
for (rgrps = 0;; rgrps++) {
loff_t pos = rgrps * sizeof(struct gfs2_rindex);
if (pos + sizeof(struct gfs2_rindex) > i_size_read(inode))
break;
error = gfs2_internal_read(ip, buf, &pos,
sizeof(struct gfs2_rindex));
if (error != sizeof(struct gfs2_rindex))
break;
total_data += be32_to_cpu(((struct gfs2_rindex *)buf)->ri_data);
}
return total_data;
}
static int rgd_insert(struct gfs2_rgrpd *rgd)
{
struct gfs2_sbd *sdp = rgd->rd_sbd;
struct rb_node **newn = &sdp->sd_rindex_tree.rb_node, *parent = NULL;
while (*newn) {
struct gfs2_rgrpd *cur = rb_entry(*newn, struct gfs2_rgrpd,
rd_node);
parent = *newn;
if (rgd->rd_addr < cur->rd_addr)
newn = &((*newn)->rb_left);
else if (rgd->rd_addr > cur->rd_addr)
newn = &((*newn)->rb_right);
else
return -EEXIST;
}
rb_link_node(&rgd->rd_node, parent, newn);
rb_insert_color(&rgd->rd_node, &sdp->sd_rindex_tree);
sdp->sd_rgrps++;
return 0;
}
static int read_rindex_entry(struct gfs2_inode *ip)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
const unsigned bsize = sdp->sd_sb.sb_bsize;
loff_t pos = sdp->sd_rgrps * sizeof(struct gfs2_rindex);
struct gfs2_rindex buf;
int error;
struct gfs2_rgrpd *rgd;
if (pos >= i_size_read(&ip->i_inode))
return 1;
error = gfs2_internal_read(ip, (char *)&buf, &pos,
sizeof(struct gfs2_rindex));
if (error != sizeof(struct gfs2_rindex))
return (error == 0) ? 1 : error;
rgd = kmem_cache_zalloc(gfs2_rgrpd_cachep, GFP_NOFS);
error = -ENOMEM;
if (!rgd)
return error;
rgd->rd_sbd = sdp;
rgd->rd_addr = be64_to_cpu(buf.ri_addr);
rgd->rd_length = be32_to_cpu(buf.ri_length);
rgd->rd_data0 = be64_to_cpu(buf.ri_data0);
rgd->rd_data = be32_to_cpu(buf.ri_data);
rgd->rd_bitbytes = be32_to_cpu(buf.ri_bitbytes);
spin_lock_init(&rgd->rd_rsspin);
error = compute_bitstructs(rgd);
if (error)
goto fail;
error = gfs2_glock_get(sdp, rgd->rd_addr,
&gfs2_rgrp_glops, CREATE, &rgd->rd_gl);
if (error)
goto fail;
rgd->rd_gl->gl_object = rgd;
rgd->rd_gl->gl_vm.start = rgd->rd_addr * bsize;
rgd->rd_gl->gl_vm.end = rgd->rd_gl->gl_vm.start + (rgd->rd_length * bsize) - 1;
rgd->rd_rgl = (struct gfs2_rgrp_lvb *)rgd->rd_gl->gl_lksb.sb_lvbptr;
rgd->rd_flags &= ~GFS2_RDF_UPTODATE;
if (rgd->rd_data > sdp->sd_max_rg_data)
sdp->sd_max_rg_data = rgd->rd_data;
spin_lock(&sdp->sd_rindex_spin);
error = rgd_insert(rgd);
spin_unlock(&sdp->sd_rindex_spin);
if (!error)
return 0;
error = 0;
gfs2_glock_put(rgd->rd_gl);
fail:
kfree(rgd->rd_bits);
kmem_cache_free(gfs2_rgrpd_cachep, rgd);
return error;
}
static int gfs2_ri_update(struct gfs2_inode *ip)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
int error;
do {
error = read_rindex_entry(ip);
} while (error == 0);
if (error < 0)
return error;
sdp->sd_rindex_uptodate = 1;
return 0;
}
int gfs2_rindex_update(struct gfs2_sbd *sdp)
{
struct gfs2_inode *ip = GFS2_I(sdp->sd_rindex);
struct gfs2_glock *gl = ip->i_gl;
struct gfs2_holder ri_gh;
int error = 0;
int unlock_required = 0;
if (!sdp->sd_rindex_uptodate) {
if (!gfs2_glock_is_locked_by_me(gl)) {
error = gfs2_glock_nq_init(gl, LM_ST_SHARED, 0, &ri_gh);
if (error)
return error;
unlock_required = 1;
}
if (!sdp->sd_rindex_uptodate)
error = gfs2_ri_update(ip);
if (unlock_required)
gfs2_glock_dq_uninit(&ri_gh);
}
return error;
}
static void gfs2_rgrp_in(struct gfs2_rgrpd *rgd, const void *buf)
{
const struct gfs2_rgrp *str = buf;
u32 rg_flags;
rg_flags = be32_to_cpu(str->rg_flags);
rg_flags &= ~GFS2_RDF_MASK;
rgd->rd_flags &= GFS2_RDF_MASK;
rgd->rd_flags |= rg_flags;
rgd->rd_free = be32_to_cpu(str->rg_free);
rgd->rd_dinodes = be32_to_cpu(str->rg_dinodes);
rgd->rd_igeneration = be64_to_cpu(str->rg_igeneration);
}
static void gfs2_rgrp_out(struct gfs2_rgrpd *rgd, void *buf)
{
struct gfs2_rgrp *str = buf;
str->rg_flags = cpu_to_be32(rgd->rd_flags & ~GFS2_RDF_MASK);
str->rg_free = cpu_to_be32(rgd->rd_free);
str->rg_dinodes = cpu_to_be32(rgd->rd_dinodes);
str->__pad = cpu_to_be32(0);
str->rg_igeneration = cpu_to_be64(rgd->rd_igeneration);
memset(&str->rg_reserved, 0, sizeof(str->rg_reserved));
}
static int gfs2_rgrp_lvb_valid(struct gfs2_rgrpd *rgd)
{
struct gfs2_rgrp_lvb *rgl = rgd->rd_rgl;
struct gfs2_rgrp *str = (struct gfs2_rgrp *)rgd->rd_bits[0].bi_bh->b_data;
if (rgl->rl_flags != str->rg_flags || rgl->rl_free != str->rg_free ||
rgl->rl_dinodes != str->rg_dinodes ||
rgl->rl_igeneration != str->rg_igeneration)
return 0;
return 1;
}
static void gfs2_rgrp_ondisk2lvb(struct gfs2_rgrp_lvb *rgl, const void *buf)
{
const struct gfs2_rgrp *str = buf;
rgl->rl_magic = cpu_to_be32(GFS2_MAGIC);
rgl->rl_flags = str->rg_flags;
rgl->rl_free = str->rg_free;
rgl->rl_dinodes = str->rg_dinodes;
rgl->rl_igeneration = str->rg_igeneration;
rgl->__pad = 0UL;
}
static void update_rgrp_lvb_unlinked(struct gfs2_rgrpd *rgd, u32 change)
{
struct gfs2_rgrp_lvb *rgl = rgd->rd_rgl;
u32 unlinked = be32_to_cpu(rgl->rl_unlinked) + change;
rgl->rl_unlinked = cpu_to_be32(unlinked);
}
static u32 count_unlinked(struct gfs2_rgrpd *rgd)
{
struct gfs2_bitmap *bi;
const u32 length = rgd->rd_length;
const u8 *buffer = NULL;
u32 i, goal, count = 0;
for (i = 0, bi = rgd->rd_bits; i < length; i++, bi++) {
goal = 0;
buffer = bi->bi_bh->b_data + bi->bi_offset;
WARN_ON(!buffer_uptodate(bi->bi_bh));
while (goal < bi->bi_len * GFS2_NBBY) {
goal = gfs2_bitfit(buffer, bi->bi_len, goal,
GFS2_BLKST_UNLINKED);
if (goal == BFITNOENT)
break;
count++;
goal++;
}
}
return count;
}
static int gfs2_rgrp_bh_get(struct gfs2_rgrpd *rgd)
{
struct gfs2_sbd *sdp = rgd->rd_sbd;
struct gfs2_glock *gl = rgd->rd_gl;
unsigned int length = rgd->rd_length;
struct gfs2_bitmap *bi;
unsigned int x, y;
int error;
if (rgd->rd_bits[0].bi_bh != NULL)
return 0;
for (x = 0; x < length; x++) {
bi = rgd->rd_bits + x;
error = gfs2_meta_read(gl, rgd->rd_addr + x, 0, &bi->bi_bh);
if (error)
goto fail;
}
for (y = length; y--;) {
bi = rgd->rd_bits + y;
error = gfs2_meta_wait(sdp, bi->bi_bh);
if (error)
goto fail;
if (gfs2_metatype_check(sdp, bi->bi_bh, y ? GFS2_METATYPE_RB :
GFS2_METATYPE_RG)) {
error = -EIO;
goto fail;
}
}
if (!(rgd->rd_flags & GFS2_RDF_UPTODATE)) {
for (x = 0; x < length; x++)
clear_bit(GBF_FULL, &rgd->rd_bits[x].bi_flags);
gfs2_rgrp_in(rgd, (rgd->rd_bits[0].bi_bh)->b_data);
rgd->rd_flags |= (GFS2_RDF_UPTODATE | GFS2_RDF_CHECK);
rgd->rd_free_clone = rgd->rd_free;
rgd->rd_extfail_pt = rgd->rd_free;
}
if (cpu_to_be32(GFS2_MAGIC) != rgd->rd_rgl->rl_magic) {
rgd->rd_rgl->rl_unlinked = cpu_to_be32(count_unlinked(rgd));
gfs2_rgrp_ondisk2lvb(rgd->rd_rgl,
rgd->rd_bits[0].bi_bh->b_data);
}
else if (sdp->sd_args.ar_rgrplvb) {
if (!gfs2_rgrp_lvb_valid(rgd)){
gfs2_consist_rgrpd(rgd);
error = -EIO;
goto fail;
}
if (rgd->rd_rgl->rl_unlinked == 0)
rgd->rd_flags &= ~GFS2_RDF_CHECK;
}
return 0;
fail:
while (x--) {
bi = rgd->rd_bits + x;
brelse(bi->bi_bh);
bi->bi_bh = NULL;
gfs2_assert_warn(sdp, !bi->bi_clone);
}
return error;
}
static int update_rgrp_lvb(struct gfs2_rgrpd *rgd)
{
u32 rl_flags;
if (rgd->rd_flags & GFS2_RDF_UPTODATE)
return 0;
if (cpu_to_be32(GFS2_MAGIC) != rgd->rd_rgl->rl_magic)
return gfs2_rgrp_bh_get(rgd);
rl_flags = be32_to_cpu(rgd->rd_rgl->rl_flags);
rl_flags &= ~GFS2_RDF_MASK;
rgd->rd_flags &= GFS2_RDF_MASK;
rgd->rd_flags |= (rl_flags | GFS2_RDF_UPTODATE | GFS2_RDF_CHECK);
if (rgd->rd_rgl->rl_unlinked == 0)
rgd->rd_flags &= ~GFS2_RDF_CHECK;
rgd->rd_free = be32_to_cpu(rgd->rd_rgl->rl_free);
rgd->rd_free_clone = rgd->rd_free;
rgd->rd_dinodes = be32_to_cpu(rgd->rd_rgl->rl_dinodes);
rgd->rd_igeneration = be64_to_cpu(rgd->rd_rgl->rl_igeneration);
return 0;
}
int gfs2_rgrp_go_lock(struct gfs2_holder *gh)
{
struct gfs2_rgrpd *rgd = gh->gh_gl->gl_object;
struct gfs2_sbd *sdp = rgd->rd_sbd;
if (gh->gh_flags & GL_SKIP && sdp->sd_args.ar_rgrplvb)
return 0;
return gfs2_rgrp_bh_get(rgd);
}
void gfs2_rgrp_go_unlock(struct gfs2_holder *gh)
{
struct gfs2_rgrpd *rgd = gh->gh_gl->gl_object;
int x, length = rgd->rd_length;
for (x = 0; x < length; x++) {
struct gfs2_bitmap *bi = rgd->rd_bits + x;
if (bi->bi_bh) {
brelse(bi->bi_bh);
bi->bi_bh = NULL;
}
}
}
int gfs2_rgrp_send_discards(struct gfs2_sbd *sdp, u64 offset,
struct buffer_head *bh,
const struct gfs2_bitmap *bi, unsigned minlen, u64 *ptrimmed)
{
struct super_block *sb = sdp->sd_vfs;
u64 blk;
sector_t start = 0;
sector_t nr_blks = 0;
int rv;
unsigned int x;
u32 trimmed = 0;
u8 diff;
for (x = 0; x < bi->bi_len; x++) {
const u8 *clone = bi->bi_clone ? bi->bi_clone : bi->bi_bh->b_data;
clone += bi->bi_offset;
clone += x;
if (bh) {
const u8 *orig = bh->b_data + bi->bi_offset + x;
diff = ~(*orig | (*orig >> 1)) & (*clone | (*clone >> 1));
} else {
diff = ~(*clone | (*clone >> 1));
}
diff &= 0x55;
if (diff == 0)
continue;
blk = offset + ((bi->bi_start + x) * GFS2_NBBY);
while(diff) {
if (diff & 1) {
if (nr_blks == 0)
goto start_new_extent;
if ((start + nr_blks) != blk) {
if (nr_blks >= minlen) {
rv = sb_issue_discard(sb,
start, nr_blks,
GFP_NOFS, 0);
if (rv)
goto fail;
trimmed += nr_blks;
}
nr_blks = 0;
start_new_extent:
start = blk;
}
nr_blks++;
}
diff >>= 2;
blk++;
}
}
if (nr_blks >= minlen) {
rv = sb_issue_discard(sb, start, nr_blks, GFP_NOFS, 0);
if (rv)
goto fail;
trimmed += nr_blks;
}
if (ptrimmed)
*ptrimmed = trimmed;
return 0;
fail:
if (sdp->sd_args.ar_discard)
fs_warn(sdp, "error %d on discard request, turning discards off for this filesystem", rv);
sdp->sd_args.ar_discard = 0;
return -EIO;
}
int gfs2_fitrim(struct file *filp, void __user *argp)
{
struct inode *inode = file_inode(filp);
struct gfs2_sbd *sdp = GFS2_SB(inode);
struct request_queue *q = bdev_get_queue(sdp->sd_vfs->s_bdev);
struct buffer_head *bh;
struct gfs2_rgrpd *rgd;
struct gfs2_rgrpd *rgd_end;
struct gfs2_holder gh;
struct fstrim_range r;
int ret = 0;
u64 amt;
u64 trimmed = 0;
u64 start, end, minlen;
unsigned int x;
unsigned bs_shift = sdp->sd_sb.sb_bsize_shift;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (!blk_queue_discard(q))
return -EOPNOTSUPP;
if (copy_from_user(&r, argp, sizeof(r)))
return -EFAULT;
ret = gfs2_rindex_update(sdp);
if (ret)
return ret;
start = r.start >> bs_shift;
end = start + (r.len >> bs_shift);
minlen = max_t(u64, r.minlen,
q->limits.discard_granularity) >> bs_shift;
if (end <= start || minlen > sdp->sd_max_rg_data)
return -EINVAL;
rgd = gfs2_blk2rgrpd(sdp, start, 0);
rgd_end = gfs2_blk2rgrpd(sdp, end, 0);
if ((gfs2_rgrpd_get_first(sdp) == gfs2_rgrpd_get_next(rgd_end))
&& (start > rgd_end->rd_data0 + rgd_end->rd_data))
return -EINVAL;
while (1) {
ret = gfs2_glock_nq_init(rgd->rd_gl, LM_ST_EXCLUSIVE, 0, &gh);
if (ret)
goto out;
if (!(rgd->rd_flags & GFS2_RGF_TRIMMED)) {
for (x = 0; x < rgd->rd_length; x++) {
struct gfs2_bitmap *bi = rgd->rd_bits + x;
ret = gfs2_rgrp_send_discards(sdp,
rgd->rd_data0, NULL, bi, minlen,
&amt);
if (ret) {
gfs2_glock_dq_uninit(&gh);
goto out;
}
trimmed += amt;
}
ret = gfs2_trans_begin(sdp, RES_RG_HDR, 0);
if (ret == 0) {
bh = rgd->rd_bits[0].bi_bh;
rgd->rd_flags |= GFS2_RGF_TRIMMED;
gfs2_trans_add_meta(rgd->rd_gl, bh);
gfs2_rgrp_out(rgd, bh->b_data);
gfs2_rgrp_ondisk2lvb(rgd->rd_rgl, bh->b_data);
gfs2_trans_end(sdp);
}
}
gfs2_glock_dq_uninit(&gh);
if (rgd == rgd_end)
break;
rgd = gfs2_rgrpd_get_next(rgd);
}
out:
r.len = trimmed << bs_shift;
if (copy_to_user(argp, &r, sizeof(r)))
return -EFAULT;
return ret;
}
static void rs_insert(struct gfs2_inode *ip)
{
struct rb_node **newn, *parent = NULL;
int rc;
struct gfs2_blkreserv *rs = ip->i_res;
struct gfs2_rgrpd *rgd = rs->rs_rbm.rgd;
u64 fsblock = gfs2_rbm_to_block(&rs->rs_rbm);
BUG_ON(gfs2_rs_active(rs));
spin_lock(&rgd->rd_rsspin);
newn = &rgd->rd_rstree.rb_node;
while (*newn) {
struct gfs2_blkreserv *cur =
rb_entry(*newn, struct gfs2_blkreserv, rs_node);
parent = *newn;
rc = rs_cmp(fsblock, rs->rs_free, cur);
if (rc > 0)
newn = &((*newn)->rb_right);
else if (rc < 0)
newn = &((*newn)->rb_left);
else {
spin_unlock(&rgd->rd_rsspin);
WARN_ON(1);
return;
}
}
rb_link_node(&rs->rs_node, parent, newn);
rb_insert_color(&rs->rs_node, &rgd->rd_rstree);
rgd->rd_reserved += rs->rs_free;
spin_unlock(&rgd->rd_rsspin);
trace_gfs2_rs(rs, TRACE_RS_INSERT);
}
static void rg_mblk_search(struct gfs2_rgrpd *rgd, struct gfs2_inode *ip,
const struct gfs2_alloc_parms *ap)
{
struct gfs2_rbm rbm = { .rgd = rgd, };
u64 goal;
struct gfs2_blkreserv *rs = ip->i_res;
u32 extlen;
u32 free_blocks = rgd->rd_free_clone - rgd->rd_reserved;
int ret;
struct inode *inode = &ip->i_inode;
if (S_ISDIR(inode->i_mode))
extlen = 1;
else {
extlen = max_t(u32, atomic_read(&rs->rs_sizehint), ap->target);
extlen = clamp(extlen, RGRP_RSRV_MINBLKS, free_blocks);
}
if ((rgd->rd_free_clone < rgd->rd_reserved) || (free_blocks < extlen))
return;
if (rgrp_contains_block(rgd, ip->i_goal))
goal = ip->i_goal;
else
goal = rgd->rd_last_alloc + rgd->rd_data0;
if (WARN_ON(gfs2_rbm_from_block(&rbm, goal)))
return;
ret = gfs2_rbm_find(&rbm, GFS2_BLKST_FREE, &extlen, ip, true, ap);
if (ret == 0) {
rs->rs_rbm = rbm;
rs->rs_free = extlen;
rs->rs_inum = ip->i_no_addr;
rs_insert(ip);
} else {
if (goal == rgd->rd_last_alloc + rgd->rd_data0)
rgd->rd_last_alloc = 0;
}
}
static u64 gfs2_next_unreserved_block(struct gfs2_rgrpd *rgd, u64 block,
u32 length,
const struct gfs2_inode *ip)
{
struct gfs2_blkreserv *rs;
struct rb_node *n;
int rc;
spin_lock(&rgd->rd_rsspin);
n = rgd->rd_rstree.rb_node;
while (n) {
rs = rb_entry(n, struct gfs2_blkreserv, rs_node);
rc = rs_cmp(block, length, rs);
if (rc < 0)
n = n->rb_left;
else if (rc > 0)
n = n->rb_right;
else
break;
}
if (n) {
while ((rs_cmp(block, length, rs) == 0) && (ip->i_res != rs)) {
block = gfs2_rbm_to_block(&rs->rs_rbm) + rs->rs_free;
n = n->rb_right;
if (n == NULL)
break;
rs = rb_entry(n, struct gfs2_blkreserv, rs_node);
}
}
spin_unlock(&rgd->rd_rsspin);
return block;
}
static int gfs2_reservation_check_and_update(struct gfs2_rbm *rbm,
const struct gfs2_inode *ip,
u32 minext,
struct gfs2_extent *maxext)
{
u64 block = gfs2_rbm_to_block(rbm);
u32 extlen = 1;
u64 nblock;
int ret;
if (minext) {
extlen = gfs2_free_extlen(rbm, minext);
if (extlen <= maxext->len)
goto fail;
}
nblock = gfs2_next_unreserved_block(rbm->rgd, block, extlen, ip);
if (nblock == block) {
if (!minext || extlen >= minext)
return 0;
if (extlen > maxext->len) {
maxext->len = extlen;
maxext->rbm = *rbm;
}
fail:
nblock = block + extlen;
}
ret = gfs2_rbm_from_block(rbm, nblock);
if (ret < 0)
return ret;
return 1;
}
static int gfs2_rbm_find(struct gfs2_rbm *rbm, u8 state, u32 *minext,
const struct gfs2_inode *ip, bool nowrap,
const struct gfs2_alloc_parms *ap)
{
struct buffer_head *bh;
int initial_bii;
u32 initial_offset;
int first_bii = rbm->bii;
u32 first_offset = rbm->offset;
u32 offset;
u8 *buffer;
int n = 0;
int iters = rbm->rgd->rd_length;
int ret;
struct gfs2_bitmap *bi;
struct gfs2_extent maxext = { .rbm.rgd = rbm->rgd, };
if (rbm->offset != 0)
iters++;
while(1) {
bi = rbm_bi(rbm);
if (test_bit(GBF_FULL, &bi->bi_flags) &&
(state == GFS2_BLKST_FREE))
goto next_bitmap;
bh = bi->bi_bh;
buffer = bh->b_data + bi->bi_offset;
WARN_ON(!buffer_uptodate(bh));
if (state != GFS2_BLKST_UNLINKED && bi->bi_clone)
buffer = bi->bi_clone + bi->bi_offset;
initial_offset = rbm->offset;
offset = gfs2_bitfit(buffer, bi->bi_len, rbm->offset, state);
if (offset == BFITNOENT)
goto bitmap_full;
rbm->offset = offset;
if (ip == NULL)
return 0;
initial_bii = rbm->bii;
ret = gfs2_reservation_check_and_update(rbm, ip,
minext ? *minext : 0,
&maxext);
if (ret == 0)
return 0;
if (ret > 0) {
n += (rbm->bii - initial_bii);
goto next_iter;
}
if (ret == -E2BIG) {
rbm->bii = 0;
rbm->offset = 0;
n += (rbm->bii - initial_bii);
goto res_covered_end_of_rgrp;
}
return ret;
bitmap_full:
if ((state == GFS2_BLKST_FREE) && initial_offset == 0) {
struct gfs2_bitmap *bi = rbm_bi(rbm);
set_bit(GBF_FULL, &bi->bi_flags);
}
next_bitmap:
rbm->offset = 0;
rbm->bii++;
if (rbm->bii == rbm->rgd->rd_length)
rbm->bii = 0;
res_covered_end_of_rgrp:
if ((rbm->bii == 0) && nowrap)
break;
n++;
next_iter:
if (n >= iters)
break;
}
if (minext == NULL || state != GFS2_BLKST_FREE)
return -ENOSPC;
if ((first_offset == 0) && (first_bii == 0) &&
(*minext < rbm->rgd->rd_extfail_pt))
rbm->rgd->rd_extfail_pt = *minext;
if (maxext.len) {
*rbm = maxext.rbm;
*minext = maxext.len;
return 0;
}
return -ENOSPC;
}
static void try_rgrp_unlink(struct gfs2_rgrpd *rgd, u64 *last_unlinked, u64 skip)
{
u64 block;
struct gfs2_sbd *sdp = rgd->rd_sbd;
struct gfs2_glock *gl;
struct gfs2_inode *ip;
int error;
int found = 0;
struct gfs2_rbm rbm = { .rgd = rgd, .bii = 0, .offset = 0 };
while (1) {
down_write(&sdp->sd_log_flush_lock);
error = gfs2_rbm_find(&rbm, GFS2_BLKST_UNLINKED, NULL, NULL,
true, NULL);
up_write(&sdp->sd_log_flush_lock);
if (error == -ENOSPC)
break;
if (WARN_ON_ONCE(error))
break;
block = gfs2_rbm_to_block(&rbm);
if (gfs2_rbm_from_block(&rbm, block + 1))
break;
if (*last_unlinked != NO_BLOCK && block <= *last_unlinked)
continue;
if (block == skip)
continue;
*last_unlinked = block;
error = gfs2_glock_get(sdp, block, &gfs2_inode_glops, CREATE, &gl);
if (error)
continue;
ip = gl->gl_object;
if (ip || queue_work(gfs2_delete_workqueue, &gl->gl_delete) == 0)
gfs2_glock_put(gl);
else
found++;
if (found > NR_CPUS)
return;
}
rgd->rd_flags &= ~GFS2_RDF_CHECK;
return;
}
static bool gfs2_rgrp_congested(const struct gfs2_rgrpd *rgd, int loops)
{
const struct gfs2_glock *gl = rgd->rd_gl;
const struct gfs2_sbd *sdp = gl->gl_sbd;
struct gfs2_lkstats *st;
s64 r_dcount, l_dcount;
s64 r_srttb, l_srttb;
s64 srttb_diff;
s64 sqr_diff;
s64 var;
preempt_disable();
st = &this_cpu_ptr(sdp->sd_lkstats)->lkstats[LM_TYPE_RGRP];
r_srttb = st->stats[GFS2_LKS_SRTTB];
r_dcount = st->stats[GFS2_LKS_DCOUNT];
var = st->stats[GFS2_LKS_SRTTVARB] +
gl->gl_stats.stats[GFS2_LKS_SRTTVARB];
preempt_enable();
l_srttb = gl->gl_stats.stats[GFS2_LKS_SRTTB];
l_dcount = gl->gl_stats.stats[GFS2_LKS_DCOUNT];
if ((l_dcount < 1) || (r_dcount < 1) || (r_srttb == 0))
return false;
srttb_diff = r_srttb - l_srttb;
sqr_diff = srttb_diff * srttb_diff;
var *= 2;
if (l_dcount < 8 || r_dcount < 8)
var *= 2;
if (loops == 1)
var *= 2;
return ((srttb_diff < 0) && (sqr_diff > var));
}
static bool gfs2_rgrp_used_recently(const struct gfs2_blkreserv *rs,
u64 msecs)
{
u64 tdiff;
tdiff = ktime_to_ns(ktime_sub(ktime_get_real(),
rs->rs_rbm.rgd->rd_gl->gl_dstamp));
return tdiff > (msecs * 1000 * 1000);
}
static u32 gfs2_orlov_skip(const struct gfs2_inode *ip)
{
const struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
u32 skip;
get_random_bytes(&skip, sizeof(skip));
return skip % sdp->sd_rgrps;
}
static bool gfs2_select_rgrp(struct gfs2_rgrpd **pos, const struct gfs2_rgrpd *begin)
{
struct gfs2_rgrpd *rgd = *pos;
struct gfs2_sbd *sdp = rgd->rd_sbd;
rgd = gfs2_rgrpd_get_next(rgd);
if (rgd == NULL)
rgd = gfs2_rgrpd_get_first(sdp);
*pos = rgd;
if (rgd != begin)
return true;
return false;
}
int gfs2_inplace_reserve(struct gfs2_inode *ip, const struct gfs2_alloc_parms *ap)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
struct gfs2_rgrpd *begin = NULL;
struct gfs2_blkreserv *rs = ip->i_res;
int error = 0, rg_locked, flags = 0;
u64 last_unlinked = NO_BLOCK;
int loops = 0;
u32 skip = 0;
if (sdp->sd_args.ar_rgrplvb)
flags |= GL_SKIP;
if (gfs2_assert_warn(sdp, ap->target))
return -EINVAL;
if (gfs2_rs_active(rs)) {
begin = rs->rs_rbm.rgd;
} else if (ip->i_rgd && rgrp_contains_block(ip->i_rgd, ip->i_goal)) {
rs->rs_rbm.rgd = begin = ip->i_rgd;
} else {
rs->rs_rbm.rgd = begin = gfs2_blk2rgrpd(sdp, ip->i_goal, 1);
}
if (S_ISDIR(ip->i_inode.i_mode) && (ap->aflags & GFS2_AF_ORLOV))
skip = gfs2_orlov_skip(ip);
if (rs->rs_rbm.rgd == NULL)
return -EBADSLT;
while (loops < 3) {
rg_locked = 1;
if (!gfs2_glock_is_locked_by_me(rs->rs_rbm.rgd->rd_gl)) {
rg_locked = 0;
if (skip && skip--)
goto next_rgrp;
if (!gfs2_rs_active(rs) && (loops < 2) &&
gfs2_rgrp_used_recently(rs, 1000) &&
gfs2_rgrp_congested(rs->rs_rbm.rgd, loops))
goto next_rgrp;
error = gfs2_glock_nq_init(rs->rs_rbm.rgd->rd_gl,
LM_ST_EXCLUSIVE, flags,
&rs->rs_rgd_gh);
if (unlikely(error))
return error;
if (!gfs2_rs_active(rs) && (loops < 2) &&
gfs2_rgrp_congested(rs->rs_rbm.rgd, loops))
goto skip_rgrp;
if (sdp->sd_args.ar_rgrplvb) {
error = update_rgrp_lvb(rs->rs_rbm.rgd);
if (unlikely(error)) {
gfs2_glock_dq_uninit(&rs->rs_rgd_gh);
return error;
}
}
}
if ((rs->rs_rbm.rgd->rd_flags & (GFS2_RGF_NOALLOC |
GFS2_RDF_ERROR)) ||
(ap->target > rs->rs_rbm.rgd->rd_extfail_pt))
goto skip_rgrp;
if (sdp->sd_args.ar_rgrplvb)
gfs2_rgrp_bh_get(rs->rs_rbm.rgd);
if (!gfs2_rs_active(rs))
rg_mblk_search(rs->rs_rbm.rgd, ip, ap);
if (!gfs2_rs_active(rs) && (loops < 1))
goto check_rgrp;
if (rs->rs_rbm.rgd->rd_free_clone >= ap->target) {
ip->i_rgd = rs->rs_rbm.rgd;
return 0;
}
check_rgrp:
if (rs->rs_rbm.rgd->rd_flags & GFS2_RDF_CHECK)
try_rgrp_unlink(rs->rs_rbm.rgd, &last_unlinked,
ip->i_no_addr);
skip_rgrp:
if (gfs2_rs_active(rs))
gfs2_rs_deltree(rs);
if (!rg_locked)
gfs2_glock_dq_uninit(&rs->rs_rgd_gh);
next_rgrp:
if (gfs2_select_rgrp(&rs->rs_rbm.rgd, begin))
continue;
if (skip)
continue;
loops++;
if (ip == GFS2_I(sdp->sd_rindex) && !sdp->sd_rindex_uptodate) {
error = gfs2_ri_update(ip);
if (error)
return error;
}
if (loops == 2)
gfs2_log_flush(sdp, NULL);
}
return -ENOSPC;
}
void gfs2_inplace_release(struct gfs2_inode *ip)
{
struct gfs2_blkreserv *rs = ip->i_res;
if (rs->rs_rgd_gh.gh_gl)
gfs2_glock_dq_uninit(&rs->rs_rgd_gh);
}
static unsigned char gfs2_get_block_type(struct gfs2_rgrpd *rgd, u64 block)
{
struct gfs2_rbm rbm = { .rgd = rgd, };
int ret;
ret = gfs2_rbm_from_block(&rbm, block);
WARN_ON_ONCE(ret != 0);
return gfs2_testbit(&rbm);
}
static void gfs2_alloc_extent(const struct gfs2_rbm *rbm, bool dinode,
unsigned int *n)
{
struct gfs2_rbm pos = { .rgd = rbm->rgd, };
const unsigned int elen = *n;
u64 block;
int ret;
*n = 1;
block = gfs2_rbm_to_block(rbm);
gfs2_trans_add_meta(rbm->rgd->rd_gl, rbm_bi(rbm)->bi_bh);
gfs2_setbit(rbm, true, dinode ? GFS2_BLKST_DINODE : GFS2_BLKST_USED);
block++;
while (*n < elen) {
ret = gfs2_rbm_from_block(&pos, block);
if (ret || gfs2_testbit(&pos) != GFS2_BLKST_FREE)
break;
gfs2_trans_add_meta(pos.rgd->rd_gl, rbm_bi(&pos)->bi_bh);
gfs2_setbit(&pos, true, GFS2_BLKST_USED);
(*n)++;
block++;
}
}
static struct gfs2_rgrpd *rgblk_free(struct gfs2_sbd *sdp, u64 bstart,
u32 blen, unsigned char new_state)
{
struct gfs2_rbm rbm;
struct gfs2_bitmap *bi;
rbm.rgd = gfs2_blk2rgrpd(sdp, bstart, 1);
if (!rbm.rgd) {
if (gfs2_consist(sdp))
fs_err(sdp, "block = %llu\n", (unsigned long long)bstart);
return NULL;
}
while (blen--) {
gfs2_rbm_from_block(&rbm, bstart);
bi = rbm_bi(&rbm);
bstart++;
if (!bi->bi_clone) {
bi->bi_clone = kmalloc(bi->bi_bh->b_size,
GFP_NOFS | __GFP_NOFAIL);
memcpy(bi->bi_clone + bi->bi_offset,
bi->bi_bh->b_data + bi->bi_offset, bi->bi_len);
}
gfs2_trans_add_meta(rbm.rgd->rd_gl, bi->bi_bh);
gfs2_setbit(&rbm, false, new_state);
}
return rbm.rgd;
}
void gfs2_rgrp_dump(struct seq_file *seq, const struct gfs2_glock *gl)
{
struct gfs2_rgrpd *rgd = gl->gl_object;
struct gfs2_blkreserv *trs;
const struct rb_node *n;
if (rgd == NULL)
return;
gfs2_print_dbg(seq, " R: n:%llu f:%02x b:%u/%u i:%u r:%u e:%u\n",
(unsigned long long)rgd->rd_addr, rgd->rd_flags,
rgd->rd_free, rgd->rd_free_clone, rgd->rd_dinodes,
rgd->rd_reserved, rgd->rd_extfail_pt);
spin_lock(&rgd->rd_rsspin);
for (n = rb_first(&rgd->rd_rstree); n; n = rb_next(&trs->rs_node)) {
trs = rb_entry(n, struct gfs2_blkreserv, rs_node);
dump_rs(seq, trs);
}
spin_unlock(&rgd->rd_rsspin);
}
static void gfs2_rgrp_error(struct gfs2_rgrpd *rgd)
{
struct gfs2_sbd *sdp = rgd->rd_sbd;
fs_warn(sdp, "rgrp %llu has an error, marking it readonly until umount\n",
(unsigned long long)rgd->rd_addr);
fs_warn(sdp, "umount on all nodes and run fsck.gfs2 to fix the error\n");
gfs2_rgrp_dump(NULL, rgd->rd_gl);
rgd->rd_flags |= GFS2_RDF_ERROR;
}
static void gfs2_adjust_reservation(struct gfs2_inode *ip,
const struct gfs2_rbm *rbm, unsigned len)
{
struct gfs2_blkreserv *rs = ip->i_res;
struct gfs2_rgrpd *rgd = rbm->rgd;
unsigned rlen;
u64 block;
int ret;
spin_lock(&rgd->rd_rsspin);
if (gfs2_rs_active(rs)) {
if (gfs2_rbm_eq(&rs->rs_rbm, rbm)) {
block = gfs2_rbm_to_block(rbm);
ret = gfs2_rbm_from_block(&rs->rs_rbm, block + len);
rlen = min(rs->rs_free, len);
rs->rs_free -= rlen;
rgd->rd_reserved -= rlen;
trace_gfs2_rs(rs, TRACE_RS_CLAIM);
if (rs->rs_free && !ret)
goto out;
}
__rs_deltree(rs);
}
out:
spin_unlock(&rgd->rd_rsspin);
}
static void gfs2_set_alloc_start(struct gfs2_rbm *rbm,
const struct gfs2_inode *ip, bool dinode)
{
u64 goal;
if (gfs2_rs_active(ip->i_res)) {
*rbm = ip->i_res->rs_rbm;
return;
}
if (!dinode && rgrp_contains_block(rbm->rgd, ip->i_goal))
goal = ip->i_goal;
else
goal = rbm->rgd->rd_last_alloc + rbm->rgd->rd_data0;
gfs2_rbm_from_block(rbm, goal);
}
int gfs2_alloc_blocks(struct gfs2_inode *ip, u64 *bn, unsigned int *nblocks,
bool dinode, u64 *generation)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
struct buffer_head *dibh;
struct gfs2_rbm rbm = { .rgd = ip->i_rgd, };
unsigned int ndata;
u64 block;
int error;
gfs2_set_alloc_start(&rbm, ip, dinode);
error = gfs2_rbm_find(&rbm, GFS2_BLKST_FREE, NULL, ip, false, NULL);
if (error == -ENOSPC) {
gfs2_set_alloc_start(&rbm, ip, dinode);
error = gfs2_rbm_find(&rbm, GFS2_BLKST_FREE, NULL, NULL, false,
NULL);
}
if (error) {
fs_warn(sdp, "inum=%llu error=%d, nblocks=%u, full=%d fail_pt=%d\n",
(unsigned long long)ip->i_no_addr, error, *nblocks,
test_bit(GBF_FULL, &rbm.rgd->rd_bits->bi_flags),
rbm.rgd->rd_extfail_pt);
goto rgrp_error;
}
gfs2_alloc_extent(&rbm, dinode, nblocks);
block = gfs2_rbm_to_block(&rbm);
rbm.rgd->rd_last_alloc = block - rbm.rgd->rd_data0;
if (gfs2_rs_active(ip->i_res))
gfs2_adjust_reservation(ip, &rbm, *nblocks);
ndata = *nblocks;
if (dinode)
ndata--;
if (!dinode) {
ip->i_goal = block + ndata - 1;
error = gfs2_meta_inode_buffer(ip, &dibh);
if (error == 0) {
struct gfs2_dinode *di =
(struct gfs2_dinode *)dibh->b_data;
gfs2_trans_add_meta(ip->i_gl, dibh);
di->di_goal_meta = di->di_goal_data =
cpu_to_be64(ip->i_goal);
brelse(dibh);
}
}
if (rbm.rgd->rd_free < *nblocks) {
pr_warn("nblocks=%u\n", *nblocks);
goto rgrp_error;
}
rbm.rgd->rd_free -= *nblocks;
if (dinode) {
rbm.rgd->rd_dinodes++;
*generation = rbm.rgd->rd_igeneration++;
if (*generation == 0)
*generation = rbm.rgd->rd_igeneration++;
}
gfs2_trans_add_meta(rbm.rgd->rd_gl, rbm.rgd->rd_bits[0].bi_bh);
gfs2_rgrp_out(rbm.rgd, rbm.rgd->rd_bits[0].bi_bh->b_data);
gfs2_rgrp_ondisk2lvb(rbm.rgd->rd_rgl, rbm.rgd->rd_bits[0].bi_bh->b_data);
gfs2_statfs_change(sdp, 0, -(s64)*nblocks, dinode ? 1 : 0);
if (dinode)
gfs2_trans_add_unrevoke(sdp, block, *nblocks);
gfs2_quota_change(ip, *nblocks, ip->i_inode.i_uid, ip->i_inode.i_gid);
rbm.rgd->rd_free_clone -= *nblocks;
trace_gfs2_block_alloc(ip, rbm.rgd, block, *nblocks,
dinode ? GFS2_BLKST_DINODE : GFS2_BLKST_USED);
*bn = block;
return 0;
rgrp_error:
gfs2_rgrp_error(rbm.rgd);
return -EIO;
}
void __gfs2_free_blocks(struct gfs2_inode *ip, u64 bstart, u32 blen, int meta)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
struct gfs2_rgrpd *rgd;
rgd = rgblk_free(sdp, bstart, blen, GFS2_BLKST_FREE);
if (!rgd)
return;
trace_gfs2_block_alloc(ip, rgd, bstart, blen, GFS2_BLKST_FREE);
rgd->rd_free += blen;
rgd->rd_flags &= ~GFS2_RGF_TRIMMED;
gfs2_trans_add_meta(rgd->rd_gl, rgd->rd_bits[0].bi_bh);
gfs2_rgrp_out(rgd, rgd->rd_bits[0].bi_bh->b_data);
gfs2_rgrp_ondisk2lvb(rgd->rd_rgl, rgd->rd_bits[0].bi_bh->b_data);
if (meta || ip->i_depth)
gfs2_meta_wipe(ip, bstart, blen);
}
void gfs2_free_meta(struct gfs2_inode *ip, u64 bstart, u32 blen)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
__gfs2_free_blocks(ip, bstart, blen, 1);
gfs2_statfs_change(sdp, 0, +blen, 0);
gfs2_quota_change(ip, -(s64)blen, ip->i_inode.i_uid, ip->i_inode.i_gid);
}
void gfs2_unlink_di(struct inode *inode)
{
struct gfs2_inode *ip = GFS2_I(inode);
struct gfs2_sbd *sdp = GFS2_SB(inode);
struct gfs2_rgrpd *rgd;
u64 blkno = ip->i_no_addr;
rgd = rgblk_free(sdp, blkno, 1, GFS2_BLKST_UNLINKED);
if (!rgd)
return;
trace_gfs2_block_alloc(ip, rgd, blkno, 1, GFS2_BLKST_UNLINKED);
gfs2_trans_add_meta(rgd->rd_gl, rgd->rd_bits[0].bi_bh);
gfs2_rgrp_out(rgd, rgd->rd_bits[0].bi_bh->b_data);
gfs2_rgrp_ondisk2lvb(rgd->rd_rgl, rgd->rd_bits[0].bi_bh->b_data);
update_rgrp_lvb_unlinked(rgd, 1);
}
static void gfs2_free_uninit_di(struct gfs2_rgrpd *rgd, u64 blkno)
{
struct gfs2_sbd *sdp = rgd->rd_sbd;
struct gfs2_rgrpd *tmp_rgd;
tmp_rgd = rgblk_free(sdp, blkno, 1, GFS2_BLKST_FREE);
if (!tmp_rgd)
return;
gfs2_assert_withdraw(sdp, rgd == tmp_rgd);
if (!rgd->rd_dinodes)
gfs2_consist_rgrpd(rgd);
rgd->rd_dinodes--;
rgd->rd_free++;
gfs2_trans_add_meta(rgd->rd_gl, rgd->rd_bits[0].bi_bh);
gfs2_rgrp_out(rgd, rgd->rd_bits[0].bi_bh->b_data);
gfs2_rgrp_ondisk2lvb(rgd->rd_rgl, rgd->rd_bits[0].bi_bh->b_data);
update_rgrp_lvb_unlinked(rgd, -1);
gfs2_statfs_change(sdp, 0, +1, -1);
}
void gfs2_free_di(struct gfs2_rgrpd *rgd, struct gfs2_inode *ip)
{
gfs2_free_uninit_di(rgd, ip->i_no_addr);
trace_gfs2_block_alloc(ip, rgd, ip->i_no_addr, 1, GFS2_BLKST_FREE);
gfs2_quota_change(ip, -1, ip->i_inode.i_uid, ip->i_inode.i_gid);
gfs2_meta_wipe(ip, ip->i_no_addr, 1);
}
int gfs2_check_blk_type(struct gfs2_sbd *sdp, u64 no_addr, unsigned int type)
{
struct gfs2_rgrpd *rgd;
struct gfs2_holder rgd_gh;
int error = -EINVAL;
rgd = gfs2_blk2rgrpd(sdp, no_addr, 1);
if (!rgd)
goto fail;
error = gfs2_glock_nq_init(rgd->rd_gl, LM_ST_SHARED, 0, &rgd_gh);
if (error)
goto fail;
if (gfs2_get_block_type(rgd, no_addr) != type)
error = -ESTALE;
gfs2_glock_dq_uninit(&rgd_gh);
fail:
return error;
}
void gfs2_rlist_add(struct gfs2_inode *ip, struct gfs2_rgrp_list *rlist,
u64 block)
{
struct gfs2_sbd *sdp = GFS2_SB(&ip->i_inode);
struct gfs2_rgrpd *rgd;
struct gfs2_rgrpd **tmp;
unsigned int new_space;
unsigned int x;
if (gfs2_assert_warn(sdp, !rlist->rl_ghs))
return;
if (ip->i_rgd && rgrp_contains_block(ip->i_rgd, block))
rgd = ip->i_rgd;
else
rgd = gfs2_blk2rgrpd(sdp, block, 1);
if (!rgd) {
fs_err(sdp, "rlist_add: no rgrp for block %llu\n", (unsigned long long)block);
return;
}
ip->i_rgd = rgd;
for (x = 0; x < rlist->rl_rgrps; x++)
if (rlist->rl_rgd[x] == rgd)
return;
if (rlist->rl_rgrps == rlist->rl_space) {
new_space = rlist->rl_space + 10;
tmp = kcalloc(new_space, sizeof(struct gfs2_rgrpd *),
GFP_NOFS | __GFP_NOFAIL);
if (rlist->rl_rgd) {
memcpy(tmp, rlist->rl_rgd,
rlist->rl_space * sizeof(struct gfs2_rgrpd *));
kfree(rlist->rl_rgd);
}
rlist->rl_space = new_space;
rlist->rl_rgd = tmp;
}
rlist->rl_rgd[rlist->rl_rgrps++] = rgd;
}
void gfs2_rlist_alloc(struct gfs2_rgrp_list *rlist, unsigned int state)
{
unsigned int x;
rlist->rl_ghs = kcalloc(rlist->rl_rgrps, sizeof(struct gfs2_holder),
GFP_NOFS | __GFP_NOFAIL);
for (x = 0; x < rlist->rl_rgrps; x++)
gfs2_holder_init(rlist->rl_rgd[x]->rd_gl,
state, 0,
&rlist->rl_ghs[x]);
}
void gfs2_rlist_free(struct gfs2_rgrp_list *rlist)
{
unsigned int x;
kfree(rlist->rl_rgd);
if (rlist->rl_ghs) {
for (x = 0; x < rlist->rl_rgrps; x++)
gfs2_holder_uninit(&rlist->rl_ghs[x]);
kfree(rlist->rl_ghs);
rlist->rl_ghs = NULL;
}
}
