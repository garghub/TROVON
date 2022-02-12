static int
dissect_error_status_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item;
proto_tree *tree;
int old_offset = offset;
guint32 st;
const char *st_str;
if (di->conformant_run)
{
return offset;
}
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_error_status_t, &item, "error_status_t");
offset =
dissect_ndr_uint32 (tvb, offset, pinfo, tree, di, drep, hf_error_status_t,
&st);
st_str = val_to_str_ext (st, &dce_error_vals_ext, "%u");
col_append_fstr (pinfo->cinfo, COL_INFO, " st:%s ", st_str);
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_sec_rgy_pname_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
#define sec_rgy_pname_t_size 257
guint32 string_size;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_sec_rgy_pname_t, &item, "sec_rgy_pname_t");
}
offset = dissect_ndr_uint32 (tvb, offset, pinfo, tree, di, drep,
hf_sec_rgy_pname_t_size, &string_size);
col_append_fstr (pinfo->cinfo, COL_INFO, " String_size:%u", string_size);
if (string_size < sec_rgy_pname_t_size)
{
proto_tree_add_item (tree, hf_sec_rgy_pname_t_principalName_string,
tvb, offset, string_size, ENC_ASCII|ENC_NA);
if (string_size > 1)
{
col_append_fstr (pinfo->cinfo, COL_INFO, " Principal:%s",
tvb_get_string_enc(wmem_packet_scope(), tvb, offset, string_size, ENC_ASCII));
}
offset += string_size;
}
else
{
col_append_fstr (pinfo->cinfo, COL_INFO,
" :FIXME!: Invalid string length of %u",
string_size);
}
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_sec_rgy_pgo_flags_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint32 flags;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_sec_rgy_pgo_flags_t, &item, "sec_rgy_pgo_flags_t ");
}
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_sec_rgy_pgo_flags_t, &flags);
#define sec_rgy_pgo_is_an_alias 0x01
#define sec_rgy_pgo_is_required 0x02
#define sec_rgy_pgo_projlist_ok 0x04
#define sec_rgy_pgo_flags_none 0x00
col_append_str (pinfo->cinfo, COL_INFO, " PgoFlags=");
if ((flags & sec_rgy_pgo_is_an_alias) == sec_rgy_pgo_is_an_alias)
{
col_append_str (pinfo->cinfo, COL_INFO, ":IS_AN_ALIAS");
}
if ((flags & sec_rgy_pgo_is_required) == sec_rgy_pgo_is_required)
{
col_append_str (pinfo->cinfo, COL_INFO, ":IS_REQUIRED");
}
if ((flags & sec_rgy_pgo_projlist_ok) == sec_rgy_pgo_projlist_ok)
{
col_append_str (pinfo->cinfo, COL_INFO, ":PROJLIST_OK");
}
if ((flags & sec_rgy_acct_admin_client) == sec_rgy_acct_admin_client)
{
col_append_str (pinfo->cinfo, COL_INFO, ":NONE");
}
if ((flags & sec_rgy_pgo_flags_none) == sec_rgy_pgo_flags_none)
{
col_append_str (pinfo->cinfo, COL_INFO, ":NONE");
}
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_rs_cache_data_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint32 person_dtm, group_dtm, org_dtm;
e_guid_t uuid1;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_rs_cache_data_t, &item, "rs_cache_data_t");
}
offset =
dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_rs_uuid1, &uuid1);
offset =
dissect_dcerpc_time_t (tvb, offset, pinfo, tree, drep, hf_rs_timeval,
&person_dtm);
offset =
dissect_dcerpc_time_t (tvb, offset, pinfo, tree, drep, hf_rs_timeval,
&group_dtm);
offset =
dissect_dcerpc_time_t (tvb, offset, pinfo, tree, drep, hf_rs_timeval,
&org_dtm);
col_append_fstr (pinfo->cinfo, COL_INFO,
" siteid %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x person_dtm:%u group_dtm:%u org_dtm:%u",
uuid1.data1, uuid1.data2, uuid1.data3, uuid1.data4[0],
uuid1.data4[1], uuid1.data4[2], uuid1.data4[3],
uuid1.data4[4], uuid1.data4[5], uuid1.data4[6],
uuid1.data4[7], person_dtm, group_dtm, org_dtm);
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_sec_rgy_name_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
#define sec_rgy_name_t_size 1025
guint32 string_size;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_sec_rgy_name_t, &item, "sec_rgy_name_t");
}
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_sec_rgy_name_t_size, &string_size);
col_append_fstr (pinfo->cinfo, COL_INFO, " String_size:%u", string_size);
if (string_size < sec_rgy_name_t_size)
{
proto_tree_add_item (tree, hf_sec_rgy_name_t_principalName_string,
tvb, offset, string_size, ENC_ASCII|ENC_NA);
if (string_size > 1)
{
col_append_fstr (pinfo->cinfo, COL_INFO, " Principal:%s",
tvb_get_string_enc(wmem_packet_scope(), tvb, offset, string_size, ENC_ASCII));
}
offset += string_size;
}
else
{
col_append_fstr (pinfo->cinfo, COL_INFO,
" :FIXME!: Invalid string length of %u",
string_size);
}
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_sec_rgy_domain_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint32 domain_t;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_sec_rgy_domain_t, &item, "sec_rgy_domain_t");
}
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_sec_rgy_domain_t,
&domain_t);
col_append_fstr (pinfo->cinfo, COL_INFO, " sec_rgy_domain_t:%u",
domain_t);
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_sec_rgy_pgo_item_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
e_guid_t id;
guint32 unix_num, quota;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_sec_rgy_pgo_item_t, &item, " sec_rgy_pgo_item_t ");
}
offset =
dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_rs_uuid1, &id);
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_sec_rgy_pgo_item_t_unix_num, &unix_num);
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_sec_rgy_pgo_item_t_quota, &quota);
offset = dissect_sec_rgy_pgo_flags_t (tvb, offset, pinfo, tree, di, drep);
offset += 4;
offset = dissect_sec_rgy_pname_t (tvb, offset, pinfo, tree, di, drep);
col_append_fstr (pinfo->cinfo, COL_INFO,
" sec_rgy_pgo_item_t - id %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x unix_num:%u quota:%u",
id.data1, id.data2, id.data3, id.data4[0],
id.data4[1], id.data4[2], id.data4[3],
id.data4[4], id.data4[5], id.data4[6],
id.data4[7], unix_num, quota);
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_sec_rgy_cursor_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
e_guid_t source;
guint32 handle, valid;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_sec_rgy_cursor_t, &item, " sec_rgy_cursor_t ");
}
offset =
dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_rs_uuid1, &source);
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_sec_rgy_pgo_item_t_unix_num, &handle);
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_sec_rgy_pgo_item_t_quota, &valid);
col_append_fstr (pinfo->cinfo, COL_INFO,
" sec_rgy_cursor_t - source %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x handle:%u valid:%u",
source.data1, source.data2, source.data3,
source.data4[0], source.data4[1], source.data4[2],
source.data4[3], source.data4[4], source.data4[5],
source.data4[6], source.data4[7], handle, valid);
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_rs_pgo_query_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
enum
{
rs_pgo_query_name,
rs_pgo_query_id,
rs_pgo_query_unix_num,
rs_pgo_query_next,
rs_pgo_query_none
};
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint8 query_t;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1, ett_rs_pgo_query_t, &item, "rs_pgo_query_t ");
}
offset =
dissect_ndr_uint8 (tvb, offset, pinfo, tree, di, drep, hf_rs_pgo_query_t,
&query_t);
col_append_str (pinfo->cinfo, COL_INFO, " rs_pgo_query_t:");
switch (query_t)
{
case rs_pgo_query_name:
col_append_str (pinfo->cinfo, COL_INFO, "NAME");
break;
case rs_pgo_query_id:
col_append_str (pinfo->cinfo, COL_INFO, "ID");
break;
case rs_pgo_query_unix_num:
col_append_str (pinfo->cinfo, COL_INFO, "UNIX_NUM");
break;
case rs_pgo_query_next:
col_append_str (pinfo->cinfo, COL_INFO, "NEXT");
break;
case rs_pgo_query_none:
col_append_str (pinfo->cinfo, COL_INFO, "NONE");
break;
default:
col_append_fstr (pinfo->cinfo, COL_INFO, " unknown:%u", query_t);
break;
;
}
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_rs_pgo_id_key_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
e_guid_t id;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_rs_pgo_id_key_t, &item, "rs_pgo_id_key_t ");
}
offset =
dissect_ndr_uuid_t(tvb, offset, pinfo, tree, di, drep, hf_rs_uuid1, &id);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
col_append_fstr (pinfo->cinfo, COL_INFO,
" rs_pgo_id_key_t - id %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
id.data1, id.data2, id.data3, id.data4[0],
id.data4[1], id.data4[2], id.data4[3],
id.data4[4], id.data4[5], id.data4[6], id.data4[7]);
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_rs_pgo_result_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_rs_pgo_result_t, &item, "rs_pgo_result_t ");
}
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_pgo_item_t (tvb, offset, pinfo, tree, di, drep);
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_rs_pgo_unix_num_key_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint32 rs_pgo_unix_num_key_t;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_rs_pgo_unix_num_key_t, &item, " rs_pgo_unix_num_key_t ");
}
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_pgo_unix_num_key_t, &rs_pgo_unix_num_key_t);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
col_append_fstr (pinfo->cinfo, COL_INFO,
" rs_pgo_unix_num_key_t:%u", rs_pgo_unix_num_key_t);
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_rs_pgo_query_key_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
enum
{
rs_pgo_query_name,
rs_pgo_query_id,
rs_pgo_query_unix_num,
rs_pgo_query_next,
rs_pgo_query_none
};
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint16 query_t;
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree =
proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_rs_pgo_query_key_t, &item, "rs_pgo_query_key_t ");
}
offset =
dissect_ndr_uint16 (tvb, offset, pinfo, tree, di, drep, hf_rs_pgo_query_key_t,
&query_t);
col_append_str (pinfo->cinfo, COL_INFO, " rs_pgo_query_key_t:");
offset += 4;
switch (query_t)
{
case rs_pgo_query_name:
col_append_str (pinfo->cinfo, COL_INFO, "NAME");
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
break;
case rs_pgo_query_id:
col_append_str (pinfo->cinfo, COL_INFO, "ID");
offset = dissect_rs_pgo_id_key_t (tvb, offset, pinfo, tree, di, drep);
break;
case rs_pgo_query_unix_num:
col_append_str (pinfo->cinfo, COL_INFO, "UNIX_NUM");
offset = dissect_rs_pgo_unix_num_key_t (tvb, offset, pinfo, tree, di, drep);
break;
case rs_pgo_query_next:
col_append_str (pinfo->cinfo, COL_INFO, "NEXT");
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
break;
case rs_pgo_query_none:
col_append_str (pinfo->cinfo, COL_INFO, "NONE");
break;
default:
col_append_fstr (pinfo->cinfo, COL_INFO, " unknown:%u", query_t);
break;
}
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
dissect_rs_pgo_query_result_t (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * parent_tree,
dcerpc_info *di, guint8 * drep)
{
proto_item *item = NULL;
proto_tree *tree = NULL;
int old_offset = offset;
guint32 st;
const char *status;
#define error_status_ok 0
if (di->conformant_run)
{
return offset;
}
if (parent_tree)
{
tree = proto_tree_add_subtree(parent_tree, tvb, offset, -1,
ett_rs_pgo_query_result_t, &item, "rs_pgo_query_result_t");
}
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep,
hf_rs_pgo_query_result_t, &st);
status = val_to_str_ext (st, &dce_error_vals_ext, "%u");
col_append_fstr (pinfo->cinfo, COL_INFO, " status:%s ", status);
offset += 4;
switch (st)
{
case error_status_ok:
offset = dissect_rs_pgo_result_t (tvb, offset, pinfo, tree, di, drep);
break;
default:
;
}
proto_item_set_len (item, offset - old_offset);
return offset;
}
static int
rs_pgo_dissect_add_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset += 4;
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_sec_rgy_pgo_item_t, NDR_POINTER_REF,
"sec_rgy_pgo_item_t: ", -1);
return offset;
}
static int
rs_pgo_dissect_add_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
gint buff_remain;
if (di->conformant_run)
{
return offset;
}
buff_remain = tvb_captured_length_remaining(tvb, offset);
if (buff_remain > 8) {
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info: ", -1);
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_error_status_t, NDR_POINTER_REF, "status: ",
-1);
return offset;
}
static int
rs_pgo_dissect_delete_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
rs_pgo_dissect_delete_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
gint buff_remain;
if (di->conformant_run)
{
return offset;
}
buff_remain = tvb_captured_length_remaining(tvb, offset);
if (buff_remain > 8) {
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info:", -1);
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_error_status_t, NDR_POINTER_REF, "status:",
-1);
return offset;
}
static int
rs_pgo_dissect_replace_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_sec_rgy_pgo_item_t, NDR_POINTER_REF,
"pgo_item:", -1);
return offset;
}
static int
rs_pgo_dissect_replace_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info:", -1);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_error_status_t, NDR_POINTER_REF, "status:",
-1);
return offset;
}
static int
rs_pgo_dissect_add_member_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
rs_pgo_dissect_rename_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
rs_pgo_dissect_rename_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info:", -1);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_error_status_t, NDR_POINTER_REF, "status:",
-1);
return offset;
}
static int
rs_pgo_dissect_add_member_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
gint buff_remain;
if (di->conformant_run)
{
return offset;
}
buff_remain = tvb_captured_length_remaining(tvb, offset);
if (buff_remain > 8) {
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info:", -1);
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_error_status_t, NDR_POINTER_REF, "status:",
-1);
return offset;
}
static int
rs_pgo_dissect_delete_member_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
rs_pgo_dissect_get_members_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
guint32 max_members;
if (di->conformant_run)
{
return offset;
}
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset += 4;
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_sec_rgy_cursor_t, NDR_POINTER_REF,
"member_cursor:", -1);
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_rs_var1,
&max_members);
col_append_fstr (pinfo->cinfo, COL_INFO, " :max_members:%u", max_members);
return offset;
}
static int
rs_pgo_dissect_key_transfer_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset += 4;
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_rs_pgo_query_t (tvb, offset, pinfo, tree, di, drep);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_pgo_query_key_t, NDR_POINTER_REF, "key:",
-1);
return offset;
}
static int
rs_pgo_dissect_key_transfer_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_pgo_query_key_t, NDR_POINTER_REF, "key:",
-1);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info:", -1);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_error_status_t, NDR_POINTER_REF, "status:",
-1);
return offset;
}
static int
rs_pgo_dissect_is_member_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info:", -1);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_error_status_t, NDR_POINTER_REF, "status:",
-1);
return offset;
}
static int
rs_pgo_dissect_is_member_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset += 4;
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
offset += 4;
offset = dissect_sec_rgy_name_t (tvb, offset, pinfo, tree, di, drep);
return offset;
}
static int
rs_pgo_dissect_get_rqst (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
guint32 allow_aliases;
if (di->conformant_run)
{
return offset;
}
offset = dissect_sec_rgy_domain_t (tvb, offset, pinfo, tree, di, drep);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_pgo_query_key_t, NDR_POINTER_REF, "key:",
-1);
offset =
dissect_ndr_uint32(tvb, offset, pinfo, tree, di, drep, hf_rs_var1,
&allow_aliases);
col_append_fstr (pinfo->cinfo, COL_INFO, " :allow_aliases:%u",
allow_aliases);
offset += 4;
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_sec_rgy_cursor_t, NDR_POINTER_REF,
"item_cursor:", -1);
return offset;
}
static int
rs_pgo_dissect_get_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_sec_rgy_cursor_t, NDR_POINTER_REF,
"item_cursor:", -1);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info:", -1);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_pgo_query_result_t, NDR_POINTER_REF,
"result:", -1);
return offset;
}
static int
rs_pgo_dissect_delete_member_resp (tvbuff_t * tvb, int offset,
packet_info * pinfo, proto_tree * tree,
dcerpc_info *di, guint8 * drep)
{
if (di->conformant_run)
{
return offset;
}
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_rs_cache_data_t, NDR_POINTER_REF,
"cache_info:", -1);
offset =
dissect_ndr_pointer(tvb, offset, pinfo, tree, di, drep,
dissect_error_status_t, NDR_POINTER_REF, "status:",
-1);
return offset;
}
void
proto_register_rs_pgo (void)
{
static hf_register_info hf[] = {
{&hf_rs_pgo_opnum,
{"Operation", "rs_pgo.opnum", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{&hf_error_status_t,
{"Error status", "rs_pgo.error_status", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{&hf_rs_pgo_query_key_t,
{"Query key", "rs_pgo.query_key", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_rs_pgo_query_result_t,
{"Query result", "rs_pgo.query_result", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_rs_pgo_query_t,
{"Query", "rs_pgo.query", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{&hf_rs_sec_rgy_pgo_item_t_quota,
{"Quota", "rs_pgo.quota",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_rs_sec_rgy_pgo_item_t_unix_num,
{"Unix num",
"rs_pgo.unix_num", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{&hf_rs_timeval,
{"Timeval", "rs_pgo.timeval", FT_RELATIVE_TIME, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{&hf_rs_uuid1,
{"Uuid1", "rs_pgo.uuid1", FT_GUID, BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_rs_var1,
{"Var1", "rs_pgo.var1", FT_UINT32, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{&hf_sec_rgy_domain_t,
{"Domain", "rs_pgo.domain", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{&hf_sec_rgy_name_t_principalName_string,
{"Name principalName", "rs_pgo.name_principalName", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{&hf_sec_rgy_name_t_size,
{"Name_t size", "rs_pgo.name_t_size", FT_UINT32,
BASE_DEC, NULL, 0x0, NULL, HFILL}},
{&hf_sec_rgy_pgo_flags_t,
{"Flags", "rs_pgo.flags", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL}},
{&hf_sec_rgy_pname_t_size,
{"Pname_t size", "rs_pgo.pname_t_size", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{&hf_sec_rgy_pname_t_principalName_string,
{"Pname principalName", "rs_pgo.pname_principalName", FT_STRING,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{&hf_rs_pgo_unix_num_key_t,
{"Unix num key", "rs_pgo.unix_num_key_t", FT_UINT32,
BASE_DEC,
NULL, 0x0, NULL, HFILL}}
};
static gint *ett[] = {
&ett_error_status_t,
&ett_rgy_acct_user_flags_t,
&ett_rs_pgo,
&ett_rs_pgo_id_key_t,
&ett_rs_pgo_query_key_t,
&ett_rs_pgo_query_result_t,
&ett_rs_pgo_query_t,
&ett_rs_pgo_result_t,
&ett_rs_pgo_unix_num_key_t,
&ett_sec_attr_component_name_t,
&ett_sec_passwd_type_t,
&ett_sec_rgy_acct_admin_flags_t,
&ett_sec_rgy_acct_admin_t,
&ett_sec_rgy_acct_auth_flags_t,
&ett_sec_rgy_acct_key_t,
&ett_sec_rgy_acct_user_t,
&ett_sec_rgy_cursor_t,
&ett_sec_rgy_foreign_id_t,
&ett_sec_rgy_login_name_t,
&ett_sec_rgy_name_t,
&ett_sec_rgy_domain_t,
&ett_sec_rgy_pgo_flags_t,
&ett_sec_rgy_pgo_item_t,
&ett_sec_rgy_pname_t,
&ett_sec_rgy_sid_t,
&ett_sec_rgy_unix_passwd_buf_t,
&ett_sec_rgy_unix_sid_t,
&ett_sec_timeval_sec_t,
&ett_rs_cache_data_t,
};
proto_rs_pgo =
proto_register_protocol ("DCE Name Service", "RS_PGO", "rs_pgo");
proto_register_field_array (proto_rs_pgo, hf, array_length (hf));
proto_register_subtree_array (ett, array_length (ett));
}
void
proto_reg_handoff_rs_pgo (void)
{
dcerpc_init_uuid (proto_rs_pgo, ett_rs_pgo, &uuid_rs_pgo, ver_rs_pgo,
rs_pgo_dissectors, hf_rs_pgo_opnum);
}
