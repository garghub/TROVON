static struct lu_device *osc2lu_dev(struct osc_device *osc)
{
return &osc->od_cl.cd_lu_dev;
}
static void *osc_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct osc_thread_info *info;
OBD_SLAB_ALLOC_PTR_GFP(info, osc_thread_kmem, GFP_NOFS);
if (info == NULL)
info = ERR_PTR(-ENOMEM);
return info;
}
static void osc_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct osc_thread_info *info = data;
OBD_SLAB_FREE_PTR(info, osc_thread_kmem);
}
static void *osc_session_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct osc_session *info;
OBD_SLAB_ALLOC_PTR_GFP(info, osc_session_kmem, GFP_NOFS);
if (info == NULL)
info = ERR_PTR(-ENOMEM);
return info;
}
static void osc_session_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct osc_session *info = data;
OBD_SLAB_FREE_PTR(info, osc_session_kmem);
}
static int osc_cl_process_config(const struct lu_env *env,
struct lu_device *d, struct lustre_cfg *cfg)
{
return osc_process_config_base(d->ld_obd, cfg);
}
static int osc_device_init(const struct lu_env *env, struct lu_device *d,
const char *name, struct lu_device *next)
{
return 0;
}
static struct lu_device *osc_device_fini(const struct lu_env *env,
struct lu_device *d)
{
return NULL;
}
static struct lu_device *osc_device_free(const struct lu_env *env,
struct lu_device *d)
{
struct osc_device *od = lu2osc_dev(d);
cl_device_fini(lu2cl_dev(d));
kfree(od);
return NULL;
}
static struct lu_device *osc_device_alloc(const struct lu_env *env,
struct lu_device_type *t,
struct lustre_cfg *cfg)
{
struct lu_device *d;
struct osc_device *od;
struct obd_device *obd;
int rc;
od = kzalloc(sizeof(*od), GFP_NOFS);
if (od == NULL)
return ERR_PTR(-ENOMEM);
cl_device_init(&od->od_cl, t);
d = osc2lu_dev(od);
d->ld_ops = &osc_lu_ops;
od->od_cl.cd_ops = &osc_cl_ops;
obd = class_name2obd(lustre_cfg_string(cfg, 0));
LASSERT(obd != NULL);
rc = osc_setup(obd, cfg);
if (rc) {
osc_device_free(env, d);
return ERR_PTR(rc);
}
od->od_exp = obd->obd_self_export;
return d;
}
