static unsigned short
kingfisher_checksum(tvbuff_t *tvb, int offset)
{
gint c, i, j, len;
unsigned short crc;
crc = 0;
len = tvb_reported_length_remaining(tvb, offset) - 2;
for( i = 1; i < len; i++ )
{
c = ( ( unsigned char ) tvb_get_guint8( tvb, i ) ) & 0xff;
for( j = 0; j < 8; ++j )
{
if( crc & 0x8000 )
{
crc <<= 1;
crc += ( ( ( c <<= 1 ) & 0x100 ) != 0 );
crc ^= 0x1021;
}
else
{
crc <<= 1;
crc += ( ( ( c <<= 1 ) & 0x100 ) != 0 );
}
}
}
return crc;
}
static gboolean
dissect_kingfisher(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean is_conv_dissector)
{
kingfisher_packet_t *kfp;
proto_tree *kingfisher_tree=NULL;
proto_item *item=NULL;
const char *func_string = NULL;
unsigned short checksum;
int message;
if(is_conv_dissector && (tvb_reported_length(tvb)==1)){
switch(tvb_get_guint8(tvb, 0)){
case 0x00:
case 0x01:
case 0x80:
case 0x81:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Kingfisher");
func_string = val_to_str(tvb_get_guint8(tvb, 0), function_code_vals, "Unknown function");
col_add_fstr(pinfo->cinfo, COL_INFO, "(%s)", func_string);
proto_tree_add_protocol_format(tree, proto_kingfisher, tvb, 0, -1, "Kingfisher Protocol, %s", func_string);
return TRUE;
}
return FALSE;
}
kfp=ep_alloc(sizeof(kingfisher_packet_t));
if(tvb_reported_length(tvb)<9){
return FALSE;
}
kfp->function = tvb_get_guint8( tvb, 6 );
if (match_strval(kfp->function, function_code_vals) == NULL) {
return FALSE;
}
kfp->length = tvb_get_guint8(tvb, 2);
if((kfp->length+1) != (guint8)tvb_length(tvb)){
return FALSE;
}
kfp->checksum = tvb_get_ntohs(tvb, kfp->length - 1);
checksum = kingfisher_checksum(tvb, 0);
if(kfp->checksum!=checksum){
return FALSE;
}
kfp->version = (kfp->function & 0x80)?3:2;
kfp->system = tvb_get_guint8( tvb, 0 );
kfp->message = tvb_get_guint8( tvb, 5 );
kfp->target = tvb_get_guint8( tvb, 1 );
kfp->from = tvb_get_guint8( tvb, 3 );
kfp->via = tvb_get_guint8( tvb, 4 );
if( kfp->version == 3 )
{
kfp->target |= ( tvb_get_guint8( tvb, 7 ) << 8 );
kfp->from |= ( tvb_get_guint8( tvb, 8 ) << 8 );
kfp->via |= ( tvb_get_guint8( tvb, 9 ) << 8 );
}
func_string = val_to_str(kfp->function, function_code_vals, "Unknown function");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Kingfisher");
col_add_fstr(pinfo->cinfo, COL_INFO, "%u > %u (%s)", kfp->from, kfp->target, func_string);
message = (kfp->message & 0x0f) | ((kfp->message & 0xf0) >> 4);
if(tree){
item = proto_tree_add_protocol_format(tree, proto_kingfisher, tvb, 0, -1, "Kingfisher Protocol, From RTU: %d, Target RTU: %d", kfp->from, kfp->target );
kingfisher_tree = proto_item_add_subtree( item, ett_kingfisher );
}
proto_tree_add_uint(kingfisher_tree, hf_kingfisher_version, tvb, 6, 1, kfp->version);
proto_tree_add_uint_format(kingfisher_tree, hf_kingfisher_system, tvb, 0, 1, kfp->system, "System Identifier: %u (0x%02X)", kfp->system, kfp->system);
proto_tree_add_uint_format(kingfisher_tree, hf_kingfisher_target, tvb, 1, 1, kfp->target, "Target RTU: %u (0x%02X)", kfp->target, kfp->target);
proto_tree_add_uint_format(kingfisher_tree, hf_kingfisher_length, tvb, 2, 1, kfp->length, "Length: %u (0x%02X)", kfp->length, kfp->length);
proto_tree_add_uint_format(kingfisher_tree, hf_kingfisher_from, tvb, 3, 1, kfp->from, "From RTU: %u (0x%02X)", kfp->from, kfp->from);
proto_tree_add_uint_format(kingfisher_tree, hf_kingfisher_via, tvb, 4, 1, kfp->via, "Via RTU: %u (0x%02X)", kfp->via, kfp->via);
proto_tree_add_uint_format(kingfisher_tree, hf_kingfisher_message, tvb, 5, 1, kfp->message, "Message Number: %u (0x%02X, %s)", message, kfp->message, ((kfp->message & 0xf0)?"Response":"Request"));
proto_tree_add_uint_format(kingfisher_tree, hf_kingfisher_function, tvb, 6, 1, kfp->function, "Message Function Code: %u (0x%02X, %s)", kfp->function, kfp->function, func_string);
if(kfp->length > ((kfp->version==3)?11:8)){
proto_tree_add_text(kingfisher_tree, tvb, ((kfp->version==3)?10:7), kfp->length - ((kfp->version==3)?11:8), "Message Data");
}
proto_tree_add_uint_format(kingfisher_tree, hf_kingfisher_checksum, tvb, kfp->length-1, 2, kfp->checksum, "Checksum: 0x%04X [%s]", kfp->checksum, ((checksum != kfp->checksum)?"incorrect":"correct"));
return TRUE;
}
static gboolean
dissect_kingfisher_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gboolean was_kingfisher;
was_kingfisher=dissect_kingfisher(tvb, pinfo, tree, FALSE);
if(was_kingfisher){
conversation_t *conversation;
conversation = find_or_create_conversation(pinfo);
conversation_set_dissector(conversation, kingfisher_conv_handle);
}
return was_kingfisher;
}
static gboolean
dissect_kingfisher_conv(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
return dissect_kingfisher(tvb, pinfo, tree, TRUE);
}
void
proto_register_kingfisher( void )
{
static hf_register_info hf[] =
{
{ &hf_kingfisher_version, { "Version", "kingfisher.version", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_kingfisher_system, { "System Identifier", "kingfisher.system", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_kingfisher_length, { "Length", "kingfisher.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_kingfisher_from, { "From RTU", "kingfisher.from", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_kingfisher_target, { "Target RTU", "kingfisher.target", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_kingfisher_via, { "Via RTU", "kingfisher.via", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_kingfisher_message, { "Message Number", "kingfisher.message", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_kingfisher_function, { "Function Code", "kingfisher.function", FT_UINT8, BASE_DEC, VALS( function_code_vals ), 0x0, NULL, HFILL } },
{ &hf_kingfisher_checksum, { "Checksum", "kingfisher.checksum", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_kingfisher
};
proto_kingfisher = proto_register_protocol( "Kingfisher", "Kingfisher", "kf" );
proto_register_field_array( proto_kingfisher, hf, array_length( hf ) );
proto_register_subtree_array( ett, array_length( ett ) );
}
void
proto_reg_handoff_kingfisher( void )
{
dissector_handle_t kingfisher_handle=NULL;
kingfisher_handle = new_create_dissector_handle(dissect_kingfisher_heur, proto_kingfisher);
dissector_add_uint("tcp.port", TCP_PORT_KINGFISHER, kingfisher_handle);
dissector_add_uint("udp.port", UDP_PORT_KINGFISHER, kingfisher_handle);
#ifdef SUPPORT_KINGFISHER_SERIES_2
dissector_add_uint("tcp.port", TCP_PORT_KINGFISHER_OLD, kingfisher_handle);
dissector_add_uint("udp.port", UDP_PORT_KINGFISHER_OLD, kingfisher_handle);
#endif
kingfisher_conv_handle = new_create_dissector_handle(dissect_kingfisher_conv, proto_kingfisher);
}
