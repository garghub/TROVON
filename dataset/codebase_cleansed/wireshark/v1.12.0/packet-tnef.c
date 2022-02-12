static gint dissect_counted_values(tvbuff_t *tvb, gint offset, int hf_id, packet_info *pinfo, proto_tree *tree, gboolean single, guint encoding)
{
proto_item *item;
guint32 length, count, i;
count = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_tnef_values_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
if(count > 1) {
if(single) {
item = proto_tree_add_expert_format(tree, pinfo, &ei_tnef_expect_single_item, tvb, offset, 4,
"Expecting a single item but found %d", count);
tree = proto_item_add_subtree(item, ett_tnef_counted_items);
}
}
offset += 4;
for(i = 0; i < count; i++) {
length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tree, hf_tnef_value_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_id, tvb, offset, length, encoding);
offset += length;
}
return offset;
}
static gint dissect_counted_address(tvbuff_t *tvb, gint offset, packet_info *pinfo _U_, proto_tree *tree)
{
guint16 length;
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_tnef_value_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_tnef_attribute_display_name, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += length;
length = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_tnef_value_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_tnef_attribute_email_address, tvb, offset, length, ENC_ASCII|ENC_NA);
offset += length;
return offset;
}
static void dissect_DTR(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
gint offset;
offset = 0;
proto_tree_add_item(tree, hf_tnef_attribute_date_year, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_tnef_attribute_date_month, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_tnef_attribute_date_day, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_tnef_attribute_date_hour, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_tnef_attribute_date_minute, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_tnef_attribute_date_second, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset +=2;
proto_tree_add_item(tree, hf_tnef_attribute_date_day_of_week, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void dissect_mapiprops(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *item, *prop_item;
proto_tree *prop_tree, *tag_tree;
guint32 tag, tag_kind, tag_length;
guint16 padding;
gint offset, start_offset;
guint8 drep[] = {0x10 , 0 };
static dcerpc_info di;
static dcerpc_call_value call_data;
offset = 0;
di.conformant_run = 0;
di.call_data = &call_data;
di.dcerpc_procedure_name = "";
proto_tree_add_item(tree, hf_tnef_mapi_props_count, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
while(tvb_reported_length_remaining(tvb, offset) > 0 ) {
start_offset = offset;
prop_item = proto_tree_add_item(tree, hf_tnef_property, tvb, offset, -1, ENC_NA);
prop_tree = proto_item_add_subtree(prop_item, ett_tnef_property);
item = proto_tree_add_item(prop_tree, hf_tnef_property_tag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
tag_tree = proto_item_add_subtree(item, ett_tnef_property_tag);
tag = tvb_get_letohl(tvb, offset);
proto_item_append_text(prop_item, " %s", val_to_str(tag, nspi_MAPITAGS_vals, "Unknown tag (0x%08lx)"));
proto_tree_add_item(tag_tree, hf_tnef_property_tag_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tag_tree, hf_tnef_property_tag_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if(tag & 0x80000000) {
proto_tree_add_item(tag_tree, hf_tnef_property_tag_set, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset += 16;
tag_kind = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tag_tree, hf_tnef_property_tag_kind, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if(tag_kind == 0) {
proto_tree_add_item(tag_tree, hf_tnef_property_tag_name_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_item_append_text(prop_item, " [Named Property]");
} else {
char *name_string = NULL;
tag_length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(tag_tree, hf_tnef_property_tag_name_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tag_tree, hf_tnef_property_tag_name_string, tvb, offset, tag_length, ENC_UTF_16|ENC_LITTLE_ENDIAN);
offset += tag_length;
if((padding = (4 - tag_length % 4)) != 4) {
proto_tree_add_item(tag_tree, hf_tnef_property_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
proto_item_append_text(prop_item, " [Named Property: %s]", name_string);
}
}
switch(tag) {
default:
switch(tag & 0x0000ffff) {
case PT_I2:
offset = PIDL_dissect_uint16(tvb, offset, pinfo, prop_tree, &di, drep, hf_tnef_PropValue_i, 0);
break;
case PT_LONG:
offset = PIDL_dissect_uint32(tvb, offset, pinfo, prop_tree, &di, drep, hf_tnef_PropValue_l, 0);
break;
case PT_BOOLEAN:
offset = PIDL_dissect_uint16(tvb, offset, pinfo, prop_tree, &di, drep, hf_tnef_PropValue_b, 0);
break;
case PT_STRING8:
offset = dissect_counted_values(tvb, offset, hf_tnef_PropValue_lpszA, pinfo, prop_tree, TRUE, ENC_ASCII|ENC_NA);
break;
case PT_BINARY:
offset = dissect_counted_values(tvb, offset, hf_tnef_PropValue_bin, pinfo, prop_tree, TRUE, ENC_NA);
break;
case PT_UNICODE:
offset = dissect_counted_values (tvb, offset, hf_tnef_PropValue_lpszW, pinfo, prop_tree, TRUE, ENC_UTF_16|ENC_NA);
break;
case PT_CLSID:
offset = nspi_dissect_struct_MAPIUID(tvb, offset, pinfo, prop_tree, &di, drep, hf_tnef_PropValue_lpguid, 0);
break;
case PT_SYSTIME:
offset = nspi_dissect_struct_FILETIME(tvb,offset,pinfo,prop_tree,&di,drep,hf_tnef_PropValue_ft,0);
break;
case PT_ERROR:
offset = nspi_dissect_enum_MAPISTATUS(tvb, offset, pinfo, prop_tree, &di, drep, hf_tnef_PropValue_err, 0);
break;
case PT_MV_I2:
offset = nspi_dissect_struct_SShortArray(tvb,offset,pinfo,prop_tree,&di,drep,hf_tnef_PropValue_MVi,0);
break;
case PT_MV_LONG:
offset = nspi_dissect_struct_MV_LONG_STRUCT(tvb,offset,pinfo,prop_tree,&di,drep,hf_tnef_PropValue_MVl,0);
break;
case PT_MV_STRING8:
offset = nspi_dissect_struct_SLPSTRArray(tvb,offset,pinfo,prop_tree,&di,drep,hf_tnef_PropValue_MVszA,0);
break;
case PT_MV_BINARY:
offset = nspi_dissect_struct_SBinaryArray(tvb,offset,pinfo,prop_tree,&di,drep,hf_tnef_PropValue_MVbin,0);
break;
case PT_MV_CLSID:
offset = nspi_dissect_struct_SGuidArray(tvb,offset,pinfo,prop_tree,&di,drep,hf_tnef_PropValue_MVguid,0);
break;
case PT_MV_UNICODE:
offset = nspi_dissect_struct_MV_UNICODE_STRUCT(tvb,offset,pinfo,prop_tree,&di,drep,hf_tnef_PropValue_MVszW,0);
break;
case PT_MV_SYSTIME:
offset = nspi_dissect_struct_SDateTimeArray(tvb,offset,pinfo,prop_tree,&di,drep,hf_tnef_PropValue_MVft,0);
break;
case PT_NULL:
offset = PIDL_dissect_uint32(tvb, offset, pinfo, prop_tree, &di, drep, hf_tnef_PropValue_null, 0);
break;
case PT_OBJECT:
offset = PIDL_dissect_uint32(tvb, offset, pinfo, prop_tree, &di, drep, hf_tnef_PropValue_object, 0);
break;
}
}
if((padding = (4 - (offset - start_offset) % 4)) != 4) {
proto_tree_add_item(prop_tree, hf_tnef_property_padding, tvb, offset, padding, ENC_NA);
offset += padding;
}
proto_item_set_len(prop_item, offset - start_offset);
}
}
static void dissect_tnef(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *attr_item, *item;
proto_tree *attr_tree, *tag_tree, *props_tree, *addr_tree, *date_tree;
guint32 tag, length, signature;
gint offset, start_offset;
tvbuff_t *next_tvb;
if(tree){
item = proto_tree_add_item(tree, proto_tnef, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_tnef);
}
offset = 0;
signature = tvb_get_letohl(tvb, offset);
item = proto_tree_add_item(tree, hf_tnef_signature, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
if(signature != TNEF_SIGNATURE) {
expert_add_info_format(pinfo, item, &ei_tnef_incorrect_signature,
" [Incorrect, should be 0x%x. No further dissection possible. Check any Content-Transfer-Encoding has been removed.]", TNEF_SIGNATURE);
return;
} else {
proto_item_append_text(item, " [Correct]");
}
proto_tree_add_item(tree, hf_tnef_key, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
while(tvb_reported_length_remaining(tvb, offset) > 9 ) {
start_offset = offset;
attr_item = proto_tree_add_item(tree, hf_tnef_attribute, tvb, offset, -1, ENC_NA);
attr_tree = proto_item_add_subtree(attr_item, ett_tnef_attribute);
proto_tree_add_item(attr_tree, hf_tnef_attribute_lvl, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
item = proto_tree_add_item(attr_tree, hf_tnef_attribute_tag, tvb, offset, 4, ENC_LITTLE_ENDIAN);
tag_tree = proto_item_add_subtree(item, ett_tnef_attribute_tag);
tag = tvb_get_letohl(tvb, offset);
proto_item_append_text(attr_item, " %s", val_to_str(tag, tnef_Attribute_vals, "Unknown tag (0x%08lx)"));
proto_tree_add_item(tag_tree, hf_tnef_attribute_tag_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tag_tree, hf_tnef_attribute_tag_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
length = tvb_get_letohl(tvb, offset);
proto_tree_add_item(attr_tree, hf_tnef_attribute_length, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
switch(tag) {
case ATT_OEM_CODEPAGE:
proto_tree_add_item(attr_tree, hf_tnef_oem_codepage, tvb, offset, length, ENC_LITTLE_ENDIAN);
break;
case ATT_TNEF_VERSION:
proto_tree_add_item(attr_tree, hf_tnef_version, tvb, offset, length, ENC_LITTLE_ENDIAN);
break;
case ATT_MESSAGE_CLASS:
proto_tree_add_item(attr_tree, hf_tnef_message_class, tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case ATT_ORIGINAL_MESSAGE_CLASS:
proto_tree_add_item(attr_tree, hf_tnef_original_message_class, tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case ATT_MAPI_PROPS:
item = proto_tree_add_item(attr_tree, hf_tnef_mapi_props, tvb, offset, length, ENC_NA);
props_tree = proto_item_add_subtree(item, ett_tnef_mapi_props);
next_tvb = tvb_new_subset(tvb, offset, length, length);
dissect_mapiprops(next_tvb, pinfo, props_tree);
break;
case ATT_OWNER:
case ATT_SENT_FOR:
addr_tree = proto_item_add_subtree(item, ett_tnef_attribute_address);
(void)dissect_counted_address(tvb, offset, pinfo, addr_tree);
break;
case ATT_PRIORITY:
proto_tree_add_item(attr_tree, hf_tnef_priority, tvb, offset, length, ENC_LITTLE_ENDIAN);
break;
default:
switch((tag >> 16) & 0xffff) {
case ATP_DATE:
item = proto_tree_add_item(attr_tree, hf_tnef_attribute_date, tvb, offset, length, ENC_NA);
date_tree = proto_item_add_subtree(item, ett_tnef_attribute_date);
next_tvb = tvb_new_subset(tvb, offset, length, length);
dissect_DTR(next_tvb, pinfo, date_tree);
break;
case ATP_STRING:
proto_tree_add_item(attr_tree, hf_tnef_attribute_string, tvb, offset, length, ENC_ASCII|ENC_NA);
proto_item_append_text(attr_item, " %s", tvb_get_string(wmem_packet_scope(), tvb, offset, length));
break;
default:
proto_tree_add_item(attr_tree, hf_tnef_attribute_value, tvb, offset, length, ENC_NA);
break;
}
}
offset += length;
proto_tree_add_item(attr_tree, hf_tnef_attribute_checksum, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_item_set_len(attr_item, offset - start_offset);
}
if(tvb_reported_length_remaining(tvb, offset))
proto_tree_add_item(tree, hf_tnef_padding, tvb, offset, tvb_reported_length_remaining(tvb, offset), ENC_NA);
}
static void dissect_tnef_file(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_set_str(pinfo->cinfo, COL_DEF_SRC, PSNAME " encoded file");
col_append_str(pinfo->cinfo, COL_INFO, PNAME);
dissect_tnef(tvb, pinfo, tree);
}
void
proto_register_tnef(void)
{
static hf_register_info hf[] = {
{ &hf_tnef_signature,
{ "Signature", "tnef.signature", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_key,
{ "Key", "tnef.key", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute,
{ "Attribute", "tnef.attribute", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_lvl,
{ "Type", "tnef.attribute.lvl", FT_UINT8, BASE_DEC, VALS(tnef_Lvl_vals), 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_tag,
{ "Tag", "tnef.attribute.tag", FT_UINT32, BASE_HEX, VALS(tnef_Attribute_vals), 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_tag_type,
{ "Type", "tnef.attribute.tag.type", FT_UINT16, BASE_HEX, VALS(tnef_Types_vals), 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_tag_id,
{ "Tag", "tnef.attribute.tag.id", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_length,
{ "Length", "tnef.attribute.length", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_value,
{ "Value", "tnef.attribute.value", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_string,
{ "String", "tnef.attribute.string", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_date,
{ "Date", "tnef.attribute.date", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_display_name,
{ "Display Name", "tnef.attribute.display_name", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_email_address,
{ "Email Address", "tnef.attribute.email_address", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_attribute_date_year,
{ "Year", "tnef.attribute.date.year", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_attribute_date_month,
{ "Month", "tnef.attribute.date.month", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_attribute_date_day,
{ "Day", "tnef.attribute.date.day", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_attribute_date_hour,
{ "Hour", "tnef.attribute.date.hour", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_attribute_date_minute,
{ "Minute", "tnef.attribute.date.minute", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_attribute_date_second,
{ "Second", "tnef.attribute.date.second", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_attribute_date_day_of_week,
{ "Day Of Week", "tnef.attribute.date.day_of_week", FT_UINT16, BASE_DEC, VALS(weekday_vals), 0, NULL, HFILL }},
{ &hf_tnef_attribute_checksum,
{ "Checksum", "tnef.attribute.checksum", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_mapi_props,
{ "MAPI Properties", "tnef.mapi_props", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_version,
{ "Version", "tnef.version", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_oem_codepage,
{ "OEM Codepage", "tnef.oem_codepage", FT_UINT64, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_message_class,
{ "Message Class", "tnef.message_class", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_original_message_class,
{ "Original Message Class", "tnef.message_class.original", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_priority,
{ "Priority", "tnef.priority", FT_UINT16, BASE_DEC, VALS(tnef_Priority_vals), 0x0,
NULL, HFILL }},
{ &hf_tnef_mapi_props_count,
{ "Count", "tnef.mapi_props.count", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_property,
{ "Property", "tnef.property", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_property_tag,
{ "Tag", "tnef.property.tag", FT_UINT32, BASE_HEX, VALS(nspi_MAPITAGS_vals), 0x0,
NULL, HFILL }},
{ &hf_tnef_property_tag_type,
{ "Type", "tnef.property.tag.type", FT_UINT16, BASE_HEX, VALS(nspi_property_types_vals), 0x0,
NULL, HFILL }},
{ &hf_tnef_property_tag_id,
{ "Tag", "tnef.property.tag.id", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_property_tag_set,
{ "Set", "tnef.attribute.tag.set", FT_GUID, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_property_tag_kind,
{ "Kind", "tnef.attribute.tag.kind", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_property_tag_name_id,
{ "Name", "tnef.attribute.tag.name.id", FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_property_tag_name_length,
{ "Length", "tnef.attribute.tag.name.length", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_property_tag_name_string,
{ "Name", "tnef.attribute.tag.name.string", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_property_padding,
{ "Padding", "tnef.property.padding", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_padding,
{ "Padding", "tnef.padding", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_values_count,
{ "Count", "tnef.values.count", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_value_length,
{ "Length", "tnef.value.length", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_tnef_PropValue_i,
{ "I", "tnef.PropValue.i", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_l,
{ "L", "tnef.PropValue.l", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_b,
{ "B", "tnef.PropValue.b", FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_lpszA,
{ "Lpsza", "tnef.PropValue.lpszA", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_lpszW,
{ "Lpszw", "tnef.PropValue.lpszW", FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_lpguid,
{ "Lpguid", "tnef.PropValue.lpguid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_bin,
{ "Bin", "tnef.PropValue.bin", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_ft,
{ "Ft", "tnef.PropValue.ft", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_err,
{ "Err", "tnef.PropValue.err", FT_UINT32, BASE_DEC, VALS(nspi_MAPISTATUS_vals), 0, NULL, HFILL }},
{ &hf_tnef_PropValue_MVi,
{ "Mvi", "tnef.PropValue.MVi", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_MVl,
{ "Mvl", "tnef.PropValue.MVl", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_MVszA,
{ "Mvsza", "tnef.PropValue.MVszA", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_MVbin,
{ "Mvbin", "tnef.PropValue.MVbin", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_MVguid,
{ "Mvguid", "tnef.PropValue.MVguid", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_MVszW,
{ "Mvszw", "tnef.PropValue.MVszW", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_MVft,
{ "Mvft", "tnef.PropValue.MVft", FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_null,
{ "Null", "tnef.PropValue.null", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
{ &hf_tnef_PropValue_object,
{ "Object", "tnef.PropValue.object", FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_tnef,
&ett_tnef_attribute,
&ett_tnef_attribute_tag,
&ett_tnef_mapi_props,
&ett_tnef_property,
&ett_tnef_property_tag,
&ett_tnef_counted_items,
&ett_tnef_attribute_date,
&ett_tnef_attribute_address,
};
static ei_register_info ei[] = {
{ &ei_tnef_expect_single_item, { "tnef.expect_single_item", PI_MALFORMED, PI_ERROR, "Expected single item", EXPFILL }},
{ &ei_tnef_incorrect_signature, { "tnef.signature.incorrect", PI_MALFORMED, PI_WARN, "Incorrect signature", EXPFILL }},
};
expert_module_t* expert_tnef;
proto_tnef = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_register_field_array(proto_tnef, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_tnef = expert_register_protocol(proto_tnef);
expert_register_field_array(expert_tnef, ei, array_length(ei));
tnef_handle = register_dissector(PFNAME, dissect_tnef, proto_tnef);
}
void
proto_reg_handoff_tnef(void)
{
dissector_handle_t tnef_file_handle;
tnef_file_handle = create_dissector_handle(dissect_tnef_file, proto_tnef);
dissector_add_string("media_type", "application/ms-tnef", tnef_handle);
register_ber_oid_dissector_handle("1.2.840.113556.3.10.1", tnef_handle, proto_tnef, "id-et-tnef");
dissector_add_uint("wtap_encap", WTAP_ENCAP_TNEF, tnef_file_handle);
}
