static struct inode *ll_alloc_inode(struct super_block *sb)
{
struct ll_inode_info *lli;
ll_stats_ops_tally(ll_s2sbi(sb), LPROC_LL_ALLOC_INODE, 1);
OBD_SLAB_ALLOC_PTR_GFP(lli, ll_inode_cachep, GFP_NOFS);
if (lli == NULL)
return NULL;
inode_init_once(&lli->lli_vfs_inode);
return &lli->lli_vfs_inode;
}
static void ll_inode_destroy_callback(struct rcu_head *head)
{
struct inode *inode = container_of(head, struct inode, i_rcu);
struct ll_inode_info *ptr = ll_i2info(inode);
OBD_SLAB_FREE_PTR(ptr, ll_inode_cachep);
}
static void ll_destroy_inode(struct inode *inode)
{
call_rcu(&inode->i_rcu, ll_inode_destroy_callback);
}
static int ll_init_inodecache(void)
{
ll_inode_cachep = kmem_cache_create("lustre_inode_cache",
sizeof(struct ll_inode_info),
0, SLAB_HWCACHE_ALIGN, NULL);
if (ll_inode_cachep == NULL)
return -ENOMEM;
return 0;
}
static void ll_destroy_inodecache(void)
{
kmem_cache_destroy(ll_inode_cachep);
}
static int __init init_lustre_lite(void)
{
int i, rc, seed[2];
struct timeval tv;
lnet_process_id_t lnet_id;
CLASSERT(sizeof(LUSTRE_VOLATILE_HDR) == LUSTRE_VOLATILE_HDR_LEN + 1);
CDEBUG(D_INFO, "Lustre client module (%p).\n",
&lustre_super_operations);
rc = ll_init_inodecache();
if (rc)
return -ENOMEM;
ll_file_data_slab = kmem_cache_create("ll_file_data",
sizeof(struct ll_file_data), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (ll_file_data_slab == NULL) {
ll_destroy_inodecache();
return -ENOMEM;
}
ll_remote_perm_cachep = kmem_cache_create("ll_remote_perm_cache",
sizeof(struct ll_remote_perm),
0, 0, NULL);
if (ll_remote_perm_cachep == NULL) {
kmem_cache_destroy(ll_file_data_slab);
ll_file_data_slab = NULL;
ll_destroy_inodecache();
return -ENOMEM;
}
ll_rmtperm_hash_cachep = kmem_cache_create("ll_rmtperm_hash_cache",
REMOTE_PERM_HASHSIZE *
sizeof(struct list_head),
0, 0, NULL);
if (ll_rmtperm_hash_cachep == NULL) {
kmem_cache_destroy(ll_remote_perm_cachep);
ll_remote_perm_cachep = NULL;
kmem_cache_destroy(ll_file_data_slab);
ll_file_data_slab = NULL;
ll_destroy_inodecache();
return -ENOMEM;
}
proc_lustre_fs_root = proc_lustre_root ?
lprocfs_register("llite", proc_lustre_root, NULL, NULL) : NULL;
lustre_register_client_fill_super(ll_fill_super);
lustre_register_kill_super_cb(ll_kill_super);
lustre_register_client_process_config(ll_process_config);
cfs_get_random_bytes(seed, sizeof(seed));
for (i = 0; ; i++) {
if (LNetGetId(i, &lnet_id) == -ENOENT) {
break;
}
if (LNET_NETTYP(LNET_NIDNET(lnet_id.nid)) != LOLND) {
seed[0] ^= LNET_NIDADDR(lnet_id.nid);
}
}
do_gettimeofday(&tv);
cfs_srand(tv.tv_sec ^ seed[0], tv.tv_usec ^ seed[1]);
init_timer(&ll_capa_timer);
ll_capa_timer.function = ll_capa_timer_callback;
rc = ll_capa_thread_start();
if (rc == 0)
rc = vvp_global_init();
if (rc == 0)
rc = ll_xattr_init();
return rc;
}
static void __exit exit_lustre_lite(void)
{
ll_xattr_fini();
vvp_global_fini();
del_timer(&ll_capa_timer);
ll_capa_thread_stop();
LASSERTF(capa_count[CAPA_SITE_CLIENT] == 0,
"client remaining capa count %d\n",
capa_count[CAPA_SITE_CLIENT]);
lustre_register_client_fill_super(NULL);
lustre_register_kill_super_cb(NULL);
lustre_register_client_process_config(NULL);
ll_destroy_inodecache();
kmem_cache_destroy(ll_rmtperm_hash_cachep);
ll_rmtperm_hash_cachep = NULL;
kmem_cache_destroy(ll_remote_perm_cachep);
ll_remote_perm_cachep = NULL;
kmem_cache_destroy(ll_file_data_slab);
if (proc_lustre_fs_root && !IS_ERR(proc_lustre_fs_root))
lprocfs_remove(&proc_lustre_fs_root);
}
