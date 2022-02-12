static int dissect_rate_class(tvbuff_t *tvb, packet_info *pinfo _U_, int offset, proto_tree *class_tree)
{
proto_tree_add_uint(class_tree, hf_generic_rateinfo_classid, tvb, offset, 2, tvb_get_ntohs(tvb, offset));offset+=2;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_windowsize, tvb, offset, 4, tvb_get_ntohl(tvb, offset));offset+=4;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_clearlevel, tvb, offset, 4, tvb_get_ntohl(tvb, offset));offset+=4;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_alertlevel, tvb, offset, 4, tvb_get_ntohl(tvb, offset));offset+=4;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_limitlevel, tvb, offset, 4, tvb_get_ntohl(tvb, offset));offset+=4;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_disconnectlevel, tvb, offset, 4, tvb_get_ntohl(tvb, offset));offset+=4;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_currentlevel, tvb, offset, 4, tvb_get_ntohl(tvb, offset));offset+=4;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_maxlevel, tvb, offset, 4, tvb_get_ntohl(tvb, offset));offset+=4;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_lasttime, tvb, offset, 4, tvb_get_ntohl(tvb, offset));offset+=4;
proto_tree_add_uint(class_tree, hf_generic_rateinfo_curstate, tvb, offset, 1, tvb_get_guint8(tvb, offset));offset+=1;
return offset;
}
static int dissect_generic_rateinfo(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree)
{
int offset = 0;
guint16 i;
proto_item *ti;
guint16 numclasses = tvb_get_ntohs(tvb, 0);
proto_tree *classes_tree = NULL, *groups_tree, *group_tree;
proto_tree_add_uint(tree, hf_generic_rateinfo_numclasses, tvb, 0, 2, numclasses );
offset+=2;
if(tree) {
ti = proto_tree_add_text(tree, tvb, offset, 35 * numclasses, "Available Rate Classes");
classes_tree = proto_item_add_subtree(ti, ett_generic_rateinfo_classes);
}
for(i = 0; i < numclasses; i++) {
guint16 myid = tvb_get_ntohs(tvb, offset);
proto_item *ti_local = proto_tree_add_text(classes_tree, tvb, offset, 35, "Rate Class 0x%02x", myid);
proto_tree *class_tree = proto_item_add_subtree(ti_local, ett_generic_rateinfo_class);
offset = dissect_rate_class(tvb, pinfo, offset, class_tree);
}
ti = proto_tree_add_text(tree, tvb, offset, -1, "Rate Groups");
groups_tree = proto_item_add_subtree(ti, ett_generic_rateinfo_groups);
for(i = 0; i < numclasses; i++) {
guint16 j;
guint16 myid = tvb_get_ntohs(tvb, offset);
guint16 numpairs = tvb_get_ntohs(tvb, offset + 2);
proto_item *ti_local = proto_tree_add_text(groups_tree, tvb, offset, 4 + 4 * numpairs, "Rate Group 0x%02x", myid);
group_tree = proto_item_add_subtree(ti_local, ett_generic_rateinfo_group);
proto_tree_add_uint(group_tree, hf_generic_rateinfo_classid, tvb, offset, 2, myid);offset+=2;
proto_tree_add_uint(group_tree, hf_generic_rateinfo_numpairs, tvb, offset, 2, numpairs); offset+=2;
for(j = 0; j < numpairs; j++) {
guint16 family_id;
guint16 subtype_id;
const aim_family *family;
const aim_subtype *subtype;
family_id = tvb_get_ntohs(tvb, offset); offset+=2;
subtype_id = tvb_get_ntohs(tvb, offset); offset+=2;
family = aim_get_family(family_id);
subtype = aim_get_subtype(family_id, subtype_id);
proto_tree_add_text(group_tree, tvb, offset-4, 4, "Family: %s (0x%04x), Subtype: %s (0x%04x)", family?family->name:"Unknown", family_id, subtype?subtype->name:"Unknown", subtype_id);
}
}
return offset;
}
static int dissect_aim_generic_clientready(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_item *ti = proto_tree_add_text(gen_tree, tvb, 0, tvb_length(tvb), "Supported services");
proto_tree *entry = proto_item_add_subtree(ti, ett_generic_clientready);
while(tvb_length_remaining(tvb, offset) > 0) {
guint16 famnum = tvb_get_ntohs(tvb, offset);
const aim_family *family = aim_get_family(famnum);
proto_tree *subentry;
ti = proto_tree_add_text(entry, tvb, offset, 2, "%s (0x%x)", family?family->name:"Unknown Family", famnum);
offset+=2;
subentry = proto_item_add_subtree(ti, ett_generic_clientready_item);
proto_tree_add_text(subentry, tvb, offset, 2, "Version: %d", tvb_get_ntohs(tvb, offset) ); offset += 2;
proto_tree_add_text(subentry, tvb, offset, 4, "DLL Version: %u", tvb_get_ntoh24(tvb, offset) ); offset += 4;
}
return offset;
}
static int dissect_aim_generic_serverready(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_item *ti = proto_tree_add_text(gen_tree, tvb, offset, tvb_length(tvb), "Supported services");
proto_tree *entry = proto_item_add_subtree(ti, ett_generic_clientready);
while(tvb_length_remaining(tvb, offset) > 0) {
guint16 famnum = tvb_get_ntohs(tvb, offset);
const aim_family *family = aim_get_family(famnum);
proto_tree_add_text(entry, tvb, offset, 2, "%s (0x%x)", family?family->name:"Unknown Family", famnum);
offset+=2;
}
return offset;
}
static int dissect_aim_generic_service_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
const aim_family *family = aim_get_family( tvb_get_ntohs(tvb, offset) );
proto_tree_add_uint_format(gen_tree, hf_generic_servicereq_service, tvb, offset, 2, tvb_get_ntohs(tvb, offset), "%s (0x%04x)", family?family->name:"Unknown", tvb_get_ntohs(tvb, offset) );
offset+=2;
return offset;
}
static int dissect_aim_generic_redirect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, gen_tree, aim_client_tlvs);
}
static int dissect_aim_generic_capabilities(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_item *ti = proto_tree_add_text(gen_tree, tvb, offset, tvb_length(tvb), "Requested services");
proto_tree *entry = proto_item_add_subtree(ti, ett_generic_clientready);
while(tvb_length_remaining(tvb, offset) > 0) {
guint16 famnum = tvb_get_ntohs(tvb, offset);
const aim_family *family = aim_get_family(famnum);
proto_tree_add_text(entry, tvb, offset, 4, "%s (0x%x), Version: %d", family?family->name:"Unknown Family", famnum, tvb_get_ntohs(tvb, offset+2));
offset += 4;
}
return offset;
}
static int dissect_aim_generic_capack(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_item *ti = proto_tree_add_text(gen_tree, tvb, offset, tvb_length(tvb), "Accepted requested services");
proto_tree *entry = proto_item_add_subtree(ti, ett_generic_clientready);
while(tvb_length_remaining(tvb, offset) > 0) {
guint16 famnum = tvb_get_ntohs(tvb, offset);
const aim_family *family = aim_get_family(famnum);
proto_tree_add_text(entry, tvb, offset, 4, "%s (0x%x), Version: %d", family?family->name:"Unknown Family", famnum, tvb_get_ntohs(tvb, offset+2));
offset += 4;
}
return offset;
}
static int dissect_aim_generic_motd(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_motd_motdtype, tvb, offset,
2, tvb_get_ntohs(tvb, offset));
offset+=2;
return dissect_aim_tlv_sequence(tvb, pinfo, offset, gen_tree, aim_motd_tlvs);
}
static int dissect_aim_generic_rateinfoack(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
while(tvb_length_remaining(tvb, offset) > 0) {
proto_tree_add_uint(gen_tree, hf_generic_rateinfoack_group, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
offset+=2;
}
return offset;
}
static int dissect_aim_generic_ratechange(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = 0;
proto_tree_add_uint(gen_tree, hf_generic_ratechange_msg, tvb, offset, 2, tvb_get_ntohs(tvb, offset));
offset+=2;
offset = dissect_rate_class(tvb, pinfo, offset, gen_tree);
return offset;
}
static int dissect_aim_generic_clientpauseack(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
while(tvb_length_remaining(tvb, offset) > 0) {
guint16 famnum = tvb_get_ntohs(tvb, offset);
const aim_family *family = aim_get_family(famnum);
proto_tree_add_text(gen_tree, tvb, offset, 4, "Family: %s (0x%x)", family?family->name:"Unknown Family", famnum);
offset += 2;
}
return offset;
}
static int dissect_aim_generic_migration_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = 0;
guint32 n, i;
proto_item *ti;
proto_tree *entry;
n = tvb_get_ntohs(tvb, offset);offset+=2;
proto_tree_add_uint(gen_tree, hf_generic_migration_numfams, tvb, offset, 2, n);
ti = proto_tree_add_text(gen_tree, tvb, offset, 2 * n, "Families to migrate");
entry = proto_item_add_subtree(ti, ett_generic_migratefamilies);
for(i = 0; i < n; i++) {
guint16 famnum = tvb_get_ntohs(tvb, offset);
const aim_family *family = aim_get_family(famnum);
proto_tree_add_text(entry, tvb, offset, 4, "Family: %s (0x%x)", family?family->name:"Unknown Family", famnum);
offset += 2;
}
return dissect_aim_tlv_sequence(tvb, pinfo, offset, gen_tree, aim_client_tlvs);
}
static int dissect_aim_generic_setprivflags(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
guint32 flags = tvb_get_ntoh24(tvb, offset);
proto_item *ti = proto_tree_add_uint(gen_tree, hf_generic_priv_flags, tvb, offset, 4, flags);
proto_tree *entry = proto_item_add_subtree(ti, ett_generic_priv_flags);
proto_tree_add_boolean(entry, hf_generic_allow_idle_see, tvb, offset, 4, flags);
proto_tree_add_boolean(entry, hf_generic_allow_member_see, tvb, offset, 4, flags);
offset+=4;
return offset;
}
static int dissect_aim_generic_selfinfo_repl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = dissect_aim_buddyname(tvb, pinfo, 0, gen_tree);
proto_tree_add_item(gen_tree, hf_generic_selfinfo_warninglevel, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return dissect_aim_tlv_list(tvb, pinfo, offset, gen_tree, aim_onlinebuddy_tlvs);
}
static int dissect_aim_generic_evil(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_evil_new_warn_level, tvb, offset, 2, ENC_BIG_ENDIAN);
while(tvb_length_remaining(tvb, offset) > 0) {
offset = dissect_aim_userinfo(tvb, pinfo, offset, gen_tree);
}
return offset;
}
static int dissect_aim_generic_setidle(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
proto_tree_add_item(gen_tree, hf_generic_idle_time, tvb, 0, 2, ENC_BIG_ENDIAN);
return 2;
}
static int dissect_aim_generic_ext_status_req(tvbuff_t *tvb, packet_info *pinfo, proto_tree *gen_tree)
{
return dissect_aim_tlv_sequence(tvb, pinfo, 0, gen_tree, aim_onlinebuddy_tlvs);
}
static int dissect_aim_generic_clientver_req(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_client_ver_req_offset, tvb, offset, 4, ENC_BIG_ENDIAN);
offset+=4;
proto_tree_add_item(gen_tree, hf_generic_client_ver_req_length, tvb, offset, 4, ENC_BIG_ENDIAN);
return offset+4;
}
static int dissect_aim_generic_clientver_repl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
proto_tree_add_item(gen_tree, hf_generic_client_ver_req_hash, tvb, 0, 16, ENC_NA);
return 16;
}
static int dissect_aim_generic_ext_status_repl(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *gen_tree)
{
guint8 length;
int offset = 0;
proto_tree_add_item(gen_tree, hf_generic_ext_status_type, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(gen_tree, hf_generic_ext_status_flags, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(gen_tree, hf_generic_ext_status_length, tvb, offset, 1, ENC_BIG_ENDIAN); length = tvb_get_guint8(tvb, offset); offset += 1;
proto_tree_add_item(gen_tree, hf_generic_ext_status_data, tvb, offset, length, ENC_NA); offset += 1;
return offset;
}
void
proto_register_aim_generic(void)
{
static hf_register_info hf[] = {
{ &hf_generic_servicereq_service,
{ "Requested Service", "aim_generic.servicereq.service", FT_UINT16,
BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_motd_motdtype,
{ "MOTD Type", "aim_generic.motd.motdtype", FT_UINT16,
BASE_HEX, VALS(aim_snac_generic_motd_motdtypes), 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_numclasses,
{ "Number of Rateinfo Classes", "aim_generic.rateinfo.numclasses", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_windowsize,
{ "Window Size", "aim_generic.rateinfo.class.window_size", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_clearlevel,
{ "Clear Level", "aim_generic.rateinfo.class.clearlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_alertlevel,
{ "Alert Level", "aim_generic.rateinfo.class.alertlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_limitlevel,
{ "Limit Level", "aim_generic.rateinfo.class.limitlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_disconnectlevel,
{ "Disconnect Level", "aim_generic.rateinfo.class.disconnectlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_currentlevel,
{ "Current Level", "aim_generic.rateinfo.class.currentlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_maxlevel,
{ "Max Level", "aim_generic.rateinfo.class.maxlevel", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_lasttime,
{ "Last Time", "aim_generic.rateinfo.class.lasttime", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_curstate,
{ "Current State", "aim_generic.rateinfo.class.curstate", FT_UINT8, BASE_HEX, VALS(rateinfo_states), 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_classid,
{ "Class ID", "aim_generic.rateinfo.class.id", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfo_numpairs,
{ "Number of Family/Subtype pairs", "aim_generic.rateinfo.class.numpairs", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_rateinfoack_group,
{ "Acknowledged Rate Class", "aim_generic.rateinfoack.class", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_ratechange_msg,
{ "Rate Change Message", "aim_generic.ratechange.msg", FT_UINT16, BASE_HEX, VALS(ratechange_msgs), 0x0, NULL, HFILL },
},
{ &hf_generic_migration_numfams,
{ "Number of families to migrate", "aim_generic.migrate.numfams", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_priv_flags,
{ "Privilege flags", "aim_generic.privilege_flags", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_allow_idle_see,
{ "Allow other users to see idle time", "aim_generic.privilege_flags.allow_idle", FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x0001, NULL, HFILL },
},
{ &hf_generic_allow_member_see,
{ "Allow other users to see how long account has been a member", "aim_generic.privilege_flags.allow_member", FT_BOOLEAN, 32, TFS(&tfs_set_notset), 0x0002, NULL, HFILL },
},
{ &hf_generic_selfinfo_warninglevel,
{ "Warning level", "aim_generic.selfinfo.warn_level", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_evil_new_warn_level,
{ "New warning level", "aim_generic.evil.new_warn_level", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_idle_time,
{ "Idle time (seconds)", "aim_generic.idle_time", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_client_ver_req_offset,
{ "Client Verification Request Offset", "aim_generic.client_verification.offset", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_client_ver_req_length,
{ "Client Verification Request Length", "aim_generic.client_verification.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_client_ver_req_hash,
{ "Client Verification MD5 Hash", "aim_generic.client_verification.hash", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL },
},
{ &hf_generic_ext_status_type,
{ "Extended Status Type", "aim_generic.ext_status.type", FT_UINT16, BASE_DEC, VALS(ext_status_types), 0x0, NULL, HFILL },
},
{ &hf_generic_ext_status_flags,
{ "Extended Status Flags", "aim_generic.ext_status.flags", FT_UINT8, BASE_HEX, VALS(ext_status_flags), 0x0, NULL, HFILL },
},
{ &hf_generic_ext_status_length,
{ "Extended Status Length", "aim_generic.ext_status.length", FT_UINT8, BASE_HEX, NULL, 0x0, NULL , HFILL },
},
{ &hf_generic_ext_status_data,
{ "Extended Status Data", "aim_generic.ext_status.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL , HFILL },
},
};
static gint *ett[] = {
&ett_generic,
&ett_generic_migratefamilies,
&ett_generic_rateinfo_class,
&ett_generic_rateinfo_group,
&ett_generic_rateinfo_groups,
&ett_generic_rateinfo_classes,
&ett_generic_clientready,
&ett_generic_clientready_item,
&ett_generic_serverready,
&ett_generic_priv_flags,
};
proto_aim_generic = proto_register_protocol("AIM Generic Service", "AIM Generic", "aim_generic");
proto_register_field_array(proto_aim_generic, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_aim_generic(void)
{
aim_init_family(proto_aim_generic, ett_generic, FAMILY_GENERIC, aim_fnac_family_generic);
}
