static void
dissect_gmr1_dtap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 len, offset;
gmr1_msg_func_t msg_func;
const gchar *msg_str;
gint ett_tree;
int hf_idx;
proto_item *dtap_item = NULL;
proto_tree *dtap_tree = NULL;
guint32 oct[2];
guint8 pd;
len = tvb_length(tvb);
offset = 0;
oct[0] = tvb_get_guint8(tvb, offset++);
if ((oct[0] & GMR1_PD_EXT_MSK) == GMR1_PD_EXT_VAL)
pd = oct[0] & 0xff;
else
pd = oct[0] & 0x0f;
if (pd != GMR1_PD_RR) {
call_dissector(gsm_dtap_handle, tvb, pinfo, tree);
return;
}
col_append_str(pinfo->cinfo, COL_INFO, " (DTAP) ");
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ",
val_to_str(pd, gmr1_pd_short_vals, "Unknown (%u)"));
oct[1] = tvb_get_guint8(tvb, offset);
gmr1_get_msg_params((gmr1_pd_e)pd, oct[1], &msg_str, &ett_tree, &hf_idx, &msg_func);
if (msg_str == NULL)
{
dtap_item = proto_tree_add_protocol_format(
tree, proto_gmr1_dtap, tvb, 0, len,
"GMR-1 DTAP - Message Type (0x%02x)", oct[1]);
dtap_tree = proto_item_add_subtree(dtap_item, ett_gmr1_dtap);
col_append_fstr(pinfo->cinfo, COL_INFO, "Message Type (0x%02x) ", oct[1]);
}
else
{
dtap_item = proto_tree_add_protocol_format(
tree, proto_gmr1_dtap, tvb, 0, -1,
"GMR-1 DTAP - %s", msg_str);
dtap_tree = proto_item_add_subtree(dtap_item, ett_gmr1_dtap);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", msg_str);
}
offset = 0;
proto_tree_add_text(
dtap_tree, tvb, 1, 1,
"Protocol Discriminator: %s",
val_to_str(pd, gmr1_pd_vals, "Unknown (%u)")
);
offset++;
proto_tree_add_uint_format(
dtap_tree, hf_idx, tvb, offset, 1, oct[1],
"Message Type: %s", msg_str ? msg_str : "(Unknown)"
);
offset++;
if (msg_func) {
(*msg_func)(tvb, dtap_tree, pinfo, offset, len - offset);
} else {
proto_tree_add_text(dtap_tree, tvb, offset, len - offset,
"Message Elements");
}
return;
}
void
proto_register_gmr1_dtap(void)
{
#if 0
static hf_register_info hf[] = {
};
#endif
static gint *ett[] = {
&ett_gmr1_dtap,
&ett_gmr1_pd,
};
proto_register_subtree_array(ett, array_length(ett));
proto_gmr1_dtap = proto_register_protocol("GEO-Mobile Radio (1) DTAP", "GMR-1 DTAP", "gmr1.dtap");
#if 0
proto_register_field_array(proto_gmr1_dtap, hf, array_length(hf));
#endif
register_dissector("gmr1_dtap", dissect_gmr1_dtap, proto_gmr1_dtap);
}
void
proto_reg_handoff_gmr1_dtap(void)
{
dissector_handle_t dtap_handle;
dtap_handle = find_dissector("gmr1_dtap");
dissector_add_uint("lapsat.sapi", 0 , dtap_handle);
dissector_add_uint("lapsat.sapi", 3 , dtap_handle);
data_handle = find_dissector("data");
gsm_dtap_handle = find_dissector("gsm_a_dtap");
}
