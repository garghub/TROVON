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
default:
ld->other++;
break;
}
}
void
ethertype(guint16 etype, tvbuff_t *tvb, int offset_after_etype,
packet_info *pinfo, proto_tree *tree, proto_tree *fh_tree,
int etype_id, int trailer_id, int fcs_len)
{
const char *description;
tvbuff_t *volatile next_tvb;
guint length_before;
gint captured_length, reported_length;
volatile gboolean dissector_found = FALSE;
const char *volatile saved_proto;
void *pd_save;
if (tree) {
proto_tree_add_uint(fh_tree, etype_id, tvb,
offset_after_etype - 2, 2, etype);
}
captured_length = tvb_length_remaining(tvb, offset_after_etype);
reported_length = tvb_reported_length_remaining(tvb,
offset_after_etype);
length_before = reported_length;
if (fcs_len > 0) {
if (captured_length >= 0 && reported_length >= 0) {
if (reported_length >= fcs_len)
reported_length -= fcs_len;
if (captured_length > reported_length)
captured_length = reported_length;
}
}
next_tvb = tvb_new_subset(tvb, offset_after_etype, captured_length,
reported_length);
pinfo->ethertype = etype;
saved_proto = pinfo->current_proto;
pd_save = pinfo->private_data;
TRY {
dissector_found = dissector_try_uint(ethertype_dissector_table,
etype, next_tvb, pinfo, tree);
}
CATCH(BoundsError) {
RETHROW;
}
CATCH(OutOfMemoryError) {
RETHROW;
}
CATCH_ALL {
show_exception(next_tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
pinfo->private_data = pd_save;
dissector_found = TRUE;
pinfo->current_proto = saved_proto;
}
ENDTRY;
if (!dissector_found) {
call_dissector(data_handle,next_tvb, pinfo, tree);
col_add_fstr(pinfo->cinfo, COL_PROTOCOL, "0x%04x", etype);
description = match_strval(etype, etype_vals);
if (description) {
col_add_str(pinfo->cinfo, COL_INFO, description);
}
}
add_dix_trailer(pinfo, tree, fh_tree, trailer_id, tvb, next_tvb, offset_after_etype,
length_before, fcs_len);
}
static void
add_dix_trailer(packet_info *pinfo, proto_tree *tree, proto_tree *fh_tree, int trailer_id,
tvbuff_t *tvb, tvbuff_t *next_tvb, int offset_after_etype,
guint length_before, gint fcs_len)
{
guint length;
tvbuff_t *trailer_tvb;
if (fh_tree == NULL)
return;
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
ethertype_dissector_table = register_dissector_table("ethertype",
"Ethertype", FT_UINT16, BASE_HEX);
}
void
proto_reg_handoff_ethertype(void)
{
data_handle = find_dissector("data");
}
