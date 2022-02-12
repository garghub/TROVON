int pp_override_get_default_fuse_value(uint64_t key,
struct phm_fuses_default list[],
struct phm_fuses_default *result)
{
uint32_t i;
uint64_t temp_serial_numer;
uint32_t bit;
const char *temp;
for (i = 0; list[i].key != NULL; i++) {
temp = list[i].key;
temp_serial_numer = 0;
do {
bit = *temp=='1'? 1 : 0;
temp_serial_numer = (temp_serial_numer <<1 ) | bit;
temp++;
} while (*temp);
if (key == temp_serial_numer) {
result->key = list[i].key;
result->VFT2_m1 = list[i].VFT2_m1;
result->VFT2_m2 = list[i].VFT2_m2;
result->VFT2_b = list[i].VFT2_b;
result->VFT1_m1 = list[i].VFT1_m1;
result->VFT1_m2 = list[i].VFT1_m2;
result->VFT1_b = list[i].VFT1_b;
result->VFT0_m1 = list[i].VFT0_m1;
result->VFT0_m2 = list[i].VFT0_m2;
result->VFT0_b = list[i].VFT0_b;
return 0;
}
}
return -EINVAL;
}
