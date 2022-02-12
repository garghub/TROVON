static void eth_prompt(packet_info *pinfo, gchar* result)
{
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Ethertype 0x%04x as",
GPOINTER_TO_UINT(p_get_proto_data(pinfo->pool, pinfo, proto_ethertype, 0)));
}
static gpointer eth_value(packet_info *pinfo)
{
return p_get_proto_data(pinfo->pool, pinfo, proto_ethertype, 0);
}
void
capture_ethertype(guint16 etype, const guchar *pd, int offset, int len,
packet_counts *ld)
{
switch (etype) {
case ETHERTYPE_ARP:
ld->arp++;
break;
case ETHERTYPE_IP:
capture_ip(pd, offset, len, ld);
break;
case ETHERTYPE_IPv6:
capture_ipv6(pd, offset, len, ld);
break;
case ETHERTYPE_IPX:
capture_ipx(ld);
break;
case ETHERTYPE_VLAN:
capture_vlan(pd, offset, len, ld);
break;
case ETHERTYPE_IEEE_802_1AD:
case ETHERTYPE_IEEE_802_1AH:
capture_ieee8021ah(pd, offset, len, ld);
break;
case ETHERTYPE_VINES_IP:
case ETHERTYPE_VINES_ECHO:
capture_vines(ld);
break;
case ETHERTYPE_BPQ:
capture_bpq(pd, offset, len, ld);
break;
default:
ld->other++;
break;
}
}
static int
dissect_ethertype(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
const char *description;
tvbuff_t *volatile next_tvb;
guint length_before;
gint captured_length, reported_length;
volatile gboolean dissector_found = FALSE;
const char *volatile saved_proto;
void *pd_save;
ethertype_data_t *ethertype_data;
if (data == NULL)
return 0;
ethertype_data = (ethertype_data_t*)data;
proto_tree_add_uint(ethertype_data->fh_tree, ethertype_data->etype_id, tvb,
ethertype_data->offset_after_ethertype - 2, 2, ethertype_data->etype);
captured_length = tvb_length_remaining(tvb, ethertype_data->offset_after_ethertype);
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
pd_save = pinfo->private_data;
TRY {
dissector_found = dissector_try_uint(ethertype_dissector_table,
ethertype_data->etype, next_tvb, pinfo, tree);
}
CATCH_NONFATAL_ERRORS {
show_exception(next_tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
pinfo->private_data = pd_save;
dissector_found = TRUE;
pinfo->current_proto = saved_proto;
}
ENDTRY;
if (!dissector_found) {
call_dissector(data_handle,next_tvb, pinfo, tree);
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "0x%04x", ethertype_data->etype);
description = try_val_to_str(ethertype_data->etype, etype_vals);
if (description) {
col_add_str(pinfo->cinfo, COL_INFO, description);
}
}
add_dix_trailer(pinfo, tree, ethertype_data->fh_tree, ethertype_data->trailer_id, tvb, next_tvb, ethertype_data->offset_after_ethertype,
length_before, ethertype_data->fcs_len);
return tvb_length(tvb);
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
new_register_dissector("ethertype", dissect_ethertype, proto_ethertype);
ethertype_dissector_table = register_dissector_table("ethertype",
"Ethertype", FT_UINT16, BASE_HEX);
register_decode_as(&ethertype_da);
}
void
proto_reg_handoff_ethertype(void)
{
data_handle = find_dissector("data");
}
