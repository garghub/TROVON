static bool snd_soc_set_cache_val(void *base, unsigned int idx,
unsigned int val, unsigned int word_size)
{
switch (word_size) {
case 1: {
u8 *cache = base;
if (cache[idx] == val)
return true;
cache[idx] = val;
break;
}
case 2: {
u16 *cache = base;
if (cache[idx] == val)
return true;
cache[idx] = val;
break;
}
default:
BUG();
}
return false;
}
static unsigned int snd_soc_get_cache_val(const void *base, unsigned int idx,
unsigned int word_size)
{
if (!base)
return -1;
switch (word_size) {
case 1: {
const u8 *cache = base;
return cache[idx];
}
case 2: {
const u16 *cache = base;
return cache[idx];
}
default:
BUG();
}
return -1;
}
static inline void snd_soc_rbtree_get_base_top_reg(
struct snd_soc_rbtree_node *rbnode,
unsigned int *base, unsigned int *top)
{
*base = rbnode->base_reg;
*top = rbnode->base_reg + rbnode->blklen - 1;
}
static unsigned int snd_soc_rbtree_get_register(
struct snd_soc_rbtree_node *rbnode, unsigned int idx)
{
unsigned int val;
switch (rbnode->word_size) {
case 1: {
u8 *p = rbnode->block;
val = p[idx];
return val;
}
case 2: {
u16 *p = rbnode->block;
val = p[idx];
return val;
}
default:
BUG();
break;
}
return -1;
}
static void snd_soc_rbtree_set_register(struct snd_soc_rbtree_node *rbnode,
unsigned int idx, unsigned int val)
{
switch (rbnode->word_size) {
case 1: {
u8 *p = rbnode->block;
p[idx] = val;
break;
}
case 2: {
u16 *p = rbnode->block;
p[idx] = val;
break;
}
default:
BUG();
break;
}
}
static struct snd_soc_rbtree_node *snd_soc_rbtree_lookup(
struct rb_root *root, unsigned int reg)
{
struct rb_node *node;
struct snd_soc_rbtree_node *rbnode;
unsigned int base_reg, top_reg;
node = root->rb_node;
while (node) {
rbnode = container_of(node, struct snd_soc_rbtree_node, node);
snd_soc_rbtree_get_base_top_reg(rbnode, &base_reg, &top_reg);
if (reg >= base_reg && reg <= top_reg)
return rbnode;
else if (reg > top_reg)
node = node->rb_right;
else if (reg < base_reg)
node = node->rb_left;
}
return NULL;
}
static int snd_soc_rbtree_insert(struct rb_root *root,
struct snd_soc_rbtree_node *rbnode)
{
struct rb_node **new, *parent;
struct snd_soc_rbtree_node *rbnode_tmp;
unsigned int base_reg_tmp, top_reg_tmp;
unsigned int base_reg;
parent = NULL;
new = &root->rb_node;
while (*new) {
rbnode_tmp = container_of(*new, struct snd_soc_rbtree_node,
node);
snd_soc_rbtree_get_base_top_reg(rbnode_tmp, &base_reg_tmp,
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
static int snd_soc_rbtree_cache_sync(struct snd_soc_codec *codec)
{
struct snd_soc_rbtree_ctx *rbtree_ctx;
struct rb_node *node;
struct snd_soc_rbtree_node *rbnode;
unsigned int regtmp;
unsigned int val, def;
int ret;
int i;
rbtree_ctx = codec->reg_cache;
for (node = rb_first(&rbtree_ctx->root); node; node = rb_next(node)) {
rbnode = rb_entry(node, struct snd_soc_rbtree_node, node);
for (i = 0; i < rbnode->blklen; ++i) {
regtmp = rbnode->base_reg + i;
val = snd_soc_rbtree_get_register(rbnode, i);
def = snd_soc_get_cache_val(codec->reg_def_copy, i,
rbnode->word_size);
if (val == def)
continue;
WARN_ON(!snd_soc_codec_writable_register(codec, regtmp));
codec->cache_bypass = 1;
ret = snd_soc_write(codec, regtmp, val);
codec->cache_bypass = 0;
if (ret)
return ret;
dev_dbg(codec->dev, "Synced register %#x, value = %#x\n",
regtmp, val);
}
}
return 0;
}
static int snd_soc_rbtree_insert_to_block(struct snd_soc_rbtree_node *rbnode,
unsigned int pos, unsigned int reg,
unsigned int value)
{
u8 *blk;
blk = krealloc(rbnode->block,
(rbnode->blklen + 1) * rbnode->word_size, GFP_KERNEL);
if (!blk)
return -ENOMEM;
memmove(blk + (pos + 1) * rbnode->word_size,
blk + pos * rbnode->word_size,
(rbnode->blklen - pos) * rbnode->word_size);
rbnode->block = blk;
rbnode->blklen++;
if (!pos)
rbnode->base_reg = reg;
snd_soc_rbtree_set_register(rbnode, pos, value);
return 0;
}
static int snd_soc_rbtree_cache_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
struct snd_soc_rbtree_ctx *rbtree_ctx;
struct snd_soc_rbtree_node *rbnode, *rbnode_tmp;
struct rb_node *node;
unsigned int val;
unsigned int reg_tmp;
unsigned int base_reg, top_reg;
unsigned int pos;
int i;
int ret;
rbtree_ctx = codec->reg_cache;
rbnode = rbtree_ctx->cached_rbnode;
if (rbnode) {
snd_soc_rbtree_get_base_top_reg(rbnode, &base_reg, &top_reg);
if (reg >= base_reg && reg <= top_reg) {
reg_tmp = reg - base_reg;
val = snd_soc_rbtree_get_register(rbnode, reg_tmp);
if (val == value)
return 0;
snd_soc_rbtree_set_register(rbnode, reg_tmp, value);
return 0;
}
}
rbnode = snd_soc_rbtree_lookup(&rbtree_ctx->root, reg);
if (rbnode) {
reg_tmp = reg - rbnode->base_reg;
val = snd_soc_rbtree_get_register(rbnode, reg_tmp);
if (val == value)
return 0;
snd_soc_rbtree_set_register(rbnode, reg_tmp, value);
rbtree_ctx->cached_rbnode = rbnode;
} else {
if (!value)
return 0;
for (node = rb_first(&rbtree_ctx->root); node;
node = rb_next(node)) {
rbnode_tmp = rb_entry(node, struct snd_soc_rbtree_node, node);
for (i = 0; i < rbnode_tmp->blklen; ++i) {
reg_tmp = rbnode_tmp->base_reg + i;
if (abs(reg_tmp - reg) != 1)
continue;
if (reg_tmp + 1 == reg)
pos = i + 1;
else
pos = i;
ret = snd_soc_rbtree_insert_to_block(rbnode_tmp, pos,
reg, value);
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
rbnode->word_size = codec->driver->reg_word_size;
rbnode->block = kmalloc(rbnode->blklen * rbnode->word_size,
GFP_KERNEL);
if (!rbnode->block) {
kfree(rbnode);
return -ENOMEM;
}
snd_soc_rbtree_set_register(rbnode, 0, value);
snd_soc_rbtree_insert(&rbtree_ctx->root, rbnode);
rbtree_ctx->cached_rbnode = rbnode;
}
return 0;
}
static int snd_soc_rbtree_cache_read(struct snd_soc_codec *codec,
unsigned int reg, unsigned int *value)
{
struct snd_soc_rbtree_ctx *rbtree_ctx;
struct snd_soc_rbtree_node *rbnode;
unsigned int base_reg, top_reg;
unsigned int reg_tmp;
rbtree_ctx = codec->reg_cache;
rbnode = rbtree_ctx->cached_rbnode;
if (rbnode) {
snd_soc_rbtree_get_base_top_reg(rbnode, &base_reg, &top_reg);
if (reg >= base_reg && reg <= top_reg) {
reg_tmp = reg - base_reg;
*value = snd_soc_rbtree_get_register(rbnode, reg_tmp);
return 0;
}
}
rbnode = snd_soc_rbtree_lookup(&rbtree_ctx->root, reg);
if (rbnode) {
reg_tmp = reg - rbnode->base_reg;
*value = snd_soc_rbtree_get_register(rbnode, reg_tmp);
rbtree_ctx->cached_rbnode = rbnode;
} else {
*value = 0;
}
return 0;
}
static int snd_soc_rbtree_cache_exit(struct snd_soc_codec *codec)
{
struct rb_node *next;
struct snd_soc_rbtree_ctx *rbtree_ctx;
struct snd_soc_rbtree_node *rbtree_node;
rbtree_ctx = codec->reg_cache;
if (!rbtree_ctx)
return 0;
next = rb_first(&rbtree_ctx->root);
while (next) {
rbtree_node = rb_entry(next, struct snd_soc_rbtree_node, node);
next = rb_next(&rbtree_node->node);
rb_erase(&rbtree_node->node, &rbtree_ctx->root);
kfree(rbtree_node->block);
kfree(rbtree_node);
}
kfree(codec->reg_cache);
codec->reg_cache = NULL;
return 0;
}
static int snd_soc_rbtree_cache_init(struct snd_soc_codec *codec)
{
struct snd_soc_rbtree_ctx *rbtree_ctx;
unsigned int word_size;
unsigned int val;
int i;
int ret;
codec->reg_cache = kmalloc(sizeof *rbtree_ctx, GFP_KERNEL);
if (!codec->reg_cache)
return -ENOMEM;
rbtree_ctx = codec->reg_cache;
rbtree_ctx->root = RB_ROOT;
rbtree_ctx->cached_rbnode = NULL;
if (!codec->reg_def_copy)
return 0;
word_size = codec->driver->reg_word_size;
for (i = 0; i < codec->driver->reg_cache_size; ++i) {
val = snd_soc_get_cache_val(codec->reg_def_copy, i,
word_size);
if (!val)
continue;
ret = snd_soc_rbtree_cache_write(codec, i, val);
if (ret)
goto err;
}
return 0;
err:
snd_soc_cache_exit(codec);
return ret;
}
static int snd_soc_lzo_block_count(void)
{
return LZO_BLOCK_NUM;
}
static int snd_soc_lzo_prepare(struct snd_soc_lzo_ctx *lzo_ctx)
{
lzo_ctx->wmem = kmalloc(LZO1X_MEM_COMPRESS, GFP_KERNEL);
if (!lzo_ctx->wmem)
return -ENOMEM;
return 0;
}
static int snd_soc_lzo_compress(struct snd_soc_lzo_ctx *lzo_ctx)
{
size_t compress_size;
int ret;
ret = lzo1x_1_compress(lzo_ctx->src, lzo_ctx->src_len,
lzo_ctx->dst, &compress_size, lzo_ctx->wmem);
if (ret != LZO_E_OK || compress_size > lzo_ctx->dst_len)
return -EINVAL;
lzo_ctx->dst_len = compress_size;
return 0;
}
static int snd_soc_lzo_decompress(struct snd_soc_lzo_ctx *lzo_ctx)
{
size_t dst_len;
int ret;
dst_len = lzo_ctx->dst_len;
ret = lzo1x_decompress_safe(lzo_ctx->src, lzo_ctx->src_len,
lzo_ctx->dst, &dst_len);
if (ret != LZO_E_OK || dst_len != lzo_ctx->dst_len)
return -EINVAL;
return 0;
}
static int snd_soc_lzo_compress_cache_block(struct snd_soc_codec *codec,
struct snd_soc_lzo_ctx *lzo_ctx)
{
int ret;
lzo_ctx->dst_len = lzo1x_worst_compress(PAGE_SIZE);
lzo_ctx->dst = kmalloc(lzo_ctx->dst_len, GFP_KERNEL);
if (!lzo_ctx->dst) {
lzo_ctx->dst_len = 0;
return -ENOMEM;
}
ret = snd_soc_lzo_compress(lzo_ctx);
if (ret < 0)
return ret;
return 0;
}
static int snd_soc_lzo_decompress_cache_block(struct snd_soc_codec *codec,
struct snd_soc_lzo_ctx *lzo_ctx)
{
int ret;
lzo_ctx->dst_len = lzo_ctx->decompressed_size;
lzo_ctx->dst = kmalloc(lzo_ctx->dst_len, GFP_KERNEL);
if (!lzo_ctx->dst) {
lzo_ctx->dst_len = 0;
return -ENOMEM;
}
ret = snd_soc_lzo_decompress(lzo_ctx);
if (ret < 0)
return ret;
return 0;
}
static inline int snd_soc_lzo_get_blkindex(struct snd_soc_codec *codec,
unsigned int reg)
{
const struct snd_soc_codec_driver *codec_drv;
codec_drv = codec->driver;
return (reg * codec_drv->reg_word_size) /
DIV_ROUND_UP(codec->reg_size, snd_soc_lzo_block_count());
}
static inline int snd_soc_lzo_get_blkpos(struct snd_soc_codec *codec,
unsigned int reg)
{
const struct snd_soc_codec_driver *codec_drv;
codec_drv = codec->driver;
return reg % (DIV_ROUND_UP(codec->reg_size, snd_soc_lzo_block_count()) /
codec_drv->reg_word_size);
}
static inline int snd_soc_lzo_get_blksize(struct snd_soc_codec *codec)
{
return DIV_ROUND_UP(codec->reg_size, snd_soc_lzo_block_count());
}
static int snd_soc_lzo_cache_sync(struct snd_soc_codec *codec)
{
struct snd_soc_lzo_ctx **lzo_blocks;
unsigned int val;
int i;
int ret;
lzo_blocks = codec->reg_cache;
for_each_set_bit(i, lzo_blocks[0]->sync_bmp, lzo_blocks[0]->sync_bmp_nbits) {
WARN_ON(!snd_soc_codec_writable_register(codec, i));
ret = snd_soc_cache_read(codec, i, &val);
if (ret)
return ret;
codec->cache_bypass = 1;
ret = snd_soc_write(codec, i, val);
codec->cache_bypass = 0;
if (ret)
return ret;
dev_dbg(codec->dev, "Synced register %#x, value = %#x\n",
i, val);
}
return 0;
}
static int snd_soc_lzo_cache_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
struct snd_soc_lzo_ctx *lzo_block, **lzo_blocks;
int ret, blkindex, blkpos;
size_t blksize, tmp_dst_len;
void *tmp_dst;
blkindex = snd_soc_lzo_get_blkindex(codec, reg);
blkpos = snd_soc_lzo_get_blkpos(codec, reg);
blksize = snd_soc_lzo_get_blksize(codec);
lzo_blocks = codec->reg_cache;
lzo_block = lzo_blocks[blkindex];
tmp_dst = lzo_block->dst;
tmp_dst_len = lzo_block->dst_len;
lzo_block->src = lzo_block->dst;
lzo_block->src_len = lzo_block->dst_len;
ret = snd_soc_lzo_decompress_cache_block(codec, lzo_block);
if (ret < 0) {
kfree(lzo_block->dst);
goto out;
}
if (snd_soc_set_cache_val(lzo_block->dst, blkpos, value,
codec->driver->reg_word_size)) {
kfree(lzo_block->dst);
goto out;
}
lzo_block->src = lzo_block->dst;
lzo_block->src_len = lzo_block->dst_len;
ret = snd_soc_lzo_compress_cache_block(codec, lzo_block);
if (ret < 0) {
kfree(lzo_block->dst);
kfree(lzo_block->src);
goto out;
}
set_bit(reg, lzo_block->sync_bmp);
kfree(tmp_dst);
kfree(lzo_block->src);
return 0;
out:
lzo_block->dst = tmp_dst;
lzo_block->dst_len = tmp_dst_len;
return ret;
}
static int snd_soc_lzo_cache_read(struct snd_soc_codec *codec,
unsigned int reg, unsigned int *value)
{
struct snd_soc_lzo_ctx *lzo_block, **lzo_blocks;
int ret, blkindex, blkpos;
size_t blksize, tmp_dst_len;
void *tmp_dst;
*value = 0;
blkindex = snd_soc_lzo_get_blkindex(codec, reg);
blkpos = snd_soc_lzo_get_blkpos(codec, reg);
blksize = snd_soc_lzo_get_blksize(codec);
lzo_blocks = codec->reg_cache;
lzo_block = lzo_blocks[blkindex];
tmp_dst = lzo_block->dst;
tmp_dst_len = lzo_block->dst_len;
lzo_block->src = lzo_block->dst;
lzo_block->src_len = lzo_block->dst_len;
ret = snd_soc_lzo_decompress_cache_block(codec, lzo_block);
if (ret >= 0)
*value = snd_soc_get_cache_val(lzo_block->dst, blkpos,
codec->driver->reg_word_size);
kfree(lzo_block->dst);
lzo_block->dst = tmp_dst;
lzo_block->dst_len = tmp_dst_len;
return 0;
}
static int snd_soc_lzo_cache_exit(struct snd_soc_codec *codec)
{
struct snd_soc_lzo_ctx **lzo_blocks;
int i, blkcount;
lzo_blocks = codec->reg_cache;
if (!lzo_blocks)
return 0;
blkcount = snd_soc_lzo_block_count();
if (lzo_blocks[0])
kfree(lzo_blocks[0]->sync_bmp);
for (i = 0; i < blkcount; ++i) {
if (lzo_blocks[i]) {
kfree(lzo_blocks[i]->wmem);
kfree(lzo_blocks[i]->dst);
}
kfree(lzo_blocks[i]);
}
kfree(lzo_blocks);
codec->reg_cache = NULL;
return 0;
}
static int snd_soc_lzo_cache_init(struct snd_soc_codec *codec)
{
struct snd_soc_lzo_ctx **lzo_blocks;
size_t bmp_size;
const struct snd_soc_codec_driver *codec_drv;
int ret, tofree, i, blksize, blkcount;
const char *p, *end;
unsigned long *sync_bmp;
ret = 0;
codec_drv = codec->driver;
tofree = 0;
if (!codec->reg_def_copy)
tofree = 1;
if (!codec->reg_def_copy) {
codec->reg_def_copy = kzalloc(codec->reg_size, GFP_KERNEL);
if (!codec->reg_def_copy)
return -ENOMEM;
}
blkcount = snd_soc_lzo_block_count();
codec->reg_cache = kzalloc(blkcount * sizeof *lzo_blocks,
GFP_KERNEL);
if (!codec->reg_cache) {
ret = -ENOMEM;
goto err_tofree;
}
lzo_blocks = codec->reg_cache;
bmp_size = codec_drv->reg_cache_size;
sync_bmp = kmalloc(BITS_TO_LONGS(bmp_size) * sizeof(long),
GFP_KERNEL);
if (!sync_bmp) {
ret = -ENOMEM;
goto err;
}
bitmap_zero(sync_bmp, bmp_size);
for (i = 0; i < blkcount; ++i) {
lzo_blocks[i] = kzalloc(sizeof **lzo_blocks,
GFP_KERNEL);
if (!lzo_blocks[i]) {
kfree(sync_bmp);
ret = -ENOMEM;
goto err;
}
lzo_blocks[i]->sync_bmp = sync_bmp;
lzo_blocks[i]->sync_bmp_nbits = bmp_size;
ret = snd_soc_lzo_prepare(lzo_blocks[i]);
if (ret < 0)
goto err;
}
blksize = snd_soc_lzo_get_blksize(codec);
p = codec->reg_def_copy;
end = codec->reg_def_copy + codec->reg_size;
for (i = 0; i < blkcount; ++i, p += blksize) {
lzo_blocks[i]->src = p;
if (p + blksize > end)
lzo_blocks[i]->src_len = end - p;
else
lzo_blocks[i]->src_len = blksize;
ret = snd_soc_lzo_compress_cache_block(codec,
lzo_blocks[i]);
if (ret < 0)
goto err;
lzo_blocks[i]->decompressed_size =
lzo_blocks[i]->src_len;
}
if (tofree) {
kfree(codec->reg_def_copy);
codec->reg_def_copy = NULL;
}
return 0;
err:
snd_soc_cache_exit(codec);
err_tofree:
if (tofree) {
kfree(codec->reg_def_copy);
codec->reg_def_copy = NULL;
}
return ret;
}
static int snd_soc_flat_cache_sync(struct snd_soc_codec *codec)
{
int i;
int ret;
const struct snd_soc_codec_driver *codec_drv;
unsigned int val;
codec_drv = codec->driver;
for (i = 0; i < codec_drv->reg_cache_size; ++i) {
ret = snd_soc_cache_read(codec, i, &val);
if (ret)
return ret;
if (codec->reg_def_copy)
if (snd_soc_get_cache_val(codec->reg_def_copy,
i, codec_drv->reg_word_size) == val)
continue;
WARN_ON(!snd_soc_codec_writable_register(codec, i));
ret = snd_soc_write(codec, i, val);
if (ret)
return ret;
dev_dbg(codec->dev, "Synced register %#x, value = %#x\n",
i, val);
}
return 0;
}
static int snd_soc_flat_cache_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
snd_soc_set_cache_val(codec->reg_cache, reg, value,
codec->driver->reg_word_size);
return 0;
}
static int snd_soc_flat_cache_read(struct snd_soc_codec *codec,
unsigned int reg, unsigned int *value)
{
*value = snd_soc_get_cache_val(codec->reg_cache, reg,
codec->driver->reg_word_size);
return 0;
}
static int snd_soc_flat_cache_exit(struct snd_soc_codec *codec)
{
if (!codec->reg_cache)
return 0;
kfree(codec->reg_cache);
codec->reg_cache = NULL;
return 0;
}
static int snd_soc_flat_cache_init(struct snd_soc_codec *codec)
{
if (codec->reg_def_copy)
codec->reg_cache = kmemdup(codec->reg_def_copy,
codec->reg_size, GFP_KERNEL);
else
codec->reg_cache = kzalloc(codec->reg_size, GFP_KERNEL);
if (!codec->reg_cache)
return -ENOMEM;
return 0;
}
int snd_soc_cache_init(struct snd_soc_codec *codec)
{
int i;
for (i = 0; i < ARRAY_SIZE(cache_types); ++i)
if (cache_types[i].id == codec->compress_type)
break;
if (i == ARRAY_SIZE(cache_types)) {
dev_warn(codec->dev, "Could not match compress type: %d\n",
codec->compress_type);
i = 0;
}
mutex_init(&codec->cache_rw_mutex);
codec->cache_ops = &cache_types[i];
if (codec->cache_ops->init) {
if (codec->cache_ops->name)
dev_dbg(codec->dev, "Initializing %s cache for %s codec\n",
codec->cache_ops->name, codec->name);
return codec->cache_ops->init(codec);
}
return -ENOSYS;
}
int snd_soc_cache_exit(struct snd_soc_codec *codec)
{
if (codec->cache_ops && codec->cache_ops->exit) {
if (codec->cache_ops->name)
dev_dbg(codec->dev, "Destroying %s cache for %s codec\n",
codec->cache_ops->name, codec->name);
return codec->cache_ops->exit(codec);
}
return -ENOSYS;
}
int snd_soc_cache_read(struct snd_soc_codec *codec,
unsigned int reg, unsigned int *value)
{
int ret;
mutex_lock(&codec->cache_rw_mutex);
if (value && codec->cache_ops && codec->cache_ops->read) {
ret = codec->cache_ops->read(codec, reg, value);
mutex_unlock(&codec->cache_rw_mutex);
return ret;
}
mutex_unlock(&codec->cache_rw_mutex);
return -ENOSYS;
}
int snd_soc_cache_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
int ret;
mutex_lock(&codec->cache_rw_mutex);
if (codec->cache_ops && codec->cache_ops->write) {
ret = codec->cache_ops->write(codec, reg, value);
mutex_unlock(&codec->cache_rw_mutex);
return ret;
}
mutex_unlock(&codec->cache_rw_mutex);
return -ENOSYS;
}
int snd_soc_cache_sync(struct snd_soc_codec *codec)
{
int ret;
const char *name;
if (!codec->cache_sync) {
return 0;
}
if (!codec->cache_ops || !codec->cache_ops->sync)
return -ENOSYS;
if (codec->cache_ops->name)
name = codec->cache_ops->name;
else
name = "unknown";
if (codec->cache_ops->name)
dev_dbg(codec->dev, "Syncing %s cache for %s codec\n",
codec->cache_ops->name, codec->name);
trace_snd_soc_cache_sync(codec, name, "start");
ret = codec->cache_ops->sync(codec);
if (!ret)
codec->cache_sync = 0;
trace_snd_soc_cache_sync(codec, name, "end");
return ret;
}
static int snd_soc_get_reg_access_index(struct snd_soc_codec *codec,
unsigned int reg)
{
const struct snd_soc_codec_driver *codec_drv;
unsigned int min, max, index;
codec_drv = codec->driver;
min = 0;
max = codec_drv->reg_access_size - 1;
do {
index = (min + max) / 2;
if (codec_drv->reg_access_default[index].reg == reg)
return index;
if (codec_drv->reg_access_default[index].reg < reg)
min = index + 1;
else
max = index;
} while (min <= max);
return -1;
}
int snd_soc_default_volatile_register(struct snd_soc_codec *codec,
unsigned int reg)
{
int index;
if (reg >= codec->driver->reg_cache_size)
return 1;
index = snd_soc_get_reg_access_index(codec, reg);
if (index < 0)
return 0;
return codec->driver->reg_access_default[index].vol;
}
int snd_soc_default_readable_register(struct snd_soc_codec *codec,
unsigned int reg)
{
int index;
if (reg >= codec->driver->reg_cache_size)
return 1;
index = snd_soc_get_reg_access_index(codec, reg);
if (index < 0)
return 0;
return codec->driver->reg_access_default[index].read;
}
int snd_soc_default_writable_register(struct snd_soc_codec *codec,
unsigned int reg)
{
int index;
if (reg >= codec->driver->reg_cache_size)
return 1;
index = snd_soc_get_reg_access_index(codec, reg);
if (index < 0)
return 0;
return codec->driver->reg_access_default[index].write;
}
