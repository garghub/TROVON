u32 rcar_du_group_read(struct rcar_du_group *rgrp, u32 reg)
{
return rcar_du_read(rgrp->dev, rgrp->mmio_offset + reg);
}
void rcar_du_group_write(struct rcar_du_group *rgrp, u32 reg, u32 data)
{
rcar_du_write(rgrp->dev, rgrp->mmio_offset + reg, data);
}
static void rcar_du_group_setup_defr8(struct rcar_du_group *rgrp)
{
u32 defr8 = DEFR8_CODE | DEFR8_DEFE8;
if (rgrp->dev->info->routes[RCAR_DU_OUTPUT_DPAD0].possible_crtcs > 1 &&
rgrp->index == 0)
defr8 |= DEFR8_DRGBS_DU(rgrp->dev->dpad0_source);
rcar_du_group_write(rgrp, DEFR8, defr8);
}
static void rcar_du_group_setup(struct rcar_du_group *rgrp)
{
rcar_du_group_write(rgrp, DEFR, DEFR_CODE | DEFR_DEFE);
rcar_du_group_write(rgrp, DEFR2, DEFR2_CODE | DEFR2_DEFE2G);
rcar_du_group_write(rgrp, DEFR3, DEFR3_CODE | DEFR3_DEFE3);
rcar_du_group_write(rgrp, DEFR4, DEFR4_CODE);
rcar_du_group_write(rgrp, DEFR5, DEFR5_CODE | DEFR5_DEFE5);
if (rcar_du_has(rgrp->dev, RCAR_DU_FEATURE_EXT_CTRL_REGS)) {
rcar_du_group_setup_defr8(rgrp);
rcar_du_group_write(rgrp, DIDSR, DIDSR_CODE |
DIDSR_LCDS_DCLKIN(2) |
DIDSR_LCDS_DCLKIN(1) |
DIDSR_LCDS_DCLKIN(0) |
DIDSR_PDCS_CLK(2, 0) |
DIDSR_PDCS_CLK(1, 0) |
DIDSR_PDCS_CLK(0, 0));
}
rcar_du_group_write(rgrp, DORCR, DORCR_PG1D_DS1 | DORCR_DPRS);
mutex_lock(&rgrp->lock);
rcar_du_group_write(rgrp, DPTSR, (rgrp->dptsr_planes << 16) |
rgrp->dptsr_planes);
mutex_unlock(&rgrp->lock);
}
int rcar_du_group_get(struct rcar_du_group *rgrp)
{
if (rgrp->use_count)
goto done;
rcar_du_group_setup(rgrp);
done:
rgrp->use_count++;
return 0;
}
void rcar_du_group_put(struct rcar_du_group *rgrp)
{
--rgrp->use_count;
}
static void __rcar_du_group_start_stop(struct rcar_du_group *rgrp, bool start)
{
rcar_du_group_write(rgrp, DSYSR,
(rcar_du_group_read(rgrp, DSYSR) & ~(DSYSR_DRES | DSYSR_DEN)) |
(start ? DSYSR_DEN : DSYSR_DRES));
}
void rcar_du_group_start_stop(struct rcar_du_group *rgrp, bool start)
{
if (start) {
if (rgrp->used_crtcs++ != 0)
__rcar_du_group_start_stop(rgrp, false);
__rcar_du_group_start_stop(rgrp, true);
} else {
if (--rgrp->used_crtcs == 0)
__rcar_du_group_start_stop(rgrp, false);
}
}
void rcar_du_group_restart(struct rcar_du_group *rgrp)
{
__rcar_du_group_start_stop(rgrp, false);
__rcar_du_group_start_stop(rgrp, true);
}
static int rcar_du_set_dpad0_routing(struct rcar_du_device *rcdu)
{
int ret;
if (!rcar_du_has(rcdu, RCAR_DU_FEATURE_EXT_CTRL_REGS))
return 0;
ret = clk_prepare_enable(rcdu->crtcs[0].clock);
if (ret < 0)
return ret;
rcar_du_group_setup_defr8(&rcdu->groups[0]);
clk_disable_unprepare(rcdu->crtcs[0].clock);
return 0;
}
int rcar_du_group_set_routing(struct rcar_du_group *rgrp)
{
struct rcar_du_crtc *crtc0 = &rgrp->dev->crtcs[rgrp->index * 2];
u32 dorcr = rcar_du_group_read(rgrp, DORCR);
dorcr &= ~(DORCR_PG2T | DORCR_DK2S | DORCR_PG2D_MASK);
if (crtc0->outputs & BIT(RCAR_DU_OUTPUT_DPAD1))
dorcr |= DORCR_PG2D_DS1;
else
dorcr |= DORCR_PG2T | DORCR_DK2S | DORCR_PG2D_DS2;
rcar_du_group_write(rgrp, DORCR, dorcr);
return rcar_du_set_dpad0_routing(rgrp->dev);
}
