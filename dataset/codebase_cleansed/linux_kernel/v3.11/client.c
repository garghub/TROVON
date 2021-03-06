static struct nfs_subversion *find_nfs_version(unsigned int version)
{
struct nfs_subversion *nfs;
spin_lock(&nfs_version_lock);
list_for_each_entry(nfs, &nfs_versions, list) {
if (nfs->rpc_ops->version == version) {
spin_unlock(&nfs_version_lock);
return nfs;
}
}
spin_unlock(&nfs_version_lock);
return ERR_PTR(-EPROTONOSUPPORT);
}
struct nfs_subversion *get_nfs_version(unsigned int version)
{
struct nfs_subversion *nfs = find_nfs_version(version);
if (IS_ERR(nfs)) {
mutex_lock(&nfs_version_mutex);
request_module("nfsv%d", version);
nfs = find_nfs_version(version);
mutex_unlock(&nfs_version_mutex);
}
if (!IS_ERR(nfs))
try_module_get(nfs->owner);
return nfs;
}
void put_nfs_version(struct nfs_subversion *nfs)
{
module_put(nfs->owner);
}
void register_nfs_version(struct nfs_subversion *nfs)
{
spin_lock(&nfs_version_lock);
list_add(&nfs->list, &nfs_versions);
nfs_version[nfs->rpc_ops->version] = nfs->rpc_vers;
spin_unlock(&nfs_version_lock);
}
void unregister_nfs_version(struct nfs_subversion *nfs)
{
spin_lock(&nfs_version_lock);
nfs_version[nfs->rpc_ops->version] = NULL;
list_del(&nfs->list);
spin_unlock(&nfs_version_lock);
}
struct nfs_client *nfs_alloc_client(const struct nfs_client_initdata *cl_init)
{
struct nfs_client *clp;
struct rpc_cred *cred;
int err = -ENOMEM;
if ((clp = kzalloc(sizeof(*clp), GFP_KERNEL)) == NULL)
goto error_0;
clp->cl_nfs_mod = cl_init->nfs_mod;
try_module_get(clp->cl_nfs_mod->owner);
clp->rpc_ops = clp->cl_nfs_mod->rpc_ops;
atomic_set(&clp->cl_count, 1);
clp->cl_cons_state = NFS_CS_INITING;
memcpy(&clp->cl_addr, cl_init->addr, cl_init->addrlen);
clp->cl_addrlen = cl_init->addrlen;
if (cl_init->hostname) {
err = -ENOMEM;
clp->cl_hostname = kstrdup(cl_init->hostname, GFP_KERNEL);
if (!clp->cl_hostname)
goto error_cleanup;
}
INIT_LIST_HEAD(&clp->cl_superblocks);
clp->cl_rpcclient = ERR_PTR(-EINVAL);
clp->cl_proto = cl_init->proto;
clp->cl_net = get_net(cl_init->net);
cred = rpc_lookup_machine_cred("*");
if (!IS_ERR(cred))
clp->cl_machine_cred = cred;
nfs_fscache_get_client_cookie(clp);
return clp;
error_cleanup:
put_nfs_version(clp->cl_nfs_mod);
kfree(clp);
error_0:
return ERR_PTR(err);
}
void nfs_cleanup_cb_ident_idr(struct net *net)
{
struct nfs_net *nn = net_generic(net, nfs_net_id);
idr_destroy(&nn->cb_ident_idr);
}
static void nfs_cb_idr_remove_locked(struct nfs_client *clp)
{
struct nfs_net *nn = net_generic(clp->cl_net, nfs_net_id);
if (clp->cl_cb_ident)
idr_remove(&nn->cb_ident_idr, clp->cl_cb_ident);
}
static void pnfs_init_server(struct nfs_server *server)
{
rpc_init_wait_queue(&server->roc_rpcwaitq, "pNFS ROC");
}
void nfs_cleanup_cb_ident_idr(struct net *net)
{
}
static void nfs_cb_idr_remove_locked(struct nfs_client *clp)
{
}
static void pnfs_init_server(struct nfs_server *server)
{
}
void nfs_free_client(struct nfs_client *clp)
{
dprintk("--> nfs_free_client(%u)\n", clp->rpc_ops->version);
nfs_fscache_release_client_cookie(clp);
if (!IS_ERR(clp->cl_rpcclient))
rpc_shutdown_client(clp->cl_rpcclient);
if (clp->cl_machine_cred != NULL)
put_rpccred(clp->cl_machine_cred);
put_net(clp->cl_net);
put_nfs_version(clp->cl_nfs_mod);
kfree(clp->cl_hostname);
kfree(clp);
dprintk("<-- nfs_free_client()\n");
}
void nfs_put_client(struct nfs_client *clp)
{
struct nfs_net *nn;
if (!clp)
return;
dprintk("--> nfs_put_client({%d})\n", atomic_read(&clp->cl_count));
nn = net_generic(clp->cl_net, nfs_net_id);
if (atomic_dec_and_lock(&clp->cl_count, &nn->nfs_client_lock)) {
list_del(&clp->cl_share_link);
nfs_cb_idr_remove_locked(clp);
spin_unlock(&nn->nfs_client_lock);
WARN_ON_ONCE(!list_empty(&clp->cl_superblocks));
clp->rpc_ops->free_client(clp);
}
}
static int nfs_sockaddr_match_ipaddr6(const struct sockaddr *sa1,
const struct sockaddr *sa2)
{
const struct sockaddr_in6 *sin1 = (const struct sockaddr_in6 *)sa1;
const struct sockaddr_in6 *sin2 = (const struct sockaddr_in6 *)sa2;
if (!ipv6_addr_equal(&sin1->sin6_addr, &sin2->sin6_addr))
return 0;
else if (ipv6_addr_type(&sin1->sin6_addr) & IPV6_ADDR_LINKLOCAL)
return sin1->sin6_scope_id == sin2->sin6_scope_id;
return 1;
}
static int nfs_sockaddr_match_ipaddr6(const struct sockaddr *sa1,
const struct sockaddr *sa2)
{
return 0;
}
static int nfs_sockaddr_match_ipaddr4(const struct sockaddr *sa1,
const struct sockaddr *sa2)
{
const struct sockaddr_in *sin1 = (const struct sockaddr_in *)sa1;
const struct sockaddr_in *sin2 = (const struct sockaddr_in *)sa2;
return sin1->sin_addr.s_addr == sin2->sin_addr.s_addr;
}
static int nfs_sockaddr_cmp_ip6(const struct sockaddr *sa1,
const struct sockaddr *sa2)
{
const struct sockaddr_in6 *sin1 = (const struct sockaddr_in6 *)sa1;
const struct sockaddr_in6 *sin2 = (const struct sockaddr_in6 *)sa2;
return nfs_sockaddr_match_ipaddr6(sa1, sa2) &&
(sin1->sin6_port == sin2->sin6_port);
}
static int nfs_sockaddr_cmp_ip4(const struct sockaddr *sa1,
const struct sockaddr *sa2)
{
const struct sockaddr_in *sin1 = (const struct sockaddr_in *)sa1;
const struct sockaddr_in *sin2 = (const struct sockaddr_in *)sa2;
return nfs_sockaddr_match_ipaddr4(sa1, sa2) &&
(sin1->sin_port == sin2->sin_port);
}
int nfs_sockaddr_match_ipaddr(const struct sockaddr *sa1,
const struct sockaddr *sa2)
{
if (sa1->sa_family != sa2->sa_family)
return 0;
switch (sa1->sa_family) {
case AF_INET:
return nfs_sockaddr_match_ipaddr4(sa1, sa2);
case AF_INET6:
return nfs_sockaddr_match_ipaddr6(sa1, sa2);
}
return 0;
}
static int nfs_sockaddr_cmp(const struct sockaddr *sa1,
const struct sockaddr *sa2)
{
if (sa1->sa_family != sa2->sa_family)
return 0;
switch (sa1->sa_family) {
case AF_INET:
return nfs_sockaddr_cmp_ip4(sa1, sa2);
case AF_INET6:
return nfs_sockaddr_cmp_ip6(sa1, sa2);
}
return 0;
}
static struct nfs_client *nfs_match_client(const struct nfs_client_initdata *data)
{
struct nfs_client *clp;
const struct sockaddr *sap = data->addr;
struct nfs_net *nn = net_generic(data->net, nfs_net_id);
list_for_each_entry(clp, &nn->nfs_client_list, cl_share_link) {
const struct sockaddr *clap = (struct sockaddr *)&clp->cl_addr;
if (clp->cl_cons_state < 0)
continue;
if (clp->rpc_ops != data->nfs_mod->rpc_ops)
continue;
if (clp->cl_proto != data->proto)
continue;
if (clp->cl_minorversion != data->minorversion)
continue;
if (!nfs_sockaddr_cmp(sap, clap))
continue;
atomic_inc(&clp->cl_count);
return clp;
}
return NULL;
}
static bool nfs_client_init_is_complete(const struct nfs_client *clp)
{
return clp->cl_cons_state != NFS_CS_INITING;
}
int nfs_wait_client_init_complete(const struct nfs_client *clp)
{
return wait_event_killable(nfs_client_active_wq,
nfs_client_init_is_complete(clp));
}
static struct nfs_client *
nfs_found_client(const struct nfs_client_initdata *cl_init,
struct nfs_client *clp)
{
int error;
error = nfs_wait_client_init_complete(clp);
if (error < 0) {
nfs_put_client(clp);
return ERR_PTR(-ERESTARTSYS);
}
if (clp->cl_cons_state < NFS_CS_READY) {
error = clp->cl_cons_state;
nfs_put_client(clp);
return ERR_PTR(error);
}
smp_rmb();
dprintk("<-- %s found nfs_client %p for %s\n",
__func__, clp, cl_init->hostname ?: "");
return clp;
}
struct nfs_client *
nfs_get_client(const struct nfs_client_initdata *cl_init,
const struct rpc_timeout *timeparms,
const char *ip_addr,
rpc_authflavor_t authflavour)
{
struct nfs_client *clp, *new = NULL;
struct nfs_net *nn = net_generic(cl_init->net, nfs_net_id);
const struct nfs_rpc_ops *rpc_ops = cl_init->nfs_mod->rpc_ops;
dprintk("--> nfs_get_client(%s,v%u)\n",
cl_init->hostname ?: "", rpc_ops->version);
do {
spin_lock(&nn->nfs_client_lock);
clp = nfs_match_client(cl_init);
if (clp) {
spin_unlock(&nn->nfs_client_lock);
if (new)
new->rpc_ops->free_client(new);
return nfs_found_client(cl_init, clp);
}
if (new) {
list_add_tail(&new->cl_share_link,
&nn->nfs_client_list);
spin_unlock(&nn->nfs_client_lock);
new->cl_flags = cl_init->init_flags;
return rpc_ops->init_client(new, timeparms, ip_addr,
authflavour);
}
spin_unlock(&nn->nfs_client_lock);
new = rpc_ops->alloc_client(cl_init);
} while (!IS_ERR(new));
dprintk("<-- nfs_get_client() Failed to find %s (%ld)\n",
cl_init->hostname ?: "", PTR_ERR(new));
return new;
}
void nfs_mark_client_ready(struct nfs_client *clp, int state)
{
smp_wmb();
clp->cl_cons_state = state;
wake_up_all(&nfs_client_active_wq);
}
void nfs_init_timeout_values(struct rpc_timeout *to, int proto,
unsigned int timeo, unsigned int retrans)
{
to->to_initval = timeo * HZ / 10;
to->to_retries = retrans;
switch (proto) {
case XPRT_TRANSPORT_TCP:
case XPRT_TRANSPORT_RDMA:
if (to->to_retries == 0)
to->to_retries = NFS_DEF_TCP_RETRANS;
if (to->to_initval == 0)
to->to_initval = NFS_DEF_TCP_TIMEO * HZ / 10;
if (to->to_initval > NFS_MAX_TCP_TIMEOUT)
to->to_initval = NFS_MAX_TCP_TIMEOUT;
to->to_increment = to->to_initval;
to->to_maxval = to->to_initval + (to->to_increment * to->to_retries);
if (to->to_maxval > NFS_MAX_TCP_TIMEOUT)
to->to_maxval = NFS_MAX_TCP_TIMEOUT;
if (to->to_maxval < to->to_initval)
to->to_maxval = to->to_initval;
to->to_exponential = 0;
break;
case XPRT_TRANSPORT_UDP:
if (to->to_retries == 0)
to->to_retries = NFS_DEF_UDP_RETRANS;
if (!to->to_initval)
to->to_initval = NFS_DEF_UDP_TIMEO * HZ / 10;
if (to->to_initval > NFS_MAX_UDP_TIMEOUT)
to->to_initval = NFS_MAX_UDP_TIMEOUT;
to->to_maxval = NFS_MAX_UDP_TIMEOUT;
to->to_exponential = 1;
break;
default:
BUG();
}
}
int nfs_create_rpc_client(struct nfs_client *clp,
const struct rpc_timeout *timeparms,
rpc_authflavor_t flavor)
{
struct rpc_clnt *clnt = NULL;
struct rpc_create_args args = {
.net = clp->cl_net,
.protocol = clp->cl_proto,
.address = (struct sockaddr *)&clp->cl_addr,
.addrsize = clp->cl_addrlen,
.timeout = timeparms,
.servername = clp->cl_hostname,
.program = &nfs_program,
.version = clp->rpc_ops->version,
.authflavor = flavor,
};
if (test_bit(NFS_CS_DISCRTRY, &clp->cl_flags))
args.flags |= RPC_CLNT_CREATE_DISCRTRY;
if (test_bit(NFS_CS_NORESVPORT, &clp->cl_flags))
args.flags |= RPC_CLNT_CREATE_NONPRIVPORT;
if (test_bit(NFS_CS_INFINITE_SLOTS, &clp->cl_flags))
args.flags |= RPC_CLNT_CREATE_INFINITE_SLOTS;
if (!IS_ERR(clp->cl_rpcclient))
return 0;
clnt = rpc_create(&args);
if (IS_ERR(clnt)) {
dprintk("%s: cannot create RPC client. Error = %ld\n",
__func__, PTR_ERR(clnt));
return PTR_ERR(clnt);
}
clp->cl_rpcclient = clnt;
return 0;
}
static void nfs_destroy_server(struct nfs_server *server)
{
if (server->nlm_host)
nlmclnt_done(server->nlm_host);
}
static int nfs_start_lockd(struct nfs_server *server)
{
struct nlm_host *host;
struct nfs_client *clp = server->nfs_client;
struct nlmclnt_initdata nlm_init = {
.hostname = clp->cl_hostname,
.address = (struct sockaddr *)&clp->cl_addr,
.addrlen = clp->cl_addrlen,
.nfs_version = clp->rpc_ops->version,
.noresvport = server->flags & NFS_MOUNT_NORESVPORT ?
1 : 0,
.net = clp->cl_net,
};
if (nlm_init.nfs_version > 3)
return 0;
if ((server->flags & NFS_MOUNT_LOCAL_FLOCK) &&
(server->flags & NFS_MOUNT_LOCAL_FCNTL))
return 0;
switch (clp->cl_proto) {
default:
nlm_init.protocol = IPPROTO_TCP;
break;
case XPRT_TRANSPORT_UDP:
nlm_init.protocol = IPPROTO_UDP;
}
host = nlmclnt_init(&nlm_init);
if (IS_ERR(host))
return PTR_ERR(host);
server->nlm_host = host;
server->destroy = nfs_destroy_server;
return 0;
}
int nfs_init_server_rpcclient(struct nfs_server *server,
const struct rpc_timeout *timeo,
rpc_authflavor_t pseudoflavour)
{
struct nfs_client *clp = server->nfs_client;
server->client = rpc_clone_client_set_auth(clp->cl_rpcclient,
pseudoflavour);
if (IS_ERR(server->client)) {
dprintk("%s: couldn't create rpc_client!\n", __func__);
return PTR_ERR(server->client);
}
memcpy(&server->client->cl_timeout_default,
timeo,
sizeof(server->client->cl_timeout_default));
server->client->cl_timeout = &server->client->cl_timeout_default;
server->client->cl_softrtry = 0;
if (server->flags & NFS_MOUNT_SOFT)
server->client->cl_softrtry = 1;
return 0;
}
struct nfs_client *nfs_init_client(struct nfs_client *clp,
const struct rpc_timeout *timeparms,
const char *ip_addr, rpc_authflavor_t authflavour)
{
int error;
if (clp->cl_cons_state == NFS_CS_READY) {
dprintk("<-- nfs_init_client() = 0 [already %p]\n", clp);
return clp;
}
error = nfs_create_rpc_client(clp, timeparms, RPC_AUTH_UNIX);
if (error < 0)
goto error;
nfs_mark_client_ready(clp, NFS_CS_READY);
return clp;
error:
nfs_mark_client_ready(clp, error);
nfs_put_client(clp);
dprintk("<-- nfs_init_client() = xerror %d\n", error);
return ERR_PTR(error);
}
static int nfs_init_server(struct nfs_server *server,
const struct nfs_parsed_mount_data *data,
struct nfs_subversion *nfs_mod)
{
struct nfs_client_initdata cl_init = {
.hostname = data->nfs_server.hostname,
.addr = (const struct sockaddr *)&data->nfs_server.address,
.addrlen = data->nfs_server.addrlen,
.nfs_mod = nfs_mod,
.proto = data->nfs_server.protocol,
.net = data->net,
};
struct rpc_timeout timeparms;
struct nfs_client *clp;
int error;
dprintk("--> nfs_init_server()\n");
nfs_init_timeout_values(&timeparms, data->nfs_server.protocol,
data->timeo, data->retrans);
if (data->flags & NFS_MOUNT_NORESVPORT)
set_bit(NFS_CS_NORESVPORT, &cl_init.init_flags);
clp = nfs_get_client(&cl_init, &timeparms, NULL, RPC_AUTH_UNIX);
if (IS_ERR(clp)) {
dprintk("<-- nfs_init_server() = error %ld\n", PTR_ERR(clp));
return PTR_ERR(clp);
}
server->nfs_client = clp;
server->flags = data->flags;
server->options = data->options;
server->caps |= NFS_CAP_HARDLINKS|NFS_CAP_SYMLINKS|NFS_CAP_FILEID|
NFS_CAP_MODE|NFS_CAP_NLINK|NFS_CAP_OWNER|NFS_CAP_OWNER_GROUP|
NFS_CAP_ATIME|NFS_CAP_CTIME|NFS_CAP_MTIME|NFS_CAP_CHANGE_ATTR;
if (data->rsize)
server->rsize = nfs_block_size(data->rsize, NULL);
if (data->wsize)
server->wsize = nfs_block_size(data->wsize, NULL);
server->acregmin = data->acregmin * HZ;
server->acregmax = data->acregmax * HZ;
server->acdirmin = data->acdirmin * HZ;
server->acdirmax = data->acdirmax * HZ;
error = nfs_start_lockd(server);
if (error < 0)
goto error;
server->port = data->nfs_server.port;
error = nfs_init_server_rpcclient(server, &timeparms, data->auth_flavors[0]);
if (error < 0)
goto error;
if (data->mount_server.addrlen) {
memcpy(&server->mountd_address, &data->mount_server.address,
data->mount_server.addrlen);
server->mountd_addrlen = data->mount_server.addrlen;
}
server->mountd_version = data->mount_server.version;
server->mountd_port = data->mount_server.port;
server->mountd_protocol = data->mount_server.protocol;
server->namelen = data->namlen;
dprintk("<-- nfs_init_server() = 0 [new %p]\n", clp);
return 0;
error:
server->nfs_client = NULL;
nfs_put_client(clp);
dprintk("<-- nfs_init_server() = xerror %d\n", error);
return error;
}
static void nfs_server_set_fsinfo(struct nfs_server *server,
struct nfs_fh *mntfh,
struct nfs_fsinfo *fsinfo)
{
unsigned long max_rpc_payload;
if (server->rsize == 0)
server->rsize = nfs_block_size(fsinfo->rtpref, NULL);
if (server->wsize == 0)
server->wsize = nfs_block_size(fsinfo->wtpref, NULL);
if (fsinfo->rtmax >= 512 && server->rsize > fsinfo->rtmax)
server->rsize = nfs_block_size(fsinfo->rtmax, NULL);
if (fsinfo->wtmax >= 512 && server->wsize > fsinfo->wtmax)
server->wsize = nfs_block_size(fsinfo->wtmax, NULL);
max_rpc_payload = nfs_block_size(rpc_max_payload(server->client), NULL);
if (server->rsize > max_rpc_payload)
server->rsize = max_rpc_payload;
if (server->rsize > NFS_MAX_FILE_IO_SIZE)
server->rsize = NFS_MAX_FILE_IO_SIZE;
server->rpages = (server->rsize + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;
server->backing_dev_info.name = "nfs";
server->backing_dev_info.ra_pages = server->rpages * NFS_MAX_READAHEAD;
if (server->wsize > max_rpc_payload)
server->wsize = max_rpc_payload;
if (server->wsize > NFS_MAX_FILE_IO_SIZE)
server->wsize = NFS_MAX_FILE_IO_SIZE;
server->wpages = (server->wsize + PAGE_CACHE_SIZE - 1) >> PAGE_CACHE_SHIFT;
server->wtmult = nfs_block_bits(fsinfo->wtmult, NULL);
server->dtsize = nfs_block_size(fsinfo->dtpref, NULL);
if (server->dtsize > PAGE_CACHE_SIZE * NFS_MAX_READDIR_PAGES)
server->dtsize = PAGE_CACHE_SIZE * NFS_MAX_READDIR_PAGES;
if (server->dtsize > server->rsize)
server->dtsize = server->rsize;
if (server->flags & NFS_MOUNT_NOAC) {
server->acregmin = server->acregmax = 0;
server->acdirmin = server->acdirmax = 0;
}
server->maxfilesize = fsinfo->maxfilesize;
server->time_delta = fsinfo->time_delta;
rpc_setbufsize(server->client, server->wsize + 100, server->rsize + 100);
}
int nfs_probe_fsinfo(struct nfs_server *server, struct nfs_fh *mntfh, struct nfs_fattr *fattr)
{
struct nfs_fsinfo fsinfo;
struct nfs_client *clp = server->nfs_client;
int error;
dprintk("--> nfs_probe_fsinfo()\n");
if (clp->rpc_ops->set_capabilities != NULL) {
error = clp->rpc_ops->set_capabilities(server, mntfh);
if (error < 0)
goto out_error;
}
fsinfo.fattr = fattr;
fsinfo.layouttype = 0;
error = clp->rpc_ops->fsinfo(server, mntfh, &fsinfo);
if (error < 0)
goto out_error;
nfs_server_set_fsinfo(server, mntfh, &fsinfo);
if (server->namelen == 0) {
struct nfs_pathconf pathinfo;
pathinfo.fattr = fattr;
nfs_fattr_init(fattr);
if (clp->rpc_ops->pathconf(server, mntfh, &pathinfo) >= 0)
server->namelen = pathinfo.max_namelen;
}
dprintk("<-- nfs_probe_fsinfo() = 0\n");
return 0;
out_error:
dprintk("nfs_probe_fsinfo: error = %d\n", -error);
return error;
}
void nfs_server_copy_userdata(struct nfs_server *target, struct nfs_server *source)
{
target->flags = source->flags;
target->rsize = source->rsize;
target->wsize = source->wsize;
target->acregmin = source->acregmin;
target->acregmax = source->acregmax;
target->acdirmin = source->acdirmin;
target->acdirmax = source->acdirmax;
target->caps = source->caps;
target->options = source->options;
}
void nfs_server_insert_lists(struct nfs_server *server)
{
struct nfs_client *clp = server->nfs_client;
struct nfs_net *nn = net_generic(clp->cl_net, nfs_net_id);
spin_lock(&nn->nfs_client_lock);
list_add_tail_rcu(&server->client_link, &clp->cl_superblocks);
list_add_tail(&server->master_link, &nn->nfs_volume_list);
clear_bit(NFS_CS_STOP_RENEW, &clp->cl_res_state);
spin_unlock(&nn->nfs_client_lock);
}
static void nfs_server_remove_lists(struct nfs_server *server)
{
struct nfs_client *clp = server->nfs_client;
struct nfs_net *nn;
if (clp == NULL)
return;
nn = net_generic(clp->cl_net, nfs_net_id);
spin_lock(&nn->nfs_client_lock);
list_del_rcu(&server->client_link);
if (list_empty(&clp->cl_superblocks))
set_bit(NFS_CS_STOP_RENEW, &clp->cl_res_state);
list_del(&server->master_link);
spin_unlock(&nn->nfs_client_lock);
synchronize_rcu();
}
struct nfs_server *nfs_alloc_server(void)
{
struct nfs_server *server;
server = kzalloc(sizeof(struct nfs_server), GFP_KERNEL);
if (!server)
return NULL;
server->client = server->client_acl = ERR_PTR(-EINVAL);
INIT_LIST_HEAD(&server->client_link);
INIT_LIST_HEAD(&server->master_link);
INIT_LIST_HEAD(&server->delegations);
INIT_LIST_HEAD(&server->layouts);
INIT_LIST_HEAD(&server->state_owners_lru);
atomic_set(&server->active, 0);
server->io_stats = nfs_alloc_iostats();
if (!server->io_stats) {
kfree(server);
return NULL;
}
if (bdi_init(&server->backing_dev_info)) {
nfs_free_iostats(server->io_stats);
kfree(server);
return NULL;
}
ida_init(&server->openowner_id);
ida_init(&server->lockowner_id);
pnfs_init_server(server);
return server;
}
void nfs_free_server(struct nfs_server *server)
{
dprintk("--> nfs_free_server()\n");
nfs_server_remove_lists(server);
if (server->destroy != NULL)
server->destroy(server);
if (!IS_ERR(server->client_acl))
rpc_shutdown_client(server->client_acl);
if (!IS_ERR(server->client))
rpc_shutdown_client(server->client);
nfs_put_client(server->nfs_client);
ida_destroy(&server->lockowner_id);
ida_destroy(&server->openowner_id);
nfs_free_iostats(server->io_stats);
bdi_destroy(&server->backing_dev_info);
kfree(server);
nfs_release_automount_timer();
dprintk("<-- nfs_free_server()\n");
}
struct nfs_server *nfs_create_server(struct nfs_mount_info *mount_info,
struct nfs_subversion *nfs_mod)
{
struct nfs_server *server;
struct nfs_fattr *fattr;
int error;
server = nfs_alloc_server();
if (!server)
return ERR_PTR(-ENOMEM);
error = -ENOMEM;
fattr = nfs_alloc_fattr();
if (fattr == NULL)
goto error;
error = nfs_init_server(server, mount_info->parsed, nfs_mod);
if (error < 0)
goto error;
error = nfs_probe_fsinfo(server, mount_info->mntfh, fattr);
if (error < 0)
goto error;
if (server->nfs_client->rpc_ops->version == 3) {
if (server->namelen == 0 || server->namelen > NFS3_MAXNAMLEN)
server->namelen = NFS3_MAXNAMLEN;
if (!(mount_info->parsed->flags & NFS_MOUNT_NORDIRPLUS))
server->caps |= NFS_CAP_READDIRPLUS;
} else {
if (server->namelen == 0 || server->namelen > NFS2_MAXNAMLEN)
server->namelen = NFS2_MAXNAMLEN;
}
if (!(fattr->valid & NFS_ATTR_FATTR)) {
error = nfs_mod->rpc_ops->getattr(server, mount_info->mntfh, fattr, NULL);
if (error < 0) {
dprintk("nfs_create_server: getattr error = %d\n", -error);
goto error;
}
}
memcpy(&server->fsid, &fattr->fsid, sizeof(server->fsid));
dprintk("Server FSID: %llx:%llx\n",
(unsigned long long) server->fsid.major,
(unsigned long long) server->fsid.minor);
nfs_server_insert_lists(server);
server->mount_time = jiffies;
nfs_free_fattr(fattr);
return server;
error:
nfs_free_fattr(fattr);
nfs_free_server(server);
return ERR_PTR(error);
}
struct nfs_server *nfs_clone_server(struct nfs_server *source,
struct nfs_fh *fh,
struct nfs_fattr *fattr,
rpc_authflavor_t flavor)
{
struct nfs_server *server;
struct nfs_fattr *fattr_fsinfo;
int error;
dprintk("--> nfs_clone_server(,%llx:%llx,)\n",
(unsigned long long) fattr->fsid.major,
(unsigned long long) fattr->fsid.minor);
server = nfs_alloc_server();
if (!server)
return ERR_PTR(-ENOMEM);
error = -ENOMEM;
fattr_fsinfo = nfs_alloc_fattr();
if (fattr_fsinfo == NULL)
goto out_free_server;
server->nfs_client = source->nfs_client;
server->destroy = source->destroy;
atomic_inc(&server->nfs_client->cl_count);
nfs_server_copy_userdata(server, source);
server->fsid = fattr->fsid;
error = nfs_init_server_rpcclient(server,
source->client->cl_timeout,
flavor);
if (error < 0)
goto out_free_server;
error = nfs_probe_fsinfo(server, fh, fattr_fsinfo);
if (error < 0)
goto out_free_server;
if (server->namelen == 0 || server->namelen > NFS4_MAXNAMLEN)
server->namelen = NFS4_MAXNAMLEN;
dprintk("Cloned FSID: %llx:%llx\n",
(unsigned long long) server->fsid.major,
(unsigned long long) server->fsid.minor);
error = nfs_start_lockd(server);
if (error < 0)
goto out_free_server;
nfs_server_insert_lists(server);
server->mount_time = jiffies;
nfs_free_fattr(fattr_fsinfo);
dprintk("<-- nfs_clone_server() = %p\n", server);
return server;
out_free_server:
nfs_free_fattr(fattr_fsinfo);
nfs_free_server(server);
dprintk("<-- nfs_clone_server() = error %d\n", error);
return ERR_PTR(error);
}
void nfs_clients_init(struct net *net)
{
struct nfs_net *nn = net_generic(net, nfs_net_id);
INIT_LIST_HEAD(&nn->nfs_client_list);
INIT_LIST_HEAD(&nn->nfs_volume_list);
#if IS_ENABLED(CONFIG_NFS_V4)
idr_init(&nn->cb_ident_idr);
#endif
spin_lock_init(&nn->nfs_client_lock);
nn->boot_time = CURRENT_TIME;
}
static int nfs_server_list_open(struct inode *inode, struct file *file)
{
struct seq_file *m;
int ret;
struct pid_namespace *pid_ns = file->f_dentry->d_sb->s_fs_info;
struct net *net = pid_ns->child_reaper->nsproxy->net_ns;
ret = seq_open(file, &nfs_server_list_ops);
if (ret < 0)
return ret;
m = file->private_data;
m->private = net;
return 0;
}
static void *nfs_server_list_start(struct seq_file *m, loff_t *_pos)
{
struct nfs_net *nn = net_generic(m->private, nfs_net_id);
spin_lock(&nn->nfs_client_lock);
return seq_list_start_head(&nn->nfs_client_list, *_pos);
}
static void *nfs_server_list_next(struct seq_file *p, void *v, loff_t *pos)
{
struct nfs_net *nn = net_generic(p->private, nfs_net_id);
return seq_list_next(v, &nn->nfs_client_list, pos);
}
static void nfs_server_list_stop(struct seq_file *p, void *v)
{
struct nfs_net *nn = net_generic(p->private, nfs_net_id);
spin_unlock(&nn->nfs_client_lock);
}
static int nfs_server_list_show(struct seq_file *m, void *v)
{
struct nfs_client *clp;
struct nfs_net *nn = net_generic(m->private, nfs_net_id);
if (v == &nn->nfs_client_list) {
seq_puts(m, "NV SERVER PORT USE HOSTNAME\n");
return 0;
}
clp = list_entry(v, struct nfs_client, cl_share_link);
if (clp->cl_cons_state != NFS_CS_READY)
return 0;
rcu_read_lock();
seq_printf(m, "v%u %s %s %3d %s\n",
clp->rpc_ops->version,
rpc_peeraddr2str(clp->cl_rpcclient, RPC_DISPLAY_HEX_ADDR),
rpc_peeraddr2str(clp->cl_rpcclient, RPC_DISPLAY_HEX_PORT),
atomic_read(&clp->cl_count),
clp->cl_hostname);
rcu_read_unlock();
return 0;
}
static int nfs_volume_list_open(struct inode *inode, struct file *file)
{
struct seq_file *m;
int ret;
struct pid_namespace *pid_ns = file->f_dentry->d_sb->s_fs_info;
struct net *net = pid_ns->child_reaper->nsproxy->net_ns;
ret = seq_open(file, &nfs_volume_list_ops);
if (ret < 0)
return ret;
m = file->private_data;
m->private = net;
return 0;
}
static void *nfs_volume_list_start(struct seq_file *m, loff_t *_pos)
{
struct nfs_net *nn = net_generic(m->private, nfs_net_id);
spin_lock(&nn->nfs_client_lock);
return seq_list_start_head(&nn->nfs_volume_list, *_pos);
}
static void *nfs_volume_list_next(struct seq_file *p, void *v, loff_t *pos)
{
struct nfs_net *nn = net_generic(p->private, nfs_net_id);
return seq_list_next(v, &nn->nfs_volume_list, pos);
}
static void nfs_volume_list_stop(struct seq_file *p, void *v)
{
struct nfs_net *nn = net_generic(p->private, nfs_net_id);
spin_unlock(&nn->nfs_client_lock);
}
static int nfs_volume_list_show(struct seq_file *m, void *v)
{
struct nfs_server *server;
struct nfs_client *clp;
char dev[8], fsid[17];
struct nfs_net *nn = net_generic(m->private, nfs_net_id);
if (v == &nn->nfs_volume_list) {
seq_puts(m, "NV SERVER PORT DEV FSID FSC\n");
return 0;
}
server = list_entry(v, struct nfs_server, master_link);
clp = server->nfs_client;
snprintf(dev, 8, "%u:%u",
MAJOR(server->s_dev), MINOR(server->s_dev));
snprintf(fsid, 17, "%llx:%llx",
(unsigned long long) server->fsid.major,
(unsigned long long) server->fsid.minor);
rcu_read_lock();
seq_printf(m, "v%u %s %s %-7s %-17s %s\n",
clp->rpc_ops->version,
rpc_peeraddr2str(clp->cl_rpcclient, RPC_DISPLAY_HEX_ADDR),
rpc_peeraddr2str(clp->cl_rpcclient, RPC_DISPLAY_HEX_PORT),
dev,
fsid,
nfs_server_fscache_state(server));
rcu_read_unlock();
return 0;
}
int __init nfs_fs_proc_init(void)
{
struct proc_dir_entry *p;
proc_fs_nfs = proc_mkdir("fs/nfsfs", NULL);
if (!proc_fs_nfs)
goto error_0;
p = proc_create("servers", S_IFREG|S_IRUGO,
proc_fs_nfs, &nfs_server_list_fops);
if (!p)
goto error_1;
p = proc_create("volumes", S_IFREG|S_IRUGO,
proc_fs_nfs, &nfs_volume_list_fops);
if (!p)
goto error_2;
return 0;
error_2:
remove_proc_entry("servers", proc_fs_nfs);
error_1:
remove_proc_entry("fs/nfsfs", NULL);
error_0:
return -ENOMEM;
}
void nfs_fs_proc_exit(void)
{
remove_proc_entry("volumes", proc_fs_nfs);
remove_proc_entry("servers", proc_fs_nfs);
remove_proc_entry("fs/nfsfs", NULL);
}
