static void
dissect_tsp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *tsp_tree = NULL;
proto_item *tsp_item = NULL;
guint8 tsp_type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TSP");
col_clear(pinfo->cinfo, COL_INFO);
tsp_type = tvb_get_guint8(tvb, 0);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(tsp_type, names_tsp_type, "Unknown message type (%u)"));
if (tree) {
tsp_item = proto_tree_add_item(tree, proto_tsp,
tvb, 0, -1, ENC_NA);
if (tsp_item)
tsp_tree = proto_item_add_subtree(tsp_item, ett_tsp);
}
if (tsp_tree) {
proto_tree_add_uint(tsp_tree, hf_tsp_type,
tvb, 0, 1, tsp_type);
proto_tree_add_item(tsp_tree, hf_tsp_vers,
tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tsp_tree, hf_tsp_seq,
tvb, 2, 2, ENC_BIG_ENDIAN);
}
switch (tsp_type) {
case TSP_LOOP:
if (tsp_tree)
proto_tree_add_item(tsp_tree, hf_tsp_hopcnt,
tvb, 4, 1, ENC_BIG_ENDIAN);
break;
case TSP_SETTIME:
case TSP_ADJTIME:
case TSP_SETDATE:
case TSP_SETDATEREQ:
if (tsp_tree) {
proto_tree_add_item(tsp_tree, hf_tsp_time_sec,
tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tsp_tree, hf_tsp_time_usec,
tvb, 8, 4, ENC_BIG_ENDIAN);
}
break;
}
if (tsp_tree) {
proto_tree_add_item(tsp_tree, hf_tsp_name, tvb, 12,
-1, ENC_ASCII|ENC_NA);
}
}
void
proto_reg_handoff_tsp(void)
{
dissector_handle_t tsp_handle;
tsp_handle = create_dissector_handle(dissect_tsp, proto_tsp);
dissector_add_uint("udp.port", UDP_PORT_TIMED, tsp_handle);
}
void
proto_register_tsp(void)
{
static hf_register_info hf[] = {
{ &hf_tsp_type,
{ "Type", "tsp.type",
FT_UINT8, BASE_DEC, VALS(names_tsp_type), 0x0,
"Packet Type", HFILL }},
{ &hf_tsp_vers,
{ "Version", "tsp.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Protocol Version Number", HFILL }},
{ &hf_tsp_seq,
{ "Sequence", "tsp.sequence",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Sequence Number", HFILL }},
{ &hf_tsp_hopcnt,
{ "Hop Count", "tsp.hopcnt",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tsp_time_sec,
{ "Seconds", "tsp.sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tsp_time_usec,
{ "Microseconds", "tsp.usec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tsp_name,
{ "Machine Name", "tsp.name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Sender Machine Name", HFILL }}
};
static gint *ett[] = {
&ett_tsp
};
proto_tsp = proto_register_protocol("Time Synchronization Protocol",
"TSP", "tsp");
proto_register_field_array(proto_tsp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
