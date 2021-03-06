static double getOlsrTime(guint8 timeval) {
int high_bits, low_bits;
high_bits = ((timeval & 0xF0) >> 4);
low_bits = (timeval & 0x0F);
return ((1 << low_bits) / 16.0) * (1 + (high_bits / 16.0));
}
static int dissect_olsr_tc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset, int message_end) {
if (message_end - offset < 4) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_ansn, tvb, offset, message_end - offset,
NULL, "Not enough bytes for TC");
return message_end;
}
proto_tree_add_item(olsr_tree, hf_olsr_ansn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 4;
while (offset < message_end) {
if (message_end - offset < pinfo->src.len) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor_addr, tvb, offset, message_end - offset,
NULL, "Not enough bytes for last neighbor");
return message_end;
}
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_item(olsr_tree, hf_olsr_neighbor_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_item(olsr_tree, hf_olsr_neighbor6_addr, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
break;
}
}
return message_end;
}
static int dissect_olsrorg_lq_tc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset, int message_end) {
if (message_end - offset < 4) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_ansn, tvb, offset, message_end - offset,
NULL, "Not enough bytes for Olsr.org LQ-TC");
return message_end;
}
proto_tree_add_item(olsr_tree, hf_olsr_ansn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 4;
while (offset < message_end) {
proto_item *address_group;
proto_tree *address_tree;
guint8 lq, nlq;
if (pinfo->src.type == AT_IPv4) {
if (message_end - offset < 8) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor, tvb, offset, message_end - offset,
NULL, "Not enough bytes for last entry (need 8 bytes)");
return message_end;
}
lq = tvb_get_guint8(tvb, offset + 4);
nlq = tvb_get_guint8(tvb, offset + 5);
address_group = proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor, tvb, offset, 8,
NULL, "Neighbor Address: %s (%d/%d)", tvb_ip_to_str(tvb, offset), lq, nlq);
address_tree = proto_item_add_subtree(address_group, ett_olsr_message_neigh);
proto_tree_add_item(address_tree, hf_olsr_neighbor_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (pinfo->src.type == AT_IPv6) {
if (message_end - offset < 20) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor, tvb, offset, message_end - offset,
NULL, "Not enough bytes for last entry (need 20 bytes)");
return message_end;
}
lq = tvb_get_guint8(tvb, offset + 16);
nlq = tvb_get_guint8(tvb, offset + 17);
address_group = proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor, tvb, offset, 20,
NULL, "Neighbor Address: %s (%d/%d)", tvb_ip6_to_str(tvb, offset), lq, nlq);
address_tree = proto_item_add_subtree(address_group, ett_olsr_message_neigh);
proto_tree_add_item(address_tree, hf_olsr_neighbor6_addr, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
break;
}
proto_tree_add_item(address_tree, hf_olsrorg_lq, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(address_tree, hf_olsrorg_nlq, tvb, offset++, 1, ENC_BIG_ENDIAN);
offset += 2;
}
return message_end;
}
static int dissect_nrlolsr_tc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset, int message_end) {
int field1Ptr, field2Ptr, saneEnd;
if (message_end - offset < 4) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_ansn, tvb, offset, message_end - offset,
NULL, "Not enough bytes for NRLOLSR LQ-TC");
return message_end;
}
proto_tree_add_item(olsr_tree, hf_olsr_ansn, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 4;
field1Ptr = offset + (message_end - offset) / (pinfo->src.len + 2) * (pinfo->src.len);
field2Ptr = offset + (message_end - offset) / (pinfo->src.len + 2) * (pinfo->src.len + 1);
saneEnd = message_end - ((message_end - offset) % (pinfo->src.len + 2));
while (field2Ptr < saneEnd) {
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_item(olsr_tree, hf_olsr_neighbor_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_item(olsr_tree, hf_olsr_neighbor6_addr, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
break;
}
proto_tree_add_item(olsr_tree, hf_nrlolsr_f1, tvb, field1Ptr++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(olsr_tree, hf_nrlolsr_f2, tvb, field2Ptr++, 1, ENC_BIG_ENDIAN);
}
return message_end;
}
static int dissect_olsr_hello(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset, int message_end,
int(*handleNeighbors)(tvbuff_t *, packet_info *, proto_tree *, int, int)) {
double hTime;
proto_item *ti;
proto_tree *link_type_tree;
guint16 message_size = 0;
if (message_end - offset < 4) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_htime, tvb, offset, message_end - offset,
NULL, "Not enough bytes for Hello");
return message_end;
}
offset += 2;
hTime = getOlsrTime(tvb_get_guint8(tvb, offset));
proto_tree_add_double_format(olsr_tree, hf_olsr_htime, tvb, offset, 1, hTime,
"Hello Emission Interval: %.3f (in seconds)", hTime);
offset++;
proto_tree_add_item(olsr_tree, hf_olsr_willingness, tvb, offset++, 1, ENC_BIG_ENDIAN);
while (offset < message_end) {
if (message_end - offset < 4) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_link_type, tvb, offset, message_end - offset,
NULL, "Not enough bytes for last Hello entry");
return message_end;
}
ti = proto_tree_add_item(olsr_tree, hf_olsr_link_type, tvb, offset++, 1, ENC_BIG_ENDIAN);
link_type_tree = proto_item_add_subtree(ti, ett_olsr_message_linktype);
offset++;
message_size = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(link_type_tree, hf_olsr_link_message_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (message_size < 4) {
proto_item_append_string(ti, "(too short, must be >= 4)");
return message_end;
}
offset = handleNeighbors(tvb, pinfo, link_type_tree, offset, offset + message_size - 4);
}
return message_end;
}
static int handle_olsr_hello_rfc(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset,
int link_message_end) {
while (offset < link_message_end) {
if (link_message_end - offset < pinfo->src.len) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor, tvb, offset, link_message_end - offset,
NULL, "Not enough bytes for last Hello entry");
return link_message_end;
}
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_item(olsr_tree, hf_olsr_neighbor_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_item(olsr_tree, hf_olsr_neighbor6_addr, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
break;
}
}
return link_message_end;
}
static int handle_olsr_hello_olsrorg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset,
int link_message_end) {
while (offset < link_message_end) {
proto_item *address_group;
proto_tree *address_tree;
guint8 lq, nlq;
if (link_message_end - offset < pinfo->src.len + 4) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor, tvb, offset, link_message_end - offset,
NULL, "Not enough bytes for last Olsr.org LQ-Hello entry");
return link_message_end;
}
if (pinfo->src.type == AT_IPv4) {
lq = tvb_get_guint8(tvb, offset + 4);
nlq = tvb_get_guint8(tvb, offset + 5);
address_group = proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor, tvb, offset, 8,
NULL, "Neighbor Address: %s (%d/%d)", tvb_ip_to_str(tvb, offset), lq, nlq);
address_tree = proto_item_add_subtree(address_group, ett_olsr_message_neigh);
proto_tree_add_item(address_tree, hf_olsr_neighbor_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (pinfo->src.type == AT_IPv6) {
lq = tvb_get_guint8(tvb, offset + 16);
nlq = tvb_get_guint8(tvb, offset + 17);
address_group = proto_tree_add_bytes_format(olsr_tree, hf_olsr_neighbor, tvb, offset, 20,
NULL, "Neighbor Address: %s (%d/%d)", tvb_ip6_to_str(tvb, offset), lq, nlq);
address_tree = proto_item_add_subtree(address_group, ett_olsr_message_neigh);
proto_tree_add_item(address_tree, hf_olsr_neighbor6_addr, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
break;
}
proto_tree_add_item(address_tree, hf_olsrorg_lq, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(address_tree, hf_olsrorg_nlq, tvb, offset++, 1, ENC_BIG_ENDIAN);
offset += 2;
}
return link_message_end;
}
static int dissect_olsr_mid(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset, int message_end) {
while (offset < message_end) {
if (message_end - offset < pinfo->src.len) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_interface_addr, tvb, offset, message_end - offset,
NULL, "Not enough bytes for last MID entry");
return message_end;
}
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_item(olsr_tree, hf_olsr_interface_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_item(olsr_tree, hf_olsr_interface6_addr, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
break;
}
}
return message_end;
}
static int dissect_olsr_hna(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset, int message_end) {
while (offset < message_end) {
if (message_end - offset < pinfo->src.len * 2) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_network_addr, tvb, offset, message_end - offset,
NULL, "Not enough bytes for last HNA entry");
return message_end;
}
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_item(olsr_tree, hf_olsr_network_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(olsr_tree, hf_olsr_netmask, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_item(olsr_tree, hf_olsr_network6_addr, tvb, offset, 4, ENC_NA);
offset += 16;
proto_tree_add_item(olsr_tree, hf_olsr_netmask6, tvb, offset, 4, ENC_NA);
offset += 16;
} else {
break;
}
}
return message_end;
}
static int dissect_olsrorg_nameservice(tvbuff_t *tvb, packet_info *pinfo, proto_tree *olsr_tree, int offset,
int message_end) {
guint16 version, count;
proto_item *olsr_ns_item;
proto_tree *olsr_ns_tree;
if (message_end - offset < 4) {
proto_tree_add_bytes_format(olsr_tree, hf_olsrorg_ns_version, tvb, offset, message_end - offset,
NULL, "Not enough bytes for Olsr.org Nameservice message");
return message_end;
}
version = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(olsr_tree, hf_olsrorg_ns_version, tvb, offset, 2, ENC_BIG_ENDIAN);
count = tvb_get_ntohs(tvb, offset + 2);
proto_tree_add_item(olsr_tree, hf_olsrorg_ns_count, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
offset += 4;
if (version != 1) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_data, tvb, offset, message_end - offset,
NULL, "Unknown nameservice protocol version %d", version);
return message_end;
}
while (offset < message_end && count-- > 0) {
guint16 type, length;
int total_length;
if (message_end - offset < 20) {
proto_tree_add_bytes_format(olsr_tree, hf_olsrorg_ns, tvb, offset, message_end - offset,
NULL, "Not enough bytes for last nameservice entry");
return message_end;
}
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
total_length = 4 + 16 + ((length - 1) | 3) + 1;
olsr_ns_item = proto_tree_add_bytes_format(olsr_tree, hf_olsrorg_ns, tvb, offset, total_length,
NULL, "Nameservice: %s (%d)", val_to_str_const(type, nameservice_type_vals, "UNKNOWN"), type);
olsr_ns_tree = proto_item_add_subtree(olsr_ns_item, ett_olsr_message_ns);
proto_tree_add_item(olsr_ns_tree, hf_olsrorg_ns_type, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(olsr_ns_tree, hf_olsrorg_ns_length, tvb, offset + 2, 2, length);
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_item(olsr_ns_tree, hf_olsrorg_ns_ip, tvb, offset + 4, 4, ENC_BIG_ENDIAN);
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_item(olsr_ns_tree, hf_olsrorg_ns_ip6, tvb, offset + 4, 16, ENC_NA);
} else {
break;
}
if (message_end - offset < total_length) {
proto_tree_add_bytes_format(olsr_tree, hf_olsrorg_ns, tvb, offset, message_end - offset,
NULL, "Not enough bytes for content of last nameservice entry");
return message_end;
}
proto_tree_add_item(olsr_ns_tree, hf_olsrorg_ns_content, tvb, offset + 20, length, ENC_ASCII|ENC_NA);
offset += 4 + 16 + ((length - 1) | 3) + 1;
}
return message_end;
}
static int dissect_olsr(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
proto_item *ti;
proto_tree *olsr_tree;
int offset, message_len, message_end;
guint message_type;
double vTime;
guint16 packet_len;
if (tvb_length(tvb) < 4) {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "OLSR Packet, Length: %u Bytes (not enough data in packet)",
tvb_length(tvb));
}
return 0;
}
packet_len = tvb_get_ntohs(tvb, 0);
if (packet_len > tvb_length(tvb)) {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "OLSR Packet, Length: %u Bytes (not enough data in packet)", packet_len);
}
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OLSR v1");
col_clear(pinfo->cinfo, COL_INFO);
if ((pinfo->src.type != AT_IPv4) && (pinfo->src.type != AT_IPv6)) {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "OLSR (unknown address type) Packet, Length: %u Bytes", packet_len);
}
return 0;
}
if (check_col(pinfo->cinfo, COL_INFO) && (pinfo->src.type == AT_IPv4)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "OLSR (IPv4) Packet, Length: %u Bytes", packet_len);
} else if (check_col(pinfo->cinfo, COL_INFO) && (pinfo->src.type == AT_IPv6)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "OLSR (IPv6) Packet, Length: %u Bytes", packet_len);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_olsr, tvb, 0, -1, ENC_NA);
olsr_tree = proto_item_add_subtree(ti, ett_olsr);
proto_tree_add_item(olsr_tree, hf_olsr_packet_len, tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(olsr_tree, hf_olsr_packet_seq_num, tvb, 2, 2, ENC_BIG_ENDIAN);
offset = 4;
while (offset < packet_len) {
proto_item *message_item;
proto_tree *message_tree;
if (packet_len - offset < 4) {
proto_tree_add_bytes_format(olsr_tree, hf_olsr_message, tvb, offset, packet_len - offset,
NULL, "Message too short !");
break;
}
message_type = tvb_get_guint8(tvb, offset);
vTime = getOlsrTime(tvb_get_guint8(tvb, offset + 1));
message_len = tvb_get_ntohs(tvb, offset + 2);
message_item = proto_tree_add_bytes_format(olsr_tree, hf_olsr_message, tvb, offset, message_len,
NULL, "Message: %s (%d)", val_to_str_const(message_type, message_type_vals, "UNKNOWN"),
message_type);
message_tree = proto_item_add_subtree(message_item, ett_olsr_message[message_type]);
proto_tree_add_uint(message_tree, hf_olsr_message_type, tvb, offset, 1, message_type);
offset++;
proto_tree_add_double_format(message_tree, hf_olsr_vtime, tvb, offset, 1, vTime,
"Validity Time: %.3f (in seconds)", vTime);
offset++;
ti = proto_tree_add_item(message_tree, hf_olsr_message_size, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (message_len < 8 + pinfo->src.len) {
proto_item_append_text(ti, "(too short, must be >= %d)", 8 + pinfo->src.len);
break;
}
message_end = offset + message_len - 4;
if (message_end > packet_len) {
proto_item_append_string(ti, "(not enough data for message)");
break;
}
if (pinfo->src.type == AT_IPv4) {
proto_tree_add_item(message_tree, hf_olsr_origin_addr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
} else if (pinfo->src.type == AT_IPv6) {
proto_tree_add_item(message_tree, hf_olsr_origin6_addr, tvb, offset, 16, ENC_NA);
offset += 16;
} else {
break;
}
proto_tree_add_item(message_tree, hf_olsr_ttl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_olsr_hop_count, tvb, offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(message_tree, hf_olsr_message_seq_num, tvb, offset + 2, 2, ENC_BIG_ENDIAN);
offset += 4;
if (offset < message_end) {
if (message_type == TC) {
dissect_olsr_tc(tvb, pinfo, message_tree, offset, message_end);
}
else if (message_type == HELLO) {
dissect_olsr_hello(tvb, pinfo, message_tree, offset, message_end, &handle_olsr_hello_rfc);
}
else if (message_type == MID) {
dissect_olsr_mid(tvb, pinfo, message_tree, offset, message_end);
}
else if (message_type == HNA) {
dissect_olsr_hna(tvb, pinfo, message_tree, offset, message_end);
}
else if (global_olsr_olsrorg && message_type == OLSR_ORG_LQ_HELLO) {
dissect_olsr_hello(tvb, pinfo, message_tree, offset, message_end, &handle_olsr_hello_olsrorg);
}
else if (global_olsr_olsrorg && message_type == OLSR_ORG_LQ_TC) {
dissect_olsrorg_lq_tc(tvb, pinfo, message_tree, offset, message_end);
}
else if (global_olsr_olsrorg && message_type == OLSR_ORG_NAMESERVICE) {
dissect_olsrorg_nameservice(tvb, pinfo, message_tree, offset, message_end);
}
else if (global_olsr_nrlolsr && message_type == NRLOLSR_TC_EXTRA) {
dissect_nrlolsr_tc(tvb, pinfo, message_tree, offset, message_end);
}
else {
if ((message_len - 12) % 4) {
proto_tree_add_bytes_format(message_tree, hf_olsr_data, tvb, offset, message_len - 12,
NULL, "Data (%u bytes) (must be aligned on 32 bits)", message_len - 12);
break;
}
proto_tree_add_bytes_format(message_tree, hf_olsr_data, tvb, offset, message_len - 12,
NULL, "Data (%u bytes)", message_len - 12);
offset += message_len - 12;
}
}
offset = message_end;
}
}
return tvb_length(tvb);
}
void proto_register_olsr(void) {
static hf_register_info hf[] = {
{ &hf_olsr_packet_len,
{ "Packet Length", "olsr.packet_len",
FT_UINT16, BASE_DEC, NULL, 0,
"Packet Length in Bytes", HFILL
}
},
{ &hf_olsr_packet_seq_num,
{ "Packet Sequence Number", "olsr.packet_seq_num",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_message,
{ "Message", "olsr.message",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_message_type,
{ "Message Type", "olsr.message_type",
FT_UINT8, BASE_DEC, VALS(message_type_vals), 0,
NULL, HFILL
}
},
{ &hf_olsr_message_size,
{ "Message", "olsr.message_size",
FT_UINT16, BASE_DEC, NULL, 0,
"Message Size in Bytes", HFILL
}
},
{ &hf_olsr_message_seq_num,
{ "Message Sequence Number", "olsr.message_seq_num",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_vtime,
{ "Validity Time", "olsr.vtime",
FT_DOUBLE, BASE_NONE, NULL, 0,
"Validity Time in seconds", HFILL
}
},
{ &hf_olsr_ansn,
{ "Advertised Neighbor Sequence Number (ANSN)", "olsr.ansn",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_htime,
{ "Hello emission interval", "olsr.htime",
FT_DOUBLE, BASE_NONE, NULL, 0,
"Hello emission interval in seconds", HFILL
}
},
{ &hf_olsr_willingness,
{ "Willingness to forward messages", "olsr.willingness",
FT_UINT8, BASE_DEC, VALS(willingness_type_vals), 0,
NULL, HFILL
}
},
{ &hf_olsr_ttl,
{ "TTL", "olsr.ttl",
FT_UINT8, BASE_DEC, NULL, 0,
"Time to Live in hops", HFILL
}
},
{ &hf_olsr_link_type,
{ "Link Type", "olsr.link_type",
FT_UINT8, BASE_DEC, VALS(link_type_vals), 0,
NULL, HFILL
}
},
{ &hf_olsr_link_message_size,
{ "Link Message Size", "olsr.link_message_size",
FT_UINT16, BASE_DEC, NULL, 0,
"Link Message Size in bytes", HFILL
}
},
{ &hf_olsr_hop_count,
{ "Hop Count", "olsr.hop_count",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_neighbor,
{ "Neighbor Address", "olsr.neighbor",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_origin_addr,
{ "Originator Address", "olsr.origin_addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_neighbor_addr,
{ "Neighbor Address", "olsr.neighbor_addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_network_addr,
{ "Network Address", "olsr.network_addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_interface_addr,
{ "Interface Address", "olsr.interface_addr",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_netmask,
{ "Netmask", "olsr.netmask",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
#if 0
{ &hf_olsr_neighbor6,
{ "Neighbor Address", "olsr.neighbor6",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
#endif
{ &hf_olsr_origin6_addr,
{ "Originator Address", "olsr.origin6_addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_neighbor6_addr,
{ "Neighbor Address", "olsr.neighbor6_addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_network6_addr,
{ "Network Address", "olsr.network6_addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_interface6_addr,
{ "Interface Address", "olsr.interface6_addr",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_netmask6,
{ "Netmask", "olsr.netmask6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsr_data,
{ "Data", "olsr.data",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsrorg_lq,
{ "LQ", "olsr.lq",
FT_UINT8, BASE_DEC, NULL, 0,
"Link quality", HFILL
}
},
{ &hf_olsrorg_nlq,
{ "NLQ", "olsr.nlq",
FT_UINT8, BASE_DEC, NULL, 0,
"Neighbor link quality", HFILL
}
},
{ &hf_olsrorg_ns,
{ "Nameservice message", "olsr.ns",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsrorg_ns_version,
{ "Version", "olsr.ns.version",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsrorg_ns_count,
{ "Count", "olsr.ns.count",
FT_UINT16, BASE_DEC, NULL, 0,
"Number of nameservice messages", HFILL
}
},
{ &hf_olsrorg_ns_type,
{ "Message Type", "olsr.ns.type",
FT_UINT16, BASE_DEC, VALS(nameservice_type_vals), 0,
NULL, HFILL
}
},
{ &hf_olsrorg_ns_length,
{ "Length", "olsr.ns.length",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsrorg_ns_ip,
{ "Address", "olsr.ns.ip",
FT_IPv4, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsrorg_ns_ip6,
{ "Address", "olsr.ns.ip6",
FT_IPv6, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_olsrorg_ns_content,
{ "Content", "olsr.ns.content",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL
}
},
{ &hf_nrlolsr_f1,
{ "NRL MINMAX", "olsr.nrl.minmax",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL
}
},
{ &hf_nrlolsr_f2,
{ "NRL SPF", "olsr.nrl.spf",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL
}
}
};
static gint *ett_base[] = {
&ett_olsr,
&ett_olsr_message_linktype,
&ett_olsr_message_neigh,
&ett_olsr_message_neigh6,
&ett_olsr_message_ns
};
gint *ett[array_length(ett_base) + (G_MAXUINT8+1)];
module_t *olsr_module;
int i,j;
memcpy(ett, ett_base, sizeof(ett_base));
j = array_length(ett_base);
for (i=0; i<G_MAXUINT8+1; i++) {
ett_olsr_message[i] = -1;
ett[j++] = &ett_olsr_message[i];
}
proto_olsr = proto_register_protocol("Optimized Link State Routing Protocol", "OLSR", "olsr");
proto_register_field_array(proto_olsr, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
olsr_module = prefs_register_protocol(proto_olsr, NULL);
prefs_register_bool_preference(olsr_module, "ff_olsrorg",
"Dissect olsr.org messages","Dissect custom olsr.org message types (compatible with rfc routing agents)",
&global_olsr_olsrorg);
prefs_register_bool_preference(olsr_module, "nrlolsr",
"Dissect NRL-Olsr TC messages", "Dissect custom nrlolsr tc message (incompatible with rfc routing agents)",
&global_olsr_nrlolsr);
}
void proto_reg_handoff_olsr(void) {
dissector_handle_t olsr_handle;
olsr_handle = new_create_dissector_handle(dissect_olsr, proto_olsr);
dissector_add_uint("udp.port", UDP_PORT_OLSR, olsr_handle);
}
