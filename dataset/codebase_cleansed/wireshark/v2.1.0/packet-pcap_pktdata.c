static int
dissect_pcap_pktdata(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
guint32 *link_type;
tvbuff_t *next_tvb;
proto_item *pseudoheader_item;
proto_tree *pseudoheader_tree = NULL;
proto_item *packet_item;
struct eth_phdr eth;
void *phdr;
DISSECTOR_ASSERT(data);
link_type = (guint32 *) data;
pinfo->phdr->pkt_encap = wtap_pcap_encap_to_wtap_encap(*link_type);
if (pinfo->phdr->pkt_encap == WTAP_ENCAP_UNKNOWN) {
packet_item = proto_tree_add_item(tree, hf_pcap_pktdata_undecoded_data, tvb, offset, tvb_reported_length(tvb), ENC_NA);
expert_add_info_format(pinfo, packet_item,
&ei_pcap_pktdata_linktype_unknown,
"Link-layer header type %u is not supported",
*link_type);
return tvb_captured_length(tvb);
}
if (wtap_encap_requires_phdr(pinfo->phdr->pkt_encap)) {
switch (pinfo->phdr->pkt_encap) {
case WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR:
pseudoheader_item = proto_tree_add_item(tree, hf_pcap_pktdata_pseudoheader, tvb, offset, 4, ENC_NA);
pseudoheader_tree = proto_item_add_subtree(pseudoheader_item, ett_pcap_pktdata_pseudoheader);
proto_tree_add_item(pseudoheader_tree, hf_pcap_pktdata_pseudoheader_bluetooth_direction, tvb, offset, 4, ENC_BIG_ENDIAN);
if (tvb_get_guint32(tvb, offset, ENC_BIG_ENDIAN) == 0)
pinfo->p2p_dir = P2P_DIR_SENT;
else if (tvb_get_guint32(tvb, offset, ENC_BIG_ENDIAN) == 1)
pinfo->p2p_dir = P2P_DIR_RECV;
else
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
offset += 4;
phdr = NULL;
break;
case WTAP_ENCAP_ATM_PDUS:
case WTAP_ENCAP_IRDA:
case WTAP_ENCAP_MTP2_WITH_PHDR:
case WTAP_ENCAP_LINUX_LAPD:
case WTAP_ENCAP_SITA:
case WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR:
case WTAP_ENCAP_NFC_LLCP:
case WTAP_ENCAP_PPP_WITH_PHDR:
case WTAP_ENCAP_ERF:
case WTAP_ENCAP_I2C:
default:
packet_item = proto_tree_add_item(tree, hf_pcap_pktdata_undecoded_data, tvb, offset, tvb_reported_length(tvb), ENC_NA);
expert_add_info_format(pinfo, packet_item,
&ei_pcap_pktdata_cant_generate_phdr,
"No pseudo-header can be generated for link-layer header type %u",
*link_type);
return tvb_captured_length(tvb);
}
} else {
switch (pinfo->phdr->pkt_encap) {
case WTAP_ENCAP_ETHERNET:
eth.fcs_len = -1;
phdr = &eth;
break;
default:
phdr = NULL;
break;
}
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
offset = dissector_try_uint_new(wtap_encap_table, pinfo->phdr->pkt_encap, next_tvb, pinfo, tree, TRUE, phdr);
return offset;
}
void
proto_register_pcap_pktdata(void)
{
static hf_register_info hf[] = {
{ &hf_pcap_pktdata_pseudoheader,
{ "Pseudoheader", "pcap_pktdata.data.pseudoheader",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_pcap_pktdata_pseudoheader_bluetooth_direction,
{ "Direction", "pcap_pktdata.pseudoheader.bluetooth.direction",
FT_UINT32, BASE_HEX, VALS(pseudoheader_bluetooth_direction_vals), 0x00,
NULL, HFILL }
},
{ &hf_pcap_pktdata_undecoded_data,
{ "Undecoded data", "pcap_pktdata.undecoded_data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_pcap_pktdata_pseudoheader,
};
static ei_register_info ei[] = {
{ &ei_pcap_pktdata_linktype_unknown, { "pcap_pktdata.linktype_unknown", PI_UNDECODED, PI_NOTE, "That link-layer header type is not supported", EXPFILL }},
{ &ei_pcap_pktdata_cant_generate_phdr, { "pcap_pktdata.cant_generate_phdr", PI_UNDECODED, PI_NOTE, "No pseudo-header can be generated for that link-layer header type", EXPFILL }},
};
expert_module_t *expert_pcap_pktdata;
proto_pcap_pktdata = proto_register_protocol("pcap/pcapng packet data", "pcap_pktdata", "pcap_pktdata");
proto_register_field_array(proto_pcap_pktdata, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_pcap_pktdata = expert_register_protocol(proto_pcap_pktdata);
expert_register_field_array(expert_pcap_pktdata, ei, array_length(ei));
register_dissector("pcap_pktdata", dissect_pcap_pktdata, proto_pcap_pktdata);
}
void
proto_reg_handoff_pcap_pktdata(void)
{
wtap_encap_table = find_dissector_table("wtap_encap");
}
