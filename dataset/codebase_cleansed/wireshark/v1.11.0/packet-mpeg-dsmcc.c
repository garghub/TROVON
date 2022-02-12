static void
dissect_dsmcc_adaptation_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *sub_tvb;
guint offset = 0;
proto_item *pi;
proto_tree *sub_tree;
guint8 type, tmp;
guint16 ca_len;
type = tvb_get_guint8(tvb, offset);
if (1 == type) {
pi = proto_tree_add_text(tree, tvb, offset, -1, "Adaptation Header");
sub_tree = proto_item_add_subtree(pi, ett_dsmcc_adaptation_header);
proto_tree_add_item(sub_tree, hf_dsmcc_adaptation_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset +=1;
tmp = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(sub_tree, hf_dsmcc_adaptation_ca_reserved, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (0xff != tmp) {
expert_add_info_format(pinfo, pi, &ei_dsmcc_invalid_value,
"Invalid value - should be 0xff");
}
offset +=1;
proto_tree_add_item(sub_tree, hf_dsmcc_adaptation_ca_system_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ca_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(sub_tree, hf_dsmcc_adaptation_ca_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
sub_tvb = tvb_new_subset(tvb, offset, ca_len, ca_len);
call_dissector(data_handle, sub_tvb, pinfo, tree);
} else if (2 == type) {
pi = proto_tree_add_text(tree, tvb, offset, -1, "Adaptation Header");
sub_tree = proto_item_add_subtree(pi, ett_dsmcc_adaptation_header);
proto_tree_add_item(sub_tree, hf_dsmcc_adaptation_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset +=1;
tmp = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(sub_tree, hf_dsmcc_adaptation_user_id_reserved, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (0xff != tmp) {
expert_add_info_format(pinfo, pi, &ei_dsmcc_invalid_value,
"Invalid value - should be 0xff");
}
} else {
pi = proto_tree_add_text(tree, tvb, offset, -1, "Unknown Adaptation Header");
sub_tree = proto_item_add_subtree(pi, ett_dsmcc_adaptation_header);
proto_tree_add_item(sub_tree, hf_dsmcc_adaptation_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
}
}
static guint
dissect_dsmcc_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset,
gboolean download_header)
{
tvbuff_t *sub_tvb;
proto_item *pi;
proto_tree *sub_tree;
guint8 prot_disc;
guint reserved;
guint8 adaptation_len;
guint offset_start;
int msg_id, tx_id;
offset_start = offset;
prot_disc = tvb_get_guint8(tvb, offset);
reserved = tvb_get_guint8(tvb, 8+offset);
adaptation_len = tvb_get_guint8(tvb, 9+offset);
pi = proto_tree_add_text(tree, tvb, offset, 12+adaptation_len, "DSM-CC Header");
sub_tree = proto_item_add_subtree(pi, ett_dsmcc_header);
pi = proto_tree_add_item(sub_tree, hf_dsmcc_protocol_discriminator, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (0x11 != prot_disc) {
expert_add_info_format(pinfo, pi, &ei_dsmcc_invalid_value,
"Invalid value - should be 0x11");
}
offset +=1;
proto_tree_add_item(sub_tree, hf_dsmcc_type, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset +=1;
if (TRUE == download_header) {
msg_id = hf_dsmcc_dd_message_id;
tx_id = hf_dsmcc_dd_download_id;
} else {
msg_id = hf_dsmcc_message_id;
tx_id = hf_dsmcc_transaction_id;
}
proto_tree_add_item(sub_tree, msg_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, tx_id, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
pi = proto_tree_add_item(sub_tree, hf_dsmcc_header_reserved, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (0xff != reserved) {
expert_add_info_format(pinfo, pi, &ei_dsmcc_invalid_value,
"Invalid value - should be 0xff");
}
offset +=1;
proto_tree_add_item(sub_tree, hf_dsmcc_adaptation_length, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(sub_tree, hf_dsmcc_message_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (0 < adaptation_len) {
sub_tvb = tvb_new_subset(tvb, offset, adaptation_len, adaptation_len);
dissect_dsmcc_adaptation_header(sub_tvb, pinfo, sub_tree);
offset += adaptation_len;
}
return offset-offset_start;
}
static guint
dissect_dsmcc_dii_compat_desc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset)
{
gint i, j;
guint8 sub_count, sub_len;
guint16 len, count;
proto_item *pi;
proto_tree *compat_tree;
proto_tree *desc_sub_tree;
len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_compat_desc_length, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
if (0 < len) {
count = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_compat_desc_count, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
for (i = 0; i < count; i++) {
pi = proto_tree_add_text(tree, tvb, offset, len, "Compatibility Descriptor");
compat_tree = proto_item_add_subtree(pi, ett_dsmcc_compat);
proto_tree_add_item(compat_tree, hf_desc_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(compat_tree, hf_desc_length, tvb, offset,
1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(compat_tree, hf_desc_spec_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(compat_tree, hf_desc_spec_data, tvb, offset,
3, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(compat_tree, hf_desc_model, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(compat_tree, hf_desc_version, tvb, offset,
2, ENC_BIG_ENDIAN);
offset += 2;
sub_count = tvb_get_guint8(tvb, offset);
proto_tree_add_item(compat_tree, hf_desc_sub_desc_count, tvb, offset,
1, ENC_BIG_ENDIAN);
offset +=1;
for (j = 0; j < sub_count; j++) {
sub_len = tvb_get_guint8(tvb, offset+1);
pi = proto_tree_add_text(compat_tree, tvb, offset, sub_len+2, "Sub Descriptor");
desc_sub_tree = proto_item_add_subtree(pi, ett_dsmcc_compat_sub_desc);
proto_tree_add_item(desc_sub_tree, hf_desc_sub_desc_type, tvb, offset,
1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(desc_sub_tree, hf_desc_sub_desc_len, tvb, offset,
1, ENC_BIG_ENDIAN);
offset +=1;
offset += sub_len;
}
}
if( 1000 == offset ) {
expert_add_info( pinfo, NULL, &ei_dsmcc_crc_invalid);
}
}
return 2 + len;
}
static void
dissect_dsmcc_dii(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint offset)
{
guint8 module_info_len;
guint16 modules, private_data_len;
guint16 module_id;
guint8 module_version;
guint module_size;
guint i;
proto_item *pi;
proto_tree *mod_tree;
proto_tree_add_item(tree, hf_dsmcc_dii_download_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dsmcc_dii_block_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dsmcc_dii_window_size, tvb, offset, 1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(tree, hf_dsmcc_dii_ack_period, tvb, offset, 1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(tree, hf_dsmcc_dii_t_c_download_window, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dsmcc_dii_t_c_download_scenario, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset += dissect_dsmcc_dii_compat_desc(tvb, pinfo, tree, offset);
proto_tree_add_item(tree, hf_dsmcc_dii_number_of_modules, tvb, offset, 2, ENC_BIG_ENDIAN);
modules = tvb_get_ntohs(tvb, offset);
offset += 2;
for (i = 0; i < modules; i++ ) {
module_id = tvb_get_ntohs(tvb, offset);
module_size = tvb_get_ntohl(tvb, 2+offset);
module_version = tvb_get_guint8(tvb, 6+offset);
pi = proto_tree_add_text(tree, tvb, offset, -1,
"Module Id: 0x%x, Version: %u, Size: %u",
module_id, module_version, module_size);
mod_tree = proto_item_add_subtree(pi, ett_dsmcc_dii_module);
proto_tree_add_item(mod_tree, hf_dsmcc_dii_module_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mod_tree, hf_dsmcc_dii_module_size, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(mod_tree, hf_dsmcc_dii_module_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset +=1;
module_info_len = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mod_tree, hf_dsmcc_dii_module_info_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset +=1;
if (0 < module_info_len) {
proto_tree_add_item(mod_tree, hf_etv_module_abs_path, tvb, offset, 1,
ENC_ASCII|ENC_NA);
offset += module_info_len;
}
}
private_data_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dsmcc_dii_private_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (0 < private_data_len) {
proto_tree_add_item(tree, hf_etv_dii_authority, tvb, offset, 1,
ENC_ASCII|ENC_NA);
}
}
static void
dissect_dsmcc_ddb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *top_tree, guint offset)
{
tvbuff_t *sub_tvb;
proto_item *pi;
guint8 reserved;
proto_tree_add_item(tree, hf_dsmcc_ddb_module_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dsmcc_ddb_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset +=1;
reserved = tvb_get_guint8(tvb, offset);
pi = proto_tree_add_item(tree, hf_dsmcc_ddb_reserved, tvb,
offset, 1, ENC_BIG_ENDIAN);
if (0xff != reserved) {
expert_add_info_format(pinfo, pi, &ei_dsmcc_invalid_value,
"Invalid value - should be 0xff");
}
offset +=1;
proto_tree_add_item(tree, hf_dsmcc_ddb_block_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
sub_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, sub_tvb, pinfo, top_tree);
}
static void
dissect_dsmcc_un_download(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *top_tree)
{
proto_item *pi;
proto_tree *sub_tree;
guint16 msg_id;
guint offset = 0;
msg_id = tvb_get_ntohs(tvb, offset+2);
pi = proto_tree_add_text(tree, tvb, 0, -1, "User Network Message - %s",
val_to_str(msg_id, dsmcc_dd_message_id_vals, "%u"));
sub_tree = proto_item_add_subtree(pi, ett_dsmcc_payload);
switch (msg_id) {
case 0x1001:
case 0x1002:
offset += dissect_dsmcc_header(tvb, pinfo, sub_tree, offset, FALSE);
dissect_dsmcc_dii(tvb, pinfo, sub_tree, offset);
break;
case 0x1003:
offset += dissect_dsmcc_header(tvb, pinfo, sub_tree, offset, TRUE);
dissect_dsmcc_ddb(tvb, pinfo, sub_tree, top_tree, offset);
break;
case 0x1004:
break;
case 0x1005:
break;
case 0x1006:
break;
default:
break;
}
}
static void
dissect_dsmcc_un(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
proto_tree *top_tree)
{
guint8 type;
type = tvb_get_guint8(tvb, 1);
switch (type) {
case 1:
break;
case 2:
break;
case 3:
dissect_dsmcc_un_download(tvb, pinfo, tree, top_tree);
break;
case 4:
break;
case 5:
break;
default:
break;
}
}
static gboolean
dissect_dsmcc_ts(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree_in, void *data _U_)
{
proto_item *pi;
proto_tree *tree;
guint crc_len;
guint8 tid;
guint16 sect_len;
guint32 crc, calculated_crc;
const char *label;
tvbuff_t *sub_tvb;
guint16 ssi;
guint offset = 0;
pi = proto_tree_add_item(tree_in, proto_dsmcc, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(pi, ett_dsmcc);
tid = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dsmcc_table_id, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset +=1;
ssi = tvb_get_ntohs(tvb, offset);
ssi &= DSMCC_SSI_MASK;
proto_tree_add_item(tree, hf_dsmcc_section_syntax_indicator, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dsmcc_private_indicator, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dsmcc_reserved, tvb,
offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dsmcc_section_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
sect_len = tvb_get_ntohs(tvb, offset);
sect_len &= DSMCC_LENGTH_MASK;
offset += 2;
proto_tree_add_item(tree, hf_dsmcc_table_id_extension, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dsmcc_reserved2, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dsmcc_version_number, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_dsmcc_current_next_indicator, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(tree, hf_dsmcc_section_number, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset +=1;
proto_tree_add_item(tree, hf_dsmcc_last_section_number, tvb,
offset, 1, ENC_BIG_ENDIAN);
offset +=1;
sub_tvb = tvb_new_subset(tvb, offset, sect_len-9, sect_len-9);
switch (tid) {
case DSMCC_TID_LLCSNAP:
break;
case DSMCC_TID_UN_MSG:
case DSMCC_TID_DD_MSG:
dissect_dsmcc_un(sub_tvb, pinfo, tree, tree_in);
break;
case DSMCC_TID_DESC_LIST:
break;
case DSMCC_TID_PRIVATE:
break;
default:
break;
}
crc_len = 3 + sect_len - 4;
if (ssi) {
crc = tvb_get_ntohl(tvb, crc_len);
calculated_crc = crc;
label = "Unverified";
if (dsmcc_sect_check_crc) {
label = "Verified";
calculated_crc = crc32_mpeg2_tvb_offset(tvb, 0, crc_len);
}
if (calculated_crc == crc) {
proto_tree_add_uint_format( tree, hf_dsmcc_crc, tvb,
crc_len, 4, crc, "CRC: 0x%08x [%s]", crc, label);
} else {
proto_item *msg_error;
msg_error = proto_tree_add_uint_format( tree, hf_dsmcc_crc, tvb,
crc_len, 4, crc,
"CRC: 0x%08x [Failed Verification (Calculated: 0x%08x)]",
crc, calculated_crc );
PROTO_ITEM_SET_GENERATED(msg_error);
expert_add_info( pinfo, msg_error, &ei_dsmcc_crc_invalid);
}
} else {
proto_tree_add_item(tree, hf_dsmcc_checksum, tvb,
crc_len, 4, ENC_BIG_ENDIAN);
}
return TRUE;
}
static void
dissect_dsmcc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DSM-CC");
dissect_dsmcc_ts(tvb, pinfo, tree, NULL);
}
void
proto_register_dsmcc(void)
{
static hf_register_info hf[] = {
{ &hf_dsmcc_protocol_discriminator, {
"Protocol Discriminator", "mpeg_dsmcc.protocol",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_type, {
"Type", "mpeg_dsmcc.type",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(dsmcc_header_type_vals), 0, NULL, HFILL
} },
{ &hf_dsmcc_message_id, {
"Message ID", "mpeg_dsmcc.message_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_transaction_id, {
"Transaction ID", "mpeg_dsmcc.transaction_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_header_reserved, {
"Reserved", "mpeg_dsmcc.header_reserved",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_adaptation_length, {
"Adaptation Length", "mpeg_dsmcc.adaptation_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_message_length, {
"Message Length", "mpeg_dsmcc.message_length",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_adaptation_type, {
"Adaptation Type", "mpeg_dsmcc.adaptation_header.type",
FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(dsmcc_adaptation_header_vals), 0, NULL, HFILL
} },
{ &hf_dsmcc_adaptation_ca_reserved, {
"Reserved", "mpeg_dsmcc.adaptation_header.ca.reserved",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_adaptation_ca_system_id, {
"System ID", "mpeg_dsmcc.adaptation_header.ca.system_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_adaptation_ca_length, {
"System ID", "mpeg_dsmcc.adaptation_header.ca.length",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_adaptation_user_id_reserved, {
"Reserved", "mpeg_dsmcc.adaptation_header.uid.reserved",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_compat_desc_length, {
"Compatibility Descriptor Length", "mpeg_dsmcc.dii.compat_desc_len",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_compat_desc_count, {
"Descriptor Length", "mpeg_dsmcc.dii.compat_desc_count",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_desc_type, {
"Descriptor Type", "mpeg_dsmcc.dii.compat.type",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_desc_length, {
"Descriptor Length", "mpeg_dsmcc.dii.compat.length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_desc_spec_type, {
"Specifier Type", "mpeg_dsmcc.dii.compat.spec_type",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_desc_spec_data, {
"Specifier Data", "mpeg_dsmcc.dii.compat.spec_data",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_desc_model, {
"Model", "mpeg_dsmcc.dii.compat.model",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_desc_version, {
"Version", "mpeg_dsmcc.dii.compat.version",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_desc_sub_desc_count, {
"Version", "mpeg_dsmcc.dii.compat.sub_count",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_desc_sub_desc_type, {
"Type", "mpeg_dsmcc.dii.compat.sub_type",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_desc_sub_desc_len, {
"Length", "mpeg_dsmcc.dii.compat.sub_len",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dd_download_id, {
"Download ID", "mpeg_dsmcc.download_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dd_message_id, {
"Message ID", "mpeg_dsmcc.message_id",
FT_UINT16, BASE_HEX, VALS(dsmcc_dd_message_id_vals), 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_download_id, {
"Download ID", "mpeg_dsmcc.dii.download_id",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_block_size, {
"Block Size", "mpeg_dsmcc.dii.block_size",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_window_size, {
"Window Size", "mpeg_dsmcc.dii.window_size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_ack_period, {
"ACK Period", "mpeg_dsmcc.dii.ack_period",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_t_c_download_window, {
"Carousel Download Window", "mpeg_dsmcc.dii.carousel_download_window",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_t_c_download_scenario, {
"Carousel Download Scenario", "mpeg_dsmcc.dii.carousel_download_scenario",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_number_of_modules, {
"Number of Modules", "mpeg_dsmcc.dii.module_count",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_module_id, {
"Module ID", "mpeg_dsmcc.dii.module_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_module_size, {
"Module Size", "mpeg_dsmcc.dii.module_size",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_module_version, {
"Module Version", "mpeg_dsmcc.dii.module_version",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_module_info_length, {
"Module Info Length", "mpeg_dsmcc.dii.module_info_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_dii_private_data_length, {
"Private Data Length", "mpeg_dsmcc.dii.private_data_length",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_ddb_module_id, {
"Module ID", "mpeg_dsmcc.ddb.module_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_ddb_version, {
"Version", "mpeg_dsmcc.ddb.version",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_ddb_reserved, {
"Reserved", "mpeg_dsmcc.ddb.reserved",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_ddb_block_number, {
"Block Number", "mpeg_dsmcc.ddb.block_num",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_table_id, {
"Table ID", "mpeg_sect.table_id",
FT_UINT8, BASE_HEX, VALS(dsmcc_payload_name_vals), 0, NULL, HFILL
} },
{ &hf_dsmcc_section_syntax_indicator, {
"Session Syntax Indicator", "mpeg_sect.ssi",
FT_UINT16, BASE_DEC, NULL, DSMCC_SSI_MASK, NULL, HFILL
} },
{ &hf_dsmcc_private_indicator, {
"Private Indicator", "mpeg_dsmcc.private_indicator",
FT_UINT16, BASE_DEC, NULL, DSMCC_PRIVATE_MASK, NULL, HFILL
} },
{ &hf_dsmcc_reserved, {
"Reserved", "mpeg_sect.reserved",
FT_UINT16, BASE_HEX, NULL, DSMCC_RESERVED_MASK, NULL, HFILL
} },
{ &hf_dsmcc_section_length, {
"Length", "mpeg_sect.section_length",
FT_UINT16, BASE_DEC, NULL, DSMCC_LENGTH_MASK, NULL, HFILL
} },
{ &hf_dsmcc_table_id_extension, {
"Table ID Extension", "mpeg_dsmcc.table_id_extension",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_reserved2, {
"Reserved", "mpeg_dsmcc.reserved2",
FT_UINT8, BASE_HEX, NULL, DSMCC_RESERVED2_MASK, NULL, HFILL
} },
{ &hf_dsmcc_version_number, {
"Version Number", "mpeg_dsmcc.version_number",
FT_UINT8, BASE_DEC, NULL, DSMCC_VERSION_NUMBER_MASK, NULL, HFILL
} },
{ &hf_dsmcc_current_next_indicator, {
"Current Next Indicator", "mpeg_dsmcc.current_next_indicator",
FT_UINT8, BASE_DEC, NULL, DSMCC_CURRENT_NEXT_INDICATOR_MASK, NULL, HFILL
} },
{ &hf_dsmcc_section_number, {
"Section Number", "mpeg_dsmcc.section_number",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_last_section_number, {
"Last Section Number", "mpeg_dsmcc.last_section_number",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_crc, {
"CRC 32", "mpeg_sect.crc",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_dsmcc_checksum, {
"Checksum", "mpeg_dsmcc.checksum",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL
} },
{ &hf_etv_module_abs_path, {
"Module Absolute Path", "etv.dsmcc.dii.module_abs_path",
FT_UINT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} },
{ &hf_etv_dii_authority, {
"Authority", "etv.dsmcc.dii.authority",
FT_UINT_STRING, BASE_NONE, NULL, 0, NULL, HFILL
} }
};
static gint *ett[] = {
&ett_dsmcc,
&ett_dsmcc_payload,
&ett_dsmcc_adaptation_header,
&ett_dsmcc_header,
&ett_dsmcc_compat,
&ett_dsmcc_compat_sub_desc,
&ett_dsmcc_dii_module
};
static ei_register_info ei[] = {
{ &ei_dsmcc_invalid_value, { "mpeg_dsmcc.invalid_value", PI_PROTOCOL, PI_WARN, "Invalid value", EXPFILL }},
{ &ei_dsmcc_crc_invalid, { "mpeg_sect.crc.invalid", PI_CHECKSUM, PI_WARN, "Invalid CRC", EXPFILL }},
};
module_t *dsmcc_module;
expert_module_t* expert_dsmcc;
proto_dsmcc = proto_register_protocol("MPEG DSM-CC", "MPEG DSM-CC", "mpeg_dsmcc");
proto_register_field_array(proto_dsmcc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_dsmcc = expert_register_protocol(proto_dsmcc);
expert_register_field_array(expert_dsmcc, ei, array_length(ei));
new_register_dissector("mp2t-dsmcc", dissect_dsmcc_ts, proto_dsmcc);
dsmcc_module = prefs_register_protocol(proto_dsmcc, NULL);
prefs_register_bool_preference(dsmcc_module, "verify_crc",
"Verify the section CRC or checksum",
"Whether the section dissector should verify the CRC or checksum",
&dsmcc_sect_check_crc);
}
void
proto_reg_handoff_dsmcc(void)
{
dissector_handle_t dsmcc_handle;
dsmcc_handle = create_dissector_handle(dissect_dsmcc, proto_dsmcc);
dissector_add_uint("mpeg_sect.tid", DSMCC_TID_LLCSNAP, dsmcc_handle);
dissector_add_uint("mpeg_sect.tid", DSMCC_TID_UN_MSG, dsmcc_handle);
dissector_add_uint("mpeg_sect.tid", DSMCC_TID_DD_MSG, dsmcc_handle);
dissector_add_uint("mpeg_sect.tid", DSMCC_TID_DESC_LIST, dsmcc_handle);
dissector_add_uint("mpeg_sect.tid", DSMCC_TID_PRIVATE, dsmcc_handle);
data_handle = find_dissector("data");
}
