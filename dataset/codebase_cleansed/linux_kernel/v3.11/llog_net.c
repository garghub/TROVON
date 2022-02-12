int llog_initiator_connect(struct llog_ctxt *ctxt)
{
struct obd_import *new_imp;
ENTRY;
LASSERT(ctxt);
new_imp = ctxt->loc_obd->u.cli.cl_import;
LASSERTF(ctxt->loc_imp == NULL || ctxt->loc_imp == new_imp,
"%p - %p\n", ctxt->loc_imp, new_imp);
mutex_lock(&ctxt->loc_mutex);
if (ctxt->loc_imp != new_imp) {
if (ctxt->loc_imp)
class_import_put(ctxt->loc_imp);
ctxt->loc_imp = class_import_get(new_imp);
}
mutex_unlock(&ctxt->loc_mutex);
RETURN(0);
}
