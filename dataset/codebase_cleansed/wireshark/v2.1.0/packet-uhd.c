static int
dissect_uhd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int ind;
proto_item *ti;
proto_tree *uhd_tree;
guint32 id;
guint8 i2c_bytes;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UHD");
col_clear(pinfo->cinfo, COL_INFO);
id = tvb_get_ntohl(tvb, 4);
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(id, uhd_ids, "Unknown UHD message type '%c'"));
if (tree == NULL)
return tvb_captured_length(tvb);
ti = proto_tree_add_protocol_format(tree, proto_uhd, tvb, 0, 34, "UHD id = %c ", id);
uhd_tree = proto_item_add_subtree(ti, ett_uhd);
proto_tree_add_item(uhd_tree, hf_uhd_version, tvb, 0, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_id, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_seq, tvb, 8, 4, ENC_BIG_ENDIAN);
switch (id) {
case UMTRX_CTRL_ID_REQUEST:
case UMTRX_CTRL_ID_RESPONSE:
case USRP2_CTRL_ID_WAZZUP_BRO:
case USRP2_CTRL_ID_WAZZUP_DUDE:
proto_tree_add_item(uhd_tree, hf_uhd_ip_addr, tvb, 12, 4, ENC_BIG_ENDIAN);
break;
case USRP2_CTRL_ID_TRANSACT_ME_SOME_SPI_BRO:
case USRP2_CTRL_ID_OMG_TRANSACTED_SPI_DUDE:
proto_tree_add_item(uhd_tree, hf_uhd_spi_dev, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_spi_data, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_spi_miso_edge, tvb, 20, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_spi_mosi_edge, tvb, 21, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_spi_num_bits, tvb, 22, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_spi_readback, tvb, 23, 1, ENC_BIG_ENDIAN);
break;
case USRP2_CTRL_ID_DO_AN_I2C_READ_FOR_ME_BRO:
case USRP2_CTRL_ID_HERES_THE_I2C_DATA_DUDE:
case USRP2_CTRL_ID_WRITE_THESE_I2C_VALUES_BRO:
case USRP2_CTRL_ID_COOL_IM_DONE_I2C_WRITE_DUDE:
proto_tree_add_item(uhd_tree, hf_uhd_i2c_addr, tvb, 12, 1, ENC_BIG_ENDIAN);
i2c_bytes = tvb_get_guint8(tvb, 13);
proto_tree_add_item(uhd_tree, hf_uhd_i2c_bytes, tvb, 13, 1, ENC_BIG_ENDIAN);
for (ind = 0; ind < i2c_bytes; ind++) {
proto_tree_add_item(uhd_tree, hf_uhd_i2c_data, tvb, 14 + ind, 1, ENC_BIG_ENDIAN);
}
break;
case USRP2_CTRL_ID_GET_THIS_REGISTER_FOR_ME_BRO:
case USRP2_CTRL_ID_OMG_GOT_REGISTER_SO_BAD_DUDE:
proto_tree_add_item(uhd_tree, hf_uhd_reg_addr, tvb, 12, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_reg_data, tvb, 16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(uhd_tree, hf_uhd_reg_action, tvb, 20, 1, ENC_BIG_ENDIAN);
break;
case USRP2_CTRL_ID_HOLLER_AT_ME_BRO:
case USRP2_CTRL_ID_HOLLER_BACK_DUDE:
case USRP2_CTRL_ID_HUH_WHAT:
case USRP2_CTRL_ID_PEACE_OUT:
proto_tree_add_item(uhd_tree, hf_uhd_echo_len, tvb, 12, 4, ENC_BIG_ENDIAN);
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_uhd(void)
{
static hf_register_info hf[] = {
{ &hf_uhd_version, { "VERSION", "uhd.version",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_uhd_id, { "ID", "uhd.id",
FT_UINT32, BASE_HEX, VALS(uhd_ids), 0, NULL, HFILL } },
{ &hf_uhd_seq, { "SEQ", "uhd.seq",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_uhd_ip_addr, { "IP ADDR", "uhd.ip_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,"", HFILL } },
{ &hf_uhd_i2c_addr, { "I2C ADDR", "uhd.i2c_addr",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_i2c_bytes, { "I2C BYTES", "uhd.i2c_bytes",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_uhd_i2c_data, { "I2C DATA", "uhd.i2c_data",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_spi_dev, { "SPI DEV", "uhd.spi_dev",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_spi_data, { "SPI DATA", "uhd.spi_data",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_spi_miso_edge, { "SPI MISO EDGE", "uhd.spi_miso_edge",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_spi_mosi_edge, { "SPI MOSI EDGE", "uhd.spi_mosi_edge",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_spi_num_bits, { "SPI NUM BITS", "uhd.spi_num_bits",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_uhd_spi_readback, { "SPI READBACK", "uhd.spi_readback",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_reg_addr, { "REG ADDR", "uhd.reg_addr",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_reg_data, { "REG DATA", "uhd.reg_data",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_uhd_reg_action, { "REG ACTION", "uhd.reg_action",
FT_UINT8, BASE_HEX, VALS(uhd_reg_actions), 0, NULL, HFILL } },
{ &hf_uhd_echo_len, { "ECHO LEN", "uhd.echo_len",
FT_UINT32, BASE_DEC, NULL, 0, NULL, HFILL } },
};
static gint *ett[] = {
&ett_uhd
};
module_t *uhd_module;
proto_uhd = proto_register_protocol("UHD", "UHD", "uhd");
proto_register_field_array(proto_uhd, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
uhd_module = prefs_register_protocol(proto_uhd, proto_reg_handoff_uhd);
prefs_register_uint_preference(uhd_module,
"dissector_port",
"Dissector UDP port",
"The UDP port used by this dissector",
10, &dissector_port_pref);
}
void
proto_reg_handoff_uhd(void)
{
static gboolean uhd_prefs_initialized = FALSE;
static dissector_handle_t uhd_handle;
static gint dissector_port;
if (!uhd_prefs_initialized) {
uhd_handle = create_dissector_handle(dissect_uhd, proto_uhd);
uhd_prefs_initialized = TRUE;
} else {
dissector_delete_uint("udp.port", dissector_port, uhd_handle);
}
dissector_port = dissector_port_pref;
dissector_add_uint("udp.port", dissector_port, uhd_handle);
}
