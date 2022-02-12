void __init reserve_bios_regions(void)
{
unsigned int bios_start, ebda_start;
if (!x86_platform.legacy.reserve_bios_regions)
return;
bios_start = *(unsigned short *)__va(BIOS_RAM_SIZE_KB_PTR);
bios_start <<= 10;
if (bios_start < BIOS_START_MIN || bios_start > BIOS_START_MAX)
bios_start = BIOS_START_MAX;
ebda_start = get_bios_ebda();
if (ebda_start >= BIOS_START_MIN && ebda_start < bios_start)
bios_start = ebda_start;
memblock_reserve(bios_start, 0x100000 - bios_start);
}
