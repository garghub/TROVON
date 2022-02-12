static inline bool i40e_is_nvm_update_op(struct i40e_aq_desc *desc)
{
return (desc->opcode == i40e_aqc_opc_nvm_erase) ||
(desc->opcode == i40e_aqc_opc_nvm_update);
}
static void i40e_adminq_init_regs(struct i40e_hw *hw)
{
if (hw->mac.type == I40E_MAC_VF) {
hw->aq.asq.tail = I40E_VF_ATQT1;
hw->aq.asq.head = I40E_VF_ATQH1;
hw->aq.asq.len = I40E_VF_ATQLEN1;
hw->aq.arq.tail = I40E_VF_ARQT1;
hw->aq.arq.head = I40E_VF_ARQH1;
hw->aq.arq.len = I40E_VF_ARQLEN1;
} else {
hw->aq.asq.tail = I40E_PF_ATQT;
hw->aq.asq.head = I40E_PF_ATQH;
hw->aq.asq.len = I40E_PF_ATQLEN;
hw->aq.arq.tail = I40E_PF_ARQT;
hw->aq.arq.head = I40E_PF_ARQH;
hw->aq.arq.len = I40E_PF_ARQLEN;
}
}
static i40e_status i40e_alloc_adminq_asq_ring(struct i40e_hw *hw)
{
i40e_status ret_code;
ret_code = i40e_allocate_dma_mem(hw, &hw->aq.asq.desc_buf,
i40e_mem_atq_ring,
(hw->aq.num_asq_entries *
sizeof(struct i40e_aq_desc)),
I40E_ADMINQ_DESC_ALIGNMENT);
if (ret_code)
return ret_code;
ret_code = i40e_allocate_virt_mem(hw, &hw->aq.asq.cmd_buf,
(hw->aq.num_asq_entries *
sizeof(struct i40e_asq_cmd_details)));
if (ret_code) {
i40e_free_dma_mem(hw, &hw->aq.asq.desc_buf);
return ret_code;
}
return ret_code;
}
static i40e_status i40e_alloc_adminq_arq_ring(struct i40e_hw *hw)
{
i40e_status ret_code;
ret_code = i40e_allocate_dma_mem(hw, &hw->aq.arq.desc_buf,
i40e_mem_arq_ring,
(hw->aq.num_arq_entries *
sizeof(struct i40e_aq_desc)),
I40E_ADMINQ_DESC_ALIGNMENT);
return ret_code;
}
static void i40e_free_adminq_asq(struct i40e_hw *hw)
{
i40e_free_dma_mem(hw, &hw->aq.asq.desc_buf);
}
static void i40e_free_adminq_arq(struct i40e_hw *hw)
{
i40e_free_dma_mem(hw, &hw->aq.arq.desc_buf);
}
static i40e_status i40e_alloc_arq_bufs(struct i40e_hw *hw)
{
i40e_status ret_code;
struct i40e_aq_desc *desc;
struct i40e_dma_mem *bi;
int i;
ret_code = i40e_allocate_virt_mem(hw, &hw->aq.arq.dma_head,
(hw->aq.num_arq_entries * sizeof(struct i40e_dma_mem)));
if (ret_code)
goto alloc_arq_bufs;
hw->aq.arq.r.arq_bi = (struct i40e_dma_mem *)hw->aq.arq.dma_head.va;
for (i = 0; i < hw->aq.num_arq_entries; i++) {
bi = &hw->aq.arq.r.arq_bi[i];
ret_code = i40e_allocate_dma_mem(hw, bi,
i40e_mem_arq_buf,
hw->aq.arq_buf_size,
I40E_ADMINQ_DESC_ALIGNMENT);
if (ret_code)
goto unwind_alloc_arq_bufs;
desc = I40E_ADMINQ_DESC(hw->aq.arq, i);
desc->flags = cpu_to_le16(I40E_AQ_FLAG_BUF);
if (hw->aq.arq_buf_size > I40E_AQ_LARGE_BUF)
desc->flags |= cpu_to_le16(I40E_AQ_FLAG_LB);
desc->opcode = 0;
desc->datalen = cpu_to_le16((u16)bi->size);
desc->retval = 0;
desc->cookie_high = 0;
desc->cookie_low = 0;
desc->params.external.addr_high =
cpu_to_le32(upper_32_bits(bi->pa));
desc->params.external.addr_low =
cpu_to_le32(lower_32_bits(bi->pa));
desc->params.external.param0 = 0;
desc->params.external.param1 = 0;
}
alloc_arq_bufs:
return ret_code;
unwind_alloc_arq_bufs:
i--;
for (; i >= 0; i--)
i40e_free_dma_mem(hw, &hw->aq.arq.r.arq_bi[i]);
i40e_free_virt_mem(hw, &hw->aq.arq.dma_head);
return ret_code;
}
static i40e_status i40e_alloc_asq_bufs(struct i40e_hw *hw)
{
i40e_status ret_code;
struct i40e_dma_mem *bi;
int i;
ret_code = i40e_allocate_virt_mem(hw, &hw->aq.asq.dma_head,
(hw->aq.num_asq_entries * sizeof(struct i40e_dma_mem)));
if (ret_code)
goto alloc_asq_bufs;
hw->aq.asq.r.asq_bi = (struct i40e_dma_mem *)hw->aq.asq.dma_head.va;
for (i = 0; i < hw->aq.num_asq_entries; i++) {
bi = &hw->aq.asq.r.asq_bi[i];
ret_code = i40e_allocate_dma_mem(hw, bi,
i40e_mem_asq_buf,
hw->aq.asq_buf_size,
I40E_ADMINQ_DESC_ALIGNMENT);
if (ret_code)
goto unwind_alloc_asq_bufs;
}
alloc_asq_bufs:
return ret_code;
unwind_alloc_asq_bufs:
i--;
for (; i >= 0; i--)
i40e_free_dma_mem(hw, &hw->aq.asq.r.asq_bi[i]);
i40e_free_virt_mem(hw, &hw->aq.asq.dma_head);
return ret_code;
}
static void i40e_free_arq_bufs(struct i40e_hw *hw)
{
int i;
for (i = 0; i < hw->aq.num_arq_entries; i++)
i40e_free_dma_mem(hw, &hw->aq.arq.r.arq_bi[i]);
i40e_free_dma_mem(hw, &hw->aq.arq.desc_buf);
i40e_free_virt_mem(hw, &hw->aq.arq.dma_head);
}
static void i40e_free_asq_bufs(struct i40e_hw *hw)
{
int i;
for (i = 0; i < hw->aq.num_asq_entries; i++)
if (hw->aq.asq.r.asq_bi[i].pa)
i40e_free_dma_mem(hw, &hw->aq.asq.r.asq_bi[i]);
i40e_free_virt_mem(hw, &hw->aq.asq.cmd_buf);
i40e_free_dma_mem(hw, &hw->aq.asq.desc_buf);
i40e_free_virt_mem(hw, &hw->aq.asq.dma_head);
}
static i40e_status i40e_config_asq_regs(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
u32 reg = 0;
if (hw->mac.type == I40E_MAC_VF) {
wr32(hw, I40E_VF_ATQBAH1,
upper_32_bits(hw->aq.asq.desc_buf.pa));
wr32(hw, I40E_VF_ATQBAL1,
lower_32_bits(hw->aq.asq.desc_buf.pa));
wr32(hw, I40E_VF_ATQLEN1, (hw->aq.num_asq_entries |
I40E_VF_ATQLEN1_ATQENABLE_MASK));
reg = rd32(hw, I40E_VF_ATQBAL1);
} else {
wr32(hw, I40E_PF_ATQBAH,
upper_32_bits(hw->aq.asq.desc_buf.pa));
wr32(hw, I40E_PF_ATQBAL,
lower_32_bits(hw->aq.asq.desc_buf.pa));
wr32(hw, I40E_PF_ATQLEN, (hw->aq.num_asq_entries |
I40E_PF_ATQLEN_ATQENABLE_MASK));
reg = rd32(hw, I40E_PF_ATQBAL);
}
if (reg != lower_32_bits(hw->aq.asq.desc_buf.pa))
ret_code = I40E_ERR_ADMIN_QUEUE_ERROR;
return ret_code;
}
static i40e_status i40e_config_arq_regs(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
u32 reg = 0;
if (hw->mac.type == I40E_MAC_VF) {
wr32(hw, I40E_VF_ARQBAH1,
upper_32_bits(hw->aq.arq.desc_buf.pa));
wr32(hw, I40E_VF_ARQBAL1,
lower_32_bits(hw->aq.arq.desc_buf.pa));
wr32(hw, I40E_VF_ARQLEN1, (hw->aq.num_arq_entries |
I40E_VF_ARQLEN1_ARQENABLE_MASK));
reg = rd32(hw, I40E_VF_ARQBAL1);
} else {
wr32(hw, I40E_PF_ARQBAH,
upper_32_bits(hw->aq.arq.desc_buf.pa));
wr32(hw, I40E_PF_ARQBAL,
lower_32_bits(hw->aq.arq.desc_buf.pa));
wr32(hw, I40E_PF_ARQLEN, (hw->aq.num_arq_entries |
I40E_PF_ARQLEN_ARQENABLE_MASK));
reg = rd32(hw, I40E_PF_ARQBAL);
}
wr32(hw, hw->aq.arq.tail, hw->aq.num_arq_entries - 1);
if (reg != lower_32_bits(hw->aq.arq.desc_buf.pa))
ret_code = I40E_ERR_ADMIN_QUEUE_ERROR;
return ret_code;
}
static i40e_status i40e_init_asq(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
if (hw->aq.asq.count > 0) {
ret_code = I40E_ERR_NOT_READY;
goto init_adminq_exit;
}
if ((hw->aq.num_asq_entries == 0) ||
(hw->aq.asq_buf_size == 0)) {
ret_code = I40E_ERR_CONFIG;
goto init_adminq_exit;
}
hw->aq.asq.next_to_use = 0;
hw->aq.asq.next_to_clean = 0;
hw->aq.asq.count = hw->aq.num_asq_entries;
ret_code = i40e_alloc_adminq_asq_ring(hw);
if (ret_code)
goto init_adminq_exit;
ret_code = i40e_alloc_asq_bufs(hw);
if (ret_code)
goto init_adminq_free_rings;
ret_code = i40e_config_asq_regs(hw);
if (ret_code)
goto init_adminq_free_rings;
goto init_adminq_exit;
init_adminq_free_rings:
i40e_free_adminq_asq(hw);
init_adminq_exit:
return ret_code;
}
static i40e_status i40e_init_arq(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
if (hw->aq.arq.count > 0) {
ret_code = I40E_ERR_NOT_READY;
goto init_adminq_exit;
}
if ((hw->aq.num_arq_entries == 0) ||
(hw->aq.arq_buf_size == 0)) {
ret_code = I40E_ERR_CONFIG;
goto init_adminq_exit;
}
hw->aq.arq.next_to_use = 0;
hw->aq.arq.next_to_clean = 0;
hw->aq.arq.count = hw->aq.num_arq_entries;
ret_code = i40e_alloc_adminq_arq_ring(hw);
if (ret_code)
goto init_adminq_exit;
ret_code = i40e_alloc_arq_bufs(hw);
if (ret_code)
goto init_adminq_free_rings;
ret_code = i40e_config_arq_regs(hw);
if (ret_code)
goto init_adminq_free_rings;
goto init_adminq_exit;
init_adminq_free_rings:
i40e_free_adminq_arq(hw);
init_adminq_exit:
return ret_code;
}
static i40e_status i40e_shutdown_asq(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
if (hw->aq.asq.count == 0)
return I40E_ERR_NOT_READY;
wr32(hw, hw->aq.asq.head, 0);
wr32(hw, hw->aq.asq.tail, 0);
wr32(hw, hw->aq.asq.len, 0);
mutex_lock(&hw->aq.asq_mutex);
hw->aq.asq.count = 0;
i40e_free_asq_bufs(hw);
mutex_unlock(&hw->aq.asq_mutex);
return ret_code;
}
static i40e_status i40e_shutdown_arq(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
if (hw->aq.arq.count == 0)
return I40E_ERR_NOT_READY;
wr32(hw, hw->aq.arq.head, 0);
wr32(hw, hw->aq.arq.tail, 0);
wr32(hw, hw->aq.arq.len, 0);
mutex_lock(&hw->aq.arq_mutex);
hw->aq.arq.count = 0;
i40e_free_arq_bufs(hw);
mutex_unlock(&hw->aq.arq_mutex);
return ret_code;
}
i40e_status i40e_init_adminq(struct i40e_hw *hw)
{
i40e_status ret_code;
u16 eetrack_lo, eetrack_hi;
int retry = 0;
if ((hw->aq.num_arq_entries == 0) ||
(hw->aq.num_asq_entries == 0) ||
(hw->aq.arq_buf_size == 0) ||
(hw->aq.asq_buf_size == 0)) {
ret_code = I40E_ERR_CONFIG;
goto init_adminq_exit;
}
mutex_init(&hw->aq.asq_mutex);
mutex_init(&hw->aq.arq_mutex);
i40e_adminq_init_regs(hw);
ret_code = i40e_init_asq(hw);
if (ret_code)
goto init_adminq_destroy_locks;
ret_code = i40e_init_arq(hw);
if (ret_code)
goto init_adminq_free_asq;
do {
ret_code = i40e_aq_get_firmware_version(hw,
&hw->aq.fw_maj_ver,
&hw->aq.fw_min_ver,
&hw->aq.api_maj_ver,
&hw->aq.api_min_ver,
NULL);
if (ret_code != I40E_ERR_ADMIN_QUEUE_TIMEOUT)
break;
retry++;
msleep(100);
i40e_resume_aq(hw);
} while (retry < 10);
if (ret_code != I40E_SUCCESS)
goto init_adminq_free_arq;
i40e_read_nvm_word(hw, I40E_SR_NVM_IMAGE_VERSION, &hw->nvm.version);
i40e_read_nvm_word(hw, I40E_SR_NVM_EETRACK_LO, &eetrack_lo);
i40e_read_nvm_word(hw, I40E_SR_NVM_EETRACK_HI, &eetrack_hi);
hw->nvm.eetrack = (eetrack_hi << 16) | eetrack_lo;
if (hw->aq.api_maj_ver > I40E_FW_API_VERSION_MAJOR) {
ret_code = I40E_ERR_FIRMWARE_API_VERSION;
goto init_adminq_free_arq;
}
i40e_aq_release_resource(hw, I40E_NVM_RESOURCE_ID, 0, NULL);
hw->aq.nvm_busy = false;
ret_code = i40e_aq_set_hmc_resource_profile(hw,
I40E_HMC_PROFILE_DEFAULT,
0,
NULL);
ret_code = 0;
goto init_adminq_exit;
init_adminq_free_arq:
i40e_shutdown_arq(hw);
init_adminq_free_asq:
i40e_shutdown_asq(hw);
init_adminq_destroy_locks:
init_adminq_exit:
return ret_code;
}
i40e_status i40e_shutdown_adminq(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
if (i40e_check_asq_alive(hw))
i40e_aq_queue_shutdown(hw, true);
i40e_shutdown_asq(hw);
i40e_shutdown_arq(hw);
return ret_code;
}
static u16 i40e_clean_asq(struct i40e_hw *hw)
{
struct i40e_adminq_ring *asq = &(hw->aq.asq);
struct i40e_asq_cmd_details *details;
u16 ntc = asq->next_to_clean;
struct i40e_aq_desc desc_cb;
struct i40e_aq_desc *desc;
desc = I40E_ADMINQ_DESC(*asq, ntc);
details = I40E_ADMINQ_DETAILS(*asq, ntc);
while (rd32(hw, hw->aq.asq.head) != ntc) {
if (details->callback) {
I40E_ADMINQ_CALLBACK cb_func =
(I40E_ADMINQ_CALLBACK)details->callback;
desc_cb = *desc;
cb_func(hw, &desc_cb);
}
memset(desc, 0, sizeof(*desc));
memset(details, 0, sizeof(*details));
ntc++;
if (ntc == asq->count)
ntc = 0;
desc = I40E_ADMINQ_DESC(*asq, ntc);
details = I40E_ADMINQ_DETAILS(*asq, ntc);
}
asq->next_to_clean = ntc;
return I40E_DESC_UNUSED(asq);
}
static bool i40e_asq_done(struct i40e_hw *hw)
{
return rd32(hw, hw->aq.asq.head) == hw->aq.asq.next_to_use;
}
i40e_status i40e_asq_send_command(struct i40e_hw *hw,
struct i40e_aq_desc *desc,
void *buff,
u16 buff_size,
struct i40e_asq_cmd_details *cmd_details)
{
i40e_status status = 0;
struct i40e_dma_mem *dma_buff = NULL;
struct i40e_asq_cmd_details *details;
struct i40e_aq_desc *desc_on_ring;
bool cmd_completed = false;
u16 retval = 0;
if (hw->aq.asq.count == 0) {
i40e_debug(hw, I40E_DEBUG_AQ_MESSAGE,
"AQTX: Admin queue not initialized.\n");
status = I40E_ERR_QUEUE_EMPTY;
goto asq_send_command_exit;
}
if (i40e_is_nvm_update_op(desc) && hw->aq.nvm_busy) {
i40e_debug(hw, I40E_DEBUG_AQ_MESSAGE, "AQTX: NVM busy.\n");
status = I40E_ERR_NVM;
goto asq_send_command_exit;
}
details = I40E_ADMINQ_DETAILS(hw->aq.asq, hw->aq.asq.next_to_use);
if (cmd_details) {
*details = *cmd_details;
if (details->cookie) {
desc->cookie_high =
cpu_to_le32(upper_32_bits(details->cookie));
desc->cookie_low =
cpu_to_le32(lower_32_bits(details->cookie));
}
} else {
memset(details, 0, sizeof(struct i40e_asq_cmd_details));
}
desc->flags &= ~cpu_to_le16(details->flags_dis);
desc->flags |= cpu_to_le16(details->flags_ena);
mutex_lock(&hw->aq.asq_mutex);
if (buff_size > hw->aq.asq_buf_size) {
i40e_debug(hw,
I40E_DEBUG_AQ_MESSAGE,
"AQTX: Invalid buffer size: %d.\n",
buff_size);
status = I40E_ERR_INVALID_SIZE;
goto asq_send_command_error;
}
if (details->postpone && !details->async) {
i40e_debug(hw,
I40E_DEBUG_AQ_MESSAGE,
"AQTX: Async flag not set along with postpone flag");
status = I40E_ERR_PARAM;
goto asq_send_command_error;
}
if (i40e_clean_asq(hw) == 0) {
i40e_debug(hw,
I40E_DEBUG_AQ_MESSAGE,
"AQTX: Error queue is full.\n");
status = I40E_ERR_ADMIN_QUEUE_FULL;
goto asq_send_command_error;
}
desc_on_ring = I40E_ADMINQ_DESC(hw->aq.asq, hw->aq.asq.next_to_use);
*desc_on_ring = *desc;
if (buff != NULL) {
dma_buff = &(hw->aq.asq.r.asq_bi[hw->aq.asq.next_to_use]);
memcpy(dma_buff->va, buff, buff_size);
desc_on_ring->datalen = cpu_to_le16(buff_size);
desc_on_ring->params.external.addr_high =
cpu_to_le32(upper_32_bits(dma_buff->pa));
desc_on_ring->params.external.addr_low =
cpu_to_le32(lower_32_bits(dma_buff->pa));
}
i40e_debug_aq(hw, I40E_DEBUG_AQ_COMMAND, (void *)desc_on_ring, buff);
(hw->aq.asq.next_to_use)++;
if (hw->aq.asq.next_to_use == hw->aq.asq.count)
hw->aq.asq.next_to_use = 0;
if (!details->postpone)
wr32(hw, hw->aq.asq.tail, hw->aq.asq.next_to_use);
if (!details->async && !details->postpone) {
u32 total_delay = 0;
u32 delay_len = 10;
do {
if (i40e_asq_done(hw))
break;
udelay(delay_len);
total_delay += delay_len;
} while (total_delay < I40E_ASQ_CMD_TIMEOUT);
}
if (i40e_asq_done(hw)) {
*desc = *desc_on_ring;
if (buff != NULL)
memcpy(buff, dma_buff->va, buff_size);
retval = le16_to_cpu(desc->retval);
if (retval != 0) {
i40e_debug(hw,
I40E_DEBUG_AQ_MESSAGE,
"AQTX: Command completed with error 0x%X.\n",
retval);
retval &= 0xff;
}
cmd_completed = true;
if ((enum i40e_admin_queue_err)retval == I40E_AQ_RC_OK)
status = 0;
else
status = I40E_ERR_ADMIN_QUEUE_ERROR;
hw->aq.asq_last_status = (enum i40e_admin_queue_err)retval;
}
if (i40e_is_nvm_update_op(desc))
hw->aq.nvm_busy = true;
if ((!cmd_completed) &&
(!details->async && !details->postpone)) {
i40e_debug(hw,
I40E_DEBUG_AQ_MESSAGE,
"AQTX: Writeback timeout.\n");
status = I40E_ERR_ADMIN_QUEUE_TIMEOUT;
}
asq_send_command_error:
mutex_unlock(&hw->aq.asq_mutex);
asq_send_command_exit:
return status;
}
void i40e_fill_default_direct_cmd_desc(struct i40e_aq_desc *desc,
u16 opcode)
{
memset((void *)desc, 0, sizeof(struct i40e_aq_desc));
desc->opcode = cpu_to_le16(opcode);
desc->flags = cpu_to_le16(I40E_AQ_FLAG_SI);
}
i40e_status i40e_clean_arq_element(struct i40e_hw *hw,
struct i40e_arq_event_info *e,
u16 *pending)
{
i40e_status ret_code = 0;
u16 ntc = hw->aq.arq.next_to_clean;
struct i40e_aq_desc *desc;
struct i40e_dma_mem *bi;
u16 desc_idx;
u16 datalen;
u16 flags;
u16 ntu;
mutex_lock(&hw->aq.arq_mutex);
ntu = (rd32(hw, hw->aq.arq.head) & I40E_PF_ARQH_ARQH_MASK);
if (ntu == ntc) {
i40e_debug(hw,
I40E_DEBUG_AQ_MESSAGE,
"AQRX: Queue is empty.\n");
ret_code = I40E_ERR_ADMIN_QUEUE_NO_WORK;
goto clean_arq_element_out;
}
desc = I40E_ADMINQ_DESC(hw->aq.arq, ntc);
desc_idx = ntc;
i40e_debug_aq(hw,
I40E_DEBUG_AQ_COMMAND,
(void *)desc,
hw->aq.arq.r.arq_bi[desc_idx].va);
flags = le16_to_cpu(desc->flags);
if (flags & I40E_AQ_FLAG_ERR) {
ret_code = I40E_ERR_ADMIN_QUEUE_ERROR;
hw->aq.arq_last_status =
(enum i40e_admin_queue_err)le16_to_cpu(desc->retval);
i40e_debug(hw,
I40E_DEBUG_AQ_MESSAGE,
"AQRX: Event received with error 0x%X.\n",
hw->aq.arq_last_status);
} else {
e->desc = *desc;
datalen = le16_to_cpu(desc->datalen);
e->msg_size = min(datalen, e->msg_size);
if (e->msg_buf != NULL && (e->msg_size != 0))
memcpy(e->msg_buf, hw->aq.arq.r.arq_bi[desc_idx].va,
e->msg_size);
}
if (i40e_is_nvm_update_op(&e->desc))
hw->aq.nvm_busy = false;
bi = &hw->aq.arq.r.arq_bi[ntc];
memset((void *)desc, 0, sizeof(struct i40e_aq_desc));
desc->flags = cpu_to_le16(I40E_AQ_FLAG_BUF);
if (hw->aq.arq_buf_size > I40E_AQ_LARGE_BUF)
desc->flags |= cpu_to_le16(I40E_AQ_FLAG_LB);
desc->datalen = cpu_to_le16((u16)bi->size);
desc->params.external.addr_high = cpu_to_le32(upper_32_bits(bi->pa));
desc->params.external.addr_low = cpu_to_le32(lower_32_bits(bi->pa));
wr32(hw, hw->aq.arq.tail, ntc);
ntc++;
if (ntc == hw->aq.num_arq_entries)
ntc = 0;
hw->aq.arq.next_to_clean = ntc;
hw->aq.arq.next_to_use = ntu;
clean_arq_element_out:
if (pending != NULL)
*pending = (ntc > ntu ? hw->aq.arq.count : 0) + (ntu - ntc);
mutex_unlock(&hw->aq.arq_mutex);
return ret_code;
}
static void i40e_resume_aq(struct i40e_hw *hw)
{
hw->aq.asq.next_to_use = 0;
hw->aq.asq.next_to_clean = 0;
i40e_config_asq_regs(hw);
hw->aq.arq.next_to_use = 0;
hw->aq.arq.next_to_clean = 0;
i40e_config_arq_regs(hw);
}
