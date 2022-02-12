static int ps2_gpio_open(struct serio *serio)
{
struct ps2_gpio_data *drvdata = serio->port_data;
enable_irq(drvdata->irq);
return 0;
}
static void ps2_gpio_close(struct serio *serio)
{
struct ps2_gpio_data *drvdata = serio->port_data;
disable_irq(drvdata->irq);
}
static int __ps2_gpio_write(struct serio *serio, unsigned char val)
{
struct ps2_gpio_data *drvdata = serio->port_data;
disable_irq_nosync(drvdata->irq);
gpiod_direction_output(drvdata->gpio_clk, 0);
drvdata->mode = PS2_MODE_TX;
drvdata->tx_byte = val;
schedule_delayed_work(&drvdata->tx_work, usecs_to_jiffies(200));
return 0;
}
static int ps2_gpio_write(struct serio *serio, unsigned char val)
{
struct ps2_gpio_data *drvdata = serio->port_data;
int ret = 0;
if (in_task()) {
mutex_lock(&drvdata->tx_mutex);
__ps2_gpio_write(serio, val);
if (!wait_for_completion_timeout(&drvdata->tx_done,
msecs_to_jiffies(10000)))
ret = SERIO_TIMEOUT;
mutex_unlock(&drvdata->tx_mutex);
} else {
__ps2_gpio_write(serio, val);
}
return ret;
}
static void ps2_gpio_tx_work_fn(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct ps2_gpio_data *drvdata = container_of(dwork,
struct ps2_gpio_data,
tx_work);
enable_irq(drvdata->irq);
gpiod_direction_output(drvdata->gpio_data, 0);
gpiod_direction_input(drvdata->gpio_clk);
}
static irqreturn_t ps2_gpio_irq_rx(struct ps2_gpio_data *drvdata)
{
unsigned char byte, cnt;
int data;
int rxflags = 0;
static unsigned long old_jiffies;
byte = drvdata->rx_byte;
cnt = drvdata->rx_cnt;
if (old_jiffies == 0)
old_jiffies = jiffies;
if ((jiffies - old_jiffies) > usecs_to_jiffies(100)) {
dev_err(drvdata->dev,
"RX: timeout, probably we missed an interrupt\n");
goto err;
}
old_jiffies = jiffies;
data = gpiod_get_value(drvdata->gpio_data);
if (unlikely(data < 0)) {
dev_err(drvdata->dev, "RX: failed to get data gpio val: %d\n",
data);
goto err;
}
switch (cnt) {
case PS2_START_BIT:
if (unlikely(data)) {
dev_err(drvdata->dev, "RX: start bit should be low\n");
goto err;
}
break;
case PS2_DATA_BIT0:
case PS2_DATA_BIT1:
case PS2_DATA_BIT2:
case PS2_DATA_BIT3:
case PS2_DATA_BIT4:
case PS2_DATA_BIT5:
case PS2_DATA_BIT6:
case PS2_DATA_BIT7:
if (data)
byte |= (data << (cnt - 1));
break;
case PS2_PARITY_BIT:
if (!((hweight8(byte) & 1) ^ data)) {
rxflags |= SERIO_PARITY;
dev_warn(drvdata->dev, "RX: parity error\n");
if (!drvdata->write_enable)
goto err;
}
if (!drvdata->write_enable) {
if (byte == PS2_DEV_RET_NACK)
goto err;
else if (byte == PS2_DEV_RET_ACK)
break;
}
serio_interrupt(drvdata->serio, byte, rxflags);
dev_dbg(drvdata->dev, "RX: sending byte 0x%x\n", byte);
break;
case PS2_STOP_BIT:
if (unlikely(!data)) {
dev_err(drvdata->dev, "RX: stop bit should be high\n");
goto err;
}
cnt = byte = 0;
old_jiffies = 0;
goto end;
default:
dev_err(drvdata->dev, "RX: got out of sync with the device\n");
goto err;
}
cnt++;
goto end;
err:
cnt = byte = 0;
old_jiffies = 0;
__ps2_gpio_write(drvdata->serio, PS2_CMD_RESEND);
end:
drvdata->rx_cnt = cnt;
drvdata->rx_byte = byte;
return IRQ_HANDLED;
}
static irqreturn_t ps2_gpio_irq_tx(struct ps2_gpio_data *drvdata)
{
unsigned char byte, cnt;
int data;
static unsigned long old_jiffies;
cnt = drvdata->tx_cnt;
byte = drvdata->tx_byte;
if (old_jiffies == 0)
old_jiffies = jiffies;
if ((jiffies - old_jiffies) > usecs_to_jiffies(100)) {
dev_err(drvdata->dev,
"TX: timeout, probably we missed an interrupt\n");
goto err;
}
old_jiffies = jiffies;
switch (cnt) {
case PS2_START_BIT:
dev_err(drvdata->dev,
"TX: start bit should have been sent already\n");
goto err;
case PS2_DATA_BIT0:
case PS2_DATA_BIT1:
case PS2_DATA_BIT2:
case PS2_DATA_BIT3:
case PS2_DATA_BIT4:
case PS2_DATA_BIT5:
case PS2_DATA_BIT6:
case PS2_DATA_BIT7:
data = byte & BIT(cnt - 1);
gpiod_set_value(drvdata->gpio_data, data);
break;
case PS2_PARITY_BIT:
data = !(hweight8(byte) & 1);
gpiod_set_value(drvdata->gpio_data, data);
break;
case PS2_STOP_BIT:
gpiod_direction_input(drvdata->gpio_data);
break;
case PS2_TX_TIMEOUT:
break;
case PS2_ACK_BIT:
gpiod_direction_input(drvdata->gpio_data);
data = gpiod_get_value(drvdata->gpio_data);
if (data) {
dev_warn(drvdata->dev, "TX: received NACK, retry\n");
goto err;
}
drvdata->mode = PS2_MODE_RX;
complete(&drvdata->tx_done);
cnt = 1;
old_jiffies = 0;
goto end;
default:
gpiod_direction_input(drvdata->gpio_data);
dev_err(drvdata->dev, "TX: got out of sync with the device\n");
goto err;
}
cnt++;
goto end;
err:
cnt = 1;
old_jiffies = 0;
gpiod_direction_input(drvdata->gpio_data);
__ps2_gpio_write(drvdata->serio, drvdata->tx_byte);
end:
drvdata->tx_cnt = cnt;
return IRQ_HANDLED;
}
static irqreturn_t ps2_gpio_irq(int irq, void *dev_id)
{
struct ps2_gpio_data *drvdata = dev_id;
return drvdata->mode ? ps2_gpio_irq_tx(drvdata) :
ps2_gpio_irq_rx(drvdata);
}
static int ps2_gpio_get_props(struct device *dev,
struct ps2_gpio_data *drvdata)
{
drvdata->gpio_data = devm_gpiod_get(dev, "data", GPIOD_IN);
if (IS_ERR(drvdata->gpio_data)) {
dev_err(dev, "failed to request data gpio: %ld",
PTR_ERR(drvdata->gpio_data));
return PTR_ERR(drvdata->gpio_data);
}
drvdata->gpio_clk = devm_gpiod_get(dev, "clk", GPIOD_IN);
if (IS_ERR(drvdata->gpio_clk)) {
dev_err(dev, "failed to request clock gpio: %ld",
PTR_ERR(drvdata->gpio_clk));
return PTR_ERR(drvdata->gpio_clk);
}
drvdata->write_enable = device_property_read_bool(dev,
"write-enable");
return 0;
}
static int ps2_gpio_probe(struct platform_device *pdev)
{
struct ps2_gpio_data *drvdata;
struct serio *serio;
struct device *dev = &pdev->dev;
int error;
drvdata = devm_kzalloc(dev, sizeof(struct ps2_gpio_data), GFP_KERNEL);
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!drvdata || !serio) {
error = -ENOMEM;
goto err_free_serio;
}
error = ps2_gpio_get_props(dev, drvdata);
if (error)
goto err_free_serio;
if (gpiod_cansleep(drvdata->gpio_data) ||
gpiod_cansleep(drvdata->gpio_clk)) {
dev_err(dev, "GPIO data or clk are connected via slow bus\n");
error = -EINVAL;
}
drvdata->irq = platform_get_irq(pdev, 0);
if (drvdata->irq < 0) {
dev_err(dev, "failed to get irq from platform resource: %d\n",
drvdata->irq);
error = drvdata->irq;
goto err_free_serio;
}
error = devm_request_irq(dev, drvdata->irq, ps2_gpio_irq,
IRQF_NO_THREAD, DRIVER_NAME, drvdata);
if (error) {
dev_err(dev, "failed to request irq %d: %d\n",
drvdata->irq, error);
goto err_free_serio;
}
disable_irq(drvdata->irq);
serio->id.type = SERIO_8042;
serio->open = ps2_gpio_open;
serio->close = ps2_gpio_close;
serio->write = drvdata->write_enable ? ps2_gpio_write : NULL;
serio->port_data = drvdata;
serio->dev.parent = dev;
strlcpy(serio->name, dev_name(dev), sizeof(serio->name));
strlcpy(serio->phys, dev_name(dev), sizeof(serio->phys));
drvdata->serio = serio;
drvdata->dev = dev;
drvdata->mode = PS2_MODE_RX;
drvdata->tx_cnt = 1;
INIT_DELAYED_WORK(&drvdata->tx_work, ps2_gpio_tx_work_fn);
init_completion(&drvdata->tx_done);
mutex_init(&drvdata->tx_mutex);
serio_register_port(serio);
platform_set_drvdata(pdev, drvdata);
return 0;
err_free_serio:
kfree(serio);
return error;
}
static int ps2_gpio_remove(struct platform_device *pdev)
{
struct ps2_gpio_data *drvdata = platform_get_drvdata(pdev);
serio_unregister_port(drvdata->serio);
return 0;
}
