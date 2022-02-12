static unsigned char
parport_atari_read_data(struct parport *p)
{
unsigned long flags;
unsigned char data;
local_irq_save(flags);
sound_ym.rd_data_reg_sel = 15;
data = sound_ym.rd_data_reg_sel;
local_irq_restore(flags);
return data;
}
static void
parport_atari_write_data(struct parport *p, unsigned char data)
{
unsigned long flags;
local_irq_save(flags);
sound_ym.rd_data_reg_sel = 15;
sound_ym.wd_data = data;
local_irq_restore(flags);
}
static unsigned char
parport_atari_read_control(struct parport *p)
{
unsigned long flags;
unsigned char control = 0;
local_irq_save(flags);
sound_ym.rd_data_reg_sel = 14;
if (!(sound_ym.rd_data_reg_sel & (1 << 5)))
control = PARPORT_CONTROL_STROBE;
local_irq_restore(flags);
return control;
}
static void
parport_atari_write_control(struct parport *p, unsigned char control)
{
unsigned long flags;
local_irq_save(flags);
sound_ym.rd_data_reg_sel = 14;
if (control & PARPORT_CONTROL_STROBE)
sound_ym.wd_data = sound_ym.rd_data_reg_sel & ~(1 << 5);
else
sound_ym.wd_data = sound_ym.rd_data_reg_sel | (1 << 5);
local_irq_restore(flags);
}
static unsigned char
parport_atari_frob_control(struct parport *p, unsigned char mask,
unsigned char val)
{
unsigned char old = parport_atari_read_control(p);
parport_atari_write_control(p, (old & ~mask) ^ val);
return old;
}
static unsigned char
parport_atari_read_status(struct parport *p)
{
return ((st_mfp.par_dt_reg & 1 ? 0 : PARPORT_STATUS_BUSY) |
PARPORT_STATUS_SELECT | PARPORT_STATUS_ERROR);
}
static void
parport_atari_init_state(struct pardevice *d, struct parport_state *s)
{
}
static void
parport_atari_save_state(struct parport *p, struct parport_state *s)
{
}
static void
parport_atari_restore_state(struct parport *p, struct parport_state *s)
{
}
static void
parport_atari_enable_irq(struct parport *p)
{
enable_irq(IRQ_MFP_BUSY);
}
static void
parport_atari_disable_irq(struct parport *p)
{
disable_irq(IRQ_MFP_BUSY);
}
static void
parport_atari_data_forward(struct parport *p)
{
unsigned long flags;
local_irq_save(flags);
sound_ym.rd_data_reg_sel = 7;
sound_ym.wd_data = sound_ym.rd_data_reg_sel | 0x40;
local_irq_restore(flags);
}
static void
parport_atari_data_reverse(struct parport *p)
{
}
static int __init parport_atari_init(void)
{
struct parport *p;
unsigned long flags;
if (MACH_IS_ATARI) {
local_irq_save(flags);
sound_ym.rd_data_reg_sel = 7;
sound_ym.wd_data = (sound_ym.rd_data_reg_sel & 0x3f) | 0xc0;
sound_ym.rd_data_reg_sel = 14;
sound_ym.wd_data = sound_ym.rd_data_reg_sel | (1 << 5);
local_irq_restore(flags);
st_mfp.data_dir &= ~1;
st_mfp.active_edge &= ~1;
p = parport_register_port((unsigned long)&sound_ym.wd_data,
IRQ_MFP_BUSY, PARPORT_DMA_NONE,
&parport_atari_ops);
if (!p)
return -ENODEV;
if (request_irq(IRQ_MFP_BUSY, parport_irq_handler,
IRQ_TYPE_SLOW, p->name, p)) {
parport_put_port (p);
return -ENODEV;
}
this_port = p;
printk(KERN_INFO "%s: Atari built-in port using irq\n", p->name);
parport_announce_port (p);
return 0;
}
return -ENODEV;
}
static void __exit parport_atari_exit(void)
{
parport_remove_port(this_port);
if (this_port->irq != PARPORT_IRQ_NONE)
free_irq(IRQ_MFP_BUSY, this_port);
parport_put_port(this_port);
}
