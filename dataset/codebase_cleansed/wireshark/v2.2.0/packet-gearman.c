static guint
get_gearman_pdu_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
return tvb_get_ntohl(tvb, offset+8)+GEARMAN_COMMAND_HEADER_SIZE;
}
static int
dissect_binary_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
gint offset, start_offset;
char *magic_code;
guint32 type, size;
guint len;
proto_item *content_item = NULL;
proto_tree *content_tree = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Gearman");
col_clear(pinfo->cinfo,COL_INFO);
magic_code = tvb_get_string_enc(wmem_packet_scope(), tvb, 1, 3, ENC_ASCII);
type = tvb_get_ntohl(tvb, 4);
size = tvb_get_ntohl(tvb, 8);
col_append_sep_fstr(pinfo->cinfo, COL_INFO, " , ", "[%s] ", magic_code);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s(%d) LEN=%d",
val_to_str(type, gearman_command_names, "Unknown (0x%08x)"), type, size);
if (tree) {
proto_item *ti;
proto_tree *command_tree, *gearman_tree;
ti = proto_tree_add_item(tree, proto_gearman, tvb, 0, -1, ENC_NA);
gearman_tree = proto_item_add_subtree(ti, ett_gearman);
command_tree = proto_tree_add_subtree_format(gearman_tree, tvb, 0, GEARMAN_COMMAND_HEADER_SIZE+size, ett_gearman_command, NULL,
"[%s] %s(%d) LEN=%d", magic_code, val_to_str(type, gearman_command_names, "Unknown (0x%08x)"), type, size);
proto_tree_add_string(command_tree, hf_gearman_magic_code, tvb, 0, 4, magic_code);
proto_tree_add_item(command_tree, hf_gearman_pkt_type, tvb, 4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(command_tree, hf_gearman_data_size, tvb, 8, 4, ENC_BIG_ENDIAN);
content_item = proto_tree_add_item(command_tree, hf_gearman_data_content, tvb, GEARMAN_COMMAND_HEADER_SIZE, size, ENC_ASCII|ENC_NA);
content_tree = proto_item_add_subtree(content_item, ett_gearman_content);
}
offset = GEARMAN_COMMAND_HEADER_SIZE;
switch(type)
{
case GEARMAN_COMMAND_ECHO_REQ:
case GEARMAN_COMMAND_ECHO_RES:
if (!tree) break;
proto_tree_add_item(content_tree, hf_gearman_echo_text, tvb,
offset, size, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_ERROR:
if (!tree) break;
len = tvb_strsize(tvb, offset);
proto_tree_add_item(content_tree, hf_gearman_err_code, tvb, offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_err_text, tvb, offset+len, size-len, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_JOB_CREATED:
case GEARMAN_COMMAND_WORK_FAIL:
if (!tree) break;
proto_tree_add_item(content_tree, hf_gearman_job_handle, tvb,
offset, size, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_STATUS_RES:
if (!tree) break;
start_offset = offset;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_job_handlez, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_known_status, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_running_status, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_complete_numerator, tvb, start_offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_complete_denominator, tvb, start_offset+len, size-start_offset+GEARMAN_COMMAND_HEADER_SIZE, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_OPTION_REQ:
case GEARMAN_COMMAND_OPTION_RES:
if (!tree) break;
proto_tree_add_item(content_tree, hf_gearman_option_name, tvb,
offset, size, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_SUBMIT_JOB:
case GEARMAN_COMMAND_SUBMIT_JOB_BG:
case GEARMAN_COMMAND_SUBMIT_JOB_HIGH:
case GEARMAN_COMMAND_SUBMIT_JOB_HIGH_BG:
case GEARMAN_COMMAND_SUBMIT_JOB_LOW:
case GEARMAN_COMMAND_SUBMIT_JOB_LOW_BG:
if (!tree) break;
start_offset = offset;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_func_name, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_uniq_id, tvb, start_offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_argument, tvb, start_offset+len, size-start_offset+GEARMAN_COMMAND_HEADER_SIZE, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_SUBMIT_JOB_SCHED:
if (!tree) break;
start_offset = offset;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_func_name, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_uniq_id, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_submit_job_sched_minute, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_submit_job_sched_hour, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_submit_job_sched_day_of_month, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_submit_job_sched_month, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_submit_job_sched_day_of_week, tvb, start_offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_argument, tvb, start_offset+len, size-start_offset+GEARMAN_COMMAND_HEADER_SIZE, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_SUBMIT_JOB_EPOCH:
if (!tree) break;
start_offset = offset;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_func_name, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_uniq_id, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_submit_job_epoch_time, tvb, start_offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_argument, tvb, start_offset+len, size-start_offset+GEARMAN_COMMAND_HEADER_SIZE, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_JOB_ASSIGN:
start_offset = offset;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_job_handlez, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_func_namez, tvb, start_offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_argument, tvb, start_offset+len, size-start_offset+GEARMAN_COMMAND_HEADER_SIZE, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_JOB_ASSIGN_UNIQ:
start_offset = offset;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_job_handlez, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_func_namez, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_uniq_id, tvb, start_offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_argument, tvb, start_offset+len, size-start_offset+GEARMAN_COMMAND_HEADER_SIZE, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_CAN_DO:
case GEARMAN_COMMAND_CANT_DO:
if (!tree) break;
proto_tree_add_item(content_tree, hf_gearman_func_name, tvb,
offset, size, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_CAN_DO_TIMEOUT:
if (!tree) break;
proto_tree_add_item(content_tree, hf_gearman_func_name, tvb,
offset, tvb_strsize(tvb, offset), ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_WORK_DATA:
case GEARMAN_COMMAND_WORK_WARNING:
case GEARMAN_COMMAND_WORK_COMPLETE:
case GEARMAN_COMMAND_WORK_EXCEPTION:
if (!tree) break;
len = tvb_strsize(tvb, offset);
proto_tree_add_item(content_tree, hf_gearman_job_handlez, tvb, offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_result, tvb, offset+len, size-len, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_WORK_STATUS:
if (!tree) break;
start_offset = offset;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_job_handlez, tvb, start_offset, len, ENC_NA|ENC_ASCII);
start_offset += len;
len = tvb_strsize(tvb, start_offset);
proto_tree_add_item(content_tree, hf_gearman_complete_numerator, tvb, start_offset, len, ENC_NA|ENC_ASCII);
proto_tree_add_item(content_tree, hf_gearman_complete_denominator, tvb, start_offset+len, size-start_offset+GEARMAN_COMMAND_HEADER_SIZE, ENC_NA|ENC_ASCII);
break;
case GEARMAN_COMMAND_SET_CLIENT_ID:
if (!tree) break;
proto_tree_add_item(content_tree, hf_gearman_client_id, tvb,
offset, size, ENC_NA|ENC_ASCII);
break;
default:
if (size > 0)
expert_add_info(pinfo, content_item, &ei_gearman_pkt_type_unknown);
}
col_set_fence(pinfo->cinfo, COL_INFO);
return tvb_captured_length(tvb);
}
static void
dissect_management_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int i, type = 0, cmdlen, linelen, offset = 0, next_offset = 0;
proto_item *ti;
proto_tree *gearman_tree;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Gearman");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_gearman, tvb, 0, -1, ENC_NA);
gearman_tree = proto_item_add_subtree(ti, ett_gearman);
while ((linelen = tvb_find_line_end(tvb, offset, -1, &next_offset, FALSE)) > 0)
{
for (i=0; i<GEARMAN_MGR_CMDS_COUNT; i++)
{
cmdlen = (int)strlen(GEARMAN_MGR_CMDS[i]);
if (cmdlen == linelen && 0 == tvb_strneql(tvb, offset, GEARMAN_MGR_CMDS[i], cmdlen))
{
const guint8* cmdstr;
proto_tree_add_item_ret_string(gearman_tree, hf_gearman_mgr_cmd, tvb, offset, cmdlen, ENC_ASCII|ENC_NA, wmem_packet_scope(), &cmdstr);
col_add_fstr(pinfo->cinfo, COL_INFO, "[MGR] %s", cmdstr);
type = 1;
break;
}
}
if (GEARMAN_MGR_CMDS_COUNT == i)
{
proto_tree_add_format_text(gearman_tree, tvb, offset, next_offset - offset);
if (type == 0)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "[MGR] %s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, linelen, ENC_ASCII));
type = -1;
}
else
{
col_append_sep_fstr(pinfo->cinfo, COL_INFO, ",", "%s", tvb_get_string_enc(wmem_packet_scope(), tvb, offset, linelen, ENC_ASCII));
}
}
offset = next_offset;
}
}
static int
dissect_gearman(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
if ((0 == tvb_memeql(tvb, 0, GEARMAN_MAGIC_CODE_REQUEST, 4)) ||
(0 == tvb_memeql(tvb, 0, GEARMAN_MAGIC_CODE_RESPONSE, 4)))
{
tcp_dissect_pdus(tvb, pinfo, tree, gearman_desegment, GEARMAN_COMMAND_HEADER_SIZE, get_gearman_pdu_len, dissect_binary_packet, data);
}
else
{
dissect_management_packet(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
void
proto_register_gearman(void)
{
static hf_register_info hf[] = {
{ &hf_gearman_mgr_cmd, { "Management Command", "gearman.mgr_cmd", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_gearman_magic_code, { "Magic Code", "gearman.magic_code", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_gearman_pkt_type, { "Packet Type", "gearman.pkt_type", FT_UINT32, BASE_DEC_HEX, VALS(gearman_command_names), 0x0, NULL, HFILL} },
{ &hf_gearman_data_size, { "Data Length", "gearman.data_size", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_data_content, { "Data Content", "gearman.data_content", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_option_name, { "Option Name", "gearman.opt.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_func_name, { "Function Name", "gearman.func.name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_func_namez, { "Function Name", "gearman.func.name", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_client_id, { "Client ID", "gearman.client_id", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_uniq_id, { "Unique ID", "gearman.uniq_id", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_argument, { "Function Argument", "gearman.func.arg", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_job_handle, { "Job Handle", "gearman.job.handle", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_job_handlez, { "Job Handle", "gearman.job.handle", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_complete_numerator, { "Complete Numerator", "gearman.numerator", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_complete_denominator, { "Complete Denominator", "gearman.denominator", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_submit_job_sched_minute, { "Minute", "gearman.submit_job_sched.minute", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_submit_job_sched_hour, { "Hour", "gearman.submit_job_sched.hour", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_submit_job_sched_day_of_month, { "Day of Month", "gearman.submit_job_sched.day_of_month", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_submit_job_sched_month, { "Month", "gearman.submit_job_sched.month", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_submit_job_sched_day_of_week, { "Day of Week", "gearman.submit_job_sched.day_of_week", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_submit_job_epoch_time, { "Epoch Time", "gearman.submit_job.epoch_time", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_result, { "Function Result", "gearman.func.result", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_known_status, { "Known job", "gearman.job.known", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_running_status, { "Running Job", "gearman.job.running", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_echo_text, { "Echo Text", "gearman.echo_text", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_err_code, { "Error Code", "gearman.err.code", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL} },
{ &hf_gearman_err_text, { "Error Text", "gearman.err.text", FT_STRINGZ, BASE_NONE, NULL, 0x0, NULL, HFILL} }
};
static gint *ett[] = {
&ett_gearman,
&ett_gearman_command,
&ett_gearman_content
};
static ei_register_info ei[] = {
{ &ei_gearman_pkt_type_unknown, { "gearman.pkt_type.unknown", PI_PROTOCOL, PI_WARN, "Unknown command", EXPFILL }},
};
module_t *gearman_module;
expert_module_t* expert_gearman;
proto_gearman = proto_register_protocol("Gearman Protocol", "Gearman", "gearman");
proto_register_field_array(proto_gearman, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gearman = expert_register_protocol(proto_gearman);
expert_register_field_array(expert_gearman, ei, array_length(ei));
gearman_module = prefs_register_protocol(proto_gearman, NULL);
prefs_register_bool_preference(gearman_module, "desegment",
"Desegment all Gearman messages spanning multiple TCP segments",
"Whether the Gearman dissector should desegment all messages spanning multiple TCP segments",
&gearman_desegment);
}
void
proto_reg_handoff_gearman(void)
{
dissector_handle_t gearman_handle;
gearman_handle = create_dissector_handle(dissect_gearman, proto_gearman);
dissector_add_uint("tcp.port", GEARMAN_PORT, gearman_handle);
}
