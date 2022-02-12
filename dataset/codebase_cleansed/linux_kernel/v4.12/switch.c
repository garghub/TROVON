static int dsa_switch_bridge_join(struct dsa_switch *ds,
struct dsa_notifier_bridge_info *info)
{
if (ds->index == info->sw_index && ds->ops->port_bridge_join)
return ds->ops->port_bridge_join(ds, info->port, info->br);
if (ds->index != info->sw_index && ds->ops->crosschip_bridge_join)
return ds->ops->crosschip_bridge_join(ds, info->sw_index,
info->port, info->br);
return 0;
}
static int dsa_switch_bridge_leave(struct dsa_switch *ds,
struct dsa_notifier_bridge_info *info)
{
if (ds->index == info->sw_index && ds->ops->port_bridge_leave)
ds->ops->port_bridge_leave(ds, info->port, info->br);
if (ds->index != info->sw_index && ds->ops->crosschip_bridge_leave)
ds->ops->crosschip_bridge_leave(ds, info->sw_index, info->port,
info->br);
return 0;
}
static int dsa_switch_event(struct notifier_block *nb,
unsigned long event, void *info)
{
struct dsa_switch *ds = container_of(nb, struct dsa_switch, nb);
int err;
switch (event) {
case DSA_NOTIFIER_BRIDGE_JOIN:
err = dsa_switch_bridge_join(ds, info);
break;
case DSA_NOTIFIER_BRIDGE_LEAVE:
err = dsa_switch_bridge_leave(ds, info);
break;
default:
err = -EOPNOTSUPP;
break;
}
if (err)
dev_dbg(ds->dev, "breaking chain for DSA event %lu (%d)\n",
event, err);
return notifier_from_errno(err);
}
int dsa_switch_register_notifier(struct dsa_switch *ds)
{
ds->nb.notifier_call = dsa_switch_event;
return raw_notifier_chain_register(&ds->dst->nh, &ds->nb);
}
void dsa_switch_unregister_notifier(struct dsa_switch *ds)
{
int err;
err = raw_notifier_chain_unregister(&ds->dst->nh, &ds->nb);
if (err)
dev_err(ds->dev, "failed to unregister notifier (%d)\n", err);
}
