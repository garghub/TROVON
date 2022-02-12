static int nfs_get_cb_ident_idr(struct nfs_client *clp, int minorversion)
{
int ret = 0;
struct nfs_net *nn = net_generic(clp->cl_net, nfs_net_id);
if (clp->rpc_ops->version != 4 || minorversion != 0)
return ret;
idr_preload(GFP_KERNEL);
spin_lock(&nn->nfs_client_lock);
ret = idr_alloc(&nn->cb_ident_idr, clp, 0, 0, GFP_NOWAIT);
if (ret >= 0)
clp->cl_cb_ident = ret;
spin_unlock(&nn->nfs_client_lock);
idr_preload_end();
return ret < 0 ? ret : 0;
}
static void nfs4_shutdown_session(struct nfs_client *clp)
{
if (nfs4_has_session(clp)) {
nfs4_destroy_session(clp->cl_session);
nfs4_destroy_clientid(clp);
}
}
static void nfs4_shutdown_session(struct nfs_client *clp)
{
}
struct nfs_client *nfs4_alloc_client(const struct nfs_client_initdata *cl_init)
{
int err;
struct nfs_client *clp = nfs_alloc_client(cl_init);
if (IS_ERR(clp))
return clp;
err = nfs_get_cb_ident_idr(clp, cl_init->minorversion);
if (err)
goto error;
spin_lock_init(&clp->cl_lock);
INIT_DELAYED_WORK(&clp->cl_renewd, nfs4_renew_state);
rpc_init_wait_queue(&clp->cl_rpcwaitq, "NFS client");
clp->cl_state = 1 << NFS4CLNT_LEASE_EXPIRED;
clp->cl_minorversion = cl_init->minorversion;
clp->cl_mvops = nfs_v4_minor_ops[cl_init->minorversion];
return clp;
error:
nfs_free_client(clp);
return ERR_PTR(err);
}
static void nfs4_destroy_callback(struct nfs_client *clp)
{
if (__test_and_clear_bit(NFS_CS_CALLBACK, &clp->cl_res_state))
nfs_callback_down(clp->cl_mvops->minor_version, clp->cl_net);
}
static void nfs4_shutdown_client(struct nfs_client *clp)
{
if (__test_and_clear_bit(NFS_CS_RENEWD, &clp->cl_res_state))
nfs4_kill_renewd(clp);
nfs4_shutdown_session(clp);
nfs4_destroy_callback(clp);
if (__test_and_clear_bit(NFS_CS_IDMAP, &clp->cl_res_state))
nfs_idmap_delete(clp);
rpc_destroy_wait_queue(&clp->cl_rpcwaitq);
kfree(clp->cl_serverowner);
kfree(clp->cl_serverscope);
kfree(clp->cl_implid);
}
void nfs4_free_client(struct nfs_client *clp)
{
nfs4_shutdown_client(clp);
nfs_free_client(clp);
}
static int nfs4_init_callback(struct nfs_client *clp)
{
int error;
if (clp->rpc_ops->version == 4) {
struct rpc_xprt *xprt;
xprt = rcu_dereference_raw(clp->cl_rpcclient->cl_xprt);
if (nfs4_has_session(clp)) {
error = xprt_setup_backchannel(xprt,
NFS41_BC_MIN_CALLBACKS);
if (error < 0)
return error;
}
error = nfs_callback_up(clp->cl_mvops->minor_version, xprt);
if (error < 0) {
dprintk("%s: failed to start callback. Error = %d\n",
__func__, error);
return error;
}
__set_bit(NFS_CS_CALLBACK, &clp->cl_res_state);
}
return 0;
}
static int nfs4_init_client_minor_version(struct nfs_client *clp)
{
#if defined(CONFIG_NFS_V4_1)
if (clp->cl_mvops->minor_version) {
struct nfs4_session *session = NULL;
session = nfs4_alloc_session(clp);
if (!session)
return -ENOMEM;
clp->cl_session = session;
nfs_mark_client_ready(clp, NFS_CS_SESSION_INITING);
}
#endif
return nfs4_init_callback(clp);
}
struct nfs_client *nfs4_init_client(struct nfs_client *clp,
const struct rpc_timeout *timeparms,
const char *ip_addr,
rpc_authflavor_t authflavour)
{
char buf[INET6_ADDRSTRLEN + 1];
struct nfs_client *old;
int error;
if (clp->cl_cons_state == NFS_CS_READY) {
dprintk("<-- nfs4_init_client() = 0 [already %p]\n", clp);
return clp;
}
clp->rpc_ops = &nfs_v4_clientops;
if (clp->cl_minorversion != 0)
__set_bit(NFS_CS_INFINITE_SLOTS, &clp->cl_flags);
__set_bit(NFS_CS_DISCRTRY, &clp->cl_flags);
error = nfs_create_rpc_client(clp, timeparms, RPC_AUTH_GSS_KRB5I);
if (error == -EINVAL)
error = nfs_create_rpc_client(clp, timeparms, RPC_AUTH_UNIX);
if (error < 0)
goto error;
if (ip_addr == NULL) {
struct sockaddr_storage cb_addr;
struct sockaddr *sap = (struct sockaddr *)&cb_addr;
error = rpc_localaddr(clp->cl_rpcclient, sap, sizeof(cb_addr));
if (error < 0)
goto error;
error = rpc_ntop(sap, buf, sizeof(buf));
if (error < 0)
goto error;
ip_addr = (const char *)buf;
}
strlcpy(clp->cl_ipaddr, ip_addr, sizeof(clp->cl_ipaddr));
error = nfs_idmap_new(clp);
if (error < 0) {
dprintk("%s: failed to create idmapper. Error = %d\n",
__func__, error);
goto error;
}
__set_bit(NFS_CS_IDMAP, &clp->cl_res_state);
error = nfs4_init_client_minor_version(clp);
if (error < 0)
goto error;
if (!nfs4_has_session(clp))
nfs_mark_client_ready(clp, NFS_CS_READY);
error = nfs4_discover_server_trunking(clp, &old);
if (error < 0)
goto error;
nfs_put_client(clp);
if (clp != old) {
clp->cl_preserve_clid = true;
clp = old;
}
return clp;
error:
nfs_mark_client_ready(clp, error);
nfs_put_client(clp);
dprintk("<-- nfs4_init_client() = xerror %d\n", error);
return ERR_PTR(error);
}
static void nfs4_swap_callback_idents(struct nfs_client *keep,
struct nfs_client *drop)
{
struct nfs_net *nn = net_generic(keep->cl_net, nfs_net_id);
unsigned int save = keep->cl_cb_ident;
if (keep->cl_cb_ident == drop->cl_cb_ident)
return;
dprintk("%s: keeping callback ident %u and dropping ident %u\n",
__func__, keep->cl_cb_ident, drop->cl_cb_ident);
spin_lock(&nn->nfs_client_lock);
idr_replace(&nn->cb_ident_idr, keep, drop->cl_cb_ident);
keep->cl_cb_ident = drop->cl_cb_ident;
idr_replace(&nn->cb_ident_idr, drop, save);
drop->cl_cb_ident = save;
spin_unlock(&nn->nfs_client_lock);
}
int nfs40_walk_client_list(struct nfs_client *new,
struct nfs_client **result,
struct rpc_cred *cred)
{
struct nfs_net *nn = net_generic(new->cl_net, nfs_net_id);
struct nfs_client *pos, *prev = NULL;
struct nfs4_setclientid_res clid = {
.clientid = new->cl_clientid,
.confirm = new->cl_confirm,
};
int status = -NFS4ERR_STALE_CLIENTID;
spin_lock(&nn->nfs_client_lock);
list_for_each_entry(pos, &nn->nfs_client_list, cl_share_link) {
if (pos->cl_cons_state > NFS_CS_READY) {
atomic_inc(&pos->cl_count);
spin_unlock(&nn->nfs_client_lock);
if (prev)
nfs_put_client(prev);
prev = pos;
status = nfs_wait_client_init_complete(pos);
spin_lock(&nn->nfs_client_lock);
if (status < 0)
continue;
}
if (pos->cl_cons_state != NFS_CS_READY)
continue;
if (pos->rpc_ops != new->rpc_ops)
continue;
if (pos->cl_proto != new->cl_proto)
continue;
if (pos->cl_minorversion != new->cl_minorversion)
continue;
if (pos->cl_clientid != new->cl_clientid)
continue;
atomic_inc(&pos->cl_count);
spin_unlock(&nn->nfs_client_lock);
if (prev)
nfs_put_client(prev);
prev = pos;
status = nfs4_proc_setclientid_confirm(pos, &clid, cred);
switch (status) {
case -NFS4ERR_STALE_CLIENTID:
break;
case 0:
nfs4_swap_callback_idents(pos, new);
prev = NULL;
*result = pos;
dprintk("NFS: <-- %s using nfs_client = %p ({%d})\n",
__func__, pos, atomic_read(&pos->cl_count));
default:
goto out;
}
spin_lock(&nn->nfs_client_lock);
}
spin_unlock(&nn->nfs_client_lock);
out:
if (prev)
nfs_put_client(prev);
dprintk("NFS: <-- %s status = %d\n", __func__, status);
return status;
}
static bool nfs4_match_clientids(struct nfs_client *a, struct nfs_client *b)
{
if (a->cl_clientid != b->cl_clientid) {
dprintk("NFS: --> %s client ID %llx does not match %llx\n",
__func__, a->cl_clientid, b->cl_clientid);
return false;
}
dprintk("NFS: --> %s client ID %llx matches %llx\n",
__func__, a->cl_clientid, b->cl_clientid);
return true;
}
static bool
nfs4_match_serverowners(struct nfs_client *a, struct nfs_client *b)
{
struct nfs41_server_owner *o1 = a->cl_serverowner;
struct nfs41_server_owner *o2 = b->cl_serverowner;
if (o1->minor_id != o2->minor_id) {
dprintk("NFS: --> %s server owner minor IDs do not match\n",
__func__);
return false;
}
if (o1->major_id_sz != o2->major_id_sz)
goto out_major_mismatch;
if (memcmp(o1->major_id, o2->major_id, o1->major_id_sz) != 0)
goto out_major_mismatch;
dprintk("NFS: --> %s server owners match\n", __func__);
return true;
out_major_mismatch:
dprintk("NFS: --> %s server owner major IDs do not match\n",
__func__);
return false;
}
int nfs41_walk_client_list(struct nfs_client *new,
struct nfs_client **result,
struct rpc_cred *cred)
{
struct nfs_net *nn = net_generic(new->cl_net, nfs_net_id);
struct nfs_client *pos, *prev = NULL;
int status = -NFS4ERR_STALE_CLIENTID;
spin_lock(&nn->nfs_client_lock);
list_for_each_entry(pos, &nn->nfs_client_list, cl_share_link) {
if (pos->cl_cons_state > NFS_CS_READY) {
atomic_inc(&pos->cl_count);
spin_unlock(&nn->nfs_client_lock);
if (prev)
nfs_put_client(prev);
prev = pos;
status = nfs_wait_client_init_complete(pos);
if (status == 0) {
nfs4_schedule_lease_recovery(pos);
status = nfs4_wait_clnt_recover(pos);
}
spin_lock(&nn->nfs_client_lock);
if (status < 0)
continue;
}
if (pos->cl_cons_state != NFS_CS_READY)
continue;
if (pos->rpc_ops != new->rpc_ops)
continue;
if (pos->cl_proto != new->cl_proto)
continue;
if (pos->cl_minorversion != new->cl_minorversion)
continue;
if (!nfs4_match_clientids(pos, new))
continue;
if (!nfs4_match_serverowners(pos, new))
continue;
atomic_inc(&pos->cl_count);
*result = pos;
status = 0;
dprintk("NFS: <-- %s using nfs_client = %p ({%d})\n",
__func__, pos, atomic_read(&pos->cl_count));
break;
}
spin_unlock(&nn->nfs_client_lock);
dprintk("NFS: <-- %s status = %d\n", __func__, status);
if (prev)
nfs_put_client(prev);
return status;
}
static void nfs4_destroy_server(struct nfs_server *server)
{
nfs_server_return_all_delegations(server);
unset_pnfs_layoutdriver(server);
nfs4_purge_state_owners(server);
}
struct nfs_client *
nfs4_find_client_ident(struct net *net, int cb_ident)
{
struct nfs_client *clp;
struct nfs_net *nn = net_generic(net, nfs_net_id);
spin_lock(&nn->nfs_client_lock);
clp = idr_find(&nn->cb_ident_idr, cb_ident);
if (clp)
atomic_inc(&clp->cl_count);
spin_unlock(&nn->nfs_client_lock);
return clp;
}
static bool nfs4_cb_match_client(const struct sockaddr *addr,
struct nfs_client *clp, u32 minorversion)
{
struct sockaddr *clap = (struct sockaddr *)&clp->cl_addr;
if (!(clp->cl_cons_state == NFS_CS_READY ||
clp->cl_cons_state == NFS_CS_SESSION_INITING))
return false;
smp_rmb();
if (clp->rpc_ops->version != 4 ||
clp->cl_minorversion != minorversion)
return false;
if (!nfs_sockaddr_match_ipaddr(addr, clap))
return false;
return true;
}
struct nfs_client *
nfs4_find_client_sessionid(struct net *net, const struct sockaddr *addr,
struct nfs4_sessionid *sid)
{
struct nfs_client *clp;
struct nfs_net *nn = net_generic(net, nfs_net_id);
spin_lock(&nn->nfs_client_lock);
list_for_each_entry(clp, &nn->nfs_client_list, cl_share_link) {
if (nfs4_cb_match_client(addr, clp, 1) == false)
continue;
if (!nfs4_has_session(clp))
continue;
if (memcmp(clp->cl_session->sess_id.data,
sid->data, NFS4_MAX_SESSIONID_LEN) != 0)
continue;
atomic_inc(&clp->cl_count);
spin_unlock(&nn->nfs_client_lock);
return clp;
}
spin_unlock(&nn->nfs_client_lock);
return NULL;
}
struct nfs_client *
nfs4_find_client_sessionid(struct net *net, const struct sockaddr *addr,
struct nfs4_sessionid *sid)
{
return NULL;
}
static int nfs4_set_client(struct nfs_server *server,
const char *hostname,
const struct sockaddr *addr,
const size_t addrlen,
const char *ip_addr,
rpc_authflavor_t authflavour,
int proto, const struct rpc_timeout *timeparms,
u32 minorversion, struct net *net)
{
struct nfs_client_initdata cl_init = {
.hostname = hostname,
.addr = addr,
.addrlen = addrlen,
.nfs_mod = &nfs_v4,
.proto = proto,
.minorversion = minorversion,
.net = net,
};
struct nfs_client *clp;
int error;
dprintk("--> nfs4_set_client()\n");
if (server->flags & NFS_MOUNT_NORESVPORT)
set_bit(NFS_CS_NORESVPORT, &cl_init.init_flags);
clp = nfs_get_client(&cl_init, timeparms, ip_addr, authflavour);
if (IS_ERR(clp)) {
error = PTR_ERR(clp);
goto error;
}
set_bit(NFS_CS_CHECK_LEASE_TIME, &clp->cl_res_state);
server->nfs_client = clp;
dprintk("<-- nfs4_set_client() = 0 [new %p]\n", clp);
return 0;
error:
dprintk("<-- nfs4_set_client() = xerror %d\n", error);
return error;
}
struct nfs_client *nfs4_set_ds_client(struct nfs_client* mds_clp,
const struct sockaddr *ds_addr, int ds_addrlen,
int ds_proto, unsigned int ds_timeo, unsigned int ds_retrans)
{
struct nfs_client_initdata cl_init = {
.addr = ds_addr,
.addrlen = ds_addrlen,
.nfs_mod = &nfs_v4,
.proto = ds_proto,
.minorversion = mds_clp->cl_minorversion,
.net = mds_clp->cl_net,
};
struct rpc_timeout ds_timeout;
struct nfs_client *clp;
nfs_init_timeout_values(&ds_timeout, ds_proto, ds_timeo, ds_retrans);
clp = nfs_get_client(&cl_init, &ds_timeout, mds_clp->cl_ipaddr,
mds_clp->cl_rpcclient->cl_auth->au_flavor);
dprintk("<-- %s %p\n", __func__, clp);
return clp;
}
static void nfs4_session_set_rwsize(struct nfs_server *server)
{
#ifdef CONFIG_NFS_V4_1
struct nfs4_session *sess;
u32 server_resp_sz;
u32 server_rqst_sz;
if (!nfs4_has_session(server->nfs_client))
return;
sess = server->nfs_client->cl_session;
server_resp_sz = sess->fc_attrs.max_resp_sz - nfs41_maxread_overhead;
server_rqst_sz = sess->fc_attrs.max_rqst_sz - nfs41_maxwrite_overhead;
if (server->rsize > server_resp_sz)
server->rsize = server_resp_sz;
if (server->wsize > server_rqst_sz)
server->wsize = server_rqst_sz;
#endif
}
static int nfs4_server_common_setup(struct nfs_server *server,
struct nfs_fh *mntfh)
{
struct nfs_fattr *fattr;
int error;
if (is_ds_only_client(server->nfs_client))
return -EPROTONOSUPPORT;
fattr = nfs_alloc_fattr();
if (fattr == NULL)
return -ENOMEM;
error = nfs4_init_session(server);
if (error < 0)
goto out;
server->caps |= server->nfs_client->cl_mvops->init_caps;
if (server->flags & NFS_MOUNT_NORDIRPLUS)
server->caps &= ~NFS_CAP_READDIRPLUS;
if (nfs4_disable_idmapping &&
server->client->cl_auth->au_flavor == RPC_AUTH_UNIX)
server->caps |= NFS_CAP_UIDGID_NOMAP;
error = nfs4_get_rootfh(server, mntfh);
if (error < 0)
goto out;
dprintk("Server FSID: %llx:%llx\n",
(unsigned long long) server->fsid.major,
(unsigned long long) server->fsid.minor);
dprintk("Mount FH: %d\n", mntfh->size);
nfs4_session_set_rwsize(server);
error = nfs_probe_fsinfo(server, mntfh, fattr);
if (error < 0)
goto out;
if (server->namelen == 0 || server->namelen > NFS4_MAXNAMLEN)
server->namelen = NFS4_MAXNAMLEN;
nfs_server_insert_lists(server);
server->mount_time = jiffies;
server->destroy = nfs4_destroy_server;
out:
nfs_free_fattr(fattr);
return error;
}
static int nfs4_init_server(struct nfs_server *server,
const struct nfs_parsed_mount_data *data)
{
struct rpc_timeout timeparms;
int error;
dprintk("--> nfs4_init_server()\n");
nfs_init_timeout_values(&timeparms, data->nfs_server.protocol,
data->timeo, data->retrans);
server->flags = data->flags;
server->options = data->options;
error = nfs4_set_client(server,
data->nfs_server.hostname,
(const struct sockaddr *)&data->nfs_server.address,
data->nfs_server.addrlen,
data->client_address,
data->auth_flavors[0],
data->nfs_server.protocol,
&timeparms,
data->minorversion,
data->net);
if (error < 0)
goto error;
if (data->rsize)
server->rsize = nfs_block_size(data->rsize, NULL);
if (data->wsize)
server->wsize = nfs_block_size(data->wsize, NULL);
server->acregmin = data->acregmin * HZ;
server->acregmax = data->acregmax * HZ;
server->acdirmin = data->acdirmin * HZ;
server->acdirmax = data->acdirmax * HZ;
server->port = data->nfs_server.port;
error = nfs_init_server_rpcclient(server, &timeparms, data->auth_flavors[0]);
error:
dprintk("<-- nfs4_init_server() = %d\n", error);
return error;
}
struct nfs_server *nfs4_create_server(struct nfs_mount_info *mount_info,
struct nfs_subversion *nfs_mod)
{
struct nfs_server *server;
int error;
dprintk("--> nfs4_create_server()\n");
server = nfs_alloc_server();
if (!server)
return ERR_PTR(-ENOMEM);
error = nfs4_init_server(server, mount_info->parsed);
if (error < 0)
goto error;
error = nfs4_server_common_setup(server, mount_info->mntfh);
if (error < 0)
goto error;
dprintk("<-- nfs4_create_server() = %p\n", server);
return server;
error:
nfs_free_server(server);
dprintk("<-- nfs4_create_server() = error %d\n", error);
return ERR_PTR(error);
}
struct nfs_server *nfs4_create_referral_server(struct nfs_clone_mount *data,
struct nfs_fh *mntfh)
{
struct nfs_client *parent_client;
struct nfs_server *server, *parent_server;
int error;
dprintk("--> nfs4_create_referral_server()\n");
server = nfs_alloc_server();
if (!server)
return ERR_PTR(-ENOMEM);
parent_server = NFS_SB(data->sb);
parent_client = parent_server->nfs_client;
nfs_server_copy_userdata(server, parent_server);
error = nfs4_set_client(server, data->hostname,
data->addr,
data->addrlen,
parent_client->cl_ipaddr,
data->authflavor,
rpc_protocol(parent_server->client),
parent_server->client->cl_timeout,
parent_client->cl_mvops->minor_version,
parent_client->cl_net);
if (error < 0)
goto error;
error = nfs_init_server_rpcclient(server, parent_server->client->cl_timeout, data->authflavor);
if (error < 0)
goto error;
error = nfs4_server_common_setup(server, mntfh);
if (error < 0)
goto error;
dprintk("<-- nfs_create_referral_server() = %p\n", server);
return server;
error:
nfs_free_server(server);
dprintk("<-- nfs4_create_referral_server() = error %d\n", error);
return ERR_PTR(error);
}
