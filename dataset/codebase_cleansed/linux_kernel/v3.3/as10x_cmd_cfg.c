int as10x_cmd_get_context(struct as10x_bus_adapter_t *adap, uint16_t tag,
uint32_t *pvalue)
{
int error;
struct as10x_cmd_t *pcmd, *prsp;
ENTER();
pcmd = adap->cmd;
prsp = adap->rsp;
as10x_cmd_build(pcmd, (++adap->cmd_xid),
sizeof(pcmd->body.context.req));
pcmd->body.context.req.proc_id = cpu_to_le16(CONTROL_PROC_CONTEXT);
pcmd->body.context.req.tag = cpu_to_le16(tag);
pcmd->body.context.req.type = cpu_to_le16(GET_CONTEXT_DATA);
if (adap->ops->xfer_cmd) {
error = adap->ops->xfer_cmd(adap,
(uint8_t *) pcmd,
sizeof(pcmd->body.context.req)
+ HEADER_SIZE,
(uint8_t *) prsp,
sizeof(prsp->body.context.rsp)
+ HEADER_SIZE);
} else {
error = AS10X_CMD_ERROR;
}
if (error < 0)
goto out;
error = as10x_context_rsp_parse(prsp, CONTROL_PROC_CONTEXT_RSP);
if (error == 0) {
*pvalue = le32_to_cpu(prsp->body.context.rsp.reg_val.u.value32);
}
out:
LEAVE();
return error;
}
int as10x_cmd_set_context(struct as10x_bus_adapter_t *adap, uint16_t tag,
uint32_t value)
{
int error;
struct as10x_cmd_t *pcmd, *prsp;
ENTER();
pcmd = adap->cmd;
prsp = adap->rsp;
as10x_cmd_build(pcmd, (++adap->cmd_xid),
sizeof(pcmd->body.context.req));
pcmd->body.context.req.proc_id = cpu_to_le16(CONTROL_PROC_CONTEXT);
pcmd->body.context.req.reg_val.u.value32 = cpu_to_le32(value);
pcmd->body.context.req.tag = cpu_to_le16(tag);
pcmd->body.context.req.type = cpu_to_le16(SET_CONTEXT_DATA);
if (adap->ops->xfer_cmd) {
error = adap->ops->xfer_cmd(adap,
(uint8_t *) pcmd,
sizeof(pcmd->body.context.req)
+ HEADER_SIZE,
(uint8_t *) prsp,
sizeof(prsp->body.context.rsp)
+ HEADER_SIZE);
} else {
error = AS10X_CMD_ERROR;
}
if (error < 0)
goto out;
error = as10x_context_rsp_parse(prsp, CONTROL_PROC_CONTEXT_RSP);
out:
LEAVE();
return error;
}
int as10x_cmd_eLNA_change_mode(struct as10x_bus_adapter_t *adap, uint8_t mode)
{
int error;
struct as10x_cmd_t *pcmd, *prsp;
ENTER();
pcmd = adap->cmd;
prsp = adap->rsp;
as10x_cmd_build(pcmd, (++adap->cmd_xid),
sizeof(pcmd->body.cfg_change_mode.req));
pcmd->body.cfg_change_mode.req.proc_id =
cpu_to_le16(CONTROL_PROC_ELNA_CHANGE_MODE);
pcmd->body.cfg_change_mode.req.mode = mode;
if (adap->ops->xfer_cmd) {
error = adap->ops->xfer_cmd(adap, (uint8_t *) pcmd,
sizeof(pcmd->body.cfg_change_mode.req)
+ HEADER_SIZE, (uint8_t *) prsp,
sizeof(prsp->body.cfg_change_mode.rsp)
+ HEADER_SIZE);
} else {
error = AS10X_CMD_ERROR;
}
if (error < 0)
goto out;
error = as10x_rsp_parse(prsp, CONTROL_PROC_ELNA_CHANGE_MODE_RSP);
out:
LEAVE();
return error;
}
int as10x_context_rsp_parse(struct as10x_cmd_t *prsp, uint16_t proc_id)
{
int err;
err = prsp->body.context.rsp.error;
if ((err == 0) &&
(le16_to_cpu(prsp->body.context.rsp.proc_id) == proc_id)) {
return 0;
}
return AS10X_CMD_ERROR;
}
