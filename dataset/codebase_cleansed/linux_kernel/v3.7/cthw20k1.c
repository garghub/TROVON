static int src_get_rsc_ctrl_blk(void **rblk)
{
struct src_rsc_ctrl_blk *blk;
*rblk = NULL;
blk = kzalloc(sizeof(*blk), GFP_KERNEL);
if (!blk)
return -ENOMEM;
*rblk = blk;
return 0;
}
static int src_put_rsc_ctrl_blk(void *blk)
{
kfree((struct src_rsc_ctrl_blk *)blk);
return 0;
}
static int src_set_state(void *blk, unsigned int state)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_STATE, state);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_bm(void *blk, unsigned int bm)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_BM, bm);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_rsr(void *blk, unsigned int rsr)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_RSR, rsr);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_sf(void *blk, unsigned int sf)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_SF, sf);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_wr(void *blk, unsigned int wr)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_WR, wr);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_pm(void *blk, unsigned int pm)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_PM, pm);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_rom(void *blk, unsigned int rom)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_ROM, rom);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_vo(void *blk, unsigned int vo)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_VO, vo);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_st(void *blk, unsigned int st)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_ST, st);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_ie(void *blk, unsigned int ie)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_IE, ie);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_ilsz(void *blk, unsigned int ilsz)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_ILSZ, ilsz);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_bp(void *blk, unsigned int bp)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ctl, SRCCTL_BP, bp);
ctl->dirty.bf.ctl = 1;
return 0;
}
static int src_set_cisz(void *blk, unsigned int cisz)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ccr, SRCCCR_CISZ, cisz);
ctl->dirty.bf.ccr = 1;
return 0;
}
static int src_set_ca(void *blk, unsigned int ca)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->ca, SRCCA_CA, ca);
ctl->dirty.bf.ca = 1;
return 0;
}
static int src_set_sa(void *blk, unsigned int sa)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->sa, SRCSA_SA, sa);
ctl->dirty.bf.sa = 1;
return 0;
}
static int src_set_la(void *blk, unsigned int la)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->la, SRCLA_LA, la);
ctl->dirty.bf.la = 1;
return 0;
}
static int src_set_pitch(void *blk, unsigned int pitch)
{
struct src_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->mpr, MPRLH_PITCH, pitch);
ctl->dirty.bf.mpr = 1;
return 0;
}
static int src_set_clear_zbufs(void *blk, unsigned int clear)
{
((struct src_rsc_ctrl_blk *)blk)->dirty.bf.czbfs = (clear ? 1 : 0);
return 0;
}
static int src_set_dirty(void *blk, unsigned int flags)
{
((struct src_rsc_ctrl_blk *)blk)->dirty.data = (flags & 0xffff);
return 0;
}
static int src_set_dirty_all(void *blk)
{
((struct src_rsc_ctrl_blk *)blk)->dirty.data = ~(0x0);
return 0;
}
static unsigned int src_param_pitch_mixer(unsigned int src_idx)
{
return ((src_idx << 4) + AR_PTS_PITCH + AR_SLOT_SIZE
- AR_PARAM_SRC_OFFSET) % AR_SLOT_SIZE;
}
static int src_commit_write(struct hw *hw, unsigned int idx, void *blk)
{
struct src_rsc_ctrl_blk *ctl = blk;
int i;
if (ctl->dirty.bf.czbfs) {
for (i = 0; i < 8; i++)
hw_write_20kx(hw, SRCUPZ+idx*0x100+i*0x4, 0);
for (i = 0; i < 4; i++)
hw_write_20kx(hw, SRCDN0Z+idx*0x100+i*0x4, 0);
for (i = 0; i < 8; i++)
hw_write_20kx(hw, SRCDN1Z+idx*0x100+i*0x4, 0);
ctl->dirty.bf.czbfs = 0;
}
if (ctl->dirty.bf.mpr) {
unsigned int pm_idx = src_param_pitch_mixer(idx);
hw_write_20kx(hw, PRING_LO_HI+4*pm_idx, ctl->mpr);
hw_write_20kx(hw, PMOPLO+8*pm_idx, 0x3);
hw_write_20kx(hw, PMOPHI+8*pm_idx, 0x0);
ctl->dirty.bf.mpr = 0;
}
if (ctl->dirty.bf.sa) {
hw_write_20kx(hw, SRCSA+idx*0x100, ctl->sa);
ctl->dirty.bf.sa = 0;
}
if (ctl->dirty.bf.la) {
hw_write_20kx(hw, SRCLA+idx*0x100, ctl->la);
ctl->dirty.bf.la = 0;
}
if (ctl->dirty.bf.ca) {
hw_write_20kx(hw, SRCCA+idx*0x100, ctl->ca);
ctl->dirty.bf.ca = 0;
}
hw_write_20kx(hw, SRCCF+idx*0x100, 0x0);
if (ctl->dirty.bf.ccr) {
hw_write_20kx(hw, SRCCCR+idx*0x100, ctl->ccr);
ctl->dirty.bf.ccr = 0;
}
if (ctl->dirty.bf.ctl) {
hw_write_20kx(hw, SRCCTL+idx*0x100, ctl->ctl);
ctl->dirty.bf.ctl = 0;
}
return 0;
}
static int src_get_ca(struct hw *hw, unsigned int idx, void *blk)
{
struct src_rsc_ctrl_blk *ctl = blk;
ctl->ca = hw_read_20kx(hw, SRCCA+idx*0x100);
ctl->dirty.bf.ca = 0;
return get_field(ctl->ca, SRCCA_CA);
}
static unsigned int src_get_dirty(void *blk)
{
return ((struct src_rsc_ctrl_blk *)blk)->dirty.data;
}
static unsigned int src_dirty_conj_mask(void)
{
return 0x20;
}
static int src_mgr_enbs_src(void *blk, unsigned int idx)
{
((struct src_mgr_ctrl_blk *)blk)->enbsa = ~(0x0);
((struct src_mgr_ctrl_blk *)blk)->dirty.bf.enbsa = 1;
((struct src_mgr_ctrl_blk *)blk)->enb[idx/32] |= (0x1 << (idx%32));
return 0;
}
static int src_mgr_enb_src(void *blk, unsigned int idx)
{
((struct src_mgr_ctrl_blk *)blk)->enb[idx/32] |= (0x1 << (idx%32));
((struct src_mgr_ctrl_blk *)blk)->dirty.data |= (0x1 << (idx/32));
return 0;
}
static int src_mgr_dsb_src(void *blk, unsigned int idx)
{
((struct src_mgr_ctrl_blk *)blk)->enb[idx/32] &= ~(0x1 << (idx%32));
((struct src_mgr_ctrl_blk *)blk)->dirty.data |= (0x1 << (idx/32));
return 0;
}
static int src_mgr_commit_write(struct hw *hw, void *blk)
{
struct src_mgr_ctrl_blk *ctl = blk;
int i;
unsigned int ret;
if (ctl->dirty.bf.enbsa) {
do {
ret = hw_read_20kx(hw, SRCENBSTAT);
} while (ret & 0x1);
hw_write_20kx(hw, SRCENBS, ctl->enbsa);
ctl->dirty.bf.enbsa = 0;
}
for (i = 0; i < 8; i++) {
if ((ctl->dirty.data & (0x1 << i))) {
hw_write_20kx(hw, SRCENB+(i*0x100), ctl->enb[i]);
ctl->dirty.data &= ~(0x1 << i);
}
}
return 0;
}
static int src_mgr_get_ctrl_blk(void **rblk)
{
struct src_mgr_ctrl_blk *blk;
*rblk = NULL;
blk = kzalloc(sizeof(*blk), GFP_KERNEL);
if (!blk)
return -ENOMEM;
*rblk = blk;
return 0;
}
static int src_mgr_put_ctrl_blk(void *blk)
{
kfree((struct src_mgr_ctrl_blk *)blk);
return 0;
}
static int srcimp_mgr_get_ctrl_blk(void **rblk)
{
struct srcimp_mgr_ctrl_blk *blk;
*rblk = NULL;
blk = kzalloc(sizeof(*blk), GFP_KERNEL);
if (!blk)
return -ENOMEM;
*rblk = blk;
return 0;
}
static int srcimp_mgr_put_ctrl_blk(void *blk)
{
kfree((struct srcimp_mgr_ctrl_blk *)blk);
return 0;
}
static int srcimp_mgr_set_imaparc(void *blk, unsigned int slot)
{
struct srcimp_mgr_ctrl_blk *ctl = blk;
set_field(&ctl->srcimap.srcaim, SRCAIM_ARC, slot);
ctl->dirty.bf.srcimap = 1;
return 0;
}
static int srcimp_mgr_set_imapuser(void *blk, unsigned int user)
{
struct srcimp_mgr_ctrl_blk *ctl = blk;
set_field(&ctl->srcimap.srcaim, SRCAIM_SRC, user);
ctl->dirty.bf.srcimap = 1;
return 0;
}
static int srcimp_mgr_set_imapnxt(void *blk, unsigned int next)
{
struct srcimp_mgr_ctrl_blk *ctl = blk;
set_field(&ctl->srcimap.srcaim, SRCAIM_NXT, next);
ctl->dirty.bf.srcimap = 1;
return 0;
}
static int srcimp_mgr_set_imapaddr(void *blk, unsigned int addr)
{
struct srcimp_mgr_ctrl_blk *ctl = blk;
ctl->srcimap.idx = addr;
ctl->dirty.bf.srcimap = 1;
return 0;
}
static int srcimp_mgr_commit_write(struct hw *hw, void *blk)
{
struct srcimp_mgr_ctrl_blk *ctl = blk;
if (ctl->dirty.bf.srcimap) {
hw_write_20kx(hw, SRCIMAP+ctl->srcimap.idx*0x100,
ctl->srcimap.srcaim);
ctl->dirty.bf.srcimap = 0;
}
return 0;
}
static int amixer_set_mode(void *blk, unsigned int mode)
{
struct amixer_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->amoplo, AMOPLO_M, mode);
ctl->dirty.bf.amoplo = 1;
return 0;
}
static int amixer_set_iv(void *blk, unsigned int iv)
{
return 0;
}
static int amixer_set_x(void *blk, unsigned int x)
{
struct amixer_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->amoplo, AMOPLO_X, x);
ctl->dirty.bf.amoplo = 1;
return 0;
}
static int amixer_set_y(void *blk, unsigned int y)
{
struct amixer_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->amoplo, AMOPLO_Y, y);
ctl->dirty.bf.amoplo = 1;
return 0;
}
static int amixer_set_sadr(void *blk, unsigned int sadr)
{
struct amixer_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->amophi, AMOPHI_SADR, sadr);
ctl->dirty.bf.amophi = 1;
return 0;
}
static int amixer_set_se(void *blk, unsigned int se)
{
struct amixer_rsc_ctrl_blk *ctl = blk;
set_field(&ctl->amophi, AMOPHI_SE, se);
ctl->dirty.bf.amophi = 1;
return 0;
}
static int amixer_set_dirty(void *blk, unsigned int flags)
{
((struct amixer_rsc_ctrl_blk *)blk)->dirty.data = (flags & 0xffff);
return 0;
}
static int amixer_set_dirty_all(void *blk)
{
((struct amixer_rsc_ctrl_blk *)blk)->dirty.data = ~(0x0);
return 0;
}
static int amixer_commit_write(struct hw *hw, unsigned int idx, void *blk)
{
struct amixer_rsc_ctrl_blk *ctl = blk;
if (ctl->dirty.bf.amoplo || ctl->dirty.bf.amophi) {
hw_write_20kx(hw, AMOPLO+idx*8, ctl->amoplo);
ctl->dirty.bf.amoplo = 0;
hw_write_20kx(hw, AMOPHI+idx*8, ctl->amophi);
ctl->dirty.bf.amophi = 0;
}
return 0;
}
static int amixer_get_y(void *blk)
{
struct amixer_rsc_ctrl_blk *ctl = blk;
return get_field(ctl->amoplo, AMOPLO_Y);
}
static unsigned int amixer_get_dirty(void *blk)
{
return ((struct amixer_rsc_ctrl_blk *)blk)->dirty.data;
}
static int amixer_rsc_get_ctrl_blk(void **rblk)
{
struct amixer_rsc_ctrl_blk *blk;
*rblk = NULL;
blk = kzalloc(sizeof(*blk), GFP_KERNEL);
if (!blk)
return -ENOMEM;
*rblk = blk;
return 0;
}
static int amixer_rsc_put_ctrl_blk(void *blk)
{
kfree((struct amixer_rsc_ctrl_blk *)blk);
return 0;
}
static int amixer_mgr_get_ctrl_blk(void **rblk)
{
*rblk = NULL;
return 0;
}
static int amixer_mgr_put_ctrl_blk(void *blk)
{
return 0;
}
static int dai_srt_set_srcr(void *blk, unsigned int src)
{
struct dai_ctrl_blk *ctl = blk;
set_field(&ctl->srtctl, SRTCTL_SRCR, src);
ctl->dirty.bf.srtctl = 1;
return 0;
}
static int dai_srt_set_srcl(void *blk, unsigned int src)
{
struct dai_ctrl_blk *ctl = blk;
set_field(&ctl->srtctl, SRTCTL_SRCL, src);
ctl->dirty.bf.srtctl = 1;
return 0;
}
static int dai_srt_set_rsr(void *blk, unsigned int rsr)
{
struct dai_ctrl_blk *ctl = blk;
set_field(&ctl->srtctl, SRTCTL_RSR, rsr);
ctl->dirty.bf.srtctl = 1;
return 0;
}
static int dai_srt_set_drat(void *blk, unsigned int drat)
{
struct dai_ctrl_blk *ctl = blk;
set_field(&ctl->srtctl, SRTCTL_DRAT, drat);
ctl->dirty.bf.srtctl = 1;
return 0;
}
static int dai_srt_set_ec(void *blk, unsigned int ec)
{
struct dai_ctrl_blk *ctl = blk;
set_field(&ctl->srtctl, SRTCTL_EC, ec ? 1 : 0);
ctl->dirty.bf.srtctl = 1;
return 0;
}
static int dai_srt_set_et(void *blk, unsigned int et)
{
struct dai_ctrl_blk *ctl = blk;
set_field(&ctl->srtctl, SRTCTL_ET, et ? 1 : 0);
ctl->dirty.bf.srtctl = 1;
return 0;
}
static int dai_commit_write(struct hw *hw, unsigned int idx, void *blk)
{
struct dai_ctrl_blk *ctl = blk;
if (ctl->dirty.bf.srtctl) {
if (idx < 4) {
hw_write_20kx(hw, SRTSCTL+0x4*idx, ctl->srtctl);
} else {
hw_write_20kx(hw, SRTICTL, ctl->srtctl);
}
ctl->dirty.bf.srtctl = 0;
}
return 0;
}
static int dai_get_ctrl_blk(void **rblk)
{
struct dai_ctrl_blk *blk;
*rblk = NULL;
blk = kzalloc(sizeof(*blk), GFP_KERNEL);
if (!blk)
return -ENOMEM;
*rblk = blk;
return 0;
}
static int dai_put_ctrl_blk(void *blk)
{
kfree((struct dai_ctrl_blk *)blk);
return 0;
}
static int dao_set_spos(void *blk, unsigned int spos)
{
((struct dao_ctrl_blk *)blk)->spos = spos;
((struct dao_ctrl_blk *)blk)->dirty.bf.spos = 1;
return 0;
}
static int dao_commit_write(struct hw *hw, unsigned int idx, void *blk)
{
struct dao_ctrl_blk *ctl = blk;
if (ctl->dirty.bf.spos) {
if (idx < 4) {
hw_write_20kx(hw, SPOS+0x4*idx, ctl->spos);
}
ctl->dirty.bf.spos = 0;
}
return 0;
}
static int dao_get_spos(void *blk, unsigned int *spos)
{
*spos = ((struct dao_ctrl_blk *)blk)->spos;
return 0;
}
static int dao_get_ctrl_blk(void **rblk)
{
struct dao_ctrl_blk *blk;
*rblk = NULL;
blk = kzalloc(sizeof(*blk), GFP_KERNEL);
if (!blk)
return -ENOMEM;
*rblk = blk;
return 0;
}
static int dao_put_ctrl_blk(void *blk)
{
kfree((struct dao_ctrl_blk *)blk);
return 0;
}
static int daio_mgr_enb_dai(void *blk, unsigned int idx)
{
struct daio_mgr_ctrl_blk *ctl = blk;
if (idx < 4) {
set_field(&ctl->spictl, SPICTL_EN << (idx*8), 1);
ctl->dirty.bf.spictl |= (0x1 << idx);
} else {
idx %= 4;
set_field(&ctl->i2sctl, I2SCTL_EI << (idx*8), 1);
ctl->dirty.bf.i2sictl |= (0x1 << idx);
}
return 0;
}
static int daio_mgr_dsb_dai(void *blk, unsigned int idx)
{
struct daio_mgr_ctrl_blk *ctl = blk;
if (idx < 4) {
set_field(&ctl->spictl, SPICTL_EN << (idx*8), 0);
ctl->dirty.bf.spictl |= (0x1 << idx);
} else {
idx %= 4;
set_field(&ctl->i2sctl, I2SCTL_EI << (idx*8), 0);
ctl->dirty.bf.i2sictl |= (0x1 << idx);
}
return 0;
}
static int daio_mgr_enb_dao(void *blk, unsigned int idx)
{
struct daio_mgr_ctrl_blk *ctl = blk;
if (idx < 4) {
set_field(&ctl->spoctl, SPOCTL_OE << (idx*8), 1);
ctl->dirty.bf.spoctl |= (0x1 << idx);
} else {
idx %= 4;
set_field(&ctl->i2sctl, I2SCTL_EA << (idx*8), 1);
ctl->dirty.bf.i2soctl |= (0x1 << idx);
}
return 0;
}
static int daio_mgr_dsb_dao(void *blk, unsigned int idx)
{
struct daio_mgr_ctrl_blk *ctl = blk;
if (idx < 4) {
set_field(&ctl->spoctl, SPOCTL_OE << (idx*8), 0);
ctl->dirty.bf.spoctl |= (0x1 << idx);
} else {
idx %= 4;
set_field(&ctl->i2sctl, I2SCTL_EA << (idx*8), 0);
ctl->dirty.bf.i2soctl |= (0x1 << idx);
}
return 0;
}
static int daio_mgr_dao_init(void *blk, unsigned int idx, unsigned int conf)
{
struct daio_mgr_ctrl_blk *ctl = blk;
if (idx < 4) {
switch ((conf & 0x7)) {
case 0:
set_field(&ctl->spoctl, SPOCTL_SR << (idx*8), 3);
break;
case 1:
set_field(&ctl->spoctl, SPOCTL_SR << (idx*8), 0);
break;
case 2:
set_field(&ctl->spoctl, SPOCTL_SR << (idx*8), 1);
break;
case 4:
set_field(&ctl->spoctl, SPOCTL_SR << (idx*8), 2);
break;
default:
break;
}
set_field(&ctl->spoctl, SPOCTL_LIV << (idx*8),
(conf >> 4) & 0x1);
set_field(&ctl->spoctl, SPOCTL_RIV << (idx*8),
(conf >> 4) & 0x1);
set_field(&ctl->spoctl, SPOCTL_OS << (idx*8),
((conf >> 3) & 0x1) ? 2 : 2);
ctl->dirty.bf.spoctl |= (0x1 << idx);
} else {
}
return 0;
}
static int daio_mgr_set_imaparc(void *blk, unsigned int slot)
{
struct daio_mgr_ctrl_blk *ctl = blk;
set_field(&ctl->daoimap.aim, AIM_ARC, slot);
ctl->dirty.bf.daoimap = 1;
return 0;
}
static int daio_mgr_set_imapnxt(void *blk, unsigned int next)
{
struct daio_mgr_ctrl_blk *ctl = blk;
set_field(&ctl->daoimap.aim, AIM_NXT, next);
ctl->dirty.bf.daoimap = 1;
return 0;
}
static int daio_mgr_set_imapaddr(void *blk, unsigned int addr)
{
struct daio_mgr_ctrl_blk *ctl = blk;
ctl->daoimap.idx = addr;
ctl->dirty.bf.daoimap = 1;
return 0;
}
static int daio_mgr_commit_write(struct hw *hw, void *blk)
{
struct daio_mgr_ctrl_blk *ctl = blk;
int i;
if (ctl->dirty.bf.i2sictl || ctl->dirty.bf.i2soctl) {
for (i = 0; i < 4; i++) {
if ((ctl->dirty.bf.i2sictl & (0x1 << i)))
ctl->dirty.bf.i2sictl &= ~(0x1 << i);
if ((ctl->dirty.bf.i2soctl & (0x1 << i)))
ctl->dirty.bf.i2soctl &= ~(0x1 << i);
}
hw_write_20kx(hw, I2SCTL, ctl->i2sctl);
mdelay(1);
}
if (ctl->dirty.bf.spoctl) {
for (i = 0; i < 4; i++) {
if ((ctl->dirty.bf.spoctl & (0x1 << i)))
ctl->dirty.bf.spoctl &= ~(0x1 << i);
}
hw_write_20kx(hw, SPOCTL, ctl->spoctl);
mdelay(1);
}
if (ctl->dirty.bf.spictl) {
for (i = 0; i < 4; i++) {
if ((ctl->dirty.bf.spictl & (0x1 << i)))
ctl->dirty.bf.spictl &= ~(0x1 << i);
}
hw_write_20kx(hw, SPICTL, ctl->spictl);
mdelay(1);
}
if (ctl->dirty.bf.daoimap) {
hw_write_20kx(hw, DAOIMAP+ctl->daoimap.idx*4,
ctl->daoimap.aim);
ctl->dirty.bf.daoimap = 0;
}
return 0;
}
static int daio_mgr_get_ctrl_blk(struct hw *hw, void **rblk)
{
struct daio_mgr_ctrl_blk *blk;
*rblk = NULL;
blk = kzalloc(sizeof(*blk), GFP_KERNEL);
if (!blk)
return -ENOMEM;
blk->i2sctl = hw_read_20kx(hw, I2SCTL);
blk->spoctl = hw_read_20kx(hw, SPOCTL);
blk->spictl = hw_read_20kx(hw, SPICTL);
*rblk = blk;
return 0;
}
static int daio_mgr_put_ctrl_blk(void *blk)
{
kfree((struct daio_mgr_ctrl_blk *)blk);
return 0;
}
static int set_timer_irq(struct hw *hw, int enable)
{
hw_write_20kx(hw, GIE, enable ? IT_INT : 0);
return 0;
}
static int set_timer_tick(struct hw *hw, unsigned int ticks)
{
if (ticks)
ticks |= TIMR_IE | TIMR_IP;
hw_write_20kx(hw, TIMR, ticks);
return 0;
}
static unsigned int get_wc(struct hw *hw)
{
return hw_read_20kx(hw, WC);
}
static int hw_daio_init(struct hw *hw, const struct daio_conf *info)
{
u32 i2sorg;
u32 spdorg;
i2sorg = 0x94040404;
i2sorg &= 0xfffffffc;
hw_write_20kx(hw, SPOCTL, 0x0);
spdorg = 0x05;
switch (info->msr) {
case 1:
i2sorg |= 1;
spdorg |= (0x0 << 6);
break;
case 2:
i2sorg |= 2;
spdorg |= (0x1 << 6);
break;
case 4:
i2sorg |= 3;
spdorg |= (0x2 << 6);
break;
default:
i2sorg |= 1;
break;
}
hw_write_20kx(hw, I2SCTL, i2sorg);
hw_write_20kx(hw, SPOCTL, spdorg);
hw_write_20kx(hw, SPICTL, 0x0);
mdelay(1);
spdorg = 0x0a0a0a0a;
hw_write_20kx(hw, SPICTL, spdorg);
mdelay(1);
return 0;
}
static int hw_trn_init(struct hw *hw, const struct trn_conf *info)
{
u32 trnctl;
u32 ptp_phys_low, ptp_phys_high;
if ((~0UL) == info->vm_pgt_phys) {
printk(KERN_ERR "Wrong device page table page address!\n");
return -1;
}
trnctl = 0x13;
ptp_phys_low = (u32)info->vm_pgt_phys;
ptp_phys_high = upper_32_bits(info->vm_pgt_phys);
if (sizeof(void *) == 8)
trnctl |= (1 << 2);
#if 0
#if PAGE_SIZE == 8192
trnctl |= (1<<5);
#endif
#endif
hw_write_20kx(hw, PTPALX, ptp_phys_low);
hw_write_20kx(hw, PTPAHX, ptp_phys_high);
hw_write_20kx(hw, TRNCTL, trnctl);
hw_write_20kx(hw, TRNIS, 0x200c01);
return 0;
}
static int hw_pll_init(struct hw *hw, unsigned int rsr)
{
unsigned int pllctl;
int i;
pllctl = (48000 == rsr) ? 0x1480a001 : 0x1480a731;
for (i = 0; i < 3; i++) {
if (hw_read_20kx(hw, PLLCTL) == pllctl)
break;
hw_write_20kx(hw, PLLCTL, pllctl);
mdelay(40);
}
if (i >= 3) {
printk(KERN_ALERT "PLL initialization failed!!!\n");
return -EBUSY;
}
return 0;
}
static int hw_auto_init(struct hw *hw)
{
unsigned int gctl;
int i;
gctl = hw_read_20kx(hw, GCTL);
set_field(&gctl, GCTL_EAI, 0);
hw_write_20kx(hw, GCTL, gctl);
set_field(&gctl, GCTL_EAI, 1);
hw_write_20kx(hw, GCTL, gctl);
mdelay(10);
for (i = 0; i < 400000; i++) {
gctl = hw_read_20kx(hw, GCTL);
if (get_field(gctl, GCTL_AID))
break;
}
if (!get_field(gctl, GCTL_AID)) {
printk(KERN_ALERT "Card Auto-init failed!!!\n");
return -EBUSY;
}
return 0;
}
static int i2c_unlock(struct hw *hw)
{
if ((hw_read_pci(hw, 0xcc) & 0xff) == 0xaa)
return 0;
hw_write_pci(hw, 0xcc, 0x8c);
hw_write_pci(hw, 0xcc, 0x0e);
if ((hw_read_pci(hw, 0xcc) & 0xff) == 0xaa)
return 0;
hw_write_pci(hw, 0xcc, 0xee);
hw_write_pci(hw, 0xcc, 0xaa);
if ((hw_read_pci(hw, 0xcc) & 0xff) == 0xaa)
return 0;
return -1;
}
static void i2c_lock(struct hw *hw)
{
if ((hw_read_pci(hw, 0xcc) & 0xff) == 0xaa)
hw_write_pci(hw, 0xcc, 0x00);
}
static void i2c_write(struct hw *hw, u32 device, u32 addr, u32 data)
{
unsigned int ret;
do {
ret = hw_read_pci(hw, 0xEC);
} while (!(ret & 0x800000));
hw_write_pci(hw, 0xE0, device);
hw_write_pci(hw, 0xE4, (data << 8) | (addr & 0xff));
}
static int hw_reset_dac(struct hw *hw)
{
u32 i;
u16 gpioorg;
unsigned int ret;
if (i2c_unlock(hw))
return -1;
do {
ret = hw_read_pci(hw, 0xEC);
} while (!(ret & 0x800000));
hw_write_pci(hw, 0xEC, 0x05);
for (i = 0; i < 2; i++) {
mdelay(100);
gpioorg = (u16)hw_read_20kx(hw, GPIO);
gpioorg &= 0xfffd;
hw_write_20kx(hw, GPIO, gpioorg);
mdelay(1);
hw_write_20kx(hw, GPIO, gpioorg | 0x2);
}
i2c_write(hw, 0x00180080, 0x01, 0x80);
i2c_write(hw, 0x00180080, 0x02, 0x10);
i2c_lock(hw);
return 0;
}
static int hw_dac_init(struct hw *hw, const struct dac_conf *info)
{
u32 data;
u16 gpioorg;
unsigned int ret;
if (hw->model == CTSB055X) {
gpioorg = (u16)hw_read_20kx(hw, GPIO);
gpioorg &= 0xffbf;
gpioorg |= 2;
hw_write_20kx(hw, GPIO, gpioorg);
return 0;
}
gpioorg = (u16)hw_read_20kx(hw, GPIO);
gpioorg &= 0xffbf;
hw_write_20kx(hw, GPIO, gpioorg);
hw_reset_dac(hw);
if (i2c_unlock(hw))
return -1;
hw_write_pci(hw, 0xEC, 0x05);
do {
ret = hw_read_pci(hw, 0xEC);
} while (!(ret & 0x800000));
switch (info->msr) {
case 1:
data = 0x24;
break;
case 2:
data = 0x25;
break;
case 4:
data = 0x26;
break;
default:
data = 0x24;
break;
}
i2c_write(hw, 0x00180080, 0x06, data);
i2c_write(hw, 0x00180080, 0x09, data);
i2c_write(hw, 0x00180080, 0x0c, data);
i2c_write(hw, 0x00180080, 0x0f, data);
i2c_lock(hw);
gpioorg = (u16)hw_read_20kx(hw, GPIO);
gpioorg = gpioorg | 0x40;
hw_write_20kx(hw, GPIO, gpioorg);
return 0;
}
static int is_adc_input_selected_SB055x(struct hw *hw, enum ADCSRC type)
{
return 0;
}
static int is_adc_input_selected_SBx(struct hw *hw, enum ADCSRC type)
{
u32 data;
data = hw_read_20kx(hw, GPIO);
switch (type) {
case ADC_MICIN:
data = ((data & (0x1<<7)) && (data & (0x1<<8)));
break;
case ADC_LINEIN:
data = (!(data & (0x1<<7)) && (data & (0x1<<8)));
break;
case ADC_NONE:
data = (!(data & (0x1<<8)));
break;
default:
data = 0;
}
return data;
}
static int is_adc_input_selected_hendrix(struct hw *hw, enum ADCSRC type)
{
u32 data;
data = hw_read_20kx(hw, GPIO);
switch (type) {
case ADC_MICIN:
data = (data & (0x1 << 7)) ? 1 : 0;
break;
case ADC_LINEIN:
data = (data & (0x1 << 7)) ? 0 : 1;
break;
default:
data = 0;
}
return data;
}
static int hw_is_adc_input_selected(struct hw *hw, enum ADCSRC type)
{
switch (hw->model) {
case CTSB055X:
return is_adc_input_selected_SB055x(hw, type);
case CTSB073X:
return is_adc_input_selected_hendrix(hw, type);
case CTUAA:
return is_adc_input_selected_hendrix(hw, type);
default:
return is_adc_input_selected_SBx(hw, type);
}
}
static int
adc_input_select_SB055x(struct hw *hw, enum ADCSRC type, unsigned char boost)
{
u32 data;
data = hw_read_20kx(hw, GPIO);
data &= 0xec73;
switch (type) {
case ADC_MICIN:
data |= (0x1<<7) | (0x1<<8) | (0x1<<9) ;
data |= boost ? (0x1<<2) : 0;
break;
case ADC_LINEIN:
data |= (0x1<<8);
break;
case ADC_AUX:
data |= (0x1<<8) | (0x1<<12);
break;
case ADC_NONE:
data |= (0x1<<12);
break;
default:
return -1;
}
hw_write_20kx(hw, GPIO, data);
return 0;
}
static int
adc_input_select_SBx(struct hw *hw, enum ADCSRC type, unsigned char boost)
{
u32 data;
u32 i2c_data;
unsigned int ret;
if (i2c_unlock(hw))
return -1;
do {
ret = hw_read_pci(hw, 0xEC);
} while (!(ret & 0x800000));
hw_write_pci(hw, 0xEC, 0x05);
data = hw_read_20kx(hw, GPIO);
switch (type) {
case ADC_MICIN:
data |= ((0x1 << 7) | (0x1 << 8));
i2c_data = 0x1;
break;
case ADC_LINEIN:
data &= ~(0x1 << 7);
data |= (0x1 << 8);
i2c_data = 0x2;
break;
case ADC_NONE:
data &= ~(0x1 << 8);
i2c_data = 0x0;
break;
default:
i2c_lock(hw);
return -1;
}
hw_write_20kx(hw, GPIO, data);
i2c_write(hw, 0x001a0080, 0x2a, i2c_data);
if (boost) {
i2c_write(hw, 0x001a0080, 0x1c, 0xe7);
i2c_write(hw, 0x001a0080, 0x1e, 0xe7);
} else {
i2c_write(hw, 0x001a0080, 0x1c, 0xcf);
i2c_write(hw, 0x001a0080, 0x1e, 0xcf);
}
i2c_lock(hw);
return 0;
}
static int
adc_input_select_hendrix(struct hw *hw, enum ADCSRC type, unsigned char boost)
{
u32 data;
u32 i2c_data;
unsigned int ret;
if (i2c_unlock(hw))
return -1;
do {
ret = hw_read_pci(hw, 0xEC);
} while (!(ret & 0x800000));
hw_write_pci(hw, 0xEC, 0x05);
data = hw_read_20kx(hw, GPIO);
switch (type) {
case ADC_MICIN:
data |= (0x1 << 7);
i2c_data = 0x1;
break;
case ADC_LINEIN:
data &= ~(0x1 << 7);
i2c_data = 0x2;
break;
default:
i2c_lock(hw);
return -1;
}
hw_write_20kx(hw, GPIO, data);
i2c_write(hw, 0x001a0080, 0x2a, i2c_data);
if (boost) {
i2c_write(hw, 0x001a0080, 0x1c, 0xe7);
i2c_write(hw, 0x001a0080, 0x1e, 0xe7);
} else {
i2c_write(hw, 0x001a0080, 0x1c, 0xcf);
i2c_write(hw, 0x001a0080, 0x1e, 0xcf);
}
i2c_lock(hw);
return 0;
}
static int hw_adc_input_select(struct hw *hw, enum ADCSRC type)
{
int state = type == ADC_MICIN;
switch (hw->model) {
case CTSB055X:
return adc_input_select_SB055x(hw, type, state);
case CTSB073X:
return adc_input_select_hendrix(hw, type, state);
case CTUAA:
return adc_input_select_hendrix(hw, type, state);
default:
return adc_input_select_SBx(hw, type, state);
}
}
static int adc_init_SB055x(struct hw *hw, int input, int mic20db)
{
return adc_input_select_SB055x(hw, input, mic20db);
}
static int adc_init_SBx(struct hw *hw, int input, int mic20db)
{
u16 gpioorg;
u16 input_source;
u32 adcdata;
unsigned int ret;
input_source = 0x100;
switch (input) {
case ADC_MICIN:
adcdata = 0x1;
input_source = 0x180;
break;
case ADC_LINEIN:
adcdata = 0x2;
break;
case ADC_VIDEO:
adcdata = 0x4;
break;
case ADC_AUX:
adcdata = 0x8;
break;
case ADC_NONE:
adcdata = 0x0;
input_source = 0x0;
break;
default:
adcdata = 0x0;
break;
}
if (i2c_unlock(hw))
return -1;
do {
ret = hw_read_pci(hw, 0xEC);
} while (!(ret & 0x800000));
hw_write_pci(hw, 0xEC, 0x05);
i2c_write(hw, 0x001a0080, 0x0e, 0x08);
i2c_write(hw, 0x001a0080, 0x18, 0x0a);
i2c_write(hw, 0x001a0080, 0x28, 0x86);
i2c_write(hw, 0x001a0080, 0x2a, adcdata);
if (mic20db) {
i2c_write(hw, 0x001a0080, 0x1c, 0xf7);
i2c_write(hw, 0x001a0080, 0x1e, 0xf7);
} else {
i2c_write(hw, 0x001a0080, 0x1c, 0xcf);
i2c_write(hw, 0x001a0080, 0x1e, 0xcf);
}
if (!(hw_read_20kx(hw, ID0) & 0x100))
i2c_write(hw, 0x001a0080, 0x16, 0x26);
i2c_lock(hw);
gpioorg = (u16)hw_read_20kx(hw, GPIO);
gpioorg &= 0xfe7f;
gpioorg |= input_source;
hw_write_20kx(hw, GPIO, gpioorg);
return 0;
}
static int hw_adc_init(struct hw *hw, const struct adc_conf *info)
{
if (hw->model == CTSB055X)
return adc_init_SB055x(hw, info->input, info->mic20db);
else
return adc_init_SBx(hw, info->input, info->mic20db);
}
static struct capabilities hw_capabilities(struct hw *hw)
{
struct capabilities cap;
cap.digit_io_switch = !(hw->model == CTSB073X || hw->model == CTUAA);
cap.dedicated_mic = 0;
cap.output_switch = 0;
cap.mic_source_switch = 0;
return cap;
}
static int uaa_to_xfi(struct pci_dev *pci)
{
unsigned int bar0, bar1, bar2, bar3, bar4, bar5;
unsigned int cmd, irq, cl_size, l_timer, pwr;
unsigned int is_uaa;
unsigned int data[4] = {0};
unsigned int io_base;
void *mem_base;
int i;
const u32 CTLX = CTLBITS('C', 'T', 'L', 'X');
const u32 CTL_ = CTLBITS('C', 'T', 'L', '-');
const u32 CTLF = CTLBITS('C', 'T', 'L', 'F');
const u32 CTLi = CTLBITS('C', 'T', 'L', 'i');
const u32 CTLA = CTLBITS('C', 'T', 'L', 'A');
const u32 CTLZ = CTLBITS('C', 'T', 'L', 'Z');
const u32 CTLL = CTLBITS('C', 'T', 'L', 'L');
io_base = pci_resource_start(pci, 0);
mem_base = ioremap(io_base, pci_resource_len(pci, 0));
if (!mem_base)
return -ENOENT;
for (i = 0; i < 4; i++)
data[i] = readl(mem_base + UAA_CORE_CHANGE);
if (data[0] == CTLA) {
is_uaa = ((data[1] == CTLZ && data[2] == CTLL
&& data[3] == CTLA) || (data[1] == CTLA
&& data[2] == CTLZ && data[3] == CTLL));
} else if (data[0] == CTLZ) {
is_uaa = (data[1] == CTLL
&& data[2] == CTLA && data[3] == CTLA);
} else if (data[0] == CTLL) {
is_uaa = (data[1] == CTLA
&& data[2] == CTLA && data[3] == CTLZ);
} else {
is_uaa = 0;
}
if (!is_uaa) {
iounmap(mem_base);
return 0;
}
pci_read_config_dword(pci, PCI_BASE_ADDRESS_0, &bar0);
pci_read_config_dword(pci, PCI_BASE_ADDRESS_1, &bar1);
pci_read_config_dword(pci, PCI_BASE_ADDRESS_2, &bar2);
pci_read_config_dword(pci, PCI_BASE_ADDRESS_3, &bar3);
pci_read_config_dword(pci, PCI_BASE_ADDRESS_4, &bar4);
pci_read_config_dword(pci, PCI_BASE_ADDRESS_5, &bar5);
pci_read_config_dword(pci, PCI_INTERRUPT_LINE, &irq);
pci_read_config_dword(pci, PCI_CACHE_LINE_SIZE, &cl_size);
pci_read_config_dword(pci, PCI_LATENCY_TIMER, &l_timer);
pci_read_config_dword(pci, UAA_CFG_PWRSTATUS, &pwr);
pci_read_config_dword(pci, PCI_COMMAND, &cmd);
pci_write_config_dword(pci, UAA_CFG_SPACE_FLAG, 0x87654321);
pci_write_config_dword(pci, PCI_BASE_ADDRESS_0, bar5);
pci_write_config_dword(pci, UAA_CFG_SPACE_FLAG, 0x12345678);
pci_write_config_dword(pci, PCI_BASE_ADDRESS_1, bar1);
pci_write_config_dword(pci, PCI_BASE_ADDRESS_2, bar2);
pci_write_config_dword(pci, PCI_BASE_ADDRESS_3, bar3);
pci_write_config_dword(pci, PCI_BASE_ADDRESS_4, bar4);
pci_write_config_dword(pci, PCI_INTERRUPT_LINE, irq);
pci_write_config_dword(pci, PCI_CACHE_LINE_SIZE, cl_size);
pci_write_config_dword(pci, PCI_LATENCY_TIMER, l_timer);
pci_write_config_dword(pci, UAA_CFG_PWRSTATUS, pwr);
pci_write_config_dword(pci, PCI_COMMAND, cmd);
writel(CTLX, (mem_base + UAA_CORE_CHANGE));
writel(CTL_, (mem_base + UAA_CORE_CHANGE));
writel(CTLF, (mem_base + UAA_CORE_CHANGE));
writel(CTLi, (mem_base + UAA_CORE_CHANGE));
iounmap(mem_base);
return 0;
}
static irqreturn_t ct_20k1_interrupt(int irq, void *dev_id)
{
struct hw *hw = dev_id;
unsigned int status;
status = hw_read_20kx(hw, GIP);
if (!status)
return IRQ_NONE;
if (hw->irq_callback)
hw->irq_callback(hw->irq_callback_data, status);
hw_write_20kx(hw, GIP, status);
return IRQ_HANDLED;
}
static int hw_card_start(struct hw *hw)
{
int err;
struct pci_dev *pci = hw->pci;
err = pci_enable_device(pci);
if (err < 0)
return err;
if (pci_set_dma_mask(pci, CT_XFI_DMA_MASK) < 0 ||
pci_set_consistent_dma_mask(pci, CT_XFI_DMA_MASK) < 0) {
printk(KERN_ERR "architecture does not support PCI "
"busmaster DMA with mask 0x%llx\n",
CT_XFI_DMA_MASK);
err = -ENXIO;
goto error1;
}
if (!hw->io_base) {
err = pci_request_regions(pci, "XFi");
if (err < 0)
goto error1;
if (hw->model == CTUAA)
hw->io_base = pci_resource_start(pci, 5);
else
hw->io_base = pci_resource_start(pci, 0);
}
if (hw->model == CTUAA) {
err = uaa_to_xfi(pci);
if (err)
goto error2;
}
if (hw->irq < 0) {
err = request_irq(pci->irq, ct_20k1_interrupt, IRQF_SHARED,
KBUILD_MODNAME, hw);
if (err < 0) {
printk(KERN_ERR "XFi: Cannot get irq %d\n", pci->irq);
goto error2;
}
hw->irq = pci->irq;
}
pci_set_master(pci);
return 0;
error2:
pci_release_regions(pci);
hw->io_base = 0;
error1:
pci_disable_device(pci);
return err;
}
static int hw_card_stop(struct hw *hw)
{
unsigned int data;
hw_write_20kx(hw, TRNCTL, 0x00);
data = hw_read_20kx(hw, PLLCTL);
hw_write_20kx(hw, PLLCTL, (data & (~(0x0F<<12))));
if (hw->irq >= 0)
synchronize_irq(hw->irq);
return 0;
}
static int hw_card_shutdown(struct hw *hw)
{
if (hw->irq >= 0)
free_irq(hw->irq, hw);
hw->irq = -1;
if (hw->mem_base)
iounmap((void *)hw->mem_base);
hw->mem_base = (unsigned long)NULL;
if (hw->io_base)
pci_release_regions(hw->pci);
hw->io_base = 0;
pci_disable_device(hw->pci);
return 0;
}
static int hw_card_init(struct hw *hw, struct card_conf *info)
{
int err;
unsigned int gctl;
u32 data;
struct dac_conf dac_info = {0};
struct adc_conf adc_info = {0};
struct daio_conf daio_info = {0};
struct trn_conf trn_info = {0};
err = hw_card_start(hw);
if (err)
return err;
err = hw_pll_init(hw, info->rsr);
if (err < 0)
return err;
err = hw_auto_init(hw);
if (err < 0)
return err;
gctl = hw_read_20kx(hw, GCTL);
set_field(&gctl, GCTL_EAC, 1);
set_field(&gctl, GCTL_DBP, 1);
set_field(&gctl, GCTL_TBP, 1);
set_field(&gctl, GCTL_FBP, 1);
set_field(&gctl, GCTL_ET, 1);
hw_write_20kx(hw, GCTL, gctl);
mdelay(10);
hw_write_20kx(hw, GIE, 0);
hw_write_20kx(hw, SRCIP, 0);
mdelay(30);
switch (hw->model) {
case CTSB055X:
hw_write_20kx(hw, GPIOCTL, 0x13fe);
break;
case CTSB073X:
hw_write_20kx(hw, GPIOCTL, 0x00e6);
break;
case CTUAA:
hw_write_20kx(hw, GPIOCTL, 0x00c2);
break;
default:
hw_write_20kx(hw, GPIOCTL, 0x01e6);
break;
}
trn_info.vm_pgt_phys = info->vm_pgt_phys;
err = hw_trn_init(hw, &trn_info);
if (err < 0)
return err;
daio_info.msr = info->msr;
err = hw_daio_init(hw, &daio_info);
if (err < 0)
return err;
dac_info.msr = info->msr;
err = hw_dac_init(hw, &dac_info);
if (err < 0)
return err;
adc_info.msr = info->msr;
adc_info.input = ADC_LINEIN;
adc_info.mic20db = 0;
err = hw_adc_init(hw, &adc_info);
if (err < 0)
return err;
data = hw_read_20kx(hw, SRCMCTL);
data |= 0x1;
hw_write_20kx(hw, SRCMCTL, data);
return 0;
}
static int hw_suspend(struct hw *hw)
{
struct pci_dev *pci = hw->pci;
hw_card_stop(hw);
if (hw->model == CTUAA) {
pci_write_config_dword(pci, UAA_CFG_SPACE_FLAG, 0x0);
}
pci_disable_device(pci);
pci_save_state(pci);
pci_set_power_state(pci, PCI_D3hot);
return 0;
}
static int hw_resume(struct hw *hw, struct card_conf *info)
{
struct pci_dev *pci = hw->pci;
pci_set_power_state(pci, PCI_D0);
pci_restore_state(pci);
return hw_card_init(hw, info);
}
static u32 hw_read_20kx(struct hw *hw, u32 reg)
{
u32 value;
unsigned long flags;
spin_lock_irqsave(
&container_of(hw, struct hw20k1, hw)->reg_20k1_lock, flags);
outl(reg, hw->io_base + 0x0);
value = inl(hw->io_base + 0x4);
spin_unlock_irqrestore(
&container_of(hw, struct hw20k1, hw)->reg_20k1_lock, flags);
return value;
}
static void hw_write_20kx(struct hw *hw, u32 reg, u32 data)
{
unsigned long flags;
spin_lock_irqsave(
&container_of(hw, struct hw20k1, hw)->reg_20k1_lock, flags);
outl(reg, hw->io_base + 0x0);
outl(data, hw->io_base + 0x4);
spin_unlock_irqrestore(
&container_of(hw, struct hw20k1, hw)->reg_20k1_lock, flags);
}
static u32 hw_read_pci(struct hw *hw, u32 reg)
{
u32 value;
unsigned long flags;
spin_lock_irqsave(
&container_of(hw, struct hw20k1, hw)->reg_pci_lock, flags);
outl(reg, hw->io_base + 0x10);
value = inl(hw->io_base + 0x14);
spin_unlock_irqrestore(
&container_of(hw, struct hw20k1, hw)->reg_pci_lock, flags);
return value;
}
static void hw_write_pci(struct hw *hw, u32 reg, u32 data)
{
unsigned long flags;
spin_lock_irqsave(
&container_of(hw, struct hw20k1, hw)->reg_pci_lock, flags);
outl(reg, hw->io_base + 0x10);
outl(data, hw->io_base + 0x14);
spin_unlock_irqrestore(
&container_of(hw, struct hw20k1, hw)->reg_pci_lock, flags);
}
int __devinit create_20k1_hw_obj(struct hw **rhw)
{
struct hw20k1 *hw20k1;
*rhw = NULL;
hw20k1 = kzalloc(sizeof(*hw20k1), GFP_KERNEL);
if (!hw20k1)
return -ENOMEM;
spin_lock_init(&hw20k1->reg_20k1_lock);
spin_lock_init(&hw20k1->reg_pci_lock);
hw20k1->hw = ct20k1_preset;
*rhw = &hw20k1->hw;
return 0;
}
int destroy_20k1_hw_obj(struct hw *hw)
{
if (hw->io_base)
hw_card_shutdown(hw);
kfree(container_of(hw, struct hw20k1, hw));
return 0;
}
