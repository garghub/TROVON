static void
decode_arfcn(guint16 arfcn, const char **band, guint *uplink, guint *downlink)
{
if( arfcn >= 1 && arfcn <= 124 ) {
*band = "P-GSM 900";
*uplink = 890000 + 200 * arfcn;
*downlink = *uplink + 45000;
}
else if( arfcn == 0 ) {
*band = "E-GSM 900";
*uplink = 890000 + 200 * arfcn;
*downlink = *uplink + 45000;
}
else if( arfcn >= 975 && arfcn <= 1023 ) {
*band = "E-GSM 900";
*uplink = 890000 + 200 * (arfcn - 1024);
*downlink = *uplink + 45000;
}
else if( arfcn >= 955 && arfcn <= 1023 ) {
*band = "R-GSM 900";
*uplink = 890000 + 200 * (arfcn - 1024);
*downlink = *uplink + 45000;
}
else if( arfcn >= 512 && arfcn <= 885 && dcs1800_gsm) {
*band = "DCS 1800";
*uplink = 1710200 + 200 * (arfcn - 512);
*downlink = *uplink + 95000;
}
else if( arfcn >= 512 && arfcn <= 810 && !dcs1800_gsm) {
*band = "PCS 1900";
*uplink = 1850200 + 200 * (arfcn - 512);
*downlink = *uplink + 80000;
}
else if( arfcn >= 259 && arfcn <= 293 ) {
*band = "GSM 450";
*uplink = 450600 + 200 * (arfcn - 259);
*downlink = *uplink + 10000;
}
else if( arfcn >= 306 && arfcn <= 340 ) {
*band = "GSM 480";
*uplink = 479000 + 200 * (arfcn - 306);
*downlink = *uplink + 10000;
}
else if( arfcn >= 128 && arfcn <= 251 ) {
*band = "GSM 850";
*uplink = 824200 + 200 * (arfcn - 128);
*downlink = *uplink + 45000;
}
else {
*band = "Unknown";
*uplink = *downlink = 0;
}
}
static void
dissect_gsm_um(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *gsm_um_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GSM Um");
if (pinfo->pseudo_header->gsm_um.uplink) {
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "BTS");
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "MS");
}
else {
switch (pinfo->pseudo_header->gsm_um.channel) {
case GSM_UM_CHANNEL_BCCH:
case GSM_UM_CHANNEL_CCCH:
case GSM_UM_CHANNEL_PCH:
case GSM_UM_CHANNEL_AGCH:
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "Broadcast");
break;
default:
col_set_str(pinfo->cinfo, COL_RES_DL_DST, "MS");
break;
}
col_set_str(pinfo->cinfo, COL_RES_DL_SRC, "BTS");
}
if (tree) {
const char *channel;
ti = proto_tree_add_item(tree, proto_gsm_um, tvb, 0, 0, ENC_NA);
gsm_um_tree = proto_item_add_subtree(ti, ett_gsm_um);
switch( pinfo->pseudo_header->gsm_um.channel ) {
case GSM_UM_CHANNEL_BCCH: channel = "BCCH"; break;
case GSM_UM_CHANNEL_CCCH: channel = "CCCH"; break;
case GSM_UM_CHANNEL_PCH: channel = "PCH"; break;
case GSM_UM_CHANNEL_AGCH: channel = "AGCH"; break;
case GSM_UM_CHANNEL_SACCH: channel = "SACCH"; break;
case GSM_UM_CHANNEL_FACCH: channel = "FACCH"; break;
case GSM_UM_CHANNEL_SDCCH: channel = "SDCCH"; break;
default: channel = "Unknown"; break;
}
if( pinfo->pseudo_header->gsm_um.uplink ) {
proto_tree_add_string(gsm_um_tree, hf_gsm_um_direction, tvb, 0, 0, "Uplink");
}
else {
proto_tree_add_string(gsm_um_tree, hf_gsm_um_direction, tvb, 0, 0, "Downlink");
}
proto_tree_add_string(gsm_um_tree, hf_gsm_um_channel, tvb, 0, 0, channel);
if( !pinfo->pseudo_header->gsm_um.uplink ) {
const char *band;
guint downlink, uplink;
decode_arfcn(pinfo->pseudo_header->gsm_um.arfcn, &band, &uplink, &downlink);
proto_tree_add_uint(gsm_um_tree, hf_gsm_um_arfcn, tvb, 0, 0,
pinfo->pseudo_header->gsm_um.arfcn);
proto_tree_add_text(gsm_um_tree, tvb, 0, 0,
"Band: %s, Frequency: %u.%03uMHz", band,
downlink / 1000, downlink % 1000);
proto_tree_add_uint(gsm_um_tree, hf_gsm_um_bsic, tvb, 0, 0,
pinfo->pseudo_header->gsm_um.bsic);
proto_tree_add_uint(gsm_um_tree, hf_gsm_um_frame, tvb, 0, 0,
pinfo->pseudo_header->gsm_um.tdma_frame);
proto_tree_add_uint(gsm_um_tree, hf_gsm_um_error, tvb, 0, 0,
pinfo->pseudo_header->gsm_um.error);
proto_tree_add_uint(gsm_um_tree, hf_gsm_um_timeshift, tvb, 0, 0,
pinfo->pseudo_header->gsm_um.timeshift);
}
}
switch( pinfo->pseudo_header->gsm_um.channel ) {
case GSM_UM_CHANNEL_BCCH:
case GSM_UM_CHANNEL_CCCH:
case GSM_UM_CHANNEL_PCH:
case GSM_UM_CHANNEL_AGCH:
if( !pinfo->pseudo_header->gsm_um.uplink ) {
tvbuff_t *next_tvb;
guint8 pseudo_len, len_left, len_byte;
len_left = tvb_length(tvb);
len_byte = tvb_get_guint8(tvb, 0);
pseudo_len = len_byte >> 2;
next_tvb = tvb_new_subset(tvb, 1, MIN(len_left, pseudo_len), -1);
if (tree) {
proto_tree_add_uint(gsm_um_tree, hf_gsm_um_l2_pseudo_len, tvb, 0, 1,
len_byte);
}
if( tvb_length(next_tvb) ) {
call_dissector(dtap_handle, next_tvb, pinfo, tree);
}
}
else {
call_dissector(data_handle, tvb, pinfo, tree);
}
break;
case GSM_UM_CHANNEL_SACCH:
case GSM_UM_CHANNEL_FACCH:
case GSM_UM_CHANNEL_SDCCH:
call_dissector(lapdm_handle, tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, tvb, pinfo, tree);
break;
}
}
void
proto_register_gsm_um(void)
{
static hf_register_info hf[] = {
{ &hf_gsm_um_direction,
{ "Direction", "gsm_um.direction", FT_STRINGZ, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_um_channel,
{ "Channel", "gsm_um.channel", FT_STRINGZ, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_um_bsic,
{ "BSIC", "gsm_um.bsic", FT_UINT8, BASE_DEC,
NULL, 0x0, "Base station identity code", HFILL }},
{ &hf_gsm_um_arfcn,
{ "ARFCN", "gsm_um.arfcn", FT_UINT16, BASE_DEC,
NULL, 0x0, "Absolute radio frequency channel number", HFILL }},
{ &hf_gsm_um_frame,
{ "TDMA Frame", "gsm_um.frame", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_um_error,
{ "Error", "gsm_um.error", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_um_timeshift,
{ "Timeshift", "gsm_um.timeshift", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_um_l2_pseudo_len,
{ "L2 Pseudo Length", "gsm_um.l2_pseudo_len", FT_UINT8, BASE_DEC,
NULL, GSM_UM_L2_PSEUDO_LEN, NULL, HFILL }}
};
static gint *ett[] = {
&ett_gsm_um
};
module_t *gsm_um_module;
proto_gsm_um = proto_register_protocol("GSM Um Interface", "GSM Um", "gsm_um");
proto_register_field_array(proto_gsm_um, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
gsm_um_module = prefs_register_protocol(proto_gsm_um, NULL);
prefs_register_bool_preference(gsm_um_module, "dcs1800",
"Treat ARFCN 512-810 as DCS 1800 rather than PCS 1900",
"Treat ARFCN 512-810 as DCS 1800 rather than PCS 1900",
&dcs1800_gsm);
}
void
proto_reg_handoff_gsm_um(void)
{
dissector_handle_t gsm_um_handle;
lapdm_handle = find_dissector("lapdm");
dtap_handle = find_dissector("gsm_a_dtap");
data_handle = find_dissector("data");
gsm_um_handle = create_dissector_handle(dissect_gsm_um, proto_gsm_um);
dissector_add_uint("wtap_encap", WTAP_ENCAP_GSM_UM, gsm_um_handle);
}
