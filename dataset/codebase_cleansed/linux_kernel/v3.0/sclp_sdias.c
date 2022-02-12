static void sdias_callback(struct sclp_req *request, void *data)
{
sclp_req_done = 1;
wake_up(&sdias_wq);
TRACE("callback done\n");
}
static int sdias_sclp_send(struct sclp_req *req)
{
int retries;
int rc;
for (retries = SDIAS_RETRIES; retries; retries--) {
sclp_req_done = 0;
TRACE("add request\n");
rc = sclp_add_request(req);
if (rc) {
set_current_state(TASK_INTERRUPTIBLE);
TRACE("add request failed: rc = %i\n",rc);
schedule_timeout(SDIAS_SLEEP_TICKS);
continue;
}
wait_event(sdias_wq, (sclp_req_done == 1));
if (req->status == SCLP_REQ_FAILED) {
TRACE("sclp request failed\n");
rc = -EIO;
continue;
}
TRACE("request done\n");
break;
}
return rc;
}
int sclp_sdias_blk_count(void)
{
struct sclp_req request;
int rc;
mutex_lock(&sdias_mutex);
memset(&sccb, 0, sizeof(sccb));
memset(&request, 0, sizeof(request));
sccb.hdr.length = sizeof(sccb);
sccb.evbuf.hdr.length = sizeof(struct sdias_evbuf);
sccb.evbuf.hdr.type = EVTYP_SDIAS;
sccb.evbuf.event_qual = EQ_SIZE;
sccb.evbuf.data_id = DI_FCP_DUMP;
sccb.evbuf.event_id = 4712;
sccb.evbuf.dbs = 1;
request.sccb = &sccb;
request.command = SCLP_CMDW_WRITE_EVENT_DATA;
request.status = SCLP_REQ_FILLED;
request.callback = sdias_callback;
rc = sdias_sclp_send(&request);
if (rc) {
pr_err("sclp_send failed for get_nr_blocks\n");
goto out;
}
if (sccb.hdr.response_code != 0x0020) {
TRACE("send failed: %x\n", sccb.hdr.response_code);
rc = -EIO;
goto out;
}
switch (sccb.evbuf.event_status) {
case 0:
rc = sccb.evbuf.blk_cnt;
break;
default:
pr_err("SCLP error: %x\n",
sccb.evbuf.event_status);
rc = -EIO;
goto out;
}
TRACE("%i blocks\n", rc);
out:
mutex_unlock(&sdias_mutex);
return rc;
}
int sclp_sdias_copy(void *dest, int start_blk, int nr_blks)
{
struct sclp_req request;
int rc;
mutex_lock(&sdias_mutex);
memset(&sccb, 0, sizeof(sccb));
memset(&request, 0, sizeof(request));
sccb.hdr.length = sizeof(sccb);
sccb.evbuf.hdr.length = sizeof(struct sdias_evbuf);
sccb.evbuf.hdr.type = EVTYP_SDIAS;
sccb.evbuf.hdr.flags = 0;
sccb.evbuf.event_qual = EQ_STORE_DATA;
sccb.evbuf.data_id = DI_FCP_DUMP;
sccb.evbuf.event_id = 4712;
#ifdef __s390x__
sccb.evbuf.asa_size = ASA_SIZE_64;
#else
sccb.evbuf.asa_size = ASA_SIZE_32;
#endif
sccb.evbuf.event_status = 0;
sccb.evbuf.blk_cnt = nr_blks;
sccb.evbuf.asa = (unsigned long)dest;
sccb.evbuf.fbn = start_blk;
sccb.evbuf.lbn = 0;
sccb.evbuf.dbs = 1;
request.sccb = &sccb;
request.command = SCLP_CMDW_WRITE_EVENT_DATA;
request.status = SCLP_REQ_FILLED;
request.callback = sdias_callback;
rc = sdias_sclp_send(&request);
if (rc) {
pr_err("sclp_send failed: %x\n", rc);
goto out;
}
if (sccb.hdr.response_code != 0x0020) {
TRACE("copy failed: %x\n", sccb.hdr.response_code);
rc = -EIO;
goto out;
}
switch (sccb.evbuf.event_status) {
case EVSTATE_ALL_STORED:
TRACE("all stored\n");
case EVSTATE_PART_STORED:
TRACE("part stored: %i\n", sccb.evbuf.blk_cnt);
break;
case EVSTATE_NO_DATA:
TRACE("no data\n");
default:
pr_err("Error from SCLP while copying hsa. "
"Event status = %x\n",
sccb.evbuf.event_status);
rc = -EIO;
}
out:
mutex_unlock(&sdias_mutex);
return rc;
}
int __init sclp_sdias_init(void)
{
int rc;
if (ipl_info.type != IPL_TYPE_FCP_DUMP)
return 0;
sdias_dbf = debug_register("dump_sdias", 4, 1, 4 * sizeof(long));
debug_register_view(sdias_dbf, &debug_sprintf_view);
debug_set_level(sdias_dbf, 6);
rc = sclp_register(&sclp_sdias_register);
if (rc)
return rc;
init_waitqueue_head(&sdias_wq);
TRACE("init done\n");
return 0;
}
void __exit sclp_sdias_exit(void)
{
debug_unregister(sdias_dbf);
sclp_unregister(&sclp_sdias_register);
}
