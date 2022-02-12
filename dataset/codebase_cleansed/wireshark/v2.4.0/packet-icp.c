static void dissect_icp_payload(tvbuff_t *tvb, packet_info *pinfo, int offset,
proto_tree *pload_tree, guint8 opcode)
{
gint stringlength;
guint16 objectlength;
proto_item* object_item;
switch(opcode)
{
case CODE_ICP_OP_QUERY:
proto_tree_add_item(pload_tree, hf_icp_requester_host_address, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
stringlength = tvb_strsize(tvb, offset);
proto_tree_add_item(pload_tree, hf_icp_url, tvb, offset, stringlength, ENC_ASCII|ENC_NA);
break;
case CODE_ICP_OP_SECHO:
case CODE_ICP_OP_DECHO:
case CODE_ICP_OP_HIT:
case CODE_ICP_OP_MISS:
case CODE_ICP_OP_ERR:
case CODE_ICP_OP_MISS_NOFETCH:
case CODE_ICP_OP_DENIED:
stringlength = tvb_strsize(tvb, offset);
proto_tree_add_item(pload_tree, hf_icp_url, tvb, offset, stringlength, ENC_ASCII|ENC_NA);
break;
case CODE_ICP_OP_HIT_OBJ:
stringlength = tvb_strsize(tvb, offset);
proto_tree_add_item(pload_tree, hf_icp_url, tvb, offset, stringlength, ENC_ASCII|ENC_NA);
offset += stringlength;
objectlength=tvb_get_ntohs(tvb, offset);
proto_tree_add_item(pload_tree, hf_icp_object_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
object_item = proto_tree_add_item(pload_tree, hf_icp_object_data, tvb, offset, objectlength, ENC_NA);
if (objectlength > tvb_reported_length_remaining(tvb, offset))
{
expert_add_info(pinfo, object_item, &ei_icp_fragmented_packet);
}
break;
default:
break;
}
}
static int dissect_icp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_tree *icp_tree , *payload_tree;
proto_item *ti;
guint8 opcode;
guint16 message_length;
guint32 request_number;
guint32 options;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICP");
col_clear(pinfo->cinfo, COL_INFO);
opcode=tvb_get_guint8(tvb, 0);
message_length=tvb_get_ntohs(tvb, 2);
request_number=tvb_get_ntohl(tvb, 4);
col_add_fstr(pinfo->cinfo,COL_INFO,"Opcode: %s (%u), Req Nr: %u",
val_to_str_const(opcode, opcode_vals, "Unknown"), opcode,
request_number);
ti = proto_tree_add_item(tree,proto_icp, tvb, 0, message_length, ENC_NA);
icp_tree = proto_item_add_subtree(ti, ett_icp);
if (tree)
{
proto_tree_add_uint(icp_tree,hf_icp_opcode, tvb, 0, 1, opcode);
proto_tree_add_item(icp_tree,hf_icp_version, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(icp_tree,hf_icp_length, tvb, 2, 2, message_length);
proto_tree_add_uint(icp_tree,hf_icp_request_nr, tvb, 4, 4,
request_number);
options=tvb_get_ntohl(tvb, 8);
if ( (opcode == CODE_ICP_OP_QUERY) && ((options & 0x80000000 ) != 0) )
{
proto_tree_add_item(icp_tree, hf_icp_option_hit_obj, tvb, 8, 4, ENC_NA);
}
if ( (opcode == CODE_ICP_OP_QUERY)&& ((options & 0x40000000 ) != 0) )
{
proto_tree_add_item(icp_tree, hf_icp_option_src_rtt, tvb, 8, 4, ENC_NA);
}
if ((opcode != CODE_ICP_OP_QUERY)&& ((options & 0x40000000 ) != 0))
{
proto_tree_add_item(icp_tree, hf_icp_option_src_rtt, tvb, 8, 4, ENC_NA);
proto_tree_add_item(icp_tree, hf_icp_rtt, tvb, 12, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(icp_tree, hf_icp_sender_host_ip_address, tvb, 16, 4, ENC_BIG_ENDIAN);
}
payload_tree = proto_tree_add_subtree(icp_tree, tvb,
20, message_length - 20,
ett_icp_payload, NULL, "Payload");
dissect_icp_payload(tvb, pinfo, 20, payload_tree, opcode);
return tvb_captured_length(tvb);
}
void
proto_register_icp(void)
{
static hf_register_info hf[] = {
{ &hf_icp_opcode,
{ "Opcode", "icp.opcode", FT_UINT8, BASE_HEX, VALS(opcode_vals),
0x0, NULL, HFILL }},
{ &hf_icp_version,
{ "Version", "icp.version", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_icp_length,
{ "Length", "icp.length", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_icp_request_nr,
{ "Request Number", "icp.nr", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_icp_requester_host_address, { "Requester Host Address", "icp.requester_host_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icp_url, { "URL", "icp.url", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icp_object_length, { "Object length", "icp.object_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icp_object_data, { "Object data", "icp.object_data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icp_option_hit_obj, { "Option: ICP_FLAG_HIT_OBJ", "icp.option.hit_obj", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icp_option_src_rtt, { "Option: ICP_FLAG_SRC_RTT", "icp.option.src_rtt", FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_icp_rtt, { "RTT", "icp.rtt", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_icp_sender_host_ip_address, { "Sender Host IP address", "icp.sender_host_ip_address", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_icp,
&ett_icp_payload,
};
static ei_register_info ei[] = {
{ &ei_icp_fragmented_packet, { "icp.fragmented_packet", PI_PROTOCOL, PI_WARN, "Packet is fragmented", EXPFILL }},
};
expert_module_t* expert_icp;
proto_icp = proto_register_protocol("Internet Cache Protocol", "ICP", "icp");
proto_register_field_array(proto_icp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_icp = expert_register_protocol(proto_icp);
expert_register_field_array(expert_icp, ei, array_length(ei));
}
void
proto_reg_handoff_icp(void)
{
dissector_handle_t icp_handle;
icp_handle = create_dissector_handle(dissect_icp, proto_icp);
dissector_add_uint_with_preference("udp.port", UDP_PORT_ICP, icp_handle);
}
