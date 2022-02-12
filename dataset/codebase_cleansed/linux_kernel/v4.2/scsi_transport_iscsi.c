static void iscsi_transport_release(struct device *dev)
{
struct iscsi_internal *priv = dev_to_iscsi_internal(dev);
kfree(priv);
}
static ssize_t
show_transport_handle(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct iscsi_internal *priv = dev_to_iscsi_internal(dev);
return sprintf(buf, "%llu\n", (unsigned long long)iscsi_handle(priv->iscsi_transport));
}
static void iscsi_endpoint_release(struct device *dev)
{
struct iscsi_endpoint *ep = iscsi_dev_to_endpoint(dev);
kfree(ep);
}
static ssize_t
show_ep_handle(struct device *dev, struct device_attribute *attr, char *buf)
{
struct iscsi_endpoint *ep = iscsi_dev_to_endpoint(dev);
return sprintf(buf, "%llu\n", (unsigned long long) ep->id);
}
static int iscsi_match_epid(struct device *dev, const void *data)
{
struct iscsi_endpoint *ep = iscsi_dev_to_endpoint(dev);
const uint64_t *epid = data;
return *epid == ep->id;
}
struct iscsi_endpoint *
iscsi_create_endpoint(int dd_size)
{
struct device *dev;
struct iscsi_endpoint *ep;
uint64_t id;
int err;
for (id = 1; id < ISCSI_MAX_EPID; id++) {
dev = class_find_device(&iscsi_endpoint_class, NULL, &id,
iscsi_match_epid);
if (!dev)
break;
else
put_device(dev);
}
if (id == ISCSI_MAX_EPID) {
printk(KERN_ERR "Too many connections. Max supported %u\n",
ISCSI_MAX_EPID - 1);
return NULL;
}
ep = kzalloc(sizeof(*ep) + dd_size, GFP_KERNEL);
if (!ep)
return NULL;
ep->id = id;
ep->dev.class = &iscsi_endpoint_class;
dev_set_name(&ep->dev, "ep-%llu", (unsigned long long) id);
err = device_register(&ep->dev);
if (err)
goto free_ep;
err = sysfs_create_group(&ep->dev.kobj, &iscsi_endpoint_group);
if (err)
goto unregister_dev;
if (dd_size)
ep->dd_data = &ep[1];
return ep;
unregister_dev:
device_unregister(&ep->dev);
return NULL;
free_ep:
kfree(ep);
return NULL;
}
void iscsi_destroy_endpoint(struct iscsi_endpoint *ep)
{
sysfs_remove_group(&ep->dev.kobj, &iscsi_endpoint_group);
device_unregister(&ep->dev);
}
struct iscsi_endpoint *iscsi_lookup_endpoint(u64 handle)
{
struct iscsi_endpoint *ep;
struct device *dev;
dev = class_find_device(&iscsi_endpoint_class, NULL, &handle,
iscsi_match_epid);
if (!dev)
return NULL;
ep = iscsi_dev_to_endpoint(dev);
put_device(dev);
return ep;
}
static void iscsi_iface_release(struct device *dev)
{
struct iscsi_iface *iface = iscsi_dev_to_iface(dev);
struct device *parent = iface->dev.parent;
kfree(iface);
put_device(parent);
}
static umode_t iscsi_iface_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int i)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct iscsi_iface *iface = iscsi_dev_to_iface(dev);
struct iscsi_transport *t = iface->transport;
int param;
int param_type;
if (attr == &dev_attr_iface_enabled.attr)
param = ISCSI_NET_PARAM_IFACE_ENABLE;
else if (attr == &dev_attr_iface_vlan_id.attr)
param = ISCSI_NET_PARAM_VLAN_ID;
else if (attr == &dev_attr_iface_vlan_priority.attr)
param = ISCSI_NET_PARAM_VLAN_PRIORITY;
else if (attr == &dev_attr_iface_vlan_enabled.attr)
param = ISCSI_NET_PARAM_VLAN_ENABLED;
else if (attr == &dev_attr_iface_mtu.attr)
param = ISCSI_NET_PARAM_MTU;
else if (attr == &dev_attr_iface_port.attr)
param = ISCSI_NET_PARAM_PORT;
else if (attr == &dev_attr_iface_ipaddress_state.attr)
param = ISCSI_NET_PARAM_IPADDR_STATE;
else if (attr == &dev_attr_iface_delayed_ack_en.attr)
param = ISCSI_NET_PARAM_DELAYED_ACK_EN;
else if (attr == &dev_attr_iface_tcp_nagle_disable.attr)
param = ISCSI_NET_PARAM_TCP_NAGLE_DISABLE;
else if (attr == &dev_attr_iface_tcp_wsf_disable.attr)
param = ISCSI_NET_PARAM_TCP_WSF_DISABLE;
else if (attr == &dev_attr_iface_tcp_wsf.attr)
param = ISCSI_NET_PARAM_TCP_WSF;
else if (attr == &dev_attr_iface_tcp_timer_scale.attr)
param = ISCSI_NET_PARAM_TCP_TIMER_SCALE;
else if (attr == &dev_attr_iface_tcp_timestamp_en.attr)
param = ISCSI_NET_PARAM_TCP_TIMESTAMP_EN;
else if (attr == &dev_attr_iface_cache_id.attr)
param = ISCSI_NET_PARAM_CACHE_ID;
else if (attr == &dev_attr_iface_redirect_en.attr)
param = ISCSI_NET_PARAM_REDIRECT_EN;
else if (attr == &dev_attr_iface_def_taskmgmt_tmo.attr)
param = ISCSI_IFACE_PARAM_DEF_TASKMGMT_TMO;
else if (attr == &dev_attr_iface_header_digest.attr)
param = ISCSI_IFACE_PARAM_HDRDGST_EN;
else if (attr == &dev_attr_iface_data_digest.attr)
param = ISCSI_IFACE_PARAM_DATADGST_EN;
else if (attr == &dev_attr_iface_immediate_data.attr)
param = ISCSI_IFACE_PARAM_IMM_DATA_EN;
else if (attr == &dev_attr_iface_initial_r2t.attr)
param = ISCSI_IFACE_PARAM_INITIAL_R2T_EN;
else if (attr == &dev_attr_iface_data_seq_in_order.attr)
param = ISCSI_IFACE_PARAM_DATASEQ_INORDER_EN;
else if (attr == &dev_attr_iface_data_pdu_in_order.attr)
param = ISCSI_IFACE_PARAM_PDU_INORDER_EN;
else if (attr == &dev_attr_iface_erl.attr)
param = ISCSI_IFACE_PARAM_ERL;
else if (attr == &dev_attr_iface_max_recv_dlength.attr)
param = ISCSI_IFACE_PARAM_MAX_RECV_DLENGTH;
else if (attr == &dev_attr_iface_first_burst_len.attr)
param = ISCSI_IFACE_PARAM_FIRST_BURST;
else if (attr == &dev_attr_iface_max_outstanding_r2t.attr)
param = ISCSI_IFACE_PARAM_MAX_R2T;
else if (attr == &dev_attr_iface_max_burst_len.attr)
param = ISCSI_IFACE_PARAM_MAX_BURST;
else if (attr == &dev_attr_iface_chap_auth.attr)
param = ISCSI_IFACE_PARAM_CHAP_AUTH_EN;
else if (attr == &dev_attr_iface_bidi_chap.attr)
param = ISCSI_IFACE_PARAM_BIDI_CHAP_EN;
else if (attr == &dev_attr_iface_discovery_auth_optional.attr)
param = ISCSI_IFACE_PARAM_DISCOVERY_AUTH_OPTIONAL;
else if (attr == &dev_attr_iface_discovery_logout.attr)
param = ISCSI_IFACE_PARAM_DISCOVERY_LOGOUT_EN;
else if (attr == &dev_attr_iface_strict_login_comp_en.attr)
param = ISCSI_IFACE_PARAM_STRICT_LOGIN_COMP_EN;
else if (attr == &dev_attr_iface_initiator_name.attr)
param = ISCSI_IFACE_PARAM_INITIATOR_NAME;
else if (iface->iface_type == ISCSI_IFACE_TYPE_IPV4) {
if (attr == &dev_attr_ipv4_iface_ipaddress.attr)
param = ISCSI_NET_PARAM_IPV4_ADDR;
else if (attr == &dev_attr_ipv4_iface_gateway.attr)
param = ISCSI_NET_PARAM_IPV4_GW;
else if (attr == &dev_attr_ipv4_iface_subnet.attr)
param = ISCSI_NET_PARAM_IPV4_SUBNET;
else if (attr == &dev_attr_ipv4_iface_bootproto.attr)
param = ISCSI_NET_PARAM_IPV4_BOOTPROTO;
else if (attr ==
&dev_attr_ipv4_iface_dhcp_dns_address_en.attr)
param = ISCSI_NET_PARAM_IPV4_DHCP_DNS_ADDR_EN;
else if (attr ==
&dev_attr_ipv4_iface_dhcp_slp_da_info_en.attr)
param = ISCSI_NET_PARAM_IPV4_DHCP_SLP_DA_EN;
else if (attr == &dev_attr_ipv4_iface_tos_en.attr)
param = ISCSI_NET_PARAM_IPV4_TOS_EN;
else if (attr == &dev_attr_ipv4_iface_tos.attr)
param = ISCSI_NET_PARAM_IPV4_TOS;
else if (attr == &dev_attr_ipv4_iface_grat_arp_en.attr)
param = ISCSI_NET_PARAM_IPV4_GRAT_ARP_EN;
else if (attr ==
&dev_attr_ipv4_iface_dhcp_alt_client_id_en.attr)
param = ISCSI_NET_PARAM_IPV4_DHCP_ALT_CLIENT_ID_EN;
else if (attr == &dev_attr_ipv4_iface_dhcp_alt_client_id.attr)
param = ISCSI_NET_PARAM_IPV4_DHCP_ALT_CLIENT_ID;
else if (attr ==
&dev_attr_ipv4_iface_dhcp_req_vendor_id_en.attr)
param = ISCSI_NET_PARAM_IPV4_DHCP_REQ_VENDOR_ID_EN;
else if (attr ==
&dev_attr_ipv4_iface_dhcp_use_vendor_id_en.attr)
param = ISCSI_NET_PARAM_IPV4_DHCP_USE_VENDOR_ID_EN;
else if (attr == &dev_attr_ipv4_iface_dhcp_vendor_id.attr)
param = ISCSI_NET_PARAM_IPV4_DHCP_VENDOR_ID;
else if (attr ==
&dev_attr_ipv4_iface_dhcp_learn_iqn_en.attr)
param = ISCSI_NET_PARAM_IPV4_DHCP_LEARN_IQN_EN;
else if (attr ==
&dev_attr_ipv4_iface_fragment_disable.attr)
param = ISCSI_NET_PARAM_IPV4_FRAGMENT_DISABLE;
else if (attr ==
&dev_attr_ipv4_iface_incoming_forwarding_en.attr)
param = ISCSI_NET_PARAM_IPV4_IN_FORWARD_EN;
else if (attr == &dev_attr_ipv4_iface_ttl.attr)
param = ISCSI_NET_PARAM_IPV4_TTL;
else
return 0;
} else if (iface->iface_type == ISCSI_IFACE_TYPE_IPV6) {
if (attr == &dev_attr_ipv6_iface_ipaddress.attr)
param = ISCSI_NET_PARAM_IPV6_ADDR;
else if (attr == &dev_attr_ipv6_iface_link_local_addr.attr)
param = ISCSI_NET_PARAM_IPV6_LINKLOCAL;
else if (attr == &dev_attr_ipv6_iface_router_addr.attr)
param = ISCSI_NET_PARAM_IPV6_ROUTER;
else if (attr == &dev_attr_ipv6_iface_ipaddr_autocfg.attr)
param = ISCSI_NET_PARAM_IPV6_ADDR_AUTOCFG;
else if (attr == &dev_attr_ipv6_iface_link_local_autocfg.attr)
param = ISCSI_NET_PARAM_IPV6_LINKLOCAL_AUTOCFG;
else if (attr == &dev_attr_ipv6_iface_link_local_state.attr)
param = ISCSI_NET_PARAM_IPV6_LINKLOCAL_STATE;
else if (attr == &dev_attr_ipv6_iface_router_state.attr)
param = ISCSI_NET_PARAM_IPV6_ROUTER_STATE;
else if (attr ==
&dev_attr_ipv6_iface_grat_neighbor_adv_en.attr)
param = ISCSI_NET_PARAM_IPV6_GRAT_NEIGHBOR_ADV_EN;
else if (attr == &dev_attr_ipv6_iface_mld_en.attr)
param = ISCSI_NET_PARAM_IPV6_MLD_EN;
else if (attr == &dev_attr_ipv6_iface_flow_label.attr)
param = ISCSI_NET_PARAM_IPV6_FLOW_LABEL;
else if (attr == &dev_attr_ipv6_iface_traffic_class.attr)
param = ISCSI_NET_PARAM_IPV6_TRAFFIC_CLASS;
else if (attr == &dev_attr_ipv6_iface_hop_limit.attr)
param = ISCSI_NET_PARAM_IPV6_HOP_LIMIT;
else if (attr == &dev_attr_ipv6_iface_nd_reachable_tmo.attr)
param = ISCSI_NET_PARAM_IPV6_ND_REACHABLE_TMO;
else if (attr == &dev_attr_ipv6_iface_nd_rexmit_time.attr)
param = ISCSI_NET_PARAM_IPV6_ND_REXMIT_TIME;
else if (attr == &dev_attr_ipv6_iface_nd_stale_tmo.attr)
param = ISCSI_NET_PARAM_IPV6_ND_STALE_TMO;
else if (attr == &dev_attr_ipv6_iface_dup_addr_detect_cnt.attr)
param = ISCSI_NET_PARAM_IPV6_DUP_ADDR_DETECT_CNT;
else if (attr == &dev_attr_ipv6_iface_router_adv_link_mtu.attr)
param = ISCSI_NET_PARAM_IPV6_RTR_ADV_LINK_MTU;
else
return 0;
} else {
WARN_ONCE(1, "Invalid iface attr");
return 0;
}
switch (param) {
case ISCSI_IFACE_PARAM_DEF_TASKMGMT_TMO:
case ISCSI_IFACE_PARAM_HDRDGST_EN:
case ISCSI_IFACE_PARAM_DATADGST_EN:
case ISCSI_IFACE_PARAM_IMM_DATA_EN:
case ISCSI_IFACE_PARAM_INITIAL_R2T_EN:
case ISCSI_IFACE_PARAM_DATASEQ_INORDER_EN:
case ISCSI_IFACE_PARAM_PDU_INORDER_EN:
case ISCSI_IFACE_PARAM_ERL:
case ISCSI_IFACE_PARAM_MAX_RECV_DLENGTH:
case ISCSI_IFACE_PARAM_FIRST_BURST:
case ISCSI_IFACE_PARAM_MAX_R2T:
case ISCSI_IFACE_PARAM_MAX_BURST:
case ISCSI_IFACE_PARAM_CHAP_AUTH_EN:
case ISCSI_IFACE_PARAM_BIDI_CHAP_EN:
case ISCSI_IFACE_PARAM_DISCOVERY_AUTH_OPTIONAL:
case ISCSI_IFACE_PARAM_DISCOVERY_LOGOUT_EN:
case ISCSI_IFACE_PARAM_STRICT_LOGIN_COMP_EN:
case ISCSI_IFACE_PARAM_INITIATOR_NAME:
param_type = ISCSI_IFACE_PARAM;
break;
default:
param_type = ISCSI_NET_PARAM;
}
return t->attr_is_visible(param_type, param);
}
char *iscsi_get_ipaddress_state_name(enum iscsi_ipaddress_state port_state)
{
int i;
char *state = NULL;
for (i = 0; i < ARRAY_SIZE(iscsi_ipaddress_state_names); i++) {
if (iscsi_ipaddress_state_names[i].value == port_state) {
state = iscsi_ipaddress_state_names[i].name;
break;
}
}
return state;
}
char *iscsi_get_router_state_name(enum iscsi_router_state router_state)
{
int i;
char *state = NULL;
for (i = 0; i < ARRAY_SIZE(iscsi_router_state_names); i++) {
if (iscsi_router_state_names[i].value == router_state) {
state = iscsi_router_state_names[i].name;
break;
}
}
return state;
}
struct iscsi_iface *
iscsi_create_iface(struct Scsi_Host *shost, struct iscsi_transport *transport,
uint32_t iface_type, uint32_t iface_num, int dd_size)
{
struct iscsi_iface *iface;
int err;
iface = kzalloc(sizeof(*iface) + dd_size, GFP_KERNEL);
if (!iface)
return NULL;
iface->transport = transport;
iface->iface_type = iface_type;
iface->iface_num = iface_num;
iface->dev.release = iscsi_iface_release;
iface->dev.class = &iscsi_iface_class;
iface->dev.parent = get_device(&shost->shost_gendev);
if (iface_type == ISCSI_IFACE_TYPE_IPV4)
dev_set_name(&iface->dev, "ipv4-iface-%u-%u", shost->host_no,
iface_num);
else
dev_set_name(&iface->dev, "ipv6-iface-%u-%u", shost->host_no,
iface_num);
err = device_register(&iface->dev);
if (err)
goto free_iface;
err = sysfs_create_group(&iface->dev.kobj, &iscsi_iface_group);
if (err)
goto unreg_iface;
if (dd_size)
iface->dd_data = &iface[1];
return iface;
unreg_iface:
device_unregister(&iface->dev);
return NULL;
free_iface:
put_device(iface->dev.parent);
kfree(iface);
return NULL;
}
void iscsi_destroy_iface(struct iscsi_iface *iface)
{
sysfs_remove_group(&iface->dev.kobj, &iscsi_iface_group);
device_unregister(&iface->dev);
}
static umode_t iscsi_flashnode_sess_attr_is_visible(struct kobject *kobj,
struct attribute *attr,
int i)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct iscsi_bus_flash_session *fnode_sess =
iscsi_dev_to_flash_session(dev);
struct iscsi_transport *t = fnode_sess->transport;
int param;
if (attr == &dev_attr_fnode_auto_snd_tgt_disable.attr) {
param = ISCSI_FLASHNODE_AUTO_SND_TGT_DISABLE;
} else if (attr == &dev_attr_fnode_discovery_session.attr) {
param = ISCSI_FLASHNODE_DISCOVERY_SESS;
} else if (attr == &dev_attr_fnode_portal_type.attr) {
param = ISCSI_FLASHNODE_PORTAL_TYPE;
} else if (attr == &dev_attr_fnode_entry_enable.attr) {
param = ISCSI_FLASHNODE_ENTRY_EN;
} else if (attr == &dev_attr_fnode_immediate_data.attr) {
param = ISCSI_FLASHNODE_IMM_DATA_EN;
} else if (attr == &dev_attr_fnode_initial_r2t.attr) {
param = ISCSI_FLASHNODE_INITIAL_R2T_EN;
} else if (attr == &dev_attr_fnode_data_seq_in_order.attr) {
param = ISCSI_FLASHNODE_DATASEQ_INORDER;
} else if (attr == &dev_attr_fnode_data_pdu_in_order.attr) {
param = ISCSI_FLASHNODE_PDU_INORDER;
} else if (attr == &dev_attr_fnode_chap_auth.attr) {
param = ISCSI_FLASHNODE_CHAP_AUTH_EN;
} else if (attr == &dev_attr_fnode_discovery_logout.attr) {
param = ISCSI_FLASHNODE_DISCOVERY_LOGOUT_EN;
} else if (attr == &dev_attr_fnode_bidi_chap.attr) {
param = ISCSI_FLASHNODE_BIDI_CHAP_EN;
} else if (attr == &dev_attr_fnode_discovery_auth_optional.attr) {
param = ISCSI_FLASHNODE_DISCOVERY_AUTH_OPTIONAL;
} else if (attr == &dev_attr_fnode_erl.attr) {
param = ISCSI_FLASHNODE_ERL;
} else if (attr == &dev_attr_fnode_first_burst_len.attr) {
param = ISCSI_FLASHNODE_FIRST_BURST;
} else if (attr == &dev_attr_fnode_def_time2wait.attr) {
param = ISCSI_FLASHNODE_DEF_TIME2WAIT;
} else if (attr == &dev_attr_fnode_def_time2retain.attr) {
param = ISCSI_FLASHNODE_DEF_TIME2RETAIN;
} else if (attr == &dev_attr_fnode_max_outstanding_r2t.attr) {
param = ISCSI_FLASHNODE_MAX_R2T;
} else if (attr == &dev_attr_fnode_isid.attr) {
param = ISCSI_FLASHNODE_ISID;
} else if (attr == &dev_attr_fnode_tsid.attr) {
param = ISCSI_FLASHNODE_TSID;
} else if (attr == &dev_attr_fnode_max_burst_len.attr) {
param = ISCSI_FLASHNODE_MAX_BURST;
} else if (attr == &dev_attr_fnode_def_taskmgmt_tmo.attr) {
param = ISCSI_FLASHNODE_DEF_TASKMGMT_TMO;
} else if (attr == &dev_attr_fnode_targetalias.attr) {
param = ISCSI_FLASHNODE_ALIAS;
} else if (attr == &dev_attr_fnode_targetname.attr) {
param = ISCSI_FLASHNODE_NAME;
} else if (attr == &dev_attr_fnode_tpgt.attr) {
param = ISCSI_FLASHNODE_TPGT;
} else if (attr == &dev_attr_fnode_discovery_parent_idx.attr) {
param = ISCSI_FLASHNODE_DISCOVERY_PARENT_IDX;
} else if (attr == &dev_attr_fnode_discovery_parent_type.attr) {
param = ISCSI_FLASHNODE_DISCOVERY_PARENT_TYPE;
} else if (attr == &dev_attr_fnode_chap_in_idx.attr) {
param = ISCSI_FLASHNODE_CHAP_IN_IDX;
} else if (attr == &dev_attr_fnode_chap_out_idx.attr) {
param = ISCSI_FLASHNODE_CHAP_OUT_IDX;
} else if (attr == &dev_attr_fnode_username.attr) {
param = ISCSI_FLASHNODE_USERNAME;
} else if (attr == &dev_attr_fnode_username_in.attr) {
param = ISCSI_FLASHNODE_USERNAME_IN;
} else if (attr == &dev_attr_fnode_password.attr) {
param = ISCSI_FLASHNODE_PASSWORD;
} else if (attr == &dev_attr_fnode_password_in.attr) {
param = ISCSI_FLASHNODE_PASSWORD_IN;
} else if (attr == &dev_attr_fnode_is_boot_target.attr) {
param = ISCSI_FLASHNODE_IS_BOOT_TGT;
} else {
WARN_ONCE(1, "Invalid flashnode session attr");
return 0;
}
return t->attr_is_visible(ISCSI_FLASHNODE_PARAM, param);
}
static void iscsi_flashnode_sess_release(struct device *dev)
{
struct iscsi_bus_flash_session *fnode_sess =
iscsi_dev_to_flash_session(dev);
kfree(fnode_sess->targetname);
kfree(fnode_sess->targetalias);
kfree(fnode_sess->portal_type);
kfree(fnode_sess);
}
static umode_t iscsi_flashnode_conn_attr_is_visible(struct kobject *kobj,
struct attribute *attr,
int i)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct iscsi_bus_flash_conn *fnode_conn = iscsi_dev_to_flash_conn(dev);
struct iscsi_transport *t = fnode_conn->transport;
int param;
if (attr == &dev_attr_fnode_is_fw_assigned_ipv6.attr) {
param = ISCSI_FLASHNODE_IS_FW_ASSIGNED_IPV6;
} else if (attr == &dev_attr_fnode_header_digest.attr) {
param = ISCSI_FLASHNODE_HDR_DGST_EN;
} else if (attr == &dev_attr_fnode_data_digest.attr) {
param = ISCSI_FLASHNODE_DATA_DGST_EN;
} else if (attr == &dev_attr_fnode_snack_req.attr) {
param = ISCSI_FLASHNODE_SNACK_REQ_EN;
} else if (attr == &dev_attr_fnode_tcp_timestamp_stat.attr) {
param = ISCSI_FLASHNODE_TCP_TIMESTAMP_STAT;
} else if (attr == &dev_attr_fnode_tcp_nagle_disable.attr) {
param = ISCSI_FLASHNODE_TCP_NAGLE_DISABLE;
} else if (attr == &dev_attr_fnode_tcp_wsf_disable.attr) {
param = ISCSI_FLASHNODE_TCP_WSF_DISABLE;
} else if (attr == &dev_attr_fnode_tcp_timer_scale.attr) {
param = ISCSI_FLASHNODE_TCP_TIMER_SCALE;
} else if (attr == &dev_attr_fnode_tcp_timestamp_enable.attr) {
param = ISCSI_FLASHNODE_TCP_TIMESTAMP_EN;
} else if (attr == &dev_attr_fnode_fragment_disable.attr) {
param = ISCSI_FLASHNODE_IP_FRAG_DISABLE;
} else if (attr == &dev_attr_fnode_max_recv_dlength.attr) {
param = ISCSI_FLASHNODE_MAX_RECV_DLENGTH;
} else if (attr == &dev_attr_fnode_max_xmit_dlength.attr) {
param = ISCSI_FLASHNODE_MAX_XMIT_DLENGTH;
} else if (attr == &dev_attr_fnode_keepalive_tmo.attr) {
param = ISCSI_FLASHNODE_KEEPALIVE_TMO;
} else if (attr == &dev_attr_fnode_port.attr) {
param = ISCSI_FLASHNODE_PORT;
} else if (attr == &dev_attr_fnode_ipaddress.attr) {
param = ISCSI_FLASHNODE_IPADDR;
} else if (attr == &dev_attr_fnode_redirect_ipaddr.attr) {
param = ISCSI_FLASHNODE_REDIRECT_IPADDR;
} else if (attr == &dev_attr_fnode_max_segment_size.attr) {
param = ISCSI_FLASHNODE_MAX_SEGMENT_SIZE;
} else if (attr == &dev_attr_fnode_local_port.attr) {
param = ISCSI_FLASHNODE_LOCAL_PORT;
} else if (attr == &dev_attr_fnode_ipv4_tos.attr) {
param = ISCSI_FLASHNODE_IPV4_TOS;
} else if (attr == &dev_attr_fnode_ipv6_traffic_class.attr) {
param = ISCSI_FLASHNODE_IPV6_TC;
} else if (attr == &dev_attr_fnode_ipv6_flow_label.attr) {
param = ISCSI_FLASHNODE_IPV6_FLOW_LABEL;
} else if (attr == &dev_attr_fnode_link_local_ipv6.attr) {
param = ISCSI_FLASHNODE_LINK_LOCAL_IPV6;
} else if (attr == &dev_attr_fnode_tcp_xmit_wsf.attr) {
param = ISCSI_FLASHNODE_TCP_XMIT_WSF;
} else if (attr == &dev_attr_fnode_tcp_recv_wsf.attr) {
param = ISCSI_FLASHNODE_TCP_RECV_WSF;
} else if (attr == &dev_attr_fnode_statsn.attr) {
param = ISCSI_FLASHNODE_STATSN;
} else if (attr == &dev_attr_fnode_exp_statsn.attr) {
param = ISCSI_FLASHNODE_EXP_STATSN;
} else {
WARN_ONCE(1, "Invalid flashnode connection attr");
return 0;
}
return t->attr_is_visible(ISCSI_FLASHNODE_PARAM, param);
}
static void iscsi_flashnode_conn_release(struct device *dev)
{
struct iscsi_bus_flash_conn *fnode_conn = iscsi_dev_to_flash_conn(dev);
kfree(fnode_conn->ipaddress);
kfree(fnode_conn->redirect_ipaddr);
kfree(fnode_conn->link_local_ipv6_addr);
kfree(fnode_conn);
}
int iscsi_flashnode_bus_match(struct device *dev,
struct device_driver *drv)
{
if (dev->bus == &iscsi_flashnode_bus)
return 1;
return 0;
}
struct iscsi_bus_flash_session *
iscsi_create_flashnode_sess(struct Scsi_Host *shost, int index,
struct iscsi_transport *transport,
int dd_size)
{
struct iscsi_bus_flash_session *fnode_sess;
int err;
fnode_sess = kzalloc(sizeof(*fnode_sess) + dd_size, GFP_KERNEL);
if (!fnode_sess)
return NULL;
fnode_sess->transport = transport;
fnode_sess->target_id = index;
fnode_sess->dev.type = &iscsi_flashnode_sess_dev_type;
fnode_sess->dev.bus = &iscsi_flashnode_bus;
fnode_sess->dev.parent = &shost->shost_gendev;
dev_set_name(&fnode_sess->dev, "flashnode_sess-%u:%u",
shost->host_no, index);
err = device_register(&fnode_sess->dev);
if (err)
goto free_fnode_sess;
if (dd_size)
fnode_sess->dd_data = &fnode_sess[1];
return fnode_sess;
free_fnode_sess:
kfree(fnode_sess);
return NULL;
}
struct iscsi_bus_flash_conn *
iscsi_create_flashnode_conn(struct Scsi_Host *shost,
struct iscsi_bus_flash_session *fnode_sess,
struct iscsi_transport *transport,
int dd_size)
{
struct iscsi_bus_flash_conn *fnode_conn;
int err;
fnode_conn = kzalloc(sizeof(*fnode_conn) + dd_size, GFP_KERNEL);
if (!fnode_conn)
return NULL;
fnode_conn->transport = transport;
fnode_conn->dev.type = &iscsi_flashnode_conn_dev_type;
fnode_conn->dev.bus = &iscsi_flashnode_bus;
fnode_conn->dev.parent = &fnode_sess->dev;
dev_set_name(&fnode_conn->dev, "flashnode_conn-%u:%u:0",
shost->host_no, fnode_sess->target_id);
err = device_register(&fnode_conn->dev);
if (err)
goto free_fnode_conn;
if (dd_size)
fnode_conn->dd_data = &fnode_conn[1];
return fnode_conn;
free_fnode_conn:
kfree(fnode_conn);
return NULL;
}
int iscsi_is_flashnode_conn_dev(struct device *dev, void *data)
{
return dev->bus == &iscsi_flashnode_bus;
}
static int iscsi_destroy_flashnode_conn(struct iscsi_bus_flash_conn *fnode_conn)
{
device_unregister(&fnode_conn->dev);
return 0;
}
static int flashnode_match_index(struct device *dev, void *data)
{
struct iscsi_bus_flash_session *fnode_sess = NULL;
int ret = 0;
if (!iscsi_flashnode_bus_match(dev, NULL))
goto exit_match_index;
fnode_sess = iscsi_dev_to_flash_session(dev);
ret = (fnode_sess->target_id == *((int *)data)) ? 1 : 0;
exit_match_index:
return ret;
}
static struct iscsi_bus_flash_session *
iscsi_get_flashnode_by_index(struct Scsi_Host *shost, uint32_t idx)
{
struct iscsi_bus_flash_session *fnode_sess = NULL;
struct device *dev;
dev = device_find_child(&shost->shost_gendev, &idx,
flashnode_match_index);
if (dev)
fnode_sess = iscsi_dev_to_flash_session(dev);
return fnode_sess;
}
struct device *
iscsi_find_flashnode_sess(struct Scsi_Host *shost, void *data,
int (*fn)(struct device *dev, void *data))
{
return device_find_child(&shost->shost_gendev, data, fn);
}
struct device *
iscsi_find_flashnode_conn(struct iscsi_bus_flash_session *fnode_sess)
{
return device_find_child(&fnode_sess->dev, NULL,
iscsi_is_flashnode_conn_dev);
}
static int iscsi_iter_destroy_flashnode_conn_fn(struct device *dev, void *data)
{
if (!iscsi_is_flashnode_conn_dev(dev, NULL))
return 0;
return iscsi_destroy_flashnode_conn(iscsi_dev_to_flash_conn(dev));
}
void iscsi_destroy_flashnode_sess(struct iscsi_bus_flash_session *fnode_sess)
{
int err;
err = device_for_each_child(&fnode_sess->dev, NULL,
iscsi_iter_destroy_flashnode_conn_fn);
if (err)
pr_err("Could not delete all connections for %s. Error %d.\n",
fnode_sess->dev.kobj.name, err);
device_unregister(&fnode_sess->dev);
}
static int iscsi_iter_destroy_flashnode_fn(struct device *dev, void *data)
{
if (!iscsi_flashnode_bus_match(dev, NULL))
return 0;
iscsi_destroy_flashnode_sess(iscsi_dev_to_flash_session(dev));
return 0;
}
void iscsi_destroy_all_flashnode(struct Scsi_Host *shost)
{
device_for_each_child(&shost->shost_gendev, NULL,
iscsi_iter_destroy_flashnode_fn);
}
static int iscsi_bsg_host_dispatch(struct bsg_job *job)
{
struct Scsi_Host *shost = iscsi_job_to_shost(job);
struct iscsi_bsg_request *req = job->request;
struct iscsi_bsg_reply *reply = job->reply;
struct iscsi_internal *i = to_iscsi_internal(shost->transportt);
int cmdlen = sizeof(uint32_t);
int ret;
if (job->request_len < sizeof(uint32_t)) {
ret = -ENOMSG;
goto fail_host_msg;
}
switch (req->msgcode) {
case ISCSI_BSG_HST_VENDOR:
cmdlen += sizeof(struct iscsi_bsg_host_vendor);
if ((shost->hostt->vendor_id == 0L) ||
(req->rqst_data.h_vendor.vendor_id !=
shost->hostt->vendor_id)) {
ret = -ESRCH;
goto fail_host_msg;
}
break;
default:
ret = -EBADR;
goto fail_host_msg;
}
if (job->request_len < cmdlen) {
ret = -ENOMSG;
goto fail_host_msg;
}
ret = i->iscsi_transport->bsg_request(job);
if (!ret)
return 0;
fail_host_msg:
BUG_ON(job->reply_len < sizeof(uint32_t));
reply->reply_payload_rcv_len = 0;
reply->result = ret;
job->reply_len = sizeof(uint32_t);
bsg_job_done(job, ret, 0);
return 0;
}
static int
iscsi_bsg_host_add(struct Scsi_Host *shost, struct iscsi_cls_host *ihost)
{
struct device *dev = &shost->shost_gendev;
struct iscsi_internal *i = to_iscsi_internal(shost->transportt);
struct request_queue *q;
char bsg_name[20];
int ret;
if (!i->iscsi_transport->bsg_request)
return -ENOTSUPP;
snprintf(bsg_name, sizeof(bsg_name), "iscsi_host%d", shost->host_no);
q = __scsi_alloc_queue(shost, bsg_request_fn);
if (!q)
return -ENOMEM;
ret = bsg_setup_queue(dev, q, bsg_name, iscsi_bsg_host_dispatch, 0);
if (ret) {
shost_printk(KERN_ERR, shost, "bsg interface failed to "
"initialize - no request queue\n");
blk_cleanup_queue(q);
return ret;
}
ihost->bsg_q = q;
return 0;
}
static int iscsi_setup_host(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct iscsi_cls_host *ihost = shost->shost_data;
memset(ihost, 0, sizeof(*ihost));
atomic_set(&ihost->nr_scans, 0);
mutex_init(&ihost->mutex);
iscsi_bsg_host_add(shost, ihost);
return 0;
}
static int iscsi_remove_host(struct transport_container *tc,
struct device *dev, struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct iscsi_cls_host *ihost = shost->shost_data;
if (ihost->bsg_q) {
bsg_unregister_queue(ihost->bsg_q);
blk_cleanup_queue(ihost->bsg_q);
}
return 0;
}
static uint32_t iscsi_conn_get_sid(struct iscsi_cls_conn *conn)
{
struct iscsi_cls_session *sess = iscsi_dev_to_session(conn->dev.parent);
return sess->sid;
}
static struct iscsi_cls_session *iscsi_session_lookup(uint32_t sid)
{
unsigned long flags;
struct iscsi_cls_session *sess;
spin_lock_irqsave(&sesslock, flags);
list_for_each_entry(sess, &sesslist, sess_list) {
if (sess->sid == sid) {
spin_unlock_irqrestore(&sesslock, flags);
return sess;
}
}
spin_unlock_irqrestore(&sesslock, flags);
return NULL;
}
static struct iscsi_cls_conn *iscsi_conn_lookup(uint32_t sid, uint32_t cid)
{
unsigned long flags;
struct iscsi_cls_conn *conn;
spin_lock_irqsave(&connlock, flags);
list_for_each_entry(conn, &connlist, conn_list) {
if ((conn->cid == cid) && (iscsi_conn_get_sid(conn) == sid)) {
spin_unlock_irqrestore(&connlock, flags);
return conn;
}
}
spin_unlock_irqrestore(&connlock, flags);
return NULL;
}
static const char *iscsi_session_state_name(int state)
{
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(iscsi_session_state_names); i++) {
if (iscsi_session_state_names[i].value == state) {
name = iscsi_session_state_names[i].name;
break;
}
}
return name;
}
int iscsi_session_chkready(struct iscsi_cls_session *session)
{
unsigned long flags;
int err;
spin_lock_irqsave(&session->lock, flags);
switch (session->state) {
case ISCSI_SESSION_LOGGED_IN:
err = 0;
break;
case ISCSI_SESSION_FAILED:
err = DID_IMM_RETRY << 16;
break;
case ISCSI_SESSION_FREE:
err = DID_TRANSPORT_FAILFAST << 16;
break;
default:
err = DID_NO_CONNECT << 16;
break;
}
spin_unlock_irqrestore(&session->lock, flags);
return err;
}
int iscsi_is_session_online(struct iscsi_cls_session *session)
{
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&session->lock, flags);
if (session->state == ISCSI_SESSION_LOGGED_IN)
ret = 1;
spin_unlock_irqrestore(&session->lock, flags);
return ret;
}
static void iscsi_session_release(struct device *dev)
{
struct iscsi_cls_session *session = iscsi_dev_to_session(dev);
struct Scsi_Host *shost;
shost = iscsi_session_to_shost(session);
scsi_host_put(shost);
ISCSI_DBG_TRANS_SESSION(session, "Completing session release\n");
kfree(session);
}
int iscsi_is_session_dev(const struct device *dev)
{
return dev->release == iscsi_session_release;
}
static int iscsi_iter_session_fn(struct device *dev, void *data)
{
void (* fn) (struct iscsi_cls_session *) = data;
if (!iscsi_is_session_dev(dev))
return 0;
fn(iscsi_dev_to_session(dev));
return 0;
}
void iscsi_host_for_each_session(struct Scsi_Host *shost,
void (*fn)(struct iscsi_cls_session *))
{
device_for_each_child(&shost->shost_gendev, fn,
iscsi_iter_session_fn);
}
int iscsi_scan_finished(struct Scsi_Host *shost, unsigned long time)
{
struct iscsi_cls_host *ihost = shost->shost_data;
return !atomic_read(&ihost->nr_scans);
}
static int iscsi_user_scan_session(struct device *dev, void *data)
{
struct iscsi_scan_data *scan_data = data;
struct iscsi_cls_session *session;
struct Scsi_Host *shost;
struct iscsi_cls_host *ihost;
unsigned long flags;
unsigned int id;
if (!iscsi_is_session_dev(dev))
return 0;
session = iscsi_dev_to_session(dev);
ISCSI_DBG_TRANS_SESSION(session, "Scanning session\n");
shost = iscsi_session_to_shost(session);
ihost = shost->shost_data;
mutex_lock(&ihost->mutex);
spin_lock_irqsave(&session->lock, flags);
if (session->state != ISCSI_SESSION_LOGGED_IN) {
spin_unlock_irqrestore(&session->lock, flags);
goto user_scan_exit;
}
id = session->target_id;
spin_unlock_irqrestore(&session->lock, flags);
if (id != ISCSI_MAX_TARGET) {
if ((scan_data->channel == SCAN_WILD_CARD ||
scan_data->channel == 0) &&
(scan_data->id == SCAN_WILD_CARD ||
scan_data->id == id))
scsi_scan_target(&session->dev, 0, id,
scan_data->lun, 1);
}
user_scan_exit:
mutex_unlock(&ihost->mutex);
ISCSI_DBG_TRANS_SESSION(session, "Completed session scan\n");
return 0;
}
static int iscsi_user_scan(struct Scsi_Host *shost, uint channel,
uint id, u64 lun)
{
struct iscsi_scan_data scan_data;
scan_data.channel = channel;
scan_data.id = id;
scan_data.lun = lun;
return device_for_each_child(&shost->shost_gendev, &scan_data,
iscsi_user_scan_session);
}
static void iscsi_scan_session(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session, scan_work);
struct Scsi_Host *shost = iscsi_session_to_shost(session);
struct iscsi_cls_host *ihost = shost->shost_data;
struct iscsi_scan_data scan_data;
scan_data.channel = 0;
scan_data.id = SCAN_WILD_CARD;
scan_data.lun = SCAN_WILD_CARD;
iscsi_user_scan_session(&session->dev, &scan_data);
atomic_dec(&ihost->nr_scans);
}
int iscsi_block_scsi_eh(struct scsi_cmnd *cmd)
{
struct iscsi_cls_session *session =
starget_to_session(scsi_target(cmd->device));
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&session->lock, flags);
while (session->state != ISCSI_SESSION_LOGGED_IN) {
if (session->state == ISCSI_SESSION_FREE) {
ret = FAST_IO_FAIL;
break;
}
spin_unlock_irqrestore(&session->lock, flags);
msleep(1000);
spin_lock_irqsave(&session->lock, flags);
}
spin_unlock_irqrestore(&session->lock, flags);
return ret;
}
static void session_recovery_timedout(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session,
recovery_work.work);
unsigned long flags;
iscsi_cls_session_printk(KERN_INFO, session,
"session recovery timed out after %d secs\n",
session->recovery_tmo);
spin_lock_irqsave(&session->lock, flags);
switch (session->state) {
case ISCSI_SESSION_FAILED:
session->state = ISCSI_SESSION_FREE;
break;
case ISCSI_SESSION_LOGGED_IN:
case ISCSI_SESSION_FREE:
spin_unlock_irqrestore(&session->lock, flags);
return;
}
spin_unlock_irqrestore(&session->lock, flags);
if (session->transport->session_recovery_timedout)
session->transport->session_recovery_timedout(session);
ISCSI_DBG_TRANS_SESSION(session, "Unblocking SCSI target\n");
scsi_target_unblock(&session->dev, SDEV_TRANSPORT_OFFLINE);
ISCSI_DBG_TRANS_SESSION(session, "Completed unblocking SCSI target\n");
}
static void __iscsi_unblock_session(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session,
unblock_work);
struct Scsi_Host *shost = iscsi_session_to_shost(session);
struct iscsi_cls_host *ihost = shost->shost_data;
unsigned long flags;
ISCSI_DBG_TRANS_SESSION(session, "Unblocking session\n");
cancel_delayed_work(&session->recovery_work);
spin_lock_irqsave(&session->lock, flags);
session->state = ISCSI_SESSION_LOGGED_IN;
spin_unlock_irqrestore(&session->lock, flags);
scsi_target_unblock(&session->dev, SDEV_RUNNING);
if (shost->hostt->scan_finished) {
if (scsi_queue_work(shost, &session->scan_work))
atomic_inc(&ihost->nr_scans);
}
ISCSI_DBG_TRANS_SESSION(session, "Completed unblocking session\n");
}
void iscsi_unblock_session(struct iscsi_cls_session *session)
{
queue_work(iscsi_eh_timer_workq, &session->unblock_work);
flush_workqueue(iscsi_eh_timer_workq);
}
static void __iscsi_block_session(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session,
block_work);
unsigned long flags;
ISCSI_DBG_TRANS_SESSION(session, "Blocking session\n");
spin_lock_irqsave(&session->lock, flags);
session->state = ISCSI_SESSION_FAILED;
spin_unlock_irqrestore(&session->lock, flags);
scsi_target_block(&session->dev);
ISCSI_DBG_TRANS_SESSION(session, "Completed SCSI target blocking\n");
if (session->recovery_tmo >= 0)
queue_delayed_work(iscsi_eh_timer_workq,
&session->recovery_work,
session->recovery_tmo * HZ);
}
void iscsi_block_session(struct iscsi_cls_session *session)
{
queue_work(iscsi_eh_timer_workq, &session->block_work);
}
static void __iscsi_unbind_session(struct work_struct *work)
{
struct iscsi_cls_session *session =
container_of(work, struct iscsi_cls_session,
unbind_work);
struct Scsi_Host *shost = iscsi_session_to_shost(session);
struct iscsi_cls_host *ihost = shost->shost_data;
unsigned long flags;
unsigned int target_id;
ISCSI_DBG_TRANS_SESSION(session, "Unbinding session\n");
mutex_lock(&ihost->mutex);
spin_lock_irqsave(&session->lock, flags);
if (session->target_id == ISCSI_MAX_TARGET) {
spin_unlock_irqrestore(&session->lock, flags);
mutex_unlock(&ihost->mutex);
return;
}
target_id = session->target_id;
session->target_id = ISCSI_MAX_TARGET;
spin_unlock_irqrestore(&session->lock, flags);
mutex_unlock(&ihost->mutex);
if (session->ida_used)
ida_simple_remove(&iscsi_sess_ida, target_id);
scsi_remove_target(&session->dev);
iscsi_session_event(session, ISCSI_KEVENT_UNBIND_SESSION);
ISCSI_DBG_TRANS_SESSION(session, "Completed target removal\n");
}
struct iscsi_cls_session *
iscsi_alloc_session(struct Scsi_Host *shost, struct iscsi_transport *transport,
int dd_size)
{
struct iscsi_cls_session *session;
session = kzalloc(sizeof(*session) + dd_size,
GFP_KERNEL);
if (!session)
return NULL;
session->transport = transport;
session->creator = -1;
session->recovery_tmo = 120;
session->state = ISCSI_SESSION_FREE;
INIT_DELAYED_WORK(&session->recovery_work, session_recovery_timedout);
INIT_LIST_HEAD(&session->sess_list);
INIT_WORK(&session->unblock_work, __iscsi_unblock_session);
INIT_WORK(&session->block_work, __iscsi_block_session);
INIT_WORK(&session->unbind_work, __iscsi_unbind_session);
INIT_WORK(&session->scan_work, iscsi_scan_session);
spin_lock_init(&session->lock);
scsi_host_get(shost);
session->dev.parent = &shost->shost_gendev;
session->dev.release = iscsi_session_release;
device_initialize(&session->dev);
if (dd_size)
session->dd_data = &session[1];
ISCSI_DBG_TRANS_SESSION(session, "Completed session allocation\n");
return session;
}
int iscsi_add_session(struct iscsi_cls_session *session, unsigned int target_id)
{
struct Scsi_Host *shost = iscsi_session_to_shost(session);
struct iscsi_cls_host *ihost;
unsigned long flags;
int id = 0;
int err;
ihost = shost->shost_data;
session->sid = atomic_add_return(1, &iscsi_session_nr);
if (target_id == ISCSI_MAX_TARGET) {
id = ida_simple_get(&iscsi_sess_ida, 0, 0, GFP_KERNEL);
if (id < 0) {
iscsi_cls_session_printk(KERN_ERR, session,
"Failure in Target ID Allocation\n");
return id;
}
session->target_id = (unsigned int)id;
session->ida_used = true;
} else
session->target_id = target_id;
dev_set_name(&session->dev, "session%u", session->sid);
err = device_add(&session->dev);
if (err) {
iscsi_cls_session_printk(KERN_ERR, session,
"could not register session's dev\n");
goto release_ida;
}
transport_register_device(&session->dev);
spin_lock_irqsave(&sesslock, flags);
list_add(&session->sess_list, &sesslist);
spin_unlock_irqrestore(&sesslock, flags);
iscsi_session_event(session, ISCSI_KEVENT_CREATE_SESSION);
ISCSI_DBG_TRANS_SESSION(session, "Completed session adding\n");
return 0;
release_ida:
if (session->ida_used)
ida_simple_remove(&iscsi_sess_ida, session->target_id);
return err;
}
struct iscsi_cls_session *
iscsi_create_session(struct Scsi_Host *shost, struct iscsi_transport *transport,
int dd_size, unsigned int target_id)
{
struct iscsi_cls_session *session;
session = iscsi_alloc_session(shost, transport, dd_size);
if (!session)
return NULL;
if (iscsi_add_session(session, target_id)) {
iscsi_free_session(session);
return NULL;
}
return session;
}
static void iscsi_conn_release(struct device *dev)
{
struct iscsi_cls_conn *conn = iscsi_dev_to_conn(dev);
struct device *parent = conn->dev.parent;
ISCSI_DBG_TRANS_CONN(conn, "Releasing conn\n");
kfree(conn);
put_device(parent);
}
static int iscsi_is_conn_dev(const struct device *dev)
{
return dev->release == iscsi_conn_release;
}
static int iscsi_iter_destroy_conn_fn(struct device *dev, void *data)
{
if (!iscsi_is_conn_dev(dev))
return 0;
return iscsi_destroy_conn(iscsi_dev_to_conn(dev));
}
void iscsi_remove_session(struct iscsi_cls_session *session)
{
struct Scsi_Host *shost = iscsi_session_to_shost(session);
unsigned long flags;
int err;
ISCSI_DBG_TRANS_SESSION(session, "Removing session\n");
spin_lock_irqsave(&sesslock, flags);
list_del(&session->sess_list);
spin_unlock_irqrestore(&sesslock, flags);
flush_workqueue(iscsi_eh_timer_workq);
if (!cancel_delayed_work(&session->recovery_work))
flush_workqueue(iscsi_eh_timer_workq);
spin_lock_irqsave(&session->lock, flags);
session->state = ISCSI_SESSION_FREE;
spin_unlock_irqrestore(&session->lock, flags);
scsi_target_unblock(&session->dev, SDEV_TRANSPORT_OFFLINE);
scsi_flush_work(shost);
__iscsi_unbind_session(&session->unbind_work);
err = device_for_each_child(&session->dev, NULL,
iscsi_iter_destroy_conn_fn);
if (err)
iscsi_cls_session_printk(KERN_ERR, session,
"Could not delete all connections "
"for session. Error %d.\n", err);
transport_unregister_device(&session->dev);
ISCSI_DBG_TRANS_SESSION(session, "Completing session removal\n");
device_del(&session->dev);
}
void iscsi_free_session(struct iscsi_cls_session *session)
{
ISCSI_DBG_TRANS_SESSION(session, "Freeing session\n");
iscsi_session_event(session, ISCSI_KEVENT_DESTROY_SESSION);
put_device(&session->dev);
}
int iscsi_destroy_session(struct iscsi_cls_session *session)
{
iscsi_remove_session(session);
ISCSI_DBG_TRANS_SESSION(session, "Completing session destruction\n");
iscsi_free_session(session);
return 0;
}
struct iscsi_cls_conn *
iscsi_create_conn(struct iscsi_cls_session *session, int dd_size, uint32_t cid)
{
struct iscsi_transport *transport = session->transport;
struct iscsi_cls_conn *conn;
unsigned long flags;
int err;
conn = kzalloc(sizeof(*conn) + dd_size, GFP_KERNEL);
if (!conn)
return NULL;
if (dd_size)
conn->dd_data = &conn[1];
mutex_init(&conn->ep_mutex);
INIT_LIST_HEAD(&conn->conn_list);
conn->transport = transport;
conn->cid = cid;
if (!get_device(&session->dev))
goto free_conn;
dev_set_name(&conn->dev, "connection%d:%u", session->sid, cid);
conn->dev.parent = &session->dev;
conn->dev.release = iscsi_conn_release;
err = device_register(&conn->dev);
if (err) {
iscsi_cls_session_printk(KERN_ERR, session, "could not "
"register connection's dev\n");
goto release_parent_ref;
}
transport_register_device(&conn->dev);
spin_lock_irqsave(&connlock, flags);
list_add(&conn->conn_list, &connlist);
spin_unlock_irqrestore(&connlock, flags);
ISCSI_DBG_TRANS_CONN(conn, "Completed conn creation\n");
return conn;
release_parent_ref:
put_device(&session->dev);
free_conn:
kfree(conn);
return NULL;
}
int iscsi_destroy_conn(struct iscsi_cls_conn *conn)
{
unsigned long flags;
spin_lock_irqsave(&connlock, flags);
list_del(&conn->conn_list);
spin_unlock_irqrestore(&connlock, flags);
transport_unregister_device(&conn->dev);
ISCSI_DBG_TRANS_CONN(conn, "Completing conn destruction\n");
device_unregister(&conn->dev);
return 0;
}
static struct iscsi_internal *
iscsi_if_transport_lookup(struct iscsi_transport *tt)
{
struct iscsi_internal *priv;
unsigned long flags;
spin_lock_irqsave(&iscsi_transport_lock, flags);
list_for_each_entry(priv, &iscsi_transports, list) {
if (tt == priv->iscsi_transport) {
spin_unlock_irqrestore(&iscsi_transport_lock, flags);
return priv;
}
}
spin_unlock_irqrestore(&iscsi_transport_lock, flags);
return NULL;
}
static int
iscsi_multicast_skb(struct sk_buff *skb, uint32_t group, gfp_t gfp)
{
return nlmsg_multicast(nls, skb, 0, group, gfp);
}
int iscsi_recv_pdu(struct iscsi_cls_conn *conn, struct iscsi_hdr *hdr,
char *data, uint32_t data_size)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
char *pdu;
struct iscsi_internal *priv;
int len = nlmsg_total_size(sizeof(*ev) + sizeof(struct iscsi_hdr) +
data_size);
priv = iscsi_if_transport_lookup(conn->transport);
if (!priv)
return -EINVAL;
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
iscsi_conn_error_event(conn, ISCSI_ERR_CONN_FAILED);
iscsi_cls_conn_printk(KERN_ERR, conn, "can not deliver "
"control PDU: OOM\n");
return -ENOMEM;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = nlmsg_data(nlh);
memset(ev, 0, sizeof(*ev));
ev->transport_handle = iscsi_handle(conn->transport);
ev->type = ISCSI_KEVENT_RECV_PDU;
ev->r.recv_req.cid = conn->cid;
ev->r.recv_req.sid = iscsi_conn_get_sid(conn);
pdu = (char*)ev + sizeof(*ev);
memcpy(pdu, hdr, sizeof(struct iscsi_hdr));
memcpy(pdu + sizeof(struct iscsi_hdr), data, data_size);
return iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_ATOMIC);
}
int iscsi_offload_mesg(struct Scsi_Host *shost,
struct iscsi_transport *transport, uint32_t type,
char *data, uint16_t data_size)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
int len = nlmsg_total_size(sizeof(*ev) + data_size);
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
printk(KERN_ERR "can not deliver iscsi offload message:OOM\n");
return -ENOMEM;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = nlmsg_data(nlh);
memset(ev, 0, sizeof(*ev));
ev->type = type;
ev->transport_handle = iscsi_handle(transport);
switch (type) {
case ISCSI_KEVENT_PATH_REQ:
ev->r.req_path.host_no = shost->host_no;
break;
case ISCSI_KEVENT_IF_DOWN:
ev->r.notify_if_down.host_no = shost->host_no;
break;
}
memcpy((char *)ev + sizeof(*ev), data, data_size);
return iscsi_multicast_skb(skb, ISCSI_NL_GRP_UIP, GFP_ATOMIC);
}
void iscsi_conn_error_event(struct iscsi_cls_conn *conn, enum iscsi_err error)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
struct iscsi_internal *priv;
int len = nlmsg_total_size(sizeof(*ev));
priv = iscsi_if_transport_lookup(conn->transport);
if (!priv)
return;
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
iscsi_cls_conn_printk(KERN_ERR, conn, "gracefully ignored "
"conn error (%d)\n", error);
return;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = nlmsg_data(nlh);
ev->transport_handle = iscsi_handle(conn->transport);
ev->type = ISCSI_KEVENT_CONN_ERROR;
ev->r.connerror.error = error;
ev->r.connerror.cid = conn->cid;
ev->r.connerror.sid = iscsi_conn_get_sid(conn);
iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_ATOMIC);
iscsi_cls_conn_printk(KERN_INFO, conn, "detected conn error (%d)\n",
error);
}
void iscsi_conn_login_event(struct iscsi_cls_conn *conn,
enum iscsi_conn_state state)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
struct iscsi_internal *priv;
int len = nlmsg_total_size(sizeof(*ev));
priv = iscsi_if_transport_lookup(conn->transport);
if (!priv)
return;
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
iscsi_cls_conn_printk(KERN_ERR, conn, "gracefully ignored "
"conn login (%d)\n", state);
return;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = nlmsg_data(nlh);
ev->transport_handle = iscsi_handle(conn->transport);
ev->type = ISCSI_KEVENT_CONN_LOGIN_STATE;
ev->r.conn_login.state = state;
ev->r.conn_login.cid = conn->cid;
ev->r.conn_login.sid = iscsi_conn_get_sid(conn);
iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_ATOMIC);
iscsi_cls_conn_printk(KERN_INFO, conn, "detected conn login (%d)\n",
state);
}
void iscsi_post_host_event(uint32_t host_no, struct iscsi_transport *transport,
enum iscsi_host_event_code code, uint32_t data_size,
uint8_t *data)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
int len = nlmsg_total_size(sizeof(*ev) + data_size);
skb = alloc_skb(len, GFP_NOIO);
if (!skb) {
printk(KERN_ERR "gracefully ignored host event (%d):%d OOM\n",
host_no, code);
return;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = nlmsg_data(nlh);
ev->transport_handle = iscsi_handle(transport);
ev->type = ISCSI_KEVENT_HOST_EVENT;
ev->r.host_event.host_no = host_no;
ev->r.host_event.code = code;
ev->r.host_event.data_size = data_size;
if (data_size)
memcpy((char *)ev + sizeof(*ev), data, data_size);
iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_NOIO);
}
void iscsi_ping_comp_event(uint32_t host_no, struct iscsi_transport *transport,
uint32_t status, uint32_t pid, uint32_t data_size,
uint8_t *data)
{
struct nlmsghdr *nlh;
struct sk_buff *skb;
struct iscsi_uevent *ev;
int len = nlmsg_total_size(sizeof(*ev) + data_size);
skb = alloc_skb(len, GFP_NOIO);
if (!skb) {
printk(KERN_ERR "gracefully ignored ping comp: OOM\n");
return;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = nlmsg_data(nlh);
ev->transport_handle = iscsi_handle(transport);
ev->type = ISCSI_KEVENT_PING_COMP;
ev->r.ping_comp.host_no = host_no;
ev->r.ping_comp.status = status;
ev->r.ping_comp.pid = pid;
ev->r.ping_comp.data_size = data_size;
memcpy((char *)ev + sizeof(*ev), data, data_size);
iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_NOIO);
}
static int
iscsi_if_send_reply(uint32_t group, int seq, int type, int done, int multi,
void *payload, int size)
{
struct sk_buff *skb;
struct nlmsghdr *nlh;
int len = nlmsg_total_size(size);
int flags = multi ? NLM_F_MULTI : 0;
int t = done ? NLMSG_DONE : type;
skb = alloc_skb(len, GFP_ATOMIC);
if (!skb) {
printk(KERN_ERR "Could not allocate skb to send reply.\n");
return -ENOMEM;
}
nlh = __nlmsg_put(skb, 0, 0, t, (len - sizeof(*nlh)), 0);
nlh->nlmsg_flags = flags;
memcpy(nlmsg_data(nlh), payload, size);
return iscsi_multicast_skb(skb, group, GFP_ATOMIC);
}
static int
iscsi_if_get_stats(struct iscsi_transport *transport, struct nlmsghdr *nlh)
{
struct iscsi_uevent *ev = nlmsg_data(nlh);
struct iscsi_stats *stats;
struct sk_buff *skbstat;
struct iscsi_cls_conn *conn;
struct nlmsghdr *nlhstat;
struct iscsi_uevent *evstat;
struct iscsi_internal *priv;
int len = nlmsg_total_size(sizeof(*ev) +
sizeof(struct iscsi_stats) +
sizeof(struct iscsi_stats_custom) *
ISCSI_STATS_CUSTOM_MAX);
int err = 0;
priv = iscsi_if_transport_lookup(transport);
if (!priv)
return -EINVAL;
conn = iscsi_conn_lookup(ev->u.get_stats.sid, ev->u.get_stats.cid);
if (!conn)
return -EEXIST;
do {
int actual_size;
skbstat = alloc_skb(len, GFP_ATOMIC);
if (!skbstat) {
iscsi_cls_conn_printk(KERN_ERR, conn, "can not "
"deliver stats: OOM\n");
return -ENOMEM;
}
nlhstat = __nlmsg_put(skbstat, 0, 0, 0,
(len - sizeof(*nlhstat)), 0);
evstat = nlmsg_data(nlhstat);
memset(evstat, 0, sizeof(*evstat));
evstat->transport_handle = iscsi_handle(conn->transport);
evstat->type = nlh->nlmsg_type;
evstat->u.get_stats.cid =
ev->u.get_stats.cid;
evstat->u.get_stats.sid =
ev->u.get_stats.sid;
stats = (struct iscsi_stats *)
((char*)evstat + sizeof(*evstat));
memset(stats, 0, sizeof(*stats));
transport->get_stats(conn, stats);
actual_size = nlmsg_total_size(sizeof(struct iscsi_uevent) +
sizeof(struct iscsi_stats) +
sizeof(struct iscsi_stats_custom) *
stats->custom_length);
actual_size -= sizeof(*nlhstat);
actual_size = nlmsg_msg_size(actual_size);
skb_trim(skbstat, NLMSG_ALIGN(actual_size));
nlhstat->nlmsg_len = actual_size;
err = iscsi_multicast_skb(skbstat, ISCSI_NL_GRP_ISCSID,
GFP_ATOMIC);
} while (err < 0 && err != -ECONNREFUSED);
return err;
}
int iscsi_session_event(struct iscsi_cls_session *session,
enum iscsi_uevent_e event)
{
struct iscsi_internal *priv;
struct Scsi_Host *shost;
struct iscsi_uevent *ev;
struct sk_buff *skb;
struct nlmsghdr *nlh;
int rc, len = nlmsg_total_size(sizeof(*ev));
priv = iscsi_if_transport_lookup(session->transport);
if (!priv)
return -EINVAL;
shost = iscsi_session_to_shost(session);
skb = alloc_skb(len, GFP_KERNEL);
if (!skb) {
iscsi_cls_session_printk(KERN_ERR, session,
"Cannot notify userspace of session "
"event %u\n", event);
return -ENOMEM;
}
nlh = __nlmsg_put(skb, 0, 0, 0, (len - sizeof(*nlh)), 0);
ev = nlmsg_data(nlh);
ev->transport_handle = iscsi_handle(session->transport);
ev->type = event;
switch (event) {
case ISCSI_KEVENT_DESTROY_SESSION:
ev->r.d_session.host_no = shost->host_no;
ev->r.d_session.sid = session->sid;
break;
case ISCSI_KEVENT_CREATE_SESSION:
ev->r.c_session_ret.host_no = shost->host_no;
ev->r.c_session_ret.sid = session->sid;
break;
case ISCSI_KEVENT_UNBIND_SESSION:
ev->r.unbind_session.host_no = shost->host_no;
ev->r.unbind_session.sid = session->sid;
break;
default:
iscsi_cls_session_printk(KERN_ERR, session, "Invalid event "
"%u.\n", event);
kfree_skb(skb);
return -EINVAL;
}
rc = iscsi_multicast_skb(skb, ISCSI_NL_GRP_ISCSID, GFP_KERNEL);
if (rc == -ESRCH)
iscsi_cls_session_printk(KERN_ERR, session,
"Cannot notify userspace of session "
"event %u. Check iscsi daemon\n",
event);
ISCSI_DBG_TRANS_SESSION(session, "Completed handling event %d rc %d\n",
event, rc);
return rc;
}
static int
iscsi_if_create_session(struct iscsi_internal *priv, struct iscsi_endpoint *ep,
struct iscsi_uevent *ev, pid_t pid,
uint32_t initial_cmdsn, uint16_t cmds_max,
uint16_t queue_depth)
{
struct iscsi_transport *transport = priv->iscsi_transport;
struct iscsi_cls_session *session;
struct Scsi_Host *shost;
session = transport->create_session(ep, cmds_max, queue_depth,
initial_cmdsn);
if (!session)
return -ENOMEM;
session->creator = pid;
shost = iscsi_session_to_shost(session);
ev->r.c_session_ret.host_no = shost->host_no;
ev->r.c_session_ret.sid = session->sid;
ISCSI_DBG_TRANS_SESSION(session,
"Completed creating transport session\n");
return 0;
}
static int
iscsi_if_create_conn(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
struct iscsi_cls_conn *conn;
struct iscsi_cls_session *session;
session = iscsi_session_lookup(ev->u.c_conn.sid);
if (!session) {
printk(KERN_ERR "iscsi: invalid session %d.\n",
ev->u.c_conn.sid);
return -EINVAL;
}
conn = transport->create_conn(session, ev->u.c_conn.cid);
if (!conn) {
iscsi_cls_session_printk(KERN_ERR, session,
"couldn't create a new connection.");
return -ENOMEM;
}
ev->r.c_conn_ret.sid = session->sid;
ev->r.c_conn_ret.cid = conn->cid;
ISCSI_DBG_TRANS_CONN(conn, "Completed creating transport conn\n");
return 0;
}
static int
iscsi_if_destroy_conn(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
struct iscsi_cls_conn *conn;
conn = iscsi_conn_lookup(ev->u.d_conn.sid, ev->u.d_conn.cid);
if (!conn)
return -EINVAL;
ISCSI_DBG_TRANS_CONN(conn, "Destroying transport conn\n");
if (transport->destroy_conn)
transport->destroy_conn(conn);
return 0;
}
static int
iscsi_set_param(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
char *data = (char*)ev + sizeof(*ev);
struct iscsi_cls_conn *conn;
struct iscsi_cls_session *session;
int err = 0, value = 0;
session = iscsi_session_lookup(ev->u.set_param.sid);
conn = iscsi_conn_lookup(ev->u.set_param.sid, ev->u.set_param.cid);
if (!conn || !session)
return -EINVAL;
switch (ev->u.set_param.param) {
case ISCSI_PARAM_SESS_RECOVERY_TMO:
sscanf(data, "%d", &value);
session->recovery_tmo = value;
break;
default:
err = transport->set_param(conn, ev->u.set_param.param,
data, ev->u.set_param.len);
}
return err;
}
static int iscsi_if_ep_connect(struct iscsi_transport *transport,
struct iscsi_uevent *ev, int msg_type)
{
struct iscsi_endpoint *ep;
struct sockaddr *dst_addr;
struct Scsi_Host *shost = NULL;
int non_blocking, err = 0;
if (!transport->ep_connect)
return -EINVAL;
if (msg_type == ISCSI_UEVENT_TRANSPORT_EP_CONNECT_THROUGH_HOST) {
shost = scsi_host_lookup(ev->u.ep_connect_through_host.host_no);
if (!shost) {
printk(KERN_ERR "ep connect failed. Could not find "
"host no %u\n",
ev->u.ep_connect_through_host.host_no);
return -ENODEV;
}
non_blocking = ev->u.ep_connect_through_host.non_blocking;
} else
non_blocking = ev->u.ep_connect.non_blocking;
dst_addr = (struct sockaddr *)((char*)ev + sizeof(*ev));
ep = transport->ep_connect(shost, dst_addr, non_blocking);
if (IS_ERR(ep)) {
err = PTR_ERR(ep);
goto release_host;
}
ev->r.ep_connect_ret.handle = ep->id;
release_host:
if (shost)
scsi_host_put(shost);
return err;
}
static int iscsi_if_ep_disconnect(struct iscsi_transport *transport,
u64 ep_handle)
{
struct iscsi_cls_conn *conn;
struct iscsi_endpoint *ep;
if (!transport->ep_disconnect)
return -EINVAL;
ep = iscsi_lookup_endpoint(ep_handle);
if (!ep)
return -EINVAL;
conn = ep->conn;
if (conn) {
mutex_lock(&conn->ep_mutex);
conn->ep = NULL;
mutex_unlock(&conn->ep_mutex);
}
transport->ep_disconnect(ep);
return 0;
}
static int
iscsi_if_transport_ep(struct iscsi_transport *transport,
struct iscsi_uevent *ev, int msg_type)
{
struct iscsi_endpoint *ep;
int rc = 0;
switch (msg_type) {
case ISCSI_UEVENT_TRANSPORT_EP_CONNECT_THROUGH_HOST:
case ISCSI_UEVENT_TRANSPORT_EP_CONNECT:
rc = iscsi_if_ep_connect(transport, ev, msg_type);
break;
case ISCSI_UEVENT_TRANSPORT_EP_POLL:
if (!transport->ep_poll)
return -EINVAL;
ep = iscsi_lookup_endpoint(ev->u.ep_poll.ep_handle);
if (!ep)
return -EINVAL;
ev->r.retcode = transport->ep_poll(ep,
ev->u.ep_poll.timeout_ms);
break;
case ISCSI_UEVENT_TRANSPORT_EP_DISCONNECT:
rc = iscsi_if_ep_disconnect(transport,
ev->u.ep_disconnect.ep_handle);
break;
}
return rc;
}
static int
iscsi_tgt_dscvr(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct sockaddr *dst_addr;
int err;
if (!transport->tgt_dscvr)
return -EINVAL;
shost = scsi_host_lookup(ev->u.tgt_dscvr.host_no);
if (!shost) {
printk(KERN_ERR "target discovery could not find host no %u\n",
ev->u.tgt_dscvr.host_no);
return -ENODEV;
}
dst_addr = (struct sockaddr *)((char*)ev + sizeof(*ev));
err = transport->tgt_dscvr(shost, ev->u.tgt_dscvr.type,
ev->u.tgt_dscvr.enable, dst_addr);
scsi_host_put(shost);
return err;
}
static int
iscsi_set_host_param(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
char *data = (char*)ev + sizeof(*ev);
struct Scsi_Host *shost;
int err;
if (!transport->set_host_param)
return -ENOSYS;
shost = scsi_host_lookup(ev->u.set_host_param.host_no);
if (!shost) {
printk(KERN_ERR "set_host_param could not find host no %u\n",
ev->u.set_host_param.host_no);
return -ENODEV;
}
err = transport->set_host_param(shost, ev->u.set_host_param.param,
data, ev->u.set_host_param.len);
scsi_host_put(shost);
return err;
}
static int
iscsi_set_path(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct iscsi_path *params;
int err;
if (!transport->set_path)
return -ENOSYS;
shost = scsi_host_lookup(ev->u.set_path.host_no);
if (!shost) {
printk(KERN_ERR "set path could not find host no %u\n",
ev->u.set_path.host_no);
return -ENODEV;
}
params = (struct iscsi_path *)((char *)ev + sizeof(*ev));
err = transport->set_path(shost, params);
scsi_host_put(shost);
return err;
}
static int
iscsi_set_iface_params(struct iscsi_transport *transport,
struct iscsi_uevent *ev, uint32_t len)
{
char *data = (char *)ev + sizeof(*ev);
struct Scsi_Host *shost;
int err;
if (!transport->set_iface_param)
return -ENOSYS;
shost = scsi_host_lookup(ev->u.set_iface_params.host_no);
if (!shost) {
printk(KERN_ERR "set_iface_params could not find host no %u\n",
ev->u.set_iface_params.host_no);
return -ENODEV;
}
err = transport->set_iface_param(shost, data, len);
scsi_host_put(shost);
return err;
}
static int
iscsi_send_ping(struct iscsi_transport *transport, struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct sockaddr *dst_addr;
int err;
if (!transport->send_ping)
return -ENOSYS;
shost = scsi_host_lookup(ev->u.iscsi_ping.host_no);
if (!shost) {
printk(KERN_ERR "iscsi_ping could not find host no %u\n",
ev->u.iscsi_ping.host_no);
return -ENODEV;
}
dst_addr = (struct sockaddr *)((char *)ev + sizeof(*ev));
err = transport->send_ping(shost, ev->u.iscsi_ping.iface_num,
ev->u.iscsi_ping.iface_type,
ev->u.iscsi_ping.payload_size,
ev->u.iscsi_ping.pid,
dst_addr);
scsi_host_put(shost);
return err;
}
static int
iscsi_get_chap(struct iscsi_transport *transport, struct nlmsghdr *nlh)
{
struct iscsi_uevent *ev = nlmsg_data(nlh);
struct Scsi_Host *shost = NULL;
struct iscsi_chap_rec *chap_rec;
struct iscsi_internal *priv;
struct sk_buff *skbchap;
struct nlmsghdr *nlhchap;
struct iscsi_uevent *evchap;
uint32_t chap_buf_size;
int len, err = 0;
char *buf;
if (!transport->get_chap)
return -EINVAL;
priv = iscsi_if_transport_lookup(transport);
if (!priv)
return -EINVAL;
chap_buf_size = (ev->u.get_chap.num_entries * sizeof(*chap_rec));
len = nlmsg_total_size(sizeof(*ev) + chap_buf_size);
shost = scsi_host_lookup(ev->u.get_chap.host_no);
if (!shost) {
printk(KERN_ERR "%s: failed. Cound not find host no %u\n",
__func__, ev->u.get_chap.host_no);
return -ENODEV;
}
do {
int actual_size;
skbchap = alloc_skb(len, GFP_KERNEL);
if (!skbchap) {
printk(KERN_ERR "can not deliver chap: OOM\n");
err = -ENOMEM;
goto exit_get_chap;
}
nlhchap = __nlmsg_put(skbchap, 0, 0, 0,
(len - sizeof(*nlhchap)), 0);
evchap = nlmsg_data(nlhchap);
memset(evchap, 0, sizeof(*evchap));
evchap->transport_handle = iscsi_handle(transport);
evchap->type = nlh->nlmsg_type;
evchap->u.get_chap.host_no = ev->u.get_chap.host_no;
evchap->u.get_chap.chap_tbl_idx = ev->u.get_chap.chap_tbl_idx;
evchap->u.get_chap.num_entries = ev->u.get_chap.num_entries;
buf = (char *)evchap + sizeof(*evchap);
memset(buf, 0, chap_buf_size);
err = transport->get_chap(shost, ev->u.get_chap.chap_tbl_idx,
&evchap->u.get_chap.num_entries, buf);
actual_size = nlmsg_total_size(sizeof(*ev) + chap_buf_size);
skb_trim(skbchap, NLMSG_ALIGN(actual_size));
nlhchap->nlmsg_len = actual_size;
err = iscsi_multicast_skb(skbchap, ISCSI_NL_GRP_ISCSID,
GFP_KERNEL);
} while (err < 0 && err != -ECONNREFUSED);
exit_get_chap:
scsi_host_put(shost);
return err;
}
static int iscsi_set_chap(struct iscsi_transport *transport,
struct iscsi_uevent *ev, uint32_t len)
{
char *data = (char *)ev + sizeof(*ev);
struct Scsi_Host *shost;
int err = 0;
if (!transport->set_chap)
return -ENOSYS;
shost = scsi_host_lookup(ev->u.set_path.host_no);
if (!shost) {
pr_err("%s could not find host no %u\n",
__func__, ev->u.set_path.host_no);
return -ENODEV;
}
err = transport->set_chap(shost, data, len);
scsi_host_put(shost);
return err;
}
static int iscsi_delete_chap(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
int err = 0;
if (!transport->delete_chap)
return -ENOSYS;
shost = scsi_host_lookup(ev->u.delete_chap.host_no);
if (!shost) {
printk(KERN_ERR "%s could not find host no %u\n",
__func__, ev->u.delete_chap.host_no);
return -ENODEV;
}
err = transport->delete_chap(shost, ev->u.delete_chap.chap_tbl_idx);
scsi_host_put(shost);
return err;
}
char *iscsi_get_discovery_parent_name(int parent_type)
{
int i;
char *state = "Unknown!";
for (i = 0; i < ARRAY_SIZE(iscsi_discovery_parent_names); i++) {
if (iscsi_discovery_parent_names[i].value & parent_type) {
state = iscsi_discovery_parent_names[i].name;
break;
}
}
return state;
}
static int iscsi_set_flashnode_param(struct iscsi_transport *transport,
struct iscsi_uevent *ev, uint32_t len)
{
char *data = (char *)ev + sizeof(*ev);
struct Scsi_Host *shost;
struct iscsi_bus_flash_session *fnode_sess;
struct iscsi_bus_flash_conn *fnode_conn;
struct device *dev;
uint32_t idx;
int err = 0;
if (!transport->set_flashnode_param) {
err = -ENOSYS;
goto exit_set_fnode;
}
shost = scsi_host_lookup(ev->u.set_flashnode.host_no);
if (!shost) {
pr_err("%s could not find host no %u\n",
__func__, ev->u.set_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
idx = ev->u.set_flashnode.flashnode_idx;
fnode_sess = iscsi_get_flashnode_by_index(shost, idx);
if (!fnode_sess) {
pr_err("%s could not find flashnode %u for host no %u\n",
__func__, idx, ev->u.set_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
dev = iscsi_find_flashnode_conn(fnode_sess);
if (!dev) {
err = -ENODEV;
goto put_sess;
}
fnode_conn = iscsi_dev_to_flash_conn(dev);
err = transport->set_flashnode_param(fnode_sess, fnode_conn, data, len);
put_device(dev);
put_sess:
put_device(&fnode_sess->dev);
put_host:
scsi_host_put(shost);
exit_set_fnode:
return err;
}
static int iscsi_new_flashnode(struct iscsi_transport *transport,
struct iscsi_uevent *ev, uint32_t len)
{
char *data = (char *)ev + sizeof(*ev);
struct Scsi_Host *shost;
int index;
int err = 0;
if (!transport->new_flashnode) {
err = -ENOSYS;
goto exit_new_fnode;
}
shost = scsi_host_lookup(ev->u.new_flashnode.host_no);
if (!shost) {
pr_err("%s could not find host no %u\n",
__func__, ev->u.new_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
index = transport->new_flashnode(shost, data, len);
if (index >= 0)
ev->r.new_flashnode_ret.flashnode_idx = index;
else
err = -EIO;
put_host:
scsi_host_put(shost);
exit_new_fnode:
return err;
}
static int iscsi_del_flashnode(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct iscsi_bus_flash_session *fnode_sess;
uint32_t idx;
int err = 0;
if (!transport->del_flashnode) {
err = -ENOSYS;
goto exit_del_fnode;
}
shost = scsi_host_lookup(ev->u.del_flashnode.host_no);
if (!shost) {
pr_err("%s could not find host no %u\n",
__func__, ev->u.del_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
idx = ev->u.del_flashnode.flashnode_idx;
fnode_sess = iscsi_get_flashnode_by_index(shost, idx);
if (!fnode_sess) {
pr_err("%s could not find flashnode %u for host no %u\n",
__func__, idx, ev->u.del_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
err = transport->del_flashnode(fnode_sess);
put_device(&fnode_sess->dev);
put_host:
scsi_host_put(shost);
exit_del_fnode:
return err;
}
static int iscsi_login_flashnode(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct iscsi_bus_flash_session *fnode_sess;
struct iscsi_bus_flash_conn *fnode_conn;
struct device *dev;
uint32_t idx;
int err = 0;
if (!transport->login_flashnode) {
err = -ENOSYS;
goto exit_login_fnode;
}
shost = scsi_host_lookup(ev->u.login_flashnode.host_no);
if (!shost) {
pr_err("%s could not find host no %u\n",
__func__, ev->u.login_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
idx = ev->u.login_flashnode.flashnode_idx;
fnode_sess = iscsi_get_flashnode_by_index(shost, idx);
if (!fnode_sess) {
pr_err("%s could not find flashnode %u for host no %u\n",
__func__, idx, ev->u.login_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
dev = iscsi_find_flashnode_conn(fnode_sess);
if (!dev) {
err = -ENODEV;
goto put_sess;
}
fnode_conn = iscsi_dev_to_flash_conn(dev);
err = transport->login_flashnode(fnode_sess, fnode_conn);
put_device(dev);
put_sess:
put_device(&fnode_sess->dev);
put_host:
scsi_host_put(shost);
exit_login_fnode:
return err;
}
static int iscsi_logout_flashnode(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct iscsi_bus_flash_session *fnode_sess;
struct iscsi_bus_flash_conn *fnode_conn;
struct device *dev;
uint32_t idx;
int err = 0;
if (!transport->logout_flashnode) {
err = -ENOSYS;
goto exit_logout_fnode;
}
shost = scsi_host_lookup(ev->u.logout_flashnode.host_no);
if (!shost) {
pr_err("%s could not find host no %u\n",
__func__, ev->u.logout_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
idx = ev->u.logout_flashnode.flashnode_idx;
fnode_sess = iscsi_get_flashnode_by_index(shost, idx);
if (!fnode_sess) {
pr_err("%s could not find flashnode %u for host no %u\n",
__func__, idx, ev->u.logout_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
dev = iscsi_find_flashnode_conn(fnode_sess);
if (!dev) {
err = -ENODEV;
goto put_sess;
}
fnode_conn = iscsi_dev_to_flash_conn(dev);
err = transport->logout_flashnode(fnode_sess, fnode_conn);
put_device(dev);
put_sess:
put_device(&fnode_sess->dev);
put_host:
scsi_host_put(shost);
exit_logout_fnode:
return err;
}
static int iscsi_logout_flashnode_sid(struct iscsi_transport *transport,
struct iscsi_uevent *ev)
{
struct Scsi_Host *shost;
struct iscsi_cls_session *session;
int err = 0;
if (!transport->logout_flashnode_sid) {
err = -ENOSYS;
goto exit_logout_sid;
}
shost = scsi_host_lookup(ev->u.logout_flashnode_sid.host_no);
if (!shost) {
pr_err("%s could not find host no %u\n",
__func__, ev->u.logout_flashnode.host_no);
err = -ENODEV;
goto put_host;
}
session = iscsi_session_lookup(ev->u.logout_flashnode_sid.sid);
if (!session) {
pr_err("%s could not find session id %u\n",
__func__, ev->u.logout_flashnode_sid.sid);
err = -EINVAL;
goto put_host;
}
err = transport->logout_flashnode_sid(session);
put_host:
scsi_host_put(shost);
exit_logout_sid:
return err;
}
static int
iscsi_get_host_stats(struct iscsi_transport *transport, struct nlmsghdr *nlh)
{
struct iscsi_uevent *ev = nlmsg_data(nlh);
struct Scsi_Host *shost = NULL;
struct iscsi_internal *priv;
struct sk_buff *skbhost_stats;
struct nlmsghdr *nlhhost_stats;
struct iscsi_uevent *evhost_stats;
int host_stats_size = 0;
int len, err = 0;
char *buf;
if (!transport->get_host_stats)
return -ENOSYS;
priv = iscsi_if_transport_lookup(transport);
if (!priv)
return -EINVAL;
host_stats_size = sizeof(struct iscsi_offload_host_stats);
len = nlmsg_total_size(sizeof(*ev) + host_stats_size);
shost = scsi_host_lookup(ev->u.get_host_stats.host_no);
if (!shost) {
pr_err("%s: failed. Cound not find host no %u\n",
__func__, ev->u.get_host_stats.host_no);
return -ENODEV;
}
do {
int actual_size;
skbhost_stats = alloc_skb(len, GFP_KERNEL);
if (!skbhost_stats) {
pr_err("cannot deliver host stats: OOM\n");
err = -ENOMEM;
goto exit_host_stats;
}
nlhhost_stats = __nlmsg_put(skbhost_stats, 0, 0, 0,
(len - sizeof(*nlhhost_stats)), 0);
evhost_stats = nlmsg_data(nlhhost_stats);
memset(evhost_stats, 0, sizeof(*evhost_stats));
evhost_stats->transport_handle = iscsi_handle(transport);
evhost_stats->type = nlh->nlmsg_type;
evhost_stats->u.get_host_stats.host_no =
ev->u.get_host_stats.host_no;
buf = (char *)evhost_stats + sizeof(*evhost_stats);
memset(buf, 0, host_stats_size);
err = transport->get_host_stats(shost, buf, host_stats_size);
if (err) {
kfree_skb(skbhost_stats);
goto exit_host_stats;
}
actual_size = nlmsg_total_size(sizeof(*ev) + host_stats_size);
skb_trim(skbhost_stats, NLMSG_ALIGN(actual_size));
nlhhost_stats->nlmsg_len = actual_size;
err = iscsi_multicast_skb(skbhost_stats, ISCSI_NL_GRP_ISCSID,
GFP_KERNEL);
} while (err < 0 && err != -ECONNREFUSED);
exit_host_stats:
scsi_host_put(shost);
return err;
}
static int
iscsi_if_recv_msg(struct sk_buff *skb, struct nlmsghdr *nlh, uint32_t *group)
{
int err = 0;
struct iscsi_uevent *ev = nlmsg_data(nlh);
struct iscsi_transport *transport = NULL;
struct iscsi_internal *priv;
struct iscsi_cls_session *session;
struct iscsi_cls_conn *conn;
struct iscsi_endpoint *ep = NULL;
if (nlh->nlmsg_type == ISCSI_UEVENT_PATH_UPDATE)
*group = ISCSI_NL_GRP_UIP;
else
*group = ISCSI_NL_GRP_ISCSID;
priv = iscsi_if_transport_lookup(iscsi_ptr(ev->transport_handle));
if (!priv)
return -EINVAL;
transport = priv->iscsi_transport;
if (!try_module_get(transport->owner))
return -EINVAL;
switch (nlh->nlmsg_type) {
case ISCSI_UEVENT_CREATE_SESSION:
err = iscsi_if_create_session(priv, ep, ev,
NETLINK_CB(skb).portid,
ev->u.c_session.initial_cmdsn,
ev->u.c_session.cmds_max,
ev->u.c_session.queue_depth);
break;
case ISCSI_UEVENT_CREATE_BOUND_SESSION:
ep = iscsi_lookup_endpoint(ev->u.c_bound_session.ep_handle);
if (!ep) {
err = -EINVAL;
break;
}
err = iscsi_if_create_session(priv, ep, ev,
NETLINK_CB(skb).portid,
ev->u.c_bound_session.initial_cmdsn,
ev->u.c_bound_session.cmds_max,
ev->u.c_bound_session.queue_depth);
break;
case ISCSI_UEVENT_DESTROY_SESSION:
session = iscsi_session_lookup(ev->u.d_session.sid);
if (session)
transport->destroy_session(session);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_UNBIND_SESSION:
session = iscsi_session_lookup(ev->u.d_session.sid);
if (session)
scsi_queue_work(iscsi_session_to_shost(session),
&session->unbind_work);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_CREATE_CONN:
err = iscsi_if_create_conn(transport, ev);
break;
case ISCSI_UEVENT_DESTROY_CONN:
err = iscsi_if_destroy_conn(transport, ev);
break;
case ISCSI_UEVENT_BIND_CONN:
session = iscsi_session_lookup(ev->u.b_conn.sid);
conn = iscsi_conn_lookup(ev->u.b_conn.sid, ev->u.b_conn.cid);
if (conn && conn->ep)
iscsi_if_ep_disconnect(transport, conn->ep->id);
if (!session || !conn) {
err = -EINVAL;
break;
}
ev->r.retcode = transport->bind_conn(session, conn,
ev->u.b_conn.transport_eph,
ev->u.b_conn.is_leading);
if (ev->r.retcode || !transport->ep_connect)
break;
ep = iscsi_lookup_endpoint(ev->u.b_conn.transport_eph);
if (ep) {
ep->conn = conn;
mutex_lock(&conn->ep_mutex);
conn->ep = ep;
mutex_unlock(&conn->ep_mutex);
} else
iscsi_cls_conn_printk(KERN_ERR, conn,
"Could not set ep conn "
"binding\n");
break;
case ISCSI_UEVENT_SET_PARAM:
err = iscsi_set_param(transport, ev);
break;
case ISCSI_UEVENT_START_CONN:
conn = iscsi_conn_lookup(ev->u.start_conn.sid, ev->u.start_conn.cid);
if (conn)
ev->r.retcode = transport->start_conn(conn);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_STOP_CONN:
conn = iscsi_conn_lookup(ev->u.stop_conn.sid, ev->u.stop_conn.cid);
if (conn)
transport->stop_conn(conn, ev->u.stop_conn.flag);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_SEND_PDU:
conn = iscsi_conn_lookup(ev->u.send_pdu.sid, ev->u.send_pdu.cid);
if (conn)
ev->r.retcode = transport->send_pdu(conn,
(struct iscsi_hdr*)((char*)ev + sizeof(*ev)),
(char*)ev + sizeof(*ev) + ev->u.send_pdu.hdr_size,
ev->u.send_pdu.data_size);
else
err = -EINVAL;
break;
case ISCSI_UEVENT_GET_STATS:
err = iscsi_if_get_stats(transport, nlh);
break;
case ISCSI_UEVENT_TRANSPORT_EP_CONNECT:
case ISCSI_UEVENT_TRANSPORT_EP_POLL:
case ISCSI_UEVENT_TRANSPORT_EP_DISCONNECT:
case ISCSI_UEVENT_TRANSPORT_EP_CONNECT_THROUGH_HOST:
err = iscsi_if_transport_ep(transport, ev, nlh->nlmsg_type);
break;
case ISCSI_UEVENT_TGT_DSCVR:
err = iscsi_tgt_dscvr(transport, ev);
break;
case ISCSI_UEVENT_SET_HOST_PARAM:
err = iscsi_set_host_param(transport, ev);
break;
case ISCSI_UEVENT_PATH_UPDATE:
err = iscsi_set_path(transport, ev);
break;
case ISCSI_UEVENT_SET_IFACE_PARAMS:
err = iscsi_set_iface_params(transport, ev,
nlmsg_attrlen(nlh, sizeof(*ev)));
break;
case ISCSI_UEVENT_PING:
err = iscsi_send_ping(transport, ev);
break;
case ISCSI_UEVENT_GET_CHAP:
err = iscsi_get_chap(transport, nlh);
break;
case ISCSI_UEVENT_DELETE_CHAP:
err = iscsi_delete_chap(transport, ev);
break;
case ISCSI_UEVENT_SET_FLASHNODE_PARAMS:
err = iscsi_set_flashnode_param(transport, ev,
nlmsg_attrlen(nlh,
sizeof(*ev)));
break;
case ISCSI_UEVENT_NEW_FLASHNODE:
err = iscsi_new_flashnode(transport, ev,
nlmsg_attrlen(nlh, sizeof(*ev)));
break;
case ISCSI_UEVENT_DEL_FLASHNODE:
err = iscsi_del_flashnode(transport, ev);
break;
case ISCSI_UEVENT_LOGIN_FLASHNODE:
err = iscsi_login_flashnode(transport, ev);
break;
case ISCSI_UEVENT_LOGOUT_FLASHNODE:
err = iscsi_logout_flashnode(transport, ev);
break;
case ISCSI_UEVENT_LOGOUT_FLASHNODE_SID:
err = iscsi_logout_flashnode_sid(transport, ev);
break;
case ISCSI_UEVENT_SET_CHAP:
err = iscsi_set_chap(transport, ev,
nlmsg_attrlen(nlh, sizeof(*ev)));
break;
case ISCSI_UEVENT_GET_HOST_STATS:
err = iscsi_get_host_stats(transport, nlh);
break;
default:
err = -ENOSYS;
break;
}
module_put(transport->owner);
return err;
}
static void
iscsi_if_rx(struct sk_buff *skb)
{
mutex_lock(&rx_queue_mutex);
while (skb->len >= NLMSG_HDRLEN) {
int err;
uint32_t rlen;
struct nlmsghdr *nlh;
struct iscsi_uevent *ev;
uint32_t group;
nlh = nlmsg_hdr(skb);
if (nlh->nlmsg_len < sizeof(*nlh) ||
skb->len < nlh->nlmsg_len) {
break;
}
ev = nlmsg_data(nlh);
rlen = NLMSG_ALIGN(nlh->nlmsg_len);
if (rlen > skb->len)
rlen = skb->len;
err = iscsi_if_recv_msg(skb, nlh, &group);
if (err) {
ev->type = ISCSI_KEVENT_IF_ERROR;
ev->iferror = err;
}
do {
if (ev->type == ISCSI_UEVENT_GET_STATS && !err)
break;
if (ev->type == ISCSI_UEVENT_GET_CHAP && !err)
break;
err = iscsi_if_send_reply(group, nlh->nlmsg_seq,
nlh->nlmsg_type, 0, 0, ev, sizeof(*ev));
} while (err < 0 && err != -ECONNREFUSED && err != -ESRCH);
skb_pull(skb, rlen);
}
mutex_unlock(&rx_queue_mutex);
}
static umode_t iscsi_conn_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int i)
{
struct device *cdev = container_of(kobj, struct device, kobj);
struct iscsi_cls_conn *conn = transport_class_to_conn(cdev);
struct iscsi_transport *t = conn->transport;
int param;
if (attr == &dev_attr_conn_max_recv_dlength.attr)
param = ISCSI_PARAM_MAX_RECV_DLENGTH;
else if (attr == &dev_attr_conn_max_xmit_dlength.attr)
param = ISCSI_PARAM_MAX_XMIT_DLENGTH;
else if (attr == &dev_attr_conn_header_digest.attr)
param = ISCSI_PARAM_HDRDGST_EN;
else if (attr == &dev_attr_conn_data_digest.attr)
param = ISCSI_PARAM_DATADGST_EN;
else if (attr == &dev_attr_conn_ifmarker.attr)
param = ISCSI_PARAM_IFMARKER_EN;
else if (attr == &dev_attr_conn_ofmarker.attr)
param = ISCSI_PARAM_OFMARKER_EN;
else if (attr == &dev_attr_conn_address.attr)
param = ISCSI_PARAM_CONN_ADDRESS;
else if (attr == &dev_attr_conn_port.attr)
param = ISCSI_PARAM_CONN_PORT;
else if (attr == &dev_attr_conn_exp_statsn.attr)
param = ISCSI_PARAM_EXP_STATSN;
else if (attr == &dev_attr_conn_persistent_address.attr)
param = ISCSI_PARAM_PERSISTENT_ADDRESS;
else if (attr == &dev_attr_conn_persistent_port.attr)
param = ISCSI_PARAM_PERSISTENT_PORT;
else if (attr == &dev_attr_conn_ping_tmo.attr)
param = ISCSI_PARAM_PING_TMO;
else if (attr == &dev_attr_conn_recv_tmo.attr)
param = ISCSI_PARAM_RECV_TMO;
else if (attr == &dev_attr_conn_local_port.attr)
param = ISCSI_PARAM_LOCAL_PORT;
else if (attr == &dev_attr_conn_statsn.attr)
param = ISCSI_PARAM_STATSN;
else if (attr == &dev_attr_conn_keepalive_tmo.attr)
param = ISCSI_PARAM_KEEPALIVE_TMO;
else if (attr == &dev_attr_conn_max_segment_size.attr)
param = ISCSI_PARAM_MAX_SEGMENT_SIZE;
else if (attr == &dev_attr_conn_tcp_timestamp_stat.attr)
param = ISCSI_PARAM_TCP_TIMESTAMP_STAT;
else if (attr == &dev_attr_conn_tcp_wsf_disable.attr)
param = ISCSI_PARAM_TCP_WSF_DISABLE;
else if (attr == &dev_attr_conn_tcp_nagle_disable.attr)
param = ISCSI_PARAM_TCP_NAGLE_DISABLE;
else if (attr == &dev_attr_conn_tcp_timer_scale.attr)
param = ISCSI_PARAM_TCP_TIMER_SCALE;
else if (attr == &dev_attr_conn_tcp_timestamp_enable.attr)
param = ISCSI_PARAM_TCP_TIMESTAMP_EN;
else if (attr == &dev_attr_conn_fragment_disable.attr)
param = ISCSI_PARAM_IP_FRAGMENT_DISABLE;
else if (attr == &dev_attr_conn_ipv4_tos.attr)
param = ISCSI_PARAM_IPV4_TOS;
else if (attr == &dev_attr_conn_ipv6_traffic_class.attr)
param = ISCSI_PARAM_IPV6_TC;
else if (attr == &dev_attr_conn_ipv6_flow_label.attr)
param = ISCSI_PARAM_IPV6_FLOW_LABEL;
else if (attr == &dev_attr_conn_is_fw_assigned_ipv6.attr)
param = ISCSI_PARAM_IS_FW_ASSIGNED_IPV6;
else if (attr == &dev_attr_conn_tcp_xmit_wsf.attr)
param = ISCSI_PARAM_TCP_XMIT_WSF;
else if (attr == &dev_attr_conn_tcp_recv_wsf.attr)
param = ISCSI_PARAM_TCP_RECV_WSF;
else if (attr == &dev_attr_conn_local_ipaddr.attr)
param = ISCSI_PARAM_LOCAL_IPADDR;
else {
WARN_ONCE(1, "Invalid conn attr");
return 0;
}
return t->attr_is_visible(ISCSI_PARAM, param);
}
static ssize_t
show_priv_session_state(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct iscsi_cls_session *session = iscsi_dev_to_session(dev->parent);
return sprintf(buf, "%s\n", iscsi_session_state_name(session->state));
}
static ssize_t
show_priv_session_creator(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct iscsi_cls_session *session = iscsi_dev_to_session(dev->parent);
return sprintf(buf, "%d\n", session->creator);
}
static ssize_t
show_priv_session_target_id(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct iscsi_cls_session *session = iscsi_dev_to_session(dev->parent);
return sprintf(buf, "%d\n", session->target_id);
}
static umode_t iscsi_session_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int i)
{
struct device *cdev = container_of(kobj, struct device, kobj);
struct iscsi_cls_session *session = transport_class_to_session(cdev);
struct iscsi_transport *t = session->transport;
int param;
if (attr == &dev_attr_sess_initial_r2t.attr)
param = ISCSI_PARAM_INITIAL_R2T_EN;
else if (attr == &dev_attr_sess_max_outstanding_r2t.attr)
param = ISCSI_PARAM_MAX_R2T;
else if (attr == &dev_attr_sess_immediate_data.attr)
param = ISCSI_PARAM_IMM_DATA_EN;
else if (attr == &dev_attr_sess_first_burst_len.attr)
param = ISCSI_PARAM_FIRST_BURST;
else if (attr == &dev_attr_sess_max_burst_len.attr)
param = ISCSI_PARAM_MAX_BURST;
else if (attr == &dev_attr_sess_data_pdu_in_order.attr)
param = ISCSI_PARAM_PDU_INORDER_EN;
else if (attr == &dev_attr_sess_data_seq_in_order.attr)
param = ISCSI_PARAM_DATASEQ_INORDER_EN;
else if (attr == &dev_attr_sess_erl.attr)
param = ISCSI_PARAM_ERL;
else if (attr == &dev_attr_sess_targetname.attr)
param = ISCSI_PARAM_TARGET_NAME;
else if (attr == &dev_attr_sess_tpgt.attr)
param = ISCSI_PARAM_TPGT;
else if (attr == &dev_attr_sess_chap_in_idx.attr)
param = ISCSI_PARAM_CHAP_IN_IDX;
else if (attr == &dev_attr_sess_chap_out_idx.attr)
param = ISCSI_PARAM_CHAP_OUT_IDX;
else if (attr == &dev_attr_sess_password.attr)
param = ISCSI_PARAM_USERNAME;
else if (attr == &dev_attr_sess_password_in.attr)
param = ISCSI_PARAM_USERNAME_IN;
else if (attr == &dev_attr_sess_username.attr)
param = ISCSI_PARAM_PASSWORD;
else if (attr == &dev_attr_sess_username_in.attr)
param = ISCSI_PARAM_PASSWORD_IN;
else if (attr == &dev_attr_sess_fast_abort.attr)
param = ISCSI_PARAM_FAST_ABORT;
else if (attr == &dev_attr_sess_abort_tmo.attr)
param = ISCSI_PARAM_ABORT_TMO;
else if (attr == &dev_attr_sess_lu_reset_tmo.attr)
param = ISCSI_PARAM_LU_RESET_TMO;
else if (attr == &dev_attr_sess_tgt_reset_tmo.attr)
param = ISCSI_PARAM_TGT_RESET_TMO;
else if (attr == &dev_attr_sess_ifacename.attr)
param = ISCSI_PARAM_IFACE_NAME;
else if (attr == &dev_attr_sess_initiatorname.attr)
param = ISCSI_PARAM_INITIATOR_NAME;
else if (attr == &dev_attr_sess_targetalias.attr)
param = ISCSI_PARAM_TARGET_ALIAS;
else if (attr == &dev_attr_sess_boot_root.attr)
param = ISCSI_PARAM_BOOT_ROOT;
else if (attr == &dev_attr_sess_boot_nic.attr)
param = ISCSI_PARAM_BOOT_NIC;
else if (attr == &dev_attr_sess_boot_target.attr)
param = ISCSI_PARAM_BOOT_TARGET;
else if (attr == &dev_attr_sess_auto_snd_tgt_disable.attr)
param = ISCSI_PARAM_AUTO_SND_TGT_DISABLE;
else if (attr == &dev_attr_sess_discovery_session.attr)
param = ISCSI_PARAM_DISCOVERY_SESS;
else if (attr == &dev_attr_sess_portal_type.attr)
param = ISCSI_PARAM_PORTAL_TYPE;
else if (attr == &dev_attr_sess_chap_auth.attr)
param = ISCSI_PARAM_CHAP_AUTH_EN;
else if (attr == &dev_attr_sess_discovery_logout.attr)
param = ISCSI_PARAM_DISCOVERY_LOGOUT_EN;
else if (attr == &dev_attr_sess_bidi_chap.attr)
param = ISCSI_PARAM_BIDI_CHAP_EN;
else if (attr == &dev_attr_sess_discovery_auth_optional.attr)
param = ISCSI_PARAM_DISCOVERY_AUTH_OPTIONAL;
else if (attr == &dev_attr_sess_def_time2wait.attr)
param = ISCSI_PARAM_DEF_TIME2WAIT;
else if (attr == &dev_attr_sess_def_time2retain.attr)
param = ISCSI_PARAM_DEF_TIME2RETAIN;
else if (attr == &dev_attr_sess_isid.attr)
param = ISCSI_PARAM_ISID;
else if (attr == &dev_attr_sess_tsid.attr)
param = ISCSI_PARAM_TSID;
else if (attr == &dev_attr_sess_def_taskmgmt_tmo.attr)
param = ISCSI_PARAM_DEF_TASKMGMT_TMO;
else if (attr == &dev_attr_sess_discovery_parent_idx.attr)
param = ISCSI_PARAM_DISCOVERY_PARENT_IDX;
else if (attr == &dev_attr_sess_discovery_parent_type.attr)
param = ISCSI_PARAM_DISCOVERY_PARENT_TYPE;
else if (attr == &dev_attr_priv_sess_recovery_tmo.attr)
return S_IRUGO | S_IWUSR;
else if (attr == &dev_attr_priv_sess_state.attr)
return S_IRUGO;
else if (attr == &dev_attr_priv_sess_creator.attr)
return S_IRUGO;
else if (attr == &dev_attr_priv_sess_target_id.attr)
return S_IRUGO;
else {
WARN_ONCE(1, "Invalid session attr");
return 0;
}
return t->attr_is_visible(ISCSI_PARAM, param);
}
static umode_t iscsi_host_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int i)
{
struct device *cdev = container_of(kobj, struct device, kobj);
struct Scsi_Host *shost = transport_class_to_shost(cdev);
struct iscsi_internal *priv = to_iscsi_internal(shost->transportt);
int param;
if (attr == &dev_attr_host_netdev.attr)
param = ISCSI_HOST_PARAM_NETDEV_NAME;
else if (attr == &dev_attr_host_hwaddress.attr)
param = ISCSI_HOST_PARAM_HWADDRESS;
else if (attr == &dev_attr_host_ipaddress.attr)
param = ISCSI_HOST_PARAM_IPADDRESS;
else if (attr == &dev_attr_host_initiatorname.attr)
param = ISCSI_HOST_PARAM_INITIATOR_NAME;
else if (attr == &dev_attr_host_port_state.attr)
param = ISCSI_HOST_PARAM_PORT_STATE;
else if (attr == &dev_attr_host_port_speed.attr)
param = ISCSI_HOST_PARAM_PORT_SPEED;
else {
WARN_ONCE(1, "Invalid host attr");
return 0;
}
return priv->iscsi_transport->attr_is_visible(ISCSI_HOST_PARAM, param);
}
char *iscsi_get_port_speed_name(struct Scsi_Host *shost)
{
int i;
char *speed = "Unknown!";
struct iscsi_cls_host *ihost = shost->shost_data;
uint32_t port_speed = ihost->port_speed;
for (i = 0; i < ARRAY_SIZE(iscsi_port_speed_names); i++) {
if (iscsi_port_speed_names[i].value & port_speed) {
speed = iscsi_port_speed_names[i].name;
break;
}
}
return speed;
}
char *iscsi_get_port_state_name(struct Scsi_Host *shost)
{
int i;
char *state = "Unknown!";
struct iscsi_cls_host *ihost = shost->shost_data;
uint32_t port_state = ihost->port_state;
for (i = 0; i < ARRAY_SIZE(iscsi_port_state_names); i++) {
if (iscsi_port_state_names[i].value & port_state) {
state = iscsi_port_state_names[i].name;
break;
}
}
return state;
}
static int iscsi_session_match(struct attribute_container *cont,
struct device *dev)
{
struct iscsi_cls_session *session;
struct Scsi_Host *shost;
struct iscsi_internal *priv;
if (!iscsi_is_session_dev(dev))
return 0;
session = iscsi_dev_to_session(dev);
shost = iscsi_session_to_shost(session);
if (!shost->transportt)
return 0;
priv = to_iscsi_internal(shost->transportt);
if (priv->session_cont.ac.class != &iscsi_session_class.class)
return 0;
return &priv->session_cont.ac == cont;
}
static int iscsi_conn_match(struct attribute_container *cont,
struct device *dev)
{
struct iscsi_cls_session *session;
struct iscsi_cls_conn *conn;
struct Scsi_Host *shost;
struct iscsi_internal *priv;
if (!iscsi_is_conn_dev(dev))
return 0;
conn = iscsi_dev_to_conn(dev);
session = iscsi_dev_to_session(conn->dev.parent);
shost = iscsi_session_to_shost(session);
if (!shost->transportt)
return 0;
priv = to_iscsi_internal(shost->transportt);
if (priv->conn_cont.ac.class != &iscsi_connection_class.class)
return 0;
return &priv->conn_cont.ac == cont;
}
static int iscsi_host_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct iscsi_internal *priv;
if (!scsi_is_host_device(dev))
return 0;
shost = dev_to_shost(dev);
if (!shost->transportt ||
shost->transportt->host_attrs.ac.class != &iscsi_host_class.class)
return 0;
priv = to_iscsi_internal(shost->transportt);
return &priv->t.host_attrs.ac == cont;
}
struct scsi_transport_template *
iscsi_register_transport(struct iscsi_transport *tt)
{
struct iscsi_internal *priv;
unsigned long flags;
int err;
BUG_ON(!tt);
priv = iscsi_if_transport_lookup(tt);
if (priv)
return NULL;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return NULL;
INIT_LIST_HEAD(&priv->list);
priv->iscsi_transport = tt;
priv->t.user_scan = iscsi_user_scan;
priv->t.create_work_queue = 1;
priv->dev.class = &iscsi_transport_class;
dev_set_name(&priv->dev, "%s", tt->name);
err = device_register(&priv->dev);
if (err)
goto free_priv;
err = sysfs_create_group(&priv->dev.kobj, &iscsi_transport_group);
if (err)
goto unregister_dev;
priv->t.host_attrs.ac.class = &iscsi_host_class.class;
priv->t.host_attrs.ac.match = iscsi_host_match;
priv->t.host_attrs.ac.grp = &iscsi_host_group;
priv->t.host_size = sizeof(struct iscsi_cls_host);
transport_container_register(&priv->t.host_attrs);
priv->conn_cont.ac.class = &iscsi_connection_class.class;
priv->conn_cont.ac.match = iscsi_conn_match;
priv->conn_cont.ac.grp = &iscsi_conn_group;
transport_container_register(&priv->conn_cont);
priv->session_cont.ac.class = &iscsi_session_class.class;
priv->session_cont.ac.match = iscsi_session_match;
priv->session_cont.ac.grp = &iscsi_session_group;
transport_container_register(&priv->session_cont);
spin_lock_irqsave(&iscsi_transport_lock, flags);
list_add(&priv->list, &iscsi_transports);
spin_unlock_irqrestore(&iscsi_transport_lock, flags);
printk(KERN_NOTICE "iscsi: registered transport (%s)\n", tt->name);
return &priv->t;
unregister_dev:
device_unregister(&priv->dev);
return NULL;
free_priv:
kfree(priv);
return NULL;
}
int iscsi_unregister_transport(struct iscsi_transport *tt)
{
struct iscsi_internal *priv;
unsigned long flags;
BUG_ON(!tt);
mutex_lock(&rx_queue_mutex);
priv = iscsi_if_transport_lookup(tt);
BUG_ON (!priv);
spin_lock_irqsave(&iscsi_transport_lock, flags);
list_del(&priv->list);
spin_unlock_irqrestore(&iscsi_transport_lock, flags);
transport_container_unregister(&priv->conn_cont);
transport_container_unregister(&priv->session_cont);
transport_container_unregister(&priv->t.host_attrs);
sysfs_remove_group(&priv->dev.kobj, &iscsi_transport_group);
device_unregister(&priv->dev);
mutex_unlock(&rx_queue_mutex);
return 0;
}
static __init int iscsi_transport_init(void)
{
int err;
struct netlink_kernel_cfg cfg = {
.groups = 1,
.input = iscsi_if_rx,
};
printk(KERN_INFO "Loading iSCSI transport class v%s.\n",
ISCSI_TRANSPORT_VERSION);
atomic_set(&iscsi_session_nr, 0);
err = class_register(&iscsi_transport_class);
if (err)
return err;
err = class_register(&iscsi_endpoint_class);
if (err)
goto unregister_transport_class;
err = class_register(&iscsi_iface_class);
if (err)
goto unregister_endpoint_class;
err = transport_class_register(&iscsi_host_class);
if (err)
goto unregister_iface_class;
err = transport_class_register(&iscsi_connection_class);
if (err)
goto unregister_host_class;
err = transport_class_register(&iscsi_session_class);
if (err)
goto unregister_conn_class;
err = bus_register(&iscsi_flashnode_bus);
if (err)
goto unregister_session_class;
nls = netlink_kernel_create(&init_net, NETLINK_ISCSI, &cfg);
if (!nls) {
err = -ENOBUFS;
goto unregister_flashnode_bus;
}
iscsi_eh_timer_workq = create_singlethread_workqueue("iscsi_eh");
if (!iscsi_eh_timer_workq) {
err = -ENOMEM;
goto release_nls;
}
return 0;
release_nls:
netlink_kernel_release(nls);
unregister_flashnode_bus:
bus_unregister(&iscsi_flashnode_bus);
unregister_session_class:
transport_class_unregister(&iscsi_session_class);
unregister_conn_class:
transport_class_unregister(&iscsi_connection_class);
unregister_host_class:
transport_class_unregister(&iscsi_host_class);
unregister_iface_class:
class_unregister(&iscsi_iface_class);
unregister_endpoint_class:
class_unregister(&iscsi_endpoint_class);
unregister_transport_class:
class_unregister(&iscsi_transport_class);
return err;
}
static void __exit iscsi_transport_exit(void)
{
destroy_workqueue(iscsi_eh_timer_workq);
netlink_kernel_release(nls);
bus_unregister(&iscsi_flashnode_bus);
transport_class_unregister(&iscsi_connection_class);
transport_class_unregister(&iscsi_session_class);
transport_class_unregister(&iscsi_host_class);
class_unregister(&iscsi_endpoint_class);
class_unregister(&iscsi_iface_class);
class_unregister(&iscsi_transport_class);
}
