void request_out_callback(lnet_event_t *ev)
{
struct ptlrpc_cb_id *cbid = ev->md.user_ptr;
struct ptlrpc_request *req = cbid->cbid_arg;
bool wakeup = false;
LASSERT(ev->type == LNET_EVENT_SEND || ev->type == LNET_EVENT_UNLINK);
LASSERT(ev->unlinked);
DEBUG_REQ(D_NET, req, "type %d, status %d", ev->type, ev->status);
sptlrpc_request_out_callback(req);
spin_lock(&req->rq_lock);
req->rq_real_sent = ktime_get_real_seconds();
req->rq_req_unlinked = 1;
if (req->rq_reply_unlinked)
wakeup = true;
if (ev->type == LNET_EVENT_UNLINK || ev->status != 0) {
req->rq_net_err = 1;
wakeup = true;
}
if (wakeup)
ptlrpc_client_wake_req(req);
spin_unlock(&req->rq_lock);
ptlrpc_req_finished(req);
}
void reply_in_callback(lnet_event_t *ev)
{
struct ptlrpc_cb_id *cbid = ev->md.user_ptr;
struct ptlrpc_request *req = cbid->cbid_arg;
DEBUG_REQ(D_NET, req, "type %d, status %d", ev->type, ev->status);
LASSERT(ev->type == LNET_EVENT_PUT || ev->type == LNET_EVENT_UNLINK);
LASSERT(ev->md.start == req->rq_repbuf);
LASSERT(ev->offset + ev->mlength <= req->rq_repbuf_len);
LASSERT((ev->md.options & LNET_MD_MANAGE_REMOTE) != 0);
spin_lock(&req->rq_lock);
req->rq_receiving_reply = 0;
req->rq_early = 0;
if (ev->unlinked)
req->rq_reply_unlinked = 1;
if (ev->status)
goto out_wake;
if (ev->type == LNET_EVENT_UNLINK) {
LASSERT(ev->unlinked);
DEBUG_REQ(D_NET, req, "unlink");
goto out_wake;
}
if (ev->mlength < ev->rlength) {
CDEBUG(D_RPCTRACE, "truncate req %p rpc %d - %d+%d\n", req,
req->rq_replen, ev->rlength, ev->offset);
req->rq_reply_truncated = 1;
req->rq_replied = 1;
req->rq_status = -EOVERFLOW;
req->rq_nob_received = ev->rlength + ev->offset;
goto out_wake;
}
if ((ev->offset == 0) &&
((lustre_msghdr_get_flags(req->rq_reqmsg) & MSGHDR_AT_SUPPORT))) {
DEBUG_REQ(D_ADAPTTO, req,
"Early reply received: mlen=%u offset=%d replen=%d replied=%d unlinked=%d",
ev->mlength, ev->offset,
req->rq_replen, req->rq_replied, ev->unlinked);
req->rq_early_count++;
if (req->rq_replied || req->rq_reply_unlinked == 1)
goto out_wake;
req->rq_early = 1;
req->rq_reply_off = ev->offset;
req->rq_nob_received = ev->mlength;
req->rq_receiving_reply = 1;
} else {
req->rq_rep_swab_mask = 0;
req->rq_replied = 1;
req->rq_resend = 0;
req->rq_reply_off = ev->offset;
req->rq_nob_received = ev->mlength;
DEBUG_REQ(D_INFO, req,
"reply in flags=%x mlen=%u offset=%d replen=%d",
lustre_msg_get_flags(req->rq_reqmsg),
ev->mlength, ev->offset, req->rq_replen);
}
req->rq_import->imp_last_reply_time = ktime_get_real_seconds();
out_wake:
ptlrpc_client_wake_req(req);
spin_unlock(&req->rq_lock);
}
void client_bulk_callback(lnet_event_t *ev)
{
struct ptlrpc_cb_id *cbid = ev->md.user_ptr;
struct ptlrpc_bulk_desc *desc = cbid->cbid_arg;
struct ptlrpc_request *req;
LASSERT((ptlrpc_is_bulk_put_sink(desc->bd_type) &&
ev->type == LNET_EVENT_PUT) ||
(ptlrpc_is_bulk_get_source(desc->bd_type) &&
ev->type == LNET_EVENT_GET) ||
ev->type == LNET_EVENT_UNLINK);
LASSERT(ev->unlinked);
if (CFS_FAIL_CHECK_ORSET(OBD_FAIL_PTLRPC_CLIENT_BULK_CB, CFS_FAIL_ONCE))
ev->status = -EIO;
if (CFS_FAIL_CHECK_ORSET(OBD_FAIL_PTLRPC_CLIENT_BULK_CB2,
CFS_FAIL_ONCE))
ev->status = -EIO;
CDEBUG((ev->status == 0) ? D_NET : D_ERROR,
"event type %d, status %d, desc %p\n",
ev->type, ev->status, desc);
spin_lock(&desc->bd_lock);
req = desc->bd_req;
LASSERT(desc->bd_md_count > 0);
desc->bd_md_count--;
if (ev->type != LNET_EVENT_UNLINK && ev->status == 0) {
desc->bd_nob_transferred += ev->mlength;
desc->bd_sender = ev->sender;
} else {
spin_lock(&req->rq_lock);
req->rq_net_err = 1;
spin_unlock(&req->rq_lock);
}
if (ev->status != 0)
desc->bd_failure = 1;
if (desc->bd_md_count == 0)
ptlrpc_client_wake_req(desc->bd_req);
spin_unlock(&desc->bd_lock);
}
static void ptlrpc_req_add_history(struct ptlrpc_service_part *svcpt,
struct ptlrpc_request *req)
{
__u64 sec = req->rq_arrival_time.tv_sec;
__u32 usec = req->rq_arrival_time.tv_nsec / NSEC_PER_USEC / 16;
__u64 new_seq;
new_seq = (sec << REQS_SEC_SHIFT) |
(usec << REQS_USEC_SHIFT) |
(svcpt->scp_cpt < 0 ? 0 : svcpt->scp_cpt);
if (new_seq > svcpt->scp_hist_seq) {
svcpt->scp_hist_seq = new_seq;
} else {
LASSERT(REQS_SEQ_SHIFT(svcpt) < REQS_USEC_SHIFT);
svcpt->scp_hist_seq += (1U << REQS_SEQ_SHIFT(svcpt));
new_seq = svcpt->scp_hist_seq;
}
req->rq_history_seq = new_seq;
list_add_tail(&req->rq_history_list, &svcpt->scp_hist_reqs);
}
void request_in_callback(lnet_event_t *ev)
{
struct ptlrpc_cb_id *cbid = ev->md.user_ptr;
struct ptlrpc_request_buffer_desc *rqbd = cbid->cbid_arg;
struct ptlrpc_service_part *svcpt = rqbd->rqbd_svcpt;
struct ptlrpc_service *service = svcpt->scp_service;
struct ptlrpc_request *req;
LASSERT(ev->type == LNET_EVENT_PUT ||
ev->type == LNET_EVENT_UNLINK);
LASSERT((char *)ev->md.start >= rqbd->rqbd_buffer);
LASSERT((char *)ev->md.start + ev->offset + ev->mlength <=
rqbd->rqbd_buffer + service->srv_buf_size);
CDEBUG((ev->status == 0) ? D_NET : D_ERROR,
"event type %d, status %d, service %s\n",
ev->type, ev->status, service->srv_name);
if (ev->unlinked) {
req = &rqbd->rqbd_req;
memset(req, 0, sizeof(*req));
} else {
LASSERT(ev->type == LNET_EVENT_PUT);
if (ev->status != 0) {
return;
}
req = ptlrpc_request_cache_alloc(GFP_ATOMIC);
if (!req) {
CERROR("Can't allocate incoming request descriptor: Dropping %s RPC from %s\n",
service->srv_name,
libcfs_id2str(ev->initiator));
return;
}
}
ptlrpc_srv_req_init(req);
req->rq_xid = ev->match_bits;
req->rq_reqbuf = ev->md.start + ev->offset;
if (ev->type == LNET_EVENT_PUT && ev->status == 0)
req->rq_reqdata_len = ev->mlength;
ktime_get_real_ts64(&req->rq_arrival_time);
req->rq_peer = ev->initiator;
req->rq_self = ev->target.nid;
req->rq_rqbd = rqbd;
req->rq_phase = RQ_PHASE_NEW;
if (ev->type == LNET_EVENT_PUT)
CDEBUG(D_INFO, "incoming req@%p x%llu msgsize %u\n",
req, req->rq_xid, ev->mlength);
CDEBUG(D_RPCTRACE, "peer: %s\n", libcfs_id2str(req->rq_peer));
spin_lock(&svcpt->scp_lock);
ptlrpc_req_add_history(svcpt, req);
if (ev->unlinked) {
svcpt->scp_nrqbds_posted--;
CDEBUG(D_INFO, "Buffer complete: %d buffers still posted\n",
svcpt->scp_nrqbds_posted);
if (test_req_buffer_pressure &&
ev->type != LNET_EVENT_UNLINK &&
svcpt->scp_nrqbds_posted == 0)
CWARN("All %s request buffers busy\n",
service->srv_name);
} else {
rqbd->rqbd_refcount++;
}
list_add_tail(&req->rq_list, &svcpt->scp_req_incoming);
svcpt->scp_nreqs_incoming++;
wake_up(&svcpt->scp_waitq);
spin_unlock(&svcpt->scp_lock);
}
void reply_out_callback(lnet_event_t *ev)
{
struct ptlrpc_cb_id *cbid = ev->md.user_ptr;
struct ptlrpc_reply_state *rs = cbid->cbid_arg;
struct ptlrpc_service_part *svcpt = rs->rs_svcpt;
LASSERT(ev->type == LNET_EVENT_SEND ||
ev->type == LNET_EVENT_ACK ||
ev->type == LNET_EVENT_UNLINK);
if (!rs->rs_difficult) {
LASSERT(ev->unlinked);
ptlrpc_rs_decref(rs);
return;
}
LASSERT(rs->rs_on_net);
if (ev->unlinked) {
spin_lock(&svcpt->scp_rep_lock);
spin_lock(&rs->rs_lock);
rs->rs_on_net = 0;
if (!rs->rs_no_ack ||
rs->rs_transno <=
rs->rs_export->exp_obd->obd_last_committed)
ptlrpc_schedule_difficult_reply(rs);
spin_unlock(&rs->rs_lock);
spin_unlock(&svcpt->scp_rep_lock);
}
}
static void ptlrpc_master_callback(lnet_event_t *ev)
{
struct ptlrpc_cb_id *cbid = ev->md.user_ptr;
void (*callback)(lnet_event_t *ev) = cbid->cbid_fn;
LASSERT(cbid->cbid_arg != LP_POISON);
LASSERT(callback == request_out_callback ||
callback == reply_in_callback ||
callback == client_bulk_callback ||
callback == request_in_callback ||
callback == reply_out_callback);
callback(ev);
}
int ptlrpc_uuid_to_peer(struct obd_uuid *uuid,
lnet_process_id_t *peer, lnet_nid_t *self)
{
int best_dist = 0;
__u32 best_order = 0;
int count = 0;
int rc = -ENOENT;
int dist;
__u32 order;
lnet_nid_t dst_nid;
lnet_nid_t src_nid;
peer->pid = LNET_PID_LUSTRE;
while (lustre_uuid_to_peer(uuid->uuid, &dst_nid, count++) == 0) {
dist = LNetDist(dst_nid, &src_nid, &order);
if (dist < 0)
continue;
if (dist == 0) {
peer->nid = *self = LNET_MKNID(LNET_MKNET(LOLND, 0), 0);
rc = 0;
break;
}
if (rc < 0 ||
dist < best_dist ||
(dist == best_dist && order < best_order)) {
best_dist = dist;
best_order = order;
peer->nid = dst_nid;
*self = src_nid;
rc = 0;
}
}
CDEBUG(D_NET, "%s->%s\n", uuid->uuid, libcfs_id2str(*peer));
return rc;
}
static void ptlrpc_ni_fini(void)
{
wait_queue_head_t waitq;
struct l_wait_info lwi;
int rc;
int retries;
for (retries = 0;; retries++) {
rc = LNetEQFree(ptlrpc_eq_h);
switch (rc) {
default:
LBUG();
case 0:
LNetNIFini();
return;
case -EBUSY:
if (retries != 0)
CWARN("Event queue still busy\n");
init_waitqueue_head(&waitq);
lwi = LWI_TIMEOUT(cfs_time_seconds(2), NULL, NULL);
l_wait_event(waitq, 0, &lwi);
break;
}
}
}
static lnet_pid_t ptl_get_pid(void)
{
lnet_pid_t pid;
pid = LNET_PID_LUSTRE;
return pid;
}
static int ptlrpc_ni_init(void)
{
int rc;
lnet_pid_t pid;
pid = ptl_get_pid();
CDEBUG(D_NET, "My pid is: %x\n", pid);
rc = LNetNIInit(pid);
if (rc < 0) {
CDEBUG(D_NET, "Can't init network interface: %d\n", rc);
return rc;
}
rc = LNetEQAlloc(0, ptlrpc_master_callback, &ptlrpc_eq_h);
if (rc == 0)
return 0;
CERROR("Failed to allocate event queue: %d\n", rc);
LNetNIFini();
return rc;
}
int ptlrpc_init_portals(void)
{
int rc = ptlrpc_ni_init();
if (rc != 0) {
CERROR("network initialisation failed\n");
return rc;
}
rc = ptlrpcd_addref();
if (rc == 0)
return 0;
CERROR("rpcd initialisation failed\n");
ptlrpc_ni_fini();
return rc;
}
void ptlrpc_exit_portals(void)
{
ptlrpcd_decref();
ptlrpc_ni_fini();
}
