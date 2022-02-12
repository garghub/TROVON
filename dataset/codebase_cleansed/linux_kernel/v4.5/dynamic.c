struct device_node *of_node_get(struct device_node *node)
{
if (node)
kobject_get(&node->kobj);
return node;
}
void of_node_put(struct device_node *node)
{
if (node)
kobject_put(&node->kobj);
}
void __of_detach_node_sysfs(struct device_node *np)
{
struct property *pp;
if (!IS_ENABLED(CONFIG_SYSFS))
return;
BUG_ON(!of_node_is_initialized(np));
if (!of_kset)
return;
if (of_node_is_attached(np)) {
for_each_property_of_node(np, pp)
sysfs_remove_bin_file(&np->kobj, &pp->attr);
kobject_del(&np->kobj);
}
of_node_put(np);
}
int of_reconfig_notifier_register(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&of_reconfig_chain, nb);
}
int of_reconfig_notifier_unregister(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&of_reconfig_chain, nb);
}
int of_reconfig_notify(unsigned long action, struct of_reconfig_data *p)
{
int rc;
#ifdef DEBUG
struct of_reconfig_data *pr = p;
switch (action) {
case OF_RECONFIG_ATTACH_NODE:
case OF_RECONFIG_DETACH_NODE:
pr_debug("of/notify %-15s %s\n", action_names[action],
pr->dn->full_name);
break;
case OF_RECONFIG_ADD_PROPERTY:
case OF_RECONFIG_REMOVE_PROPERTY:
case OF_RECONFIG_UPDATE_PROPERTY:
pr_debug("of/notify %-15s %s:%s\n", action_names[action],
pr->dn->full_name, pr->prop->name);
break;
}
#endif
rc = blocking_notifier_call_chain(&of_reconfig_chain, action, p);
return notifier_to_errno(rc);
}
int of_reconfig_get_state_change(unsigned long action, struct of_reconfig_data *pr)
{
struct property *prop, *old_prop = NULL;
int is_status, status_state, old_status_state, prev_state, new_state;
switch (action) {
case OF_RECONFIG_ATTACH_NODE:
case OF_RECONFIG_DETACH_NODE:
prop = of_find_property(pr->dn, "status", NULL);
break;
case OF_RECONFIG_ADD_PROPERTY:
case OF_RECONFIG_REMOVE_PROPERTY:
prop = pr->prop;
break;
case OF_RECONFIG_UPDATE_PROPERTY:
prop = pr->prop;
old_prop = pr->old_prop;
break;
default:
return OF_RECONFIG_NO_CHANGE;
}
is_status = 0;
status_state = -1;
old_status_state = -1;
prev_state = -1;
new_state = -1;
if (prop && !strcmp(prop->name, "status")) {
is_status = 1;
status_state = !strcmp(prop->value, "okay") ||
!strcmp(prop->value, "ok");
if (old_prop)
old_status_state = !strcmp(old_prop->value, "okay") ||
!strcmp(old_prop->value, "ok");
}
switch (action) {
case OF_RECONFIG_ATTACH_NODE:
prev_state = 0;
new_state = status_state != 0;
break;
case OF_RECONFIG_DETACH_NODE:
prev_state = status_state != 0;
new_state = 0;
break;
case OF_RECONFIG_ADD_PROPERTY:
if (is_status) {
prev_state = 1;
new_state = status_state;
}
break;
case OF_RECONFIG_REMOVE_PROPERTY:
if (is_status) {
prev_state = status_state;
new_state = 1;
}
break;
case OF_RECONFIG_UPDATE_PROPERTY:
if (is_status) {
prev_state = old_status_state != 0;
new_state = status_state != 0;
}
break;
}
if (prev_state == new_state)
return OF_RECONFIG_NO_CHANGE;
return new_state ? OF_RECONFIG_CHANGE_ADD : OF_RECONFIG_CHANGE_REMOVE;
}
int of_property_notify(int action, struct device_node *np,
struct property *prop, struct property *oldprop)
{
struct of_reconfig_data pr;
if (!of_node_is_attached(np))
return 0;
pr.dn = np;
pr.prop = prop;
pr.old_prop = oldprop;
return of_reconfig_notify(action, &pr);
}
void __of_attach_node(struct device_node *np)
{
const __be32 *phandle;
int sz;
np->name = __of_get_property(np, "name", NULL) ? : "<NULL>";
np->type = __of_get_property(np, "device_type", NULL) ? : "<NULL>";
phandle = __of_get_property(np, "phandle", &sz);
if (!phandle)
phandle = __of_get_property(np, "linux,phandle", &sz);
if (IS_ENABLED(CONFIG_PPC_PSERIES) && !phandle)
phandle = __of_get_property(np, "ibm,phandle", &sz);
np->phandle = (phandle && (sz >= 4)) ? be32_to_cpup(phandle) : 0;
np->child = NULL;
np->sibling = np->parent->child;
np->parent->child = np;
of_node_clear_flag(np, OF_DETACHED);
}
int of_attach_node(struct device_node *np)
{
struct of_reconfig_data rd;
unsigned long flags;
memset(&rd, 0, sizeof(rd));
rd.dn = np;
mutex_lock(&of_mutex);
raw_spin_lock_irqsave(&devtree_lock, flags);
__of_attach_node(np);
raw_spin_unlock_irqrestore(&devtree_lock, flags);
__of_attach_node_sysfs(np);
mutex_unlock(&of_mutex);
of_reconfig_notify(OF_RECONFIG_ATTACH_NODE, &rd);
return 0;
}
void __of_detach_node(struct device_node *np)
{
struct device_node *parent;
if (WARN_ON(of_node_check_flag(np, OF_DETACHED)))
return;
parent = np->parent;
if (WARN_ON(!parent))
return;
if (parent->child == np)
parent->child = np->sibling;
else {
struct device_node *prevsib;
for (prevsib = np->parent->child;
prevsib->sibling != np;
prevsib = prevsib->sibling)
;
prevsib->sibling = np->sibling;
}
of_node_set_flag(np, OF_DETACHED);
}
int of_detach_node(struct device_node *np)
{
struct of_reconfig_data rd;
unsigned long flags;
int rc = 0;
memset(&rd, 0, sizeof(rd));
rd.dn = np;
mutex_lock(&of_mutex);
raw_spin_lock_irqsave(&devtree_lock, flags);
__of_detach_node(np);
raw_spin_unlock_irqrestore(&devtree_lock, flags);
__of_detach_node_sysfs(np);
mutex_unlock(&of_mutex);
of_reconfig_notify(OF_RECONFIG_DETACH_NODE, &rd);
return rc;
}
void of_node_release(struct kobject *kobj)
{
struct device_node *node = kobj_to_device_node(kobj);
struct property *prop = node->properties;
if (!of_node_check_flag(node, OF_DETACHED)) {
pr_err("ERROR: Bad of_node_put() on %s\n", node->full_name);
dump_stack();
return;
}
if (!of_node_check_flag(node, OF_DYNAMIC))
return;
while (prop) {
struct property *next = prop->next;
kfree(prop->name);
kfree(prop->value);
kfree(prop);
prop = next;
if (!prop) {
prop = node->deadprops;
node->deadprops = NULL;
}
}
kfree(node->full_name);
kfree(node->data);
kfree(node);
}
struct property *__of_prop_dup(const struct property *prop, gfp_t allocflags)
{
struct property *new;
new = kzalloc(sizeof(*new), allocflags);
if (!new)
return NULL;
new->name = kstrdup(prop->name, allocflags);
new->value = kmemdup(prop->value, prop->length, allocflags);
new->length = prop->length;
if (!new->name || !new->value)
goto err_free;
of_property_set_flag(new, OF_DYNAMIC);
return new;
err_free:
kfree(new->name);
kfree(new->value);
kfree(new);
return NULL;
}
struct device_node *__of_node_dup(const struct device_node *np, const char *fmt, ...)
{
va_list vargs;
struct device_node *node;
node = kzalloc(sizeof(*node), GFP_KERNEL);
if (!node)
return NULL;
va_start(vargs, fmt);
node->full_name = kvasprintf(GFP_KERNEL, fmt, vargs);
va_end(vargs);
if (!node->full_name) {
kfree(node);
return NULL;
}
of_node_set_flag(node, OF_DYNAMIC);
of_node_set_flag(node, OF_DETACHED);
of_node_init(node);
if (np) {
struct property *pp, *new_pp;
for_each_property_of_node(np, pp) {
new_pp = __of_prop_dup(pp, GFP_KERNEL);
if (!new_pp)
goto err_prop;
if (__of_add_property(node, new_pp)) {
kfree(new_pp->name);
kfree(new_pp->value);
kfree(new_pp);
goto err_prop;
}
}
}
return node;
err_prop:
of_node_put(node);
return NULL;
}
static void __of_changeset_entry_destroy(struct of_changeset_entry *ce)
{
of_node_put(ce->np);
list_del(&ce->node);
kfree(ce);
}
static void __of_changeset_entry_dump(struct of_changeset_entry *ce)
{
switch (ce->action) {
case OF_RECONFIG_ADD_PROPERTY:
case OF_RECONFIG_REMOVE_PROPERTY:
case OF_RECONFIG_UPDATE_PROPERTY:
pr_debug("of/cset<%p> %-15s %s/%s\n", ce, action_names[ce->action],
ce->np->full_name, ce->prop->name);
break;
case OF_RECONFIG_ATTACH_NODE:
case OF_RECONFIG_DETACH_NODE:
pr_debug("of/cset<%p> %-15s %s\n", ce, action_names[ce->action],
ce->np->full_name);
break;
}
}
static inline void __of_changeset_entry_dump(struct of_changeset_entry *ce)
{
}
static void __of_changeset_entry_invert(struct of_changeset_entry *ce,
struct of_changeset_entry *rce)
{
memcpy(rce, ce, sizeof(*rce));
switch (ce->action) {
case OF_RECONFIG_ATTACH_NODE:
rce->action = OF_RECONFIG_DETACH_NODE;
break;
case OF_RECONFIG_DETACH_NODE:
rce->action = OF_RECONFIG_ATTACH_NODE;
break;
case OF_RECONFIG_ADD_PROPERTY:
rce->action = OF_RECONFIG_REMOVE_PROPERTY;
break;
case OF_RECONFIG_REMOVE_PROPERTY:
rce->action = OF_RECONFIG_ADD_PROPERTY;
break;
case OF_RECONFIG_UPDATE_PROPERTY:
rce->old_prop = ce->prop;
rce->prop = ce->old_prop;
break;
}
}
static void __of_changeset_entry_notify(struct of_changeset_entry *ce, bool revert)
{
struct of_reconfig_data rd;
struct of_changeset_entry ce_inverted;
int ret;
if (revert) {
__of_changeset_entry_invert(ce, &ce_inverted);
ce = &ce_inverted;
}
switch (ce->action) {
case OF_RECONFIG_ATTACH_NODE:
case OF_RECONFIG_DETACH_NODE:
memset(&rd, 0, sizeof(rd));
rd.dn = ce->np;
ret = of_reconfig_notify(ce->action, &rd);
break;
case OF_RECONFIG_ADD_PROPERTY:
case OF_RECONFIG_REMOVE_PROPERTY:
case OF_RECONFIG_UPDATE_PROPERTY:
ret = of_property_notify(ce->action, ce->np, ce->prop, ce->old_prop);
break;
default:
pr_err("%s: invalid devicetree changeset action: %i\n", __func__,
(int)ce->action);
return;
}
if (ret)
pr_err("%s: notifier error @%s\n", __func__, ce->np->full_name);
}
static int __of_changeset_entry_apply(struct of_changeset_entry *ce)
{
struct property *old_prop, **propp;
unsigned long flags;
int ret = 0;
__of_changeset_entry_dump(ce);
raw_spin_lock_irqsave(&devtree_lock, flags);
switch (ce->action) {
case OF_RECONFIG_ATTACH_NODE:
__of_attach_node(ce->np);
break;
case OF_RECONFIG_DETACH_NODE:
__of_detach_node(ce->np);
break;
case OF_RECONFIG_ADD_PROPERTY:
for (propp = &ce->np->deadprops; *propp; propp = &(*propp)->next) {
if (*propp == ce->prop) {
*propp = ce->prop->next;
ce->prop->next = NULL;
break;
}
}
ret = __of_add_property(ce->np, ce->prop);
if (ret) {
pr_err("%s: add_property failed @%s/%s\n",
__func__, ce->np->full_name,
ce->prop->name);
break;
}
break;
case OF_RECONFIG_REMOVE_PROPERTY:
ret = __of_remove_property(ce->np, ce->prop);
if (ret) {
pr_err("%s: remove_property failed @%s/%s\n",
__func__, ce->np->full_name,
ce->prop->name);
break;
}
break;
case OF_RECONFIG_UPDATE_PROPERTY:
for (propp = &ce->np->deadprops; *propp; propp = &(*propp)->next) {
if (*propp == ce->prop) {
*propp = ce->prop->next;
ce->prop->next = NULL;
break;
}
}
ret = __of_update_property(ce->np, ce->prop, &old_prop);
if (ret) {
pr_err("%s: update_property failed @%s/%s\n",
__func__, ce->np->full_name,
ce->prop->name);
break;
}
break;
default:
ret = -EINVAL;
}
raw_spin_unlock_irqrestore(&devtree_lock, flags);
if (ret)
return ret;
switch (ce->action) {
case OF_RECONFIG_ATTACH_NODE:
__of_attach_node_sysfs(ce->np);
break;
case OF_RECONFIG_DETACH_NODE:
__of_detach_node_sysfs(ce->np);
break;
case OF_RECONFIG_ADD_PROPERTY:
__of_add_property_sysfs(ce->np, ce->prop);
break;
case OF_RECONFIG_REMOVE_PROPERTY:
__of_remove_property_sysfs(ce->np, ce->prop);
break;
case OF_RECONFIG_UPDATE_PROPERTY:
__of_update_property_sysfs(ce->np, ce->prop, ce->old_prop);
break;
}
return 0;
}
static inline int __of_changeset_entry_revert(struct of_changeset_entry *ce)
{
struct of_changeset_entry ce_inverted;
__of_changeset_entry_invert(ce, &ce_inverted);
return __of_changeset_entry_apply(&ce_inverted);
}
void of_changeset_init(struct of_changeset *ocs)
{
memset(ocs, 0, sizeof(*ocs));
INIT_LIST_HEAD(&ocs->entries);
}
void of_changeset_destroy(struct of_changeset *ocs)
{
struct of_changeset_entry *ce, *cen;
list_for_each_entry_safe_reverse(ce, cen, &ocs->entries, node)
__of_changeset_entry_destroy(ce);
}
int __of_changeset_apply(struct of_changeset *ocs)
{
struct of_changeset_entry *ce;
int ret;
pr_debug("of_changeset: applying...\n");
list_for_each_entry(ce, &ocs->entries, node) {
ret = __of_changeset_entry_apply(ce);
if (ret) {
pr_err("%s: Error applying changeset (%d)\n", __func__, ret);
list_for_each_entry_continue_reverse(ce, &ocs->entries, node)
__of_changeset_entry_revert(ce);
return ret;
}
}
pr_debug("of_changeset: applied, emitting notifiers.\n");
mutex_unlock(&of_mutex);
list_for_each_entry(ce, &ocs->entries, node)
__of_changeset_entry_notify(ce, 0);
mutex_lock(&of_mutex);
pr_debug("of_changeset: notifiers sent.\n");
return 0;
}
int of_changeset_apply(struct of_changeset *ocs)
{
int ret;
mutex_lock(&of_mutex);
ret = __of_changeset_apply(ocs);
mutex_unlock(&of_mutex);
return ret;
}
int __of_changeset_revert(struct of_changeset *ocs)
{
struct of_changeset_entry *ce;
int ret;
pr_debug("of_changeset: reverting...\n");
list_for_each_entry_reverse(ce, &ocs->entries, node) {
ret = __of_changeset_entry_revert(ce);
if (ret) {
pr_err("%s: Error reverting changeset (%d)\n", __func__, ret);
list_for_each_entry_continue(ce, &ocs->entries, node)
__of_changeset_entry_apply(ce);
return ret;
}
}
pr_debug("of_changeset: reverted, emitting notifiers.\n");
mutex_unlock(&of_mutex);
list_for_each_entry_reverse(ce, &ocs->entries, node)
__of_changeset_entry_notify(ce, 1);
mutex_lock(&of_mutex);
pr_debug("of_changeset: notifiers sent.\n");
return 0;
}
int of_changeset_revert(struct of_changeset *ocs)
{
int ret;
mutex_lock(&of_mutex);
ret = __of_changeset_revert(ocs);
mutex_unlock(&of_mutex);
return ret;
}
int of_changeset_action(struct of_changeset *ocs, unsigned long action,
struct device_node *np, struct property *prop)
{
struct of_changeset_entry *ce;
ce = kzalloc(sizeof(*ce), GFP_KERNEL);
if (!ce) {
pr_err("%s: Failed to allocate\n", __func__);
return -ENOMEM;
}
ce->action = action;
ce->np = of_node_get(np);
ce->prop = prop;
if (action == OF_RECONFIG_UPDATE_PROPERTY && prop)
ce->old_prop = of_find_property(np, prop->name, NULL);
list_add_tail(&ce->node, &ocs->entries);
return 0;
}
