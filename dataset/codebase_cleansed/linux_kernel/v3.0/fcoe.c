static int fcoe_interface_setup(struct fcoe_interface *fcoe,
struct net_device *netdev)
{
struct fcoe_ctlr *fip = &fcoe->ctlr;
struct netdev_hw_addr *ha;
struct net_device *real_dev;
u8 flogi_maddr[ETH_ALEN];
const struct net_device_ops *ops;
fcoe->netdev = netdev;
ops = netdev->netdev_ops;
if (ops->ndo_fcoe_enable) {
if (ops->ndo_fcoe_enable(netdev))
FCOE_NETDEV_DBG(netdev, "Failed to enable FCoE"
" specific feature for LLD.\n");
}
if (netdev->priv_flags & IFF_BONDING && netdev->flags & IFF_MASTER) {
FCOE_NETDEV_DBG(netdev, "Bonded interfaces not supported\n");
return -EOPNOTSUPP;
}
real_dev = (netdev->priv_flags & IFF_802_1Q_VLAN) ?
vlan_dev_real_dev(netdev) : netdev;
rcu_read_lock();
for_each_dev_addr(real_dev, ha) {
if ((ha->type == NETDEV_HW_ADDR_T_SAN) &&
(is_valid_ether_addr(ha->addr))) {
memcpy(fip->ctl_src_addr, ha->addr, ETH_ALEN);
fip->spma = 1;
break;
}
}
rcu_read_unlock();
if (!fip->spma)
memcpy(fip->ctl_src_addr, netdev->dev_addr, netdev->addr_len);
memcpy(flogi_maddr, (u8[6]) FC_FCOE_FLOGI_MAC, ETH_ALEN);
dev_uc_add(netdev, flogi_maddr);
if (fip->spma)
dev_uc_add(netdev, fip->ctl_src_addr);
if (fip->mode == FIP_MODE_VN2VN) {
dev_mc_add(netdev, FIP_ALL_VN2VN_MACS);
dev_mc_add(netdev, FIP_ALL_P2P_MACS);
} else
dev_mc_add(netdev, FIP_ALL_ENODE_MACS);
fcoe->fcoe_packet_type.func = fcoe_rcv;
fcoe->fcoe_packet_type.type = __constant_htons(ETH_P_FCOE);
fcoe->fcoe_packet_type.dev = netdev;
dev_add_pack(&fcoe->fcoe_packet_type);
fcoe->fip_packet_type.func = fcoe_fip_recv;
fcoe->fip_packet_type.type = htons(ETH_P_FIP);
fcoe->fip_packet_type.dev = netdev;
dev_add_pack(&fcoe->fip_packet_type);
return 0;
}
static struct fcoe_interface *fcoe_interface_create(struct net_device *netdev,
enum fip_state fip_mode)
{
struct fcoe_interface *fcoe;
int err;
if (!try_module_get(THIS_MODULE)) {
FCOE_NETDEV_DBG(netdev,
"Could not get a reference to the module\n");
fcoe = ERR_PTR(-EBUSY);
goto out;
}
fcoe = kzalloc(sizeof(*fcoe), GFP_KERNEL);
if (!fcoe) {
FCOE_NETDEV_DBG(netdev, "Could not allocate fcoe structure\n");
fcoe = ERR_PTR(-ENOMEM);
goto out_nomod;
}
dev_hold(netdev);
kref_init(&fcoe->kref);
fcoe_ctlr_init(&fcoe->ctlr, fip_mode);
fcoe->ctlr.send = fcoe_fip_send;
fcoe->ctlr.update_mac = fcoe_update_src_mac;
fcoe->ctlr.get_src_addr = fcoe_get_src_mac;
err = fcoe_interface_setup(fcoe, netdev);
if (err) {
fcoe_ctlr_destroy(&fcoe->ctlr);
kfree(fcoe);
dev_put(netdev);
fcoe = ERR_PTR(err);
goto out_nomod;
}
goto out;
out_nomod:
module_put(THIS_MODULE);
out:
return fcoe;
}
static void fcoe_interface_release(struct kref *kref)
{
struct fcoe_interface *fcoe;
struct net_device *netdev;
fcoe = container_of(kref, struct fcoe_interface, kref);
netdev = fcoe->netdev;
fcoe_ctlr_destroy(&fcoe->ctlr);
kfree(fcoe);
dev_put(netdev);
module_put(THIS_MODULE);
}
static inline void fcoe_interface_get(struct fcoe_interface *fcoe)
{
kref_get(&fcoe->kref);
}
static inline void fcoe_interface_put(struct fcoe_interface *fcoe)
{
kref_put(&fcoe->kref, fcoe_interface_release);
}
void fcoe_interface_cleanup(struct fcoe_interface *fcoe)
{
struct net_device *netdev = fcoe->netdev;
struct fcoe_ctlr *fip = &fcoe->ctlr;
u8 flogi_maddr[ETH_ALEN];
const struct net_device_ops *ops;
struct fcoe_port *port = lport_priv(fcoe->ctlr.lp);
FCOE_NETDEV_DBG(netdev, "Destroying interface\n");
fc_fabric_logoff(fcoe->ctlr.lp);
fc_lport_destroy(fcoe->ctlr.lp);
del_timer_sync(&port->timer);
fcoe_clean_pending_queue(fcoe->ctlr.lp);
__dev_remove_pack(&fcoe->fcoe_packet_type);
__dev_remove_pack(&fcoe->fip_packet_type);
synchronize_net();
memcpy(flogi_maddr, (u8[6]) FC_FCOE_FLOGI_MAC, ETH_ALEN);
dev_uc_del(netdev, flogi_maddr);
if (fip->spma)
dev_uc_del(netdev, fip->ctl_src_addr);
if (fip->mode == FIP_MODE_VN2VN) {
dev_mc_del(netdev, FIP_ALL_VN2VN_MACS);
dev_mc_del(netdev, FIP_ALL_P2P_MACS);
} else
dev_mc_del(netdev, FIP_ALL_ENODE_MACS);
if (!is_zero_ether_addr(port->data_src_addr))
dev_uc_del(netdev, port->data_src_addr);
ops = netdev->netdev_ops;
if (ops->ndo_fcoe_disable) {
if (ops->ndo_fcoe_disable(netdev))
FCOE_NETDEV_DBG(netdev, "Failed to disable FCoE"
" specific feature for LLD.\n");
}
fcoe_interface_put(fcoe);
}
static int fcoe_fip_recv(struct sk_buff *skb, struct net_device *netdev,
struct packet_type *ptype,
struct net_device *orig_dev)
{
struct fcoe_interface *fcoe;
fcoe = container_of(ptype, struct fcoe_interface, fip_packet_type);
fcoe_ctlr_recv(&fcoe->ctlr, skb);
return 0;
}
static void fcoe_fip_send(struct fcoe_ctlr *fip, struct sk_buff *skb)
{
skb->dev = fcoe_from_ctlr(fip)->netdev;
dev_queue_xmit(skb);
}
static void fcoe_update_src_mac(struct fc_lport *lport, u8 *addr)
{
struct fcoe_port *port = lport_priv(lport);
struct fcoe_interface *fcoe = port->priv;
rtnl_lock();
if (!is_zero_ether_addr(port->data_src_addr))
dev_uc_del(fcoe->netdev, port->data_src_addr);
if (!is_zero_ether_addr(addr))
dev_uc_add(fcoe->netdev, addr);
memcpy(port->data_src_addr, addr, ETH_ALEN);
rtnl_unlock();
}
static u8 *fcoe_get_src_mac(struct fc_lport *lport)
{
struct fcoe_port *port = lport_priv(lport);
return port->data_src_addr;
}
static int fcoe_lport_config(struct fc_lport *lport)
{
lport->link_up = 0;
lport->qfull = 0;
lport->max_retry_count = 3;
lport->max_rport_retry_count = 3;
lport->e_d_tov = 2 * 1000;
lport->r_a_tov = 2 * 2 * 1000;
lport->service_params = (FCP_SPPF_INIT_FCN | FCP_SPPF_RD_XRDY_DIS |
FCP_SPPF_RETRY | FCP_SPPF_CONF_COMPL);
lport->does_npiv = 1;
fc_lport_init_stats(lport);
fc_lport_config(lport);
lport->crc_offload = 0;
lport->seq_offload = 0;
lport->lro_enabled = 0;
lport->lro_xid = 0;
lport->lso_max = 0;
return 0;
}
static int fcoe_get_wwn(struct net_device *netdev, u64 *wwn, int type)
{
const struct net_device_ops *ops = netdev->netdev_ops;
if (ops->ndo_fcoe_get_wwn)
return ops->ndo_fcoe_get_wwn(netdev, wwn, type);
return -EINVAL;
}
static void fcoe_netdev_features_change(struct fc_lport *lport,
struct net_device *netdev)
{
mutex_lock(&lport->lp_mutex);
if (netdev->features & NETIF_F_SG)
lport->sg_supp = 1;
else
lport->sg_supp = 0;
if (netdev->features & NETIF_F_FCOE_CRC) {
lport->crc_offload = 1;
FCOE_NETDEV_DBG(netdev, "Supports FCCRC offload\n");
} else {
lport->crc_offload = 0;
}
if (netdev->features & NETIF_F_FSO) {
lport->seq_offload = 1;
lport->lso_max = netdev->gso_max_size;
FCOE_NETDEV_DBG(netdev, "Supports LSO for max len 0x%x\n",
lport->lso_max);
} else {
lport->seq_offload = 0;
lport->lso_max = 0;
}
if (netdev->fcoe_ddp_xid) {
lport->lro_enabled = 1;
lport->lro_xid = netdev->fcoe_ddp_xid;
FCOE_NETDEV_DBG(netdev, "Supports LRO for max xid 0x%x\n",
lport->lro_xid);
} else {
lport->lro_enabled = 0;
lport->lro_xid = 0;
}
mutex_unlock(&lport->lp_mutex);
}
static int fcoe_netdev_config(struct fc_lport *lport, struct net_device *netdev)
{
u32 mfs;
u64 wwnn, wwpn;
struct fcoe_interface *fcoe;
struct fcoe_port *port;
port = lport_priv(lport);
fcoe = port->priv;
mfs = netdev->mtu;
if (netdev->features & NETIF_F_FCOE_MTU) {
mfs = FCOE_MTU;
FCOE_NETDEV_DBG(netdev, "Supports FCOE_MTU of %d bytes\n", mfs);
}
mfs -= (sizeof(struct fcoe_hdr) + sizeof(struct fcoe_crc_eof));
if (fc_set_mfs(lport, mfs))
return -EINVAL;
fcoe_netdev_features_change(lport, netdev);
skb_queue_head_init(&port->fcoe_pending_queue);
port->fcoe_pending_queue_active = 0;
setup_timer(&port->timer, fcoe_queue_timer, (unsigned long)lport);
fcoe_link_speed_update(lport);
if (!lport->vport) {
if (fcoe_get_wwn(netdev, &wwnn, NETDEV_FCOE_WWNN))
wwnn = fcoe_wwn_from_mac(fcoe->ctlr.ctl_src_addr, 1, 0);
fc_set_wwnn(lport, wwnn);
if (fcoe_get_wwn(netdev, &wwpn, NETDEV_FCOE_WWPN))
wwpn = fcoe_wwn_from_mac(fcoe->ctlr.ctl_src_addr,
2, 0);
fc_set_wwpn(lport, wwpn);
}
return 0;
}
static int fcoe_shost_config(struct fc_lport *lport, struct device *dev)
{
int rc = 0;
lport->host->max_lun = FCOE_MAX_LUN;
lport->host->max_id = FCOE_MAX_FCP_TARGET;
lport->host->max_channel = 0;
lport->host->max_cmd_len = FCOE_MAX_CMD_LEN;
if (lport->vport)
lport->host->transportt = fcoe_vport_scsi_transport;
else
lport->host->transportt = fcoe_nport_scsi_transport;
rc = scsi_add_host(lport->host, dev);
if (rc) {
FCOE_NETDEV_DBG(fcoe_netdev(lport), "fcoe_shost_config: "
"error on scsi_add_host\n");
return rc;
}
if (!lport->vport)
fc_host_max_npiv_vports(lport->host) = USHRT_MAX;
snprintf(fc_host_symbolic_name(lport->host), FC_SYMBOLIC_NAME_SIZE,
"%s v%s over %s", FCOE_NAME, FCOE_VERSION,
fcoe_netdev(lport)->name);
return 0;
}
bool fcoe_oem_match(struct fc_frame *fp)
{
return fc_fcp_is_read(fr_fsp(fp)) &&
(fr_fsp(fp)->data_len > fcoe_ddp_min);
}
static inline int fcoe_em_config(struct fc_lport *lport)
{
struct fcoe_port *port = lport_priv(lport);
struct fcoe_interface *fcoe = port->priv;
struct fcoe_interface *oldfcoe = NULL;
struct net_device *old_real_dev, *cur_real_dev;
u16 min_xid = FCOE_MIN_XID;
u16 max_xid = FCOE_MAX_XID;
if (!lport->lro_enabled || !lport->lro_xid ||
(lport->lro_xid >= max_xid)) {
lport->lro_xid = 0;
goto skip_oem;
}
if (fcoe->netdev->priv_flags & IFF_802_1Q_VLAN)
cur_real_dev = vlan_dev_real_dev(fcoe->netdev);
else
cur_real_dev = fcoe->netdev;
list_for_each_entry(oldfcoe, &fcoe_hostlist, list) {
if (oldfcoe->netdev->priv_flags & IFF_802_1Q_VLAN)
old_real_dev = vlan_dev_real_dev(oldfcoe->netdev);
else
old_real_dev = oldfcoe->netdev;
if (cur_real_dev == old_real_dev) {
fcoe->oem = oldfcoe->oem;
break;
}
}
if (fcoe->oem) {
if (!fc_exch_mgr_add(lport, fcoe->oem, fcoe_oem_match)) {
printk(KERN_ERR "fcoe_em_config: failed to add "
"offload em:%p on interface:%s\n",
fcoe->oem, fcoe->netdev->name);
return -ENOMEM;
}
} else {
fcoe->oem = fc_exch_mgr_alloc(lport, FC_CLASS_3,
FCOE_MIN_XID, lport->lro_xid,
fcoe_oem_match);
if (!fcoe->oem) {
printk(KERN_ERR "fcoe_em_config: failed to allocate "
"em for offload exches on interface:%s\n",
fcoe->netdev->name);
return -ENOMEM;
}
}
min_xid += lport->lro_xid + 1;
skip_oem:
if (!fc_exch_mgr_alloc(lport, FC_CLASS_3, min_xid, max_xid, NULL)) {
printk(KERN_ERR "fcoe_em_config: failed to "
"allocate em on interface %s\n", fcoe->netdev->name);
return -ENOMEM;
}
return 0;
}
static void fcoe_if_destroy(struct fc_lport *lport)
{
fcoe_percpu_clean(lport);
fc_remove_host(lport->host);
scsi_remove_host(lport->host);
fc_fcp_destroy(lport);
fc_exch_mgr_free(lport);
fc_lport_free_stats(lport);
scsi_host_put(lport->host);
}
static int fcoe_ddp_setup(struct fc_lport *lport, u16 xid,
struct scatterlist *sgl, unsigned int sgc)
{
struct net_device *netdev = fcoe_netdev(lport);
if (netdev->netdev_ops->ndo_fcoe_ddp_setup)
return netdev->netdev_ops->ndo_fcoe_ddp_setup(netdev,
xid, sgl,
sgc);
return 0;
}
static int fcoe_ddp_done(struct fc_lport *lport, u16 xid)
{
struct net_device *netdev = fcoe_netdev(lport);
if (netdev->netdev_ops->ndo_fcoe_ddp_done)
return netdev->netdev_ops->ndo_fcoe_ddp_done(netdev, xid);
return 0;
}
static struct fc_lport *fcoe_if_create(struct fcoe_interface *fcoe,
struct device *parent, int npiv)
{
struct net_device *netdev = fcoe->netdev;
struct fc_lport *lport, *n_port;
struct fcoe_port *port;
struct Scsi_Host *shost;
int rc;
struct fc_vport *vport = dev_to_vport(parent);
FCOE_NETDEV_DBG(netdev, "Create Interface\n");
if (!npiv)
lport = libfc_host_alloc(&fcoe_shost_template, sizeof(*port));
else
lport = libfc_vport_create(vport, sizeof(*port));
if (!lport) {
FCOE_NETDEV_DBG(netdev, "Could not allocate host structure\n");
rc = -ENOMEM;
goto out;
}
port = lport_priv(lport);
port->lport = lport;
port->priv = fcoe;
port->max_queue_depth = FCOE_MAX_QUEUE_DEPTH;
port->min_queue_depth = FCOE_MIN_QUEUE_DEPTH;
INIT_WORK(&port->destroy_work, fcoe_destroy_work);
rc = fcoe_lport_config(lport);
if (rc) {
FCOE_NETDEV_DBG(netdev, "Could not configure lport for the "
"interface\n");
goto out_host_put;
}
if (npiv) {
FCOE_NETDEV_DBG(netdev, "Setting vport names, "
"%16.16llx %16.16llx\n",
vport->node_name, vport->port_name);
fc_set_wwnn(lport, vport->node_name);
fc_set_wwpn(lport, vport->port_name);
}
rc = fcoe_netdev_config(lport, netdev);
if (rc) {
FCOE_NETDEV_DBG(netdev, "Could not configure netdev for the "
"interface\n");
goto out_lp_destroy;
}
rc = fcoe_shost_config(lport, parent);
if (rc) {
FCOE_NETDEV_DBG(netdev, "Could not configure shost for the "
"interface\n");
goto out_lp_destroy;
}
rc = fcoe_libfc_config(lport, &fcoe->ctlr, &fcoe_libfc_fcn_templ, 1);
if (rc) {
FCOE_NETDEV_DBG(netdev, "Could not configure libfc for the "
"interface\n");
goto out_lp_destroy;
}
if (!npiv)
rc = fcoe_em_config(lport);
else {
shost = vport_to_shost(vport);
n_port = shost_priv(shost);
rc = fc_exch_mgr_list_clone(n_port, lport);
}
if (rc) {
FCOE_NETDEV_DBG(netdev, "Could not configure the EM\n");
goto out_lp_destroy;
}
fcoe_interface_get(fcoe);
return lport;
out_lp_destroy:
fc_exch_mgr_free(lport);
out_host_put:
scsi_host_put(lport->host);
out:
return ERR_PTR(rc);
}
static int __init fcoe_if_init(void)
{
fcoe_nport_scsi_transport =
fc_attach_transport(&fcoe_nport_fc_functions);
fcoe_vport_scsi_transport =
fc_attach_transport(&fcoe_vport_fc_functions);
if (!fcoe_nport_scsi_transport) {
printk(KERN_ERR "fcoe: Failed to attach to the FC transport\n");
return -ENODEV;
}
return 0;
}
int __exit fcoe_if_exit(void)
{
fc_release_transport(fcoe_nport_scsi_transport);
fc_release_transport(fcoe_vport_scsi_transport);
fcoe_nport_scsi_transport = NULL;
fcoe_vport_scsi_transport = NULL;
return 0;
}
static void fcoe_percpu_thread_create(unsigned int cpu)
{
struct fcoe_percpu_s *p;
struct task_struct *thread;
p = &per_cpu(fcoe_percpu, cpu);
thread = kthread_create(fcoe_percpu_receive_thread,
(void *)p, "fcoethread/%d", cpu);
if (likely(!IS_ERR(thread))) {
kthread_bind(thread, cpu);
wake_up_process(thread);
spin_lock_bh(&p->fcoe_rx_list.lock);
p->thread = thread;
spin_unlock_bh(&p->fcoe_rx_list.lock);
}
}
static void fcoe_percpu_thread_destroy(unsigned int cpu)
{
struct fcoe_percpu_s *p;
struct task_struct *thread;
struct page *crc_eof;
struct sk_buff *skb;
#ifdef CONFIG_SMP
struct fcoe_percpu_s *p0;
unsigned targ_cpu = get_cpu();
#endif
FCOE_DBG("Destroying receive thread for CPU %d\n", cpu);
p = &per_cpu(fcoe_percpu, cpu);
spin_lock_bh(&p->fcoe_rx_list.lock);
thread = p->thread;
p->thread = NULL;
crc_eof = p->crc_eof_page;
p->crc_eof_page = NULL;
p->crc_eof_offset = 0;
spin_unlock_bh(&p->fcoe_rx_list.lock);
#ifdef CONFIG_SMP
if (cpu != targ_cpu) {
p0 = &per_cpu(fcoe_percpu, targ_cpu);
spin_lock_bh(&p0->fcoe_rx_list.lock);
if (p0->thread) {
FCOE_DBG("Moving frames from CPU %d to CPU %d\n",
cpu, targ_cpu);
while ((skb = __skb_dequeue(&p->fcoe_rx_list)) != NULL)
__skb_queue_tail(&p0->fcoe_rx_list, skb);
spin_unlock_bh(&p0->fcoe_rx_list.lock);
} else {
while ((skb = __skb_dequeue(&p->fcoe_rx_list)) != NULL)
kfree_skb(skb);
spin_unlock_bh(&p0->fcoe_rx_list.lock);
}
} else {
spin_lock_bh(&p->fcoe_rx_list.lock);
while ((skb = __skb_dequeue(&p->fcoe_rx_list)) != NULL)
kfree_skb(skb);
spin_unlock_bh(&p->fcoe_rx_list.lock);
}
put_cpu();
#else
spin_lock_bh(&p->fcoe_rx_list.lock);
while ((skb = __skb_dequeue(&p->fcoe_rx_list)) != NULL)
kfree_skb(skb);
spin_unlock_bh(&p->fcoe_rx_list.lock);
#endif
if (thread)
kthread_stop(thread);
if (crc_eof)
put_page(crc_eof);
}
static int fcoe_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned cpu = (unsigned long)hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
FCOE_DBG("CPU %x online: Create Rx thread\n", cpu);
fcoe_percpu_thread_create(cpu);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
FCOE_DBG("CPU %x offline: Remove Rx thread\n", cpu);
fcoe_percpu_thread_destroy(cpu);
break;
default:
break;
}
return NOTIFY_OK;
}
int fcoe_rcv(struct sk_buff *skb, struct net_device *netdev,
struct packet_type *ptype, struct net_device *olddev)
{
struct fc_lport *lport;
struct fcoe_rcv_info *fr;
struct fcoe_interface *fcoe;
struct fc_frame_header *fh;
struct fcoe_percpu_s *fps;
struct ethhdr *eh;
unsigned int cpu;
fcoe = container_of(ptype, struct fcoe_interface, fcoe_packet_type);
lport = fcoe->ctlr.lp;
if (unlikely(!lport)) {
FCOE_NETDEV_DBG(netdev, "Cannot find hba structure");
goto err2;
}
if (!lport->link_up)
goto err2;
FCOE_NETDEV_DBG(netdev, "skb_info: len:%d data_len:%d head:%p "
"data:%p tail:%p end:%p sum:%d dev:%s",
skb->len, skb->data_len, skb->head, skb->data,
skb_tail_pointer(skb), skb_end_pointer(skb),
skb->csum, skb->dev ? skb->dev->name : "<NULL>");
eh = eth_hdr(skb);
if (is_fip_mode(&fcoe->ctlr) &&
compare_ether_addr(eh->h_source, fcoe->ctlr.dest_addr)) {
FCOE_NETDEV_DBG(netdev, "wrong source mac address:%pM\n",
eh->h_source);
goto err;
}
if (unlikely((skb->len < FCOE_MIN_FRAME) ||
!pskb_may_pull(skb, FCOE_HEADER_LEN)))
goto err;
skb_set_transport_header(skb, sizeof(struct fcoe_hdr));
fh = (struct fc_frame_header *) skb_transport_header(skb);
if (ntoh24(&eh->h_dest[3]) != ntoh24(fh->fh_d_id)) {
FCOE_NETDEV_DBG(netdev, "FC frame d_id mismatch with MAC:%pM\n",
eh->h_dest);
goto err;
}
fr = fcoe_dev_from_skb(skb);
fr->fr_dev = lport;
fr->ptype = ptype;
if (ntoh24(fh->fh_f_ctl) & FC_FC_EX_CTX)
cpu = ntohs(fh->fh_ox_id) & fc_cpu_mask;
else
cpu = smp_processor_id();
fps = &per_cpu(fcoe_percpu, cpu);
spin_lock_bh(&fps->fcoe_rx_list.lock);
if (unlikely(!fps->thread)) {
FCOE_NETDEV_DBG(netdev, "CPU is online, but no receive thread "
"ready for incoming skb- using first online "
"CPU.\n");
spin_unlock_bh(&fps->fcoe_rx_list.lock);
cpu = cpumask_first(cpu_online_mask);
fps = &per_cpu(fcoe_percpu, cpu);
spin_lock_bh(&fps->fcoe_rx_list.lock);
if (!fps->thread) {
spin_unlock_bh(&fps->fcoe_rx_list.lock);
goto err;
}
}
if (fh->fh_type == FC_TYPE_FCP &&
cpu == smp_processor_id() &&
skb_queue_empty(&fps->fcoe_rx_list)) {
spin_unlock_bh(&fps->fcoe_rx_list.lock);
fcoe_recv_frame(skb);
} else {
__skb_queue_tail(&fps->fcoe_rx_list, skb);
if (fps->fcoe_rx_list.qlen == 1)
wake_up_process(fps->thread);
spin_unlock_bh(&fps->fcoe_rx_list.lock);
}
return 0;
err:
per_cpu_ptr(lport->dev_stats, get_cpu())->ErrorFrames++;
put_cpu();
err2:
kfree_skb(skb);
return -1;
}
static int fcoe_alloc_paged_crc_eof(struct sk_buff *skb, int tlen)
{
struct fcoe_percpu_s *fps;
int rc;
fps = &get_cpu_var(fcoe_percpu);
rc = fcoe_get_paged_crc_eof(skb, tlen, fps);
put_cpu_var(fcoe_percpu);
return rc;
}
int fcoe_xmit(struct fc_lport *lport, struct fc_frame *fp)
{
int wlen;
u32 crc;
struct ethhdr *eh;
struct fcoe_crc_eof *cp;
struct sk_buff *skb;
struct fcoe_dev_stats *stats;
struct fc_frame_header *fh;
unsigned int hlen;
unsigned int tlen;
unsigned int elen;
struct fcoe_port *port = lport_priv(lport);
struct fcoe_interface *fcoe = port->priv;
u8 sof, eof;
struct fcoe_hdr *hp;
WARN_ON((fr_len(fp) % sizeof(u32)) != 0);
fh = fc_frame_header_get(fp);
skb = fp_skb(fp);
wlen = skb->len / FCOE_WORD_TO_BYTE;
if (!lport->link_up) {
kfree_skb(skb);
return 0;
}
if (unlikely(fh->fh_type == FC_TYPE_ELS) &&
fcoe_ctlr_els_send(&fcoe->ctlr, lport, skb))
return 0;
sof = fr_sof(fp);
eof = fr_eof(fp);
elen = sizeof(struct ethhdr);
hlen = sizeof(struct fcoe_hdr);
tlen = sizeof(struct fcoe_crc_eof);
wlen = (skb->len - tlen + sizeof(crc)) / FCOE_WORD_TO_BYTE;
if (likely(lport->crc_offload)) {
skb->ip_summed = CHECKSUM_PARTIAL;
skb->csum_start = skb_headroom(skb);
skb->csum_offset = skb->len;
crc = 0;
} else {
skb->ip_summed = CHECKSUM_NONE;
crc = fcoe_fc_crc(fp);
}
if (skb_is_nonlinear(skb)) {
skb_frag_t *frag;
if (fcoe_alloc_paged_crc_eof(skb, tlen)) {
kfree_skb(skb);
return -ENOMEM;
}
frag = &skb_shinfo(skb)->frags[skb_shinfo(skb)->nr_frags - 1];
cp = kmap_atomic(frag->page, KM_SKB_DATA_SOFTIRQ)
+ frag->page_offset;
} else {
cp = (struct fcoe_crc_eof *)skb_put(skb, tlen);
}
memset(cp, 0, sizeof(*cp));
cp->fcoe_eof = eof;
cp->fcoe_crc32 = cpu_to_le32(~crc);
if (skb_is_nonlinear(skb)) {
kunmap_atomic(cp, KM_SKB_DATA_SOFTIRQ);
cp = NULL;
}
skb_push(skb, elen + hlen);
skb_reset_mac_header(skb);
skb_reset_network_header(skb);
skb->mac_len = elen;
skb->protocol = htons(ETH_P_FCOE);
skb->dev = fcoe->netdev;
eh = eth_hdr(skb);
eh->h_proto = htons(ETH_P_FCOE);
memcpy(eh->h_dest, fcoe->ctlr.dest_addr, ETH_ALEN);
if (fcoe->ctlr.map_dest)
memcpy(eh->h_dest + 3, fh->fh_d_id, 3);
if (unlikely(fcoe->ctlr.flogi_oxid != FC_XID_UNKNOWN))
memcpy(eh->h_source, fcoe->ctlr.ctl_src_addr, ETH_ALEN);
else
memcpy(eh->h_source, port->data_src_addr, ETH_ALEN);
hp = (struct fcoe_hdr *)(eh + 1);
memset(hp, 0, sizeof(*hp));
if (FC_FCOE_VER)
FC_FCOE_ENCAPS_VER(hp, FC_FCOE_VER);
hp->fcoe_sof = sof;
if (lport->seq_offload && fr_max_payload(fp)) {
skb_shinfo(skb)->gso_type = SKB_GSO_FCOE;
skb_shinfo(skb)->gso_size = fr_max_payload(fp);
} else {
skb_shinfo(skb)->gso_type = 0;
skb_shinfo(skb)->gso_size = 0;
}
stats = per_cpu_ptr(lport->dev_stats, get_cpu());
stats->TxFrames++;
stats->TxWords += wlen;
put_cpu();
fr_dev(fp) = lport;
if (port->fcoe_pending_queue.qlen)
fcoe_check_wait_queue(lport, skb);
else if (fcoe_start_io(skb))
fcoe_check_wait_queue(lport, skb);
return 0;
}
static void fcoe_percpu_flush_done(struct sk_buff *skb)
{
complete(&fcoe_flush_completion);
}
static inline int fcoe_filter_frames(struct fc_lport *lport,
struct fc_frame *fp)
{
struct fcoe_interface *fcoe;
struct fc_frame_header *fh;
struct sk_buff *skb = (struct sk_buff *)fp;
struct fcoe_dev_stats *stats;
if (lport->crc_offload && skb->ip_summed == CHECKSUM_UNNECESSARY)
fr_flags(fp) &= ~FCPHF_CRC_UNCHECKED;
else
fr_flags(fp) |= FCPHF_CRC_UNCHECKED;
fh = (struct fc_frame_header *) skb_transport_header(skb);
fh = fc_frame_header_get(fp);
if (fh->fh_r_ctl == FC_RCTL_DD_SOL_DATA && fh->fh_type == FC_TYPE_FCP)
return 0;
fcoe = ((struct fcoe_port *)lport_priv(lport))->priv;
if (is_fip_mode(&fcoe->ctlr) && fc_frame_payload_op(fp) == ELS_LOGO &&
ntoh24(fh->fh_s_id) == FC_FID_FLOGI) {
FCOE_DBG("fcoe: dropping FCoE lport LOGO in fip mode\n");
return -EINVAL;
}
if (!(fr_flags(fp) & FCPHF_CRC_UNCHECKED) ||
le32_to_cpu(fr_crc(fp)) == ~crc32(~0, skb->data, skb->len)) {
fr_flags(fp) &= ~FCPHF_CRC_UNCHECKED;
return 0;
}
stats = per_cpu_ptr(lport->dev_stats, get_cpu());
stats->InvalidCRCCount++;
if (stats->InvalidCRCCount < 5)
printk(KERN_WARNING "fcoe: dropping frame with CRC error\n");
return -EINVAL;
}
static void fcoe_recv_frame(struct sk_buff *skb)
{
u32 fr_len;
struct fc_lport *lport;
struct fcoe_rcv_info *fr;
struct fcoe_dev_stats *stats;
struct fcoe_crc_eof crc_eof;
struct fc_frame *fp;
struct fcoe_port *port;
struct fcoe_hdr *hp;
fr = fcoe_dev_from_skb(skb);
lport = fr->fr_dev;
if (unlikely(!lport)) {
if (skb->destructor != fcoe_percpu_flush_done)
FCOE_NETDEV_DBG(skb->dev, "NULL lport in skb");
kfree_skb(skb);
return;
}
FCOE_NETDEV_DBG(skb->dev, "skb_info: len:%d data_len:%d "
"head:%p data:%p tail:%p end:%p sum:%d dev:%s",
skb->len, skb->data_len,
skb->head, skb->data, skb_tail_pointer(skb),
skb_end_pointer(skb), skb->csum,
skb->dev ? skb->dev->name : "<NULL>");
port = lport_priv(lport);
if (skb_is_nonlinear(skb))
skb_linearize(skb);
hp = (struct fcoe_hdr *) skb_network_header(skb);
stats = per_cpu_ptr(lport->dev_stats, get_cpu());
if (unlikely(FC_FCOE_DECAPS_VER(hp) != FC_FCOE_VER)) {
if (stats->ErrorFrames < 5)
printk(KERN_WARNING "fcoe: FCoE version "
"mismatch: The frame has "
"version %x, but the "
"initiator supports version "
"%x\n", FC_FCOE_DECAPS_VER(hp),
FC_FCOE_VER);
goto drop;
}
skb_pull(skb, sizeof(struct fcoe_hdr));
fr_len = skb->len - sizeof(struct fcoe_crc_eof);
stats->RxFrames++;
stats->RxWords += fr_len / FCOE_WORD_TO_BYTE;
fp = (struct fc_frame *)skb;
fc_frame_init(fp);
fr_dev(fp) = lport;
fr_sof(fp) = hp->fcoe_sof;
if (skb_copy_bits(skb, fr_len, &crc_eof, sizeof(crc_eof)))
goto drop;
fr_eof(fp) = crc_eof.fcoe_eof;
fr_crc(fp) = crc_eof.fcoe_crc32;
if (pskb_trim(skb, fr_len))
goto drop;
if (!fcoe_filter_frames(lport, fp)) {
put_cpu();
fc_exch_recv(lport, fp);
return;
}
drop:
stats->ErrorFrames++;
put_cpu();
kfree_skb(skb);
}
int fcoe_percpu_receive_thread(void *arg)
{
struct fcoe_percpu_s *p = arg;
struct sk_buff *skb;
set_user_nice(current, -20);
while (!kthread_should_stop()) {
spin_lock_bh(&p->fcoe_rx_list.lock);
while ((skb = __skb_dequeue(&p->fcoe_rx_list)) == NULL) {
set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_bh(&p->fcoe_rx_list.lock);
schedule();
set_current_state(TASK_RUNNING);
if (kthread_should_stop())
return 0;
spin_lock_bh(&p->fcoe_rx_list.lock);
}
spin_unlock_bh(&p->fcoe_rx_list.lock);
fcoe_recv_frame(skb);
}
return 0;
}
static void fcoe_dev_setup(void)
{
register_netdevice_notifier(&fcoe_notifier);
}
static void fcoe_dev_cleanup(void)
{
unregister_netdevice_notifier(&fcoe_notifier);
}
static int fcoe_device_notification(struct notifier_block *notifier,
ulong event, void *ptr)
{
struct fc_lport *lport = NULL;
struct net_device *netdev = ptr;
struct fcoe_interface *fcoe;
struct fcoe_port *port;
struct fcoe_dev_stats *stats;
u32 link_possible = 1;
u32 mfs;
int rc = NOTIFY_OK;
list_for_each_entry(fcoe, &fcoe_hostlist, list) {
if (fcoe->netdev == netdev) {
lport = fcoe->ctlr.lp;
break;
}
}
if (!lport) {
rc = NOTIFY_DONE;
goto out;
}
switch (event) {
case NETDEV_DOWN:
case NETDEV_GOING_DOWN:
link_possible = 0;
break;
case NETDEV_UP:
case NETDEV_CHANGE:
break;
case NETDEV_CHANGEMTU:
if (netdev->features & NETIF_F_FCOE_MTU)
break;
mfs = netdev->mtu - (sizeof(struct fcoe_hdr) +
sizeof(struct fcoe_crc_eof));
if (mfs >= FC_MIN_MAX_FRAME)
fc_set_mfs(lport, mfs);
break;
case NETDEV_REGISTER:
break;
case NETDEV_UNREGISTER:
list_del(&fcoe->list);
port = lport_priv(fcoe->ctlr.lp);
fcoe_interface_cleanup(fcoe);
queue_work(fcoe_wq, &port->destroy_work);
goto out;
break;
case NETDEV_FEAT_CHANGE:
fcoe_netdev_features_change(lport, netdev);
break;
default:
FCOE_NETDEV_DBG(netdev, "Unknown event %ld "
"from netdev netlink\n", event);
}
fcoe_link_speed_update(lport);
if (link_possible && !fcoe_link_ok(lport))
fcoe_ctlr_link_up(&fcoe->ctlr);
else if (fcoe_ctlr_link_down(&fcoe->ctlr)) {
stats = per_cpu_ptr(lport->dev_stats, get_cpu());
stats->LinkFailureCount++;
put_cpu();
fcoe_clean_pending_queue(lport);
}
out:
return rc;
}
static int fcoe_disable(struct net_device *netdev)
{
struct fcoe_interface *fcoe;
int rc = 0;
mutex_lock(&fcoe_config_mutex);
rtnl_lock();
fcoe = fcoe_hostlist_lookup_port(netdev);
rtnl_unlock();
if (fcoe) {
fcoe_ctlr_link_down(&fcoe->ctlr);
fcoe_clean_pending_queue(fcoe->ctlr.lp);
} else
rc = -ENODEV;
mutex_unlock(&fcoe_config_mutex);
return rc;
}
static int fcoe_enable(struct net_device *netdev)
{
struct fcoe_interface *fcoe;
int rc = 0;
mutex_lock(&fcoe_config_mutex);
rtnl_lock();
fcoe = fcoe_hostlist_lookup_port(netdev);
rtnl_unlock();
if (!fcoe)
rc = -ENODEV;
else if (!fcoe_link_ok(fcoe->ctlr.lp))
fcoe_ctlr_link_up(&fcoe->ctlr);
mutex_unlock(&fcoe_config_mutex);
return rc;
}
static int fcoe_destroy(struct net_device *netdev)
{
struct fcoe_interface *fcoe;
struct fc_lport *lport;
int rc = 0;
mutex_lock(&fcoe_config_mutex);
rtnl_lock();
fcoe = fcoe_hostlist_lookup_port(netdev);
if (!fcoe) {
rtnl_unlock();
rc = -ENODEV;
goto out_nodev;
}
lport = fcoe->ctlr.lp;
list_del(&fcoe->list);
fcoe_interface_cleanup(fcoe);
rtnl_unlock();
fcoe_if_destroy(lport);
out_nodev:
mutex_unlock(&fcoe_config_mutex);
return rc;
}
static void fcoe_destroy_work(struct work_struct *work)
{
struct fcoe_port *port;
port = container_of(work, struct fcoe_port, destroy_work);
mutex_lock(&fcoe_config_mutex);
fcoe_if_destroy(port->lport);
mutex_unlock(&fcoe_config_mutex);
}
static bool fcoe_match(struct net_device *netdev)
{
return true;
}
static int fcoe_create(struct net_device *netdev, enum fip_state fip_mode)
{
int rc;
struct fcoe_interface *fcoe;
struct fc_lport *lport;
mutex_lock(&fcoe_config_mutex);
rtnl_lock();
if (fcoe_hostlist_lookup(netdev)) {
rc = -EEXIST;
goto out_nodev;
}
fcoe = fcoe_interface_create(netdev, fip_mode);
if (IS_ERR(fcoe)) {
rc = PTR_ERR(fcoe);
goto out_nodev;
}
lport = fcoe_if_create(fcoe, &netdev->dev, 0);
if (IS_ERR(lport)) {
printk(KERN_ERR "fcoe: Failed to create interface (%s)\n",
netdev->name);
rc = -EIO;
fcoe_interface_cleanup(fcoe);
goto out_free;
}
fcoe->ctlr.lp = lport;
fcoe_hostlist_add(lport);
lport->boot_time = jiffies;
fc_fabric_login(lport);
if (!fcoe_link_ok(lport))
fcoe_ctlr_link_up(&fcoe->ctlr);
fcoe_interface_put(fcoe);
rtnl_unlock();
mutex_unlock(&fcoe_config_mutex);
return 0;
out_free:
fcoe_interface_put(fcoe);
out_nodev:
rtnl_unlock();
mutex_unlock(&fcoe_config_mutex);
return rc;
}
int fcoe_link_speed_update(struct fc_lport *lport)
{
struct net_device *netdev = fcoe_netdev(lport);
struct ethtool_cmd ecmd;
if (!dev_ethtool_get_settings(netdev, &ecmd)) {
lport->link_supported_speeds &=
~(FC_PORTSPEED_1GBIT | FC_PORTSPEED_10GBIT);
if (ecmd.supported & (SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full))
lport->link_supported_speeds |= FC_PORTSPEED_1GBIT;
if (ecmd.supported & SUPPORTED_10000baseT_Full)
lport->link_supported_speeds |=
FC_PORTSPEED_10GBIT;
switch (ethtool_cmd_speed(&ecmd)) {
case SPEED_1000:
lport->link_speed = FC_PORTSPEED_1GBIT;
break;
case SPEED_10000:
lport->link_speed = FC_PORTSPEED_10GBIT;
break;
}
return 0;
}
return -1;
}
int fcoe_link_ok(struct fc_lport *lport)
{
struct net_device *netdev = fcoe_netdev(lport);
if (netif_oper_up(netdev))
return 0;
return -1;
}
void fcoe_percpu_clean(struct fc_lport *lport)
{
struct fcoe_percpu_s *pp;
struct fcoe_rcv_info *fr;
struct sk_buff_head *list;
struct sk_buff *skb, *next;
struct sk_buff *head;
unsigned int cpu;
for_each_possible_cpu(cpu) {
pp = &per_cpu(fcoe_percpu, cpu);
spin_lock_bh(&pp->fcoe_rx_list.lock);
list = &pp->fcoe_rx_list;
head = list->next;
for (skb = head; skb != (struct sk_buff *)list;
skb = next) {
next = skb->next;
fr = fcoe_dev_from_skb(skb);
if (fr->fr_dev == lport) {
__skb_unlink(skb, list);
kfree_skb(skb);
}
}
if (!pp->thread || !cpu_online(cpu)) {
spin_unlock_bh(&pp->fcoe_rx_list.lock);
continue;
}
skb = dev_alloc_skb(0);
if (!skb) {
spin_unlock_bh(&pp->fcoe_rx_list.lock);
continue;
}
skb->destructor = fcoe_percpu_flush_done;
__skb_queue_tail(&pp->fcoe_rx_list, skb);
if (pp->fcoe_rx_list.qlen == 1)
wake_up_process(pp->thread);
spin_unlock_bh(&pp->fcoe_rx_list.lock);
wait_for_completion(&fcoe_flush_completion);
}
}
int fcoe_reset(struct Scsi_Host *shost)
{
struct fc_lport *lport = shost_priv(shost);
struct fcoe_port *port = lport_priv(lport);
struct fcoe_interface *fcoe = port->priv;
fcoe_ctlr_link_down(&fcoe->ctlr);
fcoe_clean_pending_queue(fcoe->ctlr.lp);
if (!fcoe_link_ok(fcoe->ctlr.lp))
fcoe_ctlr_link_up(&fcoe->ctlr);
return 0;
}
static struct fcoe_interface *
fcoe_hostlist_lookup_port(const struct net_device *netdev)
{
struct fcoe_interface *fcoe;
list_for_each_entry(fcoe, &fcoe_hostlist, list) {
if (fcoe->netdev == netdev)
return fcoe;
}
return NULL;
}
static struct fc_lport *fcoe_hostlist_lookup(const struct net_device *netdev)
{
struct fcoe_interface *fcoe;
fcoe = fcoe_hostlist_lookup_port(netdev);
return (fcoe) ? fcoe->ctlr.lp : NULL;
}
static int fcoe_hostlist_add(const struct fc_lport *lport)
{
struct fcoe_interface *fcoe;
struct fcoe_port *port;
fcoe = fcoe_hostlist_lookup_port(fcoe_netdev(lport));
if (!fcoe) {
port = lport_priv(lport);
fcoe = port->priv;
list_add_tail(&fcoe->list, &fcoe_hostlist);
}
return 0;
}
static int __init fcoe_init(void)
{
struct fcoe_percpu_s *p;
unsigned int cpu;
int rc = 0;
fcoe_wq = alloc_workqueue("fcoe", 0, 0);
if (!fcoe_wq)
return -ENOMEM;
rc = fcoe_transport_attach(&fcoe_sw_transport);
if (rc) {
printk(KERN_ERR "failed to register an fcoe transport, check "
"if libfcoe is loaded\n");
return rc;
}
mutex_lock(&fcoe_config_mutex);
for_each_possible_cpu(cpu) {
p = &per_cpu(fcoe_percpu, cpu);
skb_queue_head_init(&p->fcoe_rx_list);
}
for_each_online_cpu(cpu)
fcoe_percpu_thread_create(cpu);
rc = register_hotcpu_notifier(&fcoe_cpu_notifier);
if (rc)
goto out_free;
fcoe_dev_setup();
rc = fcoe_if_init();
if (rc)
goto out_free;
mutex_unlock(&fcoe_config_mutex);
return 0;
out_free:
for_each_online_cpu(cpu) {
fcoe_percpu_thread_destroy(cpu);
}
mutex_unlock(&fcoe_config_mutex);
destroy_workqueue(fcoe_wq);
return rc;
}
static void __exit fcoe_exit(void)
{
struct fcoe_interface *fcoe, *tmp;
struct fcoe_port *port;
unsigned int cpu;
mutex_lock(&fcoe_config_mutex);
fcoe_dev_cleanup();
rtnl_lock();
list_for_each_entry_safe(fcoe, tmp, &fcoe_hostlist, list) {
list_del(&fcoe->list);
port = lport_priv(fcoe->ctlr.lp);
fcoe_interface_cleanup(fcoe);
queue_work(fcoe_wq, &port->destroy_work);
}
rtnl_unlock();
unregister_hotcpu_notifier(&fcoe_cpu_notifier);
for_each_online_cpu(cpu)
fcoe_percpu_thread_destroy(cpu);
mutex_unlock(&fcoe_config_mutex);
destroy_workqueue(fcoe_wq);
fcoe_if_exit();
fcoe_transport_detach(&fcoe_sw_transport);
}
static void fcoe_flogi_resp(struct fc_seq *seq, struct fc_frame *fp, void *arg)
{
struct fcoe_ctlr *fip = arg;
struct fc_exch *exch = fc_seq_exch(seq);
struct fc_lport *lport = exch->lp;
u8 *mac;
if (IS_ERR(fp))
goto done;
mac = fr_cb(fp)->granted_mac;
if (is_zero_ether_addr(mac)) {
if (fcoe_ctlr_recv_flogi(fip, lport, fp)) {
fc_frame_free(fp);
return;
}
}
fcoe_update_src_mac(lport, mac);
done:
fc_lport_flogi_resp(seq, fp, lport);
}
static void fcoe_logo_resp(struct fc_seq *seq, struct fc_frame *fp, void *arg)
{
struct fc_lport *lport = arg;
static u8 zero_mac[ETH_ALEN] = { 0 };
if (!IS_ERR(fp))
fcoe_update_src_mac(lport, zero_mac);
fc_lport_logo_resp(seq, fp, lport);
}
static struct fc_seq *fcoe_elsct_send(struct fc_lport *lport, u32 did,
struct fc_frame *fp, unsigned int op,
void (*resp)(struct fc_seq *,
struct fc_frame *,
void *),
void *arg, u32 timeout)
{
struct fcoe_port *port = lport_priv(lport);
struct fcoe_interface *fcoe = port->priv;
struct fcoe_ctlr *fip = &fcoe->ctlr;
struct fc_frame_header *fh = fc_frame_header_get(fp);
switch (op) {
case ELS_FLOGI:
case ELS_FDISC:
if (lport->point_to_multipoint)
break;
return fc_elsct_send(lport, did, fp, op, fcoe_flogi_resp,
fip, timeout);
case ELS_LOGO:
if (ntoh24(fh->fh_d_id) != FC_FID_FLOGI)
break;
return fc_elsct_send(lport, did, fp, op, fcoe_logo_resp,
lport, timeout);
}
return fc_elsct_send(lport, did, fp, op, resp, arg, timeout);
}
static int fcoe_vport_create(struct fc_vport *vport, bool disabled)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_lport *n_port = shost_priv(shost);
struct fcoe_port *port = lport_priv(n_port);
struct fcoe_interface *fcoe = port->priv;
struct net_device *netdev = fcoe->netdev;
struct fc_lport *vn_port;
int rc;
char buf[32];
rc = fcoe_validate_vport_create(vport);
if (rc) {
wwn_to_str(vport->port_name, buf, sizeof(buf));
printk(KERN_ERR "fcoe: Failed to create vport, "
"WWPN (0x%s) already exists\n",
buf);
return rc;
}
mutex_lock(&fcoe_config_mutex);
vn_port = fcoe_if_create(fcoe, &vport->dev, 1);
mutex_unlock(&fcoe_config_mutex);
if (IS_ERR(vn_port)) {
printk(KERN_ERR "fcoe: fcoe_vport_create(%s) failed\n",
netdev->name);
return -EIO;
}
if (disabled) {
fc_vport_set_state(vport, FC_VPORT_DISABLED);
} else {
vn_port->boot_time = jiffies;
fc_fabric_login(vn_port);
fc_vport_setlink(vn_port);
}
return 0;
}
static int fcoe_vport_destroy(struct fc_vport *vport)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_lport *n_port = shost_priv(shost);
struct fc_lport *vn_port = vport->dd_data;
struct fcoe_port *port = lport_priv(vn_port);
mutex_lock(&n_port->lp_mutex);
list_del(&vn_port->list);
mutex_unlock(&n_port->lp_mutex);
queue_work(fcoe_wq, &port->destroy_work);
return 0;
}
static int fcoe_vport_disable(struct fc_vport *vport, bool disable)
{
struct fc_lport *lport = vport->dd_data;
if (disable) {
fc_vport_set_state(vport, FC_VPORT_DISABLED);
fc_fabric_logoff(lport);
} else {
lport->boot_time = jiffies;
fc_fabric_login(lport);
fc_vport_setlink(lport);
}
return 0;
}
static void fcoe_set_vport_symbolic_name(struct fc_vport *vport)
{
struct fc_lport *lport = vport->dd_data;
struct fc_frame *fp;
size_t len;
snprintf(fc_host_symbolic_name(lport->host), FC_SYMBOLIC_NAME_SIZE,
"%s v%s over %s : %s", FCOE_NAME, FCOE_VERSION,
fcoe_netdev(lport)->name, vport->symbolic_name);
if (lport->state != LPORT_ST_READY)
return;
len = strnlen(fc_host_symbolic_name(lport->host), 255);
fp = fc_frame_alloc(lport,
sizeof(struct fc_ct_hdr) +
sizeof(struct fc_ns_rspn) + len);
if (!fp)
return;
lport->tt.elsct_send(lport, FC_FID_DIR_SERV, fp, FC_NS_RSPN_ID,
NULL, NULL, 3 * lport->r_a_tov);
}
static void fcoe_get_lesb(struct fc_lport *lport,
struct fc_els_lesb *fc_lesb)
{
unsigned int cpu;
u32 lfc, vlfc, mdac;
struct fcoe_dev_stats *devst;
struct fcoe_fc_els_lesb *lesb;
struct rtnl_link_stats64 temp;
struct net_device *netdev = fcoe_netdev(lport);
lfc = 0;
vlfc = 0;
mdac = 0;
lesb = (struct fcoe_fc_els_lesb *)fc_lesb;
memset(lesb, 0, sizeof(*lesb));
for_each_possible_cpu(cpu) {
devst = per_cpu_ptr(lport->dev_stats, cpu);
lfc += devst->LinkFailureCount;
vlfc += devst->VLinkFailureCount;
mdac += devst->MissDiscAdvCount;
}
lesb->lesb_link_fail = htonl(lfc);
lesb->lesb_vlink_fail = htonl(vlfc);
lesb->lesb_miss_fka = htonl(mdac);
lesb->lesb_fcs_error = htonl(dev_get_stats(netdev, &temp)->rx_crc_errors);
}
static void fcoe_set_port_id(struct fc_lport *lport,
u32 port_id, struct fc_frame *fp)
{
struct fcoe_port *port = lport_priv(lport);
struct fcoe_interface *fcoe = port->priv;
if (fp && fc_frame_payload_op(fp) == ELS_FLOGI)
fcoe_ctlr_recv_flogi(&fcoe->ctlr, lport, fp);
}
static int fcoe_validate_vport_create(struct fc_vport *vport)
{
struct Scsi_Host *shost = vport_to_shost(vport);
struct fc_lport *n_port = shost_priv(shost);
struct fc_lport *vn_port;
int rc = 0;
char buf[32];
mutex_lock(&n_port->lp_mutex);
wwn_to_str(vport->port_name, buf, sizeof(buf));
if (!memcmp(&n_port->wwpn, &vport->port_name, sizeof(u64))) {
FCOE_DBG("vport WWPN 0x%s is same as that of the "
"base port WWPN\n", buf);
rc = -EINVAL;
goto out;
}
list_for_each_entry(vn_port, &n_port->vports, list) {
if (!memcmp(&vn_port->wwpn, &vport->port_name, sizeof(u64))) {
FCOE_DBG("vport with given WWPN 0x%s already "
"exists\n", buf);
rc = -EINVAL;
break;
}
}
out:
mutex_unlock(&n_port->lp_mutex);
return rc;
}
