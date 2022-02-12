struct nfp_cpp *nfp_nsp_cpp(struct nfp_nsp *state)
{
return state->cpp;
}
bool nfp_nsp_config_modified(struct nfp_nsp *state)
{
return state->modified;
}
void nfp_nsp_config_set_modified(struct nfp_nsp *state, bool modified)
{
state->modified = modified;
}
void *nfp_nsp_config_entries(struct nfp_nsp *state)
{
return state->entries;
}
unsigned int nfp_nsp_config_idx(struct nfp_nsp *state)
{
return state->idx;
}
void
nfp_nsp_config_set_state(struct nfp_nsp *state, void *entries, unsigned int idx)
{
state->entries = entries;
state->idx = idx;
}
void nfp_nsp_config_clear_state(struct nfp_nsp *state)
{
state->entries = NULL;
state->idx = 0;
}
static void nfp_nsp_print_extended_error(struct nfp_nsp *state, u32 ret_val)
{
int i;
if (!ret_val)
return;
for (i = 0; i < ARRAY_SIZE(nsp_errors); i++)
if (ret_val == nsp_errors[i].code)
nfp_err(state->cpp, "err msg: %s\n", nsp_errors[i].msg);
}
static int nfp_nsp_check(struct nfp_nsp *state)
{
struct nfp_cpp *cpp = state->cpp;
u64 nsp_status, reg;
u32 nsp_cpp;
int err;
nsp_cpp = nfp_resource_cpp_id(state->res);
nsp_status = nfp_resource_address(state->res) + NSP_STATUS;
err = nfp_cpp_readq(cpp, nsp_cpp, nsp_status, &reg);
if (err < 0)
return err;
if (FIELD_GET(NSP_STATUS_MAGIC, reg) != NSP_MAGIC) {
nfp_err(cpp, "Cannot detect NFP Service Processor\n");
return -ENODEV;
}
state->ver.major = FIELD_GET(NSP_STATUS_MAJOR, reg);
state->ver.minor = FIELD_GET(NSP_STATUS_MINOR, reg);
if (state->ver.major != NSP_MAJOR || state->ver.minor < NSP_MINOR) {
nfp_err(cpp, "Unsupported ABI %hu.%hu\n",
state->ver.major, state->ver.minor);
return -EINVAL;
}
if (reg & NSP_STATUS_BUSY) {
nfp_err(cpp, "Service processor busy!\n");
return -EBUSY;
}
return 0;
}
struct nfp_nsp *nfp_nsp_open(struct nfp_cpp *cpp)
{
struct nfp_resource *res;
struct nfp_nsp *state;
int err;
res = nfp_resource_acquire(cpp, NFP_RESOURCE_NSP);
if (IS_ERR(res))
return (void *)res;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state) {
nfp_resource_release(res);
return ERR_PTR(-ENOMEM);
}
state->cpp = cpp;
state->res = res;
err = nfp_nsp_check(state);
if (err) {
nfp_nsp_close(state);
return ERR_PTR(err);
}
return state;
}
void nfp_nsp_close(struct nfp_nsp *state)
{
nfp_resource_release(state->res);
kfree(state);
}
u16 nfp_nsp_get_abi_ver_major(struct nfp_nsp *state)
{
return state->ver.major;
}
u16 nfp_nsp_get_abi_ver_minor(struct nfp_nsp *state)
{
return state->ver.minor;
}
static int
nfp_nsp_wait_reg(struct nfp_cpp *cpp, u64 *reg,
u32 nsp_cpp, u64 addr, u64 mask, u64 val)
{
const unsigned long wait_until = jiffies + 30 * HZ;
int err;
for (;;) {
const unsigned long start_time = jiffies;
err = nfp_cpp_readq(cpp, nsp_cpp, addr, reg);
if (err < 0)
return err;
if ((*reg & mask) == val)
return 0;
if (msleep_interruptible(25))
return -ERESTARTSYS;
if (time_after(start_time, wait_until))
return -ETIMEDOUT;
}
}
static int nfp_nsp_command(struct nfp_nsp *state, u16 code, u32 option,
u32 buff_cpp, u64 buff_addr)
{
u64 reg, ret_val, nsp_base, nsp_buffer, nsp_status, nsp_command;
struct nfp_cpp *cpp = state->cpp;
u32 nsp_cpp;
int err;
nsp_cpp = nfp_resource_cpp_id(state->res);
nsp_base = nfp_resource_address(state->res);
nsp_status = nsp_base + NSP_STATUS;
nsp_command = nsp_base + NSP_COMMAND;
nsp_buffer = nsp_base + NSP_BUFFER;
err = nfp_nsp_check(state);
if (err)
return err;
if (!FIELD_FIT(NSP_BUFFER_CPP, buff_cpp >> 8) ||
!FIELD_FIT(NSP_BUFFER_ADDRESS, buff_addr)) {
nfp_err(cpp, "Host buffer out of reach %08x %016llx\n",
buff_cpp, buff_addr);
return -EINVAL;
}
err = nfp_cpp_writeq(cpp, nsp_cpp, nsp_buffer,
FIELD_PREP(NSP_BUFFER_CPP, buff_cpp >> 8) |
FIELD_PREP(NSP_BUFFER_ADDRESS, buff_addr));
if (err < 0)
return err;
err = nfp_cpp_writeq(cpp, nsp_cpp, nsp_command,
FIELD_PREP(NSP_COMMAND_OPTION, option) |
FIELD_PREP(NSP_COMMAND_CODE, code) |
FIELD_PREP(NSP_COMMAND_START, 1));
if (err < 0)
return err;
err = nfp_nsp_wait_reg(cpp, &reg,
nsp_cpp, nsp_command, NSP_COMMAND_START, 0);
if (err) {
nfp_err(cpp, "Error %d waiting for code 0x%04x to start\n",
err, code);
return err;
}
err = nfp_nsp_wait_reg(cpp, &reg,
nsp_cpp, nsp_status, NSP_STATUS_BUSY, 0);
if (err) {
nfp_err(cpp, "Error %d waiting for code 0x%04x to complete\n",
err, code);
return err;
}
err = nfp_cpp_readq(cpp, nsp_cpp, nsp_command, &ret_val);
if (err < 0)
return err;
ret_val = FIELD_GET(NSP_COMMAND_OPTION, ret_val);
err = FIELD_GET(NSP_STATUS_RESULT, reg);
if (err) {
nfp_warn(cpp, "Result (error) code set: %d (%d) command: %d\n",
-err, (int)ret_val, code);
nfp_nsp_print_extended_error(state, ret_val);
return -err;
}
return ret_val;
}
static int nfp_nsp_command_buf(struct nfp_nsp *nsp, u16 code, u32 option,
const void *in_buf, unsigned int in_size,
void *out_buf, unsigned int out_size)
{
struct nfp_cpp *cpp = nsp->cpp;
unsigned int max_size;
u64 reg, cpp_buf;
int ret, err;
u32 cpp_id;
if (nsp->ver.minor < 13) {
nfp_err(cpp, "NSP: Code 0x%04x with buffer not supported (ABI %hu.%hu)\n",
code, nsp->ver.major, nsp->ver.minor);
return -EOPNOTSUPP;
}
err = nfp_cpp_readq(cpp, nfp_resource_cpp_id(nsp->res),
nfp_resource_address(nsp->res) +
NSP_DFLT_BUFFER_CONFIG,
&reg);
if (err < 0)
return err;
max_size = max(in_size, out_size);
if (FIELD_GET(NSP_DFLT_BUFFER_SIZE_MB, reg) * SZ_1M < max_size) {
nfp_err(cpp, "NSP: default buffer too small for command 0x%04x (%llu < %u)\n",
code, FIELD_GET(NSP_DFLT_BUFFER_SIZE_MB, reg) * SZ_1M,
max_size);
return -EINVAL;
}
err = nfp_cpp_readq(cpp, nfp_resource_cpp_id(nsp->res),
nfp_resource_address(nsp->res) +
NSP_DFLT_BUFFER,
&reg);
if (err < 0)
return err;
cpp_id = FIELD_GET(NSP_BUFFER_CPP, reg) << 8;
cpp_buf = FIELD_GET(NSP_BUFFER_ADDRESS, reg);
if (in_buf && in_size) {
err = nfp_cpp_write(cpp, cpp_id, cpp_buf, in_buf, in_size);
if (err < 0)
return err;
}
if (out_buf && out_size && out_size > in_size) {
memset(out_buf, 0, out_size - in_size);
err = nfp_cpp_write(cpp, cpp_id, cpp_buf + in_size,
out_buf, out_size - in_size);
if (err < 0)
return err;
}
ret = nfp_nsp_command(nsp, code, option, cpp_id, cpp_buf);
if (ret < 0)
return ret;
if (out_buf && out_size) {
err = nfp_cpp_read(cpp, cpp_id, cpp_buf, out_buf, out_size);
if (err < 0)
return err;
}
return ret;
}
int nfp_nsp_wait(struct nfp_nsp *state)
{
const unsigned long wait_until = jiffies + 30 * HZ;
int err;
nfp_dbg(state->cpp, "Waiting for NSP to respond (30 sec max).\n");
for (;;) {
const unsigned long start_time = jiffies;
err = nfp_nsp_command(state, SPCODE_NOOP, 0, 0, 0);
if (err != -EAGAIN)
break;
if (msleep_interruptible(25)) {
err = -ERESTARTSYS;
break;
}
if (time_after(start_time, wait_until)) {
err = -ETIMEDOUT;
break;
}
}
if (err)
nfp_err(state->cpp, "NSP failed to respond %d\n", err);
return err;
}
int nfp_nsp_device_soft_reset(struct nfp_nsp *state)
{
return nfp_nsp_command(state, SPCODE_SOFT_RESET, 0, 0, 0);
}
int nfp_nsp_load_fw(struct nfp_nsp *state, const struct firmware *fw)
{
return nfp_nsp_command_buf(state, SPCODE_FW_LOAD, fw->size, fw->data,
fw->size, NULL, 0);
}
int nfp_nsp_read_eth_table(struct nfp_nsp *state, void *buf, unsigned int size)
{
return nfp_nsp_command_buf(state, SPCODE_ETH_RESCAN, size, NULL, 0,
buf, size);
}
int nfp_nsp_write_eth_table(struct nfp_nsp *state,
const void *buf, unsigned int size)
{
return nfp_nsp_command_buf(state, SPCODE_ETH_CONTROL, size, buf, size,
NULL, 0);
}
int nfp_nsp_read_identify(struct nfp_nsp *state, void *buf, unsigned int size)
{
return nfp_nsp_command_buf(state, SPCODE_NSP_IDENTIFY, size, NULL, 0,
buf, size);
}
int nfp_nsp_read_sensors(struct nfp_nsp *state, unsigned int sensor_mask,
void *buf, unsigned int size)
{
return nfp_nsp_command_buf(state, SPCODE_NSP_SENSORS, sensor_mask,
NULL, 0, buf, size);
}
