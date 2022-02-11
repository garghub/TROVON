void F_1 ( unsigned char * V_1 , unsigned char * V_2 , long V_3 ,
T_1 * V_4 , unsigned char * V_5 , int V_6 )
{
register unsigned long V_7 , V_8 ;
register unsigned long V_9 , V_10 , V_11 , V_12 ;
register long V_13 = V_3 ;
unsigned long V_14 [ 2 ] ;
if ( V_6 )
{
F_2 ( V_5 , V_9 ) ;
F_2 ( V_5 , V_10 ) ;
V_5 -= 8 ;
for ( V_13 -= 8 ; V_13 >= 0 ; V_13 -= 8 )
{
F_2 ( V_1 , V_7 ) ;
F_2 ( V_1 , V_8 ) ;
V_7 ^= V_9 ;
V_8 ^= V_10 ;
V_14 [ 0 ] = V_7 ;
V_14 [ 1 ] = V_8 ;
F_3 ( V_14 , V_4 ) ;
V_9 = V_14 [ 0 ] ; F_4 ( V_9 , V_2 ) ;
V_10 = V_14 [ 1 ] ; F_4 ( V_10 , V_2 ) ;
}
if ( V_13 != - 8 )
{
F_5 ( V_1 , V_7 , V_8 , V_13 + 8 ) ;
V_7 ^= V_9 ;
V_8 ^= V_10 ;
V_14 [ 0 ] = V_7 ;
V_14 [ 1 ] = V_8 ;
F_3 ( V_14 , V_4 ) ;
V_9 = V_14 [ 0 ] ; F_4 ( V_9 , V_2 ) ;
V_10 = V_14 [ 1 ] ; F_4 ( V_10 , V_2 ) ;
}
F_4 ( V_9 , V_5 ) ;
F_4 ( V_10 , V_5 ) ;
}
else
{
F_2 ( V_5 , V_11 ) ;
F_2 ( V_5 , V_12 ) ;
V_5 -= 8 ;
for ( V_13 -= 8 ; V_13 >= 0 ; V_13 -= 8 )
{
F_2 ( V_1 , V_7 ) ; V_14 [ 0 ] = V_7 ;
F_2 ( V_1 , V_8 ) ; V_14 [ 1 ] = V_8 ;
F_6 ( V_14 , V_4 ) ;
V_9 = V_14 [ 0 ] ^ V_11 ;
V_10 = V_14 [ 1 ] ^ V_12 ;
F_4 ( V_9 , V_2 ) ;
F_4 ( V_10 , V_2 ) ;
V_11 = V_7 ;
V_12 = V_8 ;
}
if ( V_13 != - 8 )
{
F_2 ( V_1 , V_7 ) ; V_14 [ 0 ] = V_7 ;
F_2 ( V_1 , V_8 ) ; V_14 [ 1 ] = V_8 ;
F_6 ( V_14 , V_4 ) ;
V_9 = V_14 [ 0 ] ^ V_11 ;
V_10 = V_14 [ 1 ] ^ V_12 ;
F_7 ( V_9 , V_10 , V_2 , V_13 + 8 ) ;
V_11 = V_7 ;
V_12 = V_8 ;
}
F_4 ( V_11 , V_5 ) ;
F_4 ( V_12 , V_5 ) ;
}
V_7 = V_8 = V_9 = V_10 = V_11 = V_12 = 0 ;
V_14 [ 0 ] = V_14 [ 1 ] = 0 ;
}
void F_3 ( unsigned long * V_15 , T_1 * V_16 )
{
int V_17 , V_18 ;
register T_2 * V_19 , * V_20 ;
register T_2 V_21 , V_22 , V_23 , V_24 , V_25 ;
unsigned long V_13 ;
V_13 = V_15 [ 0 ] ;
V_21 = ( T_2 ) V_13 & 0xffff ;
V_22 = ( T_2 ) ( V_13 >> 16L ) ;
V_13 = V_15 [ 1 ] ;
V_23 = ( T_2 ) V_13 & 0xffff ;
V_24 = ( T_2 ) ( V_13 >> 16L ) ;
V_18 = 3 ;
V_17 = 5 ;
V_19 = V_20 = & ( V_16 -> V_26 [ 0 ] ) ;
for (; ; )
{
V_25 = ( V_21 + ( V_22 & ~ V_24 ) + ( V_23 & V_24 ) + * ( V_19 ++ ) ) & 0xffff ;
V_21 = ( V_25 << 1 ) | ( V_25 >> 15 ) ;
V_25 = ( V_22 + ( V_23 & ~ V_21 ) + ( V_24 & V_21 ) + * ( V_19 ++ ) ) & 0xffff ;
V_22 = ( V_25 << 2 ) | ( V_25 >> 14 ) ;
V_25 = ( V_23 + ( V_24 & ~ V_22 ) + ( V_21 & V_22 ) + * ( V_19 ++ ) ) & 0xffff ;
V_23 = ( V_25 << 3 ) | ( V_25 >> 13 ) ;
V_25 = ( V_24 + ( V_21 & ~ V_23 ) + ( V_22 & V_23 ) + * ( V_19 ++ ) ) & 0xffff ;
V_24 = ( V_25 << 5 ) | ( V_25 >> 11 ) ;
if ( -- V_17 == 0 )
{
if ( -- V_18 == 0 ) break;
V_17 = ( V_18 == 2 ) ? 6 : 5 ;
V_21 += V_20 [ V_24 & 0x3f ] ;
V_22 += V_20 [ V_21 & 0x3f ] ;
V_23 += V_20 [ V_22 & 0x3f ] ;
V_24 += V_20 [ V_23 & 0x3f ] ;
}
}
V_15 [ 0 ] = ( unsigned long ) ( V_21 & 0xffff ) | ( ( unsigned long ) ( V_22 & 0xffff ) << 16L ) ;
V_15 [ 1 ] = ( unsigned long ) ( V_23 & 0xffff ) | ( ( unsigned long ) ( V_24 & 0xffff ) << 16L ) ;
}
void F_6 ( unsigned long * V_15 , T_1 * V_16 )
{
int V_17 , V_18 ;
register T_2 * V_19 , * V_20 ;
register T_2 V_21 , V_22 , V_23 , V_24 , V_25 ;
unsigned long V_13 ;
V_13 = V_15 [ 0 ] ;
V_21 = ( T_2 ) V_13 & 0xffff ;
V_22 = ( T_2 ) ( V_13 >> 16L ) ;
V_13 = V_15 [ 1 ] ;
V_23 = ( T_2 ) V_13 & 0xffff ;
V_24 = ( T_2 ) ( V_13 >> 16L ) ;
V_18 = 3 ;
V_17 = 5 ;
V_19 = & ( V_16 -> V_26 [ 63 ] ) ;
V_20 = & ( V_16 -> V_26 [ 0 ] ) ;
for (; ; )
{
V_25 = ( ( V_24 << 11 ) | ( V_24 >> 5 ) ) & 0xffff ;
V_24 = ( V_25 - ( V_21 & ~ V_23 ) - ( V_22 & V_23 ) - * ( V_19 -- ) ) & 0xffff ;
V_25 = ( ( V_23 << 13 ) | ( V_23 >> 3 ) ) & 0xffff ;
V_23 = ( V_25 - ( V_24 & ~ V_22 ) - ( V_21 & V_22 ) - * ( V_19 -- ) ) & 0xffff ;
V_25 = ( ( V_22 << 14 ) | ( V_22 >> 2 ) ) & 0xffff ;
V_22 = ( V_25 - ( V_23 & ~ V_21 ) - ( V_24 & V_21 ) - * ( V_19 -- ) ) & 0xffff ;
V_25 = ( ( V_21 << 15 ) | ( V_21 >> 1 ) ) & 0xffff ;
V_21 = ( V_25 - ( V_22 & ~ V_24 ) - ( V_23 & V_24 ) - * ( V_19 -- ) ) & 0xffff ;
if ( -- V_17 == 0 )
{
if ( -- V_18 == 0 ) break;
V_17 = ( V_18 == 2 ) ? 6 : 5 ;
V_24 = ( V_24 - V_20 [ V_23 & 0x3f ] ) & 0xffff ;
V_23 = ( V_23 - V_20 [ V_22 & 0x3f ] ) & 0xffff ;
V_22 = ( V_22 - V_20 [ V_21 & 0x3f ] ) & 0xffff ;
V_21 = ( V_21 - V_20 [ V_24 & 0x3f ] ) & 0xffff ;
}
}
V_15 [ 0 ] = ( unsigned long ) ( V_21 & 0xffff ) | ( ( unsigned long ) ( V_22 & 0xffff ) << 16L ) ;
V_15 [ 1 ] = ( unsigned long ) ( V_23 & 0xffff ) | ( ( unsigned long ) ( V_24 & 0xffff ) << 16L ) ;
}
