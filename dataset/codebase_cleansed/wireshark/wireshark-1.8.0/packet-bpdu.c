static void
dissect_bpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 protocol_identifier;
guint8 protocol_version_identifier;
guint8 bpdu_type;
guint8 flags;
guint16 root_identifier_bridge_priority;
guint16 root_identifier_system_id_extension = 0;
const guint8 *root_identifier_mac;
gchar *root_identifier_mac_str;
guint32 root_path_cost;
guint16 bridge_identifier_bridge_priority;
guint16 bridge_identifier_system_id_extension = 0;
const guint8 *bridge_identifier_mac;
gchar *bridge_identifier_mac_str;
guint16 port_identifier;
double message_age;
double max_age;
double hello_time;
double forward_delay;
guint8 version_1_length;
guint16 version_3_length;
guint8 config_format_selector;
guint16 cist_bridge_identifier_bridge_priority;
guint16 cist_bridge_identifier_system_id_extension = 0;
const guint8 *cist_bridge_identifier_mac;
gchar *cist_bridge_identifier_mac_str;
guint16 msti_mstid;
guint32 msti_regional_root_mstid, msti_regional_root_priority;
const guint8 *msti_regional_root_mac;
gchar *msti_regional_root_mac_str;
guint16 msti_bridge_identifier_priority, msti_port_identifier_priority;
const guint8 *msti_bridge_identifier_mac;
gchar *msti_bridge_identifier_mac_str;
int total_msti_length, offset, msti, msti_format;
proto_tree *bpdu_tree;
proto_tree *mstp_tree, *msti_tree;
proto_item *bpdu_item;
proto_item *mstp_item, *msti_item;
proto_tree *flags_tree;
proto_item *flags_item;
proto_tree *root_id_tree;
proto_item *root_id_item;
proto_tree *bridge_id_tree;
proto_item *bridge_id_item;
proto_tree *cist_bridge_id_tree;
proto_item *cist_bridge_id_item;
proto_item *hidden_item;
const char *sep;
if (pinfo->dl_dst.type == AT_ETHER) {
const guint8 *dstaddr;
dstaddr = pinfo->dl_dst.data;
if(dstaddr[0] == 0x01 && dstaddr[1] == 0x80 &&
dstaddr[2] == 0xC2 && dstaddr[3] == 0x00 &&
dstaddr[4] == 0x00 && ((dstaddr[5] & 0xF0) == 0x20)) {
switch (dstaddr[5]) {
case 0x20:
call_dissector(gmrp_handle, tvb, pinfo, tree);
return;
case 0x21:
call_dissector(gvrp_handle, tvb, pinfo, tree);
return;
}
pinfo->current_proto = "GARP";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GARP");
col_add_fstr(pinfo->cinfo, COL_INFO,
"Unknown GARP application (0x%02X)",
dstaddr[5]);
return;
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "STP");
col_clear(pinfo->cinfo, COL_INFO);
bpdu_type = tvb_get_guint8(tvb, BPDU_TYPE);
protocol_version_identifier = tvb_get_guint8(tvb, BPDU_VERSION_IDENTIFIER);
switch (bpdu_type) {
case BPDU_TYPE_CONF:
case BPDU_TYPE_RST:
flags = tvb_get_guint8(tvb, BPDU_FLAGS);
root_identifier_bridge_priority = tvb_get_ntohs(tvb,BPDU_ROOT_IDENTIFIER);
if (bpdu_use_system_id_extensions ) {
root_identifier_system_id_extension = root_identifier_bridge_priority & 0x0fff;
root_identifier_bridge_priority &= 0xf000;
}
root_identifier_mac = tvb_get_ptr(tvb, BPDU_ROOT_IDENTIFIER + 2, 6);
root_identifier_mac_str = ether_to_str(root_identifier_mac);
root_path_cost = tvb_get_ntohl(tvb, BPDU_ROOT_PATH_COST);
port_identifier = tvb_get_ntohs(tvb, BPDU_PORT_IDENTIFIER);
break;
default:
flags = 0;
root_identifier_bridge_priority = 0;
root_identifier_mac = NULL;
root_identifier_mac_str = NULL;
root_path_cost = 0;
port_identifier = 0;
break;
}
switch (bpdu_type) {
case BPDU_TYPE_CONF:
if (bpdu_use_system_id_extensions ) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Conf. %sRoot = %d/%d/%s Cost = %d Port = 0x%04x",
flags & 0x1 ? "TC + " : "",
root_identifier_bridge_priority,
root_identifier_system_id_extension,
root_identifier_mac_str,
root_path_cost, port_identifier);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO,
"Conf. %sRoot = %d/%s Cost = %d Port = 0x%04x",
flags & 0x1 ? "TC + " : "",
root_identifier_bridge_priority, root_identifier_mac_str,
root_path_cost, port_identifier);
}
break;
case BPDU_TYPE_TOPOLOGY_CHANGE:
col_set_str(pinfo->cinfo, COL_INFO, "Topology Change Notification");
break;
case BPDU_TYPE_RST:
if (bpdu_use_system_id_extensions ) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%cST. %sRoot = %d/%d/%s Cost = %d Port = 0x%04x",
protocol_version_identifier == 3 ? 'M':'R',
flags & 0x1 ? "TC + " : "",
root_identifier_bridge_priority,
root_identifier_system_id_extension,
root_identifier_mac_str,
root_path_cost, port_identifier);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%cST. %sRoot = %d/%s Cost = %d Port = 0x%04x",
protocol_version_identifier == 3 ? 'M':'R',
flags & 0x1 ? "TC + " : "",
root_identifier_bridge_priority, root_identifier_mac_str,
root_path_cost, port_identifier);
}
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown BPDU type (%u)", bpdu_type);
break;
}
if (tree) {
bpdu_item = proto_tree_add_protocol_format(tree, proto_bpdu, tvb, 0, -1,
"Spanning Tree Protocol");
bpdu_tree = proto_item_add_subtree(bpdu_item, ett_bpdu);
protocol_identifier = tvb_get_ntohs(tvb, BPDU_IDENTIFIER);
proto_tree_add_uint(bpdu_tree, hf_bpdu_proto_id, tvb, BPDU_IDENTIFIER, 2,
protocol_identifier);
proto_tree_add_uint(bpdu_tree, hf_bpdu_version_id, tvb,
BPDU_VERSION_IDENTIFIER, 1,
protocol_version_identifier);
switch (protocol_version_identifier) {
case 0:
break;
case 2:
case 3:
break;
default:
proto_tree_add_text(bpdu_tree, tvb, BPDU_VERSION_IDENTIFIER, 1,
" (Warning: this version of Wireshark only knows about versions 0, 2 & 3)");
break;
}
proto_tree_add_uint(bpdu_tree, hf_bpdu_type, tvb, BPDU_TYPE, 1, bpdu_type);
if (bpdu_type == BPDU_TYPE_TOPOLOGY_CHANGE) {
set_actual_length(tvb, TC_BPDU_SIZE);
return;
}
if (bpdu_type != BPDU_TYPE_CONF && bpdu_type != BPDU_TYPE_RST) {
proto_tree_add_text(bpdu_tree, tvb, BPDU_TYPE + 1, -1,
"Unknown BPDU type data");
return;
}
bridge_identifier_bridge_priority = tvb_get_ntohs(tvb, BPDU_BRIDGE_IDENTIFIER);
if (bpdu_use_system_id_extensions ) {
bridge_identifier_system_id_extension = bridge_identifier_bridge_priority & 0x0fff;
bridge_identifier_bridge_priority &= 0xf000;
}
bridge_identifier_mac = tvb_get_ptr(tvb, BPDU_BRIDGE_IDENTIFIER + 2, 6);
bridge_identifier_mac_str = ether_to_str(bridge_identifier_mac);
flags_item = proto_tree_add_uint(bpdu_tree, hf_bpdu_flags, tvb,
BPDU_FLAGS, 1, flags);
flags_tree = proto_item_add_subtree(flags_item, ett_bpdu_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_TCACK, flags_item,
"%sTopology Change Acknowledgment");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_tcack, tvb,
BPDU_FLAGS, 1, flags);
if (bpdu_type == BPDU_TYPE_RST) {
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_AGREEMENT, flags_item,
"%sAgreement");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_agreement, tvb,
BPDU_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_FORWARDING, flags_item,
"%sForwarding");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_forwarding, tvb,
BPDU_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_LEARNING, flags_item,
"%sLearning");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_learning, tvb,
BPDU_FLAGS, 1, flags);
if (flags_item) {
guint8 port_role;
port_role = (flags & BPDU_FLAGS_PORT_ROLE_MASK) >> BPDU_FLAGS_PORT_ROLE_SHIFT;
proto_item_append_text(flags_item, "%sPort Role: %s", sep,
val_to_str(port_role, role_vals,
"Unknown (%u)"));
}
sep = cont_sep;
proto_tree_add_uint(flags_tree, hf_bpdu_flags_port_role, tvb,
BPDU_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_PROPOSAL, flags_item,
"%sProposal");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_proposal, tvb,
BPDU_FLAGS, 1, flags);
}
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_TC, flags_item,
"%sTopology Change");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_tc, tvb,
BPDU_FLAGS, 1, flags);
if (sep != initial_sep) {
proto_item_append_text(flags_item, ")");
}
if (bpdu_use_system_id_extensions) {
root_id_item = proto_tree_add_text(bpdu_tree, tvb,
BPDU_ROOT_IDENTIFIER, 8,
"Root Identifier: %d / %d / %s",
root_identifier_bridge_priority,
root_identifier_system_id_extension,
root_identifier_mac_str);
root_id_tree = proto_item_add_subtree(root_id_item, ett_root_id);
proto_tree_add_uint(root_id_tree, hf_bpdu_root_prio, tvb,
BPDU_ROOT_IDENTIFIER , 1,
root_identifier_bridge_priority);
proto_tree_add_uint(root_id_tree, hf_bpdu_root_sys_id_ext, tvb,
BPDU_ROOT_IDENTIFIER , 2,
root_identifier_system_id_extension);
proto_tree_add_ether_format_value(root_id_tree, hf_bpdu_root_mac,
tvb, BPDU_ROOT_IDENTIFIER + 2, 6,
root_identifier_mac,
"%s", root_identifier_mac_str);
} else {
root_id_item = proto_tree_add_text(bpdu_tree, tvb,
BPDU_ROOT_IDENTIFIER, 8,
"Root Identifier: %d / %s",
root_identifier_bridge_priority,
root_identifier_mac_str);
root_id_tree = proto_item_add_subtree(root_id_item, ett_root_id);
proto_tree_add_uint(root_id_tree, hf_bpdu_root_prio, tvb,
BPDU_ROOT_IDENTIFIER , 2,
root_identifier_bridge_priority);
proto_tree_add_ether_format_value(root_id_tree, hf_bpdu_root_mac,
tvb, BPDU_ROOT_IDENTIFIER + 2, 6,
root_identifier_mac,
"%s", root_identifier_mac_str);
}
proto_tree_add_uint(bpdu_tree, hf_bpdu_root_cost, tvb,
BPDU_ROOT_PATH_COST, 4, root_path_cost);
if (bpdu_use_system_id_extensions) {
bridge_id_item = proto_tree_add_text(bpdu_tree, tvb,
BPDU_BRIDGE_IDENTIFIER, 8,
"Bridge Identifier: %d / %d / %s",
bridge_identifier_bridge_priority,
bridge_identifier_system_id_extension,
bridge_identifier_mac_str);
bridge_id_tree = proto_item_add_subtree(bridge_id_item, ett_bridge_id);
proto_tree_add_uint(bridge_id_tree, hf_bpdu_bridge_prio, tvb,
BPDU_BRIDGE_IDENTIFIER , 1,
bridge_identifier_bridge_priority);
proto_tree_add_uint(bridge_id_tree, hf_bpdu_bridge_sys_id_ext, tvb,
BPDU_BRIDGE_IDENTIFIER , 2,
bridge_identifier_system_id_extension);
proto_tree_add_ether_format_value(bridge_id_tree, hf_bpdu_bridge_mac,
tvb, BPDU_BRIDGE_IDENTIFIER + 2, 6,
bridge_identifier_mac,
"%s", bridge_identifier_mac_str);
} else {
bridge_id_item = proto_tree_add_text(bpdu_tree, tvb,
BPDU_BRIDGE_IDENTIFIER, 8,
"Bridge Identifier: %d / %s",
bridge_identifier_bridge_priority,
bridge_identifier_mac_str);
bridge_id_tree = proto_item_add_subtree(bridge_id_item, ett_bridge_id);
proto_tree_add_uint(bridge_id_tree, hf_bpdu_bridge_prio, tvb,
BPDU_BRIDGE_IDENTIFIER , 2,
bridge_identifier_bridge_priority);
proto_tree_add_ether_format_value(bridge_id_tree, hf_bpdu_bridge_mac,
tvb, BPDU_BRIDGE_IDENTIFIER + 2, 6,
bridge_identifier_mac,
"%s", bridge_identifier_mac_str);
}
proto_tree_add_uint(bpdu_tree, hf_bpdu_port_id, tvb,
BPDU_PORT_IDENTIFIER, 2, port_identifier);
message_age = tvb_get_ntohs(tvb, BPDU_MESSAGE_AGE) / 256.0;
proto_tree_add_double(bpdu_tree, hf_bpdu_msg_age, tvb, BPDU_MESSAGE_AGE, 2,
message_age);
max_age = tvb_get_ntohs(tvb, BPDU_MAX_AGE) / 256.0;
proto_tree_add_double(bpdu_tree, hf_bpdu_max_age, tvb, BPDU_MAX_AGE, 2,
max_age);
hello_time = tvb_get_ntohs(tvb, BPDU_HELLO_TIME) / 256.0;
proto_tree_add_double(bpdu_tree, hf_bpdu_hello_time, tvb,
BPDU_HELLO_TIME, 2, hello_time);
forward_delay = tvb_get_ntohs(tvb, BPDU_FORWARD_DELAY) / 256.0;
proto_tree_add_double(bpdu_tree, hf_bpdu_forward_delay, tvb,
BPDU_FORWARD_DELAY, 2, forward_delay);
if (bpdu_type == BPDU_TYPE_CONF) {
set_actual_length(tvb, CONF_BPDU_SIZE);
return;
}
version_1_length = tvb_get_guint8(tvb, BPDU_VERSION_1_LENGTH);
proto_tree_add_uint(bpdu_tree, hf_bpdu_version_1_length, tvb,
BPDU_VERSION_1_LENGTH, 1, version_1_length);
if (protocol_version_identifier >= 3 && version_1_length == 0 &&
tvb_reported_length(tvb) >= 102) {
version_3_length = tvb_get_ntohs(tvb, BPDU_VERSION_3_LENGTH);
proto_tree_add_uint(bpdu_tree, hf_bpdu_version_3_length, tvb,
BPDU_VERSION_3_LENGTH, 2, version_3_length);
config_format_selector = tvb_get_guint8(tvb, BPDU_MST_CONFIG_FORMAT_SELECTOR);
if (version_3_length != 0) {
msti_format = MSTI_FORMAT_IEEE_8021S;
if (version_3_length >= VERSION_3_STATIC_LENGTH) {
total_msti_length = version_3_length - VERSION_3_STATIC_LENGTH;
} else {
total_msti_length = version_3_length * MSTI_MESSAGE_SIZE;
}
} else {
if (tvb_reported_length(tvb) == (guint)config_format_selector + MST_BPDU_SIZE + 1 ) {
msti_format = MSTI_FORMAT_ALTERNATIVE;
total_msti_length = config_format_selector - VERSION_3_STATIC_LENGTH;
} else {
msti_format = MSTI_FORMAT_UNKNOWN;
total_msti_length = 0;
}
}
set_actual_length(tvb, BPDU_MSTI + total_msti_length);
mstp_item = proto_tree_add_text(bpdu_tree, tvb, BPDU_VERSION_3_LENGTH,
-1, "MST Extension");
mstp_tree = proto_item_add_subtree(mstp_item, ett_mstp);
proto_tree_add_item(mstp_tree, hf_bpdu_mst_config_format_selector, tvb,
BPDU_MST_CONFIG_FORMAT_SELECTOR, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mstp_tree, hf_bpdu_mst_config_name, tvb,
BPDU_MST_CONFIG_NAME, 32, ENC_ASCII|ENC_NA);
proto_tree_add_item(mstp_tree, hf_bpdu_mst_config_revision_level, tvb,
BPDU_MST_CONFIG_REVISION_LEVEL, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mstp_tree, hf_bpdu_mst_config_digest, tvb,
BPDU_MST_CONFIG_DIGEST, 16, ENC_NA);
switch(msti_format) {
case MSTI_FORMAT_IEEE_8021S:
proto_tree_add_item(mstp_tree, hf_bpdu_cist_internal_root_path_cost, tvb,
BPDU_CIST_INTERNAL_ROOT_PATH_COST, 4, ENC_BIG_ENDIAN);
cist_bridge_identifier_bridge_priority = tvb_get_ntohs(tvb,BPDU_CIST_BRIDGE_IDENTIFIER);
cist_bridge_identifier_mac = tvb_get_ptr(tvb, BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6);
cist_bridge_identifier_mac_str = ether_to_str(cist_bridge_identifier_mac);
if (bpdu_use_system_id_extensions ) {
cist_bridge_identifier_system_id_extension = cist_bridge_identifier_bridge_priority & 0x0fff;
cist_bridge_identifier_bridge_priority &= 0xf000;
cist_bridge_id_item = proto_tree_add_text(mstp_tree, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER, 8,
"CIST Bridge Identifier: %d / %d / %s",
cist_bridge_identifier_bridge_priority,
cist_bridge_identifier_system_id_extension,
cist_bridge_identifier_mac_str);
cist_bridge_id_tree = proto_item_add_subtree(cist_bridge_id_item, ett_cist_bridge_id);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_prio, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER , 1,
cist_bridge_identifier_bridge_priority);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_sys_id_ext, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER , 2,
cist_bridge_identifier_system_id_extension);
proto_tree_add_ether_format_value(cist_bridge_id_tree, hf_bpdu_cist_bridge_mac,
tvb, BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6,
cist_bridge_identifier_mac,
"%s", cist_bridge_identifier_mac_str);
} else {
cist_bridge_id_item = proto_tree_add_text(mstp_tree, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER, 8,
"CIST Bridge Identifier: %d / %s",
cist_bridge_identifier_bridge_priority,
cist_bridge_identifier_mac_str);
cist_bridge_id_tree = proto_item_add_subtree(cist_bridge_id_item, ett_cist_bridge_id);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_prio, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER , 2,
cist_bridge_identifier_bridge_priority);
proto_tree_add_ether_format_value(cist_bridge_id_tree, hf_bpdu_cist_bridge_mac,
tvb, BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6,
cist_bridge_identifier_mac,
"%s", cist_bridge_identifier_mac_str);
}
break;
case MSTI_FORMAT_ALTERNATIVE:
cist_bridge_identifier_bridge_priority = tvb_get_ntohs(tvb,ALT_BPDU_CIST_BRIDGE_IDENTIFIER);
cist_bridge_identifier_mac = tvb_get_ptr(tvb, ALT_BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6);
cist_bridge_identifier_mac_str = ether_to_str(cist_bridge_identifier_mac);
if (bpdu_use_system_id_extensions ) {
cist_bridge_identifier_system_id_extension = cist_bridge_identifier_bridge_priority & 0x0fff;
cist_bridge_identifier_bridge_priority &= 0xf000;
cist_bridge_id_item = proto_tree_add_text(mstp_tree, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER, 8,
"CIST Bridge Identifier: %d / %d / %s",
cist_bridge_identifier_bridge_priority,
cist_bridge_identifier_system_id_extension,
cist_bridge_identifier_mac_str);
cist_bridge_id_tree = proto_item_add_subtree(cist_bridge_id_item, ett_cist_bridge_id);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_prio, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER , 1,
cist_bridge_identifier_bridge_priority);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_sys_id_ext, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER , 2,
cist_bridge_identifier_system_id_extension);
proto_tree_add_ether_format_value(cist_bridge_id_tree, hf_bpdu_cist_bridge_mac,
tvb, ALT_BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6,
cist_bridge_identifier_mac,
"%s", cist_bridge_identifier_mac_str);
} else {
cist_bridge_id_item = proto_tree_add_text(mstp_tree, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER, 8,
"CIST Bridge Identifier: %d / %s",
cist_bridge_identifier_bridge_priority,
cist_bridge_identifier_mac_str);
cist_bridge_id_tree = proto_item_add_subtree(cist_bridge_id_item, ett_cist_bridge_id);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_prio, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER , 2,
cist_bridge_identifier_bridge_priority);
proto_tree_add_ether_format_value(cist_bridge_id_tree, hf_bpdu_cist_bridge_mac,
tvb, ALT_BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6,
cist_bridge_identifier_mac,
"%s", cist_bridge_identifier_mac_str);
}
proto_tree_add_item(mstp_tree, hf_bpdu_cist_internal_root_path_cost, tvb,
ALT_BPDU_CIST_INTERNAL_ROOT_PATH_COST, 4, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(mstp_tree, hf_bpdu_cist_remaining_hops, tvb,
BPDU_CIST_REMAINING_HOPS, 1, ENC_BIG_ENDIAN);
offset = BPDU_MSTI;
msti = 1;
while (total_msti_length > 0) {
switch(msti_format) {
case MSTI_FORMAT_IEEE_8021S:
msti_regional_root_mstid = tvb_get_guint8(tvb, offset+ MSTI_REGIONAL_ROOT);
msti_regional_root_priority = (msti_regional_root_mstid &0xf0) << 8;
msti_regional_root_mstid = ((msti_regional_root_mstid & 0x0f) << 8) +
tvb_get_guint8(tvb, offset+ MSTI_REGIONAL_ROOT+1);
msti_regional_root_mac = tvb_get_ptr(tvb, offset+ MSTI_REGIONAL_ROOT + 2, 6);
msti_regional_root_mac_str = ether_to_str(msti_regional_root_mac);
msti_item = proto_tree_add_text(mstp_tree, tvb, offset, 16,
"MSTID %d, Regional Root Identifier %d / %s",
msti_regional_root_mstid,
msti_regional_root_priority,
msti_regional_root_mac_str);
msti_tree = proto_item_add_subtree(msti_item, ett_msti);
flags = tvb_get_guint8(tvb, offset+MSTI_FLAGS);
flags_item = proto_tree_add_uint(msti_tree, hf_bpdu_msti_flags, tvb,
offset+MSTI_FLAGS, 1, flags);
flags_tree = proto_item_add_subtree(flags_item, ett_bpdu_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_TCACK, flags_item, "%sMaster");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_tcack, tvb,
offset+MSTI_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_AGREEMENT, flags_item, "%sAgreement");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_agreement, tvb,
offset+MSTI_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_FORWARDING, flags_item, "%sForwarding");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_forwarding, tvb,
offset+MSTI_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_LEARNING, flags_item, "%sLearning");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_learning, tvb,
offset+MSTI_FLAGS, 1, flags);
if (flags_item) {
guint8 port_role;
port_role = (flags & BPDU_FLAGS_PORT_ROLE_MASK) >> BPDU_FLAGS_PORT_ROLE_SHIFT;
proto_item_append_text(flags_item, "%sPort Role: %s", sep,
val_to_str(port_role, role_vals,
"Unknown (%u)"));
}
proto_tree_add_uint(flags_tree, hf_bpdu_flags_port_role, tvb,
offset+MSTI_FLAGS, 1, flags);
sep = cont_sep;
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_PROPOSAL, flags_item, "%sProposal");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_proposal, tvb,
offset+MSTI_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_TC, flags_item, "%sTopology Change");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_tc, tvb,
offset+MSTI_FLAGS, 1, flags);
if (sep != initial_sep) {
proto_item_append_text(flags_item, ")");
}
hidden_item = proto_tree_add_ether(msti_tree, hf_bpdu_msti_regional_root_mac, tvb,
offset + MSTI_REGIONAL_ROOT + 2, 6,
msti_regional_root_mac);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(msti_tree, tvb, offset + MSTI_REGIONAL_ROOT, 8,
"MSTID %d, priority %d Root Identifier %s",
msti_regional_root_mstid,
msti_regional_root_priority,
msti_regional_root_mac_str);
proto_tree_add_item(msti_tree, hf_bpdu_msti_internal_root_path_cost, tvb,
offset+MSTI_INTERNAL_ROOT_PATH_COST, 4, ENC_BIG_ENDIAN);
msti_bridge_identifier_priority = tvb_get_guint8(tvb, offset+MSTI_BRIDGE_IDENTIFIER_PRIORITY) >> 4;
msti_port_identifier_priority = tvb_get_guint8(tvb, offset+MSTI_PORT_IDENTIFIER_PRIORITY) >> 4;
proto_tree_add_uint(msti_tree, hf_bpdu_msti_bridge_identifier_priority, tvb,
offset+MSTI_BRIDGE_IDENTIFIER_PRIORITY, 1,
msti_bridge_identifier_priority);
proto_tree_add_uint(msti_tree, hf_bpdu_msti_port_identifier_priority, tvb,
offset+MSTI_PORT_IDENTIFIER_PRIORITY, 1,
msti_port_identifier_priority);
proto_tree_add_item(msti_tree, hf_bpdu_msti_remaining_hops, tvb,
offset + MSTI_REMAINING_HOPS, 1, ENC_BIG_ENDIAN);
total_msti_length -= MSTI_MESSAGE_SIZE;
offset += MSTI_MESSAGE_SIZE;
break;
case MSTI_FORMAT_ALTERNATIVE:
msti_regional_root_mstid = tvb_get_guint8(tvb, offset+ ALT_MSTI_REGIONAL_ROOT);
msti_regional_root_priority = (msti_regional_root_mstid &0xf0) << 8;
msti_regional_root_mstid = ((msti_regional_root_mstid & 0x0f) << 8) +
tvb_get_guint8(tvb, offset+ ALT_MSTI_REGIONAL_ROOT+1);
msti_regional_root_mac = tvb_get_ptr(tvb, offset+ ALT_MSTI_REGIONAL_ROOT + 2, 6);
msti_regional_root_mac_str = ether_to_str(msti_regional_root_mac);
msti_item = proto_tree_add_text(mstp_tree, tvb, offset, 16,
"MSTID %d, Regional Root Identifier %d / %s",
msti_regional_root_mstid,
msti_regional_root_priority,
msti_regional_root_mac_str);
msti_tree = proto_item_add_subtree(msti_item, ett_msti);
msti_mstid = tvb_get_ntohs(tvb, offset+ ALT_MSTI_MSTID);
proto_tree_add_text(msti_tree, tvb, offset+ALT_MSTI_MSTID, 2,
"MSTID: %d", msti_mstid);
flags = tvb_get_guint8(tvb, offset+ALT_MSTI_FLAGS);
flags_item = proto_tree_add_uint(msti_tree, hf_bpdu_msti_flags, tvb,
offset+ALT_MSTI_FLAGS, 1, flags);
flags_tree = proto_item_add_subtree(flags_item, ett_bpdu_flags);
sep = initial_sep;
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_TCACK, flags_item, "%sMaster");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_tcack, tvb,
offset+ALT_MSTI_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_AGREEMENT, flags_item, "%sAgreement");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_agreement, tvb,
offset+ALT_MSTI_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_FORWARDING, flags_item, "%sForwarding");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_forwarding, tvb,
offset+ALT_MSTI_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_LEARNING, flags_item, "%sLearning");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_learning, tvb,
offset+ALT_MSTI_FLAGS, 1, flags);
if (flags_item) {
guint8 port_role;
port_role = (flags & BPDU_FLAGS_PORT_ROLE_MASK) >> BPDU_FLAGS_PORT_ROLE_SHIFT;
proto_item_append_text(flags_item, "%sPort Role: %s", sep,
val_to_str(port_role, role_vals,
"Unknown (%u)"));
}
proto_tree_add_uint(flags_tree, hf_bpdu_flags_port_role, tvb,
offset+ALT_MSTI_FLAGS, 1, flags);
sep = cont_sep;
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_PROPOSAL, flags_item, "%sProposal");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_proposal, tvb,
offset+ALT_MSTI_FLAGS, 1, flags);
APPEND_BOOLEAN_FLAG(flags & BPDU_FLAGS_TC, flags_item, "%sTopology Change");
proto_tree_add_boolean(flags_tree, hf_bpdu_flags_tc, tvb,
offset+ALT_MSTI_FLAGS, 1, flags);
if (sep != initial_sep) {
proto_item_append_text(flags_item, ")");
}
hidden_item = proto_tree_add_ether(msti_tree, hf_bpdu_msti_regional_root_mac, tvb,
offset + ALT_MSTI_REGIONAL_ROOT + 2, 6,
msti_regional_root_mac);
PROTO_ITEM_SET_HIDDEN(hidden_item);
proto_tree_add_text(msti_tree, tvb, offset + ALT_MSTI_REGIONAL_ROOT, 8,
"MSTI Regional Root Identifier: %d / %d / %s",
msti_regional_root_mstid,
msti_regional_root_priority,
msti_regional_root_mac_str);
proto_tree_add_item(msti_tree, hf_bpdu_msti_internal_root_path_cost, tvb,
offset+ALT_MSTI_INTERNAL_ROOT_PATH_COST, 4, ENC_BIG_ENDIAN);
msti_bridge_identifier_priority = tvb_get_ntohs(tvb, offset+ALT_MSTI_BRIDGE_IDENTIFIER);
msti_bridge_identifier_mac = tvb_get_ptr(tvb, offset+ALT_MSTI_BRIDGE_IDENTIFIER + 2, 6);
msti_bridge_identifier_mac_str = ether_to_str(msti_bridge_identifier_mac);
proto_tree_add_text(msti_tree, tvb, offset+ALT_MSTI_BRIDGE_IDENTIFIER, 8,
"MSTI Bridge Identifier: %d / %d / %s",
msti_bridge_identifier_priority & 0x0fff,
msti_bridge_identifier_priority & 0xf000,
msti_bridge_identifier_mac_str);
msti_port_identifier_priority = tvb_get_ntohs(tvb, offset+ALT_MSTI_PORT_IDENTIFIER);
proto_tree_add_uint(msti_tree, hf_bpdu_msti_port_id, tvb,
offset+ALT_MSTI_PORT_IDENTIFIER, 2, msti_port_identifier_priority);
proto_tree_add_item(msti_tree, hf_bpdu_msti_remaining_hops, tvb,
offset + ALT_MSTI_REMAINING_HOPS, 1, ENC_BIG_ENDIAN);
total_msti_length -= ALT_MSTI_MESSAGE_SIZE;
offset += ALT_MSTI_MESSAGE_SIZE;
break;
}
msti++;
}
}
}
}
void
proto_register_bpdu(void)
{
static hf_register_info hf[] = {
{ &hf_bpdu_proto_id,
{ "Protocol Identifier", "stp.protocol",
FT_UINT16, BASE_HEX, VALS(protocol_id_vals), 0x0,
NULL, HFILL }},
{ &hf_bpdu_version_id,
{ "Protocol Version Identifier", "stp.version",
FT_UINT8, BASE_DEC, VALS(version_id_vals), 0x0,
NULL, HFILL }},
{ &hf_bpdu_type,
{ "BPDU Type", "stp.type",
FT_UINT8, BASE_HEX, VALS(bpdu_type_vals), 0x0,
NULL, HFILL }},
{ &hf_bpdu_flags,
{ "BPDU flags", "stp.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_flags_tcack,
{ "Topology Change Acknowledgment", "stp.flags.tcack",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_TCACK,
NULL, HFILL }},
{ &hf_bpdu_flags_agreement,
{ "Agreement", "stp.flags.agreement",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_AGREEMENT,
NULL, HFILL }},
{ &hf_bpdu_flags_forwarding,
{ "Forwarding", "stp.flags.forwarding",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_FORWARDING,
NULL, HFILL }},
{ &hf_bpdu_flags_learning,
{ "Learning", "stp.flags.learning",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_LEARNING,
NULL, HFILL }},
{ &hf_bpdu_flags_port_role,
{ "Port Role", "stp.flags.port_role",
FT_UINT8, BASE_DEC, VALS(role_vals), BPDU_FLAGS_PORT_ROLE_MASK,
NULL, HFILL }},
{ &hf_bpdu_flags_proposal,
{ "Proposal", "stp.flags.proposal",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_PROPOSAL,
NULL, HFILL }},
{ &hf_bpdu_flags_tc,
{ "Topology Change", "stp.flags.tc",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), BPDU_FLAGS_TC,
NULL, HFILL }},
{ &hf_bpdu_root_prio,
{ "Root Bridge Priority", "stp.root.prio",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_root_sys_id_ext,
{ "Root Bridge System ID Extension", "stp.root.ext",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_root_mac,
{ "Root Bridge System ID", "stp.root.hw",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_root_cost,
{ "Root Path Cost", "stp.root.cost",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_bridge_prio,
{ "Bridge Priority", "stp.bridge.prio",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_bridge_sys_id_ext,
{ "Bridge System ID Extension", "stp.bridge.ext",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_bridge_mac,
{ "Bridge System ID", "stp.bridge.hw",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_port_id,
{ "Port identifier", "stp.port",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msg_age,
{ "Message Age", "stp.msg_age",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_max_age,
{ "Max Age", "stp.max_age",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_hello_time,
{ "Hello Time", "stp.hello",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_forward_delay,
{ "Forward Delay", "stp.forward",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_version_1_length,
{ "Version 1 Length", "stp.version_1_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_version_3_length,
{ "Version 3 Length", "mstp.version_3_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_mst_config_format_selector,
{ "MST Config ID format selector", "mstp.config_format_selector",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_mst_config_name,
{ "MST Config name", "mstp.config_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_mst_config_revision_level,
{ "MST Config revision", "mstp.config_revision_level",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_mst_config_digest,
{ "MST Config digest", "mstp.config_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_cist_internal_root_path_cost,
{ "CIST Internal Root Path Cost", "mstp.cist_internal_root_path_cost",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_cist_bridge_prio,
{ "CIST Bridge Priority", "mstp.cist_bridge.prio",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_cist_bridge_sys_id_ext,
{ "CIST Bridge Identifier System ID Extension", "mstp.cist_bridge.ext",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_cist_bridge_mac,
{ "CIST Bridge Identifier System ID", "mstp.cist_bridge.hw",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_cist_remaining_hops,
{ "CIST Remaining hops", "mstp.cist_remaining_hops",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_flags,
{ "MSTI flags", "mstp.msti.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_regional_root_mac,
{ "Regional Root", "mstp.msti.root.hw",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_internal_root_path_cost,
{ "Internal root path cost", "mstp.msti.root_cost",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_bridge_identifier_priority,
{ "Bridge Identifier Priority", "mstp.msti.bridge_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_port_identifier_priority,
{ "Port identifier priority", "mstp.msti.port_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_port_id,
{ "Port identifier", "mstp.msti.port",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_remaining_hops,
{ "Remaining hops", "mstp.msti.remaining_hops",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_bpdu,
&ett_bpdu_flags,
&ett_root_id,
&ett_bridge_id,
&ett_mstp,
&ett_msti,
&ett_cist_bridge_id
};
module_t *bpdu_module;
proto_bpdu = proto_register_protocol("Spanning Tree Protocol", "STP", "stp");
proto_register_field_array(proto_bpdu, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("bpdu", dissect_bpdu, proto_bpdu);
bpdu_module = prefs_register_protocol(proto_bpdu, NULL);
prefs_register_bool_preference(bpdu_module, "use_system_id_extension",
"Use 802.1t System ID Extensions",
"Whether the BPDU dissector should use 802.1t System ID Extensions when dissecting the Bridge Identifier",
&bpdu_use_system_id_extensions);
}
void
proto_reg_handoff_bpdu(void)
{
dissector_handle_t bpdu_handle;
gvrp_handle = find_dissector("gvrp");
gmrp_handle = find_dissector("gmrp");
data_handle = find_dissector("data");
bpdu_handle = find_dissector("bpdu");
dissector_add_uint("llc.dsap", SAP_BPDU, bpdu_handle);
dissector_add_uint("chdlctype", CHDLCTYPE_BPDU, bpdu_handle);
dissector_add_uint("llc.cisco_pid", 0x010b, bpdu_handle);
dissector_add_uint("ethertype", ETHERTYPE_STP, bpdu_handle);
}
