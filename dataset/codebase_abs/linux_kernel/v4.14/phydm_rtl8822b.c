static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= 40 )
F_2 ( V_2 , 0x8d8 , F_3 ( 17 ) , 0x1 ) ;
else if ( V_2 -> V_3 < 35 )
F_2 ( V_2 , 0x8d8 , F_3 ( 17 ) , 0x0 ) ;
F_4 ( V_2 , V_4 , L_1 , V_5 ,
V_2 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_7 , T_1 V_8 )
{
T_2 V_9 = 0 ;
T_1 V_10 = 0 ;
bool V_11 = false ;
T_1 V_12 = 0 ;
switch ( V_7 ) {
case 0x0 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X10124 ) ;
break;
case 0x1 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X10524 ) ;
break;
case 0x2 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X10924 ) ;
break;
case 0x3 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X10D24 ) ;
break;
case 0x4 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X30164 ) ;
break;
case 0x5 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X30564 ) ;
break;
case 0x6 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X30964 ) ;
break;
case 0x7 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X30D64 ) ;
break;
case 0x8 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X50195 ) ;
break;
case 0x9 :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X50595 ) ;
break;
case 0xa :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X50995 ) ;
break;
case 0xb :
F_6 ( V_2 , V_6 , 0x18 , 0xFFFFF , 0X50D95 ) ;
break;
default:
F_4 ( V_2 , V_4 ,
L_2 ) ;
return;
}
V_9 = F_7 ( V_2 , V_6 , 0x61 , 0xFFFFF ) ;
V_10 = ( T_1 ) V_9 & ( F_3 ( 3 ) | F_3 ( 2 ) | F_3 ( 1 ) | F_3 ( 0 ) ) ;
switch ( V_8 ) {
case 0xF6 :
V_11 = true ;
V_12 = 3 ;
break;
case 0xF4 :
V_11 = true ;
V_12 = 2 ;
break;
case 0xF2 :
V_11 = true ;
V_12 = 1 ;
break;
case 0xF3 :
V_11 = false ;
V_12 = 1 ;
break;
case 0xF5 :
V_11 = false ;
V_12 = 2 ;
break;
case 0xF7 :
V_11 = false ;
V_12 = 3 ;
break;
case 0xF9 :
V_11 = false ;
V_12 = 4 ;
break;
case 0xF0 :
default:
F_4 ( V_2 , V_4 ,
L_3 ) ;
return;
}
if ( V_11 ) {
if ( V_10 >= V_12 ) {
V_10 -= V_12 ;
} else {
V_10 = 0 ;
}
} else {
V_10 += V_12 ;
if ( V_10 >= 7 )
V_10 = 7 ;
}
F_6 ( V_2 , V_6 , 0x30 , 0xFFFF ,
( V_7 << 12 | ( V_9 & 0xFF0 ) | V_10 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_6 ,
T_1 V_13 )
{
F_6 ( V_2 , V_6 , 0xEF , 0xFFFFF , 0x200 ) ;
F_5 ( V_2 , V_6 , 0x0 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x1 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x2 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x3 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x4 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x5 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x6 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x7 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x8 , V_13 ) ;
F_5 ( V_2 , V_6 , 0x9 , V_13 ) ;
F_5 ( V_2 , V_6 , 0xa , V_13 ) ;
F_5 ( V_2 , V_6 , 0xb , V_13 ) ;
F_6 ( V_2 , V_6 , 0xEF , 0xFFFFF , 0x0 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
T_1 V_14 , V_15 ;
T_2 V_16 = 0 , V_17 = 0 ;
V_16 = F_7 ( V_2 , V_18 , 0x18 , 0xFFFFF ) ;
V_17 = F_7 ( V_2 , V_19 , 0x18 , 0xFFFFF ) ;
V_14 = V_2 -> V_20 ;
V_15 = V_2 -> V_21 ;
if ( V_15 == 0xFF ) {
F_4 (
V_2 , V_4 ,
L_4 ) ;
return;
}
F_8 ( V_2 , V_18 , V_15 ) ;
F_8 ( V_2 , V_19 , V_14 ) ;
F_6 ( V_2 , V_18 , 0x18 , 0xFFFFF , V_16 ) ;
F_6 ( V_2 , V_19 , 0x18 , 0xFFFFF , V_17 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
