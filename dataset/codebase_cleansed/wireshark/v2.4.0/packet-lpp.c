static void
lpp_degreesLatitude_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%f degrees (%u)",
((float)v/8388607.0)*90, v);
}
static void
lpp_degreesLongitude_fmt(gchar *s, guint32 v)
{
gint32 longitude = (gint32) v;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f degrees (%d)",
((float)longitude/8388608.0)*180, longitude);
}
static void
lpp_uncertainty_fmt(gchar *s, guint32 v)
{
double uncertainty = 10*(pow(1.1, (double)v)-1);
if (uncertainty < 1000) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm (%u)", uncertainty, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%fkm (%u)", uncertainty/1000, v);
}
}
static void
lpp_angle_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u degrees (%u)", 2*v, v);
}
static void
lpp_confidence_fmt(gchar *s, guint32 v)
{
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "no information (0)");
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u%%", v);
}
}
static void
lpp_altitude_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%um", v);
}
static void
lpp_uncertaintyAltitude_fmt(gchar *s, guint32 v)
{
double uncertainty = 45*(pow(1.025, (double)v)-1);
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm (%u)", uncertainty, v);
}
static void
lpp_radius_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%um (%u)", 5*v, v);
}
static void
lpp_expectedRSTD_fmt(gchar *s, guint32 v)
{
gint32 rstd = 3*((gint32)v-8192);
g_snprintf(s, ITEM_LABEL_LENGTH, "%dTs (%u)", rstd, v);
}
static void
lpp_expectedRSTD_Uncertainty_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs (%u)", 3*v, v);
}
static void
lpp_rstd_fmt(gchar *s, guint32 v)
{
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "RSTD < -15391Ts (0)");
} else if (v < 2260) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-%uTs <= RSTD < -%uTs (%u)", 15391-5*(v-1), 15391-5*v, v);
} else if (v < 6355) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-%uTs <= RSTD < -%uTs (%u)", 6356-v, 6355-v, v);
} else if (v == 6355) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-1Ts <= RSTD <= 0Ts (6355)");
} else if (v < 10452) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs < RSTD <= %uTs (%u)", v-6356, v-6355, v);
} else if (v < 12711) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs < RSTD <= %uTs (%u)", 5*(v-1)-48159, 5*v-48159, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "15391Ts < RSTD (12711)");
}
}
static void
lpp_referenceTimeUnc_fmt(gchar *s, guint32 v)
{
double referenceTimeUnc = 0.5*(pow(1.14, (double)v)-1);
g_snprintf(s, ITEM_LABEL_LENGTH, "%fus (%u)", referenceTimeUnc, v);
}
static void
lpp_fractionalSecondsFromFrameStructureStart_fmt(gchar *s, guint32 v)
{
float frac = ((float)v)/4;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fus (%u)", frac, v);
}
static void
lpp_frameDrift_fmt(gchar *s, guint32 v)
{
double drift = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", drift, (gint32)v);
}
static void
lpp_alpha0_fmt(gchar *s, guint32 v)
{
double alpha = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", alpha, (gint32)v);
}
static void
lpp_alpha1_fmt(gchar *s, guint32 v)
{
double alpha = (double)((gint32)v)*pow(2, -27);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/semi-circle (%d)", alpha, (gint32)v);
}
static void
lpp_alpha2_3_fmt(gchar *s, guint32 v)
{
double alpha = (double)((gint32)v)*pow(2, -24);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/semi-circle (%d)", alpha, (gint32)v);
}
static void
lpp_beta0_fmt(gchar *s, guint32 v)
{
double beta = (double)((gint32)v)*pow(2, 11);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", beta, (gint32)v);
}
static void
lpp_beta1_fmt(gchar *s, guint32 v)
{
double beta = (double)((gint32)v)*pow(2, 14);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/semi-circle (%d)", beta, (gint32)v);
}
static void
lpp_beta2_3_fmt(gchar *s, guint32 v)
{
double beta = (double)((gint32)v)*pow(2, 16);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/semi-circle (%d)", beta, (gint32)v);
}
static void
lpp_ai0_fmt(gchar *s, guint32 v)
{
double ai = (double)v*pow(2, -2);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gsfu (%u)", ai, v);
}
static void
lpp_ai1_fmt(gchar *s, guint32 v)
{
double ai = (double)v*pow(2, -8);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gsfu/degree (%u)", ai, v);
}
static void
lpp_ai2_fmt(gchar *s, guint32 v)
{
double ai = (double)v*pow(2, -15);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gsfu/degree2 (%u)", ai, v);
}
static void
lpp_teop_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", 16*v, v);
}
static void
lpp_pmX_Y_fmt(gchar *s, guint32 v)
{
double pm = (double)((gint32)v)*pow(2, -20);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g arc-seconds (%d)", pm, (gint32)v);
}
static void
lpp_pmX_Ydot_fmt(gchar *s, guint32 v)
{
double pmDot = (double)((gint32)v)*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g arc-seconds/day (%d)", pmDot, (gint32)v);
}
static void
lpp_deltaUT1_fmt(gchar *s, guint32 v)
{
double deltaUT1 = (double)((gint32)v)*pow(2, -24);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", deltaUT1, (gint32)v);
}
static void
lpp_deltaUT1dot_fmt(gchar *s, guint32 v)
{
double deltaUT1dot = (double)((gint32)v)*pow(2, -25);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/day (%d)", deltaUT1dot, (gint32)v);
}
static void
lpp_gnss_TimeModelRefTime_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", v*16, v);
}
static void
lpp_tA0_fmt(gchar *s, guint32 v)
{
double tA0 = (double)((gint32)v)*pow(2, -35);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", tA0, (gint32)v);
}
static void
lpp_tA1_fmt(gchar *s, guint32 v)
{
double tA1 = (double)((gint32)v)*pow(2, -51);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", tA1, (gint32)v);
}
static void
lpp_tA2_fmt(gchar *s, guint32 v)
{
double tA2 = (double)((gint32)v)*pow(2, -68);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s2 (%d)", tA2, (gint32)v);
}
static void
lpp_pseudoRangeCor_fmt(gchar *s, guint32 v)
{
double pseudoRangeCor = ((double)(gint32)v)*0.32;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm (%d)", pseudoRangeCor, (gint32)v);
}
static void
lpp_rangeRateCor_fmt(gchar *s, guint32 v)
{
double rangeRateCor = ((double)(gint32)v)*0.032;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm/s (%d)", rangeRateCor, (gint32)v);
}
static void
lpp_stanClockToc_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%um/s (%u)", 60*v, v);
}
static void
lpp_stanClockAF2_fmt(gchar *s, guint32 v)
{
double stanClockAF2 = (double)((gint32)v)*pow(2, -59);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s2 (%d)", stanClockAF2, (gint32)v);
}
static void
lpp_stanClockAF1_fmt(gchar *s, guint32 v)
{
double stanClockAF1 = (double)((gint32)v)*pow(2, -46);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", stanClockAF1, (gint32)v);
}
static void
lpp_stanClockAF0_fmt(gchar *s, guint32 v)
{
double stanClockAF0 = (double)((gint32)v)*pow(2, -34);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", stanClockAF0, (gint32)v);
}
static void
lpp_stanClockTgd_fmt(gchar *s, guint32 v)
{
double stanClockTgd = (double)((gint32)v)*pow(2, -32);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", stanClockTgd, (gint32)v);
}
static void
lpp_sisa_fmt(gchar *s, guint32 v)
{
if (v < 50) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%ucm (%u)", v, v);
} else if (v < 75) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%ucm (%u)", 50+((v-50)*2), v);
} else if (v < 100) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%ucm (%u)", 100+((v-75)*4), v);
} else if (v < 126) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%ucm (%u)", 200+((v-100)*16), v);
} else if (v < 255) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Spare (%u)", v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "No Accuracy Prediction Available (255)");
}
}
static void
lpp_navToc_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", 16*v, v);
}
static void
lpp_navaf2_fmt(gchar *s, guint32 v)
{
double navaf2 = (double)((gint32)v)*pow(2, -55);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s2 (%d)", navaf2, (gint32)v);
}
static void
lpp_navaf1_fmt(gchar *s, guint32 v)
{
double navaf1 = (double)((gint32)v)*pow(2, -43);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", navaf1, (gint32)v);
}
static void
lpp_navaf0_navTgd_fmt(gchar *s, guint32 v)
{
double navaf0_navTgd = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", navaf0_navTgd, (gint32)v);
}
static void
lpp_cnavToc_cnavTop_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", 300*v, v);
}
static void
lpp_cnavAf2_fmt(gchar *s, guint32 v)
{
double cnavAf2 = (double)((gint32)v)*pow(2, -60);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s2 (%d)", cnavAf2, (gint32)v);
}
static void
lpp_cnavAf1_fmt(gchar *s, guint32 v)
{
double cnavAf1 = (double)((gint32)v)*pow(2, -48);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", cnavAf1, (gint32)v);
}
static void
lpp_cnavX_fmt(gchar *s, guint32 v)
{
double cnavX = (double)((gint32)v)*pow(2, -35);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", cnavX, (gint32)v);
}
static void
lpp_gloTau_gloDeltaTau_fmt(gchar *s, guint32 v)
{
double gloTau_gloDeltaTau = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", gloTau_gloDeltaTau, (gint32)v);
}
static void
lpp_gloGamma_fmt(gchar *s, guint32 v)
{
double gloGamma = (double)((gint32)v)*pow(2, -40);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g (%d)", gloGamma, (gint32)v);
}
static void
lpp_sbasTo_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", 16*v, v);
}
static void
lpp_sbasAgfo_fmt(gchar *s, guint32 v)
{
double sbasAgfo = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", sbasAgfo, (gint32)v);
}
static void
lpp_sbasAgf1_fmt(gchar *s, guint32 v)
{
double sbasAgf1 = (double)((gint32)v)*pow(2, -40);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", sbasAgf1, (gint32)v);
}
static void
lpp_bdsAODC_AODE_r12_fmt(gchar *s, guint32 v)
{
if (v < 25) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Age of the satellite clock correction parameters is %u hours (%u)", v, v);
} else if (v < 31) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Age of the satellite clock correction parameters is %u days (%u)", v-23, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "Age of the satellite clock correction parameters is over 7 days (%u)", v);
}
}
static void
lpp_bdsToc_Toe_r12_fmt(gchar *s, guint32 v)
{
double bdsToc = (double)((gint32)v)*pow(2, 3);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", bdsToc, (gint32)v);
}
static void
lpp_bdsA0_r12_fmt(gchar *s, guint32 v)
{
double bdsA0 = (double)((gint32)v)*pow(2, -33);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", bdsA0, (gint32)v);
}
static void
lpp_bdsA1_r12_fmt(gchar *s, guint32 v)
{
double bdsA1 = (double)((gint32)v)*pow(2, -50);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", bdsA1, (gint32)v);
}
static void
lpp_bdsA2_r12_fmt(gchar *s, guint32 v)
{
double bdsA2 = (double)((gint32)v)*pow(2, -66);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s2 (%d)", bdsA2, (gint32)v);
}
static void
lpp_bdsTgd1_r12_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%gns (%d)", (float)((gint32)v)*0.1, (gint32)v);
}
static void
lpp_keplerToe_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", 60*v, v);
}
static void
lpp_keplerW_M0_I0_Omega0_fmt(gchar *s, guint32 v)
{
double keplerW_M0_I0_Omega0 = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", keplerW_M0_I0_Omega0, (gint32)v);
}
static void
lpp_keplerDeltaN_OmegaDot_IDot_fmt(gchar *s, guint32 v)
{
double keplerDeltaN_OmegaDot_IDot = (double)((gint32)v)*pow(2, -43);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", keplerDeltaN_OmegaDot_IDot, (gint32)v);
}
static void
lpp_keplerE_fmt(gchar *s, guint32 v)
{
double keplerE = (double)v*pow(2, -33);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g (%u)", keplerE, v);
}
static void
lpp_keplerAPowerHalf_fmt(gchar *s, guint32 v)
{
double keplerAPowerHalf = (double)v*pow(2, -19);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm1/2 (%u)", keplerAPowerHalf, v);
}
static void
lpp_keplerCrs_Crc_fmt(gchar *s, guint32 v)
{
double keplerCrs_Crc = (double)((gint32)v)*pow(2, -5);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm (%d)", keplerCrs_Crc, (gint32)v);
}
static void
lpp_keplerCx_fmt(gchar *s, guint32 v)
{
double keplerCx = (double)((gint32)v)*pow(2, -29);
g_snprintf(s, ITEM_LABEL_LENGTH, "%grad (%d)", keplerCx, (gint32)v);
}
static void
lpp_navToe_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", 16*v, v);
}
static void
lpp_navOmega_M0_I0_OmegaA0_fmt(gchar *s, guint32 v)
{
double navOmega_M0_I0_OmegaA0 = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", navOmega_M0_I0_OmegaA0, (gint32)v);
}
static void
lpp_navDeltaN_OmegaADot_IDot_fmt(gchar *s, guint32 v)
{
double navDeltaN_OmegaADot_IDot = (double)((gint32)v)*pow(2, -43);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", navDeltaN_OmegaADot_IDot, (gint32)v);
}
static void
lpp_navE_fmt(gchar *s, guint32 v)
{
double navE = (double)v*pow(2, -33);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g (%u)", navE, v);
}
static void
lpp_navAPowerHalf_fmt(gchar *s, guint32 v)
{
double navAPowerHalf = (double)v*pow(2, -19);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm1/2 (%u)", navAPowerHalf, v);
}
static void
lpp_navCrs_Crc_fmt(gchar *s, guint32 v)
{
double navCrs_Crc = (double)((gint32)v)*pow(2, -5);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm (%d)", navCrs_Crc, (gint32)v);
}
static void
lpp_navCx_fmt(gchar *s, guint32 v)
{
double navCx = (double)((gint32)v)*pow(2, -29);
g_snprintf(s, ITEM_LABEL_LENGTH, "%grad (%d)", navCx, (gint32)v);
}
static void
lpp_cnavDeltaA_fmt(gchar *s, guint32 v)
{
double cnavDeltaA = (double)((gint32)v)*pow(2, -9);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm (%d)", cnavDeltaA, (gint32)v);
}
static void
lpp_cnavAdot_fmt(gchar *s, guint32 v)
{
double cnavAdot = (double)((gint32)v)*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm/s (%d)", cnavAdot, (gint32)v);
}
static void
lpp_cnavDeltaNo_fmt(gchar *s, guint32 v)
{
double cnavDeltaNo = (double)((gint32)v)*pow(2, -44);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", cnavDeltaNo, (gint32)v);
}
static void
lpp_cnavDeltaNoDot_fmt(gchar *s, guint32 v)
{
double cnavDeltaNoDot = (double)((gint32)v)*pow(2, -57);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s2 (%d)", cnavDeltaNoDot, (gint32)v);
}
static void
lpp_cnavDeltaOmegaDot_IoDot_fmt(gchar *s, guint32 v)
{
double cnavDeltaOmegaDot_IoDot = (double)((gint32)v)*pow(2, -44);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", cnavDeltaOmegaDot_IoDot, (gint32)v);
}
static void
lpp_cnavCx_fmt(gchar *s, guint32 v)
{
double cnavCx = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%grad (%d)", cnavCx, (gint32)v);
}
static void
lpp_cnavCrs_Crc_fmt(gchar *s, guint32 v)
{
double cnavCrs_Crc = (double)((gint32)v)*pow(2, -8);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm (%d)", cnavCrs_Crc, (gint32)v);
}
static void
lpp_gloX_Y_Z_fmt(gchar *s, guint32 v)
{
double gloX_Y_Z = (double)((gint32)v)*pow(2, -11);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gkm (%d)", gloX_Y_Z, (gint32)v);
}
static void
lpp_gloXdot_Ydot_Zdot_fmt(gchar *s, guint32 v)
{
double gloXdot_Ydot_Zdot = (double)((gint32)v)*pow(2, -20);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gkm/s (%d)", gloXdot_Ydot_Zdot, (gint32)v);
}
static void
lpp_gloXdotdot_Ydotdot_Zdotdot_fmt(gchar *s, guint32 v)
{
double gloXdotdot_Ydotdot_Zdotdot = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gkm/s2 (%d)", gloXdotdot_Ydotdot_Zdotdot, (gint32)v);
}
static void
lpp_sbasXg_Yg_fmt(gchar *s, guint32 v)
{
double sbasXg_Yg = (double)((gint32)v)*0.08;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm (%d)", sbasXg_Yg, (gint32)v);
}
static void
lpp_sbasZg_fmt(gchar *s, guint32 v)
{
double sbasZg = (double)((gint32)v)*0.4;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm (%d)", sbasZg, (gint32)v);
}
static void
lpp_sbasXgDot_YgDot_fmt(gchar *s, guint32 v)
{
double sbasXgDot_YgDot = (double)((gint32)v)*0.000625;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm/s (%d)", sbasXgDot_YgDot, (gint32)v);
}
static void
lpp_sbasZgDot_fmt(gchar *s, guint32 v)
{
double sbasZgDot = (double)((gint32)v)*0.004;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm/s (%d)", sbasZgDot, (gint32)v);
}
static void
lpp_sbasXgDotDot_YgDotDot_fmt(gchar *s, guint32 v)
{
double sbasXgDotDot_YgDotDot = (double)((gint32)v)*0.0000125;
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm/s2 (%d)", sbasXgDotDot_YgDotDot, (gint32)v);
}
static void
lpp_sbasZgDotDot_fmt(gchar *s, guint32 v)
{
double sbasZgDotDot = (double)((gint32)v)*0.0000625;
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm/s2 (%d)", sbasZgDotDot, (gint32)v);
}
static void
lpp_bdsAPowerHalf_r12_fmt(gchar *s, guint32 v)
{
double bdsAPowerHalf = (double)v*pow(2, -19);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm1/2 (%u)", bdsAPowerHalf, v);
}
static void
lpp_bdsE_r12_fmt(gchar *s, guint32 v)
{
double bdsE = (double)v*pow(2, -33);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g (%u)", bdsE, v);
}
static void
lpp_bdsW_M0_Omega0_I0_r12_fmt(gchar *s, guint32 v)
{
double bdsW_M0_Omega0_I0 = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", bdsW_M0_Omega0_I0, (gint32)v);
}
static void
lpp_bdsDeltaN_OmegaDot_IDot_r12_fmt(gchar *s, guint32 v)
{
double bdsDeltaN_OmegaDot_IDot = (double)((gint32)v)*pow(2, -43);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", bdsDeltaN_OmegaDot_IDot, (gint32)v);
}
static void
lpp_bdsCuc_Cus_Cic_Cis_r12_fmt(gchar *s, guint32 v)
{
double bdsCuc_Cus_Cic_Cis = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%grad (%d)", bdsCuc_Cus_Cic_Cis, (gint32)v);
}
static void
lpp_bdsCrc_Crs_r12_fmt(gchar *s, guint32 v)
{
double bdsCrc_Crs = (double)((gint32)v)*pow(2, -6);
g_snprintf(s, ITEM_LABEL_LENGTH, "%grad (%d)", bdsCrc_Crs, (gint32)v);
}
static void
lpp_doppler0_fmt(gchar *s, guint32 v)
{
double doppler0 = (double)((gint32)v)*0.5;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm/s (%d)", doppler0, (gint32)v);
}
static void
lpp_doppler1_fmt(gchar *s, guint32 v)
{
double doppler1 = (double)((gint32)(v-42))/210;
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm/s2 (%u)", doppler1, v);
}
static void
lpp_codePhase_fmt(gchar *s, guint32 v)
{
double codePhase = (double)v*pow(2, -10);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gms (%u)", codePhase, v);
}
static void
lpp_azimuth_elevation_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%f degrees (%u)", (float)v*0.703125, v);
}
static void
lpp_kepAlmanacE_fmt(gchar *s, guint32 v)
{
double kepAlmanacE = (double)v*pow(2, -16);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g (%u)", kepAlmanacE, v);
}
static void
lpp_kepAlmanacDeltaI_fmt(gchar *s, guint32 v)
{
double kepAlmanacDeltaI = (double)((gint32)v)*pow(2, -14);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", kepAlmanacDeltaI, (gint32)v);
}
static void
lpp_kepAlmanacOmegaDot_fmt(gchar *s, guint32 v)
{
double kepAlmanacOmegaDot = (double)((gint32)v)*pow(2, -33);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", kepAlmanacOmegaDot, (gint32)v);
}
static void
lpp_kepAlmanacAPowerHalf_fmt(gchar *s, guint32 v)
{
double kepAlmanacAPowerHalf = (double)((gint32)v)*pow(2, -9);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm1/2 (%d)", kepAlmanacAPowerHalf, (gint32)v);
}
static void
lpp_kepAlmanacOmega0_W_M0_fmt(gchar *s, guint32 v)
{
double kepAlmanacOmega0_W_M0 = (double)((gint32)v)*pow(2, -15);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", kepAlmanacOmega0_W_M0, (gint32)v);
}
static void
lpp_kepAlmanacAF0_fmt(gchar *s, guint32 v)
{
double kepAlmanacAF0 = (double)((gint32)v)*pow(2, -19);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", kepAlmanacAF0, (gint32)v);
}
static void
lpp_kepAlmanacAF1_fmt(gchar *s, guint32 v)
{
double kepAlmanacAF1 = (double)((gint32)v)*pow(2, -38);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", kepAlmanacAF1, (gint32)v);
}
static void
lpp_navAlmE_fmt(gchar *s, guint32 v)
{
double navAlmE = (double)v*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g (%u)", navAlmE, v);
}
static void
lpp_navAlmDeltaI_fmt(gchar *s, guint32 v)
{
double navAlmDeltaI = (double)((gint32)v)*pow(2, -19);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", navAlmDeltaI, (gint32)v);
}
static void
lpp_navAlmOMEGADOT_fmt(gchar *s, guint32 v)
{
double navAlmOMEGADOT = (double)((gint32)v)*pow(2, -38);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", navAlmOMEGADOT, (gint32)v);
}
static void
lpp_navAlmSqrtA_fmt(gchar *s, guint32 v)
{
double navAlmSqrtA = (double)v*pow(2, -11);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm1/2 (%u)", navAlmSqrtA, v);
}
static void
lpp_navAlmOMEGAo_Omega_Mo_fmt(gchar *s, guint32 v)
{
double navAlmOMEGAo_Omega_Mo = (double)((gint32)v)*pow(2, -23);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", navAlmOMEGAo_Omega_Mo, (gint32)v);
}
static void
lpp_navAlmaf0_fmt(gchar *s, guint32 v)
{
double navAlmaf0 = (double)((gint32)v)*pow(2, -20);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", navAlmaf0, (gint32)v);
}
static void
lpp_navAlmaf1_fmt(gchar *s, guint32 v)
{
double navAlmaf1 = (double)((gint32)v)*pow(2, -38);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", navAlmaf1, (gint32)v);
}
static void
lpp_redAlmDeltaA_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%dm (%d)", 512*(gint)v, (gint)v);
}
static void
lpp_redAlmOmega0_Phi0_fmt(gchar *s, guint32 v)
{
double redAlmOmega0_Phi0 = (double)((gint32)v)*pow(2, -6);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", redAlmOmega0_Phi0, (gint32)v);
}
static void
lpp_midiAlmE_fmt(gchar *s, guint32 v)
{
double midiAlmE = (double)v*pow(2, -16);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g (%u)", midiAlmE, v);
}
static void
lpp_midiAlmDeltaI_fmt(gchar *s, guint32 v)
{
double midiAlmDeltaI = (double)((gint32)v)*pow(2, -14);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", midiAlmDeltaI, (gint32)v);
}
static void
lpp_midiAlmOmegaDot_fmt(gchar *s, guint32 v)
{
double midiAlmOmegaDot = (double)((gint32)v)*pow(2, -33);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", midiAlmOmegaDot, (gint32)v);
}
static void
lpp_midiAlmSqrtA_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm1/2 (%u)", (float)v*0.0625, v);
}
static void
lpp_midiAlmOmega0_Omega_Mo_fmt(gchar *s, guint32 v)
{
double midiAlmOmega0_Omega_Mo = (double)((gint32)v)*pow(2, -15);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", midiAlmOmega0_Omega_Mo, (gint32)v);
}
static void
lpp_midiAlmaf0_fmt(gchar *s, guint32 v)
{
double midiAlmaf0 = (double)((gint32)v)*pow(2, -20);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", midiAlmaf0, (gint32)v);
}
static void
lpp_midiAlmaf1_fmt(gchar *s, guint32 v)
{
double midiAlmaf1 = (double)((gint32)v)*pow(2, -37);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", midiAlmaf1, (gint32)v);
}
static void
lpp_gloAlmLambdaA_DeltaIa_fmt(gchar *s, guint32 v)
{
double gloAlmLambdaA_DeltaIa = (double)((gint32)v)*pow(2, -20);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", gloAlmLambdaA_DeltaIa, (gint32)v);
}
static void
lpp_gloAlmtlambdaA_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%fs (%u)", (float)v*0.03125, v);
}
static void
lpp_gloAlmDeltaTA_fmt(gchar *s, guint32 v)
{
double gloAlmDeltaTA = (double)((gint32)v)*pow(2, -9);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/orbit period (%d)", gloAlmDeltaTA, (gint32)v);
}
static void
lpp_gloAlmDeltaTdotA_fmt(gchar *s, guint32 v)
{
double gloAlmDeltaTdotA = (double)((gint32)v)*pow(2, -14);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/orbit period (%d)", gloAlmDeltaTdotA, (gint32)v);
}
static void
lpp_gloAlmEpsilonA_fmt(gchar *s, guint32 v)
{
double gloAlmEpsilonA = (double)v*pow(2, -20);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g (%u)", gloAlmEpsilonA, (gint32)v);
}
static void
lpp_gloAlmOmegaA_fmt(gchar *s, guint32 v)
{
double gloAlmOmegaA = (double)((gint32)v)*pow(2, -15);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", gloAlmOmegaA, (gint32)v);
}
static void
lpp_gloAlmTauA_fmt(gchar *s, guint32 v)
{
double gloAlmTauA = (double)((gint32)v)*pow(2, -18);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", gloAlmTauA, (gint32)v);
}
static void
lpp_sbasAlmXg_Yg_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%fkm (%d)", (gint32)v*2.6, (gint32)v);
}
static void
lpp_sbasAlmZg_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%dkm (%d)", (gint32)v*26, (gint32)v);
}
static void
lpp_sbasAlmXgdot_YgDot_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%dm/s (%d)", (gint32)v*10, (gint32)v);
}
static void
lpp_sbasAlmZgDot_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%fm/s (%d)", (gint32)v*40.96, (gint32)v);
}
static void
lpp_sbasAlmTo_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%um/s (%u)", v*64, v);
}
static void
lpp_bdsAlmToa_r12_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", v*4096, v);
}
static void
lpp_bdsAlmSqrtA_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmSqrtA = (double)v*pow(2, -11);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm1/2 (%u)", bdsAlmSqrtA, v);
}
static void
lpp_bdsAlmE_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmE = (double)v*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm1/2 (%u)", bdsAlmE, v);
}
static void
lpp_bdsAlmW_M0_Omega0_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmW_M0_Omega0 = (double)((gint32)v)*pow(2, -23);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", bdsAlmW_M0_Omega0, (gint32)v);
}
static void
lpp_bdsAlmOmegaDot_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmOmegaDot = (double)((gint32)v)*pow(2, -38);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles/s (%d)", bdsAlmOmegaDot, (gint32)v);
}
static void
lpp_bdsAlmDeltaI_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmDeltaI = (double)((gint32)v)*pow(2, -19);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g semi-circles (%d)", bdsAlmDeltaI, (gint32)v);
}
static void
lpp_bdsAlmA0_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmA0 = (double)((gint32)v)*pow(2, -20);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", bdsAlmA0, (gint32)v);
}
static void
lpp_bdsAlmA1_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmA1 = (double)((gint32)v)*pow(2, -38);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", bdsAlmA1, (gint32)v);
}
static void
lpp_gnss_Utc_A1_fmt(gchar *s, guint32 v)
{
double gnss_Utc_A1 = (double)((gint32)v)*pow(2, -50);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/s (%d)", gnss_Utc_A1, (gint32)v);
}
static void
lpp_gnss_Utc_A0_fmt(gchar *s, guint32 v)
{
double gnss_Utc_A0 = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", gnss_Utc_A0, (gint32)v);
}
static void
lpp_gnss_Utc_Tot_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%us (%u)", v*4096, v);
}
static void
lpp_bds_ECC_DeltaT_r12_fmt(gchar *s, guint32 v)
{
if ((gint32)v == -4096) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Not available (%d)", (gint32)v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm (%d)", (float)((gint32)v)*0.1, (gint32)v);
}
}
static void
lpp_bds_GridIonElement_dt_r12_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm (%d)", (float)((gint32)v)*0.125, (gint32)v);
}
static void
lpp_tauC_fmt(gchar *s, guint32 v)
{
double tauC = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", tauC, (gint32)v);
}
static void
lpp_b1_fmt(gchar *s, guint32 v)
{
double b1 = (double)((gint32)v)*pow(2, -10);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs (%d)", b1, (gint32)v);
}
static void
lpp_b2_fmt(gchar *s, guint32 v)
{
double b2 = (double)((gint32)v)*pow(2, -16);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gs/msd (%d)", b2, (gint32)v);
}
static void
lpp_GNSS_SatMeas_codePhase_fmt(gchar *s, guint32 v)
{
double codePhase = (double)v*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gms (%u)", codePhase, v);
}
static void
lpp_codePhaseRMSError_fmt(gchar *s, guint32 v)
{
guint8 mantissa = v & 0x07;
guint8 exponent = (v & 0x38) >> 3;
guint8 mantissa_1 = (v - 1) & 0x07;
guint8 exponent_1 = ((v - 1) & 0x38) >> 3;
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "P < 0.5 (0)");
} else if (v < 63) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%f <= P < %f (%u)", 0.5*(1+mantissa_1/8)*pow(2, exponent_1),
0.5*(1+mantissa/8)*pow(2, exponent), v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "112 <= P (63)");
}
}
static void
lpp_doppler_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm/s (%d)", (gint32)v*0.04, (gint32)v);
}
static void
lpp_adr_fmt(gchar *s, guint32 v)
{
double adr = (double)v*pow(2, -10);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gm (%u)", adr, v);
}
static void
lpp_rsrp_Result_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%ddBm (%u)", v-140, v);
}
static void
lpp_rsrq_Result_fmt(gchar *s, guint32 v)
{
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "RSRQ < -19.5 dB (0)");
} else if (v < 34) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1fdB <= RSRQ < %.1fdB (%u)", ((float)v/2)-20, (((float)v+1)/2)-20, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "-3dB <= RSRQ (34)");
}
}
static void
lpp_ue_RxTxTimeDiff_fmt(gchar *s, guint32 v)
{
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "T < 2Ts (0)");
} else if (v < 2048) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs <= T < %uTs (%u)", v*2, (v+1)*2, v);
} else if (v < 4095) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%uTs <= T < %uTs (%u)", (v*8)-12288, ((v+1)*8)-12288, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "20472Ts <= T (4095)");
}
}
static void
lpp_mbs_beaconMeasElt_codePhase_fmt(gchar *s, guint32 v)
{
double codePhase = (double)v*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%gms (%u)", codePhase, v);
}
static int
dissect_lpp_Initiator(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_TransactionNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_LPP_TransactionID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_LPP_TransactionID, LPP_TransactionID_sequence);
return offset;
}
static int
dissect_lpp_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_lpp_SequenceNumber(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_Acknowledgement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Acknowledgement, Acknowledgement_sequence);
return offset;
}
static int
dissect_lpp_CommonIEsRequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CommonIEsRequestCapabilities, CommonIEsRequestCapabilities_sequence);
return offset;
}
static int
dissect_lpp_A_GNSS_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_A_GNSS_RequestCapabilities, A_GNSS_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lpp_OTDOA_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_RequestCapabilities, OTDOA_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lpp_ECID_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ECID_RequestCapabilities, ECID_RequestCapabilities_sequence);
return offset;
}
static int
dissect_lpp_EPDU_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 84 "./asn1/lpp/lpp.cnf"
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 256U, &lpp_epdu_id, FALSE);
return offset;
}
static int
dissect_lpp_EPDU_Name(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_VisibleString(tvb, offset, actx, tree, hf_index,
1, 32, FALSE);
return offset;
}
static int
dissect_lpp_EPDU_Identifier(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_EPDU_Identifier, EPDU_Identifier_sequence);
return offset;
}
static int
dissect_lpp_EPDU_Body(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 90 "./asn1/lpp/lpp.cnf"
tvbuff_t *lppe_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE, &lppe_tvb);
switch(lpp_epdu_id){
case 1:
if (lppe_tvb && lppe_handle) {
call_dissector(lppe_handle, lppe_tvb, actx->pinfo, tree);
}
break;
default:
break;
}
lpp_epdu_id = -1;
return offset;
}
static int
dissect_lpp_EPDU(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_EPDU, EPDU_sequence);
return offset;
}
static int
dissect_lpp_EPDU_Sequence(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_EPDU_Sequence, EPDU_Sequence_sequence_of,
1, maxEPDU, FALSE);
return offset;
}
static int
dissect_lpp_Sensor_RequestCapabilities_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Sensor_RequestCapabilities_r13, Sensor_RequestCapabilities_r13_sequence);
return offset;
}
static int
dissect_lpp_TBS_RequestCapabilities_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_TBS_RequestCapabilities_r13, TBS_RequestCapabilities_r13_sequence);
return offset;
}
static int
dissect_lpp_WLAN_RequestCapabilities_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_RequestCapabilities_r13, WLAN_RequestCapabilities_r13_sequence);
return offset;
}
static int
dissect_lpp_BT_RequestCapabilities_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_RequestCapabilities_r13, BT_RequestCapabilities_r13_sequence);
return offset;
}
static int
dissect_lpp_RequestCapabilities_r9_IEs_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, RequestCapabilities_r9_IEs_eag_1_sequence);
return offset;
}
static int
dissect_lpp_RequestCapabilities_r9_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_RequestCapabilities_r9_IEs, RequestCapabilities_r9_IEs_sequence);
return offset;
}
static int
dissect_lpp_NULL(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_null(tvb, offset, actx, tree, hf_index);
return offset;
}
static int
dissect_lpp_T_c1_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_c1_01, T_c1_01_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_criticalExtensionsFuture(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensionsFuture, T_criticalExtensionsFuture_sequence);
return offset;
}
static int
dissect_lpp_T_criticalExtensions(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensions, T_criticalExtensions_choice,
NULL);
return offset;
}
static int
dissect_lpp_RequestCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 60 "./asn1/lpp/lpp.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Request Capabilities");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_RequestCapabilities, RequestCapabilities_sequence);
return offset;
}
static int
dissect_lpp_CommonIEsProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CommonIEsProvideCapabilities, CommonIEsProvideCapabilities_sequence);
return offset;
}
static int
dissect_lpp_T_gnss_id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1572 "./asn1/lpp/lpp.cnf"
guint32 gnss_id;
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, &gnss_id, TRUE, 1, NULL);
actx->private_data = GUINT_TO_POINTER(gnss_id);
return offset;
}
int
dissect_lpp_GNSS_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ID, GNSS_ID_sequence);
return offset;
}
static int
dissect_lpp_T_sbas_IDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1606 "./asn1/lpp/lpp.cnf"
tvbuff_t *sbas_IDs_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &sbas_IDs_tvb, &len);
if(sbas_IDs_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_sbas_IDs_waas, sbas_IDs_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_sbas_IDs_egnos, sbas_IDs_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_sbas_IDs_msas, sbas_IDs_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 4) {
proto_tree_add_item(subtree, hf_lpp_T_sbas_IDs_gagan, sbas_IDs_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_SBAS_IDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_SBAS_IDs, SBAS_IDs_sequence);
return offset;
}
static int
dissect_lpp_T_posModes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 247 "./asn1/lpp/lpp.cnf"
tvbuff_t *posModes_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &posModes_tvb, &len);
if(posModes_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_posModes_standalone, posModes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_posModes_ue_based, posModes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_posModes_ue_assisted, posModes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_PositioningModes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_PositioningModes, PositioningModes_sequence);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
8, 8, FALSE, NULL, NULL);
return offset;
}
int
dissect_lpp_GNSS_SignalIDs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SignalIDs, GNSS_SignalIDs_sequence);
return offset;
}
static int
dissect_lpp_T_accessTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 104 "./asn1/lpp/lpp.cnf"
tvbuff_t *accessTypes_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &accessTypes_tvb, &len);
if(accessTypes_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_accessTypes_eutra, accessTypes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_accessTypes_utra, accessTypes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_accessTypes_gsm, accessTypes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_AccessTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AccessTypes, AccessTypes_sequence);
return offset;
}
static int
dissect_lpp_T_fta_MeasSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_fta_MeasSupport, T_fta_MeasSupport_sequence);
return offset;
}
static int
dissect_lpp_GNSS_SupportElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SupportElement, GNSS_SupportElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_SupportList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SupportList, GNSS_SupportList_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lpp_T_gnss_ids(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1577 "./asn1/lpp/lpp.cnf"
tvbuff_t *gnss_ids_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, &gnss_ids_tvb, &len);
if(gnss_ids_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_gnss_ids_gps, gnss_ids_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_gnss_ids_sbas, gnss_ids_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_gnss_ids_qzss, gnss_ids_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 4) {
proto_tree_add_item(subtree, hf_lpp_T_gnss_ids_galileo, gnss_ids_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 5) {
proto_tree_add_item(subtree, hf_lpp_T_gnss_ids_glonass, gnss_ids_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 6) {
proto_tree_add_item(subtree, hf_lpp_T_gnss_ids_bds, gnss_ids_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
int
dissect_lpp_GNSS_ID_Bitmap(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ID_Bitmap, GNSS_ID_Bitmap_sequence);
return offset;
}
static int
dissect_lpp_GNSS_ReferenceTimeSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ReferenceTimeSupport, GNSS_ReferenceTimeSupport_sequence);
return offset;
}
static int
dissect_lpp_GNSS_ReferenceLocationSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ReferenceLocationSupport, GNSS_ReferenceLocationSupport_sequence);
return offset;
}
static int
dissect_lpp_T_ionoModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1439 "./asn1/lpp/lpp.cnf"
tvbuff_t *ionoModel_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &ionoModel_tvb, &len);
if(ionoModel_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_ionoModel_klobuchar, ionoModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_ionoModel_neQuick, ionoModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_GNSS_IonosphericModelSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_IonosphericModelSupport, GNSS_IonosphericModelSupport_sequence);
return offset;
}
static int
dissect_lpp_GNSS_EarthOrientationParametersSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_EarthOrientationParametersSupport, GNSS_EarthOrientationParametersSupport_sequence);
return offset;
}
static int
dissect_lpp_GNSS_CommonAssistanceDataSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_CommonAssistanceDataSupport, GNSS_CommonAssistanceDataSupport_sequence);
return offset;
}
static int
dissect_lpp_T_sbas_id(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_SBAS_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_SBAS_ID, SBAS_ID_sequence);
return offset;
}
static int
dissect_lpp_GNSS_TimeModelListSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_TimeModelListSupport, GNSS_TimeModelListSupport_sequence);
return offset;
}
static int
dissect_lpp_GNSS_DifferentialCorrectionsSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DifferentialCorrectionsSupport, GNSS_DifferentialCorrectionsSupport_sequence);
return offset;
}
static int
dissect_lpp_T_clockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1456 "./asn1/lpp/lpp.cnf"
tvbuff_t *clockModel_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &clockModel_tvb, &len);
if(clockModel_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_clockModel_model_1, clockModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_clockModel_model_2, clockModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_clockModel_model_3, clockModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 4) {
proto_tree_add_item(subtree, hf_lpp_T_clockModel_model_4, clockModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 5) {
proto_tree_add_item(subtree, hf_lpp_T_clockModel_model_5, clockModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 6) {
proto_tree_add_item(subtree, hf_lpp_T_clockModel_model_6, clockModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_T_orbitModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1485 "./asn1/lpp/lpp.cnf"
tvbuff_t *orbitModel_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &orbitModel_tvb, &len);
if(orbitModel_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_orbitModel_model_1, orbitModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_orbitModel_model_2, orbitModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_orbitModel_model_3, orbitModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 4) {
proto_tree_add_item(subtree, hf_lpp_T_orbitModel_model_4, orbitModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 5) {
proto_tree_add_item(subtree, hf_lpp_T_orbitModel_model_5, orbitModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 6) {
proto_tree_add_item(subtree, hf_lpp_T_orbitModel_model_6, orbitModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_GNSS_NavigationModelSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_NavigationModelSupport, GNSS_NavigationModelSupport_sequence);
return offset;
}
static int
dissect_lpp_GNSS_RealTimeIntegritySupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_RealTimeIntegritySupport, GNSS_RealTimeIntegritySupport_sequence);
return offset;
}
static int
dissect_lpp_GNSS_DataBitAssistanceSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitAssistanceSupport, GNSS_DataBitAssistanceSupport_sequence);
return offset;
}
static int
dissect_lpp_T_confidenceSupport_r10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_T_dopplerUncertaintyExtSupport_r10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_GNSS_AcquisitionAssistanceSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AcquisitionAssistanceSupport, GNSS_AcquisitionAssistanceSupport_sequence);
return offset;
}
static int
dissect_lpp_T_almanacModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1514 "./asn1/lpp/lpp.cnf"
tvbuff_t *almanacModel_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &almanacModel_tvb, &len);
if(almanacModel_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_almanacModel_model_1, almanacModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_almanacModel_model_2, almanacModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_almanacModel_model_3, almanacModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 4) {
proto_tree_add_item(subtree, hf_lpp_T_almanacModel_model_4, almanacModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 5) {
proto_tree_add_item(subtree, hf_lpp_T_almanacModel_model_5, almanacModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 6) {
proto_tree_add_item(subtree, hf_lpp_T_almanacModel_model_6, almanacModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 7) {
proto_tree_add_item(subtree, hf_lpp_T_almanacModel_model_7, almanacModel_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_GNSS_AlmanacSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AlmanacSupport, GNSS_AlmanacSupport_sequence);
return offset;
}
static int
dissect_lpp_T_utc_Model(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1546 "./asn1/lpp/lpp.cnf"
tvbuff_t *utc_Model_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &utc_Model_tvb, &len);
if(utc_Model_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_utc_Model_model_1, utc_Model_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_utc_Model_model_2, utc_Model_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_utc_Model_model_3, utc_Model_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 4) {
proto_tree_add_item(subtree, hf_lpp_T_utc_Model_model_4, utc_Model_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 5) {
proto_tree_add_item(subtree, hf_lpp_T_utc_Model_model_5, utc_Model_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_GNSS_UTC_ModelSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_UTC_ModelSupport, GNSS_UTC_ModelSupport_sequence);
return offset;
}
static int
dissect_lpp_GNSS_AuxiliaryInformationSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AuxiliaryInformationSupport, GNSS_AuxiliaryInformationSupport_sequence);
return offset;
}
static int
dissect_lpp_BDS_DifferentialCorrectionsSupport_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_DifferentialCorrectionsSupport_r12, BDS_DifferentialCorrectionsSupport_r12_sequence);
return offset;
}
static int
dissect_lpp_BDS_GridModelSupport_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_GridModelSupport_r12, BDS_GridModelSupport_r12_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistDataSupportElement_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, GNSS_GenericAssistDataSupportElement_eag_1_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistDataSupportElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_GenericAssistDataSupportElement, GNSS_GenericAssistDataSupportElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistanceDataSupport(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_GenericAssistanceDataSupport, GNSS_GenericAssistanceDataSupport_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lpp_AssistanceDataSupportList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AssistanceDataSupportList, AssistanceDataSupportList_sequence);
return offset;
}
static int
dissect_lpp_LocationCoordinateTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_LocationCoordinateTypes, LocationCoordinateTypes_sequence);
return offset;
}
static int
dissect_lpp_VelocityTypes(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_VelocityTypes, VelocityTypes_sequence);
return offset;
}
static int
dissect_lpp_A_GNSS_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_A_GNSS_ProvideCapabilities, A_GNSS_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lpp_T_otdoa_Mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 382 "./asn1/lpp/lpp.cnf"
tvbuff_t *otdoa_Mode_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &otdoa_Mode_tvb, &len);
if(otdoa_Mode_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_otdoa_Mode_ue_assisted, otdoa_Mode_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_INTEGER_1_maxFBI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, maxFBI, NULL, FALSE);
return offset;
}
static int
dissect_lpp_SupportedBandEUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_SupportedBandEUTRA, SupportedBandEUTRA_sequence);
return offset;
}
static int
dissect_lpp_SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA, SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA_sequence_of,
1, maxBands, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_maxFBI_Plus1_maxFBI2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
maxFBI_Plus1, maxFBI2, NULL, FALSE);
return offset;
}
static int
dissect_lpp_SupportedBandEUTRA_v9a0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_SupportedBandEUTRA_v9a0, SupportedBandEUTRA_v9a0_sequence);
return offset;
}
static int
dissect_lpp_SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA_v9a0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA_v9a0, SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA_v9a0_sequence_of,
1, maxBands, FALSE);
return offset;
}
static int
dissect_lpp_T_interFreqRSTDmeasurement_r10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_T_additionalNeighbourCellInfoList_r10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_OTDOA_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_ProvideCapabilities, OTDOA_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lpp_T_ecid_MeasSupported(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1658 "./asn1/lpp/lpp.cnf"
tvbuff_t *ecid_MeasSupported_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &ecid_MeasSupported_tvb, &len);
if(ecid_MeasSupported_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_ecid_MeasSupported_rsrpSup, ecid_MeasSupported_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_ecid_MeasSupported_rsrqSup, ecid_MeasSupported_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_ecid_MeasSupported_ueRxTxSup, ecid_MeasSupported_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_T_ueRxTxSupTDD_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_ECID_ProvideCapabilities_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, ECID_ProvideCapabilities_eag_1_sequence);
return offset;
}
static int
dissect_lpp_ECID_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ECID_ProvideCapabilities, ECID_ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lpp_T_sensor_Modes_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1704 "./asn1/lpp/lpp.cnf"
tvbuff_t *sensor_Modes_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &sensor_Modes_tvb, &len);
if(sensor_Modes_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_sensor_Modes_r13_standalone, sensor_Modes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_sensor_Modes_r13_ue_assisted, sensor_Modes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_Sensor_ProvideCapabilities_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Sensor_ProvideCapabilities_r13, Sensor_ProvideCapabilities_r13_sequence);
return offset;
}
static int
dissect_lpp_T_tbs_Modes_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1684 "./asn1/lpp/lpp.cnf"
tvbuff_t *tbs_Modes_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &tbs_Modes_tvb, &len);
if(tbs_Modes_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_tbs_Modes_r13_standalone, tbs_Modes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_tbs_Modes_r13_ue_assisted, tbs_Modes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_TBS_ProvideCapabilities_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_TBS_ProvideCapabilities_r13, TBS_ProvideCapabilities_r13_sequence);
return offset;
}
static int
dissect_lpp_T_wlan_Modes_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1753 "./asn1/lpp/lpp.cnf"
tvbuff_t *wlan_Modes_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &wlan_Modes_tvb, &len);
if(wlan_Modes_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_wlan_Modes_r13_standalone, wlan_Modes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_wlan_Modes_r13_ue_assisted, wlan_Modes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_T_wlan_MeasSupported_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1770 "./asn1/lpp/lpp.cnf"
tvbuff_t *wlan_MeasSupported_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &wlan_MeasSupported_tvb, &len);
if(wlan_MeasSupported_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_wlan_MeasSupported_r13_rssi_r13, wlan_MeasSupported_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_wlan_MeasSupported_r13_rtt_r13, wlan_MeasSupported_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_WLAN_ProvideCapabilities_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_ProvideCapabilities_r13, WLAN_ProvideCapabilities_r13_sequence);
return offset;
}
static int
dissect_lpp_T_bt_Modes_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1813 "./asn1/lpp/lpp.cnf"
tvbuff_t *bt_Modes_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &bt_Modes_tvb, &len);
if(bt_Modes_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_bt_Modes_r13_standalone, bt_Modes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_bt_Modes_r13_ue_assisted, bt_Modes_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_T_bt_MeasSupported_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1830 "./asn1/lpp/lpp.cnf"
tvbuff_t *bt_MeasSupported_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &bt_MeasSupported_tvb, &len);
if(bt_MeasSupported_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_bt_MeasSupported_r13_rssi_r13, bt_MeasSupported_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_BT_ProvideCapabilities_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_ProvideCapabilities_r13, BT_ProvideCapabilities_r13_sequence);
return offset;
}
static int
dissect_lpp_ProvideCapabilities_r9_IEs_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, ProvideCapabilities_r9_IEs_eag_1_sequence);
return offset;
}
static int
dissect_lpp_ProvideCapabilities_r9_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ProvideCapabilities_r9_IEs, ProvideCapabilities_r9_IEs_sequence);
return offset;
}
static int
dissect_lpp_T_c1_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_c1_02, T_c1_02_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_criticalExtensionsFuture_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensionsFuture_01, T_criticalExtensionsFuture_01_sequence);
return offset;
}
static int
dissect_lpp_T_criticalExtensions_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensions_01, T_criticalExtensions_01_choice,
NULL);
return offset;
}
static int
dissect_lpp_ProvideCapabilities(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 63 "./asn1/lpp/lpp.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Provide Capabilities");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ProvideCapabilities, ProvideCapabilities_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_9(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 9U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_mcc_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_T_mcc_02, T_mcc_02_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_lpp_T_mnc_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_T_mnc_02, T_mnc_02_sequence_of,
2, 3, FALSE);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lpp_ECGI(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ECGI, ECGI_sequence);
return offset;
}
static int
dissect_lpp_CommonIEsRequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CommonIEsRequestAssistanceData, CommonIEsRequestAssistanceData_sequence);
return offset;
}
static int
dissect_lpp_SEQUENCE_SIZE_1_8_OF_GNSS_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_SEQUENCE_SIZE_1_8_OF_GNSS_ID, SEQUENCE_SIZE_1_8_OF_GNSS_ID_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_ReferenceTimeReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ReferenceTimeReq, GNSS_ReferenceTimeReq_sequence);
return offset;
}
static int
dissect_lpp_GNSS_ReferenceLocationReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ReferenceLocationReq, GNSS_ReferenceLocationReq_sequence);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lpp_GNSS_IonosphericModelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_IonosphericModelReq, GNSS_IonosphericModelReq_sequence);
return offset;
}
static int
dissect_lpp_GNSS_EarthOrientationParametersReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_EarthOrientationParametersReq, GNSS_EarthOrientationParametersReq_sequence);
return offset;
}
static int
dissect_lpp_GNSS_CommonAssistDataReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_CommonAssistDataReq, GNSS_CommonAssistDataReq_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_1_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_TimeModelElementReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_TimeModelElementReq, GNSS_TimeModelElementReq_sequence);
return offset;
}
static int
dissect_lpp_GNSS_TimeModelListReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_TimeModelListReq, GNSS_TimeModelListReq_sequence_of,
1, 15, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_DifferentialCorrectionsReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DifferentialCorrectionsReq, GNSS_DifferentialCorrectionsReq_sequence);
return offset;
}
static int
dissect_lpp_T_gnss_WeekOrDay(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
#line 1385 "./asn1/lpp/lpp.cnf"
proto_item_append_text(actx->created_item, " (days for glonass, weeks otherwise)");
return offset;
}
static int
dissect_lpp_T_gnss_Toe(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
#line 1388 "./asn1/lpp/lpp.cnf"
proto_item_append_text(actx->created_item, " (units of 15 mns for glonass, hours otherwise)");
return offset;
}
static int
dissect_lpp_T_t_toeLimit(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
#line 1391 "./asn1/lpp/lpp.cnf"
proto_item_append_text(actx->created_item, " (units of 30 mns for glonass, hours otherwise)");
return offset;
}
static int
dissect_lpp_INTEGER_0_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 63U, NULL, FALSE);
return offset;
}
int
dissect_lpp_SV_ID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_SV_ID, SV_ID_sequence);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_11(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
11, 11, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lpp_INTEGER_1_8(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 8U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_SatListRelatedDataElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_SatListRelatedDataElement, SatListRelatedDataElement_sequence);
return offset;
}
static int
dissect_lpp_SatListRelatedDataList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_SatListRelatedDataList, SatListRelatedDataList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_StoredNavListInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_StoredNavListInfo, StoredNavListInfo_sequence);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
64, 64, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lpp_T_clockModelID_PrefList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_T_clockModelID_PrefList, T_clockModelID_PrefList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lpp_T_orbitModelID_PrefList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_T_orbitModelID_PrefList, T_orbitModelID_PrefList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lpp_ReqNavListInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ReqNavListInfo, ReqNavListInfo_sequence);
return offset;
}
static int
dissect_lpp_GNSS_NavigationModelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_NavigationModelReq, GNSS_NavigationModelReq_choice,
NULL);
return offset;
}
static int
dissect_lpp_GNSS_RealTimeIntegrityReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_RealTimeIntegrityReq, GNSS_RealTimeIntegrityReq_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_3599(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3599U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 999U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_DataBitsReqSatElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitsReqSatElement, GNSS_DataBitsReqSatElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_DataBitsReqSatList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitsReqSatList, GNSS_DataBitsReqSatList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_DataBitAssistanceReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitAssistanceReq, GNSS_DataBitAssistanceReq_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 7U, NULL, FALSE);
return offset;
}
int
dissect_lpp_GNSS_SignalID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SignalID, GNSS_SignalID_sequence);
return offset;
}
static int
dissect_lpp_GNSS_AcquisitionAssistanceReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AcquisitionAssistanceReq, GNSS_AcquisitionAssistanceReq_sequence);
return offset;
}
static int
dissect_lpp_GNSS_AlmanacReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AlmanacReq, GNSS_AlmanacReq_sequence);
return offset;
}
static int
dissect_lpp_GNSS_UTC_ModelReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_UTC_ModelReq, GNSS_UTC_ModelReq_sequence);
return offset;
}
static int
dissect_lpp_GNSS_AuxiliaryInformationReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AuxiliaryInformationReq, GNSS_AuxiliaryInformationReq_sequence);
return offset;
}
static int
dissect_lpp_BDS_DifferentialCorrectionsReq_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_DifferentialCorrectionsReq_r12, BDS_DifferentialCorrectionsReq_r12_sequence);
return offset;
}
static int
dissect_lpp_BDS_GridModelReq_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_GridModelReq_r12, BDS_GridModelReq_r12_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistDataReqElement_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, GNSS_GenericAssistDataReqElement_eag_1_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistDataReqElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_GenericAssistDataReqElement, GNSS_GenericAssistDataReqElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistDataReq(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_GenericAssistDataReq, GNSS_GenericAssistDataReq_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lpp_A_GNSS_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_A_GNSS_RequestAssistanceData, A_GNSS_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_503(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 503U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_OTDOA_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_RequestAssistanceData, OTDOA_RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lpp_RequestAssistanceData_r9_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_RequestAssistanceData_r9_IEs, RequestAssistanceData_r9_IEs_sequence);
return offset;
}
static int
dissect_lpp_T_c1_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_c1_03, T_c1_03_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_criticalExtensionsFuture_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensionsFuture_02, T_criticalExtensionsFuture_02_sequence);
return offset;
}
static int
dissect_lpp_T_criticalExtensions_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensions_02, T_criticalExtensions_02_choice,
NULL);
return offset;
}
static int
dissect_lpp_RequestAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 66 "./asn1/lpp/lpp.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Request Assistance Data");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_RequestAssistanceData, RequestAssistanceData_sequence);
return offset;
}
static int
dissect_lpp_CommonIEsProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CommonIEsProvideAssistanceData, CommonIEsProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_86399(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 86399U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_notificationOfLeapSecond(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 402 "./asn1/lpp/lpp.cnf"
tvbuff_t *notificationOfLeapSecond_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &notificationOfLeapSecond_tvb, NULL);
#line 406 "./asn1/lpp/lpp.cnf"
if (notificationOfLeapSecond_tvb) {
guint bitvalue = tvb_get_bits8(notificationOfLeapSecond_tvb, 0, 2);
actx->created_item = proto_tree_add_uint(tree, hf_index, notificationOfLeapSecond_tvb, 0, 1, bitvalue);
}
return offset;
}
static int
dissect_lpp_INTEGER_1_64(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 64U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_16383(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GPS_TOW_AssistElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GPS_TOW_AssistElement, GPS_TOW_AssistElement_sequence);
return offset;
}
static int
dissect_lpp_GPS_TOW_Assist(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GPS_TOW_Assist, GPS_TOW_Assist_sequence_of,
1, 64, FALSE);
return offset;
}
int
dissect_lpp_GNSS_SystemTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SystemTime, GNSS_SystemTime_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_12533(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 12533U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_3999999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3999999U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M64_63(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-64, 63U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_mcc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_T_mcc, T_mcc_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_lpp_T_mnc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_T_mnc, T_mnc_sequence_of,
2, 3, FALSE);
return offset;
}
static int
dissect_lpp_T_plmn_Identity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_plmn_Identity, T_plmn_Identity_sequence);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_32(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
32, 32, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lpp_T_cellIdentity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_cellIdentity, T_cellIdentity_choice,
NULL);
return offset;
}
int
dissect_lpp_CellGlobalIdEUTRA_AndUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CellGlobalIdEUTRA_AndUTRA, CellGlobalIdEUTRA_AndUTRA_sequence);
return offset;
}
int
dissect_lpp_ARFCN_ValueEUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, maxEARFCN, NULL, FALSE);
return offset;
}
static int
dissect_lpp_ARFCN_ValueEUTRA_v9a0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
maxEARFCN_Plus1, maxEARFCN2, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, T_eag_1_sequence);
return offset;
}
static int
dissect_lpp_T_eUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_eUTRA, T_eUTRA_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_511(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 511U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_fdd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_fdd, T_fdd_sequence);
return offset;
}
static int
dissect_lpp_T_tdd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_tdd, T_tdd_sequence);
return offset;
}
static int
dissect_lpp_T_mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_mode, T_mode_choice,
NULL);
return offset;
}
int
dissect_lpp_ARFCN_ValueUTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_uTRA(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_uTRA, T_uTRA_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_mcc_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_T_mcc_01, T_mcc_01_sequence_of,
3, 3, FALSE);
return offset;
}
static int
dissect_lpp_T_mnc_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_T_mnc_01, T_mnc_01_sequence_of,
2, 3, FALSE);
return offset;
}
static int
dissect_lpp_T_plmn_Identity_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_plmn_Identity_01, T_plmn_Identity_01_sequence);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_16(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
16, 16, FALSE, NULL, NULL);
return offset;
}
int
dissect_lpp_CellGlobalIdGERAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CellGlobalIdGERAN, CellGlobalIdGERAN_sequence);
return offset;
}
static int
dissect_lpp_T_gSM(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_gSM, T_gSM_sequence);
return offset;
}
static int
dissect_lpp_T_cellID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_cellID, T_cellID_choice,
NULL);
return offset;
}
int
dissect_lpp_NetworkTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NetworkTime, NetworkTime_sequence);
return offset;
}
static int
dissect_lpp_T_bsAlign(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_GNSS_ReferenceTimeForOneCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ReferenceTimeForOneCell, GNSS_ReferenceTimeForOneCell_sequence);
return offset;
}
static int
dissect_lpp_SEQUENCE_SIZE_1_16_OF_GNSS_ReferenceTimeForOneCell(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_SEQUENCE_SIZE_1_16_OF_GNSS_ReferenceTimeForOneCell, SEQUENCE_SIZE_1_16_OF_GNSS_ReferenceTimeForOneCell_sequence_of,
1, 16, FALSE);
return offset;
}
int
dissect_lpp_GNSS_ReferenceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ReferenceTime, GNSS_ReferenceTime_sequence);
return offset;
}
static int
dissect_lpp_T_latitudeSign_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_INTEGER_0_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M8388608_8388607(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8388608, 8388607U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_altitudeDirection_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_INTEGER_0_179(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 179U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_100(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 100U, NULL, FALSE);
return offset;
}
int
dissect_lpp_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid, EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_sequence);
return offset;
}
static int
dissect_lpp_GNSS_ReferenceLocation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ReferenceLocation, GNSS_ReferenceLocation_sequence);
return offset;
}
static int
dissect_lpp_T_dataID(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 421 "./asn1/lpp/lpp.cnf"
tvbuff_t *dataID_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &dataID_tvb, NULL);
#line 425 "./asn1/lpp/lpp.cnf"
if (dataID_tvb) {
guint bitvalue = tvb_get_bits8(dataID_tvb, 0, 2);
actx->created_item = proto_tree_add_uint(tree, hf_index, dataID_tvb, 0, 1, bitvalue);
}
return offset;
}
static int
dissect_lpp_INTEGER_M128_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-128, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_KlobucharModelParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_KlobucharModelParameter, KlobucharModelParameter_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M1024_1023(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1024, 1023U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M8192_8191(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8192, 8191U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_NeQuickModelParameter(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NeQuickModelParameter, NeQuickModelParameter_sequence);
return offset;
}
static int
dissect_lpp_GNSS_IonosphericModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_IonosphericModel, GNSS_IonosphericModel_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M1048576_1048575(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1048576, 1048575U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M16384_16383(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-16384, 16383U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M1073741824_1073741823(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-1073741824, 1073741823U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M262144_262143(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-262144, 262143U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_EarthOrientationParameters(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_EarthOrientationParameters, GNSS_EarthOrientationParameters_sequence);
return offset;
}
static int
dissect_lpp_GNSS_CommonAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_CommonAssistData, GNSS_CommonAssistData_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_M67108864_67108863(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-67108864, 67108863U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M4096_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4096, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_8191(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 8191U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_TimeModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_TimeModelElement, GNSS_TimeModelElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_TimeModelList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_TimeModelList, GNSS_TimeModelList_sequence_of,
1, 15, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M2047_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-2047, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M127_127(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 127U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_DGNSS_CorrectionsElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_DGNSS_CorrectionsElement, DGNSS_CorrectionsElement_sequence);
return offset;
}
static int
dissect_lpp_DGNSS_SatList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_DGNSS_SatList, DGNSS_SatList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_DGNSS_SgnTypeElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_DGNSS_SgnTypeElement, DGNSS_SgnTypeElement_sequence);
return offset;
}
static int
dissect_lpp_DGNSS_SgnTypeList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_DGNSS_SgnTypeList, DGNSS_SgnTypeList_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_DifferentialCorrections(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DifferentialCorrections, GNSS_DifferentialCorrections_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_M32_31(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-32, 31U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M512_511(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-512, 511U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_StandardClockModelElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_StandardClockModelElement, StandardClockModelElement_sequence);
return offset;
}
static int
dissect_lpp_StandardClockModelList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_StandardClockModelList, StandardClockModelList_sequence_of,
1, 2, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_37799(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 37799U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M32768_32767(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-32768, 32767U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M2097152_2097151(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-2097152, 2097151U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_NAV_ClockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NAV_ClockModel, NAV_ClockModel_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_2015(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2015U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M16_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-16, 15U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M524288_524287(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-524288, 524287U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M33554432_33554431(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-33554432, 33554431U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_CNAV_ClockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CNAV_ClockModel, CNAV_ClockModel_sequence);
return offset;
}
static int
dissect_lpp_GLONASS_ClockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GLONASS_ClockModel, GLONASS_ClockModel_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_5399(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 5399U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M2048_2047(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-2048, 2047U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_SBAS_ClockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_SBAS_ClockModel, SBAS_ClockModel_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_31(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 31U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_131071(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_BDS_ClockModel_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_ClockModel_r12, BDS_ClockModel_r12_sequence);
return offset;
}
static int
dissect_lpp_GNSS_ClockModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ClockModel, GNSS_ClockModel_choice,
NULL);
return offset;
}
static int
dissect_lpp_INTEGER_M2147483648_2147483647(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
G_MININT32, 2147483647U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_4294967295(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4294967295U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_NavModelKeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NavModelKeplerianSet, NavModelKeplerianSet_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_16777215(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 16777215U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_ephemSF1Rsvd(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_ephemSF1Rsvd, T_ephemSF1Rsvd_sequence);
return offset;
}
static int
dissect_lpp_T_addNAVparam(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_addNAVparam, T_addNAVparam_sequence);
return offset;
}
static int
dissect_lpp_NavModelNAV_KeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NavModelNAV_KeplerianSet, NavModelNAV_KeplerianSet_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_M16777216_16777215(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-16777216, 16777215U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M65536_65535(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-65536, 65535U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M4194304_4194303(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4194304, 4194303U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_cnavMo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 758 "./asn1/lpp/lpp.cnf"
gint64 cnavMo;
int curr_offset = offset;
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
G_GINT64_CONSTANT(-4294967296), 4294967295U, &cnavMo, FALSE);
#line 763 "./asn1/lpp/lpp.cnf"
PROTO_ITEM_SET_HIDDEN(actx->created_item);
actx->created_item = proto_tree_add_int64_format_value(tree, hf_index, tvb, curr_offset>>3, (offset+7-curr_offset)>>3,
cnavMo, "%g semi-circles (%"G_GINT64_MODIFIER"d)",
(double)cnavMo*pow(2, -32), cnavMo);
return offset;
}
static int
dissect_lpp_T_cnavE(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 769 "./asn1/lpp/lpp.cnf"
guint64 cnavE;
int curr_offset = offset;
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
0U, G_GUINT64_CONSTANT(8589934591), &cnavE, FALSE);
#line 774 "./asn1/lpp/lpp.cnf"
PROTO_ITEM_SET_HIDDEN(actx->created_item);
actx->created_item = proto_tree_add_uint64_format_value(tree, hf_index, tvb, curr_offset>>3, (offset+7-curr_offset)>>3,
cnavE, "%g (%"G_GINT64_MODIFIER"u)",
(double)cnavE*pow(2, -34), cnavE);
return offset;
}
static int
dissect_lpp_T_cnavOmega(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 780 "./asn1/lpp/lpp.cnf"
gint64 cnavOmega;
int curr_offset = offset;
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
G_GINT64_CONSTANT(-4294967296), 4294967295U, &cnavOmega, FALSE);
#line 785 "./asn1/lpp/lpp.cnf"
PROTO_ITEM_SET_HIDDEN(actx->created_item);
actx->created_item = proto_tree_add_int64_format_value(tree, hf_index, tvb, curr_offset>>3, (offset+7-curr_offset)>>3,
cnavOmega, "%g semi-circles (%"G_GINT64_MODIFIER"d)",
(double)cnavOmega*pow(2, -32), cnavOmega);
return offset;
}
static int
dissect_lpp_T_cnavOMEGA0(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 791 "./asn1/lpp/lpp.cnf"
gint64 cnavOMEGA0;
int curr_offset = offset;
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
G_GINT64_CONSTANT(-4294967296), 4294967295U, &cnavOMEGA0, FALSE);
#line 796 "./asn1/lpp/lpp.cnf"
PROTO_ITEM_SET_HIDDEN(actx->created_item);
actx->created_item = proto_tree_add_int64_format_value(tree, hf_index, tvb, curr_offset>>3, (offset+7-curr_offset)>>3,
cnavOMEGA0, "%g semi-circles (%"G_GINT64_MODIFIER"d)",
(double)cnavOMEGA0*pow(2, -32), cnavOMEGA0);
return offset;
}
static int
dissect_lpp_T_cnavIo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 805 "./asn1/lpp/lpp.cnf"
gint64 cnavIo;
int curr_offset = offset;
offset = dissect_per_constrained_integer_64b(tvb, offset, actx, tree, hf_index,
G_GINT64_CONSTANT(-4294967296), 4294967295U, &cnavIo, FALSE);
#line 810 "./asn1/lpp/lpp.cnf"
PROTO_ITEM_SET_HIDDEN(actx->created_item);
actx->created_item = proto_tree_add_int64_format_value(tree, hf_index, tvb, curr_offset>>3, (offset+7-curr_offset)>>3,
cnavIo, "%g semi-circles (%"G_GINT64_MODIFIER"d)",
(double)cnavIo*pow(2, -32), cnavIo);
return offset;
}
static int
dissect_lpp_NavModelCNAV_KeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NavModelCNAV_KeplerianSet, NavModelCNAV_KeplerianSet_sequence);
return offset;
}
static int
dissect_lpp_T_gloP1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 840 "./asn1/lpp/lpp.cnf"
tvbuff_t *gloP1_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &gloP1_tvb, NULL);
#line 844 "./asn1/lpp/lpp.cnf"
if (gloP1_tvb) {
guint bitvalue = tvb_get_bits8(gloP1_tvb, 0, 2);
actx->created_item = proto_tree_add_uint(tree, hf_index, gloP1_tvb, 0, 1, bitvalue);
}
return offset;
}
static int
dissect_lpp_NavModel_GLONASS_ECEF(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NavModel_GLONASS_ECEF, NavModel_GLONASS_ECEF_sequence);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lpp_INTEGER_M536870912_536870911(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-536870912, 536870911U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M131072_131071(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-131072, 131071U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_NavModel_SBAS_ECEF(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NavModel_SBAS_ECEF, NavModel_SBAS_ECEF_sequence);
return offset;
}
static int
dissect_lpp_NavModel_BDS_KeplerianSet_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NavModel_BDS_KeplerianSet_r12, NavModel_BDS_KeplerianSet_r12_sequence);
return offset;
}
static int
dissect_lpp_GNSS_OrbitModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_OrbitModel, GNSS_OrbitModel_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_svHealthExt_v1240(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 527 "./asn1/lpp/lpp.cnf"
tvbuff_t *svHealthExt_tvb = NULL;
proto_tree *subtree;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, &svHealthExt_tvb, NULL);
#line 532 "./asn1/lpp/lpp.cnf"
if (svHealthExt_tvb) {
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_svHealthExt_v1240);
proto_tree_add_bits_item(subtree, hf_lpp_svHealthExt_v1240_e5bhs, svHealthExt_tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lpp_svHealthExt_v1240_e1_bhs, svHealthExt_tvb, 2, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_lpp_GNSS_NavModelSatelliteElement_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, GNSS_NavModelSatelliteElement_eag_1_sequence);
return offset;
}
static int
dissect_lpp_GNSS_NavModelSatelliteElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_NavModelSatelliteElement, GNSS_NavModelSatelliteElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_NavModelSatelliteList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_NavModelSatelliteList, GNSS_NavModelSatelliteList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_NavigationModel(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_NavigationModel, GNSS_NavigationModel_sequence);
return offset;
}
static int
dissect_lpp_BadSignalElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BadSignalElement, BadSignalElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_BadSignalList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_BadSignalList, GNSS_BadSignalList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_RealTimeIntegrity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_RealTimeIntegrity, GNSS_RealTimeIntegrity_sequence);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_1_1024(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 1024, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lpp_GNSS_DataBitsSgnElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitsSgnElement, GNSS_DataBitsSgnElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_DataBitsSgnList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitsSgnList, GNSS_DataBitsSgnList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_DataBitsSatElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitsSatElement, GNSS_DataBitsSatElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_DataBitsSatList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitsSatList, GNSS_DataBitsSatList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_DataBitAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_DataBitAssistance, GNSS_DataBitAssistance_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_1022(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1022U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_dopplerUncertaintyExt_r10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_GNSS_AcquisitionAssistElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AcquisitionAssistElement, GNSS_AcquisitionAssistElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_AcquisitionAssistList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AcquisitionAssistList, GNSS_AcquisitionAssistList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_AcquisitionAssistance(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AcquisitionAssistance, GNSS_AcquisitionAssistance_sequence);
return offset;
}
static int
dissect_lpp_T_toa(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 997 "./asn1/lpp/lpp.cnf"
guint32 toa, val;
int len, old_offset = offset;
T_GNSS_ID_enum gnss_id = (T_GNSS_ID_enum)GPOINTER_TO_UINT(actx->private_data);
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &toa, FALSE);
#line 1003 "./asn1/lpp/lpp.cnf"
len = (offset-old_offset) >> 3 ? (offset-old_offset) >> 3 : 1;
val = (gnss_id == T_GNSS_ID_GALILEO) ? 600*toa : 4096*toa;
actx->created_item = proto_tree_add_uint_format_value(tree, hf_lpp_toa, tvb, old_offset, len,
toa, "%u s (%u)", val, toa);
return offset;
}
static int
dissect_lpp_T_kepSV_StatusINAV(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1030 "./asn1/lpp/lpp.cnf"
tvbuff_t *statusINAV_tvb = NULL;
proto_tree *subtree;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, &statusINAV_tvb, NULL);
#line 1035 "./asn1/lpp/lpp.cnf"
if (statusINAV_tvb) {
subtree = proto_item_add_subtree(actx->created_item, ett_kepSV_StatusINAV);
proto_tree_add_bits_item(subtree, hf_lpp_kepSV_StatusINAV_e5bhs, statusINAV_tvb, 0, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lpp_kepSV_StatusINAV_e1_bhs, statusINAV_tvb, 2, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_lpp_T_kepSV_StatusFNAV(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1042 "./asn1/lpp/lpp.cnf"
tvbuff_t *statusFNAV_tvb = NULL;
proto_tree *subtree;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
2, 2, FALSE, &statusFNAV_tvb, NULL);
#line 1047 "./asn1/lpp/lpp.cnf"
if (statusFNAV_tvb) {
subtree = proto_item_add_subtree(actx->created_item, ett_kepSV_StatusFNAV);
proto_tree_add_bits_item(subtree, hf_lpp_kepSV_StatusFNAV_e5ahs, statusFNAV_tvb, 0, 2, ENC_BIG_ENDIAN);
}
return offset;
}
static int
dissect_lpp_AlmanacKeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AlmanacKeplerianSet, AlmanacKeplerianSet_sequence);
return offset;
}
static int
dissect_lpp_AlmanacNAV_KeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AlmanacNAV_KeplerianSet, AlmanacNAV_KeplerianSet_sequence);
return offset;
}
static int
dissect_lpp_AlmanacReducedKeplerianSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AlmanacReducedKeplerianSet, AlmanacReducedKeplerianSet_sequence);
return offset;
}
static int
dissect_lpp_AlmanacMidiAlmanacSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AlmanacMidiAlmanacSet, AlmanacMidiAlmanacSet_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_1_1461(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 1461U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_1_24(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 24U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_2097151(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 2097151U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_AlmanacGLONASS_AlmanacSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AlmanacGLONASS_AlmanacSet, AlmanacGLONASS_AlmanacSet_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_M256_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-256, 255U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M4_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-4, 3U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M8_7(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-8, 7U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_AlmanacECEF_SBAS_AlmanacSet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AlmanacECEF_SBAS_AlmanacSet, AlmanacECEF_SBAS_AlmanacSet_sequence);
return offset;
}
static int
dissect_lpp_T_bdsSvHealth_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1209 "./asn1/lpp/lpp.cnf"
tvbuff_t *bdsSvHealth_tvb = NULL;
proto_tree *subtree;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
9, 9, FALSE, &bdsSvHealth_tvb, NULL);
#line 1214 "./asn1/lpp/lpp.cnf"
if (bdsSvHealth_tvb) {
guint16 bits;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bdsSvHealth_r12);
bits = tvb_get_bits16(bdsSvHealth_tvb, 0, 9,ENC_BIG_ENDIAN);
if (bits == 0x1ff) {
proto_tree_add_boolean_bits_format_value(subtree, hf_lpp_bdsSvHealth_r12_sat_clock, bdsSvHealth_tvb, 0, 1, 1,
"Satellite is in failure or permanently shut off (1)");
} else if (bits == 0x100) {
proto_tree_add_boolean_bits_format_value(subtree, hf_lpp_bdsSvHealth_r12_sat_clock, bdsSvHealth_tvb, 0, 1, 1,
"Satellite clock is unavailable (1)");
} else {
proto_tree_add_bits_item(subtree, hf_lpp_bdsSvHealth_r12_sat_clock, bdsSvHealth_tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lpp_bdsSvHealth_r12_b1i, bdsSvHealth_tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lpp_bdsSvHealth_r12_b2i, bdsSvHealth_tvb, 2, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_lpp_bdsSvHealth_r12_nav, bdsSvHealth_tvb, 7, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_AlmanacBDS_AlmanacSet_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_AlmanacBDS_AlmanacSet_r12, AlmanacBDS_AlmanacSet_r12_sequence);
return offset;
}
static int
dissect_lpp_GNSS_AlmanacElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AlmanacElement, GNSS_AlmanacElement_choice,
NULL);
return offset;
}
static int
dissect_lpp_GNSS_AlmanacList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AlmanacList, GNSS_AlmanacList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_T_toa_ext_v1240(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1009 "./asn1/lpp/lpp.cnf"
guint32 toa_ext, val;
int len, old_offset = offset;
T_GNSS_ID_enum gnss_id = (T_GNSS_ID_enum)GPOINTER_TO_UINT(actx->private_data);
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
256U, 1023U, &toa_ext, FALSE);
#line 1015 "./asn1/lpp/lpp.cnf"
len = (offset-old_offset) >> 3 ? (offset-old_offset) >> 3 : 1;
val = (gnss_id == T_GNSS_ID_GALILEO) ? 600*toa_ext : 4096*toa_ext;
actx->created_item = proto_tree_add_uint_format_value(tree, hf_lpp_toa_ext_v1240, tvb, old_offset, len,
toa_ext, "%u s (%u)", val, toa_ext);
return offset;
}
static int
dissect_lpp_INTEGER_4_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
4U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_Almanac_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, GNSS_Almanac_eag_1_sequence);
return offset;
}
static int
dissect_lpp_GNSS_Almanac(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_Almanac, GNSS_Almanac_sequence);
return offset;
}
static int
dissect_lpp_UTC_ModelSet1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_UTC_ModelSet1, UTC_ModelSet1_sequence);
return offset;
}
static int
dissect_lpp_T_utcDN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1278 "./asn1/lpp/lpp.cnf"
tvbuff_t *utcDN_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
4, 4, FALSE, &utcDN_tvb, NULL);
#line 1282 "./asn1/lpp/lpp.cnf"
if (utcDN_tvb) {
guint bitvalue = tvb_get_bits8(utcDN_tvb, 0, 4);
actx->created_item = proto_tree_add_uint(tree, hf_index, utcDN_tvb, 0, 1, bitvalue);
}
return offset;
}
static int
dissect_lpp_UTC_ModelSet2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_UTC_ModelSet2, UTC_ModelSet2_sequence);
return offset;
}
static int
dissect_lpp_T_kp(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1306 "./asn1/lpp/lpp.cnf"
tvbuff_t *kp_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &kp_tvb, NULL);
#line 1310 "./asn1/lpp/lpp.cnf"
if (kp_tvb) {
guint bitvalue = tvb_get_bits8(kp_tvb, 0, 2);
actx->created_item = proto_tree_add_uint(tree, hf_index, kp_tvb, 0, 1, bitvalue);
}
return offset;
}
static int
dissect_lpp_UTC_ModelSet3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_UTC_ModelSet3, UTC_ModelSet3_sequence);
return offset;
}
static int
dissect_lpp_UTC_ModelSet4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_UTC_ModelSet4, UTC_ModelSet4_sequence);
return offset;
}
static int
dissect_lpp_UTC_ModelSet5_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_UTC_ModelSet5_r12, UTC_ModelSet5_r12_sequence);
return offset;
}
static int
dissect_lpp_GNSS_UTC_Model(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_UTC_Model, GNSS_UTC_Model_choice,
NULL);
return offset;
}
static int
dissect_lpp_GNSS_ID_GPS_SatElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ID_GPS_SatElement, GNSS_ID_GPS_SatElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_ID_GPS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ID_GPS, GNSS_ID_GPS_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_M7_13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-7, 13U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_ID_GLONASS_SatElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ID_GLONASS_SatElement, GNSS_ID_GLONASS_SatElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_ID_GLONASS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_ID_GLONASS, GNSS_ID_GLONASS_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_AuxiliaryInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_AuxiliaryInformation, GNSS_AuxiliaryInformation_choice,
NULL);
return offset;
}
static int
dissect_lpp_DBDS_CorrectionElement_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_DBDS_CorrectionElement_r12, DBDS_CorrectionElement_r12_sequence);
return offset;
}
static int
dissect_lpp_DBDS_CorrectionList_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_DBDS_CorrectionList_r12, DBDS_CorrectionList_r12_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_BDS_SgnTypeElement_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_SgnTypeElement_r12, BDS_SgnTypeElement_r12_sequence);
return offset;
}
static int
dissect_lpp_BDS_SgnTypeList_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_SgnTypeList_r12, BDS_SgnTypeList_r12_sequence_of,
1, 3, FALSE);
return offset;
}
static int
dissect_lpp_BDS_DifferentialCorrections_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_DifferentialCorrections_r12, BDS_DifferentialCorrections_r12_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_1_320(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 320U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GridIonElement_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GridIonElement_r12, GridIonElement_r12_sequence);
return offset;
}
static int
dissect_lpp_GridIonList_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GridIonList_r12, GridIonList_r12_sequence_of,
1, 320, FALSE);
return offset;
}
static int
dissect_lpp_BDS_GridModelParameter_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BDS_GridModelParameter_r12, BDS_GridModelParameter_r12_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistDataElement_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, GNSS_GenericAssistDataElement_eag_1_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistDataElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_GenericAssistDataElement, GNSS_GenericAssistDataElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_GenericAssistData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_GenericAssistData, GNSS_GenericAssistData_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lpp_T_cause_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_GNSS_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_LocationServerErrorCauses, GNSS_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lpp_T_cause_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_GNSS_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_TargetDeviceErrorCauses, GNSS_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lpp_A_GNSS_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_A_GNSS_Error, A_GNSS_Error_choice,
NULL);
return offset;
}
static int
dissect_lpp_A_GNSS_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_A_GNSS_ProvideAssistanceData, A_GNSS_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lpp_T_antennaPortConfig(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_T_cpLength(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_T_prs_Bandwidth(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
6, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_INTEGER_0_4095(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 4095U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_numDL_Frames(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_T_prs_MutingInfo_r9(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_prs_MutingInfo_r9, T_prs_MutingInfo_r9_choice,
NULL);
return offset;
}
static int
dissect_lpp_PRS_Info(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_PRS_Info, PRS_Info_sequence);
return offset;
}
static int
dissect_lpp_OTDOA_ReferenceCellInfo_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, OTDOA_ReferenceCellInfo_eag_1_sequence);
return offset;
}
int
dissect_lpp_OTDOA_ReferenceCellInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_ReferenceCellInfo, OTDOA_ReferenceCellInfo_sequence);
return offset;
}
static int
dissect_lpp_T_cpLength_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_T_antennaPortConfig_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_INTEGER_0_19(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 19U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_1279(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 1279U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_OTDOA_NeighbourCellInfoElement_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, OTDOA_NeighbourCellInfoElement_eag_1_sequence);
return offset;
}
int
dissect_lpp_OTDOA_NeighbourCellInfoElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_NeighbourCellInfoElement, OTDOA_NeighbourCellInfoElement_sequence);
return offset;
}
static int
dissect_lpp_OTDOA_NeighbourFreqInfo(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_NeighbourFreqInfo, OTDOA_NeighbourFreqInfo_sequence_of,
1, 24, FALSE);
return offset;
}
static int
dissect_lpp_OTDOA_NeighbourCellInfoList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_NeighbourCellInfoList, OTDOA_NeighbourCellInfoList_sequence_of,
1, maxFreqLayers, FALSE);
return offset;
}
static int
dissect_lpp_T_cause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_OTDOA_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_LocationServerErrorCauses, OTDOA_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lpp_T_cause_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_OTDOA_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_TargetDeviceErrorCauses, OTDOA_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lpp_OTDOA_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_Error, OTDOA_Error_choice,
NULL);
return offset;
}
static int
dissect_lpp_OTDOA_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_ProvideAssistanceData, OTDOA_ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lpp_ProvideAssistanceData_r9_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ProvideAssistanceData_r9_IEs, ProvideAssistanceData_r9_IEs_sequence);
return offset;
}
static int
dissect_lpp_T_c1_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_c1_04, T_c1_04_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_criticalExtensionsFuture_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensionsFuture_03, T_criticalExtensionsFuture_03_sequence);
return offset;
}
static int
dissect_lpp_T_criticalExtensions_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensions_03, T_criticalExtensions_03_choice,
NULL);
return offset;
}
static int
dissect_lpp_ProvideAssistanceData(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 69 "./asn1/lpp/lpp.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Provide Assistance Data");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ProvideAssistanceData, ProvideAssistanceData_sequence);
return offset;
}
static int
dissect_lpp_LocationInformationType(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_ReportingDuration(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 279 "./asn1/lpp/lpp.cnf"
guint32 duration;
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, &duration, FALSE);
if (duration == 0) {
proto_item_append_text(actx->created_item, " (infinite)");
}
return offset;
}
static int
dissect_lpp_TriggeredReportingCriteria(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_TriggeredReportingCriteria, TriggeredReportingCriteria_sequence);
return offset;
}
static int
dissect_lpp_T_reportingAmount(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
8, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_T_reportingInterval(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 267 "./asn1/lpp/lpp.cnf"
guint32 idx;
const gchar *interval[10] = {"", ": 1s", ": 2s", ": 4s", ": 8s", ": 10s",
": 16s", ": 20s", ": 32s", ": 64s"};
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
10, &idx, FALSE, 0, NULL);
#line 274 "./asn1/lpp/lpp.cnf"
if (idx < 10) {
proto_item_append_text(actx->created_item, "%s", interval[idx]);
}
return offset;
}
static int
dissect_lpp_PeriodicalReportingCriteria(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_PeriodicalReportingCriteria, PeriodicalReportingCriteria_sequence);
return offset;
}
static int
dissect_lpp_AdditionalInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_HorizontalAccuracy(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_HorizontalAccuracy, HorizontalAccuracy_sequence);
return offset;
}
static int
dissect_lpp_VerticalAccuracy(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_VerticalAccuracy, VerticalAccuracy_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_1_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
1U, 128U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_ResponseTime_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, ResponseTime_eag_1_sequence);
return offset;
}
static int
dissect_lpp_ResponseTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ResponseTime, ResponseTime_sequence);
return offset;
}
static int
dissect_lpp_QoS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_QoS, QoS_sequence);
return offset;
}
static int
dissect_lpp_Environment(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_CommonIEsRequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CommonIEsRequestLocationInformation, CommonIEsRequestLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_GNSS_PositioningInstructions(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_PositioningInstructions, GNSS_PositioningInstructions_sequence);
return offset;
}
static int
dissect_lpp_A_GNSS_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_A_GNSS_RequestLocationInformation, A_GNSS_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_OTDOA_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_RequestLocationInformation, OTDOA_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_T_requestedMeasurements(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1638 "./asn1/lpp/lpp.cnf"
tvbuff_t *requestedMeasurements_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &requestedMeasurements_tvb, &len);
if(requestedMeasurements_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_requestedMeasurements_rsrpReq, requestedMeasurements_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_requestedMeasurements_rsrqReq, requestedMeasurements_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_T_requestedMeasurements_ueRxTxReq, requestedMeasurements_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_ECID_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ECID_RequestLocationInformation, ECID_RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_Sensor_RequestLocationInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Sensor_RequestLocationInformation_r13, Sensor_RequestLocationInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_TBS_RequestLocationInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_TBS_RequestLocationInformation_r13, TBS_RequestLocationInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_T_requestedMeasurements_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1736 "./asn1/lpp/lpp.cnf"
tvbuff_t *requestedMeasurements_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &requestedMeasurements_tvb, &len);
if(requestedMeasurements_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_requestedMeasurements_r13_rssi, requestedMeasurements_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_T_requestedMeasurements_r13_rtt, requestedMeasurements_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_WLAN_RequestLocationInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_RequestLocationInformation_r13, WLAN_RequestLocationInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_T_requestedMeasurements_r13_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1799 "./asn1/lpp/lpp.cnf"
tvbuff_t *requestedMeasurements_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 8, FALSE, &requestedMeasurements_tvb, &len);
if(requestedMeasurements_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_T_requestedMeasurements_r13_01_rssi, requestedMeasurements_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_BT_RequestLocationInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_RequestLocationInformation_r13, BT_RequestLocationInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_RequestLocationInformation_r9_IEs_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, RequestLocationInformation_r9_IEs_eag_1_sequence);
return offset;
}
static int
dissect_lpp_RequestLocationInformation_r9_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_RequestLocationInformation_r9_IEs, RequestLocationInformation_r9_IEs_sequence);
return offset;
}
static int
dissect_lpp_T_c1_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_c1_05, T_c1_05_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_criticalExtensionsFuture_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensionsFuture_04, T_criticalExtensionsFuture_04_sequence);
return offset;
}
static int
dissect_lpp_T_criticalExtensions_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensions_04, T_criticalExtensions_04_choice,
NULL);
return offset;
}
static int
dissect_lpp_RequestLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 72 "./asn1/lpp/lpp.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Request Location Information");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_RequestLocationInformation, RequestLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_T_latitudeSign(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
int
dissect_lpp_Ellipsoid_Point(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Ellipsoid_Point, Ellipsoid_Point_sequence);
return offset;
}
static int
dissect_lpp_T_latitudeSign_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
int
dissect_lpp_Ellipsoid_PointWithUncertaintyCircle(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Ellipsoid_PointWithUncertaintyCircle, Ellipsoid_PointWithUncertaintyCircle_sequence);
return offset;
}
static int
dissect_lpp_T_latitudeSign_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
int
dissect_lpp_EllipsoidPointWithUncertaintyEllipse(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_EllipsoidPointWithUncertaintyEllipse, EllipsoidPointWithUncertaintyEllipse_sequence);
return offset;
}
static int
dissect_lpp_T_latitudeSign_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_PolygonPoints(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_PolygonPoints, PolygonPoints_sequence);
return offset;
}
int
dissect_lpp_Polygon(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_Polygon, Polygon_sequence_of,
3, 15, FALSE);
return offset;
}
static int
dissect_lpp_T_latitudeSign_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_T_altitudeDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
int
dissect_lpp_EllipsoidPointWithAltitude(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_EllipsoidPointWithAltitude, EllipsoidPointWithAltitude_sequence);
return offset;
}
static int
dissect_lpp_T_latitudeSign_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
int
dissect_lpp_EllipsoidArc(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_EllipsoidArc, EllipsoidArc_sequence);
return offset;
}
static int
dissect_lpp_LocationCoordinates(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_LocationCoordinates, LocationCoordinates_choice,
NULL);
return offset;
}
static int
dissect_lpp_INTEGER_0_359(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 359U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_HorizontalVelocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_HorizontalVelocity, HorizontalVelocity_sequence);
return offset;
}
static int
dissect_lpp_T_verticalDirection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_HorizontalWithVerticalVelocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_HorizontalWithVerticalVelocity, HorizontalWithVerticalVelocity_sequence);
return offset;
}
static int
dissect_lpp_HorizontalVelocityWithUncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_HorizontalVelocityWithUncertainty, HorizontalVelocityWithUncertainty_sequence);
return offset;
}
static int
dissect_lpp_T_verticalDirection_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_HorizontalWithVerticalVelocityAndUncertainty(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_HorizontalWithVerticalVelocityAndUncertainty, HorizontalWithVerticalVelocityAndUncertainty_sequence);
return offset;
}
static int
dissect_lpp_Velocity(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_Velocity, Velocity_choice,
NULL);
return offset;
}
static int
dissect_lpp_LocationFailureCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_LocationError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_LocationError, LocationError_sequence);
return offset;
}
static int
dissect_lpp_EarlyFixReport_r12(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_lpp_CommonIEsProvideLocationInformation_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, CommonIEsProvideLocationInformation_eag_1_sequence);
return offset;
}
static int
dissect_lpp_LocationSource_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 308 "./asn1/lpp/lpp.cnf"
tvbuff_t *locSource_tvb = NULL;
int len;
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
1, 16, FALSE, &locSource_tvb, &len);
if(locSource_tvb){
proto_tree *subtree;
subtree = proto_item_add_subtree(actx->created_item, ett_lpp_bitmap);
if (len >= 1) {
proto_tree_add_item(subtree, hf_lpp_LocationSource_r13_a_gnss, locSource_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 2) {
proto_tree_add_item(subtree, hf_lpp_LocationSource_r13_wlan, locSource_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 3) {
proto_tree_add_item(subtree, hf_lpp_LocationSource_r13_bt, locSource_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 4) {
proto_tree_add_item(subtree, hf_lpp_LocationSource_r13_tbs, locSource_tvb, 0, 1, ENC_BIG_ENDIAN);
}
if (len >= 5) {
proto_tree_add_item(subtree, hf_lpp_LocationSource_r13_sensor, locSource_tvb, 0, 1, ENC_BIG_ENDIAN);
}
}
return offset;
}
static int
dissect_lpp_UTCTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_VisibleString(tvb, offset, actx, tree, hf_index,
NO_BOUND, NO_BOUND, FALSE);
return offset;
}
static int
dissect_lpp_CommonIEsProvideLocationInformation_eag_2(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, CommonIEsProvideLocationInformation_eag_2_sequence);
return offset;
}
static int
dissect_lpp_CommonIEsProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CommonIEsProvideLocationInformation, CommonIEsProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_3599999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3599999U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_3999(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3999U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_BIT_STRING_SIZE_10(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
10, 10, FALSE, NULL, NULL);
return offset;
}
static int
dissect_lpp_T_eUTRA_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_eUTRA_01, T_eUTRA_01_sequence);
return offset;
}
static int
dissect_lpp_T_fdd_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_fdd_01, T_fdd_01_sequence);
return offset;
}
static int
dissect_lpp_T_tdd_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_tdd_01, T_tdd_01_sequence);
return offset;
}
static int
dissect_lpp_T_mode_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_mode_01, T_mode_01_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_uTRA_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_uTRA_01, T_uTRA_01_sequence);
return offset;
}
static int
dissect_lpp_T_referenceFrame(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_referenceFrame, T_referenceFrame_sequence);
return offset;
}
static int
dissect_lpp_T_gSM_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_gSM_01, T_gSM_01_sequence);
return offset;
}
static int
dissect_lpp_T_networkTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_networkTime, T_networkTime_choice,
NULL);
return offset;
}
static int
dissect_lpp_MeasurementReferenceTime(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_MeasurementReferenceTime, MeasurementReferenceTime_sequence);
return offset;
}
static int
dissect_lpp_T_mpathDet(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_INTEGER_0_33554431(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 33554431U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_SatMeasElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SatMeasElement, GNSS_SatMeasElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_SatMeasList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SatMeasList, GNSS_SatMeasList_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_SgnMeasElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SgnMeasElement, GNSS_SgnMeasElement_sequence);
return offset;
}
static int
dissect_lpp_GNSS_SgnMeasList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SgnMeasList, GNSS_SgnMeasList_sequence_of,
1, 8, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_MeasurementForOneGNSS(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_MeasurementForOneGNSS, GNSS_MeasurementForOneGNSS_sequence);
return offset;
}
static int
dissect_lpp_GNSS_MeasurementList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_MeasurementList, GNSS_MeasurementList_sequence_of,
1, 16, FALSE);
return offset;
}
static int
dissect_lpp_GNSS_SignalMeasurementInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_SignalMeasurementInformation, GNSS_SignalMeasurementInformation_sequence);
return offset;
}
static int
dissect_lpp_GNSS_LocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_GNSS_LocationInformation, GNSS_LocationInformation_sequence);
return offset;
}
static int
dissect_lpp_A_GNSS_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_A_GNSS_ProvideLocationInformation, A_GNSS_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_T_error_Resolution(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 343 "./asn1/lpp/lpp.cnf"
tvbuff_t *error_Resolution_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
2, 2, FALSE, &error_Resolution_tvb, NULL);
#line 347 "./asn1/lpp/lpp.cnf"
if (error_Resolution_tvb) {
guint bitvalue = tvb_get_bits8(error_Resolution_tvb, 0, 2);
actx->created_item = proto_tree_add_uint(tree, hf_index, error_Resolution_tvb, 0, 1, bitvalue);
}
return offset;
}
static int
dissect_lpp_T_error_Value(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 356 "./asn1/lpp/lpp.cnf"
tvbuff_t *error_Value_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
5, 5, FALSE, &error_Value_tvb, NULL);
#line 360 "./asn1/lpp/lpp.cnf"
if (error_Value_tvb) {
guint bitvalue = tvb_get_bits8(error_Value_tvb, 0, 5);
actx->created_item = proto_tree_add_uint(tree, hf_index, error_Value_tvb, 0, 1, bitvalue);
}
return offset;
}
static int
dissect_lpp_T_error_NumSamples(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 369 "./asn1/lpp/lpp.cnf"
tvbuff_t *error_NumSamples_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
3, 3, FALSE, &error_NumSamples_tvb, NULL);
#line 373 "./asn1/lpp/lpp.cnf"
if (error_NumSamples_tvb) {
guint bitvalue = tvb_get_bits8(error_NumSamples_tvb, 0, 3);
actx->created_item = proto_tree_add_uint(tree, hf_index, error_NumSamples_tvb, 0, 1, bitvalue);
}
return offset;
}
static int
dissect_lpp_OTDOA_MeasQuality(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_MeasQuality, OTDOA_MeasQuality_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_12711(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 12711U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_NeighbourMeasurementElement_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, NeighbourMeasurementElement_eag_1_sequence);
return offset;
}
static int
dissect_lpp_NeighbourMeasurementElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_NeighbourMeasurementElement, NeighbourMeasurementElement_sequence);
return offset;
}
static int
dissect_lpp_NeighbourMeasurementList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_NeighbourMeasurementList, NeighbourMeasurementList_sequence_of,
1, 24, FALSE);
return offset;
}
static int
dissect_lpp_OTDOA_SignalMeasurementInformation_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, OTDOA_SignalMeasurementInformation_eag_1_sequence);
return offset;
}
static int
dissect_lpp_OTDOA_SignalMeasurementInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_SignalMeasurementInformation, OTDOA_SignalMeasurementInformation_sequence);
return offset;
}
static int
dissect_lpp_OTDOA_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_OTDOA_ProvideLocationInformation, OTDOA_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_97(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 97U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_INTEGER_0_34(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 34U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_MeasuredResultsElement_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, MeasuredResultsElement_eag_1_sequence);
return offset;
}
static int
dissect_lpp_MeasuredResultsElement(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_MeasuredResultsElement, MeasuredResultsElement_sequence);
return offset;
}
static int
dissect_lpp_MeasuredResultsList(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_MeasuredResultsList, MeasuredResultsList_sequence_of,
1, 32, FALSE);
return offset;
}
int
dissect_lpp_ECID_SignalMeasurementInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ECID_SignalMeasurementInformation, ECID_SignalMeasurementInformation_sequence);
return offset;
}
static int
dissect_lpp_T_cause_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_ECID_LocationServerErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ECID_LocationServerErrorCauses, ECID_LocationServerErrorCauses_sequence);
return offset;
}
static int
dissect_lpp_T_cause_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_ECID_TargetDeviceErrorCauses(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ECID_TargetDeviceErrorCauses, ECID_TargetDeviceErrorCauses_sequence);
return offset;
}
static int
dissect_lpp_ECID_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_ECID_Error, ECID_Error_choice,
NULL);
return offset;
}
static int
dissect_lpp_ECID_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ECID_ProvideLocationInformation, ECID_ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_30000_115000(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
30000U, 115000U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_Sensor_MeasurementInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Sensor_MeasurementInformation_r13, Sensor_MeasurementInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_T_cause_r13_02(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_Sensor_LocationServerErrorCauses_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Sensor_LocationServerErrorCauses_r13, Sensor_LocationServerErrorCauses_r13_sequence);
return offset;
}
static int
dissect_lpp_T_cause_r13_03(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_Sensor_TargetDeviceErrorCauses_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Sensor_TargetDeviceErrorCauses_r13, Sensor_TargetDeviceErrorCauses_r13_sequence);
return offset;
}
static int
dissect_lpp_Sensor_Error_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_Sensor_Error_r13, Sensor_Error_r13_choice,
NULL);
return offset;
}
static int
dissect_lpp_Sensor_ProvideLocationInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Sensor_ProvideLocationInformation_r13, Sensor_ProvideLocationInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_MBS_BeaconMeasElement_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_MBS_BeaconMeasElement_r13, MBS_BeaconMeasElement_r13_sequence);
return offset;
}
static int
dissect_lpp_MBS_BeaconMeasList_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_MBS_BeaconMeasList_r13, MBS_BeaconMeasList_r13_sequence_of,
1, 64, FALSE);
return offset;
}
static int
dissect_lpp_TBS_MeasurementInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_TBS_MeasurementInformation_r13, TBS_MeasurementInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_T_cause_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_TBS_LocationServerErrorCauses_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_TBS_LocationServerErrorCauses_r13, TBS_LocationServerErrorCauses_r13_sequence);
return offset;
}
static int
dissect_lpp_T_cause_r13_01(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_TBS_TargetDeviceErrorCauses_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_TBS_TargetDeviceErrorCauses_r13, TBS_TargetDeviceErrorCauses_r13_sequence);
return offset;
}
static int
dissect_lpp_TBS_Error_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_TBS_Error_r13, TBS_Error_r13_choice,
NULL);
return offset;
}
static int
dissect_lpp_TBS_ProvideLocationInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_TBS_ProvideLocationInformation_r13, TBS_ProvideLocationInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_OCTET_STRING_SIZE_6(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
6, 6, FALSE, NULL);
return offset;
}
static int
dissect_lpp_T_ssid_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1730 "./asn1/lpp/lpp.cnf"
tvbuff_t *ssid_tvb = NULL;
offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
1, 32, FALSE, &ssid_tvb);
actx->created_item = proto_tree_add_item(tree, hf_index, ssid_tvb, 0, -1, ENC_ASCII|ENC_NA);
return offset;
}
static int
dissect_lpp_WLAN_AP_Identifier_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_AP_Identifier_r13, WLAN_AP_Identifier_r13_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_M127_128(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
-127, 128U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_T_rttUnits_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_WLAN_RTT_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_RTT_r13, WLAN_RTT_r13_sequence);
return offset;
}
static int
dissect_lpp_INTEGER_0_256(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 256U, NULL, FALSE);
return offset;
}
static int
dissect_lpp_WLAN_MeasurementElement_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_MeasurementElement_r13, WLAN_MeasurementElement_r13_sequence);
return offset;
}
static int
dissect_lpp_WLAN_MeasurementList_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_MeasurementList_r13, WLAN_MeasurementList_r13_sequence_of,
1, maxWLAN_AP_r13, FALSE);
return offset;
}
static int
dissect_lpp_WLAN_MeasurementInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_MeasurementInformation_r13, WLAN_MeasurementInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_T_cause_r13_04(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_WLAN_LocationServerErrorCauses_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_LocationServerErrorCauses_r13, WLAN_LocationServerErrorCauses_r13_sequence);
return offset;
}
static int
dissect_lpp_T_cause_r13_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_WLAN_TargetDeviceErrorCauses_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_TargetDeviceErrorCauses_r13, WLAN_TargetDeviceErrorCauses_r13_sequence);
return offset;
}
static int
dissect_lpp_WLAN_Error_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_Error_r13, WLAN_Error_r13_choice,
NULL);
return offset;
}
static int
dissect_lpp_WLAN_ProvideLocationInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_WLAN_ProvideLocationInformation_r13, WLAN_ProvideLocationInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_T_btAddr_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 1790 "./asn1/lpp/lpp.cnf"
tvbuff_t *btAddr_tvb = NULL;
offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
48, 48, FALSE, &btAddr_tvb, NULL);
actx->created_item = proto_tree_add_item(tree, hf_index, btAddr_tvb, 0, 6, ENC_NA);
return offset;
}
static int
dissect_lpp_BT_MeasurementElement_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_MeasurementElement_r13, BT_MeasurementElement_r13_sequence);
return offset;
}
static int
dissect_lpp_BT_MeasurementList_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_sequence_of(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_MeasurementList_r13, BT_MeasurementList_r13_sequence_of,
1, maxBT_Beacon_r13, FALSE);
return offset;
}
static int
dissect_lpp_BT_MeasurementInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_MeasurementInformation_r13, BT_MeasurementInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_T_cause_r13_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
1, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_BT_LocationServerErrorCauses_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_LocationServerErrorCauses_r13, BT_LocationServerErrorCauses_r13_sequence);
return offset;
}
static int
dissect_lpp_T_cause_r13_07(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
3, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_BT_TargetDeviceErrorCauses_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_TargetDeviceErrorCauses_r13, BT_TargetDeviceErrorCauses_r13_sequence);
return offset;
}
static int
dissect_lpp_BT_Error_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_Error_r13, BT_Error_r13_choice,
NULL);
return offset;
}
static int
dissect_lpp_BT_ProvideLocationInformation_r13(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_BT_ProvideLocationInformation_r13, BT_ProvideLocationInformation_r13_sequence);
return offset;
}
static int
dissect_lpp_ProvideLocationInformation_r9_IEs_eag_1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence_eag(tvb, offset, actx, tree, ProvideLocationInformation_r9_IEs_eag_1_sequence);
return offset;
}
static int
dissect_lpp_ProvideLocationInformation_r9_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ProvideLocationInformation_r9_IEs, ProvideLocationInformation_r9_IEs_sequence);
return offset;
}
static int
dissect_lpp_T_c1_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_c1_06, T_c1_06_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_criticalExtensionsFuture_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensionsFuture_05, T_criticalExtensionsFuture_05_sequence);
return offset;
}
static int
dissect_lpp_T_criticalExtensions_05(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensions_05, T_criticalExtensions_05_choice,
NULL);
return offset;
}
static int
dissect_lpp_ProvideLocationInformation(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 75 "./asn1/lpp/lpp.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Provide Location Information");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_ProvideLocationInformation, ProvideLocationInformation_sequence);
return offset;
}
static int
dissect_lpp_T_abortCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_CommonIEsAbort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CommonIEsAbort, CommonIEsAbort_sequence);
return offset;
}
static int
dissect_lpp_Abort_r9_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Abort_r9_IEs, Abort_r9_IEs_sequence);
return offset;
}
static int
dissect_lpp_T_c1_07(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_c1_07, T_c1_07_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_criticalExtensionsFuture_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensionsFuture_06, T_criticalExtensionsFuture_06_sequence);
return offset;
}
static int
dissect_lpp_T_criticalExtensions_06(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensions_06, T_criticalExtensions_06_choice,
NULL);
return offset;
}
static int
dissect_lpp_Abort(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 78 "./asn1/lpp/lpp.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Abort");
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Abort, Abort_sequence);
return offset;
}
static int
dissect_lpp_T_errorCause(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
5, NULL, TRUE, 0, NULL);
return offset;
}
static int
dissect_lpp_CommonIEsError(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_CommonIEsError, CommonIEsError_sequence);
return offset;
}
static int
dissect_lpp_Error_r9_IEs(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_Error_r9_IEs, Error_r9_IEs_sequence);
return offset;
}
static int
dissect_lpp_T_criticalExtensionsFuture_07(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_criticalExtensionsFuture_07, T_criticalExtensionsFuture_07_sequence);
return offset;
}
static int
dissect_lpp_Error(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
#line 81 "./asn1/lpp/lpp.cnf"
col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Error");
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_Error, Error_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_c1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_T_c1, T_c1_choice,
NULL);
return offset;
}
static int
dissect_lpp_T_messageClassExtension(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_T_messageClassExtension, T_messageClassExtension_sequence);
return offset;
}
static int
dissect_lpp_LPP_MessageBody(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_choice(tvb, offset, actx, tree, hf_index,
ett_lpp_LPP_MessageBody, LPP_MessageBody_choice,
NULL);
return offset;
}
int
dissect_lpp_LPP_Message(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_lpp_LPP_Message, LPP_Message_sequence);
return offset;
}
static int dissect_LPP_Message_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_LPP_Message(tvb, offset, &asn1_ctx, tree, hf_lpp_LPP_Message_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lpp_Ellipsoid_Point_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_Ellipsoid_Point(tvb, offset, &asn1_ctx, tree, hf_lpp_lpp_Ellipsoid_Point_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lpp_Ellipsoid_PointWithUncertaintyCircle_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_Ellipsoid_PointWithUncertaintyCircle(tvb, offset, &asn1_ctx, tree, hf_lpp_lpp_Ellipsoid_PointWithUncertaintyCircle_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lpp_EllipsoidPointWithUncertaintyEllipse_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_EllipsoidPointWithUncertaintyEllipse(tvb, offset, &asn1_ctx, tree, hf_lpp_lpp_EllipsoidPointWithUncertaintyEllipse_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lpp_EllipsoidPointWithAltitude_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_EllipsoidPointWithAltitude(tvb, offset, &asn1_ctx, tree, hf_lpp_lpp_EllipsoidPointWithAltitude_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lpp_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid(tvb, offset, &asn1_ctx, tree, hf_lpp_lpp_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lpp_EllipsoidArc_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_EllipsoidArc(tvb, offset, &asn1_ctx, tree, hf_lpp_lpp_EllipsoidArc_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lpp_HorizontalVelocity_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_HorizontalVelocity(tvb, offset, &asn1_ctx, tree, hf_lpp_lpp_HorizontalVelocity_PDU);
offset += 7; offset >>= 3;
return offset;
}
int dissect_lpp_Polygon_PDU(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, void *data _U_) {
int offset = 0;
asn1_ctx_t asn1_ctx;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, FALSE, pinfo);
offset = dissect_lpp_Polygon(tvb, offset, &asn1_ctx, tree, hf_lpp_lpp_Polygon_PDU);
offset += 7; offset >>= 3;
return offset;
}
static int dissect_lpp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_) {
proto_tree *subtree;
proto_item *it;
it = proto_tree_add_item(tree, proto_lpp, tvb, 0, -1, ENC_NA);
col_append_sep_str(pinfo->cinfo, COL_PROTOCOL, "/", "LPP");
subtree = proto_item_add_subtree(it, ett_lpp);
return dissect_LPP_Message_PDU(tvb, pinfo, subtree, NULL);
}
void proto_register_lpp(void) {
static hf_register_info hf[] = {
#line 1 "./asn1/lpp/packet-lpp-hfarr.c"
{ &hf_lpp_LPP_Message_PDU,
{ "LPP-Message", "lpp.LPP_Message_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_Ellipsoid_Point_PDU,
{ "Ellipsoid-Point", "lpp.Ellipsoid_Point_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_Ellipsoid_PointWithUncertaintyCircle_PDU,
{ "Ellipsoid-PointWithUncertaintyCircle", "lpp.Ellipsoid_PointWithUncertaintyCircle_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_EllipsoidPointWithUncertaintyEllipse_PDU,
{ "EllipsoidPointWithUncertaintyEllipse", "lpp.EllipsoidPointWithUncertaintyEllipse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_EllipsoidPointWithAltitude_PDU,
{ "EllipsoidPointWithAltitude", "lpp.EllipsoidPointWithAltitude_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_PDU,
{ "EllipsoidPointWithAltitudeAndUncertaintyEllipsoid", "lpp.EllipsoidPointWithAltitudeAndUncertaintyEllipsoid_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_EllipsoidArc_PDU,
{ "EllipsoidArc", "lpp.EllipsoidArc_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_HorizontalVelocity_PDU,
{ "HorizontalVelocity", "lpp.HorizontalVelocity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_Polygon_PDU,
{ "Polygon", "lpp.Polygon",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_transactionID,
{ "transactionID", "lpp.transactionID_element",
FT_NONE, BASE_NONE, NULL, 0,
"LPP_TransactionID", HFILL }},
{ &hf_lpp_endTransaction,
{ "endTransaction", "lpp.endTransaction",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_sequenceNumber,
{ "sequenceNumber", "lpp.sequenceNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_acknowledgement,
{ "acknowledgement", "lpp.acknowledgement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_lpp_MessageBody,
{ "lpp-MessageBody", "lpp.lpp_MessageBody",
FT_UINT32, BASE_DEC, VALS(lpp_LPP_MessageBody_vals), 0,
NULL, HFILL }},
{ &hf_lpp_ackRequested,
{ "ackRequested", "lpp.ackRequested",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_ackIndicator,
{ "ackIndicator", "lpp.ackIndicator",
FT_UINT32, BASE_DEC, NULL, 0,
"SequenceNumber", HFILL }},
{ &hf_lpp_c1,
{ "c1", "lpp.c1",
FT_UINT32, BASE_DEC, VALS(lpp_T_c1_vals), 0,
NULL, HFILL }},
{ &hf_lpp_requestCapabilities,
{ "requestCapabilities", "lpp.requestCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_provideCapabilities,
{ "provideCapabilities", "lpp.provideCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_requestAssistanceData,
{ "requestAssistanceData", "lpp.requestAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_provideAssistanceData,
{ "provideAssistanceData", "lpp.provideAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_requestLocationInformation,
{ "requestLocationInformation", "lpp.requestLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_provideLocationInformation,
{ "provideLocationInformation", "lpp.provideLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_abort,
{ "abort", "lpp.abort_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_error,
{ "error", "lpp.error",
FT_UINT32, BASE_DEC, VALS(lpp_Error_vals), 0,
NULL, HFILL }},
{ &hf_lpp_spare7,
{ "spare7", "lpp.spare7_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_spare6,
{ "spare6", "lpp.spare6_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_spare5,
{ "spare5", "lpp.spare5_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_spare4,
{ "spare4", "lpp.spare4_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_spare3,
{ "spare3", "lpp.spare3_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_spare2,
{ "spare2", "lpp.spare2_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_spare1,
{ "spare1", "lpp.spare1_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_spare0,
{ "spare0", "lpp.spare0_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_messageClassExtension,
{ "messageClassExtension", "lpp.messageClassExtension_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_initiator,
{ "initiator", "lpp.initiator",
FT_UINT32, BASE_DEC, VALS(lpp_Initiator_vals), 0,
NULL, HFILL }},
{ &hf_lpp_transactionNumber,
{ "transactionNumber", "lpp.transactionNumber",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_criticalExtensions,
{ "criticalExtensions", "lpp.criticalExtensions",
FT_UINT32, BASE_DEC, VALS(lpp_T_criticalExtensions_vals), 0,
NULL, HFILL }},
{ &hf_lpp_c1_01,
{ "c1", "lpp.c1",
FT_UINT32, BASE_DEC, VALS(lpp_T_c1_01_vals), 0,
"T_c1_01", HFILL }},
{ &hf_lpp_requestCapabilities_r9,
{ "requestCapabilities-r9", "lpp.requestCapabilities_r9_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestCapabilities_r9_IEs", HFILL }},
{ &hf_lpp_criticalExtensionsFuture,
{ "criticalExtensionsFuture", "lpp.criticalExtensionsFuture_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_commonIEsRequestCapabilities,
{ "commonIEsRequestCapabilities", "lpp.commonIEsRequestCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_a_gnss_RequestCapabilities,
{ "a-gnss-RequestCapabilities", "lpp.a_gnss_RequestCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_otdoa_RequestCapabilities,
{ "otdoa-RequestCapabilities", "lpp.otdoa_RequestCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ecid_RequestCapabilities,
{ "ecid-RequestCapabilities", "lpp.ecid_RequestCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_epdu_RequestCapabilities,
{ "epdu-RequestCapabilities", "lpp.epdu_RequestCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"EPDU_Sequence", HFILL }},
{ &hf_lpp_sensor_RequestCapabilities_r13,
{ "sensor-RequestCapabilities-r13", "lpp.sensor_RequestCapabilities_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_tbs_RequestCapabilities_r13,
{ "tbs-RequestCapabilities-r13", "lpp.tbs_RequestCapabilities_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_RequestCapabilities_r13,
{ "wlan-RequestCapabilities-r13", "lpp.wlan_RequestCapabilities_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bt_RequestCapabilities_r13,
{ "bt-RequestCapabilities-r13", "lpp.bt_RequestCapabilities_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_criticalExtensions_01,
{ "criticalExtensions", "lpp.criticalExtensions",
FT_UINT32, BASE_DEC, VALS(lpp_T_criticalExtensions_01_vals), 0,
"T_criticalExtensions_01", HFILL }},
{ &hf_lpp_c1_02,
{ "c1", "lpp.c1",
FT_UINT32, BASE_DEC, VALS(lpp_T_c1_02_vals), 0,
"T_c1_02", HFILL }},
{ &hf_lpp_provideCapabilities_r9,
{ "provideCapabilities-r9", "lpp.provideCapabilities_r9_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProvideCapabilities_r9_IEs", HFILL }},
{ &hf_lpp_criticalExtensionsFuture_01,
{ "criticalExtensionsFuture", "lpp.criticalExtensionsFuture_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_criticalExtensionsFuture_01", HFILL }},
{ &hf_lpp_commonIEsProvideCapabilities,
{ "commonIEsProvideCapabilities", "lpp.commonIEsProvideCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_a_gnss_ProvideCapabilities,
{ "a-gnss-ProvideCapabilities", "lpp.a_gnss_ProvideCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_otdoa_ProvideCapabilities,
{ "otdoa-ProvideCapabilities", "lpp.otdoa_ProvideCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ecid_ProvideCapabilities,
{ "ecid-ProvideCapabilities", "lpp.ecid_ProvideCapabilities_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_epdu_ProvideCapabilities,
{ "epdu-ProvideCapabilities", "lpp.epdu_ProvideCapabilities",
FT_UINT32, BASE_DEC, NULL, 0,
"EPDU_Sequence", HFILL }},
{ &hf_lpp_sensor_ProvideCapabilities_r13,
{ "sensor-ProvideCapabilities-r13", "lpp.sensor_ProvideCapabilities_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_tbs_ProvideCapabilities_r13,
{ "tbs-ProvideCapabilities-r13", "lpp.tbs_ProvideCapabilities_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_ProvideCapabilities_r13,
{ "wlan-ProvideCapabilities-r13", "lpp.wlan_ProvideCapabilities_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bt_ProvideCapabilities_r13,
{ "bt-ProvideCapabilities-r13", "lpp.bt_ProvideCapabilities_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_criticalExtensions_02,
{ "criticalExtensions", "lpp.criticalExtensions",
FT_UINT32, BASE_DEC, VALS(lpp_T_criticalExtensions_02_vals), 0,
"T_criticalExtensions_02", HFILL }},
{ &hf_lpp_c1_03,
{ "c1", "lpp.c1",
FT_UINT32, BASE_DEC, VALS(lpp_T_c1_03_vals), 0,
"T_c1_03", HFILL }},
{ &hf_lpp_requestAssistanceData_r9,
{ "requestAssistanceData-r9", "lpp.requestAssistanceData_r9_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestAssistanceData_r9_IEs", HFILL }},
{ &hf_lpp_criticalExtensionsFuture_02,
{ "criticalExtensionsFuture", "lpp.criticalExtensionsFuture_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_criticalExtensionsFuture_02", HFILL }},
{ &hf_lpp_commonIEsRequestAssistanceData,
{ "commonIEsRequestAssistanceData", "lpp.commonIEsRequestAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_a_gnss_RequestAssistanceData,
{ "a-gnss-RequestAssistanceData", "lpp.a_gnss_RequestAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_otdoa_RequestAssistanceData,
{ "otdoa-RequestAssistanceData", "lpp.otdoa_RequestAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_epdu_RequestAssistanceData,
{ "epdu-RequestAssistanceData", "lpp.epdu_RequestAssistanceData",
FT_UINT32, BASE_DEC, NULL, 0,
"EPDU_Sequence", HFILL }},
{ &hf_lpp_criticalExtensions_03,
{ "criticalExtensions", "lpp.criticalExtensions",
FT_UINT32, BASE_DEC, VALS(lpp_T_criticalExtensions_03_vals), 0,
"T_criticalExtensions_03", HFILL }},
{ &hf_lpp_c1_04,
{ "c1", "lpp.c1",
FT_UINT32, BASE_DEC, VALS(lpp_T_c1_04_vals), 0,
"T_c1_04", HFILL }},
{ &hf_lpp_provideAssistanceData_r9,
{ "provideAssistanceData-r9", "lpp.provideAssistanceData_r9_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProvideAssistanceData_r9_IEs", HFILL }},
{ &hf_lpp_criticalExtensionsFuture_03,
{ "criticalExtensionsFuture", "lpp.criticalExtensionsFuture_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_criticalExtensionsFuture_03", HFILL }},
{ &hf_lpp_commonIEsProvideAssistanceData,
{ "commonIEsProvideAssistanceData", "lpp.commonIEsProvideAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_a_gnss_ProvideAssistanceData,
{ "a-gnss-ProvideAssistanceData", "lpp.a_gnss_ProvideAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_otdoa_ProvideAssistanceData,
{ "otdoa-ProvideAssistanceData", "lpp.otdoa_ProvideAssistanceData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_epdu_Provide_Assistance_Data,
{ "epdu-Provide-Assistance-Data", "lpp.epdu_Provide_Assistance_Data",
FT_UINT32, BASE_DEC, NULL, 0,
"EPDU_Sequence", HFILL }},
{ &hf_lpp_criticalExtensions_04,
{ "criticalExtensions", "lpp.criticalExtensions",
FT_UINT32, BASE_DEC, VALS(lpp_T_criticalExtensions_04_vals), 0,
"T_criticalExtensions_04", HFILL }},
{ &hf_lpp_c1_05,
{ "c1", "lpp.c1",
FT_UINT32, BASE_DEC, VALS(lpp_T_c1_05_vals), 0,
"T_c1_05", HFILL }},
{ &hf_lpp_requestLocationInformation_r9,
{ "requestLocationInformation-r9", "lpp.requestLocationInformation_r9_element",
FT_NONE, BASE_NONE, NULL, 0,
"RequestLocationInformation_r9_IEs", HFILL }},
{ &hf_lpp_criticalExtensionsFuture_04,
{ "criticalExtensionsFuture", "lpp.criticalExtensionsFuture_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_criticalExtensionsFuture_04", HFILL }},
{ &hf_lpp_commonIEsRequestLocationInformation,
{ "commonIEsRequestLocationInformation", "lpp.commonIEsRequestLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_a_gnss_RequestLocationInformation,
{ "a-gnss-RequestLocationInformation", "lpp.a_gnss_RequestLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_otdoa_RequestLocationInformation,
{ "otdoa-RequestLocationInformation", "lpp.otdoa_RequestLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ecid_RequestLocationInformation,
{ "ecid-RequestLocationInformation", "lpp.ecid_RequestLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_epdu_RequestLocationInformation,
{ "epdu-RequestLocationInformation", "lpp.epdu_RequestLocationInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"EPDU_Sequence", HFILL }},
{ &hf_lpp_sensor_RequestLocationInformation_r13,
{ "sensor-RequestLocationInformation-r13", "lpp.sensor_RequestLocationInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_tbs_RequestLocationInformation_r13,
{ "tbs-RequestLocationInformation-r13", "lpp.tbs_RequestLocationInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_RequestLocationInformation_r13,
{ "wlan-RequestLocationInformation-r13", "lpp.wlan_RequestLocationInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bt_RequestLocationInformation_r13,
{ "bt-RequestLocationInformation-r13", "lpp.bt_RequestLocationInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_criticalExtensions_05,
{ "criticalExtensions", "lpp.criticalExtensions",
FT_UINT32, BASE_DEC, VALS(lpp_T_criticalExtensions_05_vals), 0,
"T_criticalExtensions_05", HFILL }},
{ &hf_lpp_c1_06,
{ "c1", "lpp.c1",
FT_UINT32, BASE_DEC, VALS(lpp_T_c1_06_vals), 0,
"T_c1_06", HFILL }},
{ &hf_lpp_provideLocationInformation_r9,
{ "provideLocationInformation-r9", "lpp.provideLocationInformation_r9_element",
FT_NONE, BASE_NONE, NULL, 0,
"ProvideLocationInformation_r9_IEs", HFILL }},
{ &hf_lpp_criticalExtensionsFuture_05,
{ "criticalExtensionsFuture", "lpp.criticalExtensionsFuture_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_criticalExtensionsFuture_05", HFILL }},
{ &hf_lpp_commonIEsProvideLocationInformation,
{ "commonIEsProvideLocationInformation", "lpp.commonIEsProvideLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_a_gnss_ProvideLocationInformation,
{ "a-gnss-ProvideLocationInformation", "lpp.a_gnss_ProvideLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_otdoa_ProvideLocationInformation,
{ "otdoa-ProvideLocationInformation", "lpp.otdoa_ProvideLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ecid_ProvideLocationInformation,
{ "ecid-ProvideLocationInformation", "lpp.ecid_ProvideLocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_epdu_ProvideLocationInformation,
{ "epdu-ProvideLocationInformation", "lpp.epdu_ProvideLocationInformation",
FT_UINT32, BASE_DEC, NULL, 0,
"EPDU_Sequence", HFILL }},
{ &hf_lpp_sensor_ProvideLocationInformation_r13,
{ "sensor-ProvideLocationInformation-r13", "lpp.sensor_ProvideLocationInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_tbs_ProvideLocationInformation_r13,
{ "tbs-ProvideLocationInformation-r13", "lpp.tbs_ProvideLocationInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_ProvideLocationInformation_r13,
{ "wlan-ProvideLocationInformation-r13", "lpp.wlan_ProvideLocationInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bt_ProvideLocationInformation_r13,
{ "bt-ProvideLocationInformation-r13", "lpp.bt_ProvideLocationInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_criticalExtensions_06,
{ "criticalExtensions", "lpp.criticalExtensions",
FT_UINT32, BASE_DEC, VALS(lpp_T_criticalExtensions_06_vals), 0,
"T_criticalExtensions_06", HFILL }},
{ &hf_lpp_c1_07,
{ "c1", "lpp.c1",
FT_UINT32, BASE_DEC, VALS(lpp_T_c1_07_vals), 0,
"T_c1_07", HFILL }},
{ &hf_lpp_abort_r9,
{ "abort-r9", "lpp.abort_r9_element",
FT_NONE, BASE_NONE, NULL, 0,
"Abort_r9_IEs", HFILL }},
{ &hf_lpp_criticalExtensionsFuture_06,
{ "criticalExtensionsFuture", "lpp.criticalExtensionsFuture_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_criticalExtensionsFuture_06", HFILL }},
{ &hf_lpp_commonIEsAbort,
{ "commonIEsAbort", "lpp.commonIEsAbort_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_epdu_Abort,
{ "epdu-Abort", "lpp.epdu_Abort",
FT_UINT32, BASE_DEC, NULL, 0,
"EPDU_Sequence", HFILL }},
{ &hf_lpp_error_r9,
{ "error-r9", "lpp.error_r9_element",
FT_NONE, BASE_NONE, NULL, 0,
"Error_r9_IEs", HFILL }},
{ &hf_lpp_criticalExtensionsFuture_07,
{ "criticalExtensionsFuture", "lpp.criticalExtensionsFuture_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_criticalExtensionsFuture_07", HFILL }},
{ &hf_lpp_commonIEsError,
{ "commonIEsError", "lpp.commonIEsError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_epdu_Error,
{ "epdu-Error", "lpp.epdu_Error",
FT_UINT32, BASE_DEC, NULL, 0,
"EPDU_Sequence", HFILL }},
{ &hf_lpp_accessTypes,
{ "accessTypes", "lpp.accessTypes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_plmn_Identity,
{ "plmn-Identity", "lpp.plmn_Identity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_mcc,
{ "mcc", "lpp.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_mcc_item,
{ "mcc item", "lpp.mcc_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9", HFILL }},
{ &hf_lpp_mnc,
{ "mnc", "lpp.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_mnc_item,
{ "mnc item", "lpp.mnc_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_9", HFILL }},
{ &hf_lpp_cellIdentity,
{ "cellIdentity", "lpp.cellIdentity",
FT_UINT32, BASE_DEC, VALS(lpp_T_cellIdentity_vals), 0,
NULL, HFILL }},
{ &hf_lpp_eutra,
{ "eutra", "lpp.eutra",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_28", HFILL }},
{ &hf_lpp_utra,
{ "utra", "lpp.utra",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_32", HFILL }},
{ &hf_lpp_plmn_Identity_01,
{ "plmn-Identity", "lpp.plmn_Identity_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_plmn_Identity_01", HFILL }},
{ &hf_lpp_mcc_01,
{ "mcc", "lpp.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mcc_01", HFILL }},
{ &hf_lpp_mnc_01,
{ "mnc", "lpp.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mnc_01", HFILL }},
{ &hf_lpp_locationAreaCode,
{ "locationAreaCode", "lpp.locationAreaCode",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
{ &hf_lpp_cellIdentity_01,
{ "cellIdentity", "lpp.cellIdentity",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
{ &hf_lpp_mcc_02,
{ "mcc", "lpp.mcc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mcc_02", HFILL }},
{ &hf_lpp_mnc_02,
{ "mnc", "lpp.mnc",
FT_UINT32, BASE_DEC, NULL, 0,
"T_mnc_02", HFILL }},
{ &hf_lpp_cellidentity,
{ "cellidentity", "lpp.cellidentity",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_28", HFILL }},
{ &hf_lpp_latitudeSign,
{ "latitudeSign", "lpp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lpp_T_latitudeSign_vals), 0,
NULL, HFILL }},
{ &hf_lpp_degreesLatitude,
{ "degreesLatitude", "lpp.degreesLatitude",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_degreesLatitude_fmt), 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_lpp_degreesLongitude,
{ "degreesLongitude", "lpp.degreesLongitude",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_degreesLongitude_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_latitudeSign_01,
{ "latitudeSign", "lpp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lpp_T_latitudeSign_01_vals), 0,
"T_latitudeSign_01", HFILL }},
{ &hf_lpp_uncertainty,
{ "uncertainty", "lpp.uncertainty",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_uncertainty_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_latitudeSign_02,
{ "latitudeSign", "lpp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lpp_T_latitudeSign_02_vals), 0,
"T_latitudeSign_02", HFILL }},
{ &hf_lpp_uncertaintySemiMajor,
{ "uncertaintySemiMajor", "lpp.uncertaintySemiMajor",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_uncertainty_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_uncertaintySemiMinor,
{ "uncertaintySemiMinor", "lpp.uncertaintySemiMinor",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_uncertainty_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_orientationMajorAxis,
{ "orientationMajorAxis", "lpp.orientationMajorAxis",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_angle_fmt), 0,
"INTEGER_0_179", HFILL }},
{ &hf_lpp_confidence,
{ "confidence", "lpp.confidence",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_confidence_fmt), 0,
"INTEGER_0_100", HFILL }},
{ &hf_lpp_latitudeSign_03,
{ "latitudeSign", "lpp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lpp_T_latitudeSign_03_vals), 0,
"T_latitudeSign_03", HFILL }},
{ &hf_lpp_altitudeDirection,
{ "altitudeDirection", "lpp.altitudeDirection",
FT_UINT32, BASE_DEC, VALS(lpp_T_altitudeDirection_vals), 0,
NULL, HFILL }},
{ &hf_lpp_altitude,
{ "altitude", "lpp.altitude",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_altitude_fmt), 0,
"INTEGER_0_32767", HFILL }},
{ &hf_lpp_latitudeSign_04,
{ "latitudeSign", "lpp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lpp_T_latitudeSign_04_vals), 0,
"T_latitudeSign_04", HFILL }},
{ &hf_lpp_altitudeDirection_01,
{ "altitudeDirection", "lpp.altitudeDirection",
FT_UINT32, BASE_DEC, VALS(lpp_T_altitudeDirection_01_vals), 0,
"T_altitudeDirection_01", HFILL }},
{ &hf_lpp_uncertaintyAltitude,
{ "uncertaintyAltitude", "lpp.uncertaintyAltitude",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_uncertaintyAltitude_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_latitudeSign_05,
{ "latitudeSign", "lpp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lpp_T_latitudeSign_05_vals), 0,
"T_latitudeSign_05", HFILL }},
{ &hf_lpp_innerRadius,
{ "innerRadius", "lpp.innerRadius",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_radius_fmt), 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lpp_uncertaintyRadius,
{ "uncertaintyRadius", "lpp.uncertaintyRadius",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_uncertainty_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_offsetAngle,
{ "offsetAngle", "lpp.offsetAngle",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_angle_fmt), 0,
"INTEGER_0_179", HFILL }},
{ &hf_lpp_includedAngle,
{ "includedAngle", "lpp.includedAngle",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_angle_fmt), 0,
"INTEGER_0_179", HFILL }},
{ &hf_lpp_EPDU_Sequence_item,
{ "EPDU", "lpp.EPDU_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ePDU_Identifier,
{ "ePDU-Identifier", "lpp.ePDU_Identifier_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ePDU_Body,
{ "ePDU-Body", "lpp.ePDU_Body",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ePDU_ID,
{ "ePDU-ID", "lpp.ePDU_ID",
FT_UINT32, BASE_DEC, VALS(lpp_ePDU_ID_vals), 0,
NULL, HFILL }},
{ &hf_lpp_ePDU_Name,
{ "ePDU-Name", "lpp.ePDU_Name",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bearing,
{ "bearing", "lpp.bearing",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_degree_degrees, 0,
"INTEGER_0_359", HFILL }},
{ &hf_lpp_horizontalSpeed,
{ "horizontalSpeed", "lpp.horizontalSpeed",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_kmh, 0,
"INTEGER_0_2047", HFILL }},
{ &hf_lpp_verticalDirection,
{ "verticalDirection", "lpp.verticalDirection",
FT_UINT32, BASE_DEC, VALS(lpp_T_verticalDirection_vals), 0,
NULL, HFILL }},
{ &hf_lpp_verticalSpeed,
{ "verticalSpeed", "lpp.verticalSpeed",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_uncertaintySpeed,
{ "uncertaintySpeed", "lpp.uncertaintySpeed",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_kmh, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_verticalDirection_01,
{ "verticalDirection", "lpp.verticalDirection",
FT_UINT32, BASE_DEC, VALS(lpp_T_verticalDirection_01_vals), 0,
"T_verticalDirection_01", HFILL }},
{ &hf_lpp_horizontalUncertaintySpeed,
{ "horizontalUncertaintySpeed", "lpp.horizontalUncertaintySpeed",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_kmh, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_verticalUncertaintySpeed,
{ "verticalUncertaintySpeed", "lpp.verticalUncertaintySpeed",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_kmh, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_ellipsoidPoint,
{ "ellipsoidPoint", "lpp.ellipsoidPoint",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_ellipsoidPointWithUncertaintyCircle,
{ "ellipsoidPointWithUncertaintyCircle", "lpp.ellipsoidPointWithUncertaintyCircle",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_ellipsoidPointWithUncertaintyEllipse,
{ "ellipsoidPointWithUncertaintyEllipse", "lpp.ellipsoidPointWithUncertaintyEllipse",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_polygon,
{ "polygon", "lpp.polygon",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_ellipsoidPointWithAltitude,
{ "ellipsoidPointWithAltitude", "lpp.ellipsoidPointWithAltitude",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_ellipsoidPointWithAltitudeAndUncertaintyEllipsoid,
{ "ellipsoidPointWithAltitudeAndUncertaintyEllipsoid", "lpp.ellipsoidPointWithAltitudeAndUncertaintyEllipsoid",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_ellipsoidArc,
{ "ellipsoidArc", "lpp.ellipsoidArc",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_Polygon_item,
{ "PolygonPoints", "lpp.PolygonPoints_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_latitudeSign_06,
{ "latitudeSign", "lpp.latitudeSign",
FT_UINT32, BASE_DEC, VALS(lpp_T_latitudeSign_06_vals), 0,
"T_latitudeSign_06", HFILL }},
{ &hf_lpp_posModes,
{ "posModes", "lpp.posModes",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_horizontalVelocity,
{ "horizontalVelocity", "lpp.horizontalVelocity",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_horizontalWithVerticalVelocity,
{ "horizontalWithVerticalVelocity", "lpp.horizontalWithVerticalVelocity",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_horizontalVelocityWithUncertainty,
{ "horizontalVelocityWithUncertainty", "lpp.horizontalVelocityWithUncertainty",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_horizontalWithVerticalVelocityAndUncertainty,
{ "horizontalWithVerticalVelocityAndUncertainty", "lpp.horizontalWithVerticalVelocityAndUncertainty",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_primaryCellID,
{ "primaryCellID", "lpp.primaryCellID_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_lpp_locationInformationType,
{ "locationInformationType", "lpp.locationInformationType",
FT_UINT32, BASE_DEC, VALS(lpp_LocationInformationType_vals), 0,
NULL, HFILL }},
{ &hf_lpp_triggeredReporting,
{ "triggeredReporting", "lpp.triggeredReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"TriggeredReportingCriteria", HFILL }},
{ &hf_lpp_periodicalReporting,
{ "periodicalReporting", "lpp.periodicalReporting_element",
FT_NONE, BASE_NONE, NULL, 0,
"PeriodicalReportingCriteria", HFILL }},
{ &hf_lpp_additionalInformation,
{ "additionalInformation", "lpp.additionalInformation",
FT_UINT32, BASE_DEC, VALS(lpp_AdditionalInformation_vals), 0,
NULL, HFILL }},
{ &hf_lpp_qos,
{ "qos", "lpp.qos_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_environment,
{ "environment", "lpp.environment",
FT_UINT32, BASE_DEC, VALS(lpp_Environment_vals), 0,
NULL, HFILL }},
{ &hf_lpp_locationCoordinateTypes,
{ "locationCoordinateTypes", "lpp.locationCoordinateTypes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_velocityTypes,
{ "velocityTypes", "lpp.velocityTypes_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_reportingAmount,
{ "reportingAmount", "lpp.reportingAmount",
FT_UINT32, BASE_DEC, VALS(lpp_T_reportingAmount_vals), 0,
NULL, HFILL }},
{ &hf_lpp_reportingInterval,
{ "reportingInterval", "lpp.reportingInterval",
FT_UINT32, BASE_DEC, VALS(lpp_T_reportingInterval_vals), 0,
NULL, HFILL }},
{ &hf_lpp_cellChange,
{ "cellChange", "lpp.cellChange",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_reportingDuration,
{ "reportingDuration", "lpp.reportingDuration",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
NULL, HFILL }},
{ &hf_lpp_horizontalAccuracy,
{ "horizontalAccuracy", "lpp.horizontalAccuracy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_verticalCoordinateRequest,
{ "verticalCoordinateRequest", "lpp.verticalCoordinateRequest",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_verticalAccuracy,
{ "verticalAccuracy", "lpp.verticalAccuracy_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_responseTime,
{ "responseTime", "lpp.responseTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_velocityRequest,
{ "velocityRequest", "lpp.velocityRequest",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_accuracy,
{ "accuracy", "lpp.accuracy",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_uncertainty_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_time,
{ "time", "lpp.time",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_1_128", HFILL }},
{ &hf_lpp_responseTimeEarlyFix_r12,
{ "responseTimeEarlyFix-r12", "lpp.responseTimeEarlyFix_r12",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_1_128", HFILL }},
{ &hf_lpp_locationEstimate,
{ "locationEstimate", "lpp.locationEstimate",
FT_UINT32, BASE_DEC, VALS(lpp_LocationCoordinates_vals), 0,
"LocationCoordinates", HFILL }},
{ &hf_lpp_velocityEstimate,
{ "velocityEstimate", "lpp.velocityEstimate",
FT_UINT32, BASE_DEC, VALS(lpp_Velocity_vals), 0,
"Velocity", HFILL }},
{ &hf_lpp_locationError,
{ "locationError", "lpp.locationError_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_earlyFixReport_r12,
{ "earlyFixReport-r12", "lpp.earlyFixReport_r12",
FT_UINT32, BASE_DEC, VALS(lpp_EarlyFixReport_r12_vals), 0,
NULL, HFILL }},
{ &hf_lpp_locationSource_r13,
{ "locationSource-r13", "lpp.locationSource_r13",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_locationTimestamp_r13,
{ "locationTimestamp-r13", "lpp.locationTimestamp_r13",
FT_STRING, BASE_NONE, NULL, 0,
"UTCTime", HFILL }},
{ &hf_lpp_ellipsoidPoint_01,
{ "ellipsoidPoint", "lpp.ellipsoidPoint_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ellipsoid_Point", HFILL }},
{ &hf_lpp_ellipsoidPointWithUncertaintyCircle_01,
{ "ellipsoidPointWithUncertaintyCircle", "lpp.ellipsoidPointWithUncertaintyCircle_element",
FT_NONE, BASE_NONE, NULL, 0,
"Ellipsoid_PointWithUncertaintyCircle", HFILL }},
{ &hf_lpp_ellipsoidPointWithUncertaintyEllipse_01,
{ "ellipsoidPointWithUncertaintyEllipse", "lpp.ellipsoidPointWithUncertaintyEllipse_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_polygon_01,
{ "polygon", "lpp.polygon",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ellipsoidPointWithAltitude_01,
{ "ellipsoidPointWithAltitude", "lpp.ellipsoidPointWithAltitude_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ellipsoidPointWithAltitudeAndUncertaintyEllipsoid_01,
{ "ellipsoidPointWithAltitudeAndUncertaintyEllipsoid", "lpp.ellipsoidPointWithAltitudeAndUncertaintyEllipsoid_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ellipsoidArc_01,
{ "ellipsoidArc", "lpp.ellipsoidArc_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_horizontalVelocity_01,
{ "horizontalVelocity", "lpp.horizontalVelocity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_horizontalWithVerticalVelocity_01,
{ "horizontalWithVerticalVelocity", "lpp.horizontalWithVerticalVelocity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_horizontalVelocityWithUncertainty_01,
{ "horizontalVelocityWithUncertainty", "lpp.horizontalVelocityWithUncertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_horizontalWithVerticalVelocityAndUncertainty_01,
{ "horizontalWithVerticalVelocityAndUncertainty", "lpp.horizontalWithVerticalVelocityAndUncertainty_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_locationfailurecause,
{ "locationfailurecause", "lpp.locationfailurecause",
FT_UINT32, BASE_DEC, VALS(lpp_LocationFailureCause_vals), 0,
NULL, HFILL }},
{ &hf_lpp_abortCause,
{ "abortCause", "lpp.abortCause",
FT_UINT32, BASE_DEC, VALS(lpp_T_abortCause_vals), 0,
NULL, HFILL }},
{ &hf_lpp_errorCause,
{ "errorCause", "lpp.errorCause",
FT_UINT32, BASE_DEC, VALS(lpp_T_errorCause_vals), 0,
NULL, HFILL }},
{ &hf_lpp_otdoa_ReferenceCellInfo,
{ "otdoa-ReferenceCellInfo", "lpp.otdoa_ReferenceCellInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_otdoa_NeighbourCellInfo,
{ "otdoa-NeighbourCellInfo", "lpp.otdoa_NeighbourCellInfo",
FT_UINT32, BASE_DEC, NULL, 0,
"OTDOA_NeighbourCellInfoList", HFILL }},
{ &hf_lpp_otdoa_Error,
{ "otdoa-Error", "lpp.otdoa_Error",
FT_UINT32, BASE_DEC, VALS(lpp_OTDOA_Error_vals), 0,
NULL, HFILL }},
{ &hf_lpp_physCellId,
{ "physCellId", "lpp.physCellId",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_503", HFILL }},
{ &hf_lpp_cellGlobalId,
{ "cellGlobalId", "lpp.cellGlobalId_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_lpp_earfcnRef,
{ "earfcnRef", "lpp.earfcnRef",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA", HFILL }},
{ &hf_lpp_antennaPortConfig,
{ "antennaPortConfig", "lpp.antennaPortConfig",
FT_UINT32, BASE_DEC, VALS(lpp_T_antennaPortConfig_vals), 0,
NULL, HFILL }},
{ &hf_lpp_cpLength,
{ "cpLength", "lpp.cpLength",
FT_UINT32, BASE_DEC, VALS(lpp_T_cpLength_vals), 0,
NULL, HFILL }},
{ &hf_lpp_prsInfo,
{ "prsInfo", "lpp.prsInfo_element",
FT_NONE, BASE_NONE, NULL, 0,
"PRS_Info", HFILL }},
{ &hf_lpp_earfcnRef_v9a0,
{ "earfcnRef-v9a0", "lpp.earfcnRef_v9a0",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA_v9a0", HFILL }},
{ &hf_lpp_prs_Bandwidth,
{ "prs-Bandwidth", "lpp.prs_Bandwidth",
FT_UINT32, BASE_DEC, VALS(lpp_T_prs_Bandwidth_vals), 0,
NULL, HFILL }},
{ &hf_lpp_prs_ConfigurationIndex,
{ "prs-ConfigurationIndex", "lpp.prs_ConfigurationIndex",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lpp_numDL_Frames,
{ "numDL-Frames", "lpp.numDL_Frames",
FT_UINT32, BASE_DEC, VALS(lpp_T_numDL_Frames_vals), 0,
NULL, HFILL }},
{ &hf_lpp_prs_MutingInfo_r9,
{ "prs-MutingInfo-r9", "lpp.prs_MutingInfo_r9",
FT_UINT32, BASE_DEC, VALS(lpp_T_prs_MutingInfo_r9_vals), 0,
NULL, HFILL }},
{ &hf_lpp_po2_r9,
{ "po2-r9", "lpp.po2_r9",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_lpp_po4_r9,
{ "po4-r9", "lpp.po4_r9",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_4", HFILL }},
{ &hf_lpp_po8_r9,
{ "po8-r9", "lpp.po8_r9",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_lpp_po16_r9,
{ "po16-r9", "lpp.po16_r9",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_16", HFILL }},
{ &hf_lpp_OTDOA_NeighbourCellInfoList_item,
{ "OTDOA-NeighbourFreqInfo", "lpp.OTDOA_NeighbourFreqInfo",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_OTDOA_NeighbourFreqInfo_item,
{ "OTDOA-NeighbourCellInfoElement", "lpp.OTDOA_NeighbourCellInfoElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_earfcn,
{ "earfcn", "lpp.earfcn",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA", HFILL }},
{ &hf_lpp_cpLength_01,
{ "cpLength", "lpp.cpLength",
FT_UINT32, BASE_DEC, VALS(lpp_T_cpLength_01_vals), 0,
"T_cpLength_01", HFILL }},
{ &hf_lpp_antennaPortConfig_01,
{ "antennaPortConfig", "lpp.antennaPortConfig",
FT_UINT32, BASE_DEC, VALS(lpp_T_antennaPortConfig_01_vals), 0,
"T_antennaPortConfig_01", HFILL }},
{ &hf_lpp_slotNumberOffset,
{ "slotNumberOffset", "lpp.slotNumberOffset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_19", HFILL }},
{ &hf_lpp_prs_SubframeOffset,
{ "prs-SubframeOffset", "lpp.prs_SubframeOffset",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1279", HFILL }},
{ &hf_lpp_expectedRSTD,
{ "expectedRSTD", "lpp.expectedRSTD",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_expectedRSTD_fmt), 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lpp_expectedRSTD_Uncertainty,
{ "expectedRSTD-Uncertainty", "lpp.expectedRSTD_Uncertainty",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_expectedRSTD_Uncertainty_fmt), 0,
"INTEGER_0_1023", HFILL }},
{ &hf_lpp_earfcn_v9a0,
{ "earfcn-v9a0", "lpp.earfcn_v9a0",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA_v9a0", HFILL }},
{ &hf_lpp_otdoaSignalMeasurementInformation,
{ "otdoaSignalMeasurementInformation", "lpp.otdoaSignalMeasurementInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTDOA_SignalMeasurementInformation", HFILL }},
{ &hf_lpp_systemFrameNumber,
{ "systemFrameNumber", "lpp.systemFrameNumber",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_10", HFILL }},
{ &hf_lpp_physCellIdRef,
{ "physCellIdRef", "lpp.physCellIdRef",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_503", HFILL }},
{ &hf_lpp_cellGlobalIdRef,
{ "cellGlobalIdRef", "lpp.cellGlobalIdRef_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_lpp_referenceQuality,
{ "referenceQuality", "lpp.referenceQuality_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTDOA_MeasQuality", HFILL }},
{ &hf_lpp_neighbourMeasurementList,
{ "neighbourMeasurementList", "lpp.neighbourMeasurementList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_NeighbourMeasurementList_item,
{ "NeighbourMeasurementElement", "lpp.NeighbourMeasurementElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_physCellIdNeighbour,
{ "physCellIdNeighbour", "lpp.physCellIdNeighbour",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_503", HFILL }},
{ &hf_lpp_cellGlobalIdNeighbour,
{ "cellGlobalIdNeighbour", "lpp.cellGlobalIdNeighbour_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECGI", HFILL }},
{ &hf_lpp_earfcnNeighbour,
{ "earfcnNeighbour", "lpp.earfcnNeighbour",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA", HFILL }},
{ &hf_lpp_rstd,
{ "rstd", "lpp.rstd",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_rstd_fmt), 0,
"INTEGER_0_12711", HFILL }},
{ &hf_lpp_rstd_Quality,
{ "rstd-Quality", "lpp.rstd_Quality_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTDOA_MeasQuality", HFILL }},
{ &hf_lpp_earfcnNeighbour_v9a0,
{ "earfcnNeighbour-v9a0", "lpp.earfcnNeighbour_v9a0",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA_v9a0", HFILL }},
{ &hf_lpp_error_Resolution,
{ "error-Resolution", "lpp.error_Resolution",
FT_UINT8, BASE_DEC, VALS(lpp_error_Resolution_vals), 0,
NULL, HFILL }},
{ &hf_lpp_error_Value,
{ "error-Value", "lpp.error_Value",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &lpp_error_Value_vals_ext, 0,
NULL, HFILL }},
{ &hf_lpp_error_NumSamples,
{ "error-NumSamples", "lpp.error_NumSamples",
FT_UINT8, BASE_DEC, VALS(lpp_error_NumSamples_vals), 0,
NULL, HFILL }},
{ &hf_lpp_assistanceAvailability,
{ "assistanceAvailability", "lpp.assistanceAvailability",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_otdoa_Mode,
{ "otdoa-Mode", "lpp.otdoa_Mode",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_supportedBandListEUTRA,
{ "supportedBandListEUTRA", "lpp.supportedBandListEUTRA",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA", HFILL }},
{ &hf_lpp_supportedBandListEUTRA_item,
{ "SupportedBandEUTRA", "lpp.SupportedBandEUTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_supportedBandListEUTRA_v9a0,
{ "supportedBandListEUTRA-v9a0", "lpp.supportedBandListEUTRA_v9a0",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA_v9a0", HFILL }},
{ &hf_lpp_supportedBandListEUTRA_v9a0_item,
{ "SupportedBandEUTRA-v9a0", "lpp.SupportedBandEUTRA_v9a0_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_interFreqRSTDmeasurement_r10,
{ "interFreqRSTDmeasurement-r10", "lpp.interFreqRSTDmeasurement_r10",
FT_UINT32, BASE_DEC, VALS(lpp_T_interFreqRSTDmeasurement_r10_vals), 0,
"T_interFreqRSTDmeasurement_r10", HFILL }},
{ &hf_lpp_additionalNeighbourCellInfoList_r10,
{ "additionalNeighbourCellInfoList-r10", "lpp.additionalNeighbourCellInfoList_r10",
FT_UINT32, BASE_DEC, VALS(lpp_T_additionalNeighbourCellInfoList_r10_vals), 0,
"T_additionalNeighbourCellInfoList_r10", HFILL }},
{ &hf_lpp_bandEUTRA,
{ "bandEUTRA", "lpp.bandEUTRA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_maxFBI", HFILL }},
{ &hf_lpp_bandEUTRA_v9a0,
{ "bandEUTRA-v9a0", "lpp.bandEUTRA_v9a0",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_maxFBI_Plus1_maxFBI2", HFILL }},
{ &hf_lpp_locationServerErrorCauses,
{ "locationServerErrorCauses", "lpp.locationServerErrorCauses_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTDOA_LocationServerErrorCauses", HFILL }},
{ &hf_lpp_targetDeviceErrorCauses,
{ "targetDeviceErrorCauses", "lpp.targetDeviceErrorCauses_element",
FT_NONE, BASE_NONE, NULL, 0,
"OTDOA_TargetDeviceErrorCauses", HFILL }},
{ &hf_lpp_cause,
{ "cause", "lpp.cause",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_vals), 0,
NULL, HFILL }},
{ &hf_lpp_cause_01,
{ "cause", "lpp.cause",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_01_vals), 0,
"T_cause_01", HFILL }},
{ &hf_lpp_gnss_CommonAssistData,
{ "gnss-CommonAssistData", "lpp.gnss_CommonAssistData_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_GenericAssistData,
{ "gnss-GenericAssistData", "lpp.gnss_GenericAssistData",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_Error,
{ "gnss-Error", "lpp.gnss_Error",
FT_UINT32, BASE_DEC, VALS(lpp_A_GNSS_Error_vals), 0,
"A_GNSS_Error", HFILL }},
{ &hf_lpp_gnss_ReferenceTime,
{ "gnss-ReferenceTime", "lpp.gnss_ReferenceTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_ReferenceLocation,
{ "gnss-ReferenceLocation", "lpp.gnss_ReferenceLocation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_IonosphericModel,
{ "gnss-IonosphericModel", "lpp.gnss_IonosphericModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_EarthOrientationParameters,
{ "gnss-EarthOrientationParameters", "lpp.gnss_EarthOrientationParameters_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_GenericAssistData_item,
{ "GNSS-GenericAssistDataElement", "lpp.GNSS_GenericAssistDataElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_ID,
{ "gnss-ID", "lpp.gnss_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_sbas_ID,
{ "sbas-ID", "lpp.sbas_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_TimeModels,
{ "gnss-TimeModels", "lpp.gnss_TimeModels",
FT_UINT32, BASE_DEC, NULL, 0,
"GNSS_TimeModelList", HFILL }},
{ &hf_lpp_gnss_DifferentialCorrections,
{ "gnss-DifferentialCorrections", "lpp.gnss_DifferentialCorrections_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_NavigationModel,
{ "gnss-NavigationModel", "lpp.gnss_NavigationModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_RealTimeIntegrity,
{ "gnss-RealTimeIntegrity", "lpp.gnss_RealTimeIntegrity_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_DataBitAssistance,
{ "gnss-DataBitAssistance", "lpp.gnss_DataBitAssistance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_AcquisitionAssistance,
{ "gnss-AcquisitionAssistance", "lpp.gnss_AcquisitionAssistance_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_Almanac,
{ "gnss-Almanac", "lpp.gnss_Almanac_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_UTC_Model,
{ "gnss-UTC-Model", "lpp.gnss_UTC_Model",
FT_UINT32, BASE_DEC, VALS(lpp_GNSS_UTC_Model_vals), 0,
NULL, HFILL }},
{ &hf_lpp_gnss_AuxiliaryInformation,
{ "gnss-AuxiliaryInformation", "lpp.gnss_AuxiliaryInformation",
FT_UINT32, BASE_DEC, VALS(lpp_GNSS_AuxiliaryInformation_vals), 0,
NULL, HFILL }},
{ &hf_lpp_bds_DifferentialCorrections_r12,
{ "bds-DifferentialCorrections-r12", "lpp.bds_DifferentialCorrections_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bds_GridModel_r12,
{ "bds-GridModel-r12", "lpp.bds_GridModel_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
"BDS_GridModelParameter_r12", HFILL }},
{ &hf_lpp_gnss_SystemTime,
{ "gnss-SystemTime", "lpp.gnss_SystemTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_referenceTimeUnc,
{ "referenceTimeUnc", "lpp.referenceTimeUnc",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_referenceTimeUnc_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_gnss_ReferenceTimeForCells,
{ "gnss-ReferenceTimeForCells", "lpp.gnss_ReferenceTimeForCells",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_16_OF_GNSS_ReferenceTimeForOneCell", HFILL }},
{ &hf_lpp_gnss_ReferenceTimeForCells_item,
{ "GNSS-ReferenceTimeForOneCell", "lpp.GNSS_ReferenceTimeForOneCell_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_networkTime,
{ "networkTime", "lpp.networkTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bsAlign,
{ "bsAlign", "lpp.bsAlign",
FT_UINT32, BASE_DEC, VALS(lpp_T_bsAlign_vals), 0,
NULL, HFILL }},
{ &hf_lpp_gnss_TimeID,
{ "gnss-TimeID", "lpp.gnss_TimeID_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_ID", HFILL }},
{ &hf_lpp_gnss_DayNumber,
{ "gnss-DayNumber", "lpp.gnss_DayNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_lpp_gnss_TimeOfDay,
{ "gnss-TimeOfDay", "lpp.gnss_TimeOfDay",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_86399", HFILL }},
{ &hf_lpp_gnss_TimeOfDayFrac_msec,
{ "gnss-TimeOfDayFrac-msec", "lpp.gnss_TimeOfDayFrac_msec",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_999", HFILL }},
{ &hf_lpp_notificationOfLeapSecond,
{ "notificationOfLeapSecond", "lpp.notificationOfLeapSecond",
FT_UINT8, BASE_DEC, VALS(lpp_kp_vals), 0,
NULL, HFILL }},
{ &hf_lpp_gps_TOW_Assist,
{ "gps-TOW-Assist", "lpp.gps_TOW_Assist",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GPS_TOW_Assist_item,
{ "GPS-TOW-AssistElement", "lpp.GPS_TOW_AssistElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_satelliteID,
{ "satelliteID", "lpp.satelliteID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_64", HFILL }},
{ &hf_lpp_tlmWord,
{ "tlmWord", "lpp.tlmWord",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lpp_antiSpoof,
{ "antiSpoof", "lpp.antiSpoof",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_alert,
{ "alert", "lpp.alert",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_tlmRsvdBits,
{ "tlmRsvdBits", "lpp.tlmRsvdBits",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_lpp_secondsFromFrameStructureStart,
{ "secondsFromFrameStructureStart", "lpp.secondsFromFrameStructureStart",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_12533", HFILL }},
{ &hf_lpp_fractionalSecondsFromFrameStructureStart,
{ "fractionalSecondsFromFrameStructureStart", "lpp.fractionalSecondsFromFrameStructureStart",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_fractionalSecondsFromFrameStructureStart_fmt), 0,
"INTEGER_0_3999999", HFILL }},
{ &hf_lpp_frameDrift,
{ "frameDrift", "lpp.frameDrift",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_frameDrift_fmt), 0,
"INTEGER_M64_63", HFILL }},
{ &hf_lpp_cellID,
{ "cellID", "lpp.cellID",
FT_UINT32, BASE_DEC, VALS(lpp_T_cellID_vals), 0,
NULL, HFILL }},
{ &hf_lpp_eUTRA,
{ "eUTRA", "lpp.eUTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cellGlobalIdEUTRA,
{ "cellGlobalIdEUTRA", "lpp.cellGlobalIdEUTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdEUTRA_AndUTRA", HFILL }},
{ &hf_lpp_uTRA,
{ "uTRA", "lpp.uTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_mode,
{ "mode", "lpp.mode",
FT_UINT32, BASE_DEC, VALS(lpp_T_mode_vals), 0,
NULL, HFILL }},
{ &hf_lpp_fdd,
{ "fdd", "lpp.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_primary_CPICH_Info,
{ "primary-CPICH-Info", "lpp.primary_CPICH_Info",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_511", HFILL }},
{ &hf_lpp_tdd,
{ "tdd", "lpp.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cellParameters,
{ "cellParameters", "lpp.cellParameters",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_cellGlobalIdUTRA,
{ "cellGlobalIdUTRA", "lpp.cellGlobalIdUTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdEUTRA_AndUTRA", HFILL }},
{ &hf_lpp_uarfcn,
{ "uarfcn", "lpp.uarfcn",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueUTRA", HFILL }},
{ &hf_lpp_gSM,
{ "gSM", "lpp.gSM_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bcchCarrier,
{ "bcchCarrier", "lpp.bcchCarrier",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1023", HFILL }},
{ &hf_lpp_bsic,
{ "bsic", "lpp.bsic",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lpp_cellGlobalIdGERAN,
{ "cellGlobalIdGERAN", "lpp.cellGlobalIdGERAN_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_threeDlocation,
{ "threeDlocation", "lpp.threeDlocation_element",
FT_NONE, BASE_NONE, NULL, 0,
"EllipsoidPointWithAltitudeAndUncertaintyEllipsoid", HFILL }},
{ &hf_lpp_klobucharModel,
{ "klobucharModel", "lpp.klobucharModel_element",
FT_NONE, BASE_NONE, NULL, 0,
"KlobucharModelParameter", HFILL }},
{ &hf_lpp_neQuickModel,
{ "neQuickModel", "lpp.neQuickModel_element",
FT_NONE, BASE_NONE, NULL, 0,
"NeQuickModelParameter", HFILL }},
{ &hf_lpp_dataID,
{ "dataID", "lpp.dataID",
FT_UINT8, BASE_DEC, VALS(lpp_dataID_vals), 0,
NULL, HFILL }},
{ &hf_lpp_alfa0,
{ "alfa0", "lpp.alfa0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_alpha0_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_alfa1,
{ "alfa1", "lpp.alfa1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_alpha1_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_alfa2,
{ "alfa2", "lpp.alfa2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_alpha2_3_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_alfa3,
{ "alfa3", "lpp.alfa3",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_alpha2_3_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_beta0,
{ "beta0", "lpp.beta0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_beta0_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_beta1,
{ "beta1", "lpp.beta1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_beta1_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_beta2,
{ "beta2", "lpp.beta2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_beta2_3_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_beta3,
{ "beta3", "lpp.beta3",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_beta2_3_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_ai0,
{ "ai0", "lpp.ai0",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_ai0_fmt), 0,
"INTEGER_0_2047", HFILL }},
{ &hf_lpp_ai1,
{ "ai1", "lpp.ai1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_ai1_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_ai2,
{ "ai2", "lpp.ai2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_ai2_fmt), 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_lpp_ionoStormFlag1,
{ "ionoStormFlag1", "lpp.ionoStormFlag1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_ionoStormFlag2,
{ "ionoStormFlag2", "lpp.ionoStormFlag2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_ionoStormFlag3,
{ "ionoStormFlag3", "lpp.ionoStormFlag3",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_ionoStormFlag4,
{ "ionoStormFlag4", "lpp.ionoStormFlag4",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_ionoStormFlag5,
{ "ionoStormFlag5", "lpp.ionoStormFlag5",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_teop,
{ "teop", "lpp.teop",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_teop_fmt), 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lpp_pmX,
{ "pmX", "lpp.pmX",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_pmX_Y_fmt), 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_lpp_pmXdot,
{ "pmXdot", "lpp.pmXdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_pmX_Ydot_fmt), 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_lpp_pmY,
{ "pmY", "lpp.pmY",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_pmX_Y_fmt), 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_lpp_pmYdot,
{ "pmYdot", "lpp.pmYdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_pmX_Ydot_fmt), 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_lpp_deltaUT1,
{ "deltaUT1", "lpp.deltaUT1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_deltaUT1_fmt), 0,
"INTEGER_M1073741824_1073741823", HFILL }},
{ &hf_lpp_deltaUT1dot,
{ "deltaUT1dot", "lpp.deltaUT1dot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_deltaUT1dot_fmt), 0,
"INTEGER_M262144_262143", HFILL }},
{ &hf_lpp_GNSS_TimeModelList_item,
{ "GNSS-TimeModelElement", "lpp.GNSS_TimeModelElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_TimeModelRefTime,
{ "gnss-TimeModelRefTime", "lpp.gnss_TimeModelRefTime",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_TimeModelRefTime_fmt), 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lpp_tA0,
{ "tA0", "lpp.tA0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_tA0_fmt), 0,
"INTEGER_M67108864_67108863", HFILL }},
{ &hf_lpp_tA1,
{ "tA1", "lpp.tA1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_tA1_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_tA2,
{ "tA2", "lpp.tA2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_tA2_fmt), 0,
"INTEGER_M64_63", HFILL }},
{ &hf_lpp_gnss_TO_ID,
{ "gnss-TO-ID", "lpp.gnss_TO_ID",
FT_UINT32, BASE_DEC, VALS(lpp_gnss_TO_ID_vals), 0,
"INTEGER_1_15", HFILL }},
{ &hf_lpp_weekNumber,
{ "weekNumber", "lpp.weekNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_lpp_deltaT,
{ "deltaT", "lpp.deltaT",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_dgnss_RefTime,
{ "dgnss-RefTime", "lpp.dgnss_RefTime",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_0_3599", HFILL }},
{ &hf_lpp_dgnss_SgnTypeList,
{ "dgnss-SgnTypeList", "lpp.dgnss_SgnTypeList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_DGNSS_SgnTypeList_item,
{ "DGNSS-SgnTypeElement", "lpp.DGNSS_SgnTypeElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_SignalID,
{ "gnss-SignalID", "lpp.gnss_SignalID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_StatusHealth,
{ "gnss-StatusHealth", "lpp.gnss_StatusHealth",
FT_UINT32, BASE_DEC, VALS(lpp_gnss_StatusHealth_vals), 0,
"INTEGER_0_7", HFILL }},
{ &hf_lpp_dgnss_SatList,
{ "dgnss-SatList", "lpp.dgnss_SatList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_DGNSS_SatList_item,
{ "DGNSS-CorrectionsElement", "lpp.DGNSS_CorrectionsElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_svID,
{ "svID", "lpp.svID_element",
FT_NONE, BASE_NONE, NULL, 0,
"SV_ID", HFILL }},
{ &hf_lpp_iod,
{ "iod", "lpp.iod",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_11", HFILL }},
{ &hf_lpp_udre,
{ "udre", "lpp.udre",
FT_UINT32, BASE_DEC, VALS(lpp_udre_vals), 0,
"INTEGER_0_3", HFILL }},
{ &hf_lpp_pseudoRangeCor,
{ "pseudoRangeCor", "lpp.pseudoRangeCor",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_pseudoRangeCor_fmt), 0,
"INTEGER_M2047_2047", HFILL }},
{ &hf_lpp_rangeRateCor,
{ "rangeRateCor", "lpp.rangeRateCor",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_rangeRateCor_fmt), 0,
"INTEGER_M127_127", HFILL }},
{ &hf_lpp_udreGrowthRate,
{ "udreGrowthRate", "lpp.udreGrowthRate",
FT_UINT32, BASE_DEC, VALS(lpp_udreGrowthRate_vals), 0,
"INTEGER_0_7", HFILL }},
{ &hf_lpp_udreValidityTime,
{ "udreValidityTime", "lpp.udreValidityTime",
FT_UINT32, BASE_DEC, VALS(lpp_udreValidityTime_vals), 0,
"INTEGER_0_7", HFILL }},
{ &hf_lpp_nonBroadcastIndFlag,
{ "nonBroadcastIndFlag", "lpp.nonBroadcastIndFlag",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_gnss_SatelliteList,
{ "gnss-SatelliteList", "lpp.gnss_SatelliteList",
FT_UINT32, BASE_DEC, NULL, 0,
"GNSS_NavModelSatelliteList", HFILL }},
{ &hf_lpp_GNSS_NavModelSatelliteList_item,
{ "GNSS-NavModelSatelliteElement", "lpp.GNSS_NavModelSatelliteElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_svHealth,
{ "svHealth", "lpp.svHealth",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_lpp_gnss_ClockModel,
{ "gnss-ClockModel", "lpp.gnss_ClockModel",
FT_UINT32, BASE_DEC, VALS(lpp_GNSS_ClockModel_vals), 0,
NULL, HFILL }},
{ &hf_lpp_gnss_OrbitModel,
{ "gnss-OrbitModel", "lpp.gnss_OrbitModel",
FT_UINT32, BASE_DEC, VALS(lpp_GNSS_OrbitModel_vals), 0,
NULL, HFILL }},
{ &hf_lpp_svHealthExt_v1240,
{ "svHealthExt-v1240", "lpp.svHealthExt_v1240",
FT_BYTES, BASE_NONE, NULL, 0,
"T_svHealthExt_v1240", HFILL }},
{ &hf_lpp_standardClockModelList,
{ "standardClockModelList", "lpp.standardClockModelList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_nav_ClockModel,
{ "nav-ClockModel", "lpp.nav_ClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cnav_ClockModel,
{ "cnav-ClockModel", "lpp.cnav_ClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_glonass_ClockModel,
{ "glonass-ClockModel", "lpp.glonass_ClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_sbas_ClockModel,
{ "sbas-ClockModel", "lpp.sbas_ClockModel_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bds_ClockModel_r12,
{ "bds-ClockModel-r12", "lpp.bds_ClockModel_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_keplerianSet,
{ "keplerianSet", "lpp.keplerianSet_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModelKeplerianSet", HFILL }},
{ &hf_lpp_nav_KeplerianSet,
{ "nav-KeplerianSet", "lpp.nav_KeplerianSet_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModelNAV_KeplerianSet", HFILL }},
{ &hf_lpp_cnav_KeplerianSet,
{ "cnav-KeplerianSet", "lpp.cnav_KeplerianSet_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModelCNAV_KeplerianSet", HFILL }},
{ &hf_lpp_glonass_ECEF,
{ "glonass-ECEF", "lpp.glonass_ECEF_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModel_GLONASS_ECEF", HFILL }},
{ &hf_lpp_sbas_ECEF,
{ "sbas-ECEF", "lpp.sbas_ECEF_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModel_SBAS_ECEF", HFILL }},
{ &hf_lpp_bds_KeplerianSet_r12,
{ "bds-KeplerianSet-r12", "lpp.bds_KeplerianSet_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
"NavModel_BDS_KeplerianSet_r12", HFILL }},
{ &hf_lpp_StandardClockModelList_item,
{ "StandardClockModelElement", "lpp.StandardClockModelElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_stanClockToc,
{ "stanClockToc", "lpp.stanClockToc",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_stanClockToc_fmt), 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lpp_stanClockAF2,
{ "stanClockAF2", "lpp.stanClockAF2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_stanClockAF2_fmt), 0,
"INTEGER_M32_31", HFILL }},
{ &hf_lpp_stanClockAF1,
{ "stanClockAF1", "lpp.stanClockAF1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_stanClockAF1_fmt), 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_lpp_stanClockAF0,
{ "stanClockAF0", "lpp.stanClockAF0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_stanClockAF0_fmt), 0,
"INTEGER_M1073741824_1073741823", HFILL }},
{ &hf_lpp_stanClockTgd,
{ "stanClockTgd", "lpp.stanClockTgd",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_stanClockTgd_fmt), 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_sisa,
{ "sisa", "lpp.sisa",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_sisa_fmt), 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_stanModelID,
{ "stanModelID", "lpp.stanModelID",
FT_UINT32, BASE_DEC, VALS(lpp_stanModelID_vals), 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_navToc,
{ "navToc", "lpp.navToc",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_navToc_fmt), 0,
"INTEGER_0_37799", HFILL }},
{ &hf_lpp_navaf2,
{ "navaf2", "lpp.navaf2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navaf2_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_navaf1,
{ "navaf1", "lpp.navaf1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navaf1_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navaf0,
{ "navaf0", "lpp.navaf0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navaf0_navTgd_fmt), 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_lpp_navTgd,
{ "navTgd", "lpp.navTgd",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navaf0_navTgd_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_cnavToc,
{ "cnavToc", "lpp.cnavToc",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_cnavToc_cnavTop_fmt), 0,
"INTEGER_0_2015", HFILL }},
{ &hf_lpp_cnavTop,
{ "cnavTop", "lpp.cnavTop",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_cnavToc_cnavTop_fmt), 0,
"INTEGER_0_2015", HFILL }},
{ &hf_lpp_cnavURA0,
{ "cnavURA0", "lpp.cnavURA0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_lpp_cnavURA1,
{ "cnavURA1", "lpp.cnavURA1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_lpp_cnavURA2,
{ "cnavURA2", "lpp.cnavURA2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_lpp_cnavAf2,
{ "cnavAf2", "lpp.cnavAf2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavAf2_fmt), 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_cnavAf1,
{ "cnavAf1", "lpp.cnavAf1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavAf1_fmt), 0,
"INTEGER_M524288_524287", HFILL }},
{ &hf_lpp_cnavAf0,
{ "cnavAf0", "lpp.cnavAf0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavX_fmt), 0,
"INTEGER_M33554432_33554431", HFILL }},
{ &hf_lpp_cnavTgd,
{ "cnavTgd", "lpp.cnavTgd",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavX_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_cnavISCl1cp,
{ "cnavISCl1cp", "lpp.cnavISCl1cp",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavX_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_cnavISCl1cd,
{ "cnavISCl1cd", "lpp.cnavISCl1cd",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavX_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_cnavISCl1ca,
{ "cnavISCl1ca", "lpp.cnavISCl1ca",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavX_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_cnavISCl2c,
{ "cnavISCl2c", "lpp.cnavISCl2c",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavX_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_cnavISCl5i5,
{ "cnavISCl5i5", "lpp.cnavISCl5i5",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavX_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_cnavISCl5q5,
{ "cnavISCl5q5", "lpp.cnavISCl5q5",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavX_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_gloTau,
{ "gloTau", "lpp.gloTau",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloTau_gloDeltaTau_fmt), 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_lpp_gloGamma,
{ "gloGamma", "lpp.gloGamma",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloGamma_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_gloDeltaTau,
{ "gloDeltaTau", "lpp.gloDeltaTau",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloTau_gloDeltaTau_fmt), 0,
"INTEGER_M16_15", HFILL }},
{ &hf_lpp_sbasTo,
{ "sbasTo", "lpp.sbasTo",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_sbasTo_fmt), 0,
"INTEGER_0_5399", HFILL }},
{ &hf_lpp_sbasAgfo,
{ "sbasAgfo", "lpp.sbasAgfo",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAgfo_fmt), 0,
"INTEGER_M2048_2047", HFILL }},
{ &hf_lpp_sbasAgf1,
{ "sbasAgf1", "lpp.sbasAgf1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAgf1_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_bdsAODC_r12,
{ "bdsAODC-r12", "lpp.bdsAODC_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAODC_AODE_r12_fmt), 0,
"INTEGER_0_31", HFILL }},
{ &hf_lpp_bdsToc_r12,
{ "bdsToc-r12", "lpp.bdsToc_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsToc_Toe_r12_fmt), 0,
"INTEGER_0_131071", HFILL }},
{ &hf_lpp_bdsA0_r12,
{ "bdsA0-r12", "lpp.bdsA0_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsA0_r12_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_bdsA1_r12,
{ "bdsA1-r12", "lpp.bdsA1_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsA1_r12_fmt), 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_lpp_bdsA2_r12,
{ "bdsA2-r12", "lpp.bdsA2_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsA2_r12_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_bdsTgd1_r12,
{ "bdsTgd1-r12", "lpp.bdsTgd1_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsTgd1_r12_fmt), 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_keplerToe,
{ "keplerToe", "lpp.keplerToe",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_keplerToe_fmt), 0,
"INTEGER_0_16383", HFILL }},
{ &hf_lpp_keplerW,
{ "keplerW", "lpp.keplerW",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerW_M0_I0_Omega0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_keplerDeltaN,
{ "keplerDeltaN", "lpp.keplerDeltaN",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerDeltaN_OmegaDot_IDot_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_keplerM0,
{ "keplerM0", "lpp.keplerM0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerW_M0_I0_Omega0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_keplerOmegaDot,
{ "keplerOmegaDot", "lpp.keplerOmegaDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerDeltaN_OmegaDot_IDot_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_keplerE,
{ "keplerE", "lpp.keplerE",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_keplerE_fmt), 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_lpp_keplerIDot,
{ "keplerIDot", "lpp.keplerIDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerDeltaN_OmegaDot_IDot_fmt), 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_lpp_keplerAPowerHalf,
{ "keplerAPowerHalf", "lpp.keplerAPowerHalf",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_keplerAPowerHalf_fmt), 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_lpp_keplerI0,
{ "keplerI0", "lpp.keplerI0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerW_M0_I0_Omega0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_keplerOmega0,
{ "keplerOmega0", "lpp.keplerOmega0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerW_M0_I0_Omega0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_keplerCrs,
{ "keplerCrs", "lpp.keplerCrs",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerCrs_Crc_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_keplerCis,
{ "keplerCis", "lpp.keplerCis",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_keplerCus,
{ "keplerCus", "lpp.keplerCus",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_keplerCrc,
{ "keplerCrc", "lpp.keplerCrc",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerCrs_Crc_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_keplerCic,
{ "keplerCic", "lpp.keplerCic",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_keplerCuc,
{ "keplerCuc", "lpp.keplerCuc",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_keplerCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navURA,
{ "navURA", "lpp.navURA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_lpp_navFitFlag,
{ "navFitFlag", "lpp.navFitFlag",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_navToe,
{ "navToe", "lpp.navToe",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_navToe_fmt), 0,
"INTEGER_0_37799", HFILL }},
{ &hf_lpp_navOmega,
{ "navOmega", "lpp.navOmega",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navOmega_M0_I0_OmegaA0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_navDeltaN,
{ "navDeltaN", "lpp.navDeltaN",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navDeltaN_OmegaADot_IDot_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navM0,
{ "navM0", "lpp.navM0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navOmega_M0_I0_OmegaA0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_navOmegaADot,
{ "navOmegaADot", "lpp.navOmegaADot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navDeltaN_OmegaADot_IDot_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_navE,
{ "navE", "lpp.navE",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_navE_fmt), 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_lpp_navIDot,
{ "navIDot", "lpp.navIDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navDeltaN_OmegaADot_IDot_fmt), 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_lpp_navAPowerHalf,
{ "navAPowerHalf", "lpp.navAPowerHalf",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_navAPowerHalf_fmt), 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_lpp_navI0,
{ "navI0", "lpp.navI0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navOmega_M0_I0_OmegaA0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_navOmegaA0,
{ "navOmegaA0", "lpp.navOmegaA0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navOmega_M0_I0_OmegaA0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_navCrs,
{ "navCrs", "lpp.navCrs",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navCrs_Crc_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navCis,
{ "navCis", "lpp.navCis",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navCus,
{ "navCus", "lpp.navCus",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navCrc,
{ "navCrc", "lpp.navCrc",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navCrs_Crc_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navCic,
{ "navCic", "lpp.navCic",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navCuc,
{ "navCuc", "lpp.navCuc",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_addNAVparam,
{ "addNAVparam", "lpp.addNAVparam_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ephemCodeOnL2,
{ "ephemCodeOnL2", "lpp.ephemCodeOnL2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_lpp_ephemL2Pflag,
{ "ephemL2Pflag", "lpp.ephemL2Pflag",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_ephemSF1Rsvd,
{ "ephemSF1Rsvd", "lpp.ephemSF1Rsvd_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_reserved1,
{ "reserved1", "lpp.reserved1",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_8388607", HFILL }},
{ &hf_lpp_reserved2,
{ "reserved2", "lpp.reserved2",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_lpp_reserved3,
{ "reserved3", "lpp.reserved3",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_lpp_reserved4,
{ "reserved4", "lpp.reserved4",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lpp_ephemAODA,
{ "ephemAODA", "lpp.ephemAODA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_lpp_cnavURAindex,
{ "cnavURAindex", "lpp.cnavURAindex",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M16_15", HFILL }},
{ &hf_lpp_cnavDeltaA,
{ "cnavDeltaA", "lpp.cnavDeltaA",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavDeltaA_fmt), 0,
"INTEGER_M33554432_33554431", HFILL }},
{ &hf_lpp_cnavAdot,
{ "cnavAdot", "lpp.cnavAdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavAdot_fmt), 0,
"INTEGER_M16777216_16777215", HFILL }},
{ &hf_lpp_cnavDeltaNo,
{ "cnavDeltaNo", "lpp.cnavDeltaNo",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavDeltaNo_fmt), 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_lpp_cnavDeltaNoDot,
{ "cnavDeltaNoDot", "lpp.cnavDeltaNoDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavDeltaNoDot_fmt), 0,
"INTEGER_M4194304_4194303", HFILL }},
{ &hf_lpp_cnavMo,
{ "cnavMo", "lpp.cnavMo",
FT_INT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cnavE,
{ "cnavE", "lpp.cnavE",
FT_UINT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cnavOmega,
{ "cnavOmega", "lpp.cnavOmega",
FT_INT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cnavOMEGA0,
{ "cnavOMEGA0", "lpp.cnavOMEGA0",
FT_INT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cnavDeltaOmegaDot,
{ "cnavDeltaOmegaDot", "lpp.cnavDeltaOmegaDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavDeltaOmegaDot_IoDot_fmt), 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_lpp_cnavIo,
{ "cnavIo", "lpp.cnavIo",
FT_INT64, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cnavIoDot,
{ "cnavIoDot", "lpp.cnavIoDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavDeltaOmegaDot_IoDot_fmt), 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_lpp_cnavCis,
{ "cnavCis", "lpp.cnavCis",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_cnavCic,
{ "cnavCic", "lpp.cnavCic",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavCx_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_cnavCrs,
{ "cnavCrs", "lpp.cnavCrs",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavCrs_Crc_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_cnavCrc,
{ "cnavCrc", "lpp.cnavCrc",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavCrs_Crc_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_cnavCus,
{ "cnavCus", "lpp.cnavCus",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavCx_fmt), 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_lpp_cnavCuc,
{ "cnavCuc", "lpp.cnavCuc",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_cnavCx_fmt), 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_lpp_gloEn,
{ "gloEn", "lpp.gloEn",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_day_days, 0,
"INTEGER_0_31", HFILL }},
{ &hf_lpp_gloP1,
{ "gloP1", "lpp.gloP1",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &units_minutes, 0,
NULL, HFILL }},
{ &hf_lpp_gloP2,
{ "gloP2", "lpp.gloP2",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_gloM,
{ "gloM", "lpp.gloM",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_lpp_gloX,
{ "gloX", "lpp.gloX",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloX_Y_Z_fmt), 0,
"INTEGER_M67108864_67108863", HFILL }},
{ &hf_lpp_gloXdot,
{ "gloXdot", "lpp.gloXdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloXdot_Ydot_Zdot_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_gloXdotdot,
{ "gloXdotdot", "lpp.gloXdotdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloXdotdot_Ydotdot_Zdotdot_fmt), 0,
"INTEGER_M16_15", HFILL }},
{ &hf_lpp_gloY,
{ "gloY", "lpp.gloY",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloX_Y_Z_fmt), 0,
"INTEGER_M67108864_67108863", HFILL }},
{ &hf_lpp_gloYdot,
{ "gloYdot", "lpp.gloYdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloXdot_Ydot_Zdot_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_gloYdotdot,
{ "gloYdotdot", "lpp.gloYdotdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloXdotdot_Ydotdot_Zdotdot_fmt), 0,
"INTEGER_M16_15", HFILL }},
{ &hf_lpp_gloZ,
{ "gloZ", "lpp.gloZ",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloX_Y_Z_fmt), 0,
"INTEGER_M67108864_67108863", HFILL }},
{ &hf_lpp_gloZdot,
{ "gloZdot", "lpp.gloZdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloXdot_Ydot_Zdot_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_gloZdotdot,
{ "gloZdotdot", "lpp.gloZdotdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloXdotdot_Ydotdot_Zdotdot_fmt), 0,
"INTEGER_M16_15", HFILL }},
{ &hf_lpp_sbasAccuracy,
{ "sbasAccuracy", "lpp.sbasAccuracy",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_4", HFILL }},
{ &hf_lpp_sbasXg,
{ "sbasXg", "lpp.sbasXg",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasXg_Yg_fmt), 0,
"INTEGER_M536870912_536870911", HFILL }},
{ &hf_lpp_sbasYg,
{ "sbasYg", "lpp.sbasYg",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasXg_Yg_fmt), 0,
"INTEGER_M536870912_536870911", HFILL }},
{ &hf_lpp_sbasZg,
{ "sbasZg", "lpp.sbasZg",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasZg_fmt), 0,
"INTEGER_M16777216_16777215", HFILL }},
{ &hf_lpp_sbasXgDot,
{ "sbasXgDot", "lpp.sbasXgDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasXgDot_YgDot_fmt), 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_lpp_sbasYgDot,
{ "sbasYgDot", "lpp.sbasYgDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasXgDot_YgDot_fmt), 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_lpp_sbasZgDot,
{ "sbasZgDot", "lpp.sbasZgDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasZgDot_fmt), 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_lpp_sbasXgDotDot,
{ "sbasXgDotDot", "lpp.sbasXgDotDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasXgDotDot_YgDotDot_fmt), 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_sbagYgDotDot,
{ "sbagYgDotDot", "lpp.sbagYgDotDot",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_sbasZgDotDot,
{ "sbasZgDotDot", "lpp.sbasZgDotDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasZgDotDot_fmt), 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_bdsAODE_r12,
{ "bdsAODE-r12", "lpp.bdsAODE_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAODC_AODE_r12_fmt), 0,
"INTEGER_0_31", HFILL }},
{ &hf_lpp_bdsURAI_r12,
{ "bdsURAI-r12", "lpp.bdsURAI_r12",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_meters, 0,
"INTEGER_0_15", HFILL }},
{ &hf_lpp_bdsToe_r12,
{ "bdsToe-r12", "lpp.bdsToe_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsToc_Toe_r12_fmt), 0,
"INTEGER_0_131071", HFILL }},
{ &hf_lpp_bdsAPowerHalf_r12,
{ "bdsAPowerHalf-r12", "lpp.bdsAPowerHalf_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAPowerHalf_r12_fmt), 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_lpp_bdsE_r12,
{ "bdsE-r12", "lpp.bdsE_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsE_r12_fmt), 0,
"INTEGER_0_4294967295", HFILL }},
{ &hf_lpp_bdsW_r12,
{ "bdsW-r12", "lpp.bdsW_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsW_M0_Omega0_I0_r12_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_bdsDeltaN_r12,
{ "bdsDeltaN-r12", "lpp.bdsDeltaN_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsDeltaN_OmegaDot_IDot_r12_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_bdsM0_r12,
{ "bdsM0-r12", "lpp.bdsM0_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsW_M0_Omega0_I0_r12_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_bdsOmega0_r12,
{ "bdsOmega0-r12", "lpp.bdsOmega0_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsW_M0_Omega0_I0_r12_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_bdsOmegaDot_r12,
{ "bdsOmegaDot-r12", "lpp.bdsOmegaDot_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsDeltaN_OmegaDot_IDot_r12_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_bdsI0_r12,
{ "bdsI0-r12", "lpp.bdsI0_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsW_M0_Omega0_I0_r12_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_bdsIDot_r12,
{ "bdsIDot-r12", "lpp.bdsIDot_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsDeltaN_OmegaDot_IDot_r12_fmt), 0,
"INTEGER_M8192_8191", HFILL }},
{ &hf_lpp_bdsCuc_r12,
{ "bdsCuc-r12", "lpp.bdsCuc_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsCuc_Cus_Cic_Cis_r12_fmt), 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_lpp_bdsCus_r12,
{ "bdsCus-r12", "lpp.bdsCus_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsCuc_Cus_Cic_Cis_r12_fmt), 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_lpp_bdsCrc_r12,
{ "bdsCrc-r12", "lpp.bdsCrc_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsCrc_Crs_r12_fmt), 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_lpp_bdsCrs_r12,
{ "bdsCrs-r12", "lpp.bdsCrs_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsCrc_Crs_r12_fmt), 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_lpp_bdsCic_r12,
{ "bdsCic-r12", "lpp.bdsCic_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsCuc_Cus_Cic_Cis_r12_fmt), 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_lpp_bdsCis_r12,
{ "bdsCis-r12", "lpp.bdsCis_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsCuc_Cus_Cic_Cis_r12_fmt), 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_lpp_gnss_BadSignalList,
{ "gnss-BadSignalList", "lpp.gnss_BadSignalList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_BadSignalList_item,
{ "BadSignalElement", "lpp.BadSignalElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_badSVID,
{ "badSVID", "lpp.badSVID_element",
FT_NONE, BASE_NONE, NULL, 0,
"SV_ID", HFILL }},
{ &hf_lpp_badSignalID,
{ "badSignalID", "lpp.badSignalID_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lpp_gnss_TOD,
{ "gnss-TOD", "lpp.gnss_TOD",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_0_3599", HFILL }},
{ &hf_lpp_gnss_TODfrac,
{ "gnss-TODfrac", "lpp.gnss_TODfrac",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
"INTEGER_0_999", HFILL }},
{ &hf_lpp_gnss_DataBitsSatList,
{ "gnss-DataBitsSatList", "lpp.gnss_DataBitsSatList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_DataBitsSatList_item,
{ "GNSS-DataBitsSatElement", "lpp.GNSS_DataBitsSatElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_DataBitsSgnList,
{ "gnss-DataBitsSgnList", "lpp.gnss_DataBitsSgnList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_DataBitsSgnList_item,
{ "GNSS-DataBitsSgnElement", "lpp.GNSS_DataBitsSgnElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_SignalType,
{ "gnss-SignalType", "lpp.gnss_SignalType_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalID", HFILL }},
{ &hf_lpp_gnss_DataBits,
{ "gnss-DataBits", "lpp.gnss_DataBits",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_1_1024", HFILL }},
{ &hf_lpp_gnss_AcquisitionAssistList,
{ "gnss-AcquisitionAssistList", "lpp.gnss_AcquisitionAssistList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_confidence_r10,
{ "confidence-r10", "lpp.confidence_r10",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_percent, 0,
"INTEGER_0_100", HFILL }},
{ &hf_lpp_GNSS_AcquisitionAssistList_item,
{ "GNSS-AcquisitionAssistElement", "lpp.GNSS_AcquisitionAssistElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_doppler0,
{ "doppler0", "lpp.doppler0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_doppler0_fmt), 0,
"INTEGER_M2048_2047", HFILL }},
{ &hf_lpp_doppler1,
{ "doppler1", "lpp.doppler1",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_doppler1_fmt), 0,
"INTEGER_0_63", HFILL }},
{ &hf_lpp_dopplerUncertainty,
{ "dopplerUncertainty", "lpp.dopplerUncertainty",
FT_UINT32, BASE_DEC, VALS(lpp_dopplerUncertainty_vals), 0,
"INTEGER_0_4", HFILL }},
{ &hf_lpp_codePhase,
{ "codePhase", "lpp.codePhase",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_codePhase_fmt), 0,
"INTEGER_0_1022", HFILL }},
{ &hf_lpp_intCodePhase,
{ "intCodePhase", "lpp.intCodePhase",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_codePhaseSearchWindow,
{ "codePhaseSearchWindow", "lpp.codePhaseSearchWindow",
FT_UINT32, BASE_DEC|BASE_EXT_STRING, &lpp_codePhaseSearchWindow_vals_ext, 0,
"INTEGER_0_31", HFILL }},
{ &hf_lpp_azimuth,
{ "azimuth", "lpp.azimuth",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_azimuth_elevation_fmt), 0,
"INTEGER_0_511", HFILL }},
{ &hf_lpp_elevation,
{ "elevation", "lpp.elevation",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_azimuth_elevation_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_codePhase1023,
{ "codePhase1023", "lpp.codePhase1023",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_dopplerUncertaintyExt_r10,
{ "dopplerUncertaintyExt-r10", "lpp.dopplerUncertaintyExt_r10",
FT_UINT32, BASE_DEC, VALS(lpp_T_dopplerUncertaintyExt_r10_vals), 0,
"T_dopplerUncertaintyExt_r10", HFILL }},
{ &hf_lpp_weekNumber_01,
{ "weekNumber", "lpp.weekNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_toa,
{ "toa", "lpp.toa",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ioda,
{ "ioda", "lpp.ioda",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_lpp_completeAlmanacProvided,
{ "completeAlmanacProvided", "lpp.completeAlmanacProvided",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_gnss_AlmanacList,
{ "gnss-AlmanacList", "lpp.gnss_AlmanacList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_toa_ext_v1240,
{ "toa-ext-v1240", "lpp.toa_ext_v1240",
FT_UINT32, BASE_DEC, NULL, 0,
"T_toa_ext_v1240", HFILL }},
{ &hf_lpp_ioda_ext_v1240,
{ "ioda-ext-v1240", "lpp.ioda_ext_v1240",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_4_15", HFILL }},
{ &hf_lpp_GNSS_AlmanacList_item,
{ "GNSS-AlmanacElement", "lpp.GNSS_AlmanacElement",
FT_UINT32, BASE_DEC, VALS(lpp_GNSS_AlmanacElement_vals), 0,
NULL, HFILL }},
{ &hf_lpp_keplerianAlmanacSet,
{ "keplerianAlmanacSet", "lpp.keplerianAlmanacSet_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlmanacKeplerianSet", HFILL }},
{ &hf_lpp_keplerianNAV_Almanac,
{ "keplerianNAV-Almanac", "lpp.keplerianNAV_Almanac_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlmanacNAV_KeplerianSet", HFILL }},
{ &hf_lpp_keplerianReducedAlmanac,
{ "keplerianReducedAlmanac", "lpp.keplerianReducedAlmanac_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlmanacReducedKeplerianSet", HFILL }},
{ &hf_lpp_keplerianMidiAlmanac,
{ "keplerianMidiAlmanac", "lpp.keplerianMidiAlmanac_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlmanacMidiAlmanacSet", HFILL }},
{ &hf_lpp_keplerianGLONASS,
{ "keplerianGLONASS", "lpp.keplerianGLONASS_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlmanacGLONASS_AlmanacSet", HFILL }},
{ &hf_lpp_ecef_SBAS_Almanac,
{ "ecef-SBAS-Almanac", "lpp.ecef_SBAS_Almanac_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlmanacECEF_SBAS_AlmanacSet", HFILL }},
{ &hf_lpp_keplerianBDS_Almanac_r12,
{ "keplerianBDS-Almanac-r12", "lpp.keplerianBDS_Almanac_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
"AlmanacBDS_AlmanacSet_r12", HFILL }},
{ &hf_lpp_kepAlmanacE,
{ "kepAlmanacE", "lpp.kepAlmanacE",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacE_fmt), 0,
"INTEGER_0_2047", HFILL }},
{ &hf_lpp_kepAlmanacDeltaI,
{ "kepAlmanacDeltaI", "lpp.kepAlmanacDeltaI",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacDeltaI_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_kepAlmanacOmegaDot,
{ "kepAlmanacOmegaDot", "lpp.kepAlmanacOmegaDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacOmegaDot_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_kepSV_StatusINAV,
{ "kepSV-StatusINAV", "lpp.kepSV_StatusINAV",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_kepSV_StatusFNAV,
{ "kepSV-StatusFNAV", "lpp.kepSV_StatusFNAV",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_kepAlmanacAPowerHalf,
{ "kepAlmanacAPowerHalf", "lpp.kepAlmanacAPowerHalf",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacAPowerHalf_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_kepAlmanacOmega0,
{ "kepAlmanacOmega0", "lpp.kepAlmanacOmega0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacOmega0_W_M0_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_kepAlmanacW,
{ "kepAlmanacW", "lpp.kepAlmanacW",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacOmega0_W_M0_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_kepAlmanacM0,
{ "kepAlmanacM0", "lpp.kepAlmanacM0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacOmega0_W_M0_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_kepAlmanacAF0,
{ "kepAlmanacAF0", "lpp.kepAlmanacAF0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacAF0_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_kepAlmanacAF1,
{ "kepAlmanacAF1", "lpp.kepAlmanacAF1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_kepAlmanacAF1_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_navAlmE,
{ "navAlmE", "lpp.navAlmE",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmE_fmt), 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lpp_navAlmDeltaI,
{ "navAlmDeltaI", "lpp.navAlmDeltaI",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmDeltaI_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navAlmOMEGADOT,
{ "navAlmOMEGADOT", "lpp.navAlmOMEGADOT",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmOMEGADOT_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_navAlmSVHealth,
{ "navAlmSVHealth", "lpp.navAlmSVHealth",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_navAlmSqrtA,
{ "navAlmSqrtA", "lpp.navAlmSqrtA",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmSqrtA_fmt), 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_lpp_navAlmOMEGAo,
{ "navAlmOMEGAo", "lpp.navAlmOMEGAo",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmOMEGAo_Omega_Mo_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_navAlmOmega,
{ "navAlmOmega", "lpp.navAlmOmega",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmOMEGAo_Omega_Mo_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_navAlmMo,
{ "navAlmMo", "lpp.navAlmMo",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmOMEGAo_Omega_Mo_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_navAlmaf0,
{ "navAlmaf0", "lpp.navAlmaf0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmaf0_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_navAlmaf1,
{ "navAlmaf1", "lpp.navAlmaf1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_navAlmaf1_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_redAlmDeltaA,
{ "redAlmDeltaA", "lpp.redAlmDeltaA",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_redAlmDeltaA_fmt), 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_redAlmOmega0,
{ "redAlmOmega0", "lpp.redAlmOmega0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_redAlmOmega0_Phi0_fmt), 0,
"INTEGER_M64_63", HFILL }},
{ &hf_lpp_redAlmPhi0,
{ "redAlmPhi0", "lpp.redAlmPhi0",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M64_63", HFILL }},
{ &hf_lpp_redAlmL1Health,
{ "redAlmL1Health", "lpp.redAlmL1Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_redAlmL2Health,
{ "redAlmL2Health", "lpp.redAlmL2Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_redAlmL5Health,
{ "redAlmL5Health", "lpp.redAlmL5Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_midiAlmE,
{ "midiAlmE", "lpp.midiAlmE",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmE_fmt), 0,
"INTEGER_0_2047", HFILL }},
{ &hf_lpp_midiAlmDeltaI,
{ "midiAlmDeltaI", "lpp.midiAlmDeltaI",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmDeltaI_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_midiAlmOmegaDot,
{ "midiAlmOmegaDot", "lpp.midiAlmOmegaDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmOmegaDot_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_midiAlmSqrtA,
{ "midiAlmSqrtA", "lpp.midiAlmSqrtA",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmSqrtA_fmt), 0,
"INTEGER_0_131071", HFILL }},
{ &hf_lpp_midiAlmOmega0,
{ "midiAlmOmega0", "lpp.midiAlmOmega0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmOmega0_Omega_Mo_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_midiAlmOmega,
{ "midiAlmOmega", "lpp.midiAlmOmega",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmOmega0_Omega_Mo_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_midiAlmMo,
{ "midiAlmMo", "lpp.midiAlmMo",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmOmega0_Omega_Mo_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_midiAlmaf0,
{ "midiAlmaf0", "lpp.midiAlmaf0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmaf0_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_midiAlmaf1,
{ "midiAlmaf1", "lpp.midiAlmaf1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_midiAlmaf1_fmt), 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_midiAlmL1Health,
{ "midiAlmL1Health", "lpp.midiAlmL1Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_midiAlmL2Health,
{ "midiAlmL2Health", "lpp.midiAlmL2Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_midiAlmL5Health,
{ "midiAlmL5Health", "lpp.midiAlmL5Health",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_gloAlm_NA,
{ "gloAlm-NA", "lpp.gloAlm_NA",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_day_days, 0,
"INTEGER_1_1461", HFILL }},
{ &hf_lpp_gloAlmnA,
{ "gloAlmnA", "lpp.gloAlmnA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_24", HFILL }},
{ &hf_lpp_gloAlmHA,
{ "gloAlmHA", "lpp.gloAlmHA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_31", HFILL }},
{ &hf_lpp_gloAlmLambdaA,
{ "gloAlmLambdaA", "lpp.gloAlmLambdaA",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloAlmLambdaA_DeltaIa_fmt), 0,
"INTEGER_M1048576_1048575", HFILL }},
{ &hf_lpp_gloAlmtlambdaA,
{ "gloAlmtlambdaA", "lpp.gloAlmtlambdaA",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_gloAlmtlambdaA_fmt), 0,
"INTEGER_0_2097151", HFILL }},
{ &hf_lpp_gloAlmDeltaIa,
{ "gloAlmDeltaIa", "lpp.gloAlmDeltaIa",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloAlmLambdaA_DeltaIa_fmt), 0,
"INTEGER_M131072_131071", HFILL }},
{ &hf_lpp_gloAlmDeltaTA,
{ "gloAlmDeltaTA", "lpp.gloAlmDeltaTA",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloAlmDeltaTA_fmt), 0,
"INTEGER_M2097152_2097151", HFILL }},
{ &hf_lpp_gloAlmDeltaTdotA,
{ "gloAlmDeltaTdotA", "lpp.gloAlmDeltaTdotA",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloAlmDeltaTdotA_fmt), 0,
"INTEGER_M64_63", HFILL }},
{ &hf_lpp_gloAlmEpsilonA,
{ "gloAlmEpsilonA", "lpp.gloAlmEpsilonA",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_gloAlmEpsilonA_fmt), 0,
"INTEGER_0_32767", HFILL }},
{ &hf_lpp_gloAlmOmegaA,
{ "gloAlmOmegaA", "lpp.gloAlmOmegaA",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloAlmOmegaA_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_gloAlmTauA,
{ "gloAlmTauA", "lpp.gloAlmTauA",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gloAlmTauA_fmt), 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_gloAlmCA,
{ "gloAlmCA", "lpp.gloAlmCA",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_1", HFILL }},
{ &hf_lpp_gloAlmMA,
{ "gloAlmMA", "lpp.gloAlmMA",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_lpp_sbasAlmDataID,
{ "sbasAlmDataID", "lpp.sbasAlmDataID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_lpp_sbasAlmHealth,
{ "sbasAlmHealth", "lpp.sbasAlmHealth",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_lpp_sbasAlmXg,
{ "sbasAlmXg", "lpp.sbasAlmXg",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAlmXg_Yg_fmt), 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_lpp_sbasAlmYg,
{ "sbasAlmYg", "lpp.sbasAlmYg",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAlmXg_Yg_fmt), 0,
"INTEGER_M16384_16383", HFILL }},
{ &hf_lpp_sbasAlmZg,
{ "sbasAlmZg", "lpp.sbasAlmZg",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAlmZg_fmt), 0,
"INTEGER_M256_255", HFILL }},
{ &hf_lpp_sbasAlmXgdot,
{ "sbasAlmXgdot", "lpp.sbasAlmXgdot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAlmXgdot_YgDot_fmt), 0,
"INTEGER_M4_3", HFILL }},
{ &hf_lpp_sbasAlmYgDot,
{ "sbasAlmYgDot", "lpp.sbasAlmYgDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAlmXgdot_YgDot_fmt), 0,
"INTEGER_M4_3", HFILL }},
{ &hf_lpp_sbasAlmZgDot,
{ "sbasAlmZgDot", "lpp.sbasAlmZgDot",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAlmZgDot_fmt), 0,
"INTEGER_M8_7", HFILL }},
{ &hf_lpp_sbasAlmTo,
{ "sbasAlmTo", "lpp.sbasAlmTo",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_sbasAlmTo_fmt), 0,
"INTEGER_0_2047", HFILL }},
{ &hf_lpp_bdsAlmToa_r12,
{ "bdsAlmToa-r12", "lpp.bdsAlmToa_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmToa_r12_fmt), 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_bdsAlmSqrtA_r12,
{ "bdsAlmSqrtA-r12", "lpp.bdsAlmSqrtA_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmSqrtA_r12_fmt), 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_lpp_bdsAlmE_r12,
{ "bdsAlmE-r12", "lpp.bdsAlmE_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmE_r12_fmt), 0,
"INTEGER_0_131071", HFILL }},
{ &hf_lpp_bdsAlmW_r12,
{ "bdsAlmW-r12", "lpp.bdsAlmW_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmW_M0_Omega0_r12_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_bdsAlmM0_r12,
{ "bdsAlmM0-r12", "lpp.bdsAlmM0_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmW_M0_Omega0_r12_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_bdsAlmOmega0_r12,
{ "bdsAlmOmega0-r12", "lpp.bdsAlmOmega0_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmW_M0_Omega0_r12_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_bdsAlmOmegaDot_r12,
{ "bdsAlmOmegaDot-r12", "lpp.bdsAlmOmegaDot_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmOmegaDot_r12_fmt), 0,
"INTEGER_M65536_65535", HFILL }},
{ &hf_lpp_bdsAlmDeltaI_r12,
{ "bdsAlmDeltaI-r12", "lpp.bdsAlmDeltaI_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmDeltaI_r12_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_bdsAlmA0_r12,
{ "bdsAlmA0-r12", "lpp.bdsAlmA0_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmA0_r12_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_bdsAlmA1_r12,
{ "bdsAlmA1-r12", "lpp.bdsAlmA1_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bdsAlmA1_r12_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_bdsSvHealth_r12,
{ "bdsSvHealth-r12", "lpp.bdsSvHealth_r12",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_utcModel1,
{ "utcModel1", "lpp.utcModel1_element",
FT_NONE, BASE_NONE, NULL, 0,
"UTC_ModelSet1", HFILL }},
{ &hf_lpp_utcModel2,
{ "utcModel2", "lpp.utcModel2_element",
FT_NONE, BASE_NONE, NULL, 0,
"UTC_ModelSet2", HFILL }},
{ &hf_lpp_utcModel3,
{ "utcModel3", "lpp.utcModel3_element",
FT_NONE, BASE_NONE, NULL, 0,
"UTC_ModelSet3", HFILL }},
{ &hf_lpp_utcModel4,
{ "utcModel4", "lpp.utcModel4_element",
FT_NONE, BASE_NONE, NULL, 0,
"UTC_ModelSet4", HFILL }},
{ &hf_lpp_utcModel5_r12,
{ "utcModel5-r12", "lpp.utcModel5_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
"UTC_ModelSet5_r12", HFILL }},
{ &hf_lpp_gnss_Utc_A1,
{ "gnss-Utc-A1", "lpp.gnss_Utc_A1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_Utc_A1_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_gnss_Utc_A0,
{ "gnss-Utc-A0", "lpp.gnss_Utc_A0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_Utc_A0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_gnss_Utc_Tot,
{ "gnss-Utc-Tot", "lpp.gnss_Utc_Tot",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_Utc_Tot_fmt), 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_gnss_Utc_WNt,
{ "gnss-Utc-WNt", "lpp.gnss_Utc_WNt",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_week_weeks, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_gnss_Utc_DeltaTls,
{ "gnss-Utc-DeltaTls", "lpp.gnss_Utc_DeltaTls",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_gnss_Utc_WNlsf,
{ "gnss-Utc-WNlsf", "lpp.gnss_Utc_WNlsf",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_week_weeks, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_gnss_Utc_DN,
{ "gnss-Utc-DN", "lpp.gnss_Utc_DN",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_day_days, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_gnss_Utc_DeltaTlsf,
{ "gnss-Utc-DeltaTlsf", "lpp.gnss_Utc_DeltaTlsf",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_utcA0,
{ "utcA0", "lpp.utcA0",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_tA0_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_utcA1,
{ "utcA1", "lpp.utcA1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_tA1_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_utcA2,
{ "utcA2", "lpp.utcA2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_tA2_fmt), 0,
"INTEGER_M64_63", HFILL }},
{ &hf_lpp_utcDeltaTls,
{ "utcDeltaTls", "lpp.utcDeltaTls",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_utcTot,
{ "utcTot", "lpp.utcTot",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_TimeModelRefTime_fmt), 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lpp_utcWNot,
{ "utcWNot", "lpp.utcWNot",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_week_weeks, 0,
"INTEGER_0_8191", HFILL }},
{ &hf_lpp_utcWNlsf,
{ "utcWNlsf", "lpp.utcWNlsf",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_week_weeks, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_utcDN,
{ "utcDN", "lpp.utcDN",
FT_UINT8, BASE_DEC|BASE_UNIT_STRING, &units_day_days, 0,
NULL, HFILL }},
{ &hf_lpp_utcDeltaTlsf,
{ "utcDeltaTlsf", "lpp.utcDeltaTlsf",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_nA,
{ "nA", "lpp.nA",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_day_days, 0,
"INTEGER_1_1461", HFILL }},
{ &hf_lpp_tauC,
{ "tauC", "lpp.tauC",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_tauC_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_b1,
{ "b1", "lpp.b1",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_b1_fmt), 0,
"INTEGER_M1024_1023", HFILL }},
{ &hf_lpp_b2,
{ "b2", "lpp.b2",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_b2_fmt), 0,
"INTEGER_M512_511", HFILL }},
{ &hf_lpp_kp,
{ "kp", "lpp.kp",
FT_UINT8, BASE_DEC, VALS(lpp_kp_vals), 0,
NULL, HFILL }},
{ &hf_lpp_utcA1wnt,
{ "utcA1wnt", "lpp.utcA1wnt",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_Utc_A1_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_utcA0wnt,
{ "utcA0wnt", "lpp.utcA0wnt",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_Utc_A0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_utcTot_01,
{ "utcTot", "lpp.utcTot",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_Utc_Tot_fmt), 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_utcWNt,
{ "utcWNt", "lpp.utcWNt",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_week_weeks, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_utcDN_01,
{ "utcDN", "lpp.utcDN",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_day_days, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_utcStandardID,
{ "utcStandardID", "lpp.utcStandardID",
FT_UINT8, BASE_DEC, VALS(lpp_utcStandardID_vals), 0,
"INTEGER_0_7", HFILL }},
{ &hf_lpp_utcA0_r12,
{ "utcA0-r12", "lpp.utcA0_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_Utc_A0_fmt), 0,
"INTEGER_M2147483648_2147483647", HFILL }},
{ &hf_lpp_utcA1_r12,
{ "utcA1-r12", "lpp.utcA1_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_gnss_Utc_A1_fmt), 0,
"INTEGER_M8388608_8388607", HFILL }},
{ &hf_lpp_utcDeltaTls_r12,
{ "utcDeltaTls-r12", "lpp.utcDeltaTls_r12",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_utcWNlsf_r12,
{ "utcWNlsf-r12", "lpp.utcWNlsf_r12",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_week_weeks, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_utcDN_r12,
{ "utcDN-r12", "lpp.utcDN_r12",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_day_days, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_utcDeltaTlsf_r12,
{ "utcDeltaTlsf-r12", "lpp.utcDeltaTlsf_r12",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_gnss_ID_GPS,
{ "gnss-ID-GPS", "lpp.gnss_ID_GPS",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_ID_GLONASS,
{ "gnss-ID-GLONASS", "lpp.gnss_ID_GLONASS",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_ID_GPS_item,
{ "GNSS-ID-GPS-SatElement", "lpp.GNSS_ID_GPS_SatElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_signalsAvailable,
{ "signalsAvailable", "lpp.signalsAvailable_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lpp_GNSS_ID_GLONASS_item,
{ "GNSS-ID-GLONASS-SatElement", "lpp.GNSS_ID_GLONASS_SatElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_channelNumber,
{ "channelNumber", "lpp.channelNumber",
FT_INT32, BASE_DEC, NULL, 0,
"INTEGER_M7_13", HFILL }},
{ &hf_lpp_dbds_RefTime_r12,
{ "dbds-RefTime-r12", "lpp.dbds_RefTime_r12",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_0_3599", HFILL }},
{ &hf_lpp_bds_SgnTypeList_r12,
{ "bds-SgnTypeList-r12", "lpp.bds_SgnTypeList_r12",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_BDS_SgnTypeList_r12_item,
{ "BDS-SgnTypeElement-r12", "lpp.BDS_SgnTypeElement_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_dbds_CorrectionList_r12,
{ "dbds-CorrectionList-r12", "lpp.dbds_CorrectionList_r12",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_DBDS_CorrectionList_r12_item,
{ "DBDS-CorrectionElement-r12", "lpp.DBDS_CorrectionElement_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bds_UDREI_r12,
{ "bds-UDREI-r12", "lpp.bds_UDREI_r12",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &lpp_bds_UDREI_vals_ext, 0,
"INTEGER_0_15", HFILL }},
{ &hf_lpp_bds_RURAI_r12,
{ "bds-RURAI-r12", "lpp.bds_RURAI_r12",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &lpp_bds_RURAI_vals_ext, 0,
"INTEGER_0_15", HFILL }},
{ &hf_lpp_bds_ECC_DeltaT_r12,
{ "bds-ECC-DeltaT-r12", "lpp.bds_ECC_DeltaT_r12",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_bds_ECC_DeltaT_r12_fmt), 0,
"INTEGER_M4096_4095", HFILL }},
{ &hf_lpp_bds_RefTime_r12,
{ "bds-RefTime-r12", "lpp.bds_RefTime_r12",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_0_3599", HFILL }},
{ &hf_lpp_gridIonList_r12,
{ "gridIonList-r12", "lpp.gridIonList_r12",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GridIonList_r12_item,
{ "GridIonElement-r12", "lpp.GridIonElement_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_igp_ID_r12,
{ "igp-ID-r12", "lpp.igp_ID_r12",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_320", HFILL }},
{ &hf_lpp_dt_r12,
{ "dt-r12", "lpp.dt_r12",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_bds_GridIonElement_dt_r12_fmt), 0,
"INTEGER_0_511", HFILL }},
{ &hf_lpp_givei_r12,
{ "givei-r12", "lpp.givei_r12",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &lpp_bds_givei_vals_ext, 0,
"INTEGER_0_15", HFILL }},
{ &hf_lpp_gnss_CommonAssistDataReq,
{ "gnss-CommonAssistDataReq", "lpp.gnss_CommonAssistDataReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_GenericAssistDataReq,
{ "gnss-GenericAssistDataReq", "lpp.gnss_GenericAssistDataReq",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_ReferenceTimeReq,
{ "gnss-ReferenceTimeReq", "lpp.gnss_ReferenceTimeReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_ReferenceLocationReq,
{ "gnss-ReferenceLocationReq", "lpp.gnss_ReferenceLocationReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_IonosphericModelReq,
{ "gnss-IonosphericModelReq", "lpp.gnss_IonosphericModelReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_EarthOrientationParametersReq,
{ "gnss-EarthOrientationParametersReq", "lpp.gnss_EarthOrientationParametersReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_GenericAssistDataReq_item,
{ "GNSS-GenericAssistDataReqElement", "lpp.GNSS_GenericAssistDataReqElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_TimeModelsReq,
{ "gnss-TimeModelsReq", "lpp.gnss_TimeModelsReq",
FT_UINT32, BASE_DEC, NULL, 0,
"GNSS_TimeModelListReq", HFILL }},
{ &hf_lpp_gnss_DifferentialCorrectionsReq,
{ "gnss-DifferentialCorrectionsReq", "lpp.gnss_DifferentialCorrectionsReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_NavigationModelReq,
{ "gnss-NavigationModelReq", "lpp.gnss_NavigationModelReq",
FT_UINT32, BASE_DEC, VALS(lpp_GNSS_NavigationModelReq_vals), 0,
NULL, HFILL }},
{ &hf_lpp_gnss_RealTimeIntegrityReq,
{ "gnss-RealTimeIntegrityReq", "lpp.gnss_RealTimeIntegrityReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_DataBitAssistanceReq,
{ "gnss-DataBitAssistanceReq", "lpp.gnss_DataBitAssistanceReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_AcquisitionAssistanceReq,
{ "gnss-AcquisitionAssistanceReq", "lpp.gnss_AcquisitionAssistanceReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_AlmanacReq,
{ "gnss-AlmanacReq", "lpp.gnss_AlmanacReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_UTCModelReq,
{ "gnss-UTCModelReq", "lpp.gnss_UTCModelReq_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_UTC_ModelReq", HFILL }},
{ &hf_lpp_gnss_AuxiliaryInformationReq,
{ "gnss-AuxiliaryInformationReq", "lpp.gnss_AuxiliaryInformationReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bds_DifferentialCorrectionsReq_r12,
{ "bds-DifferentialCorrectionsReq-r12", "lpp.bds_DifferentialCorrectionsReq_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bds_GridModelReq_r12,
{ "bds-GridModelReq-r12", "lpp.bds_GridModelReq_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_TimeReqPrefList,
{ "gnss-TimeReqPrefList", "lpp.gnss_TimeReqPrefList",
FT_UINT32, BASE_DEC, NULL, 0,
"SEQUENCE_SIZE_1_8_OF_GNSS_ID", HFILL }},
{ &hf_lpp_gnss_TimeReqPrefList_item,
{ "GNSS-ID", "lpp.GNSS_ID_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gps_TOW_assistReq,
{ "gps-TOW-assistReq", "lpp.gps_TOW_assistReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_notOfLeapSecReq,
{ "notOfLeapSecReq", "lpp.notOfLeapSecReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_klobucharModelReq,
{ "klobucharModelReq", "lpp.klobucharModelReq",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_2", HFILL }},
{ &hf_lpp_neQuickModelReq,
{ "neQuickModelReq", "lpp.neQuickModelReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_TimeModelListReq_item,
{ "GNSS-TimeModelElementReq", "lpp.GNSS_TimeModelElementReq_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_TO_IDsReq,
{ "gnss-TO-IDsReq", "lpp.gnss_TO_IDsReq",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_15", HFILL }},
{ &hf_lpp_deltaTreq,
{ "deltaTreq", "lpp.deltaTreq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_dgnss_SignalsReq,
{ "dgnss-SignalsReq", "lpp.dgnss_SignalsReq_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lpp_dgnss_ValidityTimeReq,
{ "dgnss-ValidityTimeReq", "lpp.dgnss_ValidityTimeReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_storedNavList,
{ "storedNavList", "lpp.storedNavList_element",
FT_NONE, BASE_NONE, NULL, 0,
"StoredNavListInfo", HFILL }},
{ &hf_lpp_reqNavList,
{ "reqNavList", "lpp.reqNavList_element",
FT_NONE, BASE_NONE, NULL, 0,
"ReqNavListInfo", HFILL }},
{ &hf_lpp_gnss_WeekOrDay,
{ "gnss-WeekOrDay", "lpp.gnss_WeekOrDay",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_Toe,
{ "gnss-Toe", "lpp.gnss_Toe",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_t_toeLimit,
{ "t-toeLimit", "lpp.t_toeLimit",
FT_UINT32, BASE_DEC, NULL, 0,
"T_t_toeLimit", HFILL }},
{ &hf_lpp_satListRelatedDataList,
{ "satListRelatedDataList", "lpp.satListRelatedDataList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_SatListRelatedDataList_item,
{ "SatListRelatedDataElement", "lpp.SatListRelatedDataElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_clockModelID,
{ "clockModelID", "lpp.clockModelID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_lpp_orbitModelID,
{ "orbitModelID", "lpp.orbitModelID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_lpp_svReqList,
{ "svReqList", "lpp.svReqList",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_64", HFILL }},
{ &hf_lpp_clockModelID_PrefList,
{ "clockModelID-PrefList", "lpp.clockModelID_PrefList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_clockModelID_PrefList_item,
{ "clockModelID-PrefList item", "lpp.clockModelID_PrefList_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_lpp_orbitModelID_PrefList,
{ "orbitModelID-PrefList", "lpp.orbitModelID_PrefList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_orbitModelID_PrefList_item,
{ "orbitModelID-PrefList item", "lpp.orbitModelID_PrefList_item",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_lpp_addNavparamReq,
{ "addNavparamReq", "lpp.addNavparamReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_gnss_TOD_Req,
{ "gnss-TOD-Req", "lpp.gnss_TOD_Req",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_seconds, 0,
"INTEGER_0_3599", HFILL }},
{ &hf_lpp_gnss_TOD_FracReq,
{ "gnss-TOD-FracReq", "lpp.gnss_TOD_FracReq",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
"INTEGER_0_999", HFILL }},
{ &hf_lpp_dataBitInterval,
{ "dataBitInterval", "lpp.dataBitInterval",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &lpp_dataBitInterval_vals_ext, 0,
"INTEGER_0_15", HFILL }},
{ &hf_lpp_gnss_SignalType_01,
{ "gnss-SignalType", "lpp.gnss_SignalType_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lpp_gnss_DataBitsReq,
{ "gnss-DataBitsReq", "lpp.gnss_DataBitsReq",
FT_UINT32, BASE_DEC, NULL, 0,
"GNSS_DataBitsReqSatList", HFILL }},
{ &hf_lpp_GNSS_DataBitsReqSatList_item,
{ "GNSS-DataBitsReqSatElement", "lpp.GNSS_DataBitsReqSatElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_SignalID_Req,
{ "gnss-SignalID-Req", "lpp.gnss_SignalID_Req_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalID", HFILL }},
{ &hf_lpp_modelID,
{ "modelID", "lpp.modelID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_1_8", HFILL }},
{ &hf_lpp_gnss_SignalMeasurementInformation,
{ "gnss-SignalMeasurementInformation", "lpp.gnss_SignalMeasurementInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_LocationInformation,
{ "gnss-LocationInformation", "lpp.gnss_LocationInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_measurementReferenceTime,
{ "measurementReferenceTime", "lpp.measurementReferenceTime_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_MeasurementList,
{ "gnss-MeasurementList", "lpp.gnss_MeasurementList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_TOD_msec,
{ "gnss-TOD-msec", "lpp.gnss_TOD_msec",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
"INTEGER_0_3599999", HFILL }},
{ &hf_lpp_gnss_TOD_frac,
{ "gnss-TOD-frac", "lpp.gnss_TOD_frac",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_fractionalSecondsFromFrameStructureStart_fmt), 0,
"INTEGER_0_3999", HFILL }},
{ &hf_lpp_gnss_TOD_unc,
{ "gnss-TOD-unc", "lpp.gnss_TOD_unc",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_referenceTimeUnc_fmt), 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_networkTime_01,
{ "networkTime", "lpp.networkTime",
FT_UINT32, BASE_DEC, VALS(lpp_T_networkTime_vals), 0,
NULL, HFILL }},
{ &hf_lpp_eUTRA_01,
{ "eUTRA", "lpp.eUTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_eUTRA_01", HFILL }},
{ &hf_lpp_cellGlobalId_01,
{ "cellGlobalId", "lpp.cellGlobalId_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdEUTRA_AndUTRA", HFILL }},
{ &hf_lpp_uTRA_01,
{ "uTRA", "lpp.uTRA_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_uTRA_01", HFILL }},
{ &hf_lpp_mode_01,
{ "mode", "lpp.mode",
FT_UINT32, BASE_DEC, VALS(lpp_T_mode_01_vals), 0,
"T_mode_01", HFILL }},
{ &hf_lpp_fdd_01,
{ "fdd", "lpp.fdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_fdd_01", HFILL }},
{ &hf_lpp_tdd_01,
{ "tdd", "lpp.tdd_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_tdd_01", HFILL }},
{ &hf_lpp_referenceSystemFrameNumber,
{ "referenceSystemFrameNumber", "lpp.referenceSystemFrameNumber",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lpp_gSM_01,
{ "gSM", "lpp.gSM_element",
FT_NONE, BASE_NONE, NULL, 0,
"T_gSM_01", HFILL }},
{ &hf_lpp_cellGlobalId_02,
{ "cellGlobalId", "lpp.cellGlobalId_element",
FT_NONE, BASE_NONE, NULL, 0,
"CellGlobalIdGERAN", HFILL }},
{ &hf_lpp_referenceFrame,
{ "referenceFrame", "lpp.referenceFrame_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_referenceFN,
{ "referenceFN", "lpp.referenceFN",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_65535", HFILL }},
{ &hf_lpp_referenceFNMSB,
{ "referenceFNMSB", "lpp.referenceFNMSB",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lpp_deltaGNSS_TOD,
{ "deltaGNSS-TOD", "lpp.deltaGNSS_TOD",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_GNSS_MeasurementList_item,
{ "GNSS-MeasurementForOneGNSS", "lpp.GNSS_MeasurementForOneGNSS_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_SgnMeasList,
{ "gnss-SgnMeasList", "lpp.gnss_SgnMeasList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_SgnMeasList_item,
{ "GNSS-SgnMeasElement", "lpp.GNSS_SgnMeasElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_CodePhaseAmbiguity,
{ "gnss-CodePhaseAmbiguity", "lpp.gnss_CodePhaseAmbiguity",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_gnss_SatMeasList,
{ "gnss-SatMeasList", "lpp.gnss_SatMeasList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_SatMeasList_item,
{ "GNSS-SatMeasElement", "lpp.GNSS_SatMeasElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cNo,
{ "cNo", "lpp.cNo",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_dbhz, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lpp_mpathDet,
{ "mpathDet", "lpp.mpathDet",
FT_UINT32, BASE_DEC, VALS(lpp_T_mpathDet_vals), 0,
NULL, HFILL }},
{ &hf_lpp_carrierQualityInd,
{ "carrierQualityInd", "lpp.carrierQualityInd",
FT_UINT8, BASE_DEC, VALS(lpp_carrierQualityInd_vals), 0,
"INTEGER_0_3", HFILL }},
{ &hf_lpp_codePhase_01,
{ "codePhase", "lpp.codePhase",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_GNSS_SatMeas_codePhase_fmt), 0,
"INTEGER_0_2097151", HFILL }},
{ &hf_lpp_integerCodePhase,
{ "integerCodePhase", "lpp.integerCodePhase",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_milliseconds, 0,
"INTEGER_0_127", HFILL }},
{ &hf_lpp_codePhaseRMSError,
{ "codePhaseRMSError", "lpp.codePhaseRMSError",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_codePhaseRMSError_fmt), 0,
"INTEGER_0_63", HFILL }},
{ &hf_lpp_doppler,
{ "doppler", "lpp.doppler",
FT_INT32, BASE_CUSTOM, CF_FUNC(lpp_doppler_fmt), 0,
"INTEGER_M32768_32767", HFILL }},
{ &hf_lpp_adr,
{ "adr", "lpp.adr",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_adr_fmt), 0,
"INTEGER_0_33554431", HFILL }},
{ &hf_lpp_agnss_List,
{ "agnss-List", "lpp.agnss_List_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_ID_Bitmap", HFILL }},
{ &hf_lpp_gnss_PositioningInstructions,
{ "gnss-PositioningInstructions", "lpp.gnss_PositioningInstructions_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_Methods,
{ "gnss-Methods", "lpp.gnss_Methods_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_ID_Bitmap", HFILL }},
{ &hf_lpp_fineTimeAssistanceMeasReq,
{ "fineTimeAssistanceMeasReq", "lpp.fineTimeAssistanceMeasReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_adrMeasReq,
{ "adrMeasReq", "lpp.adrMeasReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_multiFreqMeasReq,
{ "multiFreqMeasReq", "lpp.multiFreqMeasReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_gnss_SupportList,
{ "gnss-SupportList", "lpp.gnss_SupportList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_assistanceDataSupportList,
{ "assistanceDataSupportList", "lpp.assistanceDataSupportList_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_SupportList_item,
{ "GNSS-SupportElement", "lpp.GNSS_SupportElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_sbas_IDs,
{ "sbas-IDs", "lpp.sbas_IDs_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_agnss_Modes,
{ "agnss-Modes", "lpp.agnss_Modes_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositioningModes", HFILL }},
{ &hf_lpp_gnss_Signals,
{ "gnss-Signals", "lpp.gnss_Signals_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lpp_fta_MeasSupport,
{ "fta-MeasSupport", "lpp.fta_MeasSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_cellTime,
{ "cellTime", "lpp.cellTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccessTypes", HFILL }},
{ &hf_lpp_mode_02,
{ "mode", "lpp.mode_element",
FT_NONE, BASE_NONE, NULL, 0,
"PositioningModes", HFILL }},
{ &hf_lpp_adr_Support,
{ "adr-Support", "lpp.adr_Support",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_velocityMeasurementSupport,
{ "velocityMeasurementSupport", "lpp.velocityMeasurementSupport",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_gnss_CommonAssistanceDataSupport,
{ "gnss-CommonAssistanceDataSupport", "lpp.gnss_CommonAssistanceDataSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_GenericAssistanceDataSupport,
{ "gnss-GenericAssistanceDataSupport", "lpp.gnss_GenericAssistanceDataSupport",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_ReferenceTimeSupport,
{ "gnss-ReferenceTimeSupport", "lpp.gnss_ReferenceTimeSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_ReferenceLocationSupport,
{ "gnss-ReferenceLocationSupport", "lpp.gnss_ReferenceLocationSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_IonosphericModelSupport,
{ "gnss-IonosphericModelSupport", "lpp.gnss_IonosphericModelSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_EarthOrientationParametersSupport,
{ "gnss-EarthOrientationParametersSupport", "lpp.gnss_EarthOrientationParametersSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_SystemTime_01,
{ "gnss-SystemTime", "lpp.gnss_SystemTime_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_ID_Bitmap", HFILL }},
{ &hf_lpp_fta_Support,
{ "fta-Support", "lpp.fta_Support_element",
FT_NONE, BASE_NONE, NULL, 0,
"AccessTypes", HFILL }},
{ &hf_lpp_ionoModel,
{ "ionoModel", "lpp.ionoModel",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_GNSS_GenericAssistanceDataSupport_item,
{ "GNSS-GenericAssistDataSupportElement", "lpp.GNSS_GenericAssistDataSupportElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_TimeModelsSupport,
{ "gnss-TimeModelsSupport", "lpp.gnss_TimeModelsSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_TimeModelListSupport", HFILL }},
{ &hf_lpp_gnss_DifferentialCorrectionsSupport,
{ "gnss-DifferentialCorrectionsSupport", "lpp.gnss_DifferentialCorrectionsSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_NavigationModelSupport,
{ "gnss-NavigationModelSupport", "lpp.gnss_NavigationModelSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_RealTimeIntegritySupport,
{ "gnss-RealTimeIntegritySupport", "lpp.gnss_RealTimeIntegritySupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_DataBitAssistanceSupport,
{ "gnss-DataBitAssistanceSupport", "lpp.gnss_DataBitAssistanceSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_AcquisitionAssistanceSupport,
{ "gnss-AcquisitionAssistanceSupport", "lpp.gnss_AcquisitionAssistanceSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_AlmanacSupport,
{ "gnss-AlmanacSupport", "lpp.gnss_AlmanacSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_UTC_ModelSupport,
{ "gnss-UTC-ModelSupport", "lpp.gnss_UTC_ModelSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_AuxiliaryInformationSupport,
{ "gnss-AuxiliaryInformationSupport", "lpp.gnss_AuxiliaryInformationSupport_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bds_DifferentialCorrectionsSupport_r12,
{ "bds-DifferentialCorrectionsSupport-r12", "lpp.bds_DifferentialCorrectionsSupport_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bds_GridModelSupport_r12,
{ "bds-GridModelSupport-r12", "lpp.bds_GridModelSupport_r12_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnssSignalIDs,
{ "gnssSignalIDs", "lpp.gnssSignalIDs_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_SignalIDs", HFILL }},
{ &hf_lpp_dgnss_ValidityTimeSup,
{ "dgnss-ValidityTimeSup", "lpp.dgnss_ValidityTimeSup",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_clockModel,
{ "clockModel", "lpp.clockModel",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_orbitModel,
{ "orbitModel", "lpp.orbitModel",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_confidenceSupport_r10,
{ "confidenceSupport-r10", "lpp.confidenceSupport_r10",
FT_UINT32, BASE_DEC, VALS(lpp_T_confidenceSupport_r10_vals), 0,
"T_confidenceSupport_r10", HFILL }},
{ &hf_lpp_dopplerUncertaintyExtSupport_r10,
{ "dopplerUncertaintyExtSupport-r10", "lpp.dopplerUncertaintyExtSupport_r10",
FT_UINT32, BASE_DEC, VALS(lpp_T_dopplerUncertaintyExtSupport_r10_vals), 0,
"T_dopplerUncertaintyExtSupport_r10", HFILL }},
{ &hf_lpp_almanacModel,
{ "almanacModel", "lpp.almanacModel",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_utc_Model,
{ "utc-Model", "lpp.utc_Model",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_SupportListReq,
{ "gnss-SupportListReq", "lpp.gnss_SupportListReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_assistanceDataSupportListReq,
{ "assistanceDataSupportListReq", "lpp.assistanceDataSupportListReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_locationVelocityTypesReq,
{ "locationVelocityTypesReq", "lpp.locationVelocityTypesReq",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_locationServerErrorCauses_01,
{ "locationServerErrorCauses", "lpp.locationServerErrorCauses_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_LocationServerErrorCauses", HFILL }},
{ &hf_lpp_targetDeviceErrorCauses_01,
{ "targetDeviceErrorCauses", "lpp.targetDeviceErrorCauses_element",
FT_NONE, BASE_NONE, NULL, 0,
"GNSS_TargetDeviceErrorCauses", HFILL }},
{ &hf_lpp_cause_02,
{ "cause", "lpp.cause",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_02_vals), 0,
"T_cause_02", HFILL }},
{ &hf_lpp_cause_03,
{ "cause", "lpp.cause",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_03_vals), 0,
"T_cause_03", HFILL }},
{ &hf_lpp_fineTimeAssistanceMeasurementsNotPossible,
{ "fineTimeAssistanceMeasurementsNotPossible", "lpp.fineTimeAssistanceMeasurementsNotPossible_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_adrMeasurementsNotPossible,
{ "adrMeasurementsNotPossible", "lpp.adrMeasurementsNotPossible_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_multiFrequencyMeasurementsNotPossible,
{ "multiFrequencyMeasurementsNotPossible", "lpp.multiFrequencyMeasurementsNotPossible_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_id,
{ "gnss-id", "lpp.gnss_id",
FT_UINT32, BASE_DEC, VALS(lpp_T_gnss_id_vals), 0,
NULL, HFILL }},
{ &hf_lpp_gnss_ids,
{ "gnss-ids", "lpp.gnss_ids",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_gnss_SignalID_01,
{ "gnss-SignalID", "lpp.gnss_SignalID",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_7", HFILL }},
{ &hf_lpp_gnss_SignalIDs,
{ "gnss-SignalIDs", "lpp.gnss_SignalIDs",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_8", HFILL }},
{ &hf_lpp_sbas_id,
{ "sbas-id", "lpp.sbas_id",
FT_UINT32, BASE_DEC, VALS(lpp_T_sbas_id_vals), 0,
NULL, HFILL }},
{ &hf_lpp_sbas_IDs_01,
{ "sbas-IDs", "lpp.sbas_IDs",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_satellite_id,
{ "satellite-id", "lpp.satellite_id",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_63", HFILL }},
{ &hf_lpp_ecid_SignalMeasurementInformation,
{ "ecid-SignalMeasurementInformation", "lpp.ecid_SignalMeasurementInformation_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ecid_Error,
{ "ecid-Error", "lpp.ecid_Error",
FT_UINT32, BASE_DEC, VALS(lpp_ECID_Error_vals), 0,
NULL, HFILL }},
{ &hf_lpp_primaryCellMeasuredResults,
{ "primaryCellMeasuredResults", "lpp.primaryCellMeasuredResults_element",
FT_NONE, BASE_NONE, NULL, 0,
"MeasuredResultsElement", HFILL }},
{ &hf_lpp_measuredResultsList,
{ "measuredResultsList", "lpp.measuredResultsList",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_MeasuredResultsList_item,
{ "MeasuredResultsElement", "lpp.MeasuredResultsElement_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_arfcnEUTRA,
{ "arfcnEUTRA", "lpp.arfcnEUTRA",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA", HFILL }},
{ &hf_lpp_rsrp_Result,
{ "rsrp-Result", "lpp.rsrp_Result",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_rsrp_Result_fmt), 0,
"INTEGER_0_97", HFILL }},
{ &hf_lpp_rsrq_Result,
{ "rsrq-Result", "lpp.rsrq_Result",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_rsrq_Result_fmt), 0,
"INTEGER_0_34", HFILL }},
{ &hf_lpp_ue_RxTxTimeDiff,
{ "ue-RxTxTimeDiff", "lpp.ue_RxTxTimeDiff",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_ue_RxTxTimeDiff_fmt), 0,
"INTEGER_0_4095", HFILL }},
{ &hf_lpp_arfcnEUTRA_v9a0,
{ "arfcnEUTRA-v9a0", "lpp.arfcnEUTRA_v9a0",
FT_UINT32, BASE_DEC, NULL, 0,
"ARFCN_ValueEUTRA_v9a0", HFILL }},
{ &hf_lpp_requestedMeasurements,
{ "requestedMeasurements", "lpp.requestedMeasurements",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ecid_MeasSupported,
{ "ecid-MeasSupported", "lpp.ecid_MeasSupported",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ueRxTxSupTDD_r13,
{ "ueRxTxSupTDD-r13", "lpp.ueRxTxSupTDD_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_ueRxTxSupTDD_r13_vals), 0,
NULL, HFILL }},
{ &hf_lpp_locationServerErrorCauses_02,
{ "locationServerErrorCauses", "lpp.locationServerErrorCauses_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECID_LocationServerErrorCauses", HFILL }},
{ &hf_lpp_targetDeviceErrorCauses_02,
{ "targetDeviceErrorCauses", "lpp.targetDeviceErrorCauses_element",
FT_NONE, BASE_NONE, NULL, 0,
"ECID_TargetDeviceErrorCauses", HFILL }},
{ &hf_lpp_cause_04,
{ "cause", "lpp.cause",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_04_vals), 0,
"T_cause_04", HFILL }},
{ &hf_lpp_cause_05,
{ "cause", "lpp.cause",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_05_vals), 0,
"T_cause_05", HFILL }},
{ &hf_lpp_rsrpMeasurementNotPossible,
{ "rsrpMeasurementNotPossible", "lpp.rsrpMeasurementNotPossible_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_rsrqMeasurementNotPossible,
{ "rsrqMeasurementNotPossible", "lpp.rsrqMeasurementNotPossible_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_ueRxTxMeasurementNotPossible,
{ "ueRxTxMeasurementNotPossible", "lpp.ueRxTxMeasurementNotPossible_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_tbs_MeasurementInformation_r13,
{ "tbs-MeasurementInformation-r13", "lpp.tbs_MeasurementInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_tbs_Error_r13,
{ "tbs-Error-r13", "lpp.tbs_Error_r13",
FT_UINT32, BASE_DEC, VALS(lpp_TBS_Error_r13_vals), 0,
NULL, HFILL }},
{ &hf_lpp_measurementReferenceTime_r13,
{ "measurementReferenceTime-r13", "lpp.measurementReferenceTime_r13",
FT_STRING, BASE_NONE, NULL, 0,
"UTCTime", HFILL }},
{ &hf_lpp_mbs_SgnMeasList_r13,
{ "mbs-SgnMeasList-r13", "lpp.mbs_SgnMeasList_r13",
FT_UINT32, BASE_DEC, NULL, 0,
"MBS_BeaconMeasList_r13", HFILL }},
{ &hf_lpp_MBS_BeaconMeasList_r13_item,
{ "MBS-BeaconMeasElement-r13", "lpp.MBS_BeaconMeasElement_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_transmitterID_r13,
{ "transmitterID-r13", "lpp.transmitterID_r13",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_32767", HFILL }},
{ &hf_lpp_codePhase_r13,
{ "codePhase-r13", "lpp.codePhase_r13",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_mbs_beaconMeasElt_codePhase_fmt), 0,
"INTEGER_0_2097151", HFILL }},
{ &hf_lpp_codePhaseRMSError_r13,
{ "codePhaseRMSError-r13", "lpp.codePhaseRMSError_r13",
FT_UINT32, BASE_CUSTOM, CF_FUNC(lpp_codePhaseRMSError_fmt), 0,
"INTEGER_0_63", HFILL }},
{ &hf_lpp_mbsSgnMeasListReq_r13,
{ "mbsSgnMeasListReq-r13", "lpp.mbsSgnMeasListReq_r13",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_tbs_Modes_r13,
{ "tbs-Modes-r13", "lpp.tbs_Modes_r13",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_locationServerErrorCauses_r13,
{ "locationServerErrorCauses-r13", "lpp.locationServerErrorCauses_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"TBS_LocationServerErrorCauses_r13", HFILL }},
{ &hf_lpp_targetDeviceErrorCauses_r13,
{ "targetDeviceErrorCauses-r13", "lpp.targetDeviceErrorCauses_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"TBS_TargetDeviceErrorCauses_r13", HFILL }},
{ &hf_lpp_cause_r13,
{ "cause-r13", "lpp.cause_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_r13_vals), 0,
NULL, HFILL }},
{ &hf_lpp_cause_r13_01,
{ "cause-r13", "lpp.cause_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_r13_01_vals), 0,
"T_cause_r13_01", HFILL }},
{ &hf_lpp_sensor_MeasurementInformation_r13,
{ "sensor-MeasurementInformation-r13", "lpp.sensor_MeasurementInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_sensor_Error_r13,
{ "sensor-Error-r13", "lpp.sensor_Error_r13",
FT_UINT32, BASE_DEC, VALS(lpp_Sensor_Error_r13_vals), 0,
NULL, HFILL }},
{ &hf_lpp_uncompensatedBarometricPressure_r13,
{ "uncompensatedBarometricPressure-r13", "lpp.uncompensatedBarometricPressure_r13",
FT_UINT32, BASE_DEC|BASE_UNIT_STRING, &units_pa, 0,
"INTEGER_30000_115000", HFILL }},
{ &hf_lpp_uncompensatedBarometricPressureReq_r13,
{ "uncompensatedBarometricPressureReq-r13", "lpp.uncompensatedBarometricPressureReq_r13",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_sensor_Modes_r13,
{ "sensor-Modes-r13", "lpp.sensor_Modes_r13",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_locationServerErrorCauses_r13_01,
{ "locationServerErrorCauses-r13", "lpp.locationServerErrorCauses_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"Sensor_LocationServerErrorCauses_r13", HFILL }},
{ &hf_lpp_targetDeviceErrorCauses_r13_01,
{ "targetDeviceErrorCauses-r13", "lpp.targetDeviceErrorCauses_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"Sensor_TargetDeviceErrorCauses_r13", HFILL }},
{ &hf_lpp_cause_r13_02,
{ "cause-r13", "lpp.cause_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_r13_02_vals), 0,
"T_cause_r13_02", HFILL }},
{ &hf_lpp_cause_r13_03,
{ "cause-r13", "lpp.cause_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_r13_03_vals), 0,
"T_cause_r13_03", HFILL }},
{ &hf_lpp_wlan_MeasurementInformation_r13,
{ "wlan-MeasurementInformation-r13", "lpp.wlan_MeasurementInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_Error_r13,
{ "wlan-Error-r13", "lpp.wlan_Error_r13",
FT_UINT32, BASE_DEC, VALS(lpp_WLAN_Error_r13_vals), 0,
NULL, HFILL }},
{ &hf_lpp_wlan_MeasurementList_r13,
{ "wlan-MeasurementList-r13", "lpp.wlan_MeasurementList_r13",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_WLAN_MeasurementList_r13_item,
{ "WLAN-MeasurementElement-r13", "lpp.WLAN_MeasurementElement_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_AP_Identifier_r13,
{ "wlan-AP-Identifier-r13", "lpp.wlan_AP_Identifier_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_rssi_r13,
{ "rssi-r13", "lpp.rssi_r13",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
"INTEGER_M127_128", HFILL }},
{ &hf_lpp_rtt_r13,
{ "rtt-r13", "lpp.rtt_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"WLAN_RTT_r13", HFILL }},
{ &hf_lpp_apChannelFrequency_r13,
{ "apChannelFrequency-r13", "lpp.apChannelFrequency_r13",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_256", HFILL }},
{ &hf_lpp_servingFlag_r13,
{ "servingFlag-r13", "lpp.servingFlag_r13",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_lpp_bssid_r13,
{ "bssid-r13", "lpp.bssid_r13",
FT_ETHER, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_6", HFILL }},
{ &hf_lpp_ssid_r13,
{ "ssid-r13", "lpp.ssid_r13",
FT_STRING, STR_ASCII, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_rttValue_r13,
{ "rttValue-r13", "lpp.rttValue_r13",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_16777215", HFILL }},
{ &hf_lpp_rttUnits_r13,
{ "rttUnits-r13", "lpp.rttUnits_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_rttUnits_r13_vals), 0,
NULL, HFILL }},
{ &hf_lpp_rttAccuracy_r13,
{ "rttAccuracy-r13", "lpp.rttAccuracy_r13",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_lpp_requestedMeasurements_r13,
{ "requestedMeasurements-r13", "lpp.requestedMeasurements_r13",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_Modes_r13,
{ "wlan-Modes-r13", "lpp.wlan_Modes_r13",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_MeasSupported_r13,
{ "wlan-MeasSupported-r13", "lpp.wlan_MeasSupported_r13",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_locationServerErrorCauses_r13_02,
{ "locationServerErrorCauses-r13", "lpp.locationServerErrorCauses_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"WLAN_LocationServerErrorCauses_r13", HFILL }},
{ &hf_lpp_targetDeviceErrorCauses_r13_02,
{ "targetDeviceErrorCauses-r13", "lpp.targetDeviceErrorCauses_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"WLAN_TargetDeviceErrorCauses_r13", HFILL }},
{ &hf_lpp_cause_r13_04,
{ "cause-r13", "lpp.cause_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_r13_04_vals), 0,
"T_cause_r13_04", HFILL }},
{ &hf_lpp_cause_r13_05,
{ "cause-r13", "lpp.cause_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_r13_05_vals), 0,
"T_cause_r13_05", HFILL }},
{ &hf_lpp_wlan_AP_RSSI_MeasurementNotPossible_r13,
{ "wlan-AP-RSSI-MeasurementNotPossible-r13", "lpp.wlan_AP_RSSI_MeasurementNotPossible_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_wlan_AP_RTT_MeasurementNotPossible_r13,
{ "wlan-AP-RTT-MeasurementNotPossible-r13", "lpp.wlan_AP_RTT_MeasurementNotPossible_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bt_MeasurementInformation_r13,
{ "bt-MeasurementInformation-r13", "lpp.bt_MeasurementInformation_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_bt_Error_r13,
{ "bt-Error-r13", "lpp.bt_Error_r13",
FT_UINT32, BASE_DEC, VALS(lpp_BT_Error_r13_vals), 0,
NULL, HFILL }},
{ &hf_lpp_bt_MeasurementList_r13,
{ "bt-MeasurementList-r13", "lpp.bt_MeasurementList_r13",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_BT_MeasurementList_r13_item,
{ "BT-MeasurementElement-r13", "lpp.BT_MeasurementElement_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_btAddr_r13,
{ "btAddr-r13", "lpp.btAddr_r13",
FT_ETHER, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_rssi_r13_01,
{ "rssi-r13", "lpp.rssi_r13",
FT_INT32, BASE_DEC|BASE_UNIT_STRING, &units_dbm, 0,
"INTEGER_M128_127", HFILL }},
{ &hf_lpp_requestedMeasurements_r13_01,
{ "requestedMeasurements-r13", "lpp.requestedMeasurements_r13",
FT_BYTES, BASE_NONE, NULL, 0,
"T_requestedMeasurements_r13_01", HFILL }},
{ &hf_lpp_bt_Modes_r13,
{ "bt-Modes-r13", "lpp.bt_Modes_r13",
FT_BYTES, BASE_NONE, NULL, 0,
"T_bt_Modes_r13", HFILL }},
{ &hf_lpp_bt_MeasSupported_r13,
{ "bt-MeasSupported-r13", "lpp.bt_MeasSupported_r13",
FT_BYTES, BASE_NONE, NULL, 0,
"T_bt_MeasSupported_r13", HFILL }},
{ &hf_lpp_locationServerErrorCauses_r13_03,
{ "locationServerErrorCauses-r13", "lpp.locationServerErrorCauses_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"BT_LocationServerErrorCauses_r13", HFILL }},
{ &hf_lpp_targetDeviceErrorCauses_r13_03,
{ "targetDeviceErrorCauses-r13", "lpp.targetDeviceErrorCauses_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
"BT_TargetDeviceErrorCauses_r13", HFILL }},
{ &hf_lpp_cause_r13_06,
{ "cause-r13", "lpp.cause_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_r13_06_vals), 0,
"T_cause_r13_06", HFILL }},
{ &hf_lpp_cause_r13_07,
{ "cause-r13", "lpp.cause_r13",
FT_UINT32, BASE_DEC, VALS(lpp_T_cause_r13_07_vals), 0,
"T_cause_r13_07", HFILL }},
{ &hf_lpp_bt_Beacon_rssiMeasurementNotPossible_r13,
{ "bt-Beacon-rssiMeasurementNotPossible-r13", "lpp.bt_Beacon_rssiMeasurementNotPossible_r13_element",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL }},
{ &hf_lpp_T_accessTypes_eutra,
{ "eutra", "lpp.eutra",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_accessTypes_utra,
{ "utra", "lpp.utra",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_accessTypes_gsm,
{ "gsm", "lpp.gsm",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_posModes_standalone,
{ "standalone", "lpp.standalone",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_posModes_ue_based,
{ "ue-based", "lpp.ue-based",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_posModes_ue_assisted,
{ "ue-assisted", "lpp.ue-assisted",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_LocationSource_r13_a_gnss,
{ "a-gnss", "lpp.a-gnss",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_LocationSource_r13_wlan,
{ "wlan", "lpp.wlan",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_LocationSource_r13_bt,
{ "bt", "lpp.bt",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_LocationSource_r13_tbs,
{ "tbs", "lpp.tbs",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lpp_LocationSource_r13_sensor,
{ "sensor", "lpp.sensor",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lpp_T_otdoa_Mode_ue_assisted,
{ "ue-assisted", "lpp.ue-assisted",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_ionoModel_klobuchar,
{ "klobuchar", "lpp.klobuchar",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_ionoModel_neQuick,
{ "neQuick", "lpp.neQuick",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_clockModel_model_1,
{ "model-1", "lpp.model-1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_clockModel_model_2,
{ "model-2", "lpp.model-2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_clockModel_model_3,
{ "model-3", "lpp.model-3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_clockModel_model_4,
{ "model-4", "lpp.model-4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lpp_T_clockModel_model_5,
{ "model-5", "lpp.model-5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lpp_T_clockModel_model_6,
{ "model-6", "lpp.model-6",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lpp_T_orbitModel_model_1,
{ "model-1", "lpp.model-1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_orbitModel_model_2,
{ "model-2", "lpp.model-2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_orbitModel_model_3,
{ "model-3", "lpp.model-3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_orbitModel_model_4,
{ "model-4", "lpp.model-4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lpp_T_orbitModel_model_5,
{ "model-5", "lpp.model-5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lpp_T_orbitModel_model_6,
{ "model-6", "lpp.model-6",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lpp_T_almanacModel_model_1,
{ "model-1", "lpp.model-1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_almanacModel_model_2,
{ "model-2", "lpp.model-2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_almanacModel_model_3,
{ "model-3", "lpp.model-3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_almanacModel_model_4,
{ "model-4", "lpp.model-4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lpp_T_almanacModel_model_5,
{ "model-5", "lpp.model-5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lpp_T_almanacModel_model_6,
{ "model-6", "lpp.model-6",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lpp_T_almanacModel_model_7,
{ "model-7", "lpp.model-7",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }},
{ &hf_lpp_T_utc_Model_model_1,
{ "model-1", "lpp.model-1",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_utc_Model_model_2,
{ "model-2", "lpp.model-2",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_utc_Model_model_3,
{ "model-3", "lpp.model-3",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_utc_Model_model_4,
{ "model-4", "lpp.model-4",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lpp_T_utc_Model_model_5,
{ "model-5", "lpp.model-5",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lpp_T_gnss_ids_gps,
{ "gps", "lpp.gps",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_gnss_ids_sbas,
{ "sbas", "lpp.sbas",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_gnss_ids_qzss,
{ "qzss", "lpp.qzss",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_gnss_ids_galileo,
{ "galileo", "lpp.galileo",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lpp_T_gnss_ids_glonass,
{ "glonass", "lpp.glonass",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }},
{ &hf_lpp_T_gnss_ids_bds,
{ "bds", "lpp.bds",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }},
{ &hf_lpp_T_sbas_IDs_waas,
{ "waas", "lpp.waas",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_sbas_IDs_egnos,
{ "egnos", "lpp.egnos",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_sbas_IDs_msas,
{ "msas", "lpp.msas",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_sbas_IDs_gagan,
{ "gagan", "lpp.gagan",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }},
{ &hf_lpp_T_requestedMeasurements_rsrpReq,
{ "rsrpReq", "lpp.rsrpReq",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_requestedMeasurements_rsrqReq,
{ "rsrqReq", "lpp.rsrqReq",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_requestedMeasurements_ueRxTxReq,
{ "ueRxTxReq", "lpp.ueRxTxReq",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_ecid_MeasSupported_rsrpSup,
{ "rsrpSup", "lpp.rsrpSup",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_ecid_MeasSupported_rsrqSup,
{ "rsrqSup", "lpp.rsrqSup",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_ecid_MeasSupported_ueRxTxSup,
{ "ueRxTxSup", "lpp.ueRxTxSup",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }},
{ &hf_lpp_T_tbs_Modes_r13_standalone,
{ "standalone", "lpp.standalone",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_tbs_Modes_r13_ue_assisted,
{ "ue-assisted", "lpp.ue-assisted",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_sensor_Modes_r13_standalone,
{ "standalone", "lpp.standalone",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_sensor_Modes_r13_ue_assisted,
{ "ue-assisted", "lpp.ue-assisted",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_requestedMeasurements_r13_rssi,
{ "rssi", "lpp.rssi",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_requestedMeasurements_r13_rtt,
{ "rtt", "lpp.rtt",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_wlan_Modes_r13_standalone,
{ "standalone", "lpp.standalone",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_wlan_Modes_r13_ue_assisted,
{ "ue-assisted", "lpp.ue-assisted",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_wlan_MeasSupported_r13_rssi_r13,
{ "rssi-r13", "lpp.rssi-r13",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_wlan_MeasSupported_r13_rtt_r13,
{ "rtt-r13", "lpp.rtt-r13",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_requestedMeasurements_r13_01_rssi,
{ "rssi", "lpp.rssi",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_bt_Modes_r13_standalone,
{ "standalone", "lpp.standalone",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
{ &hf_lpp_T_bt_Modes_r13_ue_assisted,
{ "ue-assisted", "lpp.ue-assisted",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }},
{ &hf_lpp_T_bt_MeasSupported_r13_rssi_r13,
{ "rssi-r13", "lpp.rssi-r13",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }},
#line 1660 "./asn1/lpp/packet-lpp-template.c"
{ &hf_lpp_svHealthExt_v1240_e5bhs,
{ "E5b Signal Health Status", "lpp.svHealthExt_v1240.e5bhs",
FT_UINT8, BASE_DEC, VALS(lpp_signal_health_status_vals), 0,
NULL, HFILL }},
{ &hf_lpp_svHealthExt_v1240_e1_bhs,
{ "E1-B Signal Health Status", "lpp.svHealthExt_v1240.e1_bhs",
FT_UINT8, BASE_DEC, VALS(lpp_signal_health_status_vals), 0,
NULL, HFILL }},
{ &hf_lpp_kepSV_StatusINAV_e5bhs,
{ "E5b Signal Health Status", "lpp.kepSV_StatusINAV.e5bhs",
FT_UINT8, BASE_DEC, VALS(lpp_signal_health_status_vals), 0,
NULL, HFILL }},
{ &hf_lpp_kepSV_StatusINAV_e1_bhs,
{ "E1-B Signal Health Status", "lpp.kepSV_StatusINAV.e1_bhs",
FT_UINT8, BASE_DEC, VALS(lpp_signal_health_status_vals), 0,
NULL, HFILL }},
{ &hf_lpp_kepSV_StatusFNAV_e5ahs,
{ "E5a Signal Health Status", "lpp.kepSV_StatusFNAV.e5ahs",
FT_UINT8, BASE_DEC, VALS(lpp_signal_health_status_vals), 0,
NULL, HFILL }},
{ &hf_lpp_bdsSvHealth_r12_sat_clock,
{ "Satellite Clock", "lpp.bdsSvHealth_r12.sat_clock",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_ok_error), 0,
NULL, HFILL }},
{ &hf_lpp_bdsSvHealth_r12_b1i,
{ "B1I Signal", "lpp.bdsSvHealth_r12.b1i",
FT_BOOLEAN, BASE_NONE, TFS(&lpp_bdsSvHealth_r12_b1i_b2i_value), 0,
NULL, HFILL }},
{ &hf_lpp_bdsSvHealth_r12_b2i,
{ "B2I Signal", "lpp.bdsSvHealth_r12.b2i",
FT_BOOLEAN, BASE_NONE, TFS(&lpp_bdsSvHealth_r12_b1i_b2i_value), 0,
NULL, HFILL }},
{ &hf_lpp_bdsSvHealth_r12_nav,
{ "NAV Message", "lpp.bdsSvHealth_r12.nav",
FT_BOOLEAN, BASE_NONE, TFS(&lpp_bdsSvHealth_r12_nav_value), 0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_lpp,
&ett_lpp_bitmap,
&ett_lpp_svHealthExt_v1240,
&ett_kepSV_StatusINAV,
&ett_kepSV_StatusFNAV,
&ett_lpp_bdsSvHealth_r12,
#line 1 "./asn1/lpp/packet-lpp-ettarr.c"
&ett_lpp_LPP_Message,
&ett_lpp_Acknowledgement,
&ett_lpp_LPP_MessageBody,
&ett_lpp_T_c1,
&ett_lpp_T_messageClassExtension,
&ett_lpp_LPP_TransactionID,
&ett_lpp_RequestCapabilities,
&ett_lpp_T_criticalExtensions,
&ett_lpp_T_c1_01,
&ett_lpp_T_criticalExtensionsFuture,
&ett_lpp_RequestCapabilities_r9_IEs,
&ett_lpp_ProvideCapabilities,
&ett_lpp_T_criticalExtensions_01,
&ett_lpp_T_c1_02,
&ett_lpp_T_criticalExtensionsFuture_01,
&ett_lpp_ProvideCapabilities_r9_IEs,
&ett_lpp_RequestAssistanceData,
&ett_lpp_T_criticalExtensions_02,
&ett_lpp_T_c1_03,
&ett_lpp_T_criticalExtensionsFuture_02,
&ett_lpp_RequestAssistanceData_r9_IEs,
&ett_lpp_ProvideAssistanceData,
&ett_lpp_T_criticalExtensions_03,
&ett_lpp_T_c1_04,
&ett_lpp_T_criticalExtensionsFuture_03,
&ett_lpp_ProvideAssistanceData_r9_IEs,
&ett_lpp_RequestLocationInformation,
&ett_lpp_T_criticalExtensions_04,
&ett_lpp_T_c1_05,
&ett_lpp_T_criticalExtensionsFuture_04,
&ett_lpp_RequestLocationInformation_r9_IEs,
&ett_lpp_ProvideLocationInformation,
&ett_lpp_T_criticalExtensions_05,
&ett_lpp_T_c1_06,
&ett_lpp_T_criticalExtensionsFuture_05,
&ett_lpp_ProvideLocationInformation_r9_IEs,
&ett_lpp_Abort,
&ett_lpp_T_criticalExtensions_06,
&ett_lpp_T_c1_07,
&ett_lpp_T_criticalExtensionsFuture_06,
&ett_lpp_Abort_r9_IEs,
&ett_lpp_Error,
&ett_lpp_T_criticalExtensionsFuture_07,
&ett_lpp_Error_r9_IEs,
&ett_lpp_AccessTypes,
&ett_lpp_T_accessTypes,
&ett_lpp_CellGlobalIdEUTRA_AndUTRA,
&ett_lpp_T_plmn_Identity,
&ett_lpp_T_mcc,
&ett_lpp_T_mnc,
&ett_lpp_T_cellIdentity,
&ett_lpp_CellGlobalIdGERAN,
&ett_lpp_T_plmn_Identity_01,
&ett_lpp_T_mcc_01,
&ett_lpp_T_mnc_01,
&ett_lpp_ECGI,
&ett_lpp_T_mcc_02,
&ett_lpp_T_mnc_02,
&ett_lpp_Ellipsoid_Point,
&ett_lpp_Ellipsoid_PointWithUncertaintyCircle,
&ett_lpp_EllipsoidPointWithUncertaintyEllipse,
&ett_lpp_EllipsoidPointWithAltitude,
&ett_lpp_EllipsoidPointWithAltitudeAndUncertaintyEllipsoid,
&ett_lpp_EllipsoidArc,
&ett_lpp_EPDU_Sequence,
&ett_lpp_EPDU,
&ett_lpp_EPDU_Identifier,
&ett_lpp_HorizontalVelocity,
&ett_lpp_HorizontalWithVerticalVelocity,
&ett_lpp_HorizontalVelocityWithUncertainty,
&ett_lpp_HorizontalWithVerticalVelocityAndUncertainty,
&ett_lpp_LocationCoordinateTypes,
&ett_lpp_Polygon,
&ett_lpp_PolygonPoints,
&ett_lpp_PositioningModes,
&ett_lpp_T_posModes,
&ett_lpp_VelocityTypes,
&ett_lpp_CommonIEsRequestCapabilities,
&ett_lpp_CommonIEsProvideCapabilities,
&ett_lpp_CommonIEsRequestAssistanceData,
&ett_lpp_CommonIEsProvideAssistanceData,
&ett_lpp_CommonIEsRequestLocationInformation,
&ett_lpp_PeriodicalReportingCriteria,
&ett_lpp_TriggeredReportingCriteria,
&ett_lpp_QoS,
&ett_lpp_HorizontalAccuracy,
&ett_lpp_VerticalAccuracy,
&ett_lpp_ResponseTime,
&ett_lpp_CommonIEsProvideLocationInformation,
&ett_lpp_LocationCoordinates,
&ett_lpp_Velocity,
&ett_lpp_LocationError,
&ett_lpp_LocationSource_r13,
&ett_lpp_CommonIEsAbort,
&ett_lpp_CommonIEsError,
&ett_lpp_OTDOA_ProvideAssistanceData,
&ett_lpp_OTDOA_ReferenceCellInfo,
&ett_lpp_PRS_Info,
&ett_lpp_T_prs_MutingInfo_r9,
&ett_lpp_OTDOA_NeighbourCellInfoList,
&ett_lpp_OTDOA_NeighbourFreqInfo,
&ett_lpp_OTDOA_NeighbourCellInfoElement,
&ett_lpp_OTDOA_RequestAssistanceData,
&ett_lpp_OTDOA_ProvideLocationInformation,
&ett_lpp_OTDOA_SignalMeasurementInformation,
&ett_lpp_NeighbourMeasurementList,
&ett_lpp_NeighbourMeasurementElement,
&ett_lpp_OTDOA_MeasQuality,
&ett_lpp_OTDOA_RequestLocationInformation,
&ett_lpp_OTDOA_ProvideCapabilities,
&ett_lpp_T_otdoa_Mode,
&ett_lpp_SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA,
&ett_lpp_SEQUENCE_SIZE_1_maxBands_OF_SupportedBandEUTRA_v9a0,
&ett_lpp_SupportedBandEUTRA,
&ett_lpp_SupportedBandEUTRA_v9a0,
&ett_lpp_OTDOA_RequestCapabilities,
&ett_lpp_OTDOA_Error,
&ett_lpp_OTDOA_LocationServerErrorCauses,
&ett_lpp_OTDOA_TargetDeviceErrorCauses,
&ett_lpp_A_GNSS_ProvideAssistanceData,
&ett_lpp_GNSS_CommonAssistData,
&ett_lpp_GNSS_GenericAssistData,
&ett_lpp_GNSS_GenericAssistDataElement,
&ett_lpp_GNSS_ReferenceTime,
&ett_lpp_SEQUENCE_SIZE_1_16_OF_GNSS_ReferenceTimeForOneCell,
&ett_lpp_GNSS_ReferenceTimeForOneCell,
&ett_lpp_GNSS_SystemTime,
&ett_lpp_GPS_TOW_Assist,
&ett_lpp_GPS_TOW_AssistElement,
&ett_lpp_NetworkTime,
&ett_lpp_T_cellID,
&ett_lpp_T_eUTRA,
&ett_lpp_T_uTRA,
&ett_lpp_T_mode,
&ett_lpp_T_fdd,
&ett_lpp_T_tdd,
&ett_lpp_T_gSM,
&ett_lpp_GNSS_ReferenceLocation,
&ett_lpp_GNSS_IonosphericModel,
&ett_lpp_KlobucharModelParameter,
&ett_lpp_NeQuickModelParameter,
&ett_lpp_GNSS_EarthOrientationParameters,
&ett_lpp_GNSS_TimeModelList,
&ett_lpp_GNSS_TimeModelElement,
&ett_lpp_GNSS_DifferentialCorrections,
&ett_lpp_DGNSS_SgnTypeList,
&ett_lpp_DGNSS_SgnTypeElement,
&ett_lpp_DGNSS_SatList,
&ett_lpp_DGNSS_CorrectionsElement,
&ett_lpp_GNSS_NavigationModel,
&ett_lpp_GNSS_NavModelSatelliteList,
&ett_lpp_GNSS_NavModelSatelliteElement,
&ett_lpp_GNSS_ClockModel,
&ett_lpp_GNSS_OrbitModel,
&ett_lpp_StandardClockModelList,
&ett_lpp_StandardClockModelElement,
&ett_lpp_NAV_ClockModel,
&ett_lpp_CNAV_ClockModel,
&ett_lpp_GLONASS_ClockModel,
&ett_lpp_SBAS_ClockModel,
&ett_lpp_BDS_ClockModel_r12,
&ett_lpp_NavModelKeplerianSet,
&ett_lpp_NavModelNAV_KeplerianSet,
&ett_lpp_T_addNAVparam,
&ett_lpp_T_ephemSF1Rsvd,
&ett_lpp_NavModelCNAV_KeplerianSet,
&ett_lpp_NavModel_GLONASS_ECEF,
&ett_lpp_NavModel_SBAS_ECEF,
&ett_lpp_NavModel_BDS_KeplerianSet_r12,
&ett_lpp_GNSS_RealTimeIntegrity,
&ett_lpp_GNSS_BadSignalList,
&ett_lpp_BadSignalElement,
&ett_lpp_GNSS_DataBitAssistance,
&ett_lpp_GNSS_DataBitsSatList,
&ett_lpp_GNSS_DataBitsSatElement,
&ett_lpp_GNSS_DataBitsSgnList,
&ett_lpp_GNSS_DataBitsSgnElement,
&ett_lpp_GNSS_AcquisitionAssistance,
&ett_lpp_GNSS_AcquisitionAssistList,
&ett_lpp_GNSS_AcquisitionAssistElement,
&ett_lpp_GNSS_Almanac,
&ett_lpp_GNSS_AlmanacList,
&ett_lpp_GNSS_AlmanacElement,
&ett_lpp_AlmanacKeplerianSet,
&ett_lpp_AlmanacNAV_KeplerianSet,
&ett_lpp_AlmanacReducedKeplerianSet,
&ett_lpp_AlmanacMidiAlmanacSet,
&ett_lpp_AlmanacGLONASS_AlmanacSet,
&ett_lpp_AlmanacECEF_SBAS_AlmanacSet,
&ett_lpp_AlmanacBDS_AlmanacSet_r12,
&ett_lpp_GNSS_UTC_Model,
&ett_lpp_UTC_ModelSet1,
&ett_lpp_UTC_ModelSet2,
&ett_lpp_UTC_ModelSet3,
&ett_lpp_UTC_ModelSet4,
&ett_lpp_UTC_ModelSet5_r12,
&ett_lpp_GNSS_AuxiliaryInformation,
&ett_lpp_GNSS_ID_GPS,
&ett_lpp_GNSS_ID_GPS_SatElement,
&ett_lpp_GNSS_ID_GLONASS,
&ett_lpp_GNSS_ID_GLONASS_SatElement,
&ett_lpp_BDS_DifferentialCorrections_r12,
&ett_lpp_BDS_SgnTypeList_r12,
&ett_lpp_BDS_SgnTypeElement_r12,
&ett_lpp_DBDS_CorrectionList_r12,
&ett_lpp_DBDS_CorrectionElement_r12,
&ett_lpp_BDS_GridModelParameter_r12,
&ett_lpp_GridIonList_r12,
&ett_lpp_GridIonElement_r12,
&ett_lpp_A_GNSS_RequestAssistanceData,
&ett_lpp_GNSS_CommonAssistDataReq,
&ett_lpp_GNSS_GenericAssistDataReq,
&ett_lpp_GNSS_GenericAssistDataReqElement,
&ett_lpp_GNSS_ReferenceTimeReq,
&ett_lpp_SEQUENCE_SIZE_1_8_OF_GNSS_ID,
&ett_lpp_GNSS_ReferenceLocationReq,
&ett_lpp_GNSS_IonosphericModelReq,
&ett_lpp_GNSS_EarthOrientationParametersReq,
&ett_lpp_GNSS_TimeModelListReq,
&ett_lpp_GNSS_TimeModelElementReq,
&ett_lpp_GNSS_DifferentialCorrectionsReq,
&ett_lpp_GNSS_NavigationModelReq,
&ett_lpp_StoredNavListInfo,
&ett_lpp_SatListRelatedDataList,
&ett_lpp_SatListRelatedDataElement,
&ett_lpp_ReqNavListInfo,
&ett_lpp_T_clockModelID_PrefList,
&ett_lpp_T_orbitModelID_PrefList,
&ett_lpp_GNSS_RealTimeIntegrityReq,
&ett_lpp_GNSS_DataBitAssistanceReq,
&ett_lpp_GNSS_DataBitsReqSatList,
&ett_lpp_GNSS_DataBitsReqSatElement,
&ett_lpp_GNSS_AcquisitionAssistanceReq,
&ett_lpp_GNSS_AlmanacReq,
&ett_lpp_GNSS_UTC_ModelReq,
&ett_lpp_GNSS_AuxiliaryInformationReq,
&ett_lpp_BDS_DifferentialCorrectionsReq_r12,
&ett_lpp_BDS_GridModelReq_r12,
&ett_lpp_A_GNSS_ProvideLocationInformation,
&ett_lpp_GNSS_SignalMeasurementInformation,
&ett_lpp_MeasurementReferenceTime,
&ett_lpp_T_networkTime,
&ett_lpp_T_eUTRA_01,
&ett_lpp_T_uTRA_01,
&ett_lpp_T_mode_01,
&ett_lpp_T_fdd_01,
&ett_lpp_T_tdd_01,
&ett_lpp_T_gSM_01,
&ett_lpp_T_referenceFrame,
&ett_lpp_GNSS_MeasurementList,
&ett_lpp_GNSS_MeasurementForOneGNSS,
&ett_lpp_GNSS_SgnMeasList,
&ett_lpp_GNSS_SgnMeasElement,
&ett_lpp_GNSS_SatMeasList,
&ett_lpp_GNSS_SatMeasElement,
&ett_lpp_GNSS_LocationInformation,
&ett_lpp_A_GNSS_RequestLocationInformation,
&ett_lpp_GNSS_PositioningInstructions,
&ett_lpp_A_GNSS_ProvideCapabilities,
&ett_lpp_GNSS_SupportList,
&ett_lpp_GNSS_SupportElement,
&ett_lpp_T_fta_MeasSupport,
&ett_lpp_AssistanceDataSupportList,
&ett_lpp_GNSS_CommonAssistanceDataSupport,
&ett_lpp_GNSS_ReferenceTimeSupport,
&ett_lpp_GNSS_ReferenceLocationSupport,
&ett_lpp_GNSS_IonosphericModelSupport,
&ett_lpp_T_ionoModel,
&ett_lpp_GNSS_EarthOrientationParametersSupport,
&ett_lpp_GNSS_GenericAssistanceDataSupport,
&ett_lpp_GNSS_GenericAssistDataSupportElement,
&ett_lpp_GNSS_TimeModelListSupport,
&ett_lpp_GNSS_DifferentialCorrectionsSupport,
&ett_lpp_GNSS_NavigationModelSupport,
&ett_lpp_T_clockModel,
&ett_lpp_T_orbitModel,
&ett_lpp_GNSS_RealTimeIntegritySupport,
&ett_lpp_GNSS_DataBitAssistanceSupport,
&ett_lpp_GNSS_AcquisitionAssistanceSupport,
&ett_lpp_GNSS_AlmanacSupport,
&ett_lpp_T_almanacModel,
&ett_lpp_GNSS_UTC_ModelSupport,
&ett_lpp_T_utc_Model,
&ett_lpp_GNSS_AuxiliaryInformationSupport,
&ett_lpp_BDS_DifferentialCorrectionsSupport_r12,
&ett_lpp_BDS_GridModelSupport_r12,
&ett_lpp_A_GNSS_RequestCapabilities,
&ett_lpp_A_GNSS_Error,
&ett_lpp_GNSS_LocationServerErrorCauses,
&ett_lpp_GNSS_TargetDeviceErrorCauses,
&ett_lpp_GNSS_ID,
&ett_lpp_GNSS_ID_Bitmap,
&ett_lpp_T_gnss_ids,
&ett_lpp_GNSS_SignalID,
&ett_lpp_GNSS_SignalIDs,
&ett_lpp_SBAS_ID,
&ett_lpp_SBAS_IDs,
&ett_lpp_T_sbas_IDs,
&ett_lpp_SV_ID,
&ett_lpp_ECID_ProvideLocationInformation,
&ett_lpp_ECID_SignalMeasurementInformation,
&ett_lpp_MeasuredResultsList,
&ett_lpp_MeasuredResultsElement,
&ett_lpp_ECID_RequestLocationInformation,
&ett_lpp_T_requestedMeasurements,
&ett_lpp_ECID_ProvideCapabilities,
&ett_lpp_T_ecid_MeasSupported,
&ett_lpp_ECID_RequestCapabilities,
&ett_lpp_ECID_Error,
&ett_lpp_ECID_LocationServerErrorCauses,
&ett_lpp_ECID_TargetDeviceErrorCauses,
&ett_lpp_TBS_ProvideLocationInformation_r13,
&ett_lpp_TBS_MeasurementInformation_r13,
&ett_lpp_MBS_BeaconMeasList_r13,
&ett_lpp_MBS_BeaconMeasElement_r13,
&ett_lpp_TBS_RequestLocationInformation_r13,
&ett_lpp_TBS_ProvideCapabilities_r13,
&ett_lpp_T_tbs_Modes_r13,
&ett_lpp_TBS_RequestCapabilities_r13,
&ett_lpp_TBS_Error_r13,
&ett_lpp_TBS_LocationServerErrorCauses_r13,
&ett_lpp_TBS_TargetDeviceErrorCauses_r13,
&ett_lpp_Sensor_ProvideLocationInformation_r13,
&ett_lpp_Sensor_MeasurementInformation_r13,
&ett_lpp_Sensor_RequestLocationInformation_r13,
&ett_lpp_Sensor_ProvideCapabilities_r13,
&ett_lpp_T_sensor_Modes_r13,
&ett_lpp_Sensor_RequestCapabilities_r13,
&ett_lpp_Sensor_Error_r13,
&ett_lpp_Sensor_LocationServerErrorCauses_r13,
&ett_lpp_Sensor_TargetDeviceErrorCauses_r13,
&ett_lpp_WLAN_ProvideLocationInformation_r13,
&ett_lpp_WLAN_MeasurementInformation_r13,
&ett_lpp_WLAN_MeasurementList_r13,
&ett_lpp_WLAN_MeasurementElement_r13,
&ett_lpp_WLAN_AP_Identifier_r13,
&ett_lpp_WLAN_RTT_r13,
&ett_lpp_WLAN_RequestLocationInformation_r13,
&ett_lpp_T_requestedMeasurements_r13,
&ett_lpp_WLAN_ProvideCapabilities_r13,
&ett_lpp_T_wlan_Modes_r13,
&ett_lpp_T_wlan_MeasSupported_r13,
&ett_lpp_WLAN_RequestCapabilities_r13,
&ett_lpp_WLAN_Error_r13,
&ett_lpp_WLAN_LocationServerErrorCauses_r13,
&ett_lpp_WLAN_TargetDeviceErrorCauses_r13,
&ett_lpp_BT_ProvideLocationInformation_r13,
&ett_lpp_BT_MeasurementInformation_r13,
&ett_lpp_BT_MeasurementList_r13,
&ett_lpp_BT_MeasurementElement_r13,
&ett_lpp_BT_RequestLocationInformation_r13,
&ett_lpp_T_requestedMeasurements_r13_01,
&ett_lpp_BT_ProvideCapabilities_r13,
&ett_lpp_T_bt_Modes_r13,
&ett_lpp_T_bt_MeasSupported_r13,
&ett_lpp_BT_RequestCapabilities_r13,
&ett_lpp_BT_Error_r13,
&ett_lpp_BT_LocationServerErrorCauses_r13,
&ett_lpp_BT_TargetDeviceErrorCauses_r13,
#line 1707 "./asn1/lpp/packet-lpp-template.c"
};
proto_lpp = proto_register_protocol(PNAME, PSNAME, PFNAME);
register_dissector("lpp", dissect_lpp, proto_lpp);
proto_register_field_array(proto_lpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lpp(void)
{
lppe_handle = find_dissector_add_dependency("lppe", proto_lpp);
}
