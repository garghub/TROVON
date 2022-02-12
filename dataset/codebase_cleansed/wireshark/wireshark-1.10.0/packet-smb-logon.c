static int
dissect_account_control(tvbuff_t *tvb, proto_tree *tree, int offset)
{
proto_item *ti = NULL;
proto_tree *flags_tree = NULL;
guint32 flags;
flags = tvb_get_letohl(tvb, offset);
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 4,
"Account control = 0x%04x", flags);
flags_tree = proto_item_add_subtree(ti, ett_smb_account_flags);
}
proto_tree_add_boolean(flags_tree, hf_flags_autolock, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_expire, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_server_trust, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_workstation_trust, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_interdomain_trust, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_mns_user, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_normal_user, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_temp_dup_user, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_password_required, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_homedir_required, tvb, offset, 4, flags);
proto_tree_add_boolean(flags_tree, hf_flags_enabled, tvb, offset, 4, flags);
offset += 4;
return offset;
}
static int
display_LM_token(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint16 Token;
Token = tvb_get_letohs(tvb, offset);
if (Token & 0x01) {
proto_tree_add_uint_format(tree, hf_lm_token, tvb, offset, 2,
Token,
"LM20 Token: 0x%04x (LanMan 2.0 or higher)", Token);
} else {
proto_tree_add_uint_format(tree, hf_lm_token, tvb, offset, 2,
Token,
"LM10 Token: 0x%04x (WFW Networking)", Token);
}
offset += 2;
return offset;
}
static int
display_LMNT_token(tvbuff_t *tvb, int offset, proto_tree *tree)
{
guint16 Token;
Token = tvb_get_letohs(tvb, offset);
if (Token == 0xffff) {
proto_tree_add_uint_format(tree, hf_lmnt_token, tvb, offset, 2,
Token,
"LMNT Token: 0x%04x (Windows NT Networking)", Token);
} else {
proto_tree_add_uint_format(tree, hf_lm_token, tvb, offset, 2,
Token,
"LMNT Token: 0x%04x (Unknown)", Token);
}
offset += 2;
return offset;
}
static int
dissect_smb_logon_request(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = display_ms_string(tvb, tree, offset, hf_computer_name, NULL);
offset = display_ms_string(tvb, tree, offset, hf_user_name, NULL);
offset = display_ms_string(tvb, tree, offset, hf_mailslot_name, NULL);
proto_tree_add_item(tree, hf_request_count, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_logon_LM10_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = display_ms_string(tvb, tree, offset, hf_user_name, NULL);
offset = display_ms_string(tvb, tree, offset, hf_script_name, NULL);
return offset;
}
static int
dissect_smb_logon_2(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = display_ms_string(tvb, tree, offset, hf_computer_name, NULL);
offset = display_ms_string(tvb, tree, offset, hf_mailslot_name, NULL);
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_logon_LM20_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = display_ms_string(tvb, tree, offset, hf_server_name, NULL);
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_pdc_query(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
char *name;
offset = display_ms_string(tvb, tree, offset, hf_computer_name, &name);
if (check_col(pinfo->cinfo, COL_INFO))
col_append_fstr(pinfo->cinfo, COL_INFO, " from %s", name);
offset = display_ms_string(tvb, tree, offset, hf_mailslot_name, NULL);
if (tvb_reported_length_remaining(tvb, offset) > 2) {
if (offset % 2) offset++;
offset = display_unicode_string(tvb, tree, offset, hf_unicode_computer_name, NULL);
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LMNT_token(tvb, offset, tree);
}
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_pdc_startup(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = display_ms_string(tvb, tree, offset, hf_pdc_name, NULL);
if (tvb_reported_length_remaining(tvb, offset) != 0) {
char *name = NULL;
if (offset % 2) offset++;
offset = display_unicode_string(tvb, tree, offset, hf_unicode_pdc_name, &name);
if (name && check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ": host %s", name);
name = NULL;
}
if (offset % 2) offset++;
offset = display_unicode_string(tvb, tree, offset, hf_domain_name, &name);
if (name && check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, ", domain %s", name);
name = NULL;
}
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LMNT_token(tvb, offset, tree);
offset = display_LM_token(tvb, offset, tree);
}
return offset;
}
static int
dissect_smb_pdc_failure(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_announce_change(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 info_count;
proto_item *ti = NULL;
proto_tree *info_tree = NULL;
guint32 db_index;
guint32 domain_sid_size;
proto_tree_add_item(tree, hf_low_serial, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_date_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_pulse, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_random, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_ms_string(tvb, tree, offset, hf_pdc_name, NULL);
offset = display_ms_string(tvb, tree, offset, hf_domain_name, NULL);
if (offset % 2) offset++;
if (tvb_reported_length_remaining(tvb, offset) > 2) {
offset = display_unicode_string(tvb, tree, offset, hf_unicode_pdc_name, NULL);
offset = display_unicode_string(tvb, tree, offset, hf_domain_name, NULL);
info_count = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_db_count, tvb, offset, 4, info_count);
offset += 4;
while (info_count != 0) {
db_index = tvb_get_letohl(tvb, offset);
if (tree) {
ti = proto_tree_add_text(tree, tvb, offset, 20,
"DBChange Info Structure: index %u", db_index);
info_tree = proto_item_add_subtree(ti, ett_smb_db_info);
}
proto_tree_add_uint(info_tree, hf_db_index, tvb, offset, 4,
db_index);
offset += 4;
proto_tree_add_item(info_tree, hf_large_serial, tvb, offset, 8,
ENC_LITTLE_ENDIAN);
offset += 8;
offset = dissect_nt_64bit_time(tvb, info_tree, offset,
hf_nt_date_time);
info_count--;
}
domain_sid_size = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_domain_sid_size, tvb, offset, 4,
domain_sid_size);
offset += 4;
if (domain_sid_size != 0) {
offset = ((offset + 3)/4)*4;
offset = dissect_nt_sid(
tvb, offset, tree, "Domain", NULL, -1);
}
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LMNT_token(tvb, offset, tree);
}
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_sam_logon_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 domain_sid_size;
proto_tree_add_item(tree, hf_request_count, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
offset = display_unicode_string(tvb, tree, offset, hf_unicode_computer_name, NULL);
offset = display_unicode_string(tvb, tree, offset, hf_user_name, NULL);
offset = display_ms_string(tvb, tree, offset, hf_mailslot_name, NULL);
offset = dissect_account_control(tvb, tree, offset);
domain_sid_size = tvb_get_letohl(tvb, offset);
proto_tree_add_uint(tree, hf_domain_sid_size, tvb, offset, 4,
domain_sid_size);
offset += 4;
if (domain_sid_size != 0) {
offset = ((offset + 3)/4)*4;
offset = dissect_nt_sid(tvb, offset, tree, "Domain", NULL, -1);
}
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LMNT_token(tvb, offset, tree);
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_no_user(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
offset = display_ms_string(tvb, tree, offset, hf_computer_name, NULL);
return offset;
}
static int
dissect_smb_relogon_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_major_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_minor_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_os_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_acc_update(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
guint32 Temp1, Temp2;
Temp1 = tvb_get_letohl(tvb, offset);
Temp2 = tvb_get_letohl(tvb, offset + 4);
proto_tree_add_text(tree, tvb, offset, 8, "Signature: 0x%08x%08x",
Temp1, Temp2);
offset += 8;
proto_tree_add_item(tree, hf_date_time, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_ms_string(tvb, tree, offset, hf_computer_name, NULL);
offset = display_ms_string(tvb, tree, offset, hf_user_name, NULL);
proto_tree_add_item(tree, hf_update_type, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_inter_resp(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_item(tree, hf_major_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_minor_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_os_version, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LMNT_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_sam_logon_resp(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int offset)
{
offset = display_unicode_string(tvb, tree, offset, hf_server_name, NULL);
offset = display_unicode_string(tvb, tree, offset, hf_user_name, NULL);
offset = display_unicode_string(tvb, tree, offset, hf_domain_name, NULL);
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LMNT_token(tvb, offset, tree);
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_pdc_response_ads(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, int offset)
{
offset = ((offset + 3)/4)*4;
proto_tree_add_item(tree, hf_unknown32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_domain_guid, tvb, offset, 16, ENC_NA);
offset += 16;
offset=dissect_ms_compressed_string(tvb, tree, offset, hf_forest_dns_name, NULL);
offset=dissect_ms_compressed_string(tvb, tree, offset, hf_domain_dns_name, NULL);
offset=dissect_ms_compressed_string(tvb, tree, offset, hf_server_dns_name, NULL);
offset=dissect_ms_compressed_string(tvb, tree, offset, hf_domain_name, NULL);
offset=dissect_ms_compressed_string(tvb, tree, offset, hf_server_name, NULL);
offset=dissect_ms_compressed_string(tvb, tree, offset, hf_user_name, NULL);
offset=dissect_ms_compressed_string(tvb, tree, offset, hf_server_site_name, NULL);
offset=dissect_ms_compressed_string(tvb, tree, offset, hf_client_site_name, NULL);
proto_tree_add_item(tree, hf_unknown8, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_unknown32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_server_ip, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_unknown32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_unknown32, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(tree, hf_nt_version, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
offset = display_LMNT_token(tvb, offset, tree);
offset = display_LM_token(tvb, offset, tree);
return offset;
}
static int
dissect_smb_unknown(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, int offset)
{
proto_tree_add_text(tree, tvb, offset, -1, "Data (%u bytes)",
tvb_reported_length_remaining(tvb, offset));
return offset+tvb_length_remaining(tvb, offset);
}
static void
dissect_smb_logon(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int offset = 0;
guint8 cmd;
proto_tree *smb_logon_tree = NULL;
proto_item *item = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SMB_NETLOGON");
col_clear(pinfo->cinfo, COL_INFO);
cmd = tvb_get_guint8(tvb, offset);
if (check_col(pinfo->cinfo, COL_INFO))
col_add_str(pinfo->cinfo, COL_INFO, val_to_str(cmd, commands, "Unknown Command:%02x") );
if (tree) {
item = proto_tree_add_item(tree, proto_smb_logon, tvb,
offset, -1, ENC_NA);
smb_logon_tree = proto_item_add_subtree(item, ett_smb_logon);
}
proto_tree_add_uint(smb_logon_tree, hf_command, tvb, offset, 1, cmd);
offset += 1;
offset += 1;
if (cmd<LOGON_LAST_CMD) {
(dissect_smb_logon_cmds[cmd])(tvb, pinfo,
smb_logon_tree, offset);
} else {
dissect_smb_unknown(tvb, pinfo, smb_logon_tree,
offset);
}
}
void
proto_register_smb_logon( void)
{
static hf_register_info hf[] = {
{ &hf_command,
{ "Command", "smb_netlogon.command", FT_UINT8, BASE_HEX,
VALS(commands), 0, "SMB NETLOGON Command", HFILL }},
{ &hf_computer_name,
{ "Computer Name", "smb_netlogon.computer_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Computer Name", HFILL }},
{ &hf_unicode_computer_name,
{ "Unicode Computer Name", "smb_netlogon.unicode_computer_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Unicode Computer Name", HFILL }},
{ &hf_server_name,
{ "Server Name", "smb_netlogon.server_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Server Name", HFILL }},
{ &hf_server_dns_name,
{ "Server DNS Name", "smb_netlogon.server_dns_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Server DNS Name", HFILL }},
{ &hf_user_name,
{ "User Name", "smb_netlogon.user_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON User Name", HFILL }},
{ &hf_domain_name,
{ "Domain Name", "smb_netlogon.domain_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Domain Name", HFILL }},
{ &hf_domain_dns_name,
{ "Domain DNS Name", "smb_netlogon.domain_dns_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Domain DNS Name", HFILL }},
{ &hf_forest_dns_name,
{ "Forest DNS Name", "smb_netlogon.forest_dns_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Forest DNS Name", HFILL }},
{ &hf_mailslot_name,
{ "Mailslot Name", "smb_netlogon.mailslot_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Mailslot Name", HFILL }},
{ &hf_pdc_name,
{ "PDC Name", "smb_netlogon.pdc_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON PDC Name", HFILL }},
{ &hf_unicode_pdc_name,
{ "Unicode PDC Name", "smb_netlogon.unicode_pdc_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Unicode PDC Name", HFILL }},
{ &hf_script_name,
{ "Script Name", "smb_netlogon.script_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Script Name", HFILL }},
{ &hf_nt_version,
{ "NT Version", "smb_netlogon.nt_version", FT_UINT32, BASE_DEC,
NULL, 0, "SMB NETLOGON NT Version", HFILL }},
{ &hf_lmnt_token,
{ "LMNT Token", "smb_netlogon.lmnt_token", FT_UINT16, BASE_HEX,
NULL, 0, "SMB NETLOGON LMNT Token", HFILL }},
{ &hf_lm_token,
{ "LM Token", "smb_netlogon.lm_token", FT_UINT16, BASE_HEX,
NULL, 0, "SMB NETLOGON LM Token", HFILL }},
{ &hf_major_version,
{ "Workstation Major Version", "smb_netlogon.major_version", FT_UINT8, BASE_DEC,
NULL, 0, "SMB NETLOGON Workstation Major Version", HFILL }},
{ &hf_minor_version,
{ "Workstation Minor Version", "smb_netlogon.minor_version", FT_UINT8, BASE_DEC,
NULL, 0, "SMB NETLOGON Workstation Minor Version", HFILL }},
{ &hf_os_version,
{ "Workstation OS Version", "smb_netlogon.os_version", FT_UINT8, BASE_DEC,
NULL, 0, "SMB NETLOGON Workstation OS Version", HFILL }},
{ &hf_date_time,
{ "Date/Time", "smb_netlogon.date_time", FT_UINT32, BASE_DEC,
NULL, 0, "SMB NETLOGON Date/Time", HFILL }},
{ &hf_update_type,
{ "Update Type", "smb_netlogon.update", FT_UINT16, BASE_DEC,
NULL, 0, "SMB NETLOGON Update Type", HFILL }},
{ &hf_request_count,
{ "Request Count", "smb_netlogon.request_count", FT_UINT16, BASE_DEC,
NULL, 0, "SMB NETLOGON Request Count", HFILL }},
{ &hf_flags_autolock,
{ "Autolock", "smb_netlogon.flags.autolock", FT_BOOLEAN, 32,
TFS(&tfs_flags_autolock), ACC_FLAG_AUTO_LOCKED, "SMB NETLOGON Account Autolock", HFILL}},
{ &hf_flags_expire,
{ "Expire", "smb_netlogon.flags.expire", FT_BOOLEAN, 32,
TFS(&tfs_flags_expire), ACC_FLAG_EXPIRE, "SMB NETLOGON Will Account Expire", HFILL}},
{ &hf_flags_server_trust,
{ "Server Trust", "smb_netlogon.flags.server", FT_BOOLEAN, 32,
TFS(&tfs_flags_server_trust), ACC_FLAG_SERVER_TRUST, "SMB NETLOGON Server Trust Account", HFILL}},
{ &hf_flags_workstation_trust,
{ "Workstation Trust", "smb_netlogon.flags.workstation", FT_BOOLEAN, 32,
TFS(&tfs_flags_workstation_trust), ACC_FLAG_WORKSTATION_TRUST, "SMB NETLOGON Workstation Trust Account", HFILL}},
{ &hf_flags_interdomain_trust,
{ "Interdomain Trust", "smb_netlogon.flags.interdomain", FT_BOOLEAN, 32,
TFS(&tfs_flags_interdomain_trust), ACC_FLAG_INTERDOMAIN_TRUST, "SMB NETLOGON Inter-domain Trust Account", HFILL}},
{ &hf_flags_mns_user,
{ "MNS User", "smb_netlogon.flags.mns", FT_BOOLEAN, 32,
TFS(&tfs_flags_mns_user), ACC_FLAG_MNS_USER, "SMB NETLOGON MNS User Account", HFILL}},
{ &hf_flags_normal_user,
{ "Normal User", "smb_netlogon.flags.normal", FT_BOOLEAN, 32,
TFS(&tfs_flags_normal_user), ACC_FLAG_NORMAL_USER, "SMB NETLOGON Normal User Account", HFILL}},
{ &hf_flags_temp_dup_user,
{ "Temp Duplicate User", "smb_netlogon.flags.temp_dup", FT_BOOLEAN, 32,
TFS(&tfs_flags_temp_dup_user), ACC_FLAG_TEMP_DUP_USER, "SMB NETLOGON Temp Duplicate User Account", HFILL}},
{ &hf_flags_password_required,
{ "Password", "smb_netlogon.flags.password", FT_BOOLEAN, 32,
TFS(&tfs_flags_password_required), ACC_FLAG_PASSWORD_REQUIRED, "SMB NETLOGON Password Required", HFILL}},
{ &hf_flags_homedir_required,
{ "Homedir", "smb_netlogon.flags.homedir", FT_BOOLEAN, 32,
TFS(&tfs_flags_homedir_required), ACC_FLAG_HOMEDIR_REQUIRED, "SMB NETLOGON Homedir Required", HFILL}},
{ &hf_flags_enabled,
{ "Enabled", "smb_netlogon.flags.enabled", FT_BOOLEAN, 32,
TFS(&tfs_flags_enabled), ACC_FLAG_ENABLED, "SMB NETLOGON Is This Account Enabled", HFILL}},
{ &hf_domain_sid_size,
{ "Domain SID Size", "smb_netlogon.domain_sid_size", FT_UINT32, BASE_DEC,
NULL, 0, "SMB NETLOGON Domain SID Size", HFILL }},
{ &hf_low_serial,
{ "Low Serial Number", "smb_netlogon.low_serial", FT_UINT32, BASE_DEC,
NULL, 0, "SMB NETLOGON Low Serial Number", HFILL }},
{ &hf_pulse,
{ "Pulse", "smb_netlogon.pulse", FT_UINT32, BASE_DEC,
NULL, 0, "SMB NETLOGON Pulse", HFILL }},
{ &hf_random,
{ "Random", "smb_netlogon.random", FT_UINT32, BASE_DEC,
NULL, 0, "SMB NETLOGON Random", HFILL }},
{ &hf_db_count,
{ "DB Count", "smb_netlogon.db_count", FT_UINT32, BASE_DEC,
NULL, 0, "SMB NETLOGON DB Count", HFILL }},
{ &hf_db_index,
{ "Database Index", "smb_netlogon.db_index", FT_UINT32, BASE_DEC,
NULL, 0, "SMB NETLOGON Database Index", HFILL }},
{ &hf_large_serial,
{ "Large Serial Number", "smb_netlogon.large_serial", FT_UINT64, BASE_DEC,
NULL, 0, "SMB NETLOGON Large Serial Number", HFILL }},
{ &hf_nt_date_time,
{ "NT Date/Time", "smb_netlogon.nt_date_time", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0, "SMB NETLOGON NT Date/Time", HFILL }},
{ &hf_unknown8,
{ "Unknown", "smb_netlogon.unknown", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_unknown32,
{ "Unknown", "smb_netlogon.unknown", FT_UINT32, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_domain_guid,
{ "Domain GUID", "smb_netlogon.domain.guid", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &hf_server_ip, {
"Server IP", "smb_netlogon.server_ip", FT_IPv4, BASE_NONE,
NULL, 0x0, "Server IP Address", HFILL }},
{ &hf_server_site_name,
{ "Server Site Name", "smb_netlogon.server_site_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Server Site Name", HFILL }},
{ &hf_client_site_name,
{ "Client Site Name", "smb_netlogon.client_site_name", FT_STRING, BASE_NONE,
NULL, 0, "SMB NETLOGON Client Site Name", HFILL }},
};
static gint *ett[] = {
&ett_smb_logon,
&ett_smb_account_flags,
&ett_smb_db_info
};
proto_smb_logon = proto_register_protocol(
"Microsoft Windows Logon Protocol (Old)", "SMB_NETLOGON", "smb_netlogon");
proto_register_field_array(proto_smb_logon, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("smb_netlogon", dissect_smb_logon, proto_smb_logon);
}
