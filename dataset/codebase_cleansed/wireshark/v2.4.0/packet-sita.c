static const gchar *
format_flags_string(guchar value, const gchar *array[])
{
int i;
guint bpos;
wmem_strbuf_t *buf;
const char *sep = "";
buf = wmem_strbuf_sized_new(wmem_packet_scope(), MAX_FLAGS_LEN, MAX_FLAGS_LEN);
for (i = 0; i < 8; i++) {
bpos = 1 << i;
if (value & bpos) {
if (array[i][0]) {
wmem_strbuf_append_printf(buf, "%s%s", sep,
array[i]);
sep = ", ";
}
}
}
return wmem_strbuf_get_str(buf);
}
static int
dissect_sita(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
proto_item *ti;
guchar flags, signals, errors1, errors2, proto;
const gchar *errors1_string, *errors2_string, *flags_string;
proto_tree *sita_tree = NULL;
proto_tree *sita_flags_tree = NULL;
proto_tree *sita_errors1_tree = NULL;
proto_tree *sita_errors2_tree = NULL;
static const gchar *rx_errors1_str[] = {"Framing", "Parity", "Collision", "Long-frame", "Short-frame", "", "", "" };
static const gchar *rx_errors2_str[] = {"Non-Aligned", "Abort", "CD-lost", "DPLL", "Overrun", "Length", "CRC", "Break" };
#if 0
static const gchar *tx_errors1_str[] = {"", "", "", "", "", "", "", "" };
#endif
static const gchar *tx_errors2_str[] = {"Underrun", "CTS-lost", "UART", "ReTx-limit", "", "", "", "" };
static const gchar *flags_str[] = {"", "", "", "", "", "", "", "No-buffers" };
static const int * signal_flags[] = {
&hf_dcd,
&hf_rts,
&hf_cts,
&hf_dtr,
&hf_dsr,
NULL
};
col_clear(pinfo->cinfo, COL_PROTOCOL);
col_clear(pinfo->cinfo, COL_INFO);
flags = pinfo->pseudo_header->sita.sita_flags;
signals = pinfo->pseudo_header->sita.sita_signals;
errors1 = pinfo->pseudo_header->sita.sita_errors1;
errors2 = pinfo->pseudo_header->sita.sita_errors2;
proto = pinfo->pseudo_header->sita.sita_proto;
if ((flags & SITA_FRAME_DIR) == SITA_FRAME_DIR_TXED) {
col_set_str(pinfo->cinfo, COL_DEF_SRC, IOP);
} else {
col_set_str(pinfo->cinfo, COL_DEF_SRC, REMOTE);
}
col_set_str(pinfo->cinfo, COL_INFO, "");
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_sita, tvb, 0, 0, "Link Layer");
sita_tree = proto_item_add_subtree(ti, ett_sita);
proto_tree_add_uint(sita_tree, hf_proto, tvb, 0, 0, proto);
flags_string = format_flags_string(flags, flags_str);
sita_flags_tree = proto_tree_add_subtree_format(sita_tree, tvb, 0, 0,
ett_sita_flags, NULL, "Flags: 0x%02x (From %s)%s%s",
flags,
((flags & SITA_FRAME_DIR) == SITA_FRAME_DIR_TXED) ? IOP : REMOTE,
strlen(flags_string) ? ", " : "",
flags_string);
proto_tree_add_boolean(sita_flags_tree, hf_droppedframe, tvb, 0, 0, flags);
proto_tree_add_boolean(sita_flags_tree, hf_dir, tvb, 0, 0, flags);
proto_tree_add_bitmask_value_with_flags(sita_tree, tvb, 0, hf_signals, ett_sita_signals,
signal_flags, signals, BMT_NO_FALSE|BMT_NO_TFS);
if ((flags & SITA_FRAME_DIR) == SITA_FRAME_DIR_RXED) {
static const int * errors1_flags[] = {
&hf_shortframe,
&hf_longframe,
&hf_collision,
&hf_parity,
&hf_framing,
NULL
};
static const int * errors2_flags[] = {
&hf_break,
&hf_crc,
&hf_length,
&hf_overrun,
&hf_rxdpll,
&hf_lostcd,
&hf_abort,
&hf_nonaligned,
NULL
};
errors1_string = format_flags_string(errors1, rx_errors1_str);
sita_errors1_tree = proto_tree_add_subtree_format(sita_tree, tvb, 0, 0,
ett_sita_errors1, NULL, "Receive Status: 0x%02x %s", errors1, errors1_string);
proto_tree_add_bitmask_list_value(sita_errors1_tree, tvb, 0, 0, errors1_flags, errors1);
errors2_string = format_flags_string(errors2, rx_errors2_str);
sita_errors2_tree = proto_tree_add_subtree_format(sita_tree, tvb, 0, 0,
ett_sita_errors2, NULL, "Receive Status: 0x%02x %s", errors2, errors2_string);
proto_tree_add_bitmask_list_value(sita_errors2_tree, tvb, 0, 0, errors2_flags, errors2);
} else {
static const int * errors2_flags[] = {
&hf_rtxlimit,
&hf_uarterror,
&hf_lostcts,
&hf_underrun,
NULL
};
errors2_string = format_flags_string(errors2, tx_errors2_str);
sita_errors1_tree = proto_tree_add_subtree_format(sita_tree, tvb, 0, 0,
ett_sita_errors1, NULL, "Transmit Status: 0x%02x %s", errors2, errors2_string);
proto_tree_add_bitmask_list_value(sita_errors1_tree, tvb, 0, 0, errors2_flags, errors2);
}
}
if (!dissector_try_uint(sita_dissector_table, pinfo->pseudo_header->sita.sita_proto, tvb, pinfo, tree)) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UNKNOWN");
col_add_fstr(pinfo->cinfo, COL_INFO, "IOP protocol number: %u", pinfo->pseudo_header->sita.sita_proto);
call_data_dissector(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_sita(void)
{
static hf_register_info hf[] = {
{ &hf_proto,
{ "Protocol", "sita.errors.protocol",
FT_UINT8, BASE_HEX, VALS(tfs_sita_proto), 0,
"Protocol value", HFILL }
},
{ &hf_dir,
{ "Direction", "sita.flags.flags",
FT_BOOLEAN, 8, TFS(&tfs_sita_flags), SITA_FRAME_DIR,
"TRUE 'from Remote', FALSE 'from Local'", HFILL }
},
{ &hf_droppedframe,
{ "No Buffers", "sita.flags.droppedframe",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_NO_BUFFER,
"TRUE if Buffer Failure", HFILL }
},
{ &hf_framing,
{ "Framing", "sita.errors.framing",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_FRAMING,
"TRUE if Framing Error", HFILL }
},
{ &hf_parity,
{ "Parity", "sita.errors.parity",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_PARITY,
"TRUE if Parity Error", HFILL }
},
{ &hf_collision,
{ "Collision", "sita.errors.collision",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_COLLISION,
"TRUE if Collision", HFILL }
},
{ &hf_longframe,
{ "Long Frame", "sita.errors.longframe",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_FRAME_LONG,
"TRUE if Long Frame Received", HFILL }
},
{ &hf_shortframe,
{ "Short Frame", "sita.errors.shortframe",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_FRAME_SHORT,
"TRUE if Short Frame", HFILL }
},
{ &hf_nonaligned,
{ "NonAligned", "sita.errors.nonaligned",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_NONOCTET_ALIGNED,
"TRUE if NonAligned Frame", HFILL }
},
{ &hf_abort,
{ "Abort", "sita.errors.abort",
FT_BOOLEAN, 8, TFS(&tfs_sita_received), SITA_ERROR_RX_ABORT,
"TRUE if Abort Received", HFILL }
},
{ &hf_lostcd,
{ "Carrier", "sita.errors.lostcd",
FT_BOOLEAN, 8, TFS(&tfs_sita_lost), SITA_ERROR_RX_CD_LOST,
"TRUE if Carrier Lost", HFILL }
},
{ &hf_rxdpll,
{ "DPLL", "sita.errors.rxdpll",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_DPLL,
"TRUE if DPLL Error", HFILL }
},
{ &hf_overrun,
{ "Overrun", "sita.errors.overrun",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_OVERRUN,
"TRUE if Overrun Error", HFILL }
},
{ &hf_length,
{ "Length", "sita.errors.length",
FT_BOOLEAN, 8, TFS(&tfs_sita_violation), SITA_ERROR_RX_FRAME_LEN_VIOL,
"TRUE if Length Violation", HFILL }
},
{ &hf_crc,
{ "CRC", "sita.errors.crc",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_RX_CRC,
"TRUE if CRC Error", HFILL }
},
{ &hf_break,
{ "Break", "sita.errors.break",
FT_BOOLEAN, 8, TFS(&tfs_sita_received), SITA_ERROR_RX_BREAK,
"TRUE if Break Received", HFILL }
},
{ &hf_underrun,
{ "Underrun", "sita.errors.underrun",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_TX_UNDERRUN,
"TRUE if Tx Underrun", HFILL }
},
{ &hf_lostcts,
{ "Clear To Send", "sita.errors.lostcts",
FT_BOOLEAN, 8, TFS(&tfs_sita_lost), SITA_ERROR_TX_CTS_LOST,
"TRUE if Clear To Send Lost", HFILL }
},
{ &hf_uarterror,
{ "UART", "sita.errors.uarterror",
FT_BOOLEAN, 8, TFS(&tfs_sita_error), SITA_ERROR_TX_UART_ERROR,
"TRUE if UART Error", HFILL }
},
{ &hf_rtxlimit,
{ "Retx Limit", "sita.errors.rtxlimit",
FT_BOOLEAN, 8, TFS(&tfs_sita_exceeded), SITA_ERROR_TX_RETX_LIMIT,
"TRUE if Retransmit Limit reached", HFILL }
},
{ &hf_dsr,
{ "DSR", "sita.signals.dsr",
FT_BOOLEAN, 8, TFS(&tfs_sita_on_off), SITA_SIG_DSR,
"TRUE if Data Set Ready", HFILL }
},
{ &hf_dtr,
{ "DTR", "sita.signals.dtr",
FT_BOOLEAN, 8, TFS(&tfs_sita_on_off), SITA_SIG_DTR,
"TRUE if Data Terminal Ready", HFILL }
},
{ &hf_cts,
{ "CTS", "sita.signals.cts",
FT_BOOLEAN, 8, TFS(&tfs_sita_on_off), SITA_SIG_CTS,
"TRUE if Clear To Send", HFILL }
},
{ &hf_rts,
{ "RTS", "sita.signals.rts",
FT_BOOLEAN, 8, TFS(&tfs_sita_on_off), SITA_SIG_RTS,
"TRUE if Request To Send", HFILL }
},
{ &hf_dcd,
{ "DCD", "sita.signals.dcd",
FT_BOOLEAN, 8, TFS(&tfs_sita_on_off), SITA_SIG_DCD,
"TRUE if Data Carrier Detect", HFILL }
},
{ &hf_signals,
{ "Signals", "sita.signals",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_sita,
&ett_sita_flags,
&ett_sita_signals,
&ett_sita_errors1,
&ett_sita_errors2,
};
proto_sita = proto_register_protocol("Societe Internationale de Telecommunications Aeronautiques", "SITA", "sita");
sita_dissector_table = register_dissector_table("sita.proto", "SITA protocol number", proto_sita, FT_UINT8, BASE_HEX);
proto_register_field_array(proto_sita, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
sita_handle = register_dissector("sita", dissect_sita, proto_sita);
}
void
proto_reg_handoff_sita(void)
{
dissector_handle_t lapb_handle;
dissector_handle_t frame_relay_handle;
dissector_handle_t uts_handle;
dissector_handle_t ipars_handle;
lapb_handle = find_dissector("lapb");
frame_relay_handle = find_dissector("fr");
uts_handle = find_dissector("uts");
ipars_handle = find_dissector("ipars");
dissector_add_uint("sita.proto", SITA_PROTO_BOP_LAPB, lapb_handle);
dissector_add_uint("sita.proto", SITA_PROTO_BOP_FRL, frame_relay_handle);
dissector_add_uint("sita.proto", SITA_PROTO_UTS, uts_handle);
dissector_add_uint("sita.proto", SITA_PROTO_ALC, ipars_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_SITA, sita_handle);
}
