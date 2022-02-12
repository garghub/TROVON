static inline int DPRINTK(void *nothing, ...) {return 0;}
static void mfc3_write_data(struct parport *p, unsigned char data)
{
DPRINTK(KERN_DEBUG "write_data %c\n",data);
dummy = pia(p)->pprb;
pia(p)->pprb = data;
}
static unsigned char mfc3_read_data(struct parport *p)
{
return pia(p)->pprb;
}
static unsigned char control_pc_to_mfc3(unsigned char control)
{
unsigned char ret = 32|64;
if (control & PARPORT_CONTROL_SELECT)
ret &= ~32;
if (control & PARPORT_CONTROL_INIT)
ret |= 128;
if (control & PARPORT_CONTROL_AUTOFD)
ret &= ~64;
if (control & PARPORT_CONTROL_STROBE)
;
return ret;
}
static unsigned char control_mfc3_to_pc(unsigned char control)
{
unsigned char ret = PARPORT_CONTROL_STROBE
| PARPORT_CONTROL_AUTOFD | PARPORT_CONTROL_SELECT;
if (control & 128)
ret |= PARPORT_CONTROL_INIT;
if (control & 64)
ret &= ~PARPORT_CONTROL_AUTOFD;
if (control & 32)
ret &= ~PARPORT_CONTROL_SELECT;
return ret;
}
static void mfc3_write_control(struct parport *p, unsigned char control)
{
DPRINTK(KERN_DEBUG "write_control %02x\n",control);
pia(p)->ppra = (pia(p)->ppra & 0x1f) | control_pc_to_mfc3(control);
}
static unsigned char mfc3_read_control( struct parport *p)
{
DPRINTK(KERN_DEBUG "read_control \n");
return control_mfc3_to_pc(pia(p)->ppra & 0xe0);
}
static unsigned char mfc3_frob_control( struct parport *p, unsigned char mask, unsigned char val)
{
unsigned char old;
DPRINTK(KERN_DEBUG "frob_control mask %02x, value %02x\n",mask,val);
old = mfc3_read_control(p);
mfc3_write_control(p, (old & ~mask) ^ val);
return old;
}
static unsigned char status_mfc3_to_pc(unsigned char status)
{
unsigned char ret = PARPORT_STATUS_BUSY;
if (status & 1)
ret &= ~PARPORT_STATUS_BUSY;
if (status & 2)
ret |= PARPORT_STATUS_PAPEROUT;
if (status & 4)
ret |= PARPORT_STATUS_SELECT;
if (status & 8)
ret |= PARPORT_STATUS_ACK;
if (status & 16)
ret |= PARPORT_STATUS_ERROR;
return ret;
}
static unsigned char mfc3_read_status(struct parport *p)
{
unsigned char status;
status = status_mfc3_to_pc(pia(p)->ppra & 0x1f);
DPRINTK(KERN_DEBUG "read_status %02x\n", status);
return status;
}
static irqreturn_t mfc3_interrupt(int irq, void *dev_id)
{
int i;
for( i = 0; i < MAX_MFC; i++)
if (this_port[i] != NULL)
if (pia(this_port[i])->crb & 128) {
dummy = pia(this_port[i])->pprb;
parport_generic_irq(this_port[i]);
}
return IRQ_HANDLED;
}
static void mfc3_enable_irq(struct parport *p)
{
pia(p)->crb |= PIA_C1_ENABLE_IRQ;
}
static void mfc3_disable_irq(struct parport *p)
{
pia(p)->crb &= ~PIA_C1_ENABLE_IRQ;
}
static void mfc3_data_forward(struct parport *p)
{
DPRINTK(KERN_DEBUG "forward\n");
pia(p)->crb &= ~PIA_DDR;
pia(p)->pddrb = 255;
pia(p)->crb |= PIA_DDR;
}
static void mfc3_data_reverse(struct parport *p)
{
DPRINTK(KERN_DEBUG "reverse\n");
pia(p)->crb &= ~PIA_DDR;
pia(p)->pddrb = 0;
pia(p)->crb |= PIA_DDR;
}
static void mfc3_init_state(struct pardevice *dev, struct parport_state *s)
{
s->u.amiga.data = 0;
s->u.amiga.datadir = 255;
s->u.amiga.status = 0;
s->u.amiga.statusdir = 0xe0;
}
static void mfc3_save_state(struct parport *p, struct parport_state *s)
{
s->u.amiga.data = pia(p)->pprb;
pia(p)->crb &= ~PIA_DDR;
s->u.amiga.datadir = pia(p)->pddrb;
pia(p)->crb |= PIA_DDR;
s->u.amiga.status = pia(p)->ppra;
pia(p)->cra &= ~PIA_DDR;
s->u.amiga.statusdir = pia(p)->pddrb;
pia(p)->cra |= PIA_DDR;
}
static void mfc3_restore_state(struct parport *p, struct parport_state *s)
{
pia(p)->pprb = s->u.amiga.data;
pia(p)->crb &= ~PIA_DDR;
pia(p)->pddrb = s->u.amiga.datadir;
pia(p)->crb |= PIA_DDR;
pia(p)->ppra = s->u.amiga.status;
pia(p)->cra &= ~PIA_DDR;
pia(p)->pddrb = s->u.amiga.statusdir;
pia(p)->cra |= PIA_DDR;
}
static int __init parport_mfc3_init(void)
{
struct parport *p;
int pias = 0;
struct pia *pp;
struct zorro_dev *z = NULL;
if (!MACH_IS_AMIGA)
return -ENODEV;
while ((z = zorro_find_device(ZORRO_PROD_BSC_MULTIFACE_III, z))) {
unsigned long piabase = z->resource.start+PIABASE;
if (!request_mem_region(piabase, sizeof(struct pia), "PIA"))
continue;
pp = ZTWO_VADDR(piabase);
pp->crb = 0;
pp->pddrb = 255;
pp->crb = PIA_DDR|32|8;
dummy = pp->pddrb;
pp->cra = 0;
pp->pddra = 0xe0;
pp->cra = PIA_DDR;
pp->ppra = 0;
udelay(10);
pp->ppra = 128;
p = parport_register_port((unsigned long)pp, IRQ_AMIGA_PORTS,
PARPORT_DMA_NONE, &pp_mfc3_ops);
if (!p)
goto out_port;
if (p->irq != PARPORT_IRQ_NONE) {
if (use_cnt++ == 0)
if (request_irq(IRQ_AMIGA_PORTS, mfc3_interrupt, IRQF_SHARED, p->name, &pp_mfc3_ops))
goto out_irq;
}
p->dev = &z->dev;
this_port[pias++] = p;
printk(KERN_INFO "%s: Multiface III port using irq\n", p->name);
p->private_data = (void *)piabase;
parport_announce_port (p);
if (pias >= MAX_MFC)
break;
continue;
out_irq:
parport_put_port(p);
out_port:
release_mem_region(piabase, sizeof(struct pia));
}
return pias ? 0 : -ENODEV;
}
static void __exit parport_mfc3_exit(void)
{
int i;
for (i = 0; i < MAX_MFC; i++) {
if (!this_port[i])
continue;
parport_remove_port(this_port[i]);
if (this_port[i]->irq != PARPORT_IRQ_NONE) {
if (--use_cnt == 0)
free_irq(IRQ_AMIGA_PORTS, &pp_mfc3_ops);
}
release_mem_region(ZTWO_PADDR(this_port[i]->private_data), sizeof(struct pia));
parport_put_port(this_port[i]);
}
}
