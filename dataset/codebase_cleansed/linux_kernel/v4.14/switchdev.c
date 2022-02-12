void switchdev_trans_item_enqueue(struct switchdev_trans *trans,
void *data, void (*destructor)(void const *),
struct switchdev_trans_item *tritem)
{
tritem->data = data;
tritem->destructor = destructor;
list_add_tail(&tritem->list, &trans->item_list);
}
static struct switchdev_trans_item *
__switchdev_trans_item_dequeue(struct switchdev_trans *trans)
{
struct switchdev_trans_item *tritem;
if (list_empty(&trans->item_list))
return NULL;
tritem = list_first_entry(&trans->item_list,
struct switchdev_trans_item, list);
list_del(&tritem->list);
return tritem;
}
void *switchdev_trans_item_dequeue(struct switchdev_trans *trans)
{
struct switchdev_trans_item *tritem;
tritem = __switchdev_trans_item_dequeue(trans);
BUG_ON(!tritem);
return tritem->data;
}
static void switchdev_trans_init(struct switchdev_trans *trans)
{
INIT_LIST_HEAD(&trans->item_list);
}
static void switchdev_trans_items_destroy(struct switchdev_trans *trans)
{
struct switchdev_trans_item *tritem;
while ((tritem = __switchdev_trans_item_dequeue(trans)))
tritem->destructor(tritem->data);
}
static void switchdev_trans_items_warn_destroy(struct net_device *dev,
struct switchdev_trans *trans)
{
WARN(!list_empty(&trans->item_list), "%s: transaction item queue is not empty.\n",
dev->name);
switchdev_trans_items_destroy(trans);
}
static struct switchdev_deferred_item *switchdev_deferred_dequeue(void)
{
struct switchdev_deferred_item *dfitem;
spin_lock_bh(&deferred_lock);
if (list_empty(&deferred)) {
dfitem = NULL;
goto unlock;
}
dfitem = list_first_entry(&deferred,
struct switchdev_deferred_item, list);
list_del(&dfitem->list);
unlock:
spin_unlock_bh(&deferred_lock);
return dfitem;
}
void switchdev_deferred_process(void)
{
struct switchdev_deferred_item *dfitem;
ASSERT_RTNL();
while ((dfitem = switchdev_deferred_dequeue())) {
dfitem->func(dfitem->dev, dfitem->data);
dev_put(dfitem->dev);
kfree(dfitem);
}
}
static void switchdev_deferred_process_work(struct work_struct *work)
{
rtnl_lock();
switchdev_deferred_process();
rtnl_unlock();
}
static int switchdev_deferred_enqueue(struct net_device *dev,
const void *data, size_t data_len,
switchdev_deferred_func_t *func)
{
struct switchdev_deferred_item *dfitem;
dfitem = kmalloc(sizeof(*dfitem) + data_len, GFP_ATOMIC);
if (!dfitem)
return -ENOMEM;
dfitem->dev = dev;
dfitem->func = func;
memcpy(dfitem->data, data, data_len);
dev_hold(dev);
spin_lock_bh(&deferred_lock);
list_add_tail(&dfitem->list, &deferred);
spin_unlock_bh(&deferred_lock);
schedule_work(&deferred_process_work);
return 0;
}
int switchdev_port_attr_get(struct net_device *dev, struct switchdev_attr *attr)
{
const struct switchdev_ops *ops = dev->switchdev_ops;
struct net_device *lower_dev;
struct list_head *iter;
struct switchdev_attr first = {
.id = SWITCHDEV_ATTR_ID_UNDEFINED
};
int err = -EOPNOTSUPP;
if (ops && ops->switchdev_port_attr_get)
return ops->switchdev_port_attr_get(dev, attr);
if (attr->flags & SWITCHDEV_F_NO_RECURSE)
return err;
netdev_for_each_lower_dev(dev, lower_dev, iter) {
err = switchdev_port_attr_get(lower_dev, attr);
if (err)
break;
if (first.id == SWITCHDEV_ATTR_ID_UNDEFINED)
first = *attr;
else if (memcmp(&first, attr, sizeof(*attr)))
return -ENODATA;
}
return err;
}
static int __switchdev_port_attr_set(struct net_device *dev,
const struct switchdev_attr *attr,
struct switchdev_trans *trans)
{
const struct switchdev_ops *ops = dev->switchdev_ops;
struct net_device *lower_dev;
struct list_head *iter;
int err = -EOPNOTSUPP;
if (ops && ops->switchdev_port_attr_set) {
err = ops->switchdev_port_attr_set(dev, attr, trans);
goto done;
}
if (attr->flags & SWITCHDEV_F_NO_RECURSE)
goto done;
netdev_for_each_lower_dev(dev, lower_dev, iter) {
err = __switchdev_port_attr_set(lower_dev, attr, trans);
if (err)
break;
}
done:
if (err == -EOPNOTSUPP && attr->flags & SWITCHDEV_F_SKIP_EOPNOTSUPP)
err = 0;
return err;
}
static int switchdev_port_attr_set_now(struct net_device *dev,
const struct switchdev_attr *attr)
{
struct switchdev_trans trans;
int err;
switchdev_trans_init(&trans);
trans.ph_prepare = true;
err = __switchdev_port_attr_set(dev, attr, &trans);
if (err) {
if (err != -EOPNOTSUPP)
switchdev_trans_items_destroy(&trans);
return err;
}
trans.ph_prepare = false;
err = __switchdev_port_attr_set(dev, attr, &trans);
WARN(err, "%s: Commit of attribute (id=%d) failed.\n",
dev->name, attr->id);
switchdev_trans_items_warn_destroy(dev, &trans);
return err;
}
static void switchdev_port_attr_set_deferred(struct net_device *dev,
const void *data)
{
const struct switchdev_attr *attr = data;
int err;
err = switchdev_port_attr_set_now(dev, attr);
if (err && err != -EOPNOTSUPP)
netdev_err(dev, "failed (err=%d) to set attribute (id=%d)\n",
err, attr->id);
if (attr->complete)
attr->complete(dev, err, attr->complete_priv);
}
static int switchdev_port_attr_set_defer(struct net_device *dev,
const struct switchdev_attr *attr)
{
return switchdev_deferred_enqueue(dev, attr, sizeof(*attr),
switchdev_port_attr_set_deferred);
}
int switchdev_port_attr_set(struct net_device *dev,
const struct switchdev_attr *attr)
{
if (attr->flags & SWITCHDEV_F_DEFER)
return switchdev_port_attr_set_defer(dev, attr);
ASSERT_RTNL();
return switchdev_port_attr_set_now(dev, attr);
}
static size_t switchdev_obj_size(const struct switchdev_obj *obj)
{
switch (obj->id) {
case SWITCHDEV_OBJ_ID_PORT_VLAN:
return sizeof(struct switchdev_obj_port_vlan);
case SWITCHDEV_OBJ_ID_PORT_MDB:
return sizeof(struct switchdev_obj_port_mdb);
default:
BUG();
}
return 0;
}
static int __switchdev_port_obj_add(struct net_device *dev,
const struct switchdev_obj *obj,
struct switchdev_trans *trans)
{
const struct switchdev_ops *ops = dev->switchdev_ops;
struct net_device *lower_dev;
struct list_head *iter;
int err = -EOPNOTSUPP;
if (ops && ops->switchdev_port_obj_add)
return ops->switchdev_port_obj_add(dev, obj, trans);
netdev_for_each_lower_dev(dev, lower_dev, iter) {
err = __switchdev_port_obj_add(lower_dev, obj, trans);
if (err)
break;
}
return err;
}
static int switchdev_port_obj_add_now(struct net_device *dev,
const struct switchdev_obj *obj)
{
struct switchdev_trans trans;
int err;
ASSERT_RTNL();
switchdev_trans_init(&trans);
trans.ph_prepare = true;
err = __switchdev_port_obj_add(dev, obj, &trans);
if (err) {
if (err != -EOPNOTSUPP)
switchdev_trans_items_destroy(&trans);
return err;
}
trans.ph_prepare = false;
err = __switchdev_port_obj_add(dev, obj, &trans);
WARN(err, "%s: Commit of object (id=%d) failed.\n", dev->name, obj->id);
switchdev_trans_items_warn_destroy(dev, &trans);
return err;
}
static void switchdev_port_obj_add_deferred(struct net_device *dev,
const void *data)
{
const struct switchdev_obj *obj = data;
int err;
err = switchdev_port_obj_add_now(dev, obj);
if (err && err != -EOPNOTSUPP)
netdev_err(dev, "failed (err=%d) to add object (id=%d)\n",
err, obj->id);
if (obj->complete)
obj->complete(dev, err, obj->complete_priv);
}
static int switchdev_port_obj_add_defer(struct net_device *dev,
const struct switchdev_obj *obj)
{
return switchdev_deferred_enqueue(dev, obj, switchdev_obj_size(obj),
switchdev_port_obj_add_deferred);
}
int switchdev_port_obj_add(struct net_device *dev,
const struct switchdev_obj *obj)
{
if (obj->flags & SWITCHDEV_F_DEFER)
return switchdev_port_obj_add_defer(dev, obj);
ASSERT_RTNL();
return switchdev_port_obj_add_now(dev, obj);
}
static int switchdev_port_obj_del_now(struct net_device *dev,
const struct switchdev_obj *obj)
{
const struct switchdev_ops *ops = dev->switchdev_ops;
struct net_device *lower_dev;
struct list_head *iter;
int err = -EOPNOTSUPP;
if (ops && ops->switchdev_port_obj_del)
return ops->switchdev_port_obj_del(dev, obj);
netdev_for_each_lower_dev(dev, lower_dev, iter) {
err = switchdev_port_obj_del_now(lower_dev, obj);
if (err)
break;
}
return err;
}
static void switchdev_port_obj_del_deferred(struct net_device *dev,
const void *data)
{
const struct switchdev_obj *obj = data;
int err;
err = switchdev_port_obj_del_now(dev, obj);
if (err && err != -EOPNOTSUPP)
netdev_err(dev, "failed (err=%d) to del object (id=%d)\n",
err, obj->id);
if (obj->complete)
obj->complete(dev, err, obj->complete_priv);
}
static int switchdev_port_obj_del_defer(struct net_device *dev,
const struct switchdev_obj *obj)
{
return switchdev_deferred_enqueue(dev, obj, switchdev_obj_size(obj),
switchdev_port_obj_del_deferred);
}
int switchdev_port_obj_del(struct net_device *dev,
const struct switchdev_obj *obj)
{
if (obj->flags & SWITCHDEV_F_DEFER)
return switchdev_port_obj_del_defer(dev, obj);
ASSERT_RTNL();
return switchdev_port_obj_del_now(dev, obj);
}
int register_switchdev_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&switchdev_notif_chain, nb);
}
int unregister_switchdev_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&switchdev_notif_chain, nb);
}
int call_switchdev_notifiers(unsigned long val, struct net_device *dev,
struct switchdev_notifier_info *info)
{
info->dev = dev;
return atomic_notifier_call_chain(&switchdev_notif_chain, val, info);
}
bool switchdev_port_same_parent_id(struct net_device *a,
struct net_device *b)
{
struct switchdev_attr a_attr = {
.orig_dev = a,
.id = SWITCHDEV_ATTR_ID_PORT_PARENT_ID,
};
struct switchdev_attr b_attr = {
.orig_dev = b,
.id = SWITCHDEV_ATTR_ID_PORT_PARENT_ID,
};
if (switchdev_port_attr_get(a, &a_attr) ||
switchdev_port_attr_get(b, &b_attr))
return false;
return netdev_phys_item_id_same(&a_attr.u.ppid, &b_attr.u.ppid);
}
