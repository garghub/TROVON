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
static int __init init_lustre_lite(void)
{
lnet_process_id_t lnet_id;
struct timeval tv;
int i, rc, seed[2];
CLASSERT(sizeof(LUSTRE_VOLATILE_HDR) == LUSTRE_VOLATILE_HDR_LEN + 1);
CDEBUG(D_INFO, "Lustre client module (%p).\n",
&lustre_super_operations);
rc = -ENOMEM;
ll_inode_cachep = kmem_cache_create("lustre_inode_cache",
sizeof(struct ll_inode_info),
0, SLAB_HWCACHE_ALIGN, NULL);
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
do_gettimeofday(&tv);
cfs_srand(tv.tv_sec ^ seed[0], tv.tv_usec ^ seed[1]);
setup_timer(&ll_capa_timer, ll_capa_timer_callback, 0);
rc = ll_capa_thread_start();
if (rc != 0)
goto out_sysfs;
rc = vvp_global_init();
if (rc != 0)
goto out_capa;
rc = ll_xattr_init();
if (rc != 0)
goto out_vvp;
lustre_register_client_fill_super(ll_fill_super);
lustre_register_kill_super_cb(ll_kill_super);
lustre_register_client_process_config(ll_process_config);
return 0;
out_vvp:
vvp_global_fini();
out_capa:
del_timer(&ll_capa_timer);
ll_capa_thread_stop();
out_sysfs:
kset_unregister(llite_kset);
out_debugfs:
debugfs_remove(llite_root);
out_cache:
if (ll_inode_cachep != NULL)
kmem_cache_destroy(ll_inode_cachep);
if (ll_file_data_slab != NULL)
kmem_cache_destroy(ll_file_data_slab);
if (ll_remote_perm_cachep != NULL)
kmem_cache_destroy(ll_remote_perm_cachep);
if (ll_rmtperm_hash_cachep != NULL)
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
del_timer(&ll_capa_timer);
ll_capa_thread_stop();
LASSERTF(capa_count[CAPA_SITE_CLIENT] == 0,
"client remaining capa count %d\n",
capa_count[CAPA_SITE_CLIENT]);
kmem_cache_destroy(ll_inode_cachep);
kmem_cache_destroy(ll_rmtperm_hash_cachep);
kmem_cache_destroy(ll_remote_perm_cachep);
kmem_cache_destroy(ll_file_data_slab);
}
