static int adv748x_configure_regmap(struct adv748x_state *state, int region)
{
int err;
if (!state->i2c_clients[region])
return -ENODEV;
state->regmap[region] =
devm_regmap_init_i2c(state->i2c_clients[region],
&adv748x_regmap_cnf[region]);
if (IS_ERR(state->regmap[region])) {
err = PTR_ERR(state->regmap[region]);
adv_err(state,
"Error initializing regmap %d with error %d\n",
region, err);
return -EINVAL;
}
return 0;
}
static int adv748x_read_check(struct adv748x_state *state,
int client_page, u8 reg)
{
struct i2c_client *client = state->i2c_clients[client_page];
int err;
unsigned int val;
err = regmap_read(state->regmap[client_page], reg, &val);
if (err) {
adv_err(state, "error reading %02x, %02x\n",
client->addr, reg);
return err;
}
return val;
}
int adv748x_read(struct adv748x_state *state, u8 page, u8 reg)
{
return adv748x_read_check(state, page, reg);
}
int adv748x_write(struct adv748x_state *state, u8 page, u8 reg, u8 value)
{
return regmap_write(state->regmap[page], reg, value);
}
int adv748x_write_block(struct adv748x_state *state, int client_page,
unsigned int init_reg, const void *val,
size_t val_len)
{
struct regmap *regmap = state->regmap[client_page];
if (val_len > I2C_SMBUS_BLOCK_MAX)
val_len = I2C_SMBUS_BLOCK_MAX;
return regmap_raw_write(regmap, init_reg, val, val_len);
}
static struct i2c_client *adv748x_dummy_client(struct adv748x_state *state,
u8 addr, u8 io_reg)
{
struct i2c_client *client = state->client;
if (addr)
io_write(state, io_reg, addr << 1);
return i2c_new_dummy(client->adapter, io_read(state, io_reg) >> 1);
}
static void adv748x_unregister_clients(struct adv748x_state *state)
{
unsigned int i;
for (i = 1; i < ARRAY_SIZE(state->i2c_clients); ++i) {
if (state->i2c_clients[i])
i2c_unregister_device(state->i2c_clients[i]);
}
}
static int adv748x_initialise_clients(struct adv748x_state *state)
{
int i;
int ret;
for (i = ADV748X_PAGE_DPLL; i < ADV748X_PAGE_MAX; ++i) {
state->i2c_clients[i] =
adv748x_dummy_client(state, adv748x_i2c_addresses[i],
ADV748X_IO_SLAVE_ADDR_BASE + i);
if (state->i2c_clients[i] == NULL) {
adv_err(state, "failed to create i2c client %u\n", i);
return -ENOMEM;
}
ret = adv748x_configure_regmap(state, i);
if (ret)
return ret;
}
return 0;
}
static int adv748x_write_regs(struct adv748x_state *state,
const struct adv748x_reg_value *regs)
{
int ret;
while (regs->page != ADV748X_PAGE_EOR) {
if (regs->page == ADV748X_PAGE_WAIT) {
msleep(regs->value);
} else {
ret = adv748x_write(state, regs->page, regs->reg,
regs->value);
if (ret < 0) {
adv_err(state,
"Error regs page: 0x%02x reg: 0x%02x\n",
regs->page, regs->reg);
return ret;
}
}
regs++;
}
return 0;
}
int adv748x_txa_power(struct adv748x_state *state, bool on)
{
int val;
val = txa_read(state, ADV748X_CSI_FS_AS_LS);
if (val < 0)
return val;
WARN_ONCE((on && val & ADV748X_CSI_FS_AS_LS_UNKNOWN),
"Enabling with unknown bit set");
if (on)
return adv748x_write_regs(state, adv748x_power_up_txa_4lane);
return adv748x_write_regs(state, adv748x_power_down_txa_4lane);
}
int adv748x_txb_power(struct adv748x_state *state, bool on)
{
int val;
val = txb_read(state, ADV748X_CSI_FS_AS_LS);
if (val < 0)
return val;
WARN_ONCE((on && val & ADV748X_CSI_FS_AS_LS_UNKNOWN),
"Enabling with unknown bit set");
if (on)
return adv748x_write_regs(state, adv748x_power_up_txb_1lane);
return adv748x_write_regs(state, adv748x_power_down_txb_1lane);
}
static int adv748x_reset(struct adv748x_state *state)
{
int ret;
ret = adv748x_write_regs(state, adv748x_sw_reset);
if (ret < 0)
return ret;
ret = adv748x_write_regs(state, adv748x_set_slave_address);
if (ret < 0)
return ret;
ret = adv748x_write_regs(state, adv748x_init_txa_4lane);
if (ret)
return ret;
adv748x_txa_power(state, 0);
ret = adv748x_write_regs(state, adv748x_init_txb_1lane);
if (ret)
return ret;
adv748x_txb_power(state, 0);
io_write(state, ADV748X_IO_PD, ADV748X_IO_PD_RX_EN);
io_write(state, ADV748X_IO_10, ADV748X_IO_10_CSI4_EN |
ADV748X_IO_10_CSI1_EN |
ADV748X_IO_10_PIX_OUT_EN);
cp_clrset(state, ADV748X_CP_CLMP_POS, ADV748X_CP_CLMP_POS_DIS_AUTO,
ADV748X_CP_CLMP_POS_DIS_AUTO);
return 0;
}
static int adv748x_identify_chip(struct adv748x_state *state)
{
int msb, lsb;
lsb = io_read(state, ADV748X_IO_CHIP_REV_ID_1);
msb = io_read(state, ADV748X_IO_CHIP_REV_ID_2);
if (lsb < 0 || msb < 0) {
adv_err(state, "Failed to read chip revision\n");
return -EIO;
}
adv_info(state, "chip found @ 0x%02x revision %02x%02x\n",
state->client->addr << 1, lsb, msb);
return 0;
}
void adv748x_subdev_init(struct v4l2_subdev *sd, struct adv748x_state *state,
const struct v4l2_subdev_ops *ops, u32 function,
const char *ident)
{
v4l2_subdev_init(sd, ops);
sd->flags |= V4L2_SUBDEV_FL_HAS_DEVNODE;
sd->owner = state->dev->driver->owner;
sd->dev = state->dev;
v4l2_set_subdevdata(sd, state);
snprintf(sd->name, sizeof(sd->name), "%s %d-%04x %s",
state->dev->driver->name,
i2c_adapter_id(state->client->adapter),
state->client->addr, ident);
sd->entity.function = function;
sd->entity.ops = &adv748x_media_ops;
}
static int adv748x_parse_dt(struct adv748x_state *state)
{
struct device_node *ep_np = NULL;
struct of_endpoint ep;
bool found = false;
for_each_endpoint_of_node(state->dev->of_node, ep_np) {
of_graph_parse_endpoint(ep_np, &ep);
adv_info(state, "Endpoint %s on port %d",
of_node_full_name(ep.local_node),
ep.port);
if (ep.port >= ADV748X_PORT_MAX) {
adv_err(state, "Invalid endpoint %s on port %d",
of_node_full_name(ep.local_node),
ep.port);
continue;
}
if (state->endpoints[ep.port]) {
adv_err(state,
"Multiple port endpoints are not supported");
continue;
}
of_node_get(ep_np);
state->endpoints[ep.port] = ep_np;
found = true;
}
return found ? 0 : -ENODEV;
}
static void adv748x_dt_cleanup(struct adv748x_state *state)
{
unsigned int i;
for (i = 0; i < ADV748X_PORT_MAX; i++)
of_node_put(state->endpoints[i]);
}
static int adv748x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adv748x_state *state;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
state = kzalloc(sizeof(struct adv748x_state), GFP_KERNEL);
if (!state)
return -ENOMEM;
mutex_init(&state->mutex);
state->dev = &client->dev;
state->client = client;
state->i2c_clients[ADV748X_PAGE_IO] = client;
i2c_set_clientdata(client, state);
ret = adv748x_parse_dt(state);
if (ret) {
adv_err(state, "Failed to parse device tree");
goto err_free_mutex;
}
ret = adv748x_configure_regmap(state, ADV748X_PAGE_IO);
if (ret) {
adv_err(state, "Error configuring IO regmap region");
goto err_cleanup_dt;
}
ret = adv748x_identify_chip(state);
if (ret) {
adv_err(state, "Failed to identify chip");
goto err_cleanup_clients;
}
ret = adv748x_initialise_clients(state);
if (ret) {
adv_err(state, "Failed to setup client regmap pages");
goto err_cleanup_clients;
}
ret = adv748x_reset(state);
if (ret) {
adv_err(state, "Failed to reset hardware");
goto err_cleanup_clients;
}
ret = adv748x_hdmi_init(&state->hdmi);
if (ret) {
adv_err(state, "Failed to probe HDMI");
goto err_cleanup_clients;
}
ret = adv748x_afe_init(&state->afe);
if (ret) {
adv_err(state, "Failed to probe AFE");
goto err_cleanup_hdmi;
}
ret = adv748x_csi2_init(state, &state->txa);
if (ret) {
adv_err(state, "Failed to probe TXA");
goto err_cleanup_afe;
}
ret = adv748x_csi2_init(state, &state->txb);
if (ret) {
adv_err(state, "Failed to probe TXB");
goto err_cleanup_txa;
}
return 0;
err_cleanup_txa:
adv748x_csi2_cleanup(&state->txa);
err_cleanup_afe:
adv748x_afe_cleanup(&state->afe);
err_cleanup_hdmi:
adv748x_hdmi_cleanup(&state->hdmi);
err_cleanup_clients:
adv748x_unregister_clients(state);
err_cleanup_dt:
adv748x_dt_cleanup(state);
err_free_mutex:
mutex_destroy(&state->mutex);
kfree(state);
return ret;
}
static int adv748x_remove(struct i2c_client *client)
{
struct adv748x_state *state = i2c_get_clientdata(client);
adv748x_afe_cleanup(&state->afe);
adv748x_hdmi_cleanup(&state->hdmi);
adv748x_csi2_cleanup(&state->txa);
adv748x_csi2_cleanup(&state->txb);
adv748x_unregister_clients(state);
adv748x_dt_cleanup(state);
mutex_destroy(&state->mutex);
kfree(state);
return 0;
}
