__init int ptlrpc_init(void)
{
int rc, cleanup_phase = 0;
lustre_assert_wire_constants();
#if RS_DEBUG
spin_lock_init(&ptlrpc_rs_debug_lock);
#endif
mutex_init(&ptlrpc_all_services_mutex);
mutex_init(&pinger_mutex);
mutex_init(&ptlrpcd_mutex);
ptlrpc_init_xid();
rc = req_layout_init();
if (rc)
return rc;
rc = ptlrpc_hr_init();
if (rc)
return rc;
cleanup_phase = 1;
rc = ptlrpc_request_cache_init();
if (rc)
GOTO(cleanup, rc);
cleanup_phase = 2;
rc = ptlrpc_init_portals();
if (rc)
GOTO(cleanup, rc);
cleanup_phase = 3;
rc = ptlrpc_connection_init();
if (rc)
GOTO(cleanup, rc);
cleanup_phase = 4;
ptlrpc_put_connection_superhack = ptlrpc_connection_put;
rc = ptlrpc_start_pinger();
if (rc)
GOTO(cleanup, rc);
cleanup_phase = 5;
rc = ldlm_init();
if (rc)
GOTO(cleanup, rc);
cleanup_phase = 6;
rc = sptlrpc_init();
if (rc)
GOTO(cleanup, rc);
cleanup_phase = 7;
rc = ptlrpc_nrs_init();
if (rc)
GOTO(cleanup, rc);
cleanup_phase = 8;
rc = tgt_mod_init();
if (rc)
GOTO(cleanup, rc);
return 0;
cleanup:
switch (cleanup_phase) {
case 8:
ptlrpc_nrs_fini();
case 7:
sptlrpc_fini();
case 6:
ldlm_exit();
case 5:
ptlrpc_stop_pinger();
case 4:
ptlrpc_connection_fini();
case 3:
ptlrpc_exit_portals();
case 2:
ptlrpc_request_cache_fini();
case 1:
ptlrpc_hr_fini();
req_layout_fini();
default: ;
}
return rc;
}
static void __exit ptlrpc_exit(void)
{
tgt_mod_exit();
ptlrpc_nrs_fini();
sptlrpc_fini();
ldlm_exit();
ptlrpc_stop_pinger();
ptlrpc_exit_portals();
ptlrpc_request_cache_fini();
ptlrpc_hr_fini();
ptlrpc_connection_fini();
}
