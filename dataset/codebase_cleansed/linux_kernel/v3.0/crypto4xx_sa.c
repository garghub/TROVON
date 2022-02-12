u32 get_dynamic_sa_offset_iv_field(struct crypto4xx_ctx *ctx)
{
u32 offset;
union dynamic_sa_contents cts;
if (ctx->direction == DIR_INBOUND)
cts.w = ((struct dynamic_sa_ctl *)(ctx->sa_in))->sa_contents;
else
cts.w = ((struct dynamic_sa_ctl *)(ctx->sa_out))->sa_contents;
offset = cts.bf.key_size
+ cts.bf.inner_size
+ cts.bf.outer_size
+ cts.bf.spi
+ cts.bf.seq_num0
+ cts.bf.seq_num1
+ cts.bf.seq_num_mask0
+ cts.bf.seq_num_mask1
+ cts.bf.seq_num_mask2
+ cts.bf.seq_num_mask3;
return sizeof(struct dynamic_sa_ctl) + offset * 4;
}
u32 get_dynamic_sa_offset_state_ptr_field(struct crypto4xx_ctx *ctx)
{
u32 offset;
union dynamic_sa_contents cts;
if (ctx->direction == DIR_INBOUND)
cts.w = ((struct dynamic_sa_ctl *) ctx->sa_in)->sa_contents;
else
cts.w = ((struct dynamic_sa_ctl *) ctx->sa_out)->sa_contents;
offset = cts.bf.key_size
+ cts.bf.inner_size
+ cts.bf.outer_size
+ cts.bf.spi
+ cts.bf.seq_num0
+ cts.bf.seq_num1
+ cts.bf.seq_num_mask0
+ cts.bf.seq_num_mask1
+ cts.bf.seq_num_mask2
+ cts.bf.seq_num_mask3
+ cts.bf.iv0
+ cts.bf.iv1
+ cts.bf.iv2
+ cts.bf.iv3;
return sizeof(struct dynamic_sa_ctl) + offset * 4;
}
u32 get_dynamic_sa_iv_size(struct crypto4xx_ctx *ctx)
{
union dynamic_sa_contents cts;
if (ctx->direction == DIR_INBOUND)
cts.w = ((struct dynamic_sa_ctl *) ctx->sa_in)->sa_contents;
else
cts.w = ((struct dynamic_sa_ctl *) ctx->sa_out)->sa_contents;
return (cts.bf.iv0 + cts.bf.iv1 + cts.bf.iv2 + cts.bf.iv3) * 4;
}
u32 get_dynamic_sa_offset_key_field(struct crypto4xx_ctx *ctx)
{
union dynamic_sa_contents cts;
if (ctx->direction == DIR_INBOUND)
cts.w = ((struct dynamic_sa_ctl *) ctx->sa_in)->sa_contents;
else
cts.w = ((struct dynamic_sa_ctl *) ctx->sa_out)->sa_contents;
return sizeof(struct dynamic_sa_ctl);
}
