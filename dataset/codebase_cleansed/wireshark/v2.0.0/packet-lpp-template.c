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
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m (%u)", uncertainty, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%f km (%u)", uncertainty/1000, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%u %%", v);
}
}
static void
lpp_altitude_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u m", v);
}
static void
lpp_uncertaintyAltitude_fmt(gchar *s, guint32 v)
{
double uncertainty = 45*(pow(1.025, (double)v)-1);
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m (%u)", uncertainty, v);
}
static void
lpp_radius_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u m (%u)", 5*v, v);
}
static void
lpp_expectedRSTD_fmt(gchar *s, guint32 v)
{
gint32 rstd = 3*((gint32)v-8192);
g_snprintf(s, ITEM_LABEL_LENGTH, "%d Ts (%u)", rstd, v);
}
static void
lpp_expectedRSTD_Uncertainty_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u Ts (%u)", 3*v, v);
}
static void
lpp_rstd_fmt(gchar *s, guint32 v)
{
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "RSTD < -15391 Ts (0)");
} else if (v < 2260) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-%u Ts <= RSTD < -%u Ts (%u)", 15391-5*(v-1), 15391-5*v, v);
} else if (v < 6355) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-%u Ts <= RSTD < -%u Ts (%u)", 6356-v, 6355-v, v);
} else if (v == 6355) {
g_snprintf(s, ITEM_LABEL_LENGTH, "-1 Ts <= RSTD <= 0 Ts (6355)");
} else if (v < 10452) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u Ts < RSTD <= %u Ts (%u)", v-6356, v-6355, v);
} else if (v < 12711) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u Ts < RSTD <= %u Ts (%u)", 5*(v-1)-48159, 5*v-48159, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "15391 Ts < RSTD (12711)");
}
}
static void
lpp_referenceTimeUnc_fmt(gchar *s, guint32 v)
{
double referenceTimeUnc = 0.5*(pow(1.14, (double)v)-1);
g_snprintf(s, ITEM_LABEL_LENGTH, "%f us (%u)", referenceTimeUnc, v);
}
static void
lpp_fractionalSecondsFromFrameStructureStart_fmt(gchar *s, guint32 v)
{
float frac = ((float)v)/4;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f us (%u)", frac, v);
}
static void
lpp_frameDrift_fmt(gchar *s, guint32 v)
{
double drift = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", drift, (gint32)v);
}
static void
lpp_alpha0_fmt(gchar *s, guint32 v)
{
double alpha = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", alpha, (gint32)v);
}
static void
lpp_alpha1_fmt(gchar *s, guint32 v)
{
double alpha = (double)((gint32)v)*pow(2, -27);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/semi-circle (%d)", alpha, (gint32)v);
}
static void
lpp_alpha2_3_fmt(gchar *s, guint32 v)
{
double alpha = (double)((gint32)v)*pow(2, -24);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/semi-circle (%d)", alpha, (gint32)v);
}
static void
lpp_beta0_fmt(gchar *s, guint32 v)
{
double beta = (double)((gint32)v)*pow(2, 11);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", beta, (gint32)v);
}
static void
lpp_beta1_fmt(gchar *s, guint32 v)
{
double beta = (double)((gint32)v)*pow(2, 14);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/semi-circle (%d)", beta, (gint32)v);
}
static void
lpp_beta2_3_fmt(gchar *s, guint32 v)
{
double beta = (double)((gint32)v)*pow(2, 16);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/semi-circle (%d)", beta, (gint32)v);
}
static void
lpp_ai0_fmt(gchar *s, guint32 v)
{
double ai = (double)v*pow(2, -2);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g sfu (%u)", ai, v);
}
static void
lpp_ai1_fmt(gchar *s, guint32 v)
{
double ai = (double)v*pow(2, -8);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g sfu/degree (%u)", ai, v);
}
static void
lpp_ai2_fmt(gchar *s, guint32 v)
{
double ai = (double)v*pow(2, -15);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g sfu/degree2 (%u)", ai, v);
}
static void
lpp_teop_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", 16*v, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", deltaUT1, (gint32)v);
}
static void
lpp_deltaUT1dot_fmt(gchar *s, guint32 v)
{
double deltaUT1dot = (double)((gint32)v)*pow(2, -25);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/day (%d)", deltaUT1dot, (gint32)v);
}
static void
lpp_gnss_TimeModelRefTime_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", v*16, v);
}
static void
lpp_tA0_fmt(gchar *s, guint32 v)
{
double tA0 = (double)((gint32)v)*pow(2, -35);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", tA0, (gint32)v);
}
static void
lpp_tA1_fmt(gchar *s, guint32 v)
{
double tA1 = (double)((gint32)v)*pow(2, -51);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", tA1, (gint32)v);
}
static void
lpp_tA2_fmt(gchar *s, guint32 v)
{
double tA2 = (double)((gint32)v)*pow(2, -68);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s2 (%d)", tA2, (gint32)v);
}
static void
lpp_pseudoRangeCor_fmt(gchar *s, guint32 v)
{
double pseudoRangeCor = ((double)(gint32)v)*0.32;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m (%d)", pseudoRangeCor, (gint32)v);
}
static void
lpp_rangeRateCor_fmt(gchar *s, guint32 v)
{
double rangeRateCor = ((double)(gint32)v)*0.032;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m/s (%d)", rangeRateCor, (gint32)v);
}
static void
lpp_stanClockToc_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u m/s (%u)", 60*v, v);
}
static void
lpp_stanClockAF2_fmt(gchar *s, guint32 v)
{
double stanClockAF2 = (double)((gint32)v)*pow(2, -59);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s2 (%d)", stanClockAF2, (gint32)v);
}
static void
lpp_stanClockAF1_fmt(gchar *s, guint32 v)
{
double stanClockAF1 = (double)((gint32)v)*pow(2, -46);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", stanClockAF1, (gint32)v);
}
static void
lpp_stanClockAF0_fmt(gchar *s, guint32 v)
{
double stanClockAF0 = (double)((gint32)v)*pow(2, -34);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", stanClockAF0, (gint32)v);
}
static void
lpp_stanClockTgd_fmt(gchar *s, guint32 v)
{
double stanClockTgd = (double)((gint32)v)*pow(2, -32);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", stanClockTgd, (gint32)v);
}
static void
lpp_sisa_fmt(gchar *s, guint32 v)
{
if (v < 50) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u cm (%u)", v, v);
} else if (v < 75) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u cm (%u)", 50+((v-50)*2), v);
} else if (v < 100) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u cm (%u)", 100+((v-75)*4), v);
} else if (v < 126) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u cm (%u)", 200+((v-100)*16), v);
} else if (v < 255) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Spare (%u)", v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "No Accuracy Prediction Available (255)");
}
}
static void
lpp_navToc_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", 16*v, v);
}
static void
lpp_navaf2_fmt(gchar *s, guint32 v)
{
double navaf2 = (double)((gint32)v)*pow(2, -55);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s2 (%d)", navaf2, (gint32)v);
}
static void
lpp_navaf1_fmt(gchar *s, guint32 v)
{
double navaf1 = (double)((gint32)v)*pow(2, -43);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", navaf1, (gint32)v);
}
static void
lpp_navaf0_navTgd_fmt(gchar *s, guint32 v)
{
double navaf0_navTgd = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", navaf0_navTgd, (gint32)v);
}
static void
lpp_cnavToc_cnavTop_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", 300*v, v);
}
static void
lpp_cnavAf2_fmt(gchar *s, guint32 v)
{
double cnavAf2 = (double)((gint32)v)*pow(2, -60);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s2 (%d)", cnavAf2, (gint32)v);
}
static void
lpp_cnavAf1_fmt(gchar *s, guint32 v)
{
double cnavAf1 = (double)((gint32)v)*pow(2, -48);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", cnavAf1, (gint32)v);
}
static void
lpp_cnavX_fmt(gchar *s, guint32 v)
{
double cnavX = (double)((gint32)v)*pow(2, -35);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", cnavX, (gint32)v);
}
static void
lpp_gloTau_gloDeltaTau_fmt(gchar *s, guint32 v)
{
double gloTau_gloDeltaTau = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", gloTau_gloDeltaTau, (gint32)v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", 16*v, v);
}
static void
lpp_sbasAgfo_fmt(gchar *s, guint32 v)
{
double sbasAgfo = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", sbasAgfo, (gint32)v);
}
static void
lpp_sbasAgf1_fmt(gchar *s, guint32 v)
{
double sbasAgf1 = (double)((gint32)v)*pow(2, -40);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", sbasAgf1, (gint32)v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", bdsToc, (gint32)v);
}
static void
lpp_bdsA0_r12_fmt(gchar *s, guint32 v)
{
double bdsA0 = (double)((gint32)v)*pow(2, -33);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", bdsA0, (gint32)v);
}
static void
lpp_bdsA1_r12_fmt(gchar *s, guint32 v)
{
double bdsA1 = (double)((gint32)v)*pow(2, -50);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", bdsA1, (gint32)v);
}
static void
lpp_bdsA2_r12_fmt(gchar *s, guint32 v)
{
double bdsA2 = (double)((gint32)v)*pow(2, -66);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s2 (%d)", bdsA2, (gint32)v);
}
static void
lpp_bdsTgd1_r12_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%g ns (%d)", (float)((gint32)v)*0.1, (gint32)v);
}
static void
lpp_keplerToe_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", 60*v, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m1/2 (%u)", keplerAPowerHalf, v);
}
static void
lpp_keplerCrs_Crc_fmt(gchar *s, guint32 v)
{
double keplerCrs_Crc = (double)((gint32)v)*pow(2, -5);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m (%d)", keplerCrs_Crc, (gint32)v);
}
static void
lpp_keplerCx_fmt(gchar *s, guint32 v)
{
double keplerCx = (double)((gint32)v)*pow(2, -29);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g rad (%d)", keplerCx, (gint32)v);
}
static void
lpp_navToe_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", 16*v, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m1/2 (%u)", navAPowerHalf, v);
}
static void
lpp_navCrs_Crc_fmt(gchar *s, guint32 v)
{
double navCrs_Crc = (double)((gint32)v)*pow(2, -5);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m (%d)", navCrs_Crc, (gint32)v);
}
static void
lpp_navCx_fmt(gchar *s, guint32 v)
{
double navCx = (double)((gint32)v)*pow(2, -29);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g rad (%d)", navCx, (gint32)v);
}
static void
lpp_cnavDeltaA_fmt(gchar *s, guint32 v)
{
double cnavDeltaA = (double)((gint32)v)*pow(2, -9);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m (%d)", cnavDeltaA, (gint32)v);
}
static void
lpp_cnavAdot_fmt(gchar *s, guint32 v)
{
double cnavAdot = (double)((gint32)v)*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m/s (%d)", cnavAdot, (gint32)v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g rad (%d)", cnavCx, (gint32)v);
}
static void
lpp_cnavCrs_Crc_fmt(gchar *s, guint32 v)
{
double cnavCrs_Crc = (double)((gint32)v)*pow(2, -8);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m (%d)", cnavCrs_Crc, (gint32)v);
}
static void
lpp_gloX_Y_Z_fmt(gchar *s, guint32 v)
{
double gloX_Y_Z = (double)((gint32)v)*pow(2, -11);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g km (%d)", gloX_Y_Z, (gint32)v);
}
static void
lpp_gloXdot_Ydot_Zdot_fmt(gchar *s, guint32 v)
{
double gloXdot_Ydot_Zdot = (double)((gint32)v)*pow(2, -20);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g km/s (%d)", gloXdot_Ydot_Zdot, (gint32)v);
}
static void
lpp_gloXdotdot_Ydotdot_Zdotdot_fmt(gchar *s, guint32 v)
{
double gloXdotdot_Ydotdot_Zdotdot = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g km/s2 (%d)", gloXdotdot_Ydotdot_Zdotdot, (gint32)v);
}
static void
lpp_sbasXg_Yg_fmt(gchar *s, guint32 v)
{
double sbasXg_Yg = (double)((gint32)v)*0.08;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m (%d)", sbasXg_Yg, (gint32)v);
}
static void
lpp_sbasZg_fmt(gchar *s, guint32 v)
{
double sbasZg = (double)((gint32)v)*0.4;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m (%d)", sbasZg, (gint32)v);
}
static void
lpp_sbasXgDot_YgDot_fmt(gchar *s, guint32 v)
{
double sbasXgDot_YgDot = (double)((gint32)v)*0.000625;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m/s (%d)", sbasXgDot_YgDot, (gint32)v);
}
static void
lpp_sbasZgDot_fmt(gchar *s, guint32 v)
{
double sbasZgDot = (double)((gint32)v)*0.004;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m/s (%d)", sbasZgDot, (gint32)v);
}
static void
lpp_sbasXgDotDot_YgDotDot_fmt(gchar *s, guint32 v)
{
double sbasXgDotDot_YgDotDot = (double)((gint32)v)*0.0000125;
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m/s2 (%d)", sbasXgDotDot_YgDotDot, (gint32)v);
}
static void
lpp_sbasZgDotDot_fmt(gchar *s, guint32 v)
{
double sbasZgDotDot = (double)((gint32)v)*0.0000625;
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m/s2 (%d)", sbasZgDotDot, (gint32)v);
}
static void
lpp_bdsAPowerHalf_r12_fmt(gchar *s, guint32 v)
{
double bdsAPowerHalf = (double)v*pow(2, -19);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m1/2 (%u)", bdsAPowerHalf, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g rad (%d)", bdsCuc_Cus_Cic_Cis, (gint32)v);
}
static void
lpp_bdsCrc_Crs_r12_fmt(gchar *s, guint32 v)
{
double bdsCrc_Crs = (double)((gint32)v)*pow(2, -6);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g rad (%d)", bdsCrc_Crs, (gint32)v);
}
static void
lpp_doppler0_fmt(gchar *s, guint32 v)
{
double doppler0 = (double)((gint32)v)*0.5;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m/s (%d)", doppler0, (gint32)v);
}
static void
lpp_doppler1_fmt(gchar *s, guint32 v)
{
double doppler1 = (double)((gint32)(v-42))/210;
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m/s2 (%u)", doppler1, v);
}
static void
lpp_codePhase_fmt(gchar *s, guint32 v)
{
double codePhase = (double)v*pow(2, -10);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g ms (%u)", codePhase, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m1/2 (%d)", kepAlmanacAPowerHalf, (gint32)v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", kepAlmanacAF0, (gint32)v);
}
static void
lpp_kepAlmanacAF1_fmt(gchar *s, guint32 v)
{
double kepAlmanacAF1 = (double)((gint32)v)*pow(2, -38);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", kepAlmanacAF1, (gint32)v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m1/2 (%u)", navAlmSqrtA, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", navAlmaf0, (gint32)v);
}
static void
lpp_navAlmaf1_fmt(gchar *s, guint32 v)
{
double navAlmaf1 = (double)((gint32)v)*pow(2, -38);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", navAlmaf1, (gint32)v);
}
static void
lpp_redAlmDeltaA_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d m (%d)", 512*(gint)v, (gint)v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m1/2 (%u)", (float)v*0.0625, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", midiAlmaf0, (gint32)v);
}
static void
lpp_midiAlmaf1_fmt(gchar *s, guint32 v)
{
double midiAlmaf1 = (double)((gint32)v)*pow(2, -37);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", midiAlmaf1, (gint32)v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%f s (%u)", (float)v*0.03125, v);
}
static void
lpp_gloAlmDeltaTA_fmt(gchar *s, guint32 v)
{
double gloAlmDeltaTA = (double)((gint32)v)*pow(2, -9);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/orbit period (%d)", gloAlmDeltaTA, (gint32)v);
}
static void
lpp_gloAlmDeltaTdotA_fmt(gchar *s, guint32 v)
{
double gloAlmDeltaTdotA = (double)((gint32)v)*pow(2, -14);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/orbit period (%d)", gloAlmDeltaTdotA, (gint32)v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", gloAlmTauA, (gint32)v);
}
static void
lpp_sbasAlmXg_Yg_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%f km (%d)", (gint32)v*2.6, (gint32)v);
}
static void
lpp_sbasAlmZg_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d km (%d)", (gint32)v*26, (gint32)v);
}
static void
lpp_sbasAlmXgdot_YgDot_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d m/s (%d)", (gint32)v*10, (gint32)v);
}
static void
lpp_sbasAlmZgDot_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%f m/s (%d)", (gint32)v*40.96, (gint32)v);
}
static void
lpp_sbasAlmTo_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u m/s (%u)", v*64, v);
}
static void
lpp_bdsAlmToa_r12_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", v*4096, v);
}
static void
lpp_bdsAlmSqrtA_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmSqrtA = (double)v*pow(2, -11);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m1/2 (%u)", bdsAlmSqrtA, v);
}
static void
lpp_bdsAlmE_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmE = (double)v*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m1/2 (%u)", bdsAlmE, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", bdsAlmA0, (gint32)v);
}
static void
lpp_bdsAlmA1_r12_fmt(gchar *s, guint32 v)
{
double bdsAlmA1 = (double)((gint32)v)*pow(2, -38);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", bdsAlmA1, (gint32)v);
}
static void
lpp_gnss_Utc_A1_fmt(gchar *s, guint32 v)
{
double gnss_Utc_A1 = (double)((gint32)v)*pow(2, -50);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/s (%d)", gnss_Utc_A1, (gint32)v);
}
static void
lpp_gnss_Utc_A0_fmt(gchar *s, guint32 v)
{
double gnss_Utc_A0 = (double)((gint32)v)*pow(2, -30);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", gnss_Utc_A0, (gint32)v);
}
static void
lpp_gnss_Utc_Tot_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%u s (%u)", v*4096, v);
}
static void
lpp_bds_ECC_DeltaT_r12_fmt(gchar *s, guint32 v)
{
if ((gint32)v == -4096) {
g_snprintf(s, ITEM_LABEL_LENGTH, "Not available (%d)", (gint32)v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m (%d)", (float)((gint32)v)*0.1, (gint32)v);
}
}
static void
lpp_bds_GridIonElement_dt_r12_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m (%d)", (float)((gint32)v)*0.125, (gint32)v);
}
static void
lpp_tauC_fmt(gchar *s, guint32 v)
{
double tauC = (double)((gint32)v)*pow(2, -31);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", tauC, (gint32)v);
}
static void
lpp_b1_fmt(gchar *s, guint32 v)
{
double b1 = (double)((gint32)v)*pow(2, -10);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s (%d)", b1, (gint32)v);
}
static void
lpp_b2_fmt(gchar *s, guint32 v)
{
double b2 = (double)((gint32)v)*pow(2, -16);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g s/msd (%d)", b2, (gint32)v);
}
static void
lpp_GNSS_SatMeas_codePhase_fmt(gchar *s, guint32 v)
{
double codePhase = (double)v*pow(2, -21);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g ms (%u)", codePhase, v);
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
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m/s (%d)", (gint32)v*0.04, (gint32)v);
}
static void
lpp_adr_fmt(gchar *s, guint32 v)
{
double adr = (double)v*pow(2, -10);
g_snprintf(s, ITEM_LABEL_LENGTH, "%g m (%u)", adr, v);
}
static void
lpp_rsrp_Result_fmt(gchar *s, guint32 v)
{
g_snprintf(s, ITEM_LABEL_LENGTH, "%d dBm (%u)", v-140, v);
}
static void
lpp_rsrq_Result_fmt(gchar *s, guint32 v)
{
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "RSRQ < -19.5 dB (0)");
} else if (v < 34) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%.1f dB <= RSRQ < %.1f dB (%u)", ((float)v/2)-20, (((float)v+1)/2)-20, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "-3 dB <= RSRQ (34)");
}
}
static void
lpp_ue_RxTxTimeDiff_fmt(gchar *s, guint32 v)
{
if (v == 0) {
g_snprintf(s, ITEM_LABEL_LENGTH, "T < 2 Ts (0)");
} else if (v < 2048) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u Ts <= T < %u Ts (%u)", v*2, (v+1)*2, v);
} else if (v < 4095) {
g_snprintf(s, ITEM_LABEL_LENGTH, "%u Ts <= T < %u Ts (%u)", (v*8)-12288, ((v+1)*8)-12288, v);
} else {
g_snprintf(s, ITEM_LABEL_LENGTH, "20472 Ts <= T (4095)");
}
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
#include "packet-lpp-hfarr.c"
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
#include "packet-lpp-ettarr.c"
};
proto_lpp = proto_register_protocol(PNAME, PSNAME, PFNAME);
new_register_dissector("lpp", dissect_lpp, proto_lpp);
proto_register_field_array(proto_lpp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_lpp(void)
{
lppe_handle = find_dissector("lppe");
}
