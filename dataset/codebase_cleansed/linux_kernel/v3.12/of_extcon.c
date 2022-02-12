struct extcon_dev *of_extcon_get_extcon_dev(struct device *dev, int index)
{
struct device_node *node;
struct extcon_dev *edev;
struct platform_device *extcon_parent_dev;
if (!dev->of_node) {
dev_dbg(dev, "device does not have a device node entry\n");
return ERR_PTR(-EINVAL);
}
node = of_parse_phandle(dev->of_node, "extcon", index);
if (!node) {
dev_dbg(dev, "failed to get phandle in %s node\n",
dev->of_node->full_name);
return ERR_PTR(-ENODEV);
}
extcon_parent_dev = of_find_device_by_node(node);
if (!extcon_parent_dev) {
dev_dbg(dev, "unable to find device by node\n");
return ERR_PTR(-EPROBE_DEFER);
}
edev = extcon_get_extcon_dev(dev_name(&extcon_parent_dev->dev));
if (!edev) {
dev_dbg(dev, "unable to get extcon device : %s\n",
dev_name(&extcon_parent_dev->dev));
return ERR_PTR(-ENODEV);
}
return edev;
}
