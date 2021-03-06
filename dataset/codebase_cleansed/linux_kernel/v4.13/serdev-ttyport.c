static int ttyport_receive_buf(struct tty_port *port, const unsigned char *cp,
const unsigned char *fp, size_t count)
{
struct serdev_controller *ctrl = port->client_data;
struct serport *serport = serdev_controller_get_drvdata(ctrl);
if (!test_bit(SERPORT_ACTIVE, &serport->flags))
return 0;
return serdev_controller_receive_buf(ctrl, cp, count);
}
static void ttyport_write_wakeup(struct tty_port *port)
{
struct serdev_controller *ctrl = port->client_data;
struct serport *serport = serdev_controller_get_drvdata(ctrl);
if (test_and_clear_bit(TTY_DO_WRITE_WAKEUP, &port->tty->flags) &&
test_bit(SERPORT_ACTIVE, &serport->flags))
serdev_controller_write_wakeup(ctrl);
wake_up_interruptible_poll(&port->tty->write_wait, POLLOUT);
}
static int ttyport_write_buf(struct serdev_controller *ctrl, const unsigned char *data, size_t len)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
if (!test_bit(SERPORT_ACTIVE, &serport->flags))
return 0;
set_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
return tty->ops->write(serport->tty, data, len);
}
static void ttyport_write_flush(struct serdev_controller *ctrl)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
tty_driver_flush_buffer(tty);
}
static int ttyport_write_room(struct serdev_controller *ctrl)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
return tty_write_room(tty);
}
static int ttyport_open(struct serdev_controller *ctrl)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty;
struct ktermios ktermios;
tty = tty_init_dev(serport->tty_drv, serport->tty_idx);
if (IS_ERR(tty))
return PTR_ERR(tty);
serport->tty = tty;
if (tty->ops->open)
tty->ops->open(serport->tty, NULL);
else
tty_port_open(serport->port, tty, NULL);
ktermios = tty->termios;
ktermios.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP |
INLCR | IGNCR | ICRNL | IXON);
ktermios.c_oflag &= ~OPOST;
ktermios.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
ktermios.c_cflag &= ~(CSIZE | PARENB);
ktermios.c_cflag |= CS8;
ktermios.c_cflag |= CRTSCTS;
tty_set_termios(tty, &ktermios);
set_bit(SERPORT_ACTIVE, &serport->flags);
tty_unlock(serport->tty);
return 0;
}
static void ttyport_close(struct serdev_controller *ctrl)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
clear_bit(SERPORT_ACTIVE, &serport->flags);
if (tty->ops->close)
tty->ops->close(tty, NULL);
tty_release_struct(tty, serport->tty_idx);
}
static unsigned int ttyport_set_baudrate(struct serdev_controller *ctrl, unsigned int speed)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
struct ktermios ktermios = tty->termios;
ktermios.c_cflag &= ~CBAUD;
tty_termios_encode_baud_rate(&ktermios, speed, speed);
tty_set_termios(tty, &ktermios);
return ktermios.c_ospeed;
}
static void ttyport_set_flow_control(struct serdev_controller *ctrl, bool enable)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
struct ktermios ktermios = tty->termios;
if (enable)
ktermios.c_cflag |= CRTSCTS;
else
ktermios.c_cflag &= ~CRTSCTS;
tty_set_termios(tty, &ktermios);
}
static void ttyport_wait_until_sent(struct serdev_controller *ctrl, long timeout)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
tty_wait_until_sent(tty, timeout);
}
static int ttyport_get_tiocm(struct serdev_controller *ctrl)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
if (!tty->ops->tiocmget)
return -ENOTSUPP;
return tty->driver->ops->tiocmget(tty);
}
static int ttyport_set_tiocm(struct serdev_controller *ctrl, unsigned int set, unsigned int clear)
{
struct serport *serport = serdev_controller_get_drvdata(ctrl);
struct tty_struct *tty = serport->tty;
if (!tty->ops->tiocmset)
return -ENOTSUPP;
return tty->driver->ops->tiocmset(tty, set, clear);
}
struct device *serdev_tty_port_register(struct tty_port *port,
struct device *parent,
struct tty_driver *drv, int idx)
{
const struct tty_port_client_operations *old_ops;
struct serdev_controller *ctrl;
struct serport *serport;
int ret;
if (!port || !drv || !parent)
return ERR_PTR(-ENODEV);
ctrl = serdev_controller_alloc(parent, sizeof(struct serport));
if (!ctrl)
return ERR_PTR(-ENOMEM);
serport = serdev_controller_get_drvdata(ctrl);
serport->port = port;
serport->tty_idx = idx;
serport->tty_drv = drv;
ctrl->ops = &ctrl_ops;
old_ops = port->client_ops;
port->client_ops = &client_ops;
port->client_data = ctrl;
ret = serdev_controller_add(ctrl);
if (ret)
goto err_reset_data;
dev_info(&ctrl->dev, "tty port %s%d registered\n", drv->name, idx);
return &ctrl->dev;
err_reset_data:
port->client_data = NULL;
port->client_ops = old_ops;
serdev_controller_put(ctrl);
return ERR_PTR(ret);
}
int serdev_tty_port_unregister(struct tty_port *port)
{
struct serdev_controller *ctrl = port->client_data;
struct serport *serport = serdev_controller_get_drvdata(ctrl);
if (!serport)
return -ENODEV;
serdev_controller_remove(ctrl);
port->client_ops = NULL;
port->client_data = NULL;
serdev_controller_put(ctrl);
return 0;
}
