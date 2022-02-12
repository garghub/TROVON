static int
decodetime(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int cmd_len)
{
guint8 octet;
unsigned int consumed;
unsigned int i;
unsigned long deltatime;
consumed = 0;
deltatime = 0;
for ( i=0; i < 4; i++ ) {
if ( !cmd_len ) {
return -1;
}
octet = tvb_get_guint8( tvb, offset + consumed );
deltatime = ( deltatime << 7 ) | ( octet & RTP_MIDI_DELTA_TIME_OCTET_MASK );
consumed++;
if ( ( octet & RTP_MIDI_DELTA_TIME_EXTENSION ) == 0 ) {
break;
}
}
switch (consumed) {
case 1:
proto_tree_add_uint ( tree, hf_rtp_midi_deltatime1, tvb, offset, consumed, deltatime );
break;
case 2:
proto_tree_add_uint ( tree, hf_rtp_midi_deltatime2, tvb, offset, consumed, deltatime );
break;
case 3:
proto_tree_add_uint ( tree, hf_rtp_midi_deltatime3, tvb, offset, consumed, deltatime );
break;
case 4:
proto_tree_add_uint ( tree, hf_rtp_midi_deltatime4, tvb, offset, consumed, deltatime );
break;
}
return consumed;
}
static int
decode_note_off(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len, guint8 status, unsigned int rsoffset, gboolean using_rs ) {
guint8 note;
guint8 velocity;
const gchar *status_str;
const gchar *note_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( status >> 4, rtp_midi_channel_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1);
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
note = tvb_get_guint8( tvb, offset );
if ( note & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
note_str = val_to_str( note, rtp_midi_note_values, rtp_midi_unknown_value_dec );
if ( cmd_len < 2 ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "TRUNCATED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "TRUNCATED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
velocity = tvb_get_guint8( tvb, offset + 1 );
if ( velocity & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "ABORTED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "ABORTED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 2, "%s (c=%d, n=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, velocity );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_velocity, tvb, offset + 1, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text(tree, tvb, offset - 1, 3, "%s (c=%d, n=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, velocity );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_velocity, tvb, offset + 1, 1, ENC_BIG_ENDIAN );
}
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (c=%d, n=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, velocity );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (c=%d, n=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, velocity );
}
return 2;
}
static int
decode_note_on(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len, guint8 status, unsigned int rsoffset, gboolean using_rs ) {
guint8 note;
guint8 velocity;
const gchar *status_str;
const gchar *note_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( status >> 4, rtp_midi_channel_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1);
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
note = tvb_get_guint8( tvb, offset );
if ( note & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
note_str = val_to_str( note, rtp_midi_note_values, rtp_midi_unknown_value_dec );
if ( cmd_len < 2 ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "TRUNCATED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "TRUNCATED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
velocity = tvb_get_guint8( tvb, offset + 1 );
if ( velocity & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "ABORTED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "ABORTED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
if ( velocity == 0 ) {
status_str = rtp_midi_channel_status_special_off;
}
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 2, "%s (c=%d, n=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, velocity );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_velocity, tvb, offset + 1, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text(tree, tvb, offset - 1, 3, "%s (c=%d, n=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, velocity );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_velocity, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (c=%d, n=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, velocity );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (c=%d, n=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, velocity );
}
return 2;
}
static int
decode_poly_pressure(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len, guint8 status, unsigned int rsoffset, gboolean using_rs ) {
guint8 note;
guint8 pressure;
const gchar *status_str;
const gchar *note_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( status >> 4, rtp_midi_channel_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1);
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
note = tvb_get_guint8( tvb, offset );
if ( note & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
note_str = val_to_str( note, rtp_midi_note_values, rtp_midi_unknown_value_dec );
if ( cmd_len < 2 ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "TRUNCATED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "TRUNCATED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
pressure = tvb_get_guint8( tvb, offset + 1 );
if ( pressure & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "ABORTED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "ABORTED: %s (c=%d, n=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 2, "%s (c=%d, n=%s, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, pressure );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_pressure, tvb, offset + 1, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text(tree, tvb, offset - 1, 3, "%s (c=%d, n=%s, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, pressure );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_pressure, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (c=%d, n=%s, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, pressure );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (c=%d, n=%s, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, note_str, pressure );
}
return 2;
}
static int
decode_channel_pressure(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len, guint8 status, unsigned int rsoffset, gboolean using_rs ) {
guint8 pressure;
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( status >> 4, rtp_midi_channel_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1);
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
pressure = tvb_get_guint8( tvb, offset );
if ( pressure & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1);
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "%s (c=%d, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, pressure );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_pressure, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text(tree, tvb, offset - 1, 2, "%s (c=%d, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, pressure );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_pressure, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (c=%d, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, pressure );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (c=%d, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, pressure );
}
return 1;
}
static int
decode_pitch_bend_change(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len, guint8 status, unsigned int rsoffset, gboolean using_rs ) {
guint8 octet1;
guint8 octet2;
guint8 pitch;
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( status >> 4, rtp_midi_channel_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
octet1 = tvb_get_guint8( tvb, offset );
if ( octet1 & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
if ( cmd_len < 2 ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_pitch_bend_truncated, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_pitch_bend_truncated, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
octet2 = tvb_get_guint8( tvb, offset + 1 );
if ( octet2 & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_pitch_bend_truncated, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_pitch_bend_truncated, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
pitch = ( octet1 << 7 ) | octet2;
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 2, "%s (c=%d, pb=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, pitch );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_pitch_bend, tvb, offset, 2, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text(tree, tvb, offset - 1, 3, "%s (c=%d, pb=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, pitch );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_pitch_bend, tvb, offset, 2, ENC_BIG_ENDIAN );
}
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (c=%d, pb=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, pitch );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (c=%d, pb=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, pitch );
}
return 2;
}
static int
decode_program_change(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len, guint8 status, unsigned int rsoffset, gboolean using_rs ) {
guint8 program;
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( status >> 4, rtp_midi_channel_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1);
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
program = tvb_get_guint8( tvb, offset );
if ( program & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1);
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "%s (c=%d, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, program );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_program, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text(tree, tvb, offset - 1, 2, "%s (c=%d, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, program );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_program, tvb, offset, 1, ENC_BIG_ENDIAN);
}
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (c=%d, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, program );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (c=%d, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, program );
}
return 1;
}
static int
decode_control_change(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len, guint8 status, unsigned int rsoffset, gboolean using_rs ) {
guint8 controller;
guint8 value;
const gchar *status_str;
const gchar *ctrl_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( status >> 4, rtp_midi_channel_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
controller = tvb_get_guint8( tvb, offset );
if ( controller & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 0, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s (c=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1 );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
}
return -1;
}
ctrl_str = val_to_str( controller, rtp_midi_controller_values, "Unknown: %d" );
if ( cmd_len < 2 ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "TRUNCATED: %s (c=%d, ctrl=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, ctrl_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "TRUNCATED: %s (c=%d, ctrl=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, ctrl_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_note, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
value = tvb_get_guint8( tvb, offset + 1 );
if ( value & RTP_MIDI_COMMAND_STATUS_FLAG ) {
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 1, "ABORTED: %s (c=%d, ctrl=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, ctrl_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_controller, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "ABORTED: %s (c=%d, ctrl=%s)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, ctrl_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_controller, tvb, offset, 1, ENC_BIG_ENDIAN );
}
return -1;
}
if ( using_rs ) {
command_item = proto_tree_add_text( tree, tvb, offset, 2, "%s (c=%d, ctrl=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, ctrl_str, value );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, rsoffset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_controller, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_controller_value, tvb, offset + 1, 1, ENC_BIG_ENDIAN );
} else {
command_item = proto_tree_add_text(tree, tvb, offset - 1, 3, "%s (c=%d, ctrl=%s, v=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, ctrl_str, value );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_channel_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_channel, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_controller, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_controller_value, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
}
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (c=%d, ctrl=%s, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, ctrl_str, value );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (c=%d, ctrl=%s, p=%d)", status_str, ( status & RTP_MIDI_CHANNEL_MASK ) + 1, ctrl_str, value );
}
return 2;
}
static unsigned int
decode_sysex_common_nrt_sd_hdr( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_sn, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
data_len -= 2;
consumed += 2;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_sf, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 3 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_sp, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
data_len -= 3;
consumed += 3;
if ( data_len < 3 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_sl, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
data_len -= 3;
consumed += 3;
if ( data_len < 3 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_ls, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
data_len -= 3;
consumed += 3;
if ( data_len < 3 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_le, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
data_len -= 3;
consumed += 3;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_lt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_sd_packet( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_packet_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len > 1 ) {
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_packet_data, tvb, offset, data_len - 1, ENC_NA );
offset += ( data_len - 1 );
data_len -= ( data_len - 1 );
consumed += ( data_len -1 );
}
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_packet_check, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_sd_req( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_sn, tvb, offset, 2, ENC_BIG_ENDIAN );
consumed += 2;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_sd_ext( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
guint8 sub_id;
int consumed = 0;
if ( data_len < 1 )
return consumed;
sub_id = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_ext, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( sub_id == RTP_MIDI_SYSEX_COMMON_NRT_SD_EXT_LOOP_POINT_TRANSMISSION ) {
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_sn, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
data_len -= 2;
consumed += 2;
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_ext_ln, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
data_len -= 2;
consumed += 2;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_lt, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 3 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_ls, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
data_len -= 3;
consumed += 3;
if ( data_len < 3 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_le, tvb, offset, 3, ENC_BIG_ENDIAN );
consumed += 3;
} else if ( sub_id == RTP_MIDI_SYSEX_COMMON_NRT_SD_EXT_LOOP_POINTS_REQUEST ) {
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_header_sn, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
data_len -= 2;
consumed += 2;
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_ext_ln, tvb, offset, 2, ENC_BIG_ENDIAN );
consumed += 2;
}
return consumed;
}
static unsigned int
decode_sysex_common_nrt_gi( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
guint8 sub_id;
int consumed = 0;
if ( data_len < 1 )
return consumed;
sub_id = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_gi, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( sub_id == RTP_MIDI_SYSEX_COMMON_NRT_GI_IDENTITY_REQUEST ) {
} else if ( sub_id == RTP_MIDI_SYSEX_COMMON_NRT_GI_IDENTITY_REPLY ) {
guint8 manu_short;
if ( data_len < 1 ) {
return consumed;
}
proto_tree_add_item( tree, hf_rtp_midi_manu_short, tvb, offset, 1, ENC_BIG_ENDIAN );
manu_short = tvb_get_guint8( tvb, offset );
offset++;
data_len--;
consumed++;
if ( manu_short == RTP_MIDI_MANU_SHORT_ISLONG ) {
if ( data_len < 2 ) {
return consumed;
}
proto_tree_add_item( tree, hf_rtp_midi_manu_long, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2 ;
data_len -= 2;
consumed += 2;
}
if ( data_len < 2 ) {
return consumed;
}
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_gi_device_family, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2 ;
data_len -= 2;
consumed += 2;
if ( data_len < 2 ) {
return consumed;
}
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_gi_device_family_member, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2 ;
data_len -= 2;
consumed += 2;
if ( data_len < 4 ) {
return consumed;
}
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_gi_software_rev, tvb, offset, 4, ENC_BIG_ENDIAN );
consumed += 4;
}
return consumed;
}
static unsigned int
decode_sysex_common_nrt_fd( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
guint8 sub_id;
int consumed = 0;
if ( data_len < 1 )
return consumed;
sub_id = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( sub_id == RTP_MIDI_SYSEX_COMMON_NRT_FD_HEADER ) {
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_device_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 4 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_type, tvb, offset, 4, ENC_ASCII|ENC_NA );
offset += 4;
data_len -= 4;
consumed += 4;
if ( data_len < 4 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_length, tvb, offset, 4, ENC_BIG_ENDIAN );
offset += 4;
data_len -= 4;
consumed += 4;
if ( data_len ) {
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_name, tvb, offset, data_len, ENC_ASCII|ENC_NA );
data_len -= data_len;
consumed += data_len;
}
} else if ( sub_id == RTP_MIDI_SYSEX_COMMON_NRT_FD_DATA_PACKET ) {
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_packet_num, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_byte_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len > 1 ) {
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_packet_data, tvb, offset, data_len - 1, ENC_NA );
offset += ( data_len - 1 );
data_len -= ( data_len - 1 );
consumed += ( data_len -1 );
}
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_checksum, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
} else if ( sub_id == RTP_MIDI_SYSEX_COMMON_NRT_FD_REQUEST ) {
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_device_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 4 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_type, tvb, offset, 4, ENC_ASCII|ENC_NA );
offset += 4;
data_len -= 4;
consumed += 4;
if ( data_len ) {
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_fd_name, tvb, offset, data_len, ENC_ASCII|ENC_NA );
data_len -= data_len;
consumed += data_len;
}
}
return consumed;
}
static unsigned int
decode_sysex_common_tuning( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
proto_item *tune_item;
proto_tree *tune_tree;
const gchar *note_str;
guint8 sub_id;
int consumed = 0;
unsigned int i;
if ( data_len < 1 )
return consumed;
sub_id = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_tuning, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( sub_id == RTP_MIDI_SYSEX_COMMON_TUNING_BULK_DUMP_REQUEST ) {
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_tune_program, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
} else if ( sub_id == RTP_MIDI_SYSEX_COMMON_TUNING_BULK_DUMP_REPLY ) {
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_tune_program, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 16 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_tune_name, tvb, offset, 16, ENC_ASCII|ENC_NA );
offset += 16;
data_len -= 16;
consumed += 16;
for ( i=0; i < 128; i++ ) {
if ( data_len < 3 )
return -1;
note_str = val_to_str( i, rtp_midi_note_values, rtp_midi_unknown_value_dec );
tune_item = proto_tree_add_text(tree, tvb, offset, 3, "Note: %s", note_str );
tune_tree = proto_item_add_subtree( tune_item, ett_rtp_midi_sysex_common_tune_note );
proto_tree_add_item( tune_tree, hf_rtp_midi_sysex_common_tune_freq, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
data_len -= 3;
consumed += 3;
}
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_tune_checksum, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
} else if ( sub_id == RTP_MIDI_SYSEX_COMMON_TUNING_NOTE_CHANGE ) {
guint8 changes;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_tune_program, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
changes = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_tune_changes, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
for ( i=0; i < changes; i++ ) {
guint8 note;
if ( data_len < 4 )
return -1;
note = tvb_get_guint8( tvb, offset );
note_str = val_to_str( note, rtp_midi_note_values, rtp_midi_unknown_value_dec );
tune_item = proto_tree_add_text(tree, tvb, offset, 3, "Note: %s", note_str );
tune_tree = proto_item_add_subtree( tune_item, ett_rtp_midi_sysex_common_tune_note );
proto_tree_add_item( tune_tree, hf_rtp_midi_sysex_common_tune_note, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
proto_tree_add_item( tune_tree, hf_rtp_midi_sysex_common_tune_freq, tvb, offset, 3, ENC_BIG_ENDIAN );
offset += 3;
data_len -= 3;
consumed += 3;
}
}
return consumed;
}
static unsigned int
decode_sysex_common_nrt_gm( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_gm, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_dls( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_dls, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_eof( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_packet_number, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_wait( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_packet_number, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_cancel( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_packet_number, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_nak( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_packet_number, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_ack( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_sd_packet_number, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_nrt_mtc( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_type, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_hr, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_mn, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_sc, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_fr, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_ff, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_enl, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_enm, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len ) {
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_nrt_mtc_add, tvb, offset, data_len, ENC_NA );
data_len -= data_len;
consumed += data_len;
}
return consumed;
}
static unsigned int
decode_sysex_common_rt_mtc_cue( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_cueing, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_cue_enl, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_cue_enm, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len ) {
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_cue_add, tvb, offset, data_len, ENC_NA );
data_len -= data_len;
consumed += data_len;
}
return consumed;
}
static unsigned int
decode_sysex_common_nrt( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
guint8 common_nrt;
const gchar *nrt_str;
proto_item *command_item;
proto_tree *command_tree;
int consumed = 0;
int ext_consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_device_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 ) {
return consumed;
}
common_nrt = tvb_get_guint8( tvb, offset );
nrt_str = val_to_str( common_nrt, rtp_midi_sysex_common_nrt, "Unknown 0x%02x" );
command_item = proto_tree_add_text(tree, tvb, offset, data_len, "%s",nrt_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_sysex_common_nrt );
proto_tree_add_item( command_tree, hf_rtp_midi_sysex_common_non_realtime, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
switch ( common_nrt ) {
case RTP_MIDI_SYSEX_COMMON_NRT_SAMPLE_DUMP_HEADER:
ext_consumed = decode_sysex_common_nrt_sd_hdr( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_SAMPLE_DATA_PACKET:
ext_consumed = decode_sysex_common_nrt_sd_packet( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_SAMPLE_DUMP_REQUEST:
ext_consumed = decode_sysex_common_nrt_sd_req( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_MTC:
ext_consumed = decode_sysex_common_nrt_mtc( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_SAMPLE_DUMP_EXTENSIONS:
ext_consumed = decode_sysex_common_nrt_sd_ext( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_GENERAL_INFORMATION:
ext_consumed = decode_sysex_common_nrt_gi( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_FILE_DUMP:
ext_consumed = decode_sysex_common_nrt_fd( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_MIDI_TUNING_STANDARD:
ext_consumed = decode_sysex_common_tuning( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_GENERAL_MIDI:
ext_consumed = decode_sysex_common_nrt_gm( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_DOWNLOADABLE_SOUNDS:
ext_consumed = decode_sysex_common_nrt_dls( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_END_OF_FILE:
ext_consumed = decode_sysex_common_nrt_eof( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_WAIT:
ext_consumed = decode_sysex_common_nrt_wait( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_CANCEL:
ext_consumed = decode_sysex_common_nrt_cancel( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_NAK:
ext_consumed = decode_sysex_common_nrt_nak( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_NRT_ACK:
ext_consumed = decode_sysex_common_nrt_ack( tvb, pinfo, command_tree, offset, data_len );
break;
}
if ( ext_consumed < 0 ) {
return -1;
}
offset += ext_consumed;
data_len -= ext_consumed;
consumed += ext_consumed;
if ( data_len > 0 ) {
proto_tree_add_item( command_tree, hf_rtp_midi_unknown_data, tvb, offset, data_len, ENC_NA );
consumed += data_len;
}
return consumed;
}
static unsigned int
decode_sysex_common_rt_mtc( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
guint8 sub_id;
int consumed = 0;
if ( data_len < 1 )
return consumed;
sub_id = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( sub_id == RTP_MIDI_SYSEX_COMMON_RT_MTC_FULL_MESSAGE ) {
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_fm_type, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_fm_hr, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_fm_mn, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_fm_sc, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_fm_fr, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
} else if ( sub_id == RTP_MIDI_SYSEX_COMMON_RT_MTC_USER_BITS ) {
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u1, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u2, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u3, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u4, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u5, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u6, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u7, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u8, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mtc_ub_u9, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
}
return consumed;
}
static unsigned int
decode_sysex_common_rt_sc( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_sc, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_rt_ni( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
guint8 sub_id;
int consumed = 0;
if ( data_len < 1 )
return consumed;
sub_id = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( sub_id == RTP_MIDI_SYSEX_COMMON_RT_NT_BAR_NUMBER ) {
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni_bar_num, tvb, offset, 2, ENC_BIG_ENDIAN );
consumed += 2;
} else if ( ( sub_id == RTP_MIDI_SYSEX_COMMON_RT_NT_TIME_SIGNATURE_IMMEDIATE ) ||
( sub_id == RTP_MIDI_SYSEX_COMMON_RT_NT_TIME_SIGNATURE_DELAYED ) ) {
int bytes;
if ( data_len < 1 )
return -1;
bytes = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni_bytes, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni_numerator, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
bytes--;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni_denominator, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
bytes--;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni_midi_clocks, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
bytes--;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni_32nds, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
bytes--;
while ( bytes > 0 ) {
if ( data_len < 1 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni_numerator, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
bytes--;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_ni_denominator, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
bytes--;
}
}
return consumed;
}
static unsigned int
decode_sysex_common_rt_dc( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
guint8 sub_id;
int consumed = 0;
if ( data_len < 1 )
return consumed;
sub_id = tvb_get_guint8( tvb, offset );
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_dc, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( sub_id == RTP_MIDI_SYSEX_COMMON_RT_DC_MASTER_VOLUME ) {
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_dc_volume, tvb, offset, 2, ENC_BIG_ENDIAN );
consumed += 2;
} else if ( sub_id == RTP_MIDI_SYSEX_COMMON_RT_DC_MASTER_BALANCE ) {
if ( data_len < 2 )
return -1;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_dc_balance, tvb, offset, 2, ENC_BIG_ENDIAN );
consumed += 2;
}
return consumed;
}
static unsigned int
decode_sysex_common_rt_mmc_command( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mmc_commands, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_rt_mmc_response( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
int consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_rt_mmc_responses, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
return consumed;
}
static unsigned int
decode_sysex_common_rt( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
guint8 common_rt;
const gchar *rt_str;
proto_item *command_item;
proto_tree *command_tree;
int consumed = 0;
int ext_consumed = 0;
if ( data_len < 1 )
return consumed;
proto_tree_add_item( tree, hf_rtp_midi_sysex_common_device_id, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
data_len--;
consumed++;
if ( data_len < 1 ) {
return consumed;
}
common_rt = tvb_get_guint8( tvb, offset );
rt_str = val_to_str( common_rt, rtp_midi_sysex_common_rt, "Unknown 0x%02x" );
command_item = proto_tree_add_text(tree, tvb, offset, data_len, "%s", rt_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_sysex_common_rt );
proto_tree_add_item( command_tree, hf_rtp_midi_sysex_common_realtime, tvb, offset, 1, ENC_BIG_ENDIAN );
data_len--;
offset++;
consumed++;
switch ( common_rt ) {
case RTP_MIDI_SYSEX_COMMON_RT_MIDI_TIME_CODE:
ext_consumed = decode_sysex_common_rt_mtc( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_RT_MIDI_SHOW_CONTROL:
ext_consumed = decode_sysex_common_rt_sc( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_RT_NOTATION_INFORMATION:
ext_consumed = decode_sysex_common_rt_ni( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_RT_DEVICE_CONTROL:
ext_consumed = decode_sysex_common_rt_dc( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_RT_MTC_CUEING:
ext_consumed = decode_sysex_common_rt_mtc_cue( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_RT_MIDI_MACHINE_CONTROL_COMMAND:
ext_consumed = decode_sysex_common_rt_mmc_command( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_RT_MIDI_MACHINE_CONTROL_RESPONSE:
ext_consumed = decode_sysex_common_rt_mmc_response( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_SYSEX_COMMON_RT_MIDI_TUNING_STANDARD:
ext_consumed = decode_sysex_common_tuning( tvb, pinfo, command_tree, offset, data_len );
break;
}
if ( ext_consumed < 0 ) {
return -1;
}
offset += ext_consumed;
data_len -= ext_consumed;
consumed += ext_consumed;
if ( data_len > 0 ) {
proto_tree_add_item( command_tree, hf_rtp_midi_unknown_data, tvb, offset, data_len, ENC_NA );
consumed += data_len;
}
return consumed;
}
static unsigned int
decode_sysex_common_educational( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len ) {
proto_item *command_item;
proto_tree *command_tree;
int consumed = 0;
if ( data_len < 1 )
return consumed;
command_item = proto_tree_add_text(tree, tvb, offset, data_len, RTP_MIDI_TREE_NAME_COMMAND_SYSEX_EDU );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_sysex_edu );
proto_tree_add_item( command_tree, hf_rtp_midi_edu_data, tvb, offset, data_len, ENC_NA );
return data_len;
}
static unsigned int
decode_sysex_common_manufacturer( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int data_len, unsigned int manu_code _U_) {
proto_item *command_item;
proto_tree *command_tree;
int consumed = 0;
if ( data_len < 1 )
return consumed;
command_item = proto_tree_add_text(tree, tvb, offset, data_len, RTP_MIDI_TREE_NAME_COMMAND_SYSEX_MANU );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_sysex_manu );
proto_tree_add_item( command_tree, hf_rtp_midi_manu_data, tvb, offset, data_len, ENC_NA );
return data_len;
}
static unsigned int
decode_sysex_start(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len ) {
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
int consumed = 0;
int data_len;
int ext_consumed = 0;
status_str = val_to_str( RTP_MIDI_STATUS_COMMON_SYSEX_END, rtp_midi_common_status, rtp_midi_unknown_value_hex );
while ( cmd_len ) {
guint8 octet;
octet = tvb_get_guint8( tvb, offset + consumed );
consumed++;
if ( octet == RTP_MIDI_STATUS_COMMON_SYSEX_END ) {
status_str = rtp_midi_common_status_sysex_segment_complete;
} else if ( octet == RTP_MIDI_STATUS_COMMON_SYSEX_START ) {
status_str = rtp_midi_common_status_sysex_segment_start;
} else if ( octet == RTP_MIDI_STATUS_COMMON_UNDEFINED_F4 ) {
status_str = rtp_midi_common_status_sysex_cancel;
}
if ( octet & RTP_MIDI_COMMAND_STATUS_FLAG ) {
break;
}
}
data_len = consumed - 1;
command_item = proto_tree_add_text(tree, tvb, offset - 1, 1 + consumed, "%s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
if ( data_len > 1 ) {
guint8 manu_short;
guint16 manufacturer;
manufacturer = tvb_get_guint8( tvb, offset );
proto_tree_add_item( command_tree, hf_rtp_midi_manu_short, tvb, offset, 1, ENC_BIG_ENDIAN );
manu_short = tvb_get_guint8( tvb, offset );
offset++;
data_len--;
switch( manu_short ) {
case RTP_MIDI_MANU_SHORT_NON_REALTIME_UNIVERSAL:
ext_consumed = decode_sysex_common_nrt( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_MANU_SHORT_REALTIME_UNIVERSAL:
ext_consumed = decode_sysex_common_rt( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_MANU_SHORT_EDUCATIONAL_USE:
ext_consumed = decode_sysex_common_educational( tvb, pinfo, command_tree, offset, data_len );
break;
case RTP_MIDI_MANU_SHORT_ISLONG:
if ( data_len > 2 ) {
manufacturer = tvb_get_ntohs( tvb, offset );
proto_tree_add_item( command_tree, hf_rtp_midi_manu_long, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2 ;
data_len -= 2;
ext_consumed = decode_sysex_common_manufacturer( tvb, pinfo, command_tree, offset, data_len, manufacturer );
} else {
ext_consumed = -1;
}
break;
default:
ext_consumed = decode_sysex_common_manufacturer( tvb, pinfo, command_tree, offset, data_len, manufacturer );
break;
}
}
if ( ext_consumed < 0 ) {
return -1;
}
offset += ext_consumed;
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset, 1, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s", status_str );
} else {
col_append_str(pinfo->cinfo, COL_INFO, status_str );
}
return consumed;
}
static int
decode_mtc_quarter_frame(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len ) {
guint8 value;
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( RTP_MIDI_STATUS_COMMON_MTC_QUARTER_FRAME, rtp_midi_common_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s ", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
return -1;
}
value = tvb_get_guint8( tvb, offset );
if ( value & RTP_MIDI_COMMAND_STATUS_FLAG ) {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
return -1;
}
command_item = proto_tree_add_text(tree, tvb, offset - 1, 2, "%s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_quarter_frame_type, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_quarter_frame_value, tvb, offset + 1, 1, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s", status_str );
} else {
col_append_str(pinfo->cinfo, COL_INFO, status_str );
}
return 1;
}
static int
decode_song_position_pointer(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len ) {
guint8 octet1;
guint8 octet2;
guint8 position;
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( RTP_MIDI_STATUS_COMMON_SONG_POSITION_POINTER, rtp_midi_common_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
return -1;
}
octet1 = tvb_get_guint8( tvb, offset );
if ( octet1 & RTP_MIDI_COMMAND_STATUS_FLAG ) {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
return -1;
}
if ( cmd_len < 2 ) {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "TRUNCATED: %s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_spp_truncated, tvb, offset, 1, ENC_BIG_ENDIAN );
return -1;
}
octet2 = tvb_get_guint8( tvb, offset + 1 );
if ( octet2 & RTP_MIDI_COMMAND_STATUS_FLAG ) {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 2, "ABORTED: %s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_spp_truncated, tvb, offset, 1, ENC_BIG_ENDIAN );
return -1;
}
position = ( octet1 << 7 ) | octet2;
command_item = proto_tree_add_text(tree, tvb, offset - 1, 3, "%s (p=%d)", status_str, position );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_spp, tvb, offset, 2, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (p=%d)", status_str, position );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (p=%d)", status_str, position );
}
return 2;
}
static int
decode_song_select(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len ) {
guint8 song_nr;
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( RTP_MIDI_STATUS_COMMON_SONG_SELECT, rtp_midi_common_status, rtp_midi_unknown_value_hex );
if ( !cmd_len ) {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "TRUNCATED: %s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
return -1;
}
song_nr = tvb_get_guint8( tvb, offset );
if ( song_nr & RTP_MIDI_COMMAND_STATUS_FLAG ) {
command_item = proto_tree_add_text( tree, tvb, offset - 1, 1, "ABORTED: %s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
return -1;
}
command_item = proto_tree_add_text(tree, tvb, offset - 1, 2, "%s (s=%d)", status_str, song_nr );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_song_select, tvb, offset, 1, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s (s=%d)", status_str, song_nr );
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (s=%d)", status_str, song_nr );
}
return 1;
}
static int
decode_undefined_f4(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len ) {
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
int consumed = 0;
status_str = val_to_str( RTP_MIDI_STATUS_COMMON_UNDEFINED_F4, rtp_midi_common_status, rtp_midi_unknown_value_hex );
while ( cmd_len ) {
guint8 octet;
octet = tvb_get_guint8( tvb, offset + consumed );
consumed++;
if ( octet & RTP_MIDI_COMMAND_STATUS_FLAG ) {
break;
}
}
command_item = proto_tree_add_text(tree, tvb, offset - 1, 1 + consumed, "%s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_unknown_data, tvb, offset, consumed, ENC_NA );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset + consumed - 1, 1, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s", status_str );
} else {
col_append_str(pinfo->cinfo, COL_INFO, status_str );
}
return consumed;
}
static int
decode_undefined_f5(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len ) {
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
int consumed = 0;
status_str = val_to_str( RTP_MIDI_STATUS_COMMON_UNDEFINED_F5, rtp_midi_common_status, rtp_midi_unknown_value_hex );
while ( cmd_len ) {
guint8 octet;
octet = tvb_get_guint8( tvb, offset + consumed );
consumed++;
if ( octet & RTP_MIDI_COMMAND_STATUS_FLAG ) {
break;
}
}
command_item = proto_tree_add_text(tree, tvb, offset - 1, 1 + consumed, "%s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_unknown_data, tvb, offset, consumed, ENC_NA );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset + consumed - 1, 1, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s", status_str );
} else {
col_append_str(pinfo->cinfo, COL_INFO, status_str );
}
return consumed;
}
static int
decode_tune_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len _U_ ) {
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
status_str = val_to_str( RTP_MIDI_STATUS_COMMON_TUNE_REQUEST, rtp_midi_common_status, rtp_midi_unknown_value_hex );
command_item = proto_tree_add_text(tree, tvb, offset - 1, 1, "%s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s)", status_str );
} else {
col_append_str(pinfo->cinfo, COL_INFO, status_str );
}
return 0;
}
static int
decode_sysex_end(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len ) {
const gchar *status_str;
proto_item *command_item;
proto_tree *command_tree;
int consumed = 0;
status_str = val_to_str( RTP_MIDI_STATUS_COMMON_SYSEX_END, rtp_midi_common_status, rtp_midi_unknown_value_hex );
while ( cmd_len ) {
guint8 octet;
octet = tvb_get_guint8( tvb, offset + consumed );
consumed++;
if ( octet == RTP_MIDI_STATUS_COMMON_SYSEX_END ) {
status_str = rtp_midi_common_status_sysex_segment_end;
} else if ( octet == RTP_MIDI_STATUS_COMMON_SYSEX_START ) {
status_str = rtp_midi_common_status_sysex_segment;
} else if ( octet == RTP_MIDI_STATUS_COMMON_UNDEFINED_F4 ) {
status_str = rtp_midi_common_status_sysex_cancel;
}
if ( octet & RTP_MIDI_COMMAND_STATUS_FLAG ) {
break;
}
}
command_item = proto_tree_add_text(tree, tvb, offset - 1, 1 + consumed, "%s", status_str );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset - 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( command_tree, hf_rtp_midi_unknown_data, tvb, offset, consumed - 1, ENC_NA );
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset + consumed - 1, 1, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_append_fstr(pinfo->cinfo, COL_INFO,", %s", status_str );
} else {
col_append_str(pinfo->cinfo, COL_INFO, status_str );
}
return consumed;
}
static int
decodemidi(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int cmd_count, unsigned int offset, unsigned int cmd_len, guint8 *runningstatus, unsigned int *rsoffset )
{
int consumed = 0;
int ext_consumed = 0;
guint8 octet;
gboolean using_rs;
#if 0
guint8 octet2;
guint8 octet3;
guint8 cmd;
guint8 channel;
proto_tree *sysexdata_tree = NULL;
gboolean foundend;
guint16 wordvalue;
char helptext[200];
char entry[200];
char segtype[200];
guint8 manu1;
guint16 manu2;
guint8 subid1;
guint8 subid2;
guint8 sysexchan;
unsigned int helpoffset;
#endif
if ( !cmd_len ) {
return -1;
}
octet = tvb_get_guint8( tvb, offset );
if ( octet >= 0xf8 ) {
proto_item *command_item;
proto_tree *command_tree;
const gchar *valstr;
valstr = val_to_str( octet, rtp_midi_common_status, rtp_midi_unknown_value_hex );
command_item = proto_tree_add_text(tree, tvb, offset, 1, "%s", valstr );
command_tree = proto_item_add_subtree( command_item, ett_rtp_midi_command);
proto_tree_add_item( command_tree, hf_rtp_midi_common_status, tvb, offset, 1, ENC_BIG_ENDIAN );
if ( cmd_count ) {
col_add_fstr(pinfo->cinfo, COL_INFO,", %s", valstr );
} else {
col_add_str(pinfo->cinfo, COL_INFO, valstr );
}
return 1;
}
if ( ( octet & RTP_MIDI_COMMAND_STATUS_FLAG ) == 0 ) {
if ( ( ( *runningstatus ) & RTP_MIDI_COMMAND_STATUS_FLAG ) == 0 ) {
return -1;
}
octet = *runningstatus;
using_rs = TRUE;
} else {
using_rs = FALSE;
if ( octet < 0xf0 ) {
*rsoffset = offset ;
*runningstatus = octet;
} else {
*runningstatus = 0;
}
consumed++;
cmd_len--;
offset++;
}
if ( octet < 0xf0 ) {
switch ( octet >> 4 ) {
case RTP_MIDI_STATUS_CHANNEL_NOTE_OFF:
ext_consumed = decode_note_off( tvb, pinfo, tree, cmd_count, offset, cmd_len, octet, *rsoffset, using_rs );
break;
case RTP_MIDI_STATUS_CHANNEL_NOTE_ON:
ext_consumed = decode_note_on( tvb, pinfo, tree, cmd_count, offset, cmd_len, octet, *rsoffset, using_rs );
break;
case RTP_MIDI_STATUS_CHANNEL_POLYPHONIC_KEY_PRESSURE:
ext_consumed = decode_poly_pressure(tvb, pinfo, tree, cmd_count, offset, cmd_len, octet, *rsoffset, using_rs );
break;
case RTP_MIDI_STATUS_CHANNEL_CONTROL_CHANGE:
ext_consumed = decode_control_change(tvb, pinfo, tree, cmd_count, offset, cmd_len, octet, *rsoffset, using_rs );
break;
case RTP_MIDI_STATUS_CHANNEL_PROGRAM_CHANGE:
ext_consumed = decode_program_change(tvb, pinfo, tree, cmd_count, offset, cmd_len, octet, *rsoffset, using_rs );
break;
case RTP_MIDI_STATUS_CHANNEL_CHANNEL_PRESSURE:
ext_consumed = decode_channel_pressure(tvb, pinfo, tree, cmd_count, offset, cmd_len, octet, *rsoffset, using_rs );
break;
case RTP_MIDI_STATUS_CHANNEL_PITCH_BEND_CHANGE:
ext_consumed = decode_pitch_bend_change(tvb, pinfo, tree, cmd_count, offset, cmd_len, octet, *rsoffset, using_rs );
break;
}
if ( ext_consumed < 0 ) {
return ext_consumed;
}
return consumed + ext_consumed;
}
switch ( octet ) {
case RTP_MIDI_STATUS_COMMON_SYSEX_START:
ext_consumed = decode_sysex_start( tvb, pinfo, tree, cmd_count, offset, cmd_len );
break;
case RTP_MIDI_STATUS_COMMON_MTC_QUARTER_FRAME:
ext_consumed = decode_mtc_quarter_frame( tvb, pinfo, tree, cmd_count, offset, cmd_len );
break;
case RTP_MIDI_STATUS_COMMON_SONG_POSITION_POINTER:
ext_consumed = decode_song_position_pointer( tvb, pinfo, tree, cmd_count, offset, cmd_len );
break;
case RTP_MIDI_STATUS_COMMON_SONG_SELECT:
ext_consumed = decode_song_select( tvb, pinfo, tree, cmd_count, offset, cmd_len );
break;
case RTP_MIDI_STATUS_COMMON_UNDEFINED_F4:
ext_consumed = decode_undefined_f4( tvb, pinfo, tree, cmd_count, offset, cmd_len );
break;
case RTP_MIDI_STATUS_COMMON_UNDEFINED_F5:
ext_consumed = decode_undefined_f5( tvb, pinfo, tree, cmd_count, offset, cmd_len );
break;
case RTP_MIDI_STATUS_COMMON_TUNE_REQUEST:
ext_consumed = decode_tune_request( tvb, pinfo, tree, cmd_count, offset, cmd_len );
break;
case RTP_MIDI_STATUS_COMMON_SYSEX_END:
ext_consumed = decode_sysex_end( tvb, pinfo, tree, cmd_count, offset, cmd_len );
break;
}
if ( ext_consumed < 0 ) {
return ext_consumed;
}
return consumed + ext_consumed;
}
static int
decode_cj_chapter_c( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_cj_chapter_tree;
proto_tree *rtp_midi_loglist_tree;
int consumed = 0;
guint8 octet;
int count;
int i;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
octet = tvb_get_guint8( tvb, offset );
count = octet & 0x7f;
count++;
ti = proto_tree_add_text( tree, tvb, offset, 1 + 2 * count, RTP_MIDI_TREE_NAME_CJ_CHAPTER_C );
rtp_midi_cj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_c );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_c_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_c_length, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
ti = proto_tree_add_text( rtp_midi_cj_chapter_tree, tvb, offset, count * 2, RTP_MIDI_TREE_NAME_CJ_CHAPTER_C_LOGLIST );
rtp_midi_loglist_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_c_loglist );
for ( i = 0; i < count; i++ ) {
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
ti = proto_tree_add_text(rtp_midi_loglist_tree, tvb, offset, 2, RTP_MIDI_TREE_NAME_CJ_CHAPTER_C_LOGITEM );
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_c_logitem );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_c_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_c_number, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
octet = tvb_get_guint8( tvb, offset );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_c_aflag, tvb, offset, 1, ENC_BIG_ENDIAN );
if ( octet & 0x80 ) {
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_c_tflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_c_alt, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_c_value, tvb, offset, 1, ENC_BIG_ENDIAN );
}
offset++;
consumed++;
}
return consumed;
}
static int
decode_cj_chapter_m( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_cj_chapter_tree;
proto_tree *rtp_midi_loglist_tree;
proto_tree *rtp_midi_loglist_item_tree;
guint16 header;
guint8 logitemheader;
int length;
int logitemhdrlen;
int logitemlen;
gboolean no_pnum_msb;
int consumed = 0;
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
header = tvb_get_ntohs( tvb, offset );
length = header & RTP_MIDI_CJ_CHAPTER_M_MASK_LENGTH;
length -= 2;
ti = proto_tree_add_text( tree, tvb, offset, length, RTP_MIDI_TREE_NAME_CJ_CHAPTER_M );
rtp_midi_cj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_m );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_sflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_pflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_eflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_uflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_wflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_zflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_length, tvb, offset, 2, ENC_BIG_ENDIAN );
consumed += 2;
offset += 2;
if ( header & 0x4000 ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_qflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_m_pending, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
}
no_pnum_msb = ( header & 0x0400 ) && ( ( header & 0x0800 ) || ( header & 0x1000 ) );
logitemhdrlen = no_pnum_msb ? 2 : 3;
ti = proto_tree_add_text( rtp_midi_cj_chapter_tree, tvb, offset, length, RTP_MIDI_TREE_NAME_CJ_CHAPTER_M_LOGLIST );
rtp_midi_loglist_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_m_loglist );
while ( length > 0 ) {
if ( !tvb_bytes_exist( tvb, offset, logitemhdrlen ) ) {
return -1;
}
if ( no_pnum_msb ) {
logitemheader = tvb_get_guint8( tvb, offset + 1 );
} else {
logitemheader = tvb_get_guint8( tvb, offset + 2 );
}
logitemlen = logitemhdrlen;
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_J ) {
logitemlen++;
}
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_K ) {
logitemlen++;
}
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_L ) {
logitemlen +=2;
}
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_M ) {
logitemlen +=2;
}
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_N ) {
logitemlen++;
}
ti = proto_tree_add_text( rtp_midi_loglist_tree, tvb, offset, logitemlen, RTP_MIDI_TREE_NAME_CJ_CHAPTER_M_LOGITEM );
rtp_midi_loglist_item_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_m_logitem );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_pnum_lsb, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
length--;
if ( !no_pnum_msb ) {
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_qflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_pnum_msb, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
length--;
}
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_jflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_kflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_lflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_mflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_nflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_tflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_vflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_loglist_item_tree, hf_rtp_midi_cj_chapter_m_log_rflag, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
length--;
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_J ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_loglist_tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_CJ_CHAPTER_M_LOG_MSB );
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_m_log_msb );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_msb_x, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_msb, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
length--;
}
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_K ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_loglist_tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_CJ_CHAPTER_M_LOG_LSB );
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_m_log_lsb );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_lsb_x, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_lsb, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
length--;
}
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_L ) {
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_loglist_tree, tvb, offset, 2, RTP_MIDI_TREE_NAME_CJ_CHAPTER_M_LOG_A_BUTTON );
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_m_log_a_button );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_a_button_g, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_a_button_x, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_a_button, tvb, offset, 2, ENC_BIG_ENDIAN );
consumed += 2;
offset += 2;
length -= 2;
}
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_M ) {
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_loglist_tree, tvb, offset, 2, RTP_MIDI_TREE_NAME_CJ_CHAPTER_M_LOG_C_BUTTON );
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_m_log_c_button );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_c_button_g, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_c_button_r, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_c_button, tvb, offset, 2, ENC_BIG_ENDIAN );
consumed += 2;
offset += 2;
length -= 2;
}
if ( logitemheader & RTP_MIDI_CJ_CHAPTER_M_FLAG_N ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_loglist_tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_CJ_CHAPTER_M_LOG_COUNT );
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_m_log_count );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_count_x, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_m_log_count, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
length--;
}
}
return consumed;
}
static int
decode_cj_chapter_n( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_cj_chapter_tree;
proto_tree *rtp_midi_loglist_tree;
const gchar *note_str;
int consumed = 0;
guint16 header;
guint8 note;
guint8 velocity;
int log_count;
int octet_count;
int low;
int high;
int i;
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
header = tvb_get_ntohs( tvb, offset );
log_count = ( header & RTP_MIDI_CJ_CHAPTER_N_MASK_LENGTH ) >> 8;
low = ( header & RTP_MIDI_CJ_CHAPTER_N_MASK_LOW ) >> 4;
high = header & RTP_MIDI_CJ_CHAPTER_N_MASK_HIGH;
if ( low <= high ) {
octet_count = high - low + 1;
} else if ( ( low == 15 ) && ( high == 0 ) ) {
octet_count = 0;
} else if ( ( low == 15 ) && ( high == 1 ) ) {
octet_count = 0;
} else {
return -1;
}
if ( ( log_count == 127 ) && ( low == 15) && ( high == 0 ) ) {
log_count++;
}
ti = proto_tree_add_text( tree, tvb, offset, 2 + ( log_count * 2 ) + octet_count, RTP_MIDI_TREE_NAME_CJ_CHAPTER_N );
rtp_midi_cj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_n );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_n_bflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_n_len, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_n_low, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_n_high, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
consumed += 2;
if ( log_count > 0 ) {
if ( !tvb_bytes_exist( tvb, offset, log_count * 2 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_cj_chapter_tree, tvb, offset, log_count * 2, RTP_MIDI_TREE_NAME_CJ_CHAPTER_N_LOGLIST );
rtp_midi_loglist_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_n_loglist );
for ( i = 0; i < log_count; i++ ) {
note = tvb_get_guint8( tvb, offset ) & 0x7f;
velocity = tvb_get_guint8( tvb, offset + 1 ) & 0x7f;
note_str = val_to_str( note, rtp_midi_note_values, rtp_midi_unknown_value_dec );
ti = proto_tree_add_text(rtp_midi_loglist_tree, tvb, offset, 2, "%s (n=%s, v=%d)", RTP_MIDI_TREE_NAME_CJ_CHAPTER_N_LOGITEM, note_str, velocity );
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_n_logitem );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_n_log_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_n_log_notenum, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_n_log_yflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_n_log_velocity, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
}
if ( octet_count > 0 ) {
if ( !tvb_bytes_exist( tvb, offset, octet_count ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_cj_chapter_tree, tvb, offset, log_count, RTP_MIDI_TREE_NAME_CJ_CHAPTER_N_OCTETS );
rtp_midi_loglist_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_n_octets );
for ( i = 0; i < octet_count; i++ ) {
proto_tree_add_item(rtp_midi_loglist_tree, hf_rtp_midi_cj_chapter_n_log_octet, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
}
return consumed;
}
static int
decode_cj_chapter_e( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_cj_chapter_tree;
proto_tree *rtp_midi_loglist_tree;
const gchar *note_str;
int consumed = 0;
guint8 header;
guint8 note;
guint8 count_vel;
guint8 octet;
int log_count;
int i;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
header = tvb_get_guint8( tvb, offset );
log_count = header & RTP_MIDI_CJ_CHAPTER_E_MASK_LENGTH;
log_count++;
ti = proto_tree_add_text( tree, tvb, offset, 1 + ( log_count * 2 ), RTP_MIDI_TREE_NAME_CJ_CHAPTER_E );
rtp_midi_cj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_e );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_e_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_e_len, tvb, offset, 2, ENC_BIG_ENDIAN );
offset++;
consumed++;
if ( !tvb_bytes_exist( tvb, offset, log_count * 2 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_cj_chapter_tree, tvb, offset, log_count * 2, RTP_MIDI_TREE_NAME_CJ_CHAPTER_E_LOGLIST );
rtp_midi_loglist_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_e_loglist );
for ( i = 0; i < log_count; i++ ) {
note = tvb_get_guint8( tvb, offset ) & 0x7f;
octet = tvb_get_guint8( tvb, offset + 1 );
count_vel = octet & 0x7f;
note_str = val_to_str( note, rtp_midi_note_values, rtp_midi_unknown_value_dec );
if ( octet & 0x80 ) {
ti = proto_tree_add_text(rtp_midi_loglist_tree, tvb, offset, 2, "%s (n=%s, v=%d)", RTP_MIDI_TREE_NAME_CJ_CHAPTER_E_LOGITEM1, note_str, count_vel );
} else {
ti = proto_tree_add_text(rtp_midi_loglist_tree, tvb, offset, 2, "%s (n=%s, c=%d)", RTP_MIDI_TREE_NAME_CJ_CHAPTER_E_LOGITEM2, note_str, count_vel );
}
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_e_logitem );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_e_log_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_e_log_notenum, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_e_log_vflag, tvb, offset, 1, ENC_BIG_ENDIAN );
if ( octet & 0x80 ) {
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_e_log_velocity, tvb, offset, 1, ENC_BIG_ENDIAN );
} else {
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_e_log_count, tvb, offset, 1, ENC_BIG_ENDIAN );
}
offset++;
consumed++;
}
return consumed;
}
static int
decode_cj_chapter_a( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_cj_chapter_tree;
proto_tree *rtp_midi_loglist_tree;
const gchar *note_str;
int consumed = 0;
guint8 header;
guint8 note;
guint8 pressure;
int log_count;
int i;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
header = tvb_get_guint8( tvb, offset );
log_count = header & RTP_MIDI_CJ_CHAPTER_A_MASK_LENGTH;
log_count++;
ti = proto_tree_add_text( tree, tvb, offset, 1 + ( log_count * 2 ), RTP_MIDI_TREE_NAME_CJ_CHAPTER_A );
rtp_midi_cj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_a );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_a_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_a_len, tvb, offset, 2, ENC_BIG_ENDIAN );
offset++;
consumed++;
if ( !tvb_bytes_exist( tvb, offset, log_count * 2 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_cj_chapter_tree, tvb, offset, log_count * 2, RTP_MIDI_TREE_NAME_CJ_CHAPTER_A_LOGLIST );
rtp_midi_loglist_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_a_loglist );
for ( i = 0; i < log_count; i++ ) {
note = tvb_get_guint8( tvb, offset ) & 0x7f;
pressure = tvb_get_guint8( tvb, offset + 1 ) & 0x7f;
note_str = val_to_str( note, rtp_midi_note_values, rtp_midi_unknown_value_dec );
ti = proto_tree_add_text(rtp_midi_loglist_tree, tvb, offset, 2, "%s (n=%s, p=%d)", RTP_MIDI_TREE_NAME_CJ_CHAPTER_A_LOGITEM, note_str, pressure );
ti = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_a_logitem );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_a_log_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_a_log_notenum, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_a_log_xflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( ti, hf_rtp_midi_cj_chapter_a_log_pressure, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
return consumed;
}
static int
decode_channel_journal( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_chanjournal_tree;
proto_tree *rtp_midi_cj_chapters_tree;
proto_tree *rtp_midi_cj_chapter_tree;
guint32 chanflags;
guint16 chanjourlen;
int consumed = 0;
int ext_consumed = 0;
if ( !tvb_bytes_exist( tvb, offset, 3 ) ) {
return -1;
}
chanflags = tvb_get_ntoh24( tvb, offset );
chanjourlen = ( chanflags & RTP_MIDI_CJ_MASK_LENGTH ) >> 8;
ti = proto_tree_add_text( tree, tvb, offset, chanjourlen, "%s", val_to_str( ( chanflags & RTP_MIDI_CJ_MASK_CHANNEL ) >> RTP_MIDI_CJ_CHANNEL_SHIFT, rtp_midi_channels, rtp_midi_unknown_value_hex ) );
rtp_midi_chanjournal_tree = proto_item_add_subtree( ti, ett_rtp_midi_channeljournal );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_sflag, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_chan, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_hflag, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_len, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_toc_p, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_toc_c, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_toc_m, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_toc_w, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_toc_n, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_toc_e, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_toc_t, tvb, offset, 3, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_chanjournal_tree, hf_rtp_midi_chanjour_toc_a, tvb, offset, 3, ENC_BIG_ENDIAN );
ti = proto_tree_add_text( rtp_midi_chanjournal_tree, tvb, offset + 3, chanjourlen - 3, RTP_MIDI_TREE_NAME_CHANNEL_CHAPTERS );
rtp_midi_cj_chapters_tree = proto_item_add_subtree( ti, ett_rtp_midi_channelchapters );
offset += 3;
consumed += 3;
if ( chanflags & RTP_MIDI_CJ_FLAG_P ) {
if ( !tvb_bytes_exist( tvb, offset, 3 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_cj_chapters_tree, tvb, offset, 3, RTP_MIDI_TREE_NAME_CJ_CHAPTER_P );
rtp_midi_cj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_p );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_p_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_p_program, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_p_bflag, tvb, offset + 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_p_bank_msb, tvb, offset + 1, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_p_xflag, tvb, offset + 2, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_p_bank_lsb, tvb, offset + 2, 1, ENC_BIG_ENDIAN );
offset += 3;
consumed += 3;
}
if ( chanflags & RTP_MIDI_CJ_FLAG_C ) {
ext_consumed = decode_cj_chapter_c( tvb, pinfo, rtp_midi_cj_chapters_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( chanflags & RTP_MIDI_CJ_FLAG_M ) {
ext_consumed = decode_cj_chapter_m( tvb, pinfo, rtp_midi_cj_chapters_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( chanflags & RTP_MIDI_CJ_FLAG_W ) {
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_cj_chapters_tree, tvb, offset, 2, RTP_MIDI_TREE_NAME_CJ_CHAPTER_W );
rtp_midi_cj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_w );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_w_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_w_first, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_w_rflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_w_second, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
if ( chanflags & RTP_MIDI_CJ_FLAG_N ) {
ext_consumed = decode_cj_chapter_n( tvb, pinfo, rtp_midi_cj_chapters_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( chanflags & RTP_MIDI_CJ_FLAG_E ) {
ext_consumed = decode_cj_chapter_e( tvb, pinfo, rtp_midi_cj_chapters_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( chanflags & RTP_MIDI_CJ_FLAG_T ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_cj_chapters_tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_CJ_CHAPTER_T );
rtp_midi_cj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_cj_chapter_t );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_t_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_cj_chapter_tree, hf_rtp_midi_cj_chapter_t_pressure, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
if ( chanflags & RTP_MIDI_CJ_FLAG_A ) {
ext_consumed = decode_cj_chapter_a( tvb, pinfo, rtp_midi_cj_chapters_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
}
if ( consumed != chanjourlen ) {
return -1;
}
return consumed;
}
static int
decode_sj_chapter_d_f4( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_field_tree;
int consumed = 0;
guint16 f4flags;
guint16 f4length;
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
f4flags = tvb_get_ntohs( tvb, offset );
f4length = f4flags & RTP_MIDI_SJ_CHAPTER_D_SYSCOM_MASK_LENGTH;
ti = proto_tree_add_text( tree, tvb, offset, f4length, RTP_MIDI_TREE_NAME_SJ_CHAPTER_D_FIELD_J );
rtp_midi_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_d_field_j );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_sflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_cflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_vflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_lflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_dsz, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_length, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
consumed += 2;
f4length -= 2;
if ( f4flags & RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_C ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
f4length--;
}
if ( f4flags & RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_V ) {
int valuelen = 0;
guint8 octet;
for (;;) {
if ( !tvb_bytes_exist( tvb, offset+valuelen, 1 ) ) {
return -1;
}
octet = tvb_get_guint8( tvb, offset+valuelen );
valuelen++;
if ( octet & 0x80 ) {
break;
}
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_value, tvb, offset, valuelen, ENC_NA );
offset += valuelen;
f4length -= valuelen;
}
if ( f4flags & RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_L ) {
if ( !tvb_bytes_exist( tvb, offset, f4length ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_legal, tvb, offset, f4length, ENC_NA );
offset += f4length;
f4length -= f4length;
}
if ( f4length > 0 ) {
if ( !tvb_bytes_exist( tvb, offset, f4length ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_data, tvb, offset, f4length, ENC_NA );
consumed += f4length;
}
return consumed;
}
static int
decode_sj_chapter_d_f5( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_field_tree;
int consumed = 0;
guint16 f5flags;
guint16 f5length;
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
f5flags = tvb_get_ntohs( tvb, offset );
f5length = f5flags & RTP_MIDI_SJ_CHAPTER_D_SYSCOM_MASK_LENGTH;
ti = proto_tree_add_text( tree, tvb, offset, f5length, RTP_MIDI_TREE_NAME_SJ_CHAPTER_D_FIELD_K );
rtp_midi_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_d_field_k );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_sflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_cflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_vflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_lflag, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_dsz, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_length, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
consumed += 2;
f5length -= 2;
if ( f5flags & RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_C ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
f5length--;
}
if ( f5flags & RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_V ) {
int valuelen = 0;
guint8 octet;
for (;;) {
if ( !tvb_bytes_exist( tvb, offset+valuelen, 1 ) ) {
return -1;
}
octet = tvb_get_guint8( tvb, offset+valuelen );
valuelen++;
if ( octet & 0x80 ) {
break;
}
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_value, tvb, offset, valuelen, ENC_NA );
offset += valuelen;
f5length -= valuelen;
}
if ( f5flags & RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_L ) {
if ( !tvb_bytes_exist( tvb, offset, f5length ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_legal, tvb, offset, f5length, ENC_NA );
offset += f5length;
f5length -= f5length;
}
if ( f5length > 0 ) {
if ( !tvb_bytes_exist( tvb, offset, f5length ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_syscom_data, tvb, offset, f5length, ENC_NA );
consumed += f5length;
}
return consumed;
}
static int
decode_sj_chapter_d_f9( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_field_tree;
int consumed = 0;
guint8 f9flags;
guint8 f9length;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
f9flags = tvb_get_guint8( tvb, offset );
f9length = f9flags & RTP_MIDI_SJ_CHAPTER_D_SYSREAL_MASK_LENGTH;
ti = proto_tree_add_text( tree, tvb, offset, f9length, RTP_MIDI_TREE_NAME_SJ_CHAPTER_D_FIELD_Y );
rtp_midi_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_d_field_y );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_cflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_lflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_length, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
f9length--;
if ( f9flags & RTP_MIDI_SJ_CHAPTER_D_SYSREAL_FLAG_C ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
f9length--;
}
if ( f9flags & RTP_MIDI_SJ_CHAPTER_D_SYSREAL_FLAG_L ) {
if ( !tvb_bytes_exist( tvb, offset, f9length ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_legal, tvb, offset, f9length, ENC_NA );
offset += f9length;
f9length -= f9length;
}
if ( f9length > 0 ) {
if ( !tvb_bytes_exist( tvb, offset, f9length ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_data, tvb, offset, f9length, ENC_NA );
consumed += f9length;
}
return consumed;
}
static int
decode_sj_chapter_d_fd( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_field_tree;
int consumed = 0;
guint8 fdflags;
guint8 fdlength;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
fdflags = tvb_get_guint8( tvb, offset );
fdlength = fdflags & RTP_MIDI_SJ_CHAPTER_D_SYSREAL_MASK_LENGTH;
ti = proto_tree_add_text( tree, tvb, offset, fdlength, RTP_MIDI_TREE_NAME_SJ_CHAPTER_D_FIELD_Z );
rtp_midi_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_d_field_z );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_cflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_lflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_length, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
fdlength--;
if ( fdflags & RTP_MIDI_SJ_CHAPTER_D_SYSREAL_FLAG_C ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
fdlength--;
}
if ( fdflags & RTP_MIDI_SJ_CHAPTER_D_SYSREAL_FLAG_L ) {
if ( !tvb_bytes_exist( tvb, offset, fdlength ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_legal, tvb, offset, fdlength, ENC_NA );
offset += fdlength;
fdlength -= fdlength;
}
if ( fdlength > 0 ) {
if ( !tvb_bytes_exist( tvb, offset, fdlength ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_sysreal_data, tvb, offset, fdlength, ENC_NA );
consumed += fdlength;
}
return consumed;
}
static int
decode_sj_chapter_d( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_item *tix;
proto_tree *rtp_midi_sj_chapter_tree;
proto_tree *rtp_midi_field_tree;
guint8 header;
int consumed = 0;
int ext_consumed;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
header = tvb_get_guint8( tvb, offset );
tix = proto_tree_add_text( tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_SJ_CHAPTER_D );
rtp_midi_sj_chapter_tree = proto_item_add_subtree( tix, ett_rtp_midi_sj_chapter_d );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_d_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_d_bflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_d_gflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_d_hflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_d_jflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_d_kflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_d_yflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_d_zflag, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
if ( header & RTP_MIDI_SJ_CHAPTER_D_FLAG_B ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_sj_chapter_tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_SJ_CHAPTER_D_FIELD_B );
rtp_midi_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_d_field_b );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_reset_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_reset_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
if ( header & RTP_MIDI_SJ_CHAPTER_D_FLAG_G ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_sj_chapter_tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_SJ_CHAPTER_D_FIELD_G );
rtp_midi_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_d_field_g );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_tune_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_tune_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
if ( header & RTP_MIDI_SJ_CHAPTER_D_FLAG_H ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_sj_chapter_tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_SJ_CHAPTER_D_FIELD_H );
rtp_midi_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_d_field_h );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_song_sel_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_field_tree, hf_rtp_midi_sj_chapter_d_song_sel_value, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
if ( header & RTP_MIDI_SJ_CHAPTER_D_FLAG_J ) {
ext_consumed = decode_sj_chapter_d_f4( tvb, pinfo, rtp_midi_sj_chapter_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( header & RTP_MIDI_SJ_CHAPTER_D_FLAG_K ) {
ext_consumed = decode_sj_chapter_d_f5( tvb, pinfo, rtp_midi_sj_chapter_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( header & RTP_MIDI_SJ_CHAPTER_D_FLAG_Y ) {
ext_consumed = decode_sj_chapter_d_f9( tvb, pinfo, rtp_midi_sj_chapter_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( header & RTP_MIDI_SJ_CHAPTER_D_FLAG_Z ) {
ext_consumed = decode_sj_chapter_d_fd( tvb, pinfo, rtp_midi_sj_chapter_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
}
proto_item_set_len( tix, consumed );
return consumed;
}
static int
decode_sj_chapter_q( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_sj_chapter_tree;
guint8 header;
int consumed = 0;
int len = 1;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
header = tvb_get_guint8( tvb, offset );
if ( header & RTP_MIDI_SJ_CHAPTER_Q_FLAG_C ) {
len += 2;
}
if ( header & RTP_MIDI_SJ_CHAPTER_Q_FLAG_T ) {
len += 3;
}
ti = proto_tree_add_text( tree, tvb, offset, len, RTP_MIDI_TREE_NAME_SJ_CHAPTER_Q );
rtp_midi_sj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_q );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_q_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_q_nflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_q_dflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_q_cflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_q_tflag, tvb, offset, 1, ENC_BIG_ENDIAN );
if ( header & RTP_MIDI_SJ_CHAPTER_Q_FLAG_C ) {
if ( !tvb_bytes_exist( tvb, offset, 3 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_q_clock, tvb, offset, 3, ENC_BIG_ENDIAN );
consumed += 3;
offset += 3;
} else {
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_q_top, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
}
if ( header & RTP_MIDI_SJ_CHAPTER_Q_FLAG_T ) {
if ( !tvb_bytes_exist( tvb, offset, 3 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_q_timetools, tvb, offset, 3, ENC_BIG_ENDIAN );
consumed += 3;
}
return consumed;
}
static int
decode_sj_chapter_f( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_sj_chapter_tree;
proto_tree *rtp_midi_sj_field_tree;
guint8 header;
int consumed = 0;
int len = 1;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
header = tvb_get_guint8( tvb, offset );
if ( header & RTP_MIDI_SJ_CHAPTER_F_FLAG_C ) {
len += 4;
}
if ( header & RTP_MIDI_SJ_CHAPTER_F_FLAG_P ) {
len += 4;
}
ti = proto_tree_add_text( tree, tvb, offset, len, RTP_MIDI_TREE_NAME_SJ_CHAPTER_F );
rtp_midi_sj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_f );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_f_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_f_cflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_f_pflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_f_qflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_f_dflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_f_point, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
if ( header & RTP_MIDI_SJ_CHAPTER_F_FLAG_C ) {
if ( !tvb_bytes_exist( tvb, offset, 4 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_sj_chapter_tree, tvb, offset, 4, RTP_MIDI_TREE_NAME_SJ_CHAPTER_F_COMPLETE );
rtp_midi_sj_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_f_complete );
if ( header & RTP_MIDI_SJ_CHAPTER_F_FLAG_Q ) {
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt0, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt1, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt2, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt3, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt4, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt5, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt6, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt7, tvb, offset, 4, ENC_BIG_ENDIAN );
} else {
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_hr, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mn, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_sc, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_fr, tvb, offset, 4, ENC_BIG_ENDIAN );
}
consumed += 4;
offset += 4;
}
if ( header & RTP_MIDI_SJ_CHAPTER_F_FLAG_P ) {
if ( !tvb_bytes_exist( tvb, offset, 4 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_sj_chapter_tree, tvb, offset, 4, RTP_MIDI_TREE_NAME_SJ_CHAPTER_F_PARTIAL );
rtp_midi_sj_field_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_f_partial );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt0, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt1, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt2, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt3, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt4, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt5, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt6, tvb, offset, 4, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_field_tree, hf_rtp_midi_sj_chapter_f_mt7, tvb, offset, 4, ENC_BIG_ENDIAN );
consumed += 4;
}
return consumed;
}
static int
decode_sj_chapter_x( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset, unsigned int max_length ) {
proto_item *ti;
proto_tree *rtp_midi_sj_chapter_tree;
proto_tree *rtp_midi_sj_data_tree;
guint8 header;
guint8 octet;
unsigned int consumed = 0;
unsigned long cmdlen = 0;
unsigned int i;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
header = tvb_get_guint8( tvb, offset );
ti = proto_tree_add_text( tree, tvb, offset, max_length, RTP_MIDI_TREE_NAME_SJ_CHAPTER_X );
rtp_midi_sj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_x );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_tflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_cflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_fflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_dflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_lflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_sta, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
if ( header & RTP_MIDI_SJ_CHAPTER_X_FLAG_T ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_tcount, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
}
if ( header & RTP_MIDI_SJ_CHAPTER_X_FLAG_C ) {
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_count, tvb, offset, 1, ENC_BIG_ENDIAN );
consumed++;
offset++;
}
if ( header & RTP_MIDI_SJ_CHAPTER_X_FLAG_F ) {
unsigned long field = 0;
unsigned long fieldlen = 0;
for ( i=0; i < 4; i++ ) {
if ( ( !( consumed >= max_length ) ) || ( !tvb_bytes_exist( tvb, offset + fieldlen, 1 ) ) ) {
return -1;
}
octet = tvb_get_guint8( tvb, offset + fieldlen );
field = ( field << 7 ) | ( octet & RTP_MIDI_DELTA_TIME_OCTET_MASK );
fieldlen++;
if ( ( octet & RTP_MIDI_DELTA_TIME_EXTENSION ) == 0 ) {
break;
}
}
switch (fieldlen) {
case 1:
proto_tree_add_uint ( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_first1, tvb, offset, fieldlen, field );
break;
case 2:
proto_tree_add_uint ( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_first2, tvb, offset, fieldlen, field );
break;
case 3:
proto_tree_add_uint ( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_first3, tvb, offset, fieldlen, field );
break;
case 4:
proto_tree_add_uint ( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_x_first4, tvb, offset, fieldlen, field );
break;
}
consumed += fieldlen;
offset += fieldlen;
}
if ( header & RTP_MIDI_SJ_CHAPTER_X_FLAG_D ) {
ti = proto_tree_add_text( rtp_midi_sj_chapter_tree, tvb, offset, max_length - consumed, RTP_MIDI_TREE_NAME_SJ_CHAPTER_X_DATA );
rtp_midi_sj_data_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_x_data );
while ( consumed < max_length ) {
octet = tvb_get_guint8( tvb, offset + cmdlen );
if ( octet & 0x80 ) {
proto_tree_add_item( rtp_midi_sj_data_tree, hf_rtp_midi_sj_chapter_x_data, tvb, offset, cmdlen, ENC_NA );
offset += cmdlen;
cmdlen = 0;
}
consumed += 1;
}
if ( cmdlen ) {
proto_tree_add_item( rtp_midi_sj_data_tree, hf_rtp_midi_sj_chapter_x_invalid_data, tvb, offset, cmdlen, ENC_NA );
offset += cmdlen;
}
}
if ( consumed < max_length ) {
ti = proto_tree_add_text( rtp_midi_sj_chapter_tree, tvb, offset, max_length - consumed, RTP_MIDI_TREE_NAME_SJ_CHAPTER_X_INVALID_DATA );
rtp_midi_sj_data_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_x_data );
proto_tree_add_item( rtp_midi_sj_data_tree, hf_rtp_midi_sj_chapter_x_invalid_data, tvb, offset, max_length - consumed, ENC_NA );
consumed = max_length;
}
return consumed;
}
static int
decode_system_journal( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, unsigned int offset ) {
proto_item *ti;
proto_tree *rtp_midi_sysjournal_tree;
proto_tree *rtp_midi_sj_chapters_tree;
int consumed = 0;
int ext_consumed = 0;
guint16 sysjourlen;
guint16 systemflags;
if ( !tvb_bytes_exist( tvb, offset, 2 ) ) {
return -1;
}
systemflags = tvb_get_ntohs( tvb, offset );
sysjourlen = systemflags & RTP_MIDI_SJ_MASK_LENGTH;
ti = proto_tree_add_text( tree, tvb, offset, sysjourlen, RTP_MIDI_TREE_NAME_SYSTEM_JOURNAL );
rtp_midi_sysjournal_tree = proto_item_add_subtree( ti, ett_rtp_midi_systemjournal );
proto_tree_add_item( rtp_midi_sysjournal_tree, hf_rtp_midi_sysjour_toc_s, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sysjournal_tree, hf_rtp_midi_sysjour_toc_d, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sysjournal_tree, hf_rtp_midi_sysjour_toc_v, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sysjournal_tree, hf_rtp_midi_sysjour_toc_q, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sysjournal_tree, hf_rtp_midi_sysjour_toc_f, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sysjournal_tree, hf_rtp_midi_sysjour_toc_x, tvb, offset, 2, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sysjournal_tree, hf_rtp_midi_sysjour_len, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
consumed += 2;
ti = proto_tree_add_text( rtp_midi_sysjournal_tree, tvb, offset, sysjourlen - 2, RTP_MIDI_TREE_NAME_SYSTEM_CHAPTERS );
rtp_midi_sj_chapters_tree = proto_item_add_subtree( ti, ett_rtp_midi_systemchapters );
if ( systemflags & RTP_MIDI_SJ_FLAG_D ) {
ext_consumed = decode_sj_chapter_d( tvb, pinfo, rtp_midi_sj_chapters_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( systemflags & RTP_MIDI_SJ_FLAG_V ) {
proto_tree *rtp_midi_sj_chapter_tree;
if ( !tvb_bytes_exist( tvb, offset, 1 ) ) {
return -1;
}
ti = proto_tree_add_text( rtp_midi_sj_chapters_tree, tvb, offset, 1, RTP_MIDI_TREE_NAME_SJ_CHAPTER_V );
rtp_midi_sj_chapter_tree = proto_item_add_subtree( ti, ett_rtp_midi_sj_chapter_v );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_v_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_sj_chapter_tree, hf_rtp_midi_sj_chapter_v_count, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
consumed++;
}
if ( systemflags & RTP_MIDI_SJ_FLAG_Q ) {
ext_consumed = decode_sj_chapter_q( tvb, pinfo, rtp_midi_sj_chapters_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( systemflags & RTP_MIDI_SJ_FLAG_F ) {
ext_consumed = decode_sj_chapter_f( tvb, pinfo, rtp_midi_sj_chapters_tree, offset );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
offset += ext_consumed;
}
if ( consumed <= sysjourlen ) {
return -1;
}
if ( systemflags & RTP_MIDI_SJ_FLAG_X ) {
ext_consumed = decode_sj_chapter_x( tvb, pinfo, rtp_midi_sj_chapters_tree, offset, sysjourlen - consumed );
if ( ext_consumed < 0 ) {
return ext_consumed;
}
consumed += ext_consumed;
}
if ( consumed != sysjourlen ) {
return -1;
}
return consumed;
}
static void
dissect_rtp_midi( tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree )
{
proto_item *ti;
proto_tree *rtp_midi_tree;
unsigned int offset = 0;
guint8 flags;
unsigned int cmd_len;
unsigned int cmd_count;
guint8 runningstatus;
int consumed;
unsigned int rsoffset = 0;
guint8 totchan;
unsigned int i;
col_set_str( pinfo->cinfo, COL_PROTOCOL, RTP_MIDI_DISSECTOR_SHORTNAME );
col_clear( pinfo->cinfo, COL_INFO );
flags = tvb_get_guint8( tvb, offset );
ti = proto_tree_add_item( tree, proto_rtp_midi, tvb, 0, -1, ENC_NA );
rtp_midi_tree = proto_item_add_subtree( ti, ett_rtp_midi);
proto_tree_add_item( rtp_midi_tree, hf_rtp_midi_bflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_tree, hf_rtp_midi_jflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_tree, hf_rtp_midi_zflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_tree, hf_rtp_midi_pflag, tvb, offset, 1, ENC_BIG_ENDIAN );
cmd_len = flags & RTP_MIDI_CS_MASK_SHORTLEN;
if (flags & RTP_MIDI_CS_FLAG_B) {
guint8 octet;
octet = tvb_get_guint8( tvb, offset+1 );
cmd_len = ( cmd_len << 8 ) | octet;
proto_tree_add_item( rtp_midi_tree, hf_rtp_midi_longlen, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
} else {
proto_tree_add_item( rtp_midi_tree, hf_rtp_midi_shortlen, tvb, offset, 1, ENC_BIG_ENDIAN );
offset++;
}
if ( cmd_len ) {
proto_item *command_item;
proto_tree *rtp_midi_commands_tree;
command_item = proto_tree_add_text( rtp_midi_tree, tvb, offset, cmd_len, RTP_MIDI_TREE_NAME_COMMAND );
rtp_midi_commands_tree = proto_item_add_subtree( command_item, ett_rtp_midi_commands );
if ( !tvb_bytes_exist( tvb, offset, cmd_len ) ) {
THROW( ReportedBoundsError );
return;
}
cmd_count = 0;
runningstatus = 0;
while ( cmd_len) {
if ( ( cmd_count ) || ( flags & RTP_MIDI_CS_FLAG_Z ) ) {
consumed = decodetime( tvb, pinfo, rtp_midi_commands_tree, offset, cmd_len );
if ( -1 == consumed ) {
THROW( ReportedBoundsError );
return;
}
offset += consumed;
cmd_len -= consumed;
}
if ( cmd_len ) {
consumed = decodemidi( tvb, pinfo, rtp_midi_commands_tree, cmd_count, offset, cmd_len, &runningstatus, &rsoffset );
if ( -1 == consumed ) {
THROW( ReportedBoundsError );
return;
}
offset += consumed;
cmd_len -= consumed;
cmd_count++;
}
}
}
if ( flags & RTP_MIDI_CS_FLAG_J ) {
proto_item *journal_item;
proto_tree *rtp_midi_journal_tree;
journal_item = proto_tree_add_text( rtp_midi_tree, tvb, offset, -1, RTP_MIDI_TREE_NAME_JOURNAL );
rtp_midi_journal_tree = proto_item_add_subtree( journal_item, ett_rtp_midi_journal );
flags = tvb_get_guint8( tvb, offset );
proto_tree_add_item( rtp_midi_journal_tree, hf_rtp_midi_sflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_journal_tree, hf_rtp_midi_yflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_journal_tree, hf_rtp_midi_aflag, tvb, offset, 1, ENC_BIG_ENDIAN );
proto_tree_add_item( rtp_midi_journal_tree, hf_rtp_midi_hflag, tvb, offset, 1, ENC_BIG_ENDIAN );
totchan = flags & RTP_MIDI_JS_MASK_TOTALCHANNELS;
proto_tree_add_item( rtp_midi_journal_tree, hf_rtp_midi_totchan, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item( rtp_midi_journal_tree, hf_rtp_midi_check_seq_num, tvb, offset, 2, ENC_BIG_ENDIAN );
offset += 2;
if ( flags & RTP_MIDI_JS_FLAG_Y ) {
consumed = decode_system_journal( tvb, pinfo, rtp_midi_journal_tree, offset );
if ( -1 == consumed ) {
THROW( ReportedBoundsError );
return;
}
offset += consumed;
}
if ( flags & RTP_MIDI_JS_FLAG_A ) {
proto_tree *rtp_midi_chanjournals_tree;
ti = proto_tree_add_text( rtp_midi_journal_tree, tvb, offset, -1, RTP_MIDI_TREE_NAME_CHANNEL_JOURNAL );
rtp_midi_chanjournals_tree = proto_item_add_subtree( ti, ett_rtp_midi_channeljournals );
for ( i = 0; i <= totchan; i++ ) {
consumed = decode_channel_journal( tvb, pinfo, rtp_midi_chanjournals_tree, offset );
if ( -1 == consumed ) {
THROW( ReportedBoundsError );
return;
}
offset += consumed;
}
}
}
}
void
proto_register_rtp_midi( void )
{
module_t *rtp_midi_module;
static hf_register_info hf[] = {
{
&hf_rtp_midi_bflag,
{
"B-Flag",
"rtpmidi.b_flag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cs_flag_b),
RTP_MIDI_CS_FLAG_B,
NULL, HFILL
}
},
{
&hf_rtp_midi_jflag,
{
"J-Flag",
"rtpmidi.j_flag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cs_flag_j),
RTP_MIDI_CS_FLAG_J,
NULL, HFILL
}
},
{
&hf_rtp_midi_zflag,
{
"Z-Flag",
"rtpmidi.z_flag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cs_flag_z),
RTP_MIDI_CS_FLAG_Z,
NULL, HFILL
}
},
{
&hf_rtp_midi_pflag,
{
"P-Flag",
"rtpmidi.p_flag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cs_flag_p),
RTP_MIDI_CS_FLAG_P,
NULL, HFILL
}
},
{
&hf_rtp_midi_shortlen,
{
"Command length (short)",
"rtpmidi.cmd_length_short",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_CS_MASK_SHORTLEN,
NULL, HFILL
}
},
{
&hf_rtp_midi_longlen,
{
"Command length (long)",
"rtpmidi.cmd_length_long",
FT_UINT16,
BASE_DEC,
NULL,
RTP_MIDI_CS_MASK_LONGLEN,
NULL, HFILL
}
},
{
&hf_rtp_midi_sflag,
{
"S-Flag",
"rtpmidi.s_flag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_JS_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_yflag,
{
"Y-Flag",
"rtpmidi.y_flag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_y),
RTP_MIDI_JS_FLAG_Y,
NULL, HFILL
}
},
{
&hf_rtp_midi_aflag,
{
"A-Flag",
"rtpmidi.a_flag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_a),
RTP_MIDI_JS_FLAG_A,
NULL, HFILL
}
},
{
&hf_rtp_midi_hflag,
{
"H-Flag",
"rtpmidi.h_flag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_h),
RTP_MIDI_JS_FLAG_H,
NULL, HFILL
}
},
{
&hf_rtp_midi_totchan,
{
"Total channels",
"rtpmidi.total_channels",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_js_tot_channels),
RTP_MIDI_JS_MASK_TOTALCHANNELS,
NULL, HFILL
}
},
{
&hf_rtp_midi_check_seq_num,
{
"Checkpoint Packet Seqnum",
"rtpmidi.check_Seq_num",
FT_UINT16,
BASE_DEC,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_deltatime1,
{
"Delta Time (one octet)",
"rtpmidi.deltatime_1",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_deltatime2,
{
"Delta Time (two octets)",
"rtpmidi.deltatime_2",
FT_UINT16,
BASE_HEX,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_deltatime3,
{
"Delta Time (three octets)",
"rtpmidi.deltatime_3",
FT_UINT24,
BASE_HEX,
NULL,
0x7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_deltatime4,
{
"Delta Time (four octets)",
"rtpmidi.deltatime_4",
FT_UINT32,
BASE_HEX,
NULL,
0x7f7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_channel_status,
{
"Channel Status",
"rtpmidi.channel_status",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_channel_status),
0xf0,
NULL, HFILL
}
},
{
&hf_rtp_midi_common_status,
{
"Common Status",
"rtpmidi.common_status",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_common_status),
0xff,
NULL, HFILL
}
},
{
&hf_rtp_midi_channel,
{
"Channel",
"rtpmidi.channel",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_channels),
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_note,
{
"Note",
"rtpmidi.note",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_note_values),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_velocity,
{
"Velocity",
"rtpmidi.velocity",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_pressure,
{
"Pressure",
"rtpmidi.pressure",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_controller,
{
"Controller",
"rtpevent.controller",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_controller_values),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_controller_value,
{
"Value",
"rtpmidi.controller_value",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_program,
{
"Program",
"rtpmidi.program",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_channel_pressure,
{
"Pressure",
"rtpmidi.channel_pressure",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_pitch_bend,
{
"Pitch Bend",
"rtpmidi.pitch_bend",
FT_UINT16,
BASE_DEC,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_pitch_bend_truncated,
{
"Pitch Bend (truncated)",
"rtpmidi.pitch_bend_truncated",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_manu_short,
{
"Manufacturer (short)",
"rtpmidi.manufacturer_short",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_manu_short_values),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_manu_long,
{
"Manufacturer (long)",
"rtpmidi.manufacturer_long",
FT_UINT16,
BASE_HEX,
VALS(rtp_midi_manu_long_values),
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysjour_toc_s,
{
"System-Journal TOC-S-Flag",
"rtpmidi.sysjour_toc_s",
FT_BOOLEAN,
16,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysjour_toc_d,
{
"System-Journal TOC-D-Flag",
"rtpmidi.sysjour_toc_d",
FT_BOOLEAN,
16,
TFS(&rtp_midi_sj_flag_d),
RTP_MIDI_SJ_FLAG_D,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysjour_toc_v,
{
"System-Journal TOC-V-Flag",
"rtpmidi.sysjour_toc_v",
FT_BOOLEAN,
16,
TFS(&rtp_midi_sj_flag_v),
RTP_MIDI_SJ_FLAG_V,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysjour_toc_q,
{
"System-Journal TOC-Q-Flag",
"rtpmidi.sysjour_toc_q",
FT_BOOLEAN,
16,
TFS(&rtp_midi_sj_flag_q),
RTP_MIDI_SJ_FLAG_Q,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysjour_toc_f,
{
"System-Journal TOC-F-Flag",
"rtpmidi.sysjour_toc_f",
FT_BOOLEAN,
16,
TFS(&rtp_midi_sj_flag_f),
RTP_MIDI_SJ_FLAG_F,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysjour_toc_x,
{
"System-Journal TOC-X-Flag",
"rtpmidi.sysjour_toc_x",
FT_BOOLEAN,
16,
TFS(&rtp_midi_sj_flag_x),
RTP_MIDI_SJ_FLAG_X,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysjour_len,
{
"System-Journal-Length",
"rtpmidi.cmd_sysjour_len",
FT_UINT16,
BASE_DEC,
NULL,
RTP_MIDI_SJ_MASK_LENGTH,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_sflag,
{
"Channel-Journal S-Flag",
"rtpmidi.chanjour_s",
FT_BOOLEAN,
24,
TFS(&rtp_midi_js_flag_s),
0x800000,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_chan,
{
"Channel",
"rtpmidi.chanjour_channel",
FT_UINT24,
BASE_HEX,
VALS(rtp_midi_channels),
0x780000,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_hflag,
{
"Channel-Journal H-Flag",
"rtpmidi.chanjour_h",
FT_BOOLEAN,
24,
TFS(&rtp_midi_js_flag_h),
0x040000,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_len,
{
"Channel-Journal-Length",
"rtpmidi.cmd_chanjour_len",
FT_UINT24,
BASE_DEC,
NULL,
0x03FF00,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_toc_p,
{
"Channel-Journal TOC-P-Flag",
"rtpmidi.chanjour_toc_p",
FT_BOOLEAN,
24,
TFS(&rtp_midi_cj_flag_p),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_toc_c,
{
"Channel-Journal TOC-C-Flag",
"rtpmidi.chanjour_toc_c",
FT_BOOLEAN,
24,
TFS(&rtp_midi_cj_flag_c),
0x40,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_toc_m,
{
"Channel-Journal TOC-M-Flag",
"rtpmidi.chanjour_toc_m",
FT_BOOLEAN,
24,
TFS(&rtp_midi_cj_flag_m),
0x20,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_toc_w,
{
"Channel-Journal TOC-W-Flag",
"rtpmidi.chanjour_toc_w",
FT_BOOLEAN,
24,
TFS(&rtp_midi_cj_flag_w),
0x10,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_toc_n,
{
"Channel-Journal TOC-N-Flag",
"rtpmidi.chanjour_toc_n",
FT_BOOLEAN,
24,
TFS(&rtp_midi_cj_flag_n),
0x08,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_toc_e,
{
"Channel-Journal TOC-E-Flag",
"rtpmidi.chanjour_toc_e",
FT_BOOLEAN,
24,
TFS(&rtp_midi_cj_flag_e),
0x04,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_toc_t,
{
"Channel-Journal TOC-T-Flag",
"rtpmidi.chanjour_toc_t",
FT_BOOLEAN,
24,
TFS(&rtp_midi_cj_flag_t),
0x02,
NULL, HFILL
}
},
{
&hf_rtp_midi_chanjour_toc_a,
{
"Channel-Journal TOC-A-Flag",
"rtpmidi.chanjour_toc_a",
FT_BOOLEAN,
24,
TFS(&rtp_midi_cj_flag_a),
0x01,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_p_sflag,
{
"Chapter P S-Flag",
"rtpmidi.cj_chapter_p_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_p_program,
{
"Chapter P Program",
"rtpmidi.cj_chapter_p_program",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_p_bflag,
{
"Chapter P B-Flag",
"rtpmidi.cj_chapter_p_bflag",
FT_BOOLEAN,
8,
NULL,
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_p_bank_msb,
{
"Chapter P Bank-MSB",
"rtpmidi.cj_chapter_p_bank_msb",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_p_xflag,
{
"Chapter P X-Flag",
"rtpmidi.cj_chapter_p_xflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_p_log_flag_x),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_p_bank_lsb,
{
"Chapter P Bank-LSB",
"rtpmidi.cj_chapter_p_bank_lsb",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_c_sflag,
{
"Chapter C S-Flag",
"rtpmidi.cj_chapter_c_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_c_length,
{
"Chapter C Length",
"rtpmidi.cj_chapter_c_length",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_c_number,
{
"Chapter C Number",
"rtpmidi.cj_chapter_c_number",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_controller_values),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_c_aflag,
{
"Chapter C A-Flag",
"rtpmidi.cj_chapter_c_aflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_c_flag_a),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_c_tflag,
{
"Chapter C T-Flag",
"rtpmidi.cj_chapter_c_tflag",
FT_BOOLEAN,
8,
NULL,
0x40,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_c_value,
{
"Chapter C Value",
"rtpmidi.cj_chapter_c_value",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_c_alt,
{
"Chapter C Alt",
"rtpmidi.cj_chapter_c_alt",
FT_UINT8,
BASE_HEX,
NULL,
0x3f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_sflag,
{
"Chapter M S-Flag",
"rtpmidi.cj_chapter_m_sflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_js_flag_s),
0x8000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_pflag,
{
"Chapter M P-Flag",
"rtpmidi.cj_chapter_m_pflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_flag_p),
0x4000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_eflag,
{
"Chapter M E-Flag",
"rtpmidi.cj_chapter_m_eflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_flag_e),
0x2000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_uflag,
{
"Chapter M U-Flag",
"rtpmidi.cj_chapter_m_uflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_flag_u),
0x1000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_wflag,
{
"Chapter M W-Flag",
"rtpmidi.cj_chapter_m_wflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_flag_w),
0x0800,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_zflag,
{
"Chapter M Z-Flag",
"rtpmidi.cj_chapter_m_zflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_flag_z),
0x0400,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_length,
{
"Chapter M Length",
"rtpmidi.cj_chapter_m_length",
FT_UINT16,
BASE_DEC,
NULL,
0x03ff,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_qflag,
{
"Chapter M Q-Flag",
"rtpmidi.cj_chapter_m_qflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_flag_q),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_pending,
{
"Chapter M Pending",
"rtpmidi.cj_chapter_m_pending",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_sflag,
{
"Chapter M Log S-Flag",
"rtpmidi.cj_chapter_m_log_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_pnum_lsb,
{
"Chapter M Log PNUM-LSB",
"rtpmidi.cj_chapter_m_log_pnum_lsb",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_qflag,
{
"Chapter M Log Q-Flag",
"rtpmidi.cj_chapter_m_log_qflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_q),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_pnum_msb,
{
"Chapter M Log PNUM-MSB",
"rtpmidi.cj_chapter_m_log_pnum_msb",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_jflag,
{
"Chapter M Log J-Flag",
"rtpmidi.cj_chapter_m_log_jflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_j),
RTP_MIDI_CJ_CHAPTER_M_FLAG_J,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_kflag,
{
"Chapter M Log K-Flag",
"rtpmidi.cj_chapter_m_log_kflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_k),
RTP_MIDI_CJ_CHAPTER_M_FLAG_K,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_lflag,
{
"Chapter M Log L-Flag",
"rtpmidi.cj_chapter_m_log_lflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_l),
RTP_MIDI_CJ_CHAPTER_M_FLAG_L,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_mflag,
{
"Chapter M Log M-Flag",
"rtpmidi.cj_chapter_m_log_mflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_m),
RTP_MIDI_CJ_CHAPTER_M_FLAG_M,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_nflag,
{
"Chapter M Log N-Flag",
"rtpmidi.cj_chapter_m_log_nflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_n),
RTP_MIDI_CJ_CHAPTER_M_FLAG_N,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_tflag,
{
"Chapter M Log T-Flag",
"rtpmidi.cj_chapter_m_log_tflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_t),
RTP_MIDI_CJ_CHAPTER_M_FLAG_T,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_vflag,
{
"Chapter M Log V-Flag",
"rtpmidi.cj_chapter_m_log_vflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_v),
RTP_MIDI_CJ_CHAPTER_M_FLAG_V,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_rflag,
{
"Chapter M Log R-Flag",
"rtpmidi.cj_chapter_m_log_rflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_r),
RTP_MIDI_CJ_CHAPTER_M_FLAG_R,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_msb_x,
{
"Chapter M Log MSB X-Flag",
"rtpmidi.cj_chapter_m_log_msb_xflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_x),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_msb,
{
"Chapter M Log MSB",
"rtpmidi.cj_chapter_m_log_msb",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_lsb_x,
{
"Chapter M Log LSB X-Flag",
"rtpmidi.cj_chapter_m_log_lsb_xflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_x),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_lsb,
{
"Chapter M Log LSB",
"rtpmidi.cj_chapter_m_log_lsb",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_a_button_g,
{
"Chapter M Log A-Button G-Flag",
"rtpmidi.cj_chapter_m_log_a_button_gflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_log_flag_g),
0x8000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_a_button_x,
{
"Chapter M Log A-Button X-Flag",
"rtpmidi.cj_chapter_m_log_a_button_xflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_log_flag_x),
0x4000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_a_button,
{
"Chapter M Log A-Button",
"rtpmidi.cj_chapter_m_log_a_button",
FT_UINT16,
BASE_HEX,
NULL,
0x3fff,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_c_button_g,
{
"Chapter M Log C-Button G-Flag",
"rtpmidi.cj_chapter_m_log_c_button_gflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_log_flag_g),
0x8000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_c_button_r,
{
"Chapter M Log C-Button R-Flag",
"rtpmidi.cj_chapter_m_log_c_button_rflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_cj_chapter_m_log_flag_r),
0x4000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_c_button,
{
"Chapter M Log C-Button",
"rtpmidi.cj_chapter_m_log_c_button",
FT_UINT16,
BASE_HEX,
NULL,
0x3fff,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_count_x,
{
"Chapter M Log Count X-Flag",
"rtpmidi.cj_chapter_m_log_count_xflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_x),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_m_log_count,
{
"Chapter M Log Count",
"rtpmidi.cj_chapter_m_log_count",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_w_sflag,
{
"Chapter W S-Flag",
"rtpmidi.cj_chapter_w_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_w_first,
{
"Chapter W First",
"rtpmidi.cj_chapter_w_first",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_w_rflag,
{
"Chapter W R-Flag",
"rtpmidi.cj_chapter_w_rflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_m_log_flag_r),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_w_second,
{
"Chapter W Second",
"rtpmidi.cj_chapter_w_second",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_bflag,
{
"Chapter N B-Flag",
"rtpmidi.cj_chapter_n_bflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_js_flag_s),
0x8000,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_len,
{
"Chapter N Length",
"rtpmidi.cj_chapter_n_length",
FT_UINT16,
BASE_DEC,
NULL,
0x7f00,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_low,
{
"Chapter N Low",
"rtpmidi.cj_chapter_n_low",
FT_UINT16,
BASE_DEC,
NULL,
0x00f0,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_high,
{
"Chapter N High",
"rtpmidi.cj_chapter_n_high",
FT_UINT16,
BASE_DEC,
NULL,
0x000f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_log_sflag,
{
"Chapter N Log S-Flag",
"rtpmidi.cj_chapter_n_log_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_log_notenum,
{
"Chapter N Log Note",
"rtpmidi.cj_chapter_n_log_note",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_note_values),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_log_yflag,
{
"Chapter N Log Y-Flag",
"rtpmidi.cj_chapter_n_log_yflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_n_log_flag_y),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_log_velocity,
{
"Chapter N Log Velocity",
"rtpmidi.cj_chapter_n_log_velocity",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_n_log_octet,
{
"Chapter N Log Octet",
"rtpmidi.cj_chapter_n_log_octet",
FT_UINT8,
BASE_HEX,
NULL,
0xff,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_e_sflag,
{
"Chapter E S-Flag",
"rtpmidi.cj_chapter_e_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_e_len,
{
"Chapter E Length",
"rtpmidi.cj_chapter_e_length",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_e_log_sflag,
{
"Chapter E Log S-Flag",
"rtpmidi.cj_chapter_e_log_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_e_log_notenum,
{
"Chapter E Log Note",
"rtpmidi.cj_chapter_e_log_note",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_note_values),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_e_log_vflag,
{
"Chapter N Log V-Flag",
"rtpmidi.cj_chapter_n_log_vflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_e_log_flag_v),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_e_log_velocity,
{
"Chapter E Log Velocity",
"rtpmidi.cj_chapter_e_log_velocity",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_e_log_count,
{
"Chapter E Log Count",
"rtpmidi.cj_chapter_e_log_count",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_t_sflag,
{
"Chapter T S-Flag",
"rtpmidi.cj_chapter_t_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_t_pressure,
{
"Chapter T Pressure",
"rtpmidi.cj_chapter_t_pressure",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_a_sflag,
{
"Chapter A S-Flag",
"rtpmidi.cj_chapter_a_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_a_len,
{
"Chapter A Length",
"rtpmidi.cj_chapter_a_length",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_a_log_sflag,
{
"Chapter A Log S-Flag",
"rtpmidi.cj_chapter_a_log_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_a_log_notenum,
{
"Chapter A Log Note",
"rtpmidi.cj_chapter_a_log_note",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_note_values),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_a_log_xflag,
{
"Chapter A Log X-Flag",
"rtpmidi.cj_chapter_a_log_xflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_cj_chapter_a_log_flag_x),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_cj_chapter_a_log_pressure,
{
"Chapter A Log Pressure",
"rtpmidi.cj_chapter_a_log_pressure",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_v_sflag,
{
"Chapter V S-Flag",
"rtpmidi.sj_chapter_v_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
0x80,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_v_count,
{
"Chapter V Count",
"rtpmidi.sj_chapter_v_count",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_sflag,
{
"Chapter D S-Flag",
"rtpmidi.sj_chapter_d_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_D_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_bflag,
{
"Chapter D B-Flag",
"rtpmidi.sj_chapter_d_bflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_flag_b),
RTP_MIDI_SJ_CHAPTER_D_FLAG_B,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_gflag,
{
"Chapter D G-Flag",
"rtpmidi.sj_chapter_d_gflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_flag_g),
RTP_MIDI_SJ_CHAPTER_D_FLAG_G,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_hflag,
{
"Chapter D H-Flag",
"rtpmidi.sj_chapter_d_hflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_flag_h),
RTP_MIDI_SJ_CHAPTER_D_FLAG_H,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_jflag,
{
"Chapter D J-Flag",
"rtpmidi.sj_chapter_d_jflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_flag_j),
RTP_MIDI_SJ_CHAPTER_D_FLAG_J,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_kflag,
{
"Chapter D K-Flag",
"rtpmidi.sj_chapter_d_kflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_flag_k),
RTP_MIDI_SJ_CHAPTER_D_FLAG_K,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_yflag,
{
"Chapter D Y-Flag",
"rtpmidi.sj_chapter_d_yflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_flag_y),
RTP_MIDI_SJ_CHAPTER_D_FLAG_Y,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_zflag,
{
"Chapter D Z-Flag",
"rtpmidi.sj_chapter_d_zflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_flag_z),
RTP_MIDI_SJ_CHAPTER_D_FLAG_Z,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_reset_sflag,
{
"Chapter D Reset S-Flag",
"rtpmidi.sj_chapter_d_reset_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_D_RESET_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_reset_count,
{
"Chapter D Reset Count",
"rtpmidi.cj_chapter_d_reset_count",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_D_RESET_COUNT,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_tune_sflag,
{
"Chapter D Tune Request S-Flag",
"rtpmidi.sj_chapter_d_tune_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_D_TUNE_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_tune_count,
{
"Chapter D Tune Request Count",
"rtpmidi.cj_chapter_d_tune_count",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_D_TUNE_COUNT,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_song_sel_sflag,
{
"Chapter D Song Select S-Flag",
"rtpmidi.sj_chapter_d_song_sel_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_D_SONG_SEL_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_song_sel_value,
{
"Chapter D Song Select Value",
"rtpmidi.cj_chapter_d_song_sel_value",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_D_SONG_SEL_VALUE,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_sflag,
{
"Chapter D System Common (F4/F5) S-Flag",
"rtpmidi.sj_chapter_d_syscom_sflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_cflag,
{
"Chapter D System Common (F4/F5) C-Flag",
"rtpmidi.sj_chapter_d_syscom_cflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_sj_chapter_d_syscom_flag_c),
RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_C,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_vflag,
{
"Chapter D System Common (F4/F5) V-Flag",
"rtpmidi.sj_chapter_d_syscom_vflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_sj_chapter_d_syscom_flag_v),
RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_V,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_lflag,
{
"Chapter D System Common (F4/F5) L-Flag",
"rtpmidi.sj_chapter_d_syscom_lflag",
FT_BOOLEAN,
16,
TFS(&rtp_midi_sj_chapter_d_syscom_flag_l),
RTP_MIDI_SJ_CHAPTER_D_SYSCOM_FLAG_L,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_dsz,
{
"Chapter D System Common (F4/F5) DSZ",
"rtpmidi.sj_chapter_d_syscom_dsz",
FT_UINT16,
BASE_DEC,
VALS(rtp_midi_sj_chapter_d_syscom_dsz_values),
RTP_MIDI_SJ_CHAPTER_D_SYSCOM_MASK_DSZ,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_length,
{
"Chapter D System Common (F4/F5) Length",
"rtpmidi.sj_chapter_d_syscom_len",
FT_UINT16,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_D_SYSCOM_MASK_LENGTH,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_count,
{
"Chapter D System Common (F4/F5) Count",
"rtpmidi.sj_chapter_d_syscom_count",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_D_SYSCOM_MASK_COUNT,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_value,
{
"Chapter D System Common (F4/F5) Value",
"rtpmidi.sj_chapter_d_syscom_value",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_legal,
{
"Chapter D System Common (F4/F5) Legal - for future extension",
"rtpmidi.sj_chapter_d_syscom_legal",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_syscom_data,
{
"Chapter D System Common (F4/F5) Erroneous Data",
"rtpmidi.sj_chapter_d_syscom_data",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_sysreal_sflag,
{
"Chapter D System Realtime (F9/FD) S-Flag",
"rtpmidi.sj_chapter_d_sysreal_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_D_SYSREAL_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_sysreal_cflag,
{
"Chapter D System Realtime (F9/FF) C-Flag",
"rtpmidi.sj_chapter_d_sysreal_cflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_syscom_flag_c),
RTP_MIDI_SJ_CHAPTER_D_SYSREAL_FLAG_C,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_sysreal_lflag,
{
"Chapter D System Realtime (F9/FD) L-Flag",
"rtpmidi.sj_chapter_d_sysreal_lflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_d_syscom_flag_l),
RTP_MIDI_SJ_CHAPTER_D_SYSREAL_FLAG_L,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_sysreal_length,
{
"Chapter D System Realtime (F9/FD) Length",
"rtpmidi.sj_chapter_d_sysreal_len",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_D_SYSREAL_MASK_LENGTH,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_sysreal_count,
{
"Chapter D System Realtime (F9/FD) Count",
"rtpmidi.sj_chapter_d_sysreal_count",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_D_SYSREAL_MASK_COUNT,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_sysreal_legal,
{
"Chapter D System Realtime (F9/FD) Legal - for future extension",
"rtpmidi.sj_chapter_d_sysreal_legal",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_d_sysreal_data,
{
"Chapter D System Realtime (F9/FD) Erroneous Data",
"rtpmidi.sj_chapter_d_sysreal_data",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_q_sflag,
{
"Chapter Q Sequencer State S-Flag",
"rtpmidi.sj_chapter_q_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_Q_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_q_nflag,
{
"Chapter Q Sequencer State N-Flag",
"rtpmidi.sj_chapter_q_nflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_q_flag_n),
RTP_MIDI_SJ_CHAPTER_Q_FLAG_N,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_q_dflag,
{
"Chapter Q Sequencer State D-Flag",
"rtpmidi.sj_chapter_q_dflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_q_flag_d),
RTP_MIDI_SJ_CHAPTER_Q_FLAG_D,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_q_cflag,
{
"Chapter Q Sequencer State C-Flag",
"rtpmidi.sj_chapter_q_cflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_q_flag_c),
RTP_MIDI_SJ_CHAPTER_Q_FLAG_C,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_q_tflag,
{
"Chapter Q Sequencer State T-Flag",
"rtpmidi.sj_chapter_q_tflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_q_flag_t),
RTP_MIDI_SJ_CHAPTER_Q_FLAG_T,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_q_top,
{
"Chapter Q Sequencer State Top",
"rtpmidi.sj_chapter_q_top",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_Q_MASK_TOP,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_q_clock,
{
"Chapter Q Sequencer State Clock",
"rtpmidi.sj_chapter_q_clock",
FT_UINT24,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_Q_MASK_CLOCK,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_q_timetools,
{
"Chapter Q Sequencer State Timetools",
"rtpmidi.sj_chapter_q_timetools",
FT_UINT24,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_Q_MASK_TIMETOOLS,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_sflag,
{
"Chapter F MTC S-Flag",
"rtpmidi.sj_chapter_f_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_F_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_cflag,
{
"Chapter F MTC C-Flag",
"rtpmidi.sj_chapter_f_cflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_f_flag_c),
RTP_MIDI_SJ_CHAPTER_F_FLAG_C,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_pflag,
{
"Chapter F MTC P-Flag",
"rtpmidi.sj_chapter_f_pflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_f_flag_p),
RTP_MIDI_SJ_CHAPTER_F_FLAG_P,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_qflag,
{
"Chapter F MTC Q-Flag",
"rtpmidi.sj_chapter_f_qflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_f_flag_q),
RTP_MIDI_SJ_CHAPTER_F_FLAG_Q,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_dflag,
{
"Chapter F MTC D-Flag",
"rtpmidi.sj_chapter_f_dflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_f_flag_d),
RTP_MIDI_SJ_CHAPTER_F_FLAG_D,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_point,
{
"Chapter F MTC Point",
"rtpmidi.sj_chapter_f_point",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_POINT,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mt0,
{
"Chapter F MTC MT0",
"rtpmidi.sj_chapter_f_mt0",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MT0,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mt1,
{
"Chapter F MTC MT1",
"rtpmidi.sj_chapter_f_mt1",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MT1,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mt2,
{
"Chapter F MTC MT2",
"rtpmidi.sj_chapter_f_mt2",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MT2,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mt3,
{
"Chapter F MTC MT3",
"rtpmidi.sj_chapter_f_mt3",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MT3,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mt4,
{
"Chapter F MTC MT4",
"rtpmidi.sj_chapter_f_mt4",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MT4,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mt5,
{
"Chapter F MTC MT5",
"rtpmidi.sj_chapter_f_mt5",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MT5,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mt6,
{
"Chapter F MTC MT6",
"rtpmidi.sj_chapter_f_mt6",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MT6,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mt7,
{
"Chapter F MTC MT7",
"rtpmidi.sj_chapter_f_mt7",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MT7,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_hr,
{
"Chapter F MTC Hour",
"rtpmidi.sj_chapter_f_hr",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_HR,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_mn,
{
"Chapter F MTC Minute",
"rtpmidi.sj_chapter_f_mn",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_MN,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_sc,
{
"Chapter F MTC Second",
"rtpmidi.sj_chapter_f_sc",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_SC,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_f_fr,
{
"Chapter F MTC Frame",
"rtpmidi.sj_chapter_f_fr",
FT_UINT32,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_F_MASK_FR,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_sflag,
{
"Chapter X Sysex S-Flag",
"rtpmidi.sj_chapter_x_sflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_js_flag_s),
RTP_MIDI_SJ_CHAPTER_X_FLAG_S,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_tflag,
{
"Chapter X Sysex T-Flag",
"rtpmidi.sj_chapter_x_tflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_x_flag_t),
RTP_MIDI_SJ_CHAPTER_X_FLAG_T,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_cflag,
{
"Chapter X Sysex C-Flag",
"rtpmidi.sj_chapter_x_cflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_x_flag_c),
RTP_MIDI_SJ_CHAPTER_X_FLAG_C,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_fflag,
{
"Chapter X Sysex F-Flag",
"rtpmidi.sj_chapter_x_fflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_x_flag_f),
RTP_MIDI_SJ_CHAPTER_X_FLAG_F,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_dflag,
{
"Chapter X Sysex D-Flag",
"rtpmidi.sj_chapter_x_dflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_x_flag_d),
RTP_MIDI_SJ_CHAPTER_X_FLAG_D,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_lflag,
{
"Chapter X Sysex L-Flag",
"rtpmidi.sj_chapter_x_lflag",
FT_BOOLEAN,
8,
TFS(&rtp_midi_sj_chapter_x_flag_l),
RTP_MIDI_SJ_CHAPTER_X_FLAG_L,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_sta,
{
"Chapter X Sysex STA",
"rtpmidi.sj_chapter_x_sta",
FT_UINT8,
BASE_HEX,
NULL,
RTP_MIDI_SJ_CHAPTER_X_MASK_STA,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_tcount,
{
"Chapter X Sysex TCOUT",
"rtpmidi.sj_chapter_x_tcount",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_X_MASK_TCOUNT,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_count,
{
"Chapter X Sysex COUNT",
"rtpmidi.sj_chapter_x_count",
FT_UINT8,
BASE_DEC,
NULL,
RTP_MIDI_SJ_CHAPTER_X_MASK_COUNT,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_first1,
{
"Chapter X Sysex FIRST (one octet)",
"rtpmidi.sj_chapter_x_first_1",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_first2,
{
"Chapter X Sysex FIRST (two octets)",
"rtpmidi.sj_chapter_x_first_2",
FT_UINT16,
BASE_HEX,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_first3,
{
"Chapter X Sysex FIRST (three octets)",
"rtpmidi.sj_chapter_x_first_3",
FT_UINT24,
BASE_HEX,
NULL,
0x7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_first4,
{
"Chapter X Sysex FIRST (four octets)",
"rtpmidi.sj_chapter_x_first_4",
FT_UINT32,
BASE_HEX,
NULL,
0x7f7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_data,
{
"Chapter X Sysex Data",
"rtpmidi.sj_chapter_x_data",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_sj_chapter_x_invalid_data,
{
"Chapter X Invalid Sysex Data",
"rtpmidi.sj_chapter_x_invalid_data",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_quarter_frame_type,
{
"MTC-quarter-frame-type",
"rtpmidi.mtc_quarter_frame_type",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_qft_values),
0x70,
NULL, HFILL
}
},
{
&hf_rtp_midi_quarter_frame_value,
{
"MTC-quarter-frame-value",
"rtpmidi.mtc_quarter_frame_value",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_spp,
{
"Song Position Pointer",
"rtpmidi.song_position_pointer",
FT_UINT16,
BASE_DEC,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_spp_truncated,
{
"Song Position Pointer (truncated)",
"rtpmidi.song_position_pointer_truncated",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_song_select,
{
"Song Select",
"rtpmidi.song_select",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_manu_data,
{
"Manufacturer specific data",
"rtpmidi.manu_data",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_edu_data,
{
"Educational command data",
"rtpmidi.edu_data",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_unknown_data,
{
"Unknown Data",
"rtpmidi.unknown_data",
FT_BYTES,
BASE_NONE,
NULL,
0x00,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_realtime,
{
"Sysex Common Realtime",
"rtpmidi.sysex_common_realtime",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_rt),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_non_realtime,
{
"Sysex Common Non-Realtime",
"rtpmidi.sysex_common_non_realtime",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_nrt),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_device_id,
{
"Sysex Common Device ID",
"rtpmidi.sysex_common_device_id",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_ext,
{
"Sysex Common Non-Realtime Sample Dump Extension",
"rtpmidi.sysex_common_non_realtime_sample_dump_ext",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_nrt_sd_ext),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_gi,
{
"Sysex Common Non-Realtime General Information",
"rtpmidi.sysex_common_non_realtime_general_information",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_nrt_gi),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd,
{
"Sysex Common Non-Realtime File Dump",
"rtpmidi.sysex_common_non_realtime_file_dump",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_nrt_fd),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_tuning,
{
"Sysex Common (Non-)Realtime Tuning",
"rtpmidi.sysex_common_tuning",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_tuning),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_gm,
{
"Sysex Common Non-Realtime General MIDI (GM)",
"rtpmidi.sysex_common_non_realtime_gm",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_nrt_gm),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_dls,
{
"Sysex Common Non-Realtime Downloadable Sounds (DLS)",
"rtpmidi.sysex_common_non_realtime_dls",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_nrt_dls),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc,
{
"Sysex Common Realtime MTC",
"rtpmidi.sysex_common_realtime_mtc",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_rt_mtc),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_sc,
{
"Sysex Common Realtime Show Control",
"rtpmidi.sysex_common_realtime_sc",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_rt_show_control),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_ni,
{
"Sysex Common Realtime Notation Information",
"rtpmidi.sysex_common_realtime_ni",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_rt_notations),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_dc,
{
"Sysex Common Realtime Device Control",
"rtpmidi.sysex_common_realtime_dc",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_rt_device_control),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_cueing,
{
"Sysex Common Realtime MTC Cueing",
"rtpmidi.sysex_common_rt_mtc_cue",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_rt_mtc_cue),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc,
{
"Sysex Common Non-Realtime MTC",
"rtpmidi.sysex_common_nrt_mtc",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_nrt_mtc),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mmc_commands,
{
"Sysex Common Realtime Machine Control Commands",
"rtpmidi.sysex_common_realtime_mmc_cmds",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_rt_mmc_commands),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mmc_responses,
{
"Sysex Common Realtime Machine Control Responses",
"rtpmidi.sysex_common_realtime_mmc_resps",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_sysex_common_rt_mmc_responses),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_gi_device_family,
{
"Sysex Common Non-Realtime General Information Device Family",
"rtpmidi.sysex_common_non_realtime_general_information_device_family",
FT_UINT16,
BASE_HEX,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_gi_device_family_member,
{
"Sysex Common Non-Realtime General Information Device Family Member",
"rtpmidi.sysex_common_non_realtime_general_information_device_family_member",
FT_UINT16,
BASE_HEX,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_gi_software_rev,
{
"Sysex Common Non-Realtime General Information Software Revision",
"rtpmidi.sysex_common_non_realtime_general_information_software_revision",
FT_UINT32,
BASE_HEX,
NULL,
0x7f7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_packet_number,
{
"Sysex Common Non-Realtime Sample Dump Packet Number",
"rtpmidi.sysex_common_non_realtime_sample_dump_packet_number",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_header_sn,
{
"Sysex Common Non-Realtime Sample Dump Sample Number",
"rtpmidi.sysex_common_non_realtime_sample_dump_sample_number",
FT_UINT16,
BASE_DEC,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_header_sf,
{
"Sysex Common Non-Realtime Sample Dump Sample Format",
"rtpmidi.sysex_common_non_realtime_sample_dump_sample_format",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_header_sp,
{
"Sysex Common Non-Realtime Sample Dump Sample Period",
"rtpmidi.sysex_common_non_realtime_sample_dump_sample_period",
FT_UINT24,
BASE_DEC,
NULL,
0x7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_header_sl,
{
"Sysex Common Non-Realtime Sample Dump Sample Length",
"rtpmidi.sysex_common_non_realtime_sample_dump_sample_length",
FT_UINT24,
BASE_DEC,
NULL,
0x7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_header_ls,
{
"Sysex Common Non-Realtime Sample Dump Loop Start",
"rtpmidi.sysex_common_non_realtime_sample_dump_loop_start",
FT_UINT24,
BASE_DEC,
NULL,
0x7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_header_le,
{
"Sysex Common Non-Realtime Sample Dump Loop End",
"rtpmidi.sysex_common_non_realtime_sample_dump_loop_end",
FT_UINT24,
BASE_DEC,
NULL,
0x7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_header_lt,
{
"Sysex Common Non-Realtime Sample Dump Loop Type",
"rtpmidi.sysex_common_non_realtime_sample_dump_loop_type",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_sysex_common_nrt_sd_lt),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_packet_count,
{
"Sysex Common Non-Realtime Sample Dump Running Packet Count",
"rtpmidi.sysex_common_non_realtime_sample_dump_packet_count",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_packet_check,
{
"Sysex Common Non-Realtime Sample Dump Checkum",
"rtpmidi.sysex_common_non_realtime_sample_dump_checksum",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_packet_data,
{
"Sysex Common Non-Realtime Sample Dump Data Byte",
"rtpmidi.sysex_common_non_realtime_sample_dump_data",
FT_BYTES,
BASE_NONE,
NULL,
0,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_sd_ext_ln,
{
"Sysex Common Non-Realtime Sample Dump LP Transmission Loop Number",
"rtpmidi.sysex_common_non_realtime_sample_dump_lp_trans_ln",
FT_UINT16,
BASE_DEC,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd_device_id,
{
"Sysex Common Non-Realtime File Dump Device ID",
"rtpmidi.sysex_common_non_realtime_fd_device_id",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd_type,
{
"Sysex Common Non-Realtime File Dump File Type",
"rtpmidi.sysex_common_non_realtime_fd_type",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd_name,
{
"Sysex Common Non-Realtime File Dump File Name",
"rtpmidi.sysex_common_non_realtime_fd_name",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd_length,
{
"Sysex Common Non-Realtime File Dump Length",
"rtpmidi.sysex_common_non_realtime_fd_length",
FT_UINT32,
BASE_DEC,
NULL,
0x7f7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd_packet_num,
{
"Sysex Common Non-Realtime File Packet Number",
"rtpmidi.sysex_common_non_realtime_fd_packet_num",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd_byte_count,
{
"Sysex Common Non-Realtime File Byte Count",
"rtpmidi.sysex_common_non_realtime_fd_byte_count",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd_packet_data,
{
"Sysex Common Non-Realtime File Packet Data",
"rtpmidi.sysex_common_non_realtime_fd_packet_data",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_fd_checksum,
{
"Sysex Common Non-Realtime File Checksum",
"rtpmidi.sysex_common_non_realtime_fd_checksum",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_tune_program,
{
"Sysex Common (Non-)Realtime Tuning Program",
"rtpmidi.sysex_common_tune_program",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_tune_name,
{
"Sysex Common (Non-)Realtime Tuning Name",
"rtpmidi.sysex_common_tune_name",
FT_STRING,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_tune_freq,
{
"Sysex Common (Non-)Realtime Tuning Frequency",
"rtpmidi.sysex_common_tune_freq",
FT_UINT24,
BASE_HEX,
NULL,
0x7f7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_tune_checksum,
{
"Sysex Common (Non-)Realtime Tuning Checksum",
"rtpmidi.sysex_common_tune_checksum",
FT_UINT8,
BASE_HEX,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_tune_changes,
{
"Sysex Common (Non-)Realtime Tuning Changes",
"rtpmidi.sysex_common_tune_changes",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_tune_note,
{
"Sysex Common (Non-)Realtime Tuning Note",
"rtpmidi.sysex_common_tune_note",
FT_UINT8,
BASE_DEC,
VALS(rtp_midi_note_values),
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_fm_type,
{
"Sysex Common Realtime MTC Full Message Type",
"rtpmidi.sysex_common_rt_mtc_fm_type",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_mtc_fm_type_values),
0x60,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_fm_hr,
{
"Sysex Common Realtime MTC Full Message Hour",
"rtpmidi.sysex_common_rt_mtc_fm_hour",
FT_UINT8,
BASE_DEC,
NULL,
0x1f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_fm_mn,
{
"Sysex Common Realtime MTC Full Message Minute",
"rtpmidi.sysex_common_rt_mtc_fm_minute",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_fm_sc,
{
"Sysex Common Realtime MTC Full Message Second",
"rtpmidi.sysex_common_rt_mtc_fm_second",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_fm_fr,
{
"Sysex Common Realtime MTC Full Message Frame",
"rtpmidi.sysex_common_rt_mtc_fm_frame",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u1,
{
"Sysex Common Realtime MTC User Bits U1",
"rtpmidi.sysex_common_rt_mtc_ub_u1",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u2,
{
"Sysex Common Realtime MTC User Bits U2",
"rtpmidi.sysex_common_rt_mtc_ub_u2",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u3,
{
"Sysex Common Realtime MTC User Bits U3",
"rtpmidi.sysex_common_rt_mtc_ub_u3",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u4,
{
"Sysex Common Realtime MTC User Bits U4",
"rtpmidi.sysex_common_rt_mtc_ub_u4",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u5,
{
"Sysex Common Realtime MTC User Bits U5",
"rtpmidi.sysex_common_rt_mtc_ub_u5",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u6,
{
"Sysex Common Realtime MTC User Bits U6",
"rtpmidi.sysex_common_rt_mtc_ub_u6",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u7,
{
"Sysex Common Realtime MTC User Bits U7",
"rtpmidi.sysex_common_rt_mtc_ub_u7",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u8,
{
"Sysex Common Realtime MTC User Bits U8",
"rtpmidi.sysex_common_rt_mtc_ub_u8",
FT_UINT8,
BASE_HEX,
NULL,
0x0f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_ub_u9,
{
"Sysex Common Realtime MTC User Bits U9",
"rtpmidi.sysex_common_rt_mtc_ub_u9",
FT_UINT8,
BASE_HEX,
NULL,
0x03,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_type,
{
"Sysex Common Non-Realtime MTC Type",
"rtpmidi.sysex_common_nrt_mtc_type",
FT_UINT8,
BASE_HEX,
VALS(rtp_midi_mtc_fm_type_values),
0x60,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_hr,
{
"Sysex Common Non-Realtime MTC Hour",
"rtpmidi.sysex_common_nrt_mtc_hour",
FT_UINT8,
BASE_DEC,
NULL,
0x1f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_mn,
{
"Sysex Common Non-Realtime MTCMinute",
"rtpmidi.sysex_common_nrt_mtc_minute",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_sc,
{
"Sysex Common Non-Realtime MTC Second",
"rtpmidi.sysex_common_nrt_mtc_second",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_fr,
{
"Sysex Common Non-Realtime MTC Frame",
"rtpmidi.sysex_common_nrt_mtc_frame",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_ff,
{
"Sysex Common Non-Realtime MTC Fractional Frame",
"rtpmidi.sysex_common_nrt_mtc_fract_frame",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_enl,
{
"Sysex Common Non-Realtime MTC Event Number (LSB)",
"rtpmidi.sysex_common_nrt_mtc_en_lsb",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_enm,
{
"Sysex Common Non-Realtime MTC Event Number (MSB)",
"rtpmidi.sysex_common_nrt_mtc_en_msb",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_nrt_mtc_add,
{
"Sysex Common Non-Realtime MTC Additional Info",
"rtpmidi.sysex_common_nrt_mtc_add",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_cue_enl,
{
"Sysex Common Realtime MTC Cue Event Number (LSB)",
"rtpmidi.sysex_common_rt_mtc_cue_en_lsb",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_cue_enm,
{
"Sysex Common Realtime MTC Cue Event Number (MSB)",
"rtpmidi.sysex_common_rt_mtc_cue_en_msb",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_mtc_cue_add,
{
"Sysex Common Realtime MTC Cue Additional Info",
"rtpmidi.sysex_common_rt_mtc_cue_add",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_ni_bar_num,
{
"Sysex Common Realtime NI Bar Number",
"rtpmidi.sysex_common_rt_ni_barnum",
FT_UINT16,
BASE_HEX,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_ni_bytes,
{
"Sysex Common Realtime NI Bytes",
"rtpmidi.sysex_common_rt_ni_bytes",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_ni_numerator,
{
"Sysex Common Realtime NI Numerator",
"rtpmidi.sysex_common_rt_ni_numerator",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_ni_denominator,
{
"Sysex Common Realtime NI Denominator",
"rtpmidi.sysex_common_rt_ni_denominator",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_ni_midi_clocks,
{
"Sysex Common Realtime NI MIDI clocks in click",
"rtpmidi.sysex_common_rt_ni_midiclock",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_ni_32nds,
{
"Sysex Common Realtime NI 32nd notes in MIDI quarter note",
"rtpmidi.sysex_common_rt_ni_32nds",
FT_UINT8,
BASE_DEC,
NULL,
0x7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_dc_volume,
{
"Sysex Common Realtime DC Volume",
"rtpmidi.sysex_common_rt_dc_volume",
FT_UINT16,
BASE_DEC,
NULL,
0x7f7f,
NULL, HFILL
}
},
{
&hf_rtp_midi_sysex_common_rt_dc_balance,
{
"Sysex Common Realtime DC Balance",
"rtpmidi.sysex_common_rt_dc_balance",
FT_UINT16,
BASE_DEC,
NULL,
0x7f7f,
NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_rtp_midi,
&ett_rtp_midi_commands,
&ett_rtp_midi_journal,
&ett_rtp_midi_command,
&ett_rtp_midi_systemjournal,
&ett_rtp_midi_channeljournals,
&ett_rtp_midi_channelchapters,
&ett_rtp_midi_cj_chapter_p,
&ett_rtp_midi_cj_chapter_c,
&ett_rtp_midi_cj_chapter_c_loglist,
&ett_rtp_midi_cj_chapter_c_logitem,
&ett_rtp_midi_cj_chapter_m,
&ett_rtp_midi_cj_chapter_m_loglist,
&ett_rtp_midi_cj_chapter_m_logitem,
&ett_rtp_midi_cj_chapter_m_log_msb,
&ett_rtp_midi_cj_chapter_m_log_lsb,
&ett_rtp_midi_cj_chapter_m_log_a_button,
&ett_rtp_midi_cj_chapter_m_log_c_button,
&ett_rtp_midi_cj_chapter_m_log_count,
&ett_rtp_midi_cj_chapter_w,
&ett_rtp_midi_cj_chapter_n,
&ett_rtp_midi_cj_chapter_n_loglist,
&ett_rtp_midi_cj_chapter_n_logitem,
&ett_rtp_midi_cj_chapter_n_octets,
&ett_rtp_midi_cj_chapter_e,
&ett_rtp_midi_cj_chapter_e_loglist,
&ett_rtp_midi_cj_chapter_e_logitem,
&ett_rtp_midi_cj_chapter_t,
&ett_rtp_midi_cj_chapter_a,
&ett_rtp_midi_cj_chapter_a_loglist,
&ett_rtp_midi_cj_chapter_a_logitem,
&ett_rtp_midi_systemchapters,
&ett_rtp_midi_sj_chapter_d,
&ett_rtp_midi_sj_chapter_d_field_b,
&ett_rtp_midi_sj_chapter_d_field_g,
&ett_rtp_midi_sj_chapter_d_field_h,
&ett_rtp_midi_sj_chapter_d_field_j,
&ett_rtp_midi_sj_chapter_d_field_k,
&ett_rtp_midi_sj_chapter_d_field_y,
&ett_rtp_midi_sj_chapter_d_field_z,
&ett_rtp_midi_sj_chapter_v,
&ett_rtp_midi_sj_chapter_q,
&ett_rtp_midi_sj_chapter_f,
&ett_rtp_midi_sj_chapter_f_complete,
&ett_rtp_midi_sj_chapter_f_partial,
&ett_rtp_midi_sj_chapter_x,
&ett_rtp_midi_sj_chapter_x_first,
&ett_rtp_midi_sj_chapter_x_data,
&ett_rtp_midi_channeljournal,
&ett_rtp_midi_sysex_data,
&ett_rtp_midi_sysex_common_rt,
&ett_rtp_midi_sysex_common_nrt,
&ett_rtp_midi_sysex_common_tune_note,
&ett_rtp_midi_sysex_manu,
&ett_rtp_midi_sysex_edu
};
proto_rtp_midi = proto_register_protocol( RTP_MIDI_DISSECTOR_NAME, RTP_MIDI_DISSECTOR_SHORTNAME, RTP_MIDI_DISSECTOR_ABBREVIATION );
proto_register_field_array( proto_rtp_midi, hf, array_length( hf ) );
proto_register_subtree_array( ett, array_length( ett ) );
rtp_midi_module = prefs_register_protocol ( proto_rtp_midi, proto_reg_handoff_rtp_midi );
prefs_register_uint_preference ( rtp_midi_module, "midi_payload_type_value", "Payload Type for RFC 4695/6295 RTP-MIDI", "This is the value of the Payload Type field that specifies RTP-MIDI", 10, &rtp_midi_payload_type_value );
register_dissector( RTP_MIDI_DISSECTOR_ABBREVIATION, dissect_rtp_midi, proto_rtp_midi );
}
void
proto_reg_handoff_rtp_midi( void )
{
static dissector_handle_t rtp_midi_handle;
static int rtp_midi_prefs_initialized = FALSE;
if ( !rtp_midi_prefs_initialized ) {
rtp_midi_handle = find_dissector( RTP_MIDI_DISSECTOR_ABBREVIATION );
dissector_add_string("rtp_dyn_payload_type", "rtp-midi", rtp_midi_handle);
rtp_midi_prefs_initialized = TRUE;
}
else {
dissector_delete_uint( "rtp.pt", saved_payload_type_value, rtp_midi_handle );
}
if ( rtp_midi_payload_type_value > 95 ){
saved_payload_type_value = rtp_midi_payload_type_value;
dissector_add_uint( "rtp.pt", saved_payload_type_value, rtp_midi_handle );
}
}
