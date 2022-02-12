static u64 pcr_address(struct cmp_connection *c)
{
if (c->direction == CMP_INPUT)
return CSR_REGISTER_BASE + CSR_IPCR(c->pcr_index);
else
return CSR_REGISTER_BASE + CSR_OPCR(c->pcr_index);
}
static int pcr_modify(struct cmp_connection *c,
__be32 (*modify)(struct cmp_connection *c, __be32 old),
int (*check)(struct cmp_connection *c, __be32 pcr),
enum bus_reset_handling bus_reset_handling)
{
__be32 old_arg, buffer[2];
int err;
buffer[0] = c->last_pcr_value;
for (;;) {
old_arg = buffer[0];
buffer[1] = modify(c, buffer[0]);
err = snd_fw_transaction(
c->resources.unit, TCODE_LOCK_COMPARE_SWAP,
pcr_address(c), buffer, 8,
FW_FIXED_GENERATION | c->resources.generation);
if (err < 0) {
if (err == -EAGAIN &&
bus_reset_handling == SUCCEED_ON_BUS_RESET)
err = 0;
return err;
}
if (buffer[0] == old_arg)
break;
if (check) {
err = check(c, buffer[0]);
if (err < 0)
return err;
}
}
c->last_pcr_value = buffer[1];
return 0;
}
int cmp_connection_init(struct cmp_connection *c,
struct fw_unit *unit,
enum cmp_direction direction,
unsigned int pcr_index)
{
__be32 mpr_be;
u32 mpr;
int err;
c->direction = direction;
err = snd_fw_transaction(unit, TCODE_READ_QUADLET_REQUEST,
mpr_address(c), &mpr_be, 4, 0);
if (err < 0)
return err;
mpr = be32_to_cpu(mpr_be);
if (pcr_index >= (mpr & MPR_PLUGS_MASK))
return -EINVAL;
err = fw_iso_resources_init(&c->resources, unit);
if (err < 0)
return err;
c->connected = false;
mutex_init(&c->mutex);
c->last_pcr_value = cpu_to_be32(0x80000000);
c->pcr_index = pcr_index;
c->max_speed = (mpr & MPR_SPEED_MASK) >> MPR_SPEED_SHIFT;
if (c->max_speed == SCODE_BETA)
c->max_speed += (mpr & MPR_XSPEED_MASK) >> MPR_XSPEED_SHIFT;
return 0;
}
int cmp_connection_check_used(struct cmp_connection *c, bool *used)
{
__be32 pcr;
int err;
err = snd_fw_transaction(
c->resources.unit, TCODE_READ_QUADLET_REQUEST,
pcr_address(c), &pcr, 4, 0);
if (err >= 0)
*used = !!(pcr & cpu_to_be32(PCR_BCAST_CONN |
PCR_P2P_CONN_MASK));
return err;
}
void cmp_connection_destroy(struct cmp_connection *c)
{
WARN_ON(c->connected);
mutex_destroy(&c->mutex);
fw_iso_resources_destroy(&c->resources);
}
static __be32 ipcr_set_modify(struct cmp_connection *c, __be32 ipcr)
{
ipcr &= ~cpu_to_be32(PCR_BCAST_CONN |
PCR_P2P_CONN_MASK |
PCR_CHANNEL_MASK);
ipcr |= cpu_to_be32(1 << PCR_P2P_CONN_SHIFT);
ipcr |= cpu_to_be32(c->resources.channel << PCR_CHANNEL_SHIFT);
return ipcr;
}
static int get_overhead_id(struct cmp_connection *c)
{
int id;
for (id = 1; id < 16; id++) {
if (c->resources.bandwidth_overhead < (id << 5))
break;
}
if (id == 16)
id = 0;
return id;
}
static __be32 opcr_set_modify(struct cmp_connection *c, __be32 opcr)
{
unsigned int spd, xspd;
if (c->speed > SCODE_400) {
spd = SCODE_800;
xspd = c->speed - SCODE_800;
} else {
spd = c->speed;
xspd = 0;
}
opcr &= ~cpu_to_be32(PCR_BCAST_CONN |
PCR_P2P_CONN_MASK |
OPCR_XSPEED_MASK |
PCR_CHANNEL_MASK |
OPCR_SPEED_MASK |
OPCR_OVERHEAD_ID_MASK);
opcr |= cpu_to_be32(1 << PCR_P2P_CONN_SHIFT);
opcr |= cpu_to_be32(xspd << OPCR_XSPEED_SHIFT);
opcr |= cpu_to_be32(c->resources.channel << PCR_CHANNEL_SHIFT);
opcr |= cpu_to_be32(spd << OPCR_SPEED_SHIFT);
opcr |= cpu_to_be32(get_overhead_id(c) << OPCR_OVERHEAD_ID_SHIFT);
return opcr;
}
static int pcr_set_check(struct cmp_connection *c, __be32 pcr)
{
if (pcr & cpu_to_be32(PCR_BCAST_CONN |
PCR_P2P_CONN_MASK)) {
cmp_error(c, "plug is already in use\n");
return -EBUSY;
}
if (!(pcr & cpu_to_be32(PCR_ONLINE))) {
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
if (c->direction == CMP_OUTPUT)
err = pcr_modify(c, opcr_set_modify, pcr_set_check,
ABORT_ON_BUS_RESET);
else
err = pcr_modify(c, ipcr_set_modify, pcr_set_check,
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
if (c->direction == CMP_OUTPUT)
err = pcr_modify(c, opcr_set_modify, pcr_set_check,
SUCCEED_ON_BUS_RESET);
else
err = pcr_modify(c, ipcr_set_modify, pcr_set_check,
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
static __be32 pcr_break_modify(struct cmp_connection *c, __be32 pcr)
{
return pcr & ~cpu_to_be32(PCR_BCAST_CONN | PCR_P2P_CONN_MASK);
}
void cmp_connection_break(struct cmp_connection *c)
{
int err;
mutex_lock(&c->mutex);
if (!c->connected) {
mutex_unlock(&c->mutex);
return;
}
err = pcr_modify(c, pcr_break_modify, NULL, SUCCEED_ON_BUS_RESET);
if (err < 0)
cmp_error(c, "plug is still connected\n");
fw_iso_resources_free(&c->resources);
c->connected = false;
mutex_unlock(&c->mutex);
}
