struct xfs_bud_log_item *
xfs_trans_get_bud(
struct xfs_trans *tp,
struct xfs_bui_log_item *buip)
{
struct xfs_bud_log_item *budp;
budp = xfs_bud_init(tp->t_mountp, buip);
xfs_trans_add_item(tp, &budp->bud_item);
return budp;
}
int
xfs_trans_log_finish_bmap_update(
struct xfs_trans *tp,
struct xfs_bud_log_item *budp,
struct xfs_defer_ops *dop,
enum xfs_bmap_intent_type type,
struct xfs_inode *ip,
int whichfork,
xfs_fileoff_t startoff,
xfs_fsblock_t startblock,
xfs_filblks_t *blockcount,
xfs_exntst_t state)
{
int error;
error = xfs_bmap_finish_one(tp, dop, ip, type, whichfork, startoff,
startblock, blockcount, state);
tp->t_flags |= XFS_TRANS_DIRTY;
budp->bud_item.li_desc->lid_flags |= XFS_LID_DIRTY;
return error;
}
static int
xfs_bmap_update_diff_items(
void *priv,
struct list_head *a,
struct list_head *b)
{
struct xfs_bmap_intent *ba;
struct xfs_bmap_intent *bb;
ba = container_of(a, struct xfs_bmap_intent, bi_list);
bb = container_of(b, struct xfs_bmap_intent, bi_list);
return ba->bi_owner->i_ino - bb->bi_owner->i_ino;
}
STATIC void *
xfs_bmap_update_create_intent(
struct xfs_trans *tp,
unsigned int count)
{
struct xfs_bui_log_item *buip;
ASSERT(count == XFS_BUI_MAX_FAST_EXTENTS);
ASSERT(tp != NULL);
buip = xfs_bui_init(tp->t_mountp);
ASSERT(buip != NULL);
xfs_trans_add_item(tp, &buip->bui_item);
return buip;
}
static void
xfs_trans_set_bmap_flags(
struct xfs_map_extent *bmap,
enum xfs_bmap_intent_type type,
int whichfork,
xfs_exntst_t state)
{
bmap->me_flags = 0;
switch (type) {
case XFS_BMAP_MAP:
case XFS_BMAP_UNMAP:
bmap->me_flags = type;
break;
default:
ASSERT(0);
}
if (state == XFS_EXT_UNWRITTEN)
bmap->me_flags |= XFS_BMAP_EXTENT_UNWRITTEN;
if (whichfork == XFS_ATTR_FORK)
bmap->me_flags |= XFS_BMAP_EXTENT_ATTR_FORK;
}
STATIC void
xfs_bmap_update_log_item(
struct xfs_trans *tp,
void *intent,
struct list_head *item)
{
struct xfs_bui_log_item *buip = intent;
struct xfs_bmap_intent *bmap;
uint next_extent;
struct xfs_map_extent *map;
bmap = container_of(item, struct xfs_bmap_intent, bi_list);
tp->t_flags |= XFS_TRANS_DIRTY;
buip->bui_item.li_desc->lid_flags |= XFS_LID_DIRTY;
next_extent = atomic_inc_return(&buip->bui_next_extent) - 1;
ASSERT(next_extent < buip->bui_format.bui_nextents);
map = &buip->bui_format.bui_extents[next_extent];
map->me_owner = bmap->bi_owner->i_ino;
map->me_startblock = bmap->bi_bmap.br_startblock;
map->me_startoff = bmap->bi_bmap.br_startoff;
map->me_len = bmap->bi_bmap.br_blockcount;
xfs_trans_set_bmap_flags(map, bmap->bi_type, bmap->bi_whichfork,
bmap->bi_bmap.br_state);
}
STATIC void *
xfs_bmap_update_create_done(
struct xfs_trans *tp,
void *intent,
unsigned int count)
{
return xfs_trans_get_bud(tp, intent);
}
STATIC int
xfs_bmap_update_finish_item(
struct xfs_trans *tp,
struct xfs_defer_ops *dop,
struct list_head *item,
void *done_item,
void **state)
{
struct xfs_bmap_intent *bmap;
xfs_filblks_t count;
int error;
bmap = container_of(item, struct xfs_bmap_intent, bi_list);
count = bmap->bi_bmap.br_blockcount;
error = xfs_trans_log_finish_bmap_update(tp, done_item, dop,
bmap->bi_type,
bmap->bi_owner, bmap->bi_whichfork,
bmap->bi_bmap.br_startoff,
bmap->bi_bmap.br_startblock,
&count,
bmap->bi_bmap.br_state);
if (!error && count > 0) {
ASSERT(bmap->bi_type == XFS_BMAP_UNMAP);
bmap->bi_bmap.br_blockcount = count;
return -EAGAIN;
}
kmem_free(bmap);
return error;
}
STATIC void
xfs_bmap_update_abort_intent(
void *intent)
{
xfs_bui_release(intent);
}
STATIC void
xfs_bmap_update_cancel_item(
struct list_head *item)
{
struct xfs_bmap_intent *bmap;
bmap = container_of(item, struct xfs_bmap_intent, bi_list);
kmem_free(bmap);
}
void
xfs_bmap_update_init_defer_op(void)
{
xfs_defer_init_op_type(&xfs_bmap_update_defer_type);
}
