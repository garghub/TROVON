static int tmdc_read_packet(struct gameport *gameport, unsigned char data[2][TMDC_MAX_LENGTH])
{
unsigned char u, v, w, x;
unsigned long flags;
int i[2], j[2], t[2], p, k;
p = gameport_time(gameport, TMDC_MAX_STROBE);
for (k = 0; k < 2; k++) {
t[k] = gameport_time(gameport, TMDC_MAX_START);
i[k] = j[k] = 0;
}
local_irq_save(flags);
gameport_trigger(gameport);
w = gameport_read(gameport) >> 4;
do {
x = w;
w = gameport_read(gameport) >> 4;
for (k = 0, v = w, u = x; k < 2; k++, v >>= 2, u >>= 2) {
if (~v & u & 2) {
if (t[k] <= 0 || i[k] >= TMDC_MAX_LENGTH) continue;
t[k] = p;
if (j[k] == 0) {
if (~v & 1) t[k] = 0;
data[k][i[k]] = 0; j[k]++; continue;
}
if (j[k] == 9) {
if (v & 1) t[k] = 0;
j[k] = 0; i[k]++; continue;
}
data[k][i[k]] |= (~v & 1) << (j[k]++ - 1);
}
t[k]--;
}
} while (t[0] > 0 || t[1] > 0);
local_irq_restore(flags);
return (i[0] == TMDC_MAX_LENGTH) | ((i[1] == TMDC_MAX_LENGTH) << 1);
}
static int tmdc_parse_packet(struct tmdc_port *port, unsigned char *data)
{
int i, k, l;
if (data[TMDC_BYTE_ID] != port->mode)
return -1;
for (i = 0; i < port->absc; i++) {
if (port->abs[i] < 0)
return 0;
input_report_abs(port->dev, port->abs[i], data[tmdc_byte_a[i]]);
}
switch (port->mode) {
case TMDC_MODE_M3DI:
i = tmdc_byte_d[0];
input_report_abs(port->dev, ABS_HAT0X, ((data[i] >> 3) & 1) - ((data[i] >> 1) & 1));
input_report_abs(port->dev, ABS_HAT0Y, ((data[i] >> 2) & 1) - ( data[i] & 1));
break;
case TMDC_MODE_AT:
i = tmdc_byte_a[3];
input_report_abs(port->dev, ABS_HAT0X, tmdc_hat_to_axis[(data[i] - 141) / 25].x);
input_report_abs(port->dev, ABS_HAT0Y, tmdc_hat_to_axis[(data[i] - 141) / 25].y);
break;
}
for (k = l = 0; k < 4; k++) {
for (i = 0; i < port->btnc[k]; i++)
input_report_key(port->dev, port->btn[i + l],
((data[tmdc_byte_d[k]] >> (i + port->btno[k])) & 1));
l += port->btnc[k];
}
input_sync(port->dev);
return 0;
}
static void tmdc_poll(struct gameport *gameport)
{
unsigned char data[2][TMDC_MAX_LENGTH];
struct tmdc *tmdc = gameport_get_drvdata(gameport);
unsigned char r, bad = 0;
int i;
tmdc->reads++;
if ((r = tmdc_read_packet(tmdc->gameport, data)) != tmdc->exists)
bad = 1;
else {
for (i = 0; i < 2; i++) {
if (r & (1 << i) & tmdc->exists) {
if (tmdc_parse_packet(tmdc->port[i], data[i]))
bad = 1;
}
}
}
tmdc->bads += bad;
}
static int tmdc_open(struct input_dev *dev)
{
struct tmdc *tmdc = input_get_drvdata(dev);
gameport_start_polling(tmdc->gameport);
return 0;
}
static void tmdc_close(struct input_dev *dev)
{
struct tmdc *tmdc = input_get_drvdata(dev);
gameport_stop_polling(tmdc->gameport);
}
static int tmdc_setup_port(struct tmdc *tmdc, int idx, unsigned char *data)
{
const struct tmdc_model *model;
struct tmdc_port *port;
struct input_dev *input_dev;
int i, j, b = 0;
int err;
tmdc->port[idx] = port = kzalloc(sizeof (struct tmdc_port), GFP_KERNEL);
input_dev = input_allocate_device();
if (!port || !input_dev) {
err = -ENOMEM;
goto fail;
}
port->mode = data[TMDC_BYTE_ID];
for (model = tmdc_models; model->id && model->id != port->mode; model++)
;
port->abs = model->axes;
port->btn = model->buttons;
if (!model->id) {
port->absc = data[TMDC_BYTE_DEF] >> 4;
for (i = 0; i < 4; i++)
port->btnc[i] = i < (data[TMDC_BYTE_DEF] & 0xf) ? 8 : 0;
} else {
port->absc = model->abs;
for (i = 0; i < 4; i++)
port->btnc[i] = model->btnc[i];
}
for (i = 0; i < 4; i++)
port->btno[i] = model->btno[i];
snprintf(port->name, sizeof(port->name), model->name,
port->absc, (data[TMDC_BYTE_DEF] & 0xf) << 3, port->mode);
snprintf(port->phys, sizeof(port->phys), "%s/input%d", tmdc->gameport->phys, i);
port->dev = input_dev;
input_dev->name = port->name;
input_dev->phys = port->phys;
input_dev->id.bustype = BUS_GAMEPORT;
input_dev->id.vendor = GAMEPORT_ID_VENDOR_THRUSTMASTER;
input_dev->id.product = model->id;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &tmdc->gameport->dev;
input_set_drvdata(input_dev, tmdc);
input_dev->open = tmdc_open;
input_dev->close = tmdc_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
for (i = 0; i < port->absc && i < TMDC_ABS; i++)
if (port->abs[i] >= 0)
input_set_abs_params(input_dev, port->abs[i], 8, 248, 2, 4);
for (i = 0; i < model->hats && i < TMDC_ABS_HAT; i++)
input_set_abs_params(input_dev, tmdc_abs_hat[i], -1, 1, 0, 0);
for (i = 0; i < 4; i++) {
for (j = 0; j < port->btnc[i] && j < TMDC_BTN; j++)
set_bit(port->btn[j + b], input_dev->keybit);
b += port->btnc[i];
}
err = input_register_device(port->dev);
if (err)
goto fail;
return 0;
fail: input_free_device(input_dev);
kfree(port);
return err;
}
static int tmdc_connect(struct gameport *gameport, struct gameport_driver *drv)
{
unsigned char data[2][TMDC_MAX_LENGTH];
struct tmdc *tmdc;
int i;
int err;
if (!(tmdc = kzalloc(sizeof(struct tmdc), GFP_KERNEL)))
return -ENOMEM;
tmdc->gameport = gameport;
gameport_set_drvdata(gameport, tmdc);
err = gameport_open(gameport, drv, GAMEPORT_MODE_RAW);
if (err)
goto fail1;
if (!(tmdc->exists = tmdc_read_packet(gameport, data))) {
err = -ENODEV;
goto fail2;
}
gameport_set_poll_handler(gameport, tmdc_poll);
gameport_set_poll_interval(gameport, 20);
for (i = 0; i < 2; i++) {
if (tmdc->exists & (1 << i)) {
err = tmdc_setup_port(tmdc, i, data[i]);
if (err)
goto fail3;
}
}
return 0;
fail3: while (--i >= 0) {
if (tmdc->port[i]) {
input_unregister_device(tmdc->port[i]->dev);
kfree(tmdc->port[i]);
}
}
fail2: gameport_close(gameport);
fail1: gameport_set_drvdata(gameport, NULL);
kfree(tmdc);
return err;
}
static void tmdc_disconnect(struct gameport *gameport)
{
struct tmdc *tmdc = gameport_get_drvdata(gameport);
int i;
for (i = 0; i < 2; i++) {
if (tmdc->port[i]) {
input_unregister_device(tmdc->port[i]->dev);
kfree(tmdc->port[i]);
}
}
gameport_close(gameport);
gameport_set_drvdata(gameport, NULL);
kfree(tmdc);
}
