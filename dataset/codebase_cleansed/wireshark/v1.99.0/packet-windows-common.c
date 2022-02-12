static gboolean
nt_time_to_nstime(guint32 filetime_high, guint32 filetime_low, nstime_t *tv)
{
guint64 d;
gint64 secs;
int nsecs;
time_t l_time_min = TIME_T_MIN;
time_t l_time_max = TIME_T_MAX;
if (filetime_high == 0)
return FALSE;
d = ((guint64)filetime_high << 32) | filetime_low;
secs = d / 10000000;
nsecs = (int)((d % 10000000)*100);
secs -= TIME_FIXUP_CONSTANT;
if (!(l_time_min <= secs && secs <= l_time_max))
return FALSE;
tv->secs = (time_t) secs;
tv->nsecs = nsecs;
return TRUE;
}
int
dissect_nt_64bit_time(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_date)
{
return dissect_nt_64bit_time_ex(tvb, tree, offset, hf_date, NULL);
}
int
dissect_nt_64bit_time_ex(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_date, proto_item **createdItem)
{
guint32 filetime_high, filetime_low;
nstime_t ts;
if (tree) {
proto_item *item = NULL;
filetime_low = tvb_get_letohl(tvb, offset);
filetime_high = tvb_get_letohl(tvb, offset + 4);
if (filetime_low == 0 && filetime_high == 0) {
item = proto_tree_add_text(tree, tvb, offset, 8,
"%s: No time specified (0)",
proto_registrar_get_name(hf_date));
} else if(filetime_low==0 && filetime_high==0x80000000){
item = proto_tree_add_text(tree, tvb, offset, 8,
"%s: Infinity (relative time)",
proto_registrar_get_name(hf_date));
} else if(filetime_low==0xffffffff && filetime_high==0x7fffffff){
item = proto_tree_add_text(tree, tvb, offset, 8,
"%s: Infinity (absolute time)",
proto_registrar_get_name(hf_date));
} else {
if (nt_time_to_nstime(filetime_high, filetime_low, &ts)) {
item = proto_tree_add_time(tree, hf_date, tvb,
offset, 8, &ts);
} else {
item = proto_tree_add_text(tree, tvb, offset, 8,
"%s: Time can't be converted",
proto_registrar_get_name(hf_date));
}
}
if (createdItem != NULL)
{
*createdItem = item;
}
}
offset += 8;
return offset;
}
static const char*
match_wkwn_sids(const char* sid) {
int i = 0;
while (well_known_sids[i].name) {
if (strcmp(well_known_sids[i].sid, sid)==0) {
return(well_known_sids[i].name);
}
i++;
}
return NULL;
}
int
dissect_nt_sid(tvbuff_t *tvb, int offset, proto_tree *parent_tree,
const char *name, char **sid_str, int hf_sid)
{
int offset_sid_start = offset, sa_offset, rid_offset=0, wkwn_sid1_len=0,
wkwn_sid2_len = 0, i;
guint8 revision, num_auth;
guint32 sa_field, rid=0;
guint64 authority=0;
wmem_strbuf_t *sa_str = NULL, *sid_in_dec_str = NULL, *sid_in_hex_str = NULL, *label_str = NULL,
*domain_str = NULL, *wkwn_sid1_str = NULL, *wkwn_sid2_str = NULL;
const char *mapped_name = NULL, *mapped_rid = NULL;
gboolean domain_sid = FALSE, s_1_5_32 = FALSE, s_1_5_64 = FALSE, locally_defined = FALSE,
S_1_16 = FALSE;
proto_item *item = NULL, *hidden_item;
proto_tree *subtree = NULL;
revision = tvb_get_guint8(tvb, offset);
offset++;
num_auth = tvb_get_guint8(tvb, offset);
offset++;
if(sid_str)
*sid_str=NULL;
if(hf_sid==-1){
if (!parent_tree)
return(offset+(6+(num_auth*4)));
hf_sid=hf_nt_sid;
}
for(i=0; i<6; i++){
authority = (authority << 8) + tvb_get_guint8(tvb, offset);
offset++;
}
sid_in_dec_str = wmem_strbuf_new_label(wmem_packet_scope());
wmem_strbuf_append_printf (sid_in_dec_str, "S-%u-%" G_GINT64_MODIFIER "u", revision, authority);
if (sid_display_hex) {
sid_in_hex_str = wmem_strbuf_new_label(wmem_packet_scope());
wmem_strbuf_append_printf (sid_in_hex_str, "S-%x-%" G_GINT64_MODIFIER "x", revision, authority);
}
wkwn_sid1_str = wmem_strbuf_new_label(wmem_packet_scope());
label_str = wmem_strbuf_new_label(wmem_packet_scope());
if (strcmp(wmem_strbuf_get_str(sid_in_dec_str), "S-1-16")==0)
S_1_16 = TRUE;
if (num_auth==0 || S_1_16) {
mapped_name = match_wkwn_sids(wmem_strbuf_get_str(sid_in_dec_str));
if (mapped_name) {
wmem_strbuf_append(label_str, mapped_name);
wmem_strbuf_append(wkwn_sid1_str,
(sid_display_hex ? wmem_strbuf_get_str(sid_in_hex_str) : wmem_strbuf_get_str(sid_in_dec_str)));
wkwn_sid1_len = 8;
}
}
sa_offset = offset;
sa_str = wmem_strbuf_new_label(wmem_packet_scope());
wkwn_sid2_str = wmem_strbuf_new_label(wmem_packet_scope());
domain_str = wmem_strbuf_new_label(wmem_packet_scope());
for(i=1; i<num_auth+1; i++) {
sa_field = tvb_get_letohl(tvb, offset);
wmem_strbuf_append_printf(sid_in_dec_str, "-%u", sa_field);
wmem_strbuf_append_printf(sa_str,
(i==1 ? (sid_display_hex ? "%x" : "%u") : (sid_display_hex ? "-%x" : "-%u")),
sa_field);
if (sid_display_hex)
wmem_strbuf_append_printf(sid_in_hex_str, "-%x", sa_field);
if (i==1) {
if (S_1_16) {
mapped_rid = match_wkwn_sids(wmem_strbuf_get_str(sid_in_dec_str));
if (mapped_rid) {
wmem_strbuf_append_printf(label_str, "%s-%s", mapped_name, mapped_rid);
rid = sa_field;
rid_offset = offset;
wmem_strbuf_append(wkwn_sid2_str,
(sid_display_hex ? wmem_strbuf_get_str(sid_in_hex_str) : wmem_strbuf_get_str(sid_in_dec_str)));
wkwn_sid1_len=12; }
} else {
mapped_name = match_wkwn_sids(wmem_strbuf_get_str(sid_in_dec_str));
if (mapped_name) {
wmem_strbuf_append(label_str, mapped_name);
wmem_strbuf_append(wkwn_sid1_str,
(sid_display_hex ? wmem_strbuf_get_str(sid_in_hex_str) : wmem_strbuf_get_str(sid_in_dec_str)));
wkwn_sid1_len = 12;
}
if (strcmp(wmem_strbuf_get_str(sid_in_dec_str), "S-1-5-21")==0) {
domain_sid = TRUE;
} else if (strcmp(wmem_strbuf_get_str(sid_in_dec_str), "S-1-5-32")==0) {
s_1_5_32 = TRUE;
} else if (strcmp(wmem_strbuf_get_str(sid_in_dec_str), "S-1-5-64")==0) {
s_1_5_64 = TRUE;
}
}
} else if (i==2 && !domain_sid) {
if (s_1_5_32 || s_1_5_64) {
mapped_rid = match_wkwn_sids(wmem_strbuf_get_str(sid_in_dec_str));
if (mapped_rid) {
wmem_strbuf_append_printf(label_str, "-%s", mapped_rid);
rid = sa_field;
rid_offset = offset;
wmem_strbuf_append(wkwn_sid2_str,
(sid_display_hex ? wmem_strbuf_get_str(sid_in_hex_str) : wmem_strbuf_get_str(sid_in_dec_str)));
wkwn_sid2_len=16;
} else {
locally_defined = TRUE;
}
} else {
if (mapped_name) {
locally_defined = TRUE;
}
}
} else {
if (domain_sid) {
if (num_auth >= 4) {
if (i >= 2 && i <=4 ) {
wmem_strbuf_append_printf(domain_str,
(i==2 ? (sid_display_hex ? "%x" : "%u") : (sid_display_hex ? "-%x" : "-%u")), sa_field);
} else if (i==5) {
rid = sa_field;
rid_offset = offset;
mapped_rid = val_to_str_ext_const(rid, &wkwn_S_1_5_21_rids_ext, "Domain RID");
wmem_strbuf_append_printf(label_str, "-%s", mapped_rid);
} else {
locally_defined = TRUE;
}
} else {
mapped_name = "Corrupt domain SID";
}
} else {
if (mapped_name) {
locally_defined = TRUE;
}
}
}
offset+=4;
}
if ( !(mapped_name || domain_sid || s_1_5_32 || s_1_5_64) ) {
if (sid_name_snooping) {
mapped_name = find_sid_name(wmem_strbuf_get_str(sid_in_dec_str));
} else {
mapped_name = "<Unknown SID type>";
}
}
if (locally_defined) {
wmem_strbuf_append_printf(label_str, "-<locally defined>");
}
item = proto_tree_add_string_format(
parent_tree, hf_sid, tvb, offset_sid_start, (offset - offset_sid_start),
(sid_display_hex ? wmem_strbuf_get_str(sid_in_hex_str) : wmem_strbuf_get_str(sid_in_dec_str)),
"%s: %s", name, (sid_display_hex ? wmem_strbuf_get_str(sid_in_hex_str) : wmem_strbuf_get_str(sid_in_dec_str))
);
proto_item_append_text(item, " (%s)", wmem_strbuf_get_str(label_str));
subtree = proto_item_add_subtree(item, ett_nt_sid);
proto_tree_add_item(subtree, hf_nt_sid_revision, tvb, offset_sid_start, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(subtree, hf_nt_sid_num_auth, tvb, offset_sid_start+1, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_uint64_format_value(subtree,
(sid_display_hex ? hf_nt_sid_auth_hex : hf_nt_sid_auth_dec),
tvb, offset_sid_start+2, 6, authority, "%" G_GINT64_MODIFIER "u", authority);
proto_tree_add_string_format_value(subtree, hf_nt_sid_subauth, tvb, sa_offset,
num_auth*4, wmem_strbuf_get_str(sa_str), "%s", wmem_strbuf_get_str(sa_str));
if (rid) {
item = proto_tree_add_item (subtree,
(sid_display_hex ? hf_nt_sid_rid_hex : hf_nt_sid_rid_dec), tvb, rid_offset, 4, ENC_LITTLE_ENDIAN);
proto_item_append_text(item, " (%s)", mapped_rid);
}
if (wmem_strbuf_get_len(wkwn_sid1_str) > 0) {
hidden_item = proto_tree_add_string_format_value(
subtree, hf_nt_sid_wkwn, tvb, offset_sid_start, wkwn_sid1_len,
wmem_strbuf_get_str(wkwn_sid1_str), "%s", wmem_strbuf_get_str(wkwn_sid1_str));
proto_item_append_text(hidden_item, " (%s)", mapped_name);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (wmem_strbuf_get_len(wkwn_sid2_str) > 0) {
hidden_item = proto_tree_add_string_format_value(
subtree, hf_nt_sid_wkwn, tvb, offset_sid_start, wkwn_sid2_len,
wmem_strbuf_get_str(wkwn_sid2_str), "%s", wmem_strbuf_get_str(wkwn_sid2_str));
proto_item_append_text(hidden_item, " (%s)", wmem_strbuf_get_str(label_str));
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (domain_sid && wmem_strbuf_get_len(domain_str) > 0) {
hidden_item = proto_tree_add_string_format_value(
subtree, hf_nt_sid_domain, tvb, offset_sid_start + 12, 12,
wmem_strbuf_get_str(domain_str), "%s", wmem_strbuf_get_str(domain_str));
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if(sid_str){
if(mapped_name){
*sid_str = wmem_strdup_printf(wmem_packet_scope(), "%s (%s)",
(sid_display_hex ? wmem_strbuf_get_str(sid_in_hex_str) : wmem_strbuf_get_str(sid_in_dec_str)), wmem_strbuf_get_str(label_str));
} else {
*sid_str = wmem_strdup(wmem_packet_scope(), sid_display_hex ? wmem_strbuf_get_str(sid_in_hex_str) : wmem_strbuf_get_str(sid_in_dec_str));
}
if(!(*sid_str)){
*sid_str=wmem_strdup(wmem_packet_scope(), "corrupted SID");
}
}
return offset;
}
static void map_generic_access(guint32 *access_mask,
struct generic_mapping *mapping)
{
if (*access_mask & GENERIC_READ_ACCESS) {
*access_mask &= ~GENERIC_READ_ACCESS;
*access_mask |= mapping->generic_read;
}
if (*access_mask & GENERIC_WRITE_ACCESS) {
*access_mask &= ~GENERIC_WRITE_ACCESS;
*access_mask |= mapping->generic_write;
}
if (*access_mask & GENERIC_EXECUTE_ACCESS) {
*access_mask &= ~GENERIC_EXECUTE_ACCESS;
*access_mask |= mapping->generic_execute;
}
if (*access_mask & GENERIC_ALL_ACCESS) {
*access_mask &= ~GENERIC_ALL_ACCESS;
*access_mask |= mapping->generic_all;
}
}
static void map_standard_access(guint32 *access_mask,
struct standard_mapping *mapping)
{
if (*access_mask & READ_CONTROL_ACCESS) {
*access_mask &= ~READ_CONTROL_ACCESS;
*access_mask |= mapping->std_read;
}
if (*access_mask & (DELETE_ACCESS|WRITE_DAC_ACCESS|WRITE_OWNER_ACCESS|
SYNCHRONIZE_ACCESS)) {
*access_mask &= ~(DELETE_ACCESS|WRITE_DAC_ACCESS|
WRITE_OWNER_ACCESS|SYNCHRONIZE_ACCESS);
*access_mask |= mapping->std_all;
}
}
int
dissect_nt_access_mask(tvbuff_t *tvb, gint offset, packet_info *pinfo,
proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex,
struct access_mask_info *ami, guint32 *perms)
{
proto_item *item;
proto_tree *subtree, *generic_tree, *standard_tree, *specific_tree;
guint32 access;
if (drep != NULL) {
offset = dissect_ndr_uint32(tvb, offset, pinfo, NULL, di, drep,
hfindex, &access);
} else {
access = tvb_get_letohl(tvb, offset);
offset += 4;
}
if (perms) {
*perms = access;
}
item = proto_tree_add_uint(tree, hfindex, tvb, offset - 4, 4, access);
subtree = proto_item_add_subtree(item, ett_nt_access_mask);
item = proto_tree_add_text(subtree, tvb, offset - 4, 4,
"Generic rights: 0x%08x",
access & GENERIC_RIGHTS_MASK);
generic_tree = proto_item_add_subtree(
item, ett_nt_access_mask_generic);
proto_tree_add_boolean(
generic_tree, hf_access_generic_read, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
generic_tree, hf_access_generic_write, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
generic_tree, hf_access_generic_execute, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
generic_tree, hf_access_generic_all, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
subtree, hf_access_maximum_allowed, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
subtree, hf_access_sacl, tvb, offset - 4, 4,
access);
item = proto_tree_add_text(subtree, tvb, offset - 4, 4,
"Standard rights: 0x%08x",
access & STANDARD_RIGHTS_MASK);
standard_tree = proto_item_add_subtree(
item, ett_nt_access_mask_standard);
proto_tree_add_boolean(
standard_tree, hf_access_standard_synchronise, tvb,
offset - 4, 4, access);
proto_tree_add_boolean(
standard_tree, hf_access_standard_write_owner, tvb,
offset - 4, 4, access);
proto_tree_add_boolean(
standard_tree, hf_access_standard_write_dac, tvb,
offset - 4, 4, access);
proto_tree_add_boolean(
standard_tree, hf_access_standard_read_control, tvb,
offset - 4, 4, access);
proto_tree_add_boolean(
standard_tree, hf_access_standard_delete, tvb, offset - 4, 4,
access);
if (ami && ami->specific_rights_name)
item = proto_tree_add_text(subtree, tvb, offset - 4, 4,
"%s specific rights: 0x%08x",
ami->specific_rights_name,
access & SPECIFIC_RIGHTS_MASK);
else
item = proto_tree_add_text(subtree, tvb, offset - 4, 4,
"Specific rights: 0x%08x",
access & SPECIFIC_RIGHTS_MASK);
specific_tree = proto_item_add_subtree(
item, ett_nt_access_mask_specific);
if (ami && ami->specific_rights_fn) {
guint32 mapped_access = access;
proto_tree *specific_mapped;
specific_mapped = proto_item_add_subtree(
item, ett_nt_access_mask_specific);
ami->specific_rights_fn(
tvb, offset - 4, specific_tree, access);
if (ami->generic_mapping)
map_generic_access(&access, ami->generic_mapping);
if (ami->standard_mapping)
map_standard_access(&access, ami->standard_mapping);
if (access != mapped_access) {
ami->specific_rights_fn(
tvb, offset - 4, specific_mapped,
mapped_access);
}
return offset;
}
proto_tree_add_boolean(
specific_tree, hf_access_specific_15, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_14, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_13, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_12, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_11, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_10, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_9, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_8, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_7, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_6, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_5, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_4, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_3, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_2, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_1, tvb, offset - 4, 4,
access);
proto_tree_add_boolean(
specific_tree, hf_access_specific_0, tvb, offset - 4, 4,
access);
return offset;
}
static int
dissect_nt_ace_object(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_item *item;
proto_tree *tree;
proto_item *flags_item;
proto_tree *flags_tree;
guint32 flags;
int old_offset=offset;
const char *sep = " ";
tree = proto_tree_add_subtree(parent_tree, tvb, offset, 0,
ett_nt_ace_object, &item, "ACE Object");
flags=tvb_get_letohl(tvb, offset);
flags_item = proto_tree_add_text(tree, tvb, offset, 4,
"ACE Object Flags (0x%08x)", flags);
flags_tree = proto_item_add_subtree(flags_item, ett_nt_ace_object_flags);
proto_tree_add_boolean(flags_tree, hf_nt_ace_flags_object_type_present,
tvb, offset, 4, flags);
APPEND_ACE_TEXT(flags&0x00000001, flags_item, "%sObject Type Present");
proto_tree_add_boolean(flags_tree, hf_nt_ace_flags_inherited_object_type_present,
tvb, offset, 4, flags);
APPEND_ACE_TEXT(flags&0x00000002, flags_item, "%sInherited Object Type Present");
offset+=4;
if(flags&0x00000001){
proto_tree_add_item(tree, hf_nt_ace_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset+=16;
}
if(flags&0x00000002){
proto_tree_add_item(tree, hf_nt_ace_inherited_guid, tvb, offset, 16, ENC_LITTLE_ENDIAN);
offset+=16;
}
proto_item_set_len(item, offset-old_offset);
return offset;
}
static int
dissect_nt_v2_ace_flags(tvbuff_t *tvb, int offset, proto_tree *parent_tree,
guint8 *data)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint8 mask;
const char *sep = " ";
mask = tvb_get_guint8(tvb, offset);
if (data)
*data = mask;
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 1,
"NT ACE Flags: 0x%02x", mask);
tree = proto_item_add_subtree(item, ett_nt_ace_flags);
}
proto_tree_add_boolean(tree, hf_nt_ace_flags_failed_access,
tvb, offset, 1, mask);
APPEND_ACE_TEXT(mask&0x80, item, "%sFailed Access");
proto_tree_add_boolean(tree, hf_nt_ace_flags_successful_access,
tvb, offset, 1, mask);
APPEND_ACE_TEXT(mask&0x40, item, "%sSuccessful Access");
proto_tree_add_boolean(tree, hf_nt_ace_flags_inherited_ace,
tvb, offset, 1, mask);
APPEND_ACE_TEXT(mask&0x10, item, "%sInherited ACE");
proto_tree_add_boolean(tree, hf_nt_ace_flags_inherit_only,
tvb, offset, 1, mask);
APPEND_ACE_TEXT(mask&0x08, item, "%sInherit Only");
proto_tree_add_boolean(tree, hf_nt_ace_flags_non_propagate_inherit,
tvb, offset, 1, mask);
APPEND_ACE_TEXT(mask&0x04, item, "%sNo Propagate Inherit");
proto_tree_add_boolean(tree, hf_nt_ace_flags_container_inherit,
tvb, offset, 1, mask);
APPEND_ACE_TEXT(mask&0x02, item, "%sContainer Inherit");
proto_tree_add_boolean(tree, hf_nt_ace_flags_object_inherit,
tvb, offset, 1, mask);
APPEND_ACE_TEXT(mask&0x01, item, "%sObject Inherit");
offset += 1;
return offset;
}
static int
dissect_nt_v2_ace(tvbuff_t *tvb, int offset, packet_info *pinfo,
proto_tree *parent_tree, guint8 *drep,
struct access_mask_info *ami)
{
proto_item *item;
proto_tree *tree;
int old_offset = offset;
char *sid_str = NULL;
guint16 size;
guint8 type;
guint8 flags;
guint32 perms = 0;
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_nt_ace, &item, "NT ACE: ");
type = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(tree, hf_nt_ace_type, tvb, offset, 1, type);
offset += 1;
offset = dissect_nt_v2_ace_flags(tvb, offset, tree, &flags);
size = tvb_get_letohs(tvb, offset);
if (size < 4) {
proto_tree_add_uint_format_value(tree, hf_nt_ace_size, tvb, offset, 2,
size, "%u (bogus, must be >= 4)", size);
return old_offset;
}
proto_tree_add_uint(tree, hf_nt_ace_size, tvb, offset, 2, size);
offset += 2;
switch(type){
case ACE_TYPE_ACCESS_ALLOWED:
case ACE_TYPE_ACCESS_DENIED:
case ACE_TYPE_SYSTEM_AUDIT:
case ACE_TYPE_SYSTEM_ALARM:
case ACE_TYPE_ALLOWED_COMPOUND:
case ACE_TYPE_ACCESS_ALLOWED_OBJECT:
case ACE_TYPE_ACCESS_DENIED_OBJECT:
case ACE_TYPE_SYSTEM_AUDIT_OBJECT:
case ACE_TYPE_SYSTEM_ALARM_OBJECT:
case ACE_TYPE_ACCESS_ALLOWED_CALLBACK:
case ACE_TYPE_ACCESS_DENIED_CALLBACK:
case ACE_TYPE_ACCESS_ALLOWED_CALLBACK_OBJECT:
case ACE_TYPE_ACCESS_DENIED_CALLBACK_OBJECT:
case ACE_TYPE_SYSTEM_AUDIT_CALLBACK:
case ACE_TYPE_SYSTEM_ALARM_CALLBACK:
case ACE_TYPE_SYSTEM_AUDIT_CALLBACK_OBJECT:
case ACE_TYPE_SYSTEM_ALARM_CALLBACK_OBJECT:
case ACE_TYPE_SYSTEM_MANDATORY_LABEL:
offset = dissect_nt_access_mask(
tvb, offset, pinfo, tree, NULL, drep,
hf_nt_access_mask, ami, &perms);
switch(type){
case ACE_TYPE_ACCESS_ALLOWED_OBJECT:
case ACE_TYPE_ACCESS_DENIED_OBJECT:
case ACE_TYPE_SYSTEM_AUDIT_OBJECT:
case ACE_TYPE_SYSTEM_ALARM_OBJECT:
case ACE_TYPE_ACCESS_ALLOWED_CALLBACK_OBJECT:
case ACE_TYPE_ACCESS_DENIED_CALLBACK_OBJECT:
case ACE_TYPE_SYSTEM_AUDIT_CALLBACK_OBJECT:
case ACE_TYPE_SYSTEM_ALARM_CALLBACK_OBJECT:
offset=dissect_nt_ace_object(tvb, offset, tree);
}
offset = dissect_nt_sid(tvb, offset, tree, "SID", &sid_str, -1);
if (item)
proto_item_append_text(
item, "%s, flags 0x%02x, %s, mask 0x%08x", sid_str, flags,
val_to_str(type, ace_type_vals, "Unknown ACE type (0x%02x)"),
perms);
break;
};
proto_item_set_len(item, offset-old_offset);
return old_offset + size;
}
static int
dissect_nt_acl(tvbuff_t *tvb, int offset_a, packet_info *pinfo,
proto_tree *parent_tree, guint8 *drep, const char *name,
struct access_mask_info *ami)
{
proto_item *item;
proto_tree *tree;
int old_offset = offset_a;
int pre_ace_offset;
guint16 revision;
volatile guint32 num_aces;
volatile int offset_v = offset_a;
volatile gboolean missing_data = FALSE;
volatile gboolean bad_ace = FALSE;
tree = proto_tree_add_subtree_format(parent_tree, tvb, offset_v, -1,
ett_nt_acl, &item, "NT %s ACL", name);
revision = tvb_get_letohs(tvb, offset_v);
proto_tree_add_uint(tree, hf_nt_acl_revision,
tvb, offset_v, 2, revision);
offset_v += 2;
switch(revision){
case ACL_REVISION_NT4:
case ACL_REVISION_ADS:
case 3:
proto_tree_add_item(tree, hf_nt_acl_size, tvb, offset_v, 2, ENC_LITTLE_ENDIAN);
offset_v += 2;
num_aces = tvb_get_letohl(tvb, offset_v);
proto_tree_add_uint(tree, hf_nt_acl_num_aces,
tvb, offset_v, 4, num_aces);
offset_v += 4;
while(num_aces-- && !missing_data && !bad_ace) {
pre_ace_offset = offset_v;
TRY {
offset_v = dissect_nt_v2_ace(tvb, offset_v, pinfo, tree, drep, ami);
if (pre_ace_offset == offset_v) {
bad_ace = TRUE;
}
}
CATCH(BoundsError) {
proto_tree_add_text(tree, tvb, offset_v, 0, "ACE Extends beyond end of captured data");
missing_data = TRUE;
}
CATCH(ReportedBoundsError) {
proto_tree_add_text(tree, tvb, offset_v, 0, "ACE Extends beyond end of reassembled data");
missing_data = TRUE;
}
ENDTRY;
}
}
proto_item_set_len(item, offset_v-old_offset);
return offset_v;
}
static int
dissect_nt_sec_desc_type(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 mask;
mask = tvb_get_letohs(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 2,
"Type: 0x%04x", mask);
tree = proto_item_add_subtree(item, ett_nt_sec_desc_type);
}
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_self_relative,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_rm_control_valid,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_sacl_protected,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_dacl_protected,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_sacl_auto_inherited,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_dacl_auto_inherited,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_sacl_auto_inherit_req,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_dacl_auto_inherit_req,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_server_security,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_dacl_trusted,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_sacl_defaulted,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_sacl_present,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_dacl_defaulted,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_dacl_present,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree,hf_nt_sec_desc_type_group_defaulted,
tvb, offset, 2, mask);
proto_tree_add_boolean(tree, hf_nt_sec_desc_type_owner_defaulted,
tvb, offset, 2, mask);
offset += 2;
return offset;
}
int
dissect_nt_security_information(tvbuff_t *tvb, int offset, proto_tree *parent_tree)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint32 mask;
mask = tvb_get_letohl(tvb, offset);
if(parent_tree){
item = proto_tree_add_text(parent_tree, tvb, offset, 4,
"SEC INFO: 0x%08x", mask);
tree = proto_item_add_subtree(item, ett_nt_security_information);
}
proto_tree_add_boolean(tree,hf_nt_security_information_sacl,
tvb, offset, 4, mask);
if (mask & 0x00000008) {
proto_item_append_text(item, " SACL");
}
proto_tree_add_boolean(tree,hf_nt_security_information_dacl,
tvb, offset, 4, mask);
if (mask & 0x00000004) {
proto_item_append_text(item, " DACL");
}
proto_tree_add_boolean(tree,hf_nt_security_information_group,
tvb, offset, 4, mask);
if (mask & 0x00000002) {
proto_item_append_text(item, " GROUP");
}
proto_tree_add_boolean(tree,hf_nt_security_information_owner,
tvb, offset, 4, mask);
if (mask & 0x00000001) {
proto_item_append_text(item, " OWNER");
}
offset += 4;
return offset;
}
int
dissect_nt_sec_desc(tvbuff_t *tvb, int offset_a, packet_info *pinfo,
proto_tree *parent_tree, guint8 *drep,
gboolean len_supplied _U_, int len,
struct access_mask_info *ami)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
guint16 revision;
int start_offset = offset_a;
volatile int offset_v=offset_a;
volatile int end_offset;
volatile int item_offset;
guint32 owner_sid_offset;
volatile guint32 group_sid_offset;
volatile guint32 sacl_offset;
volatile guint32 dacl_offset;
tree = proto_tree_add_subtree(parent_tree, tvb, offset_v, -1,
ett_nt_sec_desc, &item, "NT Security Descriptor");
revision = tvb_get_letohs(tvb, offset_v);
proto_tree_add_uint(tree, hf_nt_sec_desc_revision,
tvb, offset_v, 2, revision);
offset_v += 2;
switch(revision){
case 1:
offset_v = dissect_nt_sec_desc_type(tvb, offset_v, tree);
owner_sid_offset = tvb_get_letohl(tvb, offset_v);
if(owner_sid_offset != 0 && owner_sid_offset < 20){
proto_tree_add_text(tree, tvb, offset_v, 4, "Offset to owner SID: %u (bogus, must be >= 20)", owner_sid_offset);
owner_sid_offset = 0;
} else
proto_tree_add_text(tree, tvb, offset_v, 4, "Offset to owner SID: %u", owner_sid_offset);
offset_v += 4;
group_sid_offset = tvb_get_letohl(tvb, offset_v);
if(group_sid_offset != 0 && group_sid_offset < 20){
proto_tree_add_text(tree, tvb, offset_v, 4, "Offset to group SID: %u (bogus, must be >= 20)", group_sid_offset);
group_sid_offset = 0;
} else
proto_tree_add_text(tree, tvb, offset_v, 4, "Offset to group SID: %u", group_sid_offset);
offset_v += 4;
sacl_offset = tvb_get_letohl(tvb, offset_v);
if(sacl_offset != 0 && sacl_offset < 20){
proto_tree_add_text(tree, tvb, offset_v, 4, "Offset to SACL: %u (bogus, must be >= 20)", sacl_offset);
sacl_offset = 0;
} else
proto_tree_add_text(tree, tvb, offset_v, 4, "Offset to SACL: %u", sacl_offset);
offset_v += 4;
dacl_offset = tvb_get_letohl(tvb, offset_v);
if(dacl_offset != 0 && dacl_offset < 20){
proto_tree_add_text(tree, tvb, offset_v, 4, "Offset to DACL: %u (bogus, must be >= 20)", dacl_offset);
dacl_offset = 0;
} else
proto_tree_add_text(tree, tvb, offset_v, 4, "Offset to DACL: %u", dacl_offset);
offset_v += 4;
end_offset = offset_v;
if(owner_sid_offset){
item_offset = start_offset+owner_sid_offset;
if (item_offset < start_offset) {
THROW(ReportedBoundsError);
}
TRY{
offset_v = dissect_nt_sid(tvb, item_offset, tree, "Owner", NULL, -1);
if (offset_v > end_offset)
end_offset = offset_v;
}
CATCH(BoundsError) {
proto_tree_add_text(tree, tvb, item_offset, 0, "Owner SID beyond end of captured data");
}
CATCH(ReportedBoundsError) {
proto_tree_add_text(tree, tvb, item_offset, 0, "Owner SID beyond end of reassembled data");
}
ENDTRY;
}
if(group_sid_offset){
item_offset = start_offset+group_sid_offset;
if (item_offset < start_offset) {
THROW(ReportedBoundsError);
}
TRY {
offset_v = dissect_nt_sid(tvb, item_offset, tree, "Group", NULL, -1);
if (offset_v > end_offset)
end_offset = offset_v;
}
CATCH(BoundsError) {
proto_tree_add_text(tree, tvb, item_offset, 0, "Group SID beyond end of captured data");
}
CATCH(ReportedBoundsError) {
proto_tree_add_text(tree, tvb, item_offset, 0, "Group SID beyond end of reassembled data");
}
ENDTRY;
}
if(sacl_offset){
item_offset = start_offset+sacl_offset;
if (item_offset < start_offset) {
THROW(ReportedBoundsError);
}
offset_v = dissect_nt_acl(tvb, item_offset, pinfo, tree,
drep, "System (SACL)", ami);
if (offset_v > end_offset)
end_offset = offset_v;
}
if(dacl_offset){
item_offset = start_offset+dacl_offset;
if (item_offset < start_offset) {
THROW(ReportedBoundsError);
}
offset_v = dissect_nt_acl(tvb, item_offset, pinfo, tree,
drep, "User (DACL)", ami);
if (offset_v > end_offset)
end_offset = offset_v;
}
break;
default:
end_offset = offset_v;
break;
}
len = end_offset - start_offset;
proto_item_set_len(item, len);
return offset_v;
}
void
proto_do_register_windows_common(int proto_smb)
{
static hf_register_info hf[] = {
{ &hf_nt_sec_desc_revision,
{ "Revision", "nt.sec_desc.revision", FT_UINT16, BASE_DEC,
NULL, 0, "Version of NT Security Descriptor structure", HFILL }},
{ &hf_nt_sec_desc_type_owner_defaulted,
{ "Owner Defaulted", "nt.sec_desc.type.owner_defaulted", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_owner_defaulted), 0x0001, "Is Owner Defaulted set?", HFILL }},
{ &hf_nt_sec_desc_type_group_defaulted,
{ "Group Defaulted", "nt.sec_desc.type.group_defaulted", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_group_defaulted), 0x0002, "Is Group Defaulted?", HFILL }},
{ &hf_nt_sec_desc_type_dacl_present,
{ "DACL Present", "nt.sec_desc.type.dacl_present", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_dacl_present), 0x0004, "Does this SecDesc have DACL present?", HFILL }},
{ &hf_nt_sec_desc_type_dacl_defaulted,
{ "DACL Defaulted", "nt.sec_desc.type.dacl_defaulted", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_dacl_defaulted), 0x0008, "Does this SecDesc have DACL Defaulted?", HFILL }},
{ &hf_nt_sec_desc_type_sacl_present,
{ "SACL Present", "nt.sec_desc.type.sacl_present", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_sacl_present), 0x0010, "Is the SACL present?", HFILL }},
{ &hf_nt_sec_desc_type_sacl_defaulted,
{ "SACL Defaulted", "nt.sec_desc.type.sacl_defaulted", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_sacl_defaulted), 0x0020, "Does this SecDesc have SACL Defaulted?", HFILL }},
{ &hf_nt_sec_desc_type_dacl_auto_inherit_req,
{ "DACL Auto Inherit Required", "nt.sec_desc.type.dacl_auto_inherit_req", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_dacl_auto_inherit_req), 0x0100, "Does this SecDesc have DACL Auto Inherit Required set?", HFILL }},
{ &hf_nt_sec_desc_type_dacl_trusted,
{ "DACL Trusted", "nt.sec_desc.type.dacl_trusted", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_dacl_trusted), 0x0040, "Does this SecDesc have DACL TRUSTED set?", HFILL }},
{ &hf_nt_sec_desc_type_server_security,
{ "Server Security", "nt.sec_desc.type.server_security", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_server_security), 0x0080, "Does this SecDesc have SERVER SECURITY set?", HFILL }},
{ &hf_nt_sec_desc_type_sacl_auto_inherit_req,
{ "SACL Auto Inherit Required", "nt.sec_desc.type.sacl_auto_inherit_req", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_sacl_auto_inherit_req), 0x0200, "Does this SecDesc have SACL Auto Inherit Required set?", HFILL }},
{ &hf_nt_sec_desc_type_dacl_auto_inherited,
{ "DACL Auto Inherited", "nt.sec_desc.type.dacl_auto_inherited", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_dacl_auto_inherited), 0x0400, "Is this DACL auto inherited", HFILL }},
{ &hf_nt_sec_desc_type_sacl_auto_inherited,
{ "SACL Auto Inherited", "nt.sec_desc.type.sacl_auto_inherited", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_sacl_auto_inherited), 0x0800, "Is this SACL auto inherited", HFILL }},
{ &hf_nt_sec_desc_type_dacl_protected,
{ "DACL Protected", "nt.sec_desc.type.dacl_protected", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_dacl_protected), 0x1000, "Is the DACL structure protected?", HFILL }},
{ &hf_nt_sec_desc_type_sacl_protected,
{ "SACL Protected", "nt.sec_desc.type.sacl_protected", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_sacl_protected), 0x2000, "Is the SACL structure protected?", HFILL }},
{ &hf_nt_sec_desc_type_self_relative,
{ "Self Relative", "nt.sec_desc.type.self_relative", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_self_relative), 0x8000, "Is this SecDesc self relative?", HFILL }},
{ &hf_nt_sec_desc_type_rm_control_valid,
{ "RM Control Valid", "nt.sec_desc.type.rm_control_valid", FT_BOOLEAN, 16,
TFS(&tfs_sec_desc_type_rm_control_valid), 0x4000, "Is RM Control Valid set?", HFILL }},
{ &hf_nt_sid,
{ "SID", "nt.sid", FT_STRING, BASE_NONE,
NULL, 0, "SID: Security Identifier", HFILL }},
{ &hf_nt_sid_revision,
{ "Revision", "nt.sid.revision", FT_UINT8, BASE_DEC,
NULL, 0, "Version of SID structure", HFILL }},
{ &hf_nt_sid_num_auth,
{ "Num Auth", "nt.sid.num_auth", FT_UINT8, BASE_DEC,
NULL, 0, "Number of authorities for this SID", HFILL }},
{ &hf_nt_sid_auth_dec,
{ "Authority", "nt.sid.auth", FT_UINT64, BASE_DEC,
NULL, 0, "Identifier Authority", HFILL }},
{ &hf_nt_sid_auth_hex,
{ "Authority", "nt.sid.auth", FT_UINT64, BASE_HEX,
NULL, 0, "Identifier Authority", HFILL }},
{ &hf_nt_sid_subauth,
{ "Subauthorities", "nt.sid.subauth", FT_STRING, BASE_NONE,
NULL, 0, "Subauthorities fields", HFILL }},
{ &hf_nt_sid_rid_dec,
{ "RID", "nt.sid.rid", FT_UINT32, BASE_DEC,
NULL, 0, "Relative IDentifier: identifies a user or group", HFILL }},
{ &hf_nt_sid_rid_hex,
{ "RID", "nt.sid.rid", FT_UINT32, BASE_HEX,
NULL, 0, "Relative IDentifier: identifies a user or group", HFILL }},
{ &hf_nt_sid_wkwn,
{ "Well-known SID", "nt.sid.wkwn", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nt_sid_domain,
{ "Domain", "nt.sid.domain", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nt_acl_revision,
{ "Revision", "nt.acl.revision", FT_UINT16, BASE_DEC,
VALS(acl_revision_vals), 0, "Version of NT ACL structure", HFILL }},
{ &hf_nt_acl_size,
{ "Size", "nt.acl.size", FT_UINT16, BASE_DEC,
NULL, 0, "Size of NT ACL structure", HFILL }},
{ &hf_nt_acl_num_aces,
{ "Num ACEs", "nt.acl.num_aces", FT_UINT32, BASE_DEC,
NULL, 0, "Number of ACE structures for this ACL", HFILL }},
{ &hf_nt_ace_type,
{ "Type", "nt.ace.type",
FT_UINT8, BASE_DEC, VALS(ace_type_vals), 0, "Type of ACE",
HFILL }},
{ &hf_nt_ace_size,
{ "Size", "nt.ace.size", FT_UINT16, BASE_DEC, NULL, 0,
"Size of this ACE", HFILL }},
{ &hf_nt_ace_flags_object_inherit,
{ "Object Inherit", "nt.ace.flags.object_inherit", FT_BOOLEAN, 8,
TFS(&tfs_ace_flags_object_inherit), 0x01, "Will subordinate files inherit this ACE?", HFILL }},
{ &hf_nt_ace_flags_container_inherit,
{ "Container Inherit", "nt.ace.flags.container_inherit", FT_BOOLEAN, 8,
TFS(&tfs_ace_flags_container_inherit), 0x02, "Will subordinate containers inherit this ACE?", HFILL }},
{ &hf_nt_ace_flags_non_propagate_inherit,
{ "Non-Propagate Inherit", "nt.ace.flags.non_propagate_inherit", FT_BOOLEAN, 8,
TFS(&tfs_ace_flags_non_propagate_inherit), 0x04, "Will subordinate object propagate this ACE further?", HFILL }},
{ &hf_nt_ace_flags_inherit_only,
{ "Inherit Only", "nt.ace.flags.inherit_only", FT_BOOLEAN, 8,
TFS(&tfs_ace_flags_inherit_only), 0x08, "Does this ACE apply to the current object?", HFILL }},
{ &hf_nt_ace_flags_inherited_ace,
{ "Inherited ACE", "nt.ace.flags.inherited_ace", FT_BOOLEAN, 8,
TFS(&tfs_ace_flags_inherited_ace), 0x10, "Was this ACE inherited from its parent object?", HFILL }},
{ &hf_nt_ace_flags_successful_access,
{ "Audit Successful Accesses", "nt.ace.flags.successful_access", FT_BOOLEAN, 8,
TFS(&tfs_ace_flags_successful_access), 0x40, "Should successful accesses be audited?", HFILL }},
{ &hf_nt_ace_flags_failed_access,
{ "Audit Failed Accesses", "nt.ace.flags.failed_access", FT_BOOLEAN, 8,
TFS(&tfs_ace_flags_failed_access), 0x80, "Should failed accesses be audited?", HFILL }},
{ &hf_nt_access_mask,
{ "Access required", "nt.access_mask",
FT_UINT32, BASE_HEX, NULL, 0x0, "Access mask",
HFILL }},
{ &hf_access_generic_read,
{ "Generic read", "nt.access_mask.generic_read",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
GENERIC_READ_ACCESS, NULL, HFILL }},
{ &hf_access_generic_write,
{ "Generic write", "nt.access_mask.generic_write",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
GENERIC_WRITE_ACCESS, NULL, HFILL }},
{ &hf_access_generic_execute,
{ "Generic execute", "nt.access_mask.generic_execute",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
GENERIC_EXECUTE_ACCESS, NULL, HFILL }},
{ &hf_access_generic_all,
{ "Generic all", "nt.access_mask.generic_all",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
GENERIC_ALL_ACCESS, NULL, HFILL }},
{ &hf_access_maximum_allowed,
{ "Maximum allowed", "nt.access_mask.maximum_allowed",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
MAXIMUM_ALLOWED_ACCESS, NULL, HFILL }},
{ &hf_access_sacl,
{ "Access SACL", "nt.access_mask.access_sacl",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
ACCESS_SACL_ACCESS, NULL, HFILL }},
{ &hf_access_standard_read_control,
{ "Read control", "nt.access_mask.read_control",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
READ_CONTROL_ACCESS, NULL, HFILL }},
{ &hf_access_standard_delete,
{ "Delete", "nt.access_mask.delete",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
DELETE_ACCESS, NULL, HFILL }},
{ &hf_access_standard_synchronise,
{ "Synchronise", "nt.access_mask.synchronise",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
SYNCHRONIZE_ACCESS, NULL, HFILL }},
{ &hf_access_standard_write_dac,
{ "Write DAC", "nt.access_mask.write_dac",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
WRITE_DAC_ACCESS, NULL, HFILL }},
{ &hf_access_standard_write_owner,
{ "Write owner", "nt.access_mask.write_owner",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
WRITE_OWNER_ACCESS, NULL, HFILL }},
{ &hf_access_specific_15,
{ "Specific access, bit 15", "nt.access_mask.specific_15",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x8000, NULL, HFILL }},
{ &hf_access_specific_14,
{ "Specific access, bit 14", "nt.access_mask.specific_14",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x4000, NULL, HFILL }},
{ &hf_access_specific_13,
{ "Specific access, bit 13", "nt.access_mask.specific_13",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x2000, NULL, HFILL }},
{ &hf_access_specific_12,
{ "Specific access, bit 12", "nt.access_mask.specific_12",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x1000, NULL, HFILL }},
{ &hf_access_specific_11,
{ "Specific access, bit 11", "nt.access_mask.specific_11",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0800, NULL, HFILL }},
{ &hf_access_specific_10,
{ "Specific access, bit 10", "nt.access_mask.specific_10",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0400, NULL, HFILL }},
{ &hf_access_specific_9,
{ "Specific access, bit 9", "nt.access_mask.specific_9",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0200, NULL, HFILL }},
{ &hf_access_specific_8,
{ "Specific access, bit 8", "nt.access_mask.specific_8",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0100, NULL, HFILL }},
{ &hf_access_specific_7,
{ "Specific access, bit 7", "nt.access_mask.specific_7",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0080, NULL, HFILL }},
{ &hf_access_specific_6,
{ "Specific access, bit 6", "nt.access_mask.specific_6",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0040, NULL, HFILL }},
{ &hf_access_specific_5,
{ "Specific access, bit 5", "nt.access_mask.specific_5",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0020, NULL, HFILL }},
{ &hf_access_specific_4,
{ "Specific access, bit 4", "nt.access_mask.specific_4",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0010, NULL, HFILL }},
{ &hf_access_specific_3,
{ "Specific access, bit 3", "nt.access_mask.specific_3",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0008, NULL, HFILL }},
{ &hf_access_specific_2,
{ "Specific access, bit 2", "nt.access_mask.specific_2",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0004, NULL, HFILL }},
{ &hf_access_specific_1,
{ "Specific access, bit 1", "nt.access_mask.specific_1",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0002, NULL, HFILL }},
{ &hf_access_specific_0,
{ "Specific access, bit 0", "nt.access_mask.specific_0",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x0001, NULL, HFILL }},
{ &hf_nt_ace_flags_object_type_present,
{ "Object Type Present", "nt.ace.object.flags.object_type_present",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x00000001, NULL, HFILL }},
{ &hf_nt_ace_flags_inherited_object_type_present,
{ "Inherited Object Type Present", "nt.ace.object.flags.inherited_object_type_present",
FT_BOOLEAN, 32, TFS(&tfs_set_notset),
0x00000002, NULL, HFILL }},
{ &hf_nt_ace_guid,
{ "GUID", "nt.ace.object.guid", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nt_ace_inherited_guid,
{ "Inherited GUID", "nt.ace.object.inherited_guid", FT_GUID, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_nt_security_information_sacl,
{ "SACL", "nt.sec_info.sacl", FT_BOOLEAN, 32,
TFS(&flags_sec_info_sacl), 0x00000008, NULL, HFILL }},
{ &hf_nt_security_information_dacl,
{ "DACL", "nt.sec_info.dacl", FT_BOOLEAN, 32,
TFS(&flags_sec_info_dacl), 0x00000004, NULL, HFILL }},
{ &hf_nt_security_information_group,
{ "Group", "nt.sec_info.group", FT_BOOLEAN, 32,
TFS(&flags_sec_info_group), 0x00000002, NULL, HFILL }},
{ &hf_nt_security_information_owner,
{ "Owner", "nt.sec_info.owner", FT_BOOLEAN, 32,
TFS(&flags_sec_info_owner), 0x00000001, NULL, HFILL }},
};
static gint *ett[] = {
&ett_nt_sec_desc,
&ett_nt_sec_desc_type,
&ett_nt_sid,
&ett_nt_acl,
&ett_nt_ace,
&ett_nt_ace_flags,
&ett_nt_ace_object,
&ett_nt_ace_object_flags,
&ett_nt_access_mask,
&ett_nt_access_mask_generic,
&ett_nt_access_mask_standard,
&ett_nt_access_mask_specific,
&ett_nt_security_information,
};
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_smb, hf, array_length(hf));
}
