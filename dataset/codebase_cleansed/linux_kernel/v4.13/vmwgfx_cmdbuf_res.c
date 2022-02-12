struct vmw_resource *
vmw_cmdbuf_res_lookup(struct vmw_cmdbuf_res_manager *man,
enum vmw_cmdbuf_res_type res_type,
u32 user_key)
{
struct drm_hash_item *hash;
int ret;
unsigned long key = user_key | (res_type << 24);
ret = drm_ht_find_item(&man->resources, key, &hash);
if (unlikely(ret != 0))
return ERR_PTR(ret);
return vmw_resource_reference
(drm_hash_entry(hash, struct vmw_cmdbuf_res, hash)->res);
}
static void vmw_cmdbuf_res_free(struct vmw_cmdbuf_res_manager *man,
struct vmw_cmdbuf_res *entry)
{
list_del(&entry->head);
WARN_ON(drm_ht_remove_item(&man->resources, &entry->hash));
vmw_resource_unreference(&entry->res);
kfree(entry);
}
void vmw_cmdbuf_res_commit(struct list_head *list)
{
struct vmw_cmdbuf_res *entry, *next;
list_for_each_entry_safe(entry, next, list, head) {
list_del(&entry->head);
if (entry->res->func->commit_notify)
entry->res->func->commit_notify(entry->res,
entry->state);
switch (entry->state) {
case VMW_CMDBUF_RES_ADD:
entry->state = VMW_CMDBUF_RES_COMMITTED;
list_add_tail(&entry->head, &entry->man->list);
break;
case VMW_CMDBUF_RES_DEL:
vmw_resource_unreference(&entry->res);
kfree(entry);
break;
default:
BUG();
break;
}
}
}
void vmw_cmdbuf_res_revert(struct list_head *list)
{
struct vmw_cmdbuf_res *entry, *next;
int ret;
list_for_each_entry_safe(entry, next, list, head) {
switch (entry->state) {
case VMW_CMDBUF_RES_ADD:
vmw_cmdbuf_res_free(entry->man, entry);
break;
case VMW_CMDBUF_RES_DEL:
ret = drm_ht_insert_item(&entry->man->resources,
&entry->hash);
list_del(&entry->head);
list_add_tail(&entry->head, &entry->man->list);
entry->state = VMW_CMDBUF_RES_COMMITTED;
break;
default:
BUG();
break;
}
}
}
int vmw_cmdbuf_res_add(struct vmw_cmdbuf_res_manager *man,
enum vmw_cmdbuf_res_type res_type,
u32 user_key,
struct vmw_resource *res,
struct list_head *list)
{
struct vmw_cmdbuf_res *cres;
int ret;
cres = kzalloc(sizeof(*cres), GFP_KERNEL);
if (unlikely(!cres))
return -ENOMEM;
cres->hash.key = user_key | (res_type << 24);
ret = drm_ht_insert_item(&man->resources, &cres->hash);
if (unlikely(ret != 0))
goto out_invalid_key;
cres->state = VMW_CMDBUF_RES_ADD;
cres->res = vmw_resource_reference(res);
cres->man = man;
list_add_tail(&cres->head, list);
out_invalid_key:
return ret;
}
int vmw_cmdbuf_res_remove(struct vmw_cmdbuf_res_manager *man,
enum vmw_cmdbuf_res_type res_type,
u32 user_key,
struct list_head *list,
struct vmw_resource **res_p)
{
struct vmw_cmdbuf_res *entry;
struct drm_hash_item *hash;
int ret;
ret = drm_ht_find_item(&man->resources, user_key | (res_type << 24),
&hash);
if (likely(ret != 0))
return -EINVAL;
entry = drm_hash_entry(hash, struct vmw_cmdbuf_res, hash);
switch (entry->state) {
case VMW_CMDBUF_RES_ADD:
vmw_cmdbuf_res_free(man, entry);
*res_p = NULL;
break;
case VMW_CMDBUF_RES_COMMITTED:
(void) drm_ht_remove_item(&man->resources, &entry->hash);
list_del(&entry->head);
entry->state = VMW_CMDBUF_RES_DEL;
list_add_tail(&entry->head, list);
*res_p = entry->res;
break;
default:
BUG();
break;
}
return 0;
}
struct vmw_cmdbuf_res_manager *
vmw_cmdbuf_res_man_create(struct vmw_private *dev_priv)
{
struct vmw_cmdbuf_res_manager *man;
int ret;
man = kzalloc(sizeof(*man), GFP_KERNEL);
if (!man)
return ERR_PTR(-ENOMEM);
man->dev_priv = dev_priv;
INIT_LIST_HEAD(&man->list);
ret = drm_ht_create(&man->resources, VMW_CMDBUF_RES_MAN_HT_ORDER);
if (ret == 0)
return man;
kfree(man);
return ERR_PTR(ret);
}
void vmw_cmdbuf_res_man_destroy(struct vmw_cmdbuf_res_manager *man)
{
struct vmw_cmdbuf_res *entry, *next;
list_for_each_entry_safe(entry, next, &man->list, head)
vmw_cmdbuf_res_free(man, entry);
drm_ht_remove(&man->resources);
kfree(man);
}
size_t vmw_cmdbuf_res_man_size(void)
{
static size_t res_man_size;
if (unlikely(res_man_size == 0))
res_man_size =
ttm_round_pot(sizeof(struct vmw_cmdbuf_res_manager)) +
ttm_round_pot(sizeof(struct hlist_head) <<
VMW_CMDBUF_RES_MAN_HT_ORDER);
return res_man_size;
}
