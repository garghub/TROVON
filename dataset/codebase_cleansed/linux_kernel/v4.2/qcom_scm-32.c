static struct qcom_scm_command *alloc_qcom_scm_command(size_t cmd_size, size_t resp_size)
{
struct qcom_scm_command *cmd;
size_t len = sizeof(*cmd) + sizeof(struct qcom_scm_response) + cmd_size +
resp_size;
u32 offset;
cmd = kzalloc(PAGE_ALIGN(len), GFP_KERNEL);
if (cmd) {
cmd->len = cpu_to_le32(len);
offset = offsetof(struct qcom_scm_command, buf);
cmd->buf_offset = cpu_to_le32(offset);
cmd->resp_hdr_offset = cpu_to_le32(offset + cmd_size);
}
return cmd;
}
static inline void free_qcom_scm_command(struct qcom_scm_command *cmd)
{
kfree(cmd);
}
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
static int qcom_scm_remap_error(int err)
{
pr_err("qcom_scm_call failed with error code %d\n", err);
switch (err) {
case QCOM_SCM_ERROR:
return -EIO;
case QCOM_SCM_EINVAL_ADDR:
case QCOM_SCM_EINVAL_ARG:
return -EINVAL;
case QCOM_SCM_EOPNOTSUPP:
return -EOPNOTSUPP;
case QCOM_SCM_ENOMEM:
return -ENOMEM;
}
return -EINVAL;
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
static int __qcom_scm_call(const struct qcom_scm_command *cmd)
{
int ret;
u32 cmd_addr = virt_to_phys(cmd);
__cpuc_flush_dcache_area((void *)cmd, cmd->len);
outer_flush_range(cmd_addr, cmd_addr + cmd->len);
ret = smc(cmd_addr);
if (ret < 0)
ret = qcom_scm_remap_error(ret);
return ret;
}
static void qcom_scm_inv_range(unsigned long start, unsigned long end)
{
u32 cacheline_size, ctr;
asm volatile("mrc p15, 0, %0, c0, c0, 1" : "=r" (ctr));
cacheline_size = 4 << ((ctr >> 16) & 0xf);
start = round_down(start, cacheline_size);
end = round_up(end, cacheline_size);
outer_inv_range(start, end);
while (start < end) {
asm ("mcr p15, 0, %0, c7, c6, 1" : : "r" (start)
: "memory");
start += cacheline_size;
}
dsb();
isb();
}
static int qcom_scm_call(u32 svc_id, u32 cmd_id, const void *cmd_buf,
size_t cmd_len, void *resp_buf, size_t resp_len)
{
int ret;
struct qcom_scm_command *cmd;
struct qcom_scm_response *rsp;
unsigned long start, end;
cmd = alloc_qcom_scm_command(cmd_len, resp_len);
if (!cmd)
return -ENOMEM;
cmd->id = cpu_to_le32((svc_id << 10) | cmd_id);
if (cmd_buf)
memcpy(qcom_scm_get_command_buffer(cmd), cmd_buf, cmd_len);
mutex_lock(&qcom_scm_lock);
ret = __qcom_scm_call(cmd);
mutex_unlock(&qcom_scm_lock);
if (ret)
goto out;
rsp = qcom_scm_command_to_response(cmd);
start = (unsigned long)rsp;
do {
qcom_scm_inv_range(start, start + sizeof(*rsp));
} while (!rsp->is_complete);
end = (unsigned long)qcom_scm_get_response_buffer(rsp) + resp_len;
qcom_scm_inv_range(start, end);
if (resp_buf)
memcpy(resp_buf, qcom_scm_get_response_buffer(rsp), resp_len);
out:
free_qcom_scm_command(cmd);
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
static int qcom_scm_set_boot_addr(u32 addr, int flags)
{
struct {
__le32 flags;
__le32 addr;
} cmd;
cmd.addr = cpu_to_le32(addr);
cmd.flags = cpu_to_le32(flags);
return qcom_scm_call(QCOM_SCM_SVC_BOOT, QCOM_SCM_BOOT_ADDR,
&cmd, sizeof(cmd), NULL, 0);
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
return qcom_scm_set_boot_addr(virt_to_phys(entry), flags);
}
int __qcom_scm_set_warm_boot_addr(void *entry, const cpumask_t *cpus)
{
int ret;
int flags = 0;
int cpu;
for_each_cpu(cpu, cpus) {
if (entry == qcom_scm_wb[cpu].entry)
continue;
flags |= qcom_scm_wb[cpu].flag;
}
if (!flags)
return 0;
ret = qcom_scm_set_boot_addr(virt_to_phys(entry), flags);
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
int __qcom_scm_is_call_available(u32 svc_id, u32 cmd_id)
{
int ret;
u32 svc_cmd = (svc_id << 10) | cmd_id;
u32 ret_val = 0;
ret = qcom_scm_call(QCOM_SCM_SVC_INFO, QCOM_IS_CALL_AVAIL_CMD, &svc_cmd,
sizeof(svc_cmd), &ret_val, sizeof(ret_val));
if (ret)
return ret;
return ret_val;
}
int __qcom_scm_hdcp_req(struct qcom_scm_hdcp_req *req, u32 req_cnt, u32 *resp)
{
if (req_cnt > QCOM_SCM_HDCP_MAX_REQ_CNT)
return -ERANGE;
return qcom_scm_call(QCOM_SCM_SVC_HDCP, QCOM_SCM_CMD_HDCP,
req, req_cnt * sizeof(*req), resp, sizeof(*resp));
}
