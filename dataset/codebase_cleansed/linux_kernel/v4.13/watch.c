void mips_install_watch_registers(struct task_struct *t)
{
struct mips3264_watch_reg_state *watches = &t->thread.watch.mips3264;
switch (current_cpu_data.watch_reg_use_cnt) {
default:
BUG();
case 4:
write_c0_watchlo3(watches->watchlo[3]);
write_c0_watchhi3(MIPS_WATCHHI_G | MIPS_WATCHHI_IRW |
watches->watchhi[3]);
case 3:
write_c0_watchlo2(watches->watchlo[2]);
write_c0_watchhi2(MIPS_WATCHHI_G | MIPS_WATCHHI_IRW |
watches->watchhi[2]);
case 2:
write_c0_watchlo1(watches->watchlo[1]);
write_c0_watchhi1(MIPS_WATCHHI_G | MIPS_WATCHHI_IRW |
watches->watchhi[1]);
case 1:
write_c0_watchlo0(watches->watchlo[0]);
write_c0_watchhi0(MIPS_WATCHHI_G | MIPS_WATCHHI_IRW |
watches->watchhi[0]);
}
}
void mips_read_watch_registers(void)
{
struct mips3264_watch_reg_state *watches =
&current->thread.watch.mips3264;
switch (current_cpu_data.watch_reg_use_cnt) {
default:
BUG();
case 4:
watches->watchhi[3] = (read_c0_watchhi3() &
(MIPS_WATCHHI_MASK | MIPS_WATCHHI_IRW));
case 3:
watches->watchhi[2] = (read_c0_watchhi2() &
(MIPS_WATCHHI_MASK | MIPS_WATCHHI_IRW));
case 2:
watches->watchhi[1] = (read_c0_watchhi1() &
(MIPS_WATCHHI_MASK | MIPS_WATCHHI_IRW));
case 1:
watches->watchhi[0] = (read_c0_watchhi0() &
(MIPS_WATCHHI_MASK | MIPS_WATCHHI_IRW));
}
if (current_cpu_data.watch_reg_use_cnt == 1 &&
(watches->watchhi[0] & MIPS_WATCHHI_IRW) == 0) {
watches->watchhi[0] |= (watches->watchlo[0] & MIPS_WATCHHI_IRW);
}
}
void mips_clear_watch_registers(void)
{
switch (current_cpu_data.watch_reg_count) {
default:
BUG();
case 8:
write_c0_watchlo7(0);
case 7:
write_c0_watchlo6(0);
case 6:
write_c0_watchlo5(0);
case 5:
write_c0_watchlo4(0);
case 4:
write_c0_watchlo3(0);
case 3:
write_c0_watchlo2(0);
case 2:
write_c0_watchlo1(0);
case 1:
write_c0_watchlo0(0);
}
}
void mips_probe_watch_registers(struct cpuinfo_mips *c)
{
unsigned int t;
if ((c->options & MIPS_CPU_WATCH) == 0)
return;
write_c0_watchlo0(MIPS_WATCHLO_IRW);
back_to_back_c0_hazard();
t = read_c0_watchlo0();
write_c0_watchlo0(0);
c->watch_reg_masks[0] = t & MIPS_WATCHLO_IRW;
c->watch_reg_count = 1;
c->watch_reg_use_cnt = 1;
t = read_c0_watchhi0();
write_c0_watchhi0(t | MIPS_WATCHHI_MASK);
back_to_back_c0_hazard();
t = read_c0_watchhi0();
c->watch_reg_masks[0] |= (t & MIPS_WATCHHI_MASK);
if ((t & MIPS_WATCHHI_M) == 0)
return;
write_c0_watchlo1(MIPS_WATCHLO_IRW);
back_to_back_c0_hazard();
t = read_c0_watchlo1();
write_c0_watchlo1(0);
c->watch_reg_masks[1] = t & MIPS_WATCHLO_IRW;
c->watch_reg_count = 2;
c->watch_reg_use_cnt = 2;
t = read_c0_watchhi1();
write_c0_watchhi1(t | MIPS_WATCHHI_MASK);
back_to_back_c0_hazard();
t = read_c0_watchhi1();
c->watch_reg_masks[1] |= (t & MIPS_WATCHHI_MASK);
if ((t & MIPS_WATCHHI_M) == 0)
return;
write_c0_watchlo2(MIPS_WATCHLO_IRW);
back_to_back_c0_hazard();
t = read_c0_watchlo2();
write_c0_watchlo2(0);
c->watch_reg_masks[2] = t & MIPS_WATCHLO_IRW;
c->watch_reg_count = 3;
c->watch_reg_use_cnt = 3;
t = read_c0_watchhi2();
write_c0_watchhi2(t | MIPS_WATCHHI_MASK);
back_to_back_c0_hazard();
t = read_c0_watchhi2();
c->watch_reg_masks[2] |= (t & MIPS_WATCHHI_MASK);
if ((t & MIPS_WATCHHI_M) == 0)
return;
write_c0_watchlo3(MIPS_WATCHLO_IRW);
back_to_back_c0_hazard();
t = read_c0_watchlo3();
write_c0_watchlo3(0);
c->watch_reg_masks[3] = t & MIPS_WATCHLO_IRW;
c->watch_reg_count = 4;
c->watch_reg_use_cnt = 4;
t = read_c0_watchhi3();
write_c0_watchhi3(t | MIPS_WATCHHI_MASK);
back_to_back_c0_hazard();
t = read_c0_watchhi3();
c->watch_reg_masks[3] |= (t & MIPS_WATCHHI_MASK);
if ((t & MIPS_WATCHHI_M) == 0)
return;
c->watch_reg_count = 5;
t = read_c0_watchhi4();
if ((t & MIPS_WATCHHI_M) == 0)
return;
c->watch_reg_count = 6;
t = read_c0_watchhi5();
if ((t & MIPS_WATCHHI_M) == 0)
return;
c->watch_reg_count = 7;
t = read_c0_watchhi6();
if ((t & MIPS_WATCHHI_M) == 0)
return;
c->watch_reg_count = 8;
}
