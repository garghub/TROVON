unsigned long icst_hz(const struct icst_params *p, struct icst_vco vco)
{
return p->ref * 2 * (vco.v + 8) / ((vco.r + 2) * p->s2div[vco.s]);
}
struct icst_vco
icst_hz_to_vco(const struct icst_params *p, unsigned long freq)
{
struct icst_vco vco = { .s = 1, .v = p->vd_max, .r = p->rd_max };
unsigned long f;
unsigned int i = 0, rd, best = (unsigned int)-1;
do {
f = freq * p->s2div[p->idx2s[i]];
if (f > p->vco_min && f <= p->vco_max)
break;
} while (i < 8);
if (i >= 8)
return vco;
vco.s = p->idx2s[i];
for (rd = p->rd_min; rd <= p->rd_max; rd++) {
unsigned long fref_div, f_pll;
unsigned int vd;
int f_diff;
fref_div = (2 * p->ref) / rd;
vd = (f + fref_div / 2) / fref_div;
if (vd < p->vd_min || vd > p->vd_max)
continue;
f_pll = fref_div * vd;
f_diff = f_pll - f;
if (f_diff < 0)
f_diff = -f_diff;
if ((unsigned)f_diff < best) {
vco.v = vd - 8;
vco.r = rd - 2;
if (f_diff == 0)
break;
best = f_diff;
}
}
return vco;
}
