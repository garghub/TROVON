static struct smem_private_entry *
phdr_to_last_private_entry(struct smem_partition_header *phdr)
{
void *p = phdr;
return p + le32_to_cpu(phdr->offset_free_uncached);
}
static void *phdr_to_first_cached_entry(struct smem_partition_header *phdr)
{
void *p = phdr;
return p + le32_to_cpu(phdr->offset_free_cached);
}
static struct smem_private_entry *
phdr_to_first_private_entry(struct smem_partition_header *phdr)
{
void *p = phdr;
return p + sizeof(*phdr);
}
static struct smem_private_entry *
private_entry_next(struct smem_private_entry *e)
{
void *p = e;
return p + sizeof(*e) + le16_to_cpu(e->padding_hdr) +
le32_to_cpu(e->size);
}
static void *entry_to_item(struct smem_private_entry *e)
{
void *p = e;
return p + sizeof(*e) + le16_to_cpu(e->padding_hdr);
}
static int qcom_smem_alloc_private(struct qcom_smem *smem,
unsigned host,
unsigned item,
size_t size)
{
struct smem_partition_header *phdr;
struct smem_private_entry *hdr, *end;
size_t alloc_size;
void *cached;
phdr = smem->partitions[host];
hdr = phdr_to_first_private_entry(phdr);
end = phdr_to_last_private_entry(phdr);
cached = phdr_to_first_cached_entry(phdr);
while (hdr < end) {
if (hdr->canary != SMEM_PRIVATE_CANARY) {
dev_err(smem->dev,
"Found invalid canary in host %d partition\n",
host);
return -EINVAL;
}
if (le16_to_cpu(hdr->item) == item)
return -EEXIST;
hdr = private_entry_next(hdr);
}
alloc_size = sizeof(*hdr) + ALIGN(size, 8);
if ((void *)hdr + alloc_size >= cached) {
dev_err(smem->dev, "Out of memory\n");
return -ENOSPC;
}
hdr->canary = SMEM_PRIVATE_CANARY;
hdr->item = cpu_to_le16(item);
hdr->size = cpu_to_le32(ALIGN(size, 8));
hdr->padding_data = cpu_to_le16(le32_to_cpu(hdr->size) - size);
hdr->padding_hdr = 0;
wmb();
le32_add_cpu(&phdr->offset_free_uncached, alloc_size);
return 0;
}
static int qcom_smem_alloc_global(struct qcom_smem *smem,
unsigned item,
size_t size)
{
struct smem_header *header;
struct smem_global_entry *entry;
if (WARN_ON(item >= SMEM_ITEM_COUNT))
return -EINVAL;
header = smem->regions[0].virt_base;
entry = &header->toc[item];
if (entry->allocated)
return -EEXIST;
size = ALIGN(size, 8);
if (WARN_ON(size > le32_to_cpu(header->available)))
return -ENOMEM;
entry->offset = header->free_offset;
entry->size = cpu_to_le32(size);
wmb();
entry->allocated = cpu_to_le32(1);
le32_add_cpu(&header->free_offset, size);
le32_add_cpu(&header->available, -size);
return 0;
}
int qcom_smem_alloc(unsigned host, unsigned item, size_t size)
{
unsigned long flags;
int ret;
if (!__smem)
return -EPROBE_DEFER;
if (item < SMEM_ITEM_LAST_FIXED) {
dev_err(__smem->dev,
"Rejecting allocation of static entry %d\n", item);
return -EINVAL;
}
ret = hwspin_lock_timeout_irqsave(__smem->hwlock,
HWSPINLOCK_TIMEOUT,
&flags);
if (ret)
return ret;
if (host < SMEM_HOST_COUNT && __smem->partitions[host])
ret = qcom_smem_alloc_private(__smem, host, item, size);
else
ret = qcom_smem_alloc_global(__smem, item, size);
hwspin_unlock_irqrestore(__smem->hwlock, &flags);
return ret;
}
static void *qcom_smem_get_global(struct qcom_smem *smem,
unsigned item,
size_t *size)
{
struct smem_header *header;
struct smem_region *area;
struct smem_global_entry *entry;
u32 aux_base;
unsigned i;
if (WARN_ON(item >= SMEM_ITEM_COUNT))
return ERR_PTR(-EINVAL);
header = smem->regions[0].virt_base;
entry = &header->toc[item];
if (!entry->allocated)
return ERR_PTR(-ENXIO);
aux_base = le32_to_cpu(entry->aux_base) & AUX_BASE_MASK;
for (i = 0; i < smem->num_regions; i++) {
area = &smem->regions[i];
if (area->aux_base == aux_base || !aux_base) {
if (size != NULL)
*size = le32_to_cpu(entry->size);
return area->virt_base + le32_to_cpu(entry->offset);
}
}
return ERR_PTR(-ENOENT);
}
static void *qcom_smem_get_private(struct qcom_smem *smem,
unsigned host,
unsigned item,
size_t *size)
{
struct smem_partition_header *phdr;
struct smem_private_entry *e, *end;
phdr = smem->partitions[host];
e = phdr_to_first_private_entry(phdr);
end = phdr_to_last_private_entry(phdr);
while (e < end) {
if (e->canary != SMEM_PRIVATE_CANARY) {
dev_err(smem->dev,
"Found invalid canary in host %d partition\n",
host);
return ERR_PTR(-EINVAL);
}
if (le16_to_cpu(e->item) == item) {
if (size != NULL)
*size = le32_to_cpu(e->size) -
le16_to_cpu(e->padding_data);
return entry_to_item(e);
}
e = private_entry_next(e);
}
return ERR_PTR(-ENOENT);
}
void *qcom_smem_get(unsigned host, unsigned item, size_t *size)
{
unsigned long flags;
int ret;
void *ptr = ERR_PTR(-EPROBE_DEFER);
if (!__smem)
return ptr;
ret = hwspin_lock_timeout_irqsave(__smem->hwlock,
HWSPINLOCK_TIMEOUT,
&flags);
if (ret)
return ERR_PTR(ret);
if (host < SMEM_HOST_COUNT && __smem->partitions[host])
ptr = qcom_smem_get_private(__smem, host, item, size);
else
ptr = qcom_smem_get_global(__smem, item, size);
hwspin_unlock_irqrestore(__smem->hwlock, &flags);
return ptr;
}
int qcom_smem_get_free_space(unsigned host)
{
struct smem_partition_header *phdr;
struct smem_header *header;
unsigned ret;
if (!__smem)
return -EPROBE_DEFER;
if (host < SMEM_HOST_COUNT && __smem->partitions[host]) {
phdr = __smem->partitions[host];
ret = le32_to_cpu(phdr->offset_free_cached) -
le32_to_cpu(phdr->offset_free_uncached);
} else {
header = __smem->regions[0].virt_base;
ret = le32_to_cpu(header->available);
}
return ret;
}
static int qcom_smem_get_sbl_version(struct qcom_smem *smem)
{
__le32 *versions;
size_t size;
versions = qcom_smem_get_global(smem, SMEM_ITEM_VERSION, &size);
if (IS_ERR(versions)) {
dev_err(smem->dev, "Unable to read the version item\n");
return -ENOENT;
}
if (size < sizeof(unsigned) * SMEM_MASTER_SBL_VERSION_INDEX) {
dev_err(smem->dev, "Version item is too small\n");
return -EINVAL;
}
return le32_to_cpu(versions[SMEM_MASTER_SBL_VERSION_INDEX]);
}
static int qcom_smem_enumerate_partitions(struct qcom_smem *smem,
unsigned local_host)
{
struct smem_partition_header *header;
struct smem_ptable_entry *entry;
struct smem_ptable *ptable;
unsigned remote_host;
u32 version, host0, host1;
int i;
ptable = smem->regions[0].virt_base + smem->regions[0].size - SZ_4K;
if (memcmp(ptable->magic, SMEM_PTABLE_MAGIC, sizeof(ptable->magic)))
return 0;
version = le32_to_cpu(ptable->version);
if (version != 1) {
dev_err(smem->dev,
"Unsupported partition header version %d\n", version);
return -EINVAL;
}
for (i = 0; i < le32_to_cpu(ptable->num_entries); i++) {
entry = &ptable->entry[i];
host0 = le16_to_cpu(entry->host0);
host1 = le16_to_cpu(entry->host1);
if (host0 != local_host && host1 != local_host)
continue;
if (!le32_to_cpu(entry->offset))
continue;
if (!le32_to_cpu(entry->size))
continue;
if (host0 == local_host)
remote_host = host1;
else
remote_host = host0;
if (remote_host >= SMEM_HOST_COUNT) {
dev_err(smem->dev,
"Invalid remote host %d\n",
remote_host);
return -EINVAL;
}
if (smem->partitions[remote_host]) {
dev_err(smem->dev,
"Already found a partition for host %d\n",
remote_host);
return -EINVAL;
}
header = smem->regions[0].virt_base + le32_to_cpu(entry->offset);
host0 = le16_to_cpu(header->host0);
host1 = le16_to_cpu(header->host1);
if (memcmp(header->magic, SMEM_PART_MAGIC,
sizeof(header->magic))) {
dev_err(smem->dev,
"Partition %d has invalid magic\n", i);
return -EINVAL;
}
if (host0 != local_host && host1 != local_host) {
dev_err(smem->dev,
"Partition %d hosts are invalid\n", i);
return -EINVAL;
}
if (host0 != remote_host && host1 != remote_host) {
dev_err(smem->dev,
"Partition %d hosts are invalid\n", i);
return -EINVAL;
}
if (header->size != entry->size) {
dev_err(smem->dev,
"Partition %d has invalid size\n", i);
return -EINVAL;
}
if (le32_to_cpu(header->offset_free_uncached) > le32_to_cpu(header->size)) {
dev_err(smem->dev,
"Partition %d has invalid free pointer\n", i);
return -EINVAL;
}
smem->partitions[remote_host] = header;
}
return 0;
}
static int qcom_smem_map_memory(struct qcom_smem *smem, struct device *dev,
const char *name, int i)
{
struct device_node *np;
struct resource r;
int ret;
np = of_parse_phandle(dev->of_node, name, 0);
if (!np) {
dev_err(dev, "No %s specified\n", name);
return -EINVAL;
}
ret = of_address_to_resource(np, 0, &r);
of_node_put(np);
if (ret)
return ret;
smem->regions[i].aux_base = (u32)r.start;
smem->regions[i].size = resource_size(&r);
smem->regions[i].virt_base = devm_ioremap_wc(dev, r.start, resource_size(&r));
if (!smem->regions[i].virt_base)
return -ENOMEM;
return 0;
}
static int qcom_smem_probe(struct platform_device *pdev)
{
struct smem_header *header;
struct qcom_smem *smem;
size_t array_size;
int num_regions;
int hwlock_id;
u32 version;
int ret;
num_regions = 1;
if (of_find_property(pdev->dev.of_node, "qcom,rpm-msg-ram", NULL))
num_regions++;
array_size = num_regions * sizeof(struct smem_region);
smem = devm_kzalloc(&pdev->dev, sizeof(*smem) + array_size, GFP_KERNEL);
if (!smem)
return -ENOMEM;
smem->dev = &pdev->dev;
smem->num_regions = num_regions;
ret = qcom_smem_map_memory(smem, &pdev->dev, "memory-region", 0);
if (ret)
return ret;
if (num_regions > 1 && (ret = qcom_smem_map_memory(smem, &pdev->dev,
"qcom,rpm-msg-ram", 1)))
return ret;
header = smem->regions[0].virt_base;
if (le32_to_cpu(header->initialized) != 1 ||
le32_to_cpu(header->reserved)) {
dev_err(&pdev->dev, "SMEM is not initialized by SBL\n");
return -EINVAL;
}
version = qcom_smem_get_sbl_version(smem);
if (version >> 16 != SMEM_EXPECTED_VERSION) {
dev_err(&pdev->dev, "Unsupported SMEM version 0x%x\n", version);
return -EINVAL;
}
ret = qcom_smem_enumerate_partitions(smem, SMEM_HOST_APPS);
if (ret < 0)
return ret;
hwlock_id = of_hwspin_lock_get_id(pdev->dev.of_node, 0);
if (hwlock_id < 0) {
dev_err(&pdev->dev, "failed to retrieve hwlock\n");
return hwlock_id;
}
smem->hwlock = hwspin_lock_request_specific(hwlock_id);
if (!smem->hwlock)
return -ENXIO;
__smem = smem;
return 0;
}
static int qcom_smem_remove(struct platform_device *pdev)
{
hwspin_lock_free(__smem->hwlock);
__smem = NULL;
return 0;
}
static int __init qcom_smem_init(void)
{
return platform_driver_register(&qcom_smem_driver);
}
static void __exit qcom_smem_exit(void)
{
platform_driver_unregister(&qcom_smem_driver);
}
