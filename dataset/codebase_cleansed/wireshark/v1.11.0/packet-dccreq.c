static void
dissect_dccreq_ds_params (tvbuff_t * tvb, proto_tree * tree, int start, guint16 len)
{
guint8 type, length;
proto_item *dcc_item;
proto_tree *dcc_tree;
int pos;
pos = start;
dcc_item = proto_tree_add_text ( tree, tvb, start, len, "2 DCC-REQ Downstream Params Encodings (Length = %u)", len);
dcc_tree = proto_item_add_subtree ( dcc_item , ett_docsis_dccreq_ds_params);
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case DCCREQ_DS_FREQ:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_freq, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_DS_MOD_TYPE:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_mod_type, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_DS_SYM_RATE:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_sym_rate, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_DS_INTLV_DEPTH:
if (length == 2)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_intlv_depth_i, tvb,
pos, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_intlv_depth_j, tvb,
pos + 1, 1, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_DS_CHAN_ID:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_chan_id, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_DS_SYNC_SUB:
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ds_sync_sub, tvb,
pos, length, ENC_BIG_ENDIAN);
break;
}
pos = pos + length;
}
}
static void
dissect_dccreq_sf_sub (tvbuff_t * tvb, proto_tree * tree, int start, guint16 len)
{
guint8 type, length;
proto_item *dcc_item;
proto_tree *dcc_tree;
int pos;
pos = start;
dcc_item = proto_tree_add_text ( tree, tvb, start, len, "7 DCC-REQ Service Flow Substitution Encodings (Length = %u)", len);
dcc_tree = proto_item_add_subtree ( dcc_item , ett_docsis_dccreq_sf_sub);
while ( pos < ( start + len) )
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case DCCREQ_SF_SFID:
if (length == 8)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_sfid_cur, tvb,
pos, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_sfid_new, tvb,
pos + 4, 4, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_SF_SID:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_sid_cur, tvb,
pos, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_sid_new, tvb,
pos + 2, 2, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_SF_UNSOL_GRANT_TREF:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_sf_unsol_grant_tref, tvb,
pos, length, ENC_BIG_ENDIAN);
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
dissect_dccreq (tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
guint16 pos;
guint8 type, length;
proto_tree *dcc_tree;
proto_item *dcc_item;
guint16 len;
len = tvb_length_remaining (tvb, 0);
col_set_str(pinfo->cinfo, COL_INFO, "DCC-REQ Message: ");
if (tree)
{
dcc_item =
proto_tree_add_protocol_format (tree, proto_docsis_dccreq, tvb, 0,
tvb_length_remaining (tvb, 0),
"DCC-REQ Message");
dcc_tree = proto_item_add_subtree (dcc_item, ett_docsis_dccreq);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_tran_id, tvb, 0, 2, ENC_BIG_ENDIAN);
pos = 2;
while (pos < len)
{
type = tvb_get_guint8 (tvb, pos++);
length = tvb_get_guint8 (tvb, pos++);
switch (type)
{
case DCCREQ_UP_CHAN_ID:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_up_chan_id, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_DS_PARAMS:
dissect_dccreq_ds_params (tvb , dcc_tree , pos , length );
break;
case DCCREQ_INIT_TECH:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_init_tech, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_UCD_SUB:
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_ucd_sub, tvb,
pos, length, ENC_NA);
break;
case DCCREQ_SAID_SUB:
if (length == 4)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_said_sub_cur, tvb,
pos, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_said_sub_new, tvb,
pos + 2, 2, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_SF_SUB:
dissect_dccreq_sf_sub (tvb , dcc_tree , pos , length );
break;
case DCCREQ_CMTS_MAC_ADDR:
if (length == 6)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_cmts_mac_addr, tvb,
pos, length, ENC_NA);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_KEY_SEQ_NUM:
if (length == 1)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_key_seq_num, tvb,
pos, length, ENC_BIG_ENDIAN);
}
else
{
THROW (ReportedBoundsError);
}
break;
case DCCREQ_HMAC_DIGEST:
if (length == 20)
{
proto_tree_add_item (dcc_tree, hf_docsis_dccreq_hmac_digest, tvb,
pos, length, ENC_NA);
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
}
void
proto_register_docsis_dccreq (void)
{
static hf_register_info hf[] = {
{&hf_docsis_dccreq_tran_id ,
{
"Transaction ID",
"docsis_dccreq.tran_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_up_chan_id ,
{
"Up Channel ID",
"docsis_dccreq.up_chan_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_freq ,
{
"Frequency",
"docsis_dccreq.ds_freq",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_mod_type ,
{
"Modulation Type",
"docsis_dccreq.ds_mod_type",
FT_UINT8, BASE_DEC, VALS (ds_mod_type_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_sym_rate ,
{
"Symbol Rate",
"docsis_dccreq.ds_sym_rate",
FT_UINT8, BASE_DEC, VALS (ds_sym_rate_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_intlv_depth_i ,
{
"Interleaver Depth I Value",
"docsis_dccreq.ds_intlv_depth_i",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_intlv_depth_j ,
{
"Interleaver Depth J Value",
"docsis_dccreq.ds_intlv_depth_j",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_chan_id ,
{
"Downstream Channel ID",
"docsis_dccreq.ds_chan_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ds_sync_sub ,
{
"SYNC Substitution",
"docsis_dccreq.ds_sync_sub",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_init_tech ,
{
"Initialization Technique",
"docsis_dccreq.init_tech",
FT_UINT8, BASE_DEC, VALS (init_tech_vals), 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_ucd_sub ,
{
"UCD Substitution",
"docsis_dccreq.ucd_sub",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_said_sub_cur ,
{
"SAID Sub - Current Value",
"docsis_dccreq.said_sub_cur",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_said_sub_new ,
{
"SAID Sub - New Value",
"docsis_dccreq.said_sub_new",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_sfid_cur ,
{
"SF Sub - SFID Current Value",
"docsis_dccreq.sf_sfid_cur",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_sfid_new ,
{
"SF Sub - SFID New Value",
"docsis_dccreq.sf_sfid_new",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_sid_cur ,
{
"SF Sub - SID Current Value",
"docsis_dccreq.sf_sid_cur",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_sid_new ,
{
"SF Sub - SID New Value",
"docsis_dccreq.sf_sid_new",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_sf_unsol_grant_tref ,
{
"SF Sub - Unsolicited Grant Time Reference",
"docsis_dccreq.sf_unsol_grant_tref",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_cmts_mac_addr ,
{
"CMTS Mac Address",
"docsis_dccreq.cmts_mac_addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_key_seq_num ,
{
"Auth Key Sequence Number",
"docsis_dccreq.key_seq_num",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL,
HFILL
}
},
{&hf_docsis_dccreq_hmac_digest ,
{
"HMAC-DigestNumber",
"docsis_dccreq.hmac_digest",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL,
HFILL
}
},
};
static gint *ett[] = {
&ett_docsis_dccreq,
&ett_docsis_dccreq_sf_sub,
&ett_docsis_dccreq_ds_params,
};
proto_docsis_dccreq =
proto_register_protocol ("DOCSIS Downstream Channel Change Request",
"DOCSIS DCC-REQ", "docsis_dccreq");
proto_register_field_array (proto_docsis_dccreq, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector ("docsis_dccreq", dissect_dccreq, proto_docsis_dccreq);
}
void
proto_reg_handoff_docsis_dccreq (void)
{
dissector_handle_t docsis_dccreq_handle;
docsis_dccreq_handle = find_dissector ("docsis_dccreq");
dissector_add_uint ("docsis_mgmt", 0x17, docsis_dccreq_handle);
}
