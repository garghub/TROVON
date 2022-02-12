static void start_port(struct dbg_port *p)
{
reg_ser_rw_tr_ctrl tr_ctrl = {0};
reg_ser_rw_tr_dma_en tr_dma_en = {0};
reg_ser_rw_rec_ctrl rec_ctrl = {0};
reg_ser_rw_tr_baud_div tr_baud_div = {0};
reg_ser_rw_rec_baud_div rec_baud_div = {0};
if (!p || p->started)
return;
p->started = 1;
if (p->nbr == 1)
crisv32_pinmux_alloc_fixed(pinmux_ser1);
else if (p->nbr == 2)
crisv32_pinmux_alloc_fixed(pinmux_ser2);
else if (p->nbr == 3)
crisv32_pinmux_alloc_fixed(pinmux_ser3);
#if CONFIG_ETRAX_SERIAL_PORTS == 5
else if (p->nbr == 4)
crisv32_pinmux_alloc_fixed(pinmux_ser4);
#endif
tr_ctrl.base_freq = rec_ctrl.base_freq = regk_ser_f29_493;
tr_dma_en.en = rec_ctrl.dma_mode = regk_ser_no;
tr_baud_div.div = rec_baud_div.div = 29493000 / p->baudrate / 8;
tr_ctrl.en = rec_ctrl.en = 1;
if (p->parity == 'O') {
tr_ctrl.par_en = regk_ser_yes;
tr_ctrl.par = regk_ser_odd;
rec_ctrl.par_en = regk_ser_yes;
rec_ctrl.par = regk_ser_odd;
} else if (p->parity == 'E') {
tr_ctrl.par_en = regk_ser_yes;
tr_ctrl.par = regk_ser_even;
rec_ctrl.par_en = regk_ser_yes;
rec_ctrl.par = regk_ser_odd;
}
if (p->bits == 7) {
tr_ctrl.data_bits = regk_ser_bits7;
rec_ctrl.data_bits = regk_ser_bits7;
}
REG_WR (ser, p->instance, rw_tr_baud_div, tr_baud_div);
REG_WR (ser, p->instance, rw_rec_baud_div, rec_baud_div);
REG_WR (ser, p->instance, rw_tr_dma_en, tr_dma_en);
REG_WR (ser, p->instance, rw_tr_ctrl, tr_ctrl);
REG_WR (ser, p->instance, rw_rec_ctrl, rec_ctrl);
}
int getDebugChar(void)
{
reg_ser_rs_stat_din stat;
reg_ser_rw_ack_intr ack_intr = { 0 };
do {
stat = REG_RD(ser, kgdb_port->instance, rs_stat_din);
} while (!stat.dav);
ack_intr.dav = 1;
REG_WR(ser, kgdb_port->instance, rw_ack_intr, ack_intr);
return stat.data;
}
void putDebugChar(int val)
{
reg_ser_r_stat_din stat;
do {
stat = REG_RD(ser, kgdb_port->instance, r_stat_din);
} while (!stat.tr_rdy);
REG_WR_INT(ser, kgdb_port->instance, rw_dout, val);
}
static void __init early_putch(int c)
{
reg_ser_r_stat_din stat;
do
stat = REG_RD(ser, port->instance, r_stat_din);
while (!stat.tr_rdy);
REG_WR_INT(ser, port->instance, rw_dout, c);
}
static void __init
early_console_write(struct console *con, const char *s, unsigned n)
{
extern void reset_watchdog(void);
int i;
for (i = 0; i < n; i++) {
if (s[i] == '\n')
early_putch('\r');
early_putch(s[i]);
reset_watchdog();
}
}
int __init init_etrax_debug(void)
{
start_port(port);
register_console(&early_console_dev);
#ifdef CONFIG_ETRAX_KGDB
start_port(kgdb_port);
#endif
return 0;
}
