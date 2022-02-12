static unsigned char
dect_getbit(guint8 *data, int bit)
{
guint8 byte=data[bit/8];
return (byte>>bit%8)&1;
}
static void
dect_setbit(guint8 *data, int bit, guint8 value)
{
if(!value)
data[bit/8]&=~(1<<(bit%8));
else
data[bit/8]|=(1<<(bit%8));
}
static guint8
calc_xcrc(guint8* data, guint8 length)
{
guint8 bits[21];
guint8 gp=0x1;
guint8 crc;
guint8 next;
int y, x;
memset(bits, 0, sizeof(bits));
for(y=0;y<=length-4;y++)
{
dect_setbit(bits, y, dect_getbit(data, y+48*(1+(int)(y/16))));
}
length=10;
crc=bits[0];
y=0;
while(y<length)
{
if(y<(length-1))
next=bits[y+1];
else
next=0;
y++;
x=0;
while(x<8)
{
while(!(crc&0x80))
{
crc<<=1;
crc|=!!(next&0x80);
next<<=1;
x++;
if(x>7)
break;
}
if(x>7)
break;
crc<<=1;
crc|=!!(next&0x80);
next<<=1;
x++;
crc^=(gp<<4);
}
}
return crc;
}
static guint16
calc_rcrc(guint8* data)
{
guint16 gp=0x0589;
guint16 crc;
guint8 next;
int y, x;
crc=data[0]<<8|data[1];
y=0;
while(y<6)
{
next=data[2+y];
y++;
x=0;
while(x<8)
{
while(!(crc&0x8000))
{
crc<<=1;
crc|=!!(next&0x80);
next<<=1;
x++;
if(x>7)
break;
}
if(x>7)
break;
crc<<=1;
crc|=!!(next&0x80);
next<<=1;
x++;
crc^=gp;
}
}
crc^=1;
return crc;
}
static gint
dissect_bfield(gboolean dect_packet_type _U_, guint8 ba,
packet_info *pinfo _U_, tvbuff_t *tvb, gint offset, proto_tree *DectTree, proto_tree *ColumnsTree)
{
guint8 xcrc;
guint16 blen;
gint start_offset;
const char *bfield_str;
const char *bfield_short_str;
proto_item *bfieldti = NULL;
proto_tree *BField = NULL;
proto_item *bfdescrdatati = NULL;
proto_tree *BFDescrData = NULL;
guint8 bfield_data[DECT_BFIELD_DATA_SIZE];
guint bfield_length = tvb_length_remaining(tvb, offset);
if (bfield_length > DECT_BFIELD_DATA_SIZE)
bfield_length = DECT_BFIELD_DATA_SIZE;
if (bfield_length)
tvb_memcpy(tvb, bfield_data, offset, bfield_length);
else
memset(bfield_data, 0, DECT_BFIELD_DATA_SIZE);
switch(ba)
{
case 0:
case 1:
case 3:
case 5:
case 6:
blen=40;
bfield_short_str="Full Slot";
bfield_str="Full Slot (320 bit data, 4 bit xcrc)";
break;
case 2:
blen=100;
bfield_short_str="Double Slot";
bfield_str="Double Slot (800 bit data, 4 bit xcrc)";
break;
case 4:
blen=10;
bfield_short_str="Half Slot";
bfield_str="Half Slot (80 bit data, 4 bit xcrc)";
break;
case 7:
default:
blen=0;
bfield_short_str="No B-Field";
bfield_str="No B-Field";
break;
}
proto_tree_add_string(ColumnsTree, hf_dect_cc_BField, tvb, offset, 1, bfield_short_str);
if(blen)
{
bfieldti = proto_tree_add_item(DectTree, hf_dect_B, tvb, offset, blen, ENC_NA);
BField = proto_item_add_subtree(bfieldti, ett_bfield);
proto_tree_add_none_format(BField, hf_dect_B_Data, tvb, offset, blen, "%s", bfield_str);
bfdescrdatati = proto_tree_add_item(BField, hf_dect_B_DescrambledData, tvb, offset, blen, ENC_NA);
BFDescrData = proto_item_add_subtree(bfdescrdatati, ett_bfdescrdata);
}
start_offset=offset;
if(blen<=bfield_length)
{
gint fn;
guint16 x, y;
for(fn=0;fn<8;fn++)
{
guint16 bytecount=0;
offset=start_offset;
proto_tree_add_none_format(BFDescrData, hf_dect_B_fn, tvb, offset, 0, "Framenumber %u/%u", fn, fn+8);
for(x=0;x<blen;x+=16)
{
wmem_strbuf_t *string;
string = wmem_strbuf_new(wmem_packet_scope(), NULL);
for(y=0;y<16;y++)
{
if((x+y)>=blen)
break;
wmem_strbuf_append_printf(string,"%.2x ", bfield_data[x+y]^scrt[fn][bytecount%31]);
bytecount++;
}
proto_tree_add_none_format(BFDescrData, hf_dect_B_Data, tvb, offset,
y, "Data: %s", wmem_strbuf_get_str(string));
offset+=y;
}
}
}
else
proto_tree_add_none_format(BField, hf_dect_B_Data, tvb, offset, 0, "Data too Short");
if(blen==40)
xcrc=calc_xcrc(bfield_data, 83);
else
xcrc=0;
if((unsigned)(blen+1)<=bfield_length)
{
if(xcrc!=(bfield_data[40]&0xf0))
proto_tree_add_uint_format(bfieldti, hf_dect_B_XCRC, tvb, offset, 1, 0, "X-CRC Error (Calc:%.2x, Recv:%.2x)",xcrc, bfield_data[40]&0xf0);
else
proto_tree_add_uint_format(bfieldti, hf_dect_B_XCRC, tvb, offset, 1, 1, "X-CRC Match (Calc:%.2x, Recv:%.2x)", xcrc, bfield_data[40]&0xf0);
}
else
proto_tree_add_uint_format(bfieldti, hf_dect_B_XCRC, tvb, offset, 1, 0, "No X-CRC logged (Calc:%.2x)", xcrc);
return offset;
}
static void
dissect_afield(gboolean dect_packet_type, guint8 *ba,
packet_info *pinfo _U_, tvbuff_t *tvb, gint offset, proto_tree *DectTree, proto_tree *ColumnsTree)
{
guint8 ta;
guint8 rcrcdat[8];
guint16 computed_rcrc;
wmem_strbuf_t *afield_str;
proto_item *afieldti = NULL;
proto_item *aheadti = NULL;
proto_item *atailti = NULL;
proto_tree *AField = NULL;
proto_tree *AHead = NULL;
proto_tree *ATail = NULL;
guint8 header, tail_0, tail_1, tail_2, tail_3, tail_4;
guint16 rcrc;
afield_str = wmem_strbuf_new(wmem_packet_scope(), NULL);
header = tvb_get_guint8(tvb, offset+0);
tail_0 = tvb_get_guint8(tvb, offset+1);
tail_1 = tvb_get_guint8(tvb, offset+2);
tail_2 = tvb_get_guint8(tvb, offset+3);
tail_3 = tvb_get_guint8(tvb, offset+4);
tail_4 = tvb_get_guint8(tvb, offset+5);
rcrc = tvb_get_ntohs(tvb, offset+6);
ta = (header & DECT_A_TA_MASK) >> DECT_A_TA_SHIFT;
*ba = (header & DECT_A_BA_MASK) >> DECT_A_BA_SHIFT;
afieldti = proto_tree_add_item(DectTree, hf_dect_A, tvb, offset, DECT_AFIELD_SIZE, ENC_NA);
AField = proto_item_add_subtree(afieldti, ett_afield);
aheadti = proto_tree_add_item(AField, hf_dect_A_Head, tvb, offset, 1, ENC_BIG_ENDIAN);
AHead = proto_item_add_subtree(aheadti, ett_ahead);
if(dect_packet_type==DECT_PACKET_FP)
proto_tree_add_item(AHead, hf_dect_A_Head_TA_FP, tvb, offset, 1, ENC_BIG_ENDIAN);
else
proto_tree_add_item(AHead, hf_dect_A_Head_TA_PP, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(AHead, hf_dect_A_Head_Q1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(AHead, hf_dect_A_Head_BA, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(AHead, hf_dect_A_Head_Q2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(dect_packet_type==DECT_PACKET_FP)
{
atailti = proto_tree_add_none_format(afieldti, hf_dect_A_Tail, tvb, offset, 5,
"FP-Tail: %s", val_to_str(ta, TA_vals_FP, "Error, please report: %d"));
}
else
{
atailti = proto_tree_add_none_format(afieldti, hf_dect_A_Tail, tvb, offset, 5,
"PP-Tail: %s", val_to_str(ta, TA_vals_PP, "Error, please report: %d"));
}
ATail = proto_item_add_subtree(atailti, ett_atail);
if((ta==DECT_TA_CT0)||(ta==DECT_TA_CT1))
{
proto_tree_add_string(ColumnsTree, hf_dect_cc_TA, tvb, offset, 1, "[Ct]");
if(ta==DECT_TA_CT0)
wmem_strbuf_append_printf(afield_str,"C-Channel Next Data: %s",tvb_bytes_to_str(tvb, offset, 5));
else
wmem_strbuf_append_printf(afield_str,"C-Channel First Data: %s",tvb_bytes_to_str(tvb, offset, 5));
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, wmem_strbuf_get_str(afield_str));
}
else if((ta==DECT_TA_NT)||(ta==DECT_TA_NT_CL))
{
proto_tree_add_string(ColumnsTree, hf_dect_cc_TA, tvb, offset, 1, "[Nt]");
wmem_strbuf_append_printf(afield_str,"RFPI: %s",tvb_bytes_to_str(tvb, offset, 5));
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, wmem_strbuf_get_str(afield_str));
proto_tree_add_item(atailti, hf_dect_A_Tail_Nt, tvb, offset, 5, ENC_NA);
}
else if(ta==DECT_TA_QT)
{
proto_tree_add_string(ColumnsTree, hf_dect_cc_TA, tvb, offset, 1, "[Qt]");
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_Qh, tvb, offset, 1, ENC_BIG_ENDIAN);
switch(tail_0>>4)
{
case 0:
case 1:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Static System Info");
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Nr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Sn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Sp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Esc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Txs, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Mc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_none_format(ATail, hf_dect_A_Tail_Qt_0_CA, tvb, offset, 2, " Carrier%s%s%s%s%s%s%s%s%s%s available",
(tail_1&0x02)?" 0":"", (tail_1&0x01)?" 1":"", (tail_2&0x80)?" 2":"",
(tail_2&0x40)?" 3":"", (tail_2&0x20)?" 4":"", (tail_2&0x10)?" 5":"",
(tail_2&0x08)?" 6":"", (tail_2&0x04)?" 7":"", (tail_2&0x02)?" 8":"",
(tail_2&0x01)?" 9":"");
offset+=2;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Spr1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Cn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_Spr2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_0_PSCN, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset-=5;
break;
case 2:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Extended RF Carriers Part 1");
break;
case 3:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Fixed Part Capabilities");
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A12, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A13, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A14, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A15, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A16, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A17, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A18, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A19, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A20, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A21, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A22, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A23, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A24, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A25, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A26, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A27, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A28, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A29, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A30, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A31, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A32, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A33, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A34, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A35, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A36, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A37, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A38, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A39, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A40, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A41, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A42, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A43, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A44, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A45, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A46, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_3_A47, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset-=5;
break;
case 4:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Extended Fixed Part Capabilities");
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_CRFPHops, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_CRFPEnc, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_REFHops, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_REPCap, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_Sync, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A20, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_MACSusp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_MACIpq, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A23, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A24, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A25, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A26, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A27, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A28, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A29, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A30, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A31, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A32, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A33, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A34, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A35, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A36, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A37, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A38, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A39, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A40, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A41, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A42, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A43, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A44, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A45, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A46, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_4_A47, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
offset-=5;
break;
case 5:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "SARI List Contents");
break;
case 6:
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_6_Spare, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
wmem_strbuf_append_printf(afield_str,"Multi-Frame No.: %s",tvb_bytes_to_str(tvb, offset, 3));
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, wmem_strbuf_get_str(afield_str));
proto_tree_add_item(ATail, hf_dect_A_Tail_Qt_6_Mfn, tvb, offset, 3, ENC_NA);
offset+=3;
offset-=5;
break;
case 7:
wmem_strbuf_append_printf(afield_str,"Escape Data: %s",tvb_bytes_to_str(tvb, offset, 5));
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, wmem_strbuf_get_str(afield_str));
break;
case 8:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Obsolete");
break;
case 9:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Extended RF Carriers Part 2");
break;
case 11:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Transmit Information");
break;
case 12:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Extended Fixed Part Capabilities 2");
break;
case 10:
case 13:
case 14:
case 15:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Reserved");
break;
}
}
else if(ta==DECT_TA_ESC)
{
}
else if((ta==DECT_TA_MT)||((ta==DECT_TA_MT_FIRST)&&(dect_packet_type==DECT_PACKET_PP)))
{
proto_tree_add_string(ColumnsTree, hf_dect_cc_TA, tvb, offset, 1, "[Mt]");
proto_tree_add_uint(ATail, hf_dect_A_Tail_Mt_Mh, tvb, offset, 1, tail_0);
switch(tail_0>>4)
{
case 0:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Basic Connection Control");
proto_tree_add_item(ATail, hf_dect_A_Tail_Mt_BasicConCtrl, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if(((tail_0 & 0x0f)==6)||((tail_0 & 0x0f)==7))
{
proto_tree_add_none_format(ATail, hf_dect_A_Tail_Mt_Mh_attr, tvb, offset, 4, "More infos at ETSI EN 300 175-3 V2.3.0 7.2.5.2.4");
offset +=4;
}
else
{
proto_tree_add_item(ATail, hf_dect_A_Tail_Mt_Mh_fmid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Mt_Mh_pmid, tvb, offset, 3, ENC_BIG_ENDIAN);
offset+=3;
}
offset-=5;
break;
case 1:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Advanced Connection Control");
break;
case 2:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "MAC Layer Test Messages");
break;
case 3:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Quality Control");
break;
case 4:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Broadcast and Connectionless Services");
break;
case 5:
wmem_strbuf_append_printf(afield_str,"Encryption Control: %s %s",
val_to_str((tail_0&0x0c)>>2, MTEncrCmd1_vals, "Error, please report: %d"),
val_to_str(tail_0&0x03, MTEncrCmd2_vals, "Error, please report: %d"));
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, wmem_strbuf_get_str(afield_str));
proto_tree_add_item(ATail, hf_dect_A_Tail_Mt_Encr_Cmd1, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Mt_Encr_Cmd2, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Mt_Mh_fmid, tvb, offset, 2, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Mt_Mh_pmid, tvb, offset, 3, ENC_BIG_ENDIAN);
offset+=3;
offset-=5;
break;
case 6:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Tail for use with the first Transmission of a B-Field \"bearer request\" Message");
break;
case 7:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Escape");
break;
case 8:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "TARI Message");
break;
case 9:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "REP Connection Control");
break;
case 10:
case 11:
case 12:
case 13:
case 14:
case 15:
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, "Reserved");
break;
}
}
else if((ta==DECT_TA_PT)&&(dect_packet_type==DECT_PACKET_FP))
{
proto_tree_add_string(ColumnsTree, hf_dect_cc_TA, tvb, offset, 1, "[Pt]");
proto_tree_add_item(ATail, hf_dect_A_Tail_Pt_ExtFlag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Pt_SDU, tvb, offset, 1, ENC_BIG_ENDIAN);
if(((tail_0&0x70)>>4)&0xfe)
wmem_strbuf_append_printf(afield_str,"%s, ",val_to_str((tail_0&0x70)>>4, PTSDU_vals, "Error, please report: %d"));
switch((tail_0&0x70)>>4)
{
case 0:
case 1:
if(((tail_0&0x70)>>4)==0)
{
wmem_strbuf_append_printf(afield_str,"RFPI: xxxxx%.1x%.2x%.2x, ", (tail_0&0x0f), tail_1, tail_2);
proto_tree_add_none_format(atailti, hf_dect_A_Tail_Pt_RFPI, tvb, offset, 3, "RFPI: xxxxx%.1x%.2x%.2x", (tail_0&0x0f), tail_1, tail_2);
offset+=3;
proto_tree_add_item(ATail, hf_dect_A_Tail_Pt_InfoType, tvb, offset, 1, ENC_BIG_ENDIAN);
}
else
{
wmem_strbuf_append_printf(afield_str,"Bs Data: %.1x%.2x%.2x, ", (tail_0&0x0f), tail_1, tail_2);
proto_tree_add_none_format(atailti, hf_dect_A_Tail_Pt_BsData, tvb, offset, 3, "Bs Data: %.1x%.2x%.2x", (tail_0&0x0f), tail_1, tail_2);
offset+=3;
proto_tree_add_item(ATail, hf_dect_A_Tail_Pt_InfoType, tvb, offset, 1, ENC_BIG_ENDIAN);
}
wmem_strbuf_append_printf(afield_str,"%s",val_to_str(tail_3>>4, PTInfoType_vals, "Error, please report: %d"));
switch(tail_3>>4)
{
case 0:
proto_tree_add_none_format(ATail, hf_dect_A_Tail_Pt_Fillbits, tvb, offset, 2, "Fillbits: %.1x%.2x", tail_3&0x0f, tail_4);
offset+=2;
break;
case 1:
offset+=2;
break;
case 7:
offset+=2;
break;
case 8:
proto_tree_add_none_format(ATail, hf_dect_A_Tail_Pt_SlotPairs, tvb, offset, 2, " Slot-Pairs: %s%s%s%s%s%s%s%s%s%s%s%s available",
(tail_3&0x08)?" 0/12":"", (tail_3&0x04)?" 1/13":"", (tail_3&0x02)?" 2/14":"",
(tail_3&0x01)?" 3/15":"", (tail_4&0x80)?" 4/16":"", (tail_4&0x40)?" 5/17":"",
(tail_4&0x20)?" 6/18":"", (tail_4&0x10)?" 7/19":"", (tail_4&0x08)?" 8/20":"",
(tail_4&0x04)?" 9/21":"", (tail_4&0x02)?" 10/22":"", (tail_4&0x01)?" 11/23":"");
offset+=2;
break;
case 2:
case 3:
case 4:
case 5:
case 12:
proto_tree_add_item(ATail, hf_dect_A_Tail_Pt_Bearer_Sn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(ATail, hf_dect_A_Tail_Pt_Bearer_Sp, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(ATail, hf_dect_A_Tail_Pt_Bearer_Cn, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 6:
offset+=2;
break;
case 9:
offset+=2;
break;
case 10:
offset+=2;
break;
case 11:
offset+=2;
break;
case 13:
offset+=2;
break;
case 14:
offset+=2;
break;
case 15:
offset+=2;
break;
}
offset-=5;
break;
case 2:
wmem_strbuf_append_printf(afield_str,"Full Page");
break;
case 3:
wmem_strbuf_append_printf(afield_str,"MAC Resume Page");
break;
case 4:
wmem_strbuf_append_printf(afield_str,"Not the Last 36 Bits");
break;
case 5:
wmem_strbuf_append_printf(afield_str,"The First 36 Bits");
break;
case 6:
wmem_strbuf_append_printf(afield_str,"The Last 36 Bits");
break;
case 7:
wmem_strbuf_append_printf(afield_str,"All of a Long Page");
break;
}
proto_tree_add_string(ColumnsTree, hf_dect_cc_AField, tvb, offset, 1, wmem_strbuf_get_str(afield_str));
}
offset+=5;
tvb_memcpy(tvb, rcrcdat, DECT_PACKET_INFO_LEN, 6);
rcrcdat[6]=0;
rcrcdat[7]=0;
computed_rcrc=calc_rcrc(rcrcdat);
if(computed_rcrc!=rcrc)
proto_tree_add_uint_format(afieldti, hf_dect_A_RCRC, tvb, offset, 2, 0, "R-CRC Error (Calc:%.4x, Recv:%.4x)", computed_rcrc, rcrc);
else
proto_tree_add_uint_format(afieldti, hf_dect_A_RCRC, tvb, offset, 2, 1, "R-CRC Match (Calc:%.4x, Recv:%.4x)", computed_rcrc, rcrc);
}
static void
dissect_dect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti =NULL;
proto_item *typeti =NULL;
proto_tree *DectTree =NULL;
gint offset =0;
guint16 type;
guint pkt_len;
guint8 ba;
proto_item *columnstreeti;
proto_tree *ColumnsTree;
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "Use Custom Columns for Infos");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DECT");
pkt_len=tvb_length(tvb);
if(pkt_len<=DECT_PACKET_INFO_LEN)
{
col_set_str(pinfo->cinfo, COL_INFO, "No Data");
return;
}
ti=proto_tree_add_item(tree, proto_dect, tvb, 0, -1, ENC_NA);
DectTree=proto_item_add_subtree(ti, ett_dect);
proto_tree_add_item(DectTree, hf_dect_transceivermode, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(DectTree, hf_dect_channel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(DectTree, hf_dect_slot, tvb, offset, 2, ENC_BIG_ENDIAN);
offset+=2;
proto_tree_add_item(DectTree, hf_dect_framenumber, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(DectTree, hf_dect_rssi, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
proto_tree_add_item(DectTree, hf_dect_preamble, tvb, offset, 3, ENC_NA);
offset+=3;
typeti=proto_tree_add_item(DectTree, hf_dect_type, tvb, offset, 2, ENC_NA);
type=tvb_get_ntohs(tvb, offset);
offset+=2;
columnstreeti = proto_tree_add_item(DectTree, hf_dect_cc, tvb, 0, 0, ENC_NA);
ColumnsTree = proto_item_add_subtree(columnstreeti, ett_afield);
switch(type) {
case 0x1675:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DECT PP");
proto_item_append_text(typeti, " Phone Packet");
dissect_afield(DECT_PACKET_PP, &ba, pinfo, tvb, offset, DectTree, ColumnsTree);
offset += DECT_AFIELD_SIZE;
dissect_bfield(DECT_PACKET_PP, ba, pinfo, tvb, offset, DectTree, ColumnsTree);
break;
case 0xe98a:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DECT RFP");
proto_item_append_text(typeti, " Station Packet");
dissect_afield(DECT_PACKET_FP, &ba, pinfo, tvb, offset, DectTree, ColumnsTree);
offset += DECT_AFIELD_SIZE;
dissect_bfield(DECT_PACKET_FP, ba, pinfo, tvb, offset, DectTree, ColumnsTree);
break;
default:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "DECT Unk");
proto_item_append_text(typeti, " Unknown Packet");
break;
}
}
void
proto_register_dect(void)
{
static hf_register_info hf[]=
{
{ &hf_dect_transceivermode,
{"Tranceiver-Mode", "dect.tranceivermode", FT_UINT8, BASE_HEX, VALS(tranceiver_mode),
0x0, NULL, HFILL}},
{ &hf_dect_channel,
{"Channel", "dect.channel", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_framenumber,
{"Frame#", "dect.framenumber", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_rssi,
{"RSSI", "dect.rssi", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_slot,
{"Slot", "dect.slot", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_preamble,
{"Preamble", "dect.preamble", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_type,
{"Packet-Type", "dect.type", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_cc,
{"Columns", "dect.cc", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_cc_TA,
{"TA", "dect.cc.TA", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_cc_AField,
{"A-Field", "dect.cc.afield", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_cc_BField,
{"B-Field", "dect.cc.bfield", FT_STRING, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A,
{"A-Field", "dect.afield", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Head,
{"A-Field Header", "dect.afield.head", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Head_TA_FP,
{"TA", "dect.afield.head.TA", FT_UINT8, BASE_DEC, VALS(TA_vals_FP),
DECT_A_TA_MASK, NULL, HFILL}},
{ &hf_dect_A_Head_TA_PP,
{"TA", "dect.afield.head.TA", FT_UINT8, BASE_DEC, VALS(TA_vals_PP),
DECT_A_TA_MASK, NULL, HFILL}},
{ &hf_dect_A_Head_Q1,
{"Q1", "dect.afield.head.Q1", FT_UINT8, BASE_DEC, NULL,
DECT_A_Q1_MASK, NULL, HFILL}},
{ &hf_dect_A_Head_BA,
{"BA", "dect.afield.head.BA", FT_UINT8, BASE_DEC, VALS(BA_vals),
DECT_A_BA_MASK, NULL, HFILL}},
{ &hf_dect_A_Head_Q2,
{"Q2", "dect.afield.head.Q2", FT_UINT8, BASE_DEC, NULL,
DECT_A_Q2_MASK, NULL, HFILL}},
{ &hf_dect_A_Tail,
{"A-Field Tail", "dect.afield.tail", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Tail_Nt,
{"RFPI", "dect.afield.tail.Nt", FT_BYTES, BASE_NONE, NULL,
0x0, "A-Field Tail: Nt/RFPI", HFILL}},
{ &hf_dect_A_Tail_Qt_Qh,
{"Qh", "dect.afield.tail.Qt.Qh", FT_UINT8, BASE_DEC, VALS(QTHead_vals),
0xF0, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Nr,
{"NR", "dect.afield.tail.Qt.NR", FT_UINT8, BASE_DEC, VALS(QTNormalReverse_vals),
0x10, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Sn,
{"SN", "dect.afield.tail.Qt.SN", FT_UINT8, BASE_DEC, VALS(QTSlotNumber_vals),
0x0F, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Sp,
{"SP", "dect.afield.tail.Qt.SP", FT_UINT8, BASE_DEC, VALS(QTStartPosition_vals),
0xC0, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Esc,
{"Esc", "dect.afield.tail.Qt.Esc", FT_UINT8, BASE_DEC, VALS(QTEscape_vals),
0x20, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Txs,
{"Txs", "dect.afield.tail.Qt.Txs", FT_UINT8, BASE_DEC, VALS(QTTranceiver_vals),
0x18, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Mc,
{"Mc", "dect.afield.tail.Qt.Mc", FT_UINT8, BASE_DEC, VALS(QTExtendedCarrier_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_CA,
{"CA", "dect.afield.tail.Qt.CA", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Spr1,
{"Spr1", "dect.afield.tail.Qt.Spr1", FT_UINT8, BASE_DEC, VALS(QTSpr_vals),
0xC0, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Cn,
{"CN", "dect.afield.tail.Qt.CN", FT_UINT8, BASE_DEC, VALS(QTCarrierNumber_vals),
0x3F, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_Spr2,
{"Spr2", "dect.afield.tail.Qt.Spr2", FT_UINT8, BASE_DEC, VALS(QTSpr_vals),
0xC0, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_0_PSCN,
{"PSCN", "dect.afield.tail.Qt.PSCN", FT_UINT8, BASE_DEC, VALS(QTScanCarrierNum_vals),
0x3F, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A12,
{"A12", "dect.afield.tail.Qt.Fp.A12", FT_UINT8, BASE_DEC, VALS(Qt_A12_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A13,
{"A13", "dect.afield.tail.Qt.Fp.A13", FT_UINT8, BASE_DEC, VALS(Qt_A13_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A14,
{"A14", "dect.afield.tail.Qt.Fp.A14", FT_UINT8, BASE_DEC, VALS(Qt_A14_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A15,
{"A15", "dect.afield.tail.Qt.Fp.A15", FT_UINT8, BASE_DEC, VALS(Qt_A15_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A16,
{"A16", "dect.afield.tail.Qt.Fp.A16", FT_UINT8, BASE_DEC, VALS(Qt_A16_vals),
0x80, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A17,
{"A17", "dect.afield.tail.Qt.Fp.A17", FT_UINT8, BASE_DEC, VALS(Qt_A17_vals),
0x40, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A18,
{"A18", "dect.afield.tail.Qt.Fp.A18", FT_UINT8, BASE_DEC, VALS(Qt_A18_vals),
0x20, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A19,
{"A19", "dect.afield.tail.Qt.Fp.A19", FT_UINT8, BASE_DEC, VALS(Qt_A19_vals),
0x10, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A20,
{"A20", "dect.afield.tail.Qt.Fp.A20", FT_UINT8, BASE_DEC, VALS(Qt_A20_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A21,
{"A21", "dect.afield.tail.Qt.Fp.A21", FT_UINT8, BASE_DEC, VALS(Qt_A21_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A22,
{"A22", "dect.afield.tail.Qt.Fp.A22", FT_UINT8, BASE_DEC, VALS(Qt_A22_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A23,
{"A23", "dect.afield.tail.Qt.Fp.A23", FT_UINT8, BASE_DEC, VALS(Qt_A23_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A24,
{"A24", "dect.afield.tail.Qt.Fp.A24", FT_UINT8, BASE_DEC, VALS(Qt_A24_vals),
0x80, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A25,
{"A25", "dect.afield.tail.Qt.Fp.A25", FT_UINT8, BASE_DEC, VALS(Qt_A25_vals),
0x40, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A26,
{"A26", "dect.afield.tail.Qt.Fp.A26", FT_UINT8, BASE_DEC, VALS(Qt_A26_vals),
0x20, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A27,
{"A27", "dect.afield.tail.Qt.Fp.A27", FT_UINT8, BASE_DEC, VALS(Qt_A27_vals),
0x10, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A28,
{"A28", "dect.afield.tail.Qt.Fp.A28", FT_UINT8, BASE_DEC, VALS(Qt_A28_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A29,
{"A29", "dect.afield.tail.Qt.Fp.A29", FT_UINT8, BASE_DEC, VALS(Qt_A29_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A30,
{"A30", "dect.afield.tail.Qt.Fp.A30", FT_UINT8, BASE_DEC, VALS(Qt_A30_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A31,
{"A31", "dect.afield.tail.Qt.Fp.A31", FT_UINT8, BASE_DEC, VALS(Qt_A31_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A32,
{"A32", "dect.afield.tail.Qt.Fp.A32", FT_UINT8, BASE_DEC, VALS(Qt_A32_vals),
0x80, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A33,
{"A33", "dect.afield.tail.Qt.Fp.A33", FT_UINT8, BASE_DEC, VALS(Qt_A33_vals),
0x40, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A34,
{"A34", "dect.afield.tail.Qt.Fp.A34", FT_UINT8, BASE_DEC, VALS(Qt_A34_vals),
0x20, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A35,
{"A35", "dect.afield.tail.Qt.Fp.A35", FT_UINT8, BASE_DEC, VALS(Qt_A35_vals),
0x10, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A36,
{"A36", "dect.afield.tail.Qt.Fp.A36", FT_UINT8, BASE_DEC, VALS(Qt_A36_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A37,
{"A37", "dect.afield.tail.Qt.Fp.A37", FT_UINT8, BASE_DEC, VALS(Qt_A37_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A38,
{"A38", "dect.afield.tail.Qt.Fp.A38", FT_UINT8, BASE_DEC, VALS(Qt_A38_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A39,
{"A39", "dect.afield.tail.Qt.Fp.A39", FT_UINT8, BASE_DEC, VALS(Qt_A39_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A40,
{"A40", "dect.afield.tail.Qt.Fp.A40", FT_UINT8, BASE_DEC, VALS(Qt_A40_vals),
0x80, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A41,
{"A41", "dect.afield.tail.Qt.Fp.A41", FT_UINT8, BASE_DEC, VALS(Qt_A41_vals),
0x40, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A42,
{"A42", "dect.afield.tail.Qt.Fp.A42", FT_UINT8, BASE_DEC, VALS(Qt_A42_vals),
0x20, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A43,
{"A43", "dect.afield.tail.Qt.Fp.A43", FT_UINT8, BASE_DEC, VALS(Qt_A43_vals),
0x10, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A44,
{"A44", "dect.afield.tail.Qt.Fp.A44", FT_UINT8, BASE_DEC, VALS(Qt_A44_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A45,
{"A45", "dect.afield.tail.Qt.Fp.A45", FT_UINT8, BASE_DEC, VALS(Qt_A45_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A46,
{"A46", "dect.afield.tail.Qt.Fp.A46", FT_UINT8, BASE_DEC, VALS(Qt_A46_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_3_A47,
{"A47", "dect.afield.tail.Qt.Fp.A47", FT_UINT8, BASE_DEC, VALS(Qt_A47_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_CRFPHops,
{"CRFP Hops", "dect.afield.tail.Qt.Efp.CRFPHops", FT_UINT8, BASE_DEC, VALS(Qt_CRFPHops_vals),
0x0C, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_CRFPEnc,
{"CRFP Enc", "dect.afield.tail.Qt.Efp.CRFPEnc", FT_UINT8, BASE_DEC, VALS(Qt_CRFPEnc_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_REFHops,
{"REP Hops", "dect.afield.tail.Qt.Efp.REPHops", FT_UINT16, BASE_DEC, VALS(Qt_REPHops_vals),
0x0180, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_REPCap,
{"REP Cap.", "dect.afield.tail.Qt.Efp.REPCap", FT_UINT8, BASE_DEC, VALS(Qt_REPCap_vals),
0x40, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_Sync,
{"Sync", "dect.afield.tail.Qt.Efp.Sync", FT_UINT8, BASE_DEC, VALS(Qt_Sync_vals),
0x30, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A20,
{"A20", "dect.afield.tail.Qt.Efp.A20", FT_UINT8, BASE_DEC, VALS(Qt_EA20_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_MACSusp,
{"MAC Suspend", "dect.afield.tail.Qt.Efp.MACSusp", FT_UINT8, BASE_DEC, VALS(Qt_MACSusp_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_MACIpq,
{"MAC Ipq", "dect.afield.tail.Qt.Efp.MACIpq", FT_UINT8, BASE_DEC, VALS(Qt_MACIpq_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A23,
{"A23", "dect.afield.tail.Qt.Efp.A23", FT_UINT8, BASE_DEC, VALS(Qt_EA23_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A24,
{"A24", "dect.afield.tail.Qt.Efp.A24", FT_UINT8, BASE_DEC, VALS(Qt_EA24_vals),
0x80, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A25,
{"A25", "dect.afield.tail.Qt.Efp.A25", FT_UINT8, BASE_DEC, VALS(Qt_EA25_vals),
0x40, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A26,
{"A26", "dect.afield.tail.Qt.Efp.A26", FT_UINT8, BASE_DEC, VALS(Qt_EA26_vals),
0x20, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A27,
{"A27", "dect.afield.tail.Qt.Efp.A27", FT_UINT8, BASE_DEC, VALS(Qt_EA27_vals),
0x10, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A28,
{"A28", "dect.afield.tail.Qt.Efp.A28", FT_UINT8, BASE_DEC, VALS(Qt_EA28_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A29,
{"A29", "dect.afield.tail.Qt.Efp.A29", FT_UINT8, BASE_DEC, VALS(Qt_EA29_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A30,
{"A30", "dect.afield.tail.Qt.Efp.A30", FT_UINT8, BASE_DEC, VALS(Qt_EA30_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A31,
{"A31", "dect.afield.tail.Qt.Efp.A31", FT_UINT8, BASE_DEC, VALS(Qt_EA31_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A32,
{"A32", "dect.afield.tail.Qt.Efp.A32", FT_UINT8, BASE_DEC, VALS(Qt_EA32_vals),
0x80, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A33,
{"A33", "dect.afield.tail.Qt.Efp.A33", FT_UINT8, BASE_DEC, VALS(Qt_EA33_vals),
0x40, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A34,
{"A34", "dect.afield.tail.Qt.Efp.A34", FT_UINT8, BASE_DEC, VALS(Qt_EA34_vals),
0x20, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A35,
{"A35", "dect.afield.tail.Qt.Efp.A35", FT_UINT8, BASE_DEC, VALS(Qt_EA35_vals),
0x10, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A36,
{"A36", "dect.afield.tail.Qt.Efp.A36", FT_UINT8, BASE_DEC, VALS(Qt_EA36_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A37,
{"A37", "dect.afield.tail.Qt.Efp.A37", FT_UINT8, BASE_DEC, VALS(Qt_EA37_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A38,
{"A38", "dect.afield.tail.Qt.Efp.A38", FT_UINT8, BASE_DEC, VALS(Qt_EA38_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A39,
{"A39", "dect.afield.tail.Qt.Efp.A39", FT_UINT8, BASE_DEC, VALS(Qt_EA39_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A40,
{"A40", "dect.afield.tail.Qt.Efp.A40", FT_UINT8, BASE_DEC, VALS(Qt_EA40_vals),
0x80, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A41,
{"A41", "dect.afield.tail.Qt.Efp.A41", FT_UINT8, BASE_DEC, VALS(Qt_EA41_vals),
0x40, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A42,
{"A42", "dect.afield.tail.Qt.Efp.A42", FT_UINT8, BASE_DEC, VALS(Qt_EA42_vals),
0x20, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A43,
{"A43", "dect.afield.tail.Qt.Efp.A43", FT_UINT8, BASE_DEC, VALS(Qt_EA43_vals),
0x10, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A44,
{"A44", "dect.afield.tail.Qt.Efp.A44", FT_UINT8, BASE_DEC, VALS(Qt_EA44_vals),
0x08, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A45,
{"A45", "dect.afield.tail.Qt.Efp.A45", FT_UINT8, BASE_DEC, VALS(Qt_EA45_vals),
0x04, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A46,
{"A46", "dect.afield.tail.Qt.Efp.A46", FT_UINT8, BASE_DEC, VALS(Qt_EA46_vals),
0x02, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_4_A47,
{"A47", "dect.afield.tail.Qt.Efp.A47", FT_UINT8, BASE_DEC, VALS(Qt_EA47_vals),
0x01, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_6_Spare,
{"Spare Bits", "dect.afield.tail.Qt.Mfn.Spare", FT_UINT16, BASE_HEX, NULL,
0x0FFF, NULL, HFILL}},
{ &hf_dect_A_Tail_Qt_6_Mfn,
{"Multiframe Number", "dect.afield.tail.Qt.Mfn.Mfn", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Tail_Mt_Mh,
{"Mh", "dect.afield.tail.Mt.Mh", FT_UINT8, BASE_DEC, VALS(MTHead_vals),
0xF0, NULL, HFILL}},
{ &hf_dect_A_Tail_Mt_Mh_attr,
{"Mh", "dect.afield.tail.Mt.Mh.attr", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Tail_Mt_Mh_fmid,
{"Mh/FMID", "dect.afield.tail.Mt.Mh.fmid", FT_UINT16, BASE_HEX, NULL,
0xFFF0, NULL, HFILL}},
{ &hf_dect_A_Tail_Mt_Mh_pmid,
{"Mh/PMID", "dect.afield.tail.Mt.Mh.pmid", FT_UINT24, BASE_HEX, NULL,
0x0FFFFF, NULL, HFILL}},
{ &hf_dect_A_Tail_Mt_BasicConCtrl,
{"Cmd", "dect.afield.tail.Mt.BasicConCtrl", FT_UINT8, BASE_DEC, VALS(MTBasicConCtrl_vals),
0x0F, NULL, HFILL}},
{ &hf_dect_A_Tail_Mt_Encr_Cmd1,
{"Cmd1", "dect.afield.tail.Mt.Encr.Cmd1", FT_UINT8, BASE_DEC, VALS(MTEncrCmd1_vals),
0x0C, NULL, HFILL}},
{ &hf_dect_A_Tail_Mt_Encr_Cmd2,
{"Cmd2", "dect.afield.tail.Mt.Encr.Cmd2", FT_UINT8, BASE_DEC, VALS(MTEncrCmd2_vals),
0x03, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_ExtFlag,
{"ExtFlag", "dect.afield.tail.Pt.ExtFlag", FT_UINT8, BASE_DEC, VALS(PTExtFlag_vals),
0x80, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_SDU,
{"Bs SDU", "dect.afield.tail.Pt.SDU", FT_UINT8, BASE_DEC, VALS(PTSDU_vals),
0x70, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_RFPI,
{"InfoType", "dect.afield.tail.Pt.RFPI", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_BsData,
{"Bs Data", "dect.afield.tail.Pt.BsData", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_InfoType,
{"InfoType", "dect.afield.tail.Pt.InfoType", FT_UINT8, BASE_DEC, VALS(PTInfoType_vals),
0xF0, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_Fillbits,
{"FillBits", "dect.afield.tail.Pt.FillBits", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_SlotPairs,
{"SlotPairs", "dect.afield.tail.Pt.SlotPairs", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_Bearer_Sn,
{"SN", "dect.afield.tail.Pt.SN", FT_UINT8, BASE_DEC, VALS(QTSlotNumber_vals),
0x0F, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_Bearer_Sp,
{"SP", "dect.afield.tail.Pt.SP", FT_UINT8, BASE_DEC, VALS(QTStartPosition_vals),
0xC0, NULL, HFILL}},
{ &hf_dect_A_Tail_Pt_Bearer_Cn,
{"CN", "dect.afield.tail.Pt.CN", FT_UINT8, BASE_DEC, VALS(QTCarrierNumber_vals),
0x3F, NULL, HFILL}},
{ &hf_dect_A_RCRC,
{"A-Field R-CRC", "dect.afield.rcrc", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_B,
{"B-Field", "dect.bfield", FT_BYTES, BASE_NONE,
0x0, 0x0, NULL, HFILL}},
{ &hf_dect_B_Data,
{"B-Field", "dect.bfield.data", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_B_DescrambledData,
{"Descrambled Data", "dect.bfield.descrdata", FT_NONE, BASE_NONE,
0x0, 0x0, NULL, HFILL}},
{ &hf_dect_B_fn,
{"B-Field", "dect.bfield.framenumber", FT_NONE, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_dect_B_XCRC,
{"B-Field X-CRC", "dect.bfield.xcrc", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}}
};
static gint *ett[]=
{
&ett_dect,
&ett_columns,
&ett_ahead,
&ett_afield,
&ett_atail,
&ett_aqt,
&ett_bfield,
&ett_bfdescrdata
};
proto_dect=proto_register_protocol("DECT Protocol", "DECT", "dect");
proto_register_field_array(proto_dect, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_dect(void)
{
dissector_handle_t dect_handle;
dect_handle = create_dissector_handle(dissect_dect, proto_dect);
dissector_add_uint("ethertype", ETHERTYPE_DECT , dect_handle);
}
