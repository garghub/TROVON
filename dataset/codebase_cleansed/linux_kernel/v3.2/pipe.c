char *usbhs_pipe_name(struct usbhs_pipe *pipe)
{
return usbhsp_pipe_name[usbhs_pipe_type(pipe)];
}
static void usbhsp_pipectrl_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
int offset = usbhsp_addr_offset(pipe);
if (usbhs_pipe_is_dcp(pipe))
usbhs_bset(priv, DCPCTR, mask, val);
else
usbhs_bset(priv, PIPEnCTR + offset, mask, val);
}
static u16 usbhsp_pipectrl_get(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
int offset = usbhsp_addr_offset(pipe);
if (usbhs_pipe_is_dcp(pipe))
return usbhs_read(priv, DCPCTR);
else
return usbhs_read(priv, PIPEnCTR + offset);
}
static void __usbhsp_pipe_xxx_set(struct usbhs_pipe *pipe,
u16 dcp_reg, u16 pipe_reg,
u16 mask, u16 val)
{
struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
if (usbhs_pipe_is_dcp(pipe))
usbhs_bset(priv, dcp_reg, mask, val);
else
usbhs_bset(priv, pipe_reg, mask, val);
}
static void usbhsp_pipe_cfg_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
__usbhsp_pipe_xxx_set(pipe, DCPCFG, PIPECFG, mask, val);
}
static void usbhsp_pipe_buf_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
if (usbhs_pipe_is_dcp(pipe))
return;
__usbhsp_pipe_xxx_set(pipe, 0, PIPEBUF, mask, val);
}
static void usbhsp_pipe_maxp_set(struct usbhs_pipe *pipe, u16 mask, u16 val)
{
__usbhsp_pipe_xxx_set(pipe, DCPMAXP, PIPEMAXP, mask, val);
}
static void usbhsp_pipe_select(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
usbhs_write(priv, PIPESEL, 0xF & usbhs_pipe_number(pipe));
}
static int usbhsp_pipe_barrier(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
int timeout = 1024;
u16 val;
usbhs_write(priv, CFIFOSEL, 0);
usbhs_pipe_disable(pipe);
do {
val = usbhsp_pipectrl_get(pipe);
val &= CSSTS | PID_MASK;
if (!val)
return 0;
udelay(10);
} while (timeout--);
return -EBUSY;
}
int usbhs_pipe_is_accessible(struct usbhs_pipe *pipe)
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
void usbhs_pipe_disable(struct usbhs_pipe *pipe)
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
void usbhs_pipe_enable(struct usbhs_pipe *pipe)
{
__usbhsp_pid_try_nak_if_stall(pipe);
usbhsp_pipectrl_set(pipe, PID_MASK, PID_BUF);
}
void usbhs_pipe_stall(struct usbhs_pipe *pipe)
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
static int usbhsp_possible_double_buffer(struct usbhs_pipe *pipe)
{
if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_BULK) ||
usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_ISOC))
return 1;
return 0;
}
static u16 usbhsp_setup_pipecfg(struct usbhs_pipe *pipe,
int is_host,
int dir_in)
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
if (usbhs_pipe_is_dcp(pipe))
return -EINVAL;
type = type_array[usbhs_pipe_type(pipe)];
if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_ISOC) ||
usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_BULK))
bfre = 0;
if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_ISOC) ||
usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_BULK))
dblb = (is_double) ? DBLB : 0;
if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_BULK))
cntmd = 0;
if (dir_in)
usbhsp_flags_set(pipe, IS_DIR_HOST);
if ((is_host && !dir_in) ||
(!is_host && dir_in))
dir |= DIR_OUT;
if (!dir)
usbhsp_flags_set(pipe, IS_DIR_IN);
if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_BULK) &&
!dir)
shtnak = SHTNAK;
epnum = 0;
return type |
bfre |
dblb |
cntmd |
dir |
shtnak |
epnum;
}
static u16 usbhsp_setup_pipebuff(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
struct usbhs_pipe_info *info = usbhs_priv_to_pipeinfo(priv);
struct device *dev = usbhs_priv_to_dev(priv);
int pipe_num = usbhs_pipe_number(pipe);
int is_double = usbhsp_possible_double_buffer(pipe);
u16 buff_size;
u16 bufnmb;
u16 bufnmb_cnt;
if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_CONTROL))
buff_size = 256;
else if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_INT))
buff_size = 64;
else
buff_size = 512;
bufnmb_cnt = (buff_size / 64) - 1;
if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_INT)) {
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
void usbhs_pipe_config_update(struct usbhs_pipe *pipe, u16 devsel,
u16 epnum, u16 maxp)
{
if (devsel > 0xA) {
struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
struct device *dev = usbhs_priv_to_dev(priv);
dev_err(dev, "devsel error %d\n", devsel);
devsel = 0;
}
usbhsp_pipe_barrier(pipe);
pipe->maxp = maxp;
usbhsp_pipe_select(pipe);
usbhsp_pipe_maxp_set(pipe, 0xFFFF,
(devsel << 12) |
maxp);
if (!usbhs_pipe_is_dcp(pipe))
usbhsp_pipe_cfg_set(pipe, 0x000F, epnum);
}
int usbhs_pipe_get_maxpacket(struct usbhs_pipe *pipe)
{
return pipe->maxp;
}
int usbhs_pipe_is_dir_in(struct usbhs_pipe *pipe)
{
return usbhsp_flags_has(pipe, IS_DIR_IN);
}
int usbhs_pipe_is_dir_host(struct usbhs_pipe *pipe)
{
return usbhsp_flags_has(pipe, IS_DIR_HOST);
}
void usbhs_pipe_data_sequence(struct usbhs_pipe *pipe, int data)
{
u16 mask = (SQCLR | SQSET);
u16 val = (data) ? SQSET : SQCLR;
usbhsp_pipectrl_set(pipe, mask, val);
}
void usbhs_pipe_clear(struct usbhs_pipe *pipe)
{
usbhsp_pipectrl_set(pipe, ACLRM, ACLRM);
usbhsp_pipectrl_set(pipe, ACLRM, 0);
}
static struct usbhs_pipe *usbhsp_get_pipe(struct usbhs_priv *priv, u32 type)
{
struct usbhs_pipe *pos, *pipe;
int i;
pipe = NULL;
usbhs_for_each_pipe_with_dcp(pos, priv, i) {
if (!usbhs_pipe_type_is(pos, type))
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
void usbhs_pipe_init(struct usbhs_priv *priv,
int (*dma_map_ctrl)(struct usbhs_pkt *pkt, int map))
{
struct usbhs_pipe_info *info = usbhs_priv_to_pipeinfo(priv);
struct usbhs_pipe *pipe;
int i;
info->bufnmb_last = 4;
usbhs_for_each_pipe_with_dcp(pipe, priv, i) {
if (usbhs_pipe_type_is(pipe, USB_ENDPOINT_XFER_INT))
info->bufnmb_last++;
usbhsp_flags_init(pipe);
pipe->fifo = NULL;
pipe->mod_private = NULL;
INIT_LIST_HEAD(&pipe->list);
usbhs_pipe_clear(pipe);
}
info->dma_map_ctrl = dma_map_ctrl;
}
struct usbhs_pipe *usbhs_pipe_malloc(struct usbhs_priv *priv,
int endpoint_type,
int dir_in)
{
struct device *dev = usbhs_priv_to_dev(priv);
struct usbhs_pipe *pipe;
int is_host = usbhs_mod_is_host(priv);
int ret;
u16 pipecfg, pipebuf;
pipe = usbhsp_get_pipe(priv, endpoint_type);
if (!pipe) {
dev_err(dev, "can't get pipe (%s)\n",
usbhsp_pipe_name[endpoint_type]);
return NULL;
}
INIT_LIST_HEAD(&pipe->list);
usbhs_pipe_disable(pipe);
ret = usbhsp_pipe_barrier(pipe);
if (ret < 0) {
dev_err(dev, "pipe setup failed %d\n", usbhs_pipe_number(pipe));
return NULL;
}
pipecfg = usbhsp_setup_pipecfg(pipe, is_host, dir_in);
pipebuf = usbhsp_setup_pipebuff(pipe);
usbhsp_pipe_select(pipe);
usbhsp_pipe_cfg_set(pipe, 0xFFFF, pipecfg);
usbhsp_pipe_buf_set(pipe, 0xFFFF, pipebuf);
usbhs_pipe_sequence_data0(pipe);
dev_dbg(dev, "enable pipe %d : %s (%s)\n",
usbhs_pipe_number(pipe),
usbhs_pipe_name(pipe),
usbhs_pipe_is_dir_in(pipe) ? "in" : "out");
return pipe;
}
void usbhs_pipe_select_fifo(struct usbhs_pipe *pipe, struct usbhs_fifo *fifo)
{
if (pipe->fifo)
pipe->fifo->pipe = NULL;
pipe->fifo = fifo;
if (fifo)
fifo->pipe = pipe;
}
struct usbhs_pipe *usbhs_dcp_malloc(struct usbhs_priv *priv)
{
struct usbhs_pipe *pipe;
pipe = usbhsp_get_pipe(priv, USB_ENDPOINT_XFER_CONTROL);
if (!pipe)
return NULL;
INIT_LIST_HEAD(&pipe->list);
return pipe;
}
void usbhs_dcp_control_transfer_done(struct usbhs_pipe *pipe)
{
struct usbhs_priv *priv = usbhs_pipe_to_priv(pipe);
WARN_ON(!usbhs_pipe_is_dcp(pipe));
usbhs_pipe_enable(pipe);
if (!usbhs_mod_is_host(priv))
usbhsp_pipectrl_set(pipe, CCPL, CCPL);
}
void usbhs_dcp_dir_for_host(struct usbhs_pipe *pipe, int dir_out)
{
usbhsp_pipe_cfg_set(pipe, DIR_OUT,
dir_out ? DIR_OUT : 0);
}
int usbhs_pipe_probe(struct usbhs_priv *priv)
{
struct usbhs_pipe_info *info = usbhs_priv_to_pipeinfo(priv);
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
usbhs_pipe_type(pipe) =
pipe_type[i] & USB_ENDPOINT_XFERTYPE_MASK;
dev_dbg(dev, "pipe %x\t: %s\n",
i, usbhsp_pipe_name[pipe_type[i]]);
}
return 0;
}
void usbhs_pipe_remove(struct usbhs_priv *priv)
{
struct usbhs_pipe_info *info = usbhs_priv_to_pipeinfo(priv);
kfree(info->pipe);
}
