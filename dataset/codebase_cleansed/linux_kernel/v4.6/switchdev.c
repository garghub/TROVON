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
case SWITCHDEV_OBJ_ID_IPV4_FIB:
return sizeof(struct switchdev_obj_ipv4_fib);
case SWITCHDEV_OBJ_ID_PORT_FDB:
return sizeof(struct switchdev_obj_port_fdb);
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
int switchdev_port_obj_dump(struct net_device *dev, struct switchdev_obj *obj,
switchdev_obj_dump_cb_t *cb)
{
const struct switchdev_ops *ops = dev->switchdev_ops;
struct net_device *lower_dev;
struct list_head *iter;
int err = -EOPNOTSUPP;
ASSERT_RTNL();
if (ops && ops->switchdev_port_obj_dump)
return ops->switchdev_port_obj_dump(dev, obj, cb);
netdev_for_each_lower_dev(dev, lower_dev, iter) {
err = switchdev_port_obj_dump(lower_dev, obj, cb);
break;
}
return err;
}
int register_switchdev_notifier(struct notifier_block *nb)
{
int err;
rtnl_lock();
err = raw_notifier_chain_register(&switchdev_notif_chain, nb);
rtnl_unlock();
return err;
}
int unregister_switchdev_notifier(struct notifier_block *nb)
{
int err;
rtnl_lock();
err = raw_notifier_chain_unregister(&switchdev_notif_chain, nb);
rtnl_unlock();
return err;
}
int call_switchdev_notifiers(unsigned long val, struct net_device *dev,
struct switchdev_notifier_info *info)
{
int err;
ASSERT_RTNL();
info->dev = dev;
err = raw_notifier_call_chain(&switchdev_notif_chain, val, info);
return err;
}
static int switchdev_port_vlan_dump_put(struct switchdev_vlan_dump *dump)
{
struct bridge_vlan_info vinfo;
vinfo.flags = dump->flags;
if (dump->begin == 0 && dump->end == 0) {
return 0;
} else if (dump->begin == dump->end) {
vinfo.vid = dump->begin;
if (nla_put(dump->skb, IFLA_BRIDGE_VLAN_INFO,
sizeof(vinfo), &vinfo))
return -EMSGSIZE;
} else {
vinfo.vid = dump->begin;
vinfo.flags |= BRIDGE_VLAN_INFO_RANGE_BEGIN;
if (nla_put(dump->skb, IFLA_BRIDGE_VLAN_INFO,
sizeof(vinfo), &vinfo))
return -EMSGSIZE;
vinfo.vid = dump->end;
vinfo.flags &= ~BRIDGE_VLAN_INFO_RANGE_BEGIN;
vinfo.flags |= BRIDGE_VLAN_INFO_RANGE_END;
if (nla_put(dump->skb, IFLA_BRIDGE_VLAN_INFO,
sizeof(vinfo), &vinfo))
return -EMSGSIZE;
}
return 0;
}
static int switchdev_port_vlan_dump_cb(struct switchdev_obj *obj)
{
struct switchdev_obj_port_vlan *vlan = SWITCHDEV_OBJ_PORT_VLAN(obj);
struct switchdev_vlan_dump *dump =
container_of(vlan, struct switchdev_vlan_dump, vlan);
int err = 0;
if (vlan->vid_begin > vlan->vid_end)
return -EINVAL;
if (dump->filter_mask & RTEXT_FILTER_BRVLAN) {
dump->flags = vlan->flags;
for (dump->begin = dump->end = vlan->vid_begin;
dump->begin <= vlan->vid_end;
dump->begin++, dump->end++) {
err = switchdev_port_vlan_dump_put(dump);
if (err)
return err;
}
} else if (dump->filter_mask & RTEXT_FILTER_BRVLAN_COMPRESSED) {
if (dump->begin > vlan->vid_begin &&
dump->begin >= vlan->vid_end) {
if ((dump->begin - 1) == vlan->vid_end &&
dump->flags == vlan->flags) {
dump->begin = vlan->vid_begin;
} else {
err = switchdev_port_vlan_dump_put(dump);
dump->flags = vlan->flags;
dump->begin = vlan->vid_begin;
dump->end = vlan->vid_end;
}
} else if (dump->end <= vlan->vid_begin &&
dump->end < vlan->vid_end) {
if ((dump->end + 1) == vlan->vid_begin &&
dump->flags == vlan->flags) {
dump->end = vlan->vid_end;
} else {
err = switchdev_port_vlan_dump_put(dump);
dump->flags = vlan->flags;
dump->begin = vlan->vid_begin;
dump->end = vlan->vid_end;
}
} else {
err = -EINVAL;
}
}
return err;
}
static int switchdev_port_vlan_fill(struct sk_buff *skb, struct net_device *dev,
u32 filter_mask)
{
struct switchdev_vlan_dump dump = {
.vlan.obj.orig_dev = dev,
.vlan.obj.id = SWITCHDEV_OBJ_ID_PORT_VLAN,
.skb = skb,
.filter_mask = filter_mask,
};
int err = 0;
if ((filter_mask & RTEXT_FILTER_BRVLAN) ||
(filter_mask & RTEXT_FILTER_BRVLAN_COMPRESSED)) {
err = switchdev_port_obj_dump(dev, &dump.vlan.obj,
switchdev_port_vlan_dump_cb);
if (err)
goto err_out;
if (filter_mask & RTEXT_FILTER_BRVLAN_COMPRESSED)
err = switchdev_port_vlan_dump_put(&dump);
}
err_out:
return err == -EOPNOTSUPP ? 0 : err;
}
int switchdev_port_bridge_getlink(struct sk_buff *skb, u32 pid, u32 seq,
struct net_device *dev, u32 filter_mask,
int nlflags)
{
struct switchdev_attr attr = {
.orig_dev = dev,
.id = SWITCHDEV_ATTR_ID_PORT_BRIDGE_FLAGS,
};
u16 mode = BRIDGE_MODE_UNDEF;
u32 mask = BR_LEARNING | BR_LEARNING_SYNC | BR_FLOOD;
int err;
err = switchdev_port_attr_get(dev, &attr);
if (err && err != -EOPNOTSUPP)
return err;
return ndo_dflt_bridge_getlink(skb, pid, seq, dev, mode,
attr.u.brport_flags, mask, nlflags,
filter_mask, switchdev_port_vlan_fill);
}
static int switchdev_port_br_setflag(struct net_device *dev,
struct nlattr *nlattr,
unsigned long brport_flag)
{
struct switchdev_attr attr = {
.orig_dev = dev,
.id = SWITCHDEV_ATTR_ID_PORT_BRIDGE_FLAGS,
};
u8 flag = nla_get_u8(nlattr);
int err;
err = switchdev_port_attr_get(dev, &attr);
if (err)
return err;
if (flag)
attr.u.brport_flags |= brport_flag;
else
attr.u.brport_flags &= ~brport_flag;
return switchdev_port_attr_set(dev, &attr);
}
static int switchdev_port_br_setlink_protinfo(struct net_device *dev,
struct nlattr *protinfo)
{
struct nlattr *attr;
int rem;
int err;
err = nla_validate_nested(protinfo, IFLA_BRPORT_MAX,
switchdev_port_bridge_policy);
if (err)
return err;
nla_for_each_nested(attr, protinfo, rem) {
switch (nla_type(attr)) {
case IFLA_BRPORT_LEARNING:
err = switchdev_port_br_setflag(dev, attr,
BR_LEARNING);
break;
case IFLA_BRPORT_LEARNING_SYNC:
err = switchdev_port_br_setflag(dev, attr,
BR_LEARNING_SYNC);
break;
case IFLA_BRPORT_UNICAST_FLOOD:
err = switchdev_port_br_setflag(dev, attr, BR_FLOOD);
break;
default:
err = -EOPNOTSUPP;
break;
}
if (err)
return err;
}
return 0;
}
static int switchdev_port_br_afspec(struct net_device *dev,
struct nlattr *afspec,
int (*f)(struct net_device *dev,
const struct switchdev_obj *obj))
{
struct nlattr *attr;
struct bridge_vlan_info *vinfo;
struct switchdev_obj_port_vlan vlan = {
.obj.orig_dev = dev,
.obj.id = SWITCHDEV_OBJ_ID_PORT_VLAN,
};
int rem;
int err;
nla_for_each_nested(attr, afspec, rem) {
if (nla_type(attr) != IFLA_BRIDGE_VLAN_INFO)
continue;
if (nla_len(attr) != sizeof(struct bridge_vlan_info))
return -EINVAL;
vinfo = nla_data(attr);
if (!vinfo->vid || vinfo->vid >= VLAN_VID_MASK)
return -EINVAL;
vlan.flags = vinfo->flags;
if (vinfo->flags & BRIDGE_VLAN_INFO_RANGE_BEGIN) {
if (vlan.vid_begin)
return -EINVAL;
vlan.vid_begin = vinfo->vid;
if (vlan.flags & BRIDGE_VLAN_INFO_PVID)
return -EINVAL;
} else if (vinfo->flags & BRIDGE_VLAN_INFO_RANGE_END) {
if (!vlan.vid_begin)
return -EINVAL;
vlan.vid_end = vinfo->vid;
if (vlan.vid_end <= vlan.vid_begin)
return -EINVAL;
err = f(dev, &vlan.obj);
if (err)
return err;
vlan.vid_begin = 0;
} else {
if (vlan.vid_begin)
return -EINVAL;
vlan.vid_begin = vinfo->vid;
vlan.vid_end = vinfo->vid;
err = f(dev, &vlan.obj);
if (err)
return err;
vlan.vid_begin = 0;
}
}
return 0;
}
int switchdev_port_bridge_setlink(struct net_device *dev,
struct nlmsghdr *nlh, u16 flags)
{
struct nlattr *protinfo;
struct nlattr *afspec;
int err = 0;
protinfo = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg),
IFLA_PROTINFO);
if (protinfo) {
err = switchdev_port_br_setlink_protinfo(dev, protinfo);
if (err)
return err;
}
afspec = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg),
IFLA_AF_SPEC);
if (afspec)
err = switchdev_port_br_afspec(dev, afspec,
switchdev_port_obj_add);
return err;
}
int switchdev_port_bridge_dellink(struct net_device *dev,
struct nlmsghdr *nlh, u16 flags)
{
struct nlattr *afspec;
afspec = nlmsg_find_attr(nlh, sizeof(struct ifinfomsg),
IFLA_AF_SPEC);
if (afspec)
return switchdev_port_br_afspec(dev, afspec,
switchdev_port_obj_del);
return 0;
}
int switchdev_port_fdb_add(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev, const unsigned char *addr,
u16 vid, u16 nlm_flags)
{
struct switchdev_obj_port_fdb fdb = {
.obj.orig_dev = dev,
.obj.id = SWITCHDEV_OBJ_ID_PORT_FDB,
.vid = vid,
};
ether_addr_copy(fdb.addr, addr);
return switchdev_port_obj_add(dev, &fdb.obj);
}
int switchdev_port_fdb_del(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev, const unsigned char *addr,
u16 vid)
{
struct switchdev_obj_port_fdb fdb = {
.obj.orig_dev = dev,
.obj.id = SWITCHDEV_OBJ_ID_PORT_FDB,
.vid = vid,
};
ether_addr_copy(fdb.addr, addr);
return switchdev_port_obj_del(dev, &fdb.obj);
}
static int switchdev_port_fdb_dump_cb(struct switchdev_obj *obj)
{
struct switchdev_obj_port_fdb *fdb = SWITCHDEV_OBJ_PORT_FDB(obj);
struct switchdev_fdb_dump *dump =
container_of(fdb, struct switchdev_fdb_dump, fdb);
u32 portid = NETLINK_CB(dump->cb->skb).portid;
u32 seq = dump->cb->nlh->nlmsg_seq;
struct nlmsghdr *nlh;
struct ndmsg *ndm;
if (dump->idx < dump->cb->args[0])
goto skip;
nlh = nlmsg_put(dump->skb, portid, seq, RTM_NEWNEIGH,
sizeof(*ndm), NLM_F_MULTI);
if (!nlh)
return -EMSGSIZE;
ndm = nlmsg_data(nlh);
ndm->ndm_family = AF_BRIDGE;
ndm->ndm_pad1 = 0;
ndm->ndm_pad2 = 0;
ndm->ndm_flags = NTF_SELF;
ndm->ndm_type = 0;
ndm->ndm_ifindex = dump->dev->ifindex;
ndm->ndm_state = fdb->ndm_state;
if (nla_put(dump->skb, NDA_LLADDR, ETH_ALEN, fdb->addr))
goto nla_put_failure;
if (fdb->vid && nla_put_u16(dump->skb, NDA_VLAN, fdb->vid))
goto nla_put_failure;
nlmsg_end(dump->skb, nlh);
skip:
dump->idx++;
return 0;
nla_put_failure:
nlmsg_cancel(dump->skb, nlh);
return -EMSGSIZE;
}
int switchdev_port_fdb_dump(struct sk_buff *skb, struct netlink_callback *cb,
struct net_device *dev,
struct net_device *filter_dev, int idx)
{
struct switchdev_fdb_dump dump = {
.fdb.obj.orig_dev = dev,
.fdb.obj.id = SWITCHDEV_OBJ_ID_PORT_FDB,
.dev = dev,
.skb = skb,
.cb = cb,
.idx = idx,
};
int err;
err = switchdev_port_obj_dump(dev, &dump.fdb.obj,
switchdev_port_fdb_dump_cb);
cb->args[1] = err;
return dump.idx;
}
static struct net_device *switchdev_get_lowest_dev(struct net_device *dev)
{
const struct switchdev_ops *ops = dev->switchdev_ops;
struct net_device *lower_dev;
struct net_device *port_dev;
struct list_head *iter;
if (ops && ops->switchdev_port_attr_get)
return dev;
netdev_for_each_lower_dev(dev, lower_dev, iter) {
port_dev = switchdev_get_lowest_dev(lower_dev);
if (port_dev)
return port_dev;
}
return NULL;
}
static struct net_device *switchdev_get_dev_by_nhs(struct fib_info *fi)
{
struct switchdev_attr attr = {
.id = SWITCHDEV_ATTR_ID_PORT_PARENT_ID,
};
struct switchdev_attr prev_attr;
struct net_device *dev = NULL;
int nhsel;
ASSERT_RTNL();
for (nhsel = 0; nhsel < fi->fib_nhs; nhsel++) {
const struct fib_nh *nh = &fi->fib_nh[nhsel];
if (!nh->nh_dev)
return NULL;
dev = switchdev_get_lowest_dev(nh->nh_dev);
if (!dev)
return NULL;
attr.orig_dev = dev;
if (switchdev_port_attr_get(dev, &attr))
return NULL;
if (nhsel > 0 &&
!netdev_phys_item_id_same(&prev_attr.u.ppid, &attr.u.ppid))
return NULL;
prev_attr = attr;
}
return dev;
}
int switchdev_fib_ipv4_add(u32 dst, int dst_len, struct fib_info *fi,
u8 tos, u8 type, u32 nlflags, u32 tb_id)
{
struct switchdev_obj_ipv4_fib ipv4_fib = {
.obj.id = SWITCHDEV_OBJ_ID_IPV4_FIB,
.dst = dst,
.dst_len = dst_len,
.tos = tos,
.type = type,
.nlflags = nlflags,
.tb_id = tb_id,
};
struct net_device *dev;
int err = 0;
memcpy(&ipv4_fib.fi, fi, sizeof(ipv4_fib.fi));
#ifdef CONFIG_IP_MULTIPLE_TABLES
if (fi->fib_net->ipv4.fib_has_custom_rules)
return 0;
#endif
if (fi->fib_net->ipv4.fib_offload_disabled)
return 0;
dev = switchdev_get_dev_by_nhs(fi);
if (!dev)
return 0;
ipv4_fib.obj.orig_dev = dev;
err = switchdev_port_obj_add(dev, &ipv4_fib.obj);
if (!err)
fi->fib_flags |= RTNH_F_OFFLOAD;
return err == -EOPNOTSUPP ? 0 : err;
}
int switchdev_fib_ipv4_del(u32 dst, int dst_len, struct fib_info *fi,
u8 tos, u8 type, u32 tb_id)
{
struct switchdev_obj_ipv4_fib ipv4_fib = {
.obj.id = SWITCHDEV_OBJ_ID_IPV4_FIB,
.dst = dst,
.dst_len = dst_len,
.tos = tos,
.type = type,
.nlflags = 0,
.tb_id = tb_id,
};
struct net_device *dev;
int err = 0;
memcpy(&ipv4_fib.fi, fi, sizeof(ipv4_fib.fi));
if (!(fi->fib_flags & RTNH_F_OFFLOAD))
return 0;
dev = switchdev_get_dev_by_nhs(fi);
if (!dev)
return 0;
ipv4_fib.obj.orig_dev = dev;
err = switchdev_port_obj_del(dev, &ipv4_fib.obj);
if (!err)
fi->fib_flags &= ~RTNH_F_OFFLOAD;
return err == -EOPNOTSUPP ? 0 : err;
}
void switchdev_fib_ipv4_abort(struct fib_info *fi)
{
fib_flush_external(fi->fib_net);
fi->fib_net->ipv4.fib_offload_disabled = true;
}
static bool switchdev_port_same_parent_id(struct net_device *a,
struct net_device *b)
{
struct switchdev_attr a_attr = {
.orig_dev = a,
.id = SWITCHDEV_ATTR_ID_PORT_PARENT_ID,
.flags = SWITCHDEV_F_NO_RECURSE,
};
struct switchdev_attr b_attr = {
.orig_dev = b,
.id = SWITCHDEV_ATTR_ID_PORT_PARENT_ID,
.flags = SWITCHDEV_F_NO_RECURSE,
};
if (switchdev_port_attr_get(a, &a_attr) ||
switchdev_port_attr_get(b, &b_attr))
return false;
return netdev_phys_item_id_same(&a_attr.u.ppid, &b_attr.u.ppid);
}
static u32 switchdev_port_fwd_mark_get(struct net_device *dev,
struct net_device *group_dev)
{
struct net_device *lower_dev;
struct list_head *iter;
netdev_for_each_lower_dev(group_dev, lower_dev, iter) {
if (lower_dev == dev)
continue;
if (switchdev_port_same_parent_id(dev, lower_dev))
return lower_dev->offload_fwd_mark;
return switchdev_port_fwd_mark_get(dev, lower_dev);
}
return dev->ifindex;
}
static void switchdev_port_fwd_mark_reset(struct net_device *group_dev,
u32 old_mark, u32 *reset_mark)
{
struct net_device *lower_dev;
struct list_head *iter;
netdev_for_each_lower_dev(group_dev, lower_dev, iter) {
if (lower_dev->offload_fwd_mark == old_mark) {
if (!*reset_mark)
*reset_mark = lower_dev->ifindex;
lower_dev->offload_fwd_mark = *reset_mark;
}
switchdev_port_fwd_mark_reset(lower_dev, old_mark, reset_mark);
}
}
void switchdev_port_fwd_mark_set(struct net_device *dev,
struct net_device *group_dev,
bool joining)
{
u32 mark = dev->ifindex;
u32 reset_mark = 0;
if (group_dev) {
ASSERT_RTNL();
if (joining)
mark = switchdev_port_fwd_mark_get(dev, group_dev);
else if (dev->offload_fwd_mark == mark)
switchdev_port_fwd_mark_reset(group_dev, mark,
&reset_mark);
}
dev->offload_fwd_mark = mark;
}
