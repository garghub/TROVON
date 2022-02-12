void
capture_ax25_kiss( const guchar *pd, int offset, int len, packet_counts *ld)
{
int l_offset;
guint8 kiss_cmd;
if ( ! BYTES_ARE_IN_FRAME( offset, len, KISS_HEADER_SIZE ) )
{
ld->other++;
return;
}
l_offset = offset;
kiss_cmd = pd[ l_offset ];
l_offset += KISS_HEADER_SIZE;
switch ( kiss_cmd & KISS_CMD_MASK )
{
case KISS_DATA_FRAME : capture_ax25( pd, l_offset, len, ld ); break;
case KISS_TXDELAY : break;
case KISS_PERSISTENCE : break;
case KISS_SLOT_TIME : break;
case KISS_TXTAIL : break;
case KISS_FULLDUPLEX : break;
case KISS_SETHARDWARE : break;
case KISS_RETURN : break;
default : break;
}
}
static void
dissect_ax25_kiss( tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree )
{
proto_item *ti;
proto_tree *kiss_tree;
int offset;
int kiss_cmd;
int kiss_type;
int kiss_port;
int kiss_param;
int kiss_param_len;
const char *frame_type_text;
char *info_buffer;
tvbuff_t *next_tvb = NULL;
info_buffer = (char *)wmem_alloc( wmem_packet_scope(), STRLEN );
info_buffer[0] = '\0';
col_set_str( pinfo->cinfo, COL_PROTOCOL, "AX.25 KISS" );
col_clear( pinfo->cinfo, COL_INFO );
offset = 0;
kiss_cmd = tvb_get_guint8( tvb, offset ) & 0xff;
kiss_type = kiss_cmd & KISS_CMD_MASK;
kiss_port = (kiss_cmd & KISS_PORT_MASK) >> 4;
offset += KISS_HEADER_SIZE;
kiss_param = 0;
kiss_param_len = 0;
switch ( kiss_type )
{
case KISS_TXDELAY : kiss_param_len = 1; kiss_param = tvb_get_guint8( tvb, offset ) & 0xff; break;
case KISS_PERSISTENCE : kiss_param_len = 1; kiss_param = tvb_get_guint8( tvb, offset ) & 0xff; break;
case KISS_SLOT_TIME : kiss_param_len = 1; kiss_param = tvb_get_guint8( tvb, offset ) & 0xff; break;
case KISS_TXTAIL : kiss_param_len = 1; kiss_param = tvb_get_guint8( tvb, offset ) & 0xff; break;
case KISS_FULLDUPLEX : kiss_param_len = 1; kiss_param = tvb_get_guint8( tvb, offset ) & 0xff; break;
case KISS_SETHARDWARE : kiss_param_len = 1; kiss_param = tvb_get_guint8( tvb, offset ) & 0xff; break;
default : break;
}
frame_type_text = val_to_str(kiss_type, kiss_frame_types, "Unknown (%u)");
g_snprintf( info_buffer, STRLEN, "%s, Port %u", frame_type_text, kiss_port );
if ( kiss_param_len > 0 )
g_snprintf( info_buffer, STRLEN, "%s %u, Port %u", frame_type_text, kiss_param, kiss_port );
offset += kiss_param_len;
col_add_str( pinfo->cinfo, COL_INFO, info_buffer );
if ( parent_tree )
{
offset = 0;
ti = proto_tree_add_protocol_format( parent_tree, proto_ax25_kiss, tvb, offset,
KISS_HEADER_SIZE + kiss_param_len,
"KISS: %s",
info_buffer
);
kiss_tree = proto_item_add_subtree( ti, ett_ax25_kiss );
proto_tree_add_uint( kiss_tree, hf_ax25_kiss_cmd, tvb, offset, KISS_HEADER_SIZE,
kiss_cmd );
proto_tree_add_uint( kiss_tree, hf_ax25_kiss_port, tvb, offset, KISS_HEADER_SIZE,
kiss_port );
offset += KISS_HEADER_SIZE;
switch ( kiss_type )
{
case KISS_DATA_FRAME : break;
case KISS_TXDELAY :
proto_tree_add_uint( kiss_tree, hf_ax25_kiss_txdelay,
tvb, offset, kiss_param_len, kiss_param );
offset += kiss_param_len;
break;
case KISS_PERSISTENCE :
proto_tree_add_uint( kiss_tree, hf_ax25_kiss_persistence,
tvb, offset, kiss_param_len, kiss_param );
offset += kiss_param_len;
break;
case KISS_SLOT_TIME :
proto_tree_add_uint( kiss_tree, hf_ax25_kiss_slottime,
tvb, offset, kiss_param_len, kiss_param );
offset += kiss_param_len;
break;
case KISS_TXTAIL :
proto_tree_add_uint( kiss_tree, hf_ax25_kiss_txtail,
tvb, offset, kiss_param_len, kiss_param );
offset += kiss_param_len;
break;
case KISS_FULLDUPLEX :
proto_tree_add_uint( kiss_tree, hf_ax25_kiss_fullduplex,
tvb, offset, kiss_param_len, kiss_param );
offset += kiss_param_len;
break;
case KISS_SETHARDWARE :
proto_tree_add_uint( kiss_tree, hf_ax25_kiss_sethardware,
tvb, offset, kiss_param_len, kiss_param );
offset += kiss_param_len;
break;
case KISS_RETURN : break;
default : break;
}
}
if ( kiss_type == KISS_DATA_FRAME )
{
next_tvb = tvb_new_subset_remaining( tvb, offset );
call_dissector( ax25_handle, next_tvb, pinfo, parent_tree );
}
}
void
proto_register_ax25_kiss(void)
{
static hf_register_info hf[] = {
{ &hf_ax25_kiss_cmd,
{ "Cmd", "ax25_kiss.cmd",
FT_UINT8, BASE_DEC, VALS(kiss_frame_types), KISS_CMD_MASK,
NULL, HFILL }
},
{ &hf_ax25_kiss_port,
{ "Port", "ax25_kiss.port",
FT_UINT8, BASE_DEC, NULL, KISS_PORT_MASK,
NULL, HFILL }
},
{ &hf_ax25_kiss_txdelay,
{ "Tx delay", "ax25_kiss.txdelay",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax25_kiss_persistence,
{ "Persistence", "ax25_kiss.persistence",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax25_kiss_slottime,
{ "Slot time", "ax25_kiss.slottime",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax25_kiss_txtail,
{ "Tx tail", "ax25_kiss.txtail",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax25_kiss_fullduplex,
{ "Full duplex", "ax25_kiss.fullduplex",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_ax25_kiss_sethardware,
{ "Set hardware", "ax25_kiss.sethardware",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_ax25_kiss,
};
proto_ax25_kiss = proto_register_protocol( "AX.25 KISS", "AX.25 KISS", "ax25_kiss" );
kiss_handle = register_dissector( "ax25_kiss", dissect_ax25_kiss, proto_ax25_kiss );
proto_register_field_array( proto_ax25_kiss, hf, array_length( hf ) );
proto_register_subtree_array( ett, array_length( ett ) );
}
void
proto_reg_handoff_ax25_kiss(void)
{
dissector_add_uint( "wtap_encap", WTAP_ENCAP_AX25_KISS, kiss_handle );
ax25_handle = find_dissector( "ax25" );
}
