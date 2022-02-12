static void
dissect_sscf_nni(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint reported_length;
proto_item *sscf_item = NULL;
proto_tree *sscf_tree = NULL;
guint8 sscf_status;
reported_length = tvb_reported_length(tvb);
if (tree) {
sscf_item = proto_tree_add_item(tree, proto_sscf, tvb, 0, -1, ENC_NA);
sscf_tree = proto_item_add_subtree(sscf_item, ett_sscf);
}
if (reported_length > SSCF_PDU_LENGTH)
{
call_dissector(mtp3_handle, tvb, pinfo, tree);
} else {
sscf_status = tvb_get_guint8(tvb, SSCF_STATUS_OFFSET);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SSCF-NNI");
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "STATUS (%s) ",
val_to_str_const(sscf_status, sscf_status_vals, "Unknown"));
proto_tree_add_item(sscf_tree, hf_status, tvb, SSCF_STATUS_OFFSET,
SSCF_STATUS_LENGTH, ENC_BIG_ENDIAN);
proto_tree_add_item(sscf_tree, hf_spare, tvb, SSCF_SPARE_OFFSET,
SSCF_SPARE_LENGTH, ENC_BIG_ENDIAN);
}
}
void
proto_register_sscf(void)
{
static hf_register_info hf[] =
{ { &hf_status, { "Status", "sscf-nni.status", FT_UINT8, BASE_HEX,
VALS(sscf_status_vals), 0x0, NULL, HFILL} },
{ &hf_spare, { "Spare", "sscf-nni.spare", FT_UINT24, BASE_HEX,
NULL, 0x0, NULL, HFILL} }
};
static gint *ett[] = {
&ett_sscf,
};
proto_sscf = proto_register_protocol("SSCF-NNI", "SSCF-NNI", "sscf-nni");
proto_register_field_array(proto_sscf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("sscf-nni", dissect_sscf_nni, proto_sscf);
}
void
proto_reg_handoff_sscf(void)
{
mtp3_handle = find_dissector("mtp3");
}
