static void format_custom_msgtype(gchar *out, guint32 in)
{
const gchar *tmp = NULL;
switch (global_oml_dialect) {
case OML_DIALECT_SIEMENS:
tmp = match_strval(in, oml_fom_msgtype_vals_bs11);
break;
case OML_DIALECT_IPA:
tmp = match_strval(in, oml_fom_msgtype_vals_ipa);
break;
case OML_DIALECT_ETSI:
default:
g_snprintf(out, ITEM_LABEL_LENGTH, "%s",
val_to_str(in, oml_fom_msgtype_vals, "Unknown 0x%02x"));
return;
}
if (tmp)
g_snprintf(out, ITEM_LABEL_LENGTH, "%s", tmp);
else
g_snprintf(out, ITEM_LABEL_LENGTH, "%s",
val_to_str(in, oml_fom_msgtype_vals, "Unknown 0x%02x"));
}
static void format_custom_attr(gchar *out, guint32 in)
{
const gchar *tmp = NULL;
switch (global_oml_dialect) {
case OML_DIALECT_SIEMENS:
tmp = match_strval(in, oml_fom_attr_vals_bs11);
break;
case OML_DIALECT_IPA:
tmp = match_strval(in, oml_fom_attr_vals_ipa);
break;
case OML_DIALECT_ETSI:
default:
g_snprintf(out, ITEM_LABEL_LENGTH, "%s",
val_to_str(in, oml_fom_attr_vals, "Unknown 0x%02x"));
return;
}
if (tmp)
g_snprintf(out, ITEM_LABEL_LENGTH, "%s", tmp);
else
g_snprintf(out, ITEM_LABEL_LENGTH, "%s",
val_to_str(in, oml_fom_attr_vals, "Unknown 0x%02x"));
}
static const struct tlv_def *
find_tlv_tag(guint8 tag)
{
const struct tlv_def *specific;
switch (global_oml_dialect) {
case OML_DIALECT_IPA:
specific = &nm_att_tlvdef_ipa.def[tag];
break;
case OML_DIALECT_SIEMENS:
specific = &nm_att_tlvdev_bs11.def[tag];
break;
case OML_DIALECT_ETSI:
default:
specific = NULL;
break;
}
if (specific && specific->type != TLV_TYPE_UNKNOWN)
return specific;
return &nm_att_tlvdef_base.def[tag];
}
static gint
ipacc_tr_ie_bcch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *att_tree,
int offset)
{
guint16 binfo_type;
binfo_type = tvb_get_ntohs(tvb, offset);
offset += 2;
proto_tree_add_item(att_tree, hf_attr_ipa_tr_arfcn,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(att_tree, hf_attr_ipa_tr_f_qual,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(att_tree, hf_attr_ipa_tr_b_rxlev,
tvb, offset++, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(att_tree, hf_attr_ipa_tr_rxqual,
tvb, offset++, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(att_tree, hf_attr_ipa_tr_f_err,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(att_tree, hf_attr_ipa_tr_frame_offs,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(att_tree, hf_attr_ipa_tr_framenr_offs,
tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(att_tree, hf_attr_ipa_tr_bsic,
tvb, offset++, 1, ENC_LITTLE_ENDIAN);
de_lai(tvb, att_tree, pinfo, offset, 5, NULL, 0);
offset += 5;
proto_tree_add_item(att_tree, hf_attr_ipa_tr_cell_id,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
if (binfo_type & 0x8000) {
proto_tree_add_item(att_tree, hf_attr_ipa_tr_si2,
tvb, offset, 16, ENC_NA);
offset += 16;
}
if (binfo_type & 0x0001) {
proto_tree_add_item(att_tree, hf_attr_ipa_tr_si2bis,
tvb, offset, 16, ENC_NA);
offset += 16;
}
if (binfo_type & 0x0002) {
proto_tree_add_item(att_tree, hf_attr_ipa_tr_si2ter,
tvb, offset, 16, ENC_NA);
offset += 16;
}
if (binfo_type & 0x0004) {
proto_tree_add_item(att_tree, hf_attr_ipa_tr_chan_desc,
tvb, offset, 16, ENC_NA);
offset += 16;
}
return offset;
}
static gint
ipacc_tr_ie_chan_usage(tvbuff_t *tvb, proto_tree *att_tree, int offset)
{
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint16 result;
result = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(att_tree, hf_attr_ipa_tr_arfcn,
tvb, offset, 2, result);
proto_tree_add_uint(att_tree, hf_attr_ipa_tr_rxlev,
tvb, offset, 2, result);
offset += 2;
}
return offset;
}
static gint
dissect_ipacc_test_rep(proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb)
{
gint offset = 0;
proto_tree_add_item(tree, hf_attr_ipa_test_res, tvb, offset++,
1, ENC_BIG_ENDIAN);
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint8 ie;
guint16 len;
proto_item *ti;
proto_tree *att_tree;
ie = tvb_get_guint8(tvb, offset);
len = tvb_get_ntohs(tvb, offset+1);
ti = proto_tree_add_item(tree, hf_oml_ipa_tres_attr_tag, tvb,
offset++, 1, ENC_BIG_ENDIAN);
att_tree = proto_item_add_subtree(ti, ett_oml_fom_att);
proto_tree_add_uint(att_tree, hf_oml_ipa_tres_attr_len, tvb,
offset, 2, len);
offset += 2;
switch (ie) {
case NM_IPACC_TR_IE_CHAN_USAGE:
offset = ipacc_tr_ie_chan_usage(tvb,
att_tree, offset);
break;
case NM_IPACC_TR_IE_BCCH_INFO:
offset = ipacc_tr_ie_bcch(tvb, pinfo,
att_tree, offset);
break;
default:
break;
}
}
return offset;
}
static gint
dissect_oml_attrs(tvbuff_t *tvb, int base_offs, packet_info *pinfo,
proto_tree *tree)
{
int offset = base_offs;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
guint i;
guint8 tag, val8;
guint16 val16;
guint32 val32;
unsigned int len, len_len, hlen;
const struct tlv_def *tdef;
proto_item *ti;
proto_tree *att_tree;
tvbuff_t *sub_tvb;
tag = tvb_get_guint8(tvb, offset);
tdef = find_tlv_tag(tag);
switch (tdef->type) {
case TLV_TYPE_FIXED:
hlen = 1;
len_len = 0;
len = tdef->fixed_len;
break;
case TLV_TYPE_T:
hlen = 1;
len_len = 0;
len = 0;
break;
case TLV_TYPE_TV:
hlen = 1;
len_len = 0;
len = 1;
break;
case TLV_TYPE_TLV:
hlen = 2;
len_len = 1;
len = tvb_get_guint8(tvb, offset+1);
break;
case TLV_TYPE_TL16V:
hlen = 3;
len_len = 2;
len = tvb_get_guint8(tvb, offset+1) << 8 |
tvb_get_guint8(tvb, offset+2);
break;
case TLV_TYPE_TLV16:
hlen = 2;
len_len = 1;
len = tvb_get_guint8(tvb, offset+1) * 2;
break;
case TLV_TYPE_UNKNOWN:
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
ti = proto_tree_add_item(tree, hf_oml_fom_attr_tag, tvb,
offset, 1, ENC_BIG_ENDIAN);
att_tree = proto_item_add_subtree(ti, ett_oml_fom_att);
proto_tree_add_uint(att_tree, hf_oml_fom_attr_len, tvb,
offset+1, len_len, len);
offset += hlen;
sub_tvb = tvb_new_subset(tvb, offset, len, len);
switch (tag) {
case NM_ATT_ABIS_CHANNEL:
proto_tree_add_item(att_tree, hf_attr_ach_btsp, tvb,
offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(att_tree, hf_attr_ach_tslot, tvb,
offset+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(att_tree, hf_attr_ach_sslot, tvb,
offset+2, 1, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_ADM_STATE:
proto_tree_add_item(att_tree, hf_attr_adm_state, tvb,
offset, len, ENC_BIG_ENDIAN);
val8 = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(val8, oml_adm_state_vals,
"%02x"));
break;
case NM_ATT_ARFCN_LIST:
for (i = 0; i < len; i += 2) {
val16 = tvb_get_ntohs(tvb, offset + i);
proto_tree_add_uint(att_tree, hf_attr_arfcn,
tvb, offset + i, 2, val16);
}
break;
case NM_ATT_AVAIL_STATUS:
if (len) {
val8 = tvb_get_guint8(tvb, offset);
proto_tree_add_item(att_tree,
hf_attr_avail_state, tvb,
offset, len, ENC_BIG_ENDIAN);
} else
val8 = 0xff;
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(val8, oml_avail_state_vals,
"%02x"));
break;
case NM_ATT_BCCH_ARFCN:
proto_tree_add_item(att_tree, hf_attr_bcch_arfcn, tvb,
offset, len, ENC_BIG_ENDIAN);
break;
case NM_ATT_BSIC:
proto_tree_add_item(att_tree, hf_attr_bsic, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_CHAN_COMB:
proto_tree_add_item(att_tree, hf_attr_chan_comb, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_EVENT_TYPE:
proto_tree_add_item(att_tree, hf_attr_event_type, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_GSM_TIME:
proto_tree_add_item(att_tree, hf_attr_gsm_time, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_OPER_STATE:
proto_tree_add_item(att_tree, hf_attr_oper_state, tvb,
offset, len, ENC_BIG_ENDIAN);
val8 = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(val8, oml_oper_state_vals,
"%02x"));
break;
case NM_ATT_TEI:
proto_tree_add_item(att_tree, hf_attr_tei, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_TSC:
proto_tree_add_item(att_tree, hf_attr_tsc, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_SEVERITY:
proto_tree_add_item(att_tree, hf_attr_severity, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_TEST_REPORT:
dissect_ipacc_test_rep(att_tree, pinfo, sub_tvb);
break;
case NM_ATT_TEST_NO:
proto_tree_add_item(att_tree, hf_attr_test_no, tvb,
offset, len, ENC_LITTLE_ENDIAN);
val8 = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(val8, oml_test_no_vals,
"%02x"));
break;
case NM_ATT_HSN:
proto_tree_add_item(att_tree, hf_attr_hsn, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_MAIO:
proto_tree_add_item(att_tree, hf_attr_maio, tvb,
offset, len, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(att_tree, hf_oml_fom_attr_val, tvb,
offset, len, ENC_NA);
}
if (global_oml_dialect == OML_DIALECT_IPA) switch (tag) {
case NM_ATT_IPACC_DST_IP:
val32 = tvb_get_ntohl(tvb, offset);
proto_tree_add_ipv4(att_tree, hf_attr_ipa_rsl_ip, tvb,
offset, len, val32);
break;
case NM_ATT_IPACC_DST_IP_PORT:
val16 = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(att_tree, hf_attr_ipa_rsl_port, tvb,
offset, len, val16);
break;
case NM_ATT_IPACC_LOCATION:
proto_tree_add_item(att_tree, hf_attr_ipa_location_name,
tvb, offset, len, ENC_ASCII|ENC_NA);
break;
case NM_ATT_IPACC_UNIT_ID:
proto_tree_add_item(att_tree, hf_attr_ipa_unit_id,
tvb, offset, len, ENC_ASCII|ENC_NA);
break;
case NM_ATT_IPACC_UNIT_NAME:
proto_tree_add_item(att_tree, hf_attr_ipa_unit_name,
tvb, offset, len, ENC_ASCII|ENC_NA);
break;
case NM_ATT_IPACC_PRIM_OML_CFG_LIST:
proto_tree_add_item(att_tree, hf_attr_ipa_prim_oml_ip,
tvb, offset+1, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(att_tree, hf_attr_ipa_prim_oml_port,
tvb, offset+1+4, 2, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_IPACC_NV_FLAGS:
{
guint flags, mask;
flags = tvb_get_guint8(tvb, offset);
mask = tvb_get_guint8(tvb, offset+1);
flags |= tvb_get_guint8(tvb, offset+2) << 8;
mask |= tvb_get_guint8(tvb, offset+3) << 8;
proto_tree_add_uint(att_tree, hf_attr_ipa_nv_flags,
tvb, offset, 3, flags);
proto_tree_add_uint(att_tree, hf_attr_ipa_nv_mask,
tvb, offset+1, 3, mask);
}
break;
case NM_ATT_IPACC_RAC:
proto_tree_add_item(att_tree, hf_attr_ipa_rac,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case NM_ATT_IPACC_NSEI:
val16 = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(att_tree, hf_attr_ipa_nsei,
tvb, offset, 2, val16);
break;
case NM_ATT_IPACC_NSVCI:
val16 = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(att_tree, hf_attr_ipa_nsvci,
tvb, offset, 2, val16);
break;
case NM_ATT_IPACC_BVCI:
val16 = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(att_tree, hf_attr_ipa_bvci,
tvb, offset, 2, val16);
break;
case NM_ATT_IPACC_NS_LINK_CFG:
val16 = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(att_tree, hf_attr_ipa_nsl_sport,
tvb, offset, 2, val16);
val32 = tvb_get_ipv4(tvb, offset+2);
proto_tree_add_ipv4(att_tree, hf_attr_ipa_nsl_daddr,
tvb, offset+2, 4, val32);
val16 = tvb_get_ntohs(tvb, offset+6);
proto_tree_add_uint(att_tree, hf_attr_ipa_nsl_dport,
tvb, offset+6, 2, val16);
break;
}
offset += len;
}
return offset;
}
static int
dissect_oml_fom(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, proto_item *top_ti)
{
guint8 msg_type, obj_class, bts_nr, trx_nr, ts_nr;
proto_item *ti;
proto_tree *fom_tree;
gchar formatted[ITEM_LABEL_LENGTH];
msg_type = tvb_get_guint8(tvb, offset);
obj_class = tvb_get_guint8(tvb, offset+1);
bts_nr = tvb_get_guint8(tvb, offset+2);
trx_nr = tvb_get_guint8(tvb, offset+3);
ts_nr = tvb_get_guint8(tvb, offset+4);
format_custom_msgtype(formatted, msg_type);
proto_item_append_text(top_ti, ", %s(%02x,%02x,%02x) %s ",
val_to_str(obj_class, oml_fom_objclass_vals, "%02x"),
bts_nr, trx_nr, ts_nr, formatted);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%02x,%02x,%02x) %s ",
val_to_str(obj_class, oml_fom_objclass_vals, "%02x"),
bts_nr, trx_nr, ts_nr, formatted);
ti = proto_tree_add_item(tree, hf_oml_fom_msgtype, tvb, offset++, 1, ENC_BIG_ENDIAN);
fom_tree = proto_item_add_subtree(ti, ett_oml_fom);
proto_tree_add_item(fom_tree, hf_oml_fom_objclass, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fom_tree, hf_oml_fom_inst_bts, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fom_tree, hf_oml_fom_inst_trx, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fom_tree, hf_oml_fom_inst_ts, tvb, offset++, 1, ENC_BIG_ENDIAN);
offset = dissect_oml_attrs(tvb, offset, pinfo, fom_tree);
return offset;
}
static int
dissect_oml_manuf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int offset, proto_item *top_ti)
{
if (tvb_get_guint8(tvb, offset) != 0x0d ||
tvb_memeql(tvb, offset+1, ipaccess_magic, sizeof(ipaccess_magic)))
return offset;
offset += sizeof(ipaccess_magic) + 1;
return dissect_oml_fom(tvb, pinfo, tree, offset, top_ti);
}
static int
dissect_abis_oml(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *oml_tree;
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OML");
top_tree = tree;
if (tree) {
guint8 msg_disc = tvb_get_guint8(tvb, offset);
guint8 len = tvb_get_guint8(tvb, offset+3);
ti = proto_tree_add_item(tree, proto_abis_oml, tvb, 0, -1, ENC_NA);
oml_tree = proto_item_add_subtree(ti, ett_oml);
proto_tree_add_item(oml_tree, hf_oml_msg_disc, tvb, offset++,
1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(oml_tree, hf_oml_placement, tvb, offset++,
1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(oml_tree, hf_oml_sequence, tvb, offset++,
1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(oml_tree, hf_oml_length, tvb, offset++,
1, ENC_LITTLE_ENDIAN);
if (global_oml_dialect == OML_DIALECT_ERICSSON) {
tvbuff_t *subtvb;
subtvb = tvb_new_subset(tvb, offset, len, len);
if (sub_om2000)
call_dissector(sub_om2000, subtvb, pinfo, tree);
} else {
switch (msg_disc) {
case ABIS_OM_MDISC_FOM:
offset = dissect_oml_fom(tvb, pinfo, oml_tree,
offset, ti);
break;
case ABIS_OM_MDISC_MANUF:
offset = dissect_oml_manuf(tvb, pinfo, oml_tree,
offset, ti);
break;
case ABIS_OM_MDISC_MMI:
case ABIS_OM_MDISC_TRAU:
default:
break;
}
}
}
return offset;
}
void
proto_register_abis_oml(void)
{
static hf_register_info hf[] = {
{ &hf_oml_msg_disc,
{ "Message Discriminator", "oml.msg_dsc",
FT_UINT8, BASE_HEX, VALS(oml_msg_disc_vals), 0,
"GSM 12.21 Message Discriminator", HFILL }
},
{ &hf_oml_placement,
{ "Placement Indicator", "oml.placement",
FT_UINT8, BASE_HEX, VALS(oml_placement_vals), 0,
"GSM 12.21 Placement Indicator", HFILL }
},
{ &hf_oml_sequence,
{ "Sequence Number", "oml.sequence",
FT_UINT8, BASE_HEX, NULL, 0,
"Sequence Number (if multi-part msg)", HFILL }
},
{ &hf_oml_length,
{ "Length Indicator", "oml.length",
FT_UINT8, BASE_DEC, NULL, 0,
"Total length of payload", HFILL }
},
{ &hf_oml_fom_msgtype,
{ "FOM Message Type", "oml.fom.msg_type",
FT_UINT8, BASE_CUSTOM, &format_custom_msgtype, 0,
NULL, HFILL }
},
{ &hf_oml_fom_objclass,
{ "FOM Object Class", "oml.fom.obj_class",
FT_UINT8, BASE_HEX, VALS(oml_fom_objclass_vals), 0,
NULL, HFILL }
},
{ &hf_oml_fom_inst_bts,
{ "FOM Object Instance BTS", "oml.fom.obj_inst.bts",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_oml_fom_inst_trx,
{ "FOM Object Instance TRX", "oml.fom.obj_inst.trx",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_oml_fom_inst_ts,
{ "FOM Object Instance TS", "oml.fom.obj_inst.ts",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_oml_fom_attr_tag,
{ "FOM Attribute ID", "oml.fom.attr_id",
FT_UINT8, BASE_CUSTOM, &format_custom_attr, 0,
NULL, HFILL }
},
{ &hf_oml_fom_attr_len,
{ "FOM Attribute Length", "oml.fom.attr_len",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_oml_fom_attr_val,
{ "FOM Attribute Value", "oml.fom.attr_val",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_attr_adm_state,
{ "Administrative State", "oml.fom.attr.adm_state",
FT_UINT8, BASE_HEX, VALS(oml_adm_state_vals), 0,
NULL, HFILL }
},
{ &hf_attr_arfcn,
{ "ARFCN", "oml.fom.attr.arfcn",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_oper_state,
{ "Operational State", "oml.fom.attr.oper_state",
FT_UINT8, BASE_HEX, VALS(oml_oper_state_vals), 0,
NULL, HFILL }
},
{ &hf_attr_avail_state,
{ "Availability Status", "oml.fom.attr.avail_state",
FT_UINT8, BASE_HEX, VALS(oml_avail_state_vals), 0,
NULL, HFILL }
},
{ &hf_attr_event_type,
{ "Event Type", "oml.fom.attr.event_type",
FT_UINT8, BASE_HEX, VALS(oml_event_type_vals), 0,
NULL, HFILL }
},
{ &hf_attr_severity,
{ "Severity", "oml.fom.attr.severity",
FT_UINT8, BASE_HEX, VALS(oml_severity_vals), 0,
NULL, HFILL }
},
{ &hf_attr_bcch_arfcn,
{ "BCCH ARFCN", "oml.fom.attr.bcch_arfcn",
FT_UINT16, BASE_DEC, NULL, 0,
"ARFCN of the BCCH", HFILL }
},
{ &hf_attr_bsic,
{ "BSIC", "oml.fom.attr.bsic",
FT_UINT16, BASE_HEX, NULL, 0,
"Base Station Identity Cdoe", HFILL }
},
{ &hf_attr_test_no,
{ "Test Number", "oml.fom.attr.test_no",
FT_UINT8, BASE_HEX, VALS(oml_test_no_vals), 0,
NULL, HFILL }
},
{ &hf_attr_tsc,
{ "TSC", "oml.fom.attr.tsc",
FT_UINT8, BASE_HEX, NULL, 0,
"Training Sequence Code", HFILL }
},
{ &hf_attr_tei,
{ "TEI", "oml.fom.attr.tei",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_attr_ach_btsp,
{ "BTS E1 Port", "oml.fom.attr.abis_ch.bts_port",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_attr_ach_tslot,
{ "E1 Timeslot", "oml.fom.attr.abis_ch.timeslot",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_attr_ach_sslot,
{ "E1 Subslot", "oml.fom.attr.abis_ch.subslot",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_attr_gsm_time,
{ "GSM Time", "oml.fom.attr.gsm_time",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_attr_chan_comb,
{ "Channel Combination", "oml.fom.attr.chan_comb",
FT_UINT8, BASE_HEX, VALS(oml_chan_comb_vals), 0,
NULL, HFILL }
},
{ &hf_attr_hsn,
{ "HSN", "oml.fom.attr.hsn",
FT_UINT8, BASE_DEC, NULL, 0,
"Hopping Sequence Number", HFILL }
},
{ &hf_attr_maio,
{ "MAIO", "oml.fom.attr.maio",
FT_UINT8, BASE_DEC, NULL, 0,
"Mobile Allocation Index Offset", HFILL }
},
{ &hf_oml_ipa_tres_attr_tag,
{ "IPA Test Result Embedded IE",
"oml.fom.testrep.ipa_tag",
FT_UINT8, BASE_HEX, VALS(ipacc_testres_ie_vals), 0,
"Information Element embedded into the Test Result "
"of ip.access BTS", HFILL },
},
{ &hf_oml_ipa_tres_attr_len,
{ "IPA Test Result Embedded IE Length",
"oml.fom.testrep.ipa_len",
FT_UINT16, BASE_DEC, NULL, 0,
"Length of ip.access Test Result Embedded IE", HFILL }
},
{ &hf_attr_ipa_test_res,
{ "IPA Test Result", "oml.fom.testrep.result",
FT_UINT8, BASE_DEC, VALS(ipacc_test_res_vals), 0,
NULL, HFILL }
},
{ &hf_attr_ipa_tr_rxlev,
{ "Rx Level", "oml.fom.testrep.ipa_rxlev",
FT_UINT16, BASE_DEC, NULL, 0xfc00, NULL, HFILL }
},
{ &hf_attr_ipa_tr_b_rxlev,
{ "Rx Level", "oml.fom.testrep.ipa_rxlev_b",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_tr_arfcn,
{ "ARFCN", "oml.fom.testrep.ipa_arfcn",
FT_UINT16, BASE_DEC, NULL, 0x03ff, NULL, HFILL }
},
{ &hf_attr_ipa_tr_f_qual,
{ "Frequency Quality", "oml.fom.testrep.ipa.freq_qual",
FT_UINT8, BASE_DEC, NULL, 0xfc, NULL, HFILL }
},
{ &hf_attr_ipa_tr_f_err,
{ "Frequency Error", "oml.fom.testrep.ipa.freq_err",
FT_INT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_tr_rxqual,
{ "Rx Quality", "oml.fom.testrep.ipa.rx_qual",
FT_UINT8, BASE_DEC, NULL, 0x7, NULL, HFILL }
},
{ &hf_attr_ipa_tr_frame_offs,
{ "Frame Offset", "oml.fom.testrep.ipa.frame_offset",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_tr_framenr_offs,
{ "Frame Number Offset",
"oml.fom.testrep.ipa.framenr_offset",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_tr_bsic,
{ "BSIC", "oml.fom.testrep.ipa.bsic",
FT_UINT8, BASE_DEC, NULL, 0x3f,
"Base Station Identity Code", HFILL }
},
{ &hf_attr_ipa_tr_cell_id,
{ "Cell ID", "oml.fom.testrep.ipa.cell_id",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_rsl_ip,
{ "BSC RSL IP Address", "oml.fom.attr.ipa.rsl_ip",
FT_IPv4, BASE_NONE, NULL, 0,
"IP Address to which the BTS establishes "
"the RSL link", HFILL }
},
{ &hf_attr_ipa_rsl_port,
{ "BSC RSL TCP Port", "oml.fom.attr.ipa.rsl_port",
FT_UINT16, BASE_DEC, NULL, 0,
"Port number to which the BST establishes "
"the RSL link", HFILL }
},
{ &hf_attr_ipa_prim_oml_ip,
{ "Primary OML IP Address",
"oml.fom.attr.ipa.prim_oml_ip",
FT_IPv4, BASE_NONE, NULL, 0,
"IP Address of the BSC for the primary OML link",
HFILL }
},
{ &hf_attr_ipa_prim_oml_port,
{ "Primary OML TCP Port",
"oml.fom.attr.ipa.prim_oml_port",
FT_UINT16, BASE_DEC, NULL, 0,
"TCP Port of the BSC for the primarly OML link",
HFILL }
},
{ &hf_attr_ipa_location_name,
{ "Location Name", "oml.fom.attr.ipa.loc_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_unit_name,
{ "Unit Name", "oml.fom.attr.ipa.unit_name",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_unit_id,
{ "Unit ID", "oml.fom.attr.ipa.unit_id",
FT_STRING, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_nv_flags,
{ "NVRAM Config Flags", "oml.fom.attr.ipa.nv_flags",
FT_UINT16, BASE_HEX, NULL, 0xffff, NULL, HFILL }
},
{ &hf_attr_ipa_nv_mask,
{ "NVRAM Config Mask", "oml.fom.attr.ipa.nv_mask",
FT_UINT16, BASE_HEX, NULL, 0xffff, NULL, HFILL }
},
{ &hf_attr_ipa_tr_si2,
{ "System Information 2", "oml.fom.attr.ipa.si2",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_tr_si2bis,
{ "System Information 2bis", "oml.fom.attr.ipa.si2bis",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_tr_si2ter,
{ "System Information 2ter", "oml.fom.attr.ipa.si2ter",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_tr_chan_desc,
{ "Cell Channel Description",
"oml.fom.attr.ipa.chan_desc",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_nsl_sport,
{ "NS Link IP Source Port",
"oml.fom.attr.ipa.nsl_sport",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_nsl_daddr,
{ "NS Link IP Destination Addr",
"oml.fom.attr.ipa.nsl_daddr",
FT_IPv4, BASE_NONE, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_nsl_dport,
{ "NS Link IP Destination Port",
"oml.fom.attr.ipa.nsl_dport",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_nsei,
{ "NSEI", "oml.fom.attr.ipa.nsei",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_nsvci,
{ "NSVCI", "oml.fom.attr.ipa.nsvci",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_bvci,
{ "BVCI", "oml.fom.attr.ipa.bvci",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL }
},
{ &hf_attr_ipa_rac,
{ "RAC", "oml.fom.attr.ipa.rac",
FT_UINT8, BASE_HEX, NULL, 0,
"Routing Area Code", HFILL }
},
};
static gint *ett[] = {
&ett_oml,
&ett_oml_fom,
&ett_oml_fom_att,
};
module_t *oml_module;
#define NM_ATT_TLVDEF_BASE(_attr, _type, _fixed_len) \
nm_att_tlvdef_base.def[_attr].type = _type; \
nm_att_tlvdef_base.def[_attr].fixed_len = _fixed_len; \
NM_ATT_TLVDEF_BASE(NM_ATT_ABIS_CHANNEL, TLV_TYPE_FIXED, 3);
NM_ATT_TLVDEF_BASE(NM_ATT_ADD_INFO, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_ADD_TEXT, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_ADM_STATE, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_ARFCN_LIST, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_AUTON_REPORT, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_AVAIL_STATUS, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_BCCH_ARFCN, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_BASE(NM_ATT_BSIC, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_BTS_AIR_TIMER, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_CCCH_L_I_P, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_CCCH_L_T, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_CHAN_COMB, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_CONN_FAIL_CRIT, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_DEST, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_EVENT_TYPE, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_FILE_ID, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_FILE_VERSION, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_GSM_TIME, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_BASE(NM_ATT_HSN, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_HW_CONFIG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_HW_DESC, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_INTAVE_PARAM, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_INTERF_BOUND, TLV_TYPE_FIXED, 6);
NM_ATT_TLVDEF_BASE(NM_ATT_LIST_REQ_ATTR, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_MAIO, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_MANUF_STATE, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_MANUF_THRESH, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_MANUF_ID, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_MAX_TA, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_MDROP_LINK, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_BASE(NM_ATT_MDROP_NEXT, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_BASE(NM_ATT_NACK_CAUSES, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_NY1, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_OPER_STATE, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_OVERL_PERIOD, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_PHYS_CONF, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_POWER_CLASS, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_POWER_THRESH, TLV_TYPE_FIXED, 3);
NM_ATT_TLVDEF_BASE(NM_ATT_PROB_CAUSE, TLV_TYPE_FIXED, 3);
NM_ATT_TLVDEF_BASE(NM_ATT_RACH_B_THRESH, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_LDAVG_SLOTS, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_BASE(NM_ATT_RAD_SUBC, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_RF_MAXPOWR_R, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_SITE_INPUTS, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_SITE_OUTPUTS, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_SOURCE, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_SPEC_PROB, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_START_TIME, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_BASE(NM_ATT_T200, TLV_TYPE_FIXED, 7);
NM_ATT_TLVDEF_BASE(NM_ATT_TEI, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_TEST_DUR, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_BASE(NM_ATT_TEST_NO, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_TEST_REPORT, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_VSWR_THRESH, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_BASE(NM_ATT_WINDOW_SIZE, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_TSC, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_SW_CONFIG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_SEVERITY, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_GET_ARI, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_HW_CONF_CHG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_OUTST_ALARM, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_FILE_DATA, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_BASE(NM_ATT_MEAS_RES, TLV_TYPE_TL16V, 0);
#define NM_ATT_TLVDEV_BS11(_attr, _type, _fixed_len) \
nm_att_tlvdev_bs11.def[_attr].type = _type; \
nm_att_tlvdev_bs11.def[_attr].fixed_len = _fixed_len; \
NM_ATT_TLVDEV_BS11(NM_ATT_OUTST_ALARM, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_HW_DESC, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_ARFCN_LIST, TLV_TYPE_TLV16, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_ABIS_EXT_TIME, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_OM_LAPD_REL_TIMER, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_SH_LAPD_INT_TIMER, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_EMERG_TIMER1, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_EMERG_TIMER2, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_BTSLS_HOPPING, TLV_TYPE_FIXED, 1);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_CELL_ALLOC_NR, TLV_TYPE_FIXED, 1);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_ENA_INTERF_CLASS, TLV_TYPE_FIXED, 1);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_FACCH_QUAL, TLV_TYPE_FIXED, 1);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_TSYNC, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_TTRAU, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_EXCESSIVE_DISTANCE,TLV_TYPE_TLV, 1);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_HOPPING_MODE, TLV_TYPE_TLV, 1);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_RF_RES_IND_PER, TLV_TYPE_FIXED, 1);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_RADIO_MEAS_GRAN, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_RADIO_MEAS_REP, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_EMRG_CFG_MEMBER, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_TRX_AREA, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_ESN_FW_CODE_NO, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_ESN_HW_CODE_NO, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_ESN_PCB_SERIAL, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_BOOT_SW_VERS, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(0x59, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(0xd5, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(0xa8, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_PASSWORD, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_TXPWR, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_RSSI_OFFS, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_LINE_CFG, TLV_TYPE_TV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_L1_PROT_TYPE, TLV_TYPE_TV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_BIT_ERR_THESH, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_DIVERSITY, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_LMT_LOGON_SESSION, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_LMT_LOGIN_TIME, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_LMT_USER_ACC_LEV, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_LMT_USER_NAME, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_BTS_STATE, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_E1_STATE, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_PLL_MODE, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_PLL, TLV_TYPE_TLV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_CCLK_ACCURACY, TLV_TYPE_TV, 0);
NM_ATT_TLVDEV_BS11(NM_ATT_BS11_CCLK_TYPE, TLV_TYPE_TV, 0);
#define NM_ATT_TLVDEF_IPA(_attr, _type, _fixed_len) \
nm_att_tlvdef_ipa.def[_attr].type = _type; \
nm_att_tlvdef_ipa.def[_attr].fixed_len = _fixed_len; \
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_DST_IP, TLV_TYPE_FIXED, 4);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_DST_IP_PORT, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_PRIM_OML_CFG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_NV_FLAGS, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_FREQ_CTRL, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_SEC_OML_CFG, TLV_TYPE_FIXED, 6);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_IP_IF_CFG, TLV_TYPE_FIXED, 8);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_IP_GW_CFG, TLV_TYPE_FIXED, 12);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_LOCATION, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_UNIT_ID, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_UNIT_NAME, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_SNMP_CFG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_ALM_THRESH_LIST, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_CUR_SW_CFG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_STREAM_ID, TLV_TYPE_TV, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_RAC, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_OBJ_VERSION, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_GPRS_PAGING_CFG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_NSEI, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_BVCI, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_NSVCI, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_NS_CFG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_BSSGP_CFG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_NS_LINK_CFG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_RLC_CFG, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_SUPP_FEATURES, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_CODING_SCHEMES, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_RLC_CFG_2, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_RLC_CFG_3, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_PAGING_CFG, TLV_TYPE_FIXED, 2);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_FILE_DATA, TLV_TYPE_TL16V, 0);
NM_ATT_TLVDEF_IPA(NM_ATT_IPACC_CGI, TLV_TYPE_TL16V, 0);
proto_abis_oml = proto_register_protocol("GSM A-bis OML", "A-bis OML",
"gsm_abis_oml");
proto_register_field_array(proto_abis_oml, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
new_register_dissector("gsm_abis_oml", dissect_abis_oml, proto_abis_oml);
oml_module = prefs_register_protocol(proto_abis_oml, NULL);
prefs_register_enum_preference(oml_module, "oml_dialect",
"A-bis OML dialect to be used",
"Use ipaccess nanoBTS specific definitions for OML",
&global_oml_dialect, oml_dialect_enumvals, TRUE);
}
void
proto_reg_handoff_abis_oml(void)
{
dissector_handle_t abis_oml_handle;
abis_oml_handle = new_create_dissector_handle(dissect_abis_oml,
proto_abis_oml);
dissector_add_uint("lapd.gsm.sapi", LAPD_GSM_SAPI_OM_PROC,
abis_oml_handle);
sub_om2000 = find_dissector("gsm_abis_om2000");
}
