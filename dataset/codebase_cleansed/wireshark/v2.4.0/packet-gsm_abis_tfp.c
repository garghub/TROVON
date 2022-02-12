static int
dissect_abis_tfp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *tfp_tree;
int offset = 0;
guint32 slot_rate, frame_bits, atsr, seq_nr;
guint8 ftype;
tvbuff_t *next_tvb;
gint len_remain;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TFP");
ti = proto_tree_add_item(tree, proto_abis_tfp, tvb, 0, -1, ENC_NA);
tfp_tree = proto_item_add_subtree(ti, ett_tfp);
proto_tree_add_item_ret_uint(tfp_tree, hf_tfp_hdr_atsr, tvb, offset, 2, ENC_BIG_ENDIAN, &atsr);
proto_tree_add_item_ret_uint(tfp_tree, hf_tfp_hdr_slot_rate, tvb, offset, 2, ENC_BIG_ENDIAN, &slot_rate);
proto_tree_add_item_ret_uint(tfp_tree, hf_tfp_hdr_seq_nr, tvb, offset, 2, ENC_BIG_ENDIAN, &seq_nr);
proto_tree_add_item(tfp_tree, hf_tfp_hdr_delay_info, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tfp_tree, hf_tfp_hdr_p, tvb, offset+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tfp_tree, hf_tfp_hdr_s, tvb, offset+2, 1, ENC_NA);
proto_tree_add_item(tfp_tree, hf_tfp_hdr_m, tvb, offset+2, 1, ENC_NA);
ftype = tvb_get_guint8(tvb, offset+2) & 0x1E;
if (slot_rate == 0)
ftype |= 0x80;
proto_tree_add_uint_format_value(tfp_tree, hf_tfp_hdr_frame_type, tvb, offset+2, 1, ftype, "%s",
val_to_str(ftype, tfp_frame_type_vals, "Unknown (%u)"));
offset += 2;
col_append_fstr(pinfo->cinfo, COL_INFO, "TS=%u, Seq=%u, %s, %s ", atsr, seq_nr,
val_to_str(slot_rate, tfp_slot_rate_vals, "Unknown (%u)"),
val_to_str(ftype, tfp_frame_type_vals, "Unknown (%u)"));
while ((tvb_get_guint8(tvb, offset) & 0x01) == 0)
offset++;
offset++;
switch (ftype & 0x7F) {
case 0:
len_remain = tvb_captured_length_remaining(tvb, offset);
proto_tree_add_uint(tfp_tree, hf_tfp_amr_rate, tvb, offset, 0, len_remain);
break;
case 1:
break;
case 2:
break;
case 3:
break;
case 4:
break;
}
if (slot_rate == 0)
frame_bits = 320;
else
frame_bits = 160;
next_tvb = tvb_new_subset_length(tvb, offset, frame_bits/8);
call_dissector(sub_handles[SUB_DATA], next_tvb, pinfo, tree);
return offset;
}
void
proto_register_abis_tfp(void)
{
static hf_register_info hf[] = {
{ &hf_tfp_hdr_atsr,
{ "Air Timeslot Resource", "gsm_abis_tfp.atsr",
FT_UINT16, BASE_DEC, NULL, 0xe000,
NULL, HFILL }
},
{ &hf_tfp_hdr_slot_rate,
{ "Slot Rate", "gsm_abis_tfp.slot_rate",
FT_UINT16, BASE_DEC, VALS(tfp_slot_rate_vals), 0x1800,
NULL, HFILL }
},
{ &hf_tfp_hdr_seq_nr,
{ "Sequence Number", "gsm_abis_tfp.seq_nr",
FT_UINT16, BASE_DEC, NULL, 0x07c0,
NULL, HFILL }
},
{ &hf_tfp_hdr_delay_info,
{ "Delay Information (ms)", "gsm_abis_tfp.delay_info",
FT_UINT16, BASE_DEC, NULL, 0x003e,
NULL, HFILL }
},
{ &hf_tfp_hdr_p,
{ "Packing Scheme", "gsm_abis_tfp.packing_scheme",
FT_UINT16, BASE_DEC, VALS(tfp_packed_vals), 0x0180,
NULL, HFILL }
},
{ &hf_tfp_hdr_s,
{ "Silence Indicator", "gsm_abis_tfp.silence_ind",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_tfp_hdr_m,
{ "Marker bit", "gsm_abis_tfp.marker",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_tfp_hdr_frame_type,
{ "Frame Type", "gsm_abis_tfp.frame_type",
FT_UINT8, BASE_DEC, VALS(tfp_frame_type_vals), 0x1e,
NULL, HFILL }
},
{ &hf_tfp_amr_rate,
{ "AMR Rate", "gsm_abis_tfp.amr.rate",
FT_UINT8, BASE_DEC, VALS(tfp_amr_len_rate_vals), 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_tfp,
};
proto_abis_tfp = proto_register_protocol("GSM A-bis TFP", "Ericsson GSM A-bis TFP",
"gsm_abis_tfp");
proto_register_field_array(proto_abis_tfp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("gsm_abis_tfp", dissect_abis_tfp, proto_abis_tfp);
}
void
proto_reg_handoff_abis_tfp(void)
{
sub_handles[SUB_DATA] = find_dissector("data");
}
