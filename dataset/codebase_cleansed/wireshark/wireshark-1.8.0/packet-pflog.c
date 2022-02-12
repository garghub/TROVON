static void
dissect_pflog(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_tree *pflog_tree = NULL;
proto_item *ti = NULL, *ti_len;
int length;
guint8 af, action;
guint8 *ifname;
guint32 rulenr;
guint8 pad_len = 3;
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PFLOG");
if (tree) {
ti = proto_tree_add_item(tree, proto_pflog, tvb, offset, 0, ENC_NA);
pflog_tree = proto_item_add_subtree(ti, ett_pflog);
}
length = tvb_get_guint8(tvb, offset) + pad_len;
ti_len = proto_tree_add_item(pflog_tree, hf_pflog_length, tvb, offset, 1, ENC_BIG_ENDIAN);
if(length < LEN_PFLOG_BSD34)
{
expert_add_info_format(pinfo, ti_len, PI_MALFORMED, PI_ERROR, "Invalid header length %u", length);
}
offset += 1;
proto_tree_add_item(pflog_tree, hf_pflog_af, tvb, offset, 1, ENC_BIG_ENDIAN);
af = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(pflog_tree, hf_pflog_action, tvb, offset, 1, ENC_BIG_ENDIAN);
action = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(pflog_tree, hf_pflog_reason, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(pflog_tree, hf_pflog_ifname, tvb, offset, 16, ENC_ASCII|ENC_NA);
ifname = tvb_get_ephemeral_string(tvb, offset, 16);
offset += 16;
proto_tree_add_item(pflog_tree, hf_pflog_ruleset, tvb, offset, 16, ENC_ASCII|ENC_NA);
offset += 16;
proto_tree_add_item(pflog_tree, hf_pflog_rulenr, tvb, offset, 4, ENC_BIG_ENDIAN);
rulenr = tvb_get_ntohs(tvb, offset);
offset += 4;
proto_tree_add_item(pflog_tree, hf_pflog_subrulenr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if(length >= LEN_PFLOG_BSD38)
{
proto_tree_add_item(pflog_tree, hf_pflog_uid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pflog_tree, hf_pflog_pid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pflog_tree, hf_pflog_rule_uid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pflog_tree, hf_pflog_rule_pid, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
proto_tree_add_item(pflog_tree, hf_pflog_dir, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if(length >= LEN_PFLOG_BSD49)
{
pad_len = 2;
length -= 3;
proto_tree_add_item(pflog_tree, hf_pflog_rewritten, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
proto_tree_add_item(pflog_tree, hf_pflog_pad, tvb, offset, pad_len, ENC_NA);
offset += pad_len;
if(length >= LEN_PFLOG_BSD49)
{
switch (af) {
case BSD_AF_INET:
proto_tree_add_item(pflog_tree, hf_pflog_saddr_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 16;
proto_tree_add_item(pflog_tree, hf_pflog_daddr_ipv4, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 16;
break;
case BSD_AF_INET6_BSD:
proto_tree_add_item(pflog_tree, hf_pflog_saddr_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(pflog_tree, hf_pflog_daddr_ipv6, tvb, offset, 16, ENC_NA);
offset += 16;
break;
default:
proto_tree_add_item(pflog_tree, hf_pflog_saddr, tvb, offset, 16, ENC_NA);
offset += 16;
proto_tree_add_item(pflog_tree, hf_pflog_daddr, tvb, offset, 16, ENC_NA);
offset += 16;
break;
}
proto_tree_add_item(pflog_tree, hf_pflog_sport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pflog_tree, hf_pflog_dport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
proto_item_set_text(ti, "PF Log %s %s on %s by rule %u",
val_to_str(af, pflog_af_vals, "unknown (%u)"),
val_to_str(action, pflog_action_vals, "unknown (%u)"),
ifname,
rulenr);
proto_item_set_len(ti, offset);
next_tvb = tvb_new_subset_remaining(tvb, length);
switch (af) {
case BSD_AF_INET:
call_dissector(ip_handle, next_tvb, pinfo, tree);
break;
case BSD_AF_INET6_BSD:
call_dissector(ipv6_handle, next_tvb, pinfo, tree);
break;
default:
call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_prepend_fstr(pinfo->cinfo, COL_INFO, "[%s %s/%u] ",
val_to_str(action, pflog_action_vals, "unknown (%u)"),
ifname,
rulenr);
}
}
void
proto_register_pflog(void)
{
static hf_register_info hf[] = {
{ &hf_pflog_length,
{ "Header Length", "pflog.length", FT_UINT8, BASE_DEC, NULL, 0x0,
"Length of Header", HFILL }},
{ &hf_pflog_af,
{ "Address Family", "pflog.af", FT_UINT32, BASE_DEC, VALS(pflog_af_vals), 0x0,
"Protocol (IPv4 vs IPv6)", HFILL }},
{ &hf_pflog_action,
{ "Action", "pflog.action", FT_UINT8, BASE_DEC, VALS(pflog_action_vals), 0x0,
"Action taken by PF on the packet", HFILL }},
{ &hf_pflog_reason,
{ "Reason", "pflog.reason", FT_UINT8, BASE_DEC, VALS(pflog_reason_vals), 0x0,
"Reason for logging the packet", HFILL }},
{ &hf_pflog_ifname,
{ "Interface", "pflog.ifname", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_ruleset,
{ "Ruleset", "pflog.ruleset", FT_STRING, BASE_NONE, NULL, 0x0,
"Ruleset name in anchor", HFILL }},
{ &hf_pflog_rulenr,
{ "Rule Number", "pflog.rulenr", FT_INT32, BASE_DEC, NULL, 0x0,
"Last matched firewall main ruleset rule number", HFILL }},
{ &hf_pflog_subrulenr,
{ "Sub Rule Number", "pflog.subrulenr", FT_INT32, BASE_DEC, NULL, 0x0,
"Last matched firewall anchored ruleset rule number", HFILL }},
{ &hf_pflog_uid,
{ "UID", "pflog.uid", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_pid,
{ "PID", "pflog.pid", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_rule_uid,
{ "Rule UID", "pflog.rule_uid", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_rule_pid,
{ "Rule PID", "pflog.rule_pid", FT_INT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_rewritten,
{ "Rewritten", "pflog.rewritten", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_pad,
{ "Padding", "pflog.pad", FT_BYTES, BASE_NONE, NULL, 0x0,
"Must be Zero", HFILL }},
{ &hf_pflog_saddr_ipv4,
{ "Source Address", "pflog.saddr", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_daddr_ipv4,
{ "Destination Address", "pflog.daddr", FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_saddr_ipv6,
{ "Source Address", "pflog.saddr", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_daddr_ipv6,
{ "Destination Address", "pflog.daddr", FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_saddr,
{ "Source Address", "pflog.saddr", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_daddr,
{ "Destination Address", "pflog.daddr", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_sport,
{ "Source Port", "pflog.sport", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_dport,
{ "Destination Port", "pflog.dport", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_pflog_dir,
{ "Direction", "pflog.dir", FT_UINT8, BASE_DEC, VALS(pflog_dir_vals), 0x0,
"Direction of packet in stack (inbound versus outbound)", HFILL }},
};
static gint *ett[] = { &ett_pflog };
proto_pflog = proto_register_protocol("OpenBSD Packet Filter log file",
"PFLOG", "pflog");
proto_register_field_array(proto_pflog, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pflog(void)
{
dissector_handle_t pflog_handle;
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
data_handle = find_dissector("data");
pflog_handle = create_dissector_handle(dissect_pflog, proto_pflog);
dissector_add_uint("wtap_encap", WTAP_ENCAP_PFLOG, pflog_handle);
}
static int
dissect_old_pflog(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tvbuff_t *next_tvb;
proto_tree *pflog_tree = NULL;
proto_item *ti = NULL;
guint32 af;
guint8 *ifname;
guint16 rnr, action;
gint offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PFLOG-OLD");
if (tree) {
ti = proto_tree_add_item(tree, proto_old_pflog, tvb, 0, 0, ENC_NA);
pflog_tree = proto_item_add_subtree(ti, ett_pflog);
proto_tree_add_item(pflog_tree, hf_old_pflog_af, tvb, offset, 4, ENC_BIG_ENDIAN);
}
af = tvb_get_ntohl(tvb, offset);
offset +=4;
if (tree) {
proto_tree_add_item(pflog_tree, hf_old_pflog_ifname, tvb, offset, 16, ENC_ASCII|ENC_NA);
}
ifname = tvb_get_ephemeral_string(tvb, offset, 16);
offset +=16;
if (tree) {
proto_tree_add_item(pflog_tree, hf_old_pflog_rnr, tvb, offset, 2, ENC_BIG_ENDIAN);
}
rnr = tvb_get_ntohs(tvb, offset);
offset +=2;
if (tree) {
proto_tree_add_item(pflog_tree, hf_old_pflog_reason, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset +=2;
if (tree) {
proto_tree_add_item(pflog_tree, hf_old_pflog_action, tvb, offset, 2, ENC_BIG_ENDIAN);
}
action = tvb_get_ntohs(tvb, offset);
offset +=2;
if (tree) {
proto_tree_add_item(pflog_tree, hf_old_pflog_dir, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset +=2;
if (tree) {
proto_item_set_text(ti, "PF Log (pre 3.4) %s %s on %s by rule %d",
val_to_str(af, pflog_af_vals, "unknown (%u)"),
val_to_str(action, pflog_action_vals, "unknown (%u)"),
ifname,
rnr);
proto_item_set_len(ti, offset);
}
next_tvb = tvb_new_subset_remaining(tvb, offset);
switch (af) {
case BSD_AF_INET:
offset += call_dissector(ip_handle, next_tvb, pinfo, tree);
break;
case BSD_AF_INET6_BSD:
offset += call_dissector(ipv6_handle, next_tvb, pinfo, tree);
break;
default:
offset += call_dissector(data_handle, next_tvb, pinfo, tree);
break;
}
if (check_col(pinfo->cinfo, COL_INFO)) {
col_prepend_fstr(pinfo->cinfo, COL_INFO, "[%s %s/#%d] ",
val_to_str(action, pflog_action_vals, "unknown (%u)"),
ifname,
rnr);
}
return offset;
}
void
proto_register_old_pflog(void)
{
static hf_register_info hf[] = {
{ &hf_old_pflog_af,
{ "Address Family", "pflog.af", FT_UINT32, BASE_DEC, VALS(pflog_af_vals), 0x0,
"Protocol (IPv4 vs IPv6)", HFILL }},
{ &hf_old_pflog_ifname,
{ "Interface", "pflog.ifname", FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_old_pflog_rnr,
{ "Rule Number", "pflog.rnr", FT_INT16, BASE_DEC, NULL, 0x0,
"Last matched firewall rule number", HFILL }},
{ &hf_old_pflog_reason,
{ "Reason", "pflog.reason", FT_UINT16, BASE_DEC, VALS(pflog_reason_vals), 0x0,
"Reason for logging the packet", HFILL }},
{ &hf_old_pflog_action,
{ "Action", "pflog.action", FT_UINT16, BASE_DEC, VALS(pflog_action_vals), 0x0,
"Action taken by PF on the packet", HFILL }},
{ &hf_old_pflog_dir,
{ "Direction", "pflog.dir", FT_UINT16, BASE_DEC, VALS(pflog_old_dir_vals), 0x0,
"Direction of packet in stack (inbound versus outbound)", HFILL }},
};
static gint *ett[] = { &ett_old_pflog };
proto_old_pflog = proto_register_protocol(
"OpenBSD Packet Filter log file, pre 3.4",
"PFLOG-OLD", "pflog-old");
proto_register_field_array(proto_old_pflog, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_old_pflog(void)
{
dissector_handle_t pflog_handle;
ip_handle = find_dissector("ip");
ipv6_handle = find_dissector("ipv6");
data_handle = find_dissector("data");
pflog_handle = new_create_dissector_handle(dissect_old_pflog, proto_old_pflog);
dissector_add_uint("wtap_encap", WTAP_ENCAP_OLD_PFLOG, pflog_handle);
}
