static int sis_wait_for_ctrl_ready_with_timeout(struct pqi_ctrl_info *ctrl_info,
unsigned int timeout_secs)
{
unsigned long timeout;
u32 status;
timeout = (timeout_secs * HZ) + jiffies;
while (1) {
status = readl(&ctrl_info->registers->sis_firmware_status);
if (status != ~0) {
if (status & SIS_CTRL_KERNEL_PANIC) {
dev_err(&ctrl_info->pci_dev->dev,
"controller is offline: status code 0x%x\n",
readl(
&ctrl_info->registers->sis_mailbox[7]));
return -ENODEV;
}
if (status & SIS_CTRL_KERNEL_UP)
break;
}
if (time_after(jiffies, timeout)) {
dev_err(&ctrl_info->pci_dev->dev,
"controller not ready after %u seconds\n",
timeout_secs);
return -ETIMEDOUT;
}
msleep(SIS_CTRL_READY_POLL_INTERVAL_MSECS);
}
return 0;
}
int sis_wait_for_ctrl_ready(struct pqi_ctrl_info *ctrl_info)
{
return sis_wait_for_ctrl_ready_with_timeout(ctrl_info,
SIS_CTRL_READY_TIMEOUT_SECS);
}
int sis_wait_for_ctrl_ready_resume(struct pqi_ctrl_info *ctrl_info)
{
return sis_wait_for_ctrl_ready_with_timeout(ctrl_info,
SIS_CTRL_READY_RESUME_TIMEOUT_SECS);
}
bool sis_is_firmware_running(struct pqi_ctrl_info *ctrl_info)
{
bool running;
u32 status;
status = readl(&ctrl_info->registers->sis_firmware_status);
if (status & SIS_CTRL_KERNEL_PANIC)
running = false;
else
running = true;
if (!running)
dev_err(&ctrl_info->pci_dev->dev,
"controller is offline: status code 0x%x\n",
readl(&ctrl_info->registers->sis_mailbox[7]));
return running;
}
bool sis_is_kernel_up(struct pqi_ctrl_info *ctrl_info)
{
return readl(&ctrl_info->registers->sis_firmware_status) &
SIS_CTRL_KERNEL_UP;
}
static int sis_send_sync_cmd(struct pqi_ctrl_info *ctrl_info,
u32 cmd, struct sis_sync_cmd_params *params)
{
struct pqi_ctrl_registers __iomem *registers;
unsigned int i;
unsigned long timeout;
u32 doorbell;
u32 cmd_status;
registers = ctrl_info->registers;
writel(cmd, &registers->sis_mailbox[0]);
for (i = 1; i <= 4; i++)
writel(params->mailbox[i], &registers->sis_mailbox[i]);
writel(SIS_CLEAR_CTRL_TO_HOST_DOORBELL,
&registers->sis_ctrl_to_host_doorbell_clear);
writel(~0, &registers->sis_interrupt_mask);
readl(&registers->sis_interrupt_mask);
writel(SIS_CMD_READY, &registers->sis_host_to_ctrl_doorbell);
timeout = (SIS_CMD_COMPLETE_TIMEOUT_SECS * HZ) + jiffies;
while (1) {
msleep(SIS_CMD_COMPLETE_POLL_INTERVAL_MSECS);
doorbell = readl(&registers->sis_ctrl_to_host_doorbell);
if (doorbell & SIS_CMD_COMPLETE)
break;
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
}
cmd_status = readl(&registers->sis_mailbox[0]);
if (cmd_status != SIS_CMD_STATUS_SUCCESS) {
dev_err(&ctrl_info->pci_dev->dev,
"SIS command failed for command 0x%x: status = 0x%x\n",
cmd, cmd_status);
return -EINVAL;
}
params->mailbox[0] = cmd_status;
for (i = 1; i < ARRAY_SIZE(params->mailbox); i++)
params->mailbox[i] = readl(&registers->sis_mailbox[i]);
return 0;
}
int sis_get_ctrl_properties(struct pqi_ctrl_info *ctrl_info)
{
int rc;
u32 properties;
u32 extended_properties;
struct sis_sync_cmd_params params;
memset(&params, 0, sizeof(params));
rc = sis_send_sync_cmd(ctrl_info, SIS_CMD_GET_ADAPTER_PROPERTIES,
&params);
if (rc)
return rc;
properties = params.mailbox[1];
if (!(properties & SIS_EXTENDED_PROPERTIES_SUPPORTED))
return -ENODEV;
extended_properties = params.mailbox[4];
if ((extended_properties & SIS_REQUIRED_EXTENDED_PROPERTIES) !=
SIS_REQUIRED_EXTENDED_PROPERTIES)
return -ENODEV;
return 0;
}
int sis_get_pqi_capabilities(struct pqi_ctrl_info *ctrl_info)
{
int rc;
struct sis_sync_cmd_params params;
memset(&params, 0, sizeof(params));
rc = sis_send_sync_cmd(ctrl_info, SIS_CMD_GET_PQI_CAPABILITIES,
&params);
if (rc)
return rc;
ctrl_info->max_sg_entries = params.mailbox[1];
ctrl_info->max_transfer_size = params.mailbox[2];
ctrl_info->max_outstanding_requests = params.mailbox[3];
ctrl_info->config_table_offset = params.mailbox[4];
ctrl_info->config_table_length = params.mailbox[5];
return 0;
}
int sis_init_base_struct_addr(struct pqi_ctrl_info *ctrl_info)
{
int rc;
void *base_struct_unaligned;
struct sis_base_struct *base_struct;
struct sis_sync_cmd_params params;
unsigned long error_buffer_paddr;
dma_addr_t bus_address;
base_struct_unaligned = kzalloc(sizeof(*base_struct)
+ SIS_BASE_STRUCT_ALIGNMENT - 1, GFP_KERNEL);
if (!base_struct_unaligned)
return -ENOMEM;
base_struct = PTR_ALIGN(base_struct_unaligned,
SIS_BASE_STRUCT_ALIGNMENT);
error_buffer_paddr = (unsigned long)ctrl_info->error_buffer_dma_handle;
put_unaligned_le32(SIS_BASE_STRUCT_REVISION, &base_struct->revision);
put_unaligned_le32(lower_32_bits(error_buffer_paddr),
&base_struct->error_buffer_paddr_low);
put_unaligned_le32(upper_32_bits(error_buffer_paddr),
&base_struct->error_buffer_paddr_high);
put_unaligned_le32(PQI_ERROR_BUFFER_ELEMENT_LENGTH,
&base_struct->error_buffer_element_length);
put_unaligned_le32(ctrl_info->max_io_slots,
&base_struct->error_buffer_num_elements);
bus_address = pci_map_single(ctrl_info->pci_dev, base_struct,
sizeof(*base_struct), PCI_DMA_TODEVICE);
if (pci_dma_mapping_error(ctrl_info->pci_dev, bus_address)) {
rc = -ENOMEM;
goto out;
}
memset(&params, 0, sizeof(params));
params.mailbox[1] = lower_32_bits((u64)bus_address);
params.mailbox[2] = upper_32_bits((u64)bus_address);
params.mailbox[3] = sizeof(*base_struct);
rc = sis_send_sync_cmd(ctrl_info, SIS_CMD_INIT_BASE_STRUCT_ADDRESS,
&params);
pci_unmap_single(ctrl_info->pci_dev, bus_address, sizeof(*base_struct),
PCI_DMA_TODEVICE);
out:
kfree(base_struct_unaligned);
return rc;
}
static void sis_wait_for_doorbell_bit_to_clear(
struct pqi_ctrl_info *ctrl_info, u32 bit)
{
u32 doorbell_register;
unsigned long timeout;
timeout = (SIS_DOORBELL_BIT_CLEAR_TIMEOUT_SECS * HZ) + jiffies;
while (1) {
doorbell_register =
readl(&ctrl_info->registers->sis_host_to_ctrl_doorbell);
if ((doorbell_register & bit) == 0)
break;
if (readl(&ctrl_info->registers->sis_firmware_status) &
SIS_CTRL_KERNEL_PANIC)
break;
if (time_after(jiffies, timeout)) {
dev_err(&ctrl_info->pci_dev->dev,
"doorbell register bit 0x%x not cleared\n",
bit);
break;
}
usleep_range(1000, 2000);
}
}
void sis_enable_msix(struct pqi_ctrl_info *ctrl_info)
{
u32 doorbell_register;
doorbell_register =
readl(&ctrl_info->registers->sis_host_to_ctrl_doorbell);
doorbell_register |= SIS_ENABLE_MSIX;
writel(doorbell_register,
&ctrl_info->registers->sis_host_to_ctrl_doorbell);
sis_wait_for_doorbell_bit_to_clear(ctrl_info, SIS_ENABLE_MSIX);
}
void sis_disable_msix(struct pqi_ctrl_info *ctrl_info)
{
u32 doorbell_register;
doorbell_register =
readl(&ctrl_info->registers->sis_host_to_ctrl_doorbell);
doorbell_register &= ~SIS_ENABLE_MSIX;
writel(doorbell_register,
&ctrl_info->registers->sis_host_to_ctrl_doorbell);
}
void sis_enable_intx(struct pqi_ctrl_info *ctrl_info)
{
u32 doorbell_register;
doorbell_register =
readl(&ctrl_info->registers->sis_host_to_ctrl_doorbell);
doorbell_register |= SIS_ENABLE_INTX;
writel(doorbell_register,
&ctrl_info->registers->sis_host_to_ctrl_doorbell);
sis_wait_for_doorbell_bit_to_clear(ctrl_info, SIS_ENABLE_INTX);
}
void sis_disable_intx(struct pqi_ctrl_info *ctrl_info)
{
u32 doorbell_register;
doorbell_register =
readl(&ctrl_info->registers->sis_host_to_ctrl_doorbell);
doorbell_register &= ~SIS_ENABLE_INTX;
writel(doorbell_register,
&ctrl_info->registers->sis_host_to_ctrl_doorbell);
}
void sis_soft_reset(struct pqi_ctrl_info *ctrl_info)
{
writel(SIS_SOFT_RESET,
&ctrl_info->registers->sis_host_to_ctrl_doorbell);
}
void sis_shutdown_ctrl(struct pqi_ctrl_info *ctrl_info)
{
if (readl(&ctrl_info->registers->sis_firmware_status) &
SIS_CTRL_KERNEL_PANIC)
return;
writel(SIS_TRIGGER_SHUTDOWN,
&ctrl_info->registers->sis_host_to_ctrl_doorbell);
}
int sis_reenable_sis_mode(struct pqi_ctrl_info *ctrl_info)
{
int rc;
unsigned long timeout;
struct pqi_ctrl_registers __iomem *registers;
u32 doorbell;
registers = ctrl_info->registers;
writel(SIS_REENABLE_SIS_MODE,
&registers->sis_host_to_ctrl_doorbell);
rc = 0;
timeout = (SIS_MODE_READY_TIMEOUT_SECS * HZ) + jiffies;
while (1) {
doorbell = readl(&registers->sis_ctrl_to_host_doorbell);
if ((doorbell & SIS_REENABLE_SIS_MODE) == 0)
break;
if (time_after(jiffies, timeout)) {
rc = -ETIMEDOUT;
break;
}
}
if (rc)
dev_err(&ctrl_info->pci_dev->dev,
"re-enabling SIS mode failed\n");
return rc;
}
void sis_write_driver_scratch(struct pqi_ctrl_info *ctrl_info, u32 value)
{
writel(value, &ctrl_info->registers->sis_driver_scratch);
}
u32 sis_read_driver_scratch(struct pqi_ctrl_info *ctrl_info)
{
return readl(&ctrl_info->registers->sis_driver_scratch);
}
