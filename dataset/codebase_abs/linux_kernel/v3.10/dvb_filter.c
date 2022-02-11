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
F_2 ( L_1 ) ;
V_4 -> V_12 = V_8 ;
if ( V_8 + 5 >= V_2 ) return - 1 ;
V_4 -> V_13 = 0 ;
V_6 = V_1 + V_8 + 2 ;
V_9 = ( V_6 [ 2 ] & 0x3f ) ;
V_4 -> V_14 = V_15 [ V_9 >> 1 ] * 1000 ;
if ( V_5 )
F_2 ( L_2 , ( int ) V_4 -> V_14 / 1000 ) ;
V_4 -> V_16 = ( V_6 [ 2 ] & 0xc0 ) >> 6 ;
V_10 = ( V_6 [ 2 ] & 0xc0 ) >> 6 ;
V_4 -> V_16 = V_17 [ V_10 ] * 100 ;
if ( V_5 ) F_2 ( L_3 , ( int ) V_4 -> V_16 ) ;
V_4 -> V_18 = V_19 [ V_10 ] [ V_9 >> 1 ] ;
if ( ( V_9 & 1 ) && ( V_10 == 1 ) ) V_4 -> V_18 ++ ;
V_4 -> V_18 = V_4 -> V_18 << 1 ;
if ( V_5 ) F_2 ( L_4 , ( int ) V_4 -> V_18 ) ;
return 0 ;
}
void F_3 ( struct V_20 * V_21 , unsigned short V_22 ,
T_2 * V_23 , void * V_24 )
{
unsigned char * V_25 = V_21 -> V_25 ;
V_25 [ 0 ] = 0x47 ;
V_25 [ 1 ] = ( V_22 >> 8 ) ;
V_25 [ 2 ] = V_22 & 0xff ;
V_21 -> V_26 = 0 ;
V_21 -> V_23 = V_23 ;
V_21 -> V_24 = V_24 ;
}
int V_20 ( struct V_20 * V_21 , unsigned char * V_27 ,
int V_28 , int V_29 )
{
unsigned char * V_25 = V_21 -> V_25 ;
int V_30 = 0 , V_31 ;
if ( V_29 )
V_25 [ 1 ] |= 0x40 ;
else
V_25 [ 1 ] &= ~ 0x40 ;
while ( V_28 >= 184 ) {
V_25 [ 3 ] = 0x10 | ( ( V_21 -> V_26 ++ ) & 0x0f ) ;
memcpy ( V_25 + 4 , V_27 , 184 ) ;
if ( ( V_30 = V_21 -> V_23 ( V_21 -> V_24 , V_25 ) ) )
return V_30 ;
V_28 -= 184 ; V_27 += 184 ;
V_25 [ 1 ] &= ~ 0x40 ;
}
if ( ! V_28 )
return 0 ;
V_25 [ 3 ] = 0x30 | ( ( V_21 -> V_26 ++ ) & 0x0f ) ;
V_31 = 183 - V_28 ;
if ( V_31 ) {
V_25 [ 5 ] = 0x00 ;
if ( V_31 - 1 )
memset ( V_25 + 6 , 0xff , V_31 - 1 ) ;
}
V_25 [ 4 ] = V_31 ;
memcpy ( V_25 + 5 + V_31 , V_27 , V_28 ) ;
return V_21 -> V_23 ( V_21 -> V_24 , V_25 ) ;
}
