static void __init of_numa_parse_cpu_nodes(void)
{
u32 nid;
int r;
struct device_node *cpus;
struct device_node *np = NULL;
cpus = of_find_node_by_path("/cpus");
if (!cpus)
return;
for_each_child_of_node(cpus, np) {
if (of_node_cmp(np->type, "cpu") != 0)
continue;
r = of_property_read_u32(np, "numa-node-id", &nid);
if (r)
continue;
pr_debug("NUMA: CPU on %u\n", nid);
if (nid >= MAX_NUMNODES)
pr_warn("NUMA: Node id %u exceeds maximum value\n",
nid);
else
node_set(nid, numa_nodes_parsed);
}
}
static int __init of_numa_parse_memory_nodes(void)
{
struct device_node *np = NULL;
struct resource rsrc;
u32 nid;
int r = 0;
for (;;) {
np = of_find_node_by_type(np, "memory");
if (!np)
break;
r = of_property_read_u32(np, "numa-node-id", &nid);
if (r == -EINVAL)
continue;
else if (r)
break;
r = of_address_to_resource(np, 0, &rsrc);
if (r) {
pr_err("NUMA: bad reg property in memory node\n");
break;
}
pr_debug("NUMA: base = %llx len = %llx, node = %u\n",
rsrc.start, rsrc.end - rsrc.start + 1, nid);
r = numa_add_memblk(nid, rsrc.start,
rsrc.end - rsrc.start + 1);
if (r)
break;
}
of_node_put(np);
return r;
}
static int __init of_numa_parse_distance_map_v1(struct device_node *map)
{
const __be32 *matrix;
int entry_count;
int i;
pr_info("NUMA: parsing numa-distance-map-v1\n");
matrix = of_get_property(map, "distance-matrix", NULL);
if (!matrix) {
pr_err("NUMA: No distance-matrix property in distance-map\n");
return -EINVAL;
}
entry_count = of_property_count_u32_elems(map, "distance-matrix");
if (entry_count <= 0) {
pr_err("NUMA: Invalid distance-matrix\n");
return -EINVAL;
}
for (i = 0; i + 2 < entry_count; i += 3) {
u32 nodea, nodeb, distance;
nodea = of_read_number(matrix, 1);
matrix++;
nodeb = of_read_number(matrix, 1);
matrix++;
distance = of_read_number(matrix, 1);
matrix++;
numa_set_distance(nodea, nodeb, distance);
pr_debug("NUMA: distance[node%d -> node%d] = %d\n",
nodea, nodeb, distance);
if (nodeb > nodea)
numa_set_distance(nodeb, nodea, distance);
}
return 0;
}
static int __init of_numa_parse_distance_map(void)
{
int ret = 0;
struct device_node *np;
np = of_find_compatible_node(NULL, NULL,
"numa-distance-map-v1");
if (np)
ret = of_numa_parse_distance_map_v1(np);
of_node_put(np);
return ret;
}
int of_node_to_nid(struct device_node *device)
{
struct device_node *np;
u32 nid;
int r = -ENODATA;
np = of_node_get(device);
while (np) {
struct device_node *parent;
r = of_property_read_u32(np, "numa-node-id", &nid);
if (r != -EINVAL)
break;
parent = of_get_parent(np);
of_node_put(np);
np = parent;
}
if (np && r)
pr_warn("NUMA: Invalid \"numa-node-id\" property in node %s\n",
np->name);
of_node_put(np);
if (!r) {
if (nid >= MAX_NUMNODES)
pr_warn("NUMA: Node id %u exceeds maximum value\n",
nid);
else
return nid;
}
return NUMA_NO_NODE;
}
int __init of_numa_init(void)
{
int r;
of_numa_parse_cpu_nodes();
r = of_numa_parse_memory_nodes();
if (r)
return r;
return of_numa_parse_distance_map();
}
