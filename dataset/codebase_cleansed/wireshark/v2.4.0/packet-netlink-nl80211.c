static int
dissect_nl80211_attrs(tvbuff_t *tvb, void *data, proto_tree *tree, int nla_type, int offset, int len)
{
enum ws_nl80211_commands type = (enum ws_nl80211_commands) nla_type;
genl_info_t *genl_info = (genl_info_t *)data;
switch (type) {
default:
if (len) {
if (len == 2) {
proto_tree_add_item(tree, &hfi_nl80211_attr_value16, tvb, offset, len, genl_info->encoding);
} else if (len == 4) {
proto_tree_add_item(tree, &hfi_nl80211_attr_value32, tvb, offset, len, genl_info->encoding);
} else {
proto_tree_add_item(tree, &hfi_nl80211_attr_value, tvb, offset, len, genl_info->encoding);
}
offset += len;
}
break;
}
return offset;
}
static int
dissect_netlink_nl80211(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
genl_info_t *genl_info = (genl_info_t *)data;
proto_tree *nlmsg_tree;
proto_item *pi;
int offset;
DISSECTOR_ASSERT(genl_info);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "nl80211");
col_clear(pinfo->cinfo, COL_INFO);
offset = dissect_genl_header(tvb, genl_info, &hfi_nl80211_cmd);
pi = proto_tree_add_item(tree, proto_registrar_get_nth(proto_netlink_nl80211), tvb, offset, -1, ENC_NA);
nlmsg_tree = proto_item_add_subtree(pi, ett_nl80211);
offset = dissect_netlink_attributes(tvb, &hfi_nl80211_attr_type, ett_nl80211_attr, genl_info, genl_info->data, nlmsg_tree, offset, -1, dissect_nl80211_attrs);
return offset;
}
void
proto_register_netlink_nl80211(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_nl80211_cmd,
&hfi_nl80211_attr_type,
&hfi_nl80211_attr_value,
&hfi_nl80211_attr_value16,
&hfi_nl80211_attr_value32,
};
#endif
static gint *ett[] = {
&ett_nl80211,
&ett_nl80211_attr,
};
proto_netlink_nl80211 = proto_register_protocol("Linux 802.11 Netlink", "nl80211", "nl80211");
hfi_netlink_nl80211 = proto_registrar_get_nth(proto_netlink_nl80211);
proto_register_fields(proto_netlink_nl80211, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
netlink_nl80211_handle = create_dissector_handle(dissect_netlink_nl80211, proto_netlink_nl80211);
}
void
proto_reg_handoff_netlink_nl80211(void)
{
dissector_add_string("genl.family", "nl80211", netlink_nl80211_handle);
}
