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
portsc = xhci_readl(xhci, xhci->usb2_ports[i]);
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
portsc = xhci_readl(xhci, xhci->usb3_ports[i]);
if (portsc & PORT_DEV_REMOVE)
port_removable |= 1 << (i + 1);
}
desc->u.ss.DeviceRemovable = cpu_to_le16(port_removable);
}
static void xhci_hub_descriptor(struct usb_hcd *hcd, struct xhci_hcd *xhci,
struct usb_hub_descriptor *desc)
{
if (hcd->speed == HCD_USB3)
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
if (((speed == USB_SPEED_SUPER) == (hcd->speed == HCD_USB3))
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
int timeleft;
int ret;
int i;
ret = 0;
virt_dev = xhci->devs[slot_id];
cmd = xhci_alloc_command(xhci, false, true, GFP_NOIO);
if (!cmd) {
xhci_dbg(xhci, "Couldn't allocate command structure.\n");
return -ENOMEM;
}
spin_lock_irqsave(&xhci->lock, flags);
for (i = LAST_EP_INDEX; i > 0; i--) {
if (virt_dev->eps[i].ring && virt_dev->eps[i].ring->dequeue)
xhci_queue_stop_endpoint(xhci, slot_id, i, suspend);
}
cmd->command_trb = xhci->cmd_ring->enqueue;
list_add_tail(&cmd->cmd_list, &virt_dev->cmd_list);
xhci_queue_stop_endpoint(xhci, slot_id, 0, suspend);
xhci_ring_cmd_db(xhci);
spin_unlock_irqrestore(&xhci->lock, flags);
timeleft = wait_for_completion_interruptible_timeout(
cmd->completion,
USB_CTRL_SET_TIMEOUT);
if (timeleft <= 0) {
xhci_warn(xhci, "%s while waiting for stop endpoint command\n",
timeleft == 0 ? "Timeout" : "Signal");
spin_lock_irqsave(&xhci->lock, flags);
if (cmd->cmd_list.next != LIST_POISON1)
list_del(&cmd->cmd_list);
spin_unlock_irqrestore(&xhci->lock, flags);
ret = -ETIME;
goto command_cleanup;
}
command_cleanup:
xhci_free_command(xhci, cmd);
return ret;
}
void xhci_ring_device(struct xhci_hcd *xhci, int slot_id)
{
int i;
for (i = 0; i < LAST_EP_INDEX + 1; i++)
if (xhci->devs[slot_id]->eps[i].ring &&
xhci->devs[slot_id]->eps[i].ring->dequeue)
xhci_ring_ep_doorbell(xhci, slot_id, i, 0);
return;
}
static void xhci_disable_port(struct usb_hcd *hcd, struct xhci_hcd *xhci,
u16 wIndex, __le32 __iomem *addr, u32 port_status)
{
if (hcd->speed == HCD_USB3) {
xhci_dbg(xhci, "Ignoring request to disable "
"SuperSpeed port.\n");
return;
}
xhci_writel(xhci, port_status | PORT_PE, addr);
port_status = xhci_readl(xhci, addr);
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
default:
return;
}
xhci_writel(xhci, port_status | status, addr);
port_status = xhci_readl(xhci, addr);
xhci_dbg(xhci, "clear port %s change, actual port %d status = 0x%x\n",
port_change_bit, wIndex, port_status);
}
static int xhci_get_ports(struct usb_hcd *hcd, __le32 __iomem ***port_array)
{
int max_ports;
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
if (hcd->speed == HCD_USB3) {
max_ports = xhci->num_usb3_ports;
*port_array = xhci->usb3_ports;
} else {
max_ports = xhci->num_usb2_ports;
*port_array = xhci->usb2_ports;
}
return max_ports;
}
void xhci_set_link_state(struct xhci_hcd *xhci, __le32 __iomem **port_array,
int port_id, u32 link_state)
{
u32 temp;
temp = xhci_readl(xhci, port_array[port_id]);
temp = xhci_port_state_to_neutral(temp);
temp &= ~PORT_PLS_MASK;
temp |= PORT_LINK_STROBE | link_state;
xhci_writel(xhci, temp, port_array[port_id]);
}
static void xhci_set_remote_wake_mask(struct xhci_hcd *xhci,
__le32 __iomem **port_array, int port_id, u16 wake_mask)
{
u32 temp;
temp = xhci_readl(xhci, port_array[port_id]);
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
xhci_writel(xhci, temp, port_array[port_id]);
}
void xhci_test_and_clear_bit(struct xhci_hcd *xhci, __le32 __iomem **port_array,
int port_id, u32 port_bit)
{
u32 temp;
temp = xhci_readl(xhci, port_array[port_id]);
if (temp & port_bit) {
temp = xhci_port_state_to_neutral(temp);
temp |= port_bit;
xhci_writel(xhci, temp, port_array[port_id]);
}
}
static void xhci_hub_report_link_state(u32 *status, u32 status_reg)
{
u32 pls = status_reg & PORT_PLS_MASK;
if (pls == XDEV_RESUME)
return;
if (status_reg & PORT_CAS) {
if (pls != USB_SS_PORT_LS_COMP_MOD &&
pls != USB_SS_PORT_LS_SS_INACTIVE) {
pls = USB_SS_PORT_LS_COMP_MOD;
}
pls |= USB_PORT_STAT_CONNECTION;
} else {
if (pls == USB_SS_PORT_LS_COMP_MOD)
pls |= USB_PORT_STAT_CONNECTION;
}
*status |= pls;
}
void xhci_del_comp_mod_timer(struct xhci_hcd *xhci, u32 status, u16 wIndex)
{
u32 all_ports_seen_u0 = ((1 << xhci->num_usb3_ports)-1);
bool port_in_u0 = ((status & PORT_PLS_MASK) == XDEV_U0);
if (!(xhci->quirks & XHCI_COMP_MODE_QUIRK))
return;
if ((xhci->port_status_u0 != all_ports_seen_u0) && port_in_u0) {
xhci->port_status_u0 |= 1 << wIndex;
if (xhci->port_status_u0 == all_ports_seen_u0) {
del_timer_sync(&xhci->comp_mode_recovery_timer);
xhci_dbg(xhci, "All USB3 ports have entered U0 already!\n");
xhci_dbg(xhci, "Compliance Mode Recovery Timer Deleted.\n");
}
}
}
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
max_ports = xhci_get_ports(hcd, &port_array);
bus_state = &xhci->bus_state[hcd_index(hcd)];
spin_lock_irqsave(&xhci->lock, flags);
switch (typeReq) {
case GetHubStatus:
memset(buf, 0, 4);
break;
case GetHubDescriptor:
if (hcd->speed == HCD_USB3 &&
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
if (hcd->speed != HCD_USB3)
goto error;
memcpy(buf, &usb_bos_descriptor,
USB_DT_BOS_SIZE + USB_DT_USB_SS_CAP_SIZE);
temp = xhci_readl(xhci, &xhci->cap_regs->hcs_params3);
buf[12] = HCS_U1_LATENCY(temp);
put_unaligned_le16(HCS_U2_LATENCY(temp), &buf[13]);
temp = xhci_readl(xhci, &xhci->cap_regs->hcc_params);
if (HCC_LTC(temp))
buf[8] |= USB_LTM_SUPPORT;
spin_unlock_irqrestore(&xhci->lock, flags);
return USB_DT_BOS_SIZE + USB_DT_USB_SS_CAP_SIZE;
case GetPortStatus:
if (!wIndex || wIndex > max_ports)
goto error;
wIndex--;
status = 0;
temp = xhci_readl(xhci, port_array[wIndex]);
if (temp == 0xffffffff) {
retval = -ENODEV;
break;
}
xhci_dbg(xhci, "get port status, actual port %d status = 0x%x\n", wIndex, temp);
if (temp & PORT_CSC)
status |= USB_PORT_STAT_C_CONNECTION << 16;
if (temp & PORT_PEC)
status |= USB_PORT_STAT_C_ENABLE << 16;
if ((temp & PORT_OCC))
status |= USB_PORT_STAT_C_OVERCURRENT << 16;
if ((temp & PORT_RC))
status |= USB_PORT_STAT_C_RESET << 16;
if (hcd->speed == HCD_USB3) {
if ((temp & PORT_PLC))
status |= USB_PORT_STAT_C_LINK_STATE << 16;
if ((temp & PORT_WRC))
status |= USB_PORT_STAT_C_BH_RESET << 16;
}
if (hcd->speed != HCD_USB3) {
if ((temp & PORT_PLS_MASK) == XDEV_U3
&& (temp & PORT_POWER))
status |= USB_PORT_STAT_SUSPEND;
}
if ((temp & PORT_PLS_MASK) == XDEV_RESUME &&
!DEV_SUPERSPEED(temp)) {
if ((temp & PORT_RESET) || !(temp & PORT_PE))
goto error;
if (time_after_eq(jiffies,
bus_state->resume_done[wIndex])) {
xhci_dbg(xhci, "Resume USB2 port %d\n",
wIndex + 1);
bus_state->resume_done[wIndex] = 0;
clear_bit(wIndex, &bus_state->resuming_ports);
xhci_set_link_state(xhci, port_array, wIndex,
XDEV_U0);
xhci_dbg(xhci, "set port %d resume\n",
wIndex + 1);
slot_id = xhci_find_slot_id_by_port(hcd, xhci,
wIndex + 1);
if (!slot_id) {
xhci_dbg(xhci, "slot_id is zero\n");
goto error;
}
xhci_ring_device(xhci, slot_id);
bus_state->port_c_suspend |= 1 << wIndex;
bus_state->suspended_ports &= ~(1 << wIndex);
} else {
status |= USB_PORT_STAT_SUSPEND;
}
}
if ((temp & PORT_PLS_MASK) == XDEV_U0
&& (temp & PORT_POWER)
&& (bus_state->suspended_ports & (1 << wIndex))) {
bus_state->suspended_ports &= ~(1 << wIndex);
if (hcd->speed != HCD_USB3)
bus_state->port_c_suspend |= 1 << wIndex;
}
if (temp & PORT_CONNECT) {
status |= USB_PORT_STAT_CONNECTION;
status |= xhci_port_speed(temp);
}
if (temp & PORT_PE)
status |= USB_PORT_STAT_ENABLE;
if (temp & PORT_OC)
status |= USB_PORT_STAT_OVERCURRENT;
if (temp & PORT_RESET)
status |= USB_PORT_STAT_RESET;
if (temp & PORT_POWER) {
if (hcd->speed == HCD_USB3)
status |= USB_SS_PORT_STAT_POWER;
else
status |= USB_PORT_STAT_POWER;
}
if (hcd->speed == HCD_USB3) {
xhci_hub_report_link_state(&status, temp);
xhci_del_comp_mod_timer(xhci, temp, wIndex);
}
if (bus_state->port_c_suspend & (1 << wIndex))
status |= 1 << USB_PORT_FEAT_C_SUSPEND;
xhci_dbg(xhci, "Get port status returned 0x%x\n", status);
put_unaligned(cpu_to_le32(status), (__le32 *) buf);
break;
case SetPortFeature:
if (wValue == USB_PORT_FEAT_LINK_STATE)
link_state = (wIndex & 0xff00) >> 3;
if (wValue == USB_PORT_FEAT_REMOTE_WAKE_MASK)
wake_mask = wIndex & 0xff00;
timeout = (wIndex & 0xff00) >> 8;
wIndex &= 0xff;
if (!wIndex || wIndex > max_ports)
goto error;
wIndex--;
temp = xhci_readl(xhci, port_array[wIndex]);
if (temp == 0xffffffff) {
retval = -ENODEV;
break;
}
temp = xhci_port_state_to_neutral(temp);
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
temp = xhci_readl(xhci, port_array[wIndex]);
if ((temp & PORT_PLS_MASK) != XDEV_U0) {
xhci_set_link_state(xhci, port_array, wIndex,
XDEV_U0);
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(10);
spin_lock_irqsave(&xhci->lock, flags);
}
temp = xhci_readl(xhci, port_array[wIndex]);
if ((temp & PORT_PE) == 0 || (temp & PORT_RESET)
|| (temp & PORT_PLS_MASK) >= XDEV_U3) {
xhci_warn(xhci, "USB core suspending device "
"not in U0/U1/U2.\n");
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
temp = xhci_readl(xhci, port_array[wIndex]);
bus_state->suspended_ports |= 1 << wIndex;
break;
case USB_PORT_FEAT_LINK_STATE:
temp = xhci_readl(xhci, port_array[wIndex]);
if (link_state == USB_SS_PORT_LS_SS_DISABLED) {
xhci_dbg(xhci, "Disable port %d\n", wIndex);
temp = xhci_port_state_to_neutral(temp);
temp |= PORT_CSC | PORT_PEC | PORT_WRC |
PORT_OCC | PORT_RC | PORT_PLC |
PORT_CEC;
xhci_writel(xhci, temp | PORT_PE,
port_array[wIndex]);
temp = xhci_readl(xhci, port_array[wIndex]);
break;
}
if (link_state == USB_SS_PORT_LS_RX_DETECT) {
xhci_dbg(xhci, "Enable port %d\n", wIndex);
xhci_set_link_state(xhci, port_array, wIndex,
link_state);
temp = xhci_readl(xhci, port_array[wIndex]);
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
temp = xhci_readl(xhci, port_array[wIndex]);
if (link_state == USB_SS_PORT_LS_U3)
bus_state->suspended_ports |= 1 << wIndex;
break;
case USB_PORT_FEAT_POWER:
xhci_writel(xhci, temp | PORT_POWER,
port_array[wIndex]);
temp = xhci_readl(xhci, port_array[wIndex]);
xhci_dbg(xhci, "set port power, actual port %d status = 0x%x\n", wIndex, temp);
spin_unlock_irqrestore(&xhci->lock, flags);
temp = usb_acpi_power_manageable(hcd->self.root_hub,
wIndex);
if (temp)
usb_acpi_set_power_state(hcd->self.root_hub,
wIndex, true);
spin_lock_irqsave(&xhci->lock, flags);
break;
case USB_PORT_FEAT_RESET:
temp = (temp | PORT_RESET);
xhci_writel(xhci, temp, port_array[wIndex]);
temp = xhci_readl(xhci, port_array[wIndex]);
xhci_dbg(xhci, "set port reset, actual port %d status = 0x%x\n", wIndex, temp);
break;
case USB_PORT_FEAT_REMOTE_WAKE_MASK:
xhci_set_remote_wake_mask(xhci, port_array,
wIndex, wake_mask);
temp = xhci_readl(xhci, port_array[wIndex]);
xhci_dbg(xhci, "set port remote wake mask, "
"actual port %d status = 0x%x\n",
wIndex, temp);
break;
case USB_PORT_FEAT_BH_PORT_RESET:
temp |= PORT_WR;
xhci_writel(xhci, temp, port_array[wIndex]);
temp = xhci_readl(xhci, port_array[wIndex]);
break;
case USB_PORT_FEAT_U1_TIMEOUT:
if (hcd->speed != HCD_USB3)
goto error;
temp = xhci_readl(xhci, port_array[wIndex] + PORTPMSC);
temp &= ~PORT_U1_TIMEOUT_MASK;
temp |= PORT_U1_TIMEOUT(timeout);
xhci_writel(xhci, temp, port_array[wIndex] + PORTPMSC);
break;
case USB_PORT_FEAT_U2_TIMEOUT:
if (hcd->speed != HCD_USB3)
goto error;
temp = xhci_readl(xhci, port_array[wIndex] + PORTPMSC);
temp &= ~PORT_U2_TIMEOUT_MASK;
temp |= PORT_U2_TIMEOUT(timeout);
xhci_writel(xhci, temp, port_array[wIndex] + PORTPMSC);
break;
default:
goto error;
}
temp = xhci_readl(xhci, port_array[wIndex]);
break;
case ClearPortFeature:
if (!wIndex || wIndex > max_ports)
goto error;
wIndex--;
temp = xhci_readl(xhci, port_array[wIndex]);
if (temp == 0xffffffff) {
retval = -ENODEV;
break;
}
temp = xhci_port_state_to_neutral(temp);
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
temp = xhci_readl(xhci, port_array[wIndex]);
xhci_dbg(xhci, "clear USB_PORT_FEAT_SUSPEND\n");
xhci_dbg(xhci, "PORTSC %04x\n", temp);
if (temp & PORT_RESET)
goto error;
if ((temp & PORT_PLS_MASK) == XDEV_U3) {
if ((temp & PORT_PE) == 0)
goto error;
xhci_set_link_state(xhci, port_array, wIndex,
XDEV_RESUME);
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(20);
spin_lock_irqsave(&xhci->lock, flags);
xhci_set_link_state(xhci, port_array, wIndex,
XDEV_U0);
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
xhci_clear_port_change_bit(xhci, wValue, wIndex,
port_array[wIndex], temp);
break;
case USB_PORT_FEAT_ENABLE:
xhci_disable_port(hcd, xhci, wIndex,
port_array[wIndex], temp);
break;
case USB_PORT_FEAT_POWER:
xhci_writel(xhci, temp & ~PORT_POWER,
port_array[wIndex]);
spin_unlock_irqrestore(&xhci->lock, flags);
temp = usb_acpi_power_manageable(hcd->self.root_hub,
wIndex);
if (temp)
usb_acpi_set_power_state(hcd->self.root_hub,
wIndex, false);
spin_lock_irqsave(&xhci->lock, flags);
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
mask = PORT_CSC | PORT_PEC | PORT_OCC | PORT_PLC | PORT_WRC;
spin_lock_irqsave(&xhci->lock, flags);
for (i = 0; i < max_ports; i++) {
temp = xhci_readl(xhci, port_array[i]);
if (temp == 0xffffffff) {
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
if (bus_state->resuming_ports) {
spin_unlock_irqrestore(&xhci->lock, flags);
xhci_dbg(xhci, "suspend failed because "
"a port is resuming\n");
return -EBUSY;
}
}
port_index = max_ports;
bus_state->bus_suspended = 0;
while (port_index--) {
u32 t1, t2;
int slot_id;
t1 = xhci_readl(xhci, port_array[port_index]);
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
xhci_writel(xhci, t2, port_array[port_index]);
if (hcd->speed != HCD_USB3) {
__le32 __iomem *addr;
u32 tmp;
addr = port_array[port_index] + PORTPMSC;
tmp = xhci_readl(xhci, addr);
tmp |= PORT_RWE;
xhci_writel(xhci, tmp, addr);
}
}
hcd->state = HC_STATE_SUSPENDED;
bus_state->next_statechange = jiffies + msecs_to_jiffies(10);
spin_unlock_irqrestore(&xhci->lock, flags);
return 0;
}
int xhci_bus_resume(struct usb_hcd *hcd)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
int max_ports, port_index;
__le32 __iomem **port_array;
struct xhci_bus_state *bus_state;
u32 temp;
unsigned long flags;
max_ports = xhci_get_ports(hcd, &port_array);
bus_state = &xhci->bus_state[hcd_index(hcd)];
if (time_before(jiffies, bus_state->next_statechange))
msleep(5);
spin_lock_irqsave(&xhci->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd)) {
spin_unlock_irqrestore(&xhci->lock, flags);
return -ESHUTDOWN;
}
temp = xhci_readl(xhci, &xhci->op_regs->command);
temp &= ~CMD_EIE;
xhci_writel(xhci, temp, &xhci->op_regs->command);
port_index = max_ports;
while (port_index--) {
u32 temp;
int slot_id;
temp = xhci_readl(xhci, port_array[port_index]);
if (DEV_SUPERSPEED(temp))
temp &= ~(PORT_RWC_BITS | PORT_CEC | PORT_WAKE_BITS);
else
temp &= ~(PORT_RWC_BITS | PORT_WAKE_BITS);
if (test_bit(port_index, &bus_state->bus_suspended) &&
(temp & PORT_PLS_MASK)) {
if (DEV_SUPERSPEED(temp)) {
xhci_set_link_state(xhci, port_array,
port_index, XDEV_U0);
} else {
xhci_set_link_state(xhci, port_array,
port_index, XDEV_RESUME);
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(20);
spin_lock_irqsave(&xhci->lock, flags);
xhci_set_link_state(xhci, port_array,
port_index, XDEV_U0);
}
spin_unlock_irqrestore(&xhci->lock, flags);
msleep(20);
spin_lock_irqsave(&xhci->lock, flags);
xhci_test_and_clear_bit(xhci, port_array, port_index,
PORT_PLC);
slot_id = xhci_find_slot_id_by_port(hcd,
xhci, port_index + 1);
if (slot_id)
xhci_ring_device(xhci, slot_id);
} else
xhci_writel(xhci, temp, port_array[port_index]);
if (hcd->speed != HCD_USB3) {
__le32 __iomem *addr;
u32 tmp;
addr = port_array[port_index] + PORTPMSC;
tmp = xhci_readl(xhci, addr);
tmp &= ~PORT_RWE;
xhci_writel(xhci, tmp, addr);
}
}
(void) xhci_readl(xhci, &xhci->op_regs->command);
bus_state->next_statechange = jiffies + msecs_to_jiffies(5);
temp = xhci_readl(xhci, &xhci->op_regs->command);
temp |= CMD_EIE;
xhci_writel(xhci, temp, &xhci->op_regs->command);
temp = xhci_readl(xhci, &xhci->op_regs->command);
spin_unlock_irqrestore(&xhci->lock, flags);
return 0;
}
