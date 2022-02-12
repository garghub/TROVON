static void
vortex_XtalkHw_SetLeftEQ(vortex_t * vortex, short arg_0, short arg_4,
xtalk_coefs_t const coefs)
{
int i;
for (i = 0; i < 5; i++) {
hwwrite(vortex->mmio, 0x24200 + i * 0x24, coefs[i][0]);
hwwrite(vortex->mmio, 0x24204 + i * 0x24, coefs[i][1]);
hwwrite(vortex->mmio, 0x24208 + i * 0x24, coefs[i][2]);
hwwrite(vortex->mmio, 0x2420c + i * 0x24, coefs[i][3]);
hwwrite(vortex->mmio, 0x24210 + i * 0x24, coefs[i][4]);
}
hwwrite(vortex->mmio, 0x24538, arg_0 & 0xffff);
hwwrite(vortex->mmio, 0x2453C, arg_4 & 0xffff);
}
static void
vortex_XtalkHw_SetRightEQ(vortex_t * vortex, short arg_0, short arg_4,
xtalk_coefs_t const coefs)
{
int i;
for (i = 0; i < 5; i++) {
hwwrite(vortex->mmio, 0x242b4 + i * 0x24, coefs[i][0]);
hwwrite(vortex->mmio, 0x242b8 + i * 0x24, coefs[i][1]);
hwwrite(vortex->mmio, 0x242bc + i * 0x24, coefs[i][2]);
hwwrite(vortex->mmio, 0x242c0 + i * 0x24, coefs[i][3]);
hwwrite(vortex->mmio, 0x242c4 + i * 0x24, coefs[i][4]);
}
hwwrite(vortex->mmio, 0x24540, arg_0 & 0xffff);
hwwrite(vortex->mmio, 0x24544, arg_4 & 0xffff);
}
static void
vortex_XtalkHw_SetLeftXT(vortex_t * vortex, short arg_0, short arg_4,
xtalk_coefs_t const coefs)
{
int i;
for (i = 0; i < 5; i++) {
hwwrite(vortex->mmio, 0x24368 + i * 0x24, coefs[i][0]);
hwwrite(vortex->mmio, 0x2436c + i * 0x24, coefs[i][1]);
hwwrite(vortex->mmio, 0x24370 + i * 0x24, coefs[i][2]);
hwwrite(vortex->mmio, 0x24374 + i * 0x24, coefs[i][3]);
hwwrite(vortex->mmio, 0x24378 + i * 0x24, coefs[i][4]);
}
hwwrite(vortex->mmio, 0x24548, arg_0 & 0xffff);
hwwrite(vortex->mmio, 0x2454C, arg_4 & 0xffff);
}
static void
vortex_XtalkHw_SetRightXT(vortex_t * vortex, short arg_0, short arg_4,
xtalk_coefs_t const coefs)
{
int i;
for (i = 0; i < 5; i++) {
hwwrite(vortex->mmio, 0x2441C + i * 0x24, coefs[i][0]);
hwwrite(vortex->mmio, 0x24420 + i * 0x24, coefs[i][1]);
hwwrite(vortex->mmio, 0x24424 + i * 0x24, coefs[i][2]);
hwwrite(vortex->mmio, 0x24428 + i * 0x24, coefs[i][3]);
hwwrite(vortex->mmio, 0x2442C + i * 0x24, coefs[i][4]);
}
hwwrite(vortex->mmio, 0x24550, arg_0 & 0xffff);
hwwrite(vortex->mmio, 0x24554, arg_4 & 0xffff);
}
static void
vortex_XtalkHw_SetLeftEQStates(vortex_t * vortex,
xtalk_instate_t const arg_0,
xtalk_state_t const coefs)
{
int i;
for (i = 0; i < 5; i++) {
hwwrite(vortex->mmio, 0x24214 + i * 0x24, coefs[i][0]);
hwwrite(vortex->mmio, 0x24218 + i * 0x24, coefs[i][1]);
hwwrite(vortex->mmio, 0x2421C + i * 0x24, coefs[i][2]);
hwwrite(vortex->mmio, 0x24220 + i * 0x24, coefs[i][3]);
}
hwwrite(vortex->mmio, 0x244F8 + i * 0x24, arg_0[0]);
hwwrite(vortex->mmio, 0x244FC + i * 0x24, arg_0[1]);
hwwrite(vortex->mmio, 0x24500 + i * 0x24, arg_0[2]);
hwwrite(vortex->mmio, 0x24504 + i * 0x24, arg_0[3]);
}
static void
vortex_XtalkHw_SetRightEQStates(vortex_t * vortex,
xtalk_instate_t const arg_0,
xtalk_state_t const coefs)
{
int i;
for (i = 0; i < 5; i++) {
hwwrite(vortex->mmio, 0x242C8 + i * 0x24, coefs[i][0]);
hwwrite(vortex->mmio, 0x242CC + i * 0x24, coefs[i][1]);
hwwrite(vortex->mmio, 0x242D0 + i * 0x24, coefs[i][2]);
hwwrite(vortex->mmio, 0x244D4 + i * 0x24, coefs[i][3]);
}
hwwrite(vortex->mmio, 0x24508 + i * 0x24, arg_0[0]);
hwwrite(vortex->mmio, 0x2450C + i * 0x24, arg_0[1]);
hwwrite(vortex->mmio, 0x24510 + i * 0x24, arg_0[2]);
hwwrite(vortex->mmio, 0x24514 + i * 0x24, arg_0[3]);
}
static void
vortex_XtalkHw_SetLeftXTStates(vortex_t * vortex,
xtalk_instate_t const arg_0,
xtalk_state_t const coefs)
{
int i;
for (i = 0; i < 5; i++) {
hwwrite(vortex->mmio, 0x2437C + i * 0x24, coefs[i][0]);
hwwrite(vortex->mmio, 0x24380 + i * 0x24, coefs[i][1]);
hwwrite(vortex->mmio, 0x24384 + i * 0x24, coefs[i][2]);
hwwrite(vortex->mmio, 0x24388 + i * 0x24, coefs[i][3]);
}
hwwrite(vortex->mmio, 0x24518 + i * 0x24, arg_0[0]);
hwwrite(vortex->mmio, 0x2451C + i * 0x24, arg_0[1]);
hwwrite(vortex->mmio, 0x24520 + i * 0x24, arg_0[2]);
hwwrite(vortex->mmio, 0x24524 + i * 0x24, arg_0[3]);
}
static void
vortex_XtalkHw_SetRightXTStates(vortex_t * vortex,
xtalk_instate_t const arg_0,
xtalk_state_t const coefs)
{
int i;
for (i = 0; i < 5; i++) {
hwwrite(vortex->mmio, 0x24430 + i * 0x24, coefs[i][0]);
hwwrite(vortex->mmio, 0x24434 + i * 0x24, coefs[i][1]);
hwwrite(vortex->mmio, 0x24438 + i * 0x24, coefs[i][2]);
hwwrite(vortex->mmio, 0x2443C + i * 0x24, coefs[i][3]);
}
hwwrite(vortex->mmio, 0x24528 + i * 0x24, arg_0[0]);
hwwrite(vortex->mmio, 0x2452C + i * 0x24, arg_0[1]);
hwwrite(vortex->mmio, 0x24530 + i * 0x24, arg_0[2]);
hwwrite(vortex->mmio, 0x24534 + i * 0x24, arg_0[3]);
}
static void
vortex_XtalkHw_SetGains(vortex_t * vortex, xtalk_gains_t const gains)
{
int i;
for (i = 0; i < XTGAINS_SZ; i++) {
hwwrite(vortex->mmio, 0x244D0 + (i * 4), gains[i]);
}
}
static void
vortex_XtalkHw_SetGainsAllChan(vortex_t * vortex)
{
vortex_XtalkHw_SetGains(vortex, asXtalkGainsAllChan);
}
static void
vortex_XtalkHw_SetDelay(vortex_t * vortex, unsigned short right,
unsigned short left)
{
u32 esp0 = 0;
esp0 &= 0x1FFFFFFF;
esp0 |= 0xA0000000;
esp0 = (esp0 & 0xffffE0ff) | ((right & 0x1F) << 8);
esp0 = (esp0 & 0xfffc1fff) | ((left & 0x1F) << 0xd);
hwwrite(vortex->mmio, 0x24660, esp0);
}
static void
vortex_XtalkHw_SetLeftDline(vortex_t * vortex, xtalk_dline_t const dline)
{
int i;
for (i = 0; i < 0x20; i++) {
hwwrite(vortex->mmio, 0x24000 + (i << 2), dline[i] & 0xffff);
hwwrite(vortex->mmio, 0x24080 + (i << 2), dline[i] >> 0x10);
}
}
static void
vortex_XtalkHw_SetRightDline(vortex_t * vortex, xtalk_dline_t const dline)
{
int i;
for (i = 0; i < 0x20; i++) {
hwwrite(vortex->mmio, 0x24100 + (i << 2), dline[i] & 0xffff);
hwwrite(vortex->mmio, 0x24180 + (i << 2), dline[i] >> 0x10);
}
}
static void vortex_XtalkHw_SetSampleRate(vortex_t * vortex, u32 sr)
{
u32 temp;
temp = (hwread(vortex->mmio, 0x24660) & 0x1FFFFFFF) | 0xC0000000;
temp = (temp & 0xffffff07) | ((sr & 0x1f) << 3);
hwwrite(vortex->mmio, 0x24660, temp);
}
static void vortex_XtalkHw_Enable(vortex_t * vortex)
{
u32 temp;
temp = (hwread(vortex->mmio, 0x24660) & 0x1FFFFFFF) | 0xC0000000;
temp |= 1;
hwwrite(vortex->mmio, 0x24660, temp);
}
static void vortex_XtalkHw_Disable(vortex_t * vortex)
{
u32 temp;
temp = (hwread(vortex->mmio, 0x24660) & 0x1FFFFFFF) | 0xC0000000;
temp &= 0xfffffffe;
hwwrite(vortex->mmio, 0x24660, temp);
}
static void vortex_XtalkHw_ZeroIO(vortex_t * vortex)
{
int i;
for (i = 0; i < 20; i++)
hwwrite(vortex->mmio, 0x24600 + (i << 2), 0);
for (i = 0; i < 4; i++)
hwwrite(vortex->mmio, 0x24650 + (i << 2), 0);
}
static void vortex_XtalkHw_ZeroState(vortex_t * vortex)
{
vortex_XtalkHw_ZeroIO(vortex);
vortex_XtalkHw_SetLeftEQ(vortex, 0, 0, asXtalkCoefsZeros);
vortex_XtalkHw_SetRightEQ(vortex, 0, 0, asXtalkCoefsZeros);
vortex_XtalkHw_SetLeftXT(vortex, 0, 0, asXtalkCoefsZeros);
vortex_XtalkHw_SetRightXT(vortex, 0, 0, asXtalkCoefsZeros);
vortex_XtalkHw_SetGains(vortex, asXtalkGainsZeros);
vortex_XtalkHw_SetDelay(vortex, 0, 0);
vortex_XtalkHw_SetLeftDline(vortex, alXtalkDlineZeros);
vortex_XtalkHw_SetRightDline(vortex, alXtalkDlineZeros);
vortex_XtalkHw_SetLeftDline(vortex, alXtalkDlineZeros);
vortex_XtalkHw_SetRightDline(vortex, alXtalkDlineZeros);
vortex_XtalkHw_SetLeftEQStates(vortex, asXtalkInStateZeros,
asXtalkOutStateZeros);
vortex_XtalkHw_SetRightEQStates(vortex, asXtalkInStateZeros,
asXtalkOutStateZeros);
vortex_XtalkHw_SetLeftXTStates(vortex, asXtalkInStateZeros,
asXtalkOutStateZeros);
vortex_XtalkHw_SetRightXTStates(vortex, asXtalkInStateZeros,
asXtalkOutStateZeros);
}
static void vortex_XtalkHw_ProgramPipe(vortex_t * vortex)
{
vortex_XtalkHw_SetLeftEQ(vortex, 0, 1, asXtalkCoefsPipe);
vortex_XtalkHw_SetRightEQ(vortex, 0, 1, asXtalkCoefsPipe);
vortex_XtalkHw_SetLeftXT(vortex, 0, 0, asXtalkCoefsZeros);
vortex_XtalkHw_SetRightXT(vortex, 0, 0, asXtalkCoefsZeros);
vortex_XtalkHw_SetDelay(vortex, 0, 0);
}
static void vortex_XtalkHw_ProgramXtalkWide(vortex_t * vortex)
{
vortex_XtalkHw_SetLeftEQ(vortex, sXtalkWideKLeftEq,
sXtalkWideShiftLeftEq, asXtalkWideCoefsLeftEq);
vortex_XtalkHw_SetRightEQ(vortex, sXtalkWideKRightEq,
sXtalkWideShiftRightEq,
asXtalkWideCoefsRightEq);
vortex_XtalkHw_SetLeftXT(vortex, sXtalkWideKLeftXt,
sXtalkWideShiftLeftXt, asXtalkWideCoefsLeftXt);
vortex_XtalkHw_SetRightXT(vortex, sXtalkWideKLeftXt,
sXtalkWideShiftLeftXt,
asXtalkWideCoefsLeftXt);
vortex_XtalkHw_SetDelay(vortex, wXtalkWideRightDelay, wXtalkWideLeftDelay);
}
static void vortex_XtalkHw_ProgramXtalkNarrow(vortex_t * vortex)
{
vortex_XtalkHw_SetLeftEQ(vortex, sXtalkNarrowKLeftEq,
sXtalkNarrowShiftLeftEq,
asXtalkNarrowCoefsLeftEq);
vortex_XtalkHw_SetRightEQ(vortex, sXtalkNarrowKRightEq,
sXtalkNarrowShiftRightEq,
asXtalkNarrowCoefsRightEq);
vortex_XtalkHw_SetLeftXT(vortex, sXtalkNarrowKLeftXt,
sXtalkNarrowShiftLeftXt,
asXtalkNarrowCoefsLeftXt);
vortex_XtalkHw_SetRightXT(vortex, sXtalkNarrowKLeftXt,
sXtalkNarrowShiftLeftXt,
asXtalkNarrowCoefsLeftXt);
vortex_XtalkHw_SetDelay(vortex, wXtalkNarrowRightDelay, wXtalkNarrowLeftDelay);
}
static void vortex_XtalkHw_ProgramDiamondXtalk(vortex_t * vortex)
{
vortex_XtalkHw_SetLeftEQ(vortex, sDiamondKLeftEq,
sDiamondShiftLeftEq, asDiamondCoefsLeftEq);
vortex_XtalkHw_SetRightEQ(vortex, sDiamondKRightEq,
sDiamondShiftRightEq, asDiamondCoefsRightEq);
vortex_XtalkHw_SetLeftXT(vortex, sDiamondKLeftXt,
sDiamondShiftLeftXt, asDiamondCoefsLeftXt);
vortex_XtalkHw_SetRightXT(vortex, sDiamondKLeftXt,
sDiamondShiftLeftXt, asDiamondCoefsLeftXt);
vortex_XtalkHw_SetDelay(vortex, wDiamondRightDelay, wDiamondLeftDelay);
}
static void vortex_XtalkHw_init(vortex_t * vortex)
{
vortex_XtalkHw_ZeroState(vortex);
}
