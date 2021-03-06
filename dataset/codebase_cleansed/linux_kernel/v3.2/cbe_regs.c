static struct cbe_regs_map *cbe_find_map(struct device_node *np)
{
int i;
struct device_node *tmp_np;
if (strcasecmp(np->type, "spe")) {
for (i = 0; i < cbe_regs_map_count; i++)
if (cbe_regs_maps[i].cpu_node == np ||
cbe_regs_maps[i].be_node == np)
return &cbe_regs_maps[i];
return NULL;
}
if (np->data)
return np->data;
tmp_np = np;
do {
tmp_np = tmp_np->parent;
BUG_ON(!tmp_np);
} while (strcasecmp(tmp_np->type, "cpu") &&
strcasecmp(tmp_np->type, "be"));
np->data = cbe_find_map(tmp_np);
return np->data;
}
struct cbe_pmd_regs __iomem *cbe_get_pmd_regs(struct device_node *np)
{
struct cbe_regs_map *map = cbe_find_map(np);
if (map == NULL)
return NULL;
return map->pmd_regs;
}
struct cbe_pmd_regs __iomem *cbe_get_cpu_pmd_regs(int cpu)
{
struct cbe_regs_map *map = cbe_thread_map[cpu].regs;
if (map == NULL)
return NULL;
return map->pmd_regs;
}
struct cbe_pmd_shadow_regs *cbe_get_pmd_shadow_regs(struct device_node *np)
{
struct cbe_regs_map *map = cbe_find_map(np);
if (map == NULL)
return NULL;
return &map->pmd_shadow_regs;
}
struct cbe_pmd_shadow_regs *cbe_get_cpu_pmd_shadow_regs(int cpu)
{
struct cbe_regs_map *map = cbe_thread_map[cpu].regs;
if (map == NULL)
return NULL;
return &map->pmd_shadow_regs;
}
struct cbe_iic_regs __iomem *cbe_get_iic_regs(struct device_node *np)
{
struct cbe_regs_map *map = cbe_find_map(np);
if (map == NULL)
return NULL;
return map->iic_regs;
}
struct cbe_iic_regs __iomem *cbe_get_cpu_iic_regs(int cpu)
{
struct cbe_regs_map *map = cbe_thread_map[cpu].regs;
if (map == NULL)
return NULL;
return map->iic_regs;
}
struct cbe_mic_tm_regs __iomem *cbe_get_mic_tm_regs(struct device_node *np)
{
struct cbe_regs_map *map = cbe_find_map(np);
if (map == NULL)
return NULL;
return map->mic_tm_regs;
}
struct cbe_mic_tm_regs __iomem *cbe_get_cpu_mic_tm_regs(int cpu)
{
struct cbe_regs_map *map = cbe_thread_map[cpu].regs;
if (map == NULL)
return NULL;
return map->mic_tm_regs;
}
u32 cbe_get_hw_thread_id(int cpu)
{
return cbe_thread_map[cpu].thread_id;
}
u32 cbe_cpu_to_node(int cpu)
{
return cbe_thread_map[cpu].cbe_id;
}
u32 cbe_node_to_cpu(int node)
{
return cpumask_first(&cbe_local_mask[node]);
}
static struct device_node *cbe_get_be_node(int cpu_id)
{
struct device_node *np;
for_each_node_by_type (np, "be") {
int len,i;
const phandle *cpu_handle;
cpu_handle = of_get_property(np, "cpus", &len);
if (WARN_ON_ONCE(!cpu_handle))
return np;
for (i=0; i<len; i++)
if (of_find_node_by_phandle(cpu_handle[i]) == of_get_cpu_node(cpu_id, NULL))
return np;
}
return NULL;
}
void __init cbe_fill_regs_map(struct cbe_regs_map *map)
{
if(map->be_node) {
struct device_node *be, *np;
be = map->be_node;
for_each_node_by_type(np, "pervasive")
if (of_get_parent(np) == be)
map->pmd_regs = of_iomap(np, 0);
for_each_node_by_type(np, "CBEA-Internal-Interrupt-Controller")
if (of_get_parent(np) == be)
map->iic_regs = of_iomap(np, 2);
for_each_node_by_type(np, "mic-tm")
if (of_get_parent(np) == be)
map->mic_tm_regs = of_iomap(np, 0);
} else {
struct device_node *cpu;
const struct address_prop {
unsigned long address;
unsigned int len;
} __attribute__((packed)) *prop;
cpu = map->cpu_node;
prop = of_get_property(cpu, "pervasive", NULL);
if (prop != NULL)
map->pmd_regs = ioremap(prop->address, prop->len);
prop = of_get_property(cpu, "iic", NULL);
if (prop != NULL)
map->iic_regs = ioremap(prop->address, prop->len);
prop = of_get_property(cpu, "mic-tm", NULL);
if (prop != NULL)
map->mic_tm_regs = ioremap(prop->address, prop->len);
}
}
void __init cbe_regs_init(void)
{
int i;
unsigned int thread_id;
struct device_node *cpu;
for_each_possible_cpu(i) {
cbe_thread_map[i].cpu_node = of_get_cpu_node(i, &thread_id);
cbe_thread_map[i].be_node = cbe_get_be_node(i);
cbe_thread_map[i].thread_id = thread_id;
}
for_each_node_by_type(cpu, "cpu") {
struct cbe_regs_map *map;
unsigned int cbe_id;
cbe_id = cbe_regs_map_count++;
map = &cbe_regs_maps[cbe_id];
if (cbe_regs_map_count > MAX_CBE) {
printk(KERN_ERR "cbe_regs: More BE chips than supported"
"!\n");
cbe_regs_map_count--;
of_node_put(cpu);
return;
}
map->cpu_node = cpu;
for_each_possible_cpu(i) {
struct cbe_thread_map *thread = &cbe_thread_map[i];
if (thread->cpu_node == cpu) {
thread->regs = map;
thread->cbe_id = cbe_id;
map->be_node = thread->be_node;
cpumask_set_cpu(i, &cbe_local_mask[cbe_id]);
if(thread->thread_id == 0)
cpumask_set_cpu(i, &cbe_first_online_cpu);
}
}
cbe_fill_regs_map(map);
}
}
