static void
a3dsrc_SetTimeConsts(a3dsrc_t * a, short HrtfTrack, short ItdTrack,
short GTrack, short CTrack)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio,
a3d_addrA(a->slice, a->source, A3D_A_HrtfTrackTC), HrtfTrack);
hwwrite(vortex->mmio,
a3d_addrA(a->slice, a->source, A3D_A_ITDTrackTC), ItdTrack);
hwwrite(vortex->mmio,
a3d_addrA(a->slice, a->source, A3D_A_GainTrackTC), GTrack);
hwwrite(vortex->mmio,
a3d_addrA(a->slice, a->source, A3D_A_CoeffTrackTC), CTrack);
}
static void
a3dsrc_SetAtmosTarget(a3dsrc_t * a, short aa, short b, short c, short d,
short e)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_A21Target),
(e << 0x10) | d);
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_B10Target),
(b << 0x10) | aa);
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_B2Target), c);
}
static void
a3dsrc_SetAtmosCurrent(a3dsrc_t * a, short aa, short b, short c, short d,
short e)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_A12Current),
(e << 0x10) | d);
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_B01Current),
(b << 0x10) | aa);
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_B2Current), c);
}
static void
a3dsrc_SetAtmosState(a3dsrc_t * a, short x1, short x2, short y1, short y2)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio, a3d_addrA(a->slice, a->source, A3D_A_x1), x1);
hwwrite(vortex->mmio, a3d_addrA(a->slice, a->source, A3D_A_x2), x2);
hwwrite(vortex->mmio, a3d_addrA(a->slice, a->source, A3D_A_y1), y1);
hwwrite(vortex->mmio, a3d_addrA(a->slice, a->source, A3D_A_y2), y2);
}
static void
a3dsrc_SetHrtfTarget(a3dsrc_t * a, a3d_Hrtf_t const aa, a3d_Hrtf_t const b)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
int i;
for (i = 0; i < HRTF_SZ; i++)
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source,
A3D_B_HrtfTarget) + (i << 2),
(b[i] << 0x10) | aa[i]);
}
static void
a3dsrc_SetHrtfCurrent(a3dsrc_t * a, a3d_Hrtf_t const aa, a3d_Hrtf_t const b)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
int i;
for (i = 0; i < HRTF_SZ; i++)
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source,
A3D_B_HrtfCurrent) + (i << 2),
(b[i] << 0x10) | aa[i]);
}
static void
a3dsrc_SetHrtfState(a3dsrc_t * a, a3d_Hrtf_t const aa, a3d_Hrtf_t const b)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
int i;
for (i = 0; i < HRTF_SZ; i++)
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source,
A3D_B_HrtfDelayLine) + (i << 2),
(b[i] << 0x10) | aa[i]);
}
static void a3dsrc_SetHrtfOutput(a3dsrc_t * a, short left, short right)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio,
a3d_addrA(a->slice, a->source, A3D_A_HrtfOutL), left);
hwwrite(vortex->mmio,
a3d_addrA(a->slice, a->source, A3D_A_HrtfOutR), right);
}
static void a3dsrc_SetItdTarget(a3dsrc_t * a, short litd, short ritd)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
if (litd < 0)
litd = 0;
if (litd > 0x57FF)
litd = 0x57FF;
if (ritd < 0)
ritd = 0;
if (ritd > 0x57FF)
ritd = 0x57FF;
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_ITDTarget),
(ritd << 0x10) | litd);
}
static void a3dsrc_SetItdCurrent(a3dsrc_t * a, short litd, short ritd)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
if (litd < 0)
litd = 0;
if (litd > 0x57FF)
litd = 0x57FF;
if (ritd < 0)
ritd = 0;
if (ritd > 0x57FF)
ritd = 0x57FF;
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_ITDCurrent),
(ritd << 0x10) | litd);
}
static void a3dsrc_SetItdDline(a3dsrc_t * a, a3d_ItdDline_t const dline)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
int i;
for (i = 0; i < DLINE_SZ; i++)
hwwrite(vortex->mmio,
a3d_addrA(a->slice, a->source,
A3D_A_ITDDelayLine) + (i << 2), dline[i]);
}
static void a3dsrc_SetGainTarget(a3dsrc_t * a, short left, short right)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_GainTarget),
(right << 0x10) | left);
}
static void a3dsrc_SetGainCurrent(a3dsrc_t * a, short left, short right)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio,
a3d_addrB(a->slice, a->source, A3D_B_GainCurrent),
(right << 0x10) | left);
}
static void a3dsrc_SetA3DSampleRate(a3dsrc_t * a, int sr)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
int esp0 = 0;
esp0 = (((esp0 & 0x7fffffff) | 0xB8000000) & 0x7) | ((sr & 0x1f) << 3);
hwwrite(vortex->mmio, A3D_SLICE_Control + ((a->slice) << 0xd), esp0);
}
static void a3dsrc_EnableA3D(a3dsrc_t * a)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio, A3D_SLICE_Control + ((a->slice) << 0xd),
0xF0000001);
}
static void a3dsrc_DisableA3D(a3dsrc_t * a)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio, A3D_SLICE_Control + ((a->slice) << 0xd),
0xF0000000);
}
static void a3dsrc_SetA3DControlReg(a3dsrc_t * a, unsigned long ctrl)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio, A3D_SLICE_Control + ((a->slice) << 0xd), ctrl);
}
static void a3dsrc_SetA3DPointerReg(a3dsrc_t * a, unsigned long ptr)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
hwwrite(vortex->mmio, A3D_SLICE_Pointers + ((a->slice) << 0xd), ptr);
}
static void a3dsrc_ZeroSliceIO(a3dsrc_t * a)
{
vortex_t *vortex = (vortex_t *) (a->vortex);
int i;
for (i = 0; i < 8; i++)
hwwrite(vortex->mmio,
A3D_SLICE_VDBDest +
((((a->slice) << 0xb) + i) << 2), 0);
for (i = 0; i < 4; i++)
hwwrite(vortex->mmio,
A3D_SLICE_VDBSource +
((((a->slice) << 0xb) + i) << 2), 0);
}
static void a3dsrc_ZeroState(a3dsrc_t * a)
{
a3dsrc_SetAtmosState(a, 0, 0, 0, 0);
a3dsrc_SetHrtfState(a, A3dHrirZeros, A3dHrirZeros);
a3dsrc_SetItdDline(a, A3dItdDlineZeros);
a3dsrc_SetHrtfOutput(a, 0, 0);
a3dsrc_SetTimeConsts(a, 0, 0, 0, 0);
a3dsrc_SetAtmosCurrent(a, 0, 0, 0, 0, 0);
a3dsrc_SetAtmosTarget(a, 0, 0, 0, 0, 0);
a3dsrc_SetItdCurrent(a, 0, 0);
a3dsrc_SetItdTarget(a, 0, 0);
a3dsrc_SetGainCurrent(a, 0, 0);
a3dsrc_SetGainTarget(a, 0, 0);
a3dsrc_SetHrtfCurrent(a, A3dHrirZeros, A3dHrirZeros);
a3dsrc_SetHrtfTarget(a, A3dHrirZeros, A3dHrirZeros);
}
static void a3dsrc_ZeroStateA3D(a3dsrc_t * a)
{
int i, var, var2;
if ((a->vortex) == NULL) {
pr_err( "vortex: ZeroStateA3D: ERROR: a->vortex is NULL\n");
return;
}
a3dsrc_SetA3DControlReg(a, 0);
a3dsrc_SetA3DPointerReg(a, 0);
var = a->slice;
var2 = a->source;
for (i = 0; i < 4; i++) {
a->slice = i;
a3dsrc_ZeroSliceIO(a);
}
a->source = var2;
a->slice = var;
}
static void a3dsrc_ProgramPipe(a3dsrc_t * a)
{
a3dsrc_SetTimeConsts(a, 0, 0, 0, 0);
a3dsrc_SetAtmosCurrent(a, 0, 0x4000, 0, 0, 0);
a3dsrc_SetAtmosTarget(a, 0x4000, 0, 0, 0, 0);
a3dsrc_SetItdCurrent(a, 0, 0);
a3dsrc_SetItdTarget(a, 0, 0);
a3dsrc_SetGainCurrent(a, 0x7fff, 0x7fff);
a3dsrc_SetGainTarget(a, 0x7fff, 0x7fff);
a3dsrc_SetHrtfCurrent(a, A3dHrirImpulse, A3dHrirImpulse);
a3dsrc_SetHrtfTarget(a, A3dHrirImpulse, A3dHrirImpulse);
}
static void vortex_A3dSourceHw_Initialize(vortex_t * v, int source, int slice)
{
a3dsrc_t *a3dsrc = &(v->a3d[source + (slice * 4)]);
a3dsrc->vortex = (void *)v;
a3dsrc->source = source;
a3dsrc->slice = slice;
a3dsrc_ZeroState(a3dsrc);
a3dsrc_SetA3DSampleRate(a3dsrc, 0x11);
}
static int Vort3DRend_Initialize(vortex_t * v, unsigned short mode)
{
v->xt_mode = mode;
vortex_XtalkHw_init(v);
vortex_XtalkHw_SetGainsAllChan(v);
switch (v->xt_mode) {
case XT_SPEAKER0:
vortex_XtalkHw_ProgramXtalkNarrow(v);
break;
case XT_SPEAKER1:
vortex_XtalkHw_ProgramXtalkWide(v);
break;
default:
case XT_HEADPHONE:
vortex_XtalkHw_ProgramPipe(v);
break;
case XT_DIAMOND:
vortex_XtalkHw_ProgramDiamondXtalk(v);
break;
}
vortex_XtalkHw_SetSampleRate(v, 0x11);
vortex_XtalkHw_Enable(v);
return 0;
}
static void vortex_Vort3D_enable(vortex_t *v)
{
int i;
Vort3DRend_Initialize(v, XT_HEADPHONE);
for (i = 0; i < NR_A3D; i++) {
vortex_A3dSourceHw_Initialize(v, i % 4, i >> 2);
a3dsrc_ZeroStateA3D(&(v->a3d[0]));
}
vortex_a3d_register_controls(v);
}
static void vortex_Vort3D_disable(vortex_t * v)
{
vortex_XtalkHw_Disable(v);
vortex_a3d_unregister_controls(v);
}
static void vortex_Vort3D_connect(vortex_t * v, int en)
{
int i;
#ifdef CHIP_AU8810
return;
#endif
#if 1
v->mixxtlk[0] =
vortex_adb_checkinout(v, v->fixed_res, en, VORTEX_RESOURCE_MIXIN);
if (v->mixxtlk[0] < 0) {
pr_warn
("vortex: vortex_Vort3D: ERROR: not enough free mixer resources.\n");
return;
}
v->mixxtlk[1] =
vortex_adb_checkinout(v, v->fixed_res, en, VORTEX_RESOURCE_MIXIN);
if (v->mixxtlk[1] < 0) {
pr_warn
("vortex: vortex_Vort3D: ERROR: not enough free mixer resources.\n");
return;
}
#endif
for (i = 0; i < 4; i++) {
vortex_route(v, en, 0x11, ADB_A3DOUT(i * 2), ADB_XTALKIN(i));
vortex_route(v, en, 0x11, ADB_A3DOUT(i * 2) + 1, ADB_XTALKIN(5 + i));
}
#if 0
vortex_route(v, en, 0x11, ADB_XTALKOUT(0), ADB_EQIN(2));
vortex_route(v, en, 0x11, ADB_XTALKOUT(1), ADB_EQIN(3));
#else
vortex_route(v, en, 0x11, ADB_XTALKOUT(0), ADB_MIXIN(v->mixxtlk[0]));
vortex_route(v, en, 0x11, ADB_XTALKOUT(1), ADB_MIXIN(v->mixxtlk[1]));
vortex_connection_mixin_mix(v, en, v->mixxtlk[0], v->mixplayb[0], 0);
vortex_connection_mixin_mix(v, en, v->mixxtlk[1], v->mixplayb[1], 0);
vortex_mix_setinputvolumebyte(v, v->mixplayb[0], v->mixxtlk[0],
en ? MIX_DEFIGAIN : VOL_MIN);
vortex_mix_setinputvolumebyte(v, v->mixplayb[1], v->mixxtlk[1],
en ? MIX_DEFIGAIN : VOL_MIN);
if (VORTEX_IS_QUAD(v)) {
vortex_connection_mixin_mix(v, en, v->mixxtlk[0],
v->mixplayb[2], 0);
vortex_connection_mixin_mix(v, en, v->mixxtlk[1],
v->mixplayb[3], 0);
vortex_mix_setinputvolumebyte(v, v->mixplayb[2],
v->mixxtlk[0],
en ? MIX_DEFIGAIN : VOL_MIN);
vortex_mix_setinputvolumebyte(v, v->mixplayb[3],
v->mixxtlk[1],
en ? MIX_DEFIGAIN : VOL_MIN);
}
#endif
}
static void vortex_Vort3D_InitializeSource(a3dsrc_t * a, int en)
{
if (a->vortex == NULL) {
pr_warn
("vortex: Vort3D_InitializeSource: A3D source not initialized\n");
return;
}
if (en) {
a3dsrc_ProgramPipe(a);
a3dsrc_SetA3DSampleRate(a, 0x11);
a3dsrc_SetTimeConsts(a, HrtfTCDefault,
ItdTCDefault, GainTCDefault,
CoefTCDefault);
a3dsrc_EnableA3D(a);
} else {
a3dsrc_DisableA3D(a);
a3dsrc_ZeroState(a);
}
}
static void vortex_a3d_coord2hrtf(a3d_Hrtf_t hrtf, int *coord)
{
}
static void vortex_a3d_coord2itd(a3d_Itd_t itd, int *coord)
{
}
static void vortex_a3d_coord2ild(a3d_LRGains_t ild, int left, int right)
{
}
static void vortex_a3d_translate_filter(a3d_atmos_t filter, int *params)
{
}
static int
snd_vortex_a3d_hrtf_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 6;
uinfo->value.integer.min = 0x00000000;
uinfo->value.integer.max = 0xffffffff;
return 0;
}
static int
snd_vortex_a3d_itd_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0x00000000;
uinfo->value.integer.max = 0xffffffff;
return 0;
}
static int
snd_vortex_a3d_ild_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0x00000000;
uinfo->value.integer.max = 0xffffffff;
return 0;
}
static int
snd_vortex_a3d_filter_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 4;
uinfo->value.integer.min = 0x00000000;
uinfo->value.integer.max = 0xffffffff;
return 0;
}
static int
snd_vortex_a3d_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
return 0;
}
static int
snd_vortex_a3d_hrtf_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
a3dsrc_t *a = kcontrol->private_data;
int changed = 1, i;
int coord[6];
for (i = 0; i < 6; i++)
coord[i] = ucontrol->value.integer.value[i];
vortex_a3d_coord2hrtf(a->hrtf[0], coord);
vortex_a3d_coord2hrtf(a->hrtf[1], coord);
a3dsrc_SetHrtfTarget(a, a->hrtf[0], a->hrtf[1]);
a3dsrc_SetHrtfCurrent(a, a->hrtf[0], a->hrtf[1]);
return changed;
}
static int
snd_vortex_a3d_itd_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
a3dsrc_t *a = kcontrol->private_data;
int coord[6];
int i, changed = 1;
for (i = 0; i < 6; i++)
coord[i] = ucontrol->value.integer.value[i];
vortex_a3d_coord2itd(a->hrtf[0], coord);
vortex_a3d_coord2itd(a->hrtf[1], coord);
a3dsrc_SetItdTarget(a, a->itd[0], a->itd[1]);
a3dsrc_SetItdCurrent(a, a->itd[0], a->itd[1]);
a3dsrc_SetItdDline(a, a->dline);
return changed;
}
static int
snd_vortex_a3d_ild_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
a3dsrc_t *a = kcontrol->private_data;
int changed = 1;
int l, r;
l = ucontrol->value.integer.value[0];
r = ucontrol->value.integer.value[1];
vortex_a3d_coord2ild(a->ild, l, r);
a3dsrc_SetGainTarget(a, l, r);
a3dsrc_SetGainCurrent(a, l, r);
return changed;
}
static int
snd_vortex_a3d_filter_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
a3dsrc_t *a = kcontrol->private_data;
int i, changed = 1;
int params[6];
for (i = 0; i < 6; i++)
params[i] = ucontrol->value.integer.value[i];
vortex_a3d_translate_filter(a->filter, params);
a3dsrc_SetAtmosTarget(a, a->filter[0],
a->filter[1], a->filter[2],
a->filter[3], a->filter[4]);
a3dsrc_SetAtmosCurrent(a, a->filter[0],
a->filter[1], a->filter[2],
a->filter[3], a->filter[4]);
return changed;
}
static int vortex_a3d_register_controls(vortex_t *vortex)
{
struct snd_kcontrol *kcontrol;
int err, i;
for (i = 0; i < NR_A3D; i++) {
if ((kcontrol =
snd_ctl_new1(&vortex_a3d_kcontrol, &vortex->a3d[i])) == NULL)
return -ENOMEM;
kcontrol->id.numid = CTRLID_HRTF;
kcontrol->info = snd_vortex_a3d_hrtf_info;
kcontrol->put = snd_vortex_a3d_hrtf_put;
if ((err = snd_ctl_add(vortex->card, kcontrol)) < 0)
return err;
}
for (i = 0; i < NR_A3D; i++) {
if ((kcontrol =
snd_ctl_new1(&vortex_a3d_kcontrol, &vortex->a3d[i])) == NULL)
return -ENOMEM;
kcontrol->id.numid = CTRLID_ITD;
kcontrol->info = snd_vortex_a3d_itd_info;
kcontrol->put = snd_vortex_a3d_itd_put;
if ((err = snd_ctl_add(vortex->card, kcontrol)) < 0)
return err;
}
for (i = 0; i < NR_A3D; i++) {
if ((kcontrol =
snd_ctl_new1(&vortex_a3d_kcontrol, &vortex->a3d[i])) == NULL)
return -ENOMEM;
kcontrol->id.numid = CTRLID_GAINS;
kcontrol->info = snd_vortex_a3d_ild_info;
kcontrol->put = snd_vortex_a3d_ild_put;
if ((err = snd_ctl_add(vortex->card, kcontrol)) < 0)
return err;
}
for (i = 0; i < NR_A3D; i++) {
if ((kcontrol =
snd_ctl_new1(&vortex_a3d_kcontrol, &vortex->a3d[i])) == NULL)
return -ENOMEM;
kcontrol->id.numid = CTRLID_FILTER;
kcontrol->info = snd_vortex_a3d_filter_info;
kcontrol->put = snd_vortex_a3d_filter_put;
if ((err = snd_ctl_add(vortex->card, kcontrol)) < 0)
return err;
}
return 0;
}
static void vortex_a3d_unregister_controls(vortex_t * vortex)
{
}
