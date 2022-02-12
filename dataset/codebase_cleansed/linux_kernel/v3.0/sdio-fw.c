ssize_t i2400ms_bus_bm_cmd_send(struct i2400m *i2400m,
const struct i2400m_bootrom_header *_cmd,
size_t cmd_size, int flags)
{
ssize_t result;
struct device *dev = i2400m_dev(i2400m);
struct i2400ms *i2400ms = container_of(i2400m, struct i2400ms, i2400m);
int opcode = _cmd == NULL ? -1 : i2400m_brh_get_opcode(_cmd);
struct i2400m_bootrom_header *cmd;
size_t cmd_size_a = ALIGN(cmd_size, I2400MS_BLK_SIZE);
d_fnstart(5, dev, "(i2400m %p cmd %p size %zu)\n",
i2400m, _cmd, cmd_size);
result = -E2BIG;
if (cmd_size > I2400M_BM_CMD_BUF_SIZE)
goto error_too_big;
if (_cmd != i2400m->bm_cmd_buf)
memmove(i2400m->bm_cmd_buf, _cmd, cmd_size);
cmd = i2400m->bm_cmd_buf;
if (cmd_size_a > cmd_size)
memset(i2400m->bm_cmd_buf + cmd_size, 0, cmd_size_a - cmd_size);
if ((flags & I2400M_BM_CMD_RAW) == 0) {
if (WARN_ON(i2400m_brh_get_response_required(cmd) == 0))
dev_warn(dev, "SW BUG: response_required == 0\n");
i2400m_bm_cmd_prepare(cmd);
}
d_printf(4, dev, "BM cmd %d: %zu bytes (%zu padded)\n",
opcode, cmd_size, cmd_size_a);
d_dump(5, dev, cmd, cmd_size);
sdio_claim_host(i2400ms->func);
result = sdio_memcpy_toio(i2400ms->func, I2400MS_DATA_ADDR,
i2400m->bm_cmd_buf, cmd_size_a);
sdio_release_host(i2400ms->func);
if (result < 0) {
dev_err(dev, "BM cmd %d: cannot send: %ld\n",
opcode, (long) result);
goto error_cmd_send;
}
result = cmd_size;
error_cmd_send:
error_too_big:
d_fnend(5, dev, "(i2400m %p cmd %p size %zu) = %d\n",
i2400m, _cmd, cmd_size, (int) result);
return result;
}
ssize_t i2400ms_bus_bm_wait_for_ack(struct i2400m *i2400m,
struct i2400m_bootrom_header *ack,
size_t ack_size)
{
ssize_t result;
struct i2400ms *i2400ms = container_of(i2400m, struct i2400ms, i2400m);
struct sdio_func *func = i2400ms->func;
struct device *dev = &func->dev;
int size;
BUG_ON(sizeof(*ack) > ack_size);
d_fnstart(5, dev, "(i2400m %p ack %p size %zu)\n",
i2400m, ack, ack_size);
result = wait_event_timeout(i2400ms->bm_wfa_wq,
i2400ms->bm_ack_size != -EINPROGRESS,
2 * HZ);
if (result == 0) {
result = -ETIMEDOUT;
dev_err(dev, "BM: error waiting for an ack\n");
goto error_timeout;
}
spin_lock(&i2400m->rx_lock);
result = i2400ms->bm_ack_size;
BUG_ON(result == -EINPROGRESS);
if (result < 0)
dev_err(dev, "BM: %s failed: %zd\n", __func__, result);
else {
size = min(ack_size, i2400ms->bm_ack_size);
memcpy(ack, i2400m->bm_ack_buf, size);
}
i2400ms->bm_ack_size = -EINPROGRESS;
spin_unlock(&i2400m->rx_lock);
error_timeout:
d_fnend(5, dev, "(i2400m %p ack %p size %zu) = %zd\n",
i2400m, ack, ack_size, result);
return result;
}
