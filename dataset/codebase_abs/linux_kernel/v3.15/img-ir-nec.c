static int F_1 ( int V_1 , T_1 V_2 , int * V_3 , T_1 V_4 )
{
unsigned int V_5 , V_6 , V_7 , V_8 ;
if ( ! V_1 )
return V_9 ;
if ( V_1 != 32 )
return - V_10 ;
V_5 = ( V_2 >> 0 ) & 0xff ;
V_6 = ( V_2 >> 8 ) & 0xff ;
V_7 = ( V_2 >> 16 ) & 0xff ;
V_8 = ( V_2 >> 24 ) & 0xff ;
if ( ( V_8 ^ V_7 ) != 0xff ) {
* V_3 = F_2 ( V_5 ) << 24 |
F_2 ( V_6 ) << 16 |
F_2 ( V_7 ) << 8 |
F_2 ( V_8 ) ;
} else if ( ( V_6 ^ V_5 ) != 0xff ) {
* V_3 = V_5 << 16 |
V_6 << 8 |
V_7 ;
} else {
* V_3 = V_5 << 8 |
V_7 ;
}
return V_11 ;
}
static int F_3 ( const struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_4 )
{
unsigned int V_5 , V_6 , V_7 , V_8 ;
unsigned int V_16 , V_17 , V_18 , V_19 ;
V_7 = V_13 -> V_7 & 0xff ;
V_18 = V_13 -> V_20 & 0xff ;
if ( ( V_13 -> V_7 | V_13 -> V_20 ) & 0xff000000 ) {
V_5 = F_2 ( V_13 -> V_7 >> 24 ) ;
V_16 = F_2 ( V_13 -> V_20 >> 24 ) ;
V_6 = F_2 ( V_13 -> V_7 >> 16 ) ;
V_17 = F_2 ( V_13 -> V_20 >> 16 ) ;
V_7 = F_2 ( V_13 -> V_7 >> 8 ) ;
V_18 = F_2 ( V_13 -> V_20 >> 8 ) ;
V_8 = F_2 ( V_13 -> V_7 >> 0 ) ;
V_19 = F_2 ( V_13 -> V_20 >> 0 ) ;
} else if ( ( V_13 -> V_7 | V_13 -> V_20 ) & 0x00ff0000 ) {
V_5 = ( V_13 -> V_7 >> 16 ) & 0xff ;
V_16 = ( V_13 -> V_20 >> 16 ) & 0xff ;
V_6 = ( V_13 -> V_7 >> 8 ) & 0xff ;
V_17 = ( V_13 -> V_20 >> 8 ) & 0xff ;
V_8 = V_7 ^ 0xff ;
V_19 = V_18 ;
} else {
V_5 = ( V_13 -> V_7 >> 8 ) & 0xff ;
V_16 = ( V_13 -> V_20 >> 8 ) & 0xff ;
V_6 = V_5 ^ 0xff ;
V_17 = V_16 ;
V_8 = V_7 ^ 0xff ;
V_19 = V_18 ;
}
V_15 -> V_7 = V_8 << 24 |
V_7 << 16 |
V_6 << 8 |
V_5 ;
V_15 -> V_20 = V_19 << 24 |
V_18 << 16 |
V_17 << 8 |
V_16 ;
return 0 ;
}
