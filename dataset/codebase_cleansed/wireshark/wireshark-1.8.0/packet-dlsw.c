static void
dissect_dlsw_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint version,hlen = 0,mlen = 0,mtype,dlchlen = 0,direction,flags;
proto_tree *dlsw_tree = NULL, *ti,*ti2, *dlsw_header_tree = NULL;
proto_tree *dlsw_flags_tree,*dlsw_data_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DLSw");
version=tvb_get_guint8(tvb,0);
col_add_fstr(pinfo->cinfo, COL_INFO, "DLSw %s",val_to_str_const(version , dlsw_version_vals, "Unknown Version"));
if (tree)
{
ti = proto_tree_add_item(tree, proto_dlsw, tvb, 0, -1, ENC_NA);
dlsw_tree = proto_item_add_subtree(ti, ett_dlsw);
hlen=tvb_get_guint8(tvb,1);
ti2 = proto_tree_add_text (dlsw_tree, tvb, 0, hlen,"DLSw header, %s",
val_to_str_const(version , dlsw_version_vals, "Unknown Version"));
dlsw_header_tree = proto_item_add_subtree(ti2, ett_dlsw_header);
proto_tree_add_text (dlsw_header_tree,tvb,0 ,1,"Version = %s",
val_to_str_const(version , dlsw_version_vals, "Unknown Version, dissection may be inaccurate"));
proto_tree_add_text (dlsw_header_tree,tvb,1 ,1,"Header Length = %u",hlen) ;
mlen=tvb_get_ntohs(tvb,2);
proto_tree_add_text (dlsw_header_tree,tvb,2 ,2,"Message Length = %u",mlen);
proto_tree_add_text (dlsw_header_tree,tvb,4 ,4,"Remote DLC = %u",tvb_get_ntohl(tvb,4)) ;
proto_tree_add_text (dlsw_header_tree,tvb,8 ,4,"Remote DLC PID = %u",tvb_get_ntohl(tvb,8)) ;
proto_tree_add_text (dlsw_header_tree,tvb,12,2,"Reserved") ;
} ;
mtype=tvb_get_guint8(tvb,14);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",val_to_str_const(mtype , dlsw_type_vals, "Unknown message Type"));
if (tree)
{
proto_tree_add_text (dlsw_header_tree,tvb,14,1,"Message Type = %s (0x%02x)",
val_to_str_const(mtype , dlsw_type_vals, "Unknown Type"),mtype);
if (mtype==CAP_EXCHANGE)
{
proto_tree_add_text (dlsw_header_tree,tvb, 15,1,"Not used for CapEx") ;
}
else
{
flags = tvb_get_guint8(tvb,15);
ti2 = proto_tree_add_text (dlsw_header_tree, tvb, 15,1,"Flow ctrl byte = 0x%02x",flags);
dlsw_flags_tree = proto_item_add_subtree(ti2, ett_dlsw_fc);
proto_tree_add_text (dlsw_flags_tree, tvb, 15, 1, "%s",
decode_boolean_bitfield(flags, 0x80, 8,
"Flow Control Indication: yes",
"Flow Control Indication: no"));
if (flags & 0x80)
{
proto_tree_add_text (dlsw_flags_tree, tvb, 15, 1, "%s",
decode_boolean_bitfield(flags, 0x40, 8,
"Flow Control Acknowledgment: yes",
"Flow Control Acknowledgment: no"));
proto_tree_add_text (dlsw_flags_tree, tvb, 15, 1, "%s",
decode_enumerated_bitfield(flags, 0x07, 8,
dlsw_fc_cmd_vals,
"Flow Control Operator: %s"));
}
}
if (hlen != DLSW_INFO_HEADER)
{
if (mtype==CAP_EXCHANGE)
{
proto_tree_add_text (dlsw_header_tree,tvb, 16,1,"Protocol ID = 0x%02x",tvb_get_guint8(tvb,16)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 17,1,"Header Number = 0x%02x",tvb_get_guint8(tvb,17)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 18,5,"Not used for CapEx") ;
proto_tree_add_text (dlsw_header_tree,tvb, 23,1,"Old message type = %s (0x%02x)",
val_to_str_const(tvb_get_guint8(tvb,23) , dlsw_type_vals, "Unknown Type"),
tvb_get_guint8(tvb,23));
direction=tvb_get_guint8(tvb,38);
proto_tree_add_text (dlsw_header_tree,tvb, 24,14,"Not used for CapEx") ;
proto_tree_add_text (dlsw_header_tree,tvb, 38,1,"Frame direction = %s (0x%02x)",
val_to_str_const(direction , dlsw_capex_type_vals, "Unknown Direction"),
direction);
proto_tree_add_text (dlsw_header_tree,tvb, 39,33,"Not used for CapEx") ;
}
else
{
proto_tree_add_text (dlsw_header_tree,tvb, 16,1,"Protocol ID = 0x%02x",tvb_get_guint8(tvb,16)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 17,1,"Header Number = 0x%02x",tvb_get_guint8(tvb,17)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 18,2,"Reserved") ;
proto_tree_add_text (dlsw_header_tree,tvb, 20,1,"Largest Frame size = %u",tvb_get_guint8(tvb,20)) ;
flags = tvb_get_guint8(tvb,21);
ti2 = proto_tree_add_text (dlsw_header_tree,tvb, 21,1,"SSP Flags = 0x%02x",flags) ;
dlsw_flags_tree = proto_item_add_subtree(ti2, ett_dlsw_sspflags);
proto_tree_add_text (dlsw_flags_tree, tvb, 21, 1, "%s",
decode_boolean_bitfield(flags, 0x80, 8,
"Explorer message: yes",
"Explorer message: no"));
proto_tree_add_text (dlsw_header_tree,tvb, 22,1,"Circuit priority = %s",
val_to_str((tvb_get_guint8(tvb,22)&7),dlsw_pri_vals, "Unknown (%d)")) ;
proto_tree_add_text (dlsw_header_tree,tvb, 23,1,"Old message type = %s (0x%02x)",
val_to_str_const(tvb_get_guint8(tvb,23) , dlsw_type_vals, "Unknown Type"),
tvb_get_guint8(tvb,23));
proto_tree_add_text (dlsw_header_tree,tvb, 24,6,"Target MAC Address = %s",tvb_bytes_to_str(tvb,24,6)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 30,6,"Origin MAC Address = %s",tvb_bytes_to_str(tvb,30,6)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 36,1,"Origin Link SAP = 0x%02x",tvb_get_guint8(tvb,36)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 37,1,"Target Link SAP = 0x%02x",tvb_get_guint8(tvb,37)) ;
direction=tvb_get_guint8(tvb,38);
proto_tree_add_text (dlsw_header_tree,tvb, 38,1,"Frame direction = %s (0x%02x)",
val_to_str_const(direction , dlsw_frame_direction_vals, "Unknown Direction"),
direction);
proto_tree_add_text (dlsw_header_tree,tvb, 39,3,"Reserved") ;
dlchlen=tvb_get_ntohs(tvb,42);
if ( dlchlen > mlen )
{
proto_tree_add_text (dlsw_header_tree,tvb, 42,2,"DLC Header Length = %u (bogus, must be <= message length %u)",dlchlen, mlen) ;
return;
}
proto_tree_add_text (dlsw_header_tree,tvb, 42,2,"DLC Header Length = %u",dlchlen) ;
proto_tree_add_text (dlsw_header_tree,tvb, 44,4,"Origin DLC Port ID = %u",tvb_get_ntohl(tvb,44)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 48,4,"Origin DLC = %u",tvb_get_ntohl(tvb,48)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 52,4,"Origin Transport ID = %u",tvb_get_ntohl(tvb,52)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 56,4,"Target DLC Port ID = %u",tvb_get_ntohl(tvb,56)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 60,4,"Target DLC = %u",tvb_get_ntohl(tvb,60)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 64,4,"Target Transport ID = %u",tvb_get_ntohl(tvb,64)) ;
proto_tree_add_text (dlsw_header_tree,tvb, 68,4,"Reserved") ;
}
}
ti2 = proto_tree_add_text (dlsw_tree, tvb, hlen, mlen,"DLSw data");
dlsw_data_tree = proto_item_add_subtree(ti2, ett_dlsw_data);
switch (mtype)
{
case CAP_EXCHANGE:
dissect_dlsw_capex(tvb_new_subset(tvb, hlen, mlen, -1), dlsw_data_tree,ti2);
break;
case IFCM:
case INFOFRAME:
case KEEPALIVE:
proto_tree_add_text (dlsw_data_tree,tvb,hlen,mlen,"Data") ;
break;
default:
if (dlchlen!=0)
{
proto_tree_add_text (dlsw_data_tree,tvb,hlen,1,"DLC Header - AC byte : 0x%02x",tvb_get_guint8(tvb,hlen)) ;
proto_tree_add_text (dlsw_data_tree,tvb,hlen+1,1,"DLC Header - FC byte : 0x%02x",tvb_get_guint8(tvb,hlen+1)) ;
proto_tree_add_text (dlsw_data_tree,tvb,hlen+2,6,"DLC Header - DA : %s",tvb_bytes_to_str(tvb,hlen+2,6)) ;
proto_tree_add_text (dlsw_data_tree,tvb,hlen+8,6,"DLC Header - SA : %s",tvb_bytes_to_str(tvb,hlen+8,6)) ;
proto_tree_add_text (dlsw_data_tree,tvb,hlen+14,18,"DLC Header - RIF : %s",tvb_bytes_to_str(tvb,hlen+14,18)) ;
proto_tree_add_text (dlsw_data_tree,tvb,hlen+32,1,"DLC Header - DSAP : 0x%02x",tvb_get_guint8(tvb,hlen+32)) ;
proto_tree_add_text (dlsw_data_tree,tvb,hlen+33,1,"DLC Header - SSAP : 0x%02x",tvb_get_guint8(tvb,hlen+33)) ;
proto_tree_add_text (dlsw_data_tree,tvb,hlen+34,1,"DLC Header - Ctrl : 0x%02x",tvb_get_guint8(tvb,hlen+34)) ;
}
proto_tree_add_text (dlsw_data_tree,tvb,hlen+dlchlen,mlen-dlchlen,"Data") ;
}
}
}
static void
dissect_dlsw_capex(tvbuff_t *tvb, proto_tree *tree, proto_tree *ti2)
{
int mlen,vlen,vtype,offset=4,gdsid,sap,i=0;
proto_tree *ti,*dlsw_vector_tree;
mlen=tvb_get_ntohs(tvb,0);
gdsid=tvb_get_ntohs(tvb,2);
proto_tree_add_text (tree,tvb,0,2,"Capabilities Length = %d",mlen) ;
proto_tree_add_text (tree,tvb,2,2,"%s",val_to_str_const( gdsid, dlsw_gds_vals, "Invalid GDS ID"));
proto_item_append_text(ti2," - %s",val_to_str_const( gdsid, dlsw_gds_vals, "Invalid GDS ID"));
switch (gdsid) {
case DLSW_GDSID_ACK:
break;
case DLSW_GDSID_REF:
proto_tree_add_text (tree,tvb,4,2,"Error pointer = %d",tvb_get_ntohs(tvb,4));
proto_tree_add_text (tree,tvb,6,2,"Error cause = %s",
val_to_str_const(tvb_get_ntohs(tvb,6), dlsw_refuse_vals, "Unknown refuse cause"));
break;
case DLSW_GDSID_SEND:
while (offset < mlen){
vlen=tvb_get_guint8(tvb,offset);
if (vlen < 3) THROW(ReportedBoundsError);
vtype=tvb_get_guint8(tvb,offset+1);
ti=proto_tree_add_text (tree,tvb,offset,vlen,"%s",
val_to_str_const(vtype,dlsw_vector_vals,"Unknown vector type"));
dlsw_vector_tree = proto_item_add_subtree(ti, ett_dlsw_vector);
proto_tree_add_text (dlsw_vector_tree,tvb,offset,1, "Vector Length = %d",vlen);
proto_tree_add_text (dlsw_vector_tree,tvb,offset+1,1,"Vector Type = %s (0x%02x)",
val_to_str_const(vtype,dlsw_vector_vals,"Unknown vector type"), vtype);
switch (vtype){
case 0x81:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"OUI = 0x%06x",tvb_get_ntoh24(tvb,offset+2));
break;
case 0x82:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"DLSw Version = %d.%d",tvb_get_guint8(tvb,offset+2),tvb_get_guint8(tvb,offset+3));
break;
case 0x83:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"Initial Pacing Window = %d",tvb_get_ntohs(tvb,offset+2));
break;
case 0x84:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"Version String = %s",tvb_format_text(tvb,offset+2,vlen-2));
break;
case 0x85:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"MAC Address Exclusivity = %s",tvb_get_guint8(tvb,offset+2)==1?"On":"Off");
break;
case 0x86:
while (i<vlen-2)
{
sap=tvb_get_guint8(tvb,offset+2+i);
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2+i,1,
"SAP List Support = 0x%x0=%s 0x%x2=%s 0x%x4=%s 0x%x6=%s 0x%x8=%s 0x%xa=%s 0x%xc=%s 0x%xe=%s",
i,sap&0x80?"on ":"off",i,sap&0x40?"on ":"off",i,sap&0x20?"on ":"off",i,sap&0x10?"on ":"off",
i,sap&0x08?"on ":"off",i,sap&0x04?"on ":"off",i,sap&0x02?"on ":"off",i,sap&0x01?"on ":"off");
i++;
}
break;
case 0x87:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"TCP connections = %d",tvb_get_guint8(tvb,offset+2));
break;
case 0x88:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"NetBIOS Name Exclusivity = %s",tvb_get_guint8(tvb,offset+2)==1?"On":"Off");
break;
case 0x89:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"MAC Address List = %s / %s",tvb_bytes_to_str(tvb,offset+2,6)
,tvb_bytes_to_str(tvb,offset+8,6));
break;
case 0x8a:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"NetBIOS name = %s",
tvb_format_text(tvb,offset+2,vlen-2));
break;
case 0x8b:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"Vendor OUI = 0x%06x",tvb_get_ntoh24(tvb,offset+2));
break;
case 0x8c:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,
"Multicast Version Number = %d",tvb_get_guint8(tvb,offset+2));
break;
default:
proto_tree_add_text (dlsw_vector_tree,tvb,offset+2,vlen-2,"Vector Data = ???");
}
offset+=vlen;
};
break;
default:
proto_tree_add_text (tree,tvb,4,mlen - 4,"Unknown data");
}
}
static int
dissect_dlsw_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (match_strval(tvb_get_guint8(tvb, 0), dlsw_version_vals) == NULL)
{
return 0;
}
dissect_dlsw_pdu(tvb, pinfo, tree);
return tvb_length(tvb);
}
static guint
get_dlsw_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint hlen, mlen;
hlen=tvb_get_guint8(tvb,offset+1);
mlen = tvb_get_ntohs(tvb,offset+2);
return hlen + mlen;
}
static int
dissect_dlsw_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (match_strval(tvb_get_guint8(tvb, 0), dlsw_version_vals) == NULL)
{
return 0;
}
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4, get_dlsw_pdu_len, dissect_dlsw_pdu);
return tvb_length(tvb);
}
void
proto_register_dlsw(void)
{
static gint *ett[] = {
&ett_dlsw,
&ett_dlsw_header,
&ett_dlsw_fc,
&ett_dlsw_sspflags,
&ett_dlsw_data,
&ett_dlsw_vector,
};
proto_dlsw = proto_register_protocol("Data Link SWitching", "DLSw", "dlsw");
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dlsw(void)
{
dissector_handle_t dlsw_udp_handle, dlsw_tcp_handle;
dlsw_udp_handle = new_create_dissector_handle(dissect_dlsw_udp, proto_dlsw);
dissector_add_uint("udp.port", UDP_PORT_DLSW, dlsw_udp_handle);
dlsw_tcp_handle = new_create_dissector_handle(dissect_dlsw_tcp, proto_dlsw);
dissector_add_uint("tcp.port", TCP_PORT_DLSW, dlsw_tcp_handle);
}
