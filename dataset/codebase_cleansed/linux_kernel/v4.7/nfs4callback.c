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
int *status)
{
__be32 *p;
u32 op;
p = xdr_inline_decode(xdr, 4 + 4);
if (unlikely(p == NULL))
goto out_overflow;
op = be32_to_cpup(p++);
if (unlikely(op != expected))
goto out_unexpected;
*status = nfs_cb_stat_to_errno(be32_to_cpup(p));
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
encode_nfs_fh4(xdr, &dp->dl_stid.sc_file->fi_fhandle);
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
cb->cb_seq_status = status;
return status;
out_overflow:
print_overflow_msg(__func__, xdr);
status = -EIO;
goto out;
}
static int decode_cb_sequence4res(struct xdr_stream *xdr,
struct nfsd4_callback *cb)
{
int status;
if (cb->cb_minorversion == 0)
return 0;
status = decode_cb_op_status(xdr, OP_CB_SEQUENCE, &cb->cb_seq_status);
if (unlikely(status || cb->cb_seq_status))
return status;
return decode_cb_sequence4resok(xdr, cb);
}
static void nfs4_xdr_enc_cb_null(struct rpc_rqst *req, struct xdr_stream *xdr,
void *__unused)
{
xdr_reserve_space(xdr, 0);
}
static void nfs4_xdr_enc_cb_recall(struct rpc_rqst *req, struct xdr_stream *xdr,
const struct nfsd4_callback *cb)
{
const struct nfs4_delegation *dp = cb_to_delegation(cb);
struct nfs4_cb_compound_hdr hdr = {
.ident = cb->cb_clp->cl_cb_ident,
.minorversion = cb->cb_minorversion,
};
encode_cb_compound4args(xdr, &hdr);
encode_cb_sequence4args(xdr, cb, &hdr);
encode_cb_recall4args(xdr, dp, &hdr);
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
int status;
status = decode_cb_compound4res(xdr, &hdr);
if (unlikely(status))
return status;
if (cb != NULL) {
status = decode_cb_sequence4res(xdr, cb);
if (unlikely(status || cb->cb_seq_status))
return status;
}
return decode_cb_op_status(xdr, OP_CB_RECALL, &cb->cb_status);
}
static void encode_cb_layout4args(struct xdr_stream *xdr,
const struct nfs4_layout_stateid *ls,
struct nfs4_cb_compound_hdr *hdr)
{
__be32 *p;
BUG_ON(hdr->minorversion == 0);
p = xdr_reserve_space(xdr, 5 * 4);
*p++ = cpu_to_be32(OP_CB_LAYOUTRECALL);
*p++ = cpu_to_be32(ls->ls_layout_type);
*p++ = cpu_to_be32(IOMODE_ANY);
*p++ = cpu_to_be32(1);
*p = cpu_to_be32(RETURN_FILE);
encode_nfs_fh4(xdr, &ls->ls_stid.sc_file->fi_fhandle);
p = xdr_reserve_space(xdr, 2 * 8);
p = xdr_encode_hyper(p, 0);
xdr_encode_hyper(p, NFS4_MAX_UINT64);
encode_stateid4(xdr, &ls->ls_recall_sid);
hdr->nops++;
}
static void nfs4_xdr_enc_cb_layout(struct rpc_rqst *req,
struct xdr_stream *xdr,
const struct nfsd4_callback *cb)
{
const struct nfs4_layout_stateid *ls =
container_of(cb, struct nfs4_layout_stateid, ls_recall);
struct nfs4_cb_compound_hdr hdr = {
.ident = 0,
.minorversion = cb->cb_minorversion,
};
encode_cb_compound4args(xdr, &hdr);
encode_cb_sequence4args(xdr, cb, &hdr);
encode_cb_layout4args(xdr, ls, &hdr);
encode_cb_nops(&hdr);
}
static int nfs4_xdr_dec_cb_layout(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct nfsd4_callback *cb)
{
struct nfs4_cb_compound_hdr hdr;
int status;
status = decode_cb_compound4res(xdr, &hdr);
if (unlikely(status))
return status;
if (cb) {
status = decode_cb_sequence4res(xdr, cb);
if (unlikely(status || cb->cb_seq_status))
return status;
}
return decode_cb_op_status(xdr, OP_CB_LAYOUTRECALL, &cb->cb_status);
}
static int max_cb_time(struct net *net)
{
struct nfsd_net *nn = net_generic(net, nfsd_net_id);
return max(nn->nfsd4_lease/10, (time_t)1) * HZ;
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
static struct rpc_cred *get_backchannel_cred(struct nfs4_client *clp, struct rpc_clnt *client, struct nfsd4_session *ses)
{
if (clp->cl_minorversion == 0) {
return get_rpccred(callback_cred);
} else {
struct rpc_auth *auth = client->cl_auth;
struct auth_cred acred = {};
acred.uid = ses->se_cb_sec.uid;
acred.gid = ses->se_cb_sec.gid;
return auth->au_ops->lookup_cred(client->cl_auth, &acred, 0);
}
}
static int setup_callback_client(struct nfs4_client *clp, struct nfs4_cb_conn *conn, struct nfsd4_session *ses)
{
int maxtime = max_cb_time(clp->net);
struct rpc_timeout timeparms = {
.to_initval = maxtime,
.to_retries = 0,
.to_maxval = maxtime,
};
struct rpc_create_args args = {
.net = clp->net,
.address = (struct sockaddr *) &conn->cb_addr,
.addrsize = conn->cb_addrlen,
.saddress = (struct sockaddr *) &conn->cb_saddr,
.timeout = &timeparms,
.program = &cb_program,
.version = 0,
.flags = (RPC_CLNT_CREATE_NOPING | RPC_CLNT_CREATE_QUIET),
};
struct rpc_clnt *client;
struct rpc_cred *cred;
if (clp->cl_minorversion == 0) {
if (!clp->cl_cred.cr_principal &&
(clp->cl_cred.cr_flavor >= RPC_AUTH_GSS_KRB5))
return -EINVAL;
args.client_name = clp->cl_cred.cr_principal;
args.prognumber = conn->cb_prog;
args.protocol = XPRT_TRANSPORT_TCP;
args.authflavor = clp->cl_cred.cr_flavor;
clp->cl_cb_ident = conn->cb_ident;
} else {
if (!conn->cb_xprt)
return -EINVAL;
clp->cl_cb_conn.cb_xprt = conn->cb_xprt;
clp->cl_cb_session = ses;
args.bc_xprt = conn->cb_xprt;
args.prognumber = clp->cl_cb_session->se_cb_prog;
args.protocol = conn->cb_xprt->xpt_class->xcl_ident |
XPRT_TRANSPORT_BC;
args.authflavor = ses->se_cb_sec.flavor;
}
client = rpc_create(&args);
if (IS_ERR(client)) {
dprintk("NFSD: couldn't create callback client: %ld\n",
PTR_ERR(client));
return PTR_ERR(client);
}
cred = get_backchannel_cred(clp, client, ses);
if (IS_ERR(cred)) {
rpc_shutdown_client(client);
return PTR_ERR(cred);
}
clp->cl_cb_client = client;
clp->cl_cb_cred = cred;
return 0;
}
static void warn_no_callback_path(struct nfs4_client *clp, int reason)
{
dprintk("NFSD: warning: no callback path to client %.*s: error %d\n",
(int)clp->cl_name.len, clp->cl_name.data, reason);
}
static void nfsd4_mark_cb_down(struct nfs4_client *clp, int reason)
{
if (test_bit(NFSD4_CLIENT_CB_UPDATE, &clp->cl_flags))
return;
clp->cl_cb_state = NFSD4_CB_DOWN;
warn_no_callback_path(clp, reason);
}
static void nfsd4_mark_cb_fault(struct nfs4_client *clp, int reason)
{
if (test_bit(NFSD4_CLIENT_CB_UPDATE, &clp->cl_flags))
return;
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
void nfsd4_probe_callback(struct nfs4_client *clp)
{
clp->cl_cb_state = NFSD4_CB_UNKNOWN;
set_bit(NFSD4_CLIENT_CB_UPDATE, &clp->cl_flags);
nfsd4_run_cb(&clp->cl_cb_null);
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
if (test_and_set_bit(0, &clp->cl_cb_slot_busy) != 0) {
dprintk("%s slot is busy\n", __func__);
return false;
}
rpc_wake_up_queued_task(&clp->cl_cb_waitq, task);
}
return true;
}
static void nfsd4_cb_prepare(struct rpc_task *task, void *calldata)
{
struct nfsd4_callback *cb = calldata;
struct nfs4_client *clp = cb->cb_clp;
u32 minorversion = clp->cl_minorversion;
cb->cb_minorversion = minorversion;
cb->cb_seq_status = 1;
cb->cb_status = 0;
if (minorversion) {
if (!nfsd41_cb_get_slot(clp, task))
return;
}
rpc_call_start(task);
}
static bool nfsd4_cb_sequence_done(struct rpc_task *task, struct nfsd4_callback *cb)
{
struct nfs4_client *clp = cb->cb_clp;
struct nfsd4_session *session = clp->cl_cb_session;
bool ret = true;
if (!clp->cl_minorversion) {
if (task->tk_flags & RPC_TASK_KILLED)
goto need_restart;
return true;
}
switch (cb->cb_seq_status) {
case 0:
++session->se_cb_seq_nr;
break;
case -ESERVERFAULT:
++session->se_cb_seq_nr;
case 1:
case -NFS4ERR_BADSESSION:
nfsd4_mark_cb_fault(cb->cb_clp, cb->cb_seq_status);
ret = false;
break;
case -NFS4ERR_DELAY:
if (!rpc_restart_call(task))
goto out;
rpc_delay(task, 2 * HZ);
return false;
case -NFS4ERR_BADSLOT:
goto retry_nowait;
case -NFS4ERR_SEQ_MISORDERED:
if (session->se_cb_seq_nr != 1) {
session->se_cb_seq_nr = 1;
goto retry_nowait;
}
break;
default:
dprintk("%s: unprocessed error %d\n", __func__,
cb->cb_seq_status);
}
clear_bit(0, &clp->cl_cb_slot_busy);
rpc_wake_up_next(&clp->cl_cb_waitq);
dprintk("%s: freed slot, new seqid=%d\n", __func__,
clp->cl_cb_session->se_cb_seq_nr);
if (task->tk_flags & RPC_TASK_KILLED)
goto need_restart;
out:
return ret;
retry_nowait:
if (rpc_restart_call_prepare(task))
ret = false;
goto out;
need_restart:
task->tk_status = 0;
cb->cb_need_restart = true;
return false;
}
static void nfsd4_cb_done(struct rpc_task *task, void *calldata)
{
struct nfsd4_callback *cb = calldata;
struct nfs4_client *clp = cb->cb_clp;
dprintk("%s: minorversion=%d\n", __func__,
clp->cl_minorversion);
if (!nfsd4_cb_sequence_done(task, cb))
return;
if (cb->cb_status) {
WARN_ON_ONCE(task->tk_status);
task->tk_status = cb->cb_status;
}
switch (cb->cb_ops->done(cb, task)) {
case 0:
task->tk_status = 0;
rpc_restart_call_prepare(task);
return;
case 1:
break;
case -1:
nfsd4_mark_cb_down(clp, task->tk_status);
break;
default:
BUG();
}
}
static void nfsd4_cb_release(void *calldata)
{
struct nfsd4_callback *cb = calldata;
if (cb->cb_need_restart)
nfsd4_run_cb(cb);
else
cb->cb_ops->release(cb);
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
nfsd4_run_cb(&clp->cl_cb_null);
flush_workqueue(callback_wq);
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
put_rpccred(clp->cl_cb_cred);
clp->cl_cb_cred = NULL;
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
}
static void
nfsd4_run_cb_work(struct work_struct *work)
{
struct nfsd4_callback *cb =
container_of(work, struct nfsd4_callback, cb_work);
struct nfs4_client *clp = cb->cb_clp;
struct rpc_clnt *clnt;
if (cb->cb_need_restart) {
cb->cb_need_restart = false;
} else {
if (cb->cb_ops && cb->cb_ops->prepare)
cb->cb_ops->prepare(cb);
}
if (clp->cl_flags & NFSD4_CLIENT_CB_FLAG_MASK)
nfsd4_process_cb_update(cb);
clnt = clp->cl_cb_client;
if (!clnt) {
if (cb->cb_ops && cb->cb_ops->release)
cb->cb_ops->release(cb);
return;
}
if (!cb->cb_ops && clp->cl_minorversion) {
clp->cl_cb_state = NFSD4_CB_UP;
return;
}
cb->cb_msg.rpc_cred = clp->cl_cb_cred;
rpc_call_async(clnt, &cb->cb_msg, RPC_TASK_SOFT | RPC_TASK_SOFTCONN,
cb->cb_ops ? &nfsd4_cb_ops : &nfsd4_cb_probe_ops, cb);
}
void nfsd4_init_cb(struct nfsd4_callback *cb, struct nfs4_client *clp,
const struct nfsd4_callback_ops *ops, enum nfsd4_cb_op op)
{
cb->cb_clp = clp;
cb->cb_msg.rpc_proc = &nfs4_cb_procedures[op];
cb->cb_msg.rpc_argp = cb;
cb->cb_msg.rpc_resp = cb;
cb->cb_ops = ops;
INIT_WORK(&cb->cb_work, nfsd4_run_cb_work);
cb->cb_seq_status = 1;
cb->cb_status = 0;
cb->cb_need_restart = false;
}
void nfsd4_run_cb(struct nfsd4_callback *cb)
{
queue_work(callback_wq, &cb->cb_work);
}
