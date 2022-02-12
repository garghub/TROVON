static guint
get_bitcoin_pdu_length(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint32 length;
length = BITCOIN_HEADER_LENGTH;
if (tvb_memeql(tvb, offset+4, "version", 7) != 0 &&
tvb_memeql(tvb, offset+4, "verack", 6) != 0)
{
length += 4;
}
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
proto_tree_add_boolean(tree, hf_services_network, tvb, offset, 4, (guint32)services);
return tree;
}
static proto_tree *
create_address_tree(tvbuff_t *tvb, proto_item *ti, guint32 offset)
{
proto_tree *tree;
tree = proto_item_add_subtree(ti, ett_address);
ti = proto_tree_add_item(tree, hf_address_services, tvb, offset, 8, ENC_LITTLE_ENDIAN);
create_services_tree(tvb, ti, offset);
offset += 8;
proto_tree_add_item(tree, hf_address_address, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(tree, hf_address_port, tvb, offset, 2, ENC_LITTLE_ENDIAN);
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
gint hf8, gint hf16, gint hf32, gint hf64)
{
switch (length)
{
case 1:
proto_tree_add_item(tree, hf8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case 3:
proto_tree_add_item(tree, hf16, tvb, offset+1, 2, ENC_LITTLE_ENDIAN);
break;
case 5:
proto_tree_add_item(tree, hf32, tvb, offset+1, 4, ENC_LITTLE_ENDIAN);
break;
case 9:
proto_tree_add_item(tree, hf64, tvb, offset+1, 8, ENC_LITTLE_ENDIAN);
break;
}
}
static void
dissect_bitcoin_msg_version(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
proto_item *ti;
gint subver_length;
guint32 version;
guint32 offset = 0;
if (!tree)
return;
ti = proto_tree_add_item(tree, hf_bitcoin_msg_version, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
version = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_msg_version_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
ti = proto_tree_add_item(tree, hf_msg_version_services, tvb, offset, 8, ENC_LITTLE_ENDIAN);
create_services_tree(tvb, ti, offset);
offset += 8;
proto_tree_add_item(tree, hf_msg_version_timestamp, tvb, offset, 8, ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN);
offset += 8;
ti = proto_tree_add_item(tree, hf_msg_version_addr_me, tvb, offset, 26, ENC_NA);
create_address_tree(tvb, ti, offset);
offset += 26;
if (version >= 106)
{
ti = proto_tree_add_item(tree, hf_msg_version_addr_you, tvb, offset, 26, ENC_NA);
create_address_tree(tvb, ti, offset);
offset += 26;
proto_tree_add_item(tree, hf_msg_version_nonce, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
subver_length = 0;
subver_length = tvb_strsize(tvb, offset);
proto_tree_add_item(tree, hf_msg_version_subver, tvb, offset, subver_length, ENC_ASCII|ENC_NA);
offset += subver_length;
if (version >= 209)
{
proto_tree_add_item(tree, hf_msg_version_start_height, tvb, offset, 4, ENC_LITTLE_ENDIAN);
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
ti = proto_tree_add_item(tree, hf_bitcoin_msg_addr, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, hf_msg_addr_count8, hf_msg_addr_count16,
hf_msg_addr_count32, hf_msg_addr_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree *subtree;
ti = proto_tree_add_item(tree, hf_msg_addr_address, tvb, offset, 30, ENC_NA);
subtree = create_address_tree(tvb, ti, offset+4);
proto_tree_add_item(subtree, hf_msg_addr_timestamp, tvb, offset, 4, ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN);
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
ti = proto_tree_add_item(tree, hf_bitcoin_msg_inv, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, hf_msg_inv_count8, hf_msg_inv_count16,
hf_msg_inv_count32, hf_msg_inv_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree *subtree;
ti = proto_tree_add_text(tree, tvb, offset, 36, "Inventory vector");
subtree = proto_item_add_subtree(ti, ett_inv_list);
proto_tree_add_item(subtree, hf_msg_inv_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_msg_inv_hash, tvb, offset, 32, ENC_NA);
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
ti = proto_tree_add_item(tree, hf_bitcoin_msg_getdata, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, hf_msg_getdata_count8, hf_msg_getdata_count16,
hf_msg_getdata_count32, hf_msg_getdata_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree *subtree;
ti = proto_tree_add_text(tree, tvb, offset, 36, "Inventory vector");
subtree = proto_item_add_subtree(ti, ett_getdata_list);
proto_tree_add_item(subtree, hf_msg_getdata_type, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(subtree, hf_msg_getdata_hash, tvb, offset, 32, ENC_NA);
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
ti = proto_tree_add_item(tree, hf_bitcoin_msg_getblocks, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
proto_tree_add_item(tree, hf_msg_version_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, hf_msg_getblocks_count8, hf_msg_getblocks_count16,
hf_msg_getblocks_count32, hf_msg_getblocks_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree_add_item(tree, hf_msg_getblocks_start, tvb, offset, 32, ENC_NA);
offset += 32;
}
proto_tree_add_item(tree, hf_msg_getblocks_stop, tvb, offset, 32, ENC_NA);
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
ti = proto_tree_add_item(tree, hf_bitcoin_msg_getheaders, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, hf_msg_getheaders_count8, hf_msg_getheaders_count16,
hf_msg_getheaders_count32, hf_msg_getheaders_count64);
offset += length;
for (; count > 0; count--)
{
proto_tree_add_item(tree, hf_msg_getheaders_start, tvb, offset, 32, ENC_NA);
offset += 32;
}
proto_tree_add_item(tree, hf_msg_getheaders_stop, tvb, offset, 32, ENC_NA);
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
rti = proto_tree_add_item(tree, hf_bitcoin_msg_tx, tvb, offset, -1, ENC_NA);
} else {
rti = proto_tree_add_none_format(tree, hf_bitcoin_msg_tx, tvb, offset, -1, "Tx message [ %4d ]", msgnum);
}
tree = proto_item_add_subtree(rti, ett_bitcoin_msg);
proto_tree_add_item(tree, hf_msg_tx_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
get_varint(tvb, offset, &count_length, &in_count);
add_varint_item(tree, tvb, offset, count_length, hf_msg_tx_in_count8, hf_msg_tx_in_count16,
hf_msg_tx_in_count32, hf_msg_tx_in_count64);
offset += count_length;
for (; in_count > 0; in_count--)
{
proto_tree *subtree;
proto_tree *prevtree;
proto_item *ti;
proto_item *pti;
guint64 script_length;
get_varint(tvb, offset+36, &count_length, &script_length);
ti = proto_tree_add_item(tree, hf_msg_tx_in, tvb, offset,
36 + count_length + (guint)script_length + 4, ENC_NA);
subtree = proto_item_add_subtree(ti, ett_tx_in_list);
pti = proto_tree_add_item(subtree, hf_msg_tx_in_prev_output, tvb, offset, 36, ENC_NA);
prevtree = proto_item_add_subtree(pti, ett_tx_in_outp);
proto_tree_add_item(prevtree, hf_msg_tx_in_prev_outp_hash, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(prevtree, hf_msg_tx_in_prev_outp_index, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
add_varint_item(subtree, tvb, offset, count_length, hf_msg_tx_in_script8, hf_msg_tx_in_script16,
hf_msg_tx_in_script32, hf_msg_tx_in_script64);
offset += count_length;
if ((offset + script_length) > G_MAXINT)
THROW(ReportedBoundsError);
proto_tree_add_item(subtree, hf_msg_tx_in_sig_script, tvb, offset, (guint)script_length, ENC_NA);
offset += (guint)script_length;
proto_tree_add_item(subtree, hf_msg_tx_in_seq, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
get_varint(tvb, offset, &count_length, &out_count);
add_varint_item(tree, tvb, offset, count_length, hf_msg_tx_out_count8, hf_msg_tx_out_count16,
hf_msg_tx_out_count32, hf_msg_tx_out_count64);
offset += count_length;
for (; out_count > 0; out_count--)
{
proto_item *ti;
proto_tree *subtree;
guint64 script_length;
get_varint(tvb, offset+8, &count_length, &script_length);
ti = proto_tree_add_item(tree, hf_msg_tx_out, tvb, offset,
8 + count_length + (guint)script_length , ENC_NA);
subtree = proto_item_add_subtree(ti, ett_tx_out_list);
proto_tree_add_item(subtree, hf_msg_tx_out_value, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
add_varint_item(subtree, tvb, offset, count_length, hf_msg_tx_out_script8, hf_msg_tx_out_script16,
hf_msg_tx_out_script32, hf_msg_tx_out_script64);
offset += count_length;
if ((offset + script_length) > G_MAXINT)
THROW(ReportedBoundsError);
proto_tree_add_item(subtree, hf_msg_tx_out_script, tvb, offset, (guint)script_length, ENC_NA);
offset += (guint)script_length;
}
proto_tree_add_item(tree, hf_msg_tx_lock_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
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
ti = proto_tree_add_item(tree, hf_bitcoin_msg_block, tvb, offset, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin_msg);
proto_tree_add_item(tree, hf_msg_block_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msg_block_prev_block, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(tree, hf_msg_block_merkle_root, tvb, offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(tree, hf_msg_block_time, tvb, offset, 4, ENC_TIME_TIMESPEC|ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msg_block_bits, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_msg_block_nonce, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
get_varint(tvb, offset, &length, &count);
add_varint_item(tree, tvb, offset, length, hf_msg_block_transactions8, hf_msg_block_transactions16,
hf_msg_block_transactions32, hf_msg_block_transactions64);
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
static void dissect_bitcoin_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
guint32 i;
guint32 offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Bitcoin");
ti = proto_tree_add_item(tree, proto_bitcoin, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(ti, ett_bitcoin);
proto_tree_add_item(tree, hf_bitcoin_magic, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_bitcoin_command, tvb, 4, 12, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_bitcoin_length, tvb, 16, 4, ENC_LITTLE_ENDIAN);
offset = 20;
if (tvb_memeql(tvb, 4, "version", 7) != 0 &&
tvb_memeql(tvb, 4, "verack", 6) != 0)
{
proto_tree_add_item(tree, hf_bitcoin_checksum, tvb, 20, 4, ENC_BIG_ENDIAN);
offset += 4;
}
for (i = 0; i < array_length(msg_dissectors); i++)
{
if (tvb_memeql(tvb, 4, msg_dissectors[i].command,
strlen(msg_dissectors[i].command)) == 0)
{
tvbuff_t *tvb_sub;
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", msg_dissectors[i].command);
tvb_sub = tvb_new_subset_remaining(tvb, offset);
msg_dissectors[i].function(tvb_sub, pinfo, tree);
return;
}
}
col_append_sep_str(pinfo->cinfo, COL_INFO, ", ", "[unknown command]");
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_ERROR, "Unknown command");
}
static int
dissect_bitcoin(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, bitcoin_desegment, BITCOIN_HEADER_LENGTH,
get_bitcoin_pdu_length, dissect_bitcoin_tcp_pdu);
return tvb_reported_length(tvb);
}
static gboolean
dissect_bitcoin_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
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
static hf_register_info hf[] = {
{ &hf_bitcoin_magic,
{ "Packet magic", "bitcoin.magic", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_command,
{ "Command name", "bitcoin.command", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_length,
{ "Payload Length", "bitcoin.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_checksum,
{ "Payload checksum", "bitcoin.checksum", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_msg_version,
{ "Version message", "bitcoin.version", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_version_version,
{ "Protocol version", "bitcoin.version.version", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_version_services,
{ "Node services", "bitcoin.version.services", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_version_addr_me,
{ "Address of emmitting node", "bitcoin.version.addr_me", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_version_addr_you,
{ "Address as seen by the emitting node", "bitcoin.version.addr_you", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_version_timestamp,
{ "Node timestamp", "bitcoin.version.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_version_nonce,
{ "Random nonce", "bitcoin.version.nonce", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_version_subver,
{ "Sub-version string", "bitcoin.version.subver", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_version_start_height,
{ "Block start height", "bitcoin.version.start_height", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_addr_count8,
{ "Count", "bitcoin.addr.count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_addr_count16,
{ "Count", "bitcoin.addr.count", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_addr_count32,
{ "Count", "bitcoin.addr.count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_addr_count64,
{ "Count", "bitcoin.addr.count", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_msg_addr,
{ "Address message", "bitcoin.addr", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_addr_address,
{ "Address", "bitcoin.addr.address", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_addr_timestamp,
{ "Address timestamp", "bitcoin.addr.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_inv_count8,
{ "Count", "bitcoin.inv.count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_inv_count16,
{ "Count", "bitcoin.inv.count", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_inv_count32,
{ "Count", "bitcoin.inv.count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_inv_count64,
{ "Count", "bitcoin.inv.count", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_msg_inv,
{ "Inventory message", "bitcoin.inv", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_inv_type,
{ "Type", "bitcoin.inv.type", FT_UINT32, BASE_DEC, VALS(inv_types), 0x0, NULL, HFILL }
},
{ &hf_msg_inv_hash,
{ "Data hash", "bitcoin.inv.hash", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getdata_count8,
{ "Count", "bitcoin.getdata.count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getdata_count16,
{ "Count", "bitcoin.getdata.count", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getdata_count32,
{ "Count", "bitcoin.getdata.count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getdata_count64,
{ "Count", "bitcoin.getdata.count", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_msg_getdata,
{ "Getdata message", "bitcoin.getdata", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getdata_type,
{ "Type", "bitcoin.getdata.type", FT_UINT32, BASE_DEC, VALS(inv_types), 0x0, NULL, HFILL }
},
{ &hf_msg_getdata_hash,
{ "Data hash", "bitcoin.getdata.hash", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getblocks_count8,
{ "Count", "bitcoin.getblocks.count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getblocks_count16,
{ "Count", "bitcoin.getblocks.count", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getblocks_count32,
{ "Count", "bitcoin.getblocks.count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getblocks_count64,
{ "Count", "bitcoin.getblocks.count", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_msg_getblocks,
{ "Getdata message", "bitcoin.getblocks", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getblocks_start,
{ "Starting hash", "bitcoin.getblocks.hash_start", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getblocks_stop,
{ "Stopping hash", "bitcoin.getblocks.hash_stop", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getheaders_count8,
{ "Count", "bitcoin.getheaders.count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getheaders_count16,
{ "Count", "bitcoin.getheaders.count", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getheaders_count32,
{ "Count", "bitcoin.getheaders.count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getheaders_count64,
{ "Count", "bitcoin.getheaders.count", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_msg_getheaders,
{ "Getheaders message", "bitcoin.getheaders", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getheaders_start,
{ "Starting hash", "bitcoin.getheaders.hash_start", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_getheaders_stop,
{ "Stopping hash", "bitcoin.getheaders.hash_stop", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_msg_tx,
{ "Tx message", "bitcoin.tx", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_version,
{ "Transaction version", "bitcoin.tx.version", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_count8,
{ "Input Count", "bitcoin.tx.input_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_count16,
{ "Input Count", "bitcoin.tx.input_count", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_count32,
{ "Input Count", "bitcoin.tx.input_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_count64,
{ "Input Count", "bitcoin.tx.input_count", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in,
{ "Transaction input", "bitcoin.tx.in", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_prev_output,
{ "Previous output", "bitcoin.tx.in.prev_output", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_prev_outp_hash,
{ "Hash", "bitcoin.tx.in.prev_output.hash", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_prev_outp_index,
{ "Index", "bitcoin.tx.in.prev_output.index", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_script8,
{ "Script Length", "bitcoin.tx.in.script_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_script16,
{ "Script Length", "bitcoin.tx.in.script_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_script32,
{ "Script Length", "bitcoin.tx.in.script_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_script64,
{ "Script Length", "bitcoin.tx.in.script_length", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_sig_script,
{ "Signature script", "bitcoin.tx.in.sig_script", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_in_seq,
{ "Sequence", "bitcoin.tx.in.seq", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_count8,
{ "Output Count", "bitcoin.tx.output_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_count16,
{ "Output Count", "bitcoin.tx.output_count", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_count32,
{ "Output Count", "bitcoin.tx.output_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_count64,
{ "Output Count", "bitcoin.tx.output_count", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out,
{ "Transaction output", "bitcoin.tx.out", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_value,
{ "Value", "bitcoin.tx.out.value", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_script8,
{ "Script Length", "bitcoin.tx.out.script_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_script16,
{ "Script Length", "bitcoin.tx.out.script_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_script32,
{ "Script Length", "bitcoin.tx.out.script_length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_script64,
{ "Script Length", "bitcoin.tx.out.script_length", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_out_script,
{ "Script", "bitcoin.tx.out.script", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_tx_lock_time,
{ "Block lock time or block ID", "bitcoin.tx.lock_time", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_transactions8,
{ "Number of transactions", "bitcoin.block.num_transactions", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_transactions16,
{ "Number of transactions", "bitcoin.tx.num_transactions", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_transactions32,
{ "Number of transactions", "bitcoin.tx.num_transactions", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_transactions64,
{ "Number of transactions", "bitcoin.tx.num_transactions", FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_bitcoin_msg_block,
{ "Block message", "bitcoin.block", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_version,
{ "Block version", "bitcoin.block.version", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_prev_block,
{ "Previous block", "bitcoin.block.prev_block", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_merkle_root,
{ "Merkle root", "bitcoin.block.merkle_root", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_time,
{ "Block timestamp", "bitcoin.block.timestamp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_bits,
{ "Bits", "bitcoin.block.merkle_root", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_msg_block_nonce,
{ "Nonce", "bitcoin.block.nonce", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_services_network,
{ "Network node", "bitcoin.services.network", FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x1, NULL, HFILL }
},
{ &hf_address_services,
{ "Node services", "bitcoin.address.services", FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL }
},
{ &hf_address_address,
{ "Node address", "bitcoin.address.address", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }
},
{ &hf_address_port,
{ "Node port", "bitcoin.address.port", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_bitcoin,
&ett_bitcoin_msg,
&ett_services,
&ett_address,
&ett_addr_list,
&ett_inv_list,
&ett_getdata_list,
&ett_getblocks_list,
&ett_getheaders_list,
&ett_tx_in_list,
&ett_tx_in_outp,
&ett_tx_out_list,
};
module_t *bitcoin_module;
proto_bitcoin = proto_register_protocol( "Bitcoin protocol", "Bitcoin",
"bitcoin");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_bitcoin, hf, array_length(hf));
new_register_dissector("bitcoin", dissect_bitcoin, proto_bitcoin);
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
bitcoin_handle = find_dissector("bitcoin");
dissector_add_handle("tcp.port", bitcoin_handle);
heur_dissector_add( "tcp", dissect_bitcoin_heur, proto_bitcoin);
}
