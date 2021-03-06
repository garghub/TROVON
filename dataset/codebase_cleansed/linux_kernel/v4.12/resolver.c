static struct device_node *find_node_by_full_name(struct device_node *node,
const char *full_name)
{
struct device_node *child, *found;
if (!node)
return NULL;
if (!of_node_cmp(node->full_name, full_name))
return of_node_get(node);
for_each_child_of_node(node, child) {
found = find_node_by_full_name(child, full_name);
if (found != NULL) {
of_node_put(child);
return found;
}
}
return NULL;
}
static phandle live_tree_max_phandle(void)
{
struct device_node *node;
phandle phandle;
unsigned long flags;
raw_spin_lock_irqsave(&devtree_lock, flags);
phandle = 0;
for_each_of_allnodes(node) {
if (node->phandle != OF_PHANDLE_ILLEGAL &&
node->phandle > phandle)
phandle = node->phandle;
}
raw_spin_unlock_irqrestore(&devtree_lock, flags);
return phandle;
}
static void adjust_overlay_phandles(struct device_node *overlay,
int phandle_delta)
{
struct device_node *child;
struct property *prop;
phandle phandle;
if (overlay->phandle != 0 && overlay->phandle != OF_PHANDLE_ILLEGAL)
overlay->phandle += phandle_delta;
for_each_property_of_node(overlay, prop) {
if (of_prop_cmp(prop->name, "phandle") &&
of_prop_cmp(prop->name, "linux,phandle"))
continue;
if (prop->length < 4)
continue;
phandle = be32_to_cpup(prop->value);
if (phandle == OF_PHANDLE_ILLEGAL)
continue;
*(__be32 *)prop->value = cpu_to_be32(overlay->phandle);
}
for_each_child_of_node(overlay, child)
adjust_overlay_phandles(child, phandle_delta);
}
static int update_usages_of_a_phandle_reference(struct device_node *overlay,
struct property *prop_fixup, phandle phandle)
{
struct device_node *refnode;
struct property *prop;
char *value, *cur, *end, *node_path, *prop_name, *s;
int offset, len;
int err = 0;
value = kmalloc(prop_fixup->length, GFP_KERNEL);
if (!value)
return -ENOMEM;
memcpy(value, prop_fixup->value, prop_fixup->length);
end = value + prop_fixup->length;
for (cur = value; cur < end; cur += len + 1) {
len = strlen(cur);
node_path = cur;
s = strchr(cur, ':');
if (!s) {
err = -EINVAL;
goto err_fail;
}
*s++ = '\0';
prop_name = s;
s = strchr(s, ':');
if (!s) {
err = -EINVAL;
goto err_fail;
}
*s++ = '\0';
err = kstrtoint(s, 10, &offset);
if (err)
goto err_fail;
refnode = find_node_by_full_name(overlay, node_path);
if (!refnode)
continue;
for_each_property_of_node(refnode, prop) {
if (!of_prop_cmp(prop->name, prop_name))
break;
}
of_node_put(refnode);
if (!prop) {
err = -ENOENT;
goto err_fail;
}
*(__be32 *)(prop->value + offset) = cpu_to_be32(phandle);
}
err_fail:
kfree(value);
return err;
}
static int node_name_cmp(const struct device_node *dn1,
const struct device_node *dn2)
{
const char *n1 = strrchr(dn1->full_name, '/') ? : "/";
const char *n2 = strrchr(dn2->full_name, '/') ? : "/";
return of_node_cmp(n1, n2);
}
static int adjust_local_phandle_references(struct device_node *local_fixups,
struct device_node *overlay, int phandle_delta)
{
struct device_node *child, *overlay_child;
struct property *prop_fix, *prop;
int err, i, count;
unsigned int off;
phandle phandle;
if (!local_fixups)
return 0;
for_each_property_of_node(local_fixups, prop_fix) {
if (!of_prop_cmp(prop_fix->name, "name") ||
!of_prop_cmp(prop_fix->name, "phandle") ||
!of_prop_cmp(prop_fix->name, "linux,phandle"))
continue;
if ((prop_fix->length % 4) != 0 || prop_fix->length == 0)
return -EINVAL;
count = prop_fix->length / sizeof(__be32);
for_each_property_of_node(overlay, prop) {
if (!of_prop_cmp(prop->name, prop_fix->name))
break;
}
if (!prop)
return -EINVAL;
for (i = 0; i < count; i++) {
off = be32_to_cpu(((__be32 *)prop_fix->value)[i]);
if ((off + 4) > prop->length)
return -EINVAL;
phandle = be32_to_cpu(*(__be32 *)(prop->value + off));
phandle += phandle_delta;
*(__be32 *)(prop->value + off) = cpu_to_be32(phandle);
}
}
for_each_child_of_node(local_fixups, child) {
for_each_child_of_node(overlay, overlay_child)
if (!node_name_cmp(child, overlay_child))
break;
if (!overlay_child)
return -EINVAL;
err = adjust_local_phandle_references(child, overlay_child,
phandle_delta);
if (err)
return err;
}
return 0;
}
int of_resolve_phandles(struct device_node *overlay)
{
struct device_node *child, *local_fixups, *refnode;
struct device_node *tree_symbols, *overlay_fixups;
struct property *prop;
const char *refpath;
phandle phandle, phandle_delta;
int err;
tree_symbols = NULL;
if (!overlay) {
pr_err("null overlay\n");
err = -EINVAL;
goto out;
}
if (!of_node_check_flag(overlay, OF_DETACHED)) {
pr_err("overlay not detached\n");
err = -EINVAL;
goto out;
}
phandle_delta = live_tree_max_phandle() + 1;
adjust_overlay_phandles(overlay, phandle_delta);
for_each_child_of_node(overlay, local_fixups)
if (!of_node_cmp(local_fixups->name, "__local_fixups__"))
break;
err = adjust_local_phandle_references(local_fixups, overlay, phandle_delta);
if (err)
goto out;
overlay_fixups = NULL;
for_each_child_of_node(overlay, child) {
if (!of_node_cmp(child->name, "__fixups__"))
overlay_fixups = child;
}
if (!overlay_fixups) {
err = 0;
goto out;
}
tree_symbols = of_find_node_by_path("/__symbols__");
if (!tree_symbols) {
pr_err("no symbols in root of device tree.\n");
err = -EINVAL;
goto out;
}
for_each_property_of_node(overlay_fixups, prop) {
if (!of_prop_cmp(prop->name, "name"))
continue;
err = of_property_read_string(tree_symbols,
prop->name, &refpath);
if (err)
goto out;
refnode = of_find_node_by_path(refpath);
if (!refnode) {
err = -ENOENT;
goto out;
}
phandle = refnode->phandle;
of_node_put(refnode);
err = update_usages_of_a_phandle_reference(overlay, prop, phandle);
if (err)
break;
}
out:
if (err)
pr_err("overlay phandle fixup failed: %d\n", err);
of_node_put(tree_symbols);
return err;
}
