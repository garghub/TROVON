static void
x25_hash_add_proto_start(guint16 vc, guint32 frame, dissector_handle_t dissect)
{
circuit_t *circuit;
circuit = find_circuit(CT_X25, vc, frame);
if (circuit != NULL) {
close_circuit(circuit, frame - 1);
}
circuit = circuit_new(CT_X25, vc, frame);
circuit_set_dissector(circuit, dissect);
}
static void
x25_hash_add_proto_end(guint16 vc, guint32 frame)
{
circuit_t *circuit;
circuit = find_circuit(CT_X25, vc, frame);
if (circuit != NULL)
close_circuit(circuit, frame);
}
static char *
dte_address_util(tvbuff_t *tvb, int offset, guint8 len)
{
int i;
char *tmpbuf = (char *)wmem_alloc(wmem_packet_scope(), 258);
for (i = 0; (i<len)&&(i<256); i++) {
if (i % 2 == 0) {
tmpbuf[i] = ((tvb_get_guint8(tvb, offset+i/2) >> 4) & 0x0F) + '0';
if (tmpbuf[i] > '9')
tmpbuf[i] += ('A' - '0' - 10);
} else {
tmpbuf[i] = (tvb_get_guint8(tvb, offset+i/2) & 0x0F) + '0';
if (tmpbuf[i] > '9')
tmpbuf[i] += ('A' - '0' - 10);
}
}
tmpbuf[i] = '\0';
return tmpbuf;
}
static void
add_priority(proto_tree *tree, int hf, tvbuff_t *tvb, int offset)
{
guint8 priority;
priority = tvb_get_guint8(tvb, offset);
if (priority == 255)
proto_tree_add_uint_format_value(tree, hf, tvb, offset, 1, priority,
"Unspecified (255)");
else
proto_tree_add_uint(tree, hf, tvb, offset, 1, priority);
}
static void
dump_facilities(proto_tree *tree, int *offset, tvbuff_t *tvb, packet_info *pinfo)
{
guint8 fac, byte1, byte2, byte3;
guint32 len;
proto_item *ti = NULL;
proto_tree *facilities_tree = NULL, *facility_tree = NULL;
len = tvb_get_guint8(tvb, *offset);
if (len && tree) {
facilities_tree = proto_tree_add_subtree(tree, tvb, *offset, len + 1,
ett_x25_facilities, NULL, "Facilities");
proto_tree_add_item(facilities_tree, hf_x25_facilities_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
}
(*offset)++;
while (len > 0) {
ti = proto_tree_add_item(facilities_tree, hf_x25_facility, tvb, *offset, -1, ENC_NA);
fac = tvb_get_guint8(tvb, *offset);
switch(fac & X25_FAC_CLASS_MASK) {
case X25_FAC_CLASS_A:
proto_item_set_len(ti, 2);
proto_item_append_text(ti, ": %s",
val_to_str(fac, x25_facilities_classA_vals, "Unknown (0x%02X)"));
facility_tree = proto_item_add_subtree(ti, ett_x25_facility);
proto_tree_add_item(facility_tree, hf_x25_facility_class, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_facility_classA, tvb, *offset, 1, ENC_BIG_ENDIAN);
if (facility_tree) {
switch (fac) {
case X25_FAC_COMP_MARK:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_comp_mark, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_REVERSE:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_reverse, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_fast_select, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_icrd, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_facility_reverse_charging, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_CHARGING_INFO:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_charging_info, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_facility_charging_info, tvb, *offset+1, 1, ENC_NA);
break;
case X25_FAC_THROUGHPUT:
proto_tree_add_item(facility_tree, hf_x25_facility_throughput_called_dte, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_throughput_called_dte, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_CUG:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_cug, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_CALLED_MODIF:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_called_motif, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_CUG_OUTGOING_ACC:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_cug_outgoing_acc, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_THROUGHPUT_MIN:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_throughput_min, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_EXPRESS_DATA:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_express_data, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(facility_tree, hf_x25_facility_classA_unknown, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
break;
}
}
(*offset) += 2;
len -= 2;
break;
case X25_FAC_CLASS_B:
proto_item_set_len(ti, 3);
proto_item_append_text(ti, ": %s",
val_to_str(fac, x25_facilities_classB_vals, "Unknown (0x%02X)"));
facility_tree = proto_item_add_subtree(ti, ett_x25_facility);
proto_tree_add_item(facility_tree, hf_x25_facility_class, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_facility_classB, tvb, *offset, 1, ENC_BIG_ENDIAN);
if (facility_tree) {
switch (fac) {
case X25_FAC_BILATERAL_CUG:
proto_tree_add_item(facility_tree, hf_x25_facility_classB_bilateral_cug, tvb, *offset+1, 2, ENC_BIG_ENDIAN);
break;
case X25_FAC_PACKET_SIZE:
proto_tree_add_item(facility_tree, hf_x25_facility_packet_size_called_dte, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_facility_packet_size_calling_dte, tvb, *offset+2, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_WINDOW_SIZE:
proto_tree_add_item(facility_tree, hf_x25_window_size_called_dte, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_window_size_calling_dte, tvb, *offset+2, 1, ENC_BIG_ENDIAN);
break;
case X25_FAC_RPOA_SELECTION:
proto_tree_add_item(facility_tree, hf_x25_facility_data_network_id_code, tvb, *offset+1, 2, ENC_BIG_ENDIAN);
break;
case X25_FAC_CUG_EXT:
proto_tree_add_item(facility_tree, hf_x25_facility_cug_ext, tvb, *offset+1, 2, ENC_BIG_ENDIAN);
break;
case X25_FAC_CUG_OUTGOING_ACC_EXT:
proto_tree_add_item(facility_tree, hf_x25_facility_cug_outgoing_acc_ext, tvb, *offset+1, 2, ENC_BIG_ENDIAN);
break;
case X25_FAC_TRANSIT_DELAY:
proto_tree_add_item(facility_tree, hf_x25_facility_transit_delay, tvb, *offset+1, 2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(facility_tree, hf_x25_facility_classB_unknown, tvb, *offset+1, 2, ENC_BIG_ENDIAN);
break;
}
}
(*offset) += 3;
len -= 3;
break;
case X25_FAC_CLASS_C:
proto_item_set_len(ti, 4);
proto_item_append_text(ti, ": %s",
val_to_str(fac, x25_facilities_classC_vals, "Unknown (0x%02X)"));
facility_tree = proto_item_add_subtree(ti, ett_x25_facility);
proto_tree_add_item(facility_tree, hf_x25_facility_class, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_facility_classC, tvb, *offset, 1, ENC_BIG_ENDIAN);
if (facility_tree) {
proto_tree_add_item(facility_tree, hf_x25_facility_classC_unknown, tvb, *offset+1, 2, ENC_BIG_ENDIAN);
}
(*offset) += 4;
len -= 4;
break;
case X25_FAC_CLASS_D:
proto_item_append_text(ti, ": %s",
val_to_str(fac, x25_facilities_classD_vals, "Unknown (0x%02X)"));
facility_tree = proto_item_add_subtree(ti, ett_x25_facility);
proto_tree_add_item(facility_tree, hf_x25_facility_class, tvb, *offset, 1, ENC_BIG_ENDIAN);
byte1 = tvb_get_guint8(tvb, *offset+1);
proto_item_set_len(ti, byte1+2);
proto_tree_add_item(facility_tree, hf_x25_facility_classD, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(facility_tree, hf_x25_facility_length, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
if (facility_tree) {
switch (fac) {
case X25_FAC_CALL_DURATION:
{
int i;
if ((byte1 < 4) || (byte1 % 4)) {
expert_add_info(pinfo, ti, &ei_x25_facility_length);
return;
}
for (i = 0; (i<byte1); i+=4) {
proto_tree_add_bytes_format_value(facility_tree, hf_x25_call_duration, tvb, *offset+2+i, 4,
NULL, "%u Day(s) %02X:%02X:%02X Hour(s)",
tvb_get_guint8(tvb, *offset+2+i),
tvb_get_guint8(tvb, *offset+3+i),
tvb_get_guint8(tvb, *offset+4+i),
tvb_get_guint8(tvb, *offset+5+i));
}
}
break;
case X25_FAC_SEGMENT_COUNT:
{
int i;
if ((byte1 < 8) || (byte1 % 8)) {
expert_add_info(pinfo, ti, &ei_x25_facility_length);
return;
}
for (i = 0; (i<byte1); i+=8) {
proto_tree_add_item(facility_tree, hf_x25_segments_to_dte, tvb, *offset+2+i, 4, ENC_NA);
proto_tree_add_item(facility_tree, hf_x25_segments_from_dte, tvb, *offset+6+i, 4, ENC_NA);
}
}
break;
case X25_FAC_CALL_TRANSFER:
{
char *tmpbuf;
if (byte1 < 2) {
expert_add_info(pinfo, ti, &ei_x25_facility_length);
return;
}
byte2 = tvb_get_guint8(tvb, *offset+2);
if ((byte2 & 0xC0) == 0xC0) {
proto_tree_add_uint_format_value(facility_tree, hf_x25_facility_call_transfer_reason, tvb,
*offset+2, 1, byte2, "call deflection by the originally called DTE address");
}
else {
proto_tree_add_uint(facility_tree, hf_x25_facility_call_transfer_reason, tvb, *offset+2, 1, byte2);
}
byte3 = tvb_get_guint8(tvb, *offset+3);
proto_tree_add_uint(facility_tree, hf_x25_facility_call_transfer_num_semi_octets, tvb, *offset+4, 1, byte3);
tmpbuf = dte_address_util(tvb, *offset + 4, byte3);
proto_tree_add_string(facility_tree, hf_x25_dte_address, tvb, *offset+4, byte1 - 2, tmpbuf);
}
break;
case X25_FAC_RPOA_SELECTION_EXT:
{
int i;
if ((byte1 < 2) || (byte1 % 2)) {
expert_add_info(pinfo, ti, &ei_x25_facility_length);
return;
}
for (i = 0; (i<byte1); i+=2) {
proto_tree_add_item(facility_tree, hf_x25_data_network_identification_code, tvb, *offset+2+i, 2, ENC_BIG_ENDIAN);
}
}
break;
case X25_FAC_CALLING_ADDR_EXT:
{
char *tmpbuf;
if (byte1 < 1) {
expert_add_info(pinfo, ti, &ei_x25_facility_length);
return;
}
byte2 = tvb_get_guint8(tvb, *offset+2) & 0x3F;
proto_tree_add_uint(facility_tree, hf_x25_facility_calling_addr_ext_num_semi_octets, tvb, *offset+2, 1, byte2);
tmpbuf = dte_address_util(tvb, *offset + 3, byte2);
proto_tree_add_string(facility_tree, hf_x25_dte_address, tvb, *offset+3, byte1 - 1, tmpbuf);
}
break;
case X25_FAC_MONETARY_UNIT:
proto_tree_add_item(facility_tree, hf_x25_facility_monetary_unit, tvb, *offset+2, byte1, ENC_NA);
break;
case X25_FAC_NUI:
proto_tree_add_item(facility_tree, hf_x25_facility_nui, tvb, *offset+2, byte1, ENC_NA);
break;
case X25_FAC_CALLED_ADDR_EXT:
{
char *tmpbuf;
if (byte1 < 1) {
expert_add_info(pinfo, ti, &ei_x25_facility_length);
return;
}
byte2 = tvb_get_guint8(tvb, *offset+2) & 0x3F;
proto_tree_add_uint(facility_tree, hf_x25_facility_called_addr_ext_num_semi_octets, tvb, *offset+2, 1, byte2);
tmpbuf = dte_address_util(tvb, *offset+3, byte2);
proto_tree_add_string(facility_tree, hf_x25_dte_address, tvb, *offset+3, byte1 - 1, tmpbuf);
}
break;
case X25_FAC_ETE_TRANSIT_DELAY:
if (byte1 < 2)
break;
proto_tree_add_item(facility_tree, hf_x25_facility_cumulative_ete_transit_delay, tvb, *offset+2, 2, ENC_BIG_ENDIAN);
if (byte1 < 4)
break;
proto_tree_add_item(facility_tree, hf_x25_facility_requested_ete_transit_delay, tvb, *offset+4, 2, ENC_BIG_ENDIAN);
if (byte1 < 6)
break;
proto_tree_add_item(facility_tree, hf_x25_facility_max_acceptable_ete_transit_delay, tvb, *offset+6, 2, ENC_BIG_ENDIAN);
break;
case X25_FAC_CALL_DEFLECT:
{
char *tmpbuf;
if (byte1 < 2) {
expert_add_info(pinfo, ti, &ei_x25_facility_length);
return;
}
byte2 = tvb_get_guint8(tvb, *offset+2);
if ((byte2 & 0xC0) == 0xC0)
proto_tree_add_uint_format_value(facility_tree, hf_x25_facility_call_deflect_reason, tvb, *offset+2, 1,
byte2, "call DTE originated");
else
proto_tree_add_uint_format_value(facility_tree, hf_x25_facility_call_deflect_reason, tvb, *offset+2, 1,
byte2, "unknown");
byte3 = tvb_get_guint8(tvb, *offset+3);
proto_tree_add_uint(facility_tree, hf_x25_facility_call_deflect_num_semi_octets, tvb, *offset+3, 1, byte3);
tmpbuf = dte_address_util(tvb, *offset+4, byte3);
proto_tree_add_string(facility_tree, hf_x25_alternative_dte_address, tvb, *offset+4, byte1 - 2, tmpbuf);
}
break;
case X25_FAC_PRIORITY:
if (byte1 < 1)
break;
add_priority(facility_tree, hf_x25_facility_priority_data, tvb, *offset+2);
if (byte1 < 2)
break;
add_priority(facility_tree, hf_x25_facility_priority_estab_conn, tvb, *offset+3);
if (byte1 < 3)
break;
add_priority(facility_tree, hf_x25_facility_priority_keep_conn, tvb, *offset+4);
if (byte1 < 4)
break;
add_priority(facility_tree, hf_x25_facility_min_acceptable_priority_data, tvb, *offset+5);
if (byte1 < 5)
break;
add_priority(facility_tree, hf_x25_facility_min_acceptable_priority_estab_conn, tvb, *offset+6);
if (byte1 < 6)
break;
add_priority(facility_tree, hf_x25_facility_min_acceptable_priority_keep_conn, tvb, *offset+7);
break;
default:
proto_tree_add_item(facility_tree, hf_x25_facility_classD_unknown, tvb, *offset+2, byte1, ENC_NA);
}
}
byte1 = tvb_get_guint8(tvb, *offset+1);
(*offset) += byte1+2;
len -= byte1+2;
break;
}
}
}
static void
x25_ntoa(proto_tree *tree, int *offset, tvbuff_t *tvb,
packet_info *pinfo, gboolean is_registration)
{
int len1, len2;
int i;
char *addr1, *addr2;
char *first, *second;
guint8 byte;
int localoffset;
addr1=(char *)wmem_alloc(wmem_packet_scope(), 16);
addr2=(char *)wmem_alloc(wmem_packet_scope(), 16);
byte = tvb_get_guint8(tvb, *offset);
len1 = (byte >> 0) & 0x0F;
len2 = (byte >> 4) & 0x0F;
if (tree) {
if (is_registration) {
proto_tree_add_item(tree, hf_x25_dte_address_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_x25_dce_address_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(tree, hf_x25_calling_address_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_x25_called_address_length, tvb, *offset, 1, ENC_BIG_ENDIAN);
}
}
(*offset)++;
localoffset = *offset;
byte = tvb_get_guint8(tvb, localoffset);
first=addr1;
second=addr2;
for (i = 0; i < (len1 + len2); i++) {
if (i < len1) {
if (i % 2 != 0) {
*first++ = ((byte >> 0) & 0x0F) + '0';
localoffset++;
byte = tvb_get_guint8(tvb, localoffset);
} else {
*first++ = ((byte >> 4) & 0x0F) + '0';
}
} else {
if (i % 2 != 0) {
*second++ = ((byte >> 0) & 0x0F) + '0';
localoffset++;
byte = tvb_get_guint8(tvb, localoffset);
} else {
*second++ = ((byte >> 4) & 0x0F) + '0';
}
}
}
*first = '\0';
*second = '\0';
if (len1) {
col_add_str(pinfo->cinfo, COL_RES_DL_DST, addr1);
proto_tree_add_string(tree, is_registration ? hf_x25_dce_address : hf_x25_called_address, tvb, *offset,
(len1 + 1) / 2, addr1);
}
if (len2) {
col_add_str(pinfo->cinfo, COL_RES_DL_SRC, addr2);
proto_tree_add_string(tree, is_registration ? hf_x25_dte_address : hf_x25_calling_address, tvb, *offset + len1/2,
(len2+1)/2+(len1%2+(len2+1)%2)/2, addr2);
}
(*offset) += ((len1 + len2 + 1) / 2);
}
static void
x25_toa(proto_tree *tree, int *offset, tvbuff_t *tvb,
packet_info *pinfo)
{
int len1, len2;
int i;
char *addr1, *addr2;
char *first, *second;
guint8 byte;
int localoffset;
addr1=(char *)wmem_alloc(wmem_packet_scope(), 256);
addr2=(char *)wmem_alloc(wmem_packet_scope(), 256);
len1 = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_x25_called_address_length, tvb, *offset, 1, ENC_NA);
(*offset)++;
len2 = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(tree, hf_x25_calling_address_length, tvb, *offset, 1, ENC_NA);
(*offset)++;
localoffset = *offset;
byte = tvb_get_guint8(tvb, localoffset);
first=addr1;
second=addr2;
for (i = 0; i < (len1 + len2); i++) {
if (i < len1) {
if (i % 2 != 0) {
*first++ = ((byte >> 0) & 0x0F) + '0';
localoffset++;
byte = tvb_get_guint8(tvb, localoffset);
} else {
*first++ = ((byte >> 4) & 0x0F) + '0';
}
} else {
if (i % 2 != 0) {
*second++ = ((byte >> 0) & 0x0F) + '0';
localoffset++;
byte = tvb_get_guint8(tvb, localoffset);
} else {
*second++ = ((byte >> 4) & 0x0F) + '0';
}
}
}
*first = '\0';
*second = '\0';
if (len1) {
col_add_str(pinfo->cinfo, COL_RES_DL_DST, addr1);
proto_tree_add_string(tree, hf_x25_called_address, tvb, *offset,
(len1 + 1) / 2, addr1);
}
if (len2) {
col_add_str(pinfo->cinfo, COL_RES_DL_SRC, addr2);
proto_tree_add_string(tree, hf_x25_calling_address, tvb, *offset + len1/2,
(len2+1)/2+(len1%2+(len2+1)%2)/2, addr2);
}
(*offset) += ((len1 + len2 + 1) / 2);
}
static int
get_x25_pkt_len(tvbuff_t *tvb)
{
guint length, called_len, calling_len, dte_len, dce_len;
guint8 byte2, bytex;
byte2 = tvb_get_guint8(tvb, 2);
switch (byte2)
{
case X25_CALL_REQUEST:
bytex = tvb_get_guint8(tvb, 3);
called_len = (bytex >> 0) & 0x0F;
calling_len = (bytex >> 4) & 0x0F;
length = 4 + (called_len + calling_len + 1) / 2;
if (length < tvb_reported_length(tvb))
length += (1 + tvb_get_guint8(tvb, length));
return MIN(tvb_reported_length(tvb),length);
case X25_CALL_ACCEPTED:
if (tvb_reported_length(tvb) == 3)
return(3);
bytex = tvb_get_guint8(tvb, 3);
called_len = (bytex >> 0) & 0x0F;
calling_len = (bytex >> 4) & 0x0F;
length = 4 + (called_len + calling_len + 1) / 2;
if (length < tvb_reported_length(tvb))
length += (1 + tvb_get_guint8(tvb, length));
return MIN(tvb_reported_length(tvb),length);
case X25_CLEAR_REQUEST:
case X25_RESET_REQUEST:
case X25_RESTART_REQUEST:
return MIN(tvb_reported_length(tvb),5);
case X25_DIAGNOSTIC:
return MIN(tvb_reported_length(tvb),4);
case X25_CLEAR_CONFIRMATION:
case X25_INTERRUPT:
case X25_INTERRUPT_CONFIRMATION:
case X25_RESET_CONFIRMATION:
case X25_RESTART_CONFIRMATION:
return MIN(tvb_reported_length(tvb),3);
case X25_REGISTRATION_REQUEST:
bytex = tvb_get_guint8(tvb, 3);
dce_len = (bytex >> 0) & 0x0F;
dte_len = (bytex >> 4) & 0x0F;
length = 4 + (dte_len + dce_len + 1) / 2;
if (length < tvb_reported_length(tvb))
length += (1 + tvb_get_guint8(tvb, length));
return MIN(tvb_reported_length(tvb),length);
case X25_REGISTRATION_CONFIRMATION:
bytex = tvb_get_guint8(tvb, 5);
dce_len = (bytex >> 0) & 0x0F;
dte_len = (bytex >> 4) & 0x0F;
length = 6 + (dte_len + dce_len + 1) / 2;
if (length < tvb_reported_length(tvb))
length += (1 + tvb_get_guint8(tvb, length));
return MIN(tvb_reported_length(tvb),length);
}
if (PACKET_IS_DATA(byte2))
return MIN(tvb_reported_length(tvb),3);
switch (PACKET_TYPE_FC(byte2))
{
case X25_RR:
return MIN(tvb_reported_length(tvb),3);
case X25_RNR:
return MIN(tvb_reported_length(tvb),3);
case X25_REJ:
return MIN(tvb_reported_length(tvb),3);
}
return 0;
}
static void
dissect_x25_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
x25_dir_t dir, gboolean side)
{
proto_tree *x25_tree=0, *gfi_tree=0, *userdata_tree=0;
proto_item *ti;
guint localoffset=0;
guint x25_pkt_len;
int modulo;
guint16 vc;
dissector_handle_t dissect;
gboolean toa;
guint16 bytes0_1;
guint8 pkt_type;
const char *short_name = NULL, *long_name = NULL;
tvbuff_t *next_tvb = NULL;
gboolean q_bit_set = FALSE;
gboolean m_bit_set;
gint payload_len;
guint32 frag_key;
fragment_head *fd_head;
heur_dtbl_entry_t *hdtbl_entry;
guint8 spi;
int is_x_264;
guint8 prt_id;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "X.25");
col_clear(pinfo->cinfo, COL_INFO);
bytes0_1 = tvb_get_ntohs(tvb, 0);
modulo = ((bytes0_1 & 0x2000) ? 128 : 8);
vc = (int)(bytes0_1 & 0x0FFF);
pinfo->ctype = CT_X25;
pinfo->circuit_id = vc;
if (bytes0_1 & X25_ABIT) toa = TRUE;
else toa = FALSE;
x25_pkt_len = get_x25_pkt_len(tvb);
if (x25_pkt_len < 3)
{
col_set_str(pinfo->cinfo, COL_INFO, "Invalid/short X.25 packet");
if (tree)
proto_tree_add_protocol_format(tree, proto_x25, tvb, 0, -1,
"Invalid/short X.25 packet");
return;
}
pkt_type = tvb_get_guint8(tvb, 2);
if (PACKET_IS_DATA(pkt_type)) {
if (bytes0_1 & X25_QBIT)
q_bit_set = TRUE;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_x25, tvb, 0, x25_pkt_len, ENC_NA);
x25_tree = proto_item_add_subtree(ti, ett_x25);
ti = proto_tree_add_item(x25_tree, hf_x25_gfi, tvb, 0, 2, ENC_BIG_ENDIAN);
gfi_tree = proto_item_add_subtree(ti, ett_x25_gfi);
if (PACKET_IS_DATA(pkt_type)) {
proto_tree_add_boolean(gfi_tree, hf_x25_qbit, tvb, 0, 2,
bytes0_1);
}
else if (pkt_type == X25_CALL_REQUEST ||
pkt_type == X25_CALL_ACCEPTED ||
pkt_type == X25_CLEAR_REQUEST ||
pkt_type == X25_CLEAR_CONFIRMATION) {
proto_tree_add_boolean(gfi_tree, hf_x25_abit, tvb, 0, 2,
bytes0_1);
}
if (pkt_type == X25_CALL_REQUEST || pkt_type == X25_CALL_ACCEPTED ||
PACKET_IS_DATA(pkt_type)) {
proto_tree_add_boolean(gfi_tree, hf_x25_dbit, tvb, 0, 2,
bytes0_1);
}
proto_tree_add_uint(gfi_tree, hf_x25_mod, tvb, 0, 2, bytes0_1);
}
switch (pkt_type) {
case X25_CALL_REQUEST:
switch (dir) {
case X25_FROM_DCE:
short_name = "Inc. call";
long_name = "Incoming call";
break;
case X25_FROM_DTE:
short_name = "Call req.";
long_name = "Call request";
break;
case X25_UNKNOWN:
short_name = "Inc. call/Call req.";
long_name = "Incoming call/Call request";
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d", short_name, vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb,
0, 2, bytes0_1);
proto_tree_add_uint_format_value(x25_tree, hf_x25_type, tvb, 2, 1,
X25_CALL_REQUEST, "%s", long_name);
}
localoffset = 3;
if (localoffset < x25_pkt_len) {
if (toa)
x25_toa(x25_tree, (gint*)&localoffset, tvb, pinfo);
else
x25_ntoa(x25_tree, (gint*)&localoffset, tvb, pinfo, FALSE);
}
if (localoffset < x25_pkt_len)
dump_facilities(x25_tree, (gint*)&localoffset, tvb, pinfo);
if (localoffset < tvb_reported_length(tvb))
{
userdata_tree = proto_tree_add_subtree(x25_tree, tvb, localoffset, -1,
ett_x25_user_data, &ti, "User data");
spi = tvb_get_guint8(tvb, localoffset);
if (spi > 32 || spi < 3) {
is_x_264 = FALSE;
} else {
if (tvb_bytes_exist(tvb, localoffset+1, 1)) {
if (tvb_get_guint8(tvb, localoffset+1) == 0x01) {
is_x_264 = TRUE;
} else {
is_x_264 = FALSE;
}
} else {
is_x_264 = -1;
}
}
if (is_x_264 == -1) {
localoffset = tvb_reported_length(tvb);
} else if (is_x_264) {
if (userdata_tree) {
proto_tree_add_item( userdata_tree, hf_x264_length_indicator, tvb, localoffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( userdata_tree, hf_x264_un_tpdu_id, tvb, localoffset+1, 1, ENC_BIG_ENDIAN);
}
prt_id = tvb_get_guint8(tvb, localoffset+2);
if (userdata_tree) {
proto_tree_add_item( userdata_tree, hf_x264_protocol_id, tvb, localoffset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item( userdata_tree, hf_x264_sharing_strategy, tvb, localoffset+3, 1, ENC_BIG_ENDIAN);
}
localoffset += spi + 1;
switch (prt_id) {
case PRT_ID_ISO_8073:
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->num, ositp_handle);
break;
case PRT_ID_ISO_8602:
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->num, ositp_handle);
break;
}
} else if (is_x_264 == 0) {
if (userdata_tree) {
proto_tree_add_item( userdata_tree, hf_x263_sec_protocol_id, tvb, localoffset, 1, ENC_BIG_ENDIAN);
}
if (!pinfo->fd->flags.visited) {
dissect = dissector_get_uint_handle(x25_subdissector_table, spi);
if (dissect != NULL)
x25_hash_add_proto_start(vc, pinfo->num, dissect);
}
if (localoffset + 1 == tvb_reported_length(tvb))
return;
switch (spi) {
case NLPID_ISO8473_CLNP:
case NLPID_ISO9542_ESIS:
case NLPID_ISO10589_ISIS:
case NLPID_ISO10747_IDRP:
case NLPID_SNDCF:
break;
case NLPID_SPI_X_29:
localoffset += 4;
break;
default:
localoffset++;
}
}
} else {
if (call_request_nodata_is_cotp){
x25_hash_add_proto_start(vc, pinfo->num, ositp_handle);
}
}
break;
case X25_CALL_ACCEPTED:
switch (dir) {
case X25_FROM_DCE:
short_name = "Call conn.";
long_name = "Call connected";
break;
case X25_FROM_DTE:
short_name = "Call acc.";
long_name = "Call accepted";
break;
case X25_UNKNOWN:
short_name = "Call conn./Call acc.";
long_name = "Call connected/Call accepted";
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d", short_name, vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint_format_value(x25_tree, hf_x25_type, tvb, 2, 1,
X25_CALL_ACCEPTED, "%s", long_name);
}
localoffset = 3;
if (localoffset < x25_pkt_len) {
if (toa)
x25_toa(x25_tree, (gint*)&localoffset, tvb, pinfo);
else
x25_ntoa(x25_tree, (gint*)&localoffset, tvb, pinfo, FALSE);
}
if (localoffset < x25_pkt_len)
dump_facilities(x25_tree, (gint*)&localoffset, tvb, pinfo);
break;
case X25_CLEAR_REQUEST:
switch (dir) {
case X25_FROM_DCE:
short_name = "Clear ind.";
long_name = "Clear indication";
break;
case X25_FROM_DTE:
short_name = "Clear req.";
long_name = "Clear request";
break;
case X25_UNKNOWN:
short_name = "Clear ind./Clear req.";
long_name = "Clear indication/Clear request";
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d %s - %s", short_name,
vc, rval_to_str(tvb_get_guint8(tvb, 3), clear_code_rvals, "Unknown (0x%02x)"),
val_to_str_ext(tvb_get_guint8(tvb, 4), &x25_clear_diag_vals_ext, "Unknown (0x%02x)"));
x25_hash_add_proto_end(vc, pinfo->num);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint_format_value(x25_tree, hf_x25_type, tvb,
localoffset+2, 1, X25_CLEAR_REQUEST, "%s",
long_name);
proto_tree_add_item(x25_tree, hf_x25_clear_cause, tvb, 3, 1, ENC_NA);
proto_tree_add_item(x25_tree, hf_x25_diagnostic, tvb, 4, 1, ENC_BIG_ENDIAN);
}
localoffset = x25_pkt_len;
break;
case X25_CLEAR_CONFIRMATION:
col_add_fstr(pinfo->cinfo, COL_INFO, "Clear Conf. VC:%d", vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_CLEAR_CONFIRMATION);
}
localoffset = x25_pkt_len;
if (localoffset < tvb_reported_length(tvb)) {
if (toa)
x25_toa(x25_tree, (gint*)&localoffset, tvb, pinfo);
else
x25_ntoa(x25_tree,(gint*)&localoffset, tvb, pinfo, FALSE);
}
if (localoffset < tvb_reported_length(tvb))
dump_facilities(x25_tree, (gint*)&localoffset, tvb, pinfo);
break;
case X25_DIAGNOSTIC:
col_add_fstr(pinfo->cinfo, COL_INFO, "Diag. %d",
(int)tvb_get_guint8(tvb, 3));
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_DIAGNOSTIC);
proto_tree_add_item(x25_tree, hf_x25_diagnostic, tvb, 3, 1, ENC_NA);
}
localoffset = x25_pkt_len;
break;
case X25_INTERRUPT:
col_add_fstr(pinfo->cinfo, COL_INFO, "Interrupt VC:%d", vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_INTERRUPT);
}
localoffset = x25_pkt_len;
break;
case X25_INTERRUPT_CONFIRMATION:
col_add_fstr(pinfo->cinfo, COL_INFO, "Interrupt Conf. VC:%d", vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_INTERRUPT_CONFIRMATION);
}
localoffset = x25_pkt_len;
break;
case X25_RESET_REQUEST:
switch (dir) {
case X25_FROM_DCE:
short_name = "Reset ind.";
long_name = "Reset indication";
break;
case X25_FROM_DTE:
short_name = "Reset req.";
long_name = "Reset request";
break;
case X25_UNKNOWN:
short_name = "Reset ind./Reset req.";
long_name = "Reset indication/Reset request";
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d %s - Diag.:%d",
short_name, vc, rval_to_str(tvb_get_guint8(tvb, 3), reset_code_rvals, "Unknown (0x%02x)"),
(int)tvb_get_guint8(tvb, 4));
x25_hash_add_proto_end(vc, pinfo->num);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint_format_value(x25_tree, hf_x25_type, tvb, 2, 1,
X25_RESET_REQUEST, "%s", long_name);
proto_tree_add_item(x25_tree, hf_x25_reset_cause, tvb, 3, 1, ENC_NA);
proto_tree_add_item(x25_tree, hf_x25_diagnostic, tvb, 4, 1, ENC_NA);
}
localoffset = x25_pkt_len;
break;
case X25_RESET_CONFIRMATION:
col_add_fstr(pinfo->cinfo, COL_INFO, "Reset conf. VC:%d", vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_RESET_CONFIRMATION);
}
localoffset = x25_pkt_len;
break;
case X25_RESTART_REQUEST:
switch (dir) {
case X25_FROM_DCE:
short_name = "Restart ind.";
long_name = "Restart indication";
break;
case X25_FROM_DTE:
short_name = "Restart req.";
long_name = "Restart request";
break;
case X25_UNKNOWN:
short_name = "Restart ind./Restart req.";
long_name = "Restart indication/Restart request";
break;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s - Diag.:%d",
short_name,
rval_to_str(tvb_get_guint8(tvb, 3), restart_code_rvals, "Unknown (0x%02x)"),
(int)tvb_get_guint8(tvb, 4));
if (x25_tree) {
proto_tree_add_uint_format_value(x25_tree, hf_x25_type, tvb, 2, 1,
X25_RESTART_REQUEST, "%s", long_name);
proto_tree_add_item(x25_tree, hf_x25_restart_cause, tvb, 3, 1, ENC_NA);
proto_tree_add_item(x25_tree, hf_x25_diagnostic, tvb, 4, 1, ENC_NA);
}
localoffset = x25_pkt_len;
break;
case X25_RESTART_CONFIRMATION:
col_set_str(pinfo->cinfo, COL_INFO, "Restart conf.");
if (x25_tree)
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_RESTART_CONFIRMATION);
localoffset = x25_pkt_len;
break;
case X25_REGISTRATION_REQUEST:
col_set_str(pinfo->cinfo, COL_INFO, "Registration req.");
if (x25_tree)
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_REGISTRATION_REQUEST);
localoffset = 3;
if (localoffset < x25_pkt_len)
x25_ntoa(x25_tree, (gint*)&localoffset, tvb, pinfo, TRUE);
if (x25_tree) {
if (localoffset < x25_pkt_len)
proto_tree_add_item( x25_tree, hf_x25_reg_request_length, tvb, localoffset, 1, ENC_BIG_ENDIAN);
if (localoffset+1 < x25_pkt_len)
proto_tree_add_item(x25_tree, hf_x25_registration, tvb, localoffset+1, tvb_get_guint8(tvb, localoffset) & 0x7F, ENC_NA);
}
localoffset = tvb_reported_length(tvb);
break;
case X25_REGISTRATION_CONFIRMATION:
col_set_str(pinfo->cinfo, COL_INFO, "Registration conf.");
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_REGISTRATION_CONFIRMATION);
proto_tree_add_item(x25_tree, hf_x25_reg_confirm_cause, tvb, 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(x25_tree, hf_x25_reg_confirm_diagnostic, tvb, 4, 1, ENC_BIG_ENDIAN);
}
localoffset = 5;
if (localoffset < x25_pkt_len)
x25_ntoa(x25_tree, (gint*)&localoffset, tvb, pinfo, TRUE);
if (x25_tree) {
if (localoffset < x25_pkt_len)
proto_tree_add_item( x25_tree, hf_x25_reg_confirm_length, tvb, localoffset, 1, ENC_BIG_ENDIAN);
if (localoffset+1 < x25_pkt_len)
proto_tree_add_item(x25_tree, hf_x25_registration, tvb, localoffset+1, tvb_get_guint8(tvb, localoffset) & 0x7F, ENC_NA);
}
localoffset = tvb_reported_length(tvb);
break;
default:
localoffset = 2;
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, localoffset-2,
2, bytes0_1);
}
if (PACKET_IS_DATA(pkt_type)) {
if (modulo == 8)
col_add_fstr(pinfo->cinfo, COL_INFO,
"Data VC:%d P(S):%d P(R):%d %s", vc,
(pkt_type >> 1) & 0x07,
(pkt_type >> 5) & 0x07,
(pkt_type & X25_MBIT_MOD8) ? " M" : "");
else
col_add_fstr(pinfo->cinfo, COL_INFO,
"Data VC:%d P(S):%d P(R):%d %s", vc,
tvb_get_guint8(tvb, localoffset+1) >> 1,
pkt_type >> 1,
(tvb_get_guint8(tvb, localoffset+1) & X25_MBIT_MOD128) ? " M" : "");
if (x25_tree) {
if (modulo == 8) {
proto_tree_add_uint(x25_tree, hf_x25_p_r_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_boolean(x25_tree, hf_x25_mbit_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_p_s_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_type_data, tvb,
localoffset, 1, pkt_type);
}
else {
proto_tree_add_uint(x25_tree, hf_x25_p_r_mod128, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_type_data, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_p_s_mod128, tvb,
localoffset+1, 1,
tvb_get_guint8(tvb, localoffset+1));
proto_tree_add_boolean(x25_tree, hf_x25_mbit_mod128, tvb,
localoffset+1, 1,
tvb_get_guint8(tvb, localoffset+1));
}
}
if (modulo == 8) {
m_bit_set = pkt_type & X25_MBIT_MOD8;
localoffset += 1;
} else {
m_bit_set = tvb_get_guint8(tvb, localoffset+1) & X25_MBIT_MOD128;
localoffset += 2;
}
payload_len = tvb_reported_length_remaining(tvb, localoffset);
if (reassemble_x25) {
frag_key = vc;
if (side) {
frag_key |= 0x10000;
}
fd_head = fragment_add_seq_next(&x25_reassembly_table,
tvb, localoffset,
pinfo, frag_key, NULL,
payload_len, m_bit_set);
pinfo->fragmented = m_bit_set;
if (!m_bit_set && fd_head) {
if (fd_head->next) {
proto_item *frag_tree_item;
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, "Reassembled X.25");
if (x25_tree) {
show_fragment_seq_tree(fd_head,
&x25_frag_items,
x25_tree,
pinfo, next_tvb, &frag_tree_item);
}
}
}
if (m_bit_set && next_tvb == NULL) {
proto_tree_add_item(x25_tree, hf_x25_user_data, tvb, localoffset, -1, ENC_NA);
return;
}
}
} else {
if (modulo == 8) {
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_p_r_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_item(x25_tree, hf_x25_type_fc_mod8, tvb,
localoffset, 1, ENC_BIG_ENDIAN);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d P(R):%d",
val_to_str(PACKET_TYPE_FC(pkt_type), vals_x25_type, "Unknown (0x%02X)"),
vc, (pkt_type >> 5) & 0x07);
localoffset += 1;
} else {
if (x25_tree) {
proto_tree_add_item(x25_tree, hf_x25_type, tvb,
localoffset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(x25_tree, hf_x25_p_r_mod128, tvb,
localoffset+1, 1, ENC_BIG_ENDIAN);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d P(R):%d",
val_to_str(PACKET_TYPE_FC(pkt_type), vals_x25_type, "Unknown (0x%02X)"),
vc, tvb_get_guint8(tvb, localoffset+1) >> 1);
localoffset += 2;
}
}
break;
}
if (localoffset >= tvb_reported_length(tvb))
return;
if (pinfo->fragmented)
return;
if (!next_tvb)
next_tvb = tvb_new_subset_remaining(tvb, localoffset);
if (try_circuit_dissector(CT_X25, vc, pinfo->num, next_tvb, pinfo,
tree, &q_bit_set)) {
return;
}
if (payload_is_qllc_sna) {
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->num, qllc_handle);
call_dissector_with_data(qllc_handle, next_tvb, pinfo, tree, &q_bit_set);
return;
}
if (payload_check_data){
if (tvb_get_guint8(tvb, localoffset) == tvb_reported_length(next_tvb)-1) {
if ((tvb_get_guint8(tvb, localoffset+1) & 0x0F) == 0) {
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->num, ositp_handle);
call_dissector(ositp_handle, next_tvb, pinfo, tree);
return;
}
}
switch (tvb_get_guint8(tvb, localoffset)) {
case 0x45:
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->num, ip_handle);
call_dissector(ip_handle, next_tvb, pinfo, tree);
return;
case NLPID_ISO8473_CLNP:
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->num, clnp_handle);
call_dissector(clnp_handle, next_tvb, pinfo, tree);
return;
}
}
if (dissector_try_heuristic(x25_heur_subdissector_list, next_tvb, pinfo,
tree, &hdtbl_entry, NULL)) {
return;
}
call_data_dissector(next_tvb, pinfo, tree);
}
static int
dissect_x25_dir(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
dissect_x25_common(tvb, pinfo, tree,
(pinfo->pseudo_header->x25.flags & FROM_DCE) ? X25_FROM_DCE :
X25_FROM_DTE,
pinfo->pseudo_header->x25.flags & FROM_DCE);
return tvb_captured_length(tvb);
}
static int
dissect_x25(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int direction;
direction = cmp_address(&pinfo->src, &pinfo->dst);
if (direction == 0)
direction = (pinfo->srcport > pinfo->destport)*2 - 1;
dissect_x25_common(tvb, pinfo, tree, X25_UNKNOWN, direction > 0);
return tvb_captured_length(tvb);
}
static void
x25_reassemble_init(void)
{
reassembly_table_init(&x25_reassembly_table,
&addresses_reassembly_table_functions);
}
static void
x25_reassemble_cleanup(void)
{
reassembly_table_destroy(&x25_reassembly_table);
}
void
proto_register_x25(void)
{
static hf_register_info hf[] = {
{ &hf_x25_facility,
{ "Facility", "x25.facility", FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facilities_length,
{ "Facilities Length", "x25.facilities_length", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_length,
{ "Length", "x25.facility_length", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_class,
{ "Facility Class", "x25.facility.class", FT_UINT8, BASE_HEX, VALS(x25_facilities_class_vals), X25_FAC_CLASS_MASK,
NULL, HFILL }},
{ &hf_x25_facility_classA,
{ "Code", "x25.facility.classA", FT_UINT8, BASE_HEX, VALS(x25_facilities_classA_vals), 0,
"Facility ClassA Code", HFILL }},
{ &hf_x25_facility_classA_comp_mark,
{ "Parameter", "x25.facility.comp_mark", FT_UINT8, BASE_DEC, VALS(x25_facilities_classA_comp_mark_vals), 0,
"Facility Marker Parameter", HFILL }},
{ &hf_x25_facility_classA_reverse,
{ "Parameter", "x25.facility.reverse", FT_UINT8, BASE_HEX, NULL, 0,
"Facility Reverse Charging Parameter", HFILL }},
{ &hf_x25_facility_classA_charging_info,
{ "Parameter", "x25.facility.charging_info", FT_UINT8, BASE_HEX, NULL, 0,
"Facility Charging Information Parameter", HFILL }},
{ &hf_x25_facility_reverse_charging,
{ "Reverse charging", "x25.reverse_charging", FT_BOOLEAN, 8, TFS(&x25_reverse_charging_val), 0x01,
NULL, HFILL }},
{ &hf_x25_facility_charging_info,
{ "Charging information", "x25.charging_info", FT_BOOLEAN, 8, TFS(&tfs_requested_not_requested), 0x01,
NULL, HFILL }},
{ &hf_x25_facility_throughput_called_dte,
{ "From the called DTE", "x25.facility.throughput.called_dte", FT_UINT8, BASE_DEC, VALS(x25_facilities_classA_throughput_vals), 0xF0,
"Facility Throughput called DTE", HFILL }},
{ &hf_x25_throughput_called_dte,
{ "From the calling DTE", "x25.facility.throughput.called_dte", FT_UINT8, BASE_DEC, VALS(x25_facilities_classA_throughput_vals), 0x0F,
"Facility Throughput called DTE", HFILL }},
{ &hf_x25_facility_classA_cug,
{ "Closed user group", "x25.facility.cug", FT_UINT8, BASE_HEX, NULL, 0,
"Facility Closed user group", HFILL }},
{ &hf_x25_facility_classA_called_motif,
{ "Parameter", "x25.facility.called_motif", FT_UINT8, BASE_HEX, NULL, 0,
"Facility Called address modified parameter", HFILL }},
{ &hf_x25_facility_classA_cug_outgoing_acc,
{ "Closed user group", "x25.facility.cug_outgoing_acc", FT_UINT8, BASE_HEX, NULL, 0,
"Facility Closed user group with outgoing access selection", HFILL }},
{ &hf_x25_facility_classA_throughput_min,
{ "Parameter", "x25.facility.throughput_min", FT_UINT8, BASE_HEX, NULL, 0,
"Facility Minimum throughput class parameter", HFILL }},
{ &hf_x25_facility_classA_express_data,
{ "Parameter", "x25.facility.express_data", FT_UINT8, BASE_HEX, NULL, 0,
"Facility Negotiation of express data parameter", HFILL }},
{ &hf_x25_facility_classA_unknown,
{ "Parameter", "x25.facility.classA_unknown", FT_UINT8, BASE_HEX, NULL, 0,
"Facility Class A unknown parameter", HFILL }},
{ &hf_x25_facility_classB,
{ "Code", "x25.facility.classB", FT_UINT8, BASE_HEX, VALS(x25_facilities_classB_vals), 0,
"Facility ClassB Code", HFILL }},
{ &hf_x25_facility_classB_bilateral_cug,
{ "Bilateral CUG", "x25.facility.bilateral_cug", FT_UINT16, BASE_HEX, NULL, 0,
"Facility Bilateral CUG", HFILL }},
{ &hf_x25_facility_packet_size_called_dte,
{ "From the called DTE", "x25.facility.packet_size.called_dte", FT_UINT8, BASE_DEC, VALS(x25_facilities_classB_packet_size_vals), 0,
"Facility Packet size from the called DTE", HFILL }},
{ &hf_x25_facility_packet_size_calling_dte,
{ "From the calling DTE", "x25.facility.packet_size.calling_dte", FT_UINT8, BASE_DEC, VALS(x25_facilities_classB_packet_size_vals), 0,
"Facility Packet size from the calling DTE", HFILL }},
{ &hf_x25_facility_data_network_id_code,
{ "Data network identification code", "x25.facility.data_network_id_code", FT_UINT16, BASE_HEX, NULL, 0,
"Facility RPOA selection data network identification code", HFILL }},
{ &hf_x25_facility_cug_ext,
{ "Closed user group", "x25.facility.cug_ext", FT_UINT16, BASE_HEX, NULL, 0,
"Facility Extended closed user group selection", HFILL }},
{ &hf_x25_facility_cug_outgoing_acc_ext,
{ "Closed user group", "x25.facility.cug_outgoing_acc_ext", FT_UINT16, BASE_HEX, NULL, 0,
"Facility Extended closed user group with outgoing access selection", HFILL }},
{ &hf_x25_facility_transit_delay,
{ "Transit delay (ms)", "x25.facility.transit_delay", FT_UINT16, BASE_DEC, NULL, 0,
"Facility Transit delay selection and indication", HFILL }},
{ &hf_x25_facility_classB_unknown,
{ "Parameter", "x25.facility.classB_unknown", FT_UINT16, BASE_HEX, NULL, 0,
"Facility Class B unknown parameter", HFILL }},
{ &hf_x25_facility_classC_unknown,
{ "Parameter", "x25.facility.classC_unknown", FT_UINT24, BASE_HEX, NULL, 0,
"Facility Class C unknown parameter", HFILL }},
{ &hf_x25_facility_classC,
{ "Code", "x25.facility.classC", FT_UINT8, BASE_HEX, VALS(x25_facilities_classC_vals), 0,
"Facility ClassC Code", HFILL }},
{ &hf_x25_facility_classD,
{ "Code", "x25.facility.classD", FT_UINT8, BASE_HEX, VALS(x25_facilities_classD_vals), 0,
"Facility ClassD Code", HFILL }},
{ &hf_x25_gfi,
{ "GFI", "x25.gfi", FT_UINT16, BASE_DEC, NULL, 0xF000,
"General format identifier", HFILL }},
{ &hf_x25_abit,
{ "A Bit", "x25.a", FT_BOOLEAN, 16, NULL, X25_ABIT,
"Address Bit", HFILL }},
{ &hf_x25_qbit,
{ "Q Bit", "x25.q", FT_BOOLEAN, 16, NULL, X25_QBIT,
"Qualifier Bit", HFILL }},
{ &hf_x25_dbit,
{ "D Bit", "x25.d", FT_BOOLEAN, 16, NULL, X25_DBIT,
"Delivery Confirmation Bit", HFILL }},
{ &hf_x25_mod,
{ "Modulo", "x25.mod", FT_UINT16, BASE_DEC, VALS(vals_modulo), 0x3000,
"Specifies whether the frame is modulo 8 or 128", HFILL }},
{ &hf_x25_lcn,
{ "Logical Channel", "x25.lcn", FT_UINT16, BASE_DEC, NULL, 0x0FFF,
"Logical Channel Number", HFILL }},
{ &hf_x25_type,
{ "Packet Type", "x25.type", FT_UINT8, BASE_HEX, VALS(vals_x25_type), 0x0,
NULL, HFILL }},
{ &hf_x25_type_fc_mod8,
{ "Packet Type", "x25.type", FT_UINT8, BASE_HEX, VALS(vals_x25_type), 0x1F,
NULL, HFILL }},
{ &hf_x25_type_data,
{ "Packet Type", "x25.type", FT_UINT8, BASE_HEX, VALS(vals_x25_type), 0x01,
NULL, HFILL }},
{ &hf_x25_diagnostic,
{ "Diagnostic", "x25.diagnostic", FT_UINT8, BASE_DEC|BASE_EXT_STRING, &x25_clear_diag_vals_ext, 0,
NULL, HFILL }},
{ &hf_x25_p_r_mod8,
{ "P(R)", "x25.p_r", FT_UINT8, BASE_DEC, NULL, 0xE0,
"Packet Receive Sequence Number", HFILL }},
{ &hf_x25_p_r_mod128,
{ "P(R)", "x25.p_r", FT_UINT8, BASE_DEC, NULL, 0xFE,
"Packet Receive Sequence Number", HFILL }},
{ &hf_x25_mbit_mod8,
{ "M Bit", "x25.m", FT_BOOLEAN, 8, TFS(&m_bit_tfs), X25_MBIT_MOD8,
"More Bit", HFILL }},
{ &hf_x25_mbit_mod128,
{ "M Bit", "x25.m", FT_BOOLEAN, 8, TFS(&m_bit_tfs), X25_MBIT_MOD128,
"More Bit", HFILL }},
{ &hf_x25_p_s_mod8,
{ "P(S)", "x25.p_s", FT_UINT8, BASE_DEC, NULL, 0x0E,
"Packet Send Sequence Number", HFILL }},
{ &hf_x25_p_s_mod128,
{ "P(S)", "x25.p_s", FT_UINT8, BASE_DEC, NULL, 0xFE,
"Packet Send Sequence Number", HFILL }},
{ &hf_x25_window_size_called_dte,
{ "From the called DTE", "x25.window_size.called_dte", FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_x25_window_size_calling_dte,
{ "From the calling DTE", "x25.window_size.calling_dte", FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_x25_dte_address_length,
{ "DTE address length", "x25.dte_address_length", FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{ &hf_x25_dce_address_length,
{ "DCE address length", "x25.dce_address_length", FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{ &hf_x25_calling_address_length,
{ "Calling address length", "x25.calling_address_length", FT_UINT8, BASE_DEC, NULL, 0xF0,
NULL, HFILL }},
{ &hf_x25_called_address_length,
{ "Called address length", "x25.called_address_length", FT_UINT8, BASE_DEC, NULL, 0x0F,
NULL, HFILL }},
{ &hf_x25_facility_call_transfer_reason,
{ "Reason", "x25.facility.call_transfer_reason", FT_UINT8, BASE_DEC, VALS(x25_facilities_call_transfer_reason_vals), 0,
NULL, HFILL }},
{ &hf_x25_facility_monetary_unit,
{ "Monetary unit", "x25.facility.monetary_unit", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_nui,
{ "NUI", "x25.facility.nui", FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_cumulative_ete_transit_delay,
{ "Cumulative end-to-end transit delay (ms)", "x25.facility.cumulative_ete_transit_delay", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_requested_ete_transit_delay,
{ "Requested end-to-end transit delay (ms)", "x25.facility.requested_ete_transit_delay", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_max_acceptable_ete_transit_delay,
{ "Maximum acceptable end-to-end transit delay (ms)", "x25.facility.mac_acceptable_ete_transit_delay", FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_priority_data,
{ "Priority for data", "x25.facility.priority_data", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_priority_estab_conn,
{ "Priority for establishing connection", "x25.facility.priority_estab_conn", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_priority_keep_conn,
{ "Priority for keeping connection", "x25.facility.priority_keep_conn", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_min_acceptable_priority_data,
{ "Minimum acceptable priority for data", "x25.facility.min_acceptable_priority_data", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_min_acceptable_priority_estab_conn,
{ "Minimum acceptable priority for establishing connection", "x25.facility.min_acceptable_priority_estab_conn", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_min_acceptable_priority_keep_conn,
{ "Minimum acceptable priority for keeping connection", "x25.facility.min_acceptable_priority_keep_conn", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_classD_unknown,
{ "Parameter", "x25.facility.classD_unknown", FT_BYTES, BASE_NONE, NULL, 0,
"Facility Class D unknown parameter", HFILL }},
{ &hf_x25_facility_call_transfer_num_semi_octets,
{ "Number of semi-octets in DTE address", "x25.facility.call_transfer_num_semi_octets", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_calling_addr_ext_num_semi_octets,
{ "Number of semi-octets in DTE address", "x25.facility.calling_addr_ext_num_semi_octets", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_called_addr_ext_num_semi_octets,
{ "Number of semi-octets in DTE address", "x25.facility.called_addr_ext_num_semi_octets", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x25_facility_call_deflect_num_semi_octets,
{ "Number of semi-octets in the alternative DTE address", "x25.facility.call_deflect_num_semi_octets", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x264_length_indicator,
{ "X.264 length indicator", "x25.x264_length_indicator", FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_x264_un_tpdu_id,
{ "X.264 UN TPDU identifier", "x25.x264_un_tpdu_id", FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }},
{ &hf_x264_protocol_id,
{ "X.264 protocol identifier", "x25.x264_protocol_id", FT_UINT8, BASE_HEX, VALS(prt_id_vals), 0,
NULL, HFILL }},
{ &hf_x264_sharing_strategy,
{ "X.264 sharing strategy", "x25.x264_sharing_strategy", FT_UINT8, BASE_HEX, VALS(sharing_strategy_vals), 0,
NULL, HFILL }},
{ &hf_x263_sec_protocol_id,
{ "X.263 secondary protocol ID", "x25.x263_sec_protocol_id", FT_UINT8, BASE_HEX, VALS(nlpid_vals), 0,
NULL, HFILL }},
{ &hf_x25_reg_request_length,
{ "Registration length", "x25.reg_request_length", FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_x25_reg_confirm_length,
{ "Registration length", "x25.reg_confirm_length", FT_UINT8, BASE_DEC, NULL, 0x7F,
NULL, HFILL }},
{ &hf_x25_segment_overlap,
{ "Fragment overlap", "x25.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_x25_segment_overlap_conflict,
{ "Conflicting data in fragment overlap", "x25.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_x25_segment_multiple_tails,
{ "Multiple tail fragments found", "x25.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_x25_segment_too_long_segment,
{ "Fragment too long", "x25.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_x25_segment_error,
{ "Defragmentation error", "x25.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_x25_segment_count,
{ "Fragment count", "x25.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_x25_reassembled_length,
{ "Reassembled X.25 length", "x25.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_x25_segment,
{ "X.25 Fragment", "x25.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_x25_segments,
{ "X.25 Fragments", "x25.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_x25_fast_select,
{ "Fast select", "x25.fast_select", FT_UINT8, BASE_DEC, VALS(x25_fast_select_vals), 0xC0,
NULL, HFILL }},
{ &hf_x25_icrd,
{ "ICRD", "x25.icrd", FT_UINT8, BASE_DEC, VALS(x25_icrd_vals), 0x30,
NULL, HFILL }},
{ &hf_x25_reg_confirm_cause,
{ "Cause", "x25.reg_confirm.cause", FT_UINT8, BASE_DEC, VALS(x25_registration_code_vals), 0,
NULL, HFILL }},
{ &hf_x25_reg_confirm_diagnostic,
{ "Diagnostic", "x25.reg_confirm.diagnostic", FT_UINT8, BASE_DEC, VALS(x25_registration_code_vals), 0,
NULL, HFILL }},
{ &hf_x25_call_duration, { "Call duration", "x25.call_duration", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_segments_to_dte, { "Segments sent to DTE", "x25.segments_to_dte", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_segments_from_dte, { "Segments received from DTE", "x25.segments_from_dte", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_dte_address, { "DTE address", "x25.dte_address", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_data_network_identification_code, { "Data network identification code", "x25.data_network_identification_code", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_facility_call_deflect_reason, { "Reason", "x25.facility.call_deflect_reason", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_alternative_dte_address, { "Alternative DTE address", "x25.alternative_dte_address", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_dce_address, { "DCE address", "x25.dce_address", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_called_address, { "Called address", "x25.called_address", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_calling_address, { "Calling address", "x25.calling_address", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_clear_cause, { "Cause", "x25.clear_cause", FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(clear_code_rvals), 0x0, NULL, HFILL }},
{ &hf_x25_reset_cause, { "Cause", "x25.reset_cause", FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(reset_code_rvals), 0x0, NULL, HFILL }},
{ &hf_x25_restart_cause, { "Cause", "x25.restart_cause", FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(restart_code_rvals), 0x0, NULL, HFILL }},
{ &hf_x25_registration, { "Registration", "x25.registration", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_x25_user_data, { "User data", "x25.user_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_x25,
&ett_x25_gfi,
&ett_x25_facilities,
&ett_x25_facility,
&ett_x25_user_data,
&ett_x25_segment,
&ett_x25_segments
};
static ei_register_info ei[] = {
{ &ei_x25_facility_length, { "x25.facility_length.bogus", PI_PROTOCOL, PI_WARN, "Bogus length", EXPFILL }},
};
module_t *x25_module;
expert_module_t* expert_x25;
proto_x25 = proto_register_protocol ("X.25", "X.25", "x25");
proto_register_field_array (proto_x25, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_x25 = expert_register_protocol(proto_x25);
expert_register_field_array(expert_x25, ei, array_length(ei));
x25_subdissector_table = register_dissector_table("x.25.spi",
"X.25 secondary protocol identifier", proto_x25, FT_UINT8, BASE_HEX);
x25_heur_subdissector_list = register_heur_dissector_list("x.25", proto_x25);
register_dissector("x.25_dir", dissect_x25_dir, proto_x25);
register_dissector("x.25", dissect_x25, proto_x25);
x25_module = prefs_register_protocol(proto_x25, NULL);
prefs_register_obsolete_preference(x25_module, "non_q_bit_is_sna");
prefs_register_bool_preference(x25_module, "payload_is_qllc_sna",
"Default to QLLC/SNA",
"If CALL REQUEST not seen or didn't specify protocol, dissect as QLLC/SNA",
&payload_is_qllc_sna);
prefs_register_bool_preference(x25_module, "call_request_nodata_is_cotp",
"Assume COTP for Call Request without data",
"If CALL REQUEST has no data, assume the protocol handled is COTP",
&call_request_nodata_is_cotp);
prefs_register_bool_preference(x25_module, "payload_check_data",
"Check data for COTP/IP/CLNP",
"If CALL REQUEST not seen or didn't specify protocol, check user data before checking heuristic dissectors",
&payload_check_data);
prefs_register_bool_preference(x25_module, "reassemble",
"Reassemble fragmented X.25 packets",
"Reassemble fragmented X.25 packets",
&reassemble_x25);
register_init_routine(&x25_reassemble_init);
register_cleanup_routine(&x25_reassemble_cleanup);
}
void
proto_reg_handoff_x25(void)
{
dissector_handle_t x25_handle;
ip_handle = find_dissector_add_dependency("ip", proto_x25);
clnp_handle = find_dissector_add_dependency("clnp", proto_x25);
ositp_handle = find_dissector_add_dependency("ositp", proto_x25);
qllc_handle = find_dissector_add_dependency("qllc", proto_x25);
x25_handle = find_dissector("x.25");
dissector_add_uint("llc.dsap", SAP_X25, x25_handle);
dissector_add_uint("lapd.sapi", LAPD_SAPI_X25, x25_handle);
dissector_add_uint("ax25.pid", AX25_P_ROSE, x25_handle);
dissector_add_uint("sflow_245.header_protocol", SFLOW_245_HEADER_X25, x25_handle);
}
