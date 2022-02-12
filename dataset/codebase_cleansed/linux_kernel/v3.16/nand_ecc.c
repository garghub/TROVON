void __nand_calculate_ecc(const unsigned char *buf, unsigned int eccsize,
unsigned char *code)
{
int i;
const uint32_t *bp = (uint32_t *)buf;
const uint32_t eccsize_mult = eccsize >> 8;
uint32_t cur;
uint32_t rp0, rp1, rp2, rp3, rp4, rp5, rp6, rp7;
uint32_t rp8, rp9, rp10, rp11, rp12, rp13, rp14, rp15, rp16;
uint32_t uninitialized_var(rp17);
uint32_t par;
uint32_t tmppar;
par = 0;
rp4 = 0;
rp6 = 0;
rp8 = 0;
rp10 = 0;
rp12 = 0;
rp14 = 0;
rp16 = 0;
for (i = 0; i < eccsize_mult << 2; i++) {
cur = *bp++;
tmppar = cur;
rp4 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp6 ^= tmppar;
cur = *bp++;
tmppar ^= cur;
rp4 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp8 ^= tmppar;
cur = *bp++;
tmppar ^= cur;
rp4 ^= cur;
rp6 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp6 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp4 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp10 ^= tmppar;
cur = *bp++;
tmppar ^= cur;
rp4 ^= cur;
rp6 ^= cur;
rp8 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp6 ^= cur;
rp8 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp4 ^= cur;
rp8 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp8 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp4 ^= cur;
rp6 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp6 ^= cur;
cur = *bp++;
tmppar ^= cur;
rp4 ^= cur;
cur = *bp++;
tmppar ^= cur;
par ^= tmppar;
if ((i & 0x1) == 0)
rp12 ^= tmppar;
if ((i & 0x2) == 0)
rp14 ^= tmppar;
if (eccsize_mult == 2 && (i & 0x4) == 0)
rp16 ^= tmppar;
}
rp4 ^= (rp4 >> 16);
rp4 ^= (rp4 >> 8);
rp4 &= 0xff;
rp6 ^= (rp6 >> 16);
rp6 ^= (rp6 >> 8);
rp6 &= 0xff;
rp8 ^= (rp8 >> 16);
rp8 ^= (rp8 >> 8);
rp8 &= 0xff;
rp10 ^= (rp10 >> 16);
rp10 ^= (rp10 >> 8);
rp10 &= 0xff;
rp12 ^= (rp12 >> 16);
rp12 ^= (rp12 >> 8);
rp12 &= 0xff;
rp14 ^= (rp14 >> 16);
rp14 ^= (rp14 >> 8);
rp14 &= 0xff;
if (eccsize_mult == 2) {
rp16 ^= (rp16 >> 16);
rp16 ^= (rp16 >> 8);
rp16 &= 0xff;
}
#ifdef __BIG_ENDIAN
rp2 = (par >> 16);
rp2 ^= (rp2 >> 8);
rp2 &= 0xff;
rp3 = par & 0xffff;
rp3 ^= (rp3 >> 8);
rp3 &= 0xff;
#else
rp3 = (par >> 16);
rp3 ^= (rp3 >> 8);
rp3 &= 0xff;
rp2 = par & 0xffff;
rp2 ^= (rp2 >> 8);
rp2 &= 0xff;
#endif
par ^= (par >> 16);
#ifdef __BIG_ENDIAN
rp0 = (par >> 8) & 0xff;
rp1 = (par & 0xff);
#else
rp1 = (par >> 8) & 0xff;
rp0 = (par & 0xff);
#endif
par ^= (par >> 8);
par &= 0xff;
rp5 = (par ^ rp4) & 0xff;
rp7 = (par ^ rp6) & 0xff;
rp9 = (par ^ rp8) & 0xff;
rp11 = (par ^ rp10) & 0xff;
rp13 = (par ^ rp12) & 0xff;
rp15 = (par ^ rp14) & 0xff;
if (eccsize_mult == 2)
rp17 = (par ^ rp16) & 0xff;
#ifdef CONFIG_MTD_NAND_ECC_SMC
code[0] =
(invparity[rp7] << 7) |
(invparity[rp6] << 6) |
(invparity[rp5] << 5) |
(invparity[rp4] << 4) |
(invparity[rp3] << 3) |
(invparity[rp2] << 2) |
(invparity[rp1] << 1) |
(invparity[rp0]);
code[1] =
(invparity[rp15] << 7) |
(invparity[rp14] << 6) |
(invparity[rp13] << 5) |
(invparity[rp12] << 4) |
(invparity[rp11] << 3) |
(invparity[rp10] << 2) |
(invparity[rp9] << 1) |
(invparity[rp8]);
#else
code[1] =
(invparity[rp7] << 7) |
(invparity[rp6] << 6) |
(invparity[rp5] << 5) |
(invparity[rp4] << 4) |
(invparity[rp3] << 3) |
(invparity[rp2] << 2) |
(invparity[rp1] << 1) |
(invparity[rp0]);
code[0] =
(invparity[rp15] << 7) |
(invparity[rp14] << 6) |
(invparity[rp13] << 5) |
(invparity[rp12] << 4) |
(invparity[rp11] << 3) |
(invparity[rp10] << 2) |
(invparity[rp9] << 1) |
(invparity[rp8]);
#endif
if (eccsize_mult == 1)
code[2] =
(invparity[par & 0xf0] << 7) |
(invparity[par & 0x0f] << 6) |
(invparity[par & 0xcc] << 5) |
(invparity[par & 0x33] << 4) |
(invparity[par & 0xaa] << 3) |
(invparity[par & 0x55] << 2) |
3;
else
code[2] =
(invparity[par & 0xf0] << 7) |
(invparity[par & 0x0f] << 6) |
(invparity[par & 0xcc] << 5) |
(invparity[par & 0x33] << 4) |
(invparity[par & 0xaa] << 3) |
(invparity[par & 0x55] << 2) |
(invparity[rp17] << 1) |
(invparity[rp16] << 0);
}
int nand_calculate_ecc(struct mtd_info *mtd, const unsigned char *buf,
unsigned char *code)
{
__nand_calculate_ecc(buf,
((struct nand_chip *)mtd->priv)->ecc.size, code);
return 0;
}
int __nand_correct_data(unsigned char *buf,
unsigned char *read_ecc, unsigned char *calc_ecc,
unsigned int eccsize)
{
unsigned char b0, b1, b2, bit_addr;
unsigned int byte_addr;
const uint32_t eccsize_mult = eccsize >> 8;
#ifdef CONFIG_MTD_NAND_ECC_SMC
b0 = read_ecc[0] ^ calc_ecc[0];
b1 = read_ecc[1] ^ calc_ecc[1];
#else
b0 = read_ecc[1] ^ calc_ecc[1];
b1 = read_ecc[0] ^ calc_ecc[0];
#endif
b2 = read_ecc[2] ^ calc_ecc[2];
if ((b0 | b1 | b2) == 0)
return 0;
if ((((b0 ^ (b0 >> 1)) & 0x55) == 0x55) &&
(((b1 ^ (b1 >> 1)) & 0x55) == 0x55) &&
((eccsize_mult == 1 && ((b2 ^ (b2 >> 1)) & 0x54) == 0x54) ||
(eccsize_mult == 2 && ((b2 ^ (b2 >> 1)) & 0x55) == 0x55))) {
if (eccsize_mult == 1)
byte_addr = (addressbits[b1] << 4) + addressbits[b0];
else
byte_addr = (addressbits[b2 & 0x3] << 8) +
(addressbits[b1] << 4) + addressbits[b0];
bit_addr = addressbits[b2 >> 2];
buf[byte_addr] ^= (1 << bit_addr);
return 1;
}
if ((bitsperbyte[b0] + bitsperbyte[b1] + bitsperbyte[b2]) == 1)
return 1;
pr_err("%s: uncorrectable ECC error\n", __func__);
return -1;
}
int nand_correct_data(struct mtd_info *mtd, unsigned char *buf,
unsigned char *read_ecc, unsigned char *calc_ecc)
{
return __nand_correct_data(buf, read_ecc, calc_ecc,
((struct nand_chip *)mtd->priv)->ecc.size);
}
