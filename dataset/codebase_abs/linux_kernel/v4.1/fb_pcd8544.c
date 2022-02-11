static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
V_2 -> V_5 . V_6 ( V_2 ) ;
F_3 ( V_2 , 0x21 ) ;
F_3 ( V_2 , 0x04 | ( V_7 & 0x3 ) ) ;
F_3 ( V_2 , 0x10 | ( V_8 & 0x7 ) ) ;
F_3 ( V_2 , 0x22 ) ;
F_3 ( V_2 , 0x08 | 4 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , int V_9 , int V_10 , int V_11 , int V_12 )
{
F_2 ( V_13 , V_2 , L_2 ,
V_4 , V_9 , V_10 , V_11 , V_12 ) ;
F_3 ( V_2 , 0x80 ) ;
F_3 ( V_2 , 0x40 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 )
{
T_2 * V_16 = ( T_2 * ) V_2 -> V_17 -> V_18 ;
T_3 * V_19 = V_2 -> V_20 . V_19 ;
int V_21 , V_22 , V_23 ;
int V_24 = 0 ;
F_2 ( V_25 , V_2 , L_1 , V_4 ) ;
for ( V_21 = 0 ; V_21 < 84 ; V_21 ++ ) {
for ( V_22 = 0 ; V_22 < 6 ; V_22 ++ ) {
* V_19 = 0x00 ;
for ( V_23 = 0 ; V_23 < 8 ; V_23 ++ )
* V_19 |= ( V_16 [ ( V_22 * 8 + V_23 ) * 84 + V_21 ] ? 1 : 0 ) << V_23 ;
V_19 ++ ;
}
}
F_6 ( V_2 -> V_26 . V_27 , 1 ) ;
V_24 = V_2 -> V_5 . V_28 ( V_2 , V_2 -> V_20 . V_19 , 6 * 84 ) ;
if ( V_24 < 0 )
F_7 ( V_2 -> V_17 -> V_29 , L_3 ,
V_24 ) ;
return V_24 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long * V_30 )
{
F_2 ( V_3 , V_2 , L_1 , V_4 ) ;
V_30 [ 0 ] &= 0x7F ;
F_3 ( V_2 , 0x23 ) ;
F_3 ( V_2 , 0x80 | V_30 [ 0 ] ) ;
F_3 ( V_2 , 0x22 ) ;
return 0 ;
}
