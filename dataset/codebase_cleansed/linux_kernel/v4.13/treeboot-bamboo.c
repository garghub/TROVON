static void read_pibs_mac(void)
{
unsigned long long mac64;
mac64 = strtoull((char *)PIBS_MAC0, 0, 16);
memcpy(&pibs_mac0, (char *)&mac64+2, 6);
mac64 = strtoull((char *)PIBS_MAC1, 0, 16);
memcpy(&pibs_mac1, (char *)&mac64+2, 6);
}
void platform_init(void)
{
unsigned long end_of_ram = 0x8000000;
unsigned long avail_ram = end_of_ram - (unsigned long)_end;
simple_alloc_init(_end, avail_ram, 32, 64);
read_pibs_mac();
bamboo_init((u8 *)&pibs_mac0, (u8 *)&pibs_mac1);
}
