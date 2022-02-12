static void dissect_icp_payload(tvbuff_t *tvb, int offset,
proto_tree *pload_tree, guint8 opcode)
{
gint stringlength;
guint16 objectlength;
switch(opcode)
{
case CODE_ICP_OP_QUERY:
proto_tree_add_text(pload_tree, tvb,offset,4,
"Requester Host Address %s",
tvb_ip_to_str(tvb, offset));
offset += 4;
stringlength = tvb_strsize(tvb, offset);
proto_tree_add_text(pload_tree, tvb, offset, stringlength,
"URL: %s", tvb_get_ephemeral_string(tvb, offset, stringlength));
break;
case CODE_ICP_OP_SECHO:
case CODE_ICP_OP_DECHO:
case CODE_ICP_OP_HIT:
case CODE_ICP_OP_MISS:
case CODE_ICP_OP_ERR:
case CODE_ICP_OP_MISS_NOFETCH:
case CODE_ICP_OP_DENIED:
stringlength = tvb_strsize(tvb, offset);
proto_tree_add_text(pload_tree, tvb, offset, stringlength,
"URL: %s", tvb_get_ephemeral_string(tvb, offset, stringlength));
break;
case CODE_ICP_OP_HIT_OBJ:
stringlength = tvb_strsize(tvb, offset);
proto_tree_add_text(pload_tree, tvb, offset, stringlength,
"URL: %s", tvb_get_ephemeral_string(tvb, offset, stringlength));
offset += stringlength;
objectlength=tvb_get_ntohs(tvb, offset);
proto_tree_add_text(pload_tree, tvb,offset,2,"Object length: %u", objectlength);
offset += 2;
proto_tree_add_text(pload_tree, tvb,offset,objectlength,"Object data");
if (objectlength > tvb_reported_length_remaining(tvb, offset))
{
proto_tree_add_text(pload_tree, tvb,offset,0,
"Packet is fragmented, rest of object is in next udp packet");
}
break;
default:
break;
}
}
static void dissect_icp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *icp_tree , *payload_tree;
proto_item *ti , *payloadtf;
guint8 opcode;
guint16 message_length;
guint32 request_number;
guint32 options;
guint32 option_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ICP");
col_clear(pinfo->cinfo, COL_INFO);
opcode=tvb_get_guint8(tvb, 0);
message_length=tvb_get_ntohs(tvb, 2);
request_number=tvb_get_ntohl(tvb, 4);
if (check_col(pinfo->cinfo, COL_INFO))
{
col_add_fstr(pinfo->cinfo,COL_INFO,"Opcode: %s (%u), Req Nr: %u",
val_to_str(opcode, opcode_vals, "Unknown"), opcode,
request_number);
}
if (tree)
{
ti = proto_tree_add_item(tree,proto_icp, tvb, 0, message_length, ENC_NA);
icp_tree = proto_item_add_subtree(ti, ett_icp);
proto_tree_add_uint(icp_tree,hf_icp_opcode, tvb, 0, 1, opcode);
proto_tree_add_item(icp_tree,hf_icp_version, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(icp_tree,hf_icp_length, tvb, 2, 2, message_length);
proto_tree_add_uint(icp_tree,hf_icp_request_nr, tvb, 4, 4,
request_number);
options=tvb_get_ntohl(tvb, 8);
if ( (opcode == CODE_ICP_OP_QUERY) && ((options & 0x80000000 ) != 0) )
{
proto_tree_add_text(icp_tree, tvb,8,4,
"option: ICP_FLAG_HIT_OBJ");
}
if ( (opcode == CODE_ICP_OP_QUERY)&& ((options & 0x40000000 ) != 0) )
{
proto_tree_add_text(icp_tree, tvb,8,4,
"option:ICP_FLAG_SRC_RTT");
}
if ((opcode != CODE_ICP_OP_QUERY)&& ((options & 0x40000000 ) != 0))
{
option_data=tvb_get_ntohl(tvb, 12);
proto_tree_add_text(icp_tree, tvb,8,8,
"option: ICP_FLAG_SCR_RTT RTT=%u",
option_data & 0x0000ffff);
}
proto_tree_add_text(icp_tree, tvb, 16, 4,
"Sender Host IP address %s",
tvb_ip_to_str(tvb, 16));
payloadtf = proto_tree_add_text(icp_tree, tvb,
20, message_length - 20,
"Payload");
payload_tree = proto_item_add_subtree(payloadtf, ett_icp_payload);
dissect_icp_payload(tvb, 20, payload_tree, opcode);
}
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
};
static gint *ett[] = {
&ett_icp,
&ett_icp_payload,
};
proto_icp = proto_register_protocol("Internet Cache Protocol",
"ICP", "icp");
proto_register_field_array(proto_icp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_icp(void)
{
dissector_handle_t icp_handle;
icp_handle = create_dissector_handle(dissect_icp, proto_icp);
dissector_add_uint("udp.port", UDP_PORT_ICP, icp_handle);
}
