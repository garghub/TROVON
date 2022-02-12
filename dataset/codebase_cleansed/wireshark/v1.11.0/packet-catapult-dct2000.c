static int skipASNLength(guint8 value)
{
if ((value & 0x80) == 0)
{
return 1;
}
else
{
return ((value & 0x03) == 1) ? 2 : 3;
}
}
static gboolean find_ipprim_data_offset(tvbuff_t *tvb, int *data_offset, guint8 direction,
guint32 *source_addr_offset, guint8 *source_addr_length,
guint32 *dest_addr_offset, guint8 *dest_addr_length,
guint32 *source_port_offset, guint32 *dest_port_offset,
port_type *type_of_port,
guint16 *conn_id_offset)
{
guint8 length;
int offset = *data_offset;
guint8 tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0x23:
case 0x24:
*type_of_port = PT_UDP;
break;
case 0x45:
case 0x46:
*type_of_port = PT_TCP;
break;
default:
return FALSE;
}
while (tvb_length_remaining(tvb, offset) > 2) {
tag = tvb_get_guint8(tvb, offset++);
if (((tag == 0x34) && (*type_of_port == PT_UDP)) ||
((tag == 0x48) && (*type_of_port == PT_TCP))) {
*data_offset = offset;
return TRUE;
}
else {
length = tvb_get_guint8(tvb, offset++);
if (tag == 0x31 && length >=4) {
if (direction == 0) {
*dest_addr_offset = offset;
*dest_addr_length = (length/4) * 4;
}
else {
*source_addr_offset = offset;
*source_addr_length = (length/4) * 4;
}
if ((length % 4) == 2) {
if (direction == 0) {
*dest_port_offset = offset + *dest_addr_length;
}
else {
*source_port_offset = offset + *source_addr_length;
}
}
}
else
if (tag == 0x32) {
if (length == 4 || length == 16) {
if (direction == 0) {
*source_addr_offset = offset;
*source_addr_length = length;
}
else {
*dest_addr_offset = offset;
*dest_addr_length = length;
}
}
}
else
if (tag == 0x33 && length == 2) {
if (direction == 0) {
*source_port_offset = offset;
}
else {
*dest_port_offset = offset;
}
}
else
if (tag == 0x36 && length == 2) {
*conn_id_offset = offset;
}
offset += length;
}
}
return FALSE;
}
static gboolean find_sctpprim_variant1_data_offset(tvbuff_t *tvb, int *data_offset,
guint32 *dest_addr_offset,
guint16 *dest_addr_length,
guint32 *dest_port_offset)
{
int offset = *data_offset;
guint8 first_tag = tvb_get_guint8(tvb, offset++);
guint8 tag;
guint8 first_length_byte;
switch (first_tag) {
case 0x04:
case 0x62:
break;
default:
return FALSE;
}
first_length_byte = tvb_get_guint8(tvb, offset);
offset += skipASNLength(first_length_byte);
while (tvb_length_remaining(tvb, offset) > 2) {
tag = tvb_get_guint8(tvb, offset++);
if (tag == 0x19) {
*data_offset = offset;
return TRUE;
}
else {
offset++;
switch (tag) {
case 0x0a:
*dest_port_offset = offset;
offset += 2;
break;
case 0x01:
case 0x1e:
case 0x0d:
offset += 2;
continue;
case 0x09:
*dest_addr_offset = offset;
*dest_addr_length = 4;
offset += 4;
break;
case 0x1d:
case 0x0c:
offset += 4;
continue;
default:
return FALSE;
}
}
}
return FALSE;
}
static gboolean find_sctpprim_variant3_data_offset(tvbuff_t *tvb, int *data_offset,
guint32 *dest_addr_offset,
guint16 *dest_addr_length,
guint32 *dest_port_offset)
{
guint16 tag = 0;
guint16 length = 0;
int offset = *data_offset;
guint16 top_tag = tvb_get_ntohs(tvb, offset);
offset += 2;
switch (top_tag) {
case 0x0400:
case 0x6200:
break;
default:
return FALSE;
}
offset += 2;
if (top_tag == 0x6200) {
offset += 2;
*dest_port_offset = offset;
offset += 2;
tag = tvb_get_ntohs(tvb, offset);
if (tag != 0x0900) {
return FALSE;
}
else {
offset += 2;
length = tvb_get_ntohs(tvb, offset) / 2;
if ((length != 4) && (length != 16))
{
return FALSE;
}
offset += 2;
*dest_addr_offset = offset;
*dest_addr_length = length;
offset += length;
}
if (tvb_reported_length_remaining(tvb, offset) > (4 + 2 + 2 + 4)) {
offset += (4 + 2 + 2 + 4);
}
else {
return FALSE;
}
tag = tvb_get_ntohs(tvb, offset);
offset += 2;
if (tag == 0x1900) {
offset += 2;
*data_offset = offset;
return TRUE;
}
else {
return FALSE;
}
}
else if (top_tag == 0x0400) {
tag = tvb_get_ntohs(tvb, offset);
if (tag != 0x2400) {
return FALSE;
}
else {
offset += 2;
offset += 2;
}
tag = tvb_get_ntohs(tvb, offset);
offset += 2;
while ((tag != 0x0c00) && (tvb_length_remaining(tvb, offset) > 4)) {
switch (tag) {
case 0x0900:
length = tvb_get_ntohs(tvb, offset) / 2;
if ((length != 4) && (length != 16)) {
return FALSE;
}
offset += 2;
*dest_addr_offset = offset;
*dest_addr_length = length;
offset += length;
break;
case 0x0a00:
*dest_port_offset = offset;
offset += 2;
break;
case 0x0d00:
*dest_port_offset = offset;
offset += 2;
break;
default:
return FALSE;
}
tag = tvb_get_ntohs(tvb, offset);
offset += 2;
}
if (tag != 0x0c00) {
return FALSE;
}
length = tvb_get_ntohs(tvb, offset) / 2;
offset += 2;
offset += length;
tag = tvb_get_ntohs(tvb, offset);
offset += 2;
if (tag == 0x0b00) {
length = tvb_get_ntohs(tvb, offset) / 2;
offset += 2;
offset += length;
tag = tvb_get_ntohs(tvb, offset);
offset += 2;
}
if (tag == 0x1900) {
offset += 2;
*data_offset = offset;
return TRUE;
}
else {
return FALSE;
}
}
return FALSE;
}
static void dissect_rlc_umts(tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree,
gboolean is_sent)
{
guint8 tag;
gboolean ueid_set = FALSE, rbid_set=FALSE;
guint32 ueid = 0;
guint8 rbid = 0;
guint8 length;
tvbuff_t *rlc_tvb;
dissector_handle_t rlc_umts_handle = 0;
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0xc0:
case 0xc1:
break;
default:
return;
}
while ((tag != 0x41) && tvb_length_remaining(tvb, offset)) {
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0x72:
ueid = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_catapult_dct2000_ueid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
ueid_set = TRUE;
break;
case 0xa2:
offset++;
rbid = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_catapult_dct2000_rbid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
rbid_set = TRUE;
break;
case 0x22:
offset++;
proto_tree_add_item(tree, hf_catapult_dct2000_ccch_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
rbid = 18;
break;
case 0xc4:
proto_tree_add_item(tree, hf_catapult_dct2000_no_crc_error, tvb, offset-1, 1, ENC_NA);
break;
case 0xc5:
proto_tree_add_item(tree, hf_catapult_dct2000_crc_error, tvb, offset-1, 1, ENC_NA);
break;
case 0xf7:
proto_tree_add_item(tree, hf_catapult_dct2000_clear_tx_buffer, tvb, offset-1, 1, ENC_NA);
break;
case 0x41:
offset += skipASNLength(tvb_get_guint8(tvb, offset));
break;
default:
length = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0x42:
proto_tree_add_item(tree, hf_catapult_dct2000_buffer_occupancy, tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 0x49:
proto_tree_add_item(tree, hf_catapult_dct2000_pdu_size, tvb, offset, 2, ENC_LITTLE_ENDIAN);
break;
case 0x47:
proto_tree_add_item(tree, hf_catapult_dct2000_ueid_type, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x4e:
proto_tree_add_item(tree, hf_catapult_dct2000_tx_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x4c:
proto_tree_add_item(tree, hf_catapult_dct2000_last_in_seg_set, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x43:
proto_tree_add_item(tree, hf_catapult_dct2000_rx_timing_deviation, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0x46:
proto_tree_add_item(tree, hf_catapult_dct2000_transport_channel_type, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 0xc2:
proto_tree_add_item(tree, hf_catapult_dct2000_no_padding_bits, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset += length;
}
}
if ((tag == 0x41) && ueid_set && rbid_set) {
attach_rlc_info(pinfo, ueid, rbid, is_sent);
switch (rbid) {
case 1: case 2: case 3: case 4: case 5:
case 6: case 7: case 8: case 9: case 10:
case 11: case 12: case 13: case 14: case 15:
rlc_umts_handle = find_dissector("rlc.dch_unknown");
break;
case 18:
rlc_umts_handle = find_dissector("rlc.ccch");
break;
case 21:
rlc_umts_handle = find_dissector("rlc.ctch");
break;
default:
return;
}
if (rlc_umts_handle != 0) {
rlc_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_only(rlc_umts_handle, rlc_tvb, pinfo, tree, NULL);
}
}
}
static void dissect_rrc_lte(tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree)
{
guint8 tag;
dissector_handle_t protocol_handle = 0;
gboolean isUplink = FALSE;
LogicalChannelType logicalChannelType;
guint16 cell_id;
guint8 bcch_transport = 0;
tvbuff_t *rrc_tvb;
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0x00:
case 0x04:
isUplink = TRUE;
break;
case 0x02:
case 0x03:
isUplink = FALSE;
break;
default:
return;
}
offset += skipASNLength(tvb_get_guint8(tvb, offset));
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0x12:
offset++;
logicalChannelType = Channel_DCCH;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ueid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0:
offset++;
col_append_fstr(pinfo->cinfo, COL_INFO, " SRB:%u",
tvb_get_guint8(tvb, offset));
proto_tree_add_item(tree, hf_catapult_dct2000_lte_srbid,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 1:
offset++;
col_append_fstr(pinfo->cinfo, COL_INFO, " DRB:%u",
tvb_get_guint8(tvb, offset));
proto_tree_add_item(tree, hf_catapult_dct2000_lte_drbid,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
default:
return;
}
break;
case 0x1a:
offset++;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_cellid,
tvb, offset, 2, ENC_BIG_ENDIAN);
cell_id = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_rlc_channel_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
logicalChannelType = (LogicalChannelType)tvb_get_guint8(tvb, offset);
offset++;
col_append_fstr(pinfo->cinfo, COL_INFO, " cell-id=%u %s",
cell_id,
val_to_str_const(logicalChannelType, rlc_logical_channel_vals,
"UNKNOWN-CHANNEL"));
switch (logicalChannelType) {
case Channel_BCCH:
offset++;
bcch_transport = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_catapult_dct2000_lte_bcch_transport,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case Channel_CCCH:
offset++;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ueid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
default:
break;
}
break;
default:
return;
}
tag = tvb_get_guint8(tvb, offset++);
if (tag != 0xaa) {
return;
}
offset += skipASNLength(tvb_get_guint8(tvb, offset));
if (isUplink) {
switch (logicalChannelType) {
case Channel_DCCH:
protocol_handle = find_dissector("lte_rrc.ul_dcch");
break;
case Channel_CCCH:
protocol_handle = find_dissector("lte_rrc.ul_ccch");
break;
default:
break;
}
} else {
switch (logicalChannelType) {
case Channel_DCCH:
protocol_handle = find_dissector("lte_rrc.dl_dcch");
break;
case Channel_CCCH:
protocol_handle = find_dissector("lte_rrc.dl_ccch");
break;
case Channel_PCCH:
protocol_handle = find_dissector("lte_rrc.pcch");
break;
case Channel_BCCH:
if (bcch_transport == 1) {
protocol_handle = find_dissector("lte_rrc.bcch_bch");
}
else {
protocol_handle = find_dissector("lte_rrc.bcch_dl_sch");
}
break;
default:
break;
}
}
if ((protocol_handle != NULL) && (tvb_length_remaining(tvb, offset) > 0)) {
rrc_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_only(protocol_handle, rrc_tvb, pinfo, tree, NULL);
}
}
static void dissect_ccpri_lte(tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree)
{
guint8 opcode;
guint8 tag;
tvbuff_t *ccpri_tvb;
dissector_handle_t protocol_handle = 0;
guint16 length;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ccpri_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
opcode = tvb_get_guint8(tvb, offset++);
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_cellid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (opcode == 2) {
proto_item *ti;
guint8 status = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(tree, hf_catapult_dct2000_lte_ccpri_status,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (status != 0) {
expert_add_info(pinfo, ti, &ei_catapult_dct2000_lte_ccpri_status_error);
}
}
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ccpri_channel,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
tag = tvb_get_guint8(tvb, offset++);
if (tag != 2) {
return;
}
length = tvb_get_ntohs(tvb, offset);
offset += 2;
protocol_handle = find_dissector("lapb");
if ((protocol_handle != NULL) && (tvb_length_remaining(tvb, offset) > 0)) {
ccpri_tvb = tvb_new_subset(tvb, offset, length, length);
call_dissector_only(protocol_handle, ccpri_tvb, pinfo, tree, NULL);
}
}
static void dissect_pdcp_lte(tvbuff_t *tvb, gint offset,
packet_info *pinfo, proto_tree *tree)
{
guint8 opcode;
guint8 tag;
struct pdcp_lte_info *p_pdcp_lte_info = NULL;
tvbuff_t *pdcp_lte_tvb;
guint16 ueid;
guint8 channelId;
p_pdcp_lte_info = (struct pdcp_lte_info *)p_get_proto_data(pinfo->fd, proto_pdcp_lte, 0);
if (p_pdcp_lte_info == NULL) {
return;
}
opcode = tvb_get_guint8(tvb, offset);
if (tree) {
proto_tree_add_item(tree, hf_catapult_dct2000_lte_rlc_op, tvb, offset, 1, ENC_BIG_ENDIAN);
}
offset++;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(opcode, rlc_op_vals, "Unknown"));
switch (opcode) {
case RLC_AM_DATA_REQ:
case RLC_UM_DATA_REQ:
case RLC_TR_DATA_REQ:
p_pdcp_lte_info->direction = DIRECTION_UPLINK;
break;
default:
p_pdcp_lte_info->direction = DIRECTION_DOWNLINK;
}
switch (opcode) {
case RLC_AM_DATA_REQ:
case RLC_AM_DATA_IND:
case RLC_UM_DATA_REQ:
case RLC_UM_DATA_IND:
case RLC_TR_DATA_REQ:
case RLC_TR_DATA_IND:
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0x10:
offset++;
p_pdcp_lte_info->channelType = Channel_DCCH;
ueid = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ueid, tvb, offset, 2, ENC_BIG_ENDIAN);
col_append_fstr(pinfo->cinfo, COL_INFO,
" UEId=%u", ueid);
p_pdcp_lte_info->ueid = ueid;
offset += 2;
tag = tvb_get_guint8(tvb, offset++);
switch (tag) {
case 0:
offset++;
channelId = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " SRB:%u",
channelId);
proto_tree_add_item(tree, hf_catapult_dct2000_lte_srbid,
tvb, offset++, 1, ENC_BIG_ENDIAN);
p_pdcp_lte_info->channelId = channelId;
break;
case 1:
offset++;
channelId = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " DRB:%u",
channelId);
proto_tree_add_item(tree, hf_catapult_dct2000_lte_drbid,
tvb, offset++, 1, ENC_BIG_ENDIAN);
p_pdcp_lte_info->channelId = channelId;
break;
default:
return;
}
break;
case 0x1a:
offset++;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_cellid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_rlc_channel_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
p_pdcp_lte_info->channelType = (LogicalChannelType)tvb_get_guint8(tvb, offset++);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_const(p_pdcp_lte_info->channelType, rlc_logical_channel_vals,
"UNKNOWN-CHANNEL"));
switch (p_pdcp_lte_info->channelType) {
case Channel_BCCH:
offset++;
p_pdcp_lte_info->BCCHTransport = (BCCHTransportType)tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_catapult_dct2000_lte_bcch_transport,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case Channel_CCCH:
offset++;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ueid,
tvb, offset, 2, ENC_BIG_ENDIAN);
ueid = tvb_get_ntohs(tvb, offset);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, " UEId=%u", ueid);
break;
default:
break;
}
break;
default:
return;
}
tag = tvb_get_guint8(tvb, offset++);
while ((tag != 0x41) && (tvb_length_remaining(tvb, offset) > 2)) {
if (tag == 0x35) {
offset++;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_rlc_mui,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if ((opcode == RLC_AM_DATA_REQ) || (opcode == RLC_AM_DATA_IND)) {
proto_tree_add_boolean(tree, hf_catapult_dct2000_lte_rlc_cnf,
tvb, offset, 1, tvb_get_guint8(tvb, offset));
offset++;
}
}
else if (tag == 0x45) {
offset++;
proto_tree_add_boolean(tree, hf_catapult_dct2000_lte_rlc_discard_req,
tvb, offset, 1, tvb_get_guint8(tvb, offset));
offset++;
}
tag = tvb_get_guint8(tvb, offset++);
}
pdcp_lte_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_only(pdcp_lte_handle, pdcp_lte_tvb, pinfo, tree, NULL);
break;
default:
return;
}
}
static dissector_handle_t look_for_dissector(const char *protocol_name)
{
if (strcmp(protocol_name, "tbcp") == 0) {
return find_dissector("rtcp");
}
else
if (strncmp(protocol_name, "diameter", strlen("diameter")) == 0) {
return find_dissector("diameter");
}
else
if ((strcmp(protocol_name, "xcap_caps") == 0) ||
(strcmp(protocol_name, "soap") == 0) ||
(strcmp(protocol_name, "mm1") == 0) ||
(strcmp(protocol_name, "mm3") == 0) ||
(strcmp(protocol_name, "mm7") == 0)) {
return find_dissector("http");
}
else
if ((strcmp(protocol_name, "fp") == 0) ||
(strncmp(protocol_name, "fp_r", 4) == 0) ||
(strcmp(protocol_name, "fpiur_r5") == 0)) {
return find_dissector("fp");
}
else
if ((strcmp(protocol_name, "iuup_rtp_r5") == 0) ||
(strcmp(protocol_name, "iuup_rtp_r6") == 0)) {
return find_dissector("rtp");
}
else
if (strcmp(protocol_name, "sipt") == 0) {
return find_dissector("sip");
}
else
if (strncmp(protocol_name, "nbap_sctp", strlen("nbap_sctp")) == 0) {
return find_dissector("nbap");
}
else
if (strncmp(protocol_name, "gtp", strlen("gtp")) == 0) {
return find_dissector("gtp");
}
else
if (strcmp(protocol_name, "dhcpv4") == 0) {
return find_dissector("bootp");
}
else
if (strcmp(protocol_name, "wimax") == 0) {
return find_dissector("wimaxasncp");
}
else
if (strncmp(protocol_name, "sabp", strlen("sabp")) == 0) {
return find_dissector("sabp");
}
else
if (strcmp(protocol_name, "wtp") == 0) {
return find_dissector("wtp-udp");
}
else
if (catapult_dct2000_dissect_lte_s1ap &&
strncmp(protocol_name, "s1ap", strlen("s1ap")) == 0) {
return find_dissector("s1ap");
}
else
if ((strncmp(protocol_name, "x2ap_r8_lte", strlen("x2ap_r8_lte")) == 0) ||
(strncmp(protocol_name, "x2ap_r9_lte", strlen("x2ap_r9_lte")) == 0)) {
return find_dissector("x2ap");
}
else
if ((strcmp(protocol_name, "gtpv2_r8_lte") == 0) ||
(strcmp(protocol_name, "gtpv2_r9_lte") == 0)) {
return find_dissector("gtpv2");
}
else {
return find_dissector(protocol_name);
}
}
static void parse_outhdr_string(const guchar *outhdr_string, gint outhdr_string_len)
{
int n = 0;
for (outhdr_values_found=0; outhdr_values_found < MAX_OUTHDR_VALUES; ) {
guint digit_array[MAX_OUTHDR_VALUES];
guint number_digits = 0;
guint number = 0;
guint multiplier = 1;
guint d;
for ( ; n < outhdr_string_len; n++) {
if (!isdigit(outhdr_string[n])) {
break;
}
else {
digit_array[number_digits++] = outhdr_string[n] - '0';
}
}
if (number_digits == 0) {
break;
}
for (d=number_digits; d > 0; d--) {
number += ((digit_array[d-1]) * multiplier);
multiplier *= 10;
}
outhdr_values[outhdr_values_found++] = number;
n++;
}
}
static void attach_fp_info(packet_info *pinfo, gboolean received, const char *protocol_name, int variant)
{
int i=0;
int chan;
int tf_start, num_chans_start;
gint node_type;
int calculated_variant;
struct fp_info *p_fp_info = (struct fp_info *)p_get_proto_data(pinfo->fd, proto_fp, 0);
if (p_fp_info != NULL) {
return;
}
p_fp_info = wmem_new0(wmem_file_scope(), struct fp_info);
if (((strcmp(protocol_name, "fpiur_r5") == 0) && (outhdr_values_found != 2)) ||
(outhdr_values_found < 5)) {
return;
}
if (strcmp(protocol_name, "fp") == 0) {
p_fp_info->release = 99;
}
else if (strcmp(protocol_name, "fp_r4") == 0) {
p_fp_info->release = 4;
}
else if (strcmp(protocol_name, "fp_r5") == 0) {
p_fp_info->release = 5;
}
else if (strcmp(protocol_name, "fp_r6") == 0) {
p_fp_info->release = 6;
}
else if (strcmp(protocol_name, "fp_r7") == 0) {
p_fp_info->release = 7;
}
else if (strcmp(protocol_name, "fp_r8") == 0) {
p_fp_info->release = 8;
}
else if (strcmp(protocol_name, "fpiur_r5") == 0) {
p_fp_info->release = 5;
}
else {
DISSECTOR_ASSERT_NOT_REACHED();
return;
}
switch (p_fp_info->release) {
case 6:
if (variant < 256) {
calculated_variant = variant;
}
else {
calculated_variant = variant / 256;
}
switch (calculated_variant) {
case 1:
p_fp_info->release_year = 2005;
p_fp_info->release_month = 6;
break;
case 2:
p_fp_info->release_year = 2005;
p_fp_info->release_month = 9;
break;
case 3:
default:
p_fp_info->release_year = 2006;
p_fp_info->release_month = 3;
break;
}
break;
case 7:
p_fp_info->release_year = 2008;
p_fp_info->release_month = 3;
break;
case 8:
p_fp_info->release_year = 2010;
p_fp_info->release_month = 6;
break;
default:
p_fp_info->release_year = 0;
p_fp_info->release_month = 0;
}
p_fp_info->channel = outhdr_values[i++];
if (p_fp_info->channel == 0) {
p_fp_info->channel = CHANNEL_DCH;
}
node_type = outhdr_values[i++];
p_fp_info->is_uplink = (( received && (node_type == 2)) ||
(!received && (node_type == 1)));
if ((p_fp_info->release == 7) ||
(p_fp_info->release == 8)) {
p_fp_info->division = (enum division_type)outhdr_values[i++];
}
if (p_fp_info->channel == CHANNEL_HSDSCH) {
if ((p_fp_info->release == 7) ||
(p_fp_info->release == 8)) {
if (outhdr_values[i++]) {
p_fp_info->hsdsch_entity = ehs;
}
}
else {
p_fp_info->hsdsch_entity = hs;
}
}
if (strcmp(protocol_name, "fpiur_r5") == 0) {
p_fp_info->iface_type = IuR_Interface;
p_add_proto_data(pinfo->fd, proto_fp, 0, p_fp_info);
return;
}
p_fp_info->dch_crc_present = outhdr_values[i++];
if (p_fp_info->channel == CHANNEL_EDCH) {
p_fp_info->dch_crc_present = 2;
}
p_fp_info->paging_indications = outhdr_values[i++];
p_fp_info->num_chans = outhdr_values[i++];
if (p_fp_info->channel == CHANNEL_EDCH_COMMON) {
p_fp_info->edch_type = 1;
}
if (p_fp_info->channel != CHANNEL_EDCH) {
tf_start = i;
for (chan=0; chan < p_fp_info->num_chans; chan++) {
p_fp_info->chan_tf_size[chan] = outhdr_values[tf_start+chan];
}
num_chans_start = tf_start + p_fp_info->num_chans;
for (chan=0; chan < p_fp_info->num_chans; chan++) {
p_fp_info->chan_num_tbs[chan] = outhdr_values[num_chans_start+chan];
}
}
else {
int n;
p_fp_info->no_ddi_entries = outhdr_values[i++];
for (n=0; n < p_fp_info->no_ddi_entries; n++) {
p_fp_info->edch_ddi[n] = outhdr_values[i++];
}
for (n=0; n < p_fp_info->no_ddi_entries; n++) {
p_fp_info->edch_macd_pdu_size[n] = outhdr_values[i++];
}
if (strcmp(protocol_name, "fp_r8") == 0) {
p_fp_info->edch_type = outhdr_values[i];
}
else {
p_fp_info->edch_type = 0;
}
}
p_fp_info->iface_type = IuB_Interface;
p_add_proto_data(pinfo->fd, proto_fp, 0, p_fp_info);
}
static void attach_rlc_info(packet_info *pinfo, guint32 urnti, guint8 rbid, gboolean is_sent)
{
struct fp_info *p_fp_info;
struct rlc_info *p_rlc_info = (struct rlc_info *)p_get_proto_data(pinfo->fd, proto_rlc, 0);
if (p_rlc_info != NULL) {
return;
}
if (outhdr_values_found != 2) {
return;
}
p_rlc_info = wmem_new(wmem_file_scope(), struct rlc_info);
p_fp_info = wmem_new(wmem_file_scope(), struct fp_info);
p_rlc_info->urnti[0] = urnti;
p_rlc_info->ciphered[0] = FALSE;
p_rlc_info->deciphered[0] = FALSE;
switch (outhdr_values[1]) {
case 1:
p_rlc_info->mode[0] = RLC_TM;
break;
case 2:
p_rlc_info->mode[0] = RLC_UM;
break;
case 3:
p_rlc_info->mode[0] = RLC_AM;
break;
case 4:
p_rlc_info->mode[0] = RLC_UM;
p_rlc_info->ciphered[0] = TRUE;
break;
case 5:
p_rlc_info->mode[0] = RLC_AM;
p_rlc_info->ciphered[0] = TRUE;
break;
default:
return;
}
p_rlc_info->rbid[0] = rbid;
p_rlc_info->li_size[0] = (enum rlc_li_size)outhdr_values[0];
p_add_proto_data(pinfo->fd, proto_rlc, 0, p_rlc_info);
p_fp_info->is_uplink = is_sent;
p_fp_info->cur_tb = 0;
p_add_proto_data(pinfo->fd, proto_fp, 0, p_fp_info);
}
static void attach_mac_lte_info(packet_info *pinfo)
{
struct mac_lte_info *p_mac_lte_info;
unsigned int i = 0;
p_mac_lte_info = get_mac_lte_proto_data(pinfo);
if (p_mac_lte_info != NULL) {
return;
}
p_mac_lte_info = wmem_new0(wmem_file_scope(), struct mac_lte_info);
p_mac_lte_info->crcStatusValid = crc_fail;
p_mac_lte_info->radioType = outhdr_values[i++] + 1;
p_mac_lte_info->rntiType = outhdr_values[i++];
p_mac_lte_info->direction = outhdr_values[i++];
if (p_mac_lte_info->direction == DIRECTION_UPLINK) {
p_mac_lte_info->detailed_phy_info.ul_info.present = FALSE;
}
else {
p_mac_lte_info->detailed_phy_info.dl_info.present = FALSE;
}
p_mac_lte_info->subframeNumber = outhdr_values[i++];
p_mac_lte_info->isPredefinedData = outhdr_values[i++];
p_mac_lte_info->rnti = outhdr_values[i++];
p_mac_lte_info->ueid = outhdr_values[i++];
p_mac_lte_info->length = outhdr_values[i++];
if (outhdr_values_found > 8) {
p_mac_lte_info->reTxCount = outhdr_values[i++];
}
if (outhdr_values_found == 10) {
if (p_mac_lte_info->direction == DIRECTION_DOWNLINK) {
p_mac_lte_info->crcStatusValid = crc_success;
p_mac_lte_info->detailed_phy_info.dl_info.crc_status = (mac_lte_crc_status)outhdr_values[i++];
}
else {
i++;
}
}
p_mac_lte_info->dl_retx = dl_retx_unknown;
if (outhdr_values_found > 10) {
if (p_mac_lte_info->direction == DIRECTION_DOWNLINK) {
p_mac_lte_info->detailed_phy_info.dl_info.present = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.dl_info.dci_format = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.dl_info.resource_allocation_type = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.dl_info.aggregation_level = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.dl_info.mcs_index = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.dl_info.redundancy_version_index = outhdr_values[i++];
if (outhdr_values[i++]) {
p_mac_lte_info->dl_retx = dl_retx_yes;
}
else {
p_mac_lte_info->dl_retx = dl_retx_no;
}
p_mac_lte_info->detailed_phy_info.dl_info.resource_block_length = outhdr_values[i++];
p_mac_lte_info->crcStatusValid = crc_success;
p_mac_lte_info->detailed_phy_info.dl_info.crc_status = (mac_lte_crc_status)outhdr_values[i++];
if (outhdr_values_found > 18) {
p_mac_lte_info->detailed_phy_info.dl_info.harq_id = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.dl_info.ndi = outhdr_values[i++];
}
if (outhdr_values_found > 20) {
p_mac_lte_info->detailed_phy_info.dl_info.transport_block = outhdr_values[i++];
}
}
else {
p_mac_lte_info->detailed_phy_info.ul_info.present = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.ul_info.modulation_type = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.ul_info.tbs_index = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.ul_info.resource_block_length = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.ul_info.resource_block_start = outhdr_values[i++];
i++;
if (outhdr_values_found == 16) {
p_mac_lte_info->subframeNumberOfGrantPresent = TRUE;
p_mac_lte_info->subframeNumberOfGrant = outhdr_values[i++];
}
if (outhdr_values_found > 16) {
p_mac_lte_info->detailed_phy_info.ul_info.harq_id = outhdr_values[i++];
p_mac_lte_info->detailed_phy_info.ul_info.ndi = outhdr_values[i++];
p_mac_lte_info->subframeNumberOfGrantPresent = TRUE;
p_mac_lte_info->subframeNumberOfGrant = outhdr_values[i++];
}
}
}
if (i < outhdr_values_found) {
p_mac_lte_info->sysframeNumber = outhdr_values[i++];
}
if ((p_mac_lte_info->direction == DIRECTION_UPLINK) &&
(i < outhdr_values_found)) {
p_mac_lte_info->isPHICHNACK = outhdr_values[i];
}
if (p_mac_lte_info->direction == DIRECTION_UPLINK) {
p_mac_lte_info->isExtendedBSRSizes = FALSE;
}
set_mac_lte_proto_data(pinfo, p_mac_lte_info);
}
static void attach_rlc_lte_info(packet_info *pinfo)
{
struct rlc_lte_info *p_rlc_lte_info;
unsigned int i = 0;
p_rlc_lte_info = (rlc_lte_info *)p_get_proto_data(pinfo->fd, proto_rlc_lte, 0);
if (p_rlc_lte_info != NULL) {
return;
}
p_rlc_lte_info = wmem_new0(wmem_file_scope(), rlc_lte_info);
p_rlc_lte_info->rlcMode = outhdr_values[i++];
p_rlc_lte_info->direction = outhdr_values[i++];
p_rlc_lte_info->priority = outhdr_values[i++];
p_rlc_lte_info->UMSequenceNumberLength = outhdr_values[i++];
p_rlc_lte_info->channelId = outhdr_values[i++];
p_rlc_lte_info->channelType = outhdr_values[i++];
p_rlc_lte_info->ueid = outhdr_values[i++];
p_rlc_lte_info->pduLength = outhdr_values[i];
p_add_proto_data(pinfo->fd, proto_rlc_lte, 0, p_rlc_lte_info);
}
static void attach_pdcp_lte_info(packet_info *pinfo)
{
struct pdcp_lte_info *p_pdcp_lte_info;
unsigned int i = 0;
p_pdcp_lte_info = (pdcp_lte_info *)p_get_proto_data(pinfo->fd, proto_pdcp_lte, 0);
if (p_pdcp_lte_info != NULL) {
return;
}
p_pdcp_lte_info = wmem_new0(wmem_file_scope(), pdcp_lte_info);
p_pdcp_lte_info->no_header_pdu = outhdr_values[i++];
p_pdcp_lte_info->plane = (enum pdcp_plane)outhdr_values[i++];
if (p_pdcp_lte_info->plane != USER_PLANE) {
p_pdcp_lte_info->plane = SIGNALING_PLANE;
}
p_pdcp_lte_info->seqnum_length = outhdr_values[i++];
p_pdcp_lte_info->rohc_compression = outhdr_values[i++];
p_pdcp_lte_info->rohc_ip_version = outhdr_values[i++];
p_pdcp_lte_info->cid_inclusion_info = outhdr_values[i++];
p_pdcp_lte_info->large_cid_present = outhdr_values[i++];
p_pdcp_lte_info->mode = (enum rohc_mode)outhdr_values[i++];
p_pdcp_lte_info->rnd = outhdr_values[i++];
p_pdcp_lte_info->udp_checksum_present = outhdr_values[i++];
p_pdcp_lte_info->profile = outhdr_values[i];
p_add_proto_data(pinfo->fd, proto_pdcp_lte, 0, p_pdcp_lte_info);
}
static void dissect_tty_lines(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
gint next_offset;
proto_tree *tty_tree;
proto_item *ti;
int lines = 0;
ti = proto_tree_add_item(tree, hf_catapult_dct2000_tty, tvb, offset, -1, ENC_NA);
tty_tree = proto_item_add_subtree(ti, ett_catapult_dct2000_tty);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
int linelen = tvb_find_line_end_unquoted(tvb, offset, -1, &next_offset);
char *string = (char*)tvb_get_string(wmem_packet_scope(), tvb, offset, linelen);
if (isascii(string[0])) {
proto_tree_add_string_format(tty_tree, hf_catapult_dct2000_tty_line,
tvb, offset,
linelen, string,
"%s", string);
}
else {
int n, idx;
char *hex_string;
int tty_string_length = tvb_length_remaining(tvb, offset);
int hex_string_length = 1+(2*tty_string_length)+1;
hex_string = (char *)wmem_alloc(wmem_packet_scope(), hex_string_length);
idx = g_snprintf(hex_string, hex_string_length, "$");
for (n=0; n < tty_string_length; n++) {
idx += g_snprintf(hex_string+idx, 3, "%02x",
tvb_get_guint8(tvb, offset+n));
}
string = hex_string;
}
lines++;
if (lines == 1) {
col_append_fstr(pinfo->cinfo, COL_INFO, "tty (%s", string);
proto_item_append_text(ti, " (%s)", string);
}
offset = next_offset;
}
if (lines != 0) {
col_append_str(pinfo->cinfo, COL_INFO, (lines > 1) ? "...)" : ")");
}
}
static void check_for_oob_mac_lte_events(packet_info *pinfo, tvbuff_t *tvb, proto_tree *tree,
const char *string)
{
guint number_of_ues;
guint ueids[MAX_SRs];
guint rntis[MAX_SRs];
guint rapid;
guint rach_attempt_number;
guint temp;
mac_lte_oob_event oob_event;
struct mac_lte_info *p_mac_lte_info;
tvbuff_t *mac_lte_tvb = NULL;
guint16 n;
if (sscanf(string, ">> RACH Preamble Request[UE = %u] [RAPID = %u] [Attempt = %u]",
&ueids[0], &rapid, &rach_attempt_number) == 3) {
oob_event = ltemac_send_preamble;
}
else
if (sscanf(string, ">> Schedule Requests (%u) [UE=%u][RNTI=%u]",
&number_of_ues, &ueids[0], &rntis[0]) == 3) {
const char *current_position;
oob_event = ltemac_send_sr;
number_of_ues = MIN(number_of_ues, MAX_SRs);
if (number_of_ues > 1) {
current_position = string;
for (n=1; n < number_of_ues; n++) {
current_position = strstr(current_position, "] ");
if (current_position != NULL) {
current_position += 2;
}
else {
return;
}
if (sscanf(current_position, "[UE=%u][RNTI=%u]", &ueids[n], &rntis[n]) != 2) {
number_of_ues = n;
break;
}
}
}
}
else
if ((sscanf(string, ">> INFO (inst %u) MAC: [UE = %u] SR failed (CRNTI=%u)",
&temp, &ueids[0], &rntis[0]) == 3) ||
(sscanf(string, ">> INFO MAC: SR failed for UE %u (CRNTI=%u",
&ueids[0], &rntis[0]) == 2))
{
oob_event = ltemac_sr_failure;
}
else {
return;
}
p_mac_lte_info = get_mac_lte_proto_data(pinfo);
if (p_mac_lte_info == NULL) {
p_mac_lte_info = wmem_new0(wmem_file_scope(), mac_lte_info);
p_mac_lte_info->length = 0;
switch (oob_event) {
case ltemac_send_preamble:
p_mac_lte_info->ueid = ueids[0];
p_mac_lte_info->rapid = rapid;
p_mac_lte_info->rach_attempt_number = rach_attempt_number;
p_mac_lte_info->direction = DIRECTION_UPLINK;
break;
case ltemac_send_sr:
for (n=0; n < number_of_ues; n++) {
p_mac_lte_info->oob_ueid[n] = ueids[n];
p_mac_lte_info->oob_rnti[n] = rntis[n];
}
p_mac_lte_info->number_of_srs = number_of_ues;
p_mac_lte_info->direction = DIRECTION_UPLINK;
break;
case ltemac_sr_failure:
p_mac_lte_info->rnti = rntis[0];
p_mac_lte_info->ueid = ueids[0];
p_mac_lte_info->direction = DIRECTION_DOWNLINK;
break;
}
p_mac_lte_info->radioType = FDD_RADIO;
p_mac_lte_info->oob_event = oob_event;
set_mac_lte_proto_data(pinfo, p_mac_lte_info);
}
mac_lte_tvb = tvb_new_subset(tvb, 0, 0, 0);
call_dissector_only(mac_lte_handle, mac_lte_tvb, pinfo, tree, NULL);
}
static void
dissect_catapult_dct2000(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *dct2000_tree = NULL;
proto_item *ti = NULL;
gint offset = 0;
gint context_length;
const char *context_name;
guint8 port_number;
gint protocol_length;
gint timestamp_length;
const char *timestamp_string;
gint variant_length;
const char *variant_string;
gint outhdr_length;
const char *outhdr_string;
guint8 direction;
tvbuff_t *next_tvb;
int encap;
dissector_handle_t protocol_handle = 0;
dissector_handle_t heur_protocol_handle = 0;
int sub_dissector_result = 0;
const char *protocol_name;
gboolean is_comment, is_sprint = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DCT2000");
col_clear(pinfo->cinfo, COL_INFO);
if (tree) {
ti = proto_tree_add_item(tree, proto_catapult_dct2000, tvb, offset, -1, ENC_NA);
dct2000_tree = proto_item_add_subtree(ti, ett_catapult_dct2000);
}
context_name = tvb_get_const_stringz(tvb, offset, &context_length);
if (dct2000_tree) {
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_context, tvb,
offset, context_length, ENC_ASCII|ENC_NA);
}
offset += context_length;
port_number = tvb_get_guint8(tvb, offset);
if (dct2000_tree) {
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_port_number, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
offset++;
timestamp_string = tvb_get_const_stringz(tvb, offset, &timestamp_length);
if (dct2000_tree) {
proto_tree_add_double(dct2000_tree, hf_catapult_dct2000_timestamp, tvb,
offset, timestamp_length,
atof(timestamp_string));
}
offset += timestamp_length;
protocol_name = tvb_get_const_stringz(tvb, offset, &protocol_length);
if (dct2000_tree) {
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_protocol, tvb,
offset, protocol_length, ENC_ASCII|ENC_NA);
}
is_comment = (strcmp(protocol_name, "comment") == 0);
if (!is_comment) {
is_sprint = (strcmp(protocol_name, "sprint") == 0);
}
offset += protocol_length;
variant_string = tvb_get_const_stringz(tvb, offset, &variant_length);
if (!is_comment && !is_sprint) {
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_variant, tvb,
offset, variant_length, ENC_ASCII|ENC_NA);
}
offset += variant_length;
outhdr_string = tvb_get_const_stringz(tvb, offset, &outhdr_length);
if (!is_comment && !is_sprint && (outhdr_length > 1)) {
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_outhdr, tvb,
offset, outhdr_length, ENC_ASCII|ENC_NA);
}
offset += outhdr_length;
direction = tvb_get_guint8(tvb, offset);
if (dct2000_tree) {
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_direction, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
offset++;
if (!is_comment && !is_sprint) {
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_encap, tvb, offset, 1, ENC_BIG_ENDIAN);
}
encap = tvb_get_guint8(tvb, offset);
offset++;
proto_item_append_text(ti, " context=%s.%u t=%s %c prot=%s (v=%s)",
context_name,
port_number,
timestamp_string,
(direction == 0) ? 'S' : 'R',
protocol_name,
variant_string);
if ((strcmp(protocol_name, "fp") == 0) ||
(strncmp(protocol_name, "fp_r", 4) == 0) ||
(strcmp(protocol_name, "fpiur_r5") == 0)) {
parse_outhdr_string(outhdr_string, outhdr_length);
attach_fp_info(pinfo, direction, protocol_name, atoi(variant_string));
}
else if ((strcmp(protocol_name, "rlc") == 0) ||
(strcmp(protocol_name, "rlc_r4") == 0) ||
(strcmp(protocol_name, "rlc_r5") == 0) ||
(strcmp(protocol_name, "rlc_r6") == 0) ||
(strcmp(protocol_name, "rlc_r7") == 0) ||
(strcmp(protocol_name, "rlc_r8") == 0) ||
(strcmp(protocol_name, "rlc_r9") == 0)) {
parse_outhdr_string(outhdr_string, outhdr_length);
}
else if ((strcmp(protocol_name, "mac_r8_lte") == 0) ||
(strcmp(protocol_name, "mac_r9_lte") == 0) ||
(strcmp(protocol_name, "mac_r10_lte") == 0)) {
parse_outhdr_string(outhdr_string, outhdr_length);
attach_mac_lte_info(pinfo);
}
else if ((strcmp(protocol_name, "rlc_r8_lte") == 0) ||
(strcmp(protocol_name, "rlc_r9_lte") == 0) ||
(strcmp(protocol_name, "rlc_r10_lte") == 0)) {
parse_outhdr_string(outhdr_string, outhdr_length);
attach_rlc_lte_info(pinfo);
}
else if ((strcmp(protocol_name, "pdcp_r8_lte") == 0) ||
(strcmp(protocol_name, "pdcp_r9_lte") == 0) ||
(strcmp(protocol_name, "pdcp_r10_lte") == 0)) {
parse_outhdr_string(outhdr_string, outhdr_length);
attach_pdcp_lte_info(pinfo);
}
else if ((strcmp(protocol_name, "nas_rrc_r8_lte") == 0) ||
(strcmp(protocol_name, "nas_rrc_r9_lte") == 0) ||
(strcmp(protocol_name, "nas_rrc_r10_lte") == 0)) {
gboolean nas_body_found = TRUE;
guint8 opcode = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_catapult_dct2000_lte_nas_rrc_opcode,
tvb, offset++, 1, ENC_BIG_ENDIAN);
offset++;
switch (opcode) {
case LTE_NAS_RRC_DATA_IND:
case LTE_NAS_RRC_DATA_REQ:
offset++;
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ueid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
break;
case LTE_NAS_RRC_ESTABLISH_REQ:
offset++;
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ueid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_nas_rrc_establish_cause,
tvb, offset++, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_nas_rrc_priority,
tvb, offset++, 1, ENC_BIG_ENDIAN);
break;
case LTE_NAS_RRC_RELEASE_IND:
offset++;
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_ueid,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset += 2;
proto_tree_add_item(tree, hf_catapult_dct2000_lte_nas_rrc_release_cause,
tvb, offset++, 1, ENC_BIG_ENDIAN);
break;
default:
nas_body_found = FALSE;
break;
}
if (nas_body_found) {
offset += 2;
protocol_handle = find_dissector("nas-eps");
}
}
switch (encap) {
case WTAP_ENCAP_RAW_IP:
protocol_handle = find_dissector("ip");
#if 0
if ((pinfo->pseudo_header != NULL) &&
(pinfo->pseudo_header->dct2000.inner_pseudo_header.pdcp.ueid != 0)) {
proto_item *ti;
ti = proto_tree_add_uint(dct2000_tree, hf_catapult_dct2000_lte_ueid, tvb, 0, 0,
pinfo->pseudo_header->dct2000.inner_pseudo_header.pdcp.ueid);
PROTO_ITEM_SET_GENERATED(ti);
ti = proto_tree_add_uint(dct2000_tree, hf_catapult_dct2000_lte_drbid, tvb, 0, 0,
pinfo->pseudo_header->dct2000.inner_pseudo_header.pdcp.drbid);
PROTO_ITEM_SET_GENERATED(ti);
}
#endif
break;
case WTAP_ENCAP_ETHERNET:
protocol_handle = find_dissector("eth_withoutfcs");
break;
case WTAP_ENCAP_ISDN:
protocol_handle = find_dissector("lapd");
pinfo->p2p_dir = pinfo->pseudo_header->isdn.uton;
break;
case WTAP_ENCAP_ATM_PDUS_UNTRUNCATED:
protocol_handle = find_dissector("atm_untruncated");
break;
case WTAP_ENCAP_PPP:
protocol_handle = find_dissector("ppp_hdlc");
pinfo->p2p_dir = pinfo->pseudo_header->p2p.sent;
break;
case DCT2000_ENCAP_SSCOP:
protocol_handle = find_dissector("sscop");
break;
case WTAP_ENCAP_FRELAY:
protocol_handle = find_dissector("fr");
break;
case DCT2000_ENCAP_MTP2:
protocol_handle = find_dissector("mtp2");
break;
case DCT2000_ENCAP_NBAP:
protocol_handle = find_dissector("nbap");
break;
case DCT2000_ENCAP_UNHANDLED:
if (direction == 0) {
col_add_fstr(pinfo->cinfo, COL_DEF_SRC,
"%s.%u",
context_name,
port_number);
}
else
if (direction == 1) {
col_add_fstr(pinfo->cinfo, COL_DEF_DST,
"%s.%u",
context_name,
port_number);
}
if ((strcmp(protocol_name, "rlc") == 0) ||
(strcmp(protocol_name, "rlc_r4") == 0) ||
(strcmp(protocol_name, "rlc_r5") == 0) ||
(strcmp(protocol_name, "rlc_r6") == 0) ||
(strcmp(protocol_name, "rlc_r7") == 0) ||
(strcmp(protocol_name, "rlc_r8") == 0) ||
(strcmp(protocol_name, "rlc_r9") == 0)) {
dissect_rlc_umts(tvb, offset, pinfo, tree, direction);
return;
}
else
if ((strcmp(protocol_name, "mac_r8_lte") == 0) ||
(strcmp(protocol_name, "mac_r9_lte") == 0) ||
(strcmp(protocol_name, "mac_r10_lte") == 0)) {
protocol_handle = mac_lte_handle;
}
else
if ((strcmp(protocol_name, "rlc_r8_lte") == 0) ||
(strcmp(protocol_name, "rlc_r9_lte") == 0) ||
(strcmp(protocol_name, "rlc_r10_lte") == 0)) {
protocol_handle = rlc_lte_handle;
}
else
if ((strcmp(protocol_name, "pdcp_r8_lte") == 0) ||
(strcmp(protocol_name, "pdcp_r9_lte") == 0) ||
(strcmp(protocol_name, "pdcp_r10_lte") == 0)) {
dissect_pdcp_lte(tvb, offset, pinfo, tree);
return;
}
else
if (strcmp(protocol_name, "xml") == 0) {
protocol_handle = find_dissector("xml");
}
else
if (strcmp(protocol_name, "tty") == 0) {
dissect_tty_lines(tvb, pinfo, dct2000_tree, offset);
return;
}
else
if (strcmp(protocol_name, "sipprim") == 0) {
protocol_handle = find_dissector("sipprim");
}
else
if (strcmp(protocol_name, "comment") == 0) {
proto_item *string_ti;
char *string = (char*)tvb_get_string(wmem_packet_scope(), tvb, offset, tvb_length_remaining(tvb, offset));
string_ti = proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_comment, tvb,
offset, -1, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", string);
if (catapult_dct2000_dissect_mac_lte_oob_messages) {
check_for_oob_mac_lte_events(pinfo, tvb, tree, string);
}
if (strncmp(string, ">> ERR", 6) == 0) {
proto_item *error_ti = proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_error_comment, tvb,
offset, -1, ENC_NA);
PROTO_ITEM_SET_GENERATED(error_ti);
expert_add_info_format(pinfo, string_ti, &ei_catapult_dct2000_error_comment_expert,
"%s", string);
}
return;
}
else
if (strcmp(protocol_name, "sprint") == 0) {
char *string = (char*)tvb_get_string(wmem_packet_scope(), tvb, offset, tvb_length_remaining(tvb, offset));
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_sprint, tvb,
offset, -1, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", string);
return;
}
else
if (catapult_dct2000_dissect_lte_rrc &&
((strcmp(protocol_name, "rrc_r8_lte") == 0) ||
(strcmp(protocol_name, "rrcpdcpprim_r8_lte") == 0) ||
(strcmp(protocol_name, "rrc_r9_lte") == 0) ||
(strcmp(protocol_name, "rrcpdcpprim_r9_lte") == 0) ||
(strcmp(protocol_name, "rrc_r10_lte") == 0))) {
dissect_rrc_lte(tvb, offset, pinfo, tree);
return;
}
else
if ((strcmp(protocol_name, "ccpri_r8_lte") == 0) ||
(strcmp(protocol_name, "ccpri_r9_lte") == 0)) {
dissect_ccpri_lte(tvb, offset, pinfo, tree);
return;
}
if (!protocol_handle && catapult_dct2000_try_ipprim_heuristic) {
guint32 source_addr_offset = 0, dest_addr_offset = 0;
guint8 source_addr_length = 0, dest_addr_length = 0;
guint32 source_port_offset = 0, dest_port_offset = 0;
port_type type_of_port = PT_NONE;
guint16 conn_id_offset = 0;
int offset_before_ipprim_header = offset;
heur_protocol_handle = look_for_dissector(protocol_name);
if ((heur_protocol_handle != 0) &&
find_ipprim_data_offset(tvb, &offset, direction,
&source_addr_offset, &source_addr_length,
&dest_addr_offset, &dest_addr_length,
&source_port_offset, &dest_port_offset,
&type_of_port,
&conn_id_offset)) {
proto_tree *ipprim_tree;
proto_item *ipprim_ti;
struct e_in6_addr sourcev6, destv6;
if (source_addr_length != 4) {
tvb_get_ipv6(tvb, source_addr_offset, &sourcev6);
}
if (dest_addr_length != 4) {
tvb_get_ipv6(tvb, dest_addr_offset, &destv6);
}
protocol_handle = heur_protocol_handle;
ipprim_ti = proto_tree_add_string_format(dct2000_tree, hf_catapult_dct2000_ipprim_addresses,
tvb, offset_before_ipprim_header, 0,
"", "IPPrim transport (%s): %s:%u -> %s:%u",
(type_of_port == PT_UDP) ? "UDP" : "TCP",
(source_addr_offset) ?
((source_addr_length == 4) ?
get_hostname(tvb_get_ipv4(tvb, source_addr_offset)) :
get_hostname6(&sourcev6)
) :
"0.0.0.0",
(source_port_offset) ?
tvb_get_ntohs(tvb, source_port_offset) :
0,
(dest_addr_offset) ?
((source_addr_length == 4) ?
get_hostname(tvb_get_ipv4(tvb, dest_addr_offset)) :
get_hostname6(&destv6)
) :
"0.0.0.0",
(dest_port_offset) ?
tvb_get_ntohs(tvb, dest_port_offset) :
0);
if ((type_of_port == PT_TCP) && (conn_id_offset != 0)) {
proto_item_append_text(ipprim_ti, " (conn_id=%u)", tvb_get_ntohs(tvb, conn_id_offset));
}
ipprim_tree = proto_item_add_subtree(ipprim_ti, ett_catapult_dct2000_ipprim);
pinfo->ptype = type_of_port;
switch (type_of_port) {
case PT_UDP:
pinfo->ipproto = IP_PROTO_UDP;
break;
case PT_TCP:
pinfo->ipproto = IP_PROTO_TCP;
break;
default:
pinfo->ipproto = IP_PROTO_NONE;
}
if (source_addr_offset != 0) {
proto_item *addr_ti;
TVB_SET_ADDRESS(&pinfo->net_src,
(source_addr_length == 4) ? AT_IPv4 : AT_IPv6,
tvb, source_addr_offset, source_addr_length);
TVB_SET_ADDRESS(&pinfo->src,
(source_addr_length == 4) ? AT_IPv4 : AT_IPv6,
tvb, source_addr_offset, source_addr_length);
proto_tree_add_item(ipprim_tree,
(source_addr_length == 4) ?
hf_catapult_dct2000_ipprim_src_addr_v4 :
hf_catapult_dct2000_ipprim_src_addr_v6,
tvb, source_addr_offset, source_addr_length,
(source_addr_length == 4) ? ENC_BIG_ENDIAN : ENC_NA);
addr_ti = proto_tree_add_item(ipprim_tree,
(source_addr_length == 4) ?
hf_catapult_dct2000_ipprim_addr_v4 :
hf_catapult_dct2000_ipprim_addr_v6,
tvb, source_addr_offset, source_addr_length,
(source_addr_length == 4) ? ENC_BIG_ENDIAN : ENC_NA);
PROTO_ITEM_SET_HIDDEN(addr_ti);
}
if (source_port_offset != 0) {
proto_item *port_ti;
pinfo->srcport = tvb_get_ntohs(tvb, source_port_offset);
proto_tree_add_item(ipprim_tree,
(type_of_port == PT_UDP) ?
hf_catapult_dct2000_ipprim_udp_src_port :
hf_catapult_dct2000_ipprim_tcp_src_port,
tvb, source_port_offset, 2, ENC_BIG_ENDIAN);
port_ti = proto_tree_add_item(ipprim_tree,
(type_of_port == PT_UDP) ?
hf_catapult_dct2000_ipprim_udp_port :
hf_catapult_dct2000_ipprim_tcp_port,
tvb, source_port_offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(port_ti);
}
if (dest_addr_offset != 0) {
proto_item *addr_ti;
TVB_SET_ADDRESS(&pinfo->net_dst,
(dest_addr_length == 4) ? AT_IPv4 : AT_IPv6,
tvb, dest_addr_offset, dest_addr_length);
TVB_SET_ADDRESS(&pinfo->dst,
(dest_addr_length == 4) ? AT_IPv4 : AT_IPv6,
tvb, dest_addr_offset, dest_addr_length);
proto_tree_add_item(ipprim_tree,
(dest_addr_length == 4) ?
hf_catapult_dct2000_ipprim_dst_addr_v4 :
hf_catapult_dct2000_ipprim_dst_addr_v6,
tvb, dest_addr_offset, dest_addr_length,
(dest_addr_length == 4) ? ENC_BIG_ENDIAN : ENC_NA);
addr_ti = proto_tree_add_item(ipprim_tree,
(dest_addr_length == 4) ?
hf_catapult_dct2000_ipprim_addr_v4 :
hf_catapult_dct2000_ipprim_addr_v6,
tvb, dest_addr_offset, dest_addr_length,
(dest_addr_length == 4) ? ENC_BIG_ENDIAN : ENC_NA);
PROTO_ITEM_SET_HIDDEN(addr_ti);
}
if (dest_port_offset != 0) {
proto_item *port_ti;
pinfo->destport = tvb_get_ntohs(tvb, dest_port_offset);
proto_tree_add_item(ipprim_tree,
(type_of_port == PT_UDP) ?
hf_catapult_dct2000_ipprim_udp_dst_port :
hf_catapult_dct2000_ipprim_tcp_dst_port,
tvb, dest_port_offset, 2, ENC_BIG_ENDIAN);
port_ti = proto_tree_add_item(ipprim_tree,
(type_of_port == PT_UDP) ?
hf_catapult_dct2000_ipprim_udp_port :
hf_catapult_dct2000_ipprim_tcp_port,
tvb, dest_port_offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(port_ti);
}
if (conn_id_offset != 0) {
proto_tree_add_item(ipprim_tree,
hf_catapult_dct2000_ipprim_conn_id,
tvb, conn_id_offset, 2, ENC_BIG_ENDIAN);
}
if (source_addr_offset) {
col_append_fstr(pinfo->cinfo, COL_DEF_SRC,
"(%s:%u)",
get_hostname(tvb_get_ipv4(tvb, source_addr_offset)),
tvb_get_ntohs(tvb, source_port_offset));
}
if (dest_addr_offset) {
col_append_fstr(pinfo->cinfo, COL_DEF_DST,
"(%s:%u)",
get_hostname(tvb_get_ipv4(tvb, dest_addr_offset)),
tvb_get_ntohs(tvb, dest_port_offset));
}
proto_item_set_len(ipprim_tree, offset - offset_before_ipprim_header);
}
}
if (!protocol_handle && catapult_dct2000_try_sctpprim_heuristic) {
guint32 dest_addr_offset = 0;
guint16 dest_addr_length = 0;
guint32 dest_port_offset = 0;
int offset_before_sctpprim_header = offset;
heur_protocol_handle = look_for_dissector(protocol_name);
if ((heur_protocol_handle != 0) &&
(find_sctpprim_variant1_data_offset(tvb, &offset,
&dest_addr_offset,
&dest_addr_length,
&dest_port_offset) ||
find_sctpprim_variant3_data_offset(tvb, &offset,
&dest_addr_offset,
&dest_addr_length,
&dest_port_offset))) {
proto_tree *sctpprim_tree;
proto_item *ti_local;
protocol_handle = heur_protocol_handle;
ti_local = proto_tree_add_string_format(dct2000_tree, hf_catapult_dct2000_sctpprim_addresses,
tvb, offset_before_sctpprim_header, 0,
"", "SCTPPrim transport: -> %s:%u",
(dest_addr_offset) ?
((dest_addr_length == 4) ?
get_hostname(tvb_get_ipv4(tvb, dest_addr_offset)) :
"<ipv6-address>"
) :
"0.0.0.0",
(dest_port_offset) ?
tvb_get_ntohs(tvb, dest_port_offset) :
0);
sctpprim_tree = proto_item_add_subtree(ti_local, ett_catapult_dct2000_sctpprim);
pinfo->ipproto = IP_PROTO_SCTP;
if (dest_addr_offset != 0) {
proto_item *addr_ti;
TVB_SET_ADDRESS(&pinfo->net_dst,
(dest_addr_length == 4) ? AT_IPv4 : AT_IPv6,
tvb, dest_addr_offset, dest_addr_length);
TVB_SET_ADDRESS(&pinfo->dst,
(dest_addr_length == 4) ? AT_IPv4 : AT_IPv6,
tvb, dest_addr_offset, dest_addr_length);
proto_tree_add_item(sctpprim_tree,
(dest_addr_length == 4) ?
hf_catapult_dct2000_sctpprim_dst_addr_v4 :
hf_catapult_dct2000_sctpprim_dst_addr_v6,
tvb, dest_addr_offset, dest_addr_length,
(dest_addr_length == 4) ? ENC_BIG_ENDIAN : ENC_NA);
addr_ti = proto_tree_add_item(sctpprim_tree,
(dest_addr_length == 4) ?
hf_catapult_dct2000_sctpprim_addr_v4 :
hf_catapult_dct2000_sctpprim_addr_v6,
tvb, dest_addr_offset, dest_addr_length,
(dest_addr_length == 4) ? ENC_BIG_ENDIAN : ENC_NA);
PROTO_ITEM_SET_HIDDEN(addr_ti);
}
if (dest_port_offset != 0) {
pinfo->destport = tvb_get_ntohs(tvb, dest_port_offset);
proto_tree_add_item(sctpprim_tree,
hf_catapult_dct2000_sctpprim_dst_port,
tvb, dest_port_offset, 2, ENC_BIG_ENDIAN);
}
proto_item_set_len(sctpprim_tree, offset - offset_before_sctpprim_header);
}
}
if (protocol_handle == 0) {
char dotted_protocol_name[64+128];
g_snprintf(dotted_protocol_name, 64+128, "dct2000.%s", protocol_name);
protocol_handle = find_dissector(dotted_protocol_name);
}
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
return;
}
proto_item_set_len(dct2000_tree, offset);
if (protocol_handle != 0) {
next_tvb = tvb_new_subset_remaining(tvb, offset);
sub_dissector_result = call_dissector_only(protocol_handle, next_tvb, pinfo, tree, NULL);
}
if (protocol_handle == 0 || sub_dissector_result == 0) {
proto_tree_add_item(dct2000_tree, hf_catapult_dct2000_unparsed_data,
tvb, offset, -1, ENC_NA);
col_add_fstr(pinfo->cinfo, COL_INFO,
"Not dissected (context=%s.%u t=%s %c prot=%s (v=%s))",
context_name,
port_number,
timestamp_string,
(direction == 0) ? 'S' : 'R',
protocol_name,
variant_string);
}
else {
if (dct2000_tree) {
proto_item *ti_local = proto_tree_add_uint(dct2000_tree,
hf_catapult_dct2000_dissected_length,
tvb, 0, 0, tvb_reported_length(tvb)-offset);
PROTO_ITEM_SET_GENERATED(ti_local);
}
}
}
void proto_reg_handoff_catapult_dct2000(void)
{
dissector_handle_t catapult_dct2000_handle = find_dissector("dct2000");
dissector_add_uint("wtap_encap", WTAP_ENCAP_CATAPULT_DCT2000, catapult_dct2000_handle);
mac_lte_handle = find_dissector("mac-lte");
rlc_lte_handle = find_dissector("rlc-lte");
pdcp_lte_handle = find_dissector("pdcp-lte");
}
void proto_register_catapult_dct2000(void)
{
static hf_register_info hf[] =
{
{ &hf_catapult_dct2000_context,
{ "Context",
"dct2000.context", FT_STRING, BASE_NONE, NULL, 0x0,
"Context name", HFILL
}
},
{ &hf_catapult_dct2000_port_number,
{ "Context Port number",
"dct2000.context_port", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_timestamp,
{ "Timestamp",
"dct2000.timestamp", FT_DOUBLE, BASE_NONE, NULL, 0x0,
"File timestamp", HFILL
}
},
{ &hf_catapult_dct2000_protocol,
{ "DCT2000 protocol",
"dct2000.protocol", FT_STRING, BASE_NONE, NULL, 0x0,
"Original (DCT2000) protocol name", HFILL
}
},
{ &hf_catapult_dct2000_variant,
{ "Protocol variant",
"dct2000.variant", FT_STRING, BASE_NONE, NULL, 0x0,
"DCT2000 protocol variant", HFILL
}
},
{ &hf_catapult_dct2000_outhdr,
{ "Out-header",
"dct2000.outhdr", FT_STRING, BASE_NONE, NULL, 0x0,
"DCT2000 protocol outhdr", HFILL
}
},
{ &hf_catapult_dct2000_direction,
{ "Direction",
"dct2000.direction", FT_UINT8, BASE_DEC, VALS(direction_vals), 0x0,
"Frame direction (Sent or Received)", HFILL
}
},
{ &hf_catapult_dct2000_encap,
{ "Wireshark encapsulation",
"dct2000.encapsulation", FT_UINT8, BASE_DEC, VALS(encap_vals), 0x0,
"Wireshark frame encapsulation used", HFILL
}
},
{ &hf_catapult_dct2000_unparsed_data,
{ "Unparsed protocol data",
"dct2000.unparsed_data", FT_BYTES, BASE_NONE, NULL, 0x0,
"Unparsed DCT2000 protocol data", HFILL
}
},
{ &hf_catapult_dct2000_comment,
{ "Comment",
"dct2000.comment", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_sprint,
{ "Sprint text",
"dct2000.sprint", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_error_comment,
{ "Error comment",
"dct2000.error-comment", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_dissected_length,
{ "Dissected length",
"dct2000.dissected-length", FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of bytes dissected by subdissector(s)", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_addresses,
{ "IPPrim Addresses",
"dct2000.ipprim", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_ipprim_src_addr_v4,
{ "Source Address",
"dct2000.ipprim.src", FT_IPv4, BASE_NONE, NULL, 0x0,
"IPPrim IPv4 Source Address", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_src_addr_v6,
{ "Source Address",
"dct2000.ipprim.srcv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPPrim IPv6 Source Address", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_dst_addr_v4,
{ "Destination Address",
"dct2000.ipprim.dst", FT_IPv4, BASE_NONE, NULL, 0x0,
"IPPrim IPv4 Destination Address", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_dst_addr_v6,
{ "Destination Address",
"dct2000.ipprim.dstv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPPrim IPv6 Destination Address", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_addr_v4,
{ "Address",
"dct2000.ipprim.addr", FT_IPv4, BASE_NONE, NULL, 0x0,
"IPPrim IPv4 Address", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_addr_v6,
{ "Address",
"dct2000.ipprim.addrv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"IPPrim IPv6 Address", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_udp_src_port,
{ "UDP Source Port",
"dct2000.ipprim.udp.srcport", FT_UINT16, BASE_DEC, NULL, 0x0,
"IPPrim UDP Source Port", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_udp_dst_port,
{ "UDP Destination Port",
"dct2000.ipprim.udp.dstport", FT_UINT16, BASE_DEC, NULL, 0x0,
"IPPrim UDP Destination Port", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_udp_port,
{ "UDP Port",
"dct2000.ipprim.udp.port", FT_UINT16, BASE_DEC, NULL, 0x0,
"IPPrim UDP Port", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_tcp_src_port,
{ "TCP Source Port",
"dct2000.ipprim.tcp.srcport", FT_UINT16, BASE_DEC, NULL, 0x0,
"IPPrim TCP Source Port", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_tcp_dst_port,
{ "TCP Destination Port",
"dct2000.ipprim.tcp.dstport", FT_UINT16, BASE_DEC, NULL, 0x0,
"IPPrim TCP Destination Port", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_tcp_port,
{ "TCP Port",
"dct2000.ipprim.tcp.port", FT_UINT16, BASE_DEC, NULL, 0x0,
"IPPrim TCP Port", HFILL
}
},
{ &hf_catapult_dct2000_ipprim_conn_id,
{ "Conn Id",
"dct2000.ipprim.conn-id", FT_UINT16, BASE_DEC, NULL, 0x0,
"IPPrim TCP Connection ID", HFILL
}
},
{ &hf_catapult_dct2000_sctpprim_addresses,
{ "SCTPPrim Addresses",
"dct2000.sctpprim", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_sctpprim_dst_addr_v4,
{ "Destination Address",
"dct2000.sctpprim.dst", FT_IPv4, BASE_NONE, NULL, 0x0,
"SCTPPrim IPv4 Destination Address", HFILL
}
},
{ &hf_catapult_dct2000_sctpprim_dst_addr_v6,
{ "Destination Address",
"dct2000.sctpprim.dstv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"SCTPPrim IPv6 Destination Address", HFILL
}
},
{ &hf_catapult_dct2000_sctpprim_addr_v4,
{ "Address",
"dct2000.sctpprim.addr", FT_IPv4, BASE_NONE, NULL, 0x0,
"SCTPPrim IPv4 Address", HFILL
}
},
{ &hf_catapult_dct2000_sctpprim_addr_v6,
{ "Address",
"dct2000.sctpprim.addrv6", FT_IPv6, BASE_NONE, NULL, 0x0,
"SCTPPrim IPv6 Address", HFILL
}
},
{ &hf_catapult_dct2000_sctpprim_dst_port,
{ "UDP Destination Port",
"dct2000.sctprim.dstport", FT_UINT16, BASE_DEC, NULL, 0x0,
"SCTPPrim Destination Port", HFILL
}
},
{ &hf_catapult_dct2000_tty,
{ "tty contents",
"dct2000.tty", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_tty_line,
{ "tty line",
"dct2000.tty-line", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_lte_ueid,
{ "UE Id",
"dct2000.lte.ueid", FT_UINT16, BASE_DEC, NULL, 0x0,
"User Equipment Identifier", HFILL
}
},
{ &hf_catapult_dct2000_lte_srbid,
{ "srbid",
"dct2000.lte.srbid", FT_UINT8, BASE_DEC, NULL, 0x0,
"Signalling Radio Bearer Identifier", HFILL
}
},
{ &hf_catapult_dct2000_lte_drbid,
{ "drbid",
"dct2000.lte.drbid", FT_UINT8, BASE_DEC, NULL, 0x0,
"Data Radio Bearer Identifier", HFILL
}
},
{ &hf_catapult_dct2000_lte_cellid,
{ "Cell-Id",
"dct2000.lte.cellid", FT_UINT16, BASE_DEC, NULL, 0x0,
"Cell Identifier", HFILL
}
},
{ &hf_catapult_dct2000_lte_bcch_transport,
{ "BCCH Transport",
"dct2000.lte.bcch-transport", FT_UINT16, BASE_DEC, VALS(bcch_transport_vals), 0x0,
"BCCH Transport Channel", HFILL
}
},
{ &hf_catapult_dct2000_lte_rlc_op,
{ "RLC Op",
"dct2000.lte.rlc-op", FT_UINT8, BASE_DEC, VALS(rlc_op_vals), 0x0,
"RLC top-level op", HFILL
}
},
{ &hf_catapult_dct2000_lte_rlc_channel_type,
{ "RLC Logical Channel Type",
"dct2000.lte.rlc-logchan-type", FT_UINT8, BASE_DEC, VALS(rlc_logical_channel_vals), 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_lte_rlc_mui,
{ "MUI",
"dct2000.lte.rlc-mui", FT_UINT16, BASE_DEC, NULL, 0x0,
"RLC MUI", HFILL
}
},
{ &hf_catapult_dct2000_lte_rlc_cnf,
{ "CNF",
"dct2000.lte.rlc-cnf", FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x0,
"RLC CNF", HFILL
}
},
{ &hf_catapult_dct2000_lte_rlc_discard_req,
{ "Discard Req",
"dct2000.lte.rlc-discard-req", FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x0,
"RLC Discard Req", HFILL
}
},
{ &hf_catapult_dct2000_lte_ccpri_opcode,
{ "CCPRI opcode",
"dct2000.lte.ccpri.opcode", FT_UINT8, BASE_DEC, VALS(ccpri_opcode_vals), 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_lte_ccpri_status,
{ "Status",
"dct2000.lte.ccpri.status", FT_UINT8, BASE_DEC, VALS(ccpri_status_vals), 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_lte_ccpri_channel,
{ "Channel",
"dct2000.lte.ccpri.channel", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_lte_nas_rrc_opcode,
{ "NAS RRC Opcode",
"dct2000.lte.nas-rrc.opcode", FT_UINT8, BASE_DEC, VALS(lte_nas_rrc_opcode_vals), 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_lte_nas_rrc_establish_cause,
{ "Establish Cause",
"dct2000.lte.nas-rrc.establish-cause", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_lte_nas_rrc_priority,
{ "Priority",
"dct2000.lte.nas-rrc.priority", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_lte_nas_rrc_release_cause,
{ "Priority",
"dct2000.lte.nas-rrc.priority", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_ueid,
{ "UE Id",
"dct2000.ueid", FT_UINT32, BASE_DEC, NULL, 0x0,
"User Equipment Identifier", HFILL
}
},
{ &hf_catapult_dct2000_rbid,
{ "Channel",
"dct2000.rbid", FT_UINT8, BASE_DEC, VALS(rlc_rbid_vals), 0x0,
"Channel (rbid)", HFILL
}
},
{ &hf_catapult_dct2000_ccch_id,
{ "CCCH Id",
"dct2000.ccch-id", FT_UINT8, BASE_DEC, NULL, 0x0,
"CCCH Identifier", HFILL
}
},
{ &hf_catapult_dct2000_no_crc_error,
{ "No CRC Error",
"dct2000.no-crc-error", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_crc_error,
{ "CRC Error",
"dct2000.crc-error", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_clear_tx_buffer,
{ "Clear Tx Buffer",
"dct2000.clear-tx-buffer", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_buffer_occupancy,
{ "Buffer Occupancy",
"dct2000.buffer-occupancy", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_pdu_size,
{ "PDU Size",
"dct2000.pdu-size", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_ueid_type,
{ "UEId Type",
"dct2000.ueid-type", FT_UINT8, BASE_DEC, VALS(ueid_type_vals), 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_tx_priority,
{ "Tx Priority",
"dct2000.tx-priority", FT_UINT8, BASE_DEC, VALS(tx_priority_vals), 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_last_in_seg_set,
{ "Last in seg set",
"dct2000.last-in-seg-set", FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_rx_timing_deviation,
{ "Tx Timing Deviation",
"dct2000.rx-timing-deviation", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_transport_channel_type,
{ "Transport Channel Type",
"dct2000.transport_channel_type", FT_UINT8, BASE_DEC, VALS(transport_channel_type_vals), 0x0,
NULL, HFILL
}
},
{ &hf_catapult_dct2000_no_padding_bits,
{ "Number of padding bits",
"dct2000.number-of-padding-bits", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
};
static gint *ett[] =
{
&ett_catapult_dct2000,
&ett_catapult_dct2000_ipprim,
&ett_catapult_dct2000_sctpprim,
&ett_catapult_dct2000_tty
};
static ei_register_info ei[] = {
{ &ei_catapult_dct2000_lte_ccpri_status_error, { "dct2000.lte.ccpri.status.error", PI_SEQUENCE, PI_ERROR, "CCPRI Indication has error status", EXPFILL }},
{ &ei_catapult_dct2000_error_comment_expert, { "dct2000.error-comment.expert", PI_SEQUENCE, PI_ERROR, "Formatted expert comment", EXPFILL }},
};
module_t *catapult_dct2000_module;
expert_module_t* expert_catapult_dct2000;
proto_catapult_dct2000 = proto_register_protocol("Catapult DCT2000 packet",
"DCT2000",
"dct2000");
proto_register_field_array(proto_catapult_dct2000, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_catapult_dct2000 = expert_register_protocol(proto_catapult_dct2000);
expert_register_field_array(expert_catapult_dct2000, ei, array_length(ei));
register_dissector("dct2000", dissect_catapult_dct2000, proto_catapult_dct2000);
catapult_dct2000_module = prefs_register_protocol(proto_catapult_dct2000, NULL);
prefs_register_obsolete_preference(catapult_dct2000_module, "board_ports_only");
prefs_register_bool_preference(catapult_dct2000_module, "ipprim_heuristic",
"Use IP Primitive heuristic",
"If a payload looks like it's embedded in an "
"IP primitive message, and there is a Wireshark "
"dissector matching the DCT2000 protocol name, "
"try parsing the payload using that dissector",
&catapult_dct2000_try_ipprim_heuristic);
prefs_register_bool_preference(catapult_dct2000_module, "sctpprim_heuristic",
"Use SCTP Primitive heuristic",
"If a payload looks like it's embedded in an "
"SCTP primitive message, and there is a Wireshark "
"dissector matching the DCT2000 protocol name, "
"try parsing the payload using that dissector",
&catapult_dct2000_try_sctpprim_heuristic);
prefs_register_bool_preference(catapult_dct2000_module, "decode_lte_rrc",
"Attempt to decode LTE RRC frames",
"When set, attempt to decode LTE RRC frames. "
"Note that this won't affect other protocols "
"that also call the LTE RRC dissector",
&catapult_dct2000_dissect_lte_rrc);
prefs_register_bool_preference(catapult_dct2000_module, "decode_lte_s1ap",
"Attempt to decode LTE S1AP frames",
"When set, attempt to decode LTE S1AP frames. "
"Note that this won't affect other protocols "
"that also call the LTE S1AP dissector",
&catapult_dct2000_dissect_lte_s1ap);
prefs_register_bool_preference(catapult_dct2000_module, "decode_mac_lte_oob_messages",
"Look for out-of-band LTE MAC events messages in comments",
"When set, look for formatted messages indicating "
"specific events. This may be quite slow, so should "
"be disabled if LTE MAC is not being analysed",
&catapult_dct2000_dissect_mac_lte_oob_messages);
}
