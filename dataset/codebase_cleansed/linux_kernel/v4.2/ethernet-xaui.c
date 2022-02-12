int cvm_oct_xaui_open(struct net_device *dev)
{
return cvm_oct_common_open(dev, cvm_oct_link_poll, true);
}
int cvm_oct_xaui_init(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvm_oct_common_init(dev);
if (!octeon_is_simulation() && priv->phydev == NULL)
priv->poll = cvm_oct_link_poll;
return 0;
}
