int req_layout_init(void)
{
int i;
int j;
int k;
struct req_format *rf = NULL;
for (i = 0; i < ARRAY_SIZE(req_formats); ++i) {
rf = req_formats[i];
rf->rf_idx = i;
for (j = 0; j < RCL_NR; ++j) {
LASSERT(rf->rf_fields[j].nr <= REQ_MAX_FIELD_NR);
for (k = 0; k < rf->rf_fields[j].nr; ++k) {
struct req_msg_field *field;
field = (typeof(field))rf->rf_fields[j].d[k];
LASSERT(!(field->rmf_flags & RMF_F_STRUCT_ARRAY)
|| field->rmf_size > 0);
LASSERT(field->rmf_offset[i][j] == 0);
field->rmf_offset[i][j] = k + 1;
}
}
}
return 0;
}
void req_layout_fini(void)
{
}
void req_capsule_init_area(struct req_capsule *pill)
{
int i;
for (i = 0; i < ARRAY_SIZE(pill->rc_area[RCL_CLIENT]); i++) {
pill->rc_area[RCL_CLIENT][i] = -1;
pill->rc_area[RCL_SERVER][i] = -1;
}
}
void req_capsule_init(struct req_capsule *pill,
struct ptlrpc_request *req,
enum req_location location)
{
LASSERT(location == RCL_SERVER || location == RCL_CLIENT);
if (req != NULL && pill == &req->rq_pill && req->rq_pill_init)
return;
memset(pill, 0, sizeof(*pill));
pill->rc_req = req;
pill->rc_loc = location;
req_capsule_init_area(pill);
if (req != NULL && pill == &req->rq_pill)
req->rq_pill_init = 1;
}
void req_capsule_fini(struct req_capsule *pill)
{
}
static int __req_format_is_sane(const struct req_format *fmt)
{
return
0 <= fmt->rf_idx && fmt->rf_idx < ARRAY_SIZE(req_formats) &&
req_formats[fmt->rf_idx] == fmt;
}
static struct lustre_msg *__req_msg(const struct req_capsule *pill,
enum req_location loc)
{
struct ptlrpc_request *req;
req = pill->rc_req;
return loc == RCL_CLIENT ? req->rq_reqmsg : req->rq_repmsg;
}
void req_capsule_set(struct req_capsule *pill, const struct req_format *fmt)
{
LASSERT(pill->rc_fmt == NULL || pill->rc_fmt == fmt);
LASSERT(__req_format_is_sane(fmt));
pill->rc_fmt = fmt;
}
int req_capsule_filled_sizes(struct req_capsule *pill,
enum req_location loc)
{
const struct req_format *fmt = pill->rc_fmt;
int i;
LASSERT(fmt != NULL);
for (i = 0; i < fmt->rf_fields[loc].nr; ++i) {
if (pill->rc_area[loc][i] == -1) {
pill->rc_area[loc][i] =
fmt->rf_fields[loc].d[i]->rmf_size;
if (pill->rc_area[loc][i] == -1) {
LASSERT(loc != RCL_SERVER);
break;
}
}
}
return i;
}
int req_capsule_server_pack(struct req_capsule *pill)
{
const struct req_format *fmt;
int count;
int rc;
LASSERT(pill->rc_loc == RCL_SERVER);
fmt = pill->rc_fmt;
LASSERT(fmt != NULL);
count = req_capsule_filled_sizes(pill, RCL_SERVER);
rc = lustre_pack_reply(pill->rc_req, count,
pill->rc_area[RCL_SERVER], NULL);
if (rc != 0) {
DEBUG_REQ(D_ERROR, pill->rc_req,
"Cannot pack %d fields in format `%s': ",
count, fmt->rf_name);
}
return rc;
}
static int __req_capsule_offset(const struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc)
{
int offset;
offset = field->rmf_offset[pill->rc_fmt->rf_idx][loc];
LASSERTF(offset > 0, "%s:%s, off=%d, loc=%d\n",
pill->rc_fmt->rf_name,
field->rmf_name, offset, loc);
offset --;
LASSERT(0 <= offset && offset < REQ_MAX_FIELD_NR);
return offset;
}
static
void
swabber_dumper_helper(struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc,
int offset,
void *value, int len, int dump, void (*swabber)(void *))
{
void *p;
int i;
int n;
int do_swab;
int inout = loc == RCL_CLIENT;
swabber = swabber ?: field->rmf_swabber;
if (ptlrpc_buf_need_swab(pill->rc_req, inout, offset) &&
swabber != NULL && value != NULL)
do_swab = 1;
else
do_swab = 0;
if (!field->rmf_dumper)
dump = 0;
if (!(field->rmf_flags & RMF_F_STRUCT_ARRAY)) {
if (dump) {
CDEBUG(D_RPCTRACE, "Dump of %sfield %s follows\n",
do_swab ? "unswabbed " : "", field->rmf_name);
field->rmf_dumper(value);
}
if (!do_swab)
return;
swabber(value);
ptlrpc_buf_set_swabbed(pill->rc_req, inout, offset);
if (dump) {
CDEBUG(D_RPCTRACE, "Dump of swabbed field %s follows\n",
field->rmf_name);
field->rmf_dumper(value);
}
return;
}
LASSERT((len % field->rmf_size) == 0);
for (p = value, i = 0, n = len / field->rmf_size;
i < n;
i++, p += field->rmf_size) {
if (dump) {
CDEBUG(D_RPCTRACE, "Dump of %sarray field %s, element %d follows\n",
do_swab ? "unswabbed " : "", field->rmf_name, i);
field->rmf_dumper(p);
}
if (!do_swab)
continue;
swabber(p);
if (dump) {
CDEBUG(D_RPCTRACE, "Dump of swabbed array field %s, element %d follows\n",
field->rmf_name, i);
field->rmf_dumper(value);
}
}
if (do_swab)
ptlrpc_buf_set_swabbed(pill->rc_req, inout, offset);
}
static void *__req_capsule_get(struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc,
void (*swabber)(void *),
int dump)
{
const struct req_format *fmt;
struct lustre_msg *msg;
void *value;
int len;
int offset;
void *(*getter)(struct lustre_msg *m, int n, int minlen);
static const char *rcl_names[RCL_NR] = {
[RCL_CLIENT] = "client",
[RCL_SERVER] = "server"
};
LASSERT(pill != NULL);
LASSERT(pill != LP_POISON);
fmt = pill->rc_fmt;
LASSERT(fmt != NULL);
LASSERT(fmt != LP_POISON);
LASSERT(__req_format_is_sane(fmt));
offset = __req_capsule_offset(pill, field, loc);
msg = __req_msg(pill, loc);
LASSERT(msg != NULL);
getter = (field->rmf_flags & RMF_F_STRING) ?
(typeof(getter))lustre_msg_string : lustre_msg_buf;
if (field->rmf_flags & RMF_F_STRUCT_ARRAY) {
len = lustre_msg_buflen(msg, offset);
if ((len % field->rmf_size) != 0) {
CERROR("%s: array field size mismatch %d modulo %d != 0 (%d)\n",
field->rmf_name, len, field->rmf_size, loc);
return NULL;
}
} else if (pill->rc_area[loc][offset] != -1) {
len = pill->rc_area[loc][offset];
} else {
len = max(field->rmf_size, 0);
}
value = getter(msg, offset, len);
if (value == NULL) {
DEBUG_REQ(D_ERROR, pill->rc_req,
"Wrong buffer for field `%s' (%d of %d) in format `%s': %d vs. %d (%s)\n",
field->rmf_name, offset, lustre_msg_bufcount(msg),
fmt->rf_name, lustre_msg_buflen(msg, offset), len,
rcl_names[loc]);
} else {
swabber_dumper_helper(pill, field, loc, offset, value, len,
dump, swabber);
}
return value;
}
static void __req_capsule_dump(struct req_capsule *pill, enum req_location loc)
{
const struct req_format *fmt;
const struct req_msg_field *field;
int len;
int i;
fmt = pill->rc_fmt;
DEBUG_REQ(D_RPCTRACE, pill->rc_req, "BEGIN REQ CAPSULE DUMP\n");
for (i = 0; i < fmt->rf_fields[loc].nr; ++i) {
field = FMT_FIELD(fmt, loc, i);
if (field->rmf_dumper == NULL) {
len = req_capsule_get_size(pill, field, loc);
CDEBUG(D_RPCTRACE, "Field %s has no dumper function; field size is %d\n",
field->rmf_name, len);
} else {
(void) __req_capsule_get(pill, field, loc, NULL, 1);
}
}
CDEBUG(D_RPCTRACE, "END REQ CAPSULE DUMP\n");
}
void req_capsule_client_dump(struct req_capsule *pill)
{
__req_capsule_dump(pill, RCL_CLIENT);
}
void req_capsule_server_dump(struct req_capsule *pill)
{
__req_capsule_dump(pill, RCL_SERVER);
}
void *req_capsule_client_get(struct req_capsule *pill,
const struct req_msg_field *field)
{
return __req_capsule_get(pill, field, RCL_CLIENT, NULL, 0);
}
void *req_capsule_client_swab_get(struct req_capsule *pill,
const struct req_msg_field *field,
void *swabber)
{
return __req_capsule_get(pill, field, RCL_CLIENT, swabber, 0);
}
void *req_capsule_client_sized_get(struct req_capsule *pill,
const struct req_msg_field *field,
int len)
{
req_capsule_set_size(pill, field, RCL_CLIENT, len);
return __req_capsule_get(pill, field, RCL_CLIENT, NULL, 0);
}
void *req_capsule_server_get(struct req_capsule *pill,
const struct req_msg_field *field)
{
return __req_capsule_get(pill, field, RCL_SERVER, NULL, 0);
}
void *req_capsule_server_swab_get(struct req_capsule *pill,
const struct req_msg_field *field,
void *swabber)
{
return __req_capsule_get(pill, field, RCL_SERVER, swabber, 0);
}
void *req_capsule_server_sized_get(struct req_capsule *pill,
const struct req_msg_field *field,
int len)
{
req_capsule_set_size(pill, field, RCL_SERVER, len);
return __req_capsule_get(pill, field, RCL_SERVER, NULL, 0);
}
void *req_capsule_server_sized_swab_get(struct req_capsule *pill,
const struct req_msg_field *field,
int len, void *swabber)
{
req_capsule_set_size(pill, field, RCL_SERVER, len);
return __req_capsule_get(pill, field, RCL_SERVER, swabber, 0);
}
const void *req_capsule_other_get(struct req_capsule *pill,
const struct req_msg_field *field)
{
return __req_capsule_get(pill, field, pill->rc_loc ^ 1, NULL, 0);
}
void req_capsule_set_size(struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc, int size)
{
LASSERT(loc == RCL_SERVER || loc == RCL_CLIENT);
if ((size != field->rmf_size) &&
(field->rmf_size != -1) &&
!(field->rmf_flags & RMF_F_NO_SIZE_CHECK) &&
(size > 0)) {
if ((field->rmf_flags & RMF_F_STRUCT_ARRAY) &&
(size % field->rmf_size != 0)) {
CERROR("%s: array field size mismatch %d %% %d != 0 (%d)\n",
field->rmf_name, size, field->rmf_size, loc);
LBUG();
} else if (!(field->rmf_flags & RMF_F_STRUCT_ARRAY) &&
size < field->rmf_size) {
CERROR("%s: field size mismatch %d != %d (%d)\n",
field->rmf_name, size, field->rmf_size, loc);
LBUG();
}
}
pill->rc_area[loc][__req_capsule_offset(pill, field, loc)] = size;
}
int req_capsule_get_size(const struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc)
{
LASSERT(loc == RCL_SERVER || loc == RCL_CLIENT);
return lustre_msg_buflen(__req_msg(pill, loc),
__req_capsule_offset(pill, field, loc));
}
int req_capsule_msg_size(struct req_capsule *pill, enum req_location loc)
{
return lustre_msg_size(pill->rc_req->rq_import->imp_msg_magic,
pill->rc_fmt->rf_fields[loc].nr,
pill->rc_area[loc]);
}
int req_capsule_fmt_size(__u32 magic, const struct req_format *fmt,
enum req_location loc)
{
int size, i = 0;
size = lustre_msg_hdr_size(magic, fmt->rf_fields[loc].nr);
if (size < 0)
return size;
for (; i < fmt->rf_fields[loc].nr; ++i)
if (fmt->rf_fields[loc].d[i]->rmf_size != -1)
size += cfs_size_round(fmt->rf_fields[loc].d[i]->
rmf_size);
return size;
}
void req_capsule_extend(struct req_capsule *pill, const struct req_format *fmt)
{
int i;
int j;
const struct req_format *old;
LASSERT(pill->rc_fmt != NULL);
LASSERT(__req_format_is_sane(fmt));
old = pill->rc_fmt;
for (i = 0; i < RCL_NR; ++i) {
LASSERT(fmt->rf_fields[i].nr >= old->rf_fields[i].nr);
for (j = 0; j < old->rf_fields[i].nr - 1; ++j) {
const struct req_msg_field *ofield = FMT_FIELD(old, i, j);
if (ofield->rmf_swabber == NULL &&
(ofield->rmf_flags & ~RMF_F_NO_SIZE_CHECK) == 0 &&
(ofield->rmf_size == -1 ||
ofield->rmf_flags == RMF_F_NO_SIZE_CHECK))
continue;
LASSERT(FMT_FIELD(fmt, i, j) == FMT_FIELD(old, i, j));
}
LASSERT(FMT_FIELD(fmt, i, j)->rmf_size >=
FMT_FIELD(old, i, j)->rmf_size);
}
pill->rc_fmt = fmt;
}
int req_capsule_has_field(const struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc)
{
LASSERT(loc == RCL_SERVER || loc == RCL_CLIENT);
return field->rmf_offset[pill->rc_fmt->rf_idx][loc];
}
int req_capsule_field_present(const struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc)
{
int offset;
LASSERT(loc == RCL_SERVER || loc == RCL_CLIENT);
LASSERT(req_capsule_has_field(pill, field, loc));
offset = __req_capsule_offset(pill, field, loc);
return lustre_msg_bufcount(__req_msg(pill, loc)) > offset;
}
void req_capsule_shrink(struct req_capsule *pill,
const struct req_msg_field *field,
unsigned int newlen,
enum req_location loc)
{
const struct req_format *fmt;
struct lustre_msg *msg;
int len;
int offset;
fmt = pill->rc_fmt;
LASSERT(fmt != NULL);
LASSERT(__req_format_is_sane(fmt));
LASSERT(req_capsule_has_field(pill, field, loc));
LASSERT(req_capsule_field_present(pill, field, loc));
offset = __req_capsule_offset(pill, field, loc);
msg = __req_msg(pill, loc);
len = lustre_msg_buflen(msg, offset);
LASSERTF(newlen <= len, "%s:%s, oldlen=%d, newlen=%d\n",
fmt->rf_name, field->rmf_name, len, newlen);
if (loc == RCL_CLIENT)
pill->rc_req->rq_reqlen = lustre_shrink_msg(msg, offset, newlen,
1);
else
pill->rc_req->rq_replen = lustre_shrink_msg(msg, offset, newlen,
1);
}
int req_capsule_server_grow(struct req_capsule *pill,
const struct req_msg_field *field,
unsigned int newlen)
{
struct ptlrpc_reply_state *rs = pill->rc_req->rq_reply_state, *nrs;
char *from, *to;
int offset, len, rc;
LASSERT(pill->rc_fmt != NULL);
LASSERT(__req_format_is_sane(pill->rc_fmt));
LASSERT(req_capsule_has_field(pill, field, RCL_SERVER));
LASSERT(req_capsule_field_present(pill, field, RCL_SERVER));
len = req_capsule_get_size(pill, field, RCL_SERVER);
offset = __req_capsule_offset(pill, field, RCL_SERVER);
if (pill->rc_req->rq_repbuf_len >=
lustre_packed_msg_size(pill->rc_req->rq_repmsg) - len + newlen)
CERROR("Inplace repack might be done\n");
pill->rc_req->rq_reply_state = NULL;
req_capsule_set_size(pill, field, RCL_SERVER, newlen);
rc = req_capsule_server_pack(pill);
if (rc) {
pill->rc_req->rq_reply_state = rs;
return rc;
}
nrs = pill->rc_req->rq_reply_state;
to = lustre_msg_buf(nrs->rs_msg, 0, 0);
from = lustre_msg_buf(rs->rs_msg, 0, 0);
len = (char *)lustre_msg_buf(rs->rs_msg, offset, 0) - from;
memcpy(to, from, len);
if (rs->rs_msg->lm_bufcount > offset + 1) {
to = lustre_msg_buf(nrs->rs_msg, offset + 1, 0);
from = lustre_msg_buf(rs->rs_msg, offset + 1, 0);
offset = rs->rs_msg->lm_bufcount - 1;
len = (char *)lustre_msg_buf(rs->rs_msg, offset, 0) +
cfs_size_round(rs->rs_msg->lm_buflens[offset]) - from;
memcpy(to, from, len);
}
if (rs->rs_difficult) {
int i;
nrs->rs_difficult = 1;
nrs->rs_no_ack = rs->rs_no_ack;
for (i = 0; i < rs->rs_nlocks; i++) {
nrs->rs_locks[i] = rs->rs_locks[i];
nrs->rs_modes[i] = rs->rs_modes[i];
nrs->rs_nlocks++;
}
rs->rs_nlocks = 0;
rs->rs_difficult = 0;
rs->rs_no_ack = 0;
}
ptlrpc_rs_decref(rs);
return 0;
}
