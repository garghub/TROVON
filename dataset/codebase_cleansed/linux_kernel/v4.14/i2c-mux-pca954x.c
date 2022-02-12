static int pca954x_reg_write(struct i2c_adapter *adap,
struct i2c_client *client, u8 val)
{
int ret = -ENODEV;
if (adap->algo->master_xfer) {
struct i2c_msg msg;
char buf[1];
msg.addr = client->addr;
msg.flags = 0;
msg.len = 1;
buf[0] = val;
msg.buf = buf;
ret = __i2c_transfer(adap, &msg, 1);
if (ret >= 0 && ret != 1)
ret = -EREMOTEIO;
} else {
union i2c_smbus_data data;
ret = adap->algo->smbus_xfer(adap, client->addr,
client->flags,
I2C_SMBUS_WRITE,
val, I2C_SMBUS_BYTE, &data);
}
return ret;
}
static int pca954x_select_chan(struct i2c_mux_core *muxc, u32 chan)
{
struct pca954x *data = i2c_mux_priv(muxc);
struct i2c_client *client = data->client;
const struct chip_desc *chip = data->chip;
u8 regval;
int ret = 0;
if (chip->muxtype == pca954x_ismux)
regval = chan | chip->enable;
else
regval = 1 << chan;
if (data->last_chan != regval) {
ret = pca954x_reg_write(muxc->parent, client, regval);
data->last_chan = ret < 0 ? 0 : regval;
}
return ret;
}
static int pca954x_deselect_mux(struct i2c_mux_core *muxc, u32 chan)
{
struct pca954x *data = i2c_mux_priv(muxc);
struct i2c_client *client = data->client;
if (!(data->deselect & (1 << chan)))
return 0;
data->last_chan = 0;
return pca954x_reg_write(muxc->parent, client, data->last_chan);
}
static irqreturn_t pca954x_irq_handler(int irq, void *dev_id)
{
struct pca954x *data = dev_id;
unsigned int child_irq;
int ret, i, handled = 0;
ret = i2c_smbus_read_byte(data->client);
if (ret < 0)
return IRQ_NONE;
for (i = 0; i < data->chip->nchans; i++) {
if (ret & BIT(PCA954X_IRQ_OFFSET + i)) {
child_irq = irq_linear_revmap(data->irq, i);
handle_nested_irq(child_irq);
handled++;
}
}
return handled ? IRQ_HANDLED : IRQ_NONE;
}
static void pca954x_irq_mask(struct irq_data *idata)
{
struct pca954x *data = irq_data_get_irq_chip_data(idata);
unsigned int pos = idata->hwirq;
unsigned long flags;
raw_spin_lock_irqsave(&data->lock, flags);
data->irq_mask &= ~BIT(pos);
if (!data->irq_mask)
disable_irq(data->client->irq);
raw_spin_unlock_irqrestore(&data->lock, flags);
}
static void pca954x_irq_unmask(struct irq_data *idata)
{
struct pca954x *data = irq_data_get_irq_chip_data(idata);
unsigned int pos = idata->hwirq;
unsigned long flags;
raw_spin_lock_irqsave(&data->lock, flags);
if (!data->irq_mask)
enable_irq(data->client->irq);
data->irq_mask |= BIT(pos);
raw_spin_unlock_irqrestore(&data->lock, flags);
}
static int pca954x_irq_set_type(struct irq_data *idata, unsigned int type)
{
if ((type & IRQ_TYPE_SENSE_MASK) != IRQ_TYPE_LEVEL_LOW)
return -EINVAL;
return 0;
}
static int pca954x_irq_setup(struct i2c_mux_core *muxc)
{
struct pca954x *data = i2c_mux_priv(muxc);
struct i2c_client *client = data->client;
int c, err, irq;
if (!data->chip->has_irq || client->irq <= 0)
return 0;
raw_spin_lock_init(&data->lock);
data->irq = irq_domain_add_linear(client->dev.of_node,
data->chip->nchans,
&irq_domain_simple_ops, data);
if (!data->irq)
return -ENODEV;
for (c = 0; c < data->chip->nchans; c++) {
irq = irq_create_mapping(data->irq, c);
irq_set_chip_data(irq, data);
irq_set_chip_and_handler(irq, &pca954x_irq_chip,
handle_simple_irq);
}
err = devm_request_threaded_irq(&client->dev, data->client->irq, NULL,
pca954x_irq_handler,
IRQF_ONESHOT | IRQF_SHARED,
"pca954x", data);
if (err)
goto err_req_irq;
disable_irq(data->client->irq);
return 0;
err_req_irq:
for (c = 0; c < data->chip->nchans; c++) {
irq = irq_find_mapping(data->irq, c);
irq_dispose_mapping(irq);
}
irq_domain_remove(data->irq);
return err;
}
static int pca954x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adap = to_i2c_adapter(client->dev.parent);
struct pca954x_platform_data *pdata = dev_get_platdata(&client->dev);
struct device_node *of_node = client->dev.of_node;
bool idle_disconnect_dt;
struct gpio_desc *gpio;
int num, force, class;
struct i2c_mux_core *muxc;
struct pca954x *data;
const struct of_device_id *match;
int ret;
if (!i2c_check_functionality(adap, I2C_FUNC_SMBUS_BYTE))
return -ENODEV;
muxc = i2c_mux_alloc(adap, &client->dev,
PCA954X_MAX_NCHANS, sizeof(*data), 0,
pca954x_select_chan, pca954x_deselect_mux);
if (!muxc)
return -ENOMEM;
data = i2c_mux_priv(muxc);
i2c_set_clientdata(client, muxc);
data->client = client;
gpio = devm_gpiod_get_optional(&client->dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(gpio))
return PTR_ERR(gpio);
if (i2c_smbus_write_byte(client, 0) < 0) {
dev_warn(&client->dev, "probe failed\n");
return -ENODEV;
}
match = of_match_device(of_match_ptr(pca954x_of_match), &client->dev);
if (match)
data->chip = of_device_get_match_data(&client->dev);
else
data->chip = &chips[id->driver_data];
data->last_chan = 0;
idle_disconnect_dt = of_node &&
of_property_read_bool(of_node, "i2c-mux-idle-disconnect");
ret = pca954x_irq_setup(muxc);
if (ret)
goto fail_del_adapters;
for (num = 0; num < data->chip->nchans; num++) {
bool idle_disconnect_pd = false;
force = 0;
class = 0;
if (pdata) {
if (num < pdata->num_modes) {
force = pdata->modes[num].adap_id;
class = pdata->modes[num].class;
} else
break;
idle_disconnect_pd = pdata->modes[num].deselect_on_exit;
}
data->deselect |= (idle_disconnect_pd ||
idle_disconnect_dt) << num;
ret = i2c_mux_add_adapter(muxc, force, num, class);
if (ret)
goto fail_del_adapters;
}
dev_info(&client->dev,
"registered %d multiplexed busses for I2C %s %s\n",
num, data->chip->muxtype == pca954x_ismux
? "mux" : "switch", client->name);
return 0;
fail_del_adapters:
i2c_mux_del_adapters(muxc);
return ret;
}
static int pca954x_remove(struct i2c_client *client)
{
struct i2c_mux_core *muxc = i2c_get_clientdata(client);
struct pca954x *data = i2c_mux_priv(muxc);
int c, irq;
if (data->irq) {
for (c = 0; c < data->chip->nchans; c++) {
irq = irq_find_mapping(data->irq, c);
irq_dispose_mapping(irq);
}
irq_domain_remove(data->irq);
}
i2c_mux_del_adapters(muxc);
return 0;
}
static int pca954x_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct i2c_mux_core *muxc = i2c_get_clientdata(client);
struct pca954x *data = i2c_mux_priv(muxc);
data->last_chan = 0;
return i2c_smbus_write_byte(client, 0);
}
