static int copy_packages(__le16 *dest, u16 *src, int pkg_cnt, int space)
{
int i, cnt = pkg_cnt * 32;
if (space < cnt)
return -1;
for (i = 0; i < cnt; ++i)
dest[i] = cpu_to_le16p(src + i);
return cnt;
}
static int mjpeg_frame_header(struct go7007 *go, unsigned char *buf, int q)
{
int i, p = 0;
buf[p++] = 0xff;
buf[p++] = 0xd8;
buf[p++] = 0xff;
buf[p++] = 0xdb;
buf[p++] = 0;
buf[p++] = 2 + 65;
buf[p++] = 0;
buf[p++] = default_intra_quant_table[0];
for (i = 1; i < 64; ++i)
buf[p++] = (default_intra_quant_table[zz[i]] * q) >> 3;
buf[p++] = 0xff;
buf[p++] = 0xc0;
buf[p++] = 0;
buf[p++] = 17;
buf[p++] = 8;
buf[p++] = go->height >> 8;
buf[p++] = go->height & 0xff;
buf[p++] = go->width >> 8;
buf[p++] = go->width & 0xff;
buf[p++] = 3;
buf[p++] = 1;
buf[p++] = 0x22;
buf[p++] = 0;
buf[p++] = 2;
buf[p++] = 0x11;
buf[p++] = 0;
buf[p++] = 3;
buf[p++] = 0x11;
buf[p++] = 0;
buf[p++] = 0xff;
buf[p++] = 0xc4;
buf[p++] = 418 >> 8;
buf[p++] = 418 & 0xff;
buf[p++] = 0x00;
memcpy(buf + p, bits_dc_luminance + 1, 16);
p += 16;
memcpy(buf + p, val_dc_luminance, sizeof(val_dc_luminance));
p += sizeof(val_dc_luminance);
buf[p++] = 0x01;
memcpy(buf + p, bits_dc_chrominance + 1, 16);
p += 16;
memcpy(buf + p, val_dc_chrominance, sizeof(val_dc_chrominance));
p += sizeof(val_dc_chrominance);
buf[p++] = 0x10;
memcpy(buf + p, bits_ac_luminance + 1, 16);
p += 16;
memcpy(buf + p, val_ac_luminance, sizeof(val_ac_luminance));
p += sizeof(val_ac_luminance);
buf[p++] = 0x11;
memcpy(buf + p, bits_ac_chrominance + 1, 16);
p += 16;
memcpy(buf + p, val_ac_chrominance, sizeof(val_ac_chrominance));
p += sizeof(val_ac_chrominance);
buf[p++] = 0xff;
buf[p++] = 0xda;
buf[p++] = 0;
buf[p++] = 12;
buf[p++] = 3;
buf[p++] = 1;
buf[p++] = 0x00;
buf[p++] = 2;
buf[p++] = 0x11;
buf[p++] = 3;
buf[p++] = 0x11;
buf[p++] = 0;
buf[p++] = 63;
buf[p++] = 0;
return p;
}
static int gen_mjpeghdr_to_package(struct go7007 *go, __le16 *code, int space)
{
u8 *buf;
u16 mem = 0x3e00;
unsigned int addr = 0x19;
int size = 0, i, off = 0, chunk;
buf = kzalloc(4096, GFP_KERNEL);
if (buf == NULL)
return -1;
for (i = 1; i < 32; ++i) {
mjpeg_frame_header(go, buf + size, i);
size += 80;
}
chunk = mjpeg_frame_header(go, buf + size, 1);
memmove(buf + size, buf + size + 80, chunk - 80);
size += chunk - 80;
for (i = 0; i < size; i += chunk * 2) {
if (space - off < 32) {
off = -1;
goto done;
}
code[off + 1] = __cpu_to_le16(0x8000 | mem);
chunk = 28;
if (mem + chunk > 0x4000)
chunk = 0x4000 - mem;
if (i + 2 * chunk > size)
chunk = (size - i) / 2;
if (chunk < 28) {
code[off] = __cpu_to_le16(0x4000 | chunk);
code[off + 31] = __cpu_to_le16(addr++);
mem = 0x3e00;
} else {
code[off] = __cpu_to_le16(0x1000 | 28);
code[off + 31] = 0;
mem += 28;
}
memcpy(&code[off + 2], buf + i, chunk * 2);
off += 32;
}
done:
kfree(buf);
return off;
}
static int mpeg1_frame_header(struct go7007 *go, unsigned char *buf,
int modulo, int pict_struct, enum mpeg_frame_type frame)
{
int i, j, mb_code, mb_len;
int rows = go->interlace_coding ? go->height / 32 : go->height / 16;
CODE_GEN(c, buf + 6);
switch (frame) {
case PFRAME:
mb_code = 0x1;
mb_len = 3;
break;
case BFRAME_PRE:
mb_code = 0x2;
mb_len = 4;
break;
case BFRAME_POST:
mb_code = 0x2;
mb_len = 3;
break;
case BFRAME_BIDIR:
mb_code = 0x2;
mb_len = 2;
break;
default:
mb_code = mb_len = 0;
break;
}
CODE_ADD(c, frame == PFRAME ? 0x2 : 0x3, 13);
CODE_ADD(c, 0xffff, 16);
CODE_ADD(c, go->format == GO7007_FORMAT_MPEG2 ? 0x7 : 0x4, 4);
if (frame != PFRAME)
CODE_ADD(c, go->format == GO7007_FORMAT_MPEG2 ? 0x7 : 0x4, 4);
else
CODE_ADD(c, 0, 4);
CODE_ADD(c, 0, 3);
j = 8 - (CODE_LENGTH(c) % 8);
if (j != 8)
CODE_ADD(c, 0, j);
if (go->format == GO7007_FORMAT_MPEG2) {
CODE_ADD(c, 0x1, 24);
CODE_ADD(c, 0xb5, 8);
CODE_ADD(c, 0x844, 12);
CODE_ADD(c, frame == PFRAME ? 0xff : 0x44, 8);
if (go->interlace_coding) {
CODE_ADD(c, pict_struct, 4);
if (go->dvd_mode)
CODE_ADD(c, 0x000, 11);
else
CODE_ADD(c, 0x200, 11);
} else {
CODE_ADD(c, 0x3, 4);
CODE_ADD(c, 0x20c, 11);
}
j = 8 - (CODE_LENGTH(c) % 8);
if (j != 8)
CODE_ADD(c, 0, j);
}
for (i = 0; i < rows; ++i) {
CODE_ADD(c, 1, 24);
CODE_ADD(c, i + 1, 8);
CODE_ADD(c, 0x2, 6);
CODE_ADD(c, 0x1, 1);
CODE_ADD(c, mb_code, mb_len);
if (go->interlace_coding) {
CODE_ADD(c, 0x1, 2);
CODE_ADD(c, pict_struct == 1 ? 0x0 : 0x1, 1);
}
if (frame == BFRAME_BIDIR) {
CODE_ADD(c, 0x3, 2);
if (go->interlace_coding)
CODE_ADD(c, pict_struct == 1 ? 0x0 : 0x1, 1);
}
CODE_ADD(c, 0x3, 2);
for (j = (go->width >> 4) - 2; j >= 33; j -= 33)
CODE_ADD(c, 0x8, 11);
CODE_ADD(c, addrinctab[j][0], addrinctab[j][1]);
CODE_ADD(c, mb_code, mb_len);
if (go->interlace_coding) {
CODE_ADD(c, 0x1, 2);
CODE_ADD(c, pict_struct == 1 ? 0x0 : 0x1, 1);
}
if (frame == BFRAME_BIDIR) {
CODE_ADD(c, 0x3, 2);
if (go->interlace_coding)
CODE_ADD(c, pict_struct == 1 ? 0x0 : 0x1, 1);
}
CODE_ADD(c, 0x3, 2);
j = 8 - (CODE_LENGTH(c) % 8);
if (j != 8)
CODE_ADD(c, 0, j);
}
i = CODE_LENGTH(c) + 4 * 8;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x01;
buf[5] = 0x00;
return i;
}
static int mpeg1_sequence_header(struct go7007 *go, unsigned char *buf, int ext)
{
int i, aspect_ratio, picture_rate;
CODE_GEN(c, buf + 6);
if (go->format == GO7007_FORMAT_MPEG1) {
switch (go->aspect_ratio) {
case GO7007_RATIO_4_3:
aspect_ratio = go->standard == GO7007_STD_NTSC ? 3 : 2;
break;
case GO7007_RATIO_16_9:
aspect_ratio = go->standard == GO7007_STD_NTSC ? 5 : 4;
break;
default:
aspect_ratio = 1;
break;
}
} else {
switch (go->aspect_ratio) {
case GO7007_RATIO_4_3:
aspect_ratio = 2;
break;
case GO7007_RATIO_16_9:
aspect_ratio = 3;
break;
default:
aspect_ratio = 1;
break;
}
}
switch (go->sensor_framerate) {
case 24000:
picture_rate = 1;
break;
case 24024:
picture_rate = 2;
break;
case 25025:
picture_rate = go->interlace_coding ? 6 : 3;
break;
case 30000:
picture_rate = go->interlace_coding ? 7 : 4;
break;
case 30030:
picture_rate = go->interlace_coding ? 8 : 5;
break;
default:
picture_rate = 5;
break;
}
CODE_ADD(c, go->width, 12);
CODE_ADD(c, go->height, 12);
CODE_ADD(c, aspect_ratio, 4);
CODE_ADD(c, picture_rate, 4);
CODE_ADD(c, go->format == GO7007_FORMAT_MPEG2 ? 20000 : 0x3ffff, 18);
CODE_ADD(c, 1, 1);
CODE_ADD(c, go->format == GO7007_FORMAT_MPEG2 ? 112 : 20, 10);
CODE_ADD(c, 0, 3);
i = 8 - (CODE_LENGTH(c) % 8);
if (i != 8)
CODE_ADD(c, 0, i);
if (go->format == GO7007_FORMAT_MPEG2) {
CODE_ADD(c, 0x1, 24);
CODE_ADD(c, 0xb5, 8);
CODE_ADD(c, 0x148, 12);
if (go->interlace_coding)
CODE_ADD(c, 0x20001, 20);
else
CODE_ADD(c, 0xa0001, 20);
CODE_ADD(c, 0, 16);
i = 8 - (CODE_LENGTH(c) % 8);
if (i != 8)
CODE_ADD(c, 0, i);
if (ext) {
CODE_ADD(c, 0x1, 24);
CODE_ADD(c, 0xb52, 12);
CODE_ADD(c, go->standard == GO7007_STD_NTSC ? 2 : 1, 3);
CODE_ADD(c, 0x105, 9);
CODE_ADD(c, 0x505, 16);
CODE_ADD(c, go->width, 14);
CODE_ADD(c, 1, 1);
CODE_ADD(c, go->height, 14);
i = 8 - (CODE_LENGTH(c) % 8);
if (i != 8)
CODE_ADD(c, 0, i);
}
}
i = CODE_LENGTH(c) + 4 * 8;
buf[0] = i & 0xff;
buf[1] = i >> 8;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x01;
buf[5] = 0xb3;
return i;
}
static int gen_mpeg1hdr_to_package(struct go7007 *go,
__le16 *code, int space, int *framelen)
{
u8 *buf;
u16 mem = 0x3e00;
unsigned int addr = 0x19;
int i, off = 0, chunk;
buf = kzalloc(5120, GFP_KERNEL);
if (buf == NULL)
return -1;
framelen[0] = mpeg1_frame_header(go, buf, 0, 1, PFRAME);
if (go->interlace_coding)
framelen[0] += mpeg1_frame_header(go, buf + framelen[0] / 8,
0, 2, PFRAME);
buf[0] = framelen[0] & 0xff;
buf[1] = framelen[0] >> 8;
i = 368;
framelen[1] = mpeg1_frame_header(go, buf + i, 0, 1, BFRAME_PRE);
if (go->interlace_coding)
framelen[1] += mpeg1_frame_header(go, buf + i + framelen[1] / 8,
0, 2, BFRAME_PRE);
buf[i] = framelen[1] & 0xff;
buf[i + 1] = framelen[1] >> 8;
i += 1632;
framelen[2] = mpeg1_frame_header(go, buf + i, 0, 1, BFRAME_POST);
if (go->interlace_coding)
framelen[2] += mpeg1_frame_header(go, buf + i + framelen[2] / 8,
0, 2, BFRAME_POST);
buf[i] = framelen[2] & 0xff;
buf[i + 1] = framelen[2] >> 8;
i += 1432;
framelen[3] = mpeg1_frame_header(go, buf + i, 0, 1, BFRAME_BIDIR);
if (go->interlace_coding)
framelen[3] += mpeg1_frame_header(go, buf + i + framelen[3] / 8,
0, 2, BFRAME_BIDIR);
buf[i] = framelen[3] & 0xff;
buf[i + 1] = framelen[3] >> 8;
i += 1632 + 16;
mpeg1_sequence_header(go, buf + i, 0);
i += 40;
for (i = 0; i < 5120; i += chunk * 2) {
if (space - off < 32) {
off = -1;
goto done;
}
code[off + 1] = __cpu_to_le16(0x8000 | mem);
chunk = 28;
if (mem + chunk > 0x4000)
chunk = 0x4000 - mem;
if (i + 2 * chunk > 5120)
chunk = (5120 - i) / 2;
if (chunk < 28) {
code[off] = __cpu_to_le16(0x4000 | chunk);
code[off + 31] = __cpu_to_le16(addr);
if (mem + chunk == 0x4000) {
mem = 0x3e00;
++addr;
}
} else {
code[off] = __cpu_to_le16(0x1000 | 28);
code[off + 31] = 0;
mem += 28;
}
memcpy(&code[off + 2], buf + i, chunk * 2);
off += 32;
}
done:
kfree(buf);
return off;
}
static int vti_bitlen(struct go7007 *go)
{
unsigned int i, max_time_incr = go->sensor_framerate / go->fps_scale;
for (i = 31; (max_time_incr & ((1 << i) - 1)) == max_time_incr; --i);
return i + 1;
}
static int mpeg4_frame_header(struct go7007 *go, unsigned char *buf,
int modulo, enum mpeg_frame_type frame)
{
int i;
CODE_GEN(c, buf + 6);
int mb_count = (go->width >> 4) * (go->height >> 4);
CODE_ADD(c, frame == PFRAME ? 0x1 : 0x2, 2);
if (modulo)
CODE_ADD(c, 0x1, 1);
CODE_ADD(c, 0x1, 2);
CODE_ADD(c, 0, vti_bitlen(go));
CODE_ADD(c, 0x3, 2);
if (frame == PFRAME)
CODE_ADD(c, 0, 1);
CODE_ADD(c, 0xc, 11);
if (frame != PFRAME)
CODE_ADD(c, 0x4, 3);
if (frame != BFRAME_EMPTY) {
for (i = 0; i < mb_count; ++i) {
switch (frame) {
case PFRAME:
CODE_ADD(c, 0x1, 1);
break;
case BFRAME_PRE:
CODE_ADD(c, 0x47, 8);
break;
case BFRAME_POST:
CODE_ADD(c, 0x27, 7);
break;
case BFRAME_BIDIR:
CODE_ADD(c, 0x5f, 8);
break;
case BFRAME_EMPTY:
break;
}
}
}
i = 8 - (CODE_LENGTH(c) % 8);
CODE_ADD(c, 0, 1);
CODE_ADD(c, (1 << (i - 1)) - 1, i - 1);
i = CODE_LENGTH(c) + 4 * 8;
buf[0] = i & 0xff;
buf[1] = i >> 8;
buf[2] = 0x00;
buf[3] = 0x00;
buf[4] = 0x01;
buf[5] = 0xb6;
return i;
}
static int mpeg4_sequence_header(struct go7007 *go, unsigned char *buf, int ext)
{
const unsigned char head[] = { 0x00, 0x00, 0x01, 0xb0, go->pali,
0x00, 0x00, 0x01, 0xb5, 0x09,
0x00, 0x00, 0x01, 0x00,
0x00, 0x00, 0x01, 0x20, };
int i, aspect_ratio;
int fps = go->sensor_framerate / go->fps_scale;
CODE_GEN(c, buf + 2 + sizeof(head));
switch (go->aspect_ratio) {
case GO7007_RATIO_4_3:
aspect_ratio = go->standard == GO7007_STD_NTSC ? 3 : 2;
break;
case GO7007_RATIO_16_9:
aspect_ratio = go->standard == GO7007_STD_NTSC ? 5 : 4;
break;
default:
aspect_ratio = 1;
break;
}
memcpy(buf + 2, head, sizeof(head));
CODE_ADD(c, 0x191, 17);
CODE_ADD(c, aspect_ratio, 4);
CODE_ADD(c, 0x1, 4);
CODE_ADD(c, fps, 16);
CODE_ADD(c, 0x3, 2);
CODE_ADD(c, 1001, vti_bitlen(go));
CODE_ADD(c, 1, 1);
CODE_ADD(c, go->width, 13);
CODE_ADD(c, 1, 1);
CODE_ADD(c, go->height, 13);
CODE_ADD(c, 0x2830, 14);
i = 8 - (CODE_LENGTH(c) % 8);
CODE_ADD(c, 0, 1);
CODE_ADD(c, (1 << (i - 1)) - 1, i - 1);
i = CODE_LENGTH(c) + sizeof(head) * 8;
buf[0] = i & 0xff;
buf[1] = i >> 8;
return i;
}
static int gen_mpeg4hdr_to_package(struct go7007 *go,
__le16 *code, int space, int *framelen)
{
u8 *buf;
u16 mem = 0x3e00;
unsigned int addr = 0x19;
int i, off = 0, chunk;
buf = kzalloc(5120, GFP_KERNEL);
if (buf == NULL)
return -1;
framelen[0] = mpeg4_frame_header(go, buf, 0, PFRAME);
i = 368;
framelen[1] = mpeg4_frame_header(go, buf + i, 0, BFRAME_PRE);
i += 1632;
framelen[2] = mpeg4_frame_header(go, buf + i, 0, BFRAME_POST);
i += 1432;
framelen[3] = mpeg4_frame_header(go, buf + i, 0, BFRAME_BIDIR);
i += 1632;
mpeg4_frame_header(go, buf + i, 0, BFRAME_EMPTY);
i += 16;
mpeg4_sequence_header(go, buf + i, 0);
i += 40;
for (i = 0; i < 5120; i += chunk * 2) {
if (space - off < 32) {
off = -1;
goto done;
}
code[off + 1] = __cpu_to_le16(0x8000 | mem);
chunk = 28;
if (mem + chunk > 0x4000)
chunk = 0x4000 - mem;
if (i + 2 * chunk > 5120)
chunk = (5120 - i) / 2;
if (chunk < 28) {
code[off] = __cpu_to_le16(0x4000 | chunk);
code[off + 31] = __cpu_to_le16(addr);
if (mem + chunk == 0x4000) {
mem = 0x3e00;
++addr;
}
} else {
code[off] = __cpu_to_le16(0x1000 | 28);
code[off + 31] = 0;
mem += 28;
}
memcpy(&code[off + 2], buf + i, chunk * 2);
off += 32;
}
mem = 0x3e00;
addr = go->ipb ? 0x14f9 : 0x0af9;
memset(buf, 0, 5120);
framelen[4] = mpeg4_frame_header(go, buf, 1, PFRAME);
i = 368;
framelen[5] = mpeg4_frame_header(go, buf + i, 1, BFRAME_PRE);
i += 1632;
framelen[6] = mpeg4_frame_header(go, buf + i, 1, BFRAME_POST);
i += 1432;
framelen[7] = mpeg4_frame_header(go, buf + i, 1, BFRAME_BIDIR);
i += 1632;
mpeg4_frame_header(go, buf + i, 1, BFRAME_EMPTY);
i += 16;
for (i = 0; i < 5120; i += chunk * 2) {
if (space - off < 32) {
off = -1;
goto done;
}
code[off + 1] = __cpu_to_le16(0x8000 | mem);
chunk = 28;
if (mem + chunk > 0x4000)
chunk = 0x4000 - mem;
if (i + 2 * chunk > 5120)
chunk = (5120 - i) / 2;
if (chunk < 28) {
code[off] = __cpu_to_le16(0x4000 | chunk);
code[off + 31] = __cpu_to_le16(addr);
if (mem + chunk == 0x4000) {
mem = 0x3e00;
++addr;
}
} else {
code[off] = __cpu_to_le16(0x1000 | 28);
code[off + 31] = 0;
mem += 28;
}
memcpy(&code[off + 2], buf + i, chunk * 2);
off += 32;
}
done:
kfree(buf);
return off;
}
static int brctrl_to_package(struct go7007 *go,
__le16 *code, int space, int *framelen)
{
int converge_speed = 0;
int lambda = (go->format == GO7007_FORMAT_MJPEG || go->dvd_mode) ?
100 : 0;
int peak_rate = 6 * go->bitrate / 5;
int vbv_buffer = go->format == GO7007_FORMAT_MJPEG ?
go->bitrate :
(go->dvd_mode ? 900000 : peak_rate);
int fps = go->sensor_framerate / go->fps_scale;
int q = 0;
u32 sgop_expt_addr = go->bitrate / 32 * (go->ipb ? 3 : 1) * 1001 / fps;
u32 sgop_peak_addr = peak_rate / 32 * 1001 / fps;
u32 total_expt_addr = go->bitrate / 32 * 1000 / fps * (fps / 1000);
u32 vbv_alert_addr = vbv_buffer * 3 / (4 * 32);
u32 cplx[] = {
q > 0 ? sgop_expt_addr * q :
2 * go->width * go->height * (go->ipb ? 6 : 4) / 32,
q > 0 ? sgop_expt_addr * q :
2 * go->width * go->height * (go->ipb ? 6 : 4) / 32,
q > 0 ? sgop_expt_addr * q :
2 * go->width * go->height * (go->ipb ? 6 : 4) / 32,
q > 0 ? sgop_expt_addr * q :
2 * go->width * go->height * (go->ipb ? 6 : 4) / 32,
};
u32 calc_q = q > 0 ? q : cplx[0] / sgop_expt_addr;
u16 pack[] = {
0x200e, 0x0000,
0xBF20, go->ipb ? converge_speed_ipb[converge_speed]
: converge_speed_ip[converge_speed],
0xBF21, go->ipb ? 2 : 0,
0xBF22, go->ipb ? LAMBDA_table[0][lambda / 2 + 50]
: 32767,
0xBF23, go->ipb ? LAMBDA_table[1][lambda] : 32767,
0xBF24, 32767,
0xBF25, lambda > 99 ? 32767 : LAMBDA_table[3][lambda],
0xBF26, sgop_expt_addr & 0x0000FFFF,
0xBF27, sgop_expt_addr >> 16,
0xBF28, sgop_peak_addr & 0x0000FFFF,
0xBF29, sgop_peak_addr >> 16,
0xBF2A, vbv_alert_addr & 0x0000FFFF,
0xBF2B, vbv_alert_addr >> 16,
0xBF2C, 0,
0xBF2D, 0,
0, 0,
0x200e, 0x0000,
0xBF2E, vbv_alert_addr & 0x0000FFFF,
0xBF2F, vbv_alert_addr >> 16,
0xBF30, cplx[0] & 0x0000FFFF,
0xBF31, cplx[0] >> 16,
0xBF32, cplx[1] & 0x0000FFFF,
0xBF33, cplx[1] >> 16,
0xBF34, cplx[2] & 0x0000FFFF,
0xBF35, cplx[2] >> 16,
0xBF36, cplx[3] & 0x0000FFFF,
0xBF37, cplx[3] >> 16,
0xBF38, 0,
0xBF39, 0,
0xBF3A, total_expt_addr & 0x0000FFFF,
0xBF3B, total_expt_addr >> 16,
0, 0,
0x200e, 0x0000,
0xBF3C, total_expt_addr & 0x0000FFFF,
0xBF3D, total_expt_addr >> 16,
0xBF3E, 0,
0xBF3F, 0,
0xBF48, 0,
0xBF49, 0,
0xBF4A, calc_q < 4 ? 4 : (calc_q > 124 ? 124 : calc_q),
0xBF4B, 4,
0xBF4C, 0,
0xBF4D, 0,
0xBF4E, 0,
0xBF4F, 0,
0xBF50, 0,
0xBF51, 0,
0, 0,
0x200e, 0x0000,
0xBF40, sgop_expt_addr & 0x0000FFFF,
0xBF41, sgop_expt_addr >> 16,
0xBF42, 0,
0xBF43, 0,
0xBF44, 0,
0xBF45, 0,
0xBF46, (go->width >> 4) * (go->height >> 4),
0xBF47, 0,
0xBF64, 0,
0xBF65, 0,
0xBF18, framelen[4],
0xBF19, framelen[5],
0xBF1A, framelen[6],
0xBF1B, framelen[7],
0, 0,
#if 0
0x200e, 0x0000,
0xBF56, 4,
0xBF57, 0,
0xBF58, 5,
0xBF59, 0,
0xBF5A, 6,
0xBF5B, 0,
0xBF5C, 8,
0xBF5D, 0,
0xBF5E, 1,
0xBF5F, 0,
0xBF60, 1,
0xBF61, 0,
0xBF62, 0,
0xBF63, 0,
0, 0,
#else
0x2008, 0x0000,
0xBF56, 4,
0xBF57, 0,
0xBF58, 5,
0xBF59, 0,
0xBF5A, 6,
0xBF5B, 0,
0xBF5C, 8,
0xBF5D, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
#endif
0x200e, 0x0000,
0xBF10, 0,
0xBF11, 0,
0xBF12, 0,
0xBF13, 0,
0xBF14, 0,
0xBF15, 0,
0xBF16, 0,
0xBF17, 0,
0xBF7E, 0,
0xBF7F, 1,
0xBF52, framelen[0],
0xBF53, framelen[1],
0xBF54, framelen[2],
0xBF55, framelen[3],
0, 0,
};
return copy_packages(code, pack, 6, space);
}
static int config_package(struct go7007 *go, __le16 *code, int space)
{
int fps = go->sensor_framerate / go->fps_scale / 1000;
int rows = go->interlace_coding ? go->height / 32 : go->height / 16;
int brc_window_size = fps;
int q_min = 2, q_max = 31;
int THACCoeffSet0 = 0;
u16 pack[] = {
0x200e, 0x0000,
0xc002, 0x14b4,
0xc003, 0x28b4,
0xc004, 0x3c5a,
0xdc05, 0x2a77,
0xc6c3, go->format == GO7007_FORMAT_MPEG4 ? 0 :
(go->format == GO7007_FORMAT_H263 ? 0 : 1),
0xc680, go->format == GO7007_FORMAT_MPEG4 ? 0xf1 :
(go->format == GO7007_FORMAT_H263 ? 0x61 :
0xd3),
0xc780, 0x0140,
0xe009, 0x0001,
0xc60f, 0x0008,
0xd4ff, 0x0002,
0xe403, 2340,
0xe406, 75,
0xd411, 0x0001,
0xd410, 0xa1d6,
0x0001, 0x2801,
0x200d, 0x0000,
0xe402, 0x018b,
0xe401, 0x8b01,
0xd472, (go->board_info->sensor_flags &
GO7007_SENSOR_TV) &&
(!go->interlace_coding) ?
0x01b0 : 0x0170,
0xd475, (go->board_info->sensor_flags &
GO7007_SENSOR_TV) &&
(!go->interlace_coding) ?
0x0008 : 0x0009,
0xc404, go->interlace_coding ? 0x44 :
(go->format == GO7007_FORMAT_MPEG4 ? 0x11 :
(go->format == GO7007_FORMAT_MPEG1 ? 0x02 :
(go->format == GO7007_FORMAT_MPEG2 ? 0x04 :
(go->format == GO7007_FORMAT_H263 ? 0x08 :
0x20)))),
0xbf0a, (go->format == GO7007_FORMAT_MPEG4 ? 8 :
(go->format == GO7007_FORMAT_MPEG1 ? 1 :
(go->format == GO7007_FORMAT_MPEG2 ? 2 :
(go->format == GO7007_FORMAT_H263 ? 4 : 16)))) |
((go->repeat_seqhead ? 1 : 0) << 6) |
((go->dvd_mode ? 1 : 0) << 9) |
((go->gop_header_enable ? 1 : 0) << 10),
0xbf0b, 0,
0xdd5a, go->ipb ? 0x14 : 0x0a,
0xbf0c, 0,
0xbf0d, 0,
0xc683, THACCoeffSet0,
0xc40a, (go->width << 4) | rows,
0xe01a, go->board_info->hpi_buffer_cap,
0, 0,
0, 0,
0x2008, 0,
0xe402, 0x88,
0xe401, 0x8f01,
0xbf6a, 0,
0xbf6b, 0,
0xbf6c, 0,
0xbf6d, 0,
0xbf6e, 0,
0xbf6f, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0x200e, 0,
0xbf66, brc_window_size,
0xbf67, 0,
0xbf68, q_min,
0xbf69, q_max,
0xbfe0, 0,
0xbfe1, 0,
0xbfe2, 0,
0xbfe3, go->ipb ? 3 : 1,
0xc031, go->board_info->sensor_flags &
GO7007_SENSOR_VBI ? 1 : 0,
0xc01c, 0x1f,
0xdd8c, 0x15,
0xdd94, 0x15,
0xdd88, go->ipb ? 0x1401 : 0x0a01,
0xdd90, go->ipb ? 0x1401 : 0x0a01,
0, 0,
0x200e, 0,
0xbfe4, 0,
0xbfe5, 0,
0xbfe6, 0,
0xbfe7, fps << 8,
0xbfe8, 0x3a00,
0xbfe9, 0,
0xbfea, 0,
0xbfeb, 0,
0xbfec, (go->interlace_coding ? 1 << 15 : 0) |
(go->modet_enable ? 0xa : 0) |
(go->board_info->sensor_flags &
GO7007_SENSOR_VBI ? 1 : 0),
0xbfed, 0,
0xbfee, 0,
0xbfef, 0,
0xbff0, go->board_info->sensor_flags &
GO7007_SENSOR_TV ? 0xf060 : 0xb060,
0xbff1, 0,
0, 0,
};
return copy_packages(code, pack, 5, space);
}
static int seqhead_to_package(struct go7007 *go, __le16 *code, int space,
int (*sequence_header_func)(struct go7007 *go,
unsigned char *buf, int ext))
{
int vop_time_increment_bitlength = vti_bitlen(go);
int fps = go->sensor_framerate / go->fps_scale *
(go->interlace_coding ? 2 : 1);
unsigned char buf[40] = { };
int len = sequence_header_func(go, buf, 1);
u16 pack[] = {
0x2006, 0,
0xbf08, fps,
0xbf09, 0,
0xbff2, vop_time_increment_bitlength,
0xbff3, (1 << vop_time_increment_bitlength) - 1,
0xbfe6, 0,
0xbfe7, (fps / 1000) << 8,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0x2007, 0,
0xc800, buf[2] << 8 | buf[3],
0xc801, buf[4] << 8 | buf[5],
0xc802, buf[6] << 8 | buf[7],
0xc803, buf[8] << 8 | buf[9],
0xc406, 64,
0xc407, len - 64,
0xc61b, 1,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0x200e, 0,
0xc808, buf[10] << 8 | buf[11],
0xc809, buf[12] << 8 | buf[13],
0xc80a, buf[14] << 8 | buf[15],
0xc80b, buf[16] << 8 | buf[17],
0xc80c, buf[18] << 8 | buf[19],
0xc80d, buf[20] << 8 | buf[21],
0xc80e, buf[22] << 8 | buf[23],
0xc80f, buf[24] << 8 | buf[25],
0xc810, buf[26] << 8 | buf[27],
0xc811, buf[28] << 8 | buf[29],
0xc812, buf[30] << 8 | buf[31],
0xc813, buf[32] << 8 | buf[33],
0xc814, buf[34] << 8 | buf[35],
0xc815, buf[36] << 8 | buf[37],
0, 0,
0, 0,
0, 0,
};
return copy_packages(code, pack, 3, space);
}
static int relative_prime(int big, int little)
{
int remainder;
while (little != 0) {
remainder = big % little;
big = little;
little = remainder;
}
return big;
}
static int avsync_to_package(struct go7007 *go, __le16 *code, int space)
{
int arate = go->board_info->audio_rate * 1001 * go->fps_scale;
int ratio = arate / go->sensor_framerate;
int adjratio = ratio * 215 / 100;
int rprime = relative_prime(go->sensor_framerate,
arate % go->sensor_framerate);
int f1 = (arate % go->sensor_framerate) / rprime;
int f2 = (go->sensor_framerate - arate % go->sensor_framerate) / rprime;
u16 pack[] = {
0x200e, 0,
0xbf98, (u16)((-adjratio) & 0xffff),
0xbf99, (u16)((-adjratio) >> 16),
0xbf92, 0,
0xbf93, 0,
0xbff4, f1 > f2 ? f1 : f2,
0xbff5, f1 < f2 ? f1 : f2,
0xbff6, f1 < f2 ? ratio : ratio + 1,
0xbff7, f1 > f2 ? ratio : ratio + 1,
0xbff8, 0,
0xbff9, 0,
0xbffa, adjratio & 0xffff,
0xbffb, adjratio >> 16,
0xbf94, 0,
0xbf95, 0,
0, 0,
};
return copy_packages(code, pack, 1, space);
}
static int final_package(struct go7007 *go, __le16 *code, int space)
{
int rows = go->interlace_coding ? go->height / 32 : go->height / 16;
u16 pack[] = {
0x8000,
0,
0,
0,
0,
0,
0,
2,
((go->board_info->sensor_flags & GO7007_SENSOR_TV) &&
(!go->interlace_coding) ?
(1 << 14) | (1 << 9) : 0) |
((go->encoder_subsample ? 1 : 0) << 8) |
(go->board_info->sensor_flags &
GO7007_SENSOR_CONFIG_MASK),
((go->encoder_v_halve ? 1 : 0) << 14) |
(go->encoder_v_halve ? rows << 9 : rows << 8) |
(go->encoder_h_halve ? 1 << 6 : 0) |
(go->encoder_h_halve ? go->width >> 3 : go->width >> 4),
(1 << 15) | (go->encoder_v_offset << 6) |
(1 << 7) | (go->encoder_h_offset >> 2),
(1 << 6),
0,
0,
((go->fps_scale - 1) << 8) |
(go->board_info->sensor_flags & GO7007_SENSOR_TV ?
(1 << 7) : 0) |
0x41,
go->ipb ? 0xd4c : 0x36b,
(rows << 8) | (go->width >> 4),
go->format == GO7007_FORMAT_MPEG4 ? 0x0404 : 0,
(1 << 15) | ((go->interlace_coding ? 1 : 0) << 13) |
((go->closed_gop ? 1 : 0) << 12) |
((go->format == GO7007_FORMAT_MPEG4 ? 1 : 0) << 11) |
((go->ipb ? 3 : 0) << 7) |
((go->modet_enable ? 1 : 0) << 2) |
((go->dvd_mode ? 1 : 0) << 1) | 1,
(go->format == GO7007_FORMAT_MPEG1 ? 0x89a0 :
(go->format == GO7007_FORMAT_MPEG2 ? 0x89a0 :
(go->format == GO7007_FORMAT_MJPEG ? 0x89a0 :
(go->format == GO7007_FORMAT_MPEG4 ? 0x8920 :
(go->format == GO7007_FORMAT_H263 ? 0x8920 : 0))))),
go->ipb ? 0x1f15 : 0x1f0b,
go->ipb ? 0x0015 : 0x000b,
go->ipb ? 0xa800 : 0x5800,
0xffff,
0x0020 + 0x034b * 0,
0x0020 + 0x034b * 1,
0x0020 + 0x034b * 2,
0x0020 + 0x034b * 3,
0x0020 + 0x034b * 4,
0x0020 + 0x034b * 5,
go->ipb ? (go->gop_size / 3) : go->gop_size,
(go->height >> 4) * (go->width >> 4) * 110 / 100,
};
return copy_packages(code, pack, 1, space);
}
static int audio_to_package(struct go7007 *go, __le16 *code, int space)
{
int clock_config = ((go->board_info->audio_flags &
GO7007_AUDIO_I2S_MASTER ? 1 : 0) << 11) |
((go->board_info->audio_flags &
GO7007_AUDIO_OKI_MODE ? 1 : 0) << 8) |
(((go->board_info->audio_bclk_div / 4) - 1) << 4) |
(go->board_info->audio_main_div - 1);
u16 pack[] = {
0x200d, 0,
0x9002, 0,
0x9002, 0,
0x9031, 0,
0x9032, 0,
0x9033, 0,
0x9034, 0,
0x9035, 0,
0x9036, 0,
0x9037, 0,
0x9040, 0,
0x9000, clock_config,
0x9001, (go->board_info->audio_flags & 0xffff) |
(1 << 9),
0x9000, ((go->board_info->audio_flags &
GO7007_AUDIO_I2S_MASTER ?
1 : 0) << 10) |
clock_config,
0, 0,
0, 0,
0x2005, 0,
0x9041, 0,
0x9042, 256,
0x9043, 0,
0x9044, 16,
0x9045, 16,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
0, 0,
};
return copy_packages(code, pack, 2, space);
}
static int modet_to_package(struct go7007 *go, __le16 *code, int space)
{
int ret, mb, i, addr, cnt = 0;
u16 pack[32];
u16 thresholds[] = {
0x200e, 0,
0xbf82, go->modet[0].pixel_threshold,
0xbf83, go->modet[1].pixel_threshold,
0xbf84, go->modet[2].pixel_threshold,
0xbf85, go->modet[3].pixel_threshold,
0xbf86, go->modet[0].motion_threshold,
0xbf87, go->modet[1].motion_threshold,
0xbf88, go->modet[2].motion_threshold,
0xbf89, go->modet[3].motion_threshold,
0xbf8a, go->modet[0].mb_threshold,
0xbf8b, go->modet[1].mb_threshold,
0xbf8c, go->modet[2].mb_threshold,
0xbf8d, go->modet[3].mb_threshold,
0xbf8e, 0,
0xbf8f, 0,
0, 0,
};
ret = copy_packages(code, thresholds, 1, space);
if (ret < 0)
return -1;
cnt += ret;
addr = 0xbac0;
memset(pack, 0, 64);
i = 0;
for (mb = 0; mb < 1624; ++mb) {
pack[i * 2 + 3] <<= 2;
pack[i * 2 + 3] |= go->modet_map[mb];
if (mb % 8 != 7)
continue;
pack[i * 2 + 2] = addr++;
++i;
if (i == 10 || mb == 1623) {
pack[0] = 0x2000 | i;
ret = copy_packages(code + cnt, pack, 1, space - cnt);
if (ret < 0)
return -1;
cnt += ret;
i = 0;
memset(pack, 0, 64);
}
pack[i * 2 + 3] = 0;
}
memset(pack, 0, 64);
i = 0;
for (addr = 0xbb90; addr < 0xbbfa; ++addr) {
pack[i * 2 + 2] = addr;
pack[i * 2 + 3] = 0;
++i;
if (i == 10 || addr == 0xbbf9) {
pack[0] = 0x2000 | i;
ret = copy_packages(code + cnt, pack, 1, space - cnt);
if (ret < 0)
return -1;
cnt += ret;
i = 0;
memset(pack, 0, 64);
}
}
return cnt;
}
static int do_special(struct go7007 *go, u16 type, __le16 *code, int space,
int *framelen)
{
switch (type) {
case SPECIAL_FRM_HEAD:
switch (go->format) {
case GO7007_FORMAT_MJPEG:
return gen_mjpeghdr_to_package(go, code, space);
case GO7007_FORMAT_MPEG1:
case GO7007_FORMAT_MPEG2:
return gen_mpeg1hdr_to_package(go, code, space,
framelen);
case GO7007_FORMAT_MPEG4:
return gen_mpeg4hdr_to_package(go, code, space,
framelen);
}
case SPECIAL_BRC_CTRL:
return brctrl_to_package(go, code, space, framelen);
case SPECIAL_CONFIG:
return config_package(go, code, space);
case SPECIAL_SEQHEAD:
switch (go->format) {
case GO7007_FORMAT_MPEG1:
case GO7007_FORMAT_MPEG2:
return seqhead_to_package(go, code, space,
mpeg1_sequence_header);
case GO7007_FORMAT_MPEG4:
return seqhead_to_package(go, code, space,
mpeg4_sequence_header);
default:
return 0;
}
case SPECIAL_AV_SYNC:
return avsync_to_package(go, code, space);
case SPECIAL_FINAL:
return final_package(go, code, space);
case SPECIAL_AUDIO:
return audio_to_package(go, code, space);
case SPECIAL_MODET:
return modet_to_package(go, code, space);
}
dev_err(go->dev,
"firmware file contains unsupported feature %04x\n", type);
return -1;
}
int go7007_construct_fw_image(struct go7007 *go, u8 **fw, int *fwlen)
{
const struct firmware *fw_entry;
__le16 *code, *src;
int framelen[8] = { };
int codespace = 64 * 1024, i = 0, srclen, chunk_len, chunk_flags;
int mode_flag;
int ret;
switch (go->format) {
case GO7007_FORMAT_MJPEG:
mode_flag = FLAG_MODE_MJPEG;
break;
case GO7007_FORMAT_MPEG1:
mode_flag = FLAG_MODE_MPEG1;
break;
case GO7007_FORMAT_MPEG2:
mode_flag = FLAG_MODE_MPEG2;
break;
case GO7007_FORMAT_MPEG4:
mode_flag = FLAG_MODE_MPEG4;
break;
default:
return -1;
}
if (request_firmware(&fw_entry, go->board_info->firmware, go->dev)) {
dev_err(go->dev,
"unable to load firmware from file \"%s\"\n",
go->board_info->firmware);
return -1;
}
code = kzalloc(codespace * 2, GFP_KERNEL);
if (code == NULL)
goto fw_failed;
src = (__le16 *)fw_entry->data;
srclen = fw_entry->size / 2;
while (srclen >= 2) {
chunk_flags = __le16_to_cpu(src[0]);
chunk_len = __le16_to_cpu(src[1]);
if (chunk_len + 2 > srclen) {
dev_err(go->dev,
"firmware file \"%s\" appears to be corrupted\n",
go->board_info->firmware);
goto fw_failed;
}
if (chunk_flags & mode_flag) {
if (chunk_flags & FLAG_SPECIAL) {
ret = do_special(go, __le16_to_cpu(src[2]),
&code[i], codespace - i, framelen);
if (ret < 0) {
dev_err(go->dev,
"insufficient memory for firmware construction\n");
goto fw_failed;
}
i += ret;
} else {
if (codespace - i < chunk_len) {
dev_err(go->dev,
"insufficient memory for firmware construction\n");
goto fw_failed;
}
memcpy(&code[i], &src[2], chunk_len * 2);
i += chunk_len;
}
}
srclen -= chunk_len + 2;
src += chunk_len + 2;
}
release_firmware(fw_entry);
*fw = (u8 *)code;
*fwlen = i * 2;
return 0;
fw_failed:
kfree(code);
release_firmware(fw_entry);
return -1;
}
