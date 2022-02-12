static void __vlan_add_pvid(struct net_port_vlans *v, u16 vid)
{
if (v->pvid == vid)
return;
smp_wmb();
v->pvid = vid;
}
static void __vlan_delete_pvid(struct net_port_vlans *v, u16 vid)
{
if (v->pvid != vid)
return;
smp_wmb();
v->pvid = 0;
}
static void __vlan_add_flags(struct net_port_vlans *v, u16 vid, u16 flags)
{
if (flags & BRIDGE_VLAN_INFO_PVID)
__vlan_add_pvid(v, vid);
if (flags & BRIDGE_VLAN_INFO_UNTAGGED)
set_bit(vid, v->untagged_bitmap);
}
static int __vlan_add(struct net_port_vlans *v, u16 vid, u16 flags)
{
struct net_bridge_port *p = NULL;
struct net_bridge *br;
struct net_device *dev;
int err;
if (test_bit(vid, v->vlan_bitmap)) {
__vlan_add_flags(v, vid, flags);
return 0;
}
if (v->port_idx) {
p = v->parent.port;
br = p->br;
dev = p->dev;
} else {
br = v->parent.br;
dev = br->dev;
}
if (p) {
err = vlan_vid_add(dev, htons(ETH_P_8021Q), vid);
if (err)
return err;
}
err = br_fdb_insert(br, p, dev->dev_addr, vid);
if (err) {
br_err(br, "failed insert local address into bridge "
"forwarding table\n");
goto out_filt;
}
set_bit(vid, v->vlan_bitmap);
v->num_vlans++;
__vlan_add_flags(v, vid, flags);
return 0;
out_filt:
if (p)
vlan_vid_del(dev, htons(ETH_P_8021Q), vid);
return err;
}
static int __vlan_del(struct net_port_vlans *v, u16 vid)
{
if (!test_bit(vid, v->vlan_bitmap))
return -EINVAL;
__vlan_delete_pvid(v, vid);
clear_bit(vid, v->untagged_bitmap);
if (v->port_idx)
vlan_vid_del(v->parent.port->dev, htons(ETH_P_8021Q), vid);
clear_bit(vid, v->vlan_bitmap);
v->num_vlans--;
if (bitmap_empty(v->vlan_bitmap, VLAN_N_VID)) {
if (v->port_idx)
RCU_INIT_POINTER(v->parent.port->vlan_info, NULL);
else
RCU_INIT_POINTER(v->parent.br->vlan_info, NULL);
kfree_rcu(v, rcu);
}
return 0;
}
static void __vlan_flush(struct net_port_vlans *v)
{
smp_wmb();
v->pvid = 0;
bitmap_zero(v->vlan_bitmap, VLAN_N_VID);
if (v->port_idx)
RCU_INIT_POINTER(v->parent.port->vlan_info, NULL);
else
RCU_INIT_POINTER(v->parent.br->vlan_info, NULL);
kfree_rcu(v, rcu);
}
struct sk_buff *br_handle_vlan(struct net_bridge *br,
const struct net_port_vlans *pv,
struct sk_buff *skb)
{
u16 vid;
if (!br->vlan_enabled)
goto out;
if (!pv) {
if ((br->dev->flags & IFF_PROMISC) && skb->dev == br->dev) {
goto out;
} else {
kfree_skb(skb);
return NULL;
}
}
br_vlan_get_tag(skb, &vid);
if (test_bit(vid, pv->untagged_bitmap))
skb->vlan_tci = 0;
out:
return skb;
}
bool br_allowed_ingress(struct net_bridge *br, struct net_port_vlans *v,
struct sk_buff *skb, u16 *vid)
{
int err;
if (!br->vlan_enabled)
return true;
if (!v)
goto drop;
if (unlikely(!vlan_tx_tag_present(skb) &&
(skb->protocol == htons(ETH_P_8021Q) ||
skb->protocol == htons(ETH_P_8021AD)))) {
skb = vlan_untag(skb);
if (unlikely(!skb))
return false;
}
err = br_vlan_get_tag(skb, vid);
if (!*vid) {
u16 pvid = br_get_pvid(v);
if (pvid == VLAN_N_VID)
goto drop;
*vid = pvid;
if (likely(err))
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), pvid);
else
skb->vlan_tci |= pvid;
return true;
}
if (test_bit(*vid, v->vlan_bitmap))
return true;
drop:
kfree_skb(skb);
return false;
}
bool br_allowed_egress(struct net_bridge *br,
const struct net_port_vlans *v,
const struct sk_buff *skb)
{
u16 vid;
if (!br->vlan_enabled)
return true;
if (!v)
return false;
br_vlan_get_tag(skb, &vid);
if (test_bit(vid, v->vlan_bitmap))
return true;
return false;
}
bool br_should_learn(struct net_bridge_port *p, struct sk_buff *skb, u16 *vid)
{
struct net_bridge *br = p->br;
struct net_port_vlans *v;
if (!br->vlan_enabled)
return true;
v = rcu_dereference(p->vlan_info);
if (!v)
return false;
br_vlan_get_tag(skb, vid);
if (!*vid) {
*vid = br_get_pvid(v);
if (*vid == VLAN_N_VID)
return false;
return true;
}
if (test_bit(*vid, v->vlan_bitmap))
return true;
return false;
}
int br_vlan_add(struct net_bridge *br, u16 vid, u16 flags)
{
struct net_port_vlans *pv = NULL;
int err;
ASSERT_RTNL();
pv = rtnl_dereference(br->vlan_info);
if (pv)
return __vlan_add(pv, vid, flags);
pv = kzalloc(sizeof(*pv), GFP_KERNEL);
if (!pv)
return -ENOMEM;
pv->parent.br = br;
err = __vlan_add(pv, vid, flags);
if (err)
goto out;
rcu_assign_pointer(br->vlan_info, pv);
return 0;
out:
kfree(pv);
return err;
}
int br_vlan_delete(struct net_bridge *br, u16 vid)
{
struct net_port_vlans *pv;
ASSERT_RTNL();
pv = rtnl_dereference(br->vlan_info);
if (!pv)
return -EINVAL;
br_fdb_find_delete_local(br, NULL, br->dev->dev_addr, vid);
__vlan_del(pv, vid);
return 0;
}
void br_vlan_flush(struct net_bridge *br)
{
struct net_port_vlans *pv;
ASSERT_RTNL();
pv = rtnl_dereference(br->vlan_info);
if (!pv)
return;
__vlan_flush(pv);
}
bool br_vlan_find(struct net_bridge *br, u16 vid)
{
struct net_port_vlans *pv;
bool found = false;
rcu_read_lock();
pv = rcu_dereference(br->vlan_info);
if (!pv)
goto out;
if (test_bit(vid, pv->vlan_bitmap))
found = true;
out:
rcu_read_unlock();
return found;
}
int br_vlan_filter_toggle(struct net_bridge *br, unsigned long val)
{
if (!rtnl_trylock())
return restart_syscall();
if (br->vlan_enabled == val)
goto unlock;
br->vlan_enabled = val;
unlock:
rtnl_unlock();
return 0;
}
int nbp_vlan_add(struct net_bridge_port *port, u16 vid, u16 flags)
{
struct net_port_vlans *pv = NULL;
int err;
ASSERT_RTNL();
pv = rtnl_dereference(port->vlan_info);
if (pv)
return __vlan_add(pv, vid, flags);
pv = kzalloc(sizeof(*pv), GFP_KERNEL);
if (!pv) {
err = -ENOMEM;
goto clean_up;
}
pv->port_idx = port->port_no;
pv->parent.port = port;
err = __vlan_add(pv, vid, flags);
if (err)
goto clean_up;
rcu_assign_pointer(port->vlan_info, pv);
return 0;
clean_up:
kfree(pv);
return err;
}
int nbp_vlan_delete(struct net_bridge_port *port, u16 vid)
{
struct net_port_vlans *pv;
ASSERT_RTNL();
pv = rtnl_dereference(port->vlan_info);
if (!pv)
return -EINVAL;
br_fdb_find_delete_local(port->br, port, port->dev->dev_addr, vid);
return __vlan_del(pv, vid);
}
void nbp_vlan_flush(struct net_bridge_port *port)
{
struct net_port_vlans *pv;
u16 vid;
ASSERT_RTNL();
pv = rtnl_dereference(port->vlan_info);
if (!pv)
return;
for_each_set_bit(vid, pv->vlan_bitmap, VLAN_N_VID)
vlan_vid_del(port->dev, htons(ETH_P_8021Q), vid);
__vlan_flush(pv);
}
bool nbp_vlan_find(struct net_bridge_port *port, u16 vid)
{
struct net_port_vlans *pv;
bool found = false;
rcu_read_lock();
pv = rcu_dereference(port->vlan_info);
if (!pv)
goto out;
if (test_bit(vid, pv->vlan_bitmap))
found = true;
out:
rcu_read_unlock();
return found;
}
