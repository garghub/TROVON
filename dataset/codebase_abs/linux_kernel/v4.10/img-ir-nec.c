static int F_1 ( int V_1 , T_1 V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
unsigned int V_6 , V_7 , V_8 , V_9 ;
if ( ! V_1 )
return V_10 ;
if ( V_1 != 32 )
return - V_11 ;
V_6 = ( V_2 >> 0 ) & 0xff ;
V_7 = ( V_2 >> 8 ) & 0xff ;
V_8 = ( V_2 >> 16 ) & 0xff ;
V_9 = ( V_2 >> 24 ) & 0xff ;
if ( ( V_9 ^ V_8 ) != 0xff ) {
V_5 -> V_12 = F_2 ( V_6 ) << 24 |
F_2 ( V_7 ) << 16 |
F_2 ( V_8 ) << 8 |
F_2 ( V_9 ) ;
V_5 -> V_13 = V_14 ;
} else if ( ( V_7 ^ V_6 ) != 0xff ) {
V_5 -> V_12 = V_6 << 16 |
V_7 << 8 |
V_8 ;
V_5 -> V_13 = V_15 ;
} else {
V_5 -> V_12 = V_6 << 8 |
V_8 ;
V_5 -> V_13 = V_16 ;
}
return V_17 ;
}
static int F_3 ( const struct V_18 * V_19 ,
struct V_20 * V_21 , T_1 V_22 )
{
unsigned int V_6 , V_7 , V_8 , V_9 ;
unsigned int V_23 , V_24 , V_25 , V_26 ;
V_8 = V_19 -> V_8 & 0xff ;
V_25 = V_19 -> V_27 & 0xff ;
if ( ( V_19 -> V_8 | V_19 -> V_27 ) & 0xff000000 ) {
V_6 = F_2 ( V_19 -> V_8 >> 24 ) ;
V_23 = F_2 ( V_19 -> V_27 >> 24 ) ;
V_7 = F_2 ( V_19 -> V_8 >> 16 ) ;
V_24 = F_2 ( V_19 -> V_27 >> 16 ) ;
V_8 = F_2 ( V_19 -> V_8 >> 8 ) ;
V_25 = F_2 ( V_19 -> V_27 >> 8 ) ;
V_9 = F_2 ( V_19 -> V_8 >> 0 ) ;
V_26 = F_2 ( V_19 -> V_27 >> 0 ) ;
} else if ( ( V_19 -> V_8 | V_19 -> V_27 ) & 0x00ff0000 ) {
V_6 = ( V_19 -> V_8 >> 16 ) & 0xff ;
V_23 = ( V_19 -> V_27 >> 16 ) & 0xff ;
V_7 = ( V_19 -> V_8 >> 8 ) & 0xff ;
V_24 = ( V_19 -> V_27 >> 8 ) & 0xff ;
V_9 = V_8 ^ 0xff ;
V_26 = V_25 ;
} else {
V_6 = ( V_19 -> V_8 >> 8 ) & 0xff ;
V_23 = ( V_19 -> V_27 >> 8 ) & 0xff ;
V_7 = V_6 ^ 0xff ;
V_24 = V_23 ;
V_9 = V_8 ^ 0xff ;
V_26 = V_25 ;
}
V_21 -> V_8 = V_9 << 24 |
V_8 << 16 |
V_7 << 8 |
V_6 ;
V_21 -> V_27 = V_26 << 24 |
V_25 << 16 |
V_24 << 8 |
V_23 ;
return 0 ;
}
