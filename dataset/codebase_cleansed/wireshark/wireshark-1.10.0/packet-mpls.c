void
decode_mpls_label(tvbuff_t *tvb, int offset,
guint32 *label, guint8 *exp,
guint8 *bos, guint8 *ttl)
{
guint8 octet0 = tvb_get_guint8(tvb, offset+0);
guint8 octet1 = tvb_get_guint8(tvb, offset+1);
guint8 octet2 = tvb_get_guint8(tvb, offset+2);
*label = (octet0 << 12) + (octet1 << 4) + ((octet2 >> 4) & 0xff);
*exp = (octet2 >> 1) & 0x7;
*bos = (octet2 & 0x1);
*ttl = tvb_get_guint8(tvb, offset+3);
}
static void
dissect_pw_ach(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
guint16 channel_type;
if (tvb_reported_length_remaining(tvb, 0) < 4) {
proto_tree_add_text(tree, tvb, 0, -1, "Error processing Message");
return;
}
channel_type = tvb_get_ntohs(tvb, 2);
if (tree) {
proto_tree *mpls_pw_ach_tree;
proto_item *ti;
guint16 res;
ti = proto_tree_add_item(tree, proto_pw_ach, tvb, 0, 4, ENC_NA);
mpls_pw_ach_tree = proto_item_add_subtree(ti, ett_mpls_pw_ach);
proto_tree_add_item(mpls_pw_ach_tree, hf_mpls_pw_ach_ver,
tvb, 0, 1, ENC_BIG_ENDIAN);
res = tvb_get_guint8(tvb, 1);
ti = proto_tree_add_uint(mpls_pw_ach_tree, hf_mpls_pw_ach_res,
tvb, 1, 1, res);
if (res != 0)
proto_tree_add_text(mpls_pw_ach_tree, tvb, 1, 1,
"Error: this byte is reserved and must be 0");
else
PROTO_ITEM_SET_HIDDEN(ti);
proto_tree_add_uint_format_value(mpls_pw_ach_tree, hf_mpls_pw_ach_channel_type,
tvb, 2, 2, channel_type,
"%s (0x%04x)",
val_to_str_ext_const(channel_type, &mpls_pwac_types_ext, "Unknown"),
channel_type);
}
next_tvb = tvb_new_subset_remaining(tvb, 4);
switch (channel_type) {
case ACH_TYPE_BFD_CC:
call_dissector(dissector_bfd, next_tvb, pinfo, tree);
break;
case ACH_TYPE_BFD_CV:
call_dissector(dissector_bfd, next_tvb, pinfo, tree);
dissect_bfd_mep(next_tvb, tree, 0);
break;
case ACH_TYPE_ONDEMAND_CV:
dissect_mpls_echo(next_tvb, pinfo, tree, NULL);
break;
case 0x21:
call_dissector(dissector_ip, next_tvb, pinfo, tree);
break;
case 0x7:
call_dissector(dissector_bfd, next_tvb, pinfo, tree);
break;
case 0x57:
call_dissector(dissector_ipv6, next_tvb, pinfo, tree);
break;
case 0x000A:
call_dissector(dissector_mpls_pm_dlm, next_tvb, pinfo, tree);
break;
case 0x000B:
call_dissector(dissector_mpls_pm_ilm, next_tvb, pinfo, tree);
break;
case 0x000C:
call_dissector(dissector_mpls_pm_dm, next_tvb, pinfo, tree);
break;
case 0x000D:
call_dissector(dissector_mpls_pm_dlm_dm, next_tvb, pinfo, tree);
break;
case 0x000E:
call_dissector(dissector_mpls_pm_ilm_dm, next_tvb, pinfo, tree);
break;
case 0x0024:
call_dissector(dissector_mpls_psc, next_tvb, pinfo, tree);
break;
case 0x0026:
call_dissector(dissector_mplstp_lock, next_tvb, pinfo, tree);
break;
case 0x0027:
call_dissector(dissector_pw_oam, next_tvb, pinfo, tree);
break;
case 0x0058:
call_dissector(dissector_mplstp_fm, next_tvb, pinfo, tree);
break;
default:
call_dissector(dissector_data, next_tvb, pinfo, tree);
break;
}
}
gboolean
dissect_try_cw_first_nibble( tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree )
{
guint8 nibble;
nibble = (tvb_get_guint8(tvb, 0 ) >> 4) & 0x0F;
switch ( nibble )
{
case 6:
call_dissector(dissector_ipv6, tvb, pinfo, tree);
return TRUE;
case 4:
call_dissector(dissector_ip, tvb, pinfo, tree);
return TRUE;
case 1:
dissect_pw_ach(tvb, pinfo, tree );
return TRUE;
default:
break;
}
return FALSE;
}
static void
dissect_pw_mcw(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
if (tvb_reported_length_remaining(tvb, 0) < 4) {
proto_tree_add_text(tree, tvb, 0, -1, "Error processing Message");
return;
}
if ( dissect_try_cw_first_nibble( tvb, pinfo, tree ))
return;
if (tree) {
proto_tree *mpls_pw_mcw_tree;
proto_item *ti;
ti = proto_tree_add_item(tree, proto_pw_mcw, tvb, 0, 4, ENC_NA);
mpls_pw_mcw_tree = proto_item_add_subtree(ti, ett_mpls_pw_mcw);
proto_tree_add_item(mpls_pw_mcw_tree, hf_mpls_pw_mcw_flags,
tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_pw_mcw_tree, hf_mpls_pw_mcw_length,
tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(mpls_pw_mcw_tree, hf_mpls_pw_mcw_sequence_number,
tvb, 2, 2, ENC_BIG_ENDIAN);
}
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector(dissector_data, next_tvb, pinfo, tree);
}
static void
dissect_mpls(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint32 label = MPLS_LABEL_INVALID;
guint8 exp;
guint8 bos;
guint8 ttl;
tvbuff_t *next_tvb;
gboolean found;
guint8 first_nibble;
struct mplsinfo mplsinfo;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "MPLS");
col_set_str(pinfo->cinfo, COL_INFO, "MPLS Label Switched Packet");
while (tvb_reported_length_remaining(tvb, offset) > 0) {
decode_mpls_label(tvb, offset, &label, &exp, &bos, &ttl);
mplsinfo.label = pinfo->mpls_label = label;
mplsinfo.exp = exp;
mplsinfo.bos = bos;
mplsinfo.ttl = ttl;
pinfo->private_data = &mplsinfo;
if (tree) {
proto_item *ti;
proto_tree *mpls_tree;
ti = proto_tree_add_item(tree, proto_mpls, tvb, offset, 4, ENC_NA);
mpls_tree = proto_item_add_subtree(ti, ett_mpls);
if (mpls_bos_flowlabel) {
proto_item_append_text(ti, ", Label: %u (Flow Label)", label);
} else {
proto_item_append_text(ti, ", Label: %u", label);
}
if (label <= MPLS_LABEL_MAX_RESERVED){
proto_tree_add_item(mpls_tree, hf_mpls_label_special, tvb,
offset, 4, ENC_BIG_ENDIAN);
proto_item_append_text(ti, " (%s)",
val_to_str_const(label, special_labels, "Reserved - Unknown"));
} else {
proto_tree_add_item(mpls_tree, hf_mpls_label, tvb, offset, 4,
ENC_BIG_ENDIAN);
}
proto_tree_add_item(mpls_tree, hf_mpls_exp, tvb, offset, 4,
ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Exp: %u", exp);
proto_tree_add_item(mpls_tree, hf_mpls_bos , tvb, offset, 4,
ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", S: %u", bos);
proto_tree_add_item(mpls_tree, hf_mpls_ttl, tvb, offset, 4,
ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", TTL: %u", ttl);
}
offset += 4;
if ((label == MPLS_LABEL_GACH) && !bos) {
proto_tree_add_text(tree, tvb, 0, -1, "Invalid Label");
}
if ((label == MPLS_LABEL_GACH) && bos) {
g_strlcpy(PW_ACH, "Generic Associated Channel Header",50);
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_pw_ach( next_tvb, pinfo, tree );
return;
}
else
g_strlcpy(PW_ACH, "PW Associated Channel Header",50);
if (bos)
break;
}
first_nibble = (tvb_get_guint8(tvb, offset) >> 4) & 0x0F;
next_tvb = tvb_new_subset_remaining(tvb, offset);
found = dissector_try_uint(mpls_subdissector_table, label,
next_tvb, pinfo, tree);
if (found)
return;
if (first_nibble == 4) {
call_dissector(dissector_ip, next_tvb, pinfo, tree);
set_actual_length(tvb, offset+tvb_reported_length(next_tvb));
return;
} else if (first_nibble == 6) {
call_dissector(dissector_ipv6, next_tvb, pinfo, tree);
set_actual_length(tvb, offset+tvb_reported_length(next_tvb));
return;
} else if (first_nibble == 1) {
dissect_pw_ach(next_tvb, pinfo, tree);
return;
} else if (first_nibble == 0) {
}
switch (mpls_default_payload) {
case MDD_PW_SATOP:
call_dissector(dissector_pw_satop, next_tvb, pinfo, tree);
break;
case MDD_PW_CESOPSN:
call_dissector(dissector_pw_cesopsn, next_tvb, pinfo, tree);
break;
case MDD_PW_ETH_HEUR:
call_dissector(dissector_pw_eth_heuristic, next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_FR_DLCI:
call_dissector(dissector_pw_fr, next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_HDLC_NOCW_FRPORT:
call_dissector(dissector_pw_hdlc_nocw_fr, next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_HDLC_NOCW_HDLC_PPP:
call_dissector(dissector_pw_hdlc_nocw_hdlc_ppp,next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_ETH_CW:
call_dissector(dissector_pw_eth_cw, next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_ETH_NOCW:
call_dissector(dissector_pw_eth_nocw, next_tvb, pinfo, tree);
break;
case MDD_ITDM:
call_dissector(dissector_itdm, next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_ATM_N1_CW:
call_dissector(dissector_mpls_pw_atm_n1_cw, next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_ATM_N1_NOCW:
call_dissector(dissector_mpls_pw_atm_n1_nocw, next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_ATM_11_OR_AAL5_PDU:
call_dissector(dissector_mpls_pw_atm_11_aal5pdu, next_tvb, pinfo, tree);
break;
case MDD_MPLS_PW_ATM_AAL5_SDU:
call_dissector(dissector_mpls_pw_atm_aal5_sdu, next_tvb, pinfo, tree);
break;
default:
case MDD_MPLS_PW_GENERIC:
dissect_pw_mcw(next_tvb, pinfo, tree);
break;
}
}
void
proto_register_mpls(void)
{
static hf_register_info mplsf_info[] = {
{&hf_mpls_label,
{"MPLS Label", "mpls.label",
FT_UINT32, BASE_DEC, NULL, 0xFFFFF000,
NULL, HFILL }
},
{&hf_mpls_label_special,
{"MPLS Label", "mpls.label",
FT_UINT32, BASE_DEC, VALS(special_labels), 0xFFFFF000,
NULL, HFILL }
},
{&hf_mpls_exp,
{"MPLS Experimental Bits", "mpls.exp",
FT_UINT32, BASE_DEC, NULL, 0x00000E00,
NULL, HFILL }
},
{&hf_mpls_bos,
{"MPLS Bottom Of Label Stack", "mpls.bottom",
FT_UINT32, BASE_DEC, NULL, 0x00000100,
NULL, HFILL }
},
{&hf_mpls_ttl,
{"MPLS TTL", "mpls.ttl",
FT_UINT32, BASE_DEC, NULL, 0x0000000FF,
NULL, HFILL }
},
{&hf_mpls_pw_ach_ver,
{"Channel Version", "pwach.ver",
FT_UINT8, BASE_DEC, NULL, 0x0F,
"PW Associated Channel Version", HFILL }
},
{&hf_mpls_pw_ach_res,
{"Reserved", "pwach.res",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{&hf_mpls_pw_ach_channel_type,
{"Channel Type", "pwach.channel_type",
FT_UINT16, BASE_HEX, NULL, 0x0,
"PW Associated Channel Type", HFILL }
},
{&hf_mpls_pw_mcw_flags,
{"Flags", "pwmcw.flags",
FT_UINT8, BASE_HEX, NULL, 0x0FC0,
"Generic/Preferred PW MPLS Control Word Flags", HFILL }
},
{&hf_mpls_pw_mcw_length,
{"Length", "pwmcw.length",
FT_UINT8, BASE_DEC, NULL, 0x3F,
"Generic/Preferred PW MPLS Control Word Length", HFILL }
},
{&hf_mpls_pw_mcw_sequence_number,
{"Sequence Number", "pwmcw.sequence_number",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Generic/Preferred PW MPLS Control Word Sequence Number", HFILL }
},
};
static gint *ett[] = {
&ett_mpls,
&ett_mpls_pw_ach,
&ett_mpls_pw_mcw,
};
module_t * module_mpls;
mpls_subdissector_table = register_dissector_table("mpls.label",
"MPLS protocol",
FT_UINT32, BASE_DEC);
proto_mpls = proto_register_protocol("MultiProtocol Label Switching Header",
"MPLS", "mpls");
proto_pw_ach = proto_register_protocol(PW_ACH,
"PW Associated Channel", "pwach");
proto_pw_mcw = proto_register_protocol("PW MPLS Control Word (generic/preferred)",
"Generic PW (with CW)", "pwmcw");
proto_register_field_array(proto_mpls, mplsf_info, array_length(mplsf_info));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("mpls", dissect_mpls, proto_mpls);
register_dissector("mplspwcw", dissect_pw_mcw, proto_pw_mcw );
module_mpls = prefs_register_protocol( proto_mpls, NULL );
prefs_register_enum_preference(module_mpls,
"mplspref.payload",
"Default decoder for MPLS payload",
"Default decoder for MPLS payload",
&mpls_default_payload,
mpls_default_payload_defs,
FALSE );
prefs_register_bool_preference(module_mpls,
"flowlabel_in_mpls_header",
"Assume bottom of stack label as Flow label",
"Lowest label is used to segregate flows inside a pseudowire",
&mpls_bos_flowlabel);
}
void
proto_reg_handoff_mpls(void)
{
dissector_handle_t mpls_handle;
mpls_handle = find_dissector("mpls");
dissector_add_uint("ethertype", ETHERTYPE_MPLS, mpls_handle);
dissector_add_uint("ethertype", ETHERTYPE_MPLS_MULTI, mpls_handle);
dissector_add_uint("chdlctype", ETHERTYPE_MPLS, mpls_handle);
dissector_add_uint("chdlctype", ETHERTYPE_MPLS_MULTI, mpls_handle);
dissector_add_uint("gre.proto", ETHERTYPE_MPLS, mpls_handle);
dissector_add_uint("gre.proto", ETHERTYPE_MPLS_MULTI, mpls_handle);
dissector_add_uint("ip.proto", IP_PROTO_MPLS_IN_IP, mpls_handle);
mpls_handle = find_dissector("mplspwcw");
dissector_add_uint( "mpls.label", MPLS_LABEL_INVALID, mpls_handle );
dissector_data = find_dissector("data");
dissector_ipv6 = find_dissector("ipv6");
dissector_ip = find_dissector("ip");
dissector_bfd = find_dissector("bfd");
dissector_mpls_pm_dlm = find_dissector("mpls_pm_dlm");
dissector_mpls_pm_ilm = find_dissector("mpls_pm_ilm");
dissector_mpls_pm_dm = find_dissector("mpls_pm_dm");
dissector_mpls_pm_dlm_dm = find_dissector("mpls_pm_dlm_dm");
dissector_mpls_pm_ilm_dm = find_dissector("mpls_pm_ilm_dm");
dissector_mpls_psc = find_dissector("mpls_psc");
dissector_mplstp_lock = find_dissector("mplstp_lock");
dissector_mplstp_fm = find_dissector("mplstp_fm");
dissector_pw_oam = find_dissector("pw_oam");
dissector_pw_eth_heuristic = find_dissector("pw_eth_heuristic");
dissector_pw_fr = find_dissector("pw_fr");
dissector_pw_hdlc_nocw_fr = find_dissector("pw_hdlc_nocw_fr");
dissector_pw_eth_cw = find_dissector("pw_eth_cw");
dissector_pw_eth_nocw = find_dissector("pw_eth_nocw");
dissector_pw_satop = find_dissector("pw_satop_mpls");
dissector_itdm = find_dissector("itdm");
dissector_mpls_pw_atm_n1_cw = find_dissector("mpls_pw_atm_n1_cw");
dissector_mpls_pw_atm_n1_nocw = find_dissector("mpls_pw_atm_n1_nocw");
dissector_mpls_pw_atm_11_aal5pdu= find_dissector("mpls_pw_atm_11_or_aal5_pdu");
dissector_mpls_pw_atm_aal5_sdu = find_dissector("mpls_pw_atm_aal5_sdu");
dissector_pw_cesopsn = find_dissector("pw_cesopsn_mpls");
}
