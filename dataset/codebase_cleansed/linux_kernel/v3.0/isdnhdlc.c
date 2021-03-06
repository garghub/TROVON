void isdnhdlc_rcv_init(struct isdnhdlc_vars *hdlc, u32 features)
{
memset(hdlc, 0, sizeof(struct isdnhdlc_vars));
hdlc->state = HDLC_GET_DATA;
if (features & HDLC_56KBIT)
hdlc->do_adapt56 = 1;
if (features & HDLC_BITREVERSE)
hdlc->do_bitreverse = 1;
}
void isdnhdlc_out_init(struct isdnhdlc_vars *hdlc, u32 features)
{
memset(hdlc, 0, sizeof(struct isdnhdlc_vars));
if (features & HDLC_DCHANNEL) {
hdlc->dchannel = 1;
hdlc->state = HDLC_SEND_FIRST_FLAG;
} else {
hdlc->dchannel = 0;
hdlc->state = HDLC_SEND_FAST_FLAG;
hdlc->ffvalue = 0x7e;
}
hdlc->cbin = 0x7e;
if (features & HDLC_56KBIT) {
hdlc->do_adapt56 = 1;
hdlc->state = HDLC_SENDFLAG_B0;
} else
hdlc->data_bits = 8;
if (features & HDLC_BITREVERSE)
hdlc->do_bitreverse = 1;
}
static int
check_frame(struct isdnhdlc_vars *hdlc)
{
int status;
if (hdlc->dstpos < 2)
status = -HDLC_FRAMING_ERROR;
else if (hdlc->crc != 0xf0b8)
status = -HDLC_CRC_ERROR;
else {
hdlc->dstpos -= 2;
status = hdlc->dstpos;
}
return status;
}
int isdnhdlc_decode(struct isdnhdlc_vars *hdlc, const u8 *src, int slen,
int *count, u8 *dst, int dsize)
{
int status = 0;
static const unsigned char fast_flag[] = {
0x00, 0x00, 0x00, 0x20, 0x30, 0x38, 0x3c, 0x3e, 0x3f
};
static const unsigned char fast_flag_value[] = {
0x00, 0x7e, 0xfc, 0xf9, 0xf3, 0xe7, 0xcf, 0x9f, 0x3f
};
static const unsigned char fast_abort[] = {
0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff
};
#define handle_fast_flag(h) \
do {\
if (h->cbin == fast_flag[h->bit_shift]) {\
h->ffvalue = fast_flag_value[h->bit_shift];\
h->state = HDLC_FAST_FLAG;\
h->ffbit_shift = h->bit_shift;\
h->bit_shift = 1;\
} else {\
h->state = HDLC_GET_DATA;\
h->data_received = 0;\
} \
} while (0)
#define handle_abort(h) \
do {\
h->shift_reg = fast_abort[h->ffbit_shift - 1];\
h->hdlc_bits1 = h->ffbit_shift - 2;\
if (h->hdlc_bits1 < 0)\
h->hdlc_bits1 = 0;\
h->data_bits = h->ffbit_shift - 1;\
h->state = HDLC_GET_DATA;\
h->data_received = 0;\
} while (0)
*count = slen;
while (slen > 0) {
if (hdlc->bit_shift == 0) {
if (hdlc->do_bitreverse == 0)
hdlc->cbin = bitrev8(*src++);
else
hdlc->cbin = *src++;
slen--;
hdlc->bit_shift = 8;
if (hdlc->do_adapt56)
hdlc->bit_shift--;
}
switch (hdlc->state) {
case STOPPED:
return 0;
case HDLC_FAST_IDLE:
if (hdlc->cbin == 0xff) {
hdlc->bit_shift = 0;
break;
}
hdlc->state = HDLC_GET_FLAG_B0;
hdlc->hdlc_bits1 = 0;
hdlc->bit_shift = 8;
break;
case HDLC_GET_FLAG_B0:
if (!(hdlc->cbin & 0x80)) {
hdlc->state = HDLC_GETFLAG_B1A6;
hdlc->hdlc_bits1 = 0;
} else {
if ((!hdlc->do_adapt56) &&
(++hdlc->hdlc_bits1 >= 8) &&
(hdlc->bit_shift == 1))
hdlc->state = HDLC_FAST_IDLE;
}
hdlc->cbin <<= 1;
hdlc->bit_shift--;
break;
case HDLC_GETFLAG_B1A6:
if (hdlc->cbin & 0x80) {
hdlc->hdlc_bits1++;
if (hdlc->hdlc_bits1 == 6)
hdlc->state = HDLC_GETFLAG_B7;
} else
hdlc->hdlc_bits1 = 0;
hdlc->cbin <<= 1;
hdlc->bit_shift--;
break;
case HDLC_GETFLAG_B7:
if (hdlc->cbin & 0x80) {
hdlc->state = HDLC_GET_FLAG_B0;
} else {
hdlc->state = HDLC_GET_DATA;
hdlc->crc = 0xffff;
hdlc->shift_reg = 0;
hdlc->hdlc_bits1 = 0;
hdlc->data_bits = 0;
hdlc->data_received = 0;
}
hdlc->cbin <<= 1;
hdlc->bit_shift--;
break;
case HDLC_GET_DATA:
if (hdlc->cbin & 0x80) {
hdlc->hdlc_bits1++;
switch (hdlc->hdlc_bits1) {
case 6:
break;
case 7:
if (hdlc->data_received)
status = -HDLC_FRAMING_ERROR;
if (!hdlc->do_adapt56) {
if (hdlc->cbin == fast_abort
[hdlc->bit_shift + 1]) {
hdlc->state =
HDLC_FAST_IDLE;
hdlc->bit_shift = 1;
break;
}
} else
hdlc->state = HDLC_GET_FLAG_B0;
break;
default:
hdlc->shift_reg >>= 1;
hdlc->shift_reg |= 0x80;
hdlc->data_bits++;
break;
}
} else {
switch (hdlc->hdlc_bits1) {
case 5:
break;
case 6:
if (hdlc->data_received)
status = check_frame(hdlc);
hdlc->crc = 0xffff;
hdlc->shift_reg = 0;
hdlc->data_bits = 0;
if (!hdlc->do_adapt56)
handle_fast_flag(hdlc);
else {
hdlc->state = HDLC_GET_DATA;
hdlc->data_received = 0;
}
break;
default:
hdlc->shift_reg >>= 1;
hdlc->data_bits++;
break;
}
hdlc->hdlc_bits1 = 0;
}
if (status) {
hdlc->dstpos = 0;
*count -= slen;
hdlc->cbin <<= 1;
hdlc->bit_shift--;
return status;
}
if (hdlc->data_bits == 8) {
hdlc->data_bits = 0;
hdlc->data_received = 1;
hdlc->crc = crc_ccitt_byte(hdlc->crc,
hdlc->shift_reg);
if (hdlc->dstpos < dsize)
dst[hdlc->dstpos++] = hdlc->shift_reg;
else {
status = -HDLC_LENGTH_ERROR;
hdlc->dstpos = 0;
}
}
hdlc->cbin <<= 1;
hdlc->bit_shift--;
break;
case HDLC_FAST_FLAG:
if (hdlc->cbin == hdlc->ffvalue) {
hdlc->bit_shift = 0;
break;
} else {
if (hdlc->cbin == 0xff) {
hdlc->state = HDLC_FAST_IDLE;
hdlc->bit_shift = 0;
} else if (hdlc->ffbit_shift == 8) {
hdlc->state = HDLC_GETFLAG_B7;
break;
} else
handle_abort(hdlc);
}
break;
default:
break;
}
}
*count -= slen;
return 0;
}
int isdnhdlc_encode(struct isdnhdlc_vars *hdlc, const u8 *src, u16 slen,
int *count, u8 *dst, int dsize)
{
static const unsigned char xfast_flag_value[] = {
0x7e, 0x3f, 0x9f, 0xcf, 0xe7, 0xf3, 0xf9, 0xfc, 0x7e
};
int len = 0;
*count = slen;
if ((slen == 1) && (hdlc->state == HDLC_SEND_FAST_FLAG))
hdlc->state = HDLC_SENDFLAG_ONE;
while (dsize > 0) {
if (hdlc->bit_shift == 0) {
if (slen && !hdlc->do_closing) {
hdlc->shift_reg = *src++;
slen--;
if (slen == 0)
hdlc->do_closing = 1;
hdlc->bit_shift = 8;
} else {
if (hdlc->state == HDLC_SEND_DATA) {
if (hdlc->data_received) {
hdlc->state = HDLC_SEND_CRC1;
hdlc->crc ^= 0xffff;
hdlc->bit_shift = 8;
hdlc->shift_reg =
hdlc->crc & 0xff;
} else if (!hdlc->do_adapt56)
hdlc->state =
HDLC_SEND_FAST_FLAG;
else
hdlc->state =
HDLC_SENDFLAG_B0;
}
}
}
switch (hdlc->state) {
case STOPPED:
while (dsize--)
*dst++ = 0xff;
return dsize;
case HDLC_SEND_FAST_FLAG:
hdlc->do_closing = 0;
if (slen == 0) {
if (hdlc->do_bitreverse == 0)
*dst++ = bitrev8(hdlc->ffvalue);
else
*dst++ = hdlc->ffvalue;
len++;
dsize--;
break;
}
case HDLC_SENDFLAG_ONE:
if (hdlc->bit_shift == 8) {
hdlc->cbin = hdlc->ffvalue >>
(8 - hdlc->data_bits);
hdlc->state = HDLC_SEND_DATA;
hdlc->crc = 0xffff;
hdlc->hdlc_bits1 = 0;
hdlc->data_received = 1;
}
break;
case HDLC_SENDFLAG_B0:
hdlc->do_closing = 0;
hdlc->cbin <<= 1;
hdlc->data_bits++;
hdlc->hdlc_bits1 = 0;
hdlc->state = HDLC_SENDFLAG_B1A6;
break;
case HDLC_SENDFLAG_B1A6:
hdlc->cbin <<= 1;
hdlc->data_bits++;
hdlc->cbin++;
if (++hdlc->hdlc_bits1 == 6)
hdlc->state = HDLC_SENDFLAG_B7;
break;
case HDLC_SENDFLAG_B7:
hdlc->cbin <<= 1;
hdlc->data_bits++;
if (slen == 0) {
hdlc->state = HDLC_SENDFLAG_B0;
break;
}
if (hdlc->bit_shift == 8) {
hdlc->state = HDLC_SEND_DATA;
hdlc->crc = 0xffff;
hdlc->hdlc_bits1 = 0;
hdlc->data_received = 1;
}
break;
case HDLC_SEND_FIRST_FLAG:
hdlc->data_received = 1;
if (hdlc->data_bits == 8) {
hdlc->state = HDLC_SEND_DATA;
hdlc->crc = 0xffff;
hdlc->hdlc_bits1 = 0;
break;
}
hdlc->cbin <<= 1;
hdlc->data_bits++;
if (hdlc->shift_reg & 0x01)
hdlc->cbin++;
hdlc->shift_reg >>= 1;
hdlc->bit_shift--;
if (hdlc->bit_shift == 0) {
hdlc->state = HDLC_SEND_DATA;
hdlc->crc = 0xffff;
hdlc->hdlc_bits1 = 0;
}
break;
case HDLC_SEND_DATA:
hdlc->cbin <<= 1;
hdlc->data_bits++;
if (hdlc->hdlc_bits1 == 5) {
hdlc->hdlc_bits1 = 0;
break;
}
if (hdlc->bit_shift == 8)
hdlc->crc = crc_ccitt_byte(hdlc->crc,
hdlc->shift_reg);
if (hdlc->shift_reg & 0x01) {
hdlc->hdlc_bits1++;
hdlc->cbin++;
hdlc->shift_reg >>= 1;
hdlc->bit_shift--;
} else {
hdlc->hdlc_bits1 = 0;
hdlc->shift_reg >>= 1;
hdlc->bit_shift--;
}
break;
case HDLC_SEND_CRC1:
hdlc->cbin <<= 1;
hdlc->data_bits++;
if (hdlc->hdlc_bits1 == 5) {
hdlc->hdlc_bits1 = 0;
break;
}
if (hdlc->shift_reg & 0x01) {
hdlc->hdlc_bits1++;
hdlc->cbin++;
hdlc->shift_reg >>= 1;
hdlc->bit_shift--;
} else {
hdlc->hdlc_bits1 = 0;
hdlc->shift_reg >>= 1;
hdlc->bit_shift--;
}
if (hdlc->bit_shift == 0) {
hdlc->shift_reg = (hdlc->crc >> 8);
hdlc->state = HDLC_SEND_CRC2;
hdlc->bit_shift = 8;
}
break;
case HDLC_SEND_CRC2:
hdlc->cbin <<= 1;
hdlc->data_bits++;
if (hdlc->hdlc_bits1 == 5) {
hdlc->hdlc_bits1 = 0;
break;
}
if (hdlc->shift_reg & 0x01) {
hdlc->hdlc_bits1++;
hdlc->cbin++;
hdlc->shift_reg >>= 1;
hdlc->bit_shift--;
} else {
hdlc->hdlc_bits1 = 0;
hdlc->shift_reg >>= 1;
hdlc->bit_shift--;
}
if (hdlc->bit_shift == 0) {
hdlc->shift_reg = 0x7e;
hdlc->state = HDLC_SEND_CLOSING_FLAG;
hdlc->bit_shift = 8;
}
break;
case HDLC_SEND_CLOSING_FLAG:
hdlc->cbin <<= 1;
hdlc->data_bits++;
if (hdlc->hdlc_bits1 == 5) {
hdlc->hdlc_bits1 = 0;
break;
}
if (hdlc->shift_reg & 0x01)
hdlc->cbin++;
hdlc->shift_reg >>= 1;
hdlc->bit_shift--;
if (hdlc->bit_shift == 0) {
hdlc->ffvalue =
xfast_flag_value[hdlc->data_bits];
if (hdlc->dchannel) {
hdlc->ffvalue = 0x7e;
hdlc->state = HDLC_SEND_IDLE1;
hdlc->bit_shift = 8-hdlc->data_bits;
if (hdlc->bit_shift == 0)
hdlc->state =
HDLC_SEND_FAST_IDLE;
} else {
if (!hdlc->do_adapt56) {
hdlc->state =
HDLC_SEND_FAST_FLAG;
hdlc->data_received = 0;
} else {
hdlc->state = HDLC_SENDFLAG_B0;
hdlc->data_received = 0;
}
if (dsize > 1)
dsize = 1;
}
}
break;
case HDLC_SEND_IDLE1:
hdlc->do_closing = 0;
hdlc->cbin <<= 1;
hdlc->cbin++;
hdlc->data_bits++;
hdlc->bit_shift--;
if (hdlc->bit_shift == 0) {
hdlc->state = HDLC_SEND_FAST_IDLE;
hdlc->bit_shift = 0;
}
break;
case HDLC_SEND_FAST_IDLE:
hdlc->do_closing = 0;
hdlc->cbin = 0xff;
hdlc->data_bits = 8;
if (hdlc->bit_shift == 8) {
hdlc->cbin = 0x7e;
hdlc->state = HDLC_SEND_FIRST_FLAG;
} else {
if (hdlc->do_bitreverse == 0)
*dst++ = bitrev8(hdlc->cbin);
else
*dst++ = hdlc->cbin;
hdlc->bit_shift = 0;
hdlc->data_bits = 0;
len++;
dsize = 0;
}
break;
default:
break;
}
if (hdlc->do_adapt56) {
if (hdlc->data_bits == 7) {
hdlc->cbin <<= 1;
hdlc->cbin++;
hdlc->data_bits++;
}
}
if (hdlc->data_bits == 8) {
if (hdlc->do_bitreverse == 0)
*dst++ = bitrev8(hdlc->cbin);
else
*dst++ = hdlc->cbin;
hdlc->data_bits = 0;
len++;
dsize--;
}
}
*count -= slen;
return len;
}
