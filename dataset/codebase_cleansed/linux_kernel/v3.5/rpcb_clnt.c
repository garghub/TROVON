static void rpcb_wake_rpcbind_waiters(struct rpc_xprt *xprt, int status)
{
xprt_clear_binding(xprt);
rpc_wake_up_status(&xprt->binding, status);
}
static void rpcb_map_release(void *data)
{
struct rpcbind_args *map = data;
rpcb_wake_rpcbind_waiters(map->r_xprt, map->r_status);
xprt_put(map->r_xprt);
kfree(map->r_addr);
kfree(map);
}
static int rpcb_get_local(struct net *net)
{
int cnt;
struct sunrpc_net *sn = net_generic(net, sunrpc_net_id);
spin_lock(&sn->rpcb_clnt_lock);
if (sn->rpcb_users)
sn->rpcb_users++;
cnt = sn->rpcb_users;
spin_unlock(&sn->rpcb_clnt_lock);
return cnt;
}
void rpcb_put_local(struct net *net)
{
struct sunrpc_net *sn = net_generic(net, sunrpc_net_id);
struct rpc_clnt *clnt = sn->rpcb_local_clnt;
struct rpc_clnt *clnt4 = sn->rpcb_local_clnt4;
int shutdown = 0;
spin_lock(&sn->rpcb_clnt_lock);
if (sn->rpcb_users) {
if (--sn->rpcb_users == 0) {
sn->rpcb_local_clnt = NULL;
sn->rpcb_local_clnt4 = NULL;
}
shutdown = !sn->rpcb_users;
}
spin_unlock(&sn->rpcb_clnt_lock);
if (shutdown) {
if (clnt4)
rpc_shutdown_client(clnt4);
if (clnt)
rpc_shutdown_client(clnt);
}
}
static void rpcb_set_local(struct net *net, struct rpc_clnt *clnt,
struct rpc_clnt *clnt4)
{
struct sunrpc_net *sn = net_generic(net, sunrpc_net_id);
sn->rpcb_local_clnt = clnt;
sn->rpcb_local_clnt4 = clnt4;
smp_wmb();
sn->rpcb_users = 1;
dprintk("RPC: created new rpcb local clients (rpcb_local_clnt: "
"%p, rpcb_local_clnt4: %p) for net %p%s\n",
sn->rpcb_local_clnt, sn->rpcb_local_clnt4,
net, (net == &init_net) ? " (init_net)" : "");
}
static int rpcb_create_local_unix(struct net *net)
{
static const struct sockaddr_un rpcb_localaddr_rpcbind = {
.sun_family = AF_LOCAL,
.sun_path = RPCBIND_SOCK_PATHNAME,
};
struct rpc_create_args args = {
.net = net,
.protocol = XPRT_TRANSPORT_LOCAL,
.address = (struct sockaddr *)&rpcb_localaddr_rpcbind,
.addrsize = sizeof(rpcb_localaddr_rpcbind),
.servername = "localhost",
.program = &rpcb_program,
.version = RPCBVERS_2,
.authflavor = RPC_AUTH_NULL,
};
struct rpc_clnt *clnt, *clnt4;
int result = 0;
clnt = rpc_create(&args);
if (IS_ERR(clnt)) {
dprintk("RPC: failed to create AF_LOCAL rpcbind "
"client (errno %ld).\n", PTR_ERR(clnt));
result = -PTR_ERR(clnt);
goto out;
}
clnt4 = rpc_bind_new_program(clnt, &rpcb_program, RPCBVERS_4);
if (IS_ERR(clnt4)) {
dprintk("RPC: failed to bind second program to "
"rpcbind v4 client (errno %ld).\n",
PTR_ERR(clnt4));
clnt4 = NULL;
}
rpcb_set_local(net, clnt, clnt4);
out:
return result;
}
static int rpcb_create_local_net(struct net *net)
{
static const struct sockaddr_in rpcb_inaddr_loopback = {
.sin_family = AF_INET,
.sin_addr.s_addr = htonl(INADDR_LOOPBACK),
.sin_port = htons(RPCBIND_PORT),
};
struct rpc_create_args args = {
.net = net,
.protocol = XPRT_TRANSPORT_TCP,
.address = (struct sockaddr *)&rpcb_inaddr_loopback,
.addrsize = sizeof(rpcb_inaddr_loopback),
.servername = "localhost",
.program = &rpcb_program,
.version = RPCBVERS_2,
.authflavor = RPC_AUTH_UNIX,
.flags = RPC_CLNT_CREATE_NOPING,
};
struct rpc_clnt *clnt, *clnt4;
int result = 0;
clnt = rpc_create(&args);
if (IS_ERR(clnt)) {
dprintk("RPC: failed to create local rpcbind "
"client (errno %ld).\n", PTR_ERR(clnt));
result = -PTR_ERR(clnt);
goto out;
}
clnt4 = rpc_bind_new_program(clnt, &rpcb_program, RPCBVERS_4);
if (IS_ERR(clnt4)) {
dprintk("RPC: failed to bind second program to "
"rpcbind v4 client (errno %ld).\n",
PTR_ERR(clnt4));
clnt4 = NULL;
}
rpcb_set_local(net, clnt, clnt4);
out:
return result;
}
int rpcb_create_local(struct net *net)
{
static DEFINE_MUTEX(rpcb_create_local_mutex);
int result = 0;
if (rpcb_get_local(net))
return result;
mutex_lock(&rpcb_create_local_mutex);
if (rpcb_get_local(net))
goto out;
if (rpcb_create_local_unix(net) != 0)
result = rpcb_create_local_net(net);
out:
mutex_unlock(&rpcb_create_local_mutex);
return result;
}
static struct rpc_clnt *rpcb_create(struct net *net, const char *hostname,
struct sockaddr *srvaddr, size_t salen,
int proto, u32 version)
{
struct rpc_create_args args = {
.net = net,
.protocol = proto,
.address = srvaddr,
.addrsize = salen,
.servername = hostname,
.program = &rpcb_program,
.version = version,
.authflavor = RPC_AUTH_UNIX,
.flags = (RPC_CLNT_CREATE_NOPING |
RPC_CLNT_CREATE_NONPRIVPORT),
};
switch (srvaddr->sa_family) {
case AF_INET:
((struct sockaddr_in *)srvaddr)->sin_port = htons(RPCBIND_PORT);
break;
case AF_INET6:
((struct sockaddr_in6 *)srvaddr)->sin6_port = htons(RPCBIND_PORT);
break;
default:
return ERR_PTR(-EAFNOSUPPORT);
}
return rpc_create(&args);
}
static int rpcb_register_call(struct rpc_clnt *clnt, struct rpc_message *msg)
{
int result, error = 0;
msg->rpc_resp = &result;
error = rpc_call_sync(clnt, msg, RPC_TASK_SOFTCONN);
if (error < 0) {
dprintk("RPC: failed to contact local rpcbind "
"server (errno %d).\n", -error);
return error;
}
if (!result)
return -EACCES;
return 0;
}
int rpcb_register(struct net *net, u32 prog, u32 vers, int prot, unsigned short port)
{
struct rpcbind_args map = {
.r_prog = prog,
.r_vers = vers,
.r_prot = prot,
.r_port = port,
};
struct rpc_message msg = {
.rpc_argp = &map,
};
struct sunrpc_net *sn = net_generic(net, sunrpc_net_id);
dprintk("RPC: %sregistering (%u, %u, %d, %u) with local "
"rpcbind\n", (port ? "" : "un"),
prog, vers, prot, port);
msg.rpc_proc = &rpcb_procedures2[RPCBPROC_UNSET];
if (port)
msg.rpc_proc = &rpcb_procedures2[RPCBPROC_SET];
return rpcb_register_call(sn->rpcb_local_clnt, &msg);
}
static int rpcb_register_inet4(struct sunrpc_net *sn,
const struct sockaddr *sap,
struct rpc_message *msg)
{
const struct sockaddr_in *sin = (const struct sockaddr_in *)sap;
struct rpcbind_args *map = msg->rpc_argp;
unsigned short port = ntohs(sin->sin_port);
int result;
map->r_addr = rpc_sockaddr2uaddr(sap, GFP_KERNEL);
dprintk("RPC: %sregistering [%u, %u, %s, '%s'] with "
"local rpcbind\n", (port ? "" : "un"),
map->r_prog, map->r_vers,
map->r_addr, map->r_netid);
msg->rpc_proc = &rpcb_procedures4[RPCBPROC_UNSET];
if (port)
msg->rpc_proc = &rpcb_procedures4[RPCBPROC_SET];
result = rpcb_register_call(sn->rpcb_local_clnt4, msg);
kfree(map->r_addr);
return result;
}
static int rpcb_register_inet6(struct sunrpc_net *sn,
const struct sockaddr *sap,
struct rpc_message *msg)
{
const struct sockaddr_in6 *sin6 = (const struct sockaddr_in6 *)sap;
struct rpcbind_args *map = msg->rpc_argp;
unsigned short port = ntohs(sin6->sin6_port);
int result;
map->r_addr = rpc_sockaddr2uaddr(sap, GFP_KERNEL);
dprintk("RPC: %sregistering [%u, %u, %s, '%s'] with "
"local rpcbind\n", (port ? "" : "un"),
map->r_prog, map->r_vers,
map->r_addr, map->r_netid);
msg->rpc_proc = &rpcb_procedures4[RPCBPROC_UNSET];
if (port)
msg->rpc_proc = &rpcb_procedures4[RPCBPROC_SET];
result = rpcb_register_call(sn->rpcb_local_clnt4, msg);
kfree(map->r_addr);
return result;
}
static int rpcb_unregister_all_protofamilies(struct sunrpc_net *sn,
struct rpc_message *msg)
{
struct rpcbind_args *map = msg->rpc_argp;
dprintk("RPC: unregistering [%u, %u, '%s'] with "
"local rpcbind\n",
map->r_prog, map->r_vers, map->r_netid);
map->r_addr = "";
msg->rpc_proc = &rpcb_procedures4[RPCBPROC_UNSET];
return rpcb_register_call(sn->rpcb_local_clnt4, msg);
}
int rpcb_v4_register(struct net *net, const u32 program, const u32 version,
const struct sockaddr *address, const char *netid)
{
struct rpcbind_args map = {
.r_prog = program,
.r_vers = version,
.r_netid = netid,
.r_owner = RPCB_OWNER_STRING,
};
struct rpc_message msg = {
.rpc_argp = &map,
};
struct sunrpc_net *sn = net_generic(net, sunrpc_net_id);
if (sn->rpcb_local_clnt4 == NULL)
return -EPROTONOSUPPORT;
if (address == NULL)
return rpcb_unregister_all_protofamilies(sn, &msg);
switch (address->sa_family) {
case AF_INET:
return rpcb_register_inet4(sn, address, &msg);
case AF_INET6:
return rpcb_register_inet6(sn, address, &msg);
}
return -EAFNOSUPPORT;
}
static struct rpc_task *rpcb_call_async(struct rpc_clnt *rpcb_clnt, struct rpcbind_args *map, struct rpc_procinfo *proc)
{
struct rpc_message msg = {
.rpc_proc = proc,
.rpc_argp = map,
.rpc_resp = map,
};
struct rpc_task_setup task_setup_data = {
.rpc_client = rpcb_clnt,
.rpc_message = &msg,
.callback_ops = &rpcb_getport_ops,
.callback_data = map,
.flags = RPC_TASK_ASYNC | RPC_TASK_SOFTCONN,
};
return rpc_run_task(&task_setup_data);
}
static struct rpc_clnt *rpcb_find_transport_owner(struct rpc_clnt *clnt)
{
struct rpc_clnt *parent = clnt->cl_parent;
struct rpc_xprt *xprt = rcu_dereference(clnt->cl_xprt);
while (parent != clnt) {
if (rcu_dereference(parent->cl_xprt) != xprt)
break;
if (clnt->cl_autobind)
break;
clnt = parent;
parent = parent->cl_parent;
}
return clnt;
}
void rpcb_getport_async(struct rpc_task *task)
{
struct rpc_clnt *clnt;
struct rpc_procinfo *proc;
u32 bind_version;
struct rpc_xprt *xprt;
struct rpc_clnt *rpcb_clnt;
struct rpcbind_args *map;
struct rpc_task *child;
struct sockaddr_storage addr;
struct sockaddr *sap = (struct sockaddr *)&addr;
size_t salen;
int status;
rcu_read_lock();
do {
clnt = rpcb_find_transport_owner(task->tk_client);
xprt = xprt_get(rcu_dereference(clnt->cl_xprt));
} while (xprt == NULL);
rcu_read_unlock();
dprintk("RPC: %5u %s(%s, %u, %u, %d)\n",
task->tk_pid, __func__,
xprt->servername, clnt->cl_prog, clnt->cl_vers, xprt->prot);
rpc_sleep_on(&xprt->binding, task, NULL);
if (xprt_test_and_set_binding(xprt)) {
dprintk("RPC: %5u %s: waiting for another binder\n",
task->tk_pid, __func__);
xprt_put(xprt);
return;
}
if (xprt_bound(xprt)) {
status = 0;
dprintk("RPC: %5u %s: already bound\n",
task->tk_pid, __func__);
goto bailout_nofree;
}
salen = rpc_peeraddr(clnt, sap, sizeof(addr));
switch (sap->sa_family) {
case AF_INET:
proc = rpcb_next_version[xprt->bind_index].rpc_proc;
bind_version = rpcb_next_version[xprt->bind_index].rpc_vers;
break;
case AF_INET6:
proc = rpcb_next_version6[xprt->bind_index].rpc_proc;
bind_version = rpcb_next_version6[xprt->bind_index].rpc_vers;
break;
default:
status = -EAFNOSUPPORT;
dprintk("RPC: %5u %s: bad address family\n",
task->tk_pid, __func__);
goto bailout_nofree;
}
if (proc == NULL) {
xprt->bind_index = 0;
status = -EPFNOSUPPORT;
dprintk("RPC: %5u %s: no more getport versions available\n",
task->tk_pid, __func__);
goto bailout_nofree;
}
dprintk("RPC: %5u %s: trying rpcbind version %u\n",
task->tk_pid, __func__, bind_version);
rpcb_clnt = rpcb_create(xprt->xprt_net, xprt->servername, sap, salen,
xprt->prot, bind_version);
if (IS_ERR(rpcb_clnt)) {
status = PTR_ERR(rpcb_clnt);
dprintk("RPC: %5u %s: rpcb_create failed, error %ld\n",
task->tk_pid, __func__, PTR_ERR(rpcb_clnt));
goto bailout_nofree;
}
map = kzalloc(sizeof(struct rpcbind_args), GFP_ATOMIC);
if (!map) {
status = -ENOMEM;
dprintk("RPC: %5u %s: no memory available\n",
task->tk_pid, __func__);
goto bailout_release_client;
}
map->r_prog = clnt->cl_prog;
map->r_vers = clnt->cl_vers;
map->r_prot = xprt->prot;
map->r_port = 0;
map->r_xprt = xprt;
map->r_status = -EIO;
switch (bind_version) {
case RPCBVERS_4:
case RPCBVERS_3:
map->r_netid = xprt->address_strings[RPC_DISPLAY_NETID];
map->r_addr = rpc_sockaddr2uaddr(sap, GFP_ATOMIC);
map->r_owner = "";
break;
case RPCBVERS_2:
map->r_addr = NULL;
break;
default:
BUG();
}
child = rpcb_call_async(rpcb_clnt, map, proc);
rpc_release_client(rpcb_clnt);
if (IS_ERR(child)) {
dprintk("RPC: %5u %s: rpc_run_task failed\n",
task->tk_pid, __func__);
return;
}
xprt->stat.bind_count++;
rpc_put_task(child);
return;
bailout_release_client:
rpc_release_client(rpcb_clnt);
bailout_nofree:
rpcb_wake_rpcbind_waiters(xprt, status);
task->tk_status = status;
xprt_put(xprt);
}
static void rpcb_getport_done(struct rpc_task *child, void *data)
{
struct rpcbind_args *map = data;
struct rpc_xprt *xprt = map->r_xprt;
int status = child->tk_status;
if (status == -EIO)
status = -EPROTONOSUPPORT;
if (status == -EPROTONOSUPPORT)
xprt->bind_index++;
if (status < 0) {
xprt->ops->set_port(xprt, 0);
} else if (map->r_port == 0) {
xprt->ops->set_port(xprt, 0);
status = -EACCES;
} else {
xprt->ops->set_port(xprt, map->r_port);
xprt_set_bound(xprt);
status = 0;
}
dprintk("RPC: %5u rpcb_getport_done(status %d, port %u)\n",
child->tk_pid, status, map->r_port);
map->r_status = status;
}
static void rpcb_enc_mapping(struct rpc_rqst *req, struct xdr_stream *xdr,
const struct rpcbind_args *rpcb)
{
__be32 *p;
dprintk("RPC: %5u encoding PMAP_%s call (%u, %u, %d, %u)\n",
req->rq_task->tk_pid,
req->rq_task->tk_msg.rpc_proc->p_name,
rpcb->r_prog, rpcb->r_vers, rpcb->r_prot, rpcb->r_port);
p = xdr_reserve_space(xdr, RPCB_mappingargs_sz << 2);
*p++ = cpu_to_be32(rpcb->r_prog);
*p++ = cpu_to_be32(rpcb->r_vers);
*p++ = cpu_to_be32(rpcb->r_prot);
*p = cpu_to_be32(rpcb->r_port);
}
static int rpcb_dec_getport(struct rpc_rqst *req, struct xdr_stream *xdr,
struct rpcbind_args *rpcb)
{
unsigned long port;
__be32 *p;
rpcb->r_port = 0;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -EIO;
port = be32_to_cpup(p);
dprintk("RPC: %5u PMAP_%s result: %lu\n", req->rq_task->tk_pid,
req->rq_task->tk_msg.rpc_proc->p_name, port);
if (unlikely(port > USHRT_MAX))
return -EIO;
rpcb->r_port = port;
return 0;
}
static int rpcb_dec_set(struct rpc_rqst *req, struct xdr_stream *xdr,
unsigned int *boolp)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -EIO;
*boolp = 0;
if (*p != xdr_zero)
*boolp = 1;
dprintk("RPC: %5u RPCB_%s call %s\n",
req->rq_task->tk_pid,
req->rq_task->tk_msg.rpc_proc->p_name,
(*boolp ? "succeeded" : "failed"));
return 0;
}
static void encode_rpcb_string(struct xdr_stream *xdr, const char *string,
const u32 maxstrlen)
{
__be32 *p;
u32 len;
len = strlen(string);
BUG_ON(len > maxstrlen);
p = xdr_reserve_space(xdr, 4 + len);
xdr_encode_opaque(p, string, len);
}
static void rpcb_enc_getaddr(struct rpc_rqst *req, struct xdr_stream *xdr,
const struct rpcbind_args *rpcb)
{
__be32 *p;
dprintk("RPC: %5u encoding RPCB_%s call (%u, %u, '%s', '%s')\n",
req->rq_task->tk_pid,
req->rq_task->tk_msg.rpc_proc->p_name,
rpcb->r_prog, rpcb->r_vers,
rpcb->r_netid, rpcb->r_addr);
p = xdr_reserve_space(xdr, (RPCB_program_sz + RPCB_version_sz) << 2);
*p++ = cpu_to_be32(rpcb->r_prog);
*p = cpu_to_be32(rpcb->r_vers);
encode_rpcb_string(xdr, rpcb->r_netid, RPCBIND_MAXNETIDLEN);
encode_rpcb_string(xdr, rpcb->r_addr, RPCBIND_MAXUADDRLEN);
encode_rpcb_string(xdr, rpcb->r_owner, RPCB_MAXOWNERLEN);
}
static int rpcb_dec_getaddr(struct rpc_rqst *req, struct xdr_stream *xdr,
struct rpcbind_args *rpcb)
{
struct sockaddr_storage address;
struct sockaddr *sap = (struct sockaddr *)&address;
__be32 *p;
u32 len;
rpcb->r_port = 0;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
goto out_fail;
len = be32_to_cpup(p);
if (len == 0) {
dprintk("RPC: %5u RPCB reply: program not registered\n",
req->rq_task->tk_pid);
return 0;
}
if (unlikely(len > RPCBIND_MAXUADDRLEN))
goto out_fail;
p = xdr_inline_decode(xdr, len);
if (unlikely(p == NULL))
goto out_fail;
dprintk("RPC: %5u RPCB_%s reply: %s\n", req->rq_task->tk_pid,
req->rq_task->tk_msg.rpc_proc->p_name, (char *)p);
if (rpc_uaddr2sockaddr(req->rq_xprt->xprt_net, (char *)p, len,
sap, sizeof(address)) == 0)
goto out_fail;
rpcb->r_port = rpc_get_port(sap);
return 0;
out_fail:
dprintk("RPC: %5u malformed RPCB_%s reply\n",
req->rq_task->tk_pid,
req->rq_task->tk_msg.rpc_proc->p_name);
return -EIO;
}
