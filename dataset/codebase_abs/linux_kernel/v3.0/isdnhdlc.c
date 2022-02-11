void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_4 = V_5 ;
if ( V_3 & V_6 )
V_2 -> V_7 = 1 ;
if ( V_3 & V_8 )
V_2 -> V_9 = 1 ;
}
void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
if ( V_3 & V_10 ) {
V_2 -> V_11 = 1 ;
V_2 -> V_4 = V_12 ;
} else {
V_2 -> V_11 = 0 ;
V_2 -> V_4 = V_13 ;
V_2 -> V_14 = 0x7e ;
}
V_2 -> V_15 = 0x7e ;
if ( V_3 & V_6 ) {
V_2 -> V_7 = 1 ;
V_2 -> V_4 = V_16 ;
} else
V_2 -> V_17 = 8 ;
if ( V_3 & V_8 )
V_2 -> V_9 = 1 ;
}
static int
F_3 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_19 < 2 )
V_18 = - V_20 ;
else if ( V_2 -> V_21 != 0xf0b8 )
V_18 = - V_22 ;
else {
V_2 -> V_19 -= 2 ;
V_18 = V_2 -> V_19 ;
}
return V_18 ;
}
int F_4 ( struct V_1 * V_2 , const T_2 * V_23 , int V_24 ,
int * V_25 , T_2 * V_26 , int V_27 )
{
int V_18 = 0 ;
static const unsigned char V_28 [] = {
0x00 , 0x00 , 0x00 , 0x20 , 0x30 , 0x38 , 0x3c , 0x3e , 0x3f
} ;
static const unsigned char V_29 [] = {
0x00 , 0x7e , 0xfc , 0xf9 , 0xf3 , 0xe7 , 0xcf , 0x9f , 0x3f
} ;
static const unsigned char V_30 [] = {
0x00 , 0x00 , 0x80 , 0xc0 , 0xe0 , 0xf0 , 0xf8 , 0xfc , 0xfe , 0xff
} ;
#define F_5 ( T_3 ) \
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
#define F_6 ( T_3 ) \
do {\
h->shift_reg = fast_abort[h->ffbit_shift - 1];\
h->hdlc_bits1 = h->ffbit_shift - 2;\
if (h->hdlc_bits1 < 0)\
h->hdlc_bits1 = 0;\
h->data_bits = h->ffbit_shift - 1;\
h->state = HDLC_GET_DATA;\
h->data_received = 0;\
} while (0)
* V_25 = V_24 ;
while ( V_24 > 0 ) {
if ( V_2 -> V_31 == 0 ) {
if ( V_2 -> V_9 == 0 )
V_2 -> V_15 = F_7 ( * V_23 ++ ) ;
else
V_2 -> V_15 = * V_23 ++ ;
V_24 -- ;
V_2 -> V_31 = 8 ;
if ( V_2 -> V_7 )
V_2 -> V_31 -- ;
}
switch ( V_2 -> V_4 ) {
case V_32 :
return 0 ;
case V_33 :
if ( V_2 -> V_15 == 0xff ) {
V_2 -> V_31 = 0 ;
break;
}
V_2 -> V_4 = V_34 ;
V_2 -> V_35 = 0 ;
V_2 -> V_31 = 8 ;
break;
case V_34 :
if ( ! ( V_2 -> V_15 & 0x80 ) ) {
V_2 -> V_4 = V_36 ;
V_2 -> V_35 = 0 ;
} else {
if ( ( ! V_2 -> V_7 ) &&
( ++ V_2 -> V_35 >= 8 ) &&
( V_2 -> V_31 == 1 ) )
V_2 -> V_4 = V_33 ;
}
V_2 -> V_15 <<= 1 ;
V_2 -> V_31 -- ;
break;
case V_36 :
if ( V_2 -> V_15 & 0x80 ) {
V_2 -> V_35 ++ ;
if ( V_2 -> V_35 == 6 )
V_2 -> V_4 = V_37 ;
} else
V_2 -> V_35 = 0 ;
V_2 -> V_15 <<= 1 ;
V_2 -> V_31 -- ;
break;
case V_37 :
if ( V_2 -> V_15 & 0x80 ) {
V_2 -> V_4 = V_34 ;
} else {
V_2 -> V_4 = V_5 ;
V_2 -> V_21 = 0xffff ;
V_2 -> V_38 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_39 = 0 ;
}
V_2 -> V_15 <<= 1 ;
V_2 -> V_31 -- ;
break;
case V_5 :
if ( V_2 -> V_15 & 0x80 ) {
V_2 -> V_35 ++ ;
switch ( V_2 -> V_35 ) {
case 6 :
break;
case 7 :
if ( V_2 -> V_39 )
V_18 = - V_20 ;
if ( ! V_2 -> V_7 ) {
if ( V_2 -> V_15 == V_30
[ V_2 -> V_31 + 1 ] ) {
V_2 -> V_4 =
V_33 ;
V_2 -> V_31 = 1 ;
break;
}
} else
V_2 -> V_4 = V_34 ;
break;
default:
V_2 -> V_38 >>= 1 ;
V_2 -> V_38 |= 0x80 ;
V_2 -> V_17 ++ ;
break;
}
} else {
switch ( V_2 -> V_35 ) {
case 5 :
break;
case 6 :
if ( V_2 -> V_39 )
V_18 = F_3 ( V_2 ) ;
V_2 -> V_21 = 0xffff ;
V_2 -> V_38 = 0 ;
V_2 -> V_17 = 0 ;
if ( ! V_2 -> V_7 )
F_5 ( V_2 ) ;
else {
V_2 -> V_4 = V_5 ;
V_2 -> V_39 = 0 ;
}
break;
default:
V_2 -> V_38 >>= 1 ;
V_2 -> V_17 ++ ;
break;
}
V_2 -> V_35 = 0 ;
}
if ( V_18 ) {
V_2 -> V_19 = 0 ;
* V_25 -= V_24 ;
V_2 -> V_15 <<= 1 ;
V_2 -> V_31 -- ;
return V_18 ;
}
if ( V_2 -> V_17 == 8 ) {
V_2 -> V_17 = 0 ;
V_2 -> V_39 = 1 ;
V_2 -> V_21 = F_8 ( V_2 -> V_21 ,
V_2 -> V_38 ) ;
if ( V_2 -> V_19 < V_27 )
V_26 [ V_2 -> V_19 ++ ] = V_2 -> V_38 ;
else {
V_18 = - V_40 ;
V_2 -> V_19 = 0 ;
}
}
V_2 -> V_15 <<= 1 ;
V_2 -> V_31 -- ;
break;
case V_41 :
if ( V_2 -> V_15 == V_2 -> V_14 ) {
V_2 -> V_31 = 0 ;
break;
} else {
if ( V_2 -> V_15 == 0xff ) {
V_2 -> V_4 = V_33 ;
V_2 -> V_31 = 0 ;
} else if ( V_2 -> V_42 == 8 ) {
V_2 -> V_4 = V_37 ;
break;
} else
F_6 ( V_2 ) ;
}
break;
default:
break;
}
}
* V_25 -= V_24 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , const T_2 * V_23 , T_4 V_24 ,
int * V_25 , T_2 * V_26 , int V_27 )
{
static const unsigned char V_43 [] = {
0x7e , 0x3f , 0x9f , 0xcf , 0xe7 , 0xf3 , 0xf9 , 0xfc , 0x7e
} ;
int V_44 = 0 ;
* V_25 = V_24 ;
if ( ( V_24 == 1 ) && ( V_2 -> V_4 == V_13 ) )
V_2 -> V_4 = V_45 ;
while ( V_27 > 0 ) {
if ( V_2 -> V_31 == 0 ) {
if ( V_24 && ! V_2 -> V_46 ) {
V_2 -> V_38 = * V_23 ++ ;
V_24 -- ;
if ( V_24 == 0 )
V_2 -> V_46 = 1 ;
V_2 -> V_31 = 8 ;
} else {
if ( V_2 -> V_4 == V_47 ) {
if ( V_2 -> V_39 ) {
V_2 -> V_4 = V_48 ;
V_2 -> V_21 ^= 0xffff ;
V_2 -> V_31 = 8 ;
V_2 -> V_38 =
V_2 -> V_21 & 0xff ;
} else if ( ! V_2 -> V_7 )
V_2 -> V_4 =
V_13 ;
else
V_2 -> V_4 =
V_16 ;
}
}
}
switch ( V_2 -> V_4 ) {
case V_32 :
while ( V_27 -- )
* V_26 ++ = 0xff ;
return V_27 ;
case V_13 :
V_2 -> V_46 = 0 ;
if ( V_24 == 0 ) {
if ( V_2 -> V_9 == 0 )
* V_26 ++ = F_7 ( V_2 -> V_14 ) ;
else
* V_26 ++ = V_2 -> V_14 ;
V_44 ++ ;
V_27 -- ;
break;
}
case V_45 :
if ( V_2 -> V_31 == 8 ) {
V_2 -> V_15 = V_2 -> V_14 >>
( 8 - V_2 -> V_17 ) ;
V_2 -> V_4 = V_47 ;
V_2 -> V_21 = 0xffff ;
V_2 -> V_35 = 0 ;
V_2 -> V_39 = 1 ;
}
break;
case V_16 :
V_2 -> V_46 = 0 ;
V_2 -> V_15 <<= 1 ;
V_2 -> V_17 ++ ;
V_2 -> V_35 = 0 ;
V_2 -> V_4 = V_49 ;
break;
case V_49 :
V_2 -> V_15 <<= 1 ;
V_2 -> V_17 ++ ;
V_2 -> V_15 ++ ;
if ( ++ V_2 -> V_35 == 6 )
V_2 -> V_4 = V_50 ;
break;
case V_50 :
V_2 -> V_15 <<= 1 ;
V_2 -> V_17 ++ ;
if ( V_24 == 0 ) {
V_2 -> V_4 = V_16 ;
break;
}
if ( V_2 -> V_31 == 8 ) {
V_2 -> V_4 = V_47 ;
V_2 -> V_21 = 0xffff ;
V_2 -> V_35 = 0 ;
V_2 -> V_39 = 1 ;
}
break;
case V_12 :
V_2 -> V_39 = 1 ;
if ( V_2 -> V_17 == 8 ) {
V_2 -> V_4 = V_47 ;
V_2 -> V_21 = 0xffff ;
V_2 -> V_35 = 0 ;
break;
}
V_2 -> V_15 <<= 1 ;
V_2 -> V_17 ++ ;
if ( V_2 -> V_38 & 0x01 )
V_2 -> V_15 ++ ;
V_2 -> V_38 >>= 1 ;
V_2 -> V_31 -- ;
if ( V_2 -> V_31 == 0 ) {
V_2 -> V_4 = V_47 ;
V_2 -> V_21 = 0xffff ;
V_2 -> V_35 = 0 ;
}
break;
case V_47 :
V_2 -> V_15 <<= 1 ;
V_2 -> V_17 ++ ;
if ( V_2 -> V_35 == 5 ) {
V_2 -> V_35 = 0 ;
break;
}
if ( V_2 -> V_31 == 8 )
V_2 -> V_21 = F_8 ( V_2 -> V_21 ,
V_2 -> V_38 ) ;
if ( V_2 -> V_38 & 0x01 ) {
V_2 -> V_35 ++ ;
V_2 -> V_15 ++ ;
V_2 -> V_38 >>= 1 ;
V_2 -> V_31 -- ;
} else {
V_2 -> V_35 = 0 ;
V_2 -> V_38 >>= 1 ;
V_2 -> V_31 -- ;
}
break;
case V_48 :
V_2 -> V_15 <<= 1 ;
V_2 -> V_17 ++ ;
if ( V_2 -> V_35 == 5 ) {
V_2 -> V_35 = 0 ;
break;
}
if ( V_2 -> V_38 & 0x01 ) {
V_2 -> V_35 ++ ;
V_2 -> V_15 ++ ;
V_2 -> V_38 >>= 1 ;
V_2 -> V_31 -- ;
} else {
V_2 -> V_35 = 0 ;
V_2 -> V_38 >>= 1 ;
V_2 -> V_31 -- ;
}
if ( V_2 -> V_31 == 0 ) {
V_2 -> V_38 = ( V_2 -> V_21 >> 8 ) ;
V_2 -> V_4 = V_51 ;
V_2 -> V_31 = 8 ;
}
break;
case V_51 :
V_2 -> V_15 <<= 1 ;
V_2 -> V_17 ++ ;
if ( V_2 -> V_35 == 5 ) {
V_2 -> V_35 = 0 ;
break;
}
if ( V_2 -> V_38 & 0x01 ) {
V_2 -> V_35 ++ ;
V_2 -> V_15 ++ ;
V_2 -> V_38 >>= 1 ;
V_2 -> V_31 -- ;
} else {
V_2 -> V_35 = 0 ;
V_2 -> V_38 >>= 1 ;
V_2 -> V_31 -- ;
}
if ( V_2 -> V_31 == 0 ) {
V_2 -> V_38 = 0x7e ;
V_2 -> V_4 = V_52 ;
V_2 -> V_31 = 8 ;
}
break;
case V_52 :
V_2 -> V_15 <<= 1 ;
V_2 -> V_17 ++ ;
if ( V_2 -> V_35 == 5 ) {
V_2 -> V_35 = 0 ;
break;
}
if ( V_2 -> V_38 & 0x01 )
V_2 -> V_15 ++ ;
V_2 -> V_38 >>= 1 ;
V_2 -> V_31 -- ;
if ( V_2 -> V_31 == 0 ) {
V_2 -> V_14 =
V_43 [ V_2 -> V_17 ] ;
if ( V_2 -> V_11 ) {
V_2 -> V_14 = 0x7e ;
V_2 -> V_4 = V_53 ;
V_2 -> V_31 = 8 - V_2 -> V_17 ;
if ( V_2 -> V_31 == 0 )
V_2 -> V_4 =
V_54 ;
} else {
if ( ! V_2 -> V_7 ) {
V_2 -> V_4 =
V_13 ;
V_2 -> V_39 = 0 ;
} else {
V_2 -> V_4 = V_16 ;
V_2 -> V_39 = 0 ;
}
if ( V_27 > 1 )
V_27 = 1 ;
}
}
break;
case V_53 :
V_2 -> V_46 = 0 ;
V_2 -> V_15 <<= 1 ;
V_2 -> V_15 ++ ;
V_2 -> V_17 ++ ;
V_2 -> V_31 -- ;
if ( V_2 -> V_31 == 0 ) {
V_2 -> V_4 = V_54 ;
V_2 -> V_31 = 0 ;
}
break;
case V_54 :
V_2 -> V_46 = 0 ;
V_2 -> V_15 = 0xff ;
V_2 -> V_17 = 8 ;
if ( V_2 -> V_31 == 8 ) {
V_2 -> V_15 = 0x7e ;
V_2 -> V_4 = V_12 ;
} else {
if ( V_2 -> V_9 == 0 )
* V_26 ++ = F_7 ( V_2 -> V_15 ) ;
else
* V_26 ++ = V_2 -> V_15 ;
V_2 -> V_31 = 0 ;
V_2 -> V_17 = 0 ;
V_44 ++ ;
V_27 = 0 ;
}
break;
default:
break;
}
if ( V_2 -> V_7 ) {
if ( V_2 -> V_17 == 7 ) {
V_2 -> V_15 <<= 1 ;
V_2 -> V_15 ++ ;
V_2 -> V_17 ++ ;
}
}
if ( V_2 -> V_17 == 8 ) {
if ( V_2 -> V_9 == 0 )
* V_26 ++ = F_7 ( V_2 -> V_15 ) ;
else
* V_26 ++ = V_2 -> V_15 ;
V_2 -> V_17 = 0 ;
V_44 ++ ;
V_27 -- ;
}
}
* V_25 -= V_24 ;
return V_44 ;
}
