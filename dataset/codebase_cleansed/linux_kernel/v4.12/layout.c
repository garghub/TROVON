int req_layout_init(void)
{
size_t i;
size_t j;
size_t k;
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
static void req_capsule_init_area(struct req_capsule *pill)
{
size_t i;
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
if (req && pill == &req->rq_pill && req->rq_pill_init)
return;
memset(pill, 0, sizeof(*pill));
pill->rc_req = req;
pill->rc_loc = location;
req_capsule_init_area(pill);
if (req && pill == &req->rq_pill)
req->rq_pill_init = 1;
}
void req_capsule_fini(struct req_capsule *pill)
{
}
static int __req_format_is_sane(const struct req_format *fmt)
{
return fmt->rf_idx < ARRAY_SIZE(req_formats) &&
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
LASSERT(!pill->rc_fmt || pill->rc_fmt == fmt);
LASSERT(__req_format_is_sane(fmt));
pill->rc_fmt = fmt;
}
size_t req_capsule_filled_sizes(struct req_capsule *pill,
enum req_location loc)
{
const struct req_format *fmt = pill->rc_fmt;
size_t i;
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
LASSERT(fmt);
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
static u32 __req_capsule_offset(const struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc)
{
u32 offset;
offset = field->rmf_offset[pill->rc_fmt->rf_idx][loc];
LASSERTF(offset > 0, "%s:%s, off=%d, loc=%d\n", pill->rc_fmt->rf_name,
field->rmf_name, offset, loc);
offset--;
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
swabber && value)
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
if (dump && field->rmf_dumper) {
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
u32 len;
u32 offset;
void *(*getter)(struct lustre_msg *m, u32 n, u32 minlen);
static const char *rcl_names[RCL_NR] = {
[RCL_CLIENT] = "client",
[RCL_SERVER] = "server"
};
fmt = pill->rc_fmt;
LASSERT(fmt);
LASSERT(fmt != LP_POISON);
LASSERT(__req_format_is_sane(fmt));
offset = __req_capsule_offset(pill, field, loc);
msg = __req_msg(pill, loc);
LASSERT(msg);
getter = (field->rmf_flags & RMF_F_STRING) ?
(typeof(getter))lustre_msg_string : lustre_msg_buf;
if (field->rmf_flags & (RMF_F_STRUCT_ARRAY | RMF_F_NO_SIZE_CHECK)) {
len = lustre_msg_buflen(msg, offset);
if (!(field->rmf_flags & RMF_F_NO_SIZE_CHECK) &&
(len % field->rmf_size)) {
CERROR("%s: array field size mismatch %d modulo %u != 0 (%d)\n",
field->rmf_name, len, field->rmf_size, loc);
return NULL;
}
} else if (pill->rc_area[loc][offset] != -1) {
len = pill->rc_area[loc][offset];
} else {
len = max_t(typeof(field->rmf_size), field->rmf_size, 0);
}
value = getter(msg, offset, len);
if (!value) {
DEBUG_REQ(D_ERROR, pill->rc_req,
"Wrong buffer for field `%s' (%u of %u) in format `%s': %u vs. %u (%s)\n",
field->rmf_name, offset, lustre_msg_bufcount(msg),
fmt->rf_name, lustre_msg_buflen(msg, offset), len,
rcl_names[loc]);
} else {
swabber_dumper_helper(pill, field, loc, offset, value, len,
dump, swabber);
}
return value;
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
u32 len)
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
u32 len)
{
req_capsule_set_size(pill, field, RCL_SERVER, len);
return __req_capsule_get(pill, field, RCL_SERVER, NULL, 0);
}
void *req_capsule_server_sized_swab_get(struct req_capsule *pill,
const struct req_msg_field *field,
u32 len, void *swabber)
{
req_capsule_set_size(pill, field, RCL_SERVER, len);
return __req_capsule_get(pill, field, RCL_SERVER, swabber, 0);
}
void req_capsule_set_size(struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc, u32 size)
{
LASSERT(loc == RCL_SERVER || loc == RCL_CLIENT);
if ((size != (u32)field->rmf_size) &&
(field->rmf_size != -1) &&
!(field->rmf_flags & RMF_F_NO_SIZE_CHECK) &&
(size > 0)) {
u32 rmf_size = (u32)field->rmf_size;
if ((field->rmf_flags & RMF_F_STRUCT_ARRAY) &&
(size % rmf_size != 0)) {
CERROR("%s: array field size mismatch %u %% %u != 0 (%d)\n",
field->rmf_name, size, rmf_size, loc);
LBUG();
} else if (!(field->rmf_flags & RMF_F_STRUCT_ARRAY) &&
size < rmf_size) {
CERROR("%s: field size mismatch %u != %u (%d)\n",
field->rmf_name, size, rmf_size, loc);
LBUG();
}
}
pill->rc_area[loc][__req_capsule_offset(pill, field, loc)] = size;
}
u32 req_capsule_get_size(const struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc)
{
LASSERT(loc == RCL_SERVER || loc == RCL_CLIENT);
return lustre_msg_buflen(__req_msg(pill, loc),
__req_capsule_offset(pill, field, loc));
}
u32 req_capsule_msg_size(struct req_capsule *pill, enum req_location loc)
{
return lustre_msg_size(pill->rc_req->rq_import->imp_msg_magic,
pill->rc_fmt->rf_fields[loc].nr,
pill->rc_area[loc]);
}
u32 req_capsule_fmt_size(__u32 magic, const struct req_format *fmt,
enum req_location loc)
{
size_t i = 0;
u32 size;
size = lustre_msg_hdr_size(magic, fmt->rf_fields[loc].nr);
if (!size)
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
size_t j;
const struct req_format *old;
LASSERT(pill->rc_fmt);
LASSERT(__req_format_is_sane(fmt));
old = pill->rc_fmt;
for (i = 0; i < RCL_NR; ++i) {
LASSERT(fmt->rf_fields[i].nr >= old->rf_fields[i].nr);
for (j = 0; j < old->rf_fields[i].nr - 1; ++j) {
const struct req_msg_field *ofield = FMT_FIELD(old, i, j);
if (!ofield->rmf_swabber &&
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
static int req_capsule_field_present(const struct req_capsule *pill,
const struct req_msg_field *field,
enum req_location loc)
{
u32 offset;
LASSERT(loc == RCL_SERVER || loc == RCL_CLIENT);
LASSERT(req_capsule_has_field(pill, field, loc));
offset = __req_capsule_offset(pill, field, loc);
return lustre_msg_bufcount(__req_msg(pill, loc)) > offset;
}
void req_capsule_shrink(struct req_capsule *pill,
const struct req_msg_field *field,
u32 newlen, enum req_location loc)
{
const struct req_format *fmt;
struct lustre_msg *msg;
u32 len;
int offset;
fmt = pill->rc_fmt;
LASSERT(fmt);
LASSERT(__req_format_is_sane(fmt));
LASSERT(req_capsule_has_field(pill, field, loc));
LASSERT(req_capsule_field_present(pill, field, loc));
offset = __req_capsule_offset(pill, field, loc);
msg = __req_msg(pill, loc);
len = lustre_msg_buflen(msg, offset);
LASSERTF(newlen <= len, "%s:%s, oldlen=%u, newlen=%u\n",
fmt->rf_name, field->rmf_name, len, newlen);
if (loc == RCL_CLIENT)
pill->rc_req->rq_reqlen = lustre_shrink_msg(msg, offset, newlen,
1);
else
pill->rc_req->rq_replen = lustre_shrink_msg(msg, offset, newlen,
1);
}
