u32 omap4_prm_read_inst_reg(s16 inst, u16 reg)
{
return __raw_readl(OMAP44XX_PRM_REGADDR(inst, reg));
}
void omap4_prm_write_inst_reg(u32 val, s16 inst, u16 reg)
{
__raw_writel(val, OMAP44XX_PRM_REGADDR(inst, reg));
}
u32 omap4_prm_rmw_inst_reg_bits(u32 mask, u32 bits, s16 inst, s16 reg)
{
u32 v;
v = omap4_prm_read_inst_reg(inst, reg);
v &= ~mask;
v |= bits;
omap4_prm_write_inst_reg(v, inst, reg);
return v;
}
u32 omap4_prm_vp_check_txdone(u8 vp_id)
{
struct omap4_vp *vp = &omap4_vp[vp_id];
u32 irqstatus;
irqstatus = omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
OMAP4430_PRM_OCP_SOCKET_INST,
vp->irqstatus_mpu);
return irqstatus & vp->tranxdone_status;
}
void omap4_prm_vp_clear_txdone(u8 vp_id)
{
struct omap4_vp *vp = &omap4_vp[vp_id];
omap4_prminst_write_inst_reg(vp->tranxdone_status,
OMAP4430_PRM_PARTITION,
OMAP4430_PRM_OCP_SOCKET_INST,
vp->irqstatus_mpu);
}
u32 omap4_prm_vcvp_read(u8 offset)
{
return omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
OMAP4430_PRM_DEVICE_INST, offset);
}
void omap4_prm_vcvp_write(u32 val, u8 offset)
{
omap4_prminst_write_inst_reg(val, OMAP4430_PRM_PARTITION,
OMAP4430_PRM_DEVICE_INST, offset);
}
u32 omap4_prm_vcvp_rmw(u32 mask, u32 bits, u8 offset)
{
return omap4_prminst_rmw_inst_reg_bits(mask, bits,
OMAP4430_PRM_PARTITION,
OMAP4430_PRM_DEVICE_INST,
offset);
}
static inline u32 _read_pending_irq_reg(u16 irqen_offs, u16 irqst_offs)
{
u32 mask, st;
mask = omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
irqen_offs);
st = omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST, irqst_offs);
return mask & st;
}
void omap44xx_prm_read_pending_irqs(unsigned long *events)
{
events[0] = _read_pending_irq_reg(OMAP4_PRM_IRQENABLE_MPU_OFFSET,
OMAP4_PRM_IRQSTATUS_MPU_OFFSET);
events[1] = _read_pending_irq_reg(OMAP4_PRM_IRQENABLE_MPU_2_OFFSET,
OMAP4_PRM_IRQSTATUS_MPU_2_OFFSET);
}
void omap44xx_prm_ocp_barrier(void)
{
omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_REVISION_PRM_OFFSET);
}
void omap44xx_prm_save_and_clear_irqen(u32 *saved_mask)
{
saved_mask[0] =
omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQSTATUS_MPU_OFFSET);
saved_mask[1] =
omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQSTATUS_MPU_2_OFFSET);
omap4_prm_write_inst_reg(0, OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQENABLE_MPU_OFFSET);
omap4_prm_write_inst_reg(0, OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQENABLE_MPU_2_OFFSET);
omap4_prm_read_inst_reg(OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_REVISION_PRM_OFFSET);
}
void omap44xx_prm_restore_irqen(u32 *saved_mask)
{
omap4_prm_write_inst_reg(saved_mask[0], OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQENABLE_MPU_OFFSET);
omap4_prm_write_inst_reg(saved_mask[1], OMAP4430_PRM_OCP_SOCKET_INST,
OMAP4_PRM_IRQENABLE_MPU_2_OFFSET);
}
void omap44xx_prm_reconfigure_io_chain(void)
{
int i = 0;
omap4_prm_rmw_inst_reg_bits(OMAP4430_WUCLK_CTRL_MASK,
OMAP4430_WUCLK_CTRL_MASK,
OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET);
omap_test_timeout(
(((omap4_prm_read_inst_reg(OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET) &
OMAP4430_WUCLK_STATUS_MASK) >>
OMAP4430_WUCLK_STATUS_SHIFT) == 1),
MAX_IOPAD_LATCH_TIME, i);
if (i == MAX_IOPAD_LATCH_TIME)
pr_warn("PRM: I/O chain clock line assertion timed out\n");
omap4_prm_rmw_inst_reg_bits(OMAP4430_WUCLK_CTRL_MASK, 0x0,
OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET);
omap_test_timeout(
(((omap4_prm_read_inst_reg(OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET) &
OMAP4430_WUCLK_STATUS_MASK) >>
OMAP4430_WUCLK_STATUS_SHIFT) == 0),
MAX_IOPAD_LATCH_TIME, i);
if (i == MAX_IOPAD_LATCH_TIME)
pr_warn("PRM: I/O chain clock line deassertion timed out\n");
return;
}
static void __init omap44xx_prm_enable_io_wakeup(void)
{
omap4_prm_rmw_inst_reg_bits(OMAP4430_GLOBAL_WUEN_MASK,
OMAP4430_GLOBAL_WUEN_MASK,
OMAP4430_PRM_DEVICE_INST,
OMAP4_PRM_IO_PMCTRL_OFFSET);
}
static int __init omap4xxx_prcm_init(void)
{
if (cpu_is_omap44xx()) {
omap44xx_prm_enable_io_wakeup();
return omap_prcm_register_chain_handler(&omap4_prcm_irq_setup);
}
return 0;
}
