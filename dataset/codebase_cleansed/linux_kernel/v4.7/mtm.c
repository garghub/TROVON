static void mtm_init_nat(int cpu)
{
struct nps_host_reg_mtm_cfg mtm_cfg;
struct nps_host_reg_aux_udmc udmc;
int log_nat, nat = 0, i, t;
for (i = 0, t = cpu; i < NPS_NUM_HW_THREADS; i++, t++)
nat += test_bit(t, cpumask_bits(cpu_possible_mask));
log_nat = ilog2(nat);
udmc.value = read_aux_reg(CTOP_AUX_UDMC);
udmc.nat = log_nat;
write_aux_reg(CTOP_AUX_UDMC, udmc.value);
mtm_cfg.value = ioread32be(MTM_CFG(cpu));
mtm_cfg.nat = log_nat;
iowrite32be(mtm_cfg.value, MTM_CFG(cpu));
}
static void mtm_init_thread(int cpu)
{
int i, tries = 5;
struct nps_host_reg_thr_init thr_init;
struct nps_host_reg_thr_init_sts thr_init_sts;
thr_init.value = 0;
iowrite32be(thr_init.value, MTM_THR_INIT(cpu));
thr_init.thr_id = NPS_CPU_TO_THREAD_NUM(cpu);
thr_init.str = 1;
iowrite32be(thr_init.value, MTM_THR_INIT(cpu));
for (i = 0; i < tries; i++) {
thr_init_sts.value = ioread32be(MTM_THR_INIT_STS(cpu));
if (thr_init_sts.thr_id == thr_init.thr_id) {
if (thr_init_sts.bsy)
continue;
else if (thr_init_sts.err)
pr_warn("Failed to thread init cpu %u\n", cpu);
break;
}
pr_warn("Wrong thread id in thread init for cpu %u\n", cpu);
break;
}
if (i == tries)
pr_warn("Got thread init timeout for cpu %u\n", cpu);
}
int mtm_enable_thread(int cpu)
{
struct nps_host_reg_mtm_cfg mtm_cfg;
if (NPS_CPU_TO_THREAD_NUM(cpu) == 0)
return 1;
mtm_cfg.value = ioread32be(MTM_CFG(cpu));
mtm_cfg.ten |= (1 << (NPS_CPU_TO_THREAD_NUM(cpu)));
iowrite32be(mtm_cfg.value, MTM_CFG(cpu));
return 0;
}
void mtm_enable_core(unsigned int cpu)
{
int i;
struct nps_host_reg_aux_mt_ctrl mt_ctrl;
struct nps_host_reg_mtm_cfg mtm_cfg;
if (NPS_CPU_TO_THREAD_NUM(cpu) != 0)
return;
mtm_init_nat(cpu);
mtm_cfg.value = ioread32be(MTM_CFG(cpu));
mtm_cfg.ten = 1;
iowrite32be(mtm_cfg.value, MTM_CFG(cpu));
for (i = 1; i < NPS_NUM_HW_THREADS; i++)
mtm_init_thread(cpu + i);
mt_ctrl.value = 0;
mt_ctrl.hsen = 1;
mt_ctrl.hs_cnt = MT_CTRL_HS_CNT;
mt_ctrl.sten = 1;
mt_ctrl.st_cnt = MT_CTRL_ST_CNT;
mt_ctrl.mten = 1;
write_aux_reg(CTOP_AUX_MT_CTRL, mt_ctrl.value);
cpu_relax();
}
