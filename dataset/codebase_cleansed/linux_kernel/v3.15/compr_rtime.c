static int jffs2_rtime_compress(unsigned char *data_in,
unsigned char *cpage_out,
uint32_t *sourcelen, uint32_t *dstlen)
{
unsigned short positions[256];
int outpos = 0;
int pos=0;
memset(positions,0,sizeof(positions));
while (pos < (*sourcelen) && outpos <= (*dstlen)-2) {
int backpos, runlen=0;
unsigned char value;
value = data_in[pos];
cpage_out[outpos++] = data_in[pos++];
backpos = positions[value];
positions[value]=pos;
while ((backpos < pos) && (pos < (*sourcelen)) &&
(data_in[pos]==data_in[backpos++]) && (runlen<255)) {
pos++;
runlen++;
}
cpage_out[outpos++] = runlen;
}
if (outpos >= pos) {
return -1;
}
*sourcelen = pos;
*dstlen = outpos;
return 0;
}
static int jffs2_rtime_decompress(unsigned char *data_in,
unsigned char *cpage_out,
uint32_t srclen, uint32_t destlen)
{
unsigned short positions[256];
int outpos = 0;
int pos=0;
memset(positions,0,sizeof(positions));
while (outpos<destlen) {
unsigned char value;
int backoffs;
int repeat;
value = data_in[pos++];
cpage_out[outpos++] = value;
repeat = data_in[pos++];
backoffs = positions[value];
positions[value]=outpos;
if (repeat) {
if (backoffs + repeat >= outpos) {
while(repeat) {
cpage_out[outpos++] = cpage_out[backoffs++];
repeat--;
}
} else {
memcpy(&cpage_out[outpos],&cpage_out[backoffs],repeat);
outpos+=repeat;
}
}
}
return 0;
}
int jffs2_rtime_init(void)
{
return jffs2_register_compressor(&jffs2_rtime_comp);
}
void jffs2_rtime_exit(void)
{
jffs2_unregister_compressor(&jffs2_rtime_comp);
}
