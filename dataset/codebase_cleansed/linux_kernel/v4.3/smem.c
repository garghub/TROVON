static int qcom_smem_alloc_private(struct qcom_smem *smem,
unsigned host,
unsigned item,
size_t size)
{
struct smem_partition_header *phdr;
struct smem_private_entry *hdr;
size_t alloc_size;
void *p;
phdr = smem->partitions[host];
p = (void *)phdr + sizeof(*phdr);
while (p < (void *)phdr + phdr->offset_free_uncached) {
hdr = p;
if (hdr->canary != SMEM_PRIVATE_CANARY) {
dev_err(smem->dev,
"Found invalid canary in host %d partition\n",
host);
return -EINVAL;
}
if (hdr->item == item)
return -EEXIST;
p += sizeof(*hdr) + hdr->padding_hdr + hdr->size;
}
alloc_size = sizeof(*hdr) + ALIGN(size, 8);
if (p + alloc_size >= (void *)phdr + phdr->offset_free_cached) {
dev_err(smem->dev, "Out of memory\n");
return -ENOSPC;
}
hdr = p;
hdr->canary = SMEM_PRIVATE_CANARY;
hdr->item = item;
hdr->size = ALIGN(size, 8);
hdr->padding_data = hdr->size - size;
hdr->padding_hdr = 0;
wmb();
phdr->offset_free_uncached += alloc_size;
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
if (WARN_ON(size > header->available))
return -ENOMEM;
entry->offset = header->free_offset;
entry->size = size;
wmb();
entry->allocated = 1;
header->free_offset += size;
header->available -= size;
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
static int qcom_smem_get_global(struct qcom_smem *smem,
unsigned item,
void **ptr,
size_t *size)
{
struct smem_header *header;
struct smem_region *area;
struct smem_global_entry *entry;
u32 aux_base;
unsigned i;
if (WARN_ON(item >= SMEM_ITEM_COUNT))
return -EINVAL;
header = smem->regions[0].virt_base;
entry = &header->toc[item];
if (!entry->allocated)
return -ENXIO;
if (ptr != NULL) {
aux_base = entry->aux_base & AUX_BASE_MASK;
for (i = 0; i < smem->num_regions; i++) {
area = &smem->regions[i];
if (area->aux_base == aux_base || !aux_base) {
*ptr = area->virt_base + entry->offset;
break;
}
}
}
if (size != NULL)
*size = entry->size;
return 0;
}
static int qcom_smem_get_private(struct qcom_smem *smem,
unsigned host,
unsigned item,
void **ptr,
size_t *size)
{
struct smem_partition_header *phdr;
struct smem_private_entry *hdr;
void *p;
phdr = smem->partitions[host];
p = (void *)phdr + sizeof(*phdr);
while (p < (void *)phdr + phdr->offset_free_uncached) {
hdr = p;
if (hdr->canary != SMEM_PRIVATE_CANARY) {
dev_err(smem->dev,
"Found invalid canary in host %d partition\n",
host);
return -EINVAL;
}
if (hdr->item == item) {
if (ptr != NULL)
*ptr = p + sizeof(*hdr) + hdr->padding_hdr;
if (size != NULL)
*size = hdr->size - hdr->padding_data;
return 0;
}
p += sizeof(*hdr) + hdr->padding_hdr + hdr->size;
}
return -ENOENT;
}
int qcom_smem_get(unsigned host, unsigned item, void **ptr, size_t *size)
{
unsigned long flags;
int ret;
if (!__smem)
return -EPROBE_DEFER;
ret = hwspin_lock_timeout_irqsave(__smem->hwlock,
HWSPINLOCK_TIMEOUT,
&flags);
if (ret)
return ret;
if (host < SMEM_HOST_COUNT && __smem->partitions[host])
ret = qcom_smem_get_private(__smem, host, item, ptr, size);
else
ret = qcom_smem_get_global(__smem, item, ptr, size);
hwspin_unlock_irqrestore(__smem->hwlock, &flags);
return ret;
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
ret = phdr->offset_free_cached - phdr->offset_free_uncached;
} else {
header = __smem->regions[0].virt_base;
ret = header->available;
}
return ret;
}
static int qcom_smem_get_sbl_version(struct qcom_smem *smem)
{
unsigned *versions;
size_t size;
int ret;
ret = qcom_smem_get_global(smem, SMEM_ITEM_VERSION,
(void **)&versions, &size);
if (ret < 0) {
dev_err(smem->dev, "Unable to read the version item\n");
return -ENOENT;
}
if (size < sizeof(unsigned) * SMEM_MASTER_SBL_VERSION_INDEX) {
dev_err(smem->dev, "Version item is too small\n");
return -EINVAL;
}
return versions[SMEM_MASTER_SBL_VERSION_INDEX];
}
static int qcom_smem_enumerate_partitions(struct qcom_smem *smem,
unsigned local_host)
{
struct smem_partition_header *header;
struct smem_ptable_entry *entry;
struct smem_ptable *ptable;
unsigned remote_host;
int i;
ptable = smem->regions[0].virt_base + smem->regions[0].size - SZ_4K;
if (ptable->magic != SMEM_PTABLE_MAGIC)
return 0;
if (ptable->version != 1) {
dev_err(smem->dev,
"Unsupported partition header version %d\n",
ptable->version);
return -EINVAL;
}
for (i = 0; i < ptable->num_entries; i++) {
entry = &ptable->entry[i];
if (entry->host0 != local_host && entry->host1 != local_host)
continue;
if (!entry->offset)
continue;
if (!entry->size)
continue;
if (entry->host0 == local_host)
remote_host = entry->host1;
else
remote_host = entry->host0;
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
header = smem->regions[0].virt_base + entry->offset;
if (header->magic != SMEM_PART_MAGIC) {
dev_err(smem->dev,
"Partition %d has invalid magic\n", i);
return -EINVAL;
}
if (header->host0 != local_host && header->host1 != local_host) {
dev_err(smem->dev,
"Partition %d hosts are invalid\n", i);
return -EINVAL;
}
if (header->host0 != remote_host && header->host1 != remote_host) {
dev_err(smem->dev,
"Partition %d hosts are invalid\n", i);
return -EINVAL;
}
if (header->size != entry->size) {
dev_err(smem->dev,
"Partition %d has invalid size\n", i);
return -EINVAL;
}
if (header->offset_free_uncached > header->size) {
dev_err(smem->dev,
"Partition %d has invalid free pointer\n", i);
return -EINVAL;
}
smem->partitions[remote_host] = header;
}
return 0;
}
static int qcom_smem_count_mem_regions(struct platform_device *pdev)
{
struct resource *res;
int num_regions = 0;
int i;
for (i = 0; i < pdev->num_resources; i++) {
res = &pdev->resource[i];
if (resource_type(res) == IORESOURCE_MEM)
num_regions++;
}
return num_regions;
}
static int qcom_smem_probe(struct platform_device *pdev)
{
struct smem_header *header;
struct device_node *np;
struct qcom_smem *smem;
struct resource *res;
struct resource r;
size_t array_size;
int num_regions = 0;
int hwlock_id;
u32 version;
int ret;
int i;
num_regions = qcom_smem_count_mem_regions(pdev) + 1;
array_size = num_regions * sizeof(struct smem_region);
smem = devm_kzalloc(&pdev->dev, sizeof(*smem) + array_size, GFP_KERNEL);
if (!smem)
return -ENOMEM;
smem->dev = &pdev->dev;
smem->num_regions = num_regions;
np = of_parse_phandle(pdev->dev.of_node, "memory-region", 0);
if (!np) {
dev_err(&pdev->dev, "No memory-region specified\n");
return -EINVAL;
}
ret = of_address_to_resource(np, 0, &r);
of_node_put(np);
if (ret)
return ret;
smem->regions[0].aux_base = (u32)r.start;
smem->regions[0].size = resource_size(&r);
smem->regions[0].virt_base = devm_ioremap_nocache(&pdev->dev,
r.start,
resource_size(&r));
if (!smem->regions[0].virt_base)
return -ENOMEM;
for (i = 1; i < num_regions; i++) {
res = platform_get_resource(pdev, IORESOURCE_MEM, i - 1);
smem->regions[i].aux_base = (u32)res->start;
smem->regions[i].size = resource_size(res);
smem->regions[i].virt_base = devm_ioremap_nocache(&pdev->dev,
res->start,
resource_size(res));
if (!smem->regions[i].virt_base)
return -ENOMEM;
}
header = smem->regions[0].virt_base;
if (header->initialized != 1 || header->reserved) {
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
__smem = NULL;
hwspin_lock_free(__smem->hwlock);
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
