__u64 ldlm_extent_shift_kms(struct ldlm_lock *lock, __u64 old_kms)
{
struct ldlm_resource *res = lock->l_resource;
struct list_head *tmp;
struct ldlm_lock *lck;
__u64 kms = 0;
ldlm_set_kms_ignore(lock);
list_for_each(tmp, &res->lr_granted) {
lck = list_entry(tmp, struct ldlm_lock, l_res_link);
if (ldlm_is_kms_ignore(lck))
continue;
if (lck->l_policy_data.l_extent.end >= old_kms)
return old_kms;
if (lck->l_policy_data.l_extent.end + 1 > kms)
kms = lck->l_policy_data.l_extent.end + 1;
}
LASSERTF(kms <= old_kms, "kms %llu old_kms %llu\n", kms, old_kms);
return kms;
}
static void ldlm_interval_attach(struct ldlm_interval *n, struct ldlm_lock *l)
{
LASSERT(!l->l_tree_node);
LASSERT(l->l_resource->lr_type == LDLM_EXTENT);
list_add_tail(&l->l_sl_policy, &n->li_group);
l->l_tree_node = n;
}
struct ldlm_interval *ldlm_interval_alloc(struct ldlm_lock *lock)
{
struct ldlm_interval *node;
LASSERT(lock->l_resource->lr_type == LDLM_EXTENT);
node = kmem_cache_zalloc(ldlm_interval_slab, GFP_NOFS);
if (!node)
return NULL;
INIT_LIST_HEAD(&node->li_group);
ldlm_interval_attach(node, lock);
return node;
}
void ldlm_interval_free(struct ldlm_interval *node)
{
if (node) {
LASSERT(list_empty(&node->li_group));
LASSERT(!interval_is_intree(&node->li_node));
kmem_cache_free(ldlm_interval_slab, node);
}
}
struct ldlm_interval *ldlm_interval_detach(struct ldlm_lock *l)
{
struct ldlm_interval *n = l->l_tree_node;
if (!n)
return NULL;
LASSERT(!list_empty(&n->li_group));
l->l_tree_node = NULL;
list_del_init(&l->l_sl_policy);
return list_empty(&n->li_group) ? n : NULL;
}
static inline int lock_mode_to_index(enum ldlm_mode mode)
{
int index;
LASSERT(mode != 0);
LASSERT(is_power_of_2(mode));
for (index = -1; mode; index++)
mode >>= 1;
LASSERT(index < LCK_MODE_NUM);
return index;
}
void ldlm_extent_add_lock(struct ldlm_resource *res,
struct ldlm_lock *lock)
{
struct interval_node *found, **root;
struct ldlm_interval *node;
struct ldlm_extent *extent;
int idx, rc;
LASSERT(lock->l_granted_mode == lock->l_req_mode);
node = lock->l_tree_node;
LASSERT(node);
LASSERT(!interval_is_intree(&node->li_node));
idx = lock_mode_to_index(lock->l_granted_mode);
LASSERT(lock->l_granted_mode == 1 << idx);
LASSERT(lock->l_granted_mode == res->lr_itree[idx].lit_mode);
extent = &lock->l_policy_data.l_extent;
rc = interval_set(&node->li_node, extent->start, extent->end);
LASSERT(!rc);
root = &res->lr_itree[idx].lit_root;
found = interval_insert(&node->li_node, root);
if (found) {
struct ldlm_interval *tmp;
tmp = ldlm_interval_detach(lock);
ldlm_interval_free(tmp);
ldlm_interval_attach(to_ldlm_interval(found), lock);
}
res->lr_itree[idx].lit_size++;
ldlm_resource_add_lock(res, &res->lr_granted, lock);
if (OBD_FAIL_CHECK(OBD_FAIL_LDLM_GRANT_CHECK)) {
struct ldlm_lock *lck;
list_for_each_entry_reverse(lck, &res->lr_granted,
l_res_link) {
if (lck == lock)
continue;
if (lockmode_compat(lck->l_granted_mode,
lock->l_granted_mode))
continue;
if (ldlm_extent_overlap(&lck->l_req_extent,
&lock->l_req_extent)) {
CDEBUG(D_ERROR, "granting conflicting lock %p %p\n",
lck, lock);
ldlm_resource_dump(D_ERROR, res);
LBUG();
}
}
}
}
void ldlm_extent_unlink_lock(struct ldlm_lock *lock)
{
struct ldlm_resource *res = lock->l_resource;
struct ldlm_interval *node = lock->l_tree_node;
struct ldlm_interval_tree *tree;
int idx;
if (!node || !interval_is_intree(&node->li_node))
return;
idx = lock_mode_to_index(lock->l_granted_mode);
LASSERT(lock->l_granted_mode == 1 << idx);
tree = &res->lr_itree[idx];
LASSERT(tree->lit_root);
tree->lit_size--;
node = ldlm_interval_detach(lock);
if (node) {
interval_erase(&node->li_node, &tree->lit_root);
ldlm_interval_free(node);
}
}
void ldlm_extent_policy_wire_to_local(const union ldlm_wire_policy_data *wpolicy,
union ldlm_policy_data *lpolicy)
{
lpolicy->l_extent.start = wpolicy->l_extent.start;
lpolicy->l_extent.end = wpolicy->l_extent.end;
lpolicy->l_extent.gid = wpolicy->l_extent.gid;
}
void ldlm_extent_policy_local_to_wire(const union ldlm_policy_data *lpolicy,
union ldlm_wire_policy_data *wpolicy)
{
memset(wpolicy, 0, sizeof(*wpolicy));
wpolicy->l_extent.start = lpolicy->l_extent.start;
wpolicy->l_extent.end = lpolicy->l_extent.end;
wpolicy->l_extent.gid = lpolicy->l_extent.gid;
}
