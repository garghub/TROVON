int cl_init_ea_size(struct obd_export *md_exp, struct obd_export *dt_exp)
{
struct lov_stripe_md lsm = { .lsm_magic = LOV_MAGIC_V3 };
__u32 valsize = sizeof(struct lov_desc);
int rc, easize, def_easize, cookiesize;
struct lov_desc desc;
__u16 stripes, def_stripes;
rc = obd_get_info(NULL, dt_exp, sizeof(KEY_LOVDESC), KEY_LOVDESC,
&valsize, &desc, NULL);
if (rc)
return rc;
stripes = min_t(__u32, desc.ld_tgt_count, LOV_MAX_STRIPE_COUNT);
lsm.lsm_stripe_count = stripes;
easize = obd_size_diskmd(dt_exp, &lsm);
def_stripes = min_t(__u32, desc.ld_default_stripe_count,
LOV_MAX_STRIPE_COUNT);
lsm.lsm_stripe_count = def_stripes;
def_easize = obd_size_diskmd(dt_exp, &lsm);
cookiesize = stripes * sizeof(struct llog_cookie);
CDEBUG(D_HA,
"updating def/max_easize: %d/%d def/max_cookiesize: 0/%d\n",
def_easize, easize, cookiesize);
rc = md_init_ea_size(md_exp, easize, def_easize, cookiesize, 0);
return rc;
}
int cl_ocd_update(struct obd_device *host,
struct obd_device *watched,
enum obd_notify_event ev, void *owner, void *data)
{
struct lustre_client_ocd *lco;
struct client_obd *cli;
__u64 flags;
int result;
if (!strcmp(watched->obd_type->typ_name, LUSTRE_OSC_NAME)) {
cli = &watched->u.cli;
lco = owner;
flags = cli->cl_import->imp_connect_data.ocd_connect_flags;
CDEBUG(D_SUPER, "Changing connect_flags: %#llx -> %#llx\n",
lco->lco_flags, flags);
mutex_lock(&lco->lco_lock);
lco->lco_flags &= flags;
if (lco->lco_dt_exp)
cl_init_ea_size(lco->lco_md_exp, lco->lco_dt_exp);
mutex_unlock(&lco->lco_lock);
result = 0;
} else {
CERROR("unexpected notification from %s %s!\n",
watched->obd_type->typ_name,
watched->obd_name);
result = -EINVAL;
}
return result;
}
int cl_get_grouplock(struct cl_object *obj, unsigned long gid, int nonblock,
struct ccc_grouplock *cg)
{
struct lu_env *env;
struct cl_io *io;
struct cl_lock *lock;
struct cl_lock_descr *descr;
__u32 enqflags;
int refcheck;
int rc;
env = cl_env_get(&refcheck);
if (IS_ERR(env))
return PTR_ERR(env);
io = ccc_env_thread_io(env);
io->ci_obj = obj;
io->ci_ignore_layout = 1;
rc = cl_io_init(env, io, CIT_MISC, io->ci_obj);
if (rc) {
if (rc > 0)
rc = -ENOTSUPP;
cl_env_put(env, &refcheck);
return rc;
}
descr = &ccc_env_info(env)->cti_descr;
descr->cld_obj = obj;
descr->cld_start = 0;
descr->cld_end = CL_PAGE_EOF;
descr->cld_gid = gid;
descr->cld_mode = CLM_GROUP;
enqflags = CEF_MUST | (nonblock ? CEF_NONBLOCK : 0);
descr->cld_enq_flags = enqflags;
lock = cl_lock_request(env, io, descr, GROUPLOCK_SCOPE, current);
if (IS_ERR(lock)) {
cl_io_fini(env, io);
cl_env_put(env, &refcheck);
return PTR_ERR(lock);
}
cg->cg_env = cl_env_get(&refcheck);
cg->cg_io = io;
cg->cg_lock = lock;
cg->cg_gid = gid;
LASSERT(cg->cg_env == env);
cl_env_unplant(env, &refcheck);
return 0;
}
void cl_put_grouplock(struct ccc_grouplock *cg)
{
struct lu_env *env = cg->cg_env;
struct cl_io *io = cg->cg_io;
struct cl_lock *lock = cg->cg_lock;
int refcheck;
LASSERT(cg->cg_env);
LASSERT(cg->cg_gid);
cl_env_implant(env, &refcheck);
cl_env_put(env, &refcheck);
cl_unuse(env, lock);
cl_lock_release(env, lock, GROUPLOCK_SCOPE, current);
cl_io_fini(env, io);
cl_env_put(env, NULL);
}
