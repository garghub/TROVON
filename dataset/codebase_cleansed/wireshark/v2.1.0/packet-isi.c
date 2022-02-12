static int dissect_isi_sim_auth(tvbuff_t *tvb, packet_info *pinfo, proto_item *isitree, void* data _U_) {
proto_item *item;
proto_tree *tree;
guint8 cmd, code;
item = proto_tree_add_item(isitree, hf_isi_sim_auth_payload, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_isi_msg);
proto_tree_add_item(tree, hf_isi_sim_auth_cmd, tvb, 0, 1, ENC_BIG_ENDIAN);
cmd = tvb_get_guint8(tvb, 0);
switch(cmd) {
case 0x01:
proto_tree_add_item(tree, hf_isi_sim_auth_protection_req, tvb, 2, 1, ENC_BIG_ENDIAN);
cmd = tvb_get_guint8(tvb, 2);
switch(cmd) {
case 0x00:
proto_tree_add_item(tree, hf_isi_sim_auth_pin, tvb, 3, -1, ENC_ASCII|ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "disable SIM startup protection");
break;
case 0x01:
proto_tree_add_item(tree, hf_isi_sim_auth_pin, tvb, 3, -1, ENC_ASCII|ENC_NA);
col_set_str(pinfo->cinfo, COL_INFO, "enable SIM startup protection");
break;
case 0x04:
col_set_str(pinfo->cinfo, COL_INFO, "get SIM startup protection status");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "unknown SIM startup protection packet");
break;
}
break;
case 0x02:
proto_tree_add_item(tree, hf_isi_sim_auth_protection_rsp, tvb, 1, 1, ENC_BIG_ENDIAN);
if(tvb_get_guint8(tvb, 1))
col_set_str(pinfo->cinfo, COL_INFO, "SIM startup protection enabled");
else
col_set_str(pinfo->cinfo, COL_INFO, "SIM startup protection disabled");
break;
case 0x04:
proto_tree_add_item(tree, hf_isi_sim_auth_pw_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x02:
col_set_str(pinfo->cinfo, COL_INFO, "update SIM PIN");
proto_tree_add_item(tree, hf_isi_sim_auth_pin, tvb, 2, 11, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_isi_sim_auth_new_pin, tvb, 13, 11, ENC_ASCII|ENC_NA);
break;
case 0x03:
col_set_str(pinfo->cinfo, COL_INFO, "update SIM PUK");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "unknown SIM Authentication update request");
break;
}
break;
case 0x05:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication update successful");
break;
case 0x06:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication update failed");
break;
case 0x07:
proto_tree_add_item(tree, hf_isi_sim_auth_pw_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x02:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication with PIN");
proto_tree_add_item(tree, hf_isi_sim_auth_pin, tvb, 2, 11, ENC_ASCII|ENC_NA);
break;
case 0x03:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication with PUK");
proto_tree_add_item(tree, hf_isi_sim_auth_puk, tvb, 2, 11, ENC_ASCII|ENC_NA);
proto_tree_add_item(tree, hf_isi_sim_auth_new_pin, tvb, 13, 11, ENC_ASCII|ENC_NA);
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "unknown SIM Authentication request");
break;
}
break;
case 0x08:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication successful");
break;
case 0x09:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication failed");
break;
case 0x10:
proto_tree_add_item(tree, hf_isi_sim_auth_indication, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
proto_tree_add_item(tree, hf_isi_sim_auth_pw_type, tvb, 2, 1, ENC_BIG_ENDIAN);
switch(code) {
case 0x01:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication indication: Authentication needed");
break;
case 0x02:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication indication: No Authentication needed");
break;
case 0x03:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication indication: Authentication valid");
break;
case 0x04:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication indication: Authentication invalid");
break;
case 0x05:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication indication: Authorized");
break;
case 0x06:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication indication: Config");
proto_tree_add_item(tree, hf_isi_sim_auth_indication_cfg, tvb, 3, 1, ENC_BIG_ENDIAN);
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "unknown SIM Authentication indication");
break;
}
break;
case 0x11:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication status request");
break;
case 0x12:
proto_tree_add_item(tree, hf_isi_sim_auth_status_rsp, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x02:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication status: need PIN");
break;
case 0x03:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication status: need PUK");
break;
case 0x05:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication status: running");
break;
case 0x07:
col_set_str(pinfo->cinfo, COL_INFO, "SIM Authentication status: initializing");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "unknown SIM Authentication status response packet");
break;
}
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "unknown SIM Authentication packet");
break;
}
return tvb_captured_length(tvb);
}
static int dissect_isi_sim(tvbuff_t *tvb, packet_info *pinfo, proto_item *isitree, void* data _U_) {
proto_item *item;
proto_tree *tree;
guint8 cmd, code;
item = proto_tree_add_item(isitree, hf_isi_sim_payload, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_isi_msg);
proto_tree_add_item(tree, hf_isi_sim_message_id, tvb, 0, 1, ENC_BIG_ENDIAN);
cmd = tvb_get_guint8(tvb, 0);
switch(cmd) {
case 0x19:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x2F:
col_set_str(pinfo->cinfo, COL_INFO, "Network Information Request: Read Home PLMN");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Network Information Request");
break;
}
break;
case 0x1A:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_cause, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x2F:
dissect_e212_mcc_mnc(tvb, pinfo, tree, 3, E212_LAI, FALSE);
col_set_str(pinfo->cinfo, COL_INFO, "Network Information Response: Home PLMN");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Network Information Response");
break;
}
break;
case 0x1D:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "Read IMSI Request");
break;
}
break;
case 0x1E:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
proto_tree_add_item(tree, hf_isi_sim_imsi_length, tvb, 3, 1, ENC_BIG_ENDIAN);
col_set_str(pinfo->cinfo, COL_INFO, "Read IMSI Response");
break;
}
break;
case 0x21:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Provider Name Request");
break;
}
break;
case 0x22:
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x2c:
proto_tree_add_item(tree, hf_isi_sim_cause, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_secondary_cause, tvb, 2, 1, ENC_BIG_ENDIAN);
col_set_str(pinfo->cinfo, COL_INFO, "Service Provider Name Response: Invalid Location");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Provider Name Response");
break;
}
break;
case 0xBA:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x66:
col_set_str(pinfo->cinfo, COL_INFO, "Read Field Request: Integrated Circuit Card Identification (ICCID)");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Read Field Request");
break;
}
break;
case 0xBB:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x66:
proto_tree_add_item(tree, hf_isi_sim_cause, tvb, 2, 1, ENC_BIG_ENDIAN);
col_set_str(pinfo->cinfo, COL_INFO, "Read Field Response: Integrated Circuit Card Identification (ICCID)");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Read Field Response");
break;
}
break;
case 0xBC:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "SMS Request");
break;
}
break;
case 0xBD:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "SMS Response");
break;
}
break;
case 0xDC:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_subblock_count, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_subblock, tvb, 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_subblock_size, tvb, 6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_type, tvb, 8, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_location, tvb, 9, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_subblock, tvb, 12, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_subblock_count, tvb, 13, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_tag_count, tvb, 15, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_type, tvb, 18, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_tag, tvb, 20, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_tag, tvb, 22, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_pb_tag, tvb, 24, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "Phonebook Read Request");
break;
}
break;
case 0xDD:
proto_tree_add_item(tree, hf_isi_sim_service_type, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "Phonebook Read Response");
break;
}
break;
case 0xEF:
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "Indicator");
break;
}
break;
case 0xF0:
proto_tree_add_item(tree, hf_isi_sim_cause, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sim_secondary_cause, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x00:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: SIM Server Not Available");
break;
case 0x12:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: PIN Enable OK");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message");
break;
}
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown type");
break;
}
return tvb_captured_length(tvb);
}
static int dissect_isi_gss(tvbuff_t *tvb, packet_info *pinfo, proto_item *isitree, void* data _U_) {
proto_item *item;
proto_tree *tree;
guint8 cmd, code;
item = proto_tree_add_item(isitree, hf_isi_gss_payload, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_isi_msg);
proto_tree_add_item(tree, hf_isi_gss_message_id, tvb, 0, 1, ENC_BIG_ENDIAN);
cmd = tvb_get_guint8(tvb, 0);
switch(cmd) {
case 0x00:
proto_tree_add_item(tree, hf_isi_gss_operation, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x0E:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request: Radio Access Type Write");
break;
case 0x9C:
proto_tree_add_item(tree, hf_isi_gss_subblock_count, tvb, 2, 1, ENC_BIG_ENDIAN);
col_set_str(pinfo->cinfo, COL_INFO, "Service Request: Radio Access Type Read");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request");
break;
}
break;
case 0x01:
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Response");
break;
}
break;
case 0x02:
proto_tree_add_item(tree, hf_isi_gss_operation, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_gss_cause, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x9C:
col_set_str(pinfo->cinfo, COL_INFO, "Service Failed Response: Radio Access Type Read");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Failed Response");
break;
}
break;
case 0xF0:
proto_tree_add_item(tree, hf_isi_gss_common_message_id, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x01:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: Service Not Identified Response");
break;
case 0x12:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISI Version Get Request");
break;
case 0x13:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISI Version Get Response");
break;
case 0x14:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISA Entity Not Reachable");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message");
break;
}
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown type");
break;
}
return tvb_captured_length(tvb);
}
static void dissect_isi_gps_data(tvbuff_t *tvb, packet_info *pinfo _U_, proto_item *item _U_, proto_tree *tree)
{
int i;
double tmp_double;
float tmp_float;
int tmp_int32;
int offset = 0x0b;
guint8 pkgcount = tvb_get_guint8(tvb, 0x07);
proto_tree_add_item(tree, hf_isi_gps_sub_pkgs, tvb, 0x07, 1, ENC_BIG_ENDIAN);
for(i=0; i<pkgcount; i++) {
guint8 sptype = tvb_get_guint8(tvb, offset+1);
guint8 splen = tvb_get_guint8(tvb, offset+3);
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, offset, splen, ett_isi_msg, NULL, "Subpacket (%s)", val_to_str(sptype, isi_gps_sub_id, "unknown: 0x%x"));
proto_tree_add_item(subtree, hf_isi_gps_sub_type, tvb, offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_sub_len, tvb, offset+3, 1, ENC_BIG_ENDIAN);
offset += 4;
switch(sptype) {
case 0x02:
tmp_double = tvb_get_ntohl(tvb, offset+0);
tmp_double = (tmp_double*360)/4294967296.0;
if(tmp_double > 180.0) tmp_double -= 360.0;
proto_tree_add_double(subtree, hf_isi_gps_latitude, tvb, offset+0, 4, tmp_double);
tmp_double = tvb_get_ntohl(tvb, offset+4);
tmp_double = (tmp_double*360)/4294967296.0;
if(tmp_double > 180.0) tmp_double -= 360.0;
proto_tree_add_double(subtree, hf_isi_gps_longitude, tvb, offset+4, 4, tmp_double);
tmp_float = (float)(tvb_get_ntohl(tvb, offset+12) / 100.0);
proto_tree_add_float(subtree, hf_isi_gps_eph, tvb, offset+12, 4, tmp_float);
tmp_int32 = (tvb_get_ntohs(tvb, offset+18) - tvb_get_ntohs(tvb, offset+22))/2;
proto_tree_add_int(subtree, hf_isi_gps_altitude, tvb, offset+18, 6, tmp_int32);
tmp_float = (float)(tvb_get_ntohs(tvb, offset+20) / 2.0);
proto_tree_add_float(subtree, hf_isi_gps_epv, tvb, offset+20, 2, tmp_float);
break;
case 0x03:
proto_tree_add_item(subtree, hf_isi_gps_year, tvb, offset+0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_month, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_day, tvb, offset+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_hour, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_minute, tvb, offset+6, 1, ENC_BIG_ENDIAN);
tmp_float = (float)(tvb_get_ntohs(tvb, offset+8) / 1000.0);
proto_tree_add_float(subtree, hf_isi_gps_second, tvb, offset+8, 2, tmp_float);
break;
case 0x04:
tmp_float = (float)(tvb_get_ntohs(tvb, offset+0) / 100.0);
proto_tree_add_float(subtree, hf_isi_gps_course, tvb, offset+0, 2, tmp_float);
tmp_float = (float)(tvb_get_ntohs(tvb, offset+2) / 100.0);
proto_tree_add_float(subtree, hf_isi_gps_epd, tvb, offset+2, 2, tmp_float);
tmp_float = (float)(tvb_get_ntohs(tvb, offset+6) * CMS_TO_KMH);
proto_tree_add_float(subtree, hf_isi_gps_speed, tvb, offset+6, 2, tmp_float);
tmp_float = (float)(tvb_get_ntohs(tvb, offset+8) * CMS_TO_KMH);
proto_tree_add_float(subtree, hf_isi_gps_eps, tvb, offset+8, 2, tmp_float);
tmp_float = (float)(tvb_get_ntohs(tvb, offset+10) * CMS_TO_KMH);
proto_tree_add_float(subtree, hf_isi_gps_climb, tvb, offset+10, 2, tmp_float);
tmp_float = (float)(tvb_get_ntohs(tvb, offset+12) * CMS_TO_KMH);
proto_tree_add_float(subtree, hf_isi_gps_epc, tvb, offset+12, 2, tmp_float);
break;
case 0x05:
{
guint8 satellites = tvb_get_guint8(tvb, offset+0);
int sat;
proto_tree_add_item(subtree, hf_isi_gps_satellites, tvb, offset+0, 1, ENC_BIG_ENDIAN);
for(sat = 0; sat < satellites ; sat++) {
int pos = offset+4+(sat*SAT_PKG_LEN);
proto_tree *sattree = proto_tree_add_subtree_format(subtree, tvb, pos, SAT_PKG_LEN, ett_isi_msg, NULL, "Satellite %d", sat);
float signal_strength = (float)(tvb_get_ntohs(tvb, pos+3) / 100.0);
float elevation = (float)(tvb_get_ntohs(tvb, pos+6) / 100.0);
float azimuth = (float)(tvb_get_ntohs(tvb, pos+8) / 100.0);
proto_tree_add_item(sattree, hf_isi_gps_prn, tvb, pos+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(sattree, hf_isi_gps_sat_used, tvb, pos+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_float(sattree, hf_isi_gps_sat_strength, tvb, pos+3, 2, signal_strength);
proto_tree_add_float(sattree, hf_isi_gps_sat_elevation, tvb, pos+6, 2, elevation);
proto_tree_add_float(sattree, hf_isi_gps_sat_azimuth, tvb, pos+8, 2, azimuth);
}
}
break;
case 0x07:
proto_tree_add_item(subtree, hf_isi_gps_mcc, tvb, offset+0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_mnc, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_lac, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_cid, tvb, offset+6, 2, ENC_BIG_ENDIAN);
break;
case 0x08:
proto_tree_add_item(subtree, hf_isi_gps_mcc, tvb, offset+0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_mnc, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_gps_ucid, tvb, offset+4, 4, ENC_BIG_ENDIAN);
break;
default:
break;
}
offset += splen - 4;
}
}
static int dissect_isi_gps(tvbuff_t *tvb, packet_info *pinfo, proto_item *isitree, void* data _U_)
{
proto_item *item;
proto_tree *tree;
guint8 cmd;
item = proto_tree_add_item(isitree, hf_isi_gps_payload, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_isi_msg);
proto_tree_add_item(tree, hf_isi_gps_cmd, tvb, 0, 1, ENC_BIG_ENDIAN);
cmd = tvb_get_guint8(tvb, 0);
switch(cmd) {
case 0x7d:
proto_tree_add_item(tree, hf_isi_gps_status, tvb, 2, 1, ENC_BIG_ENDIAN);
col_add_fstr(pinfo->cinfo, COL_INFO, "GPS Status Indication: %s", val_to_str(tvb_get_guint8(tvb, 2), isi_gps_status, "unknown (0x%x)"));
break;
case 0x84:
case 0x85:
case 0x86:
case 0x87:
case 0x88:
case 0x89:
case 0x8a:
case 0x8b:
col_add_fstr(pinfo->cinfo, COL_INFO, "unknown A-GPS packet (0x%02x)", cmd);
break;
case 0x90:
col_set_str(pinfo->cinfo, COL_INFO, "GPS Power Request");
break;
case 0x91:
col_set_str(pinfo->cinfo, COL_INFO, "GPS Power Response");
break;
case 0x92:
col_set_str(pinfo->cinfo, COL_INFO, "GPS Data");
dissect_isi_gps_data(tvb, pinfo, item, tree);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "unknown GPS packet (0x%02x)", cmd);
break;
}
return tvb_captured_length(tvb);
}
static int dissect_isi_ss(tvbuff_t *tvb, packet_info *pinfo, proto_item *isitree, void* data _U_)
{
proto_item *item;
proto_tree *tree;
guint8 cmd, code;
item = proto_tree_add_item(isitree, hf_isi_ss_payload, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_isi_msg);
proto_tree_add_item(tree, hf_isi_ss_message_id, tvb, 0, 1, ENC_BIG_ENDIAN);
cmd = tvb_get_guint8(tvb, 0);
switch(cmd) {
case 0x00:
proto_tree_add_item(tree, hf_isi_ss_operation, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_ss_service_code, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x05:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request: Interrogation");
break;
case 0x06:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request: GSM Password Registration");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request");
break;
}
break;
case 0x01:
proto_tree_add_item(tree, hf_isi_ss_operation, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_ss_service_code, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x05:
col_set_str(pinfo->cinfo, COL_INFO, "Service Completed Response: Interrogation");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Completed Response");
break;
}
break;
case 0x02:
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Failed Response");
break;
}
break;
case 0x04:
proto_tree_add_item(tree, hf_isi_ss_ussd_type, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_ss_subblock_count, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x02:
proto_tree_add_item(tree, hf_isi_ss_subblock, tvb, 3, 1, ENC_BIG_ENDIAN);
col_set_str(pinfo->cinfo, COL_INFO, "GSM USSD Send Command Request");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "GSM USSD Message Send Request");
break;
}
break;
case 0x05:
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "GSM USSD Message Send Response");
break;
}
break;
case 0x06:
proto_tree_add_item(tree, hf_isi_ss_ussd_type, tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_ss_ussd_length, tvb, 3, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x04:
col_set_str(pinfo->cinfo, COL_INFO, "GSM USSD Message Received Notification");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "GSM USSD Message Received Indication");
break;
}
break;
case 0x09:
proto_tree_add_item(tree, hf_isi_ss_status_indication, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_ss_subblock_count, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x00:
col_set_str(pinfo->cinfo, COL_INFO, "Status Indication: Request Service Start");
break;
case 0x01:
col_set_str(pinfo->cinfo, COL_INFO, "Status Indication: Request Service Stop");
break;
case 0x02:
col_set_str(pinfo->cinfo, COL_INFO, "Status Indication: Request USSD Start");
break;
case 0x03:
col_set_str(pinfo->cinfo, COL_INFO, "Status Indication: Request USSD Stop");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Status Indication");
break;
}
break;
case 0x10:
proto_tree_add_item(tree, hf_isi_ss_operation, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_ss_service_code, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x05:
col_set_str(pinfo->cinfo, COL_INFO, "Service Completed Indication: Interrogation");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Service Completed Indication");
break;
}
break;
case 0xF0:
proto_tree_add_item(tree, hf_isi_ss_common_message_id, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x01:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: Service Not Identified Response");
break;
case 0x12:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISI Version Get Request");
break;
case 0x13:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISI Version Get Response");
break;
case 0x14:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISA Entity Not Reachable");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message");
break;
}
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown type");
break;
}
return tvb_captured_length(tvb);
}
static void dissect_isi_network_status(tvbuff_t *tvb, packet_info *pinfo _U_, proto_item *item _U_, proto_tree *tree)
{
int i;
int offset = 0x03;
guint16 len;
guint8 pkgcount = tvb_get_guint8(tvb, 0x02);
proto_tree_add_item(tree, hf_isi_network_data_sub_pkgs, tvb, 0x02, 1, ENC_BIG_ENDIAN);
for(i=0; i<pkgcount; i++) {
guint8 sptype = tvb_get_guint8(tvb, offset+0);
guint8 splen = tvb_get_guint8(tvb, offset+1);
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, offset, splen, ett_isi_msg, NULL, "Subpacket (%s)", val_to_str(sptype, isi_network_status_sub_id, "unknown: 0x%x"));
proto_tree_add_item(subtree, hf_isi_network_status_sub_type, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_network_status_sub_len, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
switch(sptype) {
case 0x00:
break;
case 0x09:
proto_tree_add_item(subtree, hf_isi_network_status_sub_lac, tvb, offset+0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_network_status_sub_cid, tvb, offset+4, 4, ENC_BIG_ENDIAN);
break;
case 0xe3:
len = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_item(subtree, hf_isi_network_status_sub_msg_len, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_network_status_sub_msg, tvb, offset+4, len*2, ENC_UTF_16|ENC_BIG_ENDIAN);
break;
default:
break;
}
offset += splen - 2;
}
}
static void dissect_isi_network_cell_info_ind(tvbuff_t *tvb, packet_info *pinfo, proto_item *item, proto_tree *tree) {
int i;
int offset = 0x03;
guint8 pkgcount = tvb_get_guint8(tvb, 0x02);
static const int *gsm_band_fields[] = {
&hf_isi_network_gsm_band_900,
&hf_isi_network_gsm_band_1800,
&hf_isi_network_gsm_band_1900,
&hf_isi_network_gsm_band_850,
NULL
};
proto_tree_add_item(tree, hf_isi_network_data_sub_pkgs, tvb, 0x02, 1, ENC_BIG_ENDIAN);
for(i=0; i<pkgcount; i++) {
guint8 sptype = tvb_get_guint8(tvb, offset+0);
guint8 splen = tvb_get_guint8(tvb, offset+1);
proto_tree *subtree = proto_tree_add_subtree_format(tree, tvb, offset, splen, ett_isi_msg, NULL, "Subpacket (%s)", val_to_str(sptype, isi_network_cell_info_sub_id, "unknown: 0x%x"));
proto_tree_add_item(subtree, hf_isi_network_cell_info_sub_type, tvb, offset+0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_network_cell_info_sub_len, tvb, offset+1, 1, ENC_BIG_ENDIAN);
offset += 2;
switch(sptype) {
case 0x50:
expert_add_info(pinfo, item, &ei_isi_unsupported_packet);
break;
case 0x46:
proto_tree_add_item(subtree, hf_isi_network_status_sub_lac, tvb, offset+0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_isi_network_status_sub_cid, tvb, offset+2, 4, ENC_BIG_ENDIAN);
proto_tree_add_bitmask_text(subtree, tvb, offset+6, 4, "GSM Bands: ", "all bands, since none is selected", ett_isi_network_gsm_band_info, gsm_band_fields, FALSE, BMT_NO_FALSE | BMT_NO_TFS);
proto_tree_add_item(subtree, hf_isi_network_cell_info_sub_operator, tvb, offset+10, 3, ENC_BIG_ENDIAN);
break;
case 0x47:
expert_add_info(pinfo, item, &ei_isi_unsupported_packet);
break;
default:
expert_add_info(pinfo, item, &ei_isi_unsupported_packet);
break;
}
offset += splen - 2;
}
}
static int dissect_isi_network(tvbuff_t *tvb, packet_info *pinfo, proto_item *isitree, void* data _U_) {
proto_item *item;
proto_tree *tree;
guint8 cmd;
item = proto_tree_add_item(isitree, hf_isi_network_payload, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_isi_msg);
proto_tree_add_item(tree, hf_isi_network_cmd, tvb, 0, 1, ENC_BIG_ENDIAN);
cmd = tvb_get_guint8(tvb, 0);
switch(cmd) {
case 0x07:
col_set_str(pinfo->cinfo, COL_INFO, "Network Selection Request");
expert_add_info(pinfo, item, &ei_isi_unsupported_packet);
break;
case 0x20:
col_set_str(pinfo->cinfo, COL_INFO, "Network Ciphering Indication");
expert_add_info(pinfo, item, &ei_isi_unsupported_packet);
break;
case 0xE2:
col_set_str(pinfo->cinfo, COL_INFO, "Network Status Indication");
dissect_isi_network_status(tvb, pinfo, item, tree);
break;
case 0x42:
col_set_str(pinfo->cinfo, COL_INFO, "Network Cell Info Indication");
dissect_isi_network_cell_info_ind(tvb, pinfo, item, tree);
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "unknown Network packet");
expert_add_info(pinfo, item, &ei_isi_unsupported_packet);
break;
}
return tvb_captured_length(tvb);
}
static int dissect_isi_sms(tvbuff_t *tvb, packet_info *pinfo, proto_item *isitree, void* data _U_) {
proto_item *item = NULL;
proto_tree *tree = NULL;
guint8 cmd, code;
item = proto_tree_add_item(isitree, hf_isi_sms_payload, tvb, 0, -1, ENC_NA);
tree = proto_item_add_subtree(item, ett_isi_msg);
proto_tree_add_item(tree, hf_isi_sms_message_id, tvb, 0, 1, ENC_BIG_ENDIAN);
cmd = tvb_get_guint8(tvb, 0);
switch(cmd) {
case 0x03:
proto_tree_add_item(tree, hf_isi_sms_subblock_count, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
#if 0
case 0x05:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request: Interrogation");
break;
case 0x06:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request: GSM Password Registration");
break;
#endif
default:
col_set_str(pinfo->cinfo, COL_INFO, "SMS Message Send Response");
break;
}
break;
case 0x06:
proto_tree_add_item(tree, hf_isi_sms_routing_command, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sms_subblock_count, tvb, 2, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
#if 0
case 0x05:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request: Interrogation");
break;
case 0x06:
col_set_str(pinfo->cinfo, COL_INFO, "Service Request: GSM Password Registration");
break;
#endif
default:
col_set_str(pinfo->cinfo, COL_INFO, "SMS Point-to-Point Routing Request");
break;
}
break;
case 0x07:
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "SMS Point-to-Point Routing Response");
break;
}
break;
case 0x0B:
proto_tree_add_item(tree, hf_isi_sms_routing_command, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sms_routing_mode, tvb, 2, 1, ENC_BIG_ENDIAN);
#if 0
proto_tree_add_item(tree, hf_isi_sms_cb_subject_list_type, tvb, 3, 1, FALSE);
proto_tree_add_item(tree, hf_isi_sms_cb_subject_count, tvb, 4, 1, FALSE);
proto_tree_add_item(tree, hf_isi_sms_cb_language_count, tvb, 5, 1, FALSE);
proto_tree_add_item(tree, hf_isi_sms_cb_range, tvb, 6, 1, FALSE);
#endif
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x00:
col_set_str(pinfo->cinfo, COL_INFO, "SMS GSM Cell Broadcast Routing Release");
break;
case 0x01:
col_set_str(pinfo->cinfo, COL_INFO, "SMS GSM Cell Broadcast Routing Set");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "SMS GSM Cell Broadcast Routing Request");
break;
}
break;
case 0x0C:
#if 0
proto_tree_add_item(tree, hf_isi_sms_operation, tvb, 1, 1, FALSE);
proto_tree_add_item(tree, hf_isi_sms_service_code, tvb, 2, 1, FALSE);
#endif
code = tvb_get_guint8(tvb, 1);
switch(code) {
default:
col_set_str(pinfo->cinfo, COL_INFO, "SMS GSM Cell Broadcast Routing Response");
break;
}
break;
case 0x22:
proto_tree_add_item(tree, hf_isi_sms_send_status, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_isi_sms_route, tvb, 3, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x02:
col_set_str(pinfo->cinfo, COL_INFO, "SMS Message Sending Status: Waiting for Network");
break;
case 0x03:
col_set_str(pinfo->cinfo, COL_INFO, "SMS Message Sending Status: Idle");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "SMS Message Sending Status Indication");
break;
}
break;
case 0xF0:
proto_tree_add_item(tree, hf_isi_sms_common_message_id, tvb, 1, 1, ENC_BIG_ENDIAN);
code = tvb_get_guint8(tvb, 1);
switch(code) {
case 0x01:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: Service Not Identified Response");
break;
case 0x12:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISI Version Get Request");
break;
case 0x13:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISI Version Get Response");
break;
case 0x14:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message: ISA Entity Not Reachable");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Common Message");
break;
}
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "Unknown type");
break;
}
return tvb_captured_length(tvb);
}
static int dissect_isi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_) {
proto_tree *isi_tree;
proto_item *item, *item_len;
tvbuff_t *content_tvb;
guint8 src;
guint8 dst;
guint8 resource;
guint16 length;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ISI");
col_clear(pinfo->cinfo, COL_INFO);
item = proto_tree_add_item(tree, proto_isi, tvb, 0, -1, ENC_NA);
isi_tree = proto_item_add_subtree(item, ett_isi);
proto_tree_add_item(isi_tree, hf_isi_rdev, tvb, 0, 1, ENC_NA);
proto_tree_add_item(isi_tree, hf_isi_sdev, tvb, 1, 1, ENC_NA);
proto_tree_add_item(isi_tree, hf_isi_res, tvb, 2, 1, ENC_NA);
item_len = proto_tree_add_item(isi_tree, hf_isi_len, tvb, 3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(isi_tree, hf_isi_robj, tvb, 5, 1, ENC_NA);
proto_tree_add_item(isi_tree, hf_isi_sobj, tvb, 6, 1, ENC_NA);
proto_tree_add_item(isi_tree, hf_isi_id, tvb, 7, 1, ENC_NA);
length = tvb_get_ntohs(tvb, 3) - 3;
resource = tvb_get_guint8(tvb, 2);
dst = tvb_get_guint8(tvb, 0);
src = tvb_get_guint8(tvb, 1);
if (tvb_reported_length(tvb) - 8 < length) {
expert_add_info_format(pinfo, item_len, &ei_isi_len, "Broken Length (%d > %d)", length, tvb_reported_length(tvb)-8);
length = tvb_reported_length(tvb) - 8;
}
col_set_str(pinfo->cinfo, COL_DEF_SRC, val_to_str_const(src, hf_isi_device, "Unknown"));
col_set_str(pinfo->cinfo, COL_DEF_DST, val_to_str_const(dst, hf_isi_device, "Unknown"));
content_tvb = tvb_new_subset_length(tvb, 8, length);
if (!dissector_try_uint(isi_resource_dissector_table, resource, content_tvb, pinfo, isi_tree))
call_data_dissector(content_tvb, pinfo, isi_tree);
return tvb_captured_length(tvb);
}
static gboolean dissect_usb_isi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
tvbuff_t *next_tvb;
if(tvb_get_guint8(tvb, 0) != 0x1B)
return FALSE;
next_tvb = tvb_new_subset_remaining(tvb, 1);
dissect_isi(next_tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_isi(void)
{
static hf_register_info hf[] = {
{ &hf_isi_rdev,
{ "Receiver Device", "isi.rdev", FT_UINT8, BASE_HEX,
VALS(hf_isi_device), 0x0, NULL, HFILL }},
{ &hf_isi_sdev,
{ "Sender Device", "isi.sdev", FT_UINT8, BASE_HEX,
VALS(hf_isi_device), 0x0, NULL, HFILL }},
{ &hf_isi_res,
{ "Resource", "isi.res", FT_UINT8, BASE_HEX,
VALS(hf_isi_resource), 0x0, NULL, HFILL }},
{ &hf_isi_len,
{ "Length", "isi.len", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_isi_robj,
{ "Receiver Object", "isi.robj", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sobj,
{ "Sender Object", "isi.sobj", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_isi_id,
{ "Packet ID", "isi.id", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }}
};
static hf_register_info simauth_hf[] = {
{ &hf_isi_sim_auth_payload,
{ "Payload", "isi.sim.auth.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_cmd,
{ "Command", "isi.sim.auth.cmd", FT_UINT8, BASE_HEX, VALS(isi_sim_auth_id), 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_pw_type,
{ "Password Type", "isi.sim.auth.type", FT_UINT8, BASE_HEX, VALS(isi_sim_auth_pw_type), 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_pin,
{ "PIN", "isi.sim.auth.pin", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_puk,
{ "PUK", "isi.sim.auth.puk", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_new_pin,
{ "New PIN", "isi.sim.auth.new_pin", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_protection_req,
{ "Protection Request", "isi.sim.auth.request.protection", FT_UINT8, BASE_HEX, VALS(isi_sim_auth_protection_req), 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_protection_rsp,
{ "Protection Response", "isi.sim.auth.response.protection", FT_BOOLEAN, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_status_rsp,
{ "Status Response", "isi.sim.auth.response.status", FT_UINT8, BASE_HEX, VALS(isi_sim_auth_resp), 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_indication,
{ "Indication", "isi.sim.auth.indication", FT_UINT8, BASE_HEX, VALS(isi_sim_auth_indication), 0x0, NULL, HFILL }},
{ &hf_isi_sim_auth_indication_cfg,
{ "Configuration", "isi.sim.auth.cfg", FT_UINT8, BASE_HEX, VALS(isi_sim_auth_indication_cfg), 0x0, NULL, HFILL }}
};
static hf_register_info sim_hf[] = {
{ &hf_isi_sim_payload,
{ "Payload", "isi.sim.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sim_message_id,
{ "Message ID", "isi.sim.msg_id", FT_UINT8, BASE_HEX, VALS(isi_sim_message_id), 0x0, NULL, HFILL }},
{ &hf_isi_sim_service_type,
{ "Service Type", "isi.sim.service_type", FT_UINT8, BASE_HEX, VALS(isi_sim_service_type), 0x0, NULL, HFILL }},
{ &hf_isi_sim_cause,
{ "Cause", "isi.sim.cause", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &isi_sim_cause_ext, 0x0, NULL, HFILL }},
{ &hf_isi_sim_secondary_cause,
{ "Secondary Cause", "isi.sim.secondary_cause", FT_UINT8, BASE_HEX|BASE_EXT_STRING, &isi_sim_cause_ext, 0x0, NULL, HFILL }},
{&hf_isi_sim_subblock_count,
{ "Subblock Count", "isi.sim.subblock_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_isi_sim_subblock_size,
{ "Subblock Size", "isi.sim.subblock_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sim_pb_subblock,
{ "Subblock", "isi.sim.pb.subblock", FT_UINT8, BASE_HEX, VALS(isi_sim_pb_subblock), 0x0, NULL, HFILL }},
{ &hf_isi_sim_pb_type,
{ "Phonebook Type", "isi.sim.pb.type", FT_UINT8, BASE_HEX, VALS(isi_sim_pb_type), 0x0, NULL, HFILL }},
{&hf_isi_sim_pb_location,
{ "Phonebook Location", "isi.sim.pb.location", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{&hf_isi_sim_pb_tag_count,
{ "Tag Count", "isi.sim.pb.tag.count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sim_pb_tag,
{ "Phonebook Item Type", "isi.sim.pb.tag", FT_UINT8, BASE_HEX, VALS(isi_sim_pb_tag), 0x0, NULL, HFILL }},
{&hf_isi_sim_imsi_length,
{ "IMSI Length", "isi.sim.imsi.length", FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }},
};
static hf_register_info gps_hf[] = {
{ &hf_isi_gps_payload,
{ "Payload", "isi.gps.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_cmd,
{ "Command", "isi.gps.cmd", FT_UINT8, BASE_HEX, VALS(isi_gps_id), 0x0, NULL, HFILL }},
{ &hf_isi_gps_sub_pkgs,
{ "Number of Subpackets", "isi.gps.pkgs", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_sub_type,
{ "Subpacket Type", "isi.gps.sub.type", FT_UINT8, BASE_HEX, VALS(isi_gps_sub_id), 0x0, NULL, HFILL }},
{ &hf_isi_gps_sub_len,
{ "Subpacket Length", "isi.gps.sub.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_status,
{ "Status", "isi.gps.status", FT_UINT8, BASE_HEX, VALS(isi_gps_status), 0x0, NULL, HFILL }},
{ &hf_isi_gps_year,
{ "Year", "isi.gps.date.year", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_month,
{ "Month", "isi.gps.date.month", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_day,
{ "Day", "isi.gps.date.day", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_hour,
{ "Hour", "isi.gps.time.hour", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_minute,
{ "Minute", "isi.gps.time.minute", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_second,
{ "Second", "isi.gps.time.second", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_latitude,
{ "Latitude", "isi.gps.lat", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_longitude,
{ "Longitude", "isi.gps.lon", FT_DOUBLE, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_eph,
{ "Position Accuracy", "isi.gps.eph", FT_FLOAT, BASE_NONE, NULL, 0x0, "EPH (position accuracy) in meter", HFILL }},
{ &hf_isi_gps_altitude,
{ "Altitude", "isi.gps.alt", FT_INT16, BASE_DEC, NULL, 0x0, "Altitude in meter", HFILL }},
{ &hf_isi_gps_epv,
{ "Altitude Accuracy", "isi.gps.epv", FT_FLOAT, BASE_NONE, NULL, 0x0, "EPV (altitude accuracy) in meter", HFILL }},
{ &hf_isi_gps_course,
{ "Course", "isi.gps.course", FT_FLOAT, BASE_NONE, NULL, 0x0, "Course in degree", HFILL }},
{ &hf_isi_gps_epd,
{ "Course Accuracy", "isi.gps.epd", FT_FLOAT, BASE_NONE, NULL, 0x0, "EPD (course accuracy) in degree", HFILL }},
{ &hf_isi_gps_speed,
{ "Speed", "isi.gps.speed", FT_FLOAT, BASE_NONE, NULL, 0x0, "Speed in km/h", HFILL }},
{ &hf_isi_gps_eps,
{ "Speed Accuracy", "isi.gps.eps", FT_FLOAT, BASE_NONE, NULL, 0x0, "EPS (speed accuracy) in km/h", HFILL }},
{ &hf_isi_gps_climb,
{ "Climb", "isi.gps.climb", FT_FLOAT, BASE_NONE, NULL, 0x0, "Climb in km/h", HFILL }},
{ &hf_isi_gps_satellites,
{ "Visible Satellites", "isi.gps.satellites", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_prn,
{ "Pseudorandom Noise (PRN)", "isi.gps.sat.prn", FT_UINT8, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_sat_used,
{ "in use", "isi.gps.sat.used", FT_BOOLEAN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_sat_strength,
{ "Signal Strength", "isi.gps.sat.strength", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_sat_elevation,
{ "Elevation", "isi.gps.sat.elevation", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_sat_azimuth,
{ "Azimuth", "isi.gps.sat.azimuth", FT_FLOAT, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_epc,
{ "Climb Accuracy", "isi.gps.epc", FT_FLOAT, BASE_NONE, NULL, 0x0, "EPC (climb accuracy) in km/h", HFILL }},
{ &hf_isi_gps_mcc,
{ "Mobile Country Code (MCC)", "isi.gps.gsm.mcc", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_mnc,
{ "Mobile Network Code (MNC)", "isi.gps.gsm.mnc", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_lac,
{ "Location Area Code (LAC)", "isi.gps.gsm.lac", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_cid,
{ "Cell ID (CID)", "isi.gps.gsm.cid", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gps_ucid,
{ "Cell ID (UCID)", "isi.gps.gsm.ucid", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }}
};
static hf_register_info gss_hf[] = {
{ &hf_isi_gss_payload,
{ "Payload", "isi.gss.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gss_message_id,
{ "Message ID", "isi.gss.msg_id", FT_UINT8, BASE_HEX, VALS(isi_gss_message_id), 0x0, NULL, HFILL }},
#if 0
{ &hf_isi_gss_subblock,
{ "Subblock", "isi.gss.subblock", FT_UINT8, BASE_HEX, VALS(isi_gss_subblock), 0x0, NULL, HFILL }},
#endif
{ &hf_isi_gss_operation,
{ "Operation", "isi.gss.operation", FT_UINT8, BASE_HEX, VALS(isi_gss_operation), 0x0, NULL, HFILL }},
{ &hf_isi_gss_subblock_count,
{ "Subblock Count", "isi.gss.subblock_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_gss_cause,
{ "Cause", "isi.gss.cause", FT_UINT8, BASE_HEX, VALS(isi_gss_cause), 0x0, NULL, HFILL }},
{ &hf_isi_gss_common_message_id,
{ "Common Message ID", "isi.gss.common.msg_id", FT_UINT8, BASE_HEX, VALS(isi_gss_common_message_id), 0x0, NULL, HFILL }},
};
static hf_register_info ss_hf[] = {
{ &hf_isi_ss_payload,
{ "Payload", "isi.ss.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_ss_message_id,
{ "Message ID", "isi.ss.msg_id", FT_UINT8, BASE_HEX, VALS(isi_ss_message_id), 0x0, NULL, HFILL }},
{ &hf_isi_ss_ussd_type,
{ "USSD Type", "isi.ss.ussd.type", FT_UINT8, BASE_HEX, VALS(isi_ss_ussd_type), 0x0, NULL, HFILL }},
{ &hf_isi_ss_subblock_count,
{ "Subblock Count", "isi.ss.subblock_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_ss_subblock,
{ "Subblock", "isi.ss.subblock", FT_UINT8, BASE_HEX, VALS(isi_ss_subblock), 0x0, NULL, HFILL }},
{ &hf_isi_ss_operation,
{ "Operation", "isi.ss.operation", FT_UINT8, BASE_HEX, VALS(isi_ss_operation), 0x0, NULL, HFILL }},
{ &hf_isi_ss_service_code,
{ "Service Code", "isi.ss.service_code", FT_UINT8, BASE_HEX, VALS(isi_ss_service_code), 0x0, NULL, HFILL }},
{ &hf_isi_ss_status_indication,
{ "Status Indication", "isi.ss.status_indication", FT_UINT8, BASE_HEX, VALS(isi_ss_status_indication), 0x0, NULL, HFILL }},
{ &hf_isi_ss_ussd_length,
{ "Length", "isi.ss.ussd.length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_ss_common_message_id,
{ "Common Message ID", "isi.ss.common.msg_id", FT_UINT8, BASE_HEX, VALS(isi_ss_common_message_id), 0x0, NULL, HFILL }},
};
static hf_register_info network_hf[] = {
{ &hf_isi_network_payload,
{ "Payload", "isi.network.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_cmd,
{ "Command", "isi.network.cmd", FT_UINT8, BASE_HEX, VALS(isi_network_id), 0x0, NULL, HFILL }},
{ &hf_isi_network_data_sub_pkgs,
{ "Number of Subpackets", "isi.network.pkgs", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_status_sub_type,
{ "Subpacket Type", "isi.network.sub.type", FT_UINT8, BASE_HEX, VALS(isi_network_status_sub_id), 0x0, NULL, HFILL }},
{ &hf_isi_network_status_sub_len,
{ "Subpacket Length", "isi.network.sub.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_status_sub_lac,
{ "Location Area Code (LAC)", "isi.network.sub.lac", FT_UINT16, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_status_sub_cid,
{ "Cell ID (CID)", "isi.network.sub.cid", FT_UINT32, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_status_sub_msg_len,
{ "Message Length", "isi.network.sub.msg_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_status_sub_msg,
{ "Message", "isi.network.sub.msg", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_cell_info_sub_type,
{ "Subpacket Type", "isi.network.sub.type", FT_UINT8, BASE_HEX, VALS(isi_network_cell_info_sub_id), 0x0, NULL, HFILL }},
{ &hf_isi_network_cell_info_sub_len,
{ "Subpacket Length", "isi.network.sub.len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_cell_info_sub_operator,
{ "Operator Code", "isi.network.sub.operator", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_network_gsm_band_900,
{ "900 Mhz Band", "isi.network.sub.gsm_band_900", FT_BOOLEAN, 32, NULL, 0x00000001, NULL, HFILL }},
{ &hf_isi_network_gsm_band_1800,
{ "1800 Mhz Band", "isi.network.sub.gsm_band_1800", FT_BOOLEAN, 32, NULL, 0x00000002, NULL, HFILL }},
{ &hf_isi_network_gsm_band_1900,
{ "1900 Mhz Band", "isi.network.sub.gsm_band_1900", FT_BOOLEAN, 32, NULL, 0x00000004, NULL, HFILL }},
{ &hf_isi_network_gsm_band_850,
{ "850 Mhz Band", "isi.network.sub.gsm_band_850", FT_BOOLEAN, 32, NULL, 0x00000008, NULL, HFILL }}
};
static hf_register_info sms_hf[] = {
{ &hf_isi_sms_payload,
{ "Payload", "isi.sms.payload", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sms_message_id,
{ "Message ID", "isi.sms.msg_id", FT_UINT8, BASE_HEX, VALS(isi_sms_message_id), 0x0, NULL, HFILL }},
{ &hf_isi_sms_routing_command,
{ "SMS Routing Command", "isi.sms.routing.command", FT_UINT8, BASE_HEX, VALS(isi_sms_routing_command), 0x0, NULL, HFILL }},
{ &hf_isi_sms_routing_mode,
{ "Routing Mode", "isi.sms.routing.mode", FT_UINT8, BASE_HEX, VALS(isi_sms_routing_mode), 0x0, NULL, HFILL }},
{ &hf_isi_sms_route,
{ "Message Route", "isi.sms.route", FT_UINT8, BASE_HEX, VALS(isi_sms_route), 0x0, NULL, HFILL }},
{ &hf_isi_sms_subblock_count,
{ "Subblock Count", "isi.sms.subblock_count", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_isi_sms_send_status,
{ "Sending Status", "isi.sms.sending_status", FT_UINT8, BASE_HEX, VALS(isi_sms_send_status), 0x0, NULL, HFILL }},
#if 0
{ &hf_isi_sms_subblock,
{ "Subblock", "isi.sms.subblock", FT_UINT8, BASE_HEX, VALS(isi_sms_subblock), 0x0, NULL, HFILL }},
#endif
{ &hf_isi_sms_common_message_id,
{ "Common Message ID", "isi.sms.common.msg_id", FT_UINT8, BASE_HEX, VALS(isi_sms_common_message_id), 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_isi,
&ett_isi_msg,
&ett_isi_network_gsm_band_info
};
static ei_register_info ei[] = {
{ &ei_isi_len, { "isi.len.invalid", PI_PROTOCOL, PI_WARN, "Broken Length", EXPFILL }},
{ &ei_isi_unsupported_packet, { "isi.unsupported_packet", PI_UNDECODED, PI_WARN, "Unsupported packet", EXPFILL }},
};
expert_module_t* expert_isi;
proto_isi = proto_register_protocol("Intelligent Service Interface", "ISI", "isi");
proto_register_field_array(proto_isi, hf, array_length(hf));
proto_register_field_array(proto_isi, simauth_hf, array_length(simauth_hf));
proto_register_field_array(proto_isi, sim_hf, array_length(sim_hf));
proto_register_field_array(proto_isi, gss_hf, array_length(gss_hf));
proto_register_field_array(proto_isi, gps_hf, array_length(gps_hf));
proto_register_field_array(proto_isi, ss_hf, array_length(ss_hf));
proto_register_field_array(proto_isi, network_hf, array_length(network_hf));
proto_register_field_array(proto_isi, sms_hf, array_length(sms_hf));
proto_register_subtree_array(ett, array_length(ett));
expert_isi = expert_register_protocol(proto_isi);
expert_register_field_array(expert_isi, ei, array_length(ei));
isi_resource_dissector_table = register_dissector_table("isi.resource", "ISI resource", proto_isi, FT_UINT8, BASE_HEX, DISSECTOR_TABLE_ALLOW_DUPLICATE);
}
void
proto_reg_handoff_isi(void)
{
static gboolean initialized=FALSE;
if(!initialized) {
dissector_add_uint("sll.ltype", LINUX_SLL_P_ISI, create_dissector_handle(dissect_isi, proto_isi));
heur_dissector_add("usb.bulk", dissect_usb_isi, "ISI bulk endpoint", "usb_bulk_isi", proto_isi, HEURISTIC_DISABLE);
dissector_add_uint("isi.resource", 0x02, create_dissector_handle(dissect_isi_sms, proto_isi));
dissector_add_uint("isi.resource", 0x06, create_dissector_handle(dissect_isi_ss, proto_isi));
dissector_add_uint("isi.resource", 0x08, create_dissector_handle(dissect_isi_sim_auth, proto_isi));
dissector_add_uint("isi.resource", 0x09, create_dissector_handle(dissect_isi_sim, proto_isi));
dissector_add_uint("isi.resource", 0x0a, create_dissector_handle(dissect_isi_network, proto_isi));
dissector_add_uint("isi.resource", 0x32, create_dissector_handle(dissect_isi_gss, proto_isi));
dissector_add_uint("isi.resource", 0x54, create_dissector_handle(dissect_isi_gps, proto_isi));
}
}
