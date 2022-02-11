int
F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 )
{
unsigned short V_5 = V_3 ;
unsigned short V_6 = 0 , V_7 = 0 ;
unsigned short V_8 = 0 ;
int Clock ;
if( ! F_2 ( V_2 ) ) return 65000 ;
if( V_4 > 0 ) V_4 -- ;
#ifdef F_3
switch( V_5 ) {
case 0x5a : V_5 = 0x50 ; break;
case 0x5b : V_5 = 0x56 ;
}
#endif
if( ! ( F_4 ( V_2 , & V_5 , & V_6 ) ) ) { ;
F_5 ( V_9 L_1 , V_5 ) ;
return 65000 ;
}
V_8 = V_2 -> V_10 [ V_6 ] . V_11 ;
if( V_2 -> V_12 [ V_8 ] . V_13 & V_14 ) {
if( V_2 -> V_15 == 1 ) {
V_7 = V_2 -> V_12 [ V_8 ] . V_16 ;
} else {
V_8 += V_4 ;
V_7 = V_2 -> V_12 [ V_8 ] . V_17 ;
}
} else {
V_8 += V_4 ;
V_7 = V_2 -> V_12 [ V_8 ] . V_18 ;
}
Clock = V_2 -> V_19 [ V_7 ] . CLOCK * 1000 ;
return Clock ;
}
int
F_6 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_4 , struct V_20 * V_21 )
{
unsigned short V_5 = V_3 ;
unsigned short V_6 = 0 , V_22 = 0 , V_8 = 0 ;
int V_23 ;
if( ! F_2 ( V_2 ) ) return 0 ;
if( V_4 > 0 ) V_4 -- ;
#ifdef F_3
switch( V_5 ) {
case 0x5a : V_5 = 0x50 ; break;
case 0x5b : V_5 = 0x56 ;
}
#endif
if( ! ( F_4 ( V_2 , & V_5 , & V_6 ) ) ) return 0 ;
V_8 = V_2 -> V_10 [ V_6 ] . V_11 ;
if( V_2 -> V_12 [ V_8 ] . V_13 & V_14 ) {
if( V_2 -> V_15 == 1 ) {
V_22 = V_2 -> V_12 [ V_8 ] . V_24 ;
} else {
V_8 += V_4 ;
V_22 = V_2 -> V_12 [ V_8 ] . V_25 ;
}
} else {
V_8 += V_4 ;
V_22 = V_2 -> V_12 [ V_8 ] . V_26 ;
}
F_7 ( V_2 ,
( unsigned char * ) & V_2 -> V_27 [ V_22 ] . V_28 [ 0 ] ,
V_2 -> V_12 [ V_8 ] . V_29 ,
V_2 -> V_12 [ V_8 ] . V_30 ,
V_21 , false ) ;
if( V_2 -> V_12 [ V_8 ] . V_13 & 0x8000 )
V_21 -> V_31 &= ~ V_32 ;
else
V_21 -> V_31 |= V_32 ;
if( V_2 -> V_12 [ V_8 ] . V_13 & 0x4000 )
V_21 -> V_31 &= ~ V_33 ;
else
V_21 -> V_31 |= V_33 ;
V_21 -> V_34 = V_35 ;
if( V_2 -> V_12 [ V_8 ] . V_13 & 0x0080 )
V_21 -> V_34 = V_36 ;
else {
V_23 = 0 ;
while( V_2 -> V_10 [ V_23 ] . V_37 != 0xff ) {
if( V_2 -> V_10 [ V_23 ] . V_37 ==
V_2 -> V_12 [ V_8 ] . V_38 ) {
if( V_2 -> V_10 [ V_23 ] . V_39 & V_40 ) {
V_21 -> V_34 = V_41 ;
}
break;
}
V_23 ++ ;
}
}
if( ( V_21 -> V_34 & V_42 ) == V_36 ) {
#if 0
var->upper_margin <<= 1;
var->lower_margin <<= 1;
var->vsync_len <<= 1;
#endif
} else if( ( V_21 -> V_34 & V_42 ) == V_41 ) {
V_21 -> V_43 >>= 1 ;
V_21 -> V_44 >>= 1 ;
V_21 -> V_45 >>= 1 ;
}
return 1 ;
}
bool
F_8 ( struct V_1 * V_2 , unsigned char V_3 , int * V_46 ,
int * V_47 , unsigned char V_4 )
{
unsigned short V_5 = V_3 ;
unsigned short V_6 = 0 , V_48 = 0 ;
unsigned short V_8 = 0 ;
unsigned char V_49 , V_50 , V_51 ;
if( ! F_2 ( V_2 ) ) return false ;
if( V_4 > 0 ) V_4 -- ;
#ifdef F_3
switch( V_5 ) {
case 0x5a : V_5 = 0x50 ; break;
case 0x5b : V_5 = 0x56 ;
}
#endif
if( ! ( F_4 ( V_2 , & V_5 , & V_6 ) ) ) return false ;
V_8 = V_2 -> V_10 [ V_6 ] . V_11 ;
if( V_2 -> V_12 [ V_8 ] . V_13 & V_14 ) {
if( V_2 -> V_15 == 1 ) {
V_48 = V_2 -> V_12 [ V_8 ] . V_24 ;
} else {
V_8 += V_4 ;
V_48 = V_2 -> V_12 [ V_8 ] . V_25 ;
}
} else {
V_8 += V_4 ;
V_48 = V_2 -> V_12 [ V_8 ] . V_26 ;
}
V_49 = V_2 -> V_27 [ V_48 ] . V_28 [ 14 ] ;
V_50 = V_2 -> V_27 [ V_48 ] . V_28 [ 0 ] ;
* V_46 = ( ( ( V_50 & 0xff ) | ( ( unsigned short ) ( V_49 & 0x03 ) << 8 ) ) + 5 ) * 8 ;
V_49 = V_2 -> V_27 [ V_48 ] . V_28 [ 13 ] ;
V_50 = V_2 -> V_27 [ V_48 ] . V_28 [ 6 ] ;
V_51 = V_2 -> V_27 [ V_48 ] . V_28 [ 7 ] ;
* V_47 = ( ( V_50 & 0xFF ) |
( ( unsigned short ) ( V_51 & 0x01 ) << 8 ) |
( ( unsigned short ) ( V_51 & 0x20 ) << 4 ) |
( ( unsigned short ) ( V_49 & 0x01 ) << 10 ) ) + 2 ;
if( V_2 -> V_12 [ V_8 ] . V_13 & V_52 )
* V_47 *= 2 ;
return true ;
}
