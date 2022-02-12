static gint get_rx_pdu_length(guint32 channel_type)
{
gint len = 0;
switch(channel_type) {
case TETRA_CHAN_AACH:
len = 14;
break;
case TETRA_CHAN_SCH_F:
len = 268;
break;
case TETRA_CHAN_SCH_D:
len = 124; ;
break;
case TETRA_CHAN_BSCH:
len = 60;
break;
case TETRA_CHAN_BNCH:
len = 124;
break;
case TETRA_CHAN_TCH_F:
len = 274;
break;
case TETRA_CHAN_TCH_H:
len = 137;
break;
case TETRA_CHAN_TCH_2_4:
len = 144;
break;
case TETRA_CHAN_TCH_4_8:
len = 288;
break;
case TETRA_CHAN_STCH:
len = 124;
break;
case TETRA_CHAN_SCH_HU:
len = 92;
break;
default:
len = 0;
break;
}
return len;
}
static gint get_tx_pdu_length(guint32 channel_type)
{
gint len = 0;
switch(channel_type) {
case TETRA_CHAN_AACH:
len = 14;
break;
case TETRA_CHAN_SCH_F:
len = 268;
break;
case TETRA_CHAN_SCH_D:
len = 124;
break;
case TETRA_CHAN_BSCH:
len = 60;
break;
case TETRA_CHAN_BNCH:
len = 124;
break;
case TETRA_CHAN_TCH_F:
len = 274;
break;
case TETRA_CHAN_TCH_H:
len = 137;
break;
case TETRA_CHAN_TCH_2_4:
len = 144;
break;
case TETRA_CHAN_TCH_4_8:
len = 288;
break;
case TETRA_CHAN_STCH:
len = 124;
break;
}
return len;
}
void tetra_dissect_pdu(int channel_type, int dir, tvbuff_t *pdu, proto_tree *tree, packet_info *pinfo)
{
proto_item *tetra_sub_item;
proto_tree *tetra_sub_tree;
guint8 p;
tetra_sub_item = proto_tree_add_item(tree, hf_tetra_pdu,
pdu, 0, tvb_length(pdu), ENC_NA);
tetra_sub_tree = proto_item_add_subtree(tetra_sub_item, ett_tetra);
switch(channel_type) {
case TETRA_CHAN_AACH:
dissect_AACH_PDU(pdu, pinfo, tetra_sub_tree );
break;
case TETRA_CHAN_SCH_F:
p = tvb_get_guint8(pdu, 0);
switch(p >> 6) {
case 0:
dissect_MAC_RESOURCE_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 1:
if((p >> 5) == 3) {
if (dir == TETRA_DOWNLINK)
dissect_MAC_END_DOWNLINK_PDU(pdu, pinfo, tetra_sub_tree );
else
dissect_MAC_END_UPLINK_PDU(pdu, pinfo, tetra_sub_tree);
} else
dissect_MAC_FRAG_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 2:
dissect_MAC_ACCESS_DEFINE_PDU(pdu, pinfo, tetra_sub_tree );
break;
}
break;
case TETRA_CHAN_SCH_D:
p = tvb_get_guint8(pdu, 0);
switch(p >> 6) {
case 0:
dissect_MAC_RESOURCE_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 1:
if((p >> 5) == 3)
dissect_MAC_END_DOWN111_PDU(pdu, pinfo, tetra_sub_tree );
else
dissect_MAC_FRAG120_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 2:
dissect_MAC_ACCESS_DEFINE_PDU(pdu, pinfo, tetra_sub_tree );
break;
}
break;
case TETRA_CHAN_SCH_HU:
p = tvb_get_guint8(pdu, 0);
switch(p >> 7) {
case 0:
dissect_MAC_ACCESS_PDU(pdu, pinfo, tetra_sub_tree);
break;
case 1:
dissect_MAC_END_HU_PDU(pdu, pinfo, tetra_sub_tree);
break;
}
break;
case TETRA_CHAN_BSCH:
dissect_BSCH_PDU(pdu, pinfo, tetra_sub_tree );
break;
case TETRA_CHAN_BNCH:
dissect_BNCH_PDU(pdu, pinfo, tetra_sub_tree );
break;
case TETRA_CHAN_STCH:
p = tvb_get_guint8(pdu, 0);
switch(p >> 6) {
case 0:
dissect_MAC_RESOURCE_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 1:
if((p >> 5) == 3) {
if (dir == TETRA_DOWNLINK)
dissect_MAC_END_DOWN111_PDU(pdu, pinfo, tetra_sub_tree );
else
dissect_MAC_END_UP114_PDU(pdu, pinfo, tetra_sub_tree);
} else
dissect_MAC_FRAG120_PDU(pdu, pinfo, tetra_sub_tree );
break;
case 2:
dissect_MAC_ACCESS_DEFINE_PDU(pdu, pinfo, tetra_sub_tree );
break;
}
break;
}
}
static void dissect_tetra_UNITDATA_IND(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tetra_tree, int offset)
{
guint32 rxreg = 0;
guint32 channels = 0, i;
guint32 channel_type;
gint pdu_offset = 0;
proto_item *tetra_sub_item;
proto_tree *tetra_header_tree = NULL;
tvbuff_t *payload_tvb;
rxreg = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tetra_tree, hf_tetra_len0, tvb, offset, 4, rxreg);
offset += 4;
rxreg = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tetra_tree, hf_tetra_rvstr, tvb, offset, 4, rxreg);
channels = rxreg & 0x3;
tetra_sub_item = proto_tree_add_uint( tetra_tree, hf_tetra_channels, tvb, offset, 4, channels );
tetra_header_tree = proto_item_add_subtree(tetra_sub_item, ett_tetra);
if (channels > 3) {
expert_add_info_format(pinfo, tetra_sub_item, PI_MALFORMED, PI_WARN,
"Channel count incorrect, must be <= 3");
channels = 3;
}
pdu_offset = offset + 4;
for(i = 0; i < channels; i++) {
gint hf_channel[] = {
hf_tetra_rxchannel1,
hf_tetra_rxchannel2,
hf_tetra_rxchannel3
};
gint byte_len, bits_len, remaining_bits;
channel_type = (rxreg >> ((i + 1) * 4) ) & 0xf;
proto_tree_add_uint( tetra_header_tree, hf_channel[i], tvb, offset, 4, channel_type);
proto_tree_add_boolean( tetra_header_tree, hf_tetra_crc, tvb, offset, 4, !(rxreg >> (i + 2) & 0x01));
bits_len = get_rx_pdu_length(channel_type);
byte_len = bits_len >> 3;
remaining_bits = bits_len % 8;
if ((remaining_bits)!=0)
byte_len++;
payload_tvb = tvb_new_subset(tvb, pdu_offset, byte_len, byte_len);
tetra_dissect_pdu(channel_type, TETRA_UPLINK, payload_tvb, tetra_header_tree, pinfo);
if ((remaining_bits)!=0)
byte_len--;
pdu_offset += byte_len;
}
}
void dissect_tetra_UNITDATA_REQ(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tetra_tree, int offset)
{
guint32 txreg = 0;
guint32 channels = 0, i;
guint32 channel_type;
gint pdu_offset = 0;
proto_item *tetra_sub_item = NULL;
proto_tree *tetra_header_tree = NULL;
tvbuff_t *payload_tvb;
txreg = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tetra_tree, hf_tetra_txreg, tvb, offset, 4, txreg);
channels = (txreg & 0x3) + 1;
tetra_sub_item = proto_tree_add_uint( tetra_tree, hf_tetra_channels, tvb, offset, 4, channels );
tetra_header_tree = proto_item_add_subtree(tetra_sub_item, ett_tetra);
txreg >>= 2;
if(channels == 2)
txreg >>= 4;
if (channels > 3) {
expert_add_info_format(pinfo, tetra_sub_item, PI_MALFORMED, PI_WARN,
"Channel count incorrect, must be <= 3");
channels = 3;
}
pdu_offset = offset + 4;
for(i = 0; i < channels; i++) {
gint hf_channel[] = {hf_tetra_channel1, hf_tetra_channel2, hf_tetra_channel3};
gint byte_len, bits_len, remaining_bits;
channel_type = txreg & 0xf;
proto_tree_add_uint( tetra_header_tree, hf_channel[i], tvb, offset, 4, channel_type);
txreg >>= 4;
bits_len = get_tx_pdu_length(channel_type);
byte_len = bits_len >> 3;
remaining_bits = bits_len % 8;
if ((remaining_bits)!=0)
byte_len++;
payload_tvb = tvb_new_subset(tvb, pdu_offset, byte_len, byte_len);
tetra_dissect_pdu(channel_type, TETRA_DOWNLINK, payload_tvb, tetra_header_tree, pinfo);
pdu_offset += byte_len;
}
}
static void
dissect_tetra(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *tetra_item = NULL;
proto_item *tetra_sub_item = NULL;
proto_tree *tetra_tree = NULL;
proto_tree *tetra_header_tree = NULL;
guint16 type = 0;
guint16 carriernumber = -1;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_tetra);
col_clear(pinfo->cinfo,COL_INFO);
type = tvb_get_guint8(tvb, 0);
if(include_carrier_number) {
carriernumber = tvb_get_guint8(tvb, 1);
carriernumber |= 0xff00;
}
switch(type) {
case 1:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d tetra-UNITDATA-REQ, Carrier: %d",
pinfo->srcport, pinfo->destport, carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d tetra-UNITDATA-REQ",
pinfo->srcport, pinfo->destport);
break;
case 2:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d tetra-UNITDATA-IND, Carrier: %d",
pinfo->srcport, pinfo->destport, carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d tetra-UNITDATA-IND",
pinfo->srcport, pinfo->destport);
break;
case 3:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d MAC-Timer, Carrier: %d",
pinfo->srcport, pinfo->destport, carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d MAC-Timer",
pinfo->srcport, pinfo->destport);
break;
case 127:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d tetra-UNITDATA-IND Done, Carrier: %d",
pinfo->srcport, pinfo->destport, carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d tetra-UNITDATA-IND Done",
pinfo->srcport, pinfo->destport);
break;
case 128:
if(include_carrier_number)
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d tetra-UNITDATA-REQ Done, Carrier: %d",
pinfo->srcport, pinfo->destport, carriernumber);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d tetra-UNITDATA-REQ Done",
pinfo->srcport, pinfo->destport);
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "%d > %d Unknown command: %d",
pinfo->srcport, pinfo->destport, type);
break;
}
if (tree) {
guint32 offset = 0;
guint32 txtimer = 0;
guint32 tslot = 0;
tetra_item = proto_tree_add_item(tree, proto_tetra, tvb, 0, -1, ENC_NA);
tetra_tree = proto_item_add_subtree(tetra_item, ett_tetra);
offset ++;
if(include_carrier_number) {
proto_tree_add_uint(tetra_tree, hf_tetra_carriernumber, tvb, offset, 1, carriernumber);
offset ++;
}
tetra_sub_item = proto_tree_add_item( tetra_tree, hf_tetra_header, tvb, offset, -1, ENC_NA );
tetra_header_tree = proto_item_add_subtree(tetra_sub_item, ett_tetra);
txtimer = tvb_get_letohl(tvb, offset);
tetra_sub_item = proto_tree_add_item(tetra_header_tree, hf_tetra_timer, tvb, offset, 4, ENC_LITTLE_ENDIAN);
tslot = ((txtimer & 0x7800) >> 11);
if(tslot==4)
tslot = 3;
if(tslot==8)
tslot = 4;
proto_item_append_text(tetra_sub_item, " (Multiple frame: %d, Frame: %d, Slot: %d)",
txtimer & 0x3F, (txtimer & 0x7c0) >> 6,
tslot);
offset += 4;
switch(type) {
case 1:
case 128:
dissect_tetra_UNITDATA_REQ(tvb, pinfo, tetra_header_tree, offset);
break;
case 2:
case 127:
dissect_tetra_UNITDATA_IND(tvb, pinfo, tetra_header_tree, offset);
break;
case 3:
break;
default:
break;
}
}
}
void proto_reg_handoff_tetra(void)
{
static gboolean initialized=FALSE;
if (!initialized) {
data_handle = find_dissector("data");
tetra_handle = create_dissector_handle(dissect_tetra, proto_tetra);
dissector_add_uint("udp.port", global_tetra_port, tetra_handle);
}
}
void proto_register_tetra (void)
{
module_t *per_module;
static hf_register_info hf[] = {
{ &hf_tetra,
{ "Data", "tetra.data", FT_NONE, BASE_NONE, NULL, 0x0,
"tetra PDU", HFILL }},
{ &hf_tetra_header,
{ "Registers", "tetra.header", FT_NONE, BASE_NONE, NULL, 0x0,
"TETRA Registers", HFILL }},
{ &hf_tetra_channels,
{ "Logical Channels", "tetra.channels", FT_UINT8, BASE_DEC, NULL, 0x0,
"The amount of logical channels", HFILL }},
{ &hf_tetra_channel1,
{ "Channel 1", "tetra.txchannel1", FT_UINT8, BASE_DEC, VALS(channeltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_channel2,
{ "Channel 2", "tetra.txchannel2", FT_UINT8, BASE_DEC, VALS(channeltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_channel3,
{ "Channel 3", "tetra.txchannel3", FT_UINT8, BASE_DEC, VALS(channeltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_txreg,
{ "TxR", "tetra.txreg", FT_UINT16, BASE_HEX, NULL, 0x0,
"TX Register", HFILL }},
{ &hf_tetra_rvstr,
{ "RvSteR", "tetra.rvster", FT_UINT16, BASE_HEX, NULL, 0x0,
"Receive Status Register", HFILL }},
{ &hf_tetra_carriernumber,
{ "Carrier Number", "tetra.carrier", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_tetra_rxchannel1,
{ "Channel 1", "tetra.rxchannel1", FT_UINT8, BASE_DEC, VALS(recvchanneltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_rxchannel2,
{ "Channel 2", "tetra.rxchannel2", FT_UINT8, BASE_DEC, VALS(recvchanneltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_rxchannel3,
{ "Channel 3", "tetra.rxchannel3", FT_UINT8, BASE_DEC, VALS(recvchanneltypenames), 0x0,
"Logical channels type", HFILL }},
{ &hf_tetra_timer,
{ "Timer", "tetra.timer", FT_UINT16, BASE_HEX, NULL, 0x0,
"Timer Register", HFILL }},
{ &hf_tetra_crc,
{ "CRC", "tetra.crc", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"CRC result", HFILL }},
{ &hf_tetra_len0,
{ "Length", "tetra.len0", FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of the PDU", HFILL }},
{ &hf_tetra_pdu,
{ "PDU", "tetra.pdu", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }} ,
#include "packet-tetra-hfarr.c"
};
static gint *ett[] = {
&ett_tetra,
&ett_tetra_header,
&ett_tetra_length,
&ett_tetra_txreg,
&ett_tetra_text,
#include "packet-tetra-ettarr.c"
};
if (proto_tetra != -1)
return;
proto_tetra = proto_register_protocol("TETRA Protocol", "tetra", "tetra");
proto_register_field_array (proto_tetra, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
register_dissector("tetra", dissect_tetra, proto_tetra);
per_module = prefs_register_protocol(proto_tetra, NULL);
prefs_register_bool_preference(per_module, "include_carrier_number",
"The data include carrier numbers",
"Whether the captured data include carrier number",
&include_carrier_number);
}
