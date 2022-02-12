static void
dissect_linx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 dword;
int offset = 0;
int nexthdr;
int thishdr;
int size;
int pkgsize;
int payloadsize;
int version;
int conntype;
proto_tree *multicore_header_tree;
proto_tree *main_header_tree;
proto_tree *conn_header_tree;
proto_tree *ack_header_tree;
proto_tree *udata_header_tree;
proto_tree *nack_header_tree;
proto_tree *frag_header_tree;
proto_tree *rlnh_header_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LINX");
col_clear(pinfo->cinfo, COL_INFO);
{
proto_item *ti = NULL;
proto_tree *linx_tree = NULL;
proto_item *ver_item, *msg_item;
ti = proto_tree_add_item(tree, proto_linx, tvb, 0, -1, ENC_NA);
linx_tree = proto_item_add_subtree(ti, ett_linx);
dword = tvb_get_ntohl(tvb, offset);
nexthdr = (dword >> 28) & 0xf;
if (nexthdr == ETHCM_MAIN)
{
multicore_header_tree = proto_tree_add_subtree(linx_tree, tvb, 0, 4, ett_linx_multicore, NULL, "Multicore Header");
proto_tree_add_item(multicore_header_tree, hf_linx_nexthdr, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(multicore_header_tree, hf_linx_multicore_reserved, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(multicore_header_tree, hf_linx_multicore_dcoreid, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(multicore_header_tree, hf_linx_multicore_scoreid, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(multicore_header_tree, hf_linx_multicore_reserved1, tvb, 0, 4, ENC_BIG_ENDIAN);
offset += 4;
dword = tvb_get_ntohl(tvb, offset);
}
version = (dword >> 25) & 0x7;
nexthdr = (dword >> 28) & 0xf;
pkgsize = dword & 0x3fff;
main_header_tree = proto_tree_add_subtree(linx_tree, tvb, offset, 4, ett_linx_main, NULL, "Main Header");
proto_tree_add_item(main_header_tree, hf_linx_nexthdr , tvb, offset, 4, ENC_BIG_ENDIAN);
ver_item = proto_tree_add_item(main_header_tree, hf_linx_main_version , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(main_header_tree, hf_linx_main_reserved , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(main_header_tree, hf_linx_main_connection, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(main_header_tree, hf_linx_main_bundle , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(main_header_tree, hf_linx_main_pkgsize , tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (version < 2 || version > 3) {
expert_add_info(pinfo, ver_item, &ei_linx_version);
}
while (nexthdr != ETHCM_NONE) {
dword = tvb_get_ntohl(tvb, offset);
thishdr = nexthdr;
nexthdr = (dword >>28) & 0xf;
conntype = (dword >>24) & 0xf;
if ((thishdr != ETHCM_NONE) && (thishdr != ETHCM_MAIN)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(thishdr, linx_short_header_names, "unknown"));
if(thishdr == ETHCM_CONN)
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", val_to_str_const(conntype, linx_conn_cmd, "unknown"));
}
switch (thishdr) {
case ETHCM_CONN:
size = (dword >>21) & 0x7;
conn_header_tree = proto_tree_add_subtree(linx_tree, tvb, offset, (4+2*size), ett_linx_main, NULL, "Connection Header");
proto_tree_add_item(conn_header_tree, hf_linx_nexthdr , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conn_header_tree, hf_linx_conn_cmd , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conn_header_tree, hf_linx_conn_size , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conn_header_tree, hf_linx_conn_winsize , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conn_header_tree, hf_linx_conn_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(conn_header_tree, hf_linx_conn_publcid , tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if (size == 6) {
proto_tree_add_item(conn_header_tree, hf_linx_conn_dstmac, tvb, offset, 6, ENC_NA);
proto_tree_add_item(conn_header_tree, hf_linx_conn_srcmac, tvb, offset + 6, 6, ENC_NA);
}
offset += (2*size);
if(version > 2) {
proto_tree_add_item(conn_header_tree, hf_linx_conn_feat_neg_str, tvb, offset, -1, ENC_ASCII|ENC_NA);
offset += tvb_strnlen(tvb, offset, -1);
}
break;
case ETHCM_NACK:
nack_header_tree = proto_tree_add_subtree(linx_tree, tvb, offset, 4, ett_linx_main, NULL, "NACK Header");
proto_tree_add_item(nack_header_tree, hf_linx_nexthdr , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(nack_header_tree, hf_linx_nack_reserv1, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(nack_header_tree, hf_linx_nack_count , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(nack_header_tree, hf_linx_nack_reserv2, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(nack_header_tree, hf_linx_nack_seqno , tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case ETHCM_UDATA:
udata_header_tree = proto_tree_add_subtree(linx_tree, tvb, offset, 12, ett_linx_main, NULL, "Udata Header");
proto_tree_add_item(udata_header_tree, hf_linx_nexthdr, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(udata_header_tree, hf_linx_udata_reserved , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(udata_header_tree, hf_linx_udata_morefrags, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(udata_header_tree, hf_linx_udata_fragno , tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(version == 2) {
proto_tree_add_item(udata_header_tree, hf_linx_udata_signo , tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(udata_header_tree, hf_linx_udata_dstaddr16, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(udata_header_tree, hf_linx_udata_srcaddr16, tvb, offset, 4, ENC_BIG_ENDIAN);
dword = tvb_get_ntohl(tvb, offset);
} else {
proto_tree_add_item(udata_header_tree, hf_linx_udata_dstaddr32, tvb, offset, 4, ENC_BIG_ENDIAN);
dword = tvb_get_ntohl(tvb, offset);
offset += 4;
proto_tree_add_item(udata_header_tree, hf_linx_udata_srcaddr32, tvb, offset, 4, ENC_BIG_ENDIAN);
if(dword == 0 && tvb_get_ntohl(tvb, offset) == 0) {
dword = 0;
} else {
dword = 1;
}
}
offset += 4;
if (dword == 0) {
dword = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "rlnh:%s ", val_to_str_const(dword, linx_short_rlnh_names, "unknown"));
rlnh_header_tree = proto_tree_add_subtree(linx_tree, tvb, offset, 4, ett_linx_main, NULL, "RLNH");
if(version == 1) {
msg_item = proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_msg_type32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_msg_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
msg_item = proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_msg_type8, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
switch (dword) {
case RLNH_LINK_ADDR:
break;
case RLNH_QUERY_NAME:
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
offset += tvb_strnlen(tvb, offset, -1);
break;
case RLNH_PUBLISH:
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
offset += tvb_strnlen(tvb, offset, -1);
break;
case RLNH_UNPUBLISH:
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case RLNH_UNPUBLISH_ACK:
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case RLNH_INIT:
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_version, tvb, offset, 4, ENC_BIG_ENDIAN);
rlnh_version = tvb_get_ntohl(tvb, offset);
offset += 4;
break;
case RLNH_INIT_REPLY:
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(rlnh_version > 1) {
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_feat_neg_str, tvb, offset, -1, ENC_ASCII|ENC_NA);
offset += tvb_strnlen(tvb, offset, -1);
}
break;
case RLNH_PUBLISH_PEER:
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rlnh_header_tree, hf_linx_rlnh_peer_linkaddr, tvb, offset, -1, ENC_BIG_ENDIAN);
offset += tvb_strnlen(tvb, offset, -1);
break;
default:
expert_add_info(pinfo, msg_item, &ei_linx_rlnh_msg);
break;
}
} else {
payloadsize = pkgsize-offset;
if (payloadsize) {
proto_tree_add_item(linx_tree, hf_linx_udata_payload, tvb, offset, payloadsize, ENC_NA);
}
}
break;
case ETHCM_ACK:
ack_header_tree = proto_tree_add_subtree(linx_tree, tvb, offset, 4, ett_linx_main, NULL, "Ack Header");
proto_tree_add_item(ack_header_tree, hf_linx_nexthdr , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ack_header_tree, hf_linx_ack_request , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ack_header_tree, hf_linx_ack_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ack_header_tree, hf_linx_ack_ackno , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ack_header_tree, hf_linx_ack_seqno , tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case ETHCM_FRAG:
frag_header_tree = proto_tree_add_subtree(linx_tree, tvb, offset, 4, ett_linx_main, NULL, "Fragmentation Header");
proto_tree_add_item(frag_header_tree, hf_linx_nexthdr , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(frag_header_tree, hf_linx_frag_reserved , tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(frag_header_tree, hf_linx_frag_morefrags, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(frag_header_tree, hf_linx_frag_fragno , tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
default:
proto_tree_add_expert_format(linx_tree, pinfo, &ei_linx_header, tvb, offset, 4, "ERROR: Header \"%u\" not recognized", thishdr);
nexthdr = ETHCM_NONE;
break;
}
}
}
}
void
proto_register_linx(void)
{
static hf_register_info hf[] = {
{ &hf_linx_nexthdr,
{ "Next Header", "linx.nexthdr", FT_UINT32, BASE_DEC, VALS(linx_long_header_names), 0xf0000000, NULL, HFILL },
},
{ &hf_linx_multicore_scoreid,
{ "Source coreid", "linx.scoreid", FT_UINT32, BASE_DEC, VALS(linx_coreid), 0x0000ff00, "Multicore source core id", HFILL },
},
{ &hf_linx_multicore_dcoreid,
{ "Destination coreid", "linx.dcoreid", FT_UINT32, BASE_DEC, VALS(linx_coreid), 0x00ff0000, "Multicore destination core id", HFILL},
},
{ &hf_linx_multicore_reserved,
{ "Reserved", "linx.reserved8", FT_UINT32, BASE_DEC, NULL, 0x0f000000, "Multicore Hdr Reserved", HFILL},
},
{ &hf_linx_multicore_reserved1,
{ "Reserved", "linx.reserved9", FT_UINT32, BASE_DEC, NULL, 0x000000ff, "Multicore Hdr Reserved", HFILL},
},
{ &hf_linx_main_version,
{ "Version", "linx.version", FT_UINT32, BASE_DEC, NULL, 0x0e000000, "LINX Version", HFILL },
},
{ &hf_linx_main_reserved,
{ "Reserved", "linx.reserved1", FT_UINT32, BASE_DEC, NULL, 0x01800000, "Main Hdr Reserved", HFILL },
},
{ &hf_linx_main_connection,
{ "Connection", "linx.connection", FT_UINT32, BASE_DEC, NULL, 0x007f8000, NULL, HFILL },
},
{ &hf_linx_main_bundle,
{ "Bundle", "linx.bundle", FT_UINT32, BASE_DEC, VALS(linx_boolean), 0x00004000, NULL, HFILL },
},
{ &hf_linx_main_pkgsize,
{ "Package Size", "linx.pcksize", FT_UINT32, BASE_DEC, NULL, 0x00003fff, NULL, HFILL },
},
{ &hf_linx_udata_reserved,
{ "Reserved", "linx.reserved5", FT_UINT32, BASE_DEC, NULL, 0x0fff0000, "Udata Hdr Reserved", HFILL },
},
{ &hf_linx_udata_morefrags,
{ "More Fragments", "linx.morefra", FT_UINT32, BASE_DEC, VALS(linx_boolean), 0x00008000, "More fragments follow", HFILL },
},
{ &hf_linx_udata_fragno,
{ "Fragment Number", "linx.fragno", FT_UINT32, BASE_DEC, VALS(linx_nofragment), 0x00007fff, NULL, HFILL },
},
{ &hf_linx_udata_signo,
{ "Signal Number", "linx.signo", FT_UINT32, BASE_DEC, NULL, 0xffffffff, NULL, HFILL },
},
{ &hf_linx_udata_dstaddr16,
{ "Receiver Address", "linx.dstaddr", FT_UINT32, BASE_DEC, NULL, 0xffff0000, NULL, HFILL },
},
{ &hf_linx_udata_dstaddr32,
{ "Receiver Address", "linx.dstaddr32", FT_UINT32, BASE_DEC, NULL, 0xffffffff, NULL, HFILL },
},
{ &hf_linx_udata_srcaddr16,
{ "Sender Address", "linx.srcaddr", FT_UINT32, BASE_DEC, NULL, 0x0000ffff, NULL, HFILL },
},
{ &hf_linx_udata_srcaddr32,
{ "Sender Address", "linx.srcaddr32", FT_UINT32, BASE_DEC, NULL, 0xffffffff, NULL, HFILL },
},
{ &hf_linx_udata_payload,
{ "Payload", "linx.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_linx_ack_request,
{ "ACK-request", "linx.ackreq", FT_UINT32, BASE_DEC, VALS(linx_boolean), 0x08000000, NULL, HFILL },
},
{ &hf_linx_ack_reserved,
{ "Reserved", "linx.reserved7", FT_UINT32, BASE_DEC, NULL, 0x07000000, "ACK Hdr Reserved", HFILL },
},
{ &hf_linx_ack_ackno,
{ "ACK Number", "linx.ackno", FT_UINT32, BASE_DEC, NULL, 0x00fff000, NULL, HFILL },
},
{ &hf_linx_ack_seqno,
{ "Sequence Number", "linx.seqno", FT_UINT32, BASE_DEC, NULL, 0x00000fff, NULL, HFILL },
},
{ &hf_linx_conn_cmd,
{ "Command", "linx.cmd", FT_UINT32, BASE_DEC, VALS(linx_conn_cmd), 0x0f000000, NULL, HFILL },
},
{ &hf_linx_conn_size,
{ "Size", "linx.size", FT_UINT32, BASE_DEC, NULL, 0x00e00000, NULL, HFILL },
},
{ &hf_linx_conn_winsize,
{ "WinSize", "linx.winsize", FT_UINT32, BASE_DEC, NULL, 0x001e0000, "Window Size", HFILL },
},
{ &hf_linx_conn_reserved,
{ "Reserved", "linx.reserved3", FT_UINT32, BASE_DEC, NULL, 0x0001ff00, "Conn Hdr Reserved", HFILL },
},
{ &hf_linx_conn_publcid,
{ "Publish Conn ID", "linx.publcid", FT_UINT32, BASE_DEC, NULL, 0x000000ff, NULL, HFILL },
},
{ &hf_linx_conn_srcmac,
{ "Source", "linx.srcmaddr_ether", FT_ETHER, BASE_NONE, NULL, 0x0, "Source Media Address (ethernet)", HFILL },
},
{ &hf_linx_conn_dstmac,
{ "Destination", "linx.destmaddr_ether", FT_ETHER, BASE_NONE, NULL, 0x0, "Destination Media Address (ethernet)", HFILL },
},
{ &hf_linx_conn_feat_neg_str,
{ "Feature Negotiation String", "linx.feat_neg_str", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_linx_frag_reserved,
{ "Reserved", "linx.reserved6", FT_UINT32, BASE_DEC, NULL, 0x0fff0000, "Frag Hdr Reserved", HFILL },
},
{ &hf_linx_frag_morefrags,
{ "More Fragments", "linx.morefr2", FT_UINT32, BASE_DEC, VALS(linx_boolean), 0x00008000, NULL, HFILL },
},
{ &hf_linx_frag_fragno,
{ "Fragment Number", "linx.fragno2", FT_UINT32, BASE_DEC, NULL, 0x00007fff, NULL, HFILL },
},
{ &hf_linx_nack_reserv1,
{ "Reserved", "linx.nack_reserv", FT_UINT32, BASE_DEC, NULL, 0x0f000000, "Nack Hdr Reserved", HFILL },
},
{ &hf_linx_nack_count,
{ "Count", "linx.nack_count", FT_UINT32, BASE_DEC, NULL, 0x00ff0000, NULL, HFILL },
},
{ &hf_linx_nack_reserv2,
{ "Reserved", "linx.nack_reserv", FT_UINT32, BASE_DEC, NULL, 0x0000f000, "Nack Hdr Reserved", HFILL },
},
{ &hf_linx_nack_seqno,
{ "Sequence Number", "linx.nack_seqno", FT_UINT32, BASE_DEC, NULL, 0x00000fff, NULL, HFILL },
},
{ &hf_linx_rlnh_msg_type32,
{ "RLNH msg type", "linx.rlnh_msg_type", FT_UINT32, BASE_DEC, VALS(linx_long_rlnh_names), 0xffffffff, "RLNH message type", HFILL },
},
{ &hf_linx_rlnh_msg_type8,
{ "RLNH msg type", "linx.rlnh_msg_type8", FT_UINT32, BASE_DEC, VALS(linx_long_rlnh_names), 0x000000ff, "RLNH message type", HFILL },
},
{ &hf_linx_rlnh_msg_reserved,
{ "RLNH msg reserved", "linx.rlnh_msg_reserved", FT_UINT32, BASE_DEC, NULL, 0xffffff00, "RLNH message reserved", HFILL },
},
#if 0
{ &hf_linx_rlnh_linkaddr,
{ "RLNH linkaddr", "linx.rlnh_linkaddr", FT_UINT32, BASE_DEC, NULL, 0xffffffff, "RLNH linkaddress", HFILL },
},
#endif
{ &hf_linx_rlnh_src_linkaddr,
{ "RLNH src linkaddr", "linx.rlnh_src_linkaddr", FT_UINT32, BASE_DEC, NULL, 0xffffffff, "RLNH source linkaddress", HFILL },
},
{ &hf_linx_rlnh_peer_linkaddr,
{ "RLNH peer linkaddr", "linx.rlnh_peer_linkaddr", FT_UINT32, BASE_DEC, NULL, 0xffffffff, "RLNH peer linkaddress", HFILL },
},
{ &hf_linx_rlnh_version,
{ "RLNH version", "linx.rlnh_version", FT_UINT32, BASE_DEC, NULL, 0xffffffff, NULL, HFILL },
},
{ &hf_linx_rlnh_status,
{ "RLNH reply", "linx.rlnh_status", FT_UINT32, BASE_DEC, VALS(linx_rlnh_reply), 0xffffffff, NULL, HFILL },
},
{ &hf_linx_rlnh_name,
{ "RLNH name", "linx.rlnh_name", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_linx_rlnh_feat_neg_str,
{ "RLNH Feature Negotiation String", "linx.rlnh_feat_neg_str", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL },
}
};
static gint *ett[] = {
&ett_linx,
&ett_linx_multicore,
&ett_linx_main,
&ett_linx_error,
&ett_linx_udata,
&ett_linx_ack
};
static ei_register_info ei[] = {
{ &ei_linx_version, { "linx.version.unknown", PI_PROTOCOL, PI_WARN, "Version not yet supported and might be dissected incorrectly!", EXPFILL }},
{ &ei_linx_rlnh_msg, { "linx.rlnh_msg.unknown", PI_PROTOCOL, PI_WARN, "Message type not recognized", EXPFILL }},
{ &ei_linx_header, { "linx.header_not_recognized", PI_PROTOCOL, PI_WARN, "Header not recognized", EXPFILL }},
};
expert_module_t* expert_linx;
proto_linx = proto_register_protocol (
"ENEA LINX",
"LINX",
"linx"
);
proto_register_field_array(proto_linx, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_linx = expert_register_protocol(proto_linx);
expert_register_field_array(expert_linx, ei, array_length(ei));
}
void
proto_reg_handoff_linx(void)
{
dissector_handle_t linx_handle;
linx_handle = create_dissector_handle(dissect_linx, proto_linx);
dissector_add_uint("ethertype", ETHERTYPE_LINX, linx_handle);
}
static void
dissect_linx_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 dword;
int offset = 0;
proto_item *ti, *ver_item, *msg_item;
proto_tree *linx_tcp_tree;
proto_tree *tcp_header_tree;
proto_tree *rlnh_header_tree;
int payloadsize;
int version;
int size;
int type;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LINX/TCP");
col_clear(pinfo->cinfo, COL_INFO);
dword = tvb_get_ntohl(tvb, 0);
version = (dword >> 16) & 0xFF;
type = (dword >> 24) & 0xFF;
size = 16;
if (type == 0x55) {
dword = tvb_get_ntohl(tvb, 12);
size += (dword & 0xFFFFFFFF);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "tcpcm:%s ", val_to_str_const(type, linx_short_tcp_names, "unknown"));
ti = proto_tree_add_item(tree, proto_linx_tcp, tvb, 0, -1, ENC_NA);
linx_tcp_tree = proto_item_add_subtree(ti, ett_linx_tcp);
tcp_header_tree = proto_tree_add_subtree(linx_tcp_tree, tvb, 0, 16, ett_linx_tcp, NULL, "TCP CM Header");
proto_tree_add_item(tcp_header_tree, hf_linx_tcp_type, tvb, 0, 4, ENC_BIG_ENDIAN);
ver_item = proto_tree_add_item(tcp_header_tree, hf_linx_tcp_version, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tcp_header_tree, hf_linx_tcp_oob, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tcp_header_tree, hf_linx_tcp_src, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tcp_header_tree, hf_linx_tcp_dst, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tcp_header_tree, hf_linx_tcp_size, tvb, 12, 4, ENC_BIG_ENDIAN);
if (version != 3) {
expert_add_info(pinfo, ver_item, &ei_linx_tcp_version);
}
offset += 16;
if (type == 0x55) {
dword = tvb_get_ntohl(tvb, 8);
if (dword == 0) {
dword = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "rlnh:%s ", val_to_str_const(dword, linx_short_rlnh_names, "unknown"));
rlnh_header_tree = proto_tree_add_subtree(linx_tcp_tree, tvb, offset, 4, ett_linx_tcp, NULL, "RLNH");
if(version == 1) {
msg_item = proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_msg_type32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else {
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_msg_reserved, tvb, offset, 4, ENC_BIG_ENDIAN);
msg_item = proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_msg_type8, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
switch (dword) {
case RLNH_LINK_ADDR:
break;
case RLNH_QUERY_NAME:
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
break;
case RLNH_PUBLISH:
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_name, tvb, offset, -1, ENC_ASCII|ENC_NA);
break;
case RLNH_UNPUBLISH:
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case RLNH_UNPUBLISH_ACK:
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
break;
case RLNH_INIT:
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_version, tvb, offset, 4, ENC_BIG_ENDIAN);
rlnh_version = tvb_get_ntohl(tvb, offset);
break;
case RLNH_INIT_REPLY:
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(rlnh_version > 1) {
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_feat_neg_str, tvb, offset, -1, ENC_ASCII|ENC_NA);
}
break;
case RLNH_PUBLISH_PEER:
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_src_linkaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(rlnh_header_tree, hf_linx_tcp_rlnh_peer_linkaddr, tvb, offset, -1, ENC_BIG_ENDIAN);
break;
default:
expert_add_info(pinfo, msg_item, &ei_linx_tcp_rlnh_msg);
break;
}
} else {
payloadsize = size-offset;
if (payloadsize) {
proto_tree_add_item(linx_tcp_tree, hf_linx_tcp_payload, tvb, offset, payloadsize, ENC_NA);
}
}
}
}
void
proto_register_linx_tcp(void)
{
static hf_register_info hf[] = {
#if 0
{ &hf_linx_tcp_reserved,
{ "Reserved", "linxtcp.reserved", FT_UINT32, BASE_DEC, NULL, 0x00007FFF, "TCP CM reserved", HFILL },
},
#endif
{ &hf_linx_tcp_oob,
{ "Out-of-band", "linxtcp.oob", FT_UINT32, BASE_DEC, NULL, 0x00008000, "TCP CM oob", HFILL },
},
{ &hf_linx_tcp_version,
{ "Version", "linxtcp.version", FT_UINT32, BASE_DEC, NULL, 0x00FF0000, "TCP CM version", HFILL },
},
{ &hf_linx_tcp_type,
{ "Type", "linxtcp.type", FT_UINT32, BASE_HEX, VALS(linx_long_tcp_names), 0xFF000000, "TCP CM type", HFILL },
},
{ &hf_linx_tcp_src,
{ "Source", "linxtcp.src", FT_UINT32, BASE_DEC, NULL, 0xFFFFFFFF, "TCP CM source", HFILL },
},
{ &hf_linx_tcp_dst,
{ "Destination", "linxtcp.dst", FT_UINT32, BASE_DEC, NULL, 0xFFFFFFFF, "TCP CM destination", HFILL },
},
{ &hf_linx_tcp_size,
{ "Size", "linxtcp.size", FT_UINT32, BASE_DEC, NULL, 0xFFFFFFFF, "TCP CM size", HFILL },
},
{ &hf_linx_tcp_rlnh_msg_type32,
{ "RLNH msg type", "linxtcp.rlnh_msg_type", FT_UINT32, BASE_DEC, VALS(linx_long_rlnh_names), 0xffffffff, "RLNH message type", HFILL },
},
{ &hf_linx_tcp_rlnh_msg_type8,
{ "RLNH msg type", "linxtcp.rlnh_msg_type8", FT_UINT32, BASE_DEC, VALS(linx_long_rlnh_names), 0x000000ff, "RLNH message type", HFILL },
},
{ &hf_linx_tcp_rlnh_msg_reserved,
{ "RLNH msg reserved", "linxtcp.rlnh_msg_reserved", FT_UINT32, BASE_DEC, NULL, 0xffffff00, "RLNH message reserved", HFILL },
},
#if 0
{ &hf_linx_tcp_rlnh_linkaddr,
{ "RLNH linkaddr", "linxtcp.rlnh_linkaddr", FT_UINT32, BASE_DEC, NULL, 0xffffffff, "RLNH linkaddress", HFILL },
},
#endif
{ &hf_linx_tcp_rlnh_src_linkaddr,
{ "RLNH src linkaddr", "linxtcp.rlnh_src_linkaddr", FT_UINT32, BASE_DEC, NULL, 0xffffffff, "RLNH source linkaddress", HFILL },
},
{ &hf_linx_tcp_rlnh_peer_linkaddr,
{ "RLNH peer linkaddr", "linxtcp.rlnh_peer_linkaddr", FT_UINT32,
BASE_DEC, NULL, 0xffffffff, "RLNH peer linkaddress", HFILL },
},
{ &hf_linx_tcp_rlnh_version,
{ "RLNH version", "linxtcp.rlnh_version", FT_UINT32, BASE_DEC, NULL, 0xffffffff, NULL, HFILL },
},
{ &hf_linx_tcp_rlnh_status,
{ "RLNH reply", "linxtcp.rlnh_status", FT_UINT32, BASE_DEC, VALS(linx_rlnh_reply), 0xffffffff, NULL, HFILL },
},
{ &hf_linx_tcp_rlnh_name,
{ "RLNH name", "linxtcp.rlnh_name", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_linx_tcp_rlnh_feat_neg_str,
{ "RLNH Feature Negotiation String", "linxtcp.rlnh_feat_neg_str", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_linx_tcp_payload,
{ "Payload", "linxtcp.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
}
};
static gint *ett[] = {
&ett_linx_tcp,
};
static ei_register_info ei[] = {
{ &ei_linx_tcp_version, { "linxtcp.version.unknown", PI_PROTOCOL, PI_WARN, "Version not yet supported and might be dissected incorrectly!", EXPFILL }},
{ &ei_linx_tcp_rlnh_msg, { "linxtcp.rlnh_msg.unknown", PI_PROTOCOL, PI_WARN, "Message type not recognized", EXPFILL }},
};
expert_module_t* expert_linx_tcp;
module_t *linx_tcp_module;
proto_linx_tcp = proto_register_protocol("ENEA LINX over TCP", "LINX/TCP", "linxtcp");
proto_register_field_array(proto_linx_tcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_linx_tcp = expert_register_protocol(proto_linx_tcp);
expert_register_field_array(expert_linx_tcp, ei, array_length(ei));
linx_tcp_module = prefs_register_protocol(proto_linx_tcp, proto_reg_handoff_linx_tcp);
prefs_register_uint_preference(linx_tcp_module, "tcp.port",
"ENEA LINX over TCP Port",
"TCP port used by ENEA LINX, usually 19790",
10, &linx_tcp_port);
}
void
proto_reg_handoff_linx_tcp(void)
{
static dissector_handle_t linx_tcp_handle;
static gboolean linx_tcp_prefs_initialized = FALSE;
static guint saved_linx_tcp_port;
if (!linx_tcp_prefs_initialized) {
linx_tcp_handle = create_dissector_handle(dissect_linx_tcp, proto_linx_tcp);
dissector_add_uint("tcp.port", linx_tcp_port, linx_tcp_handle);
linx_tcp_prefs_initialized = TRUE;
}
else {
dissector_delete_uint("tcp.port", saved_linx_tcp_port, linx_tcp_handle);
}
saved_linx_tcp_port = linx_tcp_port;
if (linx_tcp_port != 0) {
dissector_add_uint("udp.port", linx_tcp_port, linx_tcp_handle);
}
}
