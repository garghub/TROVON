int __init ext4_init_es(void)
{
ext4_es_cachep = kmem_cache_create("ext4_extent_status",
sizeof(struct extent_status),
0, (SLAB_RECLAIM_ACCOUNT), NULL);
if (ext4_es_cachep == NULL)
return -ENOMEM;
return 0;
}
void ext4_exit_es(void)
{
if (ext4_es_cachep)
kmem_cache_destroy(ext4_es_cachep);
}
void ext4_es_init_tree(struct ext4_es_tree *tree)
{
tree->root = RB_ROOT;
tree->cache_es = NULL;
}
static void ext4_es_print_tree(struct inode *inode)
{
struct ext4_es_tree *tree;
struct rb_node *node;
printk(KERN_DEBUG "status extents for inode %lu:", inode->i_ino);
tree = &EXT4_I(inode)->i_es_tree;
node = rb_first(&tree->root);
while (node) {
struct extent_status *es;
es = rb_entry(node, struct extent_status, rb_node);
printk(KERN_DEBUG " [%u/%u) %llu %x",
es->es_lblk, es->es_len,
ext4_es_pblock(es), ext4_es_status(es));
node = rb_next(node);
}
printk(KERN_DEBUG "\n");
}
static inline ext4_lblk_t ext4_es_end(struct extent_status *es)
{
BUG_ON(es->es_lblk + es->es_len < es->es_lblk);
return es->es_lblk + es->es_len - 1;
}
static struct extent_status *__es_tree_search(struct rb_root *root,
ext4_lblk_t lblk)
{
struct rb_node *node = root->rb_node;
struct extent_status *es = NULL;
while (node) {
es = rb_entry(node, struct extent_status, rb_node);
if (lblk < es->es_lblk)
node = node->rb_left;
else if (lblk > ext4_es_end(es))
node = node->rb_right;
else
return es;
}
if (es && lblk < es->es_lblk)
return es;
if (es && lblk > ext4_es_end(es)) {
node = rb_next(&es->rb_node);
return node ? rb_entry(node, struct extent_status, rb_node) :
NULL;
}
return NULL;
}
void ext4_es_find_delayed_extent_range(struct inode *inode,
ext4_lblk_t lblk, ext4_lblk_t end,
struct extent_status *es)
{
struct ext4_es_tree *tree = NULL;
struct extent_status *es1 = NULL;
struct rb_node *node;
BUG_ON(es == NULL);
BUG_ON(end < lblk);
trace_ext4_es_find_delayed_extent_range_enter(inode, lblk);
read_lock(&EXT4_I(inode)->i_es_lock);
tree = &EXT4_I(inode)->i_es_tree;
es->es_lblk = es->es_len = es->es_pblk = 0;
if (tree->cache_es) {
es1 = tree->cache_es;
if (in_range(lblk, es1->es_lblk, es1->es_len)) {
es_debug("%u cached by [%u/%u) %llu %x\n",
lblk, es1->es_lblk, es1->es_len,
ext4_es_pblock(es1), ext4_es_status(es1));
goto out;
}
}
es1 = __es_tree_search(&tree->root, lblk);
out:
if (es1 && !ext4_es_is_delayed(es1)) {
while ((node = rb_next(&es1->rb_node)) != NULL) {
es1 = rb_entry(node, struct extent_status, rb_node);
if (es1->es_lblk > end) {
es1 = NULL;
break;
}
if (ext4_es_is_delayed(es1))
break;
}
}
if (es1 && ext4_es_is_delayed(es1)) {
tree->cache_es = es1;
es->es_lblk = es1->es_lblk;
es->es_len = es1->es_len;
es->es_pblk = es1->es_pblk;
}
read_unlock(&EXT4_I(inode)->i_es_lock);
trace_ext4_es_find_delayed_extent_range_exit(inode, es);
}
static struct extent_status *
ext4_es_alloc_extent(struct inode *inode, ext4_lblk_t lblk, ext4_lblk_t len,
ext4_fsblk_t pblk)
{
struct extent_status *es;
es = kmem_cache_alloc(ext4_es_cachep, GFP_ATOMIC);
if (es == NULL)
return NULL;
es->es_lblk = lblk;
es->es_len = len;
es->es_pblk = pblk;
if (!ext4_es_is_delayed(es)) {
EXT4_I(inode)->i_es_lru_nr++;
percpu_counter_inc(&EXT4_SB(inode->i_sb)->
s_es_stats.es_stats_lru_cnt);
}
EXT4_I(inode)->i_es_all_nr++;
percpu_counter_inc(&EXT4_SB(inode->i_sb)->s_es_stats.es_stats_all_cnt);
return es;
}
static void ext4_es_free_extent(struct inode *inode, struct extent_status *es)
{
EXT4_I(inode)->i_es_all_nr--;
percpu_counter_dec(&EXT4_SB(inode->i_sb)->s_es_stats.es_stats_all_cnt);
if (!ext4_es_is_delayed(es)) {
BUG_ON(EXT4_I(inode)->i_es_lru_nr == 0);
EXT4_I(inode)->i_es_lru_nr--;
percpu_counter_dec(&EXT4_SB(inode->i_sb)->
s_es_stats.es_stats_lru_cnt);
}
kmem_cache_free(ext4_es_cachep, es);
}
static int ext4_es_can_be_merged(struct extent_status *es1,
struct extent_status *es2)
{
if (ext4_es_status(es1) != ext4_es_status(es2))
return 0;
if (((__u64) es1->es_len) + es2->es_len > EXT_MAX_BLOCKS) {
pr_warn("ES assertion failed when merging extents. "
"The sum of lengths of es1 (%d) and es2 (%d) "
"is bigger than allowed file size (%d)\n",
es1->es_len, es2->es_len, EXT_MAX_BLOCKS);
WARN_ON(1);
return 0;
}
if (((__u64) es1->es_lblk) + es1->es_len != es2->es_lblk)
return 0;
if ((ext4_es_is_written(es1) || ext4_es_is_unwritten(es1)) &&
(ext4_es_pblock(es1) + es1->es_len == ext4_es_pblock(es2)))
return 1;
if (ext4_es_is_hole(es1))
return 1;
if (ext4_es_is_delayed(es1) && !ext4_es_is_unwritten(es1))
return 1;
return 0;
}
static struct extent_status *
ext4_es_try_to_merge_left(struct inode *inode, struct extent_status *es)
{
struct ext4_es_tree *tree = &EXT4_I(inode)->i_es_tree;
struct extent_status *es1;
struct rb_node *node;
node = rb_prev(&es->rb_node);
if (!node)
return es;
es1 = rb_entry(node, struct extent_status, rb_node);
if (ext4_es_can_be_merged(es1, es)) {
es1->es_len += es->es_len;
rb_erase(&es->rb_node, &tree->root);
ext4_es_free_extent(inode, es);
es = es1;
}
return es;
}
static struct extent_status *
ext4_es_try_to_merge_right(struct inode *inode, struct extent_status *es)
{
struct ext4_es_tree *tree = &EXT4_I(inode)->i_es_tree;
struct extent_status *es1;
struct rb_node *node;
node = rb_next(&es->rb_node);
if (!node)
return es;
es1 = rb_entry(node, struct extent_status, rb_node);
if (ext4_es_can_be_merged(es, es1)) {
es->es_len += es1->es_len;
rb_erase(node, &tree->root);
ext4_es_free_extent(inode, es1);
}
return es;
}
static void ext4_es_insert_extent_ext_check(struct inode *inode,
struct extent_status *es)
{
struct ext4_ext_path *path = NULL;
struct ext4_extent *ex;
ext4_lblk_t ee_block;
ext4_fsblk_t ee_start;
unsigned short ee_len;
int depth, ee_status, es_status;
path = ext4_find_extent(inode, es->es_lblk, NULL, EXT4_EX_NOCACHE);
if (IS_ERR(path))
return;
depth = ext_depth(inode);
ex = path[depth].p_ext;
if (ex) {
ee_block = le32_to_cpu(ex->ee_block);
ee_start = ext4_ext_pblock(ex);
ee_len = ext4_ext_get_actual_len(ex);
ee_status = ext4_ext_is_unwritten(ex) ? 1 : 0;
es_status = ext4_es_is_unwritten(es) ? 1 : 0;
if (!ext4_es_is_written(es) && !ext4_es_is_unwritten(es)) {
if (in_range(es->es_lblk, ee_block, ee_len)) {
pr_warn("ES insert assertion failed for "
"inode: %lu we can find an extent "
"at block [%d/%d/%llu/%c], but we "
"want to add a delayed/hole extent "
"[%d/%d/%llu/%x]\n",
inode->i_ino, ee_block, ee_len,
ee_start, ee_status ? 'u' : 'w',
es->es_lblk, es->es_len,
ext4_es_pblock(es), ext4_es_status(es));
}
goto out;
}
if (es->es_lblk < ee_block ||
ext4_es_pblock(es) != ee_start + es->es_lblk - ee_block) {
pr_warn("ES insert assertion failed for inode: %lu "
"ex_status [%d/%d/%llu/%c] != "
"es_status [%d/%d/%llu/%c]\n", inode->i_ino,
ee_block, ee_len, ee_start,
ee_status ? 'u' : 'w', es->es_lblk, es->es_len,
ext4_es_pblock(es), es_status ? 'u' : 'w');
goto out;
}
if (ee_status ^ es_status) {
pr_warn("ES insert assertion failed for inode: %lu "
"ex_status [%d/%d/%llu/%c] != "
"es_status [%d/%d/%llu/%c]\n", inode->i_ino,
ee_block, ee_len, ee_start,
ee_status ? 'u' : 'w', es->es_lblk, es->es_len,
ext4_es_pblock(es), es_status ? 'u' : 'w');
}
} else {
if (!ext4_es_is_delayed(es) && !ext4_es_is_hole(es)) {
pr_warn("ES insert assertion failed for inode: %lu "
"can't find an extent at block %d but we want "
"to add a written/unwritten extent "
"[%d/%d/%llu/%x]\n", inode->i_ino,
es->es_lblk, es->es_lblk, es->es_len,
ext4_es_pblock(es), ext4_es_status(es));
}
}
out:
ext4_ext_drop_refs(path);
kfree(path);
}
static void ext4_es_insert_extent_ind_check(struct inode *inode,
struct extent_status *es)
{
struct ext4_map_blocks map;
int retval;
map.m_lblk = es->es_lblk;
map.m_len = es->es_len;
retval = ext4_ind_map_blocks(NULL, inode, &map, 0);
if (retval > 0) {
if (ext4_es_is_delayed(es) || ext4_es_is_hole(es)) {
pr_warn("ES insert assertion failed for inode: %lu "
"We can find blocks but we want to add a "
"delayed/hole extent [%d/%d/%llu/%x]\n",
inode->i_ino, es->es_lblk, es->es_len,
ext4_es_pblock(es), ext4_es_status(es));
return;
} else if (ext4_es_is_written(es)) {
if (retval != es->es_len) {
pr_warn("ES insert assertion failed for "
"inode: %lu retval %d != es_len %d\n",
inode->i_ino, retval, es->es_len);
return;
}
if (map.m_pblk != ext4_es_pblock(es)) {
pr_warn("ES insert assertion failed for "
"inode: %lu m_pblk %llu != "
"es_pblk %llu\n",
inode->i_ino, map.m_pblk,
ext4_es_pblock(es));
return;
}
} else {
BUG_ON(1);
}
} else if (retval == 0) {
if (ext4_es_is_written(es)) {
pr_warn("ES insert assertion failed for inode: %lu "
"We can't find the block but we want to add "
"a written extent [%d/%d/%llu/%x]\n",
inode->i_ino, es->es_lblk, es->es_len,
ext4_es_pblock(es), ext4_es_status(es));
return;
}
}
}
static inline void ext4_es_insert_extent_check(struct inode *inode,
struct extent_status *es)
{
BUG_ON(!rwsem_is_locked(&EXT4_I(inode)->i_data_sem));
if (ext4_test_inode_flag(inode, EXT4_INODE_EXTENTS))
ext4_es_insert_extent_ext_check(inode, es);
else
ext4_es_insert_extent_ind_check(inode, es);
}
static inline void ext4_es_insert_extent_check(struct inode *inode,
struct extent_status *es)
{
}
static int __es_insert_extent(struct inode *inode, struct extent_status *newes)
{
struct ext4_es_tree *tree = &EXT4_I(inode)->i_es_tree;
struct rb_node **p = &tree->root.rb_node;
struct rb_node *parent = NULL;
struct extent_status *es;
while (*p) {
parent = *p;
es = rb_entry(parent, struct extent_status, rb_node);
if (newes->es_lblk < es->es_lblk) {
if (ext4_es_can_be_merged(newes, es)) {
es->es_lblk = newes->es_lblk;
es->es_len += newes->es_len;
if (ext4_es_is_written(es) ||
ext4_es_is_unwritten(es))
ext4_es_store_pblock(es,
newes->es_pblk);
es = ext4_es_try_to_merge_left(inode, es);
goto out;
}
p = &(*p)->rb_left;
} else if (newes->es_lblk > ext4_es_end(es)) {
if (ext4_es_can_be_merged(es, newes)) {
es->es_len += newes->es_len;
es = ext4_es_try_to_merge_right(inode, es);
goto out;
}
p = &(*p)->rb_right;
} else {
BUG_ON(1);
return -EINVAL;
}
}
es = ext4_es_alloc_extent(inode, newes->es_lblk, newes->es_len,
newes->es_pblk);
if (!es)
return -ENOMEM;
rb_link_node(&es->rb_node, parent, p);
rb_insert_color(&es->rb_node, &tree->root);
out:
tree->cache_es = es;
return 0;
}
int ext4_es_insert_extent(struct inode *inode, ext4_lblk_t lblk,
ext4_lblk_t len, ext4_fsblk_t pblk,
unsigned int status)
{
struct extent_status newes;
ext4_lblk_t end = lblk + len - 1;
int err = 0;
es_debug("add [%u/%u) %llu %x to extent status tree of inode %lu\n",
lblk, len, pblk, status, inode->i_ino);
if (!len)
return 0;
BUG_ON(end < lblk);
newes.es_lblk = lblk;
newes.es_len = len;
ext4_es_store_pblock_status(&newes, pblk, status);
trace_ext4_es_insert_extent(inode, &newes);
ext4_es_insert_extent_check(inode, &newes);
write_lock(&EXT4_I(inode)->i_es_lock);
err = __es_remove_extent(inode, lblk, end);
if (err != 0)
goto error;
retry:
err = __es_insert_extent(inode, &newes);
if (err == -ENOMEM && __ext4_es_shrink(EXT4_SB(inode->i_sb), 1,
EXT4_I(inode)))
goto retry;
if (err == -ENOMEM && !ext4_es_is_delayed(&newes))
err = 0;
error:
write_unlock(&EXT4_I(inode)->i_es_lock);
ext4_es_print_tree(inode);
return err;
}
void ext4_es_cache_extent(struct inode *inode, ext4_lblk_t lblk,
ext4_lblk_t len, ext4_fsblk_t pblk,
unsigned int status)
{
struct extent_status *es;
struct extent_status newes;
ext4_lblk_t end = lblk + len - 1;
newes.es_lblk = lblk;
newes.es_len = len;
ext4_es_store_pblock_status(&newes, pblk, status);
trace_ext4_es_cache_extent(inode, &newes);
if (!len)
return;
BUG_ON(end < lblk);
write_lock(&EXT4_I(inode)->i_es_lock);
es = __es_tree_search(&EXT4_I(inode)->i_es_tree.root, lblk);
if (!es || es->es_lblk > end)
__es_insert_extent(inode, &newes);
write_unlock(&EXT4_I(inode)->i_es_lock);
}
int ext4_es_lookup_extent(struct inode *inode, ext4_lblk_t lblk,
struct extent_status *es)
{
struct ext4_es_tree *tree;
struct ext4_es_stats *stats;
struct extent_status *es1 = NULL;
struct rb_node *node;
int found = 0;
trace_ext4_es_lookup_extent_enter(inode, lblk);
es_debug("lookup extent in block %u\n", lblk);
tree = &EXT4_I(inode)->i_es_tree;
read_lock(&EXT4_I(inode)->i_es_lock);
es->es_lblk = es->es_len = es->es_pblk = 0;
if (tree->cache_es) {
es1 = tree->cache_es;
if (in_range(lblk, es1->es_lblk, es1->es_len)) {
es_debug("%u cached by [%u/%u)\n",
lblk, es1->es_lblk, es1->es_len);
found = 1;
goto out;
}
}
node = tree->root.rb_node;
while (node) {
es1 = rb_entry(node, struct extent_status, rb_node);
if (lblk < es1->es_lblk)
node = node->rb_left;
else if (lblk > ext4_es_end(es1))
node = node->rb_right;
else {
found = 1;
break;
}
}
out:
stats = &EXT4_SB(inode->i_sb)->s_es_stats;
if (found) {
BUG_ON(!es1);
es->es_lblk = es1->es_lblk;
es->es_len = es1->es_len;
es->es_pblk = es1->es_pblk;
stats->es_stats_cache_hits++;
} else {
stats->es_stats_cache_misses++;
}
read_unlock(&EXT4_I(inode)->i_es_lock);
trace_ext4_es_lookup_extent_exit(inode, es, found);
return found;
}
static int __es_remove_extent(struct inode *inode, ext4_lblk_t lblk,
ext4_lblk_t end)
{
struct ext4_es_tree *tree = &EXT4_I(inode)->i_es_tree;
struct rb_node *node;
struct extent_status *es;
struct extent_status orig_es;
ext4_lblk_t len1, len2;
ext4_fsblk_t block;
int err;
retry:
err = 0;
es = __es_tree_search(&tree->root, lblk);
if (!es)
goto out;
if (es->es_lblk > end)
goto out;
tree->cache_es = NULL;
orig_es.es_lblk = es->es_lblk;
orig_es.es_len = es->es_len;
orig_es.es_pblk = es->es_pblk;
len1 = lblk > es->es_lblk ? lblk - es->es_lblk : 0;
len2 = ext4_es_end(es) > end ? ext4_es_end(es) - end : 0;
if (len1 > 0)
es->es_len = len1;
if (len2 > 0) {
if (len1 > 0) {
struct extent_status newes;
newes.es_lblk = end + 1;
newes.es_len = len2;
block = 0x7FDEADBEEFULL;
if (ext4_es_is_written(&orig_es) ||
ext4_es_is_unwritten(&orig_es))
block = ext4_es_pblock(&orig_es) +
orig_es.es_len - len2;
ext4_es_store_pblock_status(&newes, block,
ext4_es_status(&orig_es));
err = __es_insert_extent(inode, &newes);
if (err) {
es->es_lblk = orig_es.es_lblk;
es->es_len = orig_es.es_len;
if ((err == -ENOMEM) &&
__ext4_es_shrink(EXT4_SB(inode->i_sb), 1,
EXT4_I(inode)))
goto retry;
goto out;
}
} else {
es->es_lblk = end + 1;
es->es_len = len2;
if (ext4_es_is_written(es) ||
ext4_es_is_unwritten(es)) {
block = orig_es.es_pblk + orig_es.es_len - len2;
ext4_es_store_pblock(es, block);
}
}
goto out;
}
if (len1 > 0) {
node = rb_next(&es->rb_node);
if (node)
es = rb_entry(node, struct extent_status, rb_node);
else
es = NULL;
}
while (es && ext4_es_end(es) <= end) {
node = rb_next(&es->rb_node);
rb_erase(&es->rb_node, &tree->root);
ext4_es_free_extent(inode, es);
if (!node) {
es = NULL;
break;
}
es = rb_entry(node, struct extent_status, rb_node);
}
if (es && es->es_lblk < end + 1) {
ext4_lblk_t orig_len = es->es_len;
len1 = ext4_es_end(es) - end;
es->es_lblk = end + 1;
es->es_len = len1;
if (ext4_es_is_written(es) || ext4_es_is_unwritten(es)) {
block = es->es_pblk + orig_len - len1;
ext4_es_store_pblock(es, block);
}
}
out:
return err;
}
int ext4_es_remove_extent(struct inode *inode, ext4_lblk_t lblk,
ext4_lblk_t len)
{
ext4_lblk_t end;
int err = 0;
trace_ext4_es_remove_extent(inode, lblk, len);
es_debug("remove [%u/%u) from extent status tree of inode %lu\n",
lblk, len, inode->i_ino);
if (!len)
return err;
end = lblk + len - 1;
BUG_ON(end < lblk);
write_lock(&EXT4_I(inode)->i_es_lock);
err = __es_remove_extent(inode, lblk, end);
write_unlock(&EXT4_I(inode)->i_es_lock);
ext4_es_print_tree(inode);
return err;
}
static int ext4_inode_touch_time_cmp(void *priv, struct list_head *a,
struct list_head *b)
{
struct ext4_inode_info *eia, *eib;
eia = list_entry(a, struct ext4_inode_info, i_es_lru);
eib = list_entry(b, struct ext4_inode_info, i_es_lru);
if (ext4_test_inode_state(&eia->vfs_inode, EXT4_STATE_EXT_PRECACHED) &&
!ext4_test_inode_state(&eib->vfs_inode, EXT4_STATE_EXT_PRECACHED))
return 1;
if (!ext4_test_inode_state(&eia->vfs_inode, EXT4_STATE_EXT_PRECACHED) &&
ext4_test_inode_state(&eib->vfs_inode, EXT4_STATE_EXT_PRECACHED))
return -1;
if (eia->i_touch_when == eib->i_touch_when)
return 0;
if (time_after(eia->i_touch_when, eib->i_touch_when))
return 1;
else
return -1;
}
static int __ext4_es_shrink(struct ext4_sb_info *sbi, int nr_to_scan,
struct ext4_inode_info *locked_ei)
{
struct ext4_inode_info *ei;
struct ext4_es_stats *es_stats;
struct list_head *cur, *tmp;
LIST_HEAD(skipped);
ktime_t start_time;
u64 scan_time;
int nr_shrunk = 0;
int retried = 0, skip_precached = 1, nr_skipped = 0;
es_stats = &sbi->s_es_stats;
start_time = ktime_get();
spin_lock(&sbi->s_es_lru_lock);
retry:
list_for_each_safe(cur, tmp, &sbi->s_es_lru) {
int shrunk;
if (percpu_counter_read_positive(
&es_stats->es_stats_lru_cnt) == 0)
break;
ei = list_entry(cur, struct ext4_inode_info, i_es_lru);
if ((es_stats->es_stats_last_sorted < ei->i_touch_when) ||
(skip_precached && ext4_test_inode_state(&ei->vfs_inode,
EXT4_STATE_EXT_PRECACHED))) {
nr_skipped++;
list_move_tail(cur, &skipped);
continue;
}
if (ei->i_es_lru_nr == 0 || ei == locked_ei ||
!write_trylock(&ei->i_es_lock))
continue;
shrunk = __es_try_to_reclaim_extents(ei, nr_to_scan);
if (ei->i_es_lru_nr == 0)
list_del_init(&ei->i_es_lru);
write_unlock(&ei->i_es_lock);
nr_shrunk += shrunk;
nr_to_scan -= shrunk;
if (nr_to_scan == 0)
break;
}
list_splice_tail(&skipped, &sbi->s_es_lru);
INIT_LIST_HEAD(&skipped);
if ((nr_shrunk == 0) && nr_skipped && !retried) {
retried++;
list_sort(NULL, &sbi->s_es_lru, ext4_inode_touch_time_cmp);
es_stats->es_stats_last_sorted = jiffies;
ei = list_first_entry(&sbi->s_es_lru, struct ext4_inode_info,
i_es_lru);
if (ext4_test_inode_state(&ei->vfs_inode,
EXT4_STATE_EXT_PRECACHED))
skip_precached = 0;
goto retry;
}
spin_unlock(&sbi->s_es_lru_lock);
if (locked_ei && nr_shrunk == 0)
nr_shrunk = __es_try_to_reclaim_extents(locked_ei, nr_to_scan);
scan_time = ktime_to_ns(ktime_sub(ktime_get(), start_time));
if (likely(es_stats->es_stats_scan_time))
es_stats->es_stats_scan_time = (scan_time +
es_stats->es_stats_scan_time*3) / 4;
else
es_stats->es_stats_scan_time = scan_time;
if (scan_time > es_stats->es_stats_max_scan_time)
es_stats->es_stats_max_scan_time = scan_time;
if (likely(es_stats->es_stats_shrunk))
es_stats->es_stats_shrunk = (nr_shrunk +
es_stats->es_stats_shrunk*3) / 4;
else
es_stats->es_stats_shrunk = nr_shrunk;
trace_ext4_es_shrink(sbi->s_sb, nr_shrunk, scan_time, skip_precached,
nr_skipped, retried);
return nr_shrunk;
}
static unsigned long ext4_es_count(struct shrinker *shrink,
struct shrink_control *sc)
{
unsigned long nr;
struct ext4_sb_info *sbi;
sbi = container_of(shrink, struct ext4_sb_info, s_es_shrinker);
nr = percpu_counter_read_positive(&sbi->s_es_stats.es_stats_lru_cnt);
trace_ext4_es_shrink_count(sbi->s_sb, sc->nr_to_scan, nr);
return nr;
}
static unsigned long ext4_es_scan(struct shrinker *shrink,
struct shrink_control *sc)
{
struct ext4_sb_info *sbi = container_of(shrink,
struct ext4_sb_info, s_es_shrinker);
int nr_to_scan = sc->nr_to_scan;
int ret, nr_shrunk;
ret = percpu_counter_read_positive(&sbi->s_es_stats.es_stats_lru_cnt);
trace_ext4_es_shrink_scan_enter(sbi->s_sb, nr_to_scan, ret);
if (!nr_to_scan)
return ret;
nr_shrunk = __ext4_es_shrink(sbi, nr_to_scan, NULL);
trace_ext4_es_shrink_scan_exit(sbi->s_sb, nr_shrunk, ret);
return nr_shrunk;
}
static void *ext4_es_seq_shrinker_info_start(struct seq_file *seq, loff_t *pos)
{
return *pos ? NULL : SEQ_START_TOKEN;
}
static void *
ext4_es_seq_shrinker_info_next(struct seq_file *seq, void *v, loff_t *pos)
{
return NULL;
}
static int ext4_es_seq_shrinker_info_show(struct seq_file *seq, void *v)
{
struct ext4_sb_info *sbi = seq->private;
struct ext4_es_stats *es_stats = &sbi->s_es_stats;
struct ext4_inode_info *ei, *max = NULL;
unsigned int inode_cnt = 0;
if (v != SEQ_START_TOKEN)
return 0;
spin_lock(&sbi->s_es_lru_lock);
list_for_each_entry(ei, &sbi->s_es_lru, i_es_lru) {
inode_cnt++;
if (max && max->i_es_all_nr < ei->i_es_all_nr)
max = ei;
else if (!max)
max = ei;
}
spin_unlock(&sbi->s_es_lru_lock);
seq_printf(seq, "stats:\n %lld objects\n %lld reclaimable objects\n",
percpu_counter_sum_positive(&es_stats->es_stats_all_cnt),
percpu_counter_sum_positive(&es_stats->es_stats_lru_cnt));
seq_printf(seq, " %lu/%lu cache hits/misses\n",
es_stats->es_stats_cache_hits,
es_stats->es_stats_cache_misses);
if (es_stats->es_stats_last_sorted != 0)
seq_printf(seq, " %u ms last sorted interval\n",
jiffies_to_msecs(jiffies -
es_stats->es_stats_last_sorted));
if (inode_cnt)
seq_printf(seq, " %d inodes on lru list\n", inode_cnt);
seq_printf(seq, "average:\n %llu us scan time\n",
div_u64(es_stats->es_stats_scan_time, 1000));
seq_printf(seq, " %lu shrunk objects\n", es_stats->es_stats_shrunk);
if (inode_cnt)
seq_printf(seq,
"maximum:\n %lu inode (%u objects, %u reclaimable)\n"
" %llu us max scan time\n",
max->vfs_inode.i_ino, max->i_es_all_nr, max->i_es_lru_nr,
div_u64(es_stats->es_stats_max_scan_time, 1000));
return 0;
}
static void ext4_es_seq_shrinker_info_stop(struct seq_file *seq, void *v)
{
}
static int
ext4_es_seq_shrinker_info_open(struct inode *inode, struct file *file)
{
int ret;
ret = seq_open(file, &ext4_es_seq_shrinker_info_ops);
if (!ret) {
struct seq_file *m = file->private_data;
m->private = PDE_DATA(inode);
}
return ret;
}
static int
ext4_es_seq_shrinker_info_release(struct inode *inode, struct file *file)
{
return seq_release(inode, file);
}
int ext4_es_register_shrinker(struct ext4_sb_info *sbi)
{
int err;
INIT_LIST_HEAD(&sbi->s_es_lru);
spin_lock_init(&sbi->s_es_lru_lock);
sbi->s_es_stats.es_stats_last_sorted = 0;
sbi->s_es_stats.es_stats_shrunk = 0;
sbi->s_es_stats.es_stats_cache_hits = 0;
sbi->s_es_stats.es_stats_cache_misses = 0;
sbi->s_es_stats.es_stats_scan_time = 0;
sbi->s_es_stats.es_stats_max_scan_time = 0;
err = percpu_counter_init(&sbi->s_es_stats.es_stats_all_cnt, 0, GFP_KERNEL);
if (err)
return err;
err = percpu_counter_init(&sbi->s_es_stats.es_stats_lru_cnt, 0, GFP_KERNEL);
if (err)
goto err1;
sbi->s_es_shrinker.scan_objects = ext4_es_scan;
sbi->s_es_shrinker.count_objects = ext4_es_count;
sbi->s_es_shrinker.seeks = DEFAULT_SEEKS;
err = register_shrinker(&sbi->s_es_shrinker);
if (err)
goto err2;
if (sbi->s_proc)
proc_create_data("es_shrinker_info", S_IRUGO, sbi->s_proc,
&ext4_es_seq_shrinker_info_fops, sbi);
return 0;
err2:
percpu_counter_destroy(&sbi->s_es_stats.es_stats_lru_cnt);
err1:
percpu_counter_destroy(&sbi->s_es_stats.es_stats_all_cnt);
return err;
}
void ext4_es_unregister_shrinker(struct ext4_sb_info *sbi)
{
if (sbi->s_proc)
remove_proc_entry("es_shrinker_info", sbi->s_proc);
percpu_counter_destroy(&sbi->s_es_stats.es_stats_all_cnt);
percpu_counter_destroy(&sbi->s_es_stats.es_stats_lru_cnt);
unregister_shrinker(&sbi->s_es_shrinker);
}
void ext4_es_lru_add(struct inode *inode)
{
struct ext4_inode_info *ei = EXT4_I(inode);
struct ext4_sb_info *sbi = EXT4_SB(inode->i_sb);
ei->i_touch_when = jiffies;
if (!list_empty(&ei->i_es_lru))
return;
spin_lock(&sbi->s_es_lru_lock);
if (list_empty(&ei->i_es_lru))
list_add_tail(&ei->i_es_lru, &sbi->s_es_lru);
spin_unlock(&sbi->s_es_lru_lock);
}
void ext4_es_lru_del(struct inode *inode)
{
struct ext4_inode_info *ei = EXT4_I(inode);
struct ext4_sb_info *sbi = EXT4_SB(inode->i_sb);
spin_lock(&sbi->s_es_lru_lock);
if (!list_empty(&ei->i_es_lru))
list_del_init(&ei->i_es_lru);
spin_unlock(&sbi->s_es_lru_lock);
}
static int __es_try_to_reclaim_extents(struct ext4_inode_info *ei,
int nr_to_scan)
{
struct inode *inode = &ei->vfs_inode;
struct ext4_es_tree *tree = &ei->i_es_tree;
struct rb_node *node;
struct extent_status *es;
unsigned long nr_shrunk = 0;
static DEFINE_RATELIMIT_STATE(_rs, DEFAULT_RATELIMIT_INTERVAL,
DEFAULT_RATELIMIT_BURST);
if (ei->i_es_lru_nr == 0)
return 0;
if (ext4_test_inode_state(inode, EXT4_STATE_EXT_PRECACHED) &&
__ratelimit(&_rs))
ext4_warning(inode->i_sb, "forced shrink of precached extents");
node = rb_first(&tree->root);
while (node != NULL) {
es = rb_entry(node, struct extent_status, rb_node);
node = rb_next(&es->rb_node);
if (!ext4_es_is_delayed(es)) {
rb_erase(&es->rb_node, &tree->root);
ext4_es_free_extent(inode, es);
nr_shrunk++;
if (--nr_to_scan == 0)
break;
}
}
tree->cache_es = NULL;
return nr_shrunk;
}
