void
dissect_geographical_description(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree) {
proto_item *lat_item, *long_item, *major_item, *minor_item, *alt_item, *uncer_item;
guint8 type_of_shape;
int offset = 0;
int length;
guint8 value;
guint32 uvalue32;
gint32 svalue32;
length = tvb_reported_length_remaining(tvb, 0);
proto_tree_add_item(tree, hf_gsm_a_geo_loc_type_of_shape, tvb, 0, 1, ENC_BIG_ENDIAN);
if (length < 2)
return;
type_of_shape = tvb_get_guint8(tvb,offset)>>4;
switch (type_of_shape) {
case ELLIPSOID_POINT:
case ELLIPSOID_POINT_WITH_UNCERT_CIRC:
case ELLIPSOID_POINT_WITH_UNCERT_ELLIPSE:
case ELLIPSOID_POINT_WITH_ALT:
case ELLIPSOID_POINT_WITH_ALT_AND_UNCERT_ELLIPSOID:
case ELLIPSOID_ARC:
offset++;
if (length < 4)
return;
proto_tree_add_item(tree, hf_gsm_a_geo_loc_sign_of_lat, tvb, offset, 1, ENC_BIG_ENDIAN);
uvalue32 = tvb_get_ntoh24(tvb,offset);
lat_item = proto_tree_add_item(tree, hf_gsm_a_geo_loc_deg_of_lat, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(lat_item, " (%s%.5f degrees)",
(uvalue32 & 0x00800000) ? "-" : "",
((double)(uvalue32 & 0x7fffff)/8388607.0) * 90);
if (length < 7)
return;
offset = offset + 3;
svalue32 = tvb_get_ntoh24(tvb,offset);
svalue32 |= (svalue32 & 0x800000) ? 0xff000000 : 0x00000000;
long_item = proto_tree_add_item(tree, hf_gsm_a_geo_loc_deg_of_long, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(long_item, " (%.5f degrees)",
((double)svalue32/16777215.0) * 360);
offset = offset + 3;
if (type_of_shape == ELLIPSOID_POINT_WITH_UNCERT_CIRC) {
if (length < 8)
return;
value = tvb_get_guint8(tvb,offset)&0x7f;
uncer_item = proto_tree_add_item(tree, hf_gsm_a_geo_loc_uncertainty_code, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(uncer_item, " (%.1f m)", 10 * (pow(1.1, (double)value) - 1));
}else if (type_of_shape == ELLIPSOID_POINT_WITH_UNCERT_ELLIPSE) {
value = tvb_get_guint8(tvb,offset) & 0x7f;
major_item = proto_tree_add_item(tree, hf_gsm_a_geo_loc_uncertainty_semi_major, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(major_item, " (%.1f m)", 10 * (pow(1.1, (double)value) - 1));
offset++;
value = tvb_get_guint8(tvb,offset)&0x7f;
minor_item = proto_tree_add_item(tree, hf_gsm_a_geo_loc_uncertainty_semi_minor, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(minor_item, " (%.1f m)", 10 * (pow(1.1, (double)value) - 1));
offset++;
value = tvb_get_guint8(tvb,offset)&0x7f;
proto_tree_add_uint(tree, hf_gsm_a_geo_loc_orientation_of_major_axis, tvb, offset, 1, value*2);
offset++;
proto_tree_add_item(tree, hf_gsm_a_geo_loc_confidence, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
}else if (type_of_shape == ELLIPSOID_POINT_WITH_ALT) {
proto_tree_add_item(tree, hf_gsm_a_geo_loc_D, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_geo_loc_altitude, tvb, offset, 2, ENC_BIG_ENDIAN);
}else if (type_of_shape == ELLIPSOID_POINT_WITH_ALT_AND_UNCERT_ELLIPSOID) {
proto_tree_add_item(tree, hf_gsm_a_geo_loc_D, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_geo_loc_altitude, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset +2;
value = tvb_get_guint8(tvb,offset)&0x7f;
major_item = proto_tree_add_item(tree, hf_gsm_a_geo_loc_uncertainty_semi_major, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(major_item, " (%.1f m)", 10 * (pow(1.1, (double)value) - 1));
offset++;
value = tvb_get_guint8(tvb,offset)&0x7f;
minor_item = proto_tree_add_item(tree, hf_gsm_a_geo_loc_uncertainty_semi_minor, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(minor_item, " (%.1f m)", 10 * (pow(1.1, (double)value) - 1));
offset++;
value = tvb_get_guint8(tvb,offset)&0x7f;
proto_tree_add_uint(tree, hf_gsm_a_geo_loc_orientation_of_major_axis, tvb, offset, 1, value*2);
offset++;
value = tvb_get_guint8(tvb,offset)&0x7f;
alt_item = proto_tree_add_item(tree, hf_gsm_a_geo_loc_uncertainty_altitude, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(alt_item, " (%.1f m)", 45 * (pow(1.025, (double)value) - 1));
offset++;
proto_tree_add_item(tree, hf_gsm_a_geo_loc_confidence, tvb, offset, 1, ENC_BIG_ENDIAN);
}else if (type_of_shape == ELLIPSOID_ARC) {
proto_tree_add_item(tree, hf_gsm_a_geo_loc_inner_radius, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = offset + 2;
proto_tree_add_item(tree, hf_gsm_a_geo_loc_uncertainty_radius, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_a_geo_loc_offset_angle, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_a_geo_loc_included_angle, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_gsm_a_geo_loc_confidence, tvb, offset, 1, ENC_BIG_ENDIAN);
}
break;
case POLYGON:
proto_tree_add_item(tree, hf_gsm_a_geo_loc_no_of_points, tvb, offset, 1, ENC_BIG_ENDIAN);
#if 0
no_of_points = tvb_get_guint8(tvb,offset)&0x0f;
while ( no_of_points > 0) {
offset++;
no_of_points--;
}
#endif
break;
default:
break;
}
}
guint16
dissect_description_of_velocity(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_item *velocity_item;
guint32 curr_offset;
guint8 velocity_type, uncertainty_speed = 0;
curr_offset = offset;
velocity_type = tvb_get_guint8(tvb,curr_offset);
proto_tree_add_item(tree, hf_gsm_a_velocity_type, tvb, offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
switch (velocity_type) {
case 0:
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_bearing, tvb, (curr_offset<<3)+7, 9, ENC_BIG_ENDIAN);
curr_offset += 2;
velocity_item = proto_tree_add_item(tree, hf_gsm_a_horizontal_speed, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(velocity_item, " km/h");
curr_offset += 2;
break;
case 1:
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_d, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_bearing, tvb, (curr_offset<<3)+7, 9, ENC_BIG_ENDIAN);
curr_offset += 2;
velocity_item = proto_tree_add_item(tree, hf_gsm_a_horizontal_speed, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(velocity_item, " km/h");
curr_offset += 2;
velocity_item = proto_tree_add_item(tree, hf_gsm_a_vertical_speed, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(velocity_item, " km/h");
curr_offset++;
break;
case 2:
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 3, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_bearing, tvb, (curr_offset<<3)+7, 9, ENC_BIG_ENDIAN);
curr_offset += 2;
velocity_item = proto_tree_add_item(tree, hf_gsm_a_horizontal_speed, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(velocity_item, " km/h");
curr_offset += 2;
uncertainty_speed = tvb_get_guint8(tvb,curr_offset);
velocity_item = proto_tree_add_item(tree, hf_gsm_a_uncertainty_speed, tvb, offset, 2, ENC_BIG_ENDIAN);
if (uncertainty_speed == 255) {
proto_item_append_text(velocity_item, " not specified");
}else{
proto_item_append_text(velocity_item, " km/h");
}
offset++;
break;
case 3:
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_d, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_bearing, tvb, (curr_offset<<3)+7, 9, ENC_BIG_ENDIAN);
curr_offset += 2;
velocity_item = proto_tree_add_item(tree, hf_gsm_a_horizontal_speed, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(velocity_item, " km/h");
curr_offset += 2;
velocity_item = proto_tree_add_item(tree, hf_gsm_a_vertical_speed, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(velocity_item, " km/h");
curr_offset++;
uncertainty_speed = tvb_get_guint8(tvb,curr_offset);
velocity_item = proto_tree_add_item(tree, hf_gsm_a_h_uncertainty_speed, tvb, offset, 2, ENC_BIG_ENDIAN);
if (uncertainty_speed == 255) {
proto_item_append_text(velocity_item, " not specified");
}else{
proto_item_append_text(velocity_item, " km/h");
}
offset++;
uncertainty_speed = tvb_get_guint8(tvb,curr_offset);
velocity_item = proto_tree_add_item(tree, hf_gsm_a_v_uncertainty_speed, tvb, offset, 2, ENC_BIG_ENDIAN);
if (uncertainty_speed == 255) {
proto_item_append_text(velocity_item, " not specified");
}else{
proto_item_append_text(velocity_item, " km/h");
}
offset++;
break;
default:
break;
}
return (curr_offset - offset);
}
const char* get_gsm_a_msg_string(int pdu_type, int idx)
{
const char *msg_string = NULL;
switch (pdu_type) {
case GSM_A_PDU_TYPE_BSSMAP:
msg_string = val_to_str_ext(idx, &gsm_bssmap_elem_strings_ext, "GSM_A_PDU_TYPE_BSSMAP (%u)");
break;
case GSM_A_PDU_TYPE_DTAP:
msg_string = val_to_str_ext(idx, &gsm_dtap_elem_strings_ext, "GSM_A_PDU_TYPE_DTAP (%u)");
break;
case GSM_A_PDU_TYPE_RP:
msg_string = val_to_str_ext(idx, &gsm_rp_elem_strings_ext, "GSM_A_PDU_TYPE_RP (%u)");
break;
case GSM_A_PDU_TYPE_RR:
msg_string = val_to_str_ext(idx, &gsm_rr_elem_strings_ext, "GSM_A_PDU_TYPE_RR (%u)");
break;
case GSM_A_PDU_TYPE_COMMON:
msg_string = val_to_str_ext(idx, &gsm_common_elem_strings_ext, "GSM_A_PDU_TYPE_COMMON (%u)");
break;
case GSM_A_PDU_TYPE_GM:
msg_string = val_to_str_ext(idx, &gsm_gm_elem_strings_ext, "GSM_A_PDU_TYPE_GM (%u)");
break;
case GSM_A_PDU_TYPE_BSSLAP:
msg_string = val_to_str_ext(idx, &gsm_bsslap_elem_strings_ext, "GSM_A_PDU_TYPE_BSSLAP (%u)");
break;
case GSM_PDU_TYPE_BSSMAP_LE:
msg_string = val_to_str_ext(idx, &gsm_bssmap_le_elem_strings_ext, "GSM_PDU_TYPE_BSSMAP_LE (%u)");
break;
case NAS_PDU_TYPE_COMMON:
msg_string = val_to_str_ext(idx, &nas_eps_common_elem_strings_ext, "NAS_PDU_TYPE_COMMON (%u)");
break;
case NAS_PDU_TYPE_EMM:
msg_string = val_to_str_ext(idx, &nas_emm_elem_strings_ext, "NAS_PDU_TYPE_EMM (%u)");
break;
case NAS_PDU_TYPE_ESM:
msg_string = val_to_str_ext(idx, &nas_esm_elem_strings_ext, "NAS_PDU_TYPE_ESM (%u)");
break;
case SGSAP_PDU_TYPE:
msg_string = val_to_str_ext(idx, &sgsap_elem_strings_ext, "SGSAP_PDU_TYPE (%u)");
break;
case BSSGP_PDU_TYPE:
msg_string = val_to_str_ext(idx, &bssgp_elem_strings_ext, "BSSGP_PDU_TYPE (%u)");
break;
case GMR1_IE_COMMON:
msg_string = val_to_str_ext(idx, &gmr1_ie_common_strings_ext, "GMR1_IE_COMMON (%u)");
break;
case GMR1_IE_RR:
msg_string = val_to_str_ext(idx, &gmr1_ie_rr_strings_ext, "GMR1_IE_RR (%u)");
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
return msg_string;
}
static int get_hf_elem_id(int pdu_type)
{
int hf_elem_id = 0;
switch (pdu_type) {
case GSM_A_PDU_TYPE_BSSMAP:
hf_elem_id = hf_gsm_a_bssmap_elem_id;
break;
case GSM_A_PDU_TYPE_DTAP:
hf_elem_id = hf_gsm_a_dtap_elem_id;
break;
case GSM_A_PDU_TYPE_RP:
hf_elem_id = hf_gsm_a_rp_elem_id;
break;
case GSM_A_PDU_TYPE_RR:
hf_elem_id = hf_gsm_a_rr_elem_id;
break;
case GSM_A_PDU_TYPE_COMMON:
hf_elem_id = hf_gsm_a_common_elem_id;
break;
case GSM_A_PDU_TYPE_GM:
hf_elem_id = hf_gsm_a_gm_elem_id;
break;
case GSM_A_PDU_TYPE_BSSLAP:
hf_elem_id = hf_gsm_a_bsslap_elem_id;
break;
case GSM_PDU_TYPE_BSSMAP_LE:
hf_elem_id = hf_gsm_bssmap_le_elem_id;
break;
case NAS_PDU_TYPE_COMMON:
hf_elem_id = hf_nas_eps_common_elem_id;
break;
case NAS_PDU_TYPE_EMM:
hf_elem_id = hf_nas_eps_emm_elem_id;
break;
case NAS_PDU_TYPE_ESM:
hf_elem_id = hf_nas_eps_esm_elem_id;
break;
case SGSAP_PDU_TYPE:
hf_elem_id = hf_sgsap_elem_id;
break;
case BSSGP_PDU_TYPE:
hf_elem_id = hf_bssgp_elem_id;
break;
case GMR1_IE_COMMON:
case GMR1_IE_RR:
hf_elem_id = hf_gmr1_elem_id;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
return hf_elem_id;
}
guint16 elem_tlv(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint8 iei, gint pdu_type, int idx, guint32 offset, guint len _U_, const gchar *name_add)
{
guint8 oct;
guint16 parm_len;
guint8 lengt_length = 1;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
const gchar *elem_name;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == iei) {
parm_len = tvb_get_guint8(tvb, curr_offset + 1);
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL) {
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_unknown_element,
tvb, curr_offset, parm_len + 1 + lengt_length,
"Unknown - aborting dissection%s", (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
return consumed;
}
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, parm_len + 1 + lengt_length, elem_ett[idx], &item,
"%s%s", elem_name, (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree,
get_hf_elem_id(pdu_type), tvb,
curr_offset, 1, oct);
proto_tree_add_uint(subtree, hf_gsm_a_length, tvb,
curr_offset + 1, lengt_length, parm_len);
if (parm_len > 0)
{
if (elem_funcs[idx] == NULL)
{
proto_tree_add_item(subtree, hf_gsm_a_element_value, tvb, curr_offset + 1 + lengt_length, parm_len, ENC_NA);
consumed = (guint8)parm_len;
}
else
{
gchar *a_add_string;
a_add_string = (gchar *)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
consumed =
(*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset + 2,
parm_len, a_add_string, 1024);
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
}
}
consumed += 1 + lengt_length;
}
return consumed;
}
guint16 elem_telv(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint8 iei, gint pdu_type, int idx, guint32 offset, guint len _U_, const gchar *name_add)
{
guint8 oct;
guint16 parm_len;
guint8 lengt_length = 1;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
const gchar *elem_name;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == iei) {
parm_len = tvb_get_guint8(tvb, curr_offset + 1);
if ((parm_len&0x80) == 0) {
parm_len = tvb_get_ntohs(tvb, curr_offset + 1);
lengt_length = 2;
}else{
parm_len = parm_len & 0x7f;
}
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL) {
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_unknown_element,
tvb, curr_offset, parm_len + 1 + lengt_length,
"Unknown - aborting dissection%s", (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
return consumed;
}
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, parm_len + 1 + lengt_length, elem_ett[idx], &item,
"%s%s", elem_name, (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree,
get_hf_elem_id(pdu_type), tvb,
curr_offset, 1, oct);
proto_tree_add_item(subtree, hf_gsm_a_l_ext, tvb, curr_offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(subtree, hf_gsm_a_length, tvb,
curr_offset + 1, lengt_length, parm_len);
if (parm_len > 0)
{
if (elem_funcs[idx] == NULL)
{
proto_tree_add_item(subtree, hf_gsm_a_element_value, tvb, curr_offset + 1 + lengt_length, parm_len, ENC_NA);
consumed = parm_len;
}
else
{
gchar *a_add_string;
a_add_string = (gchar*)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
consumed =
(*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset + 1 + lengt_length,
parm_len, a_add_string, 1024);
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
}
}
consumed += 1 + lengt_length;
}
return consumed;
}
guint16 elem_tlv_e(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint8 iei, gint pdu_type, int idx, guint32 offset, guint len _U_, const gchar *name_add)
{
guint8 oct;
guint16 parm_len;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
const gchar *elem_name;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == iei) {
parm_len = tvb_get_ntohs(tvb, curr_offset + 1);
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL) {
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_unknown_element,
tvb, curr_offset, parm_len + 1 + 2,
"Unknown - aborting dissection%s", (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
return consumed;
}
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, parm_len + 1 + 2, elem_ett[idx], &item,
"%s%s", elem_name, (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree,
get_hf_elem_id(pdu_type), tvb,
curr_offset, 1, oct);
proto_tree_add_uint(subtree, hf_gsm_a_length, tvb,
curr_offset + 1, 2, parm_len);
if (parm_len > 0)
{
if (elem_funcs[idx] == NULL)
{
proto_tree_add_item(subtree, hf_gsm_a_element_value, tvb, curr_offset + 1 + 2, parm_len, ENC_NA);
consumed = parm_len;
}
else
{
gchar *a_add_string;
a_add_string = (gchar*)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
consumed =
(*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset + 1 + 2,
parm_len, a_add_string, 1024);
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
}
}
consumed += 1 + 2;
}
return consumed;
}
guint16 elem_tv(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint8 iei, gint pdu_type, int idx, guint32 offset, const gchar *name_add)
{
guint8 oct;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
const gchar *elem_name;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == iei)
{
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL) {
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_unknown_element,
tvb, curr_offset, -1,
"Unknown - aborting dissection%s", (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
return consumed;
}
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, -1, elem_ett[idx], &item,
"%s%s", elem_name, (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree,
get_hf_elem_id(pdu_type), tvb,
curr_offset, 1, oct);
if (elem_funcs[idx] == NULL)
{
expert_add_info(pinfo, item, &ei_gsm_a_no_element_dissector);
consumed = 1;
}
else
{
gchar *a_add_string;
a_add_string = (gchar*)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
consumed = (*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset + 1, -1, a_add_string, 1024);
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
}
consumed++;
proto_item_set_len(item, consumed);
}
return consumed;
}
guint16 elem_tv_short(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint8 iei, gint pdu_type, int idx, guint32 offset, const gchar *name_add)
{
guint8 oct;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
const gchar *elem_name;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
oct = tvb_get_guint8(tvb, curr_offset);
if ((oct & 0xf0) == (iei & 0xf0))
{
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL) {
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_unknown_element,
tvb, curr_offset, -1,
"Unknown - aborting dissection%s", (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
return consumed;
}
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, -1, elem_ett[idx], &item,
"%s%s", elem_name, (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint_format_value(subtree, hf_gsm_a_common_elem_id_f0, tvb, curr_offset, 1, oct, "0x%1x-", oct>>4);
if (elem_funcs[idx] == NULL)
{
expert_add_info(pinfo, item, &ei_gsm_a_no_element_dissector);
consumed++;
}
else
{
gchar *a_add_string;
a_add_string = (gchar*)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
consumed = (*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset, RIGHT_NIBBLE, a_add_string, 1024);
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
}
proto_item_set_len(item, consumed);
}
return consumed;
}
guint16 elem_t(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint8 iei, gint pdu_type, int idx, guint32 offset, const gchar *name_add)
{
guint8 oct;
guint32 curr_offset;
guint16 consumed;
value_string_ext elem_names_ext;
gint *elem_ett;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
(void)elem_ett;
(void)elem_funcs;
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == iei)
{
proto_tree_add_uint_format(tree,
get_hf_elem_id(pdu_type), tvb,
curr_offset, 1, oct,
"%s%s",
val_to_str_ext(idx, &elem_names_ext, "Unknown (%u)"),
(name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
consumed = 1;
}
return consumed;
}
guint16
elem_lv(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint pdu_type, int idx, guint32 offset, guint len _U_, const gchar *name_add)
{
guint8 parm_len;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
const gchar *elem_name;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
parm_len = tvb_get_guint8(tvb, curr_offset);
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL) {
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_unknown_element,
tvb, curr_offset, parm_len + 1,
"Unknown - aborting dissection%s", (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
return consumed;
}
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, parm_len + 1, elem_ett[idx], &item,
"%s%s", elem_name, (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree, hf_gsm_a_length, tvb,
curr_offset, 1, parm_len);
if (parm_len > 0)
{
if (elem_funcs[idx] == NULL)
{
proto_tree_add_item(subtree, hf_gsm_a_element_value, tvb, curr_offset + 1, parm_len, ENC_NA);
consumed = parm_len;
}
else
{
gchar *a_add_string;
a_add_string = (gchar*)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
consumed =
(*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset + 1,
parm_len, a_add_string, 1024);
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
}
}
return (consumed + 1);
}
guint16 elem_lv_e(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint pdu_type, int idx, guint32 offset, guint len _U_, const gchar *name_add)
{
guint16 parm_len;
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
const gchar *elem_name;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
parm_len = tvb_get_ntohs(tvb, curr_offset);
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL) {
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_unknown_element,
tvb, curr_offset, parm_len + 2,
"Unknown - aborting dissection%s", (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
return consumed;
}
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, parm_len + 2, elem_ett[idx], &item,
"%s%s", elem_name, (name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
proto_tree_add_uint(subtree, hf_gsm_a_length, tvb,
curr_offset, 2, parm_len);
if (parm_len > 0)
{
if (elem_funcs[idx] == NULL)
{
proto_tree_add_item(subtree, hf_gsm_a_element_value, tvb, curr_offset + 2, parm_len, ENC_NA);
consumed = parm_len;
}
else
{
gchar *a_add_string;
a_add_string = (gchar*)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
consumed =
(*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset + 2,
parm_len, a_add_string, 1024);
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
}
}
return (consumed + 2);
}
guint16 elem_v(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint pdu_type, int idx, guint32 offset, const gchar *name_add)
{
guint16 consumed;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
const gchar *elem_name;
guint16 (**elem_funcs)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len);
curr_offset = offset;
consumed = 0;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL || elem_funcs[idx] == NULL)
{
proto_tree_add_expert(tree, pinfo, &ei_gsm_a_no_element_dissector, tvb, curr_offset, 1);
consumed = 1;
}
else
{
gchar *a_add_string;
subtree =
proto_tree_add_subtree_format(tree,
tvb, curr_offset, 0,
elem_ett[idx], &item, "%s%s", elem_name,
(name_add == NULL) || (name_add[0] == '\0') ? "" : name_add);
a_add_string= (gchar*)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
consumed = (*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset, -1, a_add_string, 1024);
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
proto_item_set_len(item, consumed);
}
return (consumed);
}
guint16 elem_v_short(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, gint pdu_type, int idx, guint32 offset, guint32 nibble)
{
guint16 consumed = 1;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
value_string_ext elem_names_ext;
gint *elem_ett;
elem_fcn *elem_funcs;
gchar *a_add_string;
const gchar *elem_name;
curr_offset = offset;
SET_ELEM_VARS(pdu_type, elem_names_ext, elem_ett, elem_funcs, &ei_gsm_a_unknown_pdu_type);
elem_name = try_val_to_str_ext(idx, &elem_names_ext);
if (elem_name == NULL) {
proto_tree_add_expert(tree, pinfo, &ei_gsm_a_unknown_element,
tvb, curr_offset, 0);
return consumed;
}
subtree = proto_tree_add_subtree(tree, tvb, curr_offset, 0, elem_ett[idx], &item, elem_name);
a_add_string= (gchar*)wmem_alloc(wmem_packet_scope(), 1024);
a_add_string[0] = '\0';
if (elem_funcs[idx] == NULL)
{
(void)de_spare_nibble(tvb, subtree, pinfo, curr_offset, nibble, a_add_string, 1024);
}
else
{
(void)(*elem_funcs[idx])(tvb, subtree, pinfo, curr_offset, nibble, a_add_string, 1024);
}
if (a_add_string[0] != '\0')
{
proto_item_append_text(item, "%s", a_add_string);
}
proto_item_set_len(item, consumed);
return consumed;
}
static void
mcc_mnc_aux(guint8 *octs, gchar *mcc, gchar *mnc)
{
if ((octs[0] & 0x0f) <= 9)
{
mcc[0] = Dgt_tbcd.out[octs[0] & 0x0f];
}
else
{
mcc[0] = (octs[0] & 0x0f) + 55;
}
if (((octs[0] & 0xf0) >> 4) <= 9)
{
mcc[1] = Dgt_tbcd.out[(octs[0] & 0xf0) >> 4];
}
else
{
mcc[1] = ((octs[0] & 0xf0) >> 4) + 55;
}
if ((octs[1] & 0x0f) <= 9)
{
mcc[2] = Dgt_tbcd.out[octs[1] & 0x0f];
}
else
{
mcc[2] = (octs[1] & 0x0f) + 55;
}
mcc[3] = '\0';
if (((octs[1] & 0xf0) >> 4) <= 9)
{
mnc[2] = Dgt_tbcd.out[(octs[1] & 0xf0) >> 4];
}
else
{
mnc[2] = ((octs[1] & 0xf0) >> 4) + 55;
}
if ((octs[2] & 0x0f) <= 9)
{
mnc[0] = Dgt_tbcd.out[octs[2] & 0x0f];
}
else
{
mnc[0] = (octs[2] & 0x0f) + 55;
}
if (((octs[2] & 0xf0) >> 4) <= 9)
{
mnc[1] = Dgt_tbcd.out[(octs[2] & 0xf0) >> 4];
}
else
{
mnc[1] = ((octs[2] & 0xf0) >> 4) + 55;
}
if (mnc[1] == 'F')
{
mnc[1] = '\0';
}
else if (mnc[2] == 'F')
{
mnc[2] = '\0';
}
else
{
mnc[3] = '\0';
}
}
guint16
de_cell_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint32 curr_offset;
curr_offset = offset;
curr_offset +=
be_cell_id_aux(tvb, tree, pinfo, offset, len, add_string, string_len, 0x02);
return (curr_offset - offset);
}
static guint16
de_ciph_key_seq_num( tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
if (RIGHT_NIBBLE == len)
bit_offset = 4;
else
bit_offset = 0;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+bit_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_key_seq, tvb, (curr_offset<<3)+bit_offset+1, 3, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
guint16
de_lai(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 octs[3];
guint16 value;
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
gchar mcc[4];
gchar mnc[4];
curr_offset = offset;
subtree = proto_tree_add_subtree(tree,
tvb, curr_offset, 5, ett_gsm_common_elem[DE_LAI], &item,
val_to_str_ext_const(DE_LAI, &gsm_common_elem_strings_ext, ""));
octs[0] = tvb_get_guint8(tvb, curr_offset);
octs[1] = tvb_get_guint8(tvb, curr_offset + 1);
octs[2] = tvb_get_guint8(tvb, curr_offset + 2);
mcc_mnc_aux(octs, mcc, mnc);
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, subtree, curr_offset, E212_LAI, TRUE);
value = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_item(subtree, hf_gsm_a_lac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(item, " - %s/%s/%u", mcc,mnc,value);
curr_offset += 2;
return (curr_offset - offset);
}
guint16
de_mid(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 oct;
guint32 curr_offset;
guint32 value;
gboolean odd;
const gchar *digit_str;
proto_item* ti;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct & 0x07)
{
case 0:
proto_tree_add_item(tree, hf_gsm_a_unused, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_mobile_identity_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (add_string)
g_snprintf(add_string, string_len, " - No Identity Code");
curr_offset++;
if (len > 1)
{
expert_add_info(pinfo, tree, &ei_gsm_a_format_not_supported);
}
curr_offset += len - 1;
break;
case 3:
case 1:
odd = oct & 0x08;
proto_tree_add_item(tree, hf_gsm_a_id_dig_1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_mobile_identity_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (curr_offset - offset >= len)
return (curr_offset - offset);
if((oct & 0x07) == 3){
digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb ,curr_offset , len - (curr_offset - offset), NULL, TRUE);
proto_tree_add_string_format(tree,
hf_gsm_a_imeisv,
tvb, curr_offset, len - (curr_offset - offset),
digit_str,
"BCD Digits: %s",
digit_str);
}else{
digit_str = dissect_e212_imsi(tvb, pinfo, tree, curr_offset, len - (curr_offset - offset), TRUE);
}
if (sccp_assoc && ! sccp_assoc->calling_party) {
sccp_assoc->calling_party = wmem_strdup_printf(wmem_file_scope(),
((oct & 0x07) == 3) ? "IMEISV: %s" : "IMSI: %s",
digit_str );
}
if (add_string)
g_snprintf(add_string, string_len, " - %s (%s)",
((oct & 0x07) == 3) ? "IMEISV" : "IMSI",
digit_str);
curr_offset += len - (curr_offset - offset);
if (!odd)
{
proto_tree_add_item(tree, hf_gsm_a_filler, tvb, curr_offset - 1, 1, ENC_NA);
}
break;
case 2:
proto_tree_add_uint_format_value(tree, hf_gsm_a_identity_digit1, tvb, curr_offset, 1, oct, "%c", Dgt1_9_bcd.out[(oct & 0xf0) >> 4]);
proto_tree_add_item(tree, hf_gsm_a_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_mobile_identity_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
if (curr_offset - offset >= len)
return (curr_offset - offset);
digit_str = tvb_bcd_dig_to_wmem_packet_str(tvb, curr_offset, len - (curr_offset - offset), NULL, TRUE);
proto_tree_add_string_format(tree,
hf_gsm_a_imei,
tvb, curr_offset, len - (curr_offset - offset),
digit_str,
"BCD Digits: %s",
digit_str);
if (add_string)
g_snprintf(add_string, string_len, " - IMEI (%s)", digit_str);
curr_offset += len - (curr_offset - offset);
break;
case 4:
proto_tree_add_item(tree, hf_gsm_a_unused, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_mobile_identity_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
value = tvb_get_ntohl(tvb, curr_offset);
proto_tree_add_uint(tree, hf_gsm_a_tmsi,
tvb, curr_offset, 4,
value);
if (add_string)
g_snprintf(add_string, string_len, " - TMSI/P-TMSI (0x%04x)", value);
curr_offset += 4;
break;
case 5:
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_mbs_ses_id_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_tmgi_mcc_mnc_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_mobile_identity_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_gsm_a_mbs_service_id, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset += 3;
if ((oct&0x10) == 0x10) {
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, E212_NONE, TRUE);
}
if ((oct&0x20) == 0x20) {
proto_tree_add_item(tree, hf_gsm_a_mbs_session_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
break;
default:
proto_tree_add_item(tree, hf_gsm_a_odd_even_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(tree, hf_gsm_a_mobile_identity_type, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
expert_add_info_format(pinfo, ti, &ei_gsm_a_mobile_identity_type, "Unknown format %u", (oct & 0x07));
if (add_string)
g_snprintf(add_string, string_len, " - Format Unknown");
curr_offset += len;
break;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_extraneous_data);
return (curr_offset - offset);
}
guint16
de_ms_cm_1(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
proto_tree *subtree;
curr_offset = offset;
subtree =
proto_tree_add_subtree(tree,
tvb, curr_offset, 1, ett_gsm_common_elem[DE_MS_CM_1], NULL,
val_to_str_ext_const(DE_MS_CM_1, &gsm_common_elem_strings_ext, ""));
proto_tree_add_item(subtree, hf_gsm_a_b8spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_MSC_rev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_ES_IND, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_A5_1_algorithm_sup, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_RF_power_capability, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
guint16
de_ms_cm_2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_b8spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_MSC_rev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_ES_IND, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_A5_1_algorithm_sup, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_RF_power_capability, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_b8spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_ps_sup_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_SS_screening_indicator, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_SM_capability, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_VBS_notification_rec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_VGCS_notification_rec, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_FC_frequency_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_CM3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_b7spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_LCS_VA_cap, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_UCS2_treatment, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_SoLSA, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_CMSP, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_A5_3_algorithm_sup, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_A5_2_algorithm_sup, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_extraneous_data);
return (curr_offset - offset);
}
guint16
de_ms_cm_3(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 bit_offset;
guint8 length;
proto_tree *subtree;
proto_item *item;
guint32 bits_left, target_bit_offset, old_bit_offset;
guint64 multi_bnd_sup_fields, rsupport, multislotCapability;
guint64 msMeasurementCapability, msPosMethodCapPresent;
guint64 ecsdMultiSlotCapability, eightPskStructPresent, eightPskStructRfPowerCapPresent;
guint64 gsm400BandInfoPresent, gsm850AssocRadioCapabilityPresent;
guint64 gsm1900AssocRadioCapabilityPresent, dtmEGprsMultiSlotInfoPresent;
guint64 dtmEgprsMultiSlotClassPresent, singleBandSupport;
guint64 gsm750AssocRadioCapabilityPresent, extDtmEGprsMultiSlotInfoPresent;
guint64 highMultislotCapPresent, geranIuModeSupport;
guint64 tGsm400BandInfoPresent, tGsm900AssocRadioCapabilityPresent, dtmEGprsHighMultiSlotInfoPresent;
guint64 dtmEgprsHighMultiSlotClassPresent, gsm710AssocRadioCapabilityPresent;
guint64 tGsm810AssocRadioCapabilityPresent;
curr_offset = offset;
bit_offset = curr_offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
item = proto_tree_add_bits_ret_val(tree, hf_gsm_a_multi_bnd_sup_fields, tvb, bit_offset, 3, &multi_bnd_sup_fields, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_MS_CM_3]);
proto_tree_add_bits_item(subtree, hf_gsm_a_gsm1800_supported, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_egsm_supported, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_pgsm_supported, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
item = proto_tree_add_bits_item(tree, hf_gsm_a_cm3_A5_bits, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_MS_CM_3]);
proto_tree_add_bits_item(subtree, hf_gsm_a_A5_7_algorithm_sup, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_A5_6_algorithm_sup, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_A5_5_algorithm_sup, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_A5_4_algorithm_sup, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
switch (multi_bnd_sup_fields) {
case 0:
break;
case 1:
case 2:
case 4:
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(tree, hf_gsm_a_ass_radio_cap1, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
break;
case 5:
case 6:
proto_tree_add_bits_item(tree, hf_gsm_a_ass_radio_cap2, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(tree, hf_gsm_a_ass_radio_cap1, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
break;
default:
break;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_rsupport, tvb, bit_offset, 1, &rsupport, ENC_BIG_ENDIAN);
bit_offset++;
if (rsupport == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_r_capabilities, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 3;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_multislot_capabilities, tvb, bit_offset, 1, &multislotCapability, ENC_BIG_ENDIAN);
bit_offset++;
if (multislotCapability == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_multislot_class, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 5;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_ucs2_treatment, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_extended_measurement_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_ms_measurement_capability, tvb, bit_offset, 1, &msMeasurementCapability, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (msMeasurementCapability == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_sms_value, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
proto_tree_add_bits_item(tree, hf_gsm_a_sm_value, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_ms_pos_method_cap_present, tvb, bit_offset, 1, &msPosMethodCapPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (msPosMethodCapPresent == 1)
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_ms_pos_method, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_MS_CM_3]);
proto_tree_add_bits_item(subtree, hf_gsm_a_ms_assisted_e_otd, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_ms_based_e_otd, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_ms_assisted_gps, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_ms_based_gps, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_ms_conventional_gps, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_ecsd_multi_slot_capability, tvb, bit_offset, 1, &ecsdMultiSlotCapability, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (ecsdMultiSlotCapability == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_ecsd_multi_slot_class, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 5;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_8_psk_struct_present, tvb, bit_offset, 1, &eightPskStructPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (eightPskStructPresent == 1)
{
guint8 psk_struct_len = 3;
guint32 tmp_bit_offset = bit_offset;
tmp_bit_offset++;
if (tvb_get_bits8(tvb,tmp_bit_offset,1) == 1){
psk_struct_len += 2;
tmp_bit_offset += 2;
}
tmp_bit_offset++;
if (tvb_get_bits8(tvb,tmp_bit_offset,1) == 1){
psk_struct_len += 2;
}
item = proto_tree_add_bits_item(tree, hf_gsm_a_8_psk_struct, tvb, bit_offset, psk_struct_len, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_MS_CM_3]);
old_bit_offset = bit_offset;
proto_tree_add_bits_item(subtree, hf_gsm_a_modulation_capability, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
proto_tree_add_bits_ret_val(subtree, hf_gsm_a_8_psk_rf_power_capability_1_present, tvb, bit_offset,
1, &eightPskStructRfPowerCapPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (eightPskStructRfPowerCapPresent == 1)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_8_psk_rf_power_capability_1, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
}
proto_tree_add_bits_ret_val(subtree, hf_gsm_a_8_psk_rf_power_capability_2_present, tvb, bit_offset,
1, &eightPskStructRfPowerCapPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (eightPskStructRfPowerCapPresent == 1)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_8_psk_rf_power_capability_2, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
}
length = (guint8)((bit_offset - old_bit_offset)>>3);
if ((bit_offset - old_bit_offset) & 0x07)
length++;
proto_item_set_len(item, length);
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_gsm_400_band_info_present, tvb, bit_offset, 1, &gsm400BandInfoPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (gsm400BandInfoPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_gsm_400_bands_supported, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
proto_tree_add_bits_item(tree, hf_gsm_a_gsm_400_assoc_radio_cap, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_gsm_850_assoc_radio_cap_present, tvb, bit_offset, 1, &gsm850AssocRadioCapabilityPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (gsm850AssocRadioCapabilityPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_gsm_850_assoc_radio_cap, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_gsm_1900_assoc_radio_cap_present, tvb, bit_offset, 1, &gsm1900AssocRadioCapabilityPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (gsm1900AssocRadioCapabilityPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_gsm_1900_assoc_radio_cap, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_umts_fdd_rat_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_umts_384_mcps_tdd_rat_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_cdma_2000_rat_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_dtm_e_gprs_multi_slot_info_present, tvb, bit_offset, 1, &dtmEGprsMultiSlotInfoPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (dtmEGprsMultiSlotInfoPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_dtm_gprs_multi_slot_class, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
proto_tree_add_bits_item(tree, hf_gsm_a_single_slot_dtm, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
proto_tree_add_bits_ret_val(tree, hf_gsm_a_dtm_egprs_multi_slot_class_present, tvb, bit_offset, 1, &dtmEgprsMultiSlotClassPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (dtmEgprsMultiSlotClassPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_dtm_egprs_multi_slot_class, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
}
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_single_band_support, tvb, bit_offset, 1, &singleBandSupport, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (singleBandSupport == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_gsm_band, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_gsm_750_assoc_radio_cap_present, tvb, bit_offset, 1, &gsm750AssocRadioCapabilityPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (gsm750AssocRadioCapabilityPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_gsm_750_assoc_radio_cap, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_umts_128_mcps_tdd_rat_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_geran_feature_package_1, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_ext_dtm_e_gprs_multi_slot_info_present, tvb, bit_offset, 1, &extDtmEGprsMultiSlotInfoPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (extDtmEGprsMultiSlotInfoPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_ext_dtm_gprs_multi_slot_class, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
proto_tree_add_bits_item(tree, hf_gsm_a_ext_dtm_egprs_multi_slot_class, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_high_multislot_cap_present, tvb, bit_offset, 1, &highMultislotCapPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (highMultislotCapPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_high_multislot_cap, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_geran_iu_mode_support, tvb, bit_offset, 1, &geranIuModeSupport, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (geranIuModeSupport == 1)
{
length = tvb_get_bits8(tvb, bit_offset, 4);
item = proto_tree_add_bits_item(tree, hf_gsm_a_geran_iu_mode_cap, tvb, bit_offset, length + 4, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_MS_CM_3]);
proto_tree_add_bits_item(subtree, hf_gsm_a_geran_iu_mode_cap_length, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
target_bit_offset = bit_offset + length;
proto_tree_add_bits_item(subtree, hf_gsm_a_flo_iu_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
if (target_bit_offset > bit_offset)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_spare_bits, tvb, bit_offset, target_bit_offset - bit_offset, ENC_BIG_ENDIAN);
bit_offset = target_bit_offset;
}
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_geran_feature_package_2, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(2);
proto_tree_add_bits_item(tree, hf_gsm_a_gmsk_multislot_power_prof, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
AVAILABLE_BITS_CHECK(2);
proto_tree_add_bits_item(tree, hf_gsm_a_8_psk_multislot_power_prof, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_t_gsm_400_band_info_present, tvb, bit_offset, 1, &tGsm400BandInfoPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (tGsm400BandInfoPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_t_gsm_400_bands_supported, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
proto_tree_add_bits_item(tree, hf_gsm_a_t_gsm_400_assoc_radio_cap, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_t_gsm_900_assoc_radio_cap_present, tvb, bit_offset, 1, &tGsm900AssocRadioCapabilityPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (tGsm900AssocRadioCapabilityPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_t_gsm_900_assoc_radio_cap, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(2);
proto_tree_add_bits_item(tree, hf_gsm_a_downlink_adv_receiver_perf, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_dtm_enhancements_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_dtm_e_gprs_high_multi_slot_info_present, tvb, bit_offset, 1, &dtmEGprsHighMultiSlotInfoPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (dtmEGprsHighMultiSlotInfoPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_dtm_gprs_high_multi_slot_class, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 3;
proto_tree_add_bits_item(tree, hf_gsm_a_offset_required, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
proto_tree_add_bits_ret_val(tree, hf_gsm_a_dtm_egprs_high_multi_slot_class_present, tvb, bit_offset, 1, &dtmEgprsHighMultiSlotClassPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (dtmEgprsHighMultiSlotClassPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_dtm_egprs_high_multi_slot_class, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 3;
}
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_repeated_acch_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_gsm_710_assoc_radio_cap_present, tvb, bit_offset, 1, &gsm710AssocRadioCapabilityPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (gsm710AssocRadioCapabilityPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_gsm_710_assoc_radio_cap, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_ret_val(tree, hf_gsm_a_t_gsm_810_assoc_radio_cap_present, tvb, bit_offset, 1, &tGsm810AssocRadioCapabilityPresent, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
if (tGsm810AssocRadioCapabilityPresent == 1)
{
proto_tree_add_bits_item(tree, hf_gsm_a_t_gsm_810_assoc_radio_cap, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 4;
}
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_ciphering_mode_setting_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_additional_positioning_caps, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_e_utra_fdd_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_e_utra_tdd_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_e_utra_meas_and_report_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_prio_based_resel_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_utra_csg_cells_reporting, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(2);
proto_tree_add_bits_item(tree, hf_gsm_a_vamos_level, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
AVAILABLE_BITS_CHECK(2);
proto_tree_add_bits_item(tree, hf_gsm_a_tighter_cap, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_selective_ciph_down_sacch, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(2);
proto_tree_add_bits_item(tree, hf_gsm_a_cs_to_ps_srvcc_geran_to_utra, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
AVAILABLE_BITS_CHECK(2);
proto_tree_add_bits_item(tree, hf_gsm_a_cs_to_ps_srvcc_geran_to_eutra, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 2;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_geran_network_sharing_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_eutra_wb_rsrq_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_er_band_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_utra_mfbi_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_eutra_mfbi_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_ext_tsc_set_cap_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
AVAILABLE_BITS_CHECK(1);
proto_tree_add_bits_item(tree, hf_gsm_a_ext_earfcn_value_range, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset = bit_offset + 1;
bits_left = (((len + offset) << 3) - bit_offset) & 0x07;
if (bits_left != 0)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, bits_left, ENC_BIG_ENDIAN);
bit_offset += bits_left;
}
curr_offset = bit_offset >> 3;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_extraneous_data);
return len;
}
guint16 de_spare_nibble(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
curr_offset = offset;
if (RIGHT_NIBBLE == len)
bit_offset = 4;
else
bit_offset = 0;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_nibble, tvb, (curr_offset<<3)+bit_offset, 4, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return (curr_offset - offset);
}
guint16
de_d_gb_call_ref(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_group_call_reference, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_service_flag, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_af_acknowledgement, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_call_priority, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
proto_tree_add_item(tree, hf_gsm_a_ciphering_info, tvb, curr_offset, 1, ENC_NA);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3)+4, 4, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_pd_sapi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
proto_tree *subtree;
curr_offset = offset;
subtree =
proto_tree_add_subtree(tree,
tvb, curr_offset, 1, ett_gsm_dtap_elem[DE_PD_SAPI], NULL,
val_to_str_ext_const(DE_PD_SAPI, &gsm_dtap_elem_strings_ext, ""));
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset<<3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_sapi, tvb, curr_offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_gsm_a_L3_protocol_discriminator, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_prio(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_b8spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_call_prio, tvb, (curr_offset<<3)+5, 3, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
guint16
de_cn_common_gsm_map_nas_sys_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_lac, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_extraneous_data);
return (curr_offset - offset);
}
guint16
de_cs_domain_spec_sys_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_t3212, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3), 7, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_att, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_extraneous_data);
return (curr_offset - offset);
}
guint16
de_ps_domain_spec_sys_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_gm_rac, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3), 6, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_nmo_1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_nmo, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_extraneous_data);
return (curr_offset - offset);
}
guint16
de_plmn_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
guint8 octs[3];
guint32 curr_offset;
gchar mcc[4];
gchar mnc[4];
guint8 num_plmn;
proto_tree* subtree;
curr_offset = offset;
num_plmn = 0;
while ((len - (curr_offset - offset)) >= 3)
{
octs[0] = tvb_get_guint8(tvb, curr_offset);
octs[1] = tvb_get_guint8(tvb, curr_offset + 1);
octs[2] = tvb_get_guint8(tvb, curr_offset + 2);
mcc_mnc_aux(octs, mcc, mnc);
subtree = proto_tree_add_subtree_format(tree, tvb, curr_offset, 3, ett_gsm_a_plmn, NULL, "PLMN[%u]", num_plmn + 1);
proto_tree_add_string(subtree, hf_gsm_a_mobile_country_code, tvb, curr_offset, 3, mcc);
proto_tree_add_string(subtree, hf_gsm_a_mobile_network_code, tvb, curr_offset, 3, mnc);
curr_offset += 3;
num_plmn++;
}
if (add_string)
g_snprintf(add_string, string_len, " - %u PLMN%s",
num_plmn, plurality(num_plmn, "", "s"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_nas_cont_for_ps_ho(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_old_xid, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_type_of_ciph_alg, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_gsm_a_iov_ui, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_ms_net_feat_sup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_gsm_a_ext_periodic_timers, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static void gsm_a_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data, const char *table_title, const value_string *msg_strings)
{
int num_fields = sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item);
stat_tap_table* table;
guint i;
stat_tap_table_item_type items[sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item)];
items[IEI_COLUMN].type = TABLE_ITEM_UINT;
items[MSG_NAME_COLUMN].type = TABLE_ITEM_STRING;
items[COUNT_COLUMN].type = TABLE_ITEM_UINT;
items[COUNT_COLUMN].value.uint_value = 0;
table = new_stat_tap_init_table(table_title, num_fields, 0, NULL, gui_callback, gui_data);
new_stat_tap_add_table(new_stat, table);
for (i = 0; i < 256; i++)
{
const char *msg_str = try_val_to_str(i, msg_strings);
char *col_str;
if (msg_str) {
col_str = g_strdup(msg_str);
} else {
col_str = g_strdup_printf("Unknown message %d", i);
}
items[IEI_COLUMN].value.uint_value = i;
items[MSG_NAME_COLUMN].value.string_value = col_str;
new_stat_tap_init_table_row(table, i, num_fields, items);
}
}
static void gsm_a_bssmap_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F BSSMAP Statistics", gsm_a_bssmap_msg_strings);
}
static void gsm_a_dtap_mm_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F DTAP Mobility Management Statistics", gsm_a_dtap_msg_mm_strings);
}
static void gsm_a_dtap_rr_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F DTAP Radio Resource Management Statistics", gsm_a_dtap_msg_rr_strings);
}
static void gsm_a_dtap_cc_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F DTAP Call Control Statistics", gsm_a_dtap_msg_cc_strings);
}
static void gsm_a_dtap_gmm_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F DTAP GPRS Mobility Management Statistics", gsm_a_dtap_msg_gmm_strings);
}
static void gsm_a_dtap_sm_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F DTAP GPRS Session Management Statistics", gsm_a_dtap_msg_sm_strings);
}
static void gsm_a_dtap_sms_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F DTAP Short Message Service Statistics", gsm_a_dtap_msg_sms_strings);
}
static void gsm_a_dtap_tp_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F DTAP Special Conformance Testing Functions", gsm_a_dtap_msg_tp_strings);
}
static void gsm_a_dtap_ss_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F DTAP Supplementary Services Statistics", gsm_a_dtap_msg_ss_strings);
}
static void gsm_a_sacch_rr_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
gsm_a_stat_init(new_stat, gui_callback, gui_data,
"GSM A-I/F SACCH Statistics", gsm_a_rr_short_pd_msg_strings);
}
static gboolean
gsm_a_stat_packet(void *tapdata, const void *gatr_ptr, guint8 pdu_type, int protocol_disc)
{
new_stat_data_t* stat_data = (new_stat_data_t*)tapdata;
const gsm_a_tap_rec_t *gatr = (const gsm_a_tap_rec_t *) gatr_ptr;
stat_tap_table* table;
stat_tap_table_item_type* msg_data;
guint i = 0;
if (gatr->pdu_type != pdu_type) return FALSE;
if (pdu_type == BSSAP_PDU_TYPE_DTAP && (int)gatr->protocol_disc != protocol_disc) return FALSE;
if (pdu_type == GSM_A_PDU_TYPE_SACCH && gatr->protocol_disc != 0) return FALSE;
table = g_array_index(stat_data->stat_tap_data->tables, stat_tap_table*, i);
msg_data = new_stat_tap_get_field_data(table, gatr->message_type, COUNT_COLUMN);
msg_data->value.uint_value++;
new_stat_tap_set_field_data(table, gatr->message_type, COUNT_COLUMN, msg_data);
return TRUE;
}
static gboolean
gsm_a_bssmap_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_BSSMAP, 0);
}
static gboolean
gsm_a_dtap_mm_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_DTAP, PD_MM);
}
static gboolean
gsm_a_dtap_rr_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_DTAP, PD_RR);
}
static gboolean
gsm_a_dtap_cc_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_DTAP, PD_CC);
}
static gboolean
gsm_a_dtap_gmm_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_DTAP, PD_GMM);
}
static gboolean
gsm_a_dtap_sms_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_DTAP, PD_SMS);
}
static gboolean
gsm_a_dtap_sm_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_DTAP, PD_SM);
}
static gboolean
gsm_a_dtap_ss_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_DTAP, PD_SS);
}
static gboolean
gsm_a_dtap_tp_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, BSSAP_PDU_TYPE_DTAP, PD_TP);
}
static gboolean
gsm_a_sacch_rr_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *gatr_ptr)
{
return gsm_a_stat_packet(tapdata, gatr_ptr, GSM_A_PDU_TYPE_SACCH, 0);
}
static void
gsm_a_stat_reset(stat_tap_table* table)
{
guint element;
stat_tap_table_item_type* item_data;
for (element = 0; element < table->num_elements; element++)
{
item_data = new_stat_tap_get_field_data(table, element, COUNT_COLUMN);
item_data->value.uint_value = 0;
new_stat_tap_set_field_data(table, element, COUNT_COLUMN, item_data);
}
}
static void
gsm_a_stat_free_table_item(stat_tap_table* table _U_, guint row _U_, guint column, stat_tap_table_item_type* field_data)
{
if (column != MSG_NAME_COLUMN) return;
g_free((char*)field_data->value.string_value);
}
void
proto_register_gsm_a_common(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] =
{
{ &hf_gsm_a_common_elem_id,
{ "Element ID", "gsm_a.common.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_common_elem_id_f0,
{ "Element ID", "gsm_a.common.elem_id",
FT_UINT8, BASE_HEX, NULL, 0xF0,
NULL, HFILL }
},
{ &hf_gsm_a_l_ext,
{ "ext", "gsm_a.l_ext",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_tmsi,
{ "TMSI/P-TMSI", "gsm_a.tmsi",
FT_UINT32, BASE_HEX, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_imei,
{ "IMEI", "gsm_a.imei",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_gsm_a_imeisv,
{ "IMEISV", "gsm_a.imeisv",
FT_STRING, BASE_NONE, 0, 0,
NULL, HFILL }
},
{ &hf_gsm_a_MSC_rev,
{ "Revision Level", "gsm_a.MSC_rev",
FT_UINT8, BASE_DEC, VALS(gsm_a_msc_rev_vals), 0x60,
NULL, HFILL }
},
{ &hf_gsm_a_ES_IND,
{ "ES IND", "gsm_a.ES_IND",
FT_BOOLEAN, 8, TFS(&ES_IND_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_A5_1_algorithm_sup,
{ "A5/1 algorithm supported", "gsm_a.A5_1_algorithm_sup",
FT_BOOLEAN, 8, TFS(&A5_1_algorithm_sup_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_RF_power_capability,
{ "RF Power Capability", "gsm_a.RF_power_capability",
FT_UINT8, BASE_DEC, VALS(RF_power_capability_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_ps_sup_cap,
{ "PS capability (pseudo-synchronization capability)", "gsm_a.ps_sup_cap",
FT_BOOLEAN, 8, TFS(&ps_sup_cap_vals), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_SS_screening_indicator,
{ "SS Screening Indicator", "gsm_a.SS_screening_indicator",
FT_UINT8, BASE_DEC, VALS(SS_screening_indicator_vals), 0x30,
NULL, HFILL }
},
{ &hf_gsm_a_SM_capability,
{ "SM capability (MT SMS pt to pt capability)", "gsm_a.SM_cap",
FT_BOOLEAN, 8, TFS(&SM_capability_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_VBS_notification_rec,
{ "VBS notification reception", "gsm_a.VBS_notification_rec",
FT_BOOLEAN, 8, TFS(&VBS_notification_rec_vals), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_VGCS_notification_rec,
{ "VGCS notification reception", "gsm_a.VGCS_notification_rec",
FT_BOOLEAN, 8, TFS(&VGCS_notification_rec_vals), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_FC_frequency_cap,
{ "FC Frequency Capability", "gsm_a.FC_frequency_cap",
FT_BOOLEAN, 8, TFS(&FC_frequency_cap_vals), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_CM3,
{ "CM3", "gsm_a.CM3",
FT_BOOLEAN, 8, TFS(&CM3_vals), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_LCS_VA_cap,
{ "LCS VA capability (LCS value added location request notification capability)", "gsm_a.LCS_VA_cap",
FT_BOOLEAN, 8, TFS(&LCS_VA_cap_vals), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_UCS2_treatment,
{ "UCS2 treatment", "gsm_a.UCS2_treatment",
FT_BOOLEAN, 8, TFS(&UCS2_treatment_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_SoLSA,
{ "SoLSA", "gsm_a.SoLSA",
FT_BOOLEAN, 8, TFS(&SoLSA_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_CMSP,
{ "CMSP: CM Service Prompt", "gsm_a.CMSP",
FT_BOOLEAN, 8, TFS(&CMSP_vals), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_A5_7_algorithm_sup,
{ "A5/7 algorithm supported", "gsm_a.A5_7_algorithm_sup",
FT_BOOLEAN, BASE_NONE, TFS(&A5_7_algorithm_sup_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_A5_6_algorithm_sup,
{ "A5/6 algorithm supported", "gsm_a.A5_6_algorithm_sup",
FT_BOOLEAN, BASE_NONE, TFS(&A5_6_algorithm_sup_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_A5_5_algorithm_sup,
{ "A5/5 algorithm supported", "gsm_a.A5_5_algorithm_sup",
FT_BOOLEAN, BASE_NONE, TFS(&A5_5_algorithm_sup_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_A5_4_algorithm_sup,
{ "A5/4 algorithm supported", "gsm_a.A5_4_algorithm_sup",
FT_BOOLEAN, BASE_NONE, TFS(&A5_4_algorithm_sup_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_A5_3_algorithm_sup,
{ "A5/3 algorithm supported", "gsm_a.A5_3_algorithm_sup",
FT_BOOLEAN, 8, TFS(&A5_3_algorithm_sup_vals), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_A5_2_algorithm_sup,
{ "A5/2 algorithm supported", "gsm_a.A5_2_algorithm_sup",
FT_BOOLEAN, 8, TFS(&A5_2_algorithm_sup_vals), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_mobile_identity_type,
{ "Mobile Identity Type", "gsm_a.ie.mobileid.type",
FT_UINT8, BASE_DEC, VALS(mobile_identity_type_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_id_dig_1,
{ "Identity Digit 1", "gsm_a.id_dig_1",
FT_UINT8, BASE_DEC, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_odd_even_ind,
{ "Odd/even indication", "gsm_a.oddevenind",
FT_BOOLEAN, 8, TFS(&oddevenind_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_unused,
{ "Unused", "gsm_a.unused",
FT_UINT8, BASE_HEX, NULL, 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_tmgi_mcc_mnc_ind,
{ "MCC/MNC indication", "gsm_a.tmgi_mcc_mnc_ind",
FT_BOOLEAN, 8, TFS(&gsm_a_present_vals), 0x10,
NULL, HFILL}
},
{ &hf_gsm_a_mbs_ses_id_ind,
{ "MBMS Session Identity indication", "gsm_a.mbs_session_id_ind",
FT_BOOLEAN, 8, TFS(&gsm_a_present_vals), 0x20,
NULL, HFILL}
},
{ &hf_gsm_a_mbs_service_id,
{ "MBMS Service ID", "gsm_a.mbs_service_id",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_mbs_session_id,
{ "MBMS Session ID", "gsm_a.mbs_session_id",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_length,
{ "Length", "gsm_a.len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_element_value,
{ "Element Value", "gsm_a.element_value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_extension,
{ "Extension", "gsm_a.extension",
FT_BOOLEAN, 8, TFS(&gsm_a_extension_value), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_L3_protocol_discriminator,
{ "Protocol discriminator", "gsm_a.L3_protocol_discriminator",
FT_UINT8, BASE_HEX, VALS(protocol_discriminator_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_call_prio,
{ "Call priority", "gsm_a.call_prio",
FT_UINT8, BASE_DEC, VALS(gsm_a_call_prio_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_type_of_ciph_alg,
{ "Call priority", "gsm_a.call_prio",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_type_of_ciph_alg_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_att,
{ "ATT", "gsm_a.att",
FT_BOOLEAN, 8, TFS(&gsm_a_att_value), 0x01,
"ttach-detach allowed", HFILL }
},
{ &hf_gsm_a_nmo_1,
{ "NMO I", "gsm_a.nmo_1",
FT_BOOLEAN, 8, TFS(&gsm_a_nmo_1_value), 0x02,
"Network Mode of Operation I", HFILL }
},
{ &hf_gsm_a_nmo,
{ "NMO", "gsm_a.nmo",
FT_BOOLEAN, 8, TFS(&gsm_a_nmo_value), 0x01,
"Network Mode of Operation", HFILL }
},
{ &hf_gsm_a_old_xid,
{ "Old XID", "gsm_a.old_xid",
FT_UINT8, BASE_DEC, VALS(gsm_a_pld_xid_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_iov_ui,
{ "IOV-UI", "gsm_a.iov_ui",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_ext_periodic_timers,
{ "Extended periodic timers", "gsm_a.ext_periodic_timers",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_ext_periodic_timers_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_skip_ind,
{ "Skip Indicator", "gsm_a.skip.ind",
FT_UINT8, BASE_DEC, VALS(gsm_a_skip_ind_vals), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_b7spare,
{ "Spare", "gsm_a.spareb7",
FT_UINT8, BASE_DEC, NULL, 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_b8spare,
{ "Spare", "gsm_a.spareb8",
FT_UINT8, BASE_DEC, NULL, 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_spare_bits,
{ "Spare bit(s)", "gsm_a.spare_bits",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_multi_bnd_sup_fields,
{ "Multiband supported field", "gsm_a.multi_bnd_sup_fields",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_pgsm_supported,
{ "P-GSM Supported", "gsm_a.classmark3.pgsmSupported",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_egsm_supported,
{ "E-GSM or R-GSM Supported", "gsm_a.classmark3.egsmSupported",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_gsm1800_supported,
{ "GSM 1800 Supported", "gsm_a.classmark3.gsm1800Supported",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ass_radio_cap1,
{ "Associated Radio Capability 1", "gsm_a.classmark3.ass_radio_cap1",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ass_radio_cap2,
{ "Associated Radio Capability 2", "gsm_a.classmark3.ass_radio_cap2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_cm3_A5_bits,
{ "A5 bits", "gsm_a.classmark3.a5_bits",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_rsupport,
{ "R Support", "gsm_a.classmark3.rsupport",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_r_capabilities,
{ "R-GSM band Associated Radio Capability", "gsm_a.classmark3.r_capabilities",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_multislot_capabilities,
{ "HSCSD Multi Slot Capability", "gsm_a.classmark3.multislot_capabilities",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_multislot_class,
{ "HSCSD Multi Slot Class", "gsm_a.classmark3.multislot_cap",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ucs2_treatment,
{ "UCS2 treatment", "gsm_a.UCS2_treatment",
FT_BOOLEAN, BASE_NONE, TFS(&UCS2_treatment_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_extended_measurement_cap,
{ "Extended Measurement Capability", "gsm_a.classmark3.ext_meas_cap",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ms_measurement_capability,
{ "MS measurement capability", "gsm_a.classmark3.ms_measurement_capability",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_sms_value,
{ "SMS_VALUE (Switch-Measure-Switch)", "gsm_a.classmark3.sms_value",
FT_UINT8, BASE_DEC, VALS(gsm_a_sms_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_sm_value,
{ "SM_VALUE (Switch-Measure)", "gsm_a.classmark3.sm_value",
FT_UINT8, BASE_DEC, VALS(gsm_a_sms_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ms_pos_method_cap_present,
{ "MS Positioning Method Capability present", "gsm_a.classmark3.ms_pos_method_cap_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ms_pos_method,
{ "MS Positioning Method", "gsm_a.classmark3.ms_pos_method",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ms_assisted_e_otd,
{ "MS assisted E-OTD", "gsm_a.classmark3.ms_assisted_e_otd",
FT_BOOLEAN, BASE_NONE, TFS(&ms_assisted_e_otd_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ms_based_e_otd,
{ "MS based E-OTD", "gsm_a.classmark3.ms_based_e_otd",
FT_BOOLEAN, BASE_NONE, TFS(&ms_based_e_otd_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ms_assisted_gps,
{ "MS assisted GPS", "gsm_a.classmark3.ms_assisted_gps",
FT_BOOLEAN, BASE_NONE, TFS(&ms_assisted_gps_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ms_based_gps,
{ "MS based GPS", "gsm_a.classmark3.ms_based_gps",
FT_BOOLEAN, BASE_NONE, TFS(&ms_based_gps_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ms_conventional_gps,
{ "MS Conventional GPS", "gsm_a.classmark3.ms_conventional_gps",
FT_BOOLEAN, BASE_NONE, TFS(&ms_conventional_gps_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_ecsd_multi_slot_capability,
{ "ECSD Multi Slot Capability present", "gsm_a.classmark3.ecsd_multi_slot_capability",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ecsd_multi_slot_class,
{ "ECSD Multi Slot Class", "gsm_a.classmark3.ecsd_multi_slot_class",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_8_psk_struct_present,
{ "8-PSK Struct present", "gsm_a.classmark3.8_psk_struct_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_8_psk_struct,
{ "8-PSK Struct", "gsm_a.classmark3.8_psk_struct",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_modulation_capability,
{ "Modulation Capability", "gsm_a.classmark3.modulation_capability",
FT_BOOLEAN, BASE_NONE, TFS(&modulation_capability_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_8_psk_rf_power_capability_1_present,
{ "8-PSK RF Power Capability 1 present", "gsm_a.classmark3.8_psk_rf_power_capability_1_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_8_psk_rf_power_capability_1,
{ "8-PSK RF Power Capability 1", "gsm_a.classmark3.8_psk_rf_power_capability_1",
FT_UINT8, BASE_HEX, VALS(eight_psk_rf_power_capability_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_8_psk_rf_power_capability_2_present,
{ "8-PSK RF Power Capability 2 present", "gsm_a.classmark3.8_psk_rf_power_capability_2_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_8_psk_rf_power_capability_2,
{ "8-PSK RF Power Capability 2", "gsm_a.classmark3.8_psk_rf_power_capability_2",
FT_UINT8, BASE_HEX, VALS(eight_psk_rf_power_capability_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_400_band_info_present,
{ "GSM 400 Band Information present", "gsm_a.classmark3.gsm_400_band_info_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_400_bands_supported,
{ "GSM 400 Bands Supported", "gsm_a.classmark3.gsm_400_bands_supported",
FT_UINT8, BASE_HEX, VALS(gsm_400_bands_supported_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_400_assoc_radio_cap,
{ "GSM 400 Associated Radio Capability", "gsm_a.classmark3.gsm_400_assoc_radio_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_850_assoc_radio_cap_present,
{ "GSM 850 Associated Radio Capability present", "gsm_a.classmark3.gsm_850_assoc_radio_cap_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_850_assoc_radio_cap,
{ "GSM 850 Associated Radio Capability", "gsm_a.classmark3.gsm_850_assoc_radio_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_1900_assoc_radio_cap_present,
{ "GSM 1900 Associated Radio Capability present", "gsm_a.classmark3.gsm_1900_assoc_radio_cap_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_1900_assoc_radio_cap,
{ "GSM 1900 Associated Radio Capability", "gsm_a.classmark3.gsm_1900_assoc_radio_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_umts_fdd_rat_cap,
{ "UMTS FDD Radio Access Technology Capability", "gsm_a.classmark3.umts_fdd_rat_cap",
FT_BOOLEAN, BASE_NONE, TFS(&umts_fdd_rat_cap_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_umts_384_mcps_tdd_rat_cap,
{ "UMTS 3.84 Mcps TDD Radio Access Technology Capability", "gsm_a.classmark3.umts_384_mcps_tdd_rat_cap",
FT_BOOLEAN, BASE_NONE, TFS(&umts_384_mcps_tdd_rat_cap_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_cdma_2000_rat_cap,
{ "CDMA 2000 Radio Access Technology Capability", "gsm_a.classmark3.cdma_2000_rat_cap",
FT_BOOLEAN, BASE_NONE, TFS(&cdma_2000_rat_cap_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_e_gprs_multi_slot_info_present,
{ "DTM E/GPRS Multi Slot Information present", "gsm_a.classmark3.dtm_e_gprs_multi_slot_info_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_gprs_multi_slot_class,
{ "DTM GPRS Multi Slot Class", "gsm_a.classmark3.dtm_gprs_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(dtm_gprs_multi_slot_class_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_single_slot_dtm,
{ "Single Slot DTM", "gsm_a.classmark3.single_slot_dtm_supported",
FT_BOOLEAN, BASE_NONE, TFS(&single_slot_dtm_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_egprs_multi_slot_class_present,
{ "DTM EGPRS Multi Slot Class present", "gsm_a.classmark3.dtm_egprs_multi_slot_class_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_egprs_multi_slot_class,
{ "DTM EGPRS Multi Slot Class", "gsm_a.classmark3.dtm_egprs_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(dtm_gprs_multi_slot_class_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_single_band_support,
{ "Single Band Support", "gsm_a.classmark3.single_band_support",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_band,
{ "GSM Band", "gsm_a.classmark3.gsm_band",
FT_UINT8, BASE_DEC, VALS(gsm_band_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_750_assoc_radio_cap_present,
{ "GSM 750 Associated Radio Capability present", "gsm_a.classmark3.gsm_750_assoc_radio_cap_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_750_assoc_radio_cap,
{ "GSM 750 Associated Radio Capability", "gsm_a.classmark3.gsm_750_assoc_radio_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_umts_128_mcps_tdd_rat_cap,
{ "UMTS 1.28 Mcps TDD Radio Access Technology Capability", "gsm_a.classmark3.umts_128_mcps_tdd_rat_cap",
FT_BOOLEAN, BASE_NONE, TFS(&umts_128_mcps_tdd_rat_cap_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_geran_feature_package_1,
{ "GERAN Feature Package 1", "gsm_a.classmark3.geran_feature_package_1",
FT_BOOLEAN, BASE_NONE, TFS(&geran_feature_package_1_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ext_dtm_e_gprs_multi_slot_info_present,
{ "Extended DTM E/GPRS Multi Slot Information present", "gsm_a.classmark3.ext_dtm_e_gprs_info_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ext_dtm_gprs_multi_slot_class,
{ "Extended DTM GPRS Multi Slot Class", "gsm_a.classmark3.ext_dtm_gprs_multi_slot_class",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ext_dtm_egprs_multi_slot_class,
{ "Extended DTM EGPRS Multi Slot Class", "gsm_a.classmark3.ext_dtm_egprs_multi_slot_class",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_high_multislot_cap_present,
{ "High Multislot Capability present", "gsm_a.classmark3.high_multislot_cap_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_high_multislot_cap,
{ "High Multislot Capability", "gsm_a.classmark3.high_multislot_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_geran_iu_mode_support,
{ "GERAN Iu Mode Support", "gsm_a.classmark3.geran_iu_mode_support",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_geran_iu_mode_cap,
{ "GERAN Iu Mode Capabilities", "gsm_a.classmark3.geran_iu_mode_cap",
FT_UINT24, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_geran_iu_mode_cap_length,
{ "Length", "gsm_a.classmark3.geran_iu_mode_cap.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_flo_iu_cap,
{ "FLO Iu Capability", "gsm_a.classmark3.geran_iu_mode_cap.flo_iu_cap",
FT_BOOLEAN, BASE_NONE, TFS(&flo_iu_cap_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_geran_feature_package_2,
{ "GERAN Feature Package 2", "gsm_a.classmark3.geran_feature_package_2",
FT_BOOLEAN, BASE_NONE, TFS(&geran_feature_package_2_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gmsk_multislot_power_prof,
{ "GMSK Multislot Power Profile", "gsm_a.classmark3.gmsk_multislot_power_prof",
FT_UINT8, BASE_DEC, VALS(gmsk_multislot_power_prof_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_8_psk_multislot_power_prof,
{ "8-PSK Multislot Power Profile", "gsm_a.classmark3.8_psk_multislot_power_prof",
FT_UINT8, BASE_DEC, VALS(eight_psk_multislot_power_prof_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_t_gsm_400_band_info_present,
{ "T-GSM 400 Band Information present", "gsm_a.classmark3.gsm_400_band_info_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_t_gsm_400_bands_supported,
{ "T-GSM 400 Bands Supported", "gsm_a.classmark3.t_gsm_400_bands_supported",
FT_UINT8, BASE_HEX, VALS(t_gsm_400_bands_supported_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_t_gsm_400_assoc_radio_cap,
{ "T-GSM 400 Associated Radio Capability", "gsm_a.classmark3.t_gsm_400_assoc_radio_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_t_gsm_900_assoc_radio_cap_present,
{ "T-GSM 900 Associated Radio Capability present", "gsm_a.classmark3.t_gsm_900_assoc_radio_cap_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_t_gsm_900_assoc_radio_cap,
{ "T-GSM 900 Associated Radio Capability", "gsm_a.classmark3.t_gsm_900_assoc_radio_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_downlink_adv_receiver_perf,
{ "Downlink Advanced Receiver Performance", "gsm_a.classmark3.downlink_adv_receiver_perf",
FT_UINT8, BASE_DEC, VALS(downlink_adv_receiver_perf_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_enhancements_cap,
{ "DTM Enhancements Capability", "gsm_a.classmark3.dtm_enhancements_capability",
FT_BOOLEAN, BASE_NONE, TFS(&dtm_enhancements_cap_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_e_gprs_high_multi_slot_info_present,
{ "DTM E/GPRS High Multi Slot Information present", "gsm_a.classmark3.dtm_e_gprs_high_mutli_slot_info_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_gprs_high_multi_slot_class,
{ "DTM GPRS Multi Slot Class", "gsm_a.classmark3.dtm_gprs_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(dtm_gprs_high_multi_slot_class_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_offset_required,
{ "Offset required", "gsm_a.classmark3.offset_required",
FT_BOOLEAN, BASE_NONE, TFS(&offset_required_vals), 0x0,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_egprs_high_multi_slot_class_present,
{ "DTM EGPRS High Multi Slot Class present", "gsm_a.classmark3.dtm_egprs_high_multi_slot_class_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_dtm_egprs_high_multi_slot_class,
{ "DTM EGPRS High Multi Slot Class", "gsm_a.classmark3.dtm_egprs_high_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(dtm_gprs_high_multi_slot_class_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_repeated_acch_cap,
{ "Repeated ACCH Capability", "gsm_a.classmark3.repeated_acch_cap",
FT_BOOLEAN, BASE_NONE, TFS(&repeated_acch_cap_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_710_assoc_radio_cap_present,
{ "GSM 710 Associated Radio Capability present", "gsm_a.classmark3.gsm_710_assoc_radio_cap_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_gsm_710_assoc_radio_cap,
{ "GSM 710 Associated Radio Capability", "gsm_a.classmark3.gsm_710_assoc_radio_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_t_gsm_810_assoc_radio_cap_present,
{ "T-GSM 810 Associated Radio Capability present", "gsm_a.classmark3.t_gsm_810_assoc_radio_cap_present",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_t_gsm_810_assoc_radio_cap,
{ "T-GSM 810 Associated Radio Capability", "gsm_a.classmark3.t_gsm_810_assoc_radio_cap",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ciphering_mode_setting_cap,
{ "Ciphering Mode Setting Capability", "gsm_a.classmark3.ciphering_mode_setting_cap",
FT_BOOLEAN, BASE_NONE, TFS(&ciphering_mode_setting_cap_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_additional_positioning_caps,
{ "Additional Positioning Capabilities", "gsm_a.classmark3.additional_positioning_caps",
FT_BOOLEAN, BASE_NONE, TFS(&additional_positioning_caps_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_e_utra_fdd_support,
{ "E-UTRA FDD support", "gsm_a.classmark3.e_utra_fdd_support",
FT_BOOLEAN, BASE_NONE, TFS(&e_utra_fdd_support_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_e_utra_tdd_support,
{ "E-UTRA TDD support", "gsm_a.classmark3.e_utra_tdd_support",
FT_BOOLEAN, BASE_NONE, TFS(&e_utra_tdd_support_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_e_utra_meas_and_report_support,
{ "E-UTRA Measurement and Reporting support", "gsm_a.classmark3.e_utra_meas_and_report_support",
FT_BOOLEAN, BASE_NONE, TFS(&e_utra_meas_and_report_support_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_prio_based_resel_support,
{ "Priority-based reselection support", "gsm_a.classmark3.prio_based_resel_support",
FT_BOOLEAN, BASE_NONE, TFS(&prio_based_resel_support_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_utra_csg_cells_reporting,
{ "UTRA CSG Cells Reporting", "gsm_a.classmark3.utra_csg_cells_reporting",
FT_BOOLEAN, BASE_NONE, TFS(&utra_csg_cells_reporting_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_vamos_level,
{ "VAMOS Level", "gsm_a.classmark3.vamos_level",
FT_UINT8, BASE_DEC, VALS(vamos_level_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_tighter_cap,
{ "TIGHTER Capability", "gsm_a.classmark3.tighter_cap",
FT_UINT8, BASE_DEC, VALS(tighter_cap_level_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_selective_ciph_down_sacch,
{ "Selective Ciphering of Downlink SACCH", "gsm_a.classmark3.selective_ciph_down_sacch",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_cs_to_ps_srvcc_geran_to_utra,
{ "CS to PS SRVCC from GERAN to UTRA", "gsm_a.classmark3.cs_to_ps_srvcc_geran_to_utra",
FT_UINT8, BASE_DEC, VALS(cs_to_ps_srvcc_geran_to_utra_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_cs_to_ps_srvcc_geran_to_eutra,
{ "CS to PS SRVCC from GERAN to E-UTRA", "gsm_a.classmark3.cs_to_ps_srvcc_geran_to_eutra",
FT_UINT8, BASE_DEC, VALS(cs_to_ps_srvcc_geran_to_eutra_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_geran_network_sharing_support,
{ "GERAN Network Sharing support", "gsm_a.classmark3.geran_network_sharing_support",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_eutra_wb_rsrq_support,
{ "E-UTRA Wideband RSRQ measurements support", "gsm_a.classmark3.eutra_wb_rsrq_support",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_er_band_support,
{ "ER Band support", "gsm_a.classmark3.er_band_support",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_utra_mfbi_support,
{ "UTRA Multiple Frequency Band Indicators support", "gsm_a.classmark3.utra_mfbi_support",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_eutra_mfbi_support,
{ "E-UTRA Multiple Frequency Band Indicators support", "gsm_a.classmark3.eutra_mfbi_support",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ext_tsc_set_cap_support,
{ "Extended TSC Set Capability support", "gsm_a.classmark3.ext_tsc_set_cap_support",
FT_BOOLEAN, BASE_NONE, TFS(&true_false_vals), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_ext_earfcn_value_range,
{ "Extended EARFCN value range", "gsm_a.classmark3.ext_earfcn_value_range",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x00,
NULL, HFILL}
},
{ &hf_gsm_a_geo_loc_type_of_shape,
{ "Location estimate", "gsm_a.gad.location_estimate",
FT_UINT8, BASE_DEC, VALS(type_of_shape_vals), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_sign_of_lat,
{ "Sign of latitude", "gsm_a.gad.sign_of_latitude",
FT_UINT8, BASE_DEC, VALS(sign_of_latitude_vals), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_deg_of_lat,
{ "Degrees of latitude", "gsm_a.gad.deg_of_latitude",
FT_UINT24, BASE_DEC, NULL, 0x7fffff,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_deg_of_long,
{ "Degrees of longitude", "gsm_a.gad.deg_of_longitude",
FT_INT24, BASE_DEC, NULL, 0xffffff,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_uncertainty_code,
{ "Uncertainty code", "gsm_a.gad.uncertainty_code",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_uncertainty_semi_major,
{ "Uncertainty semi-major", "gsm_a.gad.uncertainty_semi_major",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_uncertainty_semi_minor,
{ "Uncertainty semi-minor", "gsm_a.gad.uncertainty_semi_minor",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_orientation_of_major_axis,
{ "Orientation of major axis", "gsm_a.gad.orientation_of_major_axis",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_uncertainty_altitude,
{ "Uncertainty Altitude", "gsm_a.gad.uncertainty_altitude",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_confidence,
{ "Confidence(%)", "gsm_a.gad.confidence",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_no_of_points,
{ "Number of points", "gsm_a.gad.no_of_points",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_velocity_type,
{ "Number of points", "gsm_a.gad.velocity_type",
FT_UINT8, BASE_DEC, VALS(gsm_a_velocity_type_vals), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_bearing,
{ "Bearing", "gsm_a.gad.bearing",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_horizontal_speed,
{ "Horizontal Speed", "gsm_a.gad.horizontal_velocity",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_vertical_speed,
{ "Vertical Speed", "gsm_a.gad.vertical_speed",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_uncertainty_speed,
{ "Uncertainty Speed", "gsm_a.gad.uncertainty_speed",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_h_uncertainty_speed,
{ "Horizontal Uncertainty Speed", "gsm_a.gad.v_uncertainty_speed",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_v_uncertainty_speed,
{ "Vertical Uncertainty Speed", "gsm_a.gad.h_uncertainty_speed",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_d,
{ "Direction of Vertical Speed", "gsm_a.gad.d",
FT_BOOLEAN, 8, TFS(&gsm_a_dir_of_ver_speed_vals), 0x08,
NULL, HFILL}
},
{ &hf_gsm_a_geo_loc_D,
{ "D: Direction of Altitude", "gsm_a.gad.D",
FT_UINT16, BASE_DEC, VALS(dir_of_alt_vals), 0x8000,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_altitude,
{ "Altitude in meters", "gsm_a.gad.altitude",
FT_UINT16, BASE_DEC, NULL, 0x7fff,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_inner_radius,
{ "Inner radius", "gsm_a.gad.altitude",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_uncertainty_radius,
{ "Uncertainty radius", "gsm_a.gad.no_of_points",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_offset_angle,
{ "Offset angle", "gsm_a.gad.offset_angle",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_geo_loc_included_angle,
{ "Included angle", "gsm_a.gad.included_angle",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_key_seq,
{ "key sequence", "gsm_a.key_seq",
FT_UINT8, BASE_DEC, VALS(gsm_a_key_seq_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_lac,
{ "Location Area Code (LAC)", "gsm_a.lac",
FT_UINT16, BASE_HEX_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_spare_nibble,
{ "Spare Nibble", "gsm_a.spare",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_filler, { "Filler", "gsm_a.filler", FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL }},
{ &hf_gsm_a_identity_digit1, { "Identity Digit 1", "gsm_a.identity_digit1", FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL }},
{ &hf_gsm_a_group_call_reference, { "Group or Broadcast call reference", "gsm_a.group_call_reference", FT_UINT32, BASE_DEC_HEX, NULL, 0xffffffe0, NULL, HFILL }},
{ &hf_gsm_a_service_flag, { "SF Service Flag", "gsm_a.service_flag", FT_BOOLEAN, 32, TFS(&tfs_vgcs_vbs), 0x00000010, NULL, HFILL }},
{ &hf_gsm_a_af_acknowledgement, { "AF Acknowledgement", "gsm_a.af_acknowledgement", FT_BOOLEAN, 32, TFS(&tfs_required_not_required), 0x00000008, NULL, HFILL }},
{ &hf_gsm_a_call_priority, { "Call Priority", "gsm_a.call_priority", FT_UINT32, BASE_DEC, VALS(gsm_a_call_priority_vals), 0x00000007, NULL, HFILL }},
{ &hf_gsm_a_ciphering_info, { "Ciphering Information", "gsm_a.ciphering_info", FT_UINT8, BASE_HEX, NULL, 0xf0, NULL, HFILL }},
{ &hf_gsm_a_sapi, { "SAPI (Service Access Point Identifier)", "gsm_a.sapi", FT_UINT8, BASE_DEC, VALS(gsm_a_sapi_vals), 0x30, NULL, HFILL }},
{ &hf_gsm_a_mobile_country_code, { "Mobile Country Code (MCC)", "gsm_a.mobile_country_code", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_mobile_network_code, { "Mobile Network Code (MNC)", "gsm_a.mobile_network_code", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
};
#define NUM_INDIVIDUAL_ELEMS 1
static gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_GSM_COMMON_ELEM];
static ei_register_info ei[] = {
{ &ei_gsm_a_extraneous_data, { "gsm_a.extraneous_data", PI_PROTOCOL, PI_NOTE, "Extraneous Data, dissector bug or later version spec(report to wireshark.org)", EXPFILL }},
{ &ei_gsm_a_unknown_element, { "gsm_a.unknown_element", PI_PROTOCOL, PI_ERROR, "Unknown - aborting dissection", EXPFILL }},
{ &ei_gsm_a_unknown_pdu_type, { "gsm_a.unknown_pdu_type", PI_PROTOCOL, PI_WARN, "Unknown PDU type", EXPFILL }},
{ &ei_gsm_a_no_element_dissector, { "gsm_a.no_element_dissector", PI_PROTOCOL, PI_WARN, "No element dissector, rest of dissection may be incorrect", EXPFILL }},
{ &ei_gsm_a_format_not_supported, { "gsm_a.format_not_supported", PI_PROTOCOL, PI_WARN, "Format not supported", EXPFILL }},
{ &ei_gsm_a_mobile_identity_type, { "gsm_a.ie.mobileid.type.unknown", PI_PROTOCOL, PI_WARN, "Format unknown", EXPFILL }},
};
expert_module_t* expert_a_common;
static tap_param gsm_a_stat_params[] = {
{ PARAM_FILTER, "filter", "Filter", NULL, TRUE }
};
static stat_tap_table_ui gsm_a_bssmap_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface BSSMAP",
"gsm_a",
"gsm_a,bssmap",
gsm_a_bssmap_stat_init,
gsm_a_bssmap_stat_packet,
gsm_a_stat_reset,
gsm_a_stat_free_table_item,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_dtap_mm_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface DTAP Mobility Management",
"gsm_a",
"gsm_a,dtap_mm",
gsm_a_dtap_mm_stat_init,
gsm_a_dtap_mm_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_dtap_rr_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface DTAP Radio Resource Management",
"gsm_a",
"gsm_a,dtap_rr",
gsm_a_dtap_rr_stat_init,
gsm_a_dtap_rr_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_dtap_cc_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface DTAP Call Control",
"gsm_a",
"gsm_a,dtap_cc",
gsm_a_dtap_cc_stat_init,
gsm_a_dtap_cc_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_dtap_gmm_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface DTAP GPRS Mobility Management",
"gsm_a",
"gsm_a,dtap_gmm",
gsm_a_dtap_gmm_stat_init,
gsm_a_dtap_gmm_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_dtap_sm_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface DTAP GPRS Session Management",
"gsm_a",
"gsm_a,dtap_sm",
gsm_a_dtap_sm_stat_init,
gsm_a_dtap_sm_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_dtap_sms_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface DTAP Short Message Service",
"gsm_a",
"gsm_a,dtap_sms",
gsm_a_dtap_sms_stat_init,
gsm_a_dtap_sms_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_dtap_tp_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface DTAP Special Conformance Testing Functions",
"gsm_a",
"gsm_a,dtap_tp",
gsm_a_dtap_tp_stat_init,
gsm_a_dtap_tp_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_dtap_ss_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface DTAP Supplementary Services",
"gsm_a",
"gsm_a,dtap_ss",
gsm_a_dtap_ss_stat_init,
gsm_a_dtap_ss_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
static stat_tap_table_ui gsm_a_sacch_rr_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY_GSM,
"A-Interface SACCH",
"gsm_a",
"gsm_a,dtap_sacch",
gsm_a_sacch_rr_stat_init,
gsm_a_sacch_rr_stat_packet,
gsm_a_stat_reset,
NULL,
NULL,
sizeof(gsm_a_stat_fields)/sizeof(stat_tap_table_item), gsm_a_stat_fields,
sizeof(gsm_a_stat_params)/sizeof(tap_param), gsm_a_stat_params,
NULL
};
last_offset = NUM_INDIVIDUAL_ELEMS;
ett[0] = &ett_gsm_a_plmn;
for (i=0; i < NUM_GSM_COMMON_ELEM; i++, last_offset++)
{
ett_gsm_common_elem[i] = -1;
ett[last_offset] = &ett_gsm_common_elem[i];
}
proto_a_common =
proto_register_protocol("GSM A-I/F COMMON", "GSM COMMON", "gsm_a");
proto_register_field_array(proto_a_common, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_a_common = expert_register_protocol(proto_a_common);
expert_register_field_array(expert_a_common, ei, array_length(ei));
gsm_a_tap = register_tap("gsm_a");
register_stat_tap_table_ui(&gsm_a_bssmap_stat_table);
register_stat_tap_table_ui(&gsm_a_dtap_mm_stat_table);
register_stat_tap_table_ui(&gsm_a_dtap_rr_stat_table);
register_stat_tap_table_ui(&gsm_a_dtap_cc_stat_table);
register_stat_tap_table_ui(&gsm_a_dtap_gmm_stat_table);
register_stat_tap_table_ui(&gsm_a_dtap_sms_stat_table);
register_stat_tap_table_ui(&gsm_a_dtap_sm_stat_table);
register_stat_tap_table_ui(&gsm_a_dtap_ss_stat_table);
register_stat_tap_table_ui(&gsm_a_dtap_tp_stat_table);
register_stat_tap_table_ui(&gsm_a_sacch_rr_stat_table);
}
