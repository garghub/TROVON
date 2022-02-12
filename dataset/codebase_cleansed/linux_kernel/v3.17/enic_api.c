int enic_api_devcmd_proxy_by_index(struct net_device *netdev, int vf,
enum vnic_devcmd_cmd cmd, u64 *a0, u64 *a1, int wait)
{
int err;
struct enic *enic = netdev_priv(netdev);
struct vnic_dev *vdev = enic->vdev;
spin_lock(&enic->enic_api_lock);
spin_lock_bh(&enic->devcmd_lock);
vnic_dev_cmd_proxy_by_index_start(vdev, vf);
err = vnic_dev_cmd(vdev, cmd, a0, a1, wait);
vnic_dev_cmd_proxy_end(vdev);
spin_unlock_bh(&enic->devcmd_lock);
spin_unlock(&enic->enic_api_lock);
return err;
}
