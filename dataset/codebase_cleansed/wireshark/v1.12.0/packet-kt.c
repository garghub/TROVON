static int
dissect_kt_replication_wait(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
gint new_offset;
guint64 ts;
nstime_t ns_ts;
new_offset = offset;
proto_tree_add_item(tree, hf_kt_magic, tvb, new_offset, 1, ENC_BIG_ENDIAN);
new_offset++;
ts = tvb_get_ntoh64(tvb, new_offset);
ns_ts.secs = (time_t)(ts/1000000000);
ns_ts.nsecs = (int)(ts%1000000000);
proto_tree_add_time(tree, hf_kt_ts, tvb, new_offset, 8, &ns_ts);
new_offset += 8;
return new_offset;
}
static int
dissect_kt_replication(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
gint new_offset;
guint32 next32, size;
guint64 ts;
nstime_t ns_ts;
proto_item *pi;
new_offset = offset;
proto_tree_add_item(tree, hf_kt_magic, tvb, new_offset, 1, ENC_BIG_ENDIAN);
new_offset++;
if (tvb_reported_length_remaining(tvb, new_offset) > 0) {
next32 = tvb_get_ntohl(tvb, new_offset);
if (next32 <= 1) {
proto_tree_add_item(tree, hf_kt_flags, tvb, new_offset, 4, ENC_BIG_ENDIAN);
new_offset += 4;
proto_tree_add_item(tree, hf_kt_ts, tvb, new_offset, 8, ENC_BIG_ENDIAN);
new_offset += 8;
proto_tree_add_item(tree, hf_kt_sid, tvb, new_offset, 2, ENC_BIG_ENDIAN);
new_offset += 2;
} else {
ts = tvb_get_ntoh64(tvb, new_offset);
ns_ts.secs = (time_t)(ts/1000000000);
ns_ts.nsecs = (int)(ts%1000000000);
proto_tree_add_time(tree, hf_kt_ts, tvb, new_offset, 8, &ns_ts);
new_offset += 8;
size = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(tree, hf_kt_size, tvb, new_offset, 4, size);
new_offset += 4;
proto_tree_add_item(tree, hf_kt_log, tvb, new_offset, size, ENC_NA);
new_offset += size;
}
} else {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_RESPONSE);
PROTO_ITEM_SET_GENERATED(pi);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "[response]");
}
return new_offset;
}
static int
dissect_kt_set_bulk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
guint32 next32, rnum, ksiz, vsiz;
gint new_offset, rec_start_offset;
proto_item *ti;
proto_item *pi;
proto_tree *rec_tree;
new_offset = offset;
proto_tree_add_item(tree, hf_kt_magic, tvb, new_offset, 1, ENC_BIG_ENDIAN);
new_offset++;
next32 = tvb_get_ntohl(tvb, new_offset);
if (tvb_reported_length_remaining(tvb, (new_offset + 4)) > 0) {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_REQUEST);
PROTO_ITEM_SET_GENERATED(pi);
proto_tree_add_uint(tree, hf_kt_flags, tvb, new_offset, 4, next32);
new_offset += 4;
rnum = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(tree, hf_kt_rnum, tvb, new_offset, 4, rnum);
new_offset += 4;
while (rnum > 0) {
ti = proto_tree_add_item(tree, hf_kt_rec, tvb, new_offset, -1, ENC_NA);
rec_tree = proto_item_add_subtree(ti, ett_kt_rec);
rec_start_offset = new_offset;
proto_tree_add_item(rec_tree, hf_kt_dbidx, tvb, new_offset, 2, ENC_BIG_ENDIAN);
new_offset += 2;
ksiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_ksiz, tvb, new_offset, 4, ksiz);
new_offset += 4;
vsiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_vsiz, tvb, new_offset, 4, vsiz);
new_offset += 4;
proto_tree_add_item(rec_tree, hf_kt_xt, tvb, new_offset, 8, ENC_BIG_ENDIAN);
new_offset += 8;
proto_tree_add_item(rec_tree, hf_kt_key, tvb, new_offset, ksiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_key_str, tvb, new_offset, ksiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += ksiz;
proto_tree_add_item(rec_tree, hf_kt_val, tvb, new_offset, vsiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_val_str, tvb, new_offset, vsiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += vsiz;
proto_item_set_len(ti, new_offset - rec_start_offset);
rnum--;
}
} else {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_RESPONSE);
PROTO_ITEM_SET_GENERATED(pi);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "[response]");
proto_tree_add_uint(tree, hf_kt_hits, tvb, new_offset, 4, next32);
new_offset += 4;
}
return new_offset;
}
static int
dissect_kt_play_script(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
guint32 next32, rnum, ksiz, vsiz, nsiz;
gint new_offset, rec_start_offset;
proto_item *ti;
proto_item *pi;
proto_tree *rec_tree;
new_offset = offset;
proto_tree_add_item(tree, hf_kt_magic, tvb, new_offset, 1, ENC_BIG_ENDIAN);
new_offset++;
next32 = tvb_get_ntohl(tvb, new_offset);
if (next32 == 0) {
if (tvb_reported_length_remaining(tvb, (new_offset + 4)) > 0) {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_REQUEST);
PROTO_ITEM_SET_GENERATED(pi);
proto_tree_add_uint(tree, hf_kt_flags, tvb, new_offset, 4, next32);
new_offset += 4;
nsiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(tree, hf_kt_nsiz, tvb, new_offset, 4, nsiz);
new_offset += 4;
rnum = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(tree, hf_kt_rnum, tvb, new_offset, 4, rnum);
new_offset += 4;
proto_tree_add_item(tree, hf_kt_name, tvb, new_offset, nsiz, ENC_ASCII|ENC_NA);
new_offset += nsiz;
while (rnum > 0) {
ti = proto_tree_add_item(tree, hf_kt_rec, tvb, new_offset, -1, ENC_NA);
rec_tree = proto_item_add_subtree(ti, ett_kt_rec);
rec_start_offset = new_offset;
ksiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_ksiz, tvb, new_offset, 4, ksiz);
new_offset += 4;
vsiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_vsiz, tvb, new_offset, 4, vsiz);
new_offset += 4;
proto_tree_add_item(rec_tree, hf_kt_key, tvb, new_offset, ksiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_key_str, tvb, new_offset, ksiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += ksiz;
proto_tree_add_item(rec_tree, hf_kt_val, tvb, new_offset, vsiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_val_str, tvb, new_offset, vsiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += vsiz;
proto_item_set_len(ti, new_offset - rec_start_offset);
rnum--;
}
} else {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_RESPONSE);
PROTO_ITEM_SET_GENERATED(pi);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "[response]");
proto_tree_add_uint(tree, hf_kt_rnum, tvb, new_offset, 4, next32);
new_offset += 4;
}
} else {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_RESPONSE);
PROTO_ITEM_SET_GENERATED(pi);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "[response]");
rnum = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(tree, hf_kt_hits, tvb, new_offset, 4, rnum);
new_offset += 4;
while (rnum > 0) {
ti = proto_tree_add_item(tree, hf_kt_rec, tvb, new_offset, -1, ENC_NA);
rec_tree = proto_item_add_subtree(ti, ett_kt_rec);
rec_start_offset = new_offset;
ksiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_ksiz, tvb, new_offset, 4, ksiz);
new_offset += 4;
vsiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_vsiz, tvb, new_offset, 4, vsiz);
new_offset += 4;
proto_tree_add_item(rec_tree, hf_kt_key, tvb, new_offset, ksiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_key_str, tvb, new_offset, ksiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += ksiz;
proto_tree_add_item(rec_tree, hf_kt_val, tvb, new_offset, vsiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_val_str, tvb, new_offset, vsiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += vsiz;
proto_item_set_len(ti, new_offset - rec_start_offset);
rnum--;
}
}
return new_offset;
}
static int
dissect_kt_get_bulk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
guint32 next32, rnum, ksiz, vsiz;
guint64 xt;
nstime_t ts;
gint new_offset, rec_start_offset;
proto_item *ti;
proto_item *pi;
proto_tree *rec_tree;
new_offset = offset;
proto_tree_add_item(tree, hf_kt_magic, tvb, new_offset, 1, ENC_BIG_ENDIAN);
new_offset++;
next32 = tvb_get_ntohl(tvb, new_offset);
if (next32 == 0) {
if (tvb_reported_length_remaining(tvb, (new_offset + 4)) > 0) {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_REQUEST);
PROTO_ITEM_SET_GENERATED(pi);
proto_tree_add_uint(tree, hf_kt_flags, tvb, new_offset, 4, next32);
new_offset += 4;
rnum = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(tree, hf_kt_rnum, tvb, new_offset, 4, rnum);
new_offset += 4;
while (rnum > 0) {
ti = proto_tree_add_item(tree, hf_kt_rec, tvb, new_offset, -1, ENC_NA);
rec_tree = proto_item_add_subtree(ti, ett_kt_rec);
rec_start_offset = new_offset;
proto_tree_add_item(rec_tree, hf_kt_dbidx, tvb, new_offset, 2, ENC_BIG_ENDIAN);
new_offset += 2;
ksiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_ksiz, tvb, new_offset, 4, ksiz);
new_offset += 4;
proto_tree_add_item(rec_tree, hf_kt_key, tvb, new_offset, ksiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_key_str, tvb, new_offset, ksiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += ksiz;
proto_item_set_len(ti, new_offset - rec_start_offset);
rnum--;
}
} else {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_RESPONSE);
PROTO_ITEM_SET_GENERATED(pi);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "[response]");
proto_tree_add_uint(tree, hf_kt_hits, tvb, new_offset, 4, next32);
new_offset += 4;
}
} else {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_RESPONSE);
PROTO_ITEM_SET_GENERATED(pi);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "[response]");
rnum = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(tree, hf_kt_hits, tvb, new_offset, 4, rnum);
new_offset += 4;
while (rnum > 0) {
ti = proto_tree_add_item(tree, hf_kt_rec, tvb, new_offset, -1, ENC_NA);
rec_tree = proto_item_add_subtree(ti, ett_kt_rec);
rec_start_offset = new_offset;
proto_tree_add_item(rec_tree, hf_kt_dbidx, tvb, new_offset, 2, ENC_BIG_ENDIAN);
new_offset += 2;
ksiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_ksiz, tvb, new_offset, 4, ksiz);
new_offset += 4;
vsiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_vsiz, tvb, new_offset, 4, vsiz);
new_offset += 4;
xt = tvb_get_ntoh64(tvb, new_offset);
ts.secs = (time_t)(xt&0xFFFFFFFF);
ts.nsecs = 0;
proto_tree_add_time(rec_tree, hf_kt_xt_resp, tvb, new_offset, 8, &ts);
new_offset += 8;
proto_tree_add_item(rec_tree, hf_kt_key, tvb, new_offset, ksiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_key_str, tvb, new_offset, ksiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += ksiz;
proto_tree_add_item(rec_tree, hf_kt_val, tvb, new_offset, vsiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_val_str, tvb, new_offset, vsiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += vsiz;
proto_item_set_len(ti, new_offset - rec_start_offset);
rnum--;
}
}
return new_offset;
}
static int
dissect_kt_remove_bulk(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gint offset)
{
guint32 next32, rnum, ksiz;
gint new_offset, rec_start_offset;
proto_item *ti;
proto_item *pi;
proto_tree *rec_tree;
new_offset = offset;
proto_tree_add_item(tree, hf_kt_magic, tvb, new_offset, 1, ENC_BIG_ENDIAN);
new_offset++;
next32 = tvb_get_ntohl(tvb, new_offset);
if (tvb_reported_length_remaining(tvb, (new_offset + 4)) > 0) {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_REQUEST);
PROTO_ITEM_SET_GENERATED(pi);
proto_tree_add_uint(tree, hf_kt_flags, tvb, new_offset, 4, next32);
new_offset += 4;
rnum = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(tree, hf_kt_rnum, tvb, new_offset, 4, rnum);
new_offset += 4;
while (rnum > 0) {
ti = proto_tree_add_item(tree, hf_kt_rec, tvb, new_offset, -1, ENC_NA);
rec_tree = proto_item_add_subtree(ti, ett_kt_rec);
rec_start_offset = new_offset;
proto_tree_add_item(rec_tree, hf_kt_dbidx, tvb, new_offset, 2, ENC_BIG_ENDIAN);
new_offset += 2;
ksiz = tvb_get_ntohl(tvb, new_offset);
proto_tree_add_uint(rec_tree, hf_kt_ksiz, tvb, new_offset, 4, ksiz);
new_offset += 4;
proto_tree_add_item(rec_tree, hf_kt_key, tvb, new_offset, ksiz, ENC_NA);
if (kt_present_key_val_as_ascii) {
pi = proto_tree_add_item(rec_tree, hf_kt_key_str, tvb, new_offset, ksiz, ENC_ASCII|ENC_NA);
PROTO_ITEM_SET_GENERATED(pi);
}
new_offset += ksiz;
proto_item_set_len(ti, new_offset - rec_start_offset);
rnum--;
}
} else {
pi = proto_tree_add_uint(tree, hf_kt_type, tvb, offset, 1, KT_OPER_RESPONSE);
PROTO_ITEM_SET_GENERATED(pi);
col_append_sep_str(pinfo->cinfo, COL_INFO, " ", "[response]");
proto_tree_add_uint(tree, hf_kt_hits, tvb, new_offset, 4, next32);
new_offset += 4;
}
return new_offset;
}
static int
dissect_kt_error(tvbuff_t *tvb, proto_tree *tree, gint offset)
{
gint new_offset;
new_offset = offset;
proto_tree_add_item(tree, hf_kt_magic, tvb, new_offset, 1, ENC_BIG_ENDIAN);
new_offset++;
return new_offset;
}
static void
dissect_kt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
gint magic;
proto_item *ti;
proto_tree *kt_tree;
gint offset, offset_start;
offset = 0;
while (tvb_reported_length_remaining(tvb, offset) > 0) {
magic = tvb_get_guint8(tvb, offset);
if (try_val_to_str(magic, kt_magic_vals) == NULL)
return;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "KT");
col_set_str(pinfo->cinfo, COL_INFO, try_val_to_str(magic, kt_magic_vals));
ti = proto_tree_add_item(tree, proto_kt, tvb, offset, -1, ENC_NA);
kt_tree = proto_item_add_subtree(ti, ett_kt);
offset_start=offset;
switch (magic) {
case KT_MAGIC_REPL_WAIT:
offset = dissect_kt_replication_wait(tvb, kt_tree, offset);
break;
case KT_MAGIC_REPLICATION:
offset = dissect_kt_replication(tvb, pinfo, kt_tree, offset);
break;
case KT_MAGIC_PLAY_SCRIPT:
offset = dissect_kt_play_script(tvb, pinfo, kt_tree, offset);
break;
case KT_MAGIC_SET_BULK:
offset = dissect_kt_set_bulk(tvb, pinfo, kt_tree, offset);
break;
case KT_MAGIC_REMOVE_BULK:
offset = dissect_kt_remove_bulk(tvb, pinfo, kt_tree, offset);
break;
case KT_MAGIC_GET_BULK:
offset = dissect_kt_get_bulk(tvb, pinfo, kt_tree, offset);
break;
case KT_MAGIC_ERROR:
offset = dissect_kt_error(tvb, kt_tree, offset);
break;
}
proto_item_set_len(ti, offset-offset_start);
}
}
void
proto_register_kt(void)
{
module_t *kt_module;
static hf_register_info hf[] = {
{ &hf_kt_magic,
{ "magic", "kt.magic", FT_UINT8, BASE_HEX,
VALS(kt_magic_vals), 0x0, "identifier", HFILL
}
},
{ &hf_kt_type,
{ "type", "kt.type", FT_UINT8, BASE_HEX,
VALS(kt_oper_vals), 0x0, "request/response", HFILL
}
},
{ &hf_kt_flags,
{ "flags", "kt.flags", FT_UINT32, BASE_HEX,
NULL, 0x0, "flags of bitwise-or", HFILL
}
},
{ &hf_kt_rnum,
{ "rnum", "kt.rnum", FT_UINT32, BASE_DEC, NULL, 0x0,
"the number of records", HFILL
}
},
{ &hf_kt_dbidx,
{ "dbidx", "kt.dbidx", FT_UINT16,
BASE_DEC, NULL, 0x0, "the index of the target database", HFILL
}
},
{ &hf_kt_sid,
{ "sid", "kt.sid", FT_UINT16, BASE_DEC,
NULL, 0x0, "the server ID number", HFILL
}
},
{ &hf_kt_ts,
{ "ts", "kt.ts", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0, "the timestamp of the log", HFILL
}
},
{ &hf_kt_xt,
{ "xt", "kt.xt", FT_UINT64, BASE_DEC,
NULL, 0x0, "the expiration time in seconds", HFILL
}
},
{ &hf_kt_xt_resp,
{ "xt", "kt.xt_resp", FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL,
NULL, 0x0, "the expiration time", HFILL
}
},
{ &hf_kt_ksiz,
{ "ksiz", "kt.ksiz", FT_UINT32, BASE_DEC,
NULL, 0x0, "the size of the key",HFILL
}
},
{ &hf_kt_vsiz,
{ "vsiz", "kt.vsiz", FT_UINT32, BASE_DEC,
NULL, 0x0, "the size of the value", HFILL
}
},
{ &hf_kt_key,
{ "key", "kt.key", FT_BYTES, BASE_NONE,
NULL, 0x0, "the key", HFILL
}
},
{ &hf_kt_val,
{ "value", "kt.value", FT_BYTES, BASE_NONE,
NULL, 0x0, "the value", HFILL
}
},
{ &hf_kt_key_str,
{ "key", "kt.key_str", FT_STRING, BASE_NONE,
NULL, 0x0, "ASCII representation of the key", HFILL
}
},
{ &hf_kt_val_str,
{ "value", "kt.value_str", FT_STRING, BASE_NONE,
NULL, 0x0, "ASCII representation of the value", HFILL
}
},
{ &hf_kt_hits,
{ "hits", "kt.hits", FT_UINT32, BASE_DEC,
NULL, 0x0, "the number of records", HFILL
}
},
{ &hf_kt_size,
{ "size", "kt.size", FT_UINT32, BASE_DEC,
NULL, 0x0, "the size of the replication log", HFILL
}
},
{ &hf_kt_log,
{ "log", "kt.log", FT_BYTES, BASE_NONE,
NULL, 0x0, "the replication log", HFILL
}
},
{ &hf_kt_nsiz,
{ "nsiz", "kt.nsiz", FT_UINT32, BASE_DEC,
NULL, 0x0, "the size of the procedure name", HFILL
}
},
{ &hf_kt_name,
{ "name", "kt.name", FT_STRING, BASE_NONE,
NULL, 0x0, "the procedure name", HFILL
}
},
{ &hf_kt_rec,
{ "record", "kt.record", FT_NONE, BASE_NONE,
NULL, 0x0, "a record", HFILL
}
}
};
static gint *ett[] = {
&ett_kt,
&ett_kt_rec
};
proto_kt = proto_register_protocol("Kyoto Tycoon Protocol", "Kyoto Tycoon", "kt");
register_dissector("kt", dissect_kt, proto_kt);
proto_register_field_array(proto_kt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
kt_module = prefs_register_protocol(proto_kt, proto_reg_handoff_kt);
range_convert_str(&global_kt_tcp_port_range, DEFAULT_KT_PORT_RANGE, MAX_TCP_PORT);
prefs_register_range_preference(kt_module, "tcp.ports", "Kyoto Tycoon TCP ports",
"TCP ports to be decoded as Kyoto Tycoon (binary protocol) (default: "
DEFAULT_KT_PORT_RANGE ")",
&global_kt_tcp_port_range, MAX_TCP_PORT);
prefs_register_bool_preference(kt_module, "present_key_val_as_ascii",
"Attempt to also show ASCII string representation of keys and values",
"KT allows binary values in keys and values. Attempt to show an ASCII representation anyway (which might be prematurely terminated by a NULL!",
&kt_present_key_val_as_ascii);
}
void
proto_reg_handoff_kt(void)
{
static gboolean Initialized = FALSE;
static range_t *kt_tcp_port_range;
if (!Initialized) {
kt_handle = find_dissector("kt");
Initialized = TRUE;
}
else {
dissector_delete_uint_range("tcp.port", kt_tcp_port_range, kt_handle);
g_free(kt_tcp_port_range);
}
kt_tcp_port_range = range_copy(global_kt_tcp_port_range);
dissector_add_uint_range("tcp.port", kt_tcp_port_range, kt_handle);
}
