void
xfs_extent_busy_insert(
struct xfs_trans *tp,
xfs_agnumber_t agno,
xfs_agblock_t bno,
xfs_extlen_t len,
unsigned int flags)
{
struct xfs_extent_busy *new;
struct xfs_extent_busy *busyp;
struct xfs_perag *pag;
struct rb_node **rbp;
struct rb_node *parent = NULL;
new = kmem_zalloc(sizeof(struct xfs_extent_busy), KM_MAYFAIL);
if (!new) {
trace_xfs_extent_busy_enomem(tp->t_mountp, agno, bno, len);
xfs_trans_set_sync(tp);
return;
}
new->agno = agno;
new->bno = bno;
new->length = len;
INIT_LIST_HEAD(&new->list);
new->flags = flags;
trace_xfs_extent_busy(tp->t_mountp, agno, bno, len);
pag = xfs_perag_get(tp->t_mountp, new->agno);
spin_lock(&pag->pagb_lock);
rbp = &pag->pagb_tree.rb_node;
while (*rbp) {
parent = *rbp;
busyp = rb_entry(parent, struct xfs_extent_busy, rb_node);
if (new->bno < busyp->bno) {
rbp = &(*rbp)->rb_left;
ASSERT(new->bno + new->length <= busyp->bno);
} else if (new->bno > busyp->bno) {
rbp = &(*rbp)->rb_right;
ASSERT(bno >= busyp->bno + busyp->length);
} else {
ASSERT(0);
}
}
rb_link_node(&new->rb_node, parent, rbp);
rb_insert_color(&new->rb_node, &pag->pagb_tree);
list_add(&new->list, &tp->t_busy);
spin_unlock(&pag->pagb_lock);
xfs_perag_put(pag);
}
int
xfs_extent_busy_search(
struct xfs_mount *mp,
xfs_agnumber_t agno,
xfs_agblock_t bno,
xfs_extlen_t len)
{
struct xfs_perag *pag;
struct rb_node *rbp;
struct xfs_extent_busy *busyp;
int match = 0;
pag = xfs_perag_get(mp, agno);
spin_lock(&pag->pagb_lock);
rbp = pag->pagb_tree.rb_node;
while (rbp) {
busyp = rb_entry(rbp, struct xfs_extent_busy, rb_node);
if (bno < busyp->bno) {
if (bno + len > busyp->bno)
match = -1;
rbp = rbp->rb_left;
} else if (bno > busyp->bno) {
if (bno < busyp->bno + busyp->length)
match = -1;
rbp = rbp->rb_right;
} else {
match = (busyp->length == len) ? 1 : -1;
break;
}
}
spin_unlock(&pag->pagb_lock);
xfs_perag_put(pag);
return match;
}
STATIC bool
xfs_extent_busy_update_extent(
struct xfs_mount *mp,
struct xfs_perag *pag,
struct xfs_extent_busy *busyp,
xfs_agblock_t fbno,
xfs_extlen_t flen,
bool userdata) __releases(&pag->pagb_lock
void
xfs_extent_busy_reuse(
struct xfs_mount *mp,
xfs_agnumber_t agno,
xfs_agblock_t fbno,
xfs_extlen_t flen,
bool userdata)
{
struct xfs_perag *pag;
struct rb_node *rbp;
ASSERT(flen > 0);
pag = xfs_perag_get(mp, agno);
spin_lock(&pag->pagb_lock);
restart:
rbp = pag->pagb_tree.rb_node;
while (rbp) {
struct xfs_extent_busy *busyp =
rb_entry(rbp, struct xfs_extent_busy, rb_node);
xfs_agblock_t bbno = busyp->bno;
xfs_agblock_t bend = bbno + busyp->length;
if (fbno + flen <= bbno) {
rbp = rbp->rb_left;
continue;
} else if (fbno >= bend) {
rbp = rbp->rb_right;
continue;
}
if (!xfs_extent_busy_update_extent(mp, pag, busyp, fbno, flen,
userdata))
goto restart;
}
spin_unlock(&pag->pagb_lock);
xfs_perag_put(pag);
}
void
xfs_extent_busy_trim(
struct xfs_alloc_arg *args,
xfs_agblock_t bno,
xfs_extlen_t len,
xfs_agblock_t *rbno,
xfs_extlen_t *rlen)
{
xfs_agblock_t fbno;
xfs_extlen_t flen;
struct rb_node *rbp;
ASSERT(len > 0);
spin_lock(&args->pag->pagb_lock);
restart:
fbno = bno;
flen = len;
rbp = args->pag->pagb_tree.rb_node;
while (rbp && flen >= args->minlen) {
struct xfs_extent_busy *busyp =
rb_entry(rbp, struct xfs_extent_busy, rb_node);
xfs_agblock_t fend = fbno + flen;
xfs_agblock_t bbno = busyp->bno;
xfs_agblock_t bend = bbno + busyp->length;
if (fend <= bbno) {
rbp = rbp->rb_left;
continue;
} else if (fbno >= bend) {
rbp = rbp->rb_right;
continue;
}
if (!xfs_alloc_is_userdata(args->datatype) &&
!(busyp->flags & XFS_EXTENT_BUSY_DISCARDED)) {
if (!xfs_extent_busy_update_extent(args->mp, args->pag,
busyp, fbno, flen,
false))
goto restart;
continue;
}
if (bbno <= fbno) {
if (fend <= bend)
goto fail;
fbno = bend;
} else if (bend >= fend) {
fend = bbno;
} else {
if (bbno - fbno >= args->maxlen) {
fend = bbno;
} else if (fend - bend >= args->maxlen * 4) {
fbno = bend;
} else if (bbno - fbno >= args->minlen) {
fend = bbno;
} else {
goto fail;
}
}
flen = fend - fbno;
}
spin_unlock(&args->pag->pagb_lock);
if (fbno != bno || flen != len) {
trace_xfs_extent_busy_trim(args->mp, args->agno, bno, len,
fbno, flen);
}
*rbno = fbno;
*rlen = flen;
return;
fail:
spin_unlock(&args->pag->pagb_lock);
trace_xfs_extent_busy_trim(args->mp, args->agno, bno, len, fbno, 0);
*rbno = fbno;
*rlen = 0;
}
STATIC void
xfs_extent_busy_clear_one(
struct xfs_mount *mp,
struct xfs_perag *pag,
struct xfs_extent_busy *busyp)
{
if (busyp->length) {
trace_xfs_extent_busy_clear(mp, busyp->agno, busyp->bno,
busyp->length);
rb_erase(&busyp->rb_node, &pag->pagb_tree);
}
list_del_init(&busyp->list);
kmem_free(busyp);
}
void
xfs_extent_busy_clear(
struct xfs_mount *mp,
struct list_head *list,
bool do_discard)
{
struct xfs_extent_busy *busyp, *n;
struct xfs_perag *pag = NULL;
xfs_agnumber_t agno = NULLAGNUMBER;
list_for_each_entry_safe(busyp, n, list, list) {
if (busyp->agno != agno) {
if (pag) {
spin_unlock(&pag->pagb_lock);
xfs_perag_put(pag);
}
pag = xfs_perag_get(mp, busyp->agno);
spin_lock(&pag->pagb_lock);
agno = busyp->agno;
}
if (do_discard && busyp->length &&
!(busyp->flags & XFS_EXTENT_BUSY_SKIP_DISCARD))
busyp->flags = XFS_EXTENT_BUSY_DISCARDED;
else
xfs_extent_busy_clear_one(mp, pag, busyp);
}
if (pag) {
spin_unlock(&pag->pagb_lock);
xfs_perag_put(pag);
}
}
int
xfs_extent_busy_ag_cmp(
void *priv,
struct list_head *a,
struct list_head *b)
{
return container_of(a, struct xfs_extent_busy, list)->agno -
container_of(b, struct xfs_extent_busy, list)->agno;
}
