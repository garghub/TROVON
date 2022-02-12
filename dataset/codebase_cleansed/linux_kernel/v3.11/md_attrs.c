void lustre_lma_init(struct lustre_mdt_attrs *lma, const struct lu_fid *fid,
__u32 incompat)
{
lma->lma_compat = 0;
lma->lma_incompat = incompat;
lma->lma_self_fid = *fid;
LASSERT(sizeof(*lma) ==
(offsetof(struct lustre_mdt_attrs, lma_self_fid) +
sizeof(lma->lma_self_fid)));
}
void lustre_lma_swab(struct lustre_mdt_attrs *lma)
{
if (LUSTRE_MSG_MAGIC != cpu_to_le32(LUSTRE_MSG_MAGIC)) {
__swab32s(&lma->lma_compat);
__swab32s(&lma->lma_incompat);
lustre_swab_lu_fid(&lma->lma_self_fid);
}
}
void lustre_som_swab(struct som_attrs *attrs)
{
if (LUSTRE_MSG_MAGIC != cpu_to_le32(LUSTRE_MSG_MAGIC)) {
__swab32s(&attrs->som_compat);
__swab32s(&attrs->som_incompat);
__swab64s(&attrs->som_ioepoch);
__swab64s(&attrs->som_size);
__swab64s(&attrs->som_blocks);
__swab64s(&attrs->som_mountid);
}
}
int lustre_buf2som(void *buf, int rc, struct md_som_data *msd)
{
struct som_attrs *attrs = (struct som_attrs *)buf;
ENTRY;
if (rc == 0 || rc == -ENODATA)
RETURN(-ENODATA);
if (rc < 0)
RETURN(rc);
if (attrs->som_incompat & ~cpu_to_le32(SOM_INCOMPAT_SUPP))
RETURN(-ENODATA);
lustre_som_swab(attrs);
msd->msd_compat = attrs->som_compat;
msd->msd_incompat = attrs->som_incompat;
msd->msd_ioepoch = attrs->som_ioepoch;
msd->msd_size = attrs->som_size;
msd->msd_blocks = attrs->som_blocks;
msd->msd_mountid = attrs->som_mountid;
RETURN(0);
}
void lustre_hsm_swab(struct hsm_attrs *attrs)
{
if (LUSTRE_MSG_MAGIC != cpu_to_le32(LUSTRE_MSG_MAGIC)) {
__swab32s(&attrs->hsm_compat);
__swab32s(&attrs->hsm_flags);
__swab64s(&attrs->hsm_arch_id);
__swab64s(&attrs->hsm_arch_ver);
}
}
int lustre_buf2hsm(void *buf, int rc, struct md_hsm *mh)
{
struct hsm_attrs *attrs = (struct hsm_attrs *)buf;
ENTRY;
if (rc == 0 || rc == -ENODATA)
RETURN(-ENODATA);
if (rc < 0)
RETURN(rc);
lustre_hsm_swab(attrs);
mh->mh_compat = attrs->hsm_compat;
mh->mh_flags = attrs->hsm_flags;
mh->mh_arch_id = attrs->hsm_arch_id;
mh->mh_arch_ver = attrs->hsm_arch_ver;
RETURN(0);
}
void lustre_hsm2buf(void *buf, struct md_hsm *mh)
{
struct hsm_attrs *attrs = (struct hsm_attrs *)buf;
ENTRY;
attrs->hsm_compat = mh->mh_compat;
attrs->hsm_flags = mh->mh_flags;
attrs->hsm_arch_id = mh->mh_arch_id;
attrs->hsm_arch_ver = mh->mh_arch_ver;
lustre_hsm_swab(attrs);
}
