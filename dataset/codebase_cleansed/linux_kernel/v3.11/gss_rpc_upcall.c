static int gssp_rpc_create(struct net *net, struct rpc_clnt **_clnt)
{
static const struct sockaddr_un gssp_localaddr = {
.sun_family = AF_LOCAL,
.sun_path = GSSPROXY_SOCK_PATHNAME,
};
struct rpc_create_args args = {
.net = net,
.protocol = XPRT_TRANSPORT_LOCAL,
.address = (struct sockaddr *)&gssp_localaddr,
.addrsize = sizeof(gssp_localaddr),
.servername = "localhost",
.program = &gssp_program,
.version = GSSPROXY_VERS_1,
.authflavor = RPC_AUTH_NULL,
.flags = RPC_CLNT_CREATE_NOPING |
RPC_CLNT_CREATE_NO_IDLE_TIMEOUT
};
struct rpc_clnt *clnt;
int result = 0;
clnt = rpc_create(&args);
if (IS_ERR(clnt)) {
dprintk("RPC: failed to create AF_LOCAL gssproxy "
"client (errno %ld).\n", PTR_ERR(clnt));
result = PTR_ERR(clnt);
*_clnt = NULL;
goto out;
}
dprintk("RPC: created new gssp local client (gssp_local_clnt: "
"%p)\n", clnt);
*_clnt = clnt;
out:
return result;
}
void init_gssp_clnt(struct sunrpc_net *sn)
{
mutex_init(&sn->gssp_lock);
sn->gssp_clnt = NULL;
init_waitqueue_head(&sn->gssp_wq);
}
int set_gssp_clnt(struct net *net)
{
struct sunrpc_net *sn = net_generic(net, sunrpc_net_id);
struct rpc_clnt *clnt;
int ret;
mutex_lock(&sn->gssp_lock);
ret = gssp_rpc_create(net, &clnt);
if (!ret) {
if (sn->gssp_clnt)
rpc_shutdown_client(sn->gssp_clnt);
sn->gssp_clnt = clnt;
}
mutex_unlock(&sn->gssp_lock);
wake_up(&sn->gssp_wq);
return ret;
}
void clear_gssp_clnt(struct sunrpc_net *sn)
{
mutex_lock(&sn->gssp_lock);
if (sn->gssp_clnt) {
rpc_shutdown_client(sn->gssp_clnt);
sn->gssp_clnt = NULL;
}
mutex_unlock(&sn->gssp_lock);
}
static struct rpc_clnt *get_gssp_clnt(struct sunrpc_net *sn)
{
struct rpc_clnt *clnt;
mutex_lock(&sn->gssp_lock);
clnt = sn->gssp_clnt;
if (clnt)
atomic_inc(&clnt->cl_count);
mutex_unlock(&sn->gssp_lock);
return clnt;
}
static int gssp_call(struct net *net, struct rpc_message *msg)
{
struct sunrpc_net *sn = net_generic(net, sunrpc_net_id);
struct rpc_clnt *clnt;
int status;
clnt = get_gssp_clnt(sn);
if (!clnt)
return -EIO;
status = rpc_call_sync(clnt, msg, 0);
if (status < 0) {
dprintk("gssp: rpc_call returned error %d\n", -status);
switch (status) {
case -EPROTONOSUPPORT:
status = -EINVAL;
break;
case -ECONNREFUSED:
case -ETIMEDOUT:
case -ENOTCONN:
status = -EAGAIN;
break;
case -ERESTARTSYS:
if (signalled ())
status = -EINTR;
break;
default:
break;
}
}
rpc_release_client(clnt);
return status;
}
int gssp_accept_sec_context_upcall(struct net *net,
struct gssp_upcall_data *data)
{
struct gssx_ctx ctxh = {
.state = data->in_handle
};
struct gssx_arg_accept_sec_context arg = {
.input_token = data->in_token,
};
struct gssx_ctx rctxh = {
.exported_context_token.len = GSSX_max_output_handle_sz,
.mech.len = GSS_OID_MAX_LEN,
.src_name.display_name.len = GSSX_max_princ_sz
};
struct gssx_res_accept_sec_context res = {
.context_handle = &rctxh,
.output_token = &data->out_token
};
struct rpc_message msg = {
.rpc_proc = &gssp_procedures[GSSX_ACCEPT_SEC_CONTEXT],
.rpc_argp = &arg,
.rpc_resp = &res,
.rpc_cred = NULL,
};
struct xdr_netobj client_name = { 0 , NULL };
int ret;
if (data->in_handle.len != 0)
arg.context_handle = &ctxh;
res.output_token->len = GSSX_max_output_token_sz;
ret = gssp_call(net, &msg);
data->major_status = res.status.major_status;
data->minor_status = res.status.minor_status;
if (res.context_handle) {
data->out_handle = rctxh.exported_context_token;
data->mech_oid.len = rctxh.mech.len;
memcpy(data->mech_oid.data, rctxh.mech.data,
data->mech_oid.len);
client_name = rctxh.src_name.display_name;
}
if (res.options.count == 1) {
gssx_buffer *value = &res.options.data[0].value;
if (value->len == 1) {
data->creds = *(struct svc_cred *)value->data;
data->found_creds = 1;
}
kfree(value->data);
}
if (res.options.count != 0) {
kfree(res.options.data);
}
if (data->found_creds && client_name.data != NULL) {
char *c;
data->creds.cr_principal = kstrndup(client_name.data,
client_name.len, GFP_KERNEL);
if (data->creds.cr_principal) {
c = strchr(data->creds.cr_principal, '@');
if (c) {
*c = '\0';
c = strchr(data->creds.cr_principal, '/');
if (c) *c = '@';
}
if (!c) {
kfree(data->creds.cr_principal);
data->creds.cr_principal = NULL;
}
}
}
kfree(client_name.data);
return ret;
}
void gssp_free_upcall_data(struct gssp_upcall_data *data)
{
kfree(data->in_handle.data);
kfree(data->out_handle.data);
kfree(data->out_token.data);
free_svc_cred(&data->creds);
}
