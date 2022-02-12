void platform_init(void)
{
unsigned long end_of_ram = 0x8000000;
unsigned long avail_ram = end_of_ram - (unsigned long)_end;
simple_alloc_init(_end, avail_ram, 32, 64);
ebony_init((u8 *)OPENBIOS_MAC_BASE,
(u8 *)(OPENBIOS_MAC_BASE + OPENBIOS_MAC_OFFSET));
}
