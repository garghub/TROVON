static guint64 decode_utf8(guint64 utf8)
{
static guint64 unicode;
if (utf8 <= G_GUINT64_CONSTANT(0xFF))
{
unicode =
utf8 & G_GUINT64_CONSTANT(0x7F);
}
else if (utf8 <= G_GUINT64_CONSTANT(0xFFFF))
{
unicode =
((utf8 & G_GUINT64_CONSTANT(0x1F00) >> 2) +
(utf8 & G_GUINT64_CONSTANT(0x3F)));
}
else if (utf8 <= G_GUINT64_CONSTANT(0xFFFFFF))
{
unicode =
((utf8 & G_GUINT64_CONSTANT(0x0F0000)) >> 4) +
((utf8 & G_GUINT64_CONSTANT(0x3F00)) >> 2) +
(utf8 & G_GUINT64_CONSTANT(0x3F));
}
else if (utf8 <= G_GUINT64_CONSTANT(0xFFFFFFFF))
{
unicode =
((utf8 & G_GUINT64_CONSTANT(0x07000000)) >> 6) +
((utf8 & G_GUINT64_CONSTANT(0x3F0000)) >> 4) +
((utf8 & G_GUINT64_CONSTANT(0x3F00)) >> 2) +
(utf8 & G_GUINT64_CONSTANT(0x3F));
}
else if (utf8 <= G_GUINT64_CONSTANT(0xFFFFFFFFFF))
{
unicode =
((utf8 & G_GUINT64_CONSTANT(0x0300000000)) >> 8) +
((utf8 & G_GUINT64_CONSTANT(0x3F000000)) >> 6) +
((utf8 & G_GUINT64_CONSTANT(0x3F0000)) >> 4) +
((utf8 & G_GUINT64_CONSTANT(0x3F00)) >> 2) +
(utf8 & G_GUINT64_CONSTANT(0x3F));
}
else if (utf8 <= G_GUINT64_CONSTANT(0xFFFFFFFFFFFF))
{
unicode =
((utf8 & G_GUINT64_CONSTANT(0x010000000000)) >> 10) +
((utf8 & G_GUINT64_CONSTANT(0x3F00000000)) >> 8) +
((utf8 & G_GUINT64_CONSTANT(0x3F000000)) >> 6) +
((utf8 & G_GUINT64_CONSTANT(0x3F0000)) >> 4) +
((utf8 & G_GUINT64_CONSTANT(0x3F00)) >> 2) +
(utf8 & G_GUINT64_CONSTANT(0x3F));
}
else
{
unicode = G_GUINT64_CONSTANT(0);
}
return unicode;
}
static char *decode_key_name(int unicode)
{
char *key_name;
key_name = ep_alloc(10);
if ((unicode <= 0x20)
|| (unicode == 0x7F)
|| (unicode == 0xE0)
|| (unicode == 0xE7)
|| (unicode == 0xE8)
|| (unicode == 0xE9)
|| (unicode == 0xF9))
{
g_snprintf(key_name, 10, "%s", val_to_str_ext_const(unicode, &str_key_name_ext, "Unknown"));
}
else if (unicode <= 0xFF)
{
g_snprintf(key_name, 10, "%c", unicode);
}
else
{
g_snprintf(key_name, 10, "%s", val_to_str_ext_const(unicode, &str_key_name_ext, "Unknown"));
}
return key_name;
}
static void decode_evt_error(proto_tree *tree,
tvbuff_t *tvb,
guint offset,
guint length)
{
guint8 method, class, property;
guint16 errcode;
guint32 Pdata;
if (!tree)
return;
errcode = tvb_get_ntohs (tvb, offset);
proto_tree_add_uint_format_value(tree, hf_noe_errcode, tvb, offset, 2,
errcode, "%s (%d)", val_to_str_ext_const(errcode, &errcode_vals_ext, "Unknown"), errcode);
offset += 2;
length -= 2;
method = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree, hf_noe_method, tvb, offset, 1,
method, "%s (%d)", val_to_str_const(method, methods_vals, "Unknown"), method);
offset += 1;
length -= 1;
class = tvb_get_guint8(tvb, offset);
proto_tree_add_int_format_value(tree, hf_noe_class, tvb, offset, 1,
class, "%s (%d)", val_to_str_ext_const(class, &val_str_class_ext, "Unknown"), class);
offset += 1;
length -= 1;
proto_tree_add_uint(tree, hf_noe_objectid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
property = tvb_get_guint8(tvb, offset);
proto_tree_add_int_format_value(tree, hf_noe_pcode, tvb, offset, 1,
property, "%s (0x%02x)", val_to_str_ext_const(property, &val_str_props_ext, "Unknown"), property);
offset += 1;
length -= 1;
proto_tree_add_item(tree, hf_noe_aindx, tvb, offset, 1, ENC_NA);
offset += 1;
length -= 1;
proto_tree_add_uint(tree, hf_noe_length, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
Pdata = tvb_get_ntohl (tvb, offset);
proto_tree_add_text(tree,
tvb,
offset,
4,
"Value: %x",
Pdata);
offset += 4;
length -= 4;
proto_tree_add_text(tree,
tvb,
offset,
length,
"Message: %s",
tvb_bytes_to_str(tvb, offset, length));
}
static void decode_tlv(proto_tree *tree,
tvbuff_t *tvb,
guint offset,
guint length)
{
proto_item *property_item, *value_item;
proto_tree *property_tree, *value_tree;
guint8 property_type;
guint16 property_length, property_value_index;
property_item = proto_tree_add_text(tree,
tvb,
offset,
length,
"NOE Message Body");
property_tree = proto_item_add_subtree(property_item, ett_body);
while(length > 0)
{
property_type = tvb_get_guint8(tvb, offset);
proto_tree_add_int_format_value(property_tree, hf_noe_pcode, tvb, offset, 1,
property_type, "%s (0x%02x)", val_to_str_ext_const(property_type, &val_str_props_ext, "Unknown"), property_type);
offset += 1;
length -= 1;
if (property_type >= P_ARRAY)
{
proto_tree_add_item(property_item, hf_noe_aindx, tvb, offset, 1, ENC_NA);
offset += 1;
length -= 1;
}
property_length = tvb_get_guint8(tvb, offset);
if (property_length & 0x80)
{
property_length = tvb_get_ntohs(tvb, offset);
property_length &= 0x7fff;
proto_tree_add_uint(property_tree, hf_noe_psize, tvb, offset, 2,
tvb_get_guint8(tvb, offset) * 256 + tvb_get_guint8(tvb, offset+1));
offset += 2;
length -= 2;
}
else
{
proto_tree_add_uint(property_tree, hf_noe_psize, tvb, offset, 1,
tvb_get_guint8(tvb, offset));
offset += 1;
length -= 1;
}
switch(property_length)
{
case 0:
{
break;
}
case 1:
{
proto_tree_add_text(property_item,
tvb,
offset,
1,
"Value: %d",
tvb_get_guint8(tvb, offset));
offset += 1;
length -= 1;
break;
}
case 2:
{
guint16 property_value;
property_value = tvb_get_ntohs(tvb, offset);
proto_tree_add_text(property_item,
tvb,
offset,
2,
"Value: %d",
property_value);
offset += 2;
length -= 2;
break;
}
case 3:
{
guint32 property_value;
property_value = tvb_get_ntoh24(tvb, offset);
proto_tree_add_text(property_item,
tvb,
offset,
3,
"Value: %u",
property_value);
offset += 3;
length -= 3;
break;
}
case 4:
{
guint32 property_value;
property_value = tvb_get_ntohl(tvb, offset);
proto_tree_add_text(property_item,
tvb,
offset,
4,
"Value: %u",
property_value);
offset += 4;
length -= 4;
break;
}
default:
{
value_item = proto_tree_add_text(property_item,
tvb,
offset,
property_length,
"Value (> 4 bytes)");
value_tree = proto_item_add_subtree(value_item, ett_value);
property_value_index = 0;
while(property_length > 0)
{
property_value_index += 1;
proto_tree_add_text(value_tree,
tvb,
offset,
1,
"Value %5d: 0x%02x",
property_value_index, tvb_get_guint8(tvb, offset));
offset += 1;
length -= 1;
property_length -= 1;
}
break;
}
}
}
}
static void decode_getproperty_tlv(proto_tree *tree,
tvbuff_t *tvb,
guint offset,
guint length)
{
proto_item *body_item;
proto_tree *body_tree;
guint8 body_type;
body_item = proto_tree_add_text(tree,
tvb,
offset,
length,
"NOE Message Body");
body_tree = proto_item_add_subtree(body_item, ett_property);
while(length > 0)
{
body_type = tvb_get_guint8(tvb, offset);
proto_tree_add_int_format_value(body_tree, hf_noe_pcode, tvb, offset, 1,
body_type, "%s (0x%02x)", val_to_str_ext_const(body_type, &val_str_props_ext, "Unknown"), body_type);
offset += 1;
length -= 1;
if (body_type >= P_ARRAY)
{
proto_tree_add_item(body_item, hf_noe_aindx, tvb, offset, 1, ENC_NA);
offset += 1;
length -= 1;
}
}
}
static void decode_evt(proto_tree *tree,
tvbuff_t *tvb,
packet_info *pinfo,
guint offset,
guint length)
{
guint8 event = tvb_get_guint8(tvb, offset);
proto_tree_add_uint_format_value(tree,
hf_noe_event,
tvb,
offset,
1,
event,
"%s (%d)",
val_to_str_ext_const(event, &val_str_event_ext, "Unknown"),
event);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext_const(event, &val_str_event_ext, "Unknown"));
proto_item_append_text(tree, ", %s",
val_to_str_ext_const(event, &val_str_event_ext, "Unknown"));
offset += 1;
length -= 1;
switch(event)
{
case OPCODE_EVT_BT_KEY_SHORTPRESS:
case OPCODE_EVT_BT_KEY_LONGPRESS:
case OPCODE_EVT_BT_KEY_VERYLONGPRESS:
case OPCODE_EVT_KEY_LINE:
case OPCODE_EVT_ONHOOK:
case OPCODE_EVT_OFFHOOK:
{
static const value_string str_struct[] = {
{0x00, "RJ9 Plug"},
{0x01, "BT Handset Link"},
{0, NULL}
};
proto_tree_add_text(tree,
tvb,
offset,
length,
"Value: %s (%d)",
val_to_str_const(tvb_get_guint8(tvb, offset), str_struct, "Unknown"), tvb_get_guint8(tvb, offset));
break;
}
case OPCODE_EVT_KEY_PRESS:
case OPCODE_EVT_KEY_RELEASE:
case OPCODE_EVT_KEY_SHORTPRESS:
case OPCODE_EVT_KEY_LONGPRESS:
case OPCODE_EVT_HELP:
{
guint64 utf8_value = 0;
guint64 unicode_value;
char *key_name;
int pt_length = length;
int pt_offset = offset;
while(pt_length > 0)
{
utf8_value = (utf8_value << 8) + tvb_get_guint8(tvb, pt_offset);
pt_offset += 1;
pt_length -= 1;
}
unicode_value = decode_utf8(utf8_value);
key_name = ep_alloc(30);
g_snprintf(key_name, 30, "\"%s\"", decode_key_name((int)unicode_value));
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
key_name);
proto_item_append_text(tree, ", %s",
key_name);
proto_tree_add_text(tree,
tvb,
offset,
length,
"Key Name: %s (UTF-8 Value: %s, Unicode Value: 0x%" G_GINT64_MODIFIER "x)",
key_name,
tvb_bytes_to_str(tvb, offset, length),
unicode_value);
break;
}
case OPCODE_EVT_ERROR_PROTOCOL:
case OPCODE_EVT_ERROR_CREATE:
case OPCODE_EVT_ERROR_DELETE:
case OPCODE_EVT_ERROR_SET_PROPERTY:
case OPCODE_EVT_ERROR_GET_PROPERTY:
{
decode_evt_error(tree, tvb, offset, length);
break;
}
case OPCODE_EVT_CONTEXT_SWITCH:
{
proto_tree_add_text(tree,
tvb,
offset,
1,
"Context: %s",
val_to_str_const(tvb_get_guint8(tvb, offset),
servers_vals,
"Unknown"));
break;
}
case OPCODE_EVT_SUCCESS_CREATE:
case OPCODE_EVT_SUCCESS_DELETE:
case OPCODE_EVT_SUCCESS_SET_PROPERTY:
case OPCODE_EVT_SUCCESS_INSERT_ITEM:
case OPCODE_EVT_SUCCESS_DELETE_ITEM:
{
proto_tree_add_uint(tree, hf_noe_objectid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
break;
}
case OPCODE_EVT_WIDGETS_GC:
{
proto_tree_add_text(tree,
tvb,
offset,
4,
"FreeMem: %d bytes",
tvb_get_ntohl(tvb, offset));
break;
}
case OPCODE_EVT_BT_BONDING_RESULT:
{
proto_tree_add_uint(tree, hf_noe_objectid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
offset += 2;
proto_tree_add_text(tree,
tvb,
offset,
1,
"Bonded: %d",
tvb_get_ntohs(tvb, offset));
offset += 1;
proto_tree_add_text(tree,
tvb,
offset,
1,
"Value: %d",
tvb_get_ntohs(tvb, offset));
break;
}
default:
{
proto_tree_add_uint(tree, hf_noe_objectid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
if (length > 0)
decode_tlv(tree, tvb, offset, length);
break;
}
}
}
static void decode_mtd(proto_tree *tree,
tvbuff_t *tvb,
packet_info *pinfo,
guint8 method,
guint offset,
guint length)
{
guint8 class = tvb_get_guint8(tvb, offset);
proto_tree_add_int_format_value(tree,
hf_noe_class,
tvb,
offset,
1,
class,
"%s (%d)",
val_to_str_ext_const(class, &val_str_class_ext, "Unknown"),
class);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext_const(class, &val_str_class_ext, "Unknown"));
proto_item_append_text(tree, ", %s",
val_to_str_ext_const(class, &val_str_class_ext, "Unknown"));
offset += 1;
length -= 1;
if (class >= C_DYNAMIC)
{
proto_tree_add_uint(tree, hf_noe_objectid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
offset += 2;
length -= 2;
}
switch(method)
{
case METHOD_INSERT_ITEM:
{
proto_tree_add_uint(tree,
hf_noe_method_index,
tvb,
offset,
1,
tvb_get_guint8(tvb, offset));
offset += 1;
length -= 1;
if (length > 0)
decode_tlv(tree, tvb, offset, length);
break;
}
case METHOD_DELETE_ITEM:
{
proto_tree_add_uint(tree,
hf_noe_method_index,
tvb,
offset,
1,
tvb_get_guint8(tvb, offset));
break;
}
case METHOD_GET_PROPERTY:
{
decode_getproperty_tlv(tree, tvb, offset, length);
break;
}
default:
{
if (length > 0)
decode_tlv(tree, tvb, offset, length);
break;
}
}
}
static void dissect_noe(tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree)
{
proto_item *noe_item;
proto_tree *noe_tree;
gint length;
guint8 server;
guint8 method;
gboolean methodack;
gint offset = 0;
noe_item = proto_tree_add_item(tree, proto_noe, tvb, 0, -1, ENC_NA);
noe_tree = proto_item_add_subtree(noe_item, ett_noe);
length = tvb_get_letohs(tvb, offset);
proto_tree_add_uint(noe_tree,
hf_noe_length,
tvb,
offset,
2,
length);
offset += 2;
server = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " - NOE Protocol (%s)",
val_to_str_const(server, servers_short_vals, "Unknown"));
proto_tree_add_uint(noe_tree,
hf_noe_server,
tvb,
offset,
1,
server);
offset += 1;
length -= 1;;
proto_item_append_text(noe_item, ", %s",
val_to_str_const(server, servers_short_vals, "Unknown"));
method = tvb_get_guint8(tvb, offset);
methodack = (method & 0x80) != 0;
method = (method & 0x7f);
proto_tree_add_uint_format_value(noe_tree,
hf_noe_method,
tvb,
offset,
1,
method,
"%s (%d)",
val_to_str_const(method, methods_vals, "Unknown"),
method);
if (method >= METHOD_INVALID)
return;
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s",
val_to_str_const(method, methods_vals, "Unknown"));
proto_item_append_text(noe_item, ", %s",
val_to_str_const(method, methods_vals, "Unknown"));
if (method == METHOD_NOTIFY)
{
offset += 1;
length -= 1;
decode_evt(noe_tree, tvb, pinfo, offset, length);
}
else
{
proto_tree_add_boolean(noe_tree,
hf_noe_method_ack,
tvb,
offset,
1,
methodack);
offset += 1;
length -= 1;
decode_mtd(noe_tree, tvb, pinfo, method, offset, length);
}
}
void proto_register_noe(void)
{
static hf_register_info hf_noe[] =
{
{ &hf_noe_length,
{
"Length",
"noe.length",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"Method Length",
HFILL
}
},
{ &hf_noe_server,
{
"Server",
"noe.server",
FT_UINT8,
BASE_HEX,
VALS(servers_vals),
0x0,
"Method Opcode",
HFILL
}
},
{ &hf_noe_method_ack,
{
"Ack",
"noe.method_ack",
FT_BOOLEAN,
BASE_NONE,
NULL,
0x0,
"Method Acknowledge",
HFILL
}
},
{ &hf_noe_method,
{
"Method",
"noe.method",
FT_UINT8,
BASE_DEC,
VALS(methods_vals),
0x0,
"Method Opcode",
HFILL
}
},
{ &hf_noe_class,
{
"Class",
"noe.class",
FT_INT8,
BASE_DEC,
NULL,
0x0,
"Class Opcode",
HFILL
}
},
{ &hf_noe_event,
{
"Event",
"noe.event",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Event Opcode",
HFILL
}
},
{ &hf_noe_objectid,
{
"Objectid",
"noe.objectid",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
"Object Identifier",
HFILL
}
},
{ &hf_noe_method_index,
{
"ItemIndx",
"noe.item_index",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Delete/Insert Index",
HFILL
}
},
{ &hf_noe_pcode,
{
"Property",
"noe.property",
FT_INT8,
BASE_DEC,
NULL,
0x0,
"Property Identifier",
HFILL
}
},
{ &hf_noe_psize,
{
"PropLength",
"noe.prop_len",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"Property Length",
HFILL
}
},
{ &hf_noe_errcode,
{
"ErrCode",
"noe.errcode",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"Error Code",
HFILL
}
},
{ &hf_noe_aindx,
{
"ArrIndex",
"noe.array_index",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Array Index",
HFILL
}
}
};
static gint *ett[] =
{
&ett_noe,
&ett_body,
&ett_property,
&ett_value,
};
proto_noe = proto_register_protocol("NOE Protocol", "NOE", "noe");
proto_register_field_array(proto_noe, hf_noe, array_length(hf_noe));
register_dissector("noe", dissect_noe, proto_noe);
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_noe(void)
{
#if 0
dissector_handle_t handle_noe = find_dissector("noe");
dissector_add_uint("ua.opcode", 0x15, handle_noe);
#endif
}
