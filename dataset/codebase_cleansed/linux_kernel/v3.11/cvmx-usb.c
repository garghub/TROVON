static int octeon_usb_get_clock_type(void)
{
switch (cvmx_sysinfo_get()->board_type) {
case CVMX_BOARD_TYPE_BBGW_REF:
case CVMX_BOARD_TYPE_LANAI2_A:
case CVMX_BOARD_TYPE_LANAI2_U:
case CVMX_BOARD_TYPE_LANAI2_G:
return USB_CLOCK_TYPE_CRYSTAL_12;
}
if (OCTEON_IS_MODEL(OCTEON_CN50XX) &&
cvmx_sysinfo_get()->board_type == 20002)
return USB_CLOCK_TYPE_CRYSTAL_12;
return USB_CLOCK_TYPE_REF_48;
}
static inline uint32_t __cvmx_usb_read_csr32(cvmx_usb_internal_state_t *usb,
uint64_t address)
{
uint32_t result = cvmx_read64_uint32(address ^ 4);
return result;
}
static inline void __cvmx_usb_write_csr32(cvmx_usb_internal_state_t *usb,
uint64_t address, uint32_t value)
{
cvmx_write64_uint32(address ^ 4, value);
cvmx_read64_uint64(CVMX_USBNX_DMA0_INB_CHN0(usb->index));
}
static inline uint64_t __cvmx_usb_read_csr64(cvmx_usb_internal_state_t *usb,
uint64_t address)
{
uint64_t result = cvmx_read64_uint64(address);
return result;
}
static inline void __cvmx_usb_write_csr64(cvmx_usb_internal_state_t *usb,
uint64_t address, uint64_t value)
{
cvmx_write64_uint64(address, value);
}
static const char *__cvmx_usb_complete_to_string(cvmx_usb_complete_t complete_code)
{
switch (complete_code)
{
case CVMX_USB_COMPLETE_SUCCESS: return "SUCCESS";
case CVMX_USB_COMPLETE_SHORT: return "SHORT";
case CVMX_USB_COMPLETE_CANCEL: return "CANCEL";
case CVMX_USB_COMPLETE_ERROR: return "ERROR";
case CVMX_USB_COMPLETE_STALL: return "STALL";
case CVMX_USB_COMPLETE_XACTERR: return "XACTERR";
case CVMX_USB_COMPLETE_DATATGLERR: return "DATATGLERR";
case CVMX_USB_COMPLETE_BABBLEERR: return "BABBLEERR";
case CVMX_USB_COMPLETE_FRAMEERR: return "FRAMEERR";
}
return "Update __cvmx_usb_complete_to_string";
}
static inline int __cvmx_usb_pipe_needs_split(cvmx_usb_internal_state_t *usb, cvmx_usb_pipe_t *pipe)
{
return ((pipe->device_speed != CVMX_USB_SPEED_HIGH) && (usb->usbcx_hprt.s.prtspd == CVMX_USB_SPEED_HIGH));
}
static inline int __cvmx_usb_get_data_pid(cvmx_usb_pipe_t *pipe)
{
if (pipe->pid_toggle)
return 2;
else
return 0;
}
int cvmx_usb_get_num_ports(void)
{
int arch_ports = 0;
if (OCTEON_IS_MODEL(OCTEON_CN56XX))
arch_ports = 1;
else if (OCTEON_IS_MODEL(OCTEON_CN52XX))
arch_ports = 2;
else if (OCTEON_IS_MODEL(OCTEON_CN50XX))
arch_ports = 1;
else if (OCTEON_IS_MODEL(OCTEON_CN31XX))
arch_ports = 1;
else if (OCTEON_IS_MODEL(OCTEON_CN30XX))
arch_ports = 1;
else
arch_ports = 0;
return arch_ports;
}
static inline cvmx_usb_transaction_t *__cvmx_usb_alloc_transaction(cvmx_usb_internal_state_t *usb)
{
cvmx_usb_transaction_t *t;
t = usb->free_transaction_head;
if (t) {
usb->free_transaction_head = t->next;
if (!usb->free_transaction_head)
usb->free_transaction_tail = NULL;
}
else if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_INFO))
cvmx_dprintf("%s: Failed to allocate a transaction\n", __FUNCTION__);
if (t) {
memset(t, 0, sizeof(*t));
t->flags = __CVMX_USB_TRANSACTION_FLAGS_IN_USE;
}
return t;
}
static inline void __cvmx_usb_free_transaction(cvmx_usb_internal_state_t *usb,
cvmx_usb_transaction_t *transaction)
{
transaction->flags = 0;
transaction->prev = NULL;
transaction->next = NULL;
if (usb->free_transaction_tail)
usb->free_transaction_tail->next = transaction;
else
usb->free_transaction_head = transaction;
usb->free_transaction_tail = transaction;
}
static inline void __cvmx_usb_append_pipe(cvmx_usb_pipe_list_t *list, cvmx_usb_pipe_t *pipe)
{
pipe->next = NULL;
pipe->prev = list->tail;
if (list->tail)
list->tail->next = pipe;
else
list->head = pipe;
list->tail = pipe;
}
static inline void __cvmx_usb_remove_pipe(cvmx_usb_pipe_list_t *list, cvmx_usb_pipe_t *pipe)
{
if (list->head == pipe) {
list->head = pipe->next;
pipe->next = NULL;
if (list->head)
list->head->prev = NULL;
else
list->tail = NULL;
}
else if (list->tail == pipe) {
list->tail = pipe->prev;
list->tail->next = NULL;
pipe->prev = NULL;
}
else {
pipe->prev->next = pipe->next;
pipe->next->prev = pipe->prev;
pipe->prev = NULL;
pipe->next = NULL;
}
}
cvmx_usb_status_t cvmx_usb_initialize(cvmx_usb_state_t *state,
int usb_port_number,
cvmx_usb_initialize_flags_t flags)
{
cvmx_usbnx_clk_ctl_t usbn_clk_ctl;
cvmx_usbnx_usbp_ctl_status_t usbn_usbp_ctl_status;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
usb->init_flags = flags;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", usb_port_number);
CVMX_USB_LOG_PARAM("0x%x", flags);
if (sizeof(*state) < sizeof(*usb))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if ((usb_port_number < 0) || (usb_port_number > 1))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (!OCTEON_IS_MODEL(OCTEON_CN52XX) && (usb_port_number > 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if ((flags & (CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_XI |
CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_GND)) == 0) {
if (octeon_usb_get_clock_type() == USB_CLOCK_TYPE_CRYSTAL_12)
flags |= CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_XI;
else
flags |= CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_GND;
}
if (flags & CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_GND) {
if (!(flags & CVMX_USB_INITIALIZE_FLAGS_CLOCK_MHZ_MASK))
switch (octeon_usb_get_clock_type()) {
case USB_CLOCK_TYPE_REF_12:
flags |= CVMX_USB_INITIALIZE_FLAGS_CLOCK_12MHZ;
break;
case USB_CLOCK_TYPE_REF_24:
flags |= CVMX_USB_INITIALIZE_FLAGS_CLOCK_24MHZ;
break;
case USB_CLOCK_TYPE_REF_48:
flags |= CVMX_USB_INITIALIZE_FLAGS_CLOCK_48MHZ;
break;
default:
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
break;
}
}
memset(usb, 0, sizeof(usb));
usb->init_flags = flags;
{
int i;
usb->index = usb_port_number;
usb->free_transaction_head = NULL;
usb->free_transaction_tail = NULL;
for (i=0; i<MAX_TRANSACTIONS; i++)
__cvmx_usb_free_transaction(usb, usb->transaction + i);
for (i=0; i<MAX_PIPES; i++)
__cvmx_usb_append_pipe(&usb->free_pipes, usb->pipe + i);
}
usbn_clk_ctl.u64 = __cvmx_usb_read_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index));
usbn_clk_ctl.s.por = 1;
usbn_clk_ctl.s.hrst = 0;
usbn_clk_ctl.s.prst = 0;
usbn_clk_ctl.s.hclk_rst = 0;
usbn_clk_ctl.s.enable = 0;
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_GND) {
if (OCTEON_IS_MODEL(OCTEON_CN3XXX)) {
usbn_clk_ctl.cn31xx.p_rclk = 1;
usbn_clk_ctl.cn31xx.p_xenbn = 0;
}
else if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN50XX))
usbn_clk_ctl.cn56xx.p_rtype = 2;
else
usbn_clk_ctl.cn52xx.p_rtype = 1;
switch (flags & CVMX_USB_INITIALIZE_FLAGS_CLOCK_MHZ_MASK) {
case CVMX_USB_INITIALIZE_FLAGS_CLOCK_12MHZ:
usbn_clk_ctl.s.p_c_sel = 0;
break;
case CVMX_USB_INITIALIZE_FLAGS_CLOCK_24MHZ:
usbn_clk_ctl.s.p_c_sel = 1;
break;
case CVMX_USB_INITIALIZE_FLAGS_CLOCK_48MHZ:
usbn_clk_ctl.s.p_c_sel = 2;
break;
}
}
else {
if (OCTEON_IS_MODEL(OCTEON_CN3XXX)) {
usbn_clk_ctl.cn31xx.p_rclk = 1;
usbn_clk_ctl.cn31xx.p_xenbn = 1;
}
else if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN50XX))
usbn_clk_ctl.cn56xx.p_rtype = 0;
else
usbn_clk_ctl.cn52xx.p_rtype = 0;
usbn_clk_ctl.s.p_c_sel = 0;
}
{
int divisor = (octeon_get_clock_rate()+125000000-1)/125000000;
if (divisor < 4)
divisor = 4;
usbn_clk_ctl.s.divide = divisor;
usbn_clk_ctl.s.divide2 = 0;
}
__cvmx_usb_write_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index),
usbn_clk_ctl.u64);
usbn_clk_ctl.s.hclk_rst = 1;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index),
usbn_clk_ctl.u64);
cvmx_wait(64);
usbn_clk_ctl.s.por = 0;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index),
usbn_clk_ctl.u64);
cvmx_wait_usec(1000);
usbn_usbp_ctl_status.u64 = __cvmx_usb_read_csr64(usb, CVMX_USBNX_USBP_CTL_STATUS(usb->index));
usbn_usbp_ctl_status.s.ate_reset = 1;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_USBP_CTL_STATUS(usb->index),
usbn_usbp_ctl_status.u64);
cvmx_wait(10);
usbn_usbp_ctl_status.s.ate_reset = 0;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_USBP_CTL_STATUS(usb->index),
usbn_usbp_ctl_status.u64);
usbn_clk_ctl.s.prst = 1;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index),
usbn_clk_ctl.u64);
usbn_usbp_ctl_status.s.hst_mode = 0;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_USBP_CTL_STATUS(usb->index),
usbn_usbp_ctl_status.u64);
cvmx_wait_usec(1);
usbn_clk_ctl.s.hrst = 1;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index),
usbn_clk_ctl.u64);
usbn_clk_ctl.s.enable = 1;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index),
usbn_clk_ctl.u64);
cvmx_wait_usec(1);
{
cvmx_usbcx_gahbcfg_t usbcx_gahbcfg;
if (OCTEON_IS_MODEL(OCTEON_CN31XX))
usb->init_flags |= CVMX_USB_INITIALIZE_FLAGS_NO_DMA;
usbcx_gahbcfg.u32 = 0;
usbcx_gahbcfg.s.dmaen = !(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA);
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
usb->idle_hardware_channels = 0x1;
else if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
usb->idle_hardware_channels = 0xf7;
else
usb->idle_hardware_channels = 0xff;
usbcx_gahbcfg.s.hbstlen = 0;
usbcx_gahbcfg.s.nptxfemplvl = 1;
usbcx_gahbcfg.s.ptxfemplvl = 1;
usbcx_gahbcfg.s.glblintrmsk = 1;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_GAHBCFG(usb->index),
usbcx_gahbcfg.u32);
}
{
cvmx_usbcx_gusbcfg_t usbcx_gusbcfg;
usbcx_gusbcfg.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_GUSBCFG(usb->index));
usbcx_gusbcfg.s.toutcal = 0;
usbcx_gusbcfg.s.ddrsel = 0;
usbcx_gusbcfg.s.usbtrdtim = 0x5;
usbcx_gusbcfg.s.phylpwrclksel = 0;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_GUSBCFG(usb->index),
usbcx_gusbcfg.u32);
}
{
cvmx_usbcx_gintmsk_t usbcx_gintmsk;
int channel;
usbcx_gintmsk.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_GINTMSK(usb->index));
usbcx_gintmsk.s.otgintmsk = 1;
usbcx_gintmsk.s.modemismsk = 1;
usbcx_gintmsk.s.hchintmsk = 1;
usbcx_gintmsk.s.sofmsk = 0;
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
usbcx_gintmsk.s.rxflvlmsk = 1;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_GINTMSK(usb->index),
usbcx_gintmsk.u32);
for (channel=0; channel<8; channel++)
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCINTMSKX(channel, usb->index), 0);
}
{
if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_INFO))
cvmx_dprintf("%s: USB%d is in host mode\n", __FUNCTION__, usb->index);
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index), cvmx_usbcx_gintmsk_t,
prtintmsk, 1);
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index), cvmx_usbcx_gintmsk_t,
disconnintmsk, 1);
{
cvmx_usbcx_hcfg_t usbcx_hcfg;
usbcx_hcfg.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCFG(usb->index));
usbcx_hcfg.s.fslssupp = 0;
usbcx_hcfg.s.fslspclksel = 0;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCFG(usb->index), usbcx_hcfg.u32);
}
USB_SET_FIELD32(CVMX_USBCX_HPRT(usb->index), cvmx_usbcx_hprt_t, prtpwr, 1);
}
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
cvmx_usb_status_t cvmx_usb_shutdown(cvmx_usb_state_t *state)
{
cvmx_usbnx_clk_ctl_t usbn_clk_ctl;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
if (usb->idle_pipes.head ||
usb->active_pipes[CVMX_USB_TRANSFER_ISOCHRONOUS].head ||
usb->active_pipes[CVMX_USB_TRANSFER_INTERRUPT].head ||
usb->active_pipes[CVMX_USB_TRANSFER_CONTROL].head ||
usb->active_pipes[CVMX_USB_TRANSFER_BULK].head)
CVMX_USB_RETURN(CVMX_USB_BUSY);
usbn_clk_ctl.u64 = __cvmx_usb_read_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index));
usbn_clk_ctl.s.enable = 1;
usbn_clk_ctl.s.por = 1;
usbn_clk_ctl.s.hclk_rst = 1;
usbn_clk_ctl.s.prst = 0;
usbn_clk_ctl.s.hrst = 0;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_CLK_CTL(usb->index),
usbn_clk_ctl.u64);
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
cvmx_usb_status_t cvmx_usb_enable(cvmx_usb_state_t *state)
{
cvmx_usbcx_ghwcfg3_t usbcx_ghwcfg3;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
usb->usbcx_hprt.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HPRT(usb->index));
if (usb->usbcx_hprt.s.prtena)
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
if (!usb->usbcx_hprt.s.prtconnsts) {
if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_INFO))
cvmx_dprintf("%s: USB%d Nothing plugged into the port\n", __FUNCTION__, usb->index);
CVMX_USB_RETURN(CVMX_USB_TIMEOUT);
}
USB_SET_FIELD32(CVMX_USBCX_HPRT(usb->index), cvmx_usbcx_hprt_t, prtrst, 1);
cvmx_wait_usec(50000);
USB_SET_FIELD32(CVMX_USBCX_HPRT(usb->index), cvmx_usbcx_hprt_t, prtrst, 0);
if (CVMX_WAIT_FOR_FIELD32(CVMX_USBCX_HPRT(usb->index), cvmx_usbcx_hprt_t,
prtena, ==, 1, 100000)) {
if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_INFO))
cvmx_dprintf("%s: Timeout waiting for the port to finish reset\n",
__FUNCTION__);
CVMX_USB_RETURN(CVMX_USB_TIMEOUT);
}
usb->usbcx_hprt.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HPRT(usb->index));
if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_INFO))
cvmx_dprintf("%s: USB%d is in %s speed mode\n", __FUNCTION__, usb->index,
(usb->usbcx_hprt.s.prtspd == CVMX_USB_SPEED_HIGH) ? "high" :
(usb->usbcx_hprt.s.prtspd == CVMX_USB_SPEED_FULL) ? "full" :
"low");
usbcx_ghwcfg3.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_GHWCFG3(usb->index));
USB_SET_FIELD32(CVMX_USBCX_GRXFSIZ(usb->index), cvmx_usbcx_grxfsiz_t,
rxfdep, usbcx_ghwcfg3.s.dfifodepth / 4);
{
cvmx_usbcx_gnptxfsiz_t siz;
siz.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_GNPTXFSIZ(usb->index));
siz.s.nptxfdep = usbcx_ghwcfg3.s.dfifodepth / 2;
siz.s.nptxfstaddr = usbcx_ghwcfg3.s.dfifodepth / 4;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_GNPTXFSIZ(usb->index), siz.u32);
}
{
cvmx_usbcx_hptxfsiz_t siz;
siz.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HPTXFSIZ(usb->index));
siz.s.ptxfsize = usbcx_ghwcfg3.s.dfifodepth / 4;
siz.s.ptxfstaddr = 3 * usbcx_ghwcfg3.s.dfifodepth / 4;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HPTXFSIZ(usb->index), siz.u32);
}
USB_SET_FIELD32(CVMX_USBCX_GRSTCTL(usb->index), cvmx_usbcx_grstctl_t, txfnum, 0x10);
USB_SET_FIELD32(CVMX_USBCX_GRSTCTL(usb->index), cvmx_usbcx_grstctl_t, txfflsh, 1);
CVMX_WAIT_FOR_FIELD32(CVMX_USBCX_GRSTCTL(usb->index), cvmx_usbcx_grstctl_t,
txfflsh, ==, 0, 100);
USB_SET_FIELD32(CVMX_USBCX_GRSTCTL(usb->index), cvmx_usbcx_grstctl_t, rxfflsh, 1);
CVMX_WAIT_FOR_FIELD32(CVMX_USBCX_GRSTCTL(usb->index), cvmx_usbcx_grstctl_t,
rxfflsh, ==, 0, 100);
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
cvmx_usb_status_t cvmx_usb_disable(cvmx_usb_state_t *state)
{
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
USB_SET_FIELD32(CVMX_USBCX_HPRT(usb->index), cvmx_usbcx_hprt_t, prtena, 1);
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
cvmx_usb_port_status_t cvmx_usb_get_status(cvmx_usb_state_t *state)
{
cvmx_usbcx_hprt_t usbc_hprt;
cvmx_usb_port_status_t result;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
memset(&result, 0, sizeof(result));
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
usbc_hprt.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HPRT(usb->index));
result.port_enabled = usbc_hprt.s.prtena;
result.port_over_current = usbc_hprt.s.prtovrcurract;
result.port_powered = usbc_hprt.s.prtpwr;
result.port_speed = usbc_hprt.s.prtspd;
result.connected = usbc_hprt.s.prtconnsts;
result.connect_change = (result.connected != usb->port_status.connected);
if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_CALLS))
cvmx_dprintf("%*s%s: returned port enabled=%d, over_current=%d, powered=%d, speed=%d, connected=%d, connect_change=%d\n",
2*(--usb->indent), "", __FUNCTION__,
result.port_enabled,
result.port_over_current,
result.port_powered,
result.port_speed,
result.connected,
result.connect_change);
return result;
}
void cvmx_usb_set_status(cvmx_usb_state_t *state, cvmx_usb_port_status_t port_status)
{
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
usb->port_status = port_status;
CVMX_USB_RETURN_NOTHING();
}
static inline int __cvmx_usb_get_submit_handle(cvmx_usb_internal_state_t *usb,
cvmx_usb_transaction_t *transaction)
{
return ((unsigned long)transaction - (unsigned long)usb->transaction) /
sizeof(*transaction);
}
static inline int __cvmx_usb_get_pipe_handle(cvmx_usb_internal_state_t *usb,
cvmx_usb_pipe_t *pipe)
{
return ((unsigned long)pipe - (unsigned long)usb->pipe) / sizeof(*pipe);
}
int cvmx_usb_open_pipe(cvmx_usb_state_t *state, cvmx_usb_pipe_flags_t flags,
int device_addr, int endpoint_num,
cvmx_usb_speed_t device_speed, int max_packet,
cvmx_usb_transfer_t transfer_type,
cvmx_usb_direction_t transfer_dir, int interval,
int multi_count, int hub_device_addr, int hub_port)
{
cvmx_usb_pipe_t *pipe;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("0x%x", flags);
CVMX_USB_LOG_PARAM("%d", device_addr);
CVMX_USB_LOG_PARAM("%d", endpoint_num);
CVMX_USB_LOG_PARAM("%d", device_speed);
CVMX_USB_LOG_PARAM("%d", max_packet);
CVMX_USB_LOG_PARAM("%d", transfer_type);
CVMX_USB_LOG_PARAM("%d", transfer_dir);
CVMX_USB_LOG_PARAM("%d", interval);
CVMX_USB_LOG_PARAM("%d", multi_count);
CVMX_USB_LOG_PARAM("%d", hub_device_addr);
CVMX_USB_LOG_PARAM("%d", hub_port);
if (cvmx_unlikely((device_addr < 0) || (device_addr > MAX_USB_ADDRESS)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((endpoint_num < 0) || (endpoint_num > MAX_USB_ENDPOINT)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(device_speed > CVMX_USB_SPEED_LOW))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((max_packet <= 0) || (max_packet > 1024)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(transfer_type > CVMX_USB_TRANSFER_INTERRUPT))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((transfer_dir != CVMX_USB_DIRECTION_OUT) &&
(transfer_dir != CVMX_USB_DIRECTION_IN)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(interval < 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((transfer_type == CVMX_USB_TRANSFER_CONTROL) && interval))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(multi_count < 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((device_speed != CVMX_USB_SPEED_HIGH) &&
(multi_count != 0)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((hub_device_addr < 0) || (hub_device_addr > MAX_USB_ADDRESS)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((hub_port < 0) || (hub_port > MAX_USB_HUB_PORT)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
pipe = usb->free_pipes.head;
if (!pipe)
CVMX_USB_RETURN(CVMX_USB_NO_MEMORY);
__cvmx_usb_remove_pipe(&usb->free_pipes, pipe);
pipe->flags = flags | __CVMX_USB_PIPE_FLAGS_OPEN;
if ((device_speed == CVMX_USB_SPEED_HIGH) &&
(transfer_dir == CVMX_USB_DIRECTION_OUT) &&
(transfer_type == CVMX_USB_TRANSFER_BULK))
pipe->flags |= __CVMX_USB_PIPE_FLAGS_NEED_PING;
pipe->device_addr = device_addr;
pipe->endpoint_num = endpoint_num;
pipe->device_speed = device_speed;
pipe->max_packet = max_packet;
pipe->transfer_type = transfer_type;
pipe->transfer_dir = transfer_dir;
if (!interval)
interval = 1;
if (__cvmx_usb_pipe_needs_split(usb, pipe)) {
pipe->interval = interval*8;
pipe->next_tx_frame = ((usb->frame_number+7)&~7) + pipe->interval;
}
else {
pipe->interval = interval;
pipe->next_tx_frame = usb->frame_number + pipe->interval;
}
pipe->multi_count = multi_count;
pipe->hub_device_addr = hub_device_addr;
pipe->hub_port = hub_port;
pipe->pid_toggle = 0;
pipe->split_sc_frame = -1;
__cvmx_usb_append_pipe(&usb->idle_pipes, pipe);
CVMX_USB_RETURN(__cvmx_usb_get_pipe_handle(usb, pipe));
}
static void __cvmx_usb_poll_rx_fifo(cvmx_usb_internal_state_t *usb)
{
cvmx_usbcx_grxstsph_t rx_status;
int channel;
int bytes;
uint64_t address;
uint32_t *ptr;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
rx_status.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_GRXSTSPH(usb->index));
if (rx_status.s.pktsts != 2)
CVMX_USB_RETURN_NOTHING();
if (!rx_status.s.bcnt)
CVMX_USB_RETURN_NOTHING();
channel = rx_status.s.chnum;
bytes = rx_status.s.bcnt;
if (!bytes)
CVMX_USB_RETURN_NOTHING();
address = __cvmx_usb_read_csr64(usb, CVMX_USBNX_DMA0_INB_CHN0(usb->index) + channel*8);
ptr = cvmx_phys_to_ptr(address);
__cvmx_usb_write_csr64(usb, CVMX_USBNX_DMA0_INB_CHN0(usb->index) + channel*8, address + bytes);
while (bytes > 0) {
*ptr++ = __cvmx_usb_read_csr32(usb, USB_FIFO_ADDRESS(channel, usb->index));
bytes -= 4;
}
CVMX_SYNCW;
CVMX_USB_RETURN_NOTHING();
}
static int __cvmx_usb_fill_tx_hw(cvmx_usb_internal_state_t *usb, cvmx_usb_tx_fifo_t *fifo, int available)
{
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
CVMX_USB_LOG_PARAM("%p", fifo);
CVMX_USB_LOG_PARAM("%d", available);
while (available && (fifo->head != fifo->tail)) {
int i = fifo->tail;
const uint32_t *ptr = cvmx_phys_to_ptr(fifo->entry[i].address);
uint64_t csr_address = USB_FIFO_ADDRESS(fifo->entry[i].channel, usb->index) ^ 4;
int words = available;
if (fifo->entry[i].size <= available) {
words = fifo->entry[i].size;
fifo->tail++;
if (fifo->tail > MAX_CHANNELS)
fifo->tail = 0;
}
available -= words;
fifo->entry[i].address += words * 4;
fifo->entry[i].size -= words;
while (words > 3) {
cvmx_write64_uint32(csr_address, *ptr++);
cvmx_write64_uint32(csr_address, *ptr++);
cvmx_write64_uint32(csr_address, *ptr++);
cvmx_read64_uint64(CVMX_USBNX_DMA0_INB_CHN0(usb->index));
words -= 3;
}
cvmx_write64_uint32(csr_address, *ptr++);
if (--words) {
cvmx_write64_uint32(csr_address, *ptr++);
if (--words)
cvmx_write64_uint32(csr_address, *ptr++);
}
cvmx_read64_uint64(CVMX_USBNX_DMA0_INB_CHN0(usb->index));
}
CVMX_USB_RETURN(fifo->head != fifo->tail);
}
static void __cvmx_usb_poll_tx_fifo(cvmx_usb_internal_state_t *usb)
{
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
if (usb->periodic.head != usb->periodic.tail) {
cvmx_usbcx_hptxsts_t tx_status;
tx_status.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HPTXSTS(usb->index));
if (__cvmx_usb_fill_tx_hw(usb, &usb->periodic, tx_status.s.ptxfspcavail))
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index), cvmx_usbcx_gintmsk_t, ptxfempmsk, 1);
else
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index), cvmx_usbcx_gintmsk_t, ptxfempmsk, 0);
}
if (usb->nonperiodic.head != usb->nonperiodic.tail) {
cvmx_usbcx_gnptxsts_t tx_status;
tx_status.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_GNPTXSTS(usb->index));
if (__cvmx_usb_fill_tx_hw(usb, &usb->nonperiodic, tx_status.s.nptxfspcavail))
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index), cvmx_usbcx_gintmsk_t, nptxfempmsk, 1);
else
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index), cvmx_usbcx_gintmsk_t, nptxfempmsk, 0);
}
CVMX_USB_RETURN_NOTHING();
}
static void __cvmx_usb_fill_tx_fifo(cvmx_usb_internal_state_t *usb, int channel)
{
cvmx_usbcx_hccharx_t hcchar;
cvmx_usbcx_hcspltx_t usbc_hcsplt;
cvmx_usbcx_hctsizx_t usbc_hctsiz;
cvmx_usb_tx_fifo_t *fifo;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
CVMX_USB_LOG_PARAM("%d", channel);
hcchar.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCCHARX(channel, usb->index));
if (hcchar.s.epdir != CVMX_USB_DIRECTION_OUT)
CVMX_USB_RETURN_NOTHING();
usbc_hcsplt.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCSPLTX(channel, usb->index));
if (usbc_hcsplt.s.spltena && usbc_hcsplt.s.compsplt)
CVMX_USB_RETURN_NOTHING();
usbc_hctsiz.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCTSIZX(channel, usb->index));
if (!usbc_hctsiz.s.xfersize)
CVMX_USB_RETURN_NOTHING();
if ((hcchar.s.eptype == CVMX_USB_TRANSFER_INTERRUPT) ||
(hcchar.s.eptype == CVMX_USB_TRANSFER_ISOCHRONOUS))
fifo = &usb->periodic;
else
fifo = &usb->nonperiodic;
fifo->entry[fifo->head].channel = channel;
fifo->entry[fifo->head].address = __cvmx_usb_read_csr64(usb, CVMX_USBNX_DMA0_OUTB_CHN0(usb->index) + channel*8);
fifo->entry[fifo->head].size = (usbc_hctsiz.s.xfersize+3)>>2;
fifo->head++;
if (fifo->head > MAX_CHANNELS)
fifo->head = 0;
__cvmx_usb_poll_tx_fifo(usb);
CVMX_USB_RETURN_NOTHING();
}
static void __cvmx_usb_start_channel_control(cvmx_usb_internal_state_t *usb,
int channel,
cvmx_usb_pipe_t *pipe)
{
cvmx_usb_transaction_t *transaction = pipe->head;
cvmx_usb_control_header_t *header = cvmx_phys_to_ptr(transaction->control_header);
int bytes_to_transfer = transaction->buffer_length - transaction->actual_bytes;
int packets_to_transfer;
cvmx_usbcx_hctsizx_t usbc_hctsiz;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
CVMX_USB_LOG_PARAM("%d", channel);
CVMX_USB_LOG_PARAM("%p", pipe);
usbc_hctsiz.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCTSIZX(channel, usb->index));
switch (transaction->stage) {
case CVMX_USB_STAGE_NON_CONTROL:
case CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE:
cvmx_dprintf("%s: ERROR - Non control stage\n", __FUNCTION__);
break;
case CVMX_USB_STAGE_SETUP:
usbc_hctsiz.s.pid = 3;
bytes_to_transfer = sizeof(*header);
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index), cvmx_usbcx_hccharx_t, epdir, CVMX_USB_DIRECTION_OUT);
__cvmx_usb_write_csr64(usb, CVMX_USBNX_DMA0_OUTB_CHN0(usb->index) + channel*8, transaction->control_header);
break;
case CVMX_USB_STAGE_SETUP_SPLIT_COMPLETE:
usbc_hctsiz.s.pid = 3;
bytes_to_transfer = 0;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index), cvmx_usbcx_hccharx_t, epdir, CVMX_USB_DIRECTION_OUT);
USB_SET_FIELD32(CVMX_USBCX_HCSPLTX(channel, usb->index), cvmx_usbcx_hcspltx_t, compsplt, 1);
break;
case CVMX_USB_STAGE_DATA:
usbc_hctsiz.s.pid = __cvmx_usb_get_data_pid(pipe);
if (__cvmx_usb_pipe_needs_split(usb, pipe)) {
if (header->s.request_type & 0x80)
bytes_to_transfer = 0;
else if (bytes_to_transfer > pipe->max_packet)
bytes_to_transfer = pipe->max_packet;
}
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx_t, epdir,
((header->s.request_type & 0x80) ?
CVMX_USB_DIRECTION_IN :
CVMX_USB_DIRECTION_OUT));
break;
case CVMX_USB_STAGE_DATA_SPLIT_COMPLETE:
usbc_hctsiz.s.pid = __cvmx_usb_get_data_pid(pipe);
if (!(header->s.request_type & 0x80))
bytes_to_transfer = 0;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx_t, epdir,
((header->s.request_type & 0x80) ?
CVMX_USB_DIRECTION_IN :
CVMX_USB_DIRECTION_OUT));
USB_SET_FIELD32(CVMX_USBCX_HCSPLTX(channel, usb->index), cvmx_usbcx_hcspltx_t, compsplt, 1);
break;
case CVMX_USB_STAGE_STATUS:
usbc_hctsiz.s.pid = __cvmx_usb_get_data_pid(pipe);
bytes_to_transfer = 0;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index), cvmx_usbcx_hccharx_t, epdir,
((header->s.request_type & 0x80) ?
CVMX_USB_DIRECTION_OUT :
CVMX_USB_DIRECTION_IN));
break;
case CVMX_USB_STAGE_STATUS_SPLIT_COMPLETE:
usbc_hctsiz.s.pid = __cvmx_usb_get_data_pid(pipe);
bytes_to_transfer = 0;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index), cvmx_usbcx_hccharx_t, epdir,
((header->s.request_type & 0x80) ?
CVMX_USB_DIRECTION_OUT :
CVMX_USB_DIRECTION_IN));
USB_SET_FIELD32(CVMX_USBCX_HCSPLTX(channel, usb->index), cvmx_usbcx_hcspltx_t, compsplt, 1);
break;
}
if (bytes_to_transfer > MAX_TRANSFER_BYTES) {
bytes_to_transfer = MAX_TRANSFER_BYTES / pipe->max_packet;
bytes_to_transfer *= pipe->max_packet;
}
packets_to_transfer = (bytes_to_transfer + pipe->max_packet - 1) / pipe->max_packet;
if (packets_to_transfer == 0)
packets_to_transfer = 1;
else if ((packets_to_transfer>1) && (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)) {
packets_to_transfer = 1;
bytes_to_transfer = packets_to_transfer * pipe->max_packet;
}
else if (packets_to_transfer > MAX_TRANSFER_PACKETS) {
packets_to_transfer = MAX_TRANSFER_PACKETS;
bytes_to_transfer = packets_to_transfer * pipe->max_packet;
}
usbc_hctsiz.s.xfersize = bytes_to_transfer;
usbc_hctsiz.s.pktcnt = packets_to_transfer;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCTSIZX(channel, usb->index), usbc_hctsiz.u32);
CVMX_USB_RETURN_NOTHING();
}
static void __cvmx_usb_start_channel(cvmx_usb_internal_state_t *usb,
int channel,
cvmx_usb_pipe_t *pipe)
{
cvmx_usb_transaction_t *transaction = pipe->head;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
CVMX_USB_LOG_PARAM("%d", channel);
CVMX_USB_LOG_PARAM("%p", pipe);
if (cvmx_unlikely((usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_TRANSFERS) ||
(pipe->flags & CVMX_USB_PIPE_FLAGS_DEBUG_TRANSFERS)))
cvmx_dprintf("%s: Channel %d started. Pipe %d transaction %d stage %d\n",
__FUNCTION__, channel, __cvmx_usb_get_pipe_handle(usb, pipe),
__cvmx_usb_get_submit_handle(usb, transaction),
transaction->stage);
CVMX_SYNCW;
usb->pipe_for_channel[channel] = pipe;
pipe->channel = channel;
pipe->flags |= __CVMX_USB_PIPE_FLAGS_SCHEDULED;
usb->idle_hardware_channels &= ~(1<<channel);
{
cvmx_usbcx_hcintx_t usbc_hcint;
cvmx_usbcx_hcintmskx_t usbc_hcintmsk;
cvmx_usbcx_haintmsk_t usbc_haintmsk;
usbc_hcint.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCINTX(channel, usb->index));
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCINTX(channel, usb->index), usbc_hcint.u32);
usbc_hcintmsk.u32 = 0;
usbc_hcintmsk.s.chhltdmsk = 1;
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA) {
usbc_hcintmsk.s.datatglerrmsk = 1;
usbc_hcintmsk.s.frmovrunmsk = 1;
usbc_hcintmsk.s.bblerrmsk = 1;
usbc_hcintmsk.s.xacterrmsk = 1;
if (__cvmx_usb_pipe_needs_split(usb, pipe)) {
usbc_hcintmsk.s.nyetmsk = 1;
usbc_hcintmsk.s.ackmsk = 1;
}
usbc_hcintmsk.s.nakmsk = 1;
usbc_hcintmsk.s.stallmsk = 1;
usbc_hcintmsk.s.xfercomplmsk = 1;
}
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCINTMSKX(channel, usb->index), usbc_hcintmsk.u32);
usbc_haintmsk.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HAINTMSK(usb->index));
usbc_haintmsk.s.haintmsk |= 1<<channel;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HAINTMSK(usb->index), usbc_haintmsk.u32);
}
{
uint64_t dma_address = transaction->buffer + transaction->actual_bytes;
if (transaction->type == CVMX_USB_TRANSFER_ISOCHRONOUS)
dma_address = transaction->buffer + transaction->iso_packets[0].offset + transaction->actual_bytes;
__cvmx_usb_write_csr64(usb, CVMX_USBNX_DMA0_OUTB_CHN0(usb->index) + channel*8, dma_address);
__cvmx_usb_write_csr64(usb, CVMX_USBNX_DMA0_INB_CHN0(usb->index) + channel*8, dma_address);
}
{
cvmx_usbcx_hcspltx_t usbc_hcsplt = {.u32 = 0};
cvmx_usbcx_hctsizx_t usbc_hctsiz = {.u32 = 0};
int packets_to_transfer;
int bytes_to_transfer = transaction->buffer_length - transaction->actual_bytes;
if (transaction->type == CVMX_USB_TRANSFER_ISOCHRONOUS)
bytes_to_transfer = transaction->iso_packets[0].length - transaction->actual_bytes;
if (__cvmx_usb_pipe_needs_split(usb, pipe)) {
if ((transaction->stage&1) == 0) {
if (transaction->type == CVMX_USB_TRANSFER_BULK)
pipe->split_sc_frame = (usb->frame_number + 1) & 0x7f;
else
pipe->split_sc_frame = (usb->frame_number + 2) & 0x7f;
}
else
pipe->split_sc_frame = -1;
usbc_hcsplt.s.spltena = 1;
usbc_hcsplt.s.hubaddr = pipe->hub_device_addr;
usbc_hcsplt.s.prtaddr = pipe->hub_port;
usbc_hcsplt.s.compsplt = (transaction->stage == CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE);
if (bytes_to_transfer > pipe->max_packet)
bytes_to_transfer = pipe->max_packet;
if (!usbc_hcsplt.s.compsplt &&
(pipe->transfer_dir == CVMX_USB_DIRECTION_OUT) &&
(pipe->transfer_type == CVMX_USB_TRANSFER_ISOCHRONOUS)) {
pipe->split_sc_frame = -1;
if (transaction->actual_bytes == 0) {
if (bytes_to_transfer <= 188)
usbc_hcsplt.s.xactpos = 3;
else
usbc_hcsplt.s.xactpos = 2;
}
else {
if (bytes_to_transfer <= 188)
usbc_hcsplt.s.xactpos = 1;
else
usbc_hcsplt.s.xactpos = 0;
}
if (bytes_to_transfer > 188)
bytes_to_transfer = 188;
}
}
if (bytes_to_transfer > MAX_TRANSFER_BYTES) {
bytes_to_transfer = MAX_TRANSFER_BYTES / pipe->max_packet;
bytes_to_transfer *= pipe->max_packet;
}
packets_to_transfer = (bytes_to_transfer + pipe->max_packet - 1) / pipe->max_packet;
if (packets_to_transfer == 0)
packets_to_transfer = 1;
else if ((packets_to_transfer>1) && (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)) {
packets_to_transfer = 1;
bytes_to_transfer = packets_to_transfer * pipe->max_packet;
}
else if (packets_to_transfer > MAX_TRANSFER_PACKETS) {
packets_to_transfer = MAX_TRANSFER_PACKETS;
bytes_to_transfer = packets_to_transfer * pipe->max_packet;
}
usbc_hctsiz.s.xfersize = bytes_to_transfer;
usbc_hctsiz.s.pktcnt = packets_to_transfer;
usbc_hctsiz.s.pid = __cvmx_usb_get_data_pid(pipe);
if (pipe->flags & __CVMX_USB_PIPE_FLAGS_NEED_PING)
usbc_hctsiz.s.dopng = 1;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCSPLTX(channel, usb->index), usbc_hcsplt.u32);
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCTSIZX(channel, usb->index), usbc_hctsiz.u32);
}
{
cvmx_usbcx_hccharx_t usbc_hcchar = {.u32 = 0};
usbc_hcchar.s.oddfrm = usb->frame_number&1;
if (__cvmx_usb_pipe_needs_split(usb, pipe))
usbc_hcchar.s.ec = 1;
else if (pipe->multi_count < 1)
usbc_hcchar.s.ec = 1;
else if (pipe->multi_count > 3)
usbc_hcchar.s.ec = 3;
else
usbc_hcchar.s.ec = pipe->multi_count;
usbc_hcchar.s.devaddr = pipe->device_addr;
usbc_hcchar.s.eptype = transaction->type;
usbc_hcchar.s.lspddev = (pipe->device_speed == CVMX_USB_SPEED_LOW);
usbc_hcchar.s.epdir = pipe->transfer_dir;
usbc_hcchar.s.epnum = pipe->endpoint_num;
usbc_hcchar.s.mps = pipe->max_packet;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCCHARX(channel, usb->index), usbc_hcchar.u32);
}
switch (transaction->type) {
case CVMX_USB_TRANSFER_CONTROL:
__cvmx_usb_start_channel_control(usb, channel, pipe);
break;
case CVMX_USB_TRANSFER_BULK:
case CVMX_USB_TRANSFER_INTERRUPT:
break;
case CVMX_USB_TRANSFER_ISOCHRONOUS:
if (!__cvmx_usb_pipe_needs_split(usb, pipe)) {
if (pipe->transfer_dir == CVMX_USB_DIRECTION_OUT) {
if (pipe->multi_count < 2)
USB_SET_FIELD32(CVMX_USBCX_HCTSIZX(channel, usb->index), cvmx_usbcx_hctsizx_t, pid, 0);
else
USB_SET_FIELD32(CVMX_USBCX_HCTSIZX(channel, usb->index), cvmx_usbcx_hctsizx_t, pid, 3);
}
}
break;
}
{
cvmx_usbcx_hctsizx_t usbc_hctsiz = {.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCTSIZX(channel, usb->index))};
transaction->xfersize = usbc_hctsiz.s.xfersize;
transaction->pktcnt = usbc_hctsiz.s.pktcnt;
}
if (__cvmx_usb_pipe_needs_split(usb, pipe))
usb->active_split = transaction;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index), cvmx_usbcx_hccharx_t, chena, 1);
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
__cvmx_usb_fill_tx_fifo(usb, channel);
CVMX_USB_RETURN_NOTHING();
}
static cvmx_usb_pipe_t *__cvmx_usb_find_ready_pipe(cvmx_usb_internal_state_t *usb, cvmx_usb_pipe_list_t *list, uint64_t current_frame)
{
cvmx_usb_pipe_t *pipe = list->head;
while (pipe) {
if (!(pipe->flags & __CVMX_USB_PIPE_FLAGS_SCHEDULED) && pipe->head &&
(pipe->next_tx_frame <= current_frame) &&
((pipe->split_sc_frame == -1) || ((((int)current_frame - (int)pipe->split_sc_frame) & 0x7f) < 0x40)) &&
(!usb->active_split || (usb->active_split == pipe->head))) {
CVMX_PREFETCH(pipe, 128);
CVMX_PREFETCH(pipe->head, 0);
return pipe;
}
pipe = pipe->next;
}
return NULL;
}
static void __cvmx_usb_schedule(cvmx_usb_internal_state_t *usb, int is_sof)
{
int channel;
cvmx_usb_pipe_t *pipe;
int need_sof;
cvmx_usb_transfer_t ttype;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA) {
cvmx_usbcx_hfnum_t hfnum = {.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HFNUM(usb->index))};
cvmx_usbcx_hfir_t hfir = {.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HFIR(usb->index))};
if (hfnum.s.frrem < hfir.s.frint/4)
goto done;
}
while (usb->idle_hardware_channels) {
CVMX_CLZ(channel, usb->idle_hardware_channels);
channel = 31 - channel;
if (cvmx_unlikely(channel > 7)) {
if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_INFO))
cvmx_dprintf("%s: Idle hardware channels has a channel higher than 7. This is wrong\n", __FUNCTION__);
break;
}
pipe = NULL;
if (is_sof) {
pipe = __cvmx_usb_find_ready_pipe(usb, usb->active_pipes + CVMX_USB_TRANSFER_ISOCHRONOUS, usb->frame_number);
if (cvmx_likely(!pipe))
pipe = __cvmx_usb_find_ready_pipe(usb, usb->active_pipes + CVMX_USB_TRANSFER_INTERRUPT, usb->frame_number);
}
if (cvmx_likely(!pipe)) {
pipe = __cvmx_usb_find_ready_pipe(usb, usb->active_pipes + CVMX_USB_TRANSFER_CONTROL, usb->frame_number);
if (cvmx_likely(!pipe))
pipe = __cvmx_usb_find_ready_pipe(usb, usb->active_pipes + CVMX_USB_TRANSFER_BULK, usb->frame_number);
}
if (!pipe)
break;
CVMX_USB_LOG_PARAM("%d", channel);
CVMX_USB_LOG_PARAM("%p", pipe);
if (cvmx_unlikely((usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_TRANSFERS) ||
(pipe->flags & CVMX_USB_PIPE_FLAGS_DEBUG_TRANSFERS))) {
cvmx_usb_transaction_t *transaction = pipe->head;
const cvmx_usb_control_header_t *header = (transaction->control_header) ? cvmx_phys_to_ptr(transaction->control_header) : NULL;
const char *dir = (pipe->transfer_dir == CVMX_USB_DIRECTION_IN) ? "IN" : "OUT";
const char *type;
switch (pipe->transfer_type) {
case CVMX_USB_TRANSFER_CONTROL:
type = "SETUP";
dir = (header->s.request_type & 0x80) ? "IN" : "OUT";
break;
case CVMX_USB_TRANSFER_ISOCHRONOUS:
type = "ISOCHRONOUS";
break;
case CVMX_USB_TRANSFER_BULK:
type = "BULK";
break;
default:
type = "INTERRUPT";
break;
}
cvmx_dprintf("%s: Starting pipe %d, transaction %d on channel %d. %s %s len=%d header=0x%llx\n",
__FUNCTION__, __cvmx_usb_get_pipe_handle(usb, pipe),
__cvmx_usb_get_submit_handle(usb, transaction),
channel, type, dir,
transaction->buffer_length,
(header) ? (unsigned long long)header->u64 : 0ull);
}
__cvmx_usb_start_channel(usb, channel, pipe);
}
done:
need_sof = 0;
for (ttype=CVMX_USB_TRANSFER_CONTROL; ttype<=CVMX_USB_TRANSFER_INTERRUPT; ttype++) {
pipe = usb->active_pipes[ttype].head;
while (pipe) {
if (pipe->next_tx_frame > usb->frame_number) {
need_sof = 1;
break;
}
pipe=pipe->next;
}
}
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index), cvmx_usbcx_gintmsk_t, sofmsk, need_sof);
CVMX_USB_RETURN_NOTHING();
}
static void __cvmx_usb_perform_callback(cvmx_usb_internal_state_t *usb,
cvmx_usb_pipe_t *pipe,
cvmx_usb_transaction_t *transaction,
cvmx_usb_callback_t reason,
cvmx_usb_complete_t complete_code)
{
cvmx_usb_callback_func_t callback = usb->callback[reason];
void *user_data = usb->callback_data[reason];
int submit_handle = -1;
int pipe_handle = -1;
int bytes_transferred = 0;
if (pipe)
pipe_handle = __cvmx_usb_get_pipe_handle(usb, pipe);
if (transaction) {
submit_handle = __cvmx_usb_get_submit_handle(usb, transaction);
bytes_transferred = transaction->actual_bytes;
if ((reason == CVMX_USB_CALLBACK_TRANSFER_COMPLETE) && transaction->callback) {
callback = transaction->callback;
user_data = transaction->callback_data;
}
}
if (!callback)
return;
if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_CALLBACKS))
cvmx_dprintf("%*s%s: calling callback %p(usb=%p, complete_code=%s, "
"pipe_handle=%d, submit_handle=%d, bytes_transferred=%d, user_data=%p);\n",
2*usb->indent, "", __FUNCTION__, callback, usb,
__cvmx_usb_complete_to_string(complete_code),
pipe_handle, submit_handle, bytes_transferred, user_data);
callback((cvmx_usb_state_t *)usb, reason, complete_code, pipe_handle, submit_handle,
bytes_transferred, user_data);
if (cvmx_unlikely(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_CALLBACKS))
cvmx_dprintf("%*s%s: callback %p complete\n", 2*usb->indent, "",
__FUNCTION__, callback);
}
static void __cvmx_usb_perform_complete(cvmx_usb_internal_state_t * usb,
cvmx_usb_pipe_t *pipe,
cvmx_usb_transaction_t *transaction,
cvmx_usb_complete_t complete_code)
{
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
CVMX_USB_LOG_PARAM("%p", pipe);
CVMX_USB_LOG_PARAM("%p", transaction);
CVMX_USB_LOG_PARAM("%d", complete_code);
if (usb->active_split == transaction)
usb->active_split = NULL;
if (cvmx_unlikely(transaction->type == CVMX_USB_TRANSFER_ISOCHRONOUS)) {
transaction->iso_packets[0].length = transaction->actual_bytes;
transaction->iso_packets[0].status = complete_code;
if ((transaction->iso_number_packets > 1) && (complete_code == CVMX_USB_COMPLETE_SUCCESS)) {
transaction->actual_bytes = 0;
transaction->iso_number_packets--;
transaction->iso_packets++;
transaction->stage = CVMX_USB_STAGE_NON_CONTROL;
goto done;
}
}
if (transaction->next)
transaction->next->prev = transaction->prev;
else
pipe->tail = transaction->prev;
if (transaction->prev)
transaction->prev->next = transaction->next;
else
pipe->head = transaction->next;
if (!pipe->head) {
__cvmx_usb_remove_pipe(usb->active_pipes + pipe->transfer_type, pipe);
__cvmx_usb_append_pipe(&usb->idle_pipes, pipe);
}
__cvmx_usb_perform_callback(usb, pipe, transaction,
CVMX_USB_CALLBACK_TRANSFER_COMPLETE,
complete_code);
__cvmx_usb_free_transaction(usb, transaction);
done:
CVMX_USB_RETURN_NOTHING();
}
static int __cvmx_usb_submit_transaction(cvmx_usb_internal_state_t *usb,
int pipe_handle,
cvmx_usb_transfer_t type,
int flags,
uint64_t buffer,
int buffer_length,
uint64_t control_header,
int iso_start_frame,
int iso_number_packets,
cvmx_usb_iso_packet_t *iso_packets,
cvmx_usb_callback_func_t callback,
void *user_data)
{
int submit_handle;
cvmx_usb_transaction_t *transaction;
cvmx_usb_pipe_t *pipe = usb->pipe + pipe_handle;
CVMX_USB_LOG_CALLED();
if (cvmx_unlikely((pipe_handle < 0) || (pipe_handle >= MAX_PIPES)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((pipe->flags & __CVMX_USB_PIPE_FLAGS_OPEN) == 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(pipe->transfer_type != type))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
transaction = __cvmx_usb_alloc_transaction(usb);
if (cvmx_unlikely(!transaction))
CVMX_USB_RETURN(CVMX_USB_NO_MEMORY);
transaction->type = type;
transaction->flags |= flags;
transaction->buffer = buffer;
transaction->buffer_length = buffer_length;
transaction->control_header = control_header;
transaction->iso_start_frame = iso_start_frame;
transaction->iso_number_packets = iso_number_packets;
transaction->iso_packets = iso_packets;
transaction->callback = callback;
transaction->callback_data = user_data;
if (transaction->type == CVMX_USB_TRANSFER_CONTROL)
transaction->stage = CVMX_USB_STAGE_SETUP;
else
transaction->stage = CVMX_USB_STAGE_NON_CONTROL;
transaction->next = NULL;
if (pipe->tail) {
transaction->prev = pipe->tail;
transaction->prev->next = transaction;
}
else {
if (pipe->next_tx_frame < usb->frame_number)
pipe->next_tx_frame = usb->frame_number + pipe->interval -
(usb->frame_number - pipe->next_tx_frame) % pipe->interval;
transaction->prev = NULL;
pipe->head = transaction;
__cvmx_usb_remove_pipe(&usb->idle_pipes, pipe);
__cvmx_usb_append_pipe(usb->active_pipes + pipe->transfer_type, pipe);
}
pipe->tail = transaction;
submit_handle = __cvmx_usb_get_submit_handle(usb, transaction);
if (!transaction->prev)
__cvmx_usb_schedule(usb, 0);
CVMX_USB_RETURN(submit_handle);
}
int cvmx_usb_submit_bulk(cvmx_usb_state_t *state, int pipe_handle,
uint64_t buffer, int buffer_length,
cvmx_usb_callback_func_t callback,
void *user_data)
{
int submit_handle;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", pipe_handle);
CVMX_USB_LOG_PARAM("0x%llx", (unsigned long long)buffer);
CVMX_USB_LOG_PARAM("%d", buffer_length);
if (cvmx_unlikely(!buffer))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(buffer_length < 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
submit_handle = __cvmx_usb_submit_transaction(usb, pipe_handle,
CVMX_USB_TRANSFER_BULK,
0,
buffer,
buffer_length,
0,
0,
0,
NULL,
callback,
user_data);
CVMX_USB_RETURN(submit_handle);
}
int cvmx_usb_submit_interrupt(cvmx_usb_state_t *state, int pipe_handle,
uint64_t buffer, int buffer_length,
cvmx_usb_callback_func_t callback,
void *user_data)
{
int submit_handle;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", pipe_handle);
CVMX_USB_LOG_PARAM("0x%llx", (unsigned long long)buffer);
CVMX_USB_LOG_PARAM("%d", buffer_length);
if (cvmx_unlikely(!buffer))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(buffer_length < 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
submit_handle = __cvmx_usb_submit_transaction(usb, pipe_handle,
CVMX_USB_TRANSFER_INTERRUPT,
0,
buffer,
buffer_length,
0,
0,
0,
NULL,
callback,
user_data);
CVMX_USB_RETURN(submit_handle);
}
int cvmx_usb_submit_control(cvmx_usb_state_t *state, int pipe_handle,
uint64_t control_header,
uint64_t buffer, int buffer_length,
cvmx_usb_callback_func_t callback,
void *user_data)
{
int submit_handle;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
cvmx_usb_control_header_t *header = cvmx_phys_to_ptr(control_header);
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", pipe_handle);
CVMX_USB_LOG_PARAM("0x%llx", (unsigned long long)control_header);
CVMX_USB_LOG_PARAM("0x%llx", (unsigned long long)buffer);
CVMX_USB_LOG_PARAM("%d", buffer_length);
if (cvmx_unlikely(!control_header))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(buffer && (buffer_length < 0)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(!buffer && (buffer_length != 0)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if ((header->s.request_type & 0x80) == 0)
buffer_length = cvmx_le16_to_cpu(header->s.length);
submit_handle = __cvmx_usb_submit_transaction(usb, pipe_handle,
CVMX_USB_TRANSFER_CONTROL,
0,
buffer,
buffer_length,
control_header,
0,
0,
NULL,
callback,
user_data);
CVMX_USB_RETURN(submit_handle);
}
int cvmx_usb_submit_isochronous(cvmx_usb_state_t *state, int pipe_handle,
int start_frame, int flags,
int number_packets,
cvmx_usb_iso_packet_t packets[],
uint64_t buffer, int buffer_length,
cvmx_usb_callback_func_t callback,
void *user_data)
{
int submit_handle;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", pipe_handle);
CVMX_USB_LOG_PARAM("%d", start_frame);
CVMX_USB_LOG_PARAM("0x%x", flags);
CVMX_USB_LOG_PARAM("%d", number_packets);
CVMX_USB_LOG_PARAM("%p", packets);
CVMX_USB_LOG_PARAM("0x%llx", (unsigned long long)buffer);
CVMX_USB_LOG_PARAM("%d", buffer_length);
if (cvmx_unlikely(start_frame < 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(flags & ~(CVMX_USB_ISOCHRONOUS_FLAGS_ALLOW_SHORT | CVMX_USB_ISOCHRONOUS_FLAGS_ASAP)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(number_packets < 1))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(!packets))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(!buffer))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(buffer_length < 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
submit_handle = __cvmx_usb_submit_transaction(usb, pipe_handle,
CVMX_USB_TRANSFER_ISOCHRONOUS,
flags,
buffer,
buffer_length,
0,
start_frame,
number_packets,
packets,
callback,
user_data);
CVMX_USB_RETURN(submit_handle);
}
cvmx_usb_status_t cvmx_usb_cancel(cvmx_usb_state_t *state, int pipe_handle,
int submit_handle)
{
cvmx_usb_transaction_t *transaction;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
cvmx_usb_pipe_t *pipe = usb->pipe + pipe_handle;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", pipe_handle);
CVMX_USB_LOG_PARAM("%d", submit_handle);
if (cvmx_unlikely((pipe_handle < 0) || (pipe_handle >= MAX_PIPES)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((submit_handle < 0) || (submit_handle >= MAX_TRANSACTIONS)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((pipe->flags & __CVMX_USB_PIPE_FLAGS_OPEN) == 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
transaction = usb->transaction + submit_handle;
if (cvmx_unlikely((transaction->flags & __CVMX_USB_TRANSACTION_FLAGS_IN_USE) == 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if ((pipe->head == transaction) &&
(pipe->flags & __CVMX_USB_PIPE_FLAGS_SCHEDULED)) {
cvmx_usbcx_hccharx_t usbc_hcchar;
usb->pipe_for_channel[pipe->channel] = NULL;
pipe->flags &= ~__CVMX_USB_PIPE_FLAGS_SCHEDULED;
CVMX_SYNCW;
usbc_hcchar.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCCHARX(pipe->channel, usb->index));
if (usbc_hcchar.s.chena) {
usbc_hcchar.s.chdis = 1;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCCHARX(pipe->channel, usb->index), usbc_hcchar.u32);
}
}
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_CANCEL);
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
cvmx_usb_status_t cvmx_usb_cancel_all(cvmx_usb_state_t *state, int pipe_handle)
{
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
cvmx_usb_pipe_t *pipe = usb->pipe + pipe_handle;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", pipe_handle);
if (cvmx_unlikely((pipe_handle < 0) || (pipe_handle >= MAX_PIPES)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((pipe->flags & __CVMX_USB_PIPE_FLAGS_OPEN) == 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
while (pipe->head) {
cvmx_usb_status_t result = cvmx_usb_cancel(state, pipe_handle,
__cvmx_usb_get_submit_handle(usb, pipe->head));
if (cvmx_unlikely(result != CVMX_USB_SUCCESS))
CVMX_USB_RETURN(result);
}
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
cvmx_usb_status_t cvmx_usb_close_pipe(cvmx_usb_state_t *state, int pipe_handle)
{
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
cvmx_usb_pipe_t *pipe = usb->pipe + pipe_handle;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", pipe_handle);
if (cvmx_unlikely((pipe_handle < 0) || (pipe_handle >= MAX_PIPES)))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely((pipe->flags & __CVMX_USB_PIPE_FLAGS_OPEN) == 0))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(pipe->head))
CVMX_USB_RETURN(CVMX_USB_BUSY);
pipe->flags = 0;
__cvmx_usb_remove_pipe(&usb->idle_pipes, pipe);
__cvmx_usb_append_pipe(&usb->free_pipes, pipe);
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
cvmx_usb_status_t cvmx_usb_register_callback(cvmx_usb_state_t *state,
cvmx_usb_callback_t reason,
cvmx_usb_callback_func_t callback,
void *user_data)
{
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
CVMX_USB_LOG_PARAM("%d", reason);
CVMX_USB_LOG_PARAM("%p", callback);
CVMX_USB_LOG_PARAM("%p", user_data);
if (cvmx_unlikely(reason >= __CVMX_USB_CALLBACK_END))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
if (cvmx_unlikely(!callback))
CVMX_USB_RETURN(CVMX_USB_INVALID_PARAM);
usb->callback[reason] = callback;
usb->callback_data[reason] = user_data;
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
int cvmx_usb_get_frame_number(cvmx_usb_state_t *state)
{
int frame_number;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
cvmx_usbcx_hfnum_t usbc_hfnum;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
usbc_hfnum.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HFNUM(usb->index));
frame_number = usbc_hfnum.s.frnum;
CVMX_USB_RETURN(frame_number);
}
static int __cvmx_usb_poll_channel(cvmx_usb_internal_state_t *usb, int channel)
{
cvmx_usbcx_hcintx_t usbc_hcint;
cvmx_usbcx_hctsizx_t usbc_hctsiz;
cvmx_usbcx_hccharx_t usbc_hcchar;
cvmx_usb_pipe_t *pipe;
cvmx_usb_transaction_t *transaction;
int bytes_this_transfer;
int bytes_in_last_packet;
int packets_processed;
int buffer_space_left;
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", usb);
CVMX_USB_LOG_PARAM("%d", channel);
usbc_hcint.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCINTX(channel, usb->index));
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA) {
usbc_hcchar.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCCHARX(channel, usb->index));
if (usbc_hcchar.s.chena && usbc_hcchar.s.chdis) {
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCCHARX(channel, usb->index), usbc_hcchar.u32);
CVMX_USB_RETURN(0);
}
if (!usbc_hcint.s.chhltd) {
if (usbc_hcchar.s.chena) {
cvmx_usbcx_hcintmskx_t hcintmsk;
hcintmsk.u32 = 0;
hcintmsk.s.chhltdmsk = 1;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCINTMSKX(channel, usb->index), hcintmsk.u32);
usbc_hcchar.s.chdis = 1;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCCHARX(channel, usb->index), usbc_hcchar.u32);
CVMX_USB_RETURN(0);
}
else if (usbc_hcint.s.xfercompl) {
}
else {
cvmx_dprintf("USB%d: Channel %d interrupt without halt\n", usb->index, channel);
CVMX_USB_RETURN(0);
}
}
}
else {
if (!usbc_hcint.s.chhltd)
CVMX_USB_RETURN(0);
}
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HCINTMSKX(channel, usb->index), 0);
usb->idle_hardware_channels |= (1<<channel);
pipe = usb->pipe_for_channel[channel];
CVMX_PREFETCH(pipe, 0);
CVMX_PREFETCH(pipe, 128);
if (!pipe)
CVMX_USB_RETURN(0);
transaction = pipe->head;
CVMX_PREFETCH0(transaction);
usb->pipe_for_channel[channel] = NULL;
pipe->flags &= ~__CVMX_USB_PIPE_FLAGS_SCHEDULED;
usbc_hcchar.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCCHARX(channel, usb->index));
usbc_hctsiz.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HCTSIZX(channel, usb->index));
packets_processed = transaction->pktcnt - usbc_hctsiz.s.pktcnt;
if (usbc_hcchar.s.epdir) {
bytes_this_transfer = transaction->xfersize - usbc_hctsiz.s.xfersize;
}
else {
bytes_this_transfer = packets_processed * usbc_hcchar.s.mps;
if (bytes_this_transfer > transaction->xfersize)
bytes_this_transfer = transaction->xfersize;
}
if (packets_processed)
bytes_in_last_packet = bytes_this_transfer - (packets_processed-1) * usbc_hcchar.s.mps;
else
bytes_in_last_packet = bytes_this_transfer;
if ((transaction->stage == CVMX_USB_STAGE_SETUP) ||
(transaction->stage == CVMX_USB_STAGE_SETUP_SPLIT_COMPLETE))
bytes_this_transfer = 0;
if (cvmx_unlikely((usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_DEBUG_TRANSFERS) ||
(pipe->flags & CVMX_USB_PIPE_FLAGS_DEBUG_TRANSFERS)))
cvmx_dprintf("%s: Channel %d halted. Pipe %d transaction %d stage %d bytes=%d\n",
__FUNCTION__, channel,
__cvmx_usb_get_pipe_handle(usb, pipe),
__cvmx_usb_get_submit_handle(usb, transaction),
transaction->stage, bytes_this_transfer);
transaction->actual_bytes += bytes_this_transfer;
if (transaction->type == CVMX_USB_TRANSFER_ISOCHRONOUS)
buffer_space_left = transaction->iso_packets[0].length - transaction->actual_bytes;
else
buffer_space_left = transaction->buffer_length - transaction->actual_bytes;
pipe->pid_toggle = !(usbc_hctsiz.s.pid == 0);
if ((pipe->device_speed == CVMX_USB_SPEED_HIGH) &&
(pipe->transfer_type == CVMX_USB_TRANSFER_BULK) &&
(pipe->transfer_dir == CVMX_USB_DIRECTION_OUT))
pipe->flags |= __CVMX_USB_PIPE_FLAGS_NEED_PING;
if (usbc_hcint.s.stall) {
pipe->pid_toggle = 0;
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_STALL);
}
else if (usbc_hcint.s.xacterr) {
if (usbc_hcint.s.nak || usbc_hcint.s.ack)
transaction->retries = 0;
transaction->retries++;
if (transaction->retries > MAX_RETRIES) {
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_XACTERR);
}
else {
if (usb->active_split == transaction)
usb->active_split = NULL;
transaction->stage &= ~1;
pipe->split_sc_frame = -1;
pipe->next_tx_frame += pipe->interval;
if (pipe->next_tx_frame < usb->frame_number)
pipe->next_tx_frame = usb->frame_number + pipe->interval -
(usb->frame_number - pipe->next_tx_frame) % pipe->interval;
}
}
else if (usbc_hcint.s.bblerr)
{
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_BABBLEERR);
}
else if (usbc_hcint.s.datatglerr)
{
transaction->retries++;
}
else if (usbc_hcint.s.nyet) {
if (!__cvmx_usb_pipe_needs_split(usb, pipe)) {
transaction->retries = 0;
if ((buffer_space_left == 0) || (bytes_in_last_packet < pipe->max_packet))
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_SUCCESS);
}
else {
transaction->retries++;
if ((transaction->retries & 0x3) == 0) {
transaction->stage &= ~1;
pipe->split_sc_frame = -1;
}
}
}
else if (usbc_hcint.s.ack) {
transaction->retries = 0;
pipe->flags &= ~__CVMX_USB_PIPE_FLAGS_NEED_PING;
switch (transaction->type)
{
case CVMX_USB_TRANSFER_CONTROL:
switch (transaction->stage)
{
case CVMX_USB_STAGE_NON_CONTROL:
case CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE:
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_ERROR);
break;
case CVMX_USB_STAGE_SETUP:
pipe->pid_toggle = 1;
if (__cvmx_usb_pipe_needs_split(usb, pipe))
transaction->stage = CVMX_USB_STAGE_SETUP_SPLIT_COMPLETE;
else {
cvmx_usb_control_header_t *header = cvmx_phys_to_ptr(transaction->control_header);
if (header->s.length)
transaction->stage = CVMX_USB_STAGE_DATA;
else
transaction->stage = CVMX_USB_STAGE_STATUS;
}
break;
case CVMX_USB_STAGE_SETUP_SPLIT_COMPLETE:
{
cvmx_usb_control_header_t *header = cvmx_phys_to_ptr(transaction->control_header);
if (header->s.length)
transaction->stage = CVMX_USB_STAGE_DATA;
else
transaction->stage = CVMX_USB_STAGE_STATUS;
}
break;
case CVMX_USB_STAGE_DATA:
if (__cvmx_usb_pipe_needs_split(usb, pipe)) {
transaction->stage = CVMX_USB_STAGE_DATA_SPLIT_COMPLETE;
if (!usbc_hcchar.s.epdir) {
if (buffer_space_left < pipe->max_packet)
transaction->actual_bytes += buffer_space_left;
else
transaction->actual_bytes += pipe->max_packet;
}
}
else if ((buffer_space_left == 0) || (bytes_in_last_packet < pipe->max_packet)) {
pipe->pid_toggle = 1;
transaction->stage = CVMX_USB_STAGE_STATUS;
}
break;
case CVMX_USB_STAGE_DATA_SPLIT_COMPLETE:
if ((buffer_space_left == 0) || (bytes_in_last_packet < pipe->max_packet)) {
pipe->pid_toggle = 1;
transaction->stage = CVMX_USB_STAGE_STATUS;
}
else {
transaction->stage = CVMX_USB_STAGE_DATA;
}
break;
case CVMX_USB_STAGE_STATUS:
if (__cvmx_usb_pipe_needs_split(usb, pipe))
transaction->stage = CVMX_USB_STAGE_STATUS_SPLIT_COMPLETE;
else
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_SUCCESS);
break;
case CVMX_USB_STAGE_STATUS_SPLIT_COMPLETE:
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_SUCCESS);
break;
}
break;
case CVMX_USB_TRANSFER_BULK:
case CVMX_USB_TRANSFER_INTERRUPT:
if (__cvmx_usb_pipe_needs_split(usb, pipe)) {
if (transaction->stage == CVMX_USB_STAGE_NON_CONTROL)
transaction->stage = CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE;
else {
if (buffer_space_left && (bytes_in_last_packet == pipe->max_packet))
transaction->stage = CVMX_USB_STAGE_NON_CONTROL;
else {
if (transaction->type == CVMX_USB_TRANSFER_INTERRUPT)
pipe->next_tx_frame += pipe->interval;
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_SUCCESS);
}
}
}
else {
if ((pipe->device_speed == CVMX_USB_SPEED_HIGH) &&
(pipe->transfer_type == CVMX_USB_TRANSFER_BULK) &&
(pipe->transfer_dir == CVMX_USB_DIRECTION_OUT) &&
(usbc_hcint.s.nak))
pipe->flags |= __CVMX_USB_PIPE_FLAGS_NEED_PING;
if (!buffer_space_left || (bytes_in_last_packet < pipe->max_packet)) {
if (transaction->type == CVMX_USB_TRANSFER_INTERRUPT)
pipe->next_tx_frame += pipe->interval;
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_SUCCESS);
}
}
break;
case CVMX_USB_TRANSFER_ISOCHRONOUS:
if (__cvmx_usb_pipe_needs_split(usb, pipe)) {
if (pipe->transfer_dir == CVMX_USB_DIRECTION_OUT) {
if (!buffer_space_left || (bytes_this_transfer < 188)) {
pipe->next_tx_frame += pipe->interval;
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_SUCCESS);
}
}
else {
if (transaction->stage == CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE) {
if ((buffer_space_left == 0) || (bytes_in_last_packet < pipe->max_packet)) {
pipe->next_tx_frame += pipe->interval;
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_SUCCESS);
}
}
else
transaction->stage = CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE;
}
}
else {
pipe->next_tx_frame += pipe->interval;
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_SUCCESS);
}
break;
}
}
else if (usbc_hcint.s.nak) {
if (usb->active_split == transaction)
usb->active_split = NULL;
transaction->retries = 0;
transaction->stage &= ~1;
pipe->next_tx_frame += pipe->interval;
if (pipe->next_tx_frame < usb->frame_number)
pipe->next_tx_frame = usb->frame_number + pipe->interval -
(usb->frame_number - pipe->next_tx_frame) % pipe->interval;
}
else {
cvmx_usb_port_status_t port;
port = cvmx_usb_get_status((cvmx_usb_state_t *)usb);
if (port.port_enabled)
{
transaction->retries++;
}
else
{
__cvmx_usb_perform_complete(usb, pipe, transaction, CVMX_USB_COMPLETE_ERROR);
}
}
CVMX_USB_RETURN(0);
}
cvmx_usb_status_t cvmx_usb_poll(cvmx_usb_state_t *state)
{
cvmx_usbcx_hfnum_t usbc_hfnum;
cvmx_usbcx_gintsts_t usbc_gintsts;
cvmx_usb_internal_state_t *usb = (cvmx_usb_internal_state_t*)state;
CVMX_PREFETCH(usb, 0);
CVMX_PREFETCH(usb, 1*128);
CVMX_PREFETCH(usb, 2*128);
CVMX_PREFETCH(usb, 3*128);
CVMX_PREFETCH(usb, 4*128);
CVMX_USB_LOG_CALLED();
CVMX_USB_LOG_PARAM("%p", state);
usbc_hfnum.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HFNUM(usb->index));
if ((usb->frame_number&0x3fff) > usbc_hfnum.s.frnum)
usb->frame_number += 0x4000;
usb->frame_number &= ~0x3fffull;
usb->frame_number |= usbc_hfnum.s.frnum;
usbc_gintsts.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_GINTSTS(usb->index));
__cvmx_usb_write_csr32(usb, CVMX_USBCX_GINTSTS(usb->index), usbc_gintsts.u32);
if (usbc_gintsts.s.rxflvl) {
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
__cvmx_usb_poll_rx_fifo(usb);
}
if (usbc_gintsts.s.ptxfemp || usbc_gintsts.s.nptxfemp) {
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
__cvmx_usb_poll_tx_fifo(usb);
}
if (usbc_gintsts.s.disconnint || usbc_gintsts.s.prtint) {
cvmx_usbcx_hprt_t usbc_hprt;
__cvmx_usb_perform_callback(usb, NULL, NULL,
CVMX_USB_CALLBACK_PORT_CHANGED,
CVMX_USB_COMPLETE_SUCCESS);
usbc_hprt.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HPRT(usb->index));
usbc_hprt.s.prtena = 0;
__cvmx_usb_write_csr32(usb, CVMX_USBCX_HPRT(usb->index), usbc_hprt.u32);
}
if (usbc_gintsts.s.hchint) {
cvmx_usbcx_haint_t usbc_haint;
usbc_haint.u32 = __cvmx_usb_read_csr32(usb, CVMX_USBCX_HAINT(usb->index));
while (usbc_haint.u32) {
int channel;
CVMX_CLZ(channel, usbc_haint.u32);
channel = 31 - channel;
__cvmx_usb_poll_channel(usb, channel);
usbc_haint.u32 ^= 1<<channel;
}
}
__cvmx_usb_schedule(usb, usbc_gintsts.s.sof);
CVMX_USB_RETURN(CVMX_USB_SUCCESS);
}
