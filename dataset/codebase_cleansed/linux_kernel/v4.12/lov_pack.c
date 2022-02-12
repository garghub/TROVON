void lov_dump_lmm_common(int level, void *lmmp)
{
struct lov_mds_md *lmm = lmmp;
struct ost_id oi;
lmm_oi_le_to_cpu(&oi, &lmm->lmm_oi);
CDEBUG(level, "objid "DOSTID", magic 0x%08x, pattern %#x\n",
POSTID(&oi), le32_to_cpu(lmm->lmm_magic),
le32_to_cpu(lmm->lmm_pattern));
CDEBUG(level, "stripe_size %u, stripe_count %u, layout_gen %u\n",
le32_to_cpu(lmm->lmm_stripe_size),
le16_to_cpu(lmm->lmm_stripe_count),
le16_to_cpu(lmm->lmm_layout_gen));
}
static void lov_dump_lmm_objects(int level, struct lov_ost_data *lod,
int stripe_count)
{
int i;
if (stripe_count > LOV_V1_INSANE_STRIPE_COUNT) {
CDEBUG(level, "bad stripe_count %u > max_stripe_count %u\n",
stripe_count, LOV_V1_INSANE_STRIPE_COUNT);
return;
}
for (i = 0; i < stripe_count; ++i, ++lod) {
struct ost_id oi;
ostid_le_to_cpu(&lod->l_ost_oi, &oi);
CDEBUG(level, "stripe %u idx %u subobj "DOSTID"\n", i,
le32_to_cpu(lod->l_ost_idx), POSTID(&oi));
}
}
void lov_dump_lmm_v1(int level, struct lov_mds_md_v1 *lmm)
{
lov_dump_lmm_common(level, lmm);
lov_dump_lmm_objects(level, lmm->lmm_objects,
le16_to_cpu(lmm->lmm_stripe_count));
}
void lov_dump_lmm_v3(int level, struct lov_mds_md_v3 *lmm)
{
lov_dump_lmm_common(level, lmm);
CDEBUG(level, "pool_name "LOV_POOLNAMEF"\n", lmm->lmm_pool_name);
lov_dump_lmm_objects(level, lmm->lmm_objects,
le16_to_cpu(lmm->lmm_stripe_count));
}
ssize_t lov_lsm_pack(const struct lov_stripe_md *lsm, void *buf,
size_t buf_size)
{
struct lov_ost_data_v1 *lmm_objects;
struct lov_mds_md_v1 *lmmv1 = buf;
struct lov_mds_md_v3 *lmmv3 = buf;
size_t lmm_size;
unsigned int i;
lmm_size = lov_mds_md_size(lsm->lsm_stripe_count, lsm->lsm_magic);
if (!buf_size)
return lmm_size;
if (buf_size < lmm_size)
return -ERANGE;
lmmv1->lmm_magic = cpu_to_le32(lsm->lsm_magic);
lmm_oi_cpu_to_le(&lmmv1->lmm_oi, &lsm->lsm_oi);
lmmv1->lmm_stripe_size = cpu_to_le32(lsm->lsm_stripe_size);
lmmv1->lmm_stripe_count = cpu_to_le16(lsm->lsm_stripe_count);
lmmv1->lmm_pattern = cpu_to_le32(lsm->lsm_pattern);
lmmv1->lmm_layout_gen = cpu_to_le16(lsm->lsm_layout_gen);
if (lsm->lsm_magic == LOV_MAGIC_V3) {
BUILD_BUG_ON(sizeof(lsm->lsm_pool_name) !=
sizeof(lmmv3->lmm_pool_name));
strlcpy(lmmv3->lmm_pool_name, lsm->lsm_pool_name,
sizeof(lmmv3->lmm_pool_name));
lmm_objects = lmmv3->lmm_objects;
} else {
lmm_objects = lmmv1->lmm_objects;
}
for (i = 0; i < lsm->lsm_stripe_count; i++) {
struct lov_oinfo *loi = lsm->lsm_oinfo[i];
ostid_cpu_to_le(&loi->loi_oi, &lmm_objects[i].l_ost_oi);
lmm_objects[i].l_ost_gen = cpu_to_le32(loi->loi_ost_gen);
lmm_objects[i].l_ost_idx = cpu_to_le32(loi->loi_ost_idx);
}
return lmm_size;
}
__u16 lov_get_stripecnt(struct lov_obd *lov, __u32 magic, __u16 stripe_count)
{
__u32 max_stripes = LOV_MAX_STRIPE_COUNT_OLD;
if (!stripe_count)
stripe_count = lov->desc.ld_default_stripe_count;
if (stripe_count > lov->desc.ld_active_tgt_count)
stripe_count = lov->desc.ld_active_tgt_count;
if (!stripe_count)
stripe_count = 1;
if (lov->lov_ocd.ocd_connect_flags & OBD_CONNECT_MAX_EASIZE &&
lov->lov_ocd.ocd_max_easize)
max_stripes = lov_mds_md_max_stripe_count(
lov->lov_ocd.ocd_max_easize, magic);
if (stripe_count > max_stripes)
stripe_count = max_stripes;
return stripe_count;
}
static int lov_verify_lmm(void *lmm, int lmm_bytes, __u16 *stripe_count)
{
int rc;
if (!lsm_op_find(le32_to_cpu(*(__u32 *)lmm))) {
CERROR("bad disk LOV MAGIC: 0x%08X; dumping LMM (size=%d):\n",
le32_to_cpu(*(__u32 *)lmm), lmm_bytes);
CERROR("%*phN\n", lmm_bytes, lmm);
return -EINVAL;
}
rc = lsm_op_find(le32_to_cpu(*(__u32 *)lmm))->lsm_lmm_verify(lmm,
lmm_bytes,
stripe_count);
return rc;
}
static struct lov_stripe_md *lov_lsm_alloc(u16 stripe_count, u32 pattern,
u32 magic)
{
struct lov_stripe_md *lsm;
unsigned int i;
CDEBUG(D_INFO, "alloc lsm, stripe_count %u\n", stripe_count);
lsm = lsm_alloc_plain(stripe_count);
if (!lsm) {
CERROR("cannot allocate LSM stripe_count %u\n", stripe_count);
return ERR_PTR(-ENOMEM);
}
atomic_set(&lsm->lsm_refc, 1);
spin_lock_init(&lsm->lsm_lock);
lsm->lsm_magic = magic;
lsm->lsm_stripe_count = stripe_count;
lsm->lsm_maxbytes = LUSTRE_EXT3_STRIPE_MAXBYTES * stripe_count;
lsm->lsm_pattern = pattern;
lsm->lsm_pool_name[0] = '\0';
lsm->lsm_layout_gen = 0;
if (stripe_count > 0)
lsm->lsm_oinfo[0]->loi_ost_idx = ~0;
for (i = 0; i < stripe_count; i++)
loi_init(lsm->lsm_oinfo[i]);
return lsm;
}
int lov_free_memmd(struct lov_stripe_md **lsmp)
{
struct lov_stripe_md *lsm = *lsmp;
int refc;
*lsmp = NULL;
LASSERT(atomic_read(&lsm->lsm_refc) > 0);
refc = atomic_dec_return(&lsm->lsm_refc);
if (refc == 0)
lsm_op_find(lsm->lsm_magic)->lsm_free(lsm);
return refc;
}
struct lov_stripe_md *lov_unpackmd(struct lov_obd *lov, struct lov_mds_md *lmm,
size_t lmm_size)
{
struct lov_stripe_md *lsm;
u16 stripe_count;
u32 pattern;
u32 magic;
int rc;
rc = lov_verify_lmm(lmm, lmm_size, &stripe_count);
if (rc)
return ERR_PTR(rc);
magic = le32_to_cpu(lmm->lmm_magic);
pattern = le32_to_cpu(lmm->lmm_pattern);
lsm = lov_lsm_alloc(stripe_count, pattern, magic);
if (IS_ERR(lsm))
return lsm;
LASSERT(lsm_op_find(magic));
rc = lsm_op_find(magic)->lsm_unpackmd(lov, lsm, lmm);
if (rc) {
lov_free_memmd(&lsm);
return ERR_PTR(rc);
}
return lsm;
}
int lov_getstripe(struct lov_object *obj, struct lov_stripe_md *lsm,
struct lov_user_md __user *lump)
{
struct lov_user_md_v3 lum;
struct lov_mds_md *lmmk;
u32 stripe_count;
ssize_t lmm_size;
size_t lmmk_size;
size_t lum_size;
int rc;
if (!lsm)
return -ENODATA;
if (lsm->lsm_magic != LOV_MAGIC_V1 && lsm->lsm_magic != LOV_MAGIC_V3) {
CERROR("bad LSM MAGIC: 0x%08X != 0x%08X nor 0x%08X\n",
lsm->lsm_magic, LOV_MAGIC_V1, LOV_MAGIC_V3);
rc = -EIO;
goto out;
}
if (!lsm_is_released(lsm))
stripe_count = lsm->lsm_stripe_count;
else
stripe_count = 0;
lum_size = sizeof(struct lov_user_md_v1);
if (copy_from_user(&lum, lump, lum_size)) {
rc = -EFAULT;
goto out;
}
if (lum.lmm_magic != LOV_USER_MAGIC_V1 &&
lum.lmm_magic != LOV_USER_MAGIC_V3 &&
lum.lmm_magic != LOV_USER_MAGIC_SPECIFIC) {
rc = -EINVAL;
goto out;
}
if (lum.lmm_stripe_count &&
(lum.lmm_stripe_count < lsm->lsm_stripe_count)) {
lum.lmm_stripe_count = stripe_count;
rc = copy_to_user(lump, &lum, lum_size);
rc = -EOVERFLOW;
goto out;
}
lmmk_size = lov_mds_md_size(stripe_count, lsm->lsm_magic);
lmmk = libcfs_kvzalloc(lmmk_size, GFP_NOFS);
if (!lmmk) {
rc = -ENOMEM;
goto out;
}
lmm_size = lov_lsm_pack(lsm, lmmk, lmmk_size);
if (lmm_size < 0) {
rc = lmm_size;
goto out_free;
}
BUILD_BUG_ON(sizeof(lum) != sizeof(struct lov_mds_md_v3));
BUILD_BUG_ON(sizeof(lum.lmm_objects[0]) != sizeof(lmmk->lmm_objects[0]));
if (cpu_to_le32(LOV_MAGIC) != LOV_MAGIC &&
(lmmk->lmm_magic == cpu_to_le32(LOV_MAGIC_V1) ||
lmmk->lmm_magic == cpu_to_le32(LOV_MAGIC_V3))) {
lustre_swab_lov_mds_md(lmmk);
lustre_swab_lov_user_md_objects(
(struct lov_user_ost_data *)lmmk->lmm_objects,
lmmk->lmm_stripe_count);
}
if (lum.lmm_magic == LOV_USER_MAGIC) {
if (lmmk->lmm_magic == LOV_MAGIC_V3) {
memmove(((struct lov_mds_md_v1 *)lmmk)->lmm_objects,
((struct lov_mds_md_v3 *)lmmk)->lmm_objects,
lmmk->lmm_stripe_count *
sizeof(struct lov_ost_data_v1));
lmm_size -= LOV_MAXPOOLNAME;
}
} else {
lum_size = sizeof(struct lov_user_md_v3);
}
if (lum.lmm_stripe_count == 0) {
lmm_size = lum_size;
} else if (lum.lmm_stripe_count < lmmk->lmm_stripe_count) {
rc = -EOVERFLOW;
goto out_free;
}
lum.lmm_stripe_count = lmmk->lmm_stripe_count;
lum.lmm_layout_gen = lmmk->lmm_layout_gen;
((struct lov_user_md *)lmmk)->lmm_layout_gen = lum.lmm_layout_gen;
((struct lov_user_md *)lmmk)->lmm_stripe_count = lum.lmm_stripe_count;
if (copy_to_user(lump, lmmk, lmm_size))
rc = -EFAULT;
else
rc = 0;
out_free:
kvfree(lmmk);
out:
return rc;
}
