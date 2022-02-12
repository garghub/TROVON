static void
dissect_pcli(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
guint32 cccid;
proto_tree *ti,*pcli_tree;
tvbuff_t * next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PCLI");
cccid = tvb_get_ntohl(tvb,0);
if(check_col(pinfo->cinfo,COL_INFO)){
col_add_fstr(pinfo->cinfo, COL_INFO, "CCCID: %u",cccid);
}
if(tree) {
ti = proto_tree_add_item(tree,proto_pcli,tvb,0,0,ENC_NA);
pcli_tree = proto_item_add_subtree(ti,ett_pcli);
proto_tree_add_uint(pcli_tree,hf_pcli_cccid,tvb,
0,4,cccid);
}
next_tvb = tvb_new_subset_remaining(tvb,4);
call_dissector(ip_handle,next_tvb,pinfo,tree);
}
void
proto_register_pcli(void) {
static hf_register_info hf[] = {
{ &hf_pcli_cccid,
{ "CCCID", "pcli.cccid", FT_UINT32, BASE_DEC, NULL, 0x0,
"Call Content Connection Identifier", HFILL }},
};
static gint *ett[] = {
&ett_pcli,
};
module_t *pcli_module;
proto_pcli = proto_register_protocol("Packet Cable Lawful Intercept",
"PCLI","pcli");
proto_register_field_array(proto_pcli,hf,array_length(hf));
proto_register_subtree_array(ett,array_length(ett));
pcli_module = prefs_register_protocol(proto_pcli,
proto_reg_handoff_pcli);
prefs_register_uint_preference(pcli_module, "udp_port",
"PCLI UDP Port",
"The UDP port on which "
"Packet Cable Lawful Intercept "
"packets will be sent",
10,&global_udp_port_pcli);
}
void
proto_reg_handoff_pcli(void) {
static gboolean pcli_initialized = FALSE;
static dissector_handle_t pcli_handle;
static guint udp_port_pcli;
if(!pcli_initialized) {
pcli_handle = create_dissector_handle(dissect_pcli,proto_pcli);
ip_handle = find_dissector("ip");
pcli_initialized = TRUE;
} else {
dissector_delete_uint("udp.port",udp_port_pcli,pcli_handle);
}
udp_port_pcli = global_udp_port_pcli;
dissector_add_uint("udp.port",global_udp_port_pcli,pcli_handle);
}
