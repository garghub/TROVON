static struct vmpressure *work_to_vmpressure(struct work_struct *work)
{
return container_of(work, struct vmpressure, work);
}
static struct vmpressure *vmpressure_parent(struct vmpressure *vmpr)
{
struct cgroup_subsys_state *css = vmpressure_to_css(vmpr);
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
memcg = parent_mem_cgroup(memcg);
if (!memcg)
return NULL;
return memcg_to_vmpressure(memcg);
}
static enum vmpressure_levels vmpressure_level(unsigned long pressure)
{
if (pressure >= vmpressure_level_critical)
return VMPRESSURE_CRITICAL;
else if (pressure >= vmpressure_level_med)
return VMPRESSURE_MEDIUM;
return VMPRESSURE_LOW;
}
static enum vmpressure_levels vmpressure_calc_level(unsigned long scanned,
unsigned long reclaimed)
{
unsigned long scale = scanned + reclaimed;
unsigned long pressure = 0;
if (reclaimed >= scanned)
goto out;
pressure = scale - (reclaimed * scale / scanned);
pressure = pressure * 100 / scale;
out:
pr_debug("%s: %3lu (s: %lu r: %lu)\n", __func__, pressure,
scanned, reclaimed);
return vmpressure_level(pressure);
}
static bool vmpressure_event(struct vmpressure *vmpr,
enum vmpressure_levels level)
{
struct vmpressure_event *ev;
bool signalled = false;
mutex_lock(&vmpr->events_lock);
list_for_each_entry(ev, &vmpr->events, node) {
if (level >= ev->level) {
eventfd_signal(ev->efd, 1);
signalled = true;
}
}
mutex_unlock(&vmpr->events_lock);
return signalled;
}
static void vmpressure_work_fn(struct work_struct *work)
{
struct vmpressure *vmpr = work_to_vmpressure(work);
unsigned long scanned;
unsigned long reclaimed;
enum vmpressure_levels level;
spin_lock(&vmpr->sr_lock);
scanned = vmpr->tree_scanned;
if (!scanned) {
spin_unlock(&vmpr->sr_lock);
return;
}
reclaimed = vmpr->tree_reclaimed;
vmpr->tree_scanned = 0;
vmpr->tree_reclaimed = 0;
spin_unlock(&vmpr->sr_lock);
level = vmpressure_calc_level(scanned, reclaimed);
do {
if (vmpressure_event(vmpr, level))
break;
} while ((vmpr = vmpressure_parent(vmpr)));
}
void vmpressure(gfp_t gfp, struct mem_cgroup *memcg, bool tree,
unsigned long scanned, unsigned long reclaimed)
{
struct vmpressure *vmpr = memcg_to_vmpressure(memcg);
if (!(gfp & (__GFP_HIGHMEM | __GFP_MOVABLE | __GFP_IO | __GFP_FS)))
return;
if (!scanned)
return;
if (tree) {
spin_lock(&vmpr->sr_lock);
scanned = vmpr->tree_scanned += scanned;
vmpr->tree_reclaimed += reclaimed;
spin_unlock(&vmpr->sr_lock);
if (scanned < vmpressure_win)
return;
schedule_work(&vmpr->work);
} else {
enum vmpressure_levels level;
if (!memcg || memcg == root_mem_cgroup)
return;
spin_lock(&vmpr->sr_lock);
scanned = vmpr->scanned += scanned;
reclaimed = vmpr->reclaimed += reclaimed;
if (scanned < vmpressure_win) {
spin_unlock(&vmpr->sr_lock);
return;
}
vmpr->scanned = vmpr->reclaimed = 0;
spin_unlock(&vmpr->sr_lock);
level = vmpressure_calc_level(scanned, reclaimed);
if (level > VMPRESSURE_LOW) {
memcg->socket_pressure = jiffies + HZ;
}
}
}
void vmpressure_prio(gfp_t gfp, struct mem_cgroup *memcg, int prio)
{
if (prio > vmpressure_level_critical_prio)
return;
vmpressure(gfp, memcg, true, vmpressure_win, 0);
}
int vmpressure_register_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd, const char *args)
{
struct vmpressure *vmpr = memcg_to_vmpressure(memcg);
struct vmpressure_event *ev;
int level;
for (level = 0; level < VMPRESSURE_NUM_LEVELS; level++) {
if (!strcmp(vmpressure_str_levels[level], args))
break;
}
if (level >= VMPRESSURE_NUM_LEVELS)
return -EINVAL;
ev = kzalloc(sizeof(*ev), GFP_KERNEL);
if (!ev)
return -ENOMEM;
ev->efd = eventfd;
ev->level = level;
mutex_lock(&vmpr->events_lock);
list_add(&ev->node, &vmpr->events);
mutex_unlock(&vmpr->events_lock);
return 0;
}
void vmpressure_unregister_event(struct mem_cgroup *memcg,
struct eventfd_ctx *eventfd)
{
struct vmpressure *vmpr = memcg_to_vmpressure(memcg);
struct vmpressure_event *ev;
mutex_lock(&vmpr->events_lock);
list_for_each_entry(ev, &vmpr->events, node) {
if (ev->efd != eventfd)
continue;
list_del(&ev->node);
kfree(ev);
break;
}
mutex_unlock(&vmpr->events_lock);
}
void vmpressure_init(struct vmpressure *vmpr)
{
spin_lock_init(&vmpr->sr_lock);
mutex_init(&vmpr->events_lock);
INIT_LIST_HEAD(&vmpr->events);
INIT_WORK(&vmpr->work, vmpressure_work_fn);
}
void vmpressure_cleanup(struct vmpressure *vmpr)
{
flush_work(&vmpr->work);
}
