static void cfs_cpu_core_siblings(int cpu, cpumask_t *mask)
{
cpumask_copy(mask, topology_core_cpumask(cpu));
}
static void cfs_cpu_ht_siblings(int cpu, cpumask_t *mask)
{
cpumask_copy(mask, topology_sibling_cpumask(cpu));
}
static void cfs_node_to_cpumask(int node, cpumask_t *mask)
{
cpumask_copy(mask, cpumask_of_node(node));
}
void
cfs_cpt_table_free(struct cfs_cpt_table *cptab)
{
int i;
if (cptab->ctb_cpu2cpt != NULL) {
LIBCFS_FREE(cptab->ctb_cpu2cpt,
num_possible_cpus() *
sizeof(cptab->ctb_cpu2cpt[0]));
}
for (i = 0; cptab->ctb_parts != NULL && i < cptab->ctb_nparts; i++) {
struct cfs_cpu_partition *part = &cptab->ctb_parts[i];
if (part->cpt_nodemask != NULL) {
LIBCFS_FREE(part->cpt_nodemask,
sizeof(*part->cpt_nodemask));
}
if (part->cpt_cpumask != NULL)
LIBCFS_FREE(part->cpt_cpumask, cpumask_size());
}
if (cptab->ctb_parts != NULL) {
LIBCFS_FREE(cptab->ctb_parts,
cptab->ctb_nparts * sizeof(cptab->ctb_parts[0]));
}
if (cptab->ctb_nodemask != NULL)
LIBCFS_FREE(cptab->ctb_nodemask, sizeof(*cptab->ctb_nodemask));
if (cptab->ctb_cpumask != NULL)
LIBCFS_FREE(cptab->ctb_cpumask, cpumask_size());
LIBCFS_FREE(cptab, sizeof(*cptab));
}
struct cfs_cpt_table *
cfs_cpt_table_alloc(unsigned int ncpt)
{
struct cfs_cpt_table *cptab;
int i;
LIBCFS_ALLOC(cptab, sizeof(*cptab));
if (cptab == NULL)
return NULL;
cptab->ctb_nparts = ncpt;
LIBCFS_ALLOC(cptab->ctb_cpumask, cpumask_size());
LIBCFS_ALLOC(cptab->ctb_nodemask, sizeof(*cptab->ctb_nodemask));
if (cptab->ctb_cpumask == NULL || cptab->ctb_nodemask == NULL)
goto failed;
LIBCFS_ALLOC(cptab->ctb_cpu2cpt,
num_possible_cpus() * sizeof(cptab->ctb_cpu2cpt[0]));
if (cptab->ctb_cpu2cpt == NULL)
goto failed;
memset(cptab->ctb_cpu2cpt, -1,
num_possible_cpus() * sizeof(cptab->ctb_cpu2cpt[0]));
LIBCFS_ALLOC(cptab->ctb_parts, ncpt * sizeof(cptab->ctb_parts[0]));
if (cptab->ctb_parts == NULL)
goto failed;
for (i = 0; i < ncpt; i++) {
struct cfs_cpu_partition *part = &cptab->ctb_parts[i];
LIBCFS_ALLOC(part->cpt_cpumask, cpumask_size());
LIBCFS_ALLOC(part->cpt_nodemask, sizeof(*part->cpt_nodemask));
if (part->cpt_cpumask == NULL || part->cpt_nodemask == NULL)
goto failed;
}
spin_lock(&cpt_data.cpt_lock);
cptab->ctb_version = cpt_data.cpt_version;
spin_unlock(&cpt_data.cpt_lock);
return cptab;
failed:
cfs_cpt_table_free(cptab);
return NULL;
}
int
cfs_cpt_table_print(struct cfs_cpt_table *cptab, char *buf, int len)
{
char *tmp = buf;
int rc = 0;
int i;
int j;
for (i = 0; i < cptab->ctb_nparts; i++) {
if (len > 0) {
rc = snprintf(tmp, len, "%d\t: ", i);
len -= rc;
}
if (len <= 0) {
rc = -EFBIG;
goto out;
}
tmp += rc;
for_each_cpu(j, cptab->ctb_parts[i].cpt_cpumask) {
rc = snprintf(tmp, len, "%d ", j);
len -= rc;
if (len <= 0) {
rc = -EFBIG;
goto out;
}
tmp += rc;
}
*tmp = '\n';
tmp++;
len--;
}
out:
if (rc < 0)
return rc;
return tmp - buf;
}
int
cfs_cpt_number(struct cfs_cpt_table *cptab)
{
return cptab->ctb_nparts;
}
int
cfs_cpt_weight(struct cfs_cpt_table *cptab, int cpt)
{
LASSERT(cpt == CFS_CPT_ANY || (cpt >= 0 && cpt < cptab->ctb_nparts));
return cpt == CFS_CPT_ANY ?
cpumask_weight(cptab->ctb_cpumask) :
cpumask_weight(cptab->ctb_parts[cpt].cpt_cpumask);
}
int
cfs_cpt_online(struct cfs_cpt_table *cptab, int cpt)
{
LASSERT(cpt == CFS_CPT_ANY || (cpt >= 0 && cpt < cptab->ctb_nparts));
return cpt == CFS_CPT_ANY ?
cpumask_any_and(cptab->ctb_cpumask,
cpu_online_mask) < nr_cpu_ids :
cpumask_any_and(cptab->ctb_parts[cpt].cpt_cpumask,
cpu_online_mask) < nr_cpu_ids;
}
cpumask_t *
cfs_cpt_cpumask(struct cfs_cpt_table *cptab, int cpt)
{
LASSERT(cpt == CFS_CPT_ANY || (cpt >= 0 && cpt < cptab->ctb_nparts));
return cpt == CFS_CPT_ANY ?
cptab->ctb_cpumask : cptab->ctb_parts[cpt].cpt_cpumask;
}
nodemask_t *
cfs_cpt_nodemask(struct cfs_cpt_table *cptab, int cpt)
{
LASSERT(cpt == CFS_CPT_ANY || (cpt >= 0 && cpt < cptab->ctb_nparts));
return cpt == CFS_CPT_ANY ?
cptab->ctb_nodemask : cptab->ctb_parts[cpt].cpt_nodemask;
}
int
cfs_cpt_set_cpu(struct cfs_cpt_table *cptab, int cpt, int cpu)
{
int node;
LASSERT(cpt >= 0 && cpt < cptab->ctb_nparts);
if (cpu < 0 || cpu >= nr_cpu_ids || !cpu_online(cpu)) {
CDEBUG(D_INFO, "CPU %d is invalid or it's offline\n", cpu);
return 0;
}
if (cptab->ctb_cpu2cpt[cpu] != -1) {
CDEBUG(D_INFO, "CPU %d is already in partition %d\n",
cpu, cptab->ctb_cpu2cpt[cpu]);
return 0;
}
cptab->ctb_cpu2cpt[cpu] = cpt;
LASSERT(!cpumask_test_cpu(cpu, cptab->ctb_cpumask));
LASSERT(!cpumask_test_cpu(cpu, cptab->ctb_parts[cpt].cpt_cpumask));
cpumask_set_cpu(cpu, cptab->ctb_cpumask);
cpumask_set_cpu(cpu, cptab->ctb_parts[cpt].cpt_cpumask);
node = cpu_to_node(cpu);
if (!node_isset(node, *cptab->ctb_nodemask))
node_set(node, *cptab->ctb_nodemask);
if (!node_isset(node, *cptab->ctb_parts[cpt].cpt_nodemask))
node_set(node, *cptab->ctb_parts[cpt].cpt_nodemask);
return 1;
}
void
cfs_cpt_unset_cpu(struct cfs_cpt_table *cptab, int cpt, int cpu)
{
int node;
int i;
LASSERT(cpt == CFS_CPT_ANY || (cpt >= 0 && cpt < cptab->ctb_nparts));
if (cpu < 0 || cpu >= nr_cpu_ids) {
CDEBUG(D_INFO, "Invalid CPU id %d\n", cpu);
return;
}
if (cpt == CFS_CPT_ANY) {
cpt = cptab->ctb_cpu2cpt[cpu];
if (cpt < 0) {
CDEBUG(D_INFO, "Try to unset cpu %d which is not in CPT-table %p\n",
cpt, cptab);
return;
}
} else if (cpt != cptab->ctb_cpu2cpt[cpu]) {
CDEBUG(D_INFO,
"CPU %d is not in cpu-partition %d\n", cpu, cpt);
return;
}
LASSERT(cpumask_test_cpu(cpu, cptab->ctb_parts[cpt].cpt_cpumask));
LASSERT(cpumask_test_cpu(cpu, cptab->ctb_cpumask));
cpumask_clear_cpu(cpu, cptab->ctb_parts[cpt].cpt_cpumask);
cpumask_clear_cpu(cpu, cptab->ctb_cpumask);
cptab->ctb_cpu2cpt[cpu] = -1;
node = cpu_to_node(cpu);
LASSERT(node_isset(node, *cptab->ctb_parts[cpt].cpt_nodemask));
LASSERT(node_isset(node, *cptab->ctb_nodemask));
for_each_cpu(i, cptab->ctb_parts[cpt].cpt_cpumask) {
if (cpu_to_node(i) == node)
break;
}
if (i >= nr_cpu_ids)
node_clear(node, *cptab->ctb_parts[cpt].cpt_nodemask);
for_each_cpu(i, cptab->ctb_cpumask) {
if (cpu_to_node(i) == node)
break;
}
if (i >= nr_cpu_ids)
node_clear(node, *cptab->ctb_nodemask);
return;
}
int
cfs_cpt_set_cpumask(struct cfs_cpt_table *cptab, int cpt, cpumask_t *mask)
{
int i;
if (cpumask_weight(mask) == 0 ||
cpumask_any_and(mask, cpu_online_mask) >= nr_cpu_ids) {
CDEBUG(D_INFO, "No online CPU is found in the CPU mask for CPU partition %d\n",
cpt);
return 0;
}
for_each_cpu(i, mask) {
if (!cfs_cpt_set_cpu(cptab, cpt, i))
return 0;
}
return 1;
}
void
cfs_cpt_unset_cpumask(struct cfs_cpt_table *cptab, int cpt, cpumask_t *mask)
{
int i;
for_each_cpu(i, mask)
cfs_cpt_unset_cpu(cptab, cpt, i);
}
int
cfs_cpt_set_node(struct cfs_cpt_table *cptab, int cpt, int node)
{
cpumask_t *mask;
int rc;
if (node < 0 || node >= MAX_NUMNODES) {
CDEBUG(D_INFO,
"Invalid NUMA id %d for CPU partition %d\n", node, cpt);
return 0;
}
mutex_lock(&cpt_data.cpt_mutex);
mask = cpt_data.cpt_cpumask;
cfs_node_to_cpumask(node, mask);
rc = cfs_cpt_set_cpumask(cptab, cpt, mask);
mutex_unlock(&cpt_data.cpt_mutex);
return rc;
}
void
cfs_cpt_unset_node(struct cfs_cpt_table *cptab, int cpt, int node)
{
cpumask_t *mask;
if (node < 0 || node >= MAX_NUMNODES) {
CDEBUG(D_INFO,
"Invalid NUMA id %d for CPU partition %d\n", node, cpt);
return;
}
mutex_lock(&cpt_data.cpt_mutex);
mask = cpt_data.cpt_cpumask;
cfs_node_to_cpumask(node, mask);
cfs_cpt_unset_cpumask(cptab, cpt, mask);
mutex_unlock(&cpt_data.cpt_mutex);
}
int
cfs_cpt_set_nodemask(struct cfs_cpt_table *cptab, int cpt, nodemask_t *mask)
{
int i;
for_each_node_mask(i, *mask) {
if (!cfs_cpt_set_node(cptab, cpt, i))
return 0;
}
return 1;
}
void
cfs_cpt_unset_nodemask(struct cfs_cpt_table *cptab, int cpt, nodemask_t *mask)
{
int i;
for_each_node_mask(i, *mask)
cfs_cpt_unset_node(cptab, cpt, i);
}
void
cfs_cpt_clear(struct cfs_cpt_table *cptab, int cpt)
{
int last;
int i;
if (cpt == CFS_CPT_ANY) {
last = cptab->ctb_nparts - 1;
cpt = 0;
} else {
last = cpt;
}
for (; cpt <= last; cpt++) {
for_each_cpu(i, cptab->ctb_parts[cpt].cpt_cpumask)
cfs_cpt_unset_cpu(cptab, cpt, i);
}
}
int
cfs_cpt_spread_node(struct cfs_cpt_table *cptab, int cpt)
{
nodemask_t *mask;
int weight;
int rotor;
int node;
if (cpt < 0 || cpt >= cptab->ctb_nparts) {
mask = cptab->ctb_nodemask;
rotor = cptab->ctb_spread_rotor++;
} else {
mask = cptab->ctb_parts[cpt].cpt_nodemask;
rotor = cptab->ctb_parts[cpt].cpt_spread_rotor++;
}
weight = nodes_weight(*mask);
LASSERT(weight > 0);
rotor %= weight;
for_each_node_mask(node, *mask) {
if (rotor-- == 0)
return node;
}
LBUG();
return 0;
}
int
cfs_cpt_current(struct cfs_cpt_table *cptab, int remap)
{
int cpu = smp_processor_id();
int cpt = cptab->ctb_cpu2cpt[cpu];
if (cpt < 0) {
if (!remap)
return cpt;
cpt = cpu % cptab->ctb_nparts;
}
return cpt;
}
int
cfs_cpt_of_cpu(struct cfs_cpt_table *cptab, int cpu)
{
LASSERT(cpu >= 0 && cpu < nr_cpu_ids);
return cptab->ctb_cpu2cpt[cpu];
}
int
cfs_cpt_bind(struct cfs_cpt_table *cptab, int cpt)
{
cpumask_t *cpumask;
nodemask_t *nodemask;
int rc;
int i;
LASSERT(cpt == CFS_CPT_ANY || (cpt >= 0 && cpt < cptab->ctb_nparts));
if (cpt == CFS_CPT_ANY) {
cpumask = cptab->ctb_cpumask;
nodemask = cptab->ctb_nodemask;
} else {
cpumask = cptab->ctb_parts[cpt].cpt_cpumask;
nodemask = cptab->ctb_parts[cpt].cpt_nodemask;
}
if (cpumask_any_and(cpumask, cpu_online_mask) >= nr_cpu_ids) {
CERROR("No online CPU found in CPU partition %d, did someone do CPU hotplug on system? You might need to reload Lustre modules to keep system working well.\n",
cpt);
return -EINVAL;
}
for_each_online_cpu(i) {
if (cpumask_test_cpu(i, cpumask))
continue;
rc = set_cpus_allowed_ptr(current, cpumask);
set_mems_allowed(*nodemask);
if (rc == 0)
schedule();
return rc;
}
return 0;
}
static int
cfs_cpt_choose_ncpus(struct cfs_cpt_table *cptab, int cpt,
cpumask_t *node, int number)
{
cpumask_t *socket = NULL;
cpumask_t *core = NULL;
int rc = 0;
int cpu;
LASSERT(number > 0);
if (number >= cpumask_weight(node)) {
while (!cpumask_empty(node)) {
cpu = cpumask_first(node);
rc = cfs_cpt_set_cpu(cptab, cpt, cpu);
if (!rc)
return -EINVAL;
cpumask_clear_cpu(cpu, node);
}
return 0;
}
LIBCFS_ALLOC(socket, cpumask_size());
LIBCFS_ALLOC(core, cpumask_size());
if (socket == NULL || core == NULL) {
rc = -ENOMEM;
goto out;
}
while (!cpumask_empty(node)) {
cpu = cpumask_first(node);
cfs_cpu_core_siblings(cpu, socket);
cpumask_and(socket, socket, node);
LASSERT(!cpumask_empty(socket));
while (!cpumask_empty(socket)) {
int i;
cfs_cpu_ht_siblings(cpu, core);
cpumask_and(core, core, node);
LASSERT(!cpumask_empty(core));
for_each_cpu(i, core) {
cpumask_clear_cpu(i, socket);
cpumask_clear_cpu(i, node);
rc = cfs_cpt_set_cpu(cptab, cpt, i);
if (!rc) {
rc = -EINVAL;
goto out;
}
if (--number == 0)
goto out;
}
cpu = cpumask_first(socket);
}
}
out:
if (socket != NULL)
LIBCFS_FREE(socket, cpumask_size());
if (core != NULL)
LIBCFS_FREE(core, cpumask_size());
return rc;
}
static unsigned int
cfs_cpt_num_estimate(void)
{
unsigned nnode = num_online_nodes();
unsigned ncpu = num_online_cpus();
unsigned ncpt;
if (ncpu <= CPT_WEIGHT_MIN) {
ncpt = 1;
goto out;
}
for (ncpt = 2; ncpu > 2 * ncpt * ncpt; ncpt <<= 1) {}
if (ncpt <= nnode) {
while (nnode > ncpt)
nnode >>= 1;
} else {
while ((nnode << 1) <= ncpt)
nnode <<= 1;
}
ncpt = nnode;
out:
#if (BITS_PER_LONG == 32)
ncpt = min(2U, ncpt);
#endif
while (ncpu % ncpt != 0)
ncpt--;
return ncpt;
}
static struct cfs_cpt_table *
cfs_cpt_table_create(int ncpt)
{
struct cfs_cpt_table *cptab = NULL;
cpumask_t *mask = NULL;
int cpt = 0;
int num;
int rc;
int i;
rc = cfs_cpt_num_estimate();
if (ncpt <= 0)
ncpt = rc;
if (ncpt > num_online_cpus() || ncpt > 4 * rc) {
CWARN("CPU partition number %d is larger than suggested value (%d), your system may have performance issue or run out of memory while under pressure\n",
ncpt, rc);
}
if (num_online_cpus() % ncpt != 0) {
CERROR("CPU number %d is not multiple of cpu_npartition %d, please try different cpu_npartitions value or set pattern string by cpu_pattern=STRING\n",
(int)num_online_cpus(), ncpt);
goto failed;
}
cptab = cfs_cpt_table_alloc(ncpt);
if (cptab == NULL) {
CERROR("Failed to allocate CPU map(%d)\n", ncpt);
goto failed;
}
num = num_online_cpus() / ncpt;
if (num == 0) {
CERROR("CPU changed while setting CPU partition\n");
goto failed;
}
LIBCFS_ALLOC(mask, cpumask_size());
if (mask == NULL) {
CERROR("Failed to allocate scratch cpumask\n");
goto failed;
}
for_each_online_node(i) {
cfs_node_to_cpumask(i, mask);
while (!cpumask_empty(mask)) {
struct cfs_cpu_partition *part;
int n;
if (cpt >= ncpt)
goto failed;
part = &cptab->ctb_parts[cpt];
n = num - cpumask_weight(part->cpt_cpumask);
LASSERT(n > 0);
rc = cfs_cpt_choose_ncpus(cptab, cpt, mask, n);
if (rc < 0)
goto failed;
LASSERT(num >= cpumask_weight(part->cpt_cpumask));
if (num == cpumask_weight(part->cpt_cpumask))
cpt++;
}
}
if (cpt != ncpt ||
num != cpumask_weight(cptab->ctb_parts[ncpt - 1].cpt_cpumask)) {
CERROR("Expect %d(%d) CPU partitions but got %d(%d), CPU hotplug/unplug while setting?\n",
cptab->ctb_nparts, num, cpt,
cpumask_weight(cptab->ctb_parts[ncpt - 1].cpt_cpumask));
goto failed;
}
LIBCFS_FREE(mask, cpumask_size());
return cptab;
failed:
CERROR("Failed to setup CPU-partition-table with %d CPU-partitions, online HW nodes: %d, HW cpus: %d.\n",
ncpt, num_online_nodes(), num_online_cpus());
if (mask != NULL)
LIBCFS_FREE(mask, cpumask_size());
if (cptab != NULL)
cfs_cpt_table_free(cptab);
return NULL;
}
static struct cfs_cpt_table *
cfs_cpt_table_create_pattern(char *pattern)
{
struct cfs_cpt_table *cptab;
char *str = pattern;
int node = 0;
int high;
int ncpt;
int c;
for (ncpt = 0;; ncpt++) {
str = strchr(str, '[');
if (str == NULL)
break;
str++;
}
str = cfs_trimwhite(pattern);
if (*str == 'n' || *str == 'N') {
pattern = str + 1;
node = 1;
}
if (ncpt == 0 ||
(node && ncpt > num_online_nodes()) ||
(!node && ncpt > num_online_cpus())) {
CERROR("Invalid pattern %s, or too many partitions %d\n",
pattern, ncpt);
return NULL;
}
high = node ? MAX_NUMNODES - 1 : nr_cpu_ids - 1;
cptab = cfs_cpt_table_alloc(ncpt);
if (cptab == NULL) {
CERROR("Failed to allocate cpu partition table\n");
return NULL;
}
for (str = cfs_trimwhite(pattern), c = 0;; c++) {
struct cfs_range_expr *range;
struct cfs_expr_list *el;
char *bracket = strchr(str, '[');
int cpt;
int rc;
int i;
int n;
if (bracket == NULL) {
if (*str != 0) {
CERROR("Invalid pattern %s\n", str);
goto failed;
} else if (c != ncpt) {
CERROR("expect %d partitions but found %d\n",
ncpt, c);
goto failed;
}
break;
}
if (sscanf(str, "%d%n", &cpt, &n) < 1) {
CERROR("Invalid cpu pattern %s\n", str);
goto failed;
}
if (cpt < 0 || cpt >= ncpt) {
CERROR("Invalid partition id %d, total partitions %d\n",
cpt, ncpt);
goto failed;
}
if (cfs_cpt_weight(cptab, cpt) != 0) {
CERROR("Partition %d has already been set.\n", cpt);
goto failed;
}
str = cfs_trimwhite(str + n);
if (str != bracket) {
CERROR("Invalid pattern %s\n", str);
goto failed;
}
bracket = strchr(str, ']');
if (bracket == NULL) {
CERROR("missing right bracket for cpt %d, %s\n",
cpt, str);
goto failed;
}
if (cfs_expr_list_parse(str, (bracket - str) + 1,
0, high, &el) != 0) {
CERROR("Can't parse number range: %s\n", str);
goto failed;
}
list_for_each_entry(range, &el->el_exprs, re_link) {
for (i = range->re_lo; i <= range->re_hi; i++) {
if ((i - range->re_lo) % range->re_stride != 0)
continue;
rc = node ? cfs_cpt_set_node(cptab, cpt, i) :
cfs_cpt_set_cpu(cptab, cpt, i);
if (!rc) {
cfs_expr_list_free(el);
goto failed;
}
}
}
cfs_expr_list_free(el);
if (!cfs_cpt_online(cptab, cpt)) {
CERROR("No online CPU is found on partition %d\n", cpt);
goto failed;
}
str = cfs_trimwhite(bracket + 1);
}
return cptab;
failed:
cfs_cpt_table_free(cptab);
return NULL;
}
static int
cfs_cpu_notify(struct notifier_block *self, unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
bool warn;
switch (action) {
case CPU_DEAD:
case CPU_DEAD_FROZEN:
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
spin_lock(&cpt_data.cpt_lock);
cpt_data.cpt_version++;
spin_unlock(&cpt_data.cpt_lock);
default:
if (action != CPU_DEAD && action != CPU_DEAD_FROZEN) {
CDEBUG(D_INFO, "CPU changed [cpu %u action %lx]\n",
cpu, action);
break;
}
mutex_lock(&cpt_data.cpt_mutex);
cfs_cpu_ht_siblings(cpu, cpt_data.cpt_cpumask);
warn = cpumask_any_and(cpt_data.cpt_cpumask,
cpu_online_mask) >= nr_cpu_ids;
mutex_unlock(&cpt_data.cpt_mutex);
CDEBUG(warn ? D_WARNING : D_INFO,
"Lustre: can't support CPU plug-out well now, performance and stability could be impacted [CPU %u action: %lx]\n",
cpu, action);
}
return NOTIFY_OK;
}
void
cfs_cpu_fini(void)
{
if (cfs_cpt_table != NULL)
cfs_cpt_table_free(cfs_cpt_table);
#ifdef CONFIG_HOTPLUG_CPU
unregister_hotcpu_notifier(&cfs_cpu_notifier);
#endif
if (cpt_data.cpt_cpumask != NULL)
LIBCFS_FREE(cpt_data.cpt_cpumask, cpumask_size());
}
int
cfs_cpu_init(void)
{
LASSERT(cfs_cpt_table == NULL);
memset(&cpt_data, 0, sizeof(cpt_data));
LIBCFS_ALLOC(cpt_data.cpt_cpumask, cpumask_size());
if (cpt_data.cpt_cpumask == NULL) {
CERROR("Failed to allocate scratch buffer\n");
return -1;
}
spin_lock_init(&cpt_data.cpt_lock);
mutex_init(&cpt_data.cpt_mutex);
#ifdef CONFIG_HOTPLUG_CPU
register_hotcpu_notifier(&cfs_cpu_notifier);
#endif
if (*cpu_pattern != 0) {
cfs_cpt_table = cfs_cpt_table_create_pattern(cpu_pattern);
if (cfs_cpt_table == NULL) {
CERROR("Failed to create cptab from pattern %s\n",
cpu_pattern);
goto failed;
}
} else {
cfs_cpt_table = cfs_cpt_table_create(cpu_npartitions);
if (cfs_cpt_table == NULL) {
CERROR("Failed to create ptable with npartitions %d\n",
cpu_npartitions);
goto failed;
}
}
spin_lock(&cpt_data.cpt_lock);
if (cfs_cpt_table->ctb_version != cpt_data.cpt_version) {
spin_unlock(&cpt_data.cpt_lock);
CERROR("CPU hotplug/unplug during setup\n");
goto failed;
}
spin_unlock(&cpt_data.cpt_lock);
LCONSOLE(0, "HW CPU cores: %d, npartitions: %d\n",
num_online_cpus(), cfs_cpt_number(cfs_cpt_table));
return 0;
failed:
cfs_cpu_fini();
return -1;
}
