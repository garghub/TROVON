static dissector_handle_t
get_heuristic_handle(tvbuff_t *tvb)
{
int offset = MIRROR_HDR_SZ;
int byte0, byte1, byte2, byte3;
if (!tvb_bytes_exist(tvb, offset, 4))
return NULL;
byte0 = tvb_get_guint8(tvb, offset + 0);
byte1 = tvb_get_guint8(tvb, offset + 1);
byte2 = tvb_get_guint8(tvb, offset + 2);
byte3 = tvb_get_guint8(tvb, offset + 3);
if ( byte0 == 0x45 && ipv4_handle )
return ipv4_handle;
else if ( hi_nibble(byte0) == 6 && lo_nibble(byte1) == 0 && byte2 == 0 && byte3 == 0 && ipv6_handle )
return ipv6_handle;
else if ( byte0 == 0xff && byte1 == 0x03 && lo_nibble(byte2) == 0 && byte3 == 0x21 && hdlc_handle )
return hdlc_handle;
else
return NULL;
}
static int
dissect_jmirror(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
dissector_handle_t dissector_handle;
unsigned int midval, sidval;
proto_item *ti = NULL;
proto_tree *jmirror_tree = NULL;
tvbuff_t *next_tvb = NULL;
if ( !( dissector_handle = get_heuristic_handle(tvb) ) )
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Jmirror");
midval = tvb_get_ntohl(tvb, offset);
sidval = tvb_get_ntohl(tvb, offset+MIRROR_ID_SZ);
col_add_fstr(pinfo->cinfo, COL_INFO, "MID: 0X%08x (%d), SID: 0x%08x (%d)", midval, midval, sidval, sidval);
ti = proto_tree_add_protocol_format(tree, proto_jmirror, tvb, offset, MIRROR_HDR_SZ,
"Juniper Packet Mirror, MID: 0x%08x (%d), SID: 0x%08x (%d)", midval, midval, sidval, sidval);
jmirror_tree = proto_item_add_subtree(ti, ett_jmirror);
proto_tree_add_item(jmirror_tree, hf_jmirror_mid, tvb, offset, MIRROR_ID_SZ, ENC_BIG_ENDIAN);
offset += MIRROR_ID_SZ;
proto_tree_add_item(jmirror_tree, hf_jmirror_sid, tvb, offset, SESSION_ID_SZ, ENC_BIG_ENDIAN);
offset += SESSION_ID_SZ;
next_tvb = tvb_new_subset(tvb, offset, -1, -1);
return MIRROR_HDR_SZ + call_dissector(dissector_handle, next_tvb, pinfo, tree);
}
void
proto_register_jmirror(void)
{
module_t *jmirror_module = NULL;
static hf_register_info jmirror_hf[] = {
{ &hf_jmirror_mid,
{ "Jmirror Identifier", "jmirror.mid", FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
"Unique identifier of the mirrored session", HFILL }
},
{ &hf_jmirror_sid,
{ "Session Identifier", "jmirror.sid", FT_UINT32, BASE_HEX_DEC, NULL, 0x0,
"Unique identifier of the user session", HFILL }
}
};
static gint *jmirror_ett[] = {
&ett_jmirror
};
proto_jmirror = proto_register_protocol("Juniper Packet Mirror", "Jmirror", "jmirror");
jmirror_module = prefs_register_protocol(proto_jmirror, proto_reg_handoff_jmirror);
prefs_register_uint_preference(jmirror_module, "udp.port", "JMirror UDP Port",
"Set the port for JMirror Port (if other than the default of 30030)",
10, &global_jmirror_udp_port);
proto_register_field_array(proto_jmirror, jmirror_hf, array_length(jmirror_hf));
proto_register_subtree_array(jmirror_ett, array_length(jmirror_ett));
}
void
proto_reg_handoff_jmirror(void)
{
static int jmirror_inited = FALSE;
static guint jmirror_udp_port;
static dissector_handle_t jmirror_handle;
if ( !jmirror_inited )
{
jmirror_handle = new_create_dissector_handle(dissect_jmirror, proto_jmirror);
ipv4_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
hdlc_handle = find_dissector("pw_hdlc_nocw_hdlc_ppp");
jmirror_inited = TRUE;
} else {
dissector_delete_uint("udp.port", jmirror_udp_port, jmirror_handle);
}
jmirror_udp_port = global_jmirror_udp_port;
dissector_add_uint("udp.port", jmirror_udp_port, jmirror_handle);
}
