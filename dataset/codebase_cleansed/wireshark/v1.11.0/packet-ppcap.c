static void
dissect_ppcap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti, *ti1;
proto_tree *ppcap_tree, *ppcap_tree1;
guint16 msg_type, msg_len;
int offset = 0;
payload_type_type payload_type = PPCAP_UNKNOWN;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPCAP");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_ppcap, tvb, 0, -1, ENC_NA);
ppcap_tree = proto_item_add_subtree(ti, ett_ppcap);
while (tvb_length_remaining(tvb, offset) > 0)
{
msg_type = tvb_get_ntohs(tvb, offset);
ti1 = proto_tree_add_text(ppcap_tree, tvb, offset, 2, "%s",
val_to_str(msg_type, payload_tag_values, "Unknown PPCAP message type (%u)"));
ppcap_tree1 = proto_item_add_subtree(ti1, ett_ppcap1);
offset = offset + 2;
msg_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item( ppcap_tree1, hf_ppcap_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
switch (msg_type) {
case 1:
payload_type = PPCAP_UNKNOWN;
offset = dissect_ppcap_payload_type(tvb, ppcap_tree1, offset, msg_len, &payload_type);
break;
case 2:
offset = dissect_ppcap_payload_data(tvb, pinfo, ppcap_tree1, offset, msg_len, tree, payload_type);
break;
case 3:
offset = dissect_ppcap_source_address(tvb, pinfo, ppcap_tree1, offset, msg_len);
break;
case 4:
offset = dissect_ppcap_destination_address(tvb, pinfo, ppcap_tree1, offset, msg_len);
break;
case 256:
offset = dissect_ppcap_info_string(tvb, ppcap_tree1, offset, msg_len);
break;
}
}
}
static int
dissect_ppcap_payload_type(tvbuff_t *tvb, proto_tree * ppcap_tree1, int offset, guint16 msg_len, payload_type_type *payload_type)
{
char *string;
string = tvb_get_string(wmem_packet_scope(), tvb, offset, msg_len);
if (strcmp(string,"mtp3") == 0) {
*payload_type = PPCAP_MTP3;
}else if (strcmp(string,"tcap") == 0) {
*payload_type = PPCAP_TCAP;
}else if (strcmp(string,"bssap") == 0) {
*payload_type = PPCAP_BSSAP;
}else if (strcmp(string,"ranap") == 0) {
*payload_type = PPCAP_RANAP;
}else if (strcmp(string,"h248") == 0) {
*payload_type = PPCAP_H248;
}else if (strcmp(string,"sip") == 0) {
*payload_type = PPCAP_SIP;
}else if (strcmp(string,"sccp") == 0) {
*payload_type = PPCAP_SCCP;
}
proto_tree_add_item(ppcap_tree1, hf_ppcap_payload_type, tvb, offset, msg_len, ENC_BIG_ENDIAN|ENC_ASCII);
if (msg_len%4)
msg_len = msg_len+(4-(msg_len%4));
offset += msg_len;
return offset;
}
static int
dissect_ppcap_source_address(tvbuff_t *tvb, packet_info *pinfo, proto_tree * ppcap_tree1, int offset, guint16 msg_len)
{
int key1;
proto_tree_add_item(ppcap_tree1, hf_ppcap_reserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
key1 = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ppcap_tree1, hf_ppcap_address_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (key1 == 1)
{
proto_tree_add_item(ppcap_tree1, hf_ppcap_ssn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ppcap_tree1, hf_ppcap_spc, tvb, offset, 3, ENC_BIG_ENDIAN);
mtp3_addr_opc = wmem_new0(wmem_packet_scope(), mtp3_addr_pc_t);
mtp3_addr_opc->pc = (guint32 )tvb_get_ntoh24(tvb, offset);
mtp3_addr_opc->type = ITU_STANDARD;
mtp3_addr_opc->ni = 0;
SET_ADDRESS(&pinfo->src, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) mtp3_addr_opc);
if (msg_len%4)
msg_len = msg_len + (4 - (msg_len%4));
offset += msg_len-1;
return offset;
}
else if (key1 == 2)
{
proto_tree_add_item(ppcap_tree1, hf_ppcap_opc, tvb, offset, msg_len, ENC_BIG_ENDIAN);
mtp3_addr_opc = wmem_new0(wmem_packet_scope(), mtp3_addr_pc_t);
mtp3_addr_opc->pc = tvb_get_ntohl(tvb, offset);
mtp3_addr_opc->type = ITU_STANDARD;
mtp3_addr_opc->ni = 0;
SET_ADDRESS(&pinfo->src, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) mtp3_addr_opc);
}
else if (key1 == 3)
{
if (msg_len%4 == 0)
{
proto_tree_add_ipv4(ppcap_tree1, hf_ppcap_source_ip_address1, tvb, offset, msg_len, tvb_get_ipv4(tvb, offset));
TVB_SET_ADDRESS(&pinfo->net_src, AT_IPv4, tvb, offset, 4);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->net_src);
}
else
{
struct e_in6_addr value;
tvb_get_ipv6(tvb, offset, &value);
proto_tree_add_ipv6(ppcap_tree1, hf_ppcap_source_ip_address2, tvb, offset, msg_len, (guint8*)&value);
TVB_SET_ADDRESS(&pinfo->net_src, AT_IPv6, tvb, offset, 6);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->net_src);
}
}
else if (key1 == 4)
{
proto_tree_add_item(ppcap_tree1, hf_ppcap_source_nodeid, tvb, offset, msg_len, ENC_BIG_ENDIAN|ENC_ASCII);
TVB_SET_ADDRESS(&pinfo->net_src, AT_STRINGZ, tvb, offset, msg_len);
COPY_ADDRESS_SHALLOW(&pinfo->src, &pinfo->net_src);
}
if (msg_len%4)
msg_len = msg_len + (4 - (msg_len%4));
offset += msg_len;
return offset;
}
static int
dissect_ppcap_destination_address(tvbuff_t *tvb, packet_info * pinfo, proto_tree * ppcap_tree1, int offset, guint16 msg_len )
{
int key2;
proto_tree_add_item(ppcap_tree1, hf_ppcap_destreserved, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
key2 = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(ppcap_tree1, hf_ppcap_address_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (key2 == 1)
{
ssn = tvb_get_guint8(tvb, offset);
proto_tree_add_item(ppcap_tree1, hf_ppcap_ssn1, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ppcap_tree1, hf_ppcap_spc1, tvb, offset, 3, ENC_BIG_ENDIAN);
mtp3_addr_dpc = wmem_new0(wmem_packet_scope(), mtp3_addr_pc_t);
mtp3_addr_dpc->pc = (guint32)tvb_get_ntoh24(tvb, offset);
mtp3_addr_dpc->type = ITU_STANDARD;
mtp3_addr_dpc->ni = 0;
SET_ADDRESS(&pinfo->dst, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) mtp3_addr_dpc);
if (msg_len%4)
msg_len = msg_len + (4 - (msg_len%4));
offset += msg_len-1;
return offset;
}
else if (key2 == 2)
{
proto_tree_add_item(ppcap_tree1, hf_ppcap_dpc, tvb, offset, 4, ENC_BIG_ENDIAN);
mtp3_addr_dpc = wmem_new0(wmem_packet_scope(), mtp3_addr_pc_t);
mtp3_addr_dpc->pc = tvb_get_ntohl(tvb, offset);
mtp3_addr_dpc->type = ITU_STANDARD;
mtp3_addr_dpc->ni = 0;
SET_ADDRESS(&pinfo->dst, AT_SS7PC, sizeof(mtp3_addr_pc_t), (guint8 *) mtp3_addr_dpc);
}
else if (key2 == 3)
{
if (msg_len%4 == 0)
{
proto_tree_add_ipv4(ppcap_tree1, hf_ppcap_destination_ip_address1, tvb, offset, msg_len, tvb_get_ipv4(tvb, offset));
TVB_SET_ADDRESS(&pinfo->net_dst, AT_IPv4, tvb, offset, 4);
COPY_ADDRESS_SHALLOW(&pinfo->dst, &pinfo->net_dst);
}
else
{
struct e_in6_addr value;
tvb_get_ipv6(tvb, offset,&value);
proto_tree_add_ipv6(ppcap_tree1, hf_ppcap_destination_ip_address2, tvb, offset, msg_len, (guint8*)&value);
TVB_SET_ADDRESS(&pinfo->net_dst, AT_IPv6, tvb, offset, 6);
COPY_ADDRESS_SHALLOW(&pinfo->dst, &pinfo->net_dst);
}
}
else if (key2 == 4)
{
char *string;
string = tvb_get_string(wmem_packet_scope(), tvb, offset, msg_len);
proto_tree_add_string(ppcap_tree1, hf_ppcap_destination_nodeid, tvb, offset, msg_len, string);
TVB_SET_ADDRESS(&pinfo->net_dst, AT_STRINGZ, tvb, offset, msg_len);
COPY_ADDRESS_SHALLOW(&pinfo->dst, &pinfo->net_dst);
}
if (msg_len%4)
msg_len = msg_len+(4-(msg_len%4));
offset += msg_len;
return offset;
}
static int
dissect_ppcap_info_string(tvbuff_t *tvb, proto_tree * ppcap_tree1, int offset, guint16 msg_len)
{
proto_tree_add_item(ppcap_tree1, hf_ppcap_info, tvb, offset, msg_len, ENC_ASCII|ENC_NA);
if (msg_len%4)
msg_len = msg_len +( 4- (msg_len%4));
offset += msg_len;
return offset;
}
static int
dissect_ppcap_payload_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree * ppcap_tree1, int offset, guint16 msg_len, proto_tree *tree, payload_type_type payload_type)
{
tvbuff_t *next_tvb;
proto_tree_add_item(ppcap_tree1, hf_ppcap_payload_data, tvb, offset, msg_len, ENC_NA);
if (msg_len%4)
msg_len = msg_len +( 4- (msg_len%4));
next_tvb = tvb_new_subset_remaining(tvb, offset);
switch (payload_type) {
case PPCAP_MTP3:
call_dissector(mtp3_handle, next_tvb, pinfo, tree);
break;
case PPCAP_TCAP:
if (ssn != INVALID_SSN && dissector_try_uint(sccp_ssn_dissector_table, ssn, next_tvb, pinfo, tree)) {
return offset+msg_len;
}else{
call_dissector(tcap_handle, next_tvb, pinfo, tree);
}
break;
case PPCAP_BSSAP:
call_dissector(bssap_handle, next_tvb, pinfo, tree);
break;
case PPCAP_RANAP:
call_dissector(ranap_handle, next_tvb, pinfo, tree);
break;
case PPCAP_H248:
call_dissector(h248_handle, next_tvb, pinfo, tree);
break;
case PPCAP_SIP:
call_dissector(sip_handle, next_tvb, pinfo, tree);
break;
case PPCAP_SCCP:
call_dissector(sccp_handle, next_tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
offset += msg_len;
return offset;
}
void proto_register_ppcap(void)
{
static hf_register_info hf[] = {
{ &hf_ppcap_length,
{ "Length", "ppcap.length",
FT_UINT16, BASE_DEC, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_payload_type,
{ "Payload Type" , "ppcap.payload_type", FT_STRING,
BASE_NONE, NULL, 0x0 , NULL, HFILL}},
{ &hf_ppcap_reserved,
{ "Reserved", "ppcap.reserved", FT_UINT16,
BASE_DEC, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_address_type,
{ "Address Type", "ppcap.address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00 , NULL, HFILL}},
#if 0
{ &hf_ppcap_source_address_type,
{ "Source Address Type", "ppcap.source_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00 , NULL, HFILL}},
#endif
{ &hf_ppcap_ssn,
{ "SSN", "ppcap.ssn", FT_UINT16,
BASE_DEC, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_spc,
{"OPC", "ppcap.spc", FT_UINT16,
BASE_DEC, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_opc,
{ "OPC", "ppcap.opc", FT_UINT16,
BASE_DEC, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_source_ip_address1,
{ "Source IP Addresss", "ppcap.source_ip_address1", FT_IPv4,
BASE_NONE, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_source_ip_address2,
{ "Source IP Address", "ppcap.source_ip_address2", FT_IPv6,
BASE_NONE, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_destreserved,
{ "Reserved", "ppcap.destreserved", FT_UINT16,
BASE_DEC, NULL, 0x00, NULL, HFILL}},
#if 0
{ &hf_ppcap_destination_address_type,
{ "Destination Address Type", "ppcap.destination_address_type", FT_UINT16,
BASE_DEC, VALS(address_type_values), 0x00, NULL, HFILL}},
#endif
{ &hf_ppcap_ssn1,
{ "SSN", "ppcap.ssn1", FT_UINT8,
BASE_DEC, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_spc1,
{ "DPC", "ppcap.spc1", FT_UINT24,
BASE_DEC, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_dpc,
{ "DPC", "ppcap.dpc", FT_UINT32,
BASE_DEC, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_destination_ip_address1,
{ "Destination IP Address", "ppcap.destination_ip_address1", FT_IPv4,
BASE_NONE, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_destination_ip_address2,
{ "Destination IP Address", "ppcap.destination_ip_address2", FT_IPv6,
BASE_NONE, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_source_nodeid,
{ "Source Node ID", "ppcap.source_nodeid", FT_STRING,
BASE_NONE, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_destination_nodeid,
{ "Destination Node ID", "ppcap.destination_address_value", FT_STRING,
BASE_NONE, NULL, 0x00, NULL, HFILL}},
{ &hf_ppcap_info,
{ "Info", "ppcap.info", FT_STRING,
BASE_NONE, NULL, 0x0000, NULL, HFILL}},
{ &hf_ppcap_payload_data,
{ "Payload Data", "ppcap.payload_data", FT_BYTES,
BASE_NONE, NULL, 0x0000, NULL, HFILL}},
};
static gint *ett[]= {
&ett_ppcap,
&ett_ppcap1,
&ett_ppcap_new,
};
proto_ppcap = proto_register_protocol("Proprietary PCAP", "PPCAP", "ppcap");
proto_register_field_array(proto_ppcap , hf , array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("ppcap", dissect_ppcap, proto_ppcap);
}
void proto_reg_handoff_ppcap(void)
{
ppcap_handle = find_dissector("ppcap");
mtp3_handle = find_dissector("mtp3");
tcap_handle = find_dissector("tcap");
bssap_handle = find_dissector("bssap");
ranap_handle = find_dissector("ranap");
h248_handle = find_dissector("h248");
sip_handle = find_dissector("sip");
sccp_handle = find_dissector("sccp");
data_handle = find_dissector("data");
sccp_ssn_dissector_table = find_dissector_table("sccp.ssn");
}
