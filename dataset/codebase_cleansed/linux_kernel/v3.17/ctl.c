static u64 get_route(struct tb_cfg_header header)
{
return (u64) header.route_hi << 32 | header.route_lo;
}
static struct tb_cfg_header make_header(u64 route)
{
struct tb_cfg_header header = {
.route_hi = route >> 32,
.route_lo = route,
};
WARN_ON(get_route(header) != route);
return header;
}
static int check_header(struct ctl_pkg *pkg, u32 len, enum tb_cfg_pkg_type type,
u64 route)
{
struct tb_cfg_header *header = pkg->buffer;
if (WARN(len != pkg->frame.size,
"wrong framesize (expected %#x, got %#x)\n",
len, pkg->frame.size))
return -EIO;
if (WARN(type != pkg->frame.eof, "wrong eof (expected %#x, got %#x)\n",
type, pkg->frame.eof))
return -EIO;
if (WARN(pkg->frame.sof, "wrong sof (expected 0x0, got %#x)\n",
pkg->frame.sof))
return -EIO;
if (WARN(header->unknown != 1 << 9,
"header->unknown is %#x\n", header->unknown))
return -EIO;
if (WARN(route != get_route(*header),
"wrong route (expected %llx, got %llx)",
route, get_route(*header)))
return -EIO;
return 0;
}
static int check_config_address(struct tb_cfg_address addr,
enum tb_cfg_space space, u32 offset,
u32 length)
{
if (WARN(addr.zero, "addr.zero is %#x\n", addr.zero))
return -EIO;
if (WARN(space != addr.space, "wrong space (expected %x, got %x\n)",
space, addr.space))
return -EIO;
if (WARN(offset != addr.offset, "wrong offset (expected %x, got %x\n)",
offset, addr.offset))
return -EIO;
if (WARN(length != addr.length, "wrong space (expected %x, got %x\n)",
length, addr.length))
return -EIO;
if (WARN(addr.seq, "addr.seq is %#x\n", addr.seq))
return -EIO;
return 0;
}
static struct tb_cfg_result decode_error(struct ctl_pkg *response)
{
struct cfg_error_pkg *pkg = response->buffer;
struct tb_cfg_result res = { 0 };
res.response_route = get_route(pkg->header);
res.response_port = 0;
res.err = check_header(response, sizeof(*pkg), TB_CFG_PKG_ERROR,
get_route(pkg->header));
if (res.err)
return res;
WARN(pkg->zero1, "pkg->zero1 is %#x\n", pkg->zero1);
WARN(pkg->zero2, "pkg->zero1 is %#x\n", pkg->zero1);
WARN(pkg->zero3, "pkg->zero1 is %#x\n", pkg->zero1);
res.err = 1;
res.tb_error = pkg->error;
res.response_port = pkg->port;
return res;
}
static struct tb_cfg_result parse_header(struct ctl_pkg *pkg, u32 len,
enum tb_cfg_pkg_type type, u64 route)
{
struct tb_cfg_header *header = pkg->buffer;
struct tb_cfg_result res = { 0 };
if (pkg->frame.eof == TB_CFG_PKG_ERROR)
return decode_error(pkg);
res.response_port = 0;
res.response_route = get_route(*header);
res.err = check_header(pkg, len, type, route);
return res;
}
static void tb_cfg_print_error(struct tb_ctl *ctl,
const struct tb_cfg_result *res)
{
WARN_ON(res->err != 1);
switch (res->tb_error) {
case TB_CFG_ERROR_PORT_NOT_CONNECTED:
return;
case TB_CFG_ERROR_INVALID_CONFIG_SPACE:
tb_ctl_WARN(ctl,
"CFG_ERROR(%llx:%x): Invalid config space of offset\n",
res->response_route, res->response_port);
return;
case TB_CFG_ERROR_NO_SUCH_PORT:
tb_ctl_WARN(ctl, "CFG_ERROR(%llx:%x): Invalid port\n",
res->response_route, res->response_port);
return;
case TB_CFG_ERROR_LOOP:
tb_ctl_WARN(ctl, "CFG_ERROR(%llx:%x): Route contains a loop\n",
res->response_route, res->response_port);
return;
default:
tb_ctl_WARN(ctl, "CFG_ERROR(%llx:%x): Unknown error\n",
res->response_route, res->response_port);
return;
}
}
static void cpu_to_be32_array(__be32 *dst, u32 *src, size_t len)
{
int i;
for (i = 0; i < len; i++)
dst[i] = cpu_to_be32(src[i]);
}
static void be32_to_cpu_array(u32 *dst, __be32 *src, size_t len)
{
int i;
for (i = 0; i < len; i++)
dst[i] = be32_to_cpu(src[i]);
}
static __be32 tb_crc(void *data, size_t len)
{
return cpu_to_be32(~__crc32c_le(~0, data, len));
}
static void tb_ctl_pkg_free(struct ctl_pkg *pkg)
{
if (pkg) {
dma_pool_free(pkg->ctl->frame_pool,
pkg->buffer, pkg->frame.buffer_phy);
kfree(pkg);
}
}
static struct ctl_pkg *tb_ctl_pkg_alloc(struct tb_ctl *ctl)
{
struct ctl_pkg *pkg = kzalloc(sizeof(*pkg), GFP_KERNEL);
if (!pkg)
return NULL;
pkg->ctl = ctl;
pkg->buffer = dma_pool_alloc(ctl->frame_pool, GFP_KERNEL,
&pkg->frame.buffer_phy);
if (!pkg->buffer) {
kfree(pkg);
return NULL;
}
return pkg;
}
static void tb_ctl_tx_callback(struct tb_ring *ring, struct ring_frame *frame,
bool canceled)
{
struct ctl_pkg *pkg = container_of(frame, typeof(*pkg), frame);
tb_ctl_pkg_free(pkg);
}
static int tb_ctl_tx(struct tb_ctl *ctl, void *data, size_t len,
enum tb_cfg_pkg_type type)
{
int res;
struct ctl_pkg *pkg;
if (len % 4 != 0) {
tb_ctl_WARN(ctl, "TX: invalid size: %zu\n", len);
return -EINVAL;
}
if (len > TB_FRAME_SIZE - 4) {
tb_ctl_WARN(ctl, "TX: packet too large: %zu/%d\n",
len, TB_FRAME_SIZE - 4);
return -EINVAL;
}
pkg = tb_ctl_pkg_alloc(ctl);
if (!pkg)
return -ENOMEM;
pkg->frame.callback = tb_ctl_tx_callback;
pkg->frame.size = len + 4;
pkg->frame.sof = type;
pkg->frame.eof = type;
cpu_to_be32_array(pkg->buffer, data, len / 4);
*(__be32 *) (pkg->buffer + len) = tb_crc(pkg->buffer, len);
res = ring_tx(ctl->tx, &pkg->frame);
if (res)
tb_ctl_pkg_free(pkg);
return res;
}
static void tb_ctl_handle_plug_event(struct tb_ctl *ctl,
struct ctl_pkg *response)
{
struct cfg_event_pkg *pkg = response->buffer;
u64 route = get_route(pkg->header);
if (check_header(response, sizeof(*pkg), TB_CFG_PKG_EVENT, route)) {
tb_ctl_warn(ctl, "malformed TB_CFG_PKG_EVENT\n");
return;
}
if (tb_cfg_error(ctl, route, pkg->port, TB_CFG_ERROR_ACK_PLUG_EVENT))
tb_ctl_warn(ctl, "could not ack plug event on %llx:%x\n",
route, pkg->port);
WARN(pkg->zero, "pkg->zero is %#x\n", pkg->zero);
ctl->callback(ctl->callback_data, route, pkg->port, pkg->unplug);
}
static void tb_ctl_rx_submit(struct ctl_pkg *pkg)
{
ring_rx(pkg->ctl->rx, &pkg->frame);
}
static void tb_ctl_rx_callback(struct tb_ring *ring, struct ring_frame *frame,
bool canceled)
{
struct ctl_pkg *pkg = container_of(frame, typeof(*pkg), frame);
if (canceled)
return;
if (frame->size < 4 || frame->size % 4 != 0) {
tb_ctl_err(pkg->ctl, "RX: invalid size %#x, dropping packet\n",
frame->size);
goto rx;
}
frame->size -= 4;
if (*(__be32 *) (pkg->buffer + frame->size)
!= tb_crc(pkg->buffer, frame->size)) {
tb_ctl_err(pkg->ctl,
"RX: checksum mismatch, dropping packet\n");
goto rx;
}
be32_to_cpu_array(pkg->buffer, pkg->buffer, frame->size / 4);
if (frame->eof == TB_CFG_PKG_EVENT) {
tb_ctl_handle_plug_event(pkg->ctl, pkg);
goto rx;
}
if (!kfifo_put(&pkg->ctl->response_fifo, pkg)) {
tb_ctl_err(pkg->ctl, "RX: fifo is full\n");
goto rx;
}
complete(&pkg->ctl->response_ready);
return;
rx:
tb_ctl_rx_submit(pkg);
}
static struct tb_cfg_result tb_ctl_rx(struct tb_ctl *ctl, void *buffer,
size_t length, int timeout_msec,
u64 route, enum tb_cfg_pkg_type type)
{
struct tb_cfg_result res;
struct ctl_pkg *pkg;
if (!wait_for_completion_timeout(&ctl->response_ready,
msecs_to_jiffies(timeout_msec))) {
tb_ctl_WARN(ctl, "RX: timeout\n");
return (struct tb_cfg_result) { .err = -ETIMEDOUT };
}
if (!kfifo_get(&ctl->response_fifo, &pkg)) {
tb_ctl_WARN(ctl, "empty kfifo\n");
return (struct tb_cfg_result) { .err = -EIO };
}
res = parse_header(pkg, length, type, route);
if (!res.err)
memcpy(buffer, pkg->buffer, length);
tb_ctl_rx_submit(pkg);
return res;
}
struct tb_ctl *tb_ctl_alloc(struct tb_nhi *nhi, hotplug_cb cb, void *cb_data)
{
int i;
struct tb_ctl *ctl = kzalloc(sizeof(*ctl), GFP_KERNEL);
if (!ctl)
return NULL;
ctl->nhi = nhi;
ctl->callback = cb;
ctl->callback_data = cb_data;
init_completion(&ctl->response_ready);
INIT_KFIFO(ctl->response_fifo);
ctl->frame_pool = dma_pool_create("thunderbolt_ctl", &nhi->pdev->dev,
TB_FRAME_SIZE, 4, 0);
if (!ctl->frame_pool)
goto err;
ctl->tx = ring_alloc_tx(nhi, 0, 10);
if (!ctl->tx)
goto err;
ctl->rx = ring_alloc_rx(nhi, 0, 10);
if (!ctl->rx)
goto err;
for (i = 0; i < TB_CTL_RX_PKG_COUNT; i++) {
ctl->rx_packets[i] = tb_ctl_pkg_alloc(ctl);
if (!ctl->rx_packets[i])
goto err;
ctl->rx_packets[i]->frame.callback = tb_ctl_rx_callback;
}
tb_ctl_info(ctl, "control channel created\n");
return ctl;
err:
tb_ctl_free(ctl);
return NULL;
}
void tb_ctl_free(struct tb_ctl *ctl)
{
int i;
if (ctl->rx)
ring_free(ctl->rx);
if (ctl->tx)
ring_free(ctl->tx);
for (i = 0; i < TB_CTL_RX_PKG_COUNT; i++)
tb_ctl_pkg_free(ctl->rx_packets[i]);
if (ctl->frame_pool)
dma_pool_destroy(ctl->frame_pool);
kfree(ctl);
}
void tb_ctl_start(struct tb_ctl *ctl)
{
int i;
tb_ctl_info(ctl, "control channel starting...\n");
ring_start(ctl->tx);
ring_start(ctl->rx);
for (i = 0; i < TB_CTL_RX_PKG_COUNT; i++)
tb_ctl_rx_submit(ctl->rx_packets[i]);
}
void tb_ctl_stop(struct tb_ctl *ctl)
{
ring_stop(ctl->rx);
ring_stop(ctl->tx);
if (!kfifo_is_empty(&ctl->response_fifo))
tb_ctl_WARN(ctl, "dangling response in response_fifo\n");
kfifo_reset(&ctl->response_fifo);
tb_ctl_info(ctl, "control channel stopped\n");
}
int tb_cfg_error(struct tb_ctl *ctl, u64 route, u32 port,
enum tb_cfg_error error)
{
struct cfg_error_pkg pkg = {
.header = make_header(route),
.port = port,
.error = error,
};
tb_ctl_info(ctl, "resetting error on %llx:%x.\n", route, port);
return tb_ctl_tx(ctl, &pkg, sizeof(pkg), TB_CFG_PKG_ERROR);
}
struct tb_cfg_result tb_cfg_reset(struct tb_ctl *ctl, u64 route,
int timeout_msec)
{
int err;
struct cfg_reset_pkg request = { .header = make_header(route) };
struct tb_cfg_header reply;
err = tb_ctl_tx(ctl, &request, sizeof(request), TB_CFG_PKG_RESET);
if (err)
return (struct tb_cfg_result) { .err = err };
return tb_ctl_rx(ctl, &reply, sizeof(reply), timeout_msec, route,
TB_CFG_PKG_RESET);
}
struct tb_cfg_result tb_cfg_read_raw(struct tb_ctl *ctl, void *buffer,
u64 route, u32 port, enum tb_cfg_space space,
u32 offset, u32 length, int timeout_msec)
{
struct tb_cfg_result res = { 0 };
struct cfg_read_pkg request = {
.header = make_header(route),
.addr = {
.port = port,
.space = space,
.offset = offset,
.length = length,
},
};
struct cfg_write_pkg reply;
res.err = tb_ctl_tx(ctl, &request, sizeof(request), TB_CFG_PKG_READ);
if (res.err)
return res;
res = tb_ctl_rx(ctl, &reply, 12 + 4 * length, timeout_msec, route,
TB_CFG_PKG_READ);
if (res.err)
return res;
res.response_port = reply.addr.port;
res.err = check_config_address(reply.addr, space, offset, length);
if (!res.err)
memcpy(buffer, &reply.data, 4 * length);
return res;
}
struct tb_cfg_result tb_cfg_write_raw(struct tb_ctl *ctl, void *buffer,
u64 route, u32 port, enum tb_cfg_space space,
u32 offset, u32 length, int timeout_msec)
{
struct tb_cfg_result res = { 0 };
struct cfg_write_pkg request = {
.header = make_header(route),
.addr = {
.port = port,
.space = space,
.offset = offset,
.length = length,
},
};
struct cfg_read_pkg reply;
memcpy(&request.data, buffer, length * 4);
res.err = tb_ctl_tx(ctl, &request, 12 + 4 * length, TB_CFG_PKG_WRITE);
if (res.err)
return res;
res = tb_ctl_rx(ctl, &reply, sizeof(reply), timeout_msec, route,
TB_CFG_PKG_WRITE);
if (res.err)
return res;
res.response_port = reply.addr.port;
res.err = check_config_address(reply.addr, space, offset, length);
return res;
}
int tb_cfg_read(struct tb_ctl *ctl, void *buffer, u64 route, u32 port,
enum tb_cfg_space space, u32 offset, u32 length)
{
struct tb_cfg_result res = tb_cfg_read_raw(ctl, buffer, route, port,
space, offset, length, TB_CFG_DEFAULT_TIMEOUT);
if (res.err == 1) {
tb_cfg_print_error(ctl, &res);
return -EIO;
}
WARN(res.err, "tb_cfg_read: %d\n", res.err);
return res.err;
}
int tb_cfg_write(struct tb_ctl *ctl, void *buffer, u64 route, u32 port,
enum tb_cfg_space space, u32 offset, u32 length)
{
struct tb_cfg_result res = tb_cfg_write_raw(ctl, buffer, route, port,
space, offset, length, TB_CFG_DEFAULT_TIMEOUT);
if (res.err == 1) {
tb_cfg_print_error(ctl, &res);
return -EIO;
}
WARN(res.err, "tb_cfg_write: %d\n", res.err);
return res.err;
}
int tb_cfg_get_upstream_port(struct tb_ctl *ctl, u64 route)
{
u32 dummy;
struct tb_cfg_result res = tb_cfg_read_raw(ctl, &dummy, route, 0,
TB_CFG_SWITCH, 0, 1,
TB_CFG_DEFAULT_TIMEOUT);
if (res.err == 1)
return -EIO;
if (res.err)
return res.err;
return res.response_port;
}
