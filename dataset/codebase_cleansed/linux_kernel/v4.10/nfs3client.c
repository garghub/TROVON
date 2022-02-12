static void nfs_init_server_aclclient(struct nfs_server *server)
{
if (server->flags & NFS_MOUNT_NOACL)
goto out_noacl;
server->client_acl = rpc_bind_new_program(server->client, &nfsacl_program, 3);
if (IS_ERR(server->client_acl))
goto out_noacl;
server->caps |= NFS_CAP_ACLS;
return;
out_noacl:
server->caps &= ~NFS_CAP_ACLS;
}
static inline void nfs_init_server_aclclient(struct nfs_server *server)
{
server->flags &= ~NFS_MOUNT_NOACL;
server->caps &= ~NFS_CAP_ACLS;
}
struct nfs_server *nfs3_create_server(struct nfs_mount_info *mount_info,
struct nfs_subversion *nfs_mod)
{
struct nfs_server *server = nfs_create_server(mount_info, nfs_mod);
if (!IS_ERR(server))
nfs_init_server_aclclient(server);
return server;
}
struct nfs_server *nfs3_clone_server(struct nfs_server *source,
struct nfs_fh *fh,
struct nfs_fattr *fattr,
rpc_authflavor_t flavor)
{
struct nfs_server *server = nfs_clone_server(source, fh, fattr, flavor);
if (!IS_ERR(server) && !IS_ERR(source->client_acl))
nfs_init_server_aclclient(server);
return server;
}
struct nfs_client *nfs3_set_ds_client(struct nfs_server *mds_srv,
const struct sockaddr *ds_addr, int ds_addrlen,
int ds_proto, unsigned int ds_timeo, unsigned int ds_retrans)
{
struct rpc_timeout ds_timeout;
struct nfs_client *mds_clp = mds_srv->nfs_client;
struct nfs_client_initdata cl_init = {
.addr = ds_addr,
.addrlen = ds_addrlen,
.nodename = mds_clp->cl_rpcclient->cl_nodename,
.ip_addr = mds_clp->cl_ipaddr,
.nfs_mod = &nfs_v3,
.proto = ds_proto,
.net = mds_clp->cl_net,
.timeparms = &ds_timeout,
};
struct nfs_client *clp;
char buf[INET6_ADDRSTRLEN + 1];
if (rpc_ntop(ds_addr, buf, sizeof(buf)) <= 0)
return ERR_PTR(-EINVAL);
cl_init.hostname = buf;
if (mds_srv->flags & NFS_MOUNT_NORESVPORT)
set_bit(NFS_CS_NORESVPORT, &cl_init.init_flags);
nfs_init_timeout_values(&ds_timeout, ds_proto, ds_timeo, ds_retrans);
clp = nfs_get_client(&cl_init);
return clp;
}
