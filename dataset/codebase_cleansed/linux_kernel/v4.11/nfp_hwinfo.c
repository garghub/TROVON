static bool nfp_hwinfo_is_updating(struct nfp_hwinfo *hwinfo)
{
return le32_to_cpu(hwinfo->version) & NFP_HWINFO_VERSION_UPDATING;
}
static int
hwinfo_db_walk(struct nfp_cpp *cpp, struct nfp_hwinfo *hwinfo, u32 size)
{
const char *key, *val, *end = hwinfo->data + size;
for (key = hwinfo->data; *key && key < end;
key = val + strlen(val) + 1) {
val = key + strlen(key) + 1;
if (val >= end) {
nfp_warn(cpp, "Bad HWINFO - overflowing key\n");
return -EINVAL;
}
if (val + strlen(val) + 1 > end) {
nfp_warn(cpp, "Bad HWINFO - overflowing value\n");
return -EINVAL;
}
}
return 0;
}
static int
hwinfo_db_validate(struct nfp_cpp *cpp, struct nfp_hwinfo *db, u32 len)
{
u32 size, crc;
size = le32_to_cpu(db->size);
if (size > len) {
nfp_err(cpp, "Unsupported hwinfo size %u > %u\n", size, len);
return -EINVAL;
}
size -= sizeof(u32);
crc = crc32_posix(db, size);
if (crc != get_unaligned_le32(db->start + size)) {
nfp_err(cpp, "Corrupt hwinfo table (CRC mismatch), calculated 0x%x, expected 0x%x\n",
crc, get_unaligned_le32(db->start + size));
return -EINVAL;
}
return hwinfo_db_walk(cpp, db, size);
}
static int hwinfo_try_fetch(struct nfp_cpp *cpp, size_t *cpp_size)
{
struct nfp_hwinfo *header;
struct nfp_resource *res;
u64 cpp_addr;
u32 cpp_id;
int err;
u8 *db;
res = nfp_resource_acquire(cpp, NFP_RESOURCE_NFP_HWINFO);
if (!IS_ERR(res)) {
cpp_id = nfp_resource_cpp_id(res);
cpp_addr = nfp_resource_address(res);
*cpp_size = nfp_resource_size(res);
nfp_resource_release(res);
if (*cpp_size < HWINFO_SIZE_MIN)
return -ENOENT;
} else if (PTR_ERR(res) == -ENOENT) {
cpp_id = NFP_CPP_ISLAND_ID(NFP_CPP_TARGET_MU,
NFP_CPP_ACTION_RW, 0, 1);
cpp_addr = 0x30000;
*cpp_size = 0x0e000;
} else {
return PTR_ERR(res);
}
db = kmalloc(*cpp_size + 1, GFP_KERNEL);
if (!db)
return -ENOMEM;
err = nfp_cpp_read(cpp, cpp_id, cpp_addr, db, *cpp_size);
if (err != *cpp_size) {
kfree(db);
return err < 0 ? err : -EIO;
}
header = (void *)db;
if (nfp_hwinfo_is_updating(header)) {
kfree(db);
return -EBUSY;
}
if (le32_to_cpu(header->version) != NFP_HWINFO_VERSION_2) {
nfp_err(cpp, "Unknown HWInfo version: 0x%08x\n",
le32_to_cpu(header->version));
kfree(db);
return -EINVAL;
}
db[*cpp_size] = '\0';
nfp_hwinfo_cache_set(cpp, db);
return 0;
}
static int hwinfo_fetch(struct nfp_cpp *cpp, size_t *hwdb_size)
{
const unsigned long wait_until = jiffies + HWINFO_WAIT * HZ;
int err;
for (;;) {
const unsigned long start_time = jiffies;
err = hwinfo_try_fetch(cpp, hwdb_size);
if (!err)
return 0;
err = msleep_interruptible(100);
if (err || time_after(start_time, wait_until)) {
nfp_err(cpp, "NFP access error\n");
return -EIO;
}
}
}
static int nfp_hwinfo_load(struct nfp_cpp *cpp)
{
struct nfp_hwinfo *db;
size_t hwdb_size = 0;
int err;
err = hwinfo_fetch(cpp, &hwdb_size);
if (err)
return err;
db = nfp_hwinfo_cache(cpp);
err = hwinfo_db_validate(cpp, db, hwdb_size);
if (err) {
kfree(db);
nfp_hwinfo_cache_set(cpp, NULL);
return err;
}
return 0;
}
const char *nfp_hwinfo_lookup(struct nfp_cpp *cpp, const char *lookup)
{
const char *key, *val, *end;
struct nfp_hwinfo *hwinfo;
int err;
hwinfo = nfp_hwinfo_cache(cpp);
if (!hwinfo) {
err = nfp_hwinfo_load(cpp);
if (err)
return NULL;
hwinfo = nfp_hwinfo_cache(cpp);
}
if (!hwinfo || !lookup)
return NULL;
end = hwinfo->data + le32_to_cpu(hwinfo->size) - sizeof(u32);
for (key = hwinfo->data; *key && key < end;
key = val + strlen(val) + 1) {
val = key + strlen(key) + 1;
if (strcmp(key, lookup) == 0)
return val;
}
return NULL;
}
