static int
dissect_banana_element(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset) {
proto_item *ti;
proto_tree *list_tree;
guint8 byte = 0;
gint64 val = 0;
gint val_len = 0;
int start_offset = offset;
int old_offset;
int i;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
byte = tvb_get_guint8(tvb, offset);
offset++;
if (byte & 0x80) {
if (is_element(byte)) {
break;
} else {
expert_add_info_format(pinfo, NULL, &ei_banana_unknown_type, "Unknown type %u", byte);
}
} else {
val_len++;
if (val_len > MAX_ELEMENT_VAL_LEN) {
expert_add_info(pinfo, NULL, &ei_banana_too_many_value_bytes);
}
val += byte + (val << 7);
}
}
switch (byte) {
case BE_LIST:
if (val > MAX_ELEMENT_VAL) {
expert_add_info_format(pinfo, NULL, &ei_banana_length_too_long, "List length %" G_GINT64_MODIFIER "d longer than we can handle", val);
}
ti = proto_tree_add_uint_format_value(tree, hf_banana_list, tvb, start_offset, offset - start_offset - 1, (guint32) val, "(%d items)", (gint) val);
list_tree = proto_item_add_subtree(ti, ett_list);
for (i = 0; i < val; i++) {
old_offset = offset;
offset += dissect_banana_element(tvb, pinfo, list_tree, offset);
if (offset <= old_offset) {
return offset - start_offset;
}
}
break;
case BE_INT:
if (val > MAX_ELEMENT_VAL) {
expert_add_info_format(pinfo, NULL, &ei_banana_value_too_large, "Integer value %" G_GINT64_MODIFIER "d too large", val);
}
proto_tree_add_uint(tree, hf_banana_int, tvb, start_offset, offset - start_offset, (guint32) val);
break;
case BE_STRING:
if (val > MAX_ELEMENT_VAL) {
expert_add_info_format(pinfo, NULL, &ei_banana_length_too_long, "String length %" G_GINT64_MODIFIER "d longer than we can handle", val);
}
proto_tree_add_item(tree, hf_banana_string, tvb, offset, (guint32) val, ENC_ASCII|ENC_NA);
offset += (gint) val;
break;
case BE_NEG_INT:
if (val > MAX_ELEMENT_VAL) {
expert_add_info_format(pinfo, NULL, &ei_banana_value_too_large, "Integer value -%" G_GINT64_MODIFIER "d too large", val);
}
proto_tree_add_int(tree, hf_banana_neg_int, tvb, start_offset, offset - start_offset, (gint32) val * -1);
break;
case BE_FLOAT:
proto_tree_add_item(tree, hf_banana_float, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
break;
case BE_LG_INT:
proto_tree_add_item(tree, hf_banana_lg_int, tvb, start_offset, offset - start_offset, ENC_NA);
break;
case BE_LG_NEG_INT:
proto_tree_add_item(tree, hf_banana_lg_neg_int, tvb, start_offset, offset - start_offset, ENC_NA);
break;
case BE_PB:
if (val_len > 1) {
expert_add_info(pinfo, NULL, &ei_banana_pb_error);
}
proto_tree_add_item(tree, hf_banana_pb, tvb, offset - 2, 1, ENC_BIG_ENDIAN);
break;
default:
return 0;
break;
}
return offset - start_offset;
}
static int
dissect_banana(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
guint8 byte = 0;
gint offset = 0, old_offset;
proto_item *ti;
proto_tree *banana_tree;
if (tvb_reported_length(tvb) < 2)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Banana");
while (tvb_reported_length_remaining(tvb, offset) > 0 && offset < MAX_ELEMENT_VAL_LEN) {
byte = tvb_get_guint8(tvb, offset);
if (is_element(byte))
break;
offset++;
}
col_add_fstr(pinfo->cinfo, COL_INFO, "First element: %s",
val_to_str(byte, type_vals, "Unknown type: %u"));
ti = proto_tree_add_item(tree, proto_banana, tvb, 0, -1, ENC_NA);
banana_tree = proto_item_add_subtree(ti, ett_banana);
offset = 0;
old_offset = -1;
while (offset > old_offset) {
old_offset = offset;
offset += dissect_banana_element(tvb, pinfo, banana_tree, offset);
}
return tvb_reported_length(tvb);
}
void
proto_register_banana(void)
{
static hf_register_info hf[] = {
{ &hf_banana_list,
{ "List Length", "banana.list",
FT_UINT32, BASE_DEC, NULL, 0,
"Banana list", HFILL }
},
{ &hf_banana_int,
{ "Integer", "banana.int",
FT_UINT32, BASE_DEC, NULL, 0,
"Banana integer", HFILL }
},
{ &hf_banana_string,
{ "String", "banana.string",
FT_STRING, BASE_NONE, NULL, 0,
"Banana string", HFILL }
},
{ &hf_banana_neg_int,
{ "Negative Integer", "banana.neg_int",
FT_INT32, BASE_DEC, NULL, 0,
"Banana negative integer", HFILL }
},
{ &hf_banana_float,
{ "Float", "banana.float",
FT_DOUBLE, BASE_NONE, NULL, 0,
"Banana float", HFILL }
},
{ &hf_banana_lg_int,
{ "Float", "banana.lg_int",
FT_BYTES, BASE_NONE, NULL, 0,
"Banana large integer", HFILL }
},
{ &hf_banana_lg_neg_int,
{ "Float", "banana.lg_neg_int",
FT_BYTES, BASE_NONE, NULL, 0,
"Banana large negative integer", HFILL }
},
{ &hf_banana_pb,
{ "pb Profile Value", "banana.pb",
FT_UINT8, BASE_HEX, VALS(pb_vals), 0,
"Banana Perspective Broker Profile Value", HFILL }
}
};
expert_module_t* expert_banana;
static gint *ett[] = {
&ett_banana,
&ett_list
};
static ei_register_info ei[] = {
{ &ei_banana_unknown_type, { "banana.unknown_type", PI_UNDECODED, PI_ERROR, "Unknown type", EXPFILL }},
{ &ei_banana_too_many_value_bytes, { "banana.too_many_value_bytes", PI_UNDECODED, PI_ERROR, "Too many value/length bytes", EXPFILL }},
{ &ei_banana_length_too_long, { "banana.length_too_long", PI_UNDECODED, PI_ERROR, "Length too long", EXPFILL }},
{ &ei_banana_value_too_large, { "banana.value_too_large", PI_MALFORMED, PI_ERROR, "Value too large", EXPFILL }},
{ &ei_banana_pb_error, { "banana.pb_error", PI_MALFORMED, PI_ERROR, "More than 1 byte before pb", EXPFILL }},
};
proto_banana = proto_register_protocol("Twisted Banana", "Banana", "banana");
proto_register_field_array(proto_banana, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_banana = expert_register_protocol(proto_banana);
expert_register_field_array(expert_banana, ei, array_length(ei));
}
void
proto_reg_handoff_banana(void)
{
banana_handle = create_dissector_handle(dissect_banana, proto_banana);
dissector_add_uint_range_with_preference("tcp.port", "", banana_handle);
}
