u32 rcar_du_group_read(struct rcar_du_group *rgrp, u32 reg)
{
return rcar_du_read(rgrp->dev, rgrp->mmio_offset + reg);
}
void rcar_du_group_write(struct rcar_du_group *rgrp, u32 reg, u32 data)
{
rcar_du_write(rgrp->dev, rgrp->mmio_offset + reg, data);
}
static void rcar_du_group_setup_pins(struct rcar_du_group *rgrp)
{
u32 defr6 = DEFR6_CODE | DEFR6_ODPM12_DISP;
if (rgrp->num_crtcs > 1)
defr6 |= DEFR6_ODPM22_DISP;
rcar_du_group_write(rgrp, DEFR6, defr6);
}
static void rcar_du_group_setup_defr8(struct rcar_du_group *rgrp)
{
struct rcar_du_device *rcdu = rgrp->dev;
unsigned int possible_crtcs =
rcdu->info->routes[RCAR_DU_OUTPUT_DPAD0].possible_crtcs;
u32 defr8 = DEFR8_CODE;
if (rcdu->info->gen < 3) {
defr8 |= DEFR8_DEFE8;
if (rgrp->index == 0) {
if (possible_crtcs > 1)
defr8 |= DEFR8_DRGBS_DU(rcdu->dpad0_source);
if (rgrp->dev->vspd1_sink == 2)
defr8 |= DEFR8_VSCS;
}
} else {
u32 crtc = ffs(possible_crtcs) - 1;
if (crtc / 2 == rgrp->index)
defr8 |= DEFR8_DRGBS_DU(crtc);
}
rcar_du_group_write(rgrp, DEFR8, defr8);
}
static void rcar_du_group_setup(struct rcar_du_group *rgrp)
{
struct rcar_du_device *rcdu = rgrp->dev;
rcar_du_group_write(rgrp, DEFR, DEFR_CODE | DEFR_DEFE);
if (rcdu->info->gen < 3) {
rcar_du_group_write(rgrp, DEFR2, DEFR2_CODE | DEFR2_DEFE2G);
rcar_du_group_write(rgrp, DEFR3, DEFR3_CODE | DEFR3_DEFE3);
rcar_du_group_write(rgrp, DEFR4, DEFR4_CODE);
}
rcar_du_group_write(rgrp, DEFR5, DEFR5_CODE | DEFR5_DEFE5);
rcar_du_group_setup_pins(rgrp);
if (rcar_du_has(rgrp->dev, RCAR_DU_FEATURE_EXT_CTRL_REGS)) {
rcar_du_group_setup_defr8(rgrp);
if ((rcdu->info->gen < 3 && rgrp->index == 0) ||
(rcdu->info->gen == 3 && rgrp->num_crtcs > 1))
rcar_du_group_write(rgrp, DIDSR, DIDSR_CODE);
}
if (rcdu->info->gen >= 3)
rcar_du_group_write(rgrp, DEFR10, DEFR10_CODE | DEFR10_DEFE10);
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
rgrp->need_restart = false;
__rcar_du_group_start_stop(rgrp, false);
__rcar_du_group_start_stop(rgrp, true);
}
int rcar_du_set_dpad0_vsp1_routing(struct rcar_du_device *rcdu)
{
struct rcar_du_group *rgrp;
struct rcar_du_crtc *crtc;
unsigned int index;
int ret;
if (!rcar_du_has(rcdu, RCAR_DU_FEATURE_EXT_CTRL_REGS))
return 0;
index = rcdu->info->gen < 3 ? 0 : DIV_ROUND_UP(rcdu->num_crtcs, 2) - 1;
rgrp = &rcdu->groups[index];
crtc = &rcdu->crtcs[index * 2];
ret = clk_prepare_enable(crtc->clock);
if (ret < 0)
return ret;
rcar_du_group_setup_defr8(rgrp);
clk_disable_unprepare(crtc->clock);
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
return rcar_du_set_dpad0_vsp1_routing(rgrp->dev);
}
