static void
dissect_ipars(tvbuff_t *tvb, packet_info *pinfo _U_ , proto_tree *tree)
{
proto_tree *ipars_tree = NULL;
proto_item *ti;
int bytes;
guint8 ia = 0, ta = 0, cmd = 0, la = 0;
tvbuff_t *next_tvb;
int offset = 0;
gchar *eom_msg;
eom_msg = ep_alloc(MAX_EOM_MSG_SIZE);
eom_msg[0] = 0;
col_clear(pinfo->cinfo, COL_INFO);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPARS");
if (tvb_length_remaining(tvb, 0) >= 2 ) {
ia = tvb_get_guint8(tvb, 0) & 0x3f;
ta = tvb_get_guint8(tvb, 1) & 0x3f;
if (ia == S1 && ta == S2) {
offset = 2;
}
}
if (tvb_length_remaining(tvb, offset) >= 1) ia = tvb_get_guint8(tvb, offset + 0);
if (tvb_length_remaining(tvb, offset) >= 2) ta = tvb_get_guint8(tvb, offset + 1);
if (ia == 0x83 || ia == 0x43 || ia == GA) {
if (tvb_length_remaining(tvb, offset) > 2) {
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Poll IA: %2.2X", ta);
} else {
if (tvb_length_remaining(tvb, offset) >= 2 ) {
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "GoAhead NextIA (0x%2.2X)", ta);
} else {
if (check_col(pinfo->cinfo, COL_INFO))
col_set_str(pinfo->cinfo, COL_INFO, "GoAhead NextIA");
}
}
} else {
ia &= 0x3f;
ta &= 0x3f;
if (ta == 0x20) {
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Reset IA: %2.2X", ia);
}
if (tvb_length_remaining(tvb, offset) >= 3) cmd = tvb_get_guint8(tvb, offset + 2) & 0x3f;
if (tvb_length_remaining(tvb, offset) >= 4) la = tvb_get_guint8(tvb, offset + 3) & 0x3f;
if (cmd == 0x1f && la == 0x38) {
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Please Resend - IA: %2.2X TA: %2.2X", ia, ta);
} else if (cmd == 0x2a && la == 0x05) {
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Unsolicited Msg Indicator - IA: %2.2X TA: %2.2X", ia, ta);
} else {
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Data Msg - IA: %2.2X TA: %2.2X", ia, ta);
}
}
if (tree) {
bytes = tvb_length_remaining(tvb, 0);
if (bytes > 0) {
ia = tvb_get_guint8(tvb, 0) & 0x3f;
ti = proto_tree_add_protocol_format(tree, proto_ipars, tvb, 0, -1, "Ipars");
ipars_tree = proto_item_add_subtree(ti, ett_ipars);
if (ia == 0x03) {
proto_tree_add_protocol_format(ipars_tree, proto_ipars, tvb, 0, 1, "GoAhead Next IA");
if (check_col(pinfo->cinfo, COL_INFO))
col_set_str(pinfo->cinfo, COL_INFO, "GoAhead");
return;
} else if (ia != S1) {
proto_tree_add_protocol_format(ipars_tree, proto_ipars, tvb,
0,
bytes, "Unknown format - Data (%d byte%s)", bytes,
plurality(bytes, "", "s"));
return;
}
proto_tree_add_protocol_format(ipars_tree, proto_ipars, tvb, 0, 1, "S1");
ia = tvb_get_guint8(tvb, 1) & 0x3f;
if (ia != S2) {
proto_tree_add_protocol_format(ipars_tree, proto_ipars, tvb,
0,
bytes, "Unknown format - Data (%d byte%s)", bytes,
plurality(bytes, "", "s"));
return;
}
proto_tree_add_protocol_format(ipars_tree, proto_ipars, tvb, 1, 1, "S2");
ia = tvb_get_guint8(tvb, 2) & 0x3f;
if (ia == GA) {
ia = tvb_get_guint8(tvb, 3) & 0x3f;
proto_tree_add_protocol_format(ipars_tree, proto_ipars, tvb, 2, 2, "GoAhead IA: %2.2X", ia);
ipars_eomtype = tvb_get_guint8(tvb, 4) & 0x3f;
switch (ipars_eomtype) {
case EOMc: g_snprintf(eom_msg, MAX_EOM_MSG_SIZE, "EOMc"); break;
case EOMi: g_snprintf(eom_msg, MAX_EOM_MSG_SIZE, "EOMi"); break;
case EOMu: g_snprintf(eom_msg, MAX_EOM_MSG_SIZE, "EOMu"); break;
case EOMpb: g_snprintf(eom_msg, MAX_EOM_MSG_SIZE, "EOMpb"); break;
default: g_snprintf(eom_msg, MAX_EOM_MSG_SIZE, "Unknown EOM type (0x%2.2X)", ia); break;
}
proto_tree_add_protocol_format(ipars_tree, proto_ipars, tvb, 4, 1, "%s", eom_msg);
ia = tvb_get_guint8(tvb, 5) & 0x3f;
proto_tree_add_protocol_format(ipars_tree, proto_ipars, tvb, 5, 1, "Good BCC");
} else {
next_tvb = tvb_new_subset_remaining(tvb, 3);
proto_tree_add_protocol_format(ipars_tree, proto_ipars, next_tvb,
0,
bytes, "Data (%d byte%s)", bytes,
plurality(bytes, "", "s"));
return;
}
}
}
}
void
proto_register_ipars(void)
{
static gint *ett[] = {
&ett_ipars,
};
proto_ipars = proto_register_protocol("International Passenger Airline Reservation System", "IPARS", "ipars");
proto_register_subtree_array(ett, array_length(ett));
register_dissector("ipars", dissect_ipars, proto_ipars);
}
