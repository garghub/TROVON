static int
dissect_oampdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
guint8 oampdu_code;
proto_tree *oampdu_tree;
proto_item *oampdu_item;
static const int * oampdu_flags[] = {
&hf_oampdu_flags_link_fault,
&hf_oampdu_flags_dying_gasp,
&hf_oampdu_flags_critical_event,
&hf_oampdu_flags_local_evaluating,
&hf_oampdu_flags_local_stable,
&hf_oampdu_flags_remote_evaluating,
&hf_oampdu_flags_remote_stable,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OAM");
col_clear(pinfo->cinfo, COL_INFO);
oampdu_item = proto_tree_add_protocol_format(tree, proto_oampdu,
tvb, 0, -1, "OAM Protocol");
oampdu_tree = proto_item_add_subtree(oampdu_item, ett_oampdu);
proto_tree_add_bitmask_with_flags(oampdu_tree, tvb, offset, hf_oampdu_flags, ett_oampdu_flags, oampdu_flags, ENC_BIG_ENDIAN, BMT_NO_FALSE|BMT_NO_TFS);
offset += 2;
oampdu_code = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(oampdu_tree, hf_oampdu_code, tvb,
offset, 1, oampdu_code);
col_add_fstr(pinfo->cinfo, COL_INFO, "OAMPDU: %s", val_to_str_const(oampdu_code, code_vals, "Unknown"));
switch (oampdu_code)
{
case OAMPDU_INFORMATION:
dissect_oampdu_information(tvb, oampdu_tree);
break;
case OAMPDU_EVENT_NOTIFICATION:
dissect_oampdu_event_notification(tvb, pinfo, oampdu_tree);
break;
case OAMPDU_VAR_REQUEST:
dissect_oampdu_variable_request(tvb, oampdu_tree);
break;
case OAMPDU_VAR_RESPONSE:
dissect_oampdu_variable_response(tvb, oampdu_tree);
break;
case OAMPDU_LOOPBACK_CTRL:
dissect_oampdu_loopback_control(tvb, oampdu_tree);
break;
case OAMPDU_VENDOR_SPECIFIC:
dissect_oampdu_vendor_specific(tvb, oampdu_tree);
default:
break;
}
return tvb_captured_length(tvb);
}
static void
dissect_oampdu_information(tvbuff_t *tvb, proto_tree *tree)
{
guint8 raw_octet;
guint8 info_type;
guint32 offset;
guint16 bytes;
const guint8 *ptr;
proto_tree *info_tree;
proto_item *info_item;
proto_item *oui_item;
offset = OAMPDU_HEADER_SIZE;
while (1)
{
bytes = tvb_captured_length_remaining(tvb, offset);
if (bytes < 1) break;
info_type = tvb_get_guint8(tvb, offset);
if (info_type == OAMPDU_INFO_TYPE_ENDMARKER) break;
info_item = proto_tree_add_uint(tree, hf_oampdu_info_type, tvb,
offset, 1, info_type);
switch (info_type)
{
case OAMPDU_INFO_TYPE_LOCAL:
info_tree = proto_item_add_subtree(info_item, ett_oampdu_local_info);
break;
case OAMPDU_INFO_TYPE_REMOTE:
info_tree = proto_item_add_subtree(info_item, ett_oampdu_remote_info);
break;
case OAMPDU_INFO_TYPE_ORG:
info_tree = proto_item_add_subtree(info_item, ett_oampdu_org_info);
break;
default:
info_tree = NULL;
break;
}
offset += OAMPDU_INFO_TYPE_SZ;
if ((info_type==OAMPDU_INFO_TYPE_LOCAL)||(info_type==OAMPDU_INFO_TYPE_REMOTE))
{
static const int * info_states[] = {
&hf_oampdu_info_state_parser,
&hf_oampdu_info_state_mux,
NULL
};
static const int * info_config[] = {
&hf_oampdu_info_oamConfig_mode,
&hf_oampdu_info_oamConfig_uni,
&hf_oampdu_info_oamConfig_lpbk,
&hf_oampdu_info_oamConfig_event,
&hf_oampdu_info_oamConfig_var,
NULL
};
proto_tree_add_item(info_tree, hf_oampdu_info_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += OAMPDU_INFO_LENGTH_SZ;
proto_tree_add_item(info_tree, hf_oampdu_info_version,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += OAMPDU_INFO_VERSION_SZ;
proto_tree_add_item(info_tree, hf_oampdu_info_revision,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_INFO_REVISION_SZ;
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet == OAMPDU_INFO_TYPE_LOCAL)
proto_tree_add_bitmask(info_tree, tvb, offset, hf_oampdu_info_state, ett_oampdu_local_info_state, info_states, ENC_NA);
else
proto_tree_add_bitmask(info_tree, tvb, offset, hf_oampdu_info_state, ett_oampdu_remote_info_state, info_states, ENC_NA);
offset += OAMPDU_INFO_STATE_SZ;
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet == OAMPDU_INFO_TYPE_LOCAL)
proto_tree_add_bitmask(info_tree, tvb, offset, hf_oampdu_info_oamConfig, ett_oampdu_local_info_config, info_config, ENC_NA);
else
proto_tree_add_bitmask(info_tree, tvb, offset, hf_oampdu_info_oamConfig, ett_oampdu_remote_info_config, info_config, ENC_NA);
offset += OAMPDU_INFO_OAM_CONFIG_SZ;
proto_tree_add_item(info_tree, hf_oampdu_info_oampduConfig,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_INFO_OAMPDU_CONFIG_SZ;
oui_item = proto_tree_add_item(info_tree, hf_oampdu_info_oui,
tvb, offset, 3, ENC_NA);
APPEND_OUI_NAME(oui_item, ptr, tvb, offset);
offset += OAMPDU_INFO_OUI_SZ;
proto_tree_add_item(info_tree, hf_oampdu_info_vendor,
tvb, offset, 4, ENC_NA);
offset += OAMPDU_INFO_VENDOR_SPECIFIC_SZ;
}
else if (info_type == OAMPDU_INFO_TYPE_ORG)
{
raw_octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(info_tree, hf_oampdu_info_len,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += OAMPDU_INFO_LENGTH_SZ;
oui_item = proto_tree_add_item(info_tree, hf_oampdu_info_oui,
tvb, offset, 3, ENC_NA);
APPEND_OUI_NAME(oui_item, ptr, tvb, offset);
offset += OAMPDU_INFO_OUI_SZ;
proto_tree_add_item(info_tree, hf_oampdu_info_vendor,
tvb, offset, raw_octet-5, ENC_NA);
offset += raw_octet-5;
}
else
{
raw_octet = tvb_get_guint8(tvb, offset);
offset += raw_octet;
}
}
}
static void
dissect_oampdu_event_notification(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 raw_octet;
guint8 event_type;
guint32 offset;
guint16 bytes;
proto_tree *event_tree;
proto_item *event_item;
offset = OAMPDU_HEADER_SIZE;
proto_tree_add_item(tree, hf_oampdu_event_sequence,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_SEQUENCE_SZ;
while (1)
{
bytes = tvb_captured_length_remaining(tvb, offset);
if (bytes < 1) break;
event_type = tvb_get_guint8(tvb, offset);
if (event_type == OAMPDU_EVENT_TYPE_END) break;
event_item = proto_tree_add_uint(tree, hf_oampdu_event_type,
tvb, offset, 1, event_type);
offset += OAMPDU_EVENT_TYPE_SZ;
switch (event_type)
{
case OAMPDU_EVENT_TYPE_ESPE:
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_espe);
proto_tree_add_item(event_tree, hf_oampdu_event_length,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_LENGTH_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_timeStamp,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_TIMESTAMP_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_espeWindow,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += OAMPDU_ESPE_WINDOW_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_espeThreshold,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += OAMPDU_ESPE_THRESHOLD_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_espeErrors,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += OAMPDU_ESPE_ERRORS_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_espeTotalErrors,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += OAMPDU_ESPE_ERR_TOTAL_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_espeTotalEvents,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_ESPE_TOTAL_SZ;
break;
case OAMPDU_EVENT_TYPE_EFE:
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_efe);
proto_tree_add_item(event_tree, hf_oampdu_event_length,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_LENGTH_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_timeStamp,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_TIMESTAMP_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efeWindow,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EFE_WINDOW_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efeThreshold,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFE_THRESHOLD_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efeErrors,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFE_ERRORS_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efeTotalErrors,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += OAMPDU_EFE_ERR_TOTAL_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efeTotalEvents,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFE_TOTAL_SZ;
break;
case OAMPDU_EVENT_TYPE_EFPE:
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_efpe);
proto_tree_add_item(event_tree, hf_oampdu_event_length,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_LENGTH_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_timeStamp,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_TIMESTAMP_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efpeWindow,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFPE_WINDOW_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efpeThreshold,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFPE_THRESHOLD_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efpeErrors,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFPE_ERRORS_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efpeTotalErrors,
tvb, offset, 8, ENC_BIG_ENDIAN);
offset += OAMPDU_EFPE_ERR_TOTAL_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efpeTotalEvents,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFPE_TOTAL_SZ;
break;
case OAMPDU_EVENT_TYPE_EFSSE:
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_efsse);
proto_tree_add_item(event_tree, hf_oampdu_event_length,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_LENGTH_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_timeStamp,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EVENT_TIMESTAMP_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efsseWindow,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EFSSE_WINDOW_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efsseThreshold,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EFSSE_THRESHOLD_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efsseErrors,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += OAMPDU_EFSSE_ERRORS_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efsseTotalErrors,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFSSE_ERR_TOTAL_SZ;
proto_tree_add_item(event_tree, hf_oampdu_event_efsseTotalEvents,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += OAMPDU_EFSSE_TOTAL_SZ;
break;
case OAMPDU_EVENT_TYPE_OSE:
{
event_tree = proto_item_add_subtree(event_item,
ett_oampdu_event_ose);
raw_octet = tvb_get_guint8(tvb, offset);
event_item = proto_tree_add_uint(event_tree, hf_oampdu_event_length,
tvb, offset, 1, raw_octet);
offset += OAMPDU_EVENT_LENGTH_SZ;
if (raw_octet < 2)
{
expert_add_info_format(pinfo, event_item, &ei_oampdu_event_length_bad, "Event length should be at least 2");
}
else
{
offset += (raw_octet-2);
}
break;
}
default:
break;
}
}
}
static void
dissect_oampdu_variable_request(tvbuff_t *tvb, proto_tree *tree)
{
guint8 raw_octet;
guint32 offset;
offset = OAMPDU_HEADER_SIZE;
while (1)
{
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet == 0) break;
proto_tree_add_uint(tree, hf_oampdu_variable_branch,
tvb,offset, 1, raw_octet);
offset+=1;
switch (raw_octet)
{
case OAMPDU_VARS_OBJECT:
proto_tree_add_item(tree, hf_oampdu_variable_object,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OAMPDU_VARS_PACKAGE:
proto_tree_add_item(tree, hf_oampdu_variable_package,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OAMPDU_VARS_BINDING:
proto_tree_add_item(tree, hf_oampdu_variable_binding,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OAMPDU_VARS_ATTRIBUTE:
proto_tree_add_item(tree, hf_oampdu_variable_attribute,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset+=2;
}
}
static void
dissect_oampdu_variable_response(tvbuff_t *tvb, proto_tree *tree)
{
guint8 branch, raw_octet;
guint32 offset;
offset = OAMPDU_HEADER_SIZE;
while (1)
{
branch = tvb_get_guint8(tvb, offset);
if (branch == 0) break;
proto_tree_add_uint(tree, hf_oampdu_variable_branch,
tvb,offset, 1, branch);
offset+=1;
switch (branch)
{
case OAMPDU_VARS_OBJECT:
proto_tree_add_item(tree, hf_oampdu_variable_object,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OAMPDU_VARS_PACKAGE:
proto_tree_add_item(tree, hf_oampdu_variable_package,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OAMPDU_VARS_BINDING:
proto_tree_add_item(tree, hf_oampdu_variable_binding,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case OAMPDU_VARS_ATTRIBUTE:
proto_tree_add_item(tree, hf_oampdu_variable_attribute,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset+=2;
do {
raw_octet = tvb_get_guint8(tvb, offset);
if (raw_octet >= 0x80) {
proto_tree_add_uint(tree, hf_oampdu_variable_indication,
tvb,offset, 1, (raw_octet&0x7F));
offset+=1;
break;
}
else {
if (raw_octet == 0) raw_octet = 128;
proto_tree_add_uint(tree, hf_oampdu_variable_width,
tvb,offset, 1, raw_octet);
offset+=1;
proto_tree_add_item(tree, hf_oampdu_variable_value,
tvb, offset, raw_octet, ENC_NA);
offset+=raw_octet;
}
} while (branch==OAMPDU_VARS_OBJECT || branch==OAMPDU_VARS_PACKAGE);
}
}
static void
dissect_oampdu_loopback_control(tvbuff_t *tvb, proto_tree *tree)
{
guint32 offset;
guint16 bytes;
static const int * ctrl[] = {
&hf_oampdu_lpbk_enable,
&hf_oampdu_lpbk_disable,
NULL
};
offset = OAMPDU_HEADER_SIZE;
bytes = tvb_captured_length_remaining(tvb, offset);
if (bytes >= 1)
{
proto_tree_add_bitmask(tree, tvb, offset, hf_oampdu_lpbk, ett_oampdu_lpbk_ctrl, ctrl, ENC_NA);
}
}
static void
dissect_oampdu_vendor_specific(tvbuff_t *tvb, proto_tree *tree)
{
guint32 offset;
guint16 bytes;
guint32 leaf_branch;
guint8 dpoe_opcode;
guint8 variable_length;
guint8 next_byte;
guint8 pir_subtype;
guint8 rr_byte;
const guint8 *ptr;
const guint8 oui_cl[] = {OUI_CL_0, OUI_CL_1, OUI_CL_2};
proto_item *oui_item;
proto_tree *oampdu_vendor_specific_tree;
proto_tree *dpoe_opcode_tree;
proto_item *dpoe_opcode_item;
proto_item *dpoe_opcode_response;
proto_tree *dpoe_opcode_response_tree;
offset = OAMPDU_HEADER_SIZE;
bytes = tvb_captured_length_remaining(tvb, offset);
if (bytes >= 3) {
oui_item = proto_tree_add_item(tree, hf_oampdu_info_oui, tvb, offset, 3, ENC_NA);
APPEND_OUI_NAME(oui_item, ptr, tvb, offset);
if (tvb_memeql(tvb, offset, oui_cl, OUI_SIZE) == 0) {
offset += 3;
oampdu_vendor_specific_tree = proto_item_add_subtree(oui_item, ett_oampdu_vendor_specific);
dpoe_opcode_item = proto_tree_add_item(oampdu_vendor_specific_tree, hf_oampdu_vendor_specific_dpoe_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
dpoe_opcode_tree = proto_item_add_subtree(dpoe_opcode_item, ett_dpoe_opcode);
dpoe_opcode = tvb_get_guint8(tvb, offset);
offset +=1;
next_byte = tvb_get_guint8(tvb, offset);
switch (dpoe_opcode) {
case 0x00:
break;
case DPOE_OPCODE_GET_REQUEST:
leaf_branch = tvb_get_ntoh24(tvb, offset);
if (leaf_branch == DPOE_LB_ONU_OBJ) {
proto_tree_add_item(dpoe_opcode_tree, hf_dpoe_variable_descriptor, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
variable_length = tvb_get_guint8(tvb, offset);
offset += 1;
offset += variable_length;
}
next_byte = tvb_get_guint8(tvb, offset);
while (next_byte != 0x00) {
proto_tree_add_item(dpoe_opcode_tree, hf_dpoe_variable_descriptor, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
next_byte = tvb_get_guint8(tvb, offset);
}
break;
case DPOE_OPCODE_GET_RESPONSE:
case DPOE_OPCODE_SET_REQUEST:
case DPOE_OPCODE_SET_RESPONSE:
while (next_byte != 0x00) {
dpoe_opcode_response = proto_tree_add_item(dpoe_opcode_tree, hf_dpoe_variable_descriptor, tvb, offset, 3, ENC_BIG_ENDIAN);
leaf_branch = tvb_get_ntoh24(tvb, offset);
offset += 3;
variable_length = tvb_get_guint8(tvb, offset);
dpoe_opcode_response_tree = proto_item_add_subtree(dpoe_opcode_response, ett_dpoe_opcode_response);
if (variable_length >= 0x80) {
proto_tree_add_item(dpoe_opcode_response_tree, hf_dpoe_variable_response_code, tvb, offset, 1, ENC_BIG_ENDIAN);
variable_length = 0;
offset += 1;
} else if (variable_length == 0) {
offset += 1;
variable_length = 128;
proto_tree_add_item(dpoe_opcode_response_tree, hf_oampdu_variable_value, tvb, offset, variable_length, ENC_NA);
} else {
offset += 1;
if (leaf_branch == (DPOE_LB_ONU_ID)) {
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_response_eth, tvb, offset, variable_length, ENC_NA);
} else if (leaf_branch == DPOE_LB_MAX_LL) {
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_mll_b, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_mll_do, tvb, offset+2, 2, ENC_BIG_ENDIAN);
} else if (leaf_branch == DPOE_LB_MAX_NET_PORTS) {
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_response_int, tvb, offset, variable_length, ENC_BIG_ENDIAN);
} else if (leaf_branch == DPOE_LB_NUM_S1_INT) {
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_response_int, tvb, offset, variable_length, ENC_BIG_ENDIAN);
} else if (leaf_branch == DPOE_LB_OAM_FR) {
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_frame_rate_minimum, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_frame_rate_maximum, tvb, offset+1, 1, ENC_BIG_ENDIAN);
} else if (leaf_branch == DPOE_LB_REP_THRESH) {
guint8 nqs;
guint8 rvpqs;
guint8 nqs_i;
guint8 rvpqs_i;
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_repthr_nqs, tvb, offset, 1, ENC_BIG_ENDIAN);
nqs = tvb_get_guint8(tvb, offset);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_repthr_rvpqs, tvb, offset+1, 1, ENC_BIG_ENDIAN);
rvpqs = tvb_get_guint8(tvb, offset+1);
for (nqs_i = 0; nqs_i < nqs; nqs_i++) {
for (rvpqs_i = 0; rvpqs_i < rvpqs; rvpqs_i++) {
dpoe_opcode_response = proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_report_threshold, tvb, offset+2+(2*(nqs_i+rvpqs_i)), 2, ENC_BIG_ENDIAN);
proto_item_append_text(dpoe_opcode_response, " (Report Threshold %i for Queue Set %i)", nqs_i, rvpqs_i);
}
}
} else if (leaf_branch == DPOE_LB_S1_INT_PORT_AUTONEG) {
proto_tree_add_bitmask(dpoe_opcode_response_tree, tvb, offset, hf_oam_dpoe_s1_autoneg, ett_oam_dpoe_s1_autoneg, s1_autoneg_mode_bits, ENC_BIG_ENDIAN);
} else if (leaf_branch == DPOE_LB_USER_PORT_OBJ) {
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object, tvb, offset, 1, ENC_BIG_ENDIAN);
} else if (leaf_branch == DPOE_LB_PORT_INGRESS_RULE) {
guint8 pir_mvl;
pir_subtype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
switch (pir_subtype) {
case 0:
break;
case 1:
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_header_precedence, tvb, offset+1, 1, ENC_BIG_ENDIAN);
break;
case 2:
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_clause_fc, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_clause_fi, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_clause_msbm, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_clause_lsbm, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_clause_operator, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_clause_mvl, tvb, offset+6, 1, ENC_BIG_ENDIAN);
pir_mvl = tvb_get_guint8(tvb, offset+6);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_clause_mv, tvb, offset+7, pir_mvl, ENC_BIG_ENDIAN);
break;
case 3:
dpoe_opcode_response = proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr, tvb, offset+1, 1, ENC_BIG_ENDIAN);
rr_byte = tvb_get_guint8(tvb, offset+1);
switch (rr_byte) {
case 0x00:
proto_item_append_text(dpoe_opcode_response, " No operation");
break;
case 0x01:
proto_item_append_text(dpoe_opcode_response, " Set Discard Flag for Frame");
break;
case 0x02:
proto_item_append_text(dpoe_opcode_response, " Clear Discard Flag for Frame (Forward Frame)");
break;
case 0x03:
proto_item_append_text(dpoe_opcode_response, " Set destination queue for frame");
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_queue, tvb, offset+2, 3, ENC_BIG_ENDIAN);
break;
case 0x04:
proto_item_append_text(dpoe_opcode_response, " Set output field");
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_set_fc, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_set_fi, tvb, offset+3, 1, ENC_BIG_ENDIAN);
break;
case 0x05:
proto_item_append_text(dpoe_opcode_response, " Copy output field");
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_copy, tvb, offset+2, 2, ENC_BIG_ENDIAN);
break;
case 0x06:
proto_item_append_text(dpoe_opcode_response, " Delete field");
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_delete, tvb, offset+2, 2, ENC_BIG_ENDIAN);
break;
case 0x07:
proto_item_append_text(dpoe_opcode_response, " Insert field");
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_insert, tvb, offset+2, 2, ENC_BIG_ENDIAN);
break;
case 0x08:
proto_item_append_text(dpoe_opcode_response, " Delete field and Insert current output field");
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_replace, tvb, offset+2, 2, ENC_BIG_ENDIAN);
break;
case 0x09:
proto_item_append_text(dpoe_opcode_response, " Do not delete field (override other Delete result)");
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_cd, tvb, offset+2, 2, ENC_BIG_ENDIAN);
break;
case 0x0A:
proto_item_append_text(dpoe_opcode_response, " Do not insert field (override other Insert result)");
proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_user_port_object_result_rr_ci, tvb, offset+2, 2, ENC_BIG_ENDIAN);
break;
default:
break;
}
break;
default:
break;
}
} else if (leaf_branch == DPOE_LB_QUEUE_CONFIG) {
guint8 qc_n;
guint8 qc_m;
guint8 qc_p;
guint8 qc_j;
guint8 qc_n_i;
guint8 qc_m_i;
guint8 qc_p_i;
guint8 qc_j_i;
proto_tree *dpoe_oam_qc_upstream;
proto_tree *dpoe_oam_qc_upstream_subtree;
proto_tree *dpoe_oam_qc_downstream;
proto_tree *dpoe_oam_qc_downstream_subtree;
proto_tree *dpoe_oam_qc_nq;
proto_tree *dpoe_oam_qc_nq_subtree;
qc_n = tvb_get_guint8(tvb, offset);
dpoe_oam_qc_upstream = proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_qc_ll_u, tvb, offset, 1, ENC_BIG_ENDIAN);
dpoe_oam_qc_upstream_subtree = proto_item_add_subtree(dpoe_oam_qc_upstream, ett_oam_dpoe_qc_u);
for (qc_n_i = 0; qc_n_i < qc_n; qc_n_i++) {
offset++;
qc_m = tvb_get_guint8(tvb, offset);
dpoe_oam_qc_nq = proto_tree_add_item(dpoe_oam_qc_upstream_subtree, hf_oam_dpoe_qc_nq, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(dpoe_oam_qc_nq, " (Upstream link %i)", qc_n_i);
dpoe_oam_qc_nq_subtree = proto_item_add_subtree(dpoe_oam_qc_nq, ett_oam_dpoe_qc_nq);
for (qc_m_i = 0; qc_m_i < qc_m; qc_m_i++) {
offset++;
dpoe_opcode_response = proto_tree_add_item(dpoe_oam_qc_nq_subtree, hf_oam_dpoe_qc_queue_size, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(dpoe_opcode_response, " (Upstream link %i queue %i size)", qc_n_i, qc_m_i);
}
}
offset++;
qc_p = tvb_get_guint8(tvb, offset);
dpoe_oam_qc_downstream = proto_tree_add_item(dpoe_opcode_response_tree, hf_oam_dpoe_qc_ports_d, tvb, offset, 1, ENC_BIG_ENDIAN);
dpoe_oam_qc_downstream_subtree = proto_item_add_subtree(dpoe_oam_qc_downstream, ett_oam_dpoe_qc_d);
for (qc_p_i = 0; qc_p_i < qc_p; qc_p_i++) {
offset++;
qc_j = tvb_get_guint8(tvb, offset);
dpoe_oam_qc_nq = proto_tree_add_item(dpoe_oam_qc_downstream_subtree, hf_oam_dpoe_qc_nq, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(dpoe_oam_qc_nq, " (Downstream port %i)", qc_p_i);
dpoe_oam_qc_nq_subtree = proto_item_add_subtree(dpoe_oam_qc_nq, ett_oam_dpoe_qc_nq);
for (qc_j_i = 0; qc_j_i < qc_j; qc_j_i++) {
offset++;
dpoe_opcode_response = proto_tree_add_item(dpoe_oam_qc_nq_subtree, hf_oam_dpoe_qc_queue_size, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(dpoe_opcode_response, " (Downstream port %i queue %i size)", qc_p_i, qc_j_i);
}
}
} else {
proto_tree_add_item(dpoe_opcode_response_tree, hf_oampdu_variable_value, tvb, offset, variable_length, ENC_NA);
}
}
offset += variable_length;
next_byte = tvb_get_guint8(tvb, offset);
}
break;
case 0x05:
break;
case 0x06:
break;
case 0x07:
break;
case 0x08:
break;
case 0x09:
break;
default:
break;
}
}
}
}
void
proto_register_oampdu(void)
{
static hf_register_info hf[] = {
{ &hf_oampdu_flags,
{ "Flags", "oampdu.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
"The Flags Field", HFILL }},
{ &hf_oampdu_flags_link_fault,
{ "Link Fault", "oampdu.flags.linkFault",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_LINK_FAULT,
"The PHY detected a fault in the receive direction. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_dying_gasp,
{ "Dying Gasp", "oampdu.flags.dyingGasp",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_DYING_GASP,
"An unrecoverable local failure occurred. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_critical_event,
{ "Critical Event", "oampdu.flags.criticalEvent",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_CRITICAL_EVENT,
"A critical event has occurred. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_local_evaluating,
{ "Local Evaluating", "oampdu.flags.localEvaluating",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_LOCAL_EVAL,
"Local DTE Discovery process in progress. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_local_stable,
{ "Local Stable", "oampdu.flags.localStable",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_LOCAL_STABLE,
"Local DTE is Stable. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_remote_evaluating,
{ "Remote Evaluating", "oampdu.flags.remoteEvaluating",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_REMOTE_EVAL,
"Remote DTE Discovery process in progress. True = 1, False = 0", HFILL }},
{ &hf_oampdu_flags_remote_stable,
{ "Remote Stable", "oampdu.flags.remoteStable",
FT_BOOLEAN, 8, TFS(&tfs_true_false), OAMPDU_FLAGS_REMOTE_STABLE,
"Remote DTE is Stable. True = 1, False = 0", HFILL }},
{ &hf_oampdu_code,
{ "OAMPDU code", "oampdu.code",
FT_UINT8, BASE_HEX, VALS(code_vals), 0x0,
"Identifies the TLVs code", HFILL }},
{ &hf_oampdu_info_type,
{ "Type", "oampdu.info.type",
FT_UINT8, BASE_HEX, VALS(info_type_vals), 0x0,
"Identifies the TLV type", HFILL }},
{ &hf_oampdu_info_len,
{ "TLV Length", "oampdu.info.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the TLVs type", HFILL }},
{ &hf_oampdu_info_version,
{ "TLV Version", "oampdu.info.version",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Identifies the TLVs version", HFILL }},
{ &hf_oampdu_info_revision,
{ "TLV Revision", "oampdu.info.revision",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the TLVs revision", HFILL }},
{ &hf_oampdu_info_state,
{ "OAM DTE States", "oampdu.info.state",
FT_UINT8, BASE_HEX, NULL, 0x0,
"OAM DTE State of the Mux and the Parser", HFILL }},
{ &hf_oampdu_info_state_parser,
{ "Parser Action", "oampdu.info.state.parser",
FT_UINT8, BASE_HEX, VALS(parser_vals), 0x03,
NULL, HFILL }},
{ &hf_oampdu_info_state_mux,
{ "Muxiplexer Action", "oampdu.info.state.muxiplexer",
FT_BOOLEAN, 8, TFS(&mux), 0x04,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig,
{ "OAM Configuration", "oampdu.info.oamConfig",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_mode,
{ "OAM Mode", "oampdu.info.oamConfig.mode",
FT_BOOLEAN, 8, TFS(&oam_mode), OAMPDU_INFO_CONFIG_MODE,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_uni,
{ "Unidirectional support", "oampdu.flags.dyingGasp",
FT_BOOLEAN, 8, TFS(&oam_uni), OAMPDU_INFO_CONFIG_UNI,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_lpbk,
{ "Loopback support", "oampdu.flags.criticalEvent",
FT_BOOLEAN, 8, TFS(&oam_lpbk), OAMPDU_INFO_CONFIG_LPBK,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_event,
{ "Link Events support", "oampdu.flags.localEvaluating",
FT_BOOLEAN, 8, TFS(&oam_event), OAMPDU_INFO_CONFIG_EVENT,
NULL, HFILL }},
{ &hf_oampdu_info_oamConfig_var,
{ "Variable Retrieval", "oampdu.flags.localStable",
FT_BOOLEAN, 8, TFS(&oam_var), OAMPDU_INFO_CONFIG_VAR,
"Variable Retrieval support", HFILL }},
{ &hf_oampdu_info_oampduConfig,
{ "Max OAMPDU Size", "oampdu.info.oampduConfig",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0,
"OAMPDU Configuration", HFILL }},
{ &hf_oampdu_info_oui,
{ "Organizationally Unique Identifier", "oampdu.info.oui",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_oampdu_info_vendor,
{ "Vendor Specific Information", "oampdu.info.vendor",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_oampdu_event_sequence,
{ "Sequence Number", "oampdu.event.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the Event Notification TLVs", HFILL }},
{ &hf_oampdu_event_type,
{ "Event Type", "oampdu.event.type",
FT_UINT8, BASE_HEX, VALS(event_type_vals), 0x0,
"Identifies the TLV type", HFILL }},
{ &hf_oampdu_event_length,
{ "Event Length", "oampdu.event.length",
FT_UINT8, BASE_HEX, NULL, 0x0,
"This field indicates the length in octets of the TLV-tuple", HFILL }},
{ &hf_oampdu_event_timeStamp,
{ "Event Timestamp (100ms)", "oampdu.event.timestamp",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Event Time Stamp in term of 100 ms intervals", HFILL }},
{ &hf_oampdu_event_espeWindow,
{ "Errored Symbol Window", "oampdu.event.espeWindow",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of symbols in the period", HFILL }},
{ &hf_oampdu_event_espeThreshold,
{ "Errored Symbol Threshold", "oampdu.event.espeThreshold",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of symbols required to generate the Event", HFILL }},
{ &hf_oampdu_event_espeErrors,
{ "Errored Symbols", "oampdu.event.espeErrors",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of symbols in error", HFILL }},
{ &hf_oampdu_event_espeTotalErrors,
{ "Error Running Total", "oampdu.event.espeTotalErrors",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of symbols in error since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_espeTotalEvents,
{ "Event Running Total", "oampdu.event.espeTotalEvents",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Event generated since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efeWindow,
{ "Errored Frame Window", "oampdu.event.efeWindow",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of symbols in the period", HFILL }},
{ &hf_oampdu_event_efeThreshold,
{ "Errored Frame Threshold", "oampdu.event.efeThreshold",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of frames required to generate the Event", HFILL }},
{ &hf_oampdu_event_efeErrors,
{ "Errored Frames", "oampdu.event.efeErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of symbols in error", HFILL }},
{ &hf_oampdu_event_efeTotalErrors,
{ "Error Running Total", "oampdu.event.efeTotalErrors",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of frames in error since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efeTotalEvents,
{ "Event Running Total", "oampdu.event.efeTotalEvents",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Event generated since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efpeWindow,
{ "Errored Frame Window", "oampdu.event.efpeWindow",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of frame in error during the period", HFILL }},
{ &hf_oampdu_event_efpeThreshold,
{ "Errored Frame Threshold", "oampdu.event.efpeThreshold",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of frames required to generate the Event", HFILL }},
{ &hf_oampdu_event_efpeErrors,
{ "Errored Frames", "oampdu.event.efeErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of symbols in error", HFILL }},
{ &hf_oampdu_event_efpeTotalErrors,
{ "Error Running Total", "oampdu.event.efpeTotalErrors",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Number of frames in error since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efpeTotalEvents,
{ "Event Running Total", "oampdu.event.efpeTotalEvents",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Event generated since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efsseWindow,
{ "Errored Frame Window", "oampdu.event.efsseWindow",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of frame in error during the period", HFILL }},
{ &hf_oampdu_event_efsseThreshold,
{ "Errored Frame Threshold", "oampdu.event.efsseThreshold",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of frames required to generate the Event", HFILL }},
{ &hf_oampdu_event_efsseErrors,
{ "Errored Frames", "oampdu.event.efeErrors",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of symbols in error", HFILL }},
{ &hf_oampdu_event_efsseTotalErrors,
{ "Error Running Total", "oampdu.event.efsseTotalErrors",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of frames in error since reset of the sublayer", HFILL }},
{ &hf_oampdu_event_efsseTotalEvents,
{ "Event Running Total", "oampdu.event.efsseTotalEvents",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total Event generated since reset of the sublayer", HFILL }},
{ &hf_oampdu_variable_branch,
{ "Branch", "oampdu.variable.branch",
FT_UINT8, BASE_HEX, VALS(branch_vals), 0x0,
"Variable Branch, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_object,
{ "Leaf", "oampdu.variable.object",
FT_UINT16, BASE_HEX, VALS(object_vals), 0x0,
"Object, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_package,
{ "Leaf", "oampdu.variable.package",
FT_UINT16, BASE_HEX, VALS(package_vals), 0x0,
"Package, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_binding,
{ "Leaf", "oampdu.variable.binding",
FT_UINT16, BASE_HEX, VALS(binding_vals), 0x0,
"Binding, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_attribute,
{ "Leaf", "oampdu.variable.attribute",
FT_UINT16, BASE_HEX|BASE_EXT_STRING, &attribute_vals_ext, 0x0,
"Attribute, derived from the CMIP protocol in Annex 30A", HFILL }},
{ &hf_oampdu_variable_width,
{ "Variable Width", "oampdu.variable.width",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Width", HFILL }},
{ &hf_oampdu_variable_indication,
{ "Variable indication", "oampdu.variable.indication",
FT_UINT8, BASE_HEX, VALS(indication_vals), 0x0,
NULL, HFILL }},
{ &hf_oampdu_variable_value,
{ "Variable Value", "oampdu.variable.value",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Value", HFILL }},
{ &hf_oampdu_lpbk,
{ "Commands", "oampdu.lpbk.commands",
FT_UINT8, BASE_HEX, NULL, 0x0,
"The List of Loopback Commands", HFILL }},
{ &hf_oampdu_lpbk_enable,
{ "Enable Remote Loopback", "oampdu.lpbk.commands.enable",
FT_BOOLEAN, 8, NULL, OAMPDU_LPBK_ENABLE,
"Enable Remote Loopback Command", HFILL }},
{ &hf_oampdu_lpbk_disable,
{ "Disable Remote Loopback", "oampdu.lpbk.commands.disable",
FT_BOOLEAN, 8, NULL, OAMPDU_LPBK_DISABLE,
"Disable Remote Loopback Command", HFILL }},
{ &hf_oampdu_vendor_specific_dpoe_opcode,
{ "DPoE Opcode", "oampdu.vendor.specific.opcode",
FT_UINT8, BASE_HEX, VALS(vendor_specific_opcode_vals),
0x0, NULL, HFILL }},
{ &hf_dpoe_variable_descriptor,
{ "Variable Descriptor", "oampdu.variable.descriptor",
FT_UINT8, BASE_HEX, VALS(dpoe_variable_descriptor_vals),
0x0, NULL, HFILL }},
{ &hf_dpoe_variable_response_code,
{ "Response Code", "oampdu.variable.response.code",
FT_UINT8, BASE_HEX, VALS(dpoe_variable_response_code_vals),
0x0, NULL, HFILL }},
{ &hf_oam_dpoe_response_eth,
{ "OAM Response Value", "oampdu.response.eth",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_oam_dpoe_response_int,
{ "OAM Response Value", "oampdu.response.int",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_oam_dpoe_mll_b,
{ "Bidirectional", "oampdu.mll.b",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_mll_do,
{ "Downstream-only", "oampdu.mll.do",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_frame_rate_maximum,
{ "Maximum OAM Rate", "oampdu.frame.rate.min",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_num_100ms, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_frame_rate_minimum,
{ "Minimum OAM Rate", "oampdu.frame.rate.max",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_pdus_100ms, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_repthr_nqs,
{ "Number of Queue Sets", "oampdu.report.threshold.queue",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_repthr_rvpqs,
{ "Report Values Per Queue Set", "oampdu.report.threshold.queue.values",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_report_threshold,
{ "Report Threshold", "oampdu.report.threshold",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg,
{ "Auto-Negotiation Capability", "oampdu.s1.autoneg",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg_hd,
{ "Half Duplex", "oampdu.s1.autoneg.hd",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x01,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg_fd,
{ "Full Duplex", "oampdu.s1.autoneg.fd",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x02,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg_10,
{ "10 Mbps", "oampdu.s1.autoneg.10",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x04,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg_100,
{ "100 Mbps", "oampdu.s1.autoneg.100",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x08,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg_1000,
{ "1000 Mbps", "oampdu.s1.autoneg.1000",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x10,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg_10000,
{ "10Gbps", "oampdu.s1.autoneg.10000",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x20,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg_fc,
{ "Flow Control", "oampdu.s1.autoneg.fc",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x40,
NULL, HFILL } },
{ &hf_oam_dpoe_s1_autoneg_mdi,
{ "Auto MDI/MDI-X", "oampdu.s1.autoneg.mdi",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x80,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object,
{ "UNI Number", "oampdu.user.port.object",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_subtype,
{ "Subtype", "oampdu.user.port.object.subtype",
FT_UINT16, BASE_DEC, VALS(user_port_object_subtype_vals), 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_header_precedence,
{ "Precedence", "oampdu.user.port.object.header.precedence",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_clause_fc,
{ "Field Code", "oampdu.user.port.object.clause.fc",
FT_UINT8, BASE_HEX, VALS(user_port_object_clause_fc_vals), 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_clause_fi,
{ "Field Instance", "oampdu.user.port.object.clause.fi",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_clause_msbm,
{ "MSB Mask", "oampdu.user.port.object.clause.msbm",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_clause_lsbm,
{ "LSB Mask", "oampdu.user.port.object.clause.lsbm",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_clause_operator,
{ "Operator", "oampdu.user.port.object.clause.operator",
FT_UINT8, BASE_HEX, VALS(user_port_object_clause_operator_vals), 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_clause_mvl,
{ "Match Value Length", "oampdu.user.port.object.clause.mvl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_clause_mv,
{ "Match Value", "oampdu.user.port.object.clause.mv",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr,
{ "Rule Result", "oampdu.user.port.object.result.rr",
FT_UINT8, BASE_HEX, VALS(user_port_object_result_rr_vals), 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_queue,
{ "{port type, port instance, link, queue}", "oampdu.user.port.object.result.rr.queue",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_set_fc,
{ "Field Code", "oampdu.user.port.object.result.rr.set.fc",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_set_fi,
{ "Field Instance", "oampdu.user.port.object.result.rr.set.fi",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_copy,
{ "Field Code to set from field used in last clause of rule", "oampdu.user.port.object.result.rr.copy",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_delete,
{ "Field Code to remove from frame", "oampdu.user.port.object.result.rr.delete",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_insert,
{ "Field Code to insert into frame", "oampdu.user.port.object.result.rr.insert",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_replace,
{ "Field Code to replace", "oampdu.user.port.object.result.rr.replace",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_cd,
{ "Field Code not to delete", "oampdu.user.port.object.result.rr.cd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_user_port_object_result_rr_ci,
{ "Field Code not to insert", "oampdu.user.port.object.result.rr.ci",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_qc_ll_u,
{ "Upstream Logical Links", "oampdu.queue_configuration.logical_links.upstream",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_qc_ports_d,
{ "Downstream Ports", "oampdu.queue_configuration.ports.downstream",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_qc_nq,
{"Number of queues", "oampdu.queue_configuration.queues",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
{ &hf_oam_dpoe_qc_queue_size,
{"Queue size (in 4KB units)", "oampdu.queue_configuration.size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL } },
};
static gint *ett[] = {
&ett_oampdu,
&ett_oampdu_flags,
&ett_oampdu_local_info,
&ett_oampdu_local_info_state,
&ett_oampdu_local_info_config,
&ett_oampdu_remote_info,
&ett_oampdu_remote_info_state,
&ett_oampdu_remote_info_config,
&ett_oampdu_org_info,
&ett_oampdu_event_espe,
&ett_oampdu_event_efe,
&ett_oampdu_event_efpe,
&ett_oampdu_event_efsse,
&ett_oampdu_event_ose,
&ett_oampdu_lpbk_ctrl,
&ett_oampdu_vendor_specific,
&ett_dpoe_opcode,
&ett_dpoe_opcode_response,
&ett_oam_dpoe_s1_autoneg,
&ett_oam_dpoe_qc_u,
&ett_oam_dpoe_qc_d,
&ett_oam_dpoe_qc_nq,
};
static ei_register_info ei[] = {
{ &ei_oampdu_event_length_bad, { "oampdu.event.length.bad", PI_MALFORMED, PI_ERROR, "Event length should be at least 2", EXPFILL }},
};
expert_module_t* expert_oampdu;
proto_oampdu = proto_register_protocol("OAMPDU", "Ethernet OAM PDU", "oampdu");
proto_register_field_array(proto_oampdu, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_oampdu = expert_register_protocol(proto_oampdu);
expert_register_field_array(expert_oampdu, ei, array_length(ei));
}
void
proto_reg_handoff_oampdu(void)
{
dissector_handle_t oampdu_handle;
oampdu_handle = create_dissector_handle(dissect_oampdu, proto_oampdu);
dissector_add_uint("slow.subtype", OAM_SUBTYPE, oampdu_handle);
}
