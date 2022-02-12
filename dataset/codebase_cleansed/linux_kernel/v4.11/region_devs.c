static int nvdimm_map_flush(struct device *dev, struct nvdimm *nvdimm, int dimm,
struct nd_region_data *ndrd)
{
int i, j;
dev_dbg(dev, "%s: map %d flush address%s\n", nvdimm_name(nvdimm),
nvdimm->num_flush, nvdimm->num_flush == 1 ? "" : "es");
for (i = 0; i < (1 << ndrd->hints_shift); i++) {
struct resource *res = &nvdimm->flush_wpq[i];
unsigned long pfn = PHYS_PFN(res->start);
void __iomem *flush_page;
for (j = 0; j < i; j++) {
struct resource *res_j = &nvdimm->flush_wpq[j];
unsigned long pfn_j = PHYS_PFN(res_j->start);
if (pfn == pfn_j)
break;
}
if (j < i)
flush_page = (void __iomem *) ((unsigned long)
ndrd_get_flush_wpq(ndrd, dimm, j)
& PAGE_MASK);
else
flush_page = devm_nvdimm_ioremap(dev,
PFN_PHYS(pfn), PAGE_SIZE);
if (!flush_page)
return -ENXIO;
ndrd_set_flush_wpq(ndrd, dimm, i, flush_page
+ (res->start & ~PAGE_MASK));
}
return 0;
}
int nd_region_activate(struct nd_region *nd_region)
{
int i, j, num_flush = 0;
struct nd_region_data *ndrd;
struct device *dev = &nd_region->dev;
size_t flush_data_size = sizeof(void *);
nvdimm_bus_lock(&nd_region->dev);
for (i = 0; i < nd_region->ndr_mappings; i++) {
struct nd_mapping *nd_mapping = &nd_region->mapping[i];
struct nvdimm *nvdimm = nd_mapping->nvdimm;
flush_data_size += sizeof(void *);
num_flush = min_not_zero(num_flush, nvdimm->num_flush);
if (!nvdimm->num_flush)
continue;
flush_data_size += nvdimm->num_flush * sizeof(void *);
}
nvdimm_bus_unlock(&nd_region->dev);
ndrd = devm_kzalloc(dev, sizeof(*ndrd) + flush_data_size, GFP_KERNEL);
if (!ndrd)
return -ENOMEM;
dev_set_drvdata(dev, ndrd);
if (!num_flush)
return 0;
ndrd->hints_shift = ilog2(num_flush);
for (i = 0; i < nd_region->ndr_mappings; i++) {
struct nd_mapping *nd_mapping = &nd_region->mapping[i];
struct nvdimm *nvdimm = nd_mapping->nvdimm;
int rc = nvdimm_map_flush(&nd_region->dev, nvdimm, i, ndrd);
if (rc)
return rc;
}
for (i = 0; i < nd_region->ndr_mappings - 1; i++) {
if (!ndrd_get_flush_wpq(ndrd, i, 0))
continue;
for (j = i + 1; j < nd_region->ndr_mappings; j++)
if (ndrd_get_flush_wpq(ndrd, i, 0) ==
ndrd_get_flush_wpq(ndrd, j, 0))
ndrd_set_flush_wpq(ndrd, j, 0, NULL);
}
return 0;
}
static void nd_region_release(struct device *dev)
{
struct nd_region *nd_region = to_nd_region(dev);
u16 i;
for (i = 0; i < nd_region->ndr_mappings; i++) {
struct nd_mapping *nd_mapping = &nd_region->mapping[i];
struct nvdimm *nvdimm = nd_mapping->nvdimm;
put_device(&nvdimm->dev);
}
free_percpu(nd_region->lane);
ida_simple_remove(&region_ida, nd_region->id);
if (is_nd_blk(dev))
kfree(to_nd_blk_region(dev));
else
kfree(nd_region);
}
bool is_nd_pmem(struct device *dev)
{
return dev ? dev->type == &nd_pmem_device_type : false;
}
bool is_nd_blk(struct device *dev)
{
return dev ? dev->type == &nd_blk_device_type : false;
}
struct nd_region *to_nd_region(struct device *dev)
{
struct nd_region *nd_region = container_of(dev, struct nd_region, dev);
WARN_ON(dev->type->release != nd_region_release);
return nd_region;
}
struct nd_blk_region *to_nd_blk_region(struct device *dev)
{
struct nd_region *nd_region = to_nd_region(dev);
WARN_ON(!is_nd_blk(dev));
return container_of(nd_region, struct nd_blk_region, nd_region);
}
void *nd_region_provider_data(struct nd_region *nd_region)
{
return nd_region->provider_data;
}
void *nd_blk_region_provider_data(struct nd_blk_region *ndbr)
{
return ndbr->blk_provider_data;
}
void nd_blk_region_set_provider_data(struct nd_blk_region *ndbr, void *data)
{
ndbr->blk_provider_data = data;
}
int nd_region_to_nstype(struct nd_region *nd_region)
{
if (is_nd_pmem(&nd_region->dev)) {
u16 i, alias;
for (i = 0, alias = 0; i < nd_region->ndr_mappings; i++) {
struct nd_mapping *nd_mapping = &nd_region->mapping[i];
struct nvdimm *nvdimm = nd_mapping->nvdimm;
if (nvdimm->flags & NDD_ALIASING)
alias++;
}
if (alias)
return ND_DEVICE_NAMESPACE_PMEM;
else
return ND_DEVICE_NAMESPACE_IO;
} else if (is_nd_blk(&nd_region->dev)) {
return ND_DEVICE_NAMESPACE_BLK;
}
return 0;
}
static ssize_t size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
unsigned long long size = 0;
if (is_nd_pmem(dev)) {
size = nd_region->ndr_size;
} else if (nd_region->ndr_mappings == 1) {
struct nd_mapping *nd_mapping = &nd_region->mapping[0];
size = nd_mapping->size;
}
return sprintf(buf, "%llu\n", size);
}
static ssize_t mappings_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
return sprintf(buf, "%d\n", nd_region->ndr_mappings);
}
static ssize_t nstype_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
return sprintf(buf, "%d\n", nd_region_to_nstype(nd_region));
}
static ssize_t set_cookie_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
struct nd_interleave_set *nd_set = nd_region->nd_set;
if (is_nd_pmem(dev) && nd_set)
;
else
return -ENXIO;
return sprintf(buf, "%#llx\n", nd_set->cookie);
}
resource_size_t nd_region_available_dpa(struct nd_region *nd_region)
{
resource_size_t blk_max_overlap = 0, available, overlap;
int i;
WARN_ON(!is_nvdimm_bus_locked(&nd_region->dev));
retry:
available = 0;
overlap = blk_max_overlap;
for (i = 0; i < nd_region->ndr_mappings; i++) {
struct nd_mapping *nd_mapping = &nd_region->mapping[i];
struct nvdimm_drvdata *ndd = to_ndd(nd_mapping);
if (!ndd)
return 0;
if (is_nd_pmem(&nd_region->dev)) {
available += nd_pmem_available_dpa(nd_region,
nd_mapping, &overlap);
if (overlap > blk_max_overlap) {
blk_max_overlap = overlap;
goto retry;
}
} else if (is_nd_blk(&nd_region->dev))
available += nd_blk_available_dpa(nd_region);
}
return available;
}
static ssize_t available_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
unsigned long long available = 0;
nvdimm_bus_lock(dev);
wait_nvdimm_bus_probe_idle(dev);
available = nd_region_available_dpa(nd_region);
nvdimm_bus_unlock(dev);
return sprintf(buf, "%llu\n", available);
}
static ssize_t init_namespaces_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region_data *ndrd = dev_get_drvdata(dev);
ssize_t rc;
nvdimm_bus_lock(dev);
if (ndrd)
rc = sprintf(buf, "%d/%d\n", ndrd->ns_active, ndrd->ns_count);
else
rc = -ENXIO;
nvdimm_bus_unlock(dev);
return rc;
}
static ssize_t namespace_seed_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
ssize_t rc;
nvdimm_bus_lock(dev);
if (nd_region->ns_seed)
rc = sprintf(buf, "%s\n", dev_name(nd_region->ns_seed));
else
rc = sprintf(buf, "\n");
nvdimm_bus_unlock(dev);
return rc;
}
static ssize_t btt_seed_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
ssize_t rc;
nvdimm_bus_lock(dev);
if (nd_region->btt_seed)
rc = sprintf(buf, "%s\n", dev_name(nd_region->btt_seed));
else
rc = sprintf(buf, "\n");
nvdimm_bus_unlock(dev);
return rc;
}
static ssize_t pfn_seed_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
ssize_t rc;
nvdimm_bus_lock(dev);
if (nd_region->pfn_seed)
rc = sprintf(buf, "%s\n", dev_name(nd_region->pfn_seed));
else
rc = sprintf(buf, "\n");
nvdimm_bus_unlock(dev);
return rc;
}
static ssize_t dax_seed_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
ssize_t rc;
nvdimm_bus_lock(dev);
if (nd_region->dax_seed)
rc = sprintf(buf, "%s\n", dev_name(nd_region->dax_seed));
else
rc = sprintf(buf, "\n");
nvdimm_bus_unlock(dev);
return rc;
}
static ssize_t read_only_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct nd_region *nd_region = to_nd_region(dev);
return sprintf(buf, "%d\n", nd_region->ro);
}
static ssize_t read_only_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t len)
{
bool ro;
int rc = strtobool(buf, &ro);
struct nd_region *nd_region = to_nd_region(dev);
if (rc)
return rc;
nd_region->ro = ro;
return len;
}
static umode_t region_visible(struct kobject *kobj, struct attribute *a, int n)
{
struct device *dev = container_of(kobj, typeof(*dev), kobj);
struct nd_region *nd_region = to_nd_region(dev);
struct nd_interleave_set *nd_set = nd_region->nd_set;
int type = nd_region_to_nstype(nd_region);
if (!is_nd_pmem(dev) && a == &dev_attr_pfn_seed.attr)
return 0;
if (!is_nd_pmem(dev) && a == &dev_attr_dax_seed.attr)
return 0;
if (a != &dev_attr_set_cookie.attr
&& a != &dev_attr_available_size.attr)
return a->mode;
if ((type == ND_DEVICE_NAMESPACE_PMEM
|| type == ND_DEVICE_NAMESPACE_BLK)
&& a == &dev_attr_available_size.attr)
return a->mode;
else if (is_nd_pmem(dev) && nd_set)
return a->mode;
return 0;
}
u64 nd_region_interleave_set_cookie(struct nd_region *nd_region)
{
struct nd_interleave_set *nd_set = nd_region->nd_set;
if (nd_set)
return nd_set->cookie;
return 0;
}
u64 nd_region_interleave_set_altcookie(struct nd_region *nd_region)
{
struct nd_interleave_set *nd_set = nd_region->nd_set;
if (nd_set)
return nd_set->altcookie;
return 0;
}
void nd_mapping_free_labels(struct nd_mapping *nd_mapping)
{
struct nd_label_ent *label_ent, *e;
lockdep_assert_held(&nd_mapping->lock);
list_for_each_entry_safe(label_ent, e, &nd_mapping->labels, list) {
list_del(&label_ent->list);
kfree(label_ent);
}
}
static void nd_region_notify_driver_action(struct nvdimm_bus *nvdimm_bus,
struct device *dev, bool probe)
{
struct nd_region *nd_region;
if (!probe && (is_nd_pmem(dev) || is_nd_blk(dev))) {
int i;
nd_region = to_nd_region(dev);
for (i = 0; i < nd_region->ndr_mappings; i++) {
struct nd_mapping *nd_mapping = &nd_region->mapping[i];
struct nvdimm_drvdata *ndd = nd_mapping->ndd;
struct nvdimm *nvdimm = nd_mapping->nvdimm;
mutex_lock(&nd_mapping->lock);
nd_mapping_free_labels(nd_mapping);
mutex_unlock(&nd_mapping->lock);
put_ndd(ndd);
nd_mapping->ndd = NULL;
if (ndd)
atomic_dec(&nvdimm->busy);
}
if (is_nd_pmem(dev))
return;
}
if (dev->parent && (is_nd_blk(dev->parent) || is_nd_pmem(dev->parent))
&& probe) {
nd_region = to_nd_region(dev->parent);
nvdimm_bus_lock(dev);
if (nd_region->ns_seed == dev)
nd_region_create_ns_seed(nd_region);
nvdimm_bus_unlock(dev);
}
if (is_nd_btt(dev) && probe) {
struct nd_btt *nd_btt = to_nd_btt(dev);
nd_region = to_nd_region(dev->parent);
nvdimm_bus_lock(dev);
if (nd_region->btt_seed == dev)
nd_region_create_btt_seed(nd_region);
if (nd_region->ns_seed == &nd_btt->ndns->dev)
nd_region_create_ns_seed(nd_region);
nvdimm_bus_unlock(dev);
}
if (is_nd_pfn(dev) && probe) {
struct nd_pfn *nd_pfn = to_nd_pfn(dev);
nd_region = to_nd_region(dev->parent);
nvdimm_bus_lock(dev);
if (nd_region->pfn_seed == dev)
nd_region_create_pfn_seed(nd_region);
if (nd_region->ns_seed == &nd_pfn->ndns->dev)
nd_region_create_ns_seed(nd_region);
nvdimm_bus_unlock(dev);
}
if (is_nd_dax(dev) && probe) {
struct nd_dax *nd_dax = to_nd_dax(dev);
nd_region = to_nd_region(dev->parent);
nvdimm_bus_lock(dev);
if (nd_region->dax_seed == dev)
nd_region_create_dax_seed(nd_region);
if (nd_region->ns_seed == &nd_dax->nd_pfn.ndns->dev)
nd_region_create_ns_seed(nd_region);
nvdimm_bus_unlock(dev);
}
}
void nd_region_probe_success(struct nvdimm_bus *nvdimm_bus, struct device *dev)
{
nd_region_notify_driver_action(nvdimm_bus, dev, true);
}
void nd_region_disable(struct nvdimm_bus *nvdimm_bus, struct device *dev)
{
nd_region_notify_driver_action(nvdimm_bus, dev, false);
}
static ssize_t mappingN(struct device *dev, char *buf, int n)
{
struct nd_region *nd_region = to_nd_region(dev);
struct nd_mapping *nd_mapping;
struct nvdimm *nvdimm;
if (n >= nd_region->ndr_mappings)
return -ENXIO;
nd_mapping = &nd_region->mapping[n];
nvdimm = nd_mapping->nvdimm;
return sprintf(buf, "%s,%llu,%llu\n", dev_name(&nvdimm->dev),
nd_mapping->start, nd_mapping->size);
}
static umode_t mapping_visible(struct kobject *kobj, struct attribute *a, int n)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nd_region *nd_region = to_nd_region(dev);
if (n < nd_region->ndr_mappings)
return a->mode;
return 0;
}
int nd_blk_region_init(struct nd_region *nd_region)
{
struct device *dev = &nd_region->dev;
struct nvdimm_bus *nvdimm_bus = walk_to_nvdimm_bus(dev);
if (!is_nd_blk(dev))
return 0;
if (nd_region->ndr_mappings < 1) {
dev_err(dev, "invalid BLK region\n");
return -ENXIO;
}
return to_nd_blk_region(dev)->enable(nvdimm_bus, dev);
}
unsigned int nd_region_acquire_lane(struct nd_region *nd_region)
{
unsigned int cpu, lane;
cpu = get_cpu();
if (nd_region->num_lanes < nr_cpu_ids) {
struct nd_percpu_lane *ndl_lock, *ndl_count;
lane = cpu % nd_region->num_lanes;
ndl_count = per_cpu_ptr(nd_region->lane, cpu);
ndl_lock = per_cpu_ptr(nd_region->lane, lane);
if (ndl_count->count++ == 0)
spin_lock(&ndl_lock->lock);
} else
lane = cpu;
return lane;
}
void nd_region_release_lane(struct nd_region *nd_region, unsigned int lane)
{
if (nd_region->num_lanes < nr_cpu_ids) {
unsigned int cpu = get_cpu();
struct nd_percpu_lane *ndl_lock, *ndl_count;
ndl_count = per_cpu_ptr(nd_region->lane, cpu);
ndl_lock = per_cpu_ptr(nd_region->lane, lane);
if (--ndl_count->count == 0)
spin_unlock(&ndl_lock->lock);
put_cpu();
}
put_cpu();
}
static struct nd_region *nd_region_create(struct nvdimm_bus *nvdimm_bus,
struct nd_region_desc *ndr_desc, struct device_type *dev_type,
const char *caller)
{
struct nd_region *nd_region;
struct device *dev;
void *region_buf;
unsigned int i;
int ro = 0;
for (i = 0; i < ndr_desc->num_mappings; i++) {
struct nd_mapping_desc *mapping = &ndr_desc->mapping[i];
struct nvdimm *nvdimm = mapping->nvdimm;
if ((mapping->start | mapping->size) % SZ_4K) {
dev_err(&nvdimm_bus->dev, "%s: %s mapping%d is not 4K aligned\n",
caller, dev_name(&nvdimm->dev), i);
return NULL;
}
if (nvdimm->flags & NDD_UNARMED)
ro = 1;
}
if (dev_type == &nd_blk_device_type) {
struct nd_blk_region_desc *ndbr_desc;
struct nd_blk_region *ndbr;
ndbr_desc = to_blk_region_desc(ndr_desc);
ndbr = kzalloc(sizeof(*ndbr) + sizeof(struct nd_mapping)
* ndr_desc->num_mappings,
GFP_KERNEL);
if (ndbr) {
nd_region = &ndbr->nd_region;
ndbr->enable = ndbr_desc->enable;
ndbr->do_io = ndbr_desc->do_io;
}
region_buf = ndbr;
} else {
nd_region = kzalloc(sizeof(struct nd_region)
+ sizeof(struct nd_mapping)
* ndr_desc->num_mappings,
GFP_KERNEL);
region_buf = nd_region;
}
if (!region_buf)
return NULL;
nd_region->id = ida_simple_get(&region_ida, 0, 0, GFP_KERNEL);
if (nd_region->id < 0)
goto err_id;
nd_region->lane = alloc_percpu(struct nd_percpu_lane);
if (!nd_region->lane)
goto err_percpu;
for (i = 0; i < nr_cpu_ids; i++) {
struct nd_percpu_lane *ndl;
ndl = per_cpu_ptr(nd_region->lane, i);
spin_lock_init(&ndl->lock);
ndl->count = 0;
}
for (i = 0; i < ndr_desc->num_mappings; i++) {
struct nd_mapping_desc *mapping = &ndr_desc->mapping[i];
struct nvdimm *nvdimm = mapping->nvdimm;
nd_region->mapping[i].nvdimm = nvdimm;
nd_region->mapping[i].start = mapping->start;
nd_region->mapping[i].size = mapping->size;
INIT_LIST_HEAD(&nd_region->mapping[i].labels);
mutex_init(&nd_region->mapping[i].lock);
get_device(&nvdimm->dev);
}
nd_region->ndr_mappings = ndr_desc->num_mappings;
nd_region->provider_data = ndr_desc->provider_data;
nd_region->nd_set = ndr_desc->nd_set;
nd_region->num_lanes = ndr_desc->num_lanes;
nd_region->flags = ndr_desc->flags;
nd_region->ro = ro;
nd_region->numa_node = ndr_desc->numa_node;
ida_init(&nd_region->ns_ida);
ida_init(&nd_region->btt_ida);
ida_init(&nd_region->pfn_ida);
ida_init(&nd_region->dax_ida);
dev = &nd_region->dev;
dev_set_name(dev, "region%d", nd_region->id);
dev->parent = &nvdimm_bus->dev;
dev->type = dev_type;
dev->groups = ndr_desc->attr_groups;
nd_region->ndr_size = resource_size(ndr_desc->res);
nd_region->ndr_start = ndr_desc->res->start;
nd_device_register(dev);
return nd_region;
err_percpu:
ida_simple_remove(&region_ida, nd_region->id);
err_id:
kfree(region_buf);
return NULL;
}
struct nd_region *nvdimm_pmem_region_create(struct nvdimm_bus *nvdimm_bus,
struct nd_region_desc *ndr_desc)
{
ndr_desc->num_lanes = ND_MAX_LANES;
return nd_region_create(nvdimm_bus, ndr_desc, &nd_pmem_device_type,
__func__);
}
struct nd_region *nvdimm_blk_region_create(struct nvdimm_bus *nvdimm_bus,
struct nd_region_desc *ndr_desc)
{
if (ndr_desc->num_mappings > 1)
return NULL;
ndr_desc->num_lanes = min(ndr_desc->num_lanes, ND_MAX_LANES);
return nd_region_create(nvdimm_bus, ndr_desc, &nd_blk_device_type,
__func__);
}
struct nd_region *nvdimm_volatile_region_create(struct nvdimm_bus *nvdimm_bus,
struct nd_region_desc *ndr_desc)
{
ndr_desc->num_lanes = ND_MAX_LANES;
return nd_region_create(nvdimm_bus, ndr_desc, &nd_volatile_device_type,
__func__);
}
void nvdimm_flush(struct nd_region *nd_region)
{
struct nd_region_data *ndrd = dev_get_drvdata(&nd_region->dev);
int i, idx;
idx = this_cpu_read(flush_idx);
idx = this_cpu_add_return(flush_idx, hash_32(current->pid + idx, 8));
wmb();
for (i = 0; i < nd_region->ndr_mappings; i++)
if (ndrd_get_flush_wpq(ndrd, i, 0))
writeq(1, ndrd_get_flush_wpq(ndrd, i, idx));
wmb();
}
int nvdimm_has_flush(struct nd_region *nd_region)
{
struct nd_region_data *ndrd = dev_get_drvdata(&nd_region->dev);
int i;
if (nd_region->ndr_mappings == 0)
return -ENXIO;
for (i = 0; i < nd_region->ndr_mappings; i++)
if (ndrd_get_flush_wpq(ndrd, i, 0))
return 1;
return 0;
}
void __exit nd_region_devs_exit(void)
{
ida_destroy(&region_ida);
}
