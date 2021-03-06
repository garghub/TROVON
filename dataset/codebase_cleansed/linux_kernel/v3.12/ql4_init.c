static void ql4xxx_set_mac_number(struct scsi_qla_host *ha)
{
uint32_t value;
uint8_t func_number;
unsigned long flags;
spin_lock_irqsave(&ha->hardware_lock, flags);
value = readw(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
func_number = (uint8_t) ((value >> 4) & 0x30);
switch (value & ISP_CONTROL_FN_MASK) {
case ISP_CONTROL_FN0_SCSI:
ha->mac_index = 1;
break;
case ISP_CONTROL_FN1_SCSI:
ha->mac_index = 3;
break;
default:
DEBUG2(printk("scsi%ld: %s: Invalid function number, "
"ispControlStatus = 0x%x\n", ha->host_no,
__func__, value));
break;
}
DEBUG2(printk("scsi%ld: %s: mac_index %d.\n", ha->host_no, __func__,
ha->mac_index));
}
void qla4xxx_free_ddb(struct scsi_qla_host *ha,
struct ddb_entry *ddb_entry)
{
ha->fw_ddb_index_map[ddb_entry->fw_ddb_index] =
(struct ddb_entry *) INVALID_ENTRY;
ha->tot_ddbs--;
}
static void qla4xxx_init_response_q_entries(struct scsi_qla_host *ha)
{
uint16_t cnt;
struct response *pkt;
pkt = (struct response *)ha->response_ptr;
for (cnt = 0; cnt < RESPONSE_QUEUE_DEPTH; cnt++) {
pkt->signature = RESPONSE_PROCESSED;
pkt++;
}
}
int qla4xxx_init_rings(struct scsi_qla_host *ha)
{
unsigned long flags = 0;
int i;
spin_lock_irqsave(&ha->hardware_lock, flags);
ha->request_out = 0;
ha->request_in = 0;
ha->request_ptr = &ha->request_ring[ha->request_in];
ha->req_q_count = REQUEST_QUEUE_DEPTH;
ha->response_in = 0;
ha->response_out = 0;
ha->response_ptr = &ha->response_ring[ha->response_out];
if (is_qla8022(ha)) {
writel(0,
(unsigned long __iomem *)&ha->qla4_82xx_reg->req_q_out);
writel(0,
(unsigned long __iomem *)&ha->qla4_82xx_reg->rsp_q_in);
writel(0,
(unsigned long __iomem *)&ha->qla4_82xx_reg->rsp_q_out);
} else if (is_qla8032(ha) || is_qla8042(ha)) {
writel(0,
(unsigned long __iomem *)&ha->qla4_83xx_reg->req_q_in);
writel(0,
(unsigned long __iomem *)&ha->qla4_83xx_reg->rsp_q_in);
writel(0,
(unsigned long __iomem *)&ha->qla4_83xx_reg->rsp_q_out);
} else {
ha->shadow_regs->req_q_out = __constant_cpu_to_le32(0);
ha->shadow_regs->rsp_q_in = __constant_cpu_to_le32(0);
wmb();
writel(0, &ha->reg->req_q_in);
writel(0, &ha->reg->rsp_q_out);
readl(&ha->reg->rsp_q_out);
}
qla4xxx_init_response_q_entries(ha);
for (i = 0; i < MAX_MRB; i++)
ha->active_mrb_array[i] = NULL;
spin_unlock_irqrestore(&ha->hardware_lock, flags);
return QLA_SUCCESS;
}
int qla4xxx_get_sys_info(struct scsi_qla_host *ha)
{
struct flash_sys_info *sys_info;
dma_addr_t sys_info_dma;
int status = QLA_ERROR;
sys_info = dma_alloc_coherent(&ha->pdev->dev, sizeof(*sys_info),
&sys_info_dma, GFP_KERNEL);
if (sys_info == NULL) {
DEBUG2(printk("scsi%ld: %s: Unable to allocate dma buffer.\n",
ha->host_no, __func__));
goto exit_get_sys_info_no_free;
}
memset(sys_info, 0, sizeof(*sys_info));
if (qla4xxx_get_flash(ha, sys_info_dma, FLASH_OFFSET_SYS_INFO,
sizeof(*sys_info)) != QLA_SUCCESS) {
DEBUG2(printk("scsi%ld: %s: get_flash FLASH_OFFSET_SYS_INFO "
"failed\n", ha->host_no, __func__));
goto exit_get_sys_info;
}
memcpy(ha->my_mac, &sys_info->physAddr[0].address[0],
min(sizeof(ha->my_mac),
sizeof(sys_info->physAddr[0].address)));
memcpy(ha->serial_number, &sys_info->acSerialNumber,
min(sizeof(ha->serial_number),
sizeof(sys_info->acSerialNumber)));
status = QLA_SUCCESS;
exit_get_sys_info:
dma_free_coherent(&ha->pdev->dev, sizeof(*sys_info), sys_info,
sys_info_dma);
exit_get_sys_info_no_free:
return status;
}
static void qla4xxx_init_local_data(struct scsi_qla_host *ha)
{
ha->aen_q_count = MAX_AEN_ENTRIES;
}
static uint8_t
qla4xxx_wait_for_ip_config(struct scsi_qla_host *ha)
{
uint8_t ipv4_wait = 0;
uint8_t ipv6_wait = 0;
int8_t ip_address[IPv6_ADDR_LEN] = {0} ;
if (is_ipv4_enabled(ha) && is_ipv6_enabled(ha)) {
if (((ha->addl_fw_state & FW_ADDSTATE_DHCPv4_ENABLED) != 0) &&
((ha->addl_fw_state &
FW_ADDSTATE_DHCPv4_LEASE_ACQUIRED) == 0)) {
ipv4_wait = 1;
}
if (((ha->ip_config.ipv6_addl_options &
IPV6_ADDOPT_NEIGHBOR_DISCOVERY_ADDR_ENABLE) != 0) &&
((ha->ip_config.ipv6_link_local_state ==
IP_ADDRSTATE_ACQUIRING) ||
(ha->ip_config.ipv6_addr0_state ==
IP_ADDRSTATE_ACQUIRING) ||
(ha->ip_config.ipv6_addr1_state ==
IP_ADDRSTATE_ACQUIRING))) {
ipv6_wait = 1;
if ((ha->ip_config.ipv6_link_local_state ==
IP_ADDRSTATE_PREFERRED) ||
(ha->ip_config.ipv6_addr0_state ==
IP_ADDRSTATE_PREFERRED) ||
(ha->ip_config.ipv6_addr1_state ==
IP_ADDRSTATE_PREFERRED)) {
DEBUG2(printk(KERN_INFO "scsi%ld: %s: "
"Preferred IP configured."
" Don't wait!\n", ha->host_no,
__func__));
ipv6_wait = 0;
}
if (memcmp(&ha->ip_config.ipv6_default_router_addr,
ip_address, IPv6_ADDR_LEN) == 0) {
DEBUG2(printk(KERN_INFO "scsi%ld: %s: "
"No Router configured. "
"Don't wait!\n", ha->host_no,
__func__));
ipv6_wait = 0;
}
if ((ha->ip_config.ipv6_default_router_state ==
IPV6_RTRSTATE_MANUAL) &&
(ha->ip_config.ipv6_link_local_state ==
IP_ADDRSTATE_TENTATIVE) &&
(memcmp(&ha->ip_config.ipv6_link_local_addr,
&ha->ip_config.ipv6_default_router_addr, 4) ==
0)) {
DEBUG2(printk("scsi%ld: %s: LinkLocal Router & "
"IP configured. Don't wait!\n",
ha->host_no, __func__));
ipv6_wait = 0;
}
}
if (ipv4_wait || ipv6_wait) {
DEBUG2(printk("scsi%ld: %s: Wait for additional "
"IP(s) \"", ha->host_no, __func__));
if (ipv4_wait)
DEBUG2(printk("IPv4 "));
if (ha->ip_config.ipv6_link_local_state ==
IP_ADDRSTATE_ACQUIRING)
DEBUG2(printk("IPv6LinkLocal "));
if (ha->ip_config.ipv6_addr0_state ==
IP_ADDRSTATE_ACQUIRING)
DEBUG2(printk("IPv6Addr0 "));
if (ha->ip_config.ipv6_addr1_state ==
IP_ADDRSTATE_ACQUIRING)
DEBUG2(printk("IPv6Addr1 "));
DEBUG2(printk("\"\n"));
}
}
return ipv4_wait|ipv6_wait;
}
void qla4xxx_alloc_fw_dump(struct scsi_qla_host *ha)
{
int status;
uint32_t capture_debug_level;
int hdr_entry_bit, k;
void *md_tmp;
dma_addr_t md_tmp_dma;
struct qla4_8xxx_minidump_template_hdr *md_hdr;
if (ha->fw_dump) {
ql4_printk(KERN_WARNING, ha,
"Firmware dump previously allocated.\n");
return;
}
status = qla4xxx_req_template_size(ha);
if (status != QLA_SUCCESS) {
ql4_printk(KERN_INFO, ha,
"scsi%ld: Failed to get template size\n",
ha->host_no);
return;
}
clear_bit(AF_82XX_FW_DUMPED, &ha->flags);
md_tmp = dma_alloc_coherent(&ha->pdev->dev, ha->fw_dump_tmplt_size,
&md_tmp_dma, GFP_KERNEL);
status = qla4xxx_get_minidump_template(ha, md_tmp_dma);
if (status != QLA_SUCCESS) {
ql4_printk(KERN_INFO, ha,
"scsi%ld: Failed to get minidump template\n",
ha->host_no);
goto alloc_cleanup;
}
md_hdr = (struct qla4_8xxx_minidump_template_hdr *)md_tmp;
capture_debug_level = md_hdr->capture_debug_level;
if (ql4xmdcapmask >= 0x3 && ql4xmdcapmask <= 0x7F)
ha->fw_dump_capture_mask = ql4xmdcapmask;
else
ha->fw_dump_capture_mask = capture_debug_level;
md_hdr->driver_capture_mask = ha->fw_dump_capture_mask;
DEBUG2(ql4_printk(KERN_INFO, ha, "Minimum num of entries = %d\n",
md_hdr->num_of_entries));
DEBUG2(ql4_printk(KERN_INFO, ha, "Dump template size = %d\n",
ha->fw_dump_tmplt_size));
DEBUG2(ql4_printk(KERN_INFO, ha, "Selected Capture mask =0x%x\n",
ha->fw_dump_capture_mask));
for (hdr_entry_bit = 0x2, k = 1; (hdr_entry_bit & 0xFF);
hdr_entry_bit <<= 1, k++) {
if (hdr_entry_bit & ha->fw_dump_capture_mask)
ha->fw_dump_size += md_hdr->capture_size_array[k];
}
ha->fw_dump_size += ha->fw_dump_tmplt_size;
ha->fw_dump = vmalloc(ha->fw_dump_size);
if (!ha->fw_dump)
goto alloc_cleanup;
DEBUG2(ql4_printk(KERN_INFO, ha,
"Minidump Tempalate Size = 0x%x KB\n",
ha->fw_dump_tmplt_size));
DEBUG2(ql4_printk(KERN_INFO, ha,
"Total Minidump size = 0x%x KB\n", ha->fw_dump_size));
memcpy(ha->fw_dump, md_tmp, ha->fw_dump_tmplt_size);
ha->fw_dump_tmplt_hdr = ha->fw_dump;
alloc_cleanup:
dma_free_coherent(&ha->pdev->dev, ha->fw_dump_tmplt_size,
md_tmp, md_tmp_dma);
}
static int qla4xxx_fw_ready(struct scsi_qla_host *ha)
{
uint32_t timeout_count;
int ready = 0;
DEBUG2(ql4_printk(KERN_INFO, ha, "Waiting for Firmware Ready..\n"));
for (timeout_count = ADAPTER_INIT_TOV; timeout_count > 0;
timeout_count--) {
if (test_and_clear_bit(DPC_GET_DHCP_IP_ADDR, &ha->dpc_flags))
qla4xxx_get_dhcp_ip_address(ha);
if (qla4xxx_get_firmware_state(ha) != QLA_SUCCESS) {
DEBUG2(printk("scsi%ld: %s: unable to get firmware "
"state\n", ha->host_no, __func__));
break;
}
if (ha->firmware_state & FW_STATE_ERROR) {
DEBUG2(printk("scsi%ld: %s: an unrecoverable error has"
" occurred\n", ha->host_no, __func__));
break;
}
if (ha->firmware_state & FW_STATE_CONFIG_WAIT) {
if (qla4xxx_initialize_fw_cb(ha) == QLA_ERROR)
break;
continue;
}
if (ha->firmware_state & FW_STATE_WAIT_AUTOCONNECT) {
DEBUG2(printk(KERN_INFO "scsi%ld: %s: fwstate:"
"AUTOCONNECT in progress\n",
ha->host_no, __func__));
}
if (ha->firmware_state & FW_STATE_CONFIGURING_IP) {
DEBUG2(printk(KERN_INFO "scsi%ld: %s: fwstate:"
" CONFIGURING IP\n",
ha->host_no, __func__));
if (timeout_count <= (ADAPTER_INIT_TOV - 15)) {
if (ha->addl_fw_state & FW_ADDSTATE_LINK_UP) {
DEBUG2(printk(KERN_INFO "scsi%ld: %s:"
" LINK UP (Cable plugged)\n",
ha->host_no, __func__));
} else if (ha->firmware_state &
(FW_STATE_CONFIGURING_IP |
FW_STATE_READY)) {
DEBUG2(printk(KERN_INFO "scsi%ld: %s: "
"LINK DOWN (Cable unplugged)\n",
ha->host_no, __func__));
ha->firmware_state = FW_STATE_READY;
}
}
}
if (ha->firmware_state == FW_STATE_READY) {
if (test_and_clear_bit(DPC_GET_DHCP_IP_ADDR,
&ha->dpc_flags))
qla4xxx_get_dhcp_ip_address(ha);
if (!qla4xxx_wait_for_ip_config(ha) ||
timeout_count == 1) {
DEBUG2(ql4_printk(KERN_INFO, ha,
"Firmware Ready..\n"));
DEBUG2(ql4_printk(KERN_INFO, ha,
"scsi%ld: %s: MEDIA TYPE"
" - %s\n", ha->host_no,
__func__, (ha->addl_fw_state &
FW_ADDSTATE_OPTICAL_MEDIA)
!= 0 ? "OPTICAL" : "COPPER"));
DEBUG2(ql4_printk(KERN_INFO, ha,
"scsi%ld: %s: DHCPv4 STATE"
" Enabled %s\n", ha->host_no,
__func__, (ha->addl_fw_state &
FW_ADDSTATE_DHCPv4_ENABLED) != 0 ?
"YES" : "NO"));
DEBUG2(ql4_printk(KERN_INFO, ha,
"scsi%ld: %s: LINK %s\n",
ha->host_no, __func__,
(ha->addl_fw_state &
FW_ADDSTATE_LINK_UP) != 0 ?
"UP" : "DOWN"));
DEBUG2(ql4_printk(KERN_INFO, ha,
"scsi%ld: %s: iSNS Service "
"Started %s\n",
ha->host_no, __func__,
(ha->addl_fw_state &
FW_ADDSTATE_ISNS_SVC_ENABLED) != 0 ?
"YES" : "NO"));
ready = 1;
break;
}
}
DEBUG2(printk("scsi%ld: %s: waiting on fw, state=%x:%x - "
"seconds expired= %d\n", ha->host_no, __func__,
ha->firmware_state, ha->addl_fw_state,
timeout_count));
if (is_qla4032(ha) &&
!(ha->addl_fw_state & FW_ADDSTATE_LINK_UP) &&
(timeout_count < ADAPTER_INIT_TOV - 5)) {
break;
}
msleep(1000);
}
if (timeout_count <= 0)
DEBUG2(printk("scsi%ld: %s: FW Initialization timed out!\n",
ha->host_no, __func__));
if (ha->firmware_state & FW_STATE_CONFIGURING_IP) {
DEBUG2(printk("scsi%ld: %s: FW initialized, but is reporting "
"it's waiting to configure an IP address\n",
ha->host_no, __func__));
ready = 1;
} else if (ha->firmware_state & FW_STATE_WAIT_AUTOCONNECT) {
DEBUG2(printk("scsi%ld: %s: FW initialized, but "
"auto-discovery still in process\n",
ha->host_no, __func__));
ready = 1;
}
return ready;
}
static int qla4xxx_init_firmware(struct scsi_qla_host *ha)
{
int status = QLA_ERROR;
if (is_aer_supported(ha) &&
test_bit(AF_PCI_CHANNEL_IO_PERM_FAILURE, &ha->flags))
return status;
if (is_qla80XX(ha))
qla4_8xxx_stop_firmware(ha);
ql4_printk(KERN_INFO, ha, "Initializing firmware..\n");
if (qla4xxx_initialize_fw_cb(ha) == QLA_ERROR) {
DEBUG2(printk("scsi%ld: %s: Failed to initialize firmware "
"control block\n", ha->host_no, __func__));
return status;
}
if (!qla4xxx_fw_ready(ha))
return status;
if (is_qla80XX(ha) && !test_bit(AF_INIT_DONE, &ha->flags))
qla4xxx_alloc_fw_dump(ha);
return qla4xxx_get_firmware_status(ha);
}
static void qla4xxx_set_model_info(struct scsi_qla_host *ha)
{
uint16_t board_id_string[8];
int i;
int size = sizeof(ha->nvram->isp4022.boardIdStr);
int offset = offsetof(struct eeprom_data, isp4022.boardIdStr) / 2;
for (i = 0; i < (size / 2) ; i++) {
board_id_string[i] = rd_nvram_word(ha, offset);
offset += 1;
}
memcpy(ha->model_name, board_id_string, size);
}
static int qla4xxx_config_nvram(struct scsi_qla_host *ha)
{
unsigned long flags;
union external_hw_config_reg extHwConfig;
DEBUG2(printk("scsi%ld: %s: Get EEProm parameters \n", ha->host_no,
__func__));
if (ql4xxx_lock_flash(ha) != QLA_SUCCESS)
return QLA_ERROR;
if (ql4xxx_lock_nvram(ha) != QLA_SUCCESS) {
ql4xxx_unlock_flash(ha);
return QLA_ERROR;
}
ql4_printk(KERN_INFO, ha, "Configuring NVRAM ...\n");
if (qla4xxx_is_nvram_configuration_valid(ha) == QLA_SUCCESS) {
spin_lock_irqsave(&ha->hardware_lock, flags);
extHwConfig.Asuint32_t =
rd_nvram_word(ha, eeprom_ext_hw_conf_offset(ha));
spin_unlock_irqrestore(&ha->hardware_lock, flags);
} else {
ql4_printk(KERN_WARNING, ha,
"scsi%ld: %s: EEProm checksum invalid. "
"Please update your EEPROM\n", ha->host_no,
__func__);
if (is_qla4010(ha))
extHwConfig.Asuint32_t = 0x1912;
else if (is_qla4022(ha) | is_qla4032(ha))
extHwConfig.Asuint32_t = 0x0023;
else
return QLA_ERROR;
}
if (is_qla4022(ha) || is_qla4032(ha))
qla4xxx_set_model_info(ha);
else
strcpy(ha->model_name, "QLA4010");
DEBUG(printk("scsi%ld: %s: Setting extHwConfig to 0xFFFF%04x\n",
ha->host_no, __func__, extHwConfig.Asuint32_t));
spin_lock_irqsave(&ha->hardware_lock, flags);
writel((0xFFFF << 16) | extHwConfig.Asuint32_t, isp_ext_hw_conf(ha));
readl(isp_ext_hw_conf(ha));
spin_unlock_irqrestore(&ha->hardware_lock, flags);
ql4xxx_unlock_nvram(ha);
ql4xxx_unlock_flash(ha);
return QLA_SUCCESS;
}
void qla4_8xxx_pci_config(struct scsi_qla_host *ha)
{
pci_set_master(ha->pdev);
}
void qla4xxx_pci_config(struct scsi_qla_host *ha)
{
uint16_t w;
int status;
ql4_printk(KERN_INFO, ha, "Configuring PCI space...\n");
pci_set_master(ha->pdev);
status = pci_set_mwi(ha->pdev);
pci_read_config_word(ha->pdev, PCI_COMMAND, &w);
w |= PCI_COMMAND_PARITY | PCI_COMMAND_SERR;
w &= ~PCI_COMMAND_INTX_DISABLE;
pci_write_config_word(ha->pdev, PCI_COMMAND, w);
}
static int qla4xxx_start_firmware_from_flash(struct scsi_qla_host *ha)
{
int status = QLA_ERROR;
unsigned long max_wait_time;
unsigned long flags;
uint32_t mbox_status;
ql4_printk(KERN_INFO, ha, "Starting firmware ...\n");
DEBUG(printk("scsi%d: %s: Start firmware from flash ROM\n",
ha->host_no, __func__));
spin_lock_irqsave(&ha->hardware_lock, flags);
writel(jiffies, &ha->reg->mailbox[7]);
if (is_qla4022(ha) | is_qla4032(ha))
writel(set_rmask(NVR_WRITE_ENABLE),
&ha->reg->u1.isp4022.nvram);
writel(2, &ha->reg->mailbox[6]);
readl(&ha->reg->mailbox[6]);
writel(set_rmask(CSR_BOOT_ENABLE), &ha->reg->ctrl_status);
readl(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
DEBUG2(printk(KERN_INFO "scsi%ld: %s: Wait up to %d seconds for "
"boot firmware to complete...\n",
ha->host_no, __func__, FIRMWARE_UP_TOV));
max_wait_time = jiffies + (FIRMWARE_UP_TOV * HZ);
do {
uint32_t ctrl_status;
spin_lock_irqsave(&ha->hardware_lock, flags);
ctrl_status = readw(&ha->reg->ctrl_status);
mbox_status = readw(&ha->reg->mailbox[0]);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
if (ctrl_status & set_rmask(CSR_SCSI_PROCESSOR_INTR))
break;
if (mbox_status == MBOX_STS_COMMAND_COMPLETE)
break;
DEBUG2(printk(KERN_INFO "scsi%ld: %s: Waiting for boot "
"firmware to complete... ctrl_sts=0x%x, remaining=%ld\n",
ha->host_no, __func__, ctrl_status, max_wait_time));
msleep_interruptible(250);
} while (!time_after_eq(jiffies, max_wait_time));
if (mbox_status == MBOX_STS_COMMAND_COMPLETE) {
DEBUG(printk(KERN_INFO "scsi%ld: %s: Firmware has started\n",
ha->host_no, __func__));
spin_lock_irqsave(&ha->hardware_lock, flags);
writel(set_rmask(CSR_SCSI_PROCESSOR_INTR),
&ha->reg->ctrl_status);
readl(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
status = QLA_SUCCESS;
} else {
printk(KERN_INFO "scsi%ld: %s: Boot firmware failed "
"- mbox status 0x%x\n", ha->host_no, __func__,
mbox_status);
status = QLA_ERROR;
}
return status;
}
int ql4xxx_lock_drvr_wait(struct scsi_qla_host *a)
{
#define QL4_LOCK_DRVR_WAIT 60
#define QL4_LOCK_DRVR_SLEEP 1
int drvr_wait = QL4_LOCK_DRVR_WAIT;
while (drvr_wait) {
if (ql4xxx_lock_drvr(a) == 0) {
ssleep(QL4_LOCK_DRVR_SLEEP);
if (drvr_wait) {
DEBUG2(printk("scsi%ld: %s: Waiting for "
"Global Init Semaphore(%d)...\n",
a->host_no,
__func__, drvr_wait));
}
drvr_wait -= QL4_LOCK_DRVR_SLEEP;
} else {
DEBUG2(printk("scsi%ld: %s: Global Init Semaphore "
"acquired\n", a->host_no, __func__));
return QLA_SUCCESS;
}
}
return QLA_ERROR;
}
int qla4xxx_start_firmware(struct scsi_qla_host *ha)
{
unsigned long flags = 0;
uint32_t mbox_status;
int status = QLA_ERROR;
int soft_reset = 1;
int config_chip = 0;
if (is_qla4022(ha) | is_qla4032(ha))
ql4xxx_set_mac_number(ha);
if (ql4xxx_lock_drvr_wait(ha) != QLA_SUCCESS)
return QLA_ERROR;
spin_lock_irqsave(&ha->hardware_lock, flags);
DEBUG2(printk("scsi%ld: %s: port_ctrl = 0x%08X\n", ha->host_no,
__func__, readw(isp_port_ctrl(ha))));
DEBUG(printk("scsi%ld: %s: port_status = 0x%08X\n", ha->host_no,
__func__, readw(isp_port_status(ha))));
if ((readw(isp_port_ctrl(ha)) & 0x8000) != 0) {
DEBUG(printk("scsi%ld: %s: Hardware has already been "
"initialized\n", ha->host_no, __func__));
mbox_status = readw(&ha->reg->mailbox[0]);
DEBUG2(printk("scsi%ld: %s: H/W Config complete - mbox[0]= "
"0x%x\n", ha->host_no, __func__, mbox_status));
if (mbox_status == 0) {
config_chip = 1;
soft_reset = 0;
} else {
writel(set_rmask(CSR_SCSI_PROCESSOR_INTR),
&ha->reg->ctrl_status);
readl(&ha->reg->ctrl_status);
writel(set_rmask(CSR_SCSI_COMPLETION_INTR),
&ha->reg->ctrl_status);
readl(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
if (qla4xxx_get_firmware_state(ha) == QLA_SUCCESS) {
DEBUG2(printk("scsi%ld: %s: Get firmware "
"state -- state = 0x%x\n",
ha->host_no,
__func__, ha->firmware_state));
if (ha->firmware_state &
FW_STATE_CONFIG_WAIT) {
DEBUG2(printk("scsi%ld: %s: Firmware "
"in known state -- "
"config and "
"boot, state = 0x%x\n",
ha->host_no, __func__,
ha->firmware_state));
config_chip = 1;
soft_reset = 0;
}
} else {
DEBUG2(printk("scsi%ld: %s: Firmware in "
"unknown state -- resetting,"
" state = "
"0x%x\n", ha->host_no, __func__,
ha->firmware_state));
}
spin_lock_irqsave(&ha->hardware_lock, flags);
}
} else {
DEBUG(printk("scsi%ld: %s: H/W initialization hasn't been "
"started - resetting\n", ha->host_no, __func__));
}
spin_unlock_irqrestore(&ha->hardware_lock, flags);
DEBUG(printk("scsi%ld: %s: Flags soft_rest=%d, config= %d\n ",
ha->host_no, __func__, soft_reset, config_chip));
if (soft_reset) {
DEBUG(printk("scsi%ld: %s: Issue Soft Reset\n", ha->host_no,
__func__));
status = qla4xxx_soft_reset(ha);
if (status == QLA_ERROR) {
DEBUG(printk("scsi%d: %s: Soft Reset failed!\n",
ha->host_no, __func__));
ql4xxx_unlock_drvr(ha);
return QLA_ERROR;
}
config_chip = 1;
if (ql4xxx_lock_drvr_wait(ha) != QLA_SUCCESS)
return QLA_ERROR;
}
if (config_chip) {
if ((status = qla4xxx_config_nvram(ha)) == QLA_SUCCESS)
status = qla4xxx_start_firmware_from_flash(ha);
}
ql4xxx_unlock_drvr(ha);
if (status == QLA_SUCCESS) {
if (test_and_clear_bit(AF_GET_CRASH_RECORD, &ha->flags))
qla4xxx_get_crash_record(ha);
} else {
DEBUG(printk("scsi%ld: %s: Firmware has NOT started\n",
ha->host_no, __func__));
}
return status;
}
void qla4xxx_free_ddb_index(struct scsi_qla_host *ha)
{
int max_ddbs;
int ret;
uint32_t idx = 0, next_idx = 0;
uint32_t state = 0, conn_err = 0;
max_ddbs = is_qla40XX(ha) ? MAX_DEV_DB_ENTRIES_40XX :
MAX_DEV_DB_ENTRIES;
for (idx = 0; idx < max_ddbs; idx = next_idx) {
ret = qla4xxx_get_fwddb_entry(ha, idx, NULL, 0, NULL,
&next_idx, &state, &conn_err,
NULL, NULL);
if (ret == QLA_ERROR) {
next_idx++;
continue;
}
if (state == DDB_DS_NO_CONNECTION_ACTIVE ||
state == DDB_DS_SESSION_FAILED) {
DEBUG2(ql4_printk(KERN_INFO, ha,
"Freeing DDB index = 0x%x\n", idx));
ret = qla4xxx_clear_ddb_entry(ha, idx);
if (ret == QLA_ERROR)
ql4_printk(KERN_ERR, ha,
"Unable to clear DDB index = "
"0x%x\n", idx);
}
if (next_idx == 0)
break;
}
}
int qla4xxx_initialize_adapter(struct scsi_qla_host *ha, int is_reset)
{
int status = QLA_ERROR;
ha->eeprom_cmd_data = 0;
ql4_printk(KERN_INFO, ha, "Configuring PCI space...\n");
ha->isp_ops->pci_config(ha);
ha->isp_ops->disable_intrs(ha);
if (ha->isp_ops->start_firmware(ha) == QLA_ERROR)
goto exit_init_hba;
if (is_qla8032(ha) || is_qla8042(ha))
qla4_83xx_enable_mbox_intrs(ha);
if (qla4xxx_about_firmware(ha) == QLA_ERROR)
goto exit_init_hba;
if (ha->isp_ops->get_sys_info(ha) == QLA_ERROR)
goto exit_init_hba;
qla4xxx_init_local_data(ha);
status = qla4xxx_init_firmware(ha);
if (status == QLA_ERROR)
goto exit_init_hba;
if (is_reset == RESET_ADAPTER)
qla4xxx_build_ddb_list(ha, is_reset);
set_bit(AF_ONLINE, &ha->flags);
exit_init_hba:
if (is_qla80XX(ha) && (status == QLA_ERROR)) {
qla4xxx_free_irqs(ha);
}
DEBUG2(printk("scsi%ld: initialize adapter: %s\n", ha->host_no,
status == QLA_ERROR ? "FAILED" : "SUCCEEDED"));
return status;
}
int qla4xxx_ddb_change(struct scsi_qla_host *ha, uint32_t fw_ddb_index,
struct ddb_entry *ddb_entry, uint32_t state)
{
uint32_t old_fw_ddb_device_state;
int status = QLA_ERROR;
old_fw_ddb_device_state = ddb_entry->fw_ddb_device_state;
DEBUG2(ql4_printk(KERN_INFO, ha,
"%s: DDB - old state = 0x%x, new state = 0x%x for "
"index [%d]\n", __func__,
ddb_entry->fw_ddb_device_state, state, fw_ddb_index));
ddb_entry->fw_ddb_device_state = state;
switch (old_fw_ddb_device_state) {
case DDB_DS_LOGIN_IN_PROCESS:
switch (state) {
case DDB_DS_SESSION_ACTIVE:
case DDB_DS_DISCOVERY:
qla4xxx_update_session_conn_param(ha, ddb_entry);
ddb_entry->unblock_sess(ddb_entry->sess);
status = QLA_SUCCESS;
break;
case DDB_DS_SESSION_FAILED:
case DDB_DS_NO_CONNECTION_ACTIVE:
iscsi_conn_login_event(ddb_entry->conn,
ISCSI_CONN_STATE_FREE);
status = QLA_SUCCESS;
break;
}
break;
case DDB_DS_SESSION_ACTIVE:
case DDB_DS_DISCOVERY:
switch (state) {
case DDB_DS_SESSION_FAILED:
iscsi_session_failure(ddb_entry->sess->dd_data,
ISCSI_ERR_CONN_FAILED);
status = QLA_SUCCESS;
break;
case DDB_DS_NO_CONNECTION_ACTIVE:
clear_bit(fw_ddb_index, ha->ddb_idx_map);
status = QLA_SUCCESS;
break;
}
break;
case DDB_DS_SESSION_FAILED:
switch (state) {
case DDB_DS_SESSION_ACTIVE:
case DDB_DS_DISCOVERY:
ddb_entry->unblock_sess(ddb_entry->sess);
qla4xxx_update_session_conn_param(ha, ddb_entry);
status = QLA_SUCCESS;
break;
case DDB_DS_SESSION_FAILED:
iscsi_session_failure(ddb_entry->sess->dd_data,
ISCSI_ERR_CONN_FAILED);
status = QLA_SUCCESS;
break;
}
break;
default:
DEBUG2(ql4_printk(KERN_INFO, ha, "%s: Unknown Event\n",
__func__));
break;
}
return status;
}
void qla4xxx_arm_relogin_timer(struct ddb_entry *ddb_entry)
{
atomic_set(&ddb_entry->relogin_timer, 0);
atomic_set(&ddb_entry->retry_relogin_timer,
ddb_entry->default_time2wait + 4);
}
int qla4xxx_flash_ddb_change(struct scsi_qla_host *ha, uint32_t fw_ddb_index,
struct ddb_entry *ddb_entry, uint32_t state)
{
uint32_t old_fw_ddb_device_state;
int status = QLA_ERROR;
old_fw_ddb_device_state = ddb_entry->fw_ddb_device_state;
DEBUG2(ql4_printk(KERN_INFO, ha,
"%s: DDB - old state = 0x%x, new state = 0x%x for "
"index [%d]\n", __func__,
ddb_entry->fw_ddb_device_state, state, fw_ddb_index));
ddb_entry->fw_ddb_device_state = state;
switch (old_fw_ddb_device_state) {
case DDB_DS_LOGIN_IN_PROCESS:
case DDB_DS_NO_CONNECTION_ACTIVE:
switch (state) {
case DDB_DS_SESSION_ACTIVE:
ddb_entry->unblock_sess(ddb_entry->sess);
qla4xxx_update_session_conn_fwddb_param(ha, ddb_entry);
status = QLA_SUCCESS;
break;
case DDB_DS_SESSION_FAILED:
iscsi_block_session(ddb_entry->sess);
if (!test_bit(DF_RELOGIN, &ddb_entry->flags))
qla4xxx_arm_relogin_timer(ddb_entry);
status = QLA_SUCCESS;
break;
}
break;
case DDB_DS_SESSION_ACTIVE:
switch (state) {
case DDB_DS_SESSION_FAILED:
iscsi_block_session(ddb_entry->sess);
if (!test_bit(DF_RELOGIN, &ddb_entry->flags))
qla4xxx_arm_relogin_timer(ddb_entry);
status = QLA_SUCCESS;
break;
}
break;
case DDB_DS_SESSION_FAILED:
switch (state) {
case DDB_DS_SESSION_ACTIVE:
ddb_entry->unblock_sess(ddb_entry->sess);
qla4xxx_update_session_conn_fwddb_param(ha, ddb_entry);
status = QLA_SUCCESS;
break;
case DDB_DS_SESSION_FAILED:
if (!test_bit(DF_RELOGIN, &ddb_entry->flags))
qla4xxx_arm_relogin_timer(ddb_entry);
status = QLA_SUCCESS;
break;
}
break;
default:
DEBUG2(ql4_printk(KERN_INFO, ha, "%s: Unknown Event\n",
__func__));
break;
}
return status;
}
int qla4xxx_process_ddb_changed(struct scsi_qla_host *ha,
uint32_t fw_ddb_index,
uint32_t state, uint32_t conn_err)
{
struct ddb_entry *ddb_entry;
int status = QLA_ERROR;
if (fw_ddb_index >= MAX_DDB_ENTRIES)
goto exit_ddb_event;
ddb_entry = qla4xxx_lookup_ddb_by_fw_index(ha, fw_ddb_index);
if (ddb_entry == NULL) {
ql4_printk(KERN_ERR, ha, "%s: No ddb_entry at FW index [%d]\n",
__func__, fw_ddb_index);
if (state == DDB_DS_NO_CONNECTION_ACTIVE)
clear_bit(fw_ddb_index, ha->ddb_idx_map);
goto exit_ddb_event;
}
ddb_entry->ddb_change(ha, fw_ddb_index, ddb_entry, state);
exit_ddb_event:
return status;
}
void qla4xxx_login_flash_ddb(struct iscsi_cls_session *cls_session)
{
struct iscsi_session *sess;
struct ddb_entry *ddb_entry;
struct scsi_qla_host *ha;
struct dev_db_entry *fw_ddb_entry = NULL;
dma_addr_t fw_ddb_dma;
uint32_t mbx_sts = 0;
int ret;
sess = cls_session->dd_data;
ddb_entry = sess->dd_data;
ha = ddb_entry->ha;
if (!test_bit(AF_LINK_UP, &ha->flags))
return;
if (ddb_entry->ddb_type != FLASH_DDB) {
DEBUG2(ql4_printk(KERN_INFO, ha,
"Skipping login to non FLASH DB"));
goto exit_login;
}
fw_ddb_entry = dma_pool_alloc(ha->fw_ddb_dma_pool, GFP_KERNEL,
&fw_ddb_dma);
if (fw_ddb_entry == NULL) {
DEBUG2(ql4_printk(KERN_ERR, ha, "Out of memory\n"));
goto exit_login;
}
if (ddb_entry->fw_ddb_index == INVALID_ENTRY) {
ret = qla4xxx_get_ddb_index(ha, &ddb_entry->fw_ddb_index);
if (ret == QLA_ERROR)
goto exit_login;
ha->fw_ddb_index_map[ddb_entry->fw_ddb_index] = ddb_entry;
ha->tot_ddbs++;
}
memcpy(fw_ddb_entry, &ddb_entry->fw_ddb_entry,
sizeof(struct dev_db_entry));
ddb_entry->sess->target_id = ddb_entry->fw_ddb_index;
ret = qla4xxx_set_ddb_entry(ha, ddb_entry->fw_ddb_index,
fw_ddb_dma, &mbx_sts);
if (ret == QLA_ERROR) {
DEBUG2(ql4_printk(KERN_ERR, ha, "Set DDB failed\n"));
goto exit_login;
}
ddb_entry->fw_ddb_device_state = DDB_DS_LOGIN_IN_PROCESS;
ret = qla4xxx_conn_open(ha, ddb_entry->fw_ddb_index);
if (ret == QLA_ERROR) {
ql4_printk(KERN_ERR, ha, "%s: Login failed: %s\n", __func__,
sess->targetname);
goto exit_login;
}
exit_login:
if (fw_ddb_entry)
dma_pool_free(ha->fw_ddb_dma_pool, fw_ddb_entry, fw_ddb_dma);
}
