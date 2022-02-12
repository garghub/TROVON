int nfs_fscache_register(void)
{
return fscache_register_netfs(&nfs_fscache_netfs);
}
void nfs_fscache_unregister(void)
{
fscache_unregister_netfs(&nfs_fscache_netfs);
}
static uint16_t nfs_server_get_key(const void *cookie_netfs_data,
void *buffer, uint16_t bufmax)
{
const struct nfs_client *clp = cookie_netfs_data;
const struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *) &clp->cl_addr;
const struct sockaddr_in *sin = (struct sockaddr_in *) &clp->cl_addr;
struct nfs_server_key *key = buffer;
uint16_t len = sizeof(struct nfs_server_key);
memset(key, 0, len);
key->nfsversion = clp->rpc_ops->version;
key->family = clp->cl_addr.ss_family;
switch (clp->cl_addr.ss_family) {
case AF_INET:
key->port = sin->sin_port;
key->addr[0].ipv4_addr = sin->sin_addr;
len += sizeof(key->addr[0].ipv4_addr);
break;
case AF_INET6:
key->port = sin6->sin6_port;
key->addr[0].ipv6_addr = sin6->sin6_addr;
len += sizeof(key->addr[0].ipv6_addr);
break;
default:
printk(KERN_WARNING "NFS: Unknown network family '%d'\n",
clp->cl_addr.ss_family);
len = 0;
break;
}
return len;
}
static uint16_t nfs_super_get_key(const void *cookie_netfs_data,
void *buffer, uint16_t bufmax)
{
const struct nfs_fscache_key *key;
const struct nfs_server *nfss = cookie_netfs_data;
uint16_t len;
key = nfss->fscache_key;
len = sizeof(key->key) + key->key.uniq_len;
if (len > bufmax) {
len = 0;
} else {
memcpy(buffer, &key->key, sizeof(key->key));
memcpy(buffer + sizeof(key->key),
key->key.uniquifier, key->key.uniq_len);
}
return len;
}
static uint16_t nfs_fscache_inode_get_key(const void *cookie_netfs_data,
void *buffer, uint16_t bufmax)
{
const struct nfs_inode *nfsi = cookie_netfs_data;
uint16_t nsize;
nsize = nfsi->fh.size;
memcpy(buffer, nfsi->fh.data, nsize);
return nsize;
}
static void nfs_fscache_inode_get_attr(const void *cookie_netfs_data,
uint64_t *size)
{
const struct nfs_inode *nfsi = cookie_netfs_data;
*size = nfsi->vfs_inode.i_size;
}
static uint16_t nfs_fscache_inode_get_aux(const void *cookie_netfs_data,
void *buffer, uint16_t bufmax)
{
struct nfs_fscache_inode_auxdata auxdata;
const struct nfs_inode *nfsi = cookie_netfs_data;
memset(&auxdata, 0, sizeof(auxdata));
auxdata.size = nfsi->vfs_inode.i_size;
auxdata.mtime = nfsi->vfs_inode.i_mtime;
auxdata.ctime = nfsi->vfs_inode.i_ctime;
if (NFS_SERVER(&nfsi->vfs_inode)->nfs_client->rpc_ops->version == 4)
auxdata.change_attr = nfsi->vfs_inode.i_version;
if (bufmax > sizeof(auxdata))
bufmax = sizeof(auxdata);
memcpy(buffer, &auxdata, bufmax);
return bufmax;
}
static
enum fscache_checkaux nfs_fscache_inode_check_aux(void *cookie_netfs_data,
const void *data,
uint16_t datalen)
{
struct nfs_fscache_inode_auxdata auxdata;
struct nfs_inode *nfsi = cookie_netfs_data;
if (datalen != sizeof(auxdata))
return FSCACHE_CHECKAUX_OBSOLETE;
memset(&auxdata, 0, sizeof(auxdata));
auxdata.size = nfsi->vfs_inode.i_size;
auxdata.mtime = nfsi->vfs_inode.i_mtime;
auxdata.ctime = nfsi->vfs_inode.i_ctime;
if (NFS_SERVER(&nfsi->vfs_inode)->nfs_client->rpc_ops->version == 4)
auxdata.change_attr = nfsi->vfs_inode.i_version;
if (memcmp(data, &auxdata, datalen) != 0)
return FSCACHE_CHECKAUX_OBSOLETE;
return FSCACHE_CHECKAUX_OKAY;
}
static void nfs_fh_get_context(void *cookie_netfs_data, void *context)
{
get_nfs_open_context(context);
}
static void nfs_fh_put_context(void *cookie_netfs_data, void *context)
{
if (context)
put_nfs_open_context(context);
}
