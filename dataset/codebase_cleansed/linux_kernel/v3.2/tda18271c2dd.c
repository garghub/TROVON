static int i2c_readn(struct i2c_adapter *adapter, u8 adr, u8 *data, int len)
{
struct i2c_msg msgs[1] = {{.addr = adr, .flags = I2C_M_RD,
.buf = data, .len = len} };
return (i2c_transfer(adapter, msgs, 1) == 1) ? 0 : -1;
}
static int i2c_write(struct i2c_adapter *adap, u8 adr, u8 *data, int len)
{
struct i2c_msg msg = {.addr = adr, .flags = 0,
.buf = data, .len = len};
if (i2c_transfer(adap, &msg, 1) != 1) {
printk(KERN_ERR "tda18271c2dd: i2c write error at addr %i\n", adr);
return -1;
}
return 0;
}
static int WriteRegs(struct tda_state *state,
u8 SubAddr, u8 *Regs, u16 nRegs)
{
u8 data[nRegs+1];
data[0] = SubAddr;
memcpy(data + 1, Regs, nRegs);
return i2c_write(state->i2c, state->adr, data, nRegs+1);
}
static int WriteReg(struct tda_state *state, u8 SubAddr, u8 Reg)
{
u8 msg[2] = {SubAddr, Reg};
return i2c_write(state->i2c, state->adr, msg, 2);
}
static int Read(struct tda_state *state, u8 * Regs)
{
return i2c_readn(state->i2c, state->adr, Regs, 16);
}
static int ReadExtented(struct tda_state *state, u8 * Regs)
{
return i2c_readn(state->i2c, state->adr, Regs, NUM_REGS);
}
static int UpdateRegs(struct tda_state *state, u8 RegFrom, u8 RegTo)
{
return WriteRegs(state, RegFrom,
&state->m_Regs[RegFrom], RegTo-RegFrom+1);
}
static int UpdateReg(struct tda_state *state, u8 Reg)
{
return WriteReg(state, Reg, state->m_Regs[Reg]);
}
static void reset(struct tda_state *state)
{
u32 ulIFLevelAnalog = 0;
u32 ulIFLevelDigital = 2;
u32 ulIFLevelDVBC = 7;
u32 ulIFLevelDVBT = 6;
u32 ulXTOut = 0;
u32 ulStandbyMode = 0x06;
u32 ulSlave = 0;
u32 ulFMInput = 0;
u32 ulSettlingTime = 100;
state->m_Frequency = 0;
state->m_SettlingTime = 100;
state->m_IFLevelAnalog = (ulIFLevelAnalog & 0x07) << 2;
state->m_IFLevelDigital = (ulIFLevelDigital & 0x07) << 2;
state->m_IFLevelDVBC = (ulIFLevelDVBC & 0x07) << 2;
state->m_IFLevelDVBT = (ulIFLevelDVBT & 0x07) << 2;
state->m_EP4 = 0x20;
if (ulXTOut != 0)
state->m_EP4 |= 0x40;
state->m_EP3_Standby = ((ulStandbyMode & 0x07) << 5) | 0x0F;
state->m_bMaster = (ulSlave == 0);
state->m_SettlingTime = ulSettlingTime;
state->m_bFMInput = (ulFMInput == 2);
}
static bool SearchMap1(struct SMap Map[],
u32 Frequency, u8 *pParam)
{
int i = 0;
while ((Map[i].m_Frequency != 0) && (Frequency > Map[i].m_Frequency))
i += 1;
if (Map[i].m_Frequency == 0)
return false;
*pParam = Map[i].m_Param;
return true;
}
static bool SearchMap2(struct SMapI Map[],
u32 Frequency, s32 *pParam)
{
int i = 0;
while ((Map[i].m_Frequency != 0) &&
(Frequency > Map[i].m_Frequency))
i += 1;
if (Map[i].m_Frequency == 0)
return false;
*pParam = Map[i].m_Param;
return true;
}
static bool SearchMap3(struct SMap2 Map[], u32 Frequency,
u8 *pParam1, u8 *pParam2)
{
int i = 0;
while ((Map[i].m_Frequency != 0) &&
(Frequency > Map[i].m_Frequency))
i += 1;
if (Map[i].m_Frequency == 0)
return false;
*pParam1 = Map[i].m_Param1;
*pParam2 = Map[i].m_Param2;
return true;
}
static bool SearchMap4(struct SRFBandMap Map[],
u32 Frequency, u8 *pRFBand)
{
int i = 0;
while (i < 7 && (Frequency > Map[i].m_RF_max))
i += 1;
if (i == 7)
return false;
*pRFBand = i;
return true;
}
static int ThermometerRead(struct tda_state *state, u8 *pTM_Value)
{
int status = 0;
do {
u8 Regs[16];
state->m_Regs[TM] |= 0x10;
status = UpdateReg(state, TM);
if (status < 0)
break;
status = Read(state, Regs);
if (status < 0)
break;
if (((Regs[TM] & 0x0F) == 0 && (Regs[TM] & 0x20) == 0x20) ||
((Regs[TM] & 0x0F) == 8 && (Regs[TM] & 0x20) == 0x00)) {
state->m_Regs[TM] ^= 0x20;
status = UpdateReg(state, TM);
if (status < 0)
break;
msleep(10);
status = Read(state, Regs);
if (status < 0)
break;
}
*pTM_Value = (Regs[TM] & 0x20)
? m_Thermometer_Map_2[Regs[TM] & 0x0F]
: m_Thermometer_Map_1[Regs[TM] & 0x0F] ;
state->m_Regs[TM] &= ~0x10;
status = UpdateReg(state, TM);
if (status < 0)
break;
state->m_Regs[EP4] &= ~0x03;
status = UpdateReg(state, EP4);
if (status < 0)
break;
} while (0);
return status;
}
static int StandBy(struct tda_state *state)
{
int status = 0;
do {
state->m_Regs[EB12] &= ~0x20;
status = UpdateReg(state, EB12);
if (status < 0)
break;
state->m_Regs[EB18] &= ~0x83;
status = UpdateReg(state, EB18);
if (status < 0)
break;
state->m_Regs[EB21] |= 0x03;
state->m_Regs[EP3] = state->m_EP3_Standby;
status = UpdateReg(state, EP3);
if (status < 0)
break;
state->m_Regs[EB23] &= ~0x06;
status = UpdateRegs(state, EB21, EB23);
if (status < 0)
break;
} while (0);
return status;
}
static int CalcMainPLL(struct tda_state *state, u32 freq)
{
u8 PostDiv;
u8 Div;
u64 OscFreq;
u32 MainDiv;
if (!SearchMap3(m_Main_PLL_Map, freq, &PostDiv, &Div))
return -EINVAL;
OscFreq = (u64) freq * (u64) Div;
OscFreq *= (u64) 16384;
do_div(OscFreq, (u64)16000000);
MainDiv = OscFreq;
state->m_Regs[MPD] = PostDiv & 0x77;
state->m_Regs[MD1] = ((MainDiv >> 16) & 0x7F);
state->m_Regs[MD2] = ((MainDiv >> 8) & 0xFF);
state->m_Regs[MD3] = (MainDiv & 0xFF);
return UpdateRegs(state, MPD, MD3);
}
static int CalcCalPLL(struct tda_state *state, u32 freq)
{
u8 PostDiv;
u8 Div;
u64 OscFreq;
u32 CalDiv;
if (!SearchMap3(m_Cal_PLL_Map, freq, &PostDiv, &Div))
return -EINVAL;
OscFreq = (u64)freq * (u64)Div;
OscFreq *= (u64)16384;
do_div(OscFreq, (u64)16000000);
CalDiv = OscFreq;
state->m_Regs[CPD] = PostDiv;
state->m_Regs[CD1] = ((CalDiv >> 16) & 0xFF);
state->m_Regs[CD2] = ((CalDiv >> 8) & 0xFF);
state->m_Regs[CD3] = (CalDiv & 0xFF);
return UpdateRegs(state, CPD, CD3);
}
static int CalibrateRF(struct tda_state *state,
u8 RFBand, u32 freq, s32 *pCprog)
{
int status = 0;
u8 Regs[NUM_REGS];
do {
u8 BP_Filter = 0;
u8 GainTaper = 0;
u8 RFC_K = 0;
u8 RFC_M = 0;
state->m_Regs[EP4] &= ~0x03;
status = UpdateReg(state, EP4);
if (status < 0)
break;
state->m_Regs[EB18] |= 0x03;
status = UpdateReg(state, EB18);
if (status < 0)
break;
if (state->m_Regs[ID] != 0x83)
state->m_Regs[EP3] |= 0x40;
if (!(SearchMap1(m_BP_Filter_Map, freq, &BP_Filter) &&
SearchMap1(m_GainTaper_Map, freq, &GainTaper) &&
SearchMap3(m_KM_Map, freq, &RFC_K, &RFC_M)))
return -EINVAL;
state->m_Regs[EP1] = (state->m_Regs[EP1] & ~0x07) | BP_Filter;
state->m_Regs[EP2] = (RFBand << 5) | GainTaper;
state->m_Regs[EB13] = (state->m_Regs[EB13] & ~0x7C) | (RFC_K << 4) | (RFC_M << 2);
status = UpdateRegs(state, EP1, EP3);
if (status < 0)
break;
status = UpdateReg(state, EB13);
if (status < 0)
break;
state->m_Regs[EB4] |= 0x20;
status = UpdateReg(state, EB4);
if (status < 0)
break;
state->m_Regs[EB7] |= 0x20;
status = UpdateReg(state, EB7);
if (status < 0)
break;
state->m_Regs[EB14] = 0;
status = UpdateReg(state, EB14);
if (status < 0)
break;
state->m_Regs[EB20] &= ~0x20;
status = UpdateReg(state, EB20);
if (status < 0)
break;
state->m_Regs[EP4] |= 0x03;
status = UpdateRegs(state, EP4, EP5);
if (status < 0)
break;
status = CalcCalPLL(state, freq);
if (status < 0)
break;
status = CalcMainPLL(state, freq + 1000000);
if (status < 0)
break;
msleep(5);
status = UpdateReg(state, EP2);
if (status < 0)
break;
status = UpdateReg(state, EP1);
if (status < 0)
break;
status = UpdateReg(state, EP2);
if (status < 0)
break;
status = UpdateReg(state, EP1);
if (status < 0)
break;
state->m_Regs[EB4] &= ~0x20;
status = UpdateReg(state, EB4);
if (status < 0)
break;
state->m_Regs[EB7] &= ~0x20;
status = UpdateReg(state, EB7);
if (status < 0)
break;
msleep(10);
state->m_Regs[EB20] |= 0x20;
status = UpdateReg(state, EB20);
if (status < 0)
break;
msleep(60);
state->m_Regs[EP4] &= ~0x03;
state->m_Regs[EP3] &= ~0x40;
state->m_Regs[EB18] &= ~0x03;
status = UpdateReg(state, EB18);
if (status < 0)
break;
status = UpdateRegs(state, EP3, EP4);
if (status < 0)
break;
status = UpdateReg(state, EP1);
if (status < 0)
break;
status = ReadExtented(state, Regs);
if (status < 0)
break;
*pCprog = Regs[EB14];
} while (0);
return status;
}
static int RFTrackingFiltersInit(struct tda_state *state,
u8 RFBand)
{
int status = 0;
u32 RF1 = m_RF_Band_Map[RFBand].m_RF1_Default;
u32 RF2 = m_RF_Band_Map[RFBand].m_RF2_Default;
u32 RF3 = m_RF_Band_Map[RFBand].m_RF3_Default;
bool bcal = false;
s32 Cprog_cal1 = 0;
s32 Cprog_table1 = 0;
s32 Cprog_cal2 = 0;
s32 Cprog_table2 = 0;
s32 Cprog_cal3 = 0;
s32 Cprog_table3 = 0;
state->m_RF_A1[RFBand] = 0;
state->m_RF_B1[RFBand] = 0;
state->m_RF_A2[RFBand] = 0;
state->m_RF_B2[RFBand] = 0;
do {
status = PowerScan(state, RFBand, RF1, &RF1, &bcal);
if (status < 0)
break;
if (bcal) {
status = CalibrateRF(state, RFBand, RF1, &Cprog_cal1);
if (status < 0)
break;
}
SearchMap2(m_RF_Cal_Map, RF1, &Cprog_table1);
if (!bcal)
Cprog_cal1 = Cprog_table1;
state->m_RF_B1[RFBand] = Cprog_cal1 - Cprog_table1;
if (RF2 == 0)
break;
status = PowerScan(state, RFBand, RF2, &RF2, &bcal);
if (status < 0)
break;
if (bcal) {
status = CalibrateRF(state, RFBand, RF2, &Cprog_cal2);
if (status < 0)
break;
}
SearchMap2(m_RF_Cal_Map, RF2, &Cprog_table2);
if (!bcal)
Cprog_cal2 = Cprog_table2;
state->m_RF_A1[RFBand] =
(Cprog_cal2 - Cprog_table2 - Cprog_cal1 + Cprog_table1) /
((s32)(RF2) - (s32)(RF1));
if (RF3 == 0)
break;
status = PowerScan(state, RFBand, RF3, &RF3, &bcal);
if (status < 0)
break;
if (bcal) {
status = CalibrateRF(state, RFBand, RF3, &Cprog_cal3);
if (status < 0)
break;
}
SearchMap2(m_RF_Cal_Map, RF3, &Cprog_table3);
if (!bcal)
Cprog_cal3 = Cprog_table3;
state->m_RF_A2[RFBand] = (Cprog_cal3 - Cprog_table3 - Cprog_cal2 + Cprog_table2) / ((s32)(RF3) - (s32)(RF2));
state->m_RF_B2[RFBand] = Cprog_cal2 - Cprog_table2;
} while (0);
state->m_RF1[RFBand] = RF1;
state->m_RF2[RFBand] = RF2;
state->m_RF3[RFBand] = RF3;
#if 0
printk(KERN_ERR "tda18271c2dd: %s %d RF1 = %d A1 = %d B1 = %d RF2 = %d A2 = %d B2 = %d RF3 = %d\n", __func__,
RFBand, RF1, state->m_RF_A1[RFBand], state->m_RF_B1[RFBand], RF2,
state->m_RF_A2[RFBand], state->m_RF_B2[RFBand], RF3);
#endif
return status;
}
static int PowerScan(struct tda_state *state,
u8 RFBand, u32 RF_in, u32 *pRF_Out, bool *pbcal)
{
int status = 0;
do {
u8 Gain_Taper = 0;
s32 RFC_Cprog = 0;
u8 CID_Target = 0;
u8 CountLimit = 0;
u32 freq_MainPLL;
u8 Regs[NUM_REGS];
u8 CID_Gain;
s32 Count = 0;
int sign = 1;
bool wait = false;
if (!(SearchMap2(m_RF_Cal_Map, RF_in, &RFC_Cprog) &&
SearchMap1(m_GainTaper_Map, RF_in, &Gain_Taper) &&
SearchMap3(m_CID_Target_Map, RF_in, &CID_Target, &CountLimit))) {
printk(KERN_ERR "tda18271c2dd: %s Search map failed\n", __func__);
return -EINVAL;
}
state->m_Regs[EP2] = (RFBand << 5) | Gain_Taper;
state->m_Regs[EB14] = (RFC_Cprog);
status = UpdateReg(state, EP2);
if (status < 0)
break;
status = UpdateReg(state, EB14);
if (status < 0)
break;
freq_MainPLL = RF_in + 1000000;
status = CalcMainPLL(state, freq_MainPLL);
if (status < 0)
break;
msleep(5);
state->m_Regs[EP4] = (state->m_Regs[EP4] & ~0x03) | 1;
status = UpdateReg(state, EP4);
if (status < 0)
break;
status = UpdateReg(state, EP2);
if (status < 0)
break;
status = ReadExtented(state, Regs);
if (status < 0)
break;
CID_Gain = Regs[EB10] & 0x3F;
state->m_Regs[ID] = Regs[ID];
*pRF_Out = RF_in;
while (CID_Gain < CID_Target) {
freq_MainPLL = RF_in + sign * Count + 1000000;
status = CalcMainPLL(state, freq_MainPLL);
if (status < 0)
break;
msleep(wait ? 5 : 1);
wait = false;
status = UpdateReg(state, EP2);
if (status < 0)
break;
status = ReadExtented(state, Regs);
if (status < 0)
break;
CID_Gain = Regs[EB10] & 0x3F;
Count += 200000;
if (Count < CountLimit * 100000)
continue;
if (sign < 0)
break;
sign = -sign;
Count = 200000;
wait = true;
}
status = status;
if (status < 0)
break;
if (CID_Gain >= CID_Target) {
*pbcal = true;
*pRF_Out = freq_MainPLL - 1000000;
} else
*pbcal = false;
} while (0);
return status;
}
static int PowerScanInit(struct tda_state *state)
{
int status = 0;
do {
state->m_Regs[EP3] = (state->m_Regs[EP3] & ~0x1F) | 0x12;
state->m_Regs[EP4] = (state->m_Regs[EP4] & ~0x1F);
status = UpdateRegs(state, EP3, EP4);
if (status < 0)
break;
state->m_Regs[EB18] = (state->m_Regs[EB18] & ~0x03);
status = UpdateReg(state, EB18);
if (status < 0)
break;
state->m_Regs[EB21] = (state->m_Regs[EB21] & ~0x03);
state->m_Regs[EB23] = (state->m_Regs[EB23] | 0x06);
status = UpdateRegs(state, EB21, EB23);
if (status < 0)
break;
} while (0);
return status;
}
static int CalcRFFilterCurve(struct tda_state *state)
{
int status = 0;
do {
msleep(200);
status = PowerScanInit(state);
if (status < 0)
break;
status = RFTrackingFiltersInit(state, 0);
if (status < 0)
break;
status = RFTrackingFiltersInit(state, 1);
if (status < 0)
break;
status = RFTrackingFiltersInit(state, 2);
if (status < 0)
break;
status = RFTrackingFiltersInit(state, 3);
if (status < 0)
break;
status = RFTrackingFiltersInit(state, 4);
if (status < 0)
break;
status = RFTrackingFiltersInit(state, 5);
if (status < 0)
break;
status = RFTrackingFiltersInit(state, 6);
if (status < 0)
break;
status = ThermometerRead(state, &state->m_TMValue_RFCal);
if (status < 0)
break;
} while (0);
return status;
}
static int FixedContentsI2CUpdate(struct tda_state *state)
{
static u8 InitRegs[] = {
0x08, 0x80, 0xC6,
0xDF, 0x16, 0x60, 0x80,
0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0xFC, 0x01, 0x84, 0x41,
0x01, 0x84, 0x40, 0x07,
0x00, 0x00, 0x96, 0x3F,
0xC1, 0x00, 0x8F, 0x00,
0x00, 0x8C, 0x00, 0x20,
0xB3, 0x48, 0xB0,
};
int status = 0;
memcpy(&state->m_Regs[TM], InitRegs, EB23 - TM + 1);
do {
status = UpdateRegs(state, TM, EB23);
if (status < 0)
break;
state->m_Regs[EB17] = 0x00;
status = UpdateReg(state, EB17);
if (status < 0)
break;
state->m_Regs[EB17] = 0x03;
status = UpdateReg(state, EB17);
if (status < 0)
break;
state->m_Regs[EB17] = 0x43;
status = UpdateReg(state, EB17);
if (status < 0)
break;
state->m_Regs[EB17] = 0x4C;
status = UpdateReg(state, EB17);
if (status < 0)
break;
state->m_Regs[EP3] = 0x1F;
state->m_Regs[EP4] = 0x66;
state->m_Regs[EP5] = 0x81;
state->m_Regs[CPD] = 0xCC;
state->m_Regs[CD1] = 0x6C;
state->m_Regs[CD2] = 0x00;
state->m_Regs[CD3] = 0x00;
state->m_Regs[MPD] = 0xC5;
state->m_Regs[MD1] = 0x77;
state->m_Regs[MD2] = 0x08;
state->m_Regs[MD3] = 0x00;
status = UpdateRegs(state, EP2, MD3);
if (status < 0)
break;
#if 0
state->m_Regs[EB4] = 0x61;
status = UpdateReg(state, EB4);
if (status < 0)
break;
msleep(1);
state->m_Regs[EB4] = 0x41;
status = UpdateReg(state, EB4);
if (status < 0)
break;
#endif
msleep(5);
status = UpdateReg(state, EP1);
if (status < 0)
break;
msleep(5);
state->m_Regs[EP5] = 0x85;
state->m_Regs[CPD] = 0xCB;
state->m_Regs[CD1] = 0x66;
state->m_Regs[CD2] = 0x70;
status = UpdateRegs(state, EP3, CD3);
if (status < 0)
break;
msleep(5);
status = UpdateReg(state, EP2);
if (status < 0)
break;
msleep(30);
state->m_Regs[EP5] = 0x82;
state->m_Regs[CPD] = 0xA8;
state->m_Regs[CD2] = 0x00;
state->m_Regs[MPD] = 0xA1;
state->m_Regs[MD1] = 0x73;
state->m_Regs[MD2] = 0x1A;
status = UpdateRegs(state, EP3, MD3);
if (status < 0)
break;
msleep(5);
status = UpdateReg(state, EP1);
if (status < 0)
break;
msleep(5);
state->m_Regs[EP5] = 0x86;
state->m_Regs[CPD] = 0xA8;
state->m_Regs[CD1] = 0x66;
state->m_Regs[CD2] = 0xA0;
status = UpdateRegs(state, EP3, CD3);
if (status < 0)
break;
msleep(5);
status = UpdateReg(state, EP2);
if (status < 0)
break;
msleep(30);
state->m_Regs[EP5] = 0x83;
state->m_Regs[CPD] = 0x98;
state->m_Regs[CD1] = 0x65;
state->m_Regs[CD2] = 0x00;
state->m_Regs[MPD] = 0x91;
state->m_Regs[MD1] = 0x71;
state->m_Regs[MD2] = 0xCD;
status = UpdateRegs(state, EP3, MD3);
if (status < 0)
break;
msleep(5);
status = UpdateReg(state, EP1);
if (status < 0)
break;
msleep(5);
state->m_Regs[EP5] = 0x87;
state->m_Regs[CD1] = 0x65;
state->m_Regs[CD2] = 0x50;
status = UpdateRegs(state, EP3, CD3);
if (status < 0)
break;
msleep(5);
status = UpdateReg(state, EP2);
if (status < 0)
break;
msleep(30);
state->m_Regs[EP4] = 0x64;
status = UpdateReg(state, EP4);
if (status < 0)
break;
status = UpdateReg(state, EP1);
if (status < 0)
break;
} while (0);
return status;
}
static int InitCal(struct tda_state *state)
{
int status = 0;
do {
status = FixedContentsI2CUpdate(state);
if (status < 0)
break;
status = CalcRFFilterCurve(state);
if (status < 0)
break;
status = StandBy(state);
if (status < 0)
break;
} while (0);
return status;
}
static int RFTrackingFiltersCorrection(struct tda_state *state,
u32 Frequency)
{
int status = 0;
s32 Cprog_table;
u8 RFBand;
u8 dCoverdT;
if (!SearchMap2(m_RF_Cal_Map, Frequency, &Cprog_table) ||
!SearchMap4(m_RF_Band_Map, Frequency, &RFBand) ||
!SearchMap1(m_RF_Cal_DC_Over_DT_Map, Frequency, &dCoverdT))
return -EINVAL;
do {
u8 TMValue_Current;
u32 RF1 = state->m_RF1[RFBand];
u32 RF2 = state->m_RF1[RFBand];
u32 RF3 = state->m_RF1[RFBand];
s32 RF_A1 = state->m_RF_A1[RFBand];
s32 RF_B1 = state->m_RF_B1[RFBand];
s32 RF_A2 = state->m_RF_A2[RFBand];
s32 RF_B2 = state->m_RF_B2[RFBand];
s32 Capprox = 0;
int TComp;
state->m_Regs[EP3] &= ~0xE0;
status = UpdateReg(state, EP3);
if (status < 0)
break;
status = ThermometerRead(state, &TMValue_Current);
if (status < 0)
break;
if (RF3 == 0 || Frequency < RF2)
Capprox = RF_A1 * ((s32)(Frequency) - (s32)(RF1)) + RF_B1 + Cprog_table;
else
Capprox = RF_A2 * ((s32)(Frequency) - (s32)(RF2)) + RF_B2 + Cprog_table;
TComp = (int)(dCoverdT) * ((int)(TMValue_Current) - (int)(state->m_TMValue_RFCal))/1000;
Capprox += TComp;
if (Capprox < 0)
Capprox = 0;
else if (Capprox > 255)
Capprox = 255;
state->m_Regs[EB14] = Capprox;
status = UpdateReg(state, EB14);
if (status < 0)
break;
} while (0);
return status;
}
static int ChannelConfiguration(struct tda_state *state,
u32 Frequency, int Standard)
{
s32 IntermediateFrequency = m_StandardTable[Standard].m_IFFrequency;
int status = 0;
u8 BP_Filter = 0;
u8 RF_Band = 0;
u8 GainTaper = 0;
u8 IR_Meas = 0;
state->IF = IntermediateFrequency;
if (!(SearchMap1(m_BP_Filter_Map, Frequency, &BP_Filter) &&
SearchMap1(m_GainTaper_Map, Frequency, &GainTaper) &&
SearchMap1(m_IR_Meas_Map, Frequency, &IR_Meas) &&
SearchMap4(m_RF_Band_Map, Frequency, &RF_Band))) {
printk(KERN_ERR "tda18271c2dd: %s SearchMap failed\n", __func__);
return -EINVAL;
}
do {
state->m_Regs[EP3] = (state->m_Regs[EP3] & ~0x1F) | m_StandardTable[Standard].m_EP3_4_0;
state->m_Regs[EP3] &= ~0x04;
state->m_Regs[EP4] = state->m_EP4 | ((Standard > HF_AnalogMax) ? state->m_IFLevelDigital : state->m_IFLevelAnalog);
if (Standard <= HF_AnalogMax)
state->m_Regs[EP4] = state->m_EP4 | state->m_IFLevelAnalog;
else if (Standard <= HF_ATSC)
state->m_Regs[EP4] = state->m_EP4 | state->m_IFLevelDVBT;
else if (Standard <= HF_DVBC)
state->m_Regs[EP4] = state->m_EP4 | state->m_IFLevelDVBC;
else
state->m_Regs[EP4] = state->m_EP4 | state->m_IFLevelDigital;
if ((Standard == HF_FM_Radio) && state->m_bFMInput)
state->m_Regs[EP4] |= 80;
state->m_Regs[MPD] &= ~0x80;
if (Standard > HF_AnalogMax)
state->m_Regs[MPD] |= 0x80;
state->m_Regs[EB22] = m_StandardTable[Standard].m_EB22;
if (Standard == HF_FM_Radio)
state->m_Regs[EB23] |= 0x06;
else
state->m_Regs[EB23] &= ~0x06;
status = UpdateRegs(state, EB22, EB23);
if (status < 0)
break;
state->m_Regs[EP1] = (state->m_Regs[EP1] & ~0x07) | 0x40 | BP_Filter;
state->m_Regs[EP5] = (state->m_Regs[EP5] & ~0x07) | IR_Meas;
state->m_Regs[EP2] = (RF_Band << 5) | GainTaper;
state->m_Regs[EB1] = (state->m_Regs[EB1] & ~0x07) |
(state->m_bMaster ? 0x04 : 0x00);
status = UpdateReg(state, EB1);
if (status < 0)
break;
if (state->m_bMaster) {
status = CalcMainPLL(state, Frequency + IntermediateFrequency);
if (status < 0)
break;
status = UpdateRegs(state, TM, EP5);
if (status < 0)
break;
state->m_Regs[EB4] |= 0x20;
status = UpdateReg(state, EB4);
if (status < 0)
break;
msleep(1);
state->m_Regs[EB4] &= ~0x20;
status = UpdateReg(state, EB4);
if (status < 0)
break;
} else {
u8 PostDiv = 0;
u8 Div;
status = CalcCalPLL(state, Frequency + IntermediateFrequency);
if (status < 0)
break;
SearchMap3(m_Cal_PLL_Map, Frequency + IntermediateFrequency, &PostDiv, &Div);
state->m_Regs[MPD] = (state->m_Regs[MPD] & ~0x7F) | (PostDiv & 0x77);
status = UpdateReg(state, MPD);
if (status < 0)
break;
status = UpdateRegs(state, TM, EP5);
if (status < 0)
break;
state->m_Regs[EB7] |= 0x20;
status = UpdateReg(state, EB7);
if (status < 0)
break;
msleep(1);
state->m_Regs[EB7] &= ~0x20;
status = UpdateReg(state, EB7);
if (status < 0)
break;
}
msleep(20);
if (Standard != HF_FM_Radio)
state->m_Regs[EP3] |= 0x04;
status = UpdateReg(state, EP3);
if (status < 0)
break;
} while (0);
return status;
}
static int sleep(struct dvb_frontend *fe)
{
struct tda_state *state = fe->tuner_priv;
StandBy(state);
return 0;
}
static int init(struct dvb_frontend *fe)
{
return 0;
}
static int release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
static int set_params(struct dvb_frontend *fe,
struct dvb_frontend_parameters *params)
{
struct tda_state *state = fe->tuner_priv;
int status = 0;
int Standard;
state->m_Frequency = params->frequency;
if (fe->ops.info.type == FE_OFDM)
switch (params->u.ofdm.bandwidth) {
case BANDWIDTH_6_MHZ:
Standard = HF_DVBT_6MHZ;
break;
case BANDWIDTH_7_MHZ:
Standard = HF_DVBT_7MHZ;
break;
default:
case BANDWIDTH_8_MHZ:
Standard = HF_DVBT_8MHZ;
break;
}
else if (fe->ops.info.type == FE_QAM) {
if (params->u.qam.symbol_rate <= MAX_SYMBOL_RATE_6MHz)
Standard = HF_DVBC_6MHZ;
else
Standard = HF_DVBC_8MHZ;
} else
return -EINVAL;
do {
status = RFTrackingFiltersCorrection(state, params->frequency);
if (status < 0)
break;
status = ChannelConfiguration(state, params->frequency, Standard);
if (status < 0)
break;
msleep(state->m_SettlingTime);
} while (0);
return status;
}
static int get_if_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct tda_state *state = fe->tuner_priv;
*frequency = state->IF;
return 0;
}
static int get_bandwidth(struct dvb_frontend *fe, u32 *bandwidth)
{
return 0;
}
struct dvb_frontend *tda18271c2dd_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c, u8 adr)
{
struct tda_state *state;
state = kzalloc(sizeof(struct tda_state), GFP_KERNEL);
if (!state)
return NULL;
fe->tuner_priv = state;
state->adr = adr;
state->i2c = i2c;
memcpy(&fe->ops.tuner_ops, &tuner_ops, sizeof(struct dvb_tuner_ops));
reset(state);
InitCal(state);
return fe;
}
