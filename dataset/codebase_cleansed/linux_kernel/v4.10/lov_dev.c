static void *lov_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct lov_thread_info *info;
info = kmem_cache_zalloc(lov_thread_kmem, GFP_NOFS);
if (!info)
info = ERR_PTR(-ENOMEM);
return info;
}
static void lov_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct lov_thread_info *info = data;
kmem_cache_free(lov_thread_kmem, info);
}
static void *lov_session_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct lov_session *info;
info = kmem_cache_zalloc(lov_session_kmem, GFP_NOFS);
if (!info)
info = ERR_PTR(-ENOMEM);
return info;
}
static void lov_session_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct lov_session *info = data;
kmem_cache_free(lov_session_kmem, info);
}
static struct lu_device *lov_device_fini(const struct lu_env *env,
struct lu_device *d)
{
int i;
struct lov_device *ld = lu2lov_dev(d);
LASSERT(ld->ld_lov);
if (!ld->ld_target)
return NULL;
lov_foreach_target(ld, i) {
struct lovsub_device *lsd;
lsd = ld->ld_target[i];
if (lsd) {
cl_stack_fini(env, lovsub2cl_dev(lsd));
ld->ld_target[i] = NULL;
}
}
return NULL;
}
static int lov_device_init(const struct lu_env *env, struct lu_device *d,
const char *name, struct lu_device *next)
{
struct lov_device *ld = lu2lov_dev(d);
int i;
int rc = 0;
LASSERT(d->ld_site);
if (!ld->ld_target)
return rc;
lov_foreach_target(ld, i) {
struct lovsub_device *lsd;
struct cl_device *cl;
struct lov_tgt_desc *desc;
desc = ld->ld_lov->lov_tgts[i];
if (!desc)
continue;
cl = cl_type_setup(env, d->ld_site, &lovsub_device_type,
desc->ltd_obd->obd_lu_dev);
if (IS_ERR(cl)) {
rc = PTR_ERR(cl);
break;
}
lsd = cl2lovsub_dev(cl);
lsd->acid_idx = i;
lsd->acid_super = ld;
ld->ld_target[i] = lsd;
}
if (rc)
lov_device_fini(env, d);
else
ld->ld_flags |= LOV_DEV_INITIALIZED;
return rc;
}
static void lov_emerg_free(struct lov_device_emerg **emrg, int nr)
{
int i;
for (i = 0; i < nr; ++i) {
struct lov_device_emerg *em;
em = emrg[i];
if (em) {
LASSERT(em->emrg_page_list.pl_nr == 0);
if (em->emrg_env)
cl_env_put(em->emrg_env, &em->emrg_refcheck);
kfree(em);
}
}
kfree(emrg);
}
static struct lu_device *lov_device_free(const struct lu_env *env,
struct lu_device *d)
{
struct lov_device *ld = lu2lov_dev(d);
const int nr = ld->ld_target_nr;
cl_device_fini(lu2cl_dev(d));
kfree(ld->ld_target);
if (ld->ld_emrg)
lov_emerg_free(ld->ld_emrg, nr);
kfree(ld);
return NULL;
}
static void lov_cl_del_target(const struct lu_env *env, struct lu_device *dev,
__u32 index)
{
struct lov_device *ld = lu2lov_dev(dev);
if (ld->ld_target[index]) {
cl_stack_fini(env, lovsub2cl_dev(ld->ld_target[index]));
ld->ld_target[index] = NULL;
}
}
static struct lov_device_emerg **lov_emerg_alloc(int nr)
{
struct lov_device_emerg **emerg;
int i;
int result;
emerg = kcalloc(nr, sizeof(emerg[0]), GFP_NOFS);
if (!emerg)
return ERR_PTR(-ENOMEM);
for (result = i = 0; i < nr && result == 0; i++) {
struct lov_device_emerg *em;
em = kzalloc(sizeof(*em), GFP_NOFS);
if (em) {
emerg[i] = em;
cl_page_list_init(&em->emrg_page_list);
em->emrg_env = cl_env_alloc(&em->emrg_refcheck,
LCT_REMEMBER | LCT_NOREF);
if (!IS_ERR(em->emrg_env)) {
em->emrg_env->le_ctx.lc_cookie = 0x2;
} else {
result = PTR_ERR(em->emrg_env);
em->emrg_env = NULL;
}
} else {
result = -ENOMEM;
}
}
if (result != 0) {
lov_emerg_free(emerg, nr);
emerg = ERR_PTR(result);
}
return emerg;
}
static int lov_expand_targets(const struct lu_env *env, struct lov_device *dev)
{
int result;
__u32 tgt_size;
__u32 sub_size;
result = 0;
tgt_size = dev->ld_lov->lov_tgt_size;
sub_size = dev->ld_target_nr;
if (sub_size < tgt_size) {
struct lovsub_device **newd;
struct lov_device_emerg **emerg;
const size_t sz = sizeof(newd[0]);
emerg = lov_emerg_alloc(tgt_size);
if (IS_ERR(emerg))
return PTR_ERR(emerg);
newd = kcalloc(tgt_size, sz, GFP_NOFS);
if (newd) {
mutex_lock(&dev->ld_mutex);
if (sub_size > 0) {
memcpy(newd, dev->ld_target, sub_size * sz);
kfree(dev->ld_target);
}
dev->ld_target = newd;
dev->ld_target_nr = tgt_size;
if (dev->ld_emrg)
lov_emerg_free(dev->ld_emrg, sub_size);
dev->ld_emrg = emerg;
mutex_unlock(&dev->ld_mutex);
} else {
lov_emerg_free(emerg, tgt_size);
result = -ENOMEM;
}
}
return result;
}
static int lov_cl_add_target(const struct lu_env *env, struct lu_device *dev,
__u32 index)
{
struct obd_device *obd = dev->ld_obd;
struct lov_device *ld = lu2lov_dev(dev);
struct lov_tgt_desc *tgt;
struct lovsub_device *lsd;
struct cl_device *cl;
int rc;
obd_getref(obd);
tgt = obd->u.lov.lov_tgts[index];
if (!tgt->ltd_obd->obd_set_up) {
CERROR("Target %s not set up\n", obd_uuid2str(&tgt->ltd_uuid));
return -EINVAL;
}
rc = lov_expand_targets(env, ld);
if (rc == 0 && ld->ld_flags & LOV_DEV_INITIALIZED) {
LASSERT(dev->ld_site);
cl = cl_type_setup(env, dev->ld_site, &lovsub_device_type,
tgt->ltd_obd->obd_lu_dev);
if (!IS_ERR(cl)) {
lsd = cl2lovsub_dev(cl);
lsd->acid_idx = index;
lsd->acid_super = ld;
ld->ld_target[index] = lsd;
} else {
CERROR("add failed (%d), deleting %s\n", rc,
obd_uuid2str(&tgt->ltd_uuid));
lov_cl_del_target(env, dev, index);
rc = PTR_ERR(cl);
}
}
obd_putref(obd);
return rc;
}
static int lov_process_config(const struct lu_env *env,
struct lu_device *d, struct lustre_cfg *cfg)
{
struct obd_device *obd = d->ld_obd;
int cmd;
int rc;
int gen;
__u32 index;
obd_getref(obd);
cmd = cfg->lcfg_command;
rc = lov_process_config_base(d->ld_obd, cfg, &index, &gen);
if (rc == 0) {
switch (cmd) {
case LCFG_LOV_ADD_OBD:
case LCFG_LOV_ADD_INA:
rc = lov_cl_add_target(env, d, index);
if (rc != 0)
lov_del_target(d->ld_obd, index, NULL, 0);
break;
case LCFG_LOV_DEL_OBD:
lov_cl_del_target(env, d, index);
break;
}
}
obd_putref(obd);
return rc;
}
static struct lu_device *lov_device_alloc(const struct lu_env *env,
struct lu_device_type *t,
struct lustre_cfg *cfg)
{
struct lu_device *d;
struct lov_device *ld;
struct obd_device *obd;
int rc;
ld = kzalloc(sizeof(*ld), GFP_NOFS);
if (!ld)
return ERR_PTR(-ENOMEM);
cl_device_init(&ld->ld_cl, t);
d = lov2lu_dev(ld);
d->ld_ops = &lov_lu_ops;
mutex_init(&ld->ld_mutex);
lockdep_set_class(&ld->ld_mutex, &cl_lov_device_mutex_class);
obd = class_name2obd(lustre_cfg_string(cfg, 0));
LASSERT(obd);
rc = lov_setup(obd, cfg);
if (rc) {
lov_device_free(env, d);
return ERR_PTR(rc);
}
ld->ld_lov = &obd->u.lov;
return d;
}
