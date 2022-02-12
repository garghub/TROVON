static inline struct lpc32xx_udc *to_udc(struct usb_gadget *g)
{
return container_of(g, struct lpc32xx_udc, gadget);
}
static void proc_ep_show(struct seq_file *s, struct lpc32xx_ep *ep)
{
struct lpc32xx_request *req;
seq_printf(s, "\n");
seq_printf(s, "%12s, maxpacket %4d %3s",
ep->ep.name, ep->ep.maxpacket,
ep->is_in ? "in" : "out");
seq_printf(s, " type %4s", epnames[ep->eptype]);
seq_printf(s, " ints: %12d", ep->totalints);
if (list_empty(&ep->queue))
seq_printf(s, "\t(queue empty)\n");
else {
list_for_each_entry(req, &ep->queue, queue) {
u32 length = req->req.actual;
seq_printf(s, "\treq %p len %d/%d buf %p\n",
&req->req, length,
req->req.length, req->req.buf);
}
}
}
static int proc_udc_show(struct seq_file *s, void *unused)
{
struct lpc32xx_udc *udc = s->private;
struct lpc32xx_ep *ep;
unsigned long flags;
seq_printf(s, "%s: version %s\n", driver_name, DRIVER_VERSION);
spin_lock_irqsave(&udc->lock, flags);
seq_printf(s, "vbus %s, pullup %s, %s powered%s, gadget %s\n\n",
udc->vbus ? "present" : "off",
udc->enabled ? (udc->vbus ? "active" : "enabled") :
"disabled",
udc->selfpowered ? "self" : "VBUS",
udc->suspended ? ", suspended" : "",
udc->driver ? udc->driver->driver.name : "(none)");
if (udc->enabled && udc->vbus) {
proc_ep_show(s, &udc->ep[0]);
list_for_each_entry(ep, &udc->gadget.ep_list, ep.ep_list)
proc_ep_show(s, ep);
}
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int proc_udc_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_udc_show, PDE(inode)->data);
}
static void create_debug_file(struct lpc32xx_udc *udc)
{
udc->pde = debugfs_create_file(debug_filename, 0, NULL, udc, &proc_ops);
}
static void remove_debug_file(struct lpc32xx_udc *udc)
{
if (udc->pde)
debugfs_remove(udc->pde);
}
static inline void create_debug_file(struct lpc32xx_udc *udc) {}
static inline void remove_debug_file(struct lpc32xx_udc *udc) {}
static void isp1301_udc_configure(struct lpc32xx_udc *udc)
{
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
(ISP1301_I2C_MODE_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR),
MC1_UART_EN);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
(ISP1301_I2C_MODE_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR), ~0);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_MODE_CONTROL_1, (MC1_SPEED_REG | MC1_DAT_SE0));
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
(ISP1301_I2C_MODE_CONTROL_2 | ISP1301_I2C_REG_CLEAR_ADDR), ~0);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_MODE_CONTROL_2, (MC2_BI_DI | MC2_SPD_SUSP_CTRL));
if (udc->board->vbus_drv_pol != 0)
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1, OTG1_VBUS_DRV);
else
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR,
OTG1_VBUS_DRV);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
(ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR), ~0);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1,
(0 | OTG1_DM_PULLDOWN | OTG1_DP_PULLDOWN));
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1, OTG1_VBUS_DISCHRG);
msleep(1);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
(ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR),
OTG1_VBUS_DISCHRG);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_LATCH | ISP1301_I2C_REG_CLEAR_ADDR, ~0);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_FALLING | ISP1301_I2C_REG_CLEAR_ADDR, ~0);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_FALLING, INT_VBUS_VLD);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_RISING | ISP1301_I2C_REG_CLEAR_ADDR, ~0);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_RISING, INT_VBUS_VLD);
writel((readl(USB_CTRL) | USB_DEV_NEED_CLK_EN), USB_CTRL);
dev_info(udc->dev, "ISP1301 Vendor ID : 0x%04x\n",
i2c_smbus_read_word_data(udc->isp1301_i2c_client, 0x00));
dev_info(udc->dev, "ISP1301 Product ID : 0x%04x\n",
i2c_smbus_read_word_data(udc->isp1301_i2c_client, 0x02));
dev_info(udc->dev, "ISP1301 Version ID : 0x%04x\n",
i2c_smbus_read_word_data(udc->isp1301_i2c_client, 0x14));
}
static void isp1301_pullup_set(struct lpc32xx_udc *udc)
{
if (udc->pullup)
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1, OTG1_DP_PULLUP);
else
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR,
OTG1_DP_PULLUP);
}
static void pullup_work(struct work_struct *work)
{
struct lpc32xx_udc *udc =
container_of(work, struct lpc32xx_udc, pullup_job);
isp1301_pullup_set(udc);
}
static void isp1301_pullup_enable(struct lpc32xx_udc *udc, int en_pullup,
int block)
{
if (en_pullup == udc->pullup)
return;
udc->pullup = en_pullup;
if (block)
isp1301_pullup_set(udc);
else
schedule_work(&udc->pullup_job);
}
static void isp1301_set_powerstate(struct lpc32xx_udc *udc, int enable)
{
if (enable != 0)
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_MODE_CONTROL_2 | ISP1301_I2C_REG_CLEAR_ADDR,
MC2_GLOBAL_PWR_DN);
else
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_MODE_CONTROL_2, MC2_GLOBAL_PWR_DN);
}
static void power_work(struct work_struct *work)
{
struct lpc32xx_udc *udc =
container_of(work, struct lpc32xx_udc, power_job);
isp1301_set_powerstate(udc, udc->poweron);
}
static void udc_protocol_cmd_w(struct lpc32xx_udc *udc, u32 cmd)
{
u32 pass = 0;
int to;
u32 tmp = readl(USBD_DEVINTST(udc->udp_baseaddr));
(void) tmp;
while (pass == 0) {
writel(USBD_CCEMPTY, USBD_DEVINTCLR(udc->udp_baseaddr));
writel(cmd, USBD_CMDCODE(udc->udp_baseaddr));
to = 10000;
while (((readl(USBD_DEVINTST(udc->udp_baseaddr)) &
USBD_CCEMPTY) == 0) && (to > 0)) {
to--;
}
if (to > 0)
pass = 1;
cpu_relax();
}
}
static inline void udc_protocol_cmd_data_w(struct lpc32xx_udc *udc, u32 cmd,
u32 data)
{
udc_protocol_cmd_w(udc, cmd);
udc_protocol_cmd_w(udc, data);
}
static u32 udc_protocol_cmd_r(struct lpc32xx_udc *udc, u32 cmd)
{
u32 tmp;
int to = 1000;
writel((USBD_CDFULL | USBD_CCEMPTY),
USBD_DEVINTCLR(udc->udp_baseaddr));
udc_protocol_cmd_w(udc, cmd);
tmp = readl(USBD_DEVINTST(udc->udp_baseaddr));
while ((!(readl(USBD_DEVINTST(udc->udp_baseaddr)) & USBD_CDFULL))
&& (to > 0))
to--;
if (!to)
dev_dbg(udc->dev,
"Protocol engine didn't receive response (CDFULL)\n");
return readl(USBD_CMDDATA(udc->udp_baseaddr));
}
static inline void uda_enable_devint(struct lpc32xx_udc *udc, u32 devmask)
{
udc->enabled_devints |= devmask;
writel(udc->enabled_devints, USBD_DEVINTEN(udc->udp_baseaddr));
}
static inline void uda_disable_devint(struct lpc32xx_udc *udc, u32 mask)
{
udc->enabled_devints &= ~mask;
writel(udc->enabled_devints, USBD_DEVINTEN(udc->udp_baseaddr));
}
static inline void uda_clear_devint(struct lpc32xx_udc *udc, u32 mask)
{
writel(mask, USBD_DEVINTCLR(udc->udp_baseaddr));
}
static void uda_enable_hwepint(struct lpc32xx_udc *udc, u32 hwep)
{
udc->enabled_hwepints |= (1 << hwep);
writel(udc->enabled_hwepints, USBD_EPINTEN(udc->udp_baseaddr));
}
static void uda_disable_hwepint(struct lpc32xx_udc *udc, u32 hwep)
{
udc->enabled_hwepints &= ~(1 << hwep);
writel(udc->enabled_hwepints, USBD_EPINTEN(udc->udp_baseaddr));
}
static inline void uda_clear_hwepint(struct lpc32xx_udc *udc, u32 hwep)
{
writel((1 << hwep), USBD_EPINTCLR(udc->udp_baseaddr));
}
static inline void udc_ep_dma_enable(struct lpc32xx_udc *udc, u32 hwep)
{
writel((1 << hwep), USBD_EPDMAEN(udc->udp_baseaddr));
}
static inline void udc_ep_dma_disable(struct lpc32xx_udc *udc, u32 hwep)
{
writel((1 << hwep), USBD_EPDMADIS(udc->udp_baseaddr));
}
static void udc_realize_hwep(struct lpc32xx_udc *udc, u32 hwep,
u32 maxpacket)
{
int to = 1000;
writel(USBD_EP_RLZED, USBD_DEVINTCLR(udc->udp_baseaddr));
writel(hwep, USBD_EPIND(udc->udp_baseaddr));
udc->realized_eps |= (1 << hwep);
writel(udc->realized_eps, USBD_REEP(udc->udp_baseaddr));
writel(maxpacket, USBD_EPMAXPSIZE(udc->udp_baseaddr));
while ((!(readl(USBD_DEVINTST(udc->udp_baseaddr)) &
USBD_EP_RLZED)) && (to > 0))
to--;
if (!to)
dev_dbg(udc->dev, "EP not correctly realized in hardware\n");
writel(USBD_EP_RLZED, USBD_DEVINTCLR(udc->udp_baseaddr));
}
static void udc_unrealize_hwep(struct lpc32xx_udc *udc, u32 hwep)
{
udc->realized_eps &= ~(1 << hwep);
writel(udc->realized_eps, USBD_REEP(udc->udp_baseaddr));
}
static u32 udc_selep_clrint(struct lpc32xx_udc *udc, u32 hwep)
{
udc_protocol_cmd_w(udc, CMD_SEL_EP_CLRI(hwep));
return udc_protocol_cmd_r(udc, DAT_SEL_EP_CLRI(hwep));
}
static void udc_disable_hwep(struct lpc32xx_udc *udc, u32 hwep)
{
udc_protocol_cmd_data_w(udc, CMD_SET_EP_STAT(hwep),
DAT_WR_BYTE(EP_STAT_DA));
}
static void udc_stall_hwep(struct lpc32xx_udc *udc, u32 hwep)
{
udc_protocol_cmd_data_w(udc, CMD_SET_EP_STAT(hwep),
DAT_WR_BYTE(EP_STAT_ST));
}
static void udc_clrstall_hwep(struct lpc32xx_udc *udc, u32 hwep)
{
udc_protocol_cmd_data_w(udc, CMD_SET_EP_STAT(hwep),
DAT_WR_BYTE(0));
}
static void udc_select_hwep(struct lpc32xx_udc *udc, u32 hwep)
{
udc_protocol_cmd_w(udc, CMD_SEL_EP(hwep));
}
static void udc_clr_buffer_hwep(struct lpc32xx_udc *udc, u32 hwep)
{
udc_select_hwep(udc, hwep);
udc_protocol_cmd_w(udc, CMD_CLR_BUF);
}
static void udc_val_buffer_hwep(struct lpc32xx_udc *udc, u32 hwep)
{
udc_select_hwep(udc, hwep);
udc_protocol_cmd_w(udc, CMD_VALID_BUF);
}
static inline u32 udc_clearep_getsts(struct lpc32xx_udc *udc, u32 hwep)
{
uda_clear_hwepint(udc, hwep);
return udc_selep_clrint(udc, hwep);
}
static struct lpc32xx_usbd_dd_gad *udc_dd_alloc(struct lpc32xx_udc *udc)
{
dma_addr_t dma;
struct lpc32xx_usbd_dd_gad *dd;
dd = (struct lpc32xx_usbd_dd_gad *) dma_pool_alloc(
udc->dd_cache, (GFP_KERNEL | GFP_DMA), &dma);
if (dd)
dd->this_dma = dma;
return dd;
}
static void udc_dd_free(struct lpc32xx_udc *udc, struct lpc32xx_usbd_dd_gad *dd)
{
dma_pool_free(udc->dd_cache, dd, dd->this_dma);
}
static void udc_clk_set(struct lpc32xx_udc *udc, int enable)
{
if (enable != 0) {
if (udc->clocked)
return;
udc->clocked = 1;
clk_enable(udc->usb_pll_clk);
writel(readl(USB_CTRL) | USB_DEV_NEED_CLK_EN,
USB_CTRL);
clk_enable(udc->usb_otg_clk);
} else {
if (!udc->clocked)
return;
udc->clocked = 0;
clk_disable(udc->usb_pll_clk);
writel(readl(USB_CTRL) & ~USB_DEV_NEED_CLK_EN,
USB_CTRL);
clk_disable(udc->usb_otg_clk);
}
}
static void udc_set_address(struct lpc32xx_udc *udc, u32 addr)
{
udc_protocol_cmd_data_w(udc, CMD_SET_ADDR,
DAT_WR_BYTE(DEV_EN | addr));
}
static int udc_ep_in_req_dma(struct lpc32xx_udc *udc, struct lpc32xx_ep *ep)
{
struct lpc32xx_request *req;
u32 hwep = ep->hwep_num;
ep->req_pending = 1;
req = list_entry(ep->queue.next, struct lpc32xx_request, queue);
udc->udca_v_base[hwep] = req->dd_desc_ptr->this_dma;
udc_ep_dma_enable(udc, hwep);
if (req->req.length % ep->ep.maxpacket)
req->send_zlp = 0;
return 0;
}
static int udc_ep_out_req_dma(struct lpc32xx_udc *udc, struct lpc32xx_ep *ep)
{
struct lpc32xx_request *req;
u32 hwep = ep->hwep_num;
ep->req_pending = 1;
req = list_entry(ep->queue.next, struct lpc32xx_request, queue);
udc->udca_v_base[hwep] = req->dd_desc_ptr->this_dma;
udc_ep_dma_enable(udc, hwep);
return 0;
}
static void udc_disable(struct lpc32xx_udc *udc)
{
u32 i;
udc_protocol_cmd_data_w(udc, CMD_CFG_DEV, DAT_WR_BYTE(0));
udc_protocol_cmd_data_w(udc, CMD_SET_DEV_STAT, DAT_WR_BYTE(0));
uda_disable_devint(udc, 0x3FF);
for (i = 0; i < 32; i++) {
uda_disable_hwepint(udc, i);
uda_clear_hwepint(udc, i);
udc_disable_hwep(udc, i);
udc_unrealize_hwep(udc, i);
udc->udca_v_base[i] = 0;
udc_ep_dma_disable(udc, i);
writel((1 << i), USBD_EOTINTCLR(udc->udp_baseaddr));
writel((1 << i), USBD_NDDRTINTCLR(udc->udp_baseaddr));
writel((1 << i), USBD_SYSERRTINTCLR(udc->udp_baseaddr));
writel((1 << i), USBD_DMARCLR(udc->udp_baseaddr));
}
writel(0, USBD_DMAINTEN(udc->udp_baseaddr));
writel(0, USBD_UDCAH(udc->udp_baseaddr));
}
static void udc_enable(struct lpc32xx_udc *udc)
{
u32 i;
struct lpc32xx_ep *ep = &udc->ep[0];
udc_disable(udc);
udc_protocol_cmd_data_w(udc, CMD_SET_DEV_STAT, DAT_WR_BYTE(DEV_CON));
writel(USBD_EP_FAST, USBD_DEVINTPRI(udc->udp_baseaddr));
writel(0xFFFF, USBD_EPINTPRI(udc->udp_baseaddr));
writel(0x3FF, USBD_DEVINTCLR(udc->udp_baseaddr));
writel(udc->udca_p_base, USBD_UDCAH(udc->udp_baseaddr));
for (i = 0; i <= 1; i++) {
udc_realize_hwep(udc, i, ep->ep.maxpacket);
uda_enable_hwepint(udc, i);
udc_select_hwep(udc, i);
udc_clrstall_hwep(udc, i);
udc_clr_buffer_hwep(udc, i);
}
uda_clear_devint(udc, (USBD_ERR_INT | USBD_DEV_STAT | USBD_EP_SLOW |
USBD_EP_FAST));
uda_enable_devint(udc, (USBD_ERR_INT | USBD_DEV_STAT | USBD_EP_SLOW |
USBD_EP_FAST));
udc_set_address(udc, 0);
udc_set_address(udc, 0);
writel((USBD_SYS_ERR_INT | USBD_EOT_INT),
USBD_DMAINTEN(udc->udp_baseaddr));
udc->dev_status = 0;
}
static void uda_power_event(struct lpc32xx_udc *udc, u32 conn)
{
if (udc->board->conn_chgb != NULL)
udc->board->conn_chgb(conn);
}
static void uda_resm_susp_event(struct lpc32xx_udc *udc, u32 conn)
{
if (udc->board->susp_chgb != NULL)
udc->board->susp_chgb(conn);
if (conn)
udc->suspended = 0;
else
udc->suspended = 1;
}
static void uda_remwkp_cgh(struct lpc32xx_udc *udc)
{
if (udc->board->rmwk_chgb != NULL)
udc->board->rmwk_chgb(udc->dev_status &
(1 << USB_DEVICE_REMOTE_WAKEUP));
}
static void udc_pop_fifo(struct lpc32xx_udc *udc, u8 *data, u32 bytes)
{
int n, i, bl;
u16 *p16;
u32 *p32, tmp, cbytes;
switch (((u32) data) & 0x3) {
case 0:
p32 = (u32 *) data;
cbytes = (bytes & ~0x3);
for (n = 0; n < cbytes; n += 4)
*p32++ = readl(USBD_RXDATA(udc->udp_baseaddr));
bl = bytes - cbytes;
if (bl) {
tmp = readl(USBD_RXDATA(udc->udp_baseaddr));
for (n = 0; n < bl; n++)
data[cbytes + n] = ((tmp >> (n * 8)) & 0xFF);
}
break;
case 1:
case 3:
for (n = 0; n < bytes; n += 4) {
tmp = readl(USBD_RXDATA(udc->udp_baseaddr));
bl = bytes - n;
if (bl > 3)
bl = 3;
for (i = 0; i < bl; i++)
data[n + i] = (u8) ((tmp >> (n * 8)) & 0xFF);
}
break;
case 2:
p16 = (u16 *) data;
cbytes = (bytes & ~0x3);
for (n = 0; n < cbytes; n += 4) {
tmp = readl(USBD_RXDATA(udc->udp_baseaddr));
*p16++ = (u16)(tmp & 0xFFFF);
*p16++ = (u16)((tmp >> 16) & 0xFFFF);
}
bl = bytes - cbytes;
if (bl) {
tmp = readl(USBD_RXDATA(udc->udp_baseaddr));
for (n = 0; n < bl; n++)
data[cbytes + n] = ((tmp >> (n * 8)) & 0xFF);
}
break;
}
}
static u32 udc_read_hwep(struct lpc32xx_udc *udc, u32 hwep, u32 *data,
u32 bytes)
{
u32 tmpv;
int to = 1000;
u32 tmp, hwrep = ((hwep & 0x1E) << 1) | CTRL_RD_EN;
writel(hwrep, USBD_CTRL(udc->udp_baseaddr));
while ((((tmpv = readl(USBD_RXPLEN(udc->udp_baseaddr))) &
PKT_RDY) == 0) && (to > 0))
to--;
if (!to)
dev_dbg(udc->dev, "No packet ready on FIFO EP read\n");
tmp = tmpv & PKT_LNGTH_MASK;
if (bytes < tmp)
tmp = bytes;
if ((tmp > 0) && (data != NULL))
udc_pop_fifo(udc, (u8 *) data, tmp);
writel(((hwep & 0x1E) << 1), USBD_CTRL(udc->udp_baseaddr));
udc_clr_buffer_hwep(udc, hwep);
return tmp;
}
static void udc_stuff_fifo(struct lpc32xx_udc *udc, u8 *data, u32 bytes)
{
int n, i, bl;
u16 *p16;
u32 *p32, tmp, cbytes;
switch (((u32) data) & 0x3) {
case 0:
p32 = (u32 *) data;
cbytes = (bytes & ~0x3);
for (n = 0; n < cbytes; n += 4)
writel(*p32++, USBD_TXDATA(udc->udp_baseaddr));
bl = bytes - cbytes;
if (bl) {
tmp = 0;
for (n = 0; n < bl; n++)
tmp |= data[cbytes + n] << (n * 8);
writel(tmp, USBD_TXDATA(udc->udp_baseaddr));
}
break;
case 1:
case 3:
for (n = 0; n < bytes; n += 4) {
bl = bytes - n;
if (bl > 4)
bl = 4;
tmp = 0;
for (i = 0; i < bl; i++)
tmp |= data[n + i] << (i * 8);
writel(tmp, USBD_TXDATA(udc->udp_baseaddr));
}
break;
case 2:
p16 = (u16 *) data;
cbytes = (bytes & ~0x3);
for (n = 0; n < cbytes; n += 4) {
tmp = *p16++ & 0xFFFF;
tmp |= (*p16++ & 0xFFFF) << 16;
writel(tmp, USBD_TXDATA(udc->udp_baseaddr));
}
bl = bytes - cbytes;
if (bl) {
tmp = 0;
for (n = 0; n < bl; n++)
tmp |= data[cbytes + n] << (n * 8);
writel(tmp, USBD_TXDATA(udc->udp_baseaddr));
}
break;
}
}
static void udc_write_hwep(struct lpc32xx_udc *udc, u32 hwep, u32 *data,
u32 bytes)
{
u32 hwwep = ((hwep & 0x1E) << 1) | CTRL_WR_EN;
if ((bytes > 0) && (data == NULL))
return;
writel(hwwep, USBD_CTRL(udc->udp_baseaddr));
writel(bytes, USBD_TXPLEN(udc->udp_baseaddr));
if (bytes == 0)
writel(0, USBD_TXDATA(udc->udp_baseaddr));
else
udc_stuff_fifo(udc, (u8 *) data, bytes);
writel(((hwep & 0x1E) << 1), USBD_CTRL(udc->udp_baseaddr));
udc_val_buffer_hwep(udc, hwep);
}
static void uda_usb_reset(struct lpc32xx_udc *udc)
{
u32 i = 0;
udc_enable(udc);
udc->gadget.speed = USB_SPEED_FULL;
for (i = 1; i < NUM_ENDPOINTS; i++) {
struct lpc32xx_ep *ep = &udc->ep[i];
ep->req_pending = 0;
}
}
static void udc_ep0_send_zlp(struct lpc32xx_udc *udc)
{
udc_write_hwep(udc, EP_IN, NULL, 0);
}
static u16 udc_get_current_frame(struct lpc32xx_udc *udc)
{
u16 flo, fhi;
udc_protocol_cmd_w(udc, CMD_RD_FRAME);
flo = (u16) udc_protocol_cmd_r(udc, DAT_RD_FRAME);
fhi = (u16) udc_protocol_cmd_r(udc, DAT_RD_FRAME);
return (fhi << 8) | flo;
}
static inline void udc_set_device_configured(struct lpc32xx_udc *udc)
{
udc_protocol_cmd_data_w(udc, CMD_CFG_DEV, DAT_WR_BYTE(CONF_DVICE));
}
static inline void udc_set_device_unconfigured(struct lpc32xx_udc *udc)
{
udc_protocol_cmd_data_w(udc, CMD_CFG_DEV, DAT_WR_BYTE(0));
}
static void udc_reinit(struct lpc32xx_udc *udc)
{
u32 i;
INIT_LIST_HEAD(&udc->gadget.ep_list);
INIT_LIST_HEAD(&udc->gadget.ep0->ep_list);
for (i = 0; i < NUM_ENDPOINTS; i++) {
struct lpc32xx_ep *ep = &udc->ep[i];
if (i != 0)
list_add_tail(&ep->ep.ep_list, &udc->gadget.ep_list);
ep->ep.maxpacket = ep->maxpacket;
INIT_LIST_HEAD(&ep->queue);
ep->req_pending = 0;
}
udc->ep0state = WAIT_FOR_SETUP;
}
static void done(struct lpc32xx_ep *ep, struct lpc32xx_request *req, int status)
{
struct lpc32xx_udc *udc = ep->udc;
list_del_init(&req->queue);
if (req->req.status == -EINPROGRESS)
req->req.status = status;
else
status = req->req.status;
if (ep->lep) {
enum dma_data_direction direction;
if (ep->is_in)
direction = DMA_TO_DEVICE;
else
direction = DMA_FROM_DEVICE;
if (req->mapped) {
dma_unmap_single(ep->udc->gadget.dev.parent,
req->req.dma, req->req.length,
direction);
req->req.dma = 0;
req->mapped = 0;
} else
dma_sync_single_for_cpu(ep->udc->gadget.dev.parent,
req->req.dma, req->req.length,
direction);
udc_dd_free(udc, req->dd_desc_ptr);
}
if (status && status != -ESHUTDOWN)
ep_dbg(ep, "%s done %p, status %d\n", ep->ep.name, req, status);
ep->req_pending = 0;
spin_unlock(&udc->lock);
req->req.complete(&ep->ep, &req->req);
spin_lock(&udc->lock);
}
static void nuke(struct lpc32xx_ep *ep, int status)
{
struct lpc32xx_request *req;
while (!list_empty(&ep->queue)) {
req = list_entry(ep->queue.next, struct lpc32xx_request, queue);
done(ep, req, status);
}
if (status == -ESHUTDOWN) {
uda_disable_hwepint(ep->udc, ep->hwep_num);
udc_disable_hwep(ep->udc, ep->hwep_num);
}
}
static int udc_ep0_in_req(struct lpc32xx_udc *udc)
{
struct lpc32xx_request *req;
struct lpc32xx_ep *ep0 = &udc->ep[0];
u32 tsend, ts = 0;
if (list_empty(&ep0->queue))
return 0;
else
req = list_entry(ep0->queue.next, struct lpc32xx_request,
queue);
tsend = ts = req->req.length - req->req.actual;
if (ts == 0) {
udc_ep0_send_zlp(udc);
done(ep0, req, 0);
return 1;
} else if (ts > ep0->ep.maxpacket)
ts = ep0->ep.maxpacket;
udc_write_hwep(udc, EP_IN, (req->req.buf + req->req.actual), ts);
req->req.actual += ts;
if (tsend >= ep0->ep.maxpacket)
return 0;
udc->ep0state = WAIT_FOR_SETUP;
done(ep0, req, 0);
return 1;
}
static int udc_ep0_out_req(struct lpc32xx_udc *udc)
{
struct lpc32xx_request *req;
struct lpc32xx_ep *ep0 = &udc->ep[0];
u32 tr, bufferspace;
if (list_empty(&ep0->queue))
return 0;
else
req = list_entry(ep0->queue.next, struct lpc32xx_request,
queue);
if (req) {
if (req->req.length == 0) {
done(ep0, req, 0);
udc->ep0state = WAIT_FOR_SETUP;
return 1;
}
bufferspace = req->req.length - req->req.actual;
if (bufferspace > ep0->ep.maxpacket)
bufferspace = ep0->ep.maxpacket;
prefetchw(req->req.buf + req->req.actual);
tr = udc_read_hwep(udc, EP_OUT, req->req.buf + req->req.actual,
bufferspace);
req->req.actual += bufferspace;
if (tr < ep0->ep.maxpacket) {
done(ep0, req, 0);
udc->ep0state = WAIT_FOR_SETUP;
return 1;
}
}
return 0;
}
static void stop_activity(struct lpc32xx_udc *udc)
{
struct usb_gadget_driver *driver = udc->driver;
int i;
if (udc->gadget.speed == USB_SPEED_UNKNOWN)
driver = NULL;
udc->gadget.speed = USB_SPEED_UNKNOWN;
udc->suspended = 0;
for (i = 0; i < NUM_ENDPOINTS; i++) {
struct lpc32xx_ep *ep = &udc->ep[i];
nuke(ep, -ESHUTDOWN);
}
if (driver) {
spin_unlock(&udc->lock);
driver->disconnect(&udc->gadget);
spin_lock(&udc->lock);
}
isp1301_pullup_enable(udc, 0, 0);
udc_disable(udc);
udc_reinit(udc);
}
static void pullup(struct lpc32xx_udc *udc, int is_on)
{
if (!udc->clocked)
return;
if (!udc->enabled || !udc->vbus)
is_on = 0;
if (is_on != udc->pullup)
isp1301_pullup_enable(udc, is_on, 0);
}
static int lpc32xx_ep_disable(struct usb_ep *_ep)
{
struct lpc32xx_ep *ep = container_of(_ep, struct lpc32xx_ep, ep);
struct lpc32xx_udc *udc = ep->udc;
unsigned long flags;
if ((ep->hwep_num_base == 0) || (ep->hwep_num == 0))
return -EINVAL;
spin_lock_irqsave(&udc->lock, flags);
nuke(ep, -ESHUTDOWN);
udc_ep_dma_disable(udc, ep->hwep_num);
writel(1 << ep->hwep_num, USBD_EOTINTCLR(udc->udp_baseaddr));
writel(1 << ep->hwep_num, USBD_NDDRTINTCLR(udc->udp_baseaddr));
writel(1 << ep->hwep_num, USBD_SYSERRTINTCLR(udc->udp_baseaddr));
writel(1 << ep->hwep_num, USBD_DMARCLR(udc->udp_baseaddr));
udc->udca_v_base[ep->hwep_num] = 0;
uda_clear_hwepint(udc, ep->hwep_num);
udc_unrealize_hwep(udc, ep->hwep_num);
ep->hwep_num = 0;
spin_unlock_irqrestore(&udc->lock, flags);
atomic_dec(&udc->enabled_ep_cnt);
wake_up(&udc->ep_disable_wait_queue);
return 0;
}
static int lpc32xx_ep_enable(struct usb_ep *_ep,
const struct usb_endpoint_descriptor *desc)
{
struct lpc32xx_ep *ep = container_of(_ep, struct lpc32xx_ep, ep);
struct lpc32xx_udc *udc = ep->udc;
u16 maxpacket;
u32 tmp;
unsigned long flags;
if ((!_ep) || (!ep) || (!desc) ||
(desc->bDescriptorType != USB_DT_ENDPOINT)) {
dev_dbg(udc->dev, "bad ep or descriptor\n");
return -EINVAL;
}
maxpacket = usb_endpoint_maxp(desc);
if ((maxpacket == 0) || (maxpacket > ep->maxpacket)) {
dev_dbg(udc->dev, "bad ep descriptor's packet size\n");
return -EINVAL;
}
if (ep->hwep_num_base == 0) {
dev_dbg(udc->dev, "Can't re-enable EP0!!!\n");
return -EINVAL;
}
if ((!udc->driver) || (udc->gadget.speed == USB_SPEED_UNKNOWN)) {
dev_dbg(udc->dev, "bogus device state\n");
return -ESHUTDOWN;
}
tmp = desc->bmAttributes & USB_ENDPOINT_XFERTYPE_MASK;
switch (tmp) {
case USB_ENDPOINT_XFER_CONTROL:
return -EINVAL;
case USB_ENDPOINT_XFER_INT:
if (maxpacket > ep->maxpacket) {
dev_dbg(udc->dev,
"Bad INT endpoint maxpacket %d\n", maxpacket);
return -EINVAL;
}
break;
case USB_ENDPOINT_XFER_BULK:
switch (maxpacket) {
case 8:
case 16:
case 32:
case 64:
break;
default:
dev_dbg(udc->dev,
"Bad BULK endpoint maxpacket %d\n", maxpacket);
return -EINVAL;
}
break;
case USB_ENDPOINT_XFER_ISOC:
break;
}
spin_lock_irqsave(&udc->lock, flags);
ep->is_in = (desc->bEndpointAddress & USB_DIR_IN) != 0;
ep->ep.maxpacket = maxpacket;
if (ep->is_in)
ep->hwep_num = ep->hwep_num_base + EP_IN;
else
ep->hwep_num = ep->hwep_num_base;
ep_dbg(ep, "EP enabled: %s, HW:%d, MP:%d IN:%d\n", ep->ep.name,
ep->hwep_num, maxpacket, (ep->is_in == 1));
udc_realize_hwep(udc, ep->hwep_num, ep->ep.maxpacket);
udc_clr_buffer_hwep(udc, ep->hwep_num);
uda_disable_hwepint(udc, ep->hwep_num);
udc_clrstall_hwep(udc, ep->hwep_num);
udc_ep_dma_disable(udc, ep->hwep_num);
writel(1 << ep->hwep_num, USBD_EOTINTCLR(udc->udp_baseaddr));
writel(1 << ep->hwep_num, USBD_NDDRTINTCLR(udc->udp_baseaddr));
writel(1 << ep->hwep_num, USBD_SYSERRTINTCLR(udc->udp_baseaddr));
writel(1 << ep->hwep_num, USBD_DMARCLR(udc->udp_baseaddr));
spin_unlock_irqrestore(&udc->lock, flags);
atomic_inc(&udc->enabled_ep_cnt);
return 0;
}
static struct usb_request *lpc32xx_ep_alloc_request(struct usb_ep *_ep,
gfp_t gfp_flags)
{
struct lpc32xx_request *req;
req = kzalloc(sizeof(struct lpc32xx_request), gfp_flags);
if (!req)
return NULL;
INIT_LIST_HEAD(&req->queue);
return &req->req;
}
static void lpc32xx_ep_free_request(struct usb_ep *_ep,
struct usb_request *_req)
{
struct lpc32xx_request *req;
req = container_of(_req, struct lpc32xx_request, req);
BUG_ON(!list_empty(&req->queue));
kfree(req);
}
static int lpc32xx_ep_queue(struct usb_ep *_ep,
struct usb_request *_req, gfp_t gfp_flags)
{
struct lpc32xx_request *req;
struct lpc32xx_ep *ep;
struct lpc32xx_udc *udc;
unsigned long flags;
int status = 0;
req = container_of(_req, struct lpc32xx_request, req);
ep = container_of(_ep, struct lpc32xx_ep, ep);
if (!_req || !_req->complete || !_req->buf ||
!list_empty(&req->queue))
return -EINVAL;
udc = ep->udc;
if (!_ep) {
dev_dbg(udc->dev, "invalid ep\n");
return -EINVAL;
}
if ((!udc) || (!udc->driver) ||
(udc->gadget.speed == USB_SPEED_UNKNOWN)) {
dev_dbg(udc->dev, "invalid device\n");
return -EINVAL;
}
if (ep->lep) {
enum dma_data_direction direction;
struct lpc32xx_usbd_dd_gad *dd;
if (ep->is_in)
direction = DMA_TO_DEVICE;
else
direction = DMA_FROM_DEVICE;
if (req->req.dma == 0) {
req->req.dma = dma_map_single(
ep->udc->gadget.dev.parent,
req->req.buf, req->req.length, direction);
req->mapped = 1;
} else {
dma_sync_single_for_device(
ep->udc->gadget.dev.parent, req->req.dma,
req->req.length, direction);
req->mapped = 0;
}
dd = udc_dd_alloc(udc);
if (!dd) {
return -ENOMEM;
}
req->dd_desc_ptr = dd;
dd->dd_next_phy = dd->dd_next_v = 0;
dd->dd_buffer_addr = req->req.dma;
dd->dd_status = 0;
if (ep->eptype == EP_ISO_TYPE) {
dd->dd_setup = DD_SETUP_ISO_EP |
DD_SETUP_PACKETLEN(0) |
DD_SETUP_DMALENBYTES(1);
dd->dd_iso_ps_mem_addr = dd->this_dma + 24;
if (ep->is_in)
dd->iso_status[0] = req->req.length;
else
dd->iso_status[0] = 0;
} else
dd->dd_setup = DD_SETUP_PACKETLEN(ep->ep.maxpacket) |
DD_SETUP_DMALENBYTES(req->req.length);
}
ep_dbg(ep, "%s queue req %p len %d buf %p (in=%d) z=%d\n", _ep->name,
_req, _req->length, _req->buf, ep->is_in, _req->zero);
spin_lock_irqsave(&udc->lock, flags);
_req->status = -EINPROGRESS;
_req->actual = 0;
req->send_zlp = _req->zero;
if (list_empty(&ep->queue)) {
list_add_tail(&req->queue, &ep->queue);
if (ep->hwep_num_base == 0) {
if (ep->is_in) {
udc->ep0state = DATA_IN;
status = udc_ep0_in_req(udc);
} else {
udc->ep0state = DATA_OUT;
status = udc_ep0_out_req(udc);
}
} else if (ep->is_in) {
if (!ep->req_pending)
udc_ep_in_req_dma(udc, ep);
} else
if (!ep->req_pending)
udc_ep_out_req_dma(udc, ep);
} else
list_add_tail(&req->queue, &ep->queue);
spin_unlock_irqrestore(&udc->lock, flags);
return (status < 0) ? status : 0;
}
static int lpc32xx_ep_dequeue(struct usb_ep *_ep, struct usb_request *_req)
{
struct lpc32xx_ep *ep;
struct lpc32xx_request *req;
unsigned long flags;
ep = container_of(_ep, struct lpc32xx_ep, ep);
if (!_ep || ep->hwep_num_base == 0)
return -EINVAL;
spin_lock_irqsave(&ep->udc->lock, flags);
list_for_each_entry(req, &ep->queue, queue) {
if (&req->req == _req)
break;
}
if (&req->req != _req) {
spin_unlock_irqrestore(&ep->udc->lock, flags);
return -EINVAL;
}
done(ep, req, -ECONNRESET);
spin_unlock_irqrestore(&ep->udc->lock, flags);
return 0;
}
static int lpc32xx_ep_set_halt(struct usb_ep *_ep, int value)
{
struct lpc32xx_ep *ep = container_of(_ep, struct lpc32xx_ep, ep);
struct lpc32xx_udc *udc = ep->udc;
unsigned long flags;
if ((!ep) || (ep->hwep_num <= 1))
return -EINVAL;
if (ep->is_in)
return -EAGAIN;
spin_lock_irqsave(&udc->lock, flags);
if (value == 1) {
udc_protocol_cmd_data_w(udc, CMD_SET_EP_STAT(ep->hwep_num),
DAT_WR_BYTE(EP_STAT_ST));
} else {
ep->wedge = 0;
udc_protocol_cmd_data_w(udc, CMD_SET_EP_STAT(ep->hwep_num),
DAT_WR_BYTE(0));
}
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int lpc32xx_ep_set_wedge(struct usb_ep *_ep)
{
struct lpc32xx_ep *ep = container_of(_ep, struct lpc32xx_ep, ep);
if (!_ep || !ep->udc)
return -EINVAL;
ep->wedge = 1;
return usb_ep_set_halt(_ep);
}
void udc_send_in_zlp(struct lpc32xx_udc *udc, struct lpc32xx_ep *ep)
{
udc_clearep_getsts(udc, ep->hwep_num);
udc_write_hwep(udc, ep->hwep_num, NULL, 0);
}
void udc_handle_eps(struct lpc32xx_udc *udc, struct lpc32xx_ep *ep)
{
u32 epstatus;
struct lpc32xx_request *req;
if (ep->hwep_num <= 0)
return;
uda_clear_hwepint(udc, ep->hwep_num);
if (!(udc->enabled_hwepints & (1 << ep->hwep_num)))
return;
epstatus = udc_clearep_getsts(udc, ep->hwep_num);
if (epstatus & EP_SEL_F)
return;
if (ep->is_in) {
udc_send_in_zlp(udc, ep);
uda_disable_hwepint(udc, ep->hwep_num);
} else
return;
req = list_entry(ep->queue.next, struct lpc32xx_request, queue);
if (req) {
done(ep, req, 0);
if (!list_empty(&ep->queue)) {
if (ep->is_in)
udc_ep_in_req_dma(udc, ep);
else
udc_ep_out_req_dma(udc, ep);
} else
ep->req_pending = 0;
}
}
static void udc_handle_dma_ep(struct lpc32xx_udc *udc, struct lpc32xx_ep *ep)
{
u32 status, epstatus;
struct lpc32xx_request *req;
struct lpc32xx_usbd_dd_gad *dd;
#ifdef CONFIG_USB_GADGET_DEBUG_FILES
ep->totalints++;
#endif
req = list_entry(ep->queue.next, struct lpc32xx_request, queue);
if (!req) {
ep_err(ep, "DMA interrupt on no req!\n");
return;
}
dd = req->dd_desc_ptr;
if (!(dd->dd_status & DD_STATUS_DD_RETIRED))
ep_warn(ep, "DMA descriptor did not retire\n");
udc_ep_dma_disable(udc, ep->hwep_num);
writel((1 << ep->hwep_num), USBD_EOTINTCLR(udc->udp_baseaddr));
writel((1 << ep->hwep_num), USBD_NDDRTINTCLR(udc->udp_baseaddr));
if (readl(USBD_SYSERRTINTST(udc->udp_baseaddr)) &
(1 << ep->hwep_num)) {
writel((1 << ep->hwep_num),
USBD_SYSERRTINTCLR(udc->udp_baseaddr));
ep_err(ep, "AHB critical error!\n");
ep->req_pending = 0;
done(ep, req, -ECONNABORTED);
return;
}
status = dd->dd_status;
switch (status & DD_STATUS_STS_MASK) {
case DD_STATUS_STS_NS:
ep->req_pending = 0;
ep_err(ep, "DMA critical EP error: DD not serviced (0x%x)!\n",
status);
done(ep, req, -ECONNABORTED);
return;
case DD_STATUS_STS_BS:
ep->req_pending = 0;
ep_err(ep, "DMA critical EP error: EOT prior to service completion (0x%x)!\n",
status);
done(ep, req, -ECONNABORTED);
return;
case DD_STATUS_STS_NC:
case DD_STATUS_STS_DUR:
break;
default:
ep->req_pending = 0;
ep_err(ep, "DMA critical EP error: System error (0x%x)!\n",
status);
done(ep, req, -ECONNABORTED);
return;
}
if (ep->eptype == EP_ISO_TYPE) {
if (ep->is_in)
req->req.actual = req->req.length;
else
req->req.actual = dd->iso_status[0] & 0xFFFF;
} else
req->req.actual += DD_STATUS_CURDMACNT(status);
if (req->send_zlp) {
if (udc_clearep_getsts(udc, ep->hwep_num) & EP_SEL_F) {
udc_clearep_getsts(udc, ep->hwep_num);
uda_enable_hwepint(udc, ep->hwep_num);
epstatus = udc_clearep_getsts(udc, ep->hwep_num);
return;
} else
udc_send_in_zlp(udc, ep);
}
done(ep, req, 0);
udc_clearep_getsts(udc, ep->hwep_num);
if (!list_empty((&ep->queue))) {
if (ep->is_in)
udc_ep_in_req_dma(udc, ep);
else
udc_ep_out_req_dma(udc, ep);
} else
ep->req_pending = 0;
}
static void udc_handle_dev(struct lpc32xx_udc *udc)
{
u32 tmp;
udc_protocol_cmd_w(udc, CMD_GET_DEV_STAT);
tmp = udc_protocol_cmd_r(udc, DAT_GET_DEV_STAT);
if (tmp & DEV_RST)
uda_usb_reset(udc);
else if (tmp & DEV_CON_CH)
uda_power_event(udc, (tmp & DEV_CON));
else if (tmp & DEV_SUS_CH) {
if (tmp & DEV_SUS) {
if (udc->vbus == 0)
stop_activity(udc);
else if ((udc->gadget.speed != USB_SPEED_UNKNOWN) &&
udc->driver) {
udc->poweron = 0;
schedule_work(&udc->pullup_job);
uda_resm_susp_event(udc, 1);
}
} else if ((udc->gadget.speed != USB_SPEED_UNKNOWN) &&
udc->driver && udc->vbus) {
uda_resm_susp_event(udc, 0);
udc->poweron = 1;
schedule_work(&udc->pullup_job);
}
}
}
static int udc_get_status(struct lpc32xx_udc *udc, u16 reqtype, u16 wIndex)
{
struct lpc32xx_ep *ep;
u32 ep0buff = 0, tmp;
switch (reqtype & USB_RECIP_MASK) {
case USB_RECIP_INTERFACE:
break;
case USB_RECIP_DEVICE:
ep0buff = (udc->selfpowered << USB_DEVICE_SELF_POWERED);
if (udc->dev_status & (1 << USB_DEVICE_REMOTE_WAKEUP))
ep0buff |= (1 << USB_DEVICE_REMOTE_WAKEUP);
break;
case USB_RECIP_ENDPOINT:
tmp = wIndex & USB_ENDPOINT_NUMBER_MASK;
ep = &udc->ep[tmp];
if ((tmp == 0) || (tmp >= NUM_ENDPOINTS))
return -EOPNOTSUPP;
if (wIndex & USB_DIR_IN) {
if (!ep->is_in)
return -EOPNOTSUPP;
} else if (ep->is_in)
return -EOPNOTSUPP;
udc_protocol_cmd_w(udc, CMD_SEL_EP(ep->hwep_num));
tmp = udc_protocol_cmd_r(udc, DAT_SEL_EP(ep->hwep_num));
if (tmp & EP_SEL_ST)
ep0buff = (1 << USB_ENDPOINT_HALT);
else
ep0buff = 0;
break;
default:
break;
}
udc_write_hwep(udc, EP_IN, &ep0buff, 2);
return 0;
}
static void udc_handle_ep0_setup(struct lpc32xx_udc *udc)
{
struct lpc32xx_ep *ep, *ep0 = &udc->ep[0];
struct usb_ctrlrequest ctrlpkt;
int i, bytes;
u16 wIndex, wValue, wLength, reqtype, req, tmp;
nuke(ep0, -EPROTO);
bytes = udc_read_hwep(udc, EP_OUT, (u32 *) &ctrlpkt, 8);
if (bytes != 8) {
ep_warn(ep0, "Incorrectly sized setup packet (s/b 8, is %d)!\n",
bytes);
return;
}
wIndex = le16_to_cpu(ctrlpkt.wIndex);
wValue = le16_to_cpu(ctrlpkt.wValue);
wLength = le16_to_cpu(ctrlpkt.wLength);
reqtype = le16_to_cpu(ctrlpkt.bRequestType);
if (likely(reqtype & USB_DIR_IN))
ep0->is_in = 1;
else
ep0->is_in = 0;
req = le16_to_cpu(ctrlpkt.bRequest);
switch (req) {
case USB_REQ_CLEAR_FEATURE:
case USB_REQ_SET_FEATURE:
switch (reqtype) {
case (USB_TYPE_STANDARD | USB_RECIP_DEVICE):
if (wValue != USB_DEVICE_REMOTE_WAKEUP)
goto stall;
if (req == USB_REQ_CLEAR_FEATURE)
udc->dev_status &=
~(1 << USB_DEVICE_REMOTE_WAKEUP);
else
udc->dev_status |=
(1 << USB_DEVICE_REMOTE_WAKEUP);
uda_remwkp_cgh(udc);
goto zlp_send;
case (USB_TYPE_STANDARD | USB_RECIP_ENDPOINT):
tmp = wIndex & USB_ENDPOINT_NUMBER_MASK;
if ((wValue != USB_ENDPOINT_HALT) ||
(tmp >= NUM_ENDPOINTS))
break;
ep = &udc->ep[tmp];
tmp = ep->hwep_num;
if (tmp == 0)
break;
if (req == USB_REQ_SET_FEATURE)
udc_stall_hwep(udc, tmp);
else if (!ep->wedge)
udc_clrstall_hwep(udc, tmp);
goto zlp_send;
default:
break;
}
case USB_REQ_SET_ADDRESS:
if (reqtype == (USB_TYPE_STANDARD | USB_RECIP_DEVICE)) {
udc_set_address(udc, wValue);
goto zlp_send;
}
break;
case USB_REQ_GET_STATUS:
udc_get_status(udc, reqtype, wIndex);
return;
default:
break;
}
if (likely(udc->driver)) {
spin_unlock(&udc->lock);
i = udc->driver->setup(&udc->gadget, &ctrlpkt);
spin_lock(&udc->lock);
if (req == USB_REQ_SET_CONFIGURATION) {
if (wValue) {
udc_set_device_configured(udc);
udc_protocol_cmd_data_w(udc, CMD_SET_MODE,
DAT_WR_BYTE(AP_CLK |
INAK_BI | INAK_II));
} else {
udc_set_device_unconfigured(udc);
udc_protocol_cmd_data_w(udc, CMD_SET_MODE,
DAT_WR_BYTE(AP_CLK));
}
}
if (i < 0) {
dev_dbg(udc->dev,
"req %02x.%02x protocol STALL; stat %d\n",
reqtype, req, i);
udc->ep0state = WAIT_FOR_SETUP;
goto stall;
}
}
if (!ep0->is_in)
udc_ep0_send_zlp(udc);
return;
stall:
udc_stall_hwep(udc, EP_IN);
return;
zlp_send:
udc_ep0_send_zlp(udc);
return;
}
static void udc_handle_ep0_in(struct lpc32xx_udc *udc)
{
struct lpc32xx_ep *ep0 = &udc->ep[0];
u32 epstatus;
epstatus = udc_clearep_getsts(udc, EP_IN);
#ifdef CONFIG_USB_GADGET_DEBUG_FILES
ep0->totalints++;
#endif
if (epstatus & EP_SEL_ST) {
udc_clrstall_hwep(udc, EP_IN);
nuke(ep0, -ECONNABORTED);
udc->ep0state = WAIT_FOR_SETUP;
return;
}
if (!(epstatus & EP_SEL_F)) {
if (udc->ep0state == DATA_IN)
udc_ep0_in_req(udc);
else {
nuke(ep0, -ECONNABORTED);
udc->ep0state = WAIT_FOR_SETUP;
}
}
}
static void udc_handle_ep0_out(struct lpc32xx_udc *udc)
{
struct lpc32xx_ep *ep0 = &udc->ep[0];
u32 epstatus;
epstatus = udc_clearep_getsts(udc, EP_OUT);
#ifdef CONFIG_USB_GADGET_DEBUG_FILES
ep0->totalints++;
#endif
if (epstatus & EP_SEL_ST) {
udc_clrstall_hwep(udc, EP_OUT);
nuke(ep0, -ECONNABORTED);
udc->ep0state = WAIT_FOR_SETUP;
return;
}
if (epstatus & EP_SEL_EPN)
return;
if (epstatus & EP_SEL_STP) {
nuke(ep0, 0);
udc->ep0state = WAIT_FOR_SETUP;
}
if (epstatus & EP_SEL_F)
switch (udc->ep0state) {
case WAIT_FOR_SETUP:
udc_handle_ep0_setup(udc);
break;
case DATA_OUT:
udc_ep0_out_req(udc);
break;
default:
nuke(ep0, -ECONNABORTED);
udc->ep0state = WAIT_FOR_SETUP;
}
}
static int lpc32xx_get_frame(struct usb_gadget *gadget)
{
int frame;
unsigned long flags;
struct lpc32xx_udc *udc = to_udc(gadget);
if (!udc->clocked)
return -EINVAL;
spin_lock_irqsave(&udc->lock, flags);
frame = (int) udc_get_current_frame(udc);
spin_unlock_irqrestore(&udc->lock, flags);
return frame;
}
static int lpc32xx_wakeup(struct usb_gadget *gadget)
{
return -ENOTSUPP;
}
static int lpc32xx_set_selfpowered(struct usb_gadget *gadget, int is_on)
{
struct lpc32xx_udc *udc = to_udc(gadget);
udc->selfpowered = (is_on != 0);
return 0;
}
static int lpc32xx_vbus_session(struct usb_gadget *gadget, int is_active)
{
unsigned long flags;
struct lpc32xx_udc *udc = to_udc(gadget);
spin_lock_irqsave(&udc->lock, flags);
if (udc->driver) {
udc_clk_set(udc, 1);
udc_enable(udc);
pullup(udc, is_active);
} else {
stop_activity(udc);
pullup(udc, 0);
spin_unlock_irqrestore(&udc->lock, flags);
if (atomic_read(&udc->enabled_ep_cnt))
wait_event_interruptible(udc->ep_disable_wait_queue,
(atomic_read(&udc->enabled_ep_cnt) == 0));
spin_lock_irqsave(&udc->lock, flags);
udc_clk_set(udc, 0);
}
spin_unlock_irqrestore(&udc->lock, flags);
return 0;
}
static int lpc32xx_pullup(struct usb_gadget *gadget, int is_on)
{
struct lpc32xx_udc *udc = to_udc(gadget);
pullup(udc, is_on);
return 0;
}
static void nop_release(struct device *dev)
{
}
static irqreturn_t lpc32xx_usb_lp_irq(int irq, void *_udc)
{
u32 tmp, devstat;
struct lpc32xx_udc *udc = _udc;
spin_lock(&udc->lock);
devstat = readl(USBD_DEVINTST(udc->udp_baseaddr));
devstat &= ~USBD_EP_FAST;
writel(devstat, USBD_DEVINTCLR(udc->udp_baseaddr));
devstat = devstat & udc->enabled_devints;
if (devstat & USBD_DEV_STAT)
udc_handle_dev(udc);
if (devstat & ERR_INT) {
udc_protocol_cmd_w(udc, CMD_RD_ERR_STAT);
tmp = udc_protocol_cmd_r(udc, DAT_RD_ERR_STAT);
dev_dbg(udc->dev, "Device error (0x%x)!\n", tmp);
}
spin_unlock(&udc->lock);
return IRQ_HANDLED;
}
static irqreturn_t lpc32xx_usb_hp_irq(int irq, void *_udc)
{
u32 tmp;
struct lpc32xx_udc *udc = _udc;
spin_lock(&udc->lock);
writel(USBD_EP_FAST, USBD_DEVINTCLR(udc->udp_baseaddr));
tmp = readl(USBD_EPINTST(udc->udp_baseaddr));
if (tmp & (EP_MASK_SEL(0, EP_OUT) | EP_MASK_SEL(0, EP_IN))) {
if (tmp & (EP_MASK_SEL(0, EP_IN)))
udc_handle_ep0_in(udc);
if (tmp & (EP_MASK_SEL(0, EP_OUT)))
udc_handle_ep0_out(udc);
}
if (tmp & ~(EP_MASK_SEL(0, EP_OUT) | EP_MASK_SEL(0, EP_IN))) {
int i;
for (i = 1; i < NUM_ENDPOINTS; i++) {
if (tmp & (1 << udc->ep[i].hwep_num))
udc_handle_eps(udc, &udc->ep[i]);
}
}
spin_unlock(&udc->lock);
return IRQ_HANDLED;
}
static irqreturn_t lpc32xx_usb_devdma_irq(int irq, void *_udc)
{
struct lpc32xx_udc *udc = _udc;
int i;
u32 tmp;
spin_lock(&udc->lock);
tmp = readl(USBD_EOTINTST(udc->udp_baseaddr)) |
(readl(USBD_EPDMAST(udc->udp_baseaddr)) &
readl(USBD_NDDRTINTST(udc->udp_baseaddr))) |
readl(USBD_SYSERRTINTST(udc->udp_baseaddr));
for (i = 1; i < NUM_ENDPOINTS; i++) {
if (tmp & (1 << udc->ep[i].hwep_num))
udc_handle_dma_ep(udc, &udc->ep[i]);
}
spin_unlock(&udc->lock);
return IRQ_HANDLED;
}
static void vbus_work(struct work_struct *work)
{
u8 value;
struct lpc32xx_udc *udc = container_of(work, struct lpc32xx_udc,
vbus_job);
if (udc->enabled != 0) {
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1, OTG1_VBUS_DISCHRG);
msleep(100);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_OTG_CONTROL_1 | ISP1301_I2C_REG_CLEAR_ADDR,
OTG1_VBUS_DISCHRG);
i2c_smbus_write_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_LATCH |
ISP1301_I2C_REG_CLEAR_ADDR, ~0);
value = i2c_smbus_read_byte_data(udc->isp1301_i2c_client,
ISP1301_I2C_INTERRUPT_SOURCE);
if (value & INT_SESS_VLD)
udc->vbus = 1;
else
udc->vbus = 0;
if (udc->last_vbus != udc->vbus) {
udc->last_vbus = udc->vbus;
lpc32xx_vbus_session(&udc->gadget, udc->vbus);
}
}
enable_irq(udc->udp_irq[IRQ_USB_ATX]);
}
static irqreturn_t lpc32xx_usb_vbus_irq(int irq, void *_udc)
{
struct lpc32xx_udc *udc = _udc;
disable_irq_nosync(udc->udp_irq[IRQ_USB_ATX]);
schedule_work(&udc->vbus_job);
return IRQ_HANDLED;
}
static int lpc32xx_start(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
struct lpc32xx_udc *udc = to_udc(gadget);
int i;
if (!driver || driver->max_speed < USB_SPEED_FULL || !driver->setup) {
dev_err(udc->dev, "bad parameter.\n");
return -EINVAL;
}
if (udc->driver) {
dev_err(udc->dev, "UDC already has a gadget driver\n");
return -EBUSY;
}
udc->driver = driver;
udc->gadget.dev.driver = &driver->driver;
udc->gadget.dev.of_node = udc->dev->of_node;
udc->enabled = 1;
udc->selfpowered = 1;
udc->vbus = 0;
udc->last_vbus = udc->vbus = 0;
schedule_work(&udc->vbus_job);
for (i = IRQ_USB_LP; i < IRQ_USB_ATX; i++)
enable_irq(udc->udp_irq[i]);
return 0;
}
static int lpc32xx_stop(struct usb_gadget *gadget,
struct usb_gadget_driver *driver)
{
int i;
struct lpc32xx_udc *udc = to_udc(gadget);
if (!driver || driver != udc->driver)
return -EINVAL;
for (i = IRQ_USB_LP; i <= IRQ_USB_ATX; i++)
disable_irq(udc->udp_irq[i]);
if (udc->clocked) {
spin_lock(&udc->lock);
stop_activity(udc);
spin_unlock(&udc->lock);
if (atomic_read(&udc->enabled_ep_cnt))
wait_event_interruptible(udc->ep_disable_wait_queue,
(atomic_read(&udc->enabled_ep_cnt) == 0));
spin_lock(&udc->lock);
udc_clk_set(udc, 0);
spin_unlock(&udc->lock);
}
udc->enabled = 0;
udc->gadget.dev.driver = NULL;
udc->driver = NULL;
return 0;
}
static void lpc32xx_udc_shutdown(struct platform_device *dev)
{
struct lpc32xx_udc *udc = platform_get_drvdata(dev);
pullup(udc, 0);
}
static void lpc32xx_usbd_conn_chg(int conn)
{
}
static void lpc32xx_usbd_susp_chg(int susp)
{
}
static void lpc32xx_rmwkup_chg(int remote_wakup_enable)
{
}
static int __init lpc32xx_udc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct lpc32xx_udc *udc;
int retval, i;
struct resource *res;
dma_addr_t dma_handle;
struct device_node *isp1301_node;
udc = kzalloc(sizeof(*udc), GFP_KERNEL);
if (!udc)
return -ENOMEM;
memcpy(udc, &controller_template, sizeof(*udc));
for (i = 0; i <= 15; i++)
udc->ep[i].udc = udc;
udc->gadget.ep0 = &udc->ep[0].ep;
udc->gadget.dev.parent = dev;
udc->pdev = pdev;
udc->dev = &pdev->dev;
udc->enabled = 0;
if (pdev->dev.of_node) {
isp1301_node = of_parse_phandle(pdev->dev.of_node,
"transceiver", 0);
} else {
isp1301_node = NULL;
}
udc->isp1301_i2c_client = isp1301_get_client(isp1301_node);
if (!udc->isp1301_i2c_client) {
retval = -EPROBE_DEFER;
goto phy_fail;
}
dev_info(udc->dev, "ISP1301 I2C device at address 0x%x\n",
udc->isp1301_i2c_client->addr);
pdev->dev.dma_mask = &lpc32xx_usbd_dmamask;
pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
udc->board = &lpc32xx_usbddata;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
retval = -ENXIO;
goto resource_fail;
}
spin_lock_init(&udc->lock);
for (i = 0; i < 4; i++) {
udc->udp_irq[i] = platform_get_irq(pdev, i);
if (udc->udp_irq[i] < 0) {
dev_err(udc->dev,
"irq resource %d not available!\n", i);
retval = udc->udp_irq[i];
goto irq_fail;
}
}
udc->io_p_start = res->start;
udc->io_p_size = resource_size(res);
if (!request_mem_region(udc->io_p_start, udc->io_p_size, driver_name)) {
dev_err(udc->dev, "someone's using UDC memory\n");
retval = -EBUSY;
goto request_mem_region_fail;
}
udc->udp_baseaddr = ioremap(udc->io_p_start, udc->io_p_size);
if (!udc->udp_baseaddr) {
retval = -ENOMEM;
dev_err(udc->dev, "IO map failure\n");
goto io_map_fail;
}
writel(USB_SLAVE_HCLK_EN | (1 << 19), USB_CTRL);
udc->usb_pll_clk = clk_get(&pdev->dev, "ck_pll5");
if (IS_ERR(udc->usb_pll_clk)) {
dev_err(udc->dev, "failed to acquire USB PLL\n");
retval = PTR_ERR(udc->usb_pll_clk);
goto pll_get_fail;
}
udc->usb_slv_clk = clk_get(&pdev->dev, "ck_usbd");
if (IS_ERR(udc->usb_slv_clk)) {
dev_err(udc->dev, "failed to acquire USB device clock\n");
retval = PTR_ERR(udc->usb_slv_clk);
goto usb_clk_get_fail;
}
udc->usb_otg_clk = clk_get(&pdev->dev, "ck_usb_otg");
if (IS_ERR(udc->usb_otg_clk)) {
dev_err(udc->dev, "failed to acquire USB otg clock\n");
retval = PTR_ERR(udc->usb_otg_clk);
goto usb_otg_clk_get_fail;
}
retval = clk_enable(udc->usb_pll_clk);
if (retval < 0) {
dev_err(udc->dev, "failed to start USB PLL\n");
goto pll_enable_fail;
}
retval = clk_set_rate(udc->usb_pll_clk, 48000);
if (retval < 0) {
dev_err(udc->dev, "failed to set USB clock rate\n");
goto pll_set_fail;
}
writel(readl(USB_CTRL) | USB_DEV_NEED_CLK_EN, USB_CTRL);
retval = clk_enable(udc->usb_slv_clk);
if (retval < 0) {
dev_err(udc->dev, "failed to start USB device clock\n");
goto usb_clk_enable_fail;
}
retval = clk_enable(udc->usb_otg_clk);
if (retval < 0) {
dev_err(udc->dev, "failed to start USB otg clock\n");
goto usb_otg_clk_enable_fail;
}
udc->poweron = udc->pullup = 0;
INIT_WORK(&udc->pullup_job, pullup_work);
INIT_WORK(&udc->vbus_job, vbus_work);
#ifdef CONFIG_PM
INIT_WORK(&udc->power_job, power_work);
#endif
udc->clocked = 1;
isp1301_udc_configure(udc);
udc->udca_v_base = dma_alloc_coherent(&pdev->dev, UDCA_BUFF_SIZE,
&dma_handle,
(GFP_KERNEL | GFP_DMA));
if (!udc->udca_v_base) {
dev_err(udc->dev, "error getting UDCA region\n");
retval = -ENOMEM;
goto i2c_fail;
}
udc->udca_p_base = dma_handle;
dev_dbg(udc->dev, "DMA buffer(0x%x bytes), P:0x%08x, V:0x%p\n",
UDCA_BUFF_SIZE, udc->udca_p_base, udc->udca_v_base);
udc->dd_cache = dma_pool_create("udc_dd", udc->dev,
sizeof(struct lpc32xx_usbd_dd_gad),
sizeof(u32), 0);
if (!udc->dd_cache) {
dev_err(udc->dev, "error getting DD DMA region\n");
retval = -ENOMEM;
goto dma_alloc_fail;
}
udc_disable(udc);
udc_reinit(udc);
retval = device_register(&udc->gadget.dev);
if (retval < 0) {
dev_err(udc->dev, "Device registration failure\n");
goto dev_register_fail;
}
retval = request_irq(udc->udp_irq[IRQ_USB_LP], lpc32xx_usb_lp_irq,
0, "udc_lp", udc);
if (retval < 0) {
dev_err(udc->dev, "LP request irq %d failed\n",
udc->udp_irq[IRQ_USB_LP]);
goto irq_lp_fail;
}
retval = request_irq(udc->udp_irq[IRQ_USB_HP], lpc32xx_usb_hp_irq,
0, "udc_hp", udc);
if (retval < 0) {
dev_err(udc->dev, "HP request irq %d failed\n",
udc->udp_irq[IRQ_USB_HP]);
goto irq_hp_fail;
}
retval = request_irq(udc->udp_irq[IRQ_USB_DEVDMA],
lpc32xx_usb_devdma_irq, 0, "udc_dma", udc);
if (retval < 0) {
dev_err(udc->dev, "DEV request irq %d failed\n",
udc->udp_irq[IRQ_USB_DEVDMA]);
goto irq_dev_fail;
}
retval = request_irq(udc->udp_irq[IRQ_USB_ATX], lpc32xx_usb_vbus_irq,
0, "udc_otg", udc);
if (retval < 0) {
dev_err(udc->dev, "VBUS request irq %d failed\n",
udc->udp_irq[IRQ_USB_ATX]);
goto irq_xcvr_fail;
}
init_waitqueue_head(&udc->ep_disable_wait_queue);
atomic_set(&udc->enabled_ep_cnt, 0);
for (i = IRQ_USB_LP; i <= IRQ_USB_ATX; i++)
disable_irq(udc->udp_irq[i]);
retval = usb_add_gadget_udc(dev, &udc->gadget);
if (retval < 0)
goto add_gadget_fail;
dev_set_drvdata(dev, udc);
device_init_wakeup(dev, 1);
create_debug_file(udc);
udc_clk_set(udc, 0);
dev_info(udc->dev, "%s version %s\n", driver_name, DRIVER_VERSION);
return 0;
add_gadget_fail:
free_irq(udc->udp_irq[IRQ_USB_ATX], udc);
irq_xcvr_fail:
free_irq(udc->udp_irq[IRQ_USB_DEVDMA], udc);
irq_dev_fail:
free_irq(udc->udp_irq[IRQ_USB_HP], udc);
irq_hp_fail:
free_irq(udc->udp_irq[IRQ_USB_LP], udc);
irq_lp_fail:
device_unregister(&udc->gadget.dev);
dev_register_fail:
dma_pool_destroy(udc->dd_cache);
dma_alloc_fail:
dma_free_coherent(&pdev->dev, UDCA_BUFF_SIZE,
udc->udca_v_base, udc->udca_p_base);
i2c_fail:
clk_disable(udc->usb_otg_clk);
usb_otg_clk_enable_fail:
clk_disable(udc->usb_slv_clk);
usb_clk_enable_fail:
pll_set_fail:
clk_disable(udc->usb_pll_clk);
pll_enable_fail:
clk_put(udc->usb_slv_clk);
usb_otg_clk_get_fail:
clk_put(udc->usb_otg_clk);
usb_clk_get_fail:
clk_put(udc->usb_pll_clk);
pll_get_fail:
iounmap(udc->udp_baseaddr);
io_map_fail:
release_mem_region(udc->io_p_start, udc->io_p_size);
dev_err(udc->dev, "%s probe failed, %d\n", driver_name, retval);
request_mem_region_fail:
irq_fail:
resource_fail:
phy_fail:
kfree(udc);
return retval;
}
static int lpc32xx_udc_remove(struct platform_device *pdev)
{
struct lpc32xx_udc *udc = platform_get_drvdata(pdev);
usb_del_gadget_udc(&udc->gadget);
if (udc->driver)
return -EBUSY;
udc_clk_set(udc, 1);
udc_disable(udc);
pullup(udc, 0);
free_irq(udc->udp_irq[IRQ_USB_ATX], udc);
device_init_wakeup(&pdev->dev, 0);
remove_debug_file(udc);
dma_pool_destroy(udc->dd_cache);
dma_free_coherent(&pdev->dev, UDCA_BUFF_SIZE,
udc->udca_v_base, udc->udca_p_base);
free_irq(udc->udp_irq[IRQ_USB_DEVDMA], udc);
free_irq(udc->udp_irq[IRQ_USB_HP], udc);
free_irq(udc->udp_irq[IRQ_USB_LP], udc);
device_unregister(&udc->gadget.dev);
clk_disable(udc->usb_otg_clk);
clk_put(udc->usb_otg_clk);
clk_disable(udc->usb_slv_clk);
clk_put(udc->usb_slv_clk);
clk_disable(udc->usb_pll_clk);
clk_put(udc->usb_pll_clk);
iounmap(udc->udp_baseaddr);
release_mem_region(udc->io_p_start, udc->io_p_size);
kfree(udc);
return 0;
}
static int lpc32xx_udc_suspend(struct platform_device *pdev, pm_message_t mesg)
{
struct lpc32xx_udc *udc = platform_get_drvdata(pdev);
if (udc->clocked) {
udc->poweron = 0;
isp1301_set_powerstate(udc, 0);
udc_clk_set(udc, 0);
udc->clocked = 1;
clk_disable(udc->usb_slv_clk);
}
return 0;
}
static int lpc32xx_udc_resume(struct platform_device *pdev)
{
struct lpc32xx_udc *udc = platform_get_drvdata(pdev);
if (udc->clocked) {
clk_enable(udc->usb_slv_clk);
udc_clk_set(udc, 1);
udc->poweron = 1;
isp1301_set_powerstate(udc, 1);
}
return 0;
}
static int __init udc_init_module(void)
{
return platform_driver_probe(&lpc32xx_udc_driver, lpc32xx_udc_probe);
}
static void __exit udc_exit_module(void)
{
platform_driver_unregister(&lpc32xx_udc_driver);
}
