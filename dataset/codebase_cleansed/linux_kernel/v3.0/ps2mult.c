static void ps2mult_select_port(struct ps2mult *psm, struct ps2mult_port *port)
{
struct serio *mx_serio = psm->mx_serio;
serio_write(mx_serio, port->sel);
psm->out_port = port;
dev_dbg(&mx_serio->dev, "switched to sel %02x\n", port->sel);
}
static int ps2mult_serio_write(struct serio *serio, unsigned char data)
{
struct serio *mx_port = serio->parent;
struct ps2mult *psm = serio_get_drvdata(mx_port);
struct ps2mult_port *port = serio->port_data;
bool need_escape;
unsigned long flags;
spin_lock_irqsave(&psm->lock, flags);
if (psm->out_port != port)
ps2mult_select_port(psm, port);
need_escape = memchr(ps2mult_controls, data, sizeof(ps2mult_controls));
dev_dbg(&serio->dev,
"write: %s%02x\n", need_escape ? "ESC " : "", data);
if (need_escape)
serio_write(mx_port, PS2MULT_ESCAPE);
serio_write(mx_port, data);
spin_unlock_irqrestore(&psm->lock, flags);
return 0;
}
static int ps2mult_serio_start(struct serio *serio)
{
struct ps2mult *psm = serio_get_drvdata(serio->parent);
struct ps2mult_port *port = serio->port_data;
unsigned long flags;
spin_lock_irqsave(&psm->lock, flags);
port->registered = true;
spin_unlock_irqrestore(&psm->lock, flags);
return 0;
}
static void ps2mult_serio_stop(struct serio *serio)
{
struct ps2mult *psm = serio_get_drvdata(serio->parent);
struct ps2mult_port *port = serio->port_data;
unsigned long flags;
spin_lock_irqsave(&psm->lock, flags);
port->registered = false;
spin_unlock_irqrestore(&psm->lock, flags);
}
static int ps2mult_create_port(struct ps2mult *psm, int i)
{
struct serio *mx_serio = psm->mx_serio;
struct serio *serio;
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!serio)
return -ENOMEM;
strlcpy(serio->name, "TQC PS/2 Multiplexer", sizeof(serio->name));
snprintf(serio->phys, sizeof(serio->phys),
"%s/port%d", mx_serio->phys, i);
serio->id.type = SERIO_8042;
serio->write = ps2mult_serio_write;
serio->start = ps2mult_serio_start;
serio->stop = ps2mult_serio_stop;
serio->parent = psm->mx_serio;
serio->port_data = &psm->ports[i];
psm->ports[i].serio = serio;
return 0;
}
static void ps2mult_reset(struct ps2mult *psm)
{
unsigned long flags;
spin_lock_irqsave(&psm->lock, flags);
serio_write(psm->mx_serio, PS2MULT_SESSION_END);
serio_write(psm->mx_serio, PS2MULT_SESSION_START);
ps2mult_select_port(psm, &psm->ports[PS2MULT_KBD_PORT]);
spin_unlock_irqrestore(&psm->lock, flags);
}
static int ps2mult_connect(struct serio *serio, struct serio_driver *drv)
{
struct ps2mult *psm;
int i;
int error;
if (!serio->write)
return -EINVAL;
psm = kzalloc(sizeof(*psm), GFP_KERNEL);
if (!psm)
return -ENOMEM;
spin_lock_init(&psm->lock);
psm->mx_serio = serio;
for (i = 0; i < PS2MULT_NUM_PORTS; i++) {
psm->ports[i].sel = ps2mult_controls[i];
error = ps2mult_create_port(psm, i);
if (error)
goto err_out;
}
psm->in_port = psm->out_port = &psm->ports[PS2MULT_KBD_PORT];
serio_set_drvdata(serio, psm);
error = serio_open(serio, drv);
if (error)
goto err_out;
ps2mult_reset(psm);
for (i = 0; i < PS2MULT_NUM_PORTS; i++) {
struct serio *s = psm->ports[i].serio;
dev_info(&serio->dev, "%s port at %s\n", s->name, serio->phys);
serio_register_port(s);
}
return 0;
err_out:
while (--i >= 0)
kfree(psm->ports[i].serio);
kfree(psm);
return error;
}
static void ps2mult_disconnect(struct serio *serio)
{
struct ps2mult *psm = serio_get_drvdata(serio);
serio_write(serio, PS2MULT_SESSION_END);
serio_close(serio);
kfree(psm);
serio_set_drvdata(serio, NULL);
}
static int ps2mult_reconnect(struct serio *serio)
{
struct ps2mult *psm = serio_get_drvdata(serio);
ps2mult_reset(psm);
return 0;
}
static irqreturn_t ps2mult_interrupt(struct serio *serio,
unsigned char data, unsigned int dfl)
{
struct ps2mult *psm = serio_get_drvdata(serio);
struct ps2mult_port *in_port;
unsigned long flags;
dev_dbg(&serio->dev, "Received %02x flags %02x\n", data, dfl);
spin_lock_irqsave(&psm->lock, flags);
if (psm->escape) {
psm->escape = false;
in_port = psm->in_port;
if (in_port->registered)
serio_interrupt(in_port->serio, data, dfl);
goto out;
}
switch (data) {
case PS2MULT_ESCAPE:
dev_dbg(&serio->dev, "ESCAPE\n");
psm->escape = true;
break;
case PS2MULT_BSYNC:
dev_dbg(&serio->dev, "BSYNC\n");
psm->in_port = psm->out_port;
break;
case PS2MULT_SESSION_START:
dev_dbg(&serio->dev, "SS\n");
break;
case PS2MULT_SESSION_END:
dev_dbg(&serio->dev, "SE\n");
break;
case PS2MULT_KB_SELECTOR:
dev_dbg(&serio->dev, "KB\n");
psm->in_port = &psm->ports[PS2MULT_KBD_PORT];
break;
case PS2MULT_MS_SELECTOR:
dev_dbg(&serio->dev, "MS\n");
psm->in_port = &psm->ports[PS2MULT_MOUSE_PORT];
break;
default:
in_port = psm->in_port;
if (in_port->registered)
serio_interrupt(in_port->serio, data, dfl);
break;
}
out:
spin_unlock_irqrestore(&psm->lock, flags);
return IRQ_HANDLED;
}
static int __init ps2mult_init(void)
{
return serio_register_driver(&ps2mult_drv);
}
static void __exit ps2mult_exit(void)
{
serio_unregister_driver(&ps2mult_drv);
}
