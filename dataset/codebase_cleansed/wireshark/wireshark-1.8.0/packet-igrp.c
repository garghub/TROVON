static void dissect_igrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 ver_and_opcode,version,opcode,network;
gint offset=IGRP_HEADER_LENGTH;
guint16 ninterior,nsystem,nexterior;
const guint8 *ipsrc;
proto_item *ti;
proto_tree *igrp_tree, *igrp_vektor_tree;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IGRP");
col_clear(pinfo->cinfo, COL_INFO);
ver_and_opcode = tvb_get_guint8(tvb,0);
if (check_col(pinfo->cinfo, COL_INFO)) {
switch (ver_and_opcode) {
case 0x11:
col_set_str(pinfo->cinfo, COL_INFO, "Response" );
break;
case 0x12:
col_set_str(pinfo->cinfo, COL_INFO, "Request" );
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown version or opcode");
}
}
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_igrp, tvb, 0, -1,
"Cisco IGRP");
igrp_tree = proto_item_add_subtree(ti, ett_igrp);
version = (ver_and_opcode&0xf0)>>4 ;
opcode = ver_and_opcode&0x0f ;
proto_tree_add_text(igrp_tree, tvb, 0,1,"IGRP Version : %d %s",version,(version==1?" ":" - Unknown Version, The dissection may be inaccurate"));
proto_tree_add_text(igrp_tree, tvb, 0,1,"Command : %d %s",opcode,(opcode==1?"(Response)":"(Request)"));
proto_tree_add_item(igrp_tree, hf_igrp_update, tvb, 1,1, ENC_BIG_ENDIAN);
proto_tree_add_item(igrp_tree, hf_igrp_as, tvb, 2,2, ENC_BIG_ENDIAN);
ninterior = tvb_get_ntohs(tvb,4);
nsystem = tvb_get_ntohs(tvb,6);
nexterior = tvb_get_ntohs(tvb,8);
if (pinfo->net_src.type == AT_IPv4) {
ipsrc = pinfo->net_src.data;
network = ipsrc[0];
} else
network = 0;
ti = proto_tree_add_text(igrp_tree, tvb, 4,2,"Interior routes : %d",ninterior);
for( ; ninterior>0 ; ninterior-- ) {
igrp_vektor_tree = proto_item_add_subtree(ti,ett_igrp_vektor);
next_tvb = tvb_new_subset(tvb, offset, IGRP_ENTRY_LENGTH, -1);
dissect_vektor_igrp (next_tvb,igrp_vektor_tree,network);
offset+=IGRP_ENTRY_LENGTH;
}
ti = proto_tree_add_text(igrp_tree, tvb, 6,2,"System routes : %d",nsystem);
for( ; nsystem>0 ; nsystem-- ) {
igrp_vektor_tree = proto_item_add_subtree(ti,ett_igrp_vektor);
next_tvb = tvb_new_subset(tvb, offset, IGRP_ENTRY_LENGTH, -1);
dissect_vektor_igrp (next_tvb,igrp_vektor_tree,0);
offset+=IGRP_ENTRY_LENGTH;
}
ti = proto_tree_add_text(igrp_tree, tvb, 8,2,"Exterior routes : %d",nexterior);
for( ; nexterior>0 ; nexterior-- ) {
igrp_vektor_tree = proto_item_add_subtree(ti,ett_igrp_vektor);
next_tvb = tvb_new_subset(tvb, offset, IGRP_ENTRY_LENGTH, -1);
dissect_vektor_igrp (next_tvb,igrp_vektor_tree,0);
offset+=IGRP_ENTRY_LENGTH;
}
proto_tree_add_text(igrp_tree, tvb, 10,2,"Checksum = 0x%4x",tvb_get_ntohs(tvb,10));
}
}
static void dissect_vektor_igrp (tvbuff_t *tvb, proto_tree *igrp_vektor_tree, guint8 network)
{
proto_item *ti;
guint8 *ptr_addr,addr[5];
addr[0]=network;
addr[1]=tvb_get_guint8(tvb,0);
addr[2]=tvb_get_guint8(tvb,1);
addr[3]=tvb_get_guint8(tvb,2);
addr[4]=0;
ptr_addr=addr;
if (network==0) ptr_addr=&addr[1];
ti = proto_tree_add_text (igrp_vektor_tree, tvb, 0 ,14,
"Entry for network %s", ip_to_str(ptr_addr)) ;
igrp_vektor_tree = proto_item_add_subtree(ti,ett_igrp_net);
proto_tree_add_text (igrp_vektor_tree, tvb, 0 ,3,"Network = %s",ip_to_str(ptr_addr)) ;
proto_tree_add_text (igrp_vektor_tree, tvb, 3 ,3,"Delay = %d",tvb_get_ntoh24(tvb,3)) ;
proto_tree_add_text (igrp_vektor_tree, tvb, 6 ,3,"Bandwidth = %d",tvb_get_ntoh24(tvb,6)) ;
proto_tree_add_text (igrp_vektor_tree, tvb, 9 ,2,"MTU = %d bytes",tvb_get_ntohs(tvb,9)) ;
proto_tree_add_text (igrp_vektor_tree, tvb, 11,1,"Reliability = %d",tvb_get_guint8(tvb,11)) ;
proto_tree_add_text (igrp_vektor_tree, tvb, 12,1,"Load = %d",tvb_get_guint8(tvb,12)) ;
proto_tree_add_text (igrp_vektor_tree, tvb, 13,1,"Hop count = %d hops",tvb_get_guint8(tvb,13)) ;
}
void proto_register_igrp(void)
{
static hf_register_info hf[] = {
{ &hf_igrp_update,
{ "Update Release", "igrp.update",
FT_UINT8, BASE_DEC, NULL, 0x0 ,
"Update Release number", HFILL }
},
{ &hf_igrp_as,
{ "Autonomous System", "igrp.as",
FT_UINT16, BASE_DEC, NULL, 0x0 ,
"Autonomous System number", HFILL }
}
};
static gint *ett[] = {
&ett_igrp,
&ett_igrp_vektor,
&ett_igrp_net
};
proto_igrp = proto_register_protocol("Cisco Interior Gateway Routing Protocol",
"IGRP", "igrp");
proto_register_field_array(proto_igrp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_igrp(void)
{
dissector_handle_t igrp_handle;
igrp_handle = create_dissector_handle(dissect_igrp, proto_igrp);
dissector_add_uint("ip.proto", IP_PROTO_IGRP, igrp_handle);
}
