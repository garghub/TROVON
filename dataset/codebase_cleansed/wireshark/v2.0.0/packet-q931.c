static void
dissect_q931_segmented_message_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree, proto_item* item)
{
guint8 octet;
if (len != 2) {
expert_add_info_format(pinfo, item, &ei_q931_invalid_length,
"Segmented message: length is %d, should be 2", len);
return;
}
octet = tvb_get_guint8(tvb, offset);
if (octet & 0x80) {
proto_tree_add_uint_format_value(tree, hf_q931_first_segment, tvb, offset, 1,
octet & 0x7F, "%u segments remaining", octet & 0x7F);
} else {
proto_tree_add_uint_format_value(tree, hf_q931_not_first_segment, tvb, offset, 1,
octet & 0x7F, "%u segments remaining", octet & 0x7F);
}
proto_tree_add_item(tree, hf_q931_segment_type, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_protocol_discriminator(tvbuff_t *tvb, int offset, proto_tree *tree)
{
unsigned int discriminator = tvb_get_guint8(tvb, offset);
if (discriminator == NLPID_DMS) {
proto_tree_add_uint_format_value(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Maintenance messages");
} else if (discriminator == NLPID_Q_931) {
proto_tree_add_uint_format_value(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Q.931");
} else if (discriminator == NLPID_Q_2931) {
proto_tree_add_uint_format_value(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Q.2931");
} else if ((discriminator >= 16 && discriminator < 63)
|| ((discriminator >= 80) && (discriminator < 254))) {
proto_tree_add_uint_format_value(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Network layer or layer 3 protocol (0x%02X)",
discriminator);
} else if (discriminator >= 64 && discriminator <= 79) {
proto_tree_add_uint_format_value(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"National use (0x%02X)",
discriminator);
} else {
proto_tree_add_uint_format_value(tree, hf_q931_discriminator,
tvb, offset, 1, discriminator,
"Reserved (0x%02X)",
discriminator);
}
}
void
dissect_q931_bearer_capability_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
guint8 it_rate;
guint8 uil2_protocol;
guint8 uil3_protocol;
guint8 add_l3_info;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q931_bearer_capability_data, tvb, offset, len, ENC_NA);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
return;
}
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_information_transfer_capability, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_out_band_negotiation, tvb, offset, 1, ENC_NA);
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_transfer_mode, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_information_transfer_rate, tvb, offset, 1, octet);
it_rate = octet & 0x1F;
offset += 1;
len -= 1;
if (it_rate == Q931_IT_RATE_MULTIRATE) {
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_bearer_capability_rate_multiplier, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x20) {
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_layer_ident, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_uil1, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_layer_1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_layer_1_in_band_negotiation, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_bearer_capability_user_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_bearer_capability_intermediate_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_send_data_net_independent_clock, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_accept_data_net_independent_clock, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_send_data_flow_control, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_accept_data_flow_control, tvb, offset, 1, ENC_NA);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_rate_adaption_header, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_multiple_frame_establishment, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_mode_of_operation, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_protocol_negotiation, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_message_originator, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_negotiation_is_done, tvb, offset, 1, ENC_NA);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_bearer_capability_stop_bits, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_bearer_capability_data_bits, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_bearer_capability_parity, tvb, offset, 1, ENC_BIG_ENDIAN);
if (octet & Q931_IE_VL_EXTENSION)
goto l1_done;
proto_tree_add_item(tree, hf_q931_bearer_capability_duplex, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_bearer_capability_modem_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
}
l1_done:
;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x40) {
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_layer_ident, tvb, offset, 1, octet);
uil2_protocol = octet & 0x1F;
proto_tree_add_item(tree, hf_q931_uil2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l2_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if (uil2_protocol == Q931_UIL2_USER_SPEC) {
proto_tree_add_item(tree, hf_q931_uil2_info, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_q931_bearer_capability_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l2_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset) & 0x7F;
proto_tree_add_uint_format_value(tree, hf_q931_bearer_capability_window_size, tvb, offset, 1,
octet, "octet & 0x7F%u k", octet);
offset += 1;
len -= 1;
}
l2_done:
;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x60) {
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_layer_ident, tvb, offset, 1, octet);
uil3_protocol = octet & 0x1F;
proto_tree_add_item(tree, hf_q931_uil3, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
switch (uil3_protocol) {
case Q931_UIL3_X25_PL:
case Q931_UIL3_ISO_8208:
case Q931_UIL3_X223:
proto_tree_add_item(tree, hf_q931_bearer_capability_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_bearer_capability_default_packet_size, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q931_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_bearer_capability_packet_window_size, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case Q931_UIL3_USER_SPEC:
proto_tree_add_uint_format_value(tree, hf_q931_bearer_capability_default_packet_size, tvb, offset, 1,
1 << (octet & 0x0F), "%u octets", 1 << (octet & 0x0F));
break;
case Q931_UIL3_TR_9577:
add_l3_info = (octet & 0x0F) << 4;
if (octet & Q931_IE_VL_EXTENSION)
goto l3_done;
if (len < 2)
return;
octet = tvb_get_guint8(tvb, offset + 1);
add_l3_info |= (octet & 0x0F);
proto_tree_add_uint(tree, hf_q931_uil3_additional, tvb, offset, 2, add_l3_info);
break;
}
}
l3_done:
;
}
static const gchar *get_message_name(guint8 prot_discr, guint8 message_type) {
if (prot_discr == NLPID_DMS)
return val_to_str(message_type, dms_message_type_vals, "Unknown (0x%02X)");
else
return val_to_str_ext(message_type, &q931_message_type_vals_ext, "Unknown (0x%02X)");
}
static void
dissect_q931_cause_ie_unsafe(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, int hf_cause_value, guint8 *cause_value, const value_string *ie_vals)
{
guint8 octet;
guint8 coding_standard;
guint8 rejection_reason;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
if (coding_standard != Q931_ITU_STANDARDIZED_CODING &&
!g931_iso_iec_cause && coding_standard != Q931_ISO_IEC_STANDARDIZED_CODING) {
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
proto_tree_add_item(tree, hf_q931_cause_data, tvb, offset, len, ENC_NA);
return;
}
proto_tree_add_uint(tree, hf_q931_cause_location, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_cause_recommendation, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
*cause_value = octet & 0x7F;
if(have_valid_q931_pi) {
q931_pi->cause_value = *cause_value;
}
proto_tree_add_uint(tree, hf_cause_value, tvb, offset, 1, *cause_value);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (len == 0)
return;
switch (*cause_value) {
case Q931_CAUSE_UNALLOC_NUMBER:
case Q931_CAUSE_NO_ROUTE_TO_DEST:
case Q931_CAUSE_QOS_UNAVAILABLE:
proto_tree_add_item(tree, hf_q931_network_service, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_extension_condition_type, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q931_extension_condition, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case Q931_CAUSE_CALL_REJECTED:
rejection_reason = octet & 0x7C;
proto_tree_add_item(tree, hf_q931_cause_call_rejection_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_cause_call_condition, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
switch (rejection_reason) {
case Q931_REJ_USER_SPECIFIC:
proto_tree_add_item(tree, hf_q931_cause_call_user_specific_diagnostic, tvb, offset, len, ENC_NA);
break;
case Q931_REJ_IE_MISSING:
proto_tree_add_uint_format_value(tree, hf_q931_missing_info_element, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "%s", val_to_str(tvb_get_guint8(tvb, offset), ie_vals,
"Unknown (0x%02X)"));
break;
case Q931_REJ_IE_INSUFFICIENT:
proto_tree_add_uint_format_value(tree, hf_q931_insufficient_info_element, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "%s", val_to_str(tvb_get_guint8(tvb, offset), ie_vals,
"Unknown (0x%02X)"));
break;
default:
proto_tree_add_item(tree, hf_q931_cause_call_diagnostic, tvb, offset, len, ENC_NA);
break;
}
break;
case Q931_CAUSE_ACCESS_INFO_DISC:
case Q931_CAUSE_INCOMPATIBLE_DEST:
case Q931_CAUSE_MAND_IE_MISSING:
case Q931_CAUSE_IE_NONEX_OR_UNIMPL:
case Q931_CAUSE_INVALID_IE_CONTENTS:
do {
proto_tree_add_uint_format_value(tree, hf_q931_information_element, tvb, offset, 1,
tvb_get_guint8(tvb, offset), "%s", val_to_str(tvb_get_guint8(tvb, offset), ie_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
} while (len != 0);
break;
case Q931_CAUSE_MT_NONEX_OR_UNIMPL:
case Q931_CAUSE_MSG_INCOMPAT_W_CS:
proto_tree_add_item(tree, hf_q931_cause_call_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case Q931_CAUSE_REC_TIMER_EXP:
if (len < 3)
return;
proto_tree_add_item(tree, hf_q931_cause_call_rec_timer, tvb, offset, 3, ENC_NA|ENC_ASCII);
break;
default:
proto_tree_add_item(tree, hf_q931_cause_call_diagnostic, tvb, offset, len, ENC_NA);
}
}
void
dissect_q931_cause_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, int hf_cause_value, guint8 *cause_value, const value_string *ie_vals)
{
gboolean have_valid_q931_pi_save = have_valid_q931_pi;
have_valid_q931_pi = FALSE;
dissect_q931_cause_ie_unsafe(tvb, offset, len, tree, hf_cause_value, cause_value, ie_vals);
have_valid_q931_pi = have_valid_q931_pi_save;
}
static void
dissect_q931_change_status_ie(tvbuff_t *tvb, int offset, int len _U_, proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_extension_ind_preference, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_extension_ind_new_status, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_call_state_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q931_call_state_data, tvb, offset, len, ENC_NA);
return;
}
proto_tree_add_item(tree, hf_q931_call_state, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_channel_identification_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_interface_explicit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_interface_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_exclusive, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_dchan, tvb, offset, 1, ENC_BIG_ENDIAN);
if (octet & Q931_NOT_BASIC_CHANNEL) {
proto_tree_add_item(tree, hf_q931_channel_selection_pri, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_q931_channel_selection_bri, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
len -= 1;
if (octet & Q931_INTERFACE_IDENTIFIED) {
guint8 octet2;
guint32 identifier_val = 0;
int identifier_offset = offset;
int identifier_len = 0;
do {
if (len == 0)
break;
octet2 = tvb_get_guint8(tvb, offset);
offset += 1;
len -= 1;
identifier_len++;
identifier_val <<= 7;
identifier_val |= octet2 & 0x7F;
} while (!(octet2 & Q931_IE_VL_EXTENSION));
if (identifier_len != 0) {
proto_tree_add_uint(tree, hf_q931_channel_interface_id, tvb, identifier_offset,
identifier_len, identifier_val);
}
}
if (octet & Q931_NOT_BASIC_CHANNEL) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q931_channel_data, tvb, offset, len, ENC_NA);
return;
}
proto_tree_add_item(tree, hf_q931_channel_map, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_channel_element_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q931_IS_SLOT_MAP) {
while (len) {
proto_tree_add_item(tree, hf_q931_channel_slot_map, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
}
} else {
guint8 octet2;
do {
if (len == 0)
break;
octet2 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree,hf_q931_channel_number,tvb,offset,1,ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
} while (!(octet2 & Q931_IE_VL_EXTENSION));
}
}
}
void
dissect_q931_progress_indicator_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q931_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q931_progress_indicator_data, tvb, offset, len, ENC_NA);
return;
}
proto_tree_add_item(tree, hf_q931_progress_indicator_location, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_progress_indicator_description, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_ns_facilities_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
int netid_len;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
netid_len = octet & 0x7F;
proto_tree_add_item(tree, hf_q931_netid_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (netid_len != 0) {
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_netid_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_netid_plan, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
netid_len--;
if (len == 0)
return;
if (netid_len > len)
netid_len = len;
if (netid_len != 0) {
proto_tree_add_item(tree, hf_q931_netid, tvb, offset, netid_len, ENC_NA|ENC_ASCII);
offset += netid_len;
len -= netid_len;
}
}
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_netid_facility_specification, tvb, offset, len, ENC_NA);
}
static void
dissect_q931_notification_indicator_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_notification_description, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_date_time_ie(tvbuff_t *tvb, packet_info* pinfo, int offset, int len,
proto_tree *tree)
{
if (len == 6) {
proto_tree_add_bytes_format_value(tree, hf_q931_date_time, tvb, offset, 6, NULL, "%02u-%02u-%02u %02u:%02u:%02u",
tvb_get_guint8(tvb, offset + 0), tvb_get_guint8(tvb, offset + 1), tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3), tvb_get_guint8(tvb, offset + 4), tvb_get_guint8(tvb, offset + 5));
} else if (len == 5) {
proto_tree_add_bytes_format_value(tree, hf_q931_date_time, tvb, offset, 5, NULL, "%02u-%02u-%02u %02u:%02u:00",
tvb_get_guint8(tvb, offset + 0), tvb_get_guint8(tvb, offset + 1), tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3), tvb_get_guint8(tvb, offset + 4));
} else {
proto_tree_add_expert_format(tree, pinfo, &ei_q931_date_time, tvb, offset, len, "Date/time: length is %d, should be 5 or 6", len);
}
}
static void
dissect_q931_signal_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree, proto_item* item)
{
if (len != 1) {
expert_add_info_format(pinfo, item, &ei_q931_invalid_length,
"Signal: length is %d, should be 1", len);
return;
}
proto_tree_add_item(tree, hf_q931_signal, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_information_rate_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree, proto_item* item)
{
if (len != 4) {
expert_add_info_format(pinfo, item, &ei_q931_invalid_length,
"Information rate: length is %d, should be 4", len);
return;
}
proto_tree_add_item(tree, hf_q931_information_rate_incoming, tvb, offset + 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_information_rate_outgoing, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_information_rate_minimum_incoming, tvb, offset + 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_information_rate_minimum_outgoing, tvb, offset + 3, 1, ENC_BIG_ENDIAN);
}
static int
dissect_q931_guint16_value(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree, proto_item* item, int hf_value)
{
guint8 octet;
guint16 value;
int value_len;
value_len = 0;
octet = tvb_get_guint8(tvb, offset);
if (octet & Q931_IE_VL_EXTENSION) {
goto bad_length;
}
value = (octet & 0x3) << 14;
offset += 1;
len -= 1;
value_len++;
if (len == 0) {
goto past_end;
}
octet = tvb_get_guint8(tvb, offset);
if (octet & Q931_IE_VL_EXTENSION) {
goto bad_length;
}
value |= (octet & 0x7F) << 7;
offset += 1;
len -= 1;
value_len++;
if (len == 0) {
goto past_end;
}
octet = tvb_get_guint8(tvb, offset);
if (!(octet & Q931_IE_VL_EXTENSION)) {
goto bad_length;
}
value |= (octet & 0x7F);
offset += 1;
value_len++;
proto_tree_add_uint_format_value(tree, hf_value, tvb, offset, value_len, value,
"%u ms", value);
return value_len;
past_end:
expert_add_info_format(pinfo, item, &ei_q931_invalid_length,
"%s goes past end of information element", proto_registrar_get_name(hf_value));
return -1;
bad_length:
expert_add_info_format(pinfo, item, &ei_q931_invalid_length, "%s isn't 3 octets long",
proto_registrar_get_name(hf_value));
return -1;
}
static void
dissect_q931_e2e_transit_delay_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree, proto_item* item)
{
int value_len;
if (len == 0)
return;
value_len = dissect_q931_guint16_value(tvb, pinfo, offset, len, tree, item, hf_q931_cumulative_transit_delay);
if (value_len < 0)
return;
offset += value_len;
len -= value_len;
if (len == 0)
return;
value_len = dissect_q931_guint16_value(tvb, pinfo, offset, len, tree, item, hf_q931_requested_end_to_end_transit_delay);
if (value_len < 0)
return;
offset += value_len;
len -= value_len;
if (len == 0)
return;
dissect_q931_guint16_value(tvb, pinfo, offset, len, tree, item, hf_q931_maximum_end_to_end_transit_delay);
}
static void
dissect_q931_td_selection_and_int_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree, proto_item* item)
{
if (len == 0)
return;
dissect_q931_guint16_value(tvb, pinfo, offset, len, tree, item, hf_q931_transit_delay);
}
static void
dissect_q931_pl_binary_parameters_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
const int * fields[] = {
&hf_q931_fast_select,
&hf_q931_pl_request,
&hf_q931_pl_binary_confirmation,
&hf_q931_pl_modulus,
NULL
};
if (len == 0)
return;
proto_tree_add_bitmask_list(tree, tvb, offset, 1, fields, ENC_NA);
}
static void
dissect_q931_pl_window_size_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_pl_window_size_forward_value, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_pl_window_size_backward_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_packet_size_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_packet_size_forward_value, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_packet_size_backward_value, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_cug_ie(tvbuff_t *tvb, int offset, int len, proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_cug_indication, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_cug_index_code, tvb, offset, len, ENC_NA|ENC_ASCII);
}
static void
dissect_q931_reverse_charge_ind_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_reverse_charging_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_number_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, int hfindex, e164_info_t e164_info)
{
guint8 octet;
gint number_plan;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
number_plan = octet & 0x0f;
e164_info.nature_of_address = ( octet & 0x70 ) >> 4;
proto_tree_add_uint(tree, hf_q931_numbering_plan, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_number_type, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_q931_screening_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_presentation_ind, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q931_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
}
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_extension_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
}
if (len == 0)
return;
proto_tree_add_item(tree, hfindex, tvb, offset, len, ENC_ASCII|ENC_NA);
proto_item_append_text(proto_tree_get_parent(tree), ": '%s'", tvb_format_text(tvb, offset, len));
if ( number_plan == 1 ) {
if ( e164_info.e164_number_type != NONE ){
e164_info.E164_number_str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII|ENC_NA);
e164_info.E164_number_length = len;
dissect_e164_number(tvb, tree, offset, len, e164_info);
}
}
if ( e164_info.e164_number_type == CALLING_PARTY_NUMBER && have_valid_q931_pi)
q931_pi->calling_number = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII|ENC_NA);
if ( e164_info.e164_number_type == CALLED_PARTY_NUMBER && have_valid_q931_pi)
q931_pi->called_number = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, len, ENC_ASCII|ENC_NA);
}
static void
dissect_q931_party_subaddr_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_party_subaddr_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q931_party_subaddr_odd_even_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_party_subaddr, tvb, offset, len, ENC_NA);
}
static void
dissect_q931_restart_indicator_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree, proto_item* item)
{
if (len != 1) {
expert_add_info_format(pinfo, item, &ei_q931_invalid_length,
"Restart indicator: length is %d, should be 1", len);
return;
}
proto_tree_add_item(tree, hf_q931_restart_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
}
void
dissect_q931_high_layer_compat_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
guint8 pres_method;
guint8 characteristics;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
pres_method = octet & 0x03;
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_coding_standard, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_interpretation, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q931_pres_meth_prot_prof, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if ((coding_standard != Q931_ITU_STANDARDIZED_CODING) || (pres_method != Q931_HIGH_LAYER_PROTOCOL_PROFILE)) {
proto_tree_add_item(tree, hf_q931_high_layer_compat_data, tvb, offset, len, ENC_NA);
return;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
characteristics = octet & 0x7F;
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_high_layer_characteristics, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q931_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((characteristics == Q931_AUDIOVISUAL) || (characteristics == 0x61) || (characteristics == 0x62) ||
(characteristics == 0x68)) {
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_extended_audiovisual_characteristics, tvb, offset, 1, octet);
}
else if ((characteristics == Q931_MANAGEMENT) || (characteristics == Q931_MAINTENANCE)) {
proto_tree_add_item(tree, hf_q931_extension_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tree, hf_q931_extended_high_layer_characteristics, tvb, offset, 1, octet);
}
}
}
void
dissect_q931_user_user_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree)
{
guint8 octet;
tvbuff_t *next_tvb = NULL;
heur_dtbl_entry_t *hdtbl_entry;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q931_user_protocol_discriminator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
switch (octet) {
case Q931_PROTOCOL_DISCRIMINATOR_USER:
next_tvb = tvb_new_subset_length(tvb, offset, len);
proto_tree_add_uint_format_value(tree, hf_q931_user_information_len, tvb, offset, len, len, "%d octets", len);
if (!dissector_try_heuristic(q931_user_heur_subdissector_list, next_tvb, pinfo, tree, &hdtbl_entry, NULL)) {
call_dissector_only(data_handle, next_tvb, pinfo, tree, NULL);
}
break;
case Q931_PROTOCOL_DISCRIMINATOR_IA5:
proto_tree_add_item(tree, hf_q931_user_information_str, tvb, offset, len, ENC_NA|ENC_ASCII);
break;
default:
proto_tree_add_item(tree, hf_q931_user_information_bytes, tvb, offset, len, ENC_NA);
break;
}
}
static void
dissect_q931_party_category_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q931_party_category, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q931_ia5_ie(tvbuff_t *tvb, int offset, int len, proto_tree *tree,
int hf_value)
{
if (len != 0) {
proto_tree_add_item(tree, hf_value, tvb, offset, len, ENC_ASCII|ENC_NA);
proto_item_append_text(proto_tree_get_parent(tree), " '%s'", tvb_format_text(tvb, offset, len));
}
}
static void
dissect_q931_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean is_over_ip)
{
int offset = 0;
proto_tree *q931_tree = NULL;
proto_tree *ie_tree = NULL;
proto_item *ti;
guint8 prot_discr;
guint8 call_ref_len;
guint8 call_ref[15];
guint32 call_ref_val;
guint8 message_type, segmented_message_type;
guint8 info_element;
guint16 info_element_len;
gboolean first_frag, more_frags;
guint32 frag_len;
fragment_head *fd_head;
tvbuff_t *next_tvb = NULL;
q931_pi=wmem_new(wmem_packet_scope(), q931_packet_info);
reset_q931_packet_info(q931_pi);
have_valid_q931_pi=TRUE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Q.931");
prot_discr = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(tree, proto_q931, tvb, offset, -1, ENC_NA);
if (tree) {
q931_tree = proto_item_add_subtree(ti, ett_q931);
dissect_q931_protocol_discriminator(tvb, offset, q931_tree);
}
offset += 1;
call_ref_len = tvb_get_guint8(tvb, offset) & 0xF;
if (q931_tree != NULL)
proto_tree_add_uint(q931_tree, hf_q931_call_ref_len, tvb, offset, 1, call_ref_len);
offset += 1;
switch (call_ref_len) {
case 0: call_ref_val = 0; break;
case 1: call_ref_val = tvb_get_guint8(tvb, offset); break;
case 2: call_ref_val = tvb_get_ntohs(tvb, offset); break;
case 3: call_ref_val = tvb_get_ntoh24(tvb, offset); break;
default: call_ref_val = tvb_get_ntohl(tvb, offset);
}
if (call_ref_len != 0) {
tvb_memcpy(tvb, call_ref, offset, call_ref_len);
if (q931_tree != NULL) {
proto_tree_add_boolean(q931_tree, hf_q931_call_ref_flag,
tvb, offset, 1, (call_ref[0] & 0x80) != 0);
call_ref[0] &= 0x7F;
proto_tree_add_bytes(q931_tree, hf_q931_call_ref,
tvb, offset, call_ref_len, call_ref);
} else
{
call_ref[0] &= 0x7F;
}
memcpy(&(q931_pi->crv), call_ref, call_ref_len > sizeof(q931_pi->crv) ? sizeof(q931_pi->crv) : call_ref_len );
offset += call_ref_len;
}
message_type = tvb_get_guint8(tvb, offset);
if(have_valid_q931_pi && q931_pi) {
q931_pi->message_type = message_type;
}
col_add_str(pinfo->cinfo, COL_INFO, get_message_name(prot_discr, message_type));
if (prot_discr == NLPID_DMS)
proto_tree_add_item(q931_tree, hf_q931_maintenance_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(q931_tree, hf_q931_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if ((message_type != Q931_SEGMENT) || !q931_reassembly ||
(tvb_reported_length_remaining(tvb, offset) <= 4)) {
dissect_q931_IEs(tvb, pinfo, tree, q931_tree, is_over_ip, offset, 0);
return;
}
info_element = tvb_get_guint8(tvb, offset);
info_element_len = tvb_get_guint8(tvb, offset + 1);
if ((info_element != Q931_IE_SEGMENTED_MESSAGE) || (info_element_len < 2)) {
dissect_q931_IEs(tvb, pinfo, tree, q931_tree, is_over_ip, offset, 0);
return;
}
ie_tree = proto_tree_add_subtree(q931_tree, tvb, offset, 1+1+info_element_len, ett_q931_ie[info_element], NULL,
val_to_str(info_element, q931_info_element_vals[0], "Unknown information element (0x%02X)"));
proto_tree_add_uint_format_value(ie_tree, hf_q931_information_element, tvb, offset, 1, info_element,
"%s", val_to_str(info_element, q931_info_element_vals[0], "Unknown (0x%02X)"));
proto_tree_add_item(ie_tree, hf_q931_information_element_len, tvb, offset + 1, 1, ENC_NA);
dissect_q931_segmented_message_ie(tvb, pinfo, offset + 2, info_element_len, ie_tree, ti);
first_frag = (tvb_get_guint8(tvb, offset + 2) & 0x80) != 0;
more_frags = (tvb_get_guint8(tvb, offset + 2) & 0x7F) != 0;
segmented_message_type = tvb_get_guint8(tvb, offset + 3);
col_append_fstr(pinfo->cinfo, COL_INFO, " of %s",
val_to_str_ext(segmented_message_type, &q931_message_type_vals_ext, "Unknown message type (0x%02X)"));
offset += 1 + 1 + info_element_len;
frag_len = tvb_reported_length_remaining(tvb, offset);
if (first_frag && fragment_get(&q931_reassembly_table, pinfo, call_ref_val, NULL)) {
fragment_end_seq_next(&q931_reassembly_table, pinfo, call_ref_val, NULL);
}
fd_head = fragment_add_seq_next(&q931_reassembly_table,
tvb, offset, pinfo, call_ref_val, NULL,
frag_len, more_frags);
if (fd_head) {
if (pinfo->fd->num == fd_head->reassembled_in) {
if (fd_head->next != NULL) {
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled Q.931 IEs");
if (tree) {
proto_item *frag_tree_item;
show_fragment_seq_tree(fd_head, &q931_frag_items, q931_tree, pinfo, next_tvb, &frag_tree_item);
}
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s [reassembled]",
val_to_str_ext(segmented_message_type, &q931_message_type_vals_ext, "Unknown message type (0x%02X)"));
} else {
if (tree) proto_tree_add_uint(q931_tree, hf_q931_reassembled_in, tvb, offset, frag_len, fd_head->reassembled_in);
}
}
if (next_tvb)
dissect_q931_IEs(next_tvb, pinfo, tree, q931_tree, is_over_ip, 0, 0);
}
static void
dissect_q931_IEs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *root_tree,
proto_tree *q931_tree, gboolean is_over_ip, int offset, int initial_codeset)
{
proto_item *ti;
proto_tree *ie_tree = NULL;
guint8 info_element;
guint8 dummy;
guint16 info_element_len;
int codeset, locked_codeset;
gboolean non_locking_shift, first_segment;
tvbuff_t *h225_tvb, *next_tvb;
e164_info_t e164_info;
e164_info.e164_number_type = NONE;
e164_info.nature_of_address = NONE;
e164_info.E164_number_str = "";
e164_info.E164_number_length = NONE;
codeset = locked_codeset = initial_codeset;
first_segment = FALSE;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
info_element = tvb_get_guint8(tvb, offset);
if ((info_element & Q931_IE_SO_MASK) &&
((info_element & Q931_IE_SO_IDENTIFIER_MASK) == Q931_IE_SHIFT)) {
non_locking_shift = info_element & Q931_IE_SHIFT_NON_LOCKING;
codeset = info_element & Q931_IE_SHIFT_CODESET;
if (!non_locking_shift)
locked_codeset = codeset;
if (q931_tree != NULL) {
proto_tree_add_uint_format(q931_tree, hf_q931_locking_codeset, tvb, offset, 1,
codeset, "%s shift to codeset %u: %s",
(non_locking_shift ? "Non-locking" : "Locking"),
codeset, val_to_str(codeset, q931_codeset_vals,
"Unknown (0x%02X)"));
}
offset += 1;
continue;
}
if (info_element & Q931_IE_SO_MASK) {
if (dissector_get_uint_handle(codeset_dissector_table, codeset) ||
dissector_get_uint_handle(ie_dissector_table, (codeset << 8) | (info_element & Q931_IE_SO_IDENTIFIER_MASK))) {
next_tvb = tvb_new_subset_length (tvb, offset, 1);
if (dissector_try_uint(ie_dissector_table, (codeset << 8) | (info_element & Q931_IE_SO_IDENTIFIER_MASK), next_tvb, pinfo, q931_tree) ||
dissector_try_uint(codeset_dissector_table, codeset, next_tvb, pinfo, q931_tree)) {
offset += 1;
codeset = locked_codeset;
continue;
}
}
switch ((codeset << 8) | (info_element & Q931_IE_SO_IDENTIFIER_MASK)) {
case CS0 | Q931_IE_MORE_DATA_OR_SEND_COMP:
switch (info_element) {
case Q931_IE_MORE_DATA:
proto_tree_add_item(q931_tree, hf_q931_more_data, tvb, offset, 1, ENC_NA);
break;
case Q931_IE_SENDING_COMPLETE:
proto_tree_add_item(q931_tree, hf_q931_sending_complete, tvb, offset, 1, ENC_NA);
break;
default:
proto_tree_add_expert_format(q931_tree, pinfo, &ei_q931_information_element, tvb, offset, 1,
"Unknown information element (0x%02X)", info_element);
break;
}
break;
case CS0 | Q931_IE_CONGESTION_LEVEL:
proto_tree_add_item(q931_tree, hf_q931_congestion_level, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case CS0 | Q931_IE_REPEAT_INDICATOR:
proto_tree_add_item(q931_tree, hf_q931_repeat_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_expert_format(q931_tree, pinfo, &ei_q931_information_element, tvb, offset, 1,
"Unknown information element (0x%02X)", info_element);
break;
}
offset += 1;
codeset = locked_codeset;
continue;
}
if (is_over_ip && tvb_bytes_exist(tvb, offset, 4) &&
codeset == 0 && tvb_get_guint8(tvb, offset) == Q931_IE_USER_USER &&
tvb_get_guint8(tvb, offset + 3) == Q931_PROTOCOL_DISCRIMINATOR_ASN1) {
info_element_len = tvb_get_ntohs(tvb, offset + 1);
if (q931_tree != NULL) {
ie_tree = proto_tree_add_subtree(q931_tree, tvb, offset,
1+2+info_element_len, ett_q931_ie[info_element], NULL,
val_to_str(info_element,
q931_info_element_vals[codeset],
"Unknown information element (0x%02X)"));
proto_tree_add_uint_format_value(ie_tree, hf_q931_information_element, tvb, offset, 1, info_element, "%s", val_to_str(info_element,
q931_info_element_vals[codeset], "Unknown (0x%02X)"));
proto_tree_add_item(ie_tree, hf_q931_information_element_len, tvb, offset + 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ie_tree, hf_q931_user_protocol_discriminator, tvb, offset + 3, 1, ENC_NA);
}
if (info_element_len > 1) {
if (!pinfo->can_desegment) {
info_element_len = MIN(info_element_len, tvb_captured_length_remaining(tvb, offset + 3));
}
if (h225_handle != NULL) {
h225_tvb = tvb_new_subset_length(tvb,
offset + 4, info_element_len - 1);
call_dissector(h225_handle, h225_tvb,
pinfo, root_tree);
} else {
proto_tree_add_item(ie_tree, hf_q931_user_information_bytes, tvb, offset + 4, info_element_len - 1, ENC_NA);
}
}
offset += 1 + 2 + info_element_len;
} else {
info_element_len = tvb_get_guint8(tvb, offset + 1);
if (first_segment && (tvb_reported_length_remaining(tvb, offset + 2) < info_element_len)) {
proto_tree_add_expert(q931_tree, pinfo, &ei_q931_incomplete_ie, tvb, offset, -1);
break;
}
if (dissector_get_uint_handle(codeset_dissector_table, codeset) ||
dissector_get_uint_handle(ie_dissector_table, (codeset << 8) | info_element)) {
next_tvb = tvb_new_subset_length (tvb, offset, info_element_len + 2);
if (dissector_try_uint(ie_dissector_table, (codeset << 8) | info_element, next_tvb, pinfo, q931_tree) ||
dissector_try_uint(codeset_dissector_table, codeset, next_tvb, pinfo, q931_tree)) {
offset += 2 + info_element_len;
codeset = locked_codeset;
continue;
}
}
ie_tree = proto_tree_add_subtree(q931_tree, tvb, offset, 1+1+info_element_len, ett_q931_ie[info_element], &ti,
val_to_str(info_element, q931_info_element_vals[codeset], "Unknown information element (0x%02X)"));
proto_tree_add_uint_format_value(ie_tree, hf_q931_information_element, tvb, offset, 1, info_element, "%s",
val_to_str(info_element, q931_info_element_vals[codeset], "Unknown (0x%02X)"));
proto_tree_add_uint(ie_tree, hf_q931_information_element_len, tvb, offset + 1, 1, info_element_len);
if (((codeset << 8) | info_element) == (CS0 | Q931_IE_SEGMENTED_MESSAGE)) {
dissect_q931_segmented_message_ie(tvb, pinfo, offset + 2, info_element_len, ie_tree, ti);
col_append_fstr(pinfo->cinfo, COL_INFO, " of %s",
val_to_str_ext(tvb_get_guint8(tvb, offset + 3), &q931_message_type_vals_ext, "Unknown message type (0x%02X)"));
if (tvb_get_guint8(tvb, offset + 2) & 0x80) {
first_segment = TRUE;
} else {
proto_tree_add_item(q931_tree, hf_q931_message_segment, tvb, offset + 4, -1, ENC_NA);
info_element_len += tvb_reported_length_remaining(tvb, offset + 4);
}
} else {
switch ((codeset << 8) | info_element) {
case CS0 | Q931_IE_BEARER_CAPABILITY:
case CS0 | Q931_IE_LOW_LAYER_COMPAT:
if (q931_tree != NULL) {
dissect_q931_bearer_capability_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CAUSE:
dissect_q931_cause_ie_unsafe(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_cause_value, &dummy, q931_info_element_vals0);
break;
case CS0 | Q931_IE_CHANGE_STATUS:
if (q931_tree != NULL) {
dissect_q931_change_status_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CALL_STATE:
if (q931_tree != NULL) {
dissect_q931_call_state_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CHANNEL_IDENTIFICATION:
if (q931_tree != NULL) {
dissect_q931_channel_identification_ie(
tvb, offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_PROGRESS_INDICATOR:
if (q931_tree != NULL) {
dissect_q931_progress_indicator_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_NETWORK_SPECIFIC_FACIL:
case CS0 | Q931_IE_TRANSIT_NETWORK_SEL:
if (q931_tree != NULL) {
dissect_q931_ns_facilities_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_NOTIFICATION_INDICATOR:
if (q931_tree != NULL) {
dissect_q931_notification_indicator_ie(
tvb, offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_DISPLAY:
if (q931_tree != NULL) {
dissect_q931_ia5_ie(tvb, offset + 2, info_element_len, ie_tree, hf_q931_display_information);
}
break;
case CS0 | Q931_IE_DATE_TIME:
dissect_q931_date_time_ie(tvb, pinfo,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q931_IE_KEYPAD_FACILITY:
if (q931_tree != NULL) {
dissect_q931_ia5_ie(tvb, offset + 2, info_element_len, ie_tree, hf_q931_keypad_facility);
}
break;
case CS0 | Q931_IE_SIGNAL:
dissect_q931_signal_ie(tvb, pinfo,
offset + 2, info_element_len,
ie_tree, ti);
break;
case CS0 | Q931_IE_INFORMATION_RATE:
dissect_q931_information_rate_ie(tvb, pinfo,
offset + 2, info_element_len,
ie_tree, ti);
break;
case CS0 | Q931_IE_E2E_TRANSIT_DELAY:
dissect_q931_e2e_transit_delay_ie(tvb, pinfo,
offset + 2, info_element_len,
ie_tree, ti);
break;
case CS0 | Q931_IE_TD_SELECTION_AND_INT:
dissect_q931_td_selection_and_int_ie(
tvb, pinfo, offset + 2, info_element_len,
ie_tree, ti);
break;
case CS0 | Q931_IE_PL_BINARY_PARAMETERS:
if (q931_tree != NULL) {
dissect_q931_pl_binary_parameters_ie(
tvb, offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_PL_WINDOW_SIZE:
if (q931_tree != NULL) {
dissect_q931_pl_window_size_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_PACKET_SIZE:
if (q931_tree != NULL) {
dissect_q931_packet_size_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CUG:
if (q931_tree != NULL) {
dissect_q931_cug_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_REVERSE_CHARGE_IND:
if (q931_tree != NULL) {
dissect_q931_reverse_charge_ind_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_CONNECTED_NUMBER_DEFAULT:
if (q931_tree != NULL) {
dissect_q931_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_connected_number, e164_info);
}
break;
case CS0 | Q931_IE_CALLING_PARTY_NUMBER:
e164_info.e164_number_type = CALLING_PARTY_NUMBER;
dissect_q931_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_calling_party_number, e164_info);
break;
case CS0 | Q931_IE_CALLED_PARTY_NUMBER:
e164_info.e164_number_type = CALLED_PARTY_NUMBER;
dissect_q931_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_called_party_number, e164_info);
break;
case CS0 | Q931_IE_CALLING_PARTY_SUBADDR:
case CS0 | Q931_IE_CALLED_PARTY_SUBADDR:
if (q931_tree != NULL) {
dissect_q931_party_subaddr_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_REDIRECTING_NUMBER:
if (q931_tree != NULL) {
dissect_q931_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q931_redirecting_number, e164_info);
}
break;
case CS0 | Q931_IE_RESTART_INDICATOR:
dissect_q931_restart_indicator_ie(tvb, pinfo,
offset + 2, info_element_len,
ie_tree, ti);
break;
case CS0 | Q931_IE_HIGH_LAYER_COMPAT:
if (q931_tree != NULL) {
dissect_q931_high_layer_compat_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS0 | Q931_IE_USER_USER:
if (q931_tree != NULL) {
dissect_q931_user_user_ie(tvb, pinfo,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS5 | Q931_IE_PARTY_CATEGORY:
if (q931_tree != NULL) {
dissect_q931_party_category_ie(tvb,
offset + 2, info_element_len,
ie_tree);
}
break;
case CS6 | Q931_IE_DISPLAY:
if (q931_tree != NULL) {
dissect_q931_ia5_ie(tvb, offset + 2, info_element_len, ie_tree, hf_q931_avaya_display);
}
break;
default:
if (q931_tree != NULL) {
proto_tree_add_item(ie_tree, hf_q931_data, tvb,
offset + 2, info_element_len, ENC_NA);
}
break;
}
}
offset += 1 + 1 + info_element_len;
}
codeset = locked_codeset;
}
if(have_valid_q931_pi) {
tap_queue_packet(q931_tap, pinfo, q931_pi);
}
have_valid_q931_pi=FALSE;
}
static gboolean
dissect_q931_tpkt_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int lv_tpkt_len;
lv_tpkt_len = is_tpkt(tvb, 3);
if (lv_tpkt_len == -1) {
return FALSE;
}
if (tvb_reported_length(tvb) == 4) {
dissect_tpkt_encap(tvb, pinfo, tree, q931_desegment,
q931_tpkt_pdu_handle);
return TRUE;
}
if (!tvb_bytes_exist(tvb, 4, 3))
return FALSE;
if ((tvb_get_guint8(tvb, 4) != NLPID_Q_931) && (tvb_get_guint8(tvb, 4) != 0x03)) {
return FALSE;
}
dissect_tpkt_encap(tvb, pinfo, tree, q931_desegment,
q931_tpkt_pdu_handle);
return TRUE;
}
static void
dissect_q931_tpkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_tpkt_heur(tvb, pinfo, tree, NULL);
}
static void
dissect_q931_tpkt_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_pdu(tvb, pinfo, tree, TRUE);
}
static void
dissect_q931(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_pdu(tvb, pinfo, tree, FALSE);
}
static void
dissect_q931_over_ip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_pdu(tvb, pinfo, tree, TRUE);
}
static void
dissect_q931_ie_cs0(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_IEs(tvb, pinfo, NULL, tree, FALSE, 0, 0);
}
static void
dissect_q931_ie_cs7(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_q931_IEs(tvb, pinfo, NULL, tree, FALSE, 0, 7);
}
static void
q931_init(void) {
reassembly_table_init(&q931_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
q931_cleanup(void) {
reassembly_table_destroy(&q931_reassembly_table);
}
void
proto_register_q931(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] = {
{ &hf_q931_discriminator,
{ "Protocol discriminator", "q931.disc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_call_ref_len,
{ "Call reference value length", "q931.call_ref_len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_call_ref_flag,
{ "Call reference flag", "q931.call_ref_flag", FT_BOOLEAN, BASE_NONE, TFS(&tfs_call_ref_flag), 0x0,
NULL, HFILL }},
{ &hf_q931_call_ref,
{ "Call reference value", "q931.call_ref", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_message_type,
{ "Message type", "q931.message_type", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_message_type_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_q931_maintenance_message_type,
{ "Maintenance message type", "q931.maintenance_message_type", FT_UINT8, BASE_HEX, VALS(dms_message_type_vals), 0x0,
NULL, HFILL }},
{ &hf_q931_segment_type,
{ "Segmented message type", "q931.segment_type", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_message_type_vals_ext, 0x0,
NULL, HFILL }},
{ &hf_q931_coding_standard,
{ "Coding standard", "q931.coding_standard", FT_UINT8, BASE_HEX,
VALS(q931_coding_standard_vals), 0x60,NULL, HFILL }},
{ &hf_q931_interpretation,
{ "Interpretation", "q931.interpretation", FT_UINT8, BASE_HEX,
VALS(q931_interpretation_vals), 0x1C, NULL, HFILL}},
{ &hf_q931_pres_meth_prot_prof,
{ "Presentation method of protocol profile", "q931.presentation_method_protocol_profile", FT_UINT8, BASE_HEX,
VALS(q931_pres_meth_prot_prof_vals), 0x03, NULL, HFILL}},
{ &hf_q931_high_layer_characteristics,
{ "High layer characteristics identification", "q931.high_layer_characteristics", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&q931_high_layer_characteristics_vals_ext, 0x7f, NULL, HFILL }},
{ &hf_q931_extended_high_layer_characteristics,
{ "Extended high layer characteristics identification", "q931.extended_high_layer_characteristics", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&q931_extended_high_layer_characteristics_vals_ext, 0x7f, NULL, HFILL }},
{ &hf_q931_extended_audiovisual_characteristics,
{ "Extended audiovisual characteristics identification", "q931.extended_audiovisual_characteristics", FT_UINT8, BASE_HEX,
VALS(q931_audiovisual_characteristics_vals), 0x7f, NULL, HFILL }},
{ &hf_q931_information_transfer_capability,
{ "Information transfer capability", "q931.information_transfer_capability", FT_UINT8, BASE_HEX,
VALS(q931_information_transfer_capability_vals), 0x1f,NULL, HFILL }},
{ &hf_q931_transfer_mode,
{ "Transfer mode", "q931.transfer_mode", FT_UINT8, BASE_HEX,
VALS(q931_transfer_mode_vals), 0x60,NULL, HFILL }},
{ &hf_q931_information_transfer_rate,
{ "Information transfer rate", "q931.information_transfer_rate", FT_UINT8, BASE_HEX,
VALS(q931_information_transfer_rate_vals), 0x1f,NULL, HFILL }},
{ &hf_q931_layer_ident,
{ "Layer identification", "q931.layer_ident", FT_UINT8, BASE_HEX,
VALS(q931_bearer_capability_layer_ident_vals), 0x60, NULL, HFILL }},
{ &hf_q931_uil1,
{ "User information layer 1 protocol", "q931.uil1", FT_UINT8, BASE_HEX|BASE_EXT_STRING,
&q931_uil1_vals_ext, 0x1f,NULL, HFILL }},
{ &hf_q931_cause_location,
{ "Cause location", "q931.cause_location", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q931_cause_location_vals_ext, 0x0f,
NULL, HFILL }},
{ &hf_q931_cause_value,
{ "Cause value", "q931.cause_value", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &q931_cause_code_vals_ext, 0x7f,
NULL, HFILL }},
{ &hf_q931_number_type,
{ "Number type", "q931.number_type", FT_UINT8, BASE_HEX, VALS(q931_number_type_vals), 0x70,
NULL, HFILL }},
{ &hf_q931_numbering_plan,
{ "Numbering plan", "q931.numbering_plan", FT_UINT8, BASE_HEX, VALS(q931_numbering_plan_vals), 0x0f,
NULL, HFILL }},
{ &hf_q931_screening_ind,
{ "Screening indicator", "q931.screening_ind", FT_UINT8, BASE_HEX, VALS(q931_screening_indicator_vals), 0x03,
NULL, HFILL }},
{ &hf_q931_presentation_ind,
{ "Presentation indicator", "q931.presentation_ind", FT_UINT8, BASE_HEX, VALS(q931_presentation_indicator_vals), 0x60,
NULL, HFILL }},
{ &hf_q931_extension_ind,
{ "Extension indicator", "q931.extension_ind",
FT_BOOLEAN, 8, TFS(&q931_extension_ind_value), 0x80,
NULL, HFILL }},
{ &hf_q931_extension_ind_preference,
{ "Preference", "q931.extension_ind_preference",
FT_UINT8, BASE_DEC, VALS(q931_status_preference_vals), 0x40,
NULL, HFILL }},
{ &hf_q931_extension_ind_new_status,
{ "New status", "q931.extension_ind_new_status",
FT_UINT8, BASE_DEC, VALS(q931_new_status_vals), 0x07,
NULL, HFILL }},
{ &hf_q931_calling_party_number,
{ "Calling party number digits", "q931.calling_party_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_called_party_number,
{ "Called party number digits", "q931.called_party_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_connected_number,
{ "Connected party number digits", "q931.connected_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_redirecting_number,
{ "Redirecting party number digits", "q931.redirecting_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_channel_interface_explicit,
{ "Interface identifier present", "q931.channel.interface_id_present", FT_BOOLEAN, 8, NULL, 0x40,
"True if the interface identifier is explicit in the following octets", HFILL }},
{ &hf_q931_channel_interface_type,
{ "Interface type", "q931.channel.interface_type", FT_BOOLEAN, 8, TFS(&tfs_interface_type), 0x20,
"Identifies the ISDN interface type", HFILL }},
{ &hf_q931_channel_exclusive,
{ "Indicated channel", "q931.channel.exclusive", FT_BOOLEAN, 8, TFS(&tfs_channel_exclusive), 0x08,
"True if only the indicated channel is acceptable", HFILL }},
{ &hf_q931_channel_dchan,
{ "D-channel indicator", "q931.channel.dchan", FT_BOOLEAN, 8, NULL, 0x04,
"True if the identified channel is the D-Channel", HFILL }},
{ &hf_q931_channel_selection_bri,
{ "Information channel selection", "q931.channel.selection", FT_UINT8, BASE_HEX, VALS(q931_basic_channel_selection_vals), 0x03,
"Identifies the information channel to be used", HFILL }},
{ &hf_q931_channel_selection_pri,
{ "Information channel selection", "q931.channel.selection", FT_UINT8, BASE_HEX, VALS(q931_not_basic_channel_selection_vals), 0x03,
"Identifies the information channel to be used", HFILL }},
{ &hf_q931_channel_map,
{ "Number/map", "q931.channel.map", FT_BOOLEAN, 8, TFS(&tfs_channel_map), 0x10,
"True if channel is indicates by channel map rather than number", HFILL }},
{ &hf_q931_channel_element_type,
{ "Element type", "q931.channel.element_type", FT_UINT8, BASE_HEX, VALS(q931_element_type_vals), 0xF,
"Type of element in the channel number/slot map octets", HFILL }},
{ &hf_q931_channel_number,
{ "Channel number", "q931.channel.number", FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_q931_segment_overlap,
{ "Segment overlap", "q931.segment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_q931_segment_overlap_conflict,
{ "Conflicting data in fragment overlap", "q931.segment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_q931_segment_multiple_tails,
{ "Multiple tail fragments found", "q931.segment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_q931_segment_too_long_segment,
{ "Segment too long", "q931.segment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Segment contained data past end of packet", HFILL }},
{ &hf_q931_segment_error,
{ "Defragmentation error", "q931.segment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_q931_segment_count,
{ "Segment count", "q931.segment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_q931_segment,
{ "Q.931 Segment", "q931.segment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_segments,
{ "Q.931 Segments", "q931.segments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q931_reassembled_in,
{ "Reassembled Q.931 in frame", "q931.reassembled_in", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This Q.931 message is reassembled in this frame", HFILL}},
{ &hf_q931_reassembled_length,
{ "Reassembled Q.931 length", "q931.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL}},
{ &hf_q931_first_segment,
{ "First segment", "q931.segment.first",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_not_first_segment,
{ "Not first segment", "q931.segment.not_first",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_data,
{ "Data", "q931.bearer_capability.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_rate_multiplier,
{ "Rate multiplier", "q931.bearer_capability.rate_multiplier",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_user_rate,
{ "User rate", "q931.bearer_capability.user_rate",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_l1_user_rate_vals_ext, 0x1F,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_intermediate_rate,
{ "Intermediate rate", "q931.bearer_capability.intermediate_rate",
FT_UINT8, BASE_HEX, VALS(q931_l1_intermediate_rate_vals), 0x60,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_stop_bits,
{ "Stop bits", "q931.bearer_capability.stop_bits",
FT_UINT8, BASE_HEX, VALS(q931_l1_stop_bits_vals), 0x60,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_data_bits,
{ "Data bits", "q931.bearer_capability.data_bits",
FT_UINT8, BASE_HEX, VALS(q931_l1_data_bits_vals), 0x18,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_parity,
{ "Parity", "q931.bearer_capability.parity",
FT_UINT8, BASE_HEX, VALS(q931_l1_parity_vals), 0x07,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_modem_type,
{ "Modem type", "q931.bearer_capability.modem_type",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(q931_l1_modem_type_rvals), 0x3F,
NULL, HFILL }
},
{ &hf_q931_uil2,
{ "User information layer 2 protocol", "q931.uil2",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_uil2_vals_ext, 0x1F,
NULL, HFILL }
},
{ &hf_q931_uil2_info,
{ "User-specified layer 2 protocol information", "q931.uil2_info",
FT_UINT8, BASE_HEX, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_mode,
{ "Mode", "q931.bearer_capability.mode",
FT_UINT8, BASE_HEX, VALS(q931_mode_vals), 0x60,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_window_size,
{ "Window size", "q931.bearer_capability.window_size",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_uil3,
{ "User information layer 3 protocol", "q931.uil3",
FT_UINT8, BASE_HEX, VALS(q931_uil3_vals), 0x1F,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_default_packet_size,
{ "Default packet size", "q931.bearer_capability.default_packet_size",
FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_packet_window_size,
{ "Packet window size", "q931.bearer_capability.packet_window_size",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_uil3_additional,
{ "Additional layer 3 protocol information", "q931.uil3_additional",
FT_UINT16, BASE_HEX, VALS(nlpid_vals), 0x0,
NULL, HFILL }
},
{ &hf_q931_cause_data,
{ "Data", "q931.cause.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_cause_recommendation,
{ "Recommendation", "q931.cause.recommendation",
FT_UINT8, BASE_HEX, VALS(q931_cause_recommendation_vals), 0x7F,
NULL, HFILL }
},
{ &hf_q931_cause_call_rejection_reason,
{ "Rejection reason", "q931.cause_call.rejection_reason",
FT_UINT8, BASE_HEX, VALS(q931_rejection_reason_vals), 0x7C,
NULL, HFILL }
},
{ &hf_q931_cause_call_condition,
{ "Condition", "q931.cause_call.condition",
FT_UINT8, BASE_HEX, VALS(q931_cause_condition_vals), 0x03,
NULL, HFILL }
},
{ &hf_q931_cause_call_user_specific_diagnostic,
{ "User specific diagnostic", "q931.cause_call.user_specific_diagnostic",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_cause_call_diagnostic,
{ "Diagnostic", "q931.cause_call.diagnostic",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_cause_call_message_type,
{ "Message type", "q931.cause_call.message_type",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_message_type_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_q931_cause_call_rec_timer,
{ "Timer", "q931.cause_call.rec_timer",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_call_state_data,
{ "Data", "q931.call_state.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_call_state,
{ "Call state", "q931.call_state",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_call_state_vals_ext, 0x3F,
NULL, HFILL }
},
{ &hf_q931_channel_interface_id,
{ "Interface ID", "q931.channel.interface_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_channel_data,
{ "Data", "q931.channel.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_channel_slot_map,
{ "Slot map", "q931.channel.slot_map",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_progress_indicator_data,
{ "Data", "q931.progress_indicator.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_progress_indicator_location,
{ "Location", "q931.progress_indicator.location",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_cause_location_vals_ext, 0x0F,
NULL, HFILL }
},
{ &hf_q931_progress_indicator_description,
{ "Progress description", "q931.progress_indicator.description",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_progress_description_vals_ext, 0x7F,
NULL, HFILL }
},
{ &hf_q931_netid_length,
{ "Network identification length", "q931.netid.length",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_netid_type,
{ "Type of network identification", "q931.netid.type",
FT_UINT8, BASE_HEX, VALS(q931_netid_type_vals), 0x70,
NULL, HFILL }
},
{ &hf_q931_netid_plan,
{ "Network identification plan", "q931.netid.plan",
FT_UINT8, BASE_HEX, VALS(q931_netid_plan_vals), 0x0F,
NULL, HFILL }
},
{ &hf_q931_netid,
{ "Network identification", "q931.netid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_netid_facility_specification,
{ "Network-specific facility specification", "q931.netid.facility_specification",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_notification_description,
{ "Notification description", "q931.notification_description",
FT_UINT8, BASE_HEX, VALS(q931_notification_description_vals), 0x7F,
NULL, HFILL }
},
{ &hf_q931_signal,
{ "Signal", "q931.signal",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_signal_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_q931_information_rate_incoming,
{ "Incoming information rate", "q931.information_rate.incoming",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_throughput_class_vals_ext, 0x1F,
NULL, HFILL }
},
{ &hf_q931_information_rate_outgoing,
{ "Outgoing information rate", "q931.information_rate.outgoing",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_throughput_class_vals_ext, 0x1F,
NULL, HFILL }
},
{ &hf_q931_information_rate_minimum_incoming,
{ "Minimum incoming information rate", "q931.information_rate.minimum_incoming",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_throughput_class_vals_ext, 0x1F,
NULL, HFILL }
},
{ &hf_q931_information_rate_minimum_outgoing,
{ "Minimum outgoing information rate", "q931.information_rate.minimum_outgoing",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_throughput_class_vals_ext, 0x1F,
NULL, HFILL }
},
{ &hf_q931_fast_select,
{ "Fast select", "q931.fast_select",
FT_UINT8, BASE_HEX, VALS(q931_fast_selected_vals), 0x18,
NULL, HFILL }
},
{ &hf_q931_pl_window_size_forward_value,
{ "Forward value", "q931.pl_window_size.forward_value",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_pl_window_size_backward_value,
{ "Backward value", "q931.pl_window_size.backward_value",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_packet_size_forward_value,
{ "Forward value", "q931.packet_size.forward_value",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_packet_size_backward_value,
{ "Backward value", "q931.packet_size.backward_value",
FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }
},
{ &hf_q931_cug_indication,
{ "CUG indication", "q931.cug_indication",
FT_UINT8, BASE_HEX, VALS(q931_cug_indication_vals), 0x07,
NULL, HFILL }
},
{ &hf_q931_cug_index_code,
{ "CUG index code", "q931.cug_index_code",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_reverse_charging_ind,
{ "Reverse charging indication", "q931.reverse_charging_ind",
FT_UINT8, BASE_HEX, VALS(q931_reverse_charging_indication_vals), 0x07,
NULL, HFILL }
},
{ &hf_q931_extension_reason,
{ "Reason for redirection", "q931.extension.reason",
FT_UINT8, BASE_HEX, VALS(q931_redirection_reason_vals), 0x0F,
NULL, HFILL }
},
{ &hf_q931_party_subaddr_type,
{ "Type of subaddress", "q931.party_subaddr.type",
FT_UINT8, BASE_HEX, VALS(q931_subaddress_type_vals), 0x70,
NULL, HFILL }
},
{ &hf_q931_party_subaddr_odd_even_indicator,
{ "Odd/even indicator", "q931.party_subaddr.odd_even",
FT_UINT8, BASE_HEX, VALS(q931_odd_even_indicator_vals), 0x08,
NULL, HFILL }
},
{ &hf_q931_party_subaddr,
{ "Subaddress", "q931.party_subaddr",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_restart_indicator,
{ "Restart indicator", "q931.restart_indicator",
FT_UINT8, BASE_HEX, VALS(q931_restart_indicator_class_vals), 0x07,
NULL, HFILL }
},
{ &hf_q931_high_layer_compat_data,
{ "Data", "q931.high_layer_compat.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_user_protocol_discriminator,
{ "Protocol discriminator", "q931.user.protocol_discriminator",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &q931_protocol_discriminator_vals_ext, 0x0,
NULL, HFILL }
},
{ &hf_q931_user_information_len,
{ "User information", "q931.user.len",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_user_information_str,
{ "User information", "q931.user.string",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_user_information_bytes,
{ "User information", "q931.user.bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_party_category,
{ "Party category", "q931.party_category",
FT_UINT8, BASE_HEX, VALS(q931_party_category_vals), 0x07,
NULL, HFILL }
},
{ &hf_q931_congestion_level,
{ "Congestion level", "q931.congestion_level",
FT_UINT8, BASE_HEX, VALS(q931_congestion_level_vals), Q931_IE_SO_IE_MASK,
NULL, HFILL }
},
{ &hf_q931_repeat_indicator,
{ "Repeat indicator", "q931.repeat_indicator",
FT_UINT8, BASE_HEX, VALS(q931_repeat_indication_vals), Q931_IE_SO_IE_MASK,
NULL, HFILL }
},
{ &hf_q931_out_band_negotiation,
{ "Out-band negotiation", "q931.out_band_negotiation",
FT_BOOLEAN, 8, TFS(&tfs_possible_not_possible), 0x40,
NULL, HFILL }
},
{ &hf_q931_layer_1,
{ "Layer 1", "q931.layer_1",
FT_BOOLEAN, 8, TFS(&tfs_asynchronous_synchronous), 0x40,
NULL, HFILL }
},
{ &hf_q931_layer_1_in_band_negotiation,
{ "Layer 1 in-band negotiation", "q931.layer_1_in_band_negotiation",
FT_BOOLEAN, 8, TFS(&tfs_possible_not_possible), 0x20,
NULL, HFILL }
},
{ &hf_q931_send_data_net_independent_clock,
{ "Send data with network independent clock", "q931.send_data_net_independent_clock",
FT_BOOLEAN, 8, TFS(&tfs_required_not_required), 0x10,
NULL, HFILL }
},
{ &hf_q931_accept_data_net_independent_clock,
{ "Accept data with network independent clock", "q931.accept_data_net_independent_clock",
FT_BOOLEAN, 8, TFS(&tfs_accepted_not_accepted), 0x08,
NULL, HFILL }
},
{ &hf_q931_send_data_flow_control,
{ "Send data with flow control mechanism", "q931.send_data_flow_control",
FT_BOOLEAN, 8, TFS(&tfs_required_not_required), 0x04,
NULL, HFILL }
},
{ &hf_q931_accept_data_flow_control,
{ "Accept data with flow control mechanism", "q931.accept_data_flow_control",
FT_BOOLEAN, 8, TFS(&tfs_accepted_not_accepted), 0x2,
NULL, HFILL }
},
{ &hf_q931_rate_adaption_header,
{ "Rate adaption header", "q931.rate_adaption_header",
FT_BOOLEAN, 8, TFS(&tfs_present_not_present), 0x40,
NULL, HFILL }
},
{ &hf_q931_multiple_frame_establishment,
{ "Multiple frame establishment", "q931.multiple_frame_establishment",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20,
NULL, HFILL }
},
{ &hf_q931_mode_of_operation,
{ "mode of operation", "q931.mode_of_operation",
FT_BOOLEAN, 8, TFS(&tfs_protocol_sensative_bit_transparent), 0x10,
NULL, HFILL }
},
{ &hf_q931_message_originator,
{ "Message originator", "q931.message_originator",
FT_BOOLEAN, 8, TFS(&tfs_assignor_default), 0x04,
NULL, HFILL }
},
{ &hf_q931_negotiation_is_done,
{ "Negotiation is done", "q931.negotiation_is_done",
FT_BOOLEAN, 8, TFS(&tfs_in_out_band), 0x02,
NULL, HFILL }
},
{ &hf_q931_bearer_capability_duplex,
{ "Duplex", "q931.bearer_capability.duplex",
FT_BOOLEAN, 8, TFS(&tfs_full_half), 0x40,
NULL, HFILL }
},
{ &hf_q931_network_service,
{ "Network service", "q931.network_service",
FT_BOOLEAN, 8, TFS(&tfs_user_provider), 0x80,
NULL, HFILL }
},
{ &hf_q931_extension_condition_type,
{ "Type", "q931.extension_condition_type",
FT_BOOLEAN, 8, TFS(&tfs_abnormal_normal), 0x40,
NULL, HFILL }
},
{ &hf_q931_extension_condition,
{ "Condition", "q931.extension_condition",
FT_UINT8, BASE_HEX, VALS(q931_cause_condition_vals), 0x03,
NULL, HFILL }
},
{ &hf_q931_pl_request,
{ "Request", "q931.pl_request",
FT_BOOLEAN, 8, TFS(&tfs_pl_request), 0x04,
NULL, HFILL }
},
{ &hf_q931_pl_binary_confirmation,
{ "Confirmation", "q931.pl_binary_confirmation",
FT_BOOLEAN, 8, TFS(&tfs_link_end), 0x02,
NULL, HFILL }
},
{ &hf_q931_pl_modulus,
{ "Modulus", "q931.pl_modulus",
FT_BOOLEAN, 8, TFS(&tfs_pl_modulus), 0x01,
NULL, HFILL }
},
{ &hf_q931_data,
{ "Data", "q931.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_information_element,
{ "Information element", "q931.information_element",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_information_element_len,
{ "Length", "q931.information_element_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_date_time,
{ "Date/time", "q931.date_time",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_more_data,
{ "More data", "q931.more_data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_sending_complete,
{ "Sending complete", "q931.sending_complete",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_message_segment,
{ "Message segment", "q931.message_segment",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_missing_info_element,
{ "Missing information element", "q931.missing_info_element",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_insufficient_info_element,
{ "Insufficient information element", "q931.insufficient_info_element",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_cumulative_transit_delay,
{ "Cumulative transit delay", "q931.cumulative_transit_delay",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_requested_end_to_end_transit_delay,
{ "Requested end-to-end transit delay", "q931.requested_end_to_end_transit_delay",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_maximum_end_to_end_transit_delay,
{ "Maximum end-to-end transit delay", "q931.maximum_end_to_end_transit_delay",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_transit_delay,
{ "Transit delay", "q931.transit_delay",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_display_information,
{ "Display information", "q931.display_information",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_keypad_facility,
{ "Keypad facility", "q931.keypad_facility",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_avaya_display,
{ "Avaya Display", "q931.avaya_display",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_locking_codeset,
{ "Locking codeset", "q931.locking_codeset",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_q931_protocol_negotiation,
{ "Protocol negotiation", "q931.protocol_negotiation",
FT_BOOLEAN, 8, TFS(&tfs_protocol_negotiation), 0x08,
NULL, HFILL }
},
};
#define NUM_INDIVIDUAL_ELEMS 3
static gint *ett[NUM_INDIVIDUAL_ELEMS + NUM_IE];
static ei_register_info ei[] = {
{ &ei_q931_invalid_length, { "q931.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
{ &ei_q931_date_time, { "q931.date_time.invalid", PI_MALFORMED, PI_ERROR, "Date/time: Invalid length", EXPFILL }},
{ &ei_q931_information_element, { "q931.information_element.unknown", PI_PROTOCOL, PI_WARN, "Unknown information element", EXPFILL }},
{ &ei_q931_incomplete_ie, { "q931.incomplete_ie", PI_MALFORMED, PI_ERROR, "Incomplete IE in the 1st segment", EXPFILL }},
};
module_t *q931_module;
expert_module_t* expert_q931;
ett[0] = &ett_q931;
ett[1] = &ett_q931_segments;
ett[2] = &ett_q931_segment;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_IE; i++, last_offset++)
{
ett_q931_ie[i] = -1;
ett[last_offset] = &ett_q931_ie[i];
}
proto_q931 = proto_register_protocol("Q.931", "Q.931", "q931");
proto_register_field_array (proto_q931, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_q931 = expert_register_protocol(proto_q931);
expert_register_field_array(expert_q931, ei, array_length(ei));
register_init_routine(q931_init);
register_cleanup_routine(q931_cleanup);
q931_handle = register_dissector("q931", dissect_q931, proto_q931);
q931_tpkt_handle = register_dissector("q931.tpkt", dissect_q931_tpkt, proto_q931);
q931_tpkt_pdu_handle = create_dissector_handle(dissect_q931_tpkt_pdu,
proto_q931);
q931_over_ip_handle = register_dissector("q931.over_ip", dissect_q931_over_ip, proto_q931);
register_dissector("q931.ie", dissect_q931_ie_cs0, proto_q931);
register_dissector("q931.ie.cs7", dissect_q931_ie_cs7, proto_q931);
codeset_dissector_table = register_dissector_table("q931.codeset", "Q.931 Codeset", FT_UINT8, BASE_HEX);
ie_dissector_table = register_dissector_table("q931.ie", "Q.931 IE", FT_UINT16, BASE_HEX);
q931_user_heur_subdissector_list = register_heur_dissector_list("q931_user");
q931_module = prefs_register_protocol(proto_q931, NULL);
prefs_register_bool_preference(q931_module, "desegment_h323_messages",
"Reassemble Q.931 messages spanning multiple TCP segments",
"Whether the Q.931 dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&q931_desegment);
prefs_register_bool_preference(q931_module, "reassembly",
"Reassemble segmented Q.931 messages",
"Reassemble segmented Q.931 messages (Q.931 - Annex H)",
&q931_reassembly);
prefs_register_bool_preference(q931_module, "iso_iec_cause_coding",
"Decode ISO/IEC cause coding standard as ITU-T",
"Decode ISO/IEC cause coding standard as ITU-T",
&g931_iso_iec_cause);
q931_tap = register_tap("q931");
}
void
proto_reg_handoff_q931(void)
{
dissector_add_uint("lapd.sapi", LAPD_SAPI_Q931, q931_handle);
dissector_add_uint("sctp.ppi", H323_PAYLOAD_PROTOCOL_ID, q931_over_ip_handle);
h225_handle = find_dissector("h225");
data_handle = find_dissector("data");
heur_dissector_add("tcp", dissect_q931_tpkt_heur, "Q.931 over TPKT over TCP", "q931_tcp", proto_q931, HEURISTIC_ENABLE);
}
static void reset_q931_packet_info(q931_packet_info *pi)
{
if(pi == NULL) {
return;
}
pi->calling_number = NULL;
pi->called_number = NULL;
pi->cause_value = 0xFF;
pi->crv = -1;
}
