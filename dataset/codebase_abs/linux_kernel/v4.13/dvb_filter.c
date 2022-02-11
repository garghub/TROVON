int F_1 ( T_1 * V_1 , int V_2 , struct V_3 * V_4 , int V_5 )
{
T_1 * V_6 ;
int V_7 = 0 ;
int V_8 = 0 ;
T_1 V_9 = 0 ;
int V_10 = 0 ;
while ( ! V_7 && V_8 < V_2 ) {
T_1 * V_11 = V_1 + V_8 ;
if ( V_11 [ 0 ] == 0x0b && V_11 [ 1 ] == 0x77 )
V_7 = 1 ;
else {
V_8 ++ ;
}
}
if ( ! V_7 ) return - 1 ;
if ( V_5 )
F_2 ( V_12 L_1 ) ;
V_4 -> V_13 = V_8 ;
if ( V_8 + 5 >= V_2 ) return - 1 ;
V_4 -> V_14 = 0 ;
V_6 = V_1 + V_8 + 2 ;
V_9 = ( V_6 [ 2 ] & 0x3f ) ;
V_4 -> V_15 = V_16 [ V_9 >> 1 ] * 1000 ;
if ( V_5 )
F_2 ( V_17 L_2 , ( int ) V_4 -> V_15 / 1000 ) ;
V_4 -> V_18 = ( V_6 [ 2 ] & 0xc0 ) >> 6 ;
V_10 = ( V_6 [ 2 ] & 0xc0 ) >> 6 ;
V_4 -> V_18 = V_19 [ V_10 ] * 100 ;
if ( V_5 )
F_2 ( V_17 L_3 , ( int ) V_4 -> V_18 ) ;
V_4 -> V_20 = V_21 [ V_10 ] [ V_9 >> 1 ] ;
if ( ( V_9 & 1 ) && ( V_10 == 1 ) ) V_4 -> V_20 ++ ;
V_4 -> V_20 = V_4 -> V_20 << 1 ;
if ( V_5 )
F_2 ( V_12 L_4 , ( int ) V_4 -> V_20 ) ;
return 0 ;
}
void F_3 ( struct V_22 * V_23 , unsigned short V_24 ,
T_2 * V_25 , void * V_26 )
{
unsigned char * V_27 = V_23 -> V_27 ;
V_27 [ 0 ] = 0x47 ;
V_27 [ 1 ] = ( V_24 >> 8 ) ;
V_27 [ 2 ] = V_24 & 0xff ;
V_23 -> V_28 = 0 ;
V_23 -> V_25 = V_25 ;
V_23 -> V_26 = V_26 ;
}
int V_22 ( struct V_22 * V_23 , unsigned char * V_29 ,
int V_30 , int V_31 )
{
unsigned char * V_27 = V_23 -> V_27 ;
int V_32 = 0 , V_33 ;
if ( V_31 )
V_27 [ 1 ] |= 0x40 ;
else
V_27 [ 1 ] &= ~ 0x40 ;
while ( V_30 >= 184 ) {
V_27 [ 3 ] = 0x10 | ( ( V_23 -> V_28 ++ ) & 0x0f ) ;
memcpy ( V_27 + 4 , V_29 , 184 ) ;
if ( ( V_32 = V_23 -> V_25 ( V_23 -> V_26 , V_27 ) ) )
return V_32 ;
V_30 -= 184 ; V_29 += 184 ;
V_27 [ 1 ] &= ~ 0x40 ;
}
if ( ! V_30 )
return 0 ;
V_27 [ 3 ] = 0x30 | ( ( V_23 -> V_28 ++ ) & 0x0f ) ;
V_33 = 183 - V_30 ;
if ( V_33 ) {
V_27 [ 5 ] = 0x00 ;
if ( V_33 - 1 )
memset ( V_27 + 6 , 0xff , V_33 - 1 ) ;
}
V_27 [ 4 ] = V_33 ;
memcpy ( V_27 + 5 + V_33 , V_29 , V_30 ) ;
return V_23 -> V_25 ( V_23 -> V_26 , V_27 ) ;
}
