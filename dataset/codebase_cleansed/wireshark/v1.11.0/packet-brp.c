static int
dissect_brp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *brp_item = NULL;
proto_tree *brp_tree = NULL;
gint offset = 0;
guint8 type = 0;
guint8 packet_type = tvb_get_guint8(tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_BRP);
col_add_fstr(pinfo->cinfo, COL_INFO, "Message Type - %s",
val_to_str(packet_type, brp_packettype_names, "Unknown (0x%02x)"));
if (tree) {
brp_item = proto_tree_add_item( tree, proto_brp, tvb, 0, -1, ENC_NA );
brp_tree = proto_item_add_subtree( brp_item, ett_brp);
type = tvb_get_guint8(tvb, offset);
offset += 0;
brp_item = proto_tree_add_item( brp_tree, hf_brp_type, tvb, offset, 1, ENC_BIG_ENDIAN );
offset += 1;
switch(type)
{
case 1:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_ver, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 2:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_stat, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 3:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
break;
case 4:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
break;
case 5:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
break;
case 6:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
break;
case 7:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_srcip, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_dstip, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_dstuport, tvb, offset, 2, ENC_BIG_ENDIAN );
offset +=2;
proto_tree_add_item( brp_tree, hf_brp_mbz, tvb, offset, 2, ENC_BIG_ENDIAN );
offset +=2;
proto_tree_add_item( brp_tree, hf_brp_bw, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_life, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 8:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_stat, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_flid, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 9:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_flid, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 10:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_stat, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 11:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_flid, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 12:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_stat, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_rmttl, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_srcip, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_dstip, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_dstuport, tvb, offset, 2, ENC_BIG_ENDIAN );
offset +=2;
proto_tree_add_item( brp_tree, hf_brp_mbz, tvb, offset, 2, ENC_BIG_ENDIAN );
offset +=2;
proto_tree_add_item( brp_tree, hf_brp_fltype, tvb, offset, 1, ENC_BIG_ENDIAN );
offset +=1;
proto_tree_add_item( brp_tree, hf_brp_bw, tvb, offset, 3, ENC_BIG_ENDIAN );
offset +=3;
proto_tree_add_item( brp_tree, hf_brp_life, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_flid, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 13:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_flid, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 14:
proto_tree_add_item( brp_tree, hf_brp_trans, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( brp_tree, hf_brp_stat, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_rmttl, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_srcip, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_dstip, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_dstuport, tvb, offset, 2, ENC_BIG_ENDIAN );
offset +=2;
proto_tree_add_item( brp_tree, hf_brp_mbz, tvb, offset, 2, ENC_BIG_ENDIAN );
offset +=2;
proto_tree_add_item( brp_tree, hf_brp_fltype, tvb, offset, 1, ENC_BIG_ENDIAN );
offset +=1;
proto_tree_add_item( brp_tree, hf_brp_bw, tvb, offset, 3, ENC_BIG_ENDIAN );
offset +=3;
proto_tree_add_item( brp_tree, hf_brp_life, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
proto_tree_add_item( brp_tree, hf_brp_flid, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
case 15:
proto_tree_add_item( brp_tree, hf_brp_mbz, tvb, offset, 3, ENC_BIG_ENDIAN );
offset +=3;
proto_tree_add_item( brp_tree, hf_brp_flid, tvb, offset, 4, ENC_BIG_ENDIAN );
offset +=4;
break;
default:
expert_add_info(pinfo, brp_item, &ei_brp_type_unknown);
break;
}
}
return offset;
}
void proto_register_brp (void)
{
module_t *brp_module;
expert_module_t* expert_brp;
static hf_register_info hf[] = {
{ &hf_brp_type,
{ "Type", "brp.type", FT_UINT8, BASE_DEC, VALS(brp_packettype_names), 0x0,
NULL, HFILL }},
{ &hf_brp_trans,
{ "Transaction ID", "brp.trans", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_ver,
{ "Version", "brp.ver", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_stat,
{ "Status", "brp.stat", FT_UINT8, BASE_DEC, VALS(brp_stat_vals), 0x0,
NULL, HFILL }},
{ &hf_brp_srcip,
{ "Source IP Address", "brp.srcip", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_dstip,
{ "Destination IP Address", "brp.dstip", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_dstuport,
{ "Destination UDP Port", "brp.dstuport", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_mbz,
{ "MBZ", "brp.mbz", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_bw,
{ "Bandwidth - Kbytes/sec", "brp.bw", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_life,
{ "Lifetime", "brp.life", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_flid,
{ "Flow Identifier", "brp.flid", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_fltype,
{ "Flow Type", "brp.fltype", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_brp_rmttl,
{ "Remaining TTL", "brp.rmttl", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_brp,
&ett_brp_type,
&ett_brp_trans,
&ett_brp_ver,
&ett_brp_stat,
&ett_brp_srcip,
&ett_brp_dstip,
&ett_brp_dstuport,
&ett_brp_mbz,
&ett_brp_bw,
&ett_brp_life,
&ett_brp_flid,
&ett_brp_fltype,
&ett_brp_rmttl
};
static ei_register_info ei[] = {
{ &ei_brp_type_unknown, { "brp.type.unknown", PI_UNDECODED, PI_WARN, "Unknown packet type", EXPFILL }},
};
proto_brp = proto_register_protocol ("BRP Protocol", "BRP", "brp");
proto_register_field_array (proto_brp, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
expert_brp = expert_register_protocol(proto_brp);
expert_register_field_array(expert_brp, ei, array_length(ei));
brp_module = prefs_register_protocol(proto_brp, proto_reg_handoff_brp);
prefs_register_uint_preference(brp_module, "port",
"BRP Port",
"Set the UDP port for BRP messages",
10, &global_brp_port);
brp_handle = new_register_dissector("brp", dissect_brp, proto_brp);
}
void proto_reg_handoff_brp(void)
{
static gboolean initialized = FALSE;
static guint saved_brp_port;
if (!initialized) {
dissector_add_handle("udp.port", brp_handle);
initialized = TRUE;
} else {
if (saved_brp_port != 0) {
dissector_delete_uint("udp.port", saved_brp_port, brp_handle);
}
}
if (global_brp_port != 0) {
dissector_add_uint("udp.port", global_brp_port, brp_handle);
}
saved_brp_port = global_brp_port;
}
