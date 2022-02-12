static int nd_region_probe(struct device *dev)
{
int err, rc;
static unsigned long once;
struct nd_region_namespaces *num_ns;
struct nd_region *nd_region = to_nd_region(dev);
if (nd_region->num_lanes > num_online_cpus()
&& nd_region->num_lanes < num_possible_cpus()
&& !test_and_set_bit(0, &once)) {
dev_info(dev, "online cpus (%d) < concurrent i/o lanes (%d) < possible cpus (%d)\n",
num_online_cpus(), nd_region->num_lanes,
num_possible_cpus());
dev_info(dev, "setting nr_cpus=%d may yield better libnvdimm device performance\n",
nd_region->num_lanes);
}
rc = nd_blk_region_init(nd_region);
if (rc)
return rc;
rc = nd_region_register_namespaces(nd_region, &err);
num_ns = devm_kzalloc(dev, sizeof(*num_ns), GFP_KERNEL);
if (!num_ns)
return -ENOMEM;
if (rc < 0)
return rc;
num_ns->active = rc;
num_ns->count = rc + err;
dev_set_drvdata(dev, num_ns);
if (rc && err && rc == err)
return -ENODEV;
nd_region->btt_seed = nd_btt_create(nd_region);
nd_region->pfn_seed = nd_pfn_create(nd_region);
if (err == 0)
return 0;
dev_err(dev, "failed to register %d namespace%s, continuing...\n",
err, err == 1 ? "" : "s");
return 0;
}
static int child_unregister(struct device *dev, void *data)
{
nd_device_unregister(dev, ND_SYNC);
return 0;
}
static int nd_region_remove(struct device *dev)
{
struct nd_region *nd_region = to_nd_region(dev);
nvdimm_bus_lock(dev);
nd_region->ns_seed = NULL;
nd_region->btt_seed = NULL;
nd_region->pfn_seed = NULL;
dev_set_drvdata(dev, NULL);
nvdimm_bus_unlock(dev);
device_for_each_child(dev, NULL, child_unregister);
return 0;
}
static int child_notify(struct device *dev, void *data)
{
nd_device_notify(dev, *(enum nvdimm_event *) data);
return 0;
}
static void nd_region_notify(struct device *dev, enum nvdimm_event event)
{
device_for_each_child(dev, &event, child_notify);
}
int __init nd_region_init(void)
{
return nd_driver_register(&nd_region_driver);
}
void nd_region_exit(void)
{
driver_unregister(&nd_region_driver.drv);
}
