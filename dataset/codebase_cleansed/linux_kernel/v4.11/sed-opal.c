static const char *opal_error_to_human(int error)
{
if (error == 0x3f)
return "Failed";
if (error >= ARRAY_SIZE(opal_errors) || error < 0)
return "Unknown Error";
return opal_errors[error];
}
static void print_buffer(const u8 *ptr, u32 length)
{
#ifdef DEBUG
print_hex_dump_bytes("OPAL: ", DUMP_PREFIX_OFFSET, ptr, length);
pr_debug("\n");
#endif
}
static bool check_tper(const void *data)
{
const struct d0_tper_features *tper = data;
u8 flags = tper->supported_features;
if (!(flags & TPER_SYNC_SUPPORTED)) {
pr_err("TPer sync not supported. flags = %d\n",
tper->supported_features);
return false;
}
return true;
}
static bool check_sum(const void *data)
{
const struct d0_single_user_mode *sum = data;
u32 nlo = be32_to_cpu(sum->num_locking_objects);
if (nlo == 0) {
pr_err("Need at least one locking object.\n");
return false;
}
pr_debug("Number of locking objects: %d\n", nlo);
return true;
}
static u16 get_comid_v100(const void *data)
{
const struct d0_opal_v100 *v100 = data;
return be16_to_cpu(v100->baseComID);
}
static u16 get_comid_v200(const void *data)
{
const struct d0_opal_v200 *v200 = data;
return be16_to_cpu(v200->baseComID);
}
static int opal_send_cmd(struct opal_dev *dev)
{
return dev->send_recv(dev->data, dev->comid, TCG_SECP_01,
dev->cmd, IO_BUFFER_LENGTH,
true);
}
static int opal_recv_cmd(struct opal_dev *dev)
{
return dev->send_recv(dev->data, dev->comid, TCG_SECP_01,
dev->resp, IO_BUFFER_LENGTH,
false);
}
static int opal_recv_check(struct opal_dev *dev)
{
size_t buflen = IO_BUFFER_LENGTH;
void *buffer = dev->resp;
struct opal_header *hdr = buffer;
int ret;
do {
pr_debug("Sent OPAL command: outstanding=%d, minTransfer=%d\n",
hdr->cp.outstandingData,
hdr->cp.minTransfer);
if (hdr->cp.outstandingData == 0 ||
hdr->cp.minTransfer != 0)
return 0;
memset(buffer, 0, buflen);
ret = opal_recv_cmd(dev);
} while (!ret);
return ret;
}
static int opal_send_recv(struct opal_dev *dev, cont_fn *cont)
{
int ret;
ret = opal_send_cmd(dev);
if (ret)
return ret;
ret = opal_recv_cmd(dev);
if (ret)
return ret;
ret = opal_recv_check(dev);
if (ret)
return ret;
return cont(dev);
}
static void check_geometry(struct opal_dev *dev, const void *data)
{
const struct d0_geometry_features *geo = data;
dev->align = geo->alignment_granularity;
dev->lowest_lba = geo->lowest_aligned_lba;
}
static int next(struct opal_dev *dev)
{
const struct opal_step *step;
int state = 0, error = 0;
do {
step = &dev->steps[state];
if (!step->fn)
break;
error = step->fn(dev, step->data);
if (error) {
pr_err("Error on step function: %d with error %d: %s\n",
state, error,
opal_error_to_human(error));
if (state > 1) {
end_opal_session_error(dev);
return error;
}
}
state++;
} while (!error);
return error;
}
static int opal_discovery0_end(struct opal_dev *dev)
{
bool found_com_id = false, supported = true, single_user = false;
const struct d0_header *hdr = (struct d0_header *)dev->resp;
const u8 *epos = dev->resp, *cpos = dev->resp;
u16 comid = 0;
u32 hlen = be32_to_cpu(hdr->length);
print_buffer(dev->resp, hlen);
if (hlen > IO_BUFFER_LENGTH - sizeof(*hdr)) {
pr_warn("Discovery length overflows buffer (%zu+%u)/%u\n",
sizeof(*hdr), hlen, IO_BUFFER_LENGTH);
return -EFAULT;
}
epos += hlen;
cpos += sizeof(*hdr);
while (cpos < epos && supported) {
const struct d0_features *body =
(const struct d0_features *)cpos;
switch (be16_to_cpu(body->code)) {
case FC_TPER:
supported = check_tper(body->features);
break;
case FC_SINGLEUSER:
single_user = check_sum(body->features);
break;
case FC_GEOMETRY:
check_geometry(dev, body);
break;
case FC_LOCKING:
case FC_ENTERPRISE:
case FC_DATASTORE:
pr_debug("Found OPAL feature description: %d\n",
be16_to_cpu(body->code));
break;
case FC_OPALV100:
comid = get_comid_v100(body->features);
found_com_id = true;
break;
case FC_OPALV200:
comid = get_comid_v200(body->features);
found_com_id = true;
break;
case 0xbfff ... 0xffff:
break;
default:
pr_debug("OPAL Unknown feature: %d\n",
be16_to_cpu(body->code));
}
cpos += body->length + 4;
}
if (!supported) {
pr_debug("This device is not Opal enabled. Not Supported!\n");
return -EOPNOTSUPP;
}
if (!single_user)
pr_debug("Device doesn't support single user mode\n");
if (!found_com_id) {
pr_debug("Could not find OPAL comid for device. Returning early\n");
return -EOPNOTSUPP;;
}
dev->comid = comid;
return 0;
}
static int opal_discovery0(struct opal_dev *dev, void *data)
{
int ret;
memset(dev->resp, 0, IO_BUFFER_LENGTH);
dev->comid = OPAL_DISCOVERY_COMID;
ret = opal_recv_cmd(dev);
if (ret)
return ret;
return opal_discovery0_end(dev);
}
static void add_token_u8(int *err, struct opal_dev *cmd, u8 tok)
{
if (*err)
return;
if (cmd->pos >= IO_BUFFER_LENGTH - 1) {
pr_err("Error adding u8: end of buffer.\n");
*err = -ERANGE;
return;
}
cmd->cmd[cmd->pos++] = tok;
}
static void add_short_atom_header(struct opal_dev *cmd, bool bytestring,
bool has_sign, int len)
{
u8 atom;
int err = 0;
atom = SHORT_ATOM_ID;
atom |= bytestring ? SHORT_ATOM_BYTESTRING : 0;
atom |= has_sign ? SHORT_ATOM_SIGNED : 0;
atom |= len & SHORT_ATOM_LEN_MASK;
add_token_u8(&err, cmd, atom);
}
static void add_medium_atom_header(struct opal_dev *cmd, bool bytestring,
bool has_sign, int len)
{
u8 header0;
header0 = MEDIUM_ATOM_ID;
header0 |= bytestring ? MEDIUM_ATOM_BYTESTRING : 0;
header0 |= has_sign ? MEDIUM_ATOM_SIGNED : 0;
header0 |= (len >> 8) & MEDIUM_ATOM_LEN_MASK;
cmd->cmd[cmd->pos++] = header0;
cmd->cmd[cmd->pos++] = len;
}
static void add_token_u64(int *err, struct opal_dev *cmd, u64 number)
{
size_t len;
int msb;
u8 n;
if (!(number & ~TINY_ATOM_DATA_MASK)) {
add_token_u8(err, cmd, number);
return;
}
msb = fls(number);
len = DIV_ROUND_UP(msb, 4);
if (cmd->pos >= IO_BUFFER_LENGTH - len - 1) {
pr_err("Error adding u64: end of buffer.\n");
*err = -ERANGE;
return;
}
add_short_atom_header(cmd, false, false, len);
while (len--) {
n = number >> (len * 8);
add_token_u8(err, cmd, n);
}
}
static void add_token_bytestring(int *err, struct opal_dev *cmd,
const u8 *bytestring, size_t len)
{
size_t header_len = 1;
bool is_short_atom = true;
if (*err)
return;
if (len & ~SHORT_ATOM_LEN_MASK) {
header_len = 2;
is_short_atom = false;
}
if (len >= IO_BUFFER_LENGTH - cmd->pos - header_len) {
pr_err("Error adding bytestring: end of buffer.\n");
*err = -ERANGE;
return;
}
if (is_short_atom)
add_short_atom_header(cmd, true, false, len);
else
add_medium_atom_header(cmd, true, false, len);
memcpy(&cmd->cmd[cmd->pos], bytestring, len);
cmd->pos += len;
}
static int build_locking_range(u8 *buffer, size_t length, u8 lr)
{
if (length > OPAL_UID_LENGTH) {
pr_err("Can't build locking range. Length OOB\n");
return -ERANGE;
}
memcpy(buffer, opaluid[OPAL_LOCKINGRANGE_GLOBAL], OPAL_UID_LENGTH);
if (lr == 0)
return 0;
buffer[5] = LOCKING_RANGE_NON_GLOBAL;
buffer[7] = lr;
return 0;
}
static int build_locking_user(u8 *buffer, size_t length, u8 lr)
{
if (length > OPAL_UID_LENGTH) {
pr_err("Can't build locking range user, Length OOB\n");
return -ERANGE;
}
memcpy(buffer, opaluid[OPAL_USER1_UID], OPAL_UID_LENGTH);
buffer[7] = lr + 1;
return 0;
}
static void set_comid(struct opal_dev *cmd, u16 comid)
{
struct opal_header *hdr = (struct opal_header *)cmd->cmd;
hdr->cp.extendedComID[0] = comid >> 8;
hdr->cp.extendedComID[1] = comid;
hdr->cp.extendedComID[2] = 0;
hdr->cp.extendedComID[3] = 0;
}
static int cmd_finalize(struct opal_dev *cmd, u32 hsn, u32 tsn)
{
struct opal_header *hdr;
int err = 0;
add_token_u8(&err, cmd, OPAL_ENDOFDATA);
add_token_u8(&err, cmd, OPAL_STARTLIST);
add_token_u8(&err, cmd, 0);
add_token_u8(&err, cmd, 0);
add_token_u8(&err, cmd, 0);
add_token_u8(&err, cmd, OPAL_ENDLIST);
if (err) {
pr_err("Error finalizing command.\n");
return -EFAULT;
}
hdr = (struct opal_header *) cmd->cmd;
hdr->pkt.tsn = cpu_to_be32(tsn);
hdr->pkt.hsn = cpu_to_be32(hsn);
hdr->subpkt.length = cpu_to_be32(cmd->pos - sizeof(*hdr));
while (cmd->pos % 4) {
if (cmd->pos >= IO_BUFFER_LENGTH) {
pr_err("Error: Buffer overrun\n");
return -ERANGE;
}
cmd->cmd[cmd->pos++] = 0;
}
hdr->pkt.length = cpu_to_be32(cmd->pos - sizeof(hdr->cp) -
sizeof(hdr->pkt));
hdr->cp.length = cpu_to_be32(cmd->pos - sizeof(hdr->cp));
return 0;
}
static const struct opal_resp_tok *response_get_token(
const struct parsed_resp *resp,
int n)
{
const struct opal_resp_tok *tok;
if (n >= resp->num) {
pr_err("Token number doesn't exist: %d, resp: %d\n",
n, resp->num);
return ERR_PTR(-EINVAL);
}
tok = &resp->toks[n];
if (tok->len == 0) {
pr_err("Token length must be non-zero\n");
return ERR_PTR(-EINVAL);
}
return tok;
}
static ssize_t response_parse_tiny(struct opal_resp_tok *tok,
const u8 *pos)
{
tok->pos = pos;
tok->len = 1;
tok->width = OPAL_WIDTH_TINY;
if (pos[0] & TINY_ATOM_SIGNED) {
tok->type = OPAL_DTA_TOKENID_SINT;
} else {
tok->type = OPAL_DTA_TOKENID_UINT;
tok->stored.u = pos[0] & 0x3f;
}
return tok->len;
}
static ssize_t response_parse_short(struct opal_resp_tok *tok,
const u8 *pos)
{
tok->pos = pos;
tok->len = (pos[0] & SHORT_ATOM_LEN_MASK) + 1;
tok->width = OPAL_WIDTH_SHORT;
if (pos[0] & SHORT_ATOM_BYTESTRING) {
tok->type = OPAL_DTA_TOKENID_BYTESTRING;
} else if (pos[0] & SHORT_ATOM_SIGNED) {
tok->type = OPAL_DTA_TOKENID_SINT;
} else {
u64 u_integer = 0;
ssize_t i, b = 0;
tok->type = OPAL_DTA_TOKENID_UINT;
if (tok->len > 9) {
pr_warn("uint64 with more than 8 bytes\n");
return -EINVAL;
}
for (i = tok->len - 1; i > 0; i--) {
u_integer |= ((u64)pos[i] << (8 * b));
b++;
}
tok->stored.u = u_integer;
}
return tok->len;
}
static ssize_t response_parse_medium(struct opal_resp_tok *tok,
const u8 *pos)
{
tok->pos = pos;
tok->len = (((pos[0] & MEDIUM_ATOM_LEN_MASK) << 8) | pos[1]) + 2;
tok->width = OPAL_WIDTH_MEDIUM;
if (pos[0] & MEDIUM_ATOM_BYTESTRING)
tok->type = OPAL_DTA_TOKENID_BYTESTRING;
else if (pos[0] & MEDIUM_ATOM_SIGNED)
tok->type = OPAL_DTA_TOKENID_SINT;
else
tok->type = OPAL_DTA_TOKENID_UINT;
return tok->len;
}
static ssize_t response_parse_long(struct opal_resp_tok *tok,
const u8 *pos)
{
tok->pos = pos;
tok->len = ((pos[1] << 16) | (pos[2] << 8) | pos[3]) + 4;
tok->width = OPAL_WIDTH_LONG;
if (pos[0] & LONG_ATOM_BYTESTRING)
tok->type = OPAL_DTA_TOKENID_BYTESTRING;
else if (pos[0] & LONG_ATOM_SIGNED)
tok->type = OPAL_DTA_TOKENID_SINT;
else
tok->type = OPAL_DTA_TOKENID_UINT;
return tok->len;
}
static ssize_t response_parse_token(struct opal_resp_tok *tok,
const u8 *pos)
{
tok->pos = pos;
tok->len = 1;
tok->type = OPAL_DTA_TOKENID_TOKEN;
tok->width = OPAL_WIDTH_TOKEN;
return tok->len;
}
static int response_parse(const u8 *buf, size_t length,
struct parsed_resp *resp)
{
const struct opal_header *hdr;
struct opal_resp_tok *iter;
int num_entries = 0;
int total;
ssize_t token_length;
const u8 *pos;
u32 clen, plen, slen;
if (!buf)
return -EFAULT;
if (!resp)
return -EFAULT;
hdr = (struct opal_header *)buf;
pos = buf;
pos += sizeof(*hdr);
clen = be32_to_cpu(hdr->cp.length);
plen = be32_to_cpu(hdr->pkt.length);
slen = be32_to_cpu(hdr->subpkt.length);
pr_debug("Response size: cp: %u, pkt: %u, subpkt: %u\n",
clen, plen, slen);
if (clen == 0 || plen == 0 || slen == 0 ||
slen > IO_BUFFER_LENGTH - sizeof(*hdr)) {
pr_err("Bad header length. cp: %u, pkt: %u, subpkt: %u\n",
clen, plen, slen);
print_buffer(pos, sizeof(*hdr));
return -EINVAL;
}
if (pos > buf + length)
return -EFAULT;
iter = resp->toks;
total = slen;
print_buffer(pos, total);
while (total > 0) {
if (pos[0] <= TINY_ATOM_BYTE)
token_length = response_parse_tiny(iter, pos);
else if (pos[0] <= SHORT_ATOM_BYTE)
token_length = response_parse_short(iter, pos);
else if (pos[0] <= MEDIUM_ATOM_BYTE)
token_length = response_parse_medium(iter, pos);
else if (pos[0] <= LONG_ATOM_BYTE)
token_length = response_parse_long(iter, pos);
else
token_length = response_parse_token(iter, pos);
if (token_length < 0)
return token_length;
pos += token_length;
total -= token_length;
iter++;
num_entries++;
}
if (num_entries == 0) {
pr_err("Couldn't parse response.\n");
return -EINVAL;
}
resp->num = num_entries;
return 0;
}
static size_t response_get_string(const struct parsed_resp *resp, int n,
const char **store)
{
*store = NULL;
if (!resp) {
pr_err("Response is NULL\n");
return 0;
}
if (n > resp->num) {
pr_err("Response has %d tokens. Can't access %d\n",
resp->num, n);
return 0;
}
if (resp->toks[n].type != OPAL_DTA_TOKENID_BYTESTRING) {
pr_err("Token is not a byte string!\n");
return 0;
}
*store = resp->toks[n].pos + 1;
return resp->toks[n].len - 1;
}
static u64 response_get_u64(const struct parsed_resp *resp, int n)
{
if (!resp) {
pr_err("Response is NULL\n");
return 0;
}
if (n > resp->num) {
pr_err("Response has %d tokens. Can't access %d\n",
resp->num, n);
return 0;
}
if (resp->toks[n].type != OPAL_DTA_TOKENID_UINT) {
pr_err("Token is not unsigned it: %d\n",
resp->toks[n].type);
return 0;
}
if (!(resp->toks[n].width == OPAL_WIDTH_TINY ||
resp->toks[n].width == OPAL_WIDTH_SHORT)) {
pr_err("Atom is not short or tiny: %d\n",
resp->toks[n].width);
return 0;
}
return resp->toks[n].stored.u;
}
static bool response_token_matches(const struct opal_resp_tok *token, u8 match)
{
if (IS_ERR(token) ||
token->type != OPAL_DTA_TOKENID_TOKEN ||
token->pos[0] != match)
return false;
return true;
}
static u8 response_status(const struct parsed_resp *resp)
{
const struct opal_resp_tok *tok;
tok = response_get_token(resp, 0);
if (response_token_matches(tok, OPAL_ENDOFSESSION))
return 0;
if (resp->num < 5)
return DTAERROR_NO_METHOD_STATUS;
tok = response_get_token(resp, resp->num - 5);
if (!response_token_matches(tok, OPAL_STARTLIST))
return DTAERROR_NO_METHOD_STATUS;
tok = response_get_token(resp, resp->num - 1);
if (!response_token_matches(tok, OPAL_ENDLIST))
return DTAERROR_NO_METHOD_STATUS;
return response_get_u64(resp, resp->num - 4);
}
static int parse_and_check_status(struct opal_dev *dev)
{
int error;
print_buffer(dev->cmd, dev->pos);
error = response_parse(dev->resp, IO_BUFFER_LENGTH, &dev->parsed);
if (error) {
pr_err("Couldn't parse response.\n");
return error;
}
return response_status(&dev->parsed);
}
static void clear_opal_cmd(struct opal_dev *dev)
{
dev->pos = sizeof(struct opal_header);
memset(dev->cmd, 0, IO_BUFFER_LENGTH);
}
static int start_opal_session_cont(struct opal_dev *dev)
{
u32 hsn, tsn;
int error = 0;
error = parse_and_check_status(dev);
if (error)
return error;
hsn = response_get_u64(&dev->parsed, 4);
tsn = response_get_u64(&dev->parsed, 5);
if (hsn == 0 && tsn == 0) {
pr_err("Couldn't authenticate session\n");
return -EPERM;
}
dev->hsn = hsn;
dev->tsn = tsn;
return 0;
}
static void add_suspend_info(struct opal_dev *dev,
struct opal_suspend_data *sus)
{
struct opal_suspend_data *iter;
list_for_each_entry(iter, &dev->unlk_lst, node) {
if (iter->lr == sus->lr) {
list_del(&iter->node);
kfree(iter);
break;
}
}
list_add_tail(&sus->node, &dev->unlk_lst);
}
static int end_session_cont(struct opal_dev *dev)
{
dev->hsn = 0;
dev->tsn = 0;
return parse_and_check_status(dev);
}
static int finalize_and_send(struct opal_dev *dev, cont_fn cont)
{
int ret;
ret = cmd_finalize(dev, dev->hsn, dev->tsn);
if (ret) {
pr_err("Error finalizing command buffer: %d\n", ret);
return ret;
}
print_buffer(dev->cmd, dev->pos);
return opal_send_recv(dev, cont);
}
static int gen_key(struct opal_dev *dev, void *data)
{
u8 uid[OPAL_UID_LENGTH];
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
memcpy(uid, dev->prev_data, min(sizeof(uid), dev->prev_d_len));
kfree(dev->prev_data);
dev->prev_data = NULL;
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, uid, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_GENKEY],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building gen key command\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int get_active_key_cont(struct opal_dev *dev)
{
const char *activekey;
size_t keylen;
int error = 0;
error = parse_and_check_status(dev);
if (error)
return error;
keylen = response_get_string(&dev->parsed, 4, &activekey);
if (!activekey) {
pr_err("%s: Couldn't extract the Activekey from the response\n",
__func__);
return OPAL_INVAL_PARAM;
}
dev->prev_data = kmemdup(activekey, keylen, GFP_KERNEL);
if (!dev->prev_data)
return -ENOMEM;
dev->prev_d_len = keylen;
return 0;
}
static int get_active_key(struct opal_dev *dev, void *data)
{
u8 uid[OPAL_UID_LENGTH];
int err = 0;
u8 *lr = data;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
err = build_locking_range(uid, sizeof(uid), *lr);
if (err)
return err;
err = 0;
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, uid, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_GET], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 3);
add_token_u8(&err, dev, 10);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 4);
add_token_u8(&err, dev, 10);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building get active key command\n");
return err;
}
return finalize_and_send(dev, get_active_key_cont);
}
static int generic_lr_enable_disable(struct opal_dev *dev,
u8 *uid, bool rle, bool wle,
bool rl, bool wl)
{
int err = 0;
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, uid, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_SET], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_VALUES);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 5);
add_token_u8(&err, dev, rle);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 6);
add_token_u8(&err, dev, wle);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_READLOCKED);
add_token_u8(&err, dev, rl);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_WRITELOCKED);
add_token_u8(&err, dev, wl);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
return err;
}
static inline int enable_global_lr(struct opal_dev *dev, u8 *uid,
struct opal_user_lr_setup *setup)
{
int err;
err = generic_lr_enable_disable(dev, uid, !!setup->RLE, !!setup->WLE,
0, 0);
if (err)
pr_err("Failed to create enable global lr command\n");
return err;
}
static int setup_locking_range(struct opal_dev *dev, void *data)
{
u8 uid[OPAL_UID_LENGTH];
struct opal_user_lr_setup *setup = data;
u8 lr;
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
lr = setup->session.opal_key.lr;
err = build_locking_range(uid, sizeof(uid), lr);
if (err)
return err;
if (lr == 0)
err = enable_global_lr(dev, uid, setup);
else {
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, uid, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_SET],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_VALUES);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 3);
add_token_u64(&err, dev, setup->range_start);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 4);
add_token_u64(&err, dev, setup->range_length);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 5);
add_token_u64(&err, dev, !!setup->RLE);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 6);
add_token_u64(&err, dev, !!setup->WLE);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
}
if (err) {
pr_err("Error building Setup Locking range command.\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int start_generic_opal_session(struct opal_dev *dev,
enum opal_uid auth,
enum opal_uid sp_type,
const char *key,
u8 key_len)
{
u32 hsn;
int err = 0;
if (key == NULL && auth != OPAL_ANYBODY_UID) {
pr_err("%s: Attempted to open ADMIN_SP Session without a Host" \
"Challenge, and not as the Anybody UID\n", __func__);
return OPAL_INVAL_PARAM;
}
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
hsn = GENERIC_HOST_SESSION_NUM;
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, opaluid[OPAL_SMUID_UID],
OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_STARTSESSION],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u64(&err, dev, hsn);
add_token_bytestring(&err, dev, opaluid[sp_type], OPAL_UID_LENGTH);
add_token_u8(&err, dev, 1);
switch (auth) {
case OPAL_ANYBODY_UID:
add_token_u8(&err, dev, OPAL_ENDLIST);
break;
case OPAL_ADMIN1_UID:
case OPAL_SID_UID:
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 0);
add_token_bytestring(&err, dev, key, key_len);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 3);
add_token_bytestring(&err, dev, opaluid[auth],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
break;
default:
pr_err("Cannot start Admin SP session with auth %d\n", auth);
return OPAL_INVAL_PARAM;
}
if (err) {
pr_err("Error building start adminsp session command.\n");
return err;
}
return finalize_and_send(dev, start_opal_session_cont);
}
static int start_anybodyASP_opal_session(struct opal_dev *dev, void *data)
{
return start_generic_opal_session(dev, OPAL_ANYBODY_UID,
OPAL_ADMINSP_UID, NULL, 0);
}
static int start_SIDASP_opal_session(struct opal_dev *dev, void *data)
{
int ret;
const u8 *key = dev->prev_data;
if (!key) {
const struct opal_key *okey = data;
ret = start_generic_opal_session(dev, OPAL_SID_UID,
OPAL_ADMINSP_UID,
okey->key,
okey->key_len);
} else {
ret = start_generic_opal_session(dev, OPAL_SID_UID,
OPAL_ADMINSP_UID,
key, dev->prev_d_len);
kfree(key);
dev->prev_data = NULL;
}
return ret;
}
static int start_admin1LSP_opal_session(struct opal_dev *dev, void *data)
{
struct opal_key *key = data;
return start_generic_opal_session(dev, OPAL_ADMIN1_UID,
OPAL_LOCKINGSP_UID,
key->key, key->key_len);
}
static int start_auth_opal_session(struct opal_dev *dev, void *data)
{
struct opal_session_info *session = data;
u8 lk_ul_user[OPAL_UID_LENGTH];
size_t keylen = session->opal_key.key_len;
int err = 0;
u8 *key = session->opal_key.key;
u32 hsn = GENERIC_HOST_SESSION_NUM;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
if (session->sum) {
err = build_locking_user(lk_ul_user, sizeof(lk_ul_user),
session->opal_key.lr);
if (err)
return err;
} else if (session->who != OPAL_ADMIN1 && !session->sum) {
err = build_locking_user(lk_ul_user, sizeof(lk_ul_user),
session->who - 1);
if (err)
return err;
} else
memcpy(lk_ul_user, opaluid[OPAL_ADMIN1_UID], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, opaluid[OPAL_SMUID_UID],
OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_STARTSESSION],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u64(&err, dev, hsn);
add_token_bytestring(&err, dev, opaluid[OPAL_LOCKINGSP_UID],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, 1);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 0);
add_token_bytestring(&err, dev, key, keylen);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 3);
add_token_bytestring(&err, dev, lk_ul_user, OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building STARTSESSION command.\n");
return err;
}
return finalize_and_send(dev, start_opal_session_cont);
}
static int revert_tper(struct opal_dev *dev, void *data)
{
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, opaluid[OPAL_ADMINSP_UID],
OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_REVERT],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building REVERT TPER command.\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int internal_activate_user(struct opal_dev *dev, void *data)
{
struct opal_session_info *session = data;
u8 uid[OPAL_UID_LENGTH];
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
memcpy(uid, opaluid[OPAL_USER1_UID], OPAL_UID_LENGTH);
uid[7] = session->who;
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, uid, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_SET], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_VALUES);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 5);
add_token_u8(&err, dev, OPAL_TRUE);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building Activate UserN command.\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int erase_locking_range(struct opal_dev *dev, void *data)
{
struct opal_session_info *session = data;
u8 uid[OPAL_UID_LENGTH];
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
if (build_locking_range(uid, sizeof(uid), session->opal_key.lr) < 0)
return -ERANGE;
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, uid, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_ERASE],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building Erase Locking Range Command.\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int set_mbr_done(struct opal_dev *dev, void *data)
{
u8 *mbr_done_tf = data;
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, opaluid[OPAL_MBRCONTROL],
OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_SET], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_VALUES);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 2);
add_token_u8(&err, dev, *mbr_done_tf);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error Building set MBR Done command\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int set_mbr_enable_disable(struct opal_dev *dev, void *data)
{
u8 *mbr_en_dis = data;
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, opaluid[OPAL_MBRCONTROL],
OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_SET], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_VALUES);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 1);
add_token_u8(&err, dev, *mbr_en_dis);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error Building set MBR done command\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int generic_pw_cmd(u8 *key, size_t key_len, u8 *cpin_uid,
struct opal_dev *dev)
{
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, cpin_uid, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_SET],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_VALUES);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 3);
add_token_bytestring(&err, dev, key, key_len);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
return err;
}
static int set_new_pw(struct opal_dev *dev, void *data)
{
u8 cpin_uid[OPAL_UID_LENGTH];
struct opal_session_info *usr = data;
memcpy(cpin_uid, opaluid[OPAL_C_PIN_ADMIN1], OPAL_UID_LENGTH);
if (usr->who != OPAL_ADMIN1) {
cpin_uid[5] = 0x03;
if (usr->sum)
cpin_uid[7] = usr->opal_key.lr + 1;
else
cpin_uid[7] = usr->who;
}
if (generic_pw_cmd(usr->opal_key.key, usr->opal_key.key_len,
cpin_uid, dev)) {
pr_err("Error building set password command.\n");
return -ERANGE;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int set_sid_cpin_pin(struct opal_dev *dev, void *data)
{
u8 cpin_uid[OPAL_UID_LENGTH];
struct opal_key *key = data;
memcpy(cpin_uid, opaluid[OPAL_C_PIN_SID], OPAL_UID_LENGTH);
if (generic_pw_cmd(key->key, key->key_len, cpin_uid, dev)) {
pr_err("Error building Set SID cpin\n");
return -ERANGE;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int add_user_to_lr(struct opal_dev *dev, void *data)
{
u8 lr_buffer[OPAL_UID_LENGTH];
u8 user_uid[OPAL_UID_LENGTH];
struct opal_lock_unlock *lkul = data;
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
memcpy(lr_buffer, opaluid[OPAL_LOCKINGRANGE_ACE_RDLOCKED],
OPAL_UID_LENGTH);
if (lkul->l_state == OPAL_RW)
memcpy(lr_buffer, opaluid[OPAL_LOCKINGRANGE_ACE_WRLOCKED],
OPAL_UID_LENGTH);
lr_buffer[7] = lkul->session.opal_key.lr;
memcpy(user_uid, opaluid[OPAL_USER1_UID], OPAL_UID_LENGTH);
user_uid[7] = lkul->session.who;
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, lr_buffer, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_SET],
OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_VALUES);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 3);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_bytestring(&err, dev,
opaluid[OPAL_HALF_UID_AUTHORITY_OBJ_REF],
OPAL_UID_LENGTH/2);
add_token_bytestring(&err, dev, user_uid, OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_bytestring(&err, dev,
opaluid[OPAL_HALF_UID_AUTHORITY_OBJ_REF],
OPAL_UID_LENGTH/2);
add_token_bytestring(&err, dev, user_uid, OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_bytestring(&err, dev, opaluid[OPAL_HALF_UID_BOOLEAN_ACE],
OPAL_UID_LENGTH/2);
add_token_u8(&err, dev, 1);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building add user to locking range command.\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int lock_unlock_locking_range(struct opal_dev *dev, void *data)
{
u8 lr_buffer[OPAL_UID_LENGTH];
struct opal_lock_unlock *lkul = data;
u8 read_locked = 1, write_locked = 1;
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
if (build_locking_range(lr_buffer, sizeof(lr_buffer),
lkul->session.opal_key.lr) < 0)
return -ERANGE;
switch (lkul->l_state) {
case OPAL_RO:
read_locked = 0;
write_locked = 1;
break;
case OPAL_RW:
read_locked = 0;
write_locked = 0;
break;
case OPAL_LK:
break;
default:
pr_err("Tried to set an invalid locking state... returning to uland\n");
return OPAL_INVAL_PARAM;
}
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, lr_buffer, OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_SET], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_VALUES);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_READLOCKED);
add_token_u8(&err, dev, read_locked);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, OPAL_WRITELOCKED);
add_token_u8(&err, dev, write_locked);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building SET command.\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int lock_unlock_locking_range_sum(struct opal_dev *dev, void *data)
{
u8 lr_buffer[OPAL_UID_LENGTH];
u8 read_locked = 1, write_locked = 1;
struct opal_lock_unlock *lkul = data;
int ret;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
if (build_locking_range(lr_buffer, sizeof(lr_buffer),
lkul->session.opal_key.lr) < 0)
return -ERANGE;
switch (lkul->l_state) {
case OPAL_RO:
read_locked = 0;
write_locked = 1;
break;
case OPAL_RW:
read_locked = 0;
write_locked = 0;
break;
case OPAL_LK:
break;
default:
pr_err("Tried to set an invalid locking state.\n");
return OPAL_INVAL_PARAM;
}
ret = generic_lr_enable_disable(dev, lr_buffer, 1, 1,
read_locked, write_locked);
if (ret < 0) {
pr_err("Error building SET command.\n");
return ret;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int activate_lsp(struct opal_dev *dev, void *data)
{
struct opal_lr_act *opal_act = data;
u8 user_lr[OPAL_UID_LENGTH];
u8 uint_3 = 0x83;
int err = 0, i;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, opaluid[OPAL_LOCKINGSP_UID],
OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_ACTIVATE],
OPAL_UID_LENGTH);
if (opal_act->sum) {
err = build_locking_range(user_lr, sizeof(user_lr),
opal_act->lr[0]);
if (err)
return err;
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, uint_3);
add_token_u8(&err, dev, 6);
add_token_u8(&err, dev, 0);
add_token_u8(&err, dev, 0);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_bytestring(&err, dev, user_lr, OPAL_UID_LENGTH);
for (i = 1; i < opal_act->num_lrs; i++) {
user_lr[7] = opal_act->lr[i];
add_token_bytestring(&err, dev, user_lr, OPAL_UID_LENGTH);
}
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
} else {
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_ENDLIST);
}
if (err) {
pr_err("Error building Activate LockingSP command.\n");
return err;
}
return finalize_and_send(dev, parse_and_check_status);
}
static int get_lsp_lifecycle_cont(struct opal_dev *dev)
{
u8 lc_status;
int error = 0;
error = parse_and_check_status(dev);
if (error)
return error;
lc_status = response_get_u64(&dev->parsed, 4);
if (lc_status != OPAL_MANUFACTURED_INACTIVE) {
pr_err("Couldn't determine the status of the Lifcycle state\n");
return -ENODEV;
}
return 0;
}
static int get_lsp_lifecycle(struct opal_dev *dev, void *data)
{
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, opaluid[OPAL_LOCKINGSP_UID],
OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_GET], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 3);
add_token_u8(&err, dev, 6);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 4);
add_token_u8(&err, dev, 6);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error Building GET Lifecycle Status command\n");
return err;
}
return finalize_and_send(dev, get_lsp_lifecycle_cont);
}
static int get_msid_cpin_pin_cont(struct opal_dev *dev)
{
const char *msid_pin;
size_t strlen;
int error = 0;
error = parse_and_check_status(dev);
if (error)
return error;
strlen = response_get_string(&dev->parsed, 4, &msid_pin);
if (!msid_pin) {
pr_err("%s: Couldn't extract PIN from response\n", __func__);
return OPAL_INVAL_PARAM;
}
dev->prev_data = kmemdup(msid_pin, strlen, GFP_KERNEL);
if (!dev->prev_data)
return -ENOMEM;
dev->prev_d_len = strlen;
return 0;
}
static int get_msid_cpin_pin(struct opal_dev *dev, void *data)
{
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
add_token_u8(&err, dev, OPAL_CALL);
add_token_bytestring(&err, dev, opaluid[OPAL_C_PIN_MSID],
OPAL_UID_LENGTH);
add_token_bytestring(&err, dev, opalmethod[OPAL_GET], OPAL_UID_LENGTH);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTLIST);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 3);
add_token_u8(&err, dev, 3);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_STARTNAME);
add_token_u8(&err, dev, 4);
add_token_u8(&err, dev, 3);
add_token_u8(&err, dev, OPAL_ENDNAME);
add_token_u8(&err, dev, OPAL_ENDLIST);
add_token_u8(&err, dev, OPAL_ENDLIST);
if (err) {
pr_err("Error building Get MSID CPIN PIN command.\n");
return err;
}
return finalize_and_send(dev, get_msid_cpin_pin_cont);
}
static int end_opal_session(struct opal_dev *dev, void *data)
{
int err = 0;
clear_opal_cmd(dev);
set_comid(dev, dev->comid);
add_token_u8(&err, dev, OPAL_ENDOFSESSION);
if (err < 0)
return err;
return finalize_and_send(dev, end_session_cont);
}
static int end_opal_session_error(struct opal_dev *dev)
{
const struct opal_step error_end_session[] = {
{ end_opal_session, },
{ NULL, }
};
dev->steps = error_end_session;
return next(dev);
}
static inline void setup_opal_dev(struct opal_dev *dev,
const struct opal_step *steps)
{
dev->steps = steps;
dev->tsn = 0;
dev->hsn = 0;
dev->prev_data = NULL;
}
static int check_opal_support(struct opal_dev *dev)
{
const struct opal_step steps[] = {
{ opal_discovery0, },
{ NULL, }
};
int ret;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, steps);
ret = next(dev);
dev->supported = !ret;
mutex_unlock(&dev->dev_lock);
return ret;
}
static void clean_opal_dev(struct opal_dev *dev)
{
struct opal_suspend_data *suspend, *next;
mutex_lock(&dev->dev_lock);
list_for_each_entry_safe(suspend, next, &dev->unlk_lst, node) {
list_del(&suspend->node);
kfree(suspend);
}
mutex_unlock(&dev->dev_lock);
}
void free_opal_dev(struct opal_dev *dev)
{
if (!dev)
return;
clean_opal_dev(dev);
kfree(dev);
}
struct opal_dev *init_opal_dev(void *data, sec_send_recv *send_recv)
{
struct opal_dev *dev;
dev = kmalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return NULL;
INIT_LIST_HEAD(&dev->unlk_lst);
mutex_init(&dev->dev_lock);
dev->data = data;
dev->send_recv = send_recv;
if (check_opal_support(dev) != 0) {
pr_debug("Opal is not supported on this device\n");
kfree(dev);
return NULL;
}
return dev;
}
static int opal_secure_erase_locking_range(struct opal_dev *dev,
struct opal_session_info *opal_session)
{
const struct opal_step erase_steps[] = {
{ opal_discovery0, },
{ start_auth_opal_session, opal_session },
{ get_active_key, &opal_session->opal_key.lr },
{ gen_key, },
{ end_opal_session, },
{ NULL, }
};
int ret;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, erase_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_erase_locking_range(struct opal_dev *dev,
struct opal_session_info *opal_session)
{
const struct opal_step erase_steps[] = {
{ opal_discovery0, },
{ start_auth_opal_session, opal_session },
{ erase_locking_range, opal_session },
{ end_opal_session, },
{ NULL, }
};
int ret;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, erase_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_enable_disable_shadow_mbr(struct opal_dev *dev,
struct opal_mbr_data *opal_mbr)
{
const struct opal_step mbr_steps[] = {
{ opal_discovery0, },
{ start_admin1LSP_opal_session, &opal_mbr->key },
{ set_mbr_done, &opal_mbr->enable_disable },
{ end_opal_session, },
{ start_admin1LSP_opal_session, &opal_mbr->key },
{ set_mbr_enable_disable, &opal_mbr->enable_disable },
{ end_opal_session, },
{ NULL, }
};
int ret;
if (opal_mbr->enable_disable != OPAL_MBR_ENABLE &&
opal_mbr->enable_disable != OPAL_MBR_DISABLE)
return -EINVAL;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, mbr_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_save(struct opal_dev *dev, struct opal_lock_unlock *lk_unlk)
{
struct opal_suspend_data *suspend;
suspend = kzalloc(sizeof(*suspend), GFP_KERNEL);
if (!suspend)
return -ENOMEM;
suspend->unlk = *lk_unlk;
suspend->lr = lk_unlk->session.opal_key.lr;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, NULL);
add_suspend_info(dev, suspend);
mutex_unlock(&dev->dev_lock);
return 0;
}
static int opal_add_user_to_lr(struct opal_dev *dev,
struct opal_lock_unlock *lk_unlk)
{
const struct opal_step steps[] = {
{ opal_discovery0, },
{ start_admin1LSP_opal_session, &lk_unlk->session.opal_key },
{ add_user_to_lr, lk_unlk },
{ end_opal_session, },
{ NULL, }
};
int ret;
if (lk_unlk->l_state != OPAL_RO &&
lk_unlk->l_state != OPAL_RW) {
pr_err("Locking state was not RO or RW\n");
return -EINVAL;
}
if (lk_unlk->session.who < OPAL_USER1 ||
lk_unlk->session.who > OPAL_USER9) {
pr_err("Authority was not within the range of users: %d\n",
lk_unlk->session.who);
return -EINVAL;
}
if (lk_unlk->session.sum) {
pr_err("%s not supported in sum. Use setup locking range\n",
__func__);
return -EINVAL;
}
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_reverttper(struct opal_dev *dev, struct opal_key *opal)
{
const struct opal_step revert_steps[] = {
{ opal_discovery0, },
{ start_SIDASP_opal_session, opal },
{ revert_tper, },
{ NULL, }
};
int ret;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, revert_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
if (!ret)
clean_opal_dev(dev);
return ret;
}
static int __opal_lock_unlock(struct opal_dev *dev,
struct opal_lock_unlock *lk_unlk)
{
const struct opal_step unlock_steps[] = {
{ opal_discovery0, },
{ start_auth_opal_session, &lk_unlk->session },
{ lock_unlock_locking_range, lk_unlk },
{ end_opal_session, },
{ NULL, }
};
const struct opal_step unlock_sum_steps[] = {
{ opal_discovery0, },
{ start_auth_opal_session, &lk_unlk->session },
{ lock_unlock_locking_range_sum, lk_unlk },
{ end_opal_session, },
{ NULL, }
};
dev->steps = lk_unlk->session.sum ? unlock_sum_steps : unlock_steps;
return next(dev);
}
static int opal_lock_unlock(struct opal_dev *dev,
struct opal_lock_unlock *lk_unlk)
{
int ret;
if (lk_unlk->session.who < OPAL_ADMIN1 ||
lk_unlk->session.who > OPAL_USER9)
return -EINVAL;
mutex_lock(&dev->dev_lock);
ret = __opal_lock_unlock(dev, lk_unlk);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_take_ownership(struct opal_dev *dev, struct opal_key *opal)
{
const struct opal_step owner_steps[] = {
{ opal_discovery0, },
{ start_anybodyASP_opal_session, },
{ get_msid_cpin_pin, },
{ end_opal_session, },
{ start_SIDASP_opal_session, opal },
{ set_sid_cpin_pin, opal },
{ end_opal_session, },
{ NULL, }
};
int ret;
if (!dev)
return -ENODEV;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, owner_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_activate_lsp(struct opal_dev *dev, struct opal_lr_act *opal_lr_act)
{
const struct opal_step active_steps[] = {
{ opal_discovery0, },
{ start_SIDASP_opal_session, &opal_lr_act->key },
{ get_lsp_lifecycle, },
{ activate_lsp, opal_lr_act },
{ end_opal_session, },
{ NULL, }
};
int ret;
if (!opal_lr_act->num_lrs || opal_lr_act->num_lrs > OPAL_MAX_LRS)
return -EINVAL;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, active_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_setup_locking_range(struct opal_dev *dev,
struct opal_user_lr_setup *opal_lrs)
{
const struct opal_step lr_steps[] = {
{ opal_discovery0, },
{ start_auth_opal_session, &opal_lrs->session },
{ setup_locking_range, opal_lrs },
{ end_opal_session, },
{ NULL, }
};
int ret;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, lr_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_set_new_pw(struct opal_dev *dev, struct opal_new_pw *opal_pw)
{
const struct opal_step pw_steps[] = {
{ opal_discovery0, },
{ start_auth_opal_session, &opal_pw->session },
{ set_new_pw, &opal_pw->new_user_pw },
{ end_opal_session, },
{ NULL }
};
int ret;
if (opal_pw->session.who < OPAL_ADMIN1 ||
opal_pw->session.who > OPAL_USER9 ||
opal_pw->new_user_pw.who < OPAL_ADMIN1 ||
opal_pw->new_user_pw.who > OPAL_USER9)
return -EINVAL;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, pw_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
static int opal_activate_user(struct opal_dev *dev,
struct opal_session_info *opal_session)
{
const struct opal_step act_steps[] = {
{ opal_discovery0, },
{ start_admin1LSP_opal_session, &opal_session->opal_key },
{ internal_activate_user, opal_session },
{ end_opal_session, },
{ NULL, }
};
int ret;
if (opal_session->who < OPAL_USER1 ||
opal_session->who > OPAL_USER9) {
pr_err("Who was not a valid user: %d\n", opal_session->who);
return -EINVAL;
}
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, act_steps);
ret = next(dev);
mutex_unlock(&dev->dev_lock);
return ret;
}
bool opal_unlock_from_suspend(struct opal_dev *dev)
{
struct opal_suspend_data *suspend;
bool was_failure = false;
int ret = 0;
if (!dev)
return false;
if (!dev->supported)
return false;
mutex_lock(&dev->dev_lock);
setup_opal_dev(dev, NULL);
list_for_each_entry(suspend, &dev->unlk_lst, node) {
dev->tsn = 0;
dev->hsn = 0;
ret = __opal_lock_unlock(dev, &suspend->unlk);
if (ret) {
pr_warn("Failed to unlock LR %hhu with sum %d\n",
suspend->unlk.session.opal_key.lr,
suspend->unlk.session.sum);
was_failure = true;
}
}
mutex_unlock(&dev->dev_lock);
return was_failure;
}
int sed_ioctl(struct opal_dev *dev, unsigned int cmd, void __user *arg)
{
void *p;
int ret = -ENOTTY;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (!dev)
return -ENOTSUPP;
if (!dev->supported) {
pr_err("Not supported\n");
return -ENOTSUPP;
}
p = memdup_user(arg, _IOC_SIZE(cmd));
if (IS_ERR(p))
return PTR_ERR(p);
switch (cmd) {
case IOC_OPAL_SAVE:
ret = opal_save(dev, p);
break;
case IOC_OPAL_LOCK_UNLOCK:
ret = opal_lock_unlock(dev, p);
break;
case IOC_OPAL_TAKE_OWNERSHIP:
ret = opal_take_ownership(dev, p);
break;
case IOC_OPAL_ACTIVATE_LSP:
ret = opal_activate_lsp(dev, p);
break;
case IOC_OPAL_SET_PW:
ret = opal_set_new_pw(dev, p);
break;
case IOC_OPAL_ACTIVATE_USR:
ret = opal_activate_user(dev, p);
break;
case IOC_OPAL_REVERT_TPR:
ret = opal_reverttper(dev, p);
break;
case IOC_OPAL_LR_SETUP:
ret = opal_setup_locking_range(dev, p);
break;
case IOC_OPAL_ADD_USR_TO_LR:
ret = opal_add_user_to_lr(dev, p);
break;
case IOC_OPAL_ENABLE_DISABLE_MBR:
ret = opal_enable_disable_shadow_mbr(dev, p);
break;
case IOC_OPAL_ERASE_LR:
ret = opal_erase_locking_range(dev, p);
break;
case IOC_OPAL_SECURE_ERASE_LR:
ret = opal_secure_erase_locking_range(dev, p);
break;
default:
pr_warn("No such Opal Ioctl %u\n", cmd);
}
kfree(p);
return ret;
}
