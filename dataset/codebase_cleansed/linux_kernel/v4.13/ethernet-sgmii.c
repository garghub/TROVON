int cvm_oct_sgmii_open(struct net_device *dev)
{
return cvm_oct_common_open(dev, cvm_oct_link_poll);
}
int cvm_oct_sgmii_init(struct net_device *dev)
{
cvm_oct_common_init(dev);
return 0;
}
