static gchar *
format_flags_string(guchar value, const gchar *array[])
{
int i;
guint bpos;
emem_strbuf_t *buf;
const char *sep = "";
buf = ep_strbuf_sized_new(MAX_FLAGS_LEN, MAX_FLAGS_LEN);
for (i = 0; i < 8; i++) {
bpos = 1 << i;
if (value & bpos) {
if (array[i][0]) {
ep_strbuf_append_printf(buf, "%s%s", sep,
array[i]);
sep = ", ";
}
}
}
return buf->str;
}
static void
dissect_sita(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
guchar flags, signals, errors1, errors2, proto;
gchar *errors1_string, *errors2_string, *signals_string, *flags_string;
proto_tree *sita_tree = NULL;
proto_tree *sita_flags_tree = NULL;
proto_tree *sita_errors1_tree = NULL;
proto_tree *sita_errors2_tree = NULL;
proto_tree *sita_signals_tree = NULL;
const gchar *rx_errors1_str[] = {"Framing", "Parity", "Collision", "Long-frame", "Short-frame", "", "", "" };
const gchar *rx_errors2_str[] = {"Non-Aligned", "Abort", "CD-lost", "DPLL", "Overrun", "Length", "CRC", "Break" };
const gchar *tx_errors2_str[] = {"Underrun", "CTS-lost", "UART", "ReTx-limit", "", "", "", "" };
const gchar *signals_str[] = {"DSR", "DTR", "CTS", "RTS", "DCD", "", "", "" };
const gchar *flags_str[] = {"", "", "", "", "", "", "", "No-buffers" };
col_clear(pinfo->cinfo, COL_PROTOCOL);
col_clear(pinfo->cinfo, COL_INFO);
flags = pinfo->pseudo_header->sita.sita_flags;
signals = pinfo->pseudo_header->sita.sita_signals;
errors1 = pinfo->pseudo_header->sita.sita_errors1;
errors2 = pinfo->pseudo_header->sita.sita_errors2;
proto = pinfo->pseudo_header->sita.sita_proto;
if (check_col(pinfo->cinfo, COL_DEF_SRC)) {
if ((flags & SITA_FRAME_DIR) == SITA_FRAME_DIR_TXED) {
col_set_str(pinfo->cinfo, COL_DEF_SRC, IOP);
} else {
col_set_str(pinfo->cinfo, COL_DEF_SRC, REMOTE);
}
}
if (check_col(pinfo->cinfo, COL_INFO))
col_set_str(pinfo->cinfo, COL_INFO, "");
if (tree) {
ti = proto_tree_add_protocol_format(tree, proto_sita, tvb, 0, 0, "Link Layer");
sita_tree = proto_item_add_subtree(ti, ett_sita);
proto_tree_add_uint(sita_tree, hf_proto, tvb, 0, 0, proto);
flags_string = format_flags_string(flags, flags_str);
ti = proto_tree_add_text(sita_tree, tvb, 0, 0, "Flags: 0x%02x (From %s)%s%s",
flags,
((flags & SITA_FRAME_DIR) == SITA_FRAME_DIR_TXED) ? IOP : REMOTE,
strlen(flags_string) ? ", " : "",
flags_string);
sita_flags_tree = proto_item_add_subtree(ti, ett_sita_flags);
proto_tree_add_boolean(sita_flags_tree, hf_droppedframe, tvb, 0, 0, flags);
proto_tree_add_boolean(sita_flags_tree, hf_dir, tvb, 0, 0, flags);
signals_string = format_flags_string(signals, signals_str);
ti = proto_tree_add_text(sita_tree, tvb, 0, 0, "Signals: 0x%02x %s", signals, signals_string);
sita_signals_tree = proto_item_add_subtree(ti, ett_sita_signals);
proto_tree_add_boolean(sita_signals_tree, hf_dcd, tvb, 0, 0, signals);
proto_tree_add_boolean(sita_signals_tree, hf_rts, tvb, 0, 0, signals);
proto_tree_add_boolean(sita_signals_tree, hf_cts, tvb, 0, 0, signals);
proto_tree_add_boolean(sita_signals_tree, hf_dtr, tvb, 0, 0, signals);
proto_tree_add_boolean(sita_signals_tree, hf_dsr, tvb, 0, 0, signals);
if ((flags & SITA_FRAME_DIR) == SITA_FRAME_DIR_RXED) {
errors1_string = format_flags_string(errors1, rx_errors1_str);
ti = proto_tree_add_text(sita_tree, tvb, 0, 0, "Receive Status: 0x%02x %s", errors1, errors1_string);
sita_errors1_tree = proto_item_add_subtree(ti, ett_sita_errors1);
proto_tree_add_boolean(sita_errors1_tree, hf_shortframe, tvb, 0, 0, errors1);
proto_tree_add_boolean(sita_errors1_tree, hf_longframe, tvb, 0, 0, errors1);
proto_tree_add_boolean(sita_errors1_tree, hf_collision, tvb, 0, 0, errors1);
proto_tree_add_boolean(sita_errors1_tree, hf_parity, tvb, 0, 0, errors1);
proto_tree_add_boolean(sita_errors1_tree, hf_framing, tvb, 0, 0, errors1);
errors2_string = format_flags_string(errors2, rx_errors2_str);
ti = proto_tree_add_text(sita_tree, tvb, 0, 0, "Receive Status: 0x%02x %s", errors2, errors2_string);
sita_errors2_tree = proto_item_add_subtree(ti, ett_sita_errors2);
proto_tree_add_boolean(sita_errors2_tree, hf_break, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors2_tree, hf_crc, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors2_tree, hf_length, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors2_tree, hf_overrun, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors2_tree, hf_rxdpll, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors2_tree, hf_lostcd, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors2_tree, hf_abort, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors2_tree, hf_nonaligned, tvb, 0, 0, errors2);
} else {
errors2_string = format_flags_string(errors2, tx_errors2_str);
ti = proto_tree_add_text(sita_tree, tvb, 0, 0, "Transmit Status: 0x%02x %s", errors2, errors2_string);
sita_errors1_tree = proto_item_add_subtree(ti, ett_sita_errors1);
proto_tree_add_boolean(sita_errors1_tree, hf_rtxlimit, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors1_tree, hf_uarterror, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors1_tree, hf_lostcts, tvb, 0, 0, errors2);
proto_tree_add_boolean(sita_errors1_tree, hf_underrun, tvb, 0, 0, errors2);
}
}
if (!dissector_try_uint(sita_dissector_table, pinfo->pseudo_header->sita.sita_proto, tvb, pinfo, tree)) {
if (check_col(pinfo->cinfo, COL_PROTOCOL))
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UNKNOWN");
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "IOP protocol number: %u", pinfo->pseudo_header->sita.sita_proto);
call_dissector(data_handle, tvb, pinfo, tree);
}
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
};
static gint *ett[] = {
&ett_sita,
&ett_sita_flags,
&ett_sita_signals,
&ett_sita_errors1,
&ett_sita_errors2,
};
proto_sita = proto_register_protocol("Societe Internationale de Telecommunications Aeronautiques", "SITA", "sita");
sita_dissector_table = register_dissector_table("sita.proto", "SITA protocol number", FT_UINT8, BASE_HEX);
proto_register_field_array(proto_sita, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("sita", dissect_sita, proto_sita);
}
void
proto_reg_handoff_sita(void)
{
dissector_handle_t lapb_handle;
dissector_handle_t frame_relay_handle;
dissector_handle_t uts_handle;
dissector_handle_t ipars_handle;
dissector_handle_t sita_handle;
lapb_handle = find_dissector("lapb");
frame_relay_handle = find_dissector("fr");
uts_handle = find_dissector("uts");
ipars_handle = find_dissector("ipars");
sita_handle = find_dissector("sita");
data_handle = find_dissector("data");
dissector_add_uint("sita.proto", SITA_PROTO_BOP_LAPB, lapb_handle);
dissector_add_uint("sita.proto", SITA_PROTO_BOP_FRL, frame_relay_handle);
dissector_add_uint("sita.proto", SITA_PROTO_UTS, uts_handle);
dissector_add_uint("sita.proto", SITA_PROTO_ALC, ipars_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_SITA, sita_handle);
}
