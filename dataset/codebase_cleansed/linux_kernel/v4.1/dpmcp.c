int dpmcp_open(struct fsl_mc_io *mc_io, int dpmcp_id, uint16_t *token)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_OPEN,
MC_CMD_PRI_LOW, 0);
cmd.params[0] |= mc_enc(0, 32, dpmcp_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = MC_CMD_HDR_READ_TOKEN(cmd.header);
return err;
}
int dpmcp_close(struct fsl_mc_io *mc_io, uint16_t token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_CLOSE, MC_CMD_PRI_HIGH,
token);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_create(struct fsl_mc_io *mc_io,
const struct dpmcp_cfg *cfg,
uint16_t *token)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_CREATE,
MC_CMD_PRI_LOW, 0);
cmd.params[0] |= mc_enc(0, 32, cfg->portal_id);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*token = MC_CMD_HDR_READ_TOKEN(cmd.header);
return 0;
}
int dpmcp_destroy(struct fsl_mc_io *mc_io, uint16_t token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_DESTROY,
MC_CMD_PRI_LOW, token);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_reset(struct fsl_mc_io *mc_io, uint16_t token)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_RESET,
MC_CMD_PRI_LOW, token);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_set_irq(struct fsl_mc_io *mc_io,
uint16_t token,
uint8_t irq_index,
uint64_t irq_addr,
uint32_t irq_val,
int user_irq_id)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ,
MC_CMD_PRI_LOW, token);
cmd.params[0] |= mc_enc(0, 8, irq_index);
cmd.params[0] |= mc_enc(32, 32, irq_val);
cmd.params[1] |= mc_enc(0, 64, irq_addr);
cmd.params[2] |= mc_enc(0, 32, user_irq_id);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_irq(struct fsl_mc_io *mc_io,
uint16_t token,
uint8_t irq_index,
int *type,
uint64_t *irq_addr,
uint32_t *irq_val,
int *user_irq_id)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ,
MC_CMD_PRI_LOW, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*irq_val = (uint32_t)mc_dec(cmd.params[0], 0, 32);
*irq_addr = (uint64_t)mc_dec(cmd.params[1], 0, 64);
*user_irq_id = (int)mc_dec(cmd.params[2], 0, 32);
*type = (int)mc_dec(cmd.params[2], 32, 32);
return 0;
}
int dpmcp_set_irq_enable(struct fsl_mc_io *mc_io,
uint16_t token,
uint8_t irq_index,
uint8_t en)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ_ENABLE,
MC_CMD_PRI_LOW, token);
cmd.params[0] |= mc_enc(0, 8, en);
cmd.params[0] |= mc_enc(32, 8, irq_index);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_irq_enable(struct fsl_mc_io *mc_io,
uint16_t token,
uint8_t irq_index,
uint8_t *en)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_ENABLE,
MC_CMD_PRI_LOW, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*en = (uint8_t)mc_dec(cmd.params[0], 0, 8);
return 0;
}
int dpmcp_set_irq_mask(struct fsl_mc_io *mc_io,
uint16_t token,
uint8_t irq_index,
uint32_t mask)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_SET_IRQ_MASK,
MC_CMD_PRI_LOW, token);
cmd.params[0] |= mc_enc(0, 32, mask);
cmd.params[0] |= mc_enc(32, 8, irq_index);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_irq_mask(struct fsl_mc_io *mc_io,
uint16_t token,
uint8_t irq_index,
uint32_t *mask)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_MASK,
MC_CMD_PRI_LOW, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*mask = (uint32_t)mc_dec(cmd.params[0], 0, 32);
return 0;
}
int dpmcp_get_irq_status(struct fsl_mc_io *mc_io,
uint16_t token,
uint8_t irq_index,
uint32_t *status)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_IRQ_STATUS,
MC_CMD_PRI_LOW, token);
cmd.params[0] |= mc_enc(32, 8, irq_index);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
*status = (uint32_t)mc_dec(cmd.params[0], 0, 32);
return 0;
}
int dpmcp_clear_irq_status(struct fsl_mc_io *mc_io,
uint16_t token,
uint8_t irq_index,
uint32_t status)
{
struct mc_command cmd = { 0 };
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_CLEAR_IRQ_STATUS,
MC_CMD_PRI_LOW, token);
cmd.params[0] |= mc_enc(0, 32, status);
cmd.params[0] |= mc_enc(32, 8, irq_index);
return mc_send_command(mc_io, &cmd);
}
int dpmcp_get_attributes(struct fsl_mc_io *mc_io,
uint16_t token,
struct dpmcp_attr *attr)
{
struct mc_command cmd = { 0 };
int err;
cmd.header = mc_encode_cmd_header(DPMCP_CMDID_GET_ATTR,
MC_CMD_PRI_LOW, token);
err = mc_send_command(mc_io, &cmd);
if (err)
return err;
attr->id = (int)mc_dec(cmd.params[0], 32, 32);
attr->version.major = (uint16_t)mc_dec(cmd.params[1], 0, 16);
attr->version.minor = (uint16_t)mc_dec(cmd.params[1], 16, 16);
return 0;
}
