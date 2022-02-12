static int make_idx_node(struct ubifs_info *c, struct ubifs_idx_node *idx,
struct ubifs_znode *znode, int lnum, int offs, int len)
{
struct ubifs_znode *zp;
int i, err;
idx->ch.node_type = UBIFS_IDX_NODE;
idx->child_cnt = cpu_to_le16(znode->child_cnt);
idx->level = cpu_to_le16(znode->level);
for (i = 0; i < znode->child_cnt; i++) {
struct ubifs_branch *br = ubifs_idx_branch(c, idx, i);
struct ubifs_zbranch *zbr = &znode->zbranch[i];
key_write_idx(c, &zbr->key, &br->key);
br->lnum = cpu_to_le32(zbr->lnum);
br->offs = cpu_to_le32(zbr->offs);
br->len = cpu_to_le32(zbr->len);
if (!zbr->lnum || !zbr->len) {
ubifs_err(c, "bad ref in znode");
ubifs_dump_znode(c, znode);
if (zbr->znode)
ubifs_dump_znode(c, zbr->znode);
return -EINVAL;
}
}
ubifs_prepare_node(c, idx, len, 0);
znode->lnum = lnum;
znode->offs = offs;
znode->len = len;
err = insert_old_idx_znode(c, znode);
zp = znode->parent;
if (zp) {
struct ubifs_zbranch *zbr;
zbr = &zp->zbranch[znode->iip];
zbr->lnum = lnum;
zbr->offs = offs;
zbr->len = len;
} else {
c->zroot.lnum = lnum;
c->zroot.offs = offs;
c->zroot.len = len;
}
c->calc_idx_sz += ALIGN(len, 8);
atomic_long_dec(&c->dirty_zn_cnt);
ubifs_assert(ubifs_zn_dirty(znode));
ubifs_assert(ubifs_zn_cow(znode));
__clear_bit(DIRTY_ZNODE, &znode->flags);
__clear_bit(COW_ZNODE, &znode->flags);
return err;
}
static int fill_gap(struct ubifs_info *c, int lnum, int gap_start, int gap_end,
int *dirt)
{
int len, gap_remains, gap_pos, written, pad_len;
ubifs_assert((gap_start & 7) == 0);
ubifs_assert((gap_end & 7) == 0);
ubifs_assert(gap_end >= gap_start);
gap_remains = gap_end - gap_start;
if (!gap_remains)
return 0;
gap_pos = gap_start;
written = 0;
while (c->enext) {
len = ubifs_idx_node_sz(c, c->enext->child_cnt);
if (len < gap_remains) {
struct ubifs_znode *znode = c->enext;
const int alen = ALIGN(len, 8);
int err;
ubifs_assert(alen <= gap_remains);
err = make_idx_node(c, c->ileb_buf + gap_pos, znode,
lnum, gap_pos, len);
if (err)
return err;
gap_remains -= alen;
gap_pos += alen;
c->enext = znode->cnext;
if (c->enext == c->cnext)
c->enext = NULL;
written += 1;
} else
break;
}
if (gap_end == c->leb_size) {
c->ileb_len = ALIGN(gap_pos, c->min_io_size);
pad_len = c->ileb_len - gap_pos;
} else
pad_len = gap_remains;
dbg_gc("LEB %d:%d to %d len %d nodes written %d wasted bytes %d",
lnum, gap_start, gap_end, gap_end - gap_start, written, pad_len);
ubifs_pad(c, c->ileb_buf + gap_pos, pad_len);
*dirt += pad_len;
return written;
}
static int find_old_idx(struct ubifs_info *c, int lnum, int offs)
{
struct ubifs_old_idx *o;
struct rb_node *p;
p = c->old_idx.rb_node;
while (p) {
o = rb_entry(p, struct ubifs_old_idx, rb);
if (lnum < o->lnum)
p = p->rb_left;
else if (lnum > o->lnum)
p = p->rb_right;
else if (offs < o->offs)
p = p->rb_left;
else if (offs > o->offs)
p = p->rb_right;
else
return 1;
}
return 0;
}
static int is_idx_node_in_use(struct ubifs_info *c, union ubifs_key *key,
int level, int lnum, int offs)
{
int ret;
ret = is_idx_node_in_tnc(c, key, level, lnum, offs);
if (ret < 0)
return ret;
if (ret == 0)
if (find_old_idx(c, lnum, offs))
return 1;
return ret;
}
static int layout_leb_in_gaps(struct ubifs_info *c, int *p)
{
struct ubifs_scan_leb *sleb;
struct ubifs_scan_node *snod;
int lnum, dirt = 0, gap_start, gap_end, err, written, tot_written;
tot_written = 0;
lnum = ubifs_find_dirty_idx_leb(c);
if (lnum < 0)
return lnum;
*p = lnum;
dbg_gc("LEB %d", lnum);
sleb = ubifs_scan(c, lnum, 0, c->ileb_buf, 0);
c->ileb_len = 0;
if (IS_ERR(sleb))
return PTR_ERR(sleb);
gap_start = 0;
list_for_each_entry(snod, &sleb->nodes, list) {
struct ubifs_idx_node *idx;
int in_use, level;
ubifs_assert(snod->type == UBIFS_IDX_NODE);
idx = snod->node;
key_read(c, ubifs_idx_key(c, idx), &snod->key);
level = le16_to_cpu(idx->level);
in_use = is_idx_node_in_use(c, &snod->key, level, lnum,
snod->offs);
if (in_use < 0) {
ubifs_scan_destroy(sleb);
return in_use;
}
if (in_use) {
if (in_use == 1)
dirt += ALIGN(snod->len, 8);
gap_end = snod->offs;
written = fill_gap(c, lnum, gap_start, gap_end, &dirt);
if (written < 0) {
ubifs_scan_destroy(sleb);
return written;
}
tot_written += written;
gap_start = ALIGN(snod->offs + snod->len, 8);
}
}
ubifs_scan_destroy(sleb);
c->ileb_len = c->leb_size;
gap_end = c->leb_size;
written = fill_gap(c, lnum, gap_start, gap_end, &dirt);
if (written < 0)
return written;
tot_written += written;
if (tot_written == 0) {
struct ubifs_lprops lp;
dbg_gc("LEB %d wrote %d index nodes", lnum, tot_written);
err = ubifs_read_one_lp(c, lnum, &lp);
if (err)
return err;
if (lp.free == c->leb_size) {
err = ubifs_change_one_lp(c, lnum,
c->leb_size - c->ileb_len,
dirt, 0, 0, 0);
if (err)
return err;
}
return 0;
}
err = ubifs_change_one_lp(c, lnum, c->leb_size - c->ileb_len, dirt,
0, 0, 0);
if (err)
return err;
err = ubifs_leb_change(c, lnum, c->ileb_buf, c->ileb_len);
if (err)
return err;
dbg_gc("LEB %d wrote %d index nodes", lnum, tot_written);
return tot_written;
}
static int get_leb_cnt(struct ubifs_info *c, int cnt)
{
int d;
cnt -= (c->leb_size - c->ihead_offs) / c->max_idx_node_sz;
if (cnt < 0)
cnt = 0;
d = c->leb_size / c->max_idx_node_sz;
return DIV_ROUND_UP(cnt, d);
}
static int layout_in_gaps(struct ubifs_info *c, int cnt)
{
int err, leb_needed_cnt, written, *p;
dbg_gc("%d znodes to write", cnt);
c->gap_lebs = kmalloc(sizeof(int) * (c->lst.idx_lebs + 1), GFP_NOFS);
if (!c->gap_lebs)
return -ENOMEM;
p = c->gap_lebs;
do {
ubifs_assert(p < c->gap_lebs + c->lst.idx_lebs);
written = layout_leb_in_gaps(c, p);
if (written < 0) {
err = written;
if (err != -ENOSPC) {
kfree(c->gap_lebs);
c->gap_lebs = NULL;
return err;
}
if (!dbg_is_chk_index(c)) {
ubifs_warn(c, "out of space");
ubifs_dump_budg(c, &c->bi);
ubifs_dump_lprops(c);
}
break;
}
p++;
cnt -= written;
leb_needed_cnt = get_leb_cnt(c, cnt);
dbg_gc("%d znodes remaining, need %d LEBs, have %d", cnt,
leb_needed_cnt, c->ileb_cnt);
} while (leb_needed_cnt > c->ileb_cnt);
*p = -1;
return 0;
}
static int layout_in_empty_space(struct ubifs_info *c)
{
struct ubifs_znode *znode, *cnext, *zp;
int lnum, offs, len, next_len, buf_len, buf_offs, used, avail;
int wlen, blen, err;
cnext = c->enext;
if (!cnext)
return 0;
lnum = c->ihead_lnum;
buf_offs = c->ihead_offs;
buf_len = ubifs_idx_node_sz(c, c->fanout);
buf_len = ALIGN(buf_len, c->min_io_size);
used = 0;
avail = buf_len;
next_len = ubifs_idx_node_sz(c, cnext->child_cnt);
if (buf_offs + next_len > c->leb_size)
lnum = -1;
while (1) {
znode = cnext;
len = ubifs_idx_node_sz(c, znode->child_cnt);
if (lnum == -1) {
if (c->ileb_nxt >= c->ileb_cnt) {
ubifs_err(c, "out of space");
return -ENOSPC;
}
lnum = c->ilebs[c->ileb_nxt++];
buf_offs = 0;
used = 0;
avail = buf_len;
}
offs = buf_offs + used;
znode->lnum = lnum;
znode->offs = offs;
znode->len = len;
zp = znode->parent;
if (zp) {
struct ubifs_zbranch *zbr;
int i;
i = znode->iip;
zbr = &zp->zbranch[i];
zbr->lnum = lnum;
zbr->offs = offs;
zbr->len = len;
} else {
c->zroot.lnum = lnum;
c->zroot.offs = offs;
c->zroot.len = len;
}
c->calc_idx_sz += ALIGN(len, 8);
atomic_long_dec(&c->dirty_zn_cnt);
cnext = znode->cnext;
if (cnext == c->cnext)
next_len = 0;
else
next_len = ubifs_idx_node_sz(c, cnext->child_cnt);
wlen = used + len;
used += ALIGN(len, 8);
avail -= ALIGN(len, 8);
if (next_len != 0 &&
buf_offs + used + next_len <= c->leb_size &&
avail > 0)
continue;
if (avail <= 0 && next_len &&
buf_offs + used + next_len <= c->leb_size)
blen = buf_len;
else
blen = ALIGN(wlen, c->min_io_size);
buf_offs += blen;
if (next_len) {
if (buf_offs + next_len > c->leb_size) {
err = ubifs_update_one_lp(c, lnum,
c->leb_size - buf_offs, blen - used,
0, 0);
if (err)
return err;
lnum = -1;
}
used -= blen;
if (used < 0)
used = 0;
avail = buf_len - used;
continue;
}
err = ubifs_update_one_lp(c, lnum, c->leb_size - buf_offs,
blen - used, 0, 0);
if (err)
return err;
break;
}
c->dbg->new_ihead_lnum = lnum;
c->dbg->new_ihead_offs = buf_offs;
return 0;
}
static int layout_commit(struct ubifs_info *c, int no_space, int cnt)
{
int err;
if (no_space) {
err = layout_in_gaps(c, cnt);
if (err)
return err;
}
err = layout_in_empty_space(c);
return err;
}
static struct ubifs_znode *find_first_dirty(struct ubifs_znode *znode)
{
int i, cont;
if (!znode)
return NULL;
while (1) {
if (znode->level == 0) {
if (ubifs_zn_dirty(znode))
return znode;
return NULL;
}
cont = 0;
for (i = 0; i < znode->child_cnt; i++) {
struct ubifs_zbranch *zbr = &znode->zbranch[i];
if (zbr->znode && ubifs_zn_dirty(zbr->znode)) {
znode = zbr->znode;
cont = 1;
break;
}
}
if (!cont) {
if (ubifs_zn_dirty(znode))
return znode;
return NULL;
}
}
}
static struct ubifs_znode *find_next_dirty(struct ubifs_znode *znode)
{
int n = znode->iip + 1;
znode = znode->parent;
if (!znode)
return NULL;
for (; n < znode->child_cnt; n++) {
struct ubifs_zbranch *zbr = &znode->zbranch[n];
if (zbr->znode && ubifs_zn_dirty(zbr->znode))
return find_first_dirty(zbr->znode);
}
return znode;
}
static int get_znodes_to_commit(struct ubifs_info *c)
{
struct ubifs_znode *znode, *cnext;
int cnt = 0;
c->cnext = find_first_dirty(c->zroot.znode);
znode = c->enext = c->cnext;
if (!znode) {
dbg_cmt("no znodes to commit");
return 0;
}
cnt += 1;
while (1) {
ubifs_assert(!ubifs_zn_cow(znode));
__set_bit(COW_ZNODE, &znode->flags);
znode->alt = 0;
cnext = find_next_dirty(znode);
if (!cnext) {
znode->cnext = c->cnext;
break;
}
znode->cnext = cnext;
znode = cnext;
cnt += 1;
}
dbg_cmt("committing %d znodes", cnt);
ubifs_assert(cnt == atomic_long_read(&c->dirty_zn_cnt));
return cnt;
}
static int alloc_idx_lebs(struct ubifs_info *c, int cnt)
{
int i, leb_cnt, lnum;
c->ileb_cnt = 0;
c->ileb_nxt = 0;
leb_cnt = get_leb_cnt(c, cnt);
dbg_cmt("need about %d empty LEBS for TNC commit", leb_cnt);
if (!leb_cnt)
return 0;
c->ilebs = kmalloc(leb_cnt * sizeof(int), GFP_NOFS);
if (!c->ilebs)
return -ENOMEM;
for (i = 0; i < leb_cnt; i++) {
lnum = ubifs_find_free_leb_for_idx(c);
if (lnum < 0)
return lnum;
c->ilebs[c->ileb_cnt++] = lnum;
dbg_cmt("LEB %d", lnum);
}
if (dbg_is_chk_index(c) && !(prandom_u32() & 7))
return -ENOSPC;
return 0;
}
static int free_unused_idx_lebs(struct ubifs_info *c)
{
int i, err = 0, lnum, er;
for (i = c->ileb_nxt; i < c->ileb_cnt; i++) {
lnum = c->ilebs[i];
dbg_cmt("LEB %d", lnum);
er = ubifs_change_one_lp(c, lnum, LPROPS_NC, LPROPS_NC, 0,
LPROPS_INDEX | LPROPS_TAKEN, 0);
if (!err)
err = er;
}
return err;
}
static int free_idx_lebs(struct ubifs_info *c)
{
int err;
err = free_unused_idx_lebs(c);
kfree(c->ilebs);
c->ilebs = NULL;
return err;
}
int ubifs_tnc_start_commit(struct ubifs_info *c, struct ubifs_zbranch *zroot)
{
int err = 0, cnt;
mutex_lock(&c->tnc_mutex);
err = dbg_check_tnc(c, 1);
if (err)
goto out;
cnt = get_znodes_to_commit(c);
if (cnt != 0) {
int no_space = 0;
err = alloc_idx_lebs(c, cnt);
if (err == -ENOSPC)
no_space = 1;
else if (err)
goto out_free;
err = layout_commit(c, no_space, cnt);
if (err)
goto out_free;
ubifs_assert(atomic_long_read(&c->dirty_zn_cnt) == 0);
err = free_unused_idx_lebs(c);
if (err)
goto out;
}
destroy_old_idx(c);
memcpy(zroot, &c->zroot, sizeof(struct ubifs_zbranch));
err = ubifs_save_dirty_idx_lnums(c);
if (err)
goto out;
spin_lock(&c->space_lock);
ubifs_assert(c->bi.min_idx_lebs == ubifs_calc_min_idx_lebs(c));
c->bi.old_idx_sz = c->calc_idx_sz;
c->bi.uncommitted_idx = 0;
c->bi.min_idx_lebs = ubifs_calc_min_idx_lebs(c);
spin_unlock(&c->space_lock);
mutex_unlock(&c->tnc_mutex);
dbg_cmt("number of index LEBs %d", c->lst.idx_lebs);
dbg_cmt("size of index %llu", c->calc_idx_sz);
return err;
out_free:
free_idx_lebs(c);
out:
mutex_unlock(&c->tnc_mutex);
return err;
}
static int write_index(struct ubifs_info *c)
{
struct ubifs_idx_node *idx;
struct ubifs_znode *znode, *cnext;
int i, lnum, offs, len, next_len, buf_len, buf_offs, used;
int avail, wlen, err, lnum_pos = 0, blen, nxt_offs;
cnext = c->enext;
if (!cnext)
return 0;
lnum = c->ihead_lnum;
buf_offs = c->ihead_offs;
buf_len = ALIGN(c->max_idx_node_sz, c->min_io_size);
used = 0;
avail = buf_len;
next_len = ubifs_idx_node_sz(c, cnext->child_cnt);
if (buf_offs + next_len > c->leb_size) {
err = ubifs_update_one_lp(c, lnum, LPROPS_NC, 0, 0,
LPROPS_TAKEN);
if (err)
return err;
lnum = -1;
}
while (1) {
cond_resched();
znode = cnext;
idx = c->cbuf + used;
idx->ch.node_type = UBIFS_IDX_NODE;
idx->child_cnt = cpu_to_le16(znode->child_cnt);
idx->level = cpu_to_le16(znode->level);
for (i = 0; i < znode->child_cnt; i++) {
struct ubifs_branch *br = ubifs_idx_branch(c, idx, i);
struct ubifs_zbranch *zbr = &znode->zbranch[i];
key_write_idx(c, &zbr->key, &br->key);
br->lnum = cpu_to_le32(zbr->lnum);
br->offs = cpu_to_le32(zbr->offs);
br->len = cpu_to_le32(zbr->len);
if (!zbr->lnum || !zbr->len) {
ubifs_err(c, "bad ref in znode");
ubifs_dump_znode(c, znode);
if (zbr->znode)
ubifs_dump_znode(c, zbr->znode);
return -EINVAL;
}
}
len = ubifs_idx_node_sz(c, znode->child_cnt);
ubifs_prepare_node(c, idx, len, 0);
if (lnum == -1) {
lnum = c->ilebs[lnum_pos++];
buf_offs = 0;
used = 0;
avail = buf_len;
}
offs = buf_offs + used;
if (lnum != znode->lnum || offs != znode->offs ||
len != znode->len) {
ubifs_err(c, "inconsistent znode posn");
return -EINVAL;
}
cnext = znode->cnext;
ubifs_assert(ubifs_zn_dirty(znode));
ubifs_assert(ubifs_zn_cow(znode));
clear_bit(DIRTY_ZNODE, &znode->flags);
smp_mb__before_atomic();
clear_bit(COW_ZNODE, &znode->flags);
smp_mb__after_atomic();
wlen = used + len;
used += ALIGN(len, 8);
avail -= ALIGN(len, 8);
if (cnext == c->cnext)
next_len = 0;
else
next_len = ubifs_idx_node_sz(c, cnext->child_cnt);
nxt_offs = buf_offs + used + next_len;
if (next_len && nxt_offs <= c->leb_size) {
if (avail > 0)
continue;
else
blen = buf_len;
} else {
wlen = ALIGN(wlen, 8);
blen = ALIGN(wlen, c->min_io_size);
ubifs_pad(c, c->cbuf + wlen, blen - wlen);
}
err = ubifs_leb_write(c, lnum, c->cbuf, buf_offs, blen);
if (err)
return err;
buf_offs += blen;
if (next_len) {
if (nxt_offs > c->leb_size) {
err = ubifs_update_one_lp(c, lnum, LPROPS_NC, 0,
0, LPROPS_TAKEN);
if (err)
return err;
lnum = -1;
}
used -= blen;
if (used < 0)
used = 0;
avail = buf_len - used;
memmove(c->cbuf, c->cbuf + blen, used);
continue;
}
break;
}
if (lnum != c->dbg->new_ihead_lnum ||
buf_offs != c->dbg->new_ihead_offs) {
ubifs_err(c, "inconsistent ihead");
return -EINVAL;
}
c->ihead_lnum = lnum;
c->ihead_offs = buf_offs;
return 0;
}
static void free_obsolete_znodes(struct ubifs_info *c)
{
struct ubifs_znode *znode, *cnext;
cnext = c->cnext;
do {
znode = cnext;
cnext = znode->cnext;
if (ubifs_zn_obsolete(znode))
kfree(znode);
else {
znode->cnext = NULL;
atomic_long_inc(&c->clean_zn_cnt);
atomic_long_inc(&ubifs_clean_zn_cnt);
}
} while (cnext != c->cnext);
}
static int return_gap_lebs(struct ubifs_info *c)
{
int *p, err;
if (!c->gap_lebs)
return 0;
dbg_cmt("");
for (p = c->gap_lebs; *p != -1; p++) {
err = ubifs_change_one_lp(c, *p, LPROPS_NC, LPROPS_NC, 0,
LPROPS_TAKEN, 0);
if (err)
return err;
}
kfree(c->gap_lebs);
c->gap_lebs = NULL;
return 0;
}
int ubifs_tnc_end_commit(struct ubifs_info *c)
{
int err;
if (!c->cnext)
return 0;
err = return_gap_lebs(c);
if (err)
return err;
err = write_index(c);
if (err)
return err;
mutex_lock(&c->tnc_mutex);
dbg_cmt("TNC height is %d", c->zroot.znode->level + 1);
free_obsolete_znodes(c);
c->cnext = NULL;
kfree(c->ilebs);
c->ilebs = NULL;
mutex_unlock(&c->tnc_mutex);
return 0;
}
