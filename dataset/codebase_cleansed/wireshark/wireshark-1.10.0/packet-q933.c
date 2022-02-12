static void
dissect_q933_segmented_message_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len != 2) {
proto_tree_add_text(tree, tvb, offset, len,
"Segmented message: length is %d, should be 2", len);
return;
}
if (tvb_get_guint8(tvb, offset) & 0x80) {
proto_tree_add_text(tree, tvb, offset, 1,
"First segment: %u segments remaining",
tvb_get_guint8(tvb, offset) & 0x7F);
} else {
proto_tree_add_text(tree, tvb, offset, 1,
"Not first segment: %u segments remaining",
tvb_get_guint8(tvb, offset) & 0x7F);
}
proto_tree_add_text(tree, tvb, offset + 1, 1,
"Segmented message type: %u", tvb_get_guint8(tvb, offset + 1));
}
static void
dissect_q933_protocol_discriminator(tvbuff_t *tvb, int offset, proto_tree *tree)
{
unsigned int discriminator = tvb_get_guint8(tvb, offset);
if (discriminator == NLPID_Q_933) {
proto_tree_add_uint_format(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Q.933");
} else if (discriminator == NLPID_Q_2931) {
proto_tree_add_uint_format(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Q.2931");
} else if ((discriminator >= 16 && discriminator < 63)
|| ((discriminator >= 80) && (discriminator < 254))) {
proto_tree_add_uint_format(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Network layer or layer 3 protocol (0x%02X)",
discriminator);
} else if (discriminator >= 64 && discriminator <= 79) {
proto_tree_add_uint_format(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: National use (0x%02X)",
discriminator);
} else {
proto_tree_add_uint_format(tree, hf_q933_discriminator,
tvb, offset, 1, discriminator,
"Protocol discriminator: Reserved (0x%02X)",
discriminator);
}
}
static void
dissect_q933_bearer_capability_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
guint8 coding_standard;
guint8 modem_type;
guint8 uil2_protocol;
guint8 uil3_protocol;
guint8 add_l3_info;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
if (coding_standard != Q933_ITU_STANDARDIZED_CODING) {
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
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
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Out-band negotiation %spossible",
(octet & 0x40) ? "" : "not ");
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
proto_tree_add_text(tree, tvb, offset, 1,
"Layer 1 is %s",
(octet & 0x40) ? "Asynchronous" : "Synchronous");
proto_tree_add_text(tree, tvb, offset, 1,
"User rate: %s",
val_to_str(octet & 0x1F, q933_l1_user_rate_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Rate adaption header %sincluded",
(octet & 0x40) ? "" : "not ");
proto_tree_add_text(tree, tvb, offset, 1,
"Multiple frame establishment %ssupported",
(octet & 0x20) ? "" : "not ");
proto_tree_add_text(tree, tvb, offset, 1,
"%s mode of operation",
(octet & 0x10) ? "Protocol sensitive" : "Bit transparent");
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Stop bits: %s",
val_to_str(octet & 0x60, q933_l1_stop_bits_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Data bits: %s",
val_to_str(octet & 0x18, q933_l1_data_bits_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Parity: %s",
val_to_str(octet & 0x07, q933_l1_parity_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l1_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"%s duplex",
(octet & 0x40) ? "Full" : "Half");
modem_type = octet & 0x3F;
proto_tree_add_text(tree, tvb, offset, 1,
"Modem type: Network-specific rules 0x%02X", modem_type);
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
proto_tree_add_text(tree, tvb, offset, 1,
"User information layer 2 protocol: %s",
val_to_str(uil2_protocol, q933_uil2_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l2_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if (uil2_protocol == Q933_UIL2_USER_SPEC) {
proto_tree_add_text(tree, tvb, offset, 1,
"User-specified layer 2 protocol information: 0x%02X",
octet & 0x7F);
} else {
proto_tree_add_text(tree, tvb, offset, 1,
"Address inclusion: %s",
val_to_str(octet & 0x03, q933_address_inclusion_vals,
"Unknown (0x%02X)"));
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
proto_tree_add_text(tree, tvb, offset, 1,
"User information layer 3 protocol: %s",
val_to_str(uil3_protocol, q933_uil3_vals,
"Unknown (0x%02X)"));
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
proto_tree_add_text(tree, tvb, offset, 1,
"Mode: %s",
val_to_str(octet & 0x60, q933_mode_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Default packet size: %u", octet & 0x0F);
offset += 1;
len -= 1;
if (octet & Q933_IE_VL_EXTENSION)
goto l3_done;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Packet window size: %u", octet & 0x7F);
break;
case Q933_UIL3_USER_SPEC:
proto_tree_add_text(tree, tvb, offset, 1,
"Default packet size: %u octets",
1 << (octet & 0x0F));
break;
case Q933_UIL3_TR_9577:
add_l3_info = (octet & 0x0F) << 4;
if (octet & Q933_IE_VL_EXTENSION)
goto l3_done;
#if 0
if (len == 0)
return;
#endif
octet = tvb_get_guint8(tvb, offset + 1);
add_l3_info |= (octet & 0x0F);
proto_tree_add_text(tree, tvb, offset, 2,
"Additional layer 3 protocol information: %s",
val_to_str(add_l3_info, nlpid_vals,
"Unknown (0x%02X)"));
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
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
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
proto_tree_add_text(tree, tvb, offset, 1,
"Recommendation: %s",
val_to_str(octet & 0x7F, q933_cause_recommendation_vals,
"Unknown (0x%02X)"));
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
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Network service: %s",
(octet & 0x80) ? "User" : "Provider");
proto_tree_add_text(tree, tvb, offset, 1,
"%s",
(octet & 0x40) ? "Abnormal" : "Normal");
proto_tree_add_text(tree, tvb, offset, 1,
"Condition: %s",
val_to_str(octet & 0x03, q933_cause_condition_vals,
"Unknown (0x%X)"));
break;
case Q933_CAUSE_CALL_REJECTED:
rejection_reason = octet & 0x7C;
proto_tree_add_text(tree, tvb, offset, 1,
"Rejection reason: %s",
val_to_str(octet & 0x7C, q933_rejection_reason_vals,
"Unknown (0x%X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Condition: %s",
val_to_str(octet & 0x03, q933_cause_condition_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
switch (rejection_reason) {
case Q933_REJ_USER_SPECIFIC:
proto_tree_add_text(tree, tvb, offset, len,
"User specific diagnostic: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
case Q933_REJ_IE_MISSING:
proto_tree_add_text(tree, tvb, offset, 1,
"Missing information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), q933_info_element_vals0,
"Unknown (0x%02X)"));
break;
case Q933_REJ_IE_INSUFFICIENT:
proto_tree_add_text(tree, tvb, offset, 1,
"Insufficient information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), q933_info_element_vals0,
"Unknown (0x%02X)"));
break;
default:
proto_tree_add_text(tree, tvb, offset, len,
"Diagnostic: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
}
break;
case Q933_CAUSE_ACCESS_INFO_DISC:
case Q933_CAUSE_INCOMPATIBLE_DEST:
case Q933_CAUSE_MAND_IE_MISSING:
case Q933_CAUSE_IE_NONEX_OR_UNIMPL:
case Q933_CAUSE_INVALID_IE_CONTENTS:
do {
proto_tree_add_text(tree, tvb, offset, 1,
"Information element: %s",
val_to_str(tvb_get_guint8(tvb, offset), q933_info_element_vals0,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
} while (len != 0);
break;
case Q933_CAUSE_MT_NONEX_OR_UNIMPL:
case Q933_CAUSE_MSG_INCOMPAT_W_CS:
proto_tree_add_text(tree, tvb, offset, 1,
"Message type: %s",
val_to_str(tvb_get_guint8(tvb, offset), q933_message_type_vals,
"Unknown (0x%02X)"));
break;
case Q933_CAUSE_REC_TIMER_EXP:
if (len < 3)
return;
proto_tree_add_text(tree, tvb, offset, 3,
"Timer: %.3s", tvb_get_ephemeral_string(tvb, offset, 3));
break;
default:
proto_tree_add_text(tree, tvb, offset, len,
"Diagnostics: %s",
tvb_bytes_to_str(tvb, offset, len));
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
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
proto_tree_add_text(tree, tvb, offset, 1,
"Call state: %s",
val_to_str(octet & 0x3F, q933_call_state_vals,
"Unknown (0x%02X)"));
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
guint8 dlci_status,dlci_len=2;
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
dlci_status=tvb_get_guint8(tvb, offset+dlci_len)&0x0a;
proto_tree_add_text(tree, tvb, offset, dlci_len, "DLCI: %u", dlci);
proto_tree_add_text(tree, tvb, offset+dlci_len, 1, "Status: %s",
val_to_str_const(dlci_status, q933_pvc_status_vals, "Unknown"));
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
proto_tree_add_text(tree, tvb, offset, 1,
"Interface %s identified",
(octet & Q933_INTERFACE_IDENTIFIED) ? "explicitly" : "implicitly");
proto_tree_add_text(tree, tvb, offset, 1,
"%s interface",
(octet & Q933_NOT_BASIC_CHANNEL) ? "Not basic" : "Basic");
proto_tree_add_text(tree, tvb, offset, 1,
"Indicated channel is %s",
(octet & 0x08) ? "required" : "preferred");
proto_tree_add_text(tree, tvb, offset, 1,
"Indicated channel is %sthe D-channel",
(octet & 0x04) ? "" : "not ");
if (octet & Q933_NOT_BASIC_CHANNEL) {
proto_tree_add_text(tree, tvb, offset, 1,
"Channel selection: %s",
val_to_str(octet & 0x03, q933_not_basic_channel_selection_vals,
"Unknown (0x%X)"));
} else {
proto_tree_add_text(tree, tvb, offset, 1,
"Channel selection: %s",
val_to_str(octet & 0x03, q933_basic_channel_selection_vals,
"Unknown (0x%X)"));
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
proto_tree_add_text(tree, tvb, identifier_offset,
identifier_len, "Interface identifier: %s",
tvb_bytes_to_str(tvb, identifier_offset, identifier_len));
}
}
if (octet & Q933_NOT_BASIC_CHANNEL) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
coding_standard = octet & 0x60;
proto_tree_add_uint(tree, hf_q933_coding_standard, tvb, offset, 1, octet);
if (coding_standard != Q933_ITU_STANDARDIZED_CODING) {
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
proto_tree_add_text(tree, tvb, offset, 1,
"Channel is indicated by %s",
(octet & Q933_IS_SLOT_MAP) ? "slot map" : "number");
proto_tree_add_text(tree, tvb, offset, 1,
"%s type: %s",
(octet & Q933_IS_SLOT_MAP) ? "Map element" : "Channel",
val_to_str(octet & 0x0F, q933_element_type_vals,
"Unknown (0x%02X)"));
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
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
proto_tree_add_text(tree, tvb, offset, 1,
"Location: %s",
val_to_str(octet & 0x0F, q933_cause_location_vals,
"Unknown (0x%X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Progress description: %s",
val_to_str(octet & 0x7F, q933_progress_description_vals,
"Unknown (0x%02X)"));
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
proto_tree_add_text(tree, tvb, offset, 1,
"Network identification length: %u",
netid_len);
offset += 1;
len -= 1;
if (netid_len != 0) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Type of network identification: %s",
val_to_str(octet & 0x70, q933_netid_type_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Network identification plan: %s",
val_to_str(octet & 0x0F, q933_netid_plan_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
netid_len--;
if (len == 0)
return;
if (netid_len > len)
netid_len = len;
if (netid_len != 0) {
proto_tree_add_text(tree, tvb, offset, netid_len,
"Network identification: %s",
tvb_format_text(tvb, offset, netid_len));
offset += netid_len;
len -= netid_len;
}
}
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset,
len, "Network-specific facility specification: %s",
tvb_bytes_to_str(tvb, offset, len));
}
static int
dissect_q933_guint16_value(tvbuff_t *tvb, int offset, int len,
proto_tree *tree, const char *label)
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
proto_tree_add_text(tree, tvb, offset, value_len, "%s: %u ms", label,
value);
return value_len;
past_end:
proto_tree_add_text(tree, tvb, offset, len,
"%s goes past end of information element", label);
return -1;
bad_length:
proto_tree_add_text(tree, tvb, offset, len, "%s isn't 3 octets long",
label);
return -1;
}
static void
dissect_q933_e2e_transit_delay_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
int value_len;
if (len == 0)
return;
value_len = dissect_q933_guint16_value(tvb, offset, len, tree,
"Cumulative transit delay");
if (value_len < 0)
return;
offset += value_len;
len -= value_len;
if (len == 0)
return;
value_len = dissect_q933_guint16_value(tvb, offset, len, tree,
"Requested end-to-end transit delay");
if (value_len < 0)
return;
offset += value_len;
len -= value_len;
if (len == 0)
return;
dissect_q933_guint16_value(tvb, offset, len, tree,
"Maximum end-to-end transit delay");
}
static void
dissect_q933_td_selection_and_int_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
dissect_q933_guint16_value(tvb, offset, len, tree,
"Transit delay");
}
static void
dissect_q933_pl_binary_parameters_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"%s",
(octet & 0x04) ? "No request/request denied" :
"Request indicated/request accepted");
proto_tree_add_text(tree, tvb, offset, 1,
"%s confirmation",
(octet & 0x02) ? "Link-by-link" : "End-to-end");
}
static void
dissect_q933_reverse_charge_ind_ie(tvbuff_t *tvb, int offset, int len,
proto_tree *tree)
{
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, 1,
"Reverse charging indication: %s",
val_to_str(tvb_get_guint8(tvb, offset) & 0x07,
q933_reverse_charging_indication_vals, "Unknown (0x%02X)"));
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
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Reason for redirection: %s",
val_to_str(octet & 0x0F, q933_redirection_reason_vals,
"Unknown (0x%X)"));
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
guint8 octet;
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text(tree, tvb, offset, 1,
"Type of subaddress: %s",
val_to_str(octet & 0x70, q933_subaddress_type_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(tree, tvb, offset, 1,
"Odd/even indicator: %s",
val_to_str(octet & 0x10, q933_odd_even_indicator_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (len == 0)
return;
proto_tree_add_text(tree, tvb, offset, len, "Subaddress: %s",
tvb_bytes_to_str(tvb, offset, len));
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
proto_tree_add_text(tree, tvb, offset,
len, "Data: %s",
tvb_bytes_to_str(tvb, offset, len));
return;
}
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
characteristics = octet & 0x7F;
proto_tree_add_text(tree, tvb, offset, 1,
"High layer characteristics identification: %s",
val_to_str(characteristics, q933_high_layer_characteristics_vals,
"Unknown (0x%02X)"));
offset += 1;
len -= 1;
if (!(octet & Q933_IE_VL_EXTENSION)) {
if (len == 0)
return;
octet = tvb_get_guint8(tvb, offset);
if (characteristics == Q933_AUDIOVISUAL) {
proto_tree_add_text(tree, tvb, offset, 1,
"Extended audiovisual characteristics identification: %s",
val_to_str(octet & 0x7F,
q933_audiovisual_characteristics_vals,
"Unknown (0x%02X)"));
} else {
proto_tree_add_text(tree, tvb, offset, 1,
"Extended high layer characteristics identification: %s",
val_to_str(octet & 0x7F,
q933_high_layer_characteristics_vals,
"Unknown (0x%02X)"));
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
proto_tree_add_text(tree, tvb, offset, 1,
"Protocol discriminator: %s",
val_to_str(octet, q933_protocol_discriminator_vals,
"Unknown (0x%02x)"));
offset += 1;
len -= 1;
if (len == 0)
return;
switch (octet) {
case Q933_PROTOCOL_DISCRIMINATOR_IA5:
proto_tree_add_text(tree, tvb, offset, len, "User information: %s",
tvb_format_text(tvb, offset, len));
break;
default:
proto_tree_add_text(tree, tvb, offset, len, "User information: %s",
tvb_bytes_to_str(tvb, offset, len));
break;
}
}
static void
dissect_q933_ia5_ie(tvbuff_t *tvb, int offset, int len, proto_tree *tree,
const char *label)
{
if (len != 0) {
proto_tree_add_text(tree, tvb, offset, len, "%s: %s", label,
tvb_format_text(tvb, offset, len));
}
}
static void
dissect_q933(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
proto_tree *q933_tree = NULL;
proto_item *ti;
proto_tree *ie_tree = NULL;
guint8 call_ref_len;
guint8 call_ref[15];
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
if (q933_tree != NULL) {
proto_tree_add_boolean(q933_tree, hf_q933_call_ref_flag,
tvb, offset, 1, (call_ref[0] & 0x80) != 0);
call_ref[0] &= 0x7F;
proto_tree_add_bytes(q933_tree, hf_q933_call_ref,
tvb, offset, call_ref_len, call_ref);
}
offset += call_ref_len;
}
message_type = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(message_type, q933_message_type_vals,
"Unknown message type (0x%02X)"));
}
if (q933_tree != NULL)
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
if (q933_tree != NULL) {
proto_tree_add_text(q933_tree, tvb, offset, 1,
"%s shift to codeset %u: %s",
(non_locking_shift ? "Non-locking" : "Locking"),
codeset,
val_to_str(codeset, q933_codeset_vals,
"Unknown (0x%02X)"));
}
offset += 1;
continue;
}
if (info_element & Q933_IE_SO_MASK) {
switch ((codeset << 8) | (info_element & Q933_IE_SO_IDENTIFIER_MASK)) {
case CS0 | Q933_IE_REPEAT_INDICATOR:
if (q933_tree != NULL) {
proto_tree_add_text(q933_tree, tvb, offset, 1,
"Repeat indicator: %s",
val_to_str(info_element & Q933_IE_SO_IE_MASK,
q933_repeat_indication_vals,
"Unknown (0x%X)"));
}
break;
default:
if (q933_tree != NULL) {
proto_tree_add_text(q933_tree, tvb, offset, 1,
"Unknown information element (0x%02X)",
info_element);
}
break;
}
offset += 1;
codeset = locked_codeset;
continue;
}
info_element_len = tvb_get_guint8(tvb, offset + 1);
if (q933_tree != NULL) {
ti = proto_tree_add_text(q933_tree, tvb, offset,
1+1+info_element_len, "%s",
val_to_str(info_element, q933_info_element_vals[codeset],
"Unknown information element (0x%02X)"));
ie_tree = proto_item_add_subtree(ti, ett_q933_ie);
proto_tree_add_text(ie_tree, tvb, offset, 1,
"Information element: %s",
val_to_str(info_element, q933_info_element_vals[codeset],
"Unknown (0x%02X)"));
proto_tree_add_text(ie_tree, tvb, offset + 1, 1,
"Length: %u", info_element_len);
switch ((codeset << 8) | info_element) {
case CS0 | Q933_IE_SEGMENTED_MESSAGE:
dissect_q933_segmented_message_ie(tvb,
offset + 2, info_element_len,
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
"Display information");
break;
case CS0 | Q933_IE_E2E_TRANSIT_DELAY:
dissect_q933_e2e_transit_delay_ie(tvb,
offset + 2, info_element_len,
ie_tree);
break;
case CS0 | Q933_IE_TD_SELECTION_AND_INT:
dissect_q933_td_selection_and_int_ie(
tvb, offset + 2, info_element_len,
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
proto_tree_add_text(ie_tree, tvb,
offset + 2, info_element_len,
"Data: %s",
tvb_bytes_to_str(tvb, offset + 2,
info_element_len));
break;
}
}
offset += 1 + 1 + info_element_len;
codeset = locked_codeset;
}
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
};
static gint *ett[] = {
&ett_q933,
&ett_q933_ie,
};
proto_q933 = proto_register_protocol("Q.933", "Q.933", "q933");
proto_register_field_array (proto_q933, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("q933", dissect_q933, proto_q933);
}
void
proto_reg_handoff_q933(void)
{
dissector_handle_t q933_handle;
q933_handle = find_dissector("q933");
dissector_add_uint("fr.osinl", NLPID_Q_933, q933_handle);
}
