static void
xfs_trans_set_rmap_flags(
struct xfs_map_extent *rmap,
enum xfs_rmap_intent_type type,
int whichfork,
xfs_exntst_t state)
{
rmap->me_flags = 0;
if (state == XFS_EXT_UNWRITTEN)
rmap->me_flags |= XFS_RMAP_EXTENT_UNWRITTEN;
if (whichfork == XFS_ATTR_FORK)
rmap->me_flags |= XFS_RMAP_EXTENT_ATTR_FORK;
switch (type) {
case XFS_RMAP_MAP:
rmap->me_flags |= XFS_RMAP_EXTENT_MAP;
break;
case XFS_RMAP_UNMAP:
rmap->me_flags |= XFS_RMAP_EXTENT_UNMAP;
break;
case XFS_RMAP_CONVERT:
rmap->me_flags |= XFS_RMAP_EXTENT_CONVERT;
break;
case XFS_RMAP_ALLOC:
rmap->me_flags |= XFS_RMAP_EXTENT_ALLOC;
break;
case XFS_RMAP_FREE:
rmap->me_flags |= XFS_RMAP_EXTENT_FREE;
break;
default:
ASSERT(0);
}
}
struct xfs_rud_log_item *
xfs_trans_get_rud(
struct xfs_trans *tp,
struct xfs_rui_log_item *ruip)
{
struct xfs_rud_log_item *rudp;
rudp = xfs_rud_init(tp->t_mountp, ruip);
xfs_trans_add_item(tp, &rudp->rud_item);
return rudp;
}
int
xfs_trans_log_finish_rmap_update(
struct xfs_trans *tp,
struct xfs_rud_log_item *rudp,
enum xfs_rmap_intent_type type,
__uint64_t owner,
int whichfork,
xfs_fileoff_t startoff,
xfs_fsblock_t startblock,
xfs_filblks_t blockcount,
xfs_exntst_t state,
struct xfs_btree_cur **pcur)
{
int error;
error = xfs_rmap_finish_one(tp, type, owner, whichfork, startoff,
startblock, blockcount, state, pcur);
tp->t_flags |= XFS_TRANS_DIRTY;
rudp->rud_item.li_desc->lid_flags |= XFS_LID_DIRTY;
return error;
}
static int
xfs_rmap_update_diff_items(
void *priv,
struct list_head *a,
struct list_head *b)
{
struct xfs_mount *mp = priv;
struct xfs_rmap_intent *ra;
struct xfs_rmap_intent *rb;
ra = container_of(a, struct xfs_rmap_intent, ri_list);
rb = container_of(b, struct xfs_rmap_intent, ri_list);
return XFS_FSB_TO_AGNO(mp, ra->ri_bmap.br_startblock) -
XFS_FSB_TO_AGNO(mp, rb->ri_bmap.br_startblock);
}
STATIC void *
xfs_rmap_update_create_intent(
struct xfs_trans *tp,
unsigned int count)
{
struct xfs_rui_log_item *ruip;
ASSERT(tp != NULL);
ASSERT(count > 0);
ruip = xfs_rui_init(tp->t_mountp, count);
ASSERT(ruip != NULL);
xfs_trans_add_item(tp, &ruip->rui_item);
return ruip;
}
STATIC void
xfs_rmap_update_log_item(
struct xfs_trans *tp,
void *intent,
struct list_head *item)
{
struct xfs_rui_log_item *ruip = intent;
struct xfs_rmap_intent *rmap;
uint next_extent;
struct xfs_map_extent *map;
rmap = container_of(item, struct xfs_rmap_intent, ri_list);
tp->t_flags |= XFS_TRANS_DIRTY;
ruip->rui_item.li_desc->lid_flags |= XFS_LID_DIRTY;
next_extent = atomic_inc_return(&ruip->rui_next_extent) - 1;
ASSERT(next_extent < ruip->rui_format.rui_nextents);
map = &ruip->rui_format.rui_extents[next_extent];
map->me_owner = rmap->ri_owner;
map->me_startblock = rmap->ri_bmap.br_startblock;
map->me_startoff = rmap->ri_bmap.br_startoff;
map->me_len = rmap->ri_bmap.br_blockcount;
xfs_trans_set_rmap_flags(map, rmap->ri_type, rmap->ri_whichfork,
rmap->ri_bmap.br_state);
}
STATIC void *
xfs_rmap_update_create_done(
struct xfs_trans *tp,
void *intent,
unsigned int count)
{
return xfs_trans_get_rud(tp, intent);
}
STATIC int
xfs_rmap_update_finish_item(
struct xfs_trans *tp,
struct xfs_defer_ops *dop,
struct list_head *item,
void *done_item,
void **state)
{
struct xfs_rmap_intent *rmap;
int error;
rmap = container_of(item, struct xfs_rmap_intent, ri_list);
error = xfs_trans_log_finish_rmap_update(tp, done_item,
rmap->ri_type,
rmap->ri_owner, rmap->ri_whichfork,
rmap->ri_bmap.br_startoff,
rmap->ri_bmap.br_startblock,
rmap->ri_bmap.br_blockcount,
rmap->ri_bmap.br_state,
(struct xfs_btree_cur **)state);
kmem_free(rmap);
return error;
}
STATIC void
xfs_rmap_update_finish_cleanup(
struct xfs_trans *tp,
void *state,
int error)
{
struct xfs_btree_cur *rcur = state;
xfs_rmap_finish_one_cleanup(tp, rcur, error);
}
STATIC void
xfs_rmap_update_abort_intent(
void *intent)
{
xfs_rui_release(intent);
}
STATIC void
xfs_rmap_update_cancel_item(
struct list_head *item)
{
struct xfs_rmap_intent *rmap;
rmap = container_of(item, struct xfs_rmap_intent, ri_list);
kmem_free(rmap);
}
void
xfs_rmap_update_init_defer_op(void)
{
xfs_defer_init_op_type(&xfs_rmap_update_defer_type);
}
