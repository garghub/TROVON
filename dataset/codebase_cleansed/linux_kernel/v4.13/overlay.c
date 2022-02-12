int of_overlay_notifier_register(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&of_overlay_chain, nb);
}
int of_overlay_notifier_unregister(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&of_overlay_chain, nb);
}
static int of_overlay_notify(struct of_overlay *ov,
enum of_overlay_notify_action action)
{
struct of_overlay_notify_data nd;
int i, ret;
for (i = 0; i < ov->count; i++) {
struct of_overlay_info *ovinfo = &ov->ovinfo_tab[i];
nd.target = ovinfo->target;
nd.overlay = ovinfo->overlay;
ret = blocking_notifier_call_chain(&of_overlay_chain,
action, &nd);
if (ret)
return notifier_to_errno(ret);
}
return 0;
}
static int of_overlay_apply_single_property(struct of_overlay *ov,
struct device_node *target, struct property *prop)
{
struct property *propn, *tprop;
tprop = of_find_property(target, prop->name, NULL);
if (of_prop_cmp(prop->name, "name") == 0 ||
of_prop_cmp(prop->name, "phandle") == 0 ||
of_prop_cmp(prop->name, "linux,phandle") == 0)
return 0;
propn = __of_prop_dup(prop, GFP_KERNEL);
if (propn == NULL)
return -ENOMEM;
if (tprop == NULL)
return of_changeset_add_property(&ov->cset, target, propn);
return of_changeset_update_property(&ov->cset, target, propn);
}
static int of_overlay_apply_single_device_node(struct of_overlay *ov,
struct device_node *target, struct device_node *child)
{
const char *cname;
struct device_node *tchild;
int ret = 0;
cname = kbasename(child->full_name);
if (cname == NULL)
return -ENOMEM;
tchild = of_get_child_by_name(target, cname);
if (tchild != NULL) {
if (child->phandle)
return -EINVAL;
ret = of_overlay_apply_one(ov, tchild, child);
of_node_put(tchild);
} else {
tchild = __of_node_dup(child, "%s/%s", target->full_name, cname);
if (!tchild)
return -ENOMEM;
tchild->parent = target;
ret = of_changeset_attach_node(&ov->cset, tchild);
if (ret)
return ret;
ret = of_overlay_apply_one(ov, tchild, child);
if (ret)
return ret;
}
return ret;
}
static int of_overlay_apply_one(struct of_overlay *ov,
struct device_node *target, const struct device_node *overlay)
{
struct device_node *child;
struct property *prop;
int ret;
for_each_property_of_node(overlay, prop) {
ret = of_overlay_apply_single_property(ov, target, prop);
if (ret) {
pr_err("Failed to apply prop @%s/%s\n",
target->full_name, prop->name);
return ret;
}
}
for_each_child_of_node(overlay, child) {
ret = of_overlay_apply_single_device_node(ov, target, child);
if (ret != 0) {
pr_err("Failed to apply single node @%s/%s\n",
target->full_name, child->name);
of_node_put(child);
return ret;
}
}
return 0;
}
static int of_overlay_apply(struct of_overlay *ov)
{
int i, err;
for (i = 0; i < ov->count; i++) {
struct of_overlay_info *ovinfo = &ov->ovinfo_tab[i];
err = of_overlay_apply_one(ov, ovinfo->target, ovinfo->overlay);
if (err != 0) {
pr_err("apply failed '%s'\n", ovinfo->target->full_name);
return err;
}
}
return 0;
}
static struct device_node *find_target_node(struct device_node *info_node)
{
const char *path;
u32 val;
int ret;
ret = of_property_read_u32(info_node, "target", &val);
if (ret == 0)
return of_find_node_by_phandle(val);
ret = of_property_read_string(info_node, "target-path", &path);
if (ret == 0)
return of_find_node_by_path(path);
pr_err("Failed to find target for node %p (%s)\n",
info_node, info_node->name);
return NULL;
}
static int of_fill_overlay_info(struct of_overlay *ov,
struct device_node *info_node, struct of_overlay_info *ovinfo)
{
ovinfo->overlay = of_get_child_by_name(info_node, "__overlay__");
if (ovinfo->overlay == NULL)
goto err_fail;
ovinfo->target = find_target_node(info_node);
if (ovinfo->target == NULL)
goto err_fail;
return 0;
err_fail:
of_node_put(ovinfo->target);
of_node_put(ovinfo->overlay);
memset(ovinfo, 0, sizeof(*ovinfo));
return -EINVAL;
}
static int of_build_overlay_info(struct of_overlay *ov,
struct device_node *tree)
{
struct device_node *node;
struct of_overlay_info *ovinfo;
int cnt, err;
cnt = 0;
for_each_child_of_node(tree, node)
cnt++;
ovinfo = kcalloc(cnt, sizeof(*ovinfo), GFP_KERNEL);
if (ovinfo == NULL)
return -ENOMEM;
cnt = 0;
for_each_child_of_node(tree, node) {
err = of_fill_overlay_info(ov, node, &ovinfo[cnt]);
if (err == 0)
cnt++;
}
if (cnt == 0) {
kfree(ovinfo);
return -ENODEV;
}
ov->count = cnt;
ov->ovinfo_tab = ovinfo;
return 0;
}
static int of_free_overlay_info(struct of_overlay *ov)
{
struct of_overlay_info *ovinfo;
int i;
for (i = ov->count - 1; i >= 0; i--) {
ovinfo = &ov->ovinfo_tab[i];
of_node_put(ovinfo->target);
of_node_put(ovinfo->overlay);
}
kfree(ov->ovinfo_tab);
return 0;
}
int of_overlay_create(struct device_node *tree)
{
struct of_overlay *ov;
int err, id;
ov = kzalloc(sizeof(*ov), GFP_KERNEL);
if (ov == NULL)
return -ENOMEM;
ov->id = -1;
INIT_LIST_HEAD(&ov->node);
of_changeset_init(&ov->cset);
mutex_lock(&of_mutex);
id = idr_alloc(&ov_idr, ov, 0, 0, GFP_KERNEL);
if (id < 0) {
err = id;
goto err_destroy_trans;
}
ov->id = id;
err = of_build_overlay_info(ov, tree);
if (err) {
pr_err("of_build_overlay_info() failed for tree@%s\n",
tree->full_name);
goto err_free_idr;
}
err = of_overlay_notify(ov, OF_OVERLAY_PRE_APPLY);
if (err < 0) {
pr_err("%s: Pre-apply notifier failed (err=%d)\n",
__func__, err);
goto err_free_idr;
}
err = of_overlay_apply(ov);
if (err)
goto err_abort_trans;
err = __of_changeset_apply(&ov->cset);
if (err)
goto err_revert_overlay;
list_add_tail(&ov->node, &ov_list);
of_overlay_notify(ov, OF_OVERLAY_POST_APPLY);
mutex_unlock(&of_mutex);
return id;
err_revert_overlay:
err_abort_trans:
of_free_overlay_info(ov);
err_free_idr:
idr_remove(&ov_idr, ov->id);
err_destroy_trans:
of_changeset_destroy(&ov->cset);
kfree(ov);
mutex_unlock(&of_mutex);
return err;
}
static int overlay_subtree_check(struct device_node *tree,
struct device_node *dn)
{
struct device_node *child;
if (tree == dn)
return 1;
for_each_child_of_node(tree, child) {
if (overlay_subtree_check(child, dn)) {
of_node_put(child);
return 1;
}
}
return 0;
}
static int overlay_is_topmost(struct of_overlay *ov, struct device_node *dn)
{
struct of_overlay *ovt;
struct of_changeset_entry *ce;
list_for_each_entry_reverse(ovt, &ov_list, node) {
if (ovt == ov)
break;
list_for_each_entry(ce, &ovt->cset.entries, node) {
if (overlay_subtree_check(ce->np, dn)) {
pr_err("%s: #%d clashes #%d @%s\n",
__func__, ov->id, ovt->id,
dn->full_name);
return 0;
}
}
}
return 1;
}
static int overlay_removal_is_ok(struct of_overlay *ov)
{
struct of_changeset_entry *ce;
list_for_each_entry(ce, &ov->cset.entries, node) {
if (!overlay_is_topmost(ov, ce->np)) {
pr_err("overlay #%d is not topmost\n", ov->id);
return 0;
}
}
return 1;
}
int of_overlay_destroy(int id)
{
struct of_overlay *ov;
int err;
mutex_lock(&of_mutex);
ov = idr_find(&ov_idr, id);
if (ov == NULL) {
err = -ENODEV;
pr_err("destroy: Could not find overlay #%d\n", id);
goto out;
}
if (!overlay_removal_is_ok(ov)) {
err = -EBUSY;
goto out;
}
of_overlay_notify(ov, OF_OVERLAY_PRE_REMOVE);
list_del(&ov->node);
__of_changeset_revert(&ov->cset);
of_overlay_notify(ov, OF_OVERLAY_POST_REMOVE);
of_free_overlay_info(ov);
idr_remove(&ov_idr, id);
of_changeset_destroy(&ov->cset);
kfree(ov);
err = 0;
out:
mutex_unlock(&of_mutex);
return err;
}
int of_overlay_destroy_all(void)
{
struct of_overlay *ov, *ovn;
mutex_lock(&of_mutex);
list_for_each_entry_safe_reverse(ov, ovn, &ov_list, node) {
list_del(&ov->node);
__of_changeset_revert(&ov->cset);
of_free_overlay_info(ov);
idr_remove(&ov_idr, ov->id);
kfree(ov);
}
mutex_unlock(&of_mutex);
return 0;
}
