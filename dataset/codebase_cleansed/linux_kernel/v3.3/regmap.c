bool regmap_writeable(struct regmap *map, unsigned int reg)
{
if (map->max_register && reg > map->max_register)
return false;
if (map->writeable_reg)
return map->writeable_reg(map->dev, reg);
return true;
}
bool regmap_readable(struct regmap *map, unsigned int reg)
{
if (map->max_register && reg > map->max_register)
return false;
if (map->readable_reg)
return map->readable_reg(map->dev, reg);
return true;
}
bool regmap_volatile(struct regmap *map, unsigned int reg)
{
if (map->max_register && reg > map->max_register)
return false;
if (map->volatile_reg)
return map->volatile_reg(map->dev, reg);
return true;
}
bool regmap_precious(struct regmap *map, unsigned int reg)
{
if (map->max_register && reg > map->max_register)
return false;
if (map->precious_reg)
return map->precious_reg(map->dev, reg);
return false;
}
static bool regmap_volatile_range(struct regmap *map, unsigned int reg,
unsigned int num)
{
unsigned int i;
for (i = 0; i < num; i++)
if (!regmap_volatile(map, reg + i))
return false;
return true;
}
static void regmap_format_4_12_write(struct regmap *map,
unsigned int reg, unsigned int val)
{
__be16 *out = map->work_buf;
*out = cpu_to_be16((reg << 12) | val);
}
static void regmap_format_7_9_write(struct regmap *map,
unsigned int reg, unsigned int val)
{
__be16 *out = map->work_buf;
*out = cpu_to_be16((reg << 9) | val);
}
static void regmap_format_10_14_write(struct regmap *map,
unsigned int reg, unsigned int val)
{
u8 *out = map->work_buf;
out[2] = val;
out[1] = (val >> 8) | (reg << 6);
out[0] = reg >> 2;
}
static void regmap_format_8(void *buf, unsigned int val)
{
u8 *b = buf;
b[0] = val;
}
static void regmap_format_16(void *buf, unsigned int val)
{
__be16 *b = buf;
b[0] = cpu_to_be16(val);
}
static unsigned int regmap_parse_8(void *buf)
{
u8 *b = buf;
return b[0];
}
static unsigned int regmap_parse_16(void *buf)
{
__be16 *b = buf;
b[0] = be16_to_cpu(b[0]);
return b[0];
}
struct regmap *regmap_init(struct device *dev,
const struct regmap_bus *bus,
const struct regmap_config *config)
{
struct regmap *map;
int ret = -EINVAL;
if (!bus || !config)
goto err;
map = kzalloc(sizeof(*map), GFP_KERNEL);
if (map == NULL) {
ret = -ENOMEM;
goto err;
}
mutex_init(&map->lock);
map->format.buf_size = (config->reg_bits + config->val_bits) / 8;
map->format.reg_bytes = config->reg_bits / 8;
map->format.val_bytes = config->val_bits / 8;
map->dev = dev;
map->bus = bus;
map->max_register = config->max_register;
map->writeable_reg = config->writeable_reg;
map->readable_reg = config->readable_reg;
map->volatile_reg = config->volatile_reg;
map->precious_reg = config->precious_reg;
map->cache_type = config->cache_type;
if (config->read_flag_mask || config->write_flag_mask) {
map->read_flag_mask = config->read_flag_mask;
map->write_flag_mask = config->write_flag_mask;
} else {
map->read_flag_mask = bus->read_flag_mask;
}
switch (config->reg_bits) {
case 4:
switch (config->val_bits) {
case 12:
map->format.format_write = regmap_format_4_12_write;
break;
default:
goto err_map;
}
break;
case 7:
switch (config->val_bits) {
case 9:
map->format.format_write = regmap_format_7_9_write;
break;
default:
goto err_map;
}
break;
case 10:
switch (config->val_bits) {
case 14:
map->format.format_write = regmap_format_10_14_write;
break;
default:
goto err_map;
}
break;
case 8:
map->format.format_reg = regmap_format_8;
break;
case 16:
map->format.format_reg = regmap_format_16;
break;
default:
goto err_map;
}
switch (config->val_bits) {
case 8:
map->format.format_val = regmap_format_8;
map->format.parse_val = regmap_parse_8;
break;
case 16:
map->format.format_val = regmap_format_16;
map->format.parse_val = regmap_parse_16;
break;
}
if (!map->format.format_write &&
!(map->format.format_reg && map->format.format_val))
goto err_map;
map->work_buf = kmalloc(map->format.buf_size, GFP_KERNEL);
if (map->work_buf == NULL) {
ret = -ENOMEM;
goto err_map;
}
regmap_debugfs_init(map);
ret = regcache_init(map, config);
if (ret < 0)
goto err_free_workbuf;
return map;
err_free_workbuf:
kfree(map->work_buf);
err_map:
kfree(map);
err:
return ERR_PTR(ret);
}
int regmap_reinit_cache(struct regmap *map, const struct regmap_config *config)
{
int ret;
mutex_lock(&map->lock);
regcache_exit(map);
map->max_register = config->max_register;
map->writeable_reg = config->writeable_reg;
map->readable_reg = config->readable_reg;
map->volatile_reg = config->volatile_reg;
map->precious_reg = config->precious_reg;
map->cache_type = config->cache_type;
map->cache_bypass = false;
map->cache_only = false;
ret = regcache_init(map, config);
mutex_unlock(&map->lock);
return ret;
}
void regmap_exit(struct regmap *map)
{
regcache_exit(map);
regmap_debugfs_exit(map);
kfree(map->work_buf);
kfree(map);
}
static int _regmap_raw_write(struct regmap *map, unsigned int reg,
const void *val, size_t val_len)
{
u8 *u8 = map->work_buf;
void *buf;
int ret = -ENOTSUPP;
size_t len;
int i;
if (map->writeable_reg)
for (i = 0; i < val_len / map->format.val_bytes; i++)
if (!map->writeable_reg(map->dev, reg + i))
return -EINVAL;
map->format.format_reg(map->work_buf, reg);
u8[0] |= map->write_flag_mask;
trace_regmap_hw_write_start(map->dev, reg,
val_len / map->format.val_bytes);
if (val == map->work_buf + map->format.reg_bytes)
ret = map->bus->write(map->dev, map->work_buf,
map->format.reg_bytes + val_len);
else if (map->bus->gather_write)
ret = map->bus->gather_write(map->dev, map->work_buf,
map->format.reg_bytes,
val, val_len);
if (ret == -ENOTSUPP) {
len = map->format.reg_bytes + val_len;
buf = kmalloc(len, GFP_KERNEL);
if (!buf)
return -ENOMEM;
memcpy(buf, map->work_buf, map->format.reg_bytes);
memcpy(buf + map->format.reg_bytes, val, val_len);
ret = map->bus->write(map->dev, buf, len);
kfree(buf);
}
trace_regmap_hw_write_done(map->dev, reg,
val_len / map->format.val_bytes);
return ret;
}
int _regmap_write(struct regmap *map, unsigned int reg,
unsigned int val)
{
int ret;
BUG_ON(!map->format.format_write && !map->format.format_val);
if (!map->cache_bypass) {
ret = regcache_write(map, reg, val);
if (ret != 0)
return ret;
if (map->cache_only) {
map->cache_dirty = true;
return 0;
}
}
trace_regmap_reg_write(map->dev, reg, val);
if (map->format.format_write) {
map->format.format_write(map, reg, val);
trace_regmap_hw_write_start(map->dev, reg, 1);
ret = map->bus->write(map->dev, map->work_buf,
map->format.buf_size);
trace_regmap_hw_write_done(map->dev, reg, 1);
return ret;
} else {
map->format.format_val(map->work_buf + map->format.reg_bytes,
val);
return _regmap_raw_write(map, reg,
map->work_buf + map->format.reg_bytes,
map->format.val_bytes);
}
}
int regmap_write(struct regmap *map, unsigned int reg, unsigned int val)
{
int ret;
mutex_lock(&map->lock);
ret = _regmap_write(map, reg, val);
mutex_unlock(&map->lock);
return ret;
}
int regmap_raw_write(struct regmap *map, unsigned int reg,
const void *val, size_t val_len)
{
size_t val_count = val_len / map->format.val_bytes;
int ret;
WARN_ON(!regmap_volatile_range(map, reg, val_count) &&
map->cache_type != REGCACHE_NONE);
mutex_lock(&map->lock);
ret = _regmap_raw_write(map, reg, val, val_len);
mutex_unlock(&map->lock);
return ret;
}
static int _regmap_raw_read(struct regmap *map, unsigned int reg, void *val,
unsigned int val_len)
{
u8 *u8 = map->work_buf;
int ret;
map->format.format_reg(map->work_buf, reg);
u8[0] |= map->read_flag_mask;
trace_regmap_hw_read_start(map->dev, reg,
val_len / map->format.val_bytes);
ret = map->bus->read(map->dev, map->work_buf, map->format.reg_bytes,
val, val_len);
trace_regmap_hw_read_done(map->dev, reg,
val_len / map->format.val_bytes);
return ret;
}
static int _regmap_read(struct regmap *map, unsigned int reg,
unsigned int *val)
{
int ret;
if (!map->cache_bypass) {
ret = regcache_read(map, reg, val);
if (ret == 0)
return 0;
}
if (!map->format.parse_val)
return -EINVAL;
if (map->cache_only)
return -EBUSY;
ret = _regmap_raw_read(map, reg, map->work_buf, map->format.val_bytes);
if (ret == 0) {
*val = map->format.parse_val(map->work_buf);
trace_regmap_reg_read(map->dev, reg, *val);
}
return ret;
}
int regmap_read(struct regmap *map, unsigned int reg, unsigned int *val)
{
int ret;
mutex_lock(&map->lock);
ret = _regmap_read(map, reg, val);
mutex_unlock(&map->lock);
return ret;
}
int regmap_raw_read(struct regmap *map, unsigned int reg, void *val,
size_t val_len)
{
size_t val_count = val_len / map->format.val_bytes;
int ret;
WARN_ON(!regmap_volatile_range(map, reg, val_count) &&
map->cache_type != REGCACHE_NONE);
mutex_lock(&map->lock);
ret = _regmap_raw_read(map, reg, val, val_len);
mutex_unlock(&map->lock);
return ret;
}
int regmap_bulk_read(struct regmap *map, unsigned int reg, void *val,
size_t val_count)
{
int ret, i;
size_t val_bytes = map->format.val_bytes;
bool vol = regmap_volatile_range(map, reg, val_count);
if (!map->format.parse_val)
return -EINVAL;
if (vol || map->cache_type == REGCACHE_NONE) {
ret = regmap_raw_read(map, reg, val, val_bytes * val_count);
if (ret != 0)
return ret;
for (i = 0; i < val_count * val_bytes; i += val_bytes)
map->format.parse_val(val + i);
} else {
for (i = 0; i < val_count; i++) {
ret = regmap_read(map, reg + i, val + (i * val_bytes));
if (ret != 0)
return ret;
}
}
return 0;
}
static int _regmap_update_bits(struct regmap *map, unsigned int reg,
unsigned int mask, unsigned int val,
bool *change)
{
int ret;
unsigned int tmp, orig;
mutex_lock(&map->lock);
ret = _regmap_read(map, reg, &orig);
if (ret != 0)
goto out;
tmp = orig & ~mask;
tmp |= val & mask;
if (tmp != orig) {
ret = _regmap_write(map, reg, tmp);
*change = true;
} else {
*change = false;
}
out:
mutex_unlock(&map->lock);
return ret;
}
int regmap_update_bits(struct regmap *map, unsigned int reg,
unsigned int mask, unsigned int val)
{
bool change;
return _regmap_update_bits(map, reg, mask, val, &change);
}
int regmap_update_bits_check(struct regmap *map, unsigned int reg,
unsigned int mask, unsigned int val,
bool *change)
{
return _regmap_update_bits(map, reg, mask, val, change);
}
static int __init regmap_initcall(void)
{
regmap_debugfs_initcall();
return 0;
}
