static inline bool dma_debug_disabled(void)
{
return global_disable || !dma_debug_initialized;
}
static inline void dump_entry_trace(struct dma_debug_entry *entry)
{
#ifdef CONFIG_STACKTRACE
if (entry) {
pr_warning("Mapped at:\n");
print_stack_trace(&entry->stacktrace, 0);
}
#endif
}
static bool driver_filter(struct device *dev)
{
struct device_driver *drv;
unsigned long flags;
bool ret;
if (likely(!current_driver_name[0]))
return true;
if (current_driver && dev && dev->driver == current_driver)
return true;
if (!dev)
return false;
if (current_driver || !current_driver_name[0])
return false;
drv = dev->driver;
if (!drv)
return false;
read_lock_irqsave(&driver_name_lock, flags);
ret = false;
if (drv->name &&
strncmp(current_driver_name, drv->name, NAME_MAX_LEN - 1) == 0) {
current_driver = drv;
ret = true;
}
read_unlock_irqrestore(&driver_name_lock, flags);
return ret;
}
static int hash_fn(struct dma_debug_entry *entry)
{
return (entry->dev_addr >> HASH_FN_SHIFT) & HASH_FN_MASK;
}
static struct hash_bucket *get_hash_bucket(struct dma_debug_entry *entry,
unsigned long *flags)
{
int idx = hash_fn(entry);
unsigned long __flags;
spin_lock_irqsave(&dma_entry_hash[idx].lock, __flags);
*flags = __flags;
return &dma_entry_hash[idx];
}
static void put_hash_bucket(struct hash_bucket *bucket,
unsigned long *flags)
{
unsigned long __flags = *flags;
spin_unlock_irqrestore(&bucket->lock, __flags);
}
static bool exact_match(struct dma_debug_entry *a, struct dma_debug_entry *b)
{
return ((a->dev_addr == b->dev_addr) &&
(a->dev == b->dev)) ? true : false;
}
static bool containing_match(struct dma_debug_entry *a,
struct dma_debug_entry *b)
{
if (a->dev != b->dev)
return false;
if ((b->dev_addr <= a->dev_addr) &&
((b->dev_addr + b->size) >= (a->dev_addr + a->size)))
return true;
return false;
}
static struct dma_debug_entry *__hash_bucket_find(struct hash_bucket *bucket,
struct dma_debug_entry *ref,
match_fn match)
{
struct dma_debug_entry *entry, *ret = NULL;
int matches = 0, match_lvl, last_lvl = -1;
list_for_each_entry(entry, &bucket->list, list) {
if (!match(ref, entry))
continue;
matches += 1;
match_lvl = 0;
entry->size == ref->size ? ++match_lvl : 0;
entry->type == ref->type ? ++match_lvl : 0;
entry->direction == ref->direction ? ++match_lvl : 0;
entry->sg_call_ents == ref->sg_call_ents ? ++match_lvl : 0;
if (match_lvl == 4) {
return entry;
} else if (match_lvl > last_lvl) {
last_lvl = match_lvl;
ret = entry;
}
}
ret = (matches == 1) ? ret : NULL;
return ret;
}
static struct dma_debug_entry *bucket_find_exact(struct hash_bucket *bucket,
struct dma_debug_entry *ref)
{
return __hash_bucket_find(bucket, ref, exact_match);
}
static struct dma_debug_entry *bucket_find_contain(struct hash_bucket **bucket,
struct dma_debug_entry *ref,
unsigned long *flags)
{
unsigned int max_range = dma_get_max_seg_size(ref->dev);
struct dma_debug_entry *entry, index = *ref;
unsigned int range = 0;
while (range <= max_range) {
entry = __hash_bucket_find(*bucket, ref, containing_match);
if (entry)
return entry;
put_hash_bucket(*bucket, flags);
range += (1 << HASH_FN_SHIFT);
index.dev_addr -= (1 << HASH_FN_SHIFT);
*bucket = get_hash_bucket(&index, flags);
}
return NULL;
}
static void hash_bucket_add(struct hash_bucket *bucket,
struct dma_debug_entry *entry)
{
list_add_tail(&entry->list, &bucket->list);
}
static void hash_bucket_del(struct dma_debug_entry *entry)
{
list_del(&entry->list);
}
static unsigned long long phys_addr(struct dma_debug_entry *entry)
{
return page_to_phys(pfn_to_page(entry->pfn)) + entry->offset;
}
void debug_dma_dump_mappings(struct device *dev)
{
int idx;
for (idx = 0; idx < HASH_SIZE; idx++) {
struct hash_bucket *bucket = &dma_entry_hash[idx];
struct dma_debug_entry *entry;
unsigned long flags;
spin_lock_irqsave(&bucket->lock, flags);
list_for_each_entry(entry, &bucket->list, list) {
if (!dev || dev == entry->dev) {
dev_info(entry->dev,
"%s idx %d P=%Lx N=%lx D=%Lx L=%Lx %s %s\n",
type2name[entry->type], idx,
phys_addr(entry), entry->pfn,
entry->dev_addr, entry->size,
dir2name[entry->direction],
maperr2str[entry->map_err_type]);
}
}
spin_unlock_irqrestore(&bucket->lock, flags);
}
}
static phys_addr_t to_cacheline_number(struct dma_debug_entry *entry)
{
return (entry->pfn << CACHELINE_PER_PAGE_SHIFT) +
(entry->offset >> L1_CACHE_SHIFT);
}
static int active_cacheline_read_overlap(phys_addr_t cln)
{
int overlap = 0, i;
for (i = RADIX_TREE_MAX_TAGS - 1; i >= 0; i--)
if (radix_tree_tag_get(&dma_active_cacheline, cln, i))
overlap |= 1 << i;
return overlap;
}
static int active_cacheline_set_overlap(phys_addr_t cln, int overlap)
{
int i;
if (overlap > ACTIVE_CACHELINE_MAX_OVERLAP || overlap < 0)
return overlap;
for (i = RADIX_TREE_MAX_TAGS - 1; i >= 0; i--)
if (overlap & 1 << i)
radix_tree_tag_set(&dma_active_cacheline, cln, i);
else
radix_tree_tag_clear(&dma_active_cacheline, cln, i);
return overlap;
}
static void active_cacheline_inc_overlap(phys_addr_t cln)
{
int overlap = active_cacheline_read_overlap(cln);
overlap = active_cacheline_set_overlap(cln, ++overlap);
WARN_ONCE(overlap > ACTIVE_CACHELINE_MAX_OVERLAP,
"DMA-API: exceeded %d overlapping mappings of cacheline %pa\n",
ACTIVE_CACHELINE_MAX_OVERLAP, &cln);
}
static int active_cacheline_dec_overlap(phys_addr_t cln)
{
int overlap = active_cacheline_read_overlap(cln);
return active_cacheline_set_overlap(cln, --overlap);
}
static int active_cacheline_insert(struct dma_debug_entry *entry)
{
phys_addr_t cln = to_cacheline_number(entry);
unsigned long flags;
int rc;
if (entry->direction == DMA_TO_DEVICE)
return 0;
spin_lock_irqsave(&radix_lock, flags);
rc = radix_tree_insert(&dma_active_cacheline, cln, entry);
if (rc == -EEXIST)
active_cacheline_inc_overlap(cln);
spin_unlock_irqrestore(&radix_lock, flags);
return rc;
}
static void active_cacheline_remove(struct dma_debug_entry *entry)
{
phys_addr_t cln = to_cacheline_number(entry);
unsigned long flags;
if (entry->direction == DMA_TO_DEVICE)
return;
spin_lock_irqsave(&radix_lock, flags);
if (active_cacheline_dec_overlap(cln) < 0)
radix_tree_delete(&dma_active_cacheline, cln);
spin_unlock_irqrestore(&radix_lock, flags);
}
void debug_dma_assert_idle(struct page *page)
{
static struct dma_debug_entry *ents[CACHELINES_PER_PAGE];
struct dma_debug_entry *entry = NULL;
void **results = (void **) &ents;
unsigned int nents, i;
unsigned long flags;
phys_addr_t cln;
if (dma_debug_disabled())
return;
if (!page)
return;
cln = (phys_addr_t) page_to_pfn(page) << CACHELINE_PER_PAGE_SHIFT;
spin_lock_irqsave(&radix_lock, flags);
nents = radix_tree_gang_lookup(&dma_active_cacheline, results, cln,
CACHELINES_PER_PAGE);
for (i = 0; i < nents; i++) {
phys_addr_t ent_cln = to_cacheline_number(ents[i]);
if (ent_cln == cln) {
entry = ents[i];
break;
} else if (ent_cln >= cln + CACHELINES_PER_PAGE)
break;
}
spin_unlock_irqrestore(&radix_lock, flags);
if (!entry)
return;
cln = to_cacheline_number(entry);
err_printk(entry->dev, entry,
"DMA-API: cpu touching an active dma mapped cacheline [cln=%pa]\n",
&cln);
}
static void add_dma_entry(struct dma_debug_entry *entry)
{
struct hash_bucket *bucket;
unsigned long flags;
int rc;
bucket = get_hash_bucket(entry, &flags);
hash_bucket_add(bucket, entry);
put_hash_bucket(bucket, &flags);
rc = active_cacheline_insert(entry);
if (rc == -ENOMEM) {
pr_err("DMA-API: cacheline tracking ENOMEM, dma-debug disabled\n");
global_disable = true;
}
}
static struct dma_debug_entry *__dma_entry_alloc(void)
{
struct dma_debug_entry *entry;
entry = list_entry(free_entries.next, struct dma_debug_entry, list);
list_del(&entry->list);
memset(entry, 0, sizeof(*entry));
num_free_entries -= 1;
if (num_free_entries < min_free_entries)
min_free_entries = num_free_entries;
return entry;
}
static struct dma_debug_entry *dma_entry_alloc(void)
{
struct dma_debug_entry *entry;
unsigned long flags;
spin_lock_irqsave(&free_entries_lock, flags);
if (list_empty(&free_entries)) {
pr_err("DMA-API: debugging out of memory - disabling\n");
global_disable = true;
spin_unlock_irqrestore(&free_entries_lock, flags);
return NULL;
}
entry = __dma_entry_alloc();
spin_unlock_irqrestore(&free_entries_lock, flags);
#ifdef CONFIG_STACKTRACE
entry->stacktrace.max_entries = DMA_DEBUG_STACKTRACE_ENTRIES;
entry->stacktrace.entries = entry->st_entries;
entry->stacktrace.skip = 2;
save_stack_trace(&entry->stacktrace);
#endif
return entry;
}
static void dma_entry_free(struct dma_debug_entry *entry)
{
unsigned long flags;
active_cacheline_remove(entry);
spin_lock_irqsave(&free_entries_lock, flags);
list_add(&entry->list, &free_entries);
num_free_entries += 1;
spin_unlock_irqrestore(&free_entries_lock, flags);
}
int dma_debug_resize_entries(u32 num_entries)
{
int i, delta, ret = 0;
unsigned long flags;
struct dma_debug_entry *entry;
LIST_HEAD(tmp);
spin_lock_irqsave(&free_entries_lock, flags);
if (nr_total_entries < num_entries) {
delta = num_entries - nr_total_entries;
spin_unlock_irqrestore(&free_entries_lock, flags);
for (i = 0; i < delta; i++) {
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
break;
list_add_tail(&entry->list, &tmp);
}
spin_lock_irqsave(&free_entries_lock, flags);
list_splice(&tmp, &free_entries);
nr_total_entries += i;
num_free_entries += i;
} else {
delta = nr_total_entries - num_entries;
for (i = 0; i < delta && !list_empty(&free_entries); i++) {
entry = __dma_entry_alloc();
kfree(entry);
}
nr_total_entries -= i;
}
if (nr_total_entries != num_entries)
ret = 1;
spin_unlock_irqrestore(&free_entries_lock, flags);
return ret;
}
static int prealloc_memory(u32 num_entries)
{
struct dma_debug_entry *entry, *next_entry;
int i;
for (i = 0; i < num_entries; ++i) {
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
goto out_err;
list_add_tail(&entry->list, &free_entries);
}
num_free_entries = num_entries;
min_free_entries = num_entries;
pr_info("DMA-API: preallocated %d debug entries\n", num_entries);
return 0;
out_err:
list_for_each_entry_safe(entry, next_entry, &free_entries, list) {
list_del(&entry->list);
kfree(entry);
}
return -ENOMEM;
}
static ssize_t filter_read(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
char buf[NAME_MAX_LEN + 1];
unsigned long flags;
int len;
if (!current_driver_name[0])
return 0;
read_lock_irqsave(&driver_name_lock, flags);
len = scnprintf(buf, NAME_MAX_LEN + 1, "%s\n", current_driver_name);
read_unlock_irqrestore(&driver_name_lock, flags);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t filter_write(struct file *file, const char __user *userbuf,
size_t count, loff_t *ppos)
{
char buf[NAME_MAX_LEN];
unsigned long flags;
size_t len;
int i;
len = min(count, (size_t)(NAME_MAX_LEN - 1));
if (copy_from_user(buf, userbuf, len))
return -EFAULT;
buf[len] = 0;
write_lock_irqsave(&driver_name_lock, flags);
if (!isalnum(buf[0])) {
if (current_driver_name[0])
pr_info("DMA-API: switching off dma-debug driver filter\n");
current_driver_name[0] = 0;
current_driver = NULL;
goto out_unlock;
}
for (i = 0; i < NAME_MAX_LEN - 1; ++i) {
current_driver_name[i] = buf[i];
if (isspace(buf[i]) || buf[i] == ' ' || buf[i] == 0)
break;
}
current_driver_name[i] = 0;
current_driver = NULL;
pr_info("DMA-API: enable driver filter for driver [%s]\n",
current_driver_name);
out_unlock:
write_unlock_irqrestore(&driver_name_lock, flags);
return count;
}
static int dma_debug_fs_init(void)
{
dma_debug_dent = debugfs_create_dir("dma-api", NULL);
if (!dma_debug_dent) {
pr_err("DMA-API: can not create debugfs directory\n");
return -ENOMEM;
}
global_disable_dent = debugfs_create_bool("disabled", 0444,
dma_debug_dent,
&global_disable);
if (!global_disable_dent)
goto out_err;
error_count_dent = debugfs_create_u32("error_count", 0444,
dma_debug_dent, &error_count);
if (!error_count_dent)
goto out_err;
show_all_errors_dent = debugfs_create_u32("all_errors", 0644,
dma_debug_dent,
&show_all_errors);
if (!show_all_errors_dent)
goto out_err;
show_num_errors_dent = debugfs_create_u32("num_errors", 0644,
dma_debug_dent,
&show_num_errors);
if (!show_num_errors_dent)
goto out_err;
num_free_entries_dent = debugfs_create_u32("num_free_entries", 0444,
dma_debug_dent,
&num_free_entries);
if (!num_free_entries_dent)
goto out_err;
min_free_entries_dent = debugfs_create_u32("min_free_entries", 0444,
dma_debug_dent,
&min_free_entries);
if (!min_free_entries_dent)
goto out_err;
filter_dent = debugfs_create_file("driver_filter", 0644,
dma_debug_dent, NULL, &filter_fops);
if (!filter_dent)
goto out_err;
return 0;
out_err:
debugfs_remove_recursive(dma_debug_dent);
return -ENOMEM;
}
static int device_dma_allocations(struct device *dev, struct dma_debug_entry **out_entry)
{
struct dma_debug_entry *entry;
unsigned long flags;
int count = 0, i;
local_irq_save(flags);
for (i = 0; i < HASH_SIZE; ++i) {
spin_lock(&dma_entry_hash[i].lock);
list_for_each_entry(entry, &dma_entry_hash[i].list, list) {
if (entry->dev == dev) {
count += 1;
*out_entry = entry;
}
}
spin_unlock(&dma_entry_hash[i].lock);
}
local_irq_restore(flags);
return count;
}
static int dma_debug_device_change(struct notifier_block *nb, unsigned long action, void *data)
{
struct device *dev = data;
struct dma_debug_entry *uninitialized_var(entry);
int count;
if (dma_debug_disabled())
return 0;
switch (action) {
case BUS_NOTIFY_UNBOUND_DRIVER:
count = device_dma_allocations(dev, &entry);
if (count == 0)
break;
err_printk(dev, entry, "DMA-API: device driver has pending "
"DMA allocations while released from device "
"[count=%d]\n"
"One of leaked entries details: "
"[device address=0x%016llx] [size=%llu bytes] "
"[mapped with %s] [mapped as %s]\n",
count, entry->dev_addr, entry->size,
dir2name[entry->direction], type2name[entry->type]);
break;
default:
break;
}
return 0;
}
void dma_debug_add_bus(struct bus_type *bus)
{
struct notifier_block *nb;
if (dma_debug_disabled())
return;
nb = kzalloc(sizeof(struct notifier_block), GFP_KERNEL);
if (nb == NULL) {
pr_err("dma_debug_add_bus: out of memory\n");
return;
}
nb->notifier_call = dma_debug_device_change;
bus_register_notifier(bus, nb);
}
void dma_debug_init(u32 num_entries)
{
int i;
if (global_disable)
return;
for (i = 0; i < HASH_SIZE; ++i) {
INIT_LIST_HEAD(&dma_entry_hash[i].list);
spin_lock_init(&dma_entry_hash[i].lock);
}
if (dma_debug_fs_init() != 0) {
pr_err("DMA-API: error creating debugfs entries - disabling\n");
global_disable = true;
return;
}
if (req_entries)
num_entries = req_entries;
if (prealloc_memory(num_entries) != 0) {
pr_err("DMA-API: debugging out of memory error - disabled\n");
global_disable = true;
return;
}
nr_total_entries = num_free_entries;
dma_debug_initialized = true;
pr_info("DMA-API: debugging enabled by kernel config\n");
}
static __init int dma_debug_cmdline(char *str)
{
if (!str)
return -EINVAL;
if (strncmp(str, "off", 3) == 0) {
pr_info("DMA-API: debugging disabled on kernel command line\n");
global_disable = true;
}
return 0;
}
static __init int dma_debug_entries_cmdline(char *str)
{
int res;
if (!str)
return -EINVAL;
res = get_option(&str, &req_entries);
if (!res)
req_entries = 0;
return 0;
}
static void check_unmap(struct dma_debug_entry *ref)
{
struct dma_debug_entry *entry;
struct hash_bucket *bucket;
unsigned long flags;
bucket = get_hash_bucket(ref, &flags);
entry = bucket_find_exact(bucket, ref);
if (!entry) {
put_hash_bucket(bucket, &flags);
if (dma_mapping_error(ref->dev, ref->dev_addr)) {
err_printk(ref->dev, NULL,
"DMA-API: device driver tries to free an "
"invalid DMA memory address\n");
} else {
err_printk(ref->dev, NULL,
"DMA-API: device driver tries to free DMA "
"memory it has not allocated [device "
"address=0x%016llx] [size=%llu bytes]\n",
ref->dev_addr, ref->size);
}
return;
}
if (ref->size != entry->size) {
err_printk(ref->dev, entry, "DMA-API: device driver frees "
"DMA memory with different size "
"[device address=0x%016llx] [map size=%llu bytes] "
"[unmap size=%llu bytes]\n",
ref->dev_addr, entry->size, ref->size);
}
if (ref->type != entry->type) {
err_printk(ref->dev, entry, "DMA-API: device driver frees "
"DMA memory with wrong function "
"[device address=0x%016llx] [size=%llu bytes] "
"[mapped as %s] [unmapped as %s]\n",
ref->dev_addr, ref->size,
type2name[entry->type], type2name[ref->type]);
} else if ((entry->type == dma_debug_coherent) &&
(phys_addr(ref) != phys_addr(entry))) {
err_printk(ref->dev, entry, "DMA-API: device driver frees "
"DMA memory with different CPU address "
"[device address=0x%016llx] [size=%llu bytes] "
"[cpu alloc address=0x%016llx] "
"[cpu free address=0x%016llx]",
ref->dev_addr, ref->size,
phys_addr(entry),
phys_addr(ref));
}
if (ref->sg_call_ents && ref->type == dma_debug_sg &&
ref->sg_call_ents != entry->sg_call_ents) {
err_printk(ref->dev, entry, "DMA-API: device driver frees "
"DMA sg list with different entry count "
"[map count=%d] [unmap count=%d]\n",
entry->sg_call_ents, ref->sg_call_ents);
}
if (ref->direction != entry->direction) {
err_printk(ref->dev, entry, "DMA-API: device driver frees "
"DMA memory with different direction "
"[device address=0x%016llx] [size=%llu bytes] "
"[mapped with %s] [unmapped with %s]\n",
ref->dev_addr, ref->size,
dir2name[entry->direction],
dir2name[ref->direction]);
}
if (entry->map_err_type == MAP_ERR_NOT_CHECKED) {
err_printk(ref->dev, entry,
"DMA-API: device driver failed to check map error"
"[device address=0x%016llx] [size=%llu bytes] "
"[mapped as %s]",
ref->dev_addr, ref->size,
type2name[entry->type]);
}
hash_bucket_del(entry);
dma_entry_free(entry);
put_hash_bucket(bucket, &flags);
}
static void check_for_stack(struct device *dev, void *addr)
{
if (object_is_on_stack(addr))
err_printk(dev, NULL, "DMA-API: device driver maps memory from "
"stack [addr=%p]\n", addr);
}
static inline bool overlap(void *addr, unsigned long len, void *start, void *end)
{
unsigned long a1 = (unsigned long)addr;
unsigned long b1 = a1 + len;
unsigned long a2 = (unsigned long)start;
unsigned long b2 = (unsigned long)end;
return !(b1 <= a2 || a1 >= b2);
}
static void check_for_illegal_area(struct device *dev, void *addr, unsigned long len)
{
if (overlap(addr, len, _text, _etext) ||
overlap(addr, len, __start_rodata, __end_rodata))
err_printk(dev, NULL, "DMA-API: device driver maps memory from kernel text or rodata [addr=%p] [len=%lu]\n", addr, len);
}
static void check_sync(struct device *dev,
struct dma_debug_entry *ref,
bool to_cpu)
{
struct dma_debug_entry *entry;
struct hash_bucket *bucket;
unsigned long flags;
bucket = get_hash_bucket(ref, &flags);
entry = bucket_find_contain(&bucket, ref, &flags);
if (!entry) {
err_printk(dev, NULL, "DMA-API: device driver tries "
"to sync DMA memory it has not allocated "
"[device address=0x%016llx] [size=%llu bytes]\n",
(unsigned long long)ref->dev_addr, ref->size);
goto out;
}
if (ref->size > entry->size) {
err_printk(dev, entry, "DMA-API: device driver syncs"
" DMA memory outside allocated range "
"[device address=0x%016llx] "
"[allocation size=%llu bytes] "
"[sync offset+size=%llu]\n",
entry->dev_addr, entry->size,
ref->size);
}
if (entry->direction == DMA_BIDIRECTIONAL)
goto out;
if (ref->direction != entry->direction) {
err_printk(dev, entry, "DMA-API: device driver syncs "
"DMA memory with different direction "
"[device address=0x%016llx] [size=%llu bytes] "
"[mapped with %s] [synced with %s]\n",
(unsigned long long)ref->dev_addr, entry->size,
dir2name[entry->direction],
dir2name[ref->direction]);
}
if (to_cpu && !(entry->direction == DMA_FROM_DEVICE) &&
!(ref->direction == DMA_TO_DEVICE))
err_printk(dev, entry, "DMA-API: device driver syncs "
"device read-only DMA memory for cpu "
"[device address=0x%016llx] [size=%llu bytes] "
"[mapped with %s] [synced with %s]\n",
(unsigned long long)ref->dev_addr, entry->size,
dir2name[entry->direction],
dir2name[ref->direction]);
if (!to_cpu && !(entry->direction == DMA_TO_DEVICE) &&
!(ref->direction == DMA_FROM_DEVICE))
err_printk(dev, entry, "DMA-API: device driver syncs "
"device write-only DMA memory to device "
"[device address=0x%016llx] [size=%llu bytes] "
"[mapped with %s] [synced with %s]\n",
(unsigned long long)ref->dev_addr, entry->size,
dir2name[entry->direction],
dir2name[ref->direction]);
out:
put_hash_bucket(bucket, &flags);
}
void debug_dma_map_page(struct device *dev, struct page *page, size_t offset,
size_t size, int direction, dma_addr_t dma_addr,
bool map_single)
{
struct dma_debug_entry *entry;
if (unlikely(dma_debug_disabled()))
return;
if (dma_mapping_error(dev, dma_addr))
return;
entry = dma_entry_alloc();
if (!entry)
return;
entry->dev = dev;
entry->type = dma_debug_page;
entry->pfn = page_to_pfn(page);
entry->offset = offset,
entry->dev_addr = dma_addr;
entry->size = size;
entry->direction = direction;
entry->map_err_type = MAP_ERR_NOT_CHECKED;
if (map_single)
entry->type = dma_debug_single;
if (!PageHighMem(page)) {
void *addr = page_address(page) + offset;
check_for_stack(dev, addr);
check_for_illegal_area(dev, addr, size);
}
add_dma_entry(entry);
}
void debug_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
struct dma_debug_entry ref;
struct dma_debug_entry *entry;
struct hash_bucket *bucket;
unsigned long flags;
if (unlikely(dma_debug_disabled()))
return;
ref.dev = dev;
ref.dev_addr = dma_addr;
bucket = get_hash_bucket(&ref, &flags);
list_for_each_entry(entry, &bucket->list, list) {
if (!exact_match(&ref, entry))
continue;
if (entry->map_err_type == MAP_ERR_NOT_CHECKED) {
entry->map_err_type = MAP_ERR_CHECKED;
break;
}
}
put_hash_bucket(bucket, &flags);
}
void debug_dma_unmap_page(struct device *dev, dma_addr_t addr,
size_t size, int direction, bool map_single)
{
struct dma_debug_entry ref = {
.type = dma_debug_page,
.dev = dev,
.dev_addr = addr,
.size = size,
.direction = direction,
};
if (unlikely(dma_debug_disabled()))
return;
if (map_single)
ref.type = dma_debug_single;
check_unmap(&ref);
}
void debug_dma_map_sg(struct device *dev, struct scatterlist *sg,
int nents, int mapped_ents, int direction)
{
struct dma_debug_entry *entry;
struct scatterlist *s;
int i;
if (unlikely(dma_debug_disabled()))
return;
for_each_sg(sg, s, mapped_ents, i) {
entry = dma_entry_alloc();
if (!entry)
return;
entry->type = dma_debug_sg;
entry->dev = dev;
entry->pfn = page_to_pfn(sg_page(s));
entry->offset = s->offset,
entry->size = sg_dma_len(s);
entry->dev_addr = sg_dma_address(s);
entry->direction = direction;
entry->sg_call_ents = nents;
entry->sg_mapped_ents = mapped_ents;
if (!PageHighMem(sg_page(s))) {
check_for_stack(dev, sg_virt(s));
check_for_illegal_area(dev, sg_virt(s), sg_dma_len(s));
}
add_dma_entry(entry);
}
}
static int get_nr_mapped_entries(struct device *dev,
struct dma_debug_entry *ref)
{
struct dma_debug_entry *entry;
struct hash_bucket *bucket;
unsigned long flags;
int mapped_ents;
bucket = get_hash_bucket(ref, &flags);
entry = bucket_find_exact(bucket, ref);
mapped_ents = 0;
if (entry)
mapped_ents = entry->sg_mapped_ents;
put_hash_bucket(bucket, &flags);
return mapped_ents;
}
void debug_dma_unmap_sg(struct device *dev, struct scatterlist *sglist,
int nelems, int dir)
{
struct scatterlist *s;
int mapped_ents = 0, i;
if (unlikely(dma_debug_disabled()))
return;
for_each_sg(sglist, s, nelems, i) {
struct dma_debug_entry ref = {
.type = dma_debug_sg,
.dev = dev,
.pfn = page_to_pfn(sg_page(s)),
.offset = s->offset,
.dev_addr = sg_dma_address(s),
.size = sg_dma_len(s),
.direction = dir,
.sg_call_ents = nelems,
};
if (mapped_ents && i >= mapped_ents)
break;
if (!i)
mapped_ents = get_nr_mapped_entries(dev, &ref);
check_unmap(&ref);
}
}
void debug_dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t dma_addr, void *virt)
{
struct dma_debug_entry *entry;
if (unlikely(dma_debug_disabled()))
return;
if (unlikely(virt == NULL))
return;
entry = dma_entry_alloc();
if (!entry)
return;
entry->type = dma_debug_coherent;
entry->dev = dev;
entry->pfn = page_to_pfn(virt_to_page(virt));
entry->offset = (size_t) virt & PAGE_MASK;
entry->size = size;
entry->dev_addr = dma_addr;
entry->direction = DMA_BIDIRECTIONAL;
add_dma_entry(entry);
}
void debug_dma_free_coherent(struct device *dev, size_t size,
void *virt, dma_addr_t addr)
{
struct dma_debug_entry ref = {
.type = dma_debug_coherent,
.dev = dev,
.pfn = page_to_pfn(virt_to_page(virt)),
.offset = (size_t) virt & PAGE_MASK,
.dev_addr = addr,
.size = size,
.direction = DMA_BIDIRECTIONAL,
};
if (unlikely(dma_debug_disabled()))
return;
check_unmap(&ref);
}
void debug_dma_sync_single_for_cpu(struct device *dev, dma_addr_t dma_handle,
size_t size, int direction)
{
struct dma_debug_entry ref;
if (unlikely(dma_debug_disabled()))
return;
ref.type = dma_debug_single;
ref.dev = dev;
ref.dev_addr = dma_handle;
ref.size = size;
ref.direction = direction;
ref.sg_call_ents = 0;
check_sync(dev, &ref, true);
}
void debug_dma_sync_single_for_device(struct device *dev,
dma_addr_t dma_handle, size_t size,
int direction)
{
struct dma_debug_entry ref;
if (unlikely(dma_debug_disabled()))
return;
ref.type = dma_debug_single;
ref.dev = dev;
ref.dev_addr = dma_handle;
ref.size = size;
ref.direction = direction;
ref.sg_call_ents = 0;
check_sync(dev, &ref, false);
}
void debug_dma_sync_single_range_for_cpu(struct device *dev,
dma_addr_t dma_handle,
unsigned long offset, size_t size,
int direction)
{
struct dma_debug_entry ref;
if (unlikely(dma_debug_disabled()))
return;
ref.type = dma_debug_single;
ref.dev = dev;
ref.dev_addr = dma_handle;
ref.size = offset + size;
ref.direction = direction;
ref.sg_call_ents = 0;
check_sync(dev, &ref, true);
}
void debug_dma_sync_single_range_for_device(struct device *dev,
dma_addr_t dma_handle,
unsigned long offset,
size_t size, int direction)
{
struct dma_debug_entry ref;
if (unlikely(dma_debug_disabled()))
return;
ref.type = dma_debug_single;
ref.dev = dev;
ref.dev_addr = dma_handle;
ref.size = offset + size;
ref.direction = direction;
ref.sg_call_ents = 0;
check_sync(dev, &ref, false);
}
void debug_dma_sync_sg_for_cpu(struct device *dev, struct scatterlist *sg,
int nelems, int direction)
{
struct scatterlist *s;
int mapped_ents = 0, i;
if (unlikely(dma_debug_disabled()))
return;
for_each_sg(sg, s, nelems, i) {
struct dma_debug_entry ref = {
.type = dma_debug_sg,
.dev = dev,
.pfn = page_to_pfn(sg_page(s)),
.offset = s->offset,
.dev_addr = sg_dma_address(s),
.size = sg_dma_len(s),
.direction = direction,
.sg_call_ents = nelems,
};
if (!i)
mapped_ents = get_nr_mapped_entries(dev, &ref);
if (i >= mapped_ents)
break;
check_sync(dev, &ref, true);
}
}
void debug_dma_sync_sg_for_device(struct device *dev, struct scatterlist *sg,
int nelems, int direction)
{
struct scatterlist *s;
int mapped_ents = 0, i;
if (unlikely(dma_debug_disabled()))
return;
for_each_sg(sg, s, nelems, i) {
struct dma_debug_entry ref = {
.type = dma_debug_sg,
.dev = dev,
.pfn = page_to_pfn(sg_page(s)),
.offset = s->offset,
.dev_addr = sg_dma_address(s),
.size = sg_dma_len(s),
.direction = direction,
.sg_call_ents = nelems,
};
if (!i)
mapped_ents = get_nr_mapped_entries(dev, &ref);
if (i >= mapped_ents)
break;
check_sync(dev, &ref, false);
}
}
static int __init dma_debug_driver_setup(char *str)
{
int i;
for (i = 0; i < NAME_MAX_LEN - 1; ++i, ++str) {
current_driver_name[i] = *str;
if (*str == 0)
break;
}
if (current_driver_name[0])
pr_info("DMA-API: enable driver filter for driver [%s]\n",
current_driver_name);
return 1;
}
