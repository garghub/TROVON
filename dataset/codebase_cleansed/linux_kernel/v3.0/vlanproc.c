static int vlan_seq_open(struct inode *inode, struct file *file)
{
return seq_open_net(inode, file, &vlan_seq_ops,
sizeof(struct seq_net_private));
}
static int vlandev_seq_open(struct inode *inode, struct file *file)
{
return single_open(file, vlandev_seq_show, PDE(inode)->data);
}
void vlan_proc_cleanup(struct net *net)
{
struct vlan_net *vn = net_generic(net, vlan_net_id);
if (vn->proc_vlan_conf)
remove_proc_entry(name_conf, vn->proc_vlan_dir);
if (vn->proc_vlan_dir)
proc_net_remove(net, name_root);
}
int __net_init vlan_proc_init(struct net *net)
{
struct vlan_net *vn = net_generic(net, vlan_net_id);
vn->proc_vlan_dir = proc_net_mkdir(net, name_root, net->proc_net);
if (!vn->proc_vlan_dir)
goto err;
vn->proc_vlan_conf = proc_create(name_conf, S_IFREG|S_IRUSR|S_IWUSR,
vn->proc_vlan_dir, &vlan_fops);
if (!vn->proc_vlan_conf)
goto err;
return 0;
err:
pr_err("%s: can't create entry in proc filesystem!\n", __func__);
vlan_proc_cleanup(net);
return -ENOBUFS;
}
int vlan_proc_add_dev(struct net_device *vlandev)
{
struct vlan_dev_info *dev_info = vlan_dev_info(vlandev);
struct vlan_net *vn = net_generic(dev_net(vlandev), vlan_net_id);
dev_info->dent =
proc_create_data(vlandev->name, S_IFREG|S_IRUSR|S_IWUSR,
vn->proc_vlan_dir, &vlandev_fops, vlandev);
if (!dev_info->dent)
return -ENOBUFS;
return 0;
}
int vlan_proc_rem_dev(struct net_device *vlandev)
{
struct vlan_net *vn = net_generic(dev_net(vlandev), vlan_net_id);
if (vlan_dev_info(vlandev)->dent) {
remove_proc_entry(vlan_dev_info(vlandev)->dent->name,
vn->proc_vlan_dir);
vlan_dev_info(vlandev)->dent = NULL;
}
return 0;
}
static void *vlan_seq_start(struct seq_file *seq, loff_t *pos)
__acquires(rcu)
{
struct net_device *dev;
struct net *net = seq_file_net(seq);
loff_t i = 1;
rcu_read_lock();
if (*pos == 0)
return SEQ_START_TOKEN;
for_each_netdev_rcu(net, dev) {
if (!is_vlan_dev(dev))
continue;
if (i++ == *pos)
return dev;
}
return NULL;
}
static void *vlan_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct net_device *dev;
struct net *net = seq_file_net(seq);
++*pos;
dev = (struct net_device *)v;
if (v == SEQ_START_TOKEN)
dev = net_device_entry(&net->dev_base_head);
for_each_netdev_continue_rcu(net, dev) {
if (!is_vlan_dev(dev))
continue;
return dev;
}
return NULL;
}
static void vlan_seq_stop(struct seq_file *seq, void *v)
__releases(rcu)
{
rcu_read_unlock();
}
static int vlan_seq_show(struct seq_file *seq, void *v)
{
struct net *net = seq_file_net(seq);
struct vlan_net *vn = net_generic(net, vlan_net_id);
if (v == SEQ_START_TOKEN) {
const char *nmtype = NULL;
seq_puts(seq, "VLAN Dev name | VLAN ID\n");
if (vn->name_type < ARRAY_SIZE(vlan_name_type_str))
nmtype = vlan_name_type_str[vn->name_type];
seq_printf(seq, "Name-Type: %s\n",
nmtype ? nmtype : "UNKNOWN");
} else {
const struct net_device *vlandev = v;
const struct vlan_dev_info *dev_info = vlan_dev_info(vlandev);
seq_printf(seq, "%-15s| %d | %s\n", vlandev->name,
dev_info->vlan_id, dev_info->real_dev->name);
}
return 0;
}
static int vlandev_seq_show(struct seq_file *seq, void *offset)
{
struct net_device *vlandev = (struct net_device *) seq->private;
const struct vlan_dev_info *dev_info = vlan_dev_info(vlandev);
struct rtnl_link_stats64 temp;
const struct rtnl_link_stats64 *stats;
static const char fmt64[] = "%30s %12llu\n";
int i;
if (!is_vlan_dev(vlandev))
return 0;
stats = dev_get_stats(vlandev, &temp);
seq_printf(seq,
"%s VID: %d REORDER_HDR: %i dev->priv_flags: %hx\n",
vlandev->name, dev_info->vlan_id,
(int)(dev_info->flags & 1), vlandev->priv_flags);
seq_printf(seq, fmt64, "total frames received", stats->rx_packets);
seq_printf(seq, fmt64, "total bytes received", stats->rx_bytes);
seq_printf(seq, fmt64, "Broadcast/Multicast Rcvd", stats->multicast);
seq_puts(seq, "\n");
seq_printf(seq, fmt64, "total frames transmitted", stats->tx_packets);
seq_printf(seq, fmt64, "total bytes transmitted", stats->tx_bytes);
seq_printf(seq, "Device: %s", dev_info->real_dev->name);
seq_printf(seq, "\nINGRESS priority mappings: "
"0:%u 1:%u 2:%u 3:%u 4:%u 5:%u 6:%u 7:%u\n",
dev_info->ingress_priority_map[0],
dev_info->ingress_priority_map[1],
dev_info->ingress_priority_map[2],
dev_info->ingress_priority_map[3],
dev_info->ingress_priority_map[4],
dev_info->ingress_priority_map[5],
dev_info->ingress_priority_map[6],
dev_info->ingress_priority_map[7]);
seq_printf(seq, " EGRESS priority mappings: ");
for (i = 0; i < 16; i++) {
const struct vlan_priority_tci_mapping *mp
= dev_info->egress_priority_map[i];
while (mp) {
seq_printf(seq, "%u:%hu ",
mp->priority, ((mp->vlan_qos >> 13) & 0x7));
mp = mp->next;
}
}
seq_puts(seq, "\n");
return 0;
}
