static int nfs_get_cb_ident_idr(struct nfs_client *clp, int minorversion)
{
int ret = 0;
struct nfs_net *nn = net_generic(clp->cl_net, nfs_net_id);
if (clp->rpc_ops->version != 4 || minorversion != 0)
return ret;
idr_preload(GFP_KERNEL);
spin_lock(&nn->nfs_client_lock);
ret = idr_alloc(&nn->cb_ident_idr, clp, 1, 0, GFP_NOWAIT);
if (ret >= 0)
clp->cl_cb_ident = ret;
spin_unlock(&nn->nfs_client_lock);
idr_preload_end();
return ret < 0 ? ret : 0;
}
static struct nfs4_ds_server *
nfs4_find_ds_client(struct nfs_client *ds_clp, rpc_authflavor_t flavor)
{
struct nfs4_ds_server *dss;
rcu_read_lock();
list_for_each_entry_rcu(dss, &ds_clp->cl_ds_clients, list) {
if (dss->rpc_clnt->cl_auth->au_flavor != flavor)
continue;
goto out;
}
dss = NULL;
out:
rcu_read_unlock();
return dss;
}
static struct nfs4_ds_server *
nfs4_add_ds_client(struct nfs_client *ds_clp, rpc_authflavor_t flavor,
struct nfs4_ds_server *new)
{
struct nfs4_ds_server *dss;
spin_lock(&ds_clp->cl_lock);
list_for_each_entry(dss, &ds_clp->cl_ds_clients, list) {
if (dss->rpc_clnt->cl_auth->au_flavor != flavor)
continue;
goto out;
}
if (new)
list_add_rcu(&new->list, &ds_clp->cl_ds_clients);
dss = new;
out:
spin_unlock(&ds_clp->cl_lock);
return dss;
}
static struct nfs4_ds_server *
nfs4_alloc_ds_server(struct nfs_client *ds_clp, rpc_authflavor_t flavor)
{
struct nfs4_ds_server *dss;
dss = kmalloc(sizeof(*dss), GFP_NOFS);
if (dss == NULL)
return ERR_PTR(-ENOMEM);
dss->rpc_clnt = rpc_clone_client_set_auth(ds_clp->cl_rpcclient, flavor);
if (IS_ERR(dss->rpc_clnt)) {
int err = PTR_ERR(dss->rpc_clnt);
kfree (dss);
return ERR_PTR(err);
}
INIT_LIST_HEAD(&dss->list);
return dss;
}
static void
nfs4_free_ds_server(struct nfs4_ds_server *dss)
{
rpc_release_client(dss->rpc_clnt);
kfree(dss);
}
struct rpc_clnt *
nfs4_find_or_create_ds_client(struct nfs_client *ds_clp, struct inode *inode)
{
struct nfs4_ds_server *dss, *new;
rpc_authflavor_t flavor = NFS_SERVER(inode)->client->cl_auth->au_flavor;
dss = nfs4_find_ds_client(ds_clp, flavor);
if (dss != NULL)
goto out;
new = nfs4_alloc_ds_server(ds_clp, flavor);
if (IS_ERR(new))
return ERR_CAST(new);
dss = nfs4_add_ds_client(ds_clp, flavor, new);
if (dss != new)
nfs4_free_ds_server(new);
out:
return dss->rpc_clnt;
}
static void
nfs4_shutdown_ds_clients(struct nfs_client *clp)
{
struct nfs4_ds_server *dss;
LIST_HEAD(shutdown_list);
while (!list_empty(&clp->cl_ds_clients)) {
dss = list_entry(clp->cl_ds_clients.next,
struct nfs4_ds_server, list);
list_del(&dss->list);
rpc_shutdown_client(dss->rpc_clnt);
kfree (dss);
}
}
void nfs41_shutdown_client(struct nfs_client *clp)
{
if (nfs4_has_session(clp)) {
nfs4_shutdown_ds_clients(clp);
nfs4_destroy_session(clp->cl_session);
nfs4_destroy_clientid(clp);
}
}
void nfs40_shutdown_client(struct nfs_client *clp)
{
if (clp->cl_slot_tbl) {
nfs4_shutdown_slot_table(clp->cl_slot_tbl);
kfree(clp->cl_slot_tbl);
}
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
if (cl_init->minorversion > NFS4_MAX_MINOR_VERSION) {
err = -EINVAL;
goto error;
}
spin_lock_init(&clp->cl_lock);
INIT_DELAYED_WORK(&clp->cl_renewd, nfs4_renew_state);
INIT_LIST_HEAD(&clp->cl_ds_clients);
rpc_init_wait_queue(&clp->cl_rpcwaitq, "NFS client");
clp->cl_state = 1 << NFS4CLNT_LEASE_EXPIRED;
clp->cl_minorversion = cl_init->minorversion;
clp->cl_mvops = nfs_v4_minor_ops[cl_init->minorversion];
clp->cl_mig_gen = 1;
#if IS_ENABLED(CONFIG_NFS_V4_1)
init_waitqueue_head(&clp->cl_lock_waitq);
#endif
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
clp->cl_mvops->shutdown_client(clp);
nfs4_destroy_callback(clp);
if (__test_and_clear_bit(NFS_CS_IDMAP, &clp->cl_res_state))
nfs_idmap_delete(clp);
rpc_destroy_wait_queue(&clp->cl_rpcwaitq);
kfree(clp->cl_serverowner);
kfree(clp->cl_serverscope);
kfree(clp->cl_implid);
kfree(clp->cl_owner_id);
}
void nfs4_free_client(struct nfs_client *clp)
{
nfs4_shutdown_client(clp);
nfs_free_client(clp);
}
static int nfs4_init_callback(struct nfs_client *clp)
{
struct rpc_xprt *xprt;
int error;
xprt = rcu_dereference_raw(clp->cl_rpcclient->cl_xprt);
if (nfs4_has_session(clp)) {
error = xprt_setup_backchannel(xprt, NFS41_BC_MIN_CALLBACKS);
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
return 0;
}
int nfs40_init_client(struct nfs_client *clp)
{
struct nfs4_slot_table *tbl;
int ret;
tbl = kzalloc(sizeof(*tbl), GFP_NOFS);
if (tbl == NULL)
return -ENOMEM;
ret = nfs4_setup_slot_table(tbl, NFS4_MAX_SLOT_TABLE,
"NFSv4.0 transport Slot table");
if (ret) {
kfree(tbl);
return ret;
}
clp->cl_slot_tbl = tbl;
return 0;
}
int nfs41_init_client(struct nfs_client *clp)
{
struct nfs4_session *session = NULL;
session = nfs4_alloc_session(clp);
if (!session)
return -ENOMEM;
clp->cl_session = session;
nfs_mark_client_ready(clp, NFS_CS_SESSION_INITING);
return 0;
}
static int nfs4_init_client_minor_version(struct nfs_client *clp)
{
int ret;
ret = clp->cl_mvops->init_client(clp);
if (ret)
return ret;
return nfs4_init_callback(clp);
}
struct nfs_client *nfs4_init_client(struct nfs_client *clp,
const struct nfs_client_initdata *cl_init)
{
char buf[INET6_ADDRSTRLEN + 1];
const char *ip_addr = cl_init->ip_addr;
struct nfs_client *old;
int error;
if (clp->cl_cons_state == NFS_CS_READY)
return clp;
clp->rpc_ops = &nfs_v4_clientops;
if (clp->cl_minorversion != 0)
__set_bit(NFS_CS_INFINITE_SLOTS, &clp->cl_flags);
__set_bit(NFS_CS_DISCRTRY, &clp->cl_flags);
__set_bit(NFS_CS_NO_RETRANS_TIMEOUT, &clp->cl_flags);
error = nfs_create_rpc_client(clp, cl_init, RPC_AUTH_GSS_KRB5I);
if (error == -EINVAL)
error = nfs_create_rpc_client(clp, cl_init, RPC_AUTH_UNIX);
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
if (clp != old)
clp->cl_preserve_clid = true;
nfs_put_client(clp);
clear_bit(NFS_CS_TSM_POSSIBLE, &clp->cl_flags);
return old;
error:
nfs_mark_client_ready(clp, error);
nfs_put_client(clp);
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
static bool nfs4_match_client_owner_id(const struct nfs_client *clp1,
const struct nfs_client *clp2)
{
if (clp1->cl_owner_id == NULL || clp2->cl_owner_id == NULL)
return true;
return strcmp(clp1->cl_owner_id, clp2->cl_owner_id) == 0;
}
static bool nfs4_same_verifier(nfs4_verifier *v1, nfs4_verifier *v2)
{
return memcmp(v1->data, v2->data, sizeof(v1->data)) == 0;
}
static int nfs4_match_client(struct nfs_client *pos, struct nfs_client *new,
struct nfs_client **prev, struct nfs_net *nn)
{
int status;
if (pos->rpc_ops != new->rpc_ops)
return 1;
if (pos->cl_minorversion != new->cl_minorversion)
return 1;
if (pos->cl_cons_state > NFS_CS_READY) {
atomic_inc(&pos->cl_count);
spin_unlock(&nn->nfs_client_lock);
nfs_put_client(*prev);
*prev = pos;
status = nfs_wait_client_init_complete(pos);
spin_lock(&nn->nfs_client_lock);
if (status < 0)
return status;
}
if (pos->cl_cons_state != NFS_CS_READY)
return 1;
if (pos->cl_clientid != new->cl_clientid)
return 1;
if (!nfs4_match_client_owner_id(pos, new))
return 1;
return 0;
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
status = nfs4_match_client(pos, new, &prev, nn);
if (status < 0)
goto out_unlock;
if (status != 0)
continue;
if ((new != pos) && nfs4_same_verifier(&pos->cl_confirm,
&new->cl_confirm))
continue;
atomic_inc(&pos->cl_count);
spin_unlock(&nn->nfs_client_lock);
nfs_put_client(prev);
prev = pos;
status = nfs4_proc_setclientid_confirm(pos, &clid, cred);
switch (status) {
case -NFS4ERR_STALE_CLIENTID:
break;
case 0:
nfs4_swap_callback_idents(pos, new);
pos->cl_confirm = new->cl_confirm;
prev = NULL;
*result = pos;
goto out;
case -ERESTARTSYS:
case -ETIMEDOUT:
nfs4_schedule_path_down_recovery(pos);
default:
goto out;
}
spin_lock(&nn->nfs_client_lock);
}
out_unlock:
spin_unlock(&nn->nfs_client_lock);
out:
nfs_put_client(prev);
return status;
}
static bool
nfs4_check_serverowner_major_id(struct nfs41_server_owner *o1,
struct nfs41_server_owner *o2)
{
if (o1->major_id_sz != o2->major_id_sz)
return false;
return memcmp(o1->major_id, o2->major_id, o1->major_id_sz) == 0;
}
static bool
nfs4_check_server_scope(struct nfs41_server_scope *s1,
struct nfs41_server_scope *s2)
{
if (s1->server_scope_sz != s2->server_scope_sz)
return false;
return memcmp(s1->server_scope, s2->server_scope,
s1->server_scope_sz) == 0;
}
int nfs4_detect_session_trunking(struct nfs_client *clp,
struct nfs41_exchange_id_res *res,
struct rpc_xprt *xprt)
{
if (clp->cl_clientid != res->clientid)
goto out_err;
if (!nfs4_check_serverowner_major_id(clp->cl_serverowner,
res->server_owner))
goto out_err;
if (clp->cl_serverowner->minor_id != res->server_owner->minor_id)
goto out_err;
if (!nfs4_check_server_scope(clp->cl_serverscope, res->server_scope))
goto out_err;
pr_info("NFS: %s: Session trunking succeeded for %s\n",
clp->cl_hostname,
xprt->address_strings[RPC_DISPLAY_ADDR]);
return 0;
out_err:
pr_info("NFS: %s: Session trunking failed for %s\n", clp->cl_hostname,
xprt->address_strings[RPC_DISPLAY_ADDR]);
return -EINVAL;
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
if (pos == new)
goto found;
status = nfs4_match_client(pos, new, &prev, nn);
if (status < 0)
goto out;
if (status != 0)
continue;
if (!nfs4_check_serverowner_major_id(pos->cl_serverowner,
new->cl_serverowner))
continue;
found:
atomic_inc(&pos->cl_count);
*result = pos;
status = 0;
break;
}
out:
spin_unlock(&nn->nfs_client_lock);
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
return rpc_cmp_addr(addr, clap);
}
struct nfs_client *
nfs4_find_client_sessionid(struct net *net, const struct sockaddr *addr,
struct nfs4_sessionid *sid, u32 minorversion)
{
struct nfs_client *clp;
struct nfs_net *nn = net_generic(net, nfs_net_id);
spin_lock(&nn->nfs_client_lock);
list_for_each_entry(clp, &nn->nfs_client_list, cl_share_link) {
if (nfs4_cb_match_client(addr, clp, minorversion) == false)
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
struct nfs4_sessionid *sid, u32 minorversion)
{
return NULL;
}
static int nfs4_set_client(struct nfs_server *server,
const char *hostname,
const struct sockaddr *addr,
const size_t addrlen,
const char *ip_addr,
int proto, const struct rpc_timeout *timeparms,
u32 minorversion, struct net *net)
{
struct nfs_client_initdata cl_init = {
.hostname = hostname,
.addr = addr,
.addrlen = addrlen,
.ip_addr = ip_addr,
.nfs_mod = &nfs_v4,
.proto = proto,
.minorversion = minorversion,
.net = net,
.timeparms = timeparms,
};
struct nfs_client *clp;
if (server->flags & NFS_MOUNT_NORESVPORT)
set_bit(NFS_CS_NORESVPORT, &cl_init.init_flags);
if (server->options & NFS_OPTION_MIGRATION)
set_bit(NFS_CS_MIGRATION, &cl_init.init_flags);
if (test_bit(NFS_MIG_TSM_POSSIBLE, &server->mig_status))
set_bit(NFS_CS_TSM_POSSIBLE, &cl_init.init_flags);
clp = nfs_get_client(&cl_init);
if (IS_ERR(clp))
return PTR_ERR(clp);
if (server->nfs_client == clp)
return -ELOOP;
set_bit(NFS_CS_CHECK_LEASE_TIME, &clp->cl_res_state);
server->nfs_client = clp;
return 0;
}
struct nfs_client *nfs4_set_ds_client(struct nfs_server *mds_srv,
const struct sockaddr *ds_addr, int ds_addrlen,
int ds_proto, unsigned int ds_timeo, unsigned int ds_retrans,
u32 minor_version)
{
struct rpc_timeout ds_timeout;
struct nfs_client *mds_clp = mds_srv->nfs_client;
struct nfs_client_initdata cl_init = {
.addr = ds_addr,
.addrlen = ds_addrlen,
.nodename = mds_clp->cl_rpcclient->cl_nodename,
.ip_addr = mds_clp->cl_ipaddr,
.nfs_mod = &nfs_v4,
.proto = ds_proto,
.minorversion = minor_version,
.net = mds_clp->cl_net,
.timeparms = &ds_timeout,
};
char buf[INET6_ADDRSTRLEN + 1];
if (rpc_ntop(ds_addr, buf, sizeof(buf)) <= 0)
return ERR_PTR(-EINVAL);
cl_init.hostname = buf;
if (mds_srv->flags & NFS_MOUNT_NORESVPORT)
__set_bit(NFS_CS_NORESVPORT, &cl_init.init_flags);
nfs_init_timeout_values(&ds_timeout, ds_proto, ds_timeo, ds_retrans);
return nfs_get_client(&cl_init);
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
if (!server->rsize || server->rsize > server_resp_sz)
server->rsize = server_resp_sz;
if (!server->wsize || server->wsize > server_rqst_sz)
server->wsize = server_rqst_sz;
#endif
}
static int nfs4_server_common_setup(struct nfs_server *server,
struct nfs_fh *mntfh, bool auth_probe)
{
struct nfs_fattr *fattr;
int error;
if (is_ds_only_client(server->nfs_client))
return -EPROTONOSUPPORT;
fattr = nfs_alloc_fattr();
if (fattr == NULL)
return -ENOMEM;
error = nfs4_init_session(server->nfs_client);
if (error < 0)
goto out;
server->caps |= server->nfs_client->cl_mvops->init_caps;
if (server->flags & NFS_MOUNT_NORDIRPLUS)
server->caps &= ~NFS_CAP_READDIRPLUS;
if (nfs4_disable_idmapping &&
server->client->cl_auth->au_flavor == RPC_AUTH_UNIX)
server->caps |= NFS_CAP_UIDGID_NOMAP;
error = nfs4_get_rootfh(server, mntfh, auth_probe);
if (error < 0)
goto out;
dprintk("Server FSID: %llx:%llx\n",
(unsigned long long) server->fsid.major,
(unsigned long long) server->fsid.minor);
nfs_display_fhandle(mntfh, "Pseudo-fs root FH");
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
struct nfs_parsed_mount_data *data)
{
struct rpc_timeout timeparms;
int error;
nfs_init_timeout_values(&timeparms, data->nfs_server.protocol,
data->timeo, data->retrans);
server->flags = data->flags;
server->options = data->options;
server->auth_info = data->auth_info;
if (data->auth_info.flavor_len >= 1)
data->selected_flavor = data->auth_info.flavors[0];
else
data->selected_flavor = RPC_AUTH_UNIX;
error = nfs4_set_client(server,
data->nfs_server.hostname,
(const struct sockaddr *)&data->nfs_server.address,
data->nfs_server.addrlen,
data->client_address,
data->nfs_server.protocol,
&timeparms,
data->minorversion,
data->net);
if (error < 0)
return error;
if (data->rsize)
server->rsize = nfs_block_size(data->rsize, NULL);
if (data->wsize)
server->wsize = nfs_block_size(data->wsize, NULL);
server->acregmin = data->acregmin * HZ;
server->acregmax = data->acregmax * HZ;
server->acdirmin = data->acdirmin * HZ;
server->acdirmax = data->acdirmax * HZ;
server->port = data->nfs_server.port;
return nfs_init_server_rpcclient(server, &timeparms,
data->selected_flavor);
}
struct nfs_server *nfs4_create_server(struct nfs_mount_info *mount_info,
struct nfs_subversion *nfs_mod)
{
struct nfs_server *server;
bool auth_probe;
int error;
server = nfs_alloc_server();
if (!server)
return ERR_PTR(-ENOMEM);
auth_probe = mount_info->parsed->auth_info.flavor_len < 1;
error = nfs4_init_server(server, mount_info->parsed);
if (error < 0)
goto error;
error = nfs4_server_common_setup(server, mount_info->mntfh, auth_probe);
if (error < 0)
goto error;
return server;
error:
nfs_free_server(server);
return ERR_PTR(error);
}
struct nfs_server *nfs4_create_referral_server(struct nfs_clone_mount *data,
struct nfs_fh *mntfh)
{
struct nfs_client *parent_client;
struct nfs_server *server, *parent_server;
bool auth_probe;
int error;
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
rpc_protocol(parent_server->client),
parent_server->client->cl_timeout,
parent_client->cl_mvops->minor_version,
parent_client->cl_net);
if (error < 0)
goto error;
error = nfs_init_server_rpcclient(server, parent_server->client->cl_timeout, data->authflavor);
if (error < 0)
goto error;
auth_probe = parent_server->auth_info.flavor_len < 1;
error = nfs4_server_common_setup(server, mntfh, auth_probe);
if (error < 0)
goto error;
return server;
error:
nfs_free_server(server);
return ERR_PTR(error);
}
static int nfs_probe_destination(struct nfs_server *server)
{
struct inode *inode = d_inode(server->super->s_root);
struct nfs_fattr *fattr;
int error;
fattr = nfs_alloc_fattr();
if (fattr == NULL)
return -ENOMEM;
error = nfs_probe_fsinfo(server, NFS_FH(inode), fattr);
nfs_free_fattr(fattr);
return error;
}
int nfs4_update_server(struct nfs_server *server, const char *hostname,
struct sockaddr *sap, size_t salen, struct net *net)
{
struct nfs_client *clp = server->nfs_client;
struct rpc_clnt *clnt = server->client;
struct xprt_create xargs = {
.ident = clp->cl_proto,
.net = net,
.dstaddr = sap,
.addrlen = salen,
.servername = hostname,
};
char buf[INET6_ADDRSTRLEN + 1];
struct sockaddr_storage address;
struct sockaddr *localaddr = (struct sockaddr *)&address;
int error;
error = rpc_switch_client_transport(clnt, &xargs, clnt->cl_timeout);
if (error != 0)
return error;
error = rpc_localaddr(clnt, localaddr, sizeof(address));
if (error != 0)
return error;
if (rpc_ntop(localaddr, buf, sizeof(buf)) == 0)
return -EAFNOSUPPORT;
nfs_server_remove_lists(server);
set_bit(NFS_MIG_TSM_POSSIBLE, &server->mig_status);
error = nfs4_set_client(server, hostname, sap, salen, buf,
clp->cl_proto, clnt->cl_timeout,
clp->cl_minorversion, net);
clear_bit(NFS_MIG_TSM_POSSIBLE, &server->mig_status);
nfs_put_client(clp);
if (error != 0) {
nfs_server_insert_lists(server);
return error;
}
if (server->nfs_client->cl_hostname == NULL)
server->nfs_client->cl_hostname = kstrdup(hostname, GFP_KERNEL);
nfs_server_insert_lists(server);
return nfs_probe_destination(server);
}
