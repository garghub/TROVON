void usbhs_usbreq_get_val(struct usbhs_priv *priv, struct usb_ctrlrequest *req)
{
u16 val;
val = usbhs_read(priv, USBREQ);
req->bRequest = (val >> 8) & 0xFF;
req->bRequestType = (val >> 0) & 0xFF;
req->wValue = usbhs_read(priv, USBVAL);
req->wIndex = usbhs_read(priv, USBINDX);
req->wLength = usbhs_read(priv, USBLENG);
}
void usbhs_usbreq_set_val(struct usbhs_priv *priv, struct usb_ctrlrequest *req)
{
usbhs_write(priv, USBREQ, (req->bRequest << 8) | req->bRequestType);
usbhs_write(priv, USBVAL, req->wValue);
usbhs_write(priv, USBINDX, req->wIndex);
usbhs_write(priv, USBLENG, req->wLength);
}
static void usbhsp_pipectrl_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
int offset = usbhsp_addr_offset(pipe);
if (usbhsp_is_dcp(pipe))
usbhs_bset(priv, DCPCTR, mask, val);
else
usbhs_bset(priv, PIPEnCTR + offset, mask, val);
}
static u16 usbhsp_pipectrl_get(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
int offset = usbhsp_addr_offset(pipe);
if (usbhsp_is_dcp(pipe))
return usbhs_read(priv, DCPCTR);
else
return usbhs_read(priv, PIPEnCTR + offset);
}
static void __usbhsp_pipe_xxx_set(struct usbhs_pipe *pipe,
u16 dcp_reg, u16 pipe_reg,
u16 mask, u16 val)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
if (usbhsp_is_dcp(pipe))
usbhs_bset(priv, dcp_reg, mask, val);
else
usbhs_bset(priv, pipe_reg, mask, val);
}
static u16 __usbhsp_pipe_xxx_get(struct usbhs_pipe *pipe,
u16 dcp_reg, u16 pipe_reg)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
if (usbhsp_is_dcp(pipe))
return usbhs_read(priv, dcp_reg);
else
return usbhs_read(priv, pipe_reg);
}
static void usbhsp_pipe_cfg_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
__usbhsp_pipe_xxx_set(pipe, DCPCFG, PIPECFG, mask, val);
}
static void usbhsp_pipe_buf_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
if (usbhsp_is_dcp(pipe))
return;
__usbhsp_pipe_xxx_set(pipe, 0, PIPEBUF, mask, val);
}
static void usbhsp_pipe_maxp_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
__usbhsp_pipe_xxx_set(pipe, DCPMAXP, PIPEMAXP, mask, val);
}
static u16 usbhsp_pipe_maxp_get(struct usbhs_pipe *pipe)
{
return __usbhsp_pipe_xxx_get(pipe, DCPMAXP, PIPEMAXP);
}
static void usbhsp_pipe_select(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
usbhs_write(priv, PIPESEL, 0xF & usbhs_pipe_number(pipe));
}
static int usbhsp_pipe_barrier(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
int timeout = 1024;
u16 val;
usbhs_write(priv, CFIFOSEL, 0);
usbhs_fifo_disable(pipe);
do {
val = usbhsp_pipectrl_get(pipe);
val &= CSSTS | PID_MASK;
if (!val)
return 0;
udelay(10);
} while (timeout--);
return -EBUSY;
}
static int usbhsp_pipe_is_accessible(struct usbhs_pipe *pipe)
{
u16 val;
val = usbhsp_pipectrl_get(pipe);
if (val & BSTS)
return 0;
return -EBUSY;
}
static void __usbhsp_pid_try_nak_if_stall(struct usbhs_pipe *pipe)
{
u16 pid = usbhsp_pipectrl_get(pipe);
pid &= PID_MASK;
switch (pid) {
case PID_STALL11:
usbhsp_pipectrl_set(pipe, PID_MASK, PID_STALL10);
case PID_STALL10:
usbhsp_pipectrl_set(pipe, PID_MASK, PID_NAK);
}
}
void usbhs_fifo_disable(struct usbhs_pipe *pipe)
{
int timeout = 1024;
u16 val;
__usbhsp_pid_try_nak_if_stall(pipe);
usbhsp_pipectrl_set(pipe, PID_MASK, PID_NAK);
do {
val = usbhsp_pipectrl_get(pipe);
val &= PBUSY;
if (!val)
break;
udelay(10);
} while (timeout--);
}
void usbhs_fifo_enable(struct usbhs_pipe *pipe)
{
__usbhsp_pid_try_nak_if_stall(pipe);
usbhsp_pipectrl_set(pipe, PID_MASK, PID_BUF);
}
void usbhs_fifo_stall(struct usbhs_pipe *pipe)
{
u16 pid = usbhsp_pipectrl_get(pipe);
pid &= PID_MASK;
switch (pid) {
case PID_NAK:
usbhsp_pipectrl_set(pipe, PID_MASK, PID_STALL10);
break;
case PID_BUF:
usbhsp_pipectrl_set(pipe, PID_MASK, PID_STALL11);
break;
}
}
void usbhs_fifo_send_terminator(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
usbhs_bset(priv, CFIFOCTR, BVAL, BVAL);
}
static void usbhsp_fifo_clear(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
usbhs_write(priv, CFIFOCTR, BCLR);
}
static int usbhsp_fifo_barrier(struct usbhs_priv *priv)
{
int timeout = 1024;
do {
if (usbhs_read(priv, CFIFOCTR) & FRDY)
return 0;
udelay(10);
} while (timeout--);
return -EBUSY;
}
static int usbhsp_fifo_rcv_len(struct usbhs_priv *priv)
{
return usbhs_read(priv, CFIFOCTR) & DTLN_MASK;
}
static int usbhsp_fifo_select(struct usbhs_pipe *pipe, int write)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
struct device *dev = usbhs_priv_to_dev(priv);
int timeout = 1024;
u16 mask = ((1 << 5) | 0xF);
u16 base = usbhs_pipe_number(pipe);
if (usbhsp_is_dcp(pipe))
base |= (1 == write) << 5;
usbhs_write(priv, CFIFOSEL, base | MBW_32);
while (timeout--) {
if (base == (mask & usbhs_read(priv, CFIFOSEL)))
return 0;
udelay(10);
}
dev_err(dev, "fifo select error\n");
return -EIO;
}
int usbhs_fifo_prepare_write(struct usbhs_pipe *pipe)
{
return usbhsp_fifo_select(pipe, 1);
}
int usbhs_fifo_write(struct usbhs_pipe *pipe, u8 *buf, int len)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
void __iomem *addr = priv->base + CFIFO;
int maxp = usbhs_pipe_get_maxpacket(pipe);
int total_len;
int i, ret;
ret = usbhsp_pipe_is_accessible(pipe);
if (ret < 0)
return ret;
ret = usbhsp_fifo_select(pipe, 1);
if (ret < 0)
return ret;
ret = usbhsp_fifo_barrier(priv);
if (ret < 0)
return ret;
len = min(len, maxp);
total_len = len;
if (len >= 4 &&
!((unsigned long)buf & 0x03)) {
iowrite32_rep(addr, buf, len / 4);
len %= 4;
buf += total_len - len;
}
for (i = 0; i < len; i++)
iowrite8(buf[i], addr + (0x03 - (i & 0x03)));
if (total_len < maxp)
usbhs_fifo_send_terminator(pipe);
return total_len;
}
int usbhs_fifo_prepare_read(struct usbhs_pipe *pipe)
{
int ret;
ret = usbhsp_fifo_select(pipe, 0);
if (ret < 0)
return ret;
usbhs_fifo_enable(pipe);
return ret;
}
int usbhs_fifo_read(struct usbhs_pipe *pipe, u8 *buf, int len)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
void __iomem *addr = priv->base + CFIFO;
int rcv_len;
int i, ret;
int total_len;
u32 data = 0;
ret = usbhsp_fifo_select(pipe, 0);
if (ret < 0)
return ret;
ret = usbhsp_fifo_barrier(priv);
if (ret < 0)
return ret;
rcv_len = usbhsp_fifo_rcv_len(priv);
if (0 == rcv_len) {
usbhsp_fifo_clear(pipe);
return 0;
}
len = min(rcv_len, len);
total_len = len;
if (len >= 4 &&
!((unsigned long)buf & 0x03)) {
ioread32_rep(addr, buf, len / 4);
len %= 4;
buf += rcv_len - len;
}
for (i = 0; i < len; i++) {
if (!(i & 0x03))
data = ioread32(addr);
buf[i] = (data >> ((i & 0x03) * 8)) & 0xff;
}
return total_len;
}
static int usbhsp_possible_double_buffer(struct usbhs_pipe *pipe)
{
if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_BULK) ||
usbhsp_type_is(pipe, USB_ENDPOINT_XFER_ISOC))
return 1;
return 0;
}
static u16 usbhsp_setup_pipecfg(struct usbhs_pipe *pipe,
const struct usb_endpoint_descriptor *desc,
int is_host)
{
u16 type = 0;
u16 bfre = 0;
u16 dblb = 0;
u16 cntmd = 0;
u16 dir = 0;
u16 epnum = 0;
u16 shtnak = 0;
u16 type_array[] = {
[USB_ENDPOINT_XFER_BULK] = TYPE_BULK,
[USB_ENDPOINT_XFER_INT] = TYPE_INT,
[USB_ENDPOINT_XFER_ISOC] = TYPE_ISO,
};
int is_double = usbhsp_possible_double_buffer(pipe);
if (usbhsp_is_dcp(pipe))
return -EINVAL;
type = type_array[usbhsp_type(pipe)];
if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_ISOC) ||
usbhsp_type_is(pipe, USB_ENDPOINT_XFER_BULK))
bfre = 0;
if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_ISOC) ||
usbhsp_type_is(pipe, USB_ENDPOINT_XFER_BULK))
dblb = (is_double) ? DBLB : 0;
if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_BULK))
cntmd = 0;
if (usb_endpoint_dir_in(desc))
usbhsp_flags_set(pipe, IS_DIR_IN);
if ((is_host && usb_endpoint_dir_out(desc)) ||
(!is_host && usb_endpoint_dir_in(desc)))
dir |= DIR_OUT;
if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_BULK) &&
!dir)
shtnak = SHTNAK;
epnum = 0xF & usb_endpoint_num(desc);
return type |
bfre |
dblb |
cntmd |
dir |
shtnak |
epnum;
}
static u16 usbhsp_setup_pipemaxp(struct usbhs_pipe *pipe,
const struct usb_endpoint_descriptor *desc,
int is_host)
{
return PIPE_MAXP_MASK & le16_to_cpu(desc->wMaxPacketSize);
}
static u16 usbhsp_setup_pipebuff(struct usbhs_pipe *pipe,
const struct usb_endpoint_descriptor *desc,
int is_host)
{
struct usbhs_priv *priv = usbhsp_pipe_to_priv(pipe);
struct usbhs_pipe_info *info = usbhsp_priv_to_pipeinfo(priv);
struct device *dev = usbhs_priv_to_dev(priv);
int pipe_num = usbhs_pipe_number(pipe);
int is_double = usbhsp_possible_double_buffer(pipe);
u16 buff_size;
u16 bufnmb;
u16 bufnmb_cnt;
if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_CONTROL))
buff_size = 256;
else if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_INT))
buff_size = 64;
else
buff_size = 512;
bufnmb_cnt = (buff_size / 64) - 1;
if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_INT)) {
bufnmb = pipe_num - 2;
} else {
bufnmb = info->bufnmb_last;
info->bufnmb_last += bufnmb_cnt + 1;
if (is_double)
info->bufnmb_last += bufnmb_cnt + 1;
}
dev_dbg(dev, "pipe : %d : buff_size 0x%x: bufnmb 0x%x\n",
pipe_num, buff_size, bufnmb);
return (0x1f & bufnmb_cnt) << 10 |
(0xff & bufnmb) << 0;
}
int usbhs_pipe_get_maxpacket(struct usbhs_pipe *pipe)
{
u16 mask = usbhsp_is_dcp(pipe) ? DCP_MAXP_MASK : PIPE_MAXP_MASK;
usbhsp_pipe_select(pipe);
return (int)(usbhsp_pipe_maxp_get(pipe) & mask);
}
int usbhs_pipe_is_dir_in(struct usbhs_pipe *pipe)
{
return usbhsp_flags_has(pipe, IS_DIR_IN);
}
void usbhs_pipe_clear_sequence(struct usbhs_pipe *pipe)
{
usbhsp_pipectrl_set(pipe, SQCLR, SQCLR);
}
static struct usbhs_pipe *usbhsp_get_pipe(struct usbhs_priv *priv, u32 type)
{
struct usbhs_pipe *pos, *pipe;
int i;
pipe = NULL;
usbhs_for_each_pipe_with_dcp(pos, priv, i) {
if (!usbhsp_type_is(pos, type))
continue;
if (usbhsp_flags_has(pos, IS_USED))
continue;
pipe = pos;
break;
}
if (!pipe)
return NULL;
usbhsp_flags_init(pipe);
usbhsp_flags_set(pipe, IS_USED);
return pipe;
}
void usbhs_pipe_init(struct usbhs_priv *priv)
{
struct usbhs_pipe_info *info = usbhsp_priv_to_pipeinfo(priv);
struct usbhs_pipe *pipe;
int i;
info->bufnmb_last = 4;
usbhs_for_each_pipe_with_dcp(pipe, priv, i) {
if (usbhsp_type_is(pipe, USB_ENDPOINT_XFER_INT))
info->bufnmb_last++;
usbhsp_flags_init(pipe);
pipe->mod_private = NULL;
usbhsp_fifo_clear(pipe);
}
}
struct usbhs_pipe *usbhs_pipe_malloc(struct usbhs_priv *priv,
const struct usb_endpoint_descriptor *desc)
{
struct device *dev = usbhs_priv_to_dev(priv);
struct usbhs_mod *mod = usbhs_mod_get_current(priv);
struct usbhs_pipe *pipe;
int is_host = usbhs_mod_is_host(priv, mod);
int ret;
u16 pipecfg, pipebuf, pipemaxp;
pipe = usbhsp_get_pipe(priv, usb_endpoint_type(desc));
if (!pipe) {
dev_err(dev, "can't get pipe (%s)\n",
usbhsp_pipe_name[usb_endpoint_type(desc)]);
return NULL;
}
usbhs_fifo_disable(pipe);
ret = usbhsp_pipe_barrier(pipe);
if (ret < 0) {
dev_err(dev, "pipe setup failed %d\n", usbhs_pipe_number(pipe));
return NULL;
}
pipecfg = usbhsp_setup_pipecfg(pipe, desc, is_host);
pipebuf = usbhsp_setup_pipebuff(pipe, desc, is_host);
pipemaxp = usbhsp_setup_pipemaxp(pipe, desc, is_host);
usbhsp_pipectrl_set(pipe, ACLRM, ACLRM);
usbhsp_pipectrl_set(pipe, ACLRM, 0);
usbhsp_pipe_select(pipe);
usbhsp_pipe_cfg_set(pipe, 0xFFFF, pipecfg);
usbhsp_pipe_buf_set(pipe, 0xFFFF, pipebuf);
usbhsp_pipe_maxp_set(pipe, 0xFFFF, pipemaxp);
usbhs_pipe_clear_sequence(pipe);
dev_dbg(dev, "enable pipe %d : %s (%s)\n",
usbhs_pipe_number(pipe),
usbhsp_pipe_name[usb_endpoint_type(desc)],
usbhs_pipe_is_dir_in(pipe) ? "in" : "out");
return pipe;
}
struct usbhs_pipe *usbhs_dcp_malloc(struct usbhs_priv *priv)
{
struct usbhs_pipe *pipe;
pipe = usbhsp_get_pipe(priv, USB_ENDPOINT_XFER_CONTROL);
if (!pipe)
return NULL;
usbhsp_pipe_select(pipe);
usbhs_pipe_clear_sequence(pipe);
return pipe;
}
void usbhs_dcp_control_transfer_done(struct usbhs_pipe *pipe)
{
WARN_ON(!usbhsp_is_dcp(pipe));
usbhs_fifo_enable(pipe);
usbhsp_pipectrl_set(pipe, CCPL, CCPL);
}
int usbhs_pipe_probe(struct usbhs_priv *priv)
{
struct usbhs_pipe_info *info = usbhsp_priv_to_pipeinfo(priv);
struct usbhs_pipe *pipe;
struct device *dev = usbhs_priv_to_dev(priv);
u32 *pipe_type = usbhs_get_dparam(priv, pipe_type);
int pipe_size = usbhs_get_dparam(priv, pipe_size);
int i;
if (pipe_type[0] != USB_ENDPOINT_XFER_CONTROL) {
dev_err(dev, "1st PIPE is not DCP\n");
return -EINVAL;
}
info->pipe = kzalloc(sizeof(struct usbhs_pipe) * pipe_size, GFP_KERNEL);
if (!info->pipe) {
dev_err(dev, "Could not allocate pipe\n");
return -ENOMEM;
}
info->size = pipe_size;
usbhs_for_each_pipe_with_dcp(pipe, priv, i) {
pipe->priv = priv;
usbhsp_type(pipe) = pipe_type[i] & USB_ENDPOINT_XFERTYPE_MASK;
dev_dbg(dev, "pipe %x\t: %s\n",
i, usbhsp_pipe_name[pipe_type[i]]);
}
return 0;
}
void usbhs_pipe_remove(struct usbhs_priv *priv)
{
struct usbhs_pipe_info *info = usbhsp_priv_to_pipeinfo(priv);
kfree(info->pipe);
}
