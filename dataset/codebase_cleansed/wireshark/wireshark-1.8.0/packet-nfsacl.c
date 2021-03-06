static int
dissect_nfsacl_mask(tvbuff_t *tvb, int offset, proto_tree *tree,
const char *name)
{
guint32 mask;
proto_item *mask_item = NULL;
proto_tree *mask_tree = NULL;
mask = tvb_get_ntohl(tvb, offset + 0);
if (tree)
{
mask_item = proto_tree_add_text(tree, tvb, offset, 4, "%s: 0x%02x",
name, mask);
if (mask_item)
mask_tree = proto_item_add_subtree(mask_item, ett_nfsacl_mask);
}
if (mask_tree)
{
proto_tree_add_text(mask_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(mask, 0x01, 8, "ACL entry",
"(no ACL entry)"));
proto_tree_add_text(mask_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(mask, 0x02, 8, "ACL count",
"(no ACL count)"));
proto_tree_add_text(mask_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(mask, 0x04, 8, "default ACL entry",
"(no default ACL entry)"));
proto_tree_add_text(mask_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(mask, 0x08, 8, "default ACL count",
"(no default ACL count)"));
}
offset += 4;
return offset;
}
static int
dissect_nfsacl_aclent(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree* tree)
{
proto_item *entry_item = NULL;
proto_tree *entry_tree = NULL;
guint32 perm;
proto_item *perm_item = NULL;
proto_tree *perm_tree = NULL;
if (tree)
{
entry_item = proto_tree_add_item(tree, hf_nfsacl_aclent, tvb,
offset + 0, -1, ENC_NA);
entry_tree = proto_item_add_subtree(entry_item, ett_nfsacl_aclent);
}
offset = dissect_rpc_uint32(tvb, entry_tree, hf_nfsacl_aclent_type, offset);
offset = dissect_rpc_uint32(tvb, entry_tree, hf_nfsacl_aclent_uid, offset);
perm = tvb_get_ntohl(tvb, offset);
perm_item = proto_tree_add_uint(entry_tree, hf_nfsacl_aclent_perm,
tvb, offset, 4, perm);
if (perm_item)
perm_tree = proto_item_add_subtree(perm_item, ett_nfsacl_aclent_perm);
if (perm_tree)
{
proto_tree_add_text(perm_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(perm, NA_READ, 4, "READ", "no READ"));
proto_tree_add_text(perm_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(perm, NA_WRITE, 4, "WRITE", "no WRITE"));
proto_tree_add_text(perm_tree, tvb, offset, 4, "%s",
decode_boolean_bitfield(perm, NA_EXEC, 4, "EXEC", "no EXEC"));
}
offset += 4;
return offset;
}
static int
dissect_nfsacl_secattr(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint32 aclcnt, dfaclcnt;
guint32 i;
proto_item *entry_item = NULL;
proto_tree *entry_tree = NULL;
offset = dissect_nfsacl_mask(tvb, offset, tree, "mask");
offset = dissect_rpc_uint32(tvb, tree, hf_nfsacl_aclcnt, offset);
aclcnt = tvb_get_ntohl(tvb, offset);
entry_item = proto_tree_add_text(tree, tvb, offset, 4,
"Total ACL entries: %d", aclcnt);
if (entry_item)
entry_tree = proto_item_add_subtree(entry_item,
ett_nfsacl_aclent_entries);
offset += 4;
if (aclcnt > 0)
{
for (i = 0; i < aclcnt; i++)
offset = dissect_nfsacl_aclent(tvb, offset, pinfo, entry_tree);
}
offset = dissect_rpc_uint32(tvb, tree, hf_nfsacl_dfaclcnt, offset);
dfaclcnt = tvb_get_ntohl(tvb, offset);
entry_item = proto_tree_add_text(tree, tvb, offset, 4,
"Total default ACL entries: %d", dfaclcnt);
if (entry_item)
entry_tree = proto_item_add_subtree(entry_item,
ett_nfsacl_aclent_entries);
offset += 4;
if (dfaclcnt > 0)
{
for (i = 0; i < dfaclcnt; i++)
offset = dissect_nfsacl_aclent(tvb, offset, pinfo, entry_tree);
}
return offset;
}
static int
dissect_nfsacl2_getacl_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
offset = dissect_fhandle(tvb, offset, pinfo, tree, "fhandle", NULL);
offset = dissect_nfsacl_mask(tvb, offset, tree, "mask");
return offset;
}
static int
dissect_nfsacl2_getacl_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint32 status;
status = tvb_get_ntohl(tvb, offset + 0);
proto_tree_add_uint(tree, hf_nfs_nfsstat, tvb, offset + 0, 4, status);
offset += 4;
if (status == ACL2_OK)
{
offset = dissect_fattr(tvb, offset, tree, "attr");
offset = dissect_nfsacl_secattr(tvb, offset, pinfo, tree);
}
return offset;
}
static int
dissect_nfsacl2_setacl_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
offset = dissect_fhandle(tvb, offset, pinfo, tree, "fhandle", NULL);
offset = dissect_nfsacl_secattr(tvb, offset, pinfo, tree);
return offset;
}
static int
dissect_nfsacl2_setacl_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint32 status;
status = tvb_get_ntohl(tvb, offset + 0);
proto_tree_add_uint(tree, hf_nfs_nfsstat, tvb, offset + 0, 4, status);
offset += 4;
if (status == ACL2_OK)
offset = dissect_fattr(tvb, offset, tree, "attr");
return offset;
}
static int
dissect_nfsacl2_getattr_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
offset = dissect_fhandle(tvb, offset, pinfo, tree, "fhandle", NULL);
return offset;
}
static int
dissect_nfsacl2_getattr_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
offset = dissect_fattr(tvb, offset, tree, "attr");
return offset;
}
static int
dissect_nfsacl2_access_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint32 *acc_request, amask;
rpc_call_info_value *civ;
offset = dissect_fhandle(tvb, offset, pinfo, tree, "fhandle", NULL);
amask = tvb_get_ntohl(tvb, offset);
acc_request = se_memdup( &amask, sizeof(guint32));
civ = pinfo->private_data;
civ->private_data = acc_request;
display_access_items(tvb, offset, pinfo, tree, amask, 'C', 3, NULL, "Check") ;
offset+=4;
return offset;
}
static int
dissect_nfsacl2_access_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint32 status;
status = tvb_get_ntohl(tvb, offset + 0);
proto_tree_add_uint(tree, hf_nfs_nfsstat, tvb, offset + 0, 4, status);
offset += 4;
if (status == ACL2_OK)
{
offset = dissect_fattr(tvb, offset, tree, "attr");
offset = dissect_access_reply(tvb, offset, pinfo, tree, 3, NULL);
}
return offset;
}
static int
dissect_nfsacl2_getxattrdir_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_fhandle(tvb, offset, pinfo, tree, "fhandle", NULL);
offset = dissect_rpc_bool(tvb, tree, hf_nfsacl_create, offset);
return offset;
}
static int
dissect_nfsacl2_getxattrdir_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
guint32 status;
status = tvb_get_ntohl(tvb, offset + 0);
proto_tree_add_uint(tree, hf_nfs_nfsstat, tvb, offset + 0, 4, status);
offset += 4;
if (status == ACL2_OK)
{
offset = dissect_fhandle(tvb, offset, pinfo, tree, "fhandle", NULL);
offset = dissect_fattr(tvb, offset, tree, "attr");
}
return offset;
}
static int
dissect_nfsacl3_getacl_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
offset = dissect_nfs_fh3(tvb, offset, pinfo, tree, "fhandle", NULL);
offset = dissect_nfsacl_mask(tvb, offset, tree, "mask");
return offset;
}
static int
dissect_nfsacl3_getacl_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint32 status;
proto_item *entry_item = NULL;
proto_tree *entry_tree = NULL;
status = tvb_get_ntohl(tvb, offset + 0);
if (tree)
proto_tree_add_uint(tree, hf_nfs_nfsstat, tvb, offset + 0, 4,
status);
offset += 4;
if (tree)
{
entry_item = proto_tree_add_item(tree, hf_nfsacl_entry, tvb,
offset + 0, -1, ENC_NA);
if (entry_item)
entry_tree = proto_item_add_subtree(entry_item, ett_nfsacl_entry);
}
if (entry_tree)
offset = dissect_nfs_post_op_attr(tvb, offset, pinfo, entry_tree, "attr");
if (status != ACL3_OK)
return offset;
if (entry_tree)
offset = dissect_nfsacl_secattr(tvb, offset, pinfo, entry_tree);
return offset;
}
static int
dissect_nfsacl3_setacl_call(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
proto_item *acl_item = NULL;
proto_tree *acl_tree = NULL;
offset = dissect_nfs_fh3(tvb, offset, pinfo, tree, "fhandle", NULL);
if (tree)
{
acl_item = proto_tree_add_item(tree, hf_nfsacl_entry, tvb, offset + 0,
-1, ENC_NA);
if (acl_item)
acl_tree = proto_item_add_subtree(acl_item, ett_nfsacl_entry);
}
if (acl_tree)
offset = dissect_nfsacl_secattr(tvb, offset, pinfo, acl_tree);
return offset;
}
static int
dissect_nfsacl3_setacl_reply(tvbuff_t *tvb, int offset, packet_info *pinfo _U_,
proto_tree *tree)
{
guint32 status = tvb_get_ntohl(tvb, offset + 0);
if (tree)
proto_tree_add_uint(tree, hf_nfs_nfsstat, tvb, offset + 0, 4,
status);
offset += 4;
offset = dissect_nfs_post_op_attr(tvb, offset, pinfo, tree, "attr");
return offset;
}
static int
dissect_nfsacl3_getxattrdir_call(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
offset = dissect_nfs_fh3(tvb, offset, pinfo, tree, "fhandle", NULL);
offset = dissect_rpc_bool(tvb, tree, hf_nfsacl_create, offset);
return offset;
}
static int
dissect_nfsacl3_getxattrdir_reply(tvbuff_t *tvb, int offset,
packet_info *pinfo _U_, proto_tree *tree)
{
guint32 status;
status = tvb_get_ntohl(tvb, offset + 0);
if (tree)
proto_tree_add_uint(tree, hf_nfs_nfsstat, tvb, offset + 0, 4,
status);
offset += 4;
if (status == ACL3_OK)
{
offset = dissect_nfs_fh3(tvb, offset, pinfo, tree, "fhandle", NULL);
offset = dissect_nfs_post_op_attr(tvb, offset, pinfo, tree, "attr");
}
return offset;
}
void
proto_register_nfsacl(void)
{
static hf_register_info hf[] = {
{ &hf_nfsacl_procedure_v1, {
"V1 Procedure", "nfsacl.procedure_v1", FT_UINT32, BASE_DEC,
VALS(nfsacl1_proc_vals), 0, NULL, HFILL }},
{ &hf_nfsacl_procedure_v2, {
"V2 Procedure", "nfsacl.procedure_v2", FT_UINT32, BASE_DEC,
VALS(nfsacl2_proc_vals), 0, NULL, HFILL }},
{ &hf_nfsacl_procedure_v3, {
"V3 Procedure", "nfsacl.procedure_v3", FT_UINT32, BASE_DEC,
VALS(nfsacl3_proc_vals), 0, NULL, HFILL }},
{ &hf_nfsacl_entry, {
"ACL", "nfsacl.acl", FT_NONE, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nfsacl_aclcnt, {
"ACL count", "nfsacl.aclcnt", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nfsacl_dfaclcnt, {
"Default ACL count", "nfsacl.dfaclcnt", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nfsacl_aclent, {
"ACL Entry", "nfsacl.aclent", FT_NONE, BASE_NONE,
NULL, 0, "ACL", HFILL }},
{ &hf_nfsacl_aclent_type, {
"Type", "nfsacl.aclent.type", FT_UINT32, BASE_DEC,
VALS(names_nfsacl_aclent_type), 0, NULL, HFILL }},
{ &hf_nfsacl_aclent_uid, {
"UID", "nfsacl.aclent.uid", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nfsacl_aclent_perm, {
"Permissions", "nfsacl.aclent.perm", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_nfsacl_create, {
"create", "nfsacl.create", FT_BOOLEAN, BASE_NONE,
TFS(&tfs_yes_no), 0x0, "Create?", HFILL }},
};
static gint *ett[] = {
&ett_nfsacl,
&ett_nfsacl_mask,
&ett_nfsacl_entry,
&ett_nfsacl_aclent,
&ett_nfsacl_aclent_perm,
&ett_nfsacl_aclent_entries
};
proto_nfsacl = proto_register_protocol("NFSACL", "NFSACL", "nfsacl");
proto_register_field_array(proto_nfsacl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_nfsacl(void)
{
rpc_init_prog(proto_nfsacl, NFSACL_PROGRAM, ett_nfsacl);
rpc_init_proc_table(NFSACL_PROGRAM, 1, nfsacl1_proc, hf_nfsacl_procedure_v1);
rpc_init_proc_table(NFSACL_PROGRAM, 2, nfsacl2_proc, hf_nfsacl_procedure_v2);
rpc_init_proc_table(NFSACL_PROGRAM, 3, nfsacl3_proc, hf_nfsacl_procedure_v3);
}
