static unsigned int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
unsigned int V_4 , V_5 ;
V_4 = ( V_2 << 16 ) | ( ( V_3 ) & 0xffff ) ;
F_2 ( V_4 >> 8 , V_1 + ( V_6 << 2 ) ) ;
V_5 = F_3 ( V_1 + ( ( V_4 & 0xff ) << 2 ) ) ;
return V_5 ;
}
static void F_4 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 , unsigned int V_5 )
{
unsigned int V_4 ;
V_4 = ( V_2 << 16 ) | ( ( V_3 ) & 0xffff ) ;
F_2 ( V_4 >> 8 , V_1 + ( V_6 << 2 ) ) ;
F_2 ( V_5 , V_1 + ( ( V_4 & 0xff ) << 2 ) ) ;
}
int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_11 [ 0 ] ;
struct V_9 * V_12 = & V_8 -> V_11 [ 1 ] ;
T_1 V_13 , V_14 , V_5 ;
unsigned int V_15 ;
if ( ! V_10 -> V_1 ) {
V_10 -> V_1 =
F_6 ( V_10 -> V_16 , V_10 -> V_17 ) ;
if ( ! V_10 -> V_1 )
return - V_18 ;
}
if ( ! V_12 -> V_1 ) {
V_12 -> V_1 =
F_6 ( V_12 -> V_16 , V_12 -> V_17 ) ;
if ( ! V_12 -> V_1 )
return - V_18 ;
}
V_14 = F_1 ( V_12 -> V_1 , V_19 , V_20 ) ;
V_14 |= V_21 ;
F_4 ( V_12 -> V_1 , V_19 , V_20 , V_14 ) ;
V_15 = 50 ;
do {
F_7 ( 20 ) ;
V_14 = F_1 ( V_12 -> V_1 , V_19 ,
V_20 ) ;
} while ( ( V_14 & V_21 ) && -- V_15 );
if ( V_14 & V_21 )
F_8 ( L_1 , V_22 ) ;
V_5 = F_1 ( V_12 -> V_1 , V_23 , V_20 ) ;
V_5 &= ~ V_24 ;
F_4 ( V_12 -> V_1 , V_23 , V_20 , V_5 ) ;
F_4 ( V_12 -> V_1 , V_23 , V_25 , 0 ) ;
F_4 ( V_12 -> V_1 , V_23 , V_26 , 0 ) ;
V_13 = F_3 ( V_10 -> V_1 + V_27 ) ;
V_13 |= 0x1 ;
F_2 ( V_13 , V_10 -> V_1 + V_27 ) ;
F_9 ( 10 , 15 ) ;
V_15 = 2000 ;
while ( -- V_15 && ( F_3 ( V_10 -> V_1 + V_27 ) & 1 ) )
F_9 ( 500 , 600 ) ;
if ( ! V_15 )
F_8 ( L_2 , V_22 ) ;
return 0 ;
}
