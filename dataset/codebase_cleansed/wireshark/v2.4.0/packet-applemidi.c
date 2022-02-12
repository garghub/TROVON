static void
dissect_applemidi_common( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint16 command ) {
proto_item *ti;
guint16 seq_num;
guint8 count;
guint8 *name;
gint offset = 0;
gint len;
gint string_size;
proto_tree *applemidi_tree;
proto_tree *applemidi_tree_seq_num;
col_set_str( pinfo->cinfo, COL_PROTOCOL, APPLEMIDI_DISSECTOR_SHORTNAME );
col_add_fstr( pinfo->cinfo, COL_INFO, "%s", val_to_str( command, applemidi_commands, applemidi_unknown_command ) );
ti = proto_tree_add_item( tree, proto_applemidi, tvb, 0, -1, ENC_NA );
applemidi_tree = proto_item_add_subtree( ti, ett_applemidi );
proto_tree_add_item( applemidi_tree, hf_applemidi_signature, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
proto_tree_add_item( applemidi_tree, hf_applemidi_command, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
if ( ( APPLEMIDI_COMMAND_INVITATION == command ) ||
( APPLEMIDI_COMMAND_INVITATION_REJECTED == command ) ||
( APLLEMIDI_COMMAND_INVITATION_ACCEPTED == command ) ||
( APPLEMIDI_COMMAND_ENDSESSION == command ) ) {
proto_tree_add_item( applemidi_tree, hf_applemidi_protocol_version, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( applemidi_tree, hf_applemidi_token, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( applemidi_tree, hf_applemidi_ssrc, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
len = tvb_reported_length(tvb) - offset;
if ( len > 0 ) {
name = tvb_get_string_enc( wmem_packet_scope(), tvb, offset, len, ENC_UTF_8|ENC_NA );
string_size = (gint)( strlen( name ) + 1 );
proto_tree_add_item( applemidi_tree, hf_applemidi_name, tvb, offset, string_size, ENC_UTF_8|ENC_NA );
col_append_fstr( pinfo->cinfo, COL_INFO, ": peer = \"%s\"", name );
offset += string_size;
}
} else if ( APPLEMIDI_COMMAND_SYNCHRONIZATION == command ) {
proto_tree_add_item( applemidi_tree, hf_applemidi_ssrc, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
count = tvb_get_guint8( tvb, offset );
proto_tree_add_item( applemidi_tree, hf_applemidi_count, tvb, offset, 1, ENC_BIG_ENDIAN );
col_append_fstr( pinfo->cinfo, COL_INFO, ": count = %u", count );
offset += 1;
proto_tree_add_item( applemidi_tree, hf_applemidi_padding, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
proto_tree_add_item( applemidi_tree, hf_applemidi_timestamp1, tvb, offset, 8, ENC_BIG_ENDIAN );
offset += 8;
proto_tree_add_item( applemidi_tree, hf_applemidi_timestamp2, tvb, offset, 8, ENC_BIG_ENDIAN );
offset += 8;
proto_tree_add_item( applemidi_tree, hf_applemidi_timestamp3, tvb, offset, 8, ENC_BIG_ENDIAN );
offset += 8;
} else if ( APPLEMIDI_COMMAND_RECEIVER_FEEDBACK == command ) {
proto_tree_add_item( applemidi_tree, hf_applemidi_ssrc, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
ti = proto_tree_add_item( applemidi_tree, hf_applemidi_sequence_num, tvb, offset, 4, ENC_BIG_ENDIAN );
applemidi_tree_seq_num = proto_item_add_subtree( ti, ett_applemidi_seq_num );
seq_num = tvb_get_ntohs( tvb, offset );
proto_tree_add_uint( applemidi_tree_seq_num, hf_applemidi_rtp_sequence_num, tvb, offset, 2, seq_num );
offset += 4;
col_append_fstr( pinfo->cinfo, COL_INFO, ": seq = %u", seq_num );
} else if ( APPLEMIDI_COMMAND_BITRATE_RECEIVE_LIMIT == command ) {
proto_tree_add_item( applemidi_tree, hf_applemidi_ssrc, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
proto_tree_add_item( applemidi_tree, hf_applemidi_rtp_bitrate_limit,
tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
}
len = tvb_reported_length_remaining( tvb, offset );
if ( len > 0 ) {
proto_tree_add_item( applemidi_tree, hf_applemidi_unknown_data, tvb, offset, len, ENC_NA );
}
}
static gboolean
test_applemidi(tvbuff_t *tvb, guint16 *command_p, gboolean conversation_established ) {
*command_p = 0xffff;
if ( APPLEMIDI_PROTOCOL_SIGNATURE != tvb_get_ntohs( tvb, 0 ) )
return FALSE;
*command_p = tvb_get_ntohs( tvb, 2 );
if ( conversation_established ) {
return TRUE;
}
if ( ( APPLEMIDI_COMMAND_INVITATION == *command_p ) ||
( APPLEMIDI_COMMAND_INVITATION_REJECTED == *command_p ) ||
( APLLEMIDI_COMMAND_INVITATION_ACCEPTED == *command_p ) ||
( APPLEMIDI_COMMAND_ENDSESSION == *command_p ) ||
( APPLEMIDI_COMMAND_SYNCHRONIZATION == *command_p ) ||
( APPLEMIDI_COMMAND_RECEIVER_FEEDBACK == *command_p ) ||
( APPLEMIDI_COMMAND_BITRATE_RECEIVE_LIMIT == *command_p ) )
return TRUE;
return FALSE;
}
static int
dissect_applemidi( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_ ) {
guint16 command;
if ( test_applemidi( tvb, &command, TRUE ) )
dissect_applemidi_common( tvb, pinfo, tree, command );
else
call_dissector( rtp_handle, tvb, pinfo, tree );
return tvb_captured_length(tvb);
}
static gboolean
dissect_applemidi_heur( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_ ) {
guint16 command;
conversation_t *p_conv;
rtp_dyn_payload_t *rtp_dyn_payload;
if ( tvb_captured_length( tvb ) < 4)
return FALSE;
if ( !test_applemidi( tvb, &command, FALSE ) ) {
return FALSE;
}
rtp_dyn_payload = rtp_dyn_payload_new();
rtp_dyn_payload_insert(rtp_dyn_payload, 97, "rtp-midi", 10000);
rtp_add_address( pinfo, PT_UDP, &pinfo->src, pinfo->srcport, 0, APPLEMIDI_DISSECTOR_SHORTNAME,
pinfo->num, FALSE, rtp_dyn_payload);
p_conv = find_or_create_conversation(pinfo);
conversation_set_dissector( p_conv, applemidi_handle );
dissect_applemidi_common( tvb, pinfo, tree, command );
return TRUE;
}
void
proto_register_applemidi( void )
{
static hf_register_info hf[] = {
{
&hf_applemidi_signature,
{
"Signature",
"applemidi.signature",
FT_UINT16,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_command,
{
"Command",
"applemidi.command",
FT_UINT16,
BASE_HEX,
VALS( applemidi_commands ),
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_protocol_version,
{
"Protocol Version",
"applemidi.protocol_version",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_token,
{
"Initiator Token",
"applemidi.initiator_token",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_ssrc,
{
"Sender SSRC",
"applemidi.sender_ssrc",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_name,
{
"Name",
"applemidi.name",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_count,
{
"Count",
"applemidi.count",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_padding,
{
"Padding",
"applemidi.padding",
FT_UINT24,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_timestamp1,
{
"Timestamp 1",
"applemidi.timestamp1",
FT_UINT64,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_timestamp2,
{
"Timestamp 2",
"applemidi.timestamp2",
FT_UINT64,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_timestamp3,
{
"Timestamp 3",
"applemidi.timestamp3",
FT_UINT64,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_sequence_num,
{
"Sequence Number",
"applemidi.sequence_number",
FT_UINT32,
BASE_HEX,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_rtp_sequence_num,
{
"RTP Sequence Number",
"applemidi.rtp_sequence_number",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_rtp_bitrate_limit,
{
"Bitrate limit",
"applemidi.bitrate_limit",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_applemidi_unknown_data,
{
"Unknown Data",
"applemidi.unknown_data",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
};
static gint *ett[] = {
&ett_applemidi,
&ett_applemidi_seq_num
};
proto_applemidi = proto_register_protocol( APPLEMIDI_DISSECTOR_NAME,
APPLEMIDI_DISSECTOR_SHORTNAME,
APPLEMIDI_DISSECTOR_ABBREVIATION );
proto_register_field_array( proto_applemidi, hf, array_length( hf ) );
proto_register_subtree_array( ett, array_length( ett ) );
}
void
proto_reg_handoff_applemidi( void ) {
applemidi_handle = create_dissector_handle( dissect_applemidi, proto_applemidi );
rtp_handle = find_dissector_add_dependency( "rtp", proto_applemidi );
heur_dissector_add( "udp", dissect_applemidi_heur, "Apple MIDI over UDP", "applemidi_udp", proto_applemidi, HEURISTIC_ENABLE );
}
