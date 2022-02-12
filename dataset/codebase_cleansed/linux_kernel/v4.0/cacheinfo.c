static struct cache_index_dir *kobj_to_cache_index_dir(struct kobject *k)
{
return container_of(k, struct cache_index_dir, kobj);
}
static const char *cache_type_string(const struct cache *cache)
{
return cache_type_info[cache->type].name;
}
static void cache_init(struct cache *cache, int type, int level,
struct device_node *ofnode)
{
cache->type = type;
cache->level = level;
cache->ofnode = of_node_get(ofnode);
INIT_LIST_HEAD(&cache->list);
list_add(&cache->list, &cache_list);
}
static struct cache *new_cache(int type, int level, struct device_node *ofnode)
{
struct cache *cache;
cache = kzalloc(sizeof(*cache), GFP_KERNEL);
if (cache)
cache_init(cache, type, level, ofnode);
return cache;
}
static void release_cache_debugcheck(struct cache *cache)
{
struct cache *iter;
list_for_each_entry(iter, &cache_list, list)
WARN_ONCE(iter->next_local == cache,
"cache for %s(%s) refers to cache for %s(%s)\n",
iter->ofnode->full_name,
cache_type_string(iter),
cache->ofnode->full_name,
cache_type_string(cache));
}
static void release_cache(struct cache *cache)
{
if (!cache)
return;
pr_debug("freeing L%d %s cache for %s\n", cache->level,
cache_type_string(cache), cache->ofnode->full_name);
release_cache_debugcheck(cache);
list_del(&cache->list);
of_node_put(cache->ofnode);
kfree(cache);
}
static void cache_cpu_set(struct cache *cache, int cpu)
{
struct cache *next = cache;
while (next) {
WARN_ONCE(cpumask_test_cpu(cpu, &next->shared_cpu_map),
"CPU %i already accounted in %s(%s)\n",
cpu, next->ofnode->full_name,
cache_type_string(next));
cpumask_set_cpu(cpu, &next->shared_cpu_map);
next = next->next_local;
}
}
static int cache_size(const struct cache *cache, unsigned int *ret)
{
const char *propname;
const __be32 *cache_size;
propname = cache_type_info[cache->type].size_prop;
cache_size = of_get_property(cache->ofnode, propname, NULL);
if (!cache_size)
return -ENODEV;
*ret = of_read_number(cache_size, 1);
return 0;
}
static int cache_size_kb(const struct cache *cache, unsigned int *ret)
{
unsigned int size;
if (cache_size(cache, &size))
return -ENODEV;
*ret = size / 1024;
return 0;
}
static int cache_get_line_size(const struct cache *cache, unsigned int *ret)
{
const __be32 *line_size;
int i, lim;
lim = ARRAY_SIZE(cache_type_info[cache->type].line_size_props);
for (i = 0; i < lim; i++) {
const char *propname;
propname = cache_type_info[cache->type].line_size_props[i];
line_size = of_get_property(cache->ofnode, propname, NULL);
if (line_size)
break;
}
if (!line_size)
return -ENODEV;
*ret = of_read_number(line_size, 1);
return 0;
}
static int cache_nr_sets(const struct cache *cache, unsigned int *ret)
{
const char *propname;
const __be32 *nr_sets;
propname = cache_type_info[cache->type].nr_sets_prop;
nr_sets = of_get_property(cache->ofnode, propname, NULL);
if (!nr_sets)
return -ENODEV;
*ret = of_read_number(nr_sets, 1);
return 0;
}
static int cache_associativity(const struct cache *cache, unsigned int *ret)
{
unsigned int line_size;
unsigned int nr_sets;
unsigned int size;
if (cache_nr_sets(cache, &nr_sets))
goto err;
if (nr_sets == 1) {
*ret = 0;
return 0;
}
if (cache_get_line_size(cache, &line_size))
goto err;
if (cache_size(cache, &size))
goto err;
if (!(nr_sets > 0 && size > 0 && line_size > 0))
goto err;
*ret = (size / nr_sets) / line_size;
return 0;
err:
return -ENODEV;
}
static struct cache *cache_find_first_sibling(struct cache *cache)
{
struct cache *iter;
if (cache->type == CACHE_TYPE_UNIFIED)
return cache;
list_for_each_entry(iter, &cache_list, list)
if (iter->ofnode == cache->ofnode && iter->next_local == cache)
return iter;
return cache;
}
static struct cache *cache_lookup_by_node(const struct device_node *node)
{
struct cache *cache = NULL;
struct cache *iter;
list_for_each_entry(iter, &cache_list, list) {
if (iter->ofnode != node)
continue;
cache = cache_find_first_sibling(iter);
break;
}
return cache;
}
static bool cache_node_is_unified(const struct device_node *np)
{
return of_get_property(np, "cache-unified", NULL);
}
static struct cache *cache_do_one_devnode_unified(struct device_node *node,
int level)
{
struct cache *cache;
pr_debug("creating L%d ucache for %s\n", level, node->full_name);
cache = new_cache(CACHE_TYPE_UNIFIED, level, node);
return cache;
}
static struct cache *cache_do_one_devnode_split(struct device_node *node,
int level)
{
struct cache *dcache, *icache;
pr_debug("creating L%d dcache and icache for %s\n", level,
node->full_name);
dcache = new_cache(CACHE_TYPE_DATA, level, node);
icache = new_cache(CACHE_TYPE_INSTRUCTION, level, node);
if (!dcache || !icache)
goto err;
dcache->next_local = icache;
return dcache;
err:
release_cache(dcache);
release_cache(icache);
return NULL;
}
static struct cache *cache_do_one_devnode(struct device_node *node, int level)
{
struct cache *cache;
if (cache_node_is_unified(node))
cache = cache_do_one_devnode_unified(node, level);
else
cache = cache_do_one_devnode_split(node, level);
return cache;
}
static struct cache *cache_lookup_or_instantiate(struct device_node *node,
int level)
{
struct cache *cache;
cache = cache_lookup_by_node(node);
WARN_ONCE(cache && cache->level != level,
"cache level mismatch on lookup (got %d, expected %d)\n",
cache->level, level);
if (!cache)
cache = cache_do_one_devnode(node, level);
return cache;
}
static void link_cache_lists(struct cache *smaller, struct cache *bigger)
{
while (smaller->next_local) {
if (smaller->next_local == bigger)
return;
smaller = smaller->next_local;
}
smaller->next_local = bigger;
}
static void do_subsidiary_caches_debugcheck(struct cache *cache)
{
WARN_ON_ONCE(cache->level != 1);
WARN_ON_ONCE(strcmp(cache->ofnode->type, "cpu"));
}
static void do_subsidiary_caches(struct cache *cache)
{
struct device_node *subcache_node;
int level = cache->level;
do_subsidiary_caches_debugcheck(cache);
while ((subcache_node = of_find_next_cache_node(cache->ofnode))) {
struct cache *subcache;
level++;
subcache = cache_lookup_or_instantiate(subcache_node, level);
of_node_put(subcache_node);
if (!subcache)
break;
link_cache_lists(cache, subcache);
cache = subcache;
}
}
static struct cache *cache_chain_instantiate(unsigned int cpu_id)
{
struct device_node *cpu_node;
struct cache *cpu_cache = NULL;
pr_debug("creating cache object(s) for CPU %i\n", cpu_id);
cpu_node = of_get_cpu_node(cpu_id, NULL);
WARN_ONCE(!cpu_node, "no OF node found for CPU %i\n", cpu_id);
if (!cpu_node)
goto out;
cpu_cache = cache_lookup_or_instantiate(cpu_node, 1);
if (!cpu_cache)
goto out;
do_subsidiary_caches(cpu_cache);
cache_cpu_set(cpu_cache, cpu_id);
out:
of_node_put(cpu_node);
return cpu_cache;
}
static struct cache_dir *cacheinfo_create_cache_dir(unsigned int cpu_id)
{
struct cache_dir *cache_dir;
struct device *dev;
struct kobject *kobj = NULL;
dev = get_cpu_device(cpu_id);
WARN_ONCE(!dev, "no dev for CPU %i\n", cpu_id);
if (!dev)
goto err;
kobj = kobject_create_and_add("cache", &dev->kobj);
if (!kobj)
goto err;
cache_dir = kzalloc(sizeof(*cache_dir), GFP_KERNEL);
if (!cache_dir)
goto err;
cache_dir->kobj = kobj;
WARN_ON_ONCE(per_cpu(cache_dir_pcpu, cpu_id) != NULL);
per_cpu(cache_dir_pcpu, cpu_id) = cache_dir;
return cache_dir;
err:
kobject_put(kobj);
return NULL;
}
static void cache_index_release(struct kobject *kobj)
{
struct cache_index_dir *index;
index = kobj_to_cache_index_dir(kobj);
pr_debug("freeing index directory for L%d %s cache\n",
index->cache->level, cache_type_string(index->cache));
kfree(index);
}
static ssize_t cache_index_show(struct kobject *k, struct attribute *attr, char *buf)
{
struct kobj_attribute *kobj_attr;
kobj_attr = container_of(attr, struct kobj_attribute, attr);
return kobj_attr->show(k, kobj_attr, buf);
}
static struct cache *index_kobj_to_cache(struct kobject *k)
{
struct cache_index_dir *index;
index = kobj_to_cache_index_dir(k);
return index->cache;
}
static ssize_t size_show(struct kobject *k, struct kobj_attribute *attr, char *buf)
{
unsigned int size_kb;
struct cache *cache;
cache = index_kobj_to_cache(k);
if (cache_size_kb(cache, &size_kb))
return -ENODEV;
return sprintf(buf, "%uK\n", size_kb);
}
static ssize_t line_size_show(struct kobject *k, struct kobj_attribute *attr, char *buf)
{
unsigned int line_size;
struct cache *cache;
cache = index_kobj_to_cache(k);
if (cache_get_line_size(cache, &line_size))
return -ENODEV;
return sprintf(buf, "%u\n", line_size);
}
static ssize_t nr_sets_show(struct kobject *k, struct kobj_attribute *attr, char *buf)
{
unsigned int nr_sets;
struct cache *cache;
cache = index_kobj_to_cache(k);
if (cache_nr_sets(cache, &nr_sets))
return -ENODEV;
return sprintf(buf, "%u\n", nr_sets);
}
static ssize_t associativity_show(struct kobject *k, struct kobj_attribute *attr, char *buf)
{
unsigned int associativity;
struct cache *cache;
cache = index_kobj_to_cache(k);
if (cache_associativity(cache, &associativity))
return -ENODEV;
return sprintf(buf, "%u\n", associativity);
}
static ssize_t type_show(struct kobject *k, struct kobj_attribute *attr, char *buf)
{
struct cache *cache;
cache = index_kobj_to_cache(k);
return sprintf(buf, "%s\n", cache_type_string(cache));
}
static ssize_t level_show(struct kobject *k, struct kobj_attribute *attr, char *buf)
{
struct cache_index_dir *index;
struct cache *cache;
index = kobj_to_cache_index_dir(k);
cache = index->cache;
return sprintf(buf, "%d\n", cache->level);
}
static ssize_t shared_cpu_map_show(struct kobject *k, struct kobj_attribute *attr, char *buf)
{
struct cache_index_dir *index;
struct cache *cache;
int ret;
index = kobj_to_cache_index_dir(k);
cache = index->cache;
ret = scnprintf(buf, PAGE_SIZE - 1, "%*pb\n",
cpumask_pr_args(&cache->shared_cpu_map));
buf[ret++] = '\n';
buf[ret] = '\0';
return ret;
}
static void cacheinfo_create_index_opt_attrs(struct cache_index_dir *dir)
{
const char *cache_name;
const char *cache_type;
struct cache *cache;
char *buf;
int i;
buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!buf)
return;
cache = dir->cache;
cache_name = cache->ofnode->full_name;
cache_type = cache_type_string(cache);
for (i = 0; i < ARRAY_SIZE(cache_index_opt_attrs); i++) {
struct kobj_attribute *attr;
ssize_t rc;
attr = cache_index_opt_attrs[i];
rc = attr->show(&dir->kobj, attr, buf);
if (rc <= 0) {
pr_debug("not creating %s attribute for "
"%s(%s) (rc = %zd)\n",
attr->attr.name, cache_name,
cache_type, rc);
continue;
}
if (sysfs_create_file(&dir->kobj, &attr->attr))
pr_debug("could not create %s attribute for %s(%s)\n",
attr->attr.name, cache_name, cache_type);
}
kfree(buf);
}
static void cacheinfo_create_index_dir(struct cache *cache, int index,
struct cache_dir *cache_dir)
{
struct cache_index_dir *index_dir;
int rc;
index_dir = kzalloc(sizeof(*index_dir), GFP_KERNEL);
if (!index_dir)
goto err;
index_dir->cache = cache;
rc = kobject_init_and_add(&index_dir->kobj, &cache_index_type,
cache_dir->kobj, "index%d", index);
if (rc)
goto err;
index_dir->next = cache_dir->index;
cache_dir->index = index_dir;
cacheinfo_create_index_opt_attrs(index_dir);
return;
err:
kfree(index_dir);
}
static void cacheinfo_sysfs_populate(unsigned int cpu_id,
struct cache *cache_list)
{
struct cache_dir *cache_dir;
struct cache *cache;
int index = 0;
cache_dir = cacheinfo_create_cache_dir(cpu_id);
if (!cache_dir)
return;
cache = cache_list;
while (cache) {
cacheinfo_create_index_dir(cache, index, cache_dir);
index++;
cache = cache->next_local;
}
}
void cacheinfo_cpu_online(unsigned int cpu_id)
{
struct cache *cache;
cache = cache_chain_instantiate(cpu_id);
if (!cache)
return;
cacheinfo_sysfs_populate(cpu_id, cache);
}
static struct cache *cache_lookup_by_cpu(unsigned int cpu_id)
{
struct device_node *cpu_node;
struct cache *cache;
cpu_node = of_get_cpu_node(cpu_id, NULL);
WARN_ONCE(!cpu_node, "no OF node found for CPU %i\n", cpu_id);
if (!cpu_node)
return NULL;
cache = cache_lookup_by_node(cpu_node);
of_node_put(cpu_node);
return cache;
}
static void remove_index_dirs(struct cache_dir *cache_dir)
{
struct cache_index_dir *index;
index = cache_dir->index;
while (index) {
struct cache_index_dir *next;
next = index->next;
kobject_put(&index->kobj);
index = next;
}
}
static void remove_cache_dir(struct cache_dir *cache_dir)
{
remove_index_dirs(cache_dir);
kobject_del(cache_dir->kobj);
kobject_put(cache_dir->kobj);
kfree(cache_dir);
}
static void cache_cpu_clear(struct cache *cache, int cpu)
{
while (cache) {
struct cache *next = cache->next_local;
WARN_ONCE(!cpumask_test_cpu(cpu, &cache->shared_cpu_map),
"CPU %i not accounted in %s(%s)\n",
cpu, cache->ofnode->full_name,
cache_type_string(cache));
cpumask_clear_cpu(cpu, &cache->shared_cpu_map);
if (cpumask_empty(&cache->shared_cpu_map))
release_cache(cache);
cache = next;
}
}
void cacheinfo_cpu_offline(unsigned int cpu_id)
{
struct cache_dir *cache_dir;
struct cache *cache;
cache_dir = per_cpu(cache_dir_pcpu, cpu_id);
if (cache_dir)
remove_cache_dir(cache_dir);
per_cpu(cache_dir_pcpu, cpu_id) = NULL;
cache = cache_lookup_by_cpu(cpu_id);
if (cache)
cache_cpu_clear(cache, cpu_id);
}
