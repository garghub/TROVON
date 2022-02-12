struct device_node *pseries_of_derive_parent(const char *path)
{
struct device_node *parent;
char *parent_path = "/";
const char *tail;
tail = kbasename(path) - 1;
if (!strcmp(path, "/"))
return ERR_PTR(-EINVAL);
if (tail > path) {
parent_path = kstrndup(path, tail - path, GFP_KERNEL);
if (!parent_path)
return ERR_PTR(-ENOMEM);
}
parent = of_find_node_by_path(parent_path);
if (strcmp(parent_path, "/"))
kfree(parent_path);
return parent ? parent : ERR_PTR(-EINVAL);
}
