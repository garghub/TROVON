static int spcp8x5_probe(struct usb_serial *serial,\r\nconst struct usb_device_id *id)\r\n{\r\nusb_set_serial_data(serial, (void *)id);\r\nreturn 0;\r\n}\r\nstatic int spcp8x5_port_probe(struct usb_serial_port *port)\r\n{\r\nconst struct usb_device_id *id = usb_get_serial_data(port->serial);\r\nstruct spcp8x5_private *priv;\r\npriv = kzalloc(sizeof(*priv), GFP_KERNEL);\r\nif (!priv)\r\nreturn -ENOMEM;\r\nspin_lock_init(&priv->lock);\r\npriv->quirks = id->driver_info;\r\nusb_set_serial_port_data(port, priv);\r\nreturn 0;\r\n}\r\nstatic int spcp8x5_port_remove(struct usb_serial_port *port)\r\n{\r\nstruct spcp8x5_private *priv;\r\npriv = usb_get_serial_port_data(port);\r\nkfree(priv);\r\nreturn 0;\r\n}\r\nstatic int spcp8x5_set_ctrl_line(struct usb_serial_port *port, u8 mcr)\r\n{\r\nstruct spcp8x5_private *priv = usb_get_serial_port_data(port);\r\nstruct usb_device *dev = port->serial->dev;\r\nint retval;\r\nif (priv->quirks & SPCP825_QUIRK_NO_UART_STATUS)\r\nreturn -EPERM;\r\nretval = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),\r\nSET_UART_STATUS_TYPE, SET_UART_STATUS,\r\nmcr, 0x04, NULL, 0, 100);\r\nif (retval != 0) {\r\ndev_err(&port->dev, "failed to set control lines: %d\n",\r\nretval);\r\n}\r\nreturn retval;\r\n}\r\nstatic int spcp8x5_get_msr(struct usb_serial_port *port, u8 *status)\r\n{\r\nstruct spcp8x5_private *priv = usb_get_serial_port_data(port);\r\nstruct usb_device *dev = port->serial->dev;\r\nu8 *buf;\r\nint ret;\r\nif (priv->quirks & SPCP825_QUIRK_NO_UART_STATUS)\r\nreturn -EPERM;\r\nbuf = kzalloc(1, GFP_KERNEL);\r\nif (!buf)\r\nreturn -ENOMEM;\r\nret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0),\r\nGET_UART_STATUS, GET_UART_STATUS_TYPE,\r\n0, GET_UART_STATUS_MSR, buf, 1, 100);\r\nif (ret < 0)\r\ndev_err(&port->dev, "failed to get modem status: %d", ret);\r\ndev_dbg(&port->dev, "0xc0:0x22:0:6 %d - 0x02%x", ret, *buf);\r\n*status = *buf;\r\nkfree(buf);\r\nreturn ret;\r\n}\r\nstatic void spcp8x5_set_work_mode(struct usb_serial_port *port, u16 value,\r\nu16 index)\r\n{\r\nstruct spcp8x5_private *priv = usb_get_serial_port_data(port);\r\nstruct usb_device *dev = port->serial->dev;\r\nint ret;\r\nif (priv->quirks & SPCP825_QUIRK_NO_WORK_MODE)\r\nreturn;\r\nret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),\r\nSET_WORKING_MODE_TYPE, SET_WORKING_MODE,\r\nvalue, index, NULL, 0, 100);\r\ndev_dbg(&port->dev, "value = %#x , index = %#x\n", value, index);\r\nif (ret < 0)\r\ndev_err(&port->dev, "failed to set work mode: %d\n", ret);\r\n}\r\nstatic int spcp8x5_carrier_raised(struct usb_serial_port *port)\r\n{\r\nu8 msr;\r\nint ret;\r\nret = spcp8x5_get_msr(port, &msr);\r\nif (ret || msr & MSR_STATUS_LINE_DCD)\r\nreturn 1;\r\nreturn 0;\r\n}\r\nstatic void spcp8x5_dtr_rts(struct usb_serial_port *port, int on)\r\n{\r\nstruct spcp8x5_private *priv = usb_get_serial_port_data(port);\r\nunsigned long flags;\r\nu8 control;\r\nspin_lock_irqsave(&priv->lock, flags);\r\nif (on)\r\npriv->line_control = MCR_CONTROL_LINE_DTR\r\n| MCR_CONTROL_LINE_RTS;\r\nelse\r\npriv->line_control &= ~ (MCR_CONTROL_LINE_DTR\r\n| MCR_CONTROL_LINE_RTS);\r\ncontrol = priv->line_control;\r\nspin_unlock_irqrestore(&priv->lock, flags);\r\nspcp8x5_set_ctrl_line(port, control);\r\n}\r\nstatic void spcp8x5_init_termios(struct tty_struct *tty)\r\n{\r\ntty->termios = tty_std_termios;\r\ntty->termios.c_cflag = B115200 | CS8 | CREAD | HUPCL | CLOCAL;\r\ntty->termios.c_ispeed = 115200;\r\ntty->termios.c_ospeed = 115200;\r\n}\r\nstatic void spcp8x5_set_termios(struct tty_struct *tty,\r\nstruct usb_serial_port *port, struct ktermios *old_termios)\r\n{\r\nstruct usb_serial *serial = port->serial;\r\nstruct spcp8x5_private *priv = usb_get_serial_port_data(port);\r\nunsigned long flags;\r\nunsigned int cflag = tty->termios.c_cflag;\r\nunsigned short uartdata;\r\nunsigned char buf[2] = {0, 0};\r\nint baud;\r\nint i;\r\nu8 control;\r\nif (old_termios && !tty_termios_hw_change(&tty->termios, old_termios))\r\nreturn;\r\nspin_lock_irqsave(&priv->lock, flags);\r\ncontrol = priv->line_control;\r\nif (old_termios && (old_termios->c_cflag & CBAUD) == B0) {\r\npriv->line_control |= MCR_DTR;\r\nif (!(old_termios->c_cflag & CRTSCTS))\r\npriv->line_control |= MCR_RTS;\r\n}\r\nif (control != priv->line_control) {\r\ncontrol = priv->line_control;\r\nspin_unlock_irqrestore(&priv->lock, flags);\r\nspcp8x5_set_ctrl_line(port, control);\r\n} else {\r\nspin_unlock_irqrestore(&priv->lock, flags);\r\n}\r\nbaud = tty_get_baud_rate(tty);\r\nswitch (baud) {\r\ncase 300: buf[0] = 0x00; break;\r\ncase 600: buf[0] = 0x01; break;\r\ncase 1200: buf[0] = 0x02; break;\r\ncase 2400: buf[0] = 0x03; break;\r\ncase 4800: buf[0] = 0x04; break;\r\ncase 9600: buf[0] = 0x05; break;\r\ncase 19200: buf[0] = 0x07; break;\r\ncase 38400: buf[0] = 0x09; break;\r\ncase 57600: buf[0] = 0x0a; break;\r\ncase 115200: buf[0] = 0x0b; break;\r\ncase 230400: buf[0] = 0x0c; break;\r\ncase 460800: buf[0] = 0x0d; break;\r\ncase 921600: buf[0] = 0x0e; break;\r\ncase 3000000: buf[0] = 0x11; break;\r\ncase 0:\r\ncase 1000000:\r\nbuf[0] = 0x0b; break;\r\ndefault:\r\ndev_err(&port->dev, "spcp825 driver does not support the "\r\n"baudrate requested, using default of 9600.\n");\r\n}\r\nif (cflag & CSIZE) {\r\nswitch (cflag & CSIZE) {\r\ncase CS5:\r\nbuf[1] |= SET_UART_FORMAT_SIZE_5;\r\nbreak;\r\ncase CS6:\r\nbuf[1] |= SET_UART_FORMAT_SIZE_6;\r\nbreak;\r\ncase CS7:\r\nbuf[1] |= SET_UART_FORMAT_SIZE_7;\r\nbreak;\r\ndefault:\r\ncase CS8:\r\nbuf[1] |= SET_UART_FORMAT_SIZE_8;\r\nbreak;\r\n}\r\n}\r\nbuf[1] |= (cflag & CSTOPB) ? SET_UART_FORMAT_STOP_2 :\r\nSET_UART_FORMAT_STOP_1;\r\nif (cflag & PARENB) {\r\nbuf[1] |= (cflag & PARODD) ?\r\nSET_UART_FORMAT_PAR_ODD : SET_UART_FORMAT_PAR_EVEN ;\r\n} else {\r\nbuf[1] |= SET_UART_FORMAT_PAR_NONE;\r\n}\r\nuartdata = buf[0] | buf[1]<<8;\r\ni = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),\r\nSET_UART_FORMAT_TYPE, SET_UART_FORMAT,\r\nuartdata, 0, NULL, 0, 100);\r\nif (i < 0)\r\ndev_err(&port->dev, "Set UART format %#x failed (error = %d)\n",\r\nuartdata, i);\r\ndev_dbg(&port->dev, "0x21:0x40:0:0 %d\n", i);\r\nif (cflag & CRTSCTS) {\r\nspcp8x5_set_work_mode(port, 0x000a, SET_WORKING_MODE_U2C);\r\n}\r\n}\r\nstatic int spcp8x5_open(struct tty_struct *tty, struct usb_serial_port *port)\r\n{\r\nstruct usb_serial *serial = port->serial;\r\nstruct spcp8x5_private *priv = usb_get_serial_port_data(port);\r\nint ret;\r\nusb_clear_halt(serial->dev, port->write_urb->pipe);\r\nusb_clear_halt(serial->dev, port->read_urb->pipe);\r\nret = usb_control_msg(serial->dev, usb_sndctrlpipe(serial->dev, 0),\r\n0x09, 0x00,\r\n0x01, 0x00, NULL, 0x00, 100);\r\nif (ret)\r\nreturn ret;\r\nspcp8x5_set_ctrl_line(port, priv->line_control);\r\nif (tty)\r\nspcp8x5_set_termios(tty, port, NULL);\r\nport->port.drain_delay = 256;\r\nreturn usb_serial_generic_open(tty, port);\r\n}\r\nstatic int spcp8x5_tiocmset(struct tty_struct *tty,\r\nunsigned int set, unsigned int clear)\r\n{\r\nstruct usb_serial_port *port = tty->driver_data;\r\nstruct spcp8x5_private *priv = usb_get_serial_port_data(port);\r\nunsigned long flags;\r\nu8 control;\r\nspin_lock_irqsave(&priv->lock, flags);\r\nif (set & TIOCM_RTS)\r\npriv->line_control |= MCR_RTS;\r\nif (set & TIOCM_DTR)\r\npriv->line_control |= MCR_DTR;\r\nif (clear & TIOCM_RTS)\r\npriv->line_control &= ~MCR_RTS;\r\nif (clear & TIOCM_DTR)\r\npriv->line_control &= ~MCR_DTR;\r\ncontrol = priv->line_control;\r\nspin_unlock_irqrestore(&priv->lock, flags);\r\nreturn spcp8x5_set_ctrl_line(port, control);\r\n}\r\nstatic int spcp8x5_tiocmget(struct tty_struct *tty)\r\n{\r\nstruct usb_serial_port *port = tty->driver_data;\r\nstruct spcp8x5_private *priv = usb_get_serial_port_data(port);\r\nunsigned long flags;\r\nunsigned int mcr;\r\nu8 status;\r\nunsigned int result;\r\nresult = spcp8x5_get_msr(port, &status);\r\nif (result)\r\nreturn result;\r\nspin_lock_irqsave(&priv->lock, flags);\r\nmcr = priv->line_control;\r\nspin_unlock_irqrestore(&priv->lock, flags);\r\nresult = ((mcr & MCR_DTR) ? TIOCM_DTR : 0)\r\n| ((mcr & MCR_RTS) ? TIOCM_RTS : 0)\r\n| ((status & MSR_STATUS_LINE_CTS) ? TIOCM_CTS : 0)\r\n| ((status & MSR_STATUS_LINE_DSR) ? TIOCM_DSR : 0)\r\n| ((status & MSR_STATUS_LINE_RI) ? TIOCM_RI : 0)\r\n| ((status & MSR_STATUS_LINE_DCD) ? TIOCM_CD : 0);\r\nreturn result;\r\n}
