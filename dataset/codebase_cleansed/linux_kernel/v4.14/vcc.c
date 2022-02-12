static int vcc_table_add(struct vcc_port *port)
{
unsigned long flags;
int i;
spin_lock_irqsave(&vcc_table_lock, flags);
for (i = VCC_MINOR_START; i < VCC_MAX_PORTS; i++) {
if (!vcc_table[i]) {
vcc_table[i] = port;
break;
}
}
spin_unlock_irqrestore(&vcc_table_lock, flags);
if (i < VCC_MAX_PORTS)
return i;
else
return -1;
}
static void vcc_table_remove(unsigned long index)
{
unsigned long flags;
if (WARN_ON(index >= VCC_MAX_PORTS))
return;
spin_lock_irqsave(&vcc_table_lock, flags);
vcc_table[index] = NULL;
spin_unlock_irqrestore(&vcc_table_lock, flags);
}
static struct vcc_port *vcc_get(unsigned long index, bool excl)
{
struct vcc_port *port;
unsigned long flags;
try_again:
spin_lock_irqsave(&vcc_table_lock, flags);
port = vcc_table[index];
if (!port) {
spin_unlock_irqrestore(&vcc_table_lock, flags);
return NULL;
}
if (!excl) {
if (port->excl_locked) {
spin_unlock_irqrestore(&vcc_table_lock, flags);
udelay(VCC_REF_DELAY);
goto try_again;
}
port->refcnt++;
spin_unlock_irqrestore(&vcc_table_lock, flags);
return port;
}
if (port->refcnt) {
spin_unlock_irqrestore(&vcc_table_lock, flags);
udelay(VCC_REF_DELAY/2);
goto try_again;
}
port->refcnt++;
port->excl_locked = true;
spin_unlock_irqrestore(&vcc_table_lock, flags);
return port;
}
static void vcc_put(struct vcc_port *port, bool excl)
{
unsigned long flags;
if (!port)
return;
spin_lock_irqsave(&vcc_table_lock, flags);
if (WARN_ON((excl && !port->excl_locked) ||
(!excl && port->excl_locked)))
goto done;
port->refcnt--;
if (excl)
port->excl_locked = false;
done:
spin_unlock_irqrestore(&vcc_table_lock, flags);
}
static struct vcc_port *vcc_get_ne(unsigned long index)
{
struct vcc_port *port;
port = vcc_get(index, false);
if (port && port->removed) {
vcc_put(port, false);
return NULL;
}
return port;
}
static void vcc_kick_rx(struct vcc_port *port)
{
struct vio_driver_state *vio = &port->vio;
assert_spin_locked(&port->lock);
if (!timer_pending(&port->rx_timer) && !port->removed) {
disable_irq_nosync(vio->vdev->rx_irq);
port->rx_timer.expires = (jiffies + 1);
add_timer(&port->rx_timer);
}
}
static void vcc_kick_tx(struct vcc_port *port)
{
assert_spin_locked(&port->lock);
if (!timer_pending(&port->tx_timer) && !port->removed) {
port->tx_timer.expires = (jiffies + 1);
add_timer(&port->tx_timer);
}
}
static int vcc_rx_check(struct tty_struct *tty, int size)
{
if (WARN_ON(!tty || !tty->port))
return 1;
if (test_bit(TTY_THROTTLED, &tty->flags) ||
(tty_buffer_request_room(tty->port, VCC_BUFF_LEN) < VCC_BUFF_LEN))
return 0;
return 1;
}
static int vcc_rx(struct tty_struct *tty, char *buf, int size)
{
int len = 0;
if (WARN_ON(!tty || !tty->port))
return len;
len = tty_insert_flip_string(tty->port, buf, size);
if (len)
tty_flip_buffer_push(tty->port);
return len;
}
static int vcc_ldc_read(struct vcc_port *port)
{
struct vio_driver_state *vio = &port->vio;
struct tty_struct *tty;
struct vio_vcc pkt;
int rv = 0;
tty = port->tty;
if (!tty) {
rv = ldc_rx_reset(vio->lp);
vccdbg("VCC: reset rx q: rv=%d\n", rv);
goto done;
}
while (1) {
if (!vcc_rx_check(tty, VIO_VCC_MTU_SIZE)) {
vcc_kick_rx(port);
break;
}
vccdbgl(vio->lp);
rv = ldc_read(vio->lp, &pkt, sizeof(pkt));
if (rv <= 0)
break;
vccdbg("VCC: ldc_read()=%d\n", rv);
vccdbg("TAG [%02x:%02x:%04x:%08x]\n",
pkt.tag.type, pkt.tag.stype,
pkt.tag.stype_env, pkt.tag.sid);
if (pkt.tag.type == VIO_TYPE_DATA) {
vccdbgp(pkt);
vcc_rx(tty, pkt.data, pkt.tag.stype);
} else {
pr_err("VCC: unknown msg [%02x:%02x:%04x:%08x]\n",
pkt.tag.type, pkt.tag.stype,
pkt.tag.stype_env, pkt.tag.sid);
rv = -ECONNRESET;
break;
}
WARN_ON(rv != LDC_PACKET_SIZE);
}
done:
return rv;
}
static void vcc_rx_timer(unsigned long index)
{
struct vio_driver_state *vio;
struct vcc_port *port;
unsigned long flags;
int rv;
port = vcc_get_ne(index);
if (!port)
return;
spin_lock_irqsave(&port->lock, flags);
port->rx_timer.expires = 0;
vio = &port->vio;
enable_irq(vio->vdev->rx_irq);
if (!port->tty || port->removed)
goto done;
rv = vcc_ldc_read(port);
if (rv == -ECONNRESET)
vio_conn_reset(vio);
done:
spin_unlock_irqrestore(&port->lock, flags);
vcc_put(port, false);
}
static void vcc_tx_timer(unsigned long index)
{
struct vcc_port *port;
struct vio_vcc *pkt;
unsigned long flags;
int tosend = 0;
int rv;
port = vcc_get_ne(index);
if (!port)
return;
spin_lock_irqsave(&port->lock, flags);
port->tx_timer.expires = 0;
if (!port->tty || port->removed)
goto done;
tosend = min(VCC_BUFF_LEN, port->chars_in_buffer);
if (!tosend)
goto done;
pkt = &port->buffer;
pkt->tag.type = VIO_TYPE_DATA;
pkt->tag.stype = tosend;
vccdbgl(port->vio.lp);
rv = ldc_write(port->vio.lp, pkt, (VIO_TAG_SIZE + tosend));
WARN_ON(!rv);
if (rv < 0) {
vccdbg("VCC: ldc_write()=%d\n", rv);
vcc_kick_tx(port);
} else {
struct tty_struct *tty = port->tty;
port->chars_in_buffer = 0;
if (tty)
tty_wakeup(tty);
}
done:
spin_unlock_irqrestore(&port->lock, flags);
vcc_put(port, false);
}
static void vcc_event(void *arg, int event)
{
struct vio_driver_state *vio;
struct vcc_port *port;
unsigned long flags;
int rv;
port = arg;
vio = &port->vio;
spin_lock_irqsave(&port->lock, flags);
switch (event) {
case LDC_EVENT_RESET:
case LDC_EVENT_UP:
vio_link_state_change(vio, event);
break;
case LDC_EVENT_DATA_READY:
rv = vcc_ldc_read(port);
if (rv == -ECONNRESET)
vio_conn_reset(vio);
break;
default:
pr_err("VCC: unexpected LDC event(%d)\n", event);
}
spin_unlock_irqrestore(&port->lock, flags);
}
static ssize_t vcc_sysfs_domain_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct vcc_port *port;
int rv;
port = dev_get_drvdata(dev);
if (!port)
return -ENODEV;
rv = scnprintf(buf, PAGE_SIZE, "%s\n", port->domain);
return rv;
}
static int vcc_send_ctl(struct vcc_port *port, int ctl)
{
struct vio_vcc pkt;
int rv;
pkt.tag.type = VIO_TYPE_CTRL;
pkt.tag.sid = ctl;
pkt.tag.stype = 0;
rv = ldc_write(port->vio.lp, &pkt, sizeof(pkt.tag));
WARN_ON(!rv);
vccdbg("VCC: ldc_write(%ld)=%d\n", sizeof(pkt.tag), rv);
return rv;
}
static ssize_t vcc_sysfs_break_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct vcc_port *port;
unsigned long flags;
int rv = count;
int brk;
port = dev_get_drvdata(dev);
if (!port)
return -ENODEV;
spin_lock_irqsave(&port->lock, flags);
if (sscanf(buf, "%ud", &brk) != 1 || brk != 1)
rv = -EINVAL;
else if (vcc_send_ctl(port, VCC_CTL_BREAK) < 0)
vcc_kick_tx(port);
spin_unlock_irqrestore(&port->lock, flags);
return rv;
}
static int vcc_probe(struct vio_dev *vdev, const struct vio_device_id *id)
{
struct mdesc_handle *hp;
struct vcc_port *port;
struct device *dev;
const char *domain;
char *name;
u64 node;
int rv;
vccdbg("VCC: name=%s\n", dev_name(&vdev->dev));
if (!vcc_tty_driver) {
pr_err("VCC: TTY driver not registered\n");
return -ENODEV;
}
port = kzalloc(sizeof(struct vcc_port), GFP_KERNEL);
if (!port)
return -ENOMEM;
name = kstrdup(dev_name(&vdev->dev), GFP_KERNEL);
rv = vio_driver_init(&port->vio, vdev, VDEV_CONSOLE_CON, vcc_versions,
ARRAY_SIZE(vcc_versions), NULL, name);
if (rv)
goto free_port;
port->vio.debug = vcc_dbg_vio;
vcc_ldc_cfg.debug = vcc_dbg_ldc;
rv = vio_ldc_alloc(&port->vio, &vcc_ldc_cfg, port);
if (rv)
goto free_port;
spin_lock_init(&port->lock);
port->index = vcc_table_add(port);
if (port->index == -1) {
pr_err("VCC: no more TTY indices left for allocation\n");
goto free_ldc;
}
dev = tty_register_device(vcc_tty_driver, port->index, &vdev->dev);
if (IS_ERR(dev)) {
rv = PTR_ERR(dev);
goto free_table;
}
hp = mdesc_grab();
node = vio_vdev_node(hp, vdev);
if (node == MDESC_NODE_NULL) {
rv = -ENXIO;
mdesc_release(hp);
goto unreg_tty;
}
domain = mdesc_get_property(hp, node, "vcc-domain-name", NULL);
if (!domain) {
rv = -ENXIO;
mdesc_release(hp);
goto unreg_tty;
}
port->domain = kstrdup(domain, GFP_KERNEL);
mdesc_release(hp);
rv = sysfs_create_group(&vdev->dev.kobj, &vcc_attribute_group);
if (rv)
goto free_domain;
init_timer(&port->rx_timer);
port->rx_timer.function = vcc_rx_timer;
port->rx_timer.data = port->index;
init_timer(&port->tx_timer);
port->tx_timer.function = vcc_tx_timer;
port->tx_timer.data = port->index;
dev_set_drvdata(&vdev->dev, port);
disable_irq_nosync(vdev->rx_irq);
vio_port_up(&port->vio);
enable_irq(vdev->rx_irq);
return 0;
free_domain:
kfree(port->domain);
unreg_tty:
tty_unregister_device(vcc_tty_driver, port->index);
free_table:
vcc_table_remove(port->index);
free_ldc:
vio_ldc_free(&port->vio);
free_port:
kfree(name);
kfree(port);
return rv;
}
static int vcc_remove(struct vio_dev *vdev)
{
struct vcc_port *port = dev_get_drvdata(&vdev->dev);
if (!port)
return -ENODEV;
del_timer_sync(&port->rx_timer);
del_timer_sync(&port->tx_timer);
if (port->tty)
tty_vhangup(port->tty);
port = vcc_get(port->index, true);
if (WARN_ON(!port))
return -ENODEV;
tty_unregister_device(vcc_tty_driver, port->index);
del_timer_sync(&port->vio.timer);
vio_ldc_free(&port->vio);
sysfs_remove_group(&vdev->dev.kobj, &vcc_attribute_group);
dev_set_drvdata(&vdev->dev, NULL);
if (port->tty) {
port->removed = true;
vcc_put(port, true);
} else {
vcc_table_remove(port->index);
kfree(port->vio.name);
kfree(port->domain);
kfree(port);
}
return 0;
}
static int vcc_open(struct tty_struct *tty, struct file *vcc_file)
{
struct vcc_port *port;
if (unlikely(!tty)) {
pr_err("VCC: open: Invalid TTY handle\n");
return -ENXIO;
}
if (tty->count > 1)
return -EBUSY;
port = vcc_get_ne(tty->index);
if (unlikely(!port)) {
pr_err("VCC: open: Failed to find VCC port\n");
return -ENODEV;
}
if (unlikely(!port->vio.lp)) {
pr_err("VCC: open: LDC channel not configured\n");
vcc_put(port, false);
return -EPIPE;
}
vccdbgl(port->vio.lp);
vcc_put(port, false);
if (unlikely(!tty->port)) {
pr_err("VCC: open: TTY port not found\n");
return -ENXIO;
}
if (unlikely(!tty->port->ops)) {
pr_err("VCC: open: TTY ops not defined\n");
return -ENXIO;
}
return tty_port_open(tty->port, tty, vcc_file);
}
static void vcc_close(struct tty_struct *tty, struct file *vcc_file)
{
if (unlikely(!tty)) {
pr_err("VCC: close: Invalid TTY handle\n");
return;
}
if (unlikely(tty->count > 1))
return;
if (unlikely(!tty->port)) {
pr_err("VCC: close: TTY port not found\n");
return;
}
tty_port_close(tty->port, tty, vcc_file);
}
static void vcc_ldc_hup(struct vcc_port *port)
{
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
if (vcc_send_ctl(port, VCC_CTL_HUP) < 0)
vcc_kick_tx(port);
spin_unlock_irqrestore(&port->lock, flags);
}
static void vcc_hangup(struct tty_struct *tty)
{
struct vcc_port *port;
if (unlikely(!tty)) {
pr_err("VCC: hangup: Invalid TTY handle\n");
return;
}
port = vcc_get_ne(tty->index);
if (unlikely(!port)) {
pr_err("VCC: hangup: Failed to find VCC port\n");
return;
}
if (unlikely(!tty->port)) {
pr_err("VCC: hangup: TTY port not found\n");
vcc_put(port, false);
return;
}
vcc_ldc_hup(port);
vcc_put(port, false);
tty_port_hangup(tty->port);
}
static int vcc_write(struct tty_struct *tty, const unsigned char *buf,
int count)
{
struct vcc_port *port;
struct vio_vcc *pkt;
unsigned long flags;
int total_sent = 0;
int tosend = 0;
int rv = -EINVAL;
if (unlikely(!tty)) {
pr_err("VCC: write: Invalid TTY handle\n");
return -ENXIO;
}
port = vcc_get_ne(tty->index);
if (unlikely(!port)) {
pr_err("VCC: write: Failed to find VCC port");
return -ENODEV;
}
spin_lock_irqsave(&port->lock, flags);
pkt = &port->buffer;
pkt->tag.type = VIO_TYPE_DATA;
while (count > 0) {
tosend = min(count, (VCC_BUFF_LEN - port->chars_in_buffer));
if (!tosend)
break;
memcpy(&pkt->data[port->chars_in_buffer], &buf[total_sent],
tosend);
port->chars_in_buffer += tosend;
pkt->tag.stype = tosend;
vccdbg("TAG [%02x:%02x:%04x:%08x]\n", pkt->tag.type,
pkt->tag.stype, pkt->tag.stype_env, pkt->tag.sid);
vccdbg("DATA [%s]\n", pkt->data);
vccdbgl(port->vio.lp);
rv = ldc_write(port->vio.lp, pkt, (VIO_TAG_SIZE + tosend));
vccdbg("VCC: write: ldc_write(%d)=%d\n",
(VIO_TAG_SIZE + tosend), rv);
total_sent += tosend;
count -= tosend;
if (rv < 0) {
vcc_kick_tx(port);
break;
}
port->chars_in_buffer = 0;
}
spin_unlock_irqrestore(&port->lock, flags);
vcc_put(port, false);
vccdbg("VCC: write: total=%d rv=%d", total_sent, rv);
return total_sent ? total_sent : rv;
}
static int vcc_write_room(struct tty_struct *tty)
{
struct vcc_port *port;
u64 num;
if (unlikely(!tty)) {
pr_err("VCC: write_room: Invalid TTY handle\n");
return -ENXIO;
}
port = vcc_get_ne(tty->index);
if (unlikely(!port)) {
pr_err("VCC: write_room: Failed to find VCC port\n");
return -ENODEV;
}
num = VCC_BUFF_LEN - port->chars_in_buffer;
vcc_put(port, false);
return num;
}
static int vcc_chars_in_buffer(struct tty_struct *tty)
{
struct vcc_port *port;
u64 num;
if (unlikely(!tty)) {
pr_err("VCC: chars_in_buffer: Invalid TTY handle\n");
return -ENXIO;
}
port = vcc_get_ne(tty->index);
if (unlikely(!port)) {
pr_err("VCC: chars_in_buffer: Failed to find VCC port\n");
return -ENODEV;
}
num = port->chars_in_buffer;
vcc_put(port, false);
return num;
}
static int vcc_break_ctl(struct tty_struct *tty, int state)
{
struct vcc_port *port;
unsigned long flags;
if (unlikely(!tty)) {
pr_err("VCC: break_ctl: Invalid TTY handle\n");
return -ENXIO;
}
port = vcc_get_ne(tty->index);
if (unlikely(!port)) {
pr_err("VCC: break_ctl: Failed to find VCC port\n");
return -ENODEV;
}
if (state == 0) {
vcc_put(port, false);
return 0;
}
spin_lock_irqsave(&port->lock, flags);
if (vcc_send_ctl(port, VCC_CTL_BREAK) < 0)
vcc_kick_tx(port);
spin_unlock_irqrestore(&port->lock, flags);
vcc_put(port, false);
return 0;
}
static int vcc_install(struct tty_driver *driver, struct tty_struct *tty)
{
struct vcc_port *port_vcc;
struct tty_port *port_tty;
int ret;
if (unlikely(!tty)) {
pr_err("VCC: install: Invalid TTY handle\n");
return -ENXIO;
}
if (tty->index >= VCC_MAX_PORTS)
return -EINVAL;
ret = tty_standard_install(driver, tty);
if (ret)
return ret;
port_tty = kzalloc(sizeof(struct tty_port), GFP_KERNEL);
if (!port_tty)
return -ENOMEM;
port_vcc = vcc_get(tty->index, true);
if (!port_vcc) {
pr_err("VCC: install: Failed to find VCC port\n");
tty->port = NULL;
kfree(port_tty);
return -ENODEV;
}
tty_port_init(port_tty);
port_tty->ops = &vcc_port_ops;
tty->port = port_tty;
port_vcc->tty = tty;
vcc_put(port_vcc, true);
return 0;
}
static void vcc_cleanup(struct tty_struct *tty)
{
struct vcc_port *port;
if (unlikely(!tty)) {
pr_err("VCC: cleanup: Invalid TTY handle\n");
return;
}
port = vcc_get(tty->index, true);
if (port) {
port->tty = NULL;
if (port->removed) {
vcc_table_remove(tty->index);
kfree(port->vio.name);
kfree(port->domain);
kfree(port);
} else {
vcc_put(port, true);
}
}
tty_port_destroy(tty->port);
kfree(tty->port);
tty->port = NULL;
}
static int vcc_tty_init(void)
{
int rv;
pr_info("VCC: %s\n", version);
vcc_tty_driver = tty_alloc_driver(VCC_MAX_PORTS, VCC_TTY_FLAGS);
if (IS_ERR(vcc_tty_driver)) {
pr_err("VCC: TTY driver alloc failed\n");
return PTR_ERR(vcc_tty_driver);
}
vcc_tty_driver->driver_name = vcc_driver_name;
vcc_tty_driver->name = vcc_device_node;
vcc_tty_driver->minor_start = VCC_MINOR_START;
vcc_tty_driver->type = TTY_DRIVER_TYPE_SYSTEM;
vcc_tty_driver->init_termios = vcc_tty_termios;
tty_set_operations(vcc_tty_driver, &vcc_ops);
rv = tty_register_driver(vcc_tty_driver);
if (rv) {
pr_err("VCC: TTY driver registration failed\n");
put_tty_driver(vcc_tty_driver);
vcc_tty_driver = NULL;
return rv;
}
vccdbg("VCC: TTY driver registered\n");
return 0;
}
static void vcc_tty_exit(void)
{
tty_unregister_driver(vcc_tty_driver);
put_tty_driver(vcc_tty_driver);
vccdbg("VCC: TTY driver unregistered\n");
vcc_tty_driver = NULL;
}
static int __init vcc_init(void)
{
int rv;
rv = vcc_tty_init();
if (rv) {
pr_err("VCC: TTY init failed\n");
return rv;
}
rv = vio_register_driver(&vcc_driver);
if (rv) {
pr_err("VCC: VIO driver registration failed\n");
vcc_tty_exit();
} else {
vccdbg("VCC: VIO driver registered successfully\n");
}
return rv;
}
static void __exit vcc_exit(void)
{
vio_unregister_driver(&vcc_driver);
vccdbg("VCC: VIO driver unregistered\n");
vcc_tty_exit();
vccdbg("VCC: TTY driver unregistered\n");
}
