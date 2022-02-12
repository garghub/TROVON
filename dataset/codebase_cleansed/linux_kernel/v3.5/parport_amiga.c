static void amiga_write_data(struct parport *p, unsigned char data)
{
DPRINTK(KERN_DEBUG "write_data %c\n",data);
ciaa.prb = data;
mb();
}
static unsigned char amiga_read_data(struct parport *p)
{
return ciaa.prb;
}
static unsigned char control_amiga_to_pc(unsigned char control)
{
return PARPORT_CONTROL_SELECT |
PARPORT_CONTROL_AUTOFD | PARPORT_CONTROL_STROBE;
}
static void amiga_write_control(struct parport *p, unsigned char control)
{
DPRINTK(KERN_DEBUG "write_control %02x\n",control);
}
static unsigned char amiga_read_control( struct parport *p)
{
DPRINTK(KERN_DEBUG "read_control \n");
return control_amiga_to_pc(0);
}
static unsigned char amiga_frob_control( struct parport *p, unsigned char mask, unsigned char val)
{
unsigned char old;
DPRINTK(KERN_DEBUG "frob_control mask %02x, value %02x\n",mask,val);
old = amiga_read_control(p);
amiga_write_control(p, (old & ~mask) ^ val);
return old;
}
static unsigned char status_amiga_to_pc(unsigned char status)
{
unsigned char ret = PARPORT_STATUS_BUSY | PARPORT_STATUS_ACK | PARPORT_STATUS_ERROR;
if (status & 1)
ret &= ~PARPORT_STATUS_BUSY;
if (status & 2)
ret |= PARPORT_STATUS_PAPEROUT;
if (status & 4)
ret |= PARPORT_STATUS_SELECT;
return ret;
}
static unsigned char amiga_read_status(struct parport *p)
{
unsigned char status;
status = status_amiga_to_pc(ciab.pra & 7);
DPRINTK(KERN_DEBUG "read_status %02x\n", status);
return status;
}
static void amiga_enable_irq(struct parport *p)
{
enable_irq(IRQ_AMIGA_CIAA_FLG);
}
static void amiga_disable_irq(struct parport *p)
{
disable_irq(IRQ_AMIGA_CIAA_FLG);
}
static void amiga_data_forward(struct parport *p)
{
DPRINTK(KERN_DEBUG "forward\n");
ciaa.ddrb = 0xff;
mb();
}
static void amiga_data_reverse(struct parport *p)
{
DPRINTK(KERN_DEBUG "reverse\n");
ciaa.ddrb = 0;
mb();
}
static void amiga_init_state(struct pardevice *dev, struct parport_state *s)
{
s->u.amiga.data = 0;
s->u.amiga.datadir = 255;
s->u.amiga.status = 0;
s->u.amiga.statusdir = 0;
}
static void amiga_save_state(struct parport *p, struct parport_state *s)
{
mb();
s->u.amiga.data = ciaa.prb;
s->u.amiga.datadir = ciaa.ddrb;
s->u.amiga.status = ciab.pra & 7;
s->u.amiga.statusdir = ciab.ddra & 7;
mb();
}
static void amiga_restore_state(struct parport *p, struct parport_state *s)
{
mb();
ciaa.prb = s->u.amiga.data;
ciaa.ddrb = s->u.amiga.datadir;
ciab.pra |= (ciab.pra & 0xf8) | s->u.amiga.status;
ciab.ddra |= (ciab.ddra & 0xf8) | s->u.amiga.statusdir;
mb();
}
static int __init amiga_parallel_probe(struct platform_device *pdev)
{
struct parport *p;
int err;
ciaa.ddrb = 0xff;
ciab.ddra &= 0xf8;
mb();
p = parport_register_port((unsigned long)&ciaa.prb, IRQ_AMIGA_CIAA_FLG,
PARPORT_DMA_NONE, &pp_amiga_ops);
if (!p)
return -EBUSY;
err = request_irq(IRQ_AMIGA_CIAA_FLG, parport_irq_handler, 0, p->name,
p);
if (err)
goto out_irq;
printk(KERN_INFO "%s: Amiga built-in port using irq\n", p->name);
parport_announce_port(p);
platform_set_drvdata(pdev, p);
return 0;
out_irq:
parport_put_port(p);
return err;
}
static int __exit amiga_parallel_remove(struct platform_device *pdev)
{
struct parport *port = platform_get_drvdata(pdev);
parport_remove_port(port);
if (port->irq != PARPORT_IRQ_NONE)
free_irq(IRQ_AMIGA_CIAA_FLG, port);
parport_put_port(port);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init amiga_parallel_init(void)
{
return platform_driver_probe(&amiga_parallel_driver,
amiga_parallel_probe);
}
static void __exit amiga_parallel_exit(void)
{
platform_driver_unregister(&amiga_parallel_driver);
}
