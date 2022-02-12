static ssize_t security_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct tb *tb = container_of(dev, struct tb, dev);
return sprintf(buf, "%s\n", tb_security_names[tb->security_level]);
}
static void tb_domain_release(struct device *dev)
{
struct tb *tb = container_of(dev, struct tb, dev);
tb_ctl_free(tb->ctl);
destroy_workqueue(tb->wq);
ida_simple_remove(&tb_domain_ida, tb->index);
mutex_destroy(&tb->lock);
kfree(tb);
}
struct tb *tb_domain_alloc(struct tb_nhi *nhi, size_t privsize)
{
struct tb *tb;
BUILD_BUG_ON(sizeof(struct tb_regs_switch_header) != 5 * 4);
BUILD_BUG_ON(sizeof(struct tb_regs_port_header) != 8 * 4);
BUILD_BUG_ON(sizeof(struct tb_regs_hop) != 2 * 4);
tb = kzalloc(sizeof(*tb) + privsize, GFP_KERNEL);
if (!tb)
return NULL;
tb->nhi = nhi;
mutex_init(&tb->lock);
tb->index = ida_simple_get(&tb_domain_ida, 0, 0, GFP_KERNEL);
if (tb->index < 0)
goto err_free;
tb->wq = alloc_ordered_workqueue("thunderbolt%d", 0, tb->index);
if (!tb->wq)
goto err_remove_ida;
tb->dev.parent = &nhi->pdev->dev;
tb->dev.bus = &tb_bus_type;
tb->dev.type = &tb_domain_type;
tb->dev.groups = domain_attr_groups;
dev_set_name(&tb->dev, "domain%d", tb->index);
device_initialize(&tb->dev);
return tb;
err_remove_ida:
ida_simple_remove(&tb_domain_ida, tb->index);
err_free:
kfree(tb);
return NULL;
}
static void tb_domain_event_cb(void *data, enum tb_cfg_pkg_type type,
const void *buf, size_t size)
{
struct tb *tb = data;
if (!tb->cm_ops->handle_event) {
tb_warn(tb, "domain does not have event handler\n");
return;
}
tb->cm_ops->handle_event(tb, type, buf, size);
}
int tb_domain_add(struct tb *tb)
{
int ret;
if (WARN_ON(!tb->cm_ops))
return -EINVAL;
mutex_lock(&tb->lock);
tb->ctl = tb_ctl_alloc(tb->nhi, tb_domain_event_cb, tb);
if (!tb->ctl) {
ret = -ENOMEM;
goto err_unlock;
}
tb_ctl_start(tb->ctl);
if (tb->cm_ops->driver_ready) {
ret = tb->cm_ops->driver_ready(tb);
if (ret)
goto err_ctl_stop;
}
ret = device_add(&tb->dev);
if (ret)
goto err_ctl_stop;
if (tb->cm_ops->start) {
ret = tb->cm_ops->start(tb);
if (ret)
goto err_domain_del;
}
mutex_unlock(&tb->lock);
return 0;
err_domain_del:
device_del(&tb->dev);
err_ctl_stop:
tb_ctl_stop(tb->ctl);
err_unlock:
mutex_unlock(&tb->lock);
return ret;
}
void tb_domain_remove(struct tb *tb)
{
mutex_lock(&tb->lock);
if (tb->cm_ops->stop)
tb->cm_ops->stop(tb);
tb_ctl_stop(tb->ctl);
mutex_unlock(&tb->lock);
flush_workqueue(tb->wq);
device_unregister(&tb->dev);
}
int tb_domain_suspend_noirq(struct tb *tb)
{
int ret = 0;
mutex_lock(&tb->lock);
if (tb->cm_ops->suspend_noirq)
ret = tb->cm_ops->suspend_noirq(tb);
if (!ret)
tb_ctl_stop(tb->ctl);
mutex_unlock(&tb->lock);
return ret;
}
int tb_domain_resume_noirq(struct tb *tb)
{
int ret = 0;
mutex_lock(&tb->lock);
tb_ctl_start(tb->ctl);
if (tb->cm_ops->resume_noirq)
ret = tb->cm_ops->resume_noirq(tb);
mutex_unlock(&tb->lock);
return ret;
}
int tb_domain_suspend(struct tb *tb)
{
int ret;
mutex_lock(&tb->lock);
if (tb->cm_ops->suspend) {
ret = tb->cm_ops->suspend(tb);
if (ret) {
mutex_unlock(&tb->lock);
return ret;
}
}
mutex_unlock(&tb->lock);
return 0;
}
void tb_domain_complete(struct tb *tb)
{
mutex_lock(&tb->lock);
if (tb->cm_ops->complete)
tb->cm_ops->complete(tb);
mutex_unlock(&tb->lock);
}
int tb_domain_approve_switch(struct tb *tb, struct tb_switch *sw)
{
struct tb_switch *parent_sw;
if (!tb->cm_ops->approve_switch)
return -EPERM;
parent_sw = tb_to_switch(sw->dev.parent);
if (!parent_sw || !parent_sw->authorized)
return -EINVAL;
return tb->cm_ops->approve_switch(tb, sw);
}
int tb_domain_approve_switch_key(struct tb *tb, struct tb_switch *sw)
{
struct tb_switch *parent_sw;
int ret;
if (!tb->cm_ops->approve_switch || !tb->cm_ops->add_switch_key)
return -EPERM;
parent_sw = tb_to_switch(sw->dev.parent);
if (!parent_sw || !parent_sw->authorized)
return -EINVAL;
ret = tb->cm_ops->add_switch_key(tb, sw);
if (ret)
return ret;
return tb->cm_ops->approve_switch(tb, sw);
}
int tb_domain_challenge_switch_key(struct tb *tb, struct tb_switch *sw)
{
u8 challenge[TB_SWITCH_KEY_SIZE];
u8 response[TB_SWITCH_KEY_SIZE];
u8 hmac[TB_SWITCH_KEY_SIZE];
struct tb_switch *parent_sw;
struct crypto_shash *tfm;
struct shash_desc *shash;
int ret;
if (!tb->cm_ops->approve_switch || !tb->cm_ops->challenge_switch_key)
return -EPERM;
parent_sw = tb_to_switch(sw->dev.parent);
if (!parent_sw || !parent_sw->authorized)
return -EINVAL;
get_random_bytes(challenge, sizeof(challenge));
ret = tb->cm_ops->challenge_switch_key(tb, sw, challenge, response);
if (ret)
return ret;
tfm = crypto_alloc_shash("hmac(sha256)", 0, 0);
if (IS_ERR(tfm))
return PTR_ERR(tfm);
ret = crypto_shash_setkey(tfm, sw->key, TB_SWITCH_KEY_SIZE);
if (ret)
goto err_free_tfm;
shash = kzalloc(sizeof(*shash) + crypto_shash_descsize(tfm),
GFP_KERNEL);
if (!shash) {
ret = -ENOMEM;
goto err_free_tfm;
}
shash->tfm = tfm;
shash->flags = CRYPTO_TFM_REQ_MAY_SLEEP;
memset(hmac, 0, sizeof(hmac));
ret = crypto_shash_digest(shash, challenge, sizeof(hmac), hmac);
if (ret)
goto err_free_shash;
if (memcmp(response, hmac, sizeof(hmac))) {
ret = -EKEYREJECTED;
goto err_free_shash;
}
crypto_free_shash(tfm);
kfree(shash);
return tb->cm_ops->approve_switch(tb, sw);
err_free_shash:
kfree(shash);
err_free_tfm:
crypto_free_shash(tfm);
return ret;
}
int tb_domain_disconnect_pcie_paths(struct tb *tb)
{
if (!tb->cm_ops->disconnect_pcie_paths)
return -EPERM;
return tb->cm_ops->disconnect_pcie_paths(tb);
}
int tb_domain_init(void)
{
return bus_register(&tb_bus_type);
}
void tb_domain_exit(void)
{
bus_unregister(&tb_bus_type);
ida_destroy(&tb_domain_ida);
tb_switch_exit();
}
