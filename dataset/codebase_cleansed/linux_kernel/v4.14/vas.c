static int init_vas_instance(struct platform_device *pdev)
{
int rc, vasid;
struct resource *res;
struct vas_instance *vinst;
struct device_node *dn = pdev->dev.of_node;
rc = of_property_read_u32(dn, "ibm,vas-id", &vasid);
if (rc) {
pr_err("No ibm,vas-id property for %s?\n", pdev->name);
return -ENODEV;
}
if (pdev->num_resources != 4) {
pr_err("Unexpected DT configuration for [%s, %d]\n",
pdev->name, vasid);
return -ENODEV;
}
vinst = kzalloc(sizeof(*vinst), GFP_KERNEL);
if (!vinst)
return -ENOMEM;
INIT_LIST_HEAD(&vinst->node);
ida_init(&vinst->ida);
mutex_init(&vinst->mutex);
vinst->vas_id = vasid;
vinst->pdev = pdev;
res = &pdev->resource[0];
vinst->hvwc_bar_start = res->start;
res = &pdev->resource[1];
vinst->uwc_bar_start = res->start;
res = &pdev->resource[2];
vinst->paste_base_addr = res->start;
res = &pdev->resource[3];
if (res->end > 62) {
pr_err("Bad 'paste_win_id_shift' in DT, %llx\n", res->end);
goto free_vinst;
}
vinst->paste_win_id_shift = 63 - res->end;
pr_devel("Initialized instance [%s, %d], paste_base 0x%llx, "
"paste_win_id_shift 0x%llx\n", pdev->name, vasid,
vinst->paste_base_addr, vinst->paste_win_id_shift);
mutex_lock(&vas_mutex);
list_add(&vinst->node, &vas_instances);
mutex_unlock(&vas_mutex);
dev_set_drvdata(&pdev->dev, vinst);
return 0;
free_vinst:
kfree(vinst);
return -ENODEV;
}
struct vas_instance *find_vas_instance(int vasid)
{
struct list_head *ent;
struct vas_instance *vinst;
mutex_lock(&vas_mutex);
list_for_each(ent, &vas_instances) {
vinst = list_entry(ent, struct vas_instance, node);
if (vinst->vas_id == vasid) {
mutex_unlock(&vas_mutex);
return vinst;
}
}
mutex_unlock(&vas_mutex);
pr_devel("Instance %d not found\n", vasid);
return NULL;
}
static int vas_probe(struct platform_device *pdev)
{
return init_vas_instance(pdev);
}
static int __init vas_init(void)
{
int found = 0;
struct device_node *dn;
platform_driver_register(&vas_driver);
for_each_compatible_node(dn, NULL, "ibm,vas") {
of_platform_device_create(dn, NULL, NULL);
found++;
}
if (!found)
return -ENODEV;
pr_devel("Found %d instances\n", found);
return 0;
}
