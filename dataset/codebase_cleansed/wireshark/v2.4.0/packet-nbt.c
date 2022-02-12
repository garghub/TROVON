static void
add_rr_to_tree(proto_tree *rr_tree, tvbuff_t *tvb, int offset,
const char *name, int namelen,
int type, int class_val,
guint ttl, gushort data_len)
{
proto_tree_add_string(rr_tree, hf_nbns_name, tvb, offset+1, namelen-1, name);
offset += namelen;
proto_tree_add_uint(rr_tree, hf_nbns_type, tvb, offset, 2, type);
offset += 2;
proto_tree_add_uint(rr_tree, hf_nbns_class, tvb, offset, 2, class_val);
offset += 2;
proto_tree_add_uint_format_value(rr_tree, hf_nbns_ttl, tvb, offset, 4, ttl, "%s",
signed_time_secs_to_str(wmem_packet_scope(), ttl));
offset += 4;
proto_tree_add_uint(rr_tree, hf_nbns_data_length, tvb, offset, 2, data_len);
}
static int
get_nbns_name(tvbuff_t *tvb, int offset, int nbns_data_offset,
char *name_ret, int name_ret_len, int *name_type_ret)
{
int name_len;
const guchar *name;
const guchar *nbname;
char *nbname_buf;
const guchar *pname;
char cname, cnbname;
int name_type;
char *pname_ret;
size_t idx = 0;
guint used_bytes;
nbname_buf = (char *)wmem_alloc(wmem_packet_scope(), NBNAME_BUF_LEN);
nbname = nbname_buf;
used_bytes = get_dns_name(tvb, offset, 0, nbns_data_offset, &name, &name_len);
pname = &name[0];
pname_ret = name_ret;
for (;;) {
cname = *pname;
if (cname == '\0')
break;
if (cname == '.')
break;
if (cname < 'A' || cname > 'Z') {
nbname = "Illegal NetBIOS name (1st character not between A and Z in first-level encoding)";
goto bad;
}
cname -= 'A';
cnbname = cname << 4;
pname++;
cname = *pname;
if (cname == '\0' || cname == '.') {
nbname = "Illegal NetBIOS name (odd number of bytes)";
goto bad;
}
if (cname < 'A' || cname > 'Z') {
nbname = "Illegal NetBIOS name (2nd character not between A and Z in first-level encoding)";
goto bad;
}
cname -= 'A';
cnbname |= cname;
pname++;
if (idx < NETBIOS_NAME_LEN) {
nbname_buf[idx++] = cnbname;
}
}
if (idx != NETBIOS_NAME_LEN) {
g_snprintf(nbname_buf, NBNAME_BUF_LEN, "Illegal NetBIOS name (%lu bytes long)",
(unsigned long)idx);
goto bad;
}
name_type = process_netbios_name(nbname, name_ret, name_ret_len);
pname_ret += MIN(strlen(name_ret), (size_t) name_ret_len);
pname_ret += MIN(name_ret_len-(pname_ret-name_ret),
g_snprintf(pname_ret, name_ret_len-(gulong)(pname_ret-name_ret), "<%02x>", name_type));
if (cname == '.') {
g_snprintf(pname_ret, name_ret_len-(gulong)(pname_ret-name_ret), "%s", pname);
}
if (name_type_ret != NULL)
*name_type_ret = name_type;
return used_bytes;
bad:
if (name_type_ret != NULL)
*name_type_ret = -1;
g_snprintf(pname_ret, name_ret_len-(gulong)(pname_ret-name_ret), "%s", nbname);
return used_bytes;
}
static int
get_nbns_name_type_class(tvbuff_t *tvb, int offset, int nbns_data_offset,
char *name_ret, int *name_len_ret, int *name_type_ret,
int *type_ret, int *class_ret)
{
int name_len;
int type;
int rr_class;
name_len = get_nbns_name(tvb, offset, nbns_data_offset, name_ret,
*name_len_ret, name_type_ret);
offset += name_len;
type = tvb_get_ntohs(tvb, offset);
offset += 2;
rr_class = tvb_get_ntohs(tvb, offset);
*type_ret = type;
*class_ret = rr_class;
*name_len_ret = name_len;
return name_len + 4;
}
static void
add_name_and_type(proto_tree *tree, tvbuff_t *tvb, int offset, int len,
int hf_tag, const char *name, int name_type)
{
if (name_type != -1) {
proto_tree_add_string_format_value(tree, hf_tag, tvb, offset, len, name, "%s (%s)",
name, netbios_name_type_descr(name_type));
} else {
proto_tree_add_string(tree, hf_tag, tvb, offset, len, name);
}
}
static int
dissect_nbns_query(tvbuff_t *tvb, int offset, int nbns_data_offset,
column_info *cinfo, proto_tree *nbns_tree)
{
int len;
char *name;
int name_len;
int name_type;
int type;
int dns_class;
const char *type_name;
int data_offset;
int data_start;
proto_tree *q_tree;
name = (char *)wmem_alloc(wmem_packet_scope(), MAX_NAME_LEN);
data_start = data_offset = offset;
name_len = MAX_NAME_LEN;
len = get_nbns_name_type_class(tvb, offset, nbns_data_offset, name,
&name_len, &name_type, &type, &dns_class);
data_offset += len;
type_name = val_to_str_const(type, nb_type_name_vals, "Unknown");
if (cinfo != NULL)
col_append_fstr(cinfo, COL_INFO, " %s %s", type_name, name);
if (nbns_tree != NULL) {
q_tree = proto_tree_add_subtree_format(nbns_tree, tvb, offset, len,
ett_nbns_qd, NULL, "%s: type %s, class %s", name, type_name,
val_to_str_const(dns_class, dns_classes, "Unknown"));
add_name_and_type(q_tree, tvb, offset, name_len, hf_nbns_name, name,
name_type);
offset += name_len;
proto_tree_add_uint(q_tree, hf_nbns_type, tvb, offset, 2, type);
offset += 2;
proto_tree_add_uint(q_tree, hf_nbns_class, tvb, offset, 2, dns_class);
}
return data_offset - data_start;
}
static void
nbns_add_nbns_flags(column_info *cinfo, proto_tree *nbns_tree, tvbuff_t *tvb, int offset, int is_wack)
{
guint16 flag;
static const int * req_flags[] = {
&hf_nbns_flags_response,
&hf_nbns_flags_opcode,
&hf_nbns_flags_truncated,
&hf_nbns_flags_recdesired,
&hf_nbns_flags_broadcast,
NULL
};
static const int * resp_flags[] = {
&hf_nbns_flags_response,
&hf_nbns_flags_opcode,
&hf_nbns_flags_authoritative,
&hf_nbns_flags_truncated,
&hf_nbns_flags_recdesired,
&hf_nbns_flags_recavail,
&hf_nbns_flags_broadcast,
&hf_nbns_flags_rcode,
NULL
};
static const int * resp_wack_flags[] = {
&hf_nbns_flags_response,
&hf_nbns_flags_opcode,
&hf_nbns_flags_authoritative,
&hf_nbns_flags_truncated,
&hf_nbns_flags_recdesired,
&hf_nbns_flags_recavail,
&hf_nbns_flags_broadcast,
NULL
};
flag = tvb_get_ntohs(tvb, offset);
if (cinfo) {
if (flag & F_RESPONSE && !is_wack) {
if ((flag & F_RCODE))
col_append_fstr(cinfo, COL_INFO, ", %s",
val_to_str_const(flag & F_RCODE, rcode_vals,
"Unknown error"));
}
}
if (!nbns_tree)
return;
if (flag & F_RESPONSE) {
if (!is_wack) {
proto_tree_add_bitmask(nbns_tree, tvb, offset, hf_nbns_flags, ett_nbns_flags, resp_flags, ENC_BIG_ENDIAN);
} else {
proto_tree_add_bitmask(nbns_tree, tvb, offset, hf_nbns_flags, ett_nbns_flags, resp_wack_flags, ENC_BIG_ENDIAN);
}
} else {
proto_tree_add_bitmask(nbns_tree, tvb, offset, hf_nbns_flags, ett_nbns_flags, req_flags, ENC_BIG_ENDIAN);
}
}
static void
nbns_add_nb_flags(proto_tree *rr_tree, tvbuff_t *tvb, int offset)
{
proto_item *tf;
gushort flag;
static const int * flags[] = {
&hf_nbns_nb_flags_group,
&hf_nbns_nb_flags_ont,
NULL
};
tf = proto_tree_add_bitmask(rr_tree, tvb, offset, hf_nbns_nb_flags, ett_nbns_nb_flags, flags, ENC_BIG_ENDIAN);
flag = tvb_get_ntohs(tvb, offset);
proto_item_append_text(tf, " (%s, %s)",
val_to_str_const(flag & NB_FLAGS_ONT, nb_flags_ont_vals, "Unknown"),
(flag & NB_FLAGS_G) ? "group" : "unique");
}
static void
nbns_add_name_flags(proto_tree *rr_tree, tvbuff_t *tvb, int offset)
{
static const int * flags[] = {
&hf_nbns_name_flags_group,
&hf_nbns_name_flags_ont,
&hf_nbns_name_flags_drg,
&hf_nbns_name_flags_cnf,
&hf_nbns_name_flags_act,
&hf_nbns_name_flags_prm,
NULL
};
proto_tree_add_bitmask(rr_tree, tvb, offset, hf_nbns_name_flags, ett_nbns_name_flags, flags, ENC_BIG_ENDIAN);
}
static int
dissect_nbns_answer(tvbuff_t *tvb, packet_info *pinfo, int offset, int nbns_data_offset,
column_info *cinfo, proto_tree *nbns_tree, int opcode)
{
int len;
char *name;
int name_len;
int name_type;
int type;
int dns_class;
const char *class_name;
const char *type_name;
int cur_offset;
guint ttl;
gushort data_len;
proto_tree *rr_tree = NULL;
char *name_str;
guint num_names;
char *nbname;
cur_offset = offset;
name = (char *)wmem_alloc(wmem_packet_scope(), MAX_NAME_LEN);
name_str = (char *)wmem_alloc(wmem_packet_scope(), MAX_NAME_LEN);
nbname = (char *)wmem_alloc(wmem_packet_scope(), 16+4+1);
name_len = MAX_NAME_LEN;
len = get_nbns_name_type_class(tvb, offset, nbns_data_offset, name,
&name_len, &name_type, &type, &dns_class);
cur_offset += len;
type_name = val_to_str_const(type, nb_type_name_vals, "Unknown");
class_name = val_to_str_const(dns_class, dns_classes, "Unknown");
ttl = tvb_get_ntohl(tvb, cur_offset);
cur_offset += 4;
data_len = tvb_get_ntohs(tvb, cur_offset);
cur_offset += 2;
switch (type) {
case T_NB:
if (cinfo != NULL) {
if (opcode != OPCODE_WACK) {
col_append_fstr(cinfo, COL_INFO, " %s %s",
type_name,
tvb_ip_to_str(tvb, cur_offset+2));
}
}
if (nbns_tree) {
rr_tree = proto_tree_add_subtree_format(nbns_tree, tvb, offset,
(cur_offset - offset) + data_len,
ett_nbns_rr, NULL, "%s: type %s, class %s",
name, type_name, class_name);
g_strlcat(name, " (", MAX_NAME_LEN);
g_strlcat(name, netbios_name_type_descr(name_type), MAX_NAME_LEN);
g_strlcat(name, ")", MAX_NAME_LEN);
add_rr_to_tree(rr_tree, tvb, offset, name,
name_len, type, dns_class, ttl, data_len);
}
while (data_len > 0) {
if (opcode == OPCODE_WACK) {
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
nbns_add_nbns_flags(cinfo, rr_tree, tvb, cur_offset, 1);
cur_offset += 2;
data_len -= 2;
} else {
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
nbns_add_nb_flags(rr_tree, tvb, cur_offset);
cur_offset += 2;
data_len -= 2;
if (data_len < 4) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_addr, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
data_len -= 4;
}
}
break;
case T_NBSTAT:
if (cinfo != NULL)
col_append_fstr(cinfo, COL_INFO, " %s", type_name);
if (nbns_tree) {
rr_tree = proto_tree_add_subtree_format(nbns_tree, tvb, offset,
(cur_offset - offset) + data_len,
ett_nbns_rr, NULL, "%s: type %s, class %s",
name, type_name, class_name);
add_rr_to_tree(rr_tree, tvb, offset, name,
name_len, type, dns_class, ttl, data_len);
}
if (data_len < 1) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
num_names = tvb_get_guint8(tvb, cur_offset);
proto_tree_add_item(rr_tree, hf_nbns_number_of_names, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
while (num_names != 0) {
if (data_len < NETBIOS_NAME_LEN) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
goto out;
}
if (rr_tree) {
tvb_memcpy(tvb, (guint8 *)nbname, cur_offset,
NETBIOS_NAME_LEN);
name_type = process_netbios_name(nbname,
name_str, name_len);
proto_tree_add_string_format_value(rr_tree, hf_nbns_netbios_name, tvb, cur_offset,
NETBIOS_NAME_LEN, name_str, "%s<%02x> (%s)",
name_str, name_type,
netbios_name_type_descr(name_type));
}
cur_offset += NETBIOS_NAME_LEN;
data_len -= NETBIOS_NAME_LEN;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
goto out;
}
if (rr_tree) {
nbns_add_name_flags(rr_tree, tvb, cur_offset);
}
cur_offset += 2;
data_len -= 2;
num_names--;
}
if (data_len < 6) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_unit_id, tvb, cur_offset, 6, ENC_NA);
cur_offset += 6;
data_len -= 6;
if (data_len < 1) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_jumpers, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
data_len -= 1;
if (data_len < 1) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_test_result, tvb, cur_offset, 1, ENC_BIG_ENDIAN);
cur_offset += 1;
data_len -= 1;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_version_number, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_period_of_statistics, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_crcs, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_alignment_errors, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_collisions, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_send_aborts, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 4) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_good_sends, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
data_len -= 4;
if (data_len < 4) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_good_receives, tvb, cur_offset, 4, ENC_BIG_ENDIAN);
cur_offset += 4;
data_len -= 4;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_retransmits, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_no_resource_conditions, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_command_blocks, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_num_pending_sessions, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_max_num_pending_sessions, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_max_total_sessions_possible, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
data_len -= 2;
if (data_len < 2) {
proto_tree_add_expert(rr_tree, pinfo, &ei_nbns_incomplete_entry, tvb, cur_offset, data_len);
break;
}
proto_tree_add_item(rr_tree, hf_nbns_session_data_packet_size, tvb, cur_offset, 2, ENC_BIG_ENDIAN);
cur_offset += 2;
out:
break;
default:
if (cinfo != NULL)
col_append_fstr(cinfo, COL_INFO, " %s", type_name);
if (nbns_tree) {
rr_tree = proto_tree_add_subtree_format(nbns_tree, tvb, offset,
(cur_offset - offset) + data_len,
ett_nbns_rr, NULL, "%s: type %s, class %s",
name, type_name, class_name);
add_rr_to_tree(rr_tree, tvb, offset, name,
name_len, type, dns_class, ttl, data_len);
proto_tree_add_item(rr_tree, hf_nbns_data, tvb, cur_offset, data_len, ENC_NA);
}
cur_offset += data_len;
break;
}
return cur_offset - offset;
}
static int
dissect_query_records(tvbuff_t *tvb, int cur_off, int nbns_data_offset,
int count, column_info *cinfo, proto_tree *nbns_tree)
{
int start_off, add_off;
proto_tree *qatree;
proto_item *ti;
start_off = cur_off;
qatree = proto_tree_add_subtree(nbns_tree, tvb, start_off, -1, ett_nbns_qry, &ti, "Queries");
while (count-- > 0) {
add_off = dissect_nbns_query(tvb, cur_off, nbns_data_offset,
cinfo, qatree);
cur_off += add_off;
}
proto_item_set_len(ti, cur_off - start_off);
return cur_off - start_off;
}
static int
dissect_answer_records(tvbuff_t *tvb, packet_info *pinfo, int cur_off, int nbns_data_offset,
int count, column_info *cinfo, proto_tree *nbns_tree,
int opcode, const char *name)
{
int start_off, add_off;
proto_tree *qatree;
proto_item *ti;
start_off = cur_off;
qatree = proto_tree_add_subtree(nbns_tree, tvb, start_off, -1, ett_nbns_ans, &ti, name);
while (count-- > 0) {
add_off = dissect_nbns_answer(tvb, pinfo, cur_off, nbns_data_offset,
cinfo, qatree, opcode);
cur_off += add_off;
}
proto_item_set_len(ti, cur_off - start_off);
return cur_off - start_off;
}
static int
dissect_nbns(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
int nbns_data_offset;
proto_tree *nbns_tree = NULL;
proto_item *ti;
guint32 id, flags, opcode, quest, ans, auth, add;
int cur_off;
nbns_data_offset = offset;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NBNS");
col_clear(pinfo->cinfo, COL_INFO);
id = tvb_get_ntohs(tvb, offset + NBNS_ID);
flags = tvb_get_ntohs(tvb, offset + NBNS_FLAGS);
opcode = (guint16) ((flags & F_OPCODE) >> OPCODE_SHIFT);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s%s",
val_to_str(opcode, opcode_vals, "Unknown operation (%u)"),
(flags & F_RESPONSE) ? " response" : "");
ti = proto_tree_add_item(tree, proto_nbns, tvb, offset, -1, ENC_NA);
nbns_tree = proto_item_add_subtree(ti, ett_nbns);
proto_tree_add_uint(nbns_tree, hf_nbns_transaction_id, tvb,
offset + NBNS_ID, 2, id);
nbns_add_nbns_flags(pinfo->cinfo, nbns_tree, tvb, offset + NBNS_FLAGS, 0);
proto_tree_add_item_ret_uint(nbns_tree, hf_nbns_count_questions, tvb,
offset + NBNS_QUEST, 2, ENC_BIG_ENDIAN, &quest);
proto_tree_add_item_ret_uint(nbns_tree, hf_nbns_count_answers, tvb,
offset + NBNS_ANS, 2, ENC_BIG_ENDIAN, &ans);
proto_tree_add_item_ret_uint(nbns_tree, hf_nbns_count_auth_rr, tvb,
offset + NBNS_AUTH, 2, ENC_BIG_ENDIAN, &auth);
proto_tree_add_item_ret_uint(nbns_tree, hf_nbns_count_add_rr, tvb,
offset + NBNS_ADD, 2, ENC_BIG_ENDIAN, &add);
cur_off = offset + NBNS_HDRLEN;
if (quest > 0) {
cur_off += dissect_query_records(tvb, cur_off,
nbns_data_offset, quest,
(!(flags & F_RESPONSE) ? pinfo->cinfo : NULL), nbns_tree);
}
if (ans > 0) {
cur_off += dissect_answer_records(tvb, pinfo, cur_off,
nbns_data_offset, ans,
((flags & F_RESPONSE) ? pinfo->cinfo : NULL), nbns_tree,
opcode, "Answers");
}
if (auth > 0)
cur_off += dissect_answer_records(tvb, pinfo, cur_off,
nbns_data_offset,
auth, NULL, nbns_tree, opcode,
"Authoritative nameservers");
if (add > 0)
dissect_answer_records(tvb, pinfo, cur_off,
nbns_data_offset,
add, NULL, nbns_tree, opcode,
"Additional records");
return tvb_captured_length(tvb);
}
static void
dissect_netbios_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
heur_dtbl_entry_t *hdtbl_entry;
if (!dissector_try_heuristic(netbios_heur_subdissector_list,
tvb, pinfo, tree, &hdtbl_entry, NULL))
call_data_dissector(tvb, pinfo, tree);
}
static int
dissect_nbdgm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
proto_tree *nbdgm_tree;
proto_item *ti;
tvbuff_t *next_tvb;
guint32 msg_type;
char *name;
int name_type;
int len;
static const int * flags[] = {
&hf_nbdgm_fragment,
&hf_nbdgm_first,
&hf_nbdgm_node_type,
NULL
};
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NBDS");
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_nbdgm, tvb, offset, -1, ENC_NA);
nbdgm_tree = proto_item_add_subtree(ti, ett_nbdgm);
proto_tree_add_item_ret_uint(nbdgm_tree, hf_nbdgm_type, tvb,
offset, 1, ENC_NA, &msg_type);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(msg_type, nbds_msgtype_vals,
"Unknown message type (0x%02X)"));
proto_tree_add_bitmask(nbdgm_tree, tvb, offset+1, hf_nbdgm_flags, ett_nbdgm_flags, flags, ENC_BIG_ENDIAN);
proto_tree_add_item(nbdgm_tree, hf_nbdgm_datagram_id, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(nbdgm_tree, hf_nbdgm_src_ip, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(nbdgm_tree, hf_nbdgm_src_port, tvb, offset+8, 2, ENC_BIG_ENDIAN);
offset += 10;
switch (msg_type) {
case NBDS_DIRECT_UNIQUE:
case NBDS_DIRECT_GROUP:
case NBDS_BROADCAST:
proto_tree_add_item(nbdgm_tree, hf_nbdgm_datagram_length,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(nbdgm_tree, hf_nbdgm_packet_offset,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
name = (char *)wmem_alloc(wmem_packet_scope(), MAX_NAME_LEN);
len = get_nbns_name(tvb, offset, offset, name, MAX_NAME_LEN, &name_type);
add_name_and_type(nbdgm_tree, tvb, offset, len, hf_nbdgm_source_name, name, name_type);
offset += len;
len = get_nbns_name(tvb, offset, offset, name, MAX_NAME_LEN, &name_type);
add_name_and_type(nbdgm_tree, tvb, offset, len, hf_nbdgm_destination_name, name, name_type);
offset += len;
proto_item_set_len(ti, offset);
next_tvb = tvb_new_subset_remaining(tvb, offset);
dissect_netbios_payload(next_tvb, pinfo, tree);
break;
case NBDS_ERROR:
proto_tree_add_item(nbdgm_tree, hf_nbdgm_error_code, tvb, offset,
1, ENC_BIG_ENDIAN);
offset += 1;
proto_item_set_len(ti, offset);
break;
case NBDS_QUERY_REQUEST:
case NBDS_POS_QUERY_RESPONSE:
case NBDS_NEG_QUERY_RESPONSE:
name = (char *)wmem_alloc(wmem_packet_scope(), MAX_NAME_LEN);
len = get_nbns_name(tvb, offset, offset, name, MAX_NAME_LEN, &name_type);
add_name_and_type(nbdgm_tree, tvb, offset, len,
hf_nbdgm_destination_name, name, name_type);
offset += len;
proto_item_set_len(ti, offset);
break;
}
return tvb_captured_length(tvb);
}
static void
dissect_nbss_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
int is_cifs)
{
int offset = 0;
proto_tree *nbss_tree = NULL;
proto_item *ti = NULL;
guint8 msg_type;
guint8 flags;
guint32 length;
int len;
char *name;
int name_type;
guint8 error_code;
tvbuff_t *next_tvb;
const char *saved_proto;
static const int * nbss_flags[] = {
&hf_nbss_flags_e,
NULL
};
name = (char *)wmem_alloc(wmem_packet_scope(), MAX_NAME_LEN);
msg_type = tvb_get_guint8(tvb, offset);
ti = proto_tree_add_item(tree, proto_nbss, tvb, offset, -1, ENC_NA);
nbss_tree = proto_item_add_subtree(ti, ett_nbss);
proto_tree_add_item(nbss_tree, hf_nbss_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
if (is_cifs) {
proto_tree_add_item(nbss_tree, hf_nbss_cifs_length, tvb, offset, 3, ENC_BIG_ENDIAN);
offset += 3;
} else {
flags = tvb_get_guint8(tvb, offset);
proto_tree_add_bitmask(nbss_tree, tvb, offset, hf_nbss_flags, ett_nbss_flags, nbss_flags, ENC_BIG_ENDIAN);
length = tvb_get_ntohs(tvb, offset + 1);
if (flags & NBSS_FLAGS_E)
length += 0x10000;
proto_tree_add_uint(nbss_tree, hf_nbss_length, tvb, offset, 3, length);
offset += 3;
}
switch (msg_type) {
case SESSION_REQUEST:
len = get_nbns_name(tvb, offset, offset, name, MAX_NAME_LEN, &name_type);
if (tree)
add_name_and_type(nbss_tree, tvb, offset, len,
hf_nbss_called_name, name, name_type);
offset += len;
col_append_fstr(pinfo->cinfo, COL_INFO, ", to %s ", name);
len = get_nbns_name(tvb, offset, offset, name, MAX_NAME_LEN, &name_type);
if (tree)
add_name_and_type(nbss_tree, tvb, offset, len,
hf_nbss_calling_name, name, name_type);
col_append_fstr(pinfo->cinfo, COL_INFO, "from %s", name);
break;
case NEGATIVE_SESSION_RESPONSE:
error_code = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(nbss_tree, hf_nbss_error_code, tvb, offset, 1,
error_code);
col_append_fstr(pinfo->cinfo, COL_INFO, ", %s",
val_to_str(error_code, nbss_error_codes, "Unknown (%x)"));
break;
case RETARGET_SESSION_RESPONSE:
proto_tree_add_item(nbss_tree, hf_nbss_retarget_ip_address,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(nbss_tree, hf_nbss_retarget_port,
tvb, offset, 2, ENC_BIG_ENDIAN);
break;
case SESSION_MESSAGE:
next_tvb = tvb_new_subset_remaining(tvb, offset);
saved_proto = pinfo->current_proto;
TRY {
dissect_netbios_payload(next_tvb, pinfo, tree);
}
CATCH_NONFATAL_ERRORS {
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
pinfo->current_proto = saved_proto;
}
ENDTRY;
break;
}
}
static int
dissect_continuation_packet(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *nbss_tree;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_INFO, "NBSS Continuation Message");
if (tree) {
ti = proto_tree_add_item(tree, proto_nbss, tvb, 0, -1, ENC_NA);
nbss_tree = proto_item_add_subtree(ti, ett_nbss);
proto_tree_add_item(nbss_tree, hf_nbss_continuation_data, tvb, 0, -1, ENC_NA);
}
return tvb_captured_length(tvb);
}
static int
dissect_nbss(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
struct tcpinfo *tcpinfo;
int offset = 0;
guint length_remaining;
guint plen;
int max_data;
guint8 msg_type;
guint8 flags;
guint32 length;
gboolean is_cifs;
tvbuff_t *next_tvb;
if (data == NULL)
return 0;
tcpinfo = (struct tcpinfo *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "NBSS");
col_clear(pinfo->cinfo, COL_INFO);
max_data = tvb_captured_length(tvb);
msg_type = tvb_get_guint8(tvb, offset);
if (pinfo->match_uint == TCP_PORT_CIFS) {
is_cifs = TRUE;
} else {
is_cifs = FALSE;
}
if (!tcpinfo->is_reassembled) {
if (max_data < 4) {
return dissect_continuation_packet(tvb, pinfo, tree);
}
if (tvb_captured_length_remaining(tvb, offset) >= 8
&& tvb_get_guint8(tvb,offset+0) == SESSION_MESSAGE
&& tvb_get_guint8(tvb,offset+5) == 'S'
&& tvb_get_guint8(tvb,offset+6) == 'M'
&& tvb_get_guint8(tvb,offset+7) == 'B') {
is_cifs = TRUE;
} else {
is_cifs = FALSE;
}
if (is_cifs) {
flags = 0;
length = tvb_get_ntoh24(tvb, offset + 1);
} else {
flags = tvb_get_guint8(tvb, offset + 1);
length = tvb_get_ntohs(tvb, offset + 2);
if (flags & NBSS_FLAGS_E)
length += 0x10000;
}
if ((flags & (~NBSS_FLAGS_E)) != 0) {
return dissect_continuation_packet(tvb, pinfo, tree);
}
switch (msg_type) {
case SESSION_MESSAGE:
if (length == 0)
return dissect_continuation_packet(tvb, pinfo, tree);
break;
case SESSION_REQUEST:
if (length < 2 || length > 256)
return dissect_continuation_packet(tvb, pinfo, tree);
break;
case POSITIVE_SESSION_RESPONSE:
if (length != 0)
return dissect_continuation_packet(tvb, pinfo, tree);
break;
case NEGATIVE_SESSION_RESPONSE:
if (length != 1)
return dissect_continuation_packet(tvb, pinfo, tree);
break;
case RETARGET_SESSION_RESPONSE:
if (length != 6)
return dissect_continuation_packet(tvb, pinfo, tree);
break;
case SESSION_KEEP_ALIVE:
if (length != 0)
return dissect_continuation_packet(tvb, pinfo, tree);
break;
default:
return dissect_continuation_packet(tvb, pinfo, tree);
}
}
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str(msg_type, message_types, "Unknown (%02x)"));
while ((length_remaining = tvb_reported_length_remaining(tvb, offset)) > 0) {
if (nbss_desegment && pinfo->can_desegment) {
if (length_remaining < 4) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return tvb_captured_length(tvb);
}
}
if (is_cifs) {
length = tvb_get_ntoh24(tvb, offset + 1);
} else {
flags = tvb_get_guint8(tvb, offset + 1);
length = tvb_get_ntohs(tvb, offset + 2);
if (flags & NBSS_FLAGS_E)
length += 65536;
}
plen = length + 4;
if(!pinfo->fd->flags.visited){
if( ((int)plen>tvb_reported_length_remaining(tvb, offset))
&&(tvb_captured_length_remaining(tvb, offset) >= 8)
&&(tvb_get_guint8(tvb,offset+5) == 'S')
&&(tvb_get_guint8(tvb,offset+6) == 'M')
&&(tvb_get_guint8(tvb,offset+7) == 'B') ){
pinfo->want_pdu_tracking = 2;
pinfo->bytes_until_next_pdu = (length+4)-tvb_reported_length_remaining(tvb, offset);
}
}
if (nbss_desegment && pinfo->can_desegment) {
if (length_remaining < plen) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = plen - length_remaining;
return tvb_captured_length(tvb);
}
}
length = length_remaining;
if (length > plen)
length = plen;
next_tvb = tvb_new_subset_length_caplen(tvb, offset, length, plen);
dissect_nbss_packet(next_tvb, pinfo, tree, is_cifs);
offset += plen;
}
return tvb_captured_length(tvb);
}
void
proto_register_nbt(void)
{
static hf_register_info hf_nbns[] = {
{ &hf_nbns_flags,
{ "Flags", "nbns.flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbns_flags_response,
{ "Response", "nbns.flags.response",
FT_BOOLEAN, 16, TFS(&tfs_flags_response), F_RESPONSE,
"Is the message a response?", HFILL }},
{ &hf_nbns_flags_opcode,
{ "Opcode", "nbns.flags.opcode",
FT_UINT16, BASE_DEC, VALS(opcode_vals), F_OPCODE,
"Operation code", HFILL }},
{ &hf_nbns_flags_authoritative,
{ "Authoritative", "nbns.flags.authoritative",
FT_BOOLEAN, 16, TFS(&tfs_flags_authoritative), F_AUTHORITATIVE,
"Is the server is an authority for the domain?", HFILL }},
{ &hf_nbns_flags_truncated,
{ "Truncated", "nbns.flags.truncated",
FT_BOOLEAN, 16, TFS(&tfs_flags_truncated), F_TRUNCATED,
"Is the message truncated?", HFILL }},
{ &hf_nbns_flags_recdesired,
{ "Recursion desired", "nbns.flags.recdesired",
FT_BOOLEAN, 16, TFS(&tfs_flags_recdesired), F_RECDESIRED,
"Do query recursively?", HFILL }},
{ &hf_nbns_flags_recavail,
{ "Recursion available", "nbns.flags.recavail",
FT_BOOLEAN, 16, TFS(&tfs_flags_recavail), F_RECAVAIL,
"Can the server do recursive queries?", HFILL }},
{ &hf_nbns_flags_broadcast,
{ "Broadcast", "nbns.flags.broadcast",
FT_BOOLEAN, 16, TFS(&tfs_flags_broadcast), F_BROADCAST,
"Is this a broadcast packet?", HFILL }},
{ &hf_nbns_flags_rcode,
{ "Reply code", "nbns.flags.rcode",
FT_UINT16, BASE_DEC, VALS(rcode_vals), F_RCODE,
NULL, HFILL }},
{ &hf_nbns_transaction_id,
{ "Transaction ID", "nbns.id",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Identification of transaction", HFILL }},
{ &hf_nbns_count_questions,
{ "Questions", "nbns.count.queries",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of queries in packet", HFILL }},
{ &hf_nbns_count_answers,
{ "Answer RRs", "nbns.count.answers",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of answers in packet", HFILL }},
{ &hf_nbns_count_auth_rr,
{ "Authority RRs", "nbns.count.auth_rr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of authoritative records in packet", HFILL }},
{ &hf_nbns_count_add_rr,
{ "Additional RRs", "nbns.count.add_rr",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of additional records in packet", HFILL }},
{ &hf_nbns_name_flags,
{ "Name flags", "nbns.name_flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbns_name_flags_group,
{ "Name type", "nbns.name_flags.group",
FT_BOOLEAN, 16, TFS(&tfs_group_unique_name), NAME_FLAGS_G,
NULL, HFILL }},
{ &hf_nbns_name_flags_ont,
{ "ONT", "nbns.name_flags.ont",
FT_UINT16, BASE_DEC, VALS(name_flags_ont_vals), NAME_FLAGS_ONT,
NULL, HFILL }},
{ &hf_nbns_name_flags_drg,
{ "Name is being deregistered", "nbns.name_flags.drg",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), NAME_FLAGS_DRG,
NULL, HFILL }},
{ &hf_nbns_name_flags_cnf,
{ "Name is in conflict", "nbns.name_flags.cnf",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), NAME_FLAGS_CNF,
NULL, HFILL }},
{ &hf_nbns_name_flags_act,
{ "Name is active", "nbns.name_flags.act",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), NAME_FLAGS_ACT,
NULL, HFILL }},
{ &hf_nbns_name_flags_prm,
{ "Permanent node name", "nbns.name_flags.prm",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), NAME_FLAGS_PRM,
NULL, HFILL }},
{ &hf_nbns_nb_flags,
{ "Name flags", "nbns.nb_flags",
FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbns_nb_flags_group,
{ "Name type", "nbns.nb_flags.group",
FT_BOOLEAN, 16, TFS(&tfs_group_unique_name), NB_FLAGS_G,
NULL, HFILL }},
{ &hf_nbns_nb_flags_ont,
{ "ONT", "nbns.nb_flags.ont",
FT_UINT16, BASE_DEC, VALS(nb_flags_ont_vals), NB_FLAGS_ONT,
NULL, HFILL }},
{ &hf_nbns_type,
{ "Type", "nbns.type",
FT_UINT16, BASE_DEC, VALS(nb_type_name_vals), 0x0,
NULL, HFILL }},
{ &hf_nbns_class,
{ "Class", "nbns.class",
FT_UINT16, BASE_DEC, VALS(dns_classes), 0x0,
NULL, HFILL }},
{ &hf_nbns_name,
{ "Name", "nbns.name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbns_addr, { "Addr", "nbns.addr", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_number_of_names, { "Number of names", "nbns.number_of_names", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_unit_id, { "Unit ID", "nbns.unit_id", FT_ETHER, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_jumpers, { "Jumpers", "nbns.jumpers", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_test_result, { "Test result", "nbns.test_result", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_version_number, { "Version number", "nbns.version_number", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_period_of_statistics, { "Period of statistics", "nbns.period_of_statistics", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_crcs, { "Number of CRCs", "nbns.num_crcs", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_alignment_errors, { "Number of alignment errors", "nbns.num_alignment_errors", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_collisions, { "Number of collisions", "nbns.num_collisions", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_send_aborts, { "Number of send aborts", "nbns.num_send_aborts", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_good_sends, { "Number of good sends", "nbns.num_good_sends", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_good_receives, { "Number of good receives", "nbns.num_good_receives", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_retransmits, { "Number of retransmits", "nbns.numretransmits", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_no_resource_conditions, { "Number of no resource conditions", "nbns.num_no_resource_conditions", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_command_blocks, { "Number of command blocks", "nbns.numcommand_blocks", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_num_pending_sessions, { "Number of pending sessions", "nbns.numpending_sessions", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_max_num_pending_sessions, { "Max number of pending sessions", "nbns.max_num_pending_sessions", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_max_total_sessions_possible, { "Max total sessions possible", "nbns.max_total_sessions_possible", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_session_data_packet_size, { "Session data packet size", "nbns.session_data_packet_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_data, { "Data", "nbns.data", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_netbios_name, { "Name", "nbns.netbios_name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_ttl, { "Time to live", "nbns.ttl", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_nbns_data_length, { "Data length", "nbns.data_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static hf_register_info hf_nbdgm[] = {
{ &hf_nbdgm_type,
{ "Message Type", "nbdgm.type",
FT_UINT8, BASE_DEC, VALS(nbds_msgtype_vals), 0x0,
"NBDGM message type", HFILL }},
{ &hf_nbdgm_flags,
{ "Flags", "nbdgm.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbdgm_fragment,
{ "More fragments follow", "nbdgm.next",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x01,
"TRUE if more fragments follow", HFILL }},
{ &hf_nbdgm_first,
{ "This is first fragment", "nbdgm.first",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), 0x02,
"TRUE if first fragment", HFILL }},
{ &hf_nbdgm_node_type,
{ "Node Type", "nbdgm.node_type",
FT_UINT8, BASE_DEC, VALS(node_type_vals), 0x0C,
NULL, HFILL }},
{ &hf_nbdgm_datagram_id,
{ "Datagram ID", "nbdgm.dgram_id",
FT_UINT16, BASE_HEX, NULL, 0x0,
"Datagram identifier", HFILL }},
{ &hf_nbdgm_src_ip,
{ "Source IP", "nbdgm.src.ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Source IPv4 address", HFILL }},
{ &hf_nbdgm_src_port,
{ "Source Port", "nbdgm.src.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbdgm_datagram_length,
{ "Datagram length", "nbdgm.dgram_len",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0,
NULL, HFILL }},
{ &hf_nbdgm_packet_offset,
{ "Packet offset", "nbdgm.pkt_offset",
FT_UINT16, BASE_DEC|BASE_UNIT_STRING, &units_byte_bytes, 0x0,
NULL, HFILL }},
{ &hf_nbdgm_error_code,
{ "Error code", "nbdgm.error_code",
FT_UINT8, BASE_HEX, VALS(nbds_error_codes), 0x0,
NULL, HFILL }},
{ &hf_nbdgm_source_name,
{ "Source name", "nbdgm.source_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbdgm_destination_name,
{ "Destination name", "nbdgm.destination_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static hf_register_info hf_nbss[] = {
{ &hf_nbss_type,
{ "Message Type", "nbss.type",
FT_UINT8, BASE_HEX, VALS(message_types), 0x0,
"NBSS message type", HFILL }},
{ &hf_nbss_flags,
{ "Flags", "nbss.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"NBSS message flags", HFILL }},
{ &hf_nbss_flags_e,
{ "Extend", "nbss.flags.e",
FT_BOOLEAN, 8, TFS(&tfs_nbss_flags_e), NBSS_FLAGS_E,
NULL, HFILL }},
{ &hf_nbss_length,
{ "Length", "nbss.length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length of trailer (payload) following this field in bytes", HFILL }},
{ &hf_nbss_cifs_length,
{ "Length", "nbss.length",
FT_UINT24, BASE_DEC, NULL, 0x0,
"Length trailer (payload) following this field in bytes", HFILL }},
{ &hf_nbss_error_code,
{ "Error code", "nbss.error_code",
FT_UINT8, BASE_HEX, VALS(nbss_error_codes), 0x0,
NULL, HFILL }},
{ &hf_nbss_retarget_ip_address,
{ "Retarget IP address", "nbss.retarget_ip_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbss_retarget_port,
{ "Retarget port", "nbss.retarget_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbss_continuation_data,
{ "Continuation data", "nbss.continuation_data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbss_called_name,
{ "Called name", "nbss.called_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nbss_calling_name,
{ "Calling name", "nbss.calling_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_nbns,
&ett_nbns_qd,
&ett_nbns_flags,
&ett_nbns_nb_flags,
&ett_nbns_name_flags,
&ett_nbns_rr,
&ett_nbns_qry,
&ett_nbns_ans,
&ett_nbdgm,
&ett_nbdgm_flags,
&ett_nbss,
&ett_nbss_flags,
};
static ei_register_info ei[] = {
{ &ei_nbns_incomplete_entry, { "nbns.incomplete_entry", PI_MALFORMED, PI_ERROR, "incomplete entry", EXPFILL }},
};
module_t *nbss_module;
expert_module_t* expert_nbns;
proto_nbns = proto_register_protocol("NetBIOS Name Service", "NBNS", "nbns");
proto_register_field_array(proto_nbns, hf_nbns, array_length(hf_nbns));
expert_nbns = expert_register_protocol(proto_nbns);
expert_register_field_array(expert_nbns, ei, array_length(ei));
proto_nbdgm = proto_register_protocol("NetBIOS Datagram Service",
"NBDS", "nbdgm");
proto_register_field_array(proto_nbdgm, hf_nbdgm, array_length(hf_nbdgm));
proto_nbss = proto_register_protocol("NetBIOS Session Service",
"NBSS", "nbss");
proto_register_field_array(proto_nbss, hf_nbss, array_length(hf_nbss));
proto_register_subtree_array(ett, array_length(ett));
nbss_module = prefs_register_protocol(proto_nbss, NULL);
prefs_register_bool_preference(nbss_module, "desegment_nbss_commands",
"Reassemble NBSS packets spanning multiple TCP segments",
"Whether the NBSS dissector should reassemble packets spanning multiple TCP segments."
" To use this option, you must also enable"
" \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&nbss_desegment);
}
void
proto_reg_handoff_nbt(void)
{
dissector_handle_t nbns_handle, nbdgm_handle, nbss_handle;
nbns_handle = create_dissector_handle(dissect_nbns, proto_nbns);
dissector_add_uint_with_preference("udp.port", UDP_PORT_NBNS, nbns_handle);
nbdgm_handle = create_dissector_handle(dissect_nbdgm, proto_nbdgm);
dissector_add_uint_with_preference("udp.port", UDP_PORT_NBDGM, nbdgm_handle);
nbss_handle = create_dissector_handle(dissect_nbss, proto_nbss);
dissector_add_uint_range_with_preference("tcp.port", TCP_NBSS_PORT_RANGE, nbss_handle);
netbios_heur_subdissector_list = find_heur_dissector_list("netbios");
}
