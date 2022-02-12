static int lovsub_device_init(const struct lu_env *env, struct lu_device *d,
const char *name, struct lu_device *next)
{
struct lovsub_device *lsd = lu2lovsub_dev(d);
struct lu_device_type *ldt;
int rc;
next->ld_site = d->ld_site;
ldt = next->ld_type;
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
kfree(lsd);
return next;
}
static struct lu_device *lovsub_device_alloc(const struct lu_env *env,
struct lu_device_type *t,
struct lustre_cfg *cfg)
{
struct lu_device *d;
struct lovsub_device *lsd;
lsd = kzalloc(sizeof(*lsd), GFP_NOFS);
if (lsd) {
int result;
result = cl_device_init(&lsd->acid_cl, t);
if (result == 0) {
d = lovsub2lu_dev(lsd);
d->ld_ops = &lovsub_lu_ops;
} else {
d = ERR_PTR(result);
}
} else {
d = ERR_PTR(-ENOMEM);
}
return d;
}
