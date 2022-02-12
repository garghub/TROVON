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
void lov_dump_lmm(int level, void *lmm)
{
int magic;
magic = le32_to_cpu(((struct lov_mds_md *)lmm)->lmm_magic);
switch (magic) {
case LOV_MAGIC_V1:
lov_dump_lmm_v1(level, (struct lov_mds_md_v1 *)lmm);
break;
case LOV_MAGIC_V3:
lov_dump_lmm_v3(level, (struct lov_mds_md_v3 *)lmm);
break;
default:
CDEBUG(level, "unrecognized lmm_magic %x, assuming %x\n",
magic, LOV_MAGIC_V1);
lov_dump_lmm_common(level, lmm);
break;
}
}
int lov_packmd(struct obd_export *exp, struct lov_mds_md **lmmp,
struct lov_stripe_md *lsm)
{
struct obd_device *obd = class_exp2obd(exp);
struct lov_obd *lov = &obd->u.lov;
struct lov_mds_md_v1 *lmmv1;
struct lov_mds_md_v3 *lmmv3;
__u16 stripe_count;
struct lov_ost_data_v1 *lmm_objects;
int lmm_size, lmm_magic;
int i;
int cplen = 0;
if (lsm) {
lmm_magic = lsm->lsm_magic;
} else {
if (lmmp && *lmmp)
lmm_magic = le32_to_cpu((*lmmp)->lmm_magic);
else
lmm_magic = LOV_MAGIC;
}
if ((lmm_magic != LOV_MAGIC_V1) &&
(lmm_magic != LOV_MAGIC_V3)) {
CERROR("bad mem LOV MAGIC: 0x%08X != 0x%08X nor 0x%08X\n",
lmm_magic, LOV_MAGIC_V1, LOV_MAGIC_V3);
return -EINVAL;
}
if (lsm) {
if (!lmmp) {
stripe_count = lov_get_stripecnt(lov, lmm_magic,
lsm->lsm_stripe_count);
lsm->lsm_stripe_count = stripe_count;
} else if (!lsm_is_released(lsm)) {
stripe_count = lsm->lsm_stripe_count;
} else {
stripe_count = 0;
}
} else {
stripe_count = lov_mds_md_max_stripe_count(
lov->lov_ocd.ocd_max_easize, lmm_magic);
if (stripe_count > lov->desc.ld_tgt_count)
stripe_count = lov->desc.ld_tgt_count;
}
lmm_size = lov_mds_md_size(stripe_count, lmm_magic);
if (!lmmp)
return lmm_size;
if (*lmmp && !lsm) {
stripe_count = le16_to_cpu((*lmmp)->lmm_stripe_count);
lmm_size = lov_mds_md_size(stripe_count, lmm_magic);
kvfree(*lmmp);
*lmmp = NULL;
return 0;
}
if (!*lmmp) {
*lmmp = libcfs_kvzalloc(lmm_size, GFP_NOFS);
if (!*lmmp)
return -ENOMEM;
}
CDEBUG(D_INFO, "lov_packmd: LOV_MAGIC 0x%08X, lmm_size = %d \n",
lmm_magic, lmm_size);
lmmv1 = *lmmp;
lmmv3 = (struct lov_mds_md_v3 *)*lmmp;
if (lmm_magic == LOV_MAGIC_V3)
lmmv3->lmm_magic = cpu_to_le32(LOV_MAGIC_V3);
else
lmmv1->lmm_magic = cpu_to_le32(LOV_MAGIC_V1);
if (!lsm)
return lmm_size;
lmm_oi_cpu_to_le(&lmmv1->lmm_oi, &lsm->lsm_oi);
lmmv1->lmm_stripe_size = cpu_to_le32(lsm->lsm_stripe_size);
lmmv1->lmm_stripe_count = cpu_to_le16(stripe_count);
lmmv1->lmm_pattern = cpu_to_le32(lsm->lsm_pattern);
lmmv1->lmm_layout_gen = cpu_to_le16(lsm->lsm_layout_gen);
if (lsm->lsm_magic == LOV_MAGIC_V3) {
cplen = strlcpy(lmmv3->lmm_pool_name, lsm->lsm_pool_name,
sizeof(lmmv3->lmm_pool_name));
if (cplen >= sizeof(lmmv3->lmm_pool_name))
return -E2BIG;
lmm_objects = lmmv3->lmm_objects;
} else {
lmm_objects = lmmv1->lmm_objects;
}
for (i = 0; i < stripe_count; i++) {
struct lov_oinfo *loi = lsm->lsm_oinfo[i];
LASSERTF(ostid_id(&loi->loi_oi) != 0, "lmm_oi "DOSTID
" stripe %u/%u idx %u\n", POSTID(&lmmv1->lmm_oi),
i, stripe_count, loi->loi_ost_idx);
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
if (lsm_op_find(le32_to_cpu(*(__u32 *)lmm)) == NULL) {
char *buffer;
int sz;
CERROR("bad disk LOV MAGIC: 0x%08X; dumping LMM (size=%d):\n",
le32_to_cpu(*(__u32 *)lmm), lmm_bytes);
sz = lmm_bytes * 2 + 1;
buffer = libcfs_kvzalloc(sz, GFP_NOFS);
if (buffer != NULL) {
int i;
for (i = 0; i < lmm_bytes; i++)
sprintf(buffer+2*i, "%.2X", ((char *)lmm)[i]);
buffer[sz - 1] = '\0';
CERROR("%s\n", buffer);
kvfree(buffer);
}
return -EINVAL;
}
rc = lsm_op_find(le32_to_cpu(*(__u32 *)lmm))->lsm_lmm_verify(lmm,
lmm_bytes, stripe_count);
return rc;
}
int lov_alloc_memmd(struct lov_stripe_md **lsmp, __u16 stripe_count,
int pattern, int magic)
{
int i, lsm_size;
CDEBUG(D_INFO, "alloc lsm, stripe_count %d\n", stripe_count);
*lsmp = lsm_alloc_plain(stripe_count, &lsm_size);
if (!*lsmp) {
CERROR("can't allocate lsmp stripe_count %d\n", stripe_count);
return -ENOMEM;
}
atomic_set(&(*lsmp)->lsm_refc, 1);
spin_lock_init(&(*lsmp)->lsm_lock);
(*lsmp)->lsm_magic = magic;
(*lsmp)->lsm_stripe_count = stripe_count;
(*lsmp)->lsm_maxbytes = LUSTRE_STRIPE_MAXBYTES * stripe_count;
(*lsmp)->lsm_pattern = pattern;
(*lsmp)->lsm_pool_name[0] = '\0';
(*lsmp)->lsm_layout_gen = 0;
if (stripe_count > 0)
(*lsmp)->lsm_oinfo[0]->loi_ost_idx = ~0;
for (i = 0; i < stripe_count; i++)
loi_init((*lsmp)->lsm_oinfo[i]);
return lsm_size;
}
int lov_free_memmd(struct lov_stripe_md **lsmp)
{
struct lov_stripe_md *lsm = *lsmp;
int refc;
*lsmp = NULL;
LASSERT(atomic_read(&lsm->lsm_refc) > 0);
refc = atomic_dec_return(&lsm->lsm_refc);
if (refc == 0) {
LASSERT(lsm_op_find(lsm->lsm_magic) != NULL);
lsm_op_find(lsm->lsm_magic)->lsm_free(lsm);
}
return refc;
}
int lov_unpackmd(struct obd_export *exp, struct lov_stripe_md **lsmp,
struct lov_mds_md *lmm, int lmm_bytes)
{
struct obd_device *obd = class_exp2obd(exp);
struct lov_obd *lov = &obd->u.lov;
int rc = 0, lsm_size;
__u16 stripe_count;
__u32 magic;
__u32 pattern;
if (lmm) {
rc = lov_verify_lmm(lmm, lmm_bytes, &stripe_count);
if (rc)
return rc;
magic = le32_to_cpu(lmm->lmm_magic);
pattern = le32_to_cpu(lmm->lmm_pattern);
} else {
magic = LOV_MAGIC;
stripe_count = lov_get_stripecnt(lov, magic, 0);
pattern = LOV_PATTERN_RAID0;
}
if (!lsmp) {
LBUG();
return lov_stripe_md_size(stripe_count);
}
if (*lsmp && !lmm) {
lov_free_memmd(lsmp);
return 0;
}
lsm_size = lov_alloc_memmd(lsmp, stripe_count, pattern, magic);
if (lsm_size < 0)
return lsm_size;
if (!lmm)
return lsm_size;
LASSERT(lsm_op_find(magic) != NULL);
rc = lsm_op_find(magic)->lsm_unpackmd(lov, *lsmp, lmm);
if (rc) {
lov_free_memmd(lsmp);
return rc;
}
return lsm_size;
}
int lov_getstripe(struct obd_export *exp, struct lov_stripe_md *lsm,
struct lov_user_md *lump)
{
struct lov_user_md_v3 lum;
struct lov_mds_md *lmmk = NULL;
int rc, lmm_size;
int lum_size;
mm_segment_t seg;
if (!lsm)
return -ENODATA;
seg = get_fs();
set_fs(KERNEL_DS);
lum_size = sizeof(struct lov_user_md_v1);
if (copy_from_user(&lum, lump, lum_size)) {
rc = -EFAULT;
goto out_set;
} else if ((lum.lmm_magic != LOV_USER_MAGIC) &&
(lum.lmm_magic != LOV_USER_MAGIC_V3)) {
rc = -EINVAL;
goto out_set;
}
if (lum.lmm_stripe_count &&
(lum.lmm_stripe_count < lsm->lsm_stripe_count)) {
lum.lmm_stripe_count = lsm->lsm_stripe_count;
rc = copy_to_user(lump, &lum, lum_size);
rc = -EOVERFLOW;
goto out_set;
}
rc = lov_packmd(exp, &lmmk, lsm);
if (rc < 0)
goto out_set;
lmm_size = rc;
rc = 0;
CLASSERT(sizeof(lum) == sizeof(struct lov_mds_md_v3));
CLASSERT(sizeof(lum.lmm_objects[0]) == sizeof(lmmk->lmm_objects[0]));
if ((cpu_to_le32(LOV_MAGIC) != LOV_MAGIC) &&
((lmmk->lmm_magic == cpu_to_le32(LOV_MAGIC_V1)) ||
(lmmk->lmm_magic == cpu_to_le32(LOV_MAGIC_V3)))) {
lustre_swab_lov_mds_md(lmmk);
lustre_swab_lov_user_md_objects(
(struct lov_user_ost_data *)lmmk->lmm_objects,
lmmk->lmm_stripe_count);
}
if (lum.lmm_magic == LOV_USER_MAGIC) {
if (lmmk->lmm_magic == LOV_MAGIC_V3) {
memmove((char *)(&lmmk->lmm_stripe_count) +
sizeof(lmmk->lmm_stripe_count),
((struct lov_mds_md_v3 *)lmmk)->lmm_objects,
lmmk->lmm_stripe_count *
sizeof(struct lov_ost_data_v1));
lmm_size -= LOV_MAXPOOLNAME;
}
} else {
lum_size = sizeof(struct lov_user_md_v3);
}
if (lum.lmm_stripe_count == 0)
lmm_size = lum_size;
else if (lum.lmm_stripe_count < lmmk->lmm_stripe_count) {
rc = -EOVERFLOW;
goto out_set;
}
lum.lmm_stripe_count = lmmk->lmm_stripe_count;
lum.lmm_layout_gen = lmmk->lmm_layout_gen;
((struct lov_user_md *)lmmk)->lmm_layout_gen = lum.lmm_layout_gen;
((struct lov_user_md *)lmmk)->lmm_stripe_count = lum.lmm_stripe_count;
if (copy_to_user(lump, lmmk, lmm_size))
rc = -EFAULT;
obd_free_diskmd(exp, &lmmk);
out_set:
set_fs(seg);
return rc;
}
