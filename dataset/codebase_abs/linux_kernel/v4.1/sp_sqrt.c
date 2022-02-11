union V_1 F_1 ( union V_1 V_2 )
{
int V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ;
unsigned int V_9 ;
V_10 ;
V_11 ;
F_2 () ;
V_12 ;
switch ( V_13 ) {
case V_14 :
return F_3 ( V_2 ) ;
case V_15 :
return V_2 ;
case V_16 :
return V_2 ;
case V_17 :
if ( V_18 ) {
F_4 ( V_19 ) ;
return F_5 () ;
}
return V_2 ;
case V_20 :
case V_21 :
if ( V_18 ) {
F_4 ( V_19 ) ;
return F_5 () ;
}
break;
}
V_3 = V_2 . V_22 ;
V_6 = ( V_3 >> 23 ) ;
if ( V_6 == 0 ) {
for ( V_8 = 0 ; ( V_3 & 0x00800000 ) == 0 ; V_8 ++ )
V_3 <<= 1 ;
V_6 -= V_8 - 1 ;
}
V_6 -= 127 ;
V_3 = ( V_3 & 0x007fffff ) | 0x00800000 ;
if ( V_6 & 1 )
V_3 += V_3 ;
V_6 >>= 1 ;
V_3 += V_3 ;
V_5 = V_4 = 0 ;
V_9 = 0x01000000 ;
while ( V_9 != 0 ) {
V_7 = V_4 + V_9 ;
if ( V_7 <= V_3 ) {
V_4 = V_7 + V_9 ;
V_3 -= V_7 ;
V_5 += V_9 ;
}
V_3 += V_3 ;
V_9 >>= 1 ;
}
if ( V_3 != 0 ) {
F_4 ( V_23 ) ;
switch ( V_24 . V_25 ) {
case V_26 :
V_5 += 2 ;
break;
case V_27 :
V_5 += ( V_5 & 1 ) ;
break;
}
}
V_3 = ( V_5 >> 1 ) + 0x3f000000 ;
V_3 += ( V_6 << 23 ) ;
V_2 . V_22 = V_3 ;
return V_2 ;
}
