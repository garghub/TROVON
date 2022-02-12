static guint
get_bitcoin_pdu_length(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 length;
length = BITCOIN_HEADER_LENGTH;
length += tvb_get_letohl(tvb, offset+16);
return length;
}
static proto_tree *
create_services_tree(tvbuff_t *tvb, proto_item *ti, guint32 offset)
{
proto_tree *tree;
guint64 services;
tree = proto_item_add_subtree(ti, ett_services);
services = tvb_get_letoh64(tvb, offset);
proto_tree_add_boolean(tree, &hfi_services_network, tvb, offset, 4, (guint32)services);
return tree;
}
static proto_tree *
create_address_tree(tvbuff_t *tvb, proto_item *ti, guint32 offset)
{
proto_tree *tree;
tree = proto_item_add_subtree(ti, ett_address);
ti = proto_tree_add_item(tree, &hfi_address_services, tvb, offset, 8, ENC_LITTLE_ENDIAN);
create_services_tree(tvb, ti, offset);
offset += 8;
proto_tree_add_item(tree, &hfi_address_address, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, &hfi_address_port, tvb, offset, 2, ENC_BIG_ENDIAN);
return tree;
}
static void
get_varint(tvbuff_t *tvb, const gint offset, gint *length, guint64 *ret)
{
guint value;
value = tvb_get_guint8(tvb, offset);
if (value < 0xfd)
{
*length = 1;
*ret = value;
return;
}
if (value == 0xfd)
{
*length = 3;
*ret = tvb_get_letohs(tvb, offset+1);
return;
}
if (value == 0xfe)
{
*length = 5;
*ret = tvb_get_letohl(tvb, offset+1);
return;
}
*length = 9;
*ret = tvb_get_letoh64(tvb, offset+1);
return;
}
static void add_varint_item(proto_tree *tree, tvbuff_t *tvb, const gint offset, gint length,
header_field_info *hfi8, header_field_info *hfi16, header_field_info *hfi32, header_field_info *hfi64)
{
switch (length)
{
case 1:
proto_tree_add_item(tree, hfi8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case 3:
proto_tree_add_item(tree, hfi16, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
break;
case 5:
proto_tree_add_item(tree, hfi32, tvb, offset+1, 4, ENC_LITTLE_ENDIAN);
break;
case 9:
proto_tree_add_item(tree, hfi64, tvb, offset+1, 8, ENC_LITTLE_ENDIAN);
break;
}
}
static proto_tree *
create_string_tree(proto_tree *tree, header_field_info* hfi, tvbuff_t *tvb, guint32* offset)
{
proto_tree *subtree;
proto_item *ti;
gint varint_length;
guint64 varint;
gint string_length;
get_varint(tvb, *offset, &varint_length, &varint);
string_length = (gint) varint;
ti = proto_tree_add_item(tree, hfi, tvb, *offset, varint_length + string_length, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_string);
add_varint_item(subtree, tvb, *offset, varint_length, &hfi_string_varint_count8,
&hfi_string_varint_count16, &hfi_string_varint_count32,
&hfi_string_varint_count64);
*offset += varint_length;
proto_tree_add_item(subtree, &hfi_string_value, tvb, *offset, string_length,
ENC_ASCII|ENC_NA);
*offset += string_length;
return subtree;
}
static void
dissect_bitcoin_msg_version(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
guint32 version;
guint32 offset = 0;
if (!tree)
return;
ti = proto_tree_add_item(tree, &hfi_bitcoin_msg_version, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
version = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, &hfi_msg_version_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ti = proto_tree_add_item(tree, &hfi_msg_version_services, tvb, offset, 8, ENC_LITTLE_ENDIAN);
create_services_tree(tvb, ti, offset);
offset += 8;
proto_tree_add_item(tree, &hfi_msg_version_timestamp, tvb, offset, 8, ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN);
offset += 8;
ti = proto_tree_add_item(tree, &hfi_msg_version_addr_you, tvb, offset, 26, ENC_NA);
create_address_tree(tvb, ti, offset);
offset += 26;
if (version >= 106)
{
ti = proto_tree_add_item(tree, &hfi_msg_version_addr_me, tvb, offset, 26, ENC_NA);
create_address_tree(tvb, ti, offset);
offset += 26;
proto_tree_add_item(tree, &hfi_msg_version_nonce, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
create_string_tree(tree, &hfi_msg_version_user_agent, tvb, &offset);
if (version >= 209)
{
proto_tree_add_item(tree, &hfi_msg_version_start_height, tvb, offset, 4, ENC_LITTLE_ENDIAN);
}
}
}
static void
dissect_bitcoin_msg_addr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
gint length;
guint64 count;
guint32 offset = 0;
if (!tree)
return;
ti = proto_tree_add_item(tree, &hfi_bitcoin_msg_addr, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, &hfi_msg_addr_count8, &hfi_msg_addr_count16,
&hfi_msg_addr_count32, &hfi_msg_addr_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree *subtree;
ti = proto_tree_add_item(tree, &hfi_msg_addr_address, tvb, offset, 30, ENC_NA);
subtree = create_address_tree(tvb, ti, offset+4);
proto_tree_add_item(subtree, &hfi_msg_addr_timestamp, tvb, offset, 4, ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN);
offset += 26;
offset += 4;
}
}
static void
dissect_bitcoin_msg_inv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
gint length;
guint64 count;
guint32 offset = 0;
if (!tree)
return;
ti = proto_tree_add_item(tree, &hfi_bitcoin_msg_inv, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, &hfi_msg_inv_count8, &hfi_msg_inv_count16,
&hfi_msg_inv_count32, &hfi_msg_inv_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree *subtree;
ti = proto_tree_add_text(tree, tvb, offset, 36, "Inventory vector");
subtree = proto_item_add_subtree(ti, ett_inv_list);
proto_tree_add_item(subtree, &hfi_msg_inv_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, &hfi_msg_inv_hash, tvb, offset, 32, ENC_NA);
offset += 32;
}
}
static void
dissect_bitcoin_msg_getdata(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
gint length;
guint64 count;
guint32 offset = 0;
if (!tree)
return;
ti = proto_tree_add_item(tree, &hfi_bitcoin_msg_getdata, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, &hfi_msg_getdata_count8, &hfi_msg_getdata_count16,
&hfi_msg_getdata_count32, &hfi_msg_getdata_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree *subtree;
ti = proto_tree_add_text(tree, tvb, offset, 36, "Inventory vector");
subtree = proto_item_add_subtree(ti, ett_getdata_list);
proto_tree_add_item(subtree, &hfi_msg_getdata_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, &hfi_msg_getdata_hash, tvb, offset, 32, ENC_NA);
offset += 32;
}
}
static void
dissect_bitcoin_msg_getblocks(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
gint length;
guint64 count;
guint32 offset = 0;
if (!tree)
return;
ti = proto_tree_add_item(tree, &hfi_bitcoin_msg_getblocks, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
proto_tree_add_item(tree, &hfi_msg_version_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, &hfi_msg_getblocks_count8, &hfi_msg_getblocks_count16,
&hfi_msg_getblocks_count32, &hfi_msg_getblocks_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree_add_item(tree, &hfi_msg_getblocks_start, tvb, offset, 32, ENC_NA);
offset += 32;
}
proto_tree_add_item(tree, &hfi_msg_getblocks_stop, tvb, offset, 32, ENC_NA);
}
static void
dissect_bitcoin_msg_getheaders(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
gint length;
guint64 count;
guint32 offset = 0;
if (!tree)
return;
ti = proto_tree_add_item(tree, &hfi_bitcoin_msg_getheaders, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, &hfi_msg_getheaders_count8, &hfi_msg_getheaders_count16,
&hfi_msg_getheaders_count32, &hfi_msg_getheaders_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree_add_item(tree, &hfi_msg_getheaders_start, tvb, offset, 32, ENC_NA);
offset += 32;
}
proto_tree_add_item(tree, &hfi_msg_getheaders_stop, tvb, offset, 32, ENC_NA);
return;
}
static guint32
dissect_bitcoin_msg_tx_common(tvbuff_t *tvb, guint32 offset, packet_info *pinfo _U_, proto_tree *tree, guint msgnum)
{
proto_item *rti;
gint count_length;
guint64 in_count;
guint64 out_count;
DISSECTOR_ASSERT(tree != NULL);
if (msgnum == 0) {
rti = proto_tree_add_item(tree, &hfi_bitcoin_msg_tx, tvb, offset, -1, ENC_NA);
} else {
rti = proto_tree_add_none_format(tree, hfi_bitcoin_msg_tx.id, tvb, offset, -1, "Tx message [ %4d ]", msgnum);
}
tree = proto_item_add_subtree(rti, ett_bitcoin_msg);
proto_tree_add_item(tree, &hfi_msg_tx_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
get_varint(tvb, offset, &count_length, &in_count);
add_varint_item(tree, tvb, offset, count_length, &hfi_msg_tx_in_count8, &hfi_msg_tx_in_count16,
&hfi_msg_tx_in_count32, &hfi_msg_tx_in_count64);
offset += count_length;
for (; in_count > 0; in_count--)
{
proto_tree *subtree;
proto_tree *prevtree;
proto_item *ti;
proto_item *pti;
guint64 script_length;
get_varint(tvb, offset+36, &count_length, &script_length);
ti = proto_tree_add_item(tree, &hfi_msg_tx_in, tvb, offset,
36 + count_length + (guint)script_length + 4, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_tx_in_list);
pti = proto_tree_add_item(subtree, &hfi_msg_tx_in_prev_output, tvb, offset, 36, ENC_NA);
prevtree = proto_item_add_subtree(pti, ett_tx_in_outp);
proto_tree_add_item(prevtree, &hfi_msg_tx_in_prev_outp_hash, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(prevtree, &hfi_msg_tx_in_prev_outp_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
add_varint_item(subtree, tvb, offset, count_length, &hfi_msg_tx_in_script8, &hfi_msg_tx_in_script16,
&hfi_msg_tx_in_script32, &hfi_msg_tx_in_script64);
offset += count_length;
if ((offset + script_length) > G_MAXINT)
THROW(ReportedBoundsError);
proto_tree_add_item(subtree, &hfi_msg_tx_in_sig_script, tvb, offset, (guint)script_length, ENC_NA);
offset += (guint)script_length;
proto_tree_add_item(subtree, &hfi_msg_tx_in_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
get_varint(tvb, offset, &count_length, &out_count);
add_varint_item(tree, tvb, offset, count_length, &hfi_msg_tx_out_count8, &hfi_msg_tx_out_count16,
&hfi_msg_tx_out_count32, &hfi_msg_tx_out_count64);
offset += count_length;
for (; out_count > 0; out_count--)
{
proto_item *ti;
proto_tree *subtree;
guint64 script_length;
get_varint(tvb, offset+8, &count_length, &script_length);
ti = proto_tree_add_item(tree, &hfi_msg_tx_out, tvb, offset,
8 + count_length + (guint)script_length , ENC_NA);
subtree = proto_item_add_subtree(ti, ett_tx_out_list);
proto_tree_add_item(subtree, &hfi_msg_tx_out_value, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
add_varint_item(subtree, tvb, offset, count_length, &hfi_msg_tx_out_script8, &hfi_msg_tx_out_script16,
&hfi_msg_tx_out_script32, &hfi_msg_tx_out_script64);
offset += count_length;
if ((offset + script_length) > G_MAXINT)
THROW(ReportedBoundsError);
proto_tree_add_item(subtree, &hfi_msg_tx_out_script, tvb, offset, (guint)script_length, ENC_NA);
offset += (guint)script_length;
}
proto_tree_add_item(tree, &hfi_msg_tx_lock_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_set_len(rti, offset);
return offset;
}
static void
dissect_bitcoin_msg_tx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (!tree)
return;
dissect_bitcoin_msg_tx_common(tvb, 0, pinfo, tree, 0);
}
static void
dissect_bitcoin_msg_block(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
gint length;
guint64 count;
guint msgnum;
guint32 offset = 0;
if (!tree)
return;
ti = proto_tree_add_item(tree, &hfi_bitcoin_msg_block, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
proto_tree_add_item(tree, &hfi_msg_block_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_msg_block_prev_block, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(tree, &hfi_msg_block_merkle_root, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(tree, &hfi_msg_block_time, tvb, offset, 4, ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_msg_block_bits, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, &hfi_msg_block_nonce, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, &hfi_msg_block_transactions8, &hfi_msg_block_transactions16,
&hfi_msg_block_transactions32, &hfi_msg_block_transactions64);
offset += length;
msgnum = 0;
for (; count > 0; count--)
{
msgnum += 1;
offset = dissect_bitcoin_msg_tx_common(tvb, offset, pinfo, tree, msgnum);
}
}
static void
dissect_bitcoin_msg_empty(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_)
{
return;
}
static int dissect_bitcoin_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
guint32 i;
guint32 offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Bitcoin");
ti = proto_tree_add_item(tree, hfi_bitcoin, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin);
proto_tree_add_item(tree, &hfi_bitcoin_magic, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, &hfi_bitcoin_command, tvb, 4, 12, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, &hfi_bitcoin_length, tvb, 16, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, &hfi_bitcoin_checksum, tvb, 20, 4, ENC_BIG_ENDIAN);
offset = 24;
for (i = 0; i < array_length(msg_dissectors); i++)
{
if (tvb_memeql(tvb, 4, msg_dissectors[i].command,
strlen(msg_dissectors[i].command)) == 0)
{
tvbuff_t *tvb_sub;
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", msg_dissectors[i].command);
tvb_sub = tvb_new_subset_remaining(tvb, offset);
msg_dissectors[i].function(tvb_sub, pinfo, tree);
return tvb_length(tvb);
}
}
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", "[unknown command]");
expert_add_info(pinfo, ti, &ei_bitcoin_command_unknown);
return tvb_length(tvb);
}
static int
dissect_bitcoin(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, bitcoin_desegment, BITCOIN_HEADER_LENGTH,
get_bitcoin_pdu_length, dissect_bitcoin_tcp_pdu, data);
return tvb_reported_length(tvb);
}
static gboolean
dissect_bitcoin_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint32 magic_number;
conversation_t *conversation;
if (tvb_length(tvb) < 4)
return FALSE;
magic_number = tvb_get_letohl(tvb, 0);
if ((magic_number != BITCOIN_MAIN_MAGIC_NUMBER) &&
(magic_number != BITCOIN_TESTNET_MAGIC_NUMBER) &&
(magic_number != BITCOIN_TESTNET3_MAGIC_NUMBER))
return FALSE;
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, bitcoin_handle);
dissect_bitcoin(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_bitcoin(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_bitcoin_magic,
&hfi_bitcoin_command,
&hfi_bitcoin_length,
&hfi_bitcoin_checksum,
&hfi_bitcoin_msg_version,
&hfi_msg_version_version,
&hfi_msg_version_services,
&hfi_msg_version_addr_me,
&hfi_msg_version_addr_you,
&hfi_msg_version_timestamp,
&hfi_msg_version_nonce,
&hfi_msg_version_user_agent,
&hfi_msg_version_start_height,
&hfi_msg_addr_count8,
&hfi_msg_addr_count16,
&hfi_msg_addr_count32,
&hfi_msg_addr_count64,
&hfi_bitcoin_msg_addr,
&hfi_msg_addr_address,
&hfi_msg_addr_timestamp,
&hfi_msg_inv_count8,
&hfi_msg_inv_count16,
&hfi_msg_inv_count32,
&hfi_msg_inv_count64,
&hfi_bitcoin_msg_inv,
&hfi_msg_inv_type,
&hfi_msg_inv_hash,
&hfi_msg_getdata_count8,
&hfi_msg_getdata_count16,
&hfi_msg_getdata_count32,
&hfi_msg_getdata_count64,
&hfi_bitcoin_msg_getdata,
&hfi_msg_getdata_type,
&hfi_msg_getdata_hash,
&hfi_msg_getblocks_count8,
&hfi_msg_getblocks_count16,
&hfi_msg_getblocks_count32,
&hfi_msg_getblocks_count64,
&hfi_bitcoin_msg_getblocks,
&hfi_msg_getblocks_start,
&hfi_msg_getblocks_stop,
&hfi_msg_getheaders_count8,
&hfi_msg_getheaders_count16,
&hfi_msg_getheaders_count32,
&hfi_msg_getheaders_count64,
&hfi_bitcoin_msg_getheaders,
&hfi_msg_getheaders_start,
&hfi_msg_getheaders_stop,
&hfi_bitcoin_msg_tx,
&hfi_msg_tx_version,
&hfi_msg_tx_in_count8,
&hfi_msg_tx_in_count16,
&hfi_msg_tx_in_count32,
&hfi_msg_tx_in_count64,
&hfi_msg_tx_in,
&hfi_msg_tx_in_prev_output,
&hfi_msg_tx_in_prev_outp_hash,
&hfi_msg_tx_in_prev_outp_index,
&hfi_msg_tx_in_script8,
&hfi_msg_tx_in_script16,
&hfi_msg_tx_in_script32,
&hfi_msg_tx_in_script64,
&hfi_msg_tx_in_sig_script,
&hfi_msg_tx_in_seq,
&hfi_msg_tx_out_count8,
&hfi_msg_tx_out_count16,
&hfi_msg_tx_out_count32,
&hfi_msg_tx_out_count64,
&hfi_msg_tx_out,
&hfi_msg_tx_out_value,
&hfi_msg_tx_out_script8,
&hfi_msg_tx_out_script16,
&hfi_msg_tx_out_script32,
&hfi_msg_tx_out_script64,
&hfi_msg_tx_out_script,
&hfi_msg_tx_lock_time,
&hfi_msg_block_transactions8,
&hfi_msg_block_transactions16,
&hfi_msg_block_transactions32,
&hfi_msg_block_transactions64,
&hfi_bitcoin_msg_block,
&hfi_msg_block_version,
&hfi_msg_block_prev_block,
&hfi_msg_block_merkle_root,
&hfi_msg_block_time,
&hfi_msg_block_bits,
&hfi_msg_block_nonce,
&hfi_services_network,
&hfi_address_services,
&hfi_address_address,
&hfi_address_port,
&hfi_string_value,
&hfi_string_varint_count8,
&hfi_string_varint_count16,
&hfi_string_varint_count32,
&hfi_string_varint_count64,
};
#endif
static gint *ett[] = {
&ett_bitcoin,
&ett_bitcoin_msg,
&ett_services,
&ett_address,
&ett_string,
&ett_addr_list,
&ett_inv_list,
&ett_getdata_list,
&ett_getblocks_list,
&ett_getheaders_list,
&ett_tx_in_list,
&ett_tx_in_outp,
&ett_tx_out_list,
};
static ei_register_info ei[] = {
{ &ei_bitcoin_command_unknown, { "bitcoin.command.unknown", PI_PROTOCOL, PI_WARN, "Unknown command", EXPFILL }},
};
module_t *bitcoin_module;
expert_module_t* expert_bitcoin;
int proto_bitcoin;
proto_bitcoin = proto_register_protocol("Bitcoin protocol", "Bitcoin", "bitcoin");
hfi_bitcoin = proto_registrar_get_nth(proto_bitcoin);
proto_register_subtree_array(ett, array_length(ett));
proto_register_fields(proto_bitcoin, hfi, array_length(hfi));
expert_bitcoin = expert_register_protocol(proto_bitcoin);
expert_register_field_array(expert_bitcoin, ei, array_length(ei));
bitcoin_handle = new_register_dissector("bitcoin", dissect_bitcoin, proto_bitcoin);
bitcoin_module = prefs_register_protocol(proto_bitcoin, NULL);
prefs_register_bool_preference(bitcoin_module, "desegment",
"Desegment all Bitcoin messages spanning multiple TCP segments",
"Whether the Bitcoin dissector should desegment all messages"
" spanning multiple TCP segments",
&bitcoin_desegment);
}
void
proto_reg_handoff_bitcoin(void)
{
dissector_add_handle("tcp.port", bitcoin_handle);
heur_dissector_add( "tcp", dissect_bitcoin_heur, hfi_bitcoin->id);
}
