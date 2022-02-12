static int dissect_mac_header_type_2_decoder(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint tvb_len, offset = 0;
guint cii_bit, first_byte, fb_type, mimo_type;
proto_item *parent_item = NULL;
proto_item *ti = NULL;
proto_tree *ti_tree = NULL;
{
tvb_len = tvb_reported_length(tvb);
ti = proto_tree_add_protocol_format(tree, proto_mac_header_type_2_decoder, tvb, offset, tvb_len, "Mac Type II Header (6 bytes)");
ti_tree = proto_item_add_subtree(ti, ett_mac_header_type_2_decoder);
if(tvb_len < WIMAX_MAC_HEADER_SIZE)
{
proto_tree_add_protocol_format(ti_tree, proto_mac_header_type_2_decoder, tvb, offset, tvb_len, "Error: the size of Mac Header Type II tvb is too small! (%u bytes)", tvb_len);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_value_bytes, tvb, offset, tvb_len, ENC_NA);
return tvb_captured_length(tvb);
}
#ifdef DEBUG
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "MAC Signaling Header Type II");
#endif
parent_item = proto_tree_get_parent(tree);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_ht, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_ec, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cii, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_fb_type, tvb, offset, 1, ENC_BIG_ENDIAN);
first_byte = tvb_get_guint8(tvb, offset);
cii_bit = ((first_byte & WIMAX_MAC_HEADER_TYPE_2_CII)?1:0);
if(!(first_byte & WIMAX_MAC_HEADER_TYPE_2_TYPE))
{
fb_type = (first_byte & WIMAX_MAC_HEADER_TYPE_2_FB_TYPE);
if(fb_type < TYPE_II_FB_TYPE_MAX)
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, type2_fb_type_abbrv[fb_type]);
}
else
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Unknown type 2 fb type");
proto_tree_add_item(ti_tree, hf_mac_header_type_2_value_bytes, tvb, offset, tvb_len, ENC_NA);
return tvb_captured_length(tvb);
}
offset++;
proto_item_append_text(parent_item, "%s", type2_fb_type_abbrv[fb_type]);
switch (fb_type)
{
case CQI_MIMO_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cqi_fb_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cqi_payload, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cqi_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case DL_AVG_CINR:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_dl_ave_cinr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_dl_ave_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case MIMO_COEF_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_coef_ni, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_coef_ai, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_coef, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_coef_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case PREF_DL_CHAN_DIUC_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_dl_chan_diuc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_dl_chan_dcd, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_dl_chan_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case UL_TX_PWR:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_ul_tx_pwr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_ul_tx_pwr_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case PHY_CHAN_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_phy_diuc, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_phy_ul_tx_pwr, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_phy_ul_hdrm, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_phy_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case AMC_BAND_BITMAP:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_amc_bitmap, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_amc_cqi_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_amc_cqi_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_amc_cqi_3, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_amc_cqi_4, tvb, offset, 2, ENC_BIG_ENDIAN);
#if 0
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
#endif
break;
case SHORT_PRECODE_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_life_span, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_life_span_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case MULTI_TYPES_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mt_num_fb_types, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mt_occu_fb_type, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mt_fb_contents, tvb, offset, 4, ENC_BIG_ENDIAN);
#if 0
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
#endif
break;
case LONG_PRECODE_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_lt_id_fb, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_lt_rank, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_lt_fec_qam, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_lt_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case COMB_DL_AVG_CINR:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_comb_dl_ave, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_comb_dl_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case MIMO_CHAN_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_diuc, tvb, (offset+1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_pbwi, tvb, (offset+1), 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_slpb, tvb, offset, 3, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_bpri_cid, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_cid, tvb, offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_bpri, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_cti, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_ai_0, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_ai_1, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_ai_2, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_ai_3, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_mi, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_ct, tvb, offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_mimo_cqi, tvb, offset, 3, ENC_BIG_ENDIAN);
}
break;
case CINR_FB:
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cinr_mean, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cinr_devi, tvb, offset, 2, ENC_BIG_ENDIAN);
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
case CL_MIMO_FB:
mimo_type = ((tvb_get_guint8(tvb, offset) & 0xC0) >> 6);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_type, tvb, offset, 2, ENC_BIG_ENDIAN);
if(mimo_type == 1)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_streams, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_ant_sel, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_cqi_1, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_rsv_1, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else if(mimo_type == 2)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_streams, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_codebook_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_cqi_2, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_rsv_2, tvb, offset, 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_ant_id, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_cqi, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cl_mimo_rsv, tvb, offset, 2, ENC_BIG_ENDIAN);
}
if(cii_bit)
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(ti_tree, hf_mac_header_type_2_no_cid, tvb, (offset+2), 2, ENC_BIG_ENDIAN);
}
break;
default:
break;
}
proto_tree_add_item(ti_tree, hf_mac_header_type_2_hcs, tvb, (offset+4), 1, ENC_BIG_ENDIAN);
}
else
{
col_append_sep_str(pinfo->cinfo, COL_INFO, NULL, "Error - Undefined Type");
}
}
return tvb_captured_length(tvb);
}
void proto_register_mac_header_type_2(void)
{
static hf_register_info hf[] =
{
{
&hf_mac_header_type_2_value_bytes,
{
"Values", "wmx.type2ValueBytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_ht,
{
"MAC Header Type", "wmx.type2Ht",
FT_UINT8, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_HT,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_ec,
{
"MAC Encryption Control", "wmx.type2Ec",
FT_UINT8, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_EC,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_type,
{
"MAC Sub-Type", "wmx.type2Type",
FT_UINT8, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_TYPE,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cii,
{
"CID Inclusion Indication", "wmx.type2Cii",
FT_UINT8, BASE_DEC, VALS(cii_msgs), WIMAX_MAC_HEADER_TYPE_2_CII,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_fb_type,
{
"Feedback Type", "wmx.type2FbType",
FT_UINT8, BASE_DEC, VALS(fb_types), WIMAX_MAC_HEADER_TYPE_2_FB_TYPE,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cqi_fb_type,
{
"Mimo Feedback Type", "wmx.type2MimoFbType",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CQI_FB_TYPE,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cqi_payload,
{
"CQI and Mimo Feedback Payload", "wmx.type2MimoFbPayload",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CQI_PAYLOAD,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cqi_rsv,
{
"Reserved", "wmx.type2MimoFbRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CQI_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_dl_ave_cinr,
{
"DL Average CINR", "wmx.type2DlAveCinr",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_DL_AVE_CINR,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_dl_ave_rsv,
{
"Reserved", "wmx.type2DlAveRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_DL_AVE_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_coef_ni,
{
"Number of Index", "wmx.type2MimoCoefNi",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_MIMO_COEF_NI,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_coef_ai,
{
"Occurrences of Antenna Index", "wmx.type2MimoCoefAi",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_MIMO_COEF_AI,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_coef,
{
"MIMO Coefficients", "wmx.type2MimoCoef",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_MIMO_COEF,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_coef_rsv,
{
"Reserved", "wmx.type2MimoCoefRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_MIMO_COEF_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_dl_chan_diuc,
{
"Preferred DIUC", "wmx.type2DlChanDiuc",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_DL_CHAN_DIUC,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_dl_chan_dcd,
{
"DCD Change Count", "wmx.type2DlChanDcd",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_DL_CHAN_DCD,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_dl_chan_rsv,
{
"Reserved", "wmx.type2DlChanRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_DL_CHAN_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_ul_tx_pwr,
{
"UL TX Power", "wmx.type2UlTxPwr",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_UL_TX_PWR,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_ul_tx_pwr_rsv,
{
"Reserved", "wmx.type2UlTxPwrRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_UL_TX_PWR_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_phy_diuc,
{
"Preferred DIUC Index", "wmx.type2PhyDiuc",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_PHY_DIUC,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_phy_ul_tx_pwr,
{
"UL TX Power", "wmx.type2PhyUlTxPwr",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_PHY_UL_TX_PWR,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_phy_ul_hdrm,
{
"UL Headroom", "wmx.type2PhyHdRm",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_PHY_UL_HDRM,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_phy_rsv,
{
"Reserved", "wmx.type2PhyRsv",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_PHY_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_amc_bitmap,
{
"AMC Band Indication Bitmap", "wmx.type2AmcBitmap",
FT_UINT32, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_AMC_BITMAP,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_amc_cqi_1,
{
"CQI 1", "wmx.type2AmcCqi1",
FT_UINT32, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_AMC_CQI_1,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_amc_cqi_2,
{
"CQI 2", "wmx.type2AmcCqi2",
FT_UINT32, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_AMC_CQI_2,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_amc_cqi_3,
{
"CQI 3", "wmx.type2AmcCqi3",
FT_UINT32, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_AMC_CQI_3,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_amc_cqi_4,
{
"CQI 4", "wmx.type2AmcCqi4",
FT_UINT32, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_AMC_CQI_4,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_life_span,
{
"Life Span of Short-term", "wmx.type2LifeSpan",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_LIFE_SPAN,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_life_span_rsv,
{
"Reserved", "wmx.type2LifeSpanRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_LIFE_SPAN_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mt_num_fb_types,
{
"Number of Feedback Types", "wmx.type2MtNumFbTypes",
FT_UINT32, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_MT_NUM_FB_TYPES,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mt_occu_fb_type,
{
"Occurrences of Feedback Type", "wmx.type2MtOccuFbType",
FT_UINT32, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_MT_OCCU_FB_TYPE,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mt_fb_contents,
{
"Number of Feedback Types", "wmx.type2MtNumFbTypes",
FT_UINT32, BASE_HEX, NULL, WIMAX_MAC_HEADER_TYPE_2_MT_FB_CONTENTS,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_lt_id_fb,
{
"Long-term Feedback Index", "wmx.type2LtFbId",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_LT_ID_FB,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_lt_rank,
{
"Rank of Precoding Codebook", "wmx.type2LtRank",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_LT_RANK,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_lt_fec_qam,
{
"FEC and QAM", "wmx.type2LtFecQam",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_LT_FEC_QAM,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_lt_rsv,
{
"Reserved", "wmx.type2LtFbId",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_LT_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_comb_dl_ave,
{
"Combined DL Average CINR of Active BSs", "wmx.type2CombDlAve",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_COMB_DL_AVE,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_comb_dl_rsv,
{
"Reserved", "wmx.type2CombDlRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_COMB_DL_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_diuc,
{
"Preferred DIUC Index", "wmx.type2MimoDiuc",
FT_UINT8, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_DIUC,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_pbwi,
{
"Preferred Bandwidth Index", "wmx.type2MimoPbwi",
FT_UINT8, BASE_DEC, VALS(pbwi_table), WIMAX_MAC_HEADER_TYPE_2_PBWI,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_slpb,
{
"Starting Location of Preferred Bandwidth", "wmx.type2MimoSlpb",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_SLPB,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_bpri_cid,
{
"Burst Profile Ranking Indicator with CID", "wmx.type2MimoBpriCid",
FT_UINT24, BASE_HEX, VALS(bpri_table), WIMAX_MAC_HEADER_TYPE_2_PBRI_CID,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_cid,
{
"Connection ID", "wmx.type2MimoCid",
FT_UINT24, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CID,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_bpri,
{
"Burst Profile Ranking Indicator without CID", "wmx.type2MimoBpri",
FT_UINT24, BASE_HEX, VALS(bpri_table), WIMAX_MAC_HEADER_TYPE_2_PBRI,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_cti,
{
"Coherent Time Index", "wmx.type2MimoCti",
FT_UINT24, BASE_HEX, VALS(cti_table), WIMAX_MAC_HEADER_TYPE_2_CTI,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_ai_0,
{
"Antenna 0 Indication", "wmx.type2MimoAi",
FT_UINT24, BASE_HEX, VALS(ai_msgs), WIMAX_MAC_HEADER_TYPE_2_AI_0,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_ai_1,
{
"Antenna 1 Indication", "wmx.type2MimoAi",
FT_UINT24, BASE_HEX, VALS(ai_msgs), WIMAX_MAC_HEADER_TYPE_2_AI_1,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_ai_2,
{
"Antenna 2 Indication", "wmx.type2MimoAi",
FT_UINT24, BASE_HEX, VALS(ai_msgs), WIMAX_MAC_HEADER_TYPE_2_AI_2,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_ai_3,
{
"Antenna 3 Indication", "wmx.type2MimoAi",
FT_UINT24, BASE_HEX, VALS(ai_msgs), WIMAX_MAC_HEADER_TYPE_2_AI_3,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_mi,
{
"MS Matrix Indicator", "wmx.type2MimoMi",
FT_UINT24, BASE_HEX, VALS(mi_table), WIMAX_MAC_HEADER_TYPE_2_MI,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_ct,
{
"CQI Type", "wmx.type2MimoCt",
FT_UINT24, BASE_HEX, VALS(ct_msgs), WIMAX_MAC_HEADER_TYPE_2_CT,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_mimo_cqi,
{
"CQI Feedback", "wmx.type2MimoCqi",
FT_UINT24, BASE_HEX, NULL, WIMAX_MAC_HEADER_TYPE_2_CQI,
NULL, HFILL
}
},
{ &hf_mac_header_type_2_cinr_mean,
{
"CINR Mean", "wmx.type2CinrMean",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cinr_devi,
{
"CINR Standard Deviation", "wmx.type2CinrDevi",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_type,
{
"Closed-Loop MIMO Type", "wmx.type2ClMimoType",
FT_UINT16, BASE_HEX, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_TYPE,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_ant_id,
{
"Antenna Grouping Index", "wmx.type2ClMimoAntId",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_ANT_ID,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_cqi,
{
"Average CQI", "wmx.type2ClMimoCqi",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_CQI,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_cqi_1,
{
"Average CQI", "wmx.type2ClMimoCqi",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_CQI_1,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_cqi_2,
{
"Average CQI", "wmx.type2ClMimoCqi",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_CQI_2,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_rsv,
{
"Reserved", "wmx.type2ClMimoRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_RSV,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_rsv_1,
{
"Reserved", "wmx.type2ClMimoRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_RSV_1,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_rsv_2,
{
"Reserved", "wmx.type2ClMimoRsv",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_RSV_2,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_streams,
{
"Number of Streams", "wmx.type2ClMimoStreams",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_STREAMS,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_ant_sel,
{
"Antenna Selection Option Index", "wmx.type2ClMimoAntSel",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_ANT_SEL,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cl_mimo_codebook_id,
{
"Codebook Index", "wmx.type2ClMimoCodeBkId",
FT_UINT16, BASE_DEC, NULL, WIMAX_MAC_HEADER_TYPE_2_CL_MIMO_CODEBOOK_ID,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_cid,
{
"Connection ID", "wmx.type2Cid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_no_cid,
{
"Reserved", "wmx.type2NoCid",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
},
{
&hf_mac_header_type_2_hcs,
{
"Header Check Sequence", "wmx.type2Hcs",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL
}
}
};
static gint *ett[] =
{
&ett_mac_header_type_2_decoder,
};
proto_mac_header_type_2_decoder = proto_mac_header_generic_decoder;
proto_register_field_array(proto_mac_header_type_2_decoder, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mac_header_type_2_handler", dissect_mac_header_type_2_decoder, proto_mac_header_type_2_decoder);
}
