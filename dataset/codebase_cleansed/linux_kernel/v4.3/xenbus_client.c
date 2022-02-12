const char *xenbus_strstate(enum xenbus_state state)
{
static const char *const name[] = {
[ XenbusStateUnknown ] = "Unknown",
[ XenbusStateInitialising ] = "Initialising",
[ XenbusStateInitWait ] = "InitWait",
[ XenbusStateInitialised ] = "Initialised",
[ XenbusStateConnected ] = "Connected",
[ XenbusStateClosing ] = "Closing",
[ XenbusStateClosed ] = "Closed",
[XenbusStateReconfiguring] = "Reconfiguring",
[XenbusStateReconfigured] = "Reconfigured",
};
return (state < ARRAY_SIZE(name)) ? name[state] : "INVALID";
}
int xenbus_watch_path(struct xenbus_device *dev, const char *path,
struct xenbus_watch *watch,
void (*callback)(struct xenbus_watch *,
const char **, unsigned int))
{
int err;
watch->node = path;
watch->callback = callback;
err = register_xenbus_watch(watch);
if (err) {
watch->node = NULL;
watch->callback = NULL;
xenbus_dev_fatal(dev, err, "adding watch on %s", path);
}
return err;
}
int xenbus_watch_pathfmt(struct xenbus_device *dev,
struct xenbus_watch *watch,
void (*callback)(struct xenbus_watch *,
const char **, unsigned int),
const char *pathfmt, ...)
{
int err;
va_list ap;
char *path;
va_start(ap, pathfmt);
path = kvasprintf(GFP_NOIO | __GFP_HIGH, pathfmt, ap);
va_end(ap);
if (!path) {
xenbus_dev_fatal(dev, -ENOMEM, "allocating path for watch");
return -ENOMEM;
}
err = xenbus_watch_path(dev, path, watch, callback);
if (err)
kfree(path);
return err;
}
static int
__xenbus_switch_state(struct xenbus_device *dev,
enum xenbus_state state, int depth)
{
struct xenbus_transaction xbt;
int current_state;
int err, abort;
if (state == dev->state)
return 0;
again:
abort = 1;
err = xenbus_transaction_start(&xbt);
if (err) {
xenbus_switch_fatal(dev, depth, err, "starting transaction");
return 0;
}
err = xenbus_scanf(xbt, dev->nodename, "state", "%d", &current_state);
if (err != 1)
goto abort;
err = xenbus_printf(xbt, dev->nodename, "state", "%d", state);
if (err) {
xenbus_switch_fatal(dev, depth, err, "writing new state");
goto abort;
}
abort = 0;
abort:
err = xenbus_transaction_end(xbt, abort);
if (err) {
if (err == -EAGAIN && !abort)
goto again;
xenbus_switch_fatal(dev, depth, err, "ending transaction");
} else
dev->state = state;
return 0;
}
int xenbus_switch_state(struct xenbus_device *dev, enum xenbus_state state)
{
return __xenbus_switch_state(dev, state, 0);
}
int xenbus_frontend_closed(struct xenbus_device *dev)
{
xenbus_switch_state(dev, XenbusStateClosed);
complete(&dev->down);
return 0;
}
static char *error_path(struct xenbus_device *dev)
{
return kasprintf(GFP_KERNEL, "error/%s", dev->nodename);
}
static void xenbus_va_dev_error(struct xenbus_device *dev, int err,
const char *fmt, va_list ap)
{
unsigned int len;
char *printf_buffer = NULL;
char *path_buffer = NULL;
#define PRINTF_BUFFER_SIZE 4096
printf_buffer = kmalloc(PRINTF_BUFFER_SIZE, GFP_KERNEL);
if (printf_buffer == NULL)
goto fail;
len = sprintf(printf_buffer, "%i ", -err);
vsnprintf(printf_buffer+len, PRINTF_BUFFER_SIZE-len, fmt, ap);
dev_err(&dev->dev, "%s\n", printf_buffer);
path_buffer = error_path(dev);
if (path_buffer == NULL) {
dev_err(&dev->dev, "failed to write error node for %s (%s)\n",
dev->nodename, printf_buffer);
goto fail;
}
if (xenbus_write(XBT_NIL, path_buffer, "error", printf_buffer) != 0) {
dev_err(&dev->dev, "failed to write error node for %s (%s)\n",
dev->nodename, printf_buffer);
goto fail;
}
fail:
kfree(printf_buffer);
kfree(path_buffer);
}
void xenbus_dev_error(struct xenbus_device *dev, int err, const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
xenbus_va_dev_error(dev, err, fmt, ap);
va_end(ap);
}
void xenbus_dev_fatal(struct xenbus_device *dev, int err, const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
xenbus_va_dev_error(dev, err, fmt, ap);
va_end(ap);
xenbus_switch_state(dev, XenbusStateClosing);
}
static void xenbus_switch_fatal(struct xenbus_device *dev, int depth, int err,
const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
xenbus_va_dev_error(dev, err, fmt, ap);
va_end(ap);
if (!depth)
__xenbus_switch_state(dev, XenbusStateClosing, 1);
}
int xenbus_grant_ring(struct xenbus_device *dev, void *vaddr,
unsigned int nr_pages, grant_ref_t *grefs)
{
int err;
int i, j;
for (i = 0; i < nr_pages; i++) {
err = gnttab_grant_foreign_access(dev->otherend_id,
virt_to_gfn(vaddr), 0);
if (err < 0) {
xenbus_dev_fatal(dev, err,
"granting access to ring page");
goto fail;
}
grefs[i] = err;
vaddr = vaddr + PAGE_SIZE;
}
return 0;
fail:
for (j = 0; j < i; j++)
gnttab_end_foreign_access_ref(grefs[j], 0);
return err;
}
int xenbus_alloc_evtchn(struct xenbus_device *dev, int *port)
{
struct evtchn_alloc_unbound alloc_unbound;
int err;
alloc_unbound.dom = DOMID_SELF;
alloc_unbound.remote_dom = dev->otherend_id;
err = HYPERVISOR_event_channel_op(EVTCHNOP_alloc_unbound,
&alloc_unbound);
if (err)
xenbus_dev_fatal(dev, err, "allocating event channel");
else
*port = alloc_unbound.port;
return err;
}
int xenbus_free_evtchn(struct xenbus_device *dev, int port)
{
struct evtchn_close close;
int err;
close.port = port;
err = HYPERVISOR_event_channel_op(EVTCHNOP_close, &close);
if (err)
xenbus_dev_error(dev, err, "freeing event channel %d", port);
return err;
}
int xenbus_map_ring_valloc(struct xenbus_device *dev, grant_ref_t *gnt_refs,
unsigned int nr_grefs, void **vaddr)
{
return ring_ops->map(dev, gnt_refs, nr_grefs, vaddr);
}
static int __xenbus_map_ring(struct xenbus_device *dev,
grant_ref_t *gnt_refs,
unsigned int nr_grefs,
grant_handle_t *handles,
phys_addr_t *addrs,
unsigned int flags,
bool *leaked)
{
struct gnttab_map_grant_ref map[XENBUS_MAX_RING_PAGES];
struct gnttab_unmap_grant_ref unmap[XENBUS_MAX_RING_PAGES];
int i, j;
int err = GNTST_okay;
if (nr_grefs > XENBUS_MAX_RING_PAGES)
return -EINVAL;
for (i = 0; i < nr_grefs; i++) {
memset(&map[i], 0, sizeof(map[i]));
gnttab_set_map_op(&map[i], addrs[i], flags, gnt_refs[i],
dev->otherend_id);
handles[i] = INVALID_GRANT_HANDLE;
}
gnttab_batch_map(map, i);
for (i = 0; i < nr_grefs; i++) {
if (map[i].status != GNTST_okay) {
err = map[i].status;
xenbus_dev_fatal(dev, map[i].status,
"mapping in shared page %d from domain %d",
gnt_refs[i], dev->otherend_id);
goto fail;
} else
handles[i] = map[i].handle;
}
return GNTST_okay;
fail:
for (i = j = 0; i < nr_grefs; i++) {
if (handles[i] != INVALID_GRANT_HANDLE) {
memset(&unmap[j], 0, sizeof(unmap[j]));
gnttab_set_unmap_op(&unmap[j], (phys_addr_t)addrs[i],
GNTMAP_host_map, handles[i]);
j++;
}
}
if (HYPERVISOR_grant_table_op(GNTTABOP_unmap_grant_ref, unmap, j))
BUG();
*leaked = false;
for (i = 0; i < j; i++) {
if (unmap[i].status != GNTST_okay) {
*leaked = true;
break;
}
}
return err;
}
static int xenbus_map_ring_valloc_pv(struct xenbus_device *dev,
grant_ref_t *gnt_refs,
unsigned int nr_grefs,
void **vaddr)
{
struct xenbus_map_node *node;
struct vm_struct *area;
pte_t *ptes[XENBUS_MAX_RING_PAGES];
phys_addr_t phys_addrs[XENBUS_MAX_RING_PAGES];
int err = GNTST_okay;
int i;
bool leaked;
*vaddr = NULL;
if (nr_grefs > XENBUS_MAX_RING_PAGES)
return -EINVAL;
node = kzalloc(sizeof(*node), GFP_KERNEL);
if (!node)
return -ENOMEM;
area = alloc_vm_area(PAGE_SIZE * nr_grefs, ptes);
if (!area) {
kfree(node);
return -ENOMEM;
}
for (i = 0; i < nr_grefs; i++)
phys_addrs[i] = arbitrary_virt_to_machine(ptes[i]).maddr;
err = __xenbus_map_ring(dev, gnt_refs, nr_grefs, node->handles,
phys_addrs,
GNTMAP_host_map | GNTMAP_contains_pte,
&leaked);
if (err)
goto failed;
node->nr_handles = nr_grefs;
node->pv.area = area;
spin_lock(&xenbus_valloc_lock);
list_add(&node->next, &xenbus_valloc_pages);
spin_unlock(&xenbus_valloc_lock);
*vaddr = area->addr;
return 0;
failed:
if (!leaked)
free_vm_area(area);
else
pr_alert("leaking VM area %p size %u page(s)", area, nr_grefs);
kfree(node);
return err;
}
static int xenbus_map_ring_valloc_hvm(struct xenbus_device *dev,
grant_ref_t *gnt_ref,
unsigned int nr_grefs,
void **vaddr)
{
struct xenbus_map_node *node;
int i;
int err;
void *addr;
bool leaked = false;
phys_addr_t phys_addrs[XENBUS_MAX_RING_PAGES];
unsigned long addrs[XENBUS_MAX_RING_PAGES];
if (nr_grefs > XENBUS_MAX_RING_PAGES)
return -EINVAL;
*vaddr = NULL;
node = kzalloc(sizeof(*node), GFP_KERNEL);
if (!node)
return -ENOMEM;
err = alloc_xenballooned_pages(nr_grefs, node->hvm.pages,
false );
if (err)
goto out_err;
for (i = 0; i < nr_grefs; i++) {
unsigned long pfn = page_to_pfn(node->hvm.pages[i]);
phys_addrs[i] = (unsigned long)pfn_to_kaddr(pfn);
addrs[i] = (unsigned long)pfn_to_kaddr(pfn);
}
err = __xenbus_map_ring(dev, gnt_ref, nr_grefs, node->handles,
phys_addrs, GNTMAP_host_map, &leaked);
node->nr_handles = nr_grefs;
if (err)
goto out_free_ballooned_pages;
addr = vmap(node->hvm.pages, nr_grefs, VM_MAP | VM_IOREMAP,
PAGE_KERNEL);
if (!addr) {
err = -ENOMEM;
goto out_xenbus_unmap_ring;
}
node->hvm.addr = addr;
spin_lock(&xenbus_valloc_lock);
list_add(&node->next, &xenbus_valloc_pages);
spin_unlock(&xenbus_valloc_lock);
*vaddr = addr;
return 0;
out_xenbus_unmap_ring:
if (!leaked)
xenbus_unmap_ring(dev, node->handles, node->nr_handles,
addrs);
else
pr_alert("leaking %p size %u page(s)",
addr, nr_grefs);
out_free_ballooned_pages:
if (!leaked)
free_xenballooned_pages(nr_grefs, node->hvm.pages);
out_err:
kfree(node);
return err;
}
int xenbus_map_ring(struct xenbus_device *dev, grant_ref_t *gnt_refs,
unsigned int nr_grefs, grant_handle_t *handles,
unsigned long *vaddrs, bool *leaked)
{
phys_addr_t phys_addrs[XENBUS_MAX_RING_PAGES];
int i;
if (nr_grefs > XENBUS_MAX_RING_PAGES)
return -EINVAL;
for (i = 0; i < nr_grefs; i++)
phys_addrs[i] = (unsigned long)vaddrs[i];
return __xenbus_map_ring(dev, gnt_refs, nr_grefs, handles,
phys_addrs, GNTMAP_host_map, leaked);
}
int xenbus_unmap_ring_vfree(struct xenbus_device *dev, void *vaddr)
{
return ring_ops->unmap(dev, vaddr);
}
static int xenbus_unmap_ring_vfree_pv(struct xenbus_device *dev, void *vaddr)
{
struct xenbus_map_node *node;
struct gnttab_unmap_grant_ref unmap[XENBUS_MAX_RING_PAGES];
unsigned int level;
int i;
bool leaked = false;
int err;
spin_lock(&xenbus_valloc_lock);
list_for_each_entry(node, &xenbus_valloc_pages, next) {
if (node->pv.area->addr == vaddr) {
list_del(&node->next);
goto found;
}
}
node = NULL;
found:
spin_unlock(&xenbus_valloc_lock);
if (!node) {
xenbus_dev_error(dev, -ENOENT,
"can't find mapped virtual address %p", vaddr);
return GNTST_bad_virt_addr;
}
for (i = 0; i < node->nr_handles; i++) {
unsigned long addr;
memset(&unmap[i], 0, sizeof(unmap[i]));
addr = (unsigned long)vaddr + (PAGE_SIZE * i);
unmap[i].host_addr = arbitrary_virt_to_machine(
lookup_address(addr, &level)).maddr;
unmap[i].dev_bus_addr = 0;
unmap[i].handle = node->handles[i];
}
if (HYPERVISOR_grant_table_op(GNTTABOP_unmap_grant_ref, unmap, i))
BUG();
err = GNTST_okay;
leaked = false;
for (i = 0; i < node->nr_handles; i++) {
if (unmap[i].status != GNTST_okay) {
leaked = true;
xenbus_dev_error(dev, unmap[i].status,
"unmapping page at handle %d error %d",
node->handles[i], unmap[i].status);
err = unmap[i].status;
break;
}
}
if (!leaked)
free_vm_area(node->pv.area);
else
pr_alert("leaking VM area %p size %u page(s)",
node->pv.area, node->nr_handles);
kfree(node);
return err;
}
static int xenbus_unmap_ring_vfree_hvm(struct xenbus_device *dev, void *vaddr)
{
int rv;
struct xenbus_map_node *node;
void *addr;
unsigned long addrs[XENBUS_MAX_RING_PAGES];
int i;
spin_lock(&xenbus_valloc_lock);
list_for_each_entry(node, &xenbus_valloc_pages, next) {
addr = node->hvm.addr;
if (addr == vaddr) {
list_del(&node->next);
goto found;
}
}
node = addr = NULL;
found:
spin_unlock(&xenbus_valloc_lock);
if (!node) {
xenbus_dev_error(dev, -ENOENT,
"can't find mapped virtual address %p", vaddr);
return GNTST_bad_virt_addr;
}
for (i = 0; i < node->nr_handles; i++)
addrs[i] = (unsigned long)pfn_to_kaddr(page_to_pfn(node->hvm.pages[i]));
rv = xenbus_unmap_ring(dev, node->handles, node->nr_handles,
addrs);
if (!rv) {
vunmap(vaddr);
free_xenballooned_pages(node->nr_handles, node->hvm.pages);
}
else
WARN(1, "Leaking %p, size %u page(s)\n", vaddr,
node->nr_handles);
kfree(node);
return rv;
}
int xenbus_unmap_ring(struct xenbus_device *dev,
grant_handle_t *handles, unsigned int nr_handles,
unsigned long *vaddrs)
{
struct gnttab_unmap_grant_ref unmap[XENBUS_MAX_RING_PAGES];
int i;
int err;
if (nr_handles > XENBUS_MAX_RING_PAGES)
return -EINVAL;
for (i = 0; i < nr_handles; i++)
gnttab_set_unmap_op(&unmap[i], vaddrs[i],
GNTMAP_host_map, handles[i]);
if (HYPERVISOR_grant_table_op(GNTTABOP_unmap_grant_ref, unmap, i))
BUG();
err = GNTST_okay;
for (i = 0; i < nr_handles; i++) {
if (unmap[i].status != GNTST_okay) {
xenbus_dev_error(dev, unmap[i].status,
"unmapping page at handle %d error %d",
handles[i], unmap[i].status);
err = unmap[i].status;
break;
}
}
return err;
}
enum xenbus_state xenbus_read_driver_state(const char *path)
{
enum xenbus_state result;
int err = xenbus_gather(XBT_NIL, path, "state", "%d", &result, NULL);
if (err)
result = XenbusStateUnknown;
return result;
}
void __init xenbus_ring_ops_init(void)
{
if (!xen_feature(XENFEAT_auto_translated_physmap))
ring_ops = &ring_ops_pv;
else
ring_ops = &ring_ops_hvm;
}
