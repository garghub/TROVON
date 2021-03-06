static inline void nlm_debug_print_fh(char *msg, struct nfs_fh *f)
{
u32 *fhp = (u32*)f->data;
dprintk("lockd: %s (%08x %08x %08x %08x %08x %08x %08x %08x)\n",
msg, fhp[0], fhp[1], fhp[2], fhp[3],
fhp[4], fhp[5], fhp[6], fhp[7]);
}
static inline void nlm_debug_print_file(char *msg, struct nlm_file *file)
{
struct inode *inode = file->f_file->f_path.dentry->d_inode;
dprintk("lockd: %s %s/%ld\n",
msg, inode->i_sb->s_id, inode->i_ino);
}
static inline void nlm_debug_print_fh(char *msg, struct nfs_fh *f)
{
return;
}
static inline void nlm_debug_print_file(char *msg, struct nlm_file *file)
{
return;
}
static inline unsigned int file_hash(struct nfs_fh *f)
{
unsigned int tmp=0;
int i;
for (i=0; i<NFS2_FHSIZE;i++)
tmp += f->data[i];
return tmp & (FILE_NRHASH - 1);
}
__be32
nlm_lookup_file(struct svc_rqst *rqstp, struct nlm_file **result,
struct nfs_fh *f)
{
struct hlist_node *pos;
struct nlm_file *file;
unsigned int hash;
__be32 nfserr;
nlm_debug_print_fh("nlm_lookup_file", f);
hash = file_hash(f);
mutex_lock(&nlm_file_mutex);
hlist_for_each_entry(file, pos, &nlm_files[hash], f_list)
if (!nfs_compare_fh(&file->f_handle, f))
goto found;
nlm_debug_print_fh("creating file for", f);
nfserr = nlm_lck_denied_nolocks;
file = kzalloc(sizeof(*file), GFP_KERNEL);
if (!file)
goto out_unlock;
memcpy(&file->f_handle, f, sizeof(struct nfs_fh));
mutex_init(&file->f_mutex);
INIT_HLIST_NODE(&file->f_list);
INIT_LIST_HEAD(&file->f_blocks);
if ((nfserr = nlmsvc_ops->fopen(rqstp, f, &file->f_file)) != 0) {
dprintk("lockd: open failed (error %d)\n", nfserr);
goto out_free;
}
hlist_add_head(&file->f_list, &nlm_files[hash]);
found:
dprintk("lockd: found file %p (count %d)\n", file, file->f_count);
*result = file;
file->f_count++;
nfserr = 0;
out_unlock:
mutex_unlock(&nlm_file_mutex);
return nfserr;
out_free:
kfree(file);
goto out_unlock;
}
static inline void
nlm_delete_file(struct nlm_file *file)
{
nlm_debug_print_file("closing file", file);
if (!hlist_unhashed(&file->f_list)) {
hlist_del(&file->f_list);
nlmsvc_ops->fclose(file->f_file);
kfree(file);
} else {
printk(KERN_WARNING "lockd: attempt to release unknown file!\n");
}
}
static int
nlm_traverse_locks(struct nlm_host *host, struct nlm_file *file,
nlm_host_match_fn_t match)
{
struct inode *inode = nlmsvc_file_inode(file);
struct file_lock *fl;
struct nlm_host *lockhost;
again:
file->f_locks = 0;
lock_flocks();
for (fl = inode->i_flock; fl; fl = fl->fl_next) {
if (fl->fl_lmops != &nlmsvc_lock_operations)
continue;
file->f_locks++;
lockhost = (struct nlm_host *) fl->fl_owner;
if (match(lockhost, host)) {
struct file_lock lock = *fl;
unlock_flocks();
lock.fl_type = F_UNLCK;
lock.fl_start = 0;
lock.fl_end = OFFSET_MAX;
if (vfs_lock_file(file->f_file, F_SETLK, &lock, NULL) < 0) {
printk("lockd: unlock failure in %s:%d\n",
__FILE__, __LINE__);
return 1;
}
goto again;
}
}
unlock_flocks();
return 0;
}
static int
nlmsvc_always_match(void *dummy1, struct nlm_host *dummy2)
{
return 1;
}
static inline int
nlm_inspect_file(struct nlm_host *host, struct nlm_file *file, nlm_host_match_fn_t match)
{
nlmsvc_traverse_blocks(host, file, match);
nlmsvc_traverse_shares(host, file, match);
return nlm_traverse_locks(host, file, match);
}
static inline int
nlm_file_inuse(struct nlm_file *file)
{
struct inode *inode = nlmsvc_file_inode(file);
struct file_lock *fl;
if (file->f_count || !list_empty(&file->f_blocks) || file->f_shares)
return 1;
lock_flocks();
for (fl = inode->i_flock; fl; fl = fl->fl_next) {
if (fl->fl_lmops == &nlmsvc_lock_operations) {
unlock_flocks();
return 1;
}
}
unlock_flocks();
file->f_locks = 0;
return 0;
}
static int
nlm_traverse_files(void *data, nlm_host_match_fn_t match,
int (*is_failover_file)(void *data, struct nlm_file *file))
{
struct hlist_node *pos, *next;
struct nlm_file *file;
int i, ret = 0;
mutex_lock(&nlm_file_mutex);
for (i = 0; i < FILE_NRHASH; i++) {
hlist_for_each_entry_safe(file, pos, next, &nlm_files[i], f_list) {
if (is_failover_file && !is_failover_file(data, file))
continue;
file->f_count++;
mutex_unlock(&nlm_file_mutex);
if (nlm_inspect_file(data, file, match))
ret = 1;
mutex_lock(&nlm_file_mutex);
file->f_count--;
if (list_empty(&file->f_blocks) && !file->f_locks
&& !file->f_shares && !file->f_count) {
hlist_del(&file->f_list);
nlmsvc_ops->fclose(file->f_file);
kfree(file);
}
}
}
mutex_unlock(&nlm_file_mutex);
return ret;
}
void
nlm_release_file(struct nlm_file *file)
{
dprintk("lockd: nlm_release_file(%p, ct = %d)\n",
file, file->f_count);
mutex_lock(&nlm_file_mutex);
if (--file->f_count == 0 && !nlm_file_inuse(file))
nlm_delete_file(file);
mutex_unlock(&nlm_file_mutex);
}
static int
nlmsvc_mark_host(void *data, struct nlm_host *dummy)
{
struct nlm_host *host = data;
host->h_inuse = 1;
return 0;
}
static int
nlmsvc_same_host(void *data, struct nlm_host *other)
{
struct nlm_host *host = data;
return host == other;
}
static int
nlmsvc_is_client(void *data, struct nlm_host *dummy)
{
struct nlm_host *host = data;
if (host->h_server) {
if (host->h_nsmhandle)
host->h_nsmhandle->sm_sticky = 1;
return 1;
} else
return 0;
}
void
nlmsvc_mark_resources(void)
{
dprintk("lockd: nlmsvc_mark_resources\n");
nlm_traverse_files(NULL, nlmsvc_mark_host, NULL);
}
void
nlmsvc_free_host_resources(struct nlm_host *host)
{
dprintk("lockd: nlmsvc_free_host_resources\n");
if (nlm_traverse_files(host, nlmsvc_same_host, NULL)) {
printk(KERN_WARNING
"lockd: couldn't remove all locks held by %s\n",
host->h_name);
BUG();
}
}
void
nlmsvc_invalidate_all(void)
{
nlm_traverse_files(NULL, nlmsvc_is_client, NULL);
}
static int
nlmsvc_match_sb(void *datap, struct nlm_file *file)
{
struct super_block *sb = datap;
return sb == file->f_file->f_path.dentry->d_sb;
}
int
nlmsvc_unlock_all_by_sb(struct super_block *sb)
{
int ret;
ret = nlm_traverse_files(sb, nlmsvc_always_match, nlmsvc_match_sb);
return ret ? -EIO : 0;
}
static int
nlmsvc_match_ip(void *datap, struct nlm_host *host)
{
return rpc_cmp_addr(nlm_srcaddr(host), datap);
}
int
nlmsvc_unlock_all_by_ip(struct sockaddr *server_addr)
{
int ret;
ret = nlm_traverse_files(server_addr, nlmsvc_match_ip, NULL);
return ret ? -EIO : 0;
}
