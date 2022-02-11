T_1 F_1 ( T_1 V_1 )
{
int V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ;
unsigned int V_8 ;
V_9 ;
V_10 ;
V_11 ;
V_12 ;
switch ( V_13 ) {
case V_14 :
return F_2 ( V_1 , L_1 ) ;
case V_15 :
F_3 ( V_16 ) ;
return F_2 ( F_4 () , L_1 ) ;
case V_17 :
return V_1 ;
case V_18 :
if ( V_19 ) {
F_3 ( V_16 ) ;
return F_2 ( F_4 () , L_1 ) ;
}
return V_1 ;
case V_20 :
case V_21 :
if ( V_19 ) {
F_3 ( V_16 ) ;
return F_2 ( F_4 () , L_1 ) ;
}
break;
}
V_2 = V_1 . V_22 ;
V_5 = ( V_2 >> 23 ) ;
if ( V_5 == 0 ) {
for ( V_7 = 0 ; ( V_2 & 0x00800000 ) == 0 ; V_7 ++ )
V_2 <<= 1 ;
V_5 -= V_7 - 1 ;
}
V_5 -= 127 ;
V_2 = ( V_2 & 0x007fffff ) | 0x00800000 ;
if ( V_5 & 1 )
V_2 += V_2 ;
V_5 >>= 1 ;
V_2 += V_2 ;
V_4 = V_3 = 0 ;
V_8 = 0x01000000 ;
while ( V_8 != 0 ) {
V_6 = V_3 + V_8 ;
if ( V_6 <= V_2 ) {
V_3 = V_6 + V_8 ;
V_2 -= V_6 ;
V_4 += V_8 ;
}
V_2 += V_2 ;
V_8 >>= 1 ;
}
if ( V_2 != 0 ) {
F_3 ( V_23 ) ;
switch ( V_24 . V_25 ) {
case V_26 :
V_4 += 2 ;
break;
case V_27 :
V_4 += ( V_4 & 1 ) ;
break;
}
}
V_2 = ( V_4 >> 1 ) + 0x3f000000 ;
V_2 += ( V_5 << 23 ) ;
V_1 . V_22 = V_2 ;
return V_1 ;
}
