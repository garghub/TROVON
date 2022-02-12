int btrfs_defrag_leaves(struct btrfs_trans_handle *trans,
struct btrfs_root *root)
{
struct btrfs_path *path = NULL;
struct btrfs_key key;
int ret = 0;
int wret;
int level;
int is_extent = 0;
int next_key_ret = 0;
u64 last_ret = 0;
u64 min_trans = 0;
if (root->fs_info->extent_root == root) {
goto out;
}
if (root->ref_cows == 0 && !is_extent)
goto out;
if (btrfs_test_opt(root, SSD))
goto out;
path = btrfs_alloc_path();
if (!path)
return -ENOMEM;
level = btrfs_header_level(root->node);
if (level == 0)
goto out;
if (root->defrag_progress.objectid == 0) {
struct extent_buffer *root_node;
u32 nritems;
root_node = btrfs_lock_root_node(root);
btrfs_set_lock_blocking(root_node);
nritems = btrfs_header_nritems(root_node);
root->defrag_max.objectid = 0;
btrfs_node_key_to_cpu(root_node, &root->defrag_max,
nritems - 1);
btrfs_tree_unlock(root_node);
free_extent_buffer(root_node);
memset(&key, 0, sizeof(key));
} else {
memcpy(&key, &root->defrag_progress, sizeof(key));
}
path->keep_locks = 1;
ret = btrfs_search_forward(root, &key, NULL, path, min_trans);
if (ret < 0)
goto out;
if (ret > 0) {
ret = 0;
goto out;
}
btrfs_release_path(path);
wret = btrfs_search_slot(trans, root, &key, path, 0, 1);
if (wret < 0) {
ret = wret;
goto out;
}
if (!path->nodes[1]) {
ret = 0;
goto out;
}
path->slots[1] = btrfs_header_nritems(path->nodes[1]);
next_key_ret = btrfs_find_next_key(root, path, &key, 1,
min_trans);
ret = btrfs_realloc_node(trans, root,
path->nodes[1], 0,
&last_ret,
&root->defrag_progress);
if (ret) {
WARN_ON(ret == -EAGAIN);
goto out;
}
if (next_key_ret == 0) {
memcpy(&root->defrag_progress, &key, sizeof(key));
ret = -EAGAIN;
}
out:
if (path)
btrfs_free_path(path);
if (ret == -EAGAIN) {
if (root->defrag_max.objectid > root->defrag_progress.objectid)
goto done;
if (root->defrag_max.type > root->defrag_progress.type)
goto done;
if (root->defrag_max.offset > root->defrag_progress.offset)
goto done;
ret = 0;
}
done:
if (ret != -EAGAIN) {
memset(&root->defrag_progress, 0,
sizeof(root->defrag_progress));
root->defrag_trans_start = trans->transid;
}
return ret;
}
