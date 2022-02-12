void cmp_connection_destroy(struct cmp_connection *c)
{
WARN_ON(c->connected);
mutex_destroy(&c->mutex);
fw_iso_resources_destroy(&c->resources);
}
static __be32 ipcr_set_modify(struct cmp_connection *c, __be32 ipcr)
{
ipcr &= ~cpu_to_be32(IPCR_BCAST_CONN |
IPCR_P2P_CONN_MASK |
IPCR_CHANNEL_MASK);
ipcr |= cpu_to_be32(1 << IPCR_P2P_CONN_SHIFT);
ipcr |= cpu_to_be32(c->resources.channel << IPCR_CHANNEL_SHIFT);
return ipcr;
}
static int ipcr_set_check(struct cmp_connection *c, __be32 ipcr)
{
if (ipcr & cpu_to_be32(IPCR_BCAST_CONN |
IPCR_P2P_CONN_MASK)) {
cmp_error(c, "plug is already in use\n");
return -EBUSY;
}
if (!(ipcr & cpu_to_be32(IPCR_ONLINE))) {
cmp_error(c, "plug is not on-line\n");
return -ECONNREFUSED;
}
return 0;
}
int cmp_connection_establish(struct cmp_connection *c,
unsigned int max_payload_bytes)
{
int err;
if (WARN_ON(c->connected))
return -EISCONN;
c->speed = min(c->max_speed,
fw_parent_device(c->resources.unit)->max_speed);
mutex_lock(&c->mutex);
retry_after_bus_reset:
err = fw_iso_resources_allocate(&c->resources,
max_payload_bytes, c->speed);
if (err < 0)
goto err_mutex;
err = pcr_modify(c, ipcr_set_modify, ipcr_set_check,
ABORT_ON_BUS_RESET);
if (err == -EAGAIN) {
fw_iso_resources_free(&c->resources);
goto retry_after_bus_reset;
}
if (err < 0)
goto err_resources;
c->connected = true;
mutex_unlock(&c->mutex);
return 0;
err_resources:
fw_iso_resources_free(&c->resources);
err_mutex:
mutex_unlock(&c->mutex);
return err;
}
int cmp_connection_update(struct cmp_connection *c)
{
int err;
mutex_lock(&c->mutex);
if (!c->connected) {
mutex_unlock(&c->mutex);
return 0;
}
err = fw_iso_resources_update(&c->resources);
if (err < 0)
goto err_unconnect;
err = pcr_modify(c, ipcr_set_modify, ipcr_set_check,
SUCCEED_ON_BUS_RESET);
if (err < 0)
goto err_resources;
mutex_unlock(&c->mutex);
return 0;
err_resources:
fw_iso_resources_free(&c->resources);
err_unconnect:
c->connected = false;
mutex_unlock(&c->mutex);
return err;
}
static __be32 ipcr_break_modify(struct cmp_connection *c, __be32 ipcr)
{
return ipcr & ~cpu_to_be32(IPCR_BCAST_CONN | IPCR_P2P_CONN_MASK);
}
void cmp_connection_break(struct cmp_connection *c)
{
int err;
mutex_lock(&c->mutex);
if (!c->connected) {
mutex_unlock(&c->mutex);
return;
}
err = pcr_modify(c, ipcr_break_modify, NULL, SUCCEED_ON_BUS_RESET);
if (err < 0)
cmp_error(c, "plug is still connected\n");
fw_iso_resources_free(&c->resources);
c->connected = false;
mutex_unlock(&c->mutex);
}
