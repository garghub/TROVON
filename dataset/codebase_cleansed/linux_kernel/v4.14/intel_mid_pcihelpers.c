static inline int platform_is(u8 model)
{
return (boot_cpu_data.x86_model == model);
}
static int intel_mid_msgbus_init(void)
{
pci_root = pci_get_bus_and_slot(0, PCI_DEVFN(0, 0));
if (!pci_root) {
pr_err("%s: Error: msgbus PCI handle NULL\n", __func__);
return -ENODEV;
}
if (DW_I2C_NEED_QOS) {
pm_qos_add_request(&pm_qos,
PM_QOS_CPU_DMA_LATENCY,
PM_QOS_DEFAULT_VALUE);
}
return 0;
}
u32 intel_mid_msgbus_read32_raw(u32 cmd)
{
unsigned long irq_flags;
u32 data;
spin_lock_irqsave(&msgbus_lock, irq_flags);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_REG, cmd);
pci_read_config_dword(pci_root, PCI_ROOT_MSGBUS_DATA_REG, &data);
spin_unlock_irqrestore(&msgbus_lock, irq_flags);
return data;
}
u32 intel_mid_msgbus_read32_raw_ext(u32 cmd, u32 cmd_ext)
{
unsigned long irq_flags;
u32 data;
spin_lock_irqsave(&msgbus_lock, irq_flags);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_EXT_REG, cmd_ext);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_REG, cmd);
pci_read_config_dword(pci_root, PCI_ROOT_MSGBUS_DATA_REG, &data);
spin_unlock_irqrestore(&msgbus_lock, irq_flags);
return data;
}
void intel_mid_msgbus_write32_raw(u32 cmd, u32 data)
{
unsigned long irq_flags;
spin_lock_irqsave(&msgbus_lock, irq_flags);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_DATA_REG, data);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_REG, cmd);
spin_unlock_irqrestore(&msgbus_lock, irq_flags);
}
void intel_mid_msgbus_write32_raw_ext(u32 cmd, u32 cmd_ext, u32 data)
{
unsigned long irq_flags;
spin_lock_irqsave(&msgbus_lock, irq_flags);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_DATA_REG, data);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_EXT_REG, cmd_ext);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_REG, cmd);
spin_unlock_irqrestore(&msgbus_lock, irq_flags);
}
u32 intel_mid_msgbus_read32(u8 port, u32 addr)
{
unsigned long irq_flags;
u32 data;
u32 cmd;
u32 cmdext;
cmd = (PCI_ROOT_MSGBUS_READ << 24) | (port << 16) |
((addr & 0xff) << 8) | PCI_ROOT_MSGBUS_DWORD_ENABLE;
cmdext = addr & 0xffffff00;
spin_lock_irqsave(&msgbus_lock, irq_flags);
if (cmdext) {
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_EXT_REG,
cmdext);
}
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_REG, cmd);
pci_read_config_dword(pci_root, PCI_ROOT_MSGBUS_DATA_REG, &data);
spin_unlock_irqrestore(&msgbus_lock, irq_flags);
return data;
}
void intel_mid_msgbus_write32(u8 port, u32 addr, u32 data)
{
unsigned long irq_flags;
u32 cmd;
u32 cmdext;
cmd = (PCI_ROOT_MSGBUS_WRITE << 24) | (port << 16) |
((addr & 0xFF) << 8) | PCI_ROOT_MSGBUS_DWORD_ENABLE;
cmdext = addr & 0xffffff00;
spin_lock_irqsave(&msgbus_lock, irq_flags);
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_DATA_REG, data);
if (cmdext) {
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_EXT_REG,
cmdext);
}
pci_write_config_dword(pci_root, PCI_ROOT_MSGBUS_CTRL_REG, cmd);
spin_unlock_irqrestore(&msgbus_lock, irq_flags);
}
u32 intel_mid_soc_stepping(void)
{
return pci_root->revision;
}
static bool is_south_complex_device(struct pci_dev *dev)
{
unsigned int base_class = dev->class >> 16;
unsigned int sub_class = (dev->class & SUB_CLASS_MASK) >> 8;
if (((base_class == PCI_BASE_CLASS_MULTIMEDIA) &&
(sub_class == ISP_SUB_CLASS)) ||
(base_class == PCI_BASE_CLASS_BRIDGE) ||
((base_class == PCI_BASE_CLASS_DISPLAY) && !sub_class))
return false;
else
return true;
}
static void pci_d3_delay_fixup(struct pci_dev *dev)
{
if (platform_is(INTEL_ATOM_BYT) ||
platform_is(INTEL_ATOM_CHT)) {
if (dev->bus->number == 0 && is_south_complex_device(dev)) {
dev->d3_delay = INTERNAL_PCI_PM_D3_WAIT;
dev->d3cold_delay = INTERNAL_PCI_PM_D3_WAIT;
}
}
}
static void reset_semaphore(void)
{
u32 data;
data = intel_mid_msgbus_read32(PUNIT_PORT, PUNIT_SEMAPHORE);
smp_mb();
data = data & 0xfffffffc;
intel_mid_msgbus_write32(PUNIT_PORT, PUNIT_SEMAPHORE, data);
smp_mb();
}
int intel_mid_dw_i2c_acquire_ownership(void)
{
u32 ret = 0;
u32 data = 0;
u32 cmd;
u32 cmdext;
int timeout = 1000;
if (DW_I2C_NEED_QOS)
pm_qos_update_request(&pm_qos, CSTATE_EXIT_LATENCY_C1 - 1);
BUG_ON(irqs_disabled());
local_irq_disable();
intel_mid_msgbus_write32(PUNIT_PORT, PUNIT_SEMAPHORE, 0x2);
smp_mb();
cmd = (PUNIT_DOORBELL_OPCODE << 24) | (PUNIT_PORT << 16) |
((PUNIT_DOORBELL_REG & 0xFF) << 8) | PCI_ROOT_MSGBUS_DWORD_ENABLE;
cmdext = PUNIT_DOORBELL_REG & 0xffffff00;
if (cmdext)
intel_mid_msgbus_write32_raw_ext(cmd, cmdext, data);
else
intel_mid_msgbus_write32_raw(cmd, data);
while (GET_SEM() != 0x1) {
udelay(100);
timeout--;
if (timeout <= 0) {
pr_err("Timeout: semaphore timed out, reset sem\n");
ret = -ETIMEDOUT;
reset_semaphore();
udelay(1000);
if (GET_SEM() != 0) {
reset_semaphore();
}
pr_err("PUNIT SEM: %d\n",
intel_mid_msgbus_read32(PUNIT_PORT,
PUNIT_SEMAPHORE));
local_irq_enable();
if (DW_I2C_NEED_QOS) {
pm_qos_update_request(&pm_qos,
PM_QOS_DEFAULT_VALUE);
}
return ret;
}
}
smp_mb();
return ret;
}
int intel_mid_dw_i2c_release_ownership(void)
{
reset_semaphore();
local_irq_enable();
if (DW_I2C_NEED_QOS)
pm_qos_update_request(&pm_qos, PM_QOS_DEFAULT_VALUE);
return 0;
}
