static void port_write_data(struct parport *p, unsigned char d)
{
parport_write_data(p, d);
}
static void port_write_control(struct parport *p, unsigned char d)
{
parport_write_control(p, d);
}
static unsigned char port_read_data(struct parport *p)
{
return parport_read_data(p);
}
static unsigned char port_read_status(struct parport *p)
{
return parport_read_status(p);
}
static unsigned char port_read_control(struct parport *p)
{
return parport_read_control(p);
}
static inline void line_set(struct parport *data, int state,
const struct lineop *op)
{
u8 oldval = port_read[op->port](data);
if ((op->inverted && !state) || (!op->inverted && state))
port_write[op->port](data, oldval | op->val);
else
port_write[op->port](data, oldval & ~op->val);
}
static inline int line_get(struct parport *data,
const struct lineop *op)
{
u8 oldval = port_read[op->port](data);
return ((op->inverted && (oldval & op->val) != op->val)
|| (!op->inverted && (oldval & op->val) == op->val));
}
static void parport_setscl(void *data, int state)
{
line_set((struct parport *) data, state, &adapter_parm[type].setscl);
}
static void parport_setsda(void *data, int state)
{
line_set((struct parport *) data, state, &adapter_parm[type].setsda);
}
static int parport_getscl(void *data)
{
return line_get((struct parport *) data, &adapter_parm[type].getscl);
}
static int parport_getsda(void *data)
{
return line_get((struct parport *) data, &adapter_parm[type].getsda);
}
static void i2c_parport_irq(void *data)
{
struct i2c_par *adapter = data;
struct i2c_client *ara = adapter->ara;
if (ara) {
dev_dbg(&ara->dev, "SMBus alert received\n");
i2c_handle_smbus_alert(ara);
} else
dev_dbg(&adapter->adapter.dev,
"SMBus alert received but no ARA client!\n");
}
static void i2c_parport_attach(struct parport *port)
{
struct i2c_par *adapter;
int i;
struct pardev_cb i2c_parport_cb;
for (i = 0; i < MAX_DEVICE; i++) {
if (parport[i] == -1)
continue;
if (port->number == parport[i])
break;
}
if (i == MAX_DEVICE) {
pr_debug("Not using parport%d.\n", port->number);
return;
}
adapter = kzalloc(sizeof(struct i2c_par), GFP_KERNEL);
if (!adapter)
return;
memset(&i2c_parport_cb, 0, sizeof(i2c_parport_cb));
i2c_parport_cb.flags = PARPORT_FLAG_EXCL;
i2c_parport_cb.irq_func = i2c_parport_irq;
i2c_parport_cb.private = adapter;
pr_debug("attaching to %s\n", port->name);
parport_disable_irq(port);
adapter->pdev = parport_register_dev_model(port, "i2c-parport",
&i2c_parport_cb, i);
if (!adapter->pdev) {
pr_err("Unable to register with parport\n");
goto err_free;
}
adapter->adapter.owner = THIS_MODULE;
adapter->adapter.class = I2C_CLASS_HWMON;
strlcpy(adapter->adapter.name, "Parallel port adapter",
sizeof(adapter->adapter.name));
adapter->algo_data = parport_algo_data;
if (!adapter_parm[type].getscl.val) {
adapter->algo_data.getscl = NULL;
adapter->algo_data.udelay = 50;
}
adapter->algo_data.data = port;
adapter->adapter.algo_data = &adapter->algo_data;
adapter->adapter.dev.parent = port->physport->dev;
if (parport_claim_or_block(adapter->pdev) < 0) {
dev_err(&adapter->pdev->dev,
"Could not claim parallel port\n");
goto err_unregister;
}
parport_setsda(port, 1);
parport_setscl(port, 1);
if (adapter_parm[type].init.val) {
line_set(port, 1, &adapter_parm[type].init);
msleep(100);
}
if (i2c_bit_add_bus(&adapter->adapter) < 0) {
dev_err(&adapter->pdev->dev, "Unable to register with I2C\n");
goto err_unregister;
}
if (adapter_parm[type].smbus_alert) {
adapter->alert_data.alert_edge_triggered = 1;
adapter->ara = i2c_setup_smbus_alert(&adapter->adapter,
&adapter->alert_data);
if (adapter->ara)
parport_enable_irq(port);
else
dev_warn(&adapter->pdev->dev,
"Failed to register ARA client\n");
}
mutex_lock(&adapter_list_lock);
list_add_tail(&adapter->node, &adapter_list);
mutex_unlock(&adapter_list_lock);
return;
err_unregister:
parport_release(adapter->pdev);
parport_unregister_device(adapter->pdev);
err_free:
kfree(adapter);
}
static void i2c_parport_detach(struct parport *port)
{
struct i2c_par *adapter, *_n;
mutex_lock(&adapter_list_lock);
list_for_each_entry_safe(adapter, _n, &adapter_list, node) {
if (adapter->pdev->port == port) {
if (adapter->ara) {
parport_disable_irq(port);
i2c_unregister_device(adapter->ara);
}
i2c_del_adapter(&adapter->adapter);
if (adapter_parm[type].init.val)
line_set(port, 0, &adapter_parm[type].init);
parport_release(adapter->pdev);
parport_unregister_device(adapter->pdev);
list_del(&adapter->node);
kfree(adapter);
}
}
mutex_unlock(&adapter_list_lock);
}
static int __init i2c_parport_init(void)
{
if (type < 0) {
pr_warn("adapter type unspecified\n");
return -ENODEV;
}
if (type >= ARRAY_SIZE(adapter_parm)) {
pr_warn("invalid type (%d)\n", type);
return -ENODEV;
}
return parport_register_driver(&i2c_parport_driver);
}
static void __exit i2c_parport_exit(void)
{
parport_unregister_driver(&i2c_parport_driver);
}
