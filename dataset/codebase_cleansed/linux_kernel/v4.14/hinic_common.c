void hinic_cpu_to_be32(void *data, int len)
{
u32 *mem = data;
int i;
len = len / sizeof(u32);
for (i = 0; i < len; i++) {
*mem = cpu_to_be32(*mem);
mem++;
}
}
void hinic_be32_to_cpu(void *data, int len)
{
u32 *mem = data;
int i;
len = len / sizeof(u32);
for (i = 0; i < len; i++) {
*mem = be32_to_cpu(*mem);
mem++;
}
}
void hinic_set_sge(struct hinic_sge *sge, dma_addr_t addr, int len)
{
sge->hi_addr = upper_32_bits(addr);
sge->lo_addr = lower_32_bits(addr);
sge->len = len;
}
dma_addr_t hinic_sge_to_dma(struct hinic_sge *sge)
{
return (dma_addr_t)((((u64)sge->hi_addr) << 32) | sge->lo_addr);
}
