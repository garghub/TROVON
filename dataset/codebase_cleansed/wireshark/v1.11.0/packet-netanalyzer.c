static int
dissect_netanalyzer_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *netanalyzer_header_tree = NULL;
proto_item *ti_status = NULL;
proto_tree *netanalyzer_status_tree = NULL;
guint32 packet_status;
guint32 port_num;
guint32 frame_length;
guint is_gpio;
guint32 offset;
guint gpio_num;
guint gpio_edge;
guint version;
guint idx;
if (tree)
{
ti = proto_tree_add_item(tree, proto_netanalyzer, tvb, 0, HEADER_SIZE, ENC_NA);
netanalyzer_header_tree = proto_item_add_subtree(ti, ett_netanalyzer);
is_gpio = (tvb_get_guint8(tvb, 1) >> SRT_GPIO_FLAG) & 0x1;
if (!is_gpio)
{
version = (tvb_get_guint8(tvb, 1) >> SRT_VERSION) & 0xf;
if (version != 1)
{
expert_add_info(pinfo, ti, &ei_netanalyzer_header_version_wrong);
return FALSE;
}
port_num = (tvb_get_guint8(tvb, 1) >> SRT_PORT_NUM) & 0x3;
proto_tree_add_uint(netanalyzer_header_tree, hf_netanalyzer_port, tvb, 0, 4, port_num);
proto_item_append_text(ti, " (Port: %u, ", port_num);
frame_length = tvb_get_letohs(tvb, 2) & MSK_LENGTH;
proto_tree_add_uint(netanalyzer_header_tree, hf_netanalyzer_length, tvb, 0, 4, frame_length);
proto_item_append_text(ti, "Length: %u byte%s, ", frame_length, (frame_length == 1) ? "" : "s");
proto_item_append_text(ti, "Status: ");
packet_status = tvb_get_guint8(tvb, 0);
if (packet_status == 0)
{
ti_status = proto_tree_add_uint_format(netanalyzer_header_tree, hf_netanalyzer_status, tvb, 0, 1,
packet_status, "Status: No Error");
proto_item_append_text(ti, "No Error)");
}
else
{
wmem_strbuf_t *strbuf;
gboolean first = TRUE;
ti_status = proto_tree_add_uint_format(netanalyzer_header_tree, hf_netanalyzer_status, tvb, 0, 1,
packet_status, "Status: Error present (expand tree for details)");
strbuf = wmem_strbuf_new_label(wmem_epan_scope());
for (idx = 0; idx < 8; idx++)
{
if (packet_status & (1 << idx))
{
if (first)
{
first = FALSE;
}
else
{
wmem_strbuf_append(strbuf, ", ");
}
wmem_strbuf_append(strbuf, msk_strings[idx]);
}
}
proto_item_append_text(ti, "%s)", wmem_strbuf_get_str(strbuf));
}
netanalyzer_status_tree = proto_item_add_subtree(ti_status, ett_netanalyzer_status);
proto_tree_add_item(netanalyzer_status_tree, hf_netanalyzer_status_rx_err, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(netanalyzer_status_tree, hf_netanalyzer_status_align_err, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(netanalyzer_status_tree, hf_netanalyzer_status_fcs, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(netanalyzer_status_tree, hf_netanalyzer_status_too_long, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(netanalyzer_status_tree, hf_netanalyzer_status_sfd_error, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(netanalyzer_status_tree, hf_netanalyzer_status_short_frame, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(netanalyzer_status_tree, hf_netanalyzer_status_short_preamble, tvb, 0, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(netanalyzer_status_tree, hf_netanalyzer_status_long_preamble, tvb, 0, 1, ENC_LITTLE_ENDIAN);
if (tvb_get_guint8(tvb, 1) & MSK_TRANSPARENT_MODE)
{
proto_tree_add_text(netanalyzer_header_tree, tvb, 0, 4, "This frame was captured in transparent mode");
proto_item_append_text(ti, ", Transparent Mode");
if (packet_status & MSK_ALIGN_ERR)
{
proto_tree_add_text(netanalyzer_header_tree, tvb, tvb_length(tvb)-1, 1, "Displayed frame data contains additional nibble due to alignment error (upper nibble is not valid)");
}
}
}
else
{
guchar *szTemp;
if ( (tvb_get_guint8(tvb, 10) == 0x00) &&
(tvb_get_guint8(tvb, 11) == 0x02) &&
(tvb_get_guint8(tvb, 12) == 0xa2) &&
(tvb_get_guint8(tvb, 13) == 0xff) &&
(tvb_get_guint8(tvb, 14) == 0xff) &&
(tvb_get_guint8(tvb, 15) == 0xff) &&
(tvb_get_guint8(tvb, 16) == 0x88) &&
(tvb_get_guint8(tvb, 17) == 0xff) &&
(tvb_get_guint8(tvb, INFO_TYPE_OFFSET) == 0x00) )
{
#define MAX_BUFFER 255
szTemp=(guchar *)wmem_alloc(wmem_epan_scope(), MAX_BUFFER);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "netANALYZER");
offset = INFO_TYPE_OFFSET;
offset++;
proto_tree_add_item (netanalyzer_header_tree, hf_netanalyzer_gpio_number, tvb, offset, 1, ENC_LITTLE_ENDIAN);
gpio_num = (tvb_get_guint8(tvb, offset) & 0x03);
offset++;
ti = proto_tree_add_item (netanalyzer_header_tree, hf_netanalyzer_gpio_edge, tvb, offset, 1, ENC_LITTLE_ENDIAN);
gpio_edge = (tvb_get_guint8(tvb, offset) & 0x01);
g_snprintf(szTemp, MAX_BUFFER,
"GPIO event on GPIO %d (%sing edge)", gpio_num, (gpio_edge == 0x00) ? "ris" : "fall");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", szTemp);
proto_item_append_text(ti, " %s", szTemp);
}
else
{
expert_add_info(pinfo, ti, &ei_netanalyzer_gpio_def_none);
}
return FALSE;
}
}
return TRUE;
}
static void
dissect_netanalyzer(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_item *ti = NULL;
if (tvb_length(tvb) >= 4)
{
if (dissect_netanalyzer_common(tvb, pinfo, tree))
{
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector(eth_dissector_handle, next_tvb, pinfo, tree);
}
}
else
{
ti = proto_tree_add_text(tree, tvb, 4, tvb_length(tvb)-4, "netANALYZER");
expert_add_info(pinfo, ti, &ei_netanalyzer_header_version_none);
}
}
static void
dissect_netanalyzer_transparent(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti = NULL;
proto_tree *transparent_payload_tree = NULL;
tvbuff_t *next_tvb;
if (tvb_length(tvb) >= 4)
{
if (dissect_netanalyzer_common(tvb, pinfo, tree))
{
ti = proto_tree_add_text(tree, tvb, 4, tvb_length(tvb)-4, "Raw packet data");
transparent_payload_tree = proto_item_add_subtree(ti, ett_netanalyzer_transparent);
next_tvb = tvb_new_subset_remaining(tvb, 4);
call_dissector(data_dissector_handle, next_tvb, pinfo, transparent_payload_tree);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "netANALYZER");
col_set_str(pinfo->cinfo, COL_INFO, "Frame captured in transparent mode");
}
}
else
{
ti = proto_tree_add_text(tree, tvb, 4, tvb_length(tvb)-4, "netANALYZER transparent mode");
expert_add_info(pinfo, ti, &ei_netanalyzer_header_version_none);
}
}
void proto_register_netanalyzer(void)
{
static hf_register_info hf[] = {
{ &hf_netanalyzer_gpio_number,
{ "Event on", "netanalyzer.gpio_event.gpio_number",
FT_UINT8, BASE_HEX, VALS(gpio_number), 0x0,
"Event on GPIO number", HFILL }
},
{ &hf_netanalyzer_gpio_edge,
{ "Event type", "netanalyzer.gpio_event.gpio_edge",
FT_UINT8, BASE_HEX, VALS(gpio_edge_vals), 0x0,
"Edge of GPIO event", HFILL }
},
{ &hf_netanalyzer_port,
{ "Reception Port", "netanalyzer.port",
FT_UINT8, BASE_DEC, NULL, 0x0,
"netANALYZER reception port", HFILL }
},
{ &hf_netanalyzer_length,
{ "Ethernet frame length", "netanalyzer.framelen",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Actual Ethernet frame length", HFILL }
},
{ &hf_netanalyzer_status,
{ "Frame Status", "netanalyzer.packetstatus",
FT_UINT8, BASE_HEX, NULL, MSK_PACKET_STATUS,
"Status of Ethernet frame", HFILL }
},
{ &hf_netanalyzer_status_rx_err,
{ TXT_RX_ERR, "netanalyzer.packetstatus.rx_er",
FT_BOOLEAN, 8, NULL, MSK_RX_ERR,
"RX_ER detected in frame", HFILL }
},
{ &hf_netanalyzer_status_align_err,
{ TXT_ALIGN_ERR, "netanalyzer.packetstatus.alignment_error",
FT_BOOLEAN, 8, NULL, MSK_ALIGN_ERR,
"Alignment error detected in frame", HFILL }
},
{ &hf_netanalyzer_status_fcs,
{ TXT_FCS_ERROR, "netanalyzer.packetstatus.fcs_error",
FT_BOOLEAN, 8, NULL, MSK_FCS_ERROR,
"FCS error detected in frame", HFILL }
},
{ &hf_netanalyzer_status_too_long,
{ TXT_TOO_LONG, "netanalyzer.packetstatus.too_long",
FT_BOOLEAN, 8, NULL, MSK_TOO_LONG,
"Frame too long (capture truncated)", HFILL }
},
{ &hf_netanalyzer_status_sfd_error,
{ TXT_SFD_ERROR, "netanalyzer.packetstatus.sfd_error",
FT_BOOLEAN, 8, NULL, MSK_SFD_ERROR,
"SDF error detected in frame", HFILL }
},
{ &hf_netanalyzer_status_short_frame,
{ TXT_SHORT_FRAME, "netanalyzer.packetstatus.short_frame",
FT_BOOLEAN, 8, NULL, MSK_SHORT_FRAME,
"Frame too short", HFILL }
},
{ &hf_netanalyzer_status_short_preamble,
{ TXT_SHORT_PREAMBLE, "netanalyzer.packetstatus.short_preamble",
FT_BOOLEAN, 8, NULL, MSK_SHORT_PREAMBLE,
"Preamble shorter than 7 bytes", HFILL }
},
{ &hf_netanalyzer_status_long_preamble,
{ TXT_LONG_PREAMBLE, "netanalyzer.packetstatus.long_preamble",
FT_BOOLEAN, 8, NULL, MSK_LONG_PREAMBLE,
"Preamble longer than 7 bytes", HFILL }
},
};
static gint *ett[] = {
&ett_netanalyzer,
&ett_netanalyzer_status,
&ett_netanalyzer_transparent,
};
static ei_register_info ei[] = {
{ &ei_netanalyzer_header_version_wrong, { "netanalyzer.header_version.wrong", PI_PROTOCOL, PI_ERROR, "Wrong netANALYZER header version", EXPFILL }},
{ &ei_netanalyzer_gpio_def_none, { "netanalyzer.gpio_def_none", PI_MALFORMED, PI_ERROR, "No valid netANALYZER GPIO definition found", EXPFILL }},
{ &ei_netanalyzer_header_version_none, { "netanalyzer.header_version.none", PI_MALFORMED, PI_ERROR, "No netANALYZER header found", EXPFILL }},
};
expert_module_t* expert_netanalyzer;
proto_netanalyzer = proto_register_protocol (
"netANALYZER",
"netANALYZER",
"netanalyzer" );
proto_register_field_array(proto_netanalyzer, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_netanalyzer = expert_register_protocol(proto_netanalyzer);
expert_register_field_array(expert_netanalyzer, ei, array_length(ei));
}
void proto_reg_handoff_netanalyzer(void)
{
dissector_handle_t netana_handle;
dissector_handle_t netana_handle_transparent;
eth_dissector_handle = find_dissector("eth_withfcs");
data_dissector_handle = find_dissector("data");
netana_handle = create_dissector_handle(dissect_netanalyzer, proto_netanalyzer);
netana_handle_transparent = create_dissector_handle(dissect_netanalyzer_transparent, proto_netanalyzer);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETANALYZER, netana_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_NETANALYZER_TRANSPARENT, netana_handle_transparent);
}
