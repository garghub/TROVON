static int
getMNP_single(struct nouveau_clock *clock, struct nvbios_pll *info, int clk,
int *pN, int *pM, int *pP)
{
int cv = nouveau_bios(clock)->version.chip;
int minvco = info->vco1.min_freq, maxvco = info->vco1.max_freq;
int minM = info->vco1.min_m, maxM = info->vco1.max_m;
int minN = info->vco1.min_n, maxN = info->vco1.max_n;
int minU = info->vco1.min_inputfreq;
int maxU = info->vco1.max_inputfreq;
int minP = info->min_p;
int maxP = info->max_p_usable;
int crystal = info->refclk;
int M, N, thisP, P;
int clkP, calcclk;
int delta, bestdelta = INT_MAX;
int bestclk = 0;
if (cv < 0x17 || cv == 0x1a || cv == 0x20) {
if (clk > 250000)
maxM = 6;
if (clk > 340000)
maxM = 2;
} else if (cv < 0x40) {
if (clk > 150000)
maxM = 6;
if (clk > 200000)
maxM = 4;
if (clk > 340000)
maxM = 2;
}
P = 1 << maxP;
if ((clk * P) < minvco) {
minvco = clk * maxP;
maxvco = minvco * 2;
}
if (clk + clk/200 > maxvco)
maxvco = clk + clk/200;
for (thisP = minP; thisP <= maxP; thisP++) {
P = 1 << thisP;
clkP = clk * P;
if (clkP < minvco)
continue;
if (clkP > maxvco)
return bestclk;
for (M = minM; M <= maxM; M++) {
if (crystal/M < minU)
return bestclk;
if (crystal/M > maxU)
continue;
N = (clkP * M + crystal/2) / crystal;
if (N < minN)
continue;
if (N > maxN)
break;
calcclk = ((N * crystal + P/2) / P + M/2) / M;
delta = abs(calcclk - clk);
if (delta < bestdelta) {
bestdelta = delta;
bestclk = calcclk;
*pN = N;
*pM = M;
*pP = thisP;
if (delta == 0)
return bestclk;
}
}
}
return bestclk;
}
static int
getMNP_double(struct nouveau_clock *clock, struct nvbios_pll *info, int clk,
int *pN1, int *pM1, int *pN2, int *pM2, int *pP)
{
int chip_version = nouveau_bios(clock)->version.chip;
int minvco1 = info->vco1.min_freq, maxvco1 = info->vco1.max_freq;
int minvco2 = info->vco2.min_freq, maxvco2 = info->vco2.max_freq;
int minU1 = info->vco1.min_inputfreq, minU2 = info->vco2.min_inputfreq;
int maxU1 = info->vco1.max_inputfreq, maxU2 = info->vco2.max_inputfreq;
int minM1 = info->vco1.min_m, maxM1 = info->vco1.max_m;
int minN1 = info->vco1.min_n, maxN1 = info->vco1.max_n;
int minM2 = info->vco2.min_m, maxM2 = info->vco2.max_m;
int minN2 = info->vco2.min_n, maxN2 = info->vco2.max_n;
int maxlog2P = info->max_p_usable;
int crystal = info->refclk;
bool fixedgain2 = (minM2 == maxM2 && minN2 == maxN2);
int M1, N1, M2, N2, log2P;
int clkP, calcclk1, calcclk2, calcclkout;
int delta, bestdelta = INT_MAX;
int bestclk = 0;
int vco2 = (maxvco2 - maxvco2/200) / 2;
for (log2P = 0; clk && log2P < maxlog2P && clk <= (vco2 >> log2P); log2P++)
;
clkP = clk << log2P;
if (maxvco2 < clk + clk/200)
maxvco2 = clk + clk/200;
for (M1 = minM1; M1 <= maxM1; M1++) {
if (crystal/M1 < minU1)
return bestclk;
if (crystal/M1 > maxU1)
continue;
for (N1 = minN1; N1 <= maxN1; N1++) {
calcclk1 = crystal * N1 / M1;
if (calcclk1 < minvco1)
continue;
if (calcclk1 > maxvco1)
break;
for (M2 = minM2; M2 <= maxM2; M2++) {
if (calcclk1/M2 < minU2)
break;
if (calcclk1/M2 > maxU2)
continue;
N2 = (clkP * M2 + calcclk1/2) / calcclk1;
if (N2 < minN2)
continue;
if (N2 > maxN2)
break;
if (!fixedgain2) {
if (chip_version < 0x60)
if (N2/M2 < 4 || N2/M2 > 10)
continue;
calcclk2 = calcclk1 * N2 / M2;
if (calcclk2 < minvco2)
break;
if (calcclk2 > maxvco2)
continue;
} else
calcclk2 = calcclk1;
calcclkout = calcclk2 >> log2P;
delta = abs(calcclkout - clk);
if (delta < bestdelta) {
bestdelta = delta;
bestclk = calcclkout;
*pN1 = N1;
*pM1 = M1;
*pN2 = N2;
*pM2 = M2;
*pP = log2P;
if (delta == 0)
return bestclk;
}
}
}
}
return bestclk;
}
int
nv04_pll_calc(struct nouveau_clock *clk, struct nvbios_pll *info, u32 freq,
int *N1, int *M1, int *N2, int *M2, int *P)
{
int ret;
if (!info->vco2.max_freq) {
ret = getMNP_single(clk, info, freq, N1, M1, P);
*N2 = 1;
*M2 = 1;
} else {
ret = getMNP_double(clk, info, freq, N1, M1, N2, M2, P);
}
if (!ret)
nv_error(clk, "unable to compute acceptable pll values\n");
return ret;
}
