static void
dissect_q2931_shift_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, guint8 info_element)
{
gboolean non_locking_shift;
guint8 codeset;
if (len == 0)
return;
non_locking_shift = (info_element == Q2931_IE_BBAND_NLOCKING_SHIFT);
codeset = tvb_get_guint8(tvb, offset) & 0x07;
proto_tree_add_text(tree, tvb, offset, 1, "%s shift to codeset %u: %s",
(non_locking_shift ? "Non-locking" : "Locking"),
codeset,
val_to_str(codeset, q2931_codeset_vals, "Unknown (0x%02X)"));
}
static void
dissect_q2931_aal_parameters_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 aal_type;
guint8 identifier;
guint32 value;
guint32 low_mid, high_mid;
if (len == 0)
return;
aal_type = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1, "AAL type: %s",
val_to_str(aal_type, q9231_aal_type_vals, "Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (aal_type == 0x40) {
if (len > 4)
len = 4;
proto_tree_add_text(tree, tvb, offset, len,
"User defined AAL information: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
while (len >= 0) {
identifier = tvb_get_guint8(tvb, offset);
switch (identifier) {
case 0x85:
if (len < 2)
return;
value = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 2,
"Subtype: %s",
val_to_str(value, q9231_aal1_subtype_vals,
"Unknown (0x%02X)"));
offset += 2;
len -= 2;
break;
case 0x86:
if (len < 2)
return;
value = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 2,
"CBR rate: %s",
val_to_str(value, q9231_aal1_cbr_rate_vals,
"Unknown (0x%02X)"));
offset += 2;
len -= 2;
break;
case 0x87:
if (len < 3)
return;
value = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 3,
"Multiplier: %u", value);
offset += 3;
len -= 3;
break;
case 0x88:
if (len < 2)
return;
value = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 2,
"Source clock frequency recovery method: %s",
val_to_str(value, q2931_aal1_src_clk_rec_meth_vals,
"Unknown (0x%02X)"));
offset += 2;
len -= 2;
break;
case 0x89:
if (len < 2)
return;
value = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 2,
"Error correction method: %s",
val_to_str(value, q2931_aal1_err_correction_method_vals,
"Unknown (0x%02X)"));
offset += 2;
len -= 2;
break;
case 0x8A:
if (len < 3)
return;
value = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 3,
"Structured data transfer block size: %u", value);
offset += 3;
len -= 3;
break;
case 0x8B:
if (len < 2)
return;
value = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 2,
"Partially filled cells method: %u octets", value);
offset += 2;
len -= 2;
break;
case 0x8C:
if (len < 3)
return;
value = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 3,
"Forward maximum CPCS-SDU size: %u", value);
offset += 3;
len -= 3;
break;
case 0x81:
if (len < 3)
return;
value = tvb_get_ntohs(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 3,
"Backward maximum CPCS-SDU size: %u", value);
offset += 3;
len -= 3;
break;
case 0x82:
if (len < 5)
return;
low_mid = tvb_get_ntohs(tvb, offset + 1);
high_mid = tvb_get_ntohs(tvb, offset + 3);
proto_tree_add_text(tree, tvb, offset, 3,
"MID range: %u - %u", low_mid, high_mid);
offset += 5;
len -= 5;
break;
case 0x83:
if (len < 2)
return;
value = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 2,
"Mode: %s",
val_to_str(value, q2931_aal_mode_vals,
"Unknown (0x%02X)"));
offset += 2;
len -= 2;
break;
case 0x84:
if (len < 2)
return;
value = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 2,
"SSCS type: %s",
val_to_str(value, q2931_sscs_type_vals,
"Unknown (0x%02X)"));
offset += 2;
len -= 2;
break;
default:
proto_tree_add_text(tree, tvb, offset, 1,
"Unknown AAL parameter (0x%02X)",
identifier);
return;
}
}
}
static void
dissect_q2931_atm_cell_rate_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 identifier;
guint32 value;
while (len >= 0) {
identifier = tvb_get_guint8(tvb, offset);
switch (identifier) {
case Q2931_ATM_CR_FW_PEAK_CLP_0:
case Q2931_ATM_CR_BW_PEAK_CLP_0:
case Q2931_ATM_CR_FW_PEAK_CLP_0_1:
case Q2931_ATM_CR_BW_PEAK_CLP_0_1:
case Q2931_ATM_CR_FW_SUST_CLP_0:
case Q2931_ATM_CR_BW_SUST_CLP_0:
case Q2931_ATM_CR_FW_SUST_CLP_0_1:
case Q2931_ATM_CR_BW_SUST_CLP_0_1:
case Q2931_ATM_CR_FW_MAXB_CLP_0:
case Q2931_ATM_CR_BW_MAXB_CLP_0:
case Q2931_ATM_CR_FW_MAXB_CLP_0_1:
case Q2931_ATM_CR_BW_MAXB_CLP_0_1:
if (len < 4)
return;
value = tvb_get_ntoh24(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 4,
"%s: %u cell%s/s",
val_to_str(identifier, q2931_atm_td_subfield_vals,
"Unknown (0x%02X)"),
value, plurality(value, "", "s"));
offset += 4;
len -= 4;
break;
case Q2931_ATM_CR_BEST_EFFORT_IND:
proto_tree_add_text(tree, tvb, offset, 1,
"%s",
val_to_str(identifier, q2931_atm_td_subfield_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
break;
case Q2931_ATM_CR_TRAFFIC_MGMT_OPT:
if (len < 2)
return;
value = tvb_get_guint8(tvb, offset + 1);
proto_tree_add_text(tree, tvb, offset, 2,
"%s",
val_to_str(identifier, q2931_atm_td_subfield_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset + 1, 1,
"%s allowed in forward direction",
(value & 0x80) ? "Frame discard" : "No frame discard");
proto_tree_add_text(tree, tvb, offset + 1, 1,
"%s allowed in backward direction",
(value & 0x40) ? "Frame discard" : "No frame discard");
proto_tree_add_text(tree, tvb, offset + 1, 1,
"Tagging %srequested in backward direction",
(value & 0x02) ? "" : "not ");
proto_tree_add_text(tree, tvb, offset + 1, 1,
"Tagging %srequested in forward direction",
(value & 0x01) ? "" : "not ");
offset += 2;
len -= 2;
break;
default:
proto_tree_add_text(tree, tvb, offset, 1,
"Unknown ATM traffic descriptor element (0x%02X)",
identifier);
return;
}
}
}
static void
dissect_q2931_bband_bearer_cap_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Bearer class: %s",
val_to_str(octet & 0x1F, q2931_bearer_class_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
if (!(octet & Q2931_IE_EXTENSION)) {
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"ATM Transfer Capability: %s",
val_to_str(octet & 0x1F, q2931_transfer_capability_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Susceptibility to clipping: %s",
val_to_str(octet & 0x60, q2931_susc_clip_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"User-plane connection configuration: %s",
val_to_str(octet & 0x03, q2931_up_conn_config_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q2931_bband_hi_layer_info_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"High layer information type: %s",
val_to_str(octet & 0x7F, q2931_hi_layer_info_type_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q2931_bband_low_layer_info_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 uil2_protocol;
guint8 uil3_protocol;
guint8 add_l3_info;
guint32 organization_code;
guint16 pid;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x20) {
proto_tree_add_text(tree, tvb, offset, 1,
"User information layer 1 protocol: 0x%02X",
octet & 0x1F);
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x40) {
uil2_protocol = octet & 0x1F;
proto_tree_add_text(tree, tvb, offset, 1,
"User information layer 2 protocol: %s",
val_to_str(uil2_protocol, q2931_uil2_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q2931_IE_EXTENSION)
goto l2_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if (uil2_protocol == Q2931_UIL2_USER_SPEC) {
proto_tree_add_text(tree, tvb, offset, 1,
"User-specified layer 2 protocol information: 0x%02X",
octet & 0x7F);
} else {
proto_tree_add_text(tree, tvb, offset, 1,
"Mode: %s",
val_to_str(octet & 0x60, q2931_mode_vals,
"Unknown (0x%02X)"));
}
offset += 1;
len -= 1;
if (octet & Q2931_IE_EXTENSION)
goto l2_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Window size: %u k", octet & 0x7F);
offset += 1;
len -= 1;
}
l2_done:
;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x60) {
uil3_protocol = octet & 0x1F;
proto_tree_add_text(tree, tvb, offset, 1,
"User information layer 3 protocol: %s",
val_to_str(uil3_protocol, q2931_uil3_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q2931_IE_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
switch (uil3_protocol) {
case Q2931_UIL3_X25_PL:
case Q2931_UIL3_ISO_8208:
case Q2931_UIL3_X223:
proto_tree_add_text(tree, tvb, offset, 1,
"Mode: %s",
val_to_str(octet & 0x60, q2931_mode_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q2931_IE_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Default packet size: %u", octet & 0x0F);
offset += 1;
len -= 1;
if (octet & Q2931_IE_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Packet window size: %u", octet & 0x7F);
break;
case Q2931_UIL3_USER_SPEC:
proto_tree_add_text(tree, tvb, offset, 1,
"Default packet size: %u octets",
1 << (octet & 0x0F));
break;
case Q2931_UIL3_TR_9577:
add_l3_info = (octet & 0x7F) << 1;
if (octet & Q2931_IE_EXTENSION)
goto l3_done;
if (len < 2)
return;
add_l3_info |= (tvb_get_guint8(tvb, offset + 1) & 0x40) >> 6;
proto_tree_add_text(tree, tvb, offset, 2,
"Additional layer 3 protocol information: %s",
val_to_str(add_l3_info, nlpid_vals,
"Unknown (0x%02X)"));
offset += 2;
len -= 2;
if (add_l3_info == NLPID_SNAP) {
if (len < 6)
return;
offset += 1;
organization_code = tvb_get_ntoh24(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 3,
"Organization Code: 0x%06X (%s)",
organization_code,
val_to_str_const(organization_code, oui_vals,
"Unknown"));
offset += 3;
pid = tvb_get_ntohs(tvb, offset);
switch (organization_code) {
case OUI_ENCAP_ETHER:
proto_tree_add_text(tree, tvb, offset, 2,
"Ethernet type: %s",
val_to_str(pid, etype_vals,
"Unknown (0x%04X)"));
break;
case OUI_ATM_FORUM:
proto_tree_add_text(tree, tvb, offset, 2,
"LANE Protocol ID: %s",
val_to_str(pid, lane_pid_vals,
"Unknown (0x%04X)"));
break;
default:
proto_tree_add_text(tree, tvb, offset, 2,
"Protocol ID: 0x%04X", pid);
break;
}
}
break;
}
}
l3_done:
;
}
static void
dissect_q2931_cause_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 cause_value;
guint8 rejection_reason;
guint8 info_element;
guint8 info_element_ext;
guint16 info_element_len;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Location: %s",
val_to_str(octet & 0x0F, q2931_cause_location_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
cause_value = octet & 0x7F;
proto_tree_add_text(tree, tvb, offset, 1,
"Cause value: %s",
val_to_str(cause_value, q2931_cause_code_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
switch (cause_value) {
case Q2931_CAUSE_UNALLOC_NUMBER:
case Q2931_CAUSE_NO_ROUTE_TO_DEST:
case Q2931_CAUSE_QOS_UNAVAILABLE:
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Network service: %s",
(octet & 0x80) ? "User" : "Provider");
proto_tree_add_text(tree, tvb, offset, 1,
"%s",
(octet & 0x40) ? "Abnormal" : "Normal");
proto_tree_add_text(tree, tvb, offset, 1,
"Condition: %s",
val_to_str(octet & 0x03, q2931_cause_condition_vals,
"Unknown (0x%X)"));
break;
case Q2931_CAUSE_CALL_REJECTED:
rejection_reason = octet & 0x7C;
proto_tree_add_text(tree, tvb, offset, 1,
"Rejection reason: %s",
val_to_str(octet & 0x7C, q2931_rejection_reason_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Condition: %s",
val_to_str(octet & 0x03, q2931_cause_condition_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
switch (rejection_reason) {
case Q2931_REJ_USER_SPECIFIC:
proto_tree_add_text(tree, tvb, offset, len,
"User specific diagnostic: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
case Q2931_REJ_IE_MISSING:
proto_tree_add_text(tree, tvb, offset, 1,
"Missing information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), q2931_info_element_vals,
"Unknown (0x%02X)"));
break;
case Q2931_REJ_IE_INSUFFICIENT:
proto_tree_add_text(tree, tvb, offset, 1,
"Insufficient information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), q2931_info_element_vals,
"Unknown (0x%02X)"));
break;
default:
proto_tree_add_text(tree, tvb, offset, len,
"Diagnostic: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
}
break;
case Q2931_CAUSE_NUMBER_CHANGED:
info_element = tvb_get_guint8(tvb, offset);
info_element_ext = tvb_get_guint8(tvb, offset + 1);
info_element_len = tvb_get_ntohs(tvb, offset + 2);
dissect_q2931_ie(tvb, offset, info_element_len, tree,
info_element, info_element_ext);
break;
case Q2931_CAUSE_ACCESS_INFO_DISC:
case Q2931_CAUSE_INCOMPATIBLE_DEST:
case Q2931_CAUSE_MAND_IE_MISSING:
case Q2931_CAUSE_IE_NONEX_OR_UNIMPL:
case Q2931_CAUSE_INVALID_IE_CONTENTS:
do {
proto_tree_add_text(tree, tvb, offset, 1,
"Information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), q2931_info_element_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
} while (len >= 0);
break;
case Q2931_CAUSE_CELL_RATE_UNAVAIL:
do {
proto_tree_add_text(tree, tvb, offset, 1,
"Cell rate subfield identifier: %s",
val_to_str(tvb_get_guint8(tvb, offset), q2931_atm_td_subfield_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
} while (len >= 0);
break;
case Q2931_CAUSE_CHAN_NONEXISTENT:
if (len < 2)
return;
proto_tree_add_text(tree, tvb, offset, 2,
"VPCI: %u", tvb_get_ntohs(tvb, offset));
offset += 2;
len -= 2;
if (len < 2)
return;
proto_tree_add_text(tree, tvb, offset, 2,
"VCI: %u", tvb_get_ntohs(tvb, offset));
break;
case Q2931_CAUSE_MT_NONEX_OR_UNIMPL:
case Q2931_CAUSE_MSG_INCOMPAT_W_CS:
proto_tree_add_text(tree, tvb, offset, 1,
"Message type: %s",
val_to_str(tvb_get_guint8(tvb, offset), q2931_message_type_vals,
"Unknown (0x%02X)"));
break;
case Q2931_CAUSE_REC_TIMER_EXP:
if (len < 3)
return;
proto_tree_add_text(tree, tvb, offset, 3,
"Timer: %.3s", tvb_get_string(wmem_packet_scope(), tvb, offset, 3));
break;
default:
proto_tree_add_text(tree, tvb, offset, len,
"Diagnostics: %s",
tvb_bytes_to_str(tvb, offset, len));
}
}
static void
dissect_q2931_call_state_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Call state: %s",
val_to_str(octet & 0x3F, q2931_call_state_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q2931_number_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 numbering_plan;
proto_item *ti;
proto_tree *nsap_tree;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Type of number: %s",
val_to_str(octet & 0x70, q2931_number_type_vals,
"Unknown (0x%02X)"));
numbering_plan = octet & 0x0F;
proto_tree_add_text(tree, tvb, offset, 1,
"Numbering plan: %s",
val_to_str(numbering_plan, q2931_numbering_plan_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (!(octet & Q2931_IE_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Presentation indicator: %s",
val_to_str(octet & 0x60, q2931_presentation_indicator_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Screening indicator: %s",
val_to_str(octet & 0x03, q2931_screening_indicator_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
}
if (len == 0)
return;
switch (numbering_plan) {
case Q2931_ISDN_NUMBERING:
proto_tree_add_text(tree, tvb, offset, len, "Number: %.*s",
len, tvb_get_string(wmem_packet_scope(), tvb, offset, len));
break;
case Q2931_NSAP_ADDRESSING:
if (len < 20) {
proto_tree_add_text(tree, tvb, offset, len,
"Number (too short): %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
ti = proto_tree_add_text(tree, tvb, offset, len, "Number");
nsap_tree = proto_item_add_subtree(ti, ett_q2931_nsap);
dissect_atm_nsap(tvb, offset, len, nsap_tree);
break;
default:
proto_tree_add_text(tree, tvb, offset, len, "Number: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
}
}
static void
dissect_q2931_party_subaddr_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Type of subaddress: %s",
val_to_str(octet & 0x70, q2931_subaddress_type_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Odd/even indicator: %s",
val_to_str(octet & 0x10, q2931_odd_even_indicator_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, len, "Subaddress: %s",
tvb_bytes_to_str(tvb, offset, len));
}
static void
dissect_q2931_connection_identifier_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"VP-associated signalling: %s",
val_to_str(octet & 0x18, q2931_vp_associated_signalling_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Preferred/exclusive: %s",
val_to_str(octet & 0x07, q2931_preferred_exclusive_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len < 2)
return;
proto_tree_add_text(tree, tvb, offset, 2, "VPCI: %u",
tvb_get_ntohs(tvb, offset));
offset += 2;
len -= 2;
if (len < 2)
return;
proto_tree_add_text(tree, tvb, offset, 2, "VCI: %u",
tvb_get_ntohs(tvb, offset));
}
static void
dissect_q2931_e2e_transit_delay_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 identifier;
guint16 value;
while (len >= 3) {
identifier = tvb_get_guint8(tvb, offset);
value = tvb_get_ntohs(tvb, offset + 1);
len -=3;
switch (identifier) {
case 0x01:
proto_tree_add_text(tree, tvb, offset, 3,
"Cumulative transit delay: %u ms", value);
break;
case 0x03:
if (value == 0xFFFF) {
proto_tree_add_text(tree, tvb, offset, 3,
"Any end-to-end transit delay value acceptable");
} else {
proto_tree_add_text(tree, tvb, offset, 3,
"Maximum end-to-end transit delay: %u ms",
value);
}
break;
default:
proto_tree_add_text(tree, tvb, offset, 1,
"Unknown transit delay identifier (0x%02X)",
identifier);
return;
}
}
}
static void
dissect_q2931_qos_parameter_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"QOS class forward: %s",
val_to_str(octet, q2931_qos_parameter_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"QOS class backward: %s",
val_to_str(octet, q2931_qos_parameter_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q2931_bband_rpt_indicator(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Broadband repeat indicator: %s",
val_to_str(octet & 0x0F, q2931_bband_rpt_indicator_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q2931_restart_indicator(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Restart indicator: %s",
val_to_str(octet & 0x07, q2931_class_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q2931_bband_sending_compl_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 identifier;
while (len >= 0) {
identifier = tvb_get_guint8(tvb, offset);
switch (identifier) {
case 0xA1:
proto_tree_add_text(tree, tvb, offset, 1,
"Broadband sending complete indication");
offset += 1;
len -= 1;
break;
default:
proto_tree_add_text(tree, tvb, offset, 1,
"Unknown broadband sending complete element (0x%02X)",
identifier);
return;
}
}
}
static void
dissect_q2931_transit_network_sel_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Type of network identification: %s",
val_to_str(octet & 0x70, q2931_netid_type_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Network identification plan: %s",
val_to_str(octet & 0x0F, q2931_netid_plan_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, len,
"Network identification: %.*s", len, tvb_get_string(wmem_packet_scope(), tvb, offset, len));
}
static void
dissect_q2931_oam_traffic_descriptor_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Shaping indicator: %s",
val_to_str(octet & 0x60, q2931_shaping_indicator_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Use of end-to-end OAM F5 flow is %s",
(octet & 0x10) ? "mandatory" : "optional");
proto_tree_add_text(tree, tvb, offset, 1,
"User-Network fault management indicator: %s",
val_to_str(octet & 0x07, q2931_user_net_fault_mgmt_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Forward end-to-end OAM F5 flow indicator: %s",
val_to_str(octet & 0x70, q2931_fwd_e2e_oam_f5_flow_indicator_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Backward end-to-end OAM F5 flow indicator: %s",
val_to_str(octet & 0x07, q2931_bwd_e2e_oam_f5_flow_indicator_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q2931_endpoint_reference_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint16 value;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Endpoint reference type: %s",
val_to_str(octet, q2931_endpoint_reference_type_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len < 2)
return;
value = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 2,
"Endpoint reference flag: %s",
(value & 0x8000) ? "Message sent to side that originates the endpoint reference" :
"Message sent from side that originates the endpoint reference");
proto_tree_add_text(tree, tvb, offset, 2,
"Endpoint reference identifier value: %u",
value & 0x7FFF);
}
static void
dissect_q2931_endpoint_state_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Endpoint reference party-state: %s",
val_to_str(octet & 0x3F, q2931_endpoint_reference_party_state_vals,
"Unknown (0x%02X)"));
}
static void
dissect_q2931_ie_contents(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, guint8 info_element)
{
switch (info_element) {
case Q2931_IE_BBAND_LOCKING_SHIFT:
case Q2931_IE_BBAND_NLOCKING_SHIFT:
dissect_q2931_shift_ie(tvb, offset, len, tree, info_element);
break;
case Q2931_IE_NBAND_BEARER_CAP:
case Q2931_IE_NBAND_LOW_LAYER_COMPAT:
dissect_q931_bearer_capability_ie(tvb, offset, len, tree);
break;
case Q2931_IE_NBAND_HIGH_LAYER_COMPAT:
dissect_q931_high_layer_compat_ie(tvb, offset, len, tree);
break;
case Q2931_IE_PROGRESS_INDICATOR:
dissect_q931_progress_indicator_ie(tvb, offset, len, tree);
break;
case Q2931_IE_AAL_PARAMETERS:
dissect_q2931_aal_parameters_ie(tvb, offset, len, tree);
break;
case Q2931_IE_ATM_USER_CELL_RATE:
dissect_q2931_atm_cell_rate_ie(tvb, offset, len, tree);
break;
case Q2931_IE_BBAND_BEARER_CAP:
dissect_q2931_bband_bearer_cap_ie(tvb, offset, len, tree);
break;
case Q2931_IE_BBAND_HI_LAYER_INFO:
dissect_q2931_bband_hi_layer_info_ie(tvb, offset, len, tree);
break;
case Q2931_IE_BBAND_LOW_LAYER_INFO:
dissect_q2931_bband_low_layer_info_ie(tvb, offset, len, tree);
break;
case Q2931_IE_CALL_STATE:
dissect_q2931_call_state_ie(tvb, offset, len, tree);
break;
case Q2931_IE_CALLED_PARTY_NUMBER:
case Q2931_IE_CALLING_PARTY_NUMBER:
dissect_q2931_number_ie(tvb, offset, len, tree);
break;
case Q2931_IE_CALLED_PARTY_SUBADDR:
case Q2931_IE_CALLING_PARTY_SUBADDR:
dissect_q2931_party_subaddr_ie(tvb, offset, len, tree);
break;
case Q2931_IE_CAUSE:
dissect_q2931_cause_ie(tvb, offset, len, tree);
break;
case Q2931_IE_CONNECTION_IDENTIFIER:
dissect_q2931_connection_identifier_ie(tvb, offset, len, tree);
break;
case Q2931_IE_E2E_TRANSIT_DELAY:
dissect_q2931_e2e_transit_delay_ie(tvb, offset, len, tree);
break;
case Q2931_IE_QOS_PARAMETER:
dissect_q2931_qos_parameter_ie(tvb, offset, len, tree);
break;
case Q2931_IE_BBAND_RPT_INDICATOR:
dissect_q2931_bband_rpt_indicator(tvb, offset, len, tree);
break;
case Q2931_IE_RESTART_INDICATOR:
dissect_q2931_restart_indicator(tvb, offset, len, tree);
break;
case Q2931_IE_BBAND_SENDING_COMPL:
dissect_q2931_bband_sending_compl_ie(tvb, offset, len, tree);
break;
case Q2931_IE_TRANSIT_NETWORK_SEL:
dissect_q2931_transit_network_sel_ie(tvb, offset, len, tree);
break;
case Q2931_IE_OAM_TRAFFIC_DESCRIPTOR:
dissect_q2931_oam_traffic_descriptor_ie(tvb, offset, len, tree);
break;
case Q2931_IE_ENDPOINT_REFERENCE:
dissect_q2931_endpoint_reference_ie(tvb, offset, len, tree);
break;
case Q2931_IE_ENDPOINT_STATE:
dissect_q2931_endpoint_state_ie(tvb, offset, len, tree);
break;
}
}
static void
dissect_q2931_ie(tvbuff_t *tvb, int offset, int len, proto_tree *tree,
guint8 info_element, guint8 info_element_ext)
{
proto_item *ti;
proto_tree *ie_tree;
proto_tree *ie_ext_tree;
ti = proto_tree_add_text(tree, tvb, offset, 1+1+2+len, "%s",
val_to_str(info_element, q2931_info_element_vals,
"Unknown information element (0x%02X)"));
ie_tree = proto_item_add_subtree(ti, ett_q2931_ie);
proto_tree_add_text(ie_tree, tvb, offset, 1, "Information element: %s",
val_to_str(info_element, q2931_info_element_vals,
"Unknown (0x%02X)"));
ti = proto_tree_add_text(ie_tree, tvb, offset + 1, 1,
"Information element extension: 0x%02x",
info_element_ext);
ie_ext_tree = proto_item_add_subtree(ti, ett_q2931_ie_ext);
proto_tree_add_item(ie_ext_tree, hf_q2931_ie_coding_standard, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_ext_tree, hf_q2931_ie_handling_instructions, tvb, offset+1, 1, ENC_BIG_ENDIAN);
if (info_element_ext & Q2931_IE_COMPAT_FOLLOW_INST) {
proto_tree_add_item(ie_ext_tree, hf_q2931_ie_action_indicator, tvb, offset+1, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_text(ie_tree, tvb, offset + 2, 2, "Length: %u", len);
if ((info_element_ext & Q2931_IE_COMPAT_CODING_STD)
== Q2931_ITU_STANDARDIZED_CODING) {
dissect_q2931_ie_contents(tvb, offset + 4,
len, ie_tree, info_element);
} else {
proto_tree_add_text(ie_tree, tvb, offset + 4, len,
"Data: %s", tvb_bytes_to_str(tvb, offset + 4, len));
}
}
static void
dissect_q2931(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
proto_tree *q2931_tree = NULL;
proto_item *ti;
proto_tree *ext_tree;
guint8 call_ref_len;
guint8 call_ref[15];
guint8 message_type;
guint8 message_type_ext;
guint16 message_len;
guint8 info_element;
guint8 info_element_ext;
guint16 info_element_len;
#if 0
int codeset;
gboolean non_locking_shift;
#endif
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Q.2931");
if (tree) {
ti = proto_tree_add_item(tree, proto_q2931, tvb, offset, -1,
ENC_NA);
q2931_tree = proto_item_add_subtree(ti, ett_q2931);
proto_tree_add_uint(q2931_tree, hf_q2931_discriminator, tvb, offset, 1, tvb_get_guint8(tvb, offset));
}
offset += 1;
call_ref_len = tvb_get_guint8(tvb, offset) & 0xF;
if (q2931_tree != NULL)
proto_tree_add_uint(q2931_tree, hf_q2931_call_ref_len, tvb, offset, 1, call_ref_len);
offset += 1;
if (call_ref_len != 0) {
tvb_memcpy(tvb, call_ref, offset, call_ref_len);
if (q2931_tree != NULL) {
proto_tree_add_boolean(q2931_tree, hf_q2931_call_ref_flag,
tvb, offset, 1, (call_ref[0] & 0x80) != 0);
call_ref[0] &= 0x7F;
proto_tree_add_bytes(q2931_tree, hf_q2931_call_ref, tvb, offset, call_ref_len, call_ref);
}
offset += call_ref_len;
}
message_type = tvb_get_guint8(tvb, offset);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(message_type, q2931_message_type_vals,
"Unknown message type (0x%02X)"));
if (q2931_tree != NULL)
proto_tree_add_uint(q2931_tree, hf_q2931_message_type, tvb, offset, 1, message_type);
offset += 1;
message_type_ext = tvb_get_guint8(tvb, offset);
if (q2931_tree != NULL) {
ti = proto_tree_add_uint(q2931_tree, hf_q2931_message_type_ext, tvb,
offset, 1, message_type_ext);
ext_tree = proto_item_add_subtree(ti, ett_q2931_ext);
proto_tree_add_boolean(ext_tree, hf_q2931_message_flag, tvb,
offset, 1, message_type_ext);
if (message_type_ext & Q2931_MSG_TYPE_EXT_FOLLOW_INST) {
proto_tree_add_uint(ext_tree, hf_q2931_message_action_indicator, tvb,
offset, 1, message_type_ext);
}
}
offset += 1;
message_len = tvb_get_ntohs(tvb, offset);
if (q2931_tree != NULL)
proto_tree_add_uint(q2931_tree, hf_q2931_message_len, tvb, offset, 2, message_len);
offset += 2;
#if 0
codeset = 0;
non_locking_shift = TRUE;
#endif
while (tvb_reported_length_remaining(tvb, offset) > 0) {
info_element = tvb_get_guint8(tvb, offset);
info_element_ext = tvb_get_guint8(tvb, offset + 1);
info_element_len = tvb_get_ntohs(tvb, offset + 2);
if (q2931_tree != NULL) {
dissect_q2931_ie(tvb, offset, info_element_len,
q2931_tree, info_element, info_element_ext);
}
#if 0
if (non_locking_shift)
codeset = 0;
switch (info_element) {
case Q2931_IE_BBAND_LOCKING_SHIFT:
if (info_element_len >= 1) {
non_locking_shift = FALSE;
codeset = tvb_get_guint8(tvb, offset + 4) & 0x07;
}
break;
case Q2931_IE_BBAND_NLOCKING_SHIFT:
if (info_element_len >= 1) {
non_locking_shift = TRUE;
codeset = tvb_get_guint8(tvb, offset + 4) & 0x07;
}
break;
}
#endif
offset += 1 + 1 + 2 + info_element_len;
}
}
void
proto_register_q2931(void)
{
static hf_register_info hf[] = {
{ &hf_q2931_discriminator,
{ "Protocol discriminator", "q2931.disc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_q2931_call_ref_len,
{ "Call reference value length", "q2931.call_ref_len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_q2931_call_ref_flag,
{ "Call reference flag", "q2931.call_ref_flag", FT_BOOLEAN, BASE_NONE, TFS(&tfs_call_ref_flag), 0x0,
NULL, HFILL }},
{ &hf_q2931_call_ref,
{ "Call reference value", "q2931.call_ref", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q2931_message_type,
{ "Message type", "q2931.message_type", FT_UINT8, BASE_HEX, VALS(q2931_message_type_vals), 0x0,
NULL, HFILL }},
{ &hf_q2931_message_type_ext,
{ "Message type extension", "q2931.message_type_ext", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_q2931_message_flag,
{ "Flag", "q2931.message_flag", FT_BOOLEAN, 8, TFS(&tos_msg_flag), Q2931_MSG_TYPE_EXT_FOLLOW_INST,
NULL, HFILL }},
{ &hf_q2931_message_action_indicator,
{ "Action indicator", "q2931.message_action_indicator", FT_UINT8, BASE_DEC, VALS(msg_action_ind_vals), Q2931_MSG_TYPE_EXT_ACTION_IND,
NULL, HFILL }},
{ &hf_q2931_message_len,
{ "Message length", "q2931.message_len", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_q2931_ie_handling_instructions,
{ "Handling Instructions", "q2931.ie_handling_instructions", FT_BOOLEAN, 8, TFS(&tfs_q2931_handling_instructions), Q2931_IE_COMPAT_FOLLOW_INST,
NULL, HFILL }},
{ &hf_q2931_ie_coding_standard,
{ "Coding standard", "q2931.ie_coding_standard", FT_UINT8, BASE_DEC, VALS(coding_std_vals), Q2931_IE_COMPAT_CODING_STD,
NULL, HFILL }},
{ &hf_q2931_ie_action_indicator,
{ "Action indicator", "q2931.ie_action_indicator", FT_UINT8, BASE_DEC, VALS(ie_action_ind_vals), Q2931_IE_COMPAT_ACTION_IND,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_q2931,
&ett_q2931_ext,
&ett_q2931_ie,
&ett_q2931_ie_ext,
&ett_q2931_nsap,
};
proto_q2931 = proto_register_protocol("Q.2931", "Q.2931", "q2931");
proto_register_field_array (proto_q2931, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("q2931", dissect_q2931, proto_q2931);
}
