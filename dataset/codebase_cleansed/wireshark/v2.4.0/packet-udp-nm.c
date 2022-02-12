static gboolean
user_data_fields_update_cb(void *r, char **err)
{
user_data_field_t *rec = (user_data_field_t *)r;
char c;
*err = NULL;
if (rec->udf_length == 0) {
*err = g_strdup_printf("length of user data field can't be 0 Bytes (name: %s offset: %i length: %i)", rec->udf_name, rec->udf_offset, rec->udf_length);
return (*err == NULL);
}
if (rec->udf_length > 4) {
*err = g_strdup_printf("length of user data field can't be greater 4 Bytes (name: %s offset: %i length: %i)", rec->udf_name, rec->udf_offset, rec->udf_length);
return (*err == NULL);
}
if (rec->udf_offset < 2) {
*err = g_strdup_printf("offset of user data field can't be short than 2 (name: %s offset: %i length: %i)", rec->udf_name, rec->udf_offset, rec->udf_length);
return (*err == NULL);
}
if (rec->udf_mask >= G_MAXUINT32) {
*err = g_strdup_printf("mask can only be up to 32bits (name: %s)", rec->udf_name);
return (*err == NULL);
}
if (rec->udf_name == NULL) {
*err = g_strdup_printf("Name of user data field can't be empty");
return (*err == NULL);
}
g_strstrip(rec->udf_name);
if (rec->udf_name[0] == 0) {
*err = g_strdup_printf("Name of user data field can't be empty");
return (*err == NULL);
}
c = proto_check_field_name(rec->udf_name);
if (c) {
*err = g_strdup_printf("Name of user data field can't contain '%c'", c);
return (*err == NULL);
}
return (*err == NULL);
}
static void *
user_data_fields_copy_cb(void* n, const void* o, size_t siz _U_)
{
user_data_field_t* new_rec = (user_data_field_t*)n;
const user_data_field_t* old_rec = (const user_data_field_t*)o;
if (old_rec->udf_name) {
new_rec->udf_name = g_strdup(old_rec->udf_name);
}
else {
new_rec->udf_name = NULL;
}
if (old_rec->udf_desc) {
new_rec->udf_desc = g_strdup(old_rec->udf_desc);
}
else {
new_rec->udf_desc = NULL;
}
new_rec->udf_offset = old_rec->udf_offset;
new_rec->udf_length = old_rec->udf_length;
new_rec->udf_mask = old_rec->udf_mask;
if (old_rec->udf_value_desc) {
new_rec->udf_value_desc = g_strdup(old_rec->udf_value_desc);
}
else {
new_rec->udf_value_desc = NULL;
}
return new_rec;
}
static void
user_data_fields_free_cb(void*r)
{
user_data_field_t* rec = (user_data_field_t*)r;
if (rec->udf_name) g_free(rec->udf_name);
if (rec->udf_desc) g_free(rec->udf_desc);
if (rec->udf_value_desc) g_free(rec->udf_value_desc);
}
static guint64
calc_ett_key(guint32 offset, guint32 length)
{
guint64 ret = offset;
return (ret * 0x100000000) ^ length;
}
static gchar*
calc_hf_key(user_data_field_t udf)
{
gchar* ret = NULL;
ret = g_strdup_printf("%i-%i-%i-%s", udf.udf_offset, udf.udf_length, udf.udf_mask, udf.udf_name);
return ret;
}
static gint*
get_hf_for_user_data(gchar* key)
{
gint* hf_id = NULL;
if (user_data_fields_hash_hf) {
hf_id = (gint*)g_hash_table_lookup(user_data_fields_hash_hf, key);
}
else {
hf_id = NULL;
}
return hf_id;
}
static gint*
get_ett_for_user_data(guint32 offset, guint32 length)
{
gint* ett_id = NULL;
guint64 key = calc_ett_key(offset, length);
if (user_data_fields_hash_ett) {
ett_id = (gint*)g_hash_table_lookup(user_data_fields_hash_ett, &key);
}
else {
ett_id = NULL;
}
return ett_id;
}
static void
user_data_post_update_cb(void)
{
static hf_register_info* hf;
gint* hf_id;
guint i;
gchar* tmp = NULL;
guint64* key = NULL;
static gint ett_dummy = -1;
static gint *ett[] = {
&ett_dummy,
};
static gint *ett_id;
if (user_data_fields_hash_hf && hf) {
guint hf_size = g_hash_table_size(user_data_fields_hash_hf);
for (i = 0; i < hf_size; i++) {
proto_deregister_field(proto_udp_nm, *(hf[i].p_id));
}
g_hash_table_destroy(user_data_fields_hash_hf);
user_data_fields_hash_hf = NULL;
}
if (num_user_data_fields) {
user_data_fields_hash_hf = g_hash_table_new(g_str_hash, g_str_equal);
hf = g_new0(hf_register_info, num_user_data_fields);
if (user_data_fields_hash_ett == NULL) {
user_data_fields_hash_ett = g_hash_table_new(g_int64_hash, g_int64_equal);
}
for (i = 0; i < num_user_data_fields; i++) {
hf_id = g_new(gint, 1);
*hf_id = -1;
hf[i].p_id = hf_id;
hf[i].hfinfo.strings = NULL;
hf[i].hfinfo.bitmask = user_data_fields[i].udf_mask;
hf[i].hfinfo.same_name_next = NULL;
hf[i].hfinfo.same_name_prev_id = -1;
if (user_data_fields[i].udf_mask == 0 || user_data_fields[i].udf_length <= 0 || user_data_fields[i].udf_length>4) {
hf[i].hfinfo.name = g_strdup(user_data_fields[i].udf_name);
hf[i].hfinfo.abbrev = g_strdup_printf("nm.user_data.%s", user_data_fields[i].udf_name);
hf[i].hfinfo.type = FT_BYTES;
hf[i].hfinfo.display = BASE_NONE;
hf[i].hfinfo.bitmask = 0;
hf[i].hfinfo.blurb = g_strdup(user_data_fields[i].udf_desc);
}
else {
hf[i].hfinfo.name = g_strdup(user_data_fields[i].udf_value_desc);
hf[i].hfinfo.abbrev = g_strdup_printf("nm.user_data.%s.%s", user_data_fields[i].udf_name, user_data_fields[i].udf_value_desc);
hf[i].hfinfo.type = FT_BOOLEAN;
hf[i].hfinfo.display = 8 * (user_data_fields[i].udf_length);
hf[i].hfinfo.blurb = g_strdup(user_data_fields[i].udf_value_desc);
}
tmp = calc_hf_key(user_data_fields[i]);
g_hash_table_insert(user_data_fields_hash_hf, tmp, hf_id);
if (get_ett_for_user_data(user_data_fields[i].udf_offset, user_data_fields[i].udf_length) == NULL) {
ett_dummy = -1;
proto_register_subtree_array(ett, array_length(ett));
ett_id = g_new(gint, 1);
*ett_id = ett_dummy;
key = g_new(guint64, 1);
*key = calc_ett_key(user_data_fields[i].udf_offset, user_data_fields[i].udf_length);
g_hash_table_insert(user_data_fields_hash_ett, key, ett_id);
}
}
proto_register_field_array(proto_udp_nm, hf, num_user_data_fields);
}
}
static int
dissect_udp_nm(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *udp_nm_tree;
proto_tree *udp_nm_subtree = NULL;
gchar* tmp = NULL;
guint32 offset = 0;
guint32 length = 0;
guint32 msg_length = 0;
guint32 ctrl_bit_vector;
guint32 src_node_id = 0;
guint i = 0;
int* hf_id;
int ett_id;
guint32 offset_ctrl_bit_vector = 1;
guint32 offset_src_node_id = 0;
static const int * control_bits[] = {
&hf_udp_nm_control_bit_vector_repeat_msg_req,
&hf_udp_nm_control_bit_vector_nm_coord_sleep,
&hf_udp_nm_control_bit_vector_active_wakeup,
&hf_udp_nm_control_bit_vector_pni,
NULL
};
if (g_udp_nm_swap_first_fields == TRUE) {
offset_ctrl_bit_vector = 0;
offset_src_node_id = 1;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NM");
col_clear(pinfo->cinfo, COL_INFO);
msg_length = tvb_reported_length(tvb);
ti = proto_tree_add_item(tree, proto_udp_nm, tvb, 0, -1, ENC_NA);
udp_nm_tree = proto_item_add_subtree(ti, ett_udp_nm);
if (g_udp_nm_swap_first_fields == FALSE) {
proto_tree_add_item_ret_uint(udp_nm_tree, hf_udp_nm_source_node_identifier, tvb, offset_src_node_id, 1, ENC_BIG_ENDIAN, &src_node_id);
}
proto_tree_add_bitmask(udp_nm_tree, tvb, offset_ctrl_bit_vector, hf_udp_nm_control_bit_vector, ett_udp_nm_cbv, control_bits, ENC_BIG_ENDIAN);
ctrl_bit_vector = tvb_get_guint8(tvb, offset_ctrl_bit_vector);
if (g_udp_nm_swap_first_fields == TRUE) {
proto_tree_add_item_ret_uint(udp_nm_tree, hf_udp_nm_source_node_identifier, tvb, offset_src_node_id, 1, ENC_BIG_ENDIAN, &src_node_id);
}
col_add_fstr(pinfo->cinfo, COL_INFO, "Control Bit Vector: 0x%02x, Source Node: 0x%02x", ctrl_bit_vector, src_node_id);
proto_item_append_text(ti, ", Control Bit Vector: 0x%02x, Source Node: %i", ctrl_bit_vector, src_node_id);
offset = 2;
ti = proto_tree_add_item(udp_nm_tree, hf_udp_nm_user_data, tvb, offset, msg_length - offset, ENC_NA);
udp_nm_tree = proto_item_add_subtree(ti, ett_udp_nm_user_data);
for (i = 0; i < num_user_data_fields; i++) {
tmp = calc_hf_key(user_data_fields[i]);
hf_id = get_hf_for_user_data(tmp);
offset = user_data_fields[i].udf_offset;
length = user_data_fields[i].udf_length;
ett_id = *(get_ett_for_user_data(offset, length));
if (hf_id && msg_length >= length + offset) {
if (user_data_fields[i].udf_mask == 0) {
ti = proto_tree_add_item(udp_nm_tree, *hf_id, tvb, offset, length, ENC_BIG_ENDIAN);
udp_nm_subtree = proto_item_add_subtree(ti, ett_id);
}
else {
if (udp_nm_subtree != NULL) {
proto_tree_add_item(udp_nm_subtree, *hf_id, tvb, offset, length, ENC_BIG_ENDIAN);
}
}
}
else {
}
g_free(tmp);
}
return 8;
}
void proto_register_udp_nm(void)
{
module_t *udp_nm_module;
uat_t* user_data_fields_uat;
static hf_register_info hf_udp_nm[] = {
{ &hf_udp_nm_control_bit_vector,
{ "Control Bit Vector", "nm.ctrl", FT_UINT8, BASE_HEX, NULL, 0x0, "The Control Bit Vector", HFILL } },
{ &hf_udp_nm_control_bit_vector_repeat_msg_req,
{ "Repeat Message Request", "nm.ctrl.repeat_msg_req", FT_BOOLEAN, 8, TFS(&tfs_udp_nm_control_rep_msg_req), 0x01, "The Repeat Message Request Bit", HFILL } },
{ &hf_udp_nm_control_bit_vector_nm_coord_sleep,
{ "NM Coordinator Sleep", "nm.ctrl.nm_coord_sleep", FT_BOOLEAN, 8, TFS(&tfs_udp_nm_control_sleep_bit), 0x08, "NM Coordinator Sleep Bit", HFILL } },
{ &hf_udp_nm_control_bit_vector_active_wakeup,
{ "Active Wakeup", "nm.ctrl.active_wakeup", FT_BOOLEAN, 8, TFS(&tfs_udp_nm_control_active_wakeup), 0x10, "Active Wakeup Bit", HFILL } },
{ &hf_udp_nm_control_bit_vector_pni,
{ "Partial Network Information", "nm.ctrl.pni", FT_BOOLEAN, 8, TFS(&tfs_udp_nm_control_pni), 0x40, "Partial Network Information Bit", HFILL } },
{ &hf_udp_nm_source_node_identifier,
{ "Source Node Identifier", "nm.src", FT_UINT8, BASE_DEC, NULL, 0x0, "The identification of the sending node", HFILL } },
{ &hf_udp_nm_user_data,
{ "User Data", "nm.user_data", FT_BYTES, BASE_NONE, NULL, 0x0, "The User Data", HFILL } },
};
static gint *ett[] = {
&ett_udp_nm,
&ett_udp_nm_cbv,
&ett_udp_nm_user_data,
};
static uat_field_t user_data_uat_fields[] = {
UAT_FLD_CSTRING(user_data_fields, udf_name, "User data name", "Name of user data field"),
UAT_FLD_CSTRING(user_data_fields, udf_desc, "User data desc", "Description of user data field"),
UAT_FLD_DEC(user_data_fields, udf_offset, "User data offset", "Offset of the user data field in the UDP-NM message (uint32)"),
UAT_FLD_DEC(user_data_fields, udf_length, "User data length", "Length of the user data field in the UDP-NM message (uint32)"),
UAT_FLD_DEC(user_data_fields, udf_mask, "User data mask", "Relevant bits of the user data field in the UDP-NM message (uint32)"),
UAT_FLD_CSTRING(user_data_fields, udf_value_desc, "User data value", "Description what the masked bits mean"),
UAT_END_FIELDS
};
proto_udp_nm = proto_register_protocol("Network Management", "NM", "nm");
proto_register_field_array(proto_udp_nm, hf_udp_nm, array_length(hf_udp_nm));
proto_register_subtree_array(ett, array_length(ett));
udp_nm_module = prefs_register_protocol(proto_udp_nm, NULL);
prefs_register_bool_preference(udp_nm_module, "swap_ctrl_and_src",
"Swap Source Node Identifier and Control Bit Vector",
"In the standard the Source Node Identifier is the first byte "
"and the Control Bit Vector is the second byte. "
"Using this parameter they can be swapped",
&g_udp_nm_swap_first_fields);
user_data_fields_uat = uat_new("NM User Data Fields Table",
sizeof(user_data_field_t),
"NM_user_data_fields",
TRUE,
&user_data_fields,
&num_user_data_fields,
UAT_AFFECTS_DISSECTION | UAT_AFFECTS_FIELDS,
NULL,
user_data_fields_copy_cb,
user_data_fields_update_cb,
user_data_fields_free_cb,
user_data_post_update_cb,
NULL,
user_data_uat_fields);
prefs_register_uat_preference(udp_nm_module, "udp_nm_user_data_fields", "User Data Field Configuration",
"A table to define user defined fields in the NM payload",
user_data_fields_uat);
}
void proto_reg_handoff_udp_nm(void)
{
dissector_handle_t nm_handle = create_dissector_handle(dissect_udp_nm, proto_udp_nm);
dissector_add_for_decode_as_with_preference("udp.port", nm_handle);
dissector_add_for_decode_as("can.subdissector", nm_handle);
}
