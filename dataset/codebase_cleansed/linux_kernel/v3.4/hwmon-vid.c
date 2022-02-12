int vid_from_reg(int val, u8 vrm)
{
int vid;
switch (vrm) {
case 100:
val &= 0x3f;
if ((val & 0x1f) == 0x1f)
return 0;
if ((val & 0x1f) <= 0x09 || val == 0x0a)
vid = 1087500 - (val & 0x1f) * 25000;
else
vid = 1862500 - (val & 0x1f) * 25000;
if (val & 0x20)
vid -= 12500;
return (vid + 500) / 1000;
case 110:
val &= 0xff;
if (val < 0x02 || val > 0xb2)
return 0;
return (1600000 - (val - 2) * 6250 + 500) / 1000;
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
return val == 0x1f ? 0 :
1850 - val * 25;
case 85:
val &= 0x1f;
return (val & 0x10 ? 25 : 0) +
((val & 0x0f) > 0x04 ? 2050 : 1250) -
((val & 0x0f) * 50);
case 84:
val &= 0x0f;
case 82:
val &= 0x1f;
return val == 0x1f ? 0 :
val & 0x10 ? 5100 - (val) * 100 :
2050 - (val) * 50;
case 17:
val &= 0x1f;
return val & 0x10 ? 975 - (val & 0xF) * 25 :
1750 - val * 50;
case 13:
case 131:
val &= 0x3f;
if (vrm == 131 && val == 0x3f)
val++;
return 1708 - val * 16;
case 14:
val &= 0x7f;
return val > 0x77 ? 0 : (1500000 - (val * 12500) + 500) / 1000;
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
static u8 find_vrm(u8 family, u8 model, u8 stepping, u8 vendor)
{
int i;
for (i = 0; i < ARRAY_SIZE(vrm_models); i++) {
if (vendor == vrm_models[i].vendor &&
family == vrm_models[i].family &&
model >= vrm_models[i].model_from &&
model <= vrm_models[i].model_to &&
stepping <= vrm_models[i].stepping_to)
return vrm_models[i].vrm_type;
}
return 0;
}
u8 vid_which_vrm(void)
{
struct cpuinfo_x86 *c = &cpu_data(0);
u8 vrm_ret;
if (c->x86 < 6)
return 0;
vrm_ret = find_vrm(c->x86, c->x86_model, c->x86_mask, c->x86_vendor);
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
