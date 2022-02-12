static void
dissect_q933_segmented_message_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len != 2) {
proto_tree_add_expert_format(tree, pinfo, &ei_q933_invalid_length, tvb, offset, len, "Segmented message: length is %d, should be 2", len);
return;
}
octet = tvb_get_guint8(tvb, offset);
if (octet & 0x80) {
proto_tree_add_uint_format_value(tree, hf_q933_first_segment, tvb, offset, 1,
octet & 0x7F, "%u segments remaining", octet & 0x7F);
} else {
proto_tree_add_uint_format_value(tree, hf_q933_not_first_segment, tvb, offset, 1,
octet & 0x7F, "%u segments remaining", octet & 0x7F);
}
proto_tree_add_item(tree, hf_q933_segmented_message_type, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q933_protocol_discriminator(tvbuff_t *tvb, int offset, proto_tree *tree)
{
unsigned int discriminator = tvb_get_guint8(tvb, offset);
if (discriminator == NLPID_Q_933) {
proto_tree_add_uint_format_value(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Q.933");
} else if (discriminator == NLPID_Q_2931) {
proto_tree_add_uint_format_value(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Q.2931");
} else if ((discriminator >= 16 && discriminator < 63)
|| ((discriminator >= 80) && (discriminator < 254))) {
proto_tree_add_uint_format_value(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Network layer or layer 3 protocol (0x%02X)",
discriminator);
} else if (discriminator >= 64 && discriminator <= 79) {
proto_tree_add_uint_format_value(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"National use (0x%02X)",
discriminator);
} else {
proto_tree_add_uint_format_value(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Reserved (0x%02X)",
discriminator);
}
}
static void
dissect_q933_bearer_capability_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
guint8 uil2_protocol;
guint8 uil3_protocol;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
if (coding_standard != Q933_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q933_data, tvb, offset, len, ENC_NA);
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
return;
}
proto_tree_add_uint(tree, hf_q933_information_transfer_capability, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q933_IE_VL_EXTENSION)) {
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_out_band_negotiation, tvb, offset, 1, ENC_NA);
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_q933_transfer_mode, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x20) {
proto_tree_add_uint(tree, hf_q933_uil1, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q933_layer_1, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_user_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q933_rate_adaption_header, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_multiple_frame_establishment, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_mode_of_operation, tvb, offset, 1, ENC_NA);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q933_stop_bits, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q933_data_bits, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q933_parity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_duplex, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_modem_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
}
l1_done:
;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if ((octet & 0x60) == 0x40) {
uil2_protocol = octet & 0x1F;
proto_tree_add_item(tree, hf_q933_user_information_layer_2_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l2_done;
if (len == 0)
return;
if (uil2_protocol == Q933_UIL2_USER_SPEC) {
proto_tree_add_item(tree, hf_q933_user_specified_layer_2_protocol_information, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_q933_address_inclusion, tvb, offset, 1, ENC_BIG_ENDIAN);
}
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
proto_tree_add_item(tree, hf_q933_user_information_layer_3_protocol, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
switch (uil3_protocol) {
case Q933_UIL3_X25_PL:
case Q933_UIL3_ISO_8208:
case Q933_UIL3_X223:
proto_tree_add_item(tree, hf_q933_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q933_default_packet_size_0F, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_packet_window_size, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case Q933_UIL3_USER_SPEC:
proto_tree_add_uint_format_value(tree, hf_q933_default_packet_size, tvb, offset, 1,
1 << (octet & 0x0F), "%u octets", 1 << (octet & 0x0F));
break;
case Q933_UIL3_TR_9577:
if (octet & Q933_IE_VL_EXTENSION)
goto l3_done;
#if 0
if (len == 0)
return;
#endif
proto_tree_add_item(tree, hf_q933_additional_layer_3_protocol_information, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
}
}
l3_done:
;
}
static void
dissect_q933_cause_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, int hf_cause_value)
{
guint8 octet;
guint8 cause_value;
guint8 coding_standard;
guint8 rejection_reason;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
if (coding_standard != Q933_ITU_STANDARDIZED_CODING) {
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
proto_tree_add_item(tree, hf_q933_data, tvb, offset, len, ENC_NA);
return;
}
proto_tree_add_uint(tree, hf_q933_cause_location, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q933_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q933_recommendation, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
cause_value = octet & 0x7F;
proto_tree_add_uint(tree, hf_cause_value, tvb, offset, 1, cause_value);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (len == 0)
return;
switch (cause_value) {
case Q933_CAUSE_UNALLOC_NUMBER:
case Q933_CAUSE_NO_ROUTE_TO_DEST:
case Q933_CAUSE_QOS_UNAVAILABLE:
proto_tree_add_item(tree, hf_q933_network_service, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_condition_normal, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_condition, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case Q933_CAUSE_CALL_REJECTED:
rejection_reason = octet & 0x7C;
proto_tree_add_item(tree, hf_q933_rejection_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q933_condition, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
switch (rejection_reason) {
case Q933_REJ_USER_SPECIFIC:
proto_tree_add_item(tree, hf_q933_user_specific_diagnostic, tvb, offset, len, ENC_NA);
break;
case Q933_REJ_IE_MISSING:
proto_tree_add_item(tree, hf_q933_missing_information_element, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case Q933_REJ_IE_INSUFFICIENT:
proto_tree_add_item(tree, hf_q933_insufficient_information_element, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_q933_diagnostic, tvb, offset, len, ENC_NA);
break;
}
break;
case Q933_CAUSE_ACCESS_INFO_DISC:
case Q933_CAUSE_INCOMPATIBLE_DEST:
case Q933_CAUSE_MAND_IE_MISSING:
case Q933_CAUSE_IE_NONEX_OR_UNIMPL:
case Q933_CAUSE_INVALID_IE_CONTENTS:
do {
proto_tree_add_item(tree, hf_q933_information_element, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
} while (len != 0);
break;
case Q933_CAUSE_MT_NONEX_OR_UNIMPL:
case Q933_CAUSE_MSG_INCOMPAT_W_CS:
proto_tree_add_item(tree, hf_q933_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case Q933_CAUSE_REC_TIMER_EXP:
if (len < 3)
return;
proto_tree_add_item(tree, hf_q933_timer, tvb, offset, 3, ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_item(tree, hf_q933_diagnostics, tvb, offset, len, ENC_NA);
}
}
static void
dissect_q933_call_state_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q933_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q933_data, tvb, offset, len, ENC_NA);
return;
}
proto_tree_add_item(tree, hf_q933_call_state, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q933_report_type_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 report_type;
if (len == 0)
return;
report_type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_q933_report_type, tvb, offset, 1, report_type);
}
static void
dissect_q933_link_integrity_verf_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 txseq,rxseq;
if (len < 2)
return;
txseq = tvb_get_guint8(tvb, offset);
rxseq = tvb_get_guint8(tvb, offset+1);
proto_tree_add_uint(tree, hf_q933_link_verf_txseq, tvb, offset, 1, txseq);
proto_tree_add_uint(tree, hf_q933_link_verf_rxseq, tvb, offset+1, 1, rxseq);
}
static void
dissect_q933_pvc_status_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint32 dlci;
guint8 dlci_len=2;
if (len < 3)
return;
dlci = ((tvb_get_guint8(tvb, offset) & 0x3F) << 4) |
((tvb_get_guint8(tvb, offset+1) & 0x78) >> 3);
if (len == 4) {
dlci = (dlci << 6) | ((tvb_get_guint8(tvb, offset+2) & 0x7E) >> 1);
dlci_len++;
} else if (len == 5) {
dlci = (dlci << 13) | (tvb_get_guint8(tvb, offset+3) & 0x7F) |
((tvb_get_guint8(tvb, offset+4) & 0x7E) >> 1);
dlci_len+=2;
}
proto_tree_add_uint(tree, hf_q933_dlci, tvb, offset, dlci_len, dlci);
proto_tree_add_item(tree, hf_q933_status, tvb, offset+dlci_len, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q933_channel_identification_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
int identifier_offset;
int identifier_len;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q933_interface_identified, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_interface_basic, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_indicated_channel_required, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_indicated_channel_d_channel, tvb, offset, 1, ENC_NA);
if (octet & Q933_NOT_BASIC_CHANNEL) {
proto_tree_add_item(tree, hf_q933_not_channel_selection, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_q933_channel_selection, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset += 1;
len -= 1;
if (octet & Q933_INTERFACE_IDENTIFIED) {
identifier_offset = offset;
identifier_len = 0;
do {
if (len == 0)
break;
octet = tvb_get_guint8(tvb, offset);
offset += 1;
len -= 1;
identifier_len++;
} while (!(octet & Q933_IE_VL_EXTENSION));
if (identifier_len != 0) {
proto_tree_add_item(tree, hf_q933_interface_identifier, tvb, identifier_offset, identifier_len, ENC_NA);
}
}
if (octet & Q933_NOT_BASIC_CHANNEL) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q933_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q933_data, tvb, offset, len, ENC_NA);
return;
}
proto_tree_add_item(tree, hf_q933_channel_indicated_by, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, (octet & Q933_IS_SLOT_MAP) ? hf_q933_map_element_type : hf_q933_channel_type, tvb, offset, 1, ENC_NA);
}
}
static void
dissect_q933_progress_indicator_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q933_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q933_data, tvb, offset, len, ENC_NA);
return;
}
proto_tree_add_item(tree, hf_q933_location, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_progress_description, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q933_ns_facilities_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
int netid_len;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
netid_len = octet & 0x7F;
proto_tree_add_item(tree, hf_q933_network_identification_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (netid_len != 0) {
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_type_of_network_identification, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q933_network_identification_plan, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
netid_len--;
if (len == 0)
return;
if (netid_len > len)
netid_len = len;
if (netid_len != 0) {
proto_tree_add_item(tree, hf_q933_network_identification, tvb, offset, netid_len, ENC_NA|ENC_ASCII);
offset += netid_len;
len -= netid_len;
}
}
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_network_specific_facility_specification, tvb, offset, len, ENC_NA);
}
static int
dissect_q933_guint16_value(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree, int hf)
{
guint8 octet;
guint16 value;
int value_len;
value_len = 0;
octet = tvb_get_guint8(tvb, offset);
if (octet & Q933_IE_VL_EXTENSION) {
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
if (octet & Q933_IE_VL_EXTENSION) {
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
if (!(octet & Q933_IE_VL_EXTENSION)) {
goto bad_length;
}
value |= (octet & 0x7F);
offset += 1;
value_len++;
proto_tree_add_uint_format_value(tree, hf, tvb, offset, value_len, value, "%u ms", value);
return value_len;
past_end:
proto_tree_add_expert_format(tree, pinfo, &ei_q933_invalid_length, tvb, offset, len,
"%s goes past end of information element", proto_registrar_get_name(hf));
return -1;
bad_length:
proto_tree_add_expert_format(tree, pinfo, &ei_q933_invalid_length, tvb, offset, len,
"%s isn't 3 octets long", proto_registrar_get_name(hf));
return -1;
}
static void
dissect_q933_e2e_transit_delay_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree)
{
int value_len;
if (len == 0)
return;
value_len = dissect_q933_guint16_value(tvb, pinfo, offset, len, tree,
hf_q933_cumulative_transit_delay);
if (value_len < 0)
return;
offset += value_len;
len -= value_len;
if (len == 0)
return;
value_len = dissect_q933_guint16_value(tvb, pinfo, offset, len, tree,
hf_q933_requested_end_to_end_transit_delay);
if (value_len < 0)
return;
offset += value_len;
len -= value_len;
if (len == 0)
return;
dissect_q933_guint16_value(tvb, pinfo, offset, len, tree,
hf_q933_max_end_to_end_transit_delay);
}
static void
dissect_q933_td_selection_and_int_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
dissect_q933_guint16_value(tvb, pinfo, offset, len, tree, hf_q933_transit_delay);
}
static void
dissect_q933_pl_binary_parameters_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_request, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_q933_confirmation, tvb, offset, 1, ENC_NA);
}
static void
dissect_q933_reverse_charge_ind_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_reverse_charging_indication, tvb, offset, 1, ENC_BIG_ENDIAN);
}
static void
dissect_q933_number_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, int hfindex)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_q933_numbering_plan, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q933_number_type, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (!(octet & Q933_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_q933_screening_ind, tvb, offset, 1, octet);
proto_tree_add_uint(tree, hf_q933_presentation_ind, tvb, offset, 1, octet);
proto_tree_add_boolean(tree, hf_q933_extension_ind, tvb, offset, 1, octet);
offset += 1;
len -= 1;
}
if (!(octet & Q933_IE_VL_EXTENSION)) {
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_reason_for_redirection, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
}
if (len == 0)
return;
proto_tree_add_item(tree, hfindex, tvb, offset, len, ENC_ASCII|ENC_NA);
}
static void
dissect_q933_party_subaddr_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_type_of_subaddress, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_q933_odd_even_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_item(tree, hf_q933_subaddress, tvb, offset, len, ENC_NA);
}
static void
dissect_q933_high_layer_compat_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
guint8 characteristics;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
offset += 1;
len -= 1;
if (coding_standard != Q933_ITU_STANDARDIZED_CODING) {
proto_tree_add_item(tree, hf_q933_data, tvb, offset, len, ENC_NA);
return;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
characteristics = octet & 0x7F;
proto_tree_add_item(tree, hf_q933_high_layer_characteristics_identification, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (!(octet & Q933_IE_VL_EXTENSION)) {
if (len == 0)
return;
if (characteristics == Q933_AUDIOVISUAL) {
proto_tree_add_item(tree, hf_q933_extended_audiovisual_characteristics_id, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tree, hf_q933_extended_high_layer_characteristics_id, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_q933_user_user_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_q933_protocol_discriminator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
len -= 1;
if (len == 0)
return;
switch (octet) {
case Q933_PROTOCOL_DISCRIMINATOR_IA5:
proto_tree_add_item(tree, hf_q933_user_information_str, tvb, offset, len, ENC_NA|ENC_ASCII);
break;
default:
proto_tree_add_item(tree, hf_q933_user_information_bytes, tvb, offset, len, ENC_NA);
break;
}
}
static void
dissect_q933_ia5_ie(tvbuff_t *tvb, int offset, int len, proto_tree *tree, int hf)
{
if (len != 0) {
proto_tree_add_item(tree, hf, tvb, offset, len, ENC_ASCII|ENC_NA);
}
}
static int
dissect_q933(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_tree *q933_tree = NULL;
proto_item *ti;
proto_tree *ie_tree = NULL;
guint8 call_ref_len;
guint8 call_ref[16];
guint8 message_type;
guint8 info_element;
guint16 info_element_len;
int codeset, locked_codeset;
gboolean non_locking_shift;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Q.933");
if (tree) {
ti = proto_tree_add_item(tree, proto_q933, tvb, offset, -1,
ENC_NA);
q933_tree = proto_item_add_subtree(ti, ett_q933);
dissect_q933_protocol_discriminator(tvb, offset, q933_tree);
}
offset += 1;
call_ref_len = tvb_get_guint8(tvb, offset) & 0xF;
if (q933_tree != NULL)
proto_tree_add_uint(q933_tree, hf_q933_call_ref_len, tvb, offset, 1, call_ref_len);
offset += 1;
if (call_ref_len != 0) {
tvb_memcpy(tvb, call_ref, offset, call_ref_len);
proto_tree_add_boolean(q933_tree, hf_q933_call_ref_flag,
tvb, offset, 1, (call_ref[0] & 0x80) != 0);
call_ref[0] &= 0x7F;
proto_tree_add_bytes(q933_tree, hf_q933_call_ref,
tvb, offset, call_ref_len, call_ref);
offset += call_ref_len;
}
message_type = tvb_get_guint8(tvb, offset);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(message_type, q933_message_type_vals,
"Unknown message type (0x%02X)"));
proto_tree_add_uint(q933_tree, hf_q933_message_type, tvb, offset, 1, message_type);
offset += 1;
codeset = locked_codeset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
info_element = tvb_get_guint8(tvb, offset);
if ((info_element & Q933_IE_SO_MASK) &&
((info_element & Q933_IE_SO_IDENTIFIER_MASK) == Q933_IE_SHIFT)) {
non_locking_shift = info_element & Q933_IE_SHIFT_NON_LOCKING;
codeset = info_element & Q933_IE_SHIFT_CODESET;
if (!non_locking_shift)
locked_codeset = codeset;
proto_tree_add_item(q933_tree, non_locking_shift ? hf_q933_non_locking_shift_to_codeset : hf_q933_locking_shift_to_codeset, tvb, offset, 1, ENC_NA);
offset += 1;
continue;
}
if (info_element & Q933_IE_SO_MASK) {
switch ((codeset << 8) | (info_element & Q933_IE_SO_IDENTIFIER_MASK)) {
case CS0 | Q933_IE_REPEAT_INDICATOR:
proto_tree_add_item(q933_tree, hf_q933_repeat_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_expert_format(q933_tree, pinfo, &ei_q933_information_element, tvb, offset, 1,
"Unknown information element (0x%02X)", info_element);
break;
}
offset += 1;
codeset = locked_codeset;
continue;
}
info_element_len = tvb_get_guint8(tvb, offset + 1);
if (q933_tree != NULL) {
ie_tree = proto_tree_add_subtree(q933_tree, tvb, offset,
1+1+info_element_len, ett_q933_ie, NULL,
val_to_str(info_element, q933_info_element_vals[codeset],
"Unknown information element (0x%02X)"));
proto_tree_add_uint_format_value(ie_tree, hf_q933_information_element, tvb, offset, 1, info_element,
"%s", val_to_str(info_element, q933_info_element_vals[codeset], "Unknown (0x%02X)"));
proto_tree_add_item(ie_tree, hf_q933_length, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
switch ((codeset << 8) | info_element) {
case CS0 | Q933_IE_SEGMENTED_MESSAGE:
dissect_q933_segmented_message_ie(tvb,
pinfo, offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_BEARER_CAPABILITY:
case CS0 | Q933_IE_LOW_LAYER_COMPAT:
dissect_q933_bearer_capability_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_CAUSE:
dissect_q933_cause_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q933_cause_value);
break;
case CS0 | Q933_IE_CALL_STATE:
dissect_q933_call_state_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_CHANNEL_IDENTIFICATION:
dissect_q933_channel_identification_ie(
tvb, offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_PROGRESS_INDICATOR:
dissect_q933_progress_indicator_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_NETWORK_SPECIFIC_FACIL:
case CS0 | Q933_IE_TRANSIT_NETWORK_SEL:
dissect_q933_ns_facilities_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_DISPLAY:
dissect_q933_ia5_ie(tvb, offset + 2,
info_element_len, ie_tree,
hf_q933_display_information);
break;
case CS0 | Q933_IE_E2E_TRANSIT_DELAY:
dissect_q933_e2e_transit_delay_ie(tvb,
pinfo, offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_TD_SELECTION_AND_INT:
dissect_q933_td_selection_and_int_ie(
tvb, pinfo, offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_PL_BINARY_PARAMETERS:
dissect_q933_pl_binary_parameters_ie(
tvb, offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_REVERSE_CHARGE_IND:
dissect_q933_reverse_charge_ind_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_CALLING_PARTY_NUMBER:
dissect_q933_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q933_calling_party_number);
break;
case CS0 | Q933_IE_CONNECTED_NUMBER:
dissect_q933_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q933_connected_number);
break;
case CS0 | Q933_IE_CALLED_PARTY_NUMBER:
dissect_q933_number_ie(tvb,
offset + 2, info_element_len,
ie_tree,
hf_q933_called_party_number);
break;
case CS0 | Q933_IE_CALLING_PARTY_SUBADDR:
case CS0 | Q933_IE_CALLED_PARTY_SUBADDR:
dissect_q933_party_subaddr_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_HIGH_LAYER_COMPAT:
dissect_q933_high_layer_compat_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_USER_USER:
dissect_q933_user_user_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_REPORT_TYPE:
case CS5 | Q933_IE_REPORT_TYPE:
case CS5 | Q933_IE_ANSI_REPORT_TYPE:
dissect_q933_report_type_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS5 | Q933_IE_LINK_INTEGRITY_VERF:
case CS5 | Q933_IE_ANSI_LINK_INTEGRITY_VERF:
dissect_q933_link_integrity_verf_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS5 | Q933_IE_PVC_STATUS:
case CS5 | Q933_IE_ANSI_PVC_STATUS:
dissect_q933_pvc_status_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
default:
proto_tree_add_item(ie_tree, hf_q933_data, tvb, offset + 2, info_element_len, ENC_NA);
break;
}
}
offset += 1 + 1 + info_element_len;
codeset = locked_codeset;
}
return tvb_captured_length(tvb);
}
void
proto_register_q933(void)
{
static hf_register_info hf[] = {
{ &hf_q933_discriminator,
{ "Protocol discriminator", "q933.disc", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_q933_call_ref_flag,
{ "Call reference flag", "q933.call_ref_flag", FT_BOOLEAN, BASE_NONE, TFS(&tfs_call_ref_flag), 0x0,
NULL, HFILL }},
{ &hf_q933_call_ref,
{ "Call reference value", "q933.call_ref", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q933_coding_standard,
{ "Coding standard", "q933.coding_standard", FT_UINT8, BASE_HEX,
VALS(q933_coding_standard_vals), 0x60,NULL, HFILL }},
{ &hf_q933_information_transfer_capability,
{ "Information transfer capability", "q933.information_transfer_capability", FT_UINT8, BASE_HEX,
VALS(q933_information_transfer_capability_vals), 0x1f,NULL, HFILL }},
{ &hf_q933_transfer_mode,
{ "Transfer mode", "q933.transfer_mode", FT_UINT8, BASE_HEX,
VALS(q933_transfer_mode_vals), 0x60,NULL, HFILL }},
{ &hf_q933_uil1,
{ "User information layer 1 protocol", "q933.uil1", FT_UINT8, BASE_HEX,
VALS(q933_uil1_vals), 0x1f,NULL, HFILL }},
{ &hf_q933_call_ref_len,
{ "Call reference value length", "q933.call_ref_len", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_q933_message_type,
{ "Message type", "q933.message_type", FT_UINT8, BASE_HEX, VALS(q933_message_type_vals), 0x0,
NULL, HFILL }},
{ &hf_q933_cause_location,
{ "Cause location", "q933.cause_location", FT_UINT8, BASE_DEC, VALS(q933_cause_location_vals), 0x0f,
NULL, HFILL }},
{ &hf_q933_cause_value,
{ "Cause value", "q933.cause_value", FT_UINT8, BASE_DEC, VALS(q933_cause_code_vals), 0x7f,
NULL, HFILL }},
{ &hf_q933_number_type,
{ "Number type", "q933.number_type", FT_UINT8, BASE_HEX, VALS(q933_number_type_vals), 0x70,
NULL, HFILL }},
{ &hf_q933_numbering_plan,
{ "numbering plan", "q933.numbering_plan", FT_UINT8, BASE_HEX, VALS(q933_numbering_plan_vals), 0x0f,
NULL, HFILL }},
{ &hf_q933_screening_ind,
{ "Screening indicator", "q933.screening_ind", FT_UINT8, BASE_HEX, VALS(q933_screening_indicator_vals), 0x03,
NULL, HFILL }},
{ &hf_q933_presentation_ind,
{ "Presentation indicator", "q933.presentation_ind", FT_UINT8, BASE_HEX, VALS(q933_presentation_indicator_vals), 0x60,
NULL, HFILL }},
{ &hf_q933_extension_ind,
{ "Extension indicator", "q933.extension_ind",
FT_BOOLEAN, 8, TFS(&q933_extension_ind_value), 0x80,
NULL, HFILL }},
{ &hf_q933_calling_party_number,
{ "Calling party number digits", "q933.calling_party_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q933_called_party_number,
{ "Called party number digits", "q933.called_party_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q933_connected_number,
{ "Connected party number digits", "q933.connected_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#if 0
{ &hf_q933_redirecting_number,
{ "Redirecting party number digits", "q933.redirecting_number.digits", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
#endif
{ &hf_q933_report_type,
{ "Report type", "q933.report_type", FT_UINT8, BASE_DEC, VALS(q933_report_type_vals), 0x0,
NULL, HFILL }},
{ &hf_q933_link_verf_txseq,
{ "TX Sequence", "q933.link_verification.txseq", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_q933_link_verf_rxseq,
{ "RX Sequence", "q933.link_verification.rxseq", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_q933_data,
{ "Data", "q933.data", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_q933_first_segment, { "First segment", "q933.first_segment", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_not_first_segment, { "Not first segment", "q933.not_first_segment", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_segmented_message_type, { "Segmented message type", "q933.segmented_message_type", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_out_band_negotiation, { "Out-band negotiation", "q933.out_band_negotiation", FT_BOOLEAN, 8, TFS(&tfs_possible_not_possible), 0x40, NULL, HFILL }},
{ &hf_q933_layer_1, { "Layer 1", "q933.layer_1", FT_BOOLEAN, 8, TFS(&tfs_asynchronous_synchronous), 0x40, NULL, HFILL }},
{ &hf_q933_user_rate, { "User rate", "q933.user_rate", FT_UINT8, BASE_DEC, VALS(q933_l1_user_rate_vals), 0x1F, NULL, HFILL }},
{ &hf_q933_rate_adaption_header, { "Rate adaption header", "q933.rate_adaption_header", FT_BOOLEAN, 8, TFS(&tfs_included_not_included), 0x40, NULL, HFILL }},
{ &hf_q933_multiple_frame_establishment, { "Multiple frame establishment", "q933.multiple_frame_establishment", FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x20, NULL, HFILL }},
{ &hf_q933_mode_of_operation, { "Mode of operation", "q933.mode_of_operation", FT_BOOLEAN, 8, TFS(&tfs_protocol_sensative_bit_transparent), 0x10, NULL, HFILL }},
{ &hf_q933_stop_bits, { "Stop bits", "q933.stop_bits", FT_UINT8, BASE_DEC, VALS(q933_l1_stop_bits_vals), 0x60, NULL, HFILL }},
{ &hf_q933_data_bits, { "Data bits", "q933.data_bits", FT_UINT8, BASE_DEC, VALS(q933_l1_data_bits_vals), 0x18, NULL, HFILL }},
{ &hf_q933_parity, { "Parity", "q933.parity", FT_UINT8, BASE_DEC, VALS(q933_l1_parity_vals), 0x07, NULL, HFILL }},
{ &hf_q933_duplex, { "Duplex", "q933.duplex", FT_BOOLEAN, 8, TFS(&tfs_full_half), 0x40, NULL, HFILL }},
{ &hf_q933_modem_type, { "Modem type (Network-specific rules)", "q933.modem_type", FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL }},
{ &hf_q933_user_information_layer_2_protocol, { "User information layer 2 protocol", "q933.user_information_layer_2_protocol", FT_UINT8, BASE_HEX, VALS(q933_uil2_vals), 0x1F, NULL, HFILL }},
{ &hf_q933_user_specified_layer_2_protocol_information, { "User-specified layer 2 protocol information", "q933.user_specified_layer_2_protocol_information", FT_UINT8, BASE_HEX, NULL, 0x7F, NULL, HFILL }},
{ &hf_q933_address_inclusion, { "Address inclusion", "q933.address_inclusion", FT_UINT8, BASE_HEX, VALS(q933_address_inclusion_vals), 0x03, NULL, HFILL }},
{ &hf_q933_user_information_layer_3_protocol, { "User information layer 3 protocol", "q933.user_information_layer_3_protocol", FT_UINT8, BASE_HEX, VALS(q933_uil3_vals), 0x1F, NULL, HFILL }},
{ &hf_q933_mode, { "Mode", "q933.mode", FT_UINT8, BASE_HEX, VALS(q933_mode_vals), 0x60, NULL, HFILL }},
{ &hf_q933_default_packet_size_0F, { "Default packet size", "q933.default_packet_size", FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL }},
{ &hf_q933_packet_window_size, { "Packet window size", "q933.packet_window_size", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }},
{ &hf_q933_default_packet_size, { "Default packet size", "q933.default_packet_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_additional_layer_3_protocol_information, { "Additional layer 3 protocol information", "q933.additional_layer_3_protocol_information", FT_UINT16, BASE_HEX, VALS(nlpid_vals), 0x0FF0, NULL, HFILL }},
{ &hf_q933_recommendation, { "Recommendation", "q933.recommendation", FT_UINT8, BASE_HEX, VALS(q933_cause_recommendation_vals), 0x7F, NULL, HFILL }},
{ &hf_q933_network_service, { "Network service", "q933.network_service", FT_BOOLEAN, 8, TFS(&tfs_user_provider), 0x80, NULL, HFILL }},
{ &hf_q933_condition_normal, { "Condition", "q933.condition_normal", FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }},
{ &hf_q933_condition, { "Condition", "q933.condition", FT_UINT8, BASE_HEX, VALS(q933_cause_condition_vals), 0x03, NULL, HFILL }},
{ &hf_q933_rejection_reason, { "Rejection reason", "q933.rejection_reason", FT_UINT8, BASE_HEX, VALS(q933_rejection_reason_vals), 0x7C, NULL, HFILL }},
{ &hf_q933_user_specific_diagnostic, { "User specific diagnostic", "q933.user_specific_diagnostic", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_missing_information_element, { "Missing information element", "q933.missing_information_element", FT_UINT8, BASE_HEX, VALS(q933_info_element_vals0), 0x0, NULL, HFILL }},
{ &hf_q933_insufficient_information_element, { "Insufficient information element", "q933.insufficient_information_element", FT_UINT8, BASE_HEX, VALS(q933_info_element_vals0), 0x0, NULL, HFILL }},
{ &hf_q933_diagnostic, { "Diagnostic", "q933.diagnostic", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_information_element, { "Information element", "q933.information_element", FT_UINT8, BASE_HEX, VALS(q933_info_element_vals0), 0x0, NULL, HFILL }},
{ &hf_q933_timer, { "Timer", "q933.timer", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_call_state, { "Call state", "q933.call_state", FT_UINT8, BASE_HEX, VALS(q933_call_state_vals), 0x3F, NULL, HFILL }},
{ &hf_q933_dlci, { "DLCI", "q933.dlci", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_status, { "Status", "q933.status", FT_UINT8, BASE_DEC, VALS(q933_pvc_status_vals), 0x0A, NULL, HFILL }},
{ &hf_q933_interface_identified, { "Interface", "q933.interface_identified", FT_BOOLEAN, 8, TFS(&tfs_explicitly_implicitly_identified), Q933_INTERFACE_IDENTIFIED, NULL, HFILL }},
{ &hf_q933_interface_basic, { "Interface", "q933.interface_basic", FT_BOOLEAN, 8, TFS(&tfs_not_basic_basic), Q933_NOT_BASIC_CHANNEL, NULL, HFILL }},
{ &hf_q933_indicated_channel_required, { "Indicated channel", "q933.indicated_channel_required", FT_BOOLEAN, 8, TFS(&tfs_required_preferred), 0x08, NULL, HFILL }},
{ &hf_q933_indicated_channel_d_channel, { "Indicated channel", "q933.indicated_channel_d_channel", FT_BOOLEAN, 8, TFS(&tfs_dchannel_not_dchannel), 0x04, NULL, HFILL }},
{ &hf_q933_not_channel_selection, { "Channel selection", "q933.channel_selection", FT_UINT8, BASE_HEX, VALS(q933_not_basic_channel_selection_vals), 0x03, NULL, HFILL }},
{ &hf_q933_channel_selection, { "Channel selection", "q933.channel_selection", FT_UINT8, BASE_HEX, VALS(q933_basic_channel_selection_vals), 0x03, NULL, HFILL }},
{ &hf_q933_interface_identifier, { "Interface identifier", "q933.interface_identifier", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_channel_indicated_by, { "Channel indicated by", "q933.channel_indicated_by", FT_BOOLEAN, 8, TFS(&tfs_slot_map_number), Q933_IS_SLOT_MAP, NULL, HFILL }},
{ &hf_q933_map_element_type, { "Map element type", "q933.map_element_type", FT_UINT8, BASE_HEX, VALS(q933_element_type_vals), 0x0F, NULL, HFILL }},
{ &hf_q933_channel_type, { "Channel", "q933.channel_type", FT_UINT8, BASE_HEX, VALS(q933_element_type_vals), 0x0F, NULL, HFILL }},
{ &hf_q933_location, { "Location", "q933.location", FT_UINT8, BASE_HEX, VALS(q933_cause_location_vals), 0x0F, NULL, HFILL }},
{ &hf_q933_progress_description, { "Progress description", "q933.progress_description", FT_UINT8, BASE_HEX, VALS(q933_progress_description_vals), 0x7F, NULL, HFILL }},
{ &hf_q933_network_identification_length, { "Network identification length", "q933.network_identification_length", FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL }},
{ &hf_q933_type_of_network_identification, { "Type of network identification", "q933.type_of_network_identification", FT_UINT8, BASE_HEX, VALS(q933_netid_type_vals), 0x70, NULL, HFILL }},
{ &hf_q933_network_identification_plan, { "Network identification plan", "q933.network_identification_plan", FT_UINT8, BASE_HEX, VALS(q933_netid_plan_vals), 0x0F, NULL, HFILL }},
{ &hf_q933_network_identification, { "Network identification", "q933.network_identification", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_network_specific_facility_specification, { "Network-specific facility specification", "q933.network_specific_facility_specification", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_confirmation, { "Confirmation", "q933.confirmation", FT_BOOLEAN, 8, TFS(&tfs_link_by_link_end_to_end), 0x02, NULL, HFILL }},
{ &hf_q933_reverse_charging_indication, { "Reverse charging indication", "q933.reverse_charging_indication", FT_UINT8, BASE_HEX, VALS(q933_reverse_charging_indication_vals), 0x07, NULL, HFILL }},
{ &hf_q933_reason_for_redirection, { "Reason for redirection", "q933.reason_for_redirection", FT_UINT8, BASE_HEX, VALS(q933_redirection_reason_vals), 0x0F, NULL, HFILL }},
{ &hf_q933_type_of_subaddress, { "Type of subaddress", "q933.type_of_subaddress", FT_UINT8, BASE_HEX, VALS(q933_subaddress_type_vals), 0x70, NULL, HFILL }},
{ &hf_q933_odd_even_indicator, { "Odd/even indicator", "q933.odd_even_indicator", FT_UINT8, BASE_HEX, VALS(q933_odd_even_indicator_vals), 0x10, NULL, HFILL }},
{ &hf_q933_subaddress, { "Subaddress", "q933.subaddress", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_high_layer_characteristics_identification, { "High layer characteristics identification", "q933.high_layer_characteristics_identification", FT_UINT8, BASE_HEX, VALS(q933_high_layer_characteristics_vals), 0x7F, NULL, HFILL }},
{ &hf_q933_extended_audiovisual_characteristics_id, { "Extended audiovisual characteristics identification", "q933.extended_audiovisual_characteristics_id", FT_UINT8, BASE_HEX, VALS(q933_audiovisual_characteristics_vals), 0x7F, NULL, HFILL }},
{ &hf_q933_extended_high_layer_characteristics_id, { "Extended high layer characteristics identification", "q933.extended_high_layer_characteristics_id", FT_UINT8, BASE_HEX, VALS(q933_high_layer_characteristics_vals), 0x7F, NULL, HFILL }},
{ &hf_q933_protocol_discriminator, { "Protocol discriminator", "q933.protocol_discriminator", FT_UINT8, BASE_HEX, VALS(q933_protocol_discriminator_vals), 0x0, NULL, HFILL }},
{ &hf_q933_user_information_str, { "User information", "q933.user_information_str", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_user_information_bytes, { "User information", "q933.user_information_bytes", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_locking_shift_to_codeset, { "Locking shift to codeset", "q933.locking_shift_to_codeset", FT_UINT8, BASE_DEC, VALS(q933_codeset_vals), Q933_IE_SHIFT_CODESET, NULL, HFILL }},
{ &hf_q933_non_locking_shift_to_codeset, { "Non-locking shift to codeset", "q933.non_locking_shift_to_codeset", FT_UINT8, BASE_DEC, VALS(q933_codeset_vals), Q933_IE_SHIFT_CODESET, NULL, HFILL }},
{ &hf_q933_repeat_indicator, { "Repeat indicator", "q933.repeat_indicator", FT_UINT8, BASE_HEX, VALS(q933_repeat_indication_vals), Q933_IE_SO_IE_MASK, NULL, HFILL }},
{ &hf_q933_length, { "Length", "q933.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_diagnostics, { "Diagnostics", "q933.diagnostics", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_display_information, { "Display information", "q933.display_information", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_cumulative_transit_delay, { "Cumulative transit delay", "q933.cumulative_transit_delay", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_requested_end_to_end_transit_delay, { "Requested end-to-end transit delay", "q933.requested_end_to_end_transit_delay", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_max_end_to_end_transit_delay, { "Maximum end-to-end transit delay", "q933.max_end_to_end_transit_delay", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_transit_delay, { "Transit Delay", "q933.transit_delay", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_q933_request, { "Request", "q933.request", FT_BOOLEAN, 8, TFS(&tfs_no_request_request_indicated), 0x04, NULL, HFILL }},
};
static gint *ett[] = {
&ett_q933,
&ett_q933_ie,
};
static ei_register_info ei[] = {
{ &ei_q933_invalid_length, { "q933.invalid_length", PI_MALFORMED, PI_ERROR, "Invalid length", EXPFILL }},
{ &ei_q933_information_element, { "q933.information_element.unknown", PI_PROTOCOL, PI_WARN, "Unknown information element", EXPFILL }},
};
expert_module_t* expert_q933;
proto_q933 = proto_register_protocol("Q.933", "Q.933", "q933");
proto_register_field_array (proto_q933, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_q933 = expert_register_protocol(proto_q933);
expert_register_field_array(expert_q933, ei, array_length(ei));
register_dissector("q933", dissect_q933, proto_q933);
}
void
proto_reg_handoff_q933(void)
{
dissector_handle_t q933_handle;
q933_handle = find_dissector("q933");
dissector_add_uint("fr.osinl", NLPID_Q_933, q933_handle);
dissector_add_uint("juniper.proto", JUNIPER_PROTO_Q933, q933_handle);
}
