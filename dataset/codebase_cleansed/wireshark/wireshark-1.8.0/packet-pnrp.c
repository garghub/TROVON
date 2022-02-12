static int dissect_pnrp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint offset;
gint padding_bytes;
guint8 message_type;
guint16 field_type;
guint16 data_length;
data_length = tvb_reported_length(tvb);
if (data_length < 12+8 )
{
return 0;
}
if (tvb_get_ntohs(tvb,0) != PNRP_HEADER )
{
return 0;
}
if (tvb_get_ntohs(tvb,2) != 0x000C) {
return 0;
}
if (tvb_get_guint8(tvb,4) != 0x51) {
return 0;
}
offset= 0;
padding_bytes = 0;
message_type = tvb_get_guint8(tvb,7);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "pnrp");
col_add_fstr(pinfo->cinfo, COL_INFO, "PNRP %s Message ",
val_to_str(message_type, messageType, "Unknown (0x%02x)"));
if(tree){
proto_item *ti;
proto_tree *pnrp_tree;
proto_item *pnrp_header_item;
proto_tree *pnrp_header_tree;
proto_item *pnrp_message_tree = NULL;
proto_item *pnrp_message_item = NULL;
ti = proto_tree_add_item(tree, proto_pnrp, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, ", Message Type %s",
val_to_str(message_type, messageType, "Unknown (0x%02x)"));
pnrp_tree = proto_item_add_subtree(ti, ett_pnrp);
pnrp_header_item = proto_tree_add_item(pnrp_tree, hf_pnrp_header, tvb, offset,12,ENC_NA);
pnrp_header_tree = proto_item_add_subtree(pnrp_header_item, ett_pnrp_header);
proto_tree_add_item(pnrp_header_tree,hf_pnrp_header_fieldID,tvb,offset,2,ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pnrp_header_tree,hf_pnrp_header_length,tvb,offset,2,ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pnrp_header_tree,hf_pnrp_header_ident,tvb,offset,1,ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pnrp_header_tree,hf_pnrp_header_versionMajor,tvb,offset,1,ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pnrp_header_tree,hf_pnrp_header_versionMinor,tvb,offset,1,ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pnrp_header_tree,hf_pnrp_header_messageType,tvb,offset,1,ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pnrp_header_tree,hf_pnrp_header_messageID,tvb,offset,4,ENC_BIG_ENDIAN);
offset += 4;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
field_type = tvb_get_ntohs(tvb,offset );
data_length = tvb_get_ntohs(tvb,offset + 2);
if (data_length < 4) {
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset, 4, "Message with invalid length %u (< 4)", data_length);
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
}
offset += 4;
break;
}
switch (field_type) {
case PNRP_HEADER_ACKED:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Message ACK ID: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_headerack, tvb, offset + 4, data_length -4, ENC_BIG_ENDIAN);
}
offset += data_length;
break;
case VALIDATE_PNRP_ID:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Validate PNRP ID: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
dissect_pnrp_ids(tvb,offset+4,data_length-4,pnrp_message_tree);
}
offset += data_length;
break;
case FLAGS_FIELD:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Flags Field: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
switch (message_type) {
case INQUIRE:
proto_tree_add_bitmask(pnrp_message_tree, tvb, offset+4, hf_pnrp_message_inquire_flags, ett_pnrp_message_inquire_flags, inquire_flags, ENC_BIG_ENDIAN);
proto_tree_add_text(pnrp_message_tree, tvb, offset + 6, 2, "Padding : %d - 2 Bytes",tvb_get_ntohs(tvb,offset+6));
offset += data_length+2;
break;
case ACK:
proto_tree_add_bits_item(pnrp_message_tree, hf_pnrp_message_ack_flags_reserved, tvb, (offset + 4)*8, 15, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(pnrp_message_tree, hf_pnrp_message_ack_flags_Nbit, tvb,((offset + 4)*8)+15, 1, ENC_BIG_ENDIAN);
offset += data_length;
break;
case AUTHORITY:
proto_tree_add_bitmask(pnrp_message_tree, tvb, offset+4, hf_pnrp_message_authority_flags, ett_pnrp_message_authority_flags, authority_flags, ENC_BIG_ENDIAN);
if(tvb_reported_length_remaining(tvb, offset+data_length)==0)
{
offset += data_length;
}
else {
padding_bytes = 2;
proto_tree_add_text(pnrp_message_tree, tvb, offset + 6, padding_bytes, "Padding: %d bytes", padding_bytes);
offset += data_length+2;
}
break;
default:
proto_tree_add_text(pnrp_message_tree, tvb, offset + 4, data_length -4, "Flags");
offset += data_length;
break;
}
}
break;
case FLOOD_CONTROLS:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Flood Control: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(pnrp_message_tree, hf_pnrp_message_flood_flags_reserved1, tvb, (offset + 4)*8, 15, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(pnrp_message_tree, hf_pnrp_message_flood_flags_Dbit, tvb,((offset + 4)*8)+15, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(pnrp_message_tree, tvb, offset + 6, 1, "Reserved 2: %d",tvb_get_guint8(tvb,offset+6));
proto_tree_add_text(pnrp_message_tree, tvb, offset + 7, 1, "Padding: %d",tvb_get_guint8(tvb,offset+7));
}
offset += data_length+1;
break;
case SOLICIT_CONTROLS:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Solicit Controls: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(pnrp_message_tree, tvb, offset + 4, 1, "Reserved : %d",tvb_get_guint8(tvb,offset+4));
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_solicitType, tvb, offset + 5, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(pnrp_message_tree, tvb, offset + 6, 2, "Reserved : %d",tvb_get_ntohs(tvb,offset+6));
}
offset += data_length +2;
break;
case LOOKUP_CONTROLS:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Lookup Control: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(pnrp_message_tree, tvb, offset+4, hf_pnrp_message_lookupControls_flags, ett_pnrp_message_lookupControls_flags, lookupControls_flags, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_lookupControls_precision, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_lookupControls_resolveCriteria, tvb, offset + 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_lookupControls_reasonCode, tvb, offset + 9, 1, ENC_BIG_ENDIAN);
proto_tree_add_text(pnrp_message_tree, tvb, offset + 10, 2, "Reserved : %d",tvb_get_ntohs(tvb,offset+10));
}
offset += data_length;
break;
case TARGET_PNRP_ID:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Target PNRP ID: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
dissect_pnrp_ids(tvb, offset+4, data_length-4, pnrp_message_tree);
}
offset += data_length;
break;
case EXTENDED_PAYLOAD:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Extended Payload: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
}
offset += data_length;
break;
case PNRP_ID_ARRAY:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "PNRP ID Array: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_idArray_NumEntries, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_idArray_Length, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_ElementFieldType, tvb, offset + 8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_idarray_Entrylength, tvb, offset + 10, 2, ENC_BIG_ENDIAN);
dissect_pnrp_ids(tvb,offset+12,data_length-12,pnrp_message_tree);
}
offset += data_length;
break;
case CERT_CHAIN:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "CERT Chain: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_certChain, tvb, offset + 4, data_length-4, ENC_NA);
}
padding_bytes = 0;
while (data_length%4 != 0 &&tvb_reported_length_remaining(tvb, offset+data_length)>0) {
data_length++;
padding_bytes++;
}
if (0<padding_bytes) {
proto_tree_add_text(pnrp_message_tree, tvb, offset + data_length-padding_bytes, padding_bytes, "Padding: %d bytes", padding_bytes);
}
offset += data_length;
break;
case CLASSIFIER:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Classifier: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_classifier_unicodeCount, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_classifier_arrayLength, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset+8 , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_classifier_entryLength, tvb, offset + 10, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(pnrp_message_tree, tvb, offset + 12, tvb_get_ntohs(tvb,offset+6)-8, "Classifier: %s",tvb_get_ephemeral_unicode_string(tvb, offset + 12, tvb_get_ntohs(tvb,offset+6)-8, ENC_BIG_ENDIAN));
}
padding_bytes = 0;
while (data_length%4 != 0 &&tvb_reported_length_remaining(tvb, offset+data_length)>0) {
data_length++;
padding_bytes++;
}
if (0<padding_bytes) {
proto_tree_add_text(pnrp_message_tree, tvb, offset + data_length-padding_bytes, padding_bytes, "Padding: %d bytes", padding_bytes);
}
offset += data_length;
break;
case HASHED_NONCE:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Hashed Nonce: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_hashednonce, tvb, offset + 4, data_length-4, ENC_NA);
}
offset += data_length;
break;
case NONCE:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Nonce: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_nonce, tvb, offset + 4, data_length-4, ENC_NA);
}
offset += data_length;
break;
case SPLIT_CONTROLS:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Split controls: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_splitControls_authorityBuffer, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_text(pnrp_message_tree, tvb, offset + 6, 2, "Offset : %d",tvb_get_ntohs(tvb,offset+6));
}
offset += data_length+tvb_get_ntohs(tvb,offset+6);
break;
case ROUTING_ENTRY:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Routing Entry: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
dissect_route_entry(tvb,offset+4, tvb_get_ntohs(tvb,offset+2)-4, pnrp_message_tree);
}
padding_bytes = 0;
while (data_length%4 != 0 &&tvb_reported_length_remaining(tvb, offset+data_length)>0) {
data_length++;
padding_bytes++;
}
if (0<padding_bytes) {
proto_tree_add_text(pnrp_message_tree, tvb, offset + data_length-padding_bytes, padding_bytes, "Padding: %d bytes", padding_bytes);
}
offset += data_length;
break;
case VALIDATE_CPA:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Validate CPA: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
dissect_encodedCPA_structure(tvb, offset+4, data_length-4, pnrp_message_tree);
}
offset += data_length;
break;
case IPV6_ENDPOINT_ARRAY:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "IPv6 Endpoint Array: ");
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_ipv6EndpointArray_NumberOfEntries, tvb, offset + 4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_ipv6EndpointArray_ArrayLength, tvb, offset + 6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset+8 , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_ipv6EndpointArray_EntryLength, tvb, offset + 10, 2, ENC_BIG_ENDIAN);
dissect_ipv6_endpoint_structure(tvb, offset+12, tvb_get_ntohs(tvb,offset+6)-8,pnrp_message_tree);
}
offset += data_length;
break;
default:
if (tree) {
pnrp_message_item = proto_tree_add_text(pnrp_tree, tvb, offset,
data_length, "Type: %s, length: %u",
val_to_str(field_type, fieldID, "Unknown (0x%04x)"), data_length);
pnrp_message_tree = proto_item_add_subtree(pnrp_message_item, ett_pnrp_message);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_type, tvb, offset , 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_message_tree, hf_pnrp_message_length, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
if(data_length > 4)
{
proto_tree_add_text(pnrp_message_tree, tvb, offset + 4, data_length -4, "Data");
}
else {
return 0;
}
}
offset += data_length;
break;
}
}
}
return offset;
}
static void dissect_pnrp_ids(tvbuff_t *tvb, gint offset, gint length, proto_tree *tree)
{
while (32 <=length) {
proto_tree_add_item(tree, hf_pnrp_message_pnrpID, tvb, offset, 32, ENC_NA);
length -= 32;
offset += 32;
}
}
static void dissect_route_entry(tvbuff_t *tvb, gint offset, gint length, proto_tree *tree)
{
gint tmp_offset;
if (0 <= tvb_reported_length_remaining(tvb, offset+length)) {
tmp_offset = 0;
proto_tree_add_item(tree, hf_pnrp_message_pnrpID, tvb, offset+tmp_offset, 32, ENC_NA);
tmp_offset +=32;
proto_tree_add_item(tree,hf_pnrp_header_versionMajor,tvb,offset+tmp_offset,1,ENC_BIG_ENDIAN);
tmp_offset += 1;
proto_tree_add_item(tree,hf_pnrp_header_versionMinor,tvb,offset+tmp_offset,1,ENC_BIG_ENDIAN);
tmp_offset +=1;
proto_tree_add_item(tree,hf_pnrp_message_routeEntry_portNumber,tvb,offset+tmp_offset,2,ENC_BIG_ENDIAN);
tmp_offset +=2;
proto_tree_add_item(tree,hf_pnrp_message_routeEntry_flags,tvb,offset+tmp_offset,1,ENC_BIG_ENDIAN);
tmp_offset +=1;
proto_tree_add_item(tree,hf_pnrp_message_routeEntry_addressCount,tvb,offset+tmp_offset,1,ENC_BIG_ENDIAN);
tmp_offset +=1;
dissect_ipv6_address(tvb, offset+tmp_offset, length -tmp_offset, tree);
}
}
static void dissect_ipv6_endpoint_structure(tvbuff_t *tvb, gint offset, gint length, proto_tree *tree)
{
while (0 <= tvb_reported_length_remaining(tvb, offset+18) && 18 <=length) {
proto_tree_add_text(tree, tvb, offset, 2, "Port Number : %d",tvb_get_ntohs(tvb, offset));
dissect_ipv6_address(tvb, offset+2,16,tree);
offset += 18;
length -= 18;
}
}
static void dissect_ipv6_address(tvbuff_t *tvb, gint offset, gint length, proto_tree *tree)
{
while (0 <= tvb_reported_length_remaining(tvb, offset+16) && 16 <=length) {
proto_tree_add_item(tree, hf_pnrp_message_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
length -= 16;
}
}
static void dissect_encodedCPA_structure(tvbuff_t *tvb, gint offset, gint length, proto_tree *tree)
{
if (0 <= tvb_reported_length_remaining(tvb, offset+length)) {
guint8 flagsField;
proto_item *pnrp_encodedCPA_tree = NULL;
proto_item *pnrp_encodedCPA_item = NULL;
pnrp_encodedCPA_item = proto_tree_add_item(tree, hf_pnrp_encodedCPA, tvb, offset,length,ENC_NA);
pnrp_encodedCPA_tree = proto_item_add_subtree(pnrp_encodedCPA_item, ett_pnrp_message_encodedCPA);
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_encodedCPA_length, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_encodedCPA_minorVersion, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_encodedCPA_majorVersion, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_header_versionMinor, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_header_versionMajor, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_bitmask(pnrp_encodedCPA_tree, tvb, offset+6, hf_pnrp_encodedCPA_flags, ett_pnrp_message_encodedCPA_flags, encodedCPA_flags, ENC_BIG_ENDIAN);
flagsField = tvb_get_guint8(tvb,offset+6);
proto_tree_add_text(pnrp_encodedCPA_tree, tvb, offset + 7, 1, "Reserved");
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_encodedCPA_notAfter, tvb, offset+8, 8, ENC_BIG_ENDIAN);
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_encodedCPA_serviceLocation, tvb, offset+16, 16, ENC_NA);
offset +=32;
if ((flagsField & FLAGS_ENCODED_CPA_R)==0x00) {
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_message_nonce, tvb, offset, 16, ENC_NA);
offset +=16;
}
if (flagsField & FLAGS_ENCODED_CPA_A) {
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_encodedCPA_binaryAuthority, tvb, offset, 20, ENC_NA);
offset +=20;
}
if (flagsField & FLAGS_ENCODED_CPA_C) {
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_encodedCPA_classifiertHash, tvb, offset, 20, ENC_NA);
offset +=20;
}
if (flagsField & FLAGS_ENCODED_CPA_F) {
proto_tree_add_text(pnrp_encodedCPA_tree, tvb, offset,2, "Length of Friendly name : %d",tvb_get_letohs(tvb,offset));
proto_tree_add_item(pnrp_encodedCPA_tree, hf_pnrp_encodedCPA_friendlyName, tvb, offset+2, tvb_get_letohs(tvb,offset), ENC_ASCII|ENC_NA);
offset +=tvb_get_letohs(tvb,offset)+2;
}
proto_tree_add_text(pnrp_encodedCPA_tree, tvb, offset,2, "Number of Service Addresses : %d",tvb_get_letohs(tvb,offset));
offset += 2;
proto_tree_add_text(pnrp_encodedCPA_tree, tvb, offset,2, "Service Address Length : %d",tvb_get_letohs(tvb,offset));
offset += 2;
dissect_ipv6_endpoint_structure(tvb, offset,tvb_get_letohs(tvb,offset-4)*tvb_get_letohs(tvb,offset-2) , pnrp_encodedCPA_tree);
offset += tvb_get_letohs(tvb,offset-4)*tvb_get_letohs(tvb,offset-2);
proto_tree_add_text(pnrp_encodedCPA_tree, tvb, offset,2, "Number of Payload Structures : %d",tvb_get_letohs(tvb,offset));
offset += 2;
proto_tree_add_text(pnrp_encodedCPA_tree, tvb, offset,2, "Total Bytes of Payload : %d",tvb_get_letohs(tvb,offset));
offset += 2;
dissect_payload_structure(tvb,offset, tvb_get_letohs(tvb,offset-2)-4,pnrp_encodedCPA_tree);
offset += tvb_get_letohs(tvb,offset-2)-4;
dissect_publicKey_structure(tvb, offset,tvb_get_letohs(tvb,offset),pnrp_encodedCPA_tree);
offset += tvb_get_letohs(tvb,offset);
dissect_signature_structure(tvb, offset,tvb_get_letohs(tvb,offset),pnrp_encodedCPA_tree);
offset += tvb_get_letohs(tvb,offset);
}
}
static void dissect_payload_structure(tvbuff_t *tvb, gint offset, gint length, proto_tree *tree)
{
guint16 lengthOfData;
proto_item *pnrp_payload_tree = NULL;
proto_item *pnrp_payload_item = NULL;
if (0<length ) {
pnrp_payload_item = proto_tree_add_text(tree, tvb, offset, length, "Payload Structure");
pnrp_payload_tree = proto_item_add_subtree(pnrp_payload_item, ett_pnrp_message_payloadStructure);
proto_tree_add_text(pnrp_payload_tree, tvb, offset,4, "Payload Type : %d",tvb_get_letohl(tvb,offset));
offset += 4;
lengthOfData = tvb_get_letohs(tvb,offset);
proto_tree_add_text(pnrp_payload_tree, tvb, offset,2, "Length of Data : %d",lengthOfData);
offset += 2;
while (0 <= tvb_reported_length_remaining(tvb, offset+20)&& 20 <= lengthOfData) {
dissect_ipv6_address(tvb, offset, 16, pnrp_payload_tree);
offset += 16;
proto_tree_add_text(pnrp_payload_tree, tvb, offset,2, "Port Number : %d",tvb_get_letohs(tvb,offset));
offset += 2;
proto_tree_add_text(pnrp_payload_tree, tvb, offset,2, "IANA Protocol Number : %d",tvb_get_letohs(tvb,offset));
offset += 2;
lengthOfData -=20;
}
}
}
static void dissect_publicKey_structure(tvbuff_t *tvb, gint offset, gint length, proto_tree *tree)
{
guint16 objIDLength;
guint16 cbDataLength;
proto_item *pnrp_publicKey_tree = NULL;
proto_item *pnrp_publicKey_item = NULL;
if (0 < length && 0 <= tvb_reported_length_remaining(tvb, offset+length)) {
pnrp_publicKey_item = proto_tree_add_text(tree, tvb, offset, length, "CPA Public Key Structure");
pnrp_publicKey_tree = proto_item_add_subtree(pnrp_publicKey_item, ett_pnrp_message_publicKeyStructure);
proto_tree_add_text(pnrp_publicKey_tree, tvb, offset,2, "Length of Structure : %d",tvb_get_letohs(tvb,offset));
offset += 2;
objIDLength = tvb_get_letohs(tvb,offset);
proto_tree_add_text(pnrp_publicKey_tree, tvb, offset,2, "Size of Algorithm OID : %d",objIDLength);
offset += 2;
proto_tree_add_text(pnrp_publicKey_tree, tvb, offset,2, "Reserved : %d",tvb_get_ntohs(tvb,offset));
offset +=2;
cbDataLength = tvb_get_letohs(tvb,offset);
proto_tree_add_text(pnrp_publicKey_tree, tvb, offset,2, "Size of cbData : %d",cbDataLength);
offset += 2;
proto_tree_add_text(pnrp_publicKey_tree, tvb, offset,1, "Unused Bits : %d",7);
offset +=1;
proto_tree_add_item(pnrp_publicKey_tree, hf_pnrp_publicKey_objID, tvb, offset, objIDLength, ENC_ASCII|ENC_NA);
offset += objIDLength;
proto_tree_add_item(pnrp_publicKey_tree, hf_pnrp_publicKey_publicKeyData, tvb, offset, cbDataLength, ENC_ASCII|ENC_NA);
}
}
static void dissect_signature_structure(tvbuff_t *tvb, gint offset, gint length, proto_tree *tree)
{
guint16 signatureLength;
proto_item *pnrp_signature_tree = NULL;
proto_item *pnrp_signature_item = NULL;
if (0 < length && 0 <= tvb_reported_length_remaining(tvb, offset+length)) {
pnrp_signature_item = proto_tree_add_text(tree, tvb, offset, length, "Signature Structure");
pnrp_signature_tree = proto_item_add_subtree(pnrp_signature_item, ett_pnrp_message_signatureStructure);
proto_tree_add_text(pnrp_signature_tree, tvb, offset,2, "Length of Structure : %d",tvb_get_letohs(tvb,offset));
offset +=2;
signatureLength = tvb_get_letohs(tvb,offset);
proto_tree_add_text(pnrp_signature_tree, tvb, offset,2, "Length of Signature : %d",signatureLength);
offset += 2;
proto_tree_add_text(pnrp_signature_tree, tvb, offset,4, "Hash Algorithm Identifier : %x",tvb_get_letohl(tvb,offset));
offset += 4;
proto_tree_add_item(pnrp_signature_tree, hf_pnrp_signature_signatureData, tvb, offset, signatureLength, ENC_NA);
}
}
void proto_register_pnrp(void)
{
static hf_register_info hf[] = {
{ &hf_pnrp_header,
{ "Header", "pnrp.header", FT_NONE, BASE_NONE, NULL, 0x0,
"PNRP Header", HFILL }},
{ &hf_pnrp_header_fieldID,
{ "Header FieldID", "pnrp.header.fieldID", FT_UINT16, BASE_HEX, VALS(fieldID), 0x0,
NULL, HFILL }},
{ &hf_pnrp_header_length,
{ "Header length", "pnrp.header.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_header_ident,
{ "Ident", "pnrp.ident", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_header_versionMajor,
{ "Version Major", "pnrp.vMajor", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_header_versionMinor,
{ "Version Minor", "pnrp.vMinor", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_header_messageType,
{ "Message Type", "pnrp.messageType", FT_UINT8, BASE_DEC, VALS(messageType), 0x0,
NULL, HFILL }},
{ &hf_pnrp_header_messageID,
{ "Message ID", "pnrp.header.messageID", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_type,
{ "Segment Type", "pnrp.segment.type", FT_UINT16, BASE_HEX, VALS(fieldID), 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_length,
{ "Segment length", "pnrp.segment.length", FT_UINT16, BASE_DEC, NULL, 0x0,
"Message length", HFILL }},
{ &hf_pnrp_message_headerack,
{ "ACKed Header ID", "pnrp.segment.headerAck", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_pnrpID,
{ "PNRP ID", "pnrp.segment.pnrpID", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_inquire_flags,
{ "Flags", "pnrp.segment.inquire.flags", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_inquire_flags_reserved1,
{ "Reserved 1", "pnrp.segment.inquire.flags.reserved1", FT_UINT16, BASE_HEX, NULL, FLAGS_INQUIRE_RESERVED1,
NULL, HFILL }},
{ &hf_pnrp_message_inquire_flags_Abit,
{ "CPA should (a)ppear in response", "pnrp.segment.inquire.flags.Abit", FT_UINT16, BASE_HEX, NULL, FLAGS_INQUIRE_A,
NULL, HFILL }},
{ &hf_pnrp_message_inquire_flags_Xbit,
{ "E(X)tended Payload sent in Authority response", "pnrp.segment.inquire.flags.Xbit", FT_UINT16, BASE_HEX, NULL, FLAGS_INQUIRE_X,
NULL, HFILL }},
{ &hf_pnrp_message_inquire_flags_Cbit,
{ "(C)ertificate Chain sent in Authority response", "pnrp.segment.inquire.flags.Cbit", FT_UINT16, BASE_HEX, NULL, FLAGS_INQUIRE_C,
NULL, HFILL }},
{ &hf_pnrp_message_inquire_flags_reserved2,
{ "Reserved 2", "pnrp.segment.inquire.flags.reserved2", FT_UINT16, BASE_HEX, NULL, FLAGS_INQUIRE_RESERVED2,
NULL, HFILL }},
{ &hf_pnrp_message_classifier_unicodeCount,
{ "Number of Unicode Characters", "pnrp.segment.classifier.unicodeCount", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_classifier_arrayLength,
{ "Array Length", "pnrp.segment.classifier.arrayLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_classifier_entryLength,
{ "Entry Length", "pnrp.segment.classifier.entryLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_ack_flags_reserved,
{ "Reserved", "pnrp.segment.ack.flags.reserved", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_ack_flags_Nbit,
{ "(N)ot found Bit", "pnrp.segment.ack.flags.Nbit", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_authority_flags,
{ "Flags", "pnrp.segment.authority.flags", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_authority_flags_reserved1,
{ "Reserved 1", "pnrp.segment.authority.flags.reserved1", FT_UINT16, BASE_HEX, NULL, FLAGS_AUTHORITY_RESERVED1,
NULL, HFILL }},
{ &hf_pnrp_message_authority_flags_Lbit,
{ "(L)eaf Set", "pnrp.segment.authority.flags.Lbit", FT_UINT16, BASE_HEX, NULL, FLAGS_AUTHORITY_L,
NULL, HFILL }},
{ &hf_pnrp_message_authority_flags_reserved2,
{ "Reserved 2", "pnrp.segment.authority.flags.reserved2", FT_UINT16, BASE_HEX, NULL, FLAGS_AUTHORITY_RESERVED2,
NULL, HFILL }},
{ &hf_pnrp_message_authority_flags_Bbit,
{ "(B)usy", "pnrp.segment.authority.flags.Bbit", FT_UINT16, BASE_HEX, NULL, FLAGS_AUTHORITY_B,
NULL, HFILL }},
{ &hf_pnrp_message_authority_flags_reserved3,
{ "Reserved 3", "pnrp.segment.authority.flags.reserved3", FT_UINT16, BASE_HEX, NULL, FLAGS_AUTHORITY_RESERVED3,
NULL, HFILL }},
{ &hf_pnrp_message_authority_flags_Nbit,
{ "(N)ot found", "pnrp.segment.authority.flags.Nbit", FT_UINT16, BASE_HEX, NULL, FLAGS_AUTHORITY_N,
NULL, HFILL }},
{ &hf_pnrp_message_flood_flags_reserved1,
{ "Reserved", "pnrp.segment.flood.flags.reserved", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_flood_flags_Dbit,
{ "(D)on't send ACK", "pnrp.segment.flood.flags.Dbit", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_splitControls_authorityBuffer,
{ "Authority Buffer Size:", "pnrp.segment.splitControls.authorityBuffer", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_ipv6EndpointArray_NumberOfEntries,
{ "Number of Entries:", "pnrp.segment.ipv6EndpointArray.NumberOfEntries", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_ipv6EndpointArray_ArrayLength,
{ "Array Length:", "pnrp.segment.ipv6EndpointArray.ArrayLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_ipv6EndpointArray_EntryLength,
{ "Entry Length", "pnrp.segment.ipv6EndpointArray.EntryLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA,
{ "Encoded CPA structure", "pnrp.encodedCPA", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_length,
{ "Length", "pnrp.encodedCPA.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_majorVersion,
{ "CPA Major Version", "pnrp.encodedCPA.vMajor", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_minorVersion,
{ "CPA Minor Version", "pnrp.encodedCPA.vMinor", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_flags,
{ "Flags", "pnrp.encodedCPA.flags", FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_flags_reserved,
{ "Reserved", "pnrp.encodedCPA.flags.reserved", FT_UINT8, BASE_HEX, NULL, FLAGS_ENCODED_CPA_RESERVED,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_flags_Xbit,
{ "CPA has E(X)tended Payload", "pnrp.encodedCPA.flags.xbit", FT_UINT8, BASE_HEX, NULL, FLAGS_ENCODED_CPA_X,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_flags_Fbit,
{ "CPA contains (F)riendly Name", "pnrp.encodedCPA.flags.fbit", FT_UINT8, BASE_HEX, NULL, FLAGS_ENCODED_CPA_F,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_flags_Cbit,
{ "CPA contains (C)lassifier Hash", "pnrp.encodedCPA.flags.cbit", FT_UINT8, BASE_HEX, NULL, FLAGS_ENCODED_CPA_C,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_flags_Abit,
{ "CPA contains Binary (A)uthority field", "pnrp.encodedCPA.flags.abit", FT_UINT8, BASE_HEX, NULL, FLAGS_ENCODED_CPA_A,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_flags_Ubit,
{ "Friendly Name in (U)TF-8", "pnrp.encodedCPA.flags.ubit", FT_UINT8, BASE_HEX, NULL, FLAGS_ENCODED_CPA_U,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_flags_Rbit,
{ "This is a (r)evoke CPA", "pnrp.encodedCPA.flags.rbit", FT_UINT8, BASE_HEX, NULL, FLAGS_ENCODED_CPA_R,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_notAfter,
{ "CPA expiration Date", "pnrp.encodedCPA.expirationDate", FT_UINT64,BASE_DEC, NULL, 0x0,
"CPA expiration Date since January 1, 1601 UTC", HFILL }},
{ &hf_pnrp_encodedCPA_serviceLocation,
{ "Service Location", "pnrp.encodedCPA.serviceLocation", FT_BYTES,BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_encodedCPA_binaryAuthority,
{ "Binary Authority", "pnrp.encodedCPA.binaryAuthority", FT_BYTES,BASE_NONE, NULL, 0x0,
"SHA-1 Hash of PublicKey Data field", HFILL }},
{ &hf_pnrp_encodedCPA_classifiertHash,
{ "Classifiert Hash", "pnrp.encodedCPA.classifierHash", FT_BYTES,BASE_NONE, NULL, 0x0,
"SHA-1 Hash of the classifier text", HFILL }},
{ &hf_pnrp_encodedCPA_friendlyName,
{ "Friendly Name of PNRP ID", "pnrp.encodedCPA.friendlyName", FT_STRING,BASE_NONE, NULL, 0x0,
"A human-readable label identifying the PNRP ID", HFILL }},
{ &hf_pnrp_message_lookupControls_flags,
{ "Flags", "pnrp.lookupControls.flags", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_lookupControls_flags_reserved,
{ "Reserved", "pnrp.lookupControls.flags.reserved", FT_UINT16, BASE_HEX, NULL, FLAGS_LOOKUPCONTROLS_RESERVED,
NULL, HFILL }},
{ &hf_pnrp_message_lookupControls_flags_Abit,
{ "A bit:", "pnrp.lookupControls.flags.Abit", FT_UINT16, BASE_HEX, NULL, FLAGS_LOOKUPCONTROLS_A,
"Sender is willing to accept returned nodes that are not closer to the target ID than the Validate PNRP ID", HFILL }},
{ &hf_pnrp_message_lookupControls_flags_0bit,
{ "0 bit - reserved:", "pnrp.lookupControls.flags.0bit", FT_UINT16, BASE_HEX, NULL, FLAGS_LOOKUPCONTROLS_0,
NULL, HFILL }},
{ &hf_pnrp_message_lookupControls_precision,
{ "Precision", "pnrp.lookupControls.precision", FT_UINT16, BASE_HEX, NULL, 0x0,
"Precision - Number of significant bits to match", HFILL }},
{ &hf_pnrp_message_lookupControls_resolveCriteria,
{ "Resolve Criteria", "pnrp.lookupControls.resolveCriteria", FT_UINT8, BASE_HEX, VALS(resolveCriteria), 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_lookupControls_reasonCode,
{ "Reason Code", "pnrp.lookupControls.reasonCode", FT_UINT8, BASE_HEX, VALS(reasonCode), 0x0,
NULL, HFILL }},
{ &hf_pnrp_publicKey_objID,
{ "Public Key Object Identifier", "pnrp.publicKey.objID", FT_STRING,BASE_NONE, NULL, 0x0,
"An ASN.1-encoded object identifier (OID) indicating the public key format", HFILL }},
{ &hf_pnrp_publicKey_publicKeyData,
{ "Public Key Data", "pnrp.publicKey.publicKeyData", FT_STRING,BASE_NONE, NULL, 0x0,
"An ASN.1-encoded 1024-bit RSA public key", HFILL }},
{ &hf_pnrp_signature_signatureData,
{ "Signature", "pnrp.signature.data", FT_BYTES,BASE_NONE, NULL, 0x0,
"Signature created when signing the CPA", HFILL }},
{ &hf_pnrp_message_routeEntry_portNumber,
{ "Port Number", "pnrp.segment.routeEntry.portNumber", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_routeEntry_flags,
{ "Flags", "pnrp.segment.routeEntry.flags", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_routeEntry_addressCount,
{ "Address Count", "pnrp.segment.routeEntry.addressCount", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_nonce,
{ "Nonce", "pnrp.segment.nonce", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_hashednonce,
{ "Hashed Nonce", "pnrp.segment.hashednonce", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_idArray_NumEntries,
{ "Number of Entries", "pnrp.segment.idArray.NumEnries", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_idArray_Length,
{ "Length of Array", "pnrp.segment.idArray.Length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_ElementFieldType,
{ "Type of Array Entry", "pnrp.segment.ElementFieldType", FT_UINT16, BASE_HEX, VALS(fieldID), 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_idarray_Entrylength,
{ "Length of each Array Entry", "pnrp.segment.idArray.Entrylength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_certChain,
{ "Certificate Chain", "pnrp.segment.certChain", FT_BYTES,BASE_NONE, NULL, 0x0,
"A Certificate Chain, containing the public key used to sign the CPA and its Certificate Chain", HFILL }},
{ &hf_pnrp_message_solicitType,
{ "Solicit Type", "pnrp.segment.solicitType", FT_UINT8, BASE_DEC, VALS(solicitType), 0x0,
NULL, HFILL }},
{ &hf_pnrp_message_ipv6,
{ "IPv6 Address","pnrp.segment.ipv6Address",FT_IPv6, BASE_NONE, NULL, 0x0,NULL,HFILL}}
};
static gint *ett[] = {
&ett_pnrp,
&ett_pnrp_header,
&ett_pnrp_message,
&ett_pnrp_message_inquire_flags,
&ett_pnrp_message_authority_flags,
&ett_pnrp_message_encodedCPA,
&ett_pnrp_message_encodedCPA_flags,
&ett_pnrp_message_payloadStructure,
&ett_pnrp_message_publicKeyStructure,
&ett_pnrp_message_signatureStructure,
&ett_pnrp_message_lookupControls_flags
};
proto_pnrp = proto_register_protocol(PROTONAME,PROTOSHORTNAME,PROTOABBREV);
proto_register_field_array(proto_pnrp,hf,array_length(hf));
proto_register_subtree_array (ett, array_length(ett));
}
void proto_reg_handoff_pnrp(void)
{
dissector_handle_t pnrp_handle;
pnrp_handle = new_create_dissector_handle(dissect_pnrp, proto_pnrp);
dissector_add_uint("udp.port",PNRP_PORT,pnrp_handle);
}
