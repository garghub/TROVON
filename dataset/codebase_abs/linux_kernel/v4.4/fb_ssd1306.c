static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 ( V_2 ) ;
if ( V_2 -> gamma . V_5 [ 0 ] == 0 ) {
F_2 ( & V_2 -> gamma . V_6 ) ;
if ( V_2 -> V_7 -> V_8 . V_9 == 64 )
V_2 -> gamma . V_5 [ 0 ] = 0xCF ;
else
V_2 -> gamma . V_5 [ 0 ] = 0x8F ;
F_3 ( & V_2 -> gamma . V_6 ) ;
}
F_4 ( V_2 , 0xAE ) ;
F_4 ( V_2 , 0xD5 ) ;
F_4 ( V_2 , 0x80 ) ;
F_4 ( V_2 , 0xA8 ) ;
if ( V_2 -> V_7 -> V_8 . V_9 == 64 )
F_4 ( V_2 , 0x3F ) ;
else
F_4 ( V_2 , 0x1F ) ;
F_4 ( V_2 , 0xD3 ) ;
F_4 ( V_2 , 0x0 ) ;
F_4 ( V_2 , 0x40 | 0x0 ) ;
F_4 ( V_2 , 0x8D ) ;
F_4 ( V_2 , 0x14 ) ;
F_4 ( V_2 , 0x20 ) ;
F_4 ( V_2 , 0x01 ) ;
F_4 ( V_2 , 0xA0 | 0x1 ) ;
F_4 ( V_2 , 0xC8 ) ;
F_4 ( V_2 , 0xDA ) ;
if ( V_2 -> V_7 -> V_8 . V_9 == 64 )
F_4 ( V_2 , 0x12 ) ;
else
F_4 ( V_2 , 0x02 ) ;
F_4 ( V_2 , 0xD9 ) ;
F_4 ( V_2 , 0xF1 ) ;
F_4 ( V_2 , 0xDB ) ;
F_4 ( V_2 , 0x40 ) ;
F_4 ( V_2 , 0xA4 ) ;
F_4 ( V_2 , 0xA6 ) ;
F_4 ( V_2 , 0xAF ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , int V_10 , int V_11 , int V_12 , int V_13 )
{
F_4 ( V_2 , 0x00 | 0x0 ) ;
F_4 ( V_2 , 0x10 | 0x0 ) ;
F_4 ( V_2 , 0x40 | 0x0 ) ;
}
static int F_6 ( struct V_1 * V_2 , bool V_14 )
{
F_7 ( V_15 , V_2 , L_1 ,
V_16 , V_14 ? L_2 : L_3 ) ;
if ( V_14 )
F_4 ( V_2 , 0xAE ) ;
else
F_4 ( V_2 , 0xAF ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long * V_5 )
{
V_5 [ 0 ] &= 0xFF ;
F_4 ( V_2 , 0x81 ) ;
F_4 ( V_2 , V_5 [ 0 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_17 , T_1 V_18 )
{
T_2 * V_19 = ( T_2 * ) V_2 -> V_7 -> V_20 ;
T_3 * V_21 = V_2 -> V_22 . V_21 ;
int V_23 , V_24 , V_25 ;
int V_26 = 0 ;
for ( V_23 = 0 ; V_23 < V_2 -> V_7 -> V_8 . V_27 ; V_23 ++ ) {
for ( V_24 = 0 ; V_24 < V_2 -> V_7 -> V_8 . V_9 / 8 ; V_24 ++ ) {
* V_21 = 0x00 ;
for ( V_25 = 0 ; V_25 < 8 ; V_25 ++ )
* V_21 |= ( V_19 [ ( V_24 * 8 + V_25 ) *
V_2 -> V_7 -> V_8 . V_27 + V_23 ] ?
1 : 0 ) << V_25 ;
V_21 ++ ;
}
}
F_10 ( V_2 -> V_28 . V_29 , 1 ) ;
V_26 = V_2 -> V_3 . V_30 ( V_2 , V_2 -> V_22 . V_21 ,
V_2 -> V_7 -> V_8 . V_27 * V_2 -> V_7 -> V_8 . V_9 /
8 ) ;
if ( V_26 < 0 )
F_11 ( V_2 -> V_7 -> V_31 , L_4 ,
V_26 ) ;
return V_26 ;
}
