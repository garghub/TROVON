static void __init
fixup_clep7312(struct tag *tags, char **cmdline)
{
memblock_add(0xc0000000, 0x01000000);
}
