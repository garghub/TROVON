static void eth_prompt(packet_info *pinfo, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Ethertype 0x%04x as",
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_ethertype, 0)));
}
static gpointer eth_value(packet_info *pinfo)
{
return p_get_proto_data(pinfo->pool, pinfo, proto_ethertype, 0);
}
static int
dissect_ethertype(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
const char *description;
tvbuff_t *volatile next_tvb;
guint length_before;
gint captured_length, reported_length;
volatile int dissector_found = 0;
const char *volatile saved_proto;
ethertype_data_t *ethertype_data;
if (data == NULL)
return 0;
ethertype_data = (ethertype_data_t*)data;
proto_tree_add_uint(ethertype_data->fh_tree, ethertype_data->etype_id, tvb,
ethertype_data->offset_after_ethertype - 2, 2, ethertype_data->etype);
captured_length = tvb_captured_length_remaining(tvb, ethertype_data->offset_after_ethertype);
reported_length = tvb_reported_length_remaining(tvb,
ethertype_data->offset_after_ethertype);
length_before = reported_length;
if (ethertype_data->fcs_len > 0) {
if (captured_length >= 0 && reported_length >= 0) {
if (reported_length >= ethertype_data->fcs_len)
reported_length -= ethertype_data->fcs_len;
if (captured_length > reported_length)
captured_length = reported_length;
}
}
next_tvb = tvb_new_subset(tvb, ethertype_data->offset_after_ethertype, captured_length,
reported_length);
p_add_proto_data(pinfo->pool, pinfo, proto_ethertype, 0, GUINT_TO_POINTER((guint)ethertype_data->etype));
saved_proto = pinfo->current_proto;
TRY {
dissector_found = dissector_try_uint(ethertype_dissector_table,
ethertype_data->etype, next_tvb, pinfo, tree);
}
CATCH_NONFATAL_ERRORS {
show_exception(next_tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
dissector_found = 1;
pinfo->current_proto = saved_proto;
}
ENDTRY;
if (!dissector_found) {
call_data_dissector(next_tvb, pinfo, tree);
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "0x%04x", ethertype_data->etype);
description = try_val_to_str(ethertype_data->etype, etype_vals);
if (description) {
col_add_str(pinfo->cinfo, COL_INFO, description);
}
}
add_dix_trailer(pinfo, tree, ethertype_data->fh_tree, ethertype_data->trailer_id, tvb, next_tvb, ethertype_data->offset_after_ethertype,
length_before, ethertype_data->fcs_len);
return tvb_captured_length(tvb);
}
static void
add_dix_trailer(packet_info *pinfo, proto_tree *tree, proto_tree *fh_tree, int trailer_id,
tvbuff_t *tvb, tvbuff_t *next_tvb, int offset_after_etype,
guint length_before, gint fcs_len)
{
guint length;
tvbuff_t *trailer_tvb;
length = tvb_reported_length(next_tvb);
if (length < length_before) {
if (tvb_offset_exists(tvb, offset_after_etype + length)) {
trailer_tvb = tvb_new_subset_remaining(tvb,
offset_after_etype + length);
} else {
trailer_tvb = NULL;
}
} else
trailer_tvb = NULL;
add_ethernet_trailer(pinfo, tree, fh_tree, trailer_id, tvb, trailer_tvb, fcs_len);
}
void
proto_register_ethertype(void)
{
static build_valid_func eth_da_build_value[1] = {eth_value};
static decode_as_value_t eth_da_values = {eth_prompt, 1, eth_da_build_value};
static decode_as_t ethertype_da = {"ethertype", "Link", "ethertype", 1, 0, &eth_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
proto_ethertype = proto_register_protocol("Ethertype", "Ethertype", "ethertype");
proto_set_cant_toggle(proto_ethertype);
register_dissector("ethertype", dissect_ethertype, proto_ethertype);
ethertype_dissector_table = register_dissector_table("ethertype",
"Ethertype", proto_ethertype, FT_UINT16, BASE_HEX);
register_capture_dissector_table("ethertype", "Ethertype");
register_decode_as(&ethertype_da);
}
