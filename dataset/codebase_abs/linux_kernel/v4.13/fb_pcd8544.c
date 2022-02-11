static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 ( V_2 ) ;
F_2 ( V_2 , 0x21 ) ;
F_2 ( V_2 , 0x04 | ( V_5 & 0x3 ) ) ;
F_2 ( V_2 , 0x10 | ( V_6 & 0x7 ) ) ;
F_2 ( V_2 , 0x22 ) ;
F_2 ( V_2 , 0x08 | 4 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_7 , int V_8 , int V_9 , int V_10 )
{
F_2 ( V_2 , 0x80 ) ;
F_2 ( V_2 , 0x40 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 )
{
T_2 * V_13 = ( T_2 * ) V_2 -> V_14 -> V_15 ;
T_3 * V_16 = V_2 -> V_17 . V_16 ;
int V_18 , V_19 , V_20 ;
int V_21 = 0 ;
for ( V_18 = 0 ; V_18 < 84 ; V_18 ++ ) {
for ( V_19 = 0 ; V_19 < 6 ; V_19 ++ ) {
* V_16 = 0x00 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
* V_16 |= ( V_13 [ ( V_19 * 8 + V_20 ) * 84 + V_18 ] ?
1 : 0 ) << V_20 ;
V_16 ++ ;
}
}
F_5 ( V_2 -> V_22 . V_23 , 1 ) ;
V_21 = V_2 -> V_3 . V_24 ( V_2 , V_2 -> V_17 . V_16 , 6 * 84 ) ;
if ( V_21 < 0 )
F_6 ( V_2 -> V_14 -> V_25 , L_1 ,
V_21 ) ;
return V_21 ;
}
static int F_7 ( struct V_1 * V_2 , T_4 * V_26 )
{
V_26 [ 0 ] &= 0x7F ;
F_2 ( V_2 , 0x23 ) ;
F_2 ( V_2 , 0x80 | V_26 [ 0 ] ) ;
F_2 ( V_2 , 0x22 ) ;
return 0 ;
}
