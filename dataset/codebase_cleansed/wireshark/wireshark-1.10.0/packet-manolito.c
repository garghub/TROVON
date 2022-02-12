static void
dissect_manolito(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
unsigned int offset;
proto_item *ti;
proto_tree *manolito_tree;
const char* packet_type = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MANOLITO");
ti = proto_tree_add_item(tree, proto_manolito, tvb, 0, -1, ENC_NA);
manolito_tree = proto_item_add_subtree(ti, ett_manolito);
proto_tree_add_item(manolito_tree,
hf_manolito_checksum, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(manolito_tree,
hf_manolito_seqno, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(manolito_tree,
hf_manolito_src, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(manolito_tree,
hf_manolito_dest, tvb, 12, 4, ENC_BIG_ENDIAN);
if (tvb_reported_length(tvb) == 19) {
packet_type = "Ping (truncated)";
proto_tree_add_item(manolito_tree,
hf_manolito_options_short, tvb, 16, 3, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(manolito_tree,
hf_manolito_options, tvb, 16, 4, ENC_BIG_ENDIAN);
}
if (tvb_reported_length(tvb) <= 20)
{
col_set_str(pinfo->cinfo, COL_INFO, "Ping");
} else {
offset = 20;
do
{
guint16 field_name;
guint8 dtype;
guint8 length;
guint8* data;
int start;
char field_name_str[3];
const char* longname;
start = offset;
field_name = tvb_get_ntohs(tvb, offset);
offset += 2;
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
if (tvb_reported_length(tvb) == 20)
packet_type = "Ping";
switch(field_name)
{
case 0x5346: longname = "Shared Files"; break;
case 0x534b: longname = "Shared Kilobytes";break;
case 0x4e49: longname = "Network ID"; break;
case 0x4e43: longname = "Num. Connections";break;
case 0x4356: longname = "Client Version"; break;
case 0x564c: longname = "Velocity"; break;
case 0x464e: longname = "Filename"; break;
case 0x464c: longname = "File Length"; break;
case 0x4252: longname = "Bit Rate"; break;
case 0x4643: longname = "Frequency"; break;
case 0x5354: longname = "???"; break;
case 0x534c: longname = "Song Length (s)"; break;
case 0x434b: longname = "Checksum"; break;
case 0x4e4e: longname = "Nickname"; break;
case 0x434e: longname = "Client Name"; break;
case 0x5054: longname = "Port"; break;
case 0x484e: longname = "???"; break;
case 0x4d45: longname = "Message"; break;
case 0x4944: longname = "Identification"; break;
case 0x4144: longname = "???"; break;
default: longname = "unknown"; break;
}
#define MANOLITO_STRING 1
#define MANOLITO_INTEGER 0
dtype = tvb_get_guint8(tvb, offset);
length = tvb_get_guint8(tvb, ++offset);
data = (guint8 *)ep_alloc((guint)length + 1);
tvb_memcpy(tvb, data, ++offset, length);
offset += length;
field_name_str[0] = g_htons(field_name) & 0x00ff;
field_name_str[1] = (g_htons(field_name) & 0xff00) >> 8;
field_name_str[2] = 0;
if (dtype == MANOLITO_STRING)
{
data[length] = 0;
proto_tree_add_text(manolito_tree, tvb, start,
offset - start, "%s (%s): %s",
(char*)field_name_str, longname, data);
} else if (dtype == MANOLITO_INTEGER) {
int n = 0;
switch(length)
{
case 5: n += data[4] << ((length - 5) * 8);
case 4: n += data[3] << ((length - 4) * 8);
case 3: n += data[2] << ((length - 3) * 8);
case 2: n += data[1] << ((length - 2) * 8);
case 1: n += data[0] << ((length - 1) * 8);
}
proto_tree_add_text(manolito_tree, tvb, start,
offset - start, "%s (%s): %d",
(char*)field_name_str, longname, n);
} else {
proto_tree_add_text(manolito_tree, tvb, start,
offset - start, "unknown type %d", dtype);
}
} while(offset < tvb_reported_length(tvb));
}
if (packet_type)
{
col_set_str(pinfo->cinfo, COL_INFO, packet_type);
}
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
{ "Destination IP Address","manolito.dest",
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
};
static gint *ett[] = {
&ett_manolito,
};
proto_manolito = proto_register_protocol("Blubster/Piolet MANOLITO Protocol",
"Manolito", "manolito");
proto_register_field_array(proto_manolito, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_manolito(void)
{
dissector_handle_t manolito_handle;
manolito_handle = create_dissector_handle(dissect_manolito,
proto_manolito);
dissector_add_uint("udp.port", 41170, manolito_handle);
}
