static int dissect_DIS_FIELDS_BURST_DESCRIPTOR(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_burst_descriptor, NULL, "Burst Descriptor");
offset = dissect_DIS_FIELDS_ENTITY_TYPE(tvb, sub_tree, offset, "Munition");
proto_tree_add_item(sub_tree, hf_dis_warhead, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_fuse, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_quality, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_rate, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_DIS_FIELDS_CLOCK_TIME(tvbuff_t *tvb, proto_tree *tree, int offset, const char* clock_name)
{
proto_item *ti;
proto_tree *sub_tree;
static guint MSEC_PER_HOUR = 60 * 60 * 1000;
static guint FSV = 0x7fffffff;
guint32 hour, uintVal;
guint64 ms;
guint isAbsolute = 0;
nstime_t tv;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_clock_time, NULL, clock_name);
hour = tvb_get_ntohl(tvb, offset);
uintVal = tvb_get_ntohl(tvb, offset+4);
isAbsolute = uintVal & 1;
ms = (uintVal >> 1) * MSEC_PER_HOUR / FSV;
tv.secs = (time_t)ms/1000;
tv.nsecs = (int)(ms%1000)*1000000;
tv.secs += (hour*3600);
ti = proto_tree_add_time(sub_tree, hf_dis_clocktime, tvb, offset, 8, &tv);
if (isAbsolute)
{
proto_item_append_text(ti, " (absolute)");
}
else
{
proto_item_append_text(ti, " (relative)");
}
return (offset+8);
}
static int dissect_DIS_FIELDS_ENTITY_TYPE(tvbuff_t *tvb, proto_tree *tree, int offset, const char* entity_name)
{
proto_tree *sub_tree;
int hf_cat = hf_dis_category;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_entity_type, NULL, entity_name);
proto_tree_add_item(sub_tree, hf_dis_entityKind, tvb, offset, 1, ENC_BIG_ENDIAN);
entityKind = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(sub_tree, hf_dis_entityDomain, tvb, offset, 1, ENC_BIG_ENDIAN);
entityDomain = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(sub_tree, hf_dis_country, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (entityKind == DIS_ENTITYKIND_PLATFORM)
{
switch(entityDomain)
{
case DIS_DOMAIN_LAND:
hf_cat = hf_dis_category_land;
break;
case DIS_DOMAIN_AIR:
hf_cat = hf_dis_category_air;
break;
case DIS_DOMAIN_SURFACE:
hf_cat = hf_dis_category_surface;
break;
case DIS_DOMAIN_SUBSURFACE:
hf_cat = hf_dis_category_subsurface;
break;
case DIS_DOMAIN_SPACE:
hf_cat = hf_dis_category_space;
break;
}
}
proto_tree_add_item(sub_tree, hf_cat, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_subcategory, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_specific, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_extra, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int dissect_DIS_FIELDS_RADIO_ENTITY_TYPE(tvbuff_t *tvb, proto_tree *tree, int offset, const char* entity_name)
{
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_radio_entity_type, NULL, entity_name);
proto_tree_add_item(sub_tree, hf_dis_entityKind, tvb, offset, 1, ENC_BIG_ENDIAN);
entityKind = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(sub_tree, hf_dis_entityDomain, tvb, offset, 1, ENC_BIG_ENDIAN);
entityDomain = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(sub_tree, hf_dis_country, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_radio_category, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_nomenclature_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_nomenclature, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_DIS_FIELDS_MODULATION_TYPE(tvbuff_t *tvb, proto_tree *tree, int offset, guint16* systemModulation)
{
proto_tree *sub_tree;
guint32 majorModulation;
int hf_mod_detail;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_modulation_type, NULL, "Modulation Type");
proto_tree_add_item(sub_tree, hf_dis_spread_spectrum_usage, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_dis_frequency_hopping, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_dis_pseudo_noise_modulation, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_dis_time_hopping, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
majorModulation = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dis_modulation_major, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (majorModulation) {
case DIS_MAJOR_MOD_AMPLITUDE:
hf_mod_detail = hf_dis_modulation_amplitude;
break;
case DIS_MAJOR_MOD_AMPLITUDE_AND_ANGLE:
hf_mod_detail = hf_dis_modulation_amplitude_angle;
break;
case DIS_MAJOR_MOD_ANGLE:
hf_mod_detail = hf_dis_modulation_angle;
break;
case DIS_MAJOR_MOD_COMBINATION:
hf_mod_detail = hf_dis_modulation_combination;
break;
case DIS_MAJOR_MOD_PULSE:
hf_mod_detail = hf_dis_modulation_pulse;
break;
case DIS_MAJOR_MOD_UNMODULATED:
hf_mod_detail = hf_dis_modulation_unmodulated;
break;
case DIS_MAJOR_MOD_CPSM:
case DIS_MAJOR_MOD_OTHER:
default:
hf_mod_detail = hf_dis_modulation_detail;
break;
}
proto_tree_add_item(tree, hf_mod_detail, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
*systemModulation = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dis_modulation_system, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_DIS_FIELDS_EVENT_ID(tvbuff_t *tvb, proto_tree *tree, int offset, const char* event_name)
{
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 6, ett_event_id, NULL, event_name);
proto_tree_add_item(sub_tree, hf_dis_site, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_application, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_event_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvbuff_t *tvb, proto_tree *tree, int offset, const char* sim_name)
{
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_simulation_address, NULL, sim_name);
proto_tree_add_item(sub_tree, hf_dis_site, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_application, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_DIS_FIELDS_MOD_PARAMS_CCTT_SINCGARS(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_modulation_parameters, NULL, "Modulation Parameters");
proto_tree_add_item(sub_tree, hf_dis_mod_param_fh_net_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_mod_param_fh_set_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_mod_param_fh_lo_set_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_mod_param_fh_msg_start, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_mod_param_fh_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_mod_param_fh_sync_time_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_mod_param_fh_security_key, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_mod_param_fh_clear_channel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_padding, tvb, offset, 1, ENC_NA);
offset++;
return offset;
}
static int dissect_DIS_FIELDS_MOD_PARAMS_JTIDS_MIDS(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_modulation_parameters, NULL, "Modulation Parameters");
proto_tree_add_item(sub_tree, hf_dis_mod_param_ts_allocation_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_mod_param_transmitter_prim_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_mod_param_transmitter_second_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_mod_param_sync_state, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_mod_param_network_sync_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint parse_DIS_FIELDS_SIGNAL_LINK16_NETWORK_HEADER(tvbuff_t *tvb, proto_tree *tree,
gint offset, guint8* messageType)
{
proto_tree *sub_tree;
nstime_t tv;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_dis_signal_link16_network_header, NULL, "Link 16 Network Header");
proto_tree_add_item(sub_tree, hf_dis_signal_link16_npg, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_signal_link16_network_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_signal_link16_tsec_cvll, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_signal_link16_msec_cvll, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_signal_link16_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
if (messageType)
*messageType = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(sub_tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_signal_link16_time_slot_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
tv.secs = tvb_get_ntohl(tvb, offset);
if (tv.secs == (time_t)0xFFFFFFFF)
{
tv.nsecs = 0;
proto_tree_add_time_format_value(sub_tree, hf_dis_signal_link16_ptt, tvb, offset, 8, &tv, "NO STATEMENT");
}
else
{
proto_tree_add_item(sub_tree, hf_dis_signal_link16_ptt, tvb, offset, 8, ENC_TIME_NTP|ENC_BIG_ENDIAN);
}
offset += 8;
return offset;
}
static gint parse_Link16_Message_Data(proto_tree *tree, tvbuff_t *tvb, gint offset, packet_info *pinfo,
guint32 encodingScheme, guint8 messageType)
{
guint32 cache, value, i;
Link16State state;
tvbuff_t *newtvb;
static const int * jtids_message_header_fields[] = {
&hf_dis_signal_link16_time_slot_type,
&hf_dis_signal_link16_rti,
&hf_dis_signal_link16_stn,
NULL
};
switch (messageType) {
case DIS_MESSAGE_TYPE_JTIDS_HEADER_MESSAGES:
proto_tree_add_bitmask_text(tree, tvb, offset, 4, "JTIDS Header", NULL, ett_dis_signal_link16_jtids_header, jtids_message_header_fields, ENC_BIG_ENDIAN, BMT_NO_APPEND);
cache = tvb_get_ntohl(tvb, offset);
value = (cache >> 4) & 0x7FFF;
col_append_fstr(pinfo->cinfo, COL_INFO, ", STN=0%o, Link 16 Words:", value);
value = (cache >> 19);
offset += 4;
cache = tvb_get_ntohl(tvb, offset);
value |= (cache & 0x7) << 13;
proto_tree_add_uint(tree, hf_dis_signal_link16_sdusn, tvb, offset - 4, 8, value);
offset += 4;
memset(&state, 0, sizeof(state));
for (i = 0; i < (encodingScheme & 0x3FFF); i++) {
gint8 *word = (gint8 *)g_malloc(10);
if (!(i & 1)) {
word[0] = (cache >> 16) & 0xFF;
word[1] = (cache >> 24) & 0xFF;
cache = tvb_get_ntohl(tvb, offset);
offset += 4;
word[2] = cache & 0xFF;
word[3] = (cache >> 8) & 0xFF;
word[4] = (cache >> 16) & 0xFF;
word[5] = (cache >> 24) & 0xFF;
cache = tvb_get_ntohl(tvb, offset);
offset += 4;
word[6] = cache & 0xFF;
word[7] = (cache >> 8) & 0xFF;
word[8] = (cache >> 16) & 0xFF;
word[9] = (cache >> 24) & 0xFF;
} else {
cache = tvb_get_ntohl(tvb, offset);
offset += 4;
word[0] = cache & 0xFF;
word[1] = (cache >> 8) & 0xFF;
word[2] = (cache >> 16) & 0xFF;
word[3] = (cache >> 24) & 0xFF;
cache = tvb_get_ntohl(tvb, offset);
offset += 4;
word[4] = cache & 0xFF;
word[5] = (cache >> 8) & 0xFF;
word[6] = (cache >> 16) & 0xFF;
word[7] = (cache >> 24) & 0xFF;
cache = tvb_get_ntohl(tvb, offset);
offset += 4;
word[8] = cache & 0xFF;
word[9] = (cache >> 8) & 0xFF;
}
newtvb = tvb_new_child_real_data(tvb, word, 10, 10);
tvb_set_free_cb(newtvb, g_free);
add_new_data_source(pinfo, newtvb, "Link 16 Word");
call_dissector_with_data(find_dissector("link16"), newtvb, pinfo, tree, &state);
}
break;
}
return offset;
}
static gint parseField_DIS_FIELDS_FIXED_DATUM(tvbuff_t *tvb, proto_tree *tree, gint offset, const char* field_name, guint32 num_items)
{
proto_tree *sub_tree;
guint32 i;
for (i = 0; i < num_items; i++)
{
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_fixed_datum, NULL, field_name);
proto_tree_add_item(sub_tree, hf_dis_datum_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_fixed_datum_value, tvb, offset, 4, ENC_NA);
offset += 4;
}
return offset;
}
static gint parseField_DIS_FIELDS_VARIABLE_DATUM(tvbuff_t *tvb, proto_tree *tree, gint offset, const char* field_name, guint32 num_items)
{
proto_item *ti;
proto_tree *sub_tree;
guint32 i, data_length, lengthInBytes;
for (i = 0; i < num_items; i++)
{
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_fixed_datum, &ti, field_name);
proto_tree_add_item(sub_tree, hf_dis_datum_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
data_length = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(sub_tree, hf_dis_datum_length, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
lengthInBytes = data_length / 8;
if (data_length % 8 > 0)
lengthInBytes += (8 - (data_length % 8));
proto_tree_add_item(sub_tree, hf_dis_variable_datum_value, tvb, offset, lengthInBytes, ENC_NA);
offset += lengthInBytes;
proto_item_set_end(ti, tvb, offset);
}
return offset;
}
static gint parseField_DIS_FIELDS_FIXED_DATUM_IDS(tvbuff_t *tvb, proto_tree *tree, gint offset, const char* field_name, guint32 num_items)
{
proto_tree *sub_tree;
guint32 i;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, num_items*4, ett_fixed_datum, NULL, field_name);
for (i = 0; i < num_items; i++)
{
proto_tree_add_item(sub_tree, hf_dis_datum_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static gint parseField_DIS_FIELDS_VARIABLE_DATUM_IDS(tvbuff_t *tvb, proto_tree *tree, gint offset, const char* field_name, guint32 num_items)
{
return parseField_DIS_FIELDS_FIXED_DATUM_IDS(tvb, tree, offset, field_name, num_items);
}
static gint parseField_TRACK_JAM(tvbuff_t *tvb, proto_tree *tree, gint offset, const char* entity_name)
{
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 8, ett_trackjam, NULL, entity_name);
proto_tree_add_item(sub_tree, hf_dis_entity_id_site, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_entity_id_application, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_entity_id_entity, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_emitter_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_beam_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static gint dissect_DIS_FIELDS_VP_ARTICULATED_PART(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_dis_vp_change, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_vp_part_attached_to_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_vp_artic_param_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_vp_parameter_value, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static gint dissect_DIS_FIELDS_VP_ATTACHED_PART(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_dis_vp_attached_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_vp_part_attached_to_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_vp_artic_param_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_DIS_FIELDS_ENTITY_TYPE(tvb, tree, offset, "Part Type");
return offset;
}
static gint dissect_DIS_FIELDS_VP_ENTITY_OFFSET(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree *sub_tree;
proto_tree_add_item(tree, hf_dis_vp_offset_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_offset_vector, NULL, "Offset");
proto_tree_add_item(sub_tree, hf_dis_vp_offset_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_vp_offset_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_vp_offset_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint dissect_DIS_FIELDS_VP_ENTITY_ASSOCIATION(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
proto_tree_add_item(tree, hf_dis_vp_change_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_vp_association_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_vp_association_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = parseField_Entity(tvb, tree, offset, "Object Identifier");
proto_tree_add_item(tree, hf_dis_vp_own_station_location, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_vp_phys_conn_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_vp_group_member_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_vp_group_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int dissect_DIS_FIELDS_VR_APPLICATION_HEALTH_STATUS(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_dis_vr_status_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_vr_general_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_vr_specific_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_vr_status_value_int, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_vr_status_value_float, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
return offset;
}
static int dissect_DIS_FIELDS_VR_APPLICATION_INITIALIZATION(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_dis_vr_exercise_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_dis_vr_exercise_file_path, tvb, offset, 256, ENC_ASCII|ENC_NA);
offset += 256;
proto_tree_add_item(tree, hf_dis_vr_exercise_file_name, tvb, offset, 128, ENC_ASCII|ENC_NA);
offset += 128;
proto_tree_add_item(tree, hf_dis_vr_application_role, tvb, offset, 64, ENC_ASCII|ENC_NA);
offset += 64;
return offset;
}
static int dissect_DIS_FIELDS_VR_DATA_QUERY(tvbuff_t *tvb, proto_tree *tree, int offset)
{
guint32 numFixed;
numFixed = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dis_vr_num_records, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = parseField_DIS_FIELDS_FIXED_DATUM_IDS(tvb, tree, offset, "Record", numFixed);
return offset;
}
static int dissect_DIS_PARSER_ENTITY_STATE_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *sub_tree;
guint8 variableParameterType, numVariable;
guint32 i;
offset = parseField_Entity(tvb, tree, offset, "Entity ID");
proto_tree_add_item(tree, hf_dis_force_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numVariable = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_art_params, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset = dissect_DIS_FIELDS_ENTITY_TYPE(tvb, tree, offset, "Entity Type");
col_append_fstr( pinfo->cinfo, COL_INFO, ", %s, %s",
val_to_str_const(entityKind, DIS_PDU_EntityKind_Strings, "Unknown Entity Kind"),
val_to_str_const(entityDomain, DIS_PDU_Domain_Strings, "Unknown Entity Domain")
);
offset = dissect_DIS_FIELDS_ENTITY_TYPE(tvb, tree, offset, "Alternative Entity Type");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_entity_linear_velocity, NULL, "Entity Linear Velocity");
proto_tree_add_item(sub_tree, hf_dis_entity_linear_velocity_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_entity_linear_velocity_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_entity_linear_velocity_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 24, ett_entity_location, NULL, "Entity Location");
proto_tree_add_item(sub_tree, hf_dis_entity_location_x_double, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_dis_entity_location_y_double, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_dis_entity_location_z_double, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_entity_orientation, NULL, "Entity Orientation");
proto_tree_add_item(sub_tree, hf_dis_entity_orientation_psi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_entity_orientation_theta, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_entity_orientation_phi, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 4, ett_entity_appearance, NULL, "Entity Appearance");
if ((entityKind == DIS_ENTITYKIND_PLATFORM) &&
(entityDomain == DIS_DOMAIN_LAND))
{
proto_tree_add_item(sub_tree, hf_appearance_landform_paint_scheme, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_appearance_landform_mobility, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_appearance_landform_fire_power, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_appearance_landform_damage, tvb, offset, 4, ENC_BIG_ENDIAN);
}
else if (entityKind == DIS_ENTITYKIND_LIFE_FORM)
{
proto_tree_add_item(sub_tree, hf_appearance_lifeform_paint_scheme, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_appearance_lifeform_health, tvb, offset, 4, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(sub_tree, hf_entity_appearance, tvb, offset, 4, ENC_BIG_ENDIAN);
}
offset += 4;
proto_tree_add_item(tree, hf_dis_dead_reckoning_parameters, tvb, offset, 40, ENC_NA);
offset += 40;
proto_tree_add_item(tree, hf_dis_entity_marking, tvb, offset, 12, ENC_NA);
offset += 12;
proto_tree_add_item(tree, hf_dis_capabilities, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (i = 0; i < numVariable; i++)
{
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_variable_parameter, &ti, "Variable Parameter");
proto_tree_add_item(sub_tree, hf_dis_variable_parameter_type, tvb, offset, 1, ENC_BIG_ENDIAN);
variableParameterType = tvb_get_guint8(tvb, offset);
offset++;
offset = parseField_VariableParameter(tvb, sub_tree, offset, variableParameterType);
proto_item_set_end(ti, tvb, offset);
}
return offset;
}
static int dissect_DIS_PARSER_ELECTROMAGNETIC_EMISSION_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *emission_ti, *beam_ti;
proto_tree *sub_tree, *sub_tree2, *fundamental_tree;
guint8 i, j, k, numVariable, numBeams, numTrackJamTargets;
offset = parseField_Entity(tvb, tree, offset, "Emitting Entity ID");
offset = dissect_DIS_FIELDS_EVENT_ID(tvb, tree, offset, "Event ID");
proto_tree_add_item(tree, hf_dis_state_update_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numVariable = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_electromagnetic_emission_systems, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
for (i = 0; i < numVariable; i++)
{
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_emission_system, &emission_ti, "Emission System");
proto_tree_add_item(sub_tree, hf_dis_em_data_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numBeams = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sub_tree, hf_dis_em_num_beams, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
sub_tree2 = proto_tree_add_subtree(sub_tree, tvb, offset, 4, ett_emitter_system, NULL, "Emitter System");
proto_tree_add_item(sub_tree2, hf_dis_emitter_name, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree2, hf_dis_emission_function, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree2, hf_dis_emitter_id_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
sub_tree2 = proto_tree_add_subtree(sub_tree, tvb, offset, 12, ett_emitter_location, NULL, "Location");
proto_tree_add_item(sub_tree2, hf_dis_em_location_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree2, hf_dis_em_location_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree2, hf_dis_em_location_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (j = 0; j < numBeams; j++)
{
sub_tree2 = proto_tree_add_subtree(sub_tree, tvb, offset, -1, ett_em_beam, &beam_ti, "Beam");
proto_tree_add_item(sub_tree2, hf_dis_em_beam_data_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree2, hf_dis_em_beam_id_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree2, hf_dis_em_beam_parameter_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
fundamental_tree = proto_tree_add_subtree(sub_tree2, tvb, offset, 40, ett_em_fundamental_parameter_data, NULL, "Fundamental Parameter Data");
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_frequency, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_frequency_range, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_effective_radiated_power, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_pulse_repition_freq, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_pulse_width, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_beam_azimuth_center, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_beam_azimuth_sweep, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_beam_elevation_center, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_beam_elevation_sweep, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(fundamental_tree, hf_dis_em_fund_beem_sweep_sync, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree2, hf_dis_beam_function, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numTrackJamTargets = tvb_get_guint8(tvb, offset);
proto_tree_add_item(sub_tree2, hf_dis_track_jam_num_targ, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree2, hf_dis_track_jam_high_density, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree2, hf_dis_padding, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(sub_tree2, hf_dis_jamming_mode_seq, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
for (k = 0; k < numTrackJamTargets; k++)
{
offset = parseField_TRACK_JAM(tvb, sub_tree2, offset, "Track/Jam Entity");
}
proto_item_set_end(beam_ti, tvb, offset);
}
proto_item_set_end(emission_ti, tvb, offset);
}
return offset;
}
static int dissect_DIS_PARSER_UNDERWATER_ACOUSTIC_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_tree *sub_tree, *sub_tree2;
guint8 i, numShafts, numApas, numUAEmitter, numUABeams = 0;
offset = parseField_Entity(tvb, tree, offset, "Emitting Entity ID");
offset = dissect_DIS_FIELDS_EVENT_ID(tvb, tree, offset, "Event ID");
proto_tree_add_item(tree, hf_dis_state_update_indicator, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_dis_passive_parameter_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_propulsion_plant_config, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numShafts = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_shafts, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numApas = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_apas, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numUAEmitter = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_ua_emitter_systems, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
col_append_fstr( pinfo->cinfo, COL_INFO, ", Shafts=%d, APA=%d, Acoustic Emitter=%d",
numShafts, numApas, numUAEmitter);
for (i = 0; i < numShafts; i++)
{
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 6, ett_shafts, NULL, "Shafts [%d of %d]", i+1, numShafts);
proto_tree_add_item(sub_tree, hf_dis_shaft_rpm_current, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_shaft_rpm_ordered, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_shaft_rpm_change_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
for (i = 0; i < numApas; i++)
{
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 4, ett_apas, NULL, "APAs [%d of %d]", i+1, numApas);
proto_tree_add_item(sub_tree, hf_dis_apas_parameter_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_apas_value, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
for (i = 0; i < numUAEmitter; i++)
{
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 20, ett_underwater_acoustic_emission, NULL,
"Underwater Acoustic Emission System [%d of %d]", i+1, numUAEmitter);
proto_tree_add_item(sub_tree, hf_dis_ua_emitter_data_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numUABeams += tvb_get_guint8(tvb, offset);
proto_tree_add_item(sub_tree, hf_dis_ua_num_beams, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
sub_tree2 = proto_tree_add_subtree(sub_tree, tvb, offset, 4, ett_acoustic_emitter_system, NULL, "Acoustic Emitter System");
proto_tree_add_item(sub_tree2, hf_dis_ua_emission_name, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree2, hf_dis_ua_emission_function, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree2, hf_dis_ua_emission_id_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
sub_tree2 = proto_tree_add_subtree(sub_tree, tvb, offset, 12, ett_ua_location, NULL, "Location (with respect to entity)");
proto_tree_add_item(sub_tree2, hf_dis_ua_location_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree2, hf_dis_ua_location_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree2, hf_dis_ua_location_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
for (i = 0; i < numUABeams; ++i)
{
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, 24, ett_ua_beams, NULL, "Beams [%d of %d]", i+1, numUABeams);
proto_tree_add_item(sub_tree, hf_dis_ua_beam_data_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_ua_beam_id_number, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(sub_tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
sub_tree2 = proto_tree_add_subtree_format(sub_tree, tvb, offset, 20, ett_ua_beam_data, NULL, "Fundamental Data Parameters");
proto_tree_add_item(sub_tree2, hf_dis_ua_beam_active_emission_parameter_index, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree2, hf_dis_ua_beam_scan_pattern, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree2, hf_dis_ua_beam_center_azimuth, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree2, hf_dis_ua_beam_azimuthal_beamwidth, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree2, hf_dis_ua_beam_center_de, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree2, hf_dis_ua_beam_de_beamwidth, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
return offset;
}
static int dissect_DIS_PARSER_IFF_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *sub_tree,*field_tree;
guint16 site, application, entity, parameter_5, mode1, mode2, mode3;
gint16 altitude;
site = tvb_get_ntohs(tvb, offset);
application = tvb_get_ntohs(tvb, offset+2);
entity = tvb_get_ntohs(tvb, offset+4);
offset = parseField_Entity(tvb, tree, offset, "Emitting Entity ID");
offset = dissect_DIS_FIELDS_EVENT_ID(tvb, tree, offset, "Event ID");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_iff_location, NULL, "Location (with respect to entity)");
proto_tree_add_item(sub_tree, hf_dis_ua_location_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_ua_location_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_ua_location_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 6, ett_iff_system_id, NULL, "System ID");
proto_tree_add_item(sub_tree, hf_dis_iff_system_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_iff_system_name, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_iff_system_mode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_item(sub_tree, hf_dis_iff_change_options, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_change_options);
proto_tree_add_bits_item(field_tree, hf_dis_iff_change_indicator, tvb, offset*8+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_alternate_mode_4, tvb, offset*8+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_alternate_mode_c, tvb, offset*8+5, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 16, ett_iff_fundamental_operational_data, NULL, "Fundamental Operational Data");
ti = proto_tree_add_item(sub_tree, hf_dis_iff_system_status, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_system_status);
proto_tree_add_bits_item(field_tree, hf_dis_iff_system_status_system_onoff, tvb, offset*8+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_system_status_parameter_1, tvb, offset*8+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_system_status_parameter_2, tvb, offset*8+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_system_status_parameter_3, tvb, offset*8+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_system_status_parameter_4, tvb, offset*8+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_system_status_parameter_5, tvb, offset*8+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_system_status_parameter_6, tvb, offset*8+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_system_status_operational, tvb, offset*8, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(sub_tree, hf_dis_iff_alternate_parameter_4, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_item(sub_tree, hf_dis_iff_information_layers, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_information_layers);
proto_tree_add_bits_item(field_tree, hf_dis_iff_information_layers_layer_1, tvb, offset*8+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_information_layers_layer_2, tvb, offset*8+5, 1, ENC_BIG_ENDIAN);
offset += 1;
ti = proto_tree_add_item(sub_tree, hf_dis_iff_modifier, tvb, offset, 1, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_modifier);
proto_tree_add_bits_item(field_tree, hf_dis_iff_modifier_other, tvb, offset*8+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_modifier_emergency, tvb, offset*8+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_modifier_ident, tvb, offset*8+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_modifier_sti, tvb, offset*8+4, 1, ENC_BIG_ENDIAN);
offset += 1;
mode1 = tvb_get_ntohs(tvb, offset) & 0x3f;
ti = proto_tree_add_item(sub_tree, hf_dis_iff_parameter_1, tvb, offset, 2, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_parameter_1);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_1, tvb, offset*8+10, 6, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_status, tvb, offset*8+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_damage, tvb, offset*8+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_malfunction, tvb, offset*8, 1, ENC_BIG_ENDIAN);
offset += 2;
mode2 = tvb_get_ntohs(tvb, offset) & 0xfff;
ti = proto_tree_add_item(sub_tree, hf_dis_iff_parameter_2, tvb, offset, 2, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_parameter_2);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_2, tvb, offset*8+4, 12, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_status, tvb, offset*8+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_damage, tvb, offset*8+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_malfunction, tvb, offset*8, 1, ENC_BIG_ENDIAN);
offset += 2;
mode3 = tvb_get_ntohs(tvb, offset) & 0xfff;
ti = proto_tree_add_item(sub_tree, hf_dis_iff_parameter_3, tvb, offset, 2, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_parameter_3);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_3, tvb, offset*8+4, 12, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_status, tvb, offset*8+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_damage, tvb, offset*8+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_malfunction, tvb, offset*8, 1, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(sub_tree, hf_dis_iff_parameter_4, tvb, offset, 2, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_parameter_4);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_4, tvb, offset*8+4, 12, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_status, tvb, offset*8+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_damage, tvb, offset*8+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_malfunction, tvb, offset*8, 1, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(sub_tree, hf_dis_iff_parameter_5, tvb, offset, 2, ENC_BIG_ENDIAN);
field_tree = proto_item_add_subtree(ti, ett_iff_parameter_5);
parameter_5 = tvb_get_ntohs(tvb, offset);
altitude = ((parameter_5 >> 1) & 0x7ff) * ((parameter_5 & 1) ? -1: 1);
proto_tree_add_int(field_tree, hf_dis_iff_mode_c, tvb, offset, 2, altitude);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_status, tvb, offset*8+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_damage, tvb, offset*8+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(field_tree, hf_dis_iff_mode_malfunction, tvb, offset*8, 1, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_iff_parameter_6, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, ", %d-%d-%d", site, application, entity);
if (mode1) col_append_fstr(pinfo->cinfo, COL_INFO, ", 1=%02o", mode1);
if (mode2) col_append_fstr(pinfo->cinfo, COL_INFO, ", 2=%04o", mode2);
if (mode3) col_append_fstr(pinfo->cinfo, COL_INFO, ", 3=%04o", mode3);
if (altitude || (parameter_5 & 0x2000)) col_append_fstr(pinfo->cinfo, COL_INFO, ", C=FL%d", altitude);
return offset;
}
static int dissect_DIS_PARSER_TRANSMITTER_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item* ti;
proto_tree* sub_tree;
guint32 radioID, disRadioTransmitState, modulationParamLength;
guint16 systemModulation;
offset = parseField_Entity(tvb, tree, offset, "Entity ID");
proto_tree_add_item(tree, hf_dis_radio_id, tvb, offset, 2, ENC_BIG_ENDIAN);
radioID = tvb_get_ntohs(tvb, offset);
col_append_fstr( pinfo->cinfo, COL_INFO, ", RadioID=%u", radioID);
offset += 2;
offset = dissect_DIS_FIELDS_RADIO_ENTITY_TYPE(tvb, tree, offset, "Radio Entity Type");
disRadioTransmitState = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dis_radio_transmit_state, tvb, offset, 1, ENC_BIG_ENDIAN);
col_append_fstr( pinfo->cinfo, COL_INFO, ", Transmit State=%s", val_to_str_const(disRadioTransmitState, DIS_PDU_RadioTransmitState_Strings, "Unknown Transmit State"));
offset++;
proto_tree_add_item(tree, hf_dis_radio_input_source, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 24, ett_antenna_location, NULL, "Antenna Location");
proto_tree_add_item(sub_tree, hf_dis_antenna_location_x, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_dis_antenna_location_y, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_dis_antenna_location_z, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_rel_antenna_location, NULL, "Relative Antenna Location");
proto_tree_add_item(sub_tree, hf_dis_rel_antenna_location_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_rel_antenna_location_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_rel_antenna_location_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_antenna_pattern_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_antenna_pattern_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_transmit_frequency, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(tree, hf_dis_transmit_freq_bandwidth, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_transmit_power, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = dissect_DIS_FIELDS_MODULATION_TYPE(tvb, tree, offset, &systemModulation);
proto_tree_add_item(tree, hf_dis_crypto_system, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(tree, hf_dis_crypto_key, tvb, offset, 2, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(ti, ett_dis_crypto_key);
proto_tree_add_item(sub_tree, hf_dis_encryption_mode, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree, hf_dis_key_identifier, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
modulationParamLength = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dis_modulation_parameter_length, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 3, ENC_NA);
offset += 3;
if (modulationParamLength > 0 ) {
switch(systemModulation)
{
case DIS_SYSTEM_MOD_CCTT_SINCGARS:
offset = dissect_DIS_FIELDS_MOD_PARAMS_CCTT_SINCGARS(tvb, sub_tree, offset);
break;
case DIS_SYSTEM_MOD_JTIDS_MIDS:
offset = dissect_DIS_FIELDS_MOD_PARAMS_JTIDS_MIDS(tvb, sub_tree, offset);
break;
default:
proto_tree_add_item(tree, hf_dis_mod_param_dump, tvb, offset, modulationParamLength, ENC_NA );
offset += modulationParamLength;
break;
}
}
return offset;
}
static int dissect_DIS_PARSER_SIGNAL_PDU(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item* ti;
proto_tree* sub_tree;
guint32 radioID, encodingScheme, numSamples;
guint16 tdlType;
guint8 messageType;
offset = parseField_Entity(tvb, tree, offset, "Entity ID");
proto_tree_add_item(tree, hf_dis_radio_id, tvb, offset, 2, ENC_BIG_ENDIAN);
radioID = tvb_get_ntohs(tvb, offset);
col_append_fstr( pinfo->cinfo, COL_INFO, ", RadioID=%u", radioID);
offset += 2;
encodingScheme = tvb_get_ntohs(tvb, offset);
if ((encodingScheme & 0xC000) >> 14 == DIS_ENCODING_CLASS_ENCODED_AUDIO)
col_append_fstr(pinfo->cinfo, COL_INFO,", Encoding Type=%s",
val_to_str_const(DIS_ENCODING_TYPE(encodingScheme),
DIS_PDU_Encoding_Type_Strings, "Unknown"));
ti = proto_tree_add_item(tree, hf_dis_ens, tvb, offset, 2, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(ti, ett_dis_ens);
proto_tree_add_item(sub_tree, hf_dis_ens_class, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(sub_tree,
((encodingScheme >> 14) & 3) == DIS_ENCODING_CLASS_ENCODED_AUDIO ? hf_dis_ens_type_audio : hf_dis_ens_type,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
tdlType = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dis_tdl_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_sample_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_data_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
numSamples = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_of_samples, tvb, offset, 2, ENC_BIG_ENDIAN);
if (numSamples)
col_append_fstr(pinfo->cinfo, COL_INFO, ", Number of Samples=%u", numSamples);
offset += 2;
if (tdlType == DIS_TDL_TYPE_LINK16_STD) {
offset = parse_DIS_FIELDS_SIGNAL_LINK16_NETWORK_HEADER(tvb, tree, offset, &messageType);
sub_tree = proto_tree_add_subtree_format(tree, tvb, offset, -1, ett_dis_signal_link16_message_data, NULL,
"Link 16 Message Data: %s", val_to_str_const(messageType, DIS_PDU_Link16_MessageType_Strings, ""));
offset = parse_Link16_Message_Data(sub_tree, tvb, offset, pinfo, encodingScheme, messageType);
proto_item_set_end(ti, tvb, offset);
} else {
proto_tree_add_item(tree, hf_dis_signal_data, tvb, offset, -1, ENC_NA );
offset += tvb_reported_length_remaining(tvb, offset);
}
return offset;
}
static int dissect_DIS_PARSER_FIRE_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree* sub_tree;
offset = parseField_Entity(tvb, tree, offset, "Firing Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Target Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Munition ID");
offset = dissect_DIS_FIELDS_EVENT_ID(tvb, tree, offset, "Event ID");
proto_tree_add_item(tree, hf_dis_fire_mission_index, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 24, ett_fire_location, NULL, "Location in World Coordinates");
proto_tree_add_item(sub_tree, hf_dis_fire_location_x, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_dis_fire_location_y, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_dis_fire_location_z, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
offset = dissect_DIS_FIELDS_BURST_DESCRIPTOR(tvb, tree, offset);
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_linear_velocity, NULL, "Velocity");
proto_tree_add_item(sub_tree, hf_dis_linear_velocity_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_linear_velocity_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_linear_velocity_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_range, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_DIS_PARSER_DETONATION_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *sub_tree;
guint8 variableParameterType, numVariable;
guint32 i;
offset = parseField_Entity(tvb, tree, offset, "Firing Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Target Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Munition ID");
offset = dissect_DIS_FIELDS_EVENT_ID(tvb, tree, offset, "Event ID");
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_linear_velocity, NULL, "Velocity");
proto_tree_add_item(sub_tree, hf_dis_linear_velocity_x, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_linear_velocity_y, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_linear_velocity_z, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 24, ett_detonation_location, NULL, "Location in World Coordinates");
proto_tree_add_item(sub_tree, hf_dis_detonation_location_x, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_dis_detonation_location_y, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(sub_tree, hf_dis_detonation_location_z, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
offset = dissect_DIS_FIELDS_BURST_DESCRIPTOR(tvb, tree, offset);
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 12, ett_linear_velocity, NULL, "Location in Entity Coordinates");
proto_tree_add_item(sub_tree, hf_dis_entity_location_x_float, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_entity_location_y_float, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(sub_tree, hf_dis_entity_location_z_float, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_detonation_result, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numVariable = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_art_params, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
for (i = 0; i < numVariable; i++)
{
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_variable_parameter, &ti, "Variable Parameter");
proto_tree_add_item(sub_tree, hf_dis_variable_parameter_type, tvb, offset, 1, ENC_BIG_ENDIAN);
variableParameterType = tvb_get_guint8(tvb, offset);
offset++;
offset = parseField_VariableParameter(tvb, sub_tree, offset, variableParameterType);
proto_item_set_end(ti, tvb, offset);
}
return offset;
}
static int dissect_DIS_PARSER_START_RESUME_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
offset = dissect_DIS_FIELDS_CLOCK_TIME(tvb, tree, offset, "Real World Time");
offset = dissect_DIS_FIELDS_CLOCK_TIME(tvb, tree, offset, "Simulation Time");
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_DIS_PARSER_STOP_FREEZE_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
offset = dissect_DIS_FIELDS_CLOCK_TIME(tvb, tree, offset, "Real World Time");
proto_tree_add_item(tree, hf_dis_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_frozen_behavior, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_DIS_PARSER_ACKNOWLEDGE_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_acknowledge_flag, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_response_flag, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_DIS_PARSER_ACTION_REQUEST_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 numFixed, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_action_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numFixed = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_fixed_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numVariable = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_DIS_FIELDS_FIXED_DATUM(tvb, tree, offset, "Fixed data", numFixed);
offset = parseField_DIS_FIELDS_VARIABLE_DATUM(tvb, tree, offset, "Variable data", numVariable);
return offset;
}
static int dissect_DIS_PARSER_ACTION_RESPONSE_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 numFixed, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_request_status, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numFixed = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_fixed_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numVariable = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_DIS_FIELDS_FIXED_DATUM(tvb, tree, offset, "Fixed data", numFixed);
offset = parseField_DIS_FIELDS_VARIABLE_DATUM(tvb, tree, offset, "Variable data", numVariable);
return offset;
}
static int dissect_DIS_PARSER_DATA_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 numFixed, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 4, ENC_NA);
offset += 4;
numFixed = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_fixed_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numVariable = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_DIS_FIELDS_FIXED_DATUM(tvb, tree, offset, "Fixed data", numFixed);
offset = parseField_DIS_FIELDS_VARIABLE_DATUM(tvb, tree, offset, "Variable data", numVariable);
return offset;
}
static int dissect_DIS_PARSER_DATA_QUERY_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 numFixed, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_time_interval32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numFixed = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_fixed_datum_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numVariable = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_datum_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_DIS_FIELDS_FIXED_DATUM_IDS(tvb, tree, offset, "Fixed datum ids", numFixed);
offset = parseField_DIS_FIELDS_VARIABLE_DATUM_IDS(tvb, tree, offset, "Variable datum ids", numVariable);
return offset;
}
static int dissect_DIS_PARSER_COMMENT_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 numFixed, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
numFixed = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_fixed_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numVariable = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_DIS_FIELDS_FIXED_DATUM(tvb, tree, offset, "Fixed data", numFixed);
offset = parseField_DIS_FIELDS_VARIABLE_DATUM(tvb, tree, offset, "Variable data", numVariable);
return offset;
}
static int dissect_DIS_PARSER_SIMAN_ENTITY_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_DIS_PARSER_START_RESUME_R_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
offset = dissect_DIS_FIELDS_CLOCK_TIME(tvb, tree, offset, "Real World Time");
offset = dissect_DIS_FIELDS_CLOCK_TIME(tvb, tree, offset, "Simulation Time");
proto_tree_add_item(tree, hf_dis_reliability, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_DIS_PARSER_STOP_FREEZE_R_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
offset = dissect_DIS_FIELDS_CLOCK_TIME(tvb, tree, offset, "Real World Time");
proto_tree_add_item(tree, hf_dis_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_frozen_behavior, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_reliability, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_DIS_PARSER_ACTION_REQUEST_R_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 numFixed, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_reliability, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_action_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numFixed = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_fixed_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numVariable = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_DIS_FIELDS_FIXED_DATUM(tvb, tree, offset, "Fixed data", numFixed);
offset = parseField_DIS_FIELDS_VARIABLE_DATUM(tvb, tree, offset, "Variable data", numVariable);
return offset;
}
static int dissect_DIS_PARSER_DATA_R_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 numFixed, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_reliability, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numFixed = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_fixed_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numVariable = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_data, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_DIS_FIELDS_FIXED_DATUM(tvb, tree, offset, "Fixed data", numFixed);
offset = parseField_DIS_FIELDS_VARIABLE_DATUM(tvb, tree, offset, "Variable data", numVariable);
return offset;
}
static int dissect_DIS_PARSER_DATA_QUERY_R_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 numFixed, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_reliability, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_time_interval32, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numFixed = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_fixed_datum_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
numVariable = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_datum_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_DIS_FIELDS_FIXED_DATUM_IDS(tvb, tree, offset, "Fixed datum ids", numFixed);
offset = parseField_DIS_FIELDS_VARIABLE_DATUM_IDS(tvb, tree, offset, "Variable datum ids", numVariable);
return offset;
}
static int dissect_DIS_PARSER_SIMAN_ENTITY_R_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_reliability, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 3, ENC_NA);
offset += 3;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int dissect_DIS_PARSER_APPLICATION_CONTROL_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_item* ti;
proto_tree* sub_tree;
guint32 i, variableRecordType;
guint16 variableRecordLength, numVariable;
offset = parseField_Entity(tvb, tree, offset, "Originating Entity ID");
offset = parseField_Entity(tvb, tree, offset, "Receiving Entity ID");
proto_tree_add_item(tree, hf_dis_reliability, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_time_interval8, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_control_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 1, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_dis_orig_app_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_recv_app_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_request_id, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_num_parts, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_current_part, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
numVariable = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tree, hf_dis_num_variable_records, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
for (i = 0; i < numVariable; i++)
{
sub_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_record, &ti, "Record");
variableRecordType = tvb_get_ntohl(tvb, offset);
proto_tree_add_item(tree, hf_dis_variable_record_type, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
variableRecordLength = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(sub_tree, hf_dis_variable_record_len, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = parseField_VariableRecord(tvb, sub_tree, offset, variableRecordType, variableRecordLength);
proto_item_set_end(ti, tvb, offset);
}
return offset;
}
static int dissect_DIS_PARSER_SIMULATOR_PRESENT_PO_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Nominated Simulator");
proto_tree_add_item(tree, hf_dis_simulator_type, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(tree, hf_dis_database_seq_num, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_simulator_load, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_simulation_load, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_time, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_packets_sent, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_unit_database_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_relative_battle_scheme, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_terrain_name, tvb, offset, 32, ENC_ASCII|ENC_NA);
offset += 32;
proto_tree_add_item(tree, hf_dis_terrain_version, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_host_name, tvb, offset, 32, ENC_ASCII|ENC_NA);
offset += 32;
return offset;
}
static int dissect_DIS_PARSER_DESCRIBE_OBJECT_PO_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_dis_database_seq_num, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_Entity(tvb, tree, offset, "Object ID");
offset = parseField_Entity(tvb, tree, offset, "World State ID");
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Owner");
proto_tree_add_item(tree, hf_dis_sequence_number, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_persist_obj_class, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_missing_from_world_state, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int dissect_DIS_PARSER_OBJECTS_PRESENT_PO_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Owner");
offset = parseField_Entity(tvb, tree, offset, "World State ID");
proto_tree_add_item(tree, hf_dis_obj_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int dissect_DIS_PARSER_OBJECT_REQUEST_PO_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Requesting Simulator");
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Object Owner");
offset = parseField_Entity(tvb, tree, offset, "World State ID");
proto_tree_add_item(tree, hf_dis_obj_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int dissect_DIS_PARSER_DELETE_OBJECTS_PO_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Requesting Simulator");
proto_tree_add_item(tree, hf_dis_obj_count, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
return offset;
}
static int dissect_DIS_PARSER_SET_WORLD_STATE_PO_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Requesting Simulator");
proto_tree_add_item(tree, hf_dis_clock_rate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_dis_sec_since_1970, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = parseField_Entity(tvb, tree, offset, "World State ID");
return offset;
}
static int dissect_DIS_PARSER_NOMINATION_PO_PDU(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Nominated Simulator");
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Nominating Simulator");
offset = dissect_DIS_FIELDS_SIMULATION_ADDRESS(tvb, tree, offset, "Missing Simulator");
return offset;
}
static gint alignOffset(gint offset, guint fieldLength)
{
gint remainder = offset % fieldLength;
if (remainder != 0)
{
offset += fieldLength - remainder;
}
return offset;
}
static gint parseField_Timestamp(tvbuff_t *tvb, proto_tree *tree, gint offset, int hf_relative)
{
static guint MSEC_PER_HOUR = 60 * 60 * 1000;
static guint FSV = 0x7fffffff;
guint isAbsolute = 0;
guint32 uintVal;
guint64 ms;
nstime_t tv;
proto_item* ti;
offset = alignOffset(offset, 4);
uintVal = tvb_get_ntohl(tvb, offset);
isAbsolute = uintVal & 1;
ms = (uintVal >> 1) * MSEC_PER_HOUR / FSV;
tv.secs = (time_t)ms/1000;
tv.nsecs = (int)(ms%1000)*1000000;
ti = proto_tree_add_time(tree, hf_relative, tvb, offset, 4, &tv);
if (isAbsolute)
{
proto_item_append_text(ti, " (absolute)");
}
else
{
proto_item_append_text(ti, " (relative)");
}
return (offset+4);
}
static gint parseField_Entity(tvbuff_t *tvb, proto_tree *tree, gint offset, const char* entity_name)
{
proto_tree *sub_tree;
sub_tree = proto_tree_add_subtree(tree, tvb, offset, 6, ett_entity, NULL, entity_name);
proto_tree_add_item(sub_tree, hf_dis_entity_id_site, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_entity_id_application, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(sub_tree, hf_dis_entity_id_entity, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint parseField_VariableParameter(tvbuff_t *tvb, proto_tree *tree, gint offset, guint8 paramType)
{
switch (paramType) {
case DIS_PARAM_TYPE_DESIG_ARTICULATED_PART:
offset = dissect_DIS_FIELDS_VP_ARTICULATED_PART(tvb, tree, offset);
break;
case DIS_PARAM_TYPE_DESIG_ATTACHED_PART:
offset = dissect_DIS_FIELDS_VP_ATTACHED_PART(tvb, tree, offset);
break;
case DIS_PARAM_TYPE_DESIG_ENTITY_OFFSET:
offset = dissect_DIS_FIELDS_VP_ENTITY_OFFSET(tvb, tree, offset);
break;
case DIS_PARAM_TYPE_DESIG_ENTITY_ASSOCIATION:
offset = dissect_DIS_FIELDS_VP_ENTITY_ASSOCIATION(tvb, tree, offset);
break;
default:
proto_tree_add_item(tree, hf_dis_str_data, tvb, offset, 15, ENC_NA);
offset += 15;
break;
}
return offset;
}
static gint parseField_VariableRecord(tvbuff_t *tvb, proto_tree *tree, gint offset, guint32 variableRecordType, guint16 record_length)
{
switch (variableRecordType) {
case 47200:
offset = dissect_DIS_FIELDS_VR_APPLICATION_HEALTH_STATUS(tvb, tree, offset);
break;
case 47300:
offset = dissect_DIS_FIELDS_VR_APPLICATION_INITIALIZATION(tvb, tree, offset);
break;
case 47600:
offset = dissect_DIS_FIELDS_VR_DATA_QUERY(tvb, tree, offset);
break;
default:
{
int dataLength = record_length - 6;
if (dataLength > 0)
{
proto_tree_add_item(tree, hf_dis_record_data, tvb, offset, dataLength, ENC_NA);
offset += dataLength;
}
}
break;
}
if (record_length % 8)
{
guint32 alignmentPadding = (8 - (record_length % 8));
proto_tree_add_item(tree, hf_dis_alignment_padding, tvb, offset, alignmentPadding, ENC_NA);
offset += alignmentPadding;
}
return offset;
}
static int parseDISHeader(tvbuff_t *tvb, proto_tree *tree, int offset, dis_header_t* header)
{
proto_tree_add_item(tree, hf_dis_proto_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
header->version = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_dis_exercise_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_pdu_type, tvb, offset, 1, ENC_BIG_ENDIAN);
header->pduType = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_dis_proto_fam, tvb, offset, 1, ENC_BIG_ENDIAN);
header->family = tvb_get_guint8(tvb, offset);
offset++;
offset = parseField_Timestamp(tvb, tree, offset, hf_dis_header_rel_ts);
proto_tree_add_item(tree, hf_dis_pdu_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_padding, tvb, offset, 2, ENC_NA);
offset += 2;
return offset;
}
static int parsePOHeader(tvbuff_t *tvb, proto_tree *tree, int offset, guint8* pduType)
{
proto_tree_add_item(tree, hf_dis_po_ver, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_po_pdu_type, tvb, offset, 1, ENC_BIG_ENDIAN);
*pduType = tvb_get_guint8(tvb, offset);
offset++;
proto_tree_add_item(tree, hf_dis_exercise_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_po_database_id, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_dis_po_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_dis_po_pdu_count, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint dissect_dis(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_tree *dis_tree, *dis_header_tree;
proto_item *dis_node;
proto_tree *dis_payload_tree = NULL;
proto_item *dis_payload_node = NULL;
gint offset = 0;
const gchar *pduString = 0;
DIS_Parser_func* pduFunc = NULL;
dis_header_t header;
guint8 persistentObjectPduType;
if (tvb_reported_length(tvb) < 12)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DIS");
col_clear(pinfo->cinfo, COL_INFO);
dis_node = proto_tree_add_item(tree, proto_dis, tvb, offset, -1, ENC_NA);
dis_tree = proto_item_add_subtree(dis_node, ett_dis);
dis_header_tree = proto_tree_add_subtree(dis_tree, tvb, offset, 12, ett_dis_header, NULL, "Header");
offset = parseDISHeader(tvb, dis_header_tree, offset, &header);
pduString = val_to_str_ext_const(header.pduType, &DIS_PDU_Type_Strings_Ext, "Unknown");
switch (header.family)
{
case DIS_PROTOCOLFAMILY_PERSISTENT_OBJECT:
{
proto_item *dis_po_header_tree;
dis_po_header_tree = proto_tree_add_subtree(dis_header_tree, tvb, offset, 8, ett_dis_po_header, NULL, "PO Header");
offset = parsePOHeader(tvb, dis_po_header_tree, offset, &persistentObjectPduType);
switch (persistentObjectPduType)
{
case DIS_PERSISTENT_OBJECT_TYPE_SIMULATOR_PRESENT:
pduFunc = &dissect_DIS_PARSER_SIMULATOR_PRESENT_PO_PDU;
break;
case DIS_PERSISTENT_OBJECT_TYPE_DESCRIBE_OBJECT:
pduFunc = &dissect_DIS_PARSER_DESCRIBE_OBJECT_PO_PDU;
break;
case DIS_PERSISTENT_OBJECT_TYPE_OBJECTS_PRESENT:
pduFunc = &dissect_DIS_PARSER_OBJECTS_PRESENT_PO_PDU;
break;
case DIS_PERSISTENT_OBJECT_TYPE_OBJECT_REQUEST:
pduFunc = &dissect_DIS_PARSER_OBJECT_REQUEST_PO_PDU;
break;
case DIS_PERSISTENT_OBJECT_TYPE_DELETE_OBJECTS:
pduFunc = &dissect_DIS_PARSER_DELETE_OBJECTS_PO_PDU;
break;
case DIS_PERSISTENT_OBJECT_TYPE_SET_WORLD_STATE:
pduFunc = &dissect_DIS_PARSER_SET_WORLD_STATE_PO_PDU;
break;
case DIS_PERSISTENT_OBJECT_TYPE_NOMINATION:
pduFunc = &dissect_DIS_PARSER_NOMINATION_PO_PDU;
break;
default:
pduFunc = NULL;
break;
}
pduString = val_to_str
(persistentObjectPduType,
DIS_PDU_PersistentObjectType_Strings, "Unknown");
dis_payload_tree = proto_tree_add_subtree_format(dis_tree, tvb, offset, -1,
ett_dis_payload, &dis_payload_node, "%s PO PDU", pduString);
}
break;
default:
dis_payload_tree = proto_tree_add_subtree_format(dis_tree, tvb, offset, -1,
ett_dis_payload, &dis_payload_node, "%s PDU", pduString);
switch (header.pduType)
{
case DIS_PDUTYPE_ENTITY_STATE:
pduFunc = &dissect_DIS_PARSER_ENTITY_STATE_PDU;
break;
case DIS_PDUTYPE_ELECTROMAGNETIC_EMISSION:
pduFunc = &dissect_DIS_PARSER_ELECTROMAGNETIC_EMISSION_PDU;
break;
case DIS_PDUTYPE_UNDERWATER_ACOUSTIC:
pduFunc = &dissect_DIS_PARSER_UNDERWATER_ACOUSTIC_PDU;
break;
case DIS_PDUTYPE_IFF:
pduFunc = &dissect_DIS_PARSER_IFF_PDU;
break;
case DIS_PDUTYPE_TRANSMITTER:
pduFunc = &dissect_DIS_PARSER_TRANSMITTER_PDU;
break;
case DIS_PDUTYPE_SIGNAL:
pduFunc = &dissect_DIS_PARSER_SIGNAL_PDU;
break;
case DIS_PDUTYPE_FIRE:
pduFunc = &dissect_DIS_PARSER_FIRE_PDU;
break;
case DIS_PDUTYPE_DETONATION:
if ( header.version < DIS_VERSION_IEEE_1278_1_2012 )
{
pduFunc = &dissect_DIS_PARSER_DETONATION_PDU;
}
else
{
pduFunc = &dissect_DIS_PARSER_DETONATION_PDU;
}
break;
case DIS_PDUTYPE_START_RESUME:
pduFunc = &dissect_DIS_PARSER_START_RESUME_PDU;
break;
case DIS_PDUTYPE_STOP_FREEZE:
pduFunc = &dissect_DIS_PARSER_STOP_FREEZE_PDU;
break;
case DIS_PDUTYPE_ACKNOWLEDGE:
pduFunc = &dissect_DIS_PARSER_ACKNOWLEDGE_PDU;
break;
case DIS_PDUTYPE_ACTION_REQUEST:
pduFunc = &dissect_DIS_PARSER_ACTION_REQUEST_PDU;
break;
case DIS_PDUTYPE_ACTION_RESPONSE:
pduFunc = &dissect_DIS_PARSER_ACTION_RESPONSE_PDU;
break;
case DIS_PDUTYPE_DATA:
case DIS_PDUTYPE_SET_DATA:
pduFunc = &dissect_DIS_PARSER_DATA_PDU;
break;
case DIS_PDUTYPE_DATA_QUERY:
pduFunc = &dissect_DIS_PARSER_DATA_QUERY_PDU;
break;
case DIS_PDUTYPE_COMMENT:
pduFunc = &dissect_DIS_PARSER_COMMENT_PDU;
break;
case DIS_PDUTYPE_CREATE_ENTITY:
case DIS_PDUTYPE_REMOVE_ENTITY:
pduFunc = &dissect_DIS_PARSER_SIMAN_ENTITY_PDU;
break;
case DIS_PDUTYPE_START_RESUME_R:
pduFunc = &dissect_DIS_PARSER_START_RESUME_R_PDU;
break;
case DIS_PDUTYPE_STOP_FREEZE_R:
pduFunc = &dissect_DIS_PARSER_STOP_FREEZE_R_PDU;
break;
case DIS_PDUTYPE_ACKNOWLEDGE_R:
pduFunc = &dissect_DIS_PARSER_ACKNOWLEDGE_PDU;
break;
case DIS_PDUTYPE_ACTION_REQUEST_R:
pduFunc = &dissect_DIS_PARSER_ACTION_REQUEST_R_PDU;
break;
case DIS_PDUTYPE_ACTION_RESPONSE_R:
pduFunc = &dissect_DIS_PARSER_ACTION_RESPONSE_PDU;
break;
case DIS_PDUTYPE_DATA_R:
case DIS_PDUTYPE_SET_DATA_R:
pduFunc = &dissect_DIS_PARSER_DATA_R_PDU;
break;
case DIS_PDUTYPE_DATA_QUERY_R:
pduFunc = &dissect_DIS_PARSER_DATA_QUERY_R_PDU;
break;
case DIS_PDUTYPE_COMMENT_R:
pduFunc = &dissect_DIS_PARSER_COMMENT_PDU;
break;
case DIS_PDUTYPE_CREATE_ENTITY_R:
case DIS_PDUTYPE_REMOVE_ENTITY_R:
pduFunc = &dissect_DIS_PARSER_SIMAN_ENTITY_R_PDU;
break;
case DIS_PDUTYPE_APPLICATION_CONTROL:
pduFunc = &dissect_DIS_PARSER_APPLICATION_CONTROL_PDU;
break;
default:
pduFunc = NULL;
break;
}
break;
}
col_add_fstr( pinfo->cinfo, COL_INFO, "PDUType: %s", pduString);
if (pduFunc != NULL)
{
offset = (*pduFunc)(tvb, pinfo, dis_payload_tree, offset);
proto_item_set_end(dis_payload_node, tvb, offset);
}
return tvb_captured_length(tvb);
}
void proto_register_dis(void)
{
static hf_register_info hf[] =
{
{ &hf_dis_proto_ver,
{ "Proto version", "dis.proto_ver",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_ProtocolVersion_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_exercise_id,
{ "Exercise ID", "dis.exer_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_pdu_type,
{ "PDU type", "dis.pdu_type",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &DIS_PDU_Type_Strings_Ext, 0x0,
NULL, HFILL }
},
{ &hf_dis_proto_fam,
{ "Proto Family", "dis.proto_fam",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_ProtocolFamily_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_header_rel_ts,
{ "Timestamp", "dis.timestamp",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_pdu_length,
{ "PDU Length", "dis.pdu_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_padding,
{ "Padding", "dis.padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_po_ver,
{ "Protocol Version", "dis.po.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_po_pdu_type,
{ "PO PDU Type", "dis.po.pdu_type",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_PersistentObjectType_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_po_database_id,
{ "PO Database ID", "dis.po.database_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_po_length,
{ "Length", "dis.po.length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_po_pdu_count,
{ "PDU Count", "dis.po.pdu_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_entity_id_site,
{ "Entity ID Site", "dis.entity_id_site",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_entity_id_application,
{ "Entity ID Application", "dis.entity_id_application",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_entity_id_entity,
{ "Entity ID Entity", "dis.entity_id_entity",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_emitter_id,
{ "Emitter ID", "dis.emitter_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_beam_id,
{ "Beam ID", "dis.beam_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_clocktime,
{ "Timestamp", "dis.clocktime",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_art_params,
{ "Number of Articulation Parameters", "dis.num_articulation_params",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_entityKind,
{ "Kind", "dis.entityKind",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_EntityKind_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_entityDomain,
{ "Domain", "dis.entityDomain",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_Domain_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_category_land,
{ "Category / Land", "dis.category.land",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &DIS_PDU_Category_LandPlatform_Strings_Ext, 0x0,
NULL, HFILL }
},
{ &hf_dis_category_air,
{ "Category / Air", "dis.category.air",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_Category_AirPlatform_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_category_surface,
{ "Category / Surface", "dis.category.surface",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_Category_SurfacePlatform_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_category_subsurface,
{ "Category / Subsurface", "dis.category.subsurface",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_Category_SubsurfacePlatform_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_category_space,
{ "Category / Space", "dis.category.space",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_Category_SpacePlatform_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_category,
{ "Category", "dis.category",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_subcategory,
{ "Subcategory", "dis.subcategory",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_specific,
{ "Specific", "dis.specific",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_extra,
{ "Extra", "dis.extra",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_reason,
{ "Reason", "dis.reason",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_Reason_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_frozen_behavior,
{ "Frozen Behavior", "dis.frozen_behavior",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_FrozenBehavior_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_acknowledge_flag,
{ "Acknowledge Flag", "dis.acknowledge_flag",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_AcknowledgeFlag_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_response_flag,
{ "Response Flag", "dis.response_flag",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_DisResponseFlag_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_site,
{ "Site", "dis.site",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_request_id,
{ "Request ID", "dis.request_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_application,
{ "Application", "dis.application",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_fixed_data,
{ "Number of Fixed Data Fields", "dis.num_fixed_data",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_variable_data,
{ "Number of Variable Data Fields", "dis.num_variable_data",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_action_id,
{ "Action ID", "dis.action_id",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &DIS_PDU_ActionId_Strings_Ext, 0x0,
NULL, HFILL }
},
{ &hf_dis_request_status,
{ "Request Status", "dis.request_status",
FT_UINT32, BASE_DEC, VALS(DIS_PDU_RequestStatus_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_datum_id,
{ "Datum ID", "dis.datum_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_fixed_datum_value,
{ "Datum value", "dis.fixed_datum_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_datum_length,
{ "Datum length", "dis.datum_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_variable_datum_value,
{ "Datum value", "dis.variable_datum_value",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_fixed_datum_id,
{ "Number of Fixed Datum Ids", "dis.num_fixed_datum_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_variable_datum_id,
{ "Number of Variable Datum Ids", "dis.num_variable_datum_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_reliability,
{ "Reliability", "dis.reliability",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_RequiredReliabilityService_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_control_id,
{ "Control ID", "dis.control_id",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_ControlId_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_orig_app_type,
{ "Originating App Type", "dis.orig_app_type",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_ApplicationType_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_recv_app_type,
{ "Receiving App Type", "dis.recv_app_type",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_ApplicationType_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_num_parts,
{ "Number of Parts", "dis.num_parts",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_current_part,
{ "Current Part", "dis.num_parts",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_variable_records,
{ "Number of Variable Records", "dis.num_variable_records",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_variable_record_type,
{ "Record Type", "dis.variable_record_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_variable_record_len,
{ "Record Length", "dis.variable_record_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_time_interval8,
{ "Time interval", "dis.time_interval",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_time_interval32,
{ "Time interval", "dis.time_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_event_number,
{ "Event Number", "dis.event_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_country,
{ "Country", "dis.country",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_Country_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_emitter_name,
{ "Emitter Name", "dis.electromagnetic.emitter.name",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &DIS_PDU_EmitterName_Strings_Ext, 0x0,
NULL, HFILL }
},
{ &hf_dis_emission_function,
{ "Emission Function", "dis.electromagnetic.emission.function",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &DIS_PDU_EmissionFunction_Strings_Ext, 0x0,
NULL, HFILL }
},
{ &hf_dis_em_data_length,
{ "System Data Length", "dis.electromagnetic.emission.data_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_em_num_beams,
{ "System Data Length", "dis.electromagnetic.emission.num_beams",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_emitter_id_number,
{ "Emitter ID Number", "dis.electromagnetic.emission.emitter_id_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_em_location_x,
{"X", "dis.electromagnetic.emission.location.x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_location_y,
{"Y", "dis.electromagnetic.emission.location.y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_location_z,
{"Z", "dis.electromagnetic.emission.location.z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_beam_function,
{ "Beam Function", "dis.electromagnetic.emission.beam.function",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_BeamFunction_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_num_electromagnetic_emission_systems,
{ "Number of Electromagnetic Emission Systems", "dis.electromagnetic.num_emission_systems",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_radio_id,
{ "Radio ID", "dis.radio.radio_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ens,
{ "Encoding Scheme", "dis.radio.encoding_scheme",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ens_class,
{ "Encoding Class", "dis.radio.encoding_class",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_Encoding_Class_Strings), 0xc000,
NULL, HFILL }
},
{ &hf_dis_ens_type,
{ "Encoding Type", "dis.radio.encoding_type",
FT_UINT16, BASE_DEC, NULL, 0x3fff,
NULL, HFILL }
},
{ &hf_dis_ens_type_audio,
{ "Encoding Type", "dis.radio.encoding_type.audio",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_Encoding_Type_Strings), 0x3fff,
NULL, HFILL }
},
{ &hf_dis_tdl_type,
{ "TDL Type", "dis.radio.tdl_type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &DIS_PDU_TDL_Type_Strings_Ext, 0x0,
NULL, HFILL }
},
{ &hf_dis_sample_rate,
{ "Sample Rate", "dis.radio.sample_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_data_length,
{ "Data Length", "dis.radio.data_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_of_samples,
{ "Number of Samples", "dis.radio.num_of_samples",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_signal_data,
{"Data", "dis.radio.signal_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_radio_category,
{ "Radio Category", "dis.radio.radio_category",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_RadioCategory_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_nomenclature_version,
{ "Nomenclature Version", "dis.radio.nomenclature_version",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_NomenclatureVersion_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_nomenclature,
{ "Nomenclature", "dis.radio.nomenclature",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_Nomenclature_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_radio_transmit_state,
{ "Radio Transmit State", "dis.radio.transmit_state",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_RadioTransmitState_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_radio_input_source,
{ "Radio Input Source", "dis.radio.input_source",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_RadioInputSource_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_antenna_pattern_type,
{ "Antenna Pattern Type", "dis.radio.antenna_pattern_type",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_AntennaPatternType_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_antenna_pattern_length,
{ "Antenna Pattern Length", "dis.radio.antenna_pattern_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_antenna_location_x,
{"X", "dis.antenna_location.x",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_antenna_location_y,
{"Y", "dis.antenna_location.y",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_antenna_location_z,
{"Z", "dis.antenna_location.z",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_rel_antenna_location_x,
{"X", "dis.rel_antenna_location.x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_rel_antenna_location_y,
{"Y", "dis.rel_antenna_location.y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_rel_antenna_location_z,
{"Z", "dis.rel_antenna_location.z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_transmit_frequency,
{ "Transmit Frequency (Hz)", "dis.radio.frequency",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_transmit_freq_bandwidth,
{"Transmit Frequency Bandwidth", "dis.transmit_freq_bandwidth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_transmit_power,
{"Transmit Power", "dis.transmit_power",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_spread_spectrum_usage,
{ "Spread Spectrum", "dis.radio.mod_type.spread_spectrum_usage",
FT_BOOLEAN, 16, TFS(&dis_modulation_spread_spectrum),0xFFFF,
NULL, HFILL }
},
{ &hf_dis_frequency_hopping,
{ "Frequency Hopping modulation", "dis.radio.mod_type.frequency_hopping",
FT_BOOLEAN, 16, TFS(&dis_frequency_hopping_value),0x0001,
NULL, HFILL }
},
{ &hf_dis_pseudo_noise_modulation,
{ "Psuedo noise modulation", "dis.radio.mod_type.pseudo_noise_modulation",
FT_BOOLEAN, 16, TFS(&dis_pseudo_noise_value),0x0002,
NULL, HFILL }
},
{ &hf_dis_time_hopping,
{ "Time Hopping modulation", "dis.radio.mod_type.time_hopping",
FT_BOOLEAN, 16, TFS(&dis_time_hopping_value),0x0004,
NULL, HFILL }
},
{ &hf_dis_modulation_major,
{ "Major Modulation", "dis.radio.mod_type.major",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_MajorModulation_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_modulation_amplitude,
{ "Detail", "dis.modulation_detail",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_DetailModulationAmplitude_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_modulation_amplitude_angle,
{ "Detail", "dis.modulation_detail",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_DetailModulationAmpAndAngle_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_modulation_angle,
{ "Detail", "dis.modulation_detail",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_DetailModulationAngle_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_modulation_combination,
{ "Detail", "dis.modulation_detail",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_DetailModulationCombination_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_modulation_pulse,
{ "Detail", "dis.modulation_detail",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_DetailModulationPulse_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_modulation_unmodulated,
{ "Detail", "dis.modulation_detail",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_DetailModulationUnmodulated_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_modulation_detail,
{ "Detail", "dis.modulation_detail",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_DetailModulationCPSM_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_modulation_system,
{ "System Modulation", "dis.radio.mod_type.system",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_SystemModulation_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_crypto_system,
{ "Crypto System", "dis.radio.crypto_system",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_CryptoSystem_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_crypto_key,
{ "Encryption Key", "dis.radio.encryption_key",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_encryption_mode,
{ "Encryption Mode", "dis.radio.encryption_key.mode",
FT_BOOLEAN, 16, TFS(&dis_encryption_mode_value),0x8000,
NULL, HFILL }
},
{ &hf_dis_key_identifier,
{ "Encryption Key ID", "dis.radio.encryption_key.id",
FT_UINT16, BASE_DEC, NULL,0x7FFF,
NULL, HFILL }
},
{ &hf_dis_modulation_parameter_length,
{ "Modulation Parameter Length", "dis.radio.mod_param.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_fh_net_id,
{ "Frequency Hopping Network ID", "dis.radio.mod_param.cctt_cingars.fh_nw_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_fh_set_id,
{ "Frequency Set ID", "dis.radio.mod_param.cctt_cingars.fh_set_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_fh_lo_set_id,
{ "Frequency Lockout Set ID", "dis.radio.mod_param.cctt_cingars.fh_lo_set_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_fh_msg_start,
{ "Start of Message", "dis.radio.mod_param.cctt_cingars.fh_msg_start",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_ModParamMsgStart_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_fh_reserved,
{ "Reserved", "dis.radio.mod_param.cctt_cingars.fh_reserved",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_fh_sync_time_offset,
{ "Sync Time Offset (Seconds)", "dis.radio.mod_param.cctt_cingars.fh_sync_offset",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_fh_security_key,
{ "Transmission Security Key", "dis.radio.mod_param.cctt_cingars.fh_securit_key",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_fh_clear_channel,
{ "Clear Channel", "dis.radio.mod_param.cctt_cingars.fh_clr_channel",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_ModParamClrChannel_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_dump,
{"Modulation Parameter All", "dis.radio.mod_param.all",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_mod_param_ts_allocation_mode,
{ "Time Slot Allocaton Mode", "dis.radio.mod_param.jtids.ts_alloc_mode",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_TSAllocationFidelity_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_transmitter_prim_mode,
{ "Transmitter Primary Mode", "dis.radio.mod_param.jtids.transmitter_primary_mode",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_TerminalPrimaryMode_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_transmitter_second_mode,
{ "Transmitter Primary Mode", "dis.radio.mod_param.jtids.transmitter_secondary_mode",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_TerminalSecondaryMode_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_sync_state,
{ "Synchronization State", "dis.radio.mod_param.jtids.sync_state",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_ModParamSyncState_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_mod_param_network_sync_id,
{ "Network Sync ID", "dis.radio.mod_param.jtids.network_sync_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_force_id,
{ "Force ID", "dis.force_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_entity_linear_velocity_x,
{"X", "dis.entity_linear_velocity.x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_linear_velocity_y,
{"Y", "dis.entity_linear_velocity.y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_linear_velocity_z,
{"Z", "dis.entity_linear_velocity.z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_location_x_double,
{"X", "dis.entity_location.x",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_location_x_float,
{"X", "dis.entity_location.x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_location_y_double,
{"Y", "dis.entity_location.y",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_location_y_float,
{"Y", "dis.entity_location.y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_location_z_double,
{"Z", "dis.entity_location.z",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_location_z_float,
{"Z", "dis.entity_location.z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_orientation_psi,
{"Psi", "dis.entity_orientation.psi",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_orientation_theta,
{"Theta", "dis.entity_orientation.theta",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_orientation_phi,
{"Phi", "dis.entity_orientation.phi",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_appearance_landform_paint_scheme,
{"Paint Scheme", "dis.appearance.landform.paint_scheme",
FT_BOOLEAN, 32, TFS(&tfs_camouflage_uniform_color), 0x00000001,
NULL, HFILL}
},
{ &hf_appearance_landform_mobility,
{"Mobility", "dis.appearance.landform.mobility",
FT_BOOLEAN, 32, TFS(&tfs_mobility_kill), 0x00000002,
NULL, HFILL}
},
{ &hf_appearance_landform_fire_power,
{"Fire Power", "dis.appearance.landform.fire_power",
FT_BOOLEAN, 32, TFS(&tfs_fire_power_kill), 0x00000004,
NULL, HFILL}
},
{ &hf_appearance_landform_damage,
{"Fire Power", "dis.appearance.landform.damage",
FT_UINT32, BASE_DEC, VALS(appearance_damage_vals), 0x00000018,
NULL, HFILL}
},
{ &hf_appearance_lifeform_paint_scheme,
{"Paint Scheme", "dis.appearance.lifeform.paint_scheme",
FT_BOOLEAN, 32, TFS(&tfs_camouflage_uniform_color), 0x00000001,
NULL, HFILL}
},
{ &hf_appearance_lifeform_health,
{"Health", "dis.appearance.lifeform.health",
FT_UINT32, BASE_DEC, VALS(appearance_health_vals), 0x00000018,
NULL, HFILL}
},
{ &hf_entity_appearance,
{"Appearance", "dis.appearance",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_dead_reckoning_parameters,
{"Dead Reckoning Parameters", "dis.dead_reckoning_parameters",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_entity_marking,
{"Entity Marking", "dis.entity_marking",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_capabilities,
{"Capabilities", "dis.capabilities",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_variable_parameter_type,
{ "Variable Parameter Type", "dis.variable_parameter_type",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_ParameterTypeDesignator_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_signal_link16_npg,
{ "NPG Number", "dis.signal.link16.npg",
FT_UINT16, BASE_DEC, VALS(Link16_NPG_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_signal_link16_tsec_cvll,
{ "TSEC CVLL", "dis.signal.link16.tsec_cvll",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(DIS_PDU_Link16_CVLL_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_signal_link16_msec_cvll,
{ "MSEC CVLL", "dis.signal.link16.msec_cvll",
FT_UINT8, BASE_RANGE_STRING | BASE_DEC, RVALS(DIS_PDU_Link16_CVLL_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_signal_link16_message_type,
{ "Message Type", "dis.signal.link16.message_type",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_Link16_MessageType_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_signal_link16_ptt,
{ "Perceived Transmit Time", "dis.signal.link16.ptt",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_signal_link16_time_slot_type,
{ "Time Slot Type", "dis.signal.link16.time_slot_type", FT_UINT32, BASE_DEC, NULL, 0x7,
NULL, HFILL},
},
{ &hf_dis_signal_link16_rti,
{ "Relay Transmission Indicator", "dis.signal.link16.relay", FT_BOOLEAN, 32, NULL, 0x8,
NULL, HFILL},
},
{ &hf_dis_signal_link16_stn,
{ "Source Track Number", "dis.signal.link16.stn", FT_UINT32, BASE_OCT, NULL, 0x7FFF0,
NULL, HFILL },
},
{ &hf_dis_signal_link16_sdusn,
{ "Secure Data Unit Serial Number", "dis.signal.link16.sdusn", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL },
},
{ &hf_dis_signal_link16_network_number,
{ "Network Number", "dis.signal.link16.network_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_signal_link16_time_slot_id,
{ "Time Slot ID", "dis.signal.link16.time_slot_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_shafts,
{ "Number of Shafts", "dis.ua.number_of_shafts",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_apas,
{ "Number of APAs", "dis.ua.number_of_apas",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_state_update_indicator,
{ "State Update Indicator", "dis.ua.state_update_indicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_passive_parameter_index,
{ "Passive Parameter Index", "dis.ua.passive_parameter_index",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_propulsion_plant_config,
{ "Propulsion Plant Configuration", "dis.ua.propulsion_plant_config",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_shaft_rpm_current,
{ "Current Shaft RPM", "dis.ua.shaft.rpm.current",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_shaft_rpm_ordered,
{ "Ordered Shaft RPM", "dis.ua.shaft.rpm.ordered",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_shaft_rpm_change_rate,
{ "Shaft RPM Rate of Change", "dis.ua.shaft.rpm.change_rate",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_num_ua_emitter_systems,
{ "Number of UA Emitter Systems", "dis.ua.number_of_ua_emitter_systems",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_apas_parameter_index,
{ "Parameter Index", "dis.ua.apas.parameter_index",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_apas_value,
{ "Value", "dis.apas.value",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_emission_name,
{ "Acoustic Emitter Name", "dis.ua.emitter.name",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_emission_function,
{ "Function", "dis.ua.emitter.function",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_emission_id_number,
{ "Acoustic ID Number", "dis.ua.emitter.id_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_emitter_data_length,
{ "Emitter System Data Length", "dis.ua.emitter.data_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_num_beams,
{ "Number of Beams (m)", "dis.ua.num_beams",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_location_x,
{"X", "dis.ua.location.x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_ua_location_y,
{"Y", "dis.ua.location.y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_ua_location_z,
{"Z", "dis.ua.location.z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_ua_beam_data_length,
{ "Beam Data Length", "dis.ua.beam.data_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_beam_id_number,
{ "Beam ID Number", "dis.ua.beam.id_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_beam_active_emission_parameter_index,
{ "Active Emission Parameter Index", "dis.ua.beam.active_emission_parameter_index",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_beam_scan_pattern,
{ "Scan Pattern", "dis.ua.beam.scan_pattern",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_ua_beam_center_azimuth,
{"Beam Center Azimuth (Horizontal Bearing)", "dis.ua.beam.center_azimuth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_ua_beam_azimuthal_beamwidth,
{"Azimuthal Beamwidth (Horizontal Beamwidth)", "dis.ua.beam.azimuthal_beamwidth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_ua_beam_center_de,
{"Beam Center D/E", "dis.ua.beam.center_de",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_ua_beam_de_beamwidth,
{"D/E Beamwidth (Vertical Beamwidth)", "dis.ua.beam.de_beamwidth",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_beam_data_length,
{ "Beam Data Length", "dis.em.beam.data_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_em_beam_id_number,
{ "Beam ID Number", "dis.em.beam.id_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_em_beam_parameter_index,
{ "Beam Parameter Index", "dis.em.beam.parameter_index",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_em_fund_frequency,
{"Frequency", "dis.em.fund.frequency",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_frequency_range,
{"Frequency Range", "dis.em.fund.frequency_range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_effective_radiated_power,
{"Effective Radiated Power", "dis.em.fund.effective_radiated_power",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_pulse_repition_freq,
{"Pulse Repetition Frequency", "dis.em.fund.pulse_repition_freq",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_pulse_width,
{"Pulse Width", "dis.em.fund.pulse_width",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_beam_azimuth_center,
{"Beam Azimuth Center", "dis.em.fund.beam.azimuth_center",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_beam_azimuth_sweep,
{"Beam Azimuth Sweep", "dis.em.fund.beam.azimuth_sweep",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_beam_elevation_center,
{"Beam Elevation Center", "dis.em.fund.beam.elevation_center",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_beam_elevation_sweep,
{"Beam Elevation Sweep", "dis.em.fund.beam.elevation_sweep",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_em_fund_beem_sweep_sync,
{"Beam Sweep Sync", "dis.em.fund.beem.sweep_sync",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_track_jam_num_targ,
{ "Number of Targets in Track/Jam Field", "dis.track_jam.num_targ",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_track_jam_high_density,
{ "High Density Track/Jam", "dis.track_jam.high_density",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_jamming_mode_seq,
{ "Jamming Mode Sequence", "dis.jamming_mode_seq",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_warhead,
{ "Warhead", "dis.warhead",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_fuse,
{ "Fuse", "dis.fuse",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_quality,
{ "Quantity", "dis.quality",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_rate,
{ "Rate", "dis.rate",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_fire_mission_index,
{ "Fire Mission Index", "dis.fire.mission_index",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_fire_location_x,
{"X", "dis.fire.location.x",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_fire_location_y,
{"Y", "dis.fire.location.y",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_fire_location_z,
{"Z", "dis.fire.location.z",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_linear_velocity_x,
{"X", "dis.linear_velocity.x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_linear_velocity_y,
{"Y", "dis.linear_velocity.y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_linear_velocity_z,
{"Z", "dis.linear_velocity.z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_range,
{"Range", "dis.range",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_detonation_location_x,
{"X", "dis.detonation.location.x",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_detonation_location_y,
{"Y", "dis.detonation.location.y",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_detonation_location_z,
{"Z", "dis.detonation.location.z",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_detonation_result,
{ "Detonation Result", "dis.detonation.result",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &DIS_PDU_DetonationResult_Strings_Ext, 0x0,
NULL, HFILL }
},
{ &hf_dis_simulator_type,
{ "Simulator Type", "dis.simulator_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_database_seq_num,
{ "Database Sequence Number", "dis.database_seq_num",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_simulator_load,
{ "Simulator Load", "dis.simulator_load",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_simulation_load,
{"Simulation Load", "dis.simulation_load",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_time,
{ "Time", "dis.time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_packets_sent,
{ "Packets Sent", "dis.packets_sent",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_unit_database_version,
{ "Unit Database Version", "dis.unit_database_version",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_relative_battle_scheme,
{ "Relative Battle Scheme", "dis.relative_battle_scheme",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_terrain_version,
{ "Terrain Version", "dis.terrain_version",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_terrain_name,
{"Terrain Name", "dis.terrain_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_host_name,
{"Host Name", "dis.host_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_sequence_number,
{ "Sequence Number", "dis.sequence_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_persist_obj_class,
{ "Object Class", "dis.persist_obj_class",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &DIS_PDU_PO_ObjectClass_Strings_Ext, 0x0,
NULL, HFILL }
},
{ &hf_dis_missing_from_world_state,
{ "Missing From World State", "dis.missing_from_world_state",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_obj_count,
{ "Object Count", "dis.obj_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_clock_rate,
{"Clock Rate", "dis.clock_rate",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_sec_since_1970,
{ "Seconds Since 1970", "dis.sec_since_1970",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_str_data,
{ "Data", "dis.str_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_record_data,
{ "Record data", "dis.record_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_alignment_padding,
{ "Alignment padding", "dis.alignment_padding",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_change_indicator,
{ "Change Indicator", "dis.vp.change_indicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_association_status,
{ "Association Status", "dis.vp.association_status",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_association_type,
{ "Association Type", "dis.vp.association_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_phys_conn_type,
{ "Physical Connection Type", "dis.vp.phys_conn_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_group_member_type,
{ "Group Member Type", "dis.vp.group_member_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_own_station_location,
{ "Group Member Type", "dis.vp.own_station_location",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_group_number,
{ "Group Member Type", "dis.vp.group_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_offset_type,
{ "Offset Type", "dis.vp.offset_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_offset_x,
{"X", "dis.vp.offset.x",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_vp_offset_y,
{"Y", "dis.vp.offset.y",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_vp_offset_z,
{"Z", "dis.vp.offset.z",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_vp_attached_indicator,
{ "Attached Indicator", "dis.vp.attached_indicator",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_part_attached_to_id,
{ "Part Attached To ID", "dis.vp.part_attached_to_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_artic_param_type,
{ "Parameter Type", "dis.vp.artic_param_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_change,
{ "Change", "dis.vp.change",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vp_parameter_value,
{ "Parameter Value", "dis.vp.parameter_value",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vr_num_records,
{ "Num Records", "dis.vr.num_records",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vr_exercise_id,
{ "Exercise ID", "dis.vr.exercise_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vr_exercise_file_path,
{"Exercise File Path", "dis.vr.exercise_file_path",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_vr_exercise_file_name,
{"Exercise File Name", "dis.vr.exercise_file_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_vr_application_role,
{"Application Role", "dis.vr.application_role",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_vr_status_type,
{ "Status Type", "dis.vr.status_type",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_ApplicationStatusType_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_vr_general_status,
{ "General Status", "dis.vr.general_status",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_ApplicationGeneralStatus_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_vr_specific_status,
{ "Specific Status", "dis.vr.specific_status",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vr_status_value_int,
{ "Status Value Int", "dis.vr.status_value_int",
FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_vr_status_value_float,
{"Status Value Float", "dis.vr.status_value_float",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_dis_iff_system_type,
{ "System Type", "dis.iff.system_type",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_IffSystemType_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_name,
{ "System Name", "dis.iff.system_name",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_IffSystemName_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_mode,
{ "System Mode", "dis.iff.system_mode",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffSystemMode_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_change_options,
{ "Change/Options", "dis.iff.change_options",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_change_indicator,
{ "Change Indicator", "dis.iff.change_indicator",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffChangeIndicator_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_alternate_mode_4,
{ "Alternate Mode 4", "dis.iff.alternate_mode_4",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffNoYes_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_alternate_mode_c,
{ "Alternate Mode C", "dis.iff.alternate_mode_c",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffNoYes_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status,
{ "System Status", "dis.iff.system_status",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status_system_onoff,
{ "System On/Off", "dis.iff.system_status.system_onoff",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffOffOn_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status_parameter_1,
{ "Parameter 1", "dis.iff.system_status.parameter_1",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffCapable_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status_parameter_2,
{ "Parameter 2", "dis.iff.system_status.parameter_2",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffCapable_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status_parameter_3,
{ "Parameter 3", "dis.iff.system_status.parameter_3",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffCapable_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status_parameter_4,
{ "Parameter 4", "dis.iff.system_status.parameter_4",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffCapable_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status_parameter_5,
{ "Parameter 5", "dis.iff.system_status.parameter_5",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffCapable_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status_parameter_6,
{ "Parameter 6", "dis.iff.system_status.parameter_6",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffCapable_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_system_status_operational,
{ "Operational", "dis.iff.system_status.operational",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffOperational_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_alternate_parameter_4,
{ "Alternate Parameter 4", "dis.iff.alternate_parameter_4",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffAlternateMode4_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_information_layers,
{ "Information Layers", "dis.iff.information_layers",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_information_layers_layer_1,
{ "Layer 1", "dis.iff.information_layers.layer_1",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffPresent_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_information_layers_layer_2,
{ "Layer 2", "dis.iff.information_layers.layer_2",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffPresent_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_modifier,
{ "Modifier", "dis.iff.modifier",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_modifier_other,
{ "Other", "dis.iff.modifier.other",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_modifier_emergency,
{ "Emergency", "dis.iff.modifier.emergency",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffOffOn_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_modifier_ident,
{ "Ident/Squawk Flash", "dis.iff.modifier.ident",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffOffOn_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_modifier_sti,
{ "STI", "dis.iff.modifier.sti",
FT_UINT8, BASE_DEC, VALS(DIS_PDU_IffOffOn_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_parameter_1,
{ "Parameter 1", "dis.iff.parameter_1",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_parameter_2,
{ "Parameter 2", "dis.iff.parameter_2",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_parameter_3,
{ "Parameter 3", "dis.iff.parameter_3",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_parameter_4,
{ "Parameter 4", "dis.iff.parameter_4",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_parameter_5,
{ "Parameter 5", "dis.iff.parameter_5",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_parameter_6,
{ "Parameter 6", "dis.iff.parameter_6",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_mode_1,
{ "IFF Mode 1", "dis.iff.mode_1",
FT_UINT16, BASE_OCT, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_mode_2,
{ "IFF Mode 2", "dis.iff.mode_2",
FT_UINT16, BASE_OCT, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_mode_3,
{ "IFF Mode 3", "dis.iff.mode_3",
FT_UINT16, BASE_OCT, NULL, 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_mode_status,
{ "Status", "dis.iff.mode.status",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_IffOffOn_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_mode_damage,
{ "Damage", "dis.iff.mode.damage",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_IffDamaged_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_mode_malfunction,
{ "Malfunction", "dis.iff.mode.malfunction",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_IffMalfunction_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_mode_4,
{ "IFF Mode 4 Pseude Crypto", "dis.iff.mode_4",
FT_UINT16, BASE_DEC, VALS(DIS_PDU_IffMode4_Strings), 0x0,
NULL, HFILL }
},
{ &hf_dis_iff_mode_c,
{ "IFF Mode C (FL)", "dis.iff.mode_c",
FT_INT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] =
{
&ett_dis,
&ett_dis_header,
&ett_dis_po_header,
&ett_dis_ens,
&ett_dis_crypto_key,
&ett_dis_payload,
&ett_entity,
&ett_trackjam,
&ett_radio_entity_type,
&ett_entity_type,
&ett_antenna_location,
&ett_rel_antenna_location,
&ett_modulation_type,
&ett_modulation_parameters,
&ett_entity_linear_velocity,
&ett_entity_location,
&ett_entity_orientation,
&ett_entity_appearance,
&ett_variable_parameter,
&ett_event_id,
&ett_shafts,
&ett_apas,
&ett_underwater_acoustic_emission,
&ett_acoustic_emitter_system,
&ett_ua_location,
&ett_ua_beams,
&ett_ua_beam_data,
&ett_emission_system,
&ett_emitter_system,
&ett_em_beam,
&ett_emitter_location,
&ett_em_fundamental_parameter_data,
&ett_burst_descriptor,
&ett_fire_location,
&ett_linear_velocity,
&ett_detonation_location,
&ett_clock_time,
&ett_fixed_datum,
&ett_record,
&ett_simulation_address,
&ett_offset_vector,
&ett_dis_signal_link16_network_header,
&ett_dis_signal_link16_message_data,
&ett_dis_signal_link16_jtids_header,
&ett_iff_location,
&ett_iff_system_id,
&ett_iff_change_options,
&ett_iff_fundamental_operational_data,
&ett_iff_system_status,
&ett_iff_information_layers,
&ett_iff_modifier,
&ett_iff_parameter_1,
&ett_iff_parameter_2,
&ett_iff_parameter_3,
&ett_iff_parameter_4,
&ett_iff_parameter_5,
&ett_iff_parameter_6,
};
module_t *dis_module;
proto_dis = proto_register_protocol("Distributed Interactive Simulation", "DIS", "dis");
proto_register_field_array(proto_dis, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
dis_module = prefs_register_protocol(proto_dis, proto_reg_handoff_dis);
prefs_register_uint_preference(dis_module, "udp.port",
"DIS UDP Port",
"Set the UDP port for DIS messages",
10, &dis_udp_port);
}
void proto_reg_handoff_dis(void)
{
static gboolean dis_prefs_initialized = FALSE;
static dissector_handle_t dis_dissector_handle;
static guint saved_dis_udp_port;
if (!dis_prefs_initialized)
{
dis_dissector_handle = new_create_dissector_handle(dissect_dis, proto_dis);
dis_prefs_initialized = TRUE;
}
else
{
dissector_delete_uint("udp.port", saved_dis_udp_port, dis_dissector_handle);
}
dissector_add_uint("udp.port", dis_udp_port, dis_dissector_handle);
saved_dis_udp_port = dis_udp_port;
}
