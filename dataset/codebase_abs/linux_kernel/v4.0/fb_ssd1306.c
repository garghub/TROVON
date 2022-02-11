static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
V_2 -> V_5 . V_6 ( V_2 ) ;
if ( V_2 -> gamma . V_7 [ 0 ] == 0 ) {
F_3 ( & V_2 -> gamma . V_8 ) ;
if ( V_2 -> V_9 -> V_10 . V_11 == 64 )
V_2 -> gamma . V_7 [ 0 ] = 0xCF ;
else
V_2 -> gamma . V_7 [ 0 ] = 0x8F ;
F_4 ( & V_2 -> gamma . V_8 ) ;
}
F_5 ( V_2 , 0xAE ) ;
F_5 ( V_2 , 0xD5 ) ;
F_5 ( V_2 , 0x80 ) ;
F_5 ( V_2 , 0xA8 ) ;
if ( V_2 -> V_9 -> V_10 . V_11 == 64 )
F_5 ( V_2 , 0x3F ) ;
else
F_5 ( V_2 , 0x1F ) ;
F_5 ( V_2 , 0xD3 ) ;
F_5 ( V_2 , 0x0 ) ;
F_5 ( V_2 , 0x40 | 0x0 ) ;
F_5 ( V_2 , 0x8D ) ;
F_5 ( V_2 , 0x14 ) ;
F_5 ( V_2 , 0x20 ) ;
F_5 ( V_2 , 0x01 ) ;
F_5 ( V_2 , 0xA0 | 0x1 ) ;
F_5 ( V_2 , 0xC8 ) ;
F_5 ( V_2 , 0xDA ) ;
if ( V_2 -> V_9 -> V_10 . V_11 == 64 )
F_5 ( V_2 , 0x12 ) ;
else
F_5 ( V_2 , 0x02 ) ;
F_5 ( V_2 , 0xD9 ) ;
F_5 ( V_2 , 0xF1 ) ;
F_5 ( V_2 , 0xDB ) ;
F_5 ( V_2 , 0x40 ) ;
F_5 ( V_2 , 0xA4 ) ;
F_5 ( V_2 , 0xA6 ) ;
F_5 ( V_2 , 0xAF ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 , int V_12 , int V_13 , int V_14 , int V_15 )
{
F_2 ( V_16 , V_2 ,
L_2 , V_4 , V_12 , V_13 , V_14 , V_15 ) ;
F_5 ( V_2 , 0x00 | 0x0 ) ;
F_5 ( V_2 , 0x10 | 0x0 ) ;
F_5 ( V_2 , 0x40 | 0x0 ) ;
}
static int F_7 ( struct V_1 * V_2 , bool V_17 )
{
F_2 ( V_18 , V_2 , L_3 ,
V_4 , V_17 ? L_4 : L_5 ) ;
if ( V_17 )
F_5 ( V_2 , 0xAE ) ;
else
F_5 ( V_2 , 0xAF ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long * V_7 )
{
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
V_7 [ 0 ] &= 0xFF ;
F_5 ( V_2 , 0x81 ) ;
F_5 ( V_2 , V_7 [ 0 ] ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_20 )
{
T_2 * V_21 = ( T_2 * ) V_2 -> V_9 -> V_22 ;
T_3 * V_23 = V_2 -> V_24 . V_23 ;
int V_25 , V_26 , V_27 ;
int V_28 = 0 ;
F_2 ( V_29 , V_2 , L_1 , V_4 ) ;
for ( V_25 = 0 ; V_25 < V_2 -> V_9 -> V_10 . V_30 ; V_25 ++ ) {
for ( V_26 = 0 ; V_26 < V_2 -> V_9 -> V_10 . V_11 / 8 ; V_26 ++ ) {
* V_23 = 0x00 ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ )
* V_23 |= ( V_21 [ ( V_26 * 8 + V_27 ) * V_2 -> V_9 -> V_10 . V_30 + V_25 ] ? 1 : 0 ) << V_27 ;
V_23 ++ ;
}
}
F_10 ( V_2 -> V_31 . V_32 , 1 ) ;
V_28 = V_2 -> V_5 . V_33 ( V_2 , V_2 -> V_24 . V_23 ,
V_2 -> V_9 -> V_10 . V_30 * V_2 -> V_9 -> V_10 . V_11 / 8 ) ;
if ( V_28 < 0 )
F_11 ( V_2 -> V_9 -> V_34 ,
L_6 , V_4 , V_28 ) ;
return V_28 ;
}
