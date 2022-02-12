static void coda_memcpy_parabuf(void *parabuf,
const struct coda_memcpy_desc *desc)
{
u32 *dst = parabuf + desc->offset;
const u32 *src = desc->src;
int len = desc->len / 4;
int i;
for (i = 0; i < len; i += 2) {
dst[i + 1] = swab32(src[i]);
dst[i] = swab32(src[i + 1]);
}
}
int coda_jpeg_write_tables(struct coda_ctx *ctx)
{
int i;
static const struct coda_memcpy_desc huff[8] = {
{ 0, luma_dc_bits, sizeof(luma_dc_bits) },
{ 16, luma_dc_value, sizeof(luma_dc_value) },
{ 32, luma_ac_bits, sizeof(luma_ac_bits) },
{ 48, luma_ac_value, sizeof(luma_ac_value) },
{ 216, chroma_dc_bits, sizeof(chroma_dc_bits) },
{ 232, chroma_dc_value, sizeof(chroma_dc_value) },
{ 248, chroma_ac_bits, sizeof(chroma_ac_bits) },
{ 264, chroma_ac_value, sizeof(chroma_ac_value) },
};
struct coda_memcpy_desc qmat[3] = {
{ 512, ctx->params.jpeg_qmat_tab[0], 64 },
{ 576, ctx->params.jpeg_qmat_tab[1], 64 },
{ 640, ctx->params.jpeg_qmat_tab[1], 64 },
};
for (i = 0; i < ARRAY_SIZE(huff); i++)
coda_memcpy_parabuf(ctx->parabuf.vaddr, huff + i);
for (i = 0; i < ARRAY_SIZE(qmat); i++)
coda_memcpy_parabuf(ctx->parabuf.vaddr, qmat + i);
return 0;
}
bool coda_jpeg_check_buffer(struct coda_ctx *ctx, struct vb2_v4l2_buffer *vb)
{
void *vaddr = vb2_plane_vaddr(&vb->vb2_buf, 0);
u16 soi = be16_to_cpup((__be16 *)vaddr);
u16 eoi = be16_to_cpup((__be16 *)(vaddr +
vb2_get_plane_payload(&vb->vb2_buf, 0) - 2));
return soi == SOI_MARKER && eoi == EOI_MARKER;
}
static void coda_scale_quant_table(u8 *q_tab, int scale)
{
unsigned int temp;
int i;
for (i = 0; i < 64; i++) {
temp = DIV_ROUND_CLOSEST((unsigned int)q_tab[i] * scale, 100);
if (temp <= 0)
temp = 1;
if (temp > 255)
temp = 255;
q_tab[i] = (unsigned char)temp;
}
}
void coda_set_jpeg_compression_quality(struct coda_ctx *ctx, int quality)
{
unsigned int scale;
ctx->params.jpeg_quality = quality;
if (quality > 100)
quality = 100;
if (quality < 5)
quality = 5;
if (quality < 50)
scale = 5000 / quality;
else
scale = 200 - 2 * quality;
if (ctx->params.jpeg_qmat_tab[0]) {
memcpy(ctx->params.jpeg_qmat_tab[0], luma_q, 64);
coda_scale_quant_table(ctx->params.jpeg_qmat_tab[0], scale);
}
if (ctx->params.jpeg_qmat_tab[1]) {
memcpy(ctx->params.jpeg_qmat_tab[1], chroma_q, 64);
coda_scale_quant_table(ctx->params.jpeg_qmat_tab[1], scale);
}
}
