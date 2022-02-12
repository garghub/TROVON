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
return NULL;
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
return map;
err_map:
kfree(map);
err:
return ERR_PTR(ret);
}
void regmap_exit(struct regmap *map)
{
kfree(map->work_buf);
kfree(map);
}
static int _regmap_raw_write(struct regmap *map, unsigned int reg,
const void *val, size_t val_len)
{
void *buf;
int ret = -ENOTSUPP;
size_t len;
map->format.format_reg(map->work_buf, reg);
if (map->bus->gather_write)
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
return ret;
}
static int _regmap_write(struct regmap *map, unsigned int reg,
unsigned int val)
{
BUG_ON(!map->format.format_write && !map->format.format_val);
if (map->format.format_write) {
map->format.format_write(map, reg, val);
return map->bus->write(map->dev, map->work_buf,
map->format.buf_size);
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
int ret;
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
if (map->bus->read_flag_mask)
u8[0] |= map->bus->read_flag_mask;
ret = map->bus->read(map->dev, map->work_buf, map->format.reg_bytes,
val, val_len);
if (ret != 0)
return ret;
return 0;
}
static int _regmap_read(struct regmap *map, unsigned int reg,
unsigned int *val)
{
int ret;
if (!map->format.parse_val)
return -EINVAL;
ret = _regmap_raw_read(map, reg, map->work_buf, map->format.val_bytes);
if (ret == 0)
*val = map->format.parse_val(map->work_buf);
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
int ret;
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
if (!map->format.parse_val)
return -EINVAL;
ret = regmap_raw_read(map, reg, val, val_bytes * val_count);
if (ret != 0)
return ret;
for (i = 0; i < val_count * val_bytes; i += val_bytes)
map->format.parse_val(val + i);
return 0;
}
int regmap_update_bits(struct regmap *map, unsigned int reg,
unsigned int mask, unsigned int val)
{
int ret;
unsigned int tmp;
mutex_lock(&map->lock);
ret = _regmap_read(map, reg, &tmp);
if (ret != 0)
goto out;
tmp &= ~mask;
tmp |= val & mask;
ret = _regmap_write(map, reg, tmp);
out:
mutex_unlock(&map->lock);
return ret;
}
