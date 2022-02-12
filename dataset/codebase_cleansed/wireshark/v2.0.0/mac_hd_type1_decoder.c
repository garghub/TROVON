static void dissect_mac_header_type_1_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint tvb_len, offset = 0;
guint first_byte, sub_type;
proto_item *parent_item = NULL;
proto_item *ti = NULL;
proto_tree *ti_tree = NULL;
if (tree)
{
tvb_len = tvb_reported_length(tvb);
ti = proto_tree_add_protocol_format(tree, proto_mac_header_type_1_decoder, tvb, offset, tvb_len, "Mac Type I Header (%u bytes)", WIMAX_MAC_HEADER_SIZE);
ti_tree = proto_item_add_subtree(ti, ett_mac_header_type_1_decoder);
if(tvb_len < WIMAX_MAC_HEADER_SIZE)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_1_value_bytes, tvb, offset, tvb_len, ENC_NA);
return;
}
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, type1_subtype_abbrv[]);
#endif
parent_item = proto_tree_get_parent(tree);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_ht, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_ec, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_type, tvb, offset, 3, ENC_BIG_ENDIAN);
first_byte = tvb_get_guint8(tvb, offset);
sub_type = ((first_byte & WIMAX_MAC_HEADER_TYPE_1_SUB_TYPE_MASK)>>3);
if(sub_type < TYPE_I_SUBTYPE_MAX)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, type1_subtype_abbrv[sub_type]);
}
else
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Unknown type 1 subtype");
proto_tree_add_protocol_format(ti_tree, proto_mac_header_type_1_decoder, tvb, offset, tvb_len, "Unknown type 1 subtype: %u", sub_type);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_value_bytes, tvb, offset, tvb_len, ENC_NA);
return;
}
proto_item_append_text(parent_item, "%s", type1_subtype_abbrv[sub_type]);
switch (sub_type)
{
case BR_INCREMENTAL:
case BR_AGGREGATE:
proto_tree_add_item(ti_tree, hf_mac_header_type_1_br, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
case PHY_CHANNEL_REPORT:
proto_tree_add_item(ti_tree, hf_mac_header_type_1_diuc, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_ultxpwr, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_ulhdrm, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_rsv_2, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
case BR_WITH_UL_TX_POWER_REPORT:
proto_tree_add_item(ti_tree, hf_mac_header_type_1_br_3, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_ultxpwr_3, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
case BR_AND_CINR_REPORT:
proto_tree_add_item(ti_tree, hf_mac_header_type_1_br_3, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_cinr, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_dci, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
case BR_WITH_UL_SLEEP_CONTROL:
proto_tree_add_item(ti_tree, hf_mac_header_type_1_br_3, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_pscid, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_op, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_rsv_5, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
case SN_REPORT:
proto_tree_add_item(ti_tree, hf_mac_header_type_1_last, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_sdu_sn1, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_sdu_sn2, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_sdu_sn3, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
case CQICH_ALLOCATION_REQUEST:
proto_tree_add_item(ti_tree, hf_mac_header_type_1_fb_type, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_fbssi, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_period, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_rsv_7, tvb, offset, 3, ENC_BIG_ENDIAN);
break;
}
proto_tree_add_item(ti_tree, hf_mac_header_type_1_cid, tvb, (offset+3), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_1_hcs, tvb, (offset+5), 1, ENC_BIG_ENDIAN);
}
}
void proto_register_mac_header_type_1(void)
{
static hf_register_info hf[] =
{
{
&hf_mac_header_type_1_value_bytes,
{
"Values", "wmx.type1ValueBytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_ht,
{
"MAC Header Type", "wmx.type1Ht",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_HT,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_ec,
{
"MAC Encryption Control", "wmx.type1Ec",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_EC,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_type,
{
"MAC Sub-Type", "wmx.type1Type",
FT_UINT24, BASE_HEX, VALS(sub_types), WIMAX_MAC_HEADER_TYPE_1_TYPE,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_br,
{
"Bandwidth Request", "wmx.type1Br",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_BR,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_br_3,
{
"Bandwidth Request", "wmx.type1Br3",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_BR_3,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_fb_type,
{
"Feedback Type", "wmx.type1FbType",
FT_UINT24, BASE_HEX, VALS(fb_types), WIMAX_MAC_HEADER_TYPE_1_FB_TYPE,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_diuc,
{
"Preferred DIUC Index", "wmx.type1Diuc",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_DIUC,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_ultxpwr,
{
"UL TX Power", "wmx.type1UlTxPwr",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_UL_TX_PWR,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_ultxpwr_3,
{
"UL TX Power", "wmx.type1UlTxPwr3",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_UL_TX_PWR_3,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_ulhdrm,
{
"Headroom to UL Max Power Level", "wmx.type1HdRm",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_UL_HDRM,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_cinr,
{
"CINR Value", "wmx.type1Cinr",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_CINR,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_dci,
{
"DCD Change Indication", "wmx.type1Dci",
FT_UINT24, BASE_HEX, VALS(dci_msgs), WIMAX_MAC_HEADER_TYPE_1_DCI,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_pscid,
{
"Power Saving Class ID", "wmx.type1PsCid",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_PSCID,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_op,
{
"Operation", "wmx.type1Op",
FT_UINT24, BASE_HEX, VALS(op_msgs), WIMAX_MAC_HEADER_TYPE_1_OP,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_last,
{
"Last ARQ BSN or SDU SN", "wmx.type1Last",
FT_UINT24, BASE_HEX, VALS(last_msgs), WIMAX_MAC_HEADER_TYPE_1_LAST,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_sdu_sn1,
{
"ARQ BSN or MAC SDU SN (1)", "wmx.type1SduSn1",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_SDU_SN1,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_sdu_sn2,
{
"ARQ BSN or MAC SDU SN (2)", "wmx.type1SduSn2",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_SDU_SN2,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_sdu_sn3,
{
"ARQ BSN or MAC SDU SN (3)", "wmx.type1SduSn3",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_SDU_SN3,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_fbssi,
{
"FBSS Indicator", "wmx.type1Fbssi",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_FBSSI,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_period,
{
"Preferred CQICH Allocation Period", "wmx.type1Period",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_PERIOD,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_rsv_2,
{
"Reserved", "wmx.type1Rsv2",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_RSV_2,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_rsv_5,
{
"Reserved", "wmx.type1Rsv5",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_RSV_5,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_rsv_7,
{
"Reserved", "wmx.type1Rsv7",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_1_RSV_7,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_cid,
{
"Connection ID", "wmx.type1Cid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_type_1_hcs,
{
"Header Check Sequence", "wmx.type1Hcs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_header_type_1_decoder,
};
proto_mac_header_type_1_decoder = proto_mac_header_generic_decoder;
proto_register_field_array(proto_mac_header_type_1_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mac_header_type_1_handler", dissect_mac_header_type_1_decoder, -1);
}
