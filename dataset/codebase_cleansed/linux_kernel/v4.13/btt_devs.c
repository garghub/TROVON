static void nd_btt_release(struct device *dev)
{
struct nd_region *nd_region = to_nd_region(dev->parent);
struct nd_btt *nd_btt = to_nd_btt(dev);
dev_dbg(dev, "%s\n", __func__);
nd_detach_ndns(&nd_btt->dev, &nd_btt->ndns);
ida_simple_remove(&nd_region->btt_ida, nd_btt->id);
kfree(nd_btt->uuid);
kfree(nd_btt);
}
bool is_nd_btt(struct device *dev)
{
return dev->type == &nd_btt_device_type;
}
struct nd_btt *to_nd_btt(struct device *dev)
{
struct nd_btt *nd_btt = container_of(dev, struct nd_btt, dev);
WARN_ON(!is_nd_btt(dev));
return nd_btt;
}
static ssize_t sector_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_btt *nd_btt = to_nd_btt(dev);
return nd_sector_size_show(nd_btt->lbasize, btt_lbasize_supported, buf);
}
static ssize_t sector_size_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct nd_btt *nd_btt = to_nd_btt(dev);
ssize_t rc;
device_lock(dev);
nvdimm_bus_lock(dev);
rc = nd_sector_size_store(dev, buf, &nd_btt->lbasize,
btt_lbasize_supported);
dev_dbg(dev, "%s: result: %zd wrote: %s%s", __func__,
rc, buf, buf[len - 1] == '\n' ? "" : "\n");
nvdimm_bus_unlock(dev);
device_unlock(dev);
return rc ? rc : len;
}
static ssize_t uuid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_btt *nd_btt = to_nd_btt(dev);
if (nd_btt->uuid)
return sprintf(buf, "%pUb\n", nd_btt->uuid);
return sprintf(buf, "\n");
}
static ssize_t uuid_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct nd_btt *nd_btt = to_nd_btt(dev);
ssize_t rc;
device_lock(dev);
rc = nd_uuid_store(dev, &nd_btt->uuid, buf, len);
dev_dbg(dev, "%s: result: %zd wrote: %s%s", __func__,
rc, buf, buf[len - 1] == '\n' ? "" : "\n");
device_unlock(dev);
return rc ? rc : len;
}
static ssize_t namespace_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_btt *nd_btt = to_nd_btt(dev);
ssize_t rc;
nvdimm_bus_lock(dev);
rc = sprintf(buf, "%s\n", nd_btt->ndns
? dev_name(&nd_btt->ndns->dev) : "");
nvdimm_bus_unlock(dev);
return rc;
}
static ssize_t namespace_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
struct nd_btt *nd_btt = to_nd_btt(dev);
ssize_t rc;
device_lock(dev);
nvdimm_bus_lock(dev);
rc = nd_namespace_store(dev, &nd_btt->ndns, buf, len);
dev_dbg(dev, "%s: result: %zd wrote: %s%s", __func__,
rc, buf, buf[len - 1] == '\n' ? "" : "\n");
nvdimm_bus_unlock(dev);
device_unlock(dev);
return rc;
}
static ssize_t size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_btt *nd_btt = to_nd_btt(dev);
ssize_t rc;
device_lock(dev);
if (dev->driver)
rc = sprintf(buf, "%llu\n", nd_btt->size);
else {
rc = -ENXIO;
}
device_unlock(dev);
return rc;
}
static struct device *__nd_btt_create(struct nd_region *nd_region,
unsigned long lbasize, u8 *uuid,
struct nd_namespace_common *ndns)
{
struct nd_btt *nd_btt;
struct device *dev;
nd_btt = kzalloc(sizeof(*nd_btt), GFP_KERNEL);
if (!nd_btt)
return NULL;
nd_btt->id = ida_simple_get(&nd_region->btt_ida, 0, 0, GFP_KERNEL);
if (nd_btt->id < 0) {
kfree(nd_btt);
return NULL;
}
nd_btt->lbasize = lbasize;
if (uuid)
uuid = kmemdup(uuid, 16, GFP_KERNEL);
nd_btt->uuid = uuid;
dev = &nd_btt->dev;
dev_set_name(dev, "btt%d.%d", nd_region->id, nd_btt->id);
dev->parent = &nd_region->dev;
dev->type = &nd_btt_device_type;
dev->groups = nd_btt_attribute_groups;
device_initialize(&nd_btt->dev);
if (ndns && !__nd_attach_ndns(&nd_btt->dev, ndns, &nd_btt->ndns)) {
dev_dbg(&ndns->dev, "%s failed, already claimed by %s\n",
__func__, dev_name(ndns->claim));
put_device(dev);
return NULL;
}
return dev;
}
struct device *nd_btt_create(struct nd_region *nd_region)
{
struct device *dev = __nd_btt_create(nd_region, 0, NULL, NULL);
__nd_device_register(dev);
return dev;
}
bool nd_btt_arena_is_valid(struct nd_btt *nd_btt, struct btt_sb *super)
{
const u8 *parent_uuid = nd_dev_to_uuid(&nd_btt->ndns->dev);
u64 checksum;
if (memcmp(super->signature, BTT_SIG, BTT_SIG_LEN) != 0)
return false;
if (!guid_is_null((guid_t *)&super->parent_uuid))
if (memcmp(super->parent_uuid, parent_uuid, 16) != 0)
return false;
checksum = le64_to_cpu(super->checksum);
super->checksum = 0;
if (checksum != nd_sb_checksum((struct nd_gen_sb *) super))
return false;
super->checksum = cpu_to_le64(checksum);
if ((le32_to_cpu(super->flags) & IB_FLAG_ERROR_MASK) != 0)
dev_info(&nd_btt->dev, "Found arena with an error flag\n");
return true;
}
int nd_btt_version(struct nd_btt *nd_btt, struct nd_namespace_common *ndns,
struct btt_sb *btt_sb)
{
if (ndns->claim_class == NVDIMM_CCLASS_BTT2) {
nd_btt->initial_offset = 0;
nd_btt->version_major = 2;
nd_btt->version_minor = 0;
if (nvdimm_read_bytes(ndns, 0, btt_sb, sizeof(*btt_sb), 0))
return -ENXIO;
if (!nd_btt_arena_is_valid(nd_btt, btt_sb))
return -ENODEV;
if ((le16_to_cpu(btt_sb->version_major) != 2) ||
(le16_to_cpu(btt_sb->version_minor) != 0))
return -ENODEV;
} else {
nd_btt->initial_offset = SZ_4K;
nd_btt->version_major = 1;
nd_btt->version_minor = 1;
if (nvdimm_read_bytes(ndns, SZ_4K, btt_sb, sizeof(*btt_sb), 0))
return -ENXIO;
if (!nd_btt_arena_is_valid(nd_btt, btt_sb))
return -ENODEV;
if ((le16_to_cpu(btt_sb->version_major) != 1) ||
(le16_to_cpu(btt_sb->version_minor) != 1))
return -ENODEV;
}
return 0;
}
static int __nd_btt_probe(struct nd_btt *nd_btt,
struct nd_namespace_common *ndns, struct btt_sb *btt_sb)
{
int rc;
if (!btt_sb || !ndns || !nd_btt)
return -ENODEV;
if (nvdimm_namespace_capacity(ndns) < SZ_16M)
return -ENXIO;
rc = nd_btt_version(nd_btt, ndns, btt_sb);
if (rc < 0)
return rc;
nd_btt->lbasize = le32_to_cpu(btt_sb->external_lbasize);
nd_btt->uuid = kmemdup(btt_sb->uuid, 16, GFP_KERNEL);
if (!nd_btt->uuid)
return -ENOMEM;
__nd_device_register(&nd_btt->dev);
return 0;
}
int nd_btt_probe(struct device *dev, struct nd_namespace_common *ndns)
{
int rc;
struct device *btt_dev;
struct btt_sb *btt_sb;
struct nd_region *nd_region = to_nd_region(ndns->dev.parent);
if (ndns->force_raw)
return -ENODEV;
switch (ndns->claim_class) {
case NVDIMM_CCLASS_NONE:
case NVDIMM_CCLASS_BTT:
case NVDIMM_CCLASS_BTT2:
break;
default:
return -ENODEV;
}
nvdimm_bus_lock(&ndns->dev);
btt_dev = __nd_btt_create(nd_region, 0, NULL, ndns);
nvdimm_bus_unlock(&ndns->dev);
if (!btt_dev)
return -ENOMEM;
btt_sb = devm_kzalloc(dev, sizeof(*btt_sb), GFP_KERNEL);
rc = __nd_btt_probe(to_nd_btt(btt_dev), ndns, btt_sb);
dev_dbg(dev, "%s: btt: %s\n", __func__,
rc == 0 ? dev_name(btt_dev) : "<none>");
if (rc < 0) {
struct nd_btt *nd_btt = to_nd_btt(btt_dev);
nd_detach_ndns(btt_dev, &nd_btt->ndns);
put_device(btt_dev);
}
return rc;
}
