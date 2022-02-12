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
