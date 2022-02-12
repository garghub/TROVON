void
dissect_802_3(volatile int length, gboolean is_802_2, tvbuff_t *tvb,
int offset_after_length, packet_info *pinfo, proto_tree *tree,
proto_tree *fh_tree, int length_id, int trailer_id,
int fcs_len)
{
proto_item *length_it;
tvbuff_t *volatile next_tvb = NULL;
tvbuff_t *volatile trailer_tvb = NULL;
const char *saved_proto;
gint captured_length, reported_length;
void *pd_save;
length_it = proto_tree_add_uint(fh_tree, length_id, tvb,
offset_after_length - 2, 2, length);
reported_length = tvb_reported_length_remaining(tvb, offset_after_length);
if (fcs_len > 0) {
if (reported_length >= fcs_len)
reported_length -= fcs_len;
}
if (length > reported_length) {
length = reported_length;
expert_add_info_format(pinfo, length_it, PI_MALFORMED, PI_ERROR,
"Length field value goes past the end of the payload");
}
captured_length = tvb_length_remaining(tvb, offset_after_length);
if (captured_length > length)
captured_length = length;
next_tvb = tvb_new_subset(tvb, offset_after_length, captured_length, length);
TRY {
trailer_tvb = tvb_new_subset_remaining(tvb, offset_after_length + length);
}
CATCH2(BoundsError, ReportedBoundsError) {
trailer_tvb = NULL;
}
ENDTRY;
saved_proto = pinfo->current_proto;
pd_save = pinfo->private_data;
TRY {
if (is_802_2)
call_dissector(llc_handle, next_tvb, pinfo, tree);
else {
if (tvb_get_bits8(next_tvb, 0, 3) == 7)
call_dissector(ipx_handle, next_tvb, pinfo, tree);
else
call_dissector(ccsds_handle, next_tvb, pinfo, tree);
}
}
CATCH(BoundsError) {
RETHROW;
}
CATCH_ALL {
pinfo->private_data = pd_save;
show_exception(next_tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
pinfo->current_proto = saved_proto;
}
ENDTRY;
add_ethernet_trailer(pinfo, tree, fh_tree, trailer_id, tvb, trailer_tvb, fcs_len);
}
void
proto_reg_handoff_ieee802_3(void)
{
ipx_handle = find_dissector("ipx");
llc_handle = find_dissector("llc");
ccsds_handle = find_dissector("ccsds");
}
