void
dissect_unid(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_item *pi,
const char* ssn_name, int hf_ssn_timestamp,
int hf_ssn_date, int hf_ssn_time, int hf_macid, gint ett, gint ett_ssn)
{
proto_tree *tree, *ssn_tree;
tree = proto_item_add_subtree(pi, ett);
ssn_tree = proto_tree_add_subtree(tree, tvb, offset, 6, ett_ssn, NULL, ssn_name);
dissect_cipsafety_ssn(ssn_tree, tvb, pinfo, offset, hf_ssn_timestamp, hf_ssn_date, hf_ssn_time);
proto_tree_add_item(tree, hf_macid, tvb, offset+6, 4, ENC_LITTLE_ENDIAN);
}
void dissect_cipsafety_ssn(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo _U_, int offset,
int hf_real_datetime, int hf_date, int hf_time)
{
guint16 date;
date = tvb_get_letohs( tvb, offset);
if ((date >= 11688) && (date <= 65534))
{
dissect_cip_date_and_time(tree, tvb, offset, hf_real_datetime);
}
else
{
proto_tree_add_item(tree, hf_date, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_time, tvb, offset+2, 4, ENC_LITTLE_ENDIAN);
}
}
static void
dissect_cip_s_supervisor_data( proto_tree *item_tree,
tvbuff_t *tvb, int offset, int item_length, packet_info *pinfo )
{
proto_item *pi, *rrsc_item;
proto_tree *rrsc_tree, *cmd_data_tree, *bitmap_tree;
int req_path_size;
int temp_data;
guint8 service, gen_status, add_stat_size;
cip_simple_request_info_t req_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIPS Supervisor");
service = tvb_get_guint8( tvb, offset );
rrsc_tree = proto_tree_add_subtree( item_tree, tvb, offset, 1, ett_ssupervisor_rrsc, &rrsc_item, "Service: " );
proto_tree_add_item( rrsc_tree, hf_cip_reqrsp, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_item_append_text( rrsc_item, "%s (%s)",
val_to_str( ( service & CIP_SC_MASK ), cip_sc_vals_ssupervisor , "Unknown Service (0x%02x)"),
val_to_str_const( ( service & CIP_SC_RESPONSE_MASK )>>7, cip_sc_rr, "") );
proto_tree_add_item(rrsc_tree, hf_cip_ssupervisor_sc, tvb, offset, 1, ENC_LITTLE_ENDIAN );
load_cip_request_data(pinfo, &req_data);
if (service & CIP_SC_RESPONSE_MASK)
{
gen_status = tvb_get_guint8( tvb, offset+2 );
add_stat_size = tvb_get_guint8( tvb, offset+3 ) * 2;
if( ( item_length-4-add_stat_size ) != 0 )
{
cmd_data_tree = proto_tree_add_subtree( item_tree, tvb, offset+4+add_stat_size,
item_length-4-add_stat_size, ett_ssupervisor_cmd_data, NULL, "Command Specific Data" );
if( gen_status == CI_GRC_SUCCESS || gen_status == CI_GRC_SERVICE_ERROR )
{
switch (service & CIP_SC_MASK)
{
case SC_SSUPER_VALIDATE_CONFIGURATION:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_validate_configuration_sccrc,
tvb, offset+4+add_stat_size, 4, ENC_LITTLE_ENDIAN);
dissect_cipsafety_ssn(cmd_data_tree,
tvb, pinfo, offset+4+add_stat_size+4,
hf_cip_ssupervisor_validate_configuration_scts_timestamp,
hf_cip_ssupervisor_validate_configuration_scts_date,
hf_cip_ssupervisor_validate_configuration_scts_time);
break;
}
}
else if ((gen_status == 0xD0) && ((service & CIP_SC_MASK) == SC_SSUPER_VALIDATE_CONFIGURATION))
{
if (add_stat_size > 0)
{
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_validate_configuration_ext_error,
tvb, offset+4, 2, ENC_LITTLE_ENDIAN);
}
}
else
{
proto_tree_add_item(cmd_data_tree, hf_cip_data,
tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
}
}
else
{
req_path_size = tvb_get_guint8( tvb, offset+1 )*2;
if( (item_length-req_path_size-2) != 0 )
{
cmd_data_tree = proto_tree_add_subtree( item_tree, tvb, offset+2+req_path_size, item_length-req_path_size-2,
ett_ssupervisor_cmd_data, NULL, "Command Specific Data" );
switch (service)
{
case SC_SSUPER_RECOVER:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_recover_data,
tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
break;
case SC_SSUPER_PERFORM_DIAGNOSTICS:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_perform_diag_data,
tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
break;
case SC_SSUPER_CONFIGURE_REQUEST:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_configure_request_password,
tvb, offset+2+req_path_size, 16, ENC_NA);
pi = proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_configure_request_tunid,
tvb, offset+2+req_path_size+16, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+2+req_path_size+16, pi, "TUNID SSN",
hf_cip_ssupervisor_configure_request_tunid_ssn_timestamp,
hf_cip_ssupervisor_configure_request_tunid_ssn_date,
hf_cip_ssupervisor_configure_request_tunid_ssn_time,
hf_cip_ssupervisor_configure_request_tunid_macid,
ett_ssupervisor_configure_request_tunid,
ett_ssupervisor_configure_request_tunid_ssn);
pi = proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_configure_request_ounid,
tvb, offset+2+req_path_size+26, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+2+req_path_size+16, pi, "OUNID SSN",
hf_cip_ssupervisor_configure_request_ounid_ssn_timestamp,
hf_cip_ssupervisor_configure_request_ounid_ssn_date,
hf_cip_ssupervisor_configure_request_ounid_ssn_time,
hf_cip_ssupervisor_configure_request_ounid_macid,
ett_ssupervisor_configure_request_ounid,
ett_ssupervisor_configure_request_ounid_ssn);
break;
case SC_SSUPER_VALIDATE_CONFIGURATION:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_validate_configuration_sccrc,
tvb, offset+2+req_path_size, 4, ENC_LITTLE_ENDIAN);
dissect_cipsafety_ssn(cmd_data_tree, tvb, pinfo, offset+2+req_path_size+4,
hf_cip_ssupervisor_validate_configuration_scts_timestamp,
hf_cip_ssupervisor_validate_configuration_scts_date,
hf_cip_ssupervisor_validate_configuration_scts_time);
break;
case SC_SSUPER_SET_PASSWORD:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_set_password_current_password,
tvb, offset+2+req_path_size, 16, ENC_NA);
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_set_password_new_password,
tvb, offset+2+req_path_size+16, 16, ENC_NA);
break;
case SC_SSUPER_CONFIGURATION_LOCK:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_configure_lock_value,
tvb, offset+2+req_path_size+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_configure_lock_password,
tvb, offset+2+req_path_size+1, 16, ENC_NA);
pi = proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_configure_lock_tunid,
tvb, offset+2+req_path_size+17, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+2+req_path_size+17, pi, "TUNID SSN",
hf_cip_ssupervisor_configure_lock_tunid_ssn_timestamp,
hf_cip_ssupervisor_configure_lock_tunid_ssn_date,
hf_cip_ssupervisor_configure_lock_tunid_ssn_time,
hf_cip_ssupervisor_configure_lock_tunid_macid,
ett_ssupervisor_configure_lock_tunid,
ett_ssupervisor_configure_lock_tunid_ssn);
break;
case SC_SSUPER_MODE_CHANGE:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_mode_change_value,
tvb, offset+2+req_path_size+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_mode_change_password,
tvb, offset+2+req_path_size+1, 16, ENC_NA);
break;
case SC_SSUPER_SAFETY_RESET:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_reset_type,
tvb, offset+2+req_path_size+1, 1, ENC_LITTLE_ENDIAN);
temp_data = tvb_get_guint8( tvb, offset+2+req_path_size+1 );
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_reset_password,
tvb, offset+2+req_path_size+1, 16, ENC_NA);
pi = proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_reset_tunid,
tvb, offset+2+req_path_size+17, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+2+req_path_size+17, pi, "TUNID SSN",
hf_cip_ssupervisor_reset_tunid_tunid_ssn_timestamp,
hf_cip_ssupervisor_reset_tunid_tunid_ssn_date,
hf_cip_ssupervisor_reset_tunid_tunid_ssn_time,
hf_cip_ssupervisor_reset_tunid_macid,
ett_ssupervisor_reset_tunid,
ett_ssupervisor_reset_tunid_ssn);
if (temp_data == 2)
{
pi = proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_reset_attr_bitmap,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
bitmap_tree = proto_item_add_subtree(pi, ett_cip_ssupervisor_reset_attr_bitmap);
proto_tree_add_item(bitmap_tree, hf_cip_ssupervisor_reset_attr_bitmap_macid,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bitmap_tree, hf_cip_ssupervisor_reset_attr_bitmap_baudrate,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bitmap_tree, hf_cip_ssupervisor_reset_attr_bitmap_tunid,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bitmap_tree, hf_cip_ssupervisor_reset_attr_bitmap_password,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bitmap_tree, hf_cip_ssupervisor_reset_attr_bitmap_cfunid,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bitmap_tree, hf_cip_ssupervisor_reset_attr_bitmap_ocpunid,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bitmap_tree, hf_cip_ssupervisor_reset_attr_bitmap_reserved,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(bitmap_tree, hf_cip_ssupervisor_reset_attr_bitmap_extended,
tvb, offset+2+req_path_size+27, 1, ENC_LITTLE_ENDIAN);
}
break;
case SC_SSUPER_RESET_PASSWORD:
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_reset_password_data_size,
tvb, offset+2+req_path_size, 1, ENC_LITTLE_ENDIAN);
temp_data = tvb_get_guint8(tvb, offset+2+req_path_size);
proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_reset_password_data,
tvb, offset+2+req_path_size+1, temp_data, ENC_NA);
break;
case SC_SSUPER_PROPOSE_TUNID:
pi = proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_propose_tunid_tunid,
tvb, offset+2+req_path_size, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+2+req_path_size, pi, "TUNID SSN",
hf_cip_ssupervisor_propose_tunid_tunid_ssn_timestamp,
hf_cip_ssupervisor_propose_tunid_tunid_ssn_date,
hf_cip_ssupervisor_propose_tunid_tunid_ssn_time,
hf_cip_ssupervisor_propose_tunid_tunid_macid,
ett_ssupervisor_propose_tunid,
ett_ssupervisor_propose_tunid_ssn);
break;
case SC_SSUPER_APPLY_TUNID:
pi = proto_tree_add_item(cmd_data_tree, hf_cip_ssupervisor_apply_tunid_tunid,
tvb, offset+2+req_path_size, 10, ENC_NA);
dissect_unid(tvb, pinfo, offset+2+req_path_size, pi, "TUNID SSN",
hf_cip_ssupervisor_apply_tunid_tunid_ssn_timestamp,
hf_cip_ssupervisor_apply_tunid_tunid_ssn_date,
hf_cip_ssupervisor_apply_tunid_tunid_ssn_time,
hf_cip_ssupervisor_apply_tunid_tunid_macid,
ett_ssupervisor_apply_tunid,
ett_ssupervisor_apply_tunid_ssn);
break;
default:
proto_tree_add_item(cmd_data_tree, hf_cip_data,
tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
}
}
}
add_cip_service_to_info_column(pinfo, service, cip_sc_vals_ssupervisor);
}
static int
dissect_cip_class_s_supervisor(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *class_tree;
ti = proto_tree_add_item(tree, proto_cip_class_s_supervisor, tvb, 0, -1, ENC_NA);
class_tree = proto_item_add_subtree( ti, ett_cip_class_s_supervisor );
dissect_cip_s_supervisor_data( class_tree, tvb, 0, tvb_reported_length(tvb), pinfo );
return tvb_reported_length(tvb);
}
static int dissect_s_supervisor_exception_detail(proto_tree *tree, proto_item *item, tvbuff_t *tvb, int offset, int hf_size, int hf_data)
{
int size;
proto_tree_add_item(tree, hf_size, tvb, offset, 1, ENC_LITTLE_ENDIAN );
size = tvb_get_guint8( tvb, offset);
proto_tree_add_item(tree, hf_data, tvb, offset+1, size, ENC_NA );
proto_item_set_len(item, size+1);
return size+1;
}
static int dissect_s_supervisor_exception_detail_common(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
proto_item *pi;
proto_tree *item_tree;
int total_size = 0, size;
item_tree = proto_tree_add_subtree(tree, tvb, offset, 1, ett_exception_detail_common, &pi, "Common Exception Detail");
size = dissect_s_supervisor_exception_detail(item_tree, pi, tvb, offset,
hf_cip_ssupervisor_exception_detail_ced_size,
hf_cip_ssupervisor_exception_detail_ced_detail);
if (size == 0)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_exception_detail_ced);
return total_len;
}
total_size += size;
item_tree = proto_tree_add_subtree(tree, tvb, offset + total_size, 1, ett_exception_detail_device, &pi, "Device Exception Detail");
size = dissect_s_supervisor_exception_detail(item_tree, pi, tvb, offset + total_size,
hf_cip_ssupervisor_exception_detail_ded_size,
hf_cip_ssupervisor_exception_detail_ded_detail);
if (size == 0)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_exception_detail_ded);
return total_len;
}
total_size += size;
item_tree = proto_tree_add_subtree(tree, tvb, offset + total_size, 1, ett_exception_detail_manufacturer, &pi, "Manufacturer Exception Detail");
size = dissect_s_supervisor_exception_detail(item_tree, pi, tvb, offset + total_size,
hf_cip_ssupervisor_exception_detail_med_size,
hf_cip_ssupervisor_exception_detail_med_detail);
if (size == 0)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_exception_detail_med);
return total_len;
}
total_size += size;
return total_size;
}
static int dissect_s_supervisor_configuration_unid(packet_info *pinfo, proto_tree *tree _U_, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
if (total_len < 10)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_configuration_unid);
return total_len;
}
dissect_unid(tvb, pinfo, offset, item, "CFUNID SSN",
hf_cip_ssupervisor_configuration_unid_ssn_timestamp,
hf_cip_ssupervisor_configuration_unid_ssn_date,
hf_cip_ssupervisor_configuration_unid_ssn_time,
hf_cip_ssupervisor_configuration_unid_macid,
ett_ssupervisor_configuration_unid,
ett_ssupervisor_configuration_unid_ssn);
return 10;
}
static int dissect_s_supervisor_safety_configuration_id(packet_info *pinfo, proto_tree *tree _U_, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
if (total_len < 10)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_safety_configuration_id);
return total_len;
}
dissect_unid(tvb, pinfo, offset, item, "SCID SSN",
hf_cip_ssupervisor_safety_configuration_id_ssn_timestamp,
hf_cip_ssupervisor_safety_configuration_id_ssn_date,
hf_cip_ssupervisor_safety_configuration_id_ssn_time,
hf_cip_ssupervisor_safety_configuration_id_macid,
ett_ssupervisor_safety_configuration_id,
ett_ssupervisor_safety_configuration_id_ssn);
return 10;
}
static int dissect_s_supervisor_target_unid(packet_info *pinfo, proto_tree *tree _U_, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
if (total_len < 10)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_target_unid);
return total_len;
}
dissect_unid(tvb, pinfo, offset, item, "TUNID SSN",
hf_cip_ssupervisor_target_unid_ssn_timestamp,
hf_cip_ssupervisor_target_unid_ssn_date,
hf_cip_ssupervisor_target_unid_ssn_time,
hf_cip_ssupervisor_target_unid_macid,
ett_ssupervisor_target_unid,
ett_ssupervisor_target_unid_ssn);
return 10;
}
static int dissect_s_supervisor_output_connection_point_owners(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
guint16 i, num_entries;
proto_item *entry_item, *app_path_item;
proto_tree *entry_tree, *epath_tree;
int attr_len = 0, app_path_size;
if (total_len < 2)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_cp_owners);
return total_len;
}
entry_item = proto_tree_add_item(tree, hf_cip_ssupervisor_cp_owners_num_entries,
tvb, offset, 2, ENC_LITTLE_ENDIAN );
num_entries = tvb_get_letohs(tvb, offset);
attr_len += 2;
if (num_entries > 0)
{
entry_tree = proto_item_add_subtree(entry_item, ett_ssupervisor_output_cp_owners);
for (i = 0; i < num_entries; i++)
{
if (total_len < attr_len+11)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_cp_owners_entry);
return total_len;
}
dissect_unid(tvb, pinfo, offset+attr_len, entry_item, "OCPUNID SSN",
hf_cip_ssupervisor_output_cp_owners_ocpunid_ssn_timestamp,
hf_cip_ssupervisor_output_cp_owners_ocpunid_ssn_date,
hf_cip_ssupervisor_output_cp_owners_ocpunid_ssn_time,
hf_cip_ssupervisor_output_cp_owners_ocpunid_macid,
ett_ssupervisor_output_cp_owners_ocpunid,
ett_ssupervisor_output_cp_owners_ocpunid_ssn);
attr_len += 10;
proto_tree_add_item(entry_tree, hf_cip_ssupervisor_cp_owners_app_path_size,
tvb, offset+attr_len, 1, ENC_LITTLE_ENDIAN );
app_path_size = tvb_get_guint8( tvb, offset+attr_len);
attr_len += 1;
if (total_len < attr_len+app_path_size)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_cp_owners_app_path_size);
return total_len;
}
epath_tree = proto_tree_add_subtree(entry_tree,
tvb, offset+attr_len, app_path_size, ett_path, &app_path_item, "Application Resource: ");
dissect_epath(tvb, pinfo, epath_tree, app_path_item, offset+attr_len, app_path_size, FALSE, TRUE, NULL, NULL, NO_DISPLAY, NULL, FALSE);
attr_len += app_path_size;
}
}
return attr_len;
}
static int dissect_s_supervisor_proposed_tunid(packet_info *pinfo, proto_tree *tree _U_, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
if (total_len < 10)
{
expert_add_info(pinfo, item, &ei_mal_ssupervisor_proposed_tunid);
return total_len;
}
dissect_unid(tvb, pinfo, offset, item, "Proposed TUNID SSN",
hf_cip_ssupervisor_proposed_tunid_ssn_timestamp,
hf_cip_ssupervisor_proposed_tunid_ssn_date,
hf_cip_ssupervisor_proposed_tunid_ssn_time,
hf_cip_ssupervisor_proposed_tunid_macid,
ett_ssupervisor_proposed_tunid,
ett_ssupervisor_proposed_tunid_ssn);
return 10;
}
static int dissect_s_validator_type(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
proto_item *pi;
proto_tree *item_tree;
if (total_len < 1)
{
expert_add_info(pinfo, item, &ei_mal_svalidator_type);
return total_len;
}
pi = proto_tree_add_item(tree, hf_cip_svalidator_type, tvb, offset, 1, ENC_LITTLE_ENDIAN );
item_tree = proto_item_add_subtree(pi, ett_svalidator_type);
proto_tree_add_item(item_tree, hf_cip_svalidator_type_pc, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_tree_add_item(item_tree, hf_cip_svalidator_type_conn_type, tvb, offset, 1, ENC_LITTLE_ENDIAN );
return 1;
}
static int dissect_s_validator_time_coord_msg_min_mult(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
int i, size;
proto_tree_add_item(tree, hf_cip_svalidator_time_coord_msg_min_mult_size,
tvb, offset, 1, ENC_LITTLE_ENDIAN );
size = tvb_get_guint8( tvb, offset )*2;
if (total_len < size+1)
{
expert_add_info(pinfo, item, &ei_mal_svalidator_time_coord_msg_min_mult);
return total_len;
}
for (i = 0; i < size; i+=2)
{
proto_tree_add_item(tree, hf_cip_svalidator_time_coord_msg_min_mult_item,
tvb, offset+1+i, 2, ENC_LITTLE_ENDIAN );
}
return (size+1);
}
static int dissect_s_validator_network_time_multiplier(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
int i, size;
proto_tree_add_item(tree, hf_cip_svalidator_network_time_multiplier_size,
tvb, offset, 1, ENC_LITTLE_ENDIAN );
size = tvb_get_guint8( tvb, offset )*2;
if (total_len < size+1)
{
expert_add_info(pinfo, item, &ei_mal_svalidator_network_time_multiplier);
return total_len;
}
for (i = 0; i < size; i+=2)
{
proto_tree_add_item(tree, hf_cip_svalidator_network_time_multiplier_item,
tvb, offset+1+i, 2, ENC_LITTLE_ENDIAN );
}
return (size+1);
}
static int dissect_s_validator_timeout_multiplier(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
int i, size;
proto_tree_add_item(tree, hf_cip_svalidator_timeout_multiplier_size,
tvb, offset, 1, ENC_LITTLE_ENDIAN );
size = tvb_get_guint8( tvb, offset );
if (total_len < size+1)
{
expert_add_info(pinfo, item, &ei_mal_svalidator_timeout_multiplier);
return total_len;
}
for (i = 0; i < size; i++)
{
proto_tree_add_item(tree, hf_cip_svalidator_timeout_multiplier_item,
tvb, offset+1+i, 1, ENC_LITTLE_ENDIAN );
}
return (size+1);
}
static int dissect_s_validator_coordination_conn_inst(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
int i, size;
proto_tree_add_item(tree, hf_cip_svalidator_coordination_conn_inst_size,
tvb, offset, 1, ENC_LITTLE_ENDIAN );
size = tvb_get_guint8( tvb, offset )*2;
if (total_len < size+1)
{
expert_add_info(pinfo, item, &ei_mal_svalidator_coordination_conn_inst);
return total_len;
}
for (i = 0; i < size; i+=2)
{
proto_tree_add_item(tree, hf_cip_svalidator_coordination_conn_inst_item,
tvb, offset+1+i, 2, ENC_LITTLE_ENDIAN );
}
return (size+1);
}
static int dissect_s_validator_app_data_path(packet_info *pinfo, proto_tree *tree,
proto_item *item _U_, tvbuff_t *tvb, int offset, int total_len)
{
proto_item* pi;
proto_tree* epath_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_path, &pi, "Application Data Path: ");
dissect_epath(tvb, pinfo, epath_tree, pi, offset, total_len, FALSE, FALSE, NULL, NULL, NO_DISPLAY, NULL, FALSE);
return total_len;
}
static int dissect_s_validator_prod_cons_fault_count(packet_info *pinfo, proto_tree *tree, proto_item *item,
tvbuff_t *tvb, int offset, int total_len)
{
int i, size;
proto_tree_add_item(tree, hf_cip_svalidator_prod_cons_fault_count_size,
tvb, offset, 1, ENC_LITTLE_ENDIAN );
size = tvb_get_guint8( tvb, offset );
if (total_len < size+1)
{
expert_add_info(pinfo, item, &ei_mal_svalidator_prod_cons_fault_count);
return total_len;
}
for (i = 0; i < size; i++)
{
proto_tree_add_item(tree, hf_cip_svalidator_prod_cons_fault_count_item,
tvb, offset+1+i, 1, ENC_LITTLE_ENDIAN );
}
return (size+1);
}
static void
dissect_cip_s_validator_data( proto_tree *item_tree,
tvbuff_t *tvb, int offset, int item_length, packet_info *pinfo )
{
proto_item *pi, *rrsc_item;
proto_tree *rrsc_tree, *cmd_data_tree;
int req_path_size;
guint8 service, gen_status, add_stat_size;
cip_simple_request_info_t req_data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIPS Validator");
service = tvb_get_guint8( tvb, offset );
rrsc_tree = proto_tree_add_subtree( item_tree, tvb, offset, 1, ett_svalidator_rrsc, &rrsc_item, "Service: " );
proto_tree_add_item( rrsc_tree, hf_cip_reqrsp, tvb, offset, 1, ENC_LITTLE_ENDIAN );
proto_item_append_text( rrsc_item, "%s (%s)",
val_to_str( ( service & CIP_SC_MASK ),
cip_sc_vals_svalidator , "Unknown Service (0x%02x)"),
val_to_str_const( ( service & CIP_SC_RESPONSE_MASK )>>7,
cip_sc_rr, "") );
proto_tree_add_item(rrsc_tree, hf_cip_svalidator_sc, tvb, offset, 1, ENC_LITTLE_ENDIAN );
load_cip_request_data(pinfo, &req_data);
if (service & CIP_SC_RESPONSE_MASK)
{
gen_status = tvb_get_guint8( tvb, offset+2 );
add_stat_size = tvb_get_guint8( tvb, offset+3 ) * 2;
if( ( item_length-4-add_stat_size ) != 0 )
{
cmd_data_tree = proto_tree_add_subtree( item_tree, tvb, offset+4+add_stat_size, item_length-4-add_stat_size,
ett_ssupervisor_cmd_data, &pi, "Command Specific Data" );
if( gen_status == CI_GRC_SUCCESS || gen_status == CI_GRC_SERVICE_ERROR )
{
if (((service & CIP_SC_MASK) == SC_GET_ATT_ALL) &&
(req_data.iInstance != (guint32)-1) &&
(req_data.iInstance != 0))
{
dissect_cip_get_attribute_all_rsp(tvb, pinfo, cmd_data_tree, offset + 4 + add_stat_size, &req_data);
}
else
{
proto_tree_add_item(cmd_data_tree, hf_cip_data,
tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
}
else
{
proto_tree_add_item(cmd_data_tree, hf_cip_data,
tvb, offset+4+add_stat_size, item_length-4-add_stat_size, ENC_NA);
}
}
}
else
{
req_path_size = tvb_get_guint8( tvb, offset+1 )*2;
if( (item_length-req_path_size-2) != 0 )
{
cmd_data_tree = proto_tree_add_subtree( item_tree, tvb, offset+2+req_path_size, item_length-req_path_size-2,
ett_ssupervisor_cmd_data, NULL, "Command Specific Data" );
proto_tree_add_item(cmd_data_tree, hf_cip_data,
tvb, offset+2+req_path_size, item_length-req_path_size-2, ENC_NA);
}
}
add_cip_service_to_info_column(pinfo, service, cip_sc_vals_svalidator);
}
static int
dissect_cip_class_s_validator(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *class_tree;
ti = proto_tree_add_item(tree, proto_cip_class_s_validator, tvb, 0, -1, ENC_NA);
class_tree = proto_item_add_subtree( ti, ett_cip_class_s_validator );
dissect_cip_s_validator_data( class_tree, tvb, 0, tvb_reported_length(tvb), pinfo );
return tvb_reported_length(tvb);
}
static gboolean
dissect_class_svalidator_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
unsigned char service, service_code, ioilen, segment;
cip_req_info_t* preq_info;
guint32 classid = 0;
int offset = 0;
service = tvb_get_guint8( tvb, offset );
service_code = service & CIP_SC_MASK;
if (service_code == SC_GET_ATT_ALL)
{
if (service & CIP_SC_RESPONSE_MASK)
{
preq_info = (cip_req_info_t*)p_get_proto_data(wmem_file_scope(), pinfo, proto_cip, 0);
if ((preq_info != NULL) &&
(preq_info->dissector == dissector_get_uint_handle( subdissector_class_table, CI_CLS_SAFETY_VALIDATOR)))
{
call_dissector(preq_info->dissector, tvb, pinfo, tree);
return TRUE;
}
}
else
{
ioilen = tvb_get_guint8( tvb, offset + 1 );
if (ioilen > 1)
{
segment = tvb_get_guint8( tvb, offset + 2 );
if (((segment & CI_SEGMENT_TYPE_MASK) == CI_LOGICAL_SEGMENT) &&
((segment & CI_LOGICAL_SEG_TYPE_MASK) == CI_LOGICAL_SEG_CLASS_ID))
{
switch ( segment & CI_LOGICAL_SEG_FORMAT_MASK )
{
case CI_LOGICAL_SEG_8_BIT:
classid = tvb_get_guint8( tvb, offset + 3 );
break;
case CI_LOGICAL_SEG_16_BIT:
if ( ioilen >= 2 )
classid = tvb_get_letohs( tvb, offset + 4 );
break;
case CI_LOGICAL_SEG_32_BIT:
if ( ioilen >= 3 )
classid = tvb_get_letohl( tvb, offset + 4 );
break;
}
}
}
if (classid == CI_CLS_SAFETY_VALIDATOR)
{
call_dissector(cip_class_s_validator_handle, tvb, pinfo, tree );
return TRUE;
}
}
}
return FALSE;
}
static guint8 compute_crc_s1_pid(guint16 conn_serial_number, guint16 vendor_id, guint32 device_serial_number)
{
guint8 temp_buf[8];
memcpy(temp_buf, &vendor_id, 2);
memcpy(&temp_buf[2], &device_serial_number, 4);
memcpy(&temp_buf[6], &conn_serial_number, 2);
return crc8_0x37(temp_buf, 8, 0);
}
static guint8 compute_crc_s1_timestamp(guint8 pid_seed, guint8 mode_byte_mask, guint16 timestamp)
{
guint8 mode_byte_crc = crc8_0x37(&mode_byte_mask, 1, pid_seed);
guint8 timestamp_crc = crc8_0x37((guint8*)&timestamp, 2, mode_byte_crc);
return timestamp_crc;
}
static guint8 compute_crc_s1_data(guint8 pid_seed, guint8 mode_byte_mask, guint8 *buf, int len)
{
guint8 mode_byte_crc = crc8_0x37(&mode_byte_mask, 1, pid_seed);
return crc8_0x37(buf, len, mode_byte_crc);
}
static guint8 compute_crc_s2_data(guint8 pid_seed, guint8 mode_byte_mask, guint8 *comp_buf, int len)
{
int i;
guint8 mode_byte_crc = crc8_0x3B(&mode_byte_mask, 1, pid_seed);
for (i = 0; i < len; i++)
comp_buf[i] ^= 0xFF;
return crc8_0x3B(comp_buf, len, mode_byte_crc);
}
static guint16 compute_crc_s3_pid(guint16 conn_serial_number, guint16 vendor_id, guint32 device_serial_number)
{
guint8 temp_buf[8];
memcpy(temp_buf, &vendor_id, 2);
memcpy(&temp_buf[2], &device_serial_number, 4);
memcpy(&temp_buf[6], &conn_serial_number, 2);
return crc16_0x080F_seed(temp_buf, 8, 0);
}
static guint16 compute_crc_s3_base_data(guint16 pid_seed, guint8 mode_byte_mask, guint8 *buf, int len)
{
guint16 mode_byte_crc = crc16_0x080F_seed(&mode_byte_mask, 1, pid_seed);
return crc16_0x080F_seed(buf, len, mode_byte_crc);
}
static guint16 compute_crc_s3_extended_data(guint16 pid_seed, guint16 rollover_value, guint8 mode_byte_mask, guint8 *buf, int len)
{
guint16 rollover_crc = crc16_0x080F_seed((guint8*)&rollover_value, 2, pid_seed);
guint16 mode_byte_crc = crc16_0x080F_seed(&mode_byte_mask, 1, rollover_crc);
return crc16_0x080F_seed(buf, len, mode_byte_crc);
}
static guint16 compute_crc_s3_time(guint16 pid_seed, guint8 ack_mcast_byte, guint16 timestamp_value)
{
guint16 mode_byte_crc = crc16_0x080F_seed(&ack_mcast_byte, 1, pid_seed);
guint16 timestamp_crc;
timestamp_crc = crc16_0x080F_seed((guint8*)&timestamp_value, 2, mode_byte_crc);
return timestamp_crc;
}
static guint32 compute_crc_s5_pid(guint16 conn_serial_number, guint16 vendor_id, guint32 device_serial_number)
{
guint8 temp_buf[8];
memcpy(temp_buf, &vendor_id, 2);
memcpy(&temp_buf[2], &device_serial_number, 4);
memcpy(&temp_buf[6], &conn_serial_number, 2);
return crc32_0x5D6DCB_seed(temp_buf, 8, 0);
}
static guint32 compute_crc_s5_short_data(guint32 pid_seed, guint16 rollover_value, guint8 mode_byte_mask, guint16 timestamp_value, guint8 *buf, int len)
{
guint32 rollover_crc = crc32_0x5D6DCB_seed((guint8*)&rollover_value, 2, pid_seed);
guint32 mode_byte_crc = crc32_0x5D6DCB_seed(&mode_byte_mask, 1, rollover_crc);
guint32 data_crc, timestamp_crc;
data_crc = crc32_0x5D6DCB_seed(buf, len, mode_byte_crc);
timestamp_crc = crc32_0x5D6DCB_seed((guint8*)&timestamp_value, 2, data_crc);
return timestamp_crc;
}
static guint32 compute_crc_s5_long_data(guint32 pid_seed, guint16 rollover_value, guint8 mode_byte_mask, guint16 timestamp_value, guint8 *comp_buf, int len)
{
int i;
guint32 rollover_crc = crc32_0x5D6DCB_seed((guint8*)&rollover_value, 2, pid_seed);
guint32 mode_byte_crc = crc32_0x5D6DCB_seed(&mode_byte_mask, 1, rollover_crc);
guint32 comp_data_crc, timestamp_crc;
for (i = 0; i < len; i++)
comp_buf[i] ^= 0xFF;
comp_data_crc = crc32_0x5D6DCB_seed(comp_buf, len, mode_byte_crc);
timestamp_crc = crc32_0x5D6DCB_seed((guint8*)&timestamp_value, 2, comp_data_crc);
return timestamp_crc;
}
static guint32 compute_crc_s5_time(guint32 pid_seed, guint8 ack_mcast_byte, guint16 timestamp_value)
{
guint32 mode_byte_crc = crc32_0x5D6DCB_seed(&ack_mcast_byte, 1, pid_seed);
guint32 timestamp_crc;
timestamp_crc = crc32_0x5D6DCB_seed((guint8*)&timestamp_value, 2, mode_byte_crc);
return timestamp_crc;
}
static gboolean verify_compliment_data(tvbuff_t *tvb, int data_offset, int complement_data_offset, int data_size)
{
const guint8 *data = tvb_get_ptr(tvb, data_offset, data_size);
const guint8 *complement_data = tvb_get_ptr(tvb, complement_data_offset, data_size);
int i;
for (i = 0; i < data_size; i++)
{
if ((data[i] ^ complement_data[i])!= 0xFF)
return FALSE;
}
return TRUE;
}
static void
dissect_mode_byte( proto_tree *tree, tvbuff_t *tvb, int offset, packet_info *pinfo)
{
proto_item *mode_item, *run_idle_item, *tbd_item, *tbd2_item;
proto_tree *mode_tree;
guint8 mode_byte;
mode_byte = tvb_get_guint8(tvb, offset);
mode_item = proto_tree_add_item(tree, hf_cipsafety_mode_byte, tvb, offset, 1, ENC_LITTLE_ENDIAN);
mode_tree = proto_item_add_subtree( mode_item, ett_cipsafety_mode_byte);
proto_tree_add_item(mode_tree, hf_cipsafety_mode_byte_ping_count, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_cipsafety_mode_byte_not_tbd, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_cipsafety_mode_byte_tbd_2_copy, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mode_tree, hf_cipsafety_mode_byte_not_run_idle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tbd_item = proto_tree_add_item(mode_tree, hf_cipsafety_mode_byte_tbd, tvb, offset, 1, ENC_LITTLE_ENDIAN);
tbd2_item = proto_tree_add_item(mode_tree, hf_cipsafety_mode_byte_tbd_2_bit, tvb, offset, 1, ENC_LITTLE_ENDIAN);
run_idle_item = proto_tree_add_item(mode_tree, hf_cipsafety_mode_byte_run_idle, tvb, offset, 1, ENC_LITTLE_ENDIAN);
if ((((mode_byte & 0x20) >> 5) & 0x01) == (((mode_byte & 0x04) >> 2) & 0x01))
expert_add_info(pinfo, tbd_item, &ei_cipsafety_tbd2_not_complemented);
if ((((mode_byte & 0x40) >> 6) & 0x01) != (((mode_byte & 0x08) >> 3) & 0x01))
expert_add_info(pinfo, tbd2_item, &ei_cipsafety_tbd_not_copied);
if ((((mode_byte & 0x80) >> 7) & 0x01) == (((mode_byte & 0x10) >> 4) & 0x01))
expert_add_info(pinfo, run_idle_item, &ei_cipsafety_run_idle_not_complemented);
}
static void
dissect_ack_byte( proto_tree *tree, tvbuff_t *tvb, int offset, packet_info *pinfo _U_)
{
proto_item *ack_item;
proto_tree *ack_tree;
#if 0
guint8 ack_byte;
ack_byte = tvb_get_guint8(tvb, offset);
#endif
if (!tree)
return;
ack_item = proto_tree_add_item(tree, hf_cipsafety_ack_byte, tvb, offset, 1, ENC_LITTLE_ENDIAN);
ack_tree = proto_item_add_subtree( ack_item, ett_cipsafety_ack_byte);
proto_tree_add_item(ack_tree, hf_cipsafety_ack_byte_ping_count_reply, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ack_tree, hf_cipsafety_ack_byte_reserved1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ack_tree, hf_cipsafety_ack_byte_ping_response, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ack_tree, hf_cipsafety_ack_byte_reserved2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ack_tree, hf_cipsafety_ack_byte_parity_even, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_mcast_byte( proto_tree *tree, tvbuff_t *tvb, int offset, packet_info *pinfo _U_)
{
proto_item *mcast_item;
proto_tree *mcast_tree;
#if 0
guint8 mcast_byte;
mcast_byte = tvb_get_guint8(tvb, offset);
#endif
mcast_item = proto_tree_add_item(tree, hf_cipsafety_mcast_byte, tvb, offset, 1, ENC_LITTLE_ENDIAN);
mcast_tree = proto_item_add_subtree( mcast_item, ett_cipsafety_mcast_byte);
proto_tree_add_item(mcast_tree, hf_cipsafety_mcast_byte_consumer_num, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcast_tree, hf_cipsafety_mcast_byte_reserved1, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcast_tree, hf_cipsafety_mcast_byte_mai, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcast_tree, hf_cipsafety_mcast_byte_reserved2, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(mcast_tree, hf_cipsafety_mcast_byte_parity_even, tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
static void
dissect_cip_safety_data( proto_tree *tree, proto_item *item, tvbuff_t *tvb, int item_length, packet_info *pinfo, cip_safety_info_t* safety_info)
{
int base_length, io_data_size;
gboolean multicast = (((pntoh32(pinfo->dst.data)) & 0xf0000000) == 0xe0000000);
gboolean server_dir = FALSE;
enum enip_connid_type conn_type = ECIDT_UNKNOWN;
enum cip_safety_format_type format = CIP_SAFETY_BASE_FORMAT;
guint16 timestamp, conn_sn = 0, vendorID = 0;
guint8 mode_byte;
guint32 device_sn = 0;
cip_safety_packet_data_t* packet_data = NULL;
guint32 test_crc_c5, value_c5 = 0, tmp_c5;
proto_item *complement_item, *crc_s5_item, *crc_s5_status_item;
gboolean short_format = TRUE;
gboolean compute_crc = ((safety_info != NULL) && (safety_info->eip_conn_info != NULL));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CIP Safety");
if (safety_info != NULL && safety_info->eip_conn_info != NULL)
{
conn_type = safety_info->conn_type;
format = safety_info->eip_conn_info->safety.format;
server_dir = (safety_info->eip_conn_info->TransportClass_trigger & CI_PRODUCTION_DIR_MASK) ? TRUE : FALSE;
}
base_length = multicast ? 12 : 6;
if (((conn_type == ECIDT_O2T) && (server_dir == FALSE)) ||
((conn_type == ECIDT_T2O) && (server_dir == TRUE)))
{
if (compute_crc)
{
if ((conn_type == ECIDT_O2T) && (server_dir == FALSE))
{
conn_sn = safety_info->eip_conn_info->ConnSerialNumber;
vendorID = safety_info->eip_conn_info->VendorID;
device_sn = safety_info->eip_conn_info->DeviceSerialNumber;
}
else
{
conn_sn = safety_info->eip_conn_info->safety.target_conn_sn;
vendorID = safety_info->eip_conn_info->safety.target_vendorID;
device_sn = safety_info->eip_conn_info->safety.target_device_sn;
}
}
dissect_ack_byte(tree, tvb, 0, pinfo);
proto_tree_add_item(tree, hf_cipsafety_consumer_time_value, tvb, 1, 2, ENC_LITTLE_ENDIAN);
timestamp = tvb_get_letohs(tvb, 1);
switch (format)
{
case CIP_SAFETY_BASE_FORMAT:
proto_tree_add_item(tree, hf_cipsafety_ack_byte2, tvb, 3, 1, ENC_LITTLE_ENDIAN);
if (compute_crc)
{
proto_tree_add_checksum(tree, tvb, 4,
hf_cipsafety_crc_s3, hf_cipsafety_crc_s3_status, &ei_cipsafety_crc_s3, pinfo,
compute_crc_s3_time(compute_crc_s3_pid(conn_sn, vendorID, device_sn),
tvb_get_guint8(tvb, 0),
timestamp),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
else
{
proto_tree_add_checksum(tree, tvb, 4,
hf_cipsafety_crc_s3, hf_cipsafety_crc_s3_status, &ei_cipsafety_crc_s3,
pinfo, 0, ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
break;
case CIP_SAFETY_EXTENDED_FORMAT:
proto_tree_add_item(tree, hf_cipsafety_crc_s5_0, tvb, 3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_1, tvb, 4, 1, ENC_LITTLE_ENDIAN);
crc_s5_item = proto_tree_add_item(tree, hf_cipsafety_crc_s5_2, tvb, 5, 1, ENC_LITTLE_ENDIAN);
if (compute_crc)
{
test_crc_c5 = compute_crc_s5_time(compute_crc_s5_pid(conn_sn, vendorID, device_sn),
tvb_get_guint8(tvb, 0),
timestamp);
tmp_c5 = tvb_get_guint8(tvb, 3);
value_c5 = tmp_c5;
tmp_c5 = tvb_get_guint8(tvb, 4);
value_c5 += ((tmp_c5 << 8) & 0xFF00);
tmp_c5 = tvb_get_guint8(tvb, 5);
value_c5 += ((tmp_c5 << 16) & 0xFF0000);
if (test_crc_c5 == value_c5)
{
proto_item_append_text(crc_s5_item, " [correct]");
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, 5, 0, PROTO_CHECKSUM_E_GOOD);
}
else
{
proto_item_append_text(crc_s5_item, " incorrect, should be 0x%08x", test_crc_c5);
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, 5, 0, PROTO_CHECKSUM_E_BAD);
expert_add_info_format(pinfo, crc_s5_item, &ei_cipsafety_crc_s5, "Bad checksum [should be 0x%08x]", test_crc_c5);
}
}
else
{
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, 5, 0, PROTO_CHECKSUM_E_UNVERIFIED);
}
PROTO_ITEM_SET_GENERATED(crc_s5_status_item);
break;
}
}
else if (((conn_type == ECIDT_O2T) && (server_dir == TRUE)) ||
((conn_type == ECIDT_T2O) && (server_dir == FALSE)))
{
if (compute_crc)
{
if ((conn_type == ECIDT_O2T) && (server_dir == TRUE))
{
conn_sn = safety_info->eip_conn_info->ConnSerialNumber;
vendorID = safety_info->eip_conn_info->VendorID;
device_sn = safety_info->eip_conn_info->DeviceSerialNumber;
}
else
{
conn_sn = safety_info->eip_conn_info->safety.target_conn_sn;
vendorID = safety_info->eip_conn_info->safety.target_vendorID;
device_sn = safety_info->eip_conn_info->safety.target_device_sn;
}
}
if (item_length-base_length > 2)
short_format = FALSE;
switch (format)
{
case CIP_SAFETY_BASE_FORMAT:
if (short_format)
{
io_data_size = item_length-base_length;
proto_tree_add_item(tree, hf_cipsafety_data, tvb, 0, io_data_size, ENC_NA);
dissect_mode_byte(tree, tvb, io_data_size, pinfo);
mode_byte = tvb_get_guint8(tvb, io_data_size);
if (compute_crc)
{
proto_tree_add_checksum(tree, tvb, io_data_size+1,
hf_cipsafety_crc_s1, hf_cipsafety_crc_s1_status, &ei_cipsafety_crc_s1, pinfo,
compute_crc_s1_data(compute_crc_s1_pid(conn_sn, vendorID, device_sn),
(mode_byte & MODE_BYTE_CRC_S1_MASK),
(guint8*)tvb_get_ptr(tvb, 0, io_data_size), io_data_size),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
proto_tree_add_checksum(tree, tvb, io_data_size+2,
hf_cipsafety_crc_s2, hf_cipsafety_crc_s2_status, &ei_cipsafety_crc_s2, pinfo,
compute_crc_s2_data(compute_crc_s1_pid(conn_sn, vendorID, device_sn),
((mode_byte ^ 0xFF) & MODE_BYTE_CRC_S1_MASK),
(guint8*)tvb_memdup(wmem_packet_scope(), tvb, 0, io_data_size), io_data_size),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
else
{
proto_tree_add_checksum(tree, tvb, io_data_size+1,
hf_cipsafety_crc_s1, hf_cipsafety_crc_s1_status, &ei_cipsafety_crc_s1,
pinfo, 0, ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
proto_tree_add_checksum(tree, tvb, io_data_size+2,
hf_cipsafety_crc_s2, hf_cipsafety_crc_s2_status, &ei_cipsafety_crc_s2,
pinfo, 0, ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
proto_tree_add_item(tree, hf_cipsafety_timestamp, tvb, io_data_size+3, 2, ENC_LITTLE_ENDIAN);
timestamp = tvb_get_letohs(tvb, io_data_size+3);
if (compute_crc)
{
proto_tree_add_checksum(tree, tvb, io_data_size+5,
hf_cipsafety_crc_s1, hf_cipsafety_crc_s1_status, &ei_cipsafety_crc_s1, pinfo,
compute_crc_s1_timestamp(compute_crc_s1_pid(conn_sn, vendorID, device_sn),
(mode_byte & MODE_BYTE_CRC_S1_TIME_STAMP_MASK),
timestamp),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
else
{
proto_tree_add_checksum(tree, tvb, io_data_size+5,
hf_cipsafety_crc_s1, hf_cipsafety_crc_s1_status, &ei_cipsafety_crc_s1,
pinfo, 0, ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
if (multicast)
{
dissect_mcast_byte(tree, tvb, item_length-6, pinfo);
proto_tree_add_item(tree, hf_cipsafety_time_correction, tvb, item_length-5, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_mcast_byte2, tvb, item_length-3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s3, tvb, item_length-2, 2, ENC_LITTLE_ENDIAN);
}
}
else
{
if (item_length%2 == 1)
{
expert_add_info(pinfo, item, &ei_mal_io);
return;
}
io_data_size = multicast ? ((item_length-14)/2) : ((item_length-8)/2);
proto_tree_add_item(tree, hf_cipsafety_data, tvb, 0, io_data_size, ENC_NA);
dissect_mode_byte(tree, tvb, io_data_size, pinfo);
mode_byte = tvb_get_guint8(tvb, io_data_size);
if (compute_crc)
{
proto_tree_add_checksum(tree, tvb, io_data_size+1,
hf_cipsafety_crc_s3, hf_cipsafety_crc_s3_status, &ei_cipsafety_crc_s3, pinfo,
compute_crc_s3_base_data(compute_crc_s3_pid(conn_sn, vendorID, device_sn),
mode_byte & MODE_BYTE_CRC_S3_MASK, (guint8*)tvb_get_ptr(tvb, 0, io_data_size), io_data_size),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
else
{
proto_tree_add_checksum(tree, tvb, io_data_size+1,
hf_cipsafety_crc_s3, hf_cipsafety_crc_s3_status, &ei_cipsafety_crc_s3,
pinfo, 0, ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
complement_item = proto_tree_add_item(tree, hf_cipsafety_complement_data, tvb, io_data_size+3, io_data_size, ENC_NA);
if (!verify_compliment_data(tvb, 0, io_data_size+3, io_data_size))
expert_add_info(pinfo, complement_item, &ei_cipsafety_not_complement_data);
if (compute_crc)
{
proto_tree_add_checksum(tree, tvb, (io_data_size*2)+3,
hf_cipsafety_complement_crc_s3, hf_cipsafety_complement_crc_s3_status, &ei_cipsafety_complement_crc_s3, pinfo,
compute_crc_s3_base_data(compute_crc_s3_pid(conn_sn, vendorID, device_sn),
((mode_byte ^ 0xFF) & MODE_BYTE_CRC_S3_MASK),
(guint8*)tvb_get_ptr(tvb, io_data_size+3, io_data_size), io_data_size),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
else
{
proto_tree_add_checksum(tree, tvb, (io_data_size*2)+3,
hf_cipsafety_complement_crc_s3, hf_cipsafety_complement_crc_s3_status, &ei_cipsafety_complement_crc_s3,
pinfo, 0, ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
proto_tree_add_item(tree, hf_cipsafety_timestamp, tvb, (io_data_size*2)+5, 2, ENC_LITTLE_ENDIAN);
timestamp = tvb_get_letohs(tvb, (io_data_size*2)+5);
if (compute_crc)
{
proto_tree_add_checksum(tree, tvb, (io_data_size*2)+7,
hf_cipsafety_crc_s1, hf_cipsafety_crc_s1_status, &ei_cipsafety_crc_s1, pinfo,
compute_crc_s1_timestamp(compute_crc_s1_pid(conn_sn, vendorID, device_sn),
(mode_byte & MODE_BYTE_CRC_S1_TIME_STAMP_MASK),
timestamp),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
else
{
proto_tree_add_checksum(tree, tvb, (io_data_size*2)+7,
hf_cipsafety_crc_s1, hf_cipsafety_crc_s1_status, &ei_cipsafety_crc_s1,
pinfo, 0, ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
if (multicast)
{
dissect_mcast_byte(tree, tvb, (io_data_size*2)+5, pinfo);
proto_tree_add_item(tree, hf_cipsafety_time_correction, tvb, (io_data_size*2)+6, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_mcast_byte2, tvb, (io_data_size*2)+8, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s3, tvb, (io_data_size*2)+9, 2, ENC_LITTLE_ENDIAN);
}
}
break;
case CIP_SAFETY_EXTENDED_FORMAT:
if (short_format)
{
io_data_size = item_length-base_length;
timestamp = tvb_get_letohs(tvb, io_data_size+3);
}
else
{
io_data_size = multicast ? ((item_length-14)/2) : ((item_length-8)/2);
timestamp = tvb_get_letohs(tvb, (io_data_size*2)+5);
}
mode_byte = tvb_get_guint8(tvb, io_data_size);
if (compute_crc)
{
if (!pinfo->fd->flags.visited)
{
if ((timestamp != 0) && (timestamp < safety_info->eip_conn_info->safety.running_timestamp_value))
{
safety_info->eip_conn_info->safety.running_rollover_value++;
}
safety_info->eip_conn_info->safety.running_timestamp_value = timestamp;
packet_data = wmem_new0(wmem_file_scope(), cip_safety_packet_data_t);
packet_data->rollover_value = safety_info->eip_conn_info->safety.running_rollover_value;
p_add_proto_data(wmem_file_scope(), pinfo, proto_cipsafety, 0, packet_data);
}
else
{
packet_data = (cip_safety_packet_data_t*)p_get_proto_data(wmem_file_scope(), pinfo, proto_cipsafety, 0);
}
}
if (short_format)
{
proto_tree_add_item(tree, hf_cipsafety_data, tvb, 0, io_data_size, ENC_NA);
dissect_mode_byte(tree, tvb, io_data_size, pinfo);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_0, tvb, io_data_size+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_1, tvb, io_data_size+2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_timestamp, tvb, io_data_size+3, 2, ENC_LITTLE_ENDIAN);
crc_s5_item = proto_tree_add_item(tree, hf_cipsafety_crc_s5_2, tvb, io_data_size+5, 1, ENC_LITTLE_ENDIAN);
if (compute_crc && (packet_data != NULL))
{
test_crc_c5 = compute_crc_s5_short_data(compute_crc_s5_pid(conn_sn, vendorID, device_sn),
((timestamp != 0) ? packet_data->rollover_value : 0), mode_byte & MODE_BYTE_CRC_S5_BASE_MASK, timestamp,
(guint8*)tvb_get_ptr(tvb, 0, io_data_size), io_data_size);
tmp_c5 = tvb_get_guint8(tvb, io_data_size+1);
value_c5 = tmp_c5;
tmp_c5 = tvb_get_guint8(tvb, io_data_size+2);
value_c5 += ((tmp_c5 << 8) & 0xFF00);
tmp_c5 = tvb_get_guint8(tvb, io_data_size+5);
value_c5 += ((tmp_c5 << 16) & 0xFF0000);
if (test_crc_c5 == value_c5)
{
proto_item_append_text(crc_s5_item, " [correct]");
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, io_data_size+5, 0, PROTO_CHECKSUM_E_GOOD);
}
else
{
proto_item_append_text(crc_s5_item, " incorrect, should be 0x%08x", test_crc_c5);
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, io_data_size+5, 0, PROTO_CHECKSUM_E_BAD);
expert_add_info_format(pinfo, crc_s5_item, &ei_cipsafety_crc_s5, "Bad checksum [should be 0x%08x]", test_crc_c5);
}
}
else
{
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, io_data_size+5, 0, PROTO_CHECKSUM_E_UNVERIFIED);
}
PROTO_ITEM_SET_GENERATED(crc_s5_status_item);
if (multicast)
{
dissect_mcast_byte(tree, tvb, item_length-6, pinfo);
proto_tree_add_item(tree, hf_cipsafety_time_correction, tvb, item_length-5, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_0, tvb, item_length-3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_1, tvb, item_length-2, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_2, tvb, item_length-1, 1, ENC_LITTLE_ENDIAN);
}
}
else
{
if (item_length%2 == 1)
{
expert_add_info(pinfo, item, &ei_mal_io);
return;
}
proto_tree_add_item(tree, hf_cipsafety_data, tvb, 0, io_data_size, ENC_NA);
dissect_mode_byte(tree, tvb, io_data_size, pinfo);
if (compute_crc)
{
if (!pinfo->fd->flags.visited)
{
if ((timestamp != 0) && (timestamp < safety_info->eip_conn_info->safety.running_timestamp_value))
{
safety_info->eip_conn_info->safety.running_rollover_value++;
}
safety_info->eip_conn_info->safety.running_timestamp_value = timestamp;
packet_data = wmem_new0(wmem_file_scope(), cip_safety_packet_data_t);
packet_data->rollover_value = safety_info->eip_conn_info->safety.running_rollover_value;
p_add_proto_data(wmem_file_scope(), pinfo, proto_cipsafety, 0, packet_data);
}
else
{
packet_data = (cip_safety_packet_data_t*)p_get_proto_data(wmem_file_scope(), pinfo, proto_cipsafety, 0);
}
if (packet_data != NULL)
{
proto_tree_add_checksum(tree, tvb, io_data_size+1,
hf_cipsafety_crc_s3, hf_cipsafety_crc_s3_status, &ei_cipsafety_crc_s3, pinfo,
compute_crc_s3_extended_data(compute_crc_s3_pid(conn_sn, vendorID, device_sn),
((timestamp != 0) ? packet_data->rollover_value : 0), mode_byte & MODE_BYTE_CRC_S3_MASK, (guint8*)tvb_get_ptr(tvb, 0, io_data_size), io_data_size),
ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_VERIFY);
}
}
else
{
proto_tree_add_checksum(tree, tvb, io_data_size+1,
hf_cipsafety_crc_s3, hf_cipsafety_crc_s3_status, &ei_cipsafety_crc_s3,
pinfo, 0, ENC_LITTLE_ENDIAN, PROTO_CHECKSUM_NO_FLAGS);
}
complement_item = proto_tree_add_item(tree, hf_cipsafety_complement_data, tvb, io_data_size+3, io_data_size, ENC_NA);
if (!verify_compliment_data(tvb, 0, io_data_size+3, io_data_size))
expert_add_info(pinfo, complement_item, &ei_cipsafety_not_complement_data);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_0, tvb, (io_data_size*2)+3, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_1, tvb, (io_data_size*2)+4, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_timestamp, tvb, (io_data_size*2)+5, 2, ENC_LITTLE_ENDIAN);
crc_s5_item = proto_tree_add_item(tree, hf_cipsafety_crc_s5_2, tvb, (io_data_size*2)+7, 1, ENC_LITTLE_ENDIAN);
if (compute_crc && (packet_data != NULL))
{
test_crc_c5 = compute_crc_s5_long_data(compute_crc_s5_pid(conn_sn, vendorID, device_sn),
((timestamp != 0) ? packet_data->rollover_value : 0), mode_byte & MODE_BYTE_CRC_S5_EXTENDED_MASK, timestamp,
(guint8*)tvb_memdup(wmem_packet_scope(), tvb, 0, io_data_size), io_data_size);
tmp_c5 = tvb_get_guint8(tvb, (io_data_size*2)+3);
value_c5 = tmp_c5;
tmp_c5 = tvb_get_guint8(tvb, (io_data_size*2)+4);
value_c5 += ((tmp_c5 << 8) & 0xFF00);
tmp_c5 = tvb_get_guint8(tvb, (io_data_size*2)+7);
value_c5 += ((tmp_c5 << 16) & 0xFF0000);
if (test_crc_c5 == value_c5)
{
proto_item_append_text(crc_s5_item, " [correct]");
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, (io_data_size*2)+7, 0, PROTO_CHECKSUM_E_GOOD);
}
else
{
proto_item_append_text(crc_s5_item, " incorrect, should be 0x%08x", test_crc_c5);
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, (io_data_size*2)+7, 0, PROTO_CHECKSUM_E_BAD);
expert_add_info_format(pinfo, crc_s5_item, &ei_cipsafety_crc_s5, "Bad checksum [should be 0x%08x]", test_crc_c5);
}
}
else
{
crc_s5_status_item = proto_tree_add_uint(tree, hf_cipsafety_crc_s5_status, tvb, (io_data_size*2)+7, 0, PROTO_CHECKSUM_E_UNVERIFIED);
}
PROTO_ITEM_SET_GENERATED(crc_s5_status_item);
if (multicast)
{
dissect_mcast_byte(tree, tvb, (io_data_size*2)+8, pinfo);
proto_tree_add_item(tree, hf_cipsafety_time_correction, tvb, (io_data_size*2)+9, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_0, tvb, (io_data_size*2)+11, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_1, tvb, (io_data_size*2)+12, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_cipsafety_crc_s5_2, tvb, (io_data_size*2)+13, 1, ENC_LITTLE_ENDIAN);
}
}
break;
}
}
else
{
proto_tree_add_item(tree, hf_cipsafety_data, tvb, 0, item_length, ENC_NA);
}
}
static int
dissect_cipsafety(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ti;
proto_tree *safety_tree;
cip_safety_info_t* safety_info = (cip_safety_info_t*)data;
ti = proto_tree_add_item(tree, proto_cipsafety, tvb, 0, -1, ENC_NA);
safety_tree = proto_item_add_subtree( ti, ett_cip_safety);
dissect_cip_safety_data(safety_tree, ti, tvb, tvb_reported_length(tvb), pinfo, safety_info);
return tvb_captured_length(tvb);
}
static int dissect_sercosiii_link_error_count_p1p2(packet_info *pinfo, proto_tree *tree, proto_item *item, tvbuff_t *tvb,
int offset, int total_len)
{
if (total_len < 4)
{
expert_add_info(pinfo, item, &ei_mal_sercosiii_link_error_count_p1p2);
return total_len;
}
proto_tree_add_item(tree, hf_cip_sercosiii_link_error_count_p1, tvb, offset, 2, ENC_LITTLE_ENDIAN );
proto_tree_add_item(tree, hf_cip_sercosiii_link_error_count_p2, tvb, offset+2, 2, ENC_LITTLE_ENDIAN );
return 4;
}
static int dissect_sercosiii_safety_network_number(packet_info *pinfo _U_, proto_tree *tree, proto_item *item _U_, tvbuff_t *tvb,
int offset, int total_len _U_)
{
proto_tree_add_item(tree, hf_cip_sercosiii_link_snn, tvb, offset, 6, ENC_NA);
return 6;
}
void
proto_register_cipsafety(void)
{
static hf_register_info hf[] =
{
{ &hf_cip_reqrsp,
{ "Request/Response", "cip.rr",
FT_UINT8, BASE_HEX, VALS(cip_sc_rr), CIP_SC_RESPONSE_MASK, "Request or Response message", HFILL }
},
{ &hf_cip_data,
{ "Data", "cip.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_data,
{ "Data", "enip.connection_transport_data",
FT_BYTES, BASE_NONE, NULL, 0, "Connection Transport Data", HFILL }
},
{ &hf_cipsafety_mode_byte,
{ "Mode Byte", "cipsafety.mode_byte",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_mode_byte_ping_count,
{ "Ping Count", "cipsafety.mode_byte.ping_count",
FT_UINT8, BASE_DEC, NULL, 0x03, NULL, HFILL }
},
{ &hf_cipsafety_mode_byte_not_tbd,
{ "Not TBD Bit", "cipsafety.mode_byte.not_tbd",
FT_BOOLEAN, 8, NULL, 0x04, NULL, HFILL }
},
{ &hf_cipsafety_mode_byte_tbd_2_copy,
{ "TBD 2 Bit Copy", "cipsafety.mode_byte.tbd_2_copy",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_cipsafety_mode_byte_not_run_idle,
{ "Not Run/Idle", "cipsafety.mode_byte.not_run_idle",
FT_BOOLEAN, 8, NULL, 0x10, NULL, HFILL }
},
{ &hf_cipsafety_mode_byte_tbd,
{ "TBD Bit", "cipsafety.mode_byte.tbd",
FT_BOOLEAN, 8, NULL, 0x20, NULL, HFILL }
},
{ &hf_cipsafety_mode_byte_tbd_2_bit,
{ "TBD 2 Bit", "cipsafety.mode_byte.tbd_2_bit",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL }
},
{ &hf_cipsafety_mode_byte_run_idle,
{ "Run/Idle", "cipsafety.mode_byte.run_idle",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }
},
{ &hf_cipsafety_crc_s1,
{ "CRC S1", "cipsafety.crc_s1",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s1_status,
{ "CRC S1 Status", "cipsafety.crc_s1.status",
FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s2,
{ "CRC S2", "cipsafety.crc_s2",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s2_status,
{ "CRC S2 Status", "cipsafety.crc_s2.status",
FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s3,
{ "CRC S3", "cipsafety.crc_s3",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s3_status,
{ "CRC S3 Status", "cipsafety.crc_s3.status",
FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0, NULL, HFILL }
},
{ &hf_cipsafety_complement_crc_s3,
{ "Complement CRC S3", "cipsafety.complement_crc_s3",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_complement_crc_s3_status,
{ "Complement CRC S3 Status", "cipsafety.complement_crc_s3.status",
FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0, NULL, HFILL }
},
{ &hf_cipsafety_timestamp,
{ "Timestamp", "cipsafety.timestamp",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_ack_byte,
{ "ACK Byte", "cipsafety.ack_byte",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_ack_byte_ping_count_reply,
{ "Ping Count Reply", "cipsafety.ack_byte.ping_count_reply",
FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL }
},
{ &hf_cipsafety_ack_byte_reserved1,
{ "Reserved", "cipsafety.ack_byte.reserved1",
FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL }
},
{ &hf_cipsafety_ack_byte_ping_response,
{ "Ping Response", "cipsafety.ack_byte.ping_response",
FT_BOOLEAN, 8, NULL, 0x08, NULL, HFILL }
},
{ &hf_cipsafety_ack_byte_reserved2,
{ "Reserved", "cipsafety.ack_byte.reserved2",
FT_UINT8, BASE_HEX, NULL, 0x70, NULL, HFILL }
},
{ &hf_cipsafety_ack_byte_parity_even,
{ "Parity Even", "cipsafety.ack_byte.parity_even",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }
},
{ &hf_cipsafety_ack_byte2,
{ "ACK Byte 2", "cipsafety.ack_byte2",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_consumer_time_value,
{ "Consumer Time Value", "cipsafety.consumer_time_value",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_mcast_byte,
{ "MCAST Byte", "cipsafety.mcast_byte",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_mcast_byte_consumer_num,
{ "Consumer #", "cipsafety.mcast_byte.consumer_num",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL }
},
{ &hf_cipsafety_mcast_byte_reserved1,
{ "Reserved", "cipsafety.mcast_byte.reserved1",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL }
},
{ &hf_cipsafety_mcast_byte_mai,
{ "Multicast Active/Idle", "cipsafety.mcast_byte.active_idle",
FT_BOOLEAN, 8, TFS(&cip_safety_vals_active_idle), 0x20, NULL, HFILL }
},
{ &hf_cipsafety_mcast_byte_reserved2,
{ "Reserved", "cipsafety.mcast_byte.reserved2",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL }
},
{ &hf_cipsafety_mcast_byte_parity_even,
{ "Parity Even", "cipsafety.mcast_byte.parity_even",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL }
},
{ &hf_cipsafety_mcast_byte2,
{ "MCAST Byte 2", "cipsafety.mcast_byte2",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_time_correction,
{ "Time Correction", "cipsafety.time_correction",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s5_0,
{ "CRC S5_0", "cipsafety.crc_s5_0",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s5_1,
{ "CRC S5_1", "cipsafety.crc_s5_1",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s5_2,
{ "CRC S5_2", "cipsafety.crc_s5_2",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cipsafety_crc_s5_status,
{ "CRC S5 Status", "cipsafety.crc_s5.status",
FT_UINT8, BASE_NONE, VALS(proto_checksum_vals), 0, NULL, HFILL }
},
{ &hf_cipsafety_complement_data,
{ "Complement Data", "cipsafety.complement_data",
FT_BYTES, BASE_NONE, NULL, 0, "Connection Transport Data", HFILL }
},
{ &hf_cip_sercosiii_link_snn,
{ "Data", "cipsafety.sercosiii_link.snn",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_sercosiii_link_communication_cycle_time,
{ "Communication Cycle Time", "cipsafety.sercosiii_link.communication_cycle_time",
FT_INT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_sercosiii_link_interface_status,
{ "Communication Cycle Time", "cipsafety.sercosiii_link.interface_status",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_sercosiii_link_error_count_mstps,
{ "Error Counter MST-P/S", "cipsafety.sercosiii_link.error_count_mstps",
FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_sercosiii_link_error_count_p1,
{ "Error Count Port 1", "cipsafety.sercosiii_link.error_count_p1",
FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_sercosiii_link_error_count_p2,
{ "Error Count Port 2", "cipsafety.sercosiii_link.error_count_p2",
FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_sercosiii_link_sercos_address,
{ "SERCOS Address", "cipsafety.sercosiii_link.sercos_address",
FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
};
static hf_register_info hf_ssupervisor[] = {
{ &hf_cip_ssupervisor_sc,
{ "Service", "cipsafety.ssupervisor.sc",
FT_UINT8, BASE_HEX, VALS(cip_sc_vals_ssupervisor), CIP_SC_MASK, NULL, HFILL }
},
{ &hf_cip_ssupervisor_recover_data,
{ "Data", "cipsafety.ssupervisor.recover.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_perform_diag_data,
{ "Data", "cipsafety.ssupervisor.perform_diag.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_password,
{ "Password", "cipsafety.ssupervisor.configure_request.password",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_tunid,
{ "Target UNID", "cipsafety.ssupervisor.configure_request.tunid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_tunid_ssn_timestamp,
{ "TUNID SSN Timestamp", "cipsafety.ssupervisor.configure_request.tunid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_tunid_ssn_date,
{ "TUNID SSN (Manual) Date", "cipsafety.ssupervisor.configure_request.tunid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_tunid_ssn_time,
{ "TUNID SSN (Manual) Time", "cipsafety.ssupervisor.configure_request.tunid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_tunid_macid,
{ "MAC ID", "cipsafety.ssupervisor.configure_request.tunid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_ounid,
{ "Originator UNID", "cipsafety.ssupervisor.configure_request.ounid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_ounid_ssn_timestamp,
{ "OUNID SSN Timestamp", "cipsafety.ssupervisor.configure_request.ounid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_ounid_ssn_date,
{ "OUNID SSN (Manual) Date", "cipsafety.ssupervisor.configure_request.ounid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_ounid_ssn_time,
{ "OUNID SSN (Manual) Time", "cipsafety.ssupervisor.configure_request.ounid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_request_ounid_macid,
{ "MAC ID", "cipsafety.ssupervisor.configure_request.ounid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_validate_configuration_sccrc,
{ "SCCRC", "cipsafety.ssupervisor.validate_configuration.sccrc",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_validate_configuration_scts_timestamp,
{ "SCTS (Timestamp)", "cipsafety.ssupervisor.validate_configuration.scts.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_validate_configuration_scts_date,
{ "SCTS (Manual) Date", "cipsafety.ssupervisor.validate_configuration.scts.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_validate_configuration_scts_time,
{ "SCTS (Manual) Time", "cipsafety.ssupervisor.validate_configuration.scts.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_validate_configuration_ext_error,
{ "Extended Error", "cipsafety.ssupervisor.validate_configuration.ext_error",
FT_UINT16, BASE_DEC, VALS(cip_ssupervisor_validate_configuration_ext_error_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_set_password_current_password,
{ "Current Password", "cipsafety.ssupervisor.set_password.current_pass",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_set_password_new_password,
{ "New Password", "cipsafety.ssupervisor.set_password.new_pass",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_lock_value,
{ "Lock Value", "cipsafety.ssupervisor.configure_lock.lock",
FT_UINT8, BASE_DEC, VALS(cip_ssupervisor_lock_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_lock_password,
{ "Password", "cipsafety.ssupervisor.configure_lock.password",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_lock_tunid,
{ "Target UNID", "cipsafety.ssupervisor.configure_lock.tunid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_lock_tunid_ssn_timestamp,
{ "TUNID SSN Timestamp", "cipsafety.ssupervisor.configure_lock.tunid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_lock_tunid_ssn_date,
{ "TUNID SSN (Manual) Date", "cipsafety.ssupervisor.configure_lock.tunid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_lock_tunid_ssn_time,
{ "TUNID SSN (Manual) Time", "cipsafety.ssupervisor.configure_lock.tunid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configure_lock_tunid_macid,
{ "MAC ID", "cipsafety.ssupervisor.configure_lock.tunid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_mode_change_value,
{ "Value", "cipsafety.ssupervisor.mode_change.value",
FT_UINT8, BASE_DEC, VALS(cip_ssupervisor_change_mode_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_mode_change_password,
{ "Password", "cipsafety.ssupervisor.mode_change.password",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_type,
{ "Reset Type", "cipsafety.ssupervisor.reset.type",
FT_UINT8, BASE_DEC, VALS(cip_reset_type_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_password,
{ "Password", "cipsafety.ssupervisor.reset.password",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_tunid,
{ "Target UNID", "cipsafety.ssupervisor.reset.tunid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_tunid_tunid_ssn_timestamp,
{ "TUNID SSN Timestamp", "cipsafety.ssupervisor.reset.tunid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_tunid_tunid_ssn_date,
{ "TUNID SSN (Manual) Date", "cipsafety.ssupervisor.reset.tunid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_tunid_tunid_ssn_time,
{ "TUNID SSN (Manual) Time", "cipsafety.ssupervisor.reset.tunid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_tunid_macid,
{ "MAC ID", "cipsafety.ssupervisor.reset.tunid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap,
{ "Attribute Bit Map", "cipsafety.ssupervisor.reset.attr_bitmap",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap_macid,
{ "Preserve MacID", "cipsafety.ssupervisor.reset.attr_bitmap.macid",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x01, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap_baudrate,
{ "Preserve Baud Rate", "cipsafety.ssupervisor.reset.attr_bitmap.baudrate",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x02, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap_tunid,
{ "Preserve TUNID", "cipsafety.ssupervisor.reset.attr_bitmap.tunid",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x04, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap_password,
{ "Preserve Password", "cipsafety.ssupervisor.reset.attr_bitmap.password",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x08, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap_cfunid,
{ "Preserve CFUNID", "cipsafety.ssupervisor.reset.attr_bitmap.cfunid",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x10, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap_ocpunid,
{ "Preserve OPCUNID", "cipsafety.ssupervisor.reset.attr_bitmap.ocpunid",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x20, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap_reserved,
{ "Reserved", "cipsafety.ssupervisor.reset.attr_bitmap.reserved",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x40, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_attr_bitmap_extended,
{ "Use Extended Map", "cipsafety.ssupervisor.reset.attr_bitmap.extended",
FT_BOOLEAN, 8, TFS(&tfs_true_false), 0x80, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_password_data_size,
{ "Data Size", "cipsafety.ssupervisor.reset_password.data_size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_reset_password_data,
{ "Password Data", "cipsafety.ssupervisor.reset_password.password_data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_propose_tunid_tunid,
{ "Target UNID", "cipsafety.ssupervisor.propose_tunid.tunid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_propose_tunid_tunid_ssn_timestamp,
{ "TUNID SSN Timestamp", "cipsafety.ssupervisor.propose_tunid.tunid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_propose_tunid_tunid_ssn_date,
{ "TUNID SSN (Manual) Date", "cipsafety.ssupervisor.propose_tunid.tunid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_propose_tunid_tunid_ssn_time,
{ "TUNID SSN (Manual) Time", "cipsafety.ssupervisor.propose_tunid.tunid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_propose_tunid_tunid_macid,
{ "MAC ID", "cipsafety.ssupervisor.propose_tunid.tunid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_apply_tunid_tunid,
{ "Target UNID", "cipsafety.ssupervisor.apply_tunid.tunid",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_apply_tunid_tunid_ssn_timestamp,
{ "TUNID SSN Timestamp", "cipsafety.ssupervisor.apply_tunid.tunid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_apply_tunid_tunid_ssn_date,
{ "TUNID SSN (Manual) Date", "cipsafety.ssupervisor.apply_tunid.tunid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_apply_tunid_tunid_ssn_time,
{ "TUNID SSN (Manual) Time", "cipsafety.ssupervisor.apply_tunid.tunid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_apply_tunid_tunid_macid,
{ "MAC ID", "cipsafety.ssupervisor.apply_tunid.tunid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_class_subclass,
{ "Subclass", "cipsafety.ssupervisor.class_subclass",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_num_attr,
{ "Number of Attributes", "cipsafety.ssupervisor.num_attr",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_attr_list,
{ "Attributes List Item", "cipsafety.ssupervisor.attr_item",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_manufacture_name,
{ "Manufacturer Name", "cipsafety.ssupervisor.manufacture_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_manufacture_model_number,
{ "Manufacturer Model Number", "cipsafety.ssupervisor.manufacture_model_number",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_sw_rev_level,
{ "Software Revision Level", "cipsafety.ssupervisor.sw_rev_level",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_hw_rev_level,
{ "Hardware Revision Level", "cipsafety.ssupervisor.hw_rev_level",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_manufacture_serial_number,
{ "Manufacturer Serial Number", "cipsafety.ssupervisor.manufacture_serial_number",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_device_config,
{ "Device Configuration", "cipsafety.ssupervisor.device_config",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_device_status,
{ "Device Status", "cipsafety.ssupervisor.device_status",
FT_UINT8, BASE_DEC, VALS(cip_ssupervisor_device_status_type_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_exception_status,
{ "Exception Status", "cipsafety.ssupervisor.exception_status",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_exception_detail_ced_size,
{ "Common Exception Detail Size", "cipsafety.ssupervisor.exception_detail.ced.size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_exception_detail_ced_detail,
{ "Common Exception Detail Data", "cipsafety.ssupervisor.exception_detail.ced.detail",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_exception_detail_ded_size,
{ "Device Exception Detail Size", "cipsafety.ssupervisor.exception_detail.ded.size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_exception_detail_ded_detail,
{ "Device Exception Detail Data", "cipsafety.ssupervisor.exception_detail.ded.detail",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_exception_detail_med_size,
{ "Manufacturer Exception Detail Size", "cipsafety.ssupervisor.exception_detail.med.size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_exception_detail_med_detail,
{ "Manufacturer Exception Detail Data", "cipsafety.ssupervisor.exception_detail.med.detail",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_alarm_enable,
{ "Exception Detail Alarm", "cipsafety.ssupervisor.alarm_enable",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_true_false), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_warning_enable,
{ "Exception Detail Warning", "cipsafety.ssupervisor.warning_enable",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_true_false), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_time,
{ "Time", "cipsafety.ssupervisor.time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_clock_power_cycle_behavior,
{ "Clock Power Cycle Behavior", "cipsafety.ssupervisor.clock_power_cycle_behavior",
FT_UINT8, BASE_DEC, VALS(cip_ssupervisor_clock_power_cycle_type_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_last_maintenance_date,
{ "Last Maintenance Date", "cipsafety.ssupervisor.last_maintenance_date",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_next_scheduled_maintenance_date,
{ "Next Scheduled Maintenance Date", "cipsafety.ssupervisor.next_scheduled_maintenance_date",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_scheduled_maintenance_expiration_timer,
{ "Scheduled Maintenance Expiration Timer", "cipsafety.ssupervisor.scheduled_maintenance_expiration_timer",
FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_scheduled_maintenance_expiration_warning_enable,
{ "Scheduled Maintenance Expiration Warning Enable", "cipsafety.ssupervisor.scheduled_maintenance_expiration_warning",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_enabled_disabled), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_run_hours,
{ "Run Hours", "cipsafety.ssupervisor.run_hours",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configuration_lock,
{ "Configuration Lock", "cipsafety.ssupervisor.configuration_lock",
FT_UINT8, BASE_DEC, VALS(cip_ssupervisor_lock_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configuration_unid_ssn_timestamp,
{ "Configuration UNID SSN Timestamp", "cipsafety.ssupervisor.configuration_unid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configuration_unid_ssn_date,
{ "Configuration UNID SSN (Manual) Date", "cipsafety.ssupervisor.configuration_unid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configuration_unid_ssn_time,
{ "Configuration UNID SSN (Manual) Time", "cipsafety.ssupervisor.configuration_unid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_configuration_unid_macid,
{ "Configuration UNID MAC ID", "cipsafety.ssupervisor.configuration_unid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_safety_configuration_id_ssn_timestamp,
{ "Safety Configuration ID SSN Timestamp", "cipsafety.ssupervisor.safety_configuration_id.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_safety_configuration_id_ssn_date,
{ "Safety Configuration ID SSN (Manual) Date", "cipsafety.ssupervisor.safety_configuration_id.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_safety_configuration_id_ssn_time,
{ "Safety Configuration ID SSN (Manual) Time", "cipsafety.ssupervisor.safety_configuration_id.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_safety_configuration_id_macid,
{ "Safety Configuration ID MAC ID", "cipsafety.ssupervisor.safety_configuration_id.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_target_unid_ssn_timestamp,
{ "Target UNID SSN Timestamp", "cipsafety.ssupervisor.target_unid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_target_unid_ssn_date,
{ "Target UNID SSN (Manual) Date", "cipsafety.ssupervisor.target_unid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_target_unid_ssn_time,
{ "Target UNID SSN (Manual) Time", "cipsafety.ssupervisor.target_unid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_target_unid_macid,
{ "Target UNID MAC ID", "cipsafety.ssupervisor.target_unid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_cp_owners_num_entries,
{ "Number of Array Entries", "cipsafety.ssupervisor.cp_owners.num_entries",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_output_cp_owners_ocpunid_ssn_timestamp,
{ "OCPUNID SSN Timestamp", "cipsafety.ssupervisor.cp_owners.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_output_cp_owners_ocpunid_ssn_date,
{ "OCPUNID SSN (Manual) Date", "cipsafety.ssupervisor.cp_owners.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_output_cp_owners_ocpunid_ssn_time,
{ "OCPUNID SSN (Manual) Time", "cipsafety.ssupervisor.cp_owners.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_output_cp_owners_ocpunid_macid,
{ "OCPUNID MAC ID", "cipsafety.ssupervisor.cp_owners.ocpunid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_cp_owners_app_path_size,
{ "EPATH Size", "cipsafety.ssupervisor.cp_owners.epath_size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_proposed_tunid_ssn_timestamp,
{ "Proposed TUNID SSN Timestamp", "cipsafety.ssupervisor.proposed_tunid.ssn.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_proposed_tunid_ssn_date,
{ "Proposed TUNID SSN (Manual) Date", "cipsafety.ssupervisor.proposed_tunid.ssn.date",
FT_UINT16, BASE_HEX, VALS(cipsafety_ssn_date_vals), 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_proposed_tunid_ssn_time,
{ "Proposed TUNID SSN (Manual) Time", "cipsafety.ssupervisor.proposed_tunid.ssn.time",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_proposed_tunid_macid,
{ "Proposed TUNID MAC ID", "cipsafety.ssupervisor.proposed_tunid.macid",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_ssupervisor_instance_subclass,
{ "Subclass", "cipsafety.ssupervisor.instance_subclass",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
}
};
static hf_register_info hf_svalidator[] = {
{ &hf_cip_svalidator_sc,
{ "Service", "cipsafety.svalidator.sc",
FT_UINT8, BASE_HEX, VALS(cip_sc_vals_svalidator), CIP_SC_MASK, NULL, HFILL }
},
{ &hf_cip_svalidator_sconn_fault_count,
{ "Safety Connection Fault Count", "cipsafety.svalidator.sconn_fault_count",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_state,
{ "Safety Validator State", "cipsafety.svalidator.state",
FT_UINT8, BASE_DEC, VALS(cip_svalidator_state_vals), 0, NULL, HFILL }
},
{ &hf_cip_svalidator_type,
{ "Safety Validator Type", "cipsafety.svalidator.type",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_type_pc,
{ "Producer/Consumer", "cipsafety.svalidator.type.pc",
FT_UINT8, BASE_HEX, VALS(cip_svalidator_type_pc_vals), 0x80, NULL, HFILL }
},
{ &hf_cip_svalidator_type_conn_type,
{ "Safety Connection Type", "cipsafety.svalidator.type.conn_type",
FT_UINT8, BASE_DEC, VALS(cip_svalidator_type_conn_type_vals), 0x7F, NULL, HFILL }
},
{ &hf_cip_svalidator_ping_eri,
{ "Ping Interval EPI Multiplier", "cipsafety.svalidator.ping_eri",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_time_coord_msg_min_mult_size,
{ "Time Coord Msg Min Multiplier Size", "cipsafety.svalidator.time_coord_msg_min_mult.size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_time_coord_msg_min_mult_item,
{ "Time Coord Msg Min Multiplier Item", "cipsafety.svalidator.time_coord_msg_min_mult.item",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_network_time_multiplier_size,
{ "Network Time Expectation Multiplier Size", "cipsafety.svalidator.network_time_multiplier.size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_network_time_multiplier_item,
{ "Network Time Expectation Multiplier Item", "cipsafety.svalidator.network_time_multiplier.item",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_timeout_multiplier_size,
{ "Timeout Multiplier Size", "cipsafety.svalidator.timeout_multiplier.size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_timeout_multiplier_item,
{ "Timeout Multiplier Item", "cipsafety.svalidator.timeout_multiplier.item",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_max_consumer_num,
{ "Max Consumer Number", "cipsafety.svalidator.max_consumer_num",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_data_conn_inst,
{ "Data Connection Instance", "cipsafety.svalidator.data_conn_inst",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_coordination_conn_inst_size,
{ "Coordination Connection Instance Size", "cipsafety.svalidator.coordination_conn_inst.size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_coordination_conn_inst_item,
{ "Coordination Connection Instance Item", "cipsafety.svalidator.coordination_conn_inst.item",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_correction_conn_inst,
{ "Correction Connection Instance", "cipsafety.svalidator.correction_conn_inst",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_cco_binding,
{ "CCO Binding", "cipsafety.svalidator.cco_binding",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_max_data_age,
{ "Max Data Age", "cipsafety.svalidator.max_data_age",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_error_code,
{ "Error Code", "cipsafety.svalidator.error_code",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_prod_cons_fault_count_size,
{ "Producer/Consumer Counter Size", "cipsafety.svalidator.prod_cons_fault_count.size",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_cip_svalidator_prod_cons_fault_count_item,
{ "Producer/Consumer Counter Item", "cipsafety.svalidator.prod_cons_fault_count.item",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
}
};
static gint *ett[] = {
&ett_cip_safety,
&ett_path,
&ett_cipsafety_mode_byte,
&ett_cipsafety_ack_byte,
&ett_cipsafety_mcast_byte
};
static gint *ett_ssupervisor[] = {
&ett_cip_class_s_supervisor,
&ett_ssupervisor_rrsc,
&ett_ssupervisor_cmd_data,
&ett_ssupervisor_propose_tunid,
&ett_ssupervisor_propose_tunid_ssn,
&ett_ssupervisor_configure_request_tunid,
&ett_ssupervisor_configure_request_tunid_ssn,
&ett_ssupervisor_configure_request_ounid,
&ett_ssupervisor_configure_request_ounid_ssn,
&ett_ssupervisor_configure_lock_tunid,
&ett_ssupervisor_configure_lock_tunid_ssn,
&ett_ssupervisor_reset_tunid,
&ett_ssupervisor_reset_tunid_ssn,
&ett_ssupervisor_apply_tunid,
&ett_ssupervisor_apply_tunid_ssn,
&ett_exception_detail_common,
&ett_exception_detail_device,
&ett_exception_detail_manufacturer,
&ett_ssupervisor_configuration_unid,
&ett_ssupervisor_configuration_unid_ssn,
&ett_ssupervisor_safety_configuration_id,
&ett_ssupervisor_safety_configuration_id_ssn,
&ett_ssupervisor_target_unid,
&ett_ssupervisor_target_unid_ssn,
&ett_ssupervisor_output_cp_owners,
&ett_ssupervisor_output_cp_owners_ocpunid,
&ett_ssupervisor_output_cp_owners_ocpunid_ssn,
&ett_ssupervisor_proposed_tunid,
&ett_ssupervisor_proposed_tunid_ssn,
&ett_cip_ssupervisor_reset_attr_bitmap
};
static gint *ett_svalidator[] = {
&ett_cip_class_s_validator,
&ett_svalidator_rrsc,
&ett_svalidator_cmd_data,
&ett_svalidator_type
};
static ei_register_info ei[] = {
{ &ei_cipsafety_tbd2_not_complemented, { "cipsafety.tbd2_not_complemented", PI_PROTOCOL, PI_WARN, "TBD_2_bit not complemented", EXPFILL }},
{ &ei_cipsafety_tbd_not_copied, { "cipsafety.tbd_not_copied", PI_PROTOCOL, PI_WARN, "TBD bit not copied", EXPFILL }},
{ &ei_cipsafety_run_idle_not_complemented, { "cipsafety.run_idle_not_complemented", PI_PROTOCOL, PI_WARN, "Run/Idle bit not complemented", EXPFILL }},
{ &ei_mal_io, { "cipsafety.malformed.io", PI_MALFORMED, PI_ERROR, "Malformed CIP Safety I/O packet", EXPFILL }},
{ &ei_mal_sercosiii_link_error_count_p1p2, { "cipsafety.malformed.sercosiii_link.error_count_p1p2", PI_MALFORMED, PI_ERROR, "Malformed SERCOS III Attribute 5", EXPFILL }},
{ &ei_cipsafety_not_complement_data, { "cipsafety.not_complement_data", PI_PROTOCOL, PI_WARN, "Data not complemented", EXPFILL }},
{ &ei_cipsafety_crc_s1, { "cipsafety.crc_s1.incorrect", PI_PROTOCOL, PI_WARN, "CRC-S1 incorrect", EXPFILL }},
{ &ei_cipsafety_crc_s2, { "cipsafety.crc_s2.incorrect", PI_PROTOCOL, PI_WARN, "CRC-S2 incorrect", EXPFILL }},
{ &ei_cipsafety_crc_s3, { "cipsafety.crc_s3.incorrect", PI_PROTOCOL, PI_WARN, "CRC-S3 incorrect", EXPFILL }},
{ &ei_cipsafety_complement_crc_s3, { "cipsafety.complement_crc_s3.incorrect", PI_PROTOCOL, PI_WARN, "Complement CRC-S3 incorrect", EXPFILL }},
{ &ei_cipsafety_crc_s5, { "cipsafety.crc_s5.incorrect", PI_PROTOCOL, PI_WARN, "CRC-S5 incorrect", EXPFILL }},
};
static ei_register_info ei_ssupervisor[] = {
{ &ei_mal_ssupervisor_exception_detail_ced, { "cipsafety.ssupervisor.malformed.exception_detail.ced", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Exception Detail (Common Exception Detail)", EXPFILL }},
{ &ei_mal_ssupervisor_exception_detail_ded, { "cipsafety.ssupervisor.malformed.exception_detail.ded", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Exception Detail (Device Exception Detail)", EXPFILL }},
{ &ei_mal_ssupervisor_exception_detail_med, { "cipsafety.ssupervisor.malformed.exception_detail.med", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Exception Detail (Manufacturer Exception Detail)", EXPFILL }},
{ &ei_mal_ssupervisor_configuration_unid, { "cipsafety.ssupervisor.malformed.configuration_unid", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Configuration UNID", EXPFILL }},
{ &ei_mal_ssupervisor_safety_configuration_id, { "cipsafety.ssupervisor.malformed.safety_configuration_id", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Safety Configuration Identifier", EXPFILL }},
{ &ei_mal_ssupervisor_target_unid, { "cipsafety.ssupervisor.malformed.target_unid", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Target UNID", EXPFILL }},
{ &ei_mal_ssupervisor_cp_owners, { "cipsafety.ssupervisor.malformed.cp_owners", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Output Connection Point Owners", EXPFILL }},
{ &ei_mal_ssupervisor_cp_owners_entry, { "cipsafety.ssupervisor.malformed.cp_owners.entry", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Output Connection Point Owners (UNID)", EXPFILL }},
{ &ei_mal_ssupervisor_cp_owners_app_path_size, { "cipsafety.ssupervisor.malformed.cp_owners.app_path_size", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Output Connection Point Owners (EPATH)", EXPFILL }},
{ &ei_mal_ssupervisor_proposed_tunid, { "cipsafety.ssupervisor.malformed.proposed_tunid", PI_MALFORMED, PI_ERROR,
"Malformed Safety Supervisor Proposed TUNID", EXPFILL }},
};
static ei_register_info ei_svalidator[] = {
{ &ei_mal_svalidator_type, { "cipsafety.ssupervisor.malformed.svalidator.type", PI_MALFORMED, PI_ERROR,
"Malformed Safety Validator Type", EXPFILL }},
{ &ei_mal_svalidator_time_coord_msg_min_mult, { "cipsafety.ssupervisor.malformed.svalidator.time_coord_msg_min_mult", PI_MALFORMED, PI_ERROR,
"Malformed Safety Validator Time Coord Msg Min Multiplier", EXPFILL }},
{ &ei_mal_svalidator_network_time_multiplier, { "cipsafety.ssupervisor.malformed.svalidator.network_time_multiplier", PI_MALFORMED, PI_ERROR,
"Malformed Safety Validator Network Time Expectation Multiplier", EXPFILL }},
{ &ei_mal_svalidator_timeout_multiplier, { "cipsafety.ssupervisor.malformed.svalidator.timeout_multiplier", PI_MALFORMED, PI_ERROR,
"Malformed Safety Validator Timeout Multiplier", EXPFILL }},
{ &ei_mal_svalidator_coordination_conn_inst, { "cipsafety.ssupervisor.malformed.svalidator.coordination_conn_inst", PI_MALFORMED, PI_ERROR,
"Malformed Safety Validator Coordination Connection Instance", EXPFILL }},
{ &ei_mal_svalidator_prod_cons_fault_count, { "cipsafety.ssupervisor.malformed.svalidator.prod_cons_fault_count", PI_MALFORMED, PI_ERROR,
"Malformed Safety Validator Produce/Consume Fault Counters", EXPFILL }},
};
expert_module_t* expert_cip_safety;
expert_module_t* expert_cip_class_s_supervisor;
expert_module_t* expert_cip_class_s_validator;
proto_cipsafety = proto_register_protocol("Common Industrial Protocol, Safety", "CIP Safety", "cipsafety");
proto_register_field_array(proto_cipsafety, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_cip_safety = expert_register_protocol(proto_cipsafety);
expert_register_field_array(expert_cip_safety, ei, array_length(ei));
cipsafety_handle = register_dissector( "cipsafety", dissect_cipsafety, proto_cipsafety);
proto_cip_class_s_supervisor = proto_register_protocol("CIP Safety Supervisor",
"CIPSSupervisor", "cipssupervisor");
proto_register_field_array(proto_cip_class_s_supervisor, hf_ssupervisor, array_length(hf_ssupervisor));
proto_register_subtree_array(ett_ssupervisor, array_length(ett_ssupervisor));
expert_cip_class_s_supervisor = expert_register_protocol(proto_cip_class_s_supervisor);
expert_register_field_array(expert_cip_class_s_supervisor, ei_ssupervisor, array_length(ei_ssupervisor));
proto_cip_class_s_validator = proto_register_protocol("CIP Safety Validator",
"CIPSValidator", "cipsvalidator");
proto_register_field_array(proto_cip_class_s_validator, hf_svalidator, array_length(hf_svalidator));
proto_register_subtree_array(ett_svalidator, array_length(ett_svalidator));
expert_cip_class_s_validator = expert_register_protocol(proto_cip_class_s_validator);
expert_register_field_array(expert_cip_class_s_validator, ei_svalidator, array_length(ei_svalidator));
}
void
proto_reg_handoff_cipsafety(void)
{
dissector_handle_t cip_class_s_supervisor_handle;
cip_class_s_supervisor_handle = create_dissector_handle( dissect_cip_class_s_supervisor, proto_cip_class_s_supervisor );
dissector_add_uint( "cip.class.iface", CI_CLS_SAFETY_SUPERVISOR, cip_class_s_supervisor_handle );
cip_class_s_validator_handle = create_dissector_handle( dissect_cip_class_s_validator, proto_cip_class_s_validator );
dissector_add_uint( "cip.class.iface", CI_CLS_SAFETY_VALIDATOR, cip_class_s_validator_handle );
heur_dissector_add("cip.sc", dissect_class_svalidator_heur, "CIP Safety Validator", "s_validator_cip", proto_cip_class_s_validator, HEURISTIC_ENABLE);
dissector_add_for_decode_as("enip.io", cipsafety_handle );
proto_cip = proto_get_id_by_filter_name( "cip" );
subdissector_class_table = find_dissector_table("cip.class.iface");
}
