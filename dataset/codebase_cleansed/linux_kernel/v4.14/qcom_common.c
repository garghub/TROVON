struct resource_table *qcom_mdt_find_rsc_table(struct rproc *rproc,
const struct firmware *fw,
int *tablesz)
{
static struct resource_table table = { .ver = 1, };
*tablesz = sizeof(table);
return &table;
}
static int glink_subdev_probe(struct rproc_subdev *subdev)
{
struct qcom_rproc_glink *glink = to_glink_subdev(subdev);
glink->edge = qcom_glink_smem_register(glink->dev, glink->node);
return IS_ERR(glink->edge) ? PTR_ERR(glink->edge) : 0;
}
static void glink_subdev_remove(struct rproc_subdev *subdev)
{
struct qcom_rproc_glink *glink = to_glink_subdev(subdev);
qcom_glink_smem_unregister(glink->edge);
glink->edge = NULL;
}
void qcom_add_glink_subdev(struct rproc *rproc, struct qcom_rproc_glink *glink)
{
struct device *dev = &rproc->dev;
glink->node = of_get_child_by_name(dev->parent->of_node, "glink-edge");
if (!glink->node)
return;
glink->dev = dev;
rproc_add_subdev(rproc, &glink->subdev, glink_subdev_probe, glink_subdev_remove);
}
void qcom_remove_glink_subdev(struct rproc *rproc, struct qcom_rproc_glink *glink)
{
rproc_remove_subdev(rproc, &glink->subdev);
of_node_put(glink->node);
}
static int smd_subdev_probe(struct rproc_subdev *subdev)
{
struct qcom_rproc_subdev *smd = to_smd_subdev(subdev);
smd->edge = qcom_smd_register_edge(smd->dev, smd->node);
return PTR_ERR_OR_ZERO(smd->edge);
}
static void smd_subdev_remove(struct rproc_subdev *subdev)
{
struct qcom_rproc_subdev *smd = to_smd_subdev(subdev);
qcom_smd_unregister_edge(smd->edge);
smd->edge = NULL;
}
void qcom_add_smd_subdev(struct rproc *rproc, struct qcom_rproc_subdev *smd)
{
struct device *dev = &rproc->dev;
smd->node = of_get_child_by_name(dev->parent->of_node, "smd-edge");
if (!smd->node)
return;
smd->dev = dev;
rproc_add_subdev(rproc, &smd->subdev, smd_subdev_probe, smd_subdev_remove);
}
void qcom_remove_smd_subdev(struct rproc *rproc, struct qcom_rproc_subdev *smd)
{
rproc_remove_subdev(rproc, &smd->subdev);
of_node_put(smd->node);
}
int qcom_register_ssr_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&ssr_notifiers, nb);
}
void qcom_unregister_ssr_notifier(struct notifier_block *nb)
{
blocking_notifier_chain_unregister(&ssr_notifiers, nb);
}
static int ssr_notify_start(struct rproc_subdev *subdev)
{
return 0;
}
static void ssr_notify_stop(struct rproc_subdev *subdev)
{
struct qcom_rproc_ssr *ssr = to_ssr_subdev(subdev);
blocking_notifier_call_chain(&ssr_notifiers, 0, (void *)ssr->name);
}
void qcom_add_ssr_subdev(struct rproc *rproc, struct qcom_rproc_ssr *ssr,
const char *ssr_name)
{
ssr->name = ssr_name;
rproc_add_subdev(rproc, &ssr->subdev, ssr_notify_start, ssr_notify_stop);
}
void qcom_remove_ssr_subdev(struct rproc *rproc, struct qcom_rproc_ssr *ssr)
{
rproc_remove_subdev(rproc, &ssr->subdev);
}
