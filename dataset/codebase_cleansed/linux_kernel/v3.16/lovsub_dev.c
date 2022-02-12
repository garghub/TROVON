static void lovsub_req_completion(const struct lu_env *env,
const struct cl_req_slice *slice, int ioret)
{
struct lovsub_req *lsr;
lsr = cl2lovsub_req(slice);
OBD_SLAB_FREE_PTR(lsr, lovsub_req_kmem);
}
static void lovsub_req_attr_set(const struct lu_env *env,
const struct cl_req_slice *slice,
const struct cl_object *obj,
struct cl_req_attr *attr, obd_valid flags)
{
struct lovsub_object *subobj;
subobj = cl2lovsub(obj);
attr->cra_oa->o_stripe_idx = subobj->lso_index;
}
static int lovsub_device_init(const struct lu_env *env, struct lu_device *d,
const char *name, struct lu_device *next)
{
struct lovsub_device *lsd = lu2lovsub_dev(d);
struct lu_device_type *ldt;
int rc;
next->ld_site = d->ld_site;
ldt = next->ld_type;
LASSERT(ldt != NULL);
rc = ldt->ldt_ops->ldto_device_init(env, next, ldt->ldt_name, NULL);
if (rc) {
next->ld_site = NULL;
return rc;
}
lu_device_get(next);
lu_ref_add(&next->ld_reference, "lu-stack", &lu_site_init);
lsd->acid_next = lu2cl_dev(next);
return rc;
}
static struct lu_device *lovsub_device_fini(const struct lu_env *env,
struct lu_device *d)
{
struct lu_device *next;
struct lovsub_device *lsd;
lsd = lu2lovsub_dev(d);
next = cl2lu_dev(lsd->acid_next);
lsd->acid_super = NULL;
lsd->acid_next = NULL;
return next;
}
static struct lu_device *lovsub_device_free(const struct lu_env *env,
struct lu_device *d)
{
struct lovsub_device *lsd = lu2lovsub_dev(d);
struct lu_device *next = cl2lu_dev(lsd->acid_next);
if (atomic_read(&d->ld_ref) && d->ld_site) {
LIBCFS_DEBUG_MSG_DATA_DECL(msgdata, D_ERROR, NULL);
lu_site_print(env, d->ld_site, &msgdata, lu_cdebug_printer);
}
cl_device_fini(lu2cl_dev(d));
OBD_FREE_PTR(lsd);
return next;
}
static int lovsub_req_init(const struct lu_env *env, struct cl_device *dev,
struct cl_req *req)
{
struct lovsub_req *lsr;
int result;
OBD_SLAB_ALLOC_PTR_GFP(lsr, lovsub_req_kmem, GFP_NOFS);
if (lsr != NULL) {
cl_req_slice_add(req, &lsr->lsrq_cl, dev, &lovsub_req_ops);
result = 0;
} else
result = -ENOMEM;
return result;
}
static struct lu_device *lovsub_device_alloc(const struct lu_env *env,
struct lu_device_type *t,
struct lustre_cfg *cfg)
{
struct lu_device *d;
struct lovsub_device *lsd;
OBD_ALLOC_PTR(lsd);
if (lsd != NULL) {
int result;
result = cl_device_init(&lsd->acid_cl, t);
if (result == 0) {
d = lovsub2lu_dev(lsd);
d->ld_ops = &lovsub_lu_ops;
lsd->acid_cl.cd_ops = &lovsub_cl_ops;
} else
d = ERR_PTR(result);
} else
d = ERR_PTR(-ENOMEM);
return d;
}
