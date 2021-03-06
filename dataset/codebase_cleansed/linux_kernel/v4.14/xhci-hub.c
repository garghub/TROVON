static int xhci_create_usb3_bos_desc(struct xhci_hcd *xhci, char *buf,
u16 wLength)
{
int i, ssa_count;
u32 temp;
u16 desc_size, ssp_cap_size, ssa_size = 0;
bool usb3_1 = false;
desc_size = USB_DT_BOS_SIZE + USB_DT_USB_SS_CAP_SIZE;
ssp_cap_size = sizeof(usb_bos_descriptor) - desc_size;
if (xhci->usb3_rhub.min_rev >= 0x01) {
if (xhci->usb3_rhub.psi_count) {
ssa_count = xhci->usb3_rhub.psi_uid_count * 2;
ssa_size = ssa_count * sizeof(u32);
ssp_cap_size -= 16;
}
desc_size += ssp_cap_size;
usb3_1 = true;
}
memcpy(buf, &usb_bos_descriptor, min(desc_size, wLength));
if (usb3_1) {
buf[4] += 1;
put_unaligned_le16(desc_size + ssa_size, &buf[2]);
}
if (wLength < USB_DT_BOS_SIZE + USB_DT_USB_SS_CAP_SIZE)
return wLength;
temp = readl(&xhci->cap_regs->hcc_params);
if (HCC_LTC(temp))
buf[8] |= USB_LTM_SUPPORT;
if ((xhci->quirks & XHCI_LPM_SUPPORT)) {
temp = readl(&xhci->cap_regs->hcs_params3);
buf[12] = HCS_U1_LATENCY(temp);
put_unaligned_le16(HCS_U2_LATENCY(temp), &buf[13]);
}
if (usb3_1 && xhci->usb3_rhub.psi_count) {
u32 ssp_cap_base, bm_attrib, psi, psi_mant, psi_exp;
int offset;
ssp_cap_base = USB_DT_BOS_SIZE + USB_DT_USB_SS_CAP_SIZE;
if (wLength < desc_size)
return wLength;
buf[ssp_cap_base] = ssp_cap_size + ssa_size;
bm_attrib = (ssa_count - 1) & 0x1f;
bm_attrib |= (xhci->usb3_rhub.psi_uid_count - 1) << 5;
put_unaligned_le32(bm_attrib, &buf[ssp_cap_base + 4]);
if (wLength < desc_size + ssa_size)
return wLength;
offset = desc_size;
for (i = 0; i < xhci->usb3_rhub.psi_count; i++) {
psi = xhci->usb3_rhub.psi[i];
psi &= ~USB_SSP_SUBLINK_SPEED_RSVD;
psi_exp = XHCI_EXT_PORT_PSIE(psi);
psi_mant = XHCI_EXT_PORT_PSIM(psi);
for (; psi_exp < 3; psi_exp++)
psi_mant /= 1000;
if (psi_mant >= 10)
psi |= BIT(14);
if ((psi & PLT_MASK) == PLT_SYM) {
put_unaligned_le32(psi, &buf[offset]);
psi |= 1 << 7;
offset += 4;
if (offset >= desc_size + ssa_size)
return desc_size + ssa_size;
} else if ((psi & PLT_MASK) == PLT_ASYM_RX) {
psi ^= PLT_MASK;
}
put_unaligned_le32(psi, &buf[offset]);
offset += 4;
if (offset >= desc_size + ssa_size)
return desc_size + ssa_size;
}
}
return desc_size + ssa_size;
}
static void xhci_common_hub_descriptor(struct xhci_hcd *xhci,
struct usb_hub_descriptor *desc, int ports)
{
u16 temp;
desc->bPwrOn2PwrGood = 10;
desc->bHubContrCurrent = 0;
desc->bNbrPorts = ports;
temp = 0;
if (HCC_PPC(xhci->hcc_params))
temp |= HUB_CHAR_INDV_PORT_LPSM;
else
temp |= HUB_CHAR_NO_LPSM;
temp |= HUB_CHAR_INDV_PORT_OCPM;
desc->wHubCharacteristics = cpu_to_le16(temp);
}
static void xhci_usb2_hub_descriptor(struct usb_hcd *hcd, struct xhci_hcd *xhci,
struct usb_hub_descriptor *desc)
{
int ports;
u16 temp;
__u8 port_removable[(USB_MAXCHILDREN + 1 + 7) / 8];
u32 portsc;
unsigned int i;
ports = xhci->num_usb2_ports;
xhci_common_hub_descriptor(xhci, desc, ports);
desc->bDescriptorType = USB_DT_HUB;
temp = 1 + (ports / 8);
desc->bDescLength = USB_DT_HUB_NONVAR_SIZE + 2 * temp;
memset(port_removable, 0, sizeof(port_removable));
for (i = 0; i < ports; i++) {
portsc = readl(xhci->usb2_ports[i]);
if (portsc & PORT_DEV_REMOVE)
port_removable[(i + 1) / 8] |= 1 << ((i + 1) % 8);
}
memset(desc->u.hs.DeviceRemovable, 0xff,
sizeof(desc->u.hs.DeviceRemovable));
memset(desc->u.hs.PortPwrCtrlMask, 0xff,
sizeof(desc->u.hs.PortPwrCtrlMask));
for (i = 0; i < (ports + 1 + 7) / 8; i++)
memset(&desc->u.hs.DeviceRemovable[i], port_removable[i],
sizeof(__u8));
}
static void xhci_usb3_hub_descriptor(struct usb_hcd *hcd, struct xhci_hcd *xhci,
struct usb_hub_descriptor *desc)
{
int ports;
u16 port_removable;
u32 portsc;
unsigned int i;
ports = xhci->num_usb3_ports;
xhci_common_hub_descriptor(xhci, desc, ports);
desc->bDescriptorType = USB_DT_SS_HUB;
desc->bDescLength = USB_DT_SS_HUB_SIZE;
desc->u.ss.bHubHdrDecLat = 0;
desc->u.ss.wHubDelay = 0;
port_removable = 0;
for (i = 0; i < ports; i++) {
portsc = readl(xhci->usb3_ports[i]);
if (portsc & PORT_DEV_REMOVE)
port_removable |= 1 << (i + 1);
}
desc->u.ss.DeviceRemovable = cpu_to_le16(port_removable);
}
static void xhci_hub_descriptor(struct usb_hcd *hcd, struct xhci_hcd *xhci,
struct usb_hub_descriptor *desc)
{
if (hcd->speed >= HCD_USB3)
xhci_usb3_hub_descriptor(hcd, xhci, desc);
else
xhci_usb2_hub_descriptor(hcd, xhci, desc);
}
static unsigned int xhci_port_speed(unsigned int port_status)
{
if (DEV_LOWSPEED(port_status))
return USB_PORT_STAT_LOW_SPEED;
if (DEV_HIGHSPEED(port_status))
return USB_PORT_STAT_HIGH_SPEED;
return 0;
}
u32 xhci_port_state_to_neutral(u32 state)
{
return (state & XHCI_PORT_RO) | (state & XHCI_PORT_RWS);
}
int xhci_find_slot_id_by_port(struct usb_hcd *hcd, struct xhci_hcd *xhci,
u16 port)
{
int slot_id;
int i;
enum usb_device_speed speed;
slot_id = 0;
for (i = 0; i < MAX_HC_SLOTS; i++) {
if (!xhci->devs[i])
continue;
speed = xhci->devs[i]->udev->speed;
if (((speed >= USB_SPEED_SUPER) == (hcd->speed >= HCD_USB3))
&& xhci->devs[i]->fake_port == port) {
slot_id = i;
break;
}
}
return slot_id;
}
static int xhci_stop_device(struct xhci_hcd *xhci, int slot_id, int suspend)
{
struct xhci_virt_device *virt_dev;
struct xhci_command *cmd;
unsigned long flags;
int ret;
int i;
ret = 0;
virt_dev = xhci->devs[slot_id];
if (!virt_dev)
return -ENODEV;
trace_xhci_stop_device(virt_dev);
cmd = xhci_alloc_command(xhci, false, true, GFP_NOIO);
if (!cmd)
return -ENOMEM;
spin_lock_irqsave(&xhci->lock, flags);
for (i = LAST_EP_INDEX; i > 0; i--) {
if (virt_dev->eps[i].ring && virt_dev->eps[i].ring->dequeue) {
struct xhci_ep_ctx *ep_ctx;
struct xhci_command *command;
ep_ctx = xhci_get_ep_ctx(xhci, virt_dev->out_ctx, i);
if (GET_EP_CTX_STATE(ep_ctx) != EP_STATE_RUNNING)
continue;
command = xhci_alloc_command(xhci, false, false,
GFP_NOWAIT);
if (!command) {
spin_unlock_irqrestore(&xhci->lock, flags);
ret = -ENOMEM;
goto cmd_cleanup;
}
ret = xhci_queue_stop_endpoint(xhci, command, slot_id,
i, suspend);
if (ret) {
spin_unlock_irqrestore(&xhci->lock, flags);
xhci_free_command(xhci, command);
goto cmd_cleanup;
}
}
}
ret = xhci_queue_stop_endpoint(xhci, cmd, slot_id, 0, suspend);
if (ret) {
spin_unlock_irqrestore(&xhci->lock, flags);
goto cmd_cleanup;
}
xhci_ring_cmd_db(xhci);
spin_unlock_irqrestore(&xhci->lock, flags);
wait_for_completion(cmd->completion);
if (cmd->status == COMP_COMMAND_ABORTED ||
cmd->status == COMP_COMMAND_RING_STOPPED) {
xhci_warn(xhci, "Timeout while waiting for stop endpoint command\n");
ret = -ETIME;
}
cmd_cleanup:
xhci_free_command(xhci, cmd);
return ret;
}
void xhci_ring_device(struct xhci_hcd *xhci, int slot_id)
{
int i, s;
struct xhci_virt_ep *ep;
for (i = 0; i < LAST_EP_INDEX + 1; i++) {
ep = &xhci->devs[slot_id]->eps[i];
if (ep->ep_state & EP_HAS_STREAMS) {
for (s = 1; s < ep->stream_info->num_streams; s++)
xhci_ring_ep_doorbell(xhci, slot_id, i, s);
} else if (ep->ring && ep->ring->dequeue) {
xhci_ring_ep_doorbell(xhci, slot_id, i, 0);
}
}
return;
}
static void xhci_disable_port(struct usb_hcd *hcd, struct xhci_hcd *xhci,
u16 wIndex, __le32 __iomem *addr, u32 port_status)
{
if (hcd->speed >= HCD_USB3) {
xhci_dbg(xhci, "Ignoring request to disable "
"SuperSpeed port.\n");
return;
}
if (xhci->quirks & XHCI_BROKEN_PORT_PED) {
xhci_dbg(xhci,
"Broken Port Enabled/Disabled, ignoring port disable request.\n");
return;
}
writel(port_status | PORT_PE, addr);
port_status = readl(addr);
xhci_dbg(xhci, "disable port, actual port %d status = 0x%x\n",
wIndex, port_status);
}
static void xhci_clear_port_change_bit(struct xhci_hcd *xhci, u16 wValue,
u16 wIndex, __le32 __iomem *addr, u32 port_status)
{
char *port_change_bit;
u32 status;
switch (wValue) {
case USB_PORT_FEAT_C_RESET:
status = PORT_RC;
port_change_bit = "reset";
break;
case USB_PORT_FEAT_C_BH_PORT_RESET:
status = PORT_WRC;
port_change_bit = "warm(BH) reset";
break;
case USB_PORT_FEAT_C_CONNECTION:
status = PORT_CSC;
port_change_bit = "connect";
break;
case USB_PORT_FEAT_C_OVER_CURRENT:
status = PORT_OCC;
port_change_bit = "over-current";
break;
case USB_PORT_FEAT_C_ENABLE:
status = PORT_PEC;
port_change_bit = "enable/disable";
break;
case USB_PORT_FEAT_C_SUSPEND:
status = PORT_PLC;
port_change_bit = "suspend/resume";
break;
case USB_PORT_FEAT_C_PORT_LINK_STATE:
status = PORT_PLC;
port_change_bit = "link state";
break;
case USB_PORT_FEAT_C_PORT_CONFIG_ERROR:
status = PORT_CEC;
port_change_bit = "config error";
break;
default:
return;
}
writel(port_status | status, addr);
port_status = readl(addr);
xhci_dbg(xhci, "clear port %s change, actual port %d status = 0x%x\n",
port_change_bit, wIndex, port_status);
}
static int xhci_get_ports(struct usb_hcd *hcd, __le32 __iomem ***port_array)
{
int max_ports;
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
if (hcd->speed >= HCD_USB3) {
max_ports = xhci->num_usb3_ports;
*port_array = xhci->usb3_ports;
} else {
max_ports = xhci->num_usb2_ports;
*port_array = xhci->usb2_ports;
}
return max_ports;
}
static __le32 __iomem *xhci_get_port_io_addr(struct usb_hcd *hcd, int index)
{
__le32 __iomem **port_array;
xhci_get_ports(hcd, &port_array);
return port_array[index];
}
static void xhci_set_port_power(struct xhci_hcd *xhci, struct usb_hcd *hcd,
u16 index, bool on, unsigned long *flags)
{
__le32 __iomem *addr;
u32 temp;
addr = xhci_get_port_io_addr(hcd, index);
temp = readl(addr);
temp = xhci_port_state_to_neutral(temp);
if (on) {
writel(temp | PORT_POWER, addr);
temp = readl(addr);
xhci_dbg(xhci, "set port power, actual port %d status = 0x%x\n",
index, temp);
} else {
writel(temp & ~PORT_POWER, addr);
}
spin_unlock_irqrestore(&xhci->lock, *flags);
temp = usb_acpi_power_manageable(hcd->self.root_hub,
index);
if (temp)
usb_acpi_set_power_state(hcd->self.root_hub,
index, on);
spin_lock_irqsave(&xhci->lock, *flags);
}
static void xhci_port_set_test_mode(struct xhci_hcd *xhci,
u16 test_mode, u16 wIndex)
{
u32 temp;
__le32 __iomem *addr;
addr = xhci_get_port_io_addr(xhci->main_hcd, wIndex);
temp = readl(addr + PORTPMSC);
temp |= test_mode << PORT_TEST_MODE_SHIFT;
writel(temp, addr + PORTPMSC);
xhci->test_mode = test_mode;
if (test_mode == TEST_FORCE_EN)
xhci_start(xhci);
}
static int xhci_enter_test_mode(struct xhci_hcd *xhci,
u16 test_mode, u16 wIndex, unsigned long *flags)
{
int i, retval;
xhci_dbg(xhci, "Disable all slots\n");
spin_unlock_irqrestore(&xhci->lock, *flags);
for (i = 1; i <= HCS_MAX_SLOTS(xhci->hcs_params1); i++) {
retval = xhci_disable_slot(xhci, NULL, i);
if (retval)
xhci_err(xhci, "Failed to disable slot %d, %d. Enter test mode anyway\n",
i, retval);
}
spin_lock_irqsave(&xhci->lock, *flags);
xhci_dbg(xhci, "Disable all port (PP = 0)\n");
for (i = 0; i < xhci->num_usb3_ports; i++)
xhci_set_port_power(xhci, xhci->shared_hcd, i, false, flags);
for (i = 0; i < xhci->num_usb2_ports; i++)
xhci_set_port_power(xhci, xhci->main_hcd, i, false, flags);
xhci_dbg(xhci, "Stop controller\n");
retval = xhci_halt(xhci);
if (retval)
return retval;
pm_runtime_forbid(xhci_to_hcd(xhci)->self.controller);
xhci_dbg(xhci, "Enter Test Mode: %d, Port_id=%d\n",
test_mode, wIndex + 1);
xhci_port_set_test_mode(xhci, test_mode, wIndex);
return retval;
}
static int xhci_exit_test_mode(struct xhci_hcd *xhci)
{
int retval;
if (!xhci->test_mode) {
xhci_err(xhci, "Not in test mode, do nothing.\n");
return 0;
}
if (xhci->test_mode == TEST_FORCE_EN &&
!(xhci->xhc_state & XHCI_STATE_HALTED)) {
retval = xhci_halt(xhci);
if (retval)
return retval;
}
pm_runtime_allow(xhci_to_hcd(xhci)->self.controller);
xhci->test_mode = 0;
return xhci_reset(xhci);
}
void xhci_set_link_state(struct xhci_hcd *xhci, __le32 __iomem **port_array,
int port_id, u32 link_state)
{
u32 temp;
temp = readl(port_array[port_id]);
temp = xhci_port_state_to_neutral(temp);
temp &= ~PORT_PLS_MASK;
temp |= PORT_LINK_STROBE | link_state;
writel(temp, port_array[port_id]);
}
static void xhci_set_remote_wake_mask(struct xhci_hcd *xhci,
__le32 __iomem **port_array, int port_id, u16 wake_mask)
{
u32 temp;
temp = readl(port_array[port_id]);
temp = xhci_port_state_to_neutral(temp);
if (wake_mask & USB_PORT_FEAT_REMOTE_WAKE_CONNECT)
temp |= PORT_WKCONN_E;
else
temp &= ~PORT_WKCONN_E;
if (wake_mask & USB_PORT_FEAT_REMOTE_WAKE_DISCONNECT)
temp |= PORT_WKDISC_E;
else
temp &= ~PORT_WKDISC_E;
if (wake_mask & USB_PORT_FEAT_REMOTE_WAKE_OVER_CURRENT)
temp |= PORT_WKOC_E;
else
temp &= ~PORT_WKOC_E;
writel(temp, port_array[port_id]);
}
void xhci_test_and_clear_bit(struct xhci_hcd *xhci, __le32 __iomem **port_array,
int port_id, u32 port_bit)
{
u32 temp;
temp = readl(port_array[port_id]);
if (temp & port_bit) {
temp = xhci_port_state_to_neutral(temp);
temp |= port_bit;
writel(temp, port_array[port_id]);
}
}
static void xhci_hub_report_usb2_link_state(u32 *status, u32 status_reg)
{
if ((status_reg & PORT_PLS_MASK) == XDEV_U2)
*status |= USB_PORT_STAT_L1;
}
static void xhci_hub_report_usb3_link_state(struct xhci_hcd *xhci,
u32 *status, u32 status_reg)
{
u32 pls = status_reg & PORT_PLS_MASK;
if (pls == XDEV_RESUME) {
*status |= USB_SS_PORT_LS_U3;
return;
}
if (status_reg & PORT_CAS) {
if (pls != USB_SS_PORT_LS_COMP_MOD &&
pls != USB_SS_PORT_LS_SS_INACTIVE) {
pls = USB_SS_PORT_LS_COMP_MOD;
}
pls |= USB_PORT_STAT_CONNECTION;
} else {
if ((xhci->quirks & XHCI_COMP_MODE_QUIRK) &&
(pls == USB_SS_PORT_LS_COMP_MOD))
pls |= USB_PORT_STAT_CONNECTION;
}
*status |= pls;
}
static void xhci_del_comp_mod_timer(struct xhci_hcd *xhci, u32 status,
u16 wIndex)
{
u32 all_ports_seen_u0 = ((1 << xhci->num_usb3_ports)-1);
bool port_in_u0 = ((status & PORT_PLS_MASK) == XDEV_U0);
if (!(xhci->quirks & XHCI_COMP_MODE_QUIRK))
return;
if ((xhci->port_status_u0 != all_ports_seen_u0) && port_in_u0) {
xhci->port_status_u0 |= 1 << wIndex;
if (xhci->port_status_u0 == all_ports_seen_u0) {
del_timer_sync(&xhci->comp_mode_recovery_timer);
xhci_dbg_trace(xhci, trace_xhci_dbg_quirks,
"All USB3 ports have entered U0 already!");
xhci_dbg_trace(xhci, trace_xhci_dbg_quirks,
"Compliance Mode Recovery Timer Deleted.");
}
}
}
static u32 xhci_get_ext_port_status(u32 raw_port_status, u32 port_li)
{
u32 ext_stat = 0;
int speed_id;
speed_id = DEV_PORT_SPEED(raw_port_status);
ext_stat |= speed_id;
ext_stat |= speed_id << 4;
ext_stat |= PORT_RX_LANES(port_li) << 8;
ext_stat |= PORT_TX_LANES(port_li) << 12;
return ext_stat;
}
static u32 xhci_get_port_status(struct usb_hcd *hcd,
struct xhci_bus_state *bus_state,
__le32 __iomem **port_array,
u16 wIndex, u32 raw_port_status,
unsigned long flags)
__releases(&xhci->lock
int xhci_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
int max_ports;
unsigned long flags;
u32 temp, status;
int retval = 0;
__le32 __iomem **port_array;
int slot_id;
struct xhci_bus_state *bus_state;
u16 link_state = 0;
u16 wake_mask = 0;
u16 timeout = 0;
u16 test_mode = 0;
max_ports = xhci_get_ports(hcd, &port_array);
bus_state = &xhci->bus_state[hcd_index(hcd)];
spin_lock_irqsave(&xhci->lock, flags);
switch (typeReq) {
case GetHubStatus:
memset(buf, 0, 4);
break;
case GetHubDescriptor:
if (hcd->speed >= HCD_USB3 &&
(wLength < USB_DT_SS_HUB_SIZE ||
wValue != (USB_DT_SS_HUB << 8))) {
xhci_dbg(xhci, "Wrong hub descriptor type for "
"USB 3.0 roothub.\n");
goto error;
}
xhci_hub_descriptor(hcd, xhci,
(struct usb_hub_descriptor *) buf);
break;
case DeviceRequest | USB_REQ_GET_DESCRIPTOR:
if ((wValue & 0xff00) != (USB_DT_BOS << 8))
goto error;
if (hcd->speed < HCD_USB3)
goto error;
retval = xhci_create_usb3_bos_desc(xhci, buf, wLength);
spin_unlock_irqrestore(&xhci->lock, flags);
return retval;
case GetPortStatus:
if (!wIndex || wIndex > max_ports)
goto error;
wIndex--;
temp = readl(port_array[wIndex]);
if (temp == ~(u32)0) {
xhci_hc_died(xhci);
retval = -ENODEV;
break;
}
status = xhci_get_port_status(hcd, bus_state, port_array,
wIndex, temp, flags);
if (status == 0xffffffff)
goto error;
xhci_dbg(xhci, "get port status, actual port %d status = 0x%x\n",
wIndex, temp);
xhci_dbg(xhci, "Get port status returned 0x%x\n", status);
put_unaligned(cpu_to_le32(status), (__le32 *) buf);
if (wValue == 0x02) {
u32 port_li;
if (hcd->speed < HCD_USB31 || wLength != 8) {
xhci_err(xhci, "get ext port status invalid parameter\n");
retval = -EINVAL;
break;
}
port_li = readl(port_array[wIndex] + PORTLI);
status = xhci_get_ext_port_status(temp, port_li);
put_unaligned_le32(cpu_to_le32(status), &buf[4]);
}
break;
case SetPortFeature:
if (wValue == USB_PORT_FEAT_LINK_STATE)
link_state = (wIndex & 0xff00) >> 3;
if (wValue == USB_PORT_FEAT_REMOTE_WAKE_MASK)
wake_mask = wIndex & 0xff00;
if (wValue == USB_PORT_FEAT_TEST)
test_mode = (wIndex & 0xff00) >> 8;
timeout = (wIndex & 0xff00) >> 8;
wIndex &= 0xff;
if (!wIndex || wIndex > max_ports)
goto error;
wIndex--;
temp = readl(port_array[wIndex]);
if (temp == ~(u32)0) {
xhci_hc_died(xhci);
retval = -ENODEV;
break;
}
temp = xhci_port_state_to_neutral(temp);
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
temp = readl(port_array[wIndex]);
if ((temp & PORT_PLS_MASK) != XDEV_U0) {
xhci_set_link_state(xhci, port_array, wIndex,
XDEV_U0);
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(10);
spin_lock_irqsave(&xhci->lock, flags);
}
temp = readl(port_array[wIndex]);
if ((temp & PORT_PE) == 0 || (temp & PORT_RESET)
|| (temp & PORT_PLS_MASK) >= XDEV_U3) {
xhci_warn(xhci, "USB core suspending device not in U0/U1/U2.\n");
goto error;
}
slot_id = xhci_find_slot_id_by_port(hcd, xhci,
wIndex + 1);
if (!slot_id) {
xhci_warn(xhci, "slot_id is zero\n");
goto error;
}
spin_unlock_irqrestore(&xhci->lock, flags);
xhci_stop_device(xhci, slot_id, 1);
spin_lock_irqsave(&xhci->lock, flags);
xhci_set_link_state(xhci, port_array, wIndex, XDEV_U3);
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(10);
spin_lock_irqsave(&xhci->lock, flags);
temp = readl(port_array[wIndex]);
bus_state->suspended_ports |= 1 << wIndex;
break;
case USB_PORT_FEAT_LINK_STATE:
temp = readl(port_array[wIndex]);
if (link_state == USB_SS_PORT_LS_SS_DISABLED) {
xhci_dbg(xhci, "Disable port %d\n", wIndex);
temp = xhci_port_state_to_neutral(temp);
temp |= PORT_CSC | PORT_PEC | PORT_WRC |
PORT_OCC | PORT_RC | PORT_PLC |
PORT_CEC;
writel(temp | PORT_PE, port_array[wIndex]);
temp = readl(port_array[wIndex]);
break;
}
if (link_state == USB_SS_PORT_LS_RX_DETECT) {
xhci_dbg(xhci, "Enable port %d\n", wIndex);
xhci_set_link_state(xhci, port_array, wIndex,
link_state);
temp = readl(port_array[wIndex]);
break;
}
if (link_state == USB_SS_PORT_LS_COMP_MOD) {
if (!HCC2_CTC(xhci->hcc_params2)) {
xhci_dbg(xhci, "CTC flag is 0, port already supports entering compliance mode\n");
break;
}
if ((temp & PORT_CONNECT)) {
xhci_warn(xhci, "Can't set compliance mode when port is connected\n");
goto error;
}
xhci_dbg(xhci, "Enable compliance mode transition for port %d\n",
wIndex);
xhci_set_link_state(xhci, port_array, wIndex,
link_state);
temp = readl(port_array[wIndex]);
break;
}
if ((temp & PORT_PE) == 0 ||
(link_state > USB_SS_PORT_LS_U3)) {
xhci_warn(xhci, "Cannot set link state.\n");
goto error;
}
if (link_state == USB_SS_PORT_LS_U3) {
slot_id = xhci_find_slot_id_by_port(hcd, xhci,
wIndex + 1);
if (slot_id) {
spin_unlock_irqrestore(&xhci->lock,
flags);
xhci_stop_device(xhci, slot_id, 1);
spin_lock_irqsave(&xhci->lock, flags);
}
}
xhci_set_link_state(xhci, port_array, wIndex,
link_state);
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(20);
spin_lock_irqsave(&xhci->lock, flags);
temp = readl(port_array[wIndex]);
if (link_state == USB_SS_PORT_LS_U3)
bus_state->suspended_ports |= 1 << wIndex;
break;
case USB_PORT_FEAT_POWER:
xhci_set_port_power(xhci, hcd, wIndex, true, &flags);
break;
case USB_PORT_FEAT_RESET:
temp = (temp | PORT_RESET);
writel(temp, port_array[wIndex]);
temp = readl(port_array[wIndex]);
xhci_dbg(xhci, "set port reset, actual port %d status = 0x%x\n", wIndex, temp);
break;
case USB_PORT_FEAT_REMOTE_WAKE_MASK:
xhci_set_remote_wake_mask(xhci, port_array,
wIndex, wake_mask);
temp = readl(port_array[wIndex]);
xhci_dbg(xhci, "set port remote wake mask, "
"actual port %d status = 0x%x\n",
wIndex, temp);
break;
case USB_PORT_FEAT_BH_PORT_RESET:
temp |= PORT_WR;
writel(temp, port_array[wIndex]);
temp = readl(port_array[wIndex]);
break;
case USB_PORT_FEAT_U1_TIMEOUT:
if (hcd->speed < HCD_USB3)
goto error;
temp = readl(port_array[wIndex] + PORTPMSC);
temp &= ~PORT_U1_TIMEOUT_MASK;
temp |= PORT_U1_TIMEOUT(timeout);
writel(temp, port_array[wIndex] + PORTPMSC);
break;
case USB_PORT_FEAT_U2_TIMEOUT:
if (hcd->speed < HCD_USB3)
goto error;
temp = readl(port_array[wIndex] + PORTPMSC);
temp &= ~PORT_U2_TIMEOUT_MASK;
temp |= PORT_U2_TIMEOUT(timeout);
writel(temp, port_array[wIndex] + PORTPMSC);
break;
case USB_PORT_FEAT_TEST:
if (hcd->speed != HCD_USB2)
goto error;
if (test_mode > TEST_FORCE_EN || test_mode < TEST_J)
goto error;
retval = xhci_enter_test_mode(xhci, test_mode, wIndex,
&flags);
break;
default:
goto error;
}
temp = readl(port_array[wIndex]);
break;
case ClearPortFeature:
if (!wIndex || wIndex > max_ports)
goto error;
wIndex--;
temp = readl(port_array[wIndex]);
if (temp == ~(u32)0) {
xhci_hc_died(xhci);
retval = -ENODEV;
break;
}
temp = xhci_port_state_to_neutral(temp);
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
temp = readl(port_array[wIndex]);
xhci_dbg(xhci, "clear USB_PORT_FEAT_SUSPEND\n");
xhci_dbg(xhci, "PORTSC %04x\n", temp);
if (temp & PORT_RESET)
goto error;
if ((temp & PORT_PLS_MASK) == XDEV_U3) {
if ((temp & PORT_PE) == 0)
goto error;
set_bit(wIndex, &bus_state->resuming_ports);
xhci_set_link_state(xhci, port_array, wIndex,
XDEV_RESUME);
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(USB_RESUME_TIMEOUT);
spin_lock_irqsave(&xhci->lock, flags);
xhci_set_link_state(xhci, port_array, wIndex,
XDEV_U0);
clear_bit(wIndex, &bus_state->resuming_ports);
}
bus_state->port_c_suspend |= 1 << wIndex;
slot_id = xhci_find_slot_id_by_port(hcd, xhci,
wIndex + 1);
if (!slot_id) {
xhci_dbg(xhci, "slot_id is zero\n");
goto error;
}
xhci_ring_device(xhci, slot_id);
break;
case USB_PORT_FEAT_C_SUSPEND:
bus_state->port_c_suspend &= ~(1 << wIndex);
case USB_PORT_FEAT_C_RESET:
case USB_PORT_FEAT_C_BH_PORT_RESET:
case USB_PORT_FEAT_C_CONNECTION:
case USB_PORT_FEAT_C_OVER_CURRENT:
case USB_PORT_FEAT_C_ENABLE:
case USB_PORT_FEAT_C_PORT_LINK_STATE:
case USB_PORT_FEAT_C_PORT_CONFIG_ERROR:
xhci_clear_port_change_bit(xhci, wValue, wIndex,
port_array[wIndex], temp);
break;
case USB_PORT_FEAT_ENABLE:
xhci_disable_port(hcd, xhci, wIndex,
port_array[wIndex], temp);
break;
case USB_PORT_FEAT_POWER:
xhci_set_port_power(xhci, hcd, wIndex, false, &flags);
break;
case USB_PORT_FEAT_TEST:
retval = xhci_exit_test_mode(xhci);
break;
default:
goto error;
}
break;
default:
error:
retval = -EPIPE;
}
spin_unlock_irqrestore(&xhci->lock, flags);
return retval;
}
int xhci_hub_status_data(struct usb_hcd *hcd, char *buf)
{
unsigned long flags;
u32 temp, status;
u32 mask;
int i, retval;
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
int max_ports;
__le32 __iomem **port_array;
struct xhci_bus_state *bus_state;
bool reset_change = false;
max_ports = xhci_get_ports(hcd, &port_array);
bus_state = &xhci->bus_state[hcd_index(hcd)];
retval = (max_ports + 8) / 8;
memset(buf, 0, retval);
status = bus_state->resuming_ports;
mask = PORT_CSC | PORT_PEC | PORT_OCC | PORT_PLC | PORT_WRC | PORT_CEC;
spin_lock_irqsave(&xhci->lock, flags);
for (i = 0; i < max_ports; i++) {
temp = readl(port_array[i]);
if (temp == ~(u32)0) {
xhci_hc_died(xhci);
retval = -ENODEV;
break;
}
if ((temp & mask) != 0 ||
(bus_state->port_c_suspend & 1 << i) ||
(bus_state->resume_done[i] && time_after_eq(
jiffies, bus_state->resume_done[i]))) {
buf[(i + 1) / 8] |= 1 << (i + 1) % 8;
status = 1;
}
if ((temp & PORT_RC))
reset_change = true;
}
if (!status && !reset_change) {
xhci_dbg(xhci, "%s: stopping port polling.\n", __func__);
clear_bit(HCD_FLAG_POLL_RH, &hcd->flags);
}
spin_unlock_irqrestore(&xhci->lock, flags);
return status ? retval : 0;
}
int xhci_bus_suspend(struct usb_hcd *hcd)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
int max_ports, port_index;
__le32 __iomem **port_array;
struct xhci_bus_state *bus_state;
unsigned long flags;
max_ports = xhci_get_ports(hcd, &port_array);
bus_state = &xhci->bus_state[hcd_index(hcd)];
spin_lock_irqsave(&xhci->lock, flags);
if (hcd->self.root_hub->do_remote_wakeup) {
if (bus_state->resuming_ports ||
bus_state->port_remote_wakeup) {
spin_unlock_irqrestore(&xhci->lock, flags);
xhci_dbg(xhci, "suspend failed because a port is resuming\n");
return -EBUSY;
}
}
port_index = max_ports;
bus_state->bus_suspended = 0;
while (port_index--) {
u32 t1, t2;
int slot_id;
t1 = readl(port_array[port_index]);
t2 = xhci_port_state_to_neutral(t1);
if ((t1 & PORT_PE) && !(t1 & PORT_PLS_MASK)) {
xhci_dbg(xhci, "port %d not suspended\n", port_index);
slot_id = xhci_find_slot_id_by_port(hcd, xhci,
port_index + 1);
if (slot_id) {
spin_unlock_irqrestore(&xhci->lock, flags);
xhci_stop_device(xhci, slot_id, 1);
spin_lock_irqsave(&xhci->lock, flags);
}
t2 &= ~PORT_PLS_MASK;
t2 |= PORT_LINK_STROBE | XDEV_U3;
set_bit(port_index, &bus_state->bus_suspended);
}
if (hcd->self.root_hub->do_remote_wakeup) {
if (t1 & PORT_CONNECT) {
t2 |= PORT_WKOC_E | PORT_WKDISC_E;
t2 &= ~PORT_WKCONN_E;
} else {
t2 |= PORT_WKOC_E | PORT_WKCONN_E;
t2 &= ~PORT_WKDISC_E;
}
} else
t2 &= ~PORT_WAKE_BITS;
t1 = xhci_port_state_to_neutral(t1);
if (t1 != t2)
writel(t2, port_array[port_index]);
}
hcd->state = HC_STATE_SUSPENDED;
bus_state->next_statechange = jiffies + msecs_to_jiffies(10);
spin_unlock_irqrestore(&xhci->lock, flags);
return 0;
}
static bool xhci_port_missing_cas_quirk(int port_index,
__le32 __iomem **port_array)
{
u32 portsc;
portsc = readl(port_array[port_index]);
if (portsc & (PORT_CONNECT | PORT_CAS))
return false;
if (((portsc & PORT_PLS_MASK) != XDEV_POLLING) &&
((portsc & PORT_PLS_MASK) != XDEV_COMP_MODE))
return false;
portsc &= ~(PORT_RWC_BITS | PORT_CEC | PORT_WAKE_BITS);
portsc |= PORT_WR;
writel(portsc, port_array[port_index]);
readl(port_array[port_index]);
return true;
}
int xhci_bus_resume(struct usb_hcd *hcd)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
struct xhci_bus_state *bus_state;
__le32 __iomem **port_array;
unsigned long flags;
int max_ports, port_index;
int slot_id;
int sret;
u32 next_state;
u32 temp, portsc;
max_ports = xhci_get_ports(hcd, &port_array);
bus_state = &xhci->bus_state[hcd_index(hcd)];
if (time_before(jiffies, bus_state->next_statechange))
msleep(5);
spin_lock_irqsave(&xhci->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd)) {
spin_unlock_irqrestore(&xhci->lock, flags);
return -ESHUTDOWN;
}
temp = readl(&xhci->op_regs->command);
temp &= ~CMD_EIE;
writel(temp, &xhci->op_regs->command);
if (hcd->speed >= HCD_USB3)
next_state = XDEV_U0;
else
next_state = XDEV_RESUME;
port_index = max_ports;
while (port_index--) {
portsc = readl(port_array[port_index]);
if ((xhci->quirks & XHCI_MISSING_CAS) &&
(hcd->speed >= HCD_USB3) &&
xhci_port_missing_cas_quirk(port_index, port_array)) {
xhci_dbg(xhci, "reset stuck port %d\n", port_index);
clear_bit(port_index, &bus_state->bus_suspended);
continue;
}
if (test_bit(port_index, &bus_state->bus_suspended))
switch (portsc & PORT_PLS_MASK) {
case XDEV_U3:
portsc = xhci_port_state_to_neutral(portsc);
portsc &= ~PORT_PLS_MASK;
portsc |= PORT_LINK_STROBE | next_state;
break;
case XDEV_RESUME:
break;
default:
clear_bit(port_index,
&bus_state->bus_suspended);
break;
}
portsc &= ~(PORT_RWC_BITS | PORT_CEC | PORT_WAKE_BITS);
writel(portsc, port_array[port_index]);
}
if (hcd->speed < HCD_USB3) {
if (bus_state->bus_suspended) {
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(USB_RESUME_TIMEOUT);
spin_lock_irqsave(&xhci->lock, flags);
}
for_each_set_bit(port_index, &bus_state->bus_suspended,
BITS_PER_LONG) {
xhci_test_and_clear_bit(xhci, port_array, port_index,
PORT_PLC);
xhci_set_link_state(xhci, port_array, port_index,
XDEV_U0);
}
}
for_each_set_bit(port_index, &bus_state->bus_suspended, BITS_PER_LONG) {
sret = xhci_handshake(port_array[port_index], PORT_PLC,
PORT_PLC, 10 * 1000);
if (sret) {
xhci_warn(xhci, "port %d resume PLC timeout\n",
port_index);
continue;
}
xhci_test_and_clear_bit(xhci, port_array, port_index, PORT_PLC);
slot_id = xhci_find_slot_id_by_port(hcd, xhci, port_index + 1);
if (slot_id)
xhci_ring_device(xhci, slot_id);
}
(void) readl(&xhci->op_regs->command);
bus_state->next_statechange = jiffies + msecs_to_jiffies(5);
temp = readl(&xhci->op_regs->command);
temp |= CMD_EIE;
writel(temp, &xhci->op_regs->command);
temp = readl(&xhci->op_regs->command);
spin_unlock_irqrestore(&xhci->lock, flags);
return 0;
}
