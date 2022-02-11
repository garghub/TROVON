static int F_1 ( int V_1 , T_1 V_2 , enum V_3 * V_4 ,
T_2 * V_5 , T_1 V_6 )
{
unsigned int V_7 , V_8 , V_9 , V_10 ;
if ( ! V_1 )
return V_11 ;
if ( V_1 != 32 )
return - V_12 ;
V_7 = ( V_2 >> 0 ) & 0xff ;
V_8 = ( V_2 >> 8 ) & 0xff ;
V_9 = ( V_2 >> 16 ) & 0xff ;
V_10 = ( V_2 >> 24 ) & 0xff ;
if ( ( V_10 ^ V_9 ) != 0xff ) {
* V_5 = F_2 ( V_7 ) << 24 |
F_2 ( V_8 ) << 16 |
F_2 ( V_9 ) << 8 |
F_2 ( V_10 ) ;
} else if ( ( V_8 ^ V_7 ) != 0xff ) {
* V_5 = V_7 << 16 |
V_8 << 8 |
V_9 ;
} else {
* V_5 = V_7 << 8 |
V_9 ;
}
* V_4 = V_13 ;
return V_14 ;
}
static int F_3 ( const struct V_15 * V_16 ,
struct V_17 * V_18 , T_1 V_19 )
{
unsigned int V_7 , V_8 , V_9 , V_10 ;
unsigned int V_20 , V_21 , V_22 , V_23 ;
V_9 = V_16 -> V_9 & 0xff ;
V_22 = V_16 -> V_24 & 0xff ;
if ( ( V_16 -> V_9 | V_16 -> V_24 ) & 0xff000000 ) {
V_7 = F_2 ( V_16 -> V_9 >> 24 ) ;
V_20 = F_2 ( V_16 -> V_24 >> 24 ) ;
V_8 = F_2 ( V_16 -> V_9 >> 16 ) ;
V_21 = F_2 ( V_16 -> V_24 >> 16 ) ;
V_9 = F_2 ( V_16 -> V_9 >> 8 ) ;
V_22 = F_2 ( V_16 -> V_24 >> 8 ) ;
V_10 = F_2 ( V_16 -> V_9 >> 0 ) ;
V_23 = F_2 ( V_16 -> V_24 >> 0 ) ;
} else if ( ( V_16 -> V_9 | V_16 -> V_24 ) & 0x00ff0000 ) {
V_7 = ( V_16 -> V_9 >> 16 ) & 0xff ;
V_20 = ( V_16 -> V_24 >> 16 ) & 0xff ;
V_8 = ( V_16 -> V_9 >> 8 ) & 0xff ;
V_21 = ( V_16 -> V_24 >> 8 ) & 0xff ;
V_10 = V_9 ^ 0xff ;
V_23 = V_22 ;
} else {
V_7 = ( V_16 -> V_9 >> 8 ) & 0xff ;
V_20 = ( V_16 -> V_24 >> 8 ) & 0xff ;
V_8 = V_7 ^ 0xff ;
V_21 = V_20 ;
V_10 = V_9 ^ 0xff ;
V_23 = V_22 ;
}
V_18 -> V_9 = V_10 << 24 |
V_9 << 16 |
V_8 << 8 |
V_7 ;
V_18 -> V_24 = V_23 << 24 |
V_22 << 16 |
V_21 << 8 |
V_20 ;
return 0 ;
}
