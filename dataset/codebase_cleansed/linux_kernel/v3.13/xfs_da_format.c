static int
xfs_dir2_sf_entsize(
struct xfs_dir2_sf_hdr *hdr,
int len)
{
int count = sizeof(struct xfs_dir2_sf_entry);
count += len;
count += hdr->i8count ? sizeof(xfs_dir2_ino8_t) :
sizeof(xfs_dir2_ino4_t);
return count;
}
static int
xfs_dir3_sf_entsize(
struct xfs_dir2_sf_hdr *hdr,
int len)
{
return xfs_dir2_sf_entsize(hdr, len) + sizeof(__uint8_t);
}
static struct xfs_dir2_sf_entry *
xfs_dir2_sf_nextentry(
struct xfs_dir2_sf_hdr *hdr,
struct xfs_dir2_sf_entry *sfep)
{
return (struct xfs_dir2_sf_entry *)
((char *)sfep + xfs_dir2_sf_entsize(hdr, sfep->namelen));
}
static struct xfs_dir2_sf_entry *
xfs_dir3_sf_nextentry(
struct xfs_dir2_sf_hdr *hdr,
struct xfs_dir2_sf_entry *sfep)
{
return (struct xfs_dir2_sf_entry *)
((char *)sfep + xfs_dir3_sf_entsize(hdr, sfep->namelen));
}
static __uint8_t
xfs_dir2_sfe_get_ftype(
struct xfs_dir2_sf_entry *sfep)
{
return XFS_DIR3_FT_UNKNOWN;
}
static void
xfs_dir2_sfe_put_ftype(
struct xfs_dir2_sf_entry *sfep,
__uint8_t ftype)
{
ASSERT(ftype < XFS_DIR3_FT_MAX);
}
static __uint8_t
xfs_dir3_sfe_get_ftype(
struct xfs_dir2_sf_entry *sfep)
{
__uint8_t ftype;
ftype = sfep->name[sfep->namelen];
if (ftype >= XFS_DIR3_FT_MAX)
return XFS_DIR3_FT_UNKNOWN;
return ftype;
}
static void
xfs_dir3_sfe_put_ftype(
struct xfs_dir2_sf_entry *sfep,
__uint8_t ftype)
{
ASSERT(ftype < XFS_DIR3_FT_MAX);
sfep->name[sfep->namelen] = ftype;
}
static xfs_ino_t
xfs_dir2_sf_get_ino(
struct xfs_dir2_sf_hdr *hdr,
xfs_dir2_inou_t *from)
{
if (hdr->i8count)
return get_unaligned_be64(&from->i8.i) & 0x00ffffffffffffffULL;
else
return get_unaligned_be32(&from->i4.i);
}
static void
xfs_dir2_sf_put_ino(
struct xfs_dir2_sf_hdr *hdr,
xfs_dir2_inou_t *to,
xfs_ino_t ino)
{
ASSERT((ino & 0xff00000000000000ULL) == 0);
if (hdr->i8count)
put_unaligned_be64(ino, &to->i8.i);
else
put_unaligned_be32(ino, &to->i4.i);
}
static xfs_ino_t
xfs_dir2_sf_get_parent_ino(
struct xfs_dir2_sf_hdr *hdr)
{
return xfs_dir2_sf_get_ino(hdr, &hdr->parent);
}
static void
xfs_dir2_sf_put_parent_ino(
struct xfs_dir2_sf_hdr *hdr,
xfs_ino_t ino)
{
xfs_dir2_sf_put_ino(hdr, &hdr->parent, ino);
}
static xfs_ino_t
xfs_dir2_sfe_get_ino(
struct xfs_dir2_sf_hdr *hdr,
struct xfs_dir2_sf_entry *sfep)
{
return xfs_dir2_sf_get_ino(hdr,
(xfs_dir2_inou_t *)&sfep->name[sfep->namelen]);
}
static void
xfs_dir2_sfe_put_ino(
struct xfs_dir2_sf_hdr *hdr,
struct xfs_dir2_sf_entry *sfep,
xfs_ino_t ino)
{
xfs_dir2_sf_put_ino(hdr,
(xfs_dir2_inou_t *)&sfep->name[sfep->namelen], ino);
}
static xfs_ino_t
xfs_dir3_sfe_get_ino(
struct xfs_dir2_sf_hdr *hdr,
struct xfs_dir2_sf_entry *sfep)
{
return xfs_dir2_sf_get_ino(hdr,
(xfs_dir2_inou_t *)&sfep->name[sfep->namelen + 1]);
}
static void
xfs_dir3_sfe_put_ino(
struct xfs_dir2_sf_hdr *hdr,
struct xfs_dir2_sf_entry *sfep,
xfs_ino_t ino)
{
xfs_dir2_sf_put_ino(hdr,
(xfs_dir2_inou_t *)&sfep->name[sfep->namelen + 1], ino);
}
static int
xfs_dir2_data_entsize(
int n)
{
return XFS_DIR2_DATA_ENTSIZE(n);
}
static int
xfs_dir3_data_entsize(
int n)
{
return XFS_DIR3_DATA_ENTSIZE(n);
}
static __uint8_t
xfs_dir2_data_get_ftype(
struct xfs_dir2_data_entry *dep)
{
return XFS_DIR3_FT_UNKNOWN;
}
static void
xfs_dir2_data_put_ftype(
struct xfs_dir2_data_entry *dep,
__uint8_t ftype)
{
ASSERT(ftype < XFS_DIR3_FT_MAX);
}
static __uint8_t
xfs_dir3_data_get_ftype(
struct xfs_dir2_data_entry *dep)
{
__uint8_t ftype = dep->name[dep->namelen];
ASSERT(ftype < XFS_DIR3_FT_MAX);
if (ftype >= XFS_DIR3_FT_MAX)
return XFS_DIR3_FT_UNKNOWN;
return ftype;
}
static void
xfs_dir3_data_put_ftype(
struct xfs_dir2_data_entry *dep,
__uint8_t type)
{
ASSERT(type < XFS_DIR3_FT_MAX);
ASSERT(dep->namelen != 0);
dep->name[dep->namelen] = type;
}
static __be16 *
xfs_dir2_data_entry_tag_p(
struct xfs_dir2_data_entry *dep)
{
return (__be16 *)((char *)dep +
xfs_dir2_data_entsize(dep->namelen) - sizeof(__be16));
}
static __be16 *
xfs_dir3_data_entry_tag_p(
struct xfs_dir2_data_entry *dep)
{
return (__be16 *)((char *)dep +
xfs_dir3_data_entsize(dep->namelen) - sizeof(__be16));
}
static struct xfs_dir2_data_entry *
xfs_dir2_data_dot_entry_p(
struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir2_data_hdr));
}
static struct xfs_dir2_data_entry *
xfs_dir2_data_dotdot_entry_p(
struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir2_data_hdr) +
XFS_DIR2_DATA_ENTSIZE(1));
}
static struct xfs_dir2_data_entry *
xfs_dir2_data_first_entry_p(
struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir2_data_hdr) +
XFS_DIR2_DATA_ENTSIZE(1) +
XFS_DIR2_DATA_ENTSIZE(2));
}
static struct xfs_dir2_data_entry *
xfs_dir2_ftype_data_dotdot_entry_p(
struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir2_data_hdr) +
XFS_DIR3_DATA_ENTSIZE(1));
}
static struct xfs_dir2_data_entry *
xfs_dir2_ftype_data_first_entry_p(
struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir2_data_hdr) +
XFS_DIR3_DATA_ENTSIZE(1) +
XFS_DIR3_DATA_ENTSIZE(2));
}
static struct xfs_dir2_data_entry *
xfs_dir3_data_dot_entry_p(
struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir3_data_hdr));
}
static struct xfs_dir2_data_entry *
xfs_dir3_data_dotdot_entry_p(
struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir3_data_hdr) +
XFS_DIR3_DATA_ENTSIZE(1));
}
static struct xfs_dir2_data_entry *
xfs_dir3_data_first_entry_p(
struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir3_data_hdr) +
XFS_DIR3_DATA_ENTSIZE(1) +
XFS_DIR3_DATA_ENTSIZE(2));
}
static struct xfs_dir2_data_free *
xfs_dir2_data_bestfree_p(struct xfs_dir2_data_hdr *hdr)
{
return hdr->bestfree;
}
static struct xfs_dir2_data_free *
xfs_dir3_data_bestfree_p(struct xfs_dir2_data_hdr *hdr)
{
return ((struct xfs_dir3_data_hdr *)hdr)->best_free;
}
static struct xfs_dir2_data_entry *
xfs_dir2_data_entry_p(struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir2_data_hdr));
}
static struct xfs_dir2_data_unused *
xfs_dir2_data_unused_p(struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_unused *)
((char *)hdr + sizeof(struct xfs_dir2_data_hdr));
}
static struct xfs_dir2_data_entry *
xfs_dir3_data_entry_p(struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_entry *)
((char *)hdr + sizeof(struct xfs_dir3_data_hdr));
}
static struct xfs_dir2_data_unused *
xfs_dir3_data_unused_p(struct xfs_dir2_data_hdr *hdr)
{
return (struct xfs_dir2_data_unused *)
((char *)hdr + sizeof(struct xfs_dir3_data_hdr));
}
static int
xfs_dir2_max_leaf_ents(struct xfs_mount *mp)
{
return (mp->m_dirblksize - sizeof(struct xfs_dir2_leaf_hdr)) /
(uint)sizeof(struct xfs_dir2_leaf_entry);
}
static struct xfs_dir2_leaf_entry *
xfs_dir2_leaf_ents_p(struct xfs_dir2_leaf *lp)
{
return lp->__ents;
}
static int
xfs_dir3_max_leaf_ents(struct xfs_mount *mp)
{
return (mp->m_dirblksize - sizeof(struct xfs_dir3_leaf_hdr)) /
(uint)sizeof(struct xfs_dir2_leaf_entry);
}
static struct xfs_dir2_leaf_entry *
xfs_dir3_leaf_ents_p(struct xfs_dir2_leaf *lp)
{
return ((struct xfs_dir3_leaf *)lp)->__ents;
}
static void
xfs_dir2_leaf_hdr_from_disk(
struct xfs_dir3_icleaf_hdr *to,
struct xfs_dir2_leaf *from)
{
to->forw = be32_to_cpu(from->hdr.info.forw);
to->back = be32_to_cpu(from->hdr.info.back);
to->magic = be16_to_cpu(from->hdr.info.magic);
to->count = be16_to_cpu(from->hdr.count);
to->stale = be16_to_cpu(from->hdr.stale);
ASSERT(to->magic == XFS_DIR2_LEAF1_MAGIC ||
to->magic == XFS_DIR2_LEAFN_MAGIC);
}
static void
xfs_dir2_leaf_hdr_to_disk(
struct xfs_dir2_leaf *to,
struct xfs_dir3_icleaf_hdr *from)
{
ASSERT(from->magic == XFS_DIR2_LEAF1_MAGIC ||
from->magic == XFS_DIR2_LEAFN_MAGIC);
to->hdr.info.forw = cpu_to_be32(from->forw);
to->hdr.info.back = cpu_to_be32(from->back);
to->hdr.info.magic = cpu_to_be16(from->magic);
to->hdr.count = cpu_to_be16(from->count);
to->hdr.stale = cpu_to_be16(from->stale);
}
static void
xfs_dir3_leaf_hdr_from_disk(
struct xfs_dir3_icleaf_hdr *to,
struct xfs_dir2_leaf *from)
{
struct xfs_dir3_leaf_hdr *hdr3 = (struct xfs_dir3_leaf_hdr *)from;
to->forw = be32_to_cpu(hdr3->info.hdr.forw);
to->back = be32_to_cpu(hdr3->info.hdr.back);
to->magic = be16_to_cpu(hdr3->info.hdr.magic);
to->count = be16_to_cpu(hdr3->count);
to->stale = be16_to_cpu(hdr3->stale);
ASSERT(to->magic == XFS_DIR3_LEAF1_MAGIC ||
to->magic == XFS_DIR3_LEAFN_MAGIC);
}
static void
xfs_dir3_leaf_hdr_to_disk(
struct xfs_dir2_leaf *to,
struct xfs_dir3_icleaf_hdr *from)
{
struct xfs_dir3_leaf_hdr *hdr3 = (struct xfs_dir3_leaf_hdr *)to;
ASSERT(from->magic == XFS_DIR3_LEAF1_MAGIC ||
from->magic == XFS_DIR3_LEAFN_MAGIC);
hdr3->info.hdr.forw = cpu_to_be32(from->forw);
hdr3->info.hdr.back = cpu_to_be32(from->back);
hdr3->info.hdr.magic = cpu_to_be16(from->magic);
hdr3->count = cpu_to_be16(from->count);
hdr3->stale = cpu_to_be16(from->stale);
}
static struct xfs_da_node_entry *
xfs_da2_node_tree_p(struct xfs_da_intnode *dap)
{
return dap->__btree;
}
static struct xfs_da_node_entry *
xfs_da3_node_tree_p(struct xfs_da_intnode *dap)
{
return ((struct xfs_da3_intnode *)dap)->__btree;
}
static void
xfs_da2_node_hdr_from_disk(
struct xfs_da3_icnode_hdr *to,
struct xfs_da_intnode *from)
{
ASSERT(from->hdr.info.magic == cpu_to_be16(XFS_DA_NODE_MAGIC));
to->forw = be32_to_cpu(from->hdr.info.forw);
to->back = be32_to_cpu(from->hdr.info.back);
to->magic = be16_to_cpu(from->hdr.info.magic);
to->count = be16_to_cpu(from->hdr.__count);
to->level = be16_to_cpu(from->hdr.__level);
}
static void
xfs_da2_node_hdr_to_disk(
struct xfs_da_intnode *to,
struct xfs_da3_icnode_hdr *from)
{
ASSERT(from->magic == XFS_DA_NODE_MAGIC);
to->hdr.info.forw = cpu_to_be32(from->forw);
to->hdr.info.back = cpu_to_be32(from->back);
to->hdr.info.magic = cpu_to_be16(from->magic);
to->hdr.__count = cpu_to_be16(from->count);
to->hdr.__level = cpu_to_be16(from->level);
}
static void
xfs_da3_node_hdr_from_disk(
struct xfs_da3_icnode_hdr *to,
struct xfs_da_intnode *from)
{
struct xfs_da3_node_hdr *hdr3 = (struct xfs_da3_node_hdr *)from;
ASSERT(from->hdr.info.magic == cpu_to_be16(XFS_DA3_NODE_MAGIC));
to->forw = be32_to_cpu(hdr3->info.hdr.forw);
to->back = be32_to_cpu(hdr3->info.hdr.back);
to->magic = be16_to_cpu(hdr3->info.hdr.magic);
to->count = be16_to_cpu(hdr3->__count);
to->level = be16_to_cpu(hdr3->__level);
}
static void
xfs_da3_node_hdr_to_disk(
struct xfs_da_intnode *to,
struct xfs_da3_icnode_hdr *from)
{
struct xfs_da3_node_hdr *hdr3 = (struct xfs_da3_node_hdr *)to;
ASSERT(from->magic == XFS_DA3_NODE_MAGIC);
hdr3->info.hdr.forw = cpu_to_be32(from->forw);
hdr3->info.hdr.back = cpu_to_be32(from->back);
hdr3->info.hdr.magic = cpu_to_be16(from->magic);
hdr3->__count = cpu_to_be16(from->count);
hdr3->__level = cpu_to_be16(from->level);
}
static int
xfs_dir2_free_max_bests(struct xfs_mount *mp)
{
return (mp->m_dirblksize - sizeof(struct xfs_dir2_free_hdr)) /
sizeof(xfs_dir2_data_off_t);
}
static __be16 *
xfs_dir2_free_bests_p(struct xfs_dir2_free *free)
{
return (__be16 *)((char *)free + sizeof(struct xfs_dir2_free_hdr));
}
static xfs_dir2_db_t
xfs_dir2_db_to_fdb(struct xfs_mount *mp, xfs_dir2_db_t db)
{
return XFS_DIR2_FREE_FIRSTDB(mp) + db / xfs_dir2_free_max_bests(mp);
}
static int
xfs_dir2_db_to_fdindex(struct xfs_mount *mp, xfs_dir2_db_t db)
{
return db % xfs_dir2_free_max_bests(mp);
}
static int
xfs_dir3_free_max_bests(struct xfs_mount *mp)
{
return (mp->m_dirblksize - sizeof(struct xfs_dir3_free_hdr)) /
sizeof(xfs_dir2_data_off_t);
}
static __be16 *
xfs_dir3_free_bests_p(struct xfs_dir2_free *free)
{
return (__be16 *)((char *)free + sizeof(struct xfs_dir3_free_hdr));
}
static xfs_dir2_db_t
xfs_dir3_db_to_fdb(struct xfs_mount *mp, xfs_dir2_db_t db)
{
return XFS_DIR2_FREE_FIRSTDB(mp) + db / xfs_dir3_free_max_bests(mp);
}
static int
xfs_dir3_db_to_fdindex(struct xfs_mount *mp, xfs_dir2_db_t db)
{
return db % xfs_dir3_free_max_bests(mp);
}
static void
xfs_dir2_free_hdr_from_disk(
struct xfs_dir3_icfree_hdr *to,
struct xfs_dir2_free *from)
{
to->magic = be32_to_cpu(from->hdr.magic);
to->firstdb = be32_to_cpu(from->hdr.firstdb);
to->nvalid = be32_to_cpu(from->hdr.nvalid);
to->nused = be32_to_cpu(from->hdr.nused);
ASSERT(to->magic == XFS_DIR2_FREE_MAGIC);
}
static void
xfs_dir2_free_hdr_to_disk(
struct xfs_dir2_free *to,
struct xfs_dir3_icfree_hdr *from)
{
ASSERT(from->magic == XFS_DIR2_FREE_MAGIC);
to->hdr.magic = cpu_to_be32(from->magic);
to->hdr.firstdb = cpu_to_be32(from->firstdb);
to->hdr.nvalid = cpu_to_be32(from->nvalid);
to->hdr.nused = cpu_to_be32(from->nused);
}
static void
xfs_dir3_free_hdr_from_disk(
struct xfs_dir3_icfree_hdr *to,
struct xfs_dir2_free *from)
{
struct xfs_dir3_free_hdr *hdr3 = (struct xfs_dir3_free_hdr *)from;
to->magic = be32_to_cpu(hdr3->hdr.magic);
to->firstdb = be32_to_cpu(hdr3->firstdb);
to->nvalid = be32_to_cpu(hdr3->nvalid);
to->nused = be32_to_cpu(hdr3->nused);
ASSERT(to->magic == XFS_DIR3_FREE_MAGIC);
}
static void
xfs_dir3_free_hdr_to_disk(
struct xfs_dir2_free *to,
struct xfs_dir3_icfree_hdr *from)
{
struct xfs_dir3_free_hdr *hdr3 = (struct xfs_dir3_free_hdr *)to;
ASSERT(from->magic == XFS_DIR3_FREE_MAGIC);
hdr3->hdr.magic = cpu_to_be32(from->magic);
hdr3->firstdb = cpu_to_be32(from->firstdb);
hdr3->nvalid = cpu_to_be32(from->nvalid);
hdr3->nused = cpu_to_be32(from->nused);
}
const struct xfs_dir_ops *
xfs_dir_get_ops(
struct xfs_mount *mp,
struct xfs_inode *dp)
{
if (dp)
return dp->d_ops;
if (mp->m_dir_inode_ops)
return mp->m_dir_inode_ops;
if (xfs_sb_version_hascrc(&mp->m_sb))
return &xfs_dir3_ops;
if (xfs_sb_version_hasftype(&mp->m_sb))
return &xfs_dir2_ftype_ops;
return &xfs_dir2_ops;
}
const struct xfs_dir_ops *
xfs_nondir_get_ops(
struct xfs_mount *mp,
struct xfs_inode *dp)
{
if (dp)
return dp->d_ops;
if (mp->m_nondir_inode_ops)
return mp->m_nondir_inode_ops;
if (xfs_sb_version_hascrc(&mp->m_sb))
return &xfs_dir3_nondir_ops;
return &xfs_dir2_nondir_ops;
}
