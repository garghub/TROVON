static void dbgp_ehci_status(char *str)
{
if (!ehci_debug)
return;
dbgp_printk("dbgp: %s\n", str);
dbgp_printk(" Debug control: %08x", readl(&ehci_debug->control));
dbgp_printk(" ehci cmd : %08x", readl(&ehci_regs->command));
dbgp_printk(" ehci conf flg: %08x\n",
readl(&ehci_regs->configured_flag));
dbgp_printk(" ehci status : %08x", readl(&ehci_regs->status));
dbgp_printk(" ehci portsc : %08x\n",
readl(&ehci_regs->port_status[dbgp_phys_port - 1]));
}
static inline void dbgp_ehci_status(char *str) { }
static inline void dbgp_printk(const char *fmt, ...) { }
static inline u32 dbgp_len_update(u32 x, u32 len)
{
return (x & ~0x0f) | (len & 0x0f);
}
static inline u32 dbgp_pid_write_update(u32 x, u32 tok)
{
static int data0 = USB_PID_DATA1;
data0 ^= USB_PID_DATA_TOGGLE;
return (x & 0xffff0000) | (data0 << 8) | (tok & 0xff);
}
static inline u32 dbgp_pid_read_update(u32 x, u32 tok)
{
return (x & 0xffff0000) | (USB_PID_DATA0 << 8) | (tok & 0xff);
}
static int dbgp_wait_until_complete(void)
{
u32 ctrl;
int loop = DBGP_TIMEOUT;
do {
ctrl = readl(&ehci_debug->control);
if (ctrl & DBGP_DONE)
break;
udelay(1);
} while (--loop > 0);
if (!loop)
return -DBGP_TIMEOUT;
writel(ctrl | DBGP_DONE, &ehci_debug->control);
return (ctrl & DBGP_ERROR) ? -DBGP_ERRCODE(ctrl) : DBGP_LEN(ctrl);
}
static inline void dbgp_mdelay(int ms)
{
int i;
while (ms--) {
for (i = 0; i < 1000; i++)
outb(0x1, 0x80);
}
}
static void dbgp_breath(void)
{
}
static int dbgp_wait_until_done(unsigned ctrl, int loop)
{
u32 pids, lpid;
int ret;
retry:
writel(ctrl | DBGP_GO, &ehci_debug->control);
ret = dbgp_wait_until_complete();
pids = readl(&ehci_debug->pids);
lpid = DBGP_PID_GET(pids);
if (ret < 0) {
if (ret == -DBGP_TIMEOUT && !dbgp_not_safe)
dbgp_not_safe = 1;
if (ret == -DBGP_ERR_BAD && --loop > 0)
goto retry;
return ret;
}
if ((lpid == USB_PID_NAK) || (lpid == USB_PID_NYET))
dbgp_breath();
if (lpid == USB_PID_NAK) {
if (--loop > 0)
goto retry;
}
return ret;
}
static inline void dbgp_set_data(const void *buf, int size)
{
const unsigned char *bytes = buf;
u32 lo, hi;
int i;
lo = hi = 0;
for (i = 0; i < 4 && i < size; i++)
lo |= bytes[i] << (8*i);
for (; i < 8 && i < size; i++)
hi |= bytes[i] << (8*(i - 4));
writel(lo, &ehci_debug->data03);
writel(hi, &ehci_debug->data47);
}
static inline void dbgp_get_data(void *buf, int size)
{
unsigned char *bytes = buf;
u32 lo, hi;
int i;
lo = readl(&ehci_debug->data03);
hi = readl(&ehci_debug->data47);
for (i = 0; i < 4 && i < size; i++)
bytes[i] = (lo >> (8*i)) & 0xff;
for (; i < 8 && i < size; i++)
bytes[i] = (hi >> (8*(i - 4))) & 0xff;
}
static int dbgp_bulk_write(unsigned devnum, unsigned endpoint,
const char *bytes, int size)
{
int ret;
u32 addr;
u32 pids, ctrl;
if (size > DBGP_MAX_PACKET)
return -1;
addr = DBGP_EPADDR(devnum, endpoint);
pids = readl(&ehci_debug->pids);
pids = dbgp_pid_write_update(pids, USB_PID_OUT);
ctrl = readl(&ehci_debug->control);
ctrl = dbgp_len_update(ctrl, size);
ctrl |= DBGP_OUT;
ctrl |= DBGP_GO;
dbgp_set_data(bytes, size);
writel(addr, &ehci_debug->address);
writel(pids, &ehci_debug->pids);
ret = dbgp_wait_until_done(ctrl, DBGP_LOOPS);
return ret;
}
static int dbgp_bulk_read(unsigned devnum, unsigned endpoint, void *data,
int size, int loops)
{
u32 pids, addr, ctrl;
int ret;
if (size > DBGP_MAX_PACKET)
return -1;
addr = DBGP_EPADDR(devnum, endpoint);
pids = readl(&ehci_debug->pids);
pids = dbgp_pid_read_update(pids, USB_PID_IN);
ctrl = readl(&ehci_debug->control);
ctrl = dbgp_len_update(ctrl, size);
ctrl &= ~DBGP_OUT;
ctrl |= DBGP_GO;
writel(addr, &ehci_debug->address);
writel(pids, &ehci_debug->pids);
ret = dbgp_wait_until_done(ctrl, loops);
if (ret < 0)
return ret;
if (size > ret)
size = ret;
dbgp_get_data(data, size);
return ret;
}
static int dbgp_control_msg(unsigned devnum, int requesttype,
int request, int value, int index, void *data, int size)
{
u32 pids, addr, ctrl;
struct usb_ctrlrequest req;
int read;
int ret;
read = (requesttype & USB_DIR_IN) != 0;
if (size > (read ? DBGP_MAX_PACKET:0))
return -1;
req.bRequestType = requesttype;
req.bRequest = request;
req.wValue = cpu_to_le16(value);
req.wIndex = cpu_to_le16(index);
req.wLength = cpu_to_le16(size);
pids = DBGP_PID_SET(USB_PID_DATA0, USB_PID_SETUP);
addr = DBGP_EPADDR(devnum, 0);
ctrl = readl(&ehci_debug->control);
ctrl = dbgp_len_update(ctrl, sizeof(req));
ctrl |= DBGP_OUT;
ctrl |= DBGP_GO;
dbgp_set_data(&req, sizeof(req));
writel(addr, &ehci_debug->address);
writel(pids, &ehci_debug->pids);
ret = dbgp_wait_until_done(ctrl, DBGP_LOOPS);
if (ret < 0)
return ret;
return dbgp_bulk_read(devnum, 0, data, size, DBGP_LOOPS);
}
static u32 __init find_cap(u32 num, u32 slot, u32 func, int cap)
{
u8 pos;
int bytes;
if (!(read_pci_config_16(num, slot, func, PCI_STATUS) &
PCI_STATUS_CAP_LIST))
return 0;
pos = read_pci_config_byte(num, slot, func, PCI_CAPABILITY_LIST);
for (bytes = 0; bytes < 48 && pos >= 0x40; bytes++) {
u8 id;
pos &= ~3;
id = read_pci_config_byte(num, slot, func, pos+PCI_CAP_LIST_ID);
if (id == 0xff)
break;
if (id == cap)
return pos;
pos = read_pci_config_byte(num, slot, func,
pos+PCI_CAP_LIST_NEXT);
}
return 0;
}
static u32 __init __find_dbgp(u32 bus, u32 slot, u32 func)
{
u32 class;
class = read_pci_config(bus, slot, func, PCI_CLASS_REVISION);
if ((class >> 8) != PCI_CLASS_SERIAL_USB_EHCI)
return 0;
return find_cap(bus, slot, func, PCI_CAP_ID_EHCI_DEBUG);
}
static u32 __init find_dbgp(int ehci_num, u32 *rbus, u32 *rslot, u32 *rfunc)
{
u32 bus, slot, func;
for (bus = 0; bus < 256; bus++) {
for (slot = 0; slot < 32; slot++) {
for (func = 0; func < 8; func++) {
unsigned cap;
cap = __find_dbgp(bus, slot, func);
if (!cap)
continue;
if (ehci_num-- != 0)
continue;
*rbus = bus;
*rslot = slot;
*rfunc = func;
return cap;
}
}
}
return 0;
}
static int dbgp_ehci_startup(void)
{
u32 ctrl, cmd, status;
int loop;
ctrl = readl(&ehci_debug->control);
ctrl |= DBGP_OWNER;
ctrl &= ~(DBGP_ENABLED | DBGP_INUSE);
writel(ctrl, &ehci_debug->control);
udelay(1);
dbgp_ehci_status("EHCI startup");
cmd = readl(&ehci_regs->command);
cmd &= ~(CMD_LRESET | CMD_IAAD | CMD_PSE | CMD_ASE | CMD_RESET);
cmd |= CMD_RUN;
writel(cmd, &ehci_regs->command);
writel(FLAG_CF, &ehci_regs->configured_flag);
loop = 10;
do {
status = readl(&ehci_regs->status);
if (!(status & STS_HALT))
break;
udelay(1);
} while (--loop > 0);
if (!loop) {
dbgp_printk("ehci can not be started\n");
return -ENODEV;
}
dbgp_printk("ehci started\n");
return 0;
}
static int dbgp_ehci_controller_reset(void)
{
int loop = 250 * 1000;
u32 cmd;
cmd = readl(&ehci_regs->command);
cmd |= CMD_RESET;
writel(cmd, &ehci_regs->command);
do {
cmd = readl(&ehci_regs->command);
} while ((cmd & CMD_RESET) && (--loop > 0));
if (!loop) {
dbgp_printk("can not reset ehci\n");
return -1;
}
dbgp_ehci_status("ehci reset done");
return 0;
}
int dbgp_external_startup(void)
{
int devnum;
struct usb_debug_descriptor dbgp_desc;
int ret;
u32 ctrl, portsc, cmd;
int dbg_port = dbgp_phys_port;
int tries = 3;
int reset_port_tries = 1;
int try_hard_once = 1;
try_port_reset_again:
ret = dbgp_ehci_startup();
if (ret)
return ret;
ret = ehci_wait_for_port(dbg_port);
if (ret < 0) {
portsc = readl(&ehci_regs->port_status[dbg_port - 1]);
if (!(portsc & PORT_CONNECT) && try_hard_once) {
try_hard_once = 0;
cmd = readl(&ehci_regs->command);
cmd &= ~CMD_RUN;
writel(cmd, &ehci_regs->command);
portsc = readl(&ehci_regs->port_status[dbg_port - 1]);
portsc |= PORT_TEST_PKT;
writel(portsc, &ehci_regs->port_status[dbg_port - 1]);
dbgp_ehci_status("Trying to force debug port online");
mdelay(50);
dbgp_ehci_controller_reset();
goto try_port_reset_again;
} else if (reset_port_tries--) {
goto try_port_reset_again;
}
dbgp_printk("No device found in debug port\n");
return -EIO;
}
dbgp_ehci_status("wait for port done");
ctrl = readl(&ehci_debug->control);
ctrl |= DBGP_CLAIM;
writel(ctrl, &ehci_debug->control);
ctrl = readl(&ehci_debug->control);
if ((ctrl & DBGP_CLAIM) != DBGP_CLAIM) {
dbgp_printk("No device in debug port\n");
writel(ctrl & ~DBGP_CLAIM, &ehci_debug->control);
return -ENODEV;
}
dbgp_ehci_status("debug ported enabled");
portsc = readl(&ehci_regs->port_status[dbg_port - 1]);
portsc &= ~PORT_PE;
writel(portsc, &ehci_regs->port_status[dbg_port - 1]);
dbgp_mdelay(100);
try_again:
for (devnum = 0; devnum <= 127; devnum++) {
ret = dbgp_control_msg(devnum,
USB_DIR_IN | USB_TYPE_STANDARD | USB_RECIP_DEVICE,
USB_REQ_GET_DESCRIPTOR, (USB_DT_DEBUG << 8), 0,
&dbgp_desc, sizeof(dbgp_desc));
if (ret > 0)
break;
}
if (devnum > 127) {
dbgp_printk("Could not find attached debug device\n");
goto err;
}
if (ret < 0) {
dbgp_printk("Attached device is not a debug device\n");
goto err;
}
dbgp_endpoint_out = dbgp_desc.bDebugOutEndpoint;
dbgp_endpoint_in = dbgp_desc.bDebugInEndpoint;
if (devnum != USB_DEBUG_DEVNUM) {
ret = dbgp_control_msg(devnum,
USB_DIR_OUT | USB_TYPE_STANDARD | USB_RECIP_DEVICE,
USB_REQ_SET_ADDRESS, USB_DEBUG_DEVNUM, 0, NULL, 0);
if (ret < 0) {
dbgp_printk("Could not move attached device to %d\n",
USB_DEBUG_DEVNUM);
goto err;
}
devnum = USB_DEBUG_DEVNUM;
dbgp_printk("debug device renamed to 127\n");
}
ret = dbgp_control_msg(USB_DEBUG_DEVNUM,
USB_DIR_OUT | USB_TYPE_STANDARD | USB_RECIP_DEVICE,
USB_REQ_SET_FEATURE, USB_DEVICE_DEBUG_MODE, 0, NULL, 0);
if (ret < 0) {
dbgp_printk(" Could not enable the debug device\n");
goto err;
}
dbgp_printk("debug interface enabled\n");
ret = dbgp_bulk_write(USB_DEBUG_DEVNUM, dbgp_endpoint_out, " ", 1);
if (ret < 0) {
dbgp_printk("dbgp_bulk_write failed: %d\n", ret);
goto err;
}
dbgp_printk("small write done\n");
dbgp_not_safe = 0;
return 0;
err:
if (tries--)
goto try_again;
return -ENODEV;
}
static int ehci_reset_port(int port)
{
u32 portsc;
u32 delay_time, delay;
int loop;
dbgp_ehci_status("reset port");
portsc = readl(&ehci_regs->port_status[port - 1]);
portsc &= ~PORT_PE;
portsc |= PORT_RESET;
writel(portsc, &ehci_regs->port_status[port - 1]);
delay = HUB_ROOT_RESET_TIME;
for (delay_time = 0; delay_time < HUB_RESET_TIMEOUT;
delay_time += delay) {
dbgp_mdelay(delay);
portsc = readl(&ehci_regs->port_status[port - 1]);
if (!(portsc & PORT_RESET))
break;
}
if (portsc & PORT_RESET) {
loop = 100 * 1000;
writel(portsc & ~(PORT_RWC_BITS | PORT_RESET),
&ehci_regs->port_status[port - 1]);
do {
udelay(1);
portsc = readl(&ehci_regs->port_status[port-1]);
} while ((portsc & PORT_RESET) && (--loop > 0));
}
if (!(portsc & PORT_CONNECT))
return -ENOTCONN;
if ((portsc & PORT_CSC))
return -EINVAL;
if (!(portsc & PORT_RESET) && (portsc & PORT_PE))
return 0;
return -EBUSY;
}
static int ehci_wait_for_port(int port)
{
u32 status;
int ret, reps;
for (reps = 0; reps < 300; reps++) {
status = readl(&ehci_regs->status);
if (status & STS_PCD)
break;
dbgp_mdelay(1);
}
ret = ehci_reset_port(port);
if (ret == 0)
return 0;
return -ENOTCONN;
}
static void __init default_set_debug_port(int port)
{
}
static void __init nvidia_set_debug_port(int port)
{
u32 dword;
dword = read_pci_config(ehci_dev.bus, ehci_dev.slot, ehci_dev.func,
0x74);
dword &= ~(0x0f<<12);
dword |= ((port & 0x0f)<<12);
write_pci_config(ehci_dev.bus, ehci_dev.slot, ehci_dev.func, 0x74,
dword);
dbgp_printk("set debug port to %d\n", port);
}
static void __init detect_set_debug_port(void)
{
u32 vendorid;
vendorid = read_pci_config(ehci_dev.bus, ehci_dev.slot, ehci_dev.func,
0x00);
if ((vendorid & 0xffff) == 0x10de) {
dbgp_printk("using nvidia set_debug_port\n");
set_debug_port = nvidia_set_debug_port;
}
}
static void __init early_ehci_bios_handoff(void)
{
u32 hcc_params = readl(&ehci_caps->hcc_params);
int offset = (hcc_params >> 8) & 0xff;
u32 cap;
int msec;
if (!offset)
return;
cap = read_pci_config(ehci_dev.bus, ehci_dev.slot,
ehci_dev.func, offset);
dbgp_printk("dbgp: ehci BIOS state %08x\n", cap);
if ((cap & 0xff) == 1 && (cap & EHCI_USBLEGSUP_BIOS)) {
dbgp_printk("dbgp: BIOS handoff\n");
write_pci_config_byte(ehci_dev.bus, ehci_dev.slot,
ehci_dev.func, offset + 3, 1);
}
msec = 1000;
while ((cap & EHCI_USBLEGSUP_BIOS) && (msec > 0)) {
mdelay(10);
msec -= 10;
cap = read_pci_config(ehci_dev.bus, ehci_dev.slot,
ehci_dev.func, offset);
}
if (cap & EHCI_USBLEGSUP_BIOS) {
dbgp_printk("dbgp: BIOS handoff failed: %08x\n", cap);
write_pci_config_byte(ehci_dev.bus, ehci_dev.slot,
ehci_dev.func, offset + 2, 0);
}
write_pci_config_byte(ehci_dev.bus, ehci_dev.slot, ehci_dev.func,
offset + EHCI_USBLEGCTLSTS, 0);
}
static int __init ehci_setup(void)
{
u32 ctrl, portsc, hcs_params;
u32 debug_port, new_debug_port = 0, n_ports;
int ret, i;
int port_map_tried;
int playtimes = 3;
early_ehci_bios_handoff();
try_next_time:
port_map_tried = 0;
try_next_port:
hcs_params = readl(&ehci_caps->hcs_params);
debug_port = HCS_DEBUG_PORT(hcs_params);
dbgp_phys_port = debug_port;
n_ports = HCS_N_PORTS(hcs_params);
dbgp_printk("debug_port: %d\n", debug_port);
dbgp_printk("n_ports: %d\n", n_ports);
dbgp_ehci_status("");
for (i = 1; i <= n_ports; i++) {
portsc = readl(&ehci_regs->port_status[i-1]);
dbgp_printk("portstatus%d: %08x\n", i, portsc);
}
if (port_map_tried && (new_debug_port != debug_port)) {
if (--playtimes) {
set_debug_port(new_debug_port);
goto try_next_time;
}
return -1;
}
if (!(readl(&ehci_regs->configured_flag) & FLAG_CF)) {
if (dbgp_ehci_controller_reset() != 0)
return -1;
} else {
dbgp_ehci_status("ehci skip - already configured");
}
ret = dbgp_external_startup();
if (ret == -EIO)
goto next_debug_port;
if (ret < 0) {
ctrl = readl(&ehci_debug->control);
ctrl &= ~(DBGP_CLAIM | DBGP_OUT);
writel(ctrl, &ehci_debug->control);
return -1;
}
return 0;
next_debug_port:
port_map_tried |= (1<<(debug_port - 1));
new_debug_port = ((debug_port-1+1)%n_ports) + 1;
if (port_map_tried != ((1<<n_ports) - 1)) {
set_debug_port(new_debug_port);
goto try_next_port;
}
if (--playtimes) {
set_debug_port(new_debug_port);
goto try_next_time;
}
return -1;
}
int __init early_dbgp_init(char *s)
{
u32 debug_port, bar, offset;
u32 bus, slot, func, cap;
void __iomem *ehci_bar;
u32 dbgp_num;
u32 bar_val;
char *e;
int ret;
u8 byte;
if (!early_pci_allowed())
return -1;
dbgp_num = 0;
if (*s)
dbgp_num = simple_strtoul(s, &e, 10);
dbgp_printk("dbgp_num: %d\n", dbgp_num);
cap = find_dbgp(dbgp_num, &bus, &slot, &func);
if (!cap)
return -1;
dbgp_printk("Found EHCI debug port on %02x:%02x.%1x\n", bus, slot,
func);
debug_port = read_pci_config(bus, slot, func, cap);
bar = (debug_port >> 29) & 0x7;
bar = (bar * 4) + 0xc;
offset = (debug_port >> 16) & 0xfff;
dbgp_printk("bar: %02x offset: %03x\n", bar, offset);
if (bar != PCI_BASE_ADDRESS_0) {
dbgp_printk("only debug ports on bar 1 handled.\n");
return -1;
}
bar_val = read_pci_config(bus, slot, func, PCI_BASE_ADDRESS_0);
dbgp_printk("bar_val: %02x offset: %03x\n", bar_val, offset);
if (bar_val & ~PCI_BASE_ADDRESS_MEM_MASK) {
dbgp_printk("only simple 32bit mmio bars supported\n");
return -1;
}
byte = read_pci_config_byte(bus, slot, func, 0x04);
if (!(byte & 0x2)) {
byte |= 0x02;
write_pci_config_byte(bus, slot, func, 0x04, byte);
dbgp_printk("mmio for ehci enabled\n");
}
set_fixmap_nocache(FIX_DBGP_BASE, bar_val & PAGE_MASK);
ehci_bar = (void __iomem *)__fix_to_virt(FIX_DBGP_BASE);
ehci_bar += bar_val & ~PAGE_MASK;
dbgp_printk("ehci_bar: %p\n", ehci_bar);
ehci_caps = ehci_bar;
ehci_regs = ehci_bar + EARLY_HC_LENGTH(readl(&ehci_caps->hc_capbase));
ehci_debug = ehci_bar + offset;
ehci_dev.bus = bus;
ehci_dev.slot = slot;
ehci_dev.func = func;
detect_set_debug_port();
ret = ehci_setup();
if (ret < 0) {
dbgp_printk("ehci_setup failed\n");
ehci_debug = NULL;
return -1;
}
dbgp_ehci_status("early_init_complete");
return 0;
}
static void early_dbgp_write(struct console *con, const char *str, u32 n)
{
int chunk, ret;
char buf[DBGP_MAX_PACKET];
int use_cr = 0;
u32 cmd, ctrl;
int reset_run = 0;
if (!ehci_debug || dbgp_not_safe)
return;
cmd = readl(&ehci_regs->command);
if (unlikely(!(cmd & CMD_RUN))) {
ctrl = readl(&ehci_debug->control);
if (!(ctrl & DBGP_ENABLED)) {
dbgp_not_safe = 1;
dbgp_external_startup();
} else {
cmd |= CMD_RUN;
writel(cmd, &ehci_regs->command);
reset_run = 1;
}
}
while (n > 0) {
for (chunk = 0; chunk < DBGP_MAX_PACKET && n > 0;
str++, chunk++, n--) {
if (!use_cr && *str == '\n') {
use_cr = 1;
buf[chunk] = '\r';
str--;
n++;
continue;
}
if (use_cr)
use_cr = 0;
buf[chunk] = *str;
}
if (chunk > 0) {
ret = dbgp_bulk_write(USB_DEBUG_DEVNUM,
dbgp_endpoint_out, buf, chunk);
}
}
if (unlikely(reset_run)) {
cmd = readl(&ehci_regs->command);
cmd &= ~CMD_RUN;
writel(cmd, &ehci_regs->command);
}
}
int dbgp_reset_prep(void)
{
u32 ctrl;
dbgp_not_safe = 1;
if (!ehci_debug)
return 0;
if ((early_dbgp_console.index != -1 &&
!(early_dbgp_console.flags & CON_BOOT)) ||
dbgp_kgdb_mode)
return 1;
ctrl = readl(&ehci_debug->control);
if (ctrl & DBGP_ENABLED) {
ctrl &= ~(DBGP_CLAIM);
writel(ctrl, &ehci_debug->control);
}
return 0;
}
static int kgdbdbgp_read_char(void)
{
int ret;
if (kgdbdbgp_buf_idx < kgdbdbgp_buf_sz) {
char ch = kgdbdbgp_buf[kgdbdbgp_buf_idx++];
return ch;
}
ret = dbgp_bulk_read(USB_DEBUG_DEVNUM, dbgp_endpoint_in,
&kgdbdbgp_buf, DBGP_MAX_PACKET,
kgdbdbgp_loop_cnt);
if (ret <= 0)
return NO_POLL_CHAR;
kgdbdbgp_buf_sz = ret;
kgdbdbgp_buf_idx = 1;
return kgdbdbgp_buf[0];
}
static void kgdbdbgp_write_char(u8 chr)
{
early_dbgp_write(NULL, &chr, 1);
}
static int __init kgdbdbgp_parse_config(char *str)
{
char *ptr;
if (!ehci_debug) {
if (early_dbgp_init(str))
return -1;
}
ptr = strchr(str, ',');
if (ptr) {
ptr++;
kgdbdbgp_wait_time = simple_strtoul(ptr, &ptr, 10);
}
kgdb_register_io_module(&kgdbdbgp_io_ops);
kgdbdbgp_io_ops.is_console = early_dbgp_console.index != -1;
return 0;
}
static int kgdbdbgp_reader_thread(void *ptr)
{
int ret;
while (readl(&ehci_debug->control) & DBGP_ENABLED) {
kgdbdbgp_loop_cnt = 1;
ret = kgdbdbgp_read_char();
kgdbdbgp_loop_cnt = DBGP_LOOPS;
if (ret != NO_POLL_CHAR) {
if (ret == 0x3 || ret == '$') {
if (ret == '$')
kgdbdbgp_buf_idx--;
kgdb_breakpoint();
}
continue;
}
schedule_timeout_interruptible(kgdbdbgp_wait_time * HZ);
}
return 0;
}
static int __init kgdbdbgp_start_thread(void)
{
if (dbgp_kgdb_mode && kgdbdbgp_wait_time)
kthread_run(kgdbdbgp_reader_thread, NULL, "%s", "dbgp");
return 0;
}
