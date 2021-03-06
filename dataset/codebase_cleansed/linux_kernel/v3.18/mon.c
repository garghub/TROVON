static inline struct sockaddr *nsm_addr(const struct nsm_handle *nsm)
{
return (struct sockaddr *)&nsm->sm_addr;
}
static struct rpc_clnt *nsm_create(struct net *net)
{
struct sockaddr_in sin = {
.sin_family = AF_INET,
.sin_addr.s_addr = htonl(INADDR_LOOPBACK),
};
struct rpc_create_args args = {
.net = net,
.protocol = XPRT_TRANSPORT_TCP,
.address = (struct sockaddr *)&sin,
.addrsize = sizeof(sin),
.servername = "rpc.statd",
.program = &nsm_program,
.version = NSM_VERSION,
.authflavor = RPC_AUTH_NULL,
.flags = RPC_CLNT_CREATE_NOPING,
};
return rpc_create(&args);
}
static struct rpc_clnt *nsm_client_set(struct lockd_net *ln,
struct rpc_clnt *clnt)
{
spin_lock(&ln->nsm_clnt_lock);
if (ln->nsm_users == 0) {
if (clnt == NULL)
goto out;
ln->nsm_clnt = clnt;
}
clnt = ln->nsm_clnt;
ln->nsm_users++;
out:
spin_unlock(&ln->nsm_clnt_lock);
return clnt;
}
static struct rpc_clnt *nsm_client_get(struct net *net)
{
struct rpc_clnt *clnt, *new;
struct lockd_net *ln = net_generic(net, lockd_net_id);
clnt = nsm_client_set(ln, NULL);
if (clnt != NULL)
goto out;
clnt = new = nsm_create(net);
if (IS_ERR(clnt))
goto out;
clnt = nsm_client_set(ln, new);
if (clnt != new)
rpc_shutdown_client(new);
out:
return clnt;
}
static void nsm_client_put(struct net *net)
{
struct lockd_net *ln = net_generic(net, lockd_net_id);
struct rpc_clnt *clnt = NULL;
spin_lock(&ln->nsm_clnt_lock);
ln->nsm_users--;
if (ln->nsm_users == 0) {
clnt = ln->nsm_clnt;
ln->nsm_clnt = NULL;
}
spin_unlock(&ln->nsm_clnt_lock);
if (clnt != NULL)
rpc_shutdown_client(clnt);
}
static int nsm_mon_unmon(struct nsm_handle *nsm, u32 proc, struct nsm_res *res,
struct rpc_clnt *clnt)
{
int status;
struct nsm_args args = {
.priv = &nsm->sm_priv,
.prog = NLM_PROGRAM,
.vers = 3,
.proc = NLMPROC_NSM_NOTIFY,
.mon_name = nsm->sm_mon_name,
.nodename = clnt->cl_nodename,
};
struct rpc_message msg = {
.rpc_argp = &args,
.rpc_resp = res,
};
memset(res, 0, sizeof(*res));
msg.rpc_proc = &clnt->cl_procinfo[proc];
status = rpc_call_sync(clnt, &msg, RPC_TASK_SOFTCONN);
if (status == -ECONNREFUSED) {
dprintk("lockd: NSM upcall RPC failed, status=%d, forcing rebind\n",
status);
rpc_force_rebind(clnt);
status = rpc_call_sync(clnt, &msg, RPC_TASK_SOFTCONN);
}
if (status < 0)
dprintk("lockd: NSM upcall RPC failed, status=%d\n",
status);
else
status = 0;
return status;
}
int nsm_monitor(const struct nlm_host *host)
{
struct nsm_handle *nsm = host->h_nsmhandle;
struct nsm_res res;
int status;
struct rpc_clnt *clnt;
dprintk("lockd: nsm_monitor(%s)\n", nsm->sm_name);
if (nsm->sm_monitored)
return 0;
nsm->sm_mon_name = nsm_use_hostnames ? nsm->sm_name : nsm->sm_addrbuf;
clnt = nsm_client_get(host->net);
if (IS_ERR(clnt)) {
status = PTR_ERR(clnt);
dprintk("lockd: failed to create NSM upcall transport, "
"status=%d, net=%p\n", status, host->net);
return status;
}
status = nsm_mon_unmon(nsm, NSMPROC_MON, &res, clnt);
if (unlikely(res.status != 0))
status = -EIO;
if (unlikely(status < 0)) {
printk(KERN_NOTICE "lockd: cannot monitor %s\n", nsm->sm_name);
return status;
}
nsm->sm_monitored = 1;
if (unlikely(nsm_local_state != res.state)) {
nsm_local_state = res.state;
dprintk("lockd: NSM state changed to %d\n", nsm_local_state);
}
return 0;
}
void nsm_unmonitor(const struct nlm_host *host)
{
struct nsm_handle *nsm = host->h_nsmhandle;
struct nsm_res res;
int status;
if (atomic_read(&nsm->sm_count) == 1
&& nsm->sm_monitored && !nsm->sm_sticky) {
struct lockd_net *ln = net_generic(host->net, lockd_net_id);
dprintk("lockd: nsm_unmonitor(%s)\n", nsm->sm_name);
status = nsm_mon_unmon(nsm, NSMPROC_UNMON, &res, ln->nsm_clnt);
if (res.status != 0)
status = -EIO;
if (status < 0)
printk(KERN_NOTICE "lockd: cannot unmonitor %s\n",
nsm->sm_name);
else
nsm->sm_monitored = 0;
nsm_client_put(host->net);
}
}
static struct nsm_handle *nsm_lookup_hostname(const char *hostname,
const size_t len)
{
struct nsm_handle *nsm;
list_for_each_entry(nsm, &nsm_handles, sm_link)
if (strlen(nsm->sm_name) == len &&
memcmp(nsm->sm_name, hostname, len) == 0)
return nsm;
return NULL;
}
static struct nsm_handle *nsm_lookup_addr(const struct sockaddr *sap)
{
struct nsm_handle *nsm;
list_for_each_entry(nsm, &nsm_handles, sm_link)
if (rpc_cmp_addr(nsm_addr(nsm), sap))
return nsm;
return NULL;
}
static struct nsm_handle *nsm_lookup_priv(const struct nsm_private *priv)
{
struct nsm_handle *nsm;
list_for_each_entry(nsm, &nsm_handles, sm_link)
if (memcmp(nsm->sm_priv.data, priv->data,
sizeof(priv->data)) == 0)
return nsm;
return NULL;
}
static void nsm_init_private(struct nsm_handle *nsm)
{
u64 *p = (u64 *)&nsm->sm_priv.data;
s64 ns;
ns = ktime_get_ns();
put_unaligned(ns, p);
put_unaligned((unsigned long)nsm, p + 1);
}
static struct nsm_handle *nsm_create_handle(const struct sockaddr *sap,
const size_t salen,
const char *hostname,
const size_t hostname_len)
{
struct nsm_handle *new;
new = kzalloc(sizeof(*new) + hostname_len + 1, GFP_KERNEL);
if (unlikely(new == NULL))
return NULL;
atomic_set(&new->sm_count, 1);
new->sm_name = (char *)(new + 1);
memcpy(nsm_addr(new), sap, salen);
new->sm_addrlen = salen;
nsm_init_private(new);
if (rpc_ntop(nsm_addr(new), new->sm_addrbuf,
sizeof(new->sm_addrbuf)) == 0)
(void)snprintf(new->sm_addrbuf, sizeof(new->sm_addrbuf),
"unsupported address family");
memcpy(new->sm_name, hostname, hostname_len);
new->sm_name[hostname_len] = '\0';
return new;
}
struct nsm_handle *nsm_get_handle(const struct sockaddr *sap,
const size_t salen, const char *hostname,
const size_t hostname_len)
{
struct nsm_handle *cached, *new = NULL;
if (hostname && memchr(hostname, '/', hostname_len) != NULL) {
if (printk_ratelimit()) {
printk(KERN_WARNING "Invalid hostname \"%.*s\" "
"in NFS lock request\n",
(int)hostname_len, hostname);
}
return NULL;
}
retry:
spin_lock(&nsm_lock);
if (nsm_use_hostnames && hostname != NULL)
cached = nsm_lookup_hostname(hostname, hostname_len);
else
cached = nsm_lookup_addr(sap);
if (cached != NULL) {
atomic_inc(&cached->sm_count);
spin_unlock(&nsm_lock);
kfree(new);
dprintk("lockd: found nsm_handle for %s (%s), "
"cnt %d\n", cached->sm_name,
cached->sm_addrbuf,
atomic_read(&cached->sm_count));
return cached;
}
if (new != NULL) {
list_add(&new->sm_link, &nsm_handles);
spin_unlock(&nsm_lock);
dprintk("lockd: created nsm_handle for %s (%s)\n",
new->sm_name, new->sm_addrbuf);
return new;
}
spin_unlock(&nsm_lock);
new = nsm_create_handle(sap, salen, hostname, hostname_len);
if (unlikely(new == NULL))
return NULL;
goto retry;
}
struct nsm_handle *nsm_reboot_lookup(const struct nlm_reboot *info)
{
struct nsm_handle *cached;
spin_lock(&nsm_lock);
cached = nsm_lookup_priv(&info->priv);
if (unlikely(cached == NULL)) {
spin_unlock(&nsm_lock);
dprintk("lockd: never saw rebooted peer '%.*s' before\n",
info->len, info->mon);
return cached;
}
atomic_inc(&cached->sm_count);
spin_unlock(&nsm_lock);
dprintk("lockd: host %s (%s) rebooted, cnt %d\n",
cached->sm_name, cached->sm_addrbuf,
atomic_read(&cached->sm_count));
return cached;
}
void nsm_release(struct nsm_handle *nsm)
{
if (atomic_dec_and_lock(&nsm->sm_count, &nsm_lock)) {
list_del(&nsm->sm_link);
spin_unlock(&nsm_lock);
dprintk("lockd: destroyed nsm_handle for %s (%s)\n",
nsm->sm_name, nsm->sm_addrbuf);
kfree(nsm);
}
}
static void encode_nsm_string(struct xdr_stream *xdr, const char *string)
{
const u32 len = strlen(string);
__be32 *p;
p = xdr_reserve_space(xdr, 4 + len);
xdr_encode_opaque(p, string, len);
}
static void encode_mon_name(struct xdr_stream *xdr, const struct nsm_args *argp)
{
encode_nsm_string(xdr, argp->mon_name);
}
static void encode_my_id(struct xdr_stream *xdr, const struct nsm_args *argp)
{
__be32 *p;
encode_nsm_string(xdr, argp->nodename);
p = xdr_reserve_space(xdr, 4 + 4 + 4);
*p++ = cpu_to_be32(argp->prog);
*p++ = cpu_to_be32(argp->vers);
*p = cpu_to_be32(argp->proc);
}
static void encode_mon_id(struct xdr_stream *xdr, const struct nsm_args *argp)
{
encode_mon_name(xdr, argp);
encode_my_id(xdr, argp);
}
static void encode_priv(struct xdr_stream *xdr, const struct nsm_args *argp)
{
__be32 *p;
p = xdr_reserve_space(xdr, SM_PRIV_SIZE);
xdr_encode_opaque_fixed(p, argp->priv->data, SM_PRIV_SIZE);
}
static void nsm_xdr_enc_mon(struct rpc_rqst *req, struct xdr_stream *xdr,
const struct nsm_args *argp)
{
encode_mon_id(xdr, argp);
encode_priv(xdr, argp);
}
static void nsm_xdr_enc_unmon(struct rpc_rqst *req, struct xdr_stream *xdr,
const struct nsm_args *argp)
{
encode_mon_id(xdr, argp);
}
static int nsm_xdr_dec_stat_res(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct nsm_res *resp)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4 + 4);
if (unlikely(p == NULL))
return -EIO;
resp->status = be32_to_cpup(p++);
resp->state = be32_to_cpup(p);
dprintk("lockd: %s status %d state %d\n",
__func__, resp->status, resp->state);
return 0;
}
static int nsm_xdr_dec_stat(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct nsm_res *resp)
{
__be32 *p;
p = xdr_inline_decode(xdr, 4);
if (unlikely(p == NULL))
return -EIO;
resp->state = be32_to_cpup(p);
dprintk("lockd: %s state %d\n", __func__, resp->state);
return 0;
}
