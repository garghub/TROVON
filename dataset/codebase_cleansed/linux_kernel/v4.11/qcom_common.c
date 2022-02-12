struct resource_table *qcom_mdt_find_rsc_table(struct rproc *rproc,
const struct firmware *fw,
int *tablesz)
{
static struct resource_table table = { .ver = 1, };
*tablesz = sizeof(table);
return &table;
}
static int smd_subdev_probe(struct rproc_subdev *subdev)
{
struct qcom_rproc_subdev *smd = to_smd_subdev(subdev);
smd->edge = qcom_smd_register_edge(smd->dev, smd->node);
return IS_ERR(smd->edge) ? PTR_ERR(smd->edge) : 0;
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
