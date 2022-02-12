int __must_check fsl_create_mc_io(struct device *dev,
phys_addr_t mc_portal_phys_addr,
u32 mc_portal_size,
struct fsl_mc_device *dpmcp_dev,
u32 flags, struct fsl_mc_io **new_mc_io)
{
int error;
struct fsl_mc_io *mc_io;
void __iomem *mc_portal_virt_addr;
struct resource *res;
mc_io = devm_kzalloc(dev, sizeof(*mc_io), GFP_KERNEL);
if (!mc_io)
return -ENOMEM;
mc_io->dev = dev;
mc_io->flags = flags;
mc_io->portal_phys_addr = mc_portal_phys_addr;
mc_io->portal_size = mc_portal_size;
if (flags & FSL_MC_IO_ATOMIC_CONTEXT_PORTAL)
spin_lock_init(&mc_io->spinlock);
else
mutex_init(&mc_io->mutex);
res = devm_request_mem_region(dev,
mc_portal_phys_addr,
mc_portal_size,
"mc_portal");
if (!res) {
dev_err(dev,
"devm_request_mem_region failed for MC portal %#llx\n",
mc_portal_phys_addr);
return -EBUSY;
}
mc_portal_virt_addr = devm_ioremap_nocache(dev,
mc_portal_phys_addr,
mc_portal_size);
if (!mc_portal_virt_addr) {
dev_err(dev,
"devm_ioremap_nocache failed for MC portal %#llx\n",
mc_portal_phys_addr);
return -ENXIO;
}
mc_io->portal_virt_addr = mc_portal_virt_addr;
if (dpmcp_dev) {
error = fsl_mc_io_set_dpmcp(mc_io, dpmcp_dev);
if (error < 0)
goto error_destroy_mc_io;
}
*new_mc_io = mc_io;
return 0;
error_destroy_mc_io:
fsl_destroy_mc_io(mc_io);
return error;
}
void fsl_destroy_mc_io(struct fsl_mc_io *mc_io)
{
struct fsl_mc_device *dpmcp_dev = mc_io->dpmcp_dev;
if (dpmcp_dev)
fsl_mc_io_unset_dpmcp(mc_io);
devm_iounmap(mc_io->dev, mc_io->portal_virt_addr);
devm_release_mem_region(mc_io->dev,
mc_io->portal_phys_addr,
mc_io->portal_size);
mc_io->portal_virt_addr = NULL;
devm_kfree(mc_io->dev, mc_io);
}
int fsl_mc_io_set_dpmcp(struct fsl_mc_io *mc_io,
struct fsl_mc_device *dpmcp_dev)
{
int error;
if (WARN_ON(!dpmcp_dev))
return -EINVAL;
if (WARN_ON(mc_io->dpmcp_dev))
return -EINVAL;
if (WARN_ON(dpmcp_dev->mc_io))
return -EINVAL;
error = dpmcp_open(mc_io,
0,
dpmcp_dev->obj_desc.id,
&dpmcp_dev->mc_handle);
if (error < 0)
return error;
mc_io->dpmcp_dev = dpmcp_dev;
dpmcp_dev->mc_io = mc_io;
return 0;
}
void fsl_mc_io_unset_dpmcp(struct fsl_mc_io *mc_io)
{
int error;
struct fsl_mc_device *dpmcp_dev = mc_io->dpmcp_dev;
if (WARN_ON(!dpmcp_dev))
return;
if (WARN_ON(dpmcp_dev->mc_io != mc_io))
return;
error = dpmcp_close(mc_io,
0,
dpmcp_dev->mc_handle);
if (error < 0) {
dev_err(&dpmcp_dev->dev, "dpmcp_close() failed: %d\n",
error);
}
mc_io->dpmcp_dev = NULL;
dpmcp_dev->mc_io = NULL;
}
static int mc_status_to_error(enum mc_cmd_status status)
{
static const int mc_status_to_error_map[] = {
[MC_CMD_STATUS_OK] = 0,
[MC_CMD_STATUS_AUTH_ERR] = -EACCES,
[MC_CMD_STATUS_NO_PRIVILEGE] = -EPERM,
[MC_CMD_STATUS_DMA_ERR] = -EIO,
[MC_CMD_STATUS_CONFIG_ERR] = -ENXIO,
[MC_CMD_STATUS_TIMEOUT] = -ETIMEDOUT,
[MC_CMD_STATUS_NO_RESOURCE] = -ENAVAIL,
[MC_CMD_STATUS_NO_MEMORY] = -ENOMEM,
[MC_CMD_STATUS_BUSY] = -EBUSY,
[MC_CMD_STATUS_UNSUPPORTED_OP] = -ENOTSUPP,
[MC_CMD_STATUS_INVALID_STATE] = -ENODEV,
};
if (WARN_ON((u32)status >= ARRAY_SIZE(mc_status_to_error_map)))
return -EINVAL;
return mc_status_to_error_map[status];
}
static const char *mc_status_to_string(enum mc_cmd_status status)
{
static const char *const status_strings[] = {
[MC_CMD_STATUS_OK] = "Command completed successfully",
[MC_CMD_STATUS_READY] = "Command ready to be processed",
[MC_CMD_STATUS_AUTH_ERR] = "Authentication error",
[MC_CMD_STATUS_NO_PRIVILEGE] = "No privilege",
[MC_CMD_STATUS_DMA_ERR] = "DMA or I/O error",
[MC_CMD_STATUS_CONFIG_ERR] = "Configuration error",
[MC_CMD_STATUS_TIMEOUT] = "Operation timed out",
[MC_CMD_STATUS_NO_RESOURCE] = "No resources",
[MC_CMD_STATUS_NO_MEMORY] = "No memory available",
[MC_CMD_STATUS_BUSY] = "Device is busy",
[MC_CMD_STATUS_UNSUPPORTED_OP] = "Unsupported operation",
[MC_CMD_STATUS_INVALID_STATE] = "Invalid state"
};
if ((unsigned int)status >= ARRAY_SIZE(status_strings))
return "Unknown MC error";
return status_strings[status];
}
static inline void mc_write_command(struct mc_command __iomem *portal,
struct mc_command *cmd)
{
int i;
for (i = 0; i < MC_CMD_NUM_OF_PARAMS; i++)
writeq(cmd->params[i], &portal->params[i]);
writeq(cmd->header, &portal->header);
}
static inline enum mc_cmd_status mc_read_response(struct mc_command __iomem *
portal,
struct mc_command *resp)
{
int i;
enum mc_cmd_status status;
resp->header = readq(&portal->header);
status = MC_CMD_HDR_READ_STATUS(resp->header);
if (status != MC_CMD_STATUS_OK)
return status;
for (i = 0; i < MC_CMD_NUM_OF_PARAMS; i++)
resp->params[i] = readq(&portal->params[i]);
return status;
}
static int mc_polling_wait_preemptible(struct fsl_mc_io *mc_io,
struct mc_command *cmd,
enum mc_cmd_status *mc_status)
{
enum mc_cmd_status status;
unsigned long jiffies_until_timeout =
jiffies + msecs_to_jiffies(MC_CMD_COMPLETION_TIMEOUT_MS);
for (;;) {
status = mc_read_response(mc_io->portal_virt_addr, cmd);
if (status != MC_CMD_STATUS_READY)
break;
usleep_range(MC_CMD_COMPLETION_POLLING_MIN_SLEEP_USECS,
MC_CMD_COMPLETION_POLLING_MAX_SLEEP_USECS);
if (time_after_eq(jiffies, jiffies_until_timeout)) {
pr_debug("MC command timed out (portal: %#llx, obj handle: %#x, command: %#x)\n",
mc_io->portal_phys_addr,
(unsigned int)
MC_CMD_HDR_READ_TOKEN(cmd->header),
(unsigned int)
MC_CMD_HDR_READ_CMDID(cmd->header));
return -ETIMEDOUT;
}
}
*mc_status = status;
return 0;
}
static int mc_polling_wait_atomic(struct fsl_mc_io *mc_io,
struct mc_command *cmd,
enum mc_cmd_status *mc_status)
{
enum mc_cmd_status status;
unsigned long timeout_usecs = MC_CMD_COMPLETION_TIMEOUT_MS * 1000;
BUILD_BUG_ON((MC_CMD_COMPLETION_TIMEOUT_MS * 1000) %
MC_CMD_COMPLETION_POLLING_MAX_SLEEP_USECS != 0);
for (;;) {
status = mc_read_response(mc_io->portal_virt_addr, cmd);
if (status != MC_CMD_STATUS_READY)
break;
udelay(MC_CMD_COMPLETION_POLLING_MAX_SLEEP_USECS);
timeout_usecs -= MC_CMD_COMPLETION_POLLING_MAX_SLEEP_USECS;
if (timeout_usecs == 0) {
pr_debug("MC command timed out (portal: %#llx, obj handle: %#x, command: %#x)\n",
mc_io->portal_phys_addr,
(unsigned int)
MC_CMD_HDR_READ_TOKEN(cmd->header),
(unsigned int)
MC_CMD_HDR_READ_CMDID(cmd->header));
return -ETIMEDOUT;
}
}
*mc_status = status;
return 0;
}
int mc_send_command(struct fsl_mc_io *mc_io, struct mc_command *cmd)
{
int error;
enum mc_cmd_status status;
unsigned long irq_flags = 0;
if (WARN_ON(in_irq() &&
!(mc_io->flags & FSL_MC_IO_ATOMIC_CONTEXT_PORTAL)))
return -EINVAL;
if (mc_io->flags & FSL_MC_IO_ATOMIC_CONTEXT_PORTAL)
spin_lock_irqsave(&mc_io->spinlock, irq_flags);
else
mutex_lock(&mc_io->mutex);
mc_write_command(mc_io->portal_virt_addr, cmd);
if (!(mc_io->flags & FSL_MC_IO_ATOMIC_CONTEXT_PORTAL))
error = mc_polling_wait_preemptible(mc_io, cmd, &status);
else
error = mc_polling_wait_atomic(mc_io, cmd, &status);
if (error < 0)
goto common_exit;
if (status != MC_CMD_STATUS_OK) {
pr_debug("MC command failed: portal: %#llx, obj handle: %#x, command: %#x, status: %s (%#x)\n",
mc_io->portal_phys_addr,
(unsigned int)MC_CMD_HDR_READ_TOKEN(cmd->header),
(unsigned int)MC_CMD_HDR_READ_CMDID(cmd->header),
mc_status_to_string(status),
(unsigned int)status);
error = mc_status_to_error(status);
goto common_exit;
}
error = 0;
common_exit:
if (mc_io->flags & FSL_MC_IO_ATOMIC_CONTEXT_PORTAL)
spin_unlock_irqrestore(&mc_io->spinlock, irq_flags);
else
mutex_unlock(&mc_io->mutex);
return error;
}
