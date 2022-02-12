static int dissect_netlink_netfilter_header(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, &hfi_netlink_netfilter_family, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, &hfi_netlink_netfilter_version, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, &hfi_netlink_netfilter_resid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_nfq_config_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_nfqnl_attr_config type = (enum ws_nfqnl_attr_config) nla_type;
netlink_netfilter_info_t *info = (netlink_netfilter_info_t *) data;
switch (type) {
case WS_NFQA_CFG_UNSPEC:
break;
case WS_NFQA_CFG_CMD:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_config_command_command, tvb, offset, 1, ENC_NA);
offset += 2;
proto_tree_add_item(tree, &hfi_nfq_config_command_pf, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
break;
case WS_NFQA_CFG_PARAMS:
if (len == 5) {
proto_tree_add_item(tree, &hfi_nfq_config_params_copyrange, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_nfq_config_params_copymode, tvb, offset, 1, ENC_NA);
offset++;
}
break;
case WS_NFQA_CFG_QUEUE_MAXLEN:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_config_queue_maxlen, tvb, offset, 4, info->encoding);
offset += 4;
}
break;
case WS_NFQA_CFG_MASK:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_config_mask, tvb, offset, 4, info->encoding);
offset += 4;
}
break;
case WS_NFQA_CFG_FLAGS:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_config_flags, tvb, offset, 4, info->encoding);
offset += 4;
}
break;
}
return offset;
}
static int
dissect_nfq_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_nfqnl_attr_type type = (enum ws_nfqnl_attr_type) nla_type;
netlink_netfilter_info_t *info = (netlink_netfilter_info_t *) data;
switch (type) {
case WS_NFQA_UNSPEC:
break;
case WS_NFQA_PACKET_HDR:
if (len == 7) {
proto_tree_add_item(tree, &hfi_nfq_packet_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_nfq_packet_hwprotocol, tvb, offset, 2, ENC_BIG_ENDIAN);
info->hw_protocol = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, &hfi_nfq_packet_hook, tvb, offset, 1, ENC_NA);
offset++;
}
break;
case WS_NFQA_VERDICT_HDR:
if (len == 8) {
proto_tree_add_item(tree, &hfi_nfq_verdict_verdict, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_nfq_verdict_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_MARK:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_nfmark, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_TIMESTAMP:
if (len == 16) {
nstime_t ts;
ts.secs = (time_t)tvb_get_ntoh64(tvb, offset);
ts.nsecs = (int)tvb_get_ntoh64(tvb, offset + 8) * 1000;
proto_tree_add_time(tree, &hfi_nfq_timestamp, tvb, offset, 16, &ts);
offset += 16;
}
break;
case WS_NFQA_IFINDEX_INDEV:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_ifindex_indev, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_IFINDEX_OUTDEV:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_ifindex_outdev, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_IFINDEX_PHYSINDEV:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_ifindex_physindev, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_IFINDEX_PHYSOUTDEV:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_ifindex_physoutdev, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_HWADDR:
if (len >= 4) {
guint16 addrlen;
proto_tree_add_item(tree, &hfi_nfq_hwaddr_len, tvb, offset, 2, ENC_BIG_ENDIAN);
addrlen = tvb_get_ntohs(tvb, offset);
offset += 4;
addrlen = MIN(addrlen, len - 4);
proto_tree_add_item(tree, &hfi_nfq_hwaddr_addr, tvb, offset, addrlen, ENC_BIG_ENDIAN);
offset += addrlen;
}
break;
case WS_NFQA_PAYLOAD:
if (len > 0) {
tvbuff_t *next_tvb = tvb_new_subset_length(tvb, offset, len);
proto_tree *parent_tree = proto_item_get_parent(tree);
if (!dissector_try_uint(ethertype_table, info->hw_protocol, next_tvb, info->pinfo, parent_tree))
call_data_dissector(next_tvb, info->pinfo, parent_tree);
offset += len;
}
break;
case WS_NFQA_CT:
break;
case WS_NFQA_CT_INFO:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_ctinfo, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_CAP_LEN:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_caplen, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_SKB_INFO:
case WS_NFQA_EXP:
break;
case WS_NFQA_UID:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_uid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_GID:
if (len == 4) {
proto_tree_add_item(tree, &hfi_nfq_gid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
break;
case WS_NFQA_SECCTX:
case WS_NFQA_VLAN:
case WS_NFQA_L2HDR:
break;
}
return offset;
}
static int
dissect_netfilter_queue(tvbuff_t *tvb, netlink_netfilter_info_t *info, proto_tree *tree, int offset)
{
enum ws_nfqnl_msg_types type = (enum ws_nfqnl_msg_types) (info->data->type & 0xff);
offset = dissect_netlink_netfilter_header(tvb, tree, offset);
switch (type) {
case WS_NFQNL_MSG_CONFIG:
return dissect_netlink_attributes(tvb, &hfi_nfq_config_attr, ett_nfq_config_attr, info, info->data, tree, offset, -1, dissect_nfq_config_attrs);
case WS_NFQNL_MSG_PACKET:
case WS_NFQNL_MSG_VERDICT:
return dissect_netlink_attributes(tvb, &hfi_nfq_attr, ett_nfq_attr, info, info->data, tree, offset, -1, dissect_nfq_attrs);
case WS_NFQNL_MSG_VERDICT_BATCH:
break;
}
return offset;
}
static int
dissect_netfilter_ulog(tvbuff_t *tvb, netlink_netfilter_info_t *info, proto_tree *tree, int offset)
{
enum ws_nfulnl_msg_types type = (enum ws_nfulnl_msg_types) (info->data->type & 0xff);
tvbuff_t *next_tvb;
switch (type) {
case WS_NFULNL_MSG_PACKET:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(nflog_handle, next_tvb, info->pinfo, tree);
offset = tvb_reported_length(tvb);
break;
default:
break;
}
return offset;
}
static int
dissect_ipset_ip_attrs(tvbuff_t *tvb, void *data _U_, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_ipset_ip_attr type = (enum ws_ipset_ip_attr) nla_type & NLA_TYPE_MASK;
switch (type) {
case WS_IPSET_ATTR_IPADDR_IPV4:
proto_tree_add_item(tree, &hfi_ipset_ip_attr_ipv4, tvb, offset, len, ENC_BIG_ENDIAN);
return 1;
case WS_IPSET_ATTR_IPADDR_IPV6:
proto_tree_add_item(tree, &hfi_ipset_ip_attr_ipv6, tvb, offset, len, ENC_BIG_ENDIAN);
return 1;
}
return 0;
}
static int
dissect_ipset_cadt_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_ipset_cadt_attr type = (enum ws_ipset_cadt_attr) nla_type & NLA_TYPE_MASK;
netlink_netfilter_info_t *info = (netlink_netfilter_info_t *) data;
switch (type) {
case WS_IPSET_ATTR_IP_FROM:
case WS_IPSET_ATTR_IP_TO:
if (nla_type & NLA_F_NESTED)
return dissect_netlink_attributes(tvb, &hfi_ipset_ip_attr, ett_ipset_ip_attr, info, info->data, tree, offset, len, dissect_ipset_ip_attrs);
return 0;
case WS_IPSET_ATTR_CIDR:
if (len == 1) {
proto_tree_add_item(tree, &hfi_ipset_cadt_attr_cidr, tvb, offset, len, ENC_NA);
return 1;
}
return 0;
case WS_IPSET_ATTR_PORT_FROM:
case WS_IPSET_ATTR_PORT_TO:
return 0;
case WS_IPSET_ATTR_TIMEOUT:
if (len == 4) {
proto_tree_add_item(tree, &hfi_ipset_cadt_attr_timeout, tvb, offset, len, ENC_BIG_ENDIAN);
return 1;
}
return 0;
case WS_IPSET_ATTR_PROTO:
return 0;
case WS_IPSET_ATTR_CADT_FLAGS:
if (len == 4) {
proto_tree_add_item(tree, &hfi_ipset_cadt_attr_cadt_flags, tvb, offset, len, ENC_BIG_ENDIAN);
return 1;
}
return 0;
case WS_IPSET_ATTR_CADT_LINENO:
case WS_IPSET_ATTR_MARK:
case WS_IPSET_ATTR_MARKMASK:
case WS_IPSET_ATTR_GC:
case WS_IPSET_ATTR_HASHSIZE:
case WS_IPSET_ATTR_MAXELEM:
case WS_IPSET_ATTR_NETMASK:
case WS_IPSET_ATTR_PROBES:
case WS_IPSET_ATTR_RESIZE:
case WS_IPSET_ATTR_SIZE:
case WS_IPSET_ATTR_ELEMENTS:
case WS_IPSET_ATTR_REFERENCES:
case WS_IPSET_ATTR_MEMSIZE:
return 0;
}
return 0;
}
static int
dissect_ipset_adt_data_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_ipset_adt_attr type = (enum ws_ipset_adt_attr) nla_type & NLA_TYPE_MASK;
if ((nla_type & NLA_TYPE_MASK) <= WS_IPSET_ATTR_CADT_MAX)
return dissect_ipset_cadt_attrs(tvb, data, tree, nla_type, offset, len);
switch (type) {
case WS_IPSET_ATTR_COMMENT:
proto_tree_add_item(tree, &hfi_ipset_adt_attr_comment, tvb, offset, len, ENC_UTF_8);
return 1;
default:
return 0;
}
return 0;
}
static int
dissect_ipset_adt_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
netlink_netfilter_info_t *info = (netlink_netfilter_info_t *) data;
if (nla_type & NLA_F_NESTED)
return dissect_netlink_attributes(tvb, &hfi_ipset_adt_attr, ett_ipset_adt_attr, info, info->data, tree, offset, len, dissect_ipset_adt_data_attrs);
return 0;
}
static int
dissect_ipset_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_ipset_attr type = (enum ws_ipset_attr) nla_type & NLA_TYPE_MASK;
netlink_netfilter_info_t *info = (netlink_netfilter_info_t *) data;
switch (type) {
case WS_IPSET_ATTR_PROTOCOL:
return 0;
case WS_IPSET_ATTR_SETNAME:
proto_tree_add_item(tree, &hfi_ipset_attr_setname, tvb, offset, len, ENC_UTF_8);
return 1;
case WS_IPSET_ATTR_TYPENAME:
proto_tree_add_item(tree, &hfi_ipset_attr_typename, tvb, offset, len, ENC_UTF_8);
return 1;
case WS_IPSET_ATTR_REVISION:
return 0;
case WS_IPSET_ATTR_FAMILY:
proto_tree_add_item(tree, &hfi_ipset_attr_family, tvb, offset, len, ENC_BIG_ENDIAN);
return 1;
case WS_IPSET_ATTR_FLAGS:
if (len == 4) {
proto_tree_add_item(tree, &hfi_ipset_attr_flags, tvb, offset, len, ENC_BIG_ENDIAN);
return 1;
}
return 0;
case WS_IPSET_ATTR_DATA:
if (nla_type & NLA_F_NESTED) {
guint16 command = info->data->type & 0xffff;
if (command == WS_IPSET_CMD_CREATE ||
command == WS_IPSET_CMD_LIST ||
command == WS_IPSET_CMD_SAVE)
return dissect_netlink_attributes(tvb, &hfi_ipset_cadt_attr, ett_ipset_cadt_attr, info, info->data, tree, offset, len, dissect_ipset_cadt_attrs);
else
return dissect_netlink_attributes(tvb, &hfi_ipset_adt_attr, ett_ipset_adt_attr, info, info->data, tree, offset, len, dissect_ipset_adt_data_attrs);
}
return 0;
case WS_IPSET_ATTR_ADT:
if (nla_type & NLA_F_NESTED)
return dissect_netlink_attributes(tvb, &hfi_ipset_attr, ett_ipset_attr, info, info->data, tree, offset, len, dissect_ipset_adt_attrs);
return 0;
case WS_IPSET_ATTR_LINENO:
case WS_IPSET_ATTR_PROTOCOL_MIN:
return 0;
}
return 0;
}
static int
dissect_netfilter_ipset(tvbuff_t *tvb, netlink_netfilter_info_t *info, proto_tree *tree, int offset)
{
offset = dissect_netlink_netfilter_header(tvb, tree, offset);
return dissect_netlink_attributes(tvb, &hfi_ipset_attr, ett_ipset_attr, info, info->data, tree, offset, -1, dissect_ipset_attrs);
}
static int
dissect_netlink_netfilter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *_data)
{
struct packet_netlink_data *data = (struct packet_netlink_data *)_data;
netlink_netfilter_info_t info;
proto_tree *nlmsg_tree;
proto_item *pi;
int offset = 0;
DISSECTOR_ASSERT(data && data->magic == PACKET_NETLINK_MAGIC);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netlink netfilter");
col_clear(pinfo->cinfo, COL_INFO);
pi = proto_tree_add_item(tree, proto_registrar_get_nth(proto_netlink_netfilter), tvb, 0, -1, ENC_NA);
nlmsg_tree = proto_item_add_subtree(pi, ett_netlink_netfilter);
offset = dissect_netlink_header(tvb, nlmsg_tree, offset, data->encoding, NULL, NULL);
proto_tree_add_item(nlmsg_tree, &hfi_netlink_netfilter_subsys, tvb, 4, 2, data->encoding);
switch (data->type >> 8) {
case WS_NFNL_SUBSYS_QUEUE:
proto_tree_add_item(nlmsg_tree, &hfi_nfq_type, tvb, 4, 2, data->encoding);
break;
case WS_NFNL_SUBSYS_ULOG:
proto_tree_add_item(nlmsg_tree, &hfi_netlink_netfilter_ulog_type, tvb, 4, 2, data->encoding);
break;
case WS_NFNL_SUBSYS_IPSET:
proto_tree_add_item(nlmsg_tree, &hfi_ipset_command, tvb, 4, 2, data->encoding);
break;
}
info.encoding = data->encoding;
info.pinfo = pinfo;
info.data = data;
info.hw_protocol = 0;
switch (data->type >> 8) {
case WS_NFNL_SUBSYS_QUEUE:
offset = dissect_netfilter_queue(tvb, &info, nlmsg_tree, offset);
break;
case WS_NFNL_SUBSYS_ULOG:
offset = dissect_netfilter_ulog(tvb, &info, nlmsg_tree, offset);
break;
case WS_NFNL_SUBSYS_IPSET:
offset = dissect_netfilter_ipset(tvb, &info, nlmsg_tree, offset);
break;
default:
call_data_dissector(tvb_new_subset_remaining(tvb, offset), pinfo, nlmsg_tree);
offset = tvb_reported_length(tvb);
break;
}
return offset;
}
void
proto_register_netlink_netfilter(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_netlink_netfilter_subsys,
&hfi_netlink_netfilter_family,
&hfi_netlink_netfilter_version,
&hfi_netlink_netfilter_resid,
&hfi_nfq_type,
&hfi_nfq_attr,
&hfi_nfq_config_command_command,
&hfi_nfq_config_command_pf,
&hfi_nfq_config_params_copyrange,
&hfi_nfq_config_params_copymode,
&hfi_nfq_config_queue_maxlen,
&hfi_nfq_config_mask,
&hfi_nfq_config_flags,
&hfi_nfq_config_attr,
&hfi_nfq_verdict_verdict,
&hfi_nfq_verdict_id,
&hfi_nfq_packet_id,
&hfi_nfq_packet_hwprotocol,
&hfi_nfq_packet_hook,
&hfi_nfq_nfmark,
&hfi_nfq_timestamp,
&hfi_nfq_ifindex_indev,
&hfi_nfq_ifindex_outdev,
&hfi_nfq_ifindex_physindev,
&hfi_nfq_ifindex_physoutdev,
&hfi_nfq_hwaddr_len,
&hfi_nfq_hwaddr_addr,
&hfi_nfq_ctinfo,
&hfi_nfq_caplen,
&hfi_nfq_uid,
&hfi_nfq_gid,
&hfi_netlink_netfilter_ulog_type,
&hfi_ipset_command,
&hfi_ipset_attr,
&hfi_ipset_cadt_attr,
&hfi_ipset_cadt_attr_cidr,
&hfi_ipset_cadt_attr_timeout,
&hfi_ipset_cadt_attr_cadt_flags,
&hfi_ipset_attr_setname,
&hfi_ipset_attr_typename,
&hfi_ipset_attr_family,
&hfi_ipset_attr_flags,
&hfi_ipset_adt_attr,
&hfi_ipset_adt_attr_comment,
&hfi_ipset_ip_attr,
&hfi_ipset_ip_attr_ipv4,
&hfi_ipset_ip_attr_ipv6,
};
#endif
static gint *ett[] = {
&ett_netlink_netfilter,
&ett_nfq_config_attr,
&ett_nfq_attr,
&ett_ipset_attr,
&ett_ipset_cadt_attr,
&ett_ipset_adt_attr,
&ett_ipset_ip_attr,
};
proto_netlink_netfilter = proto_register_protocol("Linux netlink netfilter protocol", "netfilter", "netlink-netfilter" );
hfi_netlink_netfilter = proto_registrar_get_nth(proto_netlink_netfilter);
proto_register_fields(proto_netlink_netfilter, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
netlink_netfilter = create_dissector_handle(dissect_netlink_netfilter, proto_netlink_netfilter);
}
void
proto_reg_handoff_netlink_netfilter(void)
{
dissector_add_uint("netlink.protocol", WS_NETLINK_NETFILTER, netlink_netfilter);
nflog_handle = find_dissector_add_dependency("nflog", hfi_netlink_netfilter->id);
ethertype_table = find_dissector_table("ethertype");
}
