static void set_audio_registers(struct cx88_core *core, const struct rlist *l)
{
int i;
for (i = 0; l[i].reg; i++) {
switch (l[i].reg) {
case AUD_PDF_DDS_CNST_BYTE2:
case AUD_PDF_DDS_CNST_BYTE1:
case AUD_PDF_DDS_CNST_BYTE0:
case AUD_QAM_MODE:
case AUD_PHACC_FREQ_8MSB:
case AUD_PHACC_FREQ_8LSB:
cx_writeb(l[i].reg, l[i].val);
break;
default:
cx_write(l[i].reg, l[i].val);
break;
}
}
}
static void set_audio_start(struct cx88_core *core, u32 mode)
{
cx_write(AUD_VOL_CTL, (1 << 6));
cx_write(AUD_INIT, mode);
cx_write(AUD_INIT_LD, 0x0001);
cx_write(AUD_SOFT_RESET, 0x0001);
}
static void set_audio_finish(struct cx88_core *core, u32 ctl)
{
u32 volume;
cx88_stop_audio_dma(core);
cx_write(AUD_RATE_THRES_DMD, 0x000000C0);
cx88_start_audio_dma(core);
if (core->board.mpeg & CX88_MPEG_BLACKBIRD) {
cx_write(AUD_I2SINPUTCNTL, 4);
cx_write(AUD_BAUDRATE, 1);
cx_set(AUD_CTL, EN_I2SOUT_ENABLE);
cx_write(AUD_I2SOUTPUTCNTL, 1);
cx_write(AUD_I2SCNTL, 0);
}
if ((always_analog) || (!(core->board.mpeg & CX88_MPEG_BLACKBIRD))) {
ctl |= EN_DAC_ENABLE;
cx_write(AUD_CTL, ctl);
}
cx_write(AUD_SOFT_RESET, 0x0000);
volume = cx_sread(SHADOW_AUD_VOL_CTL);
cx_swrite(SHADOW_AUD_VOL_CTL, AUD_VOL_CTL, volume);
core->last_change = jiffies;
}
static void set_audio_standard_BTSC(struct cx88_core *core, unsigned int sap,
u32 mode)
{
static const struct rlist btsc[] = {
{AUD_AFE_12DB_EN, 0x00000001},
{AUD_OUT1_SEL, 0x00000013},
{AUD_OUT1_SHIFT, 0x00000000},
{AUD_POLY0_DDS_CONSTANT, 0x0012010c},
{AUD_DMD_RA_DDS, 0x00c3e7aa},
{AUD_DBX_IN_GAIN, 0x00004734},
{AUD_DBX_WBE_GAIN, 0x00004640},
{AUD_DBX_SE_GAIN, 0x00008d31},
{AUD_DCOC_0_SRC, 0x0000001a},
{AUD_IIR1_4_SEL, 0x00000021},
{AUD_DCOC_PASS_IN, 0x00000003},
{AUD_DCOC_0_SHIFT_IN0, 0x0000000a},
{AUD_DCOC_0_SHIFT_IN1, 0x00000008},
{AUD_DCOC_1_SHIFT_IN0, 0x0000000a},
{AUD_DCOC_1_SHIFT_IN1, 0x00000008},
{AUD_DN0_FREQ, 0x0000283b},
{AUD_DN2_SRC_SEL, 0x00000008},
{AUD_DN2_FREQ, 0x00003000},
{AUD_DN2_AFC, 0x00000002},
{AUD_DN2_SHFT, 0x00000000},
{AUD_IIR2_2_SEL, 0x00000020},
{AUD_IIR2_2_SHIFT, 0x00000000},
{AUD_IIR2_3_SEL, 0x0000001f},
{AUD_IIR2_3_SHIFT, 0x00000000},
{AUD_CRDC1_SRC_SEL, 0x000003ce},
{AUD_CRDC1_SHIFT, 0x00000000},
{AUD_CORDIC_SHIFT_1, 0x00000007},
{AUD_DCOC_1_SRC, 0x0000001b},
{AUD_DCOC1_SHIFT, 0x00000000},
{AUD_RDSI_SEL, 0x00000008},
{AUD_RDSQ_SEL, 0x00000008},
{AUD_RDSI_SHIFT, 0x00000000},
{AUD_RDSQ_SHIFT, 0x00000000},
{AUD_POLYPH80SCALEFAC, 0x00000003},
{ },
};
static const struct rlist btsc_sap[] = {
{AUD_AFE_12DB_EN, 0x00000001},
{AUD_DBX_IN_GAIN, 0x00007200},
{AUD_DBX_WBE_GAIN, 0x00006200},
{AUD_DBX_SE_GAIN, 0x00006200},
{AUD_IIR1_1_SEL, 0x00000000},
{AUD_IIR1_3_SEL, 0x00000001},
{AUD_DN1_SRC_SEL, 0x00000007},
{AUD_IIR1_4_SHIFT, 0x00000006},
{AUD_IIR2_1_SHIFT, 0x00000000},
{AUD_IIR2_2_SHIFT, 0x00000000},
{AUD_IIR3_0_SHIFT, 0x00000000},
{AUD_IIR3_1_SHIFT, 0x00000000},
{AUD_IIR3_0_SEL, 0x0000000d},
{AUD_IIR3_1_SEL, 0x0000000e},
{AUD_DEEMPH1_SRC_SEL, 0x00000014},
{AUD_DEEMPH1_SHIFT, 0x00000000},
{AUD_DEEMPH1_G0, 0x00004000},
{AUD_DEEMPH1_A0, 0x00000000},
{AUD_DEEMPH1_B0, 0x00000000},
{AUD_DEEMPH1_A1, 0x00000000},
{AUD_DEEMPH1_B1, 0x00000000},
{AUD_OUT0_SEL, 0x0000003f},
{AUD_OUT1_SEL, 0x0000003f},
{AUD_DN1_AFC, 0x00000002},
{AUD_DCOC_0_SHIFT_IN0, 0x0000000a},
{AUD_DCOC_0_SHIFT_IN1, 0x00000008},
{AUD_DCOC_1_SHIFT_IN0, 0x0000000a},
{AUD_DCOC_1_SHIFT_IN1, 0x00000008},
{AUD_IIR1_0_SEL, 0x0000001d},
{AUD_IIR1_2_SEL, 0x0000001e},
{AUD_IIR2_1_SEL, 0x00000002},
{AUD_IIR2_2_SEL, 0x00000004},
{AUD_IIR3_2_SEL, 0x0000000f},
{AUD_DCOC2_SHIFT, 0x00000001},
{AUD_IIR3_2_SHIFT, 0x00000001},
{AUD_DEEMPH0_SRC_SEL, 0x00000014},
{AUD_CORDIC_SHIFT_1, 0x00000006},
{AUD_POLY0_DDS_CONSTANT, 0x000e4db2},
{AUD_DMD_RA_DDS, 0x00f696e6},
{AUD_IIR2_3_SEL, 0x00000025},
{AUD_IIR1_4_SEL, 0x00000021},
{AUD_DN1_FREQ, 0x0000c965},
{AUD_DCOC_PASS_IN, 0x00000003},
{AUD_DCOC_0_SRC, 0x0000001a},
{AUD_DCOC_1_SRC, 0x0000001b},
{AUD_DCOC1_SHIFT, 0x00000000},
{AUD_RDSI_SEL, 0x00000009},
{AUD_RDSQ_SEL, 0x00000009},
{AUD_RDSI_SHIFT, 0x00000000},
{AUD_RDSQ_SHIFT, 0x00000000},
{AUD_POLYPH80SCALEFAC, 0x00000003},
{ },
};
mode |= EN_FMRADIO_EN_RDS;
if (sap) {
dprintk("%s SAP (status: unknown)\n", __func__);
set_audio_start(core, SEL_SAP);
set_audio_registers(core, btsc_sap);
set_audio_finish(core, mode);
} else {
dprintk("%s (status: known-good)\n", __func__);
set_audio_start(core, SEL_BTSC);
set_audio_registers(core, btsc);
set_audio_finish(core, mode);
}
}
static void set_audio_standard_NICAM(struct cx88_core *core, u32 mode)
{
static const struct rlist nicam_l[] = {
{AUD_AFE_12DB_EN, 0x00000001},
{AUD_RATE_ADJ1, 0x00000060},
{AUD_RATE_ADJ2, 0x000000F9},
{AUD_RATE_ADJ3, 0x000001CC},
{AUD_RATE_ADJ4, 0x000002B3},
{AUD_RATE_ADJ5, 0x00000726},
{AUD_DEEMPHDENOM1_R, 0x0000F3D0},
{AUD_DEEMPHDENOM2_R, 0x00000000},
{AUD_ERRLOGPERIOD_R, 0x00000064},
{AUD_ERRINTRPTTHSHLD1_R, 0x00000FFF},
{AUD_ERRINTRPTTHSHLD2_R, 0x0000001F},
{AUD_ERRINTRPTTHSHLD3_R, 0x0000000F},
{AUD_POLYPH80SCALEFAC, 0x00000003},
{AUD_DMD_RA_DDS, 0x00C00000},
{AUD_PLL_INT, 0x0000001E},
{AUD_PLL_DDS, 0x00000000},
{AUD_PLL_FRAC, 0x0000E542},
{AUD_START_TIMER, 0x00000000},
{AUD_DEEMPHNUMER1_R, 0x000353DE},
{AUD_DEEMPHNUMER2_R, 0x000001B1},
{AUD_PDF_DDS_CNST_BYTE2, 0x06},
{AUD_PDF_DDS_CNST_BYTE1, 0x82},
{AUD_PDF_DDS_CNST_BYTE0, 0x12},
{AUD_QAM_MODE, 0x05},
{AUD_PHACC_FREQ_8MSB, 0x34},
{AUD_PHACC_FREQ_8LSB, 0x4C},
{AUD_DEEMPHGAIN_R, 0x00006680},
{AUD_RATE_THRES_DMD, 0x000000C0},
{ },
};
static const struct rlist nicam_bgdki_common[] = {
{AUD_AFE_12DB_EN, 0x00000001},
{AUD_RATE_ADJ1, 0x00000010},
{AUD_RATE_ADJ2, 0x00000040},
{AUD_RATE_ADJ3, 0x00000100},
{AUD_RATE_ADJ4, 0x00000400},
{AUD_RATE_ADJ5, 0x00001000},
{AUD_ERRLOGPERIOD_R, 0x00000fff},
{AUD_ERRINTRPTTHSHLD1_R, 0x000003ff},
{AUD_ERRINTRPTTHSHLD2_R, 0x000000ff},
{AUD_ERRINTRPTTHSHLD3_R, 0x0000003f},
{AUD_POLYPH80SCALEFAC, 0x00000003},
{AUD_DEEMPHGAIN_R, 0x000023c2},
{AUD_DEEMPHNUMER1_R, 0x0002a7bc},
{AUD_DEEMPHNUMER2_R, 0x0003023e},
{AUD_DEEMPHDENOM1_R, 0x0000f3d0},
{AUD_DEEMPHDENOM2_R, 0x00000000},
{AUD_PDF_DDS_CNST_BYTE2, 0x06},
{AUD_PDF_DDS_CNST_BYTE1, 0x82},
{AUD_QAM_MODE, 0x05},
{ },
};
static const struct rlist nicam_i[] = {
{AUD_PDF_DDS_CNST_BYTE0, 0x12},
{AUD_PHACC_FREQ_8MSB, 0x3a},
{AUD_PHACC_FREQ_8LSB, 0x93},
{ },
};
static const struct rlist nicam_default[] = {
{AUD_PDF_DDS_CNST_BYTE0, 0x16},
{AUD_PHACC_FREQ_8MSB, 0x34},
{AUD_PHACC_FREQ_8LSB, 0x4c},
{ },
};
set_audio_start(core, SEL_NICAM);
switch (core->tvaudio) {
case WW_L:
dprintk("%s SECAM-L NICAM (status: devel)\n", __func__);
set_audio_registers(core, nicam_l);
break;
case WW_I:
dprintk("%s PAL-I NICAM (status: known-good)\n", __func__);
set_audio_registers(core, nicam_bgdki_common);
set_audio_registers(core, nicam_i);
break;
case WW_NONE:
case WW_BTSC:
case WW_BG:
case WW_DK:
case WW_EIAJ:
case WW_I2SPT:
case WW_FM:
case WW_I2SADC:
case WW_M:
dprintk("%s PAL-BGDK NICAM (status: known-good)\n", __func__);
set_audio_registers(core, nicam_bgdki_common);
set_audio_registers(core, nicam_default);
break;
}
mode |= EN_DMTRX_LR | EN_DMTRX_BYPASS;
set_audio_finish(core, mode);
}
static void set_audio_standard_A2(struct cx88_core *core, u32 mode)
{
static const struct rlist a2_bgdk_common[] = {
{AUD_ERRLOGPERIOD_R, 0x00000064},
{AUD_ERRINTRPTTHSHLD1_R, 0x00000fff},
{AUD_ERRINTRPTTHSHLD2_R, 0x0000001f},
{AUD_ERRINTRPTTHSHLD3_R, 0x0000000f},
{AUD_PDF_DDS_CNST_BYTE2, 0x06},
{AUD_PDF_DDS_CNST_BYTE1, 0x82},
{AUD_PDF_DDS_CNST_BYTE0, 0x12},
{AUD_QAM_MODE, 0x05},
{AUD_PHACC_FREQ_8MSB, 0x34},
{AUD_PHACC_FREQ_8LSB, 0x4c},
{AUD_RATE_ADJ1, 0x00000100},
{AUD_RATE_ADJ2, 0x00000200},
{AUD_RATE_ADJ3, 0x00000300},
{AUD_RATE_ADJ4, 0x00000400},
{AUD_RATE_ADJ5, 0x00000500},
{AUD_THR_FR, 0x00000000},
{AAGC_HYST, 0x0000001a},
{AUD_PILOT_BQD_1_K0, 0x0000755b},
{AUD_PILOT_BQD_1_K1, 0x00551340},
{AUD_PILOT_BQD_1_K2, 0x006d30be},
{AUD_PILOT_BQD_1_K3, 0xffd394af},
{AUD_PILOT_BQD_1_K4, 0x00400000},
{AUD_PILOT_BQD_2_K0, 0x00040000},
{AUD_PILOT_BQD_2_K1, 0x002a4841},
{AUD_PILOT_BQD_2_K2, 0x00400000},
{AUD_PILOT_BQD_2_K3, 0x00000000},
{AUD_PILOT_BQD_2_K4, 0x00000000},
{AUD_MODE_CHG_TIMER, 0x00000040},
{AUD_AFE_12DB_EN, 0x00000001},
{AUD_CORDIC_SHIFT_0, 0x00000007},
{AUD_CORDIC_SHIFT_1, 0x00000007},
{AUD_DEEMPH0_G0, 0x00000380},
{AUD_DEEMPH1_G0, 0x00000380},
{AUD_DCOC_0_SRC, 0x0000001a},
{AUD_DCOC0_SHIFT, 0x00000000},
{AUD_DCOC_0_SHIFT_IN0, 0x0000000a},
{AUD_DCOC_0_SHIFT_IN1, 0x00000008},
{AUD_DCOC_PASS_IN, 0x00000003},
{AUD_IIR3_0_SEL, 0x00000021},
{AUD_DN2_AFC, 0x00000002},
{AUD_DCOC_1_SRC, 0x0000001b},
{AUD_DCOC1_SHIFT, 0x00000000},
{AUD_DCOC_1_SHIFT_IN0, 0x0000000a},
{AUD_DCOC_1_SHIFT_IN1, 0x00000008},
{AUD_IIR3_1_SEL, 0x00000023},
{AUD_RDSI_SEL, 0x00000017},
{AUD_RDSI_SHIFT, 0x00000000},
{AUD_RDSQ_SEL, 0x00000017},
{AUD_RDSQ_SHIFT, 0x00000000},
{AUD_PLL_INT, 0x0000001e},
{AUD_PLL_DDS, 0x00000000},
{AUD_PLL_FRAC, 0x0000e542},
{AUD_POLYPH80SCALEFAC, 0x00000001},
{AUD_START_TIMER, 0x00000000},
{ },
};
static const struct rlist a2_bg[] = {
{AUD_DMD_RA_DDS, 0x002a4f2f},
{AUD_C1_UP_THR, 0x00007000},
{AUD_C1_LO_THR, 0x00005400},
{AUD_C2_UP_THR, 0x00005400},
{AUD_C2_LO_THR, 0x00003000},
{ },
};
static const struct rlist a2_dk[] = {
{AUD_DMD_RA_DDS, 0x002a4f2f},
{AUD_C1_UP_THR, 0x00007000},
{AUD_C1_LO_THR, 0x00005400},
{AUD_C2_UP_THR, 0x00005400},
{AUD_C2_LO_THR, 0x00003000},
{AUD_DN0_FREQ, 0x00003a1c},
{AUD_DN2_FREQ, 0x0000d2e0},
{ },
};
static const struct rlist a1_i[] = {
{AUD_ERRLOGPERIOD_R, 0x00000064},
{AUD_ERRINTRPTTHSHLD1_R, 0x00000fff},
{AUD_ERRINTRPTTHSHLD2_R, 0x0000001f},
{AUD_ERRINTRPTTHSHLD3_R, 0x0000000f},
{AUD_PDF_DDS_CNST_BYTE2, 0x06},
{AUD_PDF_DDS_CNST_BYTE1, 0x82},
{AUD_PDF_DDS_CNST_BYTE0, 0x12},
{AUD_QAM_MODE, 0x05},
{AUD_PHACC_FREQ_8MSB, 0x3a},
{AUD_PHACC_FREQ_8LSB, 0x93},
{AUD_DMD_RA_DDS, 0x002a4f2f},
{AUD_PLL_INT, 0x0000001e},
{AUD_PLL_DDS, 0x00000004},
{AUD_PLL_FRAC, 0x0000e542},
{AUD_RATE_ADJ1, 0x00000100},
{AUD_RATE_ADJ2, 0x00000200},
{AUD_RATE_ADJ3, 0x00000300},
{AUD_RATE_ADJ4, 0x00000400},
{AUD_RATE_ADJ5, 0x00000500},
{AUD_THR_FR, 0x00000000},
{AUD_PILOT_BQD_1_K0, 0x0000755b},
{AUD_PILOT_BQD_1_K1, 0x00551340},
{AUD_PILOT_BQD_1_K2, 0x006d30be},
{AUD_PILOT_BQD_1_K3, 0xffd394af},
{AUD_PILOT_BQD_1_K4, 0x00400000},
{AUD_PILOT_BQD_2_K0, 0x00040000},
{AUD_PILOT_BQD_2_K1, 0x002a4841},
{AUD_PILOT_BQD_2_K2, 0x00400000},
{AUD_PILOT_BQD_2_K3, 0x00000000},
{AUD_PILOT_BQD_2_K4, 0x00000000},
{AUD_MODE_CHG_TIMER, 0x00000060},
{AUD_AFE_12DB_EN, 0x00000001},
{AAGC_HYST, 0x0000000a},
{AUD_CORDIC_SHIFT_0, 0x00000007},
{AUD_CORDIC_SHIFT_1, 0x00000007},
{AUD_C1_UP_THR, 0x00007000},
{AUD_C1_LO_THR, 0x00005400},
{AUD_C2_UP_THR, 0x00005400},
{AUD_C2_LO_THR, 0x00003000},
{AUD_DCOC_0_SRC, 0x0000001a},
{AUD_DCOC0_SHIFT, 0x00000000},
{AUD_DCOC_0_SHIFT_IN0, 0x0000000a},
{AUD_DCOC_0_SHIFT_IN1, 0x00000008},
{AUD_DCOC_PASS_IN, 0x00000003},
{AUD_IIR3_0_SEL, 0x00000021},
{AUD_DN2_AFC, 0x00000002},
{AUD_DCOC_1_SRC, 0x0000001b},
{AUD_DCOC1_SHIFT, 0x00000000},
{AUD_DCOC_1_SHIFT_IN0, 0x0000000a},
{AUD_DCOC_1_SHIFT_IN1, 0x00000008},
{AUD_IIR3_1_SEL, 0x00000023},
{AUD_DN0_FREQ, 0x000035a3},
{AUD_DN2_FREQ, 0x000029c7},
{AUD_CRDC0_SRC_SEL, 0x00000511},
{AUD_IIR1_0_SEL, 0x00000001},
{AUD_IIR1_1_SEL, 0x00000000},
{AUD_IIR3_2_SEL, 0x00000003},
{AUD_IIR3_2_SHIFT, 0x00000000},
{AUD_IIR3_0_SEL, 0x00000002},
{AUD_IIR2_0_SEL, 0x00000021},
{AUD_IIR2_0_SHIFT, 0x00000002},
{AUD_DEEMPH0_SRC_SEL, 0x0000000b},
{AUD_DEEMPH1_SRC_SEL, 0x0000000b},
{AUD_POLYPH80SCALEFAC, 0x00000001},
{AUD_START_TIMER, 0x00000000},
{ },
};
static const struct rlist am_l[] = {
{AUD_ERRLOGPERIOD_R, 0x00000064},
{AUD_ERRINTRPTTHSHLD1_R, 0x00000FFF},
{AUD_ERRINTRPTTHSHLD2_R, 0x0000001F},
{AUD_ERRINTRPTTHSHLD3_R, 0x0000000F},
{AUD_PDF_DDS_CNST_BYTE2, 0x48},
{AUD_PDF_DDS_CNST_BYTE1, 0x3D},
{AUD_QAM_MODE, 0x00},
{AUD_PDF_DDS_CNST_BYTE0, 0xf5},
{AUD_PHACC_FREQ_8MSB, 0x3a},
{AUD_PHACC_FREQ_8LSB, 0x4a},
{AUD_DEEMPHGAIN_R, 0x00006680},
{AUD_DEEMPHNUMER1_R, 0x000353DE},
{AUD_DEEMPHNUMER2_R, 0x000001B1},
{AUD_DEEMPHDENOM1_R, 0x0000F3D0},
{AUD_DEEMPHDENOM2_R, 0x00000000},
{AUD_FM_MODE_ENABLE, 0x00000007},
{AUD_POLYPH80SCALEFAC, 0x00000003},
{AUD_AFE_12DB_EN, 0x00000001},
{AAGC_GAIN, 0x00000000},
{AAGC_HYST, 0x00000018},
{AAGC_DEF, 0x00000020},
{AUD_DN0_FREQ, 0x00000000},
{AUD_POLY0_DDS_CONSTANT, 0x000E4DB2},
{AUD_DCOC_0_SRC, 0x00000021},
{AUD_IIR1_0_SEL, 0x00000000},
{AUD_IIR1_0_SHIFT, 0x00000007},
{AUD_IIR1_1_SEL, 0x00000002},
{AUD_IIR1_1_SHIFT, 0x00000000},
{AUD_DCOC_1_SRC, 0x00000003},
{AUD_DCOC1_SHIFT, 0x00000000},
{AUD_DCOC_PASS_IN, 0x00000000},
{AUD_IIR1_2_SEL, 0x00000023},
{AUD_IIR1_2_SHIFT, 0x00000000},
{AUD_IIR1_3_SEL, 0x00000004},
{AUD_IIR1_3_SHIFT, 0x00000007},
{AUD_IIR1_4_SEL, 0x00000005},
{AUD_IIR1_4_SHIFT, 0x00000007},
{AUD_IIR3_0_SEL, 0x00000007},
{AUD_IIR3_0_SHIFT, 0x00000000},
{AUD_DEEMPH0_SRC_SEL, 0x00000011},
{AUD_DEEMPH0_SHIFT, 0x00000000},
{AUD_DEEMPH0_G0, 0x00007000},
{AUD_DEEMPH0_A0, 0x00000000},
{AUD_DEEMPH0_B0, 0x00000000},
{AUD_DEEMPH0_A1, 0x00000000},
{AUD_DEEMPH0_B1, 0x00000000},
{AUD_DEEMPH1_SRC_SEL, 0x00000011},
{AUD_DEEMPH1_SHIFT, 0x00000000},
{AUD_DEEMPH1_G0, 0x00007000},
{AUD_DEEMPH1_A0, 0x00000000},
{AUD_DEEMPH1_B0, 0x00000000},
{AUD_DEEMPH1_A1, 0x00000000},
{AUD_DEEMPH1_B1, 0x00000000},
{AUD_OUT0_SEL, 0x0000003F},
{AUD_OUT1_SEL, 0x0000003F},
{AUD_DMD_RA_DDS, 0x00F5C285},
{AUD_PLL_INT, 0x0000001E},
{AUD_PLL_DDS, 0x00000000},
{AUD_PLL_FRAC, 0x0000E542},
{AUD_RATE_ADJ1, 0x00000100},
{AUD_RATE_ADJ2, 0x00000200},
{AUD_RATE_ADJ3, 0x00000300},
{AUD_RATE_ADJ4, 0x00000400},
{AUD_RATE_ADJ5, 0x00000500},
{AUD_RATE_THRES_DMD, 0x000000C0},
{ },
};
static const struct rlist a2_deemph50[] = {
{AUD_DEEMPH0_G0, 0x00000380},
{AUD_DEEMPH1_G0, 0x00000380},
{AUD_DEEMPHGAIN_R, 0x000011e1},
{AUD_DEEMPHNUMER1_R, 0x0002a7bc},
{AUD_DEEMPHNUMER2_R, 0x0003023c},
{ },
};
set_audio_start(core, SEL_A2);
switch (core->tvaudio) {
case WW_BG:
dprintk("%s PAL-BG A1/2 (status: known-good)\n", __func__);
set_audio_registers(core, a2_bgdk_common);
set_audio_registers(core, a2_bg);
set_audio_registers(core, a2_deemph50);
break;
case WW_DK:
dprintk("%s PAL-DK A1/2 (status: known-good)\n", __func__);
set_audio_registers(core, a2_bgdk_common);
set_audio_registers(core, a2_dk);
set_audio_registers(core, a2_deemph50);
break;
case WW_I:
dprintk("%s PAL-I A1 (status: known-good)\n", __func__);
set_audio_registers(core, a1_i);
set_audio_registers(core, a2_deemph50);
break;
case WW_L:
dprintk("%s AM-L (status: devel)\n", __func__);
set_audio_registers(core, am_l);
break;
case WW_NONE:
case WW_BTSC:
case WW_EIAJ:
case WW_I2SPT:
case WW_FM:
case WW_I2SADC:
case WW_M:
dprintk("%s Warning: wrong value\n", __func__);
return;
}
mode |= EN_FMRADIO_EN_RDS | EN_DMTRX_SUMDIFF;
set_audio_finish(core, mode);
}
static void set_audio_standard_EIAJ(struct cx88_core *core)
{
static const struct rlist eiaj[] = {
{ },
};
dprintk("%s (status: unknown)\n", __func__);
set_audio_start(core, SEL_EIAJ);
set_audio_registers(core, eiaj);
set_audio_finish(core, EN_EIAJ_AUTO_STEREO);
}
static void set_audio_standard_FM(struct cx88_core *core,
enum cx88_deemph_type deemph)
{
static const struct rlist fm_deemph_50[] = {
{AUD_DEEMPH0_G0, 0x0C45},
{AUD_DEEMPH0_A0, 0x6262},
{AUD_DEEMPH0_B0, 0x1C29},
{AUD_DEEMPH0_A1, 0x3FC66},
{AUD_DEEMPH0_B1, 0x399A},
{AUD_DEEMPH1_G0, 0x0D80},
{AUD_DEEMPH1_A0, 0x6262},
{AUD_DEEMPH1_B0, 0x1C29},
{AUD_DEEMPH1_A1, 0x3FC66},
{AUD_DEEMPH1_B1, 0x399A},
{AUD_POLYPH80SCALEFAC, 0x0003},
{ },
};
static const struct rlist fm_deemph_75[] = {
{AUD_DEEMPH0_G0, 0x091B},
{AUD_DEEMPH0_A0, 0x6B68},
{AUD_DEEMPH0_B0, 0x11EC},
{AUD_DEEMPH0_A1, 0x3FC66},
{AUD_DEEMPH0_B1, 0x399A},
{AUD_DEEMPH1_G0, 0x0AA0},
{AUD_DEEMPH1_A0, 0x6B68},
{AUD_DEEMPH1_B0, 0x11EC},
{AUD_DEEMPH1_A1, 0x3FC66},
{AUD_DEEMPH1_B1, 0x399A},
{AUD_POLYPH80SCALEFAC, 0x0003},
{ },
};
static const struct rlist fm_no_deemph[] = {
{AUD_POLYPH80SCALEFAC, 0x0003},
{ },
};
dprintk("%s (status: unknown)\n", __func__);
set_audio_start(core, SEL_FMRADIO);
switch (deemph) {
default:
case FM_NO_DEEMPH:
set_audio_registers(core, fm_no_deemph);
break;
case FM_DEEMPH_50:
set_audio_registers(core, fm_deemph_50);
break;
case FM_DEEMPH_75:
set_audio_registers(core, fm_deemph_75);
break;
}
set_audio_finish(core, EN_FMRADIO_AUTO_STEREO);
}
static int cx88_detect_nicam(struct cx88_core *core)
{
int i, j = 0;
dprintk("start nicam autodetect.\n");
for (i = 0; i < 6; i++) {
j += ((cx_read(AUD_NICAM_STATUS2) & 0x02) >> 1);
if (j == 1) {
dprintk("nicam is detected.\n");
return 1;
}
usleep_range(10000, 20000);
}
dprintk("nicam is not detected.\n");
return 0;
}
void cx88_set_tvaudio(struct cx88_core *core)
{
switch (core->tvaudio) {
case WW_BTSC:
set_audio_standard_BTSC(core, 0, EN_BTSC_AUTO_STEREO);
break;
case WW_BG:
case WW_DK:
case WW_M:
case WW_I:
case WW_L:
set_audio_standard_A2(core, EN_A2_FORCE_MONO1);
set_audio_standard_NICAM(core, EN_NICAM_AUTO_STEREO);
if (cx88_detect_nicam(core) == 0) {
set_audio_standard_A2(core, EN_A2_FORCE_MONO1);
core->audiomode_current = V4L2_TUNER_MODE_MONO;
core->use_nicam = 0;
} else {
core->use_nicam = 1;
}
break;
case WW_EIAJ:
set_audio_standard_EIAJ(core);
break;
case WW_FM:
set_audio_standard_FM(core, radio_deemphasis);
break;
case WW_I2SADC:
set_audio_start(core, 0x01);
cx_write(AUD_I2SINPUTCNTL, core->board.i2sinputcntl);
cx_write(AUD_I2SCNTL, 0x1);
set_audio_finish(core, EN_I2SIN_ENABLE);
break;
case WW_NONE:
case WW_I2SPT:
pr_info("unknown tv audio mode [%d]\n", core->tvaudio);
break;
}
}
void cx88_newstation(struct cx88_core *core)
{
core->audiomode_manual = UNSET;
core->last_change = jiffies;
}
void cx88_get_stereo(struct cx88_core *core, struct v4l2_tuner *t)
{
static const char * const m[] = { "stereo", "dual mono",
"mono", "sap" };
static const char * const p[] = { "no pilot", "pilot c1",
"pilot c2", "?" };
u32 reg, mode, pilot;
reg = cx_read(AUD_STATUS);
mode = reg & 0x03;
pilot = (reg >> 2) & 0x03;
if (core->astat != reg)
dprintk("AUD_STATUS: 0x%x [%s/%s] ctl=%s\n",
reg, m[mode], p[pilot],
aud_ctl_names[cx_read(AUD_CTL) & 63]);
core->astat = reg;
t->capability = V4L2_TUNER_CAP_STEREO | V4L2_TUNER_CAP_SAP |
V4L2_TUNER_CAP_LANG1 | V4L2_TUNER_CAP_LANG2;
t->rxsubchans = UNSET;
t->audmode = V4L2_TUNER_MODE_MONO;
switch (mode) {
case 0:
t->audmode = V4L2_TUNER_MODE_STEREO;
break;
case 1:
t->audmode = V4L2_TUNER_MODE_LANG2;
break;
case 2:
t->audmode = V4L2_TUNER_MODE_MONO;
break;
case 3:
t->audmode = V4L2_TUNER_MODE_SAP;
break;
}
switch (core->tvaudio) {
case WW_BTSC:
case WW_BG:
case WW_DK:
case WW_M:
case WW_EIAJ:
if (!core->use_nicam) {
t->rxsubchans = cx88_dsp_detect_stereo_sap(core);
break;
}
break;
case WW_NONE:
case WW_I:
case WW_L:
case WW_I2SPT:
case WW_FM:
case WW_I2SADC:
break;
}
if (t->rxsubchans == UNSET) {
t->rxsubchans = V4L2_TUNER_SUB_MONO;
if (t->audmode == V4L2_TUNER_MODE_STEREO)
t->rxsubchans |= V4L2_TUNER_SUB_STEREO;
}
}
void cx88_set_stereo(struct cx88_core *core, u32 mode, int manual)
{
u32 ctl = UNSET;
u32 mask = UNSET;
if (manual) {
core->audiomode_manual = mode;
} else {
if (core->audiomode_manual != UNSET)
return;
}
core->audiomode_current = mode;
switch (core->tvaudio) {
case WW_BTSC:
switch (mode) {
case V4L2_TUNER_MODE_MONO:
set_audio_standard_BTSC(core, 0, EN_BTSC_FORCE_MONO);
break;
case V4L2_TUNER_MODE_LANG1:
set_audio_standard_BTSC(core, 0, EN_BTSC_AUTO_STEREO);
break;
case V4L2_TUNER_MODE_LANG2:
set_audio_standard_BTSC(core, 1, EN_BTSC_FORCE_SAP);
break;
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1_LANG2:
set_audio_standard_BTSC(core, 0, EN_BTSC_FORCE_STEREO);
break;
}
break;
case WW_BG:
case WW_DK:
case WW_M:
case WW_I:
case WW_L:
if (core->use_nicam == 1) {
switch (mode) {
case V4L2_TUNER_MODE_MONO:
case V4L2_TUNER_MODE_LANG1:
set_audio_standard_NICAM(core,
EN_NICAM_FORCE_MONO1);
break;
case V4L2_TUNER_MODE_LANG2:
set_audio_standard_NICAM(core,
EN_NICAM_FORCE_MONO2);
break;
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1_LANG2:
set_audio_standard_NICAM(core,
EN_NICAM_FORCE_STEREO);
break;
}
} else {
if ((core->tvaudio == WW_I) ||
(core->tvaudio == WW_L)) {
set_audio_standard_A2(core, EN_A2_FORCE_MONO1);
} else {
mask = 0x3f;
switch (mode) {
case V4L2_TUNER_MODE_MONO:
case V4L2_TUNER_MODE_LANG1:
ctl = EN_A2_FORCE_MONO1;
break;
case V4L2_TUNER_MODE_LANG2:
ctl = EN_A2_FORCE_MONO2;
break;
case V4L2_TUNER_MODE_STEREO:
case V4L2_TUNER_MODE_LANG1_LANG2:
ctl = EN_A2_FORCE_STEREO;
break;
}
}
}
break;
case WW_FM:
switch (mode) {
case V4L2_TUNER_MODE_MONO:
ctl = EN_FMRADIO_FORCE_MONO;
mask = 0x3f;
break;
case V4L2_TUNER_MODE_STEREO:
ctl = EN_FMRADIO_AUTO_STEREO;
mask = 0x3f;
break;
}
break;
case WW_I2SADC:
case WW_NONE:
case WW_EIAJ:
case WW_I2SPT:
break;
}
if (ctl != UNSET) {
dprintk("cx88_set_stereo: mask 0x%x, ctl 0x%x [status=0x%x,ctl=0x%x,vol=0x%x]\n",
mask, ctl, cx_read(AUD_STATUS),
cx_read(AUD_CTL), cx_sread(SHADOW_AUD_VOL_CTL));
cx_andor(AUD_CTL, mask, ctl);
}
}
int cx88_audio_thread(void *data)
{
struct cx88_core *core = data;
struct v4l2_tuner t;
u32 mode = 0;
dprintk("cx88: tvaudio thread started\n");
set_freezable();
for (;;) {
msleep_interruptible(1000);
if (kthread_should_stop())
break;
try_to_freeze();
switch (core->tvaudio) {
case WW_BG:
case WW_DK:
case WW_M:
case WW_I:
case WW_L:
if (core->use_nicam)
goto hw_autodetect;
memset(&t, 0, sizeof(t));
cx88_get_stereo(core, &t);
if (core->audiomode_manual != UNSET)
continue;
if (t.rxsubchans & V4L2_TUNER_SUB_STEREO)
mode = V4L2_TUNER_MODE_STEREO;
else
mode = V4L2_TUNER_MODE_MONO;
if (mode == core->audiomode_current)
continue;
cx88_set_stereo(core, mode, 0);
break;
case WW_NONE:
case WW_BTSC:
case WW_EIAJ:
case WW_I2SPT:
case WW_FM:
case WW_I2SADC:
hw_autodetect:
break;
}
}
dprintk("cx88: tvaudio thread exiting\n");
return 0;
}
