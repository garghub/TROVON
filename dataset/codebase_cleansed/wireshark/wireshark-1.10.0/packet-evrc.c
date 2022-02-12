static guint8
evrc_frame_type_to_octs(guint8 frame_type)
{
switch (frame_type)
{
default:
break;
case 1:
return(2);
case 2:
return(5);
case 3:
return(10);
case 4:
return(22);
}
return(0);
}
static void
dissect_evrc_aux(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, evrc_variant_t evrc_variant)
{
guint8 oct;
guint8 frame_count;
guint8 i;
guint32 offset, saved_offset;
gboolean further_entries;
guint32 len;
proto_item *item = NULL;
proto_tree *evrc_tree = NULL;
proto_tree *toc_tree = NULL;
int hf_mode_request;
int hf_toc_frame_type_high;
int hf_toc_frame_type_low;
guint8 speech_data_len[0x20];
col_set_str(pinfo->cinfo, COL_PROTOCOL, "EVRC");
if (!tree) return;
offset = 0;
g_pinfo = pinfo;
g_tree = tree;
memset(speech_data_len, 0, sizeof(speech_data_len));
len = tvb_reported_length(tvb);
item = proto_tree_add_item(tree, proto_evrc, tvb, 0, -1, ENC_NA);
evrc_tree = proto_item_add_subtree(item, ett_evrc);
proto_tree_add_item(evrc_tree, hf_evrc_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(evrc_tree, hf_evrc_interleave_length, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(evrc_tree, hf_evrc_interleave_index, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (evrc_variant == EVRC_VARIANT_EVRC_LEGACY)
{
frame_count = 0;
further_entries = TRUE;
while (further_entries && (frame_count < sizeof(speech_data_len)) &&
((len - offset) > 0))
{
item =
proto_tree_add_text(evrc_tree, tvb, offset, 1, "ToC [%u]", frame_count+1);
toc_tree = proto_item_add_subtree(item, ett_toc);
proto_tree_add_item(toc_tree, hf_evrc_legacy_toc_fe_ind, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(toc_tree, hf_evrc_legacy_toc_reduc_rate, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(toc_tree, hf_evrc_legacy_toc_frame_type, tvb, offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, offset);
further_entries = (oct & 0x80) ? TRUE : FALSE;
speech_data_len[frame_count] = evrc_frame_type_to_octs((guint8)(oct & 0x7f));
frame_count++;
offset++;
}
}
else
{
switch (evrc_variant)
{
case EVRC_VARIANT_EVRC:
hf_mode_request = hf_evrc_mode_request;
hf_toc_frame_type_high = hf_evrc_toc_frame_type_high;
hf_toc_frame_type_low = hf_evrc_toc_frame_type_low;
break;
case EVRC_VARIANT_EVRC_B:
hf_mode_request = hf_evrc_b_mode_request;
hf_toc_frame_type_high = hf_evrc_b_toc_frame_type_high;
hf_toc_frame_type_low = hf_evrc_b_toc_frame_type_low;
break;
case EVRC_VARIANT_EVRC_WB:
hf_mode_request = hf_evrc_wb_mode_request;
hf_toc_frame_type_high = hf_evrc_b_toc_frame_type_high;
hf_toc_frame_type_low = hf_evrc_b_toc_frame_type_low;
break;
case EVRC_VARIANT_EVRC_NW:
hf_mode_request = hf_evrc_nw_mode_request;
hf_toc_frame_type_high = hf_evrc_b_toc_frame_type_high;
hf_toc_frame_type_low = hf_evrc_b_toc_frame_type_low;
break;
default:
return;
}
proto_tree_add_item(evrc_tree, hf_mode_request, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(evrc_tree, hf_evrc_frame_count, tvb, offset, 1, ENC_BIG_ENDIAN);
frame_count = (tvb_get_guint8(tvb, offset) & 0x1f) + 1;
offset++;
saved_offset = offset;
item =
proto_tree_add_text(evrc_tree, tvb, offset, -1, "ToC - %u frame%s",
frame_count, plurality(frame_count, "", "s"));
toc_tree = proto_item_add_subtree(item, ett_toc);
i = 0;
while ((i < frame_count) &&
((len - offset) > 0))
{
oct = tvb_get_guint8(tvb, offset);
proto_tree_add_item(toc_tree, hf_toc_frame_type_high, tvb, offset, 1, ENC_BIG_ENDIAN);
speech_data_len[i] = evrc_frame_type_to_octs((guint8)((oct & 0xf0) >> 4));
i++;
if (i < frame_count)
{
proto_tree_add_item(toc_tree, hf_toc_frame_type_low, tvb, offset, 1, ENC_BIG_ENDIAN);
speech_data_len[i] = evrc_frame_type_to_octs((guint8)(oct & 0x0f));
i++;
}
offset++;
}
if (frame_count & 0x01)
{
proto_tree_add_item(toc_tree, hf_evrc_padding, tvb, offset-1, 1, ENC_BIG_ENDIAN);
}
proto_item_set_len(item, offset - saved_offset);
}
i = 0;
while ((i < frame_count) &&
((len - offset) >= speech_data_len[i]))
{
proto_tree_add_text(evrc_tree, tvb, offset, speech_data_len[i], "Speech Data [%u]", i+1);
offset += speech_data_len[i];
i++;
}
}
static void
dissect_evrc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_evrc_aux(tvb, pinfo, tree, EVRC_VARIANT_EVRC);
}
static void
dissect_evrcb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_evrc_aux(tvb, pinfo, tree, EVRC_VARIANT_EVRC_B);
}
static void
dissect_evrcwb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_evrc_aux(tvb, pinfo, tree, EVRC_VARIANT_EVRC_WB);
}
static void
dissect_evrcnw(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_evrc_aux(tvb, pinfo, tree, EVRC_VARIANT_EVRC_NW);
}
static void
dissect_evrc_legacy(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_evrc_aux(tvb, pinfo, tree, EVRC_VARIANT_EVRC_LEGACY);
}
void
proto_register_evrc(void)
{
module_t *evrc_module;
static hf_register_info hf[] =
{
{ &hf_evrc_reserved,
{ "Reserved", "evrc.reserved",
FT_UINT8, BASE_HEX, NULL, 0xc0,
"Reserved bits", HFILL }
},
{ &hf_evrc_interleave_length,
{ "Interleave Length", "evrc.interleave_len",
FT_UINT8, BASE_DEC, NULL, 0x38,
"Interleave length bits", HFILL }
},
{ &hf_evrc_interleave_index,
{ "Interleave Index", "evrc.interleave_idx",
FT_UINT8, BASE_DEC, NULL, 0x07,
"Interleave index bits", HFILL }
},
{ &hf_evrc_mode_request,
{ "Mode Request", "evrc.mode_request",
FT_UINT8, BASE_DEC, VALS(evrc_mode_request_vals), 0xe0,
"Mode Request bits", HFILL }
},
{ &hf_evrc_b_mode_request,
{ "Mode Request", "evrc.b.mode_request",
FT_UINT8, BASE_DEC, VALS(evrc_b_mode_request_vals), 0xe0,
"Mode Request bits", HFILL }
},
{ &hf_evrc_wb_mode_request,
{ "Mode Request", "evrc.wb.mode_request",
FT_UINT8, BASE_DEC, VALS(evrc_wb_mode_request_vals), 0xe0,
"Mode Request bits", HFILL }
},
{ &hf_evrc_nw_mode_request,
{ "Mode Request", "evrc.nw.mode_request",
FT_UINT8, BASE_DEC, VALS(evrc_nw_mode_request_vals), 0xe0,
"Mode Request bits", HFILL }
},
{ &hf_evrc_frame_count,
{ "Frame Count (0 means 1 frame)", "evrc.frame_count",
FT_UINT8, BASE_DEC, NULL, 0x1f,
"Frame Count bits, a value of 0 means 1 frame", HFILL }
},
{ &hf_evrc_toc_frame_type_high,
{ "ToC Frame Type", "evrc.toc.frame_type_hi",
FT_UINT8, BASE_DEC, VALS(evrc_frame_type_vals), 0xf0,
"ToC Frame Type bits", HFILL }
},
{ &hf_evrc_toc_frame_type_low,
{ "ToC Frame Type", "evrc.toc.frame_type_lo",
FT_UINT8, BASE_DEC, VALS(evrc_frame_type_vals), 0x0f,
"ToC Frame Type bits", HFILL }
},
{ &hf_evrc_b_toc_frame_type_high,
{ "ToC Frame Type", "evrc.b.toc.frame_type_hi",
FT_UINT8, BASE_DEC, VALS(evrc_b_frame_type_vals), 0xf0,
"ToC Frame Type bits", HFILL }
},
{ &hf_evrc_b_toc_frame_type_low,
{ "ToC Frame Type", "evrc.b.toc.frame_type_lo",
FT_UINT8, BASE_DEC, VALS(evrc_b_frame_type_vals), 0x0f,
"ToC Frame Type bits", HFILL }
},
{ &hf_evrc_padding,
{ "Padding", "evrc.padding",
FT_UINT8, BASE_DEC, NULL, 0x0f,
"Padding bits", HFILL }
},
{ &hf_evrc_legacy_toc_fe_ind,
{ "ToC Further Entries Indicator", "evrc.legacy.toc.further_entries_ind",
FT_BOOLEAN, 8, TFS(&toc_further_entries_bit_vals), 0x80,
"ToC Further Entries Indicator bit", HFILL }
},
{ &hf_evrc_legacy_toc_reduc_rate,
{ "ToC Reduced Rate", "evrc.legacy.toc.reduced_rate",
FT_UINT8, BASE_DEC, NULL, 0x40,
"ToC Reduced Rate bits", HFILL }
},
{ &hf_evrc_legacy_toc_frame_type,
{ "ToC Frame Type", "evrc.legacy.toc.frame_type",
FT_UINT8, BASE_DEC, VALS(evrc_legacy_frame_type_vals), 0x3f,
"ToC Frame Type bits", HFILL }
}
};
static gint *ett[] =
{
&ett_evrc,
&ett_toc
};
proto_evrc =
proto_register_protocol("Enhanced Variable Rate Codec", "EVRC", "evrc");
proto_register_field_array(proto_evrc, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
evrc_module = prefs_register_protocol(proto_evrc, proto_reg_handoff_evrc);
prefs_register_bool_preference(evrc_module,
"legacy_pt_60",
"Add dissector for static payload type 60 as legacy EVRC (non-RFC3558)",
"Whether the EVRC dissector should process payload type 60 as legacy EVRC packets",
&legacy_pt_60);
}
void
proto_reg_handoff_evrc(void)
{
static gboolean evrc_prefs_initialized = FALSE;
static dissector_handle_t evrc_legacy_handle;
if (!evrc_prefs_initialized)
{
dissector_handle_t evrc_handle;
dissector_handle_t evrcb_handle;
dissector_handle_t evrcwb_handle;
dissector_handle_t evrcnw_handle;
evrc_handle = create_dissector_handle(dissect_evrc, proto_evrc);
evrcb_handle = create_dissector_handle(dissect_evrcb, proto_evrc);
evrcwb_handle = create_dissector_handle(dissect_evrcwb, proto_evrc);
evrcnw_handle = create_dissector_handle(dissect_evrcnw, proto_evrc);
evrc_legacy_handle = create_dissector_handle(dissect_evrc_legacy, proto_evrc);
dissector_add_string("rtp_dyn_payload_type", "EVRC", evrc_handle);
dissector_add_string("rtp_dyn_payload_type", "EVRCB", evrcb_handle);
dissector_add_string("rtp_dyn_payload_type", "EVRCWB", evrcwb_handle);
dissector_add_string("rtp_dyn_payload_type", "EVRCNW", evrcnw_handle);
evrc_prefs_initialized = TRUE;
}
else
{
dissector_delete_uint("rtp.pt", 60, evrc_legacy_handle);
}
if (legacy_pt_60)
{
dissector_add_uint("rtp.pt", 60, evrc_legacy_handle);
}
}
