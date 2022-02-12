static void
hiqnet_display_vdobjectaddr(proto_tree *hiqnet_tree, int hf_hiqnet, tvbuff_t *tvb, gint offset) {
proto_tree_add_bytes_format_value(hiqnet_tree, hf_hiqnet, tvb, offset, 4, NULL,
"%u.%u.%u.%u",
tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1),
tvb_get_guint8(tvb, offset + 2),
tvb_get_guint8(tvb, offset + 3));
}
static gint
hiqnet_display_tcpipnetinfo(proto_tree *hiqnet_payload_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_macaddr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_dhcp, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_ipaddr, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subnetmsk, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_gateway, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static gint
hiqnet_display_rs232netinfo(proto_tree *hiqnet_payload_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_comid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_baudrate, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_parity, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_stopbits, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_databits, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_flowcontrol, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
return offset;
}
static gint
hiqnet_display_netinfo(proto_tree *hiqnet_payload_tree, tvbuff_t *tvb, gint offset) {
guint netid = 0;
netid = tvb_get_guint8(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_netid, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (netid == HIQNET_TCPIP_NET) {
offset = hiqnet_display_tcpipnetinfo(hiqnet_payload_tree, tvb, offset);
}
if (netid == HIQNET_RS232_NET) {
offset = hiqnet_display_rs232netinfo(hiqnet_payload_tree, tvb, offset);
}
return offset;
}
static gint
hiqnet_display_sernum(proto_tree *hiqnet_payload_tree, tvbuff_t *tvb, gint offset) {
gint str_len;
str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_sernumlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_sernum, tvb, offset, str_len, ENC_NA);
offset += str_len;
return offset;
}
static gint
hiqnet_display_paramsub(proto_tree *hiqnet_payload_tree, tvbuff_t *tvb, gint offset) {
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_pubparmid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subaddr, tvb, offset, 6, ENC_NA);
offset += 6;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subparmid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_reserved0, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_reserved1, tvb, offset, 2, ENC_NA);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_sensrate, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static gint
hiqnet_display_data(proto_tree *hiqnet_payload_tree, tvbuff_t *tvb, gint offset) {
guint8 datatype = 0;
gint datalen;
datatype = tvb_get_guint8(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_datatype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
datalen = hiqnet_datasize_per_type[datatype];
if (datalen < 0) {
datalen = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_datalen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (datatype == 9) {
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_string, tvb, offset, datalen, ENC_UCS_2);
} else {
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_value, tvb, offset, datalen, ENC_NA);
}
offset += datalen;
return offset;
}
static int
dissect_hiqnet_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
guint8 headerlen = 0;
guint32 messagelen = 0;
guint16 srcdev = 0;
guint8 srcvdaddr = 0;
guint8 srcob0addr = 0;
guint8 srcob1addr = 0;
guint8 srcob2addr = 0;
guint16 dstdev = 0;
guint8 dstvdaddr = 0;
guint8 dstob0addr = 0;
guint8 dstob1addr = 0;
guint8 dstob2addr = 0;
guint16 messageid = 0;
guint16 flags = 0;
guint16 paramcount = 0;
guint16 subcount = 0;
guint16 attrcount = 0;
gint str_len = 0;
guint16 vdscount = 0;
guint16 eventscount = 0;
guint16 objcount = 0;
guint16 ifacecount = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HiQnet");
col_clear(pinfo->cinfo,COL_INFO);
srcdev = tvb_get_ntohs(tvb, 6);
srcvdaddr = tvb_get_guint8(tvb, 8);
srcob0addr = tvb_get_guint8(tvb, 9);
srcob1addr = tvb_get_guint8(tvb, 10);
srcob2addr = tvb_get_guint8(tvb, 11);
dstdev = tvb_get_ntohs(tvb, 12);
dstvdaddr = tvb_get_guint8(tvb, 14);
dstob0addr = tvb_get_guint8(tvb, 15);
dstob1addr = tvb_get_guint8(tvb, 16);
dstob2addr = tvb_get_guint8(tvb, 17);
messageid = tvb_get_ntohs(tvb, 18);
col_add_fstr(pinfo->cinfo, COL_INFO, "Msg: %s, Src: %u.%u.%u.%u.%u, Dst: %u.%u.%u.%u.%u",
val_to_str(messageid, messageidnames, "Unknown (0x%04x)"),
srcdev, srcvdaddr, srcob0addr, srcob1addr, srcob2addr,
dstdev, dstvdaddr, dstob0addr, dstob1addr, dstob2addr);
if (tree) {
proto_item *ti = NULL;
proto_item *item = NULL;
proto_tree *hiqnet_tree = NULL;
proto_tree *hiqnet_header_tree = NULL;
proto_tree *hiqnet_session_tree = NULL;
proto_tree *hiqnet_error_tree = NULL;
proto_tree *hiqnet_multipart_tree = NULL;
proto_tree *hiqnet_payload_tree = NULL;
proto_tree *hiqnet_parameter_tree = NULL;
proto_tree *hiqnet_attribute_tree = NULL;
proto_tree *hiqnet_vds_tree = NULL;
proto_tree *hiqnet_event_tree = NULL;
proto_tree *hiqnet_subscription_tree = NULL;
proto_tree *hiqnet_object_tree = NULL;
proto_tree *hiqnet_ifaces_tree = NULL;
gint offset = 0;
messagelen = tvb_get_ntohl(tvb, 2);
ti = proto_tree_add_item(tree, proto_hiqnet, tvb, 0, messagelen, ENC_NA);
proto_item_append_text(ti, ", Msg: %s",
val_to_str(messageid, messageidnames, "Unknown (0x%04x)"));
proto_item_append_text(ti, ", Src %u.%u.%u.%u.%u",
srcdev, srcvdaddr, srcob0addr, srcob1addr, srcob2addr);
proto_item_append_text(ti, ", Dst: %u.%u.%u.%u.%u",
dstdev, dstvdaddr, dstob0addr, dstob1addr, dstob2addr);
hiqnet_tree = proto_item_add_subtree(ti, ett_hiqnet);
headerlen = tvb_get_guint8(tvb, 1);
hiqnet_header_tree = proto_tree_add_subtree(hiqnet_tree, tvb, 0, headerlen, ett_hiqnet, NULL, "Header");
proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_version, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_headerlen, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_messagelen, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_sourcedev, tvb, offset, 2, ENC_BIG_ENDIAN);
item = proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_devaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
offset += 2;
hiqnet_display_vdobjectaddr(hiqnet_header_tree, hf_hiqnet_sourceaddr, tvb, offset);
offset += 4;
proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_destdev, tvb, offset, 2, ENC_BIG_ENDIAN);
item = proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_devaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
PROTO_ITEM_SET_HIDDEN(item);
offset += 2;
hiqnet_display_vdobjectaddr(hiqnet_header_tree, hf_hiqnet_destaddr, tvb, offset);
offset += 4;
proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_messageid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
flags = tvb_get_ntohs(tvb, offset);
proto_tree_add_bitmask(hiqnet_header_tree, tvb, offset, hf_hiqnet_flags,
ett_hiqnet_flags, hiqnet_flag_fields, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_hopcnt, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_header_tree, hf_hiqnet_seqnum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (flags & HIQNET_ERROR_FLAG) {
hiqnet_error_tree = proto_tree_add_subtree(hiqnet_header_tree, tvb, offset, 2, ett_hiqnet, NULL, "Error");
proto_tree_add_item(hiqnet_error_tree, hf_hiqnet_errcode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_error_tree, hf_hiqnet_errstr, tvb, offset, headerlen - offset, ENC_UCS_2);
}
if (flags & HIQNET_MULTIPART_FLAG) {
hiqnet_multipart_tree = proto_tree_add_subtree(hiqnet_header_tree, tvb, offset, 2, ett_hiqnet, NULL, "Multi-part");
proto_tree_add_item(hiqnet_multipart_tree, hf_hiqnet_startseqno, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_multipart_tree, hf_hiqnet_rembytes, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (flags & HIQNET_SESSION_NUMBER_FLAG) {
hiqnet_session_tree = proto_tree_add_subtree(hiqnet_header_tree, tvb, offset, 2, ett_hiqnet, NULL, "Session");
proto_tree_add_item(hiqnet_session_tree, hf_hiqnet_sessnum, tvb, offset, 2, ENC_BIG_ENDIAN);
}
offset = headerlen;
hiqnet_payload_tree = proto_tree_add_subtree(
hiqnet_tree, tvb, offset, messagelen - headerlen, ett_hiqnet, NULL, "Payload");
switch(messageid) {
case HIQNET_DISCOINFO_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_devaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_cost, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
offset = hiqnet_display_sernum(hiqnet_payload_tree, tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_maxmsgsize, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_keepaliveperiod, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hiqnet_display_netinfo(hiqnet_payload_tree, tvb, offset);
break;
case HIQNET_HELLO_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_sessnum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(hiqnet_payload_tree, tvb, offset, hf_hiqnet_flagmask,
ett_hiqnet_flags, hiqnet_flag_fields, ENC_BIG_ENDIAN);
break;
case HIQNET_MULTPARMGET_MSG :
paramcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_paramcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (paramcount > 0) {
hiqnet_parameter_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Parameter");
proto_tree_add_item(hiqnet_parameter_tree, hf_hiqnet_paramid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (flags & HIQNET_INFO_FLAG) {
offset = hiqnet_display_data(hiqnet_parameter_tree, tvb, offset);
}
paramcount -= 1;
}
break;
case HIQNET_MULTPARMSET_MSG :
paramcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_paramcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (paramcount > 0) {
hiqnet_parameter_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Parameter");
proto_tree_add_item(hiqnet_parameter_tree, hf_hiqnet_paramid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = hiqnet_display_data(hiqnet_parameter_tree, tvb, offset);
paramcount -= 1;
}
break;
case HIQNET_PARMSUBALL_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_devaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hiqnet_display_vdobjectaddr(hiqnet_payload_tree, hf_hiqnet_vdobject, tvb, offset);
offset += 4;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_sensrate, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subflags, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case HIQNET_PARMUNSUBALL_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_devaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hiqnet_display_vdobjectaddr(hiqnet_payload_tree, hf_hiqnet_vdobject, tvb, offset);
offset += 4;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subtype, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case HIQNET_MULTPARMSUB_MSG :
subcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (subcount > 0) {
hiqnet_subscription_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Subscription");
offset = hiqnet_display_paramsub(hiqnet_subscription_tree, tvb, offset);
subcount -= 1;
}
break;
case HIQNET_GOODBYE_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_devaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case HIQNET_GETATTR_MSG :
attrcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_attrcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (flags & HIQNET_INFO_FLAG) {
while (attrcount > 0) {
hiqnet_attribute_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Attribute");
proto_tree_add_item(hiqnet_attribute_tree, hf_hiqnet_attrid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = hiqnet_display_data(hiqnet_attribute_tree, tvb, offset);
attrcount -= 1;
}
} else {
while (attrcount > 0) {
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_attrid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
attrcount -= 1;
}
}
break;
case HIQNET_GETVDLIST_MSG :
str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_strlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_wrkgrppath, tvb, offset, str_len, ENC_UCS_2);
offset += str_len;
if (flags & HIQNET_INFO_FLAG) {
vdscount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_numvds, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (vdscount > 0) {
hiqnet_vds_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Virtual Devices");
proto_tree_add_item(hiqnet_vds_tree, hf_hiqnet_vdaddr, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_vds_tree, hf_hiqnet_vdclassid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
vdscount -= 1;
}
}
break;
case HIQNET_STORE_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_stract, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_strnum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_strlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_wrkgrppath, tvb, offset, str_len, ENC_UCS_2);
offset += str_len;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case HIQNET_RECALL_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_recact, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_recnum, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_strlen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_wrkgrppath, tvb, offset, str_len, ENC_UCS_2);
offset += str_len;
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_scope, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case HIQNET_LOCATE_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_time, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hiqnet_display_sernum(hiqnet_payload_tree, tvb, offset);
break;
case HIQNET_SUBEVTLOGMSGS_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_maxdatasize, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_bitmask(hiqnet_payload_tree, tvb, offset, hf_hiqnet_catfilter,
ett_hiqnet_cats, hiqnet_cat_fields, ENC_BIG_ENDIAN);
break;
case HIQNET_UNSUBEVTLOGMSGS_MSG :
proto_tree_add_bitmask(hiqnet_payload_tree, tvb, offset, hf_hiqnet_catfilter,
ett_hiqnet_cats, hiqnet_cat_fields, ENC_BIG_ENDIAN);
break;
case HIQNET_REQEVTLOG_MSG :
if (flags & HIQNET_INFO_FLAG) {
eventscount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_entrieslen, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (eventscount > 0) {
hiqnet_event_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Event");
proto_tree_add_item(hiqnet_event_tree, hf_hiqnet_category, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_event_tree, hf_hiqnet_eventid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_event_tree, hf_hiqnet_priority, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hiqnet_event_tree, hf_hiqnet_eventseqnum, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_event_tree, hf_hiqnet_eventtime, tvb, offset, str_len, ENC_UCS_2);
offset += str_len;
str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_event_tree, hf_hiqnet_eventdate, tvb, offset, str_len, ENC_UCS_2);
offset += str_len;
str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_event_tree, hf_hiqnet_eventinfo, tvb, offset, str_len, ENC_UCS_2);
offset += str_len;
str_len = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(
hiqnet_event_tree, hf_hiqnet_eventadddata, tvb, offset, str_len, ENC_NA);
offset += str_len;
eventscount -= 1;
}
}
break;
case HIQNET_MULTPARMUNSUB_MSG :
subcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (subcount > 0) {
hiqnet_subscription_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Subscription");
proto_tree_add_item(hiqnet_subscription_tree, hf_hiqnet_pubparmid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_subscription_tree, hf_hiqnet_subparmid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
subcount -= 1;
}
break;
case HIQNET_MULTOBJPARMSET_MSG :
objcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_objcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (objcount > 0) {
hiqnet_object_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Object");
hiqnet_display_vdobjectaddr(hiqnet_header_tree, hf_hiqnet_vdobject, tvb, offset);
offset += 4;
paramcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_object_tree, hf_hiqnet_paramcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (paramcount > 0) {
hiqnet_parameter_tree = proto_tree_add_subtree(
hiqnet_object_tree, tvb, offset, -1, ett_hiqnet, NULL, "Parameter");
proto_tree_add_item(hiqnet_parameter_tree, hf_hiqnet_paramid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = hiqnet_display_data(hiqnet_parameter_tree, tvb, offset);
paramcount -= 1;
}
objcount -= 1;
}
break;
case HIQNET_PARMSETPCT_MSG :
paramcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_paramcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (paramcount > 0) {
hiqnet_parameter_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Parameter");
proto_tree_add_item(hiqnet_parameter_tree, hf_hiqnet_paramid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hiqnet_parameter_tree, hf_hiqnet_paramval, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
paramcount -= 1;
}
break;
case HIQNET_PARMSUBPCT_MSG :
subcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_subcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (subcount > 0) {
hiqnet_subscription_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Subscription");
offset = hiqnet_display_paramsub(hiqnet_subscription_tree, tvb, offset);
subcount -= 1;
}
break;
case HIQNET_GETNETINFO_MSG :
offset = hiqnet_display_sernum(hiqnet_payload_tree, tvb, offset);
if (flags & HIQNET_INFO_FLAG) {
ifacecount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_ifacecount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (ifacecount > 0) {
hiqnet_ifaces_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Interface");
proto_tree_add_item(hiqnet_ifaces_tree, hf_hiqnet_maxmsgsize, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = hiqnet_display_netinfo(hiqnet_ifaces_tree, tvb, offset);
ifacecount -= 1;
}
}
break;
case HIQNET_REQADDR_MSG :
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_devaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case HIQNET_SETADDR_MSG :
offset = hiqnet_display_sernum(hiqnet_payload_tree, tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_newdevaddr, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
hiqnet_display_netinfo(hiqnet_payload_tree, tvb, offset);
break;
case HIQNET_SETATTR_MSG :
attrcount = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(hiqnet_payload_tree, hf_hiqnet_attrcount, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
while (attrcount > 0) {
hiqnet_attribute_tree = proto_tree_add_subtree(
hiqnet_payload_tree, tvb, offset, -1, ett_hiqnet, NULL, "Attribute");
proto_tree_add_item(hiqnet_attribute_tree, hf_hiqnet_attrid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = hiqnet_display_data(hiqnet_attribute_tree, tvb, offset);
attrcount -= 1;
}
break;
case HIQNET_RESERVED0_MSG:
case HIQNET_RESERVED1_MSG:
case HIQNET_ADDRUSED_MSG:
break;
default :
break;
}
}
return tvb_reported_length(tvb);
}
static guint
get_hiqnet_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohl(tvb, offset + 2);
}
static int
dissect_hiqnet_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 6,
get_hiqnet_pdu_len, dissect_hiqnet_pdu, data);
return tvb_captured_length(tvb);
}
static int
dissect_hiqnet_udp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
gint offset = 0;
tvbuff_t *next_tvb;
gint offset_before;
guint plen;
guint captured_length;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
plen = get_hiqnet_pdu_len(pinfo, tvb, offset, NULL);
captured_length = tvb_captured_length_remaining(tvb, offset);
if (captured_length > plen)
captured_length = plen;
next_tvb = tvb_new_subset(tvb, offset, captured_length, plen);
dissect_hiqnet_pdu(next_tvb, pinfo, tree, data);
offset_before = offset;
offset += plen;
if (offset <= offset_before)
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_hiqnet(void)
{
static hf_register_info hf[] = {
{ &hf_hiqnet_version,
{ "Version", "hiqnet.version",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_headerlen,
{ "Header length", "hiqnet.hlen",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_messagelen,
{ "Message length", "hiqnet.mlen",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_sourcedev,
{ "Source device", "hiqnet.srcdev",
FT_UINT8, BASE_DEC_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_sourceaddr,
{ "Source address", "hiqnet.srcaddr",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_destdev,
{ "Destination device", "hiqnet.dstdev",
FT_UINT8, BASE_DEC_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_destaddr,
{ "Destination address", "hiqnet.dstaddr",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_messageid,
{ "Message ID", "hiqnet.msgid",
FT_UINT16, BASE_HEX,
VALS(messageidnames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_flags,
{ "Flags", "hiqnet.flags",
FT_UINT16, BASE_HEX,
NULL, HIQNET_FLAGS_MASK,
NULL, HFILL }
},
{ &hf_hiqnet_reqack_flag,
{ "Request Acknowledgement", "hiqnet.flags.reqack",
FT_BOOLEAN, 16,
NULL, HIQNET_REQACK_FLAG,
NULL, HFILL }
},
{ &hf_hiqnet_ack_flag,
{ "Acknowledgement", "hiqnet.flags.ack",
FT_BOOLEAN, 16,
NULL, HIQNET_ACK_FLAG,
NULL, HFILL }
},
{ &hf_hiqnet_info_flag,
{ "Information", "hiqnet.flags.info",
FT_BOOLEAN, 16,
NULL, HIQNET_INFO_FLAG,
NULL, HFILL }
},
{ &hf_hiqnet_error_flag,
{ "Error", "hiqnet.flags.error",
FT_BOOLEAN, 16,
NULL, HIQNET_ERROR_FLAG,
NULL, HFILL }
},
{ &hf_hiqnet_guaranteed_flag,
{ "Guaranteed", "hiqnet.flags.guar",
FT_BOOLEAN, 16,
NULL, HIQNET_GUARANTEED_FLAG,
NULL, HFILL }
},
{ &hf_hiqnet_multipart_flag,
{ "Multipart", "hiqnet.flags.multi",
FT_BOOLEAN, 16,
NULL, HIQNET_MULTIPART_FLAG,
NULL, HFILL }
},
{ &hf_hiqnet_session_number_flag,
{ "Session Number", "hiqnet.flags.session_number",
FT_BOOLEAN, 16,
NULL, HIQNET_SESSION_NUMBER_FLAG,
NULL, HFILL }
},
{ &hf_hiqnet_hopcnt,
{ "Hop count", "hiqnet.hc",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_seqnum,
{ "Sequence number", "hiqnet.seqnum",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_errcode,
{ "Error code", "hiqnet.errcode",
FT_UINT8, BASE_DEC_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_errstr,
{ "Error string", "hiqnet.errstr",
FT_STRINGZ, STR_UNICODE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_startseqno,
{ "Start seq. no.", "hiqnet.ssno",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_rembytes,
{ "Remaining bytes", "hiqnet.rembytes",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_sessnum,
{ "Session number", "hiqnet.sessnum",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_cost,
{ "Cost", "hiqnet.cost",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_sernumlen,
{ "Serial number length", "hiqnet.sernumlen",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_sernum,
{ "Serial number", "hiqnet.sernum",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_maxmsgsize,
{ "Max message size", "hiqnet.maxmsgsize",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_keepaliveperiod,
{ "Keepalive period (ms)", "hiqnet.keepaliveperiod",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_netid,
{ "Network ID", "hiqnet.netid",
FT_UINT8, BASE_DEC,
VALS(networknames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_macaddr,
{ "MAC address", "hiqnet.macaddr",
FT_ETHER, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_dhcp,
{ "DHCP", "hiqnet.dhcp",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_ipaddr,
{ "IP Address", "hiqnet.ipaddr",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_subnetmsk,
{ "Subnet mask", "hiqnet.subnetmsk",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_gateway,
{ "Gateway", "hiqnet.gateway",
FT_IPv4, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_flagmask,
{ "Flag mask", "hiqnet.flagmask",
FT_UINT16, BASE_HEX,
NULL, HIQNET_FLAGS_MASK,
NULL, HFILL }
},
{ &hf_hiqnet_paramcount,
{ "Parameter count", "hiqnet.paramcount",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_paramid,
{ "Parameter ID", "hiqnet.paramid",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_datatype,
{ "Data type", "hiqnet.datatype",
FT_UINT8, BASE_HEX,
VALS(datatypenames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_value,
{ "Value", "hiqnet.value",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_vdobject,
{ "Virtual Device Object", "hiqnet.vdobject",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_subtype,
{ "Subscription Type (New Style)", "hiqnet.subtype",
FT_UINT8, BASE_DEC,
NULL, HIQNET_SUBSCRIPTION_TYPE_MASK,
NULL, HFILL }
},
{ &hf_hiqnet_sensrate,
{ "Sensor Rate (ms)", "hiqnet.sensrate",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_subflags,
{ "Subscription Flags", "hiqnet.subflags",
FT_UINT16, BASE_HEX,
NULL, HIQNET_SUBSCRIPTION_FLAGS_MASK,
NULL, HFILL }
},
{ &hf_hiqnet_subcount,
{ "No of Subscriptions", "hiqnet.subcount",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_pubparmid,
{ "Publisher Parameter ID", "hiqnet.pubparmid",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_subaddr,
{ "Subscriber Address", "hiqnet.subaddr",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_subparmid,
{ "Subscriber Parameter ID", "hiqnet.subparmid",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_reserved0,
{ "Reserved", "hiqnet.reserved0",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_reserved1,
{ "Reserved", "hiqnet.reserved1",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_attrcount,
{ "Attribute count", "hiqnet.attrcount",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_attrid,
{ "Attribute ID", "hiqnet.attrid",
FT_UINT16, BASE_DEC,
VALS(device_attributes_names), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_datalen,
{ "Data length", "hiqnet.datalen",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_string,
{ "String", "hiqnet.string",
FT_STRINGZ, STR_UNICODE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_wrkgrppath,
{ "Workgroup Path", "hiqnet.wrkgrppath",
FT_STRINGZ, STR_UNICODE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_numvds,
{ "Number of Virtual Devices", "hiqnet.numvds",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_vdaddr,
{ "Virtual Device Address", "hiqnet.vdaddr",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_vdclassid,
{ "Virtual Device Class ID", "hiqnet.vdclassid",
FT_UINT16, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_stract,
{ "Store Action", "hiqnet.stract",
FT_UINT8, BASE_DEC,
VALS(actionnames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_strnum,
{ "Store Number", "hiqnet.strnum",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_scope,
{ "Scope", "hiqnet.scope",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_recact,
{ "Recall Action", "hiqnet.rec.act",
FT_UINT8, BASE_DEC,
VALS(actionnames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_recnum,
{ "Recall Number", "hiqnet.recnum",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_strlen,
{ "String length", "hiqnet.strlen",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_time,
{ "Locate time (ms)", "hiqnet.time",
FT_UINT16, BASE_DEC,
VALS(timenames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_maxdatasize,
{ "Maximum Data Size", "hiqnet.maxdatasize",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_catfilter,
{ "Category Filter", "hiqnet.catfilter",
FT_UINT32, BASE_HEX,
NULL, HIQNET_CATEGORIES_MASK,
NULL, HFILL }
},
{ &hf_hiqnet_app_cat,
{ "Application", "hiqnet.appcat",
FT_BOOLEAN, 32,
NULL, HIQNET_APPLICATION_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_conf_cat,
{ "Configuration", "hiqnet.confcat",
FT_BOOLEAN, 32,
NULL, HIQNET_CONF_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_audionet_cat,
{ "Audio Network", "hiqnet.audionetcat",
FT_BOOLEAN, 32,
NULL, HIQNET_AUDIONET_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_ctrlnet_cat,
{ "Control Network", "hiqnet.ctrlnetcat",
FT_BOOLEAN, 32,
NULL, HIQNET_CTRLNET_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_vendnet_cat,
{ "Vendor Network", "hiqnet.vendnetcat",
FT_BOOLEAN, 32,
NULL, HIQNET_VENDNET_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_startup_cat,
{ "Startup", "hiqnet.startupcat",
FT_BOOLEAN, 32,
NULL, HIQNET_STARTUP_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_dsp_cat,
{ "DSP", "hiqnet.dspcat",
FT_BOOLEAN, 32,
NULL, HIQNET_DSP_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_misc_cat,
{ "Miscellenaous", "hiqnet.misccat",
FT_BOOLEAN, 32,
NULL, HIQNET_MISC_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_ctrlog_cat,
{ "Control Logic", "hiqnet.crtllogcat",
FT_BOOLEAN, 32,
NULL, HIQNET_CTRLLOG_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_foreignproto_cat,
{ "Foreign Protocol", "hiqnet.foreignprotocat",
FT_BOOLEAN, 32,
NULL, HIQNET_FOREIGNPROTO_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_digio_cat,
{ "Digital I/O", "hiqnet.digiocat",
FT_BOOLEAN, 32,
NULL, HIQNET_DIGIO_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_ctrlsurf_cat,
{ "Control Surface", "hiqnet.ctrlsurfcat",
FT_BOOLEAN, 32,
NULL, HIQNET_CTRLSURF_CAT,
NULL, HFILL }
},
{ &hf_hiqnet_entrieslen,
{ "Number of Entries", "hiqnet.entrieslen",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_category,
{ "Category", "hiqnet.cat",
FT_UINT16, BASE_HEX,
VALS(eventcategorynames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_eventid,
{ "Event ID", "hiqnet.eventid",
FT_UINT16, BASE_DEC,
VALS(eventidnames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_priority,
{ "Priority", "hiqnet.priority",
FT_UINT8, BASE_DEC,
VALS(prioritynames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_eventseqnum,
{ "Sequence Number", "hiqnet.eventseqnum",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_eventtime,
{ "Time", "hiqnet.eventtime",
FT_STRING, STR_UNICODE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_eventdate,
{ "Date", "hiqnet.eventdate",
FT_STRING, STR_UNICODE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_eventinfo,
{ "Information", "hiqnet.information",
FT_STRING, STR_UNICODE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_eventadddata,
{ "Additional Data", "hiqnet.eventadddata",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_objcount,
{ "Object Count", "hiqnet.objcount",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_paramval,
{ "Parameter Value (%)", "hiqnet.paramval",
FT_INT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_ifacecount,
{ "Interface Count", "hiqnet.ifacecount",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_comid,
{ "Com Port Identifier", "hiqnet.comid",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_baudrate,
{ "Baud Rate", "hiqnet.baudrate",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_parity,
{ "Parity", "hiqnet.parity",
FT_UINT8, BASE_DEC,
VALS(paritynames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_stopbits,
{ "Stop Bits", "hiqnet.stopbits",
FT_UINT8, BASE_DEC,
VALS(stopbitsnames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_databits,
{ "Data Bits", "hiqnet.databits",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_flowcontrol,
{ "Flowcontrol", "hiqnet.flowcontrol",
FT_UINT8, BASE_DEC,
VALS(flowcontrolnames), 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_devaddr,
{ "Device Address", "hiqnet.device",
FT_UINT16, BASE_DEC_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hiqnet_newdevaddr,
{ "New Device Address", "hiqnet.device",
FT_UINT16, BASE_DEC_HEX,
NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_hiqnet,
&ett_hiqnet_flags,
&ett_hiqnet_cats
};
proto_hiqnet = proto_register_protocol (
"Harman HiQnet",
"HiQnet",
"hiqnet"
);
proto_register_field_array(proto_hiqnet, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_hiqnet(void)
{
static dissector_handle_t hiqnet_udp_handle;
static dissector_handle_t hiqnet_tcp_handle;
hiqnet_udp_handle = new_create_dissector_handle(dissect_hiqnet_udp, proto_hiqnet);
hiqnet_tcp_handle = new_create_dissector_handle(dissect_hiqnet_tcp, proto_hiqnet);
dissector_add_uint("udp.port", HIQNET_PORT, hiqnet_udp_handle);
dissector_add_uint("tcp.port", HIQNET_PORT, hiqnet_tcp_handle);
}
