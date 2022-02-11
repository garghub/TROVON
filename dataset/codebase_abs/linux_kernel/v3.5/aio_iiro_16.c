static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_10 &= ~ V_7 [ 0 ] ;
V_4 -> V_10 |= V_7 [ 0 ] & V_7 [ 1 ] ;
F_2 ( V_4 -> V_10 & 0xff , V_2 -> V_11 + V_12 ) ;
F_2 ( ( V_4 -> V_10 >> 8 ) & 0xff ,
V_2 -> V_11 + V_13 ) ;
}
V_7 [ 1 ] = V_4 -> V_10 ;
return 2 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
V_7 [ 1 ] = 0 ;
V_7 [ 1 ] |= F_4 ( V_2 -> V_11 + V_14 ) ;
V_7 [ 1 ] |= F_4 ( V_2 -> V_11 + V_15 ) << 8 ;
return 2 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_11 ;
struct V_3 * V_4 ;
F_6 ( V_18 L_1 , V_2 -> V_19 ) ;
V_2 -> V_20 = V_21 -> V_22 ;
V_11 = V_17 -> V_23 [ 0 ] ;
if ( ! F_7 ( V_11 , V_24 , V_2 -> V_20 ) ) {
F_6 ( L_2 ) ;
return - V_25 ;
}
V_2 -> V_11 = V_11 ;
if ( F_8 ( V_2 , sizeof( struct V_26 ) ) < 0 )
return - V_27 ;
if ( F_9 ( V_2 , 2 ) < 0 )
return - V_27 ;
V_4 = V_2 -> V_28 + 0 ;
V_4 -> type = V_29 ;
V_4 -> V_30 = V_31 ;
V_4 -> V_32 = 16 ;
V_4 -> V_33 = 1 ;
V_4 -> V_34 = & V_35 ;
V_4 -> V_36 = F_1 ;
V_4 = V_2 -> V_28 + 1 ;
V_4 -> type = V_29 ;
V_4 -> V_30 = V_37 ;
V_4 -> V_32 = 16 ;
V_4 -> V_33 = 1 ;
V_4 -> V_34 = & V_35 ;
V_4 -> V_36 = F_3 ;
F_6 ( L_3 ) ;
return 1 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 )
F_11 ( V_2 -> V_11 , V_24 ) ;
}
