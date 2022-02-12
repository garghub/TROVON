static void
fw1_init(void)
{
interface_anzahl = 0;
}
static int
dissect_fw1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
proto_tree *fh_tree = NULL;
char direction;
char chain;
char *interface_name;
guint32 iface_len = 10;
wmem_strbuf_t *header;
int i;
gboolean found;
static const char fw1_header[] = "FW1 Monitor";
ethertype_data_t ethertype_data;
header = wmem_strbuf_new_label(wmem_packet_scope());
wmem_strbuf_append(header, fw1_header);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FW1");
col_clear(pinfo->cinfo, COL_INFO);
direction = tvb_get_guint8(tvb, 0);
if (!fw1_iflist_with_chain)
chain = ' ';
else
chain = tvb_get_guint8(tvb, 1);
if (fw1_with_uuid)
iface_len = 6;
interface_name=tvb_get_stringzpad(wmem_packet_scope(), tvb, 2, iface_len, ENC_ASCII|ENC_NA);
found=FALSE;
for (i=0; i<interface_anzahl; i++) {
if ( strcmp(p_interfaces[i], interface_name) == 0 ) {
found=TRUE;
break;
}
}
if (!found && interface_anzahl < MAX_INTERFACES) {
p_interfaces[interface_anzahl] = wmem_strdup(wmem_file_scope(), interface_name);
interface_anzahl++;
}
for (i=0; i<interface_anzahl; i++) {
if ( strcmp(p_interfaces[i], interface_name) == 0 ) {
wmem_strbuf_append_printf(header, " %c%c %s %c%c",
direction == 'i' ? 'i' : (direction == 'O' ? 'O' : ' '),
(direction == 'i' || direction == 'O') ? chain : ' ',
p_interfaces[i],
direction == 'I' ? 'I' : (direction == 'o' ? 'o' : ' '),
(direction == 'I' || direction == 'o') ? chain : ' '
);
} else {
wmem_strbuf_append_printf(header, " %s ", p_interfaces[i]);
}
}
col_add_str(pinfo->cinfo, COL_IF_DIR, wmem_strbuf_get_str(header) + sizeof(fw1_header) + 1);
if (tree) {
if (!fw1_summary_in_tree)
ti = proto_tree_add_protocol_format(tree, proto_fw1, tvb, 0, ETH_HEADER_SIZE, "%s", fw1_header);
else
ti = proto_tree_add_protocol_format(tree, proto_fw1, tvb, 0, ETH_HEADER_SIZE, "%s", wmem_strbuf_get_str(header));
fh_tree = proto_item_add_subtree(ti, ett_fw1);
proto_tree_add_item(fh_tree, hf_fw1_direction, tvb, 0, 1, ENC_ASCII|ENC_NA);
if (fw1_iflist_with_chain)
proto_tree_add_item(fh_tree, hf_fw1_chain, tvb, 1, 1, ENC_ASCII|ENC_NA);
proto_tree_add_item(fh_tree, hf_fw1_interface, tvb, 2, iface_len, ENC_ASCII|ENC_NA);
if (fw1_with_uuid)
proto_tree_add_item(fh_tree, hf_fw1_uuid, tvb, 8, 4, ENC_BIG_ENDIAN);
}
ethertype_data.etype = tvb_get_ntohs(tvb, 12);
ethertype_data.offset_after_ethertype = ETH_HEADER_SIZE;
ethertype_data.fh_tree = fh_tree;
ethertype_data.etype_id = hf_fw1_type;
ethertype_data.trailer_id = hf_fw1_trailer;
ethertype_data.fcs_len = 0;
call_dissector_with_data(ethertype_handle, tvb, pinfo, tree, &ethertype_data);
return tvb_captured_length(tvb);
}
void
proto_register_fw1(void)
{
static hf_register_info hf[] = {
{ &hf_fw1_direction,
{ "Direction", "fw1.direction", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_fw1_chain,
{ "Chain Position", "fw1.chain", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_fw1_interface,
{ "Interface", "fw1.interface", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_fw1_uuid,
{ "UUID", "fw1.uuid", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_fw1_type,
{ "Type", "fw1.type", FT_UINT16, BASE_HEX, VALS(etype_vals), 0x0,
NULL, HFILL }},
{ &hf_fw1_trailer,
{ "Trailer", "fw1.trailer", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_fw1,
};
module_t *fw1_module;
int i;
proto_fw1 = proto_register_protocol("Checkpoint FW-1", "FW-1", "fw1");
proto_register_field_array(proto_fw1, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
fw1_module = prefs_register_protocol(proto_fw1, NULL);
prefs_register_bool_preference(fw1_module, "summary_in_tree",
"Show FireWall-1 summary in protocol tree",
"Whether the FireWall-1 summary line should be shown in the protocol tree",
&fw1_summary_in_tree);
prefs_register_bool_preference(fw1_module, "with_uuid",
"Monitor file includes UUID",
"Whether the Firewall-1 monitor file includes UUID information",
&fw1_with_uuid);
prefs_register_bool_preference(fw1_module, "iflist_with_chain",
"Interface list includes chain position",
"Whether the interface list includes the chain position",
&fw1_iflist_with_chain);
register_dissector("fw1", dissect_fw1, proto_fw1);
for (i=0; i<MAX_INTERFACES; i++) {
p_interfaces[i] = NULL;
}
register_init_routine(fw1_init);
}
void
proto_reg_handoff_fw1(void)
{
ethertype_handle = find_dissector_add_dependency("ethertype", proto_fw1);
}
