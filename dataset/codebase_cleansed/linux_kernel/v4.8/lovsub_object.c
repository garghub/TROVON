int lovsub_object_init(const struct lu_env *env, struct lu_object *obj,
const struct lu_object_conf *conf)
{
struct lovsub_device *dev = lu2lovsub_dev(obj->lo_dev);
struct lu_object *below;
struct lu_device *under;
int result;
under = &dev->acid_next->cd_lu_dev;
below = under->ld_ops->ldo_object_alloc(env, obj->lo_header, under);
if (below) {
lu_object_add(obj, below);
cl_object_page_init(lu2cl(obj), sizeof(struct lovsub_page));
result = 0;
} else {
result = -ENOMEM;
}
return result;
}
static void lovsub_object_free(const struct lu_env *env, struct lu_object *obj)
{
struct lovsub_object *los = lu2lovsub(obj);
struct lov_object *lov = los->lso_super;
if (lov) {
LASSERT(lov->lo_type == LLT_RAID0);
LASSERT(lov->u.raid0.lo_sub[los->lso_index] == los);
spin_lock(&lov->u.raid0.lo_sub_lock);
lov->u.raid0.lo_sub[los->lso_index] = NULL;
spin_unlock(&lov->u.raid0.lo_sub_lock);
}
lu_object_fini(obj);
lu_object_header_fini(&los->lso_header.coh_lu);
kmem_cache_free(lovsub_object_kmem, los);
}
static int lovsub_object_print(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct lu_object *obj)
{
struct lovsub_object *los = lu2lovsub(obj);
return (*p)(env, cookie, "[%d]", los->lso_index);
}
static int lovsub_attr_set(const struct lu_env *env, struct cl_object *obj,
const struct cl_attr *attr, unsigned valid)
{
struct lov_object *lov = cl2lovsub(obj)->lso_super;
lov_r0(lov)->lo_attr_valid = 0;
return 0;
}
static int lovsub_object_glimpse(const struct lu_env *env,
const struct cl_object *obj,
struct ost_lvb *lvb)
{
struct lovsub_object *los = cl2lovsub(obj);
return cl_object_glimpse(env, &los->lso_super->lo_cl, lvb);
}
struct lu_object *lovsub_object_alloc(const struct lu_env *env,
const struct lu_object_header *unused,
struct lu_device *dev)
{
struct lovsub_object *los;
struct lu_object *obj;
los = kmem_cache_zalloc(lovsub_object_kmem, GFP_NOFS);
if (los) {
struct cl_object_header *hdr;
obj = lovsub2lu(los);
hdr = &los->lso_header;
cl_object_header_init(hdr);
lu_object_init(obj, &hdr->coh_lu, dev);
lu_object_add_top(&hdr->coh_lu, obj);
los->lso_cl.co_ops = &lovsub_ops;
obj->lo_ops = &lovsub_lu_obj_ops;
} else {
obj = NULL;
}
return obj;
}
