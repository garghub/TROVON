static void _dissect_uaudp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
e_ua_direction direction)
{
gint offset = 0;
guint32 type, length;
guint8 opcode;
proto_item *uaudp_item, *tlv_item, *tlv_len_item;
proto_tree *uaudp_tree, *connect_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "UAUDP");
opcode = tvb_get_guint8(tvb, offset);
offset += 1;
ua_tap_info.opcode = opcode;
ua_tap_info.expseq = 0;
ua_tap_info.sntseq = 0;
col_add_fstr(pinfo->cinfo,
COL_INFO,
"%s",
val_to_str_ext(opcode, &uaudp_opcode_str_ext, "unknown (0x%02x)"));
uaudp_item = proto_tree_add_protocol_format(tree, proto_uaudp, tvb, 0, tvb_reported_length(tvb),
"Universal Alcatel/UDP Encapsulation Protocol, %s",
val_to_str_ext(opcode, &uaudp_opcode_str_ext, "unknown (0x%02x)"));
uaudp_tree = proto_item_add_subtree(uaudp_item, ett_uaudp);
proto_tree_add_uint(uaudp_tree, hf_uaudp_opcode, tvb, 0, 1, opcode);
switch(opcode)
{
case UAUDP_CONNECT:
{
while(tvb_reported_length_remaining(tvb, offset) > 0)
{
type = tvb_get_guint8(tvb, offset+0);
connect_tree = proto_tree_add_subtree(uaudp_tree, tvb, offset, 0, ett_uaudp_tlv, &tlv_item,
val_to_str_ext(type, &uaudp_connect_vals_ext, "Unknown %d"));
proto_tree_add_uint(connect_tree, hf_uaudp_type, tvb, offset, 1, type);
offset++;
tlv_len_item = proto_tree_add_item_ret_uint(connect_tree, hf_uaudp_length, tvb, offset, 1, ENC_NA, &length);
proto_item_set_len(tlv_item, length+2);
offset++;
switch(type)
{
case UAUDP_CONNECT_VERSION:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_version, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_WINDOW_SIZE:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_window_size, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_MTU:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_mtu, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_UDP_LOST:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_udp_lost, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_UDP_LOST_REINIT:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_udp_lost_reinit, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_KEEPALIVE:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_keepalive, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_QOS_IP_TOS:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_qos_ip_tos, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_QOS_8021_VLID:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_qos_8021_vlid, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_QOS_8021_PRI:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_qos_8021_pri, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
case UAUDP_CONNECT_SUPERFAST_CONNECT:
if ((length >= 1) && (length <= 4))
{
proto_tree_add_item(connect_tree, hf_uaudp_superfast_connect, tvb, offset, length, ENC_BIG_ENDIAN);
}
else
{
expert_add_info_format(pinfo, tlv_len_item, &ei_uaudp_tlv_length, "Invalid length %d", length);
}
break;
}
offset += length;
}
break;
}
case UAUDP_NACK:
{
proto_tree_add_item(uaudp_tree,
hf_uaudp_expseq,
tvb,
offset,
2,
ENC_BIG_ENDIAN);
break;
}
case UAUDP_DATA:
{
int datalen;
proto_tree_add_item_ret_uint(uaudp_tree,
hf_uaudp_expseq,
tvb,
offset+0,
2,
ENC_BIG_ENDIAN,
&ua_tap_info.expseq);
proto_tree_add_item_ret_uint(uaudp_tree,
hf_uaudp_sntseq,
tvb,
offset+2,
2,
ENC_BIG_ENDIAN,
&ua_tap_info.sntseq);
offset += 4;
datalen = tvb_reported_length(tvb) - offset;
if (datalen > 0)
{
if (direction == SYS_TO_TERM)
call_dissector(ua_sys_to_term_handle,
tvb_new_subset_length(tvb, offset, datalen),
pinfo,
tree);
else if (direction == TERM_TO_SYS)
call_dissector(ua_term_to_sys_handle,
tvb_new_subset_length(tvb, offset, datalen),
pinfo,
tree);
else {
col_set_str(pinfo->cinfo,
COL_INFO,
"Data - Couldn't resolve direction. Check UAUDP Preferences.");
}
ua_tap_info.expseq = hf_uaudp_expseq;
}
else {
col_set_str(pinfo->cinfo,
COL_INFO,
"Data ACK");
}
break;
}
default:
break;
}
#if 0
tap_queue_packet(uaudp_tap, pinfo, &ua_tap_info);
#endif
}
static int dissect_uaudp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
if (use_sys_ip) {
if (memcmp((pinfo->src).data, &sys_ip, sizeof(sys_ip)) == 0)
{
_dissect_uaudp(tvb, pinfo, tree, SYS_TO_TERM);
return tvb_captured_length(tvb);
}
else if (memcmp((pinfo->dst).data, &sys_ip, sizeof(sys_ip)) == 0)
{
_dissect_uaudp(tvb, pinfo, tree, TERM_TO_SYS);
return tvb_captured_length(tvb);
}
}
if (value_is_in_range(ua_udp_range, pinfo->srcport))
{
_dissect_uaudp(tvb, pinfo, tree, TERM_TO_SYS);
return tvb_captured_length(tvb);
}
else if (value_is_in_range(ua_udp_range, pinfo->destport))
{
_dissect_uaudp(tvb, pinfo, tree, SYS_TO_TERM);
return tvb_captured_length(tvb);
}
_dissect_uaudp(tvb, pinfo, tree, DIR_UNKNOWN);
return tvb_captured_length(tvb);
}
static void
apply_uaudp_prefs(void) {
ua_udp_range = prefs_get_range_value("uaudp", "udp.port");
if (*pref_sys_ip_s) {
use_sys_ip = ws_inet_pton4(pref_sys_ip_s, &sys_ip);
if (!use_sys_ip) {
report_failure("Invalid value for pref uaudp.system_ip: %s",
pref_sys_ip_s);
}
}
}
void proto_register_uaudp(void)
{
module_t *uaudp_module;
static hf_register_info hf_uaudp[] = {
{
&hf_uaudp_opcode,
{
"Opcode",
"uaudp.opcode",
FT_UINT8,
BASE_DEC | BASE_EXT_STRING,
&uaudp_opcode_str_ext,
0x0,
"UA/UDP Opcode",
HFILL
}
},
{
&hf_uaudp_version,
{
"Version",
"uaudp.version",
FT_UINT8,
BASE_DEC,
NULL, 0x0,
"UA/UDP Version",
HFILL
}
},
{
&hf_uaudp_window_size,
{
"Window Size",
"uaudp.window_size",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"UA/UDP Window Size",
HFILL
}
},
{
&hf_uaudp_mtu,
{
"MTU",
"uaudp.mtu",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"UA/UDP MTU",
HFILL
}
},
{
&hf_uaudp_udp_lost,
{
"UDP Lost",
"uaudp.udp_lost",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"UA/UDP Lost",
HFILL
}
},
{
&hf_uaudp_udp_lost_reinit,
{
"UDP lost reinit",
"uaudp.udp_lost_reinit",
FT_UINT8,
BASE_DEC,
NULL, 0x0,
"UA/UDP Lost Re-Init",
HFILL
}
},
{
&hf_uaudp_keepalive,
{
"Keepalive",
"uaudp.keepalive",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"UA/UDP Keepalive",
HFILL
}
},
{
&hf_uaudp_qos_ip_tos,
{
"QoS IP TOS",
"uaudp.qos_ip_tos",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"UA/UDP QoS IP TOS",
HFILL
}
},
{
&hf_uaudp_qos_8021_vlid,
{
"QoS 802.1 VLID",
"uaudp.qos_8021_vlid",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"UA/UDP QoS 802.1 VLID",
HFILL
}
},
{
&hf_uaudp_qos_8021_pri,
{
"QoS 802.1 PRI",
"uaudp.qos_8021_pri",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"UA/UDP QoS 802.1 PRI",
HFILL
}
},
{
&hf_uaudp_superfast_connect,
{
"SuperFast Connect",
"uaudp.superfast_connect",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"UA/UDP SuperFast Connect",
HFILL
}
},
{
&hf_uaudp_expseq,
{
"Sequence Number (expected)",
"uaudp.expseq",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"UA/UDP Expected Sequence Number",
HFILL
}
},
{
&hf_uaudp_sntseq,
{
"Sequence Number (sent)",
"uaudp.sntseq",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"UA/UDP Sent Sequence Number",
HFILL
}
},
{
&hf_uaudp_type,
{
"Type",
"uaudp.type",
FT_UINT8,
BASE_DEC|BASE_EXT_STRING,
&uaudp_connect_vals_ext,
0x0,
NULL,
HFILL
}
},
{
&hf_uaudp_length,
{
"Length",
"uaudp.length",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
};
static gint *ett[] =
{
&ett_uaudp,
&ett_uaudp_tlv,
};
static ei_register_info ei[] = {
{ &ei_uaudp_tlv_length, { "uaudp.tlv_length_invalid", PI_PROTOCOL, PI_WARN, "Invalid length", EXPFILL }},
};
expert_module_t* expert_uaudp;
proto_uaudp = proto_register_protocol("UA/UDP Encapsulation Protocol", "UAUDP", "uaudp");
uaudp_handle = register_dissector("uaudp", dissect_uaudp, proto_uaudp);
#if 0
register_dissector("uaudp_dir_unknown", dissect_uaudp_dir_unknown, proto_uaudp);
register_dissector("uaudp_term_to_serv", dissect_uaudp_term_to_serv, proto_uaudp);
register_dissector("uaudp_serv_to_term", dissect_uaudp_serv_to_term, proto_uaudp);
#endif
proto_register_field_array(proto_uaudp, hf_uaudp, array_length(hf_uaudp));
proto_register_subtree_array(ett, array_length(ett));
expert_uaudp = expert_register_protocol(proto_uaudp);
expert_register_field_array(expert_uaudp, ei, array_length(ei));
#if 0
uaudp_opcode_dissector_table =
register_dissector_table("uaudp.opcode",
"UAUDP opcode",
FT_UINT8,
BASE_DEC);
#endif
uaudp_module = prefs_register_protocol(proto_uaudp, apply_uaudp_prefs);
prefs_register_string_preference(uaudp_module, "system_ip",
"System IP Address (optional)",
"IPv4 address of the DHS3 system."
" (Used only in case of identical source and destination ports)",
&pref_sys_ip_s);
#if 0
uaudp_tap = register_tap("uaudp");*/
#endif
}
void proto_reg_handoff_uaudp(void)
{
ua_sys_to_term_handle = find_dissector_add_dependency("ua_sys_to_term", proto_uaudp);
ua_term_to_sys_handle = find_dissector_add_dependency("ua_term_to_sys", proto_uaudp);
dissector_add_uint_range_with_preference("udp.port", UAUDP_PORT_RANGE, uaudp_handle);
}
