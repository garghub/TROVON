static inline struct qcom_scm_response *qcom_scm_command_to_response(
const struct qcom_scm_command *cmd)
{
return (void *)cmd + le32_to_cpu(cmd->resp_hdr_offset);
}
static inline void *qcom_scm_get_command_buffer(const struct qcom_scm_command *cmd)
{
return (void *)cmd->buf;
}
static inline void *qcom_scm_get_response_buffer(const struct qcom_scm_response *rsp)
{
return (void *)rsp + le32_to_cpu(rsp->buf_offset);
}
static u32 smc(u32 cmd_addr)
{
int context_id;
register u32 r0 asm("r0") = 1;
register u32 r1 asm("r1") = (u32)&context_id;
register u32 r2 asm("r2") = cmd_addr;
do {
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r0")
__asmeq("%2", "r1")
__asmeq("%3", "r2")
#ifdef REQUIRES_SEC
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0)
: "r" (r0), "r" (r1), "r" (r2)
: "r3");
} while (r0 == QCOM_SCM_INTERRUPTED);
return r0;
}
static int qcom_scm_call(struct device *dev, u32 svc_id, u32 cmd_id,
const void *cmd_buf, size_t cmd_len, void *resp_buf,
size_t resp_len)
{
int ret;
struct qcom_scm_command *cmd;
struct qcom_scm_response *rsp;
size_t alloc_len = sizeof(*cmd) + cmd_len + sizeof(*rsp) + resp_len;
dma_addr_t cmd_phys;
cmd = kzalloc(PAGE_ALIGN(alloc_len), GFP_KERNEL);
if (!cmd)
return -ENOMEM;
cmd->len = cpu_to_le32(alloc_len);
cmd->buf_offset = cpu_to_le32(sizeof(*cmd));
cmd->resp_hdr_offset = cpu_to_le32(sizeof(*cmd) + cmd_len);
cmd->id = cpu_to_le32((svc_id << 10) | cmd_id);
if (cmd_buf)
memcpy(qcom_scm_get_command_buffer(cmd), cmd_buf, cmd_len);
rsp = qcom_scm_command_to_response(cmd);
cmd_phys = dma_map_single(dev, cmd, alloc_len, DMA_TO_DEVICE);
if (dma_mapping_error(dev, cmd_phys)) {
kfree(cmd);
return -ENOMEM;
}
mutex_lock(&qcom_scm_lock);
ret = smc(cmd_phys);
if (ret < 0)
ret = qcom_scm_remap_error(ret);
mutex_unlock(&qcom_scm_lock);
if (ret)
goto out;
do {
dma_sync_single_for_cpu(dev, cmd_phys + sizeof(*cmd) + cmd_len,
sizeof(*rsp), DMA_FROM_DEVICE);
} while (!rsp->is_complete);
if (resp_buf) {
dma_sync_single_for_cpu(dev, cmd_phys + sizeof(*cmd) + cmd_len +
le32_to_cpu(rsp->buf_offset),
resp_len, DMA_FROM_DEVICE);
memcpy(resp_buf, qcom_scm_get_response_buffer(rsp),
resp_len);
}
out:
dma_unmap_single(dev, cmd_phys, alloc_len, DMA_TO_DEVICE);
kfree(cmd);
return ret;
}
static s32 qcom_scm_call_atomic1(u32 svc, u32 cmd, u32 arg1)
{
int context_id;
register u32 r0 asm("r0") = SCM_ATOMIC(svc, cmd, 1);
register u32 r1 asm("r1") = (u32)&context_id;
register u32 r2 asm("r2") = arg1;
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r0")
__asmeq("%2", "r1")
__asmeq("%3", "r2")
#ifdef REQUIRES_SEC
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0)
: "r" (r0), "r" (r1), "r" (r2)
: "r3");
return r0;
}
static s32 qcom_scm_call_atomic2(u32 svc, u32 cmd, u32 arg1, u32 arg2)
{
int context_id;
register u32 r0 asm("r0") = SCM_ATOMIC(svc, cmd, 2);
register u32 r1 asm("r1") = (u32)&context_id;
register u32 r2 asm("r2") = arg1;
register u32 r3 asm("r3") = arg2;
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r0")
__asmeq("%2", "r1")
__asmeq("%3", "r2")
__asmeq("%4", "r3")
#ifdef REQUIRES_SEC
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0)
: "r" (r0), "r" (r1), "r" (r2), "r" (r3)
);
return r0;
}
u32 qcom_scm_get_version(void)
{
int context_id;
static u32 version = -1;
register u32 r0 asm("r0");
register u32 r1 asm("r1");
if (version != -1)
return version;
mutex_lock(&qcom_scm_lock);
r0 = 0x1 << 8;
r1 = (u32)&context_id;
do {
asm volatile(
__asmeq("%0", "r0")
__asmeq("%1", "r1")
__asmeq("%2", "r0")
__asmeq("%3", "r1")
#ifdef REQUIRES_SEC
".arch_extension sec\n"
#endif
"smc #0 @ switch to secure world\n"
: "=r" (r0), "=r" (r1)
: "r" (r0), "r" (r1)
: "r2", "r3");
} while (r0 == QCOM_SCM_INTERRUPTED);
version = r1;
mutex_unlock(&qcom_scm_lock);
return version;
}
int __qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus)
{
int flags = 0;
int cpu;
int scm_cb_flags[] = {
QCOM_SCM_FLAG_COLDBOOT_CPU0,
QCOM_SCM_FLAG_COLDBOOT_CPU1,
QCOM_SCM_FLAG_COLDBOOT_CPU2,
QCOM_SCM_FLAG_COLDBOOT_CPU3,
};
if (!cpus || (cpus && cpumask_empty(cpus)))
return -EINVAL;
for_each_cpu(cpu, cpus) {
if (cpu < ARRAY_SIZE(scm_cb_flags))
flags |= scm_cb_flags[cpu];
else
set_cpu_present(cpu, false);
}
return qcom_scm_call_atomic2(QCOM_SCM_SVC_BOOT, QCOM_SCM_BOOT_ADDR,
flags, virt_to_phys(entry));
}
int __qcom_scm_set_warm_boot_addr(struct device *dev, void *entry,
const cpumask_t *cpus)
{
int ret;
int flags = 0;
int cpu;
struct {
__le32 flags;
__le32 addr;
} cmd;
for_each_cpu(cpu, cpus) {
if (entry == qcom_scm_wb[cpu].entry)
continue;
flags |= qcom_scm_wb[cpu].flag;
}
if (!flags)
return 0;
cmd.addr = cpu_to_le32(virt_to_phys(entry));
cmd.flags = cpu_to_le32(flags);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_BOOT, QCOM_SCM_BOOT_ADDR,
&cmd, sizeof(cmd), NULL, 0);
if (!ret) {
for_each_cpu(cpu, cpus)
qcom_scm_wb[cpu].entry = entry;
}
return ret;
}
void __qcom_scm_cpu_power_down(u32 flags)
{
qcom_scm_call_atomic1(QCOM_SCM_SVC_BOOT, QCOM_SCM_CMD_TERMINATE_PC,
flags & QCOM_SCM_FLUSH_FLAG_MASK);
}
int __qcom_scm_is_call_available(struct device *dev, u32 svc_id, u32 cmd_id)
{
int ret;
__le32 svc_cmd = cpu_to_le32((svc_id << 10) | cmd_id);
__le32 ret_val = 0;
ret = qcom_scm_call(dev, QCOM_SCM_SVC_INFO, QCOM_IS_CALL_AVAIL_CMD,
&svc_cmd, sizeof(svc_cmd), &ret_val,
sizeof(ret_val));
if (ret)
return ret;
return le32_to_cpu(ret_val);
}
int __qcom_scm_hdcp_req(struct device *dev, struct qcom_scm_hdcp_req *req,
u32 req_cnt, u32 *resp)
{
if (req_cnt > QCOM_SCM_HDCP_MAX_REQ_CNT)
return -ERANGE;
return qcom_scm_call(dev, QCOM_SCM_SVC_HDCP, QCOM_SCM_CMD_HDCP,
req, req_cnt * sizeof(*req), resp, sizeof(*resp));
}
void __qcom_scm_init(void)
{
}
bool __qcom_scm_pas_supported(struct device *dev, u32 peripheral)
{
__le32 out;
__le32 in;
int ret;
in = cpu_to_le32(peripheral);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL,
QCOM_SCM_PAS_IS_SUPPORTED_CMD,
&in, sizeof(in),
&out, sizeof(out));
return ret ? false : !!out;
}
int __qcom_scm_pas_init_image(struct device *dev, u32 peripheral,
dma_addr_t metadata_phys)
{
__le32 scm_ret;
int ret;
struct {
__le32 proc;
__le32 image_addr;
} request;
request.proc = cpu_to_le32(peripheral);
request.image_addr = cpu_to_le32(metadata_phys);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL,
QCOM_SCM_PAS_INIT_IMAGE_CMD,
&request, sizeof(request),
&scm_ret, sizeof(scm_ret));
return ret ? : le32_to_cpu(scm_ret);
}
int __qcom_scm_pas_mem_setup(struct device *dev, u32 peripheral,
phys_addr_t addr, phys_addr_t size)
{
__le32 scm_ret;
int ret;
struct {
__le32 proc;
__le32 addr;
__le32 len;
} request;
request.proc = cpu_to_le32(peripheral);
request.addr = cpu_to_le32(addr);
request.len = cpu_to_le32(size);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL,
QCOM_SCM_PAS_MEM_SETUP_CMD,
&request, sizeof(request),
&scm_ret, sizeof(scm_ret));
return ret ? : le32_to_cpu(scm_ret);
}
int __qcom_scm_pas_auth_and_reset(struct device *dev, u32 peripheral)
{
__le32 out;
__le32 in;
int ret;
in = cpu_to_le32(peripheral);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL,
QCOM_SCM_PAS_AUTH_AND_RESET_CMD,
&in, sizeof(in),
&out, sizeof(out));
return ret ? : le32_to_cpu(out);
}
int __qcom_scm_pas_shutdown(struct device *dev, u32 peripheral)
{
__le32 out;
__le32 in;
int ret;
in = cpu_to_le32(peripheral);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL,
QCOM_SCM_PAS_SHUTDOWN_CMD,
&in, sizeof(in),
&out, sizeof(out));
return ret ? : le32_to_cpu(out);
}
int __qcom_scm_pas_mss_reset(struct device *dev, bool reset)
{
__le32 out;
__le32 in = cpu_to_le32(reset);
int ret;
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL, QCOM_SCM_PAS_MSS_RESET,
&in, sizeof(in),
&out, sizeof(out));
return ret ? : le32_to_cpu(out);
}
int __qcom_scm_set_remote_state(struct device *dev, u32 state, u32 id)
{
struct {
__le32 state;
__le32 id;
} req;
__le32 scm_ret = 0;
int ret;
req.state = cpu_to_le32(state);
req.id = cpu_to_le32(id);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_BOOT, QCOM_SCM_SET_REMOTE_STATE,
&req, sizeof(req), &scm_ret, sizeof(scm_ret));
return ret ? : le32_to_cpu(scm_ret);
}
