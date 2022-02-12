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
