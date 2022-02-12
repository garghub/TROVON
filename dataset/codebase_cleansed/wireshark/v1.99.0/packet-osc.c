static gboolean
is_valid_path(const char *path)
{
const char *ptr;
if(path[0] != '/')
return FALSE;
for(ptr=path+1; *ptr!='\0'; ptr++)
if( (g_ascii_isprint(*ptr) == 0) || (strchr(invalid_path_chars, *ptr) != NULL) )
return FALSE;
return TRUE;
}
static gboolean
is_valid_format(const char *format)
{
const char *ptr;
if(format[0] != ',')
return FALSE;
for(ptr=format+1; *ptr!='\0'; ptr++)
if(strchr(valid_format_chars, *ptr) == NULL)
return FALSE;
return TRUE;
}
static int
dissect_osc_message(tvbuff_t *tvb, proto_item *ti, proto_tree *osc_tree, gint offset, gint len)
{
proto_tree *message_tree;
proto_tree *header_tree;
gint slen;
gint rem;
gint end = offset + len;
const gchar *path;
gint path_len;
gint path_offset;
const gchar *format;
gint format_offset;
gint format_len;
const gchar *ptr;
path_offset = offset;
path = tvb_get_const_stringz(tvb, path_offset, &path_len);
if( (rem = path_len%4) ) path_len += 4-rem;
if(!is_valid_path(path))
return -1;
format_offset = path_offset + path_len;
format = tvb_get_const_stringz(tvb, format_offset, &format_len);
if( (rem = format_len%4) ) format_len += 4-rem;
if(!is_valid_format(format))
return -1;
ti = proto_tree_add_none_format(osc_tree, hf_osc_message_type, tvb, offset, len, "Message: %s %s", path, format);
message_tree = proto_item_add_subtree(ti, ett_osc_message);
ti = proto_tree_add_item(message_tree, hf_osc_message_header_type, tvb, offset, path_len+format_len, ENC_NA);
header_tree = proto_item_add_subtree(ti, ett_osc_message_header);
proto_tree_add_item(header_tree, hf_osc_message_path_type, tvb, path_offset, path_len, ENC_ASCII | ENC_NA);
proto_tree_add_item(header_tree, hf_osc_message_format_type, tvb, format_offset, format_len, ENC_ASCII | ENC_NA);
offset += path_len + format_len;
ptr = format + 1;
while( (*ptr != '\0') && (offset < end) )
{
switch(*ptr)
{
case OSC_INT32:
proto_tree_add_item(message_tree, hf_osc_message_int32_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case OSC_FLOAT:
proto_tree_add_item(message_tree, hf_osc_message_float_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
break;
case OSC_STRING:
slen = tvb_strsize(tvb, offset);
if( (rem = slen%4) ) slen += 4-rem;
proto_tree_add_item(message_tree, hf_osc_message_string_type, tvb, offset, slen, ENC_ASCII | ENC_NA);
offset += slen;
break;
case OSC_BLOB:
{
proto_item *bi;
proto_tree *blob_tree;
gint32 blen = tvb_get_ntohl(tvb, offset);
slen = blen;
if( (rem = slen%4) ) slen += 4-rem;
bi = proto_tree_add_none_format(message_tree, hf_osc_message_blob_type, tvb, offset, 4+slen, "Blob: %i bytes", blen);
blob_tree = proto_item_add_subtree(bi, ett_osc_blob);
proto_tree_add_int_format_value(blob_tree, hf_osc_message_blob_size_type, tvb, offset, 4, blen, "%i bytes", blen);
offset += 4;
if(blen == 0)
break;
proto_tree_add_item(blob_tree, hf_osc_message_blob_data_type, tvb, offset, slen, ENC_NA);
offset += slen;
break;
}
case OSC_TRUE:
proto_tree_add_item(message_tree, hf_osc_message_true_type, tvb, offset, 0, ENC_NA);
break;
case OSC_FALSE:
proto_tree_add_item(message_tree, hf_osc_message_false_type, tvb, offset, 0, ENC_NA);
break;
case OSC_NIL:
proto_tree_add_item(message_tree, hf_osc_message_nil_type, tvb, offset, 0, ENC_NA);
break;
case OSC_BANG:
proto_tree_add_item(message_tree, hf_osc_message_bang_type, tvb, offset, 0, ENC_NA);
break;
case OSC_INT64:
proto_tree_add_item(message_tree, hf_osc_message_int64_type, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
break;
case OSC_DOUBLE:
proto_tree_add_item(message_tree, hf_osc_message_double_type, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
break;
case OSC_TIMETAG:
{
guint32 sec = tvb_get_ntohl(tvb, offset);
guint32 frac = tvb_get_ntohl(tvb, offset+4);
nstime_t ns;
if( (sec == 0) && (frac == 1) )
proto_tree_add_time_format_value(message_tree, hf_osc_message_timetag_type, tvb, offset, 8, &ns, immediate_fmt, immediate_str);
else
proto_tree_add_item(message_tree, hf_osc_message_timetag_type, tvb, offset, 8, ENC_TIME_NTP | ENC_BIG_ENDIAN);
offset += 8;
}
break;
case OSC_SYMBOL:
slen = tvb_strsize(tvb, offset);
if( (rem = slen%4) ) slen += 4-rem;
proto_tree_add_item(message_tree, hf_osc_message_symbol_type, tvb, offset, slen, ENC_ASCII | ENC_NA);
offset += slen;
break;
case OSC_CHAR:
offset += 3;
proto_tree_add_item(message_tree, hf_osc_message_char_type, tvb, offset, 1, ENC_ASCII | ENC_NA);
offset += 1;
break;
case OSC_RGBA:
{
proto_item *ri;
proto_tree *rgba_tree;
ri = proto_tree_add_item(message_tree, hf_osc_message_rgba_type, tvb, offset, 4, ENC_BIG_ENDIAN);
rgba_tree = proto_item_add_subtree(ri, ett_osc_rgba);
proto_tree_add_item(rgba_tree, hf_osc_message_rgba_red_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rgba_tree, hf_osc_message_rgba_green_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rgba_tree, hf_osc_message_rgba_blue_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(rgba_tree, hf_osc_message_rgba_alpha_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
break;
}
case OSC_MIDI:
{
const gchar *status_str;
proto_item *mi = NULL;
proto_tree *midi_tree;
guint8 channel;
guint8 status;
guint8 data1;
guint8 data2;
channel = tvb_get_guint8(tvb, offset);
status = tvb_get_guint8(tvb, offset+1);
data1 = tvb_get_guint8(tvb, offset+2);
data2 = tvb_get_guint8(tvb, offset+3);
status_str = val_to_str_ext_const(status, &MIDI_status_ext, "Unknown");
if(status == MIDI_STATUS_CONTROLLER)
{
const gchar *control_str;
control_str = val_to_str_ext_const(data1, &MIDI_control_ext, "Unknown");
mi = proto_tree_add_none_format(message_tree, hf_osc_message_midi_type, tvb, offset, 4,
"MIDI: Channel %2i, %s (0x%02x), %s (0x%02x), 0x%02x",
channel,
status_str, status,
control_str, data1,
data2);
}
else
{
mi = proto_tree_add_none_format(message_tree, hf_osc_message_midi_type, tvb, offset, 4,
"MIDI: Channel %2i, %s (0x%02x), 0x%02x, 0x%02x",
channel,
status_str, status,
data1, data2);
}
midi_tree = proto_item_add_subtree(mi, ett_osc_midi);
proto_tree_add_item(midi_tree, hf_osc_message_midi_channel_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(midi_tree, hf_osc_message_midi_status_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if(status == MIDI_STATUS_CONTROLLER)
{
proto_tree_add_item(midi_tree, hf_osc_message_midi_controller_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(midi_tree, hf_osc_message_midi_value_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
else
{
proto_tree_add_item(midi_tree, hf_osc_message_midi_data1_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(midi_tree, hf_osc_message_midi_data2_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
break;
}
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
ptr++;
}
if(offset != end)
return -1;
else
return 0;
}
static int
dissect_osc_bundle(tvbuff_t *tvb, proto_item *ti, proto_tree *osc_tree, gint offset, gint len)
{
proto_tree *bundle_tree;
gint end = offset + len;
guint32 sec;
guint32 frac;
nstime_t ns;
if(tvb_strneql(tvb, offset, bundle_str, 8) != 0)
return -1;
ti = proto_tree_add_item(osc_tree, hf_osc_bundle_type, tvb, offset, len, ENC_NA);
bundle_tree = proto_item_add_subtree(ti, ett_osc_bundle);
offset += 8;
sec = tvb_get_ntohl(tvb, offset);
frac = tvb_get_ntohl(tvb, offset+4);
if( (sec == 0) && (frac == 1) )
proto_tree_add_time_format_value(bundle_tree, hf_osc_bundle_timetag_type, tvb, offset, 8, &ns, immediate_fmt, immediate_str);
else
proto_tree_add_item(bundle_tree, hf_osc_bundle_timetag_type, tvb, offset, 8, ENC_TIME_NTP | ENC_BIG_ENDIAN);
offset += 8;
while(offset < end)
{
gint32 size = tvb_get_ntohl(tvb, offset);
proto_tree_add_int_format_value(bundle_tree, hf_osc_bundle_element_size_type, tvb, offset, 4, size, "%i bytes", size);
offset += 4;
if(size == 0)
continue;
switch(tvb_get_guint8(tvb, offset))
{
case '#':
if(dissect_osc_bundle(tvb, ti, bundle_tree, offset, size))
return -1;
else
break;
case '/':
if(dissect_osc_message(tvb, ti, bundle_tree, offset, size))
return -1;
else
break;
default:
return -1;
}
if(size > G_MAXINT - offset)
return -1;
else
offset += size;
}
if(offset != end)
return -1;
else
return 0;
}
static void
dissect_osc_pdu_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_, gint offset, gint len)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OSC");
col_clear(pinfo->cinfo, COL_INFO);
if(tree)
{
proto_item *ti;
proto_tree *osc_tree;
ti = proto_tree_add_item(tree, proto_osc, tvb, 0, -1, ENC_NA);
osc_tree = proto_item_add_subtree(ti, ett_osc_packet);
switch(tvb_get_guint8(tvb, offset))
{
case '#':
if(dissect_osc_bundle(tvb, ti, osc_tree, offset, len))
return;
else
break;
case '/':
if(dissect_osc_message(tvb, ti, osc_tree, offset, len))
return;
else
break;
default:
return;
}
}
}
static guint
get_osc_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
return tvb_get_ntohl(tvb, offset) + 4;
}
static int
dissect_osc_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint pdu_len;
pdu_len = tvb_get_ntohl(tvb, 0);
dissect_osc_pdu_common(tvb, pinfo, tree, data, 4, pdu_len);
return pdu_len;
}
static int
dissect_osc_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4, get_osc_pdu_len,
dissect_osc_tcp_pdu, data);
return tvb_reported_length(tvb);
}
static int
dissect_osc_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint pdu_len;
pdu_len = tvb_reported_length(tvb);
dissect_osc_pdu_common(tvb,pinfo, tree, data, 0, pdu_len);
return pdu_len;
}
static gboolean
dissect_osc_heur_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
conversation_t *conversation;
if(tvb_captured_length(tvb) < 8)
return FALSE;
if(tvb_strneql(tvb, 0, bundle_str, 8) != 0)
{
gint offset = 0;
gint slen;
gint rem;
const gchar *str;
volatile gboolean valid = FALSE;
TRY {
str = tvb_get_const_stringz(tvb, offset, &slen);
if(is_valid_path(str)) {
if( (rem = slen%4) ) slen += 4-rem;
offset += slen;
str = tvb_get_const_stringz(tvb, offset, &slen);
if(is_valid_format(str))
valid = TRUE;
}
}
CATCH_ALL {
valid = FALSE;
}
ENDTRY;
if(! valid)
return FALSE;
}
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, osc_udp_handle);
dissect_osc_udp(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_osc(void)
{
static hf_register_info hf[] = {
{ &hf_osc_bundle_type, { "Bundle", "osc.bundle",
FT_NONE, BASE_NONE,
NULL, 0x0,
"Bundle structure", HFILL } },
{ &hf_osc_bundle_timetag_type, { "Timetag", "osc.bundle.timetag",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC,
NULL, 0x0,
"Scheduled bundle execution time", HFILL } },
{ &hf_osc_bundle_element_size_type, { "Size", "osc.bundle.element.size",
FT_INT32, BASE_DEC,
NULL, 0x0,
"Bundle element size", HFILL } },
{ &hf_osc_message_type, { "Message", "osc.message",
FT_NONE, BASE_NONE,
NULL, 0x0,
"Message structure", HFILL } },
{ &hf_osc_message_header_type, { "Header", "osc.message.header",
FT_NONE, BASE_NONE,
NULL, 0x0,
"Message header", HFILL } },
{ &hf_osc_message_path_type, { "Path", "osc.message.header.path",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Message path", HFILL } },
{ &hf_osc_message_format_type, { "Format", "osc.message.header.format",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Message format", HFILL } },
{ &hf_osc_message_int32_type, { "Int32", "osc.message.int32",
FT_INT32, BASE_DEC,
NULL, 0x0,
"32bit integer value", HFILL } },
{ &hf_osc_message_float_type, { "Float", "osc.message.float",
FT_FLOAT, BASE_NONE,
NULL, 0x0,
"Floating point value", HFILL } },
{ &hf_osc_message_string_type, { "String", "osc.message.string",
FT_STRING, BASE_NONE,
NULL, 0x0,
"String value", HFILL } },
{ &hf_osc_message_blob_type, { "Blob", "osc.message.blob",
FT_NONE, BASE_NONE,
NULL, 0x0,
"Binary blob value", HFILL } },
{ &hf_osc_message_blob_size_type, { "Size", "osc.message.blob.size",
FT_INT32, BASE_DEC,
NULL, 0x0,
"Binary blob size", HFILL } },
{ &hf_osc_message_blob_data_type, { "Data", "osc.message.blob.data",
FT_BYTES, BASE_NONE,
NULL, 0x0,
"Binary blob data", HFILL } },
{ &hf_osc_message_true_type, { "True", "osc.message.true",
FT_NONE, BASE_NONE,
NULL, 0x0,
"Boolean true value", HFILL } },
{ &hf_osc_message_false_type, { "False", "osc.message.false",
FT_NONE, BASE_NONE,
NULL, 0x0,
"Boolean false value", HFILL } },
{ &hf_osc_message_nil_type, { "Nil", "osc.message.nil",
FT_NONE, BASE_NONE,
NULL, 0x0,
"Nil value", HFILL } },
{ &hf_osc_message_bang_type, { "Bang", "osc.message.bang",
FT_NONE, BASE_NONE,
NULL, 0x0,
"Infinity, Impulse or Bang value", HFILL } },
{ &hf_osc_message_int64_type, { "Int64", "osc.message.int64",
FT_INT64, BASE_DEC,
NULL, 0x0,
"64bit integer value", HFILL } },
{ &hf_osc_message_double_type, { "Double", "osc.message.double",
FT_DOUBLE, BASE_NONE,
NULL, 0x0,
"Double value", HFILL } },
{ &hf_osc_message_timetag_type, { "Timetag", "osc.message.timetag",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC,
NULL, 0x0,
"NTP time value", HFILL } },
{ &hf_osc_message_symbol_type, { "Symbol", "osc.message.symbol",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Symbol value", HFILL } },
{ &hf_osc_message_char_type, { "Char", "osc.message.char",
FT_STRING, BASE_NONE,
NULL, 0x0,
"Character value", HFILL } },
{ &hf_osc_message_rgba_type, { "RGBA", "osc.message.rgba",
FT_UINT32, BASE_HEX,
NULL, 0x0,
"RGBA color value", HFILL } },
{ &hf_osc_message_rgba_red_type, { "Red", "osc.message.rgba.red",
FT_UINT8, BASE_DEC,
NULL, 0x0,
"Red color component", HFILL } },
{ &hf_osc_message_rgba_green_type, { "Green", "osc.message.rgba.green",
FT_UINT8, BASE_DEC,
NULL, 0x0,
"Green color component", HFILL } },
{ &hf_osc_message_rgba_blue_type, { "Blue", "osc.message.rgba.blue",
FT_UINT8, BASE_DEC,
NULL, 0x0,
"Blue color component", HFILL } },
{ &hf_osc_message_rgba_alpha_type, { "Alpha", "osc.message.rgba.alpha",
FT_UINT8, BASE_DEC,
NULL, 0x0,
"Alpha transparency component", HFILL } },
{ &hf_osc_message_midi_type, { "MIDI", "osc.message.midi",
FT_NONE, BASE_NONE,
NULL, 0x0,
"MIDI value", HFILL } },
{ &hf_osc_message_midi_channel_type, { "Channel", "osc.message.midi.channel",
FT_UINT8, BASE_DEC,
NULL, 0x0,
"MIDI channel", HFILL } },
{ &hf_osc_message_midi_status_type, { "Status", "osc.message.midi.status",
FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&MIDI_status_ext, 0x0,
"MIDI status message", HFILL } },
{ &hf_osc_message_midi_data1_type, { "Data1", "osc.message.midi.data1",
FT_UINT8, BASE_HEX,
NULL, 0x0,
"MIDI data value 1", HFILL } },
{ &hf_osc_message_midi_data2_type, { "Data2", "osc.message.midi.data2",
FT_UINT8, BASE_HEX,
NULL, 0x0,
"MIDI data value 2", HFILL } },
{ &hf_osc_message_midi_controller_type, { "Controller", "osc.message.midi.controller",
FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&MIDI_control_ext, 0x0,
"MIDI controller message", HFILL } },
{ &hf_osc_message_midi_value_type, { "Value", "osc.message.midi.value",
FT_UINT8, BASE_HEX,
NULL, 0x0,
"MIDI controller value", HFILL } }
};
static gint *ett[] = {
&ett_osc_packet,
&ett_osc_bundle,
&ett_osc_message,
&ett_osc_message_header,
&ett_osc_blob,
&ett_osc_rgba,
&ett_osc_midi
};
module_t *osc_module;
proto_osc = proto_register_protocol("Open Sound Control Protocol", "OSC", "osc");
proto_register_field_array(proto_osc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
osc_module = prefs_register_protocol(proto_osc, proto_reg_handoff_osc);
prefs_register_uint_preference(osc_module, "tcp.port",
"OSC TCP Port",
"Set the TCP port for OSC",
10, &global_osc_tcp_port);
}
void
proto_reg_handoff_osc(void)
{
static dissector_handle_t osc_tcp_handle;
static guint osc_tcp_port;
static gboolean initialized = FALSE;
if(! initialized)
{
osc_tcp_handle = new_create_dissector_handle(dissect_osc_tcp, proto_osc);
dissector_add_for_decode_as("tcp.port", osc_tcp_handle);
osc_udp_handle = new_create_dissector_handle(dissect_osc_udp, proto_osc);
heur_dissector_add("udp", dissect_osc_heur_udp, proto_osc);
initialized = TRUE;
}
else
{
if(osc_tcp_port != 0)
dissector_delete_uint("tcp.port", osc_tcp_port, osc_tcp_handle);
}
osc_tcp_port = global_osc_tcp_port;
if(osc_tcp_port != 0)
dissector_add_uint("tcp.port", osc_tcp_port, osc_tcp_handle);
}
