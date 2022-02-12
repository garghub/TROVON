static struct inode *ll_alloc_inode(struct super_block *sb)
{
struct ll_inode_info *lli;
ll_stats_ops_tally(ll_s2sbi(sb), LPROC_LL_ALLOC_INODE, 1);
lli = kmem_cache_alloc(ll_inode_cachep, GFP_NOFS | __GFP_ZERO);
if (lli == NULL)
return NULL;
inode_init_once(&lli->lli_vfs_inode);
return &lli->lli_vfs_inode;
}
static void ll_inode_destroy_callback(struct rcu_head *head)
{
struct inode *inode = container_of(head, struct inode, i_rcu);
struct ll_inode_info *ptr = ll_i2info(inode);
kmem_cache_free(ll_inode_cachep, ptr);
}
static void ll_destroy_inode(struct inode *inode)
{
call_rcu(&inode->i_rcu, ll_inode_destroy_callback);
}
static int __init init_lustre_lite(void)
{
lnet_process_id_t lnet_id;
struct timespec64 ts;
int i, rc, seed[2];
CLASSERT(sizeof(LUSTRE_VOLATILE_HDR) == LUSTRE_VOLATILE_HDR_LEN + 1);
CDEBUG(D_INFO, "Lustre client module (%p).\n",
&lustre_super_operations);
rc = -ENOMEM;
ll_inode_cachep = kmem_cache_create("lustre_inode_cache",
sizeof(struct ll_inode_info),
0, SLAB_HWCACHE_ALIGN|SLAB_ACCOUNT,
NULL);
if (ll_inode_cachep == NULL)
goto out_cache;
ll_file_data_slab = kmem_cache_create("ll_file_data",
sizeof(struct ll_file_data), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (ll_file_data_slab == NULL)
goto out_cache;
ll_remote_perm_cachep = kmem_cache_create("ll_remote_perm_cache",
sizeof(struct ll_remote_perm),
0, 0, NULL);
if (ll_remote_perm_cachep == NULL)
goto out_cache;
ll_rmtperm_hash_cachep = kmem_cache_create("ll_rmtperm_hash_cache",
REMOTE_PERM_HASHSIZE *
sizeof(struct list_head),
0, 0, NULL);
if (ll_rmtperm_hash_cachep == NULL)
goto out_cache;
llite_root = debugfs_create_dir("llite", debugfs_lustre_root);
if (IS_ERR_OR_NULL(llite_root)) {
rc = llite_root ? PTR_ERR(llite_root) : -ENOMEM;
llite_root = NULL;
goto out_cache;
}
llite_kset = kset_create_and_add("llite", NULL, lustre_kobj);
if (!llite_kset) {
rc = -ENOMEM;
goto out_debugfs;
}
cfs_get_random_bytes(seed, sizeof(seed));
for (i = 0;; i++) {
if (LNetGetId(i, &lnet_id) == -ENOENT)
break;
if (LNET_NETTYP(LNET_NIDNET(lnet_id.nid)) != LOLND)
seed[0] ^= LNET_NIDADDR(lnet_id.nid);
}
ktime_get_ts64(&ts);
cfs_srand(ts.tv_sec ^ seed[0], ts.tv_nsec ^ seed[1]);
rc = vvp_global_init();
if (rc != 0)
goto out_sysfs;
rc = ll_xattr_init();
if (rc != 0)
goto out_vvp;
lustre_register_client_fill_super(ll_fill_super);
lustre_register_kill_super_cb(ll_kill_super);
lustre_register_client_process_config(ll_process_config);
return 0;
out_vvp:
vvp_global_fini();
out_sysfs:
kset_unregister(llite_kset);
out_debugfs:
debugfs_remove(llite_root);
out_cache:
kmem_cache_destroy(ll_inode_cachep);
kmem_cache_destroy(ll_file_data_slab);
kmem_cache_destroy(ll_remote_perm_cachep);
kmem_cache_destroy(ll_rmtperm_hash_cachep);
return rc;
}
static void __exit exit_lustre_lite(void)
{
lustre_register_client_fill_super(NULL);
lustre_register_kill_super_cb(NULL);
lustre_register_client_process_config(NULL);
debugfs_remove(llite_root);
kset_unregister(llite_kset);
ll_xattr_fini();
vvp_global_fini();
kmem_cache_destroy(ll_inode_cachep);
kmem_cache_destroy(ll_rmtperm_hash_cachep);
kmem_cache_destroy(ll_remote_perm_cachep);
kmem_cache_destroy(ll_file_data_slab);
}
