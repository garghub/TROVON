static void
dissect_cat(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *cat_ti;
proto_tree *cat_tree, *elem_tree;
unsigned int pos = 0;
cat_ti = proto_tree_add_item(tree, proto_cat, tvb, 0, -1, ENC_NA);
cat_tree = proto_item_add_subtree(cat_ti, ett_cat);
while (pos < tvb_length(tvb)) {
proto_item *ti;
guint8 tag, len, g8;
void *ptr = NULL;
unsigned int i;
tag = tvb_get_guint8(tvb, pos++);
len = tvb_get_guint8(tvb, pos++);
#if 1
ti = proto_tree_add_bytes_format(cat_tree, hf_cat_tlv, tvb, pos,
len, ptr, "%s: %s",
val_to_str(tag&0x7f, comp_tlv_tag_vals, "%02x"),
tvb_bytes_to_str(tvb, pos, len));
#else
ti = proto_tree_add_bytes_format(cat_tree, hf_cat_tlv, tvb, pos,
len, ptr, "%s: ",
val_to_str(tag&0x7f, comp_tlv_tag_vals, "%02x"));
#endif
elem_tree = proto_item_add_subtree(ti, ett_elem);
switch (tag & 0x7f) {
case 0x01:
if (len < 3)
break;
proto_tree_add_item(elem_tree, hf_ctlv_cmd_nr, tvb, pos, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_cmd_type, tvb, pos+1, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_cmd_qual, tvb, pos+2, 1, ENC_NA);
g8 = tvb_get_guint8(tvb, pos+1);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(g8, cmd_type_vals, "%02x "));
break;
case 0x02:
if (len < 2)
break;
proto_tree_add_item(elem_tree, hf_ctlv_devid_src, tvb, pos, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_devid_dst, tvb, pos+1, 1, ENC_NA);
break;
case 0x03:
proto_tree_add_item(elem_tree, hf_ctlv_result_gen, tvb, pos, 1, ENC_NA);
break;
case 0x04:
if (len < 2)
break;
proto_tree_add_item(elem_tree, hf_ctlv_dur_time_intv, tvb, pos+1, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_dur_time_unit, tvb, pos, 1, ENC_NA);
break;
case 0x05:
break;
case 0x0d:
proto_tree_add_item(elem_tree, hf_ctlv_text_string_enc, tvb, pos, 1, ENC_NA);
g8 = tvb_get_guint8(tvb, pos);
switch (g8) {
case 0x04:
proto_tree_add_text(elem_tree, tvb, pos+1, len-1, "Text payload");
break;
case 0x00:
case 0x08:
break;
}
break;
case 0x0e:
if (len < 1)
break;
proto_tree_add_item(elem_tree, hf_ctlv_tone, tvb, pos, 1, ENC_NA);
break;
case 0x13:
if (len < 7)
break;
dissect_e212_mcc_mnc(tvb, pinfo, elem_tree, pos, TRUE);
proto_tree_add_item(elem_tree, hf_ctlv_loci_lac, tvb, pos+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(elem_tree, hf_ctlv_loci_cell_id, tvb, pos+5, 2, ENC_BIG_ENDIAN);
break;
case 0x19:
for (i = 0; i < len; i++)
proto_tree_add_item(elem_tree, hf_ctlv_event, tvb, pos+i, 1, ENC_NA);
break;
case 0x1b:
for (i = 0; i < len; i++)
proto_tree_add_item(elem_tree, hf_ctlv_loc_status, tvb, pos+i, 1, ENC_NA);
break;
case 0x32:
for (i = 0; i < len; i++)
proto_tree_add_item(elem_tree, hf_ctlv_bearer, tvb, pos+i, 1, ENC_NA);
break;
case 0x35:
proto_tree_add_item(elem_tree, hf_ctlv_bearer, tvb, pos, 1, ENC_NA);
for (i = 1; i < len; i++)
proto_tree_add_item(elem_tree, hf_ctlv_bearer_descr, tvb, pos+i, 1, ENC_NA);
break;
case 0x3c:
if (len < 3)
break;
proto_tree_add_item(elem_tree, hf_ctlv_transport_ptype, tvb, pos, 1, ENC_NA);
proto_tree_add_item(elem_tree, hf_ctlv_transport_port, tvb, pos+1, 2, ENC_BIG_ENDIAN);
break;
case 0x3f:
for (i = 1; i < len; i++)
proto_tree_add_item(elem_tree, hf_ctlv_access_tech, tvb, pos+i, 1, ENC_NA);
break;
}
pos += len;
}
}
void
proto_register_card_app_toolkit(void)
{
static hf_register_info hf[] = {
{ &hf_cat_tlv,
{ "COMPREHENSIVE-TLV", "cat.comp_tlv",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_devid_src,
{ "Source Device ID", "cat.comp_tlv.src_dev",
FT_UINT8, BASE_HEX, VALS(dev_id_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_devid_dst,
{ "Destination Device ID", "cat.comp_tlv.dst_dev",
FT_UINT8, BASE_HEX, VALS(dev_id_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_cmd_nr,
{ "Command Number", "cat.comp_tlv.cmd_nr",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_cmd_type,
{ "Command Type", "cat.comp_tlv.cmd_type",
FT_UINT8, BASE_HEX, VALS(cmd_type_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_cmd_qual,
{ "Command Qualifier", "cat.comp_tlv.cmd_qual",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_dur_time_intv,
{ "Time Interval", "cat.comp_tlv.time_interval",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_dur_time_unit,
{ "Time Unit", "cat.comp_tlv.time_unit",
FT_UINT8, BASE_HEX, VALS(time_unit_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_result_gen,
{ "Result", "cat.comp_tlv.result",
FT_UINT8, BASE_HEX, VALS(result_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_text_string_enc,
{ "Text String Encoding", "cat.comp_tlv.text_encoding",
FT_UINT8, BASE_HEX, VALS(text_encoding_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_event,
{ "Event", "cat.comp_tlv.event",
FT_UINT8, BASE_HEX, VALS(event_list_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_tone,
{ "Tone", "cat.comp_tlv.tone",
FT_UINT8, BASE_HEX, VALS(tone_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_loc_status,
{ "Location Status", "cat.comp_tlv.loc_status",
FT_UINT8, BASE_HEX, VALS(loc_status_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer,
{ "Bearer", "cat.comp_tlv.bearer",
FT_UINT8, BASE_HEX, VALS(bearer_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_bearer_descr,
{ "Bearer Description", "cat.comp_tlv.bearer_descr",
FT_UINT8, BASE_HEX, VALS(bearer_descr_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_transport_ptype,
{ "Transport protocol type", "cat.comp_tlv.transport.ptype",
FT_UINT8, BASE_HEX, VALS(transport_ptype_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_transport_port,
{ "Transport port", "cat.comp_tlv.transport.port",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_access_tech,
{ "Access technology", "cat.comp_tlv.access_tech",
FT_UINT8, BASE_HEX, VALS(access_tech_vals), 0,
NULL, HFILL },
},
{ &hf_ctlv_loci_lac,
{ "Location Area Code", "cat.comp_tlv.loci.lac",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL },
},
{ &hf_ctlv_loci_cell_id,
{ "Cell ID", "cat.comp_tlv.loci.cell_id",
FT_UINT16, BASE_HEX, NULL, 0,
NULL, HFILL },
},
};
static gint *ett[] = {
&ett_cat,
&ett_elem,
};
proto_cat = proto_register_protocol("Card Application Tookit ETSI TS 102.223", "ETSI CAT",
"etsi_cat");
proto_register_field_array(proto_cat, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("etsi_cat", dissect_cat, proto_cat);
}
void
proto_reg_handoff_card_app_toolkit(void)
{
}
