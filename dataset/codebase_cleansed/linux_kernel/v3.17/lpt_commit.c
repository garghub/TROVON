static struct ubifs_cnode *first_dirty_cnode(struct ubifs_nnode *nnode)
{
ubifs_assert(nnode);
while (1) {
int i, cont = 0;
for (i = 0; i < UBIFS_LPT_FANOUT; i++) {
struct ubifs_cnode *cnode;
cnode = nnode->nbranch[i].cnode;
if (cnode &&
test_bit(DIRTY_CNODE, &cnode->flags)) {
if (cnode->level == 0)
return cnode;
nnode = (struct ubifs_nnode *)cnode;
cont = 1;
break;
}
}
if (!cont)
return (struct ubifs_cnode *)nnode;
}
}
static struct ubifs_cnode *next_dirty_cnode(struct ubifs_cnode *cnode)
{
struct ubifs_nnode *nnode;
int i;
ubifs_assert(cnode);
nnode = cnode->parent;
if (!nnode)
return NULL;
for (i = cnode->iip + 1; i < UBIFS_LPT_FANOUT; i++) {
cnode = nnode->nbranch[i].cnode;
if (cnode && test_bit(DIRTY_CNODE, &cnode->flags)) {
if (cnode->level == 0)
return cnode;
return first_dirty_cnode((struct ubifs_nnode *)cnode);
}
}
return (struct ubifs_cnode *)nnode;
}
static int get_cnodes_to_commit(struct ubifs_info *c)
{
struct ubifs_cnode *cnode, *cnext;
int cnt = 0;
if (!c->nroot)
return 0;
if (!test_bit(DIRTY_CNODE, &c->nroot->flags))
return 0;
c->lpt_cnext = first_dirty_cnode(c->nroot);
cnode = c->lpt_cnext;
if (!cnode)
return 0;
cnt += 1;
while (1) {
ubifs_assert(!test_bit(COW_CNODE, &cnode->flags));
__set_bit(COW_CNODE, &cnode->flags);
cnext = next_dirty_cnode(cnode);
if (!cnext) {
cnode->cnext = c->lpt_cnext;
break;
}
cnode->cnext = cnext;
cnode = cnext;
cnt += 1;
}
dbg_cmt("committing %d cnodes", cnt);
dbg_lp("committing %d cnodes", cnt);
ubifs_assert(cnt == c->dirty_nn_cnt + c->dirty_pn_cnt);
return cnt;
}
static void upd_ltab(struct ubifs_info *c, int lnum, int free, int dirty)
{
dbg_lp("LEB %d free %d dirty %d to %d +%d",
lnum, c->ltab[lnum - c->lpt_first].free,
c->ltab[lnum - c->lpt_first].dirty, free, dirty);
ubifs_assert(lnum >= c->lpt_first && lnum <= c->lpt_last);
c->ltab[lnum - c->lpt_first].free = free;
c->ltab[lnum - c->lpt_first].dirty += dirty;
}
static int alloc_lpt_leb(struct ubifs_info *c, int *lnum)
{
int i, n;
n = *lnum - c->lpt_first + 1;
for (i = n; i < c->lpt_lebs; i++) {
if (c->ltab[i].tgc || c->ltab[i].cmt)
continue;
if (c->ltab[i].free == c->leb_size) {
c->ltab[i].cmt = 1;
*lnum = i + c->lpt_first;
return 0;
}
}
for (i = 0; i < n; i++) {
if (c->ltab[i].tgc || c->ltab[i].cmt)
continue;
if (c->ltab[i].free == c->leb_size) {
c->ltab[i].cmt = 1;
*lnum = i + c->lpt_first;
return 0;
}
}
return -ENOSPC;
}
static int layout_cnodes(struct ubifs_info *c)
{
int lnum, offs, len, alen, done_lsave, done_ltab, err;
struct ubifs_cnode *cnode;
err = dbg_chk_lpt_sz(c, 0, 0);
if (err)
return err;
cnode = c->lpt_cnext;
if (!cnode)
return 0;
lnum = c->nhead_lnum;
offs = c->nhead_offs;
done_lsave = !c->big_lpt;
done_ltab = 0;
if (!done_lsave && offs + c->lsave_sz <= c->leb_size) {
done_lsave = 1;
c->lsave_lnum = lnum;
c->lsave_offs = offs;
offs += c->lsave_sz;
dbg_chk_lpt_sz(c, 1, c->lsave_sz);
}
if (offs + c->ltab_sz <= c->leb_size) {
done_ltab = 1;
c->ltab_lnum = lnum;
c->ltab_offs = offs;
offs += c->ltab_sz;
dbg_chk_lpt_sz(c, 1, c->ltab_sz);
}
do {
if (cnode->level) {
len = c->nnode_sz;
c->dirty_nn_cnt -= 1;
} else {
len = c->pnode_sz;
c->dirty_pn_cnt -= 1;
}
while (offs + len > c->leb_size) {
alen = ALIGN(offs, c->min_io_size);
upd_ltab(c, lnum, c->leb_size - alen, alen - offs);
dbg_chk_lpt_sz(c, 2, c->leb_size - offs);
err = alloc_lpt_leb(c, &lnum);
if (err)
goto no_space;
offs = 0;
ubifs_assert(lnum >= c->lpt_first &&
lnum <= c->lpt_last);
if (!done_lsave) {
done_lsave = 1;
c->lsave_lnum = lnum;
c->lsave_offs = offs;
offs += c->lsave_sz;
dbg_chk_lpt_sz(c, 1, c->lsave_sz);
continue;
}
if (!done_ltab) {
done_ltab = 1;
c->ltab_lnum = lnum;
c->ltab_offs = offs;
offs += c->ltab_sz;
dbg_chk_lpt_sz(c, 1, c->ltab_sz);
continue;
}
break;
}
if (cnode->parent) {
cnode->parent->nbranch[cnode->iip].lnum = lnum;
cnode->parent->nbranch[cnode->iip].offs = offs;
} else {
c->lpt_lnum = lnum;
c->lpt_offs = offs;
}
offs += len;
dbg_chk_lpt_sz(c, 1, len);
cnode = cnode->cnext;
} while (cnode && cnode != c->lpt_cnext);
if (!done_lsave) {
if (offs + c->lsave_sz > c->leb_size) {
alen = ALIGN(offs, c->min_io_size);
upd_ltab(c, lnum, c->leb_size - alen, alen - offs);
dbg_chk_lpt_sz(c, 2, c->leb_size - offs);
err = alloc_lpt_leb(c, &lnum);
if (err)
goto no_space;
offs = 0;
ubifs_assert(lnum >= c->lpt_first &&
lnum <= c->lpt_last);
}
done_lsave = 1;
c->lsave_lnum = lnum;
c->lsave_offs = offs;
offs += c->lsave_sz;
dbg_chk_lpt_sz(c, 1, c->lsave_sz);
}
if (!done_ltab) {
if (offs + c->ltab_sz > c->leb_size) {
alen = ALIGN(offs, c->min_io_size);
upd_ltab(c, lnum, c->leb_size - alen, alen - offs);
dbg_chk_lpt_sz(c, 2, c->leb_size - offs);
err = alloc_lpt_leb(c, &lnum);
if (err)
goto no_space;
offs = 0;
ubifs_assert(lnum >= c->lpt_first &&
lnum <= c->lpt_last);
}
c->ltab_lnum = lnum;
c->ltab_offs = offs;
offs += c->ltab_sz;
dbg_chk_lpt_sz(c, 1, c->ltab_sz);
}
alen = ALIGN(offs, c->min_io_size);
upd_ltab(c, lnum, c->leb_size - alen, alen - offs);
dbg_chk_lpt_sz(c, 4, alen - offs);
err = dbg_chk_lpt_sz(c, 3, alen);
if (err)
return err;
return 0;
no_space:
ubifs_err("LPT out of space at LEB %d:%d needing %d, done_ltab %d, done_lsave %d",
lnum, offs, len, done_ltab, done_lsave);
ubifs_dump_lpt_info(c);
ubifs_dump_lpt_lebs(c);
dump_stack();
return err;
}
static int realloc_lpt_leb(struct ubifs_info *c, int *lnum)
{
int i, n;
n = *lnum - c->lpt_first + 1;
for (i = n; i < c->lpt_lebs; i++)
if (c->ltab[i].cmt) {
c->ltab[i].cmt = 0;
*lnum = i + c->lpt_first;
return 0;
}
for (i = 0; i < n; i++)
if (c->ltab[i].cmt) {
c->ltab[i].cmt = 0;
*lnum = i + c->lpt_first;
return 0;
}
return -ENOSPC;
}
static int write_cnodes(struct ubifs_info *c)
{
int lnum, offs, len, from, err, wlen, alen, done_ltab, done_lsave;
struct ubifs_cnode *cnode;
void *buf = c->lpt_buf;
cnode = c->lpt_cnext;
if (!cnode)
return 0;
lnum = c->nhead_lnum;
offs = c->nhead_offs;
from = offs;
if (offs == 0) {
err = ubifs_leb_unmap(c, lnum);
if (err)
return err;
}
done_lsave = !c->big_lpt;
done_ltab = 0;
if (!done_lsave && offs + c->lsave_sz <= c->leb_size) {
done_lsave = 1;
ubifs_pack_lsave(c, buf + offs, c->lsave);
offs += c->lsave_sz;
dbg_chk_lpt_sz(c, 1, c->lsave_sz);
}
if (offs + c->ltab_sz <= c->leb_size) {
done_ltab = 1;
ubifs_pack_ltab(c, buf + offs, c->ltab_cmt);
offs += c->ltab_sz;
dbg_chk_lpt_sz(c, 1, c->ltab_sz);
}
do {
if (cnode->level)
len = c->nnode_sz;
else
len = c->pnode_sz;
while (offs + len > c->leb_size) {
wlen = offs - from;
if (wlen) {
alen = ALIGN(wlen, c->min_io_size);
memset(buf + offs, 0xff, alen - wlen);
err = ubifs_leb_write(c, lnum, buf + from, from,
alen);
if (err)
return err;
}
dbg_chk_lpt_sz(c, 2, c->leb_size - offs);
err = realloc_lpt_leb(c, &lnum);
if (err)
goto no_space;
offs = from = 0;
ubifs_assert(lnum >= c->lpt_first &&
lnum <= c->lpt_last);
err = ubifs_leb_unmap(c, lnum);
if (err)
return err;
if (!done_lsave) {
done_lsave = 1;
ubifs_pack_lsave(c, buf + offs, c->lsave);
offs += c->lsave_sz;
dbg_chk_lpt_sz(c, 1, c->lsave_sz);
continue;
}
if (!done_ltab) {
done_ltab = 1;
ubifs_pack_ltab(c, buf + offs, c->ltab_cmt);
offs += c->ltab_sz;
dbg_chk_lpt_sz(c, 1, c->ltab_sz);
continue;
}
break;
}
if (cnode->level)
ubifs_pack_nnode(c, buf + offs,
(struct ubifs_nnode *)cnode);
else
ubifs_pack_pnode(c, buf + offs,
(struct ubifs_pnode *)cnode);
clear_bit(DIRTY_CNODE, &cnode->flags);
smp_mb__before_atomic();
clear_bit(COW_CNODE, &cnode->flags);
smp_mb__after_atomic();
offs += len;
dbg_chk_lpt_sz(c, 1, len);
cnode = cnode->cnext;
} while (cnode && cnode != c->lpt_cnext);
if (!done_lsave) {
if (offs + c->lsave_sz > c->leb_size) {
wlen = offs - from;
alen = ALIGN(wlen, c->min_io_size);
memset(buf + offs, 0xff, alen - wlen);
err = ubifs_leb_write(c, lnum, buf + from, from, alen);
if (err)
return err;
dbg_chk_lpt_sz(c, 2, c->leb_size - offs);
err = realloc_lpt_leb(c, &lnum);
if (err)
goto no_space;
offs = from = 0;
ubifs_assert(lnum >= c->lpt_first &&
lnum <= c->lpt_last);
err = ubifs_leb_unmap(c, lnum);
if (err)
return err;
}
done_lsave = 1;
ubifs_pack_lsave(c, buf + offs, c->lsave);
offs += c->lsave_sz;
dbg_chk_lpt_sz(c, 1, c->lsave_sz);
}
if (!done_ltab) {
if (offs + c->ltab_sz > c->leb_size) {
wlen = offs - from;
alen = ALIGN(wlen, c->min_io_size);
memset(buf + offs, 0xff, alen - wlen);
err = ubifs_leb_write(c, lnum, buf + from, from, alen);
if (err)
return err;
dbg_chk_lpt_sz(c, 2, c->leb_size - offs);
err = realloc_lpt_leb(c, &lnum);
if (err)
goto no_space;
offs = from = 0;
ubifs_assert(lnum >= c->lpt_first &&
lnum <= c->lpt_last);
err = ubifs_leb_unmap(c, lnum);
if (err)
return err;
}
ubifs_pack_ltab(c, buf + offs, c->ltab_cmt);
offs += c->ltab_sz;
dbg_chk_lpt_sz(c, 1, c->ltab_sz);
}
wlen = offs - from;
alen = ALIGN(wlen, c->min_io_size);
memset(buf + offs, 0xff, alen - wlen);
err = ubifs_leb_write(c, lnum, buf + from, from, alen);
if (err)
return err;
dbg_chk_lpt_sz(c, 4, alen - wlen);
err = dbg_chk_lpt_sz(c, 3, ALIGN(offs, c->min_io_size));
if (err)
return err;
c->nhead_lnum = lnum;
c->nhead_offs = ALIGN(offs, c->min_io_size);
dbg_lp("LPT root is at %d:%d", c->lpt_lnum, c->lpt_offs);
dbg_lp("LPT head is at %d:%d", c->nhead_lnum, c->nhead_offs);
dbg_lp("LPT ltab is at %d:%d", c->ltab_lnum, c->ltab_offs);
if (c->big_lpt)
dbg_lp("LPT lsave is at %d:%d", c->lsave_lnum, c->lsave_offs);
return 0;
no_space:
ubifs_err("LPT out of space mismatch at LEB %d:%d needing %d, done_ltab %d, done_lsave %d",
lnum, offs, len, done_ltab, done_lsave);
ubifs_dump_lpt_info(c);
ubifs_dump_lpt_lebs(c);
dump_stack();
return err;
}
static struct ubifs_pnode *next_pnode_to_dirty(struct ubifs_info *c,
struct ubifs_pnode *pnode)
{
struct ubifs_nnode *nnode;
int iip;
nnode = pnode->parent;
for (iip = pnode->iip + 1; iip < UBIFS_LPT_FANOUT; iip++) {
if (nnode->nbranch[iip].lnum)
return ubifs_get_pnode(c, nnode, iip);
}
do {
iip = nnode->iip + 1;
nnode = nnode->parent;
if (!nnode)
return NULL;
for (; iip < UBIFS_LPT_FANOUT; iip++) {
if (nnode->nbranch[iip].lnum)
break;
}
} while (iip >= UBIFS_LPT_FANOUT);
nnode = ubifs_get_nnode(c, nnode, iip);
if (IS_ERR(nnode))
return (void *)nnode;
while (nnode->level > 1) {
for (iip = 0; iip < UBIFS_LPT_FANOUT; iip++) {
if (nnode->nbranch[iip].lnum)
break;
}
if (iip >= UBIFS_LPT_FANOUT) {
iip = 0;
}
nnode = ubifs_get_nnode(c, nnode, iip);
if (IS_ERR(nnode))
return (void *)nnode;
}
for (iip = 0; iip < UBIFS_LPT_FANOUT; iip++)
if (nnode->nbranch[iip].lnum)
break;
if (iip >= UBIFS_LPT_FANOUT)
iip = 0;
return ubifs_get_pnode(c, nnode, iip);
}
static struct ubifs_pnode *pnode_lookup(struct ubifs_info *c, int i)
{
int err, h, iip, shft;
struct ubifs_nnode *nnode;
if (!c->nroot) {
err = ubifs_read_nnode(c, NULL, 0);
if (err)
return ERR_PTR(err);
}
i <<= UBIFS_LPT_FANOUT_SHIFT;
nnode = c->nroot;
shft = c->lpt_hght * UBIFS_LPT_FANOUT_SHIFT;
for (h = 1; h < c->lpt_hght; h++) {
iip = ((i >> shft) & (UBIFS_LPT_FANOUT - 1));
shft -= UBIFS_LPT_FANOUT_SHIFT;
nnode = ubifs_get_nnode(c, nnode, iip);
if (IS_ERR(nnode))
return ERR_CAST(nnode);
}
iip = ((i >> shft) & (UBIFS_LPT_FANOUT - 1));
return ubifs_get_pnode(c, nnode, iip);
}
static void add_pnode_dirt(struct ubifs_info *c, struct ubifs_pnode *pnode)
{
ubifs_add_lpt_dirt(c, pnode->parent->nbranch[pnode->iip].lnum,
c->pnode_sz);
}
static void do_make_pnode_dirty(struct ubifs_info *c, struct ubifs_pnode *pnode)
{
if (!test_and_set_bit(DIRTY_CNODE, &pnode->flags)) {
struct ubifs_nnode *nnode;
c->dirty_pn_cnt += 1;
add_pnode_dirt(c, pnode);
nnode = pnode->parent;
while (nnode) {
if (!test_and_set_bit(DIRTY_CNODE, &nnode->flags)) {
c->dirty_nn_cnt += 1;
ubifs_add_nnode_dirt(c, nnode);
nnode = nnode->parent;
} else
break;
}
}
}
static int make_tree_dirty(struct ubifs_info *c)
{
struct ubifs_pnode *pnode;
pnode = pnode_lookup(c, 0);
if (IS_ERR(pnode))
return PTR_ERR(pnode);
while (pnode) {
do_make_pnode_dirty(c, pnode);
pnode = next_pnode_to_dirty(c, pnode);
if (IS_ERR(pnode))
return PTR_ERR(pnode);
}
return 0;
}
static int need_write_all(struct ubifs_info *c)
{
long long free = 0;
int i;
for (i = 0; i < c->lpt_lebs; i++) {
if (i + c->lpt_first == c->nhead_lnum)
free += c->leb_size - c->nhead_offs;
else if (c->ltab[i].free == c->leb_size)
free += c->leb_size;
else if (c->ltab[i].free + c->ltab[i].dirty == c->leb_size)
free += c->leb_size;
}
if (free <= c->lpt_sz * 2)
return 1;
return 0;
}
static void lpt_tgc_start(struct ubifs_info *c)
{
int i;
for (i = 0; i < c->lpt_lebs; i++) {
if (i + c->lpt_first == c->nhead_lnum)
continue;
if (c->ltab[i].dirty > 0 &&
c->ltab[i].free + c->ltab[i].dirty == c->leb_size) {
c->ltab[i].tgc = 1;
c->ltab[i].free = c->leb_size;
c->ltab[i].dirty = 0;
dbg_lp("LEB %d", i + c->lpt_first);
}
}
}
static int lpt_tgc_end(struct ubifs_info *c)
{
int i, err;
for (i = 0; i < c->lpt_lebs; i++)
if (c->ltab[i].tgc) {
err = ubifs_leb_unmap(c, i + c->lpt_first);
if (err)
return err;
c->ltab[i].tgc = 0;
dbg_lp("LEB %d", i + c->lpt_first);
}
return 0;
}
static void populate_lsave(struct ubifs_info *c)
{
struct ubifs_lprops *lprops;
struct ubifs_lpt_heap *heap;
int i, cnt = 0;
ubifs_assert(c->big_lpt);
if (!(c->lpt_drty_flgs & LSAVE_DIRTY)) {
c->lpt_drty_flgs |= LSAVE_DIRTY;
ubifs_add_lpt_dirt(c, c->lsave_lnum, c->lsave_sz);
}
if (dbg_populate_lsave(c))
return;
list_for_each_entry(lprops, &c->empty_list, list) {
c->lsave[cnt++] = lprops->lnum;
if (cnt >= c->lsave_cnt)
return;
}
list_for_each_entry(lprops, &c->freeable_list, list) {
c->lsave[cnt++] = lprops->lnum;
if (cnt >= c->lsave_cnt)
return;
}
list_for_each_entry(lprops, &c->frdi_idx_list, list) {
c->lsave[cnt++] = lprops->lnum;
if (cnt >= c->lsave_cnt)
return;
}
heap = &c->lpt_heap[LPROPS_DIRTY_IDX - 1];
for (i = 0; i < heap->cnt; i++) {
c->lsave[cnt++] = heap->arr[i]->lnum;
if (cnt >= c->lsave_cnt)
return;
}
heap = &c->lpt_heap[LPROPS_DIRTY - 1];
for (i = 0; i < heap->cnt; i++) {
c->lsave[cnt++] = heap->arr[i]->lnum;
if (cnt >= c->lsave_cnt)
return;
}
heap = &c->lpt_heap[LPROPS_FREE - 1];
for (i = 0; i < heap->cnt; i++) {
c->lsave[cnt++] = heap->arr[i]->lnum;
if (cnt >= c->lsave_cnt)
return;
}
while (cnt < c->lsave_cnt)
c->lsave[cnt++] = c->main_first;
}
static struct ubifs_nnode *nnode_lookup(struct ubifs_info *c, int i)
{
int err, iip;
struct ubifs_nnode *nnode;
if (!c->nroot) {
err = ubifs_read_nnode(c, NULL, 0);
if (err)
return ERR_PTR(err);
}
nnode = c->nroot;
while (1) {
iip = i & (UBIFS_LPT_FANOUT - 1);
i >>= UBIFS_LPT_FANOUT_SHIFT;
if (!i)
break;
nnode = ubifs_get_nnode(c, nnode, iip);
if (IS_ERR(nnode))
return nnode;
}
return nnode;
}
static int make_nnode_dirty(struct ubifs_info *c, int node_num, int lnum,
int offs)
{
struct ubifs_nnode *nnode;
nnode = nnode_lookup(c, node_num);
if (IS_ERR(nnode))
return PTR_ERR(nnode);
if (nnode->parent) {
struct ubifs_nbranch *branch;
branch = &nnode->parent->nbranch[nnode->iip];
if (branch->lnum != lnum || branch->offs != offs)
return 0;
} else if (c->lpt_lnum != lnum || c->lpt_offs != offs)
return 0;
if (!test_and_set_bit(DIRTY_CNODE, &nnode->flags)) {
c->dirty_nn_cnt += 1;
ubifs_add_nnode_dirt(c, nnode);
nnode = nnode->parent;
while (nnode) {
if (!test_and_set_bit(DIRTY_CNODE, &nnode->flags)) {
c->dirty_nn_cnt += 1;
ubifs_add_nnode_dirt(c, nnode);
nnode = nnode->parent;
} else
break;
}
}
return 0;
}
static int make_pnode_dirty(struct ubifs_info *c, int node_num, int lnum,
int offs)
{
struct ubifs_pnode *pnode;
struct ubifs_nbranch *branch;
pnode = pnode_lookup(c, node_num);
if (IS_ERR(pnode))
return PTR_ERR(pnode);
branch = &pnode->parent->nbranch[pnode->iip];
if (branch->lnum != lnum || branch->offs != offs)
return 0;
do_make_pnode_dirty(c, pnode);
return 0;
}
static int make_ltab_dirty(struct ubifs_info *c, int lnum, int offs)
{
if (lnum != c->ltab_lnum || offs != c->ltab_offs)
return 0;
if (!(c->lpt_drty_flgs & LTAB_DIRTY)) {
c->lpt_drty_flgs |= LTAB_DIRTY;
ubifs_add_lpt_dirt(c, c->ltab_lnum, c->ltab_sz);
}
return 0;
}
static int make_lsave_dirty(struct ubifs_info *c, int lnum, int offs)
{
if (lnum != c->lsave_lnum || offs != c->lsave_offs)
return 0;
if (!(c->lpt_drty_flgs & LSAVE_DIRTY)) {
c->lpt_drty_flgs |= LSAVE_DIRTY;
ubifs_add_lpt_dirt(c, c->lsave_lnum, c->lsave_sz);
}
return 0;
}
static int make_node_dirty(struct ubifs_info *c, int node_type, int node_num,
int lnum, int offs)
{
switch (node_type) {
case UBIFS_LPT_NNODE:
return make_nnode_dirty(c, node_num, lnum, offs);
case UBIFS_LPT_PNODE:
return make_pnode_dirty(c, node_num, lnum, offs);
case UBIFS_LPT_LTAB:
return make_ltab_dirty(c, lnum, offs);
case UBIFS_LPT_LSAVE:
return make_lsave_dirty(c, lnum, offs);
}
return -EINVAL;
}
static int get_lpt_node_len(const struct ubifs_info *c, int node_type)
{
switch (node_type) {
case UBIFS_LPT_NNODE:
return c->nnode_sz;
case UBIFS_LPT_PNODE:
return c->pnode_sz;
case UBIFS_LPT_LTAB:
return c->ltab_sz;
case UBIFS_LPT_LSAVE:
return c->lsave_sz;
}
return 0;
}
static int get_pad_len(const struct ubifs_info *c, uint8_t *buf, int len)
{
int offs, pad_len;
if (c->min_io_size == 1)
return 0;
offs = c->leb_size - len;
pad_len = ALIGN(offs, c->min_io_size) - offs;
return pad_len;
}
static int get_lpt_node_type(const struct ubifs_info *c, uint8_t *buf,
int *node_num)
{
uint8_t *addr = buf + UBIFS_LPT_CRC_BYTES;
int pos = 0, node_type;
node_type = ubifs_unpack_bits(&addr, &pos, UBIFS_LPT_TYPE_BITS);
*node_num = ubifs_unpack_bits(&addr, &pos, c->pcnt_bits);
return node_type;
}
static int is_a_node(const struct ubifs_info *c, uint8_t *buf, int len)
{
uint8_t *addr = buf + UBIFS_LPT_CRC_BYTES;
int pos = 0, node_type, node_len;
uint16_t crc, calc_crc;
if (len < UBIFS_LPT_CRC_BYTES + (UBIFS_LPT_TYPE_BITS + 7) / 8)
return 0;
node_type = ubifs_unpack_bits(&addr, &pos, UBIFS_LPT_TYPE_BITS);
if (node_type == UBIFS_LPT_NOT_A_NODE)
return 0;
node_len = get_lpt_node_len(c, node_type);
if (!node_len || node_len > len)
return 0;
pos = 0;
addr = buf;
crc = ubifs_unpack_bits(&addr, &pos, UBIFS_LPT_CRC_BITS);
calc_crc = crc16(-1, buf + UBIFS_LPT_CRC_BYTES,
node_len - UBIFS_LPT_CRC_BYTES);
if (crc != calc_crc)
return 0;
return 1;
}
static int lpt_gc_lnum(struct ubifs_info *c, int lnum)
{
int err, len = c->leb_size, node_type, node_num, node_len, offs;
void *buf = c->lpt_buf;
dbg_lp("LEB %d", lnum);
err = ubifs_leb_read(c, lnum, buf, 0, c->leb_size, 1);
if (err)
return err;
while (1) {
if (!is_a_node(c, buf, len)) {
int pad_len;
pad_len = get_pad_len(c, buf, len);
if (pad_len) {
buf += pad_len;
len -= pad_len;
continue;
}
return 0;
}
node_type = get_lpt_node_type(c, buf, &node_num);
node_len = get_lpt_node_len(c, node_type);
offs = c->leb_size - len;
ubifs_assert(node_len != 0);
mutex_lock(&c->lp_mutex);
err = make_node_dirty(c, node_type, node_num, lnum, offs);
mutex_unlock(&c->lp_mutex);
if (err)
return err;
buf += node_len;
len -= node_len;
}
return 0;
}
static int lpt_gc(struct ubifs_info *c)
{
int i, lnum = -1, dirty = 0;
mutex_lock(&c->lp_mutex);
for (i = 0; i < c->lpt_lebs; i++) {
ubifs_assert(!c->ltab[i].tgc);
if (i + c->lpt_first == c->nhead_lnum ||
c->ltab[i].free + c->ltab[i].dirty == c->leb_size)
continue;
if (c->ltab[i].dirty > dirty) {
dirty = c->ltab[i].dirty;
lnum = i + c->lpt_first;
}
}
mutex_unlock(&c->lp_mutex);
if (lnum == -1)
return -ENOSPC;
return lpt_gc_lnum(c, lnum);
}
int ubifs_lpt_start_commit(struct ubifs_info *c)
{
int err, cnt;
dbg_lp("");
mutex_lock(&c->lp_mutex);
err = dbg_chk_lpt_free_spc(c);
if (err)
goto out;
err = dbg_check_ltab(c);
if (err)
goto out;
if (c->check_lpt_free) {
c->check_lpt_free = 0;
while (need_write_all(c)) {
mutex_unlock(&c->lp_mutex);
err = lpt_gc(c);
if (err)
return err;
mutex_lock(&c->lp_mutex);
}
}
lpt_tgc_start(c);
if (!c->dirty_pn_cnt) {
dbg_cmt("no cnodes to commit");
err = 0;
goto out;
}
if (!c->big_lpt && need_write_all(c)) {
err = make_tree_dirty(c);
if (err)
goto out;
lpt_tgc_start(c);
}
if (c->big_lpt)
populate_lsave(c);
cnt = get_cnodes_to_commit(c);
ubifs_assert(cnt != 0);
err = layout_cnodes(c);
if (err)
goto out;
memcpy(c->ltab_cmt, c->ltab,
sizeof(struct ubifs_lpt_lprops) * c->lpt_lebs);
c->lpt_drty_flgs &= ~(LTAB_DIRTY | LSAVE_DIRTY);
out:
mutex_unlock(&c->lp_mutex);
return err;
}
static void free_obsolete_cnodes(struct ubifs_info *c)
{
struct ubifs_cnode *cnode, *cnext;
cnext = c->lpt_cnext;
if (!cnext)
return;
do {
cnode = cnext;
cnext = cnode->cnext;
if (test_bit(OBSOLETE_CNODE, &cnode->flags))
kfree(cnode);
else
cnode->cnext = NULL;
} while (cnext != c->lpt_cnext);
c->lpt_cnext = NULL;
}
int ubifs_lpt_end_commit(struct ubifs_info *c)
{
int err;
dbg_lp("");
if (!c->lpt_cnext)
return 0;
err = write_cnodes(c);
if (err)
return err;
mutex_lock(&c->lp_mutex);
free_obsolete_cnodes(c);
mutex_unlock(&c->lp_mutex);
return 0;
}
int ubifs_lpt_post_commit(struct ubifs_info *c)
{
int err;
mutex_lock(&c->lp_mutex);
err = lpt_tgc_end(c);
if (err)
goto out;
if (c->big_lpt)
while (need_write_all(c)) {
mutex_unlock(&c->lp_mutex);
err = lpt_gc(c);
if (err)
return err;
mutex_lock(&c->lp_mutex);
}
out:
mutex_unlock(&c->lp_mutex);
return err;
}
static struct ubifs_nnode *first_nnode(struct ubifs_info *c, int *hght)
{
struct ubifs_nnode *nnode;
int h, i, found;
nnode = c->nroot;
*hght = 0;
if (!nnode)
return NULL;
for (h = 1; h < c->lpt_hght; h++) {
found = 0;
for (i = 0; i < UBIFS_LPT_FANOUT; i++) {
if (nnode->nbranch[i].nnode) {
found = 1;
nnode = nnode->nbranch[i].nnode;
*hght = h;
break;
}
}
if (!found)
break;
}
return nnode;
}
static struct ubifs_nnode *next_nnode(struct ubifs_info *c,
struct ubifs_nnode *nnode, int *hght)
{
struct ubifs_nnode *parent;
int iip, h, i, found;
parent = nnode->parent;
if (!parent)
return NULL;
if (nnode->iip == UBIFS_LPT_FANOUT - 1) {
*hght -= 1;
return parent;
}
for (iip = nnode->iip + 1; iip < UBIFS_LPT_FANOUT; iip++) {
nnode = parent->nbranch[iip].nnode;
if (nnode)
break;
}
if (!nnode) {
*hght -= 1;
return parent;
}
for (h = *hght + 1; h < c->lpt_hght; h++) {
found = 0;
for (i = 0; i < UBIFS_LPT_FANOUT; i++) {
if (nnode->nbranch[i].nnode) {
found = 1;
nnode = nnode->nbranch[i].nnode;
*hght = h;
break;
}
}
if (!found)
break;
}
return nnode;
}
void ubifs_lpt_free(struct ubifs_info *c, int wr_only)
{
struct ubifs_nnode *nnode;
int i, hght;
free_obsolete_cnodes(c);
vfree(c->ltab_cmt);
c->ltab_cmt = NULL;
vfree(c->lpt_buf);
c->lpt_buf = NULL;
kfree(c->lsave);
c->lsave = NULL;
if (wr_only)
return;
nnode = first_nnode(c, &hght);
while (nnode) {
for (i = 0; i < UBIFS_LPT_FANOUT; i++)
kfree(nnode->nbranch[i].nnode);
nnode = next_nnode(c, nnode, &hght);
}
for (i = 0; i < LPROPS_HEAP_CNT; i++)
kfree(c->lpt_heap[i].arr);
kfree(c->dirty_idx.arr);
kfree(c->nroot);
vfree(c->ltab);
kfree(c->lpt_nod_buf);
}
static int dbg_is_all_ff(uint8_t *buf, int len)
{
int i;
for (i = 0; i < len; i++)
if (buf[i] != 0xff)
return 0;
return 1;
}
static int dbg_is_nnode_dirty(struct ubifs_info *c, int lnum, int offs)
{
struct ubifs_nnode *nnode;
int hght;
nnode = first_nnode(c, &hght);
for (; nnode; nnode = next_nnode(c, nnode, &hght)) {
struct ubifs_nbranch *branch;
cond_resched();
if (nnode->parent) {
branch = &nnode->parent->nbranch[nnode->iip];
if (branch->lnum != lnum || branch->offs != offs)
continue;
if (test_bit(DIRTY_CNODE, &nnode->flags))
return 1;
return 0;
} else {
if (c->lpt_lnum != lnum || c->lpt_offs != offs)
continue;
if (test_bit(DIRTY_CNODE, &nnode->flags))
return 1;
return 0;
}
}
return 1;
}
static int dbg_is_pnode_dirty(struct ubifs_info *c, int lnum, int offs)
{
int i, cnt;
cnt = DIV_ROUND_UP(c->main_lebs, UBIFS_LPT_FANOUT);
for (i = 0; i < cnt; i++) {
struct ubifs_pnode *pnode;
struct ubifs_nbranch *branch;
cond_resched();
pnode = pnode_lookup(c, i);
if (IS_ERR(pnode))
return PTR_ERR(pnode);
branch = &pnode->parent->nbranch[pnode->iip];
if (branch->lnum != lnum || branch->offs != offs)
continue;
if (test_bit(DIRTY_CNODE, &pnode->flags))
return 1;
return 0;
}
return 1;
}
static int dbg_is_ltab_dirty(struct ubifs_info *c, int lnum, int offs)
{
if (lnum != c->ltab_lnum || offs != c->ltab_offs)
return 1;
return (c->lpt_drty_flgs & LTAB_DIRTY) != 0;
}
static int dbg_is_lsave_dirty(struct ubifs_info *c, int lnum, int offs)
{
if (lnum != c->lsave_lnum || offs != c->lsave_offs)
return 1;
return (c->lpt_drty_flgs & LSAVE_DIRTY) != 0;
}
static int dbg_is_node_dirty(struct ubifs_info *c, int node_type, int lnum,
int offs)
{
switch (node_type) {
case UBIFS_LPT_NNODE:
return dbg_is_nnode_dirty(c, lnum, offs);
case UBIFS_LPT_PNODE:
return dbg_is_pnode_dirty(c, lnum, offs);
case UBIFS_LPT_LTAB:
return dbg_is_ltab_dirty(c, lnum, offs);
case UBIFS_LPT_LSAVE:
return dbg_is_lsave_dirty(c, lnum, offs);
}
return 1;
}
static int dbg_check_ltab_lnum(struct ubifs_info *c, int lnum)
{
int err, len = c->leb_size, dirty = 0, node_type, node_num, node_len;
int ret;
void *buf, *p;
if (!dbg_is_chk_lprops(c))
return 0;
buf = p = __vmalloc(c->leb_size, GFP_NOFS, PAGE_KERNEL);
if (!buf) {
ubifs_err("cannot allocate memory for ltab checking");
return 0;
}
dbg_lp("LEB %d", lnum);
err = ubifs_leb_read(c, lnum, buf, 0, c->leb_size, 1);
if (err)
goto out;
while (1) {
if (!is_a_node(c, p, len)) {
int i, pad_len;
pad_len = get_pad_len(c, p, len);
if (pad_len) {
p += pad_len;
len -= pad_len;
dirty += pad_len;
continue;
}
if (!dbg_is_all_ff(p, len)) {
ubifs_err("invalid empty space in LEB %d at %d",
lnum, c->leb_size - len);
err = -EINVAL;
}
i = lnum - c->lpt_first;
if (len != c->ltab[i].free) {
ubifs_err("invalid free space in LEB %d (free %d, expected %d)",
lnum, len, c->ltab[i].free);
err = -EINVAL;
}
if (dirty != c->ltab[i].dirty) {
ubifs_err("invalid dirty space in LEB %d (dirty %d, expected %d)",
lnum, dirty, c->ltab[i].dirty);
err = -EINVAL;
}
goto out;
}
node_type = get_lpt_node_type(c, p, &node_num);
node_len = get_lpt_node_len(c, node_type);
ret = dbg_is_node_dirty(c, node_type, lnum, c->leb_size - len);
if (ret == 1)
dirty += node_len;
p += node_len;
len -= node_len;
}
err = 0;
out:
vfree(buf);
return err;
}
int dbg_check_ltab(struct ubifs_info *c)
{
int lnum, err, i, cnt;
if (!dbg_is_chk_lprops(c))
return 0;
cnt = DIV_ROUND_UP(c->main_lebs, UBIFS_LPT_FANOUT);
for (i = 0; i < cnt; i++) {
struct ubifs_pnode *pnode;
pnode = pnode_lookup(c, i);
if (IS_ERR(pnode))
return PTR_ERR(pnode);
cond_resched();
}
err = dbg_check_lpt_nodes(c, (struct ubifs_cnode *)c->nroot, 0, 0);
if (err)
return err;
for (lnum = c->lpt_first; lnum <= c->lpt_last; lnum++) {
err = dbg_check_ltab_lnum(c, lnum);
if (err) {
ubifs_err("failed at LEB %d", lnum);
return err;
}
}
dbg_lp("succeeded");
return 0;
}
int dbg_chk_lpt_free_spc(struct ubifs_info *c)
{
long long free = 0;
int i;
if (!dbg_is_chk_lprops(c))
return 0;
for (i = 0; i < c->lpt_lebs; i++) {
if (c->ltab[i].tgc || c->ltab[i].cmt)
continue;
if (i + c->lpt_first == c->nhead_lnum)
free += c->leb_size - c->nhead_offs;
else if (c->ltab[i].free == c->leb_size)
free += c->leb_size;
}
if (free < c->lpt_sz) {
ubifs_err("LPT space error: free %lld lpt_sz %lld",
free, c->lpt_sz);
ubifs_dump_lpt_info(c);
ubifs_dump_lpt_lebs(c);
dump_stack();
return -EINVAL;
}
return 0;
}
int dbg_chk_lpt_sz(struct ubifs_info *c, int action, int len)
{
struct ubifs_debug_info *d = c->dbg;
long long chk_lpt_sz, lpt_sz;
int err = 0;
if (!dbg_is_chk_lprops(c))
return 0;
switch (action) {
case 0:
d->chk_lpt_sz = 0;
d->chk_lpt_sz2 = 0;
d->chk_lpt_lebs = 0;
d->chk_lpt_wastage = 0;
if (c->dirty_pn_cnt > c->pnode_cnt) {
ubifs_err("dirty pnodes %d exceed max %d",
c->dirty_pn_cnt, c->pnode_cnt);
err = -EINVAL;
}
if (c->dirty_nn_cnt > c->nnode_cnt) {
ubifs_err("dirty nnodes %d exceed max %d",
c->dirty_nn_cnt, c->nnode_cnt);
err = -EINVAL;
}
return err;
case 1:
d->chk_lpt_sz += len;
return 0;
case 2:
d->chk_lpt_sz += len;
d->chk_lpt_wastage += len;
d->chk_lpt_lebs += 1;
return 0;
case 3:
chk_lpt_sz = c->leb_size;
chk_lpt_sz *= d->chk_lpt_lebs;
chk_lpt_sz += len - c->nhead_offs;
if (d->chk_lpt_sz != chk_lpt_sz) {
ubifs_err("LPT wrote %lld but space used was %lld",
d->chk_lpt_sz, chk_lpt_sz);
err = -EINVAL;
}
if (d->chk_lpt_sz > c->lpt_sz) {
ubifs_err("LPT wrote %lld but lpt_sz is %lld",
d->chk_lpt_sz, c->lpt_sz);
err = -EINVAL;
}
if (d->chk_lpt_sz2 && d->chk_lpt_sz != d->chk_lpt_sz2) {
ubifs_err("LPT layout size %lld but wrote %lld",
d->chk_lpt_sz, d->chk_lpt_sz2);
err = -EINVAL;
}
if (d->chk_lpt_sz2 && d->new_nhead_offs != len) {
ubifs_err("LPT new nhead offs: expected %d was %d",
d->new_nhead_offs, len);
err = -EINVAL;
}
lpt_sz = (long long)c->pnode_cnt * c->pnode_sz;
lpt_sz += (long long)c->nnode_cnt * c->nnode_sz;
lpt_sz += c->ltab_sz;
if (c->big_lpt)
lpt_sz += c->lsave_sz;
if (d->chk_lpt_sz - d->chk_lpt_wastage > lpt_sz) {
ubifs_err("LPT chk_lpt_sz %lld + waste %lld exceeds %lld",
d->chk_lpt_sz, d->chk_lpt_wastage, lpt_sz);
err = -EINVAL;
}
if (err) {
ubifs_dump_lpt_info(c);
ubifs_dump_lpt_lebs(c);
dump_stack();
}
d->chk_lpt_sz2 = d->chk_lpt_sz;
d->chk_lpt_sz = 0;
d->chk_lpt_wastage = 0;
d->chk_lpt_lebs = 0;
d->new_nhead_offs = len;
return err;
case 4:
d->chk_lpt_sz += len;
d->chk_lpt_wastage += len;
return 0;
default:
return -EINVAL;
}
}
static void dump_lpt_leb(const struct ubifs_info *c, int lnum)
{
int err, len = c->leb_size, node_type, node_num, node_len, offs;
void *buf, *p;
pr_err("(pid %d) start dumping LEB %d\n", current->pid, lnum);
buf = p = __vmalloc(c->leb_size, GFP_NOFS, PAGE_KERNEL);
if (!buf) {
ubifs_err("cannot allocate memory to dump LPT");
return;
}
err = ubifs_leb_read(c, lnum, buf, 0, c->leb_size, 1);
if (err)
goto out;
while (1) {
offs = c->leb_size - len;
if (!is_a_node(c, p, len)) {
int pad_len;
pad_len = get_pad_len(c, p, len);
if (pad_len) {
pr_err("LEB %d:%d, pad %d bytes\n",
lnum, offs, pad_len);
p += pad_len;
len -= pad_len;
continue;
}
if (len)
pr_err("LEB %d:%d, free %d bytes\n",
lnum, offs, len);
break;
}
node_type = get_lpt_node_type(c, p, &node_num);
switch (node_type) {
case UBIFS_LPT_PNODE:
{
node_len = c->pnode_sz;
if (c->big_lpt)
pr_err("LEB %d:%d, pnode num %d\n",
lnum, offs, node_num);
else
pr_err("LEB %d:%d, pnode\n", lnum, offs);
break;
}
case UBIFS_LPT_NNODE:
{
int i;
struct ubifs_nnode nnode;
node_len = c->nnode_sz;
if (c->big_lpt)
pr_err("LEB %d:%d, nnode num %d, ",
lnum, offs, node_num);
else
pr_err("LEB %d:%d, nnode, ",
lnum, offs);
err = ubifs_unpack_nnode(c, p, &nnode);
if (err) {
pr_err("failed to unpack_node, error %d\n",
err);
break;
}
for (i = 0; i < UBIFS_LPT_FANOUT; i++) {
pr_cont("%d:%d", nnode.nbranch[i].lnum,
nnode.nbranch[i].offs);
if (i != UBIFS_LPT_FANOUT - 1)
pr_cont(", ");
}
pr_cont("\n");
break;
}
case UBIFS_LPT_LTAB:
node_len = c->ltab_sz;
pr_err("LEB %d:%d, ltab\n", lnum, offs);
break;
case UBIFS_LPT_LSAVE:
node_len = c->lsave_sz;
pr_err("LEB %d:%d, lsave len\n", lnum, offs);
break;
default:
ubifs_err("LPT node type %d not recognized", node_type);
goto out;
}
p += node_len;
len -= node_len;
}
pr_err("(pid %d) finish dumping LEB %d\n", current->pid, lnum);
out:
vfree(buf);
return;
}
void ubifs_dump_lpt_lebs(const struct ubifs_info *c)
{
int i;
pr_err("(pid %d) start dumping all LPT LEBs\n", current->pid);
for (i = 0; i < c->lpt_lebs; i++)
dump_lpt_leb(c, i + c->lpt_first);
pr_err("(pid %d) finish dumping all LPT LEBs\n", current->pid);
}
static int dbg_populate_lsave(struct ubifs_info *c)
{
struct ubifs_lprops *lprops;
struct ubifs_lpt_heap *heap;
int i;
if (!dbg_is_chk_gen(c))
return 0;
if (prandom_u32() & 3)
return 0;
for (i = 0; i < c->lsave_cnt; i++)
c->lsave[i] = c->main_first;
list_for_each_entry(lprops, &c->empty_list, list)
c->lsave[prandom_u32() % c->lsave_cnt] = lprops->lnum;
list_for_each_entry(lprops, &c->freeable_list, list)
c->lsave[prandom_u32() % c->lsave_cnt] = lprops->lnum;
list_for_each_entry(lprops, &c->frdi_idx_list, list)
c->lsave[prandom_u32() % c->lsave_cnt] = lprops->lnum;
heap = &c->lpt_heap[LPROPS_DIRTY_IDX - 1];
for (i = 0; i < heap->cnt; i++)
c->lsave[prandom_u32() % c->lsave_cnt] = heap->arr[i]->lnum;
heap = &c->lpt_heap[LPROPS_DIRTY - 1];
for (i = 0; i < heap->cnt; i++)
c->lsave[prandom_u32() % c->lsave_cnt] = heap->arr[i]->lnum;
heap = &c->lpt_heap[LPROPS_FREE - 1];
for (i = 0; i < heap->cnt; i++)
c->lsave[prandom_u32() % c->lsave_cnt] = heap->arr[i]->lnum;
return 1;
}
