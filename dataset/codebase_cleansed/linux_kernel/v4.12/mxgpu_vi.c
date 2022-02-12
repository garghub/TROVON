void xgpu_vi_init_golden_registers(struct amdgpu_device *adev)
{
switch (adev->asic_type) {
case CHIP_FIJI:
amdgpu_program_register_sequence(adev,
xgpu_fiji_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(
xgpu_fiji_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
xgpu_fiji_golden_settings_a10,
(const u32)ARRAY_SIZE(
xgpu_fiji_golden_settings_a10));
amdgpu_program_register_sequence(adev,
xgpu_fiji_golden_common_all,
(const u32)ARRAY_SIZE(
xgpu_fiji_golden_common_all));
break;
case CHIP_TONGA:
amdgpu_program_register_sequence(adev,
xgpu_tonga_mgcg_cgcg_init,
(const u32)ARRAY_SIZE(
xgpu_tonga_mgcg_cgcg_init));
amdgpu_program_register_sequence(adev,
xgpu_tonga_golden_settings_a11,
(const u32)ARRAY_SIZE(
xgpu_tonga_golden_settings_a11));
amdgpu_program_register_sequence(adev,
xgpu_tonga_golden_common_all,
(const u32)ARRAY_SIZE(
xgpu_tonga_golden_common_all));
break;
default:
BUG_ON("Doesn't support chip type.\n");
break;
}
}
static void xgpu_vi_mailbox_send_ack(struct amdgpu_device *adev)
{
u32 reg;
int timeout = VI_MAILBOX_TIMEDOUT;
u32 mask = REG_FIELD_MASK(MAILBOX_CONTROL, RCV_MSG_VALID);
reg = RREG32_NO_KIQ(mmMAILBOX_CONTROL);
reg = REG_SET_FIELD(reg, MAILBOX_CONTROL, RCV_MSG_ACK, 1);
WREG32_NO_KIQ(mmMAILBOX_CONTROL, reg);
reg = RREG32_NO_KIQ(mmMAILBOX_CONTROL);
while (reg & mask) {
if (timeout <= 0) {
pr_err("RCV_MSG_VALID is not cleared\n");
break;
}
mdelay(1);
timeout -=1;
reg = RREG32_NO_KIQ(mmMAILBOX_CONTROL);
}
}
static void xgpu_vi_mailbox_set_valid(struct amdgpu_device *adev, bool val)
{
u32 reg;
reg = RREG32_NO_KIQ(mmMAILBOX_CONTROL);
reg = REG_SET_FIELD(reg, MAILBOX_CONTROL,
TRN_MSG_VALID, val ? 1 : 0);
WREG32_NO_KIQ(mmMAILBOX_CONTROL, reg);
}
static void xgpu_vi_mailbox_trans_msg(struct amdgpu_device *adev,
enum idh_request req)
{
u32 reg;
reg = RREG32_NO_KIQ(mmMAILBOX_MSGBUF_TRN_DW0);
reg = REG_SET_FIELD(reg, MAILBOX_MSGBUF_TRN_DW0,
MSGBUF_DATA, req);
WREG32_NO_KIQ(mmMAILBOX_MSGBUF_TRN_DW0, reg);
xgpu_vi_mailbox_set_valid(adev, true);
}
static int xgpu_vi_mailbox_rcv_msg(struct amdgpu_device *adev,
enum idh_event event)
{
u32 reg;
u32 mask = REG_FIELD_MASK(MAILBOX_CONTROL, RCV_MSG_VALID);
if (event != IDH_FLR_NOTIFICATION_CMPL) {
reg = RREG32_NO_KIQ(mmMAILBOX_CONTROL);
if (!(reg & mask))
return -ENOENT;
}
reg = RREG32_NO_KIQ(mmMAILBOX_MSGBUF_RCV_DW0);
if (reg != event)
return -ENOENT;
xgpu_vi_mailbox_send_ack(adev);
return 0;
}
static int xgpu_vi_poll_ack(struct amdgpu_device *adev)
{
int r = 0, timeout = VI_MAILBOX_TIMEDOUT;
u32 mask = REG_FIELD_MASK(MAILBOX_CONTROL, TRN_MSG_ACK);
u32 reg;
reg = RREG32_NO_KIQ(mmMAILBOX_CONTROL);
while (!(reg & mask)) {
if (timeout <= 0) {
pr_err("Doesn't get ack from pf.\n");
r = -ETIME;
break;
}
msleep(1);
timeout -= 1;
reg = RREG32_NO_KIQ(mmMAILBOX_CONTROL);
}
return r;
}
static int xgpu_vi_poll_msg(struct amdgpu_device *adev, enum idh_event event)
{
int r = 0, timeout = VI_MAILBOX_TIMEDOUT;
r = xgpu_vi_mailbox_rcv_msg(adev, event);
while (r) {
if (timeout <= 0) {
pr_err("Doesn't get ack from pf.\n");
r = -ETIME;
break;
}
msleep(1);
timeout -= 1;
r = xgpu_vi_mailbox_rcv_msg(adev, event);
}
return r;
}
static int xgpu_vi_send_access_requests(struct amdgpu_device *adev,
enum idh_request request)
{
int r;
xgpu_vi_mailbox_trans_msg(adev, request);
r = xgpu_vi_poll_ack(adev);
if (r)
return r;
xgpu_vi_mailbox_set_valid(adev, false);
if (request == IDH_REQ_GPU_INIT_ACCESS ||
request == IDH_REQ_GPU_FINI_ACCESS ||
request == IDH_REQ_GPU_RESET_ACCESS) {
r = xgpu_vi_poll_msg(adev, IDH_READY_TO_ACCESS_GPU);
if (r)
return r;
}
return 0;
}
static int xgpu_vi_request_reset(struct amdgpu_device *adev)
{
return xgpu_vi_send_access_requests(adev, IDH_REQ_GPU_RESET_ACCESS);
}
static int xgpu_vi_request_full_gpu_access(struct amdgpu_device *adev,
bool init)
{
enum idh_request req;
req = init ? IDH_REQ_GPU_INIT_ACCESS : IDH_REQ_GPU_FINI_ACCESS;
return xgpu_vi_send_access_requests(adev, req);
}
static int xgpu_vi_release_full_gpu_access(struct amdgpu_device *adev,
bool init)
{
enum idh_request req;
int r = 0;
req = init ? IDH_REL_GPU_INIT_ACCESS : IDH_REL_GPU_FINI_ACCESS;
r = xgpu_vi_send_access_requests(adev, req);
return r;
}
static int xgpu_vi_mailbox_ack_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
DRM_DEBUG("get ack intr and do nothing.\n");
return 0;
}
static int xgpu_vi_set_mailbox_ack_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned type,
enum amdgpu_interrupt_state state)
{
u32 tmp = RREG32_NO_KIQ(mmMAILBOX_INT_CNTL);
tmp = REG_SET_FIELD(tmp, MAILBOX_INT_CNTL, ACK_INT_EN,
(state == AMDGPU_IRQ_STATE_ENABLE) ? 1 : 0);
WREG32_NO_KIQ(mmMAILBOX_INT_CNTL, tmp);
return 0;
}
static void xgpu_vi_mailbox_flr_work(struct work_struct *work)
{
struct amdgpu_virt *virt = container_of(work, struct amdgpu_virt, flr_work);
struct amdgpu_device *adev = container_of(virt, struct amdgpu_device, virt);
if (xgpu_vi_poll_msg(adev, IDH_FLR_NOTIFICATION_CMPL)) {
pr_err("failed to recieve FLR_CMPL\n");
return;
}
amdgpu_sriov_gpu_reset(adev, false);
}
static int xgpu_vi_set_mailbox_rcv_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *src,
unsigned type,
enum amdgpu_interrupt_state state)
{
u32 tmp = RREG32_NO_KIQ(mmMAILBOX_INT_CNTL);
tmp = REG_SET_FIELD(tmp, MAILBOX_INT_CNTL, VALID_INT_EN,
(state == AMDGPU_IRQ_STATE_ENABLE) ? 1 : 0);
WREG32_NO_KIQ(mmMAILBOX_INT_CNTL, tmp);
return 0;
}
static int xgpu_vi_mailbox_rcv_irq(struct amdgpu_device *adev,
struct amdgpu_irq_src *source,
struct amdgpu_iv_entry *entry)
{
int r;
r = xgpu_vi_mailbox_rcv_msg(adev, IDH_FLR_NOTIFICATION);
if (!r)
schedule_work(&adev->virt.flr_work);
return 0;
}
void xgpu_vi_mailbox_set_irq_funcs(struct amdgpu_device *adev)
{
adev->virt.ack_irq.num_types = 1;
adev->virt.ack_irq.funcs = &xgpu_vi_mailbox_ack_irq_funcs;
adev->virt.rcv_irq.num_types = 1;
adev->virt.rcv_irq.funcs = &xgpu_vi_mailbox_rcv_irq_funcs;
}
int xgpu_vi_mailbox_add_irq_id(struct amdgpu_device *adev)
{
int r;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_LEGACY, 135, &adev->virt.rcv_irq);
if (r)
return r;
r = amdgpu_irq_add_id(adev, AMDGPU_IH_CLIENTID_LEGACY, 138, &adev->virt.ack_irq);
if (r) {
amdgpu_irq_put(adev, &adev->virt.rcv_irq, 0);
return r;
}
return 0;
}
int xgpu_vi_mailbox_get_irq(struct amdgpu_device *adev)
{
int r;
r = amdgpu_irq_get(adev, &adev->virt.rcv_irq, 0);
if (r)
return r;
r = amdgpu_irq_get(adev, &adev->virt.ack_irq, 0);
if (r) {
amdgpu_irq_put(adev, &adev->virt.rcv_irq, 0);
return r;
}
INIT_WORK(&adev->virt.flr_work, xgpu_vi_mailbox_flr_work);
return 0;
}
void xgpu_vi_mailbox_put_irq(struct amdgpu_device *adev)
{
amdgpu_irq_put(adev, &adev->virt.ack_irq, 0);
amdgpu_irq_put(adev, &adev->virt.rcv_irq, 0);
}
