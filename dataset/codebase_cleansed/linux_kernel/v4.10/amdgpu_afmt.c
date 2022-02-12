static void amdgpu_afmt_calc_cts(uint32_t clock, int *CTS, int *N, int freq)
{
int n, cts;
unsigned long div, mul;
n = 128 * freq;
cts = clock * 1000;
div = gcd(n, cts);
n /= div;
cts /= div;
mul = ((128*freq/1000) + (n-1))/n;
n *= mul;
cts *= mul;
if (n < (128*freq/1500))
printk(KERN_WARNING "Calculated ACR N value is too small. You may experience audio problems.\n");
if (n > (128*freq/300))
printk(KERN_WARNING "Calculated ACR N value is too large. You may experience audio problems.\n");
*N = n;
*CTS = cts;
DRM_DEBUG("Calculated ACR timing N=%d CTS=%d for frequency %d\n",
*N, *CTS, freq);
}
struct amdgpu_afmt_acr amdgpu_afmt_acr(uint32_t clock)
{
struct amdgpu_afmt_acr res;
u8 i;
for (i = 0; i < ARRAY_SIZE(amdgpu_afmt_predefined_acr); i++) {
if (amdgpu_afmt_predefined_acr[i].clock == clock)
return amdgpu_afmt_predefined_acr[i];
}
amdgpu_afmt_calc_cts(clock, &res.cts_32khz, &res.n_32khz, 32000);
amdgpu_afmt_calc_cts(clock, &res.cts_44_1khz, &res.n_44_1khz, 44100);
amdgpu_afmt_calc_cts(clock, &res.cts_48khz, &res.n_48khz, 48000);
return res;
}
