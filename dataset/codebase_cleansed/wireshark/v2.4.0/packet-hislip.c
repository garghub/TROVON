static void
decode_messagepara(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, hislipinfo *data)
{
proto_item * item = NULL;
proto_tree *msgpara_tree;
item = proto_tree_add_item(tree, hf_hislip_messageparameter, tvb, data->offset, 4, ENC_NA);
msgpara_tree = proto_item_add_subtree(item, ett_hislip_msgpara);
switch (data->messagetype)
{
case HISLIP_INITIALIZE:
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_clientproto, tvb, data->offset, 2, ENC_BIG_ENDIAN );
data->offset += 2;
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_vendorID, tvb, data->offset, 2, ENC_BIG_ENDIAN );
data->offset += 2;
break;
case HISLIP_INITIALIZERESPONSE:
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_serverproto, tvb, data->offset, 2, ENC_BIG_ENDIAN );
data->offset += 2;
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_sessionid, tvb, data->offset, 2, ENC_BIG_ENDIAN );
data->offset += 2;
break;
case HISLIP_ASYNCLOCK:
if (data->controlcode)
{
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_timeout, tvb, data->offset, 4, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_messageid, tvb, data->offset, 4, ENC_BIG_ENDIAN);
}
data->offset += 4;
break;
case HISLIP_ASYNCLOCKINFORESPONSE:
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_clients, tvb, data->offset, 4, ENC_BIG_ENDIAN );
data->offset += 4;
break;
case HISLIP_ASYNCINITIALIZE:
data->offset += 2;
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_sessionid, tvb, data->offset, 2, ENC_BIG_ENDIAN);
data->offset += 2;
break;
case HISLIP_ASYNCINITIALIZERESPONSE:
data->offset += 2;
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_vendorID, tvb, data->offset, 2, ENC_BIG_ENDIAN );
data->offset += 2;
break;
case HISLIP_DATA:
case HISLIP_DATAEND:
case HISLIP_TRIGGER:
case HISLIP_INTERRUPTED:
case HISLIP_ASYNCINTERRUPTED:
case HISLIP_ASYNCSTATUSQUERY:
case HISLIP_ASYNCREMOTELOCALCONTROL:
proto_tree_add_item(msgpara_tree, hf_hislip_msgpara_messageid, tvb, data->offset, 4, ENC_BIG_ENDIAN );
proto_item_append_text(data->hislip_item, ", MessageId: 0x%0x", data->messageparameter);
data->offset += 4;
break;
default:
if (data->messageparameter != 0)
{
proto_tree_add_expert(msgpara_tree, pinfo, &ei_msg_not_null, tvb, data->offset, 4);
}
data->offset += 4;
}
}
static void
decode_controlcode(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, hislipinfo *data, guint8 oldcontrolvalue)
{
proto_item * item = NULL;
switch (data->messagetype )
{
case HISLIP_DATA:
case HISLIP_DATAEND:
case HISLIP_TRIGGER:
case HISLIP_ASYNCSTATUSQUERY:
proto_tree_add_item(tree, hf_hislip_controlcode_rmt, tvb, data->offset, 1, ENC_BIG_ENDIAN );
break;
case HISLIP_INITIALIZERESPONSE:
proto_tree_add_item(tree, hf_hislip_controlcode_overlap, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]", val_to_str(data->controlcode, overlap, "Unknown"));
proto_item_append_text(data->hislip_item, ", %s", val_to_str(data->controlcode, overlap, "Unknown"));
break;
case HISLIP_ASYNCLOCK:
item = proto_tree_add_item(tree, hf_hislip_controlcode_asynclock_code, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s", val_to_str(data->controlcode, asynclock_code, "Unknown"));
proto_item_append_text(data->hislip_item, ", %s", val_to_str(data->controlcode, asynclock_code, "Unknown"));
if (data->controlcode != 1)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "]");
break;
}
if (data->payloadlength == 0)
{
proto_item_append_text(item, "[Exclusive]");
col_append_fstr(pinfo->cinfo, COL_INFO, " Exclusive]");
proto_item_append_text(data->hislip_item, " (Exclusive)");
}
else
{
proto_item_append_text(item, "[Shared]");
col_append_fstr(pinfo->cinfo, COL_INFO, " Shared]");
proto_item_append_text(data->hislip_item, " (Shared)");
}
break;
case HISLIP_FATALERROR:
proto_tree_add_item(tree, hf_hislip_fatalerrcode, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]", rval_to_str(data->controlcode, fatalerrortype, "Unknown"));
proto_item_append_text(data->hislip_item, ", %s", rval_to_str(data->controlcode, fatalerrortype, "Unknown"));
break;
case HISLIP_ERROR:
proto_tree_add_item(tree, hf_hislip_nonfatalerrorcode, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]", rval_to_str(data->controlcode, nonfatalerrortype, "Unknown"));
proto_item_append_text(data->hislip_item, ", %s", rval_to_str(data->controlcode, nonfatalerrortype, "Unknown"));
break;
case HISLIP_ASYNCLOCK_RESPONSE:
if (oldcontrolvalue == 1)
{
proto_tree_add_item(tree, hf_hislip_controlcode_asynclockresponse_code_request, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]", val_to_str(data->controlcode, asynclockresponse_code_request, "Unknown"));
proto_item_append_text(data->hislip_item, ", %s", val_to_str(data->controlcode, asynclockresponse_code_request, "Unknown"));
}
else
{
proto_tree_add_item(tree, hf_hislip_controlcode_asynclockresponse_code_release, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]", val_to_str(data->controlcode, asynclockresponse_code_release, "Unknown"));
proto_item_append_text(data->hislip_item, ", %s", val_to_str(data->controlcode, asynclockresponse_code_release, "Unknown"));
}
break;
case HISLIP_ASYNCLOCKINFORESPONSE:
proto_tree_add_item(tree, hf_hislip_controlcode_asynclockinforesponse_code, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]", val_to_str(data->controlcode, asynclockinforesponse_code, "Unknown"));
proto_item_append_text(data->hislip_item, ", %s", val_to_str(data->controlcode, asynclockinforesponse_code, "Unknown"));
break;
case HISLIP_ASYNCREMOTELOCALCONTROL:
item = proto_tree_add_item(tree, hf_hislip_controlcode_asyncremotelocalcontrol_code, tvb, data->offset, 1, ENC_BIG_ENDIAN );
proto_item_append_text(item, " %s", val_to_str(data->controlcode, remotetype, "Unknown"));
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]", val_to_str(data->controlcode, asyncremotelocalcontrol_code, "Unknown"));
proto_item_append_text(data->hislip_item, ", %s", val_to_str(data->controlcode, asyncremotelocalcontrol_code, "Unknown"));
break;
case HISLIP_ASYNCSTATUSRESPONSE:
case HISLIP_ASYNCSERVICEREQUEST:
proto_tree_add_item(tree, hf_hislip_controlcode_stb, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " STB (0x%x)", data->controlcode);
proto_item_append_text(data->hislip_item, ", STB (0x%x)", data->controlcode);
break;
case HISLIP_ASYNCDEVICECLEARACKNOWLEDGE:
case HISLIP_DEVICECLEARCOMPLETE:
case HISLIP_DEVICECLEARACKNOWLEDGE:
proto_tree_add_item(tree, hf_hislip_controlcode_feature_negotiation, tvb, data->offset, 1, ENC_BIG_ENDIAN );
col_append_fstr(pinfo->cinfo, COL_INFO, " [%s]", val_to_str(data->controlcode&0x01, feature_negotiation, "Unknown"));
break;
default:
proto_tree_add_item(tree, hf_hislip_controlcode, tvb, data->offset, 1, ENC_BIG_ENDIAN);
}
data->offset++;
}
static void
decode_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, hislipinfo *data)
{
proto_item * item = NULL;
if (data->payloadlength != 0)
{
guint64 datalength;
gdouble max_message_size;
switch (data->messagetype)
{
case HISLIP_DATA:
case HISLIP_DATAEND:
case HISLIP_INITIALIZE:
datalength = MAX_DATA_SHOW_SIZE;
if (data->payloadlength <= datalength)
datalength = data->payloadlength;
col_append_fstr(pinfo->cinfo, COL_INFO, " %s", tvb_format_text(tvb, data->offset, (guint32)datalength));
proto_tree_add_item(tree, hf_hislip_data, tvb, data->offset, -1, ENC_UTF_8 |ENC_NA);
break;
case HISLIP_ASYNCMAXIMUMMESSAGESIZE:
case HISLIP_ASYNCMAXIMUMMESSAGESIZERESPONSE:
max_message_size = (gdouble)tvb_get_ntoh64(tvb, data->offset);
max_message_size = max_message_size/1048576.0;
item = proto_tree_add_item(tree, hf_hislip_maxmessagesize, tvb, data->offset, 8, ENC_BIG_ENDIAN);
proto_item_append_text(item, " bytes (%.2f Mbytes)", max_message_size);
col_append_fstr(pinfo->cinfo, COL_INFO, " Max Message Size: %.2f Mbytes", max_message_size);
break;
default:
proto_tree_add_item(tree, hf_hislip_data, tvb, data->offset, -1, ENC_UTF_8 | ENC_NA);
}
}
data->offset += (guint32)data->payloadlength;
}
static guint32
search_for_retransmission(wmem_tree_t *pdus, hislipinfo *data, guint32 fnum )
{
hislip_transaction_t *hislip_trans;
hislip_trans = (hislip_transaction_t *)wmem_tree_lookup32_le(pdus, fnum-1);
if (hislip_trans)
{
if (hislip_trans->messagetype == data->messagetype && hislip_trans->rep_frame == 0)
return hislip_trans->req_frame;
}
return 0;
}
static guint8
is_connection_syn_or_asyn(guint8 messagetype)
{
if (messagetype >= HISLIP_ASYNCINTERRUPTED)
{
return HISLIP_ASYNCINITIALIZE;
}
else
{
switch (messagetype)
{
case HISLIP_ASYNCLOCK:
case HISLIP_ASYNCLOCK_RESPONSE:
case HISLIP_ASYNCREMOTELOCALCONTROL:
case HISLIP_ASYNCREMOTELOCALRESPONSE:
return HISLIP_ASYNCINITIALIZE;
default:
return HISLIP_INITIALIZE;
}
}
}
static gint
dissect_hislip_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
conversation_t *conversation;
hislip_conv_info_t *hislip_info;
hislip_transaction_t *hislip_trans;
proto_tree *hislip_tree;
proto_item *it = NULL;
hislipinfo hislip_data;
guint8 oldcontrolvalue = 0;
guint32 frame_number;
hislip_tree = NULL;
conversation = NULL;
hislip_info = NULL;
memset(&hislip_data, 0, sizeof(hislip_data));
col_set_str(pinfo->cinfo, COL_PROTOCOL, PROTO_TAG_HiSLIP);
col_clear(pinfo->cinfo, COL_INFO);
hislip_data.messagetype = tvb_get_guint8(tvb, hislip_data.offset+2);
hislip_data.controlcode = tvb_get_guint8(tvb, hislip_data.offset+3);
hislip_data.messageparameter = tvb_get_ntohl(tvb, hislip_data.offset+4);
hislip_data.payloadlength = tvb_get_ntoh64(tvb, hislip_data.offset+8);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s", rval_to_str(hislip_data.messagetype, messagetypestring, "Unknown"));
if (tree)
{
hislip_data.hislip_item = proto_tree_add_item(tree, proto_hislip, tvb, 0, -1, ENC_NA);
hislip_tree = proto_item_add_subtree(hislip_data.hislip_item, ett_hislip);
}
if (tvb_get_ntohs(tvb, 0) != 0x4853)
{
expert_add_info(pinfo, hislip_data.hislip_item, &ei_wrong_prologue);
}
conversation = find_or_create_conversation(pinfo);
hislip_info = (hislip_conv_info_t *)conversation_get_proto_data(conversation, proto_hislip);
if (!hislip_info)
{
hislip_info = (hislip_conv_info_t *)wmem_alloc(wmem_file_scope(), (sizeof(hislip_conv_info_t)));
hislip_info->connectiontype = is_connection_syn_or_asyn(hislip_data.messagetype);
hislip_info->pdus = wmem_tree_new(wmem_file_scope());
conversation_add_proto_data(conversation, proto_hislip, (void *)hislip_info);
}
if(hislip_info->connectiontype == HISLIP_INITIALIZE)
{
proto_item_append_text(hislip_data.hislip_item, " (Synchron)");
it = proto_tree_add_item(hislip_tree, hf_hislip_syn, tvb, 0, 0, ENC_NA);
}
else
{
proto_item_append_text(hislip_data.hislip_item," (Asynchron)");
it = proto_tree_add_item(hislip_tree, hf_hislip_asyn, tvb, 0, 0, ENC_NA);
}
PROTO_ITEM_SET_GENERATED(it);
switch(hislip_data.messagetype)
{
case HISLIP_ASYNCLOCK:
case HISLIP_ASYNCINITIALIZE:
case HISLIP_ASYNCMAXIMUMMESSAGESIZE:
case HISLIP_INITIALIZE:
case HISLIP_ASYNCSTATUSQUERY:
case HISLIP_ASYNCLOCKINFO:
if(!PINFO_FD_VISITED(pinfo))
{
hislip_trans = (hislip_transaction_t *)wmem_alloc(wmem_file_scope(), sizeof(hislip_transaction_t));
hislip_trans->req_frame = pinfo->num;
hislip_trans->rep_frame = 0;
hislip_trans->messagetype = hislip_data.messagetype;
hislip_trans->controltype = hislip_data.controlcode;
wmem_tree_insert32(hislip_info->pdus, pinfo->num , (void *)hislip_trans);
}
else
{
hislip_trans = (hislip_transaction_t *)wmem_tree_lookup32(hislip_info->pdus, pinfo->num);
}
if(hislip_trans && hislip_trans->rep_frame != 0)
{
it = proto_tree_add_uint(hislip_tree, hf_hislip_response, tvb, 0, 0, hislip_trans->rep_frame);
PROTO_ITEM_SET_GENERATED(it);
}
if((frame_number = search_for_retransmission(hislip_info->pdus, &hislip_data , pinfo->num))!=0)
{
it = proto_tree_add_uint( hislip_tree, hf_hislip_retransmission, tvb, 0, 0, frame_number);
PROTO_ITEM_SET_GENERATED(it);
}
break;
case HISLIP_ASYNCLOCK_RESPONSE:
case HISLIP_ASYNCINITIALIZERESPONSE:
case HISLIP_ASYNCMAXIMUMMESSAGESIZERESPONSE:
case HISLIP_INITIALIZERESPONSE:
case HISLIP_ASYNCSTATUSRESPONSE:
case HISLIP_ASYNCLOCKINFORESPONSE:
hislip_trans = (hislip_transaction_t *) wmem_tree_lookup32_le( hislip_info->pdus, pinfo->num);
if (hislip_trans)
{
hislip_trans->rep_frame = pinfo->num;
oldcontrolvalue = hislip_trans->controltype;
it = proto_tree_add_uint( hislip_tree, hf_hislip_request,tvb, 0, 0, hislip_trans->req_frame);
PROTO_ITEM_SET_GENERATED(it);
}
break;
default:
;
}
hislip_data.offset += 2;
proto_tree_add_item(hislip_tree, hf_hislip_messagetype, tvb, hislip_data.offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(hislip_data.hislip_item, ", %s", rval_to_str(hislip_data.messagetype, messagetypestring, "Unknown"));
hislip_data.offset += 1;
decode_controlcode(tvb, pinfo, hislip_tree, &hislip_data, oldcontrolvalue );
decode_messagepara(tvb, pinfo, hislip_tree, &hislip_data);
proto_tree_add_item(hislip_tree, hf_hislip_payloadlength, tvb, hislip_data.offset, 8, ENC_BIG_ENDIAN);
hislip_data.offset += 8;
decode_data(tvb, pinfo, hislip_tree, &hislip_data );
return tvb_captured_length(tvb);
}
static guint
get_hislip_message_len(packet_info *pinfo _U_, tvbuff_t *tvb,
int offset, void *data _U_)
{
guint64 length;
length = tvb_get_ntoh64(tvb, offset+8);
length += FRAME_HEADER_LEN;
return (guint32)length;
}
static gint
dissect_hislip(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, FRAME_HEADER_LEN,
get_hislip_message_len, dissect_hislip_message, data);
return tvb_captured_length(tvb);
}
static gboolean
dissect_hislip_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
if (tvb_captured_length(tvb) < FRAME_HEADER_LEN)
return FALSE;
if (tvb_get_ntohs(tvb, 0) != 0x4853)
return FALSE;
dissect_hislip(tvb, pinfo, tree, data);
return TRUE;
}
void
proto_register_hislip(void)
{
expert_module_t* expert_hislip;
module_t * hislip_module;
static hf_register_info hf[] = {
{ &hf_hislip_messagetype,
{ "Message Type", "hislip.messagetype", FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(messagetypestring), 0x0,
"HiSLIP Message Type", HFILL }},
{ &hf_hislip_controlcode,
{ "Control Code", "hislip.controltype", FT_UINT8, BASE_DEC, NULL, 0x0,
"HiSLIP Control Code", HFILL }},
{ &hf_hislip_controlcode_rmt,
{ "Control Code", "hislip.controltype.rmt", FT_UINT8, BASE_HEX, VALS(rmt), 0x0,
"HiSLIP RMT", HFILL }},
{ &hf_hislip_controlcode_overlap,
{ "Control Code", "hislip.controltype.overlap", FT_UINT8, BASE_HEX, VALS(overlap), 0x0,
"HiSLIP overlap", HFILL }},
{ &hf_hislip_controlcode_asynclockinforesponse_code,
{ "Control Code", "hislip.controltype.asynclockinforesponse", FT_UINT8, BASE_HEX, VALS(asynclockinforesponse_code), 0x0,
"HiSLIP asynclockinforesponse", HFILL }},
{ &hf_hislip_controlcode_asynclockresponse_code_release,
{ "Control Code", "hislip.controltype.asynclockresponse", FT_UINT8, BASE_HEX, VALS(asynclockresponse_code_release), 0x0,
"HiSLIP asynclockresponse code", HFILL }},
{ &hf_hislip_controlcode_asynclockresponse_code_request,
{ "Control Code", "hislip.controltype.asynclockresponse", FT_UINT8, BASE_HEX, VALS(asynclockresponse_code_request), 0x0,
"HiSLIP asynclockresponse code", HFILL }},
{ &hf_hislip_controlcode_asyncremotelocalcontrol_code,
{ "Control Code", "hislip.controltype.asyncremotelocalcontrol", FT_UINT8, BASE_HEX, VALS(asyncremotelocalcontrol_code), 0x0,
"HiSLIP asyncremotelocalcontrol", HFILL }},
{ &hf_hislip_controlcode_feature_negotiation,
{ "Control Code", "hislip.controltype.featurenegotiation", FT_UINT8, BASE_HEX, VALS(feature_negotiation), 0x0,
"HiSLIP feature", HFILL }},
{ &hf_hislip_controlcode_asynclock_code,
{ "Control Code", "hislip.controltype.asynclockcode", FT_UINT8, BASE_HEX, VALS(asynclock_code), 0x0,
"HiSLIP asynclock code", HFILL }},
{ &hf_hislip_controlcode_stb,
{ "STB", "hislip.controltype.stb", FT_UINT8, BASE_HEX, NULL, 0x0,
"HiSLIP Status Byte", HFILL }},
{ &hf_hislip_payloadlength,
{ "Payload Length", "hislip.payloadlength", FT_UINT64, BASE_DEC, NULL, 0x0,
"HiSLIP Payload Length", HFILL }},
{ &hf_hislip_messageparameter,
{ "Message Parameter", "hislip.msgpara", FT_NONE, BASE_NONE, NULL, 0x0,
"HiSLIP Message Parameter", HFILL }},
{ &hf_hislip_msgpara_messageid,
{ "MessageID", "hislip.msgpara.messageid", FT_UINT32, BASE_HEX, NULL, 0x0,
"HiSLIP MessageID", HFILL }},
{ &hf_hislip_msgpara_sessionid,
{ "SessionID", "hislip.msgpara.sessionid", FT_UINT16, BASE_HEX, NULL, 0x0,
"HiSLIP SessionID", HFILL }},
{ &hf_hislip_msgpara_serverproto,
{ "Server version", "hislip.msgpara.servproto", FT_UINT16, BASE_HEX, NULL, 0x0,
"HiSLIP Server Protocol version", HFILL }},
{ &hf_hislip_msgpara_vendorID,
{ "VendorID", "hislip.msgpara.vendorID", FT_UINT16, BASE_HEX|BASE_EXT_STRING, &vendorID_ext, 0x0,
"HiSLIP VendorID", HFILL }},
{ &hf_hislip_msgpara_clientproto,
{ "Client version", "hislip.msgpara.clientproto", FT_UINT16, BASE_HEX, NULL, 0x0,
"HiSLIP Client protocol version", HFILL }},
{ &hf_hislip_msgpara_clients,
{ "HiSLIP clients holding locks", "hislip.msgpara.clients", FT_UINT32, BASE_DEC, NULL, 0x0,
"HiSLIP clients holding locks on the server", HFILL }},
{ &hf_hislip_msgpara_timeout,
{ "Timeout[ms]", "hislip.msgpara.timeout", FT_UINT32, BASE_DEC, NULL, 0x0,
"Time out from a AsyncLock message", HFILL }},
{ &hf_hislip_data,
{ "Data", "hislip.data", FT_STRING, BASE_NONE, NULL, 0x0,
"HiSLIP Payload", HFILL }},
{ &hf_hislip_request,
{ "Request", "hislip.response", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"This is a response to the HiSLIP request in this frame", HFILL }},
{ &hf_hislip_response,
{ "Response", "hislip.request", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"A Request in this frame", HFILL }},
{ &hf_hislip_syn,
{ "Synchronous Channel", "hislip.syn", FT_NONE, BASE_NONE, NULL, 0x0,
"This is the HiSLIP Synchronous Channel", HFILL }},
{ &hf_hislip_asyn,
{ "Asynchronous Channel", "hislip.asyn", FT_NONE, BASE_NONE, NULL, 0x0,
"This is the HiSLIP ASynchronous Channel", HFILL }},
{ &hf_hislip_fatalerrcode,
{ "Fatalerror Code", "hislip.fatalerrcode", FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(fatalerrortype), 0x0,
"HiSLIP Fatalerror Code", HFILL }},
{ &hf_hislip_retransmission,
{ "Retransmission from", "hislip.retrans", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"HiSLIP Retransmission", HFILL }},
{ &hf_hislip_nonfatalerrorcode,
{ "Nonfatalerror Code", "hislip.nonfatalerrorcode", FT_UINT8, BASE_HEX|BASE_RANGE_STRING, RVALS(nonfatalerrortype), 0x0,
"HiSLIP Nonfatalerror Code", HFILL }},
{ &hf_hislip_maxmessagesize,
{ "Max Message Size", "hislip.maxmsgsize", FT_UINT64, BASE_DEC, NULL, 0x0,
"HiSLIP Maximum Message Size", HFILL }}
};
static gint *ett[] = {
&ett_hislip,
&ett_hislip_msgpara
};
static ei_register_info ei[] = {
{ &ei_wrong_prologue, { "hislip.wrongprologue", PI_UNDECODED, PI_WARN, "Frame hasn't 'HS' as Prologue", EXPFILL }},
{ &ei_msg_not_null, { "hislip.msgnotnull", PI_PROTOCOL, PI_WARN, "Message Parameter isn't 0", EXPFILL }}
};
proto_hislip = proto_register_protocol("High-Speed LAN Instrument Protocol", "HiSLIP", "hislip");
expert_hislip = expert_register_protocol(proto_hislip);
expert_register_field_array(expert_hislip, ei, array_length(ei));
proto_register_field_array(proto_hislip, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
hislip_module = prefs_register_protocol(proto_hislip, NULL);
prefs_register_obsolete_preference(hislip_module, "enable_heuristic");
}
void
proto_reg_handoff_hislip(void)
{
hislip_handle = create_dissector_handle(dissect_hislip, proto_hislip);
heur_dissector_add("tcp", dissect_hislip_heur, "HiSLIP over TCP", "hislip_tcp", proto_hislip, HEURISTIC_DISABLE);
dissector_add_uint_with_preference("tcp.port", HISLIP_PORT, hislip_handle);
}
