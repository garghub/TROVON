static char*
cmpp_octet_string(proto_tree *tree, tvbuff_t *tvb, gint field, gint offset, gint length)
{
char *display;
display = (char *)tvb_get_string_enc(wmem_packet_scope(), tvb, offset, length, ENC_ASCII);
proto_tree_add_string(tree, field, tvb, offset, length, display);
return display;
}
static char*
cmpp_version(proto_tree *tree, tvbuff_t *tvb, gint field, gint offset)
{
gint8 version, major, minor;
char *strval;
version = tvb_get_guint8(tvb, offset);
minor = version & 0x0F;
major = (version & 0xF0) >> 4;
strval = wmem_strdup_printf(wmem_packet_scope(), "%02u.%02u", major, minor);
proto_tree_add_string(tree, field, tvb, offset, 1, strval);
return strval;
}
static char*
cmpp_timestamp(proto_tree *tree, tvbuff_t *tvb, gint field, gint offset)
{
gint8 month, day, hour, minute, second;
gint32 timevalue;
char *strval;
timevalue = tvb_get_ntohl(tvb, offset);
second = timevalue % 100;
timevalue /= 100;
minute = timevalue % 100;
timevalue /= 100;
hour = timevalue % 100;
timevalue /= 100;
day = timevalue % 100;
month = timevalue / 100;
strval = wmem_strdup_printf(wmem_packet_scope(), "%02u/%02u %02u:%02u:%02u", month, day,
hour, minute, second);
proto_tree_add_string(tree, field, tvb, offset, 4, strval);
return strval;
}
static guint8
cmpp_uint1(proto_tree *tree, tvbuff_t *tvb, gint field, gint offset)
{
guint8 value;
value = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, field, tvb, offset, 1, value);
return value;
}
static guint16
cmpp_uint2(proto_tree *tree, tvbuff_t *tvb, gint field, gint offset)
{
guint16 value;
value = tvb_get_ntohs(tvb, offset);
proto_tree_add_uint(tree, field, tvb, offset, 2, value);
return value;
}
static gint32
cmpp_uint4(proto_tree *tree, tvbuff_t *tvb, gint field, gint offset)
{
gint32 value;
value = tvb_get_ntohl(tvb, offset);
proto_tree_add_uint(tree, field, tvb, offset, 4, value);
return value;
}
static gboolean
cmpp_boolean(proto_tree *tree, tvbuff_t *tvb, gint field, gint offset)
{
gint8 value;
value = tvb_get_guint8(tvb, offset);
proto_tree_add_boolean(tree, field, tvb, offset, 1, value);
if (value == 1)
return TRUE;
return FALSE;
}
static void
cmpp_msg_id(proto_tree *tree, tvbuff_t *tvb, gint field, gint offset)
{
guint8 month,day,hour,minute,second;
guint32 ismg_code;
proto_item *pi;
proto_tree *sub_tree;
char *strval;
pi = proto_tree_add_item(tree, field, tvb, offset, 8, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(pi, ett_msg_id);
month = (tvb_get_guint8(tvb, offset) & 0xF0) >> 4;
day = (tvb_get_ntohs(tvb, offset) & 0x0F80) >> 7;
hour = (tvb_get_guint8(tvb, offset + 1) & 0x7C) >> 2;
minute = (tvb_get_ntohs(tvb, offset + 1) & 0x03F0) >> 4;
second = (tvb_get_ntohs(tvb, offset + 2) & 0x0FC0) >> 6;
strval = wmem_strdup_printf(wmem_packet_scope(), "%02u/%02u %02u:%02u:%02u", month, day,
hour, minute, second);
ismg_code = (tvb_get_ntohl(tvb, offset + 3) & 0x3FFFFF00) >> 16;
proto_tree_add_string(sub_tree, hf_msg_id_timestamp, tvb, offset, 4, strval);
proto_tree_add_uint(sub_tree, hf_msg_id_ismg_code, tvb, offset + 3, 3, ismg_code);
cmpp_uint2(sub_tree, tvb, hf_msg_id_sequence_id, offset + 6);
}
static void
cmpp_connect(proto_tree *tree, tvbuff_t *tvb)
{
int offset;
offset = CMPP_FIX_HEADER_LENGTH;
cmpp_octet_string(tree, tvb, hf_cmpp_connect_Source_Addr, offset, 6);
offset += 6;
proto_tree_add_string(tree, hf_cmpp_connect_AuthenticatorSource, tvb, offset, 16, "MD5 Hash");
offset += 16;
cmpp_version(tree, tvb, hf_cmpp_Version, offset);
offset += 1;
cmpp_timestamp(tree, tvb, hf_cmpp_connect_Timestamp, offset);
}
static void
cmpp_connect_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset;
offset = CMPP_FIX_HEADER_LENGTH;
cmpp_uint4(tree, tvb, hf_cmpp_connect_resp_status, offset);
offset += 4;
proto_tree_add_string(tree, hf_cmpp_connect_resp_AuthenticatorISMG, tvb, offset, 16, "MD5 Hash");
offset += 16;
cmpp_version(tree, tvb, hf_cmpp_Version, offset);
}
static void
cmpp_submit(proto_tree *tree, tvbuff_t *tvb)
{
int offset, i;
guint8 destUsr, msgLen;
offset = CMPP_FIX_HEADER_LENGTH;
cmpp_msg_id(tree, tvb, hf_cmpp_msg_id, offset);
offset += 8;
cmpp_uint1(tree, tvb, hf_cmpp_submit_pk_total, offset);
offset++;
cmpp_uint1(tree, tvb, hf_cmpp_submit_pk_number, offset);
offset++;
cmpp_boolean(tree, tvb, hf_cmpp_submit_Registered_Delivery, offset);
offset++;
cmpp_uint1(tree, tvb, hf_cmpp_submit_Msg_level, offset);
offset++;
cmpp_octet_string(tree, tvb, hf_cmpp_Service_Id, offset, 10);
offset += 10;
cmpp_uint1(tree, tvb, hf_cmpp_submit_Fee_UserType, offset);
offset++;
cmpp_octet_string(tree, tvb, hf_cmpp_submit_Fee_terminal_Id, offset, 32);
offset+=32;
cmpp_boolean(tree, tvb, hf_cmpp_submit_Fee_terminal_type, offset);
offset++;
cmpp_uint1(tree, tvb, hf_cmpp_TP_pId, offset);
offset++;
cmpp_uint1(tree, tvb, hf_cmpp_TP_udhi, offset);
offset++;
cmpp_uint1(tree, tvb, hf_cmpp_Msg_Fmt, offset);
offset++;
cmpp_octet_string(tree, tvb, hf_cmpp_submit_Msg_src, offset, 6);
offset += 6;
cmpp_octet_string(tree, tvb, hf_cmpp_submit_FeeType, offset, 2);
offset += 2;
cmpp_octet_string(tree, tvb, hf_cmpp_submit_FeeCode, offset, 6);
offset += 6;
cmpp_octet_string(tree, tvb, hf_cmpp_submit_Valld_Time, offset, 17);
offset += 17;
cmpp_octet_string(tree, tvb, hf_cmpp_submit_At_Time, offset, 17);
offset += 17;
cmpp_octet_string(tree, tvb, hf_cmpp_submit_Src_Id, offset, 17);
offset += 21;
destUsr = cmpp_uint1(tree, tvb, hf_cmpp_submit_DestUsr_tl, offset);
offset++;
for(i = 0; i < destUsr; i++)
{
cmpp_octet_string(tree, tvb, hf_cmpp_Dest_terminal_Id, offset, 32);
offset += 32;
}
cmpp_boolean(tree, tvb, hf_cmpp_submit_Dest_terminal_type, offset);
offset++;
msgLen = cmpp_uint1(tree, tvb, hf_cmpp_Msg_Length, offset);
offset++;
proto_tree_add_string(tree, hf_cmpp_Msg_Content, tvb, offset, msgLen, "SMS Messages");
offset += msgLen;
cmpp_octet_string(tree, tvb, hf_cmpp_LinkID, offset, 20);
}
static void
cmpp_submit_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset;
offset = CMPP_FIX_HEADER_LENGTH;
cmpp_msg_id(tree, tvb, hf_cmpp_msg_id, offset);
offset += 8;
cmpp_uint4(tree, tvb, hf_cmpp_submit_resp_Result, offset);
}
static void
cmpp_deliver_report(proto_tree *tree, tvbuff_t *tvb, gint field, guint offset)
{
proto_item *pi;
proto_tree *sub_tree;
pi = proto_tree_add_item(tree, field, tvb, offset, CMPP_DELIVER_REPORT_LEN, ENC_BIG_ENDIAN);
sub_tree = proto_item_add_subtree(pi, ett_deliver_report);
cmpp_msg_id(sub_tree, tvb, hf_cmpp_msg_id, offset);
offset += 8;
cmpp_octet_string(sub_tree, tvb, hf_cmpp_deliver_Report_Stat, offset, 7);
offset += 7;
cmpp_octet_string(sub_tree, tvb, hf_cmpp_deliver_Report_Submit_time, offset, 10);
offset += 10;
cmpp_octet_string(sub_tree, tvb, hf_cmpp_deliver_Report_Done_time, offset, 10);
offset += 10;
cmpp_octet_string(sub_tree, tvb, hf_cmpp_Dest_terminal_Id, offset, 32);
offset += 32;
cmpp_uint4(sub_tree, tvb, hf_cmpp_deliver_Report_SMSC_sequence, offset);
}
static void
cmpp_deliver(proto_tree *tree, tvbuff_t *tvb)
{
guint offset, msgLen;
gboolean report;
offset = CMPP_FIX_HEADER_LENGTH;
cmpp_msg_id(tree, tvb, hf_cmpp_msg_id, offset);
offset += 8;
cmpp_octet_string(tree, tvb, hf_cmpp_deliver_Dest_Id, offset, 21);
offset += 21;
cmpp_octet_string(tree, tvb, hf_cmpp_Service_Id, offset, 10);
offset += 10;
cmpp_uint1(tree, tvb, hf_cmpp_TP_pId, offset);
offset++;
cmpp_uint1(tree, tvb, hf_cmpp_TP_udhi, offset);
offset++;
cmpp_uint1(tree, tvb, hf_cmpp_Msg_Fmt, offset);
offset++;
cmpp_octet_string(tree, tvb, hf_cmpp_deliver_Src_terminal_Id, offset, 32);
offset += 32;
cmpp_boolean(tree, tvb, hf_cmpp_deliver_Src_terminal_type, offset);
offset++;
report = cmpp_boolean(tree, tvb, hf_cmpp_deliver_Registered_Delivery, offset);
offset++;
msgLen = cmpp_uint1(tree, tvb, hf_cmpp_Msg_Length, offset);
offset++;
if (report == FALSE)
proto_tree_add_string(tree, hf_cmpp_Msg_Content, tvb, offset, msgLen, "SMS Messages");
else
cmpp_deliver_report(tree, tvb, hf_cmpp_deliver_Report, offset);
offset += msgLen;
cmpp_octet_string(tree, tvb, hf_cmpp_LinkID, offset, 20);
}
static void
cmpp_deliver_resp(proto_tree *tree, tvbuff_t *tvb)
{
int offset;
offset = CMPP_FIX_HEADER_LENGTH;
cmpp_msg_id(tree, tvb, hf_cmpp_msg_id, offset);
offset += 8;
cmpp_uint4(tree, tvb, hf_cmpp_deliver_resp_Result, offset);
}
static int
dissect_cmpp_tcp_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *cmpp_tree;
guint command_id;
guint tvb_len;
guint total_length;
const gchar *command_str;
tvb_len = tvb_captured_length(tvb);
if (tvb_len < CMPP_FIX_HEADER_LENGTH)
return 0;
total_length = tvb_get_ntohl(tvb, 0);
command_id = tvb_get_ntohl(tvb, 4);
if (try_val_to_str(command_id, vals_command_Id) == NULL)
{
return 0;
}
command_str = val_to_str(command_id, vals_command_Id,
"(Unknown CMPP Operation 0x%08X)");
if (tvb_len < total_length)
{
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CMPP");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s. ", command_str);
if (tree)
{
ti = proto_tree_add_item(tree, proto_cmpp, tvb, 0, -1, ENC_NA);
cmpp_tree = proto_item_add_subtree(ti, ett_cmpp);
cmpp_uint4(cmpp_tree, tvb, hf_cmpp_Total_Length, 0);
cmpp_uint4(cmpp_tree, tvb, hf_cmpp_Command_Id, 4);
cmpp_uint4(cmpp_tree, tvb, hf_cmpp_Sequence_Id, 8);
switch(command_id)
{
case CMPP_CONNECT:
cmpp_connect(cmpp_tree, tvb);
break;
case CMPP_CONNECT_RESP:
cmpp_connect_resp(cmpp_tree, tvb);
break;
case CMPP_TERMINATE:
case CMPP_TERMINATE_RESP:
break;
case CMPP_SUBMIT:
cmpp_submit(cmpp_tree, tvb);
break;
case CMPP_SUBMIT_RESP:
cmpp_submit_resp(cmpp_tree, tvb);
break;
case CMPP_DELIVER:
cmpp_deliver(cmpp_tree, tvb);
break;
case CMPP_DELIVER_RESP:
cmpp_deliver_resp(cmpp_tree, tvb);
break;
default:
break;
}
}
return tvb_reported_length(tvb);
}
static guint
get_cmpp_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohl(tvb, offset);
}
static int
dissect_cmpp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
guint total_length, command_id, tvb_len;
tvb_len = tvb_captured_length(tvb);
if (tvb_len < CMPP_FIX_HEADER_LENGTH)
return 0;
total_length = tvb_get_ntohl(tvb, 0);
command_id = tvb_get_ntohl(tvb, 4);
if (total_length < CMPP_FIX_HEADER_LENGTH || total_length > 1000)
return 0;
if (try_val_to_str(command_id, vals_command_Id) == NULL)
return 0;
col_clear(pinfo->cinfo, COL_INFO);
tcp_dissect_pdus(tvb, pinfo, tree, cmpp_desegment, CMPP_FIX_HEADER_LENGTH,
get_cmpp_pdu_len, dissect_cmpp_tcp_pdu, data);
return tvb_reported_length(tvb);
}
void
proto_register_cmpp(void) {
static hf_register_info hf[] = {
{ &hf_cmpp_Total_Length,
{ "Total Length", "cmpp.Total_Length",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Total length of the CMPP PDU.",
HFILL }
},
{ &hf_cmpp_Command_Id,
{ "Command Id", "cmpp.Command_Id",
FT_UINT32, BASE_HEX, VALS(vals_command_Id), 0x00,
"Command Id of the CMPP messages",
HFILL }
},
{ &hf_cmpp_Sequence_Id,
{ "Sequence Id", "cmpp.Sequence_Id",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Sequence Id of the CMPP messages",
HFILL }
},
{ &hf_cmpp_connect_Source_Addr,
{ "Source Addr", "cmpp.connect.Source_Addr",
FT_STRING, BASE_NONE, NULL, 0x00,
"Source Address, the SP_Id",
HFILL }
},
{ &hf_cmpp_connect_AuthenticatorSource,
{ "Authenticator Source", "cmpp.connect.AuthenticatorSource",
FT_STRING, BASE_NONE, NULL, 0x00,
"Authenticator source, MD5(Source_addr + 9 zero + shared secret + timestamp)",
HFILL }
},
{ &hf_cmpp_Version,
{ "Version", "cmpp.Version",
FT_STRING, BASE_NONE, NULL, 0x00,
"CMPP Version",
HFILL }
},
{ &hf_cmpp_connect_Timestamp,
{ "Timestamp", "cmpp.connect.Timestamp",
FT_STRING, BASE_NONE, NULL, 0x00,
"Timestamp MM/DD HH:MM:SS",
HFILL }
},
{ &hf_cmpp_connect_resp_status,
{ "Connect Response Status", "cmpp.connect_resp.Status",
FT_UINT32, BASE_DEC, VALS(vals_connect_resp_status), 0x00,
"Response Status, Value higher then 4 means other error",
HFILL }
},
{ &hf_cmpp_connect_resp_AuthenticatorISMG,
{ "SIMG Authenticate result", "cmpp.connect_resp.AuthenticatorISMG",
FT_STRING, BASE_NONE, NULL, 0x00,
"Authenticator result, MD5(Status + AuthenticatorSource + shared secret)",
HFILL }
},
{ &hf_cmpp_msg_id,
{ "Msg_Id", "cmpp.Msg_Id",
FT_UINT64, BASE_HEX, NULL, 0x00,
"Message ID",
HFILL }
},
{ &hf_cmpp_submit_pk_total,
{ "Number of Part", "cmpp.submit.Pk_total",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Total number of parts of the message with the same Msg_Id, start from 1",
HFILL }
},
{ &hf_cmpp_submit_pk_number,
{ "Part Number", "cmpp.submit.Pk_number",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Part number of the message with the same Msg_Id, start from 1",
HFILL }
},
{ &hf_msg_id_timestamp,
{ "Timestamp", "cmpp.Msg_Id.timestamp",
FT_STRING, BASE_NONE, NULL, 0x00,
"Timestamp MM/DD HH:MM:SS Bit 64 ~ 39",
HFILL }
},
{ &hf_msg_id_ismg_code,
{ "ISMG Code", "cmpp.Msg_Id.ismg_code",
FT_UINT32, BASE_DEC, NULL, 0x00,
"ISMG Code, bit 38 ~ 17",
HFILL }
},
{ &hf_msg_id_sequence_id,
{ "Msg_Id sequence Id", "cmpp.Msg_Id.sequence_id",
FT_UINT16, BASE_DEC, NULL, 0x00,
"Msg_Id sequence Id, bit 16 ~ 1",
HFILL }
},
{ &hf_cmpp_submit_Registered_Delivery,
{ "Registered Delivery", "cmpp.submit.Registered_Delivery",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Registered Delivery flag",
HFILL }
},
{ &hf_cmpp_submit_Msg_level,
{ "Message Level", "cmpp.submit.Msg_level",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL,
HFILL }
},
{ &hf_cmpp_Service_Id,
{ "Service ID", "cmpp.Servicd_Id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Service ID, a mix of characters, numbers and symbol",
HFILL }
},
{ &hf_cmpp_submit_Fee_UserType,
{ "Charging Informations", "cmpp.submit.Fee_UserType",
FT_UINT8, BASE_DEC, VALS(vals_submit_Fee_UserType), 0x00,
"Charging Informations, if value is 3, this field will not be used",
HFILL }
},
{ &hf_cmpp_submit_Fee_terminal_Id,
{ "Fee Terminal ID", "cmpp.submit.Fee_terminal_Id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Fee Terminal ID, Valid only when Fee_UserType is 3",
HFILL }
},
{ &hf_cmpp_submit_Fee_terminal_type,
{ "Fake Fee Terminal", "cmpp.submit.Fee_terminal_type",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fee terminal type, 0 is real, 1 is fake",
HFILL }
},
{ &hf_cmpp_TP_pId,
{ "TP pId", "cmpp.TP_pId",
FT_UINT8, BASE_DEC, NULL, 0x00,
"GSM TP pId Field",
HFILL }
},
{ &hf_cmpp_TP_udhi,
{ "TP udhi", "cmpp.TP_udhi",
FT_UINT8, BASE_DEC, NULL, 0x00,
"GSM TP udhi field",
HFILL }
},
{ &hf_cmpp_Msg_Fmt,
{ "Message Format", "cmpp.Msg_Fmt",
FT_UINT8, BASE_DEC, VALS(vals_Msg_Fmt), 0x00,
NULL,
HFILL }
},
{ &hf_cmpp_submit_Msg_src,
{ "Message Source SP_Id", "cmpp.submit.Msg_src",
FT_STRING, BASE_NONE, NULL, 0x00,
"Message source SP ID",
HFILL }
},
{ &hf_cmpp_submit_FeeType,
{ "Fee Type", "cmpp.submit.FeeType",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL,
HFILL }
},
{ &hf_cmpp_submit_FeeCode,
{ "Fee Code", "cmpp.submit.FeeCode",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL,
HFILL }
},
{ &hf_cmpp_submit_Valld_Time,
{ "Valid time", "cmpp.submit.Valld_Time",
FT_STRING, BASE_NONE, NULL, 0x00,
"Message Valid Time, format follow SMPP 3.3",
HFILL }
},
{ &hf_cmpp_submit_At_Time,
{ "Send time", "cmpp.submit.At_time",
FT_STRING, BASE_NONE, NULL, 0x00,
"Message send time, format following SMPP 3.3",
HFILL }
},
{ &hf_cmpp_submit_Src_Id,
{ "Source ID", "cmpp.submit.Src_Id",
FT_STRING, BASE_NONE, NULL, 0x00,
"This value matches SMPP submit_sm source_addr field",
HFILL }
},
{ &hf_cmpp_submit_DestUsr_tl,
{ "Destination Address Count", "cmpp.submit.DestUsr_tl",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Number of destination address, must smaller then 100",
HFILL }
},
{ &hf_cmpp_Dest_terminal_Id,
{ "Destination Address", "cmpp.Dest_terminal_Id",
FT_STRING, BASE_NONE, NULL, 0x00,
"MSISDN number which receive the SMS",
HFILL }
},
{ &hf_cmpp_submit_Dest_terminal_type,
{ "Fake Destination Terminal", "cmpp.submit.Dest_terminal_type",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"destination terminal type, 0 is real, 1 is fake",
HFILL }
},
{ &hf_cmpp_Msg_Length,
{ "Message length", "cmpp.Msg_Length",
FT_UINT8, BASE_DEC, NULL, 0x00,
"SMS Message length, ASCII must be <= 160 bytes, other must be <= 140 bytes",
HFILL }
},
{ &hf_cmpp_Msg_Content,
{ "Message Content", "cmpp.Msg_Content",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL,
HFILL }
},
{ &hf_cmpp_LinkID,
{ "Link ID", "cmpp.LinkID",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL,
HFILL }
},
{ &hf_cmpp_submit_resp_Result,
{ "Result", "cmpp.submit_resp.Result",
FT_UINT32, BASE_DEC, VALS(vals_Submit_Resp_Result), 0x00,
"Submit Result",
HFILL }
},
{ &hf_cmpp_deliver_Dest_Id,
{ "Destination ID", "cmpp.deliver.Dest_Id",
FT_STRING, BASE_NONE, NULL, 0x00,
"SP Service ID or server number",
HFILL }
},
{ &hf_cmpp_deliver_Src_terminal_Id,
{ "Src_terminal_Id", "cmpp.deliver.Src_terminal_Id",
FT_STRING, BASE_NONE, NULL, 0x00,
"Source MSISDN number, if it is deliver report, this will be the CMPP_SUBMIT destination number",
HFILL }
},
{ &hf_cmpp_deliver_Src_terminal_type,
{ "Fake source terminal type", "cmpp.deliver.Src_terminal_type",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Type of the source terminal, can be 0 (real) or 1 (fake)",
HFILL }
},
{ &hf_cmpp_deliver_Registered_Delivery,
{ "Deliver Report", "cmpp.deliver.Registered_Delivery",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"The message is a deliver report if this value = 1",
HFILL }
},
{ &hf_cmpp_deliver_Report,
{ "Detail Deliver Report", "cmpp.deliver.Report",
FT_NONE, BASE_NONE, NULL, 0x00,
"The detail report",
HFILL }
},
{ &hf_cmpp_deliver_Report_Stat,
{ "Deliver Status", "cmpp.deliver.Report.Status",
FT_STRING, BASE_NONE, NULL, 0x00,
NULL,
HFILL }
},
{ &hf_cmpp_deliver_Report_Submit_time,
{ "Submit_time", "cmpp.deliver.Report.Submit_time",
FT_STRING, BASE_NONE, NULL, 0x00,
"Format YYMMDDHHMM",
HFILL }
},
{ &hf_cmpp_deliver_Report_Done_time,
{ "Done_time", "cmpp.deliver.Report.Done_time",
FT_STRING, BASE_NONE, NULL, 0x00,
"Format YYMMDDHHMM",
HFILL }
},
{ &hf_cmpp_deliver_Report_SMSC_sequence,
{ "SMSC_sequence", "cmpp.Report.SMSC_sequence",
FT_UINT32, BASE_DEC, NULL, 0x00,
"Sequence number",
HFILL }
},
{ &hf_cmpp_deliver_resp_Result,
{ "Result", "cmpp.deliver_resp.Result",
FT_UINT32, BASE_DEC, VALS(vals_Deliver_Resp_Result), 0x00,
"Deliver Result",
HFILL }
}
};
static gint *ett[] = {
&ett_cmpp,
&ett_msg_id,
&ett_deliver_report,
};
proto_cmpp = proto_register_protocol("China Mobile Point to Point Protocol",
"CMPP", "cmpp");
proto_register_field_array(proto_cmpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_cmpp(void)
{
dissector_handle_t cmpp_handle;
cmpp_handle = new_create_dissector_handle(dissect_cmpp, proto_cmpp);
dissector_add_uint("tcp.port", CMPP_SP_LONG_PORT, cmpp_handle);
dissector_add_uint("tcp.port", CMPP_SP_SHORT_PORT, cmpp_handle);
dissector_add_uint("tcp.port", CMPP_ISMG_LONG_PORT, cmpp_handle);
dissector_add_uint("tcp.port", CMPP_ISMG_SHORT_PORT, cmpp_handle);
}
