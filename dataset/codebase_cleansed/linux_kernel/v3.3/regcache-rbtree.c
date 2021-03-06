static inline void regcache_rbtree_get_base_top_reg(
struct regcache_rbtree_node *rbnode,
unsigned int *base, unsigned int *top)
{
*base = rbnode->base_reg;
*top = rbnode->base_reg + rbnode->blklen - 1;
}
static unsigned int regcache_rbtree_get_register(
struct regcache_rbtree_node *rbnode, unsigned int idx,
unsigned int word_size)
{
return regcache_get_val(rbnode->block, idx, word_size);
}
static void regcache_rbtree_set_register(struct regcache_rbtree_node *rbnode,
unsigned int idx, unsigned int val,
unsigned int word_size)
{
regcache_set_val(rbnode->block, idx, val, word_size);
}
static struct regcache_rbtree_node *regcache_rbtree_lookup(struct regmap *map,
unsigned int reg)
{
struct regcache_rbtree_ctx *rbtree_ctx = map->cache;
struct rb_node *node;
struct regcache_rbtree_node *rbnode;
unsigned int base_reg, top_reg;
rbnode = rbtree_ctx->cached_rbnode;
if (rbnode) {
regcache_rbtree_get_base_top_reg(rbnode, &base_reg, &top_reg);
if (reg >= base_reg && reg <= top_reg)
return rbnode;
}
node = rbtree_ctx->root.rb_node;
while (node) {
rbnode = container_of(node, struct regcache_rbtree_node, node);
regcache_rbtree_get_base_top_reg(rbnode, &base_reg, &top_reg);
if (reg >= base_reg && reg <= top_reg) {
rbtree_ctx->cached_rbnode = rbnode;
return rbnode;
} else if (reg > top_reg) {
node = node->rb_right;
} else if (reg < base_reg) {
node = node->rb_left;
}
}
return NULL;
}
static int regcache_rbtree_insert(struct rb_root *root,
struct regcache_rbtree_node *rbnode)
{
struct rb_node **new, *parent;
struct regcache_rbtree_node *rbnode_tmp;
unsigned int base_reg_tmp, top_reg_tmp;
unsigned int base_reg;
parent = NULL;
new = &root->rb_node;
while (*new) {
rbnode_tmp = container_of(*new, struct regcache_rbtree_node,
node);
regcache_rbtree_get_base_top_reg(rbnode_tmp, &base_reg_tmp,
&top_reg_tmp);
base_reg = rbnode->base_reg;
parent = *new;
if (base_reg >= base_reg_tmp &&
base_reg <= top_reg_tmp)
return 0;
else if (base_reg > top_reg_tmp)
new = &((*new)->rb_right);
else if (base_reg < base_reg_tmp)
new = &((*new)->rb_left);
}
rb_link_node(&rbnode->node, parent, new);
rb_insert_color(&rbnode->node, root);
return 1;
}
static int rbtree_show(struct seq_file *s, void *ignored)
{
struct regmap *map = s->private;
struct regcache_rbtree_ctx *rbtree_ctx = map->cache;
struct regcache_rbtree_node *n;
struct rb_node *node;
unsigned int base, top;
int nodes = 0;
int registers = 0;
mutex_lock(&map->lock);
for (node = rb_first(&rbtree_ctx->root); node != NULL;
node = rb_next(node)) {
n = container_of(node, struct regcache_rbtree_node, node);
regcache_rbtree_get_base_top_reg(n, &base, &top);
seq_printf(s, "%x-%x (%d)\n", base, top, top - base + 1);
nodes++;
registers += top - base + 1;
}
seq_printf(s, "%d nodes, %d registers, average %d registers\n",
nodes, registers, registers / nodes);
mutex_unlock(&map->lock);
return 0;
}
static int rbtree_open(struct inode *inode, struct file *file)
{
return single_open(file, rbtree_show, inode->i_private);
}
static void rbtree_debugfs_init(struct regmap *map)
{
debugfs_create_file("rbtree", 0400, map->debugfs, map, &rbtree_fops);
}
static void rbtree_debugfs_init(struct regmap *map)
{
}
static int regcache_rbtree_init(struct regmap *map)
{
struct regcache_rbtree_ctx *rbtree_ctx;
int i;
int ret;
map->cache = kmalloc(sizeof *rbtree_ctx, GFP_KERNEL);
if (!map->cache)
return -ENOMEM;
rbtree_ctx = map->cache;
rbtree_ctx->root = RB_ROOT;
rbtree_ctx->cached_rbnode = NULL;
for (i = 0; i < map->num_reg_defaults; i++) {
ret = regcache_rbtree_write(map,
map->reg_defaults[i].reg,
map->reg_defaults[i].def);
if (ret)
goto err;
}
rbtree_debugfs_init(map);
return 0;
err:
regcache_rbtree_exit(map);
return ret;
}
static int regcache_rbtree_exit(struct regmap *map)
{
struct rb_node *next;
struct regcache_rbtree_ctx *rbtree_ctx;
struct regcache_rbtree_node *rbtree_node;
rbtree_ctx = map->cache;
if (!rbtree_ctx)
return 0;
next = rb_first(&rbtree_ctx->root);
while (next) {
rbtree_node = rb_entry(next, struct regcache_rbtree_node, node);
next = rb_next(&rbtree_node->node);
rb_erase(&rbtree_node->node, &rbtree_ctx->root);
kfree(rbtree_node->block);
kfree(rbtree_node);
}
kfree(map->cache);
map->cache = NULL;
return 0;
}
static int regcache_rbtree_read(struct regmap *map,
unsigned int reg, unsigned int *value)
{
struct regcache_rbtree_node *rbnode;
unsigned int reg_tmp;
rbnode = regcache_rbtree_lookup(map, reg);
if (rbnode) {
reg_tmp = reg - rbnode->base_reg;
*value = regcache_rbtree_get_register(rbnode, reg_tmp,
map->cache_word_size);
} else {
return -ENOENT;
}
return 0;
}
static int regcache_rbtree_insert_to_block(struct regcache_rbtree_node *rbnode,
unsigned int pos, unsigned int reg,
unsigned int value, unsigned int word_size)
{
u8 *blk;
blk = krealloc(rbnode->block,
(rbnode->blklen + 1) * word_size, GFP_KERNEL);
if (!blk)
return -ENOMEM;
memmove(blk + (pos + 1) * word_size,
blk + pos * word_size,
(rbnode->blklen - pos) * word_size);
rbnode->block = blk;
rbnode->blklen++;
if (!pos)
rbnode->base_reg = reg;
regcache_rbtree_set_register(rbnode, pos, value, word_size);
return 0;
}
static int regcache_rbtree_write(struct regmap *map, unsigned int reg,
unsigned int value)
{
struct regcache_rbtree_ctx *rbtree_ctx;
struct regcache_rbtree_node *rbnode, *rbnode_tmp;
struct rb_node *node;
unsigned int val;
unsigned int reg_tmp;
unsigned int pos;
int i;
int ret;
rbtree_ctx = map->cache;
rbnode = regcache_rbtree_lookup(map, reg);
if (rbnode) {
reg_tmp = reg - rbnode->base_reg;
val = regcache_rbtree_get_register(rbnode, reg_tmp,
map->cache_word_size);
if (val == value)
return 0;
regcache_rbtree_set_register(rbnode, reg_tmp, value,
map->cache_word_size);
} else {
for (node = rb_first(&rbtree_ctx->root); node;
node = rb_next(node)) {
rbnode_tmp = rb_entry(node, struct regcache_rbtree_node, node);
for (i = 0; i < rbnode_tmp->blklen; i++) {
reg_tmp = rbnode_tmp->base_reg + i;
if (abs(reg_tmp - reg) != 1)
continue;
if (reg_tmp + 1 == reg)
pos = i + 1;
else
pos = i;
ret = regcache_rbtree_insert_to_block(rbnode_tmp, pos,
reg, value,
map->cache_word_size);
if (ret)
return ret;
rbtree_ctx->cached_rbnode = rbnode_tmp;
return 0;
}
}
rbnode = kzalloc(sizeof *rbnode, GFP_KERNEL);
if (!rbnode)
return -ENOMEM;
rbnode->blklen = 1;
rbnode->base_reg = reg;
rbnode->block = kmalloc(rbnode->blklen * map->cache_word_size,
GFP_KERNEL);
if (!rbnode->block) {
kfree(rbnode);
return -ENOMEM;
}
regcache_rbtree_set_register(rbnode, 0, value, map->cache_word_size);
regcache_rbtree_insert(&rbtree_ctx->root, rbnode);
rbtree_ctx->cached_rbnode = rbnode;
}
return 0;
}
static int regcache_rbtree_sync(struct regmap *map)
{
struct regcache_rbtree_ctx *rbtree_ctx;
struct rb_node *node;
struct regcache_rbtree_node *rbnode;
unsigned int regtmp;
unsigned int val;
int ret;
int i;
rbtree_ctx = map->cache;
for (node = rb_first(&rbtree_ctx->root); node; node = rb_next(node)) {
rbnode = rb_entry(node, struct regcache_rbtree_node, node);
for (i = 0; i < rbnode->blklen; i++) {
regtmp = rbnode->base_reg + i;
val = regcache_rbtree_get_register(rbnode, i,
map->cache_word_size);
ret = regcache_lookup_reg(map, i);
if (ret > 0 && val == map->reg_defaults[ret].def)
continue;
map->cache_bypass = 1;
ret = _regmap_write(map, regtmp, val);
map->cache_bypass = 0;
if (ret)
return ret;
dev_dbg(map->dev, "Synced register %#x, value %#x\n",
regtmp, val);
}
}
return 0;
}
