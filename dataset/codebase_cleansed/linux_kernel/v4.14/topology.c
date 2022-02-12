static int __init sched_debug_setup(char *str)
{
sched_debug_enabled = true;
return 0;
}
static inline bool sched_debug(void)
{
return sched_debug_enabled;
}
static int sched_domain_debug_one(struct sched_domain *sd, int cpu, int level,
struct cpumask *groupmask)
{
struct sched_group *group = sd->groups;
cpumask_clear(groupmask);
printk(KERN_DEBUG "%*s domain-%d: ", level, "", level);
if (!(sd->flags & SD_LOAD_BALANCE)) {
printk("does not load-balance\n");
if (sd->parent)
printk(KERN_ERR "ERROR: !SD_LOAD_BALANCE domain"
" has parent");
return -1;
}
printk(KERN_CONT "span=%*pbl level=%s\n",
cpumask_pr_args(sched_domain_span(sd)), sd->name);
if (!cpumask_test_cpu(cpu, sched_domain_span(sd))) {
printk(KERN_ERR "ERROR: domain->span does not contain "
"CPU%d\n", cpu);
}
if (!cpumask_test_cpu(cpu, sched_group_span(group))) {
printk(KERN_ERR "ERROR: domain->groups does not contain"
" CPU%d\n", cpu);
}
printk(KERN_DEBUG "%*s groups:", level + 1, "");
do {
if (!group) {
printk("\n");
printk(KERN_ERR "ERROR: group is NULL\n");
break;
}
if (!cpumask_weight(sched_group_span(group))) {
printk(KERN_CONT "\n");
printk(KERN_ERR "ERROR: empty group\n");
break;
}
if (!(sd->flags & SD_OVERLAP) &&
cpumask_intersects(groupmask, sched_group_span(group))) {
printk(KERN_CONT "\n");
printk(KERN_ERR "ERROR: repeated CPUs\n");
break;
}
cpumask_or(groupmask, groupmask, sched_group_span(group));
printk(KERN_CONT " %d:{ span=%*pbl",
group->sgc->id,
cpumask_pr_args(sched_group_span(group)));
if ((sd->flags & SD_OVERLAP) &&
!cpumask_equal(group_balance_mask(group), sched_group_span(group))) {
printk(KERN_CONT " mask=%*pbl",
cpumask_pr_args(group_balance_mask(group)));
}
if (group->sgc->capacity != SCHED_CAPACITY_SCALE)
printk(KERN_CONT " cap=%lu", group->sgc->capacity);
if (group == sd->groups && sd->child &&
!cpumask_equal(sched_domain_span(sd->child),
sched_group_span(group))) {
printk(KERN_ERR "ERROR: domain->groups does not match domain->child\n");
}
printk(KERN_CONT " }");
group = group->next;
if (group != sd->groups)
printk(KERN_CONT ",");
} while (group != sd->groups);
printk(KERN_CONT "\n");
if (!cpumask_equal(sched_domain_span(sd), groupmask))
printk(KERN_ERR "ERROR: groups don't span domain->span\n");
if (sd->parent &&
!cpumask_subset(groupmask, sched_domain_span(sd->parent)))
printk(KERN_ERR "ERROR: parent span is not a superset "
"of domain->span\n");
return 0;
}
static void sched_domain_debug(struct sched_domain *sd, int cpu)
{
int level = 0;
if (!sched_debug_enabled)
return;
if (!sd) {
printk(KERN_DEBUG "CPU%d attaching NULL sched-domain.\n", cpu);
return;
}
printk(KERN_DEBUG "CPU%d attaching sched-domain(s):\n", cpu);
for (;;) {
if (sched_domain_debug_one(sd, cpu, level, sched_domains_tmpmask))
break;
level++;
sd = sd->parent;
if (!sd)
break;
}
}
static inline bool sched_debug(void)
{
return false;
}
static int sd_degenerate(struct sched_domain *sd)
{
if (cpumask_weight(sched_domain_span(sd)) == 1)
return 1;
if (sd->flags & (SD_LOAD_BALANCE |
SD_BALANCE_NEWIDLE |
SD_BALANCE_FORK |
SD_BALANCE_EXEC |
SD_SHARE_CPUCAPACITY |
SD_ASYM_CPUCAPACITY |
SD_SHARE_PKG_RESOURCES |
SD_SHARE_POWERDOMAIN)) {
if (sd->groups != sd->groups->next)
return 0;
}
if (sd->flags & (SD_WAKE_AFFINE))
return 0;
return 1;
}
static int
sd_parent_degenerate(struct sched_domain *sd, struct sched_domain *parent)
{
unsigned long cflags = sd->flags, pflags = parent->flags;
if (sd_degenerate(parent))
return 1;
if (!cpumask_equal(sched_domain_span(sd), sched_domain_span(parent)))
return 0;
if (parent->groups == parent->groups->next) {
pflags &= ~(SD_LOAD_BALANCE |
SD_BALANCE_NEWIDLE |
SD_BALANCE_FORK |
SD_BALANCE_EXEC |
SD_ASYM_CPUCAPACITY |
SD_SHARE_CPUCAPACITY |
SD_SHARE_PKG_RESOURCES |
SD_PREFER_SIBLING |
SD_SHARE_POWERDOMAIN);
if (nr_node_ids == 1)
pflags &= ~SD_SERIALIZE;
}
if (~cflags & pflags)
return 0;
return 1;
}
static void free_rootdomain(struct rcu_head *rcu)
{
struct root_domain *rd = container_of(rcu, struct root_domain, rcu);
cpupri_cleanup(&rd->cpupri);
cpudl_cleanup(&rd->cpudl);
free_cpumask_var(rd->dlo_mask);
free_cpumask_var(rd->rto_mask);
free_cpumask_var(rd->online);
free_cpumask_var(rd->span);
kfree(rd);
}
void rq_attach_root(struct rq *rq, struct root_domain *rd)
{
struct root_domain *old_rd = NULL;
unsigned long flags;
raw_spin_lock_irqsave(&rq->lock, flags);
if (rq->rd) {
old_rd = rq->rd;
if (cpumask_test_cpu(rq->cpu, old_rd->online))
set_rq_offline(rq);
cpumask_clear_cpu(rq->cpu, old_rd->span);
if (!atomic_dec_and_test(&old_rd->refcount))
old_rd = NULL;
}
atomic_inc(&rd->refcount);
rq->rd = rd;
cpumask_set_cpu(rq->cpu, rd->span);
if (cpumask_test_cpu(rq->cpu, cpu_active_mask))
set_rq_online(rq);
raw_spin_unlock_irqrestore(&rq->lock, flags);
if (old_rd)
call_rcu_sched(&old_rd->rcu, free_rootdomain);
}
static int init_rootdomain(struct root_domain *rd)
{
if (!zalloc_cpumask_var(&rd->span, GFP_KERNEL))
goto out;
if (!zalloc_cpumask_var(&rd->online, GFP_KERNEL))
goto free_span;
if (!zalloc_cpumask_var(&rd->dlo_mask, GFP_KERNEL))
goto free_online;
if (!zalloc_cpumask_var(&rd->rto_mask, GFP_KERNEL))
goto free_dlo_mask;
init_dl_bw(&rd->dl_bw);
if (cpudl_init(&rd->cpudl) != 0)
goto free_rto_mask;
if (cpupri_init(&rd->cpupri) != 0)
goto free_cpudl;
return 0;
free_cpudl:
cpudl_cleanup(&rd->cpudl);
free_rto_mask:
free_cpumask_var(rd->rto_mask);
free_dlo_mask:
free_cpumask_var(rd->dlo_mask);
free_online:
free_cpumask_var(rd->online);
free_span:
free_cpumask_var(rd->span);
out:
return -ENOMEM;
}
void init_defrootdomain(void)
{
init_rootdomain(&def_root_domain);
atomic_set(&def_root_domain.refcount, 1);
}
static struct root_domain *alloc_rootdomain(void)
{
struct root_domain *rd;
rd = kzalloc(sizeof(*rd), GFP_KERNEL);
if (!rd)
return NULL;
if (init_rootdomain(rd) != 0) {
kfree(rd);
return NULL;
}
return rd;
}
static void free_sched_groups(struct sched_group *sg, int free_sgc)
{
struct sched_group *tmp, *first;
if (!sg)
return;
first = sg;
do {
tmp = sg->next;
if (free_sgc && atomic_dec_and_test(&sg->sgc->ref))
kfree(sg->sgc);
if (atomic_dec_and_test(&sg->ref))
kfree(sg);
sg = tmp;
} while (sg != first);
}
static void destroy_sched_domain(struct sched_domain *sd)
{
free_sched_groups(sd->groups, 1);
if (sd->shared && atomic_dec_and_test(&sd->shared->ref))
kfree(sd->shared);
kfree(sd);
}
static void destroy_sched_domains_rcu(struct rcu_head *rcu)
{
struct sched_domain *sd = container_of(rcu, struct sched_domain, rcu);
while (sd) {
struct sched_domain *parent = sd->parent;
destroy_sched_domain(sd);
sd = parent;
}
}
static void destroy_sched_domains(struct sched_domain *sd)
{
if (sd)
call_rcu(&sd->rcu, destroy_sched_domains_rcu);
}
static void update_top_cache_domain(int cpu)
{
struct sched_domain_shared *sds = NULL;
struct sched_domain *sd;
int id = cpu;
int size = 1;
sd = highest_flag_domain(cpu, SD_SHARE_PKG_RESOURCES);
if (sd) {
id = cpumask_first(sched_domain_span(sd));
size = cpumask_weight(sched_domain_span(sd));
sds = sd->shared;
}
rcu_assign_pointer(per_cpu(sd_llc, cpu), sd);
per_cpu(sd_llc_size, cpu) = size;
per_cpu(sd_llc_id, cpu) = id;
rcu_assign_pointer(per_cpu(sd_llc_shared, cpu), sds);
sd = lowest_flag_domain(cpu, SD_NUMA);
rcu_assign_pointer(per_cpu(sd_numa, cpu), sd);
sd = highest_flag_domain(cpu, SD_ASYM_PACKING);
rcu_assign_pointer(per_cpu(sd_asym, cpu), sd);
}
static void
cpu_attach_domain(struct sched_domain *sd, struct root_domain *rd, int cpu)
{
struct rq *rq = cpu_rq(cpu);
struct sched_domain *tmp;
for (tmp = sd; tmp; ) {
struct sched_domain *parent = tmp->parent;
if (!parent)
break;
if (sd_parent_degenerate(tmp, parent)) {
tmp->parent = parent->parent;
if (parent->parent)
parent->parent->child = tmp;
if (parent->flags & SD_PREFER_SIBLING)
tmp->flags |= SD_PREFER_SIBLING;
destroy_sched_domain(parent);
} else
tmp = tmp->parent;
}
if (sd && sd_degenerate(sd)) {
tmp = sd;
sd = sd->parent;
destroy_sched_domain(tmp);
if (sd)
sd->child = NULL;
}
sched_domain_debug(sd, cpu);
rq_attach_root(rq, rd);
tmp = rq->sd;
rcu_assign_pointer(rq->sd, sd);
dirty_sched_domain_sysctl(cpu);
destroy_sched_domains(tmp);
update_top_cache_domain(cpu);
}
static int __init isolated_cpu_setup(char *str)
{
int ret;
alloc_bootmem_cpumask_var(&cpu_isolated_map);
ret = cpulist_parse(str, cpu_isolated_map);
if (ret) {
pr_err("sched: Error, all isolcpus= values must be between 0 and %u\n", nr_cpu_ids);
return 0;
}
return 1;
}
int group_balance_cpu(struct sched_group *sg)
{
return cpumask_first(group_balance_mask(sg));
}
static void
build_balance_mask(struct sched_domain *sd, struct sched_group *sg, struct cpumask *mask)
{
const struct cpumask *sg_span = sched_group_span(sg);
struct sd_data *sdd = sd->private;
struct sched_domain *sibling;
int i;
cpumask_clear(mask);
for_each_cpu(i, sg_span) {
sibling = *per_cpu_ptr(sdd->sd, i);
if (!sibling->child)
continue;
if (!cpumask_equal(sg_span, sched_domain_span(sibling->child)))
continue;
cpumask_set_cpu(i, mask);
}
WARN_ON_ONCE(cpumask_empty(mask));
}
static struct sched_group *
build_group_from_child_sched_domain(struct sched_domain *sd, int cpu)
{
struct sched_group *sg;
struct cpumask *sg_span;
sg = kzalloc_node(sizeof(struct sched_group) + cpumask_size(),
GFP_KERNEL, cpu_to_node(cpu));
if (!sg)
return NULL;
sg_span = sched_group_span(sg);
if (sd->child)
cpumask_copy(sg_span, sched_domain_span(sd->child));
else
cpumask_copy(sg_span, sched_domain_span(sd));
atomic_inc(&sg->ref);
return sg;
}
static void init_overlap_sched_group(struct sched_domain *sd,
struct sched_group *sg)
{
struct cpumask *mask = sched_domains_tmpmask2;
struct sd_data *sdd = sd->private;
struct cpumask *sg_span;
int cpu;
build_balance_mask(sd, sg, mask);
cpu = cpumask_first_and(sched_group_span(sg), mask);
sg->sgc = *per_cpu_ptr(sdd->sgc, cpu);
if (atomic_inc_return(&sg->sgc->ref) == 1)
cpumask_copy(group_balance_mask(sg), mask);
else
WARN_ON_ONCE(!cpumask_equal(group_balance_mask(sg), mask));
sg_span = sched_group_span(sg);
sg->sgc->capacity = SCHED_CAPACITY_SCALE * cpumask_weight(sg_span);
sg->sgc->min_capacity = SCHED_CAPACITY_SCALE;
}
static int
build_overlap_sched_groups(struct sched_domain *sd, int cpu)
{
struct sched_group *first = NULL, *last = NULL, *sg;
const struct cpumask *span = sched_domain_span(sd);
struct cpumask *covered = sched_domains_tmpmask;
struct sd_data *sdd = sd->private;
struct sched_domain *sibling;
int i;
cpumask_clear(covered);
for_each_cpu_wrap(i, span, cpu) {
struct cpumask *sg_span;
if (cpumask_test_cpu(i, covered))
continue;
sibling = *per_cpu_ptr(sdd->sd, i);
if (!cpumask_test_cpu(i, sched_domain_span(sibling)))
continue;
sg = build_group_from_child_sched_domain(sibling, cpu);
if (!sg)
goto fail;
sg_span = sched_group_span(sg);
cpumask_or(covered, covered, sg_span);
init_overlap_sched_group(sd, sg);
if (!first)
first = sg;
if (last)
last->next = sg;
last = sg;
last->next = first;
}
sd->groups = first;
return 0;
fail:
free_sched_groups(first, 0);
return -ENOMEM;
}
static struct sched_group *get_group(int cpu, struct sd_data *sdd)
{
struct sched_domain *sd = *per_cpu_ptr(sdd->sd, cpu);
struct sched_domain *child = sd->child;
struct sched_group *sg;
if (child)
cpu = cpumask_first(sched_domain_span(child));
sg = *per_cpu_ptr(sdd->sg, cpu);
sg->sgc = *per_cpu_ptr(sdd->sgc, cpu);
atomic_inc(&sg->ref);
atomic_inc(&sg->sgc->ref);
if (child) {
cpumask_copy(sched_group_span(sg), sched_domain_span(child));
cpumask_copy(group_balance_mask(sg), sched_group_span(sg));
} else {
cpumask_set_cpu(cpu, sched_group_span(sg));
cpumask_set_cpu(cpu, group_balance_mask(sg));
}
sg->sgc->capacity = SCHED_CAPACITY_SCALE * cpumask_weight(sched_group_span(sg));
sg->sgc->min_capacity = SCHED_CAPACITY_SCALE;
return sg;
}
static int
build_sched_groups(struct sched_domain *sd, int cpu)
{
struct sched_group *first = NULL, *last = NULL;
struct sd_data *sdd = sd->private;
const struct cpumask *span = sched_domain_span(sd);
struct cpumask *covered;
int i;
lockdep_assert_held(&sched_domains_mutex);
covered = sched_domains_tmpmask;
cpumask_clear(covered);
for_each_cpu_wrap(i, span, cpu) {
struct sched_group *sg;
if (cpumask_test_cpu(i, covered))
continue;
sg = get_group(i, sdd);
cpumask_or(covered, covered, sched_group_span(sg));
if (!first)
first = sg;
if (last)
last->next = sg;
last = sg;
}
last->next = first;
sd->groups = first;
return 0;
}
static void init_sched_groups_capacity(int cpu, struct sched_domain *sd)
{
struct sched_group *sg = sd->groups;
WARN_ON(!sg);
do {
int cpu, max_cpu = -1;
sg->group_weight = cpumask_weight(sched_group_span(sg));
if (!(sd->flags & SD_ASYM_PACKING))
goto next;
for_each_cpu(cpu, sched_group_span(sg)) {
if (max_cpu < 0)
max_cpu = cpu;
else if (sched_asym_prefer(cpu, max_cpu))
max_cpu = cpu;
}
sg->asym_prefer_cpu = max_cpu;
next:
sg = sg->next;
} while (sg != sd->groups);
if (cpu != group_balance_cpu(sg))
return;
update_group_capacity(sd, cpu);
}
static int __init setup_relax_domain_level(char *str)
{
if (kstrtoint(str, 0, &default_relax_domain_level))
pr_warn("Unable to set relax_domain_level\n");
return 1;
}
static void set_domain_attribute(struct sched_domain *sd,
struct sched_domain_attr *attr)
{
int request;
if (!attr || attr->relax_domain_level < 0) {
if (default_relax_domain_level < 0)
return;
else
request = default_relax_domain_level;
} else
request = attr->relax_domain_level;
if (request < sd->level) {
sd->flags &= ~(SD_BALANCE_WAKE|SD_BALANCE_NEWIDLE);
} else {
sd->flags |= (SD_BALANCE_WAKE|SD_BALANCE_NEWIDLE);
}
}
static void __free_domain_allocs(struct s_data *d, enum s_alloc what,
const struct cpumask *cpu_map)
{
switch (what) {
case sa_rootdomain:
if (!atomic_read(&d->rd->refcount))
free_rootdomain(&d->rd->rcu);
case sa_sd:
free_percpu(d->sd);
case sa_sd_storage:
__sdt_free(cpu_map);
case sa_none:
break;
}
}
static enum s_alloc
__visit_domain_allocation_hell(struct s_data *d, const struct cpumask *cpu_map)
{
memset(d, 0, sizeof(*d));
if (__sdt_alloc(cpu_map))
return sa_sd_storage;
d->sd = alloc_percpu(struct sched_domain *);
if (!d->sd)
return sa_sd_storage;
d->rd = alloc_rootdomain();
if (!d->rd)
return sa_sd;
return sa_rootdomain;
}
static void claim_allocations(int cpu, struct sched_domain *sd)
{
struct sd_data *sdd = sd->private;
WARN_ON_ONCE(*per_cpu_ptr(sdd->sd, cpu) != sd);
*per_cpu_ptr(sdd->sd, cpu) = NULL;
if (atomic_read(&(*per_cpu_ptr(sdd->sds, cpu))->ref))
*per_cpu_ptr(sdd->sds, cpu) = NULL;
if (atomic_read(&(*per_cpu_ptr(sdd->sg, cpu))->ref))
*per_cpu_ptr(sdd->sg, cpu) = NULL;
if (atomic_read(&(*per_cpu_ptr(sdd->sgc, cpu))->ref))
*per_cpu_ptr(sdd->sgc, cpu) = NULL;
}
static struct sched_domain *
sd_init(struct sched_domain_topology_level *tl,
const struct cpumask *cpu_map,
struct sched_domain *child, int cpu)
{
struct sd_data *sdd = &tl->data;
struct sched_domain *sd = *per_cpu_ptr(sdd->sd, cpu);
int sd_id, sd_weight, sd_flags = 0;
#ifdef CONFIG_NUMA
sched_domains_curr_level = tl->numa_level;
#endif
sd_weight = cpumask_weight(tl->mask(cpu));
if (tl->sd_flags)
sd_flags = (*tl->sd_flags)();
if (WARN_ONCE(sd_flags & ~TOPOLOGY_SD_FLAGS,
"wrong sd_flags in topology description\n"))
sd_flags &= ~TOPOLOGY_SD_FLAGS;
*sd = (struct sched_domain){
.min_interval = sd_weight,
.max_interval = 2*sd_weight,
.busy_factor = 32,
.imbalance_pct = 125,
.cache_nice_tries = 0,
.busy_idx = 0,
.idle_idx = 0,
.newidle_idx = 0,
.wake_idx = 0,
.forkexec_idx = 0,
.flags = 1*SD_LOAD_BALANCE
| 1*SD_BALANCE_NEWIDLE
| 1*SD_BALANCE_EXEC
| 1*SD_BALANCE_FORK
| 0*SD_BALANCE_WAKE
| 1*SD_WAKE_AFFINE
| 0*SD_SHARE_CPUCAPACITY
| 0*SD_SHARE_PKG_RESOURCES
| 0*SD_SERIALIZE
| 0*SD_PREFER_SIBLING
| 0*SD_NUMA
| sd_flags
,
.last_balance = jiffies,
.balance_interval = sd_weight,
.smt_gain = 0,
.max_newidle_lb_cost = 0,
.next_decay_max_lb_cost = jiffies,
.child = child,
#ifdef CONFIG_SCHED_DEBUG
.name = tl->name,
#endif
};
cpumask_and(sched_domain_span(sd), cpu_map, tl->mask(cpu));
sd_id = cpumask_first(sched_domain_span(sd));
if (sd->flags & SD_ASYM_CPUCAPACITY) {
struct sched_domain *t = sd;
for_each_lower_domain(t)
t->flags |= SD_BALANCE_WAKE;
}
if (sd->flags & SD_SHARE_CPUCAPACITY) {
sd->flags |= SD_PREFER_SIBLING;
sd->imbalance_pct = 110;
sd->smt_gain = 1178;
} else if (sd->flags & SD_SHARE_PKG_RESOURCES) {
sd->imbalance_pct = 117;
sd->cache_nice_tries = 1;
sd->busy_idx = 2;
#ifdef CONFIG_NUMA
} else if (sd->flags & SD_NUMA) {
sd->cache_nice_tries = 2;
sd->busy_idx = 3;
sd->idle_idx = 2;
sd->flags |= SD_SERIALIZE;
if (sched_domains_numa_distance[tl->numa_level] > RECLAIM_DISTANCE) {
sd->flags &= ~(SD_BALANCE_EXEC |
SD_BALANCE_FORK |
SD_WAKE_AFFINE);
}
#endif
} else {
sd->flags |= SD_PREFER_SIBLING;
sd->cache_nice_tries = 1;
sd->busy_idx = 2;
sd->idle_idx = 1;
}
if (sd->flags & SD_SHARE_PKG_RESOURCES) {
sd->shared = *per_cpu_ptr(sdd->sds, sd_id);
atomic_inc(&sd->shared->ref);
atomic_set(&sd->shared->nr_busy_cpus, sd_weight);
}
sd->private = sdd;
return sd;
}
void set_sched_topology(struct sched_domain_topology_level *tl)
{
if (WARN_ON_ONCE(sched_smp_initialized))
return;
sched_domain_topology = tl;
}
static const struct cpumask *sd_numa_mask(int cpu)
{
return sched_domains_numa_masks[sched_domains_curr_level][cpu_to_node(cpu)];
}
static void sched_numa_warn(const char *str)
{
static int done = false;
int i,j;
if (done)
return;
done = true;
printk(KERN_WARNING "ERROR: %s\n\n", str);
for (i = 0; i < nr_node_ids; i++) {
printk(KERN_WARNING " ");
for (j = 0; j < nr_node_ids; j++)
printk(KERN_CONT "%02d ", node_distance(i,j));
printk(KERN_CONT "\n");
}
printk(KERN_WARNING "\n");
}
bool find_numa_distance(int distance)
{
int i;
if (distance == node_distance(0, 0))
return true;
for (i = 0; i < sched_domains_numa_levels; i++) {
if (sched_domains_numa_distance[i] == distance)
return true;
}
return false;
}
static void init_numa_topology_type(void)
{
int a, b, c, n;
n = sched_max_numa_distance;
if (sched_domains_numa_levels <= 1) {
sched_numa_topology_type = NUMA_DIRECT;
return;
}
for_each_online_node(a) {
for_each_online_node(b) {
if (node_distance(a, b) < n)
continue;
for_each_online_node(c) {
if (node_distance(a, c) < n &&
node_distance(b, c) < n) {
sched_numa_topology_type =
NUMA_GLUELESS_MESH;
return;
}
}
sched_numa_topology_type = NUMA_BACKPLANE;
return;
}
}
}
void sched_init_numa(void)
{
int next_distance, curr_distance = node_distance(0, 0);
struct sched_domain_topology_level *tl;
int level = 0;
int i, j, k;
sched_domains_numa_distance = kzalloc(sizeof(int) * nr_node_ids, GFP_KERNEL);
if (!sched_domains_numa_distance)
return;
next_distance = curr_distance;
for (i = 0; i < nr_node_ids; i++) {
for (j = 0; j < nr_node_ids; j++) {
for (k = 0; k < nr_node_ids; k++) {
int distance = node_distance(i, k);
if (distance > curr_distance &&
(distance < next_distance ||
next_distance == curr_distance))
next_distance = distance;
if (sched_debug() && node_distance(k, i) != distance)
sched_numa_warn("Node-distance not symmetric");
if (sched_debug() && i && !find_numa_distance(distance))
sched_numa_warn("Node-0 not representative");
}
if (next_distance != curr_distance) {
sched_domains_numa_distance[level++] = next_distance;
sched_domains_numa_levels = level;
curr_distance = next_distance;
} else break;
}
if (!sched_debug())
break;
}
if (!level)
return;
sched_domains_numa_levels = 0;
sched_domains_numa_masks = kzalloc(sizeof(void *) * level, GFP_KERNEL);
if (!sched_domains_numa_masks)
return;
for (i = 0; i < level; i++) {
sched_domains_numa_masks[i] =
kzalloc(nr_node_ids * sizeof(void *), GFP_KERNEL);
if (!sched_domains_numa_masks[i])
return;
for (j = 0; j < nr_node_ids; j++) {
struct cpumask *mask = kzalloc(cpumask_size(), GFP_KERNEL);
if (!mask)
return;
sched_domains_numa_masks[i][j] = mask;
for_each_node(k) {
if (node_distance(j, k) > sched_domains_numa_distance[i])
continue;
cpumask_or(mask, mask, cpumask_of_node(k));
}
}
}
for (i = 0; sched_domain_topology[i].mask; i++);
tl = kzalloc((i + level + 1) *
sizeof(struct sched_domain_topology_level), GFP_KERNEL);
if (!tl)
return;
for (i = 0; sched_domain_topology[i].mask; i++)
tl[i] = sched_domain_topology[i];
for (j = 0; j < level; i++, j++) {
tl[i] = (struct sched_domain_topology_level){
.mask = sd_numa_mask,
.sd_flags = cpu_numa_flags,
.flags = SDTL_OVERLAP,
.numa_level = j,
SD_INIT_NAME(NUMA)
};
}
sched_domain_topology = tl;
sched_domains_numa_levels = level;
sched_max_numa_distance = sched_domains_numa_distance[level - 1];
init_numa_topology_type();
}
void sched_domains_numa_masks_set(unsigned int cpu)
{
int node = cpu_to_node(cpu);
int i, j;
for (i = 0; i < sched_domains_numa_levels; i++) {
for (j = 0; j < nr_node_ids; j++) {
if (node_distance(j, node) <= sched_domains_numa_distance[i])
cpumask_set_cpu(cpu, sched_domains_numa_masks[i][j]);
}
}
}
void sched_domains_numa_masks_clear(unsigned int cpu)
{
int i, j;
for (i = 0; i < sched_domains_numa_levels; i++) {
for (j = 0; j < nr_node_ids; j++)
cpumask_clear_cpu(cpu, sched_domains_numa_masks[i][j]);
}
}
static int __sdt_alloc(const struct cpumask *cpu_map)
{
struct sched_domain_topology_level *tl;
int j;
for_each_sd_topology(tl) {
struct sd_data *sdd = &tl->data;
sdd->sd = alloc_percpu(struct sched_domain *);
if (!sdd->sd)
return -ENOMEM;
sdd->sds = alloc_percpu(struct sched_domain_shared *);
if (!sdd->sds)
return -ENOMEM;
sdd->sg = alloc_percpu(struct sched_group *);
if (!sdd->sg)
return -ENOMEM;
sdd->sgc = alloc_percpu(struct sched_group_capacity *);
if (!sdd->sgc)
return -ENOMEM;
for_each_cpu(j, cpu_map) {
struct sched_domain *sd;
struct sched_domain_shared *sds;
struct sched_group *sg;
struct sched_group_capacity *sgc;
sd = kzalloc_node(sizeof(struct sched_domain) + cpumask_size(),
GFP_KERNEL, cpu_to_node(j));
if (!sd)
return -ENOMEM;
*per_cpu_ptr(sdd->sd, j) = sd;
sds = kzalloc_node(sizeof(struct sched_domain_shared),
GFP_KERNEL, cpu_to_node(j));
if (!sds)
return -ENOMEM;
*per_cpu_ptr(sdd->sds, j) = sds;
sg = kzalloc_node(sizeof(struct sched_group) + cpumask_size(),
GFP_KERNEL, cpu_to_node(j));
if (!sg)
return -ENOMEM;
sg->next = sg;
*per_cpu_ptr(sdd->sg, j) = sg;
sgc = kzalloc_node(sizeof(struct sched_group_capacity) + cpumask_size(),
GFP_KERNEL, cpu_to_node(j));
if (!sgc)
return -ENOMEM;
#ifdef CONFIG_SCHED_DEBUG
sgc->id = j;
#endif
*per_cpu_ptr(sdd->sgc, j) = sgc;
}
}
return 0;
}
static void __sdt_free(const struct cpumask *cpu_map)
{
struct sched_domain_topology_level *tl;
int j;
for_each_sd_topology(tl) {
struct sd_data *sdd = &tl->data;
for_each_cpu(j, cpu_map) {
struct sched_domain *sd;
if (sdd->sd) {
sd = *per_cpu_ptr(sdd->sd, j);
if (sd && (sd->flags & SD_OVERLAP))
free_sched_groups(sd->groups, 0);
kfree(*per_cpu_ptr(sdd->sd, j));
}
if (sdd->sds)
kfree(*per_cpu_ptr(sdd->sds, j));
if (sdd->sg)
kfree(*per_cpu_ptr(sdd->sg, j));
if (sdd->sgc)
kfree(*per_cpu_ptr(sdd->sgc, j));
}
free_percpu(sdd->sd);
sdd->sd = NULL;
free_percpu(sdd->sds);
sdd->sds = NULL;
free_percpu(sdd->sg);
sdd->sg = NULL;
free_percpu(sdd->sgc);
sdd->sgc = NULL;
}
}
static struct sched_domain *build_sched_domain(struct sched_domain_topology_level *tl,
const struct cpumask *cpu_map, struct sched_domain_attr *attr,
struct sched_domain *child, int cpu)
{
struct sched_domain *sd = sd_init(tl, cpu_map, child, cpu);
if (child) {
sd->level = child->level + 1;
sched_domain_level_max = max(sched_domain_level_max, sd->level);
child->parent = sd;
if (!cpumask_subset(sched_domain_span(child),
sched_domain_span(sd))) {
pr_err("BUG: arch topology borken\n");
#ifdef CONFIG_SCHED_DEBUG
pr_err(" the %s domain not a subset of the %s domain\n",
child->name, sd->name);
#endif
cpumask_or(sched_domain_span(sd),
sched_domain_span(sd),
sched_domain_span(child));
}
}
set_domain_attribute(sd, attr);
return sd;
}
static int
build_sched_domains(const struct cpumask *cpu_map, struct sched_domain_attr *attr)
{
enum s_alloc alloc_state;
struct sched_domain *sd;
struct s_data d;
struct rq *rq = NULL;
int i, ret = -ENOMEM;
alloc_state = __visit_domain_allocation_hell(&d, cpu_map);
if (alloc_state != sa_rootdomain)
goto error;
for_each_cpu(i, cpu_map) {
struct sched_domain_topology_level *tl;
sd = NULL;
for_each_sd_topology(tl) {
sd = build_sched_domain(tl, cpu_map, attr, sd, i);
if (tl == sched_domain_topology)
*per_cpu_ptr(d.sd, i) = sd;
if (tl->flags & SDTL_OVERLAP)
sd->flags |= SD_OVERLAP;
if (cpumask_equal(cpu_map, sched_domain_span(sd)))
break;
}
}
for_each_cpu(i, cpu_map) {
for (sd = *per_cpu_ptr(d.sd, i); sd; sd = sd->parent) {
sd->span_weight = cpumask_weight(sched_domain_span(sd));
if (sd->flags & SD_OVERLAP) {
if (build_overlap_sched_groups(sd, i))
goto error;
} else {
if (build_sched_groups(sd, i))
goto error;
}
}
}
for (i = nr_cpumask_bits-1; i >= 0; i--) {
if (!cpumask_test_cpu(i, cpu_map))
continue;
for (sd = *per_cpu_ptr(d.sd, i); sd; sd = sd->parent) {
claim_allocations(i, sd);
init_sched_groups_capacity(i, sd);
}
}
rcu_read_lock();
for_each_cpu(i, cpu_map) {
rq = cpu_rq(i);
sd = *per_cpu_ptr(d.sd, i);
if (rq->cpu_capacity_orig > READ_ONCE(d.rd->max_cpu_capacity))
WRITE_ONCE(d.rd->max_cpu_capacity, rq->cpu_capacity_orig);
cpu_attach_domain(sd, d.rd, i);
}
rcu_read_unlock();
if (rq && sched_debug_enabled) {
pr_info("span: %*pbl (max cpu_capacity = %lu)\n",
cpumask_pr_args(cpu_map), rq->rd->max_cpu_capacity);
}
ret = 0;
error:
__free_domain_allocs(&d, alloc_state, cpu_map);
return ret;
}
int __weak arch_update_cpu_topology(void)
{
return 0;
}
cpumask_var_t *alloc_sched_domains(unsigned int ndoms)
{
int i;
cpumask_var_t *doms;
doms = kmalloc(sizeof(*doms) * ndoms, GFP_KERNEL);
if (!doms)
return NULL;
for (i = 0; i < ndoms; i++) {
if (!alloc_cpumask_var(&doms[i], GFP_KERNEL)) {
free_sched_domains(doms, i);
return NULL;
}
}
return doms;
}
void free_sched_domains(cpumask_var_t doms[], unsigned int ndoms)
{
unsigned int i;
for (i = 0; i < ndoms; i++)
free_cpumask_var(doms[i]);
kfree(doms);
}
int sched_init_domains(const struct cpumask *cpu_map)
{
int err;
zalloc_cpumask_var(&sched_domains_tmpmask, GFP_KERNEL);
zalloc_cpumask_var(&sched_domains_tmpmask2, GFP_KERNEL);
zalloc_cpumask_var(&fallback_doms, GFP_KERNEL);
arch_update_cpu_topology();
ndoms_cur = 1;
doms_cur = alloc_sched_domains(ndoms_cur);
if (!doms_cur)
doms_cur = &fallback_doms;
cpumask_andnot(doms_cur[0], cpu_map, cpu_isolated_map);
err = build_sched_domains(doms_cur[0], NULL);
register_sched_domain_sysctl();
return err;
}
static void detach_destroy_domains(const struct cpumask *cpu_map)
{
int i;
rcu_read_lock();
for_each_cpu(i, cpu_map)
cpu_attach_domain(NULL, &def_root_domain, i);
rcu_read_unlock();
}
static int dattrs_equal(struct sched_domain_attr *cur, int idx_cur,
struct sched_domain_attr *new, int idx_new)
{
struct sched_domain_attr tmp;
if (!new && !cur)
return 1;
tmp = SD_ATTR_INIT;
return !memcmp(cur ? (cur + idx_cur) : &tmp,
new ? (new + idx_new) : &tmp,
sizeof(struct sched_domain_attr));
}
void partition_sched_domains(int ndoms_new, cpumask_var_t doms_new[],
struct sched_domain_attr *dattr_new)
{
int i, j, n;
int new_topology;
mutex_lock(&sched_domains_mutex);
unregister_sched_domain_sysctl();
new_topology = arch_update_cpu_topology();
if (!doms_new) {
WARN_ON_ONCE(dattr_new);
n = 0;
doms_new = alloc_sched_domains(1);
if (doms_new) {
n = 1;
cpumask_andnot(doms_new[0], cpu_active_mask, cpu_isolated_map);
}
} else {
n = ndoms_new;
}
for (i = 0; i < ndoms_cur; i++) {
for (j = 0; j < n && !new_topology; j++) {
if (cpumask_equal(doms_cur[i], doms_new[j])
&& dattrs_equal(dattr_cur, i, dattr_new, j))
goto match1;
}
detach_destroy_domains(doms_cur[i]);
match1:
;
}
n = ndoms_cur;
if (!doms_new) {
n = 0;
doms_new = &fallback_doms;
cpumask_andnot(doms_new[0], cpu_active_mask, cpu_isolated_map);
}
for (i = 0; i < ndoms_new; i++) {
for (j = 0; j < n && !new_topology; j++) {
if (cpumask_equal(doms_new[i], doms_cur[j])
&& dattrs_equal(dattr_new, i, dattr_cur, j))
goto match2;
}
build_sched_domains(doms_new[i], dattr_new ? dattr_new + i : NULL);
match2:
;
}
if (doms_cur != &fallback_doms)
free_sched_domains(doms_cur, ndoms_cur);
kfree(dattr_cur);
doms_cur = doms_new;
dattr_cur = dattr_new;
ndoms_cur = ndoms_new;
register_sched_domain_sysctl();
mutex_unlock(&sched_domains_mutex);
}
