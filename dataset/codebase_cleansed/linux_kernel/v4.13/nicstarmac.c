static u_int8_t read_eprom_byte(virt_addr_t base, u_int8_t offset)
{
u_int32_t val = 0;
int i, j = 0;
u_int8_t tempread = 0;
val = NICSTAR_REG_READ(base, NICSTAR_REG_GENERAL_PURPOSE) & 0xFFFFFFF0;
for (i = 0; i < ARRAY_SIZE(readtab); i++) {
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | readtab[i]));
osp_MicroDelay(CYCLE_DELAY);
}
for (i = 7; i >= 0; i--) {
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | clocktab[j++] | ((offset >> i) & 1)));
osp_MicroDelay(CYCLE_DELAY);
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | clocktab[j++] | ((offset >> i) & 1)));
osp_MicroDelay(CYCLE_DELAY);
}
j = 0;
for (i = 7; i >= 0; i--) {
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | clocktab[j++]));
osp_MicroDelay(CYCLE_DELAY);
tempread |=
(((NICSTAR_REG_READ(base, NICSTAR_REG_GENERAL_PURPOSE)
& 0x00010000) >> 16) << i);
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | clocktab[j++]));
osp_MicroDelay(CYCLE_DELAY);
}
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE, 2);
osp_MicroDelay(CYCLE_DELAY);
return tempread;
}
static void nicstar_init_eprom(virt_addr_t base)
{
u_int32_t val;
val = NICSTAR_REG_READ(base, NICSTAR_REG_GENERAL_PURPOSE) & 0xFFFFFFF0;
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | CS_HIGH | CLK_HIGH));
osp_MicroDelay(CYCLE_DELAY);
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | CS_HIGH | CLK_LOW));
osp_MicroDelay(CYCLE_DELAY);
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | CS_HIGH | CLK_HIGH));
osp_MicroDelay(CYCLE_DELAY);
NICSTAR_REG_WRITE(base, NICSTAR_REG_GENERAL_PURPOSE,
(val | CS_HIGH | CLK_LOW));
osp_MicroDelay(CYCLE_DELAY);
}
static void
nicstar_read_eprom(virt_addr_t base,
u_int8_t prom_offset, u_int8_t * buffer, u_int32_t nbytes)
{
u_int i;
for (i = 0; i < nbytes; i++) {
buffer[i] = read_eprom_byte(base, prom_offset);
++prom_offset;
osp_MicroDelay(CYCLE_DELAY);
}
}
