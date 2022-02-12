void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,
unsigned long r6, unsigned long r7)
{
CUBOOT_INIT();
bamboo_init(&bd.bi_enetaddr, &bd.bi_enet1addr);
}
