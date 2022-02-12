static int
dissect_manolito(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* dissector_data _U_)
{
gint offset = 0;
proto_item *ti;
proto_tree *manolito_tree;
gchar *packet_type = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MANOLITO");
ti = proto_tree_add_item(tree, proto_manolito, tvb, offset, -1, ENC_NA);
manolito_tree = proto_item_add_subtree(ti, ett_manolito);
proto_tree_add_item(manolito_tree,
hf_manolito_checksum, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(manolito_tree,
hf_manolito_seqno, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(manolito_tree,
hf_manolito_src, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(manolito_tree,
hf_manolito_dest, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (tvb_reported_length_remaining(tvb, offset) == 3) {
proto_tree_add_item(manolito_tree,
hf_manolito_options_short, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
col_set_str(pinfo->cinfo, COL_INFO, "Ping (truncated)");
return offset;
}
proto_tree_add_item(manolito_tree,
hf_manolito_options, tvb, 16, 4, ENC_BIG_ENDIAN);
offset += 4;
if (tvb_reported_length_remaining(tvb, offset) == 0) {
col_set_str(pinfo->cinfo, COL_INFO, "Ping");
return offset;
}
do
{
guint16 field_name;
guint8 dtype;
guint8 length;
int start;
guint8 *field_name_str;
start = offset;
field_name = tvb_get_ntohs(tvb, offset);
field_name_str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, 2, ENC_ASCII);
if (!packet_type) {
if (field_name == 0x434b)
packet_type = "Search Hit";
if (field_name == 0x4e43)
packet_type = "User Information";
if (field_name == 0x464e)
packet_type = "Search Query";
if (field_name == 0x4944)
packet_type = "Search Query (by hash)";
if (field_name == 0x5054)
packet_type = "Download Request";
if (field_name == 0x4d45)
packet_type = "Chat";
}
offset += 2;
dtype = tvb_get_guint8(tvb, offset);
offset++;
length = tvb_get_guint8(tvb, offset);
offset++;
if (dtype == MANOLITO_STRING) {
guint8 *str;
str = tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII);
proto_tree_add_string_format(manolito_tree, hf_manolito_string, tvb, start,
4+length, str, "%s (%s): %s",
field_name_str,
val_to_str_ext(field_name, &field_longname_ext, "unknown"),
str);
offset += length;
}
else if (dtype == MANOLITO_INTEGER) {
gboolean len_ok = TRUE;
guint64 n = 0;
switch(length)
{
case 5:
n = tvb_get_ntoh40(tvb, offset);
break;
case 4:
n = tvb_get_ntohl(tvb, offset);
break;
case 3:
n = tvb_get_ntoh24(tvb, offset);
break;
case 2:
n = tvb_get_ntohs(tvb, offset);
break;
case 1:
n = tvb_get_guint8(tvb, offset);
break;
default:
len_ok = FALSE;
}
if (len_ok) {
proto_tree_add_uint64_format(manolito_tree, hf_manolito_integer, tvb, start,
4+length, n, "%s (%s): %" G_GINT64_MODIFIER "u",
field_name_str,
val_to_str_ext(field_name, &field_longname_ext, "unknown"),
n);
}
else {
}
offset += length;
}
else {
proto_tree_add_expert_format(manolito_tree, pinfo, &ei_manolito_type,
tvb, start, offset - start, "Unknown type %d", dtype);
}
} while(tvb_reported_length_remaining(tvb, offset));
if (packet_type)
col_set_str(pinfo->cinfo, COL_INFO, packet_type);
return offset;
}
void
proto_register_manolito(void)
{
static hf_register_info hf[] = {
{ &hf_manolito_checksum,
{ "Checksum", "manolito.checksum",
FT_UINT32, BASE_HEX, NULL, 0,
"Checksum used for verifying integrity", HFILL }
},
{ &hf_manolito_seqno,
{ "Sequence Number", "manolito.seqno",
FT_UINT32, BASE_HEX, NULL, 0,
"Incremental sequence number", HFILL }
},
{ &hf_manolito_src,
{ "Forwarded IP Address", "manolito.src",
FT_IPv4, BASE_NONE, NULL, 0,
"Host packet was forwarded from (or 0)", HFILL }
},
{ &hf_manolito_dest,
{ "Destination IP Address", "manolito.dest",
FT_IPv4, BASE_NONE, NULL, 0,
"Destination IPv4 address", HFILL }
},
{ &hf_manolito_options_short,
{ "Options", "manolito.options",
FT_UINT24, BASE_HEX, NULL, 0,
"Packet-dependent data", HFILL }
},
{ &hf_manolito_options,
{ "Options", "manolito.options",
FT_UINT32, BASE_HEX, NULL, 0,
"Packet-dependent data", HFILL }
},
{ &hf_manolito_string,
{ "String field", "manolito.string",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_manolito_integer,
{ "Integer field", "manolito.integer",
FT_UINT40, BASE_DEC, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_manolito,
};
static ei_register_info ei[] = {
{ &ei_manolito_type, { "manolito.type.unknown", PI_PROTOCOL, PI_WARN, "Unknown type", EXPFILL }},
};
expert_module_t* expert_manolito;
proto_manolito = proto_register_protocol("Blubster/Piolet MANOLITO Protocol", "Manolito", "manolito");
proto_register_field_array(proto_manolito, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_manolito = expert_register_protocol(proto_manolito);
expert_register_field_array(expert_manolito, ei, array_length(ei));
}
void
proto_reg_handoff_manolito(void)
{
dissector_handle_t manolito_handle;
manolito_handle = create_dissector_handle(dissect_manolito,
proto_manolito);
dissector_add_uint("udp.port", 41170, manolito_handle);
}
