static int do_spi_write(void *control, const char *data, int len)
{
struct spi_device *spi = control;
int ret;
ret = spi_write(spi, data, len);
if (ret < 0)
return ret;
return len;
}
static int do_hw_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value, const void *data, int len)
{
int ret;
if (!snd_soc_codec_volatile_register(codec, reg) &&
reg < codec->driver->reg_cache_size &&
!codec->cache_bypass) {
ret = snd_soc_cache_write(codec, reg, value);
if (ret < 0)
return -1;
}
if (codec->cache_only) {
codec->cache_sync = 1;
return 0;
}
ret = codec->hw_write(codec->control_data, data, len);
if (ret == len)
return 0;
if (ret < 0)
return ret;
else
return -EIO;
}
static unsigned int do_hw_read(struct snd_soc_codec *codec, unsigned int reg)
{
int ret;
unsigned int val;
if (reg >= codec->driver->reg_cache_size ||
snd_soc_codec_volatile_register(codec, reg) ||
codec->cache_bypass) {
if (codec->cache_only)
return -1;
BUG_ON(!codec->hw_read);
return codec->hw_read(codec, reg);
}
ret = snd_soc_cache_read(codec, reg, &val);
if (ret < 0)
return -1;
return val;
}
static unsigned int snd_soc_4_12_read(struct snd_soc_codec *codec,
unsigned int reg)
{
return do_hw_read(codec, reg);
}
static int snd_soc_4_12_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u16 data;
data = cpu_to_be16((reg << 12) | (value & 0xffffff));
return do_hw_write(codec, reg, value, &data, 2);
}
static unsigned int snd_soc_7_9_read(struct snd_soc_codec *codec,
unsigned int reg)
{
return do_hw_read(codec, reg);
}
static int snd_soc_7_9_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[2];
data[0] = (reg << 1) | ((value >> 8) & 0x0001);
data[1] = value & 0x00ff;
return do_hw_write(codec, reg, value, data, 2);
}
static int snd_soc_8_8_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[2];
reg &= 0xff;
data[0] = reg;
data[1] = value & 0xff;
return do_hw_write(codec, reg, value, data, 2);
}
static unsigned int snd_soc_8_8_read(struct snd_soc_codec *codec,
unsigned int reg)
{
return do_hw_read(codec, reg);
}
static int snd_soc_8_16_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[3];
data[0] = reg;
data[1] = (value >> 8) & 0xff;
data[2] = value & 0xff;
return do_hw_write(codec, reg, value, data, 3);
}
static unsigned int snd_soc_8_16_read(struct snd_soc_codec *codec,
unsigned int reg)
{
return do_hw_read(codec, reg);
}
static unsigned int do_i2c_read(struct snd_soc_codec *codec,
void *reg, int reglen,
void *data, int datalen)
{
struct i2c_msg xfer[2];
int ret;
struct i2c_client *client = codec->control_data;
xfer[0].addr = client->addr;
xfer[0].flags = 0;
xfer[0].len = reglen;
xfer[0].buf = reg;
xfer[1].addr = client->addr;
xfer[1].flags = I2C_M_RD;
xfer[1].len = datalen;
xfer[1].buf = data;
ret = i2c_transfer(client->adapter, xfer, 2);
if (ret == 2)
return 0;
else if (ret < 0)
return ret;
else
return -EIO;
}
static unsigned int snd_soc_8_8_read_i2c(struct snd_soc_codec *codec,
unsigned int r)
{
u8 reg = r;
u8 data;
int ret;
ret = do_i2c_read(codec, &reg, 1, &data, 1);
if (ret < 0)
return 0;
return data;
}
static unsigned int snd_soc_8_16_read_i2c(struct snd_soc_codec *codec,
unsigned int r)
{
u8 reg = r;
u16 data;
int ret;
ret = do_i2c_read(codec, &reg, 1, &data, 2);
if (ret < 0)
return 0;
return (data >> 8) | ((data & 0xff) << 8);
}
static unsigned int snd_soc_16_8_read_i2c(struct snd_soc_codec *codec,
unsigned int r)
{
u16 reg = r;
u8 data;
int ret;
ret = do_i2c_read(codec, &reg, 2, &data, 1);
if (ret < 0)
return 0;
return data;
}
static unsigned int snd_soc_16_8_read(struct snd_soc_codec *codec,
unsigned int reg)
{
return do_hw_read(codec, reg);
}
static int snd_soc_16_8_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[3];
data[0] = (reg >> 8) & 0xff;
data[1] = reg & 0xff;
data[2] = value;
return do_hw_write(codec, reg, value, data, 3);
}
static unsigned int snd_soc_16_16_read_i2c(struct snd_soc_codec *codec,
unsigned int r)
{
u16 reg = cpu_to_be16(r);
u16 data;
int ret;
ret = do_i2c_read(codec, &reg, 2, &data, 2);
if (ret < 0)
return 0;
return be16_to_cpu(data);
}
static unsigned int snd_soc_16_16_read(struct snd_soc_codec *codec,
unsigned int reg)
{
return do_hw_read(codec, reg);
}
static int snd_soc_16_16_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[4];
data[0] = (reg >> 8) & 0xff;
data[1] = reg & 0xff;
data[2] = (value >> 8) & 0xff;
data[3] = value & 0xff;
return do_hw_write(codec, reg, value, data, 4);
}
static int snd_soc_hw_bulk_write_raw(struct snd_soc_codec *codec, unsigned int reg,
const void *data, size_t len)
{
int ret;
if (!codec->cache_bypass
&& !snd_soc_codec_volatile_register(codec, reg)
&& reg < codec->driver->reg_cache_size)
return -EINVAL;
switch (codec->control_type) {
#if defined(CONFIG_I2C) || (defined(CONFIG_I2C_MODULE) && defined(MODULE))
case SND_SOC_I2C:
ret = i2c_master_send(codec->control_data, data, len);
break;
#endif
#if defined(CONFIG_SPI_MASTER)
case SND_SOC_SPI:
ret = spi_write(codec->control_data, data, len);
break;
#endif
default:
BUG();
}
if (ret == len)
return 0;
if (ret < 0)
return ret;
else
return -EIO;
}
int snd_soc_codec_set_cache_io(struct snd_soc_codec *codec,
int addr_bits, int data_bits,
enum snd_soc_control_type control)
{
int i;
for (i = 0; i < ARRAY_SIZE(io_types); i++)
if (io_types[i].addr_bits == addr_bits &&
io_types[i].data_bits == data_bits)
break;
if (i == ARRAY_SIZE(io_types)) {
printk(KERN_ERR
"No I/O functions for %d bit address %d bit data\n",
addr_bits, data_bits);
return -EINVAL;
}
codec->write = io_types[i].write;
codec->read = io_types[i].read;
codec->bulk_write_raw = snd_soc_hw_bulk_write_raw;
switch (control) {
case SND_SOC_I2C:
#if defined(CONFIG_I2C) || (defined(CONFIG_I2C_MODULE) && defined(MODULE))
codec->hw_write = (hw_write_t)i2c_master_send;
#endif
if (io_types[i].i2c_read)
codec->hw_read = io_types[i].i2c_read;
codec->control_data = container_of(codec->dev,
struct i2c_client,
dev);
break;
case SND_SOC_SPI:
#ifdef CONFIG_SPI_MASTER
codec->hw_write = do_spi_write;
#endif
codec->control_data = container_of(codec->dev,
struct spi_device,
dev);
break;
}
return 0;
}
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
static struct snd_soc_rbtree_node *snd_soc_rbtree_lookup(
struct rb_root *root, unsigned int reg)
{
struct rb_node *node;
struct snd_soc_rbtree_node *rbnode;
node = root->rb_node;
while (node) {
rbnode = container_of(node, struct snd_soc_rbtree_node, node);
if (rbnode->reg < reg)
node = node->rb_left;
else if (rbnode->reg > reg)
node = node->rb_right;
else
return rbnode;
}
return NULL;
}
static int snd_soc_rbtree_insert(struct rb_root *root,
struct snd_soc_rbtree_node *rbnode)
{
struct rb_node **new, *parent;
struct snd_soc_rbtree_node *rbnode_tmp;
parent = NULL;
new = &root->rb_node;
while (*new) {
rbnode_tmp = container_of(*new, struct snd_soc_rbtree_node,
node);
parent = *new;
if (rbnode_tmp->reg < rbnode->reg)
new = &((*new)->rb_left);
else if (rbnode_tmp->reg > rbnode->reg)
new = &((*new)->rb_right);
else
return 0;
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
unsigned int val;
int ret;
rbtree_ctx = codec->reg_cache;
for (node = rb_first(&rbtree_ctx->root); node; node = rb_next(node)) {
rbnode = rb_entry(node, struct snd_soc_rbtree_node, node);
if (rbnode->value == rbnode->defval)
continue;
WARN_ON(codec->writable_register &&
codec->writable_register(codec, rbnode->reg));
ret = snd_soc_cache_read(codec, rbnode->reg, &val);
if (ret)
return ret;
codec->cache_bypass = 1;
ret = snd_soc_write(codec, rbnode->reg, val);
codec->cache_bypass = 0;
if (ret)
return ret;
dev_dbg(codec->dev, "Synced register %#x, value = %#x\n",
rbnode->reg, val);
}
return 0;
}
static int snd_soc_rbtree_cache_write(struct snd_soc_codec *codec,
unsigned int reg, unsigned int value)
{
struct snd_soc_rbtree_ctx *rbtree_ctx;
struct snd_soc_rbtree_node *rbnode;
rbtree_ctx = codec->reg_cache;
rbnode = snd_soc_rbtree_lookup(&rbtree_ctx->root, reg);
if (rbnode) {
if (rbnode->value == value)
return 0;
rbnode->value = value;
} else {
if (!value)
return 0;
rbnode = kzalloc(sizeof *rbnode, GFP_KERNEL);
if (!rbnode)
return -ENOMEM;
rbnode->reg = reg;
rbnode->value = value;
snd_soc_rbtree_insert(&rbtree_ctx->root, rbnode);
}
return 0;
}
static int snd_soc_rbtree_cache_read(struct snd_soc_codec *codec,
unsigned int reg, unsigned int *value)
{
struct snd_soc_rbtree_ctx *rbtree_ctx;
struct snd_soc_rbtree_node *rbnode;
rbtree_ctx = codec->reg_cache;
rbnode = snd_soc_rbtree_lookup(&rbtree_ctx->root, reg);
if (rbnode) {
*value = rbnode->value;
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
kfree(rbtree_node);
}
kfree(codec->reg_cache);
codec->reg_cache = NULL;
return 0;
}
static int snd_soc_rbtree_cache_init(struct snd_soc_codec *codec)
{
struct snd_soc_rbtree_node *rbtree_node;
struct snd_soc_rbtree_ctx *rbtree_ctx;
unsigned int val;
unsigned int word_size;
int i;
int ret;
codec->reg_cache = kmalloc(sizeof *rbtree_ctx, GFP_KERNEL);
if (!codec->reg_cache)
return -ENOMEM;
rbtree_ctx = codec->reg_cache;
rbtree_ctx->root = RB_ROOT;
if (!codec->reg_def_copy)
return 0;
word_size = codec->driver->reg_word_size;
for (i = 0; i < codec->driver->reg_cache_size; ++i) {
val = snd_soc_get_cache_val(codec->reg_def_copy, i, word_size);
if (!val)
continue;
rbtree_node = kzalloc(sizeof *rbtree_node, GFP_KERNEL);
if (!rbtree_node) {
ret = -ENOMEM;
snd_soc_cache_exit(codec);
break;
}
rbtree_node->reg = i;
rbtree_node->value = val;
rbtree_node->defval = val;
snd_soc_rbtree_insert(&rbtree_ctx->root, rbtree_node);
}
return 0;
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
const struct snd_soc_codec_driver *codec_drv;
codec_drv = codec->driver;
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
WARN_ON(codec->writable_register &&
codec->writable_register(codec, i));
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
WARN_ON(codec->writable_register &&
codec->writable_register(codec, i));
ret = snd_soc_cache_read(codec, i, &val);
if (ret)
return ret;
if (codec->reg_def_copy)
if (snd_soc_get_cache_val(codec->reg_def_copy,
i, codec_drv->reg_word_size) == val)
continue;
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
const struct snd_soc_codec_driver *codec_drv;
codec_drv = codec->driver;
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
