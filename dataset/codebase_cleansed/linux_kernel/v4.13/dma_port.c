static bool dma_port_match(const struct tb_cfg_request *req,
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
return true;
}
static bool dma_port_copy(struct tb_cfg_request *req, const struct ctl_pkg *pkg)
{
memcpy(req->response, pkg->buffer, req->response_size);
return true;
}
static int dma_port_read(struct tb_ctl *ctl, void *buffer, u64 route,
u32 port, u32 offset, u32 length, int timeout_msec)
{
struct cfg_read_pkg request = {
.header = tb_cfg_make_header(route),
.addr = {
.seq = 1,
.port = port,
.space = TB_CFG_PORT,
.offset = offset,
.length = length,
},
};
struct tb_cfg_request *req;
struct cfg_write_pkg reply;
struct tb_cfg_result res;
req = tb_cfg_request_alloc();
if (!req)
return -ENOMEM;
req->match = dma_port_match;
req->copy = dma_port_copy;
req->request = &request;
req->request_size = sizeof(request);
req->request_type = TB_CFG_PKG_READ;
req->response = &reply;
req->response_size = 12 + 4 * length;
req->response_type = TB_CFG_PKG_READ;
res = tb_cfg_request_sync(ctl, req, timeout_msec);
tb_cfg_request_put(req);
if (res.err)
return res.err;
memcpy(buffer, &reply.data, 4 * length);
return 0;
}
static int dma_port_write(struct tb_ctl *ctl, const void *buffer, u64 route,
u32 port, u32 offset, u32 length, int timeout_msec)
{
struct cfg_write_pkg request = {
.header = tb_cfg_make_header(route),
.addr = {
.seq = 1,
.port = port,
.space = TB_CFG_PORT,
.offset = offset,
.length = length,
},
};
struct tb_cfg_request *req;
struct cfg_read_pkg reply;
struct tb_cfg_result res;
memcpy(&request.data, buffer, length * 4);
req = tb_cfg_request_alloc();
if (!req)
return -ENOMEM;
req->match = dma_port_match;
req->copy = dma_port_copy;
req->request = &request;
req->request_size = 12 + 4 * length;
req->request_type = TB_CFG_PKG_WRITE;
req->response = &reply;
req->response_size = sizeof(reply);
req->response_type = TB_CFG_PKG_WRITE;
res = tb_cfg_request_sync(ctl, req, timeout_msec);
tb_cfg_request_put(req);
return res.err;
}
static int dma_find_port(struct tb_switch *sw)
{
int port, ret;
u32 type;
port = 5;
ret = dma_port_read(sw->tb->ctl, &type, tb_route(sw), port, 2, 1,
DMA_PORT_TIMEOUT);
if (!ret && (type & 0xffffff) == TB_TYPE_NHI)
return port;
port = 3;
ret = dma_port_read(sw->tb->ctl, &type, tb_route(sw), port, 2, 1,
DMA_PORT_TIMEOUT);
if (!ret && (type & 0xffffff) == TB_TYPE_NHI)
return port;
return -ENODEV;
}
struct tb_dma_port *dma_port_alloc(struct tb_switch *sw)
{
struct tb_dma_port *dma;
int port;
port = dma_find_port(sw);
if (port < 0)
return NULL;
dma = kzalloc(sizeof(*dma), GFP_KERNEL);
if (!dma)
return NULL;
dma->buf = kmalloc_array(MAIL_DATA_DWORDS, sizeof(u32), GFP_KERNEL);
if (!dma->buf) {
kfree(dma);
return NULL;
}
dma->sw = sw;
dma->port = port;
dma->base = DMA_PORT_CAP;
return dma;
}
void dma_port_free(struct tb_dma_port *dma)
{
if (dma) {
kfree(dma->buf);
kfree(dma);
}
}
static int dma_port_wait_for_completion(struct tb_dma_port *dma,
unsigned int timeout)
{
unsigned long end = jiffies + msecs_to_jiffies(timeout);
struct tb_switch *sw = dma->sw;
do {
int ret;
u32 in;
ret = dma_port_read(sw->tb->ctl, &in, tb_route(sw), dma->port,
dma->base + MAIL_IN, 1, 50);
if (ret) {
if (ret != -ETIMEDOUT)
return ret;
} else if (!(in & MAIL_IN_OP_REQUEST)) {
return 0;
}
usleep_range(50, 100);
} while (time_before(jiffies, end));
return -ETIMEDOUT;
}
static int status_to_errno(u32 status)
{
switch (status & MAIL_OUT_STATUS_MASK) {
case MAIL_OUT_STATUS_COMPLETED:
return 0;
case MAIL_OUT_STATUS_ERR_AUTH:
return -EINVAL;
case MAIL_OUT_STATUS_ERR_ACCESS:
return -EACCES;
}
return -EIO;
}
static int dma_port_request(struct tb_dma_port *dma, u32 in,
unsigned int timeout)
{
struct tb_switch *sw = dma->sw;
u32 out;
int ret;
ret = dma_port_write(sw->tb->ctl, &in, tb_route(sw), dma->port,
dma->base + MAIL_IN, 1, DMA_PORT_TIMEOUT);
if (ret)
return ret;
ret = dma_port_wait_for_completion(dma, timeout);
if (ret)
return ret;
ret = dma_port_read(sw->tb->ctl, &out, tb_route(sw), dma->port,
dma->base + MAIL_OUT, 1, DMA_PORT_TIMEOUT);
if (ret)
return ret;
return status_to_errno(out);
}
static int dma_port_flash_read_block(struct tb_dma_port *dma, u32 address,
void *buf, u32 size)
{
struct tb_switch *sw = dma->sw;
u32 in, dwaddress, dwords;
int ret;
dwaddress = address / 4;
dwords = size / 4;
in = MAIL_IN_CMD_FLASH_READ << MAIL_IN_CMD_SHIFT;
if (dwords < MAIL_DATA_DWORDS)
in |= (dwords << MAIL_IN_DWORDS_SHIFT) & MAIL_IN_DWORDS_MASK;
in |= (dwaddress << MAIL_IN_ADDRESS_SHIFT) & MAIL_IN_ADDRESS_MASK;
in |= MAIL_IN_OP_REQUEST;
ret = dma_port_request(dma, in, DMA_PORT_TIMEOUT);
if (ret)
return ret;
return dma_port_read(sw->tb->ctl, buf, tb_route(sw), dma->port,
dma->base + MAIL_DATA, dwords, DMA_PORT_TIMEOUT);
}
static int dma_port_flash_write_block(struct tb_dma_port *dma, u32 address,
const void *buf, u32 size)
{
struct tb_switch *sw = dma->sw;
u32 in, dwaddress, dwords;
int ret;
dwords = size / 4;
ret = dma_port_write(sw->tb->ctl, buf, tb_route(sw), dma->port,
dma->base + MAIL_DATA, dwords, DMA_PORT_TIMEOUT);
in = MAIL_IN_CMD_FLASH_WRITE << MAIL_IN_CMD_SHIFT;
if (address >= DMA_PORT_CSS_ADDRESS) {
dwaddress = DMA_PORT_CSS_ADDRESS;
in |= MAIL_IN_CSS;
} else {
dwaddress = address / 4;
}
in |= ((dwords - 1) << MAIL_IN_DWORDS_SHIFT) & MAIL_IN_DWORDS_MASK;
in |= (dwaddress << MAIL_IN_ADDRESS_SHIFT) & MAIL_IN_ADDRESS_MASK;
in |= MAIL_IN_OP_REQUEST;
return dma_port_request(dma, in, DMA_PORT_TIMEOUT);
}
int dma_port_flash_read(struct tb_dma_port *dma, unsigned int address,
void *buf, size_t size)
{
unsigned int retries = DMA_PORT_RETRIES;
unsigned int offset;
offset = address & 3;
address = address & ~3;
do {
u32 nbytes = min_t(u32, size, MAIL_DATA_DWORDS * 4);
int ret;
ret = dma_port_flash_read_block(dma, address, dma->buf,
ALIGN(nbytes, 4));
if (ret) {
if (ret == -ETIMEDOUT) {
if (retries--)
continue;
ret = -EIO;
}
return ret;
}
memcpy(buf, dma->buf + offset, nbytes);
size -= nbytes;
address += nbytes;
buf += nbytes;
} while (size > 0);
return 0;
}
int dma_port_flash_write(struct tb_dma_port *dma, unsigned int address,
const void *buf, size_t size)
{
unsigned int retries = DMA_PORT_RETRIES;
unsigned int offset;
if (address >= DMA_PORT_CSS_ADDRESS) {
offset = 0;
if (size > DMA_PORT_CSS_MAX_SIZE)
return -E2BIG;
} else {
offset = address & 3;
address = address & ~3;
}
do {
u32 nbytes = min_t(u32, size, MAIL_DATA_DWORDS * 4);
int ret;
memcpy(dma->buf + offset, buf, nbytes);
ret = dma_port_flash_write_block(dma, address, buf, nbytes);
if (ret) {
if (ret == -ETIMEDOUT) {
if (retries--)
continue;
ret = -EIO;
}
return ret;
}
size -= nbytes;
address += nbytes;
buf += nbytes;
} while (size > 0);
return 0;
}
int dma_port_flash_update_auth(struct tb_dma_port *dma)
{
u32 in;
in = MAIL_IN_CMD_FLASH_UPDATE_AUTH << MAIL_IN_CMD_SHIFT;
in |= MAIL_IN_OP_REQUEST;
return dma_port_request(dma, in, 150);
}
int dma_port_flash_update_auth_status(struct tb_dma_port *dma, u32 *status)
{
struct tb_switch *sw = dma->sw;
u32 out, cmd;
int ret;
ret = dma_port_read(sw->tb->ctl, &out, tb_route(sw), dma->port,
dma->base + MAIL_OUT, 1, DMA_PORT_TIMEOUT);
if (ret)
return ret;
cmd = (out & MAIL_OUT_STATUS_CMD_MASK) >> MAIL_OUT_STATUS_CMD_SHIFT;
if (cmd == MAIL_IN_CMD_FLASH_UPDATE_AUTH) {
if (status)
*status = out & MAIL_OUT_STATUS_MASK;
return 1;
}
return 0;
}
int dma_port_power_cycle(struct tb_dma_port *dma)
{
u32 in;
in = MAIL_IN_CMD_POWER_CYCLE << MAIL_IN_CMD_SHIFT;
in |= MAIL_IN_OP_REQUEST;
return dma_port_request(dma, in, 150);
}
