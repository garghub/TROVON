static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_2 ( V_4 -> V_8 & 0xff , V_2 -> V_9 + V_10 ) ;
F_2 ( ( V_4 -> V_8 >> 8 ) & 0xff ,
V_2 -> V_9 + V_11 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = 0 ;
V_7 [ 1 ] |= F_4 ( V_2 -> V_9 + V_13 ) ;
V_7 [ 1 ] |= F_4 ( V_2 -> V_9 + V_14 ) << 8 ;
return V_6 -> V_12 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
const struct V_17 * V_18 = F_6 ( V_2 ) ;
int V_9 ;
struct V_3 * V_4 ;
int V_19 ;
F_7 ( V_20 L_1 , V_2 -> V_21 ) ;
V_2 -> V_22 = V_18 -> V_23 ;
V_9 = V_16 -> V_24 [ 0 ] ;
if ( ! F_8 ( V_9 , V_25 , V_2 -> V_22 ) ) {
F_7 ( L_2 ) ;
return - V_26 ;
}
V_2 -> V_9 = V_9 ;
V_19 = F_9 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
V_4 = V_2 -> V_27 + 0 ;
V_4 -> type = V_28 ;
V_4 -> V_29 = V_30 ;
V_4 -> V_31 = 16 ;
V_4 -> V_32 = 1 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_35 = F_1 ;
V_4 = V_2 -> V_27 + 1 ;
V_4 -> type = V_28 ;
V_4 -> V_29 = V_36 ;
V_4 -> V_31 = 16 ;
V_4 -> V_32 = 1 ;
V_4 -> V_33 = & V_34 ;
V_4 -> V_35 = F_3 ;
F_7 ( L_3 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_11 ( V_2 -> V_9 , V_25 ) ;
}
