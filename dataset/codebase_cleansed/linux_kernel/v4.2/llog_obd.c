static struct llog_ctxt *llog_new_ctxt(struct obd_device *obd)
{
struct llog_ctxt *ctxt;
ctxt = kzalloc(sizeof(*ctxt), GFP_NOFS);
if (!ctxt)
return NULL;
ctxt->loc_obd = obd;
atomic_set(&ctxt->loc_refcount, 1);
return ctxt;
}
static void llog_ctxt_destroy(struct llog_ctxt *ctxt)
{
if (ctxt->loc_exp) {
class_export_put(ctxt->loc_exp);
ctxt->loc_exp = NULL;
}
if (ctxt->loc_imp) {
class_import_put(ctxt->loc_imp);
ctxt->loc_imp = NULL;
}
kfree(ctxt);
}
int __llog_ctxt_put(const struct lu_env *env, struct llog_ctxt *ctxt)
{
struct obd_llog_group *olg = ctxt->loc_olg;
struct obd_device *obd;
int rc = 0;
spin_lock(&olg->olg_lock);
if (!atomic_dec_and_test(&ctxt->loc_refcount)) {
spin_unlock(&olg->olg_lock);
return rc;
}
olg->olg_ctxts[ctxt->loc_idx] = NULL;
spin_unlock(&olg->olg_lock);
obd = ctxt->loc_obd;
spin_lock(&obd->obd_dev_lock);
spin_unlock(&obd->obd_dev_lock);
LASSERTF(obd->obd_starting == 1 ||
obd->obd_stopping == 1 || obd->obd_set_up == 0,
"wrong obd state: %d/%d/%d\n", !!obd->obd_starting,
!!obd->obd_stopping, !!obd->obd_set_up);
if (CTXTP(ctxt, cleanup))
rc = CTXTP(ctxt, cleanup)(env, ctxt);
llog_ctxt_destroy(ctxt);
wake_up(&olg->olg_waitq);
return rc;
}
int llog_cleanup(const struct lu_env *env, struct llog_ctxt *ctxt)
{
struct l_wait_info lwi = LWI_INTR(LWI_ON_SIGNAL_NOOP, NULL);
struct obd_llog_group *olg;
int rc, idx;
LASSERT(ctxt != NULL);
LASSERT(ctxt != LP_POISON);
olg = ctxt->loc_olg;
LASSERT(olg != NULL);
LASSERT(olg != LP_POISON);
idx = ctxt->loc_idx;
LASSERT(atomic_read(&ctxt->loc_refcount) < LI_POISON);
LASSERT(atomic_read(&ctxt->loc_refcount) > 1);
llog_ctxt_put(ctxt);
rc = __llog_ctxt_put(env, ctxt);
if (rc)
CERROR("Error %d while cleaning up ctxt %p\n",
rc, ctxt);
l_wait_event(olg->olg_waitq,
llog_group_ctxt_null(olg, idx), &lwi);
return rc;
}
int llog_setup(const struct lu_env *env, struct obd_device *obd,
struct obd_llog_group *olg, int index,
struct obd_device *disk_obd, struct llog_operations *op)
{
struct llog_ctxt *ctxt;
int rc = 0;
if (index < 0 || index >= LLOG_MAX_CTXTS)
return -EINVAL;
LASSERT(olg != NULL);
ctxt = llog_new_ctxt(obd);
if (!ctxt)
return -ENOMEM;
ctxt->loc_obd = obd;
ctxt->loc_olg = olg;
ctxt->loc_idx = index;
ctxt->loc_logops = op;
mutex_init(&ctxt->loc_mutex);
ctxt->loc_exp = class_export_get(disk_obd->obd_self_export);
ctxt->loc_flags = LLOG_CTXT_FLAG_UNINITIALIZED;
rc = llog_group_set_ctxt(olg, ctxt, index);
if (rc) {
llog_ctxt_destroy(ctxt);
if (rc == -EEXIST) {
ctxt = llog_group_get_ctxt(olg, index);
if (ctxt) {
CDEBUG(D_CONFIG, "obd %s ctxt %d already set up\n",
obd->obd_name, index);
LASSERT(ctxt->loc_olg == olg);
LASSERT(ctxt->loc_obd == obd);
LASSERT(ctxt->loc_exp == disk_obd->obd_self_export);
LASSERT(ctxt->loc_logops == op);
llog_ctxt_put(ctxt);
}
rc = 0;
}
return rc;
}
if (op->lop_setup) {
if (OBD_FAIL_CHECK(OBD_FAIL_OBD_LLOG_SETUP))
rc = -EOPNOTSUPP;
else
rc = op->lop_setup(env, obd, olg, index, disk_obd);
}
if (rc) {
CERROR("%s: ctxt %d lop_setup=%p failed: rc = %d\n",
obd->obd_name, index, op->lop_setup, rc);
llog_group_clear_ctxt(olg, index);
llog_ctxt_destroy(ctxt);
} else {
CDEBUG(D_CONFIG, "obd %s ctxt %d is initialized\n",
obd->obd_name, index);
ctxt->loc_flags &= ~LLOG_CTXT_FLAG_UNINITIALIZED;
}
return rc;
}
int llog_sync(struct llog_ctxt *ctxt, struct obd_export *exp, int flags)
{
int rc = 0;
if (!ctxt)
return 0;
if (CTXTP(ctxt, sync))
rc = CTXTP(ctxt, sync)(ctxt, exp, flags);
return rc;
}
int llog_cancel(const struct lu_env *env, struct llog_ctxt *ctxt,
struct llog_cookie *cookies, int flags)
{
int rc;
if (!ctxt) {
CERROR("No ctxt\n");
return -ENODEV;
}
CTXT_CHECK_OP(ctxt, cancel, -EOPNOTSUPP);
rc = CTXTP(ctxt, cancel)(env, ctxt, cookies, flags);
return rc;
}
int llog_info_init(void)
{
llog_key_init_generic(&llog_thread_key, NULL);
lu_context_key_register(&llog_thread_key);
return 0;
}
void llog_info_fini(void)
{
lu_context_key_degister(&llog_thread_key);
}
