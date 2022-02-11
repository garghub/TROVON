static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 ( V_2 ) ;
F_2 ( V_2 , 0x21 ) ;
F_2 ( V_2 , 0x10 | ( V_5 & 0x7 ) ) ;
F_2 ( V_2 , 0x04 | ( 64 >> 6 ) ) ;
F_2 ( V_2 , 0x40 | ( 64 & 0x3F ) ) ;
F_2 ( V_2 , 0x20 ) ;
F_2 ( V_2 , 0x08 | 4 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_6 , int V_7 , int V_8 , int V_9 )
{
F_2 ( V_2 , 0x80 ) ;
F_2 ( V_2 , 0x40 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 )
{
T_2 * V_12 = ( T_2 * ) V_2 -> V_13 -> V_14 ;
int V_15 , V_16 , V_17 ;
int V_18 = 0 ;
for ( V_16 = 0 ; V_16 < V_19 / 8 ; V_16 ++ ) {
T_3 * V_20 = V_2 -> V_21 . V_20 ;
F_5 ( V_2 -> V_22 . V_23 , 0 ) ;
F_2 ( V_2 , 0x80 | 0 ) ;
F_2 ( V_2 , 0x40 | V_16 ) ;
for ( V_15 = 0 ; V_15 < V_24 ; V_15 ++ ) {
T_3 V_25 = 0 ;
for ( V_17 = 0 ; V_17 < 8 * V_24 ; V_17 += V_24 ) {
V_25 >>= 1 ;
if ( V_12 [ ( V_16 * 8 * V_24 ) + V_17 + V_15 ] )
V_25 |= 0x80 ;
}
* V_20 ++ = V_25 ;
}
F_5 ( V_2 -> V_22 . V_23 , 1 ) ;
V_18 = V_2 -> V_3 . V_26 ( V_2 , V_2 -> V_21 . V_20 , V_24 ) ;
if ( V_18 < 0 ) {
F_6 ( V_2 -> V_13 -> V_27 ,
L_1 , V_18 ) ;
break;
}
}
return V_18 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned long * V_28 )
{
V_28 [ 0 ] &= 0x7F ;
F_2 ( V_2 , 0x21 ) ;
F_2 ( V_2 , 0x80 | V_28 [ 0 ] ) ;
F_2 ( V_2 , 0x20 ) ;
return 0 ;
}
