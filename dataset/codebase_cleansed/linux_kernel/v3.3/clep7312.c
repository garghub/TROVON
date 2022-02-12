static void __init
fixup_clep7312(struct tag *tags, char **cmdline, struct meminfo *mi)
{
mi->nr_banks=1;
mi->bank[0].start = 0xc0000000;
mi->bank[0].size = 0x01000000;
}
