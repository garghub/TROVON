void gdm_set_endian(struct gdm_endian *ed, u8 dev_endian)
{
if (dev_endian == ENDIANNESS_BIG)
ed->dev_ed = ENDIANNESS_BIG;
else
ed->dev_ed = ENDIANNESS_LITTLE;
}
__dev16 gdm_cpu_to_dev16(struct gdm_endian *ed, u16 x)
{
if (ed->dev_ed == ENDIANNESS_LITTLE)
return (__force __dev16)cpu_to_le16(x);
else
return (__force __dev16)cpu_to_be16(x);
}
u16 gdm_dev16_to_cpu(struct gdm_endian *ed, __dev16 x)
{
if (ed->dev_ed == ENDIANNESS_LITTLE)
return le16_to_cpu((__force __le16)x);
else
return be16_to_cpu((__force __be16)x);
}
__dev32 gdm_cpu_to_dev32(struct gdm_endian *ed, u32 x)
{
if (ed->dev_ed == ENDIANNESS_LITTLE)
return (__force __dev32)cpu_to_le32(x);
else
return (__force __dev32)cpu_to_be32(x);
}
u32 gdm_dev32_to_cpu(struct gdm_endian *ed, __dev32 x)
{
if (ed->dev_ed == ENDIANNESS_LITTLE)
return le32_to_cpu((__force __le32)x);
else
return be32_to_cpu((__force __be32)x);
}
