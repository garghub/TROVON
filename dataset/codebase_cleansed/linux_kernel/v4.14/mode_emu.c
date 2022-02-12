static void pin_core_to_node(int core_id, int node_id)
{
if (emu_cores->to_node_id[core_id] == NODE_ID_FREE) {
emu_cores->per_node[node_id]++;
emu_cores->to_node_id[core_id] = node_id;
emu_cores->total++;
} else {
WARN_ON(emu_cores->to_node_id[core_id] != node_id);
}
}
static int cores_pinned(struct toptree *node)
{
return emu_cores->per_node[node->id];
}
static int core_pinned_to_node_id(struct toptree *core)
{
return emu_cores->to_node_id[core->id];
}
static int cores_free(struct toptree *tree)
{
struct toptree *core;
int count = 0;
toptree_for_each(core, tree, CORE) {
if (core_pinned_to_node_id(core) == NODE_ID_FREE)
count++;
}
return count;
}
static struct toptree *core_node(struct toptree *core)
{
return core->parent->parent->parent->parent;
}
static struct toptree *core_drawer(struct toptree *core)
{
return core->parent->parent->parent;
}
static struct toptree *core_book(struct toptree *core)
{
return core->parent->parent;
}
static struct toptree *core_mc(struct toptree *core)
{
return core->parent;
}
static int dist_core_to_core(struct toptree *core1, struct toptree *core2)
{
if (core_drawer(core1)->id != core_drawer(core2)->id)
return DIST_DRAWER;
if (core_book(core1)->id != core_book(core2)->id)
return DIST_BOOK;
if (core_mc(core1)->id != core_mc(core2)->id)
return DIST_MC;
return DIST_CORE;
}
static int dist_node_to_core(struct toptree *node, struct toptree *core)
{
struct toptree *core_node;
int dist_min = DIST_MAX;
toptree_for_each(core_node, node, CORE)
dist_min = min(dist_min, dist_core_to_core(core_node, core));
return dist_min == DIST_MAX ? DIST_EMPTY : dist_min;
}
static void toptree_unify_tree(struct toptree *tree)
{
int nid;
toptree_unify(tree);
for (nid = 0; nid < emu_nodes; nid++)
toptree_get_child(tree, nid);
}
static struct toptree *node_for_core(struct toptree *numa, struct toptree *core,
int extra)
{
struct toptree *node, *node_best = NULL;
int dist_cur, dist_best, cores_target;
cores_target = emu_cores->per_node_target + extra;
dist_best = DIST_MAX;
node_best = NULL;
toptree_for_each(node, numa, NODE) {
if (core_pinned_to_node_id(core) == node->id) {
node_best = node;
break;
}
if (cores_pinned(node) >= cores_target)
continue;
dist_cur = dist_node_to_core(node, core);
if (dist_cur < dist_best) {
dist_best = dist_cur;
node_best = node;
}
}
return node_best;
}
static void toptree_to_numa_single(struct toptree *numa, struct toptree *phys,
int extra)
{
struct toptree *node, *core, *tmp;
toptree_for_each_safe(core, tmp, phys, CORE) {
node = node_for_core(numa, core, extra);
if (!node)
return;
toptree_move(core, node);
pin_core_to_node(core->id, node->id);
}
}
static void move_level_to_numa_node(struct toptree *node, struct toptree *phys,
enum toptree_level level, bool perfect)
{
int cores_free, cores_target = emu_cores->per_node_target;
struct toptree *cur, *tmp;
toptree_for_each_safe(cur, tmp, phys, level) {
cores_free = cores_target - toptree_count(node, CORE);
if (perfect) {
if (cores_free == toptree_count(cur, CORE))
toptree_move(cur, node);
} else {
if (cores_free >= toptree_count(cur, CORE))
toptree_move(cur, node);
}
}
}
static void move_level_to_numa(struct toptree *numa, struct toptree *phys,
enum toptree_level level, bool perfect)
{
struct toptree *node;
toptree_for_each(node, numa, NODE)
move_level_to_numa_node(node, phys, level, perfect);
}
static void toptree_to_numa_first(struct toptree *numa, struct toptree *phys)
{
struct toptree *core;
move_level_to_numa(numa, phys, DRAWER, true);
move_level_to_numa(numa, phys, DRAWER, false);
move_level_to_numa(numa, phys, BOOK, true);
move_level_to_numa(numa, phys, BOOK, false);
move_level_to_numa(numa, phys, MC, true);
move_level_to_numa(numa, phys, MC, false);
toptree_for_each(core, numa, CORE)
pin_core_to_node(core->id, core_node(core)->id);
}
static struct toptree *toptree_new(int id, int nodes)
{
struct toptree *tree;
int nid;
tree = toptree_alloc(TOPOLOGY, id);
if (!tree)
goto fail;
for (nid = 0; nid < nodes; nid++) {
if (!toptree_get_child(tree, nid))
goto fail;
}
return tree;
fail:
panic("NUMA emulation could not allocate topology");
}
static void __ref create_core_to_node_map(void)
{
int i;
emu_cores = memblock_virt_alloc(sizeof(*emu_cores), 8);
for (i = 0; i < ARRAY_SIZE(emu_cores->to_node_id); i++)
emu_cores->to_node_id[i] = NODE_ID_FREE;
}
static struct toptree *toptree_to_numa(struct toptree *phys)
{
static int first = 1;
struct toptree *numa;
int cores_total;
cores_total = emu_cores->total + cores_free(phys);
emu_cores->per_node_target = cores_total / emu_nodes;
numa = toptree_new(TOPTREE_ID_NUMA, emu_nodes);
if (first) {
toptree_to_numa_first(numa, phys);
first = 0;
}
toptree_to_numa_single(numa, phys, 0);
toptree_to_numa_single(numa, phys, 1);
toptree_unify_tree(numa);
WARN_ON(cpumask_weight(&phys->mask));
return numa;
}
static struct toptree *toptree_from_topology(void)
{
struct toptree *phys, *node, *drawer, *book, *mc, *core;
struct cpu_topology_s390 *top;
int cpu;
phys = toptree_new(TOPTREE_ID_PHYS, 1);
for_each_cpu(cpu, &cpus_with_topology) {
top = &cpu_topology[cpu];
node = toptree_get_child(phys, 0);
drawer = toptree_get_child(node, top->drawer_id);
book = toptree_get_child(drawer, top->book_id);
mc = toptree_get_child(book, top->socket_id);
core = toptree_get_child(mc, smp_get_base_cpu(cpu));
if (!drawer || !book || !mc || !core)
panic("NUMA emulation could not allocate memory");
cpumask_set_cpu(cpu, &core->mask);
toptree_update_mask(mc);
}
return phys;
}
static void topology_add_core(struct toptree *core)
{
struct cpu_topology_s390 *top;
int cpu;
for_each_cpu(cpu, &core->mask) {
top = &cpu_topology[cpu];
cpumask_copy(&top->thread_mask, &core->mask);
cpumask_copy(&top->core_mask, &core_mc(core)->mask);
cpumask_copy(&top->book_mask, &core_book(core)->mask);
cpumask_copy(&top->drawer_mask, &core_drawer(core)->mask);
cpumask_set_cpu(cpu, &node_to_cpumask_map[core_node(core)->id]);
top->node_id = core_node(core)->id;
}
}
static void toptree_to_topology(struct toptree *numa)
{
struct toptree *core;
int i;
for (i = 0; i < MAX_NUMNODES; i++)
cpumask_clear(&node_to_cpumask_map[i]);
toptree_for_each(core, numa, CORE)
topology_add_core(core);
}
static void print_node_to_core_map(void)
{
int nid, cid;
if (!numa_debug_enabled)
return;
printk(KERN_DEBUG "NUMA node to core mapping\n");
for (nid = 0; nid < emu_nodes; nid++) {
printk(KERN_DEBUG " node %3d: ", nid);
for (cid = 0; cid < ARRAY_SIZE(emu_cores->to_node_id); cid++) {
if (emu_cores->to_node_id[cid] == nid)
printk(KERN_CONT "%d ", cid);
}
printk(KERN_CONT "\n");
}
}
static void pin_all_possible_cpus(void)
{
int core_id, node_id, cpu;
static int initialized;
if (initialized)
return;
print_node_to_core_map();
node_id = 0;
for_each_possible_cpu(cpu) {
core_id = smp_get_base_cpu(cpu);
if (emu_cores->to_node_id[core_id] != NODE_ID_FREE)
continue;
pin_core_to_node(core_id, node_id);
cpu_topology[cpu].node_id = node_id;
node_id = (node_id + 1) % emu_nodes;
}
print_node_to_core_map();
initialized = 1;
}
static void emu_update_cpu_topology(void)
{
struct toptree *phys, *numa;
if (emu_cores == NULL)
create_core_to_node_map();
phys = toptree_from_topology();
numa = toptree_to_numa(phys);
toptree_free(phys);
toptree_to_topology(numa);
toptree_free(numa);
pin_all_possible_cpus();
}
static unsigned long emu_setup_size_adjust(unsigned long size)
{
unsigned long size_new;
size = size ? : CONFIG_EMU_SIZE;
size_new = roundup(size, memory_block_size_bytes());
if (size_new == size)
return size;
pr_warn("Increasing memory stripe size from %ld MB to %ld MB\n",
size >> 20, size_new >> 20);
return size_new;
}
static int emu_setup_nodes_adjust(int nodes)
{
int nodes_max;
nodes_max = memblock.memory.total_size / emu_size;
nodes_max = max(nodes_max, 1);
if (nodes_max >= nodes)
return nodes;
pr_warn("Not enough memory for %d nodes, reducing node count\n", nodes);
return nodes_max;
}
static void emu_setup(void)
{
int nid;
emu_size = emu_setup_size_adjust(emu_size);
emu_nodes = emu_setup_nodes_adjust(emu_nodes);
for (nid = 0; nid < emu_nodes; nid++)
node_set(nid, node_possible_map);
pr_info("Creating %d nodes with memory stripe size %ld MB\n",
emu_nodes, emu_size >> 20);
}
static int emu_pfn_to_nid(unsigned long pfn)
{
return (pfn / (emu_size >> PAGE_SHIFT)) % emu_nodes;
}
static unsigned long emu_align(void)
{
return emu_size;
}
static int emu_distance(int node1, int node2)
{
return (node1 != node2) * EMU_NODE_DIST;
}
static int __init early_parse_emu_nodes(char *p)
{
int count;
if (kstrtoint(p, 0, &count) != 0 || count <= 0)
return 0;
if (count <= 0)
return 0;
emu_nodes = min(count, MAX_NUMNODES);
return 0;
}
static int __init early_parse_emu_size(char *p)
{
emu_size = memparse(p, NULL);
return 0;
}
