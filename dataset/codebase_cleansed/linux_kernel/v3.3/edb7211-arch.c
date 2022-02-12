static void __init edb7211_reserve(void)
{
memblock_reserve(PHYS_OFFSET, 0x00020000);
}
static void __init
fixup_edb7211(struct tag *tags, char **cmdline, struct meminfo *mi)
{
mi->bank[0].start = 0xc0000000;
mi->bank[0].size = 8*1024*1024;
mi->bank[1].start = 0xc1000000;
mi->bank[1].size = 8*1024*1024;
mi->nr_banks = 2;
}
