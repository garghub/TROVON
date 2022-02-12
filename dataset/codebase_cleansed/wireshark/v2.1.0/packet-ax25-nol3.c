static int
dissect_dx(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_)
{
proto_item *ti;
proto_tree *dx_tree;
int data_len;
int offset;
offset = 0;
data_len = tvb_reported_length_remaining( tvb, offset );
col_set_str( pinfo->cinfo, COL_PROTOCOL, "DX" );
col_add_fstr( pinfo->cinfo, COL_INFO, "%s", tvb_format_text( tvb, offset, 15 ) );
if ( parent_tree )
{
ti = proto_tree_add_protocol_format( parent_tree, proto_dx, tvb, 0, -1,
"DX (%s)", tvb_format_text( tvb, offset, 15 ) );
dx_tree = proto_item_add_subtree( ti, ett_dx );
offset = 0;
proto_tree_add_item( dx_tree, hf_dx_report, tvb, offset, data_len, ENC_ASCII|ENC_NA );
}
return tvb_captured_length(tvb);
}
static gboolean
isaprs( guint8 dti )
{
gboolean b = FALSE;
switch ( dti )
{
case 0x1c :
case 0x1d :
case '!' :
case '#' :
case '$' :
case '%' :
case '&' :
case ')' :
case '*' :
case '+' :
case ',' :
case '.' :
case '/' :
case ':' :
case ';' :
case '<' :
case '=' :
case '>' :
case '?' :
case '@' :
case 'T' :
case '[' :
case '\'' :
case '_' :
case '`' :
case '{' :
case '}' : b = TRUE; break;
default : break;
}
return b;
}
static int
dissect_ax25_nol3(tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree, void* data _U_ )
{
proto_item *ti;
proto_tree *ax25_nol3_tree;
char *info_buffer;
int offset;
tvbuff_t *next_tvb = NULL;
guint8 dti = 0;
gboolean dissected;
info_buffer = (char *)wmem_alloc( wmem_packet_scope(), STRLEN );
info_buffer[0] = '\0';
col_set_str( pinfo->cinfo, COL_PROTOCOL, "AX.25-NoL3");
col_clear( pinfo->cinfo, COL_INFO);
offset = 0;
g_snprintf( info_buffer, STRLEN, "Text" );
if ( gPREF_APRS )
{
dti = tvb_get_guint8( tvb, offset );
if ( isaprs( dti ) )
g_snprintf( info_buffer, STRLEN, "APRS" );
}
if ( gPREF_DX )
{
if ( tvb_get_guint8( tvb, offset ) == 'D' && tvb_get_guint8( tvb, offset + 1 ) == 'X' )
g_snprintf( info_buffer, STRLEN, "DX cluster" );
}
col_add_str( pinfo->cinfo, COL_INFO, info_buffer );
ti = proto_tree_add_protocol_format( parent_tree,
proto_ax25_nol3,
tvb,
0,
-1,
"AX.25 No Layer 3 - (%s)", info_buffer );
ax25_nol3_tree = proto_item_add_subtree( ti, ett_ax25_nol3 );
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissected = FALSE;
if ( gPREF_APRS )
{
if ( isaprs( dti ) )
{
dissected = TRUE;
call_dissector( aprs_handle , next_tvb, pinfo, ax25_nol3_tree );
}
}
if ( gPREF_DX )
{
if ( tvb_get_guint8( tvb, offset ) == 'D' && tvb_get_guint8( tvb, offset + 1 ) == 'X' )
{
dissected = TRUE;
dissect_dx( next_tvb, pinfo, ax25_nol3_tree, NULL );
}
}
if ( ! dissected )
call_data_dissector(next_tvb, pinfo, ax25_nol3_tree );
return tvb_captured_length(tvb);
}
void
proto_register_ax25_nol3(void)
{
module_t *ax25_nol3_module;
#if 0
static hf_register_info hf[] = {
{ &hf_text,
{ "Text", "ax25_nol3.text",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
#endif
static hf_register_info hf_dx[] = {
{ &hf_dx_report,
{ "DX", "ax25_nol3.dx",
FT_STRING, BASE_NONE, NULL, 0x0,
"DX cluster", HFILL }
},
};
static gint *ett[] = {
&ett_ax25_nol3,
&ett_dx,
};
proto_ax25_nol3 = proto_register_protocol("AX.25 no Layer 3", "AX.25 no L3", "ax25_nol3");
proto_register_subtree_array( ett, array_length( ett ) );
ax25_nol3_module = prefs_register_protocol( proto_ax25_nol3, NULL);
prefs_register_bool_preference(ax25_nol3_module, "showaprs",
"Decode the APRS info field",
"Enable decoding of the payload as APRS.",
&gPREF_APRS );
prefs_register_bool_preference(ax25_nol3_module, "showcluster",
"Decode DX cluster info field",
"Enable decoding of the payload as DX cluster info.",
&gPREF_DX );
proto_dx = proto_register_protocol("DX cluster", "DX", "dx");
register_dissector( "dx", dissect_dx, proto_dx);
proto_register_field_array( proto_dx, hf_dx, array_length( hf_dx ) );
}
void
proto_reg_handoff_ax25_nol3(void)
{
dissector_add_uint( "ax25.pid", AX25_P_NO_L3, create_dissector_handle( dissect_ax25_nol3, proto_ax25_nol3 ) );
aprs_handle = find_dissector_add_dependency( "aprs", proto_ax25_nol3 );
}
