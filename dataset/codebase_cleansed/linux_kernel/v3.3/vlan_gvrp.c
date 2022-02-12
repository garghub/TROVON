int vlan_gvrp_request_join(const struct net_device *dev)
{
const struct vlan_dev_priv *vlan = vlan_dev_priv(dev);
__be16 vlan_id = htons(vlan->vlan_id);
return garp_request_join(vlan->real_dev, &vlan_gvrp_app,
&vlan_id, sizeof(vlan_id), GVRP_ATTR_VID);
}
void vlan_gvrp_request_leave(const struct net_device *dev)
{
const struct vlan_dev_priv *vlan = vlan_dev_priv(dev);
__be16 vlan_id = htons(vlan->vlan_id);
garp_request_leave(vlan->real_dev, &vlan_gvrp_app,
&vlan_id, sizeof(vlan_id), GVRP_ATTR_VID);
}
int vlan_gvrp_init_applicant(struct net_device *dev)
{
return garp_init_applicant(dev, &vlan_gvrp_app);
}
void vlan_gvrp_uninit_applicant(struct net_device *dev)
{
garp_uninit_applicant(dev, &vlan_gvrp_app);
}
int __init vlan_gvrp_init(void)
{
return garp_register_application(&vlan_gvrp_app);
}
void vlan_gvrp_uninit(void)
{
garp_unregister_application(&vlan_gvrp_app);
}
