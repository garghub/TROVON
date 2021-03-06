void ps3_os_area_flash_register(const struct ps3_os_area_flash_ops *ops)
{
mutex_lock(&os_area_flash_mutex);
os_area_flash_ops = ops;
mutex_unlock(&os_area_flash_mutex);
}
static ssize_t os_area_flash_read(void *buf, size_t count, loff_t pos)
{
ssize_t res = -ENODEV;
mutex_lock(&os_area_flash_mutex);
if (os_area_flash_ops)
res = os_area_flash_ops->read(buf, count, pos);
mutex_unlock(&os_area_flash_mutex);
return res;
}
static ssize_t os_area_flash_write(const void *buf, size_t count, loff_t pos)
{
ssize_t res = -ENODEV;
mutex_lock(&os_area_flash_mutex);
if (os_area_flash_ops)
res = os_area_flash_ops->write(buf, count, pos);
mutex_unlock(&os_area_flash_mutex);
return res;
}
static void os_area_set_property(struct device_node *node,
struct property *prop)
{
int result;
struct property *tmp = of_find_property(node, prop->name, NULL);
if (tmp) {
pr_debug("%s:%d found %s\n", __func__, __LINE__, prop->name);
prom_remove_property(node, tmp);
}
result = prom_add_property(node, prop);
if (result)
pr_debug("%s:%d prom_set_property failed\n", __func__,
__LINE__);
}
static void __init os_area_get_property(struct device_node *node,
struct property *prop)
{
const struct property *tmp = of_find_property(node, prop->name, NULL);
if (tmp) {
BUG_ON(prop->length != tmp->length);
memcpy(prop->value, tmp->value, prop->length);
} else
pr_debug("%s:%d not found %s\n", __func__, __LINE__,
prop->name);
}
static void dump_field(char *s, const u8 *field, int size_of_field)
{
#if defined(DEBUG)
int i;
for (i = 0; i < size_of_field; i++)
s[i] = isprint(field[i]) ? field[i] : '.';
s[i] = 0;
#endif
}
static void _dump_header(const struct os_area_header *h, const char *func,
int line)
{
char str[sizeof(h->magic_num) + 1];
dump_field(str, h->magic_num, sizeof(h->magic_num));
pr_debug("%s:%d: h.magic_num: '%s'\n", func, line,
str);
pr_debug("%s:%d: h.hdr_version: %u\n", func, line,
h->hdr_version);
pr_debug("%s:%d: h.db_area_offset: %u\n", func, line,
h->db_area_offset);
pr_debug("%s:%d: h.ldr_area_offset: %u\n", func, line,
h->ldr_area_offset);
pr_debug("%s:%d: h.ldr_format: %u\n", func, line,
h->ldr_format);
pr_debug("%s:%d: h.ldr_size: %xh\n", func, line,
h->ldr_size);
}
static void _dump_params(const struct os_area_params *p, const char *func,
int line)
{
pr_debug("%s:%d: p.boot_flag: %u\n", func, line, p->boot_flag);
pr_debug("%s:%d: p.num_params: %u\n", func, line, p->num_params);
pr_debug("%s:%d: p.rtc_diff %lld\n", func, line, p->rtc_diff);
pr_debug("%s:%d: p.av_multi_out %u\n", func, line, p->av_multi_out);
pr_debug("%s:%d: p.ctrl_button: %u\n", func, line, p->ctrl_button);
pr_debug("%s:%d: p.static_ip_addr: %u.%u.%u.%u\n", func, line,
p->static_ip_addr[0], p->static_ip_addr[1],
p->static_ip_addr[2], p->static_ip_addr[3]);
pr_debug("%s:%d: p.network_mask: %u.%u.%u.%u\n", func, line,
p->network_mask[0], p->network_mask[1],
p->network_mask[2], p->network_mask[3]);
pr_debug("%s:%d: p.default_gateway: %u.%u.%u.%u\n", func, line,
p->default_gateway[0], p->default_gateway[1],
p->default_gateway[2], p->default_gateway[3]);
pr_debug("%s:%d: p.dns_primary: %u.%u.%u.%u\n", func, line,
p->dns_primary[0], p->dns_primary[1],
p->dns_primary[2], p->dns_primary[3]);
pr_debug("%s:%d: p.dns_secondary: %u.%u.%u.%u\n", func, line,
p->dns_secondary[0], p->dns_secondary[1],
p->dns_secondary[2], p->dns_secondary[3]);
}
static int verify_header(const struct os_area_header *header)
{
if (memcmp(header->magic_num, OS_AREA_HEADER_MAGIC_NUM,
sizeof(header->magic_num))) {
pr_debug("%s:%d magic_num failed\n", __func__, __LINE__);
return -1;
}
if (header->hdr_version < 1) {
pr_debug("%s:%d hdr_version failed\n", __func__, __LINE__);
return -1;
}
if (header->db_area_offset > header->ldr_area_offset) {
pr_debug("%s:%d offsets failed\n", __func__, __LINE__);
return -1;
}
return 0;
}
static int db_verify(const struct os_area_db *db)
{
if (memcmp(db->magic_num, OS_AREA_DB_MAGIC_NUM,
sizeof(db->magic_num))) {
pr_debug("%s:%d magic_num failed\n", __func__, __LINE__);
return -EINVAL;
}
if (db->version != 1) {
pr_debug("%s:%d version failed\n", __func__, __LINE__);
return -EINVAL;
}
return 0;
}
static unsigned int db_align_up(unsigned int val, unsigned int size)
{
return (val + (size - 1)) & (~(size - 1));
}
static int db_for_each_64(const struct os_area_db *db,
const struct os_area_db_id *match_id, struct db_iterator *i)
{
next:
if (!i->db) {
i->db = db;
i->match_id = match_id ? *match_id : os_area_db_id_any;
i->idx = (void *)db + db->index_64;
i->last_idx = i->idx + db->count_64;
i->value_64 = (void *)db + db->index_64
+ db_align_up(db->count_64, 8);
} else {
i->idx++;
i->value_64++;
}
if (i->idx >= i->last_idx) {
pr_debug("%s:%d: reached end\n", __func__, __LINE__);
return 0;
}
if (i->match_id.owner != OS_AREA_DB_OWNER_ANY
&& i->match_id.owner != (int)i->idx->owner)
goto next;
if (i->match_id.key != OS_AREA_DB_KEY_ANY
&& i->match_id.key != (int)i->idx->key)
goto next;
return 1;
}
static int db_delete_64(struct os_area_db *db, const struct os_area_db_id *id)
{
struct db_iterator i;
for (i.db = NULL; db_for_each_64(db, id, &i); ) {
pr_debug("%s:%d: got (%d:%d) %llxh\n", __func__, __LINE__,
i.idx->owner, i.idx->key,
(unsigned long long)*i.value_64);
i.idx->owner = 0;
i.idx->key = 0;
*i.value_64 = 0;
}
return 0;
}
static int db_set_64(struct os_area_db *db, const struct os_area_db_id *id,
uint64_t value)
{
struct db_iterator i;
pr_debug("%s:%d: (%d:%d) <= %llxh\n", __func__, __LINE__,
id->owner, id->key, (unsigned long long)value);
if (!id->owner || id->owner == OS_AREA_DB_OWNER_ANY
|| id->key == OS_AREA_DB_KEY_ANY) {
pr_debug("%s:%d: bad id: (%d:%d)\n", __func__,
__LINE__, id->owner, id->key);
return -1;
}
db_delete_64(db, id);
i.db = NULL;
if (db_for_each_64(db, &os_area_db_id_empty, &i)) {
pr_debug("%s:%d: got (%d:%d) %llxh\n", __func__, __LINE__,
i.idx->owner, i.idx->key,
(unsigned long long)*i.value_64);
i.idx->owner = id->owner;
i.idx->key = id->key;
*i.value_64 = value;
pr_debug("%s:%d: set (%d:%d) <= %llxh\n", __func__, __LINE__,
i.idx->owner, i.idx->key,
(unsigned long long)*i.value_64);
return 0;
}
pr_debug("%s:%d: database full.\n",
__func__, __LINE__);
return -1;
}
static int db_get_64(const struct os_area_db *db,
const struct os_area_db_id *id, uint64_t *value)
{
struct db_iterator i;
i.db = NULL;
if (db_for_each_64(db, id, &i)) {
*value = *i.value_64;
pr_debug("%s:%d: found %lld\n", __func__, __LINE__,
(long long int)*i.value_64);
return 0;
}
pr_debug("%s:%d: not found\n", __func__, __LINE__);
return -1;
}
static int db_get_rtc_diff(const struct os_area_db *db, int64_t *rtc_diff)
{
return db_get_64(db, &os_area_db_id_rtc_diff, (uint64_t*)rtc_diff);
}
static void _dump_db(const struct os_area_db *db, const char *func,
int line)
{
char str[sizeof(db->magic_num) + 1];
dump_field(str, db->magic_num, sizeof(db->magic_num));
pr_debug("%s:%d: db.magic_num: '%s'\n", func, line,
str);
pr_debug("%s:%d: db.version: %u\n", func, line,
db->version);
pr_debug("%s:%d: db.index_64: %u\n", func, line,
db->index_64);
pr_debug("%s:%d: db.count_64: %u\n", func, line,
db->count_64);
pr_debug("%s:%d: db.index_32: %u\n", func, line,
db->index_32);
pr_debug("%s:%d: db.count_32: %u\n", func, line,
db->count_32);
pr_debug("%s:%d: db.index_16: %u\n", func, line,
db->index_16);
pr_debug("%s:%d: db.count_16: %u\n", func, line,
db->count_16);
}
static void os_area_db_init(struct os_area_db *db)
{
enum {
HEADER_SIZE = offsetof(struct os_area_db, _db_data),
INDEX_64_COUNT = 64,
VALUES_64_COUNT = 57,
INDEX_32_COUNT = 64,
VALUES_32_COUNT = 57,
INDEX_16_COUNT = 64,
VALUES_16_COUNT = 57,
};
memset(db, 0, sizeof(struct os_area_db));
memcpy(db->magic_num, OS_AREA_DB_MAGIC_NUM, sizeof(db->magic_num));
db->version = 1;
db->index_64 = HEADER_SIZE;
db->count_64 = VALUES_64_COUNT;
db->index_32 = HEADER_SIZE
+ INDEX_64_COUNT * sizeof(struct db_index)
+ VALUES_64_COUNT * sizeof(u64);
db->count_32 = VALUES_32_COUNT;
db->index_16 = HEADER_SIZE
+ INDEX_64_COUNT * sizeof(struct db_index)
+ VALUES_64_COUNT * sizeof(u64)
+ INDEX_32_COUNT * sizeof(struct db_index)
+ VALUES_32_COUNT * sizeof(u32);
db->count_16 = VALUES_16_COUNT;
BUILD_BUG_ON(sizeof(struct db_index) != 1);
BUILD_BUG_ON(sizeof(struct os_area_db) != 2 * OS_AREA_SEGMENT_SIZE);
BUILD_BUG_ON(INDEX_64_COUNT & 0x7);
BUILD_BUG_ON(VALUES_64_COUNT > INDEX_64_COUNT);
BUILD_BUG_ON(INDEX_32_COUNT & 0x7);
BUILD_BUG_ON(VALUES_32_COUNT > INDEX_32_COUNT);
BUILD_BUG_ON(INDEX_16_COUNT & 0x7);
BUILD_BUG_ON(VALUES_16_COUNT > INDEX_16_COUNT);
BUILD_BUG_ON(HEADER_SIZE
+ INDEX_64_COUNT * sizeof(struct db_index)
+ VALUES_64_COUNT * sizeof(u64)
+ INDEX_32_COUNT * sizeof(struct db_index)
+ VALUES_32_COUNT * sizeof(u32)
+ INDEX_16_COUNT * sizeof(struct db_index)
+ VALUES_16_COUNT * sizeof(u16)
> sizeof(struct os_area_db));
}
static int update_flash_db(void)
{
const unsigned int buf_len = 8 * OS_AREA_SEGMENT_SIZE;
struct os_area_header *header;
ssize_t count;
int error;
loff_t pos;
struct os_area_db* db;
header = kmalloc(buf_len, GFP_KERNEL);
if (!header) {
pr_debug("%s: kmalloc failed\n", __func__);
return -ENOMEM;
}
count = os_area_flash_read(header, buf_len, 0);
if (count < 0) {
pr_debug("%s: os_area_flash_read failed %zd\n", __func__,
count);
error = count;
goto fail;
}
pos = header->db_area_offset * OS_AREA_SEGMENT_SIZE;
if (count < OS_AREA_SEGMENT_SIZE || verify_header(header) ||
count < pos) {
pr_debug("%s: verify_header failed\n", __func__);
dump_header(header);
error = -EINVAL;
goto fail;
}
db = (void *)header + pos;
error = db_verify(db);
if (error) {
pr_notice("%s: Verify of flash database failed, formatting.\n",
__func__);
dump_db(db);
os_area_db_init(db);
}
db_set_64(db, &os_area_db_id_rtc_diff, saved_params.rtc_diff);
count = os_area_flash_write(db, sizeof(struct os_area_db), pos);
if (count < sizeof(struct os_area_db)) {
pr_debug("%s: os_area_flash_write failed %zd\n", __func__,
count);
error = count < 0 ? count : -EIO;
}
fail:
kfree(header);
return error;
}
static void os_area_queue_work_handler(struct work_struct *work)
{
struct device_node *node;
int error;
pr_debug(" -> %s:%d\n", __func__, __LINE__);
node = of_find_node_by_path("/");
if (node) {
os_area_set_property(node, &property_rtc_diff);
of_node_put(node);
} else
pr_debug("%s:%d of_find_node_by_path failed\n",
__func__, __LINE__);
error = update_flash_db();
if (error)
pr_warning("%s: Could not update FLASH ROM\n", __func__);
pr_debug(" <- %s:%d\n", __func__, __LINE__);
}
static void os_area_queue_work(void)
{
static DECLARE_WORK(q, os_area_queue_work_handler);
wmb();
schedule_work(&q);
}
void __init ps3_os_area_save_params(void)
{
int result;
u64 lpar_addr;
unsigned int size;
struct os_area_header *header;
struct os_area_params *params;
struct os_area_db *db;
pr_debug(" -> %s:%d\n", __func__, __LINE__);
result = ps3_repository_read_boot_dat_info(&lpar_addr, &size);
if (result) {
pr_debug("%s:%d ps3_repository_read_boot_dat_info failed\n",
__func__, __LINE__);
return;
}
header = (struct os_area_header *)__va(lpar_addr);
params = (struct os_area_params *)__va(lpar_addr
+ OS_AREA_SEGMENT_SIZE);
result = verify_header(header);
if (result) {
pr_debug("%s:%d verify_header failed\n", __func__, __LINE__);
dump_header(header);
return;
}
db = (struct os_area_db *)__va(lpar_addr
+ header->db_area_offset * OS_AREA_SEGMENT_SIZE);
dump_header(header);
dump_params(params);
dump_db(db);
result = db_verify(db) || db_get_rtc_diff(db, &saved_params.rtc_diff);
if (result)
saved_params.rtc_diff = params->rtc_diff ? params->rtc_diff
: SECONDS_FROM_1970_TO_2000;
saved_params.av_multi_out = params->av_multi_out;
saved_params.valid = 1;
memset(header, 0, sizeof(*header));
pr_debug(" <- %s:%d\n", __func__, __LINE__);
}
void __init ps3_os_area_init(void)
{
struct device_node *node;
pr_debug(" -> %s:%d\n", __func__, __LINE__);
node = of_find_node_by_path("/");
if (!saved_params.valid && node) {
os_area_get_property(node, &property_rtc_diff);
os_area_get_property(node, &property_av_multi_out);
}
if(!saved_params.rtc_diff)
saved_params.rtc_diff = SECONDS_FROM_1970_TO_2000;
if (node) {
os_area_set_property(node, &property_rtc_diff);
os_area_set_property(node, &property_av_multi_out);
of_node_put(node);
} else
pr_debug("%s:%d of_find_node_by_path failed\n",
__func__, __LINE__);
pr_debug(" <- %s:%d\n", __func__, __LINE__);
}
u64 ps3_os_area_get_rtc_diff(void)
{
return saved_params.rtc_diff;
}
void ps3_os_area_set_rtc_diff(u64 rtc_diff)
{
if (saved_params.rtc_diff != rtc_diff) {
saved_params.rtc_diff = rtc_diff;
os_area_queue_work();
}
}
enum ps3_param_av_multi_out ps3_os_area_get_av_multi_out(void)
{
return saved_params.av_multi_out;
}
