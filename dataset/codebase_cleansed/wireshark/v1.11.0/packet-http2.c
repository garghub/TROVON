static guint8
dissect_http2_header_flags(tvbuff_t *tvb, packet_info *pinfo, proto_tree *http2_tree, guint offset, guint8 type)
{
proto_item *ti_flags;
proto_tree *flags_tree;
guint8 flags;
ti_flags = proto_tree_add_item(http2_tree, hf_http2_flags, tvb, offset, 1, ENC_NA);
flags_tree = proto_item_add_subtree(ti_flags, ett_http2_flags);
flags = tvb_get_guint8(tvb, offset);
switch(type){
case HTTP2_DATA:
proto_tree_add_item(flags_tree, hf_http2_flags_end_stream, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_reserved1, tvb, offset, 1, ENC_NA);
break;
case HTTP2_HEADERS:
proto_tree_add_item(flags_tree, hf_http2_flags_end_stream, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_end_headers, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_priority, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_reserved3, tvb, offset, 1, ENC_NA);
break;
case HTTP2_PUSH_PROMISE:
if(flags & HTTP2_FLAGS_EPP_OLD)
{
expert_add_info(pinfo, ti_flags, &ei_http2_flags_epp_old );
}
proto_tree_add_item(flags_tree, hf_http2_flags_end_push_promise, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_reserved4, tvb, offset, 1, ENC_NA);
break;
case HTTP2_PING:
proto_tree_add_item(flags_tree, hf_http2_flags_pong, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_reserved1, tvb, offset, 1, ENC_NA);
break;
case HTTP2_CONTINUATION:
proto_tree_add_item(flags_tree, hf_http2_flags_end_stream, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_end_headers, tvb, offset, 1, ENC_NA);
proto_tree_add_item(flags_tree, hf_http2_flags_reserved2, tvb, offset, 1, ENC_NA);
break;
case HTTP2_PRIORITY:
case HTTP2_RST_STREAM:
case HTTP2_SETTINGS:
case HTTP2_GOAWAY:
case HTTP2_WINDOW_UPDATE:
default:
proto_tree_add_item(flags_tree, hf_http2_flags_reserved, tvb, offset, 1, ENC_NA);
break;
}
return flags;
}
static int
dissect_http2_headers(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags)
{
if(flags & HTTP2_FLAGS_PR)
{
proto_tree_add_item(http2_tree, hf_http2_headers_r, tvb, offset, 4, ENC_NA);
proto_tree_add_item(http2_tree, hf_http2_headers_priority, tvb, offset, 4, ENC_NA);
offset += 4;
}
proto_tree_add_item(http2_tree, hf_http2_headers, tvb, offset, -1, ENC_ASCII|ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
dissect_http2_priority(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_priority_r, tvb, offset, 4, ENC_NA);
proto_tree_add_item(http2_tree, hf_http2_priority, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int
dissect_http2_rst_stream(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_rst_stream_error, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int
dissect_http2_settings(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
guint32 settingsid;
proto_item *ti_settings;
proto_tree *settings_tree;
while(tvb_reported_length_remaining(tvb, offset) > 0){
ti_settings = proto_tree_add_item(http2_tree, hf_http2_settings, tvb, offset, 8, ENC_NA);
settings_tree = proto_item_add_subtree(ti_settings, ett_http2_settings);
proto_tree_add_item(settings_tree, hf_http2_settings_r, tvb, offset, 1, ENC_NA);
offset +=1;
proto_tree_add_item(settings_tree, hf_http2_settings_identifier, tvb, offset, 3, ENC_NA);
settingsid = tvb_get_ntoh24(tvb, offset);
proto_item_append_text(ti_settings, " - %s", val_to_str( settingsid, http2_settings_vals, "Unknown (%u)") );
offset +=3;
switch(settingsid){
case HTTP2_SETTINGS_MAX_CONCURRENT_STREAMS:
proto_tree_add_item(settings_tree, hf_http2_settings_max_concurrent_streams, tvb, offset, 4, ENC_NA);
break;
case HTTP2_SETTINGS_INITIAL_WINDOW_SIZE:
proto_tree_add_item(settings_tree, hf_http2_settings_initial_window_size, tvb, offset, 4, ENC_NA);
break;
case HTTP2_SETTINGS_FLOW_CONTROL_OPTIONS:
proto_tree_add_item(settings_tree, hf_http2_settings_flow_control_options, tvb, offset, 4, ENC_NA);
break;
default:
proto_tree_add_item(settings_tree, hf_http2_settings_unknown, tvb, offset, 4, ENC_NA);
break;
}
proto_item_append_text(ti_settings, " : %u", tvb_get_ntohl(tvb, offset));
offset += 4;
}
return offset;
}
static int
dissect_http2_push_promise(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_push_promise_r, tvb, offset, 4, ENC_NA);
proto_tree_add_item(http2_tree, hf_http2_push_promise_promised_stream_id, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(http2_tree, hf_http2_push_promise_header, tvb, offset, -1, ENC_ASCII|ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static int
dissect_http2_ping(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags)
{
if(flags & HTTP2_FLAGS_PO)
{
proto_tree_add_item(http2_tree, hf_http2_pong, tvb, offset, 8, ENC_NA);
}else{
proto_tree_add_item(http2_tree, hf_http2_ping, tvb, offset, 8, ENC_NA);
}
offset += 8;
return offset;
}
static int
dissect_http2_goaway(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_goaway_r, tvb, offset, 4, ENC_NA);
proto_tree_add_item(http2_tree, hf_http2_goaway_last_stream_id, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(http2_tree, hf_http2_goaway_error, tvb, offset, 4, ENC_NA);
offset += 4;
if(tvb_reported_length_remaining(tvb, offset) > 0)
{
proto_tree_add_item(http2_tree, hf_http2_goaway_addata , tvb, offset, -1, ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static int
dissect_http2_window_update(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_window_update_r, tvb, offset, 4, ENC_NA);
proto_tree_add_item(http2_tree, hf_http2_window_update_window_size_increment, tvb, offset, 4, ENC_NA);
offset += 4;
return offset;
}
static int
dissect_http2_continuation(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *http2_tree, guint offset, guint8 flags _U_)
{
proto_tree_add_item(http2_tree, hf_http2_continuation_header, tvb, offset, -1, ENC_ASCII|ENC_NA);
offset += tvb_reported_length_remaining(tvb, offset);
return offset;
}
static void
dissect_http2_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
proto_item *ti;
proto_tree *http2_tree;
tvbuff_t *next_tvb;
guint offset = 0;
guint8 type, flags;
guint16 length;
guint32 streamid;
ti = proto_tree_add_item(tree, hf_http2, tvb, 0, -1, ENC_NA);
http2_tree = proto_item_add_subtree(ti, ett_http2_header);
if (tvb_memeql(tvb, offset, kMagicHello, MAGIC_FRAME_LENGTH) == 0 )
{
col_append_sep_str( pinfo->cinfo, COL_INFO, ", ", "Magic" );
proto_item_set_len(ti, MAGIC_FRAME_LENGTH);
proto_item_append_text(ti, ": Magic");
proto_tree_add_item(http2_tree, hf_http2_magic, tvb, offset, MAGIC_FRAME_LENGTH, ENC_ASCII|ENC_NA);
return;
}
proto_tree_add_item(http2_tree, hf_http2_length, tvb, offset, 2, ENC_NA);
length = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(http2_tree, hf_http2_type, tvb, offset, 1, ENC_NA);
type = tvb_get_guint8(tvb, offset);
col_append_sep_fstr( pinfo->cinfo, COL_INFO, ", ", "%s", val_to_str(type, http2_type_vals, "Unknown type (%d)"));
offset += 1;
flags = dissect_http2_header_flags(tvb, pinfo, http2_tree, offset, type);
offset += 1;
proto_tree_add_item(http2_tree, hf_http2_r, tvb, offset, 4, ENC_NA);
proto_tree_add_item(http2_tree, hf_http2_streamid, tvb, offset, 4, ENC_NA);
streamid = tvb_get_ntohl(tvb, offset) & MASK_HTTP2_STREAMID;
proto_item_append_text(ti, ": %s, Stream ID: %u, Length %u", val_to_str(type, http2_type_vals, "Unknown type (%d)"), streamid, length);
offset += 4;
switch(type){
case HTTP2_DATA:
next_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector(data_handle, next_tvb, pinfo, http2_tree);
break;
case HTTP2_HEADERS:
dissect_http2_headers(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_PRIORITY:
dissect_http2_priority(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_RST_STREAM:
dissect_http2_rst_stream(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_SETTINGS:
dissect_http2_settings(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_PUSH_PROMISE:
dissect_http2_push_promise(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_PING:
dissect_http2_ping(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_GOAWAY:
dissect_http2_goaway(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_WINDOW_UPDATE:
dissect_http2_window_update(tvb, pinfo, http2_tree, offset, flags);
break;
case HTTP2_CONTINUATION:
dissect_http2_continuation(tvb, pinfo, http2_tree, offset, flags);
break;
default:
proto_tree_add_item(http2_tree, hf_http2_unknown, tvb, offset, -1, ENC_NA);
break;
}
return;
}
static guint get_http2_message_len( packet_info *pinfo _U_, tvbuff_t *tvb, int offset )
{
if ( tvb_memeql( tvb, offset, kMagicHello, MAGIC_FRAME_LENGTH ) == 0 ) {
return MAGIC_FRAME_LENGTH;
}
return (guint)tvb_get_ntohs(tvb, offset) + FRAME_HEADER_LENGTH;
}
static int
dissect_http2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti;
proto_tree *http2_tree;
if (tvb_length(tvb) < FRAME_HEADER_LENGTH)
return 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HTTP2");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_http2, tvb, 0, -1, ENC_NA);
proto_item_append_text(ti, " (draft-06)");
http2_tree = proto_item_add_subtree(ti, ett_http2);
tcp_dissect_pdus(tvb, pinfo, http2_tree, TRUE, FRAME_HEADER_LENGTH,
get_http2_message_len, dissect_http2_pdu);
return tvb_length(tvb);
}
void
proto_register_http2(void)
{
static hf_register_info hf[] = {
{ &hf_http2,
{ "Stream", "http2",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_length,
{ "Length", "http2.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The length of the frame payload (The 8 octets of the frame header are not included)", HFILL }
},
{ &hf_http2_type,
{ "Type", "http2.type",
FT_UINT8, BASE_DEC, VALS(http2_type_vals), 0x0,
"The frame type determines how the remainder of the frame header and payload are interpreted", HFILL }
},
{ &hf_http2_r,
{ "Reserved", "http2.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"The semantics of this bit are undefined and the bit MUST remain unset (0) when sending and MUST be ignored when receiving", HFILL }
},
{ &hf_http2_streamid,
{ "Stream Identifier", "http2.streamid",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_STREAMID,
"A 31-bit stream identifier", HFILL }
},
{ &hf_http2_magic,
{ "Magic", "http2.magic",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_unknown,
{ "Unknown", "http2.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_flags,
{ "Flags", "http2.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Flags are assigned semantics specific to the indicated frame type", HFILL }
},
{ &hf_http2_flags_end_stream,
{ "End Stream", "http2.flags.es",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_ES,
"Set indicates that this frame is the last that the endpoint will send for the identified stream", HFILL }
},
{ &hf_http2_flags_end_headers,
{ "End Headers", "http2.flags.eh",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_EH,
"Set indicates that this frame ends the sequence of header block fragments necessary to provide a complete set of headers", HFILL }
},
{ &hf_http2_flags_priority,
{ "Priority", "http2.flags.pr",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_PR,
"Set indicates that the first four octets of this frame contain a single reserved bit and a 31-bit priority", HFILL }
},
{ &hf_http2_flags_end_push_promise,
{ "End Push Promise", "http2.flags.epp",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_EPP,
"Set indicates that this frame ends the sequence of header block fragments necessary to provide a complete set of headers", HFILL }
},
{ &hf_http2_flags_pong,
{ "Pong", "http2.flags.po",
FT_BOOLEAN, 8, NULL, HTTP2_FLAGS_PO,
"Set indicates that this PING frame is a PING response", HFILL }
},
{ &hf_http2_flags_reserved,
{ "Reserved", "http2.flags.r",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_R,
"(Must be zero)", HFILL }
},
{ &hf_http2_flags_reserved1,
{ "Reserved", "http2.flags.r1",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_R1,
"(Must be zero)", HFILL }
},
{ &hf_http2_flags_reserved2,
{ "Reserved", "http2.flags.r2",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_R2,
"(Must be zero)", HFILL }
},
{ &hf_http2_flags_reserved3,
{ "Reserved", "http2.flags.r3",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_R3,
"(Must be zero)", HFILL }
},
{ &hf_http2_flags_reserved4,
{ "Reserved", "http2.flags.r4",
FT_UINT8, BASE_HEX, NULL, HTTP2_FLAGS_R4,
"(Must be zero)", HFILL }
},
{ &hf_http2_headers_r,
{ "Reserved", "http2.headers.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"Must be zero", HFILL }
},
{ &hf_http2_headers_priority,
{ "Priority", "http2.headers.priority",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_PRIORITY,
"Priority for the stream (0 is the highest priority)", HFILL }
},
{ &hf_http2_headers,
{ "Headers", "http2.headers",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_priority_r,
{ "Reserved", "http2.priority.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"Must be zero", HFILL }
},
{ &hf_http2_priority,
{ "Priority", "http2.priority",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_PRIORITY,
"Priority for the stream (0 is the highest priority)", HFILL }
},
{ &hf_http2_rst_stream_error,
{ "Error", "http2.rst_stream.error",
FT_UINT32, BASE_DEC, VALS(http2_error_codes_vals), 0x0,
"The error code indicates why the stream is being terminated", HFILL }
},
{ &hf_http2_settings,
{ "Settings", "http2.settings",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_settings_r,
{ "Reserved", "http2.settings.r",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Must be zero", HFILL }
},
{ &hf_http2_settings_identifier,
{ "Settings Identifier", "http2.settings.id",
FT_UINT24, BASE_DEC, VALS(http2_settings_vals), 0x0,
NULL, HFILL }
},
{ &hf_http2_settings_max_concurrent_streams,
{ "Max concurrent streams", "http2.settings.max_concurrent_streams",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the maximum number of concurrent streams that the sender will allow", HFILL }
},
{ &hf_http2_settings_initial_window_size,
{ "Initial Windows Size", "http2.settings.initial_window_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the sender's initial window size (in bytes) for stream level flow control", HFILL }
},
{ &hf_http2_settings_flow_control_options,
{ "Flow Control Options", "http2.settings.flow_control_options",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates flow control options", HFILL }
},
{ &hf_http2_settings_unknown,
{ "Unknown Settings", "http2.settings.unknown",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_push_promise_r,
{ "Reserved", "http2.push_promise.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"Must be zero", HFILL }
},
{ &hf_http2_push_promise_promised_stream_id,
{ "Promised-Stream-ID", "http2.push_promise.promised_stream_id",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_PRIORITY,
"Identifies the stream the endpoint intends to start sending frames for", HFILL }
},
{ &hf_http2_push_promise_header,
{ "Header", "http2.push_promise.header",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_ping,
{ "Ping", "http2.ping",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_pong,
{ "Pong", "http2.pong",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_goaway_r,
{ "Reserved", "http2.goway.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"Must be zero", HFILL }
},
{ &hf_http2_goaway_last_stream_id,
{ "Promised-Stream-ID", "http2.goaway.last_stream_id",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_PRIORITY,
"Contains the highest numbered stream identifier for which the sender of the GOAWAY frame has received frames on and might have taken some action on", HFILL }
},
{ &hf_http2_goaway_error,
{ "Error", "http2.goaway.error",
FT_UINT32, BASE_DEC, VALS(http2_error_codes_vals), 0x0,
"The error code indicates the reason for closing the connection", HFILL }
},
{ &hf_http2_goaway_addata,
{ "Additional Debug Data", "http2.goaway.addata",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_http2_window_update_r,
{ "Reserved", "http2.window_update.r",
FT_UINT32, BASE_HEX, NULL, MASK_HTTP2_RESERVED,
"Must be zero", HFILL }
},
{ &hf_http2_window_update_window_size_increment,
{ "Window Size Increment", "http2.window_update.window_size_increment",
FT_UINT32, BASE_DEC, NULL, MASK_HTTP2_PRIORITY,
"Indicating the number of bytes that the sender can transmit in addition to the existing flow control window", HFILL }
},
{ &hf_http2_continuation_header,
{ "Continuation Header", "http2.continuation.header",
FT_STRING, BASE_NONE, NULL, 0x0,
"Contains a header block fragment", HFILL }
},
};
static ei_register_info ei[] = {
{ &ei_http2_flags_epp_old, { "http2.flags.epp_old", PI_PROTOCOL, PI_WARN, "Deprecated End Push Promise flags (Now need to use 0x04)", EXPFILL }},
};
static gint *ett[] = {
&ett_http2,
&ett_http2_header,
&ett_http2_flags,
&ett_http2_settings
};
expert_module_t* expert_http2;
proto_http2 = proto_register_protocol("HyperText Transfer Protocol 2", "HTTP2", "http2");
proto_register_field_array(proto_http2, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_http2 = expert_register_protocol(proto_http2);
expert_register_field_array(expert_http2, ei, array_length(ei));
new_register_dissector("http2", dissect_http2, proto_http2);
}
void
proto_reg_handoff_http2(void)
{
data_handle = find_dissector("data");
}
