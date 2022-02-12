static void lov_req_completion(const struct lu_env *env,
const struct cl_req_slice *slice, int ioret)
{
struct lov_req *lr;
lr = cl2lov_req(slice);
OBD_SLAB_FREE_PTR(lr, lov_req_kmem);
}
static void *lov_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct lov_thread_info *info;
OBD_SLAB_ALLOC_PTR_GFP(info, lov_thread_kmem, GFP_NOFS);
if (info != NULL)
INIT_LIST_HEAD(&info->lti_closure.clc_list);
else
info = ERR_PTR(-ENOMEM);
return info;
}
static void lov_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct lov_thread_info *info = data;
LINVRNT(list_empty(&info->lti_closure.clc_list));
OBD_SLAB_FREE_PTR(info, lov_thread_kmem);
}
static void *lov_session_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct lov_session *info;
OBD_SLAB_ALLOC_PTR_GFP(info, lov_session_kmem, GFP_NOFS);
if (info == NULL)
info = ERR_PTR(-ENOMEM);
return info;
}
static void lov_session_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct lov_session *info = data;
OBD_SLAB_FREE_PTR(info, lov_session_kmem);
}
static struct lu_device *lov_device_fini(const struct lu_env *env,
struct lu_device *d)
{
int i;
struct lov_device *ld = lu2lov_dev(d);
LASSERT(ld->ld_lov != NULL);
if (ld->ld_target == NULL)
return NULL;
lov_foreach_target(ld, i) {
struct lovsub_device *lsd;
lsd = ld->ld_target[i];
if (lsd != NULL) {
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
LASSERT(d->ld_site != NULL);
if (ld->ld_target == NULL)
return rc;
lov_foreach_target(ld, i) {
struct lovsub_device *lsd;
struct cl_device *cl;
struct lov_tgt_desc *desc;
desc = ld->ld_lov->lov_tgts[i];
if (desc == NULL)
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
static int lov_req_init(const struct lu_env *env, struct cl_device *dev,
struct cl_req *req)
{
struct lov_req *lr;
int result;
OBD_SLAB_ALLOC_PTR_GFP(lr, lov_req_kmem, GFP_NOFS);
if (lr != NULL) {
cl_req_slice_add(req, &lr->lr_cl, dev, &lov_req_ops);
result = 0;
} else
result = -ENOMEM;
return result;
}
static void lov_emerg_free(struct lov_device_emerg **emrg, int nr)
{
int i;
for (i = 0; i < nr; ++i) {
struct lov_device_emerg *em;
em = emrg[i];
if (em != NULL) {
LASSERT(em->emrg_page_list.pl_nr == 0);
if (em->emrg_env != NULL)
cl_env_put(em->emrg_env, &em->emrg_refcheck);
OBD_FREE_PTR(em);
}
}
OBD_FREE(emrg, nr * sizeof(emrg[0]));
}
static struct lu_device *lov_device_free(const struct lu_env *env,
struct lu_device *d)
{
struct lov_device *ld = lu2lov_dev(d);
const int nr = ld->ld_target_nr;
cl_device_fini(lu2cl_dev(d));
if (ld->ld_target != NULL)
OBD_FREE(ld->ld_target, nr * sizeof(ld->ld_target[0]));
if (ld->ld_emrg != NULL)
lov_emerg_free(ld->ld_emrg, nr);
OBD_FREE_PTR(ld);
return NULL;
}
static void lov_cl_del_target(const struct lu_env *env, struct lu_device *dev,
__u32 index)
{
struct lov_device *ld = lu2lov_dev(dev);
if (ld->ld_target[index] != NULL) {
cl_stack_fini(env, lovsub2cl_dev(ld->ld_target[index]));
ld->ld_target[index] = NULL;
}
}
static struct lov_device_emerg **lov_emerg_alloc(int nr)
{
struct lov_device_emerg **emerg;
int i;
int result;
OBD_ALLOC(emerg, nr * sizeof(emerg[0]));
if (emerg == NULL)
return ERR_PTR(-ENOMEM);
for (result = i = 0; i < nr && result == 0; i++) {
struct lov_device_emerg *em;
OBD_ALLOC_PTR(em);
if (em != NULL) {
emerg[i] = em;
cl_page_list_init(&em->emrg_page_list);
em->emrg_env = cl_env_alloc(&em->emrg_refcheck,
LCT_REMEMBER|LCT_NOREF);
if (!IS_ERR(em->emrg_env))
em->emrg_env->le_ctx.lc_cookie = 0x2;
else {
result = PTR_ERR(em->emrg_env);
em->emrg_env = NULL;
}
} else
result = -ENOMEM;
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
OBD_ALLOC(newd, tgt_size * sz);
if (newd != NULL) {
mutex_lock(&dev->ld_mutex);
if (sub_size > 0) {
memcpy(newd, dev->ld_target, sub_size * sz);
OBD_FREE(dev->ld_target, sub_size * sz);
}
dev->ld_target = newd;
dev->ld_target_nr = tgt_size;
if (dev->ld_emrg != NULL)
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
LASSERT(tgt != NULL);
LASSERT(tgt->ltd_obd != NULL);
if (!tgt->ltd_obd->obd_set_up) {
CERROR("Target %s not set up\n", obd_uuid2str(&tgt->ltd_uuid));
return -EINVAL;
}
rc = lov_expand_targets(env, ld);
if (rc == 0 && ld->ld_flags & LOV_DEV_INITIALIZED) {
LASSERT(dev->ld_site != NULL);
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
OBD_ALLOC_PTR(ld);
if (ld == NULL)
return ERR_PTR(-ENOMEM);
cl_device_init(&ld->ld_cl, t);
d = lov2lu_dev(ld);
d->ld_ops = &lov_lu_ops;
ld->ld_cl.cd_ops = &lov_cl_ops;
mutex_init(&ld->ld_mutex);
lockdep_set_class(&ld->ld_mutex, &cl_lov_device_mutex_class);
obd = class_name2obd(lustre_cfg_string(cfg, 0));
LASSERT(obd != NULL);
rc = lov_setup(obd, cfg);
if (rc) {
lov_device_free(env, d);
return ERR_PTR(rc);
}
ld->ld_lov = &obd->u.lov;
return d;
}
