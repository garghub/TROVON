static void
lapsat_defragment_init(void)
{
reassembly_table_init(&lapsat_reassembly_table,
&addresses_reassembly_table_functions);
}
static guint16
dissect_control(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int is_response)
{
proto_tree *ctl_tree;
proto_item *ctl_ti;
guint16 ctl, poll_final;
const char *frame_type;
char *info;
info = (char *)wmem_alloc(wmem_packet_scope(), 80);
ctl = tvb_get_ntohs(tvb, 1) >> 4;
poll_final = ctl & LAPSAT_CTL_P_F;
switch (ctl & LAPSAT_CTL_TYPE_S_U_MSK) {
case LAPSAT_CTL_TYPE_S:
switch (ctl & LAPSAT_CTL_S_FTYPE_MSK) {
case LAPSAT_RR:
frame_type = "RR";
break;
case LAPSAT_GREJ:
frame_type = "GREJ";
break;
default:
frame_type = "Unknown";
break;
}
g_snprintf(info, 80, "S%s, func=%s, N(R)=%u",
poll_final ? (is_response ? " F" : " P") : "",
frame_type,
(ctl & LAPSAT_CTL_N_R_MSK) >> LAPSAT_CTL_N_R_SHIFT);
break;
case LAPSAT_CTL_TYPE_U:
switch (ctl & LAPSAT_CTL_U_MODIFIER_MSK) {
case LAPSAT_SABM:
frame_type = (ctl & LAPSAT_CTL_MII) ?
"SABM, MII=1" : "SABM, MII=0";
break;
case LAPSAT_DM:
frame_type = "DM";
break;
case LAPSAT_DISC:
frame_type = "DISC";
break;
case LAPSAT_UA:
frame_type = "UA";
break;
case LAPSAT_UI:
frame_type = "UI";
break;
default:
frame_type = "Unknown";
break;
}
g_snprintf(info, 80, "U%s, func=%s",
poll_final ? (is_response ? " F" : " P") : "",
frame_type);
break;
default:
g_snprintf(info, 80, "I%s, N(R)=%u, N(S)=%u",
poll_final ? " P" : "",
(ctl & LAPSAT_CTL_N_R_MSK) >> LAPSAT_CTL_N_R_SHIFT,
(ctl & LAPSAT_CTL_N_S_MSK) >> LAPSAT_CTL_N_S_SHIFT);
break;
}
col_add_str(pinfo->cinfo, COL_INFO, info);
ctl_ti = proto_tree_add_uint_format_value(
tree, hf_lapsat_ctl,
tvb, 1, 2, (guint32)ctl,
"%s (0x%03x)", info, ctl
);
ctl_tree = proto_item_add_subtree(ctl_ti, ett_lapsat_control);
switch (ctl & LAPSAT_CTL_TYPE_S_U_MSK) {
case LAPSAT_CTL_TYPE_S:
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_ftype_s_u,
tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_s_ftype,
tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_n_r,
tvb, 1, 2, ENC_BIG_ENDIAN);
if (poll_final)
proto_tree_add_item(ctl_tree,
is_response ? hf_lapsat_ctl_f : hf_lapsat_ctl_p,
tvb, 1, 2, ENC_BIG_ENDIAN);
break;
case LAPSAT_CTL_TYPE_U:
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_ftype_s_u,
tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ctl_tree,
is_response ? hf_lapsat_ctl_u_modifier_resp :
hf_lapsat_ctl_u_modifier_cmd,
tvb, 1, 2, ENC_BIG_ENDIAN);
if (poll_final)
proto_tree_add_item(ctl_tree,
is_response ? hf_lapsat_ctl_f : hf_lapsat_ctl_p,
tvb, 1, 2, ENC_BIG_ENDIAN);
if (((ctl & LAPSAT_CTL_U_MODIFIER_MSK) == LAPSAT_SABM) &&
(ctl & LAPSAT_CTL_MII))
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_mii,
tvb, 1, 2, ENC_BIG_ENDIAN);
break;
default:
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_ftype_i,
tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_n_r,
tvb, 1, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_n_s,
tvb, 1, 2, ENC_BIG_ENDIAN);
if (poll_final)
proto_tree_add_item(ctl_tree, hf_lapsat_ctl_p,
tvb, 1, 2, ENC_BIG_ENDIAN);
break;
}
return ctl;
}
static void
dissect_lapsat(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *lapsat_tree, *addr_tree;
proto_item *lapsat_ti, *addr_ti;
tvbuff_t *payload;
guint8 addr, sapi, cr;
guint16 control;
unsigned int hlen, is_response = 0, plen;
if (tvb_length(tvb) < LAPSAT_HEADER_LEN)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "LAPSat");
addr = tvb_get_guint8(tvb, 0);
sapi = (addr & LAPSAT_SAPI_MSK) >> LAPSAT_SAPI_SHIFT;
cr = addr & LAPSAT_CR;
if (pinfo->p2p_dir == P2P_DIR_RECV) {
is_response = cr ? FALSE : TRUE;
}
else if (pinfo->p2p_dir == P2P_DIR_SENT) {
is_response = cr ? TRUE : FALSE;
}
hlen = LAPSAT_HEADER_LEN;
if (addr & LAPSAT_LFI)
hlen++;
lapsat_ti = proto_tree_add_item(tree, proto_lapsat, tvb, 0, hlen, ENC_NA);
lapsat_tree = proto_item_add_subtree(lapsat_ti, ett_lapsat);
addr_ti = proto_tree_add_item(lapsat_tree, hf_lapsat_addr, tvb, 0, 1, ENC_BIG_ENDIAN);
addr_tree = proto_item_add_subtree(addr_ti, ett_lapsat_address);
proto_tree_add_item(addr_tree, hf_lapsat_addr_sst, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_lapsat_addr_cr, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_lapsat_addr_sapi, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_lapsat_addr_si, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_lapsat_addr_lpd, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(addr_tree, hf_lapsat_addr_lfi, tvb, 0, 1, ENC_BIG_ENDIAN);
control = dissect_control(tvb, pinfo, lapsat_tree, is_response);
proto_tree_add_item(lapsat_tree, hf_lapsat_payload_last_nibble, tvb, 2, 1, ENC_BIG_ENDIAN);
if (addr & LAPSAT_LFI)
proto_tree_add_item(lapsat_tree, hf_lapsat_len, tvb, 3, 1, ENC_BIG_ENDIAN);
plen = (addr & LAPSAT_LFI) ?
tvb_get_guint8(tvb, 3) : tvb_length(tvb) - hlen;
if (!plen)
return;
DISSECTOR_ASSERT((plen + hlen) <= tvb_length(tvb));
if ((plen + hlen) == tvb_length(tvb)) {
guint8 *data = (guint8 *)tvb_memdup(NULL, tvb, hlen, plen);
data[plen-1] |= tvb_get_guint8(tvb, 2) << 4;
payload = tvb_new_child_real_data(tvb, data, plen, plen);
tvb_set_free_cb(payload, g_free);
} else {
payload = tvb_new_subset(tvb, hlen, plen, -1);
}
add_new_data_source(pinfo, payload, "LAPSat Payload");
if ((control & LAPSAT_CTL_TYPE_I_MSK) == LAPSAT_CTL_TYPE_I) {
fragment_head *fd_m = NULL;
tvbuff_t *reassembled = NULL;
guint32 fragment_id;
gboolean save_fragmented = pinfo->fragmented;
pinfo->fragmented = !!(addr & LAPSAT_SI);
fragment_id = (pinfo->circuit_id << 3) | (sapi << 1) | pinfo->p2p_dir;
fd_m = fragment_add_seq_next(
&lapsat_reassembly_table,
payload, 0,
pinfo,
fragment_id,
NULL,
plen,
!!(addr & LAPSAT_SI)
);
reassembled = process_reassembled_data(
payload, 0, pinfo,
"Reassembled LAPSat", fd_m, &lapsat_frag_items,
NULL, lapsat_tree
);
if (fd_m && pinfo->fd->num == fd_m->reassembled_in) {
if (!dissector_try_uint(lapsat_sapi_dissector_table, sapi,
reassembled, pinfo, tree))
call_dissector(data_handle, reassembled, pinfo, tree);
} else {
col_append_str(pinfo->cinfo, COL_INFO, " (Fragment)");
proto_tree_add_item(lapsat_tree, hf_lapsat_fragment_data, payload, 0, -1, ENC_NA);
}
pinfo->fragmented = save_fragmented;
} else {
if (!dissector_try_uint(lapsat_sapi_dissector_table, sapi, payload, pinfo, tree))
call_dissector(data_handle, payload, pinfo, tree);
}
}
void
proto_register_lapsat(void)
{
static hf_register_info hf[] = {
{ &hf_lapsat_addr,
{ "Address Field", "lapsat.address",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL },
},
{ &hf_lapsat_addr_sst,
{ "SST", "lapsat.address.sst",
FT_UINT8, BASE_DEC, VALS(lapsat_addr_sst_vals), LAPSAT_SST,
"SACCH status bit", HFILL },
},
{ &hf_lapsat_addr_cr,
{ "C/R", "lapsat.address.cr",
FT_UINT8, BASE_DEC, NULL, LAPSAT_CR,
"Command/response bit", HFILL },
},
{ &hf_lapsat_addr_sapi,
{ "SAPI", "lapsat.address.sapi",
FT_UINT8, BASE_DEC, VALS(lapsat_addr_sapi_vals), LAPSAT_SAPI_MSK,
"Service access point identifier", HFILL },
},
{ &hf_lapsat_addr_si,
{ "SI", "lapsat.address.si",
FT_UINT8, BASE_DEC, VALS(lapsat_addr_si_vals), LAPSAT_SI,
"Segment Indicator", HFILL },
},
{ &hf_lapsat_addr_lpd,
{ "LPD", "lapsat.address.lpd",
FT_UINT8, BASE_DEC, VALS(lapsat_addr_lpd_vals), LAPSAT_LPD_MSK,
"Link Protocol Discriminator", HFILL },
},
{ &hf_lapsat_addr_lfi,
{ "LFI", "lapsat.address.lfi",
FT_UINT8, BASE_DEC, VALS(lapsat_addr_lfi_vals), LAPSAT_LFI,
"Length Field Indicator", HFILL },
},
{ &hf_lapsat_ctl,
{ "Control Field", "lapsat.control_field",
FT_UINT16, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_lapsat_ctl_ftype_i,
{ "Frame type", "lapsat.control.ftype",
FT_UINT16, BASE_DEC, VALS(lapsat_ctl_ftype_vals), LAPSAT_CTL_TYPE_I_MSK << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_ftype_s_u,
{ "Frame type", "lapsat.control.ftype",
FT_UINT16, BASE_DEC, VALS(lapsat_ctl_ftype_vals), LAPSAT_CTL_TYPE_S_U_MSK << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_s_ftype,
{ "Supervisory frame type", "lapsat.control.s_ftype",
FT_UINT16, BASE_DEC, VALS(lapsat_ctl_s_ftype_vals), LAPSAT_CTL_S_FTYPE_MSK << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_u_modifier_cmd,
{ "Command", "lapsat.control.u_modifier_cmd",
FT_UINT16, BASE_HEX, VALS(lapsat_ctl_u_modifier_vals_cmd),
LAPSAT_CTL_U_MODIFIER_MSK << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_u_modifier_resp,
{ "Response", "lapsat.control.u_modifier_resp",
FT_UINT16, BASE_HEX, VALS(lapsat_ctl_u_modifier_vals_resp),
LAPSAT_CTL_U_MODIFIER_MSK << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_n_r,
{ "N(R)", "lapsat.control.n_r",
FT_UINT16, BASE_DEC, NULL, LAPSAT_CTL_N_R_MSK << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_n_s,
{ "N(S)", "lapsat.control.n_s",
FT_UINT16, BASE_DEC, NULL, LAPSAT_CTL_N_S_MSK << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_p,
{ "Poll", "lapsat.control.p",
FT_UINT16, BASE_DEC, VALS(true_false_vals), LAPSAT_CTL_P_F << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_f,
{ "Final", "lapsat.control.f",
FT_UINT16, BASE_DEC, VALS(true_false_vals), LAPSAT_CTL_P_F << 4,
NULL, HFILL }
},
{ &hf_lapsat_ctl_mii,
{ "MII", "lapsat.control.mii",
FT_UINT16, BASE_DEC, VALS(true_false_vals), LAPSAT_CTL_MII << 4,
"Mobile Identity Indicator", HFILL }
},
{ &hf_lapsat_payload_last_nibble,
{ "Payload last nibble", "lapsat.payload.last_nibble",
FT_UINT8, BASE_HEX, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_lapsat_len,
{ "Length Field", "lapsat.length",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL },
},
{ &hf_lapsat_fragment_data,
{ "Fragment Data", "lapsat.fragment_data",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_lapsat_fragments,
{ "Message fragments", "lapsat.fragments",
FT_NONE, BASE_NONE, NULL, 0x00,
"LAPSat Message fragments", HFILL }
},
{ &hf_lapsat_fragment,
{ "Message fragment", "lapsat.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"LAPSat Message fragment", HFILL }
},
{ &hf_lapsat_fragment_overlap,
{ "Message fragment overlap", "lapsat.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"LAPSat Message fragment overlaps with other fragment(s)", HFILL }
},
{ &hf_lapsat_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data",
"lapsat.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"LAPSat Message fragment overlaps with conflicting data", HFILL }
},
{ &hf_lapsat_fragment_multiple_tails,
{ "Message has multiple tail fragments", "lapsat.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"LAPSat Message fragment has multiple tail fragments", HFILL }
},
{ &hf_lapsat_fragment_too_long_fragment,
{ "Message fragment too long", "lapsat.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"LAPSat Message fragment data goes beyond the packet end", HFILL }
},
{ &hf_lapsat_fragment_error,
{ "Message defragmentation error", "lapsat.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"LAPSat Message defragmentation error due to illegal fragments", HFILL }
},
{ &hf_lapsat_fragment_count,
{ "Message fragment count", "lapsat.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_lapsat_reassembled_in,
{ "Reassembled in", "lapsat.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
"LAPSat Message has been reassembled in this packet.", HFILL }
},
{ &hf_lapsat_reassembled_length,
{ "Reassembled LAPSat length", "lapsat.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"The total length of the reassembled payload", HFILL }
},
};
static gint *ett[] = {
&ett_lapsat,
&ett_lapsat_address,
&ett_lapsat_control,
&ett_lapsat_fragment,
&ett_lapsat_fragments,
};
proto_lapsat = proto_register_protocol("Link Access Procedure, Satellite channel (LAPSat)", "LAPSat", "lapsat");
proto_register_field_array (proto_lapsat, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("lapsat", dissect_lapsat, proto_lapsat);
lapsat_sapi_dissector_table = register_dissector_table("lapsat.sapi", "LAPSat SAPI", FT_UINT8, BASE_DEC);
register_init_routine (lapsat_defragment_init);
}
void
proto_reg_handoff_lapsat(void)
{
data_handle = find_dissector("data");
}
