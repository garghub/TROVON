int __must_check fsl_create_mc_io(struct device *dev,
phys_addr_t mc_portal_phys_addr,
uint32_t mc_portal_size,
struct fsl_mc_resource *resource,
uint32_t flags, struct fsl_mc_io **new_mc_io)
{
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
mc_io->resource = resource;
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
*new_mc_io = mc_io;
return 0;
}
void fsl_destroy_mc_io(struct fsl_mc_io *mc_io)
{
devm_iounmap(mc_io->dev, mc_io->portal_virt_addr);
devm_release_mem_region(mc_io->dev,
mc_io->portal_phys_addr,
mc_io->portal_size);
mc_io->portal_virt_addr = NULL;
devm_kfree(mc_io->dev, mc_io);
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
int mc_send_command(struct fsl_mc_io *mc_io, struct mc_command *cmd)
{
enum mc_cmd_status status;
unsigned long jiffies_until_timeout =
jiffies + MC_CMD_COMPLETION_TIMEOUT_JIFFIES;
mc_write_command(mc_io->portal_virt_addr, cmd);
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
if (status != MC_CMD_STATUS_OK) {
pr_debug("MC command failed: portal: %#llx, obj handle: %#x, command: %#x, status: %s (%#x)\n",
mc_io->portal_phys_addr,
(unsigned int)MC_CMD_HDR_READ_TOKEN(cmd->header),
(unsigned int)MC_CMD_HDR_READ_CMDID(cmd->header),
mc_status_to_string(status),
(unsigned int)status);
return mc_status_to_error(status);
}
return 0;
}
