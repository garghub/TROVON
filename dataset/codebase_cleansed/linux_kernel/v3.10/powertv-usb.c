static void fs_update(u32 pe_bits, int md_bits, u32 sdiv_bits,
u32 disable_div_by_3, u32 standby)
{
u32 val;
val = ((sdiv_bits << QAM_FS_SDIV_SHIFT) |
((md_bits & QAM_FS_MD_MASK) << QAM_FS_MD_SHIFT) |
(pe_bits << QAM_FS_PE_SHIFT) |
QAM_FS_ENABLE_OUTPUT |
standby |
disable_div_by_3);
asic_write(val, fs432x4b4_usb_ctl);
asic_write(val | QAM_FS_ENABLE_PROGRAM, fs432x4b4_usb_ctl);
asic_write(val | QAM_FS_ENABLE_PROGRAM | QAM_FS_CHOOSE_FS,
fs432x4b4_usb_ctl);
}
static void usb_eye_configure(u32 set, u32 clear)
{
u32 old;
old = asic_read(crt_spare);
old |= set;
old &= ~clear;
asic_write(old, crt_spare);
}
static void platform_configure_usb(void)
{
u32 bcm1_usb2_ctl_value;
enum asic_type asic_type;
unsigned long flags;
spin_lock_irqsave(&usb_regs_lock, flags);
usb_users++;
if (usb_users != 1) {
spin_unlock_irqrestore(&usb_regs_lock, flags);
return;
}
asic_type = platform_get_asic();
switch (asic_type) {
case ASIC_ZEUS:
fs_update(0x0000, -15, 0x02, 0, 0);
bcm1_usb2_ctl_value = BCM1_USB2_CTL_EHCI_PRT_PWR_ACTIVE_HIGH |
BCM1_USB2_CTL_APP_PRT_OVRCUR_IN_ACTIVE_HIGH;
break;
case ASIC_CRONUS:
case ASIC_CRONUSLITE:
usb_eye_configure(0, CRT_SPARE_USB_DIVIDE_BY_9);
fs_update(0x8000, -14, 0x03, QAM_FS_DISABLE_DIVIDE_BY_3,
QAM_FS_DISABLE_DIGITAL_STANDBY);
bcm1_usb2_ctl_value = BCM1_USB2_CTL_EHCI_PRT_PWR_ACTIVE_HIGH |
BCM1_USB2_CTL_APP_PRT_OVRCUR_IN_ACTIVE_HIGH;
break;
case ASIC_CALLIOPE:
fs_update(0x0000, -15, 0x02, QAM_FS_DISABLE_DIVIDE_BY_3,
QAM_FS_DISABLE_DIGITAL_STANDBY);
switch (platform_get_family()) {
case FAMILY_1500VZE:
break;
case FAMILY_1500VZF:
usb_eye_configure(CRT_SPARE_PORT2_SHIFT_JK |
CRT_SPARE_PORT1_SHIFT_JK |
CRT_SPARE_PORT2_FAST_EDGE |
CRT_SPARE_PORT1_FAST_EDGE, 0);
break;
default:
usb_eye_configure(CRT_SPARE_PORT2_SHIFT_JK |
CRT_SPARE_PORT1_SHIFT_JK, 0);
break;
}
bcm1_usb2_ctl_value = BCM1_USB2_CTL_BISTOK |
BCM1_USB2_CTL_EHCI_PRT_PWR_ACTIVE_HIGH |
BCM1_USB2_CTL_APP_PRT_OVRCUR_IN_ACTIVE_HIGH;
break;
case ASIC_GAIA:
fs_update(0x8000, -14, 0x03, QAM_FS_DISABLE_DIVIDE_BY_3,
QAM_FS_DISABLE_DIGITAL_STANDBY);
bcm1_usb2_ctl_value = BCM1_USB2_CTL_BISTOK |
BCM1_USB2_CTL_EHCI_PRT_PWR_ACTIVE_HIGH |
BCM1_USB2_CTL_APP_PRT_OVRCUR_IN_ACTIVE_HIGH;
break;
default:
pr_err("Unknown ASIC type: %d\n", asic_type);
bcm1_usb2_ctl_value = 0;
break;
}
asic_write(0, usb2_strap);
asic_write(bcm1_usb2_ctl_value, usb2_control);
asic_write(USB_STBUS_OBC_STORE32_LOAD32, usb2_stbus_obc);
asic_write(USB2_STBUS_MESS_SIZE_2, usb2_stbus_mess_size);
asic_write(USB2_STBUS_CHUNK_SIZE_2, usb2_stbus_chunk_size);
spin_unlock_irqrestore(&usb_regs_lock, flags);
}
static void platform_unconfigure_usb(void)
{
unsigned long flags;
spin_lock_irqsave(&usb_regs_lock, flags);
usb_users--;
if (usb_users == 0)
asic_write(USB2_STRAP_HFREQ_SELECT, usb2_strap);
spin_unlock_irqrestore(&usb_regs_lock, flags);
}
void platform_configure_usb_ehci()
{
platform_configure_usb();
}
void platform_configure_usb_ohci()
{
platform_configure_usb();
}
void platform_unconfigure_usb_ehci()
{
platform_unconfigure_usb();
}
void platform_unconfigure_usb_ohci()
{
platform_unconfigure_usb();
}
int __init platform_usb_devices_init(struct platform_device **ehci_dev,
struct platform_device **ohci_dev)
{
*ehci_dev = &ehci_device;
ehci_resources[0].start = asic_reg_phys_addr(ehci_hcapbase);
ehci_resources[0].end += ehci_resources[0].start;
*ohci_dev = &ohci_device;
ohci_resources[0].start = asic_reg_phys_addr(ohci_hc_revision);
ohci_resources[0].end += ohci_resources[0].start;
return 0;
}
