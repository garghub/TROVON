static int xen_unmap_device_mmio(const struct resource *resources,
unsigned int count)
{
unsigned int i, j, nr;
int rc = 0;
const struct resource *r;
struct xen_remove_from_physmap xrp;
for (i = 0; i < count; i++) {
r = &resources[i];
nr = DIV_ROUND_UP(resource_size(r), XEN_PAGE_SIZE);
if ((resource_type(r) != IORESOURCE_MEM) || (nr == 0))
continue;
for (j = 0; j < nr; j++) {
xrp.domid = DOMID_SELF;
xrp.gpfn = XEN_PFN_DOWN(r->start) + j;
rc = HYPERVISOR_memory_op(XENMEM_remove_from_physmap,
&xrp);
if (rc)
return rc;
}
}
return rc;
}
static int xen_map_device_mmio(const struct resource *resources,
unsigned int count)
{
unsigned int i, j, nr;
int rc = 0;
const struct resource *r;
xen_pfn_t *gpfns;
xen_ulong_t *idxs;
int *errs;
struct xen_add_to_physmap_range xatp;
for (i = 0; i < count; i++) {
r = &resources[i];
nr = DIV_ROUND_UP(resource_size(r), XEN_PAGE_SIZE);
if ((resource_type(r) != IORESOURCE_MEM) || (nr == 0))
continue;
gpfns = kzalloc(sizeof(xen_pfn_t) * nr, GFP_KERNEL);
idxs = kzalloc(sizeof(xen_ulong_t) * nr, GFP_KERNEL);
errs = kzalloc(sizeof(int) * nr, GFP_KERNEL);
if (!gpfns || !idxs || !errs) {
kfree(gpfns);
kfree(idxs);
kfree(errs);
rc = -ENOMEM;
goto unmap;
}
for (j = 0; j < nr; j++) {
gpfns[j] = XEN_PFN_DOWN(r->start) + j;
idxs[j] = XEN_PFN_DOWN(r->start) + j;
}
xatp.domid = DOMID_SELF;
xatp.size = nr;
xatp.space = XENMAPSPACE_dev_mmio;
set_xen_guest_handle(xatp.gpfns, gpfns);
set_xen_guest_handle(xatp.idxs, idxs);
set_xen_guest_handle(xatp.errs, errs);
rc = HYPERVISOR_memory_op(XENMEM_add_to_physmap_range, &xatp);
kfree(gpfns);
kfree(idxs);
kfree(errs);
if (rc)
goto unmap;
}
return rc;
unmap:
xen_unmap_device_mmio(resources, i);
return rc;
}
static int xen_platform_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
struct platform_device *pdev = to_platform_device(data);
int r = 0;
if (pdev->num_resources == 0 || pdev->resource == NULL)
return NOTIFY_OK;
switch (action) {
case BUS_NOTIFY_ADD_DEVICE:
r = xen_map_device_mmio(pdev->resource, pdev->num_resources);
break;
case BUS_NOTIFY_DEL_DEVICE:
r = xen_unmap_device_mmio(pdev->resource, pdev->num_resources);
break;
default:
return NOTIFY_DONE;
}
if (r)
dev_err(&pdev->dev, "Platform: Failed to %s device %s MMIO!\n",
action == BUS_NOTIFY_ADD_DEVICE ? "map" :
(action == BUS_NOTIFY_DEL_DEVICE ? "unmap" : "?"),
pdev->name);
return NOTIFY_OK;
}
static int __init register_xen_platform_notifier(void)
{
if (!xen_initial_domain() || acpi_disabled)
return 0;
return bus_register_notifier(&platform_bus_type, &platform_device_nb);
}
static int xen_amba_notifier(struct notifier_block *nb,
unsigned long action, void *data)
{
struct amba_device *adev = to_amba_device(data);
int r = 0;
switch (action) {
case BUS_NOTIFY_ADD_DEVICE:
r = xen_map_device_mmio(&adev->res, 1);
break;
case BUS_NOTIFY_DEL_DEVICE:
r = xen_unmap_device_mmio(&adev->res, 1);
break;
default:
return NOTIFY_DONE;
}
if (r)
dev_err(&adev->dev, "AMBA: Failed to %s device %s MMIO!\n",
action == BUS_NOTIFY_ADD_DEVICE ? "map" :
(action == BUS_NOTIFY_DEL_DEVICE ? "unmap" : "?"),
adev->dev.init_name);
return NOTIFY_OK;
}
static int __init register_xen_amba_notifier(void)
{
if (!xen_initial_domain() || acpi_disabled)
return 0;
return bus_register_notifier(&amba_bustype, &amba_device_nb);
}
