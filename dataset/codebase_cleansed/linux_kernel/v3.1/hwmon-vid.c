int vid_from_reg(int val, u8 vrm)
{
int vid;
switch(vrm) {
case 100:
val &= 0x3f;
if((val & 0x1f) == 0x1f)
return 0;
if((val & 0x1f) <= 0x09 || val == 0x0a)
vid = 1087500 - (val & 0x1f) * 25000;
else
vid = 1862500 - (val & 0x1f) * 25000;
if(val & 0x20)
vid -= 12500;
return((vid + 500) / 1000);
case 110:
val &= 0xff;
if (val < 0x02 || val > 0xb2)
return 0;
return((1600000 - (val - 2) * 6250 + 500) / 1000);
case 24:
val &= 0x1f;
if (val == 0x1f)
return 0;
case 25:
val &= 0x3f;
return (val < 32) ? 1550 - 25 * val
: 775 - (25 * (val - 31)) / 2;
case 91:
case 90:
val &= 0x1f;
return(val == 0x1f ? 0 :
1850 - val * 25);
case 85:
val &= 0x1f;
return((val & 0x10 ? 25 : 0) +
((val & 0x0f) > 0x04 ? 2050 : 1250) -
((val & 0x0f) * 50));
case 84:
val &= 0x0f;
case 82:
val &= 0x1f;
return(val == 0x1f ? 0 :
val & 0x10 ? 5100 - (val) * 100 :
2050 - (val) * 50);
case 17:
val &= 0x1f;
return(val & 0x10 ? 975 - (val & 0xF) * 25 :
1750 - val * 50);
case 13:
case 131:
val &= 0x3f;
if (vrm == 131 && val == 0x3f)
val++;
return(1708 - val * 16);
case 14:
val &= 0x7f;
return(val > 0x77 ? 0 : (1500000 - (val * 12500) + 500) / 1000);
default:
if (vrm)
pr_warn("Requested unsupported VRM version (%u)\n",
(unsigned int)vrm);
return 0;
}
}
static u8 get_via_model_d_vrm(void)
{
unsigned int vid, brand, dummy;
static const char *brands[4] = {
"C7-M", "C7", "Eden", "C7-D"
};
rdmsr(0x198, dummy, vid);
vid &= 0xff;
rdmsr(0x1154, brand, dummy);
brand = ((brand >> 4) ^ (brand >> 2)) & 0x03;
if (vid > 0x3f) {
pr_info("Using %d-bit VID table for VIA %s CPU\n",
7, brands[brand]);
return 14;
} else {
pr_info("Using %d-bit VID table for VIA %s CPU\n",
6, brands[brand]);
return brand == 2 ? 131 : 13;
}
}
static u8 find_vrm(u8 eff_family, u8 eff_model, u8 eff_stepping, u8 vendor)
{
int i = 0;
while (vrm_models[i].vendor!=X86_VENDOR_UNKNOWN) {
if (vrm_models[i].vendor==vendor)
if ((vrm_models[i].eff_family==eff_family)
&& ((vrm_models[i].eff_model==eff_model) ||
(vrm_models[i].eff_model >= 0x10 &&
eff_model <= vrm_models[i].eff_model) ||
(vrm_models[i].eff_model==ANY)) &&
(eff_stepping <= vrm_models[i].eff_stepping))
return vrm_models[i].vrm_type;
i++;
}
return 0;
}
u8 vid_which_vrm(void)
{
struct cpuinfo_x86 *c = &cpu_data(0);
u32 eax;
u8 eff_family, eff_model, eff_stepping, vrm_ret;
if (c->x86 < 6)
return 0;
eax = cpuid_eax(1);
eff_family = ((eax & 0x00000F00)>>8);
eff_model = ((eax & 0x000000F0)>>4);
eff_stepping = eax & 0xF;
if (eff_family == 0xF) {
eff_family += ((eax & 0x00F00000)>>20);
eff_model += ((eax & 0x000F0000)>>16)<<4;
}
vrm_ret = find_vrm(eff_family, eff_model, eff_stepping, c->x86_vendor);
if (vrm_ret == 134)
vrm_ret = get_via_model_d_vrm();
if (vrm_ret == 0)
pr_info("Unknown VRM version of your x86 CPU\n");
return vrm_ret;
}
u8 vid_which_vrm(void)
{
pr_info("Unknown VRM version of your CPU\n");
return 0;
}
