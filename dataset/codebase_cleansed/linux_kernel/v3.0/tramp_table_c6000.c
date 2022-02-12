static u32 tramp_size_get(void)
{
return sizeof(u32) * C6X_TRAMP_WORD_COUNT;
}
static u32 tramp_img_pkt_size_get(void)
{
return sizeof(struct c6000_gen_code);
}
