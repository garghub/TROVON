static proto_item *
dissect_cbor_unsigned_integer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset, guint8 type_minor)
{
proto_item *item;
switch (type_minor) {
case 0x18:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_uint8, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
return item;
case 0x19:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_uint16, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
return item;
case 0x1a:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_uint32, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
return item;
case 0x1b:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_uint64, tvb, *offset, 8, ENC_BIG_ENDIAN);
*offset += 8;
return item;
default:
if (type_minor <= 0x17) {
item = proto_tree_add_item(cbor_tree, hf_cbor_type_uints, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
return item;
}
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_minor_type,
"invalid minor type %i in unsigned integer", type_minor);
return NULL;
}
}
static proto_item *
dissect_cbor_negative_integer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset, guint8 type_minor)
{
gint64 value;
proto_item *item;
switch (type_minor) {
case 0x18:
*offset += 1;
value = (gint64)-1 - tvb_get_guint8(tvb, *offset);
item = proto_tree_add_int64(cbor_tree, hf_cbor_type_nint, tvb, *offset, 1, value);
*offset += 1;
return item;
case 0x19:
*offset += 1;
value = (gint64)-1 - tvb_get_ntohs(tvb, *offset);
item = proto_tree_add_int64(cbor_tree, hf_cbor_type_nint, tvb, *offset, 2, value);
*offset += 2;
return item;
case 0x1a:
*offset += 1;
value = (gint64)-1 - tvb_get_ntohl(tvb, *offset);
item = proto_tree_add_int64(cbor_tree, hf_cbor_type_nint, tvb, *offset, 4, value);
*offset += 4;
return item;
case 0x1b:
*offset += 1;
value = (gint64)-1 - tvb_get_ntoh64(tvb, *offset);
if (value > -1) {
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_too_long_length,
"The value is too small, we can not display it correctly");
}
item = proto_tree_add_int64(cbor_tree, hf_cbor_type_nint, tvb, *offset, 8, value);
*offset += 8;
return item;
default:
if (type_minor <= 0x17) {
value = -1 - type_minor;
item = proto_tree_add_int64(cbor_tree, hf_cbor_type_nint, tvb, *offset, 1, value);
*offset += 1;
return item;
}
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_minor_type,
"invalid minor type %i in negative integer", type_minor);
return NULL;
}
}
static proto_item *
dissect_cbor_byte_string(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset, guint8 type_minor)
{
guint64 length;
gint eof_type;
proto_tree *subtree;
proto_item *item;
proto_item *elem;
switch (type_minor) {
case 0x18:
*offset += 1;
length = tvb_get_guint8(tvb, *offset);
*offset += 1;
break;
case 0x19:
*offset += 1;
length = tvb_get_ntohs(tvb, *offset);
*offset += 2;
break;
case 0x1a:
*offset += 1;
length = tvb_get_ntohl(tvb, *offset);
*offset += 4;
break;
case 0x1b:
*offset += 1;
length = tvb_get_ntoh64(tvb, *offset);
*offset += 8;
break;
case 0x1f:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_byte_string_undef, tvb, *offset, 1, ENC_NA);
subtree = proto_item_add_subtree(item, ett_cbor_byte_string_undef);
while (1)
{
eof_type = tvb_get_guint8(tvb, *offset);
if (eof_type == 0xff) {
*offset += 1;
proto_item_set_end(item, tvb, *offset);
return item;
}
if (((eof_type & 0xe0) >> 5) != CBOR_TYPE_BYTE_STRING) {
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_element,
"invalid element %i, expected byte string", (eof_type & 0xe0) >> 5);
return NULL;
}
elem = dissect_cbor_byte_string(tvb, pinfo, subtree, offset, eof_type & 0x1f);
if (!elem)
return NULL;
}
DISSECTOR_ASSERT_NOT_REACHED();
return item;
default:
if (type_minor <= 0x17) {
length = type_minor;
*offset += 1;
break;
}
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_minor_type,
"invalid minor type %i in byte string", type_minor);
return NULL;
}
if (length > G_MAXINT32 || *offset + (gint)length < *offset) {
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_too_long_length,
"the length (%" G_GUINT64_FORMAT ") of the byte string too long", length);
return NULL;
}
item = proto_tree_add_item(cbor_tree, hf_cbor_type_byte_string, tvb, *offset, (gint)length, ENC_BIG_ENDIAN|ENC_NA);
*offset += (gint)length;
return item;
}
static proto_item *
dissect_cbor_text_string(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset, guint8 type_minor)
{
guint64 length = 0;
gint eof_type;
proto_tree *subtree;
proto_item *item;
proto_item *elem;
switch (type_minor) {
case 0x18:
*offset += 1;
length = tvb_get_guint8(tvb, *offset);
*offset += 1;
break;
case 0x19:
*offset += 1;
length = tvb_get_ntohs(tvb, *offset);
*offset += 2;
break;
case 0x1a:
*offset += 1;
length = tvb_get_ntohl(tvb, *offset);
*offset += 4;
break;
case 0x1b:
*offset += 1;
length = tvb_get_ntoh64(tvb, *offset);
*offset += 8;
break;
case 0x1f:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_text_string_undef, tvb, *offset, 1, ENC_NA);
subtree = proto_item_add_subtree(item, ett_cbor_text_string_undef);
while (1)
{
eof_type = tvb_get_guint8(tvb, *offset);
if (eof_type == 0xff) {
*offset += 1;
proto_item_set_end(item, tvb, *offset);
return item;
}
if (((eof_type & 0xe0) >> 5) != CBOR_TYPE_TEXT_STRING) {
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_element,
"invalid element %i, expected text string", (eof_type & 0xe0) >> 5);
return NULL;
}
elem = dissect_cbor_text_string(tvb, pinfo, subtree, offset, eof_type & 0x1f);
if (!elem)
return NULL;
}
DISSECTOR_ASSERT_NOT_REACHED();
return item;
default:
if (type_minor <= 0x17) {
length = type_minor;
*offset += 1;
break;
}
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_minor_type,
"invalid minor type %i in text string", type_minor);
return NULL;
}
if (length > G_MAXINT32 || *offset + (gint)length < *offset) {
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_too_long_length,
"the length (%" G_GUINT64_FORMAT ") of the text string too long", length);
return NULL;
}
item = proto_tree_add_item(cbor_tree, hf_cbor_type_text_string, tvb, *offset, (gint)length, ENC_BIG_ENDIAN|ENC_UTF_8);
*offset += (gint)length;
return item;
}
static proto_item *
dissect_cbor_array(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset, guint8 type_minor)
{
guint64 length = 0;
guint64 i;
gint orig_offset = *offset;
proto_tree *subtree;
proto_item *item;
proto_item *elem;
gboolean eof = 0;
switch (type_minor) {
case 0x18:
*offset += 1;
length = tvb_get_guint8(tvb, *offset);
*offset += 1;
break;
case 0x19:
*offset += 1;
length = tvb_get_ntohs(tvb, *offset);
*offset += 2;
break;
case 0x1a:
*offset += 1;
length = tvb_get_ntohl(tvb, *offset);
*offset += 4;
break;
case 0x1b:
*offset += 1;
length = tvb_get_ntoh64(tvb, *offset);
*offset += 8;
break;
case 0x1f:
*offset += 1;
length = INT_MAX;
eof = 1;
break;
default:
if (type_minor <= 0x17) {
length = type_minor;
*offset += 1;
break;
}
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_minor_type,
"invalid minor type %i in array", type_minor);
return NULL;
}
if (eof) {
item = proto_tree_add_string_format_value(cbor_tree, hf_cbor_type_array,
tvb, orig_offset, -1, "Array", "(undefined elements)");
} else {
item = proto_tree_add_string_format_value(cbor_tree, hf_cbor_type_array,
tvb, orig_offset, -1, "Array", "(%"G_GINT64_MODIFIER"u elements)", length);
}
subtree = proto_item_add_subtree(item, ett_cbor_array);
for (i = 0; i < length; i++)
{
if (eof) {
gint value = tvb_get_guint8(tvb, *offset);
if (value == 0xff) {
*offset += 1;
break;
}
}
elem = dissect_cbor_main_type(tvb, pinfo, subtree, offset);
if (!elem)
return NULL;
}
proto_item_set_end(item, tvb, *offset);
return item;
}
static proto_item *
dissect_cbor_map(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset, guint8 type_minor)
{
guint64 length = 0;
guint64 i;
gint orig_offset = *offset;
proto_tree *subtree;
proto_item *item;
gboolean eof = 0;
proto_tree *key_tree;
proto_item *key;
switch (type_minor) {
case 0x18:
*offset += 1;
length = tvb_get_guint8(tvb, *offset);
*offset += 1;
break;
case 0x19:
*offset += 1;
length = tvb_get_ntohs(tvb, *offset);
*offset += 2;
break;
case 0x1a:
*offset += 1;
length = tvb_get_ntohl(tvb, *offset);
*offset += 4;
break;
case 0x1b:
*offset += 1;
length = tvb_get_ntoh64(tvb, *offset);
*offset += 8;
break;
case 0x1f:
*offset += 1;
length = INT_MAX;
eof = 1;
break;
default:
if (type_minor <= 0x17) {
length = type_minor;
*offset += 1;
break;
}
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_minor_type,
"invalid minor type %i in map", type_minor);
return NULL;
}
if (eof) {
item = proto_tree_add_string_format_value(cbor_tree, hf_cbor_type_map,
tvb, orig_offset, -1, "Map", "(undefined entries)");
} else {
item = proto_tree_add_string_format_value(cbor_tree, hf_cbor_type_map,
tvb, orig_offset, -1, "Map", "(%"G_GINT64_MODIFIER"u entries)", length);
}
subtree = proto_item_add_subtree(item, ett_cbor_map);
for (i = 0; i < length; i++)
{
if (eof) {
gint value = tvb_get_guint8(tvb, *offset);
if (value == 0xff) {
*offset += 1;
break;
}
}
key = dissect_cbor_main_type(tvb, pinfo, subtree, offset);
if (!key)
return NULL;
key_tree = proto_item_add_subtree(key, ett_cbor_map_entry);
key = dissect_cbor_main_type(tvb, pinfo, key_tree, offset);
if (!key)
return NULL;
}
proto_item_set_end(item, tvb, *offset);
return item;
}
static proto_item *
dissect_cbor_tag(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset, guint8 type_minor)
{
proto_item *item;
proto_item *tagged;
proto_tree *tagged_tree;
switch (type_minor) {
case 0x18:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_tag8, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
break;
case 0x19:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_tag16, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
break;
case 0x1a:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_tag32, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
break;
case 0x1b:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_tag64, tvb, *offset, 8, ENC_BIG_ENDIAN);
*offset += 8;
break;
default:
if (type_minor <= 0x17) {
item = proto_tree_add_item(cbor_tree, hf_cbor_type_tags, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
break;
}
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_minor_type,
"invalid minor type %i in tag", type_minor);
return NULL;
}
tagged_tree = proto_item_add_subtree(item, ett_cbor_tag);
tagged = dissect_cbor_main_type(tvb, pinfo, tagged_tree, offset);
if (!tagged)
return NULL;
return item;
}
static proto_item *decode_half(tvbuff_t *tvb, proto_tree *tree, gint *offset, int hfindex) {
int half, exponent, mantissa;
float val;
proto_item *item;
half = tvb_get_ntohs(tvb, *offset);
exponent = (half >> 10) & 0x1f;
mantissa = half & 0x3ff;
if (exponent == 0) {
val = ldexpf((float)mantissa, -24);
item = proto_tree_add_float(tree, hfindex, tvb, *offset, 2,
half & 0x8000 ? -val : val);
} else if (exponent != 31) {
val = ldexpf((float)(mantissa + 1024), exponent - 25);
item = proto_tree_add_float(tree, hfindex, tvb, *offset, 2,
half & 0x8000 ? -val : val);
} else {
item = proto_tree_add_float_format_value(tree, hfindex, tvb, *offset, 2,
0, "%s", mantissa == 0 ? "INFINITY" : "NAN");
}
*offset += 2;
return item;
}
static proto_item *
dissect_cbor_float_simple_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset, guint8 type_minor)
{
proto_item *item;
switch (type_minor) {
case 0x18:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_simple_data8, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
return item;
case 0x19:
*offset += 1;
item = decode_half(tvb, cbor_tree, offset, hf_cbor_type_float16);
return item;
case 0x1a:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_float32, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
return item;
case 0x1b:
*offset += 1;
item = proto_tree_add_item(cbor_tree, hf_cbor_type_float64, tvb, *offset, 8, ENC_BIG_ENDIAN);
*offset += 8;
return item;
default:
if (type_minor <= 0x17) {
item = proto_tree_add_item(cbor_tree, hf_cbor_type_simple_datas, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
return item;
}
expert_add_info_format(pinfo, cbor_tree, &ei_cbor_invalid_minor_type,
"invalid minor type %i in fimple data and float", type_minor);
return NULL;
}
}
static proto_item *
dissect_cbor_main_type(tvbuff_t *tvb, packet_info *pinfo, proto_tree *cbor_tree, gint *offset)
{
guint8 type;
guint8 type_major;
guint8 type_minor;
type = tvb_get_guint8(tvb, *offset);
type_major = (type & 0xe0) >> 5;
type_minor = (type & 0x1f);
switch (type_major) {
case CBOR_TYPE_USIGNED_INT:
return dissect_cbor_unsigned_integer(tvb, pinfo, cbor_tree, offset, type_minor);
case CBOR_TYPE_NEGATIVE_INT:
return dissect_cbor_negative_integer(tvb, pinfo, cbor_tree, offset, type_minor);
case CBOR_TYPE_BYTE_STRING:
return dissect_cbor_byte_string(tvb, pinfo, cbor_tree, offset, type_minor);
case CBOR_TYPE_TEXT_STRING:
return dissect_cbor_text_string(tvb, pinfo, cbor_tree, offset, type_minor);
case CBOR_TYPE_ARRAY:
return dissect_cbor_array(tvb, pinfo, cbor_tree, offset, type_minor);
case CBOR_TYPE_MAP:
return dissect_cbor_map(tvb, pinfo, cbor_tree, offset, type_minor);
case CBOR_TYPE_TAGGED:
return dissect_cbor_tag(tvb, pinfo, cbor_tree, offset, type_minor);
case CBOR_TYPE_FLOAT:
return dissect_cbor_float_simple_data(tvb, pinfo, cbor_tree, offset, type_minor);
}
DISSECTOR_ASSERT_NOT_REACHED();
return NULL;
}
static void
dissect_cbor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree)
{
gint offset = 0;
proto_item *cbor_root;
proto_tree *cbor_tree;
cbor_root = proto_tree_add_item(parent_tree, proto_cbor, tvb, offset, -1, ENC_NA);
cbor_tree = proto_item_add_subtree(cbor_root, ett_cbor);
dissect_cbor_main_type(tvb, pinfo, cbor_tree, &offset);
}
void
proto_register_cbor(void)
{
static hf_register_info hf[] = {
{ &hf_cbor_type_uints,
{ "Unsigned Integer", "cbor.type.uints",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_cbor_type_uint8,
{ "Unsigned Integer", "cbor.type.uint8",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_uint16,
{ "Unsigned Integer", "cbor.type.uint16",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_uint32,
{ "Unsigned Integer", "cbor.type.uint32",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_uint64,
{ "Unsigned Integer", "cbor.type.uint64",
FT_UINT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_nint,
{ "Negative Integer", "cbor.type.nint",
FT_INT64, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_byte_string,
{ "Byte String", "cbor.type.bytestring",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_byte_string_undef,
{ "Byte String (undefined length)", "cbor.type.bytestring.undef",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cbor_type_text_string,
{ "Text String", "cbor.type.textstring",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_text_string_undef,
{ "Text String (undefined length)", "cbor.type.textstring.undef",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cbor_type_array,
{ "Array", "cbor.type.array",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_map,
{ "Map", "cbor.type.map",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_tags,
{ "Tag", "cbor.type.tags",
FT_UINT8, BASE_DEC, VALS(vals_tags), 0x1f,
NULL, HFILL }
},
{ &hf_cbor_type_tag8,
{ "Tag", "cbor.type.tag8",
FT_UINT8, BASE_DEC, VALS(vals_tags), 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_tag16,
{ "Tag", "cbor.type.tag16",
FT_UINT16, BASE_DEC, VALS(vals_tags), 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_tag32,
{ "Tag", "cbor.type.tag32",
FT_UINT32, BASE_DEC, VALS(vals_tags), 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_tag64,
{ "Tag", "cbor.type.tag64",
FT_UINT64, BASE_DEC|BASE_VAL64_STRING, VALS64(vals64_tags), 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_simple_datas,
{ "Simple data", "cbor.type.simple_datas",
FT_UINT8, BASE_DEC, VALS(vals_simple_data), 0x1f,
NULL, HFILL }
},
{ &hf_cbor_type_simple_data8,
{ "Simple data", "cbor.type.simple_data8",
FT_UINT8, BASE_DEC, VALS(vals_simple_data), 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_float16,
{ "Float 16 Bit", "cbor.type.float16",
FT_FLOAT, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_float32,
{ "Float 32 Bit", "cbor.type.float32",
FT_FLOAT, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_cbor_type_float64,
{ "Float 64 Bit", "cbor.type.float64",
FT_DOUBLE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_cbor,
&ett_cbor_byte_string_undef,
&ett_cbor_text_string_undef,
&ett_cbor_array,
&ett_cbor_map,
&ett_cbor_map_entry,
&ett_cbor_tag,
};
static ei_register_info ei[] = {
{ &ei_cbor_invalid_minor_type,
{ "cbor.invalid_minor_type", PI_MALFORMED, PI_WARN, "Invalid minor type", EXPFILL }},
{ &ei_cbor_invalid_element,
{ "cbor.invalid_element", PI_MALFORMED, PI_WARN, "Invalid element", EXPFILL }},
{ &ei_cbor_too_long_length,
{ "cbor.too_long_length", PI_MALFORMED, PI_WARN, "Too long length", EXPFILL }},
};
expert_module_t *expert_cbor;
proto_cbor = proto_register_protocol("Concise Binary Object Representation", "CBOR", "cbor");
proto_register_field_array(proto_cbor, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cbor = expert_register_protocol(proto_cbor);
expert_register_field_array(expert_cbor, ei, array_length(ei));
register_dissector("cbor", dissect_cbor, proto_cbor);
}
void
proto_reg_handoff_cbor(void)
{
static dissector_handle_t cbor_handle;
cbor_handle = create_dissector_handle(dissect_cbor, proto_cbor);
dissector_add_string("media_type", "application/cbor", cbor_handle);
}
