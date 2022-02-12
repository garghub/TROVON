static int dissect_mac_lte_framed(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data _U_)
{
gint offset = 0;
struct mac_lte_info *p_mac_lte_info;
tvbuff_t *mac_tvb;
gboolean infoAlreadySet = FALSE;
dissector_handle_t mac_lte_handle = find_dissector("mac-lte");
if (!mac_lte_handle) {
return 0;
}
if ((size_t)tvb_reported_length_remaining(tvb, offset) < (3+2)) {
return 5;
}
p_mac_lte_info = (struct mac_lte_info*)p_get_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0);
if (p_mac_lte_info == NULL) {
p_mac_lte_info = (struct mac_lte_info*)wmem_alloc0(wmem_file_scope(), sizeof(struct mac_lte_info));
infoAlreadySet = FALSE;
}
else {
infoAlreadySet = TRUE;
}
if (!dissect_mac_lte_context_fields(p_mac_lte_info, tvb, &offset)) {
return offset;
}
if (!infoAlreadySet) {
p_add_proto_data(wmem_file_scope(), pinfo, proto_mac_lte, 0, p_mac_lte_info);
}
mac_tvb = tvb_new_subset_remaining(tvb, offset);
call_dissector_only(mac_lte_handle, mac_tvb, pinfo, tree, NULL);
return tvb_captured_length(tvb);
}
void proto_register_mac_lte_framed(void)
{
proto_mac_lte_framed = proto_register_protocol("mac-lte-framed", "MAC-LTE-FRAMED", "mac-lte-framed");
register_dissector("mac-lte-framed", dissect_mac_lte_framed, proto_mac_lte_framed);
}
