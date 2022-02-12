static void nd_dax_release(struct device *dev)
{
struct nd_region *nd_region = to_nd_region(dev->parent);
struct nd_dax *nd_dax = to_nd_dax(dev);
struct nd_pfn *nd_pfn = &nd_dax->nd_pfn;
dev_dbg(dev, "%s\n", __func__);
nd_detach_ndns(dev, &nd_pfn->ndns);
ida_simple_remove(&nd_region->dax_ida, nd_pfn->id);
kfree(nd_pfn->uuid);
kfree(nd_dax);
}
bool is_nd_dax(struct device *dev)
{
return dev ? dev->type == &nd_dax_device_type : false;
}
struct nd_dax *to_nd_dax(struct device *dev)
{
struct nd_dax *nd_dax = container_of(dev, struct nd_dax, nd_pfn.dev);
WARN_ON(!is_nd_dax(dev));
return nd_dax;
}
static struct nd_dax *nd_dax_alloc(struct nd_region *nd_region)
{
struct nd_pfn *nd_pfn;
struct nd_dax *nd_dax;
struct device *dev;
nd_dax = kzalloc(sizeof(*nd_dax), GFP_KERNEL);
if (!nd_dax)
return NULL;
nd_pfn = &nd_dax->nd_pfn;
nd_pfn->id = ida_simple_get(&nd_region->dax_ida, 0, 0, GFP_KERNEL);
if (nd_pfn->id < 0) {
kfree(nd_dax);
return NULL;
}
dev = &nd_pfn->dev;
dev_set_name(dev, "dax%d.%d", nd_region->id, nd_pfn->id);
dev->groups = nd_dax_attribute_groups;
dev->type = &nd_dax_device_type;
dev->parent = &nd_region->dev;
return nd_dax;
}
struct device *nd_dax_create(struct nd_region *nd_region)
{
struct device *dev = NULL;
struct nd_dax *nd_dax;
if (!is_memory(&nd_region->dev))
return NULL;
nd_dax = nd_dax_alloc(nd_region);
if (nd_dax)
dev = nd_pfn_devinit(&nd_dax->nd_pfn, NULL);
__nd_device_register(dev);
return dev;
}
int nd_dax_probe(struct device *dev, struct nd_namespace_common *ndns)
{
int rc;
struct nd_dax *nd_dax;
struct device *dax_dev;
struct nd_pfn *nd_pfn;
struct nd_pfn_sb *pfn_sb;
struct nd_region *nd_region = to_nd_region(ndns->dev.parent);
if (ndns->force_raw)
return -ENODEV;
switch (ndns->claim_class) {
case NVDIMM_CCLASS_NONE:
case NVDIMM_CCLASS_DAX:
break;
default:
return -ENODEV;
}
nvdimm_bus_lock(&ndns->dev);
nd_dax = nd_dax_alloc(nd_region);
nd_pfn = &nd_dax->nd_pfn;
dax_dev = nd_pfn_devinit(nd_pfn, ndns);
nvdimm_bus_unlock(&ndns->dev);
if (!dax_dev)
return -ENOMEM;
pfn_sb = devm_kzalloc(dev, sizeof(*pfn_sb), GFP_KERNEL);
nd_pfn->pfn_sb = pfn_sb;
rc = nd_pfn_validate(nd_pfn, DAX_SIG);
dev_dbg(dev, "%s: dax: %s\n", __func__,
rc == 0 ? dev_name(dax_dev) : "<none>");
if (rc < 0) {
nd_detach_ndns(dax_dev, &nd_pfn->ndns);
put_device(dax_dev);
} else
__nd_device_register(dax_dev);
return rc;
}
