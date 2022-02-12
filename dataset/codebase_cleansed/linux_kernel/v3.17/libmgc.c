static int mgc_setup(struct obd_device *obd, struct lustre_cfg *lcfg)
{
int rc;
ptlrpcd_addref();
rc = client_obd_setup(obd, lcfg);
if (rc)
GOTO(err_decref, rc);
obd->u.cli.cl_flvr_mgc.sf_rpc = SPTLRPC_FLVR_NULL;
rc = obd_llog_init(obd, &obd->obd_olg, obd, NULL);
if (rc) {
CERROR("failed to setup llogging subsystems\n");
GOTO(err_cleanup, rc);
}
return rc;
err_cleanup:
client_obd_cleanup(obd);
err_decref:
ptlrpcd_decref();
return rc;
}
static int mgc_precleanup(struct obd_device *obd, enum obd_cleanup_stage stage)
{
int rc = 0;
switch (stage) {
case OBD_CLEANUP_EARLY:
case OBD_CLEANUP_EXPORTS:
obd_cleanup_client_import(obd);
rc = obd_llog_finish(obd, 0);
if (rc != 0)
CERROR("failed to cleanup llogging subsystems\n");
break;
}
return rc;
}
static int mgc_cleanup(struct obd_device *obd)
{
int rc;
ptlrpcd_decref();
rc = client_obd_cleanup(obd);
return rc;
}
static int mgc_llog_init(struct obd_device *obd, struct obd_llog_group *olg,
struct obd_device *tgt, int *index)
{
struct llog_ctxt *ctxt;
int rc;
LASSERT(olg == &obd->obd_olg);
rc = llog_setup(NULL, obd, olg, LLOG_CONFIG_REPL_CTXT, tgt,
&llog_client_ops);
if (rc < 0)
return rc;
ctxt = llog_group_get_ctxt(olg, LLOG_CONFIG_REPL_CTXT);
llog_initiator_connect(ctxt);
llog_ctxt_put(ctxt);
return rc;
}
static int mgc_llog_finish(struct obd_device *obd, int count)
{
struct llog_ctxt *ctxt;
ctxt = llog_get_context(obd, LLOG_CONFIG_REPL_CTXT);
if (ctxt)
llog_cleanup(NULL, ctxt);
return 0;
}
int __init mgc_init(void)
{
return class_register_type(&mgc_obd_ops, NULL,
NULL, LUSTRE_MGC_NAME, NULL);
}
