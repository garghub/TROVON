static void hwerr_crcbits(struct ipath_devdata *dd, ipath_err_t hwerrs,
char *msg, size_t msgl)
{
char bitsmsg[64];
ipath_err_t crcbits = hwerrs &
(_IPATH_HTLINK0_CRCBITS | _IPATH_HTLINK1_CRCBITS);
if (dd->ipath_flags & IPATH_8BIT_IN_HT0)
crcbits &= ~infinipath_hwe_htclnkabyte1crcerr;
if (dd->ipath_flags & IPATH_8BIT_IN_HT1)
crcbits &= ~infinipath_hwe_htclnkbbyte1crcerr;
if (crcbits) {
u16 ctrl0, ctrl1;
snprintf(bitsmsg, sizeof bitsmsg,
"[HT%s lane %s CRC (%llx); powercycle to completely clear]",
!(crcbits & _IPATH_HTLINK1_CRCBITS) ?
"0 (A)" : (!(crcbits & _IPATH_HTLINK0_CRCBITS)
? "1 (B)" : "0+1 (A+B)"),
!(crcbits & _IPATH_HTLANE1_CRCBITS) ? "0"
: (!(crcbits & _IPATH_HTLANE0_CRCBITS) ? "1" :
"0+1"), (unsigned long long) crcbits);
strlcat(msg, bitsmsg, msgl);
if (pci_read_config_word(dd->pcidev,
dd->ipath_ht_slave_off + 0x4,
&ctrl0))
dev_info(&dd->pcidev->dev, "Couldn't read "
"linkctrl0 of slave/primary "
"config block\n");
else if (!(ctrl0 & 1 << 6))
ipath_dbg("HT linkctrl0 0x%x%s%s\n", ctrl0,
((ctrl0 >> 8) & 7) ? " CRC" : "",
((ctrl0 >> 4) & 1) ? "linkfail" :
"");
if (pci_read_config_word(dd->pcidev,
dd->ipath_ht_slave_off + 0x8,
&ctrl1))
dev_info(&dd->pcidev->dev, "Couldn't read "
"linkctrl1 of slave/primary "
"config block\n");
else if (!(ctrl1 & 1 << 6))
ipath_dbg("HT linkctrl1 0x%x%s%s\n", ctrl1,
((ctrl1 >> 8) & 7) ? " CRC" : "",
((ctrl1 >> 4) & 1) ? "linkfail" :
"");
dd->ipath_hwerrmask &= ~crcbits;
ipath_write_kreg(dd, dd->ipath_kregs->kr_hwerrmask,
dd->ipath_hwerrmask);
ipath_dbg("HT crc errs: %s\n", msg);
} else
ipath_dbg("ignoring HT crc errors 0x%llx, "
"not in use\n", (unsigned long long)
(hwerrs & (_IPATH_HTLINK0_CRCBITS |
_IPATH_HTLINK1_CRCBITS)));
}
static void ipath_ht_txe_recover(struct ipath_devdata *dd)
{
++ipath_stats.sps_txeparity;
dev_info(&dd->pcidev->dev,
"Recovering from TXE PIO parity error\n");
}
static void ipath_ht_handle_hwerrors(struct ipath_devdata *dd, char *msg,
size_t msgl)
{
ipath_err_t hwerrs;
u32 bits, ctrl;
int isfatal = 0;
char bitsmsg[64];
int log_idx;
hwerrs = ipath_read_kreg64(dd, dd->ipath_kregs->kr_hwerrstatus);
if (!hwerrs) {
ipath_cdbg(VERBOSE, "Called but no hardware errors set\n");
goto bail;
} else if (hwerrs == -1LL) {
ipath_dev_err(dd, "Read of hardware error status failed "
"(all bits set); ignoring\n");
goto bail;
}
ipath_stats.sps_hwerrs++;
ipath_write_kreg(dd, dd->ipath_kregs->kr_hwerrclear,
hwerrs&~INFINIPATH_HWE_MEMBISTFAILED);
hwerrs &= dd->ipath_hwerrmask;
for (log_idx = 0; log_idx < IPATH_EEP_LOG_CNT; ++log_idx)
if (hwerrs & dd->ipath_eep_st_masks[log_idx].hwerrs_to_log)
ipath_inc_eeprom_err(dd, log_idx, 1);
if ((hwerrs & ~(dd->ipath_lasthwerror | TXE_PIO_PARITY |
RXE_EAGER_PARITY)) ||
(ipath_debug & __IPATH_VERBDBG))
dev_info(&dd->pcidev->dev, "Hardware error: hwerr=0x%llx "
"(cleared)\n", (unsigned long long) hwerrs);
dd->ipath_lasthwerror |= hwerrs;
if (hwerrs & ~dd->ipath_hwe_bitsextant)
ipath_dev_err(dd, "hwerror interrupt with unknown errors "
"%llx set\n", (unsigned long long)
(hwerrs & ~dd->ipath_hwe_bitsextant));
ctrl = ipath_read_kreg32(dd, dd->ipath_kregs->kr_control);
if ((ctrl & INFINIPATH_C_FREEZEMODE) && !ipath_diag_inuse) {
if (hwerrs & TXE_PIO_PARITY) {
ipath_ht_txe_recover(dd);
hwerrs &= ~TXE_PIO_PARITY;
}
if (!hwerrs) {
ipath_dbg("Clearing freezemode on ignored or "
"recovered hardware error\n");
ipath_clear_freeze(dd);
}
}
*msg = '\0';
if (hwerrs & (infinipath_hwe_htcmemparityerr_mask
<< INFINIPATH_HWE_HTCMEMPARITYERR_SHIFT)) {
bits = (u32) ((hwerrs >>
INFINIPATH_HWE_HTCMEMPARITYERR_SHIFT) &
INFINIPATH_HWE_HTCMEMPARITYERR_MASK);
snprintf(bitsmsg, sizeof bitsmsg, "[HTC Parity Errs %x] ",
bits);
strlcat(msg, bitsmsg, msgl);
}
ipath_format_hwerrors(hwerrs,
ipath_6110_hwerror_msgs,
ARRAY_SIZE(ipath_6110_hwerror_msgs),
msg, msgl);
if (hwerrs & (_IPATH_HTLINK0_CRCBITS | _IPATH_HTLINK1_CRCBITS))
hwerr_crcbits(dd, hwerrs, msg, msgl);
if (hwerrs & INFINIPATH_HWE_MEMBISTFAILED) {
strlcat(msg, "[Memory BIST test failed, InfiniPath hardware unusable]",
msgl);
dd->ipath_hwerrmask &= ~INFINIPATH_HWE_MEMBISTFAILED;
ipath_write_kreg(dd, dd->ipath_kregs->kr_hwerrmask,
dd->ipath_hwerrmask);
}
#define _IPATH_PLL_FAIL (INFINIPATH_HWE_COREPLL_FBSLIP | \
INFINIPATH_HWE_COREPLL_RFSLIP | \
INFINIPATH_HWE_HTBPLL_FBSLIP | \
INFINIPATH_HWE_HTBPLL_RFSLIP | \
INFINIPATH_HWE_HTAPLL_FBSLIP | \
INFINIPATH_HWE_HTAPLL_RFSLIP)
if (hwerrs & _IPATH_PLL_FAIL) {
snprintf(bitsmsg, sizeof bitsmsg,
"[PLL failed (%llx), InfiniPath hardware unusable]",
(unsigned long long) (hwerrs & _IPATH_PLL_FAIL));
strlcat(msg, bitsmsg, msgl);
dd->ipath_hwerrmask &= ~(hwerrs & _IPATH_PLL_FAIL);
ipath_write_kreg(dd, dd->ipath_kregs->kr_hwerrmask,
dd->ipath_hwerrmask);
}
if (hwerrs & INFINIPATH_HWE_SERDESPLLFAILED) {
dd->ipath_hwerrmask &= ~INFINIPATH_HWE_SERDESPLLFAILED;
ipath_write_kreg(dd, dd->ipath_kregs->kr_hwerrmask,
dd->ipath_hwerrmask);
}
if (hwerrs) {
if (dd->ipath_flags & IPATH_INITTED) {
ipath_set_linkstate(dd, IPATH_IB_LINKDOWN);
ipath_setup_ht_setextled(dd,
INFINIPATH_IBCS_L_STATE_DOWN,
INFINIPATH_IBCS_LT_STATE_DISABLED);
ipath_dev_err(dd, "Fatal Hardware Error (freeze "
"mode), no longer usable, SN %.16s\n",
dd->ipath_serial);
isfatal = 1;
}
*dd->ipath_statusp &= ~IPATH_STATUS_IB_READY;
*dd->ipath_statusp |= IPATH_STATUS_HWERROR;
dd->ipath_flags &= ~IPATH_INITTED;
}
else
*msg = 0;
if (*msg)
ipath_dev_err(dd, "%s hardware error\n", msg);
if (isfatal && !ipath_diag_inuse && dd->ipath_freezemsg)
snprintf(dd->ipath_freezemsg,
dd->ipath_freezelen, "{%s}", msg);
bail:;
}
static int ipath_ht_boardname(struct ipath_devdata *dd, char *name,
size_t namelen)
{
char *n = NULL;
u8 boardrev = dd->ipath_boardrev;
int ret = 0;
switch (boardrev) {
case 5:
n = "InfiniPath_QHT7040";
break;
case 7:
n = "InfiniPath_QHT7140";
break;
default:
ipath_dev_err(dd, "Don't yet know about board "
"with ID %u\n", boardrev);
snprintf(name, namelen, "Unknown_InfiniPath_QHT7xxx_%u",
boardrev);
break;
}
if (n)
snprintf(name, namelen, "%s", n);
if (ret) {
ipath_dev_err(dd, "Unsupported InfiniPath board %s!\n", name);
goto bail;
}
if (dd->ipath_majrev != 3 || (dd->ipath_minrev < 2 ||
dd->ipath_minrev > 4)) {
ipath_dev_err(dd,
"Unsupported InfiniPath hardware revision %u.%u!\n",
dd->ipath_majrev, dd->ipath_minrev);
ret = 1;
goto bail;
}
dd->ipath_flags |= IPATH_32BITCOUNTERS;
dd->ipath_flags |= IPATH_GPIO_INTR;
if (dd->ipath_lbus_speed != 800)
ipath_dev_err(dd,
"Incorrectly configured for HT @ %uMHz\n",
dd->ipath_lbus_speed);
dd->ipath_ureg_align =
ipath_read_kreg32(dd, dd->ipath_kregs->kr_pagealign);
bail:
return ret;
}
static void ipath_check_htlink(struct ipath_devdata *dd)
{
u8 linkerr, link_off, i;
for (i = 0; i < 2; i++) {
link_off = dd->ipath_ht_slave_off + i * 4 + 0xd;
if (pci_read_config_byte(dd->pcidev, link_off, &linkerr))
dev_info(&dd->pcidev->dev, "Couldn't read "
"linkerror%d of HT slave/primary block\n",
i);
else if (linkerr & 0xf0) {
ipath_cdbg(VERBOSE, "HT linkerr%d bits 0x%x set, "
"clearing\n", linkerr >> 4, i);
if (pci_write_config_byte(dd->pcidev, link_off,
linkerr))
ipath_dbg("Failed write to clear HT "
"linkerror%d\n", i);
if (pci_read_config_byte(dd->pcidev, link_off,
&linkerr))
dev_info(&dd->pcidev->dev,
"Couldn't reread linkerror%d of "
"HT slave/primary block\n", i);
else if (linkerr & 0xf0)
dev_info(&dd->pcidev->dev,
"HT linkerror%d bits 0x%x "
"couldn't be cleared\n",
i, linkerr >> 4);
}
}
}
static int ipath_setup_ht_reset(struct ipath_devdata *dd)
{
ipath_dbg("No reset possible for this InfiniPath hardware\n");
return 0;
}
static void slave_or_pri_blk(struct ipath_devdata *dd, struct pci_dev *pdev,
int pos, u8 cap_type)
{
u8 linkwidth = 0, linkerr, link_a_b_off, link_off;
u16 linkctrl = 0;
int i;
dd->ipath_ht_slave_off = pos;
if ((cap_type >> 2) & 1)
link_a_b_off = 4;
else
link_a_b_off = 0;
ipath_cdbg(VERBOSE, "HT%u (Link %c) connected to processor\n",
link_a_b_off ? 1 : 0,
link_a_b_off ? 'B' : 'A');
link_a_b_off += pos;
for (i = 0; i < 2; i++) {
link_off = pos + i * 4 + 0x4;
if (pci_read_config_word(pdev, link_off, &linkctrl))
ipath_dev_err(dd, "Couldn't read HT link control%d "
"register\n", i);
else if (linkctrl & (0xf << 8)) {
ipath_cdbg(VERBOSE, "Clear linkctrl%d CRC Error "
"bits %x\n", i, linkctrl & (0xf << 8));
pci_write_config_word(pdev, link_off,
linkctrl & (0xf << 8));
}
}
for (i = 0; i < 2; i++) {
link_off = pos + i * 4 + 0xd;
if (pci_read_config_byte(pdev, link_off, &linkerr))
dev_info(&pdev->dev, "Couldn't read linkerror%d "
"of HT slave/primary block\n", i);
else if (linkerr & 0xf0) {
ipath_cdbg(VERBOSE, "HT linkerr%d bits 0x%x set, "
"clearing\n", linkerr >> 4, i);
if (pci_write_config_byte
(pdev, link_off, linkerr))
ipath_dbg("Failed write to clear HT "
"linkerror%d\n", i);
if (pci_read_config_byte(pdev, link_off, &linkerr))
dev_info(&pdev->dev, "Couldn't reread "
"linkerror%d of HT slave/primary "
"block\n", i);
else if (linkerr & 0xf0)
dev_info(&pdev->dev, "HT linkerror%d bits "
"0x%x couldn't be cleared\n",
i, linkerr >> 4);
}
}
if (pci_read_config_byte(pdev, link_a_b_off + 7, &linkwidth))
ipath_dev_err(dd, "Couldn't read HT link width "
"config register\n");
else {
u32 width;
switch (linkwidth & 7) {
case 5:
width = 4;
break;
case 4:
width = 2;
break;
case 3:
width = 32;
break;
case 1:
width = 16;
break;
case 0:
default:
width = 8;
break;
}
dd->ipath_lbus_width = width;
if (linkwidth != 0x11) {
ipath_dev_err(dd, "Not configured for 16 bit HT "
"(%x)\n", linkwidth);
if (!(linkwidth & 0xf)) {
ipath_dbg("Will ignore HT lane1 errors\n");
dd->ipath_flags |= IPATH_8BIT_IN_HT0;
}
}
}
if (pci_read_config_byte(pdev, link_a_b_off + 0xd, &linkwidth))
ipath_dev_err(dd, "Couldn't read HT link frequency "
"config register\n");
else {
u32 speed;
switch (linkwidth & 0xf) {
case 6:
speed = 1000;
break;
case 5:
speed = 800;
break;
case 4:
speed = 600;
break;
case 3:
speed = 500;
break;
case 2:
speed = 400;
break;
case 1:
speed = 300;
break;
default:
case 0:
speed = 200;
break;
}
dd->ipath_lbus_speed = speed;
}
snprintf(dd->ipath_lbus_info, sizeof(dd->ipath_lbus_info),
"HyperTransport,%uMHz,x%u\n",
dd->ipath_lbus_speed,
dd->ipath_lbus_width);
}
static int ipath_ht_intconfig(struct ipath_devdata *dd)
{
int ret;
if (dd->ipath_intconfig) {
ipath_write_kreg(dd, dd->ipath_kregs->kr_interruptconfig,
dd->ipath_intconfig);
ret = 0;
} else {
ipath_dev_err(dd, "No interrupts enabled, couldn't setup "
"interrupt address\n");
ret = -EINVAL;
}
return ret;
}
static void ipath_ht_irq_update(struct pci_dev *dev, int irq,
struct ht_irq_msg *msg)
{
struct ipath_devdata *dd = pci_get_drvdata(dev);
u64 prev_intconfig = dd->ipath_intconfig;
dd->ipath_intconfig = msg->address_lo;
dd->ipath_intconfig |= ((u64) msg->address_hi) << 32;
if (prev_intconfig)
ipath_ht_intconfig(dd);
}
static int ipath_setup_ht_config(struct ipath_devdata *dd,
struct pci_dev *pdev)
{
int pos, ret;
ret = __ht_create_irq(pdev, 0, ipath_ht_irq_update);
if (ret < 0) {
ipath_dev_err(dd, "Couldn't create interrupt handler: "
"err %d\n", ret);
goto bail;
}
dd->ipath_irq = ret;
ret = 0;
pos = pci_find_capability(pdev, PCI_CAP_ID_HT);
if (!pos) {
ipath_dev_err(dd, "Couldn't find HyperTransport "
"capability; no interrupts\n");
ret = -ENODEV;
goto bail;
}
do {
u8 cap_type;
if (pci_read_config_byte(pdev, pos + 3, &cap_type)) {
dev_info(&pdev->dev, "Couldn't read config "
"command @ %d\n", pos);
continue;
}
if (!(cap_type & 0xE0))
slave_or_pri_blk(dd, pdev, pos, cap_type);
} while ((pos = pci_find_next_capability(pdev, pos,
PCI_CAP_ID_HT)));
dd->ipath_flags |= IPATH_SWAP_PIOBUFS;
bail:
return ret;
}
static void ipath_setup_ht_cleanup(struct ipath_devdata *dd)
{
}
static void ipath_setup_ht_setextled(struct ipath_devdata *dd,
u64 lst, u64 ltst)
{
u64 extctl;
unsigned long flags = 0;
if (ipath_diag_inuse)
return;
if (dd->ipath_led_override) {
ltst = (dd->ipath_led_override & IPATH_LED_PHYS)
? INFINIPATH_IBCS_LT_STATE_LINKUP
: INFINIPATH_IBCS_LT_STATE_DISABLED;
lst = (dd->ipath_led_override & IPATH_LED_LOG)
? INFINIPATH_IBCS_L_STATE_ACTIVE
: INFINIPATH_IBCS_L_STATE_DOWN;
}
spin_lock_irqsave(&dd->ipath_gpio_lock, flags);
if (dd->ipath_boardrev == 8) {
extctl = (dd->ipath_extctrl & ~INFINIPATH_EXTC_LEDGBLOK_ON)
| INFINIPATH_EXTC_LEDGBLERR_OFF;
if (ltst == INFINIPATH_IBCS_LT_STATE_LINKUP)
extctl &= ~INFINIPATH_EXTC_LEDGBLERR_OFF;
if (lst == INFINIPATH_IBCS_L_STATE_ACTIVE)
extctl |= INFINIPATH_EXTC_LEDGBLOK_ON;
}
else {
extctl = dd->ipath_extctrl &
~(INFINIPATH_EXTC_LED1PRIPORT_ON |
INFINIPATH_EXTC_LED2PRIPORT_ON);
if (ltst == INFINIPATH_IBCS_LT_STATE_LINKUP)
extctl |= INFINIPATH_EXTC_LED1PRIPORT_ON;
if (lst == INFINIPATH_IBCS_L_STATE_ACTIVE)
extctl |= INFINIPATH_EXTC_LED2PRIPORT_ON;
}
dd->ipath_extctrl = extctl;
ipath_write_kreg(dd, dd->ipath_kregs->kr_extctrl, extctl);
spin_unlock_irqrestore(&dd->ipath_gpio_lock, flags);
}
static void ipath_init_ht_variables(struct ipath_devdata *dd)
{
dd->ipath_kregs = &ipath_ht_kregs;
dd->ipath_cregs = &ipath_ht_cregs;
dd->ipath_gpio_sda_num = _IPATH_GPIO_SDA_NUM;
dd->ipath_gpio_scl_num = _IPATH_GPIO_SCL_NUM;
dd->ipath_gpio_sda = IPATH_GPIO_SDA;
dd->ipath_gpio_scl = IPATH_GPIO_SCL;
dd->ibcs_ls_shift = IBA6110_IBCS_LINKSTATE_SHIFT;
dd->ibcs_lts_mask = IBA6110_IBCS_LINKTRAININGSTATE_MASK;
dd->ibcs_mask = (INFINIPATH_IBCS_LINKSTATE_MASK <<
dd->ibcs_ls_shift) | dd->ibcs_lts_mask;
dd->ib_init = (INFINIPATH_IBCS_LT_STATE_LINKUP <<
INFINIPATH_IBCS_LINKTRAININGSTATE_SHIFT) |
(INFINIPATH_IBCS_L_STATE_INIT << dd->ibcs_ls_shift);
dd->ib_arm = (INFINIPATH_IBCS_LT_STATE_LINKUP <<
INFINIPATH_IBCS_LINKTRAININGSTATE_SHIFT) |
(INFINIPATH_IBCS_L_STATE_ARM << dd->ibcs_ls_shift);
dd->ib_active = (INFINIPATH_IBCS_LT_STATE_LINKUP <<
INFINIPATH_IBCS_LINKTRAININGSTATE_SHIFT) |
(INFINIPATH_IBCS_L_STATE_ACTIVE << dd->ibcs_ls_shift);
dd->ibcc_lic_mask = INFINIPATH_IBCC_LINKINITCMD_MASK;
dd->ibcc_lc_shift = INFINIPATH_IBCC_LINKCMD_SHIFT;
dd->ibcc_mpl_shift = INFINIPATH_IBCC_MAXPKTLEN_SHIFT;
dd->ipath_r_portenable_shift = INFINIPATH_R_PORTENABLE_SHIFT;
dd->ipath_r_intravail_shift = INFINIPATH_R_INTRAVAIL_SHIFT;
dd->ipath_r_tailupd_shift = INFINIPATH_R_TAILUPD_SHIFT;
dd->ipath_r_portcfg_shift = 0;
dd->ipath_i_bitsextant =
(INFINIPATH_I_RCVURG_MASK << INFINIPATH_I_RCVURG_SHIFT) |
(INFINIPATH_I_RCVAVAIL_MASK <<
INFINIPATH_I_RCVAVAIL_SHIFT) |
INFINIPATH_I_ERROR | INFINIPATH_I_SPIOSENT |
INFINIPATH_I_SPIOBUFAVAIL | INFINIPATH_I_GPIO;
dd->ipath_e_bitsextant =
INFINIPATH_E_RFORMATERR | INFINIPATH_E_RVCRC |
INFINIPATH_E_RICRC | INFINIPATH_E_RMINPKTLEN |
INFINIPATH_E_RMAXPKTLEN | INFINIPATH_E_RLONGPKTLEN |
INFINIPATH_E_RSHORTPKTLEN | INFINIPATH_E_RUNEXPCHAR |
INFINIPATH_E_RUNSUPVL | INFINIPATH_E_REBP |
INFINIPATH_E_RIBFLOW | INFINIPATH_E_RBADVERSION |
INFINIPATH_E_RRCVEGRFULL | INFINIPATH_E_RRCVHDRFULL |
INFINIPATH_E_RBADTID | INFINIPATH_E_RHDRLEN |
INFINIPATH_E_RHDR | INFINIPATH_E_RIBLOSTLINK |
INFINIPATH_E_SMINPKTLEN | INFINIPATH_E_SMAXPKTLEN |
INFINIPATH_E_SUNDERRUN | INFINIPATH_E_SPKTLEN |
INFINIPATH_E_SDROPPEDSMPPKT | INFINIPATH_E_SDROPPEDDATAPKT |
INFINIPATH_E_SPIOARMLAUNCH | INFINIPATH_E_SUNEXPERRPKTNUM |
INFINIPATH_E_SUNSUPVL | INFINIPATH_E_IBSTATUSCHANGED |
INFINIPATH_E_INVALIDADDR | INFINIPATH_E_RESET |
INFINIPATH_E_HARDWARE;
dd->ipath_hwe_bitsextant =
(INFINIPATH_HWE_HTCMEMPARITYERR_MASK <<
INFINIPATH_HWE_HTCMEMPARITYERR_SHIFT) |
(INFINIPATH_HWE_TXEMEMPARITYERR_MASK <<
INFINIPATH_HWE_TXEMEMPARITYERR_SHIFT) |
(INFINIPATH_HWE_RXEMEMPARITYERR_MASK <<
INFINIPATH_HWE_RXEMEMPARITYERR_SHIFT) |
INFINIPATH_HWE_HTCLNKABYTE0CRCERR |
INFINIPATH_HWE_HTCLNKABYTE1CRCERR |
INFINIPATH_HWE_HTCLNKBBYTE0CRCERR |
INFINIPATH_HWE_HTCLNKBBYTE1CRCERR |
INFINIPATH_HWE_HTCMISCERR4 |
INFINIPATH_HWE_HTCMISCERR5 | INFINIPATH_HWE_HTCMISCERR6 |
INFINIPATH_HWE_HTCMISCERR7 |
INFINIPATH_HWE_HTCBUSTREQPARITYERR |
INFINIPATH_HWE_HTCBUSTRESPPARITYERR |
INFINIPATH_HWE_HTCBUSIREQPARITYERR |
INFINIPATH_HWE_RXDSYNCMEMPARITYERR |
INFINIPATH_HWE_MEMBISTFAILED |
INFINIPATH_HWE_COREPLL_FBSLIP |
INFINIPATH_HWE_COREPLL_RFSLIP |
INFINIPATH_HWE_HTBPLL_FBSLIP |
INFINIPATH_HWE_HTBPLL_RFSLIP |
INFINIPATH_HWE_HTAPLL_FBSLIP |
INFINIPATH_HWE_HTAPLL_RFSLIP |
INFINIPATH_HWE_SERDESPLLFAILED |
INFINIPATH_HWE_IBCBUSTOSPCPARITYERR |
INFINIPATH_HWE_IBCBUSFRSPCPARITYERR;
dd->ipath_i_rcvavail_mask = INFINIPATH_I_RCVAVAIL_MASK;
dd->ipath_i_rcvurg_mask = INFINIPATH_I_RCVURG_MASK;
dd->ipath_i_rcvavail_shift = INFINIPATH_I_RCVAVAIL_SHIFT;
dd->ipath_i_rcvurg_shift = INFINIPATH_I_RCVURG_SHIFT;
dd->ipath_eep_st_masks[0].hwerrs_to_log =
INFINIPATH_HWE_TXEMEMPARITYERR_MASK <<
INFINIPATH_HWE_TXEMEMPARITYERR_SHIFT;
dd->ipath_eep_st_masks[1].hwerrs_to_log =
INFINIPATH_HWE_RXEMEMPARITYERR_MASK <<
INFINIPATH_HWE_RXEMEMPARITYERR_SHIFT;
dd->ipath_eep_st_masks[2].errs_to_log = INFINIPATH_E_RESET;
dd->delay_mult = 2;
dd->ipath_link_width_supported = IB_WIDTH_1X | IB_WIDTH_4X;
dd->ipath_link_speed_supported = IPATH_IB_SDR;
dd->ipath_link_width_enabled = IB_WIDTH_4X;
dd->ipath_link_speed_enabled = dd->ipath_link_speed_supported;
dd->ipath_link_width_active = dd->ipath_link_width_enabled;
dd->ipath_link_speed_active = dd->ipath_link_speed_enabled;
}
static void ipath_ht_init_hwerrors(struct ipath_devdata *dd)
{
ipath_err_t val;
u64 extsval;
extsval = ipath_read_kreg64(dd, dd->ipath_kregs->kr_extstatus);
if (!(extsval & INFINIPATH_EXTS_MEMBIST_ENDTEST))
ipath_dev_err(dd, "MemBIST did not complete!\n");
if (extsval & INFINIPATH_EXTS_MEMBIST_CORRECT)
ipath_dbg("MemBIST corrected\n");
ipath_check_htlink(dd);
val = -1LL;
if (dd->ipath_flags & IPATH_8BIT_IN_HT0)
val &= ~infinipath_hwe_htclnkabyte1crcerr;
if (dd->ipath_flags & IPATH_8BIT_IN_HT1)
val &= ~infinipath_hwe_htclnkbbyte1crcerr;
val &= ~(INFINIPATH_HWE_SERDESPLLFAILED |
INFINIPATH_HWE_RXDSYNCMEMPARITYERR);
val &= ~INFINIPATH_HWE_HTCMISCERR4;
if (dd->ipath_boardrev == 4 || dd->ipath_boardrev == 9)
val &= ~INFINIPATH_HWE_SERDESPLLFAILED;
dd->ipath_hwerrmask = val;
}
static int ipath_ht_bringup_serdes(struct ipath_devdata *dd)
{
u64 val, config1;
int ret = 0, change = 0;
ipath_dbg("Trying to bringup serdes\n");
if (ipath_read_kreg64(dd, dd->ipath_kregs->kr_hwerrstatus) &
INFINIPATH_HWE_SERDESPLLFAILED)
{
ipath_dbg("At start, serdes PLL failed bit set in "
"hwerrstatus, clearing and continuing\n");
ipath_write_kreg(dd, dd->ipath_kregs->kr_hwerrclear,
INFINIPATH_HWE_SERDESPLLFAILED);
}
val = ipath_read_kreg64(dd, dd->ipath_kregs->kr_serdesconfig0);
config1 = ipath_read_kreg64(dd, dd->ipath_kregs->kr_serdesconfig1);
ipath_cdbg(VERBOSE, "Initial serdes status is config0=%llx "
"config1=%llx, sstatus=%llx xgxs %llx\n",
(unsigned long long) val, (unsigned long long) config1,
(unsigned long long)
ipath_read_kreg64(dd, dd->ipath_kregs->kr_serdesstatus),
(unsigned long long)
ipath_read_kreg64(dd, dd->ipath_kregs->kr_xgxsconfig));
val |= INFINIPATH_SERDC0_RESET_PLL
;
ipath_write_kreg(dd, dd->ipath_kregs->kr_serdesconfig0, val);
udelay(15);
if (val & INFINIPATH_SERDC0_RESET_PLL) {
u64 val2 = val &= ~INFINIPATH_SERDC0_RESET_PLL;
val2 |= INFINIPATH_SERDC0_RESET_MASK |
INFINIPATH_SERDC0_TXIDLE;
ipath_cdbg(VERBOSE, "Clearing serdes PLL reset (writing "
"%llx)\n", (unsigned long long) val2);
ipath_write_kreg(dd, dd->ipath_kregs->kr_serdesconfig0,
val2);
val = ipath_read_kreg64(dd, dd->ipath_kregs->kr_scratch);
udelay(15);
val = val2;
}
if (val & (INFINIPATH_SERDC0_RESET_PLL |
INFINIPATH_SERDC0_RESET_MASK |
INFINIPATH_SERDC0_TXIDLE)) {
val &= ~(INFINIPATH_SERDC0_RESET_PLL |
INFINIPATH_SERDC0_RESET_MASK |
INFINIPATH_SERDC0_TXIDLE);
ipath_write_kreg(dd, dd->ipath_kregs->kr_serdesconfig0,
val);
}
val = ipath_read_kreg64(dd, dd->ipath_kregs->kr_xgxsconfig);
if (val & INFINIPATH_XGXS_RESET) {
val &= ~INFINIPATH_XGXS_RESET;
change = 1;
}
if (((val >> INFINIPATH_XGXS_RX_POL_SHIFT) &
INFINIPATH_XGXS_RX_POL_MASK) != dd->ipath_rx_pol_inv ) {
val &= ~(INFINIPATH_XGXS_RX_POL_MASK <<
INFINIPATH_XGXS_RX_POL_SHIFT);
val |= dd->ipath_rx_pol_inv <<
INFINIPATH_XGXS_RX_POL_SHIFT;
change = 1;
}
if (change)
ipath_write_kreg(dd, dd->ipath_kregs->kr_xgxsconfig, val);
val = ipath_read_kreg64(dd, dd->ipath_kregs->kr_serdesconfig0);
config1 &= ~0x0ffffffff00ULL;
config1 |= 0x00000000000ULL;
config1 |= 0x0cccc000000ULL;
ipath_write_kreg(dd, dd->ipath_kregs->kr_serdesconfig1, config1);
ipath_cdbg(VERBOSE, "After setup: serdes status is config0=%llx "
"config1=%llx, sstatus=%llx xgxs %llx\n",
(unsigned long long) val, (unsigned long long) config1,
(unsigned long long)
ipath_read_kreg64(dd, dd->ipath_kregs->kr_serdesstatus),
(unsigned long long)
ipath_read_kreg64(dd, dd->ipath_kregs->kr_xgxsconfig));
return ret;
}
static void ipath_ht_quiet_serdes(struct ipath_devdata *dd)
{
u64 val = ipath_read_kreg64(dd, dd->ipath_kregs->kr_serdesconfig0);
val |= INFINIPATH_SERDC0_TXIDLE;
ipath_dbg("Setting TxIdleEn on serdes (config0 = %llx)\n",
(unsigned long long) val);
ipath_write_kreg(dd, dd->ipath_kregs->kr_serdesconfig0, val);
}
static void ipath_ht_put_tid(struct ipath_devdata *dd,
u64 __iomem *tidptr, u32 type,
unsigned long pa)
{
if (!dd->ipath_kregbase)
return;
if (pa != dd->ipath_tidinvalid) {
if (unlikely((pa & ~INFINIPATH_RT_ADDR_MASK))) {
dev_info(&dd->pcidev->dev,
"physaddr %lx has more than "
"40 bits, using only 40!!!\n", pa);
pa &= INFINIPATH_RT_ADDR_MASK;
}
if (type == RCVHQ_RCV_TYPE_EAGER)
pa |= dd->ipath_tidtemplate;
else {
u64 lenvalid = PAGE_SIZE >> 2;
lenvalid <<= INFINIPATH_RT_BUFSIZE_SHIFT;
pa |= lenvalid | INFINIPATH_RT_VALID;
}
}
writeq(pa, tidptr);
}
static void ipath_ht_clear_tids(struct ipath_devdata *dd, unsigned port)
{
u64 __iomem *tidbase;
int i;
if (!dd->ipath_kregbase)
return;
ipath_cdbg(VERBOSE, "Invalidate TIDs for port %u\n", port);
tidbase = (u64 __iomem *) ((char __iomem *)(dd->ipath_kregbase) +
dd->ipath_rcvtidbase +
port * dd->ipath_rcvtidcnt *
sizeof(*tidbase));
for (i = 0; i < dd->ipath_rcvtidcnt; i++)
ipath_ht_put_tid(dd, &tidbase[i], RCVHQ_RCV_TYPE_EXPECTED,
dd->ipath_tidinvalid);
tidbase = (u64 __iomem *) ((char __iomem *)(dd->ipath_kregbase) +
dd->ipath_rcvegrbase +
port * dd->ipath_rcvegrcnt *
sizeof(*tidbase));
for (i = 0; i < dd->ipath_rcvegrcnt; i++)
ipath_ht_put_tid(dd, &tidbase[i], RCVHQ_RCV_TYPE_EAGER,
dd->ipath_tidinvalid);
}
static void ipath_ht_tidtemplate(struct ipath_devdata *dd)
{
dd->ipath_tidtemplate = dd->ipath_ibmaxlen >> 2;
dd->ipath_tidtemplate <<= INFINIPATH_RT_BUFSIZE_SHIFT;
dd->ipath_tidtemplate |= INFINIPATH_RT_VALID;
dd->ipath_tidinvalid = (-1LL & INFINIPATH_RT_BUFSIZE_MASK) <<
INFINIPATH_RT_BUFSIZE_SHIFT;
}
static int ipath_ht_early_init(struct ipath_devdata *dd)
{
u32 __iomem *piobuf;
u32 pioincr, val32;
int i;
dd->ipath_rcvhdrentsize = 16;
dd->ipath_rcvhdrsize = IPATH_DFLT_RCVHDRSIZE;
dd->ipath_rcvegrbufsize = dd->ipath_piosize2k;
dd->ipath_ibmaxlen = min(dd->ipath_piosize2k,
dd->ipath_rcvegrbufsize);
dd->ipath_init_ibmaxlen = dd->ipath_ibmaxlen;
ipath_ht_tidtemplate(dd);
for (val32 = 0; val32 < dd->ipath_portcnt; val32++)
ipath_ht_clear_tids(dd, val32);
piobuf = (u32 __iomem *) (((char __iomem *)(dd->ipath_kregbase)) +
dd->ipath_piobufbase);
pioincr = dd->ipath_palign / sizeof(*piobuf);
for (i = 0; i < dd->ipath_piobcnt2k; i++) {
writel(16, piobuf);
piobuf += pioincr;
}
ipath_get_eeprom_info(dd);
if (dd->ipath_boardrev == 5) {
if (dd->ipath_serial[0] == '1' &&
dd->ipath_serial[1] == '2' &&
dd->ipath_serial[2] == '8')
dd->ipath_flags |= IPATH_GPIO_INTR;
else {
ipath_dev_err(dd, "Unsupported InfiniPath board "
"(serial number %.16s)!\n",
dd->ipath_serial);
return 1;
}
}
if (dd->ipath_minrev >= 4) {
dd->ipath_flags |= IPATH_GPIO_ERRINTRS;
dd->ipath_gpio_mask |= IPATH_GPIO_ERRINTR_MASK;
ipath_write_kreg(dd, dd->ipath_kregs->kr_gpio_mask,
dd->ipath_gpio_mask);
}
return 0;
}
static int ipath_ht_get_base_info(struct ipath_portdata *pd, void *kbase)
{
struct ipath_base_info *kinfo = kbase;
kinfo->spi_runtime_flags |= IPATH_RUNTIME_HT |
IPATH_RUNTIME_PIO_REGSWAPPED;
if (pd->port_dd->ipath_minrev < 4)
kinfo->spi_runtime_flags |= IPATH_RUNTIME_RCVHDR_COPY;
return 0;
}
static void ipath_ht_free_irq(struct ipath_devdata *dd)
{
free_irq(dd->ipath_irq, dd);
ht_destroy_irq(dd->ipath_irq);
dd->ipath_irq = 0;
dd->ipath_intconfig = 0;
}
static struct ipath_message_header *
ipath_ht_get_msgheader(struct ipath_devdata *dd, __le32 *rhf_addr)
{
return (struct ipath_message_header *)
&rhf_addr[sizeof(u64) / sizeof(u32)];
}
static void ipath_ht_config_ports(struct ipath_devdata *dd, ushort cfgports)
{
dd->ipath_portcnt =
ipath_read_kreg32(dd, dd->ipath_kregs->kr_portcnt);
dd->ipath_p0_rcvegrcnt =
ipath_read_kreg32(dd, dd->ipath_kregs->kr_rcvegrcnt);
}
static void ipath_ht_read_counters(struct ipath_devdata *dd,
struct infinipath_counters *cntrs)
{
cntrs->LBIntCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(LBIntCnt));
cntrs->LBFlowStallCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(LBFlowStallCnt));
cntrs->TxSDmaDescCnt = 0;
cntrs->TxUnsupVLErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxUnsupVLErrCnt));
cntrs->TxDataPktCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxDataPktCnt));
cntrs->TxFlowPktCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxFlowPktCnt));
cntrs->TxDwordCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxDwordCnt));
cntrs->TxLenErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxLenErrCnt));
cntrs->TxMaxMinLenErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxMaxMinLenErrCnt));
cntrs->TxUnderrunCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxUnderrunCnt));
cntrs->TxFlowStallCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxFlowStallCnt));
cntrs->TxDroppedPktCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(TxDroppedPktCnt));
cntrs->RxDroppedPktCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxDroppedPktCnt));
cntrs->RxDataPktCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxDataPktCnt));
cntrs->RxFlowPktCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxFlowPktCnt));
cntrs->RxDwordCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxDwordCnt));
cntrs->RxLenErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxLenErrCnt));
cntrs->RxMaxMinLenErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxMaxMinLenErrCnt));
cntrs->RxICRCErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxICRCErrCnt));
cntrs->RxVCRCErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxVCRCErrCnt));
cntrs->RxFlowCtrlErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxFlowCtrlErrCnt));
cntrs->RxBadFormatCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxBadFormatCnt));
cntrs->RxLinkProblemCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxLinkProblemCnt));
cntrs->RxEBPCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxEBPCnt));
cntrs->RxLPCRCErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxLPCRCErrCnt));
cntrs->RxBufOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxBufOvflCnt));
cntrs->RxTIDFullErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxTIDFullErrCnt));
cntrs->RxTIDValidErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxTIDValidErrCnt));
cntrs->RxPKeyMismatchCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxPKeyMismatchCnt));
cntrs->RxP0HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP0HdrEgrOvflCnt));
cntrs->RxP1HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP1HdrEgrOvflCnt));
cntrs->RxP2HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP2HdrEgrOvflCnt));
cntrs->RxP3HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP3HdrEgrOvflCnt));
cntrs->RxP4HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP4HdrEgrOvflCnt));
cntrs->RxP5HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP5HdrEgrOvflCnt));
cntrs->RxP6HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP6HdrEgrOvflCnt));
cntrs->RxP7HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP7HdrEgrOvflCnt));
cntrs->RxP8HdrEgrOvflCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(RxP8HdrEgrOvflCnt));
cntrs->RxP9HdrEgrOvflCnt = 0;
cntrs->RxP10HdrEgrOvflCnt = 0;
cntrs->RxP11HdrEgrOvflCnt = 0;
cntrs->RxP12HdrEgrOvflCnt = 0;
cntrs->RxP13HdrEgrOvflCnt = 0;
cntrs->RxP14HdrEgrOvflCnt = 0;
cntrs->RxP15HdrEgrOvflCnt = 0;
cntrs->RxP16HdrEgrOvflCnt = 0;
cntrs->IBStatusChangeCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(IBStatusChangeCnt));
cntrs->IBLinkErrRecoveryCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(IBLinkErrRecoveryCnt));
cntrs->IBLinkDownedCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(IBLinkDownedCnt));
cntrs->IBSymbolErrCnt =
ipath_snap_cntr(dd, IPATH_CREG_OFFSET(IBSymbolErrCnt));
cntrs->RxVL15DroppedPktCnt = 0;
cntrs->RxOtherLocalPhyErrCnt = 0;
cntrs->PcieRetryBufDiagQwordCnt = 0;
cntrs->ExcessBufferOvflCnt = dd->ipath_overrun_thresh_errs;
cntrs->LocalLinkIntegrityErrCnt =
(dd->ipath_flags & IPATH_GPIO_ERRINTRS) ?
dd->ipath_lli_errs : dd->ipath_lli_errors;
cntrs->RxVlErrCnt = 0;
cntrs->RxDlidFltrCnt = 0;
}
static int ipath_ht_nointr_fallback(struct ipath_devdata *dd)
{
return 0;
}
static void ipath_ht_xgxs_reset(struct ipath_devdata *dd)
{
u64 val, prev_val;
prev_val = ipath_read_kreg64(dd, dd->ipath_kregs->kr_xgxsconfig);
val = prev_val | INFINIPATH_XGXS_RESET;
prev_val &= ~INFINIPATH_XGXS_RESET;
ipath_write_kreg(dd, dd->ipath_kregs->kr_control,
dd->ipath_control & ~INFINIPATH_C_LINKENABLE);
ipath_write_kreg(dd, dd->ipath_kregs->kr_xgxsconfig, val);
ipath_read_kreg32(dd, dd->ipath_kregs->kr_scratch);
ipath_write_kreg(dd, dd->ipath_kregs->kr_xgxsconfig, prev_val);
ipath_write_kreg(dd, dd->ipath_kregs->kr_control,
dd->ipath_control);
}
static int ipath_ht_get_ib_cfg(struct ipath_devdata *dd, int which)
{
int ret;
switch (which) {
case IPATH_IB_CFG_LWID:
ret = dd->ipath_link_width_active;
break;
case IPATH_IB_CFG_SPD:
ret = dd->ipath_link_speed_active;
break;
case IPATH_IB_CFG_LWID_ENB:
ret = dd->ipath_link_width_enabled;
break;
case IPATH_IB_CFG_SPD_ENB:
ret = dd->ipath_link_speed_enabled;
break;
default:
ret = -ENOTSUPP;
break;
}
return ret;
}
static int ipath_ht_set_ib_cfg(struct ipath_devdata *dd, int which, u32 val)
{
int ret = 0;
if (which == IPATH_IB_CFG_LWID_ENB)
dd->ipath_link_width_enabled = val;
else if (which == IPATH_IB_CFG_SPD_ENB)
dd->ipath_link_speed_enabled = val;
else
ret = -ENOTSUPP;
return ret;
}
static void ipath_ht_config_jint(struct ipath_devdata *dd, u16 a, u16 b)
{
}
static int ipath_ht_ib_updown(struct ipath_devdata *dd, int ibup, u64 ibcs)
{
ipath_setup_ht_setextled(dd, ipath_ib_linkstate(dd, ibcs),
ipath_ib_linktrstate(dd, ibcs));
return 0;
}
void ipath_init_iba6110_funcs(struct ipath_devdata *dd)
{
dd->ipath_f_intrsetup = ipath_ht_intconfig;
dd->ipath_f_bus = ipath_setup_ht_config;
dd->ipath_f_reset = ipath_setup_ht_reset;
dd->ipath_f_get_boardname = ipath_ht_boardname;
dd->ipath_f_init_hwerrors = ipath_ht_init_hwerrors;
dd->ipath_f_early_init = ipath_ht_early_init;
dd->ipath_f_handle_hwerrors = ipath_ht_handle_hwerrors;
dd->ipath_f_quiet_serdes = ipath_ht_quiet_serdes;
dd->ipath_f_bringup_serdes = ipath_ht_bringup_serdes;
dd->ipath_f_clear_tids = ipath_ht_clear_tids;
dd->ipath_f_put_tid = ipath_ht_put_tid;
dd->ipath_f_cleanup = ipath_setup_ht_cleanup;
dd->ipath_f_setextled = ipath_setup_ht_setextled;
dd->ipath_f_get_base_info = ipath_ht_get_base_info;
dd->ipath_f_free_irq = ipath_ht_free_irq;
dd->ipath_f_tidtemplate = ipath_ht_tidtemplate;
dd->ipath_f_intr_fallback = ipath_ht_nointr_fallback;
dd->ipath_f_get_msgheader = ipath_ht_get_msgheader;
dd->ipath_f_config_ports = ipath_ht_config_ports;
dd->ipath_f_read_counters = ipath_ht_read_counters;
dd->ipath_f_xgxs_reset = ipath_ht_xgxs_reset;
dd->ipath_f_get_ib_cfg = ipath_ht_get_ib_cfg;
dd->ipath_f_set_ib_cfg = ipath_ht_set_ib_cfg;
dd->ipath_f_config_jint = ipath_ht_config_jint;
dd->ipath_f_ib_updown = ipath_ht_ib_updown;
ipath_init_ht_variables(dd);
}
