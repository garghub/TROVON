void split_cdb_XX_6(
unsigned long long lba,
u32 sectors,
unsigned char *cdb)
{
cdb[1] = (lba >> 16) & 0x1f;
cdb[2] = (lba >> 8) & 0xff;
cdb[3] = lba & 0xff;
cdb[4] = sectors & 0xff;
}
void split_cdb_XX_10(
unsigned long long lba,
u32 sectors,
unsigned char *cdb)
{
put_unaligned_be32(lba, &cdb[2]);
put_unaligned_be16(sectors, &cdb[7]);
}
void split_cdb_XX_12(
unsigned long long lba,
u32 sectors,
unsigned char *cdb)
{
put_unaligned_be32(lba, &cdb[2]);
put_unaligned_be32(sectors, &cdb[6]);
}
void split_cdb_XX_16(
unsigned long long lba,
u32 sectors,
unsigned char *cdb)
{
put_unaligned_be64(lba, &cdb[2]);
put_unaligned_be32(sectors, &cdb[10]);
}
void split_cdb_XX_32(
unsigned long long lba,
u32 sectors,
unsigned char *cdb)
{
put_unaligned_be64(lba, &cdb[12]);
put_unaligned_be32(sectors, &cdb[28]);
}
