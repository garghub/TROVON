struct tb_cfg_request *tb_cfg_request_alloc(void)
{
struct tb_cfg_request *req;
req = kzalloc(sizeof(*req), GFP_KERNEL);
if (!req)
return NULL;
kref_init(&req->kref);
return req;
}
void tb_cfg_request_get(struct tb_cfg_request *req)
{
mutex_lock(&tb_cfg_request_lock);
kref_get(&req->kref);
mutex_unlock(&tb_cfg_request_lock);
}
static void tb_cfg_request_destroy(struct kref *kref)
{
struct tb_cfg_request *req = container_of(kref, typeof(*req), kref);
kfree(req);
}
void tb_cfg_request_put(struct tb_cfg_request *req)
{
mutex_lock(&tb_cfg_request_lock);
kref_put(&req->kref, tb_cfg_request_destroy);
mutex_unlock(&tb_cfg_request_lock);
}
static int tb_cfg_request_enqueue(struct tb_ctl *ctl,
struct tb_cfg_request *req)
{
WARN_ON(test_bit(TB_CFG_REQUEST_ACTIVE, &req->flags));
WARN_ON(req->ctl);
mutex_lock(&ctl->request_queue_lock);
if (!ctl->running) {
mutex_unlock(&ctl->request_queue_lock);
return -ENOTCONN;
}
req->ctl = ctl;
list_add_tail(&req->list, &ctl->request_queue);
set_bit(TB_CFG_REQUEST_ACTIVE, &req->flags);
mutex_unlock(&ctl->request_queue_lock);
return 0;
}
static void tb_cfg_request_dequeue(struct tb_cfg_request *req)
{
struct tb_ctl *ctl = req->ctl;
mutex_lock(&ctl->request_queue_lock);
list_del(&req->list);
clear_bit(TB_CFG_REQUEST_ACTIVE, &req->flags);
if (test_bit(TB_CFG_REQUEST_CANCELED, &req->flags))
wake_up(&tb_cfg_request_cancel_queue);
mutex_unlock(&ctl->request_queue_lock);
}
static bool tb_cfg_request_is_active(struct tb_cfg_request *req)
{
return test_bit(TB_CFG_REQUEST_ACTIVE, &req->flags);
}
static struct tb_cfg_request *
tb_cfg_request_find(struct tb_ctl *ctl, struct ctl_pkg *pkg)
{
struct tb_cfg_request *req;
bool found = false;
mutex_lock(&pkg->ctl->request_queue_lock);
list_for_each_entry(req, &pkg->ctl->request_queue, list) {
tb_cfg_request_get(req);
if (req->match(req, pkg)) {
found = true;
break;
}
tb_cfg_request_put(req);
}
mutex_unlock(&pkg->ctl->request_queue_lock);
return found ? req : NULL;
}
static int check_header(const struct ctl_pkg *pkg, u32 len,
enum tb_cfg_pkg_type type, u64 route)
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
if (WARN(route != tb_cfg_get_route(header),
"wrong route (expected %llx, got %llx)",
route, tb_cfg_get_route(header)))
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
return 0;
}
static struct tb_cfg_result decode_error(const struct ctl_pkg *response)
{
struct cfg_error_pkg *pkg = response->buffer;
struct tb_cfg_result res = { 0 };
res.response_route = tb_cfg_get_route(&pkg->header);
res.response_port = 0;
res.err = check_header(response, sizeof(*pkg), TB_CFG_PKG_ERROR,
tb_cfg_get_route(&pkg->header));
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
static struct tb_cfg_result parse_header(const struct ctl_pkg *pkg, u32 len,
enum tb_cfg_pkg_type type, u64 route)
{
struct tb_cfg_header *header = pkg->buffer;
struct tb_cfg_result res = { 0 };
if (pkg->frame.eof == TB_CFG_PKG_ERROR)
return decode_error(pkg);
res.response_port = 0;
res.response_route = tb_cfg_get_route(header);
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
"CFG_ERROR(%llx:%x): Invalid config space or offset\n",
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
static void cpu_to_be32_array(__be32 *dst, const u32 *src, size_t len)
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
static __be32 tb_crc(const void *data, size_t len)
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
static int tb_ctl_tx(struct tb_ctl *ctl, const void *data, size_t len,
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
static void tb_ctl_handle_event(struct tb_ctl *ctl, enum tb_cfg_pkg_type type,
struct ctl_pkg *pkg, size_t size)
{
ctl->callback(ctl->callback_data, type, pkg->buffer, size);
}
static void tb_ctl_rx_submit(struct ctl_pkg *pkg)
{
ring_rx(pkg->ctl->rx, &pkg->frame);
}
static int tb_async_error(const struct ctl_pkg *pkg)
{
const struct cfg_error_pkg *error = (const struct cfg_error_pkg *)pkg;
if (pkg->frame.eof != TB_CFG_PKG_ERROR)
return false;
switch (error->error) {
case TB_CFG_ERROR_LINK_ERROR:
case TB_CFG_ERROR_HEC_ERROR_DETECTED:
case TB_CFG_ERROR_FLOW_CONTROL_ERROR:
return true;
default:
return false;
}
}
static void tb_ctl_rx_callback(struct tb_ring *ring, struct ring_frame *frame,
bool canceled)
{
struct ctl_pkg *pkg = container_of(frame, typeof(*pkg), frame);
struct tb_cfg_request *req;
__be32 crc32;
if (canceled)
return;
if (frame->size < 4 || frame->size % 4 != 0) {
tb_ctl_err(pkg->ctl, "RX: invalid size %#x, dropping packet\n",
frame->size);
goto rx;
}
frame->size -= 4;
crc32 = tb_crc(pkg->buffer, frame->size);
be32_to_cpu_array(pkg->buffer, pkg->buffer, frame->size / 4);
switch (frame->eof) {
case TB_CFG_PKG_READ:
case TB_CFG_PKG_WRITE:
case TB_CFG_PKG_ERROR:
case TB_CFG_PKG_OVERRIDE:
case TB_CFG_PKG_RESET:
if (*(__be32 *)(pkg->buffer + frame->size) != crc32) {
tb_ctl_err(pkg->ctl,
"RX: checksum mismatch, dropping packet\n");
goto rx;
}
if (tb_async_error(pkg)) {
tb_ctl_handle_event(pkg->ctl, frame->eof,
pkg, frame->size);
goto rx;
}
break;
case TB_CFG_PKG_EVENT:
if (*(__be32 *)(pkg->buffer + frame->size) != crc32) {
tb_ctl_err(pkg->ctl,
"RX: checksum mismatch, dropping packet\n");
goto rx;
}
case TB_CFG_PKG_ICM_EVENT:
tb_ctl_handle_event(pkg->ctl, frame->eof, pkg, frame->size);
goto rx;
default:
break;
}
req = tb_cfg_request_find(pkg->ctl, pkg);
if (req) {
if (req->copy(req, pkg))
schedule_work(&req->work);
tb_cfg_request_put(req);
}
rx:
tb_ctl_rx_submit(pkg);
}
static void tb_cfg_request_work(struct work_struct *work)
{
struct tb_cfg_request *req = container_of(work, typeof(*req), work);
if (!test_bit(TB_CFG_REQUEST_CANCELED, &req->flags))
req->callback(req->callback_data);
tb_cfg_request_dequeue(req);
tb_cfg_request_put(req);
}
int tb_cfg_request(struct tb_ctl *ctl, struct tb_cfg_request *req,
void (*callback)(void *), void *callback_data)
{
int ret;
req->flags = 0;
req->callback = callback;
req->callback_data = callback_data;
INIT_WORK(&req->work, tb_cfg_request_work);
INIT_LIST_HEAD(&req->list);
tb_cfg_request_get(req);
ret = tb_cfg_request_enqueue(ctl, req);
if (ret)
goto err_put;
ret = tb_ctl_tx(ctl, req->request, req->request_size,
req->request_type);
if (ret)
goto err_dequeue;
if (!req->response)
schedule_work(&req->work);
return 0;
err_dequeue:
tb_cfg_request_dequeue(req);
err_put:
tb_cfg_request_put(req);
return ret;
}
void tb_cfg_request_cancel(struct tb_cfg_request *req, int err)
{
set_bit(TB_CFG_REQUEST_CANCELED, &req->flags);
schedule_work(&req->work);
wait_event(tb_cfg_request_cancel_queue, !tb_cfg_request_is_active(req));
req->result.err = err;
}
static void tb_cfg_request_complete(void *data)
{
complete(data);
}
struct tb_cfg_result tb_cfg_request_sync(struct tb_ctl *ctl,
struct tb_cfg_request *req,
int timeout_msec)
{
unsigned long timeout = msecs_to_jiffies(timeout_msec);
struct tb_cfg_result res = { 0 };
DECLARE_COMPLETION_ONSTACK(done);
int ret;
ret = tb_cfg_request(ctl, req, tb_cfg_request_complete, &done);
if (ret) {
res.err = ret;
return res;
}
if (!wait_for_completion_timeout(&done, timeout))
tb_cfg_request_cancel(req, -ETIMEDOUT);
flush_work(&req->work);
return req->result;
}
struct tb_ctl *tb_ctl_alloc(struct tb_nhi *nhi, event_cb cb, void *cb_data)
{
int i;
struct tb_ctl *ctl = kzalloc(sizeof(*ctl), GFP_KERNEL);
if (!ctl)
return NULL;
ctl->nhi = nhi;
ctl->callback = cb;
ctl->callback_data = cb_data;
mutex_init(&ctl->request_queue_lock);
INIT_LIST_HEAD(&ctl->request_queue);
ctl->frame_pool = dma_pool_create("thunderbolt_ctl", &nhi->pdev->dev,
TB_FRAME_SIZE, 4, 0);
if (!ctl->frame_pool)
goto err;
ctl->tx = ring_alloc_tx(nhi, 0, 10, RING_FLAG_NO_SUSPEND);
if (!ctl->tx)
goto err;
ctl->rx = ring_alloc_rx(nhi, 0, 10, RING_FLAG_NO_SUSPEND);
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
if (!ctl)
return;
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
ctl->running = true;
}
void tb_ctl_stop(struct tb_ctl *ctl)
{
mutex_lock(&ctl->request_queue_lock);
ctl->running = false;
mutex_unlock(&ctl->request_queue_lock);
ring_stop(ctl->rx);
ring_stop(ctl->tx);
if (!list_empty(&ctl->request_queue))
tb_ctl_WARN(ctl, "dangling request in request_queue\n");
INIT_LIST_HEAD(&ctl->request_queue);
tb_ctl_info(ctl, "control channel stopped\n");
}
int tb_cfg_error(struct tb_ctl *ctl, u64 route, u32 port,
enum tb_cfg_error error)
{
struct cfg_error_pkg pkg = {
.header = tb_cfg_make_header(route),
.port = port,
.error = error,
};
tb_ctl_info(ctl, "resetting error on %llx:%x.\n", route, port);
return tb_ctl_tx(ctl, &pkg, sizeof(pkg), TB_CFG_PKG_ERROR);
}
static bool tb_cfg_match(const struct tb_cfg_request *req,
const struct ctl_pkg *pkg)
{
u64 route = tb_cfg_get_route(pkg->buffer) & ~BIT_ULL(63);
if (pkg->frame.eof == TB_CFG_PKG_ERROR)
return true;
if (pkg->frame.eof != req->response_type)
return false;
if (route != tb_cfg_get_route(req->request))
return false;
if (pkg->frame.size != req->response_size)
return false;
if (pkg->frame.eof == TB_CFG_PKG_READ ||
pkg->frame.eof == TB_CFG_PKG_WRITE) {
const struct cfg_read_pkg *req_hdr = req->request;
const struct cfg_read_pkg *res_hdr = pkg->buffer;
if (req_hdr->addr.seq != res_hdr->addr.seq)
return false;
}
return true;
}
static bool tb_cfg_copy(struct tb_cfg_request *req, const struct ctl_pkg *pkg)
{
struct tb_cfg_result res;
res = parse_header(pkg, req->response_size, req->response_type,
tb_cfg_get_route(req->request));
if (!res.err)
memcpy(req->response, pkg->buffer, req->response_size);
req->result = res;
return true;
}
struct tb_cfg_result tb_cfg_reset(struct tb_ctl *ctl, u64 route,
int timeout_msec)
{
struct cfg_reset_pkg request = { .header = tb_cfg_make_header(route) };
struct tb_cfg_result res = { 0 };
struct tb_cfg_header reply;
struct tb_cfg_request *req;
req = tb_cfg_request_alloc();
if (!req) {
res.err = -ENOMEM;
return res;
}
req->match = tb_cfg_match;
req->copy = tb_cfg_copy;
req->request = &request;
req->request_size = sizeof(request);
req->request_type = TB_CFG_PKG_RESET;
req->response = &reply;
req->response_size = sizeof(reply);
req->response_type = sizeof(TB_CFG_PKG_RESET);
res = tb_cfg_request_sync(ctl, req, timeout_msec);
tb_cfg_request_put(req);
return res;
}
struct tb_cfg_result tb_cfg_read_raw(struct tb_ctl *ctl, void *buffer,
u64 route, u32 port, enum tb_cfg_space space,
u32 offset, u32 length, int timeout_msec)
{
struct tb_cfg_result res = { 0 };
struct cfg_read_pkg request = {
.header = tb_cfg_make_header(route),
.addr = {
.port = port,
.space = space,
.offset = offset,
.length = length,
},
};
struct cfg_write_pkg reply;
int retries = 0;
while (retries < TB_CTL_RETRIES) {
struct tb_cfg_request *req;
req = tb_cfg_request_alloc();
if (!req) {
res.err = -ENOMEM;
return res;
}
request.addr.seq = retries++;
req->match = tb_cfg_match;
req->copy = tb_cfg_copy;
req->request = &request;
req->request_size = sizeof(request);
req->request_type = TB_CFG_PKG_READ;
req->response = &reply;
req->response_size = 12 + 4 * length;
req->response_type = TB_CFG_PKG_READ;
res = tb_cfg_request_sync(ctl, req, timeout_msec);
tb_cfg_request_put(req);
if (res.err != -ETIMEDOUT)
break;
usleep_range(10, 100);
}
if (res.err)
return res;
res.response_port = reply.addr.port;
res.err = check_config_address(reply.addr, space, offset, length);
if (!res.err)
memcpy(buffer, &reply.data, 4 * length);
return res;
}
struct tb_cfg_result tb_cfg_write_raw(struct tb_ctl *ctl, const void *buffer,
u64 route, u32 port, enum tb_cfg_space space,
u32 offset, u32 length, int timeout_msec)
{
struct tb_cfg_result res = { 0 };
struct cfg_write_pkg request = {
.header = tb_cfg_make_header(route),
.addr = {
.port = port,
.space = space,
.offset = offset,
.length = length,
},
};
struct cfg_read_pkg reply;
int retries = 0;
memcpy(&request.data, buffer, length * 4);
while (retries < TB_CTL_RETRIES) {
struct tb_cfg_request *req;
req = tb_cfg_request_alloc();
if (!req) {
res.err = -ENOMEM;
return res;
}
request.addr.seq = retries++;
req->match = tb_cfg_match;
req->copy = tb_cfg_copy;
req->request = &request;
req->request_size = 12 + 4 * length;
req->request_type = TB_CFG_PKG_WRITE;
req->response = &reply;
req->response_size = sizeof(reply);
req->response_type = TB_CFG_PKG_WRITE;
res = tb_cfg_request_sync(ctl, req, timeout_msec);
tb_cfg_request_put(req);
if (res.err != -ETIMEDOUT)
break;
usleep_range(10, 100);
}
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
switch (res.err) {
case 0:
break;
case 1:
tb_cfg_print_error(ctl, &res);
return -EIO;
case -ETIMEDOUT:
tb_ctl_warn(ctl, "timeout reading config space %u from %#x\n",
space, offset);
break;
default:
WARN(1, "tb_cfg_read: %d\n", res.err);
break;
}
return res.err;
}
int tb_cfg_write(struct tb_ctl *ctl, const void *buffer, u64 route, u32 port,
enum tb_cfg_space space, u32 offset, u32 length)
{
struct tb_cfg_result res = tb_cfg_write_raw(ctl, buffer, route, port,
space, offset, length, TB_CFG_DEFAULT_TIMEOUT);
switch (res.err) {
case 0:
break;
case 1:
tb_cfg_print_error(ctl, &res);
return -EIO;
case -ETIMEDOUT:
tb_ctl_warn(ctl, "timeout writing config space %u to %#x\n",
space, offset);
break;
default:
WARN(1, "tb_cfg_write: %d\n", res.err);
break;
}
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
