static void
dissect_bpdu_cisco(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_bpdu(tvb, pinfo, tree, TRUE);
}
static void
dissect_bpdu_generic(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_bpdu(tvb, pinfo, tree, FALSE);
}
static void
dissect_bpdu_pvst_tlv(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb) {
gboolean pvst_tlv_origvlan_present = FALSE;
guint16 tlv_type, tlv_length;
int offset = BPDU_PVST_TLV;
proto_item * ti = NULL;
proto_item * tlv_length_item = NULL;
proto_tree * tlv_tree = NULL;
if (tvb_reported_length_remaining(tvb, offset) < 4)
expert_add_info(pinfo, tree, &ei_pvst_tlv_truncated);
while (tvb_reported_length_remaining(tvb, offset) >= 4) {
tlv_type = tvb_get_ntohs(tvb, offset);
tlv_length = tvb_get_ntohs(tvb, offset + 2);
tlv_tree = proto_tree_add_subtree(tree, tvb, offset, 4 + tlv_length,
ett_bpdu_pvst_tlv, &ti,
val_to_str(tlv_type, bpdu_pvst_tlv_vals, "Unknown TLV type: 0x%04x"));
proto_tree_add_item(tlv_tree, hf_bpdu_pvst_tlvtype, tvb, offset, 2, ENC_BIG_ENDIAN);
tlv_length_item = proto_tree_add_item(tlv_tree, hf_bpdu_pvst_tlvlength,
tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if (tvb_reported_length_remaining(tvb, offset + 4) < tlv_length) {
expert_add_info(pinfo, tlv_length_item, &ei_pvst_tlv_truncated);
break;
}
offset += 4;
switch (tlv_type) {
case BPDU_PVST_TLV_ORIGVLAN:
if (tlv_length == 2) {
proto_item_append_text(ti, " (PVID): %u", tvb_get_ntohs(tvb, offset));
proto_tree_add_item(tlv_tree, hf_bpdu_pvst_tlv_origvlan, tvb, offset, tlv_length, ENC_BIG_ENDIAN);
pvst_tlv_origvlan_present = TRUE;
}
else
expert_add_info(pinfo, tlv_length_item, &ei_pvst_tlv_length_invalid);
break;
default:
proto_tree_add_item(tlv_tree, hf_bpdu_pvst_tlvvalue, tvb, offset, tlv_length, ENC_NA);
expert_add_info(pinfo, tlv_tree, &ei_pvst_tlv_unknown);
break;
}
offset += tlv_length;
}
if (pvst_tlv_origvlan_present == FALSE)
expert_add_info(pinfo, tree, &ei_pvst_tlv_origvlan_missing);
}
static void
dissect_bpdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean is_bpdu_pvst)
{
guint16 protocol_identifier;
guint8 protocol_version_identifier;
guint8 bpdu_type;
guint8 flags;
guint16 root_identifier_bridge_priority;
guint16 root_identifier_system_id_extension = 0;
const gchar *root_identifier_mac_str;
guint32 root_path_cost;
guint16 bridge_identifier_bridge_priority;
guint16 bridge_identifier_system_id_extension = 0;
const gchar *bridge_identifier_mac_str;
guint16 port_identifier;
double message_age;
double max_age;
double hello_time;
double forward_delay;
guint8 version_1_length;
guint16 version_3_length;
guint16 version_4_length = 0;
guint16 bpdu_version_4_length = 0;
guint8 config_format_selector;
guint16 cist_bridge_identifier_bridge_priority;
guint16 cist_bridge_identifier_system_id_extension = 0;
const gchar *cist_bridge_identifier_mac_str;
guint32 msti_regional_root_mstid, msti_regional_root_priority;
const gchar *msti_regional_root_mac_str;
guint16 msti_bridge_identifier_priority, msti_port_identifier_priority;
int total_msti_length, offset, msti, msti_format;
int msti_length_remaining;
guint8 agree_num = 0, dagree_num = 0;
int spt_offset = 0;
int MCID_LEN = 51;
guint8 spt_agree_data = 0;
proto_tree *bpdu_tree;
proto_tree *mstp_tree, *msti_tree, *spt_tree = NULL, *aux_mcid_tree = NULL, *agreement_tree = NULL;
proto_item *bpdu_item;
proto_item *agreement_item, *proto_id_item, *type_item;
proto_tree *root_id_tree;
proto_tree *bridge_id_tree;
proto_tree *cist_bridge_id_tree;
const char *sep;
static const int * bpdu_flags[] = {
&hf_bpdu_flags_tcack,
&hf_bpdu_flags_tc,
NULL
};
static const int * rst_flags[] = {
&hf_bpdu_flags_tcack,
&hf_bpdu_flags_agreement,
&hf_bpdu_flags_forwarding,
&hf_bpdu_flags_learning,
&hf_bpdu_flags_port_role,
&hf_bpdu_flags_proposal,
&hf_bpdu_flags_tc,
NULL
};
if (pinfo->dl_dst.type == AT_ETHER) {
const guint8 *dstaddr;
dstaddr = (const guint8 *)pinfo->dl_dst.data;
if(dstaddr[0] == 0x01 && dstaddr[1] == 0x80 &&
dstaddr[2] == 0xC2 && dstaddr[3] == 0x00 &&
dstaddr[4] == 0x00 && ((dstaddr[5] == 0x0D) || ((dstaddr[5] & 0xF0) == 0x20))) {
switch (dstaddr[5]) {
case 0x20:
call_dissector(gmrp_handle, tvb, pinfo, tree);
return;
case 0x21:
case 0x0D:
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
root_identifier_mac_str = tvb_ether_to_str(tvb, BPDU_ROOT_IDENTIFIER + 2);
root_path_cost = tvb_get_ntohl(tvb, BPDU_ROOT_PATH_COST);
port_identifier = tvb_get_ntohs(tvb, BPDU_PORT_IDENTIFIER);
break;
default:
flags = 0;
root_identifier_bridge_priority = 0;
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
"%sT. %sRoot = %d/%d/%s Cost = %d Port = 0x%04x",
protocol_version_identifier == 3 ? "MS":
(protocol_version_identifier == 4 ? "SP":"RS"),
flags & 0x1 ? "TC + " : "",
root_identifier_bridge_priority,
root_identifier_system_id_extension,
root_identifier_mac_str,
root_path_cost, port_identifier);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO,
"%sT. %sRoot = %d/%s Cost = %d Port = 0x%04x",
protocol_version_identifier == 3 ? "MS":
(protocol_version_identifier == 4 ? "SP":"RS"),
flags & 0x1 ? "TC + " : "",
root_identifier_bridge_priority, root_identifier_mac_str,
root_path_cost, port_identifier);
}
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown BPDU type (%u)", bpdu_type);
break;
}
bpdu_item = proto_tree_add_protocol_format(tree, proto_bpdu, tvb, 0, -1,
"Spanning Tree Protocol");
bpdu_tree = proto_item_add_subtree(bpdu_item, ett_bpdu);
protocol_identifier = tvb_get_ntohs(tvb, BPDU_IDENTIFIER);
proto_tree_add_uint(bpdu_tree, hf_bpdu_proto_id, tvb, BPDU_IDENTIFIER, 2,
protocol_identifier);
proto_id_item = proto_tree_add_uint(bpdu_tree, hf_bpdu_version_id, tvb,
BPDU_VERSION_IDENTIFIER, 1,
protocol_version_identifier);
switch (protocol_version_identifier) {
case 0:
break;
case 2:
case 3:
case 4:
break;
default:
expert_add_info(pinfo, proto_id_item, &ei_bpdu_version_support);
break;
}
type_item = proto_tree_add_uint(bpdu_tree, hf_bpdu_type, tvb, BPDU_TYPE, 1, bpdu_type);
if (bpdu_type == BPDU_TYPE_TOPOLOGY_CHANGE) {
set_actual_length(tvb, TC_BPDU_SIZE);
return;
}
if (bpdu_type != BPDU_TYPE_CONF && bpdu_type != BPDU_TYPE_RST) {
expert_add_info(pinfo, type_item, &ei_bpdu_type);
return;
}
bridge_identifier_bridge_priority = tvb_get_ntohs(tvb, BPDU_BRIDGE_IDENTIFIER);
if (bpdu_use_system_id_extensions ) {
bridge_identifier_system_id_extension = bridge_identifier_bridge_priority & 0x0fff;
bridge_identifier_bridge_priority &= 0xf000;
}
bridge_identifier_mac_str = tvb_ether_to_str(tvb, BPDU_BRIDGE_IDENTIFIER + 2);
if (bpdu_type == BPDU_TYPE_RST) {
proto_tree_add_bitmask_value_with_flags(bpdu_tree, tvb, BPDU_FLAGS, hf_bpdu_flags, ett_bpdu_flags, rst_flags, flags, BMT_NO_FALSE|BMT_NO_TFS);
} else {
proto_tree_add_bitmask_value_with_flags(bpdu_tree, tvb, BPDU_FLAGS, hf_bpdu_flags, ett_bpdu_flags, bpdu_flags, flags, BMT_NO_FALSE|BMT_NO_TFS);
}
if (bpdu_use_system_id_extensions) {
root_id_tree = proto_tree_add_subtree_format(bpdu_tree, tvb,
BPDU_ROOT_IDENTIFIER, 8,
ett_root_id, NULL,
"Root Identifier: %d / %d / %s",
root_identifier_bridge_priority,
root_identifier_system_id_extension,
root_identifier_mac_str);
proto_tree_add_uint(root_id_tree, hf_bpdu_root_prio, tvb,
BPDU_ROOT_IDENTIFIER , 1,
root_identifier_bridge_priority);
proto_tree_add_uint(root_id_tree, hf_bpdu_root_sys_id_ext, tvb,
BPDU_ROOT_IDENTIFIER , 2,
root_identifier_system_id_extension);
proto_tree_add_item(root_id_tree, hf_bpdu_root_mac, tvb,
BPDU_ROOT_IDENTIFIER + 2, 6, ENC_NA);
} else {
root_id_tree = proto_tree_add_subtree_format(bpdu_tree, tvb,
BPDU_ROOT_IDENTIFIER, 8,
ett_root_id, NULL,
"Root Identifier: %d / %s",
root_identifier_bridge_priority,
root_identifier_mac_str);
proto_tree_add_uint(root_id_tree, hf_bpdu_root_prio, tvb,
BPDU_ROOT_IDENTIFIER , 2,
root_identifier_bridge_priority);
proto_tree_add_item(root_id_tree, hf_bpdu_root_mac, tvb,
BPDU_ROOT_IDENTIFIER + 2, 6, ENC_NA);
}
proto_tree_add_uint(bpdu_tree, hf_bpdu_root_cost, tvb,
BPDU_ROOT_PATH_COST, 4, root_path_cost);
if (bpdu_use_system_id_extensions) {
bridge_id_tree = proto_tree_add_subtree_format(bpdu_tree, tvb,
BPDU_BRIDGE_IDENTIFIER, 8,
ett_bridge_id, NULL,
"Bridge Identifier: %d / %d / %s",
bridge_identifier_bridge_priority,
bridge_identifier_system_id_extension,
bridge_identifier_mac_str);
proto_tree_add_uint(bridge_id_tree, hf_bpdu_bridge_prio, tvb,
BPDU_BRIDGE_IDENTIFIER , 1,
bridge_identifier_bridge_priority);
proto_tree_add_uint(bridge_id_tree, hf_bpdu_bridge_sys_id_ext, tvb,
BPDU_BRIDGE_IDENTIFIER , 2,
bridge_identifier_system_id_extension);
proto_tree_add_item(bridge_id_tree, hf_bpdu_bridge_mac, tvb,
BPDU_BRIDGE_IDENTIFIER + 2, 6, ENC_NA);
} else {
bridge_id_tree = proto_tree_add_subtree_format(bpdu_tree, tvb,
BPDU_BRIDGE_IDENTIFIER, 8,
ett_bridge_id, NULL,
"Bridge Identifier: %d / %s",
bridge_identifier_bridge_priority,
bridge_identifier_mac_str);
proto_tree_add_uint(bridge_id_tree, hf_bpdu_bridge_prio, tvb,
BPDU_BRIDGE_IDENTIFIER , 2,
bridge_identifier_bridge_priority);
proto_tree_add_item(bridge_id_tree, hf_bpdu_bridge_mac, tvb,
BPDU_BRIDGE_IDENTIFIER + 2, 6, ENC_NA);
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
if (is_bpdu_pvst)
dissect_bpdu_pvst_tlv(pinfo, bpdu_tree, tvb);
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
if (protocol_version_identifier == 3) {
set_actual_length(tvb, BPDU_MSTI + total_msti_length);
}
mstp_tree = proto_tree_add_subtree(bpdu_tree, tvb, BPDU_VERSION_3_LENGTH,
-1, ett_mstp, NULL, "MST Extension");
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
cist_bridge_identifier_mac_str = tvb_ether_to_str(tvb, BPDU_CIST_BRIDGE_IDENTIFIER + 2);
if (bpdu_use_system_id_extensions ) {
cist_bridge_identifier_system_id_extension = cist_bridge_identifier_bridge_priority & 0x0fff;
cist_bridge_identifier_bridge_priority &= 0xf000;
cist_bridge_id_tree = proto_tree_add_subtree_format(mstp_tree, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER, 8,
ett_cist_bridge_id, NULL,
"CIST Bridge Identifier: %d / %d / %s",
cist_bridge_identifier_bridge_priority,
cist_bridge_identifier_system_id_extension,
cist_bridge_identifier_mac_str);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_prio, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER , 1,
cist_bridge_identifier_bridge_priority);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_sys_id_ext, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER , 2,
cist_bridge_identifier_system_id_extension);
proto_tree_add_item(cist_bridge_id_tree, hf_bpdu_cist_bridge_mac, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6, ENC_NA);
} else {
cist_bridge_id_tree = proto_tree_add_subtree_format(mstp_tree, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER, 8,
ett_cist_bridge_id, NULL,
"CIST Bridge Identifier: %d / %s",
cist_bridge_identifier_bridge_priority,
cist_bridge_identifier_mac_str);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_prio, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER , 2,
cist_bridge_identifier_bridge_priority);
proto_tree_add_item(cist_bridge_id_tree, hf_bpdu_cist_bridge_mac, tvb,
BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6, ENC_NA);
}
break;
case MSTI_FORMAT_ALTERNATIVE:
cist_bridge_identifier_bridge_priority = tvb_get_ntohs(tvb,ALT_BPDU_CIST_BRIDGE_IDENTIFIER);
cist_bridge_identifier_mac_str = tvb_ether_to_str(tvb, ALT_BPDU_CIST_BRIDGE_IDENTIFIER + 2);
if (bpdu_use_system_id_extensions ) {
cist_bridge_identifier_system_id_extension = cist_bridge_identifier_bridge_priority & 0x0fff;
cist_bridge_identifier_bridge_priority &= 0xf000;
cist_bridge_id_tree = proto_tree_add_subtree_format(mstp_tree, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER, 8,
ett_cist_bridge_id, NULL,
"CIST Bridge Identifier: %d / %d / %s",
cist_bridge_identifier_bridge_priority,
cist_bridge_identifier_system_id_extension,
cist_bridge_identifier_mac_str);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_prio, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER , 1,
cist_bridge_identifier_bridge_priority);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_sys_id_ext, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER , 2,
cist_bridge_identifier_system_id_extension);
proto_tree_add_item(cist_bridge_id_tree, hf_bpdu_cist_bridge_mac, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6, ENC_NA);
} else {
cist_bridge_id_tree = proto_tree_add_subtree_format(mstp_tree, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER, 8,
ett_cist_bridge_id, NULL,
"CIST Bridge Identifier: %d / %s",
cist_bridge_identifier_bridge_priority,
cist_bridge_identifier_mac_str);
proto_tree_add_uint(cist_bridge_id_tree, hf_bpdu_cist_bridge_prio, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER , 2,
cist_bridge_identifier_bridge_priority);
proto_tree_add_item(cist_bridge_id_tree, hf_bpdu_cist_bridge_mac, tvb,
ALT_BPDU_CIST_BRIDGE_IDENTIFIER + 2, 6, ENC_NA);
}
proto_tree_add_item(mstp_tree, hf_bpdu_cist_internal_root_path_cost, tvb,
ALT_BPDU_CIST_INTERNAL_ROOT_PATH_COST, 4, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(mstp_tree, hf_bpdu_cist_remaining_hops, tvb,
BPDU_CIST_REMAINING_HOPS, 1, ENC_BIG_ENDIAN);
offset = BPDU_MSTI;
msti = 1;
msti_length_remaining = total_msti_length;
while (msti_length_remaining > 0) {
switch(msti_format) {
case MSTI_FORMAT_IEEE_8021S:
msti_regional_root_mstid = tvb_get_guint8(tvb, offset+ MSTI_REGIONAL_ROOT);
msti_regional_root_priority = (msti_regional_root_mstid &0xf0) << 8;
msti_regional_root_mstid = ((msti_regional_root_mstid & 0x0f) << 8) +
tvb_get_guint8(tvb, offset+ MSTI_REGIONAL_ROOT+1);
msti_regional_root_mac_str = tvb_ether_to_str(tvb, offset + MSTI_REGIONAL_ROOT + 2);
msti_tree = proto_tree_add_subtree_format(mstp_tree, tvb, offset, 16, ett_msti, NULL,
"MSTID %d, Regional Root Identifier %d / %s",
msti_regional_root_mstid,
msti_regional_root_priority,
msti_regional_root_mac_str);
proto_tree_add_bitmask_with_flags(msti_tree, tvb, offset+MSTI_FLAGS, hf_bpdu_msti_flags, ett_bpdu_flags, rst_flags, ENC_NA, BMT_NO_FALSE|BMT_NO_TFS);
proto_tree_add_item(msti_tree, hf_bpdu_mst_priority, tvb, offset + MSTI_REGIONAL_ROOT, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msti_tree, hf_bpdu_msti_id_FFF, tvb, offset + MSTI_REGIONAL_ROOT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(msti_tree, hf_bpdu_msti_regional_root_mac, tvb,
offset + MSTI_REGIONAL_ROOT + 2, 6, ENC_NA);
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
msti_length_remaining -= MSTI_MESSAGE_SIZE;
offset += MSTI_MESSAGE_SIZE;
break;
case MSTI_FORMAT_ALTERNATIVE:
msti_regional_root_mstid = tvb_get_guint8(tvb, offset+ ALT_MSTI_REGIONAL_ROOT);
msti_regional_root_priority = (msti_regional_root_mstid &0xf0) << 8;
msti_regional_root_mstid = ((msti_regional_root_mstid & 0x0f) << 8) +
tvb_get_guint8(tvb, offset+ ALT_MSTI_REGIONAL_ROOT+1);
msti_regional_root_mac_str = tvb_ether_to_str(tvb, offset+ ALT_MSTI_REGIONAL_ROOT + 2);
msti_tree = proto_tree_add_subtree_format(mstp_tree, tvb, offset, 16, ett_msti, NULL,
"MSTID %d, Regional Root Identifier %d / %s",
msti_regional_root_mstid,
msti_regional_root_priority,
msti_regional_root_mac_str);
proto_tree_add_item(msti_tree, hf_bpdu_msti_id, tvb, offset+ALT_MSTI_MSTID, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask_with_flags(msti_tree, tvb, offset+ALT_MSTI_FLAGS, hf_bpdu_msti_flags, ett_bpdu_flags, rst_flags, ENC_NA, BMT_NO_FALSE|BMT_NO_TFS);
proto_tree_add_item(msti_tree, hf_bpdu_mst_priority, tvb, offset + ALT_MSTI_REGIONAL_ROOT, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(msti_tree, hf_bpdu_msti_regional_root_id, tvb, offset + ALT_MSTI_REGIONAL_ROOT, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(msti_tree, hf_bpdu_msti_regional_root_mac, tvb,
offset + ALT_MSTI_REGIONAL_ROOT + 2, 6, ENC_NA);
proto_tree_add_item(msti_tree, hf_bpdu_msti_internal_root_path_cost, tvb,
offset+ALT_MSTI_INTERNAL_ROOT_PATH_COST, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(msti_tree, hf_bpdu_msti_bridge_id, tvb, offset + ALT_MSTI_BRIDGE_IDENTIFIER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(msti_tree, hf_bpdu_msti_bridge_id_priority, tvb, offset + ALT_MSTI_BRIDGE_IDENTIFIER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(msti_tree, hf_bpdu_msti_bridge_id_mac, tvb,
offset + ALT_MSTI_BRIDGE_IDENTIFIER + 2, 6, ENC_NA);
proto_tree_add_item(msti_tree, hf_bpdu_msti_port_id, tvb, offset+ALT_MSTI_PORT_IDENTIFIER, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(msti_tree, hf_bpdu_msti_remaining_hops, tvb,
offset + ALT_MSTI_REMAINING_HOPS, 1, ENC_BIG_ENDIAN);
msti_length_remaining -= ALT_MSTI_MESSAGE_SIZE;
offset += ALT_MSTI_MESSAGE_SIZE;
break;
}
msti++;
}
if (protocol_version_identifier >= 4 && version_1_length == 0
&& tvb_reported_length(tvb) >= 106) {
bpdu_version_4_length = BPDU_MSTI + total_msti_length;
version_4_length = tvb_get_ntohs(tvb, bpdu_version_4_length);
proto_tree_add_uint(bpdu_tree, hf_bpdu_version_4_length, tvb,
bpdu_version_4_length, 2, version_4_length);
if (version_4_length >= 53) {
spt_tree = proto_tree_add_subtree(bpdu_tree, tvb, bpdu_version_4_length, -1,
ett_spt, NULL, "SPT Extension");
spt_offset = (bpdu_version_4_length + 2);
aux_mcid_tree = proto_tree_add_subtree(spt_tree, tvb, spt_offset,
MCID_LEN, ett_aux_mcid, NULL, "MCID Data");
proto_tree_add_item(aux_mcid_tree,
hf_bpdu_spt_config_format_selector, tvb, spt_offset, 1,
ENC_BIG_ENDIAN);
proto_tree_add_item(aux_mcid_tree, hf_bpdu_spt_config_name, tvb,
spt_offset + 1, 32, ENC_ASCII | ENC_NA);
proto_tree_add_item(aux_mcid_tree,
hf_bpdu_spt_config_revision_level, tvb, spt_offset + 33,
2, ENC_BIG_ENDIAN);
proto_tree_add_item(aux_mcid_tree, hf_bpdu_spt_config_digest,
tvb, spt_offset + 35, 16, ENC_NA);
spt_offset += MCID_LEN;
agreement_tree = proto_tree_add_subtree(spt_tree, tvb, spt_offset,
-1, ett_agreement, &agreement_item, "Agreement Data");
spt_agree_data = tvb_get_guint8(tvb, spt_offset);
sep = initial_sep;
if (agreement_item) {
agree_num = (spt_agree_data & 0x03);
proto_item_append_text(agreement_item, "%sAN: %d", sep, agree_num );
}
proto_tree_add_uint(agreement_tree, hf_bpdu_flags_agree_num,
tvb, spt_offset, 1, spt_agree_data);
sep = cont_sep;
if (agreement_item) {
dagree_num = ((spt_agree_data & 0x0C) >> 2);
proto_item_append_text(agreement_item, "%sDAN: %d", sep, dagree_num);
}
proto_tree_add_uint(agreement_tree, hf_bpdu_flags_dagree_num,
tvb, spt_offset, 1, spt_agree_data);
proto_tree_add_boolean(agreement_tree, hf_bpdu_flags_agree_valid,
tvb, spt_offset, 1, spt_agree_data);
proto_tree_add_boolean(agreement_tree, hf_bpdu_flags_restricted_role,
tvb, spt_offset, 1, spt_agree_data);
if (sep != initial_sep) {
proto_item_append_text(agreement_item, ")");
}
spt_offset += 2;
proto_tree_add_item(agreement_tree, hf_bpdu_agreement_digest_format_id, tvb, spt_offset, 1, ENC_NA);
proto_tree_add_item(agreement_tree, hf_bpdu_agreement_digest_format_capabilities, tvb, spt_offset, 1, ENC_NA);
spt_offset += 1;
proto_tree_add_item(agreement_tree, hf_bpdu_agreement_digest_convention_id, tvb, spt_offset, 1, ENC_NA);
proto_tree_add_item(agreement_tree, hf_bpdu_agreement_digest_convention_capabilities, tvb, spt_offset, 1, ENC_NA);
spt_offset += 1;
proto_tree_add_item(agreement_tree, hf_bpdu_agreement_digest_edge_count, tvb, spt_offset, 2, ENC_BIG_ENDIAN);
spt_offset += 10;
proto_tree_add_item(agreement_tree, hf_bpdu_spt_agreement_digest,
tvb, spt_offset, 20, ENC_NA);
if (protocol_version_identifier == 4) {
set_actual_length(tvb, (bpdu_version_4_length + version_4_length + 2));
}
}
}
} else {
if (is_bpdu_pvst)
dissect_bpdu_pvst_tlv(pinfo, bpdu_tree, tvb);
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
{ &hf_bpdu_pvst_tlvtype,
{ "Type", "stp.pvst.tlvtype",
FT_UINT16, BASE_HEX, VALS(bpdu_pvst_tlv_vals), 0x0,
NULL, HFILL }},
{ &hf_bpdu_pvst_tlvlength,
{ "Length", "stp.pvst.tlvlen",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_pvst_tlv_origvlan,
{ "Originating VLAN", "stp.pvst.origvlan",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_pvst_tlvvalue,
{ "Value", "stp.pvst.tlvval",
FT_BYTES, BASE_NONE, NULL, 0x0,
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
{ &hf_bpdu_mst_priority,
{ "Priority", "mstp.msti.priority",
FT_UINT8, BASE_HEX, NULL, 0xF0,
NULL, HFILL }},
{ &hf_bpdu_msti_id_FFF,
{ "MSTID", "mstp.msti.msti_id",
FT_UINT16, BASE_DEC, NULL, 0x0FFF,
NULL, HFILL }},
{ &hf_bpdu_msti_id,
{ "MSTID", "mstp.msti.msti_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_regional_root_id,
{ "MSTI Regional Root Identifier", "mstp.msti.regional_root_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_regional_root_mac,
{ "Regional Root", "mstp.msti.root.hw",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_internal_root_path_cost,
{ "Internal root path cost", "mstp.msti.root_cost",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_msti_bridge_id,
{ "MSTI Bridge Identifier", "mstp.msti.bridge_id",
FT_UINT16, BASE_DEC, NULL, 0x0FFF,
NULL, HFILL }},
{ &hf_bpdu_msti_bridge_id_priority,
{ "MSTI Bridge Priority", "mstp.msti.bridge_id_priority",
FT_UINT16, BASE_DEC, NULL, 0xF000,
NULL, HFILL }},
{ &hf_bpdu_msti_bridge_id_mac,
{ "MSTI Bridge MAC", "mstp.msti.bridge_id_mac",
FT_ETHER, BASE_NONE, NULL, 0x0,
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
{ &hf_bpdu_version_4_length,
{ "Version 4 Length", "mstp.version_4_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_spt_config_format_selector,
{ "SPT Config ID format selector", "mstp.config_format_selector",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_bpdu_spt_config_name,
{"SPT Config name", "mstp.config_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_bpdu_spt_config_revision_level,
{ "SPT Config revision", "mstp.config_revision_level",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_bpdu_spt_config_digest,
{ "SPT Config digest", "mstp.config_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_bpdu_flags_agree_num,
{ "Agreement Number", "mstp.agree_flags.agreement_num",
FT_UINT8, BASE_DEC, NULL, 0x03,
NULL, HFILL } },
{ &hf_bpdu_flags_dagree_num,
{ "Disagreement Number", "mstp.agree_flags.dagreement_num",
FT_UINT8, BASE_DEC, NULL, 0x0C,
NULL, HFILL } },
{ &hf_bpdu_flags_agree_valid,
{ "Agreement Valid Flag", "mstp.agree_flags.agreement_valid",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x10,
NULL, HFILL } },
{ &hf_bpdu_flags_restricted_role,
{ "Restricted Role", "mstp.agree_flags.rest_role",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x20,
NULL, HFILL } },
{ &hf_bpdu_spt_agreement_digest,
{ "Agreement Digest", "mstp.agreement_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL } },
{ &hf_bpdu_agreement_digest_format_id,
{ "Agreement Digest Format Id", "bpdu.agreement_digest_format_id",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{ &hf_bpdu_agreement_digest_format_capabilities,
{ "Agreement Digest Format Capabilities", "bpdu.agreement_digest_format_capabilities",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{ &hf_bpdu_agreement_digest_convention_id,
{ "Agreement Digest Convention Id", "bpdu.agreement_digest_convention_id",
FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{ &hf_bpdu_agreement_digest_convention_capabilities,
{ "Agreement Digest Convention Capabilities", "bpdu.agreement_digest_convention_capabilities",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{ &hf_bpdu_agreement_digest_edge_count,
{ "Agreement Digest Edge Count", "bpdu.agreement_digest_edge_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_bpdu,
&ett_bpdu_flags,
&ett_root_id,
&ett_bridge_id,
&ett_mstp,
&ett_msti,
&ett_cist_bridge_id,
&ett_spt,
&ett_aux_mcid,
&ett_agreement,
&ett_bpdu_pvst_tlv
};
static ei_register_info ei[] = {
{ &ei_pvst_tlv_length_invalid,
{ "stp.pvst.tlvlen.invalid", PI_MALFORMED, PI_ERROR,
"Indicated length is not valid for this record type", EXPFILL }},
{ &ei_pvst_tlv_origvlan_missing,
{ "stp.pvst.origvlan.missing", PI_MALFORMED, PI_ERROR,
"Originating (PVID) VLAN TLV is missing or corrupt", EXPFILL }},
{ &ei_pvst_tlv_truncated,
{ "stp.pvst.tlv.truncated", PI_MALFORMED, PI_ERROR,
"TLV record is truncated prematurely", EXPFILL }},
{ &ei_pvst_tlv_unknown,
{ "stp.pvst.tlv.unknown", PI_UNDECODED, PI_COMMENT,
"TLV type is unknown", EXPFILL }},
{ &ei_bpdu_version_support,
{ "bpdu.version_support", PI_PROTOCOL, PI_WARN,
"This version of Wireshark only knows about versions 0, 2, 3 & 4", EXPFILL }},
{ &ei_bpdu_type,
{ "stp.type.unknown", PI_PROTOCOL, PI_WARN,
"Unknown BPDU type data", EXPFILL }},
};
module_t *bpdu_module;
expert_module_t *expert_bpdu;
proto_bpdu = proto_register_protocol("Spanning Tree Protocol", "STP", "stp");
proto_register_field_array(proto_bpdu, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("bpdu", dissect_bpdu_generic, proto_bpdu);
register_dissector("bpdu_cisco", dissect_bpdu_cisco, proto_bpdu);
expert_bpdu = expert_register_protocol(proto_bpdu);
expert_register_field_array(expert_bpdu, ei, array_length(ei));
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
bpdu_handle = find_dissector("bpdu");
dissector_add_uint("llc.dsap", SAP_BPDU, bpdu_handle);
dissector_add_uint("chdlc.protocol", CHDLCTYPE_BPDU, bpdu_handle);
dissector_add_uint("ethertype", ETHERTYPE_STP, bpdu_handle);
dissector_add_uint("llc.cisco_pid", 0x010c, bpdu_handle);
bpdu_handle = find_dissector("bpdu_cisco");
dissector_add_uint("llc.cisco_pid", 0x010b, bpdu_handle);
}
