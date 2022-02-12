static void *
uat_key_record_copy_cb(void *n, const void *o, size_t siz _U_)
{
uat_key_record_t *new_key = (uat_key_record_t *)n;
const uat_key_record_t *old_key = (const uat_key_record_t *)o;
if (old_key->string) {
new_key->string = g_strdup(old_key->string);
} else {
new_key->string = NULL;
}
if (old_key->label) {
new_key->label = g_strdup(old_key->label);
} else {
new_key->label = NULL;
}
return new_key;
}
static void
uat_key_record_free_cb(void *r)
{
uat_key_record_t *key = (uat_key_record_t *)r;
if (key->string) {
g_free(key->string);
}
if (key->label) {
g_free(key->label);
}
}
static gboolean
zbee_gp_security_parse_key(const gchar *key_str, guint8 *key_buf, gboolean byte_order)
{
gboolean string_mode = FALSE;
gchar temp;
int i, j;
memset(key_buf, 0, ZBEE_SEC_CONST_KEYSIZE);
if (key_str == NULL) {
return FALSE;
}
if ((temp = *key_str++) == '"') {
string_mode = TRUE;
temp = *key_str++;
}
j = byte_order ? ZBEE_SEC_CONST_KEYSIZE - 1 : 0;
for (i = ZBEE_SEC_CONST_KEYSIZE - 1; i >= 0; i--) {
if (string_mode) {
if (g_ascii_isprint(temp)) {
key_buf[j] = temp;
temp = *key_str++;
} else {
return FALSE;
}
} else {
if ((temp == ':') || (temp == '-') || (temp == ' ')) {
temp = *(key_str++);
}
if (g_ascii_isxdigit(temp)) {
key_buf[j] = g_ascii_xdigit_value(temp) << 4;
} else {
return FALSE;
}
temp = *(key_str++);
if (g_ascii_isxdigit(temp)) {
key_buf[j] |= g_ascii_xdigit_value(temp);
} else {
return FALSE;
}
temp = *(key_str++);
}
if (byte_order) {
j--;
} else {
j++;
}
}
return TRUE;
}
static gboolean
uat_key_record_update_cb(void *r, char **err)
{
uat_key_record_t *rec = (uat_key_record_t *)r;
if (rec->string == NULL) {
*err = g_strdup("Key can't be blank.");
return FALSE;
} else {
g_strstrip(rec->string);
if (rec->string[0] != 0) {
*err = NULL;
if (!zbee_gp_security_parse_key(rec->string, rec->key, rec->byte_order)) {
*err = g_strdup_printf("Expecting %d hexadecimal bytes or a %d character double-quoted string",
ZBEE_SEC_CONST_KEYSIZE, ZBEE_SEC_CONST_KEYSIZE);
return FALSE;
}
} else {
*err = g_strdup("Key can't be blank.");
return FALSE;
}
}
return TRUE;
}
static void uat_key_record_post_update_cb(void) {
guint i;
for (i = 0; i < num_uat_key_records; i++) {
if (memcmp(gp_uat_key_records[i].key, empty_key, ZBEE_SEC_CONST_KEYSIZE) == 0) {
zbee_gp_security_parse_key(gp_uat_key_records[i].string, gp_uat_key_records[i].key,
gp_uat_key_records[i].byte_order);
}
}
}
static guint
dissect_zbee_nwk_gp_cmd_commissioning(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
guint8 comm_options;
guint8 comm_ext_options = 0;
guint8 ms_ext_options = 0;
guint16 manufacturer_id = 0;
guint8 i;
guint8 gpd_cmd_num = 0;
proto_item *gpd_cmd_list;
proto_tree *gpd_cmd_list_tree;
guint8 length_of_clid_list_bm;
guint8 server_clid_num;
guint8 client_clid_num;
proto_item *server_clid_list, *client_clid_list;
proto_tree *server_clid_list_tree, *client_clid_list_tree;
static const int * options[] = {
&hf_zbee_nwk_gp_cmd_comm_opt_mac_sec_num_cap,
&hf_zbee_nwk_gp_cmd_comm_opt_rx_on_cap,
&hf_zbee_nwk_gp_cmd_comm_opt_ms_ext_present,
&hf_zbee_nwk_gp_cmd_comm_opt_panid_req,
&hf_zbee_nwk_gp_cmd_comm_opt_sec_key_req,
&hf_zbee_nwk_gp_cmd_comm_opt_fixed_location,
&hf_zbee_nwk_gp_cmd_comm_opt_ext_opt,
NULL
};
static const int * ext_options[] = {
&hf_zbee_nwk_gp_cmd_comm_ext_opt_sec_level_cap,
&hf_zbee_nwk_gp_cmd_comm_ext_opt_key_type,
&hf_zbee_nwk_gp_cmd_comm_ext_opt_gpd_key_present,
&hf_zbee_nwk_gp_cmd_comm_ext_opt_gpd_key_encr,
&hf_zbee_nwk_gp_cmd_comm_ext_opt_outgoing_counter,
NULL
};
static const int * ms_ext[] = {
&hf_zbee_nwk_gp_cmd_comm_ms_ext_mip,
&hf_zbee_nwk_gp_cmd_comm_ms_ext_mmip,
&hf_zbee_nwk_gp_cmd_comm_ms_ext_gclp,
&hf_zbee_nwk_gp_cmd_comm_ms_ext_crp,
NULL
};
static const int * length_of_clid_list[] = {
&hf_zbee_nwk_gp_cmd_comm_length_of_clid_list_server,
&hf_zbee_nwk_gp_cmd_comm_length_of_clid_list_client,
NULL
};
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_device_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
comm_options = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_gp_cmd_comm_opt, ett_zbee_nwk_cmd_options, options, ENC_NA);
offset += 1;
if (comm_options & ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_EXT_OPTIONS) {
comm_ext_options = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_gp_cmd_comm_ext_opt, ett_zbee_nwk_cmd_options, ext_options, ENC_NA);
offset += 1;
if (comm_ext_options & ZBEE_NWK_GP_CMD_COMMISSIONING_EXT_OPT_GPD_KEY_PRESENT) {
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_security_key, tvb, offset, NWK_CMD_SECURITY_KEY_LEN, ENC_NA);
offset += NWK_CMD_SECURITY_KEY_LEN;
}
if (comm_ext_options & ZBEE_NWK_GP_CMD_COMMISSIONING_EXT_OPT_GPD_KEY_ENCR) {
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_gpd_sec_key_mic, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
if (comm_ext_options & ZBEE_NWK_GP_CMD_COMMISSIONING_EXT_OPT_OUT_COUNTER) {
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_outgoing_counter, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
}
if (comm_options & ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_MANUFACTURER_INFO) {
ms_ext_options = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_gp_cmd_comm_ms_ext, ett_zbee_nwk_cmd_ms_ext, ms_ext, ENC_NA);
offset += 1;
if (ms_ext_options & ZBEE_NWK_GP_CMD_COMMISSIONING_MS_EXT_MIP) {
manufacturer_id = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_manufacturer_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (ms_ext_options & ZBEE_NWK_GP_CMD_COMMISSIONING_MS_EXT_MMIP) {
switch (manufacturer_id) {
case ZBEE_NWK_GP_MANUF_ID_GREENPEAK:
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_manufacturer_greenpeak_dev_id, tvb, offset, 2,
ENC_LITTLE_ENDIAN);
offset += 2;
break;
default:
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_manufacturer_dev_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
break;
}
}
if (ms_ext_options & ZBEE_NWK_GP_CMD_COMMISSIONING_MS_EXT_GCLP) {
gpd_cmd_num = tvb_get_guint8(tvb, offset);
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_gpd_cmd_num, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (gpd_cmd_num > 0) {
gpd_cmd_list = proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_gpd_cmd_id_list,
tvb, offset, gpd_cmd_num, ENC_NA);
gpd_cmd_list_tree = proto_item_add_subtree(gpd_cmd_list, ett_zbee_nwk_cmd_comm_gpd_cmd_id_list);
for (i = 0; i < gpd_cmd_num; i++, offset++) {
proto_tree_add_item(gpd_cmd_list_tree, hf_zbee_nwk_gp_command_id,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
}
}
}
if (ms_ext_options & ZBEE_NWK_GP_CMD_COMMISSIONING_MS_EXT_CRP) {
length_of_clid_list_bm = tvb_get_guint8(tvb, offset);
server_clid_num = (length_of_clid_list_bm & ZBEE_NWK_GP_CMD_COMMISSIONING_CLID_LIST_LEN_SRV) >>
ws_ctz(ZBEE_NWK_GP_CMD_COMMISSIONING_CLID_LIST_LEN_SRV);
client_clid_num = (length_of_clid_list_bm & ZBEE_NWK_GP_CMD_COMMISSIONING_CLID_LIST_LEN_CLI ) >>
ws_ctz(ZBEE_NWK_GP_CMD_COMMISSIONING_CLID_LIST_LEN_CLI);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_gp_cmd_comm_length_of_clid_list,
ett_zbee_nwk_cmd_comm_length_of_clid_list, length_of_clid_list, ENC_NA);
offset += 1;
if (server_clid_num > 0) {
server_clid_list = proto_tree_add_item(tree, hf_zbee_nwk_cmd_comm_clid_list_server,
tvb, offset, 2*server_clid_num, ENC_NA);
server_clid_list_tree = proto_item_add_subtree(server_clid_list, ett_zbee_nwk_cmd_comm_clid_list_server);
for (i = 0; i < server_clid_num; i++, offset += 2) {
proto_tree_add_item(server_clid_list_tree, hf_zbee_nwk_cmd_comm_cluster_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
}
if (client_clid_num > 0) {
client_clid_list = proto_tree_add_item(tree, hf_zbee_nwk_cmd_comm_clid_list_client,
tvb, offset, 2*client_clid_num, ENC_NA);
client_clid_list_tree = proto_item_add_subtree(client_clid_list, ett_zbee_nwk_cmd_comm_clid_list_client);
for (i = 0; i < client_clid_num; i++, offset += 2) {
proto_tree_add_item(client_clid_list_tree, hf_zbee_nwk_cmd_comm_cluster_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
}
}
}
return offset;
}
static guint
dissect_zbee_nwk_gp_cmd_channel_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
static const int * channels[] = {
&hf_zbee_nwk_gp_cmd_channel_request_toggling_behaviour_1st,
&hf_zbee_nwk_gp_cmd_channel_request_toggling_behaviour_2nd,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_gp_cmd_channel_request_toggling_behaviour, ett_zbee_nwk_cmd_options, channels, ENC_NA);
offset += 1;
return offset;
}
static guint
dissect_zbee_nwk_gp_cmd_channel_configuration(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
static const int * channels[] = {
&hf_zbee_nwk_gp_cmd_channel_configuration,
NULL
};
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_gp_cmd_operational_channel, ett_zbee_nwk_cmd_options, channels, ENC_NA);
offset += 1;
return offset;
}
static guint
dissect_zbee_nwk_gp_cmd_attr_reporting(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
guint16 cluster_id;
proto_tree *field_tree;
cluster_id = tvb_get_letohs(tvb, offset);
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_attr_report_cluster_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
field_tree = proto_tree_add_subtree_format(tree, tvb, offset, 2, ett_zbee_nwk_cmd_options, NULL,
"Attribute reporting command for cluster: 0x%02X", cluster_id);
dissect_zcl_write_attr(tvb, pinfo, field_tree, &offset, cluster_id);
return offset;
}
static guint
dissect_zbee_nwk_gp_cmd_commissioning_reply(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
guint8 cr_options;
guint8 cr_sec_level;
static const int * options[] = {
&hf_zbee_nwk_gp_cmd_comm_rep_opt_panid_present,
&hf_zbee_nwk_gp_cmd_comm_rep_opt_sec_key_present,
&hf_zbee_nwk_gp_cmd_comm_rep_opt_key_encr,
&hf_zbee_nwk_gp_cmd_comm_rep_opt_sec_level,
&hf_zbee_nwk_gp_cmd_comm_rep_opt_sec_type,
NULL
};
cr_options = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(tree, tvb, offset, hf_zbee_nwk_gp_cmd_comm_rep_opt, ett_zbee_nwk_cmd_options, options, ENC_NA);
offset += 1;
if (cr_options & ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_PAN_ID_PRESENT) {
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_rep_pan_id, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
if (cr_options & ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_SEC_KEY_PRESENT) {
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_security_key, tvb, offset, NWK_CMD_SECURITY_KEY_LEN, ENC_NA);
offset += NWK_CMD_SECURITY_KEY_LEN;
}
if ((cr_options & ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_KEY_ENCR) && (cr_options &
ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_SEC_KEY_PRESENT)) {
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_gpd_sec_key_mic, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
cr_sec_level = (cr_options & ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_SEC_LEVEL) >>
ws_ctz(ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_SEC_LEVEL);
if ((cr_options & ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_KEY_ENCR) &&
(cr_options & ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_SEC_KEY_PRESENT) &&
((cr_sec_level == ZBEE_NWK_GP_SECURITY_LEVEL_FULL) ||
(cr_sec_level == ZBEE_NWK_GP_SECURITY_LEVEL_FULLENCR))) {
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_comm_rep_frame_counter, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
}
return offset;
}
static guint
dissect_zbee_nwk_gp_cmd_move_color(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_move_color_ratex, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_move_color_ratey, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static guint
dissect_zbee_nwk_gp_cmd_move_up_down(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_move_up_down_rate, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
return offset;
}
static guint
dissect_zbee_nwk_gp_cmd_step_color(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_step_color_stepx, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_step_color_stepy, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (tvb_reported_length(tvb) - offset >= 2) {
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_step_color_transition_time, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
return offset;
}
static guint
dissect_zbee_nwk_gp_cmd_step_up_down(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
zbee_nwk_green_power_packet *packet _U_, guint offset)
{
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_step_up_down_step_size, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_zbee_nwk_gp_cmd_step_up_down_transition_time, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
return offset;
}
static int
dissect_zbee_nwk_gp_cmd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint offset = 0;
guint8 cmd_id = tvb_get_guint8(tvb, offset);
proto_item *cmd_root;
proto_tree *cmd_tree;
zbee_nwk_green_power_packet *packet = (zbee_nwk_green_power_packet *)data;
cmd_tree = proto_tree_add_subtree_format(tree, tvb, offset, -1, ett_zbee_nwk_cmd, &cmd_root,
"Command Frame: %s", val_to_str_ext_const(cmd_id,
&zbee_nwk_gp_cmd_names_ext,
"Unknown Command Frame"));
proto_tree_add_uint(cmd_tree, hf_zbee_nwk_gp_command_id, tvb, offset, 1, cmd_id);
offset += 1;
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_ext_const(cmd_id, &zbee_nwk_gp_cmd_names_ext, "Unknown command"));
switch(cmd_id) {
case ZB_GP_CMD_ID_IDENTIFY:
case ZB_GP_CMD_ID_SCENE0:
case ZB_GP_CMD_ID_SCENE1:
case ZB_GP_CMD_ID_SCENE2:
case ZB_GP_CMD_ID_SCENE3:
case ZB_GP_CMD_ID_SCENE4:
case ZB_GP_CMD_ID_SCENE5:
case ZB_GP_CMD_ID_SCENE6:
case ZB_GP_CMD_ID_SCENE7:
case ZB_GP_CMD_ID_SCENE8:
case ZB_GP_CMD_ID_SCENE9:
case ZB_GP_CMD_ID_SCENE10:
case ZB_GP_CMD_ID_SCENE11:
case ZB_GP_CMD_ID_SCENE12:
case ZB_GP_CMD_ID_SCENE13:
case ZB_GP_CMD_ID_SCENE14:
case ZB_GP_CMD_ID_SCENE15:
case ZB_GP_CMD_ID_OFF:
case ZB_GP_CMD_ID_ON:
case ZB_GP_CMD_ID_TOGGLE:
case ZB_GP_CMD_ID_RELEASE:
case ZB_GP_CMD_ID_LEVEL_CONTROL_STOP:
case ZB_GP_CMD_ID_MOVE_HUE_STOP:
case ZB_GP_CMD_ID_MOVE_SATURATION_STOP:
case ZB_GP_CMD_ID_LOCK_DOOR:
case ZB_GP_CMD_ID_UNLOCK_DOOR:
case ZB_GP_CMD_ID_PRESS11:
case ZB_GP_CMD_ID_RELEASE11:
case ZB_GP_CMD_ID_PRESS12:
case ZB_GP_CMD_ID_RELEASE12:
case ZB_GP_CMD_ID_PRESS22:
case ZB_GP_CMD_ID_RELEASE22:
case ZB_GP_CMD_ID_SHORT_PRESS11:
case ZB_GP_CMD_ID_SHORT_PRESS12:
case ZB_GP_CMD_ID_SHORT_PRESS22:
case ZB_GP_CMD_ID_DECOMMISSIONING:
case ZB_GP_CMD_ID_SUCCESS:
break;
case ZB_GP_CMD_ID_MOVE_UP:
case ZB_GP_CMD_ID_MOVE_DOWN:
case ZB_GP_CMD_ID_MOVE_UP_WITH_ON_OFF:
case ZB_GP_CMD_ID_MOVE_DOWN_WITH_ON_OFF:
case ZB_GP_CMD_ID_MOVE_HUE_UP:
case ZB_GP_CMD_ID_MOVE_HUE_DOWN:
case ZB_GP_CMD_ID_MOVE_SATURATION_UP:
case ZB_GP_CMD_ID_MOVE_SATURATION_DOWN:
offset = dissect_zbee_nwk_gp_cmd_move_up_down(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZB_GP_CMD_ID_STEP_UP:
case ZB_GP_CMD_ID_STEP_DOWN:
case ZB_GP_CMD_ID_STEP_UP_WITH_ON_OFF:
case ZB_GP_CMD_ID_STEP_DOWN_WITH_ON_OFF:
case ZB_GP_CMD_ID_STEP_HUE_UP:
case ZB_GP_CMD_ID_STEP_HUW_DOWN:
case ZB_GP_CMD_ID_STEP_SATURATION_UP:
case ZB_GP_CMD_ID_STEP_SATURATION_DOWN:
offset = dissect_zbee_nwk_gp_cmd_step_up_down(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZB_GP_CMD_ID_MOVE_COLOR:
offset = dissect_zbee_nwk_gp_cmd_move_color(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZB_GP_CMD_ID_STEP_COLOR:
offset = dissect_zbee_nwk_gp_cmd_step_color(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZB_GP_CMD_ID_ATTRIBUTE_REPORTING:
offset = dissect_zbee_nwk_gp_cmd_attr_reporting(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZB_GP_CMD_ID_MANUFACTURE_SPECIFIC_ATTR_REPORTING:
case ZB_GP_CMD_ID_MULTI_CLUSTER_REPORTING:
case ZB_GP_CMD_ID_MANUFACTURER_SPECIFIC_MCLUSTER_REPORTING:
case ZB_GP_CMD_ID_REQUEST_ATTRIBUTES:
case ZB_GP_CMD_ID_READ_ATTRIBUTES_RESPONSE:
case ZB_GP_CMD_ID_ANY_SENSOR_COMMAND_A0_A3:
break;
case ZB_GP_CMD_ID_COMMISSIONING:
offset = dissect_zbee_nwk_gp_cmd_commissioning(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZB_GP_CMD_ID_CHANNEL_REQUEST:
offset = dissect_zbee_nwk_gp_cmd_channel_request(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZB_GP_CMD_ID_COMMISSIONING_REPLY:
offset = dissect_zbee_nwk_gp_cmd_commissioning_reply(tvb, pinfo, cmd_tree, packet, offset);
break;
case ZB_GP_CMD_ID_WRITE_ATTRIBUTES:
case ZB_GP_CMD_ID_READ_ATTRIBUTES:
break;
case ZB_GP_CMD_ID_CHANNEL_CONFIGURATION:
offset = dissect_zbee_nwk_gp_cmd_channel_configuration(tvb, pinfo, cmd_tree, packet, offset);
break;
}
if (offset < tvb_reported_length(tvb)) {
proto_tree *root;
tvbuff_t *leftover_tvb = tvb_new_subset_remaining(tvb, offset);
root = proto_tree_get_root(tree);
proto_item_set_len(cmd_root, offset);
call_data_dissector(leftover_tvb, pinfo, root);
}
return offset;
}
static void
zbee_gp_make_nonce(zbee_nwk_green_power_packet *packet, gchar *nonce)
{
memset(nonce, 0, ZBEE_SEC_CONST_NONCE_LEN);
if (packet->direction == ZBEE_NWK_GP_FC_EXT_DIRECTION_FROM_ZGPD) {
nonce[0] = (guint8)((packet->source_id) & 0xff);
nonce[1] = (guint8)((packet->source_id) >> 8 & 0xff);
nonce[2] = (guint8)((packet->source_id) >> 16 & 0xff);
nonce[3] = (guint8)((packet->source_id) >> 24 & 0xff);
}
nonce[4] = (guint8)((packet->source_id) & 0xff);
nonce[5] = (guint8)((packet->source_id) >> 8 & 0xff);
nonce[6] = (guint8)((packet->source_id) >> 16 & 0xff);
nonce[7] = (guint8)((packet->source_id) >> 24 & 0xff);
nonce[8] = (guint8)((packet->security_frame_counter) & 0xff);
nonce[9] = (guint8)((packet->security_frame_counter) >> 8 & 0xff);
nonce[10] = (guint8)((packet->security_frame_counter) >> 16 & 0xff);
nonce[11] = (guint8)((packet->security_frame_counter) >> 24 & 0xff);
if ((packet->application_id == ZBEE_NWK_GP_APP_ID_ZGP) && (packet->direction !=
ZBEE_NWK_GP_FC_EXT_DIRECTION_FROM_ZGPD)) {
nonce[12] = (gchar)0xa3;
} else {
nonce[12] = (gchar)0x05;
}
}
static gboolean
zbee_gp_decrypt_payload(zbee_nwk_green_power_packet *packet, const gchar *enc_buffer, const gchar offset, guint8
*dec_buffer, guint payload_len, guint mic_len, guint8 *key)
{
guint8 *key_buffer = key;
guint8 nonce[ZBEE_SEC_CONST_NONCE_LEN];
zbee_gp_make_nonce(packet, nonce);
if (zbee_sec_ccm_decrypt(key_buffer, nonce, enc_buffer, enc_buffer + offset, dec_buffer, offset, payload_len,
mic_len)) {
return TRUE;
}
return FALSE;
}
static int
dissect_zbee_nwk_gp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gboolean gp_decrypted;
GSList *GSList_i;
guint offset = 0;
guint8 *dec_buffer;
guint8 *enc_buffer;
guint8 fcf;
proto_tree *nwk_tree;
proto_item *proto_root;
proto_item *ti = NULL;
tvbuff_t *payload_tvb;
zbee_nwk_green_power_packet packet;
static const int * fields[] = {
&hf_zbee_nwk_gp_frame_type,
&hf_zbee_nwk_gp_proto_version,
&hf_zbee_nwk_gp_auto_commissioning,
&hf_zbee_nwk_gp_fc_ext,
NULL
};
static const int * ext_fields[] = {
&hf_zbee_nwk_gp_fc_ext_app_id,
&hf_zbee_nwk_gp_fc_ext_sec_level,
&hf_zbee_nwk_gp_fc_ext_sec_key,
&hf_zbee_nwk_gp_fc_ext_rx_after_tx,
&hf_zbee_nwk_gp_fc_ext_direction,
NULL
};
memset(&packet, 0, sizeof(packet));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ZigBee Green Power");
col_clear(pinfo->cinfo, COL_INFO);
proto_root = proto_tree_add_protocol_format(tree, proto_zbee_nwk_gp, tvb, offset, tvb_captured_length(tvb),
"ZGP stub NWK header");
nwk_tree = proto_item_add_subtree(proto_root, ett_zbee_nwk);
enc_buffer = (guint8 *)tvb_memdup(wmem_packet_scope(), tvb, 0, tvb_captured_length(tvb));
fcf = tvb_get_guint8(tvb, offset);
packet.frame_type = zbee_get_bit_field(fcf, ZBEE_NWK_GP_FCF_FRAME_TYPE);
packet.nwk_frame_control_extension = zbee_get_bit_field(fcf, ZBEE_NWK_GP_FCF_CONTROL_EXTENSION);
ti = proto_tree_add_bitmask(nwk_tree, tvb, offset, hf_zbee_nwk_gp_fcf, ett_zbee_nwk_fcf, fields, ENC_NA);
proto_item_append_text(ti, " %s", val_to_str(packet.frame_type, zbee_nwk_gp_frame_types, "Unknown Frame Type"));
offset += 1;
proto_item_append_text(proto_root, " %s", val_to_str(packet.frame_type, zbee_nwk_gp_frame_types, "Unknown type"));
col_set_str(pinfo->cinfo, COL_INFO, val_to_str_const(packet.frame_type, zbee_nwk_gp_frame_types, "Reserved frame type"));
if (packet.nwk_frame_control_extension) {
fcf = tvb_get_guint8(tvb, offset);
packet.application_id = zbee_get_bit_field(fcf, ZBEE_NWK_GP_FCF_EXT_APP_ID);
packet.security_level = zbee_get_bit_field(fcf, ZBEE_NWK_GP_FCF_EXT_SECURITY_LEVEL);
packet.direction = zbee_get_bit_field(fcf, ZBEE_NWK_GP_FCF_EXT_DIRECTION);
proto_tree_add_bitmask(nwk_tree, tvb, offset, hf_zbee_nwk_gp_fc_ext_field, ett_zbee_nwk_fcf_ext, ext_fields, ENC_NA);
offset += 1;
}
if ((packet.frame_type == ZBEE_NWK_GP_FCF_DATA && !packet.nwk_frame_control_extension) || (packet.frame_type ==
ZBEE_NWK_GP_FCF_DATA && packet.nwk_frame_control_extension && packet.application_id ==
ZBEE_NWK_GP_APP_ID_DEFAULT) || (packet.frame_type == ZBEE_NWK_GP_FCF_MAINTENANCE &&
packet.nwk_frame_control_extension && packet.application_id == ZBEE_NWK_GP_APP_ID_DEFAULT && tvb_get_guint8(tvb,
offset) != ZB_GP_CMD_ID_CHANNEL_CONFIGURATION)) {
packet.source_id = tvb_get_letohl(tvb, offset);
proto_tree_add_item(nwk_tree, hf_zbee_nwk_gp_zgpd_src_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(proto_root, ", GPD Src ID: 0x%04x", packet.source_id);
col_append_fstr(pinfo->cinfo, COL_INFO, ", GPD Src ID: 0x%04x", packet.source_id);
offset += 4;
}
if (packet.application_id == ZBEE_NWK_GP_APP_ID_ZGP) {
packet.endpoint = tvb_get_guint8(tvb, offset);
proto_tree_add_item(nwk_tree, hf_zbee_nwk_gp_zgpd_endpoint, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_item_append_text(proto_root, ", Endpoint: %d", packet.endpoint);
col_append_fstr(pinfo->cinfo, COL_INFO, ", Endpoint: %d", packet.endpoint);
offset += 1;
}
packet.mic_size = 0;
if (packet.nwk_frame_control_extension) {
if (packet.application_id == ZBEE_NWK_GP_APP_ID_DEFAULT || packet.application_id == ZBEE_NWK_GP_APP_ID_ZGP
|| packet.application_id == ZBEE_NWK_GP_APP_ID_LPED) {
if (packet.security_level == ZBEE_NWK_GP_SECURITY_LEVEL_1LSB
&& packet.application_id != ZBEE_NWK_GP_APP_ID_LPED) {
packet.mic_size = 2;
} else if (packet.security_level == ZBEE_NWK_GP_SECURITY_LEVEL_FULL || packet.security_level ==
ZBEE_NWK_GP_SECURITY_LEVEL_FULLENCR) {
packet.mic_size = 4;
packet.security_frame_counter = tvb_get_letohl(tvb, offset);
proto_tree_add_item(nwk_tree, hf_zbee_nwk_gp_security_frame_counter, tvb, offset, 4,
ENC_LITTLE_ENDIAN);
offset += 4;
}
}
}
packet.payload_len = tvb_reported_length(tvb) - offset - packet.mic_size;
if (packet.payload_len <= 0) {
proto_tree_add_expert(nwk_tree, pinfo, &ei_zbee_nwk_gp_no_payload, tvb, 0, -1);
return offset;
}
if (packet.mic_size == 2) {
packet.mic = tvb_get_letohs(tvb, offset + packet.payload_len);
} else if (packet.mic_size == 4) {
packet.mic = tvb_get_letohl(tvb, offset + packet.payload_len);
}
payload_tvb = tvb_new_subset_length(tvb, offset, packet.payload_len);
if (packet.security_level != ZBEE_NWK_GP_SECURITY_LEVEL_FULLENCR) {
dissect_zbee_nwk_gp_cmd(payload_tvb, pinfo, nwk_tree, data);
}
offset += packet.payload_len;
if (packet.mic_size) {
proto_tree_add_uint(nwk_tree, packet.mic_size == 4 ? hf_zbee_nwk_gp_security_mic_4b :
hf_zbee_nwk_gp_security_mic_2b, tvb, offset, packet.mic_size, packet.mic);
offset += packet.mic_size;
}
data = (void *)&packet;
if ((offset < tvb_captured_length(tvb)) && (packet.security_level != ZBEE_NWK_GP_SECURITY_LEVEL_FULLENCR)) {
proto_tree_add_expert(nwk_tree, pinfo, &ei_zbee_nwk_gp_inval_residual_data, tvb, offset, -1);
return offset;
}
if (packet.security_level == ZBEE_NWK_GP_SECURITY_LEVEL_FULLENCR) {
dec_buffer = (guint8 *)wmem_alloc(pinfo->pool, packet.payload_len);
gp_decrypted = FALSE;
GSList_i = zbee_gp_keyring;
while (GSList_i && !gp_decrypted) {
gp_decrypted = zbee_gp_decrypt_payload(&packet, enc_buffer, offset - packet.payload_len -
packet.mic_size, dec_buffer, packet.payload_len, packet.mic_size,
((key_record_t *)(GSList_i->data))->key);
if (!gp_decrypted) {
GSList_i = g_slist_next(GSList_i);
}
}
if (gp_decrypted) {
payload_tvb = tvb_new_child_real_data(tvb, dec_buffer, packet.payload_len, packet.payload_len);
add_new_data_source(pinfo, payload_tvb, "Decrypted GP Payload");
dissect_zbee_nwk_gp_cmd(payload_tvb, pinfo, nwk_tree, data);
} else {
payload_tvb = tvb_new_subset_length_caplen(tvb, offset - packet.payload_len - packet.mic_size, packet.payload_len, -1);
call_data_dissector(payload_tvb, pinfo, tree);
}
}
return tvb_captured_length(tvb);
}
static gboolean
dissect_zbee_nwk_heur_gp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
ieee802154_packet *packet = (ieee802154_packet *)data;
guint8 fcf;
if (packet == NULL) return FALSE;
if (packet->src_addr_mode == IEEE802154_FCF_ADDR_SHORT) return FALSE;
fcf = tvb_get_guint8(tvb, 0);
if (zbee_get_bit_field(fcf, ZBEE_NWK_GP_FCF_VERSION) != ZBEE_VERSION_GREEN_POWER) return FALSE;
if (!try_val_to_str(zbee_get_bit_field(fcf, ZBEE_NWK_FCF_FRAME_TYPE), zbee_nwk_gp_frame_types)) return FALSE;
if (packet->dst_pan == IEEE802154_BCAST_PAN && packet->dst_addr_mode == IEEE802154_FCF_ADDR_SHORT &&
packet->dst16 == IEEE802154_BCAST_ADDR) {
dissect_zbee_nwk_gp(tvb, pinfo, tree, data);
return TRUE;
}
if (packet->dst_addr_mode == IEEE802154_FCF_ADDR_EXT) {
dissect_zbee_nwk_gp(tvb, pinfo, tree, data);
return TRUE;
}
return FALSE;
}
static void
gp_init_zbee_security(void)
{
guint i;
key_record_t key_record;
for (i = 0; gp_uat_key_records && (i < num_uat_key_records); i++) {
key_record.frame_num = 0;
key_record.label = g_strdup(gp_uat_key_records[i].label);
memcpy(key_record.key, gp_uat_key_records[i].key, ZBEE_SEC_CONST_KEYSIZE);
zbee_gp_keyring = g_slist_prepend(zbee_gp_keyring, g_memdup(&key_record, sizeof(key_record_t)));
}
}
static void zbee_free_key_record(gpointer ptr, gpointer user_data _U_)
{
key_record_t *k;
k = (key_record_t *)ptr;
if (!k)
return;
g_free(k->label);
g_free(k);
}
static void
gp_cleanup_zbee_security(void)
{
if (!zbee_gp_keyring)
return;
g_slist_foreach(zbee_gp_keyring, zbee_free_key_record, NULL);
g_slist_free(zbee_gp_keyring);
zbee_gp_keyring = NULL;
}
void
proto_register_zbee_nwk_gp(void)
{
module_t *gp_zbee_prefs;
expert_module_t* expert_zbee_nwk_gp;
static hf_register_info hf[] = {
{ &hf_zbee_nwk_gp_auto_commissioning,
{ "Auto Commissioning", "zbee_nwk_gp.auto_commissioning", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_FCF_AUTO_COMMISSIONING, NULL, HFILL }},
{ &hf_zbee_nwk_gp_fc_ext,
{ "NWK Frame Extension", "zbee_nwk_gp.fc_extension", FT_BOOLEAN, 8, NULL, ZBEE_NWK_GP_FCF_CONTROL_EXTENSION,
NULL, HFILL }},
{ &hf_zbee_nwk_gp_fcf,
{ "Frame Control Field", "zbee_nwk_gp.fcf", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_frame_type,
{ "Frame Type", "zbee_nwk_gp.frame_type", FT_UINT8, BASE_HEX, VALS(zbee_nwk_gp_frame_types),
ZBEE_NWK_GP_FCF_FRAME_TYPE, NULL, HFILL }},
{ &hf_zbee_nwk_gp_proto_version,
{ "Protocol Version", "zbee_nwk_gp.proto_version", FT_UINT8, BASE_DEC, NULL, ZBEE_NWK_GP_FCF_VERSION, NULL,
HFILL }},
{ &hf_zbee_nwk_gp_fc_ext_field,
{ "Extended NWK Frame Control Field", "zbee_nwk_gp.fc_ext", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_fc_ext_app_id,
{ "Application ID", "zbee_nwk_gp.fc_ext_app_id", FT_UINT8, BASE_HEX, VALS(zbee_nwk_gp_app_id_names),
ZBEE_NWK_GP_FCF_EXT_APP_ID, NULL, HFILL }},
{ &hf_zbee_nwk_gp_fc_ext_direction,
{ "Direction", "zbee_nwk_gp.fc_ext_direction", FT_UINT8, BASE_HEX, VALS(zbee_nwk_gp_directions),
ZBEE_NWK_GP_FCF_EXT_DIRECTION, NULL, HFILL }},
{ &hf_zbee_nwk_gp_fc_ext_rx_after_tx,
{ "Rx After Tx", "zbee_nwk_gp.fc_ext_rxaftertx", FT_BOOLEAN, 8, NULL, ZBEE_NWK_GP_FCF_EXT_RX_AFTER_TX, NULL,
HFILL }},
{ &hf_zbee_nwk_gp_fc_ext_sec_key,
{ "Security Key", "zbee_nwk_gp.fc_ext_security_key", FT_BOOLEAN, 8, NULL, ZBEE_NWK_GP_FCF_EXT_SECURITY_KEY,
NULL, HFILL }},
{ &hf_zbee_nwk_gp_fc_ext_sec_level,
{ "Security Level", "zbee_nwk_gp.fc_ext_security_level", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_gp_src_sec_levels_names), ZBEE_NWK_GP_FCF_EXT_SECURITY_LEVEL, NULL, HFILL }},
{ &hf_zbee_nwk_gp_zgpd_src_id,
{ "Src ID", "zbee_nwk_gp.source_id", FT_UINT32, BASE_HEX, VALS(zbee_nwk_gp_src_id_names), 0x0, NULL,
HFILL }},
{ &hf_zbee_nwk_gp_zgpd_endpoint,
{ "Endpoint", "zbee_nwk_gp.endpoint", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_security_frame_counter,
{ "Security Frame Counter", "zbee_nwk_gp.security_frame_counter", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL }},
{ &hf_zbee_nwk_gp_security_mic_2b,
{ "Security MIC", "zbee_nwk_gp.security_mic2", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_security_mic_4b,
{ "Security MIC", "zbee_nwk_gp.security_mic4", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_command_id,
{ "ZGPD Command ID", "zbee_nwk_gp.command_id", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &zbee_nwk_gp_cmd_names_ext, 0x0, NULL,
HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_device_id,
{ "ZGPD Device ID", "zbee_nwk_gp.cmd.comm.dev_id", FT_UINT8, BASE_HEX | BASE_EXT_STRING, &zbee_nwk_gp_device_ids_names_ext,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ext_opt_gpd_key_encr,
{ "GPD Key Encryption", "zbee_nwk_gp.cmd.comm.ext_opt.gpd_key_encr", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_EXT_OPT_GPD_KEY_ENCR, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ext_opt_gpd_key_present,
{ "GPD Key Present", "zbee_nwk_gp.cmd.comm.ext_opt.gpd_key_present", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_EXT_OPT_GPD_KEY_PRESENT, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ext_opt_key_type,
{ "Key Type", "zbee_nwk_gp.cmd.comm.ext_opt.key_type", FT_UINT8, BASE_HEX,
VALS(zbee_nwk_gp_src_sec_keys_type_names), ZBEE_NWK_GP_CMD_COMMISSIONING_EXT_OPT_KEY_TYPE, NULL,
HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_outgoing_counter,
{ "GPD Outgoing Counter", "zbee_nwk_gp.cmd.comm.out_counter", FT_UINT32, BASE_HEX, NULL, 0x0, NULL,
HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ext_opt_sec_level_cap,
{ "Security Level Capabilities", "zbee_nwk_gp.cmd.comm.ext_opt.seclevel_cap", FT_UINT8, BASE_HEX, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_EXT_OPT_SEC_LEVEL_CAP, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_security_key,
{ "Security Key", "zbee_nwk_gp.cmd.comm.security_key", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_gpd_sec_key_mic,
{ "GPD Key MIC", "zbee_nwk_gp.cmd.comm.gpd_key_mic", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_opt_ext_opt,
{ "Extended Option Field", "zbee_nwk_gp.cmd.comm.opt.ext_opt_field", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_EXT_OPTIONS, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_opt,
{ "Options Field", "zbee_nwk_gp.cmd.comm.opt", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_opt_fixed_location,
{ "Fixed Location", "zbee_nwk_gp.cmd.comm.opt.fixed_location", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_FIXED_LOCATION, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_opt_mac_sec_num_cap,
{ "MAC Sequence number capability", "zbee_nwk_gp.cmd.comm.opt.mac_seq_num_cap", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_MAC_SEQ, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_opt_ms_ext_present,
{ "MS Extensions Present", "zbee_nwk_gp.cmd.comm.opt.ms_ext_present", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_MANUFACTURER_INFO, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_opt_panid_req,
{ "PANId request", "zbee_nwk_gp.cmd.comm.opt.panid_req", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_PAN_ID_REQ, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_opt_rx_on_cap,
{ "RxOnCapability", "zbee_nwk_gp.cmd.comm.opt.rxon_cap", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_RX_ON_CAP, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_opt_sec_key_req,
{ "GP Security Key Request", "zbee_nwk_gp.cmd.comm.opt.seq_key_req", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_OPT_GP_SEC_KEY_REQ, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ext_opt,
{ "Extended Options Field", "zbee_nwk_gp.cmd.comm.ext_opt", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ext_opt_outgoing_counter,
{ "GPD Outgoing present", "zbee_nwk_gp.cmd.comm.ext_opt.outgoing_counter", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_EXT_OPT_OUT_COUNTER, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_manufacturer_greenpeak_dev_id,
{ "Manufacturer Model ID", "zbee_nwk_gp.cmd.comm.manufacturer_model_id", FT_UINT16, BASE_HEX,
VALS(zbee_nwk_gp_manufacturer_greenpeak_dev_names), 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_manufacturer_dev_id,
{ "Manufacturer Model ID", "zbee_nwk_gp.cmd.comm.manufacturer_model_id", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_manufacturer_id,
{ "Manufacturer ID", "zbee_nwk_gp.cmd.comm.manufacturer_id", FT_UINT16, BASE_HEX,
VALS(zbee_mfr_code_names), 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ms_ext_crp,
{ "Cluster reports present", "zbee_nwk_gp.cmd.comm.ms_ext.crp", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_MS_EXT_CRP , NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ms_ext_gclp,
{ "GP commands list present", "zbee_nwk_gp.cmd.comm.ms_ext.gclp", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_MS_EXT_GCLP , NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ms_ext,
{ "MS Extensions Field", "zbee_nwk_gp.cmd.comm.ms_ext", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ms_ext_mip,
{ "Manufacturer ID present", "zbee_nwk_gp.cmd.comm.ms_ext.mip", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_MS_EXT_MIP , NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_ms_ext_mmip,
{ "Manufacturer Model ID present", "zbee_nwk_gp.cmd.comm.ms_ext.mmip", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_MS_EXT_MMIP , NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_gpd_cmd_num,
{ "Number of GPD commands", "zbee_nwk_gp.cmd.comm.gpd_cmd_num", FT_UINT8, BASE_DEC, NULL,
0x0 , NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_gpd_cmd_id_list,
{ "GPD CommandID list", "zbee_nwk_gp.cmd.comm.gpd_cmd_id_list", FT_NONE, BASE_NONE, NULL,
0x0 , NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_length_of_clid_list,
{ "Length of ClusterID list", "zbee_nwk_gp.cmd.comm.length_of_clid_list", FT_UINT8, BASE_HEX, NULL,
0x0 , NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_length_of_clid_list_server,
{ "Number of server ClusterIDs", "zbee_nwk_gp.cmd.comm.length_of_clid_list_srv", FT_UINT8, BASE_DEC, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_CLID_LIST_LEN_SRV, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_length_of_clid_list_client,
{ "Number of client ClusterIDs", "zbee_nwk_gp.cmd.comm.length_of_clid_list_cli", FT_UINT8, BASE_DEC, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_CLID_LIST_LEN_CLI, NULL, HFILL }},
{ &hf_zbee_nwk_cmd_comm_clid_list_server,
{ "Cluster ID List Server", "zbee_nwk_gp.cmd.comm.clid_list_server", FT_NONE, BASE_NONE, NULL,
0x0 , NULL, HFILL }},
{ &hf_zbee_nwk_cmd_comm_clid_list_client,
{ "ClusterID List Client", "zbee_nwk_gp.cmd.comm.clid_list_client", FT_NONE, BASE_NONE, NULL,
0x0 , NULL, HFILL }},
{ &hf_zbee_nwk_cmd_comm_cluster_id,
{ "Cluster ID", "zbee_nwk_gp.cmd.comm.cluster_id", FT_UINT16, BASE_HEX, NULL,
0x0 , NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_rep_opt_key_encr,
{ "GPD Key Encryption", "zbee_nwk_gp.cmd.comm_reply.opt.sec_key_encr", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_KEY_ENCR, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_rep_opt,
{ "Options Field", "zbee_nwk_gp.cmd.comm_reply.opt", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_rep_opt_panid_present,
{ "PANID Present", "zbee_nwk_gp.cmd.comm_reply.opt.pan_id_present", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_PAN_ID_PRESENT, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_rep_opt_sec_key_present,
{ "GPD Security Key Present", "zbee_nwk_gp.cmd.comm_reply.opt.sec_key_present", FT_BOOLEAN, 8, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_SEC_KEY_PRESENT, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_rep_opt_sec_level,
{ "Security Level", "zbee_nwk_gp.cmd.comm_reply.opt.sec_level", FT_UINT8, BASE_HEX, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_SEC_LEVEL, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_rep_opt_sec_type,
{ "Key Type", "zbee_nwk_gp.cmd.comm_reply.opt.key_type", FT_UINT8, BASE_HEX, NULL,
ZBEE_NWK_GP_CMD_COMMISSIONING_REP_OPT_KEY_TYPE, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_rep_pan_id,
{ "PAN ID", "zbee_nwk_gp.cmd.comm_reply.pan_id", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_comm_rep_frame_counter,
{ "Frame Counter", "zbee_nwk_gp.cmd.comm_reply.frame_counter", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_attr_report_cluster_id,
{ "ZigBee Cluster ID", "zbee_nwk_gp.cmd.comm.attr_report", FT_UINT16, BASE_HEX, VALS(zbee_aps_cid_names),
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_channel_request_toggling_behaviour,
{ "Channel Toggling Behaviour", "zbee_nwk_gp.cmd.ch_req", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_channel_request_toggling_behaviour_1st,
{ "Rx channel in the next attempt", "zbee_nwk_gp.cmd.ch_req.1st", FT_UINT8, BASE_HEX, NULL,
ZBEE_NWK_GP_CMD_CHANNEL_REQUEST_1ST, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_channel_request_toggling_behaviour_2nd,
{ "Rx channel in the second next attempt", "zbee_nwk_gp.ch_req.2nd", FT_UINT8, BASE_HEX, NULL,
ZBEE_NWK_GP_CMD_CHANNEL_REQUEST_2ND, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_operational_channel,
{ "Operational Channel", "zbee_nwk_gp.cmd.configuration_ch", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_channel_configuration,
{ "Operation channel", "zbee_nwk_gp.cmd.configuration_ch.operation_ch", FT_UINT8, BASE_HEX, NULL,
ZBEE_NWK_GP_CMD_CHANNEL_CONFIGURATION_OPERATION_CH, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_move_color_ratex,
{ "RateX", "zbee_nwk_gp.cmd.move_color.ratex", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_move_color_ratey,
{ "RateY", "zbee_nwk_gp.cmd.move_color.ratey", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_move_up_down_rate,
{ "Rate", "zbee_nwk_gp.cmd.move_up_down.rate", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_step_color_stepx,
{ "StepX", "zbee_nwk_gp.cmd.step_color.stepx", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_step_color_stepy,
{ "StepY", "zbee_nwk_gp.cmd.step_color.stepy", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_step_color_transition_time,
{ "Transition Time", "zbee_nwk_gp.cmd.step_color.transition_time", FT_UINT16, BASE_DEC, NULL, 0x0, NULL,
HFILL }},
{ &hf_zbee_nwk_gp_cmd_step_up_down_step_size,
{ "Step Size", "zbee_nwk_gp.cmd.step_up_down.step_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_zbee_nwk_gp_cmd_step_up_down_transition_time,
{ "Transition Time", "zbee_nwk_gp.cmd.step_up_down.transition_time", FT_UINT16, BASE_DEC, NULL, 0x0, NULL,
HFILL }}
};
static ei_register_info ei[] = {
{ &ei_zbee_nwk_gp_no_payload,
{ "zbee_nwk_gp.no_payload", PI_MALFORMED, PI_ERROR,
"Payload is missing", EXPFILL }},
{ &ei_zbee_nwk_gp_inval_residual_data,
{ "zbee_nwk_gp.inval_residual_data", PI_MALFORMED, PI_ERROR,
"Invalid residual data", EXPFILL }}
};
static gint *ett[] = {
&ett_zbee_nwk,
&ett_zbee_nwk_cmd,
&ett_zbee_nwk_cmd_cinfo,
&ett_zbee_nwk_cmd_ms_ext,
&ett_zbee_nwk_cmd_options,
&ett_zbee_nwk_fcf,
&ett_zbee_nwk_fcf_ext,
&ett_zbee_nwk_cmd_comm_gpd_cmd_id_list,
&ett_zbee_nwk_cmd_comm_length_of_clid_list,
&ett_zbee_nwk_cmd_comm_clid_list_server,
&ett_zbee_nwk_cmd_comm_clid_list_client
};
static uat_field_t key_uat_fields[] = {
UAT_FLD_CSTRING(gp_uat_key_records, string, "Key", "A 16-byte key."),
UAT_FLD_VS(gp_uat_key_records, byte_order, "Byte Order", byte_order_vals, "Byte order of a key."),
UAT_FLD_LSTRING(gp_uat_key_records, label, "Label", "User label for a key."),
UAT_END_FIELDS
};
proto_zbee_nwk_gp = proto_register_protocol("ZigBee Green Power Profile", "ZigBee Green Power",
ZBEE_PROTOABBREV_NWK_GP);
gp_zbee_prefs = prefs_register_protocol(proto_zbee_nwk_gp, NULL);
zbee_gp_sec_key_table_uat = uat_new("ZigBee GP Security Keys", sizeof(uat_key_record_t), "zigbee_gp_keys", TRUE,
&gp_uat_key_records, &num_uat_key_records, UAT_AFFECTS_DISSECTION, NULL, uat_key_record_copy_cb,
uat_key_record_update_cb, uat_key_record_free_cb, uat_key_record_post_update_cb, NULL, key_uat_fields);
prefs_register_uat_preference(gp_zbee_prefs, "gp_key_table", "Pre-configured GP Security Keys",
"Pre-configured GP Security Keys.", zbee_gp_sec_key_table_uat);
register_init_routine(gp_init_zbee_security);
register_cleanup_routine(gp_cleanup_zbee_security);
proto_register_field_array(proto_zbee_nwk_gp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_zbee_nwk_gp = expert_register_protocol(proto_zbee_nwk_gp);
expert_register_field_array(expert_zbee_nwk_gp, ei, array_length(ei));
register_dissector(ZBEE_PROTOABBREV_NWK_GP, dissect_zbee_nwk_gp, proto_zbee_nwk_gp);
register_dissector(ZBEE_PROTOABBREV_NWK_GP_CMD, dissect_zbee_nwk_gp_cmd, proto_zbee_nwk_gp);
}
void
proto_reg_handoff_zbee_nwk_gp(void)
{
dissector_add_for_decode_as(IEEE802154_PROTOABBREV_WPAN_PANID, find_dissector(ZBEE_PROTOABBREV_NWK_GP));
heur_dissector_add(IEEE802154_PROTOABBREV_WPAN, dissect_zbee_nwk_heur_gp, "ZigBee Green Power over IEEE 802.15.4", "zbee_nwk_gp_wlan", proto_zbee_nwk_gp, HEURISTIC_ENABLE);
}
