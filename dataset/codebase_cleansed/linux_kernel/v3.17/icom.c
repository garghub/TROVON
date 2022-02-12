static inline void trace(struct icom_port *icom_port, char *trace_pt,
unsigned long trace_data)
{
dev_info(&icom_port->adapter->pci_dev->dev, ":%d:%s - %lx\n",
icom_port->port, trace_pt, trace_data);
}
static inline void trace(struct icom_port *icom_port, char *trace_pt, unsigned long trace_data) {}
static void free_port_memory(struct icom_port *icom_port)
{
struct pci_dev *dev = icom_port->adapter->pci_dev;
trace(icom_port, "RET_PORT_MEM", 0);
if (icom_port->recv_buf) {
pci_free_consistent(dev, 4096, icom_port->recv_buf,
icom_port->recv_buf_pci);
icom_port->recv_buf = NULL;
}
if (icom_port->xmit_buf) {
pci_free_consistent(dev, 4096, icom_port->xmit_buf,
icom_port->xmit_buf_pci);
icom_port->xmit_buf = NULL;
}
if (icom_port->statStg) {
pci_free_consistent(dev, 4096, icom_port->statStg,
icom_port->statStg_pci);
icom_port->statStg = NULL;
}
if (icom_port->xmitRestart) {
pci_free_consistent(dev, 4096, icom_port->xmitRestart,
icom_port->xmitRestart_pci);
icom_port->xmitRestart = NULL;
}
}
static int get_port_memory(struct icom_port *icom_port)
{
int index;
unsigned long stgAddr;
unsigned long startStgAddr;
unsigned long offset;
struct pci_dev *dev = icom_port->adapter->pci_dev;
icom_port->xmit_buf =
pci_alloc_consistent(dev, 4096, &icom_port->xmit_buf_pci);
if (!icom_port->xmit_buf) {
dev_err(&dev->dev, "Can not allocate Transmit buffer\n");
return -ENOMEM;
}
trace(icom_port, "GET_PORT_MEM",
(unsigned long) icom_port->xmit_buf);
icom_port->recv_buf =
pci_alloc_consistent(dev, 4096, &icom_port->recv_buf_pci);
if (!icom_port->recv_buf) {
dev_err(&dev->dev, "Can not allocate Receive buffer\n");
free_port_memory(icom_port);
return -ENOMEM;
}
trace(icom_port, "GET_PORT_MEM",
(unsigned long) icom_port->recv_buf);
icom_port->statStg =
pci_alloc_consistent(dev, 4096, &icom_port->statStg_pci);
if (!icom_port->statStg) {
dev_err(&dev->dev, "Can not allocate Status buffer\n");
free_port_memory(icom_port);
return -ENOMEM;
}
trace(icom_port, "GET_PORT_MEM",
(unsigned long) icom_port->statStg);
icom_port->xmitRestart =
pci_alloc_consistent(dev, 4096, &icom_port->xmitRestart_pci);
if (!icom_port->xmitRestart) {
dev_err(&dev->dev,
"Can not allocate xmit Restart buffer\n");
free_port_memory(icom_port);
return -ENOMEM;
}
memset(icom_port->statStg, 0, 4096);
stgAddr = (unsigned long) icom_port->statStg;
for (index = 0; index < NUM_XBUFFS; index++) {
trace(icom_port, "FOD_ADDR", stgAddr);
stgAddr = stgAddr + sizeof(icom_port->statStg->xmit[0]);
if (index < (NUM_XBUFFS - 1)) {
memset(&icom_port->statStg->xmit[index], 0, sizeof(struct xmit_status_area));
icom_port->statStg->xmit[index].leLengthASD =
(unsigned short int) cpu_to_le16(XMIT_BUFF_SZ);
trace(icom_port, "FOD_ADDR", stgAddr);
trace(icom_port, "FOD_XBUFF",
(unsigned long) icom_port->xmit_buf);
icom_port->statStg->xmit[index].leBuffer =
cpu_to_le32(icom_port->xmit_buf_pci);
} else if (index == (NUM_XBUFFS - 1)) {
memset(&icom_port->statStg->xmit[index], 0, sizeof(struct xmit_status_area));
icom_port->statStg->xmit[index].leLengthASD =
(unsigned short int) cpu_to_le16(XMIT_BUFF_SZ);
trace(icom_port, "FOD_XBUFF",
(unsigned long) icom_port->xmit_buf);
icom_port->statStg->xmit[index].leBuffer =
cpu_to_le32(icom_port->xmit_buf_pci);
} else {
memset(&icom_port->statStg->xmit[index], 0, sizeof(struct xmit_status_area));
}
}
startStgAddr = stgAddr;
for (index = 0; index < NUM_RBUFFS; index++) {
trace(icom_port, "FID_ADDR", stgAddr);
stgAddr = stgAddr + sizeof(icom_port->statStg->rcv[0]);
icom_port->statStg->rcv[index].leLength = 0;
icom_port->statStg->rcv[index].WorkingLength =
(unsigned short int) cpu_to_le16(RCV_BUFF_SZ);
if (index < (NUM_RBUFFS - 1) ) {
offset = stgAddr - (unsigned long) icom_port->statStg;
icom_port->statStg->rcv[index].leNext =
cpu_to_le32(icom_port-> statStg_pci + offset);
trace(icom_port, "FID_RBUFF",
(unsigned long) icom_port->recv_buf);
icom_port->statStg->rcv[index].leBuffer =
cpu_to_le32(icom_port->recv_buf_pci);
} else if (index == (NUM_RBUFFS -1) ) {
offset = startStgAddr - (unsigned long) icom_port->statStg;
icom_port->statStg->rcv[index].leNext =
cpu_to_le32(icom_port-> statStg_pci + offset);
trace(icom_port, "FID_RBUFF",
(unsigned long) icom_port->recv_buf + 2048);
icom_port->statStg->rcv[index].leBuffer =
cpu_to_le32(icom_port->recv_buf_pci + 2048);
} else {
icom_port->statStg->rcv[index].leNext = 0;
icom_port->statStg->rcv[index].leBuffer = 0;
}
}
return 0;
}
static void stop_processor(struct icom_port *icom_port)
{
unsigned long temp;
unsigned long flags;
int port;
spin_lock_irqsave(&icom_lock, flags);
port = icom_port->port;
if (port >= ARRAY_SIZE(stop_proc)) {
dev_err(&icom_port->adapter->pci_dev->dev,
"Invalid port assignment\n");
goto unlock;
}
if (port == 0 || port == 1)
stop_proc[port].global_control_reg = &icom_port->global_reg->control;
else
stop_proc[port].global_control_reg = &icom_port->global_reg->control_2;
temp = readl(stop_proc[port].global_control_reg);
temp = (temp & ~start_proc[port].processor_id) | stop_proc[port].processor_id;
writel(temp, stop_proc[port].global_control_reg);
readl(stop_proc[port].global_control_reg);
unlock:
spin_unlock_irqrestore(&icom_lock, flags);
}
static void start_processor(struct icom_port *icom_port)
{
unsigned long temp;
unsigned long flags;
int port;
spin_lock_irqsave(&icom_lock, flags);
port = icom_port->port;
if (port >= ARRAY_SIZE(start_proc)) {
dev_err(&icom_port->adapter->pci_dev->dev,
"Invalid port assignment\n");
goto unlock;
}
if (port == 0 || port == 1)
start_proc[port].global_control_reg = &icom_port->global_reg->control;
else
start_proc[port].global_control_reg = &icom_port->global_reg->control_2;
temp = readl(start_proc[port].global_control_reg);
temp = (temp & ~stop_proc[port].processor_id) | start_proc[port].processor_id;
writel(temp, start_proc[port].global_control_reg);
readl(start_proc[port].global_control_reg);
unlock:
spin_unlock_irqrestore(&icom_lock, flags);
}
static void load_code(struct icom_port *icom_port)
{
const struct firmware *fw;
char __iomem *iram_ptr;
int index;
int status = 0;
void __iomem *dram_ptr = icom_port->dram;
dma_addr_t temp_pci;
unsigned char *new_page = NULL;
unsigned char cable_id = NO_CABLE;
struct pci_dev *dev = icom_port->adapter->pci_dev;
writew(0x3FFF, icom_port->int_reg);
trace(icom_port, "CLEAR_INTERRUPTS", 0);
stop_processor(icom_port);
memset_io(dram_ptr, 0, 512);
if (request_firmware(&fw, "icom_call_setup.bin", &dev->dev) < 0) {
dev_err(&dev->dev,"Unable to load icom_call_setup.bin firmware image\n");
status = -1;
goto load_code_exit;
}
if (fw->size > ICOM_DCE_IRAM_OFFSET) {
dev_err(&dev->dev, "Invalid firmware image for icom_call_setup.bin found.\n");
release_firmware(fw);
status = -1;
goto load_code_exit;
}
iram_ptr = (char __iomem *)icom_port->dram + ICOM_IRAM_OFFSET;
for (index = 0; index < fw->size; index++)
writeb(fw->data[index], &iram_ptr[index]);
release_firmware(fw);
if (request_firmware(&fw, "icom_res_dce.bin", &dev->dev) < 0) {
dev_err(&dev->dev,"Unable to load icom_res_dce.bin firmware image\n");
status = -1;
goto load_code_exit;
}
if (fw->size > ICOM_IRAM_SIZE) {
dev_err(&dev->dev, "Invalid firmware image for icom_res_dce.bin found.\n");
release_firmware(fw);
status = -1;
goto load_code_exit;
}
iram_ptr = (char __iomem *) icom_port->dram + ICOM_IRAM_OFFSET;
for (index = ICOM_DCE_IRAM_OFFSET; index < fw->size; index++)
writeb(fw->data[index], &iram_ptr[index]);
release_firmware(fw);
if (icom_port->adapter->version == ADAPTER_V2)
writeb(V2_HARDWARE, &(icom_port->dram->misc_flags));
start_processor(icom_port);
writeb((HDLC_PPP_PURE_ASYNC | HDLC_FF_FILL),
&(icom_port->dram->HDLCConfigReg));
writeb(0x04, &(icom_port->dram->FlagFillIdleTimer));
writeb(0x00, &(icom_port->dram->CmdReg));
writeb(0x10, &(icom_port->dram->async_config3));
writeb((ICOM_ACFG_DRIVE1 | ICOM_ACFG_NO_PARITY | ICOM_ACFG_8BPC |
ICOM_ACFG_1STOP_BIT), &(icom_port->dram->async_config2));
new_page = pci_alloc_consistent(dev, 4096, &temp_pci);
if (!new_page) {
dev_err(&dev->dev, "Can not allocate DMA buffer\n");
status = -1;
goto load_code_exit;
}
if (request_firmware(&fw, "icom_asc.bin", &dev->dev) < 0) {
dev_err(&dev->dev,"Unable to load icom_asc.bin firmware image\n");
status = -1;
goto load_code_exit;
}
if (fw->size > ICOM_DCE_IRAM_OFFSET) {
dev_err(&dev->dev, "Invalid firmware image for icom_asc.bin found.\n");
release_firmware(fw);
status = -1;
goto load_code_exit;
}
for (index = 0; index < fw->size; index++)
new_page[index] = fw->data[index];
writeb((char) ((fw->size + 16)/16), &icom_port->dram->mac_length);
writel(temp_pci, &icom_port->dram->mac_load_addr);
release_firmware(fw);
writeb(START_DOWNLOAD, &icom_port->dram->sync);
for (index = 0; index < 10; index++) {
msleep(100);
if (readb(&icom_port->dram->misc_flags) & ICOM_HDW_ACTIVE)
break;
}
if (index == 10)
status = -1;
cable_id = readb(&icom_port->dram->cable_id);
if (cable_id & ICOM_CABLE_ID_VALID) {
cable_id = (cable_id & ICOM_CABLE_ID_MASK) >> 4;
icom_port->cable_id = cable_id;
} else {
dev_err(&dev->dev,"Invalid or no cable attached\n");
icom_port->cable_id = NO_CABLE;
}
load_code_exit:
if (status != 0) {
writew(0x3FFF, icom_port->int_reg);
writeb(ICOM_DISABLE, &(icom_port->dram->disable));
stop_processor(icom_port);
dev_err(&icom_port->adapter->pci_dev->dev,"Port not operational\n");
}
if (new_page != NULL)
pci_free_consistent(dev, 4096, new_page, temp_pci);
}
static int startup(struct icom_port *icom_port)
{
unsigned long temp;
unsigned char cable_id, raw_cable_id;
unsigned long flags;
int port;
trace(icom_port, "STARTUP", 0);
if (!icom_port->dram) {
dev_err(&icom_port->adapter->pci_dev->dev,
"Unusable Port, port configuration missing\n");
return -ENODEV;
}
raw_cable_id = readb(&icom_port->dram->cable_id);
trace(icom_port, "CABLE_ID", raw_cable_id);
cable_id = (raw_cable_id & ICOM_CABLE_ID_MASK) >> 4;
if (!(raw_cable_id & ICOM_CABLE_ID_VALID) ||
(cable_id != icom_port->cable_id)) {
load_code(icom_port);
raw_cable_id = readb(&icom_port->dram->cable_id);
cable_id = (raw_cable_id & ICOM_CABLE_ID_MASK) >> 4;
if (!(raw_cable_id & ICOM_CABLE_ID_VALID) ||
(icom_port->cable_id == NO_CABLE))
return -EIO;
}
spin_lock_irqsave(&icom_lock, flags);
port = icom_port->port;
if (port >= ARRAY_SIZE(int_mask_tbl)) {
dev_err(&icom_port->adapter->pci_dev->dev,
"Invalid port assignment\n");
goto unlock;
}
if (port == 0 || port == 1)
int_mask_tbl[port].global_int_mask = &icom_port->global_reg->int_mask;
else
int_mask_tbl[port].global_int_mask = &icom_port->global_reg->int_mask_2;
if (port == 0 || port == 2)
writew(0x00FF, icom_port->int_reg);
else
writew(0x3F00, icom_port->int_reg);
temp = readl(int_mask_tbl[port].global_int_mask);
writel(temp & ~int_mask_tbl[port].processor_id, int_mask_tbl[port].global_int_mask);
readl(int_mask_tbl[port].global_int_mask);
unlock:
spin_unlock_irqrestore(&icom_lock, flags);
return 0;
}
static void shutdown(struct icom_port *icom_port)
{
unsigned long temp;
unsigned char cmdReg;
unsigned long flags;
int port;
spin_lock_irqsave(&icom_lock, flags);
trace(icom_port, "SHUTDOWN", 0);
port = icom_port->port;
if (port >= ARRAY_SIZE(int_mask_tbl)) {
dev_err(&icom_port->adapter->pci_dev->dev,
"Invalid port assignment\n");
goto unlock;
}
if (port == 0 || port == 1)
int_mask_tbl[port].global_int_mask = &icom_port->global_reg->int_mask;
else
int_mask_tbl[port].global_int_mask = &icom_port->global_reg->int_mask_2;
temp = readl(int_mask_tbl[port].global_int_mask);
writel(temp | int_mask_tbl[port].processor_id, int_mask_tbl[port].global_int_mask);
readl(int_mask_tbl[port].global_int_mask);
unlock:
spin_unlock_irqrestore(&icom_lock, flags);
cmdReg = readb(&icom_port->dram->CmdReg);
if (cmdReg & CMD_SND_BREAK) {
writeb(cmdReg & ~CMD_SND_BREAK, &icom_port->dram->CmdReg);
}
}
static int icom_write(struct uart_port *port)
{
unsigned long data_count;
unsigned char cmdReg;
unsigned long offset;
int temp_tail = port->state->xmit.tail;
trace(ICOM_PORT, "WRITE", 0);
if (cpu_to_le16(ICOM_PORT->statStg->xmit[0].flags) &
SA_FLAGS_READY_TO_XMIT) {
trace(ICOM_PORT, "WRITE_FULL", 0);
return 0;
}
data_count = 0;
while ((port->state->xmit.head != temp_tail) &&
(data_count <= XMIT_BUFF_SZ)) {
ICOM_PORT->xmit_buf[data_count++] =
port->state->xmit.buf[temp_tail];
temp_tail++;
temp_tail &= (UART_XMIT_SIZE - 1);
}
if (data_count) {
ICOM_PORT->statStg->xmit[0].flags =
cpu_to_le16(SA_FLAGS_READY_TO_XMIT);
ICOM_PORT->statStg->xmit[0].leLength =
cpu_to_le16(data_count);
offset =
(unsigned long) &ICOM_PORT->statStg->xmit[0] -
(unsigned long) ICOM_PORT->statStg;
*ICOM_PORT->xmitRestart =
cpu_to_le32(ICOM_PORT->statStg_pci + offset);
cmdReg = readb(&ICOM_PORT->dram->CmdReg);
writeb(cmdReg | CMD_XMIT_RCV_ENABLE,
&ICOM_PORT->dram->CmdReg);
writeb(START_XMIT, &ICOM_PORT->dram->StartXmitCmd);
trace(ICOM_PORT, "WRITE_START", data_count);
readb(&ICOM_PORT->dram->StartXmitCmd);
}
return data_count;
}
static inline void check_modem_status(struct icom_port *icom_port)
{
static char old_status = 0;
char delta_status;
unsigned char status;
spin_lock(&icom_port->uart_port.lock);
status = readb(&icom_port->dram->isr);
trace(icom_port, "CHECK_MODEM", status);
delta_status = status ^ old_status;
if (delta_status) {
if (delta_status & ICOM_RI)
icom_port->uart_port.icount.rng++;
if (delta_status & ICOM_DSR)
icom_port->uart_port.icount.dsr++;
if (delta_status & ICOM_DCD)
uart_handle_dcd_change(&icom_port->uart_port,
delta_status & ICOM_DCD);
if (delta_status & ICOM_CTS)
uart_handle_cts_change(&icom_port->uart_port,
delta_status & ICOM_CTS);
wake_up_interruptible(&icom_port->uart_port.state->
port.delta_msr_wait);
old_status = status;
}
spin_unlock(&icom_port->uart_port.lock);
}
static void xmit_interrupt(u16 port_int_reg, struct icom_port *icom_port)
{
unsigned short int count;
int i;
if (port_int_reg & (INT_XMIT_COMPLETED)) {
trace(icom_port, "XMIT_COMPLETE", 0);
icom_port->statStg->xmit[0].flags &=
cpu_to_le16(~SA_FLAGS_READY_TO_XMIT);
count = (unsigned short int)
cpu_to_le16(icom_port->statStg->xmit[0].leLength);
icom_port->uart_port.icount.tx += count;
for (i=0; i<count &&
!uart_circ_empty(&icom_port->uart_port.state->xmit); i++) {
icom_port->uart_port.state->xmit.tail++;
icom_port->uart_port.state->xmit.tail &=
(UART_XMIT_SIZE - 1);
}
if (!icom_write(&icom_port->uart_port))
uart_write_wakeup(&icom_port->uart_port);
} else
trace(icom_port, "XMIT_DISABLED", 0);
}
static void recv_interrupt(u16 port_int_reg, struct icom_port *icom_port)
{
short int count, rcv_buff;
struct tty_port *port = &icom_port->uart_port.state->port;
unsigned short int status;
struct uart_icount *icount;
unsigned long offset;
unsigned char flag;
trace(icom_port, "RCV_COMPLETE", 0);
rcv_buff = icom_port->next_rcv;
status = cpu_to_le16(icom_port->statStg->rcv[rcv_buff].flags);
while (status & SA_FL_RCV_DONE) {
int first = -1;
trace(icom_port, "FID_STATUS", status);
count = cpu_to_le16(icom_port->statStg->rcv[rcv_buff].leLength);
trace(icom_port, "RCV_COUNT", count);
trace(icom_port, "REAL_COUNT", count);
offset =
cpu_to_le32(icom_port->statStg->rcv[rcv_buff].leBuffer) -
icom_port->recv_buf_pci;
if (count > 0) {
first = icom_port->recv_buf[offset];
tty_insert_flip_string(port, icom_port->recv_buf + offset, count - 1);
}
icount = &icom_port->uart_port.icount;
icount->rx += count;
if ((status & SA_FLAGS_FRAME_ERROR)
&& first == 0) {
status &= ~SA_FLAGS_FRAME_ERROR;
status |= SA_FLAGS_BREAK_DET;
trace(icom_port, "BREAK_DET", 0);
}
flag = TTY_NORMAL;
if (status &
(SA_FLAGS_BREAK_DET | SA_FLAGS_PARITY_ERROR |
SA_FLAGS_FRAME_ERROR | SA_FLAGS_OVERRUN)) {
if (status & SA_FLAGS_BREAK_DET)
icount->brk++;
if (status & SA_FLAGS_PARITY_ERROR)
icount->parity++;
if (status & SA_FLAGS_FRAME_ERROR)
icount->frame++;
if (status & SA_FLAGS_OVERRUN)
icount->overrun++;
if (status & icom_port->ignore_status_mask) {
trace(icom_port, "IGNORE_CHAR", 0);
goto ignore_char;
}
status &= icom_port->read_status_mask;
if (status & SA_FLAGS_BREAK_DET) {
flag = TTY_BREAK;
} else if (status & SA_FLAGS_PARITY_ERROR) {
trace(icom_port, "PARITY_ERROR", 0);
flag = TTY_PARITY;
} else if (status & SA_FLAGS_FRAME_ERROR)
flag = TTY_FRAME;
}
tty_insert_flip_char(port, *(icom_port->recv_buf + offset + count - 1), flag);
if (status & SA_FLAGS_OVERRUN)
tty_insert_flip_char(port, 0, TTY_OVERRUN);
ignore_char:
icom_port->statStg->rcv[rcv_buff].flags = 0;
icom_port->statStg->rcv[rcv_buff].leLength = 0;
icom_port->statStg->rcv[rcv_buff].WorkingLength =
(unsigned short int) cpu_to_le16(RCV_BUFF_SZ);
rcv_buff++;
if (rcv_buff == NUM_RBUFFS)
rcv_buff = 0;
status = cpu_to_le16(icom_port->statStg->rcv[rcv_buff].flags);
}
icom_port->next_rcv = rcv_buff;
spin_unlock(&icom_port->uart_port.lock);
tty_flip_buffer_push(port);
spin_lock(&icom_port->uart_port.lock);
}
static void process_interrupt(u16 port_int_reg,
struct icom_port *icom_port)
{
spin_lock(&icom_port->uart_port.lock);
trace(icom_port, "INTERRUPT", port_int_reg);
if (port_int_reg & (INT_XMIT_COMPLETED | INT_XMIT_DISABLED))
xmit_interrupt(port_int_reg, icom_port);
if (port_int_reg & INT_RCV_COMPLETED)
recv_interrupt(port_int_reg, icom_port);
spin_unlock(&icom_port->uart_port.lock);
}
static irqreturn_t icom_interrupt(int irq, void *dev_id)
{
void __iomem * int_reg;
u32 adapter_interrupts;
u16 port_int_reg;
struct icom_adapter *icom_adapter;
struct icom_port *icom_port;
icom_adapter = (struct icom_adapter *) dev_id;
if (icom_adapter->version == ADAPTER_V2) {
int_reg = icom_adapter->base_addr + 0x8024;
adapter_interrupts = readl(int_reg);
if (adapter_interrupts & 0x00003FFF) {
icom_port = &icom_adapter->port_info[2];
port_int_reg = (u16) adapter_interrupts;
process_interrupt(port_int_reg, icom_port);
check_modem_status(icom_port);
}
if (adapter_interrupts & 0x3FFF0000) {
icom_port = &icom_adapter->port_info[3];
if (icom_port->status == ICOM_PORT_ACTIVE) {
port_int_reg =
(u16) (adapter_interrupts >> 16);
process_interrupt(port_int_reg, icom_port);
check_modem_status(icom_port);
}
}
writel(adapter_interrupts, int_reg);
int_reg = icom_adapter->base_addr + 0x8004;
} else {
int_reg = icom_adapter->base_addr + 0x4004;
}
adapter_interrupts = readl(int_reg);
if (adapter_interrupts & 0x00003FFF) {
icom_port = &icom_adapter->port_info[0];
port_int_reg = (u16) adapter_interrupts;
process_interrupt(port_int_reg, icom_port);
check_modem_status(icom_port);
}
if (adapter_interrupts & 0x3FFF0000) {
icom_port = &icom_adapter->port_info[1];
if (icom_port->status == ICOM_PORT_ACTIVE) {
port_int_reg = (u16) (adapter_interrupts >> 16);
process_interrupt(port_int_reg, icom_port);
check_modem_status(icom_port);
}
}
writel(adapter_interrupts, int_reg);
adapter_interrupts = readl(int_reg);
return IRQ_HANDLED;
}
static unsigned int icom_tx_empty(struct uart_port *port)
{
int ret;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
if (cpu_to_le16(ICOM_PORT->statStg->xmit[0].flags) &
SA_FLAGS_READY_TO_XMIT)
ret = TIOCSER_TEMT;
else
ret = 0;
spin_unlock_irqrestore(&port->lock, flags);
return ret;
}
static void icom_set_mctrl(struct uart_port *port, unsigned int mctrl)
{
unsigned char local_osr;
trace(ICOM_PORT, "SET_MODEM", 0);
local_osr = readb(&ICOM_PORT->dram->osr);
if (mctrl & TIOCM_RTS) {
trace(ICOM_PORT, "RAISE_RTS", 0);
local_osr |= ICOM_RTS;
} else {
trace(ICOM_PORT, "LOWER_RTS", 0);
local_osr &= ~ICOM_RTS;
}
if (mctrl & TIOCM_DTR) {
trace(ICOM_PORT, "RAISE_DTR", 0);
local_osr |= ICOM_DTR;
} else {
trace(ICOM_PORT, "LOWER_DTR", 0);
local_osr &= ~ICOM_DTR;
}
writeb(local_osr, &ICOM_PORT->dram->osr);
}
static unsigned int icom_get_mctrl(struct uart_port *port)
{
unsigned char status;
unsigned int result;
trace(ICOM_PORT, "GET_MODEM", 0);
status = readb(&ICOM_PORT->dram->isr);
result = ((status & ICOM_DCD) ? TIOCM_CAR : 0)
| ((status & ICOM_RI) ? TIOCM_RNG : 0)
| ((status & ICOM_DSR) ? TIOCM_DSR : 0)
| ((status & ICOM_CTS) ? TIOCM_CTS : 0);
return result;
}
static void icom_stop_tx(struct uart_port *port)
{
unsigned char cmdReg;
trace(ICOM_PORT, "STOP", 0);
cmdReg = readb(&ICOM_PORT->dram->CmdReg);
writeb(cmdReg | CMD_HOLD_XMIT, &ICOM_PORT->dram->CmdReg);
}
static void icom_start_tx(struct uart_port *port)
{
unsigned char cmdReg;
trace(ICOM_PORT, "START", 0);
cmdReg = readb(&ICOM_PORT->dram->CmdReg);
if ((cmdReg & CMD_HOLD_XMIT) == CMD_HOLD_XMIT)
writeb(cmdReg & ~CMD_HOLD_XMIT,
&ICOM_PORT->dram->CmdReg);
icom_write(port);
}
static void icom_send_xchar(struct uart_port *port, char ch)
{
unsigned char xdata;
int index;
unsigned long flags;
trace(ICOM_PORT, "SEND_XCHAR", ch);
for (index = 0; index < 10; index++) {
spin_lock_irqsave(&port->lock, flags);
xdata = readb(&ICOM_PORT->dram->xchar);
if (xdata == 0x00) {
trace(ICOM_PORT, "QUICK_WRITE", 0);
writeb(ch, &ICOM_PORT->dram->xchar);
xdata = readb(&ICOM_PORT->dram->xchar);
spin_unlock_irqrestore(&port->lock, flags);
break;
}
spin_unlock_irqrestore(&port->lock, flags);
msleep(10);
}
}
static void icom_stop_rx(struct uart_port *port)
{
unsigned char cmdReg;
cmdReg = readb(&ICOM_PORT->dram->CmdReg);
writeb(cmdReg & ~CMD_RCV_ENABLE, &ICOM_PORT->dram->CmdReg);
}
static void icom_break(struct uart_port *port, int break_state)
{
unsigned char cmdReg;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
trace(ICOM_PORT, "BREAK", 0);
cmdReg = readb(&ICOM_PORT->dram->CmdReg);
if (break_state == -1) {
writeb(cmdReg | CMD_SND_BREAK, &ICOM_PORT->dram->CmdReg);
} else {
writeb(cmdReg & ~CMD_SND_BREAK, &ICOM_PORT->dram->CmdReg);
}
spin_unlock_irqrestore(&port->lock, flags);
}
static int icom_open(struct uart_port *port)
{
int retval;
kref_get(&ICOM_PORT->adapter->kref);
retval = startup(ICOM_PORT);
if (retval) {
kref_put(&ICOM_PORT->adapter->kref, icom_kref_release);
trace(ICOM_PORT, "STARTUP_ERROR", 0);
return retval;
}
return 0;
}
static void icom_close(struct uart_port *port)
{
unsigned char cmdReg;
trace(ICOM_PORT, "CLOSE", 0);
cmdReg = readb(&ICOM_PORT->dram->CmdReg);
writeb(cmdReg & ~CMD_RCV_ENABLE, &ICOM_PORT->dram->CmdReg);
shutdown(ICOM_PORT);
kref_put(&ICOM_PORT->adapter->kref, icom_kref_release);
}
static void icom_set_termios(struct uart_port *port,
struct ktermios *termios,
struct ktermios *old_termios)
{
int baud;
unsigned cflag, iflag;
char new_config2;
char new_config3 = 0;
char tmp_byte;
int index;
int rcv_buff, xmit_buff;
unsigned long offset;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
trace(ICOM_PORT, "CHANGE_SPEED", 0);
cflag = termios->c_cflag;
iflag = termios->c_iflag;
new_config2 = ICOM_ACFG_DRIVE1;
switch (cflag & CSIZE) {
case CS5:
new_config2 |= ICOM_ACFG_5BPC;
break;
case CS6:
new_config2 |= ICOM_ACFG_6BPC;
break;
case CS7:
new_config2 |= ICOM_ACFG_7BPC;
break;
case CS8:
new_config2 |= ICOM_ACFG_8BPC;
break;
default:
break;
}
if (cflag & CSTOPB) {
new_config2 |= ICOM_ACFG_2STOP_BIT;
}
if (cflag & PARENB) {
new_config2 |= ICOM_ACFG_PARITY_ENAB;
trace(ICOM_PORT, "PARENB", 0);
}
if (cflag & PARODD) {
new_config2 |= ICOM_ACFG_PARITY_ODD;
trace(ICOM_PORT, "PARODD", 0);
}
baud = uart_get_baud_rate(port, termios, old_termios,
icom_acfg_baud[0],
icom_acfg_baud[BAUD_TABLE_LIMIT]);
if (!baud)
baud = 9600;
for (index = 0; index < BAUD_TABLE_LIMIT; index++) {
if (icom_acfg_baud[index] == baud) {
new_config3 = index;
break;
}
}
uart_update_timeout(port, cflag, baud);
tmp_byte = readb(&(ICOM_PORT->dram->HDLCConfigReg));
if (cflag & CRTSCTS)
tmp_byte |= HDLC_HDW_FLOW;
else
tmp_byte &= ~HDLC_HDW_FLOW;
writeb(tmp_byte, &(ICOM_PORT->dram->HDLCConfigReg));
ICOM_PORT->read_status_mask = SA_FLAGS_OVERRUN | SA_FL_RCV_DONE;
if (iflag & INPCK)
ICOM_PORT->read_status_mask |=
SA_FLAGS_FRAME_ERROR | SA_FLAGS_PARITY_ERROR;
if ((iflag & BRKINT) || (iflag & PARMRK))
ICOM_PORT->read_status_mask |= SA_FLAGS_BREAK_DET;
ICOM_PORT->ignore_status_mask = 0;
if (iflag & IGNPAR)
ICOM_PORT->ignore_status_mask |=
SA_FLAGS_PARITY_ERROR | SA_FLAGS_FRAME_ERROR;
if (iflag & IGNBRK) {
ICOM_PORT->ignore_status_mask |= SA_FLAGS_BREAK_DET;
if (iflag & IGNPAR)
ICOM_PORT->ignore_status_mask |= SA_FLAGS_OVERRUN;
}
if ((cflag & CREAD) == 0)
ICOM_PORT->ignore_status_mask |= SA_FL_RCV_DONE;
writeb(CMD_RCV_DISABLE, &ICOM_PORT->dram->CmdReg);
for (index = 0; index < 10; index++) {
if (readb(&ICOM_PORT->dram->PrevCmdReg) == 0x00) {
break;
}
}
for (rcv_buff = 0; rcv_buff < NUM_RBUFFS; rcv_buff++) {
ICOM_PORT->statStg->rcv[rcv_buff].flags = 0;
ICOM_PORT->statStg->rcv[rcv_buff].leLength = 0;
ICOM_PORT->statStg->rcv[rcv_buff].WorkingLength =
(unsigned short int) cpu_to_le16(RCV_BUFF_SZ);
}
for (xmit_buff = 0; xmit_buff < NUM_XBUFFS; xmit_buff++) {
ICOM_PORT->statStg->xmit[xmit_buff].flags = 0;
}
writeb(new_config3, &(ICOM_PORT->dram->async_config3));
writeb(new_config2, &(ICOM_PORT->dram->async_config2));
tmp_byte = readb(&(ICOM_PORT->dram->HDLCConfigReg));
tmp_byte |= HDLC_PPP_PURE_ASYNC | HDLC_FF_FILL;
writeb(tmp_byte, &(ICOM_PORT->dram->HDLCConfigReg));
writeb(0x04, &(ICOM_PORT->dram->FlagFillIdleTimer));
writeb(0xFF, &(ICOM_PORT->dram->ier));
writeb(CMD_RESTART, &ICOM_PORT->dram->CmdReg);
for (index = 0; index < 10; index++) {
if (readb(&ICOM_PORT->dram->CmdReg) == 0x00) {
break;
}
}
offset =
(unsigned long) &ICOM_PORT->statStg->rcv[0] -
(unsigned long) ICOM_PORT->statStg;
writel(ICOM_PORT->statStg_pci + offset,
&ICOM_PORT->dram->RcvStatusAddr);
ICOM_PORT->next_rcv = 0;
ICOM_PORT->put_length = 0;
*ICOM_PORT->xmitRestart = 0;
writel(ICOM_PORT->xmitRestart_pci,
&ICOM_PORT->dram->XmitStatusAddr);
trace(ICOM_PORT, "XR_ENAB", 0);
writeb(CMD_XMIT_RCV_ENABLE, &ICOM_PORT->dram->CmdReg);
spin_unlock_irqrestore(&port->lock, flags);
}
static const char *icom_type(struct uart_port *port)
{
return "icom";
}
static void icom_release_port(struct uart_port *port)
{
}
static int icom_request_port(struct uart_port *port)
{
return 0;
}
static void icom_config_port(struct uart_port *port, int flags)
{
port->type = PORT_ICOM;
}
static int icom_init_ports(struct icom_adapter *icom_adapter)
{
u32 subsystem_id = icom_adapter->subsystem_id;
int i;
struct icom_port *icom_port;
if (icom_adapter->version == ADAPTER_V1) {
icom_adapter->numb_ports = 2;
for (i = 0; i < 2; i++) {
icom_port = &icom_adapter->port_info[i];
icom_port->port = i;
icom_port->status = ICOM_PORT_ACTIVE;
icom_port->imbed_modem = ICOM_UNKNOWN;
}
} else {
if (subsystem_id == PCI_DEVICE_ID_IBM_ICOM_FOUR_PORT_MODEL) {
icom_adapter->numb_ports = 4;
for (i = 0; i < 4; i++) {
icom_port = &icom_adapter->port_info[i];
icom_port->port = i;
icom_port->status = ICOM_PORT_ACTIVE;
icom_port->imbed_modem = ICOM_IMBED_MODEM;
}
} else {
icom_adapter->numb_ports = 4;
icom_adapter->port_info[0].port = 0;
icom_adapter->port_info[0].status = ICOM_PORT_ACTIVE;
if (subsystem_id ==
PCI_DEVICE_ID_IBM_ICOM_V2_ONE_PORT_RVX_ONE_PORT_MDM) {
icom_adapter->port_info[0].imbed_modem = ICOM_IMBED_MODEM;
} else {
icom_adapter->port_info[0].imbed_modem = ICOM_RVX;
}
icom_adapter->port_info[1].status = ICOM_PORT_OFF;
icom_adapter->port_info[2].port = 2;
icom_adapter->port_info[2].status = ICOM_PORT_ACTIVE;
icom_adapter->port_info[2].imbed_modem = ICOM_RVX;
icom_adapter->port_info[3].status = ICOM_PORT_OFF;
}
}
return 0;
}
static void icom_port_active(struct icom_port *icom_port, struct icom_adapter *icom_adapter, int port_num)
{
if (icom_adapter->version == ADAPTER_V1) {
icom_port->global_reg = icom_adapter->base_addr + 0x4000;
icom_port->int_reg = icom_adapter->base_addr +
0x4004 + 2 - 2 * port_num;
} else {
icom_port->global_reg = icom_adapter->base_addr + 0x8000;
if (icom_port->port < 2)
icom_port->int_reg = icom_adapter->base_addr +
0x8004 + 2 - 2 * icom_port->port;
else
icom_port->int_reg = icom_adapter->base_addr +
0x8024 + 2 - 2 * (icom_port->port - 2);
}
}
static int icom_load_ports(struct icom_adapter *icom_adapter)
{
struct icom_port *icom_port;
int port_num;
for (port_num = 0; port_num < icom_adapter->numb_ports; port_num++) {
icom_port = &icom_adapter->port_info[port_num];
if (icom_port->status == ICOM_PORT_ACTIVE) {
icom_port_active(icom_port, icom_adapter, port_num);
icom_port->dram = icom_adapter->base_addr +
0x2000 * icom_port->port;
icom_port->adapter = icom_adapter;
if (get_port_memory(icom_port) != 0) {
dev_err(&icom_port->adapter->pci_dev->dev,
"Memory allocation for port FAILED\n");
}
}
}
return 0;
}
static int icom_alloc_adapter(struct icom_adapter
**icom_adapter_ref)
{
int adapter_count = 0;
struct icom_adapter *icom_adapter;
struct icom_adapter *cur_adapter_entry;
struct list_head *tmp;
icom_adapter = kzalloc(sizeof(struct icom_adapter), GFP_KERNEL);
if (!icom_adapter) {
return -ENOMEM;
}
list_for_each(tmp, &icom_adapter_head) {
cur_adapter_entry =
list_entry(tmp, struct icom_adapter,
icom_adapter_entry);
if (cur_adapter_entry->index != adapter_count) {
break;
}
adapter_count++;
}
icom_adapter->index = adapter_count;
list_add_tail(&icom_adapter->icom_adapter_entry, tmp);
*icom_adapter_ref = icom_adapter;
return 0;
}
static void icom_free_adapter(struct icom_adapter *icom_adapter)
{
list_del(&icom_adapter->icom_adapter_entry);
kfree(icom_adapter);
}
static void icom_remove_adapter(struct icom_adapter *icom_adapter)
{
struct icom_port *icom_port;
int index;
for (index = 0; index < icom_adapter->numb_ports; index++) {
icom_port = &icom_adapter->port_info[index];
if (icom_port->status == ICOM_PORT_ACTIVE) {
dev_info(&icom_adapter->pci_dev->dev,
"Device removed\n");
uart_remove_one_port(&icom_uart_driver,
&icom_port->uart_port);
writeb(0x00, &icom_port->dram->osr);
msleep(100);
stop_processor(icom_port);
free_port_memory(icom_port);
}
}
free_irq(icom_adapter->pci_dev->irq, (void *) icom_adapter);
iounmap(icom_adapter->base_addr);
pci_release_regions(icom_adapter->pci_dev);
icom_free_adapter(icom_adapter);
}
static void icom_kref_release(struct kref *kref)
{
struct icom_adapter *icom_adapter;
icom_adapter = to_icom_adapter(kref);
icom_remove_adapter(icom_adapter);
}
static int icom_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
int index;
unsigned int command_reg;
int retval;
struct icom_adapter *icom_adapter;
struct icom_port *icom_port;
retval = pci_enable_device(dev);
if (retval) {
dev_err(&dev->dev, "Device enable FAILED\n");
return retval;
}
if ( (retval = pci_request_regions(dev, "icom"))) {
dev_err(&dev->dev, "pci_request_regions FAILED\n");
pci_disable_device(dev);
return retval;
}
pci_set_master(dev);
if ( (retval = pci_read_config_dword(dev, PCI_COMMAND, &command_reg))) {
dev_err(&dev->dev, "PCI Config read FAILED\n");
return retval;
}
pci_write_config_dword(dev, PCI_COMMAND,
command_reg | PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER
| PCI_COMMAND_PARITY | PCI_COMMAND_SERR);
if (ent->driver_data == ADAPTER_V1) {
pci_write_config_dword(dev, 0x44, 0x8300830A);
} else {
pci_write_config_dword(dev, 0x44, 0x42004200);
pci_write_config_dword(dev, 0x48, 0x42004200);
}
retval = icom_alloc_adapter(&icom_adapter);
if (retval) {
dev_err(&dev->dev, "icom_alloc_adapter FAILED\n");
retval = -EIO;
goto probe_exit0;
}
icom_adapter->base_addr_pci = pci_resource_start(dev, 0);
icom_adapter->pci_dev = dev;
icom_adapter->version = ent->driver_data;
icom_adapter->subsystem_id = ent->subdevice;
retval = icom_init_ports(icom_adapter);
if (retval) {
dev_err(&dev->dev, "Port configuration failed\n");
goto probe_exit1;
}
icom_adapter->base_addr = pci_ioremap_bar(dev, 0);
if (!icom_adapter->base_addr)
goto probe_exit1;
if ( (retval = request_irq(dev->irq, icom_interrupt,
IRQF_SHARED, ICOM_DRIVER_NAME,
(void *) icom_adapter))) {
goto probe_exit2;
}
retval = icom_load_ports(icom_adapter);
for (index = 0; index < icom_adapter->numb_ports; index++) {
icom_port = &icom_adapter->port_info[index];
if (icom_port->status == ICOM_PORT_ACTIVE) {
icom_port->uart_port.irq = icom_port->adapter->pci_dev->irq;
icom_port->uart_port.type = PORT_ICOM;
icom_port->uart_port.iotype = UPIO_MEM;
icom_port->uart_port.membase =
(unsigned char __iomem *)icom_adapter->base_addr_pci;
icom_port->uart_port.fifosize = 16;
icom_port->uart_port.ops = &icom_ops;
icom_port->uart_port.line =
icom_port->port + icom_adapter->index * 4;
if (uart_add_one_port (&icom_uart_driver, &icom_port->uart_port)) {
icom_port->status = ICOM_PORT_OFF;
dev_err(&dev->dev, "Device add failed\n");
} else
dev_info(&dev->dev, "Device added\n");
}
}
kref_init(&icom_adapter->kref);
return 0;
probe_exit2:
iounmap(icom_adapter->base_addr);
probe_exit1:
icom_free_adapter(icom_adapter);
probe_exit0:
pci_release_regions(dev);
pci_disable_device(dev);
return retval;
}
static void icom_remove(struct pci_dev *dev)
{
struct icom_adapter *icom_adapter;
struct list_head *tmp;
list_for_each(tmp, &icom_adapter_head) {
icom_adapter = list_entry(tmp, struct icom_adapter,
icom_adapter_entry);
if (icom_adapter->pci_dev == dev) {
kref_put(&icom_adapter->kref, icom_kref_release);
return;
}
}
dev_err(&dev->dev, "Unable to find device to remove\n");
}
static int __init icom_init(void)
{
int ret;
spin_lock_init(&icom_lock);
ret = uart_register_driver(&icom_uart_driver);
if (ret)
return ret;
ret = pci_register_driver(&icom_pci_driver);
if (ret < 0)
uart_unregister_driver(&icom_uart_driver);
return ret;
}
static void __exit icom_exit(void)
{
pci_unregister_driver(&icom_pci_driver);
uart_unregister_driver(&icom_uart_driver);
}
