static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_2 ( V_4 -> V_8 & 0xFF , V_2 -> V_9 ) ;
F_2 ( V_4 -> V_8 >> 8 , V_2 -> V_9 + 1 ) ;
}
return V_6 -> V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned long V_11 )
{
struct V_12 * V_12 = F_4 ( V_2 ) ;
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_5 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_2 -> V_9 = F_6 ( V_12 , 2 ) ;
V_13 = F_7 ( V_2 , 1 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_14 [ 0 ] ;
V_4 -> type = V_15 ;
V_4 -> V_16 = V_17 | V_18 ;
V_4 -> V_19 = 16 ;
V_4 -> V_20 = 1 ;
V_4 -> V_21 = & V_22 ;
V_4 -> V_23 = F_1 ;
V_4 -> V_8 = F_8 ( V_2 -> V_9 ) | ( F_8 ( V_2 -> V_9 + 1 ) << 8 ) ;
F_9 ( V_2 -> V_24 , L_1 , V_2 -> V_25 ,
F_10 ( V_12 ) ) ;
return 0 ;
}
static int F_11 ( struct V_12 * V_2 ,
const struct V_26 * V_27 )
{
return F_12 ( V_2 , & V_28 ,
V_27 -> V_29 ) ;
}
