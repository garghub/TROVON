static gboolean
packet_is_cigi(tvbuff_t *tvb)
{
guint8 packet_id;
guint8 packet_size;
guint8 cigi_version_local;
guint8 ig_mode;
guint16 byte_swap;
if (tvb_length(tvb) < 3) {
return FALSE;
}
packet_size = tvb_get_guint8(tvb, 1);
if ( packet_size > tvb_reported_length(tvb) ) {
return FALSE;
}
packet_id = tvb_get_guint8(tvb, 0);
cigi_version_local = tvb_get_guint8(tvb, 2);
switch ( cigi_version_local ) {
case CIGI_VERSION_1:
switch ( packet_id ) {
case 1:
if ( packet_size != 16 ) {
return FALSE;
}
if (!tvb_bytes_exist(tvb, 4, 1)) {
return FALSE;
}
ig_mode = (tvb_get_guint8(tvb, 4) & 0xc0) >> 6;
if ( ig_mode > 2 ) {
return FALSE;
}
break;
case 101:
if ( packet_size != 12 ) {
return FALSE;
}
break;
default:
return FALSE;
}
break;
case CIGI_VERSION_2:
switch ( packet_id ) {
case CIGI2_PACKET_ID_IG_CONTROL:
if ( packet_size != CIGI2_PACKET_SIZE_IG_CONTROL ) {
return FALSE;
}
if (!tvb_bytes_exist(tvb, 4, 1)) {
return FALSE;
}
ig_mode = (tvb_get_guint8(tvb, 4) & 0xc0) >> 6;
if ( ig_mode > 2 ) {
return FALSE;
}
break;
case CIGI2_PACKET_ID_START_OF_FRAME:
if ( packet_size != CIGI2_PACKET_SIZE_START_OF_FRAME ) {
return FALSE;
}
break;
default:
return FALSE;
}
break;
case CIGI_VERSION_3:
if (!tvb_bytes_exist(tvb, 6, 1)) {
return FALSE;
}
switch ( packet_id ) {
case CIGI3_PACKET_ID_IG_CONTROL:
if ( packet_size != CIGI3_PACKET_SIZE_IG_CONTROL ) {
if ( packet_size != CIGI3_2_PACKET_SIZE_IG_CONTROL ) {
return FALSE;
}
}
if (!tvb_bytes_exist(tvb, 4, 2)) {
return FALSE;
}
ig_mode = (tvb_get_guint8(tvb, 4) & 0x03);
if ( ig_mode > 2 ) {
return FALSE;
}
break;
case CIGI3_PACKET_ID_START_OF_FRAME:
if ( packet_size != CIGI3_PACKET_SIZE_START_OF_FRAME ) {
if ( packet_size != CIGI3_2_PACKET_SIZE_START_OF_FRAME) {
return FALSE;
}
}
if (!tvb_bytes_exist(tvb, 5, 1)) {
return FALSE;
}
break;
default:
return FALSE;
}
byte_swap = tvb_get_ntohs(tvb, 6);
if ( byte_swap != CIGI3_BYTE_SWAP_BIG_ENDIAN && byte_swap != CIGI3_BYTE_SWAP_LITTLE_ENDIAN ) {
return FALSE;
}
break;
default:
return FALSE;
}
return TRUE;
}
static gboolean
dissect_cigi_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !packet_is_cigi(tvb) ) {
return FALSE;
}
dissect_cigi_pdu(tvb, pinfo, tree);
return TRUE;
}
static int
dissect_cigi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if ( !packet_is_cigi(tvb) ) {
return 0;
}
dissect_cigi_pdu(tvb, pinfo, tree);
return tvb_length(tvb);
}
static void
dissect_cigi_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 packet_id = 0;
proto_item *ti, *hidden_item;
proto_tree *cigi_tree;
const char* src_str;
const char* dest_str;
packet_id = tvb_get_guint8(tvb, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIGI");
if ( ( packet_id == CIGI2_PACKET_ID_IG_CONTROL || packet_id == CIGI2_PACKET_ID_START_OF_FRAME || packet_id == CIGI3_PACKET_ID_IG_CONTROL || packet_id == CIGI3_PACKET_ID_START_OF_FRAME ) && global_cigi_version == CIGI_VERSION_FROM_PACKET ) {
cigi_version = tvb_get_guint8(tvb, 2);
}
src_str = (const char*)ip_to_str((const guint8 *)pinfo->src.data);
if ( !g_ascii_strcasecmp(global_host_ip, src_str) ) {
src_str = "Host";
} else if ( !g_ascii_strcasecmp(global_ig_ip, src_str) ) {
src_str = "IG";
}
dest_str = (const char*)ip_to_str((const guint8 *)pinfo->dst.data);
if ( !g_ascii_strcasecmp(global_host_ip, dest_str) ) {
dest_str = "Host";
} else if ( !g_ascii_strcasecmp(global_ig_ip, dest_str) ) {
dest_str = "IG";
}
col_add_fstr(pinfo->cinfo, COL_INFO, "%s => %s (%u bytes)", src_str, dest_str,
tvb_reported_length(tvb));
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_cigi, tvb, 0, tvb_length(tvb), "Common Image Generator Interface (%i), %s => %s (%u bytes)",
cigi_version, src_str, dest_str, tvb_reported_length(tvb));
cigi_tree = proto_item_add_subtree(ti, ett_cigi);
hidden_item = proto_tree_add_uint(cigi_tree, hf_cigi_src_port, tvb, 0, 0, pinfo->srcport);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(cigi_tree, hf_cigi_dest_port, tvb, 0, 0, pinfo->destport);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(cigi_tree, hf_cigi_port, tvb, 0, 0, pinfo->srcport);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(cigi_tree, hf_cigi_port, tvb, 0, 0, pinfo->destport);
PROTO_ITEM_SET_HIDDEN(hidden_item);
hidden_item = proto_tree_add_uint(cigi_tree, hf_cigi_frame_size, tvb, 0, 0, tvb_reported_length(tvb));
PROTO_ITEM_SET_HIDDEN(hidden_item);
if ( cigi_version == CIGI_VERSION_2 ) {
cigi2_add_tree(tvb, cigi_tree);
} else if ( cigi_version == CIGI_VERSION_3 ) {
cigi3_add_tree(tvb, cigi_tree);
} else {
cigi_add_tree(tvb, cigi_tree);
}
}
}
static void
cigi_add_tree(tvbuff_t *tvb, proto_tree *cigi_tree)
{
gint offset = 0;
gint length = 0;
gint packet_id = 0;
gint packet_size = 0;
gint data_size = 0;
proto_tree* cigi_packet_tree = NULL;
proto_item* tipacket;
length = tvb_length(tvb);
while ( offset < length ) {
packet_id = tvb_get_guint8(tvb, offset);
packet_size = tvb_get_guint8(tvb, offset + 1);
data_size = packet_size;
if ( packet_size < 2 ) {
THROW(ReportedBoundsError);
}
if ( ( packet_id == 1 || packet_id == 101 ) && global_cigi_version == CIGI_VERSION_FROM_PACKET ) {
cigi_version = tvb_get_guint8(tvb, 2);
}
tipacket = proto_tree_add_string_format(cigi_tree, hf_cigi_unknown, tvb, offset, packet_size, NULL, "Unknown (%i bytes)", packet_size);
cigi_packet_tree = proto_item_add_subtree(tipacket, ett_cigi);
proto_tree_add_item(cigi_packet_tree, hf_cigi_packet_id, tvb, offset, 1, cigi_byte_order);
offset++;
data_size--;
proto_tree_add_item(cigi_packet_tree, hf_cigi_packet_size, tvb, offset, 1, cigi_byte_order);
offset++;
data_size--;
if ( packet_id == 1 || packet_id == 101 ) {
proto_tree_add_item(cigi_packet_tree, hf_cigi_version, tvb, offset, 1, cigi_byte_order);
offset++;
data_size--;
}
proto_tree_add_text(cigi_packet_tree, tvb, offset, data_size, "Data (%i bytes)", data_size );
offset += data_size;
}
}
static gint
cigi_add_data(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
guint8 packet_size = 0;
packet_size = tvb_get_guint8(tvb, offset-1);
if ( packet_size < 2 ) {
THROW(ReportedBoundsError);
}
proto_tree_add_text(tree, tvb, offset, packet_size-2, "Data (%i bytes)", packet_size-2 );
offset += packet_size-2;
return offset;
}
static void
cigi2_add_tree(tvbuff_t *tvb, proto_tree *cigi_tree)
{
gint offset = 0;
gint length = 0;
gint init_offset = 0;
gint packet_id = 0;
gint packet_size = 0;
gint packet_length = 0;
proto_tree* cigi_packet_tree = NULL;
proto_item* tipacket;
int hf_cigi2_packet = -1;
length = tvb_length(tvb);
while ( offset < length ) {
packet_id = tvb_get_guint8(tvb, offset);
packet_size = tvb_get_guint8(tvb, offset + 1);
if ( ( packet_id == CIGI2_PACKET_ID_IG_CONTROL || packet_id == CIGI2_PACKET_ID_START_OF_FRAME ) && global_cigi_version == CIGI_VERSION_FROM_PACKET ) {
cigi_version = tvb_get_guint8(tvb, 2);
}
if ( packet_id == CIGI2_PACKET_ID_IG_CONTROL ) {
hf_cigi2_packet = hf_cigi2_ig_control;
packet_length = CIGI2_PACKET_SIZE_IG_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_ENTITY_CONTROL ) {
hf_cigi2_packet = hf_cigi2_entity_control;
packet_length = CIGI2_PACKET_SIZE_ENTITY_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_COMPONENT_CONTROL ) {
hf_cigi2_packet = hf_cigi2_component_control;
packet_length = CIGI2_PACKET_SIZE_COMPONENT_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_ARTICULATED_PARTS_CONTROL ) {
hf_cigi2_packet = hf_cigi2_articulated_parts_control;
packet_length = CIGI2_PACKET_SIZE_ARTICULATED_PARTS_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_RATE_CONTROL ) {
hf_cigi2_packet = hf_cigi2_rate_control;
packet_length = CIGI2_PACKET_SIZE_RATE_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_ENVIRONMENT_CONTROL ) {
hf_cigi2_packet = hf_cigi2_environment_control;
packet_length = CIGI2_PACKET_SIZE_ENVIRONMENT_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_WEATHER_CONTROL ) {
hf_cigi2_packet = hf_cigi2_weather_control;
packet_length = CIGI2_PACKET_SIZE_WEATHER_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_VIEW_CONTROL ) {
hf_cigi2_packet = hf_cigi2_view_control;
packet_length = CIGI2_PACKET_SIZE_VIEW_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_SENSOR_CONTROL ) {
hf_cigi2_packet = hf_cigi2_sensor_control;
packet_length = CIGI2_PACKET_SIZE_SENSOR_CONTROL;
} else if ( packet_id == CIGI2_PACKET_ID_TRAJECTORY_DEFINITION ) {
hf_cigi2_packet = hf_cigi2_trajectory_definition;
packet_length = CIGI2_PACKET_SIZE_TRAJECTORY_DEFINITION;
} else if ( packet_id == CIGI2_PACKET_ID_SPECIAL_EFFECT_DEFINITION ) {
hf_cigi2_packet = hf_cigi2_special_effect_definition;
packet_length = CIGI2_PACKET_SIZE_SPECIAL_EFFECT_DEFINITION;
} else if ( packet_id == CIGI2_PACKET_ID_VIEW_DEFINITION ) {
hf_cigi2_packet = hf_cigi2_view_definition;
packet_length = CIGI2_PACKET_SIZE_VIEW_DEFINITION;
} else if ( packet_id == CIGI2_PACKET_ID_COLLISION_DETECTION_SEGMENT_DEFINITION ) {
hf_cigi2_packet = hf_cigi2_collision_detection_segment_definition;
packet_length = CIGI2_PACKET_SIZE_COLLISION_DETECTION_SEGMENT_DEFINITION;
} else if ( packet_id == CIGI2_PACKET_ID_COLLISION_DETECTION_VOLUME_DEFINITION ) {
hf_cigi2_packet = hf_cigi2_collision_detection_volume_definition;
packet_length = CIGI2_PACKET_SIZE_COLLISION_DETECTION_VOLUME_DEFINITION;
} else if ( packet_id == CIGI2_PACKET_ID_HEIGHT_ABOVE_TERRAIN_REQUEST ) {
hf_cigi2_packet = hf_cigi2_height_above_terrain_request;
packet_length = CIGI2_PACKET_SIZE_HEIGHT_ABOVE_TERRAIN_REQUEST;
} else if ( packet_id == CIGI2_PACKET_ID_LINE_OF_SIGHT_OCCULT_REQUEST ) {
hf_cigi2_packet = hf_cigi2_line_of_sight_occult_request;
packet_length = CIGI2_PACKET_SIZE_LINE_OF_SIGHT_OCCULT_REQUEST;
} else if ( packet_id == CIGI2_PACKET_ID_LINE_OF_SIGHT_RANGE_REQUEST ) {
hf_cigi2_packet = hf_cigi2_line_of_sight_range_request;
packet_length = CIGI2_PACKET_SIZE_LINE_OF_SIGHT_RANGE_REQUEST;
} else if ( packet_id == CIGI2_PACKET_ID_HEIGHT_OF_TERRAIN_REQUEST ) {
hf_cigi2_packet = hf_cigi2_height_of_terrain_request;
packet_length = CIGI2_PACKET_SIZE_HEIGHT_OF_TERRAIN_REQUEST;
} else if ( packet_id == CIGI2_PACKET_ID_START_OF_FRAME ) {
hf_cigi2_packet = hf_cigi2_start_of_frame;
packet_length = CIGI2_PACKET_SIZE_START_OF_FRAME;
} else if ( packet_id == CIGI2_PACKET_ID_HEIGHT_ABOVE_TERRAIN_RESPONSE ) {
hf_cigi2_packet = hf_cigi2_height_above_terrain_response;
packet_length = CIGI2_PACKET_SIZE_HEIGHT_ABOVE_TERRAIN_RESPONSE;
} else if ( packet_id == CIGI2_PACKET_ID_LINE_OF_SIGHT_RESPONSE ) {
hf_cigi2_packet = hf_cigi2_line_of_sight_response;
packet_length = CIGI2_PACKET_SIZE_LINE_OF_SIGHT_RESPONSE;
} else if ( packet_id == CIGI2_PACKET_ID_COLLISION_DETECTION_SEGMENT_RESPONSE ) {
hf_cigi2_packet = hf_cigi2_collision_detection_segment_response;
packet_length = CIGI2_PACKET_SIZE_COLLISION_DETECTION_SEGMENT_RESPONSE;
} else if ( packet_id == CIGI2_PACKET_ID_SENSOR_RESPONSE ) {
hf_cigi2_packet = hf_cigi2_sensor_response;
packet_length = CIGI2_PACKET_SIZE_SENSOR_RESPONSE;
} else if ( packet_id == CIGI2_PACKET_ID_HEIGHT_OF_TERRAIN_RESPONSE ) {
hf_cigi2_packet = hf_cigi2_height_of_terrain_response;
packet_length = CIGI2_PACKET_SIZE_HEIGHT_OF_TERRAIN_RESPONSE;
} else if ( packet_id == CIGI2_PACKET_ID_COLLISION_DETECTION_VOLUME_RESPONSE ) {
hf_cigi2_packet = hf_cigi2_collision_detection_volume_response;
packet_length = CIGI2_PACKET_SIZE_COLLISION_DETECTION_VOLUME_RESPONSE;
} else if ( packet_id == CIGI2_PACKET_ID_IMAGE_GENERATOR_MESSAGE ) {
hf_cigi2_packet = hf_cigi2_image_generator_message;
packet_length = packet_size;
} else if ( packet_id >= CIGI2_PACKET_ID_USER_DEFINABLE_MIN && packet_id <= CIGI2_PACKET_ID_USER_DEFINABLE_MAX ) {
hf_cigi2_packet = hf_cigi2_user_definable;
packet_length = packet_size;
} else {
hf_cigi2_packet = hf_cigi_unknown;
packet_length = packet_size;
}
tipacket = proto_tree_add_string_format(cigi_tree, hf_cigi2_packet, tvb, offset, packet_length, NULL,
"%s (%i bytes)",
val_to_str_ext_const(packet_id, &cigi2_packet_id_vals_ext, "Unknown"),
packet_length);
cigi_packet_tree = proto_item_add_subtree(tipacket, ett_cigi);
init_offset = offset;
proto_tree_add_item(cigi_packet_tree, hf_cigi2_packet_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(cigi_packet_tree, hf_cigi_packet_size, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if ( packet_id == CIGI2_PACKET_ID_IG_CONTROL ) {
offset = cigi2_add_ig_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_ENTITY_CONTROL ) {
offset = cigi2_add_entity_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_COMPONENT_CONTROL ) {
offset = cigi2_add_component_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_ARTICULATED_PARTS_CONTROL ) {
offset = cigi2_add_articulated_parts_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_RATE_CONTROL ) {
offset = cigi2_add_rate_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_ENVIRONMENT_CONTROL ) {
offset = cigi2_add_environment_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_WEATHER_CONTROL ) {
offset = cigi2_add_weather_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_VIEW_CONTROL ) {
offset = cigi2_add_view_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_SENSOR_CONTROL ) {
offset = cigi2_add_sensor_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_TRAJECTORY_DEFINITION ) {
offset = cigi2_add_trajectory_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_SPECIAL_EFFECT_DEFINITION ) {
offset = cigi2_add_special_effect_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_VIEW_DEFINITION ) {
offset = cigi2_add_view_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_COLLISION_DETECTION_SEGMENT_DEFINITION ) {
offset = cigi2_add_collision_detection_segment_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_COLLISION_DETECTION_VOLUME_DEFINITION ) {
offset = cigi2_add_collision_detection_volume_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_HEIGHT_ABOVE_TERRAIN_REQUEST ) {
offset = cigi2_add_height_above_terrain_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_LINE_OF_SIGHT_OCCULT_REQUEST ) {
offset = cigi2_add_line_of_sight_occult_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_LINE_OF_SIGHT_RANGE_REQUEST ) {
offset = cigi2_add_line_of_sight_range_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_HEIGHT_OF_TERRAIN_REQUEST ) {
offset = cigi2_add_height_of_terrain_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_START_OF_FRAME ) {
offset = cigi2_add_start_of_frame(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_HEIGHT_ABOVE_TERRAIN_RESPONSE ) {
offset = cigi2_add_height_above_terrain_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_LINE_OF_SIGHT_RESPONSE ) {
offset = cigi2_add_line_of_sight_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_COLLISION_DETECTION_SEGMENT_RESPONSE ) {
offset = cigi2_add_collision_detection_segment_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_SENSOR_RESPONSE ) {
offset = cigi2_add_sensor_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_HEIGHT_OF_TERRAIN_RESPONSE ) {
offset = cigi2_add_height_of_terrain_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_COLLISION_DETECTION_VOLUME_RESPONSE ) {
offset = cigi2_add_collision_detection_volume_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI2_PACKET_ID_IMAGE_GENERATOR_MESSAGE ) {
offset = cigi2_add_image_generator_message(tvb, cigi_packet_tree, offset);
} else if ( packet_id >= CIGI2_PACKET_ID_USER_DEFINABLE_MIN && packet_id <= CIGI2_PACKET_ID_USER_DEFINABLE_MAX ) {
offset = cigi_add_data(tvb, cigi_packet_tree, offset);
} else {
offset = cigi_add_data(tvb, cigi_packet_tree, offset);
}
DISSECTOR_ASSERT_HINT(offset - init_offset == packet_length, "Packet offset does not match packet length");
}
}
static void
cigi3_add_tree(tvbuff_t *tvb, proto_tree *cigi_tree)
{
gint offset = 0;
gint length = 0;
gint init_offset = 0;
gint packet_id = 0;
gint packet_size = 0;
gint packet_length = 0;
guint16 byte_swap = 0;
proto_tree* cigi_packet_tree = NULL;
proto_item* tipacket;
int hf_cigi3_packet = -1;
length = tvb_length(tvb);
while ( offset < length ) {
packet_id = tvb_get_guint8(tvb, offset);
packet_size = tvb_get_guint8(tvb, offset + 1);
byte_swap = tvb_get_ntohs(tvb, offset + 6);
if ( ( packet_id == CIGI3_PACKET_ID_IG_CONTROL || packet_id == CIGI3_PACKET_ID_START_OF_FRAME ) && global_cigi_version == CIGI_VERSION_FROM_PACKET ) {
cigi_version = tvb_get_guint8(tvb, 2);
if ( packet_size == CIGI3_2_PACKET_SIZE_IG_CONTROL && packet_id == CIGI3_PACKET_ID_IG_CONTROL ) {
cigi_minor_version = tvb_get_guint8(tvb, 4) >> 4;
} else if ( packet_size == CIGI3_2_PACKET_SIZE_START_OF_FRAME && packet_id == CIGI3_PACKET_ID_START_OF_FRAME ) {
cigi_minor_version = tvb_get_guint8(tvb, 5) >> 4;
} else {
cigi_minor_version = 0;
}
}
if ( ( packet_id == CIGI3_PACKET_ID_IG_CONTROL || packet_id == CIGI3_PACKET_ID_START_OF_FRAME ) && global_cigi_byte_order == CIGI_BYTE_ORDER_FROM_PACKET ) {
if ( byte_swap == CIGI3_BYTE_SWAP_BIG_ENDIAN ) {
cigi_byte_order = ENC_BIG_ENDIAN;
} else if ( byte_swap == CIGI3_BYTE_SWAP_LITTLE_ENDIAN ) {
cigi_byte_order = ENC_LITTLE_ENDIAN;
} else {
cigi_byte_order = ENC_BIG_ENDIAN;
}
}
if ( packet_id == CIGI3_PACKET_ID_IG_CONTROL && cigi_minor_version == 2 ) {
hf_cigi3_packet = hf_cigi3_2_ig_control;
packet_length = CIGI3_2_PACKET_SIZE_IG_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_IG_CONTROL && cigi_minor_version == 3 ) {
hf_cigi3_packet = hf_cigi3_3_ig_control;
packet_length = CIGI3_3_PACKET_SIZE_IG_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_IG_CONTROL ) {
hf_cigi3_packet = hf_cigi3_ig_control;
packet_length = CIGI3_PACKET_SIZE_IG_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_ENTITY_CONTROL ) {
hf_cigi3_packet = hf_cigi3_entity_control;
packet_length = CIGI3_PACKET_SIZE_ENTITY_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_CONFORMAL_CLAMPED_ENTITY_CONTROL ) {
hf_cigi3_packet = hf_cigi3_conformal_clamped_entity_control;
packet_length = CIGI3_PACKET_SIZE_CONFORMAL_CLAMPED_ENTITY_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_COMPONENT_CONTROL ) {
hf_cigi3_packet = hf_cigi3_component_control;
packet_length = CIGI3_PACKET_SIZE_COMPONENT_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_SHORT_COMPONENT_CONTROL ) {
hf_cigi3_packet = hf_cigi3_short_component_control;
packet_length = CIGI3_PACKET_SIZE_SHORT_COMPONENT_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_ARTICULATED_PART_CONTROL ) {
hf_cigi3_packet = hf_cigi3_articulated_part_control;
packet_length = CIGI3_PACKET_SIZE_ARTICULATED_PART_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_SHORT_ARTICULATED_PART_CONTROL ) {
hf_cigi3_packet = hf_cigi3_short_articulated_part_control;
packet_length = CIGI3_PACKET_SIZE_SHORT_ARTICULATED_PART_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_RATE_CONTROL && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
hf_cigi3_packet = hf_cigi3_2_rate_control;
packet_length = CIGI3_2_PACKET_SIZE_RATE_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_RATE_CONTROL ) {
hf_cigi3_packet = hf_cigi3_rate_control;
packet_length = CIGI3_PACKET_SIZE_RATE_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_CELESTIAL_SPHERE_CONTROL ) {
hf_cigi3_packet = hf_cigi3_celestial_sphere_control;
packet_length = CIGI3_PACKET_SIZE_CELESTIAL_SPHERE_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_ATMOSPHERE_CONTROL ) {
hf_cigi3_packet = hf_cigi3_atmosphere_control;
packet_length = CIGI3_PACKET_SIZE_ATMOSPHERE_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_ENVIRONMENTAL_REGION_CONTROL ) {
hf_cigi3_packet = hf_cigi3_environmental_region_control;
packet_length = CIGI3_PACKET_SIZE_ENVIRONMENTAL_REGION_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_WEATHER_CONTROL ) {
hf_cigi3_packet = hf_cigi3_weather_control;
packet_length = CIGI3_PACKET_SIZE_WEATHER_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_MARITIME_SURFACE_CONDITIONS_CONTROL ) {
hf_cigi3_packet = hf_cigi3_maritime_surface_conditions_control;
packet_length = CIGI3_PACKET_SIZE_MARITIME_SURFACE_CONDITIONS_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_WAVE_CONTROL ) {
hf_cigi3_packet = hf_cigi3_wave_control;
packet_length = CIGI3_PACKET_SIZE_WAVE_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_TERRESTRIAL_SURFACE_CONDITIONS_CONTROL ) {
hf_cigi3_packet = hf_cigi3_terrestrial_surface_conditions_control;
packet_length = CIGI3_PACKET_SIZE_TERRESTRIAL_SURFACE_CONDITIONS_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_VIEW_CONTROL ) {
hf_cigi3_packet = hf_cigi3_view_control;
packet_length = CIGI3_PACKET_SIZE_VIEW_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_SENSOR_CONTROL ) {
hf_cigi3_packet = hf_cigi3_sensor_control;
packet_length = CIGI3_PACKET_SIZE_SENSOR_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_MOTION_TRACKER_CONTROL ) {
hf_cigi3_packet = hf_cigi3_motion_tracker_control;
packet_length = CIGI3_PACKET_SIZE_MOTION_TRACKER_CONTROL;
} else if ( packet_id == CIGI3_PACKET_ID_EARTH_REFERENCE_MODEL_DEFINITION ) {
hf_cigi3_packet = hf_cigi3_earth_reference_model_definition;
packet_length = CIGI3_PACKET_SIZE_EARTH_REFERENCE_MODEL_DEFINITION;
} else if ( packet_id == CIGI3_PACKET_ID_TRAJECTORY_DEFINITION ) {
hf_cigi3_packet = hf_cigi3_trajectory_definition;
packet_length = CIGI3_PACKET_SIZE_TRAJECTORY_DEFINITION;
} else if ( packet_id == CIGI3_PACKET_ID_VIEW_DEFINITION ) {
hf_cigi3_packet = hf_cigi3_view_definition;
packet_length = CIGI3_PACKET_SIZE_VIEW_DEFINITION;
} else if ( packet_id == CIGI3_PACKET_ID_COLLISION_DETECTION_SEGMENT_DEFINITION ) {
hf_cigi3_packet = hf_cigi3_collision_detection_segment_definition;
packet_length = CIGI3_PACKET_SIZE_COLLISION_DETECTION_SEGMENT_DEFINITION;
} else if ( packet_id == CIGI3_PACKET_ID_COLLISION_DETECTION_VOLUME_DEFINITION ) {
hf_cigi3_packet = hf_cigi3_collision_detection_volume_definition;
packet_length = CIGI3_PACKET_SIZE_COLLISION_DETECTION_VOLUME_DEFINITION;
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_REQUEST && (cigi_minor_version == 2 || cigi_minor_version == 3)) {
hf_cigi3_packet = hf_cigi3_2_hat_hot_request;
packet_length = CIGI3_2_PACKET_SIZE_HAT_HOT_REQUEST;
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_REQUEST ) {
hf_cigi3_packet = hf_cigi3_hat_hot_request;
packet_length = CIGI3_PACKET_SIZE_HAT_HOT_REQUEST;
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_SEGMENT_REQUEST && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
hf_cigi3_packet = hf_cigi3_2_line_of_sight_segment_request;
packet_length = CIGI3_2_PACKET_SIZE_LINE_OF_SIGHT_SEGMENT_REQUEST;
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_SEGMENT_REQUEST ) {
hf_cigi3_packet = hf_cigi3_line_of_sight_segment_request;
packet_length = CIGI3_PACKET_SIZE_LINE_OF_SIGHT_SEGMENT_REQUEST;
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_VECTOR_REQUEST && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
hf_cigi3_packet = hf_cigi3_2_line_of_sight_vector_request;
packet_length = CIGI3_2_PACKET_SIZE_LINE_OF_SIGHT_VECTOR_REQUEST;
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_VECTOR_REQUEST ) {
hf_cigi3_packet = hf_cigi3_line_of_sight_vector_request;
packet_length = CIGI3_PACKET_SIZE_LINE_OF_SIGHT_VECTOR_REQUEST;
} else if ( packet_id == CIGI3_PACKET_ID_POSITION_REQUEST ) {
hf_cigi3_packet = hf_cigi3_position_request;
packet_length = CIGI3_PACKET_SIZE_POSITION_REQUEST;
} else if ( packet_id == CIGI3_PACKET_ID_ENVIRONMENTAL_CONDITIONS_REQUEST ) {
hf_cigi3_packet = hf_cigi3_environmental_conditions_request;
packet_length = CIGI3_PACKET_SIZE_ENVIRONMENTAL_CONDITIONS_REQUEST;
} else if ( packet_id == CIGI3_PACKET_ID_SYMBOL_SURFACE_DEFINITION ) {
hf_cigi3_packet = hf_cigi3_3_symbol_surface_definition;
packet_length = CIGI3_PACKET_SIZE_SYMBOL_SURFACE_DEFINITION;
} else if ( packet_id == CIGI3_PACKET_ID_START_OF_FRAME && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
hf_cigi3_packet = hf_cigi3_2_start_of_frame;
packet_length = CIGI3_2_PACKET_SIZE_START_OF_FRAME;
} else if ( packet_id == CIGI3_PACKET_ID_START_OF_FRAME ) {
hf_cigi3_packet = hf_cigi3_start_of_frame;
packet_length = CIGI3_PACKET_SIZE_START_OF_FRAME;
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_RESPONSE && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
hf_cigi3_packet = hf_cigi3_2_hat_hot_response;
packet_length = CIGI3_2_PACKET_SIZE_HAT_HOT_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_hat_hot_response;
packet_length = CIGI3_PACKET_SIZE_HAT_HOT_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_EXTENDED_RESPONSE && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
hf_cigi3_packet = hf_cigi3_2_hat_hot_extended_response;
packet_length = CIGI3_2_PACKET_SIZE_HAT_HOT_EXTENDED_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_EXTENDED_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_hat_hot_extended_response;
packet_length = CIGI3_PACKET_SIZE_HAT_HOT_EXTENDED_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_RESPONSE && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
hf_cigi3_packet = hf_cigi3_2_line_of_sight_response;
packet_length = CIGI3_2_PACKET_SIZE_LINE_OF_SIGHT_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_line_of_sight_response;
packet_length = CIGI3_PACKET_SIZE_LINE_OF_SIGHT_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_EXTENDED_RESPONSE && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
hf_cigi3_packet = hf_cigi3_2_line_of_sight_extended_response;
packet_length = CIGI3_2_PACKET_SIZE_LINE_OF_SIGHT_EXTENDED_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_EXTENDED_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_line_of_sight_extended_response;
packet_length = CIGI3_PACKET_SIZE_LINE_OF_SIGHT_EXTENDED_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_SENSOR_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_sensor_response;
packet_length = CIGI3_PACKET_SIZE_SENSOR_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_SENSOR_EXTENDED_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_sensor_extended_response;
packet_length = CIGI3_PACKET_SIZE_SENSOR_EXTENDED_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_POSITION_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_position_response;
packet_length = CIGI3_PACKET_SIZE_POSITION_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_WEATHER_CONDITIONS_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_weather_conditions_response;
packet_length = CIGI3_PACKET_SIZE_WEATHER_CONDITIONS_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_AEROSOL_CONCENTRATION_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_aerosol_concentration_response;
packet_length = CIGI3_PACKET_SIZE_AEROSOL_CONCENTRATION_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_MARITIME_SURFACE_CONDITIONS_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_maritime_surface_conditions_response;
packet_length = CIGI3_PACKET_SIZE_MARITIME_SURFACE_CONDITIONS_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_TERRESTRIAL_SURFACE_CONDITIONS_RESPONSE ) {
hf_cigi3_packet = hf_cigi3_terrestrial_surface_conditions_response;
packet_length = CIGI3_PACKET_SIZE_TERRESTRIAL_SURFACE_CONDITIONS_RESPONSE;
} else if ( packet_id == CIGI3_PACKET_ID_COLLISION_DETECTION_SEGMENT_NOTIFICATION ) {
hf_cigi3_packet = hf_cigi3_collision_detection_segment_notification;
packet_length = CIGI3_PACKET_SIZE_COLLISION_DETECTION_SEGMENT_NOTIFICATION;
} else if ( packet_id == CIGI3_PACKET_ID_COLLISION_DETECTION_VOLUME_NOTIFICATION ) {
hf_cigi3_packet = hf_cigi3_collision_detection_volume_notification;
packet_length = CIGI3_PACKET_SIZE_COLLISION_DETECTION_VOLUME_NOTIFICATION;
} else if ( packet_id == CIGI3_PACKET_ID_ANIMATION_STOP_NOTIFICATION ) {
hf_cigi3_packet = hf_cigi3_animation_stop_notification;
packet_length = CIGI3_PACKET_SIZE_ANIMATION_STOP_NOTIFICATION;
} else if ( packet_id == CIGI3_PACKET_ID_EVENT_NOTIFICATION ) {
hf_cigi3_packet = hf_cigi3_event_notification;
packet_length = CIGI3_PACKET_SIZE_EVENT_NOTIFICATION;
} else if ( packet_id == CIGI3_PACKET_ID_IMAGE_GENERATOR_MESSAGE ) {
hf_cigi3_packet = hf_cigi3_image_generator_message;
packet_length = packet_size;
} else if ( packet_id >= CIGI3_PACKET_ID_USER_DEFINED_MIN && packet_id <= CIGI3_PACKET_ID_USER_DEFINED_MAX ) {
hf_cigi3_packet = hf_cigi3_user_defined;
packet_length = packet_size;
} else {
hf_cigi3_packet = hf_cigi_unknown;
packet_length = packet_size;
}
tipacket = proto_tree_add_string_format(cigi_tree, hf_cigi3_packet, tvb, offset, packet_length, NULL,
"%s (%i bytes)",
val_to_str_ext_const(packet_id, &cigi3_packet_id_vals_ext, "Unknown"),
packet_length);
cigi_packet_tree = proto_item_add_subtree(tipacket, ett_cigi);
init_offset = offset;
proto_tree_add_item(cigi_packet_tree, hf_cigi3_packet_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(cigi_packet_tree, hf_cigi_packet_size, tvb, offset, 1, cigi_byte_order);
offset++;
if ( packet_id == CIGI3_PACKET_ID_IG_CONTROL && cigi_minor_version == 2 ) {
offset = cigi3_2_add_ig_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_IG_CONTROL && cigi_minor_version == 3 ) {
offset = cigi3_3_add_ig_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_IG_CONTROL ) {
offset = cigi3_add_ig_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_ENTITY_CONTROL && cigi_minor_version == 3 ) {
offset = cigi3_3_add_entity_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_ENTITY_CONTROL ) {
offset = cigi3_add_entity_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_CONFORMAL_CLAMPED_ENTITY_CONTROL ) {
offset = cigi3_add_conformal_clamped_entity_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_COMPONENT_CONTROL && cigi_minor_version == 3) {
offset = cigi3_3_add_component_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_COMPONENT_CONTROL ) {
offset = cigi3_add_component_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SHORT_COMPONENT_CONTROL && cigi_minor_version == 3 ) {
offset = cigi3_3_add_short_component_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SHORT_COMPONENT_CONTROL ) {
offset = cigi3_add_short_component_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_ARTICULATED_PART_CONTROL ) {
offset = cigi3_add_articulated_part_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SHORT_ARTICULATED_PART_CONTROL ) {
offset = cigi3_add_short_articulated_part_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_RATE_CONTROL && (cigi_minor_version == 2 || cigi_minor_version == 3)) {
offset = cigi3_2_add_rate_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_RATE_CONTROL ) {
offset = cigi3_add_rate_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_CELESTIAL_SPHERE_CONTROL ) {
offset = cigi3_add_celestial_sphere_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_ATMOSPHERE_CONTROL ) {
offset = cigi3_add_atmosphere_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_ENVIRONMENTAL_REGION_CONTROL ) {
offset = cigi3_add_environmental_region_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_WEATHER_CONTROL ) {
offset = cigi3_add_weather_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_MARITIME_SURFACE_CONDITIONS_CONTROL ) {
offset = cigi3_add_maritime_surface_conditions_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_WAVE_CONTROL ) {
offset = cigi3_add_wave_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_TERRESTRIAL_SURFACE_CONDITIONS_CONTROL ) {
offset = cigi3_add_terrestrial_surface_conditions_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_VIEW_CONTROL ) {
offset = cigi3_add_view_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SENSOR_CONTROL ) {
offset = cigi3_add_sensor_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_MOTION_TRACKER_CONTROL ) {
offset = cigi3_add_motion_tracker_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_EARTH_REFERENCE_MODEL_DEFINITION ) {
offset = cigi3_add_earth_reference_model_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_TRAJECTORY_DEFINITION ) {
offset = cigi3_add_trajectory_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_VIEW_DEFINITION ) {
offset = cigi3_add_view_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_COLLISION_DETECTION_SEGMENT_DEFINITION ) {
offset = cigi3_add_collision_detection_segment_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_COLLISION_DETECTION_VOLUME_DEFINITION ) {
offset = cigi3_add_collision_detection_volume_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_REQUEST && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
offset = cigi3_2_add_hat_hot_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_REQUEST ) {
offset = cigi3_add_hat_hot_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_SEGMENT_REQUEST && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
offset = cigi3_2_add_line_of_sight_segment_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_SEGMENT_REQUEST ) {
offset = cigi3_add_line_of_sight_segment_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_VECTOR_REQUEST && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
offset = cigi3_2_add_line_of_sight_vector_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_VECTOR_REQUEST ) {
offset = cigi3_add_line_of_sight_vector_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_POSITION_REQUEST ) {
offset = cigi3_add_position_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_ENVIRONMENTAL_CONDITIONS_REQUEST ) {
offset = cigi3_add_environmental_conditions_request(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SYMBOL_SURFACE_DEFINITION && cigi_minor_version == 3 ) {
offset = cigi3_3_add_symbol_surface_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SYMBOL_TEXT_DEFINITION && cigi_minor_version == 3 ) {
offset = cigi3_3_add_symbol_text_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SYMBOL_CIRCLE_DEFINITION && cigi_minor_version == 3 ) {
offset = cigi3_3_add_symbol_circle_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SYMBOL_LINE_DEFINITION && cigi_minor_version == 3 ) {
offset = cigi3_3_add_symbol_line_definition(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SYMBOL_CLONE && cigi_minor_version == 3 ) {
offset = cigi3_3_add_symbol_clone(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SYMBOL_CONTROL && cigi_minor_version == 3 ) {
offset = cigi3_3_add_symbol_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SHORT_SYMBOL_CONTROL && cigi_minor_version == 3 ) {
offset = cigi3_3_add_short_symbol_control(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_START_OF_FRAME && (cigi_minor_version == 2 || cigi_minor_version == 3) ) {
offset = cigi3_2_add_start_of_frame(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_START_OF_FRAME ) {
offset = cigi3_add_start_of_frame(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_RESPONSE && (cigi_minor_version == 2 || cigi_minor_version == 3)) {
offset = cigi3_2_add_hat_hot_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_RESPONSE ) {
offset = cigi3_add_hat_hot_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_EXTENDED_RESPONSE && (cigi_minor_version == 2 || cigi_minor_version == 3)) {
offset = cigi3_2_add_hat_hot_extended_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_HAT_HOT_EXTENDED_RESPONSE ) {
offset = cigi3_add_hat_hot_extended_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_RESPONSE && (cigi_minor_version == 2 || cigi_minor_version == 3)) {
offset = cigi3_2_add_line_of_sight_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_RESPONSE ) {
offset = cigi3_add_line_of_sight_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_EXTENDED_RESPONSE && (cigi_minor_version == 2 || cigi_minor_version == 3)) {
offset = cigi3_2_add_line_of_sight_extended_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_LINE_OF_SIGHT_EXTENDED_RESPONSE ) {
offset = cigi3_add_line_of_sight_extended_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SENSOR_RESPONSE ) {
offset = cigi3_add_sensor_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_SENSOR_EXTENDED_RESPONSE ) {
offset = cigi3_add_sensor_extended_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_POSITION_RESPONSE ) {
offset = cigi3_add_position_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_WEATHER_CONDITIONS_RESPONSE ) {
offset = cigi3_add_weather_conditions_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_AEROSOL_CONCENTRATION_RESPONSE ) {
offset = cigi3_add_aerosol_concentration_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_MARITIME_SURFACE_CONDITIONS_RESPONSE ) {
offset = cigi3_add_maritime_surface_conditions_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_TERRESTRIAL_SURFACE_CONDITIONS_RESPONSE ) {
offset = cigi3_add_terrestrial_surface_conditions_response(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_COLLISION_DETECTION_SEGMENT_NOTIFICATION ) {
offset = cigi3_add_collision_detection_segment_notification(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_COLLISION_DETECTION_VOLUME_NOTIFICATION ) {
offset = cigi3_add_collision_detection_volume_notification(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_ANIMATION_STOP_NOTIFICATION ) {
offset = cigi3_add_animation_stop_notification(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_EVENT_NOTIFICATION ) {
offset = cigi3_add_event_notification(tvb, cigi_packet_tree, offset);
} else if ( packet_id == CIGI3_PACKET_ID_IMAGE_GENERATOR_MESSAGE ) {
offset = cigi3_add_image_generator_message(tvb, cigi_packet_tree, offset);
} else if ( packet_id >= CIGI3_PACKET_ID_USER_DEFINED_MIN && packet_id <= CIGI3_PACKET_ID_USER_DEFINED_MAX ) {
offset = cigi_add_data(tvb, cigi_packet_tree, offset);
} else {
offset = cigi_add_data(tvb, cigi_packet_tree, offset);
}
DISSECTOR_ASSERT_HINT(offset - init_offset == packet_length, "Packet offset does not match packet length");
}
}
static gint
cigi2_add_ig_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_ig_control_db_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_ig_control_ig_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_ig_control_tracking_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_ig_control_boresight, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_ig_control_frame_ctr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_ig_control_time_tag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_entity_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_entity_control_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_entity_control_entity_state, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_entity_control_attach_state, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_entity_control_collision_detect, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_entity_control_effect_state, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_entity_control_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_entity_control_parent_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_entity_control_opacity, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_entity_control_internal_temp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_entity_control_roll, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_entity_control_pitch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_entity_control_heading, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_entity_control_alt, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_entity_control_lat, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_entity_control_lon, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
cigi2_add_component_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_component_control_instance_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_component_control_component_class, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_component_control_component_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_component_control_component_state, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_component_control_component_val1, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_component_control_component_val2, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_articulated_parts_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_part_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_part_state, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_xoff_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_yoff_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_zoff_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_roll_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_pitch_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_yaw_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_x_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_y_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_z_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_roll, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_pitch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_articulated_parts_control_yaw, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_rate_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_rate_control_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_rate_control_part_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_rate_control_x_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_rate_control_y_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_rate_control_z_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_rate_control_roll_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_rate_control_pitch_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_rate_control_yaw_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_environment_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_environment_control_hour, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_environment_control_minute, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_environment_control_ephemeris_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_environment_control_humidity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_environment_control_modtran_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_cigi2_environment_control_date, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_environment_control_air_temp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_environment_control_global_visibility, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_environment_control_wind_speed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_environment_control_wind_direction, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_environment_control_pressure, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_environment_control_aerosol, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_weather_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_weather_control_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_weather_control_weather_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_weather_control_scud_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_weather_control_random_winds, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_weather_control_severity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_weather_control_phenomenon_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_weather_control_air_temp, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_weather_control_opacity, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_weather_control_scud_frequency, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_weather_control_coverage, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_weather_control_elevation, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_weather_control_thickness, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_weather_control_transition_band, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_weather_control_wind_speed, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_weather_control_wind_direction, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_view_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_view_control_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_view_control_view_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_control_view_group, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_view_control_xoff_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_control_yoff_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_control_zoff_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_control_roll_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_control_pitch_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_control_yaw_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_cigi2_view_control_x_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_control_y_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_control_z_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_control_roll, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_control_pitch, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_control_yaw, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_sensor_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_sensor_control_view_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_sensor_control_sensor_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_sensor_control_polarity, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_sensor_control_line_dropout, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_sensor_control_sensor_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_sensor_control_track_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_sensor_control_auto_gain, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_sensor_control_track_polarity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_sensor_control_gain, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_sensor_control_level, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_sensor_control_ac_coupling, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_sensor_control_noise, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_trajectory_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_trajectory_definition_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_trajectory_definition_acceleration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_trajectory_definition_retardation, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_trajectory_definition_terminal_velocity, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_special_effect_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_seq_direction, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_color_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_red, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_green, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_blue, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_float(tree, hf_cigi2_special_effect_definition_x_scale, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_special_effect_definition_y_scale, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_special_effect_definition_z_scale, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_special_effect_definition_time_scale, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_text(tree, tvb, offset, 2, "Spare");
offset += 2;
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_effect_count, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_separation, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_burst_interval, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_special_effect_definition_duration, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_view_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_view_definition_view_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_view_group, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_view_definition_view_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_pixel_rep, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_mirror, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_view_definition_tracker_assign, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_near_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_far_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_left_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_right_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_top_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_view_definition_bottom_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_definition_fov_near, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_definition_fov_far, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_definition_fov_left, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_definition_fov_right, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_definition_fov_top, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_view_definition_fov_bottom, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_collision_detection_segment_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_definition_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_definition_segment_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_definition_segment_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_definition_collision_mask, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_float(tree, hf_cigi2_collision_detection_segment_definition_x_start, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_segment_definition_y_start, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_segment_definition_z_start, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_segment_definition_x_end, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_segment_definition_y_end, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_segment_definition_z_end, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
return offset;
}
static gint
cigi2_add_collision_detection_volume_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_collision_detection_volume_definition_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_collision_detection_volume_definition_volume_enable, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_collision_detection_volume_definition_volume_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_float(tree, hf_cigi2_collision_detection_volume_definition_x_offset, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_volume_definition_y_offset, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_volume_definition_z_offset, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_volume_definition_height, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_volume_definition_width, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
proto_tree_add_float(tree, hf_cigi2_collision_detection_volume_definition_depth, tvb, offset, 2, tvb_get_fixed_point(tvb, offset, ENC_BIG_ENDIAN));
offset += 2;
return offset;
}
static gint
cigi2_add_height_above_terrain_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_height_above_terrain_request_hat_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 6;
proto_tree_add_item(tree, hf_cigi2_height_above_terrain_request_alt, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_height_above_terrain_request_lat, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_height_above_terrain_request_lon, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
cigi2_add_line_of_sight_occult_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_line_of_sight_occult_request_los_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 6;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_occult_request_source_alt, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_occult_request_source_lat, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_occult_request_source_lon, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_occult_request_dest_alt, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_occult_request_dest_lat, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_occult_request_dest_lon, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
cigi2_add_line_of_sight_range_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_line_of_sight_range_request_los_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_range_request_azimuth, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_range_request_elevation, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_range_request_min_range, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_range_request_max_range, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_range_request_source_alt, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_range_request_source_lat, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_range_request_source_lon, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
cigi2_add_height_of_terrain_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_height_of_terrain_request_hot_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 6;
proto_tree_add_item(tree, hf_cigi2_height_of_terrain_request_lat, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_height_of_terrain_request_lon, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
cigi2_add_start_of_frame(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_start_of_frame_db_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_start_of_frame_ig_status_code, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_start_of_frame_ig_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 3;
proto_tree_add_item(tree, hf_cigi2_start_of_frame_frame_ctr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_start_of_frame_time_tag, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_height_above_terrain_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_height_above_terrain_response_hat_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_height_above_terrain_response_valid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_height_above_terrain_response_material_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_height_above_terrain_response_alt, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
cigi2_add_line_of_sight_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_line_of_sight_response_los_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_response_valid, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_line_of_sight_response_occult_response, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_response_material_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_response_range, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_response_alt, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_response_lat, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_line_of_sight_response_lon, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
cigi2_add_collision_detection_segment_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_response_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_response_segment_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_response_contact, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_response_contacted_entity, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_response_material_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_response_collision_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_response_collision_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_collision_detection_segment_response_collision_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
cigi2_add_sensor_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_sensor_response_view_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_sensor_response_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_sensor_response_sensor_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_cigi2_sensor_response_x_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_sensor_response_y_offset, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_sensor_response_x_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_sensor_response_y_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint
cigi2_add_height_of_terrain_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_height_of_terrain_response_hot_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_height_of_terrain_response_valid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_cigi2_height_of_terrain_response_material_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_cigi2_height_of_terrain_response_alt, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint
cigi2_add_collision_detection_volume_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi2_collision_detection_volume_response_entity_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_collision_detection_volume_response_volume_id, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_cigi2_collision_detection_volume_response_contact, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_collision_detection_volume_response_contact_entity, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint
cigi2_add_image_generator_message(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
guint8 packet_size = 0;
packet_size = tvb_get_guint8(tvb, offset-1);
if ( packet_size < 4 ) {
THROW(ReportedBoundsError);
}
proto_tree_add_item(tree, hf_cigi2_image_generator_message_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi2_image_generator_message_message, tvb, offset, packet_size-4, ENC_ASCII|ENC_NA);
offset += packet_size-4;
return offset;
}
static gint
cigi3_add_ig_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi_version, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_ig_control_db_number, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_ig_control_ig_mode, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_ig_control_timestamp_valid, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_byte_swap, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_ig_control_frame_ctr, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_ig_control_timestamp, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_2_add_ig_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi_version, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_ig_control_db_number, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_ig_control_ig_mode, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_ig_control_timestamp_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_ig_control_minor_version, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_byte_swap, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_ig_control_host_frame_number, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_ig_control_timestamp, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_ig_control_last_ig_frame_number, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_3_add_ig_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi_version, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_ig_control_db_number, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_ig_control_ig_mode, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_ig_control_timestamp_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_ig_control_extrapolation_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_ig_control_minor_version, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_byte_swap, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_ig_control_host_frame_number, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_ig_control_timestamp, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_ig_control_last_ig_frame_number, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_entity_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_entity_control_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_entity_control_entity_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_entity_control_attach_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_entity_control_collision_detection_request, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_entity_control_inherit_alpha, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_entity_control_ground_ocean_clamp, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_entity_control_animation_direction, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_entity_control_animation_loop_mode, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_entity_control_animation_state, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_entity_control_alpha, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_entity_control_entity_type, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_entity_control_parent_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_entity_control_roll, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_entity_control_pitch, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_entity_control_yaw, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_entity_control_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_entity_control_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_entity_control_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_3_add_entity_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_3_entity_control_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_entity_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_entity_control_attach_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_entity_control_collision_detection_request, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_entity_control_inherit_alpha, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_entity_control_ground_ocean_clamp, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_animation_direction, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_entity_control_animation_loop_mode, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_entity_control_animation_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_entity_control_extrapolation_enable, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_alpha, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_entity_type, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_parent_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_roll, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_pitch, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_yaw, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_3_entity_control_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_conformal_clamped_entity_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_conformal_clamped_entity_control_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_conformal_clamped_entity_control_yaw, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_conformal_clamped_entity_control_lat, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_conformal_clamped_entity_control_lon, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_component_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_component_control_component_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_component_control_instance_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_component_control_component_class, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_component_control_component_state, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_component_control_data_1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_component_control_data_2, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_component_control_data_3, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_component_control_data_4, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_component_control_data_5, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_component_control_data_6, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_3_add_component_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_3_component_control_component_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_component_control_instance_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_component_control_component_class, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_component_control_component_state, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_component_control_data_1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_component_control_data_2, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_component_control_data_3, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_component_control_data_4, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_component_control_data_5, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_component_control_data_6, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_short_component_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_short_component_control_component_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_short_component_control_instance_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_short_component_control_component_class, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_short_component_control_component_state, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_short_component_control_data_1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_short_component_control_data_2, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_3_add_short_component_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_3_short_component_control_component_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_short_component_control_instance_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_short_component_control_component_class, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_component_control_component_state, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_component_control_data_1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_short_component_control_data_2, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_articulated_part_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_part_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_part_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_xoff_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_yoff_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_zoff_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_roll_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_pitch_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_yaw_enable, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_xoff, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_yoff, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_zoff, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_roll, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_pitch, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_articulated_part_control_yaw, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_short_articulated_part_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_part_id_1, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_part_id_2, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_dof_select_1, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_dof_select_2, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_part_enable_1, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_part_enable_2, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_dof_1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_short_articulated_part_control_dof_2, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_rate_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_rate_control_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_rate_control_part_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_rate_control_apply_to_part, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_rate_control_x_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_rate_control_y_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_rate_control_z_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_rate_control_roll_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_rate_control_pitch_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_rate_control_yaw_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_2_add_rate_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_2_rate_control_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_rate_control_part_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_rate_control_apply_to_part, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_rate_control_coordinate_system, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_2_rate_control_x_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_rate_control_y_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_rate_control_z_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_rate_control_roll_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_rate_control_pitch_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_rate_control_yaw_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_celestial_sphere_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_hour, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_minute, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_ephemeris_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_sun_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_moon_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_star_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_date_time_valid, tvb, offset, 1, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_date, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_celestial_sphere_control_star_intensity, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_atmosphere_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_atmosphere_control_atmospheric_model_enable, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_atmosphere_control_humidity, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_atmosphere_control_air_temp, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_atmosphere_control_visibility_range, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_atmosphere_control_horiz_wind, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_atmosphere_control_vert_wind, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_atmosphere_control_wind_direction, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_atmosphere_control_barometric_pressure, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_environmental_region_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_region_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_region_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_merge_weather, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_merge_aerosol, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_merge_maritime, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_merge_terrestrial, tvb, offset, 1, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_lat, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_lon, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_size_x, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_size_y, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_corner_radius, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_rotation, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_environmental_region_control_transition_perimeter, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_weather_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_weather_control_entity_region_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_weather_control_layer_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_weather_control_humidity, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_weather_control_weather_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_weather_control_scud_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_weather_control_random_winds_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_weather_control_random_lightning_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_weather_control_cloud_type, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_weather_control_scope, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_weather_control_severity, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_weather_control_air_temp, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_visibility_range, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_scud_frequency, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_coverage, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_base_elevation, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_thickness, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_transition_band, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_horiz_wind, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_vert_wind, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_wind_direction, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_barometric_pressure, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_control_aerosol_concentration, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_maritime_surface_conditions_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_control_entity_region_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_control_surface_conditions_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_control_whitecap_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_control_scope, tvb, offset, 1, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_control_sea_surface_height, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_control_surface_water_temp, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_control_surface_clarity, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_wave_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_wave_control_entity_region_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_wave_control_wave_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_wave_control_wave_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_wave_control_scope, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_wave_control_breaker_type, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_wave_control_height, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_wave_control_wavelength, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_wave_control_period, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_wave_control_direction, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_wave_control_phase_offset, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_wave_control_leading, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_terrestrial_surface_conditions_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_terrestrial_surface_conditions_control_entity_region_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_terrestrial_surface_conditions_control_surface_condition_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_terrestrial_surface_conditions_control_surface_condition_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_terrestrial_surface_conditions_control_scope, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_terrestrial_surface_conditions_control_severity, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_terrestrial_surface_conditions_control_coverage, tvb, offset, 1, cigi_byte_order);
offset++;
return offset;
}
static gint
cigi3_add_view_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_view_control_view_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_view_control_group_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_view_control_xoff_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_control_yoff_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_control_zoff_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_control_roll_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_control_pitch_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_control_yaw_enable, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_view_control_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_view_control_xoff, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_control_yoff, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_control_zoff, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_control_roll, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_control_pitch, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_control_yaw, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_sensor_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_sensor_control_view_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_control_sensor_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_sensor_control_sensor_on_off, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_sensor_control_polarity, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_sensor_control_line_dropout_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_sensor_control_auto_gain, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_sensor_control_track_white_black, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_sensor_control_track_mode, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_sensor_control_response_type, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_control_gain, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_sensor_control_level, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_sensor_control_ac_coupling, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_sensor_control_noise, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_motion_tracker_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_view_group_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_tracker_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_tracker_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_boresight_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_x_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_y_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_z_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_roll_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_pitch_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_yaw_enable, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_motion_tracker_control_view_group_select, tvb, offset, 1, cigi_byte_order);
offset += 2;
return offset;
}
static gint
cigi3_add_earth_reference_model_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_earth_reference_model_definition_erm_enable, tvb, offset, 1, cigi_byte_order);
offset += 6;
proto_tree_add_item(tree, hf_cigi3_earth_reference_model_definition_equatorial_radius, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_earth_reference_model_definition_flattening, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_trajectory_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_trajectory_definition_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_trajectory_definition_acceleration_x, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_trajectory_definition_acceleration_y, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_trajectory_definition_acceleration_z, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_trajectory_definition_retardation_rate, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_trajectory_definition_terminal_velocity, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_view_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_view_definition_view_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_view_definition_group_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_view_definition_near_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_far_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_left_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_right_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_top_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_bottom_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_mirror_mode, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_view_definition_pixel_replication, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_projection_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_reorder, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_view_definition_view_type, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_view_definition_near, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_definition_far, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_definition_left, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_definition_right, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_definition_top, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_view_definition_bottom, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_collision_detection_segment_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_segment_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_segment_enable, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_x1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_y1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_z1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_x2, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_y2, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_z2, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_definition_material_mask, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_collision_detection_volume_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_volume_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_volume_enable, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_volume_type, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_x, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_y, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_z, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_radius_height, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_width, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_depth, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_roll, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_pitch, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_definition_yaw, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_hat_hot_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_hat_hot_request_hat_hot_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_hat_hot_request_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_hat_hot_request_coordinate_system, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_hat_hot_request_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_hat_hot_request_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_hat_hot_request_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_hat_hot_request_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_2_add_hat_hot_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_request_hat_hot_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_request_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_request_coordinate_system, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_request_update_period, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_request_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_request_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_request_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_request_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_line_of_sight_segment_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_los_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_source_coord, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_destination_coord, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_response_coord, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_alpha_threshold, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_source_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_source_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_source_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_destination_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_destination_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_destination_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_segment_request_material_mask, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_2_add_line_of_sight_segment_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_los_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_source_coord, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_destination_coord, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_response_coord, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_destination_entity_id_valid, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_alpha_threshold, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_source_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_source_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_source_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_destination_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_destination_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_destination_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_material_mask, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_update_period, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_segment_request_destination_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
return offset;
}
static gint
cigi3_add_line_of_sight_vector_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_los_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_source_coord, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_response_coord, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_alpha, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_azimuth, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_elevation, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_min_range, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_max_range, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_source_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_source_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_source_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_vector_request_material_mask, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_2_add_line_of_sight_vector_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_los_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_source_coord, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_response_coord, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_alpha, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_azimuth, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_elevation, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_min_range, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_max_range, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_source_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_source_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_source_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_material_mask, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_vector_request_update_period, tvb, offset, 1, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_position_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_position_request_object_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_position_request_part_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_position_request_update_mode, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_position_request_object_class, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_position_request_coord_system, tvb, offset, 1, cigi_byte_order);
offset += 3;
return offset;
}
static gint
cigi3_add_environmental_conditions_request(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_environmental_conditions_request_type, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_environmental_conditions_request_id, tvb, offset, 1, cigi_byte_order);
offset += 5;
proto_tree_add_item(tree, hf_cigi3_environmental_conditions_request_lat, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_environmental_conditions_request_lon, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_environmental_conditions_request_alt, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_3_add_symbol_surface_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_surface_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_surface_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_attach_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_billboard, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_perspective_growth_enable, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_entity_view_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_xoff_left, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_yoff_right, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_zoff_top, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_yaw_bottom, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_pitch, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_roll, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_width, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_height, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_min_u, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_max_u, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_min_v, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_surface_definition_max_v, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_3_add_symbol_text_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
guint8 packet_size = 0;
packet_size = tvb_get_guint8(tvb, offset-1);
if ( packet_size < 16 ) {
THROW(ReportedBoundsError);
}
proto_tree_add_item(tree, hf_cigi3_3_symbol_text_definition_symbol_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_text_definition_alignment, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_symbol_text_definition_orientation, tvb, offset, 1, cigi_byte_order);
offset += 1;
proto_tree_add_item(tree, hf_cigi3_3_symbol_text_definition_font_ident, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_3_symbol_text_definition_font_size, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_text_definition_text, tvb, offset, packet_size-12, cigi_byte_order);
offset += packet_size-12;
return offset;
}
static gint
cigi3_3_add_symbol_circle_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
guint8 packet_size = 0;
int ncircles,c;
packet_size = tvb_get_guint8(tvb, offset-1);
if ( packet_size < 16 ) {
THROW(ReportedBoundsError);
}
ncircles = (packet_size - 16) / 24;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_symbol_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_drawing_style, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_stipple_pattern, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_line_width, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_stipple_pattern_length, tvb, offset, 4, cigi_byte_order);
offset += 4;
for (c = 0; c< ncircles; c++) {
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_center_u[c], tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_center_v[c], tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_radius[c], tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_inner_radius[c], tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_start_angle[c], tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_circle_definition_end_angle[c], tvb, offset, 4, cigi_byte_order);
offset += 4;
}
return offset;
}
static gint
cigi3_3_add_symbol_line_definition(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
guint8 packet_size = 0;
int nvertices,v;
packet_size = tvb_get_guint8(tvb, offset-1);
if ( packet_size < 16 ) {
THROW(ReportedBoundsError);
}
nvertices = (packet_size - 16) / 8;
proto_tree_add_item(tree, hf_cigi3_3_symbol_line_definition_symbol_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_line_definition_primitive_type, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_line_definition_stipple_pattern, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_line_definition_line_width, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_line_definition_stipple_pattern_length, tvb, offset, 4, cigi_byte_order);
offset += 4;
for(v=0; v<nvertices; v++) {
proto_tree_add_item(tree, hf_cigi3_3_symbol_line_definition_vertex_u[v], tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_line_definition_vertex_v[v], tvb, offset, 4, cigi_byte_order);
offset += 4;
}
return offset;
}
static gint
cigi3_3_add_symbol_clone(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_3_symbol_clone_symbol_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_clone_source_type, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_clone_source_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
return offset;
}
static gint
cigi3_3_add_symbol_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_symbol_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_symbol_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_attach_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_flash_control, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_inherit_color, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_parent_symbol_ident, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_surface_ident, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_layer, tvb, offset, 1, cigi_byte_order);
offset += 1;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_flash_duty_cycle, tvb, offset, 1, cigi_byte_order);
offset += 1;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_flash_period, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_position_u, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_position_v, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_rotation, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_red, tvb, offset, 1, cigi_byte_order);
offset += 1;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_green, tvb, offset, 1, cigi_byte_order);
offset += 1;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_blue, tvb, offset, 1, cigi_byte_order);
offset += 1;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_alpha, tvb, offset, 1, cigi_byte_order);
offset += 1;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_scale_u, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_3_symbol_control_scale_v, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_3_add_short_symbol_control(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
guint8 select1 = 0;
guint8 select2 = 0;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_symbol_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_symbol_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_attach_state, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_flash_control, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_inherit_color, tvb, offset, 1, cigi_byte_order);
offset += 2;
select1 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_attribute_select1, tvb, offset, 1, cigi_byte_order);
offset += 1;
select2 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_attribute_select2, tvb, offset, 1, cigi_byte_order);
offset++;
if (select1 == 9) {
if (cigi_byte_order == ENC_BIG_ENDIAN) {
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_red1, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_green1, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_blue1, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_alpha1, tvb, offset, 1, cigi_byte_order);
offset++;
} else {
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_alpha1, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_blue1, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_green1, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_red1, tvb, offset, 1, cigi_byte_order);
offset++;
}
} else {
if (select1 >= 5 && select1 <= 11) {
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_attribute_value1f, tvb, offset, 4, cigi_byte_order);
} else {
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_attribute_value1, tvb, offset, 4, cigi_byte_order);
}
offset += 4;
}
if (select2 == 9) {
if (cigi_byte_order == ENC_BIG_ENDIAN) {
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_red2, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_green2, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_blue2, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_alpha2, tvb, offset, 1, cigi_byte_order);
offset++;
} else {
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_alpha2, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_blue2, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_green2, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_red2, tvb, offset, 1, cigi_byte_order);
offset++;
}
} else {
if (select2 >= 5 && select2 <= 11) {
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_attribute_value2f, tvb, offset, 4, cigi_byte_order);
} else {
proto_tree_add_item(tree, hf_cigi3_3_short_symbol_control_attribute_value2, tvb, offset, 4, cigi_byte_order);
}
offset += 4;
}
return offset;
}
static gint
cigi3_add_start_of_frame(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi_version, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_start_of_frame_db_number, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_start_of_frame_ig_status, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_start_of_frame_ig_mode, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_start_of_frame_timestamp_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_start_of_frame_earth_reference_model, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_byte_swap, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_start_of_frame_frame_ctr, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_start_of_frame_timestamp, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_2_add_start_of_frame(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi_version, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_db_number, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_ig_status, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_ig_mode, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_timestamp_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_earth_reference_model, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_minor_version, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_byte_swap, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_ig_frame_number, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_timestamp, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_start_of_frame_last_host_frame_number, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_hat_hot_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_hat_hot_response_hat_hot_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_hat_hot_response_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_hat_hot_response_type, tvb, offset, 1, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_hat_hot_response_height, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_2_add_hat_hot_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_response_hat_hot_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_response_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_response_type, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_response_host_frame_number_lsn, tvb, offset, 1, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_response_height, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_hat_hot_extended_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_hat_hot_extended_response_hat_hot_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_hat_hot_extended_response_valid, tvb, offset, 1, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_hat_hot_extended_response_hat, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_hat_hot_extended_response_hot, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_hat_hot_extended_response_material_code, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_hat_hot_extended_response_normal_vector_azimuth, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_hat_hot_extended_response_normal_vector_elevation, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_2_add_hat_hot_extended_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_extended_response_hat_hot_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_extended_response_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_extended_response_host_frame_number_lsn, tvb, offset, 1, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_extended_response_hat, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_extended_response_hot, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_extended_response_material_code, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_extended_response_normal_vector_azimuth, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_hat_hot_extended_response_normal_vector_elevation, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_line_of_sight_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_line_of_sight_response_los_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_response_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_response_entity_id_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_response_visible, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_response_count, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_response_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_response_range, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_2_add_line_of_sight_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_response_los_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_response_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_response_entity_id_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_response_visible, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_response_host_frame_number_lsn, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_response_count, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_response_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_response_range, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_line_of_sight_extended_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_los_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_entity_id_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_range_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_visible, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_intersection_coord, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_response_count, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_range, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_red, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_green, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_blue, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_alpha, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_material_code, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_normal_vector_azimuth, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_line_of_sight_extended_response_normal_vector_elevation, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_2_add_line_of_sight_extended_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_los_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_entity_id_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_range_valid, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_visible, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_host_frame_number_lsn, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_response_count, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_range, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_red, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_green, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_blue, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_alpha, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_material_code, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_normal_vector_azimuth, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_2_line_of_sight_extended_response_normal_vector_elevation, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_sensor_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_sensor_response_view_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_response_sensor_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_sensor_response_sensor_status, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_sensor_response_gate_x_size, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_response_gate_y_size, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_response_gate_x_pos, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_sensor_response_gate_y_pos, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_sensor_response_frame_ctr, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_sensor_extended_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_view_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_sensor_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_sensor_status, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_entity_id_valid, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_gate_x_size, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_gate_y_size, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_gate_x_pos, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_gate_y_pos, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_frame_ctr, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_track_lat, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_track_lon, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_sensor_extended_response_track_alt, tvb, offset, 8, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_position_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_position_response_object_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_position_response_part_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_position_response_object_class, tvb, offset, 1, cigi_byte_order);
proto_tree_add_item(tree, hf_cigi3_position_response_coord_system, tvb, offset, 1, cigi_byte_order);
offset += 3;
proto_tree_add_item(tree, hf_cigi3_position_response_lat_xoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_position_response_lon_yoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_position_response_alt_zoff, tvb, offset, 8, cigi_byte_order);
offset += 8;
proto_tree_add_item(tree, hf_cigi3_position_response_roll, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_position_response_pitch, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_position_response_yaw, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_weather_conditions_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_weather_conditions_response_request_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_weather_conditions_response_humidity, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_weather_conditions_response_air_temp, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_conditions_response_visibility_range, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_conditions_response_horiz_speed, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_conditions_response_vert_speed, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_conditions_response_wind_direction, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_weather_conditions_response_barometric_pressure, tvb, offset, 4, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_aerosol_concentration_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_aerosol_concentration_response_request_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_aerosol_concentration_response_layer_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_aerosol_concentration_response_aerosol_concentration, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_maritime_surface_conditions_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_response_request_id, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_response_sea_surface_height, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_response_surface_water_temp, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_maritime_surface_conditions_response_surface_clarity, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_terrestrial_surface_conditions_response(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_terrestrial_surface_conditions_response_request_id, tvb, offset, 1, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_terrestrial_surface_conditions_response_surface_id, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_collision_detection_segment_notification(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_notification_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_notification_segment_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_notification_type, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_notification_contacted_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_notification_material_code, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_collision_detection_segment_notification_intersection_distance, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_collision_detection_volume_notification(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_notification_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_notification_volume_id, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_notification_type, tvb, offset, 1, cigi_byte_order);
offset++;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_notification_contacted_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_collision_detection_volume_notification_contacted_volume_id, tvb, offset, 1, cigi_byte_order);
offset += 8;
return offset;
}
static gint
cigi3_add_animation_stop_notification(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_animation_stop_notification_entity_id, tvb, offset, 2, cigi_byte_order);
offset += 6;
return offset;
}
static gint
cigi3_add_event_notification(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_cigi3_event_notification_event_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_event_notification_data_1, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_event_notification_data_2, tvb, offset, 4, cigi_byte_order);
offset += 4;
proto_tree_add_item(tree, hf_cigi3_event_notification_data_3, tvb, offset, 4, cigi_byte_order);
offset += 4;
return offset;
}
static gint
cigi3_add_image_generator_message(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
guint8 packet_size = 0;
packet_size = tvb_get_guint8(tvb, offset-1);
if ( packet_size < 4 ) {
THROW(ReportedBoundsError);
}
proto_tree_add_item(tree, hf_cigi3_image_generator_message_id, tvb, offset, 2, cigi_byte_order);
offset += 2;
proto_tree_add_item(tree, hf_cigi3_image_generator_message_message, tvb, offset, packet_size-4, cigi_byte_order);
offset += packet_size-4;
return offset;
}
static gfloat
tvb_get_fixed_point(tvbuff_t *tvb, int offset, gint rep)
{
gint16 fixed;
if (rep & ENC_LITTLE_ENDIAN)
fixed = tvb_get_letohs(tvb, offset);
else
fixed = tvb_get_ntohs(tvb, offset);
return fixed / 128.0F;
}
void
proto_register_cigi(void)
{
module_t *cigi_module;
static hf_register_info hf[] = {
{ &hf_cigi_src_port,
{ "Source Port", "cigi.srcport",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cigi_dest_port,
{ "Destination Port", "cigi.destport",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cigi_port,
{ "Source or Destination Port", "cigi.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_cigi_frame_size,
{ "Frame Size (bytes)", "cigi.frame_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Number of bytes sent with all cigi packets in this frame", HFILL }
},
{ &hf_cigi_packet_id,
{ "Packet ID", "cigi.packet_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the packet's id", HFILL }
},
{ &hf_cigi_packet_size,
{ "Packet Size (bytes)", "cigi.packet_size",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the number of bytes in this type of packet", HFILL }
},
{ &hf_cigi_version,
{ "CIGI Version", "cigi.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the version of CIGI interface that is currently running on the host", HFILL }
},
{ &hf_cigi_unknown,
{ "Unknown", "cigi.unknown",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Unknown Packet", HFILL }
},
{ &hf_cigi2_packet_id,
{ "Packet ID", "cigi.packet_id",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &cigi2_packet_id_vals_ext, 0x0,
"Identifies the packet's ID", HFILL }
},
{ &hf_cigi3_packet_id,
{ "Packet ID", "cigi.packet_id",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &cigi3_packet_id_vals_ext, 0x0,
"Identifies the packet's ID", HFILL }
},
{ &hf_cigi3_byte_swap,
{ "Byte Swap", "cigi.byte_swap",
FT_UINT16, BASE_HEX, VALS(cigi3_byte_swap_vals), 0x0,
"Used to determine whether the incoming data should be byte-swapped", HFILL }
},
{ &hf_cigi2_ig_control,
{ "IG Control", "cigi.ig_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"IG Control Packet", HFILL }
},
{ &hf_cigi2_ig_control_db_number,
{ "Database Number", "cigi.ig_control.db_number",
FT_INT8, BASE_DEC, NULL, 0x0,
"Identifies the number associated with the database requiring loading", HFILL }
},
{ &hf_cigi2_ig_control_ig_mode,
{ "IG Mode Change Request", "cigi.ig_control.ig_mode",
FT_UINT8, BASE_DEC, VALS(cigi2_ig_control_ig_mode_vals), 0xc0,
"Commands the IG to enter its various modes", HFILL }
},
{ &hf_cigi2_ig_control_tracking_enable,
{ "Tracking Device Enable", "cigi.ig_control.tracking_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x20,
"Identifies the state of an external tracking device", HFILL }
},
{ &hf_cigi2_ig_control_boresight,
{ "Tracking Device Boresight", "cigi.ig_control.boresight",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x10,
"Used by the host to enable boresight mode", HFILL }
},
{ &hf_cigi2_ig_control_frame_ctr,
{ "Frame Counter", "cigi.ig_control.frame_ctr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Identifies a particular frame", HFILL }
},
{ &hf_cigi2_ig_control_time_tag,
{ "Timing Value (microseconds)", "cigi.ig_control.time_tag",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies synchronous operation", HFILL }
},
{ &hf_cigi3_ig_control,
{ "IG Control", "cigi.ig_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"IG Control Packet", HFILL }
},
{ &hf_cigi3_ig_control_db_number,
{ "Database Number", "cigi.ig_control.db_number",
FT_INT8, BASE_DEC, NULL, 0x0,
"Used to initiate a database load on the IG", HFILL }
},
{ &hf_cigi3_ig_control_ig_mode,
{ "IG Mode", "cigi.ig_control.ig_mode",
FT_UINT8, BASE_DEC, VALS(cigi3_ig_control_ig_mode_vals), 0x03,
"Dictates the IG's operational mode", HFILL }
},
{ &hf_cigi3_ig_control_timestamp_valid,
{ "Timestamp Valid", "cigi.ig_control.timestamp_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x04,
"Indicates whether the timestamp contains a valid value", HFILL }
},
{ &hf_cigi3_ig_control_frame_ctr,
{ "Frame Counter", "cigi.ig_control.frame_ctr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Contains a number that identifying the frame", HFILL }
},
{ &hf_cigi3_ig_control_timestamp,
{ "Timestamp (microseconds)", "cigi.ig_control.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the number of 10 microsecond \"ticks\" since some initial reference time", HFILL }
},
{ &hf_cigi3_2_ig_control,
{ "IG Control", "cigi.ig_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"IG Control Packet", HFILL }
},
{ &hf_cigi3_2_ig_control_db_number,
{ "Database Number", "cigi.ig_control.db_number",
FT_INT8, BASE_DEC, NULL, 0x0,
"Used to initiate a database load on the IG", HFILL }
},
{ &hf_cigi3_2_ig_control_ig_mode,
{ "IG Mode", "cigi.ig_control.ig_mode",
FT_UINT8, BASE_DEC, VALS(cigi3_2_ig_control_ig_mode_vals), 0x03,
"Dictates the IG's operational mode", HFILL }
},
{ &hf_cigi3_2_ig_control_timestamp_valid,
{ "Timestamp Valid", "cigi.ig_control.timestamp_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x04,
"Indicates whether the timestamp contains a valid value", HFILL }
},
{ &hf_cigi3_2_ig_control_minor_version,
{ "Minor Version", "cigi.ig_control.minor_version",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Indicates the minor version of the CIGI interface", HFILL }
},
{ &hf_cigi3_2_ig_control_host_frame_number,
{ "Host Frame Number", "cigi.ig_control.host_frame_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Uniquely identifies a data frame on the host", HFILL }
},
{ &hf_cigi3_2_ig_control_timestamp,
{ "Timestamp (microseconds)", "cigi.ig_control.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the number of 10 microsecond \"ticks\" since some initial reference time", HFILL }
},
{ &hf_cigi3_2_ig_control_last_ig_frame_number,
{ "IG Frame Number", "cigi.ig_control.last_ig_frame_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Contains the value of the IG Frame Number parameter in the last Start of Frame packet received from the IG", HFILL }
},
{ &hf_cigi3_3_ig_control,
{ "IG Control", "cigi.ig_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"IG Control Packet", HFILL }
},
{ &hf_cigi3_3_ig_control_db_number,
{ "Database Number", "cigi.ig_control.db_number",
FT_INT8, BASE_DEC, NULL, 0x0,
"Used to initiate a database load on the IG", HFILL }
},
{ &hf_cigi3_3_ig_control_ig_mode,
{ "IG Mode", "cigi.ig_control.ig_mode",
FT_UINT8, BASE_DEC, VALS(cigi3_3_ig_control_ig_mode_vals), 0x03,
"Dictates the IG's operational mode", HFILL }
},
{ &hf_cigi3_3_ig_control_timestamp_valid,
{ "Timestamp Valid", "cigi.ig_control.timestamp_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x04,
"Indicates whether the timestamp contains a valid value", HFILL }
},
{ &hf_cigi3_3_ig_control_extrapolation_enable,
{ "Extrapolation/Interpolation Enable", "cigi.ig_control.extrapolation_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Indicates whether any dead reckoning is enabled.", HFILL }
},
{ &hf_cigi3_3_ig_control_minor_version,
{ "Minor Version", "cigi.ig_control.minor_version",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Indicates the minor version of the CIGI interface", HFILL }
},
#if 0
{ &hf_cigi3_3_ig_control_host_frame_number,
{ "Host Frame Number", "cigi.ig_control.host_frame_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Uniquely identifies a data frame on the host", HFILL }
},
{ &hf_cigi3_3_ig_control_timestamp,
{ "Timestamp (microseconds)", "cigi.ig_control.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the number of 10 microsecond \"ticks\" since some initial reference time", HFILL }
},
{ &hf_cigi3_3_ig_control_last_ig_frame_number,
{ "IG Frame Number", "cigi.ig_control.last_ig_frame_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Contains the value of the IG Frame Number parameter in the last Start of Frame packet received from the IG", HFILL }
},
#endif
{ &hf_cigi2_entity_control,
{ "Entity Control", "cigi.entity_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Entity Control Packet", HFILL }
},
{ &hf_cigi2_entity_control_entity_id,
{ "Entity ID", "cigi.entity_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the entity motion system", HFILL }
},
{ &hf_cigi2_entity_control_entity_state,
{ "Entity State", "cigi.entity_control.entity_state",
FT_UINT8, BASE_DEC, VALS(cigi2_entity_control_entity_state_vals), 0xc0,
"Identifies the entity's geometry state", HFILL }
},
{ &hf_cigi2_entity_control_attach_state,
{ "Attach State", "cigi.entity_control.attach_state",
FT_BOOLEAN, 8, TFS(&cigi2_entity_control_attach_state_tfs), 0x20,
"Identifies whether the entity should be attach as a child to a parent", HFILL }
},
{ &hf_cigi2_entity_control_collision_detect,
{ "Collision Detection Request", "cigi.entity_control.collision_detect",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Identifies if collision detection is enabled for the entity", HFILL }
},
{ &hf_cigi2_entity_control_effect_state,
{ "Effect Animation State", "cigi.entity_control.effect_state",
FT_UINT8, BASE_DEC, VALS(cigi2_entity_control_effect_state_vals), 0x0c,
"Identifies the animation state of a special effect", HFILL }
},
{ &hf_cigi2_entity_control_type,
{ "Entity Type", "cigi.entity_control.type",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the type of the entity", HFILL }
},
{ &hf_cigi2_entity_control_parent_id,
{ "Parent Entity ID", "cigi.entity_control.parent_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the parent to which the entity should be attached", HFILL }
},
{ &hf_cigi2_entity_control_opacity,
{ "Percent Opacity", "cigi.entity_control.opacity",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the degree of opacity of the entity", HFILL }
},
{ &hf_cigi2_entity_control_internal_temp,
{ "Internal Temperature (degrees C)", "cigi.entity_control.internal_temp",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the internal temperature of the entity in degrees Celsius", HFILL }
},
{ &hf_cigi2_entity_control_roll,
{ "Roll (degrees)", "cigi.entity_control.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the roll angle of the entity in degrees", HFILL }
},
{ &hf_cigi2_entity_control_pitch,
{ "Pitch (degrees)", "cigi.entity_control",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the pitch of the entity in degrees", HFILL }
},
{ &hf_cigi2_entity_control_heading,
{ "Heading (degrees)", "cigi.entity_control",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the heading of the entity in degrees", HFILL }
},
{ &hf_cigi2_entity_control_alt,
{ "Altitude (m)", "cigi.entity_control.alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Identifies the altitude position of the reference point of the entity in meters", HFILL }
},
{ &hf_cigi2_entity_control_lat,
{ "Latitude (degrees)", "cigi.entity_control.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Identifies the latitude position of the reference point of the entity in degrees", HFILL }
},
{ &hf_cigi2_entity_control_lon,
{ "Longitude (degrees)", "cigi.entity_control.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Identifies the longitude position of the reference point of the entity in degrees", HFILL }
},
{ &hf_cigi3_entity_control,
{ "Entity Control", "cigi.entity_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Entity Control Packet", HFILL }
},
{ &hf_cigi3_entity_control_entity_id,
{ "Entity ID", "cigi.entity_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which this packet is applied", HFILL }
},
{ &hf_cigi3_entity_control_entity_state,
{ "Entity State", "cigi.entity_control.entity_state",
FT_UINT8, BASE_DEC, VALS(cigi3_entity_control_entity_state_vals), 0x03,
"Specifies whether the entity should be active or destroyed", HFILL }
},
{ &hf_cigi3_entity_control_attach_state,
{ "Attach State", "cigi.entity_control.attach_state",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_attach_state_tfs), 0x04,
"Specifies whether the entity should be attached as a child to a parent", HFILL }
},
{ &hf_cigi3_entity_control_collision_detection_request,
{ "Collision Detection Request", "cigi.entity_control.coll_det_request",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_collision_detection_request_tfs), 0x08,
"Determines whether any collision detection segments and volumes associated with this entity are used as the source in collision testing", HFILL }
},
{ &hf_cigi3_entity_control_inherit_alpha,
{ "Inherit Alpha", "cigi.entity_control.inherit_alpha",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_inherit_alpha_tfs), 0x10,
"Specifies whether the entity's alpha is combined with the apparent alpha of its parent", HFILL }
},
{ &hf_cigi3_entity_control_ground_ocean_clamp,
{ "Ground/Ocean Clamp", "cigi.entity_control.ground_ocean_clamp",
FT_UINT8, BASE_DEC, VALS(cigi3_entity_control_ground_ocean_clamp_vals), 0x60,
"Specifies whether the entity should be clamped to the ground or water surface", HFILL }
},
{ &hf_cigi3_entity_control_animation_direction,
{ "Animation Direction", "cigi.entity_control.animation_dir",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_animation_direction_tfs), 0x01,
"Specifies the direction in which an animation plays", HFILL }
},
{ &hf_cigi3_entity_control_animation_loop_mode,
{ "Animation Loop Mode", "cigi.entity_control.animation_loop_mode",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_animation_loop_mode_tfs), 0x02,
"Specifies whether an animation should be a one-shot", HFILL }
},
{ &hf_cigi3_entity_control_animation_state,
{ "Animation State", "cigi.entity_control.animation_state",
FT_UINT8, BASE_DEC, VALS(cigi3_entity_control_animation_state_vals), 0x0c,
"Specifies the state of an animation", HFILL }
},
{ &hf_cigi3_entity_control_alpha,
{ "Alpha", "cigi.entity_control.alpha",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the explicit alpha to be applied to the entity's geometry", HFILL }
},
{ &hf_cigi3_entity_control_entity_type,
{ "Entity Type", "cigi.entity_control.entity_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the type for the entity", HFILL }
},
{ &hf_cigi3_entity_control_parent_id,
{ "Parent ID", "cigi.entity_control.parent_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the parent for the entity", HFILL }
},
{ &hf_cigi3_entity_control_roll,
{ "Roll (degrees)", "cigi.entity_control.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the roll angle of the entity", HFILL }
},
{ &hf_cigi3_entity_control_pitch,
{ "Pitch (degrees)", "cigi.entity_control.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the pitch angle of the entity", HFILL }
},
{ &hf_cigi3_entity_control_yaw,
{ "Yaw (degrees)", "cigi.entity_control.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the instantaneous heading of the entity", HFILL }
},
{ &hf_cigi3_entity_control_lat_xoff,
{ "Latitude (degrees)/X Offset (m)", "cigi.entity_control.lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the entity's geodetic latitude or the distance from the parent's reference point along its parent's X axis", HFILL }
},
{ &hf_cigi3_entity_control_lon_yoff,
{ "Longitude (degrees)/Y Offset (m)", "cigi.entity_control.lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the entity's geodetic longitude or the distance from the parent's reference point along its parent's Y axis", HFILL }
},
{ &hf_cigi3_entity_control_alt_zoff,
{ "Altitude (m)/Z Offset (m)", "cigi.entity_control.alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the entity's altitude or the distance from the parent's reference point along its parent's Z axis", HFILL }
},
#if 0
{ &hf_cigi3_3_entity_control,
{ "Entity Control", "cigi.entity_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Entity Control Packet", HFILL }
},
#endif
{ &hf_cigi3_3_entity_control_entity_id,
{ "Entity ID", "cigi.entity_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which this packet is applied", HFILL }
},
{ &hf_cigi3_3_entity_control_entity_state,
{ "Entity State", "cigi.entity_control.entity_state",
FT_UINT8, BASE_DEC, VALS(cigi3_entity_control_entity_state_vals), 0x03,
"Specifies whether the entity should be active or destroyed", HFILL }
},
{ &hf_cigi3_3_entity_control_attach_state,
{ "Attach State", "cigi.entity_control.attach_state",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_attach_state_tfs), 0x04,
"Specifies whether the entity should be attached as a child to a parent", HFILL }
},
{ &hf_cigi3_3_entity_control_collision_detection_request,
{ "Collision Detection Request", "cigi.entity_control.coll_det_request",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_collision_detection_request_tfs), 0x08,
"Determines whether any collision detection segments and volumes associated with this entity are used as the source in collision testing", HFILL }
},
{ &hf_cigi3_3_entity_control_inherit_alpha,
{ "Inherit Alpha", "cigi.entity_control.inherit_alpha",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_inherit_alpha_tfs), 0x10,
"Specifies whether the entity's alpha is combined with the apparent alpha of its parent", HFILL }
},
{ &hf_cigi3_3_entity_control_ground_ocean_clamp,
{ "Ground/Ocean Clamp", "cigi.entity_control.ground_ocean_clamp",
FT_UINT8, BASE_DEC, VALS(cigi3_entity_control_ground_ocean_clamp_vals), 0x60,
"Specifies whether the entity should be clamped to the ground or water surface", HFILL }
},
{ &hf_cigi3_3_entity_control_animation_direction,
{ "Animation Direction", "cigi.entity_control.animation_dir",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_animation_direction_tfs), 0x01,
"Specifies the direction in which an animation plays", HFILL }
},
{ &hf_cigi3_3_entity_control_animation_loop_mode,
{ "Animation Loop Mode", "cigi.entity_control.animation_loop_mode",
FT_BOOLEAN, 8, TFS(&cigi3_entity_control_animation_loop_mode_tfs), 0x02,
"Specifies whether an animation should be a one-shot", HFILL }
},
{ &hf_cigi3_3_entity_control_animation_state,
{ "Animation State", "cigi.entity_control.animation_state",
FT_UINT8, BASE_DEC, VALS(cigi3_entity_control_animation_state_vals), 0x0c,
"Specifies the state of an animation", HFILL }
},
{ &hf_cigi3_3_entity_control_extrapolation_enable,
{ "Linear Extrapolation/Interpolation Enable", "cigi.entity_control.extrapolation_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Indicates whether the entity's motion may be smoothed by extrapolation or interpolation.", HFILL }
},
{ &hf_cigi3_3_entity_control_alpha,
{ "Alpha", "cigi.entity_control.alpha",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the explicit alpha to be applied to the entity's geometry", HFILL }
},
{ &hf_cigi3_3_entity_control_entity_type,
{ "Entity Type", "cigi.entity_control.entity_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the type for the entity", HFILL }
},
{ &hf_cigi3_3_entity_control_parent_id,
{ "Parent ID", "cigi.entity_control.parent_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the parent for the entity", HFILL }
},
{ &hf_cigi3_3_entity_control_roll,
{ "Roll (degrees)", "cigi.entity_control.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the roll angle of the entity", HFILL }
},
{ &hf_cigi3_3_entity_control_pitch,
{ "Pitch (degrees)", "cigi.entity_control.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the pitch angle of the entity", HFILL }
},
{ &hf_cigi3_3_entity_control_yaw,
{ "Yaw (degrees)", "cigi.entity_control.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the instantaneous heading of the entity", HFILL }
},
{ &hf_cigi3_3_entity_control_lat_xoff,
{ "Latitude (degrees)/X Offset (m)", "cigi.entity_control.lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the entity's geodetic latitude or the distance from the parent's reference point along its parent's X axis", HFILL }
},
{ &hf_cigi3_3_entity_control_lon_yoff,
{ "Longitude (degrees)/Y Offset (m)", "cigi.entity_control.lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the entity's geodetic longitude or the distance from the parent's reference point along its parent's Y axis", HFILL }
},
{ &hf_cigi3_3_entity_control_alt_zoff,
{ "Altitude (m)/Z Offset (m)", "cigi.entity_control.alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the entity's altitude or the distance from the parent's reference point along its parent's Z axis", HFILL }
},
{ &hf_cigi3_conformal_clamped_entity_control,
{ "Conformal Clamped Entity Control", "cigi.conformal_clamped_entity_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Conformal Clamped Entity Control Packet", HFILL }
},
{ &hf_cigi3_conformal_clamped_entity_control_entity_id,
{ "Entity ID", "cigi.conformal_clamped_entity_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which this packet is applied", HFILL }
},
{ &hf_cigi3_conformal_clamped_entity_control_yaw,
{ "Yaw (degrees)", "cigi.conformal_clamped_entity_control.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the instantaneous heading of the entity", HFILL }
},
{ &hf_cigi3_conformal_clamped_entity_control_lat,
{ "Latitude (degrees)", "cigi.conformal_clamped_entity_control.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the entity's geodetic latitude", HFILL }
},
{ &hf_cigi3_conformal_clamped_entity_control_lon,
{ "Longitude (degrees)", "cigi.conformal_clamped_entity_control.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the entity's geodetic longitude", HFILL }
},
{ &hf_cigi2_component_control,
{ "Component Control", "cigi.component_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Component Control Packet", HFILL }
},
{ &hf_cigi2_component_control_instance_id,
{ "Instance ID", "cigi.component_control.instance_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the instance of the a class the component being controlled belongs to", HFILL }
},
{ &hf_cigi2_component_control_component_class,
{ "Component Class", "cigi.component_control.component_class",
FT_UINT8, BASE_DEC, VALS(cigi2_component_control_component_class_vals), 0x0,
"Identifies the class the component being controlled is in", HFILL }
},
{ &hf_cigi2_component_control_component_id,
{ "Component ID", "cigi.component_control.component_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the component of a component class and instance ID this packet will be applied to", HFILL }
},
{ &hf_cigi2_component_control_component_state,
{ "Component State", "cigi.component_control.component_state",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the commanded state of a component", HFILL }
},
{ &hf_cigi2_component_control_component_val1,
{ "Component Value 1", "cigi.component_control.component_val1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies a continuous value to be applied to a component", HFILL }
},
{ &hf_cigi2_component_control_component_val2,
{ "Component Value 2", "cigi.component_control.component_val2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies a continuous value to be applied to a component", HFILL }
},
{ &hf_cigi3_component_control,
{ "Component Control", "cigi.component_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Component Control Packet", HFILL }
},
{ &hf_cigi3_component_control_component_id,
{ "Component ID", "cigi.component_control.component_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the component to which the data in this packet should be applied", HFILL }
},
{ &hf_cigi3_component_control_instance_id,
{ "Instance ID", "cigi.component_control.instance_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the object to which the component belongs", HFILL }
},
{ &hf_cigi3_component_control_component_class,
{ "Component Class", "cigi.component_control.component_class",
FT_UINT8, BASE_DEC, VALS(cigi3_component_control_component_class_vals), 0x0f,
"Identifies the type of object to which the Instance ID parameter refers", HFILL }
},
{ &hf_cigi3_component_control_component_state,
{ "Component State", "cigi.component_control.component_state",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies a discrete state for the component", HFILL }
},
{ &hf_cigi3_component_control_data_1,
{ "Component Data 1", "cigi.component_control.data_1",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_component_control_data_2,
{ "Component Data 2", "cigi.component_control.data_2",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_component_control_data_3,
{ "Component Data 3", "cigi.component_control.data_3",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_component_control_data_4,
{ "Component Data 4", "cigi.component_control.data_4",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_component_control_data_5,
{ "Component Data 5", "cigi.component_control.data_5",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_component_control_data_6,
{ "Component Data 6", "cigi.component_control.data_6",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
#if 0
{ &hf_cigi3_3_component_control,
{ "Component Control", "cigi.component_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Component Control Packet", HFILL }
},
#endif
{ &hf_cigi3_3_component_control_component_id,
{ "Component ID", "cigi.component_control.component_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the component to which the data in this packet should be applied", HFILL }
},
{ &hf_cigi3_3_component_control_instance_id,
{ "Instance ID", "cigi.component_control.instance_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the object to which the component belongs", HFILL }
},
{ &hf_cigi3_3_component_control_component_class,
{ "Component Class", "cigi.component_control.component_class",
FT_UINT8, BASE_DEC, VALS(cigi3_3_component_control_component_class_vals), 0x3f,
"Identifies the type of object to which the Instance ID parameter refers", HFILL }
},
{ &hf_cigi3_3_component_control_component_state,
{ "Component State", "cigi.component_control.component_state",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies a discrete state for the component", HFILL }
},
{ &hf_cigi3_3_component_control_data_1,
{ "Component Data 1", "cigi.component_control.data_1",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_3_component_control_data_2,
{ "Component Data 2", "cigi.component_control.data_2",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_3_component_control_data_3,
{ "Component Data 3", "cigi.component_control.data_3",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_3_component_control_data_4,
{ "Component Data 4", "cigi.component_control.data_4",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_3_component_control_data_5,
{ "Component Data 5", "cigi.component_control.data_5",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_3_component_control_data_6,
{ "Component Data 6", "cigi.component_control.data_6",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_short_component_control,
{ "Short Component Control", "cigi.short_component_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Short Component Control Packet", HFILL }
},
{ &hf_cigi3_short_component_control_component_id,
{ "Component ID", "cigi.short_component_control.component_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the component to which the data in this packet should be applied", HFILL }
},
{ &hf_cigi3_short_component_control_instance_id,
{ "Instance ID", "cigi.short_component_control.instance_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the object to which the component belongs", HFILL }
},
{ &hf_cigi3_short_component_control_component_class,
{ "Component Class", "cigi.short_component_control.component_class",
FT_UINT8, BASE_DEC, VALS(cigi3_short_component_control_component_class_vals), 0x0f,
"Identifies the type of object to which the Instance ID parameter refers", HFILL }
},
{ &hf_cigi3_short_component_control_component_state,
{ "Component State", "cigi.short_component_control.component_state",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies a discrete state for the component", HFILL }
},
{ &hf_cigi3_short_component_control_data_1,
{ "Component Data 1", "cigi.short_component_control.data_1",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_short_component_control_data_2,
{ "Component Data 2", "cigi.short_component_control.data_2",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
#if 0
{ &hf_cigi3_3_short_component_control,
{ "Short Component Control", "cigi.short_component_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Short Component Control Packet", HFILL }
},
#endif
{ &hf_cigi3_3_short_component_control_component_id,
{ "Component ID", "cigi.short_component_control.component_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the component to which the data in this packet should be applied", HFILL }
},
{ &hf_cigi3_3_short_component_control_instance_id,
{ "Instance ID", "cigi.short_component_control.instance_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the object to which the component belongs", HFILL }
},
{ &hf_cigi3_3_short_component_control_component_class,
{ "Component Class", "cigi.short_component_control.component_class",
FT_UINT8, BASE_DEC, VALS(cigi3_3_short_component_control_component_class_vals), 0x3f,
"Identifies the type of object to which the Instance ID parameter refers", HFILL }
},
{ &hf_cigi3_3_short_component_control_component_state,
{ "Component State", "cigi.short_component_control.component_state",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies a discrete state for the component", HFILL }
},
{ &hf_cigi3_3_short_component_control_data_1,
{ "Component Data 1", "cigi.short_component_control.data_1",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi3_3_short_component_control_data_2,
{ "Component Data 2", "cigi.short_component_control.data_2",
FT_BYTES, BASE_NONE, NULL, 0x0,
"User-defined component data", HFILL }
},
{ &hf_cigi2_articulated_parts_control,
{ "Articulated Parts Control", "cigi.art_part_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Articulated Parts Control Packet", HFILL }
},
{ &hf_cigi2_articulated_parts_control_entity_id,
{ "Entity ID", "cigi.art_part_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the entity to which this data packet will be applied", HFILL }
},
{ &hf_cigi2_articulated_parts_control_part_id,
{ "Articulated Part ID", "cigi.art_part_control.part_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies which articulated part is controlled with this data packet", HFILL }
},
{ &hf_cigi2_articulated_parts_control_part_state,
{ "Articulated Part State", "cigi.art_part_control.part_state",
FT_BOOLEAN, 8, TFS(&tfs_active_inactive), 0x80,
"Indicates whether an articulated part is to be shown in the display", HFILL }
},
{ &hf_cigi2_articulated_parts_control_xoff_enable,
{ "X Offset Enable", "cigi.art_part_control.xoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x40,
"Identifies whether the articulated part x offset in this data packet is manipulated from the host", HFILL }
},
{ &hf_cigi2_articulated_parts_control_yoff_enable,
{ "Y Offset Enable", "cigi.art_part_control.yoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x20,
"Identifies whether the articulated part y offset in this data packet is manipulated from the host", HFILL }
},
{ &hf_cigi2_articulated_parts_control_zoff_enable,
{ "Z Offset Enable", "cigi.art_part_control.zoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Identifies whether the articulated part z offset in this data packet is manipulated from the host", HFILL }
},
{ &hf_cigi2_articulated_parts_control_roll_enable,
{ "Roll Enable", "cigi.art_part_control.roll_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Identifies whether the articulated part roll enable in this data packet is manipulated from the host", HFILL }
},
{ &hf_cigi2_articulated_parts_control_pitch_enable,
{ "Pitch Enable", "cigi.art_part_control.pitch_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Identifies whether the articulated part pitch enable in this data packet is manipulated from the host", HFILL }
},
{ &hf_cigi2_articulated_parts_control_yaw_enable,
{ "Yaw Enable", "cigi.art_part_control.yaw_enable",
FT_UINT8, BASE_DEC, NULL, 0x02,
"Identifies whether the articulated part yaw enable in this data packet is manipulated from the host", HFILL }
},
{ &hf_cigi2_articulated_parts_control_x_offset,
{ "X Offset (m)", "cigi.art_part_control.x_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the distance along the X axis by which the articulated part should be moved", HFILL }
},
{ &hf_cigi2_articulated_parts_control_y_offset,
{ "Y Offset (m)", "cigi.art_part_control.y_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the distance along the Y axis by which the articulated part should be moved", HFILL }
},
{ &hf_cigi2_articulated_parts_control_z_offset,
{ "Z Offset (m)", "cigi.art_part_control.z_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the distance along the Z axis by which the articulated part should be moved", HFILL }
},
{ &hf_cigi2_articulated_parts_control_roll,
{ "Roll (degrees)", "cigi.art_part_control.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the roll of this part with respect to the submodel coordinate system", HFILL }
},
{ &hf_cigi2_articulated_parts_control_pitch,
{ "Pitch (degrees)", "cigi.art_part_control.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the pitch of this part with respect to the submodel coordinate system", HFILL }
},
{ &hf_cigi2_articulated_parts_control_yaw,
{ "Yaw (degrees)", "cigi.art_part_control.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the yaw of this part with respect to the submodel coordinate system", HFILL }
},
{ &hf_cigi3_articulated_part_control,
{ "Articulated Part Control", "cigi.art_part_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Articulated Part Control Packet", HFILL }
},
{ &hf_cigi3_articulated_part_control_entity_id,
{ "Entity ID", "cigi.art_part_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which the articulated part belongs", HFILL }
},
{ &hf_cigi3_articulated_part_control_part_id,
{ "Articulated Part ID", "cigi.art_part_control.part_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the articulated part to which the data in this packet should be applied", HFILL }
},
{ &hf_cigi3_articulated_part_control_part_enable,
{ "Articulated Part Enable", "cigi.art_part_control.part_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Determines whether the articulated part submodel should be enabled or disabled within the scene graph", HFILL }
},
{ &hf_cigi3_articulated_part_control_xoff_enable,
{ "X Offset Enable", "cigi.art_part_control.xoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x02,
"Determines whether the X Offset parameter of the current packet should be applied to the articulated part", HFILL }
},
{ &hf_cigi3_articulated_part_control_yoff_enable,
{ "Y Offset Enable", "cigi.art_part_control.yoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Determines whether the Y Offset parameter of the current packet should be applied to the articulated part", HFILL }
},
{ &hf_cigi3_articulated_part_control_zoff_enable,
{ "Z Offset Enable", "cigi.art_part_control.zoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Determines whether the Z Offset parameter of the current packet should be applied to the articulated part", HFILL }
},
{ &hf_cigi3_articulated_part_control_roll_enable,
{ "Roll Enable", "cigi.art_part_control.roll_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Determines whether the Roll parameter of the current packet should be applied to the articulated part", HFILL }
},
{ &hf_cigi3_articulated_part_control_pitch_enable,
{ "Pitch Enable", "cigi.art_part_control.pitch_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x20,
"Determines whether the Pitch parameter of the current packet should be applied to the articulated part", HFILL }
},
{ &hf_cigi3_articulated_part_control_yaw_enable,
{ "Yaw Enable", "cigi.art_part_control.yaw_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x40,
"Determines whether the Yaw parameter of the current packet should be applied to the articulated part", HFILL }
},
{ &hf_cigi3_articulated_part_control_xoff,
{ "X Offset (m)", "cigi.art_part_control.xoff",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the distance of the articulated part along its X axis", HFILL }
},
{ &hf_cigi3_articulated_part_control_yoff,
{ "Y Offset (m)", "cigi.art_part_control.yoff",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the distance of the articulated part along its Y axis", HFILL }
},
{ &hf_cigi3_articulated_part_control_zoff,
{ "Z Offset (m)", "cigi.art_part_control.zoff",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the distance of the articulated part along its Z axis", HFILL }
},
{ &hf_cigi3_articulated_part_control_roll,
{ "Roll (degrees)", "cigi.art_part_control.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part submodel about its X axis after yaw and pitch have been applied", HFILL }
},
{ &hf_cigi3_articulated_part_control_pitch,
{ "Pitch (degrees)", "cigi.art_part_control.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part submodel about its Y axis after yaw has been applied", HFILL }
},
{ &hf_cigi3_articulated_part_control_yaw,
{ "Yaw (degrees)", "cigi.art_part_control.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part about its Z axis", HFILL }
},
{ &hf_cigi3_short_articulated_part_control,
{ "Short Articulated Part Control", "cigi.short_art_part_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Short Articulated Part Control Packet", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_entity_id,
{ "Entity ID", "cigi.short_art_part_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which the articulated part(s) belongs", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_part_id_1,
{ "Articulated Part ID 1", "cigi.short_art_part_control.part_id_1",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies an articulated part to which the data in this packet should be applied", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_part_id_2,
{ "Articulated Part ID 2", "cigi.short_art_part_control.part_id_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies an articulated part to which the data in this packet should be applied", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_dof_select_1,
{ "DOF Select 1", "cigi.short_art_part_control.dof_select_1",
FT_UINT8, BASE_DEC, VALS(cigi3_short_articulated_part_control_dof_select_vals), 0x07,
"Specifies the degree of freedom to which the value of DOF 1 is applied", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_dof_select_2,
{ "DOF Select 2", "cigi.short_art_part_control.dof_select_2",
FT_UINT8, BASE_DEC, VALS(cigi3_short_articulated_part_control_dof_select_vals), 0x38,
"Specifies the degree of freedom to which the value of DOF 2 is applied", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_part_enable_1,
{ "Articulated Part Enable 1", "cigi.short_art_part_control.part_enable_1",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x40,
"Determines whether the articulated part submodel specified by Articulated Part ID 1 should be enabled or disabled within the scene graph", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_part_enable_2,
{ "Articulated Part Enable 2", "cigi.short_art_part_control.part_enable_2",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x80,
"Determines whether the articulated part submodel specified by Articulated Part ID 2 should be enabled or disabled within the scene graph", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_dof_1,
{ "DOF 1", "cigi.short_art_part_control.dof_1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies either an offset or an angular position for the part identified by Articulated Part ID 1", HFILL }
},
{ &hf_cigi3_short_articulated_part_control_dof_2,
{ "DOF 2", "cigi.short_art_part_control.dof_2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies either an offset or an angular position for the part identified by Articulated Part ID 2", HFILL }
},
{ &hf_cigi2_rate_control,
{ "Rate Control", "cigi.rate_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Rate Control Packet", HFILL }
},
{ &hf_cigi2_rate_control_entity_id,
{ "Entity ID", "cigi.rate_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which this data packet will be applied", HFILL }
},
{ &hf_cigi2_rate_control_part_id,
{ "Articulated Part ID", "cigi.rate_control.part_id",
FT_INT8, BASE_DEC, NULL, 0x0,
"Identifies which articulated part is controlled with this data packet", HFILL }
},
{ &hf_cigi2_rate_control_x_rate,
{ "X Linear Rate (m/s)", "cigi.rate_control.x_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the x component of the velocity vector for the entity being represented", HFILL }
},
{ &hf_cigi2_rate_control_y_rate,
{ "Y Linear Rate (m/s)", "cigi.rate_control.y_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the y component of the velocity vector for the entity being represented", HFILL }
},
{ &hf_cigi2_rate_control_z_rate,
{ "Z Linear Rate (m/s)", "cigi.rate_control.z_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the z component of the velocity vector for the entity being represented", HFILL }
},
{ &hf_cigi2_rate_control_roll_rate,
{ "Roll Angular Rate (degrees/s)", "cigi.rate_control.roll_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the roll angular rate for the entity being represented", HFILL }
},
{ &hf_cigi2_rate_control_pitch_rate,
{ "Pitch Angular Rate (degrees/s)", "cigi.rate_control.pitch_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the pitch angular rate for the entity being represented", HFILL }
},
{ &hf_cigi2_rate_control_yaw_rate,
{ "Yaw Angular Rate (degrees/s)", "cigi.rate_control.yaw_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the yaw angular rate for the entity being represented", HFILL }
},
{ &hf_cigi3_rate_control,
{ "Rate Control", "cigi.rate_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Rate Control Packet", HFILL }
},
{ &hf_cigi3_rate_control_entity_id,
{ "Entity ID", "cigi.rate_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which the rate should be applied", HFILL }
},
{ &hf_cigi3_rate_control_part_id,
{ "Articulated Part ID", "cigi.rate_control.part_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the articulated part to which the rate should be applied", HFILL }
},
{ &hf_cigi3_rate_control_apply_to_part,
{ "Apply to Articulated Part", "cigi.rate_control.apply_to_part",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x01,
"Determines whether the rate is applied to the articulated part specified by the Articulated Part ID parameter", HFILL }
},
{ &hf_cigi3_rate_control_x_rate,
{ "X Linear Rate (m/s)", "cigi.rate_control.x_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the X component of a linear velocity vector", HFILL }
},
{ &hf_cigi3_rate_control_y_rate,
{ "Y Linear Rate (m/s)", "cigi.rate_control.y_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Y component of a linear velocity vector", HFILL }
},
{ &hf_cigi3_rate_control_z_rate,
{ "Z Linear Rate (m/s)", "cigi.rate_control.z_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Z component of a linear velocity vector", HFILL }
},
{ &hf_cigi3_rate_control_roll_rate,
{ "Roll Angular Rate (degrees/s)", "cigi.rate_control.roll_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part submodel about its X axis after yaw and pitch have been applied", HFILL }
},
{ &hf_cigi3_rate_control_pitch_rate,
{ "Pitch Angular Rate (degrees/s)", "cigi.rate_control.pitch_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part submodel about its Y axis after yaw has been applied", HFILL }
},
{ &hf_cigi3_rate_control_yaw_rate,
{ "Yaw Angular Rate (degrees/s)", "cigi.rate_control.yaw_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part about its Z axis when its X axis is parallel to that of the entity", HFILL }
},
{ &hf_cigi3_2_rate_control,
{ "Rate Control", "cigi.rate_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Rate Control Packet", HFILL }
},
{ &hf_cigi3_2_rate_control_entity_id,
{ "Entity ID", "cigi.rate_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which the rate should be applied", HFILL }
},
{ &hf_cigi3_2_rate_control_part_id,
{ "Articulated Part ID", "cigi.rate_control.part_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the articulated part to which the rate should be applied", HFILL }
},
{ &hf_cigi3_2_rate_control_apply_to_part,
{ "Apply to Articulated Part", "cigi.rate_control.apply_to_part",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x01,
"Determines whether the rate is applied to the articulated part specified by the Articulated Part ID parameter", HFILL }
},
{ &hf_cigi3_2_rate_control_coordinate_system,
{ "Coordinate System", "cigi.rate_control.coordinate_system",
FT_BOOLEAN, 8, TFS(&cigi3_2_rate_control_coord_sys_select_vals), 0x02,
"Specifies the reference coordinate system to which the linear and angular rates are applied", HFILL }
},
{ &hf_cigi3_2_rate_control_x_rate,
{ "X Linear Rate (m/s)", "cigi.rate_control.x_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the X component of a linear velocity vector", HFILL }
},
{ &hf_cigi3_2_rate_control_y_rate,
{ "Y Linear Rate (m/s)", "cigi.rate_control.y_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Y component of a linear velocity vector", HFILL }
},
{ &hf_cigi3_2_rate_control_z_rate,
{ "Z Linear Rate (m/s)", "cigi.rate_control.z_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Z component of a linear velocity vector", HFILL }
},
{ &hf_cigi3_2_rate_control_roll_rate,
{ "Roll Angular Rate (degrees/s)", "cigi.rate_control.roll_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part submodel about its X axis after yaw and pitch have been applied", HFILL }
},
{ &hf_cigi3_2_rate_control_pitch_rate,
{ "Pitch Angular Rate (degrees/s)", "cigi.rate_control.pitch_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part submodel about its Y axis after yaw has been applied", HFILL }
},
{ &hf_cigi3_2_rate_control_yaw_rate,
{ "Yaw Angular Rate (degrees/s)", "cigi.rate_control.yaw_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the articulated part about its Z axis when its X axis is parallel to that of the entity", HFILL }
},
{ &hf_cigi3_celestial_sphere_control,
{ "Celestial Sphere Control", "cigi.celestial_sphere_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Celestial Sphere Control Packet", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_hour,
{ "Hour (h)", "cigi.celestial_sphere_control.hour",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the current hour of the day within the simulation", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_minute,
{ "Minute (min)", "cigi.celestial_sphere_control.minute",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the current minute of the day within the simulation", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_ephemeris_enable,
{ "Ephemeris Model Enable", "cigi.celestial_sphere_control.ephemeris_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Controls whether the time of day is static or continuous", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_sun_enable,
{ "Sun Enable", "cigi.celestial_sphere_control.sun_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x02,
"Specifies whether the sun is enabled in the sky model", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_moon_enable,
{ "Moon Enable", "cigi.celestial_sphere_control.moon_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Specifies whether the moon is enabled in the sky model", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_star_enable,
{ "Star Field Enable", "cigi.celestial_sphere_control.star_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Specifies whether the start field is enabled in the sky model", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_date_time_valid,
{ "Date/Time Valid", "cigi.celestial_sphere_control.date_time_valid",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Specifies whether the Hour, Minute, and Date parameters are valid", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_date,
{ "Date (MMDDYYYY)", "cigi.celestial_sphere_control.date",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the current date within the simulation", HFILL }
},
{ &hf_cigi3_celestial_sphere_control_star_intensity,
{ "Star Field Intensity (%)", "cigi.celestial_sphere_control.star_intensity",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the intensity of the star field within the sky model", HFILL }
},
{ &hf_cigi3_atmosphere_control,
{ "Atmosphere Control", "cigi.atmosphere_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Atmosphere Control Packet", HFILL }
},
{ &hf_cigi3_atmosphere_control_atmospheric_model_enable,
{ "Atmospheric Model Enable", "cigi.atmosphere_control.atmospheric_model_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Specifies whether the IG should use an atmospheric model to determine spectral radiances for sensor applications", HFILL }
},
{ &hf_cigi3_atmosphere_control_humidity,
{ "Global Humidity (%)", "cigi.atmosphere_control.humidity",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the global humidity of the environment", HFILL }
},
{ &hf_cigi3_atmosphere_control_air_temp,
{ "Global Air Temperature (degrees C)", "cigi.atmosphere_control.air_temp",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the global air temperature of the environment", HFILL }
},
{ &hf_cigi3_atmosphere_control_visibility_range,
{ "Global Visibility Range (m)", "cigi.atmosphere_control.visibility_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the global visibility range through the atmosphere", HFILL }
},
{ &hf_cigi3_atmosphere_control_horiz_wind,
{ "Global Horizontal Wind Speed (m/s)", "cigi.atmosphere_control.horiz_wind",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the global wind speed parallel to the ellipsoid-tangential reference plane", HFILL }
},
{ &hf_cigi3_atmosphere_control_vert_wind,
{ "Global Vertical Wind Speed (m/s)", "cigi.atmosphere_control.vert_wind",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the global vertical wind speed", HFILL }
},
{ &hf_cigi3_atmosphere_control_wind_direction,
{ "Global Wind Direction (degrees)", "cigi.atmosphere_control.wind_direction",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the global wind direction", HFILL }
},
{ &hf_cigi3_atmosphere_control_barometric_pressure,
{ "Global Barometric Pressure (mb or hPa)", "cigi.atmosphere_control.barometric_pressure",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the global atmospheric pressure", HFILL }
},
{ &hf_cigi2_environment_control,
{ "Environment Control", "cigi.env_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Environment Control Packet", HFILL }
},
{ &hf_cigi2_environment_control_hour,
{ "Hour (h)", "cigi.env_control.hour",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the hour of the day for the ephemeris program within the image generator", HFILL }
},
{ &hf_cigi2_environment_control_minute,
{ "Minute (min)", "cigi.env_control.minute",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the minute of the hour for the ephemeris program within the image generator", HFILL }
},
{ &hf_cigi2_environment_control_ephemeris_enable,
{ "Ephemeris Enable", "cigi.env_control.ephemeris_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x80,
"Identifies whether a continuous time of day or static time of day is used", HFILL }
},
{ &hf_cigi2_environment_control_humidity,
{ "Humidity (%)", "cigi.env_control.humidity",
FT_UINT8, BASE_DEC, NULL, 0x7f,
"Specifies the global humidity of the environment", HFILL }
},
{ &hf_cigi2_environment_control_modtran_enable,
{ "MODTRAN", "cigi.env_control.modtran_enable",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x80,
"Identifies whether atmospherics will be included in the calculations", HFILL }
},
{ &hf_cigi2_environment_control_date,
{ "Date (MMDDYYYY)", "cigi.env_control.date",
FT_INT32, BASE_DEC, NULL, 0x0,
"Specifies the desired date for use by the ephemeris program within the image generator", HFILL }
},
{ &hf_cigi2_environment_control_air_temp,
{ "Air Temperature (degrees C)", "cigi.env_control.air_temp",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the global temperature of the environment", HFILL }
},
{ &hf_cigi2_environment_control_global_visibility,
{ "Global Visibility (m)", "cigi.env_control.global_visibility",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the global visibility", HFILL }
},
{ &hf_cigi2_environment_control_wind_speed,
{ "Wind Speed (m/s)", "cigi.env_control.wind_speed",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the global wind speed", HFILL }
},
{ &hf_cigi2_environment_control_wind_direction,
{ "Wind Direction (degrees)", "cigi.env_control.wind_direction",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the global wind direction", HFILL }
},
{ &hf_cigi2_environment_control_pressure,
{ "Barometric Pressure (mb)", "cigi.env_control.pressure",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Controls the atmospheric pressure input into MODTRAN", HFILL }
},
{ &hf_cigi2_environment_control_aerosol,
{ "Aerosol (gm/m^3)", "cigi.env_control.aerosol",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Controls the liquid water content for the defined atmosphere", HFILL }
},
{ &hf_cigi3_environmental_region_control,
{ "Environmental Region Control", "cigi.env_region_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Environmental Region Control Packet", HFILL }
},
{ &hf_cigi3_environmental_region_control_region_id,
{ "Region ID", "cigi.env_region_control.region_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the environmental region to which the data in this packet will be applied", HFILL }
},
{ &hf_cigi3_environmental_region_control_region_state,
{ "Region State", "cigi.env_region_control.region_state",
FT_UINT8, BASE_DEC, VALS(cigi3_environmental_region_control_region_state_vals), 0x03,
"Specifies whether the region should be active or destroyed", HFILL }
},
{ &hf_cigi3_environmental_region_control_merge_weather,
{ "Merge Weather Properties", "cigi.env_region_control.merge_weather",
FT_BOOLEAN, 8, TFS(&cigi3_environmental_region_control_merge_properties_tfs), 0x04,
"Specifies whether atmospheric conditions within this region should be merged with those of other regions within areas of overlap", HFILL }
},
{ &hf_cigi3_environmental_region_control_merge_aerosol,
{ "Merge Aerosol Concentrations", "cigi.env_region_control.merge_aerosol",
FT_BOOLEAN, 8, TFS(&cigi3_environmental_region_control_merge_properties_tfs), 0x08,
"Specifies whether the concentrations of aerosols found within this region should be merged with those of other regions within areas of overlap", HFILL }
},
{ &hf_cigi3_environmental_region_control_merge_maritime,
{ "Merge Maritime Surface Conditions", "cigi.env_region_control.merge_maritime",
FT_BOOLEAN, 8, TFS(&cigi3_environmental_region_control_merge_properties_tfs), 0x10,
"Specifies whether the maritime surface conditions found within this region should be merged with those of other regions within areas of overlap", HFILL }
},
{ &hf_cigi3_environmental_region_control_merge_terrestrial,
{ "Merge Terrestrial Surface Conditions", "cigi.env_region_control.merge_terrestrial",
FT_BOOLEAN, 8, TFS(&cigi3_environmental_region_control_merge_properties_tfs), 0x20,
"Specifies whether the terrestrial surface conditions found within this region should be merged with those of other regions within areas of overlap", HFILL }
},
{ &hf_cigi3_environmental_region_control_lat,
{ "Latitude (degrees)", "cigi.env_region_control.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the geodetic latitude of the center of the rounded rectangle", HFILL }
},
{ &hf_cigi3_environmental_region_control_lon,
{ "Longitude (degrees)", "cigi.env_region_control.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the geodetic longitude of the center of the rounded rectangle", HFILL }
},
{ &hf_cigi3_environmental_region_control_size_x,
{ "Size X (m)", "cigi.env_region_control.size_x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the length of the environmental region along its X axis at the geoid surface", HFILL }
},
{ &hf_cigi3_environmental_region_control_size_y,
{ "Size Y (m)", "cigi.env_region_control.size_y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the length of the environmental region along its Y axis at the geoid surface", HFILL }
},
{ &hf_cigi3_environmental_region_control_corner_radius,
{ "Corner Radius (m)", "cigi.env_region_control.corner_radius",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius of the corner of the rounded rectangle", HFILL }
},
{ &hf_cigi3_environmental_region_control_rotation,
{ "Rotation (degrees)", "cigi.env_region_control.rotation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the yaw angle of the rounded rectangle", HFILL }
},
{ &hf_cigi3_environmental_region_control_transition_perimeter,
{ "Transition Perimeter (m)", "cigi.env_region_control.transition_perimeter",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the width of the transition perimeter around the environmental region", HFILL }
},
{ &hf_cigi2_weather_control,
{ "Weather Control", "cigi.weather_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Weather Control Packet", HFILL }
},
{ &hf_cigi2_weather_control_entity_id,
{ "Entity ID", "cigi.weather_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the entity's ID", HFILL }
},
{ &hf_cigi2_weather_control_weather_enable,
{ "Weather Enable", "cigi.weather_control.weather_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x80,
"Indicates whether the phenomena specified by this data packet is visible", HFILL }
},
{ &hf_cigi2_weather_control_scud_enable,
{ "Scud Enable", "cigi.weather_control.scud_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x40,
"Indicates whether there will be scud effects applied to the phenomenon specified by this data packet", HFILL }
},
{ &hf_cigi2_weather_control_random_winds,
{ "Random Winds Aloft", "cigi.weather_control.random_winds",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x20,
"Indicates whether a random frequency and duration should be applied to the winds aloft value", HFILL }
},
{ &hf_cigi2_weather_control_severity,
{ "Severity", "cigi.weather_control.severity",
FT_UINT8, BASE_DEC, NULL, 0x1c,
"Indicates the severity of the weather phenomenon", HFILL }
},
{ &hf_cigi2_weather_control_phenomenon_type,
{ "Phenomenon Type", "cigi.weather_control.phenomenon_type",
FT_UINT16, BASE_DEC, VALS(cigi2_weather_control_phenomenon_type_vals), 0x0,
"Identifies the type of weather described by this data packet", HFILL }
},
{ &hf_cigi2_weather_control_air_temp,
{ "Air Temperature (degrees C)", "cigi.weather_control.air_temp",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the local temperature inside the weather phenomenon", HFILL }
},
{ &hf_cigi2_weather_control_opacity,
{ "Opacity (%)", "cigi.weather_control.opacity",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the opacity of the weather phenomenon", HFILL }
},
{ &hf_cigi2_weather_control_scud_frequency,
{ "Scud Frequency (%)", "cigi.weather_control.scud_frequency",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the frequency for the scud effect", HFILL }
},
{ &hf_cigi2_weather_control_coverage,
{ "Coverage (%)", "cigi.weather_control.coverage",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the amount of area coverage a particular phenomenon has over the specified global visibility range given in the environment control data packet", HFILL }
},
{ &hf_cigi2_weather_control_elevation,
{ "Elevation (m)", "cigi.weather_control.elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the base altitude of the weather phenomenon", HFILL }
},
{ &hf_cigi2_weather_control_thickness,
{ "Thickness (m)", "cigi.weather_control.thickness",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the vertical thickness of the weather phenomenon", HFILL }
},
{ &hf_cigi2_weather_control_transition_band,
{ "Transition Band (m)", "cigi.weather_control.transition_band",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates a vertical transition band both above and below a phenomenon", HFILL }
},
{ &hf_cigi2_weather_control_wind_speed,
{ "Winds Aloft Speed", "cigi.weather_control.wind_speed",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the local wind speed applied to the phenomenon", HFILL }
},
{ &hf_cigi2_weather_control_wind_direction,
{ "Winds Aloft Direction (degrees)", "cigi.weather_control.wind_direction",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates local direction of the wind applied to the phenomenon", HFILL }
},
{ &hf_cigi3_weather_control,
{ "Weather Control", "cigi.weather_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Weather Control Packet", HFILL }
},
{ &hf_cigi3_weather_control_entity_region_id,
{ "Entity ID/Region ID", "cigi.weather_control.entity_region_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which the weather attributes in this packet are applied", HFILL }
},
{ &hf_cigi3_weather_control_layer_id,
{ "Layer ID", "cigi.weather_control.layer_id",
FT_UINT8, BASE_DEC, VALS(cigi3_weather_control_layer_id_vals), 0x0,
"Specifies the weather layer to which the data in this packet are applied", HFILL }
},
{ &hf_cigi3_weather_control_humidity,
{ "Humidity (%)", "cigi.weather_control.humidity",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the humidity within the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_weather_enable,
{ "Weather Enable", "cigi.weather_control.weather_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Specifies whether a weather layer and its atmospheric effects are enabled", HFILL }
},
{ &hf_cigi3_weather_control_scud_enable,
{ "Scud Enable", "cigi.weather_control.scud_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x02,
"Specifies whether weather layer produces scud effects within its transition bands", HFILL }
},
{ &hf_cigi3_weather_control_random_winds_enable,
{ "Random Winds Enable", "cigi.weather_control.random_winds_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Specifies whether a random frequency and duration should be applied to the local wind effects", HFILL }
},
{ &hf_cigi3_weather_control_random_lightning_enable,
{ "Random Lightning Enable", "cigi.weather_control.random_lightning_enable",
FT_UINT8, BASE_DEC, NULL, 0x08,
"Specifies whether the weather layer exhibits random lightning effects", HFILL }
},
{ &hf_cigi3_weather_control_cloud_type,
{ "Cloud Type", "cigi.weather_control.cloud_type",
FT_UINT8, BASE_DEC, VALS(cigi3_weather_control_cloud_type_vals), 0xf0,
"Specifies the type of clouds contained within the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_scope,
{ "Scope", "cigi.weather_control.scope",
FT_UINT8, BASE_DEC, VALS(cigi3_weather_control_scope_vals), 0x03,
"Specifies whether the weather is global, regional, or assigned to an entity", HFILL }
},
{ &hf_cigi3_weather_control_severity,
{ "Severity", "cigi.weather_control.severity",
FT_UINT8, BASE_DEC, NULL, 0x1c,
"Specifies the severity of the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_air_temp,
{ "Air Temperature (degrees C)", "cigi.weather_control.air_temp",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the temperature within the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_visibility_range,
{ "Visibility Range (m)", "cigi.weather_control.visibility_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the visibility range through the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_scud_frequency,
{ "Scud Frequency (%)", "cigi.weather_control.scud_frequency",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the frequency of scud within the transition bands above and/or below a cloud or fog layer", HFILL }
},
{ &hf_cigi3_weather_control_coverage,
{ "Coverage (%)", "cigi.weather_control.coverage",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the amount of area coverage for the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_base_elevation,
{ "Base Elevation (m)", "cigi.weather_control.base_elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the base of the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_thickness,
{ "Thickness (m)", "cigi.weather_control.thickness",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the vertical thickness of the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_transition_band,
{ "Transition Band (m)", "cigi.weather_control.transition_band",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the height of a vertical transition band both above and below the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_horiz_wind,
{ "Horizontal Wind Speed (m/s)", "cigi.weather_control.horiz_wind",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the local wind speed parallel to the ellipsoid-tangential reference plane", HFILL }
},
{ &hf_cigi3_weather_control_vert_wind,
{ "Vertical Wind Speed (m/s)", "cigi.weather_control.vert_wind",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the local vertical wind speed", HFILL }
},
{ &hf_cigi3_weather_control_wind_direction,
{ "Wind Direction (degrees)", "cigi.weather_control.wind_direction",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the local wind direction", HFILL }
},
{ &hf_cigi3_weather_control_barometric_pressure,
{ "Barometric Pressure (mb or hPa)", "cigi.weather_control.barometric_pressure",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the atmospheric pressure within the weather layer", HFILL }
},
{ &hf_cigi3_weather_control_aerosol_concentration,
{ "Aerosol Concentration (g/m^3)", "cigi.weather_control.aerosol_concentration",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the concentration of water, smoke, dust, or other particles suspended in the air", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_control,
{ "Maritime Surface Conditions Control", "cigi.maritime_surface_conditions_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Maritime Surface Conditions Control Packet", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_control_entity_region_id,
{ "Entity ID/Region ID", "cigi.maritime_surface_conditions_control.entity_region_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which the surface attributes in this packet are applied or specifies the region to which the surface attributes are confined", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_control_surface_conditions_enable,
{ "Surface Conditions Enable", "cigi.maritime_surface_conditions_control.surface_conditions_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Determines the state of the specified surface conditions", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_control_whitecap_enable,
{ "Whitecap Enable", "cigi.maritime_surface_conditions_control.whitecap_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x02,
"Determines whether whitecaps are enabled", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_control_scope,
{ "Scope", "cigi.maritime_surface_conditions_control.scope",
FT_UINT8, BASE_DEC, VALS(cigi3_maritime_surface_conditions_control_scope_vals), 0x0c,
"Specifies whether this packet is applied globally, applied to region, or assigned to an entity", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_control_sea_surface_height,
{ "Sea Surface Height (m)", "cigi.maritime_surface_conditions_control.sea_surface_height",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the height of the water above MSL at equilibrium", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_control_surface_water_temp,
{ "Surface Water Temperature (degrees C)", "cigi.maritime_surface_conditions_control.surface_water_temp",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the water temperature at the surface", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_control_surface_clarity,
{ "Surface Clarity (%)", "cigi.maritime_surface_conditions_control.surface_clarity",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the clarity of the water at its surface", HFILL }
},
{ &hf_cigi3_wave_control,
{ "Wave Control", "cigi.wave_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Wave Control Packet", HFILL }
},
{ &hf_cigi3_wave_control_entity_region_id,
{ "Entity ID/Region ID", "cigi.wave_control.entity_region_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the surface entity for which the wave is defined or specifies the environmental region for which the wave is defined", HFILL }
},
{ &hf_cigi3_wave_control_wave_id,
{ "Wave ID", "cigi.wave_control.wave_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the wave to which the attributes in this packet are applied", HFILL }
},
{ &hf_cigi3_wave_control_wave_enable,
{ "Wave Enable", "cigi.wave_control.wave_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Determines whether the wave is enabled or disabled", HFILL }
},
{ &hf_cigi3_wave_control_scope,
{ "Scope", "cigi.wave_control.scope",
FT_UINT8, BASE_DEC, VALS(cigi3_wave_control_scope_vals), 0x06,
"Specifies whether the wave is defined for global, regional, or entity-controlled maritime surface conditions", HFILL }
},
{ &hf_cigi3_wave_control_breaker_type,
{ "Breaker Type", "cigi.wave_control.breaker_type",
FT_UINT8, BASE_DEC, VALS(cigi3_wave_control_breaker_type_vals), 0x18,
"Specifies the type of breaker within the surf zone", HFILL }
},
{ &hf_cigi3_wave_control_height,
{ "Wave Height (m)", "cigi.wave_control.height",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the average vertical distance from trough to crest produced by the wave", HFILL }
},
{ &hf_cigi3_wave_control_wavelength,
{ "Wavelength (m)", "cigi.wave_control.wavelength",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the distance from a particular phase on a wave to the same phase on an adjacent wave", HFILL }
},
{ &hf_cigi3_wave_control_period,
{ "Period (s)", "cigi.wave_control.period",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the time required for one complete oscillation of the wave", HFILL }
},
{ &hf_cigi3_wave_control_direction,
{ "Direction (degrees)", "cigi.wave_control.direction",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the direction in which the wave propagates", HFILL }
},
{ &hf_cigi3_wave_control_phase_offset,
{ "Phase Offset (degrees)", "cigi.wave_control.phase_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies a phase offset for the wave", HFILL }
},
{ &hf_cigi3_wave_control_leading,
{ "Leading (degrees)", "cigi.wave_control.leading",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the phase angle at which the crest occurs", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_control,
{ "Terrestrial Surface Conditions Control", "cigi.terrestrial_surface_conditions_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Terrestrial Surface Conditions Control Packet", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_control_entity_region_id,
{ "Entity ID/Region ID", "cigi.terrestrial_surface_conditions_control.entity_region_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the environmental entity to which the surface condition attributes in this packet are applied", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_control_surface_condition_id,
{ "Surface Condition ID", "cigi.terrestrial_surface_conditions_control.surface_condition_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies a surface condition or contaminant", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_control_surface_condition_enable,
{ "Surface Condition Enable", "cigi.terrestrial_surface_conditions_control.surface_condition_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Specifies whether the surface condition attribute identified by the Surface Condition ID parameter should be enabled", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_control_scope,
{ "Scope", "cigi.terrestrial_surface_conditions_control.scope",
FT_UINT8, BASE_DEC, VALS(cigi3_terrestrial_surface_conditions_control_scope_vals), 0x06,
"Determines whether the specified surface conditions are applied globally, regionally, or to an environmental entity", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_control_severity,
{ "Severity", "cigi.terrestrial_surface_conditions_control.severity",
FT_UINT8, BASE_DEC, NULL, 0xf8,
"Determines the degree of severity for the specified surface contaminant(s)", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_control_coverage,
{ "Coverage (%)", "cigi.terrestrial_surface_conditions_control.coverage",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Determines the degree of coverage of the specified surface contaminant", HFILL }
},
{ &hf_cigi2_view_control,
{ "View Control", "cigi.view_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"View Control Packet", HFILL }
},
{ &hf_cigi2_view_control_entity_id,
{ "Entity ID", "cigi.view_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity to which this view should be attached", HFILL }
},
{ &hf_cigi2_view_control_view_id,
{ "View ID", "cigi.view_control.view_id",
FT_UINT8, BASE_DEC, NULL, 0xf8,
"Specifies which view position is associated with offsets and rotation specified by this data packet", HFILL }
},
{ &hf_cigi2_view_control_view_group,
{ "View Group Select", "cigi.view_control.view_group",
FT_UINT8, BASE_DEC, NULL, 0x07,
"Specifies which view group is to be controlled by the offsets", HFILL }
},
{ &hf_cigi2_view_control_xoff_enable,
{ "X Offset Enable", "cigi.view_control.xoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x80,
"Identifies whether the x offset parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi2_view_control_yoff_enable,
{ "Y Offset Enable", "cigi.view_control.yoff_enable",
FT_UINT8, BASE_DEC, NULL, 0x40,
"Identifies whether the y offset parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi2_view_control_zoff_enable,
{ "Z Offset Enable", "cigi.view_control.zoff_enable",
FT_UINT8, BASE_DEC, NULL, 0x20,
"Identifies whether the z offset parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi2_view_control_roll_enable,
{ "Roll Enable", "cigi.view_control.roll_enable",
FT_UINT8, BASE_DEC, NULL, 0x10,
"Identifies whether the roll parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi2_view_control_pitch_enable,
{ "Pitch Enable", "cigi.view_control.pitch_enable",
FT_UINT8, BASE_DEC, NULL, 0x08,
"Identifies whether the pitch parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi2_view_control_yaw_enable,
{ "Yaw Enable", "cigi.view_control.yaw_enable",
FT_UINT8, BASE_DEC, NULL, 0x04,
"Identifies whether the yaw parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi2_view_control_x_offset,
{ "X Offset (m)", "cigi.view_control.x_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the X component of the view offset vector along the entity's longitudinal axis", HFILL }
},
{ &hf_cigi2_view_control_y_offset,
{ "Y Offset", "cigi.view_control.y_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the Y component of the view offset vector along the entity's lateral axis", HFILL }
},
{ &hf_cigi2_view_control_z_offset,
{ "Z Offset", "cigi.view_control.z_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the Z component of the view offset vector along the entity's vertical axis", HFILL }
},
{ &hf_cigi2_view_control_roll,
{ "Roll (degrees)", "cigi.view_control.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"The rotation about the view's X axis", HFILL }
},
{ &hf_cigi2_view_control_pitch,
{ "Pitch (degrees)", "cigi.view_control.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"The rotation about the view's Y axis", HFILL }
},
{ &hf_cigi2_view_control_yaw,
{ "Yaw (degrees)", "cigi.view_control.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"The rotation about the view's Z axis", HFILL }
},
{ &hf_cigi3_view_control,
{ "View Control", "cigi.view_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"View Control Packet", HFILL }
},
{ &hf_cigi3_view_control_view_id,
{ "View ID", "cigi.view_control.view_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the view to which the contents of this packet should be applied", HFILL }
},
{ &hf_cigi3_view_control_group_id,
{ "Group ID", "cigi.view_control.group_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the view group to which the contents of this packet are applied", HFILL }
},
{ &hf_cigi3_view_control_xoff_enable,
{ "X Offset Enable", "cigi.view_control.xoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Determines whether the X Offset parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi3_view_control_yoff_enable,
{ "Y Offset Enable", "cigi.view_control.yoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x02,
"Determines whether the Y Offset parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi3_view_control_zoff_enable,
{ "Z Offset Enable", "cigi.view_control.zoff_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Determines whether the Z Offset parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi3_view_control_roll_enable,
{ "Roll Enable", "cigi.view_control.roll_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Determines whether the Roll parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi3_view_control_pitch_enable,
{ "Pitch Enable", "cigi.view_control.pitch_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Determines whether the Pitch parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi3_view_control_yaw_enable,
{ "Yaw Enable", "cigi.view_control.yaw_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x20,
"Determines whether the Yaw parameter should be applied to the specified view or view group", HFILL }
},
{ &hf_cigi3_view_control_entity_id,
{ "Entity ID", "cigi.view_control.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity to which the view or view group should be attached", HFILL }
},
{ &hf_cigi3_view_control_xoff,
{ "X Offset (m)", "cigi.view_control.xoff",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the position of the view eyepoint along the X axis of the entity specified by the Entity ID parameter", HFILL }
},
{ &hf_cigi3_view_control_yoff,
{ "Y Offset (m)", "cigi.view_control.yoff",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the position of the view eyepoint along the Y axis of the entity specified by the Entity ID parameter", HFILL }
},
{ &hf_cigi3_view_control_zoff,
{ "Z Offset (m)", "cigi.view_control.zoff",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the position of the view eyepoint along the Z axis of the entity specified by the Entity ID parameter", HFILL }
},
{ &hf_cigi3_view_control_roll,
{ "Roll (degrees)", "cigi.view_control.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the view or view group about its X axis after yaw and pitch have been applied", HFILL }
},
{ &hf_cigi3_view_control_pitch,
{ "Pitch (degrees)", "cigi.view_control.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the view or view group about its Y axis after yaw has been applied", HFILL }
},
{ &hf_cigi3_view_control_yaw,
{ "Yaw (degrees)", "cigi.view_control.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the angle of rotation of the view or view group about its Z axis", HFILL }
},
{ &hf_cigi2_sensor_control,
{ "Sensor Control", "cigi.sensor_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Sensor Control Packet", HFILL }
},
{ &hf_cigi2_sensor_control_view_id,
{ "View ID", "cigi.sensor_control.view_id",
FT_UINT8, BASE_DEC, NULL, 0xf8,
"Dictates to which view the corresponding sensor is assigned, regardless of the view group", HFILL }
},
{ &hf_cigi2_sensor_control_sensor_enable,
{ "Sensor On/Off", "cigi.sensor_control.sensor_enable",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x04,
"Indicates whether the sensor is turned on or off", HFILL }
},
{ &hf_cigi2_sensor_control_polarity,
{ "Polarity", "cigi.sensor_control.polarity",
FT_BOOLEAN, 8, TFS(&cigi2_sensor_control_polarity_tfs), 0x02,
"Indicates whether this sensor is showing white hot or black hot", HFILL }
},
{ &hf_cigi2_sensor_control_line_dropout,
{ "Line-by-Line Dropout", "cigi.sensor_control.line_dropout",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x01,
"Indicates whether the line-by-line dropout feature is enabled", HFILL }
},
{ &hf_cigi2_sensor_control_sensor_id,
{ "Sensor ID", "cigi.sensor_control.sensor_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the sensor to which this packet should be applied", HFILL }
},
{ &hf_cigi2_sensor_control_track_mode,
{ "Track Mode", "cigi.sensor_control.track_mode",
FT_UINT8, BASE_DEC, VALS(cigi2_sensor_control_track_mode_vals), 0xf0,
"Indicates which track mode the sensor should be", HFILL }
},
{ &hf_cigi2_sensor_control_auto_gain,
{ "Automatic Gain", "cigi.sensor_control.auto_gain",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x08,
"When set to \"on,\" cause the weapons sensor to automatically adjust the gain value to optimize the brightness and contrast of the sensor display", HFILL }
},
{ &hf_cigi2_sensor_control_track_polarity,
{ "Track White/Black", "cigi.sensor_control.track_polarity",
FT_BOOLEAN, 8, TFS(&cigi2_sensor_control_polarity_tfs), 0x04,
"Identifies whether the weapons sensor will track wither white or black", HFILL }
},
{ &hf_cigi2_sensor_control_gain,
{ "Gain", "cigi.sensor_control.gain",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the gain value for the weapon sensor option", HFILL }
},
{ &hf_cigi2_sensor_control_level,
{ "Level", "cigi.sensor_control.level",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the level value for the weapon sensor option", HFILL }
},
{ &hf_cigi2_sensor_control_ac_coupling,
{ "AC Coupling", "cigi.sensor_control.ac_coupling",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the AC Coupling decay rate for the weapon sensor option", HFILL }
},
{ &hf_cigi2_sensor_control_noise,
{ "Noise", "cigi.sensor_control.noise",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the detector-noise gain for the weapon sensor option", HFILL }
},
{ &hf_cigi3_sensor_control,
{ "Sensor Control", "cigi.sensor_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Sensor Control Packet", HFILL }
},
{ &hf_cigi3_sensor_control_view_id,
{ "View ID", "cigi.sensor_control.view_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the view to which the specified sensor is assigned", HFILL }
},
{ &hf_cigi3_sensor_control_sensor_id,
{ "Sensor ID", "cigi.sensor_control.sensor_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the sensor to which the data in this packet are applied", HFILL }
},
{ &hf_cigi3_sensor_control_sensor_on_off,
{ "Sensor On/Off", "cigi.sensor_control.sensor_on_off",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x01,
"Specifies whether the sensor is turned on or off", HFILL }
},
{ &hf_cigi3_sensor_control_polarity,
{ "Polarity", "cigi.sensor_control.polarity",
FT_BOOLEAN, 8, TFS(&cigi3_sensor_control_polarity_tfs), 0x02,
"Specifies whether the sensor shows white hot or black hot", HFILL }
},
{ &hf_cigi3_sensor_control_line_dropout_enable,
{ "Line-by-Line Dropout Enable", "cigi.sensor_control.line_dropout_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Specifies whether line-by-line dropout is enabled", HFILL }
},
{ &hf_cigi3_sensor_control_auto_gain,
{ "Automatic Gain", "cigi.sensor_control.auto_gain",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Specifies whether the sensor automatically adjusts the gain value to optimize the brightness and contrast of the sensor display", HFILL }
},
{ &hf_cigi3_sensor_control_track_white_black,
{ "Track White/Black", "cigi.sensor_control.track_white_black",
FT_BOOLEAN, 8, TFS(&cigi3_sensor_control_track_white_black_tfs), 0x10,
"Specifies whether the sensor tracks white or black", HFILL }
},
{ &hf_cigi3_sensor_control_track_mode,
{ "Track Mode", "cigi.sensor_control.track_mode",
FT_UINT8, BASE_DEC, VALS(cigi3_sensor_control_track_mode_vals), 0xe0,
"Specifies which track mode the sensor should use", HFILL }
},
{ &hf_cigi3_sensor_control_response_type,
{ "Response Type", "cigi.sensor_control.response_type",
FT_BOOLEAN, 8, TFS(&cigi3_sensor_control_response_type_tfs), 0x01,
"Specifies whether the IG should return a Sensor Response packet or a Sensor Extended Response packet", HFILL }
},
{ &hf_cigi3_sensor_control_gain,
{ "Gain", "cigi.sensor_control.gain",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the contrast for the sensor display", HFILL }
},
{ &hf_cigi3_sensor_control_level,
{ "Level", "cigi.sensor_control.level",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the brightness for the sensor display", HFILL }
},
{ &hf_cigi3_sensor_control_ac_coupling,
{ "AC Coupling (microseconds)", "cigi.sensor_control.ac_coupling",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the AC coupling decay constant for the sensor display", HFILL }
},
{ &hf_cigi3_sensor_control_noise,
{ "Noise", "cigi.sensor_control.noise",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the amount of detector noise for the sensor", HFILL }
},
{ &hf_cigi3_motion_tracker_control,
{ "Motion Tracker Control", "cigi.motion_tracker_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Motion Tracker Control Packet", HFILL }
},
{ &hf_cigi3_motion_tracker_control_view_group_id,
{ "View/View Group ID", "cigi.motion_tracker_control.view_group_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the view or view group to which the tracking device is attached", HFILL }
},
{ &hf_cigi3_motion_tracker_control_tracker_id,
{ "Tracker ID", "cigi.motion_tracker_control.tracker_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the tracker whose state the data in this packet represents", HFILL }
},
{ &hf_cigi3_motion_tracker_control_tracker_enable,
{ "Tracker Enable", "cigi.motion_tracker_control.tracker_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Specifies whether the tracking device is enabled", HFILL }
},
{ &hf_cigi3_motion_tracker_control_boresight_enable,
{ "Boresight Enable", "cigi.motion_tracker_control.boresight_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x02,
"Sets the boresight state of the external tracking device", HFILL }
},
{ &hf_cigi3_motion_tracker_control_x_enable,
{ "X Enable", "cigi.motion_tracker_control.x_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Used to enable or disable the X-axis position of the motion tracker", HFILL }
},
{ &hf_cigi3_motion_tracker_control_y_enable,
{ "Y Enable", "cigi.motion_tracker_control.y_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Used to enable or disable the Y-axis position of the motion tracker", HFILL }
},
{ &hf_cigi3_motion_tracker_control_z_enable,
{ "Z Enable", "cigi.motion_tracker_control.z_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Used to enable or disable the Z-axis position of the motion tracker", HFILL }
},
{ &hf_cigi3_motion_tracker_control_roll_enable,
{ "Roll Enable", "cigi.motion_tracker_control.roll_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x20,
"Used to enable or disable the roll of the motion tracker", HFILL }
},
{ &hf_cigi3_motion_tracker_control_pitch_enable,
{ "Pitch Enable", "cigi.motion_tracker_control.pitch_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x40,
"Used to enable or disable the pitch of the motion tracker", HFILL }
},
{ &hf_cigi3_motion_tracker_control_yaw_enable,
{ "Yaw Enable", "cigi.motion_tracker_control.yaw_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x80,
"Used to enable or disable the yaw of the motion tracker", HFILL }
},
{ &hf_cigi3_motion_tracker_control_view_group_select,
{ "View/View Group Select", "cigi.motion_tracker_control.view_group_select",
FT_BOOLEAN, 8, TFS(&cigi3_motion_tracker_control_view_group_select_tfs), 0x01,
"Specifies whether the tracking device is attached to a single view or a view group", HFILL }
},
{ &hf_cigi3_earth_reference_model_definition,
{ "Earth Reference Model Definition", "cigi.earth_ref_model_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Earth Reference Model Definition Packet", HFILL }
},
{ &hf_cigi3_earth_reference_model_definition_erm_enable,
{ "Custom ERM Enable", "cigi.earth_ref_model_def.erm_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Specifies whether the IG should use the Earth Reference Model defined by this packet", HFILL }
},
{ &hf_cigi3_earth_reference_model_definition_equatorial_radius,
{ "Equatorial Radius (m)", "cigi.earth_ref_model_def.equatorial_radius",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the semi-major axis of the ellipsoid", HFILL }
},
{ &hf_cigi3_earth_reference_model_definition_flattening,
{ "Flattening (m)", "cigi.earth_ref_model_def.flattening",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the flattening of the ellipsoid", HFILL }
},
{ &hf_cigi2_trajectory_definition,
{ "Trajectory Definition", "cigi.trajectory_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Trajectory Definition Packet", HFILL }
},
{ &hf_cigi2_trajectory_definition_entity_id,
{ "Entity ID", "cigi.trajectory_def.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates which entity is being influenced by this trajectory behavior", HFILL }
},
{ &hf_cigi2_trajectory_definition_acceleration,
{ "Acceleration Factor (m/s^2)", "cigi.trajectory_def.acceleration",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the acceleration factor that will be applied to the Vz component of the velocity vector over time to simulate the effects of gravity on the object", HFILL }
},
{ &hf_cigi2_trajectory_definition_retardation,
{ "Retardation Rate (m/s)", "cigi.trajectory_def.retardation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates what retardation factor will be applied to the object's motion", HFILL }
},
{ &hf_cigi2_trajectory_definition_terminal_velocity,
{ "Terminal Velocity (m/s)", "cigi.trajectory_def.terminal_velocity",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates what final velocity the object will be allowed to obtain", HFILL }
},
{ &hf_cigi3_trajectory_definition,
{ "Trajectory Definition", "cigi.trajectory_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Trajectory Definition Packet", HFILL }
},
{ &hf_cigi3_trajectory_definition_entity_id,
{ "Entity ID", "cigi.trajectory_def.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the entity for which the trajectory is defined", HFILL }
},
{ &hf_cigi3_trajectory_definition_acceleration_x,
{ "Acceleration X (m/s^2)", "cigi.trajectory_def.acceleration_x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the X component of the acceleration vector", HFILL }
},
{ &hf_cigi3_trajectory_definition_acceleration_y,
{ "Acceleration Y (m/s^2)", "cigi.trajectory_def.acceleration_y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Y component of the acceleration vector", HFILL }
},
{ &hf_cigi3_trajectory_definition_acceleration_z,
{ "Acceleration Z (m/s^2)", "cigi.trajectory_def.acceleration_z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Z component of the acceleration vector", HFILL }
},
{ &hf_cigi3_trajectory_definition_retardation_rate,
{ "Retardation Rate (m/s^2)", "cigi.trajectory_def.retardation_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the magnitude of an acceleration applied against the entity's instantaneous linear velocity vector", HFILL }
},
{ &hf_cigi3_trajectory_definition_terminal_velocity,
{ "Terminal Velocity (m/s)", "cigi.trajectory_def.terminal_velocity",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the maximum velocity the entity can sustain", HFILL }
},
{ &hf_cigi2_special_effect_definition,
{ "Special Effect Definition", "cigi.special_effect_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Special Effect Definition Packet", HFILL }
},
{ &hf_cigi2_special_effect_definition_entity_id,
{ "Entity ID", "cigi.special_effect_def.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates which effect is being modified", HFILL }
},
{ &hf_cigi2_special_effect_definition_seq_direction,
{ "Sequence Direction", "cigi.special_effect_def.seq_direction",
FT_BOOLEAN, 8, TFS(&cigi2_special_effect_definition_seq_direction_tfs), 0x80,
"Indicates whether the effect animation sequence should be sequence from beginning to end or vice versa", HFILL }
},
{ &hf_cigi2_special_effect_definition_color_enable,
{ "Color Enable", "cigi.special_effect_def.color_enable",
FT_BOOLEAN, 8, TFS(&tfs_on_off), 0x40,
"Indicates whether the red, green, and blue color values will be applied to the special effect", HFILL }
},
{ &hf_cigi2_special_effect_definition_red,
{ "Red Color Value", "cigi.special_effect_def.red",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the red component of a color to be applied to the effect", HFILL }
},
{ &hf_cigi2_special_effect_definition_green,
{ "Green Color Value", "cigi.special_effect_def.green",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the green component of a color to be applied to the effect", HFILL }
},
{ &hf_cigi2_special_effect_definition_blue,
{ "Blue Color Value", "cigi.special_effect_def.blue",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the blue component of a color to be applied to the effect", HFILL }
},
{ &hf_cigi2_special_effect_definition_x_scale,
{ "X Scale", "cigi.special_effect_def.x_scale",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies a scale factor to apply along the effect's X axis", HFILL }
},
{ &hf_cigi2_special_effect_definition_y_scale,
{ "Y Scale", "cigi.special_effect_def.y_scale",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies a scale factor to apply along the effect's Y axis", HFILL }
},
{ &hf_cigi2_special_effect_definition_z_scale,
{ "Z Scale", "cigi.special_effect_def.z_scale",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies a scale factor to apply along the effect's Z axis", HFILL }
},
{ &hf_cigi2_special_effect_definition_time_scale,
{ "Time Scale", "cigi.special_effect_def.time_scale",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies a scale factor to apply to the time period for the effect's animation sequence", HFILL }
},
{ &hf_cigi2_special_effect_definition_effect_count,
{ "Effect Count", "cigi.special_effect_def.effect_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates how many effects are contained within a single burst", HFILL }
},
{ &hf_cigi2_special_effect_definition_separation,
{ "Separation (m)", "cigi.special_effect_def.separation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the distance between particles within a burst", HFILL }
},
{ &hf_cigi2_special_effect_definition_burst_interval,
{ "Burst Interval (s)", "cigi.special_effect_def.burst_interval",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the time between successive bursts", HFILL }
},
{ &hf_cigi2_special_effect_definition_duration,
{ "Duration (s)", "cigi.special_effect_def.duration",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates how long an effect or sequence of burst will be active", HFILL }
},
{ &hf_cigi2_view_definition,
{ "View Definition", "cigi.view_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"View Definition Packet", HFILL }
},
{ &hf_cigi2_view_definition_view_id,
{ "View ID", "cigi.view_def.view_id",
FT_UINT8, BASE_DEC, NULL, 0xf8,
"Specifies the view to which this packet should be applied", HFILL }
},
{ &hf_cigi2_view_definition_view_group,
{ "View Group", "cigi.view_def.view_group",
FT_UINT8, BASE_DEC, NULL, 0x07,
"Specifies the view group to which the view is to be assigned", HFILL }
},
{ &hf_cigi2_view_definition_view_type,
{ "View Type", "cigi.view_def.view_type",
FT_UINT8, BASE_DEC, NULL, 0xe0,
"Specifies the view type", HFILL }
},
{ &hf_cigi2_view_definition_pixel_rep,
{ "Pixel Replication", "cigi.view_def.pixel_rep",
FT_UINT8, BASE_DEC, VALS(cigi2_view_definition_pixel_rep_vals), 0x1c,
"Specifies what pixel replication function should be applied to the view", HFILL }
},
{ &hf_cigi2_view_definition_mirror,
{ "View Mirror", "cigi.view_def.mirror",
FT_UINT8, BASE_DEC, VALS(cigi2_view_definition_mirror_vals), 0x03,
"Specifies what mirroring function should be applied to the view", HFILL }
},
{ &hf_cigi2_view_definition_tracker_assign,
{ "Tracker Assign", "cigi.view_def.tracker_assign",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x80,
"Specifies whether the view should be controlled by an external tracking device", HFILL }
},
{ &hf_cigi2_view_definition_near_enable,
{ "Field of View Near Enable", "cigi.view_def.near_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x40,
"Identifies whether the field of view near value is manipulated from the Host", HFILL }
},
{ &hf_cigi2_view_definition_far_enable,
{ "Field of View Far Enable", "cigi.view_def.far_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x20,
"Identifies whether the field of view far value is manipulated from the Host", HFILL }
},
{ &hf_cigi2_view_definition_left_enable,
{ "Field of View Left Enable", "cigi.view_def.left_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Identifies whether the field of view left value is manipulated from the Host", HFILL }
},
{ &hf_cigi2_view_definition_right_enable,
{ "Field of View Right Enable", "cigi.view_def.right_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Identifies whether the field of view right value is manipulated from the Host", HFILL }
},
{ &hf_cigi2_view_definition_top_enable,
{ "Field of View Top Enable", "cigi.view_def.top_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Identifies whether the field of view top value is manipulated from the Host", HFILL }
},
{ &hf_cigi2_view_definition_bottom_enable,
{ "Field of View Bottom Enable", "cigi.view_def.bottom_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x02,
"Identifies whether the field of view bottom value is manipulated from the Host", HFILL }
},
{ &hf_cigi2_view_definition_fov_near,
{ "Field of View Near (m)", "cigi.view_def.fov_near",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the near clipping plane for the view", HFILL }
},
{ &hf_cigi2_view_definition_fov_far,
{ "Field of View Far (m)", "cigi.view_def.fov_far",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the far clipping plane for the view", HFILL }
},
{ &hf_cigi2_view_definition_fov_left,
{ "Field of View Left (degrees)", "cigi.view_def.fov_left",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the left clipping plane for the view", HFILL }
},
{ &hf_cigi2_view_definition_fov_right,
{ "Field of View Right (degrees)", "cigi.view_def.fov_right",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the right clipping plane for the view", HFILL }
},
{ &hf_cigi2_view_definition_fov_top,
{ "Field of View Top (degrees)", "cigi.view_def.fov_top",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the top clipping plane for the view", HFILL }
},
{ &hf_cigi2_view_definition_fov_bottom,
{ "Field of View Bottom (degrees)", "cigi.view_def.fov_bottom",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Defines the bottom clipping plane for the view", HFILL }
},
{ &hf_cigi3_view_definition,
{ "View Definition", "cigi.view_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"View Definition Packet", HFILL }
},
{ &hf_cigi3_view_definition_view_id,
{ "View ID", "cigi.view_def.view_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the view to which the data in this packet will be applied", HFILL }
},
{ &hf_cigi3_view_definition_group_id,
{ "Group ID", "cigi.view_def.group_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the group to which the view is to be assigned", HFILL }
},
{ &hf_cigi3_view_definition_near_enable,
{ "Near Enable", "cigi.view_def.near_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Specifies whether the near clipping plane will be set to the value of the Near parameter within this packet", HFILL }
},
{ &hf_cigi3_view_definition_far_enable,
{ "Far Enable", "cigi.view_def.far_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x02,
"Specifies whether the far clipping plane will be set to the value of the Far parameter within this packet", HFILL }
},
{ &hf_cigi3_view_definition_left_enable,
{ "Left Enable", "cigi.view_def.left_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x04,
"Specifies whether the left half-angle of the view frustum will be set according to the value of the Left parameter within this packet", HFILL }
},
{ &hf_cigi3_view_definition_right_enable,
{ "Right Enable", "cigi.view_def.right_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Specifies whether the right half-angle of the view frustum will be set according to the value of the Right parameter within this packet", HFILL }
},
{ &hf_cigi3_view_definition_top_enable,
{ "Top Enable", "cigi.view_def.top_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x10,
"Specifies whether the top half-angle of the view frustum will be set according to the value of the Top parameter within this packet", HFILL }
},
{ &hf_cigi3_view_definition_bottom_enable,
{ "Bottom Enable", "cigi.view_def.bottom_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x20,
"Specifies whether the bottom half-angle of the view frustum will be set according to the value of the Bottom parameter within this packet", HFILL }
},
{ &hf_cigi3_view_definition_mirror_mode,
{ "Mirror Mode", "cigi.view_def.mirror_mode",
FT_UINT8, BASE_DEC, VALS(cigi3_view_definition_mirror_mode_vals), 0xc0,
"Specifies the mirroring function to be performed on the view", HFILL }
},
{ &hf_cigi3_view_definition_pixel_replication,
{ "Pixel Replication Mode", "cigi.view_def.pixel_replication",
FT_UINT8, BASE_DEC, VALS(cigi3_view_definition_pixel_replication_vals), 0x07,
"Specifies the pixel replication function to be performed on the view", HFILL }
},
{ &hf_cigi3_view_definition_projection_type,
{ "Projection Type", "cigi.view_def.projection_type",
FT_BOOLEAN, 8, TFS(&cigi3_view_definition_projection_type_tfs), 0x08,
"Specifies whether the view projection should be perspective or orthographic parallel", HFILL }
},
{ &hf_cigi3_view_definition_reorder,
{ "Reorder", "cigi.view_def.reorder",
FT_BOOLEAN, 8, TFS(&cigi3_view_definition_reorder_tfs), 0x10,
"Specifies whether the view should be moved to the top of any overlapping views", HFILL }
},
{ &hf_cigi3_view_definition_view_type,
{ "View Type", "cigi.view_def.view_type",
FT_UINT8, BASE_DEC, NULL, 0xe0,
"Specifies an IG-defined type for the indicated view", HFILL }
},
{ &hf_cigi3_view_definition_near,
{ "Near (m)", "cigi.view_def.near",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the position of the view's near clipping plane", HFILL }
},
{ &hf_cigi3_view_definition_far,
{ "Far (m)", "cigi.view_def.far",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the position of the view's far clipping plane", HFILL }
},
{ &hf_cigi3_view_definition_left,
{ "Left (degrees)", "cigi.view_def.left",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the left half-angle of the view frustum", HFILL }
},
{ &hf_cigi3_view_definition_right,
{ "Right (degrees)", "cigi.view_def.right",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the right half-angle of the view frustum", HFILL }
},
{ &hf_cigi3_view_definition_top,
{ "Top (degrees)", "cigi.view_def.top",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the top half-angle of the view frustum", HFILL }
},
{ &hf_cigi3_view_definition_bottom,
{ "Bottom (degrees)", "cigi.view_def.bottom",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the bottom half-angle of the view frustum", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition,
{ "Collision Detection Segment Definition", "cigi.coll_det_seg_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Collision Detection Segment Definition Packet", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_entity_id,
{ "Entity ID", "cigi.coll_det_seg_def.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity to which this collision detection definition is assigned", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_segment_enable,
{ "Segment Enable", "cigi.coll_det_seg_def.segment_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x80,
"Indicates whether the defined segment is enabled for collision testing", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_segment_id,
{ "Segment ID", "cigi.coll_det_seg_def.segment_id",
FT_UINT8, BASE_DEC, NULL, 0x7f,
"Indicates which segment is being uniquely defined for the given entity", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_collision_mask,
{ "Collision Mask", "cigi.coll_det_seg_def.collision_mask",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Indicates which environment features will be included in or excluded from consideration for collision detection testing", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_x_start,
{ "Segment X Start (m)", "cigi.coll_det_seg_def.x_start",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the starting point of the collision segment in the X-axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_y_start,
{ "Segment Y Start (m)", "cigi.coll_det_seg_def.y_start",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the starting point of the collision segment in the Y-axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_z_start,
{ "Segment Z Start (m)", "cigi.coll_det_seg_def.z_start",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the starting point of the collision segment in the Z-axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_x_end,
{ "Segment X End (m)", "cigi.coll_det_seg_def.x_end",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the ending point of the collision segment in the X-axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_y_end,
{ "Segment Y End (m)", "cigi.coll_det_seg_def.y_end",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the ending point of the collision segment in the Y-axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi2_collision_detection_segment_definition_z_end,
{ "Segment Z End (m)", "cigi.coll_det_seg_def.z_end",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the ending point of the collision segment in the Z-axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition,
{ "Collision Detection Segment Definition", "cigi.coll_det_seg_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Collision Detection Segment Definition Packet", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_entity_id,
{ "Entity ID", "cigi.coll_det_seg_def.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity for which the segment is defined", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_segment_id,
{ "Segment ID", "cigi.coll_det_seg_def.segment_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the ID of the segment", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_segment_enable,
{ "Segment Enable", "cigi.coll_det_seg_def.segment_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Specifies whether the segment is enabled or disabled", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_x1,
{ "X1 (m)", "cigi.coll_det_seg_def.x1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the X offset of one endpoint of the collision segment", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_y1,
{ "Y1 (m)", "cigi.coll_det_seg_def.y1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Y offset of one endpoint of the collision segment", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_z1,
{ "Z1 (m)", "cigi.coll_det_seg_def.z1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Z offset of one endpoint of the collision segment", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_x2,
{ "X2 (m)", "cigi.coll_det_seg_def.x2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the X offset of one endpoint of the collision segment", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_y2,
{ "Y2 (m)", "cigi.coll_det_seg_def.y2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Y offset of one endpoint of the collision segment", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_z2,
{ "Z2 (m)", "cigi.coll_det_seg_def.z2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Z offset of one endpoint of the collision segment", HFILL }
},
{ &hf_cigi3_collision_detection_segment_definition_material_mask,
{ "Material Mask", "cigi.coll_det_seg_def.material_mask",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the environmental and cultural features to be included in or excluded from consideration for collision testing", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition,
{ "Collision Detection Volume Definition", "cigi.coll_det_vol_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Collision Detection Volume Definition Packet", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_entity_id,
{ "Entity ID", "cigi.coll_det_vol_def.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity to which this collision detection definition is assigned", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_volume_enable,
{ "Volume Enable", "cigi.coll_det_vol_def.volume_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x80,
"Indicates whether the defined volume is enabled for collision testing", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_volume_id,
{ "Volume ID", "cigi.coll_det_vol_def.volume_id",
FT_UINT8, BASE_DEC, NULL, 0x7f,
"Indicates which volume is being uniquely defined for a given entity", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_x_offset,
{ "Centroid X Offset (m)", "cigi.coll_det_vol_def.x_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the offset of the volume's centroid along the X axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_y_offset,
{ "Centroid Y Offset (m)", "cigi.coll_det_vol_def.y_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the offset of the volume's centroid along the Y axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_z_offset,
{ "Centroid Z Offset (m)", "cigi.coll_det_vol_def.z_offset",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the offset of the volume's centroid along the Z axis with respect to the entity's reference point", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_height,
{ "Height (m)", "cigi.coll_det_vol_def.height",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the height of the volume", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_width,
{ "Width (m)", "cigi.coll_det_vol_def.width",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the width of the volume", HFILL }
},
{ &hf_cigi2_collision_detection_volume_definition_depth,
{ "Depth (m)", "cigi.coll_det_vol_def.depth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the depth of the volume", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition,
{ "Collision Detection Volume Definition", "cigi.coll_det_vol_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Collision Detection Volume Definition Packet", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_entity_id,
{ "Entity ID", "cigi.coll_det_vol_def.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity for which the volume is defined", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_volume_id,
{ "Volume ID", "cigi.coll_det_vol_def.volume_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the ID of the volume", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_volume_enable,
{ "Volume Enable", "cigi.coll_det_vol_def.volume_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x01,
"Specifies whether the volume is enabled or disabled", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_volume_type,
{ "Volume Type", "cigi.coll_det_vol_def.volume_type",
FT_BOOLEAN, 8, TFS(&cigi3_collision_detection_volume_definition_volume_type_tfs), 0x02,
"Specified whether the volume is spherical or cuboid", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_x,
{ "X (m)", "cigi.coll_det_vol_def.x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the X offset of the center of the volume", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_y,
{ "Y (m)", "cigi.coll_det_vol_def.y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Y offset of the center of the volume", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_z,
{ "Z (m)", "cigi.coll_det_vol_def.z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Z offset of the center of the volume", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_radius_height,
{ "Radius (m)/Height (m)", "cigi.coll_det_vol_def.radius_height",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius of the sphere or specifies the length of the cuboid along its Z axis", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_width,
{ "Width (m)", "cigi.coll_det_vol_def.width",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the length of the cuboid along its Y axis", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_depth,
{ "Depth (m)", "cigi.coll_det_vol_def.depth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the length of the cuboid along its X axis", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_roll,
{ "Roll (degrees)", "cigi.coll_det_vol_def.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the roll of the cuboid with respect to the entity's coordinate system", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_pitch,
{ "Pitch (degrees)", "cigi.coll_det_vol_def.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the pitch of the cuboid with respect to the entity's coordinate system", HFILL }
},
{ &hf_cigi3_collision_detection_volume_definition_yaw,
{ "Yaw (degrees)", "cigi.coll_det_vol_def.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the yaw of the cuboid with respect to the entity's coordinate system", HFILL }
},
{ &hf_cigi2_height_above_terrain_request,
{ "Height Above Terrain Request", "cigi.hat_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Height Above Terrain Request Packet", HFILL }
},
{ &hf_cigi2_height_above_terrain_request_hat_id,
{ "HAT ID", "cigi.hat_request.hat_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HAT request", HFILL }
},
{ &hf_cigi2_height_above_terrain_request_alt,
{ "Altitude (m)", "cigi.hat_request.alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude from which the HAT request is being made", HFILL }
},
{ &hf_cigi2_height_above_terrain_request_lat,
{ "Latitude (degrees)", "cigi.hat_request.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitudinal position from which the HAT request is being made", HFILL }
},
{ &hf_cigi2_height_above_terrain_request_lon,
{ "Longitude (degrees)", "cigi.hat_request.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitudinal position from which the HAT request is being made", HFILL }
},
{ &hf_cigi2_line_of_sight_occult_request,
{ "Line of Sight Occult Request", "cigi.los_occult_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Occult Request Packet", HFILL }
},
{ &hf_cigi2_line_of_sight_occult_request_los_id,
{ "LOS ID", "cigi.los_occult_request.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS request", HFILL }
},
{ &hf_cigi2_line_of_sight_occult_request_source_alt,
{ "Source Altitude (m)", "cigi.los_occult_request.source_alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the source point for the LOS request segment", HFILL }
},
{ &hf_cigi2_line_of_sight_occult_request_source_lat,
{ "Source Latitude (degrees)", "cigi.los_occult_request.source_lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitudinal position of the source point for the LOS request segment", HFILL }
},
{ &hf_cigi2_line_of_sight_occult_request_source_lon,
{ "Source Longitude (degrees)", "cigi.los_occult_request.source_lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitudinal position of the source point for the LOS request segment", HFILL }
},
{ &hf_cigi2_line_of_sight_occult_request_dest_alt,
{ "Destination Altitude (m)", "cigi.los_occult_request.dest_alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the destination point for the LOS request segment", HFILL }
},
{ &hf_cigi2_line_of_sight_occult_request_dest_lat,
{ "Destination Latitude (degrees)", "cigi.los_occult_request.dest_lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitudinal position for the destination point for the LOS request segment", HFILL }
},
{ &hf_cigi2_line_of_sight_occult_request_dest_lon,
{ "Destination Longitude (degrees)", "cigi.los_occult_request.dest_lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitudinal position of the destination point for the LOS request segment", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request,
{ "Line of Sight Range Request", "cigi.los_range_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Range Request Packet", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request_los_id,
{ "LOS ID", "cigi.los_range_request.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS request", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request_azimuth,
{ "Azimuth (degrees)", "cigi.los_range_request.azimuth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the azimuth of the LOS vector", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request_elevation,
{ "Elevation (degrees)", "cigi.los_range_request.elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the elevation for the LOS vector", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request_min_range,
{ "Minimum Range (m)", "cigi.los_range_request.min_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the distance from the source position specified in this data packet to a point along the LOS vector where intersection testing will begin", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request_max_range,
{ "Maximum Range (m)", "cigi.los_range_request.max_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the maximum extent from the source position specified in this data packet to a point along the LOS vector where intersection testing will end", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request_source_alt,
{ "Source Altitude (m)", "cigi.los_range_request.source_alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the source point of the LOS request vector", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request_source_lat,
{ "Source Latitude (degrees)", "cigi.los_range_request.source_lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitudinal position of the source point of the LOS request vector", HFILL }
},
{ &hf_cigi2_line_of_sight_range_request_source_lon,
{ "Source Longitude (degrees)", "cigi.los_range_request.source_lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitudinal position of the source point of the LOS request vector", HFILL }
},
{ &hf_cigi2_height_of_terrain_request,
{ "Height of Terrain Request", "cigi.hot_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Height of Terrain Request Packet", HFILL }
},
{ &hf_cigi2_height_of_terrain_request_hot_id,
{ "HOT ID", "cigi.hot_request.hot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HOT request", HFILL }
},
{ &hf_cigi2_height_of_terrain_request_lat,
{ "Latitude (degrees)", "cigi.hot_request.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitudinal position from which the HOT request is made", HFILL }
},
{ &hf_cigi2_height_of_terrain_request_lon,
{ "Longitude (degrees)", "cigi.hot_request.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitudinal position from which the HOT request is made", HFILL }
},
{ &hf_cigi3_hat_hot_request,
{ "HAT/HOT Request", "cigi.hat_hot_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"HAT/HOT Request Packet", HFILL }
},
{ &hf_cigi3_hat_hot_request_hat_hot_id,
{ "HAT/HOT ID", "cigi.hat_hot_request.hat_hot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HAT/HOT request", HFILL }
},
{ &hf_cigi3_hat_hot_request_type,
{ "Request Type", "cigi.hat_hot_request.type",
FT_UINT8, BASE_DEC, VALS(cigi3_hat_hot_request_type_vals), 0x03,
"Determines the type of response packet the IG should return for this packet", HFILL }
},
{ &hf_cigi3_hat_hot_request_coordinate_system,
{ "Coordinate System", "cigi.hat_hot_request.coordinate_system",
FT_BOOLEAN, 8, TFS(&cigi3_hat_hot_request_coordinate_system_tfs), 0x04,
"Specifies the coordinate system within which the test point is defined", HFILL }
},
{ &hf_cigi3_hat_hot_request_entity_id,
{ "Entity ID", "cigi.hat_hot_request.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity relative to which the test point is defined", HFILL }
},
{ &hf_cigi3_hat_hot_request_lat_xoff,
{ "Latitude (degrees)/X Offset (m)", "cigi.hat_hot_request.lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitude from which the HAT/HOT request is being made or specifies the X offset of the point from which the HAT/HOT request is being made", HFILL }
},
{ &hf_cigi3_hat_hot_request_lon_yoff,
{ "Longitude (degrees)/Y Offset (m)", "cigi.hat_hot_request.lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitude from which the HAT/HOT request is being made or specifies the Y offset of the point from which the HAT/HOT request is being made", HFILL }
},
{ &hf_cigi3_hat_hot_request_alt_zoff,
{ "Altitude (m)/Z Offset (m)", "cigi.hat_hot_request.alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude from which the HAT/HOT request is being made or specifies the Z offset of the point from which the HAT/HOT request is being made", HFILL }
},
{ &hf_cigi3_2_hat_hot_request,
{ "HAT/HOT Request", "cigi.hat_hot_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"HAT/HOT Request Packet", HFILL }
},
{ &hf_cigi3_2_hat_hot_request_hat_hot_id,
{ "HAT/HOT ID", "cigi.hat_hot_request.hat_hot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HAT/HOT request", HFILL }
},
{ &hf_cigi3_2_hat_hot_request_type,
{ "Request Type", "cigi.hat_hot_request.type",
FT_UINT8, BASE_DEC, VALS(cigi3_2_hat_hot_request_type_vals), 0x03,
"Determines the type of response packet the IG should return for this packet", HFILL }
},
{ &hf_cigi3_2_hat_hot_request_coordinate_system,
{ "Coordinate System", "cigi.hat_hot_request.coordinate_system",
FT_BOOLEAN, 8, TFS(&cigi3_2_hat_hot_request_coordinate_system_tfs), 0x04,
"Specifies the coordinate system within which the test point is defined", HFILL }
},
{ &hf_cigi3_2_hat_hot_request_update_period,
{ "Update Period", "cigi.hat_hot_request.update_period",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies interval between successive responses to this request. A zero indicates one responses a value n > 0 the IG should respond every nth frame", HFILL }
},
{ &hf_cigi3_2_hat_hot_request_entity_id,
{ "Entity ID", "cigi.hat_hot_request.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity relative to which the test point is defined", HFILL }
},
{ &hf_cigi3_2_hat_hot_request_lat_xoff,
{ "Latitude (degrees)/X Offset (m)", "cigi.hat_hot_request.lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitude from which the HAT/HOT request is being made or specifies the X offset of the point from which the HAT/HOT request is being made", HFILL }
},
{ &hf_cigi3_2_hat_hot_request_lon_yoff,
{ "Longitude (degrees)/Y Offset (m)", "cigi.hat_hot_request.lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitude from which the HAT/HOT request is being made or specifies the Y offset of the point from which the HAT/HOT request is being made", HFILL }
},
{ &hf_cigi3_2_hat_hot_request_alt_zoff,
{ "Altitude (m)/Z Offset (m)", "cigi.hat_hot_request.alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude from which the HAT/HOT request is being made or specifies the Z offset of the point from which the HAT/HOT request is being made", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request,
{ "Line of Sight Segment Request", "cigi.los_segment_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Segment Request Packet", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_los_id,
{ "LOS ID", "cigi.los_segment_request.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS request", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_type,
{ "Request Type", "cigi.los_segment_request.type",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_segment_request_type_tfs), 0x01,
"Determines what type of response the IG should return for this request", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_source_coord,
{ "Source Point Coordinate System", "cigi.los_segment_request.source_coord",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_segment_request_coord_tfs), 0x02,
"Indicates the coordinate system relative to which the test segment source endpoint is specified", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_destination_coord,
{ "Destination Point Coordinate System", "cigi.los_segment_request.destination_coord",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_segment_request_coord_tfs), 0x04,
"Indicates the coordinate system relative to which the test segment destination endpoint is specified", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_response_coord,
{ "Response Coordinate System", "cigi.los_segment_request.response_coord",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_segment_request_coord_tfs), 0x08,
"Specifies the coordinate system to be used in the response", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_alpha_threshold,
{ "Alpha Threshold", "cigi.los_segment_request.alpha_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the minimum alpha value a surface may have for an LOS response to be generated", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_entity_id,
{ "Entity ID", "cigi.los_segment_request.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity relative to which the test segment endpoints are defined", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_source_lat_xoff,
{ "Source Latitude (degrees)/Source X Offset (m)", "cigi.los_segment_request.source_lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitude of the source endpoint of the LOS test segment or specifies the X offset of the source endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_source_lon_yoff,
{ "Source Longitude (degrees)/Source Y Offset (m)", "cigi.los_segment_request.source_lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitude of the source endpoint of the LOS test segment or specifies the Y offset of the source endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_source_alt_zoff,
{ "Source Altitude (m)/Source Z Offset (m)", "cigi.los_segment_request.source_alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the source endpoint of the LOS test segment or specifies the Z offset of the source endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_destination_lat_xoff,
{ "Destination Latitude (degrees)/ Destination X Offset (m)", "cigi.los_segment_request.destination_lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitude of the destination endpoint of the LOS test segment or specifies the X offset of the destination endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_destination_lon_yoff,
{ "Destination Longitude (degrees)/Destination Y Offset (m)", "cigi.los_segment_request.destination_lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitude of the destination endpoint of the LOS test segment or specifies the Y offset of the destination endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_destination_alt_zoff,
{ "Destination Altitude (m)/ Destination Z Offset (m)", "cigi.los_segment_request.destination_alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the destination endpoint of the LOS test segment or specifies the Z offset of the destination endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_line_of_sight_segment_request_material_mask,
{ "Material Mask", "cigi.los_segment_request.material_mask",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the environmental and cultural features to be included in or excluded from consideration for the LOS segment testing", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request,
{ "Line of Sight Segment Request", "cigi.los_segment_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Segment Request Packet", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_los_id,
{ "LOS ID", "cigi.los_segment_request.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS request", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_type,
{ "Request Type", "cigi.los_segment_request.type",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_segment_request_type_tfs), 0x01,
"Determines what type of response the IG should return for this request", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_source_coord,
{ "Source Point Coordinate System", "cigi.los_segment_request.source_coord",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_segment_request_coord_tfs), 0x02,
"Indicates the coordinate system relative to which the test segment source endpoint is specified", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_destination_coord,
{ "Destination Point Coordinate System", "cigi.los_segment_request.destination_coord",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_segment_request_coord_tfs), 0x04,
"Indicates the coordinate system relative to which the test segment destination endpoint is specified", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_response_coord,
{ "Response Coordinate System", "cigi.los_segment_request.response_coord",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_segment_request_coord_tfs), 0x08,
"Specifies the coordinate system to be used in the response", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_destination_entity_id_valid,
{ "Destination Entity ID Valid", "cigi.los_segment_request.destination_entity_id_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x10,
"Destination Entity ID is valid.", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_alpha_threshold,
{ "Alpha Threshold", "cigi.los_segment_request.alpha_threshold",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the minimum alpha value a surface may have for an LOS response to be generated", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_entity_id,
{ "Entity ID", "cigi.los_segment_request.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity relative to which the test segment endpoints are defined", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_source_lat_xoff,
{ "Source Latitude (degrees)/Source X Offset (m)", "cigi.los_segment_request.source_lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitude of the source endpoint of the LOS test segment or specifies the X offset of the source endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_source_lon_yoff,
{ "Source Longitude (degrees)/Source Y Offset (m)", "cigi.los_segment_request.source_lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitude of the source endpoint of the LOS test segment or specifies the Y offset of the source endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_source_alt_zoff,
{ "Source Altitude (m)/Source Z Offset (m)", "cigi.los_segment_request.source_alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the source endpoint of the LOS test segment or specifies the Z offset of the source endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_destination_lat_xoff,
{ "Destination Latitude (degrees)/ Destination X Offset (m)", "cigi.los_segment_request.destination_lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitude of the destination endpoint of the LOS test segment or specifies the X offset of the destination endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_destination_lon_yoff,
{ "Destination Longitude (degrees)/Destination Y Offset (m)", "cigi.los_segment_request.destination_lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitude of the destination endpoint of the LOS test segment or specifies the Y offset of the destination endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_destination_alt_zoff,
{ "Destination Altitude (m)/ Destination Z Offset (m)", "cigi.los_segment_request.destination_alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the destination endpoint of the LOS test segment or specifies the Z offset of the destination endpoint of the LOS test segment", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_material_mask,
{ "Material Mask", "cigi.los_segment_request.material_mask",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the environmental and cultural features to be included in or excluded from consideration for the LOS segment testing", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_update_period,
{ "Update Period", "cigi.los_segment_request.update_period",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies interval between successive responses to this request. A zero indicates one responses a value n > 0 the IG should respond every nth frame", HFILL }
},
{ &hf_cigi3_2_line_of_sight_segment_request_destination_entity_id,
{ "Destination Entity ID", "cigi.los_segment_request.destination_entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity with respect to which the Destination X Offset, Y Offset, and Destination Z Offset parameters are specified", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request,
{ "Line of Sight Vector Request", "cigi.los_vector_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Vector Request Packet", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_los_id,
{ "LOS ID", "cigi.los_vector_request.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS request", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_type,
{ "Request Type", "cigi.los_vector_request.type",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_vector_request_type_tfs), 0x01,
"Determines what type of response the IG should return for this request", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_source_coord,
{ "Source Point Coordinate System", "cigi.los_vector_request.source_coord",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_vector_request_coord_tfs), 0x02,
"Indicates the coordinate system relative to which the test vector source point is specified", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_response_coord,
{ "Response Coordinate System", "cigi.los_vector_request.response_coord",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_vector_request_coord_tfs), 0x04,
"Specifies the coordinate system to be used in the response", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_alpha,
{ "Alpha Threshold", "cigi.los_vector_request.alpha",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the minimum alpha value a surface may have for an LOS response to be generated", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_entity_id,
{ "Entity ID", "cigi.los_vector_request.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity relative to which the test segment endpoints are defined", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_azimuth,
{ "Azimuth (degrees)", "cigi.los_vector_request.azimuth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the horizontal angle of the LOS test vector", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_elevation,
{ "Elevation (degrees)", "cigi.los_vector_request.elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the vertical angle of the LOS test vector", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_min_range,
{ "Minimum Range (m)", "cigi.los_vector_request.min_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the minimum range along the LOS test vector at which intersection testing should occur", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_max_range,
{ "Maximum Range (m)", "cigi.los_vector_request.max_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the maximum range along the LOS test vector at which intersection testing should occur", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_source_lat_xoff,
{ "Source Latitude (degrees)/Source X Offset (m)", "cigi.los_vector_request.source_lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitude of the source point of the LOS test vector", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_source_lon_yoff,
{ "Source Longitude (degrees)/Source Y Offset (m)", "cigi.los_vector_request.source_lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitude of the source point of the LOS test vector", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_source_alt_zoff,
{ "Source Altitude (m)/Source Z Offset (m)", "cigi.los_vector_request.source_alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the source point of the LOS test vector or specifies the Z offset of the source point of the LOS test vector", HFILL }
},
{ &hf_cigi3_line_of_sight_vector_request_material_mask,
{ "Material Mask", "cigi.los_vector_request.material_mask",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the environmental and cultural features to be included in LOS segment testing", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request,
{ "Line of Sight Vector Request", "cigi.los_vector_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Vector Request Packet", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_los_id,
{ "LOS ID", "cigi.los_vector_request.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS request", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_type,
{ "Request Type", "cigi.los_vector_request.type",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_vector_request_type_tfs), 0x01,
"Determines what type of response the IG should return for this request", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_source_coord,
{ "Source Point Coordinate System", "cigi.los_vector_request.source_coord",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_vector_request_coord_tfs), 0x02,
"Indicates the coordinate system relative to which the test vector source point is specified", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_response_coord,
{ "Response Coordinate System", "cigi.los_vector_request.response_coord",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_vector_request_coord_tfs), 0x04,
"Specifies the coordinate system to be used in the response", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_alpha,
{ "Alpha Threshold", "cigi.los_vector_request.alpha",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the minimum alpha value a surface may have for an LOS response to be generated", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_entity_id,
{ "Entity ID", "cigi.los_vector_request.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity relative to which the test segment endpoints are defined", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_azimuth,
{ "Azimuth (degrees)", "cigi.los_vector_request.azimuth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the horizontal angle of the LOS test vector", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_elevation,
{ "Elevation (degrees)", "cigi.los_vector_request.elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the vertical angle of the LOS test vector", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_min_range,
{ "Minimum Range (m)", "cigi.los_vector_request.min_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the minimum range along the LOS test vector at which intersection testing should occur", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_max_range,
{ "Maximum Range (m)", "cigi.los_vector_request.max_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the maximum range along the LOS test vector at which intersection testing should occur", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_source_lat_xoff,
{ "Source Latitude (degrees)/Source X Offset (m)", "cigi.los_vector_request.source_lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitude of the source point of the LOS test vector", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_source_lon_yoff,
{ "Source Longitude (degrees)/Source Y Offset (m)", "cigi.los_vector_request.source_lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitude of the source point of the LOS test vector", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_source_alt_zoff,
{ "Source Altitude (m)/Source Z Offset (m)", "cigi.los_vector_request.source_alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the source point of the LOS test vector or specifies the Z offset of the source point of the LOS test vector", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_material_mask,
{ "Material Mask", "cigi.los_vector_request.material_mask",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the environmental and cultural features to be included in LOS segment testing", HFILL }
},
{ &hf_cigi3_2_line_of_sight_vector_request_update_period,
{ "Update Period", "cigi.los_vector_request.update_period",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies interval between successive responses to this request. A zero indicates one responses a value n > 0 the IG should respond every nth frame", HFILL }
},
{ &hf_cigi3_position_request,
{ "Position Request", "cigi.pos_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Position Request Packet", HFILL }
},
{ &hf_cigi3_position_request_object_id,
{ "Object ID", "cigi.pos_request.object_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the entity, view, view group, or motion tracking device whose position is being requested", HFILL }
},
{ &hf_cigi3_position_request_part_id,
{ "Articulated Part ID", "cigi.pos_request.part_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the articulated part whose position is being requested", HFILL }
},
{ &hf_cigi3_position_request_update_mode,
{ "Update Mode", "cigi.pos_request.update_mode",
FT_BOOLEAN, 8, TFS(&cigi3_position_request_update_mode_tfs), 0x01,
"Specifies whether the IG should report the position of the requested object each frame", HFILL }
},
{ &hf_cigi3_position_request_object_class,
{ "Object Class", "cigi.pos_request.object_class",
FT_UINT8, BASE_DEC, VALS(cigi3_position_request_object_class_vals), 0x0e,
"Specifies the type of object whose position is being requested", HFILL }
},
{ &hf_cigi3_position_request_coord_system,
{ "Coordinate System", "cigi.pos_request.coord_system",
FT_UINT8, BASE_DEC, VALS(cigi3_position_request_coord_system_vals), 0x30,
"Specifies the desired coordinate system relative to which the position and orientation should be given", HFILL }
},
{ &hf_cigi3_environmental_conditions_request,
{ "Environmental Conditions Request", "cigi.env_cond_request",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Environmental Conditions Request Packet", HFILL }
},
{ &hf_cigi3_environmental_conditions_request_type,
{ "Request Type", "cigi.env_cond_request.type",
FT_UINT8, BASE_DEC, VALS(cigi3_environmental_conditions_request_type_vals), 0x0f,
"Specifies the desired response type for the request", HFILL }
},
{ &hf_cigi3_environmental_conditions_request_id,
{ "Request ID", "cigi.env_cond_request.id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the environmental conditions request", HFILL }
},
{ &hf_cigi3_environmental_conditions_request_lat,
{ "Latitude (degrees)", "cigi.env_cond_request.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the geodetic latitude at which the environmental state is requested", HFILL }
},
{ &hf_cigi3_environmental_conditions_request_lon,
{ "Longitude (degrees)", "cigi.env_cond_request.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the geodetic longitude at which the environmental state is requested", HFILL }
},
{ &hf_cigi3_environmental_conditions_request_alt,
{ "Altitude (m)", "cigi.env_cond_request.alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the geodetic altitude at which the environmental state is requested", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition,
{ "Symbol Surface Definition", "cigi.symbl_srfc_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Symbol Surface Definition Packet", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_surface_id,
{ "Surface ID", "cigi.symbl_srfc_def.surface_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the symbol surface to which this packet is applied", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_surface_state,
{ "Surface State", "cigi.symbl_srfc_def.surface_state",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_surface_definition_surface_state_tfs), 0x01,
"Specifies whether the symbol surface should be active or destroyed", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_attach_type,
{ "Attach Type", "cigi.symbl_srfc_def.attach_type",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_surface_definition_attach_type_tfs), 0x02,
"Specifies whether the surface should be attached to an entity or view", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_billboard,
{ "Billboard", "cigi.symbl_srfc_def.billboard",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_surface_definition_billboard_tfs), 0x04,
"Specifies whether the surface is treated as a billboard", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_perspective_growth_enable,
{ "Perspective Growth Enable", "cigi.symbl_srfc_def.perspective_growth_enable",
FT_BOOLEAN, 8, TFS(&cigi_enable_tfs), 0x08,
"Specifies whether the surface appears to maintain a constant size or has perspective growth", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_entity_view_id,
{ "Entity ID/View ID", "cigi.symbl_srfc_def.entity_view_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the entity or view to which this symbol surface is attached", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_xoff_left,
{ "X Offset (m)/Left", "cigi.symbl_srfc_def.xoff_left",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the x offset or leftmost boundary for the symbol surface", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_yoff_right,
{ "Y Offset (m)/Right", "cigi.symbl_srfc_def.yoff_right",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the y offset or rightmost boundary for the symbol surface", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_zoff_top,
{ "Z Offset (m)/Top", "cigi.symbl_srfc_def.zoff_top",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the z offset or topmost boundary for the symbol surface", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_yaw_bottom,
{ "Yaw (degrees)/Bottom", "cigi.symbl_srfc_def.yaw_bottom",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the rotation about the surface's Z axis or bottommost boundary for the symbol surface", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_pitch,
{ "Pitch (degrees)", "cigi.symbl_srfc_def.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the rotation about the surface's Y axis", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_roll,
{ "Roll (degrees)", "cigi.symbl_srfc_def.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the rotation about the surface's X axis", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_width,
{ "Width (m/degrees)", "cigi.symbl_srfc_def.width",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the width of the symbol surface", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_height,
{ "Height (m/degrees)", "cigi.symbl_srfc_def.height",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the height of the symbol surface", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_min_u,
{ "Min U (surface horizontal units)", "cigi.symbl_srfc_def.min_u",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the minimum U coordinate of the symbol surface's viewable area", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_max_u,
{ "Max U (surface horizontal units)", "cigi.symbl_srfc_def.max_u",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the maximum U coordinate of the symbol surface's viewable area", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_min_v,
{ "Min V (surface vertical units)", "cigi.symbl_srfc_def.min_v",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the minimum V coordinate of the symbol surface's viewable area", HFILL }
},
{ &hf_cigi3_3_symbol_surface_definition_max_v,
{ "Max V (surface vertical units)", "cigi.symbl_srfc_def.max_v",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the maximum V coordinate of the symbol surface's viewable area", HFILL }
},
#if 0
{ &hf_cigi3_3_symbol_text_definition,
{ "Symbol Text Definition", "cigi.symbol_text_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Symbol Text Definition Packet", HFILL }
},
#endif
{ &hf_cigi3_3_symbol_text_definition_symbol_id,
{ "Symbol ID", "cigi.symbol_text_def.symbol_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the identifier of the symbol that is being defined", HFILL }
},
{ &hf_cigi3_3_symbol_text_definition_alignment,
{ "Alignment", "cigi.symbol_text_def.alignment",
FT_UINT8, BASE_DEC, VALS(cigi3_3_symbol_text_definition_alignment_vals), 0x0f,
"Specifies the position of the symbol's reference point", HFILL }
},
{ &hf_cigi3_3_symbol_text_definition_orientation,
{ "Orientation", "cigi.symbol_text_def.orientation",
FT_UINT8, BASE_DEC, VALS(cigi3_3_symbol_text_definition_orientation_vals), 0x30,
"Specifies the orientation of the text", HFILL }
},
{ &hf_cigi3_3_symbol_text_definition_font_ident,
{ "Font ID", "cigi.symbol_text_def.font_ident",
FT_UINT8, BASE_DEC, VALS(cigi3_3_symbol_text_definition_font_ident_vals), 0x0,
"Specifies the font to be used", HFILL }
},
{ &hf_cigi3_3_symbol_text_definition_font_size,
{ "Font Size", "cigi.symbol_text_def.font_size",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the font size", HFILL }
},
{ &hf_cigi3_3_symbol_text_definition_text,
{ "Text", "cigi.symbol_text_def.text",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Symbol text", HFILL }
},
#if 0
{ &hf_cigi3_3_symbol_circle_definition,
{ "Symbol Circle Definition", "cigi.symbol_circle_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Symbol Circle Definition Packet", HFILL }
},
#endif
{ &hf_cigi3_3_symbol_circle_definition_symbol_id,
{ "Symbol ID", "cigi.symbol_circle_def.symbol_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the identifier of the symbol that is being defined", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_drawing_style,
{ "Drawing Style", "cigi.symbl_circle_def.drawing_style",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_circle_definition_drawing_style_tfs), 0x01,
"Specifies whether the circles and arcs are curved lines or filled areas", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_stipple_pattern,
{ "Stipple Pattern", "cigi.symbol_circle_def.stipple_pattern",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Specifies the dash pattern used", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_line_width,
{ "Line Width (scaled symbol surface units)", "cigi.symbol_circle_def.line_width",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the thickness of the line", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_stipple_pattern_length,
{ "Stipple Pattern Length (scaled symbol surface units)", "cigi.symbol_circle_def.stipple_pattern_length",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the length of one complete repetition of the stipple pattern", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[0],
{ "Center U 1 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[0],
{ "Center V 1 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[0],
{ "Radius 1 (scaled symbol surface units)", "cigi.symbol_circle_def.radius1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[0],
{ "Inner Radius 1 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[0],
{ "Start Angle 1 (degrees)", "cigi.symbol_circle_def.start_angle1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[0],
{ "End Angle 1 (degrees)", "cigi.symbol_circle_def.end_angle1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[1],
{ "Center U 2 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[1],
{ "Center V 2 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[1],
{ "Radius 2 (scaled symbol surface units)", "cigi.symbol_circle_def.radius2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[1],
{ "Inner Radius 2 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[1],
{ "Start Angle 2 (degrees)", "cigi.symbol_circle_def.start_angle2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[1],
{ "End Angle 2 (degrees)", "cigi.symbol_circle_def.end_angle2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[2],
{ "Center U 3 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[2],
{ "Center V 3 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[2],
{ "Radius 3 (scaled symbol surface units)", "cigi.symbol_circle_def.radius3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[2],
{ "Inner Radius 3 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[2],
{ "Start Angle 3 (degrees)", "cigi.symbol_circle_def.start_angle3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[2],
{ "End Angle 3 (degrees)", "cigi.symbol_circle_def.end_angle3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[3],
{ "Center U 4 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u4",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[3],
{ "Center V 4 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v4",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[3],
{ "Radius 4 (scaled symbol surface units)", "cigi.symbol_circle_def.radius4",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[3],
{ "Inner Radius 4 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius4",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[3],
{ "Start Angle 4 (degrees)", "cigi.symbol_circle_def.start_angle4",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[3],
{ "End Angle 4 (degrees)", "cigi.symbol_circle_def.end_angle4",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[4],
{ "Center U 5 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u5",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[4],
{ "Center V 5 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v5",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[4],
{ "Radius 5 (scaled symbol surface units)", "cigi.symbol_circle_def.radius5",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[4],
{ "Inner Radius 5 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius5",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[4],
{ "Start Angle 5 (degrees)", "cigi.symbol_circle_def.start_angle5",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[4],
{ "End Angle 5 (degrees)", "cigi.symbol_circle_def.end_angle5",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[5],
{ "Center U 6 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u6",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[5],
{ "Center V 6 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v6",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[5],
{ "Radius 6 (scaled symbol surface units)", "cigi.symbol_circle_def.radius6",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[5],
{ "Inner Radius 6 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius6",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[5],
{ "Start Angle 6 (degrees)", "cigi.symbol_circle_def.start_angle6",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[5],
{ "End Angle 6 (degrees)", "cigi.symbol_circle_def.end_angle6",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[6],
{ "Center U 7 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u7",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[6],
{ "Center V 7 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v7",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[6],
{ "Radius 7 (scaled symbol surface units)", "cigi.symbol_circle_def.radius7",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[6],
{ "Inner Radius 7 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius7",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[6],
{ "Start Angle 7 (degrees)", "cigi.symbol_circle_def.start_angle7",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[6],
{ "End Angle 7 (degrees)", "cigi.symbol_circle_def.end_angle7",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[7],
{ "Center U 8 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u8",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[7],
{ "Center V 8 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v8",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[7],
{ "Radius 8 (scaled symbol surface units)", "cigi.symbol_circle_def.radius8",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[7],
{ "Inner Radius 8 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius8",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[7],
{ "Start Angle 8 (degrees)", "cigi.symbol_circle_def.start_angle8",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[7],
{ "End Angle 8 (degrees)", "cigi.symbol_circle_def.end_angle8",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_u[8],
{ "Center U 9 (scaled symbol surface units)", "cigi.symbol_circle_def.center_u9",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_center_v[8],
{ "Center V 9 (scaled symbol surface units)", "cigi.symbol_circle_def.center_v9",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the center", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_radius[8],
{ "Radius 9 (scaled symbol surface units)", "cigi.symbol_circle_def.radius9",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_inner_radius[8],
{ "Inner Radius 9 (scaled symbol surface units)", "cigi.symbol_circle_def.inner_radius9",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the inner radius", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_start_angle[8],
{ "Start Angle 9 (degrees)", "cigi.symbol_circle_def.start_angle9",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the start angle", HFILL }
},
{ &hf_cigi3_3_symbol_circle_definition_end_angle[8],
{ "End Angle 9 (degrees)", "cigi.symbol_circle_def.end_angle9",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the end angle", HFILL }
},
#if 0
{ &hf_cigi3_3_symbol_line_definition,
{ "Symbol Line Definition", "cigi.symbol_line_def",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Symbol Line Definition Packet", HFILL }
},
#endif
{ &hf_cigi3_3_symbol_line_definition_symbol_id,
{ "Symbol ID", "cigi.symbol_line_def.symbol_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the identifier of the symbol that is being defined", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_primitive_type,
{ "Drawing Style", "cigi.symbl_line_def.primitive_type",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_circle_definition_drawing_style_tfs), 0x01,
"Specifies the type of point or line primitive used", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_stipple_pattern,
{ "Stipple Pattern", "cigi.symbol_line_def.stipple_pattern",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Specifies the dash pattern used", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_line_width,
{ "Line Width (scaled symbol surface units)", "cigi.symbol_line_def.line_width",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the thickness of the line", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_stipple_pattern_length,
{ "Stipple Pattern Length (scaled symbol surface units)", "cigi.symbol_line_def.stipple_pattern_length",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the length of one complete repetition of the stipple pattern", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[0],
{ "Vertex U 1 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[0],
{ "Vertex V 1 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[1],
{ "Vertex U 2 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[1],
{ "Vertex V 2 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[2],
{ "Vertex U 3 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[2],
{ "Vertex V 3 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v3",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[3],
{ "Vertex U 4 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u4",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[3],
{ "Vertex V 4 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v4",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[4],
{ "Vertex U 5 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u5",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[4],
{ "Vertex V 5 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v5",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[5],
{ "Vertex U 6 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u6",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[5],
{ "Vertex V 6 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v6",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[6],
{ "Vertex U 7 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u7",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[6],
{ "Vertex V 7 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v7",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[7],
{ "Vertex U 8 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u8",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[7],
{ "Vertex V 8 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v8",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[8],
{ "Vertex U 9 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u9",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[8],
{ "Vertex V 9 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v9",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[9],
{ "Vertex U 10 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u10",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[9],
{ "Vertex V 10 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v10",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[10],
{ "Vertex U 11 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u11",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[10],
{ "Vertex V 11 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v11",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[11],
{ "Vertex U 12 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u12",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[11],
{ "Vertex V 12 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v12",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[12],
{ "Vertex U 13 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u13",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[12],
{ "Vertex V 13 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v13",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[13],
{ "Vertex U 14 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u14",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[13],
{ "Vertex V 14 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v14",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[14],
{ "Vertex U 15 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u15",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[14],
{ "Vertex V 15 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v15",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[15],
{ "Vertex U 16 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u16",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[15],
{ "Vertex V 16 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v16",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[16],
{ "Vertex U 17 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u17",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[16],
{ "Vertex V 17 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v17",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[17],
{ "Vertex U 18 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u18",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[17],
{ "Vertex V 18 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v18",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[18],
{ "Vertex U 19 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u19",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[18],
{ "Vertex V 19 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v19",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[19],
{ "Vertex U 20 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u20",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[19],
{ "Vertex V 20 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v20",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[20],
{ "Vertex U 21 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u21",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[20],
{ "Vertex V 21 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v21",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[21],
{ "Vertex U 22 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u22",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[21],
{ "Vertex V 22 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v22",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[22],
{ "Vertex U 23 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u23",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[22],
{ "Vertex V 23 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v23",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[23],
{ "Vertex U 24 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u24",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[23],
{ "Vertex V 24 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v24",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[24],
{ "Vertex U 25 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u25",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[24],
{ "Vertex V 25 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v25",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[25],
{ "Vertex U 26 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u26",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[25],
{ "Vertex V 26 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v26",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[26],
{ "Vertex U 27 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u27",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[26],
{ "Vertex V 27 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v27",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[27],
{ "Vertex U 28 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u28",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[27],
{ "Vertex V 28 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v28",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_u[28],
{ "Vertex U 29 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_u29",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position of the vertex", HFILL }
},
{ &hf_cigi3_3_symbol_line_definition_vertex_v[28],
{ "Vertex V 29 (scaled symbol surface units)", "cigi.symbol_line_def.vertex_v29",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position of the vertex", HFILL }
},
#if 0
{ &hf_cigi3_3_symbol_clone,
{ "Symbol Surface Definition", "cigi.symbol_clone",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Symbol Clone Packet", HFILL }
},
#endif
{ &hf_cigi3_3_symbol_clone_symbol_id,
{ "Symbol ID", "cigi.symbol_clone.symbol_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the identifier of the symbol that is being defined", HFILL }
},
{ &hf_cigi3_3_symbol_clone_source_type,
{ "Source Type", "cigi.symbol_clone.source_type",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_clone_source_type_tfs), 0x04,
"Identifies the source as an existing symbol or symbol template", HFILL }
},
{ &hf_cigi3_3_symbol_clone_source_id,
{ "Source ID", "cigi.symbol_clone.source_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the symbol to copy or template to instantiate", HFILL }
},
#if 0
{ &hf_cigi3_3_symbol_control,
{ "Symbol Control", "cigi.symbol_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Symbol Control Packet", HFILL }
},
#endif
{ &hf_cigi3_3_symbol_control_symbol_id,
{ "Symbol ID", "cigi.symbol_control.symbol_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the symbol to which this packet is applied", HFILL }
},
{ &hf_cigi3_3_symbol_control_symbol_state,
{ "Symbol State", "cigi.symbol_control.symbol_state",
FT_UINT8, BASE_DEC, VALS(cigi3_3_symbol_control_symbol_state_vals), 0x03,
"Specifies whether the symbol should be hidden, visible, or destroyed", HFILL }
},
{ &hf_cigi3_3_symbol_control_attach_state,
{ "Attach State", "cigi.symbol_control.attach_state",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_control_attach_state_tfs), 0x04,
"Specifies whether this symbol should be attached to another", HFILL }
},
{ &hf_cigi3_3_symbol_control_flash_control,
{ "Flash Control", "cigi.symbol_control.flash_control",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_control_flash_control_tfs), 0x08,
"Specifies whether the flash cycle is continued or restarted", HFILL }
},
{ &hf_cigi3_3_symbol_control_inherit_color,
{ "Inherit Color", "cigi.symbol_control.inherit_color",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_control_inherit_color_tfs), 0x10,
"Specifies whether the symbol inherits color from a parent symbol", HFILL }
},
{ &hf_cigi3_3_symbol_control_parent_symbol_ident,
{ "Parent Symbol ID", "cigi.symbol_control.parent_symbol_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the parent for the symbol", HFILL }
},
{ &hf_cigi3_3_symbol_control_surface_ident,
{ "Surface ID", "cigi.symbol_control.surface_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the symbol surface for the symbol", HFILL }
},
{ &hf_cigi3_3_symbol_control_layer,
{ "Layer", "cigi.symbol_control.layer",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the layer for the symbol", HFILL }
},
{ &hf_cigi3_3_symbol_control_flash_duty_cycle,
{ "Flash Duty Cycle (%)", "cigi.symbol_control.flash_duty_cycle",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the duty cycle for a flashing symbol", HFILL }
},
{ &hf_cigi3_3_symbol_control_flash_period,
{ "Flash Period (seconds)", "cigi.symbol_control.flash_period",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the duration of a single flash cycle", HFILL }
},
{ &hf_cigi3_3_symbol_control_position_u,
{ "Position U (scaled symbol surface units)", "cigi.symbol_control.position_u",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u position", HFILL }
},
{ &hf_cigi3_3_symbol_control_position_v,
{ "Position V (scaled symbol surface units)", "cigi.symbol_control.position_v",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v position", HFILL }
},
{ &hf_cigi3_3_symbol_control_rotation,
{ "Rotation (degrees)", "cigi.symbol_control.rotation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the rotation", HFILL }
},
{ &hf_cigi3_3_symbol_control_red,
{ "Red", "cigi.symbol_control.red",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the red color component", HFILL }
},
{ &hf_cigi3_3_symbol_control_green,
{ "Green", "cigi.symbol_control.green",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the green color component", HFILL }
},
{ &hf_cigi3_3_symbol_control_blue,
{ "Blue", "cigi.symbol_control.blue",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the blue color component", HFILL }
},
{ &hf_cigi3_3_symbol_control_alpha,
{ "Alpha", "cigi.symbol_control.alpha",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the alpha color component", HFILL }
},
{ &hf_cigi3_3_symbol_control_scale_u,
{ "Scale U", "cigi.symbol_control.scale_u",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the u scaling factor", HFILL }
},
{ &hf_cigi3_3_symbol_control_scale_v,
{ "Scale V", "cigi.symbol_control.scale_v",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the v scaling factor", HFILL }
},
#if 0
{ &hf_cigi3_3_short_symbol_control,
{ "Short Symbol Control", "cigi.short_symbol_control",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Short Symbol Control Packet", HFILL }
},
#endif
{ &hf_cigi3_3_short_symbol_control_symbol_id,
{ "Symbol ID", "cigi.short_symbol_control.symbol_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the symbol to which this packet is applied", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_symbol_state,
{ "Symbol State", "cigi.short_symbol_control.symbol_state",
FT_UINT8, BASE_DEC, VALS(cigi3_3_symbol_control_symbol_state_vals), 0x03,
"Specifies whether the symbol should be hidden, visible, or destroyed", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_attach_state,
{ "Attach State", "cigi.short_symbol_control.attach_state",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_control_attach_state_tfs), 0x04,
"Specifies whether this symbol should be attached to another", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_flash_control,
{ "Flash Control", "cigi.short_symbol_control.flash_control",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_control_flash_control_tfs), 0x08,
"Specifies whether the flash cycle is continued or restarted", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_inherit_color,
{ "Inherit Color", "cigi.short_symbol_control.inherit_color",
FT_BOOLEAN, 8, TFS(&cigi3_3_symbol_control_inherit_color_tfs), 0x10,
"Specifies whether the symbol inherits color from a parent symbol", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_attribute_select1,
{ "Attribute Select 1", "cigi.short_symbol_control.attribute_select1",
FT_UINT8, BASE_DEC, VALS(cigi3_3_short_symbol_control_attribute_select_vals), 0x0,
"Identifies the attribute whose value is specified in Attribute Value 1", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_attribute_select2,
{ "Attribute Select 2", "cigi.short_symbol_control.attribute_select2",
FT_UINT8, BASE_DEC, VALS(cigi3_3_short_symbol_control_attribute_select_vals), 0x0,
"Identifies the attribute whose value is specified in Attribute Value 2", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_attribute_value1,
{ "Value 1", "cigi.short_symbol_control.value1",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the value for attribute 1", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_attribute_value2,
{ "Value 2", "cigi.short_symbol_control.value2",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Specifies the value for attribute 2", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_attribute_value1f,
{ "Value 1", "cigi.short_symbol_control.value1",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the value for attribute 1", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_attribute_value2f,
{ "Value 2", "cigi.short_symbol_control.value2",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the value for attribute 2", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_red1,
{ "Red 1", "cigi.short_symbol_control.red1",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the red color component", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_green1,
{ "Green 1", "cigi.short_symbol_control.green1",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the green color component", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_blue1,
{ "Blue 1", "cigi.short_symbol_control.blue1",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the blue color component", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_alpha1,
{ "Alpha 1", "cigi.short_symbol_control.alpha1",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the alpha color component", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_red2,
{ "Red 2", "cigi.short_symbol_control.red2",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the red color component", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_green2,
{ "Green 2", "cigi.short_symbol_control.green2",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the green color component", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_blue2,
{ "Blue 2", "cigi.short_symbol_control.blue2",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the blue color component", HFILL }
},
{ &hf_cigi3_3_short_symbol_control_alpha2,
{ "Alpha 2", "cigi.short_symbol_control.alpha2",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the alpha color component", HFILL }
},
{ &hf_cigi2_start_of_frame,
{ "Start of Frame", "cigi.sof",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Start of Frame Packet", HFILL }
},
{ &hf_cigi2_start_of_frame_db_number,
{ "Database Number", "cigi.sof.db_number",
FT_INT8, BASE_DEC, NULL, 0x0,
"Indicates load status of the requested database", HFILL }
},
{ &hf_cigi2_start_of_frame_ig_status_code,
{ "IG Status Code", "cigi.sof.ig_status_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the operational status of the IG", HFILL }
},
{ &hf_cigi2_start_of_frame_ig_mode,
{ "IG Mode", "cigi.sof.ig_mode",
FT_UINT8, BASE_DEC, VALS(cigi2_start_of_frame_ig_mode_vals), 0xc0,
"Identifies to the host the current operating mode of the IG", HFILL }
},
{ &hf_cigi2_start_of_frame_frame_ctr,
{ "IG to Host Frame Counter", "cigi.sof.frame_ctr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Contains a number representing a particular frame", HFILL }
},
{ &hf_cigi2_start_of_frame_time_tag,
{ "Timing Value (microseconds)", "cigi.sof.time_tag",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Contains a timing value that is used to time-tag the ethernet message during asynchronous operation", HFILL }
},
{ &hf_cigi3_start_of_frame,
{ "Start of Frame", "cigi.sof",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Start of Frame Packet", HFILL }
},
{ &hf_cigi3_start_of_frame_db_number,
{ "Database Number", "cigi.sof.db_number",
FT_INT8, BASE_DEC, NULL, 0x0,
"Indicates to the Host which database is currently in use and if that database is being loaded into primary memory", HFILL }
},
{ &hf_cigi3_start_of_frame_ig_status,
{ "IG Status Code", "cigi.sof.ig_status",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the error status of the IG", HFILL }
},
{ &hf_cigi3_start_of_frame_ig_mode,
{ "IG Mode", "cigi.sof.ig_mode",
FT_UINT8, BASE_DEC, VALS(cigi3_start_of_frame_ig_mode_vals), 0x03,
"Indicates the current IG mode", HFILL }
},
{ &hf_cigi3_start_of_frame_timestamp_valid,
{ "Timestamp Valid", "cigi.sof.timestamp_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x04,
"Indicates whether the Timestamp parameter contains a valid value", HFILL }
},
{ &hf_cigi3_start_of_frame_earth_reference_model,
{ "Earth Reference Model", "cigi.sof.earth_reference_model",
FT_BOOLEAN, 8, TFS(&cigi3_start_of_frame_earth_reference_model_tfs), 0x08,
"Indicates whether the IG is using a custom Earth Reference Model or the default WGS 84 reference ellipsoid for coordinate conversion calculations", HFILL }
},
{ &hf_cigi3_start_of_frame_frame_ctr,
{ "Frame Counter", "cigi.sof.frame_ctr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Contains a number that identifies the frame", HFILL }
},
{ &hf_cigi3_start_of_frame_timestamp,
{ "Timestamp (microseconds)", "cigi.sof.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the number of 10 microsecond \"ticks\" since some initial reference time", HFILL }
},
{ &hf_cigi3_2_start_of_frame,
{ "Start of Frame", "cigi.sof",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Start of Frame Packet", HFILL }
},
{ &hf_cigi3_2_start_of_frame_db_number,
{ "Database Number", "cigi.sof.db_number",
FT_INT8, BASE_DEC, NULL, 0x0,
"Indicates to the Host which database is currently in use and if that database is being loaded into primary memory", HFILL }
},
{ &hf_cigi3_2_start_of_frame_ig_status,
{ "IG Status Code", "cigi.sof.ig_status",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the error status of the IG", HFILL }
},
{ &hf_cigi3_2_start_of_frame_minor_version,
{ "Minor Version", "cigi.sof.minor_version",
FT_UINT8, BASE_DEC, NULL, 0xF0,
"Indicates the minor version of the CIGI interface", HFILL }
},
{ &hf_cigi3_2_start_of_frame_ig_mode,
{ "IG Mode", "cigi.sof.ig_mode",
FT_UINT8, BASE_DEC, VALS(cigi3_2_start_of_frame_ig_mode_vals), 0x03,
"Indicates the current IG mode", HFILL }
},
{ &hf_cigi3_2_start_of_frame_timestamp_valid,
{ "Timestamp Valid", "cigi.sof.timestamp_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x04,
"Indicates whether the Timestamp parameter contains a valid value", HFILL }
},
{ &hf_cigi3_2_start_of_frame_earth_reference_model,
{ "Earth Reference Model", "cigi.sof.earth_reference_model",
FT_BOOLEAN, 8, TFS(&cigi3_2_start_of_frame_earth_reference_model_tfs), 0x08,
"Indicates whether the IG is using a custom Earth Reference Model or the default WGS 84 reference ellipsoid for coordinate conversion calculations", HFILL }
},
{ &hf_cigi3_2_start_of_frame_ig_frame_number,
{ "IG Frame Number", "cigi.sof.ig_frame_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Uniquely identifies the IG data frame", HFILL }
},
{ &hf_cigi3_2_start_of_frame_timestamp,
{ "Timestamp (microseconds)", "cigi.sof.timestamp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the number of 10 microsecond \"ticks\" since some initial reference time", HFILL }
},
{ &hf_cigi3_2_start_of_frame_last_host_frame_number,
{ "Last Host Frame Number", "cigi.sof.last_host_frame_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Contains the value of the Host Frame parameter in the last IG Control packet received from the Host.", HFILL }
},
{ &hf_cigi2_height_above_terrain_response,
{ "Height Above Terrain Response", "cigi.hat_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Height Above Terrain Response Packet", HFILL }
},
{ &hf_cigi2_height_above_terrain_response_hat_id,
{ "HAT ID", "cigi.hat_response.hat_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HAT response", HFILL }
},
{ &hf_cigi2_height_above_terrain_response_valid,
{ "Valid", "cigi.hat_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x80,
"Indicates whether the response is valid or invalid", HFILL }
},
{ &hf_cigi2_height_above_terrain_response_material_type,
{ "Material Type", "cigi.hat_response.material_type",
FT_INT32, BASE_DEC, NULL, 0x0,
"Specifies the material type of the object intersected by the HAT test vector", HFILL }
},
{ &hf_cigi2_height_above_terrain_response_alt,
{ "Altitude (m)", "cigi.hat_response.alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Represents the altitude above or below the terrain for the position requested", HFILL }
},
{ &hf_cigi3_hat_hot_response,
{ "HAT/HOT Response", "cigi.hat_hot_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"HAT/HOT Response Packet", HFILL }
},
{ &hf_cigi3_hat_hot_response_hat_hot_id,
{ "HAT/HOT ID", "cigi.hat_hot_response.hat_hot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HAT or HOT response", HFILL }
},
{ &hf_cigi3_hat_hot_response_valid,
{ "Valid", "cigi.hat_hot_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x01,
"Indicates whether the Height parameter contains a valid number", HFILL }
},
{ &hf_cigi3_hat_hot_response_type,
{ "Response Type", "cigi.hat_hot_response.type",
FT_BOOLEAN, 8, TFS(&cigi3_hat_hot_response_type_tfs), 0x02,
"Indicates whether the Height parameter represent Height Above Terrain or Height Of Terrain", HFILL }
},
{ &hf_cigi3_hat_hot_response_height,
{ "Height", "cigi.hat_hot_response.height",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Contains the requested height", HFILL }
},
{ &hf_cigi3_2_hat_hot_response,
{ "HAT/HOT Response", "cigi.hat_hot_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"HAT/HOT Response Packet", HFILL }
},
{ &hf_cigi3_2_hat_hot_response_hat_hot_id,
{ "HAT/HOT ID", "cigi.hat_hot_response.hat_hot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HAT or HOT response", HFILL }
},
{ &hf_cigi3_2_hat_hot_response_valid,
{ "Valid", "cigi.hat_hot_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x01,
"Indicates whether the Height parameter contains a valid number", HFILL }
},
{ &hf_cigi3_2_hat_hot_response_type,
{ "Response Type", "cigi.hat_hot_response.type",
FT_BOOLEAN, 8, TFS(&cigi3_2_hat_hot_response_type_tfs), 0x02,
"Indicates whether the Height parameter represent Height Above Terrain or Height Of Terrain", HFILL }
},
{ &hf_cigi3_2_hat_hot_response_host_frame_number_lsn,
{ "Host Frame Number LSN", "cigi.hat_hot_response.host_frame_number_lsn",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"Least significant nibble of the host frame number parameter of the last IG Control packet received before the HAT or HOT is calculated", HFILL }
},
{ &hf_cigi3_2_hat_hot_response_height,
{ "Height", "cigi.hat_hot_response.height",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Contains the requested height", HFILL }
},
{ &hf_cigi3_hat_hot_extended_response,
{ "HAT/HOT Extended Response", "cigi.hat_hot_ext_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"HAT/HOT Extended Response Packet", HFILL }
},
{ &hf_cigi3_hat_hot_extended_response_hat_hot_id,
{ "HAT/HOT ID", "cigi.hat_hot_ext_response.hat_hot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HAT/HOT response", HFILL }
},
{ &hf_cigi3_hat_hot_extended_response_valid,
{ "Valid", "cigi.hat_hot_ext_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x01,
"Indicates whether the remaining parameters in this packet contain valid numbers", HFILL }
},
{ &hf_cigi3_hat_hot_extended_response_hat,
{ "HAT", "cigi.hat_hot_ext_response.hat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the height of the test point above the terrain", HFILL }
},
{ &hf_cigi3_hat_hot_extended_response_hot,
{ "HOT", "cigi.hat_hot_ext_response.hot",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the height of terrain above or below the test point", HFILL }
},
{ &hf_cigi3_hat_hot_extended_response_material_code,
{ "Material Code", "cigi.hat_hot_ext_response.material_code",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the material code of the terrain surface at the point of intersection with the HAT/HOT test vector", HFILL }
},
{ &hf_cigi3_hat_hot_extended_response_normal_vector_azimuth,
{ "Normal Vector Azimuth (degrees)", "cigi.hat_hot_ext_response.normal_vector_azimuth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the azimuth of the normal unit vector of the surface intersected by the HAT/HOT test vector", HFILL }
},
{ &hf_cigi3_hat_hot_extended_response_normal_vector_elevation,
{ "Normal Vector Elevation (degrees)", "cigi.hat_hot_ext_response.normal_vector_elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the elevation of the normal unit vector of the surface intersected by the HAT/HOT test vector", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response,
{ "HAT/HOT Extended Response", "cigi.hat_hot_ext_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"HAT/HOT Extended Response Packet", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response_hat_hot_id,
{ "HAT/HOT ID", "cigi.hat_hot_ext_response.hat_hot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HAT/HOT response", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response_valid,
{ "Valid", "cigi.hat_hot_ext_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x01,
"Indicates whether the remaining parameters in this packet contain valid numbers", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response_host_frame_number_lsn,
{ "Host Frame Number LSN", "cigi.hat_hot_ext_response.host_frame_number_lsn",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"Least significant nibble of the host frame number parameter of the last IG Control packet received before the HAT or HOT is calculated", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response_hat,
{ "HAT", "cigi.hat_hot_ext_response.hat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the height of the test point above the terrain", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response_hot,
{ "HOT", "cigi.hat_hot_ext_response.hot",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the height of terrain above or below the test point", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response_material_code,
{ "Material Code", "cigi.hat_hot_ext_response.material_code",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the material code of the terrain surface at the point of intersection with the HAT/HOT test vector", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response_normal_vector_azimuth,
{ "Normal Vector Azimuth (degrees)", "cigi.hat_hot_ext_response.normal_vector_azimuth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the azimuth of the normal unit vector of the surface intersected by the HAT/HOT test vector", HFILL }
},
{ &hf_cigi3_2_hat_hot_extended_response_normal_vector_elevation,
{ "Normal Vector Elevation (degrees)", "cigi.hat_hot_ext_response.normal_vector_elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the elevation of the normal unit vector of the surface intersected by the HAT/HOT test vector", HFILL }
},
{ &hf_cigi2_line_of_sight_response,
{ "Line of Sight Response", "cigi.los_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Response Packet", HFILL }
},
{ &hf_cigi2_line_of_sight_response_los_id,
{ "LOS ID", "cigi.los_response.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS response corresponding tot he associated LOS request", HFILL }
},
{ &hf_cigi2_line_of_sight_response_valid,
{ "Valid", "cigi.los_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x80,
"Indicates whether the response is valid or invalid", HFILL }
},
{ &hf_cigi2_line_of_sight_response_occult_response,
{ "Occult Response", "cigi.los_response.occult_response",
FT_BOOLEAN, 8, TFS(&cigi2_line_of_sight_occult_response_tfs), 0x40,
"Used to respond to the LOS occult request data packet", HFILL }
},
{ &hf_cigi2_line_of_sight_response_material_type,
{ "Material Type", "cigi.los_response.material_type",
FT_INT32, BASE_DEC, NULL, 0x0,
"Specifies the material type of the object intersected by the LOS test segment", HFILL }
},
{ &hf_cigi2_line_of_sight_response_range,
{ "Range (m)", "cigi.los_response.range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Used to respond to the Line of Sight Range Request data packet", HFILL }
},
{ &hf_cigi2_line_of_sight_response_alt,
{ "Intersection Altitude (m)", "cigi.los_response.alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the altitude of the point of intersection of the LOS request vector with an object", HFILL }
},
{ &hf_cigi2_line_of_sight_response_lat,
{ "Intersection Latitude (degrees)", "cigi.los_response.lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the latitudinal position of the intersection point of the LOS request vector with an object", HFILL }
},
{ &hf_cigi2_line_of_sight_response_lon,
{ "Intersection Longitude (degrees)", "cigi.los_response.lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Specifies the longitudinal position of the intersection point of the LOS request vector with an object", HFILL }
},
{ &hf_cigi3_line_of_sight_response,
{ "Line of Sight Response", "cigi.los_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Response Packet", HFILL }
},
{ &hf_cigi3_line_of_sight_response_los_id,
{ "LOS ID", "cigi.los_response.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS response", HFILL }
},
{ &hf_cigi3_line_of_sight_response_valid,
{ "Valid", "cigi.los_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x01,
"Indicates whether the Range parameter is valid", HFILL }
},
{ &hf_cigi3_line_of_sight_response_entity_id_valid,
{ "Entity ID Valid", "cigi.los_response.entity_id_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x02,
"Indicates whether the LOS test vector or segment intersects with an entity or a non-entity", HFILL }
},
{ &hf_cigi3_line_of_sight_response_visible,
{ "Visible", "cigi.los_response.visible",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_response_visible_tfs), 0x04,
"Indicates whether the destination point is visible from the source point", HFILL }
},
{ &hf_cigi3_line_of_sight_response_count,
{ "Response Count", "cigi.los_response.count",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the total number of Line of Sight Response packets the IG will return for the corresponding request", HFILL }
},
{ &hf_cigi3_line_of_sight_response_entity_id,
{ "Entity ID", "cigi.los_response.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity with which an LOS test vector or segment intersects", HFILL }
},
{ &hf_cigi3_line_of_sight_response_range,
{ "Range (m)", "cigi.los_response.range",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the distance along the LOS test segment or vector from the source point to the point of intersection with a polygon surface", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response,
{ "Line of Sight Response", "cigi.los_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Response Packet", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response_los_id,
{ "LOS ID", "cigi.los_response.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS response", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response_valid,
{ "Valid", "cigi.los_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x01,
"Indicates whether the Range parameter is valid", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response_entity_id_valid,
{ "Entity ID Valid", "cigi.los_response.entity_id_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x02,
"Indicates whether the LOS test vector or segment intersects with an entity or a non-entity", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response_visible,
{ "Visible", "cigi.los_response.visible",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_response_visible_tfs), 0x04,
"Indicates whether the destination point is visible from the source point", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response_host_frame_number_lsn,
{ "Host Frame Number LSN", "cigi.los_response.host_frame_number_lsn",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"Least significant nibble of the host frame number parameter of the last IG Control packet received before the HAT or HOT is calculated", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response_count,
{ "Response Count", "cigi.los_response.count",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the total number of Line of Sight Response packets the IG will return for the corresponding request", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response_entity_id,
{ "Entity ID", "cigi.los_response.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity with which an LOS test vector or segment intersects", HFILL }
},
{ &hf_cigi3_2_line_of_sight_response_range,
{ "Range (m)", "cigi.los_response.range",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the distance along the LOS test segment or vector from the source point to the point of intersection with a polygon surface", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response,
{ "Line of Sight Extended Response", "cigi.los_ext_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Extended Response Packet", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_los_id,
{ "LOS ID", "cigi.los_ext_response.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS response", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_valid,
{ "Valid", "cigi.los_ext_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x01,
"Indicates whether this packet contains valid data", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_entity_id_valid,
{ "Entity ID Valid", "cigi.los_ext_response.entity_id_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x02,
"Indicates whether the LOS test vector or segment intersects with an entity", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_range_valid,
{ "Range Valid", "cigi.los_ext_response.range_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x04,
"Indicates whether the Range parameter is valid", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_visible,
{ "Visible", "cigi.los_ext_response.visible",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_extended_response_visible_tfs), 0x08,
"Indicates whether the destination point is visible from the source point", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_intersection_coord,
{ "Intersection Point Coordinate System", "cigi.los_ext_response.intersection_coord",
FT_BOOLEAN, 8, TFS(&cigi3_line_of_sight_extended_response_intersection_coord_tfs), 0x10,
"Indicates the coordinate system relative to which the intersection point is specified", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_response_count,
{ "Response Count", "cigi.los_ext_response.response_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the total number of Line of Sight Extended Response packets the IG will return for the corresponding request", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_entity_id,
{ "Entity ID", "cigi.los_ext_response.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity with which a LOS test vector or segment intersects", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_range,
{ "Range (m)", "cigi.los_ext_response.range",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the distance along the LOS test segment or vector from the source point to the point of intersection with an object", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_lat_xoff,
{ "Latitude (degrees)/X Offset (m)", "cigi.los_ext_response.lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic latitude of the point of intersection along the LOS test segment or vector or specifies the offset of the point of intersection of the LOS test segment or vector along the intersected entity's X axis", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_lon_yoff,
{ "Longitude (degrees)/Y Offset (m)", "cigi.los_ext_response.lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic longitude of the point of intersection along the LOS test segment or vector or specifies the offset of the point of intersection of the LOS test segment or vector along the intersected entity's Y axis", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_alt_zoff,
{ "Altitude (m)/Z Offset(m)", "cigi.los_ext_response.alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic altitude of the point of intersection along the LOS test segment or vector or specifies the offset of the point of intersection of the LOS test segment or vector along the intersected entity's Z axis", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_red,
{ "Red", "cigi.los_ext_response.red",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the red color component of the surface at the point of intersection", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_green,
{ "Green", "cigi.los_ext_response.green",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the green color component of the surface at the point of intersection", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_blue,
{ "Blue", "cigi.los_ext_response.blue",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the blue color component of the surface at the point of intersection", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_alpha,
{ "Alpha", "cigi.los_ext_response.alpha",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the alpha component of the surface at the point of intersection", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_material_code,
{ "Material Code", "cigi.los_ext_response.material_code",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the material code of the surface intersected by the LOS test segment of vector", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_normal_vector_azimuth,
{ "Normal Vector Azimuth (degrees)", "cigi.los_ext_response.normal_vector_azimuth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the azimuth of a unit vector normal to the surface intersected by the LOS test segment or vector", HFILL }
},
{ &hf_cigi3_line_of_sight_extended_response_normal_vector_elevation,
{ "Normal Vector Elevation (degrees)", "cigi.los_ext_response.normal_vector_elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the elevation of a unit vector normal to the surface intersected by the LOS test segment or vector", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response,
{ "Line of Sight Extended Response", "cigi.3_2_los_ext_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Line of Sight Extended Response Packet", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_los_id,
{ "LOS ID", "cigi.3_2_los_ext_response.los_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the LOS response", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_valid,
{ "Valid", "cigi.3_2_los_ext_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x01,
"Indicates whether this packet contains valid data", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_entity_id_valid,
{ "Entity ID Valid", "cigi.3_2_los_ext_response.entity_id_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x02,
"Indicates whether the LOS test vector or segment intersects with an entity", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_range_valid,
{ "Range Valid", "cigi.3_2_los_ext_response.range_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x04,
"Indicates whether the Range parameter is valid", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_visible,
{ "Visible", "cigi.3_2_los_ext_response.visible",
FT_BOOLEAN, 8, TFS(&cigi3_2_line_of_sight_extended_response_visible_tfs), 0x08,
"Indicates whether the destination point is visible from the source point", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_host_frame_number_lsn,
{ "Host Frame Number LSN", "cigi.3_2_los_ext_response.host_frame_number_lsn",
FT_UINT8, BASE_DEC, NULL, 0xf0,
"Least significant nibble of the host frame number parameter of the last IG Control packet received before the HAT or HOT is calculated", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_response_count,
{ "Response Count", "cigi.3_2_los_ext_response.response_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the total number of Line of Sight Extended Response packets the IG will return for the corresponding request", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_entity_id,
{ "Entity ID", "cigi.3_2_los_ext_response.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity with which a LOS test vector or segment intersects", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_range,
{ "Range (m)", "cigi.3_2_los_ext_response.range",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the distance along the LOS test segment or vector from the source point to the point of intersection with an object", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_lat_xoff,
{ "Latitude (degrees)/X Offset (m)", "cigi.3_2_los_ext_response.lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic latitude of the point of intersection along the LOS test segment or vector or specifies the offset of the point of intersection of the LOS test segment or vector along the intersected entity's X axis", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_lon_yoff,
{ "Longitude (degrees)/Y Offset (m)", "cigi.3_2_los_ext_response.lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic longitude of the point of intersection along the LOS test segment or vector or specifies the offset of the point of intersection of the LOS test segment or vector along the intersected entity's Y axis", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_alt_zoff,
{ "Altitude (m)/Z Offset(m)", "cigi.3_2_los_ext_response.alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic altitude of the point of intersection along the LOS test segment or vector or specifies the offset of the point of intersection of the LOS test segment or vector along the intersected entity's Z axis", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_red,
{ "Red", "cigi.3_2_los_ext_response.red",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the red color component of the surface at the point of intersection", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_green,
{ "Green", "cigi.3_2_los_ext_response.green",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the green color component of the surface at the point of intersection", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_blue,
{ "Blue", "cigi.3_2_los_ext_response.blue",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the blue color component of the surface at the point of intersection", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_alpha,
{ "Alpha", "cigi.3_2_los_ext_response.alpha",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the alpha component of the surface at the point of intersection", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_material_code,
{ "Material Code", "cigi.3_2_los_ext_response.material_code",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the material code of the surface intersected by the LOS test segment of vector", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_normal_vector_azimuth,
{ "Normal Vector Azimuth (degrees)", "cigi.3_2_los_ext_response.normal_vector_azimuth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the azimuth of a unit vector normal to the surface intersected by the LOS test segment or vector", HFILL }
},
{ &hf_cigi3_2_line_of_sight_extended_response_normal_vector_elevation,
{ "Normal Vector Elevation (degrees)", "cigi.3_2_los_ext_response.normal_vector_elevation",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the elevation of a unit vector normal to the surface intersected by the LOS test segment or vector", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response,
{ "Collision Detection Segment Response", "cigi.coll_det_seg_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Collision Detection Segment Response Packet", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response_entity_id,
{ "Entity ID", "cigi.coll_det_seg_response.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates which entity experienced a collision", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response_segment_id,
{ "Segment ID", "cigi.coll_det_seg_response.segment_id",
FT_UINT8, BASE_DEC, NULL, 0xfe,
"Identifies the collision segment", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response_contact,
{ "Entity/Non-Entity Contact", "cigi.coll_det_seg_response.contact",
FT_BOOLEAN, 8, TFS(&cigi2_collision_detection_segment_response_contact_tfs), 0x01,
"Indicates whether another entity was contacted during this collision", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response_contacted_entity,
{ "Contacted Entity ID", "cigi.coll_det_seg_response.contacted_entity",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates which entity was contacted during the collision", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response_material_type,
{ "Material Type", "cigi.coll_det_seg_response.material_type",
FT_INT32, BASE_DEC, NULL, 0x0,
"Specifies the material type of the surface that this collision test segment contacted", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response_collision_x,
{ "Collision Point X (m)", "cigi.coll_det_seg_response.collision_x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the X component of a vector, which lies along the defined segment where the segment intersected a surface", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response_collision_y,
{ "Collision Point Y (m)", "cigi.coll_det_seg_response.collision_y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Y component of a vector, which lies along the defined segment where the segment intersected a surface", HFILL }
},
{ &hf_cigi2_collision_detection_segment_response_collision_z,
{ "Collision Point Z (m)", "cigi.coll_det_seg_response.collision_z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the Z component of a vector, which lies along the defined segment where the segment intersected a surface", HFILL }
},
{ &hf_cigi2_sensor_response,
{ "Sensor Response", "cigi.sensor_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Sensor Response Packet", HFILL }
},
{ &hf_cigi2_sensor_response_view_id,
{ "View ID", "cigi.sensor_response.view_id",
FT_UINT8, BASE_DEC, NULL, 0xf8,
"Indicates the sensor view", HFILL }
},
{ &hf_cigi2_sensor_response_status,
{ "Sensor Status", "cigi.sensor_response.status",
FT_UINT8, BASE_DEC, VALS(cigi2_sensor_response_status_vals), 0x06,
"Indicates the current sensor mode", HFILL }
},
{ &hf_cigi2_sensor_response_sensor_id,
{ "Sensor ID", "cigi.sensor_response.sensor_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the sensor response corresponding to the associated sensor control data packet", HFILL }
},
{ &hf_cigi2_sensor_response_x_offset,
{ "Gate X Offset (degrees)", "cigi.sensor_response.x_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the target's horizontal offset from the view plane normal", HFILL }
},
{ &hf_cigi2_sensor_response_y_offset,
{ "Gate Y Offset (degrees)", "cigi.sensor_response.y_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the target's vertical offset from the view plane normal", HFILL }
},
{ &hf_cigi2_sensor_response_x_size,
{ "Gate X Size", "cigi.sensor_response.x_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the target size in the X direction (horizontal) in pixels", HFILL }
},
{ &hf_cigi2_sensor_response_y_size,
{ "Gate Y Size", "cigi.sensor_response.y_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the target size in the Y direction (vertical) in pixels", HFILL }
},
{ &hf_cigi3_sensor_response,
{ "Sensor Response", "cigi.sensor_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Sensor Response Packet", HFILL }
},
{ &hf_cigi3_sensor_response_view_id,
{ "View ID", "cigi.sensor_response.view_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the view that represents the sensor display", HFILL }
},
{ &hf_cigi3_sensor_response_sensor_id,
{ "Sensor ID", "cigi.sensor_response.sensor_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the sensor to which the data in this packet apply", HFILL }
},
{ &hf_cigi3_sensor_response_sensor_status,
{ "Sensor Status", "cigi.sensor_response.sensor_status",
FT_UINT8, BASE_DEC, VALS(cigi3_sensor_response_sensor_status_vals), 0x03,
"Indicates the current tracking state of the sensor", HFILL }
},
{ &hf_cigi3_sensor_response_gate_x_size,
{ "Gate X Size (pixels or raster lines)", "cigi.sensor_response.gate_x_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the gate symbol size along the view's X axis", HFILL }
},
{ &hf_cigi3_sensor_response_gate_y_size,
{ "Gate Y Size (pixels or raster lines)", "cigi.sensor_response.gate_y_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the gate symbol size along the view's Y axis", HFILL }
},
{ &hf_cigi3_sensor_response_gate_x_pos,
{ "Gate X Position (degrees)", "cigi.sensor_response.gate_x_pos",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the gate symbol's position along the view's X axis", HFILL }
},
{ &hf_cigi3_sensor_response_gate_y_pos,
{ "Gate Y Position (degrees)", "cigi.sensor_response.gate_y_pos",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the gate symbol's position along the view's Y axis", HFILL }
},
{ &hf_cigi3_sensor_response_frame_ctr,
{ "Frame Counter", "cigi.sensor_response.frame_ctr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the IG's frame counter at the time that the IG calculates the gate and line-of-sight intersection data", HFILL }
},
{ &hf_cigi3_sensor_extended_response,
{ "Sensor Extended Response", "cigi.sensor_ext_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Sensor Extended Response Packet", HFILL }
},
{ &hf_cigi3_sensor_extended_response_view_id,
{ "View ID", "cigi.sensor_ext_response.view_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the view that represents the sensor display", HFILL }
},
{ &hf_cigi3_sensor_extended_response_sensor_id,
{ "Sensor ID", "cigi.sensor_ext_response.sensor_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Specifies the sensor to which the data in this packet apply", HFILL }
},
{ &hf_cigi3_sensor_extended_response_sensor_status,
{ "Sensor Status", "cigi.sensor_ext_response.sensor_status",
FT_UINT8, BASE_DEC, VALS(cigi3_sensor_extended_response_sensor_status_vals), 0x03,
"Indicates the current tracking state of the sensor", HFILL }
},
{ &hf_cigi3_sensor_extended_response_entity_id_valid,
{ "Entity ID Valid", "cigi.sensor_ext_response.entity_id_valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x04,
"Indicates whether the target is an entity or a non-entity object", HFILL }
},
{ &hf_cigi3_sensor_extended_response_entity_id,
{ "Entity ID", "cigi.sensor_ext_response.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity ID of the target", HFILL }
},
{ &hf_cigi3_sensor_extended_response_gate_x_size,
{ "Gate X Size (pixels or raster lines)", "cigi.sensor_ext_response.gate_x_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the gate symbol size along the view's X axis", HFILL }
},
{ &hf_cigi3_sensor_extended_response_gate_y_size,
{ "Gate Y Size (pixels or raster lines)", "cigi.sensor_ext_response.gate_y_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies the gate symbol size along the view's Y axis", HFILL }
},
{ &hf_cigi3_sensor_extended_response_gate_x_pos,
{ "Gate X Position (degrees)", "cigi.sensor_ext_response.gate_x_pos",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the gate symbol's position along the view's X axis", HFILL }
},
{ &hf_cigi3_sensor_extended_response_gate_y_pos,
{ "Gate Y Position (degrees)", "cigi.sensor_ext_response.gate_y_pos",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Specifies the gate symbol's position along the view's Y axis", HFILL }
},
{ &hf_cigi3_sensor_extended_response_frame_ctr,
{ "Frame Counter", "cigi.sensor_ext_response.frame_ctr",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the IG's frame counter at the time that the IG calculates the gate and line-of-sight intersection data", HFILL }
},
{ &hf_cigi3_sensor_extended_response_track_lat,
{ "Track Point Latitude (degrees)", "cigi.sensor_ext_response.track_lat",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic latitude of the point being tracked by the sensor", HFILL }
},
{ &hf_cigi3_sensor_extended_response_track_lon,
{ "Track Point Longitude (degrees)", "cigi.sensor_ext_response.track_lon",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic longitude of the point being tracked by the sensor", HFILL }
},
{ &hf_cigi3_sensor_extended_response_track_alt,
{ "Track Point Altitude (m)", "cigi.sensor_ext_response.track_alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic altitude of the point being tracked by the sensor", HFILL }
},
{ &hf_cigi2_height_of_terrain_response,
{ "Height of Terrain Response", "cigi.hot_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Height of Terrain Response Packet", HFILL }
},
{ &hf_cigi2_height_of_terrain_response_hot_id,
{ "HOT ID", "cigi.hot_response.hot_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the HOT response corresponding to the associated HOT request", HFILL }
},
{ &hf_cigi2_height_of_terrain_response_valid,
{ "Valid", "cigi.hot_response.valid",
FT_BOOLEAN, 8, TFS(&cigi_valid_tfs), 0x80,
"Indicates whether the response is valid or invalid", HFILL }
},
{ &hf_cigi2_height_of_terrain_response_material_type,
{ "Material Type", "cigi.hot_response.material_type",
FT_INT32, BASE_DEC, NULL, 0x0,
"Specifies the material type of the object intersected by the HOT test segment", HFILL }
},
{ &hf_cigi2_height_of_terrain_response_alt,
{ "Altitude (m)", "cigi.hot_response.alt",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Represents the altitude of the terrain for the position requested in the HOT request data packet", HFILL }
},
{ &hf_cigi2_collision_detection_volume_response,
{ "Collision Detection Volume Response", "cigi.coll_det_vol_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Collision Detection Volume Response Packet", HFILL }
},
{ &hf_cigi2_collision_detection_volume_response_entity_id,
{ "Entity ID", "cigi.coll_det_vol_response.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates which entity experienced a collision", HFILL }
},
{ &hf_cigi2_collision_detection_volume_response_volume_id,
{ "Volume ID", "cigi.coll_det_vol_response.volume_id",
FT_UINT8, BASE_DEC, NULL, 0xfe,
"Identifies the collision volume corresponding to the associated Collision Detection Volume Request", HFILL }
},
{ &hf_cigi2_collision_detection_volume_response_contact,
{ "Entity/Non-Entity Contact", "cigi.coll_det_vol_response.contact",
FT_BOOLEAN, 8, TFS(&cigi2_collision_detection_volume_response_contact_tfs), 0x01,
"Indicates whether another entity was contacted during this collision", HFILL }
},
{ &hf_cigi2_collision_detection_volume_response_contact_entity,
{ "Contacted Entity ID", "cigi.coll_det_vol_response.contact_entity",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates which entity was contacted with during the collision", HFILL }
},
{ &hf_cigi3_position_response,
{ "Position Response", "cigi.pos_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Position Response Packet", HFILL }
},
{ &hf_cigi3_position_response_object_id,
{ "Object ID", "cigi.pos_response.object_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Identifies the entity, view, view group, or motion tracking device whose position is being reported", HFILL }
},
{ &hf_cigi3_position_response_part_id,
{ "Articulated Part ID", "cigi.pos_response.part_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the articulated part whose position is being reported", HFILL }
},
{ &hf_cigi3_position_response_object_class,
{ "Object Class", "cigi.pos_response.object_class",
FT_UINT8, BASE_DEC, VALS(cigi3_position_response_object_class_vals), 0x07,
"Indicates the type of object whose position is being reported", HFILL }
},
{ &hf_cigi3_position_response_coord_system,
{ "Coordinate System", "cigi.pos_response.coord_system",
FT_UINT8, BASE_DEC, VALS(cigi3_position_response_coord_system_vals), 0x18,
"Indicates the coordinate system in which the position and orientation are specified", HFILL }
},
{ &hf_cigi3_position_response_lat_xoff,
{ "Latitude (degrees)/X Offset (m)", "cigi.pos_response.lat_xoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic latitude of the entity, articulated part, view, or view group or indicates the X offset from the parent entity's origin to the child entity, articulated part, view or view group", HFILL }
},
{ &hf_cigi3_position_response_lon_yoff,
{ "Longitude (degrees)/Y Offset (m)", "cigi.pos_response.lon_yoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic longitude of the entity, articulated part, view, or view group or indicates the Y offset from the parent entity's origin to the child entity, articulated part, view, or view group", HFILL }
},
{ &hf_cigi3_position_response_alt_zoff,
{ "Altitude (m)/Z Offset (m)", "cigi.pos_response.alt_zoff",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
"Indicates the geodetic altitude of the entity, articulated part, view, or view group or indicates the Z offset from the parent entity's origin to the child entity, articulated part, view, or view group", HFILL }
},
{ &hf_cigi3_position_response_roll,
{ "Roll (degrees)", "cigi.pos_response.roll",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the roll angle of the specified entity, articulated part, view, or view group", HFILL }
},
{ &hf_cigi3_position_response_pitch,
{ "Pitch (degrees)", "cigi.pos_response.pitch",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the pitch angle of the specified entity, articulated part, view, or view group", HFILL }
},
{ &hf_cigi3_position_response_yaw,
{ "Yaw (degrees)", "cigi.pos_response.yaw",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the yaw angle of the specified entity, articulated part, view, or view group", HFILL }
},
{ &hf_cigi3_weather_conditions_response,
{ "Weather Conditions Response", "cigi.wea_cond_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Weather Conditions Response Packet", HFILL }
},
{ &hf_cigi3_weather_conditions_response_request_id,
{ "Request ID", "cigi.wea_cond_response.request_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the environmental conditions request to which this response packet corresponds", HFILL }
},
{ &hf_cigi3_weather_conditions_response_humidity,
{ "Humidity (%)", "cigi.wea_cond_response.humidity",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the humidity at the request location", HFILL }
},
{ &hf_cigi3_weather_conditions_response_air_temp,
{ "Air Temperature (degrees C)", "cigi.wea_cond_response.air_temp",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the air temperature at the requested location", HFILL }
},
{ &hf_cigi3_weather_conditions_response_visibility_range,
{ "Visibility Range (m)", "cigi.wea_cond_response.visibility_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the visibility range at the requested location", HFILL }
},
{ &hf_cigi3_weather_conditions_response_horiz_speed,
{ "Horizontal Wind Speed (m/s)", "cigi.wea_cond_response.horiz_speed",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the local wind speed parallel to the ellipsoid-tangential reference plane", HFILL }
},
{ &hf_cigi3_weather_conditions_response_vert_speed,
{ "Vertical Wind Speed (m/s)", "cigi.wea_cond_response.vert_speed",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the local vertical wind speed", HFILL }
},
{ &hf_cigi3_weather_conditions_response_wind_direction,
{ "Wind Direction (degrees)", "cigi.wea_cond_response.wind_direction",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the local wind direction", HFILL }
},
{ &hf_cigi3_weather_conditions_response_barometric_pressure,
{ "Barometric Pressure (mb or hPa)", "cigi.wea_cond_response.barometric_pressure",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the atmospheric pressure at the requested location", HFILL }
},
{ &hf_cigi3_aerosol_concentration_response,
{ "Aerosol Concentration Response", "cigi.aerosol_concentration_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Aerosol Concentration Response Packet", HFILL }
},
{ &hf_cigi3_aerosol_concentration_response_request_id,
{ "Request ID", "cigi.aerosol_concentration_response.request_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the environmental conditions request to which this response packet corresponds", HFILL }
},
{ &hf_cigi3_aerosol_concentration_response_layer_id,
{ "Layer ID", "cigi.aerosol_concentration_response.layer_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the weather layer whose aerosol concentration is being described", HFILL }
},
{ &hf_cigi3_aerosol_concentration_response_aerosol_concentration,
{ "Aerosol Concentration (g/m^3)", "cigi.aerosol_concentration_response.aerosol_concentration",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Identifies the concentration of airborne particles", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_response,
{ "Maritime Surface Conditions Response", "cigi.maritime_surface_conditions_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Maritime Surface Conditions Response Packet", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_response_request_id,
{ "Request ID", "cigi.maritime_surface_conditions_response.request_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the environmental conditions request to which this response packet corresponds", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_response_sea_surface_height,
{ "Sea Surface Height (m)", "cigi.maritime_surface_conditions_response.sea_surface_height",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the height of the sea surface at equilibrium", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_response_surface_water_temp,
{ "Surface Water Temperature (degrees C)", "cigi.maritime_surface_conditions_response.surface_water_temp",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the water temperature at the sea surface", HFILL }
},
{ &hf_cigi3_maritime_surface_conditions_response_surface_clarity,
{ "Surface Clarity (%)", "cigi.maritime_surface_conditions_response.surface_clarity",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the clarity of the water at its surface", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_response,
{ "Terrestrial Surface Conditions Response", "cigi.terr_surface_cond_response",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Terrestrial Surface Conditions Response Packet", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_response_request_id,
{ "Request ID", "cigi.terr_surface_cond_response.request_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Identifies the environmental conditions request to which this response packet corresponds", HFILL }
},
{ &hf_cigi3_terrestrial_surface_conditions_response_surface_id,
{ "Surface Condition ID", "cigi.terr_surface_cond_response.surface_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the presence of a specific surface condition or contaminant at the test point", HFILL }
},
{ &hf_cigi3_collision_detection_segment_notification,
{ "Collision Detection Segment Notification", "cigi.coll_det_seg_notification",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Collision Detection Segment Notification Packet", HFILL }
},
{ &hf_cigi3_collision_detection_segment_notification_entity_id,
{ "Entity ID", "cigi.coll_det_seg_notification.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity to which the collision detection segment belongs", HFILL }
},
{ &hf_cigi3_collision_detection_segment_notification_segment_id,
{ "Segment ID", "cigi.coll_det_seg_notification.segment_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the ID of the collision detection segment along which the collision occurred", HFILL }
},
{ &hf_cigi3_collision_detection_segment_notification_type,
{ "Collision Type", "cigi.coll_det_seg_notification.type",
FT_BOOLEAN, 8, TFS(&cigi3_collision_detection_segment_notification_type_tfs), 0x01,
"Indicates whether the collision occurred with another entity or with a non-entity object", HFILL }
},
{ &hf_cigi3_collision_detection_segment_notification_contacted_entity_id,
{ "Contacted Entity ID", "cigi.coll_det_seg_notification.contacted_entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity with which the collision occurred", HFILL }
},
{ &hf_cigi3_collision_detection_segment_notification_material_code,
{ "Material Code", "cigi.coll_det_seg_notification.material_code",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Indicates the material code of the surface at the point of collision", HFILL }
},
{ &hf_cigi3_collision_detection_segment_notification_intersection_distance,
{ "Intersection Distance (m)", "cigi.coll_det_seg_notification.intersection_distance",
FT_FLOAT, BASE_NONE, NULL, 0x0,
"Indicates the distance along the collision test vector from the source endpoint to the point of intersection", HFILL }
},
{ &hf_cigi3_collision_detection_volume_notification,
{ "Collision Detection Volume Notification", "cigi.coll_det_vol_notification",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Collision Detection Volume Notification Packet", HFILL }
},
{ &hf_cigi3_collision_detection_volume_notification_entity_id,
{ "Entity ID", "cigi.coll_det_vol_notification.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity to which the collision detection volume belongs", HFILL }
},
{ &hf_cigi3_collision_detection_volume_notification_volume_id,
{ "Volume ID", "cigi.coll_det_vol_notification.volume_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the ID of the collision detection volume within which the collision occurred", HFILL }
},
{ &hf_cigi3_collision_detection_volume_notification_type,
{ "Collision Type", "cigi.coll_det_vol_notification.type",
FT_BOOLEAN, 8, TFS(&cigi3_collision_detection_volume_notification_type_tfs), 0x01,
"Indicates whether the collision occurred with another entity or with a non-entity object", HFILL }
},
{ &hf_cigi3_collision_detection_volume_notification_contacted_entity_id,
{ "Contacted Entity ID", "cigi.coll_det_vol_notification.contacted_entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity with which the collision occurred", HFILL }
},
{ &hf_cigi3_collision_detection_volume_notification_contacted_volume_id,
{ "Contacted Volume ID", "cigi.coll_det_vol_notification.contacted_volume_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Indicates the ID of the collision detection volume with which the collision occurred", HFILL }
},
{ &hf_cigi3_animation_stop_notification,
{ "Animation Stop Notification", "cigi.animation_stop_notification",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Animation Stop Notification Packet", HFILL }
},
{ &hf_cigi3_animation_stop_notification_entity_id,
{ "Entity ID", "cigi.animation_stop_notification.entity_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates the entity ID of the animation that has stopped", HFILL }
},
{ &hf_cigi3_event_notification,
{ "Event Notification", "cigi.event_notification",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Event Notification Packet", HFILL }
},
{ &hf_cigi3_event_notification_event_id,
{ "Event ID", "cigi.event_notification.event_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Indicates which event has occurred", HFILL }
},
{ &hf_cigi3_event_notification_data_1,
{ "Event Data 1", "cigi.event_notification.data_1",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Used for user-defined event data", HFILL }
},
{ &hf_cigi3_event_notification_data_2,
{ "Event Data 2", "cigi.event_notification.data_2",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Used for user-defined event data", HFILL }
},
{ &hf_cigi3_event_notification_data_3,
{ "Event Data 3", "cigi.event_notification.data_3",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Used for user-defined event data", HFILL }
},
{ &hf_cigi2_image_generator_message,
{ "Image Generator Message", "cigi.image_generator_message",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Image Generator Message Packet", HFILL }
},
{ &hf_cigi2_image_generator_message_id,
{ "Message ID", "cigi.image_generator_message.message_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Uniquely identifies an instance of an Image Generator Response Message", HFILL }
},
{ &hf_cigi2_image_generator_message_message,
{ "Message", "cigi.image_generator_message.message",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Image generator message", HFILL }
},
{ &hf_cigi3_image_generator_message,
{ "Image Generator Message", "cigi.image_generator_message",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Image Generator Message Packet", HFILL }
},
{ &hf_cigi3_image_generator_message_id,
{ "Message ID", "cigi.image_generator_message.message_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Specifies a numerical identifier for the message", HFILL }
},
{ &hf_cigi3_image_generator_message_message,
{ "Message", "cigi.image_generator_message.message",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Message string", HFILL }
},
{ &hf_cigi2_user_definable,
{ "User Definable", "cigi.user_definable",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"User definable packet", HFILL }
},
{ &hf_cigi3_user_defined,
{ "User-Defined", "cigi.user_defined",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"User-Defined Packet", HFILL }
},
};
static const enum_val_t cigi_versions[] = {
{ "from_packet", "From Packet", CIGI_VERSION_FROM_PACKET },
{ "cigi2", "CIGI 2", CIGI_VERSION_2 },
{ "cigi3", "CIGI 3", CIGI_VERSION_3 },
{ NULL, NULL, 0 }
};
static const enum_val_t cigi_byte_orders[] = {
{ "from_packet", "From Packet", CIGI_BYTE_ORDER_FROM_PACKET },
{ "big_endian", "Big-Endian", CIGI_BYTE_ORDER_BIG_ENDIAN },
{ "little_endian", "Little-Endian", CIGI_BYTE_ORDER_LITTLE_ENDIAN },
{ NULL, NULL, 0 }
};
static gint *ett[] = {
&ett_cigi,
};
proto_cigi = proto_register_protocol("Common Image Generator Interface",
"CIGI", "cigi");
proto_register_field_array(proto_cigi, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
cigi_module = prefs_register_protocol(proto_cigi, proto_reg_handoff_cigi);
prefs_register_enum_preference(cigi_module, "version", "CIGI version", "The version of CIGI with which to dissect packets", &global_cigi_version, cigi_versions, FALSE);
prefs_register_enum_preference(cigi_module, "byte_order", "Byte Order", "The byte order with which to dissect CIGI packets (CIGI3)", &global_cigi_byte_order, cigi_byte_orders, FALSE);
prefs_register_string_preference(cigi_module, "host", "Host IP", "IPv4 address or hostname of the host", &global_host_ip);
prefs_register_string_preference(cigi_module, "ig", "Image Generator IP", "IPv4 address or hostname of the image generator", &global_ig_ip);
}
void
proto_reg_handoff_cigi(void)
{
static gboolean inited = FALSE;
if ( global_cigi_version != CIGI_VERSION_FROM_PACKET ) {
cigi_version = global_cigi_version;
}
switch ( global_cigi_byte_order ) {
case CIGI_BYTE_ORDER_BIG_ENDIAN:
cigi_byte_order = ENC_BIG_ENDIAN;
break;
case CIGI_BYTE_ORDER_LITTLE_ENDIAN:
cigi_byte_order = ENC_LITTLE_ENDIAN;
break;
default:
break;
}
if( !inited ) {
cigi_handle = new_create_dissector_handle(dissect_cigi, proto_cigi);
dissector_add_handle("udp.port", cigi_handle);
dissector_add_handle("tcp.port", cigi_handle);
heur_dissector_add("udp", dissect_cigi_heur, proto_cigi);
inited = TRUE;
}
}
