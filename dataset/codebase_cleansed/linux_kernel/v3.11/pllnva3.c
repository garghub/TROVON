int
nva3_pll_calc(struct nouveau_subdev *subdev, struct nvbios_pll *info,
u32 freq, int *pN, int *pfN, int *pM, int *P)
{
u32 best_err = ~0, err;
int M, lM, hM, N, fN;
*P = info->vco1.max_freq / freq;
if (*P > info->max_p)
*P = info->max_p;
if (*P < info->min_p)
*P = info->min_p;
lM = (info->refclk + info->vco1.max_inputfreq) / info->vco1.max_inputfreq;
lM = max(lM, (int)info->vco1.min_m);
hM = (info->refclk + info->vco1.min_inputfreq) / info->vco1.min_inputfreq;
hM = min(hM, (int)info->vco1.max_m);
for (M = lM; M <= hM; M++) {
u32 tmp = freq * *P * M;
N = tmp / info->refclk;
fN = tmp % info->refclk;
if (!pfN) {
if (fN >= info->refclk / 2)
N++;
} else {
if (fN < info->refclk / 2)
N--;
fN = tmp - (N * info->refclk);
}
if (N < info->vco1.min_n)
continue;
if (N > info->vco1.max_n)
break;
err = abs(freq - (info->refclk * N / M / *P));
if (err < best_err) {
best_err = err;
*pN = N;
*pM = M;
}
if (pfN) {
*pfN = ((fN << 13) + info->refclk / 2) / info->refclk;
*pfN = (*pfN - 4096) & 0xffff;
return freq;
}
}
if (unlikely(best_err == ~0)) {
nv_error(subdev, "unable to find matching pll values\n");
return -EINVAL;
}
return info->refclk * *pN / *pM / *P;
}
