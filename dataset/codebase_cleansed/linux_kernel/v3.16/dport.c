static int
dp_set_link_config(struct dp_state *dp)
{
struct nvkm_output_dp_impl *impl = (void *)nv_oclass(dp->outp);
struct nvkm_output_dp *outp = dp->outp;
struct nouveau_disp *disp = nouveau_disp(outp);
struct nouveau_bios *bios = nouveau_bios(disp);
struct nvbios_init init = {
.subdev = nv_subdev(disp),
.bios = bios,
.offset = 0x0000,
.outp = &outp->base.info,
.crtc = -1,
.execute = 1,
};
u32 lnkcmp;
u8 sink[2];
int ret;
DBG("%d lanes at %d KB/s\n", dp->link_nr, dp->link_bw);
if ((lnkcmp = dp->outp->info.lnkcmp)) {
if (outp->version < 0x30) {
while ((dp->link_bw / 10) < nv_ro16(bios, lnkcmp))
lnkcmp += 4;
init.offset = nv_ro16(bios, lnkcmp + 2);
} else {
while ((dp->link_bw / 27000) < nv_ro08(bios, lnkcmp))
lnkcmp += 3;
init.offset = nv_ro16(bios, lnkcmp + 1);
}
nvbios_exec(&init);
}
ret = impl->lnk_ctl(outp, dp->link_nr, dp->link_bw / 27000,
outp->dpcd[DPCD_RC02] &
DPCD_RC02_ENHANCED_FRAME_CAP);
if (ret) {
if (ret < 0)
ERR("lnk_ctl failed with %d\n", ret);
return ret;
}
impl->lnk_pwr(outp, dp->link_nr);
sink[0] = dp->link_bw / 27000;
sink[1] = dp->link_nr;
if (outp->dpcd[DPCD_RC02] & DPCD_RC02_ENHANCED_FRAME_CAP)
sink[1] |= DPCD_LC01_ENHANCED_FRAME_EN;
return nv_wraux(outp->base.edid, DPCD_LC00_LINK_BW_SET, sink, 2);
}
static void
dp_set_training_pattern(struct dp_state *dp, u8 pattern)
{
struct nvkm_output_dp_impl *impl = (void *)nv_oclass(dp->outp);
struct nvkm_output_dp *outp = dp->outp;
u8 sink_tp;
DBG("training pattern %d\n", pattern);
impl->pattern(outp, pattern);
nv_rdaux(outp->base.edid, DPCD_LC02, &sink_tp, 1);
sink_tp &= ~DPCD_LC02_TRAINING_PATTERN_SET;
sink_tp |= pattern;
nv_wraux(outp->base.edid, DPCD_LC02, &sink_tp, 1);
}
static int
dp_link_train_commit(struct dp_state *dp, bool pc)
{
struct nvkm_output_dp_impl *impl = (void *)nv_oclass(dp->outp);
struct nvkm_output_dp *outp = dp->outp;
int ret, i;
for (i = 0; i < dp->link_nr; i++) {
u8 lane = (dp->stat[4 + (i >> 1)] >> ((i & 1) * 4)) & 0xf;
u8 lpc2 = (dp->pc2stat >> (i * 2)) & 0x3;
u8 lpre = (lane & 0x0c) >> 2;
u8 lvsw = (lane & 0x03) >> 0;
u8 hivs = 3 - lpre;
u8 hipe = 3;
u8 hipc = 3;
if (lpc2 >= hipc)
lpc2 = hipc | DPCD_LC0F_LANE0_MAX_POST_CURSOR2_REACHED;
if (lpre >= hipe) {
lpre = hipe | DPCD_LC03_MAX_SWING_REACHED;
lvsw = hivs = 3 - (lpre & 3);
} else
if (lvsw >= hivs) {
lvsw = hivs | DPCD_LC03_MAX_SWING_REACHED;
}
dp->conf[i] = (lpre << 3) | lvsw;
dp->pc2conf[i >> 1] |= lpc2 << ((i & 1) * 4);
DBG("config lane %d %02x %02x\n", i, dp->conf[i], lpc2);
impl->drv_ctl(outp, i, lvsw & 3, lpre & 3, lpc2 & 3);
}
ret = nv_wraux(outp->base.edid, DPCD_LC03(0), dp->conf, 4);
if (ret)
return ret;
if (pc) {
ret = nv_wraux(outp->base.edid, DPCD_LC0F, dp->pc2conf, 2);
if (ret)
return ret;
}
return 0;
}
static int
dp_link_train_update(struct dp_state *dp, bool pc, u32 delay)
{
struct nvkm_output_dp *outp = dp->outp;
int ret;
if (outp->dpcd[DPCD_RC0E_AUX_RD_INTERVAL])
mdelay(outp->dpcd[DPCD_RC0E_AUX_RD_INTERVAL] * 4);
else
udelay(delay);
ret = nv_rdaux(outp->base.edid, DPCD_LS02, dp->stat, 6);
if (ret)
return ret;
if (pc) {
ret = nv_rdaux(outp->base.edid, DPCD_LS0C, &dp->pc2stat, 1);
if (ret)
dp->pc2stat = 0x00;
DBG("status %6ph pc2 %02x\n", dp->stat, dp->pc2stat);
} else {
DBG("status %6ph\n", dp->stat);
}
return 0;
}
static int
dp_link_train_cr(struct dp_state *dp)
{
bool cr_done = false, abort = false;
int voltage = dp->conf[0] & DPCD_LC03_VOLTAGE_SWING_SET;
int tries = 0, i;
dp_set_training_pattern(dp, 1);
do {
if (dp_link_train_commit(dp, false) ||
dp_link_train_update(dp, false, 100))
break;
cr_done = true;
for (i = 0; i < dp->link_nr; i++) {
u8 lane = (dp->stat[i >> 1] >> ((i & 1) * 4)) & 0xf;
if (!(lane & DPCD_LS02_LANE0_CR_DONE)) {
cr_done = false;
if (dp->conf[i] & DPCD_LC03_MAX_SWING_REACHED)
abort = true;
break;
}
}
if ((dp->conf[0] & DPCD_LC03_VOLTAGE_SWING_SET) != voltage) {
voltage = dp->conf[0] & DPCD_LC03_VOLTAGE_SWING_SET;
tries = 0;
}
} while (!cr_done && !abort && ++tries < 5);
return cr_done ? 0 : -1;
}
static int
dp_link_train_eq(struct dp_state *dp)
{
struct nvkm_output_dp *outp = dp->outp;
bool eq_done = false, cr_done = true;
int tries = 0, i;
if (outp->dpcd[2] & DPCD_RC02_TPS3_SUPPORTED)
dp_set_training_pattern(dp, 3);
else
dp_set_training_pattern(dp, 2);
do {
if ((tries &&
dp_link_train_commit(dp, dp->pc2)) ||
dp_link_train_update(dp, dp->pc2, 400))
break;
eq_done = !!(dp->stat[2] & DPCD_LS04_INTERLANE_ALIGN_DONE);
for (i = 0; i < dp->link_nr && eq_done; i++) {
u8 lane = (dp->stat[i >> 1] >> ((i & 1) * 4)) & 0xf;
if (!(lane & DPCD_LS02_LANE0_CR_DONE))
cr_done = false;
if (!(lane & DPCD_LS02_LANE0_CHANNEL_EQ_DONE) ||
!(lane & DPCD_LS02_LANE0_SYMBOL_LOCKED))
eq_done = false;
}
} while (!eq_done && cr_done && ++tries <= 5);
return eq_done ? 0 : -1;
}
static void
dp_link_train_init(struct dp_state *dp, bool spread)
{
struct nvkm_output_dp *outp = dp->outp;
struct nouveau_disp *disp = nouveau_disp(outp);
struct nouveau_bios *bios = nouveau_bios(disp);
struct nvbios_init init = {
.subdev = nv_subdev(disp),
.bios = bios,
.outp = &outp->base.info,
.crtc = -1,
.execute = 1,
};
if (spread)
init.offset = outp->info.script[2];
else
init.offset = outp->info.script[3];
nvbios_exec(&init);
init.offset = outp->info.script[0];
nvbios_exec(&init);
}
static void
dp_link_train_fini(struct dp_state *dp)
{
struct nvkm_output_dp *outp = dp->outp;
struct nouveau_disp *disp = nouveau_disp(outp);
struct nouveau_bios *bios = nouveau_bios(disp);
struct nvbios_init init = {
.subdev = nv_subdev(disp),
.bios = bios,
.outp = &outp->base.info,
.crtc = -1,
.execute = 1,
};
init.offset = outp->info.script[1],
nvbios_exec(&init);
}
void
nouveau_dp_train(struct work_struct *w)
{
struct nvkm_output_dp *outp = container_of(w, typeof(*outp), lt.work);
struct nouveau_disp *disp = nouveau_disp(outp);
const struct dp_rates *cfg = nouveau_dp_rates;
struct dp_state _dp = {
.outp = outp,
}, *dp = &_dp;
u32 datarate = 0;
int ret;
if (nv_mclass(disp) < NVD0_DISP_CLASS)
outp->dpcd[2] &= ~DPCD_RC02_TPS3_SUPPORTED;
if ((outp->dpcd[2] & 0x1f) > outp->base.info.dpconf.link_nr) {
outp->dpcd[2] &= ~DPCD_RC02_MAX_LANE_COUNT;
outp->dpcd[2] |= outp->base.info.dpconf.link_nr;
}
if (outp->dpcd[1] > outp->base.info.dpconf.link_bw)
outp->dpcd[1] = outp->base.info.dpconf.link_bw;
dp->pc2 = outp->dpcd[2] & DPCD_RC02_TPS3_SUPPORTED;
if (datarate) {
datarate = (datarate / 8) * 10;
while (cfg[1].rate >= datarate)
cfg++;
}
cfg--;
nouveau_event_put(outp->irq);
dp_link_train_init(dp, outp->dpcd[3] & 0x01);
while (ret = -EIO, (++cfg)->rate) {
while (cfg->nr > (outp->dpcd[2] & DPCD_RC02_MAX_LANE_COUNT) ||
cfg->bw > (outp->dpcd[DPCD_RC01_MAX_LINK_RATE]))
cfg++;
dp->link_bw = cfg->bw * 27000;
dp->link_nr = cfg->nr;
ret = dp_set_link_config(dp);
if (ret == 0) {
memset(dp->stat, 0x00, sizeof(dp->stat));
if (!dp_link_train_cr(dp) &&
!dp_link_train_eq(dp))
break;
} else
if (ret) {
break;
}
}
dp_set_training_pattern(dp, 0);
if (ret < 0)
ERR("link training failed\n");
dp_link_train_fini(dp);
DBG("training complete\n");
atomic_set(&outp->lt.done, 1);
wake_up(&outp->lt.wait);
nouveau_event_get(outp->irq);
}
