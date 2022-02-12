static int
dissect_gvcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint16 packet_type, packet_opcode, packet_plsize;
emem_strbuf_t *info;
if (tvb_length(tvb) < 8)
return 0;
packet_type = tvb_get_ntohs(tvb, 0);
if ( pinfo->destport == GVCP_PORT &&
(packet_type != 0x4200 && packet_type != 0x4201) )
return 0;
#if 0
if ( pinfo->srcport == GVCP_PORT && tvb_get_ntohs(tvb, 0) != 0x0 )
return 0;
#endif
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GVCP");
col_clear(pinfo->cinfo,COL_INFO);
packet_opcode = tvb_get_ntohs(tvb, 2);
packet_plsize = tvb_get_ntohs(tvb, 4);
info = ep_strbuf_new(val_to_str(packet_opcode, opcode_names, "Unknown opcode (0x%04x)"));
if (tvb_reported_length(tvb) < 8+(guint32)packet_plsize) {
ep_strbuf_append_printf(info, " (truncated? %u bytes missing)",
(8 + packet_plsize) - tvb_reported_length(tvb));
col_add_str(pinfo->cinfo, COL_INFO, info->str);
return tvb_length(tvb);
}
if (tvb_reported_length(tvb) > 8+(guint32)packet_plsize) {
ep_strbuf_append_printf(info, " (%u excess bytes)",
tvb_reported_length(tvb) - (8 + packet_plsize));
col_add_str(pinfo->cinfo, COL_INFO, info->str);
return tvb_length(tvb);
}
if (packet_plsize & 3) {
ep_strbuf_append(info, " (payload is not multiple of 4 bytes)");
col_add_str(pinfo->cinfo, COL_INFO, info->str);
return tvb_length(tvb);
}
switch (packet_opcode) {
case 0x04:
if (packet_plsize < 24) {
ep_strbuf_append(info, " <missing args>");
} else {
ep_strbuf_append_printf(info, "%d.%d.%d.%d to %s",
tvb_get_guint8(tvb, 28), tvb_get_guint8(tvb, 29),
tvb_get_guint8(tvb, 30), tvb_get_guint8(tvb, 31),
tvb_bytes_to_str_punct(tvb, 10, 6, ':'));
}
break;
case 0x80:
case 0x81:
if (packet_plsize == 0) {
ep_strbuf_append(info, " <missing arg(s)>");
} else {
ep_strbuf_append_printf(info, " 0x%08x", tvb_get_ntohl(tvb, 8));
if (packet_plsize >= 8) {
ep_strbuf_append_printf(info, ", 0x%08x", tvb_get_ntohl(tvb, 12));
if (packet_plsize >= 12)
ep_strbuf_append(info, ", ...");
}
}
break;
case 0x82:
if (packet_plsize < 8) {
ep_strbuf_append(info, " <missing arg(s)>");
} else {
ep_strbuf_append_printf(info, " *0x%08x = 0x%08x", tvb_get_ntohl(tvb, 8),
tvb_get_ntohl(tvb, 12));
if (packet_plsize >= 16) {
ep_strbuf_append_printf(info, ", *0x%08x = 0x%08x",
tvb_get_ntohl(tvb, 16), tvb_get_ntohl(tvb, 20));
if (packet_plsize >= 24)
ep_strbuf_append(info, ", ...");
}
}
break;
case 0x83:
if (packet_plsize < 4) {
ep_strbuf_append(info, " <missing arg>");
} else {
ep_strbuf_append_printf(info, " %d register%s written",
tvb_get_ntohl(tvb, 8),
tvb_get_ntohl(tvb, 8)==1?"":"s");
}
break;
case 0x84:
if (packet_plsize < 8) {
ep_strbuf_append(info, " <missing args>");
} else {
ep_strbuf_append_printf(info, " 0x%08x (%d bytes, X=0x%04x)",
tvb_get_ntohl(tvb, 8), tvb_get_ntohs(tvb, 14),
tvb_get_ntohs(tvb, 12));
if (packet_plsize > 8) {
ep_strbuf_append(info, "; excess payload");
}
}
break;
case 0x85:
if (packet_plsize < 8) {
ep_strbuf_append(info, " <missing args>");
} else {
ep_strbuf_append_printf(info, " %d bytes from 0x%08x", packet_plsize - 4,
tvb_get_ntohl(tvb, 8));
}
break;
case 0x86:
if (packet_plsize < 8) {
ep_strbuf_append(info, " <missing args>");
} else {
ep_strbuf_append_printf(info, " *0x%08x = <%d bytes>",
tvb_get_ntohl(tvb, 8), packet_plsize - 4);
}
break;
case 0x87:
if (packet_plsize < 4) {
ep_strbuf_append(info, " <missing arg>");
} else {
ep_strbuf_append_printf(info, " %d bytes written", tvb_get_ntohl(tvb, 8));
}
break;
}
col_add_str(pinfo->cinfo, COL_INFO, info->str);
if (tree) {
proto_item *ti = NULL;
proto_tree *gvcp_tree = NULL;
ti = proto_tree_add_item(tree, proto_gvcp, tvb, 0, -1, ENC_NA);
gvcp_tree = proto_item_add_subtree(ti, ett_gvcp);
proto_tree_add_item(gvcp_tree, hf_gvcp_type, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_opcode, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_payloadsize, tvb, 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_sequenceno, tvb, 6, 2, ENC_BIG_ENDIAN);
switch (packet_opcode) {
case 0x04:
if (packet_plsize >= 48) {
proto_tree_add_item(gvcp_tree, hf_gvcp_ether, tvb, 10, 6, ENC_NA);
proto_tree_add_item(gvcp_tree, hf_gvcp_ip, tvb, 28, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_netmask, tvb, 44, 4, ENC_BIG_ENDIAN);
}
break;
case 0x80:
if (packet_plsize >= 4) {
proto_tree_add_item(gvcp_tree, hf_gvcp_address, tvb, 8, 4, ENC_BIG_ENDIAN);
if (packet_plsize >= 8) {
proto_tree_add_item(gvcp_tree, hf_gvcp_address2, tvb, 12, 4, ENC_BIG_ENDIAN);
if (packet_plsize >= 12)
proto_tree_add_item(gvcp_tree, hf_gvcp_remainder, tvb, 16, -1, ENC_NA);
}
}
break;
case 0x81:
if (packet_plsize >= 4) {
proto_tree_add_item(gvcp_tree, hf_gvcp_value, tvb, 8, 4, ENC_BIG_ENDIAN);
if (packet_plsize >= 8) {
proto_tree_add_item(gvcp_tree, hf_gvcp_value2, tvb, 12, 4, ENC_BIG_ENDIAN);
if (packet_plsize >= 12)
proto_tree_add_item(gvcp_tree, hf_gvcp_remainder, tvb, 16, -1, ENC_NA);
}
}
break;
case 0x82:
if (packet_plsize >= 8) {
proto_tree_add_item(gvcp_tree, hf_gvcp_address, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_value, tvb, 12, 4, ENC_BIG_ENDIAN);
if (packet_plsize >= 16) {
proto_tree_add_item(gvcp_tree, hf_gvcp_address2, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_value2, tvb, 20, 4, ENC_BIG_ENDIAN);
if (packet_plsize >= 24)
proto_tree_add_item(gvcp_tree, hf_gvcp_remainder, tvb, 24, -1, ENC_NA);
}
}
break;
case 0x83:
if (packet_plsize >= 4)
proto_tree_add_item(gvcp_tree, hf_gvcp_nwritten, tvb, 8, 4, ENC_BIG_ENDIAN);
break;
case 0x84:
if (packet_plsize >= 8) {
proto_tree_add_item(gvcp_tree, hf_gvcp_address, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_unknown16, tvb, 12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_nbytes, tvb, 14, 2, ENC_BIG_ENDIAN);
}
break;
case 0x85:
case 0x86:
if (packet_plsize >= 8) {
proto_tree_add_item(gvcp_tree, hf_gvcp_address, tvb, 8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(gvcp_tree, hf_gvcp_data, tvb, 12, -1, ENC_NA);
}
break;
case 0x87:
if (packet_plsize >= 4)
proto_tree_add_item(gvcp_tree, hf_gvcp_nbytes, tvb, 10, 2, ENC_BIG_ENDIAN);
break;
default:
if (packet_plsize > 0)
proto_tree_add_item(gvcp_tree, hf_gvcp_data, tvb, 8, -1, ENC_NA);
break;
}
}
return tvb_length(tvb);
}
void
proto_register_gvcp(void)
{
static hf_register_info hf[] = {
{ &hf_gvcp_type,
{ "GVCP Type", "gvcp.type",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_opcode,
{ "GVCP Opcode", "gvcp.opcode",
FT_UINT16, BASE_HEX,
VALS(opcode_names), 0x0,
NULL, HFILL }
},
{ &hf_gvcp_payloadsize,
{ "GVCP Payload bytes", "gvcp.size",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_sequenceno,
{ "GVCP Sequence number", "gvcp.seqn",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_address,
{ "Address", "gvcp.address",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_value,
{ "Value", "gvcp.value",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_address2,
{ "Address 2", "gvcp.address2",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_value2,
{ "Value 2", "gvcp.value2",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_remainder,
{ "Remaining arguments", "gvcp.remainder",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_nwritten,
{ "Number of registers written", "gvcp.nwritten",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_nbytes,
{ "Number of bytes", "gvcp.nbytes",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_unknown16,
{ "2-byte unknown meaning", "gvcp.unknown16",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_data,
{ "Data", "gvcp.data",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_ether,
{ "Link layer address (ethernet)", "gvcp.ether",
FT_ETHER, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_ip,
{ "IPv4 address", "gvcp.ip",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_gvcp_netmask,
{ "Netmask", "gvcp.netmask",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_gvcp
};
proto_gvcp = proto_register_protocol ("GigE Vision Control Protocol",
"GVCP",
"gvcp" );
proto_register_field_array(proto_gvcp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_gvcp(void)
{
dissector_handle_t gvcp_handle;
gvcp_handle = new_create_dissector_handle(dissect_gvcp, proto_gvcp);
dissector_add_uint("udp.port", GVCP_PORT, gvcp_handle);
}
