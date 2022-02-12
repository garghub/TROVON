int vlan_mvrp_request_join(const struct net_device *dev)
{
const struct vlan_dev_priv *vlan = vlan_dev_priv(dev);
__be16 vlan_id = htons(vlan->vlan_id);
return mrp_request_join(vlan->real_dev, &vlan_mrp_app,
&vlan_id, sizeof(vlan_id), MVRP_ATTR_VID);
}
void vlan_mvrp_request_leave(const struct net_device *dev)
{
const struct vlan_dev_priv *vlan = vlan_dev_priv(dev);
__be16 vlan_id = htons(vlan->vlan_id);
mrp_request_leave(vlan->real_dev, &vlan_mrp_app,
&vlan_id, sizeof(vlan_id), MVRP_ATTR_VID);
}
int vlan_mvrp_init_applicant(struct net_device *dev)
{
return mrp_init_applicant(dev, &vlan_mrp_app);
}
void vlan_mvrp_uninit_applicant(struct net_device *dev)
{
mrp_uninit_applicant(dev, &vlan_mrp_app);
}
int __init vlan_mvrp_init(void)
{
return mrp_register_application(&vlan_mrp_app);
}
void vlan_mvrp_uninit(void)
{
mrp_unregister_application(&vlan_mrp_app);
}
