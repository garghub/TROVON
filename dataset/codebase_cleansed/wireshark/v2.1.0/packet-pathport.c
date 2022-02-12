static guint dissect_one_tlv(tvbuff_t *tvb, proto_tree *tree,
guint offset)
{
proto_item *ti;
proto_tree *tlv_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_pp_tlv, &ti, "Property");
guint len;
guint pad_len;
guint type = tvb_get_ntohs(tvb, offset);
const char *name = val_to_str_ext(type, &pp_pid_vals_ext, TYPE_UNKNOWN);
proto_item_append_text(ti, " : %s", name);
proto_tree_add_item(tlv_tree, hf_pp_pid_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len = tvb_get_ntohs(tvb, offset);
proto_item_set_len(ti, 4 + len);
proto_tree_add_item(tlv_tree, hf_pp_pid_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tlv_tree, hf_pp_pid_value, tvb, offset, len, ENC_NA);
offset += len;
pad_len = ~(offset-1) & 3;
if(pad_len)
{
proto_tree_add_item(tlv_tree, hf_pp_pid_pad_bytes, tvb, offset, pad_len, ENC_NA);
offset += pad_len;
}
return offset;
}
static guint
dissect_multiple_tlvs(tvbuff_t *tvb, proto_item *ti,
guint offset, guint len)
{
guint end = offset + len;
while(offset < end) {
offset = dissect_one_tlv(tvb, ti, offset);
}
return offset;
}
static guint
dissect_multiple_get_pids(tvbuff_t *tvb, proto_item *tree, guint offset, guint len)
{
guint end = offset + len;
while(offset < end)
{
proto_tree_add_item(tree, hf_pp_get_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
return len;
}
static guint
dissect_data_payload(tvbuff_t *tvb, proto_item *tree, guint offset, guint len)
{
guint end = offset + len;
guint blklen = 0;
guint xdmx, stc;
while(offset < end)
{
proto_item *ti;
proto_tree *data_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_pp_data, &ti, "xDMX Data: ");
proto_tree_add_item(data_tree, hf_pp_data_encoding, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
blklen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(data_tree, hf_pp_data_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_pp_reserved, tvb, offset++, 1, ENC_NA);
stc = tvb_get_guint8(tvb, offset);
proto_tree_add_item(data_tree, hf_pp_data_start_code, tvb, offset++, 1, ENC_BIG_ENDIAN);
xdmx = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(data_tree, hf_pp_data_dst, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(data_tree, hf_pp_data_levels, tvb, offset, blklen, ENC_NA);
proto_item_append_text(ti, "%d Channels at xDMX %d (Univ %d.%d) StartCode: %d ", blklen, xdmx, xdmx / 512 + 1, xdmx % 512, stc);
offset += roof4(blklen);
}
return len;
}
static guint
dissect_arp_reply(tvbuff_t *tvb, proto_tree *tree, guint offset, guint len)
{
proto_tree_add_item(tree, hf_pp_arp_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pp_arp_ip, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(tree, hf_pp_arp_manuf, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_pp_arp_class, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_pp_arp_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_pp_arp_numdmx, tvb, offset++, 1, ENC_BIG_ENDIAN);
return len;
}
static guint
dissect_one_pdu(tvbuff_t *tvb, proto_tree *tree, guint offset)
{
proto_item *ti;
proto_tree *pdu_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_pp_pdu, &ti, "PDU");
guint len;
guint type = tvb_get_ntohs(tvb, offset);
const char *name = val_to_str(type, pp_pdu_vals, TYPE_UNKNOWN);
proto_item_append_text(ti, " : %s", name);
proto_tree_add_item(pdu_tree, hf_pp_pdu_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
len = tvb_get_ntohs(tvb, offset);
proto_item_set_len(ti, 4 + len);
proto_tree_add_item(pdu_tree, hf_pp_pdu_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch(type)
{
case PP_ARP_REPLY :
dissect_arp_reply(tvb, pdu_tree, offset, len);
break;
case PP_GET :
dissect_multiple_get_pids(tvb, pdu_tree, offset, len);
break;
case PP_SET :
case PP_GET_REPLY :
case PP_ARP_INFO :
dissect_multiple_tlvs(tvb, pdu_tree, offset, len);
break;
case PP_DATA :
dissect_data_payload(tvb, pdu_tree, offset, len);
break;
default:
proto_tree_add_item(pdu_tree, hf_pp_pdu_payload, tvb, offset, len, ENC_NA);
break;
}
offset += roof4(len);
return offset;
}
static guint
dissect_multiple_pdus(tvbuff_t *tvb, proto_item *ti,
guint offset, guint len)
{
guint end = offset + len;
while(offset < end) {
offset = dissect_one_pdu(tvb, ti, offset);
}
return offset;
}
static int
dissect_header(tvbuff_t *tvb, proto_tree *parent, guint offset)
{
proto_tree *tree = proto_tree_add_subtree(parent, tvb, offset, PATHPORT_HEADER_LENGTH, ett_pathport, NULL, "Header");
proto_tree_add_item(tree, hf_pp_prot, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_pp_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_pp_seq, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_pp_reserved, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(tree, hf_pp_src, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pp_dst, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gboolean
packet_is_pathport(tvbuff_t *tvb)
{
if(tvb_captured_length(tvb) < PATHPORT_MIN_LENGTH)
return FALSE;
if(tvb_get_ntohs(tvb, 0) != PATHPORT_PROTO_MAGIC)
return FALSE;
return TRUE;
}
static const char *
resolve_pp_id(guint32 id)
{
return val_to_str(id, ednet_id_vals, "%X");
}
static int dissect_pathport_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *pathport_tree;
guint offset = 0;
guint remaining_len;
guint len;
guint16 type;
guint32 srcid;
guint32 dstid;
len = tvb_reported_length(tvb);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Pathport");
col_clear(pinfo->cinfo, COL_INFO);
srcid = tvb_get_ntohl(tvb, PATHPORT_HEADER_SRCID_OFFSET);
type = tvb_get_ntohs(tvb, PATHPORT_HEADER_LENGTH);
if(type == PP_ARP_REQUEST)
{
dstid = tvb_get_ntohl(tvb, PATHPORT_HEADER_DSTID_OFFSET);
col_add_fstr(pinfo->cinfo, COL_INFO, "Who has %s? Tell %s",
resolve_pp_id(dstid), resolve_pp_id(srcid));
}
else
{
if((type == PP_ARP_REPLY) && (len >= 36))
{
guint32 id = tvb_get_ntohl(tvb, 24);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s is at %s", resolve_pp_id(id), tvb_ip_to_str(tvb, 28));
}
else if((type == PP_DATA) && (len >= 32))
{
guint16 xdmx_start = tvb_get_ntohs(tvb, 30);
col_add_fstr(pinfo->cinfo, COL_INFO, "xDMX Data - %d channels @ %d (Univ %d.%d)",
tvb_get_ntohs(tvb, 26),
xdmx_start, xdmx_start / 512 + 1, xdmx_start % 512);
}
else
{
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(type, pp_pdu_vals, TYPE_UNKNOWN));
}
}
if(tree == NULL)
return tvb_reported_length(tvb);
ti = proto_tree_add_item(tree, proto_pathport, tvb, 0, -1, ENC_NA);
pathport_tree = proto_item_add_subtree(ti, ett_pathport);
offset = dissect_header(tvb, pathport_tree, PATHPORT_HEADER_OFFSET);
remaining_len = tvb_reported_length_remaining(tvb, offset);
offset = dissect_multiple_pdus(tvb, tree, offset, remaining_len);
return offset;
}
static int
dissect_pathport(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
if(!packet_is_pathport(tvb))
return 0;
return dissect_pathport_common(tvb, pinfo, tree);
}
static gboolean
dissect_pathport_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if(!packet_is_pathport(tvb))
return FALSE;
dissect_pathport_common(tvb, pinfo, tree);
return (TRUE);
}
void
proto_register_pathport(void)
{
static hf_register_info hf[] = {
{&hf_pp_prot, {"Protocol", "pathport.prot", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_reserved, {"Reserved", "pathport.resv", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{&hf_pp_version, {"Version", "pathport.version", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_seq, {"Sequence", "pathport.seq", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_pp_src, {"Source ID", "pathport.src", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_dst, {"Destination ID", "pathport.dst", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_pdu_type, {"PDU", "pathport.pdu", FT_UINT16, BASE_HEX, VALS(pp_pdu_vals), 0x0, NULL, HFILL }},
{&hf_pp_pdu_len, {"Length", "pathport.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_pp_pdu_payload, {"Payload", "pathport.payload", FT_BYTES, 0, NULL, 0x0, NULL, HFILL }},
{&hf_pp_get_type, {"Get", "pathport.get.pid", FT_UINT16, BASE_HEX | BASE_EXT_STRING, &pp_pid_vals_ext, 0x0, NULL, HFILL }},
{&hf_pp_pid_type, {"Property", "pathport.pid", FT_UINT16, BASE_HEX | BASE_EXT_STRING, &pp_pid_vals_ext, 0x0, NULL, HFILL }},
{&hf_pp_pid_len, {"Length", "pathport.pid.len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_pp_pid_value, {"Value", "pathport.pid.value", FT_BYTES, 0, NULL, 0x0, NULL, HFILL }},
{&hf_pp_pid_pad_bytes, {"Pad bytes", "pathport.pid.pad_bytes", FT_BYTES, 0, NULL, 0x0, NULL, HFILL }},
{&hf_pp_data_encoding, {"Data Encoding", "pathport.data.encoding", FT_UINT16, BASE_HEX, VALS(pp_data_encoding_vals), 0x0, NULL, HFILL }},
{&hf_pp_data_start_code, {"DMX Start Code", "pathport.data.startcode", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_data_len, {"Data Length", "pathport.data.len", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_data_dst, {"xDMX Destination", "pathport.data.dst", FT_UINT16, BASE_HEX, NULL, 0x0,NULL, HFILL }},
{&hf_pp_data_levels, {"Levels", "pathport.data.levels", FT_NONE, 0, NULL, 0x0, NULL, HFILL }},
{&hf_pp_arp_id, {"ID", "pathport.arp.id", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_arp_manuf, {"Manufacturer", "pathport.arp.manuf", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_arp_class, {"Device Class", "pathport.arp.class", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_arp_type, {"Device Type", "pathport.arp.type", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_arp_numdmx, {"Subcomponents", "pathport.arp.numdmx", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{&hf_pp_arp_ip, {"IP", "pathport.arp.ip", FT_IPv4, 0, NULL, 0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_pathport,
&ett_pp_pdu,
&ett_pp_tlv,
&ett_pp_data
};
proto_pathport = proto_register_protocol("Pathport Protocol", "Pathport", "pathport");
proto_register_field_array(proto_pathport, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pathport(void)
{
static dissector_handle_t pathport_handle;
pathport_handle = create_dissector_handle(dissect_pathport, proto_pathport);
heur_dissector_add("udp", dissect_pathport_heur, "Pathport over UDP", "pathport_udp", proto_pathport, HEURISTIC_ENABLE);
dissector_add_uint("udp.port", PATHPORT_UDP_PORT, pathport_handle);
}
