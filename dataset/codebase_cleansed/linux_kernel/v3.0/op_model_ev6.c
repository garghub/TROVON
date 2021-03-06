static void
ev6_reg_setup(struct op_register_config *reg,
struct op_counter_config *ctr,
struct op_system_config *sys)
{
unsigned long ctl, reset, need_reset, i;
ctl = 0;
if (ctr[0].enabled && ctr[0].event)
ctl |= (ctr[0].event & 1) << 4;
if (ctr[1].enabled)
ctl |= (ctr[1].event - 2) & 15;
reg->mux_select = ctl;
reg->proc_mode = 0;
reset = need_reset = 0;
for (i = 0; i < 2; ++i) {
unsigned long count = ctr[i].count;
if (!ctr[i].enabled)
continue;
if (count > 0x100000)
count = 0x100000;
ctr[i].count = count;
reset |= (0x100000 - count) << (i ? 6 : 28);
if (count != 0x100000)
need_reset |= 1 << i;
}
reg->reset_values = reset;
reg->need_reset = need_reset;
}
static void
ev6_cpu_setup (void *x)
{
struct op_register_config *reg = x;
wrperfmon(2, reg->mux_select);
wrperfmon(3, reg->proc_mode);
wrperfmon(6, reg->reset_values | 3);
}
static void
ev6_reset_ctr(struct op_register_config *reg, unsigned long ctr)
{
wrperfmon(6, reg->reset_values | (1 << ctr));
}
static void
ev6_handle_interrupt(unsigned long which, struct pt_regs *regs,
struct op_counter_config *ctr)
{
oprofile_add_sample(regs, which);
}
