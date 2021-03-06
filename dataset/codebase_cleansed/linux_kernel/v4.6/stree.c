inline int B_IS_IN_TREE(const struct buffer_head *bh)
{
RFALSE(B_LEVEL(bh) > MAX_HEIGHT,
"PAP-1010: block (%b) has too big level (%z)", bh, bh);
return (B_LEVEL(bh) != FREE_LEVEL);
}
inline void copy_item_head(struct item_head *to,
const struct item_head *from)
{
memcpy(to, from, IH_SIZE);
}
inline int comp_short_keys(const struct reiserfs_key *le_key,
const struct cpu_key *cpu_key)
{
__u32 n;
n = le32_to_cpu(le_key->k_dir_id);
if (n < cpu_key->on_disk_key.k_dir_id)
return -1;
if (n > cpu_key->on_disk_key.k_dir_id)
return 1;
n = le32_to_cpu(le_key->k_objectid);
if (n < cpu_key->on_disk_key.k_objectid)
return -1;
if (n > cpu_key->on_disk_key.k_objectid)
return 1;
return 0;
}
static inline int comp_keys(const struct reiserfs_key *le_key,
const struct cpu_key *cpu_key)
{
int retval;
retval = comp_short_keys(le_key, cpu_key);
if (retval)
return retval;
if (le_key_k_offset(le_key_version(le_key), le_key) <
cpu_key_k_offset(cpu_key))
return -1;
if (le_key_k_offset(le_key_version(le_key), le_key) >
cpu_key_k_offset(cpu_key))
return 1;
if (cpu_key->key_length == 3)
return 0;
if (le_key_k_type(le_key_version(le_key), le_key) <
cpu_key_k_type(cpu_key))
return -1;
if (le_key_k_type(le_key_version(le_key), le_key) >
cpu_key_k_type(cpu_key))
return 1;
return 0;
}
inline int comp_short_le_keys(const struct reiserfs_key *key1,
const struct reiserfs_key *key2)
{
__u32 *k1_u32, *k2_u32;
int key_length = REISERFS_SHORT_KEY_LEN;
k1_u32 = (__u32 *) key1;
k2_u32 = (__u32 *) key2;
for (; key_length--; ++k1_u32, ++k2_u32) {
if (le32_to_cpu(*k1_u32) < le32_to_cpu(*k2_u32))
return -1;
if (le32_to_cpu(*k1_u32) > le32_to_cpu(*k2_u32))
return 1;
}
return 0;
}
inline void le_key2cpu_key(struct cpu_key *to, const struct reiserfs_key *from)
{
int version;
to->on_disk_key.k_dir_id = le32_to_cpu(from->k_dir_id);
to->on_disk_key.k_objectid = le32_to_cpu(from->k_objectid);
version = le_key_version(from);
to->version = version;
to->on_disk_key.k_offset = le_key_k_offset(version, from);
to->on_disk_key.k_type = le_key_k_type(version, from);
}
inline int comp_le_keys(const struct reiserfs_key *k1,
const struct reiserfs_key *k2)
{
return memcmp(k1, k2, sizeof(struct reiserfs_key));
}
static inline int bin_search(const void *key,
const void *base,
int num,
int width,
int *pos
)
{
int rbound, lbound, j;
for (j = ((rbound = num - 1) + (lbound = 0)) / 2;
lbound <= rbound; j = (rbound + lbound) / 2)
switch (comp_keys
((struct reiserfs_key *)((char *)base + j * width),
(struct cpu_key *)key)) {
case -1:
lbound = j + 1;
continue;
case 1:
rbound = j - 1;
continue;
case 0:
*pos = j;
return ITEM_FOUND;
}
*pos = lbound;
return ITEM_NOT_FOUND;
}
static inline const struct reiserfs_key *get_lkey(const struct treepath *chk_path,
const struct super_block *sb)
{
int position, path_offset = chk_path->path_length;
struct buffer_head *parent;
RFALSE(path_offset < FIRST_PATH_ELEMENT_OFFSET,
"PAP-5010: invalid offset in the path");
while (path_offset-- > FIRST_PATH_ELEMENT_OFFSET) {
RFALSE(!buffer_uptodate
(PATH_OFFSET_PBUFFER(chk_path, path_offset)),
"PAP-5020: parent is not uptodate");
if (!B_IS_IN_TREE
(parent =
PATH_OFFSET_PBUFFER(chk_path, path_offset)))
return &MAX_KEY;
if ((position =
PATH_OFFSET_POSITION(chk_path,
path_offset)) >
B_NR_ITEMS(parent))
return &MAX_KEY;
if (B_N_CHILD_NUM(parent, position) !=
PATH_OFFSET_PBUFFER(chk_path,
path_offset + 1)->b_blocknr)
return &MAX_KEY;
if (position)
return internal_key(parent, position - 1);
}
if (PATH_OFFSET_PBUFFER(chk_path, FIRST_PATH_ELEMENT_OFFSET)->
b_blocknr == SB_ROOT_BLOCK(sb))
return &MIN_KEY;
return &MAX_KEY;
}
inline const struct reiserfs_key *get_rkey(const struct treepath *chk_path,
const struct super_block *sb)
{
int position, path_offset = chk_path->path_length;
struct buffer_head *parent;
RFALSE(path_offset < FIRST_PATH_ELEMENT_OFFSET,
"PAP-5030: invalid offset in the path");
while (path_offset-- > FIRST_PATH_ELEMENT_OFFSET) {
RFALSE(!buffer_uptodate
(PATH_OFFSET_PBUFFER(chk_path, path_offset)),
"PAP-5040: parent is not uptodate");
if (!B_IS_IN_TREE
(parent =
PATH_OFFSET_PBUFFER(chk_path, path_offset)))
return &MIN_KEY;
if ((position =
PATH_OFFSET_POSITION(chk_path,
path_offset)) >
B_NR_ITEMS(parent))
return &MIN_KEY;
if (B_N_CHILD_NUM(parent, position) !=
PATH_OFFSET_PBUFFER(chk_path,
path_offset + 1)->b_blocknr)
return &MIN_KEY;
if (position != B_NR_ITEMS(parent))
return internal_key(parent, position);
}
if (PATH_OFFSET_PBUFFER(chk_path, FIRST_PATH_ELEMENT_OFFSET)->
b_blocknr == SB_ROOT_BLOCK(sb))
return &MAX_KEY;
return &MIN_KEY;
}
static inline int key_in_buffer(
struct treepath *chk_path,
const struct cpu_key *key,
struct super_block *sb
)
{
RFALSE(!key || chk_path->path_length < FIRST_PATH_ELEMENT_OFFSET
|| chk_path->path_length > MAX_HEIGHT,
"PAP-5050: pointer to the key(%p) is NULL or invalid path length(%d)",
key, chk_path->path_length);
RFALSE(!PATH_PLAST_BUFFER(chk_path)->b_bdev,
"PAP-5060: device must not be NODEV");
if (comp_keys(get_lkey(chk_path, sb), key) == 1)
return 0;
if (comp_keys(get_rkey(chk_path, sb), key) != 1)
return 0;
return 1;
}
int reiserfs_check_path(struct treepath *p)
{
RFALSE(p->path_length != ILLEGAL_PATH_ELEMENT_OFFSET,
"path not properly relsed");
return 0;
}
void pathrelse_and_restore(struct super_block *sb,
struct treepath *search_path)
{
int path_offset = search_path->path_length;
RFALSE(path_offset < ILLEGAL_PATH_ELEMENT_OFFSET,
"clm-4000: invalid path offset");
while (path_offset > ILLEGAL_PATH_ELEMENT_OFFSET) {
struct buffer_head *bh;
bh = PATH_OFFSET_PBUFFER(search_path, path_offset--);
reiserfs_restore_prepared_buffer(sb, bh);
brelse(bh);
}
search_path->path_length = ILLEGAL_PATH_ELEMENT_OFFSET;
}
void pathrelse(struct treepath *search_path)
{
int path_offset = search_path->path_length;
RFALSE(path_offset < ILLEGAL_PATH_ELEMENT_OFFSET,
"PAP-5090: invalid path offset");
while (path_offset > ILLEGAL_PATH_ELEMENT_OFFSET)
brelse(PATH_OFFSET_PBUFFER(search_path, path_offset--));
search_path->path_length = ILLEGAL_PATH_ELEMENT_OFFSET;
}
static int is_leaf(char *buf, int blocksize, struct buffer_head *bh)
{
struct block_head *blkh;
struct item_head *ih;
int used_space;
int prev_location;
int i;
int nr;
blkh = (struct block_head *)buf;
if (blkh_level(blkh) != DISK_LEAF_NODE_LEVEL) {
reiserfs_warning(NULL, "reiserfs-5080",
"this should be caught earlier");
return 0;
}
nr = blkh_nr_item(blkh);
if (nr < 1 || nr > ((blocksize - BLKH_SIZE) / (IH_SIZE + MIN_ITEM_LEN))) {
reiserfs_warning(NULL, "reiserfs-5081",
"nr_item seems wrong: %z", bh);
return 0;
}
ih = (struct item_head *)(buf + BLKH_SIZE) + nr - 1;
used_space = BLKH_SIZE + IH_SIZE * nr + (blocksize - ih_location(ih));
if (used_space != blocksize - blkh_free_space(blkh)) {
reiserfs_warning(NULL, "reiserfs-5082",
"free space seems wrong: %z", bh);
return 0;
}
ih = (struct item_head *)(buf + BLKH_SIZE);
prev_location = blocksize;
for (i = 0; i < nr; i++, ih++) {
if (le_ih_k_type(ih) == TYPE_ANY) {
reiserfs_warning(NULL, "reiserfs-5083",
"wrong item type for item %h",
ih);
return 0;
}
if (ih_location(ih) >= blocksize
|| ih_location(ih) < IH_SIZE * nr) {
reiserfs_warning(NULL, "reiserfs-5084",
"item location seems wrong: %h",
ih);
return 0;
}
if (ih_item_len(ih) < 1
|| ih_item_len(ih) > MAX_ITEM_LEN(blocksize)) {
reiserfs_warning(NULL, "reiserfs-5085",
"item length seems wrong: %h",
ih);
return 0;
}
if (prev_location - ih_location(ih) != ih_item_len(ih)) {
reiserfs_warning(NULL, "reiserfs-5086",
"item location seems wrong "
"(second one): %h", ih);
return 0;
}
prev_location = ih_location(ih);
}
return 1;
}
static int is_internal(char *buf, int blocksize, struct buffer_head *bh)
{
struct block_head *blkh;
int nr;
int used_space;
blkh = (struct block_head *)buf;
nr = blkh_level(blkh);
if (nr <= DISK_LEAF_NODE_LEVEL || nr > MAX_HEIGHT) {
reiserfs_warning(NULL, "reiserfs-5087",
"this should be caught earlier");
return 0;
}
nr = blkh_nr_item(blkh);
if (nr > (blocksize - BLKH_SIZE - DC_SIZE) / (KEY_SIZE + DC_SIZE)) {
reiserfs_warning(NULL, "reiserfs-5088",
"number of key seems wrong: %z", bh);
return 0;
}
used_space = BLKH_SIZE + KEY_SIZE * nr + DC_SIZE * (nr + 1);
if (used_space != blocksize - blkh_free_space(blkh)) {
reiserfs_warning(NULL, "reiserfs-5089",
"free space seems wrong: %z", bh);
return 0;
}
return 1;
}
static int is_tree_node(struct buffer_head *bh, int level)
{
if (B_LEVEL(bh) != level) {
reiserfs_warning(NULL, "reiserfs-5090", "node level %d does "
"not match to the expected one %d",
B_LEVEL(bh), level);
return 0;
}
if (level == DISK_LEAF_NODE_LEVEL)
return is_leaf(bh->b_data, bh->b_size, bh);
return is_internal(bh->b_data, bh->b_size, bh);
}
static int search_by_key_reada(struct super_block *s,
struct buffer_head **bh,
b_blocknr_t *b, int num)
{
int i, j;
int depth = -1;
for (i = 0; i < num; i++) {
bh[i] = sb_getblk(s, b[i]);
}
for (j = 0; j < i; j++) {
if (!buffer_uptodate(bh[j])) {
if (depth == -1)
depth = reiserfs_write_unlock_nested(s);
ll_rw_block(READA, 1, bh + j);
}
brelse(bh[j]);
}
return depth;
}
int search_by_key(struct super_block *sb, const struct cpu_key *key,
struct treepath *search_path, int stop_level)
{
b_blocknr_t block_number;
int expected_level;
struct buffer_head *bh;
struct path_element *last_element;
int node_level, retval;
int right_neighbor_of_leaf_node;
int fs_gen;
struct buffer_head *reada_bh[SEARCH_BY_KEY_READA];
b_blocknr_t reada_blocks[SEARCH_BY_KEY_READA];
int reada_count = 0;
#ifdef CONFIG_REISERFS_CHECK
int repeat_counter = 0;
#endif
PROC_INFO_INC(sb, search_by_key);
pathrelse(search_path);
right_neighbor_of_leaf_node = 0;
block_number = SB_ROOT_BLOCK(sb);
expected_level = -1;
while (1) {
#ifdef CONFIG_REISERFS_CHECK
if (!(++repeat_counter % 50000))
reiserfs_warning(sb, "PAP-5100",
"%s: there were %d iterations of "
"while loop looking for key %K",
current->comm, repeat_counter,
key);
#endif
last_element =
PATH_OFFSET_PELEMENT(search_path,
++search_path->path_length);
fs_gen = get_generation(sb);
if ((bh = last_element->pe_buffer =
sb_getblk(sb, block_number))) {
int depth = -1;
if (!buffer_uptodate(bh) && reada_count > 1)
depth = search_by_key_reada(sb, reada_bh,
reada_blocks, reada_count);
if (!buffer_uptodate(bh) && depth == -1)
depth = reiserfs_write_unlock_nested(sb);
ll_rw_block(READ, 1, &bh);
wait_on_buffer(bh);
if (depth != -1)
reiserfs_write_lock_nested(sb, depth);
if (!buffer_uptodate(bh))
goto io_error;
} else {
io_error:
search_path->path_length--;
pathrelse(search_path);
return IO_ERROR;
}
reada_count = 0;
if (expected_level == -1)
expected_level = SB_TREE_HEIGHT(sb);
expected_level--;
if (fs_changed(fs_gen, sb) &&
(!B_IS_IN_TREE(bh) ||
B_LEVEL(bh) != expected_level ||
!key_in_buffer(search_path, key, sb))) {
PROC_INFO_INC(sb, search_by_key_fs_changed);
PROC_INFO_INC(sb, search_by_key_restarted);
PROC_INFO_INC(sb,
sbk_restarted[expected_level - 1]);
pathrelse(search_path);
block_number = SB_ROOT_BLOCK(sb);
expected_level = -1;
right_neighbor_of_leaf_node = 0;
continue;
}
RFALSE(comp_keys(&MAX_KEY, key) &&
!key_in_buffer(search_path, key, sb),
"PAP-5130: key is not in the buffer");
#ifdef CONFIG_REISERFS_CHECK
if (REISERFS_SB(sb)->cur_tb) {
print_cur_tb("5140");
reiserfs_panic(sb, "PAP-5140",
"schedule occurred in do_balance!");
}
#endif
if (!is_tree_node(bh, expected_level)) {
reiserfs_error(sb, "vs-5150",
"invalid format found in block %ld. "
"Fsck?", bh->b_blocknr);
pathrelse(search_path);
return IO_ERROR;
}
node_level = B_LEVEL(bh);
PROC_INFO_BH_STAT(sb, bh, node_level - 1);
RFALSE(node_level < stop_level,
"vs-5152: tree level (%d) is less than stop level (%d)",
node_level, stop_level);
retval = bin_search(key, item_head(bh, 0),
B_NR_ITEMS(bh),
(node_level ==
DISK_LEAF_NODE_LEVEL) ? IH_SIZE :
KEY_SIZE,
&last_element->pe_position);
if (node_level == stop_level) {
return retval;
}
if (retval == ITEM_FOUND)
last_element->pe_position++;
block_number =
B_N_CHILD_NUM(bh, last_element->pe_position);
if ((search_path->reada & PATH_READA) &&
node_level == DISK_LEAF_NODE_LEVEL + 1) {
int pos = last_element->pe_position;
int limit = B_NR_ITEMS(bh);
struct reiserfs_key *le_key;
if (search_path->reada & PATH_READA_BACK)
limit = 0;
while (reada_count < SEARCH_BY_KEY_READA) {
if (pos == limit)
break;
reada_blocks[reada_count++] =
B_N_CHILD_NUM(bh, pos);
if (search_path->reada & PATH_READA_BACK)
pos--;
else
pos++;
le_key = internal_key(bh, pos);
if (le32_to_cpu(le_key->k_objectid) !=
key->on_disk_key.k_objectid) {
break;
}
}
}
}
}
int search_for_position_by_key(struct super_block *sb,
const struct cpu_key *p_cpu_key,
struct treepath *search_path)
{
struct item_head *p_le_ih;
int blk_size;
loff_t item_offset, offset;
struct reiserfs_dir_entry de;
int retval;
if (is_direntry_cpu_key(p_cpu_key))
return search_by_entry_key(sb, p_cpu_key, search_path,
&de);
retval = search_item(sb, p_cpu_key, search_path);
if (retval == IO_ERROR)
return retval;
if (retval == ITEM_FOUND) {
RFALSE(!ih_item_len
(item_head
(PATH_PLAST_BUFFER(search_path),
PATH_LAST_POSITION(search_path))),
"PAP-5165: item length equals zero");
pos_in_item(search_path) = 0;
return POSITION_FOUND;
}
RFALSE(!PATH_LAST_POSITION(search_path),
"PAP-5170: position equals zero");
p_le_ih =
item_head(PATH_PLAST_BUFFER(search_path),
--PATH_LAST_POSITION(search_path));
blk_size = sb->s_blocksize;
if (comp_short_keys(&p_le_ih->ih_key, p_cpu_key))
return FILE_NOT_FOUND;
item_offset = le_ih_k_offset(p_le_ih);
offset = cpu_key_k_offset(p_cpu_key);
if (item_offset <= offset &&
item_offset + op_bytes_number(p_le_ih, blk_size) > offset) {
pos_in_item(search_path) = offset - item_offset;
if (is_indirect_le_ih(p_le_ih)) {
pos_in_item(search_path) /= blk_size;
}
return POSITION_FOUND;
}
if (is_indirect_le_ih(p_le_ih))
pos_in_item(search_path) =
ih_item_len(p_le_ih) / UNFM_P_SIZE;
else
pos_in_item(search_path) = ih_item_len(p_le_ih);
return POSITION_NOT_FOUND;
}
int comp_items(const struct item_head *stored_ih, const struct treepath *path)
{
struct buffer_head *bh = PATH_PLAST_BUFFER(path);
struct item_head *ih;
if (!B_IS_IN_TREE(bh))
return 1;
if (PATH_LAST_POSITION(path) >= B_NR_ITEMS(bh))
return 1;
ih = tp_item_head(path);
return memcmp(stored_ih, ih, IH_SIZE);
}
static inline int prepare_for_direct_item(struct treepath *path,
struct item_head *le_ih,
struct inode *inode,
loff_t new_file_length, int *cut_size)
{
loff_t round_len;
if (new_file_length == max_reiserfs_offset(inode)) {
*cut_size = -(IH_SIZE + ih_item_len(le_ih));
return M_DELETE;
}
if (get_inode_item_key_version(inode) == KEY_FORMAT_3_6) {
round_len = ROUND_UP(new_file_length);
if (round_len < le_ih_k_offset(le_ih)) {
*cut_size = -(IH_SIZE + ih_item_len(le_ih));
return M_DELETE;
}
pos_in_item(path) = round_len - (le_ih_k_offset(le_ih) - 1);
*cut_size = -(ih_item_len(le_ih) - pos_in_item(path));
return M_CUT;
}
if (new_file_length < le_ih_k_offset(le_ih)) {
*cut_size = -(IH_SIZE + ih_item_len(le_ih));
return M_DELETE;
}
*cut_size = -(ih_item_len(le_ih) -
(pos_in_item(path) =
new_file_length + 1 - le_ih_k_offset(le_ih)));
return M_CUT;
}
static inline int prepare_for_direntry_item(struct treepath *path,
struct item_head *le_ih,
struct inode *inode,
loff_t new_file_length,
int *cut_size)
{
if (le_ih_k_offset(le_ih) == DOT_OFFSET &&
new_file_length == max_reiserfs_offset(inode)) {
RFALSE(ih_entry_count(le_ih) != 2,
"PAP-5220: incorrect empty directory item (%h)", le_ih);
*cut_size = -(IH_SIZE + ih_item_len(le_ih));
return M_DELETE;
}
if (ih_entry_count(le_ih) == 1) {
*cut_size = -(IH_SIZE + ih_item_len(le_ih));
return M_DELETE;
}
*cut_size =
-(DEH_SIZE +
entry_length(get_last_bh(path), le_ih, pos_in_item(path)));
return M_CUT;
}
static char prepare_for_delete_or_cut(struct reiserfs_transaction_handle *th,
struct inode *inode,
struct treepath *path,
const struct cpu_key *item_key,
int *removed,
int *cut_size,
unsigned long long new_file_length
)
{
struct super_block *sb = inode->i_sb;
struct item_head *p_le_ih = tp_item_head(path);
struct buffer_head *bh = PATH_PLAST_BUFFER(path);
BUG_ON(!th->t_trans_id);
if (is_statdata_le_ih(p_le_ih)) {
RFALSE(new_file_length != max_reiserfs_offset(inode),
"PAP-5210: mode must be M_DELETE");
*cut_size = -(IH_SIZE + ih_item_len(p_le_ih));
return M_DELETE;
}
if (is_direntry_le_ih(p_le_ih))
return prepare_for_direntry_item(path, p_le_ih, inode,
new_file_length,
cut_size);
if (is_direct_le_ih(p_le_ih))
return prepare_for_direct_item(path, p_le_ih, inode,
new_file_length, cut_size);
{
int blk_size = sb->s_blocksize;
struct item_head s_ih;
int need_re_search;
int delete = 0;
int result = M_CUT;
int pos = 0;
if ( new_file_length == max_reiserfs_offset (inode) ) {
new_file_length = 0;
delete = 1;
}
do {
need_re_search = 0;
*cut_size = 0;
bh = PATH_PLAST_BUFFER(path);
copy_item_head(&s_ih, tp_item_head(path));
pos = I_UNFM_NUM(&s_ih);
while (le_ih_k_offset (&s_ih) + (pos - 1) * blk_size > new_file_length) {
__le32 *unfm;
__u32 block;
if (!delete && (*cut_size) != 0 &&
reiserfs_transaction_free_space(th) < JOURNAL_FOR_FREE_BLOCK_AND_UPDATE_SD)
break;
unfm = (__le32 *)ih_item_body(bh, &s_ih) + pos - 1;
block = get_block_num(unfm, 0);
if (block != 0) {
reiserfs_prepare_for_journal(sb, bh, 1);
put_block_num(unfm, 0, 0);
journal_mark_dirty(th, bh);
reiserfs_free_block(th, inode, block, 1);
}
reiserfs_cond_resched(sb);
if (item_moved (&s_ih, path)) {
need_re_search = 1;
break;
}
pos --;
(*removed)++;
(*cut_size) -= UNFM_P_SIZE;
if (pos == 0) {
(*cut_size) -= IH_SIZE;
result = M_DELETE;
break;
}
}
reiserfs_restore_prepared_buffer(sb, bh);
} while (need_re_search &&
search_for_position_by_key(sb, item_key, path) == POSITION_FOUND);
pos_in_item(path) = pos * UNFM_P_SIZE;
if (*cut_size == 0) {
result = M_CONVERT;
}
return result;
}
}
static int calc_deleted_bytes_number(struct tree_balance *tb, char mode)
{
int del_size;
struct item_head *p_le_ih = tp_item_head(tb->tb_path);
if (is_statdata_le_ih(p_le_ih))
return 0;
del_size =
(mode ==
M_DELETE) ? ih_item_len(p_le_ih) : -tb->insert_size[0];
if (is_direntry_le_ih(p_le_ih)) {
return del_size;
}
if (is_indirect_le_ih(p_le_ih))
del_size = (del_size / UNFM_P_SIZE) *
(PATH_PLAST_BUFFER(tb->tb_path)->b_size);
return del_size;
}
static void init_tb_struct(struct reiserfs_transaction_handle *th,
struct tree_balance *tb,
struct super_block *sb,
struct treepath *path, int size)
{
BUG_ON(!th->t_trans_id);
memset(tb, '\0', sizeof(struct tree_balance));
tb->transaction_handle = th;
tb->tb_sb = sb;
tb->tb_path = path;
PATH_OFFSET_PBUFFER(path, ILLEGAL_PATH_ELEMENT_OFFSET) = NULL;
PATH_OFFSET_POSITION(path, ILLEGAL_PATH_ELEMENT_OFFSET) = 0;
tb->insert_size[0] = size;
}
void padd_item(char *item, int total_length, int length)
{
int i;
for (i = total_length; i > length;)
item[--i] = 0;
}
char key2type(struct reiserfs_key *ih)
{
if (is_direntry_le_key(2, ih))
return 'd';
if (is_direct_le_key(2, ih))
return 'D';
if (is_indirect_le_key(2, ih))
return 'i';
if (is_statdata_le_key(2, ih))
return 's';
return 'u';
}
char head2type(struct item_head *ih)
{
if (is_direntry_le_ih(ih))
return 'd';
if (is_direct_le_ih(ih))
return 'D';
if (is_indirect_le_ih(ih))
return 'i';
if (is_statdata_le_ih(ih))
return 's';
return 'u';
}
int reiserfs_delete_item(struct reiserfs_transaction_handle *th,
struct treepath *path, const struct cpu_key *item_key,
struct inode *inode, struct buffer_head *un_bh)
{
struct super_block *sb = inode->i_sb;
struct tree_balance s_del_balance;
struct item_head s_ih;
struct item_head *q_ih;
int quota_cut_bytes;
int ret_value, del_size, removed;
int depth;
#ifdef CONFIG_REISERFS_CHECK
char mode;
int iter = 0;
#endif
BUG_ON(!th->t_trans_id);
init_tb_struct(th, &s_del_balance, sb, path,
0 );
while (1) {
removed = 0;
#ifdef CONFIG_REISERFS_CHECK
iter++;
mode =
#endif
prepare_for_delete_or_cut(th, inode, path,
item_key, &removed,
&del_size,
max_reiserfs_offset(inode));
RFALSE(mode != M_DELETE, "PAP-5320: mode must be M_DELETE");
copy_item_head(&s_ih, tp_item_head(path));
s_del_balance.insert_size[0] = del_size;
ret_value = fix_nodes(M_DELETE, &s_del_balance, NULL, NULL);
if (ret_value != REPEAT_SEARCH)
break;
PROC_INFO_INC(sb, delete_item_restarted);
ret_value =
search_for_position_by_key(sb, item_key, path);
if (ret_value == IO_ERROR)
break;
if (ret_value == FILE_NOT_FOUND) {
reiserfs_warning(sb, "vs-5340",
"no items of the file %K found",
item_key);
break;
}
}
if (ret_value != CARRY_ON) {
unfix_nodes(&s_del_balance);
return 0;
}
ret_value = calc_deleted_bytes_number(&s_del_balance, M_DELETE);
q_ih = tp_item_head(path);
quota_cut_bytes = ih_item_len(q_ih);
if (!S_ISLNK(inode->i_mode) && is_direct_le_ih(q_ih)) {
if ((le_ih_k_offset(q_ih) & (sb->s_blocksize - 1)) == 1) {
quota_cut_bytes = sb->s_blocksize + UNFM_P_SIZE;
} else {
quota_cut_bytes = 0;
}
}
if (un_bh) {
int off;
char *data;
data = kmap_atomic(un_bh->b_page);
off = ((le_ih_k_offset(&s_ih) - 1) & (PAGE_SIZE - 1));
memcpy(data + off,
ih_item_body(PATH_PLAST_BUFFER(path), &s_ih),
ret_value);
kunmap_atomic(data);
}
do_balance(&s_del_balance, NULL, NULL, M_DELETE);
#ifdef REISERQUOTA_DEBUG
reiserfs_debug(sb, REISERFS_DEBUG_CODE,
"reiserquota delete_item(): freeing %u, id=%u type=%c",
quota_cut_bytes, inode->i_uid, head2type(&s_ih));
#endif
depth = reiserfs_write_unlock_nested(inode->i_sb);
dquot_free_space_nodirty(inode, quota_cut_bytes);
reiserfs_write_lock_nested(inode->i_sb, depth);
return ret_value;
}
void reiserfs_delete_solid_item(struct reiserfs_transaction_handle *th,
struct inode *inode, struct reiserfs_key *key)
{
struct super_block *sb = th->t_super;
struct tree_balance tb;
INITIALIZE_PATH(path);
int item_len = 0;
int tb_init = 0;
struct cpu_key cpu_key;
int retval;
int quota_cut_bytes = 0;
BUG_ON(!th->t_trans_id);
le_key2cpu_key(&cpu_key, key);
while (1) {
retval = search_item(th->t_super, &cpu_key, &path);
if (retval == IO_ERROR) {
reiserfs_error(th->t_super, "vs-5350",
"i/o failure occurred trying "
"to delete %K", &cpu_key);
break;
}
if (retval != ITEM_FOUND) {
pathrelse(&path);
if (!
((unsigned long long)
GET_HASH_VALUE(le_key_k_offset
(le_key_version(key), key)) == 0
&& (unsigned long long)
GET_GENERATION_NUMBER(le_key_k_offset
(le_key_version(key),
key)) == 1))
reiserfs_warning(th->t_super, "vs-5355",
"%k not found", key);
break;
}
if (!tb_init) {
tb_init = 1;
item_len = ih_item_len(tp_item_head(&path));
init_tb_struct(th, &tb, th->t_super, &path,
-(IH_SIZE + item_len));
}
quota_cut_bytes = ih_item_len(tp_item_head(&path));
retval = fix_nodes(M_DELETE, &tb, NULL, NULL);
if (retval == REPEAT_SEARCH) {
PROC_INFO_INC(th->t_super, delete_solid_item_restarted);
continue;
}
if (retval == CARRY_ON) {
do_balance(&tb, NULL, NULL, M_DELETE);
if (inode) {
int depth;
#ifdef REISERQUOTA_DEBUG
reiserfs_debug(th->t_super, REISERFS_DEBUG_CODE,
"reiserquota delete_solid_item(): freeing %u id=%u type=%c",
quota_cut_bytes, inode->i_uid,
key2type(key));
#endif
depth = reiserfs_write_unlock_nested(sb);
dquot_free_space_nodirty(inode,
quota_cut_bytes);
reiserfs_write_lock_nested(sb, depth);
}
break;
}
reiserfs_warning(th->t_super, "vs-5360",
"could not delete %K due to fix_nodes failure",
&cpu_key);
unfix_nodes(&tb);
break;
}
reiserfs_check_path(&path);
}
int reiserfs_delete_object(struct reiserfs_transaction_handle *th,
struct inode *inode)
{
int err;
inode->i_size = 0;
BUG_ON(!th->t_trans_id);
err =
reiserfs_do_truncate(th, inode, NULL, 0 );
if (err)
return err;
#if defined( USE_INODE_GENERATION_COUNTER )
if (!old_format_only(th->t_super)) {
__le32 *inode_generation;
inode_generation =
&REISERFS_SB(th->t_super)->s_rs->s_inode_generation;
le32_add_cpu(inode_generation, 1);
}
#endif
reiserfs_delete_solid_item(th, inode, INODE_PKEY(inode));
return err;
}
static void unmap_buffers(struct page *page, loff_t pos)
{
struct buffer_head *bh;
struct buffer_head *head;
struct buffer_head *next;
unsigned long tail_index;
unsigned long cur_index;
if (page) {
if (page_has_buffers(page)) {
tail_index = pos & (PAGE_SIZE - 1);
cur_index = 0;
head = page_buffers(page);
bh = head;
do {
next = bh->b_this_page;
cur_index += bh->b_size;
if (cur_index > tail_index) {
reiserfs_unmap_buffer(bh);
}
bh = next;
} while (bh != head);
}
}
}
static int maybe_indirect_to_direct(struct reiserfs_transaction_handle *th,
struct inode *inode,
struct page *page,
struct treepath *path,
const struct cpu_key *item_key,
loff_t new_file_size, char *mode)
{
struct super_block *sb = inode->i_sb;
int block_size = sb->s_blocksize;
int cut_bytes;
BUG_ON(!th->t_trans_id);
BUG_ON(new_file_size != inode->i_size);
if (atomic_read(&inode->i_count) > 1 ||
!tail_has_to_be_packed(inode) ||
!page || (REISERFS_I(inode)->i_flags & i_nopack_mask)) {
*mode = M_SKIP_BALANCING;
cut_bytes =
block_size - (new_file_size & (block_size - 1));
pathrelse(path);
return cut_bytes;
}
return indirect2direct(th, inode, page, path, item_key,
new_file_size, mode);
}
static void indirect_to_direct_roll_back(struct reiserfs_transaction_handle *th,
struct inode *inode, struct treepath *path)
{
struct cpu_key tail_key;
int tail_len;
int removed;
BUG_ON(!th->t_trans_id);
make_cpu_key(&tail_key, inode, inode->i_size + 1, TYPE_DIRECT, 4);
tail_key.key_length = 4;
tail_len =
(cpu_key_k_offset(&tail_key) & (inode->i_sb->s_blocksize - 1)) - 1;
while (tail_len) {
if (search_for_position_by_key(inode->i_sb, &tail_key, path) ==
POSITION_NOT_FOUND)
reiserfs_panic(inode->i_sb, "vs-5615",
"found invalid item");
RFALSE(path->pos_in_item !=
ih_item_len(tp_item_head(path)) - 1,
"vs-5616: appended bytes found");
PATH_LAST_POSITION(path)--;
removed =
reiserfs_delete_item(th, path, &tail_key, inode,
NULL );
RFALSE(removed <= 0
|| removed > tail_len,
"vs-5617: there was tail %d bytes, removed item length %d bytes",
tail_len, removed);
tail_len -= removed;
set_cpu_key_k_offset(&tail_key,
cpu_key_k_offset(&tail_key) - removed);
}
reiserfs_warning(inode->i_sb, "reiserfs-5091", "indirect_to_direct "
"conversion has been rolled back due to "
"lack of disk space");
mark_inode_dirty(inode);
}
int reiserfs_cut_from_item(struct reiserfs_transaction_handle *th,
struct treepath *path,
struct cpu_key *item_key,
struct inode *inode,
struct page *page, loff_t new_file_size)
{
struct super_block *sb = inode->i_sb;
struct tree_balance s_cut_balance;
struct item_head *p_le_ih;
int cut_size = 0;
int ret_value = CARRY_ON;
int removed = 0;
int is_inode_locked = 0;
char mode;
int retval2 = -1;
int quota_cut_bytes;
loff_t tail_pos = 0;
int depth;
BUG_ON(!th->t_trans_id);
init_tb_struct(th, &s_cut_balance, inode->i_sb, path,
cut_size);
while (1) {
mode =
prepare_for_delete_or_cut(th, inode, path,
item_key, &removed,
&cut_size, new_file_size);
if (mode == M_CONVERT) {
RFALSE(ret_value != CARRY_ON,
"PAP-5570: can not convert twice");
ret_value =
maybe_indirect_to_direct(th, inode, page,
path, item_key,
new_file_size, &mode);
if (mode == M_SKIP_BALANCING)
return ret_value;
is_inode_locked = 1;
retval2 = ret_value;
set_cpu_key_k_type(item_key, TYPE_INDIRECT);
item_key->key_length = 4;
new_file_size -=
(new_file_size & (sb->s_blocksize - 1));
tail_pos = new_file_size;
set_cpu_key_k_offset(item_key, new_file_size + 1);
if (search_for_position_by_key
(sb, item_key,
path) == POSITION_NOT_FOUND) {
print_block(PATH_PLAST_BUFFER(path), 3,
PATH_LAST_POSITION(path) - 1,
PATH_LAST_POSITION(path) + 1);
reiserfs_panic(sb, "PAP-5580", "item to "
"convert does not exist (%K)",
item_key);
}
continue;
}
if (cut_size == 0) {
pathrelse(path);
return 0;
}
s_cut_balance.insert_size[0] = cut_size;
ret_value = fix_nodes(mode, &s_cut_balance, NULL, NULL);
if (ret_value != REPEAT_SEARCH)
break;
PROC_INFO_INC(sb, cut_from_item_restarted);
ret_value =
search_for_position_by_key(sb, item_key, path);
if (ret_value == POSITION_FOUND)
continue;
reiserfs_warning(sb, "PAP-5610", "item %K not found",
item_key);
unfix_nodes(&s_cut_balance);
return (ret_value == IO_ERROR) ? -EIO : -ENOENT;
}
if (ret_value != CARRY_ON) {
if (is_inode_locked) {
indirect_to_direct_roll_back(th, inode, path);
}
if (ret_value == NO_DISK_SPACE)
reiserfs_warning(sb, "reiserfs-5092",
"NO_DISK_SPACE");
unfix_nodes(&s_cut_balance);
return -EIO;
}
RFALSE(mode == M_PASTE || mode == M_INSERT, "invalid mode");
quota_cut_bytes =
(mode ==
M_DELETE) ? ih_item_len(tp_item_head(path)) : -s_cut_balance.
insert_size[0];
if (retval2 == -1)
ret_value = calc_deleted_bytes_number(&s_cut_balance, mode);
else
ret_value = retval2;
p_le_ih = tp_item_head(s_cut_balance.tb_path);
if (!S_ISLNK(inode->i_mode) && is_direct_le_ih(p_le_ih)) {
if (mode == M_DELETE &&
(le_ih_k_offset(p_le_ih) & (sb->s_blocksize - 1)) ==
1) {
REISERFS_I(inode)->i_first_direct_byte = U32_MAX;
quota_cut_bytes = sb->s_blocksize + UNFM_P_SIZE;
} else {
quota_cut_bytes = 0;
}
}
#ifdef CONFIG_REISERFS_CHECK
if (is_inode_locked) {
struct item_head *le_ih =
tp_item_head(s_cut_balance.tb_path);
if (!is_indirect_le_ih(le_ih))
reiserfs_panic(sb, "vs-5652",
"item must be indirect %h", le_ih);
if (mode == M_DELETE && ih_item_len(le_ih) != UNFM_P_SIZE)
reiserfs_panic(sb, "vs-5653", "completing "
"indirect2direct conversion indirect "
"item %h being deleted must be of "
"4 byte long", le_ih);
if (mode == M_CUT
&& s_cut_balance.insert_size[0] != -UNFM_P_SIZE) {
reiserfs_panic(sb, "vs-5654", "can not complete "
"indirect2direct conversion of %h "
"(CUT, insert_size==%d)",
le_ih, s_cut_balance.insert_size[0]);
}
}
#endif
do_balance(&s_cut_balance, NULL, NULL, mode);
if (is_inode_locked) {
unmap_buffers(page, tail_pos);
REISERFS_I(inode)->i_flags &= ~i_pack_on_close_mask;
}
#ifdef REISERQUOTA_DEBUG
reiserfs_debug(inode->i_sb, REISERFS_DEBUG_CODE,
"reiserquota cut_from_item(): freeing %u id=%u type=%c",
quota_cut_bytes, inode->i_uid, '?');
#endif
depth = reiserfs_write_unlock_nested(sb);
dquot_free_space_nodirty(inode, quota_cut_bytes);
reiserfs_write_lock_nested(sb, depth);
return ret_value;
}
static void truncate_directory(struct reiserfs_transaction_handle *th,
struct inode *inode)
{
BUG_ON(!th->t_trans_id);
if (inode->i_nlink)
reiserfs_error(inode->i_sb, "vs-5655", "link count != 0");
set_le_key_k_offset(KEY_FORMAT_3_5, INODE_PKEY(inode), DOT_OFFSET);
set_le_key_k_type(KEY_FORMAT_3_5, INODE_PKEY(inode), TYPE_DIRENTRY);
reiserfs_delete_solid_item(th, inode, INODE_PKEY(inode));
reiserfs_update_sd(th, inode);
set_le_key_k_offset(KEY_FORMAT_3_5, INODE_PKEY(inode), SD_OFFSET);
set_le_key_k_type(KEY_FORMAT_3_5, INODE_PKEY(inode), TYPE_STAT_DATA);
}
int reiserfs_do_truncate(struct reiserfs_transaction_handle *th,
struct inode *inode,
struct page *page,
int update_timestamps
)
{
INITIALIZE_PATH(s_search_path);
struct item_head *p_le_ih;
struct cpu_key s_item_key;
loff_t file_size,
new_file_size;
int deleted;
int retval;
int err = 0;
BUG_ON(!th->t_trans_id);
if (!
(S_ISREG(inode->i_mode) || S_ISDIR(inode->i_mode)
|| S_ISLNK(inode->i_mode)))
return 0;
if (S_ISDIR(inode->i_mode)) {
truncate_directory(th, inode);
return 0;
}
new_file_size = inode->i_size;
make_cpu_key(&s_item_key, inode, max_reiserfs_offset(inode),
TYPE_DIRECT, 3);
retval =
search_for_position_by_key(inode->i_sb, &s_item_key,
&s_search_path);
if (retval == IO_ERROR) {
reiserfs_error(inode->i_sb, "vs-5657",
"i/o failure occurred trying to truncate %K",
&s_item_key);
err = -EIO;
goto out;
}
if (retval == POSITION_FOUND || retval == FILE_NOT_FOUND) {
reiserfs_error(inode->i_sb, "PAP-5660",
"wrong result %d of search for %K", retval,
&s_item_key);
err = -EIO;
goto out;
}
s_search_path.pos_in_item--;
p_le_ih = tp_item_head(&s_search_path);
if (is_statdata_le_ih(p_le_ih))
file_size = 0;
else {
loff_t offset = le_ih_k_offset(p_le_ih);
int bytes =
op_bytes_number(p_le_ih, inode->i_sb->s_blocksize);
file_size = offset + bytes - 1;
}
if (new_file_size == 0)
s_search_path.reada = PATH_READA | PATH_READA_BACK;
if (file_size == 0 || file_size < new_file_size) {
goto update_and_out;
}
set_cpu_key_k_offset(&s_item_key, file_size);
do {
deleted =
reiserfs_cut_from_item(th, &s_search_path, &s_item_key,
inode, page, new_file_size);
if (deleted < 0) {
reiserfs_warning(inode->i_sb, "vs-5665",
"reiserfs_cut_from_item failed");
reiserfs_check_path(&s_search_path);
return 0;
}
RFALSE(deleted > file_size,
"PAP-5670: reiserfs_cut_from_item: too many bytes deleted: deleted %d, file_size %lu, item_key %K",
deleted, file_size, &s_item_key);
file_size -= deleted;
set_cpu_key_k_offset(&s_item_key, file_size);
if (journal_transaction_should_end(th, 0) ||
reiserfs_transaction_free_space(th) <= JOURNAL_FOR_FREE_BLOCK_AND_UPDATE_SD) {
pathrelse(&s_search_path);
if (update_timestamps) {
inode->i_mtime = CURRENT_TIME_SEC;
inode->i_ctime = CURRENT_TIME_SEC;
}
reiserfs_update_sd(th, inode);
err = journal_end(th);
if (err)
goto out;
err = journal_begin(th, inode->i_sb,
JOURNAL_FOR_FREE_BLOCK_AND_UPDATE_SD + JOURNAL_PER_BALANCE_CNT * 4) ;
if (err)
goto out;
reiserfs_update_inode_transaction(inode);
}
} while (file_size > ROUND_UP(new_file_size) &&
search_for_position_by_key(inode->i_sb, &s_item_key,
&s_search_path) == POSITION_FOUND);
RFALSE(file_size > ROUND_UP(new_file_size),
"PAP-5680: truncate did not finish: new_file_size %lld, current %lld, oid %d",
new_file_size, file_size, s_item_key.on_disk_key.k_objectid);
update_and_out:
if (update_timestamps) {
inode->i_mtime = CURRENT_TIME_SEC;
inode->i_ctime = CURRENT_TIME_SEC;
}
reiserfs_update_sd(th, inode);
out:
pathrelse(&s_search_path);
return err;
}
static void check_research_for_paste(struct treepath *path,
const struct cpu_key *key)
{
struct item_head *found_ih = tp_item_head(path);
if (is_direct_le_ih(found_ih)) {
if (le_ih_k_offset(found_ih) +
op_bytes_number(found_ih,
get_last_bh(path)->b_size) !=
cpu_key_k_offset(key)
|| op_bytes_number(found_ih,
get_last_bh(path)->b_size) !=
pos_in_item(path))
reiserfs_panic(NULL, "PAP-5720", "found direct item "
"%h or position (%d) does not match "
"to key %K", found_ih,
pos_in_item(path), key);
}
if (is_indirect_le_ih(found_ih)) {
if (le_ih_k_offset(found_ih) +
op_bytes_number(found_ih,
get_last_bh(path)->b_size) !=
cpu_key_k_offset(key)
|| I_UNFM_NUM(found_ih) != pos_in_item(path)
|| get_ih_free_space(found_ih) != 0)
reiserfs_panic(NULL, "PAP-5730", "found indirect "
"item (%h) or position (%d) does not "
"match to key (%K)",
found_ih, pos_in_item(path), key);
}
}
int reiserfs_paste_into_item(struct reiserfs_transaction_handle *th,
struct treepath *search_path,
const struct cpu_key *key,
struct inode *inode,
const char *body,
int pasted_size)
{
struct super_block *sb = inode->i_sb;
struct tree_balance s_paste_balance;
int retval;
int fs_gen;
int depth;
BUG_ON(!th->t_trans_id);
fs_gen = get_generation(inode->i_sb);
#ifdef REISERQUOTA_DEBUG
reiserfs_debug(inode->i_sb, REISERFS_DEBUG_CODE,
"reiserquota paste_into_item(): allocating %u id=%u type=%c",
pasted_size, inode->i_uid,
key2type(&key->on_disk_key));
#endif
depth = reiserfs_write_unlock_nested(sb);
retval = dquot_alloc_space_nodirty(inode, pasted_size);
reiserfs_write_lock_nested(sb, depth);
if (retval) {
pathrelse(search_path);
return retval;
}
init_tb_struct(th, &s_paste_balance, th->t_super, search_path,
pasted_size);
#ifdef DISPLACE_NEW_PACKING_LOCALITIES
s_paste_balance.key = key->on_disk_key;
#endif
if (fs_changed(fs_gen, inode->i_sb)) {
goto search_again;
}
while ((retval =
fix_nodes(M_PASTE, &s_paste_balance, NULL,
body)) == REPEAT_SEARCH) {
search_again:
PROC_INFO_INC(th->t_super, paste_into_item_restarted);
retval =
search_for_position_by_key(th->t_super, key,
search_path);
if (retval == IO_ERROR) {
retval = -EIO;
goto error_out;
}
if (retval == POSITION_FOUND) {
reiserfs_warning(inode->i_sb, "PAP-5710",
"entry or pasted byte (%K) exists",
key);
retval = -EEXIST;
goto error_out;
}
#ifdef CONFIG_REISERFS_CHECK
check_research_for_paste(search_path, key);
#endif
}
if (retval == CARRY_ON) {
do_balance(&s_paste_balance, NULL , body, M_PASTE);
return 0;
}
retval = (retval == NO_DISK_SPACE) ? -ENOSPC : -EIO;
error_out:
unfix_nodes(&s_paste_balance);
#ifdef REISERQUOTA_DEBUG
reiserfs_debug(inode->i_sb, REISERFS_DEBUG_CODE,
"reiserquota paste_into_item(): freeing %u id=%u type=%c",
pasted_size, inode->i_uid,
key2type(&key->on_disk_key));
#endif
depth = reiserfs_write_unlock_nested(sb);
dquot_free_space_nodirty(inode, pasted_size);
reiserfs_write_lock_nested(sb, depth);
return retval;
}
int reiserfs_insert_item(struct reiserfs_transaction_handle *th,
struct treepath *path, const struct cpu_key *key,
struct item_head *ih, struct inode *inode,
const char *body)
{
struct tree_balance s_ins_balance;
int retval;
int fs_gen = 0;
int quota_bytes = 0;
BUG_ON(!th->t_trans_id);
if (inode) {
int depth;
fs_gen = get_generation(inode->i_sb);
quota_bytes = ih_item_len(ih);
if (!S_ISLNK(inode->i_mode) && is_direct_le_ih(ih))
quota_bytes = inode->i_sb->s_blocksize + UNFM_P_SIZE;
#ifdef REISERQUOTA_DEBUG
reiserfs_debug(inode->i_sb, REISERFS_DEBUG_CODE,
"reiserquota insert_item(): allocating %u id=%u type=%c",
quota_bytes, inode->i_uid, head2type(ih));
#endif
depth = reiserfs_write_unlock_nested(inode->i_sb);
retval = dquot_alloc_space_nodirty(inode, quota_bytes);
reiserfs_write_lock_nested(inode->i_sb, depth);
if (retval) {
pathrelse(path);
return retval;
}
}
init_tb_struct(th, &s_ins_balance, th->t_super, path,
IH_SIZE + ih_item_len(ih));
#ifdef DISPLACE_NEW_PACKING_LOCALITIES
s_ins_balance.key = key->on_disk_key;
#endif
if (inode && fs_changed(fs_gen, inode->i_sb)) {
goto search_again;
}
while ((retval =
fix_nodes(M_INSERT, &s_ins_balance, ih,
body)) == REPEAT_SEARCH) {
search_again:
PROC_INFO_INC(th->t_super, insert_item_restarted);
retval = search_item(th->t_super, key, path);
if (retval == IO_ERROR) {
retval = -EIO;
goto error_out;
}
if (retval == ITEM_FOUND) {
reiserfs_warning(th->t_super, "PAP-5760",
"key %K already exists in the tree",
key);
retval = -EEXIST;
goto error_out;
}
}
if (retval == CARRY_ON) {
do_balance(&s_ins_balance, ih, body, M_INSERT);
return 0;
}
retval = (retval == NO_DISK_SPACE) ? -ENOSPC : -EIO;
error_out:
unfix_nodes(&s_ins_balance);
#ifdef REISERQUOTA_DEBUG
reiserfs_debug(th->t_super, REISERFS_DEBUG_CODE,
"reiserquota insert_item(): freeing %u id=%u type=%c",
quota_bytes, inode->i_uid, head2type(ih));
#endif
if (inode) {
int depth = reiserfs_write_unlock_nested(inode->i_sb);
dquot_free_space_nodirty(inode, quota_bytes);
reiserfs_write_lock_nested(inode->i_sb, depth);
}
return retval;
}
