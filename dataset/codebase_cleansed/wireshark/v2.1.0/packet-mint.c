static int
dissect_eth_frame(tvbuff_t *tvb, packet_info *pinfo, proto_tree *mint_tree,
volatile guint32 offset, guint32 length)
{
tvbuff_t *eth_tvb;
#ifdef MINT_DEVELOPMENT
col_set_writable(pinfo->cinfo, FALSE);
#endif
eth_tvb = tvb_new_subset_length(tvb, offset, length);
TRY {
call_dissector(eth_handle, eth_tvb, pinfo, mint_tree);
} CATCH_NONFATAL_ERRORS {
show_exception(eth_tvb, pinfo, mint_tree, EXCEPT_CODE, GET_MESSAGE);
} ENDTRY;
offset += length;
#ifdef MINT_DEVELOPMENT
col_set_writable(pinfo->cinfo, TRUE);
#endif
return offset;
}
static int
dissect_mint_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint32 offset, guint32 packet_length, guint received_via)
{
proto_item *ti;
proto_tree *mint_tree = NULL;
proto_tree *mint_header_tree = NULL;
proto_tree *mint_data_tree = NULL;
proto_tree *mint_ctrl_tree = NULL;
guint16 bytes_remaining;
guint16 packet_type;
guint8 type, length, header_length;
guint32 message_type;
guint8 element_length;
static header_field_info *display_hfi_tlv_vals;
packet_type = tvb_get_ntohs(tvb, offset + 12);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_SHORT_NAME);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(packet_type,
mint_packettype_vals, "Type 0x%02x"));
ti = proto_tree_add_item(tree, hfi_mint, tvb,
offset, packet_length, ENC_NA);
mint_tree = proto_item_add_subtree(ti, ett_mint);
ti = proto_tree_add_item(mint_tree, &hfi_mint_header, tvb,
offset, 16, ENC_NA);
mint_header_tree = proto_item_add_subtree(ti, ett_mint_header);
proto_tree_add_item(mint_header_tree, &hfi_mint_header_unknown1, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(mint_header_tree, &hfi_mint_header_dstid, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(mint_header_tree, &hfi_mint_header_srcid, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(mint_header_tree, &hfi_mint_header_dstdatatype, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mint_header_tree, &hfi_mint_header_srcdatatype, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch(packet_type) {
case MINT_TYPE_DATA_UC:
ti = proto_tree_add_item(mint_tree, &hfi_mint_data, tvb,
offset, packet_length - 16, ENC_NA);
mint_data_tree = proto_item_add_subtree(ti, ett_mint_data);
proto_tree_add_item(mint_data_tree, &hfi_mint_data_unknown1, tvb,
offset, 2, ENC_NA);
offset += 2;
if (offset < packet_length)
offset += dissect_eth_frame(tvb, pinfo, tree,
offset, packet_length - offset);
break;
case MINT_TYPE_DATA_BCMC:
ti = proto_tree_add_item(mint_tree, &hfi_mint_data, tvb,
offset, packet_length - 16, ENC_NA);
mint_data_tree = proto_item_add_subtree(ti, ett_mint_data);
proto_tree_add_item(mint_data_tree, &hfi_mint_data_vlan, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(mint_data_tree, &hfi_mint_data_seqno, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(mint_data_tree, &hfi_mint_data_unknown1, tvb,
offset, 4, ENC_NA);
offset += 4;
if (offset < packet_length)
offset += dissect_eth_frame(tvb, pinfo, tree,
offset, packet_length - offset);
break;
case MINT_TYPE_CTRL_0x0c:
ti = proto_tree_add_item(mint_tree, &hfi_mint_control, tvb,
offset, packet_length - 16, ENC_NA);
mint_ctrl_tree = proto_item_add_subtree(ti, ett_mint_ctrl);
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_32zerobytes, tvb,
offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_unknown1, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_unknown2, tvb,
offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_unknown3, tvb,
offset, 1, ENC_NA);
offset += 1;
header_length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_header_length, tvb,
offset, 1, ENC_NA);
offset += 1;
message_type = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_message_type, tvb,
offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_header_sender, tvb,
offset, 4, ENC_NA);
offset += 4;
switch (message_type) {
case 0x43534E50:
element_length = 12;
display_hfi_tlv_vals = &hfi_mint_control_0x0c_type_csnp;
break;
case 0x48454C4F:
element_length = 0;
display_hfi_tlv_vals = &hfi_mint_control_0x0c_type_helo;
break;
case 0x4C535000:
element_length = 8;
display_hfi_tlv_vals = &hfi_mint_control_0x0c_type_lsp;
break;
case 0x50534E50:
element_length = 4;
display_hfi_tlv_vals = &hfi_mint_control_0x0c_type_psnp;
break;
default:
element_length = 0;
display_hfi_tlv_vals = &hfi_mint_control_0x0c_type_unknown;
}
if (header_length > 12) {
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_header_unknown, tvb,
offset, header_length - 12, ENC_NA);
offset += header_length - 12;
}
while (offset < packet_length - 2) {
type = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mint_ctrl_tree, display_hfi_tlv_vals, tvb,
offset, 1, ENC_NA);
offset += 1;
length = tvb_get_guint8(tvb, offset);
if (type == 1 && length == 128) {
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_array, tvb,
offset, 1, ENC_NA);
offset += 1;
length = tvb_get_guint8(tvb, offset);
}
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_length, tvb,
offset, 1, ENC_NA);
offset += 1;
if (offset + length > packet_length) {
break;
}
if (type == 1 && element_length) {
guint32 end_offset = offset + length;
for (; offset < end_offset; offset += element_length) {
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_element, tvb,
offset, element_length, ENC_NA);
}
} else {
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x0c_value, tvb,
offset, length, ENC_NA);
offset += length;
}
}
break;
case MINT_TYPE_CTRL_0x1e:
ti = proto_tree_add_item(mint_tree, &hfi_mint_control, tvb,
offset, packet_length - 16, ENC_NA);
mint_ctrl_tree = proto_item_add_subtree(ti, ett_mint_ctrl);
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_32zerobytes, tvb,
offset, 32, ENC_NA);
offset += 32;
bytes_remaining = packet_length - offset;
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x1e_unknown, tvb,
offset, bytes_remaining, ENC_NA);
offset += bytes_remaining;
break;
case MINT_TYPE_ETH_0x22:
ti = proto_tree_add_item(mint_tree, &hfi_mint_control, tvb,
offset, packet_length - 16, ENC_NA);
mint_ctrl_tree = proto_item_add_subtree(ti, ett_mint_ctrl);
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_32zerobytes, tvb,
offset, 32, ENC_NA);
offset += 32;
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x22_message, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (offset < packet_length - 2) {
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x22_type, tvb,
offset, 1, ENC_NA);
offset += 1;
length = tvb_get_guint8(tvb, offset);
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x22_length, tvb,
offset, 1, ENC_NA);
offset += 1;
if (offset + length > packet_length) {
break;
}
proto_tree_add_item(mint_ctrl_tree, &hfi_mint_control_0x22_value, tvb,
offset, length, ENC_NA);
offset += length;
}
break;
default:
bytes_remaining = packet_length - offset;
switch(received_via) {
case PORT_MINT_CONTROL_TUNNEL:
case ETHERTYPE_MINT:
proto_tree_add_item(mint_tree, &hfi_mint_control_unknown1, tvb,
offset, bytes_remaining, ENC_NA);
break;
case PORT_MINT_DATA_TUNNEL:
proto_tree_add_item(mint_tree, &hfi_mint_data_unknown1, tvb,
offset, bytes_remaining, ENC_NA);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
offset += bytes_remaining;
break;
}
#if defined MINT_DEVELOPMENT
tree_expanded_set(ett_mint, TRUE);
tree_expanded_set(ett_mint_ethshim, TRUE);
tree_expanded_set(ett_mint_header, TRUE);
tree_expanded_set(ett_mint_ctrl, TRUE);
tree_expanded_set(ett_mint_data, TRUE);
#endif
return offset;
}
static int
dissect_mint_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 packet_length = tvb_captured_length(tvb);
return dissect_mint_common(tvb, pinfo, tree, 0, packet_length,
PORT_MINT_CONTROL_TUNNEL);
}
static int
dissect_mint_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 packet_length = tvb_captured_length(tvb);
return dissect_mint_common(tvb, pinfo, tree, 0, packet_length,
PORT_MINT_DATA_TUNNEL);
}
static int
dissect_mint_ethshim(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *mint_ethshim_tree = NULL;
guint32 offset = 0;
guint32 packet_length;
ti = proto_tree_add_item(tree, &hfi_mint_ethshim, tvb,
offset, 4, ENC_NA);
mint_ethshim_tree = proto_item_add_subtree(ti, ett_mint_ethshim);
proto_tree_add_item(mint_ethshim_tree, &hfi_mint_ethshim_unknown, tvb,
offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(mint_ethshim_tree, &hfi_mint_ethshim_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
packet_length = tvb_get_ntohs(tvb, offset) + 4;
offset += 2;
offset += dissect_mint_common(tvb, pinfo, tree, 4, packet_length, ETHERTYPE_MINT);
return offset;
}
static gboolean
test_mint_control(tvbuff_t *tvb _U_)
{
#if 0
if ( tvb_length(tvb) < 8
|| tvb_get_guint8(tvb, 0) != 3
) {
return FALSE;
}
#endif
return TRUE;
}
static gboolean
test_mint_data(tvbuff_t *tvb _U_)
{
#if 0
if ( tvb_length(tvb) < 8
|| tvb_get_guint8(tvb, 0) != 3
) {
return FALSE;
}
#endif
return TRUE;
}
static gboolean
test_mint_eth(tvbuff_t *tvb _U_)
{
#if 0
if ( tvb_length(tvb) < 8
|| tvb_get_guint8(tvb, 0) != 3
) {
return FALSE;
}
#endif
return TRUE;
}
static int
dissect_mint_control_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !test_mint_control(tvb) ) {
return 0;
}
return dissect_mint_control(tvb, pinfo, tree);
}
static int
dissect_mint_data_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !test_mint_data(tvb) ) {
return 0;
}
return dissect_mint_data(tvb, pinfo, tree);
}
static int
dissect_mint_ethshim_static(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !test_mint_eth(tvb) ) {
return 0;
}
return dissect_mint_ethshim(tvb, pinfo, tree);
}
void
proto_register_mint(void)
{
#ifndef HAVE_HFI_SECTION_INIT
static header_field_info *hfi[] = {
&hfi_mint_ethshim,
&hfi_mint_ethshim_unknown,
&hfi_mint_ethshim_length,
&hfi_mint_header,
&hfi_mint_header_unknown1,
&hfi_mint_header_srcid,
&hfi_mint_header_dstid,
&hfi_mint_header_srcdatatype,
&hfi_mint_header_dstdatatype,
&hfi_mint_data,
&hfi_mint_data_vlan,
&hfi_mint_data_seqno,
&hfi_mint_data_unknown1,
&hfi_mint_control,
&hfi_mint_control_32zerobytes,
&hfi_mint_control_unknown1,
&hfi_mint_control_0x0c_message_type,
&hfi_mint_control_0x0c_header_sender,
&hfi_mint_control_0x0c_unknown1,
&hfi_mint_control_0x0c_unknown2,
&hfi_mint_control_0x0c_unknown3,
&hfi_mint_control_0x0c_header_length,
&hfi_mint_control_0x0c_header_unknown,
&hfi_mint_control_0x0c_type_unknown,
&hfi_mint_control_0x0c_type_csnp,
&hfi_mint_control_0x0c_type_helo,
&hfi_mint_control_0x0c_type_lsp,
&hfi_mint_control_0x0c_type_psnp,
&hfi_mint_control_0x0c_length,
&hfi_mint_control_0x0c_array,
&hfi_mint_control_0x0c_element,
&hfi_mint_control_0x0c_value,
&hfi_mint_control_0x1e_unknown,
&hfi_mint_control_0x22_message,
&hfi_mint_control_0x22_type,
&hfi_mint_control_0x22_length,
&hfi_mint_control_0x22_value,
};
#endif
static gint *ett[] = {
&ett_mint_ethshim,
&ett_mint,
&ett_mint_header,
&ett_mint_ctrl,
&ett_mint_data,
};
int proto_mint, proto_mint_data;
proto_mint = proto_register_protocol(PROTO_LONG_NAME, PROTO_SHORT_NAME, "mint");
proto_mint_data = proto_register_protocol("Media independent Network Transport Data", "MiNT (Data)", "mint_data");
hfi_mint = proto_registrar_get_nth(proto_mint);
proto_register_fields(proto_mint, hfi, array_length(hfi));
proto_register_subtree_array(ett, array_length(ett));
mint_control_handle = create_dissector_handle(dissect_mint_control_static, proto_mint);
mint_data_handle = create_dissector_handle(dissect_mint_data_static, proto_mint_data);
mint_eth_handle = create_dissector_handle(dissect_mint_ethshim_static, proto_mint);
}
void
proto_reg_handoff_mint(void)
{
dissector_add_uint("udp.port", PORT_MINT_CONTROL_TUNNEL, mint_control_handle);
dissector_add_uint("udp.port", PORT_MINT_DATA_TUNNEL, mint_data_handle);
dissector_add_uint("ethertype", ETHERTYPE_MINT, mint_eth_handle);
eth_handle = find_dissector_add_dependency("eth_withoutfcs", hfi_mint->id);
}
