static void
dissect_cmstatus_tlv (tvbuff_t * tvb, proto_tree * tree, guint8 start, guint16 len)
{
proto_item *it;
proto_tree *tlv_tree;
guint16 pos = start + 1;
guint8 type, length;
it = proto_tree_add_protocol_format (tree, proto_docsis_cmstatus, tvb, 0, len, "TLV Data");
tlv_tree = proto_item_add_subtree (it, ett_docsis_cmstatus_tlv);
while (pos < (len + start + 1))
{
length = tvb_get_guint8 (tvb, pos++);
type = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case EVENT_DS_CH_ID:
if (length == 3)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmstatus_ds_ch_id, tvb, pos + 1, 1, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case EVENT_US_CH_ID:
if (length == 3)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmstatus_us_ch_id, tvb, pos + 1, 1, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case EVENT_DSID:
if (length == 5)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmstatus_dsid, tvb, pos + 1, 3, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case EVENT_DESCR:
if (length >= 3 && length <= 82)
{
proto_tree_add_item (tlv_tree, hf_docsis_cmstatus_descr, tvb, pos + 1, length - 2, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
break;
}
pos = pos + length;
}
}
static void
dissect_cmstatus (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
proto_item *it;
proto_tree *cmstatus_tree = NULL;
guint16 transid;
guint8 event_type;
guint16 len;
transid = tvb_get_ntohs (tvb, 0);
event_type = tvb_get_guint8 (tvb, 2);
len = tvb_reported_length_remaining (tvb, 3);
col_add_fstr (pinfo->cinfo, COL_INFO, "CM-STATUS Report: Transaction ID = %u", transid);
if (tree)
{
it = proto_tree_add_protocol_format (tree, proto_docsis_cmstatus, tvb, 0, -1, "CM-STATUS Report");
cmstatus_tree = proto_item_add_subtree (it, ett_docsis_cmstatus);
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_tranid, tvb, 0, 2, ENC_BIG_ENDIAN);
switch (event_type)
{
case SEC_CH_MDD_TIMEOUT:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_mdd_t, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case QAM_FEC_LOCK_FAILURE:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_qfl_f, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case SEQ_OUT_OF_RANGE:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_s_o, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case SEC_CH_MDD_RECOVERY:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_mdd_r, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case QAM_FEC_LOCK_RECOVERY:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_qfl_r, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case T4_TIMEOUT:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_t4_t, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case T3_RETRIES_EXCEEDED:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_t3_e, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case SUCCESS_RANGING_AFTER_T3_RETRIES_EXCEEDED:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_rng_s, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case CM_ON_BATTERY:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_cm_b, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
case CM_ON_AC_POWER:
proto_tree_add_item (cmstatus_tree, hf_docsis_cmstatus_e_t_cm_a, tvb, 2, 1, ENC_BIG_ENDIAN);
break;
}
}
dissect_cmstatus_tlv(tvb, cmstatus_tree, 3, len);
}
void
proto_register_docsis_cmstatus (void)
{
static hf_register_info hf[] = {
{&hf_docsis_cmstatus_tranid,
{"Transaction ID", "docsis_cmstatus.tranid",FT_UINT16, BASE_DEC, NULL, 0x0,NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_mdd_t,
{"Secondary Channel MDD timeout", "docsis_cmstatus.mdd_timeout", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_qfl_f,
{"QAM/FEC lock failure", "docsis_cmstatus.qam_fec_lock_failure", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_s_o,
{"Sequence out-of-range", "docsis_cmstatus.sequence_out_of_range", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_mdd_r,
{"Secondary Channel MDD Recovery", "docsis_cmstatus.mdd_recovery", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_qfl_r,
{"QAM/FEC Lock Recovery", "docsis_cmstatus.qam_fec_lock_recovery", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_t4_t,
{"T4 timeout", "docsis_cmstatus.t4_timeout", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_t3_e,
{"T3 retries exceeded", "docsis_cmstatus.t3_retries_exceeded", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_rng_s,
{"Successful ranging after T3 retries exceeded", "docsis_cmstatus.successful_ranging_after_t3_retries_exceeded", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_cm_b,
{"CM operating on battery backup", "docsis_cmstatus.cm_on_battery", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_e_t_cm_a,
{"CM returned to A/C power", "docsis_cmstatus.cm_on_ac_power", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_docsis_cmstatus_descr,
{"1.2 Description", "docsis_cmstatus.description",FT_BYTES, BASE_NONE, NULL, 0x0,"Description", HFILL}
},
{&hf_docsis_cmstatus_ds_ch_id,
{"1.4 Downstream Channel ID", "docsis_cmstatus.ds_chid",FT_UINT8, BASE_DEC, NULL, 0x0, "Downstream Channel ID", HFILL}
},
{&hf_docsis_cmstatus_us_ch_id,
{"1.5 Upstream Channel ID", "docsis_cmstatus.us_chid",FT_UINT8, BASE_DEC, NULL, 0x0, "Upstream Channel ID", HFILL}
},
{&hf_docsis_cmstatus_dsid,
{"1.6 DSID", "docsis_cmstatus.dsid", FT_UINT24, BASE_DEC, NULL, 0x0, "DSID", HFILL}
}
};
static gint *ett[] = {
&ett_docsis_cmstatus,
&ett_docsis_cmstatus_tlv
};
proto_docsis_cmstatus = proto_register_protocol ("DOCSIS CM-STATUS Report", "DOCSIS CM-STATUS", "docsis_cmstatus");
proto_register_field_array (proto_docsis_cmstatus, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_cmstatus", dissect_cmstatus, proto_docsis_cmstatus);
}
void
proto_reg_handoff_docsis_cmstatus (void)
{
dissector_handle_t docsis_cmstatus_handle;
docsis_cmstatus_handle = find_dissector ("docsis_cmstatus");
dissector_add_uint ("docsis_mgmt", 0x29, docsis_cmstatus_handle);
}
