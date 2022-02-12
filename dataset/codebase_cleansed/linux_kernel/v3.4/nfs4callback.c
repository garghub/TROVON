static void print_overflow_msg(const char *func, const struct xdr_stream *xdr)
{
dprintk("NFS: %s prematurely hit the end of our receive buffer. "
"Remaining buffer length is %tu words.\n",
func, xdr->end - xdr->p);
}
static __be32 *xdr_encode_empty_array(__be32 *p)
{
*p++ = xdr_zero;
return p;
}
static void encode_nfs_cb_opnum4(struct xdr_stream *xdr, enum nfs_cb_opnum4 op)
{
__be32 *p;
p = xdr_reserve_space(xdr, 4);
*p = cpu_to_be32(op);
}
static void encode_nfs_fh4(struct xdr_stream *xdr, const struct knfsd_fh *fh)
{
u32 length = fh->fh_size;
__be32 *p;
BUG_ON(length > NFS4_FHSIZE);
p = xdr_reserve_space(xdr, 4 + length);
xdr_encode_opaque(p, &fh->fh_base, length);
}
static void encode_stateid4(struct xdr_stream *xdr, const stateid_t *sid)
{
__be32 *p;
p = xdr_reserve_space(xdr, NFS4_STATEID_SIZE);
*p++ = cpu_to_be32(sid->si_generation);
xdr_encode_opaque_fixed(p, &sid->si_opaque, NFS4_STATEID_OTHER_SIZE);
}
static void encode_sessionid4(struct xdr_stream *xdr,
const struct nfsd4_session *session)
{
__be32 *p;
p = xdr_reserve_space(xdr, NFS4_MAX_SESSIONID_LEN);
xdr_encode_opaque_fixed(p, session->se_sessionid.data,
NFS4_MAX_SESSIONID_LEN);
}
static int nfs_cb_stat_to_errno(int status)
{
int i;
for (i = 0; nfs_cb_errtbl[i].stat != -1; i++) {
if (nfs_cb_errtbl[i].stat == status)
return nfs_cb_errtbl[i].errno;
}
dprintk("NFSD: Unrecognized NFS CB status value: %u\n", status);
return -status;
}
static int decode_cb_op_status(struct xdr_stream *xdr, enum nfs_opnum4 expected,
enum nfsstat4 *status)
{
__be32 *p;
u32 op;
p = xdr_inline_decode(xdr, 4 + 4);
if (unlikely(p == NULL))
goto out_overflow;
op = be32_to_cpup(p++);
if (unlikely(op != expected))
goto out_unexpected;
*status = be32_to_cpup(p);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
out_unexpected:
dprintk("NFSD: Callback server returned operation %d but "
"we issued a request for %d\n", op, expected);
return -EIO;
}
static void encode_cb_compound4args(struct xdr_stream *xdr,
struct nfs4_cb_compound_hdr *hdr)
{
__be32 * p;
p = xdr_reserve_space(xdr, 4 + 4 + 4 + 4);
p = xdr_encode_empty_array(p);
*p++ = cpu_to_be32(hdr->minorversion);
*p++ = cpu_to_be32(hdr->ident);
hdr->nops_p = p;
*p = cpu_to_be32(hdr->nops);
}
static void encode_cb_nops(struct nfs4_cb_compound_hdr *hdr)
{
BUG_ON(hdr->nops > NFS4_MAX_BACK_CHANNEL_OPS);
*hdr->nops_p = cpu_to_be32(hdr->nops);
}
static int decode_cb_compound4res(struct xdr_stream *xdr,
struct nfs4_cb_compound_hdr *hdr)
{
u32 length;
__be32 *p;
p = xdr_inline_decode(xdr, 4 + 4);
if (unlikely(p == NULL))
goto out_overflow;
hdr->status = be32_to_cpup(p++);
length = be32_to_cpup(p++);
p = xdr_inline_decode(xdr, length + 4);
if (unlikely(p == NULL))
goto out_overflow;
hdr->nops = be32_to_cpup(p);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static void encode_cb_recall4args(struct xdr_stream *xdr,
const struct nfs4_delegation *dp,
struct nfs4_cb_compound_hdr *hdr)
{
__be32 *p;
encode_nfs_cb_opnum4(xdr, OP_CB_RECALL);
encode_stateid4(xdr, &dp->dl_stid.sc_stateid);
p = xdr_reserve_space(xdr, 4);
*p++ = xdr_zero;
encode_nfs_fh4(xdr, &dp->dl_fh);
hdr->nops++;
}
static void encode_cb_sequence4args(struct xdr_stream *xdr,
const struct nfsd4_callback *cb,
struct nfs4_cb_compound_hdr *hdr)
{
struct nfsd4_session *session = cb->cb_clp->cl_cb_session;
__be32 *p;
if (hdr->minorversion == 0)
return;
encode_nfs_cb_opnum4(xdr, OP_CB_SEQUENCE);
encode_sessionid4(xdr, session);
p = xdr_reserve_space(xdr, 4 + 4 + 4 + 4 + 4);
*p++ = cpu_to_be32(session->se_cb_seq_nr);
*p++ = xdr_zero;
*p++ = xdr_zero;
*p++ = xdr_zero;
xdr_encode_empty_array(p);
hdr->nops++;
}
static int decode_cb_sequence4resok(struct xdr_stream *xdr,
struct nfsd4_callback *cb)
{
struct nfsd4_session *session = cb->cb_clp->cl_cb_session;
struct nfs4_sessionid id;
int status;
__be32 *p;
u32 dummy;
status = -ESERVERFAULT;
p = xdr_inline_decode(xdr, NFS4_MAX_SESSIONID_LEN + 4 + 4 + 4 + 4);
if (unlikely(p == NULL))
goto out_overflow;
memcpy(id.data, p, NFS4_MAX_SESSIONID_LEN);
if (memcmp(id.data, session->se_sessionid.data,
NFS4_MAX_SESSIONID_LEN) != 0) {
dprintk("NFS: %s Invalid session id\n", __func__);
goto out;
}
p += XDR_QUADLEN(NFS4_MAX_SESSIONID_LEN);
dummy = be32_to_cpup(p++);
if (dummy != session->se_cb_seq_nr) {
dprintk("NFS: %s Invalid sequence number\n", __func__);
goto out;
}
dummy = be32_to_cpup(p++);
if (dummy != 0) {
dprintk("NFS: %s Invalid slotid\n", __func__);
goto out;
}
status = 0;
out:
if (status)
nfsd4_mark_cb_fault(cb->cb_clp, status);
return status;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int decode_cb_sequence4res(struct xdr_stream *xdr,
struct nfsd4_callback *cb)
{
enum nfsstat4 nfserr;
int status;
if (cb->cb_minorversion == 0)
return 0;
status = decode_cb_op_status(xdr, OP_CB_SEQUENCE, &nfserr);
if (unlikely(status))
goto out;
if (unlikely(nfserr != NFS4_OK))
goto out_default;
status = decode_cb_sequence4resok(xdr, cb);
out:
return status;
out_default:
return nfs_cb_stat_to_errno(nfserr);
}
static void nfs4_xdr_enc_cb_null(struct rpc_rqst *req, struct xdr_stream *xdr,
void *__unused)
{
xdr_reserve_space(xdr, 0);
}
static void nfs4_xdr_enc_cb_recall(struct rpc_rqst *req, struct xdr_stream *xdr,
const struct nfsd4_callback *cb)
{
const struct nfs4_delegation *args = cb->cb_op;
struct nfs4_cb_compound_hdr hdr = {
.ident = cb->cb_clp->cl_cb_ident,
.minorversion = cb->cb_minorversion,
};
encode_cb_compound4args(xdr, &hdr);
encode_cb_sequence4args(xdr, cb, &hdr);
encode_cb_recall4args(xdr, args, &hdr);
encode_cb_nops(&hdr);
}
static int nfs4_xdr_dec_cb_null(struct rpc_rqst *req, struct xdr_stream *xdr,
void *__unused)
{
return 0;
}
static int nfs4_xdr_dec_cb_recall(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct nfsd4_callback *cb)
{
struct nfs4_cb_compound_hdr hdr;
enum nfsstat4 nfserr;
int status;
status = decode_cb_compound4res(xdr, &hdr);
if (unlikely(status))
goto out;
if (cb != NULL) {
status = decode_cb_sequence4res(xdr, cb);
if (unlikely(status))
goto out;
}
status = decode_cb_op_status(xdr, OP_CB_RECALL, &nfserr);
if (unlikely(status))
goto out;
if (unlikely(nfserr != NFS4_OK))
status = nfs_cb_stat_to_errno(nfserr);
out:
return status;
}
static int max_cb_time(void)
{
return max(nfsd4_lease/10, (time_t)1) * HZ;
}
static int setup_callback_client(struct nfs4_client *clp, struct nfs4_cb_conn *conn, struct nfsd4_session *ses)
{
struct rpc_timeout timeparms = {
.to_initval = max_cb_time(),
.to_retries = 0,
};
struct rpc_create_args args = {
.net = &init_net,
.address = (struct sockaddr *) &conn->cb_addr,
.addrsize = conn->cb_addrlen,
.saddress = (struct sockaddr *) &conn->cb_saddr,
.timeout = &timeparms,
.program = &cb_program,
.version = 0,
.flags = (RPC_CLNT_CREATE_NOPING | RPC_CLNT_CREATE_QUIET),
};
struct rpc_clnt *client;
if (clp->cl_minorversion == 0) {
if (!clp->cl_principal && (clp->cl_flavor >= RPC_AUTH_GSS_KRB5))
return -EINVAL;
args.client_name = clp->cl_principal;
args.prognumber = conn->cb_prog,
args.protocol = XPRT_TRANSPORT_TCP;
args.authflavor = clp->cl_flavor;
clp->cl_cb_ident = conn->cb_ident;
} else {
if (!conn->cb_xprt)
return -EINVAL;
clp->cl_cb_conn.cb_xprt = conn->cb_xprt;
clp->cl_cb_session = ses;
args.bc_xprt = conn->cb_xprt;
args.prognumber = clp->cl_cb_session->se_cb_prog;
args.protocol = XPRT_TRANSPORT_BC_TCP;
args.authflavor = RPC_AUTH_UNIX;
}
client = rpc_create(&args);
if (IS_ERR(client)) {
dprintk("NFSD: couldn't create callback client: %ld\n",
PTR_ERR(client));
return PTR_ERR(client);
}
clp->cl_cb_client = client;
return 0;
}
static void warn_no_callback_path(struct nfs4_client *clp, int reason)
{
dprintk("NFSD: warning: no callback path to client %.*s: error %d\n",
(int)clp->cl_name.len, clp->cl_name.data, reason);
}
static void nfsd4_mark_cb_down(struct nfs4_client *clp, int reason)
{
clp->cl_cb_state = NFSD4_CB_DOWN;
warn_no_callback_path(clp, reason);
}
static void nfsd4_mark_cb_fault(struct nfs4_client *clp, int reason)
{
clp->cl_cb_state = NFSD4_CB_FAULT;
warn_no_callback_path(clp, reason);
}
static void nfsd4_cb_probe_done(struct rpc_task *task, void *calldata)
{
struct nfs4_client *clp = container_of(calldata, struct nfs4_client, cl_cb_null);
if (task->tk_status)
nfsd4_mark_cb_down(clp, task->tk_status);
else
clp->cl_cb_state = NFSD4_CB_UP;
}
int set_callback_cred(void)
{
if (callback_cred)
return 0;
callback_cred = rpc_lookup_machine_cred("nfs");
if (!callback_cred)
return -ENOMEM;
return 0;
}
static void run_nfsd4_cb(struct nfsd4_callback *cb)
{
queue_work(callback_wq, &cb->cb_work);
}
static void do_probe_callback(struct nfs4_client *clp)
{
struct nfsd4_callback *cb = &clp->cl_cb_null;
cb->cb_op = NULL;
cb->cb_clp = clp;
cb->cb_msg.rpc_proc = &nfs4_cb_procedures[NFSPROC4_CLNT_CB_NULL];
cb->cb_msg.rpc_argp = NULL;
cb->cb_msg.rpc_resp = NULL;
cb->cb_msg.rpc_cred = callback_cred;
cb->cb_ops = &nfsd4_cb_probe_ops;
run_nfsd4_cb(cb);
}
void nfsd4_probe_callback(struct nfs4_client *clp)
{
clp->cl_cb_state = NFSD4_CB_UNKNOWN;
set_bit(NFSD4_CLIENT_CB_UPDATE, &clp->cl_flags);
do_probe_callback(clp);
}
void nfsd4_probe_callback_sync(struct nfs4_client *clp)
{
nfsd4_probe_callback(clp);
flush_workqueue(callback_wq);
}
void nfsd4_change_callback(struct nfs4_client *clp, struct nfs4_cb_conn *conn)
{
clp->cl_cb_state = NFSD4_CB_UNKNOWN;
spin_lock(&clp->cl_lock);
memcpy(&clp->cl_cb_conn, conn, sizeof(struct nfs4_cb_conn));
spin_unlock(&clp->cl_lock);
}
static bool nfsd41_cb_get_slot(struct nfs4_client *clp, struct rpc_task *task)
{
if (test_and_set_bit(0, &clp->cl_cb_slot_busy) != 0) {
rpc_sleep_on(&clp->cl_cb_waitq, task, NULL);
dprintk("%s slot is busy\n", __func__);
return false;
}
return true;
}
static void nfsd4_cb_prepare(struct rpc_task *task, void *calldata)
{
struct nfsd4_callback *cb = calldata;
struct nfs4_delegation *dp = container_of(cb, struct nfs4_delegation, dl_recall);
struct nfs4_client *clp = dp->dl_stid.sc_client;
u32 minorversion = clp->cl_minorversion;
cb->cb_minorversion = minorversion;
if (minorversion) {
if (!nfsd41_cb_get_slot(clp, task))
return;
}
spin_lock(&clp->cl_lock);
if (list_empty(&cb->cb_per_client)) {
cb->cb_done = false;
list_add(&cb->cb_per_client, &clp->cl_callbacks);
}
spin_unlock(&clp->cl_lock);
rpc_call_start(task);
}
static void nfsd4_cb_done(struct rpc_task *task, void *calldata)
{
struct nfsd4_callback *cb = calldata;
struct nfs4_delegation *dp = container_of(cb, struct nfs4_delegation, dl_recall);
struct nfs4_client *clp = dp->dl_stid.sc_client;
dprintk("%s: minorversion=%d\n", __func__,
clp->cl_minorversion);
if (clp->cl_minorversion) {
++clp->cl_cb_session->se_cb_seq_nr;
clear_bit(0, &clp->cl_cb_slot_busy);
rpc_wake_up_next(&clp->cl_cb_waitq);
dprintk("%s: freed slot, new seqid=%d\n", __func__,
clp->cl_cb_session->se_cb_seq_nr);
task->tk_msg.rpc_resp = NULL;
}
}
static void nfsd4_cb_recall_done(struct rpc_task *task, void *calldata)
{
struct nfsd4_callback *cb = calldata;
struct nfs4_delegation *dp = container_of(cb, struct nfs4_delegation, dl_recall);
struct nfs4_client *clp = dp->dl_stid.sc_client;
struct rpc_clnt *current_rpc_client = clp->cl_cb_client;
nfsd4_cb_done(task, calldata);
if (current_rpc_client != task->tk_client) {
return;
}
if (cb->cb_done)
return;
switch (task->tk_status) {
case 0:
cb->cb_done = true;
return;
case -EBADHANDLE:
case -NFS4ERR_BAD_STATEID:
break;
default:
nfsd4_mark_cb_down(clp, task->tk_status);
}
if (dp->dl_retries--) {
rpc_delay(task, 2*HZ);
task->tk_status = 0;
rpc_restart_call_prepare(task);
return;
}
nfsd4_mark_cb_down(clp, task->tk_status);
cb->cb_done = true;
}
static void nfsd4_cb_recall_release(void *calldata)
{
struct nfsd4_callback *cb = calldata;
struct nfs4_client *clp = cb->cb_clp;
struct nfs4_delegation *dp = container_of(cb, struct nfs4_delegation, dl_recall);
if (cb->cb_done) {
spin_lock(&clp->cl_lock);
list_del(&cb->cb_per_client);
spin_unlock(&clp->cl_lock);
nfs4_put_delegation(dp);
}
}
int nfsd4_create_callback_queue(void)
{
callback_wq = create_singlethread_workqueue("nfsd4_callbacks");
if (!callback_wq)
return -ENOMEM;
return 0;
}
void nfsd4_destroy_callback_queue(void)
{
destroy_workqueue(callback_wq);
}
void nfsd4_shutdown_callback(struct nfs4_client *clp)
{
set_bit(NFSD4_CLIENT_CB_KILL, &clp->cl_flags);
do_probe_callback(clp);
flush_workqueue(callback_wq);
}
static void nfsd4_release_cb(struct nfsd4_callback *cb)
{
if (cb->cb_ops->rpc_release)
cb->cb_ops->rpc_release(cb);
}
static struct nfsd4_conn * __nfsd4_find_backchannel(struct nfs4_client *clp)
{
struct nfsd4_session *s;
struct nfsd4_conn *c;
list_for_each_entry(s, &clp->cl_sessions, se_perclnt) {
list_for_each_entry(c, &s->se_conns, cn_persession) {
if (c->cn_flags & NFS4_CDFC4_BACK)
return c;
}
}
return NULL;
}
static void nfsd4_process_cb_update(struct nfsd4_callback *cb)
{
struct nfs4_cb_conn conn;
struct nfs4_client *clp = cb->cb_clp;
struct nfsd4_session *ses = NULL;
struct nfsd4_conn *c;
int err;
if (clp->cl_cb_client) {
rpc_shutdown_client(clp->cl_cb_client);
clp->cl_cb_client = NULL;
}
if (clp->cl_cb_conn.cb_xprt) {
svc_xprt_put(clp->cl_cb_conn.cb_xprt);
clp->cl_cb_conn.cb_xprt = NULL;
}
if (test_bit(NFSD4_CLIENT_CB_KILL, &clp->cl_flags))
return;
spin_lock(&clp->cl_lock);
BUG_ON(!(clp->cl_flags & NFSD4_CLIENT_CB_FLAG_MASK));
clear_bit(NFSD4_CLIENT_CB_UPDATE, &clp->cl_flags);
memcpy(&conn, &cb->cb_clp->cl_cb_conn, sizeof(struct nfs4_cb_conn));
c = __nfsd4_find_backchannel(clp);
if (c) {
svc_xprt_get(c->cn_xprt);
conn.cb_xprt = c->cn_xprt;
ses = c->cn_session;
}
spin_unlock(&clp->cl_lock);
err = setup_callback_client(clp, &conn, ses);
if (err) {
nfsd4_mark_cb_down(clp, err);
return;
}
list_for_each_entry(cb, &clp->cl_callbacks, cb_per_client)
run_nfsd4_cb(cb);
}
void nfsd4_do_callback_rpc(struct work_struct *w)
{
struct nfsd4_callback *cb = container_of(w, struct nfsd4_callback, cb_work);
struct nfs4_client *clp = cb->cb_clp;
struct rpc_clnt *clnt;
if (clp->cl_flags & NFSD4_CLIENT_CB_FLAG_MASK)
nfsd4_process_cb_update(cb);
clnt = clp->cl_cb_client;
if (!clnt) {
nfsd4_release_cb(cb);
return;
}
rpc_call_async(clnt, &cb->cb_msg, RPC_TASK_SOFT | RPC_TASK_SOFTCONN,
cb->cb_ops, cb);
}
void nfsd4_cb_recall(struct nfs4_delegation *dp)
{
struct nfsd4_callback *cb = &dp->dl_recall;
struct nfs4_client *clp = dp->dl_stid.sc_client;
dp->dl_retries = 1;
cb->cb_op = dp;
cb->cb_clp = clp;
cb->cb_msg.rpc_proc = &nfs4_cb_procedures[NFSPROC4_CLNT_CB_RECALL];
cb->cb_msg.rpc_argp = cb;
cb->cb_msg.rpc_resp = cb;
cb->cb_msg.rpc_cred = callback_cred;
cb->cb_ops = &nfsd4_cb_recall_ops;
dp->dl_retries = 1;
INIT_LIST_HEAD(&cb->cb_per_client);
cb->cb_done = true;
run_nfsd4_cb(&dp->dl_recall);
}
