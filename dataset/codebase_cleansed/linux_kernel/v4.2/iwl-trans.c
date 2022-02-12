struct iwl_trans *iwl_trans_alloc(unsigned int priv_size,
struct device *dev,
const struct iwl_cfg *cfg,
const struct iwl_trans_ops *ops,
size_t dev_cmd_headroom)
{
struct iwl_trans *trans;
#ifdef CONFIG_LOCKDEP
static struct lock_class_key __key;
#endif
trans = kzalloc(sizeof(*trans) + priv_size, GFP_KERNEL);
if (!trans)
return NULL;
#ifdef CONFIG_LOCKDEP
lockdep_init_map(&trans->sync_cmd_lockdep_map, "sync_cmd_lockdep_map",
&__key, 0);
#endif
trans->dev = dev;
trans->cfg = cfg;
trans->ops = ops;
trans->dev_cmd_headroom = dev_cmd_headroom;
snprintf(trans->dev_cmd_pool_name, sizeof(trans->dev_cmd_pool_name),
"iwl_cmd_pool:%s", dev_name(trans->dev));
trans->dev_cmd_pool =
kmem_cache_create(trans->dev_cmd_pool_name,
sizeof(struct iwl_device_cmd)
+ trans->dev_cmd_headroom,
sizeof(void *),
SLAB_HWCACHE_ALIGN,
NULL);
if (!trans->dev_cmd_pool)
goto free;
return trans;
free:
kfree(trans);
return NULL;
}
void iwl_trans_free(struct iwl_trans *trans)
{
kmem_cache_destroy(trans->dev_cmd_pool);
kfree(trans);
}
