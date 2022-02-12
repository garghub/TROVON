static int
dissect_netfilter_queue(tvbuff_t *tvb _U_, netlink_netfilter_info_t *info, proto_tree *tree, int offset)
{
enum ws_nfqnl_msg_types type = (enum ws_nfqnl_msg_types) (info->data->type & 0xff);
proto_tree_add_uint(tree, &hfi_netlink_netfilter_queue_type, NULL, 0, 0, info->data->type);
switch (type) {
default:
break;
}
return offset;
}
static int
dissect_netfilter_ulog(tvbuff_t *tvb, netlink_netfilter_info_t *info, proto_tree *tree, int offset)
{
enum ws_nfulnl_msg_types type = (enum ws_nfulnl_msg_types) (info->data->type & 0xff);
proto_tree_add_uint(tree, &hfi_netlink_netfilter_ulog_type, NULL, 0, 0, info->data->type);
switch (type) {
case WS_NFULNL_MSG_PACKET:
call_dissector(nflog_handle, tvb, info->pinfo, tree);
break;
default:
break;
}
return offset;
}
static int
dissect_netlink_netfilter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *_data)
{
struct packet_netlink_data *data = NULL;
netlink_netfilter_info_t info;
int offset;
if (_data) {
if (((struct packet_netlink_data *) _data)->magic == PACKET_NETLINK_MAGIC)
data = (struct packet_netlink_data *) _data;
}
DISSECTOR_ASSERT(data);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Netlink netfilter");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
proto_item_set_text(tree, "Linux netlink netfilter message");
proto_tree_add_uint(tree, &hfi_netlink_netfilter_subsys, NULL, 0, 0, data->type);
}
info.encoding = data->encoding;
info.pinfo = pinfo;
info.data = data;
offset = 0;
switch (data->type >> 8) {
case WS_NFNL_SUBSYS_QUEUE:
offset = dissect_netfilter_queue(tvb, &info, tree, offset);
break;
case WS_NFNL_SUBSYS_ULOG:
offset = dissect_netfilter_ulog(tvb, &info, tree, offset);
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
&hfi_netlink_netfilter_queue_type,
&hfi_netlink_netfilter_ulog_type,
};
#endif
static gint *ett[] = {
&ett_netlink_netfilter,
};
int proto_netlink_netfilter;
proto_netlink_netfilter = proto_register_protocol("Linux netlink netfilter protocol", "netfilter", "netlink-netfilter" );
hfi_netlink_netfilter = proto_registrar_get_nth(proto_netlink_netfilter);
proto_register_fields(proto_netlink_netfilter, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
netlink_netfilter = new_create_dissector_handle(dissect_netlink_netfilter, proto_netlink_netfilter);
}
void
proto_reg_handoff_netlink_netfilter(void)
{
dissector_add_uint("netlink.protocol", WS_NETLINK_NETFILTER, netlink_netfilter);
nflog_handle = find_dissector("nflog");
}
